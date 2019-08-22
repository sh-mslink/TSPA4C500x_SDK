/**
 ****************************************************************************************
 *
 * @file msrcu_config.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
#ifndef MSRCU_CONFIG_H
#define MSRCU_CONFIG_H

/* Include Files
 ****************************************************************************************
 */
#include "in_config.h"

/* Macro Definition
 ****************************************************************************************
 */
#ifdef BOARD_TSPA4C500A_REMOTER
/****************************************************************/
///MSRCU device chip part name
#define MSRCU_DEV_NULL              (0)
#define MSRCU_DEV_TSPA4C500A        (1)//Tropos: TSPA4C500A
//#define MSRCU_DEV_TSPA4C500B        (1)//Tropos: TSPA4C500B
#define MSRCU_DEV_MAX               (1)
/****************************************************************/


///Device parameters
#define MSRCU_DEV                   MSRCU_DEV_TSPA4C500A//MSRCU device chip selection

///Functions enable
#define MSRCU_VOICE_ENABLE          (1)//Enable voice functions
#define MSRCU_MOTION_ENABLE         (1)//Enable motion functions
#define MSRCU_IR_SEND_ENABLE        (1)//Enable IR send functions
#define MSRCU_IR_LEARN_ENABLE       (1)//Enable IR learn functions

///BLE parameters
#define MSRCU_BLE_ADV_INTERVAL_MIN  (0x0020)//unit: 0.625ms, range: 20ms(0x0020)~10.24s(0x4000)
#define MSRCU_BLE_ADV_INTERVAL_MAX  (0x0020)//unit: 0.625ms, range: 20ms(0x0020)~10.24s(0x4000)
#define MSRCU_BLE_ADV_DURATION      (30000)//unit: 1ms
#define MSRCU_BLE_CNT_INTERVAL_MIN  (0x0006)//unit: 1.25ms, range: 7.5ms(0x0006)~4000ms(0x0C80)
#define MSRCU_BLE_CNT_INTERVAL_MAX  (0x0006)//unit: 1.25ms, range: 7.5ms(0x0006)~4000ms(0x0C80)
#define MSRCU_BLE_CNT_LATENCY       (49)//0~499
#define MSRCU_BLE_CNT_TIMEOUT       (250)//unit: 10ms, range: 10ms(0x000A)~32000ms(0x0C80)

#define MSRCU_BLE_DIRECT_ADV_ENABLE (1)//Use direct adv after bonded
#if MSRCU_VOICE_ENABLE
#define MSRCU_BLE_VOICE_ATV_ENABLE  (1)//Use ATV Voice Service
#endif

//Power parameters
#define MSRCU_POWER_BAT_SAMPLE_INTERVAL (3600000)//ms
#define MSRCU_POWER_BAT_MV_LOW      (2200)//mV
#define MSRCU_POWER_BAT_MV_EMPTY    (1900)//mV

///LED parameters
#define MSRCU_LED_KEY_PRESS_ON_TIME     (100)//ms
#define MSRCU_LED_POWER_LOW_ON_TIME     (500)//ms
#define MSRCU_LED_POWER_LOW_OFF_TIME    (500)//ms
#define MSRCU_LED_POWER_LOW_DURATION    (3000)//ms
#define MSRCU_LED_POWER_EMPTY_ON_TIME   (250)//ms
#define MSRCU_LED_POWER_EMPTY_OFF_TIME  (250)//ms
#define MSRCU_LED_POWER_EMPTY_DURATION  (3000)//ms
#define MSRCU_LED_BOND_START_ON_TIME    (250)//ms
#define MSRCU_LED_BOND_START_OFF_TIME   (250)//ms
#define MSRCU_LED_BOND_START_DURATION   (60000)//ms
#define MSRCU_LED_BOND_SUCCESS_ON_TIME  (3000)//ms
#define MSRCU_LED_BOND_FAIL_ON_TIME     (3000)//ms
#define MSRCU_LED_BOND_CLEAR_ON_TIME    (250)//ms
#define MSRCU_LED_BOND_CLEAR_OFF_TIME   (250)//ms
#define MSRCU_LED_BOND_CLEAR_DURATION   (3000)//ms

