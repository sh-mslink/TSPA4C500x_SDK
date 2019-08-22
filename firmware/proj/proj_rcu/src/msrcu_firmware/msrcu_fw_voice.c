/**
 ****************************************************************************************
 *
 * @file msrcu_fe_voice.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
/* Include Files
 ****************************************************************************************
 */
#include "msrcu_config.h"
#if MSRCU_VOICE_ENABLE
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500A
#include "msrcu_dev_system.h"
#include "msrcu_dev_ble.h"
#include "msrcu_dev_audio.h"
#include "msrcu_dev_gpio.h"
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
static bool isStop = true;
 
/* Function Definition
 ****************************************************************************************
 */
msrcuErr_t msrcu_fw_voice_init(void)
{
    msrcuErr_t err = ERR_DEVICE;
            
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500A
#if MSRCU_DEV_MIC_POWER_USE_VDDIO_SENSOR
    msrcu_dev_system_vddio_sensor_enable();
    msrcu_dev_system_vddio_sensor_off();
#else
    msrcu_dev_gpio_mic_power_pin_init();
#endif
    
    err = msrcu_dev_audio_init();
#endif
    
    isStop = true;
    
    return err;
}

bool msrcu_fw_voice_is_stop(void)
{
    return isStop;
}

#if MSRCU_BLE_VOICE_ATV_ENABLE
msrcuErr_t msrcu_fw_voice_atv_start(void)
{
    msrcuErr_t err = ERR_DEVICE;
    
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500A
    err = msrcu_dev_audio_atv_start(); 
#endif
    
    return err;
}
#endif

msrcuErr_t msrcu_fw_voice_start(void)
{
    msrcuErr_t err = ERR_DEVICE;
    
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500A
#if MSRCU_DEV_MIC_POWER_USE_VDDIO_SENSOR
    msrcu_dev_system_vddio_sensor_on();
#else
    msrcu_dev_gpio_mic_power_on();
#endif
    err = msrcu_dev_audio_start(); 
#endif
    
    if(err)
        isStop = true;
    else
        isStop = false;
    
    return err;
}

msrcuErr_t msrcu_fw_voice_stop(void)
{
    msrcuErr_t err = ERR_DEVICE;
    
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500A
#if MSRCU_DEV_MIC_POWER_USE_VDDIO_SENSOR
    msrcu_dev_system_vddio_sensor_off();
#else
    msrcu_dev_gpio_mic_power_off();
#endif
    err = msrcu_dev_audio_stop();
#endif
    
    if(err)
        isStop = false;
    else
        isStop = true;
    
    return err;
}
 
#endif
