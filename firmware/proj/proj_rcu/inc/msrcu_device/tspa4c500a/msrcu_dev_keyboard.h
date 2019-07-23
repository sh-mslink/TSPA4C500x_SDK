/**
 ****************************************************************************************
 *
 * @file msrcu_dev_keyboard.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
#ifndef MSRCU_DEV_KEYBOARD_H
#define MSRCU_DEV_KEYBOARD_H

/* Include Files
 ****************************************************************************************
 */
#include "msrcu_event.h"

/* Macro Definition
 ****************************************************************************************
 */

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
msrcuErr_t msrcu_dev_keyboard_state_get(uint8_t keyCode, msrcuKeySt *st);
msrcuErr_t msrcu_dev_keyboard_init(uint8_t row, uint8_t col, void (*cb)(msrcuEvtKey_t *evt));

#endif