///Key parameters
#define MSRCU_KEY_MATRIX_ROW_NB     (3)//Matrix key row number
#define MSRCU_KEY_MATRIX_COL_NB     (5)//Matrix key column number
#define MSRCU_KEY_LONGPRESS_TIME_BONDSTART  (3000)//ms
#define MSRCU_KEY_LONGPRESS_TIME_BONDCLEAR  (3000)//ms

///Motion parameters
#if MSRCU_MOTION_ENABLE
    #define MSRCU_BMI160_I2C            (1)//Bosch: BMI160 with I2C interface
    #define MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE   (1)
    //#define MSRCU_MOTION_SENSOR_INTERRUPT_ENABLE    (0)
    #define MSRCU_MOTION_SENSOR_ACC_X   (2)//(1 X)(-1 -X)(2 Y)(-2 -Y)(3 Z)(-3 -Z) 
    #define MSRCU_MOTION_SENSOR_ACC_Y   (-1)//(1 X)(-1 -X)(2 Y)(-2 -Y)(3 Z)(-3 -Z)
    #define MSRCU_MOTION_SENSOR_ACC_Z   (-3)//(1 X)(-1 -X)(2 Y)(-2 -Y)(3 Z)(-3 -Z)  
    #define MSRCU_MOTION_SENSOR_GYRO_X  (2)//(1 X)(-1 -X)(2 Y)(-2 -Y)(3 Z)(-3 -Z) 
    #define MSRCU_MOTION_SENSOR_GYRO_Y  (-1)//(1 X)(-1 -X)(2 Y)(-2 -Y)(3 Z)(-3 -Z)
    #define MSRCU_MOTION_SENSOR_GYRO_Z  (-3)//(1 X)(-1 -X)(2 Y)(-2 -Y)(3 Z)(-3 -Z)   
#endif
       
///IR parameters       
#if (MSRCU_IR_SEND_ENABLE || MSRCU_IR_LEARN_ENABLE)
    #define MSRCU_IR_CMD_NB             (3)//The number of ir send cmd 
    #define MSRCU_IR_NEC_CARRIER_DUTY_RATIO (25)//1~99, recommended 25~33
    #define MSRCU_IR_NEC_ADD_L          (0xAA)//Extended NEC protocol address lower byte
    #define MSRCU_IR_NEC_ADD_H          (0x55)//Extended NEC protocol address higher byte
    #define MSRCU_IR_LEARN_NB           (4)//The number of ir learn code could be stored
#endif
  
///Device peripheral configuration
#define MSRCU_DEV_LED_0_GPIO_PORT       (2)
#define MSRCU_DEV_LED_0_GPIO_PIN        (1)
#define MSRCU_DEV_LED_0_ON_LEVEL        (0)//0 for low level, 1 for high level
#define MSRCU_DEV_LED_1_GPIO_PORT       (2)
#define MSRCU_DEV_LED_1_GPIO_PIN        (6)//no pin in TSPA4C500A
#define MSRCU_DEV_LED_1_ON_LEVEL        (0)//0 for low level, 1 for high level
#define MSRCU_DEV_LED_2_GPIO_PORT       (2)
#define MSRCU_DEV_LED_2_GPIO_PIN        (6)//no pin in TSPA4C500A
#define MSRCU_DEV_LED_2_ON_LEVEL        (0)//0 for low level, 1 for high level

#if MSRCU_VOICE_ENABLE
#define MSRCU_DEV_MIC_POWER_USE_VDDIO_SENSOR    (1)
#if (!MSRCU_DEV_MIC_POWER_USE_VDDIO_SENSOR)
#define MSRCU_DEV_MIC_POWER_GPIO_PORT   (3)
#define MSRCU_DEV_MIC_POWER_GPIO_PIN    (5)
#define MSRCU_DEV_MIC_POWER_ON_LEVEL    (0)//0 for low level, 1 for high level
#endif
#endif

#if MSRCU_MOTION_ENABLE
#if MSRCU_BMI160_I2C
#define MSRCU_DEV_MOTION_I2C_CHANNEL            (0)
#endif
#if MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE
#define MSRCU_DEV_MOTION_SENSOR_POWER_GPIO_PORT (1)
#define MSRCU_DEV_MOTION_SENSOR_POWER_GPIO_PIN  (8)
#define MSRCU_DEV_MOTION_SENSOR_POWER_ON_LEVEL  (0)//0 for low level, 1 for high level
#endif
//#if MSRCU_MOTION_SENSOR_INTERRUPT_ENABLE
//#define MSRCU_DEV_MOTION_SENSOR_INT_GPIO_PORT   (0)
//#define MSRCU_DEV_MOTION_SENSOR_INT_GPIO_PIN    (0)
//#define MSRCU_DEV_MOTION_SENSOR_INT_TRIG_LEVEL  (0)//0 for low level, 1 for high level
//#endif
#endif

