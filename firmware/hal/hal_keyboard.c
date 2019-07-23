#include "in_config.h"
/**
 ****************************************************************************************
 *
 * @file hal_keyboard.c
 *
 * @brief Keyboard driver implementation file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
#if CFG_KB_EN
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "in_arm.h"
#include "in_mmap.h"
#include "in_irq.h"
#include "in_debug.h"
#include ".\hal\hal_clk.h"
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_keyboard.h"
#include ".\hal\hal_timer.h"
#define DUMP_REG(reg, base) PRINTD(DBG_TRACE, #reg " %08x (%x)\r\n", RD_WORD(reg + base), base)
#define KB_KEEP_WAKE_TIME 500
#define GPIO_MAX_PIN 32
#define KB_DEBUG 0
osMutexDef(kb_mutex);
/* todo: remove pins that don't support keyboard */
static const uint32_t cfg_gpio_pin[GPIO_MAX_PIN] = {  
                        CFG_GPIO_0_0, CFG_GPIO_0_1, CFG_GPIO_0_2, CFG_GPIO_0_3, CFG_GPIO_0_4, CFG_GPIO_0_5,//5
                        CFG_GPIO_1_0, CFG_GPIO_1_1, CFG_GPIO_1_2, CFG_GPIO_1_3, CFG_GPIO_1_4, CFG_GPIO_1_5, CFG_GPIO_1_6, CFG_GPIO_1_7, CFG_GPIO_1_8,//14
                        CFG_GPIO_2_0, CFG_GPIO_2_1, CFG_GPIO_2_2, CFG_GPIO_2_3, CFG_GPIO_2_4, CFG_GPIO_2_5, CFG_GPIO_2_6, CFG_GPIO_2_7, CFG_GPIO_2_8,//23
                        CFG_GPIO_3_0, CFG_GPIO_3_1, CFG_GPIO_3_2, CFG_GPIO_3_3, CFG_GPIO_3_4, CFG_GPIO_3_5, //29
                        CFG_GPIO_4_0, CFG_GPIO_4_1 //31
                        };


//volatile uint32_t flag = 0;
static uint16_t keymap[KB_MAX_KEY_NUM] = {0};
static kb_dev_t kb_dev = {

    //.id = KEYBOARD0_ID,
    .used = 0,
    .msg_id = NULL,
    .long_cnt = 5,
    //.key_num = 0,

};

#if CFG_PM_EN
static void kp_tmr_callback(void *arg);
osTimerDef(kp, kp_tmr_callback);
#endif

