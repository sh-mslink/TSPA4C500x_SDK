/**
 ****************************************************************************************
 *
 * @file inb_prf_anp.h
 *
 * @brief BLE Alert Notification Service
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
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
	///If the service is multi-instance
	bool multi_instance;

	/*The following params are for PASPS only*/
	
	///If let the service check whether encryption key size is 16bytes (more security).
	bool check_enc_key_size;

	/// Security Level, @see enum inb_att_svc_perm_mask
	enum inb_att_perm sec_lvl;
	
	enum inb_pasp_alert_status		alert_status;
	enum inb_pasp_ringer_setting	ringer_setting;
} inb_pasp_prf_t;

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
/**
***************************************************************************************************
 @brief  Add PASP service. It's the first function called

 @param[in] p_prf					Pointer to profile attributes, @see inb_pasp_prf_t

 @return	@see INB_ERR_NO_ERROR 
 		@see INB_PLT_ERR_NOT_READY 
 		@see INB_PLT_ERR_NO_MEM
 **************************************************************************************************
 */
 int inb_pasps_add(inb_pasp_prf_t *p_prf);

/**
***************************************************************************************************
 @brief Enable PASP service.

 @param[in]   	conidx: 	connection index

 @note	It is called after connection or reconnection with a peer device has been established in order to restore 
 		previous config on that connection
 @return	@see INB_ERR_NO_ERROR
 		@see INB_PLT_ERR_NOT_READY
 		@see INB_PLT_ERR_NO_MEM
 **************************************************************************************************
 */
int inb_pasps_enable(int conidx);

/**
***************************************************************************************************
 @brief Update phone alert status in PASP service.

 @param[in]   	conidx: 	connection index
 @param[in]	alert_status: new phone alert status to update @see inb_pasp_alert_status

 @return	@see INB_ERR_NO_ERROR
 		@see INB_PLT_ERR_NOT_READY
 		@see INB_PLT_ERR_NO_MEM
 **************************************************************************************************
 */
int inb_pasps_update_alert_status(int conidx, enum inb_pasp_alert_status	alert_status);

/**
***************************************************************************************************
 @brief Update phone ringer setting in PASP service.

 @param[in]   	conidx: 			connection index
 @param[in]	ringer_setting: 	new ringer setting to update @see inb_pasp_ringer_setting

 @return	@see INB_ERR_NO_ERROR
 		@see INB_PLT_ERR_NOT_READY
 		@see INB_PLT_ERR_NO_MEM
 **************************************************************************************************
 */
int inb_pasps_update_ringer_setting(int conidx, enum inb_pasp_ringer_setting ringer_setting);

/**
***************************************************************************************************
 @brief  Add PASP client. It's the first function called

 @param[in] p_prf					Pointer to profile attributes, @see inb_pasp_prf_t

 @return	@see INB_ERR_NO_ERROR 
 		@see INB_PLT_ERR_NOT_READY 
 		@see INB_PLT_ERR_NO_MEM
 **************************************************************************************************
 */
int inb_paspc_add(inb_pasp_prf_t *p_prf);

/**
***************************************************************************************************
 @brief Enable PASP client.

 @param[in]   	conidx: 	connection index

 @note	It is called after connection or reconnection with a central device has been established 
 @return	@see INB_ERR_NO_ERROR
 		@see INB_PLT_ERR_NOT_READY
 		@see INB_PLT_ERR_NO_MEM
 **************************************************************************************************
 */
int inb_paspc_enable(int conidx);

/**
***************************************************************************************************
 @brief Get PASP server's Alert Status value.

 @param[in]   	conidx: 			connection index
 @param[in]	pAlertStatus:		butter to receive @see inb_pasp_alert_status

 @note	It is called after connection or reconnection with a central device has been established 
 @return	@see INB_ERR_NO_ERROR
 		@see INB_PLT_ERR_NOT_READY
 		@see INB_PLT_ERR_INVALID_PARAM
 		@see INB_PLT_ERR_NO_MEM
 **************************************************************************************************
 */
