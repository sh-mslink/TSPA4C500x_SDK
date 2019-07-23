/**
 ****************************************************************************************
 *
 * @file inb_prf_anp.h
 *
 * @brief BLE Alert Notification Service
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef INB_PRF_PASP_H
#define INB_PRF_PASP_H

/**
 ****************************************************************************************
 * @defgroup INB_PRF_ANP BLE Alert Notification Service  
 * @ingroup BLE_PRF
 * @brief  BLE Alert Notification Service
 * @{
 ****************************************************************************************
 */

#include <stdint.h>
#include ".\ble\inb_prf.h"


enum inb_pasp_ringer_setting
{
	/// Ringer Settings Keys
	INB_PASP_RINGER_SILENT 	= (0),
	INB_PASP_RINGER_NORMAL	= (1),
};

enum inb_pasp_alert_status
{
	/// Alert Status Flags
	INB_PASP_RINGER_ACTIVE              		= (0x01),
	INB_PASP_VIBRATE_ACTIVE             		= (0x02),
	INB_PASP_DISP_ALERT_STATUS_ACTIVE	= (0x04),
	INB_PASP_ALERT_STATUS_VAL_MAX       	= (0x07),
};

enum inb_pasp_cmd
{
	/// Ringer Control Point Keys
	INB_PASP_SILENT_MODE_CMD			= (1),
	INB_PASP_MUTE_ONCE_CMD				= (2),
	INB_PASP_CANCEL_SILENT_MODE_CMD	= (3),
};

/// Events defines for ANP Services
enum inb_pasp_evt 
{
	INB_EVT_PASPC_ALERT_STATUS_UPDATE = INB_PASP_EVT_CODE +1,

	INB_EVT_PASPC_RINGER_SETTING_UPDATE,

	//Informed that value of one of the two Client Characteristic Configuration Descriptors has been
	//written by the peer device
	INB_EVT_PASPS_ALERT_STATUS_NTF_CFG_UPDATE_IND,
	INB_EVT_PASPS_RINGER_SETTING_NTF_CFG_UPDATE_IND,

	INB_EVT_PASPS_CMD_IND,
};

typedef struct
{
	// Connection index
	uint8_t conidx;

	enum inb_ntf_cfg ntf_status;
} inb_evt_pasps_ntf_cfg_update_ind_t;

typedef struct
{
	// Connection index
	uint8_t conidx;

	enum inb_pasp_cmd cmd;
} inb_evt_pasps_cmd_ind_t;

typedef struct 
{
	// Connection index
	uint8_t conidx;

	enum inb_pasp_alert_status alert_status;
} inb_evt_paspc_alert_status_update_ind_t;

typedef struct 
{
	// Connection index
	uint8_t conidx;

	enum inb_pasp_ringer_setting ringer_setting;
} inb_evt_paspc_ringer_setting_update_ind_t;

/*
 * APIs
 ****************************************************************************************
 */
//int inb_anpc_add(inb_add_prf_t *p_prf);


#endif	/* INB_PRF_PASP_H */

