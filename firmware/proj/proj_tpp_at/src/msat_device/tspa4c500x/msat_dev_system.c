/**
 ****************************************************************************************
 *
 * @file msat_dev_system.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

/* Include Files
 ****************************************************************************************
 */
#include "msat_dev_system.h"

/* Macro Definition
 ****************************************************************************************
 */
#define DEV_SYSTEM_COMMAND_IN_TASK_SIZE         (1024)
#define DEV_SYSTEM_WAKEUP_TASK_SIZE             (512)
#define DEV_SYSTEM_COMMAND_IN_TASK_SIGNAL_ID    (0x0004)
#define DEV_SYSTEM_WAKUP_TASK_SIGNAL_ID         (0x0005)

#define DEV_SYSTEM_WAKUP_KEEP_TIME      (1)

#define DEV_SYSTEM_UART_RX_BUF_LENGTH   (MSAT_CMD_LENGTH_MAX)

/* Enum Definition
 ****************************************************************************************
 */

/* Struct Definition
 ****************************************************************************************
 */
typedef struct
{
    int port;
    int pin;
    int level;
    bool isWakeup;
#if CFG_PM_EN
    int power_state;
    struct pm_module pm;
#endif
}
dev_wakeup_in_t;

/* Function Declaration
 ****************************************************************************************
 */
extern void msat_fw_evt_wakeup_cb(void);
extern msatErr_t msat_fw_evt_data_in(char *buf, uint16_t len);

static void wakeup_int_cb(void* arg);
static msatErr_t msat_dev_system_uart_open(void);
static msatErr_t msat_dev_system_uart_close(void);

/* Global Variable
 ****************************************************************************************
 */
static void *devUartPtHdl;
static uint8_t devUartRxBuf[DEV_SYSTEM_UART_RX_BUF_LENGTH] = {0};

static osThreadDef_t devDataInDef;
static osThreadId devDataInThreadId;
static osThreadDef_t devWupInDef;
static osThreadId devWupInThreadId;

static dev_wakeup_in_t wakeup_dev = {0};

/* Function Definition
 ****************************************************************************************
 */
static void msat_dev_system_data_in_task(const void *arg)
{
    osEvent osEvt;
    uint32_t rxLen = 0;
    int err;
    
    while(1)
    {
        osEvt = osSignalWait(DEV_SYSTEM_COMMAND_IN_TASK_SIGNAL_ID, osWaitForever);
        if(osEvt.status == osEventSignal)
        {
            err = msat_dev_system_uart_open();
            if(err)
            {
                MSPRINT("msat_dev_system_uart_open err.\r\n");
                continue;
            }
            MSPRINT("msat wakeup.\r\n");
            
            msat_fw_evt_wakeup_cb();
            
            while(wakeup_dev.isWakeup)
            {
                err = hal_uart_rcvd_intr_tmo(devUartPtHdl, devUartRxBuf, DEV_SYSTEM_UART_RX_BUF_LENGTH, &rxLen, osWaitForever);
                if(err)
                    MSPRINT("RX err: %d\r\n", err);
                
                if(rxLen && rxLen <= MSAT_CMD_LENGTH_MAX)
                {
                    msatErr_t error = msat_fw_evt_data_in((char *)devUartRxBuf, rxLen);
                    if(error)
                        MSPRINT("AT ERROR DATA IN: %d\r\n", error);
                }
            }
        }
    }
}
static void msat_dev_system_wakeup_in_task(const void *arg)
{
    osEvent osEvt;
    
    while(1)
    {
        osEvt = osSignalWait(DEV_SYSTEM_WAKUP_TASK_SIGNAL_ID, osWaitForever);
        if(osEvt.status == osEventSignal)
        {
            wakeup_dev.isWakeup = true;
            
            osSignalSet(devDataInThreadId, DEV_SYSTEM_COMMAND_IN_TASK_SIGNAL_ID);
            
            while(wakeup_dev.isWakeup)
            {
                if(wakeup_dev.level != hal_gpio_input(wakeup_dev.port, wakeup_dev.pin))
                {
                    osSignalClear(devDataInThreadId, DEV_SYSTEM_COMMAND_IN_TASK_SIGNAL_ID);
                    msat_dev_system_uart_close();
                    
                    wakeup_dev.isWakeup = false;
                    MSPRINT("msat sleep.\r\n");
                    
                    uint32_t arg = (wakeup_dev.port << 8) | wakeup_dev.pin;
                    hal_gpio_ext_int_en(wakeup_dev.port, wakeup_dev.pin, wakeup_dev.level, (void*)arg, wakeup_int_cb);
                }
            }
        }
    }
}

