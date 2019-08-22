/**
 ****************************************************************************************
 *
 * @file msrcu_common.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
#ifndef MSRCU_COMMON_H
#define MSRCU_COMMON_H

/* Include Files
 ****************************************************************************************
 */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "msrcu_ble.h"
#include "msrcu_debug.h"
#include "msrcu_error.h"
#include "msrcu_config.h"

/* Macro Definition
 ****************************************************************************************
 */
#define KEY_LONGPRESS_CHECK_INTERVAL    (100)//ms

#define LED_NUMBER_MAX          (3)

#define VOICE_SAMPLE_RATE_8K    (8000)
#define VOICE_SAMPLE_RATE_16K   (16000)

#define BLE_CON_IDX             (0)

#define HID_KEYCODE_INSTANCE    (0)
#define HID_VOICE_INSTANCE      (1)
#define HID_MOUSE_INSTANCE      (2)

#define KEYCODE_HID_PKG_SIZE    (2)
#define KEYCODE_HID_PKG_KB_IDX  (0)
#define KEYCODE_HID_PKG_CD_IDX  (1)

#define MOUSE_HID_PKG_SIZE      (3)
#define MOUSE_HID_PKG_KEY_IDX   (0)
#define MOUSE_HID_PKG_X_IDX     (1)
#define MOUSE_HID_PKG_Y_IDX     (2)

typedef uint8_t msrcuTimerId;

typedef uint8_t msrcuIrLrnIdx;

/* Enum Definition
 ****************************************************************************************
 */
typedef enum
{
    POWER_STATE_NORMAL,
    POWER_STATE_LOW, 
    POWER_STATE_EMPTY,    
}msrcuPowerSt;//Power state

typedef enum
{
    KEY_RELEASED, 
    KEY_PRESSED,   
}msrcuKeySt;//Key state

typedef enum
{
    LED_STATE_PRIORITY_MASK = 0xf0,
    LED_STATE_FUNCTION_MASK = 0x0f,
    
    LED_STATE_NULL          = 0x00,
    
    LED_STATE_KEY_MASK      = 0x10,
    LED_STATE_KEY_PRESS,
    LED_STATE_KEY_RELEASE,
    
    LED_STATE_POWER_MASK    = 0x20,
    LED_STATE_POWER_LOW,
    LED_STATE_POWER_EMPTY,
    
    LED_STATE_FUNC_MASK     = 0x30,
    LED_STATE_FUNC_VOICE_START,
    LED_STATE_FUNC_VOICE_STOP,
    LED_STATE_FUNC_MOTION_START,
    LED_STATE_FUNC_MOTION_STOP,
    
    LED_STATE_BOND_MASK     = 0x40,
    LED_STATE_BOND_START,
    LED_STATE_BOND_SUCCESS,
    LED_STATE_BOND_FAIL,
    LED_STATE_BOND_CLEAR,    
    
    LED_STATE_IR_LEARN_MASK = 0x50,
    LED_STATE_IR_LEARN_START,
    LED_STATE_IR_LEARN_SUCCESS,
    LED_STATE_IR_LEARN_FAIL,
}msrcuLedSt;//LED state

typedef enum
{
    MOUSE_BUTTON_NULL   = 0x00,
    MOUSE_BUTTON_LEFT   = 0x01,
    MOUSE_BUTTON_TIGHT  = 0x02,
    MOUSE_BUTTON_MIDDLE = 0x03,
}
msrcuMouseButton_t;//Mouse button

typedef enum
{
    IR_FUNC_NULL    = 0,
    IR_FUNC_SEND    = 1,//IR send
    IR_FUNC_LEARN   = 2,//IR learn
}
msrcuIrFunc_t;//IR function

typedef enum
{
    IR_BEHV_NULL    = 0,
    IR_BEHV_START   = 1,//IR start
    IR_BEHV_STOP    = 2,//IR stop
}
msrcuIrBehv_t;//IR behavior

typedef enum
{
    IR_PROT_NULL    = 0,
    IR_PROT_LEARN   = 1,//code from IR learn
    IR_PROT_NEC     = 2,//Extended NEC protocol
}
msrcuIrProt_t;//IR protocol

/* Struct Definition
 ****************************************************************************************
 */
typedef struct
{
    int16_t x;
    int16_t y;
    int16_t z;
}
msrcuMotionAcc_t;

typedef struct
{
    int16_t x;
    int16_t y;
    int16_t z;
}
msrcuMotionGyro_t;

typedef struct
{
    int8_t x;
    int8_t y;
}
msrcuMotionMouse_t;

typedef struct
{
    uint8_t baseClock;//MHz
    uint8_t necCarrierDutyRatio;
    uint8_t irSendPort;
    uint8_t irSendPin;
    uint8_t irLearnPort;
    uint8_t irLearnPin;
    uint8_t irLearnCodeNb;
}
msrcuIrEnv_t;

typedef struct
{
    msrcuIrLrnIdx index;
}
msrcuIrCodeLearn_t;

typedef struct
{
    uint8_t addL;
    uint8_t addH;
    uint8_t cmd;
}
msrcuIrCodeNec_t;

typedef struct
{
    msrcuIrProt_t protocol;
    union
    {
        msrcuIrCodeLearn_t learnCode;
        msrcuIrCodeNec_t necCode;
    }
    param;
}
msrcuIrCode_t;

typedef struct
{
    msrcuIrFunc_t function;
    msrcuIrBehv_t behavior;
    msrcuIrCode_t code;
}
msrcuIr_t;

/* Global Variable
 ****************************************************************************************
 */

/* Function Declaration
 ****************************************************************************************
 */

#endif
