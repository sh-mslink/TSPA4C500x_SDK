/**
 ****************************************************************************************
 *
 * @file main.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */
 
/* Include Files
 ****************************************************************************************
 */
#include "in_config.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "in_arm.h"
#include "in_debug.h"
#include "inb_config.h"
#include "inb_plt.h"
#include "rf_int.h"
#include "hal_global.h"
#include "hal_flash.h"

#include "cmsis_os.h"

#include "msg.h"
#include "ble_app.h"
#include "ble_evt.h"

#include "msrcu_app.h"

/* Macro Definition
 ****************************************************************************************
 */

#define LED_R   0
#define LED_G   1
#define LED_B   2

#if MSRCU_MOTION_ENABLE
#define MOTION_TIMER_MS     (1000 / M_SAMPLE_FREQUENCY)
#endif

#define BOND_DATA_FLASH_OFFSET  (0x7D000)

/* Enum Definition
 ****************************************************************************************
 */

/* Struct Definition
 ****************************************************************************************
 */

/* Function Declaration
 ****************************************************************************************
 */
extern void msrcu_dev_ble_evt_cb(inb_evt_t *evt);

static void user_rcu_power_timer_callback(void const *arg);
static void user_rcu_longpress_timer_callback(void const *arg);
static void user_rcu_led_timer_callback(void const *arg);
static void user_rcu_rf_test_timer_callback(void const *arg);
static void user_rcu_adv_timer_callback(void const *arg);
static void user_rcu_connect_timer_callback(void const *arg);
static void user_rcu_bond_timer_callback(void const *arg);
#if MSRCU_MOTION_ENABLE
static void user_rcu_motion_timer_callback(void const *arg);
#endif

static msrcuErr_t user_rcu_ble_bond_data_clear(msrcuBleBondData_t* data);
static msrcuErr_t user_rcu_ble_adv_start(void);
static msrcuErr_t user_rcu_ble_adv_stop(void);


/* Global Variable
 ****************************************************************************************
 */
msrcuBleBondData_t msrcuBondData = {0};
static msrcuAppCallback_t userAppCb = {0};

static msrcuPowerSt userPowerState = POWER_STATE_NORMAL;
static osTimerId msrcuAppPowerTimerId;
static osTimerDef(msrcuAppPowerTimer, user_rcu_power_timer_callback);

static int userLongpressDuration = 0;
static osTimerId msrcuAppLongpressTimerId;
static osTimerDef(msrcuAppLongpressTimer, user_rcu_longpress_timer_callback);

static msrcuLedSt userLedSt = LED_STATE_NULL;
static int userLedDuration = 0;
static osTimerId msrcuAppLedTimerId;
static osTimerDef(msrcuAppLedTimer, user_rcu_led_timer_callback);
static msrcuErr_t user_rcu_led_set(msrcuLedSt newSt);

static osTimerId msrcuAppRfTestTimerId;
static osTimerDef(msrcuAppRfTestTimer, user_rcu_rf_test_timer_callback);

static osTimerId msrcuAppAdvTimerId;
static osTimerDef(msrcuAppAdvTimer, user_rcu_adv_timer_callback);

static osTimerId msrcuAppConnectTimerId;
static osTimerDef(msrcuAppConnectTimer, user_rcu_connect_timer_callback);

static bool userBondEnable = false;
static osTimerId msrcuAppBondTimerId;
static osTimerDef(msrcuAppBondTimer, user_rcu_bond_timer_callback);

#if MSRCU_VOICE_ENABLE
static bool userVoiceIsStop = true;
#endif

#if MSRCU_MOTION_ENABLE
bool userMotionIsStop = true;
bool userMotionIsPause = false;
static msrcuMouseButton_t userMouseButton = MOUSE_BUTTON_NULL;
osTimerId msrcuAppMotionTimerId;
osTimerDef(msrcuAppMotionTimer, user_rcu_motion_timer_callback);
#endif

#if MSRCU_IR_SEND_ENABLE
static bool userIrSendIsStop = true;
static msrcuIrCode_t userIrCode;
#endif

#if MSRCU_IR_LEARN_ENABLE
static bool userIrLearnIsStop = true;
#endif

/* Function Definition
 ****************************************************************************************
 */
static int handle_main_msg(msg_t *msg)
{
    switch(msg->msgId)
    {
#if CFG_PRF_HOGPD_EN
        case MSG_HOGPD_NTF_SEND:
            {
                msg_hogpd_ntf_send_t *p = (msg_hogpd_ntf_send_t *)msg;
                int err = inb_hogpd_report_upd_req(p->conIdx, &p->report);
                if(err)
                    MSPRINT("inb_hogpd_report_upd_req error: 0x%X\r\n", err);
            }
            break;
#endif
            
        default:
            break;
    }
    
    return 0;
}

#if MSRCU_MOTION_ENABLE
static void user_rcu_motion_timer_callback(void const *arg)
{
    if(!userMotionIsStop && BLE_STATE_READY == msrcu_app_ble_get_state())
    {
        msrcuMotionMouse_t *mouse = malloc(sizeof(msrcuMotionMouse_t));
        if(!mouse)
        {
            MSPRINT("%s no memory.\r\n", __func__);
            return;
        }
        if(!msrcu_app_motion_get_data(NULL, NULL, mouse))
        {
            //MSPRINT("x %d,y %d\r\n", mouse->x, mouse->y);
            if(mouse->x || mouse->y)//mouse move
                msrcu_app_motion_mouse_hid_send(userMouseButton, mouse);
        }
        else
            MSPRINT("Motion get data error.\r\n");
        
        if(mouse)
            free(mouse);
    }
}
#endif

