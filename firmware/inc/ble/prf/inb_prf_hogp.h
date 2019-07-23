/**
 ****************************************************************************************
 *
 * @file inb_prf_hogp.h
 *
 * @brief BLE HID over GATT Profiles 
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef IN_BLE_PRF_HOGP_H
#define IN_BLE_PRF_HOGP_H

/**
 ****************************************************************************************
 * @defgroup INB_PRF_HOG BLE HOG Profile  
 * @ingroup INB_PRF
 * @brief  BLE HOG Profile
 * @{
 ****************************************************************************************
 */

/*
 * Defines
 ****************************************************************************************
 */

/// Maximal number of hids instances that can be handled
#define INB_HOGPRH_NB_HIDS_INST_MAX              (2)
/// Maximal number of Report Char. that can be added in the DB for one HIDS - Up to 11
#define INB_HOGPRH_NB_REPORT_INST_MAX            (5)
/// Maximal length of Report Map Char. Value
#define INB_HOGPRH_REPORT_MAP_MAX_LEN            (512)

/// HOGP Devicet role
/// Maximal number of HIDS that can be added in the DB
#define INB_HOGPD_NB_HIDS_INST_MAX              (2)
/// Maximal number of Report Char. that can be added in the DB for one HIDS - Up to 11
#define INB_HOGPD_NB_REPORT_INST_MAX            (5)

/*
 * Enumerations
 ****************************************************************************************
 */

/*
 * Events
 ****************************************************************************************
 */

enum inb_hog_evt_code {
	HOGPBH_EVT_CODE = HOGP_EVT_CODE +1,

    /// Boot Report value (after Read Request or Notification), @see inb_evt_hogpbh_boot_report_ind_t
	HOGPBH_EVT_BOOT_REPORT_IND,

	HOGPRH_EVT_CODE = (HOGP_EVT_CODE + 0x10),

    /// Report value (after Notification), @see inb_evt_hogprh_report_ind_t
	HOGPRH_EVT_REPORT_IND,

	HOGPD_EVT_CODE = (HOGP_EVT_CODE + 0x20),

    /// Request from peer device to Read or update a report value, @see inb_evt_hogpd_report_req_ind_t
	HOGPD_EVT_REPORT_REQ_IND,
    /// Inform Device that Protocol Mode Characteristic Value has been written on Device, @see inb_evt_hogpd_proto_mode_req_ind_t
	HOGPD_EVT_PROTO_MODE_UPD_IND,
    /// Inform Device that a Client Characteristic Configuration has been modified, @see inb_evt_hogpd_ntf_cfg_ind_t
	HOGPD_EVT_NTF_CFG_IND,
    /// Inform that HID Control Point Characteristic Value has been written on Device, @see inb_evt_hogpd_ctnl_pt_ind_t
	HOGPD_EVT_CNTL_PT_IND,
};

/*
 * HOGP Common
 ****************************************************************************************
 */

/// HID Information bit values
enum inb_hogp_info_bit
{
    /// Device capable of providing wake-up signal to a HID host
    INB_HIDS_REMOTE_WAKE_CAPABLE           = 0x01,
    /// Normally connectable support bit
    INB_HIDS_NORM_CONNECTABLE              = 0x02,
};

/// HID Control Point Characteristic value keys
enum inb_hogp_ctnl_pt
{
    /// Suspend
    INB_HOGP_CTNL_PT_SUSPEND            = 0x00,
    /// Exit suspend
    INB_HOGP_CTNL_PT_EXIT_SUSPEND,
};

/// Protocol Mode Char. value Keys
enum inb_hogp_boot_prot_mode
{
    /// Boot Protocol Mode
    INB_HOGP_BOOT_PROTOCOL_MODE         = 0x00,
    /// Report Protocol Mode
    INB_HOGP_REPORT_PROTOCOL_MODE,
};

/*
 * HOG Boot Host profile
 ****************************************************************************************
 */

/// HOGP Boot Host Characteristics
enum inb_hogpbh_chars
{
    /// Protocol Mode
    INB_HOGPBH_CHAR_PROTO_MODE,
    /// Boot Keyboard Input Report
    INB_HOGPBH_CHAR_BOOT_KB_IN_REPORT,
    /// Boot Keyboard Output Report
    INB_HOGPBH_CHAR_BOOT_KB_OUT_REPORT,
    /// Boot Mouse Input Report
    INB_HOGPBH_CHAR_BOOT_MOUSE_IN_REPORT,

