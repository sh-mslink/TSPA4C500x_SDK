/**
 ****************************************************************************************
 *
 * @file inb_gap.h
 *
 * @brief BLE General Access Profile
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef INB_GAP_H
#define INB_GAP_H

/**
 ****************************************************************************************
 * @defgroup INB_GAP BLE General Access Profile  
 * @ingroup BLE
 * @brief  BLE GAP
 * @{
 ****************************************************************************************
 */

#include <stdint.h>

/*
 * DEFINES
 ****************************************************************************************
 */

/// BD address length
#define BLE_BDADDR_LEN       (6)
/// LE Channel map length
#define BLE_CHNL_MAP_LEN   (0x05)
/// LE Feature Flags Length
#define BLE_FEATS_LEN      (0x08)
/// ADV Data and Scan Response length
#define BLE_ADV_DATA_LEN      (0x1F)
#define BLE_SCAN_RSP_DATA_LEN (0x1F)
/// Random number length
#define BLE_RAND_NB_LEN       (0x08)
/// Key length
#define BLE_KEY_LEN           (16)
/// P256 Key Len
#define BLE_P256_KEY_LEN      (0x20)

/// Connection interval min (N*1.250ms)
#define GAP_CNX_INTERVAL_MIN            6       //(0x06)
/// Connection interval Max (N*1.250ms)
#define GAP_CNX_INTERVAL_MAX            3200    //(0xC80)
/// Connection latency min (N*cnx evt)
#define GAP_CNX_LATENCY_MIN             0       //(0x00)
/// Connection latency Max (N*cnx evt
#define GAP_CNX_LATENCY_MAX             499     //(0x1F3)
/// Supervision TO min (N*10ms)
#define GAP_CNX_SUP_TO_MIN              10      //(0x0A)
/// Supervision TO Max (N*10ms)
#define GAP_CNX_SUP_TO_MAX              3200    //(0xC80)

/// Length of resolvable random address prand part
#define ADDR_PRAND_LEN            (3)
/// Length of resolvable random address hash part
#define ADDR_HASH_LEN             (3)

/*
 * DEFINES - Optional for BLE application usage
 ****************************************************************************************
 */

/// Central idle timer
/// TGAP(conn_pause_central)
/// recommended value: 1 s: (100 for ke timer)
#define GAP_TMR_CONN_PAUSE_CT                               0x0064

/// Minimum time upon connection establishment before the peripheral
/// starts a connection update procedure: TGAP(conn_pause_peripheral)
/// recommended value: 5 s: (500 for ke timer)
#define GAP_TMR_CONN_PAUSE_PH                               0x01F4

/// Minimum time to perform scanning when user initiated
/// TGAP(scan_fast_period)
/// recommended value: 30.72 s: (3072 for ke timer)
#define GAP_TMR_SCAN_FAST_PERIOD                            0x0C00

/// Minimum time to perform advertising when user initiated
/// TGAP(adv_fast_period)
/// recommended value: 30 s: (3000 for ke timer)
#define GAP_TMR_ADV_FAST_PERIOD                             0x0BB8

/// Scan interval used during Link Layer Scanning State when
/// performing the Limited Discovery procedure
/// TGAP(lim_disc_scan_int)
/// recommended value: 11.25ms; (18 decimal)
#define GAP_LIM_DISC_SCAN_INT                               0x0012

/// Scan interval in any discovery or connection establishment
/// procedure when user initiated: TGAP(scan_fast_interval)
/// recommended value: 30 to 60 ms; N * 0.625
#define GAP_SCAN_FAST_INTV                                  0x0030

/// Scan window in any discovery or connection establishment
/// procedure when user initiated: TGAP(scan_fast_window)
/// recommended value: 30 ms; N * 0.625
#define GAP_SCAN_FAST_WIND                                  0x0030

/// Scan interval in any discovery or connection establishment
/// procedure when background scanning: TGAP(scan_slow_interval1)
/// recommended value: 1.28 s : 0x00CD (205); N * 0.625
#define GAP_SCAN_SLOW_INTV1                                 0x00CD

/// Scan interval in any discovery or connection establishment
/// procedure when background scanning: TGAP(scan_slow_interval2)
/// recommended value: 2.56 s : 0x019A (410); N * 0.625
#define GAP_SCAN_SLOW_INTV2                                 0x019A

/// Scan window in any discovery or connection establishment
/// procedure when background scanning: TGAP(scan_slow_window1)
/// recommended value: 11.25 ms : 0x0012 (18); N * 0.625
#define GAP_SCAN_SLOW_WIND1                                 0x0012

/// Scan window in any discovery or connection establishment
/// procedure when background scanning: TGAP(scan_slow_window2)
/// recommended value: 22.5 ms : 0x0024 (36); N * 0.625
#define GAP_SCAN_SLOW_WIND2                                 0x0024

/// Minimum to maximum advertisement interval in any discoverable
/// or connectable mode when user initiated: TGAP(adv_fast_interval1)
/// recommended value: 30 to 60 ms; N * 0.625
#define GAP_ADV_FAST_INTV1                                  0x0030

/// Minimum to maximum advertisement interval in any discoverable
/// or connectable mode when user initiated: TGAP(adv_fast_interval2)
/// recommended value: 100 to 150 ms; N * 0.625
#define GAP_ADV_FAST_INTV2                                  0x0064

/// Minimum to maximum advertisement interval in any discoverable or
/// connectable mode when background advertising: TGAP(adv_slow_interval)
/// recommended value: 1 to 1.2 s : 0x00B0 (176); N * 0.625
#define GAP_ADV_SLOW_INTV                                   0x00B0

/// Minimum to maximum connection interval upon any connection
/// establishment: TGAP(initial_conn_interval)
/// recommended value: 30 to 50 ms ; N * 1.25 ms
#define GAP_INIT_CONN_MIN_INTV                              0x0018
#define GAP_INIT_CONN_MAX_INTV                              0x0028

/// Connection supervision timeout
/// recommended value: 20s
#define GAP_CONN_SUPERV_TIMEOUT                             0x07D0

/// Minimum connection event
/// default value: 0x0000
#define GAP_CONN_MIN_CE                                     0x0000

/// Maximum connection event
/// default value: 0xFFFF
#define GAP_CONN_MAX_CE                                     0xFFFF

/// Connection latency
/// default value: 0x0000
#define GAP_CONN_LATENCY                                    0x0000

/// GAP Appearance or Icon Characteristic - 2 octets
/// Current appearance value is 0x0000 (unknown appearance)
/// Description:
/// http://developer.bluetooth.org/gatt/characteristics/Pages/CharacteristicViewer.aspx?u=org.bluetooth.characteristic.gap.appearance.xml
#define GAP_APPEARANCE                                      0x0000

///GAP Peripheral Preferred Connection Parameter - 8 octets
#define GAP_PPCP_CONN_INTV_MAX                              0x0064
#define GAP_PPCP_CONN_INTV_MIN                              0x00C8
#define GAP_PPCP_SLAVE_LATENCY                              0x0000
#define GAP_PPCP_STO_MULT                                   0x07D0

/*
 * Enumerations
 ****************************************************************************************
 */