static void user_rcu_power_update_battery_level(void)
{
    uint16_t batMv = 0;
    uint32_t pct = 0;
    int err;
    
    err = msrcu_app_power_bat_voltage_get(&batMv);
    if(!err)
    {
        pct = 100 * (batMv - MSRCU_POWER_BAT_MV_EMPTY) / (3000 - MSRCU_POWER_BAT_MV_EMPTY);
        if(pct > 100)
            pct = 100;
        MSPRINT("Battery: %dmV, %d%%\r\n", batMv, pct);
    }
    else
    {
        MSPRINT("Battery voltage get error: %d\r\n", err);
        return;
    }
    
    if(batMv < MSRCU_POWER_BAT_MV_EMPTY)
    {
        userPowerState = POWER_STATE_EMPTY;
        MSPRINT("Battery power empty!!!\r\n");
    }
    else if(batMv < MSRCU_POWER_BAT_MV_LOW)
    {
        userPowerState = POWER_STATE_LOW;
        MSPRINT("Battery power low!\r\n");
    }
    else
        userPowerState = POWER_STATE_NORMAL;
    
    if(BLE_STATE_READY == msrcu_app_ble_get_state())
    {
        err = inb_bass_batt_level_upd_req(BLE_CON_IDX, 0, pct);
        if(!err)
            MSPRINT("Battery level update: %d%%\r\n", pct);
        else
            MSPRINT("Battery level update error: 0x%02X\r\n", err);
    }
}

static void user_rcu_power_timer_callback(void const *arg)
{
    user_rcu_power_update_battery_level();
}

static void user_rcu_led_all_off(void)
{
    msrcu_app_led_off(LED_R);
    msrcu_app_led_off(LED_G);
    msrcu_app_led_off(LED_B);
}

static void user_rcu_led_timer_callback(void const *arg)
{
    switch(userLedSt)
    {
        case LED_STATE_KEY_PRESS:
        case LED_STATE_KEY_RELEASE:
            userLedDuration = 0;
            break;
        
        case LED_STATE_POWER_LOW:
            {
                if(msrcu_app_led_is_on(LED_R))
                {
                    userLedDuration -= MSRCU_LED_POWER_LOW_ON_TIME;
                    if(userLedDuration)
                    {
                        msrcu_app_led_off(LED_R);
                        osTimerStart(msrcuAppLedTimerId, MSRCU_LED_POWER_LOW_OFF_TIME);
                    }
                }
                else
                {
                    userLedDuration -= MSRCU_LED_POWER_LOW_OFF_TIME;
                    if(userLedDuration)
                    {
                        msrcu_app_led_on(LED_R);
                        osTimerStart(msrcuAppLedTimerId, MSRCU_LED_POWER_LOW_ON_TIME);
                    }
                }
            }
            break;
        
        case LED_STATE_POWER_EMPTY:
            {
                if(msrcu_app_led_is_on(LED_R))
                {
                    userLedDuration -= MSRCU_LED_POWER_EMPTY_ON_TIME;
                    if(userLedDuration)
                    {
                        msrcu_app_led_off(LED_R);
                        osTimerStart(msrcuAppLedTimerId, MSRCU_LED_POWER_EMPTY_OFF_TIME);
                    }
                }
                else
                {
                    userLedDuration -= MSRCU_LED_POWER_EMPTY_OFF_TIME;
                    if(userLedDuration)
                    {
                        msrcu_app_led_on(LED_R);
                        osTimerStart(msrcuAppLedTimerId, MSRCU_LED_POWER_EMPTY_ON_TIME);
                    }
                }
            }
            break;
        
        case LED_STATE_FUNC_VOICE_START:
        case LED_STATE_FUNC_VOICE_STOP:
        case LED_STATE_FUNC_MOTION_START:
        case LED_STATE_FUNC_MOTION_STOP:
            userLedDuration = 0;
            break;
            
        case LED_STATE_BOND_START:
            {
                if(msrcu_app_led_is_on(LED_R))
                {
                    userLedDuration -= MSRCU_LED_BOND_START_ON_TIME;
                    if(userLedDuration)
                    {
                        msrcu_app_led_off(LED_R);
                        osTimerStart(msrcuAppLedTimerId, MSRCU_LED_BOND_START_OFF_TIME);
                    }
                }
                else
                {
                    userLedDuration -= MSRCU_LED_BOND_START_OFF_TIME;
                    if(userLedDuration)
                    {
                        msrcu_app_led_on(LED_R);
                        osTimerStart(msrcuAppLedTimerId, MSRCU_LED_BOND_START_ON_TIME);
                    }
                }
            }
            break;
        
        case LED_STATE_BOND_SUCCESS:
        case LED_STATE_BOND_FAIL:
            userLedDuration = 0;
            break;
        
        case LED_STATE_BOND_CLEAR:
            {
                if(msrcu_app_led_is_on(LED_R))
                {
                    userLedDuration -= MSRCU_LED_BOND_CLEAR_ON_TIME;
                    if(userLedDuration)
                    {
                        msrcu_app_led_off(LED_R);
                        msrcu_app_led_on(LED_B);
                        osTimerStart(msrcuAppLedTimerId, MSRCU_LED_BOND_CLEAR_OFF_TIME);
                    }
                }
                else
                {
                    userLedDuration -= MSRCU_LED_BOND_CLEAR_OFF_TIME;
                    if(userLedDuration)
                    {
                        msrcu_app_led_off(LED_B);
                        msrcu_app_led_on(LED_R);
                        osTimerStart(msrcuAppLedTimerId, MSRCU_LED_BOND_CLEAR_ON_TIME);
                    }
                }
            }
            break;
        
        case LED_STATE_IR_LEARN_START:
        case LED_STATE_IR_LEARN_SUCCESS:
        case LED_STATE_IR_LEARN_FAIL:
        default:
            userLedDuration = 0;
            break;
    }
    
    if(userLedDuration <= 0)
    {
        userLedDuration = 0;
        osTimerStop(msrcuAppLedTimerId);
        user_rcu_led_set(LED_STATE_NULL);
    }
}

