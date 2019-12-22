#include "in_config.h"
/**
 ****************************************************************************************
 *
 * @file hal_mouse.c
 *
 * @brief Mouse driver implementation file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */
#if CFG_QD_EN
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "in_arm.h"
#include "in_mmap.h"
#include "in_irq.h"
#include "in_debug.h"
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_timer.h"
#include ".\hal\hal_clk.h"
#include ".\hal\hal_mouse.h"
#define MOUSE_DEBUG 0
#define MOUSE_KEEP_WAKE_TIME 500
static uint32_t sample_intv_factor = 1;
//static void mouse_handler0(uint32_t status);
//static void mouse_handler1(uint32_t status);
//static void mouse_handler2(uint32_t status);
static void mouse_pin_mux_en(mouse_dev_t *pd, int en);

static mouse_dev_t mouse_dev[MOUSE_MAX_ID] = {
    {
        .id = MOUSE0_ID,
        .used = 0,
        .msg_id = NULL,
        .base = 0,
        //.isr_handler = mouse_handler0,
    },
        {
        .id = MOUSE1_ID,
        .used = 0,
        .msg_id = NULL,
        .base = 0x4,
        //.isr_handler = mouse_handler1,
    },
        {
        .id = MOUSE2_ID,
        .used = 0,
        .msg_id = NULL,
        .base = 0x8,
        //.isr_handler = mouse_handler2,
    },
};

static void mouse_sample_handler(mouse_dev_t* dev, uint32_t status)
{
	if (status & MOUSE_IRQ_TRGGER)
	{
		uint32_t cnt = 0;
		cnt = mouse_get_sample(dev->base);
        if (dev->msg_id) {
            //PRINTD(DBG_FLAG, "cnt %08x \r\n", cnt);
            osMessagePut(dev->msg_id, MOUSE_MSG_BASE|cnt, 0);
        }
        #if CFG_PM_EN
        dev->cancel_tim = 1;
        dev->power_state = PM_DEEP_SLEEP;
        #endif

		PRINTD(DBG_TRACE, "mouse cnt %08x \r\n", cnt);

	}
}
#if 0
static void mouse_handler0(uint32_t status)
{
    mouse_sample_handler(&mouse_dev[0], status);
}
static void mouse_handler1(uint32_t status)
{
    mouse_sample_handler(&mouse_dev[1], status);
}
static void mouse_handler2(uint32_t status)
{
    mouse_sample_handler(&mouse_dev[2], status);
}
#endif


#if CFG_PM_EN
static void mouse_set_pin_wup(int port, int pin)
{
    hal_gpio_aon_latch(port, pin, 0);
    hal_gpio_pin_mux(port, pin, 0, 0);
    hal_gpio_pad_oe_ie(port, pin, 0, 1); 
    hal_gpio_pad_pd_pu(port, pin, 0, 1);
    hal_gpio_pad_pc(port, pin, 1);
    int val = hal_gpio_input(port, pin);
    val = (val == 0) ? 1 : 0;
    hal_gpio_output(port, pin, 0, 0);
    hal_gpio_aon_wup(port, pin, 1, val);
    
}
static int mouse_pm_state(void *arg, uint32_t *sleep_duration)
{
	mouse_dev_t *pd = (mouse_dev_t *)arg;

	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->power_state;
}
static void mouse_tmr_callback(void *arg)
{
    mouse_dev_t *pd = (mouse_dev_t *)arg;
    #if MOUSE_DEBUG
    PRINTD(DBG_TRACE, "%s \n", __func__);
    #endif
    /* contention window here, need set longer delay*/
    if (pd->used && (pd->cancel_tim == 0))
        pd->power_state = PM_DEEP_SLEEP;
}
static void mouse_pm_down(void *arg, uint32_t sleep_duration)
{
    mouse_dev_t *pd = (mouse_dev_t *)arg;
    #if MOUSE_DEBUG
    PRINTD(DBG_TRACE, "%s \n", __func__);
    #endif
    pd->misc_ctrl = RD_WORD(QUADDEC_REG_MISC_CTRL);
    pd->intv_setting = RD_WORD(QUADDEC_REG_INTERVAL_SETTING);
    pd->pin_assignment = RD_WORD(QUADDEC_REG_INPUT_PIN_ASSIGNMENT0 + pd->base);
    pd->report_intv = RD_WORD(QUADDEC_REG_REPORT_INTERVAL);
    pd->cnt_lmt = RD_WORD(QUADDEC_REG_COUNTER_LMT);
    pd->idx_ctrl = RD_WORD(QUADDEC_REG_INDEX_CTRL);
    pd->led_intv = RD_WORD(QUADDEC_REG_INTERVAL_LED_SETTING_M0 + pd->base);
    pd->curr_cnt = mouse_get_sample(pd->base);
#if MOUSE_DEBUG
    PRINTD(DBG_TRACE, "curr_cnt:0x%x \n",pd->curr_cnt);
#endif
    int pin = pd->a_pin & 0xF;
    int port = (pd->a_pin >> GPIO_CFG_PORT_SHIFT) & 0xF;

    mouse_set_pin_wup(port, pin);
    pin = pd->b_pin & 0xF;
    port = (pd->b_pin >> GPIO_CFG_PORT_SHIFT) & 0xF;
    mouse_set_pin_wup(port, pin);
    //pd->curr_idx_cnt = 
	return;
}

