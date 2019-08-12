/**
 ****************************************************************************************
 *
 * @file msrcu_dev_adc.c
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
#define ADC_BAT_SAMPLE_NUMBER   (8)

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
static adc_dev_t* batAdcDev;
static uint16_t batAdcBuf[ADC_BAT_SAMPLE_NUMBER] = {0};

/* Function Definition
 ****************************************************************************************
 */
msrcuErr_t msrcu_dev_adc_bat_voltage_get(uint16_t *mV)
{
    uint32_t avg = 0;
    
    memset(batAdcBuf, 0xff, sizeof(batAdcBuf));
    
    if(hal_adc_auto_mode_start(batAdcDev, ADC_BAT_SAMPLE_NUMBER))
    {
        *mV = 0;
        return ERR_PERIPHERAL;
    }

    avg = 0;
    for(int i = 0; i < ADC_BAT_SAMPLE_NUMBER; i++)
        avg += batAdcBuf[i];
    avg /= ADC_BAT_SAMPLE_NUMBER;
    avg = avg * 29 / 12;
    
    memset(batAdcBuf, 0, sizeof(batAdcBuf));
    
    *mV = avg;
    
    return ERR_NO_ERROR;    
}

msrcuErr_t msrcu_dev_adc_init(void)
{
    batAdcDev = hal_adc_open();
    if(!batAdcDev)
        return ERR_PERIPHERAL;
        
    if(hal_adc_auto_mode_enable_ch(batAdcDev, ADC_CH14, batAdcBuf, ADC_BAT_SAMPLE_NUMBER))
        return ERR_PERIPHERAL;
    
    return ERR_NO_ERROR;
}
