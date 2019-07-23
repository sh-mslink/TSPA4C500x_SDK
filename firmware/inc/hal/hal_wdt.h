/**
 ****************************************************************************************
 *
 * @file hal_wdt.h
 *
 * @brief Watch Dog Timer header file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef HAL_WDT_H
#define HAL_WDT_H

/**
 ****************************************************************************************
 * @defgroup HAL_WDT Watch dog timer driver  
 * @ingroup HAL
 * @brief  HAL_WDT
 * @{
 ****************************************************************************************
 */

#include "in_mmap.h"

/*
 * Defines
 ****************************************************************************************
 */

#define WDT_REG_CR_OFS	0x00000000UL
#define WDT_REG_TOR_OFS	0x00000004UL
#define WDT_REG_CVR_OFS	0x00000008UL
#define WDT_REG_CRR_OFS	0x0000000CUL
#define WDT_REG_ISR_OFS	0x00000010UL
#define WDT_REG_EOI_OFS	0x00000014UL

#define WDT_CR_WDT_EN		0x00000001UL
#define WDT_CR_RMOD		0x00000002UL

#define WDT_TORR_TOP		0x0000000FUL
#define WDT_TORR_TOP_INIT	0x000000F0UL

/*
 * Inline Functions
 ****************************************************************************************
 */

static __inline void wdt_enable(int mode)
{
	WR_WORD(WDT_BASE + WDT_REG_CR_OFS, (WDT_CR_WDT_EN | ((mode & 0x1) << 1))); 
}

static __inline void wdt_tmo_period(uint32_t bits_init, uint32_t bits)
{
	WR_WORD(WDT_BASE + WDT_REG_TOR_OFS, (((bits_init & 0xF) << 4) | (bits & 0xF)));	
}

static __inline uint32_t wdt_counter_val(void)
{
	return RD_WORD(WDT_BASE + WDT_REG_CVR_OFS);
}

static __inline void wdt_touch(void)
{
	WR_WORD(WDT_BASE + WDT_REG_CRR_OFS, 0x76);
}

static __inline uint32_t wdt_intr_status(void)
{
	return RD_WORD(WDT_BASE + WDT_REG_ISR_OFS);
}

static __inline uint32_t wdt_intr_clr(void)
{
	return RD_WORD(WDT_BASE + WDT_REG_EOI_OFS);
}

/*
 * Enumeratios
 ****************************************************************************************
 */

/// Watch dog timer response mode
enum wdt_mode {
	/// Issue a system reset.
	WDT_MODE_RESET,
	/// Interrupt first, and then system reset if the interrupt is not clear within the watch dog timer period. 
	WDT_MODE_INTR,
};

/*
 * Functions
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Enable watch dog timer
 * @note Once watch dog timer enable, it can't be disabled until a system reset.  The time out period is calculated as follow:
 *						time out period = 2 ^ (16 + tmo) / (D0 domain clock);
 *						For example:
 *							D0 domain clock = 32000000;
 *							tmo = 10;
 *							Watch dog timer expire at = 2 ^ (16 + 10) / 32000000
 *																	  = 2.097 seconds
 *
 * @param[in] mode					Watch dog timer expire response mode, @see enum wdt_mode.   
 * @param[in] tmo_init				Timeout period for initialization, range is from 0 ~ 15.
 * @param[in] tmo					Timeout period, range is from 0 ~ 15.
 *
 * @return void. This function has no return value. 
 ****************************************************************************************
 */

void hal_wdt_en(int mode, uint32_t tmo_init, uint32_t tmo);

/**
 ****************************************************************************************
 * @brief Reload the watch dog timer counter
 * @note If WDT response mode set to WDT_MODE_INTR, then there is no need to call this function since ISR 
 * 		will touch it.
 *
 * @param[in] void 		This function has not input.  
 *
 * @return void. This function has no return value. 
 ****************************************************************************************
 */

void hdl_wdt_touch(void);

/// @} HAL_WDT

#endif		// HAL_WDT_H
