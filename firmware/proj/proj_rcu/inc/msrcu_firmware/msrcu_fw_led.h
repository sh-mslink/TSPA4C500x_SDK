/**
 ****************************************************************************************
 *
 * @file msrcu_fw_led.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
#ifndef MSRCU_FW_LED_H
#define MSRCU_FW_LED_H

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
bool msrcu_fw_led_is_on(uint8_t ledIdx);
msrcuErr_t msrcu_fw_led_init(void);
msrcuErr_t msrcu_fw_led_on(uint8_t ledIdx);
msrcuErr_t msrcu_fw_led_off(uint8_t ledIdx);
msrcuErr_t msrcu_fw_led_toggle(uint8_t ledIdx);
#endif
