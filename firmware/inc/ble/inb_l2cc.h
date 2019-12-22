/**
 ****************************************************************************************
 *
 * @file inb_l2cc.h
 *
 * @brief BLE L2CAP 
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef INB_L2CC_H
#define INB_L2CC_H

/**
 ****************************************************************************************
 * @defgroup INB_L2CC BLE L2CAP  
 * @ingroup BLE
 * @brief  BLE L2CAP
 * @{
 ****************************************************************************************
 */

#include <stdint.h>

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

/*
 * Structures
 ****************************************************************************************
 */

/// LE credit based connection request
typedef struct 
{
    /// parameter used for internal usage
    uint8_t  pkt_id;
    /// LE Protocol/Service Multiplexer
    uint16_t le_psm;
    /// Local Channel identifier (0: automatically allocate a free channel)
    uint16_t local_cid;
    /// Credit allocated for the LE Credit Based Connection
    /// Shall be at least: floor(((SDU + 2) + (MPS - 1)) / MPS) + 1
    /// To be sure that 1 SDU can be fully received without requesting credits to application
    uint16_t local_credit;
    /// Maximum SDU size - Shall not exceed device MTU
    uint16_t local_mtu;
    /// Maximum Packet size - Shall not exceed device MPS
    uint16_t local_mps;
} inb_lecb_connect_t;

/// LE credit based connection indication
typedef struct 
{
    /// Status
    uint8_t  status;
    /// LE Protocol/Service Multiplexer
    uint16_t le_psm;
    /// Local Channel identifier
    uint16_t local_cid;
    ///  Destination Credit for the LE Credit Based Connection
    uint16_t peer_credit;
    /// Maximum SDU size
    uint16_t peer_mtu;
    /// Maximum Packet size
    uint16_t peer_mps;
} inb_lecb_connect_ind_t;

/// LE credit based connection request confirmation
typedef struct 
{
    /// Peer Channel identifier
    uint16_t peer_cid;
    /// True to accept the incoming connection, False else
    bool accept;
    /// Local Channel identifier (0: automatically allocate a free channel)
    uint16_t local_cid;
    /// Credit allocated for the LE Credit Based Connection
    /// Shall be at least: floor(((SDU + 2) + (MPS - 1)) / MPS) + 1
    /// To be sure that 1 SDU can be fully received without requesting credits to application
    uint16_t local_credit;
    /// Maximum SDU size - Shall not exceed device MTU
    uint16_t local_mtu;
    /// Maximum Packet size - Shall not exceed device MPS
    uint16_t local_mps;
} inb_lecb_connect_cfm_t;


/*
 * APIs
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief LE credit based connection request 
 *	
 * @param[in] conidx				Connection index
 * @param[in] p_conx				Pointer to connect request structure
 * @param[out] p_ind				Pointer to connect indicator
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_lecb_connect(int conidx, inb_lecb_connect_t *p_conx, inb_lecb_connect_ind_t *p_ind);

/**
 ****************************************************************************************
 * @brief LE credit based connection request confirmation
 *	
 * @param[in] conidx				Connection index
 * @param[in] p_cfm					Pointer to confirm structure
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_lecb_connect_req_cfm(uint8_t conidx, inb_lecb_connect_cfm_t *p_cfm);

/**
 ****************************************************************************************
 * @brief LE credit based disconnect request
 *	
 * @param[in] conidx				Connection index
 * @param[in] local_cid				Local channel ID
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_lecb_disconnect(int conidx, int local_cid);

/**
 ****************************************************************************************
 * @brief LE credit based credit addition
 *	
 * @param[in] conidx				Connection index
 * @param[in] local_cid				Local channel ID
 * @param[in[ credit				Credit to add
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_lecb_add_credit(int conidx, int local_cid, int credit);

/**
 ****************************************************************************************
 * @brief LE Send data over an LE Credit Based Connection
 *	
 * @param[in] conidx				Connection index
 * @param[in] local_cid				Local channel ID
 * @param[in] data					Send data
 * @param[in] data_length		Send data length
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_lecb_sdu_send(int conidx, int local_cid, uint8_t *data, int data_length);


/// @} INB_L2CC

#endif	/* INB_GAP_H */

