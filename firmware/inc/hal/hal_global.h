/**
 ****************************************************************************************
 *
 * @file hal_global.h
 *
 * @brief HAL Global   
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef HAL_GLOBAL_H
#define HAL_GLOBAL_H

#include "in_mmap.h"

/**
 ****************************************************************************************
 * @defgroup HAL_GLOBAL Platform globally initialization, suspend, and resume functions   
 * @ingroup HAL
 * @brief  HAL_GLOBAL
 * @{
 ****************************************************************************************
 */

/*
 * Enumeration
 ****************************************************************************************
 */
enum data_ram_access_prio {
	DATA_RAM_ACCESS_PRIO_1=0,	// Highest
	DATA_RAM_ACCESS_PRIO_2=1,
	DATA_RAM_ACCESS_PRIO_3=2,
};

/*
 * Inine
 ****************************************************************************************
 */
static __inline uint32_t chip_get_id(void)
{
	return (RD_WORD(GLOBAL_REG_CHIP_ID) & (GLOBAL_REG_CHIP_ID_VERSION|GLOBAL_REG_CHIP_ID_SUBVERSION));
}
static __inline uint32_t fw_get_version(void)
{
	return RD_WORD(0x3FFF8) ;
}

static __inline uint32_t chip_sleep(void)
{
	return (WR_WORD(GLOBAL_REG_SLEEP_CTRL, 1));
}

static __inline void data_ram_access_prio(int cpu_i_prio, int cpu_d_prio, int dma_prio)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_AHB_CTRL_1);

	reg &= ~GLOBAL_REG_AHB_CTRL_1_CTL_ICM_D2_DATA_CODE_RAM_PRIORITY ;
	reg |= ((cpu_i_prio & 0x3) << 0) | ((cpu_d_prio & 0x3) << 2) | ((dma_prio & 0x3) << 4);
	WR_WORD(GLOBAL_REG_AHB_CTRL_1, reg);
}

/*
 * APIs
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief  Globally initialize system (such as clock...) before OS starting.  
 *
 *
 * @return  No return
 ****************************************************************************************
 */
void hal_global_pre_init(void);

/**
 ****************************************************************************************
 * @brief  Globally initialize system (such as debug, RTC...) after OS starting.  
 *
 *
 * @return  No return
 ****************************************************************************************
 */
void hal_global_post_init(void);

/**
 ****************************************************************************************
 * @brief  Globally save system (such as system tick...) registers before deep sleep.  
 *
 *
 * @return  No return
 ****************************************************************************************
 */
void hal_global_suspend(void);

/**
 ****************************************************************************************
 * @brief  Globally resume system (such as system tick...) registers after wake up.  
 *
 *
 * @return  No return
 ****************************************************************************************
 */
void hal_global_resume(void);

/**
 ****************************************************************************************
 * @brief  Reset the system (cold boot)  
 *
 *
 * @return  No return
 ****************************************************************************************
 */
void hal_global_sys_reset(void);

void hal_global_debug_uart_init(void);

/// @} HAL_GLOBAL

#endif 	// HAL_GLOBAL_H