/// GAP Advertising Flags
enum inb_ad_type
{
    /// Flag
    AD_TYPE_FLAGS                      = 0x01,//!< GAP_AD_TYPE_FLAGS
    /// Use of more than 16 bits UUID
    AD_TYPE_MORE_16_BIT_UUID           = 0x02,//!< GAP_AD_TYPE_MORE_16_BIT_UUID
    /// Complete list of 16 bit UUID
    AD_TYPE_COMPLETE_LIST_16_BIT_UUID  = 0x03,//!< GAP_AD_TYPE_COMPLETE_LIST_16_BIT_UUID
    /// Use of more than 32 bit UUD
    AD_TYPE_MORE_32_BIT_UUID           = 0x04,//!< GAP_AD_TYPE_MORE_32_BIT_UUID
    /// Complete list of 32 bit UUID
    AD_TYPE_COMPLETE_LIST_32_BIT_UUID  = 0x05,//!< GAP_AD_TYPE_COMPLETE_LIST_32_BIT_UUID
    /// Use of more than 128 bit UUID
    AD_TYPE_MORE_128_BIT_UUID          = 0x06,//!< GAP_AD_TYPE_MORE_128_BIT_UUID
    /// Complete list of 128 bit UUID
    AD_TYPE_COMPLETE_LIST_128_BIT_UUID = 0x07,//!< GAP_AD_TYPE_COMPLETE_LIST_128_BIT_UUID
    /// Shortened device name
    AD_TYPE_SHORTENED_NAME             = 0x08,//!< GAP_AD_TYPE_SHORTENED_NAME
    /// Complete device name
    AD_TYPE_COMPLETE_NAME              = 0x09,//!< GAP_AD_TYPE_COMPLETE_NAME
    /// Transmit power
    AD_TYPE_TRANSMIT_POWER             = 0x0A,//!< GAP_AD_TYPE_TRANSMIT_POWER
    /// Class of device
    AD_TYPE_CLASS_OF_DEVICE            = 0x0D,//!< GAP_AD_TYPE_CLASS_OF_DEVICE
    /// Simple Pairing Hash C
    AD_TYPE_SP_HASH_C                  = 0x0E,//!< GAP_AD_TYPE_SP_HASH_C
    /// Simple Pairing Randomizer
    AD_TYPE_SP_RANDOMIZER_R            = 0x0F,//!< GAP_AD_TYPE_SP_RANDOMIZER_R
    /// Temporary key value
    AD_TYPE_TK_VALUE                   = 0x10,//!< GAP_AD_TYPE_TK_VALUE
    /// Out of Band Flag
    AD_TYPE_OOB_FLAGS                  = 0x11,//!< GAP_AD_TYPE_OOB_FLAGS
    /// Slave connection interval range
    AD_TYPE_SLAVE_CONN_INT_RANGE       = 0x12,//!< GAP_AD_TYPE_SLAVE_CONN_INT_RANGE
    /// Require 16 bit service UUID
    AD_TYPE_RQRD_16_BIT_SVC_UUID       = 0x14,//!< GAP_AD_TYPE_RQRD_16_BIT_SVC_UUID
    /// Require 32 bit service UUID
    AD_TYPE_RQRD_32_BIT_SVC_UUID       = 0x1F,//!< GAP_AD_TYPE_RQRD_32_BIT_SVC_UUID
    /// Require 128 bit service UUID
    AD_TYPE_RQRD_128_BIT_SVC_UUID      = 0x15,//!< GAP_AD_TYPE_RQRD_128_BIT_SVC_UUID
    /// Service data 16-bit UUID
    AD_TYPE_SERVICE_16_BIT_DATA        = 0x16,//!< GAP_AD_TYPE_SERVICE_16_BIT_DATA
    /// Service data 32-bit UUID
    AD_TYPE_SERVICE_32_BIT_DATA        = 0x20,//!< GAP_AD_TYPE_SERVICE_32_BIT_DATA
    /// Service data 128-bit UUID
    AD_TYPE_SERVICE_128_BIT_DATA       = 0x21,//!< GAP_AD_TYPE_SERVICE_128_BIT_DATA
    /// Public Target Address
    AD_TYPE_PUB_TGT_ADDR               = 0x17,//!< GAP_AD_TYPE_PUB_TGT_ADDR
    /// Random Target Address
    AD_TYPE_RAND_TGT_ADDR              = 0x18,//!< GAP_AD_TYPE_RAND_TGT_ADDR
    /// Appearance
    AD_TYPE_APPEARANCE                 = 0x19,//!< GAP_AD_TYPE_APPEARANCE
    /// Advertising Interval
    AD_TYPE_ADV_INTV                   = 0x1A,//!< GAP_AD_TYPE_ADV_INTV
    /// LE Bluetooth Device Address
    AD_TYPE_LE_BT_ADDR                 = 0x1B,//!< GAP_AD_TYPE_LE_BT_ADDR
    /// LE Role
    AD_TYPE_LE_ROLE                    = 0x1C,//!< GAP_AD_TYPE_LE_ROLE
    /// Simple Pairing Hash C-256
    AD_TYPE_SPAIR_HASH                 = 0x1D,//!< GAP_AD_TYPE_SPAIR_HASH
    /// Simple Pairing Randomizer R-256
    AD_TYPE_SPAIR_RAND                 = 0x1E,//!< GAP_AD_TYPE_SPAIR_RAND
    /// 3D Information Data
    AD_TYPE_3D_INFO                    = 0x3D,//!< GAP_AD_TYPE_3D_INFO

    /// Manufacturer specific data
    AD_TYPE_MANU_SPECIFIC_DATA         = 0xFF,//!< GAP_AD_TYPE_MANU_SPECIFIC_DATA
};

/// Random Address type
enum inb_rnd_addr_type
{
    /// Static random address           - 11 (MSB->LSB)
    STATIC_ADDR     = 0xC0,
    /// Private non resolvable address  - 01 (MSB->LSB)
    NON_RSLV_ADDR   = 0x00,
    /// Private resolvable address      - 01 (MSB->LSB)
    RSLV_ADDR       = 0x40,
};

/// GAP Role 
enum inb_role
{
    /// No role set yet
    ROLE_NONE        = 0x00,

    /// Observer role
    ROLE_OBSERVER    = 0x01,

    /// Broadcaster role
    ROLE_BROADCASTER = 0x02,

    /// Master/Central role
    ROLE_CENTRAL     = (0x04 | ROLE_OBSERVER),

    /// Peripheral/Slave role
    ROLE_PERIPHERAL  = (0x08 | ROLE_BROADCASTER),

    /// Device has all role, both peripheral and central
    ROLE_ALL         = (ROLE_CENTRAL | ROLE_PERIPHERAL),
};

/// IO Capability Values
enum inb_io_cap
{
    /// Display Only
    IO_CAP_DISPLAY_ONLY = 0x00,
    /// Display Yes No
    IO_CAP_DISPLAY_YES_NO,
    /// Keyboard Only
    IO_CAP_KB_ONLY,
    /// No Input No Output
    IO_CAP_NO_INPUT_NO_OUTPUT,
    /// Keyboard Display
    IO_CAP_KB_DISPLAY,
    IO_CAP_LAST
};

/// TK Type
enum inb_tk_type
{
    ///  TK get from out of band method
    TK_OOB         = 0x00,
    /// TK generated and shall be displayed by local device
    TK_DISPLAY,
    /// TK shall be entered by user using device keyboard
    TK_KEY_ENTRY
};

/// OOB Data Present Flag Values
enum inb_oob
{
    /// OOB Data not present
    OOB_AUTH_DATA_NOT_PRESENT = 0x00,
    /// OOB data present
    OOB_AUTH_DATA_PRESENT,
    OOB_AUTH_DATA_LAST
};

/// Authentication mask
enum inb_auth_mask
{
    /// No Flag set
    AUTH_NONE    = 0,
    /// Bond authentication
    AUTH_BOND    = (1 << 0),
    /// Man In the middle protection
    AUTH_MITM    = (1 << 2),
    /// Secure Connection
    AUTH_SEC_CON = (1 << 3),
    /// Key Notification
    AUTH_KEY_NOTIF = (1 << 4)
};

/// Security Link Level
enum inb_lk_sec_lvl
{
    /// No authentication
    LK_NO_AUTH             = 0,
    /// Unauthenticated link
    LK_UNAUTH,
    /// Authenticated link
    LK_AUTH,
    /// Secure Connection link
    LK_SEC_CON,
};

/// Authentication Requirements
enum inb_auth
{
    /// No MITM No Bonding
    AUTH_REQ_NO_MITM_NO_BOND  = (AUTH_NONE),
    /// No MITM Bonding
    AUTH_REQ_NO_MITM_BOND     = (AUTH_BOND),
    /// MITM No Bonding
    AUTH_REQ_MITM_NO_BOND     = (AUTH_MITM),
    /// MITM and Bonding
    AUTH_REQ_MITM_BOND        = (AUTH_MITM | AUTH_BOND),
    /// SEC_CON and No Bonding
    AUTH_REQ_SEC_CON_NO_BOND  = (AUTH_SEC_CON),
    /// SEC_CON and Bonding
    AUTH_REQ_SEC_CON_BOND     = (AUTH_SEC_CON | AUTH_BOND),

    AUTH_REQ_LAST,

    /// Mask of  authentication features without reserved flag
    AUTH_REQ_MASK             = 0x1F,
};

/// Key Distribution Flags
enum inb_kdist
{
    /// No Keys to distribute
    KDIST_NONE = 0x00,
    /// Encryption key in distribution
    KDIST_ENCKEY = (1 << 0),
    /// IRK (ID key)in distribution
    KDIST_IDKEY  = (1 << 1),
    /// CSRK(Signature key) in distribution
    KDIST_SIGNKEY= (1 << 2),
    /// LTK in distribution
    KDIST_LINKKEY=   (1 << 3),

    KDIST_LAST =   (1 << 4)
};

/// Security Defines
enum inb_sec_req
{
    /// No security (no authentication and encryption)
    NO_SEC = 0x00,
    /// Unauthenticated pairing with encryption
    SEC1_NOAUTH_PAIR_ENC,
    /// Authenticated pairing with encryption
    SEC1_AUTH_PAIR_ENC,
    /// Unauthenticated pairing with data signing
    SEC2_NOAUTH_DATA_SGN,
    /// Authentication pairing with data signing
    SEC2_AUTH_DATA_SGN,
    /// Secure Connection pairing with encryption
    SEC1_SEC_CON_PAIR_ENC,
};

/// Bit field use to select the preferred TX or RX LE PHY. 0 means no preferences
enum inb_phy
{
    /// No preferred PHY
    PHY_ANY               = 0x00,
    /// LE 1M PHY preferred for an active link
    PHY_LE_1MBPS          = (1 << 0),
    /// LE 2M PHY preferred for an active link
    PHY_LE_2MBPS          = (1 << 1),
    /// LE Coded PHY preferred for an active link
    PHY_LE_CODED          = (1 << 2),
};

/// PHY value return from the link layer
enum inb_phy_value
{
	/// Not defined
	PHY_UNDEF_LNK_VALUE    = 0,
	/// LE 1M PHY Value
	PHY_1MBPS_LNK_VALUE    = 1,
	/// LE 2M PHY Value
	PHY_2MBPS_LNK_VALUE    = 2,
	/// LE CODED PHY Value
	PHY_CODED_LNK_VALUE    = 3,
};


/// Test mode operation
enum inb_test_mode
{
	TEST_MODE_STOP = 1,
	TEST_MODE_RX,
	TEST_MODE_TX,
};

