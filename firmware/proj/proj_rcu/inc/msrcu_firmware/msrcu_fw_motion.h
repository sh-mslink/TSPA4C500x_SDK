/**
 ****************************************************************************************
 *
 * @file msrcu_fw_motion.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef MSRCU_FW_MOTION_H
#define MSRCU_FW_MOTION_H

/* Include Files
 ****************************************************************************************
 */
#include "msrcu_event.h"
#if MSRCU_MOTION_ENABLE

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
#if MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE
msrcuErr_t msrcu_fw_motion_power_on(void); 
msrcuErr_t msrcu_fw_motion_power_off(void);
msrcuErr_t msrcu_fw_motion_reinit(void);
#endif
msrcuErr_t msrcu_fw_motion_init(void); 
bool msrcu_fw_motion_is_stop(void);
msrcuErr_t msrcu_fw_motion_start(void);
msrcuErr_t msrcu_fw_motion_stop(void);
msrcuErr_t msrcu_fw_motion_get_data(msrcuMotionAcc_t *acc, msrcuMotionGyro_t *gyro, msrcuMotionMouse_t *mouse);
msrcuErr_t msrcu_fw_motion_mouse_hid_send(uint8_t conIndex, msrcuMouseButton_t button, msrcuMotionMouse_t *mouse);
#endif

#endif
