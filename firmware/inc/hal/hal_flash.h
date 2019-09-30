#ifndef HAL_FLASH_H
#define HAL_FLASH_H


int hal_spi_flash_prog(uint32_t erase_addr, uint32_t erase_size, uint32_t prog_addr, uint32_t prog_size, uint8_t *prog_data, int verify);


#endif