//static int8_t row_pin[KB_MAX_ROW_NUM];
//static int8_t col_pin[KB_MAX_COL_NUM];
//extern uint32_t cfg_gpio_pin[GPIO_MAX_PIN];
static int kb_pin_mux_en(int en)
{
    for (int i = 0; i < sizeof(cfg_gpio_pin)/sizeof(cfg_gpio_pin[0]); i++) {
        if (((cfg_gpio_pin[i]>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_2) {
            if (en) {
                hal_gpio_pin_cfg(cfg_gpio_pin[i]);
            } else {
                hal_gpio_pin_dft(cfg_gpio_pin[i]);
            }            
        }
    }
    return KB_ERR_OK;
}
//#define KEY_NUM 9
int hal_kb_set_row_col(kb_dev_t *dev, uint32_t row, uint32_t col)
{
    if (!dev) {
        return KB_ERR_INVALID_PARAM;
    }
    //col is output
    if (row * col > KB_MAX_KEY_NUM) {
        return KB_ERR_INVALID_PARAM;
    }
    osMutexWait(dev->mutex, osWaitForever);
    dev->row = row;
    dev->col = col;
    kb_set_num_col_row(col << KEYBOARD_REG_NUM_COL_ROW_CTL_NUM_COL_SHIFT |
                    row << KEYBOARD_REG_NUM_COL_ROW_CTL_NUM_ROW_SHIFT);
    osMutexRelease(dev->mutex);
    return KB_ERR_OK;
}

int hal_kb_enable(kb_dev_t *dev)
{
    if (!dev) {
        return KB_ERR_INVALID_PARAM;
    }
    osMutexWait(dev->mutex, osWaitForever);
    kb_enable();
	/* Must clear mask after enable kb module */
    kb_intr_mask_clear(0x1);
    kb_intr_clear(0x1);
	NVIC_SetPriority(Keyboard_IRQn, IRQ_PRI_AboveNormal);	
    NVIC_EnableIRQ(Keyboard_IRQn);
    osMutexRelease(dev->mutex);
    return KB_ERR_OK;
}
int hal_kb_disable(kb_dev_t *dev)
{
    if (!dev) {
        return KB_ERR_INVALID_PARAM;
    }
    osMutexWait(dev->mutex, osWaitForever);
    NVIC_DisableIRQ(Keyboard_IRQn);
    kb_disable();
    osMutexRelease(dev->mutex);
    return KB_ERR_OK;
}
int hal_kb_set_longpress_cnt(kb_dev_t *dev, uint32_t val)
{
    if (val <= 1 || !dev)
    {
        return KB_ERR_INVALID_PARAM;
    }
    osMutexWait(dev->mutex, osWaitForever);
    dev->long_cnt = val;

    dev->long_cnt = val;
    osMutexRelease(dev->mutex);
    return KB_ERR_OK;
}
#if CFG_PM_EN
static void kp_tmr_callback(void *arg)
{
    kb_dev_t *pd = &kb_dev;
    #if KB_DEBUG
    PRINTD(DBG_TRACE, "%s \n", __func__);
    #endif
    /* contention window here, need set longer delay*/
    if (pd->used && (pd->cancel_tim == 0))
        pd->power_state = PM_DEEP_SLEEP;
}
static int kb_pm_state(void *arg, uint32_t *sleep_duration)
{
	kb_dev_t *pd = (kb_dev_t *)arg;

	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->power_state;
}

static void kb_pm_down(void *arg, uint32_t sleep_duration)
{
    kb_dev_t *pd = (kb_dev_t *)arg;
    #if KB_DEBUG
    //PRINTD(DBG_TRACE, "%s \n", __func__);
    #endif
    kb_disable();
    pd->misc_reg = RD_WORD(KEYBOARD_REG_MISC_CTRL);
    pd->col_row_reg = RD_WORD(KEYBOARD_REG_NUM_COL_ROW);
    pd->ms_cnt_reg = RD_WORD(KEYBOARD_REG_HALF_MS_CNT);
    //PRINTD(DBG_TRACE, "0x%08x 0x%08x 0x%08x \n", pd->misc_reg, pd->col_row_reg, pd->ms_cnt_reg);
    for (int i = 0; i < sizeof(cfg_gpio_pin)/sizeof(cfg_gpio_pin[0]); i++) {
        if (((cfg_gpio_pin[i]>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_2) {
            int pin = cfg_gpio_pin[i] & 0xF;
            int port = (cfg_gpio_pin[i] >> GPIO_CFG_PORT_SHIFT) & 0xF;
            int oe = (cfg_gpio_pin[i] >> GPIO_CFG_OE_IE_SHIFT) & 0x1;
            int ie = (cfg_gpio_pin[i] >> (GPIO_CFG_OE_IE_SHIFT+1)) & 0x1;
             
            if (oe) {
                //hal_gpio_pin_mux(port, pin, 2, 0);
                hal_gpio_pin_mux(port, pin, 0, 0);
                hal_gpio_output(port, pin, 0, 1);
	         hal_gpio_aon_latch(port, pin, 1);
                
            }
            
        }
        
    }  
	return;
}


static void kb_pm_up(void *arg)
{
	kb_dev_t *pd = (kb_dev_t *)arg;
    #if KB_DEBUG
    //PRINTD(DBG_TRACE, "%s \n", __func__);
    #endif
    uint32_t reg = 	aon_read(0x7210);
    
	// Recover pin mux
    //kb_pin_mux_en(1);
    for (int i = 0; i < sizeof(cfg_gpio_pin)/sizeof(cfg_gpio_pin[0]); i++) {
        if (((cfg_gpio_pin[i]>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_2) {
            int pin = cfg_gpio_pin[i] & 0xF;
            int port = (cfg_gpio_pin[i] >> GPIO_CFG_PORT_SHIFT) & 0xF;
            int oe = (cfg_gpio_pin[i] >> GPIO_CFG_OE_IE_SHIFT) & 0x1;
            
            if (oe) {
                hal_gpio_aon_latch(port, pin, 0);
                hal_gpio_pin_mux(port, pin, GPIO_MUX_2, 0);
            }
    
        }
    } 
    //PRINTD(DBG_TRACE, "0x%08x 0x%08x 0x%08x \n", pd->misc_reg, pd->col_row_reg, pd->ms_cnt_reg);
    WR_WORD(KEYBOARD_REG_MISC_CTRL, pd->misc_reg);
    WR_WORD(KEYBOARD_REG_NUM_COL_ROW, pd->col_row_reg);
    WR_WORD(KEYBOARD_REG_HALF_MS_CNT, pd->ms_cnt_reg);
    //hal_clk_kb_en(1);//clk?
    pd->cancel_tim = 0;

    kb_enable();
	/* Must clear mask after enable kb module */
    kb_intr_mask_clear(0x1);
    kb_intr_clear(0x1);
	NVIC_SetPriority(Keyboard_IRQn, IRQ_PRI_AboveNormal);	
    NVIC_EnableIRQ(Keyboard_IRQn);


    
    //PRINTD(DBG_TRACE, "0x%x 0x%x  0x%x 0x%x\n", reg, aon_read(0x7200), aon_read(0x7220), aon_read(0x7230));
    /* gpio wake up */
    if (reg & 0x11) {
        if (!hal_timer_busy()) {
            pd->power_state = PM_SLEEP;
            hal_timer_once(KB_KEEP_WAKE_TIME, NULL, kp_tmr_callback);
        } else {
            PRINTD(DBG_ERR, "Err:hal timer is busy \n");
        }
    }

}
#endif	// CFG_PM_EN
kb_dev_t *hal_kb_open(uint8_t row, uint8_t col, osMessageQId msgid)
{
    kb_dev_t *pd = &kb_dev;
    if (pd->used  || (row * col > KB_MAX_KEY_NUM) || (row * col == 0))
    {
        return NULL;
    }

  
    pd->used = 1;
    pd->mutex = osMutexCreate(osMutex(kb_mutex));
    if (!pd->mutex) {
        goto fail;
    }
    pd->msg_id = msgid;
    pd->row = row;
    pd->col = col;
    pd->long_cnt = 5;

    //uint32_t val = RD_WORD(GLOBAL_REG_RESET_CTRL_1);
    kb_pin_mux_en(1);
    /// Clk 
	hal_clk_kb_en(1);
    
    //kb_reset();
    kb_set_half_ms_cnt(hal_clk_d0_get() / 2000);

    hal_kb_set_row_col(pd, row, col);

    /* default value */
    kb_set_scan_freq(0);
    kb_set_press_deb(0x11);
    kb_set_release_deb(0x20);
    kb_set_sample_th(0x4);
    memset((void*)keymap, 0, sizeof(keymap));
    


	/// PM
#if CFG_PM_EN
    pd->cancel_tim = 0;
    //pd->tim_id = osTimerCreate(osTimer(kp), osTimerOnce, NULL);
    //if (!pd->tim_id)
    //    goto fail;
	pd->power_state = PM_DEEP_SLEEP;
	pd->pmd.arg = (void *)pd;
	pd->pmd.power_state = kb_pm_state;
	pd->pmd.power_down = kb_pm_down;
	pd->pmd.power_up = kb_pm_up;
	hal_pm_reg_mod(&pd->pmd);
#endif

    return pd;

fail:
    pd->used = 0;
    return NULL;
}
void hal_kb_close(kb_dev_t *dev)
{
    if (!dev)
        return;
    //kb_dev_t *pd = (kb_dev_t *)dev;
    osMutexWait(dev->mutex, osWaitForever);
    kb_disable();
    kb_pin_mux_en(0);
    hal_clk_kb_en(0);
    dev->msg_id = NULL;
    osMutexRelease(dev->mutex);
    osMutexDelete(dev->mutex);
    dev->used = 0;
    return;
}

uint32_t hal_kb_get_key_code(uint32_t p)
{
	return  p & 0xff;
}
uint32_t hal_kb_get_key_evt(uint32_t p)
{
	return (p >> 8) & 0xff;
}
static void kb_send_press_msg(uint16_t key)
{
    uint32_t msg = KB_MSG_BASE;
    kb_dev_t *pd = &kb_dev;
    //int ret;
    if (keymap[key] == 1)
    {
        msg |= KB_MSG_PRESS<<8;
        #if KB_DEBUG
        PRINTD(DBG_TRACE, "press key  %d\r\n",key);
        #endif
    }
    else if (pd->long_cnt && (keymap[key]%pd->long_cnt == 0))
    {
        //PRINTD(DBG_TRACE, "long press key  %d\r\n",key);
        msg |= KB_MSG_LONG_PRESS<<8;
    }
    else
    {
        return;
    }
    msg |= key;

    if (pd->msg_id)
    {
        osMessagePut(pd->msg_id, msg, 0);
        //PRINTD(DBG_TRACE, "put msg  %d\r\n",ret);
    }
}
static void kb_press_handle(uint8_t key)
{
    kb_dev_t *pd = &kb_dev;
    uint32_t key_num = pd->row * pd->col;
    if (key < key_num) {
        keymap[key]++;
        if (keymap[key] == 0)
            keymap[key]++;
        kb_send_press_msg(key);
    #if CFG_PM_EN
        pd->cancel_tim = 1;
		pd->power_state = PM_SLEEP;
    #endif
    } else {
        PRINTD(DBG_ERR, "Wrong key code 0x%x  \r\n", key);
    } 
}
__irq void KB_Handler(void)
{
    kb_dev_t *pd = &kb_dev;
    uint32_t val = RD_WORD(KEYBOARD_REG_INTR_STATUS);
    WR_WORD(KEYBOARD_REG_INTR_CLEAR, val);

    uint32_t k0 = 0xff;
    uint32_t k1 = 0xff;
    uint32_t k2 = 0xff;
    uint32_t k3 = 0xff;
    //uint32_t long_cnt = kb_dev.long_cnt;
    uint32_t a01, a23;
    uint32_t key_num = pd->row * pd->col;
    //PRINTD(DBG_TRACE, "intr %x  \r\n", val);

    a01 = RD_WORD(KEYBOARD_REG_STATUS_A01);
    a23 = RD_WORD(KEYBOARD_REG_STATUS_A23);

    if (a01 & KEYBOARD_REG_STATUS_A01_PRESS_RELEASE0)
    {
        k0 = a01 & 0xff;
        kb_press_handle(k0);
    }
    if (a01 & KEYBOARD_REG_STATUS_A01_PRESS_RELEASE1)
    {
        k1 = (a01 >> 12) & 0xff;
        kb_press_handle(k1);
    }
    if (a23 & KEYBOARD_REG_STATUS_A23_PRESS_RELEASE2)
    {
        k2 = a23 & 0xff;
        kb_press_handle(k2);
    }
    if (a23 & KEYBOARD_REG_STATUS_A23_PRESS_RELEASE3)
    {
        k3 = (a23 >> 12) & 0xff;
        kb_press_handle(k3);
    }


    /* release handle */
    uint32_t press = 0;
    for (int i = 0; i < key_num; i++)
    {
        if (keymap[i] > 0 && (i != k0 && i != k1 && i != k2 && i != k3))
        {
            #if KB_DEBUG
            PRINTD(DBG_TRACE, "release key  %d\r\n",i);
            #endif
            keymap[i] = 0;
            if (pd->msg_id)
            {
                osMessagePut(pd->msg_id, KB_MSG_BASE | (KB_MSG_RELEASE<<8) | i, 0);
            }
        }
        press |= keymap[i];
    }
#if CFG_PM_EN
    if (press == 0) {
	    pd->power_state = PM_DEEP_SLEEP;     
    }
#endif 
    //DUMP_REG(KEYBOARD_REG_STATUS_A01,0);
    //DUMP_REG(KEYBOARD_REG_STATUS_A23,0);
    //DUMP_REG(KEYBOARD_REG_STATUS_B01,0);
    //DUMP_REG(KEYBOARD_REG_STATUS_B23,0);

    //kb_dev.power_state = PM_DEEP_SLEEP;
}
#endif