#if MSRCU_IR_SEND_ENABLE
#define MSRCU_DEV_IR_SEND_GPIO_PORT (2)
#define MSRCU_DEV_IR_SEND_GPIO_PIN  (4)
#endif

#if MSRCU_IR_LEARN_ENABLE
#define MSRCU_DEV_IR_LEARN_GPIO_PORT        (2)
#define MSRCU_DEV_IR_LEARN_GPIO_PIN         (7)
#define MSRCU_DEV_IR_LEARN_CTRL_GPIO_PORT   (4)
#define MSRCU_DEV_IR_LEARN_CTRL_GPIO_PIN    (1)
#define MSRCU_DEV_IR_LEARN_CTRL_ON_LEVEL    (0)//0 for low level, 1 for high level
#endif


//Task size
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500A
    #define MSRCU_DEV_KEYBOARD_TASK_SIZE    (1024)
    #define MSRCU_DEV_AUDIO_TASK_SIZE       (2048)
    #define MSRCU_DEV_IR_TASK_SIZE          (512)
#endif

/* Enum Definition
 ****************************************************************************************
 */
enum
{
    KEY_CODE_NULL       = 0,
    KEY_CODE_MOTION     = 1,
    KEY_CODE_POWER      = 2,
//    KEY_CODE_           = 3,
    KEY_CODE_VOLUP      = 4,
    KEY_CODE_VOLDOWN    = 5, 
    KEY_CODE_VOICE      = 6,
    KEY_CODE_RIGHT      = 7, 
    KEY_CODE_LEFT       = 8,
    KEY_CODE_ENTER      = 9,
    KEY_CODE_MUTE       = 10,
    KEY_CODE_HOME       = 11,
    KEY_CODE_UP         = 12, 
    KEY_CODE_MENU       = 13,
    KEY_CODE_BACK       = 14,
    KEY_CODE_DOWN       = 15, 
};

//Low byte for USAGE_PAGE Keyboard
//High byte for USAGE_PAGE Consumer Devices
//Related to HID Report Map
typedef enum
{    
    HID_KEYCODE_NULL    = 0x0000,
    HID_KEYCODE_POWER   = 0x0001,
    HID_KEYCODE_UP      = 0x0002,
    HID_KEYCODE_DOWN    = 0x0003,
    HID_KEYCODE_LEFT    = 0x0004,
    HID_KEYCODE_RIGHT   = 0x0005,
    HID_KEYCODE_ENTER   = 0x0006,
    HID_KEYCODE_BACK    = 0x0007,
    HID_KEYCODE_VOLUP   = 0x0008,
    HID_KEYCODE_VOLDOWN = 0x0009,
    HID_KEYCODE_SEARCH  = 0x0100,
    HID_KEYCODE_HOME    = 0x0200,
    HID_KEYCODE_MUTE    = 0x0300,
    HID_KEYCODE_MENU    = 0x0400,
}hidKeycode_t;

#if MSRCU_IR_SEND_ENABLE 
typedef enum
{
    IR_CMD_NULL     = 0x00,
    IR_CMD_MOTION   = 0x11,
    IR_CMD_POWER    = 0x22,
    IR_CMD_VOLUP    = 0x33,
    IR_CMD_VOLDOWN  = 0x44, 
    IR_CMD_VOICE    = 0x55,
    IR_CMD_RIGHT    = 0x66, 
    IR_CMD_LEFT     = 0x77,
    IR_CMD_ENTER    = 0x88,
    IR_CMD_MUTE     = 0x99,
    IR_CMD_HOME     = 0xAA,
    IR_CMD_UP       = 0xBB, 
    IR_CMD_MENU     = 0xCC,
    IR_CMD_BACK     = 0xDD,
    IR_CMD_DOWN     = 0xEE, 
}irCmd_t;
#endif
#endif//BOARD_TSPA4C500A_REMOTER


