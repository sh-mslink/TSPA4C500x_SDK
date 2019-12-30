/**
 ****************************************************************************************
 *
 * @file msat_app.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

/* Include Files
 ****************************************************************************************
 */
#include "msat_fw_device.h"
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
msatErr_t msat_app_data_out(char* data, uint16_t len)
{
    return msat_fw_evt_data_out(data, len);
}

msatErr_t msat_app_init(msatEvtCallback_t *cb)
{
    msatErr_t err = ERR_NO_ERROR;
    
    err =  msat_fw_evt_cb_set(cb);
    if(err)
        return err;
    
    err = msat_fw_device_init();
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
