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

#ifndef INB_PRF_ANP_H
#define INB_PRF_ANP_H

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

/// Alert Category ID Bit Mask 0 Masks
enum inb_anp_ntf_category_id_bits
{
	INB_ANP_SUPP_CAT_ID_SPL_ALERT_SUP 		= 0x01,
	INB_ANP_SUPP_CAT_ID_EMAIL_SUP 			= 0x02,
	INB_ANP_SUPP_CAT_ID_NEWS_SUP			= 0x04,
	INB_ANP_SUPP_CAT_ID_CALL_SUP			= 0x08,
	INB_ANP_SUPP_CAT_ID_MISSED_CALL_SUP	= 0x10,
	INB_ANP_SUPP_CAT_ID_SMS_MMS_SUP		= 0x20,
	INB_ANP_SUPP_CAT_ID_VOICE_MAIL_SUP		= 0x40,
	INB_ANP_SUPP_CAT_ID_SCHEDULE_SUP		= 0x80,
	INB_ANP_SUPP_CAT_ID_HIGH_PRTY_ALERT	= 0x0100,
	INB_ANP_SUPP_CAT_ID_INST_MSG			= 0x0200,
};
/*#define INB_ANP_SUPP_CAT_ID_SPL_ALERT_SUP            (0x01)
#define INB_ANP_SUPP_CAT_ID_EMAIL_SUP                (0x02)
#define INB_ANP_SUPP_CAT_ID_NEWS_SUP                 (0x04)
#define INB_ANP_SUPP_CAT_ID_CALL_SUP                 (0x08)
#define INB_ANP_SUPP_CAT_ID_MISSED_CALL_SUP          (0x10)
#define INB_ANP_SUPP_CAT_ID_SMS_MMS_SUP              (0x20)
#define INB_ANP_SUPP_CAT_ID_VOICE_MAIL_SUP           (0x40)
#define INB_ANP_SUPP_CAT_ID_SCHEDULE_SUP             (0x80)
/// Alert Category ID Bit Mask 1 Masks
#define INB_ANP_SUPP_CAT_ID_HIGH_PRTY_ALERT          (0x0100)
#define INB_ANP_SUPP_CAT_ID_INST_MSG                 (0x0200)
*/
/// New Alert Characteristic Value - Text String Information Max Length
#define INB_ANS_NEW_ALERT_STRING_INFO_MAX_LEN   (18)

/// Category ID Field Keys
/*enum inb_anp_category_id
{
	/// Simple Alert
	INB_CAT_ID_SPL_ALERT                    = 0,
	/// Email
	INB_CAT_ID_EMAIL,
	/// News Feed
	INB_CAT_ID_NEWS,
	/// Incoming Call
	INB_CAT_ID_CALL,
	/// Missed Call
	INB_CAT_ID_MISSED_CALL,
	/// SMS/MMS
	INB_CAT_ID_SMS_MMS,
	/// Voice Mail
	INB_CAT_ID_VOICE_MAIL,
	/// Schedule
	INB_CAT_ID_SCHEDULE,
	/// High Priority Alert
	INB_CAT_ID_HIGH_PRTY_ALERT,
	/// Instant Message
	INB_CAT_ID_INST_MSG,

	INB_CAT_ID_NB,

	/// All supported category
	INB_CAT_ID_ALL_SUPPORTED_CAT            = 255,
};*/

/// Command ID Field Keys
/*enum inb_anp_ctnl_pt_cmd_id
{
    /// Enable New Incoming Alert Notification
    INB_CMD_ID_EN_NEW_IN_ALERT_NTF          = 0,
    /// Enable Unread Category Status Notification
    INB_CMD_ID_EN_UNREAD_CAT_STATUS_NTF,
    /// Disable New Incoming Alert Notification
    INB_CMD_ID_DIS_NEW_IN_ALERT_NTF,
    /// Disable Unread Category Status Notification
    INB_CMD_ID_DIS_UNREAD_CAT_STATUS_NTF,
    /// Notify New Incoming Alert immediately
    INB_CMD_ID_NTF_NEW_IN_ALERT_IMM,
    /// Notify Unread Category Status immediately
    INB_CMD_ID_NTF_UNREAD_CAT_STATUS_IMM,

    INB_CMD_ID_NB,
};*/

/*typedef struct 
{
    /// service info,
    inb_svc_t svc;

    /// Characteristic Info:
    inb_char_inf_t chars[5];

    /// Descriptor handles:
    inb_char_desc_inf_t descs[2];
} inb_anpc_service_info_t;*/