    INB_HOGPBH_CHAR_MAX,
};

/// HOGP Boot Host Characteristic descriptors
enum inb_hogpbh_descs
{
    /// Boot Keyboard Input Report Client Config
    INB_HOGPBH_DESC_BOOT_KB_IN_REPORT_CFG,
    /// Boot Mouse Input Report Client Config
    INB_HOGPBH_DESC_BOOT_MOUSE_IN_REPORT_CFG,

    INB_HOGPBH_DESC_MAX,
};

/// HOGP Boot Host Peer HID service info that can be read/write
enum inb_hogpbh_info
{
    /// Protocol Mode
    INB_HOGPBH_PROTO_MODE,
    /// Boot Keyboard Input Report
    INB_HOGPBH_BOOT_KB_IN_REPORT,
    /// Boot Keyboard Output Report
    INB_HOGPBH_BOOT_KB_OUT_REPORT,
    /// Boot Mouse Input Report
    INB_HOGPBH_BOOT_MOUSE_IN_REPORT,

    /// Boot Keyboard Input Report Client Config
    INB_HOGPBH_BOOT_KB_IN_NTF_CFG,
    /// Boot Mouse Input Report Client Config
    INB_HOGPBH_BOOT_MOUSE_IN_NTF_CFG,

    INB_HOGPBH_INFO_MAX,
};

/*
 * HOG Device profile
 ****************************************************************************************
 */

enum inb_hogpd_cfg
{
    /// Keyboard Device
    INB_HOGPD_CFG_KEYBOARD      = 0x01,
    /// Mouse Device
    INB_HOGPD_CFG_MOUSE         = 0x02,
    /// Protocol Mode present
    INB_HOGPD_CFG_PROTO_MODE    = 0x04,
    /// Extended Reference Present
    INB_HOGPD_CFG_MAP_EXT_REF   = 0x08,
    /// Boot Keyboard Report write capability
    INB_HOGPD_CFG_BOOT_KB_WR    = 0x10,
    /// Boot Mouse Report write capability
    INB_HOGPD_CFG_BOOT_MOUSE_WR = 0x20,

    /// Valid Feature mask
    INB_HOGPD_CFG_MASK          = 0x3F,

    /// Report Notification Enabled (to be shift for each report index)
    INB_HOGPD_CFG_REPORT_NTF_EN = 0x40,
};

/// Report Char. Configuration Flag Values
enum inb_hogpd_report_cfg
{
    /// Input Report
    INB_HOGPD_CFG_REPORT_IN     = 0x01,
    /// Output Report
    INB_HOGPD_CFG_REPORT_OUT    = 0x02,
    //HOGPD_CFG_REPORT_FEAT can be used as a mask to check Report type
    /// Feature Report
    INB_HOGPD_CFG_REPORT_FEAT   = 0x03,
    /// Input report with Write capabilities
    INB_HOGPD_CFG_REPORT_WR     = 0x10,
};

/// Type of reports
enum inb_hogpd_report_type
{
    /// The Report characteristic is used to exchange data between a HID Device and a HID Host.
    INB_HOGPD_REPORT,
    /// The Report Map characteristic
    INB_HOGPD_REPORT_MAP,
    /// Boot Keyboard Input Report
    INB_HOGPD_BOOT_KEYBOARD_INPUT_REPORT,
    /// Boot Keyboard Output Report
    INB_HOGPD_BOOT_KEYBOARD_OUTPUT_REPORT,
    /// Boot Mouse Input Report
    INB_HOGPD_BOOT_MOUSE_INPUT_REPORT,
};

/// type of operation requested by peer device
enum inb_hogpd_op
{
    /// No operation
    INB_HOGPD_OP_NO,
    /// Read report value
    INB_HOGPD_OP_REPORT_READ,
    /// Modify/Set report value
    INB_HOGPD_OP_REPORT_WRITE,
    /// Modify Protocol mode
    INB_HOGPD_OP_PROT_UPDATE,
};

/*
 * HOG Report host profile
 ****************************************************************************************
 */


