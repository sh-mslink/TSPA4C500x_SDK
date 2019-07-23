/**
 ****************************************************************************************
 *
 * @file msrcu_dev_system.c
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
msrcuErr_t msrcu_dev_system_init(void)
{    
#if (MSRCU_DEV <= MSRCU_DEV_NULL) || (MSRCU_DEV > MSRCU_DEV_MAX)
    return ERR_DEVICE;
#else
    return ERR_NO_ERROR;
#endif
}

msrcuErr_t msrcu_dev_system_vddio_sensor_enable(void)
{    
    aon_write(AON_PS_REGS_MISC_BYPASS_0_CTRL, 
            aon_read(AON_PS_REGS_MISC_BYPASS_0_CTRL) | (AON_PS_REGS_MISC_BYPASS_0_CTRL_SENSOR_VDDIO_EN_EN));

    return ERR_NO_ERROR;
}

msrcuErr_t msrcu_dev_system_vddio_sensor_on(void)
{    
    aon_write(AON_PS_REGS_MISC_BYPASS_0_CTRL, 
            aon_read(AON_PS_REGS_MISC_BYPASS_0_CTRL) | (AON_PS_REGS_MISC_BYPASS_0_CTRL_SENSOR_VDDIO_EN_VAL));

    return ERR_NO_ERROR;
}

msrcuErr_t msrcu_dev_system_vddio_sensor_off(void)
{    
    aon_write(AON_PS_REGS_MISC_BYPASS_0_CTRL, 
            aon_read(AON_PS_REGS_MISC_BYPASS_0_CTRL) & (~AON_PS_REGS_MISC_BYPASS_0_CTRL_SENSOR_VDDIO_EN_VAL));

    return ERR_NO_ERROR;
}
