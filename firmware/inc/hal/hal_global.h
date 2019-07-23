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

static __inline uint32_t chip_get_id(void)
{
	return (RD_WORD(GLOBAL_REG_CHIP_ID) & (GLOBAL_REG_CHIP_ID_VERSION|GLOBAL_REG_CHIP_ID_SUBVERSION));
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

/// @} HAL_GLOBAL

#endif 	// HAL_GLOBAL_H
