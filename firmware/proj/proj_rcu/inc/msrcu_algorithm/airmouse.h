/**
 ****************************************************************************************
 *
 * @file airmouse.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */
 
#ifndef AIRMOUSE_H
#define AIRMOUSE_H

/* Include Files
 ****************************************************************************************
 */
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* Macro Definition
 ****************************************************************************************
 */
#define M_SAMPLE_FREQUENCY  (100)//unit: Hz
#define M_ACC_1G_COUNT      (4096)//加速度为1g时的输入数值(1 LSB)the count value when 
#define M_GYRO_1DS_COUNT    (16)//角速度为1度/秒时的输入数值(1 LSB)
#define M_SENSITIVITY       (32)//空鼠灵敏度，数值越大移动越慢

/* Enum Definition
 ****************************************************************************************
 */

/* Struct Definition
 ****************************************************************************************
 */
typedef struct 
{
    int16_t accX;
    int16_t accY;
    int16_t accZ;
    int16_t gyroX;
    int16_t gyroY;
    int16_t gyroZ;
}
amSensor_t;

typedef struct 
{
    int8_t x;
    int8_t y;
}
amMouse_t;

typedef struct 
{
    amSensor_t sensor;
    amMouse_t mouse;
}
amAirMouse_t;

/* Function Declaration
 ****************************************************************************************
 */

/* Global Variable
 ****************************************************************************************
 */

/* Function Definition
 ****************************************************************************************
 */
bool airmouseInit(int16_t sFreq, int16_t accGCount, int16_t gyroDsCount, int16_t sen);
void airmouseConversion(amAirMouse_t *amData);

/* Example:
{
    bool result;
    amAirMouse_t data = {0};

    result = airmouseInit(M_SAMPLE_FREQUENCY, M_ACC_1G_COUNT, M_GYRO_1DS_COUNT, M_SENSITIVITY);    
    if(result == false)
        return;
        
    while(SAMPLE_FREQUENCY is reached)
    {
        data.sensor.accX = accXReal;
        data.sensor.accY = accYReal;
        data.sensor.accZ = accZReal;
        data.sensor.gyroX = gyroXReal;
        data.sensor.gyroY = gyroYReal;
        data.sensor.gyroZ = gyroZReal;
        
        airmouseConversion(&data);
        
        printf("x=%d, y=%d\r\n", data.mouse.x, data.mouse.y);
    }
}   
*/

/* Note:
    If the direction of X&Y output is wrong, change 
    the sign and the sequence of sensor's X&Y&Z input, and retry.
*/

#endif
