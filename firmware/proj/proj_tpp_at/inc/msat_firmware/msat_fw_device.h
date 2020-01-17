/**
 ****************************************************************************************
 *
 * @file msat_fw_device.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef MSAT_FW_DEVICE_H
#define MSAT_FW_DEVICE_H


/* Include Files
 ****************************************************************************************
 */
#include "msat_event.h"

/* Macro Definition
 ****************************************************************************************
 */

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
bool msat_fw_device_is_mode_supported(msatMode mode);
msatErr_t msat_fw_device_init(void);

#endif