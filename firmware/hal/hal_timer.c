#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_timer.c
 *
 * @brief Generic timer implementation file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "in_arm.h"
#include "in_mmap.h"
#include "in_irq.h"
#include "in_debug.h"

#include ".\hal\hal_clk.h"
#include ".\hal\hal_timer.h"

#include "cmsis_os.h"

extern uint32_t rt_time_get(void);

/*
 * Structure
 ****************************************************************************************
 */

typedef struct {
	char used;
	char onetime;
	char pad[2];

	void *arg;
	void (*callback)(void *);

} tim_dev_t;

static tim_dev_t tim_dev = {
	.used = 0,
	.onetime = 0,
};

/*
 * ISR
 ****************************************************************************************
 */
__irq void TIM1_Handler()
{
	tim_dev_t *pd = &tim_dev;

	/// clear timer interrupt
	timer_clear_intr(TIM1_BASE);

	/// call back if needs to
	if (pd->callback) {
		pd->callback(pd->arg);
	}

	/// if one time, stop timer
	if (pd->onetime) {
		timer_disable(TIM1_BASE);
		timer_intr_mask(TIM1_BASE, 1);
		NVIC_DisableIRQ(Tim1_IROn);

		pd->used = 0;
		pd->onetime = 0;
		pd->callback = NULL;
	}	
}

/*
 * APIs
 ****************************************************************************************
 */

int hal_timer_busy(void)
{
	return tim_dev.used;
}

int hal_timer_once(uint32_t msec, void *arg, void (*tmr_cb)(void *))
{
	tim_dev_t *pd = &tim_dev;
	uint32_t count;

	if (pd->used)
		return TIM_ERR_IN_USE;

	if (msec == 0)
		return TIM_ERR_INVALID_PARAM;	

	pd->used = 1;

	NVIC_ClearPendingIRQ(Tim1_IROn);
	timer_disable(TIM1_BASE);
	timer_set_mode(TIM1_BASE, 1);	
	count = (hal_clk_tim1_get()/1000) * msec;
	timer_load_count(TIM1_BASE, count);
	pd->onetime = 1;
	pd->arg = arg;
	pd->callback = tmr_cb;
	timer_intr_mask(TIM1_BASE, 0);	/// unmask it
	NVIC_SetPriority(Tim1_IROn, IRQ_PRI_AboveNormal);	
	NVIC_EnableIRQ(Tim1_IROn);
	timer_enable(TIM1_BASE);

	return TIM_ERR_OK;
}

int hal_timer_period_start(uint32_t msec, void *arg, void (*tmr_cb)(void *))
{
	tim_dev_t *pd = &tim_dev;
	uint32_t count;

	if (pd->used)
		return TIM_ERR_IN_USE;

	if (msec == 0)
		return TIM_ERR_INVALID_PARAM;	

	pd->used = 1;

	NVIC_ClearPendingIRQ(Tim1_IROn);
	timer_disable(TIM1_BASE);
	timer_set_mode(TIM1_BASE, 0);	
	count = (hal_clk_tim1_get()/1000) * msec;
	timer_load_count(TIM1_BASE, count);
	pd->onetime = 0;
	pd->arg = arg;
	pd->callback = tmr_cb;
	timer_intr_mask(TIM1_BASE, 0);	/// unmask it
	NVIC_SetPriority(Tim1_IROn, IRQ_PRI_AboveNormal);	
	NVIC_EnableIRQ(Tim1_IROn);
	timer_enable(TIM1_BASE);

	return TIM_ERR_OK;
}

int hal_timer_period_stop(void)
{
	tim_dev_t *pd = &tim_dev;

	if (!pd->used)
		return TIM_ERR_BAD_STATE;

	timer_disable(TIM1_BASE);
	timer_intr_mask(TIM1_BASE, 1);
	NVIC_DisableIRQ(Tim1_IROn);

	pd->used = 0;
	pd->callback = NULL;

	return TIM_ERR_OK;
}

int hal_timer_profile_start(uint32_t *tick_for_us)
{
	tim_dev_t *pd = &tim_dev;

	if (pd->used)
		return TIM_ERR_IN_USE;

	if (!tick_for_us)
		return TIM_ERR_INVALID_PARAM;	

	pd->used = 1;

	timer_disable(TIM1_BASE);
	timer_set_mode(TIM1_BASE, 1);	
	timer_load_count(TIM1_BASE, 0xFFFFFFFFUL);
	timer_intr_mask(TIM1_BASE, 1);	/// mask it
	timer_enable(TIM1_BASE);

	*tick_for_us = hal_clk_tim1_get()/1000000;

	return TIM_ERR_OK;
}

uint32_t hal_timer_profile_get_tick(void)
{
	/// Count down timer...
	uint32_t tick = 0xFFFFFFFFUL - timer_get_count(TIM1_BASE);

	return tick;
}

int hal_timer_profile_end(void)
{
	tim_dev_t *pd = &tim_dev;

	if (!pd->used)
		return TIM_ERR_BAD_STATE;

	timer_disable(TIM1_BASE);
	pd->used = 0;

	return TIM_ERR_OK;
}

int hal_timer_delay_us(uint32_t usec)
{
	tim_dev_t *pd = &tim_dev;
	uint32_t count;	

	if (pd->used)
		return TIM_ERR_IN_USE;

	pd->used = 1;

	timer_disable(TIM1_BASE);
	timer_set_mode(TIM1_BASE, 1);	// Free mode
	timer_intr_mask(TIM1_BASE, 0);	// unmask it
	count = (hal_clk_tim1_get()/1000000) * usec;
	timer_load_count(TIM1_BASE, count);
	timer_enable(TIM1_BASE);

	while (!(timer_intr_status(TIM1_BASE) & 0x1));

	timer_disable(TIM1_BASE);
	timer_clear_intr(TIM1_BASE);
	timer_intr_mask(TIM1_BASE, 1);	
	NVIC_ClearPendingIRQ(Tim1_IROn);

	pd->used = 0;

	return TIM_ERR_OK;
}

uint32_t hal_timer_get_systick(void)
{
	return rt_time_get();
}