void msat_dev_system_delay_ms(uint32_t millisec)
{
    osDelay(millisec);
}

msatErr_t msat_dev_system_data_out(uint8_t *buf, uint16_t len)
{
    if(hal_uart_xmit_poll(devUartPtHdl, buf, len))
        return ERR_DEVICE_DRIVER;
    
    return ERR_NO_ERROR;
}

#if CFG_PM_EN
static int wake_power_state(void* arg, uint32_t* sleep_duration)
{
    dev_wakeup_in_t* pd = (dev_wakeup_in_t*)arg;
    *sleep_duration = 0xFFFF;
    
    return pd->power_state;
}

static void wake_power_up(void* arg)
{
    dev_wakeup_in_t* pd = (dev_wakeup_in_t*)arg;
    uint32_t reg = aon_read(0x7210);
    
    hal_gpio_ext_int_clear(pd->port, pd->pin);
    hal_gpio_ext_int_unmask(pd->port, pd->pin);
    NVIC_SetPriority((IRQn_Type)(Gpio0_IRQn + pd->port), IRQ_PRI_Normal);
    NVIC_EnableIRQ((IRQn_Type)(Gpio0_IRQn + pd->port));
    
    pd->power_state = PM_DEEP_SLEEP;
}
#endif

static void wakeup_int_cb(void* arg)
{
    int port = ((uint32_t)arg >> 8) & 0xff;
    int pin = (uint32_t)arg & 0xff;
    
    //MSPRINT("wakeup_int_cb port %d pin %d\r\n", port, pin);
    
    hal_uart_wait_break(devUartPtHdl);
    hal_gpio_ext_int_dis(port, pin);
    osSignalSet(devWupInThreadId, DEV_SYSTEM_WAKUP_TASK_SIGNAL_ID);
}

static msatErr_t msat_dev_system_uart_open(void)
{
    if(devUartPtHdl)
        return ERR_NO_ERROR;
    
    devUartPtHdl = hal_uart_open(MSAT_UART_CHANNEL, MSAT_UART_BAUDRATE, 8, 1, 0, 0, 1, UART_RT_HALF_FULL, 0, 0);
    if(!devUartPtHdl)
        return ERR_DEVICE_DRIVER;
    
    return ERR_NO_ERROR;
}

static msatErr_t msat_dev_system_uart_close(void)
{
    hal_uart_close(devUartPtHdl);
    devUartPtHdl = NULL;
    
    return ERR_NO_ERROR;
}

static msatErr_t msat_dev_system_uart_init(void)
{
    devDataInDef.pthread = msat_dev_system_data_in_task;
    devDataInDef.instances = 1;
    devDataInDef.tpriority = osPriorityNormal;
    devDataInDef.stacksize = DEV_SYSTEM_COMMAND_IN_TASK_SIZE;
    
    devDataInThreadId = osThreadCreate(&devDataInDef, NULL);
    if(!devDataInThreadId)
        return ERR_OS;
    
    return msat_dev_system_uart_open();
}

msatErr_t msat_dev_system_wakeup_out_set(void)
{
    int port = MSAT_WAKEUP_OUT_PORT;
    int pin = MSAT_WAKEUP_OUT_PIN;
    int level = MSAT_WAKEUP_OUT_LEVEL;
    
    hal_gpio_pin_mux(port, pin, 0, 0);
    hal_gpio_pad_oe_ie(port, pin, 1, 0);
    hal_gpio_aon_latch(port, pin, 0);
    if(level)
    {
        hal_gpio_pad_pd_pu(port, pin, 1, 0);
        hal_gpio_output(port, pin, 0, 1);
    }
    else
    {
        hal_gpio_pad_pd_pu(port, pin, 0, 1);
        hal_gpio_output(port, pin, 1, 1);
    }
    hal_gpio_aon_latch(port, pin, 1);
    
    return ERR_NO_ERROR;
}