static void mouse_pm_up(void *arg)
{
	mouse_dev_t *pd = (mouse_dev_t *)arg;
    #if MOUSE_DEBUG
    PRINTD(DBG_TRACE, "%s \n", __func__);
    #endif
    uint32_t reg = 	aon_read(0x7210);
    //mouse_pin_mux_en(pd, 1);
    WR_WORD(QUADDEC_REG_INTERVAL_SETTING, pd->intv_setting);
    WR_WORD(QUADDEC_REG_INPUT_PIN_ASSIGNMENT0 + pd->base, pd->pin_assignment);
    WR_WORD(QUADDEC_REG_REPORT_INTERVAL, pd->report_intv);
    WR_WORD(QUADDEC_REG_COUNTER_LMT, pd->cnt_lmt);
    WR_WORD(QUADDEC_REG_INDEX_CTRL, pd->idx_ctrl);
    WR_WORD(QUADDEC_REG_INTERVAL_LED_SETTING_M0 + pd->base, pd->led_intv);
    mouse_set_counter_init(pd->curr_cnt);


    WR_WORD(QUADDEC_REG_MISC_CTRL, pd->misc_ctrl);

  
    //mouse_enable(pd->id);
    mouse_intr_clear(0xffUL<<(pd->id * 8));
    mouse_intr_mask_clear(0xffUL<<(pd->id * 8));
    mouse_intr_mask_set(0x1UL<<(pd->id * 8));
	NVIC_SetPriority(Quad_IRQn, IRQ_PRI_AboveNormal);	
    NVIC_EnableIRQ(Quad_IRQn); 

    
    pd->cancel_tim = 0;
    //osTimerStart(pd->tim_id, 500);
        /* gpio wake up */
    if (reg & 0x11) {
        if (!hal_timer_busy()) {
            pd->power_state = PM_SLEEP;
            hal_timer_once(MOUSE_KEEP_WAKE_TIME, pd, mouse_tmr_callback);
        } else {
            PRINTD(DBG_TRACE, "hal timer is busy \n");
        }  
    }
}
#endif	// CFG_PM_EN
static int mouse_pin_chk(mouse_dev_t* dev)
{
    if (dev->id == MOUSE0_ID) {
		// GPIO_1_3 = cha_x
		// GPIO_1_6 = cha_y
		// GPIO_2_3 = cha_z
		// GPIO_3_5 = led_x

		// Sanity check
		if ((((CFG_GPIO_1_3>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_QD_0_CHA_X0) && 
            (((CFG_GPIO_1_6>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_QD_0_CHA_Y0)) {
                dev->a_pin = CFG_GPIO_1_3;
                dev->b_pin = CFG_GPIO_1_6;
        } else {
            return MOUSE_ERR_PINMUX;
        }

        if (((CFG_GPIO_2_3>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_QD_0_CHA_Z0) {
            dev->idx_pin = CFG_GPIO_2_3;
        } else {
            dev->idx_pin = 0;
        }
        if (((CFG_GPIO_3_5>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_QD_0_LED_X) {
            dev->led_pin = CFG_GPIO_3_5;
        } else {
            dev->led_pin = 0;
        }
    }

    if (dev->id == MOUSE1_ID) {
		// GPIO_1_4 = chb_x
		// GPIO_1_7 = chb_y
		// GPIO_2_5 = chb_z
		// GPIO_4_0 = led_y

		// Sanity check
		if ((((CFG_GPIO_1_4>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_QD_0_CHB_X0) && 
            (((CFG_GPIO_1_7>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_QD_0_CHB_Y0)) {
                dev->a_pin = CFG_GPIO_1_4;
                dev->b_pin = CFG_GPIO_1_7;
        } else {
            return MOUSE_ERR_PINMUX;
        }

        if (((CFG_GPIO_2_5>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_QD_0_CHB_Z0) {
            dev->idx_pin = CFG_GPIO_2_5;
        } else {
            dev->idx_pin = 0;
        }
        if (((CFG_GPIO_4_0>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_QD_0_LED_Y) {
            dev->led_pin = CFG_GPIO_4_0;
        } else {
            dev->led_pin = 0;
        }
    }

    if (dev->id == MOUSE2_ID) {
		// GPIO_1_5 = idx_x
		// GPIO_1_8 = idx_y
		// GPIO_3_4 = idx_z
		// GPIO_4_1 = led_z

		// Sanity check
		if ((((CFG_GPIO_1_5>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_QD_0_IDX_X0) && 
            (((CFG_GPIO_1_8>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_QD_0_IDX_Y0)) {
                dev->a_pin = CFG_GPIO_1_5;
                dev->b_pin = CFG_GPIO_1_8;
        } else {
            return MOUSE_ERR_PINMUX;
        }

        if (((CFG_GPIO_3_4>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_QD_0_IDX_Z0) {
            dev->idx_pin = CFG_GPIO_3_4;
        } else {
            dev->idx_pin = 0;
        }
        if (((CFG_GPIO_4_1>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_QD_0_LED_Z) {
            dev->led_pin = CFG_GPIO_4_1;
        } else {
            dev->led_pin = 0;
        }
    }
    return MOUSE_ERR_OK;

}
static void mouse_pin_mux_en(mouse_dev_t *pd, int en)
{
	if (en) {
		hal_gpio_pin_cfg(pd->a_pin);
		hal_gpio_pin_cfg(pd->b_pin);
        if (pd->idx_pin)
            hal_gpio_pin_cfg(pd->idx_pin);
        if (pd->led_pin)
		    hal_gpio_pin_cfg(pd->led_pin);
	} else {
		hal_gpio_pin_dft(pd->a_pin);
		hal_gpio_pin_dft(pd->b_pin);
        if (pd->idx_pin)
            hal_gpio_pin_dft(pd->idx_pin);
        if (pd->led_pin)
		    hal_gpio_pin_dft(pd->led_pin);
	}    
}
mouse_dev_t* hal_mouse_open(int id, osMessageQId msg)
{
    if (id >= MOUSE_MAX_ID || id < 0 || mouse_dev[id].used)
    {
        return NULL;
    }

    
		uint32_t clk_num;
    mouse_dev_t *pd = &mouse_dev[id];
    if (mouse_pin_chk(pd) != MOUSE_ERR_OK)
         goto fail;

    osMutexDef_t def;
    def.mutex = pd->mu;
    pd->mutex = osMutexCreate(&def);//todo: all device use same mutex?
    if (!pd->mutex) {
        goto fail;
    }
    
    pd->used = 1;
    pd->id = id;
    pd->msg_id = msg;
    mouse_pin_mux_en(pd, 1);
    hal_clk_quaddec_en(1);
    //mouse_set_interval_setting(pd, 0x6403ff);//default value, 0 is invalid.  

    //mouse_set_misc_ctrl(pd, 0x8001000);//default value
    //mouse_set_counter_lmt(pd, 0x8000f0);
    clk_num = hal_clk_d0_get() / 1000000;
    if (clk_num > 16) {
        clk_num /= 2;
        sample_intv_factor = 2;
    } else {
        sample_intv_factor = 1;
    }
    /*max value of num_clk is 0xf*/
    mouse_clk_num_in_us(clk_num - 1);//todo?

    //mouse_sample_interval(0x3ff);
    //mouse_led_interval(0x64);
    //mouse_set_report_interval(0x1000);
    mouse_set_led_setting(pd->base, 0x10);

    mouse_debounce_enable(pd->id);
    mouse_set_pin_a(pd->base, 0);
    mouse_set_pin_b(pd->base, 1);
    mouse_set_pin_idx(pd->base, 2);



#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
	pd->pmd.arg = (void *)pd;
	pd->pmd.power_state = mouse_pm_state;
	pd->pmd.power_down = mouse_pm_down;
	pd->pmd.power_up = mouse_pm_up;
	hal_pm_reg_mod(&pd->pmd);
#endif
    return pd;
fail:
    pd->used = 0;
    return NULL;
}

int hal_mouse_sample_interval(mouse_dev_t* dev, uint16_t intv)
{
    if (!dev) {
        return MOUSE_ERR_INVALID_PARAM;
    }
    osMutexWait(dev->mutex, osWaitForever);
    mouse_sample_interval(intv * sample_intv_factor);
    osMutexRelease(dev->mutex);
    return MOUSE_ERR_OK;
}
int hal_mouse_led_interval(mouse_dev_t* dev, uint16_t intv)
{
    if (!dev) {
        return MOUSE_ERR_INVALID_PARAM;
    }
    osMutexWait(dev->mutex, osWaitForever);
    mouse_led_interval(intv * sample_intv_factor);
    osMutexRelease(dev->mutex);    
    return MOUSE_ERR_OK;
}
int hal_mouse_enable(mouse_dev_t* dev)
{
    if (!dev) {
        return MOUSE_ERR_INVALID_PARAM;
    }
    osMutexWait(dev->mutex, osWaitForever);
    mouse_enable(dev->id);
    mouse_intr_clear(0xffUL<<(dev->id * 8));
    mouse_intr_mask_clear(0xffUL<<(dev->id * 8));
    mouse_intr_mask_set(0x1UL<<(dev->id * 8));
	NVIC_SetPriority(Quad_IRQn, IRQ_PRI_AboveNormal);	
    NVIC_EnableIRQ(Quad_IRQn);
    osMutexRelease(dev->mutex);
    return MOUSE_ERR_OK;
    
}

int hal_mouse_disable(mouse_dev_t* dev)
{
    if (!dev) {
        return MOUSE_ERR_INVALID_PARAM;
    }
    osMutexWait(dev->mutex, osWaitForever);
    mouse_intr_mask_set(0xffUL<<(dev->id * 8));
    mouse_disable(dev->id);
    osMutexRelease(dev->mutex);
    return MOUSE_ERR_OK;
}
int hal_mouse_set_pin(mouse_dev_t* dev, uint32_t a, uint32_t b, uint32_t idx)
{
    if (!dev) {
        return MOUSE_ERR_INVALID_PARAM;
    }
    osMutexWait(dev->mutex, osWaitForever);
    mouse_set_pin_a(dev->base, a);
    mouse_set_pin_b(dev->base, b);
    mouse_set_pin_idx(dev->base, idx);
    osMutexRelease(dev->mutex);
    return MOUSE_ERR_OK;
}


void hal_mouse_close(mouse_dev_t* pd)
{
    if (!pd) {
        return;
    }
    osMutexWait(pd->mutex, osWaitForever);
    mouse_intr_mask_set(0xffUL<<(pd->id * 8));
    mouse_disable(pd->id);
    pd->msg_id = NULL;
    mouse_pin_mux_en(pd, 0);
    #if CFG_PM_EN
		hal_pm_unreg_mod(&pd->pmd);
    #endif
    


    osMutexRelease(pd->mutex);
    osMutexDelete(pd->mutex);
      /* todo: contention window here*/
		pd->used = 0;
    int used = 0;
    for (int i = 0; i < sizeof(mouse_dev); i++) {
        used |= mouse_dev[0].used;
    }
    if (used == 0) {
        hal_clk_quaddec_en(0);
		NVIC_DisableIRQ(Quad_IRQn);
	}			
    //NVIC_DisableIRQ(Quad_IRQn);
}



__irq void QD_Handler(void)
{
	uint32_t status;
    status = RD_WORD(QUADDEC_REG_INTERRUPT_STATUS);
	WR_WORD(QUADDEC_REG_INTERRUPT_CLEAR, status);
    #if MOUSE_DEBUG
	//PRINTD(DBG_TRACE, "irq %08x \r\n", status);
    #endif
    for (int i = 0; i < MOUSE_MAX_ID; i++) {
        uint32_t param = (status>>(i*8)) & 0xff;
        if (mouse_dev[i].used && param) {
            mouse_sample_handler(&mouse_dev[i], param);
        }
    }
}

uint32_t hal_mouse_get_cnt(uint32_t p)
{
	return p & 0xffff;
}
#endif

