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
#include <string.h>
#include "in_arm.h"
#include "in_mmap.h"
#include "hal\hal_flash.h"
#include "..\bootloader\inc\boot_share.h"
#define SPI_FLASH_BASE_ADDR (0x300000)
#define SPI_FLASH_SIZE (0x80000)
#define SPI_FLASH_PAGE_SIZE		(256)
#define SPI_FLASH_SECTOR_SIZE (4 * 1024)

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
int hal_spi_flash_erase_sector(uint32_t erase_addr)
{
	if ((erase_addr < SPI_FLASH_BASE_ADDR) || (erase_addr >= (SPI_FLASH_BASE_ADDR + SPI_FLASH_SIZE))) {
		return FLASH_ERR_INVALID_PARAM;
	}
	return hal_spi_flash_prog(erase_addr, SPI_FLASH_SECTOR_SIZE, 0, 0, NULL, 0);
}
int hal_spi_flash_prog_page(uint32_t prog_addr, uint32_t prog_size, uint8_t *prog_data)
{
	if ((prog_addr < SPI_FLASH_BASE_ADDR) || ((prog_addr + prog_size) >= (SPI_FLASH_BASE_ADDR + SPI_FLASH_SIZE)) || (prog_size <= 0) || (!prog_data)) {
		return FLASH_ERR_INVALID_PARAM;
	}
	if ((prog_addr + prog_size) > ((prog_addr /SPI_FLASH_PAGE_SIZE + 1) * SPI_FLASH_PAGE_SIZE))
		return FLASH_ERR_INVALID_PARAM;
	return hal_spi_flash_prog(0, 0, prog_addr, prog_size, prog_data, 0);
}
int hal_spi_flash_verify(uint32_t addr, uint8_t *data, uint32_t size)
{
	int res = FLASH_ERR_OK;
	if ((data == NULL) || (size <= 0) || (addr < SPI_FLASH_BASE_ADDR) || ((addr + size) >= (SPI_FLASH_BASE_ADDR + SPI_FLASH_SIZE)))
		return FLASH_ERR_INVALID_PARAM;
	res = memcmp((uint8_t *)addr, data, size);
	return (res == 0) ? FLASH_ERR_OK : FLASH_ERR_VERIFY_FAIL;
}

