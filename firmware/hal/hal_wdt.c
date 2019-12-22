#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_wdt.c
 *
 * @brief Watch Dog Timer implementation file  
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
#include ".\hal\hal_power.h"
#include ".\hal\hal_wdt.h"

#if CFG_WDT_EN
/*
 * Structure
 ****************************************************************************************
 */
#if CFG_PM_EN
typedef struct {
	uint8_t mode;
	uint8_t tmo_init;
	uint8_t tmo;
	
	struct pm_module pmd;
} wdt_pm_t;

static wdt_pm_t g_wd;
#endif	

/*
 * ISR
 ****************************************************************************************
 */

__irq void NMI_Handler(void)
{
	PRINTD(DBG_ERR, "~~~NMI~~~");
}

__irq void WDT_Handler(void)
{
	wdt_intr_clr();
}

/*
 * PM
 ****************************************************************************************
 */
#if CFG_PM_EN
static int wdt_pm_state(void *arg, uint32_t *sleep_duration)
{
	*sleep_duration = PM_MAX_SLEEP_TIME;
	return PM_DEEP_SLEEP;
}

static void wdt_pm_down(void *arg, uint32_t sleep_duration)
{
	return;
}

static void wdt_pm_up(void *arg)
{
	wdt_pm_t *p = (wdt_pm_t *)arg;

	/// Time out period
	wdt_tmo_period(p->tmo_init, p->tmo);

	/// Enable interrupt if response mode is interrupt
	if (p->mode == WDT_MODE_INTR) {
		NVIC_SetPriority(Wdt_IRQn, IRQ_PRI_AboveNormal);	
		NVIC_EnableIRQ(Wdt_IRQn);
	}

	/// Enable it
	wdt_enable(p->mode);

	/// Touch it to load the initial value
	wdt_touch();
}
#endif

/*
 * APIs
 ****************************************************************************************
 */
void hal_wdt_start(int mode, uint32_t tmo_init, uint32_t tmo)
{
	/// Turn on WDT clock
	hal_clk_wdt_en(1);

	/// Time out period
	wdt_tmo_period(tmo_init, tmo);

	/// Enable interrupt if response mode is interrupt
	if (mode == WDT_MODE_INTR) {
		NVIC_SetPriority(Wdt_IRQn, IRQ_PRI_AboveNormal);	
		NVIC_EnableIRQ(Wdt_IRQn);
	}

	/// Enable it
	wdt_enable(mode);

	/// Touch it to load the initial value
	wdt_touch();

#if CFG_PM_EN
	/// Register with PM 
	g_wd.mode = (uint8_t)mode;
	g_wd.tmo_init = (uint8_t)tmo_init;
	g_wd.tmo = (uint8_t)tmo;

	g_wd.pmd.arg = &g_wd;
	g_wd.pmd.power_state = wdt_pm_state;
	g_wd.pmd.power_down = wdt_pm_down;
	g_wd.pmd.power_up = wdt_pm_up;

	hal_pm_reg_mod(&g_wd.pmd);
#endif

}

void hal_wdt_touch(void)
{
	wdt_touch();
}
#endif	// CFG_WDT_EN

