/**
 ****************************************************************************************
 *
 * @file hal_icache.h
 *
 * @brief  instruction cache header file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef HAL_ICACHE_H
#define HAL_ICACHE_H

#include "in_mmap.h"

static __inline void icache_clear_mem(void)
{
	uint32_t reg;

	WR_WORD(ICACHE_REG_MISC_CTRL, ICACHE_REG_MISC_CTRL_CTL_SRAM_CLR);
	while (1) {
		reg = RD_WORD(ICACHE_REG_INTR_STATUS);
		if (reg & ICACHE_REG_INTR_STATUS_SRAM_CLEAR_DONE)
			break;
	}
}

static __inline void icache_en(int en)
{
	if (en) {
		WR_WORD(ICACHE_REG_MISC_CTRL, ICACHE_REG_MISC_CTRL_CTL_CACHE_EN);
		RD_WORD(ICACHE_REG_MISC_CTRL);	// Make sure it is enable
	} else {
		WR_WORD(ICACHE_REG_MISC_CTRL, ICACHE_REG_MISC_CTRL_DEFAULT);
		WR_WORD(ICACHE_REG_MISC_CTRL, ICACHE_REG_MISC_CTRL_CTL_SRAM_CLR);
	}
}

#endif	// HAL_ICACHE_H