/// Enumeration of TX/RX PHY used for Test Mode
enum inb_test_phy
{
    /// LE 1M PHY (TX or RX)
    TEST_PHY_1MBPS        = 1,
    /// LE 2M PHY (TX or RX)
    TEST_PHY_2MBPS        = 2,
    /// LE Coded PHY (RX Only)
    TEST_PHY_CODED        = 3,
    /// LE Coded PHY with S=8 data coding (TX Only)
    TEST_PHY_125KBPS      = 3,
    /// LE Coded PHY with S=2 data coding (TX Only)
    TEST_PHY_500KBPS      = 4,
};

/// Modulation index
enum inb_modulation_idx
{
    /// Assume transmitter will have a standard modulation index
    MODULATION_STANDARD,
    /// Assume transmitter will have a stable modulation index
    MODULATION_STABLE,
};

/// Packet Payload type for test mode
enum inb_pkt_pld_type
{
    /// PRBS9 sequence "11111111100000111101..." (in transmission order)
    PKT_PLD_PRBS9,
    /// Repeated "11110000" (in transmission order)
    PKT_PLD_REPEATED_11110000,
    /// Repeated "10101010" (in transmission order)
    PKT_PLD_REPEATED_10101010,
    /// PRBS15 sequence
    PKT_PLD_PRBS15,
    /// Repeated "11111111" (in transmission order) sequence
    PKT_PLD_REPEATED_11111111,
    /// Repeated "00000000" (in transmission order) sequence
    PKT_PLD_REPEATED_00000000,
    /// Repeated "00001111" (in transmission order) sequence
    PKT_PLD_REPEATED_00001111,
    /// Repeated "01010101" (in transmission order) sequence
    PKT_PLD_REPEATED_01010101,
};

/// Privacy configuration
enum inb_priv_cfg
{
    /// Indicate if identity address is a public (0) or static private random (1) address
    PRIV_CFG_PRIV_ADDR_BIT = (1 << 0),
    /// Reserved
    PRIV_CFG_RSVD          = (1 << 1),
    /// Indicate if controller privacy is enabled
    PRIV_CFG_PRIV_EN_BIT   = (1 << 2),
};

/// Pairing mode authorized on the device
enum inb_pairing_mode
{
    /// No pairing authorized
    PAIRING_DISABLE  = 0,
    /// Legacy pairing Authorized
    PAIRING_LEGACY   = (1 << 0),
    /// Secure Connection pairing Authorized
    PAIRING_SEC_CON  = (1 << 1),

    /// Force re-generation of P256 private and public keys
    PAIRING_FORCE_P256_KEY_GEN = (1<<7),
};

/// Device Attribute write permission requirement
enum inb_write_att_perm
{
    /// Disable write access
    WRITE_DISABLE     = 0,
    /// Enable write access - no authentication required
    WRITE_NO_AUTH     = 1,
    /// Write access requires unauthenticated link
    WRITE_UNAUTH      = 2,
    /// Write access requires authenticated link
    WRITE_AUTH        = 3,
    /// Write access requires secure connected link
    WRITE_SEC_CON     = 4
};

/// get device local info command. 
enum inb_get_dev_info_cmd {
	/// Get local device version
	GET_DEV_INFO_VERSION,
	/// Get local device BD Address
	GET_DEV_INFO_BDADDR,		
	/// Get minimum and maximum transmit powers supported by the controller
	GET_DEV_INFO_TX_POWER,	
	/// Get device advertising power level 
	GET_DEV_INFO_ADV_TX_POWER,	
	/// Get suggested default data	
	GET_DEV_INFO_SUGG_DFT_DATA,	
	/// Get supported default data
	GET_DEV_INFO_SUPP_DFT_DATA,	
	/// Get maximum advertising data length supported by the controller. 
	GET_DEV_INFO_MAX_ADV_DATA_LEN,	
	/// Get White List Size. 
	GET_DEV_INFO_WLIST_SIZE,		
	/// Get resolving address list size. 		
	GET_DEV_INFO_RAL_SIZE,	
	/// Get periodic advertiser list size. 
	GET_DEV_INFO_PAL_SIZE,	
	/// Get number of available advertising sets. 
	GET_DEV_INFO_NB_ADV_SETS,		
};

/// Type of activities that can be created
enum inb_actv_type
{
    /// Advertising activity
    ACTV_TYPE_ADV = 0,
    /// Scanning activity
    ACTV_TYPE_SCAN,
    /// Initiating activity
    ACTV_TYPE_INIT,
    /// Periodic synchronization activity
    ACTV_TYPE_PER_SYNC,
};

/// Advertising report type
enum adv_report_type
{
    /// Extended advertising report
    REPORT_TYPE_ADV_EXT = 0,
    /// Legacy advertising report
    REPORT_TYPE_ADV_LEG,
    /// Extended scan response report
    REPORT_TYPE_SCAN_RSP_EXT,
    /// Legacy scan response report
    REPORT_TYPE_SCAN_RSP_LEG,
    /// Periodic advertising report
    REPORT_TYPE_PER_ADV,
};

/// Advertising report information
enum inb_adv_report_info
{
    /// Report Type
    REPORT_INFO_REPORT_TYPE_MASK    = 0x07,
    /// Report is complete
    REPORT_INFO_COMPLETE_BIT        = (1 << 3),
    /// Connectable advertising
    REPORT_INFO_CONN_ADV_BIT        = (1 << 4),
    /// Scannable advertising
    REPORT_INFO_SCAN_ADV_BIT        = (1 << 5),
    /// Directed advertising
    REPORT_INFO_DIR_ADV_BIT         = (1 << 6),
};

///  Type of advertising that can be created.
enum inb_adv_type
{
	/// Legacy advertising. 
	ADV_TYPE_LEGACY = 0,	
	/// Extended advertising. 
	ADV_TYPE_EXTENDED,		
	/// Periodic advertising. 
	ADV_TYPE_PERIODIC,
};		

///Advertising discovery mode.
enum inb_adv_mode
{
	/// non-discoverable mode
	ADV_MODE_NON_DISC = 0,	
	/// general discoverable mode 
	ADV_MODE_GEN_DISC,	
	/// limited discoverable mode
	ADV_MODE_LIM_DISC,
};

/// Advertising properties 
enum inb_adv_prop
{
	/// Advertising is connectable, reception of CONNECT_REQ or AUX_CONNECT_REQ PDUs is accepted. 
	/// not applicable for periodic advertising. 
	ADV_PROP_CONNECTABLE = 0x01,
	/// Advertising is scannable, reception of SCAN_REQ or AUX_SCAN_REQ PDUs is accepted		
	ADV_PROP_SCANNABLE = 0x02,
	/// Advertising targets a specific device. Only apply in following cases:
	///		- Legacy advertising: if connectable
	///		- Extended advertising: connectable or (non connectable and non discoverable). 					
	ADV_PROP_DIRECTED	= 0x04,
	/// High Duty Cycle has to be used for advertising on primary channel
	/// Apply only if created advertising is not an extended advertising. 						
	ADV_PROP_HDC = 0x08,
	/// Enable anonymous mode. Device address won't appear in send PDUs
	/// Valid only if created advertising is an extended advertising. 									
	ADV_PROP_ANONYMOUS = 0x20,					
	/// TX Power in the extended header of the advertising PDU
	/// Valid only if created advertising is not a legacy advertising. 
	ADV_PROP_TX_PWR	= 0x40,
	/// TX Power in the periodic advertising PDU
	/// Valid only if created advertising is a periodic advertising. 						
	ADV_PROP_PER_TX_PWR = 0x80,
	/// Indicate if application must be informed about received scan requests PDUs. 					
	ADV_PROP_SCAN_REQ_NTF_EN = 0x100,	
	/// Indicate no advertising data  */
	ADV_PROP_NO_ADV_DATA = 0x200	
};

/// Advertising properties legacy advertising.
enum inb_adv_legacy_prop
{
	/// Non connectable non scannable advertising. 
	ADV_PROP_NON_CONN_NON_SCAN = 0x00,	
	/// Broadcast non scannable advertising - Discovery mode must be Non Discoverable. 
	ADV_PROP_BROADCAST_NON_SCAN = 0x00,
	/// Non connectable scannable advertising.
	ADV_PROP_NON_CONN_SCAN = ADV_PROP_SCANNABLE,		
	/// Broadcast scannable advertising - Discovery mode must be Non Discoverable. 
	ADV_PROP_BROADCAST_SCAN = ADV_PROP_NON_CONN_SCAN,		
	/// Undirected connectable advertising.
	ADV_PROP_UNDIR_CONN = 	ADV_PROP_CONNECTABLE | ADV_PROP_SCANNABLE, 	
	/// Directed connectable advertising.
	ADV_PROP_DIR_CONN = ADV_PROP_DIRECTED | ADV_PROP_CONNECTABLE,		
	/// Directed connectable with Low Duty Cycle 
	ADV_PROP_DIR_CONN_LDC = ADV_PROP_DIR_CONN,	
	/// Directed connectable with High Duty Cycle 
	ADV_PROP_DIR_CONN_HDC = ADV_PROP_DIR_CONN | ADV_PROP_HDC,	
};

