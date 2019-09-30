/**
 ****************************************************************************************
 *
 * @file inb_prf_dis.h
 *
 * @brief BLE Device Information Service
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef INB_PRF_DIS_H
#define INB_PRF_DIS_H

/**
 ****************************************************************************************
 * @defgroup INB_PRF_DIS BLE device information service  
 * @ingroup INB_PRF
 * @brief  BLE DIS service
 * @{
 ****************************************************************************************
 */

/*
 * Defines
 ****************************************************************************************
 */

/*
 * Enumerations
 ****************************************************************************************
 */

/*
 * Events
 ****************************************************************************************
 */
enum inb_dis_evt {
    /// Peer device request to get profile attribute value, @see evt_value_req_ind_t
	DISS_EVT_VALUE_REQ_IND = 	DIS_EVT_CODE +1,
};

///DIS char code
enum inb_dis_char
{
    /// Manufacturer Name
    INB_DIS_MANUFACTURER_NAME_CHAR,
    /// Model Number
    INB_DIS_MODEL_NB_STR_CHAR,
    /// Serial Number
    INB_DIS_SERIAL_NB_STR_CHAR,
    /// HW Revision Number
    INB_DIS_HARD_REV_STR_CHAR,
    /// FW Revision Number
    INB_DIS_FIRM_REV_STR_CHAR,
    /// SW Revision Number
    INB_DIS_SW_REV_STR_CHAR,
    /// System Identifier Name
    INB_DIS_SYSTEM_ID_CHAR,
    /// IEEE Certificate
    INB_DIS_IEEE_CHAR,
    /// Plug and Play Identifier
    INB_DIS_PNP_ID_CHAR,

    INB_DISC_CHAR_MAX,
};

///Database Configuration Flags
enum inb_diss_features
{
    ///Indicate if Manufacturer Name String Char. is supported
    INB_DISS_MANUFACTURER_NAME_CHAR_SUP       = 0x0001,
    ///Indicate if Model Number String Char. is supported
    INB_DISS_MODEL_NB_STR_CHAR_SUP            = 0x0002,
    ///Indicate if Serial Number String Char. is supported
    INB_DISS_SERIAL_NB_STR_CHAR_SUP           = 0x0004,
    ///Indicate if Hardware Revision String Char. supports indications
    INB_DISS_HARD_REV_STR_CHAR_SUP            = 0x0008,
    ///Indicate if Firmware Revision String Char. is writable
    INB_DISS_FIRM_REV_STR_CHAR_SUP            = 0x0010,
    ///Indicate if Software Revision String Char. is writable
	INB_DISS_SW_REV_STR_CHAR_SUP              = 0x0020,
    ///Indicate if System ID Char. is writable
    INB_DISS_SYSTEM_ID_CHAR_SUP               = 0x0040,
    ///Indicate if IEEE Char. is writable
    INB_DISS_IEEE_CHAR_SUP                    = 0x0080,
    ///Indicate if PnP ID Char. is writable
    INB_DISS_PNP_ID_CHAR_SUP                  = 0x0100,

    ///All features are supported
    INB_DISS_ALL_FEAT_SUP                     = 0x01FF,
};

/*
 * Structures
 ****************************************************************************************
 */
typedef struct 
{
	/// Connection index
	uint8_t conidx;
	
    /// Requested value
    uint8_t value;
} evt_value_req_ind_t;

typedef struct 
{
    /// service info
    inb_svc_t svc;
    /// Characteristic info:
    inb_char_inf_t chars[INB_DISC_CHAR_MAX];
} inb_disc_content_t;

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
	
	/// Database configuration @see enum inb_diss_features
	uint16_t features;
} inb_dis_prf_t;

typedef struct 
{
    /// Value to Set
    uint8_t value;
    /// Value length
    uint8_t length;
    /// Value data
    uint8_t data[];
} inb_diss_set_value_req_t;

/// Peer device  value of requested attribute
typedef struct 
{
    /// Requested value
    uint8_t value;
    /// Value length
    uint8_t length;
    /// Value data
    uint8_t data[];
} inb_diss_value_cfm_t;

/*
 * APIs
 ****************************************************************************************
 */

/*
 * DIS Client Functions
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Add DIS client service 
 *	
 * @note Add it after device configuration, but before any activity starts
 *
 *
 * @param[in] p_prf					Pointer to profile attributes @see inb_dis_prf_t
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_disc_add(inb_dis_prf_t *p_prf);

/**
 ****************************************************************************************
 * @brief Enable DIS client servie 
 *	
 * @note First function to call after connection 
 *
 * @param[in] conidx				Connection index
 * @param[in] con_type			Connnetion type, @see enum inb_con_type
 * @param[in,out] p_dis			Contents of service
 *													- Discover connection type: Stack will fill it
 *													- Normal connection type: Application needs to fill it. 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_disc_enable(int conidx, int con_type, inb_disc_content_t *p_dis);

/**
 ****************************************************************************************
 * @brief Enable DIS client servie 
 *	
 * @note First function to call after connection 
 *
 * @param[in] conidx				Connection index
 * @param[in] char_code			Characteristic value code, @see enum inb_disc_char 
 * @param[out] p_att				Return information			
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_disc_read_char(int conidx, int char_code, inb_att_info_t *p_att)	;

/*
 * DIS Server Functions
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Add DIS server service 
 *	
 * @note Add it after device configuration, but before any activity starts
 *
 *
 * @param[in] p_prf					Pointer to profile attributes, @see inb_dis_prf_t
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_diss_add(inb_dis_prf_t *p_prf);

/**
 ****************************************************************************************
 * @brief Set the value of an attribute - Request 
 *	
 *
 * @param[in] conidx				Connection index
 * @param[in] p_req					Pointer to Connnetion type, @see enum inb_con_type
 * @param[in] p_reqs				Pointer to the request
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_diss_set_value_req(int conidx, inb_diss_set_value_req_t *p_req);

/**
 ****************************************************************************************
 * @brief Peer device  value of requested attribute confirmed 
 *	
 *
 * @param[in] conidx				Connection index
 * @param[in] p_cfm					Pointer to confirmed value
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_diss_set_value_cfm(int conidx, inb_diss_value_cfm_t *p_cfm);	


/// @} INB_PRF_DIS

#endif	/* INB_PRF_DIS_H */

