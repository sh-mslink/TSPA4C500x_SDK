/**
 ****************************************************************************************
 *
 * @file inb_evt.h
 *
 * @brief BLE stack events
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef INB_EVT_H
#define INB_EVT_H

/**
 ****************************************************************************************
 * @defgroup INB_EVT BLE error code  
 * @ingroup BLE
 * @brief  BLE error code
 * @{
 ****************************************************************************************
 */

/// Events defines for Battery Services
enum 
{
	/// GAP event code start with 0x0000
	GAP_EVT_CODE = 0x0100,

	/// GATT event code start with 0x0300
	GATT_EVT_CODE = 0x0200,

	/// L2CAP event code start with 0x0200
	L2CAP_EVT_CODE = 0x0300,

	BAS_EVT_CODE = 0x0400,

	DIS_EVT_CODE = 0x0500,

	HOGP_EVT_CODE = 0x0600,

	INB_ANP_EVT_CODE = 0x0700,

	INB_PASP_EVT_CODE = 0x0800,

	INB_EVT_MAX = 0x8000,
};

typedef struct {
	/// ID of the event
	uint16_t evt_id;
	/// Variable size parameter for this event
	uint8_t param[];
} inb_evt_t;

/// @} INB_EVT

#endif	/* INB_EVT_H */

