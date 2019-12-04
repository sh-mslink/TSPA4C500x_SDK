/**
 ****************************************************************************************
 *
 * @file inb_gap_evt.h
 *
 * @brief BLE GAP events
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef INB_GAP_EVENT_H
#define INB_GAP_EVENT_H

#include ".\ble\inb_evt.h"

/**
 ****************************************************************************************
 * @addgroup INB_EVT BLE GAP events  
 * @ingroup BLE
 * @brief  BLE GAP stack events
 * @{
 ****************************************************************************************
 */

/*
 * Enumerations
 ****************************************************************************************
 */

/// Events defines for GAP
enum inb_gap_evt{
	
	/// Peer device name indication.  For name discovery initaing type. @see inb_evt_peer_name_ind_t
	GAP_EVT_PEER_NAME_IND = 	GAP_EVT_CODE + 1,

	/// Controller synchronize with a periodic advertising, @see inb_evt_sync_established_ind_t
	GAP_EVT_SYNC_ESTABLISHED,

	/// Receive Scan request information, @see inb_evt_rx_scan_req_t
	GAP_EVT_RX_SCAN_REQ,

	/// Advertising report indication, @see inb_evt_adv_rpt_ind_t
	GAP_EVT_ADV_REPORT,

	/// Activity stop indication, @see inb_evt_act_stop_ind_t
	GAP_EVT_ACTIVITY_STOP,

	/// Random address being used information, @see inb_evt_rnd_addr_ind_t
	GAP_EVT_DEV_RND_ADDR_INFO,

	/// Key press by peer indication, @see inb_evt_keypress_ind_t
	GAP_EVT_KEYPRESS_IND,

	/// Local device info request by peer, @see inb_evt_get_dev_info_req_t
	GAP_EVT_GET_DEV_INFO_REQ,

	/// Local device info set by peer, @see inb_evt_set_dev_info_req_t
	GAP_EVT_SET_DEV_INFO_REQ,

	/// Disconnect by peer, @see inb_evt_disc_ind_t
	GAP_EVT_DISCONNECT,

	/// Connection establish request, @see inb_evt_conn_req_t
	GAP_EVT_CONN_REQ,

	/// LE ping timeout indication, @see inb_evt_ping_to_ind_t
	GAP_EVT_PING_TO_IND,		

	/// Current signed counter, @see inb_evt_sign_counter_ind_t
	GAP_EVT_SIGNED_COUNTER_UPD,

	/// Security indicator (Master only), @see inb_evt_security_ind_t
	GAP_EVT_SECURITY_IND,

	/// Encrypt request from peer, @see inb_evt_encrypt_req_ind_t
	GAP_EVT_ENCRYPT_REQ,

	/// Encrypt updated indication, @see inb_evt_encrypt_ind_t  
	GAP_EVT_ENCRYPT_IND,

	/// Bond request by peer, @see inb_evt_bond_req_ind_t 
	GAP_EVT_BOND_REQ,

	/// Bonding unpdated indication, @see inb_evt_bond_ind_t
	GAP_EVT_BOND_IND,

	/// Peer request to update connection paramters, @see inb_evt_conn_param_upd_req_t
	GAP_EVT_CONN_PARAM_UPD_REQ,

	/// Connection parameters updated, @see inb_evt_conn_param_upd_t 
	GAP_EVT_CONN_PARAM_UPD,

	/// PHY updated by peer, @see inb_evt_phy_upd_t
	GAP_EVT_CONN_PHY_UPD,

	/// LE packet size indication, @see inb_evt_le_pkt_size_t
	GAP_EVT_LE_PKT_SIZE_IND,
 };

/// Name of peer device indication
typedef struct 
{
    /// peer device bd address
    inb_addr_t addr;
    /// peer device address type
    uint8_t addr_type;
    /// peer device name length
    uint8_t name_len;
    /// peer device name
    uint8_t name[249];
} inb_evt_peer_name_ind_t;

/// Indicate that synchronization has been established with a periodic advertiser
typedef struct 
{
    /// Activity identifier
    uint8_t actv_idx;
    /// PHY on which synchronization has been established, @see enum inb_phy_value
    uint8_t phy;
    /// Periodic advertising interval (in unit of 1.25ms, min is 7.5ms)
    uint16_t intv;
    /// Advertising SID
    uint8_t adv_sid;
    /// Advertiser clock accuracy, @see enum inb_clk_acc
    uint8_t clk_acc;
    /// Advertiser address
    inb_bdaddr_t addr;
} inb_evt_sync_established_ind_t;