/// Advertising properties for extended advertising.
enum inb_adv_ext_prop
{
	/// Non connectable non scannable extended advertising. 
	EXT_ADV_PROP_NON_CONN_NON_SCAN = 0x00,		
	/// Non connectable scannable extended advertising. 
	EXT_ADV_PROP_NON_CONN_SCAN = ADV_PROP_SCANNABLE,	
	/// Non connectable scannable directed extended advertising. 
	EXT_ADV_PROP_NON_CONN_SCAN_DIR = ADV_PROP_SCANNABLE | ADV_PROP_DIRECTED,	
	/// Non connectable anonymous directed extended advertising. 
	EXT_ADV_PROP_ANONYM_DIR = ADV_PROP_ANONYMOUS | ADV_PROP_DIRECTED,		
	/// Undirected connectable extended advertising. 
	EXT_ADV_PROP_UNDIR_CONN = ADV_PROP_CONNECTABLE,		
	/// Directed connectable extended advertising. 
	EXT_ADV_PROP_DIR_CONN = ADV_PROP_CONNECTABLE | ADV_PROP_DIRECTED,		
	/// Non connectable non scannable extended advertising with no advertising data */
	EXT_ADV_PROP_NON_CONN_NON_SCAN_NON_ADV_DATA = ADV_PROP_NO_ADV_DATA,
};	

/// Advertising properties for periodic advertising.
enum inb_adv_per_prop
{
	/// Undirected periodic advertising. 
	PER_ADV_PROP_UNDIR = 0x00,		
	/// Directed periodic advertising. 
	PER_ADV_PROP_DIR = ADV_PROP_DIRECTED		
};

/// Advertising filter policy.
enum inb_adv_filt_pol 
{
	/// Allow both scan and connection requests from anyone. 
	ADV_FILT_ALLOW_SCAN_ANY_CON_ANY = 0,
	/// Allow both scan req from White List devices only and connection req from anyone		
	ADV_FILT_ALLOW_SCAN_WLST_CON_ANY,	
	/// Allow both scan req from anyone and connection req from White List devices only. 
	ADV_FILT_ALLOW_SCAN_ANY_CON_WLST,
	/// Allow scan and connection requests from White List devices only. 	
	ADV_FILT_ALLOW_SCAN_WLST_CON_WLST,
};	

/// Advertising channel.
enum inb_adv_chnl
{
	CHANNEL_37 = 0x01,
	CHANNEL_38 = 0x02,
	CHANNEL_39 = 0x04,
};

/// 
enum inb_addr_type
{
	///		0: static (public or private),
	ADDR_STATIC,
	///		1: generate resolvable private random address,
	ADDR_RESOLVABLE,
	///		2: generate non-resolvable private random address. 
	ADDR_NON_RESOLVABLE,
};

///  Scanning Types.
enum inb_scan_type
{
	/// General discovery. 
	GEN_DISC = 0,
	/// Limited discovery.  		
	LIM_DISC,	
	/// Observer. 
	OBSERVER,	
	/// Selective observer. 
	SEL_OBSERVER,	
	/// Connectable discovery. 
	CONN_DISC,
	/// Selective connectable discovery, using white list. 
	SEL_CONN_DISC,
};

/// Scan properties.
enum inb_scan_prop
{
	/// Scan advertisement on the LE 1M PHY. 
	SCAN_PROP_PHY_1M = 0x01,	
	/// Scan advertisement on the LE Coded PHY. 
	SCAN_PROP_PHY_CODED = 0x02,	
	/// Active scan on LE 1M PHY (Scan Request PDUs may be sent). 
	SCAN_PROP_ACTIVE_1M = 0x04,	
	/// Active scan on LE Coded PHY (Scan Request PDUs may be sent).  	
	SCAN_PROP_ACTIVE_CODED = 0x08,	
	/// Accept directed advertising packets if we use a RPA and target address cannot be solved by the controller. 
	SCAN_PROP_ACCEPT_RPA = 0x10,
	/// Filter truncated advertising or scan response reports. 
	SCAN_PROP_FILT_TRUNC = 0x20,
};		

/// Scan Filter duplicates Policy.
enum inb_scan_dup_filt
{
	/// Disable filtering of duplicate packets. 
	DUPLIC_DIS = 0,
	/// Enable filtering of duplicate packets. */		 
	DUPLIC_EN,
	/// Enable filtering of duplicate packets per scan period. 
	DUPLIC_EN_PER_PERIOD,
};

/// Initiator Types.
enum inb_initiator_type
{
	/// Direct connection establishment, establish a connection with an indicated device. 
	INIT_TYPE_DIRECT_CONN_EST = 0,
	/// Automatic connection establishment, establish a connection with all devices whose address is
	/// present in the white list. 
	INIT_TYPE_AUTO_CONN_EST,
	/// Name discovery, Establish a connection with an indicated device in order to read content of its
	/// Device Name characteristic. Connection is closed once this operation is stopped. 																					
	INIT_TYPE_NAME_DISC,
};

/// Initiator Properties.
enum inb_initiator_prop
{
	/// Scan connectable advertisements on the LE 1M PHY, Connection parameters for the LE 1M PHY are provided. 
	INIT_PROP_1M = 0x01,
	/// Scan connectable advertisements on the LE 2 M PHY, Connection parameters for the LE 2M PHY are provided. 
	INIT_PROP_2M = 0x02,
	/// Scan connectable advertisements on the LE Coded PHY, Connection parameters for the LE Coded PHY are provided. 
	INIT_PROP_CODED = 0x04,
};

/// Periodic synchronization types.
enum inb_per_sync_type
{
	/// Do not use periodic advertiser list for synchronization. Use advertiser information provided
	///	in the ACTIVITY_START_CMD. 
	PER_SYNC_TYPE_GENERAL = 0,	
	/// Use periodic advertiser list for synchronization. 
	PER_SYNC_TYPE_SELECTIVE,
};

///	LE CODED PHY option
enum inb_coded_phy_opt {
	/// No preference
	LE_CODED_ALL_RATES = 0x01,
	/// 500kbps rate 
	LE_CODED_500K_RATE =  0x02,
	/// 125kbps rate
	LE_CODED_125K_RATE = 0x04,
};

/// Keypress state
enum inb_keypress_state {
	/// Passkey entry started,
	PASSKEY_ENTRY_STARTED = 0,	
	/// Passkey digit entered.
	PASSKEY_DIGIT_ENTERED,
	/// Passkey digit erased. 
	PASSKEY_DIGIT_ERASED	,
	/// Passkey cleared.
	PASSKEY_CLEARED	,
	/// Passkey entry completed.
	PASSKEY_ENTRY_COMPLETED,
};	

/// Bond request/event type.
enum inb_bond
{
    /// Bond Pairing request
    PAIRING_REQ,
    /// Respond to Pairing request
    PAIRING_RSP,

    /// Pairing Finished information
    PAIRING_SUCCEED,
    /// Pairing Failed information
    PAIRING_FAILED,

    /// Used to retrieve pairing Temporary Key
    TK_EXCH,
    /// Used for Identity Resolving Key exchange
    IRK_EXCH,
    /// Used for Connection Signature Resolving Key exchange
    CSRK_EXCH,
    /// Used for Long Term Key exchange
    LTK_EXCH,

    /// Bond Pairing request issue, Repeated attempt
    REPEATED_ATTEMPT,

    /// Out of Band - exchange of confirm and rand.
    OOB_EXCH,

    /// Numeric Comparison - Exchange of Numeric Value -
    NC_EXCH
};

/// Clock accuracy values
enum inb_clk_acc
{
    /// 500 ppm
    CLK_ACC_500 = 0,
    /// 250 ppm
    CLK_ACC_250,
    /// 150 ppm
    CLK_ACC_150,
    /// 100 ppm
    CLK_ACC_100,
    /// 75 ppm
    CLK_ACC_75,
    /// 50 ppm
    CLK_ACC_50,
    /// 30 ppm
    CLK_ACC_30,
    /// 20 ppm
    CLK_ACC_20,
};

/// Disconnect reason code
enum inb_disc_reason {
	/// Pairing or authentication failed
	DISC_REASON_AUTH_FAILURE = 	0x05,
	/// User on the remote device terminated the connnection
	DISC_REASON_REMOTE_USER_TERM_CON = 0x13,
	/// Low resources
	DISC_REASON_REMOTE_DEV_TERM_LOW_RESOURCES = 0x14,
	/// Device is about to power off
	DISC_REASON_REMOTE_DEV_POWER_OFF = 0x15,
	/// Feature not supported
	DISC_REASON_UNSUPPORTED_REMOTE_FEATURE = 0x1A,		
	/// Not support key for pairing 
	DISC_REASON_PAIRING_WITH_UNIT_KEY_NOT_SUPP = 0x29,		
	/// Unacceptable connection interval 
	DISC_REASON_UNACCEPTABLE_CONN_INT = 0x3B,
};


/// List of device info that should be provided by application
/*@TRACE*/
enum inb_dev_info
{
    /// Device Name
   DEV_NAME,
    /// Device Appearance Icon
    DEV_APPEARANCE,
    /// Device Slave preferred parameters
    DEV_SLV_PREF_PARAMS,
    /// Device Central address resolution
    DEV_CTL_ADDR_RESOL,
    /// maximum device info parameter
    DEV_INFO_MAX,
};
/*************** GAP Structures ********************/

/// Device name
typedef struct 
{
    /// name length
    uint16_t length;
    /// name value
    uint8_t value[249];
} inb_dev_name_t;

///  Device version parameters  
typedef struct {
    /// HCI version
    uint8_t hci_ver;
    /// LMP version
    uint8_t lmp_ver;
    /// Host version
    uint8_t host_ver;
    /// HCI revision
    uint16_t hci_subver;
    /// LMP subversion
    uint16_t lmp_subver;
    /// Host revision
    uint16_t host_subver;
    /// Manufacturer name
    uint16_t manuf_name;
} inb_dev_verison_t;

/// Indication of peer version info
typedef struct 
{
    /// Manufacturer name
    uint16_t compid;
    /// LMP subversion
    uint16_t lmp_subvers;
    /// LMP version
    uint8_t  lmp_vers;
} inb_peer_version_ind_t;

