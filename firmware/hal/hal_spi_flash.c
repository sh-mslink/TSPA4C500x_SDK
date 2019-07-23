#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_spi_flash.c
 *
 * @brief Platform run time write to SPI flash functions  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#include <stdint.h>

#include "in_arm.h"
#include "in_mmap.h"

#include "..\bootloader\inc\boot_share.h"

int hal_spi_flash_prog(uint32_t erase_addr, uint32_t erase_size, uint32_t prog_addr, uint32_t prog_size, uint8_t *prog_data, int verify)
{
	boot_ram_entry_t entry = (boot_ram_entry_t)(BOOTRAM_CODE_START|1);		// 1 is for the thumb instruction
	spi_flash_rt_write_t sfw;

	sfw.erase_addr = erase_addr;
	sfw.erase_len = erase_size;
	sfw.data_addr = prog_addr;
	sfw.data_len = prog_size;
	sfw.data = prog_data;
	sfw.verify = verify;
	
	__disable_irq();

	entry(SPI_FLASH_RT_WRITE, (void *)&sfw);
	
	__enable_irq();

	return sfw.status;

}