/// Received Scan request information.
typedef struct 
{
    /// Activity identifier
    uint8_t actv_idx;

    /// Transmitter device address
    inb_bdaddr_t trans_addr;

} inb_evt_rx_scan_req_t;

/// Advertising report indication.
typedef struct 
{
    /// Activity identifier
    uint8_t actv_idx;

    /// Bit field providing information about the received report, @see enum inb_adv_report_info)
    uint8_t info;

    /// Transmitter device address
    inb_bdaddr_t trans_addr;

    /// Target address (in case of a directed advertising report)
    inb_bdaddr_t target_addr;

    /// TX power (in dBm)
    int8_t tx_pwr;

    /// RSSI (between -127 and +20 dBm)
    int8_t rssi;

#ifdef RPT_ADV_CHN
	/// Advertising channel number	
	int8_t adv_chn;
#endif

    /// Primary PHY on which advertising report has been received, @see enum inb_phy
    uint8_t phy_prim;

    /// Secondary PHY on which advertising report has been received, @see enum inb_phy
    uint8_t phy_second;

    /// Advertising SID
    /// Valid only for periodic advertising report
    uint8_t adv_sid;

    /// Periodic advertising interval (in unit of 1.25ms, min is 7.5ms)
    /// Valid only for periodic advertising report
    uint16_t period_adv_intv;

    /// Report length
    uint16_t length;

    /// Report
    uint8_t data[];
} inb_evt_adv_rpt_ind_t;


/// Activity stop indication.
typedef struct 
{
    /// Activity identifier
    uint8_t actv_idx;

    /// Activity type, @see enum inb_actv_type)
    uint8_t actv_type;

    /// Activity stop reason, @see enum inb_error
    uint8_t reason;

    /// In case of periodic advertising, indicate if periodic advertising has been stopped
    uint8_t per_adv_stop;

} inb_evt_act_stop_ind_t;


/// Random address indication.
typedef struct 
{
    /// Local device address information
    inb_bdaddr_t addr;

    /// Activity index
    uint8_t actv_idx;

} inb_evt_rnd_addr_ind_t;


/// Peer keypress indication.
typedef struct 
{
	/// Connection index
	uint8_t conidx;

    /// notification type, @see enum inb_keypress_state
    uint8_t notification_type;

} inb_evt_keypress_ind_t;


/// Peer request local device information.
typedef struct 
{
	/// Connection index
	uint8_t conidx;

	/// Requested information
	/// - 0: Device Name
	/// - 1; Appearance Icon
	/// - 2: Device Slave preferred parameters
	uint8_t req;

} inb_evt_get_dev_info_req_t;


/// device information data
typedef union 
{
    /// Device name
    inb_dev_name_t name;
    /// Appearance Icon
    uint16_t appearance;
} set_dev_info_t;

/// Peer device request to modify local device info such as name or appearance
typedef struct 
{
	/// Connection index
	uint8_t conidx;

    /// Requested information
    /// 		- 0: Device Name
    /// 		- 1: Device Appearance Icon
    uint8_t req;

    /// device information data
    set_dev_info_t info;
} inb_evt_set_dev_info_req_t;


/// Disconnect by peer indication message.
typedef struct 
{
	/// Connection index
	uint8_t conidx;

    /// Reason of disconnection
    uint8_t reason;

} inb_evt_disc_ind_t;


/// Connection establish request message.
typedef struct 
{
	/// Connection index
	uint8_t conidx;

    /// Connection handle
    uint16_t conhdl;

    /// Connection interval
    uint16_t con_interval;

    /// Connection latency
    uint16_t con_latency;

    /// Link supervision timeout
    uint16_t sup_to;

    /// Clock accuracy
    uint8_t clk_accuracy;

    /// Peer address type
    uint8_t peer_addr_type;

    /// Peer BT address
    inb_addr_t peer_addr;

} inb_evt_conn_req_t;


/// Ping timeout update indication.
typedef struct 
{
	/// Connection index
	uint8_t conidx;

} inb_evt_ping_to_ind_t;


/// Signed counter update indication.
typedef struct 
{
	/// Connection index
	uint8_t conidx;

    /// Local SignCounter value
    uint32_t local_sign_counter;

    /// Peer SignCounter value
    uint32_t peer_sign_counter;

} inb_evt_sign_counter_ind_t;


