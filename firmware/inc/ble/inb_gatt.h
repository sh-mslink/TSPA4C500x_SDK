/**
 ****************************************************************************************
 *
 * @file inb_gatt.h
 *
 * @brief BLE GATT 
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef INB_GATT_H
#define INB_GATT_H

/**
 ****************************************************************************************
 * @defgroup INB_GATT BLE GATT  
 * @ingroup BLE
 * @brief  BLE GATT
 * @{
 ****************************************************************************************
 */

#include <stdint.h>
#include "inb_att.h"

/*
 * DEFINES
 ****************************************************************************************
 */

/*
 * Macros
 ****************************************************************************************
 */


/*
 * Enumerations
 ****************************************************************************************
 */

/// Service Discovery Attribute type
/*@TRACE*/
enum inb_gatt_sdp_att_type
{
    /// No Attribute Information
    INB_GATT_SDP_NONE,
    /// Included Service Information
    INB_GATT_SDP_INC_SVC,
    /// Characteristic Declaration
    INB_GATT_SDP_ATT_CHAR,
    /// Attribute Value
    INB_GATT_SDP_ATT_VAL,
    /// Attribute Descriptor
    INB_GATT_SDP_ATT_DESC,
};

/// Gatt SDP type
enum inb_gatt_sdp_type
{
	/// Search specific service
	GATT_SDP_DISC_SVC, 
	/// Search for all services
    GATT_SDP_DISC_SVC_ALL, 
	/// Cancel Service Discovery Procedure
    GATT_SDP_DISC_CANCEL 
};

/// Gatt discovery type
enum inb_gatt_disc_type
{
    /// Discover all services
    GATT_DISC_ALL_SVC,
    /// Discover services by UUID
    GATT_DISC_BY_UUID_SVC,
    /// Discover included services
    GATT_DISC_INCLUDED_SVC,
    /// Discover all characteristics
    GATT_DISC_ALL_CHAR,
    /// Discover characteristic by UUID
    GATT_DISC_BY_UUID_CHAR,
    /// Discover characteristic descriptor
    GATT_DISC_DESC_CHAR,
};

/// Gatt read type
enum inb_gatt_read_type
{
    /// Read attribute
    GATT_READ,
    /// Read long attribute
    GATT_READ_LONG,
    /// Read attribute by UUID
    GATT_READ_BY_UUID,
    /// Read multiple attribute
    GATT_READ_MULTIPLE,
};

/// Gatt write type
enum inb_gatt_write_type
{
   /// Write attribute
    GATT_WRITE,
    /// Write no response
    GATT_WRITE_NO_RESPONSE,
    /// Write signed
    GATT_WRITE_SIGNED,
    /// Execute write
    GATT_EXEC_WRITE,
};

/*
 * Structures
 ****************************************************************************************
 */

/// Service Discovery Procedure (SDP)
typedef struct 
{
    /// Search start handle
    uint16_t start_hdl;
    /// Search end handle
    uint16_t end_hdl;
    /// Service UUID Length
    uint8_t  uuid_len;
    /// Service UUID
    uint8_t  uuid[];
} inb_gatt_sdp_t;

/// Service Discovery Structure
typedef struct 
{
    /// start handle 
    uint16_t start_hdl;
    /// end handle range
    uint16_t end_hdl;
    /// UUID length
    uint8_t  uuid_len;
    /// UUID, LSB first, Only for UUID discovery
    uint8_t  uuid[];
} inb_gatt_disc_t;

/// Simple Read (GATT_READ or GATT_READ_LONG)
typedef struct 
{
    /// attribute handle
    uint16_t handle;
    /// start offset in data payload
    uint16_t offset;
    /// Length of data to read (0 = read all)
    uint16_t length;
} inb_gatt_read_simple_t;

/// Read by UUID: search UUID and read it's characteristic value (GATT_READ_BY_UUID)
/// Note: it doesn't perform an automatic read long.
typedef struct 
{
    /// Start handle
    uint16_t start_hdl;
    /// End handle
    uint16_t end_hdl;
    /// Size of UUID
    uint8_t uuid_len;
    /// UUID value
    uint8_t uuid[];
} inb_gatt_read_by_uuid_t;

/// Read Multiple short characteristic (GATT_READ_MULTIPLE)
typedef struct 
{
    /// attribute handle
    uint16_t handle;
    /// Known Handle length (shall be != 0)
    uint16_t len;
} inb_gatt_read_multiple_t;

/// request union according to read type
typedef union 
{
    /// Simple Read (GATT_READ or GATT_READ_LONG)
    inb_gatt_read_simple_t simple;
    /// Read by UUID (GATT_READ_BY_UUID)
    inb_gatt_read_by_uuid_t by_uuid;
    /// Read Multiple short characteristic (GATT_READ_MULTIPLE)
    inb_gatt_read_multiple_t multiple[1];
} inb_gatt_read_req_t;

/// Gatt read response
typedef struct
{
    /// Attribute handle
    uint16_t handle;
    /// Read offset
    uint16_t offset;
    /// Read length
    uint16_t length;
    /// Handle value
    uint8_t value[];
} inb_gatt_read_rsp_t;

