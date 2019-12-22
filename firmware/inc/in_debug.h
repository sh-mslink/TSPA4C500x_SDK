#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file in_debug.h
 *
 * @brief Tropos Debug configuration
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 *
 ****************************************************************************************
 */

#ifndef IN_DEBUG_H
#define IN_DEBUG_H

#include <stdio.h>
#include <assert.h>



#if CFG_DBG_EN
#if CFG_DBG_IF_RTT_VIEW
#include "..\thirdparty\segger\inc\segger_rtt.h"
#define PRINTD(flag, fmt, ...) do { \
		if (flag & CFG_DBG_FLAG) { \
			SEGGER_RTT_printf(0, fmt,  ##__VA_ARGS__); \
		} \
	} while(0)
#endif	// CFG_DBG_IF_RTT_VIEW

#if CFG_DBG_IF_UART
#include "in_arm.h"

#define PRINTD(flag, fmt, ...) do { \
		if (flag & CFG_DBG_FLAG) { \
			printf(fmt,  ##__VA_ARGS__); \
		} \
	} while(0)
#endif	// CFG_DBG_IF_UART

#else	// CFG_DBG_EN 
#define PRINTD(flag, fmt, ...) 
#endif	// CFG_DBG_EN 

#endif	// IN_DEBG_H