#ifdef BOARD_TSPA4C500A_EVB_BONE
/****************************************************************/
///MSRCU device chip part name
#define MSRCU_DEV_NULL              (0)
#define MSRCU_DEV_TSPA4C500A        (1)//Tropos: TSPA4C500A
//#define MSRCU_DEV_TSPA4C500B        (1)//Tropos: TSPA4C500B
#define MSRCU_DEV_MAX               (1)
/****************************************************************/


///Device parameters
#define MSRCU_DEV                   MSRCU_DEV_TSPA4C500A//MSRCU device chip selection

///Functions enable
#define MSRCU_VOICE_ENABLE          (1)//Enable voice functions
#define MSRCU_MOTION_ENABLE         (1)//Enable motion functions
#define MSRCU_IR_SEND_ENABLE        (1)//Enable IR send functions
#define MSRCU_IR_LEARN_ENABLE       (1)//Enable IR learn functions

///BLE parameters
#define MSRCU_BLE_ADV_INTERVAL_MIN  (0x0020)//unit: 0.625ms, range: 20ms(0x0020)~10.24s(0x4000)
#define MSRCU_BLE_ADV_INTERVAL_MAX  (0x0020)//unit: 0.625ms, range: 20ms(0x0020)~10.24s(0x4000)
#define MSRCU_BLE_ADV_DURATION      (30000)//unit: 1ms
#define MSRCU_BLE_CNT_INTERVAL_MIN  (0x0006)//unit: 1.25ms, range: 7.5ms(0x0006)~4000ms(0x0C80)
#define MSRCU_BLE_CNT_INTERVAL_MAX  (0x0006)//unit: 1.25ms, range: 7.5ms(0x0006)~4000ms(0x0C80)
#define MSRCU_BLE_CNT_LATENCY       (49)//0~499
#define MSRCU_BLE_CNT_TIMEOUT       (250)//unit: 10ms, range: 10ms(0x000A)~32000ms(0x0C80)

#define MSRCU_BLE_DIRECT_ADV_ENABLE (1)//Use direct adv after bonded
#if MSRCU_VOICE_ENABLE
#define MSRCU_BLE_VOICE_ATV_ENABLE  (1)//Use ATV Voice Service
#endif

///Power parameters
#define MSRCU_POWER_BAT_SAMPLE_INTERVAL (3600000)//ms
#define MSRCU_POWER_BAT_MV_LOW          (2200)//mV
#define MSRCU_POWER_BAT_MV_EMPTY        (1900)//mV

///LED parameters
#define MSRCU_LED_KEY_PRESS_ON_TIME     (100)//ms
#define MSRCU_LED_POWER_LOW_ON_TIME     (500)//ms
#define MSRCU_LED_POWER_LOW_OFF_TIME    (500)//ms
#define MSRCU_LED_POWER_LOW_DURATION    (3000)//ms
#define MSRCU_LED_POWER_EMPTY_ON_TIME   (250)//ms
#define MSRCU_LED_POWER_EMPTY_OFF_TIME  (250)//ms
#define MSRCU_LED_POWER_EMPTY_DURATION  (3000)//ms
#define MSRCU_LED_BOND_START_ON_TIME    (250)//ms
#define MSRCU_LED_BOND_START_OFF_TIME   (250)//ms
#define MSRCU_LED_BOND_START_DURATION   (60000)//ms
#define MSRCU_LED_BOND_SUCCESS_ON_TIME  (3000)//ms
#define MSRCU_LED_BOND_FAIL_ON_TIME     (3000)//ms
#define MSRCU_LED_BOND_CLEAR_ON_TIME    (250)//ms
#define MSRCU_LED_BOND_CLEAR_OFF_TIME   (250)//ms
#define MSRCU_LED_BOND_CLEAR_DURATION   (3000)//ms

///Key parameters
#define MSRCU_KEY_MATRIX_ROW_NB     (3)//Matrix key row number
#define MSRCU_KEY_MATRIX_COL_NB     (5)//Matrix key column number
#define MSRCU_KEY_LONGPRESS_TIME_BONDSTART  (3000)//ms
#define MSRCU_KEY_LONGPRESS_TIME_BONDCLEAR  (3000)//ms