/// Alert codes
enum inb_anp_alert_type
{
    /// New Alert
    INB_ANP_NEW_ALERT      = 0,
    INB_ANP_UNREAD_ALERT,
};

/// Parameters of the @ref ANPS_ENABLE_REQ message
typedef struct 
{
	//Supported New Alert Category Characteristic value. refer to 
	//"RW BLE Alert Notification Profile Interface Specification"
	//Category ID Field Keys @ref in anp_common.h 
	uint16_t supp_new_alert_cat;
	//Supported Unread Alert Category Characteristic value
	uint16_t supp_unread_alert_cat;
} inb_anps_cfg_t;

typedef struct
{
	uint16_t new_alert_ntf_cfg;
	uint16_t unread_alert_status_ntf_cfg;
} inb_anp_ntf_cfg_t;

/*typedef struct 
{
	inb_anp_ntf_cfg_t enable;
	inb_anpc_service_info_t ans_svc;
} inb_anpc_cfg_t;*/

typedef struct
{
	/// Connection index
	uint8_t conidx;

	//refer to "anp_alert_codes" in anp_common.h
	uint8_t alert_type;
	
	uint16_t supp_alert_cat;
} inb_evt_supp_alert_cat_t;

typedef struct 
{
	/// Connection index
	uint8_t conidx;

	/// Information String Length
	uint8_t info_str_len;

	/// Category ID
	enum inb_anp_ntf_category_id_bits cat_id;
	
	/// Number of alerts
	uint8_t nb_new_alert;
	/// Text String Information
	uint8_t str_info[18];
} inb_evt_new_alert_t;

typedef struct 
{
	/// Connection index
	uint8_t conidx;

	/// Category ID
	uint8_t cat_id;
	/// Number of alert
	uint8_t nb_unread_alert;
} inb_evt_unread_alert_t;

/// Events defines for ANP Services
enum inb_anp_evt 
{
	INB_EVT_ANPC_NEW_ALERT = INB_ANP_EVT_CODE +1,

	INB_EVT_ANPC_UNREAD_ALERT,

	//Informed that Control Point has been written by peer device
	INB_EVT_ANPS_NTF_IMMEDIATE_REQ_IND,

	//Informed that value of one of the two Client Characteristic Configuration Descriptors has been
	//written by the peer device
	INB_EVT_ANPS_NTF_STATUS_UPDATE_IND,

	INB_EVT_ANPS_NTF_CAT_STATUS_UPDATE_IND,
};

typedef struct
{
	/// Connection index
	uint8_t conidx;

	//refer to `anp_alert_codes`
	uint8_t alert_type;
	
	//refer to `Alert Category ID Bit Mask 0 Masks`
	uint16_t cat_id;
} inb_evt_anps_ntf_immediate_req_ind_t;

typedef struct
{
	// Connection index
	uint8_t conidx;
	
	enum inb_anp_alert_type alert_type;
	enum inb_ntf_cfg ntf_status;
} inb_evt_anps_ntf_status_update_ind_t;

typedef struct
{
	// Connection index
	uint8_t conidx;
	
	enum inb_anp_alert_type alert_type;
	enum inb_ntf_cfg ntf_status;
	enum inb_anp_ntf_category_id_bits cat_id;
} inb_evt_anps_ntf_cat_status_update_ind_t;

typedef struct
{
	/// Information String Length
	uint8_t info_str_len;

	/// Category ID: refer to `enum inb_anp_category_id`
	uint8_t cat_id;
	
	/// Number of alerts
	uint8_t nb_new_alert;
	/// Text String Information
	uint8_t str_info[INB_ANS_NEW_ALERT_STRING_INFO_MAX_LEN];
} inb_anp_new_alert_value;

typedef struct
{
	/// Category ID: refer to `enum inb_anp_category_id`
	uint8_t cat_id;
	/// Number of alert
	uint8_t nb_unread_alert;
} inb_anp_unread_alert_status;

typedef union
{
	/// New Alert
	inb_anp_new_alert_value new_alert;
	/// Unread Alert Status
	inb_anp_unread_alert_status unread_alert_status;
} inb_anp_notify_alert_value;

/*
 * APIs
 ****************************************************************************************
 */
//int inb_anpc_add(inb_add_prf_t *p_prf);



	

/// @} INB_PRF_BAS

#endif	/* INB_PRF_BAS_H */

