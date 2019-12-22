/**
 ****************************************************************************************
 *
 * @file msrcu_dev_i2c.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef MSRCU_DEV_I2C_H
#define MSRCU_DEV_I2C_H

/* Include Files
 ****************************************************************************************
 */
#include "msrcu_event.h"

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
msrcuErr_t msrcu_dev_i2c_init(void);
msrcuErr_t msrcu_dev_i2c_write(uint8_t devAddr, uint8_t regAddr, uint8_t *data, uint16_t len);
msrcuErr_t msrcu_dev_i2c_read(uint8_t devAddr, uint8_t regAddr, uint8_t *data, uint16_t len);

#endif
