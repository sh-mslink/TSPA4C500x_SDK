#include "in_config.h"
/**
 ****************************************************************************************
 *
 * @file hal_cnt_timer.c
 *
 * @brief Counter driver implementation file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
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
#include ".\hal\hal_cnt_timer.h"

static cnt_timer_dev_t cnt_timer_dev[CNT_TIMER_MAX];
static void cnt_timer_handler(uint32_t status, void *priv_data)
{
    cnt_timer_dev_t *pd = (cnt_timer_dev_t *)priv_data;
    if (status & CNT_WAVEFORM_STOP) {

        if (pd->onetime) {
            if (pd->callback) {
                pd->callback(pd->arg);
            }
            pd->onetime = 0;
            cnt_trigger_stop(pd->cnt_dev->base);
            hal_cnt_intr_mask(pd->cnt_dev);
            cnt_disable(pd->cnt_dev->base);  
            pd->callback = NULL;
            pd->arg = NULL;  
            pd->busy = 0;      
#if CFG_PM_EN
	        pd->power_state = PM_DEEP_SLEEP;
#endif 
        } else {
            cnt_trigger_stop(pd->cnt_dev->base);
            cnt_trigger_start(pd->cnt_dev->base);
            if (pd->callback) {
                pd->callback(pd->arg);
            }
        }



    }
}
#if CFG_PM_EN
static int cnt_timer_pm_state(void *arg, uint32_t *sleep_duration)
{
	cnt_timer_dev_t *pd = (cnt_timer_dev_t *)arg;

	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->power_state;
}

static void cnt_timer_pm_down(void *arg, uint32_t sleep_duration)
{        
	return;
}

static void cnt_timer_pm_up(void *arg)
{
    return;    
}
#endif	// CFG_PM_EN

cnt_timer_dev_t *hal_cnt_timer_open(int id)
{
    
    if (id > CNT_TIMER_MAX || id < 0 || cnt_timer_dev[id].used)
    {
        return NULL;
    }
	cnt_timer_dev_t *pd = &cnt_timer_dev[id];
    memset(pd, 0, sizeof(cnt_timer_dev_t));
    pd->used = 1;
    pd->busy = 0;
    pd->semaphore = NULL;
    pd->mutex = NULL;
    pd->cnt_dev = hal_cnt_open(id, 0);//32Mhz
    if (pd->cnt_dev == NULL)
    {
        goto fail;
    }

    osSemaphoreDef_t sema_def;
    sema_def.semaphore = pd->sma;
    pd->semaphore = osSemaphoreCreate(&sema_def, 0);
    if (!pd->semaphore) {
        goto fail;
    }
    osMutexDef_t mutex_def;
    mutex_def.mutex = pd->mu;
    pd->mutex = osMutexCreate(&mutex_def);
    if (!pd->mutex) {
        goto fail;
    }


    

    hal_cnt_set_handler(pd->cnt_dev, cnt_timer_handler, pd);

    

    //hal_cnt_internal_din_pinmux(cnt_id*2, rx_pin);//counter A pin number is cnt_id*2
    //hal_cnt_internal_dout_pinmux(cnt_id*2, tx_pin);
	/// PM
#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
	pd->pmd.arg = (void *)pd;
	pd->pmd.power_state = cnt_timer_pm_state;
	pd->pmd.power_down = cnt_timer_pm_down;
	pd->pmd.power_up = cnt_timer_pm_up;
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
    if (pd->semaphore) {
        osSemaphoreDelete(pd->semaphore);	
        pd->semaphore = NULL;
    }
    pd->used = 0;
    return NULL; 
}
void hal_cnt_timer_close(cnt_timer_dev_t *pd)
{

    if (!pd)
        return;
    
    osMutexWait(pd->mutex, osWaitForever);
    hal_cnt_close(pd->cnt_dev);
    pd->cnt_dev = NULL;
    osMutexRelease(pd->mutex);
    osMutexDelete(pd->mutex);
    osSemaphoreDelete(pd->semaphore);
#if CFG_PM_EN
	hal_pm_unreg_mod(&pd->pmd);
#endif
    pd->mutex = NULL;
    pd->semaphore = NULL;
    pd->busy = 0;
    pd->used = 0;
}


int hal_cnt_timer_once(cnt_timer_dev_t *pd, uint32_t msec, void *arg, void (*tmr_cb)(void *))
{
	uint32_t count;
    if (!pd)
        return CNT_TIM_ERR_INVALID_PARAM;
	if (pd->busy)
		return CNT_TIM_ERR_IN_USE;

	if (msec == 0)
		return CNT_TIM_ERR_INVALID_PARAM;	
    osMutexWait(pd->mutex, osWaitForever);
#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif
    pd->onetime = 1;
	pd->arg = arg;
	pd->callback = tmr_cb;
    cnt_dev_t *cnt_dev = pd->cnt_dev;
	NVIC_SetPriority(Counter_IRQn, IRQ_PRI_AboveNormal);	
    NVIC_EnableIRQ(Counter_IRQn);
    hal_cnt_intr_unmask(cnt_dev);
    cnt_disable(cnt_dev->base);
 
    cnt_set_mode(cnt_dev->base, CNT_WAVAFORM_MODE);
    cnt_set_src_edge(cnt_dev->base, 0);

    
    cnt_set_target_ctrl(cnt_dev->base, CNT_A2_KEEP_VALUE | CNT_A2_STOP_COUNTER | CNT_B2_KEEP_VALUE | CNT_B2_STOP_COUNTER
                        | (0 << CNT_DOUT_A_RESET_VALUE_SHIFT) | (0 << CNT_DOUT_B_RESET_VALUE_SHIFT));
    cnt_set_soft_trigger(cnt_dev->base, 0);
    
    count = hal_cnt_get_clk(cnt_dev)/1000 * msec;
   
    /* target A */
    cnt_set_target_a(cnt_dev->base, 0, 0, count); // 0 start    

    /* target B */
    cnt_set_target_b(cnt_dev->base, 0, 0, 0);
    

    cnt_set_out_bypass(cnt_dev->base, 0x0); //1 is bypass


    cnt_enable(cnt_dev->base);
    cnt_trigger_start(cnt_dev->base);
    



    osMutexRelease(pd->mutex);



	return CNT_TIM_ERR_OK;
}

