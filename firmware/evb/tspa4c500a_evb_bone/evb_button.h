/**
 ****************************************************************************************
 *
 * @file evb_button.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef EVB_BUTTON_H
#define EVB_BUTTON_H

/* Include Files
 ****************************************************************************************
 */
#include "hal_keyboard.h"

/* Macro Definition
 ****************************************************************************************
 */
typedef enum
{
    BUTTON_RELEASE      = 0,
    BUTTON_PRESS        = 1,
    BUTTON_LONG_PRESS   = 2,
}
buttonState;

/* Enum Definition
 ****************************************************************************************
 */

/* Struct Definition
 ****************************************************************************************
 */

/* Global Variable
 ****************************************************************************************
 */

/* Function Declaration
 ****************************************************************************************
 */
uint8_t evb_button_get_pressd_number(void);
buttonState evb_button_get_state(uint8_t code);
void evb_button_init(void (*cb)(uint32_t *code, buttonState *state));

#endif
