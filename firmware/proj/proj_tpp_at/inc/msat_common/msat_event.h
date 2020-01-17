/**
 ****************************************************************************************
 *
 * @file msat_event.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef MSAT_EVENT_H
#define MSAT_EVENT_H

/* Include Files
 ****************************************************************************************
 */
#include "msat_common.h"

/* Macro Definition
 ****************************************************************************************
 */

/* Enum Definition
 ****************************************************************************************
 */
typedef enum
{
    MSAT_EVT_BLE_NULL           = 0,
    MSAT_EVT_BLE_CON_STATE      = 1,
    MSAT_EVT_BLE_SEND_CFG       = 2,
    MSAT_EVT_BLE_RCV_DATA       = 3,
}
msatEvtBleCode;

/* Struct Definition
 ****************************************************************************************
 */
typedef struct
{
    msatCmdIdIn id;
    uint16_t len;
    uint8_t *param;
}
msatEvtCmdIn_t;

typedef struct
{
    bool isConnected;
}
msatBleConState_t;

typedef struct
{
    bool isEnabled;
}
msatBleSendCfg_t;

typedef struct
{
    uint16_t len;
    uint8_t data[MSAT_BLE_PT_DATA_LENGTH_MAX];
}
msatBleRcvData_t;

typedef struct
{
    msatEvtBleCode code;
    union
    {
        msatBleConState_t conState;
        msatBleSendCfg_t sendCfg;
        msatBleRcvData_t rcvData;
    }
    param;
}
msatEvtBle_t;

typedef struct
{
    void (*wupCb)(void);//wakup in
    void (*cmdInCb)(msatEvtCmdIn_t *evt);//received command
    void (*noCmdCb)(char *data, uint16_t len);//received no command data
    void (*bleCb)(msatEvtBle_t *evt);//ble event callback
}
msatEvtCallback_t;

/* Global Variable
 ****************************************************************************************
 */

/* Function Declaration
 ****************************************************************************************
 */

#endif