static msrcuErr_t user_rcu_led_set(msrcuLedSt newSt)
{
    if(newSt != LED_STATE_NULL)
    {
        //function check
        if((newSt & LED_STATE_FUNCTION_MASK) == 0)
            return ERR_VALID_INPUT;
    
        //priority check
        if((newSt & LED_STATE_PRIORITY_MASK) < (userLedSt & LED_STATE_PRIORITY_MASK))
            return ERR_NOT_SUPPORT;
    }
    
    userLedDuration = 0;
    osTimerStop(msrcuAppLedTimerId);
    user_rcu_led_all_off();
    
    //MSPRINT("LED set state: 0x%02X.\r\n", newSt);
    
    switch(newSt)
    {
        case LED_STATE_NULL:
            {
                user_rcu_led_all_off();
            }
            break;
            
        case LED_STATE_KEY_PRESS:
            {
                if(BLE_STATE_READY == msrcu_app_ble_get_state())
                    msrcu_app_led_on(LED_B);
                else
                    msrcu_app_led_on(LED_R);
                osTimerStart(msrcuAppLedTimerId, MSRCU_LED_KEY_PRESS_ON_TIME);
            }
            break;
        
        case LED_STATE_KEY_RELEASE:
            {
                osTimerStop(msrcuAppLedTimerId);
                newSt = LED_STATE_NULL;
            }
            break;
        
        case LED_STATE_POWER_LOW:
            {
                msrcu_app_led_on(LED_R);
                userLedDuration = MSRCU_LED_POWER_LOW_DURATION;
                osTimerStart(msrcuAppLedTimerId, MSRCU_LED_POWER_LOW_ON_TIME);
            }
            break;
        
        case LED_STATE_POWER_EMPTY:
            {
                msrcu_app_led_on(LED_R);
                userLedDuration = MSRCU_LED_POWER_EMPTY_DURATION;
                osTimerStart(msrcuAppLedTimerId, MSRCU_LED_POWER_EMPTY_ON_TIME);
            }
            break;
        
        case LED_STATE_FUNC_VOICE_START:
            {
                msrcu_app_led_on(LED_G);
            }
            break;
        
        case LED_STATE_FUNC_VOICE_STOP:
            {
                newSt = LED_STATE_NULL;
            }
            break;
        
        case LED_STATE_FUNC_MOTION_START:
            {
                msrcu_app_led_on(LED_B);
            }
            break;
        
        case LED_STATE_FUNC_MOTION_STOP:
            {
                newSt = LED_STATE_NULL;
            }
            break;
        
        case LED_STATE_BOND_START:
            {
                msrcu_app_led_on(LED_R);
                userLedDuration = MSRCU_LED_BOND_START_DURATION;
                osTimerStart(msrcuAppLedTimerId, MSRCU_LED_BOND_START_ON_TIME);
            }
            break;
        
        case LED_STATE_BOND_SUCCESS:
            {
                msrcu_app_led_on(LED_B);
                osTimerStart(msrcuAppLedTimerId, MSRCU_LED_BOND_SUCCESS_ON_TIME);
            }
            break;
        
        case LED_STATE_BOND_FAIL:
            {
                msrcu_app_led_on(LED_R);
                osTimerStart(msrcuAppLedTimerId, MSRCU_LED_BOND_FAIL_ON_TIME);
            }
            break;
        
        case LED_STATE_BOND_CLEAR:
            {
                msrcu_app_led_on(LED_R);
                userLedDuration = MSRCU_LED_BOND_CLEAR_DURATION;
                osTimerStart(msrcuAppLedTimerId, MSRCU_LED_BOND_CLEAR_ON_TIME);
            }
            break;
        
        case LED_STATE_IR_LEARN_START:
        case LED_STATE_IR_LEARN_SUCCESS:
        case LED_STATE_IR_LEARN_FAIL:
        default:
            return ERR_NOT_SUPPORT;
    }
    
    
    if(userLedSt != newSt)
    {
        userLedSt = newSt;
        
        if(userLedSt == LED_STATE_NULL)
        {
            user_rcu_led_all_off();
            //MSPRINT("LED set state: 0x%02X.\r\n", userLedSt);
        }
    }
    
    return ERR_NO_ERROR;
}

static void user_rcu_longpress_timer_callback(void const *arg)
{
    userLongpressDuration -= KEY_LONGPRESS_CHECK_INTERVAL;
    
    if(userLongpressDuration <= 0)
    {
        osTimerStop(msrcuAppLongpressTimerId);
        
        if(BLE_STATE_CONNECTED == msrcu_app_ble_get_state()
                || BLE_STATE_READY == msrcu_app_ble_get_state())
        {
            MSPRINT("BLE is already connected, can't start or clear bond.\r\n");
            return;
        }
        
        if(msrcuBondData.status)
        {
            user_rcu_ble_bond_data_clear(&msrcuBondData);
            
            if(BLE_STATE_ADVERTISING == msrcu_app_ble_get_state())
                user_rcu_ble_adv_stop();
            
            user_rcu_led_set(LED_STATE_BOND_CLEAR);
        }
        else
        {
            userBondEnable = true;
            MSPRINT("Bond enable.\r\n");
            
            if(BLE_STATE_IDLE == msrcu_app_ble_get_state())
                user_rcu_ble_adv_start();
            
            user_rcu_led_set(LED_STATE_BOND_START);
            
            osTimerStart(msrcuAppBondTimerId, MSRCU_LED_BOND_START_DURATION);
        }
    }
}

#if MSRCU_MOTION_ENABLE 
void user_rcu_motion_start(void)
{
#if MSRCU_VOICE_ENABLE
    if(userVoiceIsStop && (userMotionIsStop || userMotionIsPause))
#else
    if(userMotionIsStop || userMotionIsPause)
#endif
    {
#if MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE
        if(msrcu_app_motion_reinit())
        {
            MSPRINT("Motion reinit error.\r\n");
            return;
        }
        msrcu_app_motion_power_on();
#endif
        if(!msrcu_app_motion_start())
        {
            userMotionIsStop = false;
            MSPRINT("Motion start.\r\n");
            osTimerStart(msrcuAppMotionTimerId, MOTION_TIMER_MS);
            user_rcu_led_set(LED_STATE_FUNC_MOTION_START);
        }
        else
            MSPRINT("Motion start error.\r\n");
    }
}

void user_rcu_motion_stop(void)
{
    if(!userMotionIsStop)
    {
        if(!msrcu_app_motion_stop())
        {
            userMotionIsStop = true;
            osTimerStop(msrcuAppMotionTimerId);
            MSPRINT("Motion stop.\r\n"); 
            user_rcu_led_set(LED_STATE_FUNC_MOTION_STOP);
        }
        else
            MSPRINT("Motion stop error.\r\n");
#if MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE
        msrcu_app_motion_power_off();
#endif
    }
}
#endif

#if MSRCU_VOICE_ENABLE
void user_rcu_voice_start(void)
{
    if(userVoiceIsStop)
    {
#if MSRCU_MOTION_ENABLE 
        if(!userMotionIsStop)
        {
            user_rcu_motion_stop();
            userMotionIsPause = true;
        }
#endif
        if(!msrcu_app_voice_start())
        {
            userVoiceIsStop = false;
            MSPRINT("Voice start.\r\n");
            user_rcu_led_set(LED_STATE_FUNC_VOICE_START);
        }
        else
            MSPRINT("Voice start error.\r\n");
    }
}