/// Indication of peer features info
typedef struct 
{
	/// 8-byte array for LE features
	uint8_t features[BLE_FEATS_LEN];
} inb_peer_features_ind_t;

/// Suggested data len & time. 
typedef struct {
	/// suggested value for the Controller's maximum transmitted number of payload octets. 
    uint16_t suggted_max_tx_octets;		
	/// suggested value for the Controller's maximum packet transmission time. 
    uint16_t suggted_max_tx_time;		
} inb_sugg_dft_t;

/// Supported data len & time. */
typedef struct {
	/// Maximum number of payload octets that the local Controller supports for transmission. 
    uint16_t suppted_max_tx_octets;		
	/// Maximum time, in microseconds, that the local Controller supports for transmission. 
    uint16_t suppted_max_tx_time;		
	/// Maximum number of payload octets that the local Controller supports for reception.
    uint16_t suppted_max_rx_octets;		
	/// Maximum time, in microseconds, that the local Controller supports for reception. 
    uint16_t suppted_max_rx_time;		
} inb_supp_dft_t;

/// Transmit powers supported by the controller. 
typedef struct 
{
	/// Minimum TX power. 
    int8_t min_tx_pwr;		
	/// Maximum TX power. 
    int8_t max_tx_pwr;	
} inb_tx_pwr_t;


/// Slave preferred connection parameters
typedef struct 
{
    /// Connection interval minimum
    uint16_t con_intv_min;
    /// Connection interval maximum
    uint16_t con_intv_max;
    /// Slave latency
    uint16_t slave_latency;
    /// Connection supervision timeout multiplier
    uint16_t conn_timeout;
} inb_slv_pref_t;

/// BD Address structure
typedef struct
{
    ///6-byte array address value
    uint8_t  addr[BLE_BDADDR_LEN];
} inb_addr_t;

///Channel map structure
typedef struct
{
    ///5-byte channel map array
    uint8_t map[BLE_CHNL_MAP_LEN];
} inb_chnl_map_t;


///Random number structure
typedef struct 
{
    ///8-byte array for random number
    uint8_t     nb[BLE_RAND_NB_LEN];
} inb_rnd_nb_t;

/// P256 Public key data format
typedef struct
{
    /// X Coordinate of the key
    uint8_t x[BLE_P256_KEY_LEN];
    /// X Coordinate of the key
    uint8_t y[BLE_P256_KEY_LEN];
} inb_pub_key_t;

/// Address information about a device address
typedef struct 
{
    /// BD Address of device
    inb_addr_t addr;
    /// Address type of the device 0=public/1=private random
    uint8_t addr_type;
} inb_bdaddr_t;

/// Resolving list device information
typedef struct 
{
    /// Device identity
    inb_bdaddr_t addr;
    /// Privacy error filter, 0: privacy error reported,  1: privacy error not reported
    uint8_t priv_mode;
    /// Peer IRK
    uint8_t peer_irk[BLE_KEY_LEN];
    /// Local IRK
    uint8_t local_irk[BLE_KEY_LEN];
} inb_ral_dev_info_t;

/// Peroidic address list device information
typedef struct 
{
	/// advertiser address information 
    inb_bdaddr_t addr;	
	/// advertising SID 
    uint8_t adv_sid;	
} inb_pal_dev_info_t;

/// Generic Security key structure
typedef struct 
{
    /// Key value MSB -> LSB
    uint8_t key[BLE_KEY_LEN];
} inb_sec_key_t;

/// Long Term Key information
typedef struct 
{
    /// Long Term Key
    inb_sec_key_t ltk;
    /// Encryption Diversifier
    uint16_t ediv;
    /// Random Number
    inb_rnd_nb_t randnb;
    /// Encryption key size (7 to 16)
    uint8_t key_size;
} inb_ltk_t;

/// Identity Resolving Key information
typedef struct 
{
    /// Identity Resolving Key
    inb_sec_key_t irk;
    /// Device BD Identity Address
    inb_bdaddr_t addr;
} inb_irk_t;

/// Authentication information
typedef struct 
{
    /// Authentication information, @see enum inb_auth.
    uint8_t info;

    /// LTK exchanged during pairing.
    bool ltk_present;
} inb_bond_auth_t;

/// Out of band data 
typedef struct 
{
	/// Confirm Value
	uint8_t conf[BLE_KEY_LEN];	
	/// Random Number 
	uint8_t rand[BLE_KEY_LEN];	
} inb_oob_t;

/// Numeric comparison value */
typedef struct 
{
	/// Numberic value
    uint8_t value[4];
} inb_nc_t;

/// Pairing structure.
typedef struct 
{
	/// IO capabilities, @see enum inb_io_cap.
    uint8_t iocap;	
	/// OOB present, @see enum inb_oob.
    uint8_t oob;		
	/// Authentication, @see enum inb_auth.
    uint8_t auth;	
	/// Encryption key size (7 to 16).  
    uint8_t key_size;	
	/// Initiator key distribution, @see enum inb_kdist.
    uint8_t ikey_dist;	
	/// Responder key distribution, @see enum inb_kdist.
    uint8_t rkey_dist;	
	/// Device security requirements (minimum security level), @see enum inb_sec_req.	
    uint8_t sec_req;	
} inb_pairing_t;

/// Indicate the PHY used for transmission and reception 
typedef struct 
{
	/// PHY for transmission, @see enum inb_phy_value.
    uint8_t tx_phy;		
	/// PHY for reception, @see enum inb_phy_value.
    uint8_t rx_phy;		
} inb_phy_ind_t;


/// Test PHY structure
typedef struct {
	/// Test mode operation, @see inb_test_mode 
	int test_mode;					
	/// Tx or Rx Channel (Range 0x00 to 0x27) 
	uint8_t channel;				
	/// Length in bytes of payload data in each packet (only valid for TX mode, range 0x00-0xFF) 
	uint8_t tx_data_length;		
	/// Packet Payload type (only valid for TX mode), @see enum inb_pkt_pld_type
	uint8_t tx_pkt_payload;		
	/// Test PHY rate @see enum inb_test_phy
	uint8_t phy;						
	/// Modulation Index (only valid for RX mode),  @see enum inb_modulation_idx
	uint8_t modulation_idx;		
} inb_test_mode_t;

/// device configuration structure
typedef struct 
{
    /// Device Role: Central, Peripheral, Observer, Broadcaster or All roles @see enum inb_role 
    uint8_t role;

    /// -------------- Privacy Config -----------------------
    /// Duration before regenerate device address when privacy is enabled. - in seconds
    uint16_t renew_dur;

    /// Provided own static private random address
    inb_addr_t addr;

    /// Device IRK used for resolvable random BD address generation (LSB first)
    inb_sec_key_t irk;

    /// Privacy configuration bit field (@see enum inb_priv_cfg for bit signification)
    uint8_t privacy_cfg;

    /// -------------- Security Config -----------------------

    /// Pairing mode authorized (@see enum inb_pairing_mode)
    uint8_t pairing_mode;

    /// -------------- ATT Database Config -----------------------

    /// GAP service start handle
    uint16_t gap_start_hdl;

    /// GATT service start handle
    uint16_t gatt_start_hdl;

    /// Attribute database configuration 
	/// Device Name write permission @see inb_write_att_perm
	uint8_t att_devname_write_perm;		
	/// Device Appearance write permission @see inb_write_att_perm
	uint8_t att_apperance_write_perm;	
	/// Slave Preferred Connection Parameters present ( 1 = yes, 0 = no )	
	uint8_t att_slv_pref_conn_param_present;		
	/// Service change feature present in GATT attribute database ( 1 = yes, 0 = no )  				
	uint8_t svc_change_feat_present;	

    /// -------------- LE Data Length Extension -----------------------
    ///Suggested value for the Controller's maximum transmitted number of payload octets to be used ( min = 27, max = 251)
    uint16_t sugg_max_tx_octets;
    ///Suggested value for the Controller's maximum packet transmission time to be used (min = 328us, max = 17040us) 
    uint16_t sugg_max_tx_time;

    /// --------------- L2CAP Configuration ---------------------------
    /// Maximal MTU acceptable for device (min = 23, max = 2048)
    uint16_t max_mtu;
    /// Maximal MPS Packet size acceptable for device
    uint16_t max_mps;
    /// Maximum number of LE Credit based connection that can be established
    uint8_t  max_nb_lecb;

    /// ------------------ LE PHY Management  -------------------------
    /// Preferred LE PHY for data transmission @see enum inb_phy
    uint8_t tx_pref_phy;
    /// Preferred LE PHY for data reception @see enum inb_phy
    uint8_t rx_pref_phy;

} inb_set_dev_config_t;

/// local device info 
typedef union {
	/// device version
	inb_dev_verison_t version;
	/// device address
	inb_bdaddr_t bd_addr;
	/// adv TX power
	int8_t adv_tx_pwr;
	/// suggested default data len and time
	inb_sugg_dft_t sugg_dft;
	/// supported default data len and time
	inb_supp_dft_t supp_dft;	
	/// WLIST, RAL, PAL list size. 
	uint8_t list_size;
	/// number of adv sets
    uint8_t nb_adv_sets;
	/// maximum advertising data length supported by controller 
    uint16_t max_adv_len;		
	/// TX power
	inb_tx_pwr_t tx_pwr;
} inb_local_dev_info_t;

