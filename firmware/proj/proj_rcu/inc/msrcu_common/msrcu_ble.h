/**
 ****************************************************************************************
 *
 * @file msrcu_ble.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
#ifndef MSRCU_BLE_H
#define MSRCU_BLE_H

/* Include Files
 ****************************************************************************************
 */
#include <stdint.h>

/* Macro Definition
 ****************************************************************************************
 */
#define BLE_ADDR_LEN        (6)
#define BLE_KEY_LEN         (16)
#define BLE_RANDOM_NB_LEN   (8)

/* Enum Definition
 ****************************************************************************************
 */
typedef enum
{
    BLE_ERROR_NO_ERROR                        = 0x00,
    
    BLE_ERROR_UNKNOWN_HCI_COMMAND             = 0x01,
    BLE_ERROR_UNKNOWN_CONNECTION_ID           = 0x02,
    BLE_ERROR_HARDWARE_FAILURE                = 0x03,
    BLE_ERROR_PAGE_TIMEOUT                    = 0x04,
    BLE_ERROR_AUTH_FAILURE                    = 0x05,
    BLE_ERROR_PIN_MISSING                     = 0x06,
    BLE_ERROR_MEMORY_CAPA_EXCEED              = 0x07,
    BLE_ERROR_CON_TIMEOUT                     = 0x08,
    BLE_ERROR_CON_LIMIT_EXCEED                = 0x09,
    BLE_ERROR_SYNC_CON_LIMIT_DEV_EXCEED       = 0x0A,
    BLE_ERROR_CON_ALREADY_EXISTS              = 0x0B,
    BLE_ERROR_COMMAND_DISALLOWED              = 0x0C,
    BLE_ERROR_CONN_REJ_LIMITED_RESOURCES      = 0x0D,
    BLE_ERROR_CONN_REJ_SECURITY_REASONS       = 0x0E,
    BLE_ERROR_CONN_REJ_UNACCEPTABLE_BDADDR    = 0x0F,
    BLE_ERROR_CONN_ACCEPT_TIMEOUT_EXCEED      = 0x10,
    BLE_ERROR_UNSUPPORTED                     = 0x11,
    BLE_ERROR_INVALID_HCI_PARAM               = 0x12,
    BLE_ERROR_REMOTE_USER_TERM_CON            = 0x13,
    BLE_ERROR_REMOTE_DEV_TERM_LOW_RESOURCES   = 0x14,
    BLE_ERROR_REMOTE_DEV_POWER_OFF            = 0x15,
    BLE_ERROR_CON_TERM_BY_LOCAL_HOST          = 0x16,
    BLE_ERROR_REPEATED_ATTEMPTS               = 0x17,
    BLE_ERROR_PAIRING_NOT_ALLOWED             = 0x18,
    BLE_ERROR_UNKNOWN_LMP_PDU                 = 0x19,
    BLE_ERROR_UNSUPPORTED_REMOTE_FEATURE      = 0x1A,
    BLE_ERROR_SCO_OFFSET_REJECTED             = 0x1B,
    BLE_ERROR_SCO_INTERVAL_REJECTED           = 0x1C,
    BLE_ERROR_SCO_AIR_MODE_REJECTED           = 0x1D,
    BLE_ERROR_INVALID_LMP_PARAM               = 0x1E,
    BLE_ERROR_UNSPECIFIED_ERROR               = 0x1F,
    BLE_ERROR_UNSUPPORTED_LMP_PARAM_VALUE     = 0x20,
    BLE_ERROR_ROLE_CHANGE_NOT_ALLOWED         = 0x21,
    BLE_ERROR_LMP_RSP_TIMEOUT                 = 0x22,
    BLE_ERROR_LMP_COLLISION                   = 0x23,
    BLE_ERROR_LMP_PDU_NOT_ALLOWED             = 0x24,
    BLE_ERROR_ENC_MODE_NOT_ACCEPT             = 0x25,
    BLE_ERROR_LINK_KEY_CANT_CHANGE            = 0x26,
    BLE_ERROR_QOS_NOT_SUPPORTED               = 0x27,
    BLE_ERROR_INSTANT_PASSED                  = 0x28,
    BLE_ERROR_PAIRING_WITH_UNIT_KEY_NOT_SUP   = 0x29,
    BLE_ERROR_DIFF_TRANSACTION_COLLISION      = 0x2A,
    BLE_ERROR_QOS_UNACCEPTABLE_PARAM          = 0x2C,
    BLE_ERROR_QOS_REJECTED                    = 0x2D,
    BLE_ERROR_CHANNEL_CLASS_NOT_SUP           = 0x2E,
    BLE_ERROR_INSUFFICIENT_SECURITY           = 0x2F,
    BLE_ERROR_PARAM_OUT_OF_MAND_RANGE         = 0x30,
    BLE_ERROR_ROLE_SWITCH_PEND                = 0x32, 
    BLE_ERROR_RESERVED_SLOT_VIOLATION         = 0x34, 
    BLE_ERROR_ROLE_SWITCH_FAIL                = 0x35, 
    BLE_ERROR_EIR_TOO_LARGE                   = 0x36, 
    BLE_ERROR_SP_NOT_SUPPORTED_HOST           = 0x37,
    BLE_ERROR_HOST_BUSY_PAIRING               = 0x38,
    BLE_ERROR_CONTROLLER_BUSY                 = 0x3A,
    BLE_ERROR_UNACCEPTABLE_CONN_PARAM         = 0x3B,
    BLE_ERROR_ADV_TO                          = 0x3C,
    BLE_ERROR_TERMINATED_MIC_FAILURE          = 0x3D,
    BLE_ERROR_CONN_FAILED_TO_BE_EST           = 0x3E,
    BLE_ERROR_CCA_REJ_USE_CLOCK_DRAG          = 0x40,
    BLE_ERROR_TYPE0_SUBMAP_NOT_DEFINED        = 0x41,
    BLE_ERROR_UNKNOWN_ADVERTISING_ID          = 0x42,
    BLE_ERROR_LIMIT_REACHED                   = 0x43,
    BLE_ERROR_OPERATION_CANCELED_BY_HOST      = 0x44,
    BLE_ERROR_UNKNOWN_STREAM_ID               = 0x45,
    BLE_ERROR_UNKNOWN_HANDLE                  = 0x46,

    BLE_ERROR_UNDEFINED                       = 0xFF,
}bleError_t;