void user_rcu_voice_stop(void)
{
    if(!userVoiceIsStop)
    {
        if(!msrcu_app_voice_stop())
            MSPRINT("Voice stop.\r\n");
        else
            MSPRINT("Voice stop error.\r\n");
        
        userVoiceIsStop = true;
        user_rcu_led_set(LED_STATE_FUNC_VOICE_STOP);
        
#if MSRCU_MOTION_ENABLE
        if(userMotionIsPause)
        {
            user_rcu_motion_start();
            userMotionIsPause = false;
        }
#endif
    }
}
#endif

static void user_rcu_rf_test_timer_callback(void const *arg)
{
    hal_global_sys_reset();//reset to stop rf test
}

static void user_rcu_adv_timer_callback(void const *arg)
{
    if(BLE_STATE_ADVERTISING == msrcu_app_ble_get_state())
        user_rcu_ble_adv_stop();
    osTimerStop(msrcuAppAdvTimerId);
}

static void user_rcu_connect_timer_callback(void const *arg)
{
    osTimerStop(msrcuAppConnectTimerId); 
    
    MSPRINT("BLE connection duration time out.\r\n"); 
    
    msrcu_app_ble_disconnect();
}

static void user_rcu_bond_timer_callback(void const *arg)
{
    osTimerStop(msrcuAppBondTimerId);
    
    userBondEnable = false;
    MSPRINT("Bond fail: time out.\r\n");
    
    if(BLE_STATE_ADVERTISING == msrcu_app_ble_get_state())
        user_rcu_ble_adv_stop();
    else if(BLE_STATE_CONNECTED == msrcu_app_ble_get_state()
            || BLE_STATE_READY == msrcu_app_ble_get_state())
        ;//msrcu_app_ble_disconnect();
    
    user_rcu_led_set(LED_STATE_BOND_FAIL);
}

static void user_rcu_ble_rf_test(void)
{
    uint8_t testMode = 0;
    const uint8_t hciMode = 1;
    const uint8_t rfMode = 2;
    
    int port = 3;
    int pin = 2;
    hal_gpio_pin_mux(port, pin, 0, 0);
    hal_gpio_pad_oe_ie(port, pin, 0, 1);
    hal_gpio_pad_pd_pu(port, pin, 0, 1);

    port = 3;
    pin = 3;
    hal_gpio_pin_mux(port, pin, 0, 0);
    hal_gpio_pad_oe_ie(port, pin, 0, 1);
    hal_gpio_pad_pd_pu(port, pin, 0, 1);
    
    port = 1;
    pin = 7;
    hal_gpio_pin_mux(port, pin, 0, 0);
    hal_gpio_pad_oe_ie(port, pin, 1, 0);
    hal_gpio_pad_pd_pu(port, pin, 0, 1);
    hal_gpio_output(port, pin, 0, 1);
        
    //If the button which connected to GPIO_3_2 & GPIO_1_7
    //is pressed when power on, go to BLE RF test mode: HCI.
    if(!hal_gpio_input(3, 2))
        testMode = hciMode;
    //If the button which connected to GPIO_3_3 & GPIO_1_7
    //is pressed when power on, go to BLE RF test mode: rfMode.
    else if(!hal_gpio_input(3, 3))
        testMode = rfMode;
    
    if(testMode == hciMode)
    {
        //LED blue on
        port = MSRCU_DEV_LED_2_GPIO_PORT;
        pin = MSRCU_DEV_LED_2_GPIO_PIN;
        hal_gpio_pin_mux(port, pin, 0, 0);
        hal_gpio_pad_oe_ie(port, pin, 1, 0);
        hal_gpio_pad_pd_pu(port, pin, 0, 1);
        hal_gpio_aon_latch(port, pin, 0);//latch off
        hal_gpio_output(port, pin, 0, 1);//output low
        hal_gpio_aon_latch(port, pin, 1);//latch on
    }
    else if(testMode == rfMode)
    {
        //LED red on
        port = MSRCU_DEV_LED_0_GPIO_PORT;
        pin = MSRCU_DEV_LED_0_GPIO_PIN;
        hal_gpio_pin_mux(port, pin, 0, 0);
        hal_gpio_pad_oe_ie(port, pin, 1, 0);
        hal_gpio_pad_pd_pu(port, pin, 0, 1);
        hal_gpio_aon_latch(port, pin, 0);//latch off
        hal_gpio_output(port, pin, 0, 1);//output low
        hal_gpio_aon_latch(port, pin, 1);//latch on
    }
    else
        return;
    
    if(testMode == hciMode)
    {
#if CFG_HCI
        ble_config(true, NULL);//wait for HCI communication
#else
        #error "CFG_HCI is disabled."
#endif
    }
    else if(testMode == rfMode)
    {
        //init timer for rf test
        if(MSRCU_RF_TEST_DURATION)
        {
            msrcuAppRfTestTimerId = osTimerCreate(osTimer(msrcuAppRfTestTimer), osTimerPeriodic, NULL);
            if(msrcuAppRfTestTimerId == NULL)
                return;
            
            osTimerStart(msrcuAppRfTestTimerId, MSRCU_RF_TEST_DURATION);
        }
        
        ble_config(false, NULL);
        
        rf_em_init();
        rf_int_prog_pll_trx_trig(0);
        rf_int_rpl_mdm_init();
        rf_int_tx_carrier_test(1, 19); //2440MHz
    }
    
    while(1);//continue to test forever until chip reset
}

static msrcuErr_t user_rcu_ble_bond_data_save(msrcuBleBondData_t* data)
{
    //make sure ble is not busy
    while(inb_is_ble_busy());
    
    if(hal_spi_flash_prog(BOND_DATA_FLASH_OFFSET, 4096,
            BOND_DATA_FLASH_OFFSET, 256, (uint8_t *)data, 0))
        return ERR_DEVICE_DRIVER;
    else
    {
        MSPRINT("Bond data save.\r\n");
        return ERR_NO_ERROR;
    }
}