/// Resolve random Address.
typedef struct 
{
	/// address to be resolved.
	inb_addr_t addr;	
	/// number of provided IRK (sahlle be > 0). 
    uint8_t nb_key;		
	/// array of IRK used to resolved address (MSB -> LSB)
    inb_sec_key_t irk[];	
} inb_rnd_addr_resolve_t;

/// Resolved address.
typedef struct 
{
	/// address resolved.
	inb_addr_t addr;	
	/// IRK that correctly solved the random address
    inb_sec_key_t irk;										
} inb_rnd_addr_solved_t;

/// AES-128 encryption  
typedef struct 
{
	/// key data 
	uint8_t key[BLE_KEY_LEN];			
	/// plain text 
	uint8_t plain_text[BLE_KEY_LEN];	
} inb_aes_enc_t;

/// LE PSM paramters
typedef struct 
{
	/// LE Protocol/Service Multiplexer 
	uint16_t lepsm;		
	/// security level, 0=NO_AUTH, 1=UNAUTH, 2=AUTH, 3=SEC_CON 
	uint8_t sec_lvl;		
	/// encryption key size must have16 bytes 
	bool full_key_size;				
} inb_lepsm_param_t;

///  Get local or peer resolvable address  
typedef struct 
{
	/// local or peer resolvable address, 
	/// 		0 - local, 
	///		1 - peer
	int opcode;
	/// either the local identity or the peer identity
	inb_bdaddr_t identity_addr;
} inb_get_ral_addr_t;

///  Add white list parameters
typedef struct 
{
	/// number of entries to be added in the list. 0 means that list content has to be cleared
	uint8_t size;		
	/// entries to be added in the list 
	inb_bdaddr_t wl_info[];	
} inb_wl_param_t;

/// Add resolvable list parameters  
typedef struct 
{
	/// number of entries to be added in the list. 0 means that list content has to be cleared
    uint8_t size;		
	/// entries to be added in the list
    inb_ral_dev_info_t ral_info[];	
} inb_ral_param_t;

/// Add periodic address list parameters
typedef struct 
{
	/// number of entries to be added in the list. 0 means that list content has to be cleared 
    uint8_t size;		
	/// entries to be added in the list */
    inb_pal_dev_info_t pal_info[];		
} inb_pal_param_t;

/// Advertising configuration for primary channel structure.  
struct adv_prim_cfg
{
	/// Minimum advertising interval (in unit of 625us). Must be greater than 20ms.  
	uint32_t adv_intv_min;		
	/// Maximum advertising interval (in unit of 625us). Must be greater than 20ms.  
	uint32_t adv_intv_max;		
	/// Advertising channel mapping, @see enum inb_adv_chnl 
	uint8_t chnl_map;				
	/// Primary advertising PHY, @see enum inb_phy_value
	/// @note LE 2M PHY is not allowed and that legacy advertising only support LE 1M PHY
	uint8_t phy;						
};

/// Advertising configuration for secondary channel structure.  
struct adv_second_cfg
{
	/// Maximum number of advertising events the controller can skip before sending the
	/// AUX_ADV_IND packets. 0 means that AUX_ADV_IND PDUs shall be sent prior each advertising events. 
	uint8_t max_skip;	
	/// Secondary advertising PHY, @see enum inb_phy_value
	uint8_t phy;			
	/// Advertising SID. 
	uint8_t adv_sid;		
};

/// Advertising periodic configuration structure.
struct adv_period_cfg
{
	/// Minimum advertising interval (in unit of 1.25ms). Must be greater than 20ms. 
    uint16_t adv_intv_min;		
	/// Maximum advertising interval (in unit of 1.25ms). Must be greater than 20ms. 
    uint16_t adv_intv_max;		
};

/// Advertisement activity create structure
typedef struct 
{
	/// advertising type, @see enum inb_adv_type 
	uint8_t type;											
	/// advertising mode, @see enum  inb_adv_mode
	uint8_t disc_mode;								
	/// advertising properties, @see enum inb_adv_legacy_prop, @see enum inb_adv_ext_prop, @see enum inb_adv_per_prop 
	uint16_t prop;
	/// Maximum power level at which the advertising packets have to be transmitted (between -127 and 126 dBm). 										
	int8_t max_tx_pwr;									
	/// Advertising filtering policy, @see enum inb_adv_filt_pol
	uint8_t filter_pol;									
	/// Peer address configuration (only used in case of directed advertising).
	inb_bdaddr_t peer_addr;								
	/// Configuration for primary advertising 
	struct adv_prim_cfg prim_cfg;				
	/// Configuration for secondary advertising (valid only if advertising type is ADV_TYPE_EXTENDED or ADV_TYPE_PERIODIC). 
	struct adv_second_cfg second_cfg;		
	/// Configuration for periodic advertising (valid only if advertising type is ADV_TYPE_PERIODIC). 
	struct adv_period_cfg period_cfg;			
} adv_create_param_t;

/// Activity create structure.  
typedef struct 
{
	/// create activity option
	///		0:  advertising, 
	///		1: scan, 
	///		2: initiating, 
	///		3: periodic advertising
	int option;								
	/// address type; 
	///		0: static (public or private),
	///		1: generate resolvable private random address,
	///		2: generate non-resolvable private random address. 
	uint8_t own_addr_type;
	/// advertising parameters only for advertising option							
	adv_create_param_t adv_param;				
} inb_actv_create_t;

/// Advertisement start structure. 
typedef struct {
	/// Advertising duration (in unit of 10ms). 0 means that advertising continues until the host disable it. 
    uint16_t duration;		
	/// Maximum number of extended advertising events the controller shall attempt to send prior to
	/// terminating the extending advertising, Valid only if extended advertising. 
    uint8_t max_adv_evt;	
}  inb_adv_start_t;

/// Scan Window operation parameters. 
struct scan_wd_op_param
{
	/// Scan interval (in unit of 625us), time range 2.5ms to 10.24s. 
	uint16_t scan_intv;	
	/// Scan window (in unit of 625us), time range 2.5ms to 10.24s.  	
	uint16_t scan_wd;		
};

/// Scanning start structure.
typedef struct
{
	/// Scan type, @see enum inb_scan_type
    uint8_t type;	
	/// Scan properties, @see enum inb_scan_prop.
    uint8_t prop;	
	/// Duplicate packet filtering policy, @see enum inb_scan_dup_filt.
    uint8_t dup_filt_pol;	
	/// Scan window opening parameters for LE 1M PHY. 
    struct scan_wd_op_param scan_param_1m;	
	/// Scan window opening parameters for LE Coded PHY. 
    struct scan_wd_op_param scan_param_coded;	
	/// Scan duration (in unit of 10ms). 0 means that the controller will scan continuously until
	/// 	reception of a stop command from the application. 
    uint16_t duration;
	/// Scan period (in unit of 1.28s). Time interval betweem two consequent starts of a scan duration
	///	by the controller. 0 means that the scan procedure is not periodic. */	
    uint16_t period;	
}  inb_scan_start_t;

/// Connection parameters.  
struct conn_param
{
	/// Minimum value for the connection interval (in unit of 1.25ms). Shall be less than or equal to
	/// conn_intv_max value. Allowed range is 7.5ms to 4s. 
    uint16_t conn_intv_min;	
	/// Maximum value for the connection interval (in unit of 1.25ms). Shall be greater than or equal to
	/// conn_intv_min value. Allowed range is 7.5ms to 4s. 
    uint16_t conn_intv_max;	
	/// Slave latency. Number of events that can be missed by a connected slave device. 
    uint16_t conn_latency;	
	/// Link supervision timeout (in unit of 10ms). Allowed range is 100ms to 32s. 
    uint16_t supervision_to;
	/// Recommended minimum duration of connection events (in unit of 625us). 	
    uint16_t ce_len_min;	
	/// Recommended maximum duration of connection events (in unit of 625us). 
    uint16_t ce_len_max;	
};

/// Initiator start structure.
typedef struct 
{
	/// Initiator type, @see enum inb_initiator_type.
    uint8_t type;	
	/// Initiator proterties, @see enum inb_initiator_prop.
    uint8_t prop;	
	/// Timeout for automatic connection establishment (in unit of 10ms). Cancel the procedure if not all
	/// 	indicated devices have been connected when the timeout occurs. 0 means there is no timeout. 
    uint16_t conn_tmo;	
	/// Scan window opening parameters for LE 1M PHY. 
    struct scan_wd_op_param scan_param_1m;	
	/// Scan window opening parameters for LE Coded PHY. 
    struct scan_wd_op_param scan_param_coded;	
	/// Connection parameters for LE 1M PHY. 
    struct conn_param conn_param_1m;	
	/// Connection parameters for LE 2M PHY. 
    struct conn_param conn_param_2m;	
	/// Connection parameters for LE Coded PHY. 
    struct conn_param conn_param_coded;	
	/// Address of peer device in case white list is not used for connection. 
    inb_bdaddr_t peer_addr;	
} inb_init_start_t;

/// Periodic advertiser information.
struct period_adv_addr_cfg
{
	/// Advertiser address information. 
    inb_bdaddr_t addr;		
	/// Advertising SID.  
    uint8_t adv_sid;	
};

/// Periodic synchronization start structure.
typedef struct 
{
	/// Periodic synchronization type, @see enum inb_per_sync_type.
    uint8_t type;	
	/// Number of periodic advertising that can be skipped after a successful receive. Maximum authorized value is 499. 
    uint16_t skip;	
	/// Synchronization timeout for the periodic advertising (in unit of 10ms between 100ms and 163.84s). 
    uint16_t sync_tmo;	
	/// Address of advertiser with which synchronization has to be established (used only if use_pal is false).
    struct period_adv_addr_cfg adv_addr;	
} inb_per_sync_start_t;