///Motion parameters
#if MSRCU_MOTION_ENABLE
    #define MSRCU_BMI160_I2C            (1)//Bosch: BMI160 with I2C interface
    #define MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE   (1)
    //#define MSRCU_MOTION_SENSOR_INTERRUPT_ENABLE    (0)
    #define MSRCU_MOTION_SENSOR_ACC_X   (1)//(1 X)(-1 -X)(2 Y)(-2 -Y)(3 Z)(-3 -Z) 
    #define MSRCU_MOTION_SENSOR_ACC_Y   (2)//(1 X)(-1 -X)(2 Y)(-2 -Y)(3 Z)(-3 -Z)
    #define MSRCU_MOTION_SENSOR_ACC_Z   (3)//(1 X)(-1 -X)(2 Y)(-2 -Y)(3 Z)(-3 -Z)  
    #define MSRCU_MOTION_SENSOR_GYRO_X  (1)//(1 X)(-1 -X)(2 Y)(-2 -Y)(3 Z)(-3 -Z) 
    #define MSRCU_MOTION_SENSOR_GYRO_Y  (2)//(1 X)(-1 -X)(2 Y)(-2 -Y)(3 Z)(-3 -Z)
    #define MSRCU_MOTION_SENSOR_GYRO_Z  (3)//(1 X)(-1 -X)(2 Y)(-2 -Y)(3 Z)(-3 -Z)    
#endif
       
///IR parameters       
#if (MSRCU_IR_SEND_ENABLE || MSRCU_IR_LEARN_ENABLE)
    #define MSRCU_IR_CMD_NB             (3)//The number of ir send cmd 
    #define MSRCU_IR_NEC_CARRIER_DUTY_RATIO (25)//1~99, recommended 25~33
    #define MSRCU_IR_NEC_ADD_L          (0xAA)//Extended NEC protocol address lower byte
    #define MSRCU_IR_NEC_ADD_H          (0x55)//Extended NEC protocol address higher byte
    #define MSRCU_IR_LEARN_NB           (4)//The number of ir learn code could be stored
#endif

///Device peripheral configuration
#define MSRCU_DEV_LED_0_GPIO_PORT       (0)
#define MSRCU_DEV_LED_0_GPIO_PIN        (1)
#define MSRCU_DEV_LED_0_ON_LEVEL        (0)//0 for low level, 1 for high level
#define MSRCU_DEV_LED_1_GPIO_PORT       (2)
#define MSRCU_DEV_LED_1_GPIO_PIN        (0)
#define MSRCU_DEV_LED_1_ON_LEVEL        (0)//0 for low level, 1 for high level
#define MSRCU_DEV_LED_2_GPIO_PORT       (1)
#define MSRCU_DEV_LED_2_GPIO_PIN        (8)
#define MSRCU_DEV_LED_2_ON_LEVEL        (0)//0 for low level, 1 for high level

#if MSRCU_VOICE_ENABLE
#define MSRCU_DEV_MIC_POWER_USE_VDDIO_SENSOR    (1)
#if (!MSRCU_DEV_MIC_POWER_USE_VDDIO_SENSOR)
#define MSRCU_DEV_MIC_POWER_GPIO_PORT   (3)
#define MSRCU_DEV_MIC_POWER_GPIO_PIN    (5)
#define MSRCU_DEV_MIC_POWER_ON_LEVEL    (0)//0 for low level, 1 for high level
#endif
#endif

#if MSRCU_MOTION_ENABLE
#if MSRCU_BMI160_I2C
#define MSRCU_DEV_MOTION_I2C_CHANNEL            (1)
#endif
#if MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE
#define MSRCU_DEV_MOTION_SENSOR_POWER_GPIO_PORT (0)
#define MSRCU_DEV_MOTION_SENSOR_POWER_GPIO_PIN  (5)
#define MSRCU_DEV_MOTION_SENSOR_POWER_ON_LEVEL  (0)//0 for low level, 1 for high level
#endif
//#if MSRCU_MOTION_SENSOR_INTERRUPT_ENABLE
//#define MSRCU_DEV_MOTION_SENSOR_INT_GPIO_PORT   (1)
//#define MSRCU_DEV_MOTION_SENSOR_INT_GPIO_PIN    (0)
//#define MSRCU_DEV_MOTION_SENSOR_INT_TRIG_LEVEL  (0)//0 for low level, 1 for high level
//#endif
#endif

#if MSRCU_IR_SEND_ENABLE
#define MSRCU_DEV_IR_SEND_GPIO_PORT (2)
#define MSRCU_DEV_IR_SEND_GPIO_PIN  (4)
#endif