static msrcuErr_t user_rcu_ble_bond_data_read(msrcuBleBondData_t* data)
{
    memcpy(data, (uint8_t*)(0x00300000 + BOND_DATA_FLASH_OFFSET), sizeof(msrcuBleBondData_t)); 
    
    return ERR_NO_ERROR;
}

static msrcuErr_t user_rcu_ble_bond_data_clear(msrcuBleBondData_t* data)
{
    if(data->status)
    {
        memset(&gBondData, 0, sizeof(gBondData));
        memset(data, 0, sizeof(msrcuBleBondData_t));
        
        // make sure ble is not busy
        while (inb_is_ble_busy());
        
        if(hal_spi_flash_prog(BOND_DATA_FLASH_OFFSET, 4096, 
                BOND_DATA_FLASH_OFFSET, 256, (uint8_t *)data, 0))
            return ERR_DEVICE_DRIVER;
        else
        {
            MSPRINT("Bond data clear.\r\n");   
            return ERR_NO_ERROR;
        }
    }
    else
        return ERR_NO_ERROR;
}

static msrcuErr_t user_rcu_ble_adv_start(void)
{
    msrcuErr_t err = ERR_NO_ERROR;
    uint8_t advData[] = 
    {
        0x03,//AD Element Length
        0x03,//AD Type: Complete list of 16-bit UUIDs
        0x12, 0x18,//AD Data UUID
        
        0x03,//AD Element Length
        0x19,//AD Type: Appearance
        0x80, 0x01,//AD Data: Generic Remote Control
    };
    uint8_t scanRspData[] = 
    {
        0x0B,//AD Element Length
        0x08,//AD Type: Shortened local name
        'T','r','o','p','o','s',' ','R','C','U',//AD Data Bytes: "Tropos RCU"
    };
    msrcuBleAdv_t* adv;
    
    adv = malloc(sizeof(msrcuBleAdv_t));
    if(adv == NULL)
        return ERR_NO_MEMORY;

#if MSRCU_BLE_DIRECT_ADV_ENABLE
    if(msrcuBondData.status)
    {
        adv->pduType = ADV_DIRECT_IND;
        adv->peerAddrType = msrcuBondData.peerAddrType;
        memcpy(adv->peerAddr.addr, msrcuBondData.peerAddr.addr, BLE_ADDR_LEN);
    }
    else
    {
        adv->pduType = ADV_IND;
    }
#else
    adv->pduType = ADV_IND;  
#endif
    adv->channel = ADV_CHANNEL_37_38_39;
    adv->intvMin = MSRCU_BLE_ADV_INTERVAL_MIN;
    adv->intvMax = MSRCU_BLE_ADV_INTERVAL_MAX;
    adv->advData = advData;
    adv->advDataLen = sizeof(advData);
    adv->scanRspData = scanRspData;
    adv->scanRspDataLen = sizeof(scanRspData);
    
    err = msrcu_app_ble_adv_start(adv);
    
    if(adv->pduType == ADV_IND)
        MSPRINT("ADV_IND\r\n");
    else if(adv->pduType == ADV_DIRECT_IND)
        MSPRINT("ADV_DIRECT_IND\r\n");
    
    if(adv)
        free(adv);
    
    if(!err)
    {
        MSPRINT("Advertising start.\r\n");     
        
        if(!userBondEnable)
            osTimerStart(msrcuAppAdvTimerId, MSRCU_BLE_ADV_DURATION);
    }
    else
        MSPRINT("Advertising start error.\r\n");
    
    return err;
}

static msrcuErr_t user_rcu_ble_adv_stop(void)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
    if(userBondEnable)
        return ERR_NOT_SUPPORT;
    
    err = msrcu_app_ble_adv_stop();
    
    if(!err)
        MSPRINT("Advertising stop.\r\n");
    else
        MSPRINT("Advertising stop error.\r\n");
    
    return err;
}

static void user_rcu_ble_callback(msrcuEvtBle_t *evt)
{
    switch(evt->code)
    {
        case EVT_BLE_CONNETED:
            {
                msrcuBleConInd_t* conInd = &evt->param.conInd;
                MSPRINT("Connected, idx:%d, interval=0x%X, latency=%d, timeout=%dms, addrType:%d, addr:%02X %02X %02X %02X %02X %02X.\r\n", 
                        conInd->conIndex, conInd->conInterval, conInd->conLatency, conInd->conTimeOut * 10, conInd->peerAddrType,
                        conInd->peerAddr.addr[0], conInd->peerAddr.addr[1], conInd->peerAddr.addr[2],
                        conInd->peerAddr.addr[3], conInd->peerAddr.addr[4], conInd->peerAddr.addr[5]);
                
                if(MSRCU_BLE_CNT_DURATION)
                    osTimerStart(msrcuAppConnectTimerId, MSRCU_BLE_CNT_DURATION);
                
                msrcuBondData.peerAddrType = conInd->peerAddrType;
                memcpy(msrcuBondData.peerAddr.addr, conInd->peerAddr.addr, BLE_ADDR_LEN);
            }
            break;
        
        case EVT_BLE_DISCONNETED:
            {
                msrcuBleDisconInd_t* disconInd = &evt->param.disconInd;
                MSPRINT("Disconnected, idx:%d, reason:0x%02X.\r\n", disconInd->conIndex, disconInd->reason);
                
                if(MSRCU_BLE_CNT_DURATION)
                    osTimerStop(msrcuAppConnectTimerId);
                
                msrcuLedSt ledSt = LED_STATE_NULL;
#if MSRCU_VOICE_ENABLE
                if(!userVoiceIsStop)
                {
                    if(!msrcu_app_voice_stop())
                    {
                        userVoiceIsStop = true;
                        MSPRINT("Voice stop.\r\n");
                        
                        ledSt = LED_STATE_FUNC_VOICE_STOP;
                    }
                    else
                        MSPRINT("Voice stop error.\r\n");
                    
                }
#endif
#if MSRCU_MOTION_ENABLE
                if(!userMotionIsStop)
                {
                    if(!msrcu_app_motion_stop())
                    {
                        userMotionIsStop = true;
                        MSPRINT("Motion stop.\r\n");
                        
                        osTimerStop(msrcuAppMotionTimerId);
                        
                        ledSt = LED_STATE_FUNC_MOTION_STOP;
                    }
                    else
                        MSPRINT("Motion stop error.\r\n"); 
#if MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE
                    msrcu_app_motion_power_off();
#endif
                    userMouseButton = MOUSE_BUTTON_NULL;
                }
#endif
                if(msrcuBondData.status
                        && disconInd->reason != BLE_ERROR_CON_TERM_BY_LOCAL_HOST
                        && disconInd->reason != BLE_ERROR_REMOTE_USER_TERM_CON )
                    user_rcu_ble_adv_start();
                
                user_rcu_led_set(ledSt);
            }
            break;
        
        case EVT_BLE_CON_PRAM_UPD:
            {
                msrcuBleConParamUpd_t* conParamUpd = &evt->param.conParamUpd;
                MSPRINT("Connection parameter updated, idx:%d, interval=0x%X, latency=%d, timeout=%dms.\r\n", 
                        conParamUpd->conIndex, conParamUpd->conInterval, 
                        conParamUpd->conLatency, conParamUpd->conTimeOut * 10);
            }
            break;
        
        case EVT_BLE_RCU_READY:
            {
                if(userBondEnable)
                {
                    MSPRINT("Bond success.\r\n");
                    userBondEnable = false;
                    osTimerStop(msrcuAppBondTimerId);
                    user_rcu_led_set(LED_STATE_BOND_SUCCESS);
                    
                    msrcuBondData.status = 1;
                    user_rcu_ble_bond_data_save(&msrcuBondData);
                }
                
                user_rcu_power_update_battery_level();
            }
            break;
        
        default:
            break;
    }
}

