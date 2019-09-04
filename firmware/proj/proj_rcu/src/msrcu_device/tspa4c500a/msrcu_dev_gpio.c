/**
 ****************************************************************************************
 *
 * @file msrcu_dev_gpio.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
/* Include Files
 ****************************************************************************************
 */
#include "msrcu_dev_system.h"

/* Macro Definition
 ****************************************************************************************
 */

/* Enum Definition
 ****************************************************************************************
 */
enum
{
    INPUT,
    OUTPUT
};

/* Struct Definition
 ****************************************************************************************
 */
typedef struct
{
    uint8_t port;
    uint8_t pin;
    bool onLevel;
    bool isOn;
}ledDev_t;

/* Function Declaration
 ****************************************************************************************
 */

/* Global Variable
 ****************************************************************************************
 */
static ledDev_t ledDev[LED_NUMBER_MAX] = {0};

/* Function Definition
 ****************************************************************************************
 */
static void msrcu_dev_gpio_output(uint8_t port, uint8_t pin, uint8_t level)
{
    hal_gpio_aon_latch(port, pin, 0);	
    hal_gpio_output(port, pin, level, 1);
    hal_gpio_aon_latch(port, pin, 1);
}

static void msrcu_dev_gpio_pin_init(uint8_t port, uint8_t pin, uint8_t direction, uint8_t level)
{
    if(direction == INPUT)
    {
        hal_gpio_pin_mux(port, pin, 0, 0);
        hal_gpio_pad_oe_ie(port, pin, 0, 1);
    }
    else if(direction == OUTPUT)
    {
        hal_gpio_pin_mux(port, pin, 0, 0);
        hal_gpio_pad_oe_ie(port, pin, 1, 0);
        hal_gpio_pad_pd_pu(port, pin, !level, level);
        msrcu_dev_gpio_output(port, pin, level);
    }
    else;
}

msrcuErr_t msrcu_dev_gpio_led_pin_init(void)
{    
    uint8_t i = 0;
    
    ledDev[0].port = MSRCU_DEV_LED_0_GPIO_PORT;
    ledDev[0].pin = MSRCU_DEV_LED_0_GPIO_PIN;
    ledDev[0].onLevel = MSRCU_DEV_LED_0_ON_LEVEL;
    ledDev[1].port = MSRCU_DEV_LED_1_GPIO_PORT;
    ledDev[1].pin = MSRCU_DEV_LED_1_GPIO_PIN;
    ledDev[1].onLevel = MSRCU_DEV_LED_1_ON_LEVEL;
    ledDev[2].port = MSRCU_DEV_LED_2_GPIO_PORT;
    ledDev[2].pin = MSRCU_DEV_LED_2_GPIO_PIN;
    ledDev[2].onLevel = MSRCU_DEV_LED_2_ON_LEVEL;
    
    for(i = 0; i < LED_NUMBER_MAX; i++)
        msrcu_dev_gpio_pin_init(ledDev[i].port, ledDev[i].pin, OUTPUT, !ledDev[i].onLevel);
            
    return ERR_NO_ERROR;
}

msrcuErr_t msrcu_dev_gpio_led_on(uint8_t ledIdx)
{             
    if(ledIdx >= LED_NUMBER_MAX)
        return ERR_NOT_SUPPORT;
    
    msrcu_dev_gpio_pin_init(ledDev[ledIdx].port, ledDev[ledIdx].pin, OUTPUT, !ledDev[ledIdx].onLevel);
    msrcu_dev_gpio_output(ledDev[ledIdx].port, ledDev[ledIdx].pin, ledDev[ledIdx].onLevel);
    ledDev[ledIdx].isOn = true;
    
    return ERR_NO_ERROR;
}

msrcuErr_t msrcu_dev_gpio_led_off(uint8_t ledIdx)
{         
    if(ledIdx >= LED_NUMBER_MAX)
        return ERR_NOT_SUPPORT;
    
    msrcu_dev_gpio_pin_init(ledDev[ledIdx].port, ledDev[ledIdx].pin, OUTPUT, !ledDev[ledIdx].onLevel);	
    msrcu_dev_gpio_output(ledDev[ledIdx].port, ledDev[ledIdx].pin, !ledDev[ledIdx].onLevel);	
    ledDev[ledIdx].isOn = false;
    
    return ERR_NO_ERROR;
}

msrcuErr_t msrcu_dev_gpio_led_toggle(uint8_t ledIdx)
{         
    if(ledIdx >= LED_NUMBER_MAX)
        return ERR_NOT_SUPPORT;
    
    if(ledDev[ledIdx].isOn)
        msrcu_dev_gpio_led_off(ledIdx);
    else        
        msrcu_dev_gpio_led_on(ledIdx);
   
    return ERR_NO_ERROR;
}

msrcuErr_t msrcu_dev_gpio_mic_power_pin_init(void)
{    
#if (MSRCU_VOICE_ENABLE && !MSRCU_DEV_MIC_POWER_USE_VDDIO_SENSOR)
    msrcu_dev_gpio_pin_init(
            MSRCU_DEV_MIC_POWER_GPIO_PORT,
            MSRCU_DEV_MIC_POWER_GPIO_PIN,
            OUTPUT,
            !MSRCU_DEV_MIC_POWER_ON_LEVEL);
    
    return ERR_NO_ERROR;
#else
    return ERR_NOT_SUPPORT;
#endif
}

