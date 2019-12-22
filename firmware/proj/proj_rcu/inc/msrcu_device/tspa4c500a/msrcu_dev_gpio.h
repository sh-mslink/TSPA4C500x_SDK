/**
 ****************************************************************************************
 *
 * @file msrcu_dev_gpio.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef MSRCU_DEV_GPIO_H
#define MSRCU_DEV_GPIO_H

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
msrcuErr_t msrcu_dev_gpio_led_pin_init(void);
msrcuErr_t msrcu_dev_gpio_led_on(uint8_t ledIdx);
msrcuErr_t msrcu_dev_gpio_led_off(uint8_t ledIdx);
msrcuErr_t msrcu_dev_gpio_led_toggle(uint8_t ledIdx);

msrcuErr_t msrcu_dev_gpio_mic_power_pin_init(void);
msrcuErr_t msrcu_dev_gpio_mic_power_on(void);
msrcuErr_t msrcu_dev_gpio_mic_power_off(void);

msrcuErr_t msrcu_dev_gpio_motion_sensor_power_pin_init(void);
msrcuErr_t msrcu_dev_gpio_motion_sensor_power_on(void);
msrcuErr_t msrcu_dev_gpio_motion_sensor_power_off(void);

msrcuErr_t msrcu_dev_gpio_ir_learn_ctrl_pin_init(void);
msrcuErr_t msrcu_dev_gpio_ir_learn_ctrl_on(void);
msrcuErr_t msrcu_dev_gpio_ir_learn_ctrl_off(void);

#endif