static void user_rcu_key_callback(msrcuEvtKey_t *param)
{
    msrcuLedSt ledSt = LED_STATE_NULL;
    
    switch(param->behavior)
    {
        case EVT_KEY_PRESS:
            {
                MSPRINT("Key %02d is pressed.\r\n", param->code);
                
                //set LED
                if(userPowerState == POWER_STATE_LOW)
                    ledSt = LED_STATE_POWER_LOW;
                else if(userPowerState == POWER_STATE_EMPTY)
                    ledSt = LED_STATE_POWER_EMPTY;
                else
                    ledSt = LED_STATE_KEY_PRESS;
                
                //BLE advertising on
                if(BLE_STATE_IDLE == msrcu_app_ble_get_state() && msrcuBondData.status)
                    user_rcu_ble_adv_start();
                
                if(BLE_STATE_IDLE == msrcu_app_ble_get_state()
                        || BLE_STATE_ADVERTISING == msrcu_app_ble_get_state()
                        || BLE_STATE_CONNECTED == msrcu_app_ble_get_state())
                {
#if MSRCU_IR_SEND_ENABLE
                    if(userIrSendIsStop)
                    {
                        //IR send start
                        userIrCode.protocol = IR_PROT_NEC;
                        userIrCode.param.necCode.address = MSRCU_IR_NEC_ADDRESS;
                        userIrCode.param.necCode.cmd = msrcuKeycodeToIrCmd(param->code); 
                        
                        if(!msrcu_app_ir_send_start(&userIrCode))
                        {
                            userIrSendIsStop = false;
                            MSPRINT("IR send start.\r\n");
                        }
                        else
                            MSPRINT("IR send start error.\r\n");
                    }
#endif
                }
                else if(BLE_STATE_READY == msrcu_app_ble_get_state())
                {
                    if(MSRCU_BLE_CNT_DURATION)
                        osTimerStart(msrcuAppConnectTimerId, MSRCU_BLE_CNT_DURATION);
                    
                    if(param->code != KEY_CODE_VOICE)
                        msrcu_app_key_hid_send(msrcuKeycodeToHidKeycode(param->code, 0));
                }
            }
            break;
        
        case EVT_KEY_RELEASE:
            {
                MSPRINT("Key %02d is released.\r\n", param->code);
                
                //stop long press check
                osTimerStop(msrcuAppLongpressTimerId);
                
                //set LED
                ledSt = LED_STATE_KEY_RELEASE;
                
#if MSRCU_IR_SEND_ENABLE 
                //IR send stop
                if(!userIrSendIsStop)
                {
                    if(!msrcu_app_ir_send_stop())
                    {
                        userIrSendIsStop = true;
                        MSPRINT("IR send stop.\r\n");
                    }
                }
#endif
                //HID keycode release
                if(BLE_STATE_READY == msrcu_app_ble_get_state())
                {
                    if(MSRCU_BLE_CNT_DURATION)
                        osTimerStart(msrcuAppConnectTimerId, MSRCU_BLE_CNT_DURATION);
                    
                    if(param->code != KEY_CODE_VOICE)
                        msrcu_app_key_hid_send(msrcuKeycodeToHidKeycode(KEY_CODE_NULL, 0));
                }
            }
            break;
        
        case EVT_KEY_LONG_PRESS:
            //MSPRINT("Key %02d is long pressed.\r\n", param->code);
            break;
        
        default:
            break;
    }
    
    switch(param->code)
    {
//        case KEY_CODE_POWER:
//            {
//                if(param->behavior == EVT_KEY_PRESS)
//                {
//#if MSRCU_IR_LEARN_ENABLE
//                    if(userIrLearnIsStop)
//                    {
//                        userIrLearnIsStop = false;
//                        MSPRINT("IR learn start.\r\n");
//                        if(msrcu_app_ir_learn_start(1))//wait result at user_rcu_ir_callback
//                        {
//                            userIrLearnIsStop = true;
//                            MSPRINT("IR learn start error.\r\n");
//                        }
//                    }
//                    else
//                    {
//                        if(msrcu_app_ir_learn_stop())//result at user_rcu_ir_callback
//                            MSPRINT("IR learn stop error.\r\n");
//                    }
//#endif
//                }
//                else if(param->behavior == EVT_KEY_RELEASE){}
//                else if(param->behavior == EVT_KEY_LONG_PRESS){}
//            }
//            break;
        
        case KEY_CODE_POWER:
            {
                if(param->behavior == EVT_KEY_PRESS)
                {
                    msrcuKeySt keyEnterSt;
                    msrcu_app_key_state_get(KEY_CODE_ENTER, &keyEnterSt);
                    if(keyEnterSt == KEY_PRESSED)
                    {
                        if(msrcuBondData.status)
                            userLongpressDuration = MSRCU_KEY_LONGPRESS_TIME_BONDCLEAR;
                        else
                            userLongpressDuration = MSRCU_KEY_LONGPRESS_TIME_BONDSTART;
                        osTimerStart(msrcuAppLongpressTimerId, KEY_LONGPRESS_CHECK_INTERVAL);
                    }
                }
                else if(param->behavior == EVT_KEY_RELEASE){}
                else if(param->behavior == EVT_KEY_LONG_PRESS){}
            }
            break;
        
        case KEY_CODE_VOICE:
            {
                if(param->behavior == EVT_KEY_PRESS)
                {
                    if(BLE_STATE_READY == msrcu_app_ble_get_state())
                    {
#if MSRCU_VOICE_ENABLE
#if MSRCU_BLE_VOICE_ATV_ENABLE
                        if(atv_task_send_is_enabled())
                        {
#if MSRCU_MOTION_ENABLE 
                            if(!userMotionIsStop)
                            {
                                user_rcu_motion_stop();
                                userMotionIsPause = true;
                            }
#endif
                            msrcu_app_key_hid_send(msrcuKeycodeToHidKeycode(param->code, 0));
                            msrcu_app_voice_atv_start();
                        }
                        if(!userVoiceIsStop)
                            user_rcu_voice_stop();
#else
                        user_rcu_voice_start();
#endif
#endif
                    }
                }
                else if(param->behavior == EVT_KEY_RELEASE)
                {
                    if(BLE_STATE_READY == msrcu_app_ble_get_state())
                    {
#if MSRCU_VOICE_ENABLE
#if MSRCU_BLE_VOICE_ATV_ENABLE
                        if(atv_task_send_is_enabled())
                            msrcu_app_key_hid_send(msrcuKeycodeToHidKeycode(KEY_CODE_NULL, 0));
#else
                        user_rcu_voice_stop();
#endif
#endif
                    }
                }
            }
            break;
        
        case KEY_CODE_MOTION:
            {
                if(param->behavior == EVT_KEY_PRESS)
                {
#if MSRCU_MOTION_ENABLE
                    if(BLE_STATE_READY == msrcu_app_ble_get_state())
                    {
#if MSRCU_VOICE_ENABLE
                        if(userVoiceIsStop && userMotionIsStop)
#else
                        if(userMotionIsStop)
#endif
                        {
                            user_rcu_motion_start();
                        }
                        else
                        {
                            user_rcu_motion_stop();
                        }
                    }
#endif
                }
                else if(param->behavior == EVT_KEY_RELEASE)
                {
                }
                else if(param->behavior == EVT_KEY_LONG_PRESS)
                {
#if 0//MSRCU_IR_LEARN_ENABLE//IR learn function is unusable in this version of SDK
#if MSRCU_IR_SEND_ENABLE
                    //stop ir send at first
                    if(!userIrSendIsStop)
                    {
                        if(!msrcu_app_ir_send_stop())
                        {
                            userIrSendIsStop = true;
                            MSPRINT("IR send stop.\r\n");
                        }
                    }
#endif
                    //ir learn start/stop
                    if(userIrLearnIsStop)
                    {
                        userIrLearnIsStop = false;
                        MSPRINT("IR learn start.\r\n");
                        if(msrcu_app_ir_learn_start(1))//wait result at user_rcu_ir_callback
                        {
                            userIrLearnIsStop = true;
                            MSPRINT("IR learn start error.\r\n");
                        }
                    }
                    else
                    {
                        if(msrcu_app_ir_learn_stop())//result at user_rcu_ir_callback
                            MSPRINT("IR learn stop error.\r\n");
                    }
#endif
                }
            }
            break;
        
        case KEY_CODE_ENTER:
            {
                if(param->behavior == EVT_KEY_PRESS)
                {
                    if(BLE_STATE_READY == msrcu_app_ble_get_state())
                    {
#if (MSRCU_VOICE_ENABLE && MSRCU_BLE_VOICE_ATV_ENABLE)
#if MSRCU_MOTION_ENABLE
                        if(userMotionIsStop)
#endif
                        {
                            if(atv_task_send_is_enabled())
                            {
                                uint8_t cmd[ATVV_CHAR_CTL_DPAP_SELECT_LEN] = {0};
                                cmd[0] = ATVV_CHAR_CTL_DPAP_SELECT_CMD;
                                atv_task_cmd_send(BLE_CON_IDX, cmd, ATVV_CHAR_CTL_DPAP_SELECT_LEN);
                            }
                        }
#endif
#if MSRCU_MOTION_ENABLE
                        if(!userMotionIsStop)
                        {
                            msrcuMotionMouse_t mouse = {0};
                            userMouseButton = MOUSE_BUTTON_LEFT;
                            msrcu_app_motion_mouse_hid_send(userMouseButton, &mouse);
                        }
#endif
                    }
                }
                else if(param->behavior == EVT_KEY_RELEASE)
                {
                    if(BLE_STATE_READY == msrcu_app_ble_get_state())
                    {
#if MSRCU_MOTION_ENABLE
                        msrcuMotionMouse_t mouse = {0};
                        userMouseButton = MOUSE_BUTTON_NULL;
                        msrcu_app_motion_mouse_hid_send(userMouseButton, &mouse);
#endif
                    }
                }
            }
            break;
            
        case KEY_CODE_UP:
        case KEY_CODE_DOWN:
        case KEY_CODE_LEFT:
        case KEY_CODE_RIGHT:
        //case other key codes...
        default:
            {
                if(param->behavior == EVT_KEY_PRESS){}
                else if(param->behavior == EVT_KEY_RELEASE){}
            }
            break;
    }
    
    if(param->behavior != EVT_KEY_LONG_PRESS)
        user_rcu_led_set(ledSt);
}

