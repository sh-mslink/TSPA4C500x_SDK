#include "in_config.h"

#define CFG_NB_PWM (CFG_PWM0_EN+CFG_PWM1_EN+CFG_PWM2_EN+CFG_PWM3_EN+CFG_PWM4_EN)
/**
 ****************************************************************************************
 *
 * @file hal_pwm.c
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
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_pwm.h"
#if CFG_PM_EN
#include ".\hal\hal_power.h"
#endif

#include "cmsis_os.h"
#if (CFG_NB_PWM)

/*
 * Structures
 ****************************************************************************************
 */

typedef struct {
	char id;
	char used;
	char pad[2];

	uint32_t pwm_pin;

	IRQn_Type irq;
	uint32_t base;
	void *arg;
	void (*callback)(void *);

#if CFG_PM_EN
	int power_state;
	struct pm_module pmd;
#endif

} pwm_device_t;

static pwm_device_t pwm_dev[CFG_NB_PWM] = 
{
#if CFG_PWM0_EN
	{
		.id = PWM0_ID,
		.used = 0,
		.base = PWM0_BASE,
		.irq = Pwm0_IRQn,
	},
#endif	
#if CFG_PWM1_EN
	{
		.id = PWM1_ID,
		.used = 0,
		.base = PWM1_BASE,
		.irq = Pwm1_IRQn,
	},
#endif	
#if CFG_PWM2_EN
	{
		.id = PWM2_ID,
		.used = 0,
		.base = PWM2_BASE,
		.irq = Pwm2_IRQn,
	},
#endif	
#if CFG_PWM3_EN
	{
		.id = PWM3_ID,
		.used = 0,
		.base = PWM3_BASE,
		.irq = Pwm3_IRQn,
	},
#endif	
#if CFG_PWM4_EN
	{
		.id = PWM4_ID,
		.used = 0,
		.base = PWM4_BASE,
		.irq = Pwm4_IRQn,
	},
#endif	
};

/*
 * Pin Mux
 ****************************************************************************************
 */
