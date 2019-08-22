/**
 ****************************************************************************************
 *
 * @file msrcu_app.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
#ifndef MSRCU_APP_H
#define MSRCU_APP_H

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
msrcuBleState_t msrcu_app_ble_get_state(void);
//void msrcu_app_ble_set_state(msrcuBleState_t state);
msrcuErr_t msrcu_app_ble_adv_start(msrcuBleAdv_t* adv);
msrcuErr_t msrcu_app_ble_adv_stop(void);
msrcuErr_t msrcu_app_ble_disconnect(void);

msrcuErr_t msrcu_app_key_state_get(uint8_t keyCode, msrcuKeySt *st);
msrcuErr_t msrcu_app_key_hid_send(hidKeycode_t code);

msrcuErr_t msrcu_app_power_bat_voltage_get(uint16_t *mV);

bool msrcu_app_led_is_on(uint8_t ledIdx);
msrcuErr_t msrcu_app_led_on(uint8_t ledIdx);
msrcuErr_t msrcu_app_led_off(uint8_t ledIdx);
msrcuErr_t msrcu_app_led_toggle(uint8_t ledIdx);
    
#if MSRCU_VOICE_ENABLE
bool msrcu_app_voice_is_stop(void);
#if MSRCU_BLE_VOICE_ATV_ENABLE
msrcuErr_t msrcu_app_voice_atv_start(void);
#endif
msrcuErr_t msrcu_app_voice_start(void);
msrcuErr_t msrcu_app_voice_stop(void);
#endif

#if MSRCU_MOTION_ENABLE
#if MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE
msrcuErr_t msrcu_app_motion_reinit(void);
msrcuErr_t msrcu_app_motion_power_on(void);
msrcuErr_t msrcu_app_motion_power_off(void);
#endif
bool msrcu_app_motion_is_stop(void);
msrcuErr_t msrcu_app_motion_start(void);
msrcuErr_t msrcu_app_motion_stop(void);
msrcuErr_t msrcu_app_motion_get_data(msrcuMotionAcc_t *acc, msrcuMotionGyro_t *gyro, msrcuMotionMouse_t *mouse);
#endif

#if (MSRCU_IR_SEND_ENABLE || MSRCU_IR_LEARN_ENABLE)
bool msrcu_app_ir_is_stop(void);
#if MSRCU_IR_SEND_ENABLE
msrcuErr_t msrcu_app_ir_send_start(msrcuIrCode_t* code);
msrcuErr_t msrcu_app_ir_send_stop(void);
#endif
#if MSRCU_IR_LEARN_ENABLE
msrcuErr_t msrcu_app_ir_learn_start(msrcuIrLrnIdx keyIndex);
msrcuErr_t msrcu_app_ir_learn_stop(void);
#endif
#endif

msrcuErr_t msrcu_app_init(msrcuAppCallback_t *cb);

#endif 