int inb_paspc_get_alert_status(int conidx, enum inb_pasp_alert_status *pAlertStatus);

/**
***************************************************************************************************
 @brief Get PASP server's Ringer Settting value.

 @param[in]   	conidx: 			connection index
 @param[in]	pRingerSetting:	butter to receive @see inb_pasp_ringer_setting

 @note	It is called after connection or reconnection with a central device has been established 
 @return	@see INB_ERR_NO_ERROR
 		@see INB_PLT_ERR_NOT_READY
 		@see INB_PLT_ERR_INVALID_PARAM
 		@see INB_PLT_ERR_NO_MEM
 **************************************************************************************************
 */
int inb_paspc_get_ringer_setting(int conidx, enum inb_pasp_ringer_setting *pRingerSetting);

/**
***************************************************************************************************
 @brief Get PASP server's Alert Status notification config, Started or Stopped.

 @param[in]   	conidx: 		connection index
 @param[in]	pCfg:		butter to receive @see inb_ntf_cfg

 @note	It is called after connection or reconnection with a central device has been established 
 @return	@see INB_ERR_NO_ERROR
 		@see INB_PLT_ERR_NOT_READY
 		@see INB_PLT_ERR_INVALID_PARAM
 		@see INB_PLT_ERR_NO_MEM
 **************************************************************************************************
 */
int inb_paspc_get_alert_status_ntf_cfg(int conidx, enum inb_ntf_cfg *pCfg);

/**
***************************************************************************************************
 @brief Set PASP server's Alert Status notification config, Start or Stop.

 @param[in]   	conidx: 	connection index
 @param[in]	cfg:		Start or Stop notification @see inb_ntf_cfg

 @note	It is called after connection or reconnection with a central device has been established 
 @return	@see INB_ERR_NO_ERROR
 		@see INB_PLT_ERR_NOT_READY
 		@see INB_PLT_ERR_NO_MEM
 **************************************************************************************************
 */
int inb_paspc_set_alert_status_ntf_cfg(int conidx, enum inb_ntf_cfg cfg);

/**
***************************************************************************************************
 @brief Get PASP server's Ringer Setting notification config, Started or Stopped.

 @param[in]   	conidx: 		connection index
 @param[in]	pCfg:		butter to receive @see inb_ntf_cfg

 @note	It is called after connection or reconnection with a central device has been established 
 @return	@see INB_ERR_NO_ERROR
 		@see INB_PLT_ERR_NOT_READY
 		@see INB_PLT_ERR_INVALID_PARAM
 		@see INB_PLT_ERR_NO_MEM
 **************************************************************************************************
 */
int inb_paspc_get_ringer_setting_ntf_cfg(int conidx, enum inb_ntf_cfg *pCfg);

/**
***************************************************************************************************
 @brief Set PASP server's Ringer Setting notification config, Start or Stop.

 @param[in]   	conidx: 	connection index
 @param[in]	cfg:		Start or Stop notification @see inb_ntf_cfg

 @note	It is called after connection or reconnection with a central device has been established 
 @return	@see INB_ERR_NO_ERROR
 		@see INB_PLT_ERR_NOT_READY
 		@see INB_PLT_ERR_NO_MEM
 **************************************************************************************************
 */
int inb_paspc_set_ringer_setting_ntf_cfg(int conidx, enum inb_ntf_cfg cfg);

/**
***************************************************************************************************
 @brief Set PASP server's Ringer Setting notification config, Start or Stop.

 @param[in]   	conidx: 	connection index
 @param[in]	ctrlCmd:	Ringer Control Point command @see inb_pasp_cmd

 @return	@see INB_ERR_NO_ERROR
 		@see INB_PLT_ERR_NOT_READY
 		@see INB_PLT_ERR_NO_MEM
 **************************************************************************************************
 */
int inb_paspc_ringer_control(int conidx, enum inb_pasp_cmd ctrlCmd);

#endif	/* INB_PRF_PASP_H */