/// HOG profile report host Characteristics
enum inb_hogprh_chars
{
    /// Report Map
    INB_HOGPRH_CHAR_REPORT_MAP,
    /// HID Information
    INB_HOGPRH_CHAR_HID_INFO,
    /// HID Control Point
    INB_HOGPRH_CHAR_HID_CTNL_PT,
    /// Protocol Mode
    INB_HOGPRH_CHAR_PROTOCOL_MODE,
    /// Report
    INB_HOGPRH_CHAR_REPORT,

    INB_HOGPRH_CHAR_MAX = INB_HOGPRH_CHAR_REPORT + INB_HOGPRH_NB_REPORT_INST_MAX,
};

/// Characteristic descriptors
enum inb_hogprh_descs
{
    /// Report Map Char. External Report Reference Descriptor
    INB_HOGPRH_DESC_REPORT_MAP_EXT_REP_REF,
    /// Report Char. Report Reference
    INB_HOGPRH_DESC_REPORT_REF,
    /// Report Client Config
    INB_HOGPRH_DESC_REPORT_CFG = INB_HOGPRH_DESC_REPORT_REF + INB_HOGPRH_NB_REPORT_INST_MAX,

    INB_HOGPRH_DESC_MAX = INB_HOGPRH_DESC_REPORT_CFG + INB_HOGPRH_NB_REPORT_INST_MAX,
};

/// Peer HID service info that can be read/write
enum inb_hogprh_info
{
    /// Protocol Mode
    INB_HOGPRH_PROTO_MODE,
    /// Report Map
    INB_HOGPRH_REPORT_MAP,
    /// Report Map Char. External Report Reference Descriptor
    INB_HOGPRH_REPORT_MAP_EXT_REP_REF,

    /// HID Information
    INB_HOGPRH_HID_INFO,
    /// HID Control Point
    INB_HOGPRH_HID_CTNL_PT,
    /// Report
    INB_HOGPRH_REPORT,
    /// Report Char. Report Reference
    INB_HOGPRH_REPORT_REF,
    /// Report Notification config
    INB_HOGPRH_REPORT_NTF_CFG,

    INB_HOGPRH_INFO_MAX,
};

/*
 * Structures
 ****************************************************************************************
 */

/*
 * HOG Boot Host profile
 ****************************************************************************************
 */

/// HOGP Boot Host HID boot report info
typedef struct 
{
    /// Report Length
    uint8_t length;
    /// Boot Report value
    uint8_t value[];
} inb_hogpbh_boot_report_t;

typedef union 
{
    /// Protocol Mode
    ///  - info = HOG_PBH_PROTO_MODE
    uint8_t proto_mode;
    ///Notification Configuration Value
    ///  - info = HOG_PBH_BOOT_KB_IN_NTF_CFG
    ///  - info = HOG_PBH_BOOT_MOUSE_IN_NTF_CFG
    uint16_t ntf_cfg;

    /// Boot report information
    ///  - info = HOG_PBH_BOOT_KB_IN_REPORT
    ///  - info = HOG_PBH_BOOT_KB_OUT_REPORT
    ///  - info = HOG_PBH_BOOT_MOUSE_IN_REPORT
    inb_hogpbh_boot_report_t report;
} inb_hogpbh_data_t;

typedef struct 
{
    ///Characteristic info @see enum hog_pbh_info
    uint8_t info;
    /// HID Service Instance - From 0 to HOG_PBH_NB_HIDS_INST_MAX-1
    uint8_t hid_idx;
    /// Information data
    inb_hogpbh_data_t data;
} inb_hogpbh_read_info_rsp_t;

typedef struct
{
	inb_svc_t svc;
	inb_char_inf_t chars[INB_HOGPBH_CHAR_MAX];
	inb_char_desc_inf_t descs[INB_HOGPBH_DESC_MAX];

} inb_hogpbh_content_t;

typedef struct 
{
	/// Connection index
	uint8_t conidx;	
    ///Characteristic info @see enum hog_pbh_info
    uint8_t info;
    /// HIDS Instance
    uint8_t hid_idx;
    /// Report data
    inb_hogpbh_boot_report_t report;
} inb_evt_hogpbh_boot_report_ind_t;

/*
 * HOG Device profile
 ****************************************************************************************
 */

/// HID Information structure
typedef struct 
{
    /// bcdHID
    uint16_t bcdHID;
    /// bCountryCode
    uint8_t  bCountryCode;
    /// Flags, @see enum inb_hogp_info_bit
    uint8_t  flags;
} inb_hogpd_info_t;