int hal_cnt_timer_period_start(cnt_timer_dev_t *pd, uint32_t msec, void *arg, void (*tmr_cb)(void *))
{

	uint32_t count;
    if (!pd)
        return CNT_TIM_ERR_INVALID_PARAM;
	if (pd->busy)
		return CNT_TIM_ERR_IN_USE;

	if (msec == 0)
		return CNT_TIM_ERR_INVALID_PARAM;	
    osMutexWait(pd->mutex, osWaitForever);
#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif
    pd->onetime = 0;
	pd->busy = 1;

	pd->arg = arg;
	pd->callback = tmr_cb;
    cnt_dev_t *cnt_dev = pd->cnt_dev;
	NVIC_SetPriority(Counter_IRQn, IRQ_PRI_AboveNormal);	
    NVIC_EnableIRQ(Counter_IRQn);
    hal_cnt_intr_unmask(cnt_dev);
    cnt_disable(cnt_dev->base);
 
    cnt_set_mode(cnt_dev->base, CNT_WAVAFORM_MODE);
    cnt_set_src_edge(cnt_dev->base, 0);

    
    cnt_set_target_ctrl(cnt_dev->base, CNT_A2_KEEP_VALUE | CNT_A2_STOP_COUNTER | CNT_B2_KEEP_VALUE | CNT_B2_STOP_COUNTER
                        | (0 << CNT_DOUT_A_RESET_VALUE_SHIFT) | (0 << CNT_DOUT_B_RESET_VALUE_SHIFT));
    cnt_set_soft_trigger(cnt_dev->base, 0);
    
    count = hal_cnt_get_clk(cnt_dev)/1000 * msec;
    
    /* target A */
    cnt_set_target_a(cnt_dev->base, 0, 0, count); // 0 start    
    cnt_set_target_b(cnt_dev->base, 0, 0, 0);
 

    cnt_set_out_bypass(cnt_dev->base, 0x0); //1 is bypass


    cnt_enable(cnt_dev->base);
    cnt_trigger_start(cnt_dev->base);
    



    osMutexRelease(pd->mutex);

	return CNT_TIM_ERR_OK;
}

int hal_cnt_timer_period_stop(cnt_timer_dev_t *pd)
{

    if (!pd)
        return CNT_TIM_ERR_INVALID_PARAM;
	if (!pd->busy)
		return CNT_TIM_ERR_BAD_STATE;
    osMutexWait(pd->mutex, osWaitForever);


	pd->busy = 0;
	pd->callback = NULL;
    pd->arg = NULL; 
    hal_cnt_intr_mask(pd->cnt_dev);
    cnt_disable(pd->cnt_dev->base);
#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif
    osMutexRelease(pd->mutex);
	return CNT_TIM_ERR_OK;
}



#endif