msatErr_t msat_dev_system_wakeup_out_clear(void)
{
    int port = MSAT_WAKEUP_OUT_PORT;
    int pin = MSAT_WAKEUP_OUT_PIN;
    int level = MSAT_WAKEUP_OUT_LEVEL;
    
    hal_gpio_pin_mux(port, pin, 0, 0);
    hal_gpio_pad_oe_ie(port, pin, 1, 0);
    hal_gpio_aon_latch(port, pin, 0);
    if(level)
    {
        hal_gpio_pad_pd_pu(port, pin, 1, 0);
        hal_gpio_output(port, pin, 1, 1);
    }
    else
    {
        hal_gpio_pad_pd_pu(port, pin, 0, 1);
        hal_gpio_output(port, pin, 0, 1);
    }
    hal_gpio_aon_latch(port, pin, 1);
    
    return ERR_NO_ERROR;
}

static msatErr_t msat_dev_system_wakeup_init(void)
{
    devWupInDef.pthread = msat_dev_system_wakeup_in_task;
    devWupInDef.instances = 1;
    devWupInDef.tpriority = osPriorityNormal;
    devWupInDef.stacksize = DEV_SYSTEM_WAKEUP_TASK_SIZE;
    
    devWupInThreadId = osThreadCreate(&devWupInDef, NULL);
    if(!devWupInThreadId)
        return ERR_OS;
    
    msat_dev_system_wakeup_out_clear();
    
    wakeup_dev.port = MSAT_WAKEUP_IN_PORT;
    wakeup_dev.pin = MSAT_WAKEUP_IN_PIN;
    wakeup_dev.level = MSAT_WAKEUP_IN_LEVEL;
    wakeup_dev.isWakeup = false;
#if CFG_PM_EN
    wakeup_dev.power_state = PM_DEEP_SLEEP;
    wakeup_dev.pm.arg = (void *)&wakeup_dev;
    wakeup_dev.pm.power_state = wake_power_state;
    wakeup_dev.pm.power_up = wake_power_up;
    hal_pm_reg_mod(&wakeup_dev.pm);
#endif
    
    uint32_t arg = (wakeup_dev.port << 8) | wakeup_dev.pin;
    
    hal_gpio_pin_mux(wakeup_dev.port, wakeup_dev.pin, 0, 0);
    hal_gpio_pad_oe_ie(wakeup_dev.port, wakeup_dev.pin, 0, 1);
    hal_gpio_ext_int_en(wakeup_dev.port, wakeup_dev.pin, wakeup_dev.level, (void*)arg, wakeup_int_cb);
    if(wakeup_dev.level)
        hal_gpio_pad_pd_pu(wakeup_dev.port, wakeup_dev.pin, 1, 0);
    else
        hal_gpio_pad_pd_pu(wakeup_dev.port, wakeup_dev.pin, 0, 1);
    hal_gpio_aon_wup(wakeup_dev.port, wakeup_dev.pin, 1, wakeup_dev.level);
    
    if(wakeup_dev.level == hal_gpio_input(wakeup_dev.port, wakeup_dev.pin))
        osSignalSet(devWupInThreadId, DEV_SYSTEM_WAKUP_TASK_SIGNAL_ID);
    
    return ERR_NO_ERROR;
}
msatErr_t msat_dev_system_init(uint8_t dev)
{
    msatErr_t err = ERR_NO_ERROR;
    
    if(dev != MSAT_DEV_TSPA4C500X)
        return ERR_DEVICE;
    
    err = msat_dev_system_uart_init();
    if(err)
        return err;
    
    err = msat_dev_system_wakeup_init();
    if(err)
        return err;
    
    return err;
}
