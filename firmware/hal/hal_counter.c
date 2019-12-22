#include "in_config.h"
/**
 ****************************************************************************************
 *
 * @file hal_counter.c
 *
 * @brief Counter driver implementation file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */
#if CFG_COUNTER_EN
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "in_arm.h"

#include "in_irq.h"
#include "in_debug.h"
#include ".\hal\hal_clk.h"
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_counter.h"
#define WAIT_TIME 100000


/* todo: need clean this */
//#define CNT_CFG_GPIO_START 16
//#define GPIO_MAX_PIN 8
static const uint32_t cfg_gpio_pin[] = {  
                    CFG_GPIO_2_1, CFG_GPIO_2_2, CFG_GPIO_2_3, CFG_GPIO_2_4, CFG_GPIO_2_5, CFG_GPIO_2_6, CFG_GPIO_2_7, CFG_GPIO_2_8,//23
                        };

osMutexDef(cnt_dev_mutex);
static osMutexId cnt_mutex = NULL;

static void cnt_set_default(cnt_dev_t* dev);
static cnt_dev_t cnt_dev[CNT_MAX_ID] = {

	{
		.id = CNT0_ID,
		.base = CNT0_BASE,
        .used = 0,
        .isr_handler = NULL,
        .clk = 32000000,
	},

	{
		.id = CNT1_ID,
		.base = CNT1_BASE,
        .used = 0,
        .isr_handler = NULL,
        .clk = 32000000,
	},

	{
		.id = CNT2_ID,
		.base = CNT2_BASE,
        .used = 0,
        .isr_handler = NULL,
        .clk = 32000000,
	},

	{
		.id = CNT3_ID,
		.base = CNT3_BASE,
        .used = 0,
        .isr_handler = NULL,
        .clk = 32000000,
	},

};



int hal_cnt_intr_mask(cnt_dev_t* dev)
{
    if (!dev)
        return CNT_ERR_INVALID_PARAM;
    uint32_t mask;
    mask = 0xff << (8 * dev->id);
    cnt_intr_mask_set(mask);
    return CNT_ERR_OK;
    
}
int hal_cnt_intr_unmask(cnt_dev_t* dev)
{
    if (!dev)
        return CNT_ERR_INVALID_PARAM;
    uint32_t mask;
    mask = 0xff << (8 * dev->id);
    cnt_intr_mask_clear(mask);
    return CNT_ERR_OK;
    
}

int hal_cnt_sync(cnt_dev_t* dev, uint32_t mask)
{
    //uint32_t snap;

    cnt_set_snap_ctrl(dev->base, CNT_SNAP_CLEAR_MASK);

    int wait = WAIT_TIME;
    while(wait--) {
        if(cnt_snap_status(dev->base) == 0)
            break;
    }
    if (wait < 0) {
        PRINTD(DBG_ERR, "sync clear timeout\r\n");
        return CNT_ERR_TIMEOUT;
    }
    /*
    snap = RD_WORD(COUNTER_ALL_APB_REG_CTRL_SNAP_C0 + dev->base);

    FLIP_BIT(snap, mask);
    WR_WORD(COUNTER_ALL_APB_REG_CTRL_SNAP_C0 + dev->base, snap);//todo reverse 0-4  wait
    */
    cnt_set_snap_ctrl(dev->base, mask);

    wait = WAIT_TIME;
    while(wait--) {
        if(cnt_snap_status(dev->base)&mask)
            break;
    }
    if (wait < 0) {
        PRINTD(DBG_ERR, "sync set timeout\r\n");
        return CNT_ERR_TIMEOUT;
    }


    return CNT_ERR_OK;
}
#if CFG_PM_EN
static int cnt_pm_state(void *arg, uint32_t *sleep_duration)
{
	cnt_dev_t *pd = (cnt_dev_t *)arg;

	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->power_state;
}

static void cnt_pm_down(void *arg, uint32_t sleep_duration)
{
  //  cnt_dev_t *pd = (cnt_dev_t *)arg;
  //  PRINTD(DBG_TRACE, "%s \n", __func__);
	return;
}

