/**
 ****************************************************************************************
 *
 * @file inb_l2cc_event.h
 *
 * @brief BLE L2CAP events
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef L2CC_EVT_H
#define L2CC_EVT_H

#include ".\ble\inb_evt.h"

/**
 ****************************************************************************************
 * @addgroup INB_L2CC BLE L2CAP events  
 * @ingroup BLE
 * @brief  BLE L2CAP events
 * @{
 ****************************************************************************************
 */

/*
 * Enumerations
 ****************************************************************************************
 */
/// Events defines for L2CAP
enum inb_l2cap_evt{
	/// Peer requests a LECB connection	
	L2CAP_EVT_LECB_CONN_REQ = L2CAP_EVT_CODE +1,

	/// LECB connected event
	L2CAP_EVT_LECB_CONN_IND,

	/// LECB terminated event	
	L2CAP_EVT_LECB_DISCONNECT,

	/// LECB receive SDU event 	
	L2CAP_EVT_LECB_SDU_RECV,

};

/*
 * Structures
 ****************************************************************************************
 */

/// LE credit based connection request indication
typedef struct 
{
	/// Connection index
	uint8_t conidx;
    /// LE Protocol/Service Multiplexer
    uint16_t le_psm;
    /// Peer Channel identifier
    uint16_t peer_cid;
    /// Maximum SDU size
    uint16_t peer_mtu;
    /// Maximum Packet size
    uint16_t peer_mps;
} inb_evt_lecb_connect_req_t;


/// LE credit based connection indication
typedef struct 
{
	/// Connection index
	uint8_t conidx;
	/// Connected parameters
	inb_lecb_connect_ind_t lecb_conn_ind;

} inb_evt_lecb_connect_ind_t;

/// LE credit based disconnect indication
typedef struct 
{
	/// Connection index
	uint8_t conidx;
    /// Local Channel identifier
    uint16_t local_cid;
    /// Reason
    uint8_t reason;
} inb_evt_lecb_disconnect_ind_t;

/// Default L2Cap SDU definition
typedef struct 
{
    /// Channel Identifier
    uint16_t cid;
    /// Number of credit used
    uint16_t credit;
    /// SDU Data length
    uint16_t length;
    /// data
    uint8_t data[];
} sdu_t;

/// Inform that a data packet has been received from a LE Credit Based connection.
typedef struct 
{
	/// Connection index
	uint8_t conidx;
    /// Status information
    uint8_t status;
    /// SDU information
    sdu_t sdu;
} inb_evt_lecb_sdu_recv_ind_t;


/// @} INB_L2CC

#endif