/// External Report Reference
typedef struct 
{
    /// External Report Reference - Included Service
    uint16_t inc_svc_hdl;
    /// External Report Reference - Characteristic UUID
    uint16_t rep_ref_uuid;
} inb_hogpd_ext_ref_t;

/// Database Creation Service Instance Configuration structure
typedef struct 
{
    /// Service Features (@see enum inb_hogpd_cfg)
    uint8_t svc_features;
    /// Number of Report Char. instances to add in the database
    uint8_t report_nb;
    /// Report Char. Configuration (@see enum inb_hogpd_report_cfg)
    uint8_t report_char_cfg[INB_HOGPD_NB_REPORT_INST_MAX];
    /// Report id number
    uint8_t report_id[INB_HOGPD_NB_REPORT_INST_MAX];
    /// HID Information Char. Values
    inb_hogpd_info_t hid_info;
    /// External Report Reference
    inb_hogpd_ext_ref_t ext_ref;
} inb_hogpd_cfg_t;

typedef struct 
{
	/// Security Level, @see enum inb_att_svc_perm_mask
    uint8_t  sec_lvl;
    /// Service start handle
    /// 0: dynamically allocated in Attribute database
    uint16_t start_hdl;
    /// Number of HIDS to add
    uint8_t hids_nb;
    /// Initial configuration for each HIDS instance
    inb_hogpd_cfg_t cfg[INB_HOGPD_NB_HIDS_INST_MAX];
} inb_hogpd_prf_t;

/// HID Report Info
typedef struct 
{
    /// HIDS Instance
    uint8_t  hid_idx;
    /// type of report (@see enum inb_hogpd_report_type)
    uint8_t  type;
    /// Report Length (uint8_t)
    uint16_t length;
    /// Report Instance - 0 for boot reports and report map
    uint8_t  idx;
    /// Report data
    uint8_t value[];
} inb_hogpd_report_info_t;

typedef struct 
{
    /// Connection Index
    uint8_t conidx;
    /// Operation requested (read/write @see hog_pd_op)
    uint8_t operation;
    /// Report Info
    inb_hogpd_report_info_t report;
} inb_evt_hogpd_report_req_ind_t;

/// Inform Device APP that Protocol Mode Characteristic Value has been written on Device
typedef struct 
{
    /// Connection Index
    uint8_t conidx;
    /// Operation requested (update protocol mode @see hogpd_op)
    uint8_t operation;
    /// HIDS Instance
    uint8_t hid_idx;
    /// New Protocol Mode Characteristic Value
    uint8_t proto_mode;
} inb_evt_hogpd_proto_mode_req_ind_t;

typedef struct 
{
    /// Connection Index
    uint8_t conidx;

    /// Notification Configurations
    uint16_t ntf_cfg[INB_HOGPD_NB_HIDS_INST_MAX];
} inb_evt_hogpd_ntf_cfg_ind_t;

typedef struct 
{
    /// Connection Index
    uint8_t conidx;
    /// HIDS Instance
    uint8_t hid_idx;
    /// New HID Control Point Characteristic Value
    uint8_t hid_ctnl_pt;
} inb_evt_hogpd_ctnl_pt_ind_t;

/*
 * HOG Report host profile
 ****************************************************************************************
 */

///Structure containing the characteristics handles, value handles and descriptors
typedef struct 
{
    /// Service info
    inb_svc_t svc;

    /// Included service info
    inb_incl_svc_t incl_svc;

    /// Characteristic info:
    inb_char_inf_t chars[INB_HOGPRH_CHAR_MAX];

    /// Descriptor handles:
    inb_char_desc_inf_t descs[INB_HOGPRH_DESC_MAX];

    /// Number of Report Char. that have been found
    uint8_t report_nb;
} inb_hogprh_content_t;

/// HID report info
typedef struct 
{
    /// Report Length
    uint8_t length;
    /// Report value
    uint8_t value[];
} inb_hogprh_report_t;

/// HID report Reference
typedef struct 
{
    /// Report ID
    uint8_t id;
    /// Report Type
    uint8_t type;
} inb_hogprh_report_ref_t;

/// HID report MAP info
typedef struct 
{
    /// Report MAP Length
    uint16_t length;
    /// Report MAP value
    uint8_t value[];
} inb_hogprh_report_map_t;

