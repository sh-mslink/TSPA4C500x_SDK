#ifndef BOOT_RAM_H
#define BOOT_RAM_H

#include <stdint.h>
#include "bootram_mem.h"

#define BOOT_MAGIC_WORD 0xA72E0129

typedef void (*boot_ram_entry_t)(int, void *);

enum serial_interface {
	SIF_NONE, 
	SIF_UART0,
	SIF_UART1,
	SIF_SSPI,
};

enum boot_options{
	BOOT_NO_OPTION = 0,
	BOOT_WAIT,
	BOOT_GPIO,
};

enum entry_reason {
	SPI_FLASH_CB = 1,
	COLD_BOOT,
	WARM_BOOT,
	SPI_FLASH_RT_WRITE,					// run time spi flash program
	PM_SAVE_CLK_CFG,						// Save clk configuration 
};

typedef struct {
	int (*sflash_open)(void);
	int (*sflash_erase)(uint32_t addr, uint32_t size);
	int (*sflash_prog)(uint32_t addr, uint8_t *data, uint32_t data_len);
	int (*sflash_read)(uint32_t addr, uint8_t *data, uint32_t data_len);
	int (*sflash_close)(void);
} spi_flash_cb_t;

typedef struct {
	uint32_t reserve;

	int 			sspi_intr_enable;
	uint32_t 	sspi_intr_gio_grp;
	uint32_t 	sspi_intr_gio_pin;
	uint32_t 	sspi_intr_gio_level;

	uint32_t 	hpb_flash_addr;
	uint32_t 	hpb_ram_addr;
	uint32_t 	hpb_size;

	uint32_t 	boot_opt;
	uint32_t 	boot_wait_time;
	uint32_t 	boot_gio_grp;
	uint32_t 	boot_gio_pin;
	uint32_t 	boot_gio_level;
	
	uint32_t secure_img_addr;
	uint32_t secure_img_size;
	uint8_t secure_signature[64];

	uint32_t magic_word;
} boot_config_t;

enum spi_flash_rt_prog_status {
	STATUS_OK,
	STATUS_ERASE_FAIL,
	STATUS_VERIFY_FAIL,
};

typedef struct {
	uint32_t erase_addr;
	uint32_t erase_len;
	uint32_t data_addr;
	uint32_t data_len;
	uint8_t *data;
	int verify;
	int status;
} spi_flash_rt_write_t;

#endif
