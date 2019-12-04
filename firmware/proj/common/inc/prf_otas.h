/**
 ****************************************************************************************
 *
 * @file in_ota_svc.h
 *
 * @brief Over the Air Firmware update header file 
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef IN_OTA_SVC_H
#define IN_OTA_SVC_H
enum ota_svc{
    OTA_DECL_CHAR_VER = 0,
    OTA_CHAR_VAL_VER,
    OTA_DECL_CHAR_INFO,
    OTA_CHAR_VAL_INFO,
    OTA_DECL_CHAR_DATA,
    OTA_CHAR_VAL_DATA,
    OTA_CHAR_DESCR_DECL_DATA,
    OTA_DECL_CHAR_ERR,
    OTA_CHAR_VAL_ERR,
    OTA_CLIENT_CHAR_CFG_ERR,
};
enum ota_err {
    OTA_ERR_NO_ERR = 0,
    OTA_ERR_MSG,
    OTA_ERR_IMG_WRITE,
    OTA_ERR_INFO_WRITE,
};
/**
 ****************************************************************************************
 * @brief Define firmware update thru over the air Gatt service
 *
 * @return @see enum inb_error for the possible return code. 
 *
 ****************************************************************************************
 */
int in_ota_svc_add(void);

/**
 ****************************************************************************************
 * @brief This is to handle attribute read request indicator from the peer.  We only hadnle read firmware version.  
 *
 * @param[in] hdl					The attribute handle
 * @param[in] rd_data_len		Pointer to the read data length; Firmware version length
 * @param[in] rd_datan			Pointer to the pointer of read data array; Firmware version
 *
 * @return @see enum inb_error for the possible return code. 
 ****************************************************************************************
 */
int in_ota_svc_read_hdl(uint16_t hdl, uint16_t *rd_data_len, uint8_t **rd_data);

/**
 ****************************************************************************************
 * @brief This is to provide attribute length to stack 
 *
 * @param[in] hdl					The attribute handle
 * @param[in] length			Pointer to the length variable
 *
 * @return @see enum inb_error for the possible return code. 
 ****************************************************************************************
 */
int in_ota_svc_info_req_hdl(uint16_t hdl, uint16_t *length);

/**
 ****************************************************************************************
 * @brief This is to handle attribute write request from the peer.  We only hadnle write download information and
 *				data.  
 *
 * @param[in] ind					@see inb_evt_write_req_ind_t
 * @return @see enum inb_error for the possible return code. 
 ****************************************************************************************
 */
int in_ota_svc_write_hdl(inb_evt_write_req_ind_t *ind);

#endif