/// Security indication message.
typedef struct 
{
	/// Connection index
	uint8_t conidx;

    /// Authentication level, @see inb_auth.
    uint8_t auth;

} inb_evt_security_ind_t;


/// Encrypt request indication message.
typedef struct 
{
	/// Connection index
	uint8_t conidx;

    /// Encryption Diversifier
    uint16_t ediv;

    /// Random Number
    inb_rnd_nb_t rand_nb;

} inb_evt_encrypt_req_ind_t;

/// Encrypt indication message.
typedef struct 
{
	/// Connection index
	uint8_t conidx;

    /// Authentication  level, @see inb_auth
    uint8_t auth;

} inb_evt_encrypt_ind_t;


/// Bond procedure requested information data
union inb_bond_req_data
{
    /// Authentication level, @see inb_auth (if request = PAIRING_REQ)
    uint8_t auth_req;
    /// LTK Key Size (if request = LTK_EXCH)
    uint8_t key_size;
    /// Device IO used to get TK, @see inb_tk_type: (if request = TK_EXCH)
    ///  - TK_OOB:       TK get from out of band method
    ///  - TK_DISPLAY:   TK generated and shall be displayed by local device
    ///  - TK_KEY_ENTRY: TK shall be entered by user using device keyboard
    uint8_t tk_type;

    /// Addition OOB Data for the OOB Conf and Rand values
    inb_oob_t  oob_data;

    /// Numeric Comparison Data
    inb_nc_t   nc_data;
};

/// Bonding requested by peer device indication message.
typedef struct 
{
	/// Connection index
	uint8_t conidx;

    /// Bond request type, @see enum inb_bond)
    uint8_t request;

    /// Bond procedure requested information data
    union inb_bond_req_data data;
} inb_evt_bond_req_ind_t;

/// Bond procedure information data
union inb_bond_data
{
    /// Authentication information (@see inb_auth)
    /// (if info = PAIRING_SUCCEED)
    inb_bond_auth_t auth;
    /// Pairing failed reason  (if info = PAIRING_FAILED)
    uint8_t reason;
    /// Long Term Key information (if info = LTK_EXCH)
    inb_ltk_t ltk;
    /// Identity Resolving Key information (if info = IRK_EXCH)
    inb_irk_t irk;
    /// Connection Signature Resolving Key information (if info = CSRK_EXCH)
    inb_sec_key_t csrk;
};

/// Event GAP_EVT_BOND_IND params
typedef struct 
{
	/// Connection index
	uint8_t conidx;

    /// Bond information type, @see enum inb_bond
    uint8_t info;

    /// Bond procedure information data
    union inb_bond_data data;

} inb_evt_bond_ind_t;


/// Event GAP_EVT_CONN_PARAM_UPD_REQ params
typedef struct 
{
	/// Connection index
	uint8_t conidx;
    /// Connection interval minimum
    uint16_t intv_min;
    /// Connection interval maximum
    uint16_t intv_max;
    /// Latency
    uint16_t latency;
    /// Supervision timeout
    uint16_t time_out;
} inb_evt_conn_param_upd_req_t;


/// Event GAP_EVT_CONN_PARAM_UPD params
typedef struct
{
	/// Connection index
	uint8_t conidx;
    ///Connection interval value
    uint16_t            con_interval;
    ///Connection latency value
    uint16_t            con_latency;
    ///Supervision timeout
    uint16_t            sup_to;
} inb_evt_conn_param_upd_t;

/// Event GAP_EVT_CONN_PHY_UPD params  
typedef struct
{
	/// Connection index
	uint8_t conidx;
	/// Updated PHY
	inb_phy_ind_t phy;
} inb_evt_phy_upd_t;

/// Event GAP_EVT_LE_PKT_SIZE_IND params  
typedef struct
{
	/// Connection index
	uint8_t conidx;
    ///The maximum number of payload octets in TX
    uint16_t max_tx_octets;
    ///The maximum time that the local Controller will take to TX
    uint16_t max_tx_time;
    ///The maximum number of payload octets in RX
    uint16_t max_rx_octets;
    ///The maximum time that the local Controller will take to RX
    uint16_t max_rx_time;
} inb_evt_le_pkt_size_t;

/// @} INB_EVT

#endif	/* INB_GAP_EVENT_H */

