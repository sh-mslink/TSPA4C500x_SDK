/**
 ****************************************************************************************
 *
 * @file msrcu_vw_device.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
/* Include Files
 ****************************************************************************************
 */
#include "msrcu_dev_system.h"
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500A
#include "msrcu_dev_adc.h"
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
msrcuErr_t msrcu_fw_device_bat_voltage_get(uint16_t *mV)
{
    return msrcu_dev_adc_bat_voltage_get(mV);
}

msrcuErr_t msrcu_fw_device_init(void)
{
    msrcuErr_t err = ERR_DEVICE;
    
    if(MSRCU_DEV == MSRCU_DEV_NULL || MSRCU_DEV > MSRCU_DEV_MAX)
        return ERR_DEVICE;
    
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500A    
    err = msrcu_dev_system_init();
    if(err)
        return err;  
    
    err = msrcu_dev_adc_init();
    if(err)
        return err;
#endif
    
    return err;
}
