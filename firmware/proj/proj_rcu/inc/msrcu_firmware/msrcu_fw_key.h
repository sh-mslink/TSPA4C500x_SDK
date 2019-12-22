/**
 ****************************************************************************************
 *
 * @file msrcu_fw_key.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef MSRCU_FW_KEY_H
#define MSRCU_FW_KEY_H

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
msrcuErr_t msrcu_fw_key_state_get(uint8_t keyCode, msrcuKeySt *st);
msrcuErr_t msrcu_fw_key_init(void (*cb)(msrcuEvtKey_t *evt)); 
msrcuErr_t msrcu_fw_key_hid_send(uint8_t conIndex, hidKeycode_t code);
 
#endif