#if MSRCU_IR_LEARN_ENABLE
static void user_rcu_ir_callback(msrcuEvtIr_t *param)
{
#if MSRCU_IR_LEARN_ENABLE
    switch(param->lrnResult)
    {
        case EVT_IR_LRN_SUCCESS:
            {
                MSPRINT("IR learn stop: Success, idx:%d.\r\n", param->index);
                userIrLearnIsStop = true;
            }
            break;
        
        case EVT_IR_LRN_FAIL:
            {
                MSPRINT("IR learn stop: Fail, idx:%d.\r\n", param->index);
                userIrLearnIsStop = true;
            }
            break;
        
        case EVT_IR_LRN_TERMINATE:
            {
                MSPRINT("IR learn stop: Terminate, idx:%d.\r\n", param->index);
                userIrLearnIsStop = true;
            }
            break;
        
        default:
            break;
    }
#endif
}
#endif

static msrcuErr_t user_rcu_timer_init(void)
{
    //init timer for key longpress
    msrcuAppLongpressTimerId = osTimerCreate(osTimer(msrcuAppLongpressTimer), osTimerPeriodic, NULL);
    if(msrcuAppLongpressTimerId == NULL)
        return ERR_OS;
    
    //init timer for LED
    msrcuAppLedTimerId = osTimerCreate(osTimer(msrcuAppLedTimer), osTimerPeriodic, NULL);
    if(msrcuAppLedTimerId == NULL)
        return ERR_OS;
    
    //init timer for checking battery voltage
    msrcuAppPowerTimerId = osTimerCreate(osTimer(msrcuAppPowerTimer), osTimerPeriodic, NULL);
    if(msrcuAppPowerTimerId == NULL)
        return ERR_OS;
    
    //init timer for advertising
    msrcuAppAdvTimerId = osTimerCreate(osTimer(msrcuAppAdvTimer), osTimerPeriodic, NULL);
    if(msrcuAppAdvTimerId == NULL)
        return ERR_OS;
    
    //init timer for conncetion duration
    msrcuAppConnectTimerId = osTimerCreate(osTimer(msrcuAppConnectTimer), osTimerPeriodic, NULL);
    if(msrcuAppConnectTimerId == NULL)
        return ERR_OS;
    
    //init timer for bond
    msrcuAppBondTimerId = osTimerCreate(osTimer(msrcuAppBondTimer), osTimerPeriodic, NULL);
    if(msrcuAppBondTimerId == NULL)
        return ERR_OS;
    
#if MSRCU_MOTION_ENABLE
    //init timer for getting motion sensor data
    msrcuAppMotionTimerId = osTimerCreate(osTimer(msrcuAppMotionTimer), osTimerPeriodic, NULL);
    if(msrcuAppMotionTimerId == NULL)
        return ERR_OS;
#endif
    
    return ERR_NO_ERROR;
}