#if MSRCU_IR_LEARN_ENABLE
#define MSRCU_DEV_IR_LEARN_GPIO_PORT        (2)
#define MSRCU_DEV_IR_LEARN_GPIO_PIN         (7)
#define MSRCU_DEV_IR_LEARN_CTRL_GPIO_PORT   (4)
#define MSRCU_DEV_IR_LEARN_CTRL_GPIO_PIN    (1)
#define MSRCU_DEV_IR_LEARN_CTRL_ON_LEVEL    (0)//0 for low level, 1 for high level
#endif


//Task size  
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500A
    #define MSRCU_DEV_KEYBOARD_TASK_SIZE    (1024) 
    #define MSRCU_DEV_AUDIO_TASK_SIZE       (2048)
    #define MSRCU_DEV_IR_TASK_SIZE          (512)
#endif

/* Enum Definition
 ****************************************************************************************
 */
enum
{
    KEY_CODE_NULL       = 0,
    KEY_CODE_VOLDOWN    = 1,
    KEY_CODE_UP         = 2,
    KEY_CODE_LEFT       = 3,
    KEY_CODE_MOTION     = 4,
    KEY_CODE_DOWN       = 5, 
    KEY_CODE_RIGHT      = 6,
    KEY_CODE_MUTE       = 7, 
    KEY_CODE_POWER      = 8,
    KEY_CODE_USER       = 9,
    KEY_CODE_ENTER      = 10,
    KEY_CODE_BACK       = 11,
    KEY_CODE_VOICE      = 12, 
    KEY_CODE_MENU       = 13,
    KEY_CODE_HOME       = 14,
    KEY_CODE_VOLUP      = 15, 
};

//Low byte for USAGE_PAGE Keyboard
//High byte for USAGE_PAGE Consumer Devices
//Related to HID Report Map
typedef enum
{    
    HID_KEYCODE_NULL    = 0x0000,
    HID_KEYCODE_POWER   = 0x0001,
    HID_KEYCODE_UP      = 0x0002,
    HID_KEYCODE_DOWN    = 0x0003,
    HID_KEYCODE_LEFT    = 0x0004,
    HID_KEYCODE_RIGHT   = 0x0005,
    HID_KEYCODE_ENTER   = 0x0006,
    HID_KEYCODE_BACK    = 0x0007,
    HID_KEYCODE_VOLUP   = 0x0008,
    HID_KEYCODE_VOLDOWN = 0x0009,
    HID_KEYCODE_SEARCH  = 0x0100,
    HID_KEYCODE_HOME    = 0x0200,
    HID_KEYCODE_MUTE    = 0x0300,
    HID_KEYCODE_MENU    = 0x0400,
}hidKeycode_t;

#if MSRCU_IR_SEND_ENABLE 
typedef enum
{
    IR_CMD_NULL     = 0x00,
    IR_CMD_MOTION   = 0x11,
    IR_CMD_POWER    = 0x22,
    IR_CMD_VOLUP    = 0x33,
    IR_CMD_VOLDOWN  = 0x44, 
    IR_CMD_VOICE    = 0x55,
    IR_CMD_RIGHT    = 0x66, 
    IR_CMD_LEFT     = 0x77,
    IR_CMD_ENTER    = 0x88,
    IR_CMD_MUTE     = 0x99,
    IR_CMD_HOME     = 0xAA,
    IR_CMD_UP       = 0xBB, 
    IR_CMD_MENU     = 0xCC,
    IR_CMD_BACK     = 0xDD,
    IR_CMD_DOWN     = 0xEE, 
}irCmd_t;
#endif
#endif //BOARD_TSPA4C500A_EVB_BONE


/* Struct Definition
 ****************************************************************************************
 */
typedef struct
{
    unsigned char enVoice;
    unsigned char enMotion;
    unsigned char enIrSend;
    unsigned char enIrLearn;
}
msrcuEnv_t;

/* Global Variable
 ****************************************************************************************
 */ 
extern msrcuEnv_t msrcuEnv;

/* Function Declaration
 ****************************************************************************************
 */
hidKeycode_t msrcuKeycodeToHidKeycode(unsigned char keycode, unsigned char multiIdx);
#if MSRCU_IR_SEND_ENABLE
irCmd_t msrcuKeycodeToIrCmd(unsigned char keycode);
#endif 
#endif
