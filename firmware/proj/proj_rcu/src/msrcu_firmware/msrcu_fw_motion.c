/**
 ****************************************************************************************
 *
 * @file msrcu_fw_motion.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
/* Include Files
 ****************************************************************************************
 */
#include "msrcu_config.h"
#if MSRCU_MOTION_ENABLE
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500X 
#include "msrcu_dev_system.h"
#include "msrcu_dev_ble.h"
#include "msrcu_dev_gpio.h"
#include "msrcu_dev_i2c.h"
#if MSRCU_BMI160_I2C
#include "bmi160.h"
#include "airmouse.h"
#endif
#endif

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
static bool isStop = true;

#if MSRCU_BMI160_I2C
static struct bmi160_dev bm160Dev = {0};
#endif
 
/* Function Definition
 ****************************************************************************************
 */
#if MSRCU_BMI160_I2C
static bmi160_com_fptr_t bmi160_i2c_write(uint8_t devAddr, uint8_t regAddr, uint8_t *data, uint16_t len)
{
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500X
    msrcu_dev_i2c_write(devAddr, regAddr, data, len);
#endif
    return 0;
}

static bmi160_com_fptr_t bmi160_i2c_read(uint8_t devAddr, uint8_t regAddr, uint8_t *data, uint16_t len)
{
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500X
    msrcu_dev_i2c_read(devAddr, regAddr, data, len);
#endif
    return 0;
}

static bmi160_delay_fptr_t bmi160_delay_ms(uint32_t millisec)
{
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500X
    osDelay(millisec);
#endif
    return 0;
}
#endif

static msrcuErr_t msrcu_fw_motion_sensor_direction_map(amSensor_t *sensor)
{
    amSensor_t *p = malloc(sizeof(amSensor_t));
    if(!p)
        return ERR_NO_MEMORY;
    
    memcpy(p, sensor, sizeof(amSensor_t));
    
    //acc
    if(MSRCU_MOTION_SENSOR_ACC_X > 0)
    {
        if     (MSRCU_MOTION_SENSOR_ACC_X == 1) sensor->accX = p->accX;
        else if(MSRCU_MOTION_SENSOR_ACC_X == 2) sensor->accX = p->accY;
        else if(MSRCU_MOTION_SENSOR_ACC_X == 3) sensor->accX = p->accZ;
    }
    else if(MSRCU_MOTION_SENSOR_ACC_X < 0)
    {
        if     (MSRCU_MOTION_SENSOR_ACC_X == -1) sensor->accX = -(p->accX);
        else if(MSRCU_MOTION_SENSOR_ACC_X == -2) sensor->accX = -(p->accY);
        else if(MSRCU_MOTION_SENSOR_ACC_X == -3) sensor->accX = -(p->accZ);
    }
    
    if(MSRCU_MOTION_SENSOR_ACC_Y > 0)
    {
        if     (MSRCU_MOTION_SENSOR_ACC_Y == 1) sensor->accY = p->accX;
        else if(MSRCU_MOTION_SENSOR_ACC_Y == 2) sensor->accY = p->accY;
        else if(MSRCU_MOTION_SENSOR_ACC_Y == 3) sensor->accY = p->accZ;
    }
    else if(MSRCU_MOTION_SENSOR_ACC_Y < 0)
    {
        if     (MSRCU_MOTION_SENSOR_ACC_Y == -1) sensor->accY = -(p->accX);
        else if(MSRCU_MOTION_SENSOR_ACC_Y == -2) sensor->accY = -(p->accY);
        else if(MSRCU_MOTION_SENSOR_ACC_Y == -3) sensor->accY = -(p->accZ);
    }
    
    if(MSRCU_MOTION_SENSOR_ACC_Z > 0)
    {
        if     (MSRCU_MOTION_SENSOR_ACC_Z == 1) sensor->accZ = p->accX;
        else if(MSRCU_MOTION_SENSOR_ACC_Z == 2) sensor->accZ = p->accY;
        else if(MSRCU_MOTION_SENSOR_ACC_Z == 3) sensor->accZ = p->accZ;
    }
    else if(MSRCU_MOTION_SENSOR_ACC_Z < 0)
    {
        if     (MSRCU_MOTION_SENSOR_ACC_Z == -1) sensor->accZ = -(p->accX);
        else if(MSRCU_MOTION_SENSOR_ACC_Z == -2) sensor->accZ = -(p->accY);
        else if(MSRCU_MOTION_SENSOR_ACC_Z == -3) sensor->accZ = -(p->accZ);
    }
    
    //gyro
    if(MSRCU_MOTION_SENSOR_GYRO_X > 0)
    {
        if     (MSRCU_MOTION_SENSOR_GYRO_X == 1) sensor->gyroX = p->gyroX;
        else if(MSRCU_MOTION_SENSOR_GYRO_X == 2) sensor->gyroX = p->gyroY;
        else if(MSRCU_MOTION_SENSOR_GYRO_X == 3) sensor->gyroX = p->gyroZ;
    }
    else if(MSRCU_MOTION_SENSOR_GYRO_X < 0)
    {
        if     (MSRCU_MOTION_SENSOR_GYRO_X == -1) sensor->gyroX = -(p->gyroX);
        else if(MSRCU_MOTION_SENSOR_GYRO_X == -2) sensor->gyroX = -(p->gyroY);
        else if(MSRCU_MOTION_SENSOR_GYRO_X == -3) sensor->gyroX = -(p->gyroZ);
    }
    
    if(MSRCU_MOTION_SENSOR_GYRO_Y > 0)
    {
        if     (MSRCU_MOTION_SENSOR_GYRO_Y == 1) sensor->gyroY = p->gyroX;
        else if(MSRCU_MOTION_SENSOR_GYRO_Y == 2) sensor->gyroY = p->gyroY;
        else if(MSRCU_MOTION_SENSOR_GYRO_Y == 3) sensor->gyroY = p->gyroZ;
    }
    else if(MSRCU_MOTION_SENSOR_GYRO_Y < 0)
    {
        if     (MSRCU_MOTION_SENSOR_GYRO_Y == -1) sensor->gyroY = -(p->gyroX);
        else if(MSRCU_MOTION_SENSOR_GYRO_Y == -2) sensor->gyroY = -(p->gyroY);
        else if(MSRCU_MOTION_SENSOR_GYRO_Y == -3) sensor->gyroY = -(p->gyroZ);
    }
    
    if(MSRCU_MOTION_SENSOR_GYRO_Z > 0)
    {
        if     (MSRCU_MOTION_SENSOR_GYRO_Z == 1) sensor->gyroZ = p->gyroX;
        else if(MSRCU_MOTION_SENSOR_GYRO_Z == 2) sensor->gyroZ = p->gyroY;
        else if(MSRCU_MOTION_SENSOR_GYRO_Z == 3) sensor->gyroZ = p->gyroZ;
    }
    else if(MSRCU_MOTION_SENSOR_GYRO_Z < 0)
    {
        if     (MSRCU_MOTION_SENSOR_GYRO_Z == -1) sensor->gyroZ = -(p->gyroX);
        else if(MSRCU_MOTION_SENSOR_GYRO_Z == -2) sensor->gyroZ = -(p->gyroY);
        else if(MSRCU_MOTION_SENSOR_GYRO_Z == -3) sensor->gyroZ = -(p->gyroZ);
    }
    
    if(p)
        free(p);
    
    return ERR_NO_ERROR;
}

