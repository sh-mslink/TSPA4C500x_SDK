/**
 ****************************************************************************************
 *
 * @file msrcu_dev_i2c.c
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
#define MSRCU_DEV_I2C_SPEED I2C_SPEED_100K

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
static void *i2cDev;

/* Function Definition
 ****************************************************************************************
 */
msrcuErr_t msrcu_dev_i2c_init(void)
{
    int id = -1;
    
#if (MSRCU_DEV_MOTION_I2C_CHANNEL == 0)
        id = I2C0_ID;
#elif (MSRCU_DEV_MOTION_I2C_CHANNEL == 1)
        id = I2C1_ID;
#endif
    
	i2cDev = hal_i2c_open(id);
	if (!i2cDev)
		return ERR_DEVICE_DRIVER;
    else    
        return ERR_NO_ERROR;
}

msrcuErr_t msrcu_dev_i2c_write(uint8_t devAddr, uint8_t regAddr, uint8_t *data, uint16_t len)
{
    uint8_t *wr = malloc(len + 1);
    if(wr == NULL)
        return ERR_NO_MEMORY;
    
    wr[0] = regAddr;
    memcpy(wr + 1, data, len);
    
    int err = hal_mi2c_write(i2cDev, MSRCU_DEV_I2C_SPEED, devAddr, wr, len + 1, osWaitForever);
    if(wr)
        free(wr);
    
    if(err)
        MSPRINT("%s err: %d.\r\n", __func__, err);
    
    if(err)
        return ERR_DEVICE_DRIVER;
    else
        return ERR_NO_ERROR;
}

msrcuErr_t msrcu_dev_i2c_read(uint8_t devAddr, uint8_t regAddr, uint8_t *data, uint16_t len)
{    
    int err;
    uint8_t wr = regAddr;
    
    err = hal_mi2c_write_read(i2cDev, MSRCU_DEV_I2C_SPEED, devAddr, &wr, 1, data, len, osWaitForever);
    if(err)
        MSPRINT("%s err: %d.\r\n", __func__, err);
    if(err)
        return ERR_DEVICE_DRIVER;    
    else
        return ERR_NO_ERROR;
}

//msrcuErr_t msrcu_dev_i2c_read(uint8_t devAddr, uint8_t regAddr, uint8_t *data, uint16_t len)
//{    
//    uint8_t wr;
//    int err;
//    
//    wr = regAddr;
//    err = hal_mi2c_write(i2cDev, MSRCU_DEV_I2C_SPEED, devAddr, &wr, 1, 1);
//    if(err)
//        MSPRINT("hal_mi2c_write R error: %d.\r\n", err);
//    if(err)
//        return ERR_DEVICE_DRIVER;    
//    
//    err = hal_mi2c_read(i2cDev, MSRCU_DEV_I2C_SPEED, devAddr, data, len, 2);
//    if(err)
//        MSPRINT("hal_mi2c_read error: %d.\r\n", err);
//    if(err)
//        return ERR_DEVICE_DRIVER;    
//    else
//        return ERR_NO_ERROR;
//}