static msrcuErr_t user_rcu_init(msrcuAppCallback_t *cb)
{
    msrcuErr_t err = ERR_NO_ERROR;
    
    //get bond data from FLASH
    user_rcu_ble_bond_data_read(&msrcuBondData);
    
    memcpy(&(gBondData.ltk.key), msrcuBondData.ltk.key, BLE_KEY_LEN);
    gBondData.ediv = msrcuBondData.ediv;
    memcpy(&(gBondData.randnb.nb), msrcuBondData.randNb.nb, BLE_RANDOM_NB_LEN);
    gBondData.key_size = msrcuBondData.keySize;
    
    //user_rcu_ble_bond_data_clear(&msrcuBondData);//for test
    
    //timer init
    err = user_rcu_timer_init();
    if(err)
        return err;
    
    //register callback
    cb->msrcu_app_ble_cb = user_rcu_ble_callback;
    cb->msrcu_app_key_cb = user_rcu_key_callback;
#if MSRCU_IR_LEARN_ENABLE
    cb->msrcu_app_ir_cb = user_rcu_ir_callback;
#endif
    
    //rcu function init
    err = msrcu_app_init(cb);
    if(err)
        return err;
    
    //LED check
    msrcu_app_led_on(LED_R);
    msrcu_app_led_on(LED_G);
    msrcu_app_led_on(LED_B);
    osDelay(1000);
    user_rcu_led_all_off();
    
    //check battery voltage
    user_rcu_power_update_battery_level();
    //start timer for checking battery voltage
    osTimerStart(msrcuAppPowerTimerId, MSRCU_POWER_BAT_SAMPLE_INTERVAL); 
    
    //start BLE advertising if bonded
    if(msrcuBondData.status)
    {
        MSPRINT("Bonded.\r\n");
        user_rcu_ble_adv_start();
    }
    else
        MSPRINT("Not bonded.\r\n");
    
    return err;
}

/*
 * main: This is actually main task.
 *  Note: The _main_init in the RTX_CM_lib.h is
 *              main entry routine (OS is initialized
 *              in there).
 */
#if 0
int main (void)//for test
{
#if GLOBAL_FLASH_WRITE
    uint32_t magciWord = 0;
    uint8_t capOffset = 0x7;
//    inb_addr_t mac = {.addr = CFG_BLE_PARAM_BD_ADDR};
    inb_addr_t mac = {.addr = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
    
//    magciWord = hal_global_flash_magic_word_get();
//    capOffset = hal_global_flash_cap_offset_get();
//    hal_global_flash_ble_mac_get(&mac);
    
    hal_global_flash_set(magciWord, capOffset, &mac);
#endif
    
    hal_global_post_init();
    
    PRINTD(DBG_TRACE, "----------------\r\n");
    PRINTD(DBG_TRACE, "main start...\r\n");
    
    ble_config(false, NULL);
    
    user_rcu_ble_adv_start();
    
    while(1)
    {
        osDelay(1000);
    }
}
#else
int main (void)
{
    //Initialize platform
    hal_global_post_init();
    
#if (CFG_PDT_HCI || CFG_PDT_TX)
    //BLE production test
    ble_production_test();
#endif
    
    //User BLE production test
    user_rcu_ble_rf_test();
    
    //Debug UART init
    hal_global_debug_uart_init();
    
    //Main LOG
    PRINTD(DBG_TRACE, "----------------\r\n");
    PRINTD(DBG_TRACE, "main start...\r\n");
    PRINTD(DBG_TRACE, "Wafer Version: %02X\r\n", chip_get_id() & 0xff);
    
    //MessageQ for main thread.
    msg_init();
    
    //BLE init
    ble_config(false, msrcu_dev_ble_evt_cb);
    
    //RCU init
    msrcuErr_t err = user_rcu_init(&userAppCb);
    if(err)
    {
        MSPRINT("RCU init failed, error %d\r\n", err);
        return 0;
    }
    else
        MSPRINT("RCU init success.\r\n");
    
    //Wait for message
    while(1)
    {
        msg_t *msg;
        msg = msg_get(osWaitForever);
        handle_main_msg(msg);
        if(msg)
            msg = msg_free(msg);
    }
}
#endif