static msrcuErr_t msrcu_fw_motion_algorithm_init(void)
{
    bool result;
    
    result = airmouseInit(M_SAMPLE_FREQUENCY, M_ACC_1G_COUNT, M_GYRO_1DS_COUNT, M_SENSITIVITY);
    if(result == false)
        return ERR_OTHERS;
    
    return ERR_NO_ERROR;
}

static msrcuErr_t msrcu_fw_motion_pin_init(void)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500X
    msrcu_dev_gpio_motion_sensor_power_pin_init();
    
#if MSRCU_BMI160_I2C
    err = msrcu_dev_i2c_init();
    if(err)
        return err;
#else
    return ERR_PERIPHERAL;
#endif
   
#else
    return ERR_DEVICE;
#endif
    
    return err;
}

static msrcuErr_t msrcu_fw_motion_sensor_init(void)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
#if MSRCU_BMI160_I2C
    int8_t rslt = BMI160_OK;
    
    //init
    bm160Dev.id = BMI160_I2C_ADDR;
    bm160Dev.interface = BMI160_I2C_INTF;
    bm160Dev.read = (bmi160_com_fptr_t)bmi160_i2c_read;
    bm160Dev.write = (bmi160_com_fptr_t)bmi160_i2c_write;
    bm160Dev.delay_ms = (bmi160_delay_fptr_t)bmi160_delay_ms;
    
    rslt = bmi160_init(&bm160Dev);
    if(rslt)
        return ERR_PERIPHERAL;
    
    //reset
    rslt = bmi160_soft_reset(&bm160Dev);
    if(rslt)
        return ERR_PERIPHERAL;
    
