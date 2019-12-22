/**
 ****************************************************************************************
 *
 * @file msrcu_app.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

/* Include Files
 ****************************************************************************************
 */
#include "msrcu_app.h"
#include "msrcu_fw_device.h"
#include "msrcu_fw_ble.h"
#include "msrcu_fw_key.h"
#include "msrcu_fw_led.h"
#if MSRCU_VOICE_ENABLE
#include "msrcu_fw_voice.h"
#endif
#if MSRCU_MOTION_ENABLE
#include "msrcu_fw_motion.h"
#endif
#if (MSRCU_IR_SEND_ENABLE || MSRCU_IR_LEARN_ENABLE)
#include "msrcu_fw_ir.h"
#endif

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

/* Function Definition
 ****************************************************************************************
 */
msrcuBleState_t msrcu_app_ble_get_state(void)
{
    return msrcu_fw_ble_get_state();
}

msrcuErr_t msrcu_app_ble_adv_start(msrcuBleAdv_t* adv)
{
    return msrcu_fw_ble_adv_start(adv);
}

msrcuErr_t msrcu_app_ble_adv_stop(void)
{
    return msrcu_fw_ble_adv_stop();
}

msrcuErr_t msrcu_app_ble_disconnect(void)
{
    return msrcu_fw_ble_disconnect();
}

msrcuErr_t msrcu_app_key_state_get(uint8_t keyCode, msrcuKeySt *st)
{
    return msrcu_fw_key_state_get(keyCode, st);
}

msrcuErr_t msrcu_app_key_hid_send(hidKeycode_t code)
{
    return msrcu_fw_key_hid_send(BLE_CON_IDX, code);
}

msrcuErr_t msrcu_app_power_bat_voltage_get(uint16_t *mV)
{
    return msrcu_fw_device_bat_voltage_get(mV);
}

bool msrcu_app_led_is_on(uint8_t ledIdx)
{
    return msrcu_fw_led_is_on(ledIdx);
}

msrcuErr_t msrcu_app_led_on(uint8_t ledIdx)
{
    return msrcu_fw_led_on(ledIdx);
}

msrcuErr_t msrcu_app_led_off(uint8_t ledIdx)
{
    return msrcu_fw_led_off(ledIdx);
}

msrcuErr_t msrcu_app_led_toggle(uint8_t ledIdx)
{
    return msrcu_fw_led_toggle(ledIdx);
}

#if MSRCU_VOICE_ENABLE
bool msrcu_app_voice_is_stop(void)
{
    return msrcu_fw_voice_is_stop();
}

#if MSRCU_BLE_VOICE_ATV_ENABLE
msrcuErr_t msrcu_app_voice_atv_start(void)
{
    return msrcu_fw_voice_atv_start();
}
#endif

msrcuErr_t msrcu_app_voice_start(void)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
    if(!msrcu_fw_voice_is_stop())
        return ERR_NOT_SUPPORT;
    
    err = msrcu_fw_voice_start();
    
    return err;
}

msrcuErr_t msrcu_app_voice_stop(void)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
    if(msrcu_fw_voice_is_stop())
        return ERR_NOT_SUPPORT;
    
    err = msrcu_fw_voice_stop();
    
    return err;
}
#endif

#if MSRCU_MOTION_ENABLE
#if MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE
msrcuErr_t msrcu_app_motion_reinit(void)
{
    return msrcu_fw_motion_reinit();
}

msrcuErr_t msrcu_app_motion_power_on(void)
{
    return msrcu_fw_motion_power_on();
}

msrcuErr_t msrcu_app_motion_power_off(void)
{
    return msrcu_fw_motion_power_off();
}
#endif
bool msrcu_app_motion_is_stop(void)
{
    return msrcu_fw_motion_is_stop();
}

msrcuErr_t msrcu_app_motion_start(void)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
    if(!msrcu_fw_motion_is_stop())
        return ERR_NOT_SUPPORT;
    
    err = msrcu_fw_motion_start();
    
    return err;
}

msrcuErr_t msrcu_app_motion_stop(void)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
    if(msrcu_fw_motion_is_stop())
        return ERR_NOT_SUPPORT;
    
    err = msrcu_fw_motion_stop();
    
    return err;
}

