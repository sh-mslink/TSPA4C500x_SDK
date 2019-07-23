#ifndef BOOT_CONFIG_H
#define BOOT_CONFIG_H

#include "boot_share.h"

#define CFG_EXT_SPI_FLASH 1

#define CFG_SPI_FLASH_READ_SPEED 2000000

#define CFG_BOOT_SERIAL_INTERFACE SIF_UART0

// high protected block
#define CFG_BOOT_HPB_FLASH_ADDR 0x301000
#define CFG_BOOT_HPB_RAM_ADDR 0x201000
#define CFG_BOOT_HPB_SIZE 284

// cold boot options
#define CFG_BOOT_OPTION BOOT_NO_OPTION
#if (CFG_BOOT_OPTION == BOOT_WAIT)
#define CFG_BOOT_WAIT_TIME 10	// 1 second
#else  
#define CFG_BOOT_WAIT_TIME 0	
#endif
#if (CFG_BOOT_OPTION == BOOT_GPIO)
#define CFG_BOOT_GPIO_GRP 4
#define CFG_BOOT_GPIO_PIN 0
#define CFG_BOOT_GPIO_LEVEL 1
#else  
#define CFG_BOOT_GPIO_GRP 0
#define CFG_BOOT_GPIO_PIN 0
#define CFG_BOOT_GPIO_LEVEL 0
#endif

// secure boot
#define CFG_SECURE_BOOT_HASH_ADDR 0x301000
#define CFG_SECURE_BOOT_HASH_SIZE 0x1bf4
#define CFG_SECURE_BOOT_ECDSA_SIG \
0xf7, 0x5f, 0xd0, 0xaa, 0x99, 0x03, 0x18, 0x3b, 0x72, 0x62, 0xeb, 0x93, 0x0f, 0x55, 0xdd, 0x02, \
0x54, 0xc8, 0x98, 0x2a, 0x9b, 0x91, 0x68, 0xaa, 0xe4, 0x6e, 0xaf, 0xca, 0x31, 0xda, 0x8b, 0x38, \
0x38, 0x60, 0x5d, 0xf3, 0xe9, 0x86, 0x78, 0x3a, 0xe0, 0x76, 0xc2, 0xab, 0xb2, 0x02, 0x0f, 0x07, \
0x3f, 0x9c, 0x42, 0xbc, 0xad, 0xa7, 0xd1, 0x1c, 0xd6, 0x33, 0x7d, 0x6d, 0x67, 0xc2, 0x06, 0x48, 

// cold boot start address:  vector table address
#if CFG_EXT_SPI_FLASH 
#define CFG_COLD_BOOT_START_ADDR 0x301000
#else
#define CFG_COLD_BOOT_START_ADDR 0x200100
#endif

#define CFG_HPB 0
#define CFG_NPB 0
#endif