/// Activity start structure.
typedef struct {
	/// start activity option
	///		0:  advertising, 
	///		1: scan, 
	///		2: initiating, 
	///		3: periodic advertising
	int option;								
	union {
		/// Advertising start parameters.	
		inb_adv_start_t adv_param;	
		/// Scan start parameters.	
		inb_scan_start_t scan_param;	
		/// Initiator start parameters.
		inb_init_start_t init_param;
		/// Periodic sync start parameters.
		inb_per_sync_start_t per_param;
	} u;
} inb_actv_start_t;

/// Connection request confirm structure.
typedef struct 
{
	/// Local CSRK value. 
	inb_sec_key_t lcsrk;	
	/// Local signature counter value. 
	uint32_t lsign_counter;	
	/// Remote CSRK value.
	inb_sec_key_t rcsrk;	
	/// Remote signature counter value.
	uint32_t rsign_counter;	
	/// Authentication,@see enum inb_auth.
	uint8_t auth;	
	/// Service Changed Indication enabled.
	uint8_t svc_changed_ind_enable;	
	/// LTK exchanged during pairing. 
	bool ltk_present;	
} inb_conn_cfm_t;

/// Connection get peer information structure.
typedef union {
	/// Device name, 
	inb_dev_name_t name;	
	/// Device apperance icon
	uint16_t apperance;
	/// Device slave prefered parameters
	inb_slv_pref_t slv_pref_params;		
	/// Device central support address resolution
	uint8_t ctl_addr_resol;
	/// Device version info.
	inb_peer_version_ind_t version;
	/// Device features.
	inb_peer_features_ind_t features;
	/// Connection rssi
	int8_t rssi;
	/// Connection channel map
	inb_chnl_map_t ch_map;
	/// authenticated payload timeout value N, value time = N*10ms
	uint16_t ping_timeout;		
	/// Currently used PHY
	inb_phy_ind_t phy;
	/// Currently used channel algorithm
    uint8_t chan_sel_algo;
} inb_conn_peer_info_t;

/// Connection parameters update structure.
typedef struct 
{
	/// Connection interval minimum N, value time = N * 1.25ms.
	uint16_t intv_min;		
	/// Connection interval maximum N, value time = N * 1.25ms.
	uint16_t intv_max;	
	/// Latency (number of events) 
	uint16_t latency;		
	/// Supervision timeout N, value time = N * 10ms 
	uint16_t time_out;	
	/// Minimum Connection Event Duration N, value time = N * 0.625ms.
	uint16_t ce_len_min;		
	/// Maximum Connection Event Duration N, value time = N * 0.625ms. 
	uint16_t ce_len_max;	
} inb_conn_param_update_t;

/// Connection encrypt request confirm structure. 
typedef struct 
{
	/// Indicate if a LTK has been found for the peer device.
	uint8_t found;	
	/// Long Term Key. 
	inb_sec_key_t ltk;	
	/// LTK Key Size.
	uint8_t key_size;	
} inb_conn_encrypt_cfm_t;


/// Connection bond confirm. 
typedef struct
{
    /// Bond request type, @see enum inb_bond
    uint8_t request;

    /// Request accepted, 
    uint8_t accept;

	union {
	    /// Pairing Features (request = PAIRING_RSP)
	    inb_pairing_t pairing_feat;		
	    /// LTK (request = LTK_EXCH)
	    inb_ltk_t ltk;									
	    /// CSRK (request = CSRK_EXCH)
	    inb_sec_key_t csrk;						
    	/// TK (request = TK_EXCH)
	    inb_sec_key_t tk;							
	    /// IRK (request = IRK_EXCH)
	    inb_irk_t irk;									
	    /// OOB Confirm and Random from the peer (request = OOB_EXCH)
	    inb_oob_t oob;								
	} u;
} inb_bond_cfm_t;

/// Connection set prefered PHY.
typedef struct 
{
	/// Prefered PHY for transmission, @see enum inb_phy.
	uint8_t tx_phy;		
	/// Prefered PHY for reception, @see enum inb_phy.
	uint8_t rx_phy;		
	/// Prefered coding scheme for CODED PHY options, @see enum inb_coded_phy_opt.
	uint8_t phy_opt;	
} inb_conn_pref_phy_t;

/// Set prefer TX data length. 
typedef struct 
{
	/// Preferred maximum number of payload octets that the local Controller should include
	/// in a single Link Layer Data Channel PDU. 
    uint16_t tx_octets;		
	/// Preferred maximum number of microseconds that the local Controller should use to transmit
	/// a single Link Layer Data Channel PDU.
    uint16_t tx_time;			
} inb_pref_le_pkt_size_t;

/// Controller max TX/RX size  
typedef struct 
{
    ///The maximum number of payload octets in TX
    uint16_t max_tx_octets;
    ///The maximum time that the local Controller will take to TX
    uint16_t max_tx_time;
    ///The maximum number of payload octets in RX
    uint16_t max_rx_octets;
    ///The maximum time that the local Controller will take to RX
    uint16_t max_rx_time;
} inb_le_pkt_size_t;

typedef struct {
	/// Security Level, @see enum inb_att_svc_perm_mask
    uint8_t  sec_lvl;
    /// Service start handle
    /// 0: dynamically allocated in Attribute database
    uint16_t start_hdl;
    /// 32 bits value that contains value to initialize profile (database parameters, etc...)
    uint32_t param[];
} inb_add_prf_t;


/// Send requested info to peer device
/*@TRACE*/
typedef struct {
	/// Requested information
    /// - GAPC_DEV_NAME: Device Name
    /// - GAPC_DEV_APPEARANCE: Device Appearance Icon
    /// - GAPC_DEV_SLV_PREF_PARAMS: Device Slave preferred parameters
    uint8_t req;
	/// Peer device information data
	union {
		   	/// Device name
		    //@trc_union parent.req == GAPC_DEV_NAME
		    inb_dev_name_t name;
		    /// Appearance Icon
		    //@trc_union parent.req == GAPC_DEV_APPEARANCE
		    uint16_t appearance;
		    /// Slave preferred parameters
		    //@trc_union parent.req == GAPC_DEV_SLV_PREF_PARAMS
		     inb_slv_pref_t slv_pref_params;
		    /// Central address resolution
		    //@trc_union parent.req == GAPC_DEV_CTL_ADDR_RESOL
		    uint8_t ctl_addr_resol;					
		} u;
}
inb_get_dev_info_cfm_t;





typedef struct{
	 /// Requested information
    /// - GAPC_DEV_NAME: Device Name
    /// - GAPC_DEV_APPEARANCE: Device Appearance Icon
    uint8_t req;

    /// GAP Specific Error of inb_error
	uint8_t status;
}
inb_set_dev_info_cfm_t;