/// HID report MAP reference
typedef struct 
{
    /// Reference UUID length
    uint8_t uuid_len;
    /// Reference UUID Value
    uint8_t uuid[];
} inb_hogprh_report_map_ref_t;

typedef union 
{
    /// Protocol Mode
    ///  - info = HOG_PRH_PROTO_MODE
    uint8_t proto_mode;

    /// HID Information value
    ///  - info = HOG_PRH_HID_INFO
    inb_hogpd_info_t hid_info;

    /// HID Control Point value to write
    ///  - info = HOG_PRH_HID_CTNL_PT
    uint8_t hid_ctnl_pt;

    /// Report information
    ///  - info = HOG_PRH_REPORT
    inb_hogprh_report_t report;

    ///Notification Configuration Value
    ///  - info = HOGPRH_REPORT_NTF_CFG
    uint16_t report_cfg;

    /// HID report Reference
    ///  - info = HOGPRH_REPORT_REF
    inb_hogprh_report_ref_t report_ref;

    /// HID report MAP info
    ///  - info = HOGPRH_REPORT_MAP
    inb_hogprh_report_map_t report_map;

    /// HID report MAP reference
    ///  - info = HOGPRH_REPORT_MAP_EXT_REP_REF
    inb_hogprh_report_map_ref_t report_map_ref;
} inb_hogprh_data_t;

typedef struct 
{
    ///Characteristic info @see enum hog_prh_info
    uint8_t info;
    /// HID Service Instance - From 0 to HOGPRH_NB_HIDS_INST_MAX-1
    uint8_t hid_idx;
    /// HID Report Index: only relevant for:
    ///  - info = HOG_PRH_REPORT
    ///  - info = HOG_PRH_REPORT_REF
    ///  - info = HOG_PRH_REPORT_NTF_CFG
    uint8_t report_idx;
} inb_hogprh_read_info_req_t;

typedef struct 
{
    ///Characteristic info @see enum hog_prh_info
    uint8_t info;
    /// HID Service Instance - From 0 to HOG_PRH_NB_HIDS_INST_MAX-1
    uint8_t hid_idx;
    /// HID Report Index: only relevant for:
    ///  - info = HOG_PRH_REPORT
    ///  - info = HOG_PRH_REPORT_REF
    ///  - info = HOG_PRH_REPORT_NTF_CFG
    uint8_t report_idx;
    /// Information data
    inb_hogprh_data_t data;
} inb_hogprh_read_info_rsp_t;

typedef struct 
{
    ///Characteristic info @see enum hog_prh_info
    uint8_t info;
    /// HID Service Instance - From 0 to HOG_PRH_NB_HIDS_INST_MAX-1
    uint8_t hid_idx;
    /// HID Report Index: only relevant for:
    ///  - info = HOG_PRH_REPORT
    ///  - info = HOG_PRH_REPORT_NTF_CFG
    uint8_t report_idx;
    /// Write type ( Write without Response True or Write Request)
    /// - only valid for HOGPRH_REPORT
    bool    wr_cmd;
    /// Information data
    inb_hogprh_data_t data;
} inb_hogprh_write_req_t;


///Parameters of the @ref HOGPRH_BOOT_REPORT_IND message
typedef struct 
{
	/// Connection index
	uint8_t conidx;
    /// HIDS Instance
    uint8_t hid_idx;
    /// HID Report Index
    uint8_t report_idx;
    /// Report data
    inb_hogprh_report_t report;
} inb_evt_hogprh_report_ind_t;

/*
 * APIs
 ****************************************************************************************
 */