/// Read command (Simple, Long, Multiple, or by UUID)
typedef struct 
{
    /// number of read (only used for multiple read)
    uint8_t nb;

    /// request union according to read type
    inb_gatt_read_req_t req;
} inb_gatt_read_t;

typedef struct 
{
    /// number of read (only used for multiple read)
    uint8_t nb;

    /// request union according to read type
    inb_gatt_read_rsp_t *pRsp;
} inb_gatt_read_value_t;

/// Write peer attribute value
typedef struct 
{
    /// Perform automatic execution
    /// (if false, an ATT Prepare Write will be used this shall be use for reliable write)
    bool auto_execute;
    /// Attribute handle
    uint16_t handle;
    /// Write offset
    uint16_t offset;
    /// Write length
    uint16_t length;
    /// Value to write
    uint8_t value[];
} inb_gatt_write_t;


/// Attribute Description
typedef struct 
{
    /// Attribute UUID (LSB First) 
    uint8_t uuid[INB_UUID_128_LEN];

     /// Attribute Permission, @see enum inb_att_perm_mask
    uint16_t perm;


    /// Maximum length of the attribute
    ///
    /// Note:
    /// For Included Services and Characteristic Declarations, this field contains targeted
    /// handle.
    ///
    /// For Characteristic Extended Properties, this field contains 2 byte value
    /// 
    /// Not used Client Characteristic Configuration and Server Characteristic Configuration,
    /// this field is not used.
    ///
    uint16_t max_len;

	/// Attribute extended permission, @see enum inb_att_value_perm_mask 
    uint16_t ext_perm;
} inb_gatt_att_desc_t;

/// Service description
typedef struct 
{
    /// Attribute Start Handle (0 = dynamically allocated)
    uint16_t start_hdl;

	/// Service permission, @see inb_svc_perm_mask
    uint8_t perm;

    /** Service  UUID */
    uint8_t uuid[INB_UUID_128_LEN];

    /// Number of attributes
    uint8_t nb_att;

     /// List of attribute description present in service.
    inb_gatt_att_desc_t atts[];

} inb_gatt_svc_desc_t;

/// attribute value
typedef struct 
{
	/// Handle of the attribute 
    uint16_t handle;	
	/// Attribute value length  
    uint16_t length;	
	/// Attribute value 
    uint8_t value[];	
} inb_att_val_t;

/// attribute permission
typedef struct 
{
	/// Handle of the attribute 
	uint16_t handle;		
	/// Attribute permission, @see enum att_perm_mask
	uint16_t perm;			
	/// Extended Attribute permission, @see att_value_perm_mask	
	uint16_t ext_perm;	
} inb_att_perm_t;


/*
 * Functions
 ****************************************************************************************
 */


int inb_gatt_exc_mtu(int conidx, uint16_t *p_mtu);
int inb_gatt_sdp(int conidx, int sdp_type, inb_gatt_sdp_t *p_sdp);
int inb_gatt_discovery(int conidx, int disc_type, inb_gatt_disc_t *p_disc);
int inb_gatt_read(int conidx, int read_type, inb_gatt_read_t *p_read, inb_gatt_read_value_t *p_readVal);
int inb_gatt_write(int conidx, int wrt_type, inb_gatt_write_t *p_write);
int inb_gatt_excute_write(int conidx, bool execute);
int inb_gatt_register_ind_ntf_event(int conidx, bool reg, uint32_t start_hdl, uint32_t end_hdl);
int inb_gatt_indication_cfm(int conidx, uint16_t handle);
int inb_gatt_send_ind(int conidx, uint32_t handle, uint32_t length, uint8_t *value);
int inb_gatt_send_ntf(int conidx, uint32_t handle, uint32_t length, uint8_t *value);
int inb_gatt_send_svc_changed(int conidx, uint32_t svc_shdl, uint32_t svc_ehdl);
int inb_gatt_add_svc(inb_gatt_svc_desc_t *p_svc, uint16_t *p_hdl);
int inb_gatt_get_svc_perm(uint16_t start_hdl, uint8_t *p_perm);
int inb_gatt_set_svc_perm(uint16_t start_hdl, uint8_t perm);
int inb_gatt_get_att_perm(uint16_t handle, inb_att_perm_t *p_perm);
int inb_gatt_set_att_perm(uint16_t handle, uint16_t perm, uint16_t ext_perm);
int inb_gatt_get_att_value(uint16_t handle, inb_att_val_t *p_att_val);
int inb_gatt_set_att_value(uint16_t handle, uint16_t length, uint8_t *value);
int inb_gatt_att_info_req_cfm(int conidx, uint16_t handle, uint16_t length, uint8_t status);
int inb_gatt_write_req_cfm(uint8_t conidx, uint16_t handle, uint8_t status);
int inb_gatt_read_req_cfm(uint8_t conidx, uint16_t handle, uint8_t status, uint16_t length, uint8_t *value);








/// @} INB_GATT

#endif	/* INB_GATT_H */

