/**
 ****************************************************************************************
 *
 * @file msrcu_dev_system.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
#ifndef MSRCU_DEV_SYSTEM_H
#define MSRCU_DEV_SYSTEM_H

/* Include Files
 ****************************************************************************************
 */
#include "msrcu_event.h"
#include "cmsis_os.h"
#include "in_arm.h"
#include ".\ble\inb_api.h"
#include "hal_keyboard.h"
#include "hal_gpio.h"
#include "hal_audio.h"
#include "hal_i2c.h"
#include "hal_adc.h"
#include "hal_ir.h"
#include "hal_counter.h"
#include "msg.h"

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
msrcuErr_t msrcu_dev_system_init(void);
msrcuErr_t msrcu_dev_system_vddio_sensor_enable(void);
msrcuErr_t msrcu_dev_system_vddio_sensor_on(void);
msrcuErr_t msrcu_dev_system_vddio_sensor_off(void);
#endif 