static void cnt_pm_up(void *arg)
{
	cnt_dev_t *pd = (cnt_dev_t *)arg;
    //PRINTD(DBG_TRACE, "%s \n", __func__);

    cnt_set_clk(pd->base, pd->clk_div);
    cnt_enable_clk(pd->base);    
    cnt_reset(pd->id);
}
#endif	// CFG_PM_EN

cnt_dev_t* hal_cnt_open(int id, uint32_t clk)
{
    cnt_dev_t* pd = NULL;
    uint32_t div;
    int clk_div;

    if (id >= CNT_MAX_ID || id < 0 || cnt_dev[id].used) {
        return NULL;
    }
    if (clk == 0) {
        clk_div = CNT_ROOT_CLK_DIV2;
        clk = hal_clk_root_get() / 2;
    } else {
        div = hal_clk_root_get()/clk;
        switch (div) {
            case 2:
                clk_div = CNT_ROOT_CLK_DIV2;
                break;
            case 4:
                clk_div = CNT_ROOT_CLK_DIV4;
                break;
            case 8:
                clk_div = CNT_ROOT_CLK_DIV8;
                break;
            default:
                return NULL;   
        }
    }


    if (!cnt_mutex) {
        cnt_mutex = osMutexCreate(osMutex(cnt_dev_mutex));
        if (!cnt_mutex) {
            return NULL;
        }
    }

    osMutexWait(cnt_mutex, osWaitForever);
    pd = &cnt_dev[id];
    pd->used = 1;
    
        /// PM
#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
	pd->pmd.arg = (void *)pd;
	pd->pmd.power_state = cnt_pm_state;
	pd->pmd.power_down = cnt_pm_down;
	pd->pmd.power_up = cnt_pm_up;
	hal_pm_reg_mod(&pd->pmd);
#endif

    hal_clk_counter_en(1);

    cnt_set_clk(pd->base, clk_div);// when use XO, it is 32MHz
    pd->clk = clk;//32Mhz
    pd->clk_div = clk_div;
    cnt_enable_clk(pd->base);

    cnt_reset(pd->id);
    
    cnt_set_default(pd);//reset clear interanl status, but not reset register value. So here we need reset register value manually
    osMutexRelease(cnt_mutex);

    
    pd->isr_handler = NULL;
#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif
    
    return pd;
}
void hal_cnt_close(cnt_dev_t *dev)
{
    if (!dev || !cnt_mutex)
        return;
    cnt_dev_t *pd = (cnt_dev_t*)dev;
    pd->used = 0;
    pd->isr_handler = NULL;
    cnt_disable(dev->base);
    cnt_disable_clk(pd->base);
    hal_cnt_intr_mask(dev); 

    osMutexWait(cnt_mutex, osWaitForever);
    int used = 0;
    for (int i = 0; i < CNT_MAX_ID; i++) {
        used |= cnt_dev[i].used;
    }
    if (used == 0) {
        hal_clk_counter_en(0);
        NVIC_DisableIRQ(Counter_IRQn);
    }
    osMutexRelease(cnt_mutex);
#if CFG_PM_EN
	hal_pm_unreg_mod(&pd->pmd);
#endif
    
}
int hal_cnt_enable(cnt_dev_t *dev)
{
    if (!dev)
        return CNT_ERR_INVALID_PARAM;    
    cnt_enable(dev->base);
	NVIC_SetPriority(Counter_IRQn, IRQ_PRI_Normal);	
    NVIC_EnableIRQ(Counter_IRQn);
    hal_cnt_intr_unmask(dev);   
    return CNT_ERR_OK;
}
int hal_cnt_disable(cnt_dev_t *dev)
{
    if (!dev)
        return CNT_ERR_INVALID_PARAM;    
    cnt_disable(dev->base);
    hal_cnt_intr_mask(dev);   
    return CNT_ERR_OK;
}
int hal_cnt_pin_chk(int pin_id)
{
    if (pin_id < 0 || pin_id >= CNT_MAX_PIN)
        return CNT_ERR_INVALID_PARAM;
    uint32_t cfg = cfg_gpio_pin[pin_id];  
    if (((cfg>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_COUNTER_1) {
        return CNT_ERR_OK;
    } else
        return CNT_ERR_INVALID_PARAM;
}
int hal_cnt_pin_mux_en(int pin_id, int en)
{
    if (pin_id < 0 || pin_id >= CNT_MAX_PIN)
        return CNT_ERR_INVALID_PARAM;
    uint32_t cfg = cfg_gpio_pin[pin_id];

    if (en) {
        hal_gpio_pin_cfg(cfg);
    } else {
        hal_gpio_pin_dft(cfg);
    }            


    return  CNT_ERR_OK;
}

int hal_cnt_internal_din_pinmux(int inner_pin, int ext_pin)
{
    uint32_t reg = cnt_get_din_mux();
    uint32_t mask = 0xF<<(inner_pin*4);
    reg &= ~mask;
    reg |= ext_pin<<(inner_pin*4);
    cnt_set_din_mux(reg);
	  return CNT_ERR_OK;

}
int hal_cnt_internal_dout_pinmux(int inner_pin, int ext_pin)
{
    uint32_t reg = cnt_get_dout_mux();
    uint32_t mask = 0xF<<(ext_pin*4);
    reg &= ~mask;
    reg |= inner_pin<<(ext_pin*4);
    cnt_set_dout_mux(reg);
	  return CNT_ERR_OK;
}
void hal_cnt_set_handler(cnt_dev_t *dev, CNT_ISR_FUN fun, void *arg)
{
    cnt_dev_t* pd = dev;
    pd->isr_handler = (CNT_ISR_FUN)fun;
	pd->isr_arg = arg;
}
uint32_t hal_cnt_get_clk(cnt_dev_t *dev)
{
	if (!dev)
		return 0;
	return dev->clk;
}
static void cnt_set_default(cnt_dev_t* dev)
{
    
    WR_WORD(COUNTER_ALL_APB_REG_INTR_MASK_CLR, 0xffffffff);
    WR_WORD(COUNTER_ALL_APB_REG_INTR_CLR, 0xffffffff);

    uint32_t snap = RD_WORD(COUNTER_ALL_APB_REG_CTRL_SNAP_C0 + dev->base);
    WR_WORD(COUNTER_ALL_APB_REG_CTRL_SNAP_C0 + dev->base, ~snap);//clear bit is clear SNAP_STATUS

    cnt_disable(dev->base);
    //WR_WORD(COUNTER_ALL_APB_REG_ENABLE_C0+offset, 0);
    WR_WORD(COUNTER_ALL_APB_REG_MODE_SEL_C0 + dev->base, 0);
    WR_WORD(COUNTER_ALL_APB_REG_SRC_SEL_EDGE_C0 + dev->base, 0);
    WR_WORD(COUNTER_ALL_APB_REG_SOFT_TRIGGER_CTRL_C0 + dev->base, 0);
    WR_WORD(COUNTER_ALL_APB_REG_TARGET_REG_CTRL_C0 + dev->base, 0);

    WR_WORD(COUNTER_ALL_APB_REG_TARGET_REG_A0_C0 + dev->base, 0);
    WR_WORD(COUNTER_ALL_APB_REG_TARGET_REG_A1_C0 + dev->base, 0);
    WR_WORD(COUNTER_ALL_APB_REG_TARGET_REG_A2_C0 + dev->base, 0);
    WR_WORD(COUNTER_ALL_APB_REG_TARGET_REG_B0_C0 + dev->base, 0);
    WR_WORD(COUNTER_ALL_APB_REG_TARGET_REG_B1_C0 + dev->base, 0);
    WR_WORD(COUNTER_ALL_APB_REG_TARGET_REG_B2_C0 + dev->base, 0);
    WR_WORD(COUNTER_ALL_APB_REG_IR_DOUT_BYPASS_C0 + dev->base, 0x30000);
    WR_WORD(COUNTER_ALL_APB_REG_IR_DIN_BYPASS_C0 + dev->base, 0x3);

    WR_WORD(COUNTER_ALL_APB_REG_SINGLE_START_TRIGGER_C0 + dev->base, 0);
    WR_WORD(COUNTER_ALL_APB_REG_SINGLE_STOP_TRIGGER_C0 + dev->base, 0);


    WR_WORD(COUNTER_ALL_APB_REG_MUX_SEL_C0 + dev->base, 0);
    WR_WORD(COUNTER_ALL_APB_REG_SHIFTMODE_CTRL_C0 + dev->base, 0);
    WR_WORD(COUNTER_ALL_APB_REG_SHIFTIN_DATA_CTRL_BITCNTS_C0 + dev->base, 0);
    WR_WORD(COUNTER_ALL_APB_REG_SHIFTMODE_POINT_EN_C0 + dev->base, 1);
    WR_WORD(COUNTER_ALL_APB_REG_SWITCH_MODE_ONEBIT_CNTS_C0 + dev->base, 0);
    WR_WORD(COUNTER_ALL_APB_REG_WAVEFORM_MODE_AUTOMATIC_C0 + dev->base, 0xffff);



    WR_WORD(COUNTER_ALL_APB_REG_SHIFTOUT_DATA_CTRL_BITCNTS_C0 + dev->base, 0);
    WR_WORD(COUNTER_ALL_APB_REG_SHIFTOUT_DATA_C0 + dev->base, 0);
    WR_WORD(COUNTER_ALL_APB_REG_SHIFTOUT_DATA_VALID_C0 + dev->base, 0);

	/* Should set to default value*/
    //WR_WORD(COUNTER_ALL_APB_REG_DIN_MUX_SEL + dev->base, 0x76543210);
    //WR_WORD(COUNTER_ALL_APB_REG_DOUT_MUX_SEL + dev->base, 0x76543210);
    //WR_WORD(COUNTER_ALL_APB_REG_DOUT_ENABLE_CTRL + dev->base, 0x11111111);
   

}

#if 0
void cnt_dump_reg(cnt_dev_t* dev)
{

    //DUMP_REG(COUNTER_ALL_APB_REG_ENABLE_C1,0);
    DUMP_REG(COUNTER_ALL_APB_REG_DIN_MUX_SEL,0);
    DUMP_REG(COUNTER_ALL_APB_REG_DOUT_MUX_SEL,0);
    DUMP_REG(COUNTER_ALL_APB_REG_DOUT_MUX_SEL,0);


    
    DUMP_REG(COUNTER_ALL_APB_REG_ENABLE_C0,dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_MODE_SEL_C0,dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_SRC_SEL_EDGE_C0,dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_SOFT_TRIGGER_CTRL_C0,dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_TARGET_REG_CTRL_C0,dev->base);
    //delay(1);
    DUMP_REG(COUNTER_ALL_APB_REG_TARGET_REG_A0_C0,dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_TARGET_REG_A1_C0,dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_TARGET_REG_A2_C0,dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_TARGET_REG_B0_C0,dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_TARGET_REG_B1_C0,dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_TARGET_REG_B2_C0,dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_IR_DOUT_BYPASS_C0,dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_IR_DIN_BYPASS_C0,dev->base);
    //delay(1);
    DUMP_REG(COUNTER_ALL_APB_REG_SINGLE_START_TRIGGER_C0,dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_SINGLE_STOP_TRIGGER_C0,dev->base);


    DUMP_REG(COUNTER_ALL_APB_REG_MUX_SEL_C0 , dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_SHIFTMODE_CTRL_C0 , dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_SHIFTIN_DATA_CTRL_BITCNTS_C0 , dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_SHIFTMODE_POINT_EN_C0 , dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_SWITCH_MODE_ONEBIT_CNTS_C0 , dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_WAVEFORM_MODE_AUTOMATIC_C0 , dev->base);

    //delay(1);

    DUMP_REG(COUNTER_ALL_APB_REG_SHIFTOUT_DATA_CTRL_BITCNTS_C0 , dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_SHIFTMODE_POINT_EN_C0 , dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_SHIFTOUT_DATA_C0 , dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_SHIFTOUT_DATA_VALID_C0 , dev->base);
    DUMP_REG(COUNTER_ALL_APB_REG_IR_DIN_ONECYCLE_VALUE_A_C0, dev->base);


}
#endif
__irq void Counter_Handler(void)
{
    uint32_t status;
    status = cnt_intr_status();
    cnt_intr_clear(0xffffffff);
	//PRINTD(DBG_TRACE, "cnt irq 0x%08x \n", status);
    for (int i = 0; i < CNT_MAX_ID; i++) {
        uint32_t param = (status>>(i*8)) & 0xff;
        if (cnt_dev[i].used && cnt_dev[i].isr_handler && param) {
            cnt_dev[i].isr_handler(param, cnt_dev[i].isr_arg);
        }
    }
}
#endif