/*    //interrupt config
    struct bmi160_int_settg int_config;
    
    int_config.int_channel = BMI160_INT_CHANNEL_1;// Interrupt channel/pin 1
    
    int_config.int_type = BMI160_ACC_HIGH_G_INT;
    
    int_config.int_pin_settg.output_en = BMI160_ENABLE;// Enabling interrupt pins to act as output pin
    int_config.int_pin_settg.output_mode = BMI160_DISABLE;// Choosing push-pull mode for interrupt pin
    int_config.int_pin_settg.output_type = BMI160_DISABLE;// Choosing active low output
    int_config.int_pin_settg.edge_ctrl = BMI160_ENABLE;// Choosing edge triggered output
    int_config.int_pin_settg.input_en = BMI160_DISABLE;// Disabling interrupt pin to act as input
    int_config.int_pin_settg.latch_dur = BMI160_LATCH_DUR_2_56_SEC;// non-latched output
    
    int_config.int_type_cfg.acc_high_g_int.high_g_x = 0;
    int_config.int_type_cfg.acc_high_g_int.high_g_y = 1;
    int_config.int_type_cfg.acc_high_g_int.high_g_z = 0;
    int_config.int_type_cfg.acc_high_g_int.high_hy = 2;
    int_config.int_type_cfg.acc_high_g_int.high_data_src = 1;
    int_config.int_type_cfg.acc_high_g_int.high_thres = 64;
    int_config.int_type_cfg.acc_high_g_int.high_dur = 9;
    
    rslt = bmi160_set_int_config(&int_config, &bm160Dev);
    if(rslt)
        return ERR_PERIPHERAL;
*/
    
    //acc&gyro config
    bm160Dev.accel_cfg.odr = BMI160_ACCEL_ODR_100HZ;
    bm160Dev.accel_cfg.range = BMI160_ACCEL_RANGE_8G;
    bm160Dev.accel_cfg.bw = BMI160_ACCEL_BW_NORMAL_AVG4;
    bm160Dev.accel_cfg.power = BMI160_ACCEL_SUSPEND_MODE;
    
    bm160Dev.gyro_cfg.odr = BMI160_GYRO_ODR_100HZ;
    bm160Dev.gyro_cfg.range = BMI160_GYRO_RANGE_2000_DPS;
    bm160Dev.gyro_cfg.bw = BMI160_GYRO_BW_NORMAL_MODE; 
    bm160Dev.gyro_cfg.power = BMI160_GYRO_SUSPEND_MODE;
    
    rslt = bmi160_set_sens_conf(&bm160Dev);
    if(rslt)
        return ERR_PERIPHERAL;
    
#else
    return ERR_PERIPHERAL;
#endif
    
    return err;
}

#if MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE
msrcuErr_t msrcu_fw_motion_power_on(void)
{
    return msrcu_dev_gpio_motion_sensor_power_on(); 
}

msrcuErr_t msrcu_fw_motion_power_off(void)
{
    return msrcu_dev_gpio_motion_sensor_power_off();
}

msrcuErr_t msrcu_fw_motion_reinit(void)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
    msrcu_dev_gpio_motion_sensor_power_on();
    
    err = msrcu_fw_motion_sensor_init();
    if(err)
        return err;
        
    msrcu_dev_gpio_motion_sensor_power_off();
    
    isStop = true;
    
    return err;
}
#endif

msrcuErr_t msrcu_fw_motion_init(void)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
    err = msrcu_fw_motion_algorithm_init();
    if(err)
        return err;
    
    err = msrcu_fw_motion_pin_init();
    if(err)
        return err; 
    
#if MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE
    msrcu_dev_gpio_motion_sensor_power_on();
#endif
    
    err = msrcu_fw_motion_sensor_init();
    if(err)
        return err;
        
#if MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE
    msrcu_dev_gpio_motion_sensor_power_off();
#endif
    
    isStop = true;
    
    return err;
}

bool msrcu_fw_motion_is_stop(void)
{
    return isStop;
}

msrcuErr_t msrcu_fw_motion_start(void)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
#if MSRCU_BMI160_I2C
    int8_t rslt = BMI160_OK;
    
    bm160Dev.accel_cfg.power = BMI160_ACCEL_NORMAL_MODE;
    bm160Dev.gyro_cfg.power = BMI160_GYRO_NORMAL_MODE; 
    
    rslt = bmi160_set_sens_conf(&bm160Dev);
    if(rslt)
    {
        MSPRINT("%s bmi160_set error: %d.\r\n", __func__, rslt);
        err = ERR_PERIPHERAL;
    }
    else
        err = ERR_NO_ERROR;
#else
    err = ERR_PERIPHERAL;
#endif
    
    if(err)
        isStop = true;
    else
        isStop = false;
    
    return err;
}

