/**
 ****************************************************************************************
 *
 * @file evb_led.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

/* Include Files
 ****************************************************************************************
 */
#include <stdint.h>
#include <stdbool.h>

#include "hal_gpio.h"

#include "evb_led.h"

/* Macro Definition
 ****************************************************************************************
 */
#define EVB_LED_R_PORT  0
#define EVB_LED_R_PIN   1
#define EVB_LED_R_LEVEL 0

#define EVB_LED_G_PORT  2
#define EVB_LED_G_PIN   0
#define EVB_LED_G_LEVEL 0

#define EVB_LED_B_PORT  1
#define EVB_LED_B_PIN   8
#define EVB_LED_B_LEVEL 0

/* Enum Definition
 ****************************************************************************************
 */

/* Struct Definition
 ****************************************************************************************
 */
typedef struct
{
    ledIndex idx;
    int port;
    int pin;
    int level;
    ledState onoff;
}
evbLed_t;

/* Function Declaration
 ****************************************************************************************
 */

/* Global Variable
 ****************************************************************************************
 */
static evbLed_t evbLed[LED_MAX] = 
{
    {
        .idx = LED_R,
        .port = EVB_LED_R_PORT,
        .pin = EVB_LED_R_PIN,
        .level = EVB_LED_R_LEVEL,
        .onoff = LED_OFF,
    },
    {
        .idx = LED_G,
        .port = EVB_LED_G_PORT,
        .pin = EVB_LED_G_PIN,
        .level = EVB_LED_G_LEVEL,
        .onoff = LED_OFF,
    },
    {
        .idx = LED_B,
        .port = EVB_LED_B_PORT,
        .pin = EVB_LED_B_PIN,
        .level = EVB_LED_B_LEVEL,
        .onoff = LED_OFF,
    },
};

/* Function Definition
 ****************************************************************************************
 */
ledState evb_led_onoff_get(ledIndex idx)
{
    for(uint8_t i = 0; i < LED_MAX; i++)
    {
        if(idx == evbLed[i].idx)
            return evbLed[idx].onoff;
    }
    
    return LED_OFF;
}

uint8_t evb_led_on_number_get(void)
{
    uint8_t ct = 0;
    
    for(uint8_t i = 0; i < LED_MAX; i++)
    {
        if(LED_ON == evb_led_onoff_get((ledIndex)i))
            ct++;
    }
    
    return ct;
}

void evb_led_single_set(ledIndex idx, ledState onoff)
{
    if(onoff == evb_led_onoff_get(idx))
        return;
    
    int port = evbLed[idx].port;
    int pin = evbLed[idx].pin;
    int level = evbLed[idx].level;
    
    hal_gpio_pin_mux(port, pin, 0, 0);
    hal_gpio_pad_oe_ie(port, pin, 1, 0);
    if(level)
    {
        hal_gpio_pad_pd_pu(port, pin, 1, 0);
        hal_gpio_aon_latch(port, pin, 0);
        if(onoff == LED_OFF)
            hal_gpio_output(port, pin, 0, 1);
        else if(onoff == LED_ON)
            hal_gpio_output(port, pin, 1, 1);
        hal_gpio_aon_latch(port, pin, 1);
    }
    else
    {
        hal_gpio_pad_pd_pu(port, pin, 0, 1);
        hal_gpio_aon_latch(port, pin, 0);
        if(onoff == LED_OFF)
            hal_gpio_output(port, pin, 1, 1);
        else if(onoff == LED_ON)
            hal_gpio_output(port, pin, 0, 1);
        hal_gpio_aon_latch(port, pin, 1);
    }
    
    evbLed[idx].onoff = onoff;
}

void evb_led_single_toggle(ledIndex idx)
{
    if(LED_OFF == evb_led_onoff_get(idx))
        evb_led_single_set(idx, LED_ON);
    else if(LED_ON == evb_led_onoff_get(idx))
        evb_led_single_set(idx, LED_OFF);
}

void evb_led_all_toggle(void)
{
    for(uint8_t i = 0; i < LED_MAX; i++)
    {
        if(LED_OFF == evb_led_onoff_get((ledIndex)i))
            evb_led_single_set((ledIndex)i, LED_ON);
        else if(LED_ON == evb_led_onoff_get((ledIndex)i))
            evb_led_single_set((ledIndex)i, LED_OFF);
    }
}

void evb_led_all_set(ledState onoff)
{
    for(uint8_t i = 0; i < LED_MAX; i++)
        evb_led_single_set((ledIndex)i, onoff);
}

void evb_led_init(void)
{
    evb_led_all_set(LED_OFF);
}
