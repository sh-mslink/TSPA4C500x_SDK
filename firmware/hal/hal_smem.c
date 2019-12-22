#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_smem.c
 *
 * @brief Share memory driver implementation file  
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
#include ".\hal\hal_smem.h"

void hal_smem_init(void)
{
	uint32_t size, offset;

	smem_enable();

	/// BLE shared memory
	size = CFG_SMEM_BLE & 0xFFFF;
	offset = (CFG_SMEM_BLE>>16) & 0xFFFF;
	if (size) {
		smem_ble_en(1, offset);		
	} else {
		smem_ble_en(0, 0);		
	}

	/// Antena control Rx data shared memory
	size = CFG_SMEM_ANT_RX_DATA & 0xFFFF;
	offset = (CFG_SMEM_ANT_RX_DATA>>16) & 0xFFFF;
	if (size) {
		smem_antena_rx_en(1, offset);		
	} else {
		smem_antena_rx_en(0, 0);		
	}

	/// Audio Rx channel shared memory
	size = CFG_SMEM_AUDIO_RX & 0xFFFF;
	offset = (CFG_SMEM_AUDIO_RX>>16) & 0xFFFF;
	if (size) {
		smem_audio_rx_en(1, offset);		
	} else {
		smem_audio_rx_en(0, 0);		
	}

	/// Audio Tx channel shared memory
	size = CFG_SMEM_AUDIO_TX & 0xFFFF;
	offset = (CFG_SMEM_AUDIO_TX>>16) & 0xFFFF;
	if (size) {
		smem_audio_tx_en(1, offset);		
	} else {
		smem_audio_tx_en(0, 0);		
	}

	/// Hardware accelerator instructions shared memory
	size = CFG_SMEM_HW_ACCEL_INST & 0xFFFF;
	offset = (CFG_SMEM_HW_ACCEL_INST>>16) & 0xFFFF;
	if (size) {
		smem_hwacc_en(1, offset);		
	} else {
		smem_hwacc_en(0, 0);		
	}

	/// Sensor ADC data storage shared memory
	size = CFG_SMEM_SADC & 0xFFFF;
	offset = (CFG_SMEM_SADC>>16) & 0xFFFF;
	if (size) {
		smem_sadc_en(1, offset);		
	} else {
		smem_sadc_en(0, 0);		
	}

	/// AHB trigger command storage shared memory
	size = CFG_SMEM_AHB_TRIG & 0xFFFF;
	offset = (CFG_SMEM_AHB_TRIG>>16) & 0xFFFF;
	if (size) {
		smem_ahb_trig_en(1, offset);		
	} else {
		smem_ahb_trig_en(0, 0);		
	}
}

void hal_smem_retn(int en, uint32_t offset, uint32_t size)
{
	uint32_t retn;

	if (offset < (4 * 1024)) {
		retn = PM_RETN_EM_4K_A; 	
		if (size >= (4*1024))
			retn |= PM_RETN_EM_4K_B;
		if (size >= (8*1024))
			retn |= PM_RETN_EM_8K_A;
		if (size >= (16*1024))
			retn |= PM_RETN_EM_8K_B;
		if (size >= (24*1024))
			retn |= PM_RETN_EM_16K;
	} else if ((offset >= (4 * 1024)) && (offset < (8 * 1024))) {
		retn = PM_RETN_EM_4K_B; 	
		if (size >= (4*1024))
			retn |= PM_RETN_EM_8K_A;
		if (size >= (12*1024))
			retn |= PM_RETN_EM_8K_B;
		if (size >= (20*1024))
			retn |= PM_RETN_EM_16K;
	} else if ((offset >= (8 * 1024)) && (offset < (16 * 1024))) {
		retn = PM_RETN_EM_8K_A; 	
		if (size >= (8*1024))
			retn |= PM_RETN_EM_8K_B;
		if (size >= (16*1024))
			retn |= PM_RETN_EM_16K;
	} else if ((offset >= (16 * 1024)) && (offset < (24 * 1024))) {
		retn = PM_RETN_EM_8K_B; 	
		if (size >= (8*1024))
			retn |= PM_RETN_EM_16K;
	} else if ((offset >= (24 * 1024)) && (offset < (40 * 1024))) {
		retn = PM_RETN_EM_16K;
	}

	aon_em_reten(en, retn);
}