msrcuErr_t msrcu_fw_motion_stop(void)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
#if MSRCU_BMI160_I2C
    int8_t rslt = BMI160_OK;
    
    bm160Dev.accel_cfg.power = BMI160_ACCEL_SUSPEND_MODE;
    bm160Dev.gyro_cfg.power = BMI160_GYRO_SUSPEND_MODE;
    
    rslt = bmi160_set_sens_conf(&bm160Dev);
    if(rslt)
    {
        MSPRINT("%s bmi160_set error: %d.\r\n", __func__, rslt);
        err = ERR_PERIPHERAL;
    }
    else
        err = ERR_NO_ERROR;
#else
    err = ERR_PERIPHERAL;
#endif
    
    if(err)
        isStop = false;
    else
        isStop = true;
    
    return err;
}

msrcuErr_t msrcu_fw_motion_get_data(msrcuMotionAcc_t *acc, msrcuMotionGyro_t *gyro, msrcuMotionMouse_t *mouse)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
    if(isStop)
        return ERR_NOT_SUPPORT;
    
    if(acc == NULL && gyro == NULL && mouse == NULL)
        return ERR_VALID_INPUT;
    
#if MSRCU_BMI160_I2C
    struct bmi160_sensor_data bAcc = {0};
    struct bmi160_sensor_data bGyro = {0};
    amAirMouse_t amD = {0};
    
    //get data from sensor
    if(mouse)
    {
        if(bmi160_get_sensor_data((BMI160_ACCEL_SEL), &bAcc, NULL, &bm160Dev))
            return ERR_PERIPHERAL;
        if(bmi160_get_sensor_data((BMI160_GYRO_SEL), NULL, &bGyro, &bm160Dev))
            return ERR_PERIPHERAL;
        
        amD.sensor.accX = bAcc.x;
        amD.sensor.accY = bAcc.y;
        amD.sensor.accZ = bAcc.z;
        amD.sensor.gyroX = bGyro.x;
        amD.sensor.gyroY = bGyro.y;
        amD.sensor.gyroZ = bGyro.z; 
        
//        MSPRINT("accG: %f %f %f, gyro: %d %d %d.\r\n",
//                amD.sensor.accX/4096.0, amD.sensor.accY/4096.0, amD.sensor.accZ/4096.0,
//                amD.sensor.gyroX, amD.sensor.gyroY, amD.sensor.gyroZ);
        msrcu_fw_motion_sensor_direction_map(&amD.sensor);
//        MSPRINT("accG: %f %f %f, gyro: %d %d %d.\r\n",
//                amD.sensor.accX/4096.0, amD.sensor.accY/4096.0, amD.sensor.accZ/4096.0,
//                amD.sensor.gyroX, amD.sensor.gyroY, amD.sensor.gyroZ);
//        MSPRINT("mouse: %d %d.\r\n", amD.mouse.x, amD.mouse.y);
        
        airmouseConversion(&amD);
    }
    else
    {
        if(acc)
            bmi160_get_sensor_data((BMI160_ACCEL_SEL), &bAcc, NULL, &bm160Dev);
        if(gyro)
            bmi160_get_sensor_data((BMI160_GYRO_SEL), NULL, &bGyro, &bm160Dev);
    }
    
    //output data
    if(acc)
    {
        acc->x = bAcc.x;
        acc->y = bAcc.y;
        acc->z = bAcc.z;
    } 
    if(gyro)
    {
        gyro->x = bGyro.x;
        gyro->y = bGyro.y;
        gyro->z = bGyro.z;
    } 
    if(mouse)
    {
        mouse->x = amD.mouse.x;
        mouse->y = amD.mouse.y;
    }
#else
    return ERR_PERIPHERAL;
#endif
    
    return err;
}

msrcuErr_t msrcu_fw_motion_mouse_hid_send(uint8_t conIndex, msrcuMouseButton_t button, msrcuMotionMouse_t *mouse)
{
    if(BLE_STATE_READY != msrcu_dev_ble_get_state())
        return ERR_NOT_SUPPORT;
    
    msrcuErr_t err = ERR_DEVICE;
    
    msrcuBleHidReport_t report = {0};
    
    report.conIndex = conIndex;
    report.instance = HID_MOUSE_INSTANCE;
    report.length = MOUSE_HID_PKG_SIZE;
    report.data[MOUSE_HID_PKG_KEY_IDX] = button;
    report.data[MOUSE_HID_PKG_X_IDX] = mouse->x;
    report.data[MOUSE_HID_PKG_Y_IDX] = mouse->y;
    
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500X
    err = msrcu_dev_ble_hid_send(&report);
#endif
    
    return err;
}
#endif
