/**
 ****************************************************************************************
 *
 * @file hal_flash.h
 *
 * @brief SPI Flash driver header file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
#ifndef HAL_FLASH_H
#define HAL_FLASH_H
#include <stdint.h>
/**
 ****************************************************************************************
 * @defgroup HAL_SPI_FLASH SPI Flash driver  
 * @ingroup HAL
 * @brief  HAL_SPI_FLASH
 * @{
 ****************************************************************************************
 */
enum flash_error {
	FLASH_ERR_OK,
	FLASH_ERR_ERASE_FAIL,
	FLASH_ERR_VERIFY_FAIL,
	FLASH_ERR_INVALID_PARAM,
};




/** 
 * @brief Erase SPI Flash sector
 * @note Now one sector is 4K bytes. erase_addr should be 4K bytes aligned. This function only erase 4K bytes.
 *          If user want to erase more sector, call this function with new sector address.
 * @param[in] erase_addr   Erase address
 * @return  @see enum flash_error for return code.
 * */
int hal_spi_flash_sector_erase(uint32_t erase_addr);

/** 
 * @brief Programme SPI Flash page
 * @note Now one page is 256 bytes. prog_size should be smaller then 256. This function only programme one page.
 *          If user want to erase more page, call this function with new page address.
 * @param[in] prog_addr     Programme address.
 * @param[in] prog_size     Programme size. This size shoudle be be smaller then 256. And (prog_addr + prog_size) should be in the same page.
 * @param[in] prog_data     Programme data buffer.
 * @return  @see enum flash_error for return code.
 * */
int hal_spi_flash_prog_page(uint32_t prog_addr, uint32_t prog_size, uint8_t *prog_data);

/** 
 * @brief Verify SPI Flash data
 * @note Read data from addr, and compare data in data buffer.
 * @param[in] addr          Flash read address.
 * @param[in] data          Data buffer.
 * @param[in] size          Data size.
 * @return  @see enum flash_error for return code.
 * */
int hal_spi_flash_verify(uint32_t addr, uint8_t *data, uint32_t size);

/** 
 * @brief Flash erase and programme function.
 * @param[in] erase_addr    Erase address.
 * @param[in] erase_size    Erase size. 
 * @param[in] prog_addr     Programme address.
 * @param[in] prog_size     Programme size.
 * @param[in] prog_data     Programme data buffer.
 * @param[in] verify        1 is verify, 0 is not verify.
 * @return  @see enum flash_error for return code.
 * */
int hal_spi_flash_prog(uint32_t erase_addr, uint32_t erase_size, uint32_t prog_addr, uint32_t prog_size, uint8_t *prog_data, int verify);


/// @} HAL_I2C
#endif