/*
 * HOGPBH FUNCTIONS
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Add HOGPBH profile 
 *	
 * @note Add it after device configuration, but before any activity starts
 *
 *
 * @param[in] p_prf					Pointer to profile attributes, no paramters
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_hogpbh_add(inb_add_prf_t *p_prf);

/**
 ****************************************************************************************
 * @brief Enable HOGPBH profile 
 *	
 * @note First function to call after connection 
 *
 * @param[in] conidx				Connection index
 * @param[in] con_type			Connnetion type, @see enum inb_con_type
 * @param[in] hids_nb				Number of profile to enable
 * @param[in,out] cont			Contents of service
 *													- Discover connection type: Stack will fill it
 *													- Normal connection type: Application needs to fill it. 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_hogpbh_enable(int conidx, int con_type, uint8_t hids_nb, inb_hogpbh_content_t cont[]);

/**
 ****************************************************************************************
 * @brief Read peer info 
 *	
 *
 * @param[in] conidx				Connection index
 * @param[in] hid_idx				Instance index  
 * @param[in] info					Information to read, @see enum inb_hogprh_info
 * @param[out] p_rsp				Reponse from the peere
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_hogpbh_read_info_req(int conidx, int hid_idx, int info, inb_hogpbh_read_info_rsp_t *p_rsp);

/**
 ****************************************************************************************
 * @brief Write info to peer  
 *	
 *
 * @param[in] conidx				Connection index
 * @param[in] hid_idx				Index  
 * @param[in] info					Information to write, @see enum inb_hogprh_info
 *	@param[in] wr_cmd				Write command
 *													1 - write request no response
 *													0 - write request 
 * @param[in] p_data				Write data
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_hogpbh_write_req(int conidx, int hid_idx, int info, int wr_cmd, inb_hogpbh_data_t *p_data);

/*
 * HOGPD FUNCTIONS
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Add HOGPD profile 
 *	
 * @note Add it after device configuration, but before any activity starts
 *
 *
 * @param[in] p_prf					Pointer to profile attributes, @see inb_hogpd_prf_t
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_hogpd_add(inb_add_prf_t *p_prf)	;

/**
 ****************************************************************************************
 * @brief Enable HOGPBH profile 
 *	
 * @note First function to call after connection 
 *
 * @param[in] conidx				Connection index
 * @param[in] ntf_cfg				Notifiction configuraton, @see enum inb_hogpd_cfg
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_hogpd_enable(int conidx, uint16_t ntf_cfg[]);

/**
 ****************************************************************************************
 * @brief Request sending of a report to the host - notification  
 *	
 *
 * @param[in] conidx				Connection index
 * @param[in] p_info					Report info
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_hogpd_report_upd_req(int conidx, inb_hogpd_report_info_t *p_info);

/**
 ****************************************************************************************
 * @brief Confirmation for peer device for Reading or Updating a report value  
 *	
 *
 * @param[in] conidx				Connection index
 * @param[in] operation			Operation requested, @see enum inb_hogpd_op
 * @param[in] status				Status of the request
 * @param[in] p_info					Report Info
 *
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_hogpd_report_req_cfm(int conidx, int operation, int status, inb_hogpd_report_info_t *p_info);

/**
 ****************************************************************************************
 * @brief Confirm if the new protocol mode value  
 *	
 *
 * @param[in] conidx				Connection index
 * @param[in] status				Status of the request
 * @param[in] hid_idx				HIDS Instance
 * @param[in] proto_mode		New Protocol Mode Characteristic Value
 *
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */

int inb_hogpd_proto_mode_req_cfm(int conidx, int status, int hid_idx, int proto_mode);

/*
 * HOGPRH FUNCTIONS
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Add HOGPRH profile 
 *	
 * @note Add it after device configuration, but before any activity starts
 *
 *
 * @param[in] p_prf					Pointer to profile attributes, no parameters
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_hogprh_add(inb_add_prf_t *p_prf);

/**
 ****************************************************************************************
 * @brief Enable HOGPRH profile 
 *	
 * @note First function to call after connection 
 *
 * @param[in] conidx				Connection index
 * @param[in] con_type			Connnetion type, @see enum inb_con_type
 * @param[in] hids_nb				Number of instances
 * @param[in,out] cont			Contents of service
 *													- Discover connection type: Stack will fill it
 *													- Normal connection type: Application needs to fill it. 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_hogprh_enable(int conidx, int con_type, int hids_nb, inb_hogprh_content_t cont[]);

/**
 ****************************************************************************************
 * @brief Read peer info 
 *	
 *
 * @param[in] conidx				Connection index
 * @param[in] p_req					Request information  
 * @param[out] p_rsp				Reponse from the peere
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_hogprh_read_info_req(int conidx, inb_hogprh_read_info_req_t *p_req, inb_hogprh_read_info_rsp_t *p_rsp);	

/**
 ****************************************************************************************
 * @brief Write info to peer  
 *	
 *
 * @param[in] conidx				Connection index
 * @param[in] p_req					Write information  
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_hogprh_write_req(int conidx, inb_hogprh_write_req_t *p_req)	;

/// @} INB_PRF_HOG
#endif