msrcuErr_t msrcu_app_motion_get_data(msrcuMotionAcc_t *acc, msrcuMotionGyro_t *gyro, msrcuMotionMouse_t *mouse)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
    if(msrcu_fw_motion_is_stop())
        return ERR_NOT_SUPPORT;
    
    err = msrcu_fw_motion_get_data(acc, gyro, mouse);
    
    return err;
}

msrcuErr_t msrcu_app_motion_mouse_hid_send(msrcuMouseButton_t button, msrcuMotionMouse_t *mouse)
{
    return msrcu_fw_motion_mouse_hid_send(BLE_CON_IDX, button, mouse);
}
#endif

#if (MSRCU_IR_SEND_ENABLE || MSRCU_IR_LEARN_ENABLE)
bool msrcu_app_ir_is_stop(void)
{
    return msrcu_fw_ir_is_stop();
}

#if MSRCU_IR_SEND_ENABLE
msrcuErr_t msrcu_app_ir_send_start(msrcuIrCode_t* code)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
    if(!msrcu_fw_ir_is_stop())
        return ERR_NOT_SUPPORT;
    
    err = msrcu_fw_ir_send_start(code);
    
    return err;
}

msrcuErr_t msrcu_app_ir_send_stop(void)
{
    return msrcu_fw_ir_send_stop();
}
#endif

#if MSRCU_IR_LEARN_ENABLE
msrcuErr_t msrcu_app_ir_learn_start(msrcuIrLrnIdx keyIndex)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
    if(!msrcu_fw_ir_is_stop())
        return ERR_NOT_SUPPORT;
    
    err = msrcu_fw_ir_learn_start(keyIndex);
    
    return err;
}

msrcuErr_t msrcu_app_ir_learn_stop(void)
{
    return msrcu_fw_ir_learn_stop();    
}
#endif
#endif

static msrcuErr_t msrcu_app_env_init(void)
{
#if MSRCU_VOICE_ENABLE 
    msrcuEnv.enVoice = 1;
#else
    msrcuEnv.enVoice = 0;
#endif
    
#if MSRCU_MOTION_ENABLE
    msrcuEnv.enMotion = 1;
#else
    msrcuEnv.enMotion = 0;
#endif
    
#if MSRCU_IR_SEND_ENABLE
    msrcuEnv.enIrSend = 1;
#else
    msrcuEnv.enIrSend = 0;
#endif
    
#if MSRCU_IR_LEARN_ENABLE 
    msrcuEnv.enIrLearn = 1;
#else
    msrcuEnv.enIrLearn = 0;
#endif
    
    return ERR_NO_ERROR;
}

msrcuErr_t msrcu_app_init(msrcuAppCallback_t *cb)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
    msrcu_app_env_init();
    
    err = msrcu_fw_device_init();
    if(err)
    {
        MSPRINT("msrcu_fw_device_init error.\r\n");
        return err;
    }
    
    err = msrcu_fw_ble_init(cb->msrcu_app_ble_cb);
    if(err)
    {
        MSPRINT("msrcu_fw_ble_init error.\r\n");
        return err;
    }
    
    err = msrcu_fw_key_init(cb->msrcu_app_key_cb);
    if(err)
    {
        MSPRINT("msrcu_fw_key_init error.\r\n");
        return err;
    }
    
    msrcu_fw_led_init();
    
#if MSRCU_VOICE_ENABLE
    err = msrcu_fw_voice_init();
    if(err)
    {
        MSPRINT("msrcu_fw_voice_init error.\r\n");
        return err;
    }
#endif
    
#if MSRCU_MOTION_ENABLE
    err = msrcu_fw_motion_init();
    if(err)
    {
        MSPRINT("msrcu_fw_motion_init error.\r\n");
        return err;
    }
#endif
    
#if (MSRCU_IR_SEND_ENABLE || MSRCU_IR_LEARN_ENABLE)
    err = msrcu_fw_ir_init(cb->msrcu_app_ir_cb);
    if(err)
    {
        MSPRINT("msrcu_fw_ir_init error.\r\n");
        return err;
    }
#endif
    
    return err;
}