msrcuErr_t msrcu_dev_gpio_mic_power_on(void)
{        
#if (MSRCU_VOICE_ENABLE && !MSRCU_DEV_MIC_POWER_USE_VDDIO_SENSOR) 
    msrcu_dev_gpio_mic_power_pin_init();
    msrcu_dev_gpio_output(
            MSRCU_DEV_MIC_POWER_GPIO_PORT, 
            MSRCU_DEV_MIC_POWER_GPIO_PIN, 
            MSRCU_DEV_MIC_POWER_ON_LEVEL);
		
    return ERR_NO_ERROR;
#else
    return ERR_NOT_SUPPORT;
#endif
}

msrcuErr_t msrcu_dev_gpio_mic_power_off(void)
{      
#if (MSRCU_VOICE_ENABLE && !MSRCU_DEV_MIC_POWER_USE_VDDIO_SENSOR)  
    msrcu_dev_gpio_mic_power_pin_init();
    msrcu_dev_gpio_output(
            MSRCU_DEV_MIC_POWER_GPIO_PORT, 
            MSRCU_DEV_MIC_POWER_GPIO_PIN, 
            !MSRCU_DEV_MIC_POWER_ON_LEVEL);
    
    return ERR_NO_ERROR;
#else
    return ERR_NOT_SUPPORT;
#endif
}

msrcuErr_t msrcu_dev_gpio_motion_sensor_power_pin_init(void)
{    
#if (MSRCU_MOTION_ENABLE && MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE)
    msrcu_dev_gpio_pin_init(
            MSRCU_DEV_MOTION_SENSOR_POWER_GPIO_PORT,
            MSRCU_DEV_MOTION_SENSOR_POWER_GPIO_PIN,
            OUTPUT,
            !MSRCU_DEV_MOTION_SENSOR_POWER_ON_LEVEL);
    
    return ERR_NO_ERROR;
#else
    return ERR_NOT_SUPPORT;
#endif
}

msrcuErr_t msrcu_dev_gpio_motion_sensor_power_on(void)
{         
#if (MSRCU_MOTION_ENABLE && MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE)
    msrcu_dev_gpio_motion_sensor_power_pin_init();
    msrcu_dev_gpio_output(
            MSRCU_DEV_MOTION_SENSOR_POWER_GPIO_PORT, 
            MSRCU_DEV_MOTION_SENSOR_POWER_GPIO_PIN, 
            MSRCU_DEV_MOTION_SENSOR_POWER_ON_LEVEL);
    
    return ERR_NO_ERROR;
#else
    return ERR_NOT_SUPPORT;
#endif
}

msrcuErr_t msrcu_dev_gpio_motion_sensor_power_off(void)
{
#if (MSRCU_MOTION_ENABLE && MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE)
    msrcu_dev_gpio_motion_sensor_power_pin_init();
    msrcu_dev_gpio_output(
            MSRCU_DEV_MOTION_SENSOR_POWER_GPIO_PORT, 
            MSRCU_DEV_MOTION_SENSOR_POWER_GPIO_PIN, 
            !MSRCU_DEV_MOTION_SENSOR_POWER_ON_LEVEL);
    
    return ERR_NO_ERROR;
#else
    return ERR_NOT_SUPPORT;
#endif
}

msrcuErr_t msrcu_dev_gpio_ir_learn_ctrl_pin_init(void)
{    
#if MSRCU_IR_LEARN_ENABLE
    msrcu_dev_gpio_pin_init(
            MSRCU_DEV_IR_LEARN_CTRL_GPIO_PORT,
            MSRCU_DEV_IR_LEARN_CTRL_GPIO_PIN,
            OUTPUT,
            !MSRCU_DEV_IR_LEARN_CTRL_ON_LEVEL);
    
    return ERR_NO_ERROR;
#else
    return ERR_NOT_SUPPORT;
#endif
}

msrcuErr_t msrcu_dev_gpio_ir_learn_ctrl_on(void)
{     
#if MSRCU_IR_LEARN_ENABLE    
    msrcu_dev_gpio_ir_learn_ctrl_pin_init();
    msrcu_dev_gpio_output(
            MSRCU_DEV_IR_LEARN_CTRL_GPIO_PORT, 
            MSRCU_DEV_IR_LEARN_CTRL_GPIO_PIN, 
            MSRCU_DEV_IR_LEARN_CTRL_ON_LEVEL);
    
    return ERR_NO_ERROR;
#else
    return ERR_NOT_SUPPORT;
#endif
}

msrcuErr_t msrcu_dev_gpio_ir_learn_ctrl_off(void)
{     
#if MSRCU_IR_LEARN_ENABLE    
    msrcu_dev_gpio_ir_learn_ctrl_pin_init();
    msrcu_dev_gpio_output(
            MSRCU_DEV_IR_LEARN_CTRL_GPIO_PORT, 
            MSRCU_DEV_IR_LEARN_CTRL_GPIO_PIN, 
            !MSRCU_DEV_IR_LEARN_CTRL_ON_LEVEL);
    
    return ERR_NO_ERROR;
#else
    return ERR_NOT_SUPPORT;
#endif
}