typedef enum
{
    BLE_STATE_NULL = -1,        //BLE not initialized
    BLE_STATE_IDLE = 0,         //BLE is not working
    BLE_STATE_ADVERTISING = 1,  //BLE is advertising
    BLE_STATE_CONNECTED = 2,    //BLE is connected with peer device(stop advertising), but not ready to transmit RCU data.
    BLE_STATE_READY = 3,        //BLE is ready to transmit RCU data.
}
msrcuBleState_t;

typedef enum
{
    ADV_IND = 1,
    ADV_DIRECT_IND = 2,
}
msrcuBleAdvPduType_t;

typedef enum 
{
    ADV_CHANNEL_37          = 0x01,
	ADV_CHANNEL_38          = 0x02,
	ADV_CHANNEL_39          = 0x04,
    ADV_CHANNEL_37_38       = (ADV_CHANNEL_37 | ADV_CHANNEL_38),
    ADV_CHANNEL_37_39       = (ADV_CHANNEL_37 | ADV_CHANNEL_39),
    ADV_CHANNEL_38_39       = (ADV_CHANNEL_38 | ADV_CHANNEL_38),
    ADV_CHANNEL_37_38_39    = (ADV_CHANNEL_37 | ADV_CHANNEL_38 | ADV_CHANNEL_39),
}
msrcuBleAdvChnl_t;

/* Struct Definition
 ****************************************************************************************
 */
typedef struct 
{
    uint8_t addr[BLE_ADDR_LEN];
}bleAddr_t;//BLE Address

typedef struct 
{
    uint8_t key[BLE_KEY_LEN];
}bleLtk_t;//BLE Long Term Key

typedef struct 
{
    uint8_t nb[BLE_RANDOM_NB_LEN];
}bleRandNb_t;//BLE Random Number

//The maximum length of advertising data and scan response data is generally 31.
//But the first 3 bytes are fixed as below. The rest 28 bytes are for user.
//{
//    0x02,//AD Element Length
//    0x01,//AD Type: Flags
//    0x06,//AD Data: BR/EDR Not Supported & LE General Discoverable Mode
//}
typedef struct
{
    msrcuBleAdvPduType_t pduType;//See msrcuBleAdvPduType_t
    msrcuBleAdvChnl_t channel;//See msrcuBleAdvChnl_t
    uint16_t intvMin;//Minimum advertising interval, unit 0.625ms, at least 20ms
    uint16_t intvMax;//Maximum advertising interval, unit 0.625ms, at least 20ms
    uint8_t* advData;//Advertising data
    uint8_t advDataLen;//Advertising data byte length, maximum 28
    uint8_t* scanRspData;//Scan response data
    uint8_t scanRspDataLen;//Scan response data byte length, maximum 28
    uint8_t peerAddrType;//0=Public/1=Private random
    bleAddr_t peerAddr;//Peer address
}
msrcuBleAdv_t;

typedef struct 
{
	uint8_t conIndex;
    uint16_t conInterval;
    uint16_t conLatency;
    uint16_t conTimeOut;
    uint8_t peerAddrType;
    bleAddr_t peerAddr;
}msrcuBleConInd_t;

typedef struct 
{
	uint8_t conIndex;
    bleError_t reason;
}msrcuBleDisconInd_t;

typedef struct 
{
	uint8_t conIndex;
    uint16_t conInterval;
    uint16_t conLatency;
    uint16_t conTimeOut;
}msrcuBleConParamUpd_t;

typedef struct 
{
	uint8_t conIndex;
}msrcuBleRcuReady_t;

typedef struct 
{
    uint8_t status;//Bonded or not
    uint8_t peerAddrType;//0=Public/1=Private random
    bleAddr_t peerAddr;//peer address
    bleLtk_t ltk;//Long term key
    uint16_t ediv;//Encryption diversifier
    bleRandNb_t randNb;//Random number
    uint8_t keySize;//Encryption key size (7 to 16)
}msrcuBleBondData_t;

typedef struct 
{
    uint8_t conIndex;
    uint8_t instance;//related to HID Report ID
    uint8_t length;
    uint8_t data[244];
}msrcuBleHidReport_t;

/* Global Variable
 ****************************************************************************************
 */

/* Function Declaration
 ****************************************************************************************
 */

#endif
