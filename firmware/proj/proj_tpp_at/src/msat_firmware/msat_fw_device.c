/**
 ****************************************************************************************
 *
 * @file msat_fw_device.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

/* Include Files
 ****************************************************************************************
 */
#include "msat_dev_system.h"
#include "msat_fw_evt.h"

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
bool msat_fw_device_is_mode_supported(msatMode mode)
{
#if (MSAT_DEV == MSAT_DEV_TSPA4C500X)
    if(mode == MSAT_MODE_PT || mode == MSAT_MODE_OTA)
        return true;
#endif
    
    return false;
}

msatErr_t msat_fw_device_init(void)
{
    msatErr_t err = ERR_NO_ERROR;
    
    err = msat_dev_system_init(MSAT_DEV);
    if(err)
        return err;
    
    err = msat_fw_evt_command_out(MSAT_CMD_ID_OUT_RESET, NULL, NULL);
    if(err)
        return err;
    
    return err;
}

/* Global Variable
 ****************************************************************************************
 */

/* Function Definition
 ****************************************************************************************
 */