static int pwm_pin_chk(pwm_device_t *pd)
{
	if (pd->id == PWM0_ID) {
		if (((CFG_GPIO_0_0	>> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_PWM_0)  {
			pd->pwm_pin = CFG_GPIO_0_0;
		} else {
			return 0;
		} 
	}

	if (pd->id == PWM1_ID) {
		if (((CFG_GPIO_0_1	>> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_PWM_1)  {
			pd->pwm_pin = CFG_GPIO_0_1;
		} else {
			return 0;
		}
	}

	if (pd->id == PWM2_ID) {
		if (((CFG_GPIO_0_2	>> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_PWM_2)  {
			pd->pwm_pin = CFG_GPIO_0_2;
		} else {
			return 0;
		}
	}

	if (pd->id == PWM3_ID) {
		if (((CFG_GPIO_1_7	>> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_PWM_3)  {
			pd->pwm_pin = CFG_GPIO_1_7;
		} else {
			return 0;
		}
	}

	if (pd->id == PWM4_ID) {
		if (((CFG_GPIO_1_8	>> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_PWM_4)  {
			pd->pwm_pin = CFG_GPIO_1_8;
		} else {
			return 0;
		}
	}

	return 1;
}

static void pwm_pin_mux_en(pwm_device_t *pd, int en)
{
	if (en) {
		hal_gpio_pin_cfg(pd->pwm_pin);
	} else {
		hal_gpio_pin_dft(pd->pwm_pin);
	}
}

/*
 * PM
 ****************************************************************************************
 */
#if CFG_PM_EN
static int pwm_pm_state(void *arg, uint32_t *sleep_duration)
{
	pwm_device_t *pd = (pwm_device_t *)arg;

	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->power_state;
}

static void pwm_pm_down(void *arg, uint32_t sleep_duration)
{
	return;
}

static void pwm_pm_up(void *arg)
{
	//pwm_device_t *pd = (pwm_device_t *)arg;
	//pwm_pin_mux_en(pd, 1);
}
#endif	// CFG_PM_EN

/*
 * ISR
 ****************************************************************************************
 */
static void pwm_isr(pwm_device_t *pd)
{
	uint32_t status = pwm_it_status(pd->base);
	if (status & 1) {
		if (pd->callback) {
			pd->callback(pd->arg);
		}
	}
}

__irq void PWM0_Handler(void)
{
	for (int i = 0; i < 	CFG_NB_PWM; i++) {
		if (pwm_dev[i].id == PWM0_ID) {
			pwm_isr(&pwm_dev[i]);
			break;
		}
	}

}

__irq void PWM1_Handler(void)
{
	for (int i = 0; i < 	CFG_NB_PWM; i++) {
		if (pwm_dev[i].id == PWM1_ID) {
			pwm_isr(&pwm_dev[i]);
			break;
		}
	}
}

__irq void PWM2_Handler(void)
{
	for (int i = 0; i < 	CFG_NB_PWM; i++) {
		if (pwm_dev[i].id == PWM2_ID) {
			pwm_isr(&pwm_dev[i]);
			break;
		}
	}
}

__irq void PWM3_Handler(void)
{
	for (int i = 0; i < 	CFG_NB_PWM; i++) {
		if (pwm_dev[i].id == PWM3_ID) {
			pwm_isr(&pwm_dev[i]);
			break;
		}
	}
}

__irq void PWM4_Handler(void)
{
	for (int i = 0; i < 	CFG_NB_PWM; i++) {
		if (pwm_dev[i].id == PWM4_ID) {
			pwm_isr(&pwm_dev[i]);
			break;
		}
	}
}

/*
 * APIs
 ****************************************************************************************
 */

void *hal_pwm_open(int id)
{
	pwm_device_t *pd = NULL;
	int i;

	for (i = 0; i < CFG_NB_PWM; i++) {
		if ((id == pwm_dev[i].id) && (!pwm_dev[i].used)) {
			pd = &pwm_dev[i];
			break;
		}
	}

	if (!pd) 
		return NULL;	

	// pin mux
	if (!pwm_pin_chk(pd))
		return NULL;

	// clock
	hal_clk_pwm_en(id, 1);

	// pin mux enable
	pwm_pin_mux_en(pd, 1);

	/// PM
#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
	pd->pmd.arg = (void *)pd;
	pd->pmd.power_state = pwm_pm_state;
	pd->pmd.power_down = pwm_pm_down;
	pd->pmd.power_up = pwm_pm_up;
	hal_pm_reg_mod(&pd->pmd);
#endif

	pd->used = 1;

	return pd;
}

int hal_pwm_close(void *hdl)
{
	pwm_device_t *pd = (pwm_device_t *)hdl;
	int err = PWM_ERR_OK;
	
	if (!pd)
 		return PWM_ERR_INVALID_PARAM;

	if (!pd->used) 
 		return PWM_ERR_BAD_STATE;

	pwm_disable(pd->base);
	pd->used = 0;

	// pin mux
	pwm_pin_mux_en(pd, 0);
	
	// clock
	hal_clk_pwm_en(pd->id, 0);

#if CFG_PM_EN
	hal_pm_unreg_mod(&pd->pmd);
#endif

	return err;
}

int hal_pwm_enable(void *hdl, uint32_t period_usec, uint32_t high_usec, void *arg, void (*callback)(void *) )
{
	pwm_device_t *pd = (pwm_device_t *)hdl;
	uint32_t pr_count, hi_count;
	int err = PWM_ERR_OK;
	
	if (!pd)
 		return PWM_ERR_INVALID_PARAM;
	
	if (!pd->used)
 		return PWM_ERR_BAD_STATE;

	pwm_disable(pd->base);
	
	pr_count = (hal_clk_d0_get()/1000000) * period_usec;
	hi_count = (hal_clk_d0_get()/1000000) * high_usec;
	pwm_config(pd->base, pr_count, hi_count);

	if (callback) {
		pd->arg = arg;
		pd->callback = callback;
		pwm_it_enable(pd->base);
		NVIC_SetPriority(pd->irq, IRQ_PRI_Normal);	
  		NVIC_EnableIRQ(pd->irq);
	}

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif
	
	pwm_enable(pd->base);

	return err;
}

int hal_pwm_adjust(void *hdl, uint32_t high_usec)
{
	pwm_device_t *pd = (pwm_device_t *)hdl;
	uint32_t hi_count;
	int err = PWM_ERR_OK;
	
	if (!pd)
 		return PWM_ERR_INVALID_PARAM;

	if (!pd->used)
 		return PWM_ERR_BAD_STATE;
	
	hi_count = (hal_clk_d0_get()/1000000) * high_usec;

	pwm_hr(pd->base, hi_count);

	return err;
}

int hal_pwm_disable(void *hdl)
{
	pwm_device_t *pd = (pwm_device_t *)hdl;
	int err = PWM_ERR_OK;
	
	if (!pd)
 		return PWM_ERR_INVALID_PARAM;

	if (!pd->used)
 		return PWM_ERR_BAD_STATE;

	pwm_disable(pd->base);
	NVIC_DisableIRQ(pd->irq);

#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif

	return err;
}
#endif	// CFG_NB_PWM
