/**
 ****************************************************************************************
 *
 * @file msrcu_error.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
#ifndef MSRCU_ERROR_H
#define MSRCU_ERROR_H

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
    ERR_PERIPHERAL,                 //Peripheral error.
    
//    //BLE Error
//    ERR_BLE_NOT_CONNECTED = 0x11,   //RCU is not connected with peer device.
//    ERR_BLE_NOT_BONDED,             //RCU is not bonded with peer device.
//    ERR_BLE_INFO_EXCH_NOT_FINISH,   //BLE profile information exchange is not finished.
//    ERR_BLE_CNT_PARAM,              //Connection parameter is not satisfied.    
    
    ERR_OTHERS                      //Undefined error.
}
msrcuErr_t;

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
