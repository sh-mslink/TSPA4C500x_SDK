/**
 ****************************************************************************************
 *
 * @file inb_prf_bas.h
 *
 * @brief BLE Battery Service
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef INB_PRF_BAS_H
#define INB_PRF_BAS_H

/**
 ****************************************************************************************
 * @defgroup INB_PRF_BAS BLE Battery Service  
 * @ingroup BLE_PRF
 * @brief  BLE Battery Service
 * @{
 ****************************************************************************************
 */

#include <stdint.h>
#include ".\ble\inb_prf.h"

#define INB_BASS_INSTANCES_MAX         (2)

/*
 * Enumerations
 ****************************************************************************************
 */

/// Events defines for Battery Services
enum inb_bas_evt 
{
	BASC_EVT_CODE = BAS_EVT_CODE +1,

    /// Indicate that the Battery Level value has been received, @see inb_evt_basc_batt_level_ind_t
	BASC_EVT_BATT_LEVEL_IND,

	BASS_EVT_CODE = BAS_EVT_CODE + 0x10,

    /// Inform that Battery Level Notification Configuration has been changed - use to update bond data, @see inb_evt_bass_level_ntf_cfg_ind_t
	BASS_EVT_BATT_LEVEL_NTF_CFG_IND,
};

/// Peer battery info that can be read
enum inb_basc_info
{
    /// Battery Level value
    INB_BASC_BATT_LVL_VAL,
    /// Battery Level Client Characteristic Configuration
    INB_BASC_NTF_CFG,
    /// Battery Level Characteristic Presentation Format
    INB_BASC_BATT_LVL_PRES_FORMAT,

    INB_BASC_INFO_MAX,
};

/// Features Flag Masks
enum inb_bass_features
{
    /// Battery Level Characteristic doesn't support notifications
    INB_BAS_BATT_LVL_NTF_NOT_SUP,
    /// Battery Level Characteristic support notifications
    INB_BAS_BATT_LVL_NTF_SUP,
};

/// Battery Service Characteristics
enum inb_bass_char_type
{
    /// Battery Level
    INB_BAS_CHAR_BATT_LEVEL,

    INB_BAS_CHAR_MAX,
};

/// Battery Service Descriptors
enum inb_bass_desc_type
{
    /// Battery Level Characteristic Presentation Format
    INB_BAS_DESC_BATT_LEVEL_PRES_FORMAT,
    /// Battery Level Client Characteristic Configuration
    INB_BAS_DESC_BATT_LEVEL_CFG,

    INB_BAS_DESC_MAX,
};

/*
 * Structures
 ****************************************************************************************
 */

typedef struct 
{
	/// Connection index
	uint8_t conidx;
    ///Battery Level
    uint8_t batt_level;
    ///Battery Service Instance - From 0 to BASC_NB_BAS_INSTANCES_MAX-1
    uint8_t bas_nb;
} inb_evt_basc_batt_level_ind_t;

typedef struct 
{
	/// Connection index
	uint8_t conidx;
    ///Notification Configuration
	uint8_t  ntf_cfg;
} inb_evt_bass_level_ntf_cfg_ind_t;

typedef struct 
{
    /// service info,
    inb_svc_t svc;

    /// Characteristic Info:
    /// - Battery Level
    inb_char_inf_t chars[INB_BAS_CHAR_MAX];

    /// Descriptor handles:
    /// - Battery Level Client Characteristic Configuration
    /// - Battery Level Characteristic Presentation Format
    inb_char_desc_inf_t descs[INB_BAS_DESC_MAX];
} inb_basc_content_t;

///Parameters of the @ref  BASC_READ_INFO_RSP message
typedef struct 
{
    ///Characteristic info @see enum basc_info
    uint8_t info;
    ///Battery Service Instance - From 0 to BASC_NB_BAS_INSTANCES_MAX-1
    uint8_t bas_nb;

    /// Information data
    union 
    {
        /// Battery Level - if info = BASC_BATT_LVL_VAL
        uint8_t batt_level;
        ///Notification Configuration Value - if info = BASC_NTF_CFG
        uint16_t ntf_cfg;
        ///Characteristic Presentation Format - if info = BASC_BATT_LVL_PRES_FORMAT
        inb_char_pres_fmt_t char_pres_format;
    } data;
} inb_basc_read_info_rsp_t;

