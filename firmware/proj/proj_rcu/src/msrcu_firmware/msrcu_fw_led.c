/**
 ****************************************************************************************
 *
 * @file msrcu_fw_led.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
/* Include Files
 ****************************************************************************************
 */
#include "msrcu_config.h"
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500X
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
static bool ledIsOn[LED_NUMBER_MAX];
 
/* Function Definition
 ****************************************************************************************
 */
bool msrcu_fw_led_is_on(uint8_t ledIdx)
{
    if(ledIdx >= LED_NUMBER_MAX)
        return false;
    
    return ledIsOn[ledIdx];
}

msrcuErr_t msrcu_fw_led_init(void)
{
    for(int i = 0; i < LED_NUMBER_MAX; i++)
        ledIsOn[i] = false;
    
    return msrcu_dev_gpio_led_pin_init();
}

msrcuErr_t msrcu_fw_led_on(uint8_t ledIdx)
{
    msrcuErr_t err;
    
    if(msrcu_fw_led_is_on(ledIdx))
        return ERR_NO_ERROR;
    
    err = msrcu_dev_gpio_led_on(ledIdx);
    if(!err)
        ledIsOn[ledIdx] = true;
    
    return err;
}

msrcuErr_t msrcu_fw_led_off(uint8_t ledIdx)
{
    msrcuErr_t err;
    
    if(!msrcu_fw_led_is_on(ledIdx))
        return ERR_NO_ERROR;
    
    err = msrcu_dev_gpio_led_off(ledIdx);
    if(!err)
        ledIsOn[ledIdx] = false;
    
    return err;
}

msrcuErr_t msrcu_fw_led_toggle(uint8_t ledIdx)
{
    msrcuErr_t err;
    
    err = msrcu_dev_gpio_led_toggle(ledIdx);
    if(!err)
        ledIsOn[ledIdx] = ~ledIsOn[ledIdx];
    
    return err;
}
