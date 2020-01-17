/**
 ****************************************************************************************
 *
 * @file msat_config.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef MSAT_CONFIG_H
#define MSAT_CONFIG_H

/* Include Files
 ****************************************************************************************
 */

/* Macro Definition
 ****************************************************************************************
 */

/****************************************************************/
///MSAT device chip part name
#define MSAT_DEV_TSPA4C500X     (1)//Tropos: TSPA4C500x, SDK_0.6.1
/****************************************************************/


///Device parameters
#define MSAT_DEV                MSAT_DEV_TSPA4C500X//MSAT device chip selection


///Device peripheral configuration
#define MSAT_UART_CHANNEL       (1)//UART channel ID for device, should match the device's configuration
#define MSAT_UART_BAUDRATE      (115200)

#define MSAT_WAKEUP_IN_PORT     (4)//GPIO port
#define MSAT_WAKEUP_IN_PIN      (1)//GPIO pin
#define MSAT_WAKEUP_IN_LEVEL    (0)//0 for low level wakeup, 1 for high level wakeup

#define MSAT_WAKEUP_OUT_PORT    (2)//GPIO port
#define MSAT_WAKEUP_OUT_PIN     (2)//GPIO pin
#define MSAT_WAKEUP_OUT_LEVEL   (0)//0 for low level wakeup, 1 for high level wakeup


///Default parameters
#define MSAT_WAKUP_OUT_DELAY    (0)//ms
#define MSAT_ADV_INTERVAL       (32)//0.625ms, 32~16384, default BLE advertising interval
#define MSAT_ADV_DATA           ("\x02\x01\x06\x05\x09\x4D\x53\x41\x54")//default BLE advertising data

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

#endif
