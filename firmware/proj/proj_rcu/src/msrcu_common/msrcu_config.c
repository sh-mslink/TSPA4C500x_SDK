/**
 ****************************************************************************************
 *
 * @file msrcu_config.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
/* Include Files
 ****************************************************************************************
 */
#include "msrcu_config.h"

/* Macro Definition
 ****************************************************************************************
 */

/* Enum Definition
 ****************************************************************************************
 */

/* Struct Definition
 ****************************************************************************************
 */

/* Function Declaration
 ****************************************************************************************
 */

/* Global Variable
 ****************************************************************************************
 */
msrcuEnv_t msrcuEnv = {0};

/* Function Definition
 ****************************************************************************************
 */
hidKeycode_t msrcuKeycodeToHidKeycode(unsigned char keycode, unsigned char multiIdx)
{
    switch(keycode)
    {
        case KEY_CODE_NULL:
            return HID_KEYCODE_NULL;
        case KEY_CODE_MOTION:
            return HID_KEYCODE_NULL;
        case KEY_CODE_POWER:
            return HID_KEYCODE_POWER;
        case KEY_CODE_VOLUP:
            return HID_KEYCODE_VOLUP;
        case KEY_CODE_VOLDOWN:
            return HID_KEYCODE_VOLDOWN;
        case KEY_CODE_VOICE:
            return HID_KEYCODE_SEARCH;
        case KEY_CODE_RIGHT:
            return HID_KEYCODE_RIGHT;
        case KEY_CODE_LEFT:
            return HID_KEYCODE_LEFT;
        case KEY_CODE_ENTER:
            return HID_KEYCODE_ENTER;
        case KEY_CODE_MUTE:
            return HID_KEYCODE_MUTE;
        case KEY_CODE_HOME:
            return HID_KEYCODE_HOME;
        case KEY_CODE_UP:
            return HID_KEYCODE_UP;
        case KEY_CODE_MENU:
            return HID_KEYCODE_MENU;
        case KEY_CODE_BACK:
            return HID_KEYCODE_BACK;
        case KEY_CODE_DOWN: 
            return HID_KEYCODE_DOWN;
        default:
            return HID_KEYCODE_NULL;
    }
}

#if MSRCU_IR_SEND_ENABLE
irCmd_t msrcuKeycodeToIrCmd(unsigned char keycode)
{
    switch(keycode)
    {
        case KEY_CODE_NULL:
            return IR_CMD_NULL;
        case KEY_CODE_MOTION:
            return IR_CMD_MOTION;
        case KEY_CODE_POWER:
            return IR_CMD_POWER;
        case KEY_CODE_VOLUP:
            return IR_CMD_VOLUP;
        case KEY_CODE_VOLDOWN:
            return IR_CMD_VOLDOWN;
        case KEY_CODE_VOICE:
            return IR_CMD_VOICE;                
        case KEY_CODE_RIGHT:
            return IR_CMD_RIGHT;
        case KEY_CODE_LEFT:
            return IR_CMD_LEFT;
        case KEY_CODE_ENTER:
            return IR_CMD_ENTER;        
        case KEY_CODE_MUTE:
            return IR_CMD_MUTE;
        case KEY_CODE_HOME:
            return IR_CMD_HOME;
        case KEY_CODE_UP:
            return IR_CMD_UP;
        case KEY_CODE_MENU:
            return IR_CMD_MENU;
        case KEY_CODE_BACK:
            return IR_CMD_BACK;        
        case KEY_CODE_DOWN: 
            return IR_CMD_DOWN;
        default:
            return IR_CMD_NULL;
    }
}
#endif