/*
 ****************************************************************************************
 * functions
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Reset BLE stack
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_reset(void);

/**
 ****************************************************************************************
 * @brief Test BLE phy TX and RX
 *
 * @param[in] p_test				Pointer to the test mode structure. 
 * @param[out] nb_rx_packet	Pointer to the nb of packets receive for RX test operation
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_test(inb_test_mode_t *p_test, uint16_t *nb_rx_packet);


/**
 ****************************************************************************************
 * @brief Set device configuration
 *
 * @param[in] p_cfg					Pointer to the device configurtion structure.
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_set_dev_config(inb_set_dev_config_t *p_cfg);

/**
 ****************************************************************************************
 * @brief Get local device informations
 *
 * @param[in] cmd					Command for information, @see enum ble_get_dev_info_cmd
 * @param[out] p_info				Pointer to a union for different info, 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_get_dev_info(int cmd, inb_local_dev_info_t *p_info);

/**
 ****************************************************************************************
 * @brief Set channel map
 * @note This function is only for central device
 *
 * @param[in] p_chn_map			Pointer to the channel map array. 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_set_chn_map(inb_chnl_map_t *p_chn_map);

/**
 ****************************************************************************************
 * @brief Resolve provided random address by usng array of IRK
 *
 * @param[in] p_rnd_addr			Pointer to the random address and possible keys, 
 * @param[out] p_addr				Pointer to the resolved random address and keys, 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_resolve_addr(inb_rnd_addr_resolve_t *p_rnd_addr, inb_rnd_addr_solved_t *p_addr);

/**
 ****************************************************************************************
 * @brief Generate random address
 *
 * @param[in] rnd_addr_type		random address type, @see enum ble_rnd_addr_type  
 * @param[out] p_rnd_addr		Pointer to the generated random address, 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_gen_random_addr(int rnd_addr_type, inb_bdaddr_t *p_rnd_addr);

/**
 ****************************************************************************************
 * @brief AES-128 calculation
 *
 * @param[in] p_enc					Pointer to the key and plain text structure.   
 * @param[out] p_enc_res		16 bytes array of calculated result, 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_aes_enc(inb_aes_enc_t *p_enc, uint8_t *p_enc_res);

/**
 ****************************************************************************************
 * @brief Generate a 8 bytes random number
 *
 * @param[out] p_rnd_nb			8 bytes array of calculated result, 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_gen_random_nb(inb_rnd_nb_t *p_rnd_nb);

/**
 ****************************************************************************************
 * @brief Change the current IRK for a renewed one
 * @note This can only be called during no air operation.
 *
 * @param[out] p_irk				Pointer to a security key data structure, 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_set_irk(inb_sec_key_t *p_irk);

/**
 ****************************************************************************************
 * @brief Register a LE Protocol/Service Multiplexer identified.
 * @note This has to be registered before LE Credit Based Connection established.
 *
 * @param[in] p_psm					Pointer to a LEPSM data structure, 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_register_lepsm(inb_lepsm_param_t *p_psm);

/**
 ****************************************************************************************
 * @brief Un-register a LE Protocol/Service Multiplexer identified.
 *
 * @param[in] psm					LE Protoca/Service Multiplexer (16 bits), 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_unregister_lepsm(uint32_t psm);

/**
 ****************************************************************************************
 * @brief Get local or peer resolvable private address.
 *
 * @param[in] p_ral_addr			Pointer to peer device identity,
 * @param[out] p_addrr			Pointer to the last resolvable private address,
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_get_ral_addr(inb_get_ral_addr_t *p_ral_addr, inb_bdaddr_t *p_addr);

/**
 ****************************************************************************************
 * @brief Set the white list content.
 * @note This will overwrite the current white list.
 *
 * @param[in] p_wlist				Pointer to white list data structure,
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_set_white_list(inb_wl_param_t *p_wlist);

/**
 ****************************************************************************************
 * @brief Set the resolving list content.
 * @note This will overwrite the current resolving list.
 *
 * @param[in] p_ral					Pointer to resolving list data structure,
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_set_ral_list(inb_ral_param_t *p_ral);

/**
 ****************************************************************************************
 * @brief Set the peroidic advertiser list content.
 * @note This will overwrite the current periodic advertiser list.
 *
 * @param[in] p_pal					Pointer to periodic advertiser list data structure,
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_set_pal_list(inb_pal_param_t *p_pal);

/**
 ****************************************************************************************
 * @brief Create an advertising, a scanning, an initiating or a periodic synchronization activity
 *
 * @param[in] p_act					Pointer to activity create structure,
 * @param[out] p_actv_idx		Pointer to return activity index,
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_actv_create(inb_actv_create_t *p_act, int *p_actv_idx);

/**
 ****************************************************************************************
 * @brief Start an advertising, a scanning, an initiating or a periodic synchronization activity
 * @note 
 * 	1.  Several advertising can be started in parallel,
 *		2.  Can't start multiple scaning and initiating activities.
 *		3.  Periodic synchronization activity must be started in parallel with a scanning activity,
 *		4.  Activity must be created and started for devices not in the Periodic Advertiser list 
 *
 * @param[in] actv_idx				Activity index return from "Create" call,
 * @param[in] p_start				Pointer to start activity data strucutre,
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_actv_start(int actv_idx, inb_actv_start_t *p_start);

/**
 ****************************************************************************************
 * @brief Set an advertising, a periodic advertising, or a scan response data.
 * @note 
 * 	1.  AD type flag must not be part of data. It will generate by stack
 *		2.  Must be set before activity starts.
 *		3.  Can be used even if the activity already starts.
 *
 * @param[in] actv_idx				Activity index return from "Create" call,
 * @param[in] option				Data options:
 *													0 - advertising data,
 *													1 - scan response data,
 *													2 - periodic advertising data
 * @param[in] data					Pointer to the data,
 * @param[in] data_len				data length.
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_actv_data(int actv_idx, int option, uint8_t *data, uint32_t data_len);

/**
 ****************************************************************************************
 * @brief Stop an activity or all activities
 *
 * @param[in] actv_idx				Activity index return from "Create" call, If 0, stop all activities 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_actv_stop(int actv_idx);

/**
 ****************************************************************************************
 * @brief Delete an activity or all activities
 *
 * @param[in] actv_idx				Activity index return from "Create" call, If 0, delete all activities 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_actv_del(int actv_idx);

/**
 ****************************************************************************************
 * @brief Confirm connection request
 * @note: This is to response to the event "GAP_EVT_CONN_REQ".  Application can call this API in the call back.
 *
 * @param[in] conidxx				Connection index.
 * @param[in] p_cfm					Pointer to the confirm data structure.
 * 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_conn_cfm(int conidx, inb_conn_cfm_t *p_cfm);

/**
 ****************************************************************************************
 * @brief Disconnect a link
 * @note: Either master or slave can call this function.
 *
 * @param[in] conidxx				Connection index.
 * @param[in] reason				Reason of disconnection, @see enum ble_disc_reason.
 * 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_conn_disconnect(int conidx, uint32_t reason);

/**
 ****************************************************************************************
 * @brief Retrieve connection information
 *
 * @param[in] conidx				Connection index  
 * @param[in] option				Options for connection information:
 *													0 - Peer Name,
 *													1 - Peer Version, 
 *													2 - Peer Features, 
 *													3 - Connection RSSI, 
 *													4 - Connection Channel Map, 
 *													5 - Peer Apperance, 
 *													6 - Peer Slaved Prefered Paramters, 
 *													7 - Address Resolution Supported (Central Only), 
 *													8 - LE Ping Time Out Value, 
 *													9 - Connection PHY, 
 *													10 - Connection Channel Selected algorithm, 
 * @param[out] p_peer_info		Pointer to union for different info.  
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_conn_get_peer_info(int conidx, int option, inb_conn_peer_info_t *p_peer_info);

/**
 ****************************************************************************************
 * @brief Update connection paramters
 * @note: Can be used by both master and slave,
 *
 * @param[in] conidx				Connection index  
 * @param[in] p_upd					Pointer to update parameters structure.
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_conn_param_update(int conidx, inb_conn_param_update_t *p_upd);

/**
 ****************************************************************************************
 * @brief Confirm updated paramters
 * @note: This is only for master to accept or reject the new parameters proposed by slave,
 *
 * @param[in] conidx				Connection index  
 * @param[in] accept				true: accept slave's connection parameters; false: otherwise.
 * @param[in] ce_len_min			Connection event minimum time N, value time = N * 0.625.
 * @param[in] ce_len_max			Connection event maximum time N, value time = N * 0.625.
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_conn_param_update_cfm(int conidx, bool accept, uint32_t ce_len_min, uint32_t ce_len_max);

/**
 ****************************************************************************************
 * @brief Initiate encryption procedure
 * @note: This is only for master and have previous LTK,
 *
 * @param[in] conidx				Connection index  
 * @param[in] p_ltk					Pointer to LTK data structure.
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_conn_req_encrypt(int conidx, inb_ltk_t *p_ltk);

/**
 ****************************************************************************************
 * @brief Confirm master's encryption request
 *
 * @param[in] conidx				Connection index  
 * @param[in] p_cfm					Pointer to LTK confirm data structure.
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_conn_req_encrypt_cfm(int conidx, inb_conn_encrypt_cfm_t *p_cfm);

/**
 ****************************************************************************************
 * @brief Initiate security request procedure
 * @note This is used only by slave to initiate a security handshake.
 *
 * @param[in] conidx				Connection index  
 * @param[in] auth					Authentication level requested, @see enum ble_auth.
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_conn_req_security(int conidx, int auth);

/**
 ****************************************************************************************
 * @brief Set LE ping time out value
 *
 * @param[in] conidx				Connection index  
 * @param[in] timeout				Authenticated payload time out value N, value time = N * 10ms.
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_conn_set_ping_tmo(int conidx, uint32_t timeout);

/**
 ****************************************************************************************
 * @brief Change current LE packet size
 *
 * @param[in] conidx				Connection index  
 * @param[in] p_pref_pkt_size	Pointer to prefered packet size data structure.
 * @param[out] p_pkt_size		Pointer to controller final packet size data structure.
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_conn_set_pkt_size(uint8_t conidx, inb_pref_le_pkt_size_t *p_pref_pkt_size, inb_le_pkt_size_t *p_pkt_size);

/**
 ****************************************************************************************
 * @brief Initiate bond
 * @note This can only issue by master.
 *
 * @param[in] conidx				Connection index  
 * @param[in] p_bond				Pointer to pairing requirement of initiator.
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_conn_bond(int conidx, inb_pairing_t *p_bond);

/**
 ****************************************************************************************
 * @brief Confirm bond request
 * @note This is to respond to event "GAP_EVT_BOND_REQ".
 *
 * @param[in] conidx				Connection index  
 * @param[in] p_cfm					Pointer to bond confirm data structure.
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_conn_bond_cfm(int conidx, inb_bond_cfm_t *p_cfm);

/**
 ****************************************************************************************
 * @brief Set prefered PHY
 *
 * @param[in] conidx				Connection index  
 * @param[in] p_phy					Pointer to prefered PHY data structure.
 * @param[out] p_phy_ind			Pointer to final PHY data structure.
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_conn_set_pref_phy(int conidx, inb_conn_pref_phy_t *p_phy, inb_phy_ind_t *p_phy_ind);

/**
 ****************************************************************************************
 * @brief Send a keypress to peer
 *
 * @param[in] conidx				Connection index  
 * @param[in] key_state			Key state, @see enum ble_keypress_state.
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_conn_keypress_notify(int conidx, int key_state);

/**
 ****************************************************************************************
 * @brief Send requested info to peer device
 *
 * @param[in] conidx				Connection index  
 * @param[in] p_cfm	       req, @see struct  inb_get_dev_info_cfm_t.
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_conn_get_dev_info_cfm(int conidx,  inb_get_dev_info_cfm_t *p_cfm);


int inb_conn_set_dev_info_cfm(int conidx, inb_set_dev_info_cfm_t *p_cfm);
/// @} INB_GAP

#endif	/* INB_GAP_H */

