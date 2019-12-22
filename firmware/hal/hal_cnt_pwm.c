#include "in_config.h"
/**
 ****************************************************************************************
 *
 * @file hal_cnt_pwm.c
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
#include ".\hal\hal_counter.h"
#include ".\hal\hal_cnt_pwm.h"

static cnt_pwm_dev_t cnt_pwm_dev[CNT_PWM_MAX];
#if CFG_PM_EN
static int cnt_pwm_pm_state(void *arg, uint32_t *sleep_duration)
{
	cnt_pwm_dev_t *pd = (cnt_pwm_dev_t *)arg;

	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->power_state;
}

static void cnt_pwm_pm_down(void *arg, uint32_t sleep_duration)
{        
    hal_gpio_aon_latch(2,  pd->pin + 1, 1);
	return;
}

static void cnt_pwm_pm_up(void *arg)
{
    ir_dev_t *pd = (ir_dev_t *)arg;
    
    hal_gpio_aon_latch(2,  pd->pin + 1, 0);
    hal_cnt_internal_dout_pinmux(pd->cnt_dev->id, pd->pin);
    return;
}
#endif	// CFG_PM_EN
cnt_pwm_dev_t *hal_cnt_pwm_open(int id, int pwm_pin)
{
    
    if (id > CNT_PWM_MAX || id < 0 || cnt_pwm_dev[id].used)
    {
        return NULL;
    }
	cnt_pwm_dev_t *pd = &cnt_pwm_dev[id];



    memset(pd, 0, sizeof(cnt_pwm_dev_t));
    pd->used = 1;
    pd->busy = 0;
    
    pd->mutex = NULL;
    if (hal_cnt_pin_chk(pwm_pin) != CNT_ERR_OK) {
        goto fail;
    }  
    hal_cnt_pin_mux_en(pwm_pin, 1);

    pd->cnt_dev = hal_cnt_open(id, 0);//32Mhz 
    if (pd->cnt_dev == NULL)
    {
        goto fail;
    }


    osMutexDef_t mutex_def;
    mutex_def.mutex = pd->mu;
    pd->mutex = osMutexCreate(&mutex_def);
    if (!pd->mutex) {
        goto fail;
    }
    pd->pin = pwm_pin;

    

    //hal_cnt_set_handler(pd->cnt_dev, cnt_timer_handler, pd);

    

    //hal_cnt_internal_din_pinmux(cnt_id*2, rx_pin);//counter A pin number is cnt_id*2
    hal_cnt_internal_dout_pinmux(id*2, pwm_pin);//counter A pin number is id*2
    
	/// PM
#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
	pd->pmd.arg = (void *)pd;
	pd->pmd.power_state = cnt_pwm_pm_state;
	pd->pmd.power_down = cnt_pwm_pm_down;
	pd->pmd.power_up = cnt_pwm_pm_up;
	hal_pm_reg_mod(&pd->pmd);
#endif
    return pd;
fail:
    if (pd->cnt_dev) {
        hal_cnt_close(pd->cnt_dev);
        pd->cnt_dev = NULL;
    }
    if (pd->mutex) {
        osMutexDelete(pd->mutex);
        pd->mutex = NULL;
    }
    pd->used = 0;
    return NULL; 
}
void hal_cnt_pwm_close(cnt_pwm_dev_t *pd)
{

    if (!pd)
        return;
    
    osMutexWait(pd->mutex, osWaitForever);
    hal_cnt_close(pd->cnt_dev);
    pd->cnt_dev = NULL;
    osMutexRelease(pd->mutex);
    osMutexDelete(pd->mutex);
#if CFG_PM_EN
	hal_pm_unreg_mod(&pd->pmd);
#endif
    pd->mutex = NULL;
    pd->busy = 0;
    pd->used = 0;
    pd->pin = 0;
}



int hal_cnt_pwm_enable(cnt_pwm_dev_t *pd, uint32_t period_usec, uint32_t high_usec)
{

	uint32_t period, high;
    if (!pd)
        return CNT_PWM_ERR_INVALID_PARAM;
	if (pd->busy)
		return CNT_PWM_ERR_IN_USE;

	if ((period_usec == 0) || (high_usec == 0) || (high_usec >= period_usec))
		return CNT_PWM_ERR_INVALID_PARAM;	
    osMutexWait(pd->mutex, osWaitForever);
#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif
	pd->busy = 1;
    cnt_dev_t *cnt_dev = pd->cnt_dev;
	NVIC_SetPriority(Counter_IRQn, IRQ_PRI_AboveNormal);	
    NVIC_EnableIRQ(Counter_IRQn);
    hal_cnt_intr_unmask(cnt_dev);
    cnt_disable(cnt_dev->base);
 
    cnt_set_mode(cnt_dev->base, CNT_WAVAFORM_MODE);
    cnt_set_src_edge(cnt_dev->base, 0);

    
    cnt_set_target_ctrl(cnt_dev->base, CNT_A2_RESET_VALUE | CNT_A2_RESTART_COUNTER | CNT_B2_KEEP_VALUE | CNT_B2_STOP_COUNTER
                        | (0 << CNT_DOUT_A_RESET_VALUE_SHIFT) | (0 << CNT_DOUT_B_RESET_VALUE_SHIFT));
    cnt_set_soft_trigger(cnt_dev->base, 0);
    
    period = hal_cnt_get_clk(cnt_dev)/1000000 * period_usec;
    high = hal_cnt_get_clk(cnt_dev)/1000000 * high_usec;
    
    /* target A */
    cnt_set_target_a(cnt_dev->base, 0, period - high, period); // 0 start    
    cnt_set_target_b(cnt_dev->base, 0, 0, 0);
 


    cnt_set_out_bypass(cnt_dev->base, CNT_OUT_BYPASS_A);

    cnt_enable(cnt_dev->base);
    cnt_trigger_start(cnt_dev->base);
    



    osMutexRelease(pd->mutex);

	return CNT_PWM_ERR_OK;
}

int hal_cnt_pwm_disable(cnt_pwm_dev_t *pd)
{

    if (!pd)
        return CNT_PWM_ERR_INVALID_PARAM;
	if (!pd->busy)
		return CNT_PWM_ERR_BAD_STATE;
    osMutexWait(pd->mutex, osWaitForever);


	pd->busy = 0;
    hal_cnt_intr_mask(pd->cnt_dev);
    cnt_disable(pd->cnt_dev->base);
#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif
    osMutexRelease(pd->mutex);
	return CNT_PWM_ERR_OK;
}



#endif



