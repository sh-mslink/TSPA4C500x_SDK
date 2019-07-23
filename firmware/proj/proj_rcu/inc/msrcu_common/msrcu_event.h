/**
 ****************************************************************************************
 *
 * @file msrcu_event.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
#ifndef MSRCU_EVENT_H
#define MSRCU_EVENT_H

/* Include Files
 ****************************************************************************************
 */
#include "msrcu_common.h"
#include "msrcu_ble.h"

/* Macro Definition
 ****************************************************************************************
 */

/* Enum Definition
 ****************************************************************************************
 */
typedef enum
{
    EVT_TYPE_NULL   = 0,
    EVT_TYPE_BLE    = 1,
    EVT_TYPE_KEY    = 2,
    EVT_TYPE_IR     = 3
}
msrcuEvtType_t;

typedef enum
{
    EVT_BLE_NULL           = 0,
    EVT_BLE_CONNETED       = 1,
    EVT_BLE_DISCONNETED    = 2,
    EVT_BLE_CON_PRAM_UPD   = 3,
    EVT_BLE_HOGPD_NTF_CFG  = 4
}
msrcuEvtBleCode_t;

typedef enum
{
    EVT_KEY_PRESS       = 1,
    EVT_KEY_RELEASE     = 2,
    EVT_KEY_LONG_PRESS  = 3
}
msrcuKeyBehavior_t;

typedef enum
{
    EVT_IR_LRN_SUCCESS      = 0,//Learn finish and success
    EVT_IR_LRN_FAIL         = 1,//Learn finish but fail
    EVT_IR_LRN_TERMINATE    = 2,//Learn terminate
}
msrcuIrLrnResult_t;

/* Struct Definition
 ****************************************************************************************
 */
typedef struct
{
    msrcuEvtBleCode_t code;
    union
    {
        msrcuBleConInd_t conInd;
        msrcuBleDisconInd_t disconInd;
        msrcuBleConParamUpd_t conParamUpd;
        msrcuBleHogpdNtfCfgInd_t hogpdNtfCfgInd;
    }
    param;
}
msrcuEvtBle_t;

typedef struct
{
    uint8_t code;
    msrcuKeyBehavior_t behavior;
}
msrcuEvtKey_t;

typedef struct
{
    msrcuIrLrnIdx index;
    msrcuIrLrnResult_t lrnResult;
}
msrcuEvtIr_t;

typedef struct
{
    msrcuEvtType_t type;
    union
    {
        msrcuEvtBle_t ble;
        msrcuEvtKey_t key;
        msrcuEvtIr_t  ir;
    }
    param;
}
msrcuEvt_t;

typedef struct
{
    void (*msrcu_app_ble_cb)(msrcuEvtBle_t *evt);
    void (*msrcu_app_key_cb)(msrcuEvtKey_t *evt);
#if (MSRCU_IR_SEND_ENABLE || MSRCU_IR_LEARN_ENABLE)
    void (*msrcu_app_ir_cb)(msrcuEvtIr_t *evt);
#endif
}
msrcuAppCallback_t;

/* Global Variable
 ****************************************************************************************
 */

/* Function Declaration
 ****************************************************************************************
 */

#endif