/// Parameters for the database creation
typedef struct 
{
	///If the service is multi-instance
	bool multi_instance;

	/*The following params are for ANPS only*/
	
	///If let the service check whether encryption key size is 16bytes (more security).
	bool check_enc_key_size;

	/// Security Level, @see enum inb_att_svc_perm_mask
	enum inb_att_perm sec_lvl;

	/// Number of BAS to add
	uint8_t bas_nb;
	/// Features of each BAS instance, @see enum inb_bass_features
	uint8_t features[INB_BASS_INSTANCES_MAX];
	/// Battery Level Characteristic Presentation Format - Should not change during connection
	inb_char_pres_fmt_t batt_level_pres_format[INB_BASS_INSTANCES_MAX];
} inb_bas_prf_t;

/// Parameters of the @ref BASS_ENABLE_REQ message
typedef struct 
{
    /// Client Notification Configuration, @see enum inb_cli_conf
    uint8_t  ntf_cfg;
    /// Old Battery Level used to decide if notification should be triggered
    uint8_t  old_batt_lvl[INB_BASS_INSTANCES_MAX];
} inb_bass_enable_req_t;

/*
 * APIs
 ****************************************************************************************
 */


/**
 ****************************************************************************************
 * @brief Add Battery Client Service 
 *	
 * @note Add it after device configuration, but before any activity starts
 *
 *
 * @param[in] p_prf					Pointer to profile attributes, @see  inb_bas_prf_t
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_basc_add(inb_bas_prf_t *p_prf);

/**
 ****************************************************************************************
 * @brief Enable BAS client service 
 *	
 * @note First function to call after connection 
 *
 * @param[in] conidx				Connection index
 * @param[in] con_type			Connnetion type, @see enum inb_con_type
 * @param[in] bas_nb				Number of instances
 * @param[in,out] content		Contents of service
 *													- Discover connection type: Stack will fill it
 *													- Normal connection type: Application needs to fill it. 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_basc_enable(int conidx, int con_type, uint8_t bas_nb, inb_basc_content_t content[]);

/**
 ****************************************************************************************
 * @brief Read peer info 
 *	
 *
 * @param[in] conidx				Connection index
 * @param[in] bas_nb				Instance index  
 * @param[in] basc_info			Information to read, @see enum inb_basc_info
 * @param[out] p_rsp				Response from the peer
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_basc_read_info_req(int conidx, int bas_nb, int basc_info, inb_basc_read_info_rsp_t *rsp);

/**
 ****************************************************************************************
 * @brief Configure notification 
 *	
 *
 * @param[in] conidx				Connection index
 * @param[in] bas_nb				Instance index  
 * @param[in] ntf_cfg				notification config
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_basc_ntf_req(uint8_t conidx, uint8_t bas_nb, uint16_t ntf_cfg);

/**
 ****************************************************************************************
 * @brief Add Battery Server Service 
 *	
 * @note Add it after device configuration, but before any activity starts
 *
 *
 * @param[in] p_prf					Pointer to profile attributes, @see inb_bas_prf_t
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_bass_add(inb_bas_prf_t *p_prf);

/**
 ****************************************************************************************
 * @brief Enable BAS server service 
 *	
 * @note First function to call after connection 
 *
 * @param[in] conidx				Connection index
 * @param[in] p_req					Pointer to the request structure
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_bass_enable(int conidx, inb_bass_enable_req_t *p_req);

/**
 ****************************************************************************************
 * @brief Update battery level request 
 *	
 *
 * @param[in] conidx				Connection index
 * @param[in[ instance			Instance index	
 * @param[in] batt_lvl				Battery level
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_bass_batt_level_upd_req(int conidx, uint8_t instance, uint8_t batt_lvl);
	

/// @} INB_PRF_BAS

#endif	/* INB_PRF_BAS_H */

