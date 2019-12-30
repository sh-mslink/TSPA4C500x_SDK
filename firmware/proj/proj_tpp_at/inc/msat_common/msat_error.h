/**
 ****************************************************************************************
 *
 * @file msat_error.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef MSAT_ERROR_H
#define MSAT_ERROR_H

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
    ERR_NO_ERROR = 0,               //No error.
    
    //System Error
    ERR_NO_MEMORY = 0x01,           //No enough memory.
    ERR_OS,                         //OS error.
    ERR_NOT_SUPPORT,                //Not supported or cannot be used right now.
    ERR_VALID_INPUT,                //The input parameter is valid.
    ERR_DEVICE,                     //MSRCU_DEV is error.
    ERR_DEVICE_DRIVER,              //Device driver error.
    ERR_DEVICE_BLE,                 //Device BLE error.
    
    ERR_OTHERS                      //Undefined error.
}
msatErr_t;

/* Struct Definition
 ****************************************************************************************
 */

/* Global Variable
 ****************************************************************************************
 */

/* Function Declaration
 ****************************************************************************************
 */

#endif
