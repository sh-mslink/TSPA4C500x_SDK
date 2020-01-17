/**
 ****************************************************************************************
 *
 * @file evb_led.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef EVB_LED_H
#define EVB_LED_H

/* Include Files
 ****************************************************************************************
 */

/* Macro Definition
 ****************************************************************************************
 */

/* Enum Definition
 ****************************************************************************************
 */
typedef enum
{
    LED_R   = 0,
    LED_G   = 1,
    LED_B   = 2,
    LED_MAX
}
ledIndex;

typedef enum
{
    LED_OFF = 0,
    LED_ON  = 1,
}
ledState;

/* Struct Definition
 ****************************************************************************************
 */

/* Global Variable
 ****************************************************************************************
 */

/* Function Declaration
 ****************************************************************************************
 */
ledState evb_led_onoff_get(ledIndex idx);
uint8_t evb_led_on_number_get(void);
void evb_led_single_set(ledIndex idx, ledState onoff);
void evb_led_single_toggle(ledIndex idx);
void evb_led_all_toggle(void);
void evb_led_all_set(ledState onoff);
void evb_led_init(void);

#endif
