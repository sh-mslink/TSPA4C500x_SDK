/**
 ****************************************************************************************
 *
 * @file in_fw_upd.h
 *
 * @brief Firmware update header file 
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 *
 ****************************************************************************************
 */
#ifndef IN_FW_UPD_H
#define IN_FW_UPD_H

// Flash area store Firmware update releated information (Last 4K)
#define FW_UPD_INFO_ADDR		(0x37f000)
// Flash area store Firmware update releated information size ( 1 sector)
#define FW_UPD_INFO_SIZE			(4*1024)

// Firmware update magic word
#define FW_UPD_MAGIC_WORD					0xC3695A1E

// Number of service attributes
#define FW_UPD_ATT_NB 								7

// Firmware update OTA Service UUID
#define FW_UPD_ATT_SVC_UUID 							0xE4,0xCC,0xDB,0xE2,0x2A,0x02,0xA3,0xA2,0xE9,0x11,0x21,0xA7,0xE6,0x48,0x5A,0xF9
// Firmware current version characteristic UUID 
#define FW_UPD_ATT_FW_VER_CHAR_UUID 			0xE4,0xCC,0xDB,0xE2,0x2A,0x02,0xA3,0xA2,0xE9,0x11,0x21,0xA7,0x66,0x4B,0x5A,0xF9
// Firmware update information characteristic UUID
#define FW_UPD_ATT_FW_INFO_CHAR_UUID 			0xE4,0xCC,0xDB,0xE2,0x2A,0x02,0xA3,0xA2,0xE9,0x11,0x21,0xA7,0x34,0x50,0x5A,0xF9
// Firmware update new firmware data characteristic UUID
#define FW_UPD_ATT_FW_DATA_CHAR_UUID 			0xE4,0xCC,0xDB,0xE2,0x2A,0x02,0xA3,0xA2,0xE9,0x11,0x21,0xA7,0xCE,0x4C,0x5A,0xF9
// Firmware update new firmware data characteristic UUID
#define FW_UPD_ATT_FW_ERR_CHAR_UUID 			0xe3,0x9a,0x5c,0x88,0x03,0x81,0xe0,0x91,0x5b,0x4e,0xfc,0x81,0x6d,0xff,0x4c,0xec //ec4cff6d-81fc-4e5b-91e0-8103885c9ae3


// Firmware donwload data (without header) max length
#define FW_UPD_DNLD_DATA_MAX_LEN 								1024

// Firmware update information
typedef struct {
	// Firmware update magic word
	uint32_t upd_magic;
	// New firmware load start address
	uint32_t load_addr;
	// New firmware destination startaddress
	uint32_t copy_addr;
	// New firmware total size
	uint32_t size;
} fw_upd_info_t;

// Firmware update donwloaded information
typedef struct {
	// Flash start address for the new firmware to be loaded into
	uint32_t load_addr;
	// Flash start address for the new firmware to be copied into  
	uint32_t copy_addr;
	// New firmware total size
	uint32_t size;
} fw_dnld_info_t;

// Firmware download data packet header
typedef struct {
	// Flash address for the new data
	uint32_t addr;
	// New data length
	//uint32_t length;
} fw_dnld_data_t;

#endif	// IN_FW_UPD_H
