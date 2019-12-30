/**
 ****************************************************************************************
 *
 * @file msat_common.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef MSAT_COMMON_H
#define MSAT_COMMON_H

/* Include Files
 ****************************************************************************************
 */
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "msat_debug.h"
#include "msat_error.h"
#include "msat_config.h"

/* Macro Definition
 ****************************************************************************************
 */
///MAT Version
#define MSAT_VERSION                    ("0.0.1")

///Command Head
#define MSAT_CMD_HEAD                   ("AT:")

///Command In
//Common command
#define MSAT_CMD_IN_RESET               ("SYSTEMRESET")
#define MSAT_CMD_IN_VERSION             ("VER-(?)")
#define MSAT_CMD_IN_MODE                ("MOD-(x)")
//Passthrough command
#define MSAT_CMD_IN_ADV_INTERVAL        ("ADP-(x)")
#define MSAT_CMD_IN_ADV_DATA            ("ADD-(data)")
#define MSAT_CMD_IN_ADV_ONOFF           ("ADS-(x)")
#define MSAT_CMD_IN_ADV_STATE           ("ADS-(?)")
#define MSAT_CMD_IN_CON_STATE           ("CST-(?)")
#define MSAT_CMD_IN_SEND_CFG_STATE      ("CFG-(?)")
#define MSAT_CMD_IN_DISCON              ("DSC")

///Command Out
//Common command
#define MSAT_CMD_OUT_WAKEUP             ("WAKEUP")
#define MSAT_CMD_OUT_OK                 ("OK")
#define MSAT_CMD_OUT_ERROR              ("ERR")
#define MSAT_CMD_OUT_RESET              ("SYSTEMRESET-OK")
#define MSAT_CMD_OUT_VERSION            ("VER-")
//Passthrough command
#define MSAT_CMD_OUT_ADV_STATE          ("ADS-")
#define MSAT_CMD_OUT_CON_STATE          ("CST-")
#define MSAT_CMD_OUT_SEND_CFG_STATE     ("CFG-")

//Paramters
#define MSAT_CMD_LENGTH_MAX             (256)
#define MSAT_BLE_ADV_DATA_LENGTH_MAX    (31)
#define MSAT_BLE_PT_DATA_LENGTH_MAX     (20)

/* Enum Definition
 ****************************************************************************************
 */
typedef enum
{
    MSAT_CMD_ID_IN                  = 0,
    
    MSAT_CMD_ID_IN_RESET            = 1,
    MSAT_CMD_ID_IN_VERSION,
    MSAT_CMD_ID_IN_MODE,
    
    MSAT_CMD_ID_IN_ADV_INTERVAL     = 101,
    MSAT_CMD_ID_IN_ADV_DATA,
    MSAT_CMD_ID_IN_ADV_ONOFF,
    MSAT_CMD_ID_IN_ADV_STATE,
    MSAT_CMD_ID_IN_CON_STATE,
    MSAT_CMD_ID_IN_SEND_CFG_STATE,
    MSAT_CMD_ID_IN_DISCON,
    
    MSAT_CMD_ID_IN_MAX,
}
msatCmdIdIn;

typedef enum
{
    MSAT_CMD_ID_OUT                 = 0,
    
    MSAT_CMD_ID_OUT_WAKEUP          = 1,
    MSAT_CMD_ID_OUT_OK,
    MSAT_CMD_ID_OUT_ERROR,
    MSAT_CMD_ID_OUT_RESET,
    MSAT_CMD_ID_OUT_VERSION,
    
    MSAT_CMD_ID_OUT_ADV_STATE       = 101,
    MSAT_CMD_ID_OUT_CON_STATE,
    MSAT_CMD_ID_OUT_SEND_CFG_STATE,
    
    MSAT_CMD_ID_OUT_MAX,
}
msatCmdIdOut;

typedef enum
{
    MSAT_MODE_NULL  = 0,
    MSAT_MODE_PT    = 1,//Passthrough
    MSAT_MODE_OTA   = 4,//OTA
}
msatMode;

/* Struct Definition
 ****************************************************************************************
 */

/* Global Variable
 ****************************************************************************************
 */

/* Function Declaration
 ****************************************************************************************
 */

#endif
