#include "in_config.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "in_arm.h"
#include "in_debug.h"
#include "inb_config.h"
#include "hal_uart.h"
#include "hal_gpio.h"
#include "hal_power.h"
#include "hal_ir.h"
#include "hal_audio.h"
#include "hal_adc.h"
#include "hal_clk.h"
#include "hal_keyboard.h"
#include "hal_global.h"
#include "spi_flash.h"

#include "cmsis_os.h"

#include "msg.h"
#include "ble_test.h"
#include "gap_test.h"

#include "msrcu_app.h"
#include "airmouse.h"

#define LED_R   0
#define LED_G   1
#define LED_B   2
#define LED_BLINK_CYCLE_MS  (500)
#define LED_BLINK_DUTY_MS   (250)


#if MSRCU_MOTION_ENABLE
#define MOTION_TIMER_MS     (1000 / M_SAMPLE_FREQUENCY)
#endif

#define BOND_DATA_FLASH_OFFSET  (0x7F000)


msrcuBleBondData_t msrcuBondData = {0};
extern int hal_spi_flash_prog(uint32_t erase_addr, uint32_t erase_size, uint32_t prog_addr, uint32_t prog_size, uint8_t *prog_data, int verify);
static msrcuAppCallback_t userAppCb = {0};

static msrcuPowerSt userPowerState = POWER_STATE_NORMAL;
static void user_rcu_power_timer_callback(void const *arg);
static osTimerId msrcuAppPowerTimerId;
static osTimerDef(msrcuAppPowerTimer, user_rcu_power_timer_callback);

static int userLongpressDuration = 0;
static void user_rcu_longpress_timer_callback(void const *arg);
static osTimerId msrcuAppLongpressTimerId;
static osTimerDef(msrcuAppLongpressTimer, user_rcu_longpress_timer_callback);

static msrcuLedSt userLedSt = LED_STATE_NULL;
static int userLedDuration = 0;
static void user_rcu_led_timer_callback(void const *arg);
static osTimerId msrcuAppLedTimerId;
static osTimerDef(msrcuAppLedTimer, user_rcu_led_timer_callback);

static void user_rcu_adv_timer_callback(void const *arg);
static osTimerId msrcuAppAdvTimerId;
static osTimerDef(msrcuAppAdvTimer, user_rcu_adv_timer_callback);

static bool userBondEnable = false;
static void user_rcu_bond_timer_callback(void const *arg);
static osTimerId msrcuAppBondTimerId;
static osTimerDef(msrcuAppBondTimer, user_rcu_bond_timer_callback);
static msrcuErr_t user_rcu_ble_bond_data_clear(msrcuBleBondData_t* data);

static msrcuErr_t user_rcu_ble_adv_start(void);
static msrcuErr_t user_rcu_ble_adv_stop(void);

#if MSRCU_VOICE_ENABLE
static bool userVoiceIsStop = true;
#endif

#if MSRCU_MOTION_ENABLE
bool userMotionIsStop = true;
bool userMotionIsPause = false;
static void user_rcu_motion_timer_callback(void const *arg);
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
            
#if (CFG_MEMORY_TRACK==1)
//Timer for memory track, optional
osTimerDef(bmem, ble_mem_usage_tmr_callback);

void ble_mem_usage_tmr_callback(void const *arg)
{
	int max;
	inb_mem_usage_t muse;

	inb_get_mem_usage(&muse);
	max = inb_get_max_mem_usage();

	PRINTD(DBG_TRACE, "--- mem: %d,%d,%d,%d,%d ---\r\n", muse.retn_mem_env_mem_usage, muse.retn_mem_db_mem_usage, muse.retn_mem_msg_mem_usage, muse.non_retn_mem_usage, max);
}
#endif

static int handle_msg(msg_t *p_msg)
{
	//PRINTD(DBG_TRACE, "main evt %d...\r\n", p_msg->msg_id);
	
	switch (p_msg->msg_id) 
	{
        default:
            handle_default_msg(p_msg);
            break;
	}
    return 0;
}

static void user_rcu_rf_test(void)
{
    bool testMode = false;
    
    //if the button which connected to GPIO_3_2 & GPIO_1_7
    //is pressed when power on, go to BLE RF test mode.
    hal_gpio_pin_mux(3, 2, 0, 0);
    hal_gpio_pad_oe_ie(3, 2, 0, 1);
    hal_gpio_pad_pd_pu(3, 2, 0, 1);		
    
    hal_gpio_pin_mux(1, 7, 0, 0);
    hal_gpio_pad_oe_ie(1, 7, 1, 0);
    hal_gpio_pad_pd_pu(1, 7, 0, 1);		
    hal_gpio_output(1, 7, 0, 1);
        
    if(!hal_gpio_input(3, 2))
        testMode = true;
    
    if(testMode)
    {        
#if 1 //HCI mode
#if CFG_HCI        
        hci_enable();
        ble_stack_init();//wait for HCI communication
#endif
#else //inb_test mode
        inb_test_mode_t tMode = {0};
        uint16_t rxPacketNb = 0;
        
        tMode.test_mode = TEST_MODE_TX;
        tMode.channel = 19;//2440MHz
        tMode.tx_data_length = 20;
        tMode.tx_pkt_payload = PKT_PLD_PRBS15;
        tMode.phy = TEST_PHY_1MBPS;
        tMode.modulation_idx = MODULATION_STANDARD;
        inb_test(&tMode, &rxPacketNb);//test start
#endif
        
        while(1);//continue to test forever until chip reset
    }    
}

static void user_rcu_power_timer_callback(void const *arg)
{
    uint16_t batMv = 0;
    int err;
    
    err = msrcu_app_power_bat_voltage_get(&batMv);
    if(!err)
        MSPRINT("Battery voltage : %dmV\r\n", batMv);
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
            break;
        }
        
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
            break;
        }
        
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
            break;
        }
        
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
            break;
        }
        
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
        user_rcu_led_all_off();
        userLedSt = LED_STATE_NULL;
    }
}

static msrcuErr_t user_rcu_led_set(msrcuLedSt newSt)
{        
    //function check
    if((newSt & LED_STATE_FUNCTION_MASK) == 0)
        return ERR_VALID_INPUT;
    
    //priority check
    if((newSt & LED_STATE_PRIORITY_MASK) < (userLedSt & LED_STATE_PRIORITY_MASK))
        return ERR_NOT_SUPPORT;
    
    userLedDuration = 0;
    osTimerStop(msrcuAppLedTimerId);
    user_rcu_led_all_off();
    
    switch(newSt)
    {
        case LED_STATE_KEY_PRESS:
        {
            if(BLE_STATE_READY == msrcu_app_ble_get_state())
                msrcu_app_led_on(LED_B);
            else
                msrcu_app_led_on(LED_R);
            osTimerStart(msrcuAppLedTimerId, MSRCU_LED_KEY_PRESS_ON_TIME);
            break;
        }
            
        case LED_STATE_KEY_RELEASE:
        {
            osTimerStop(msrcuAppLedTimerId);
            user_rcu_led_all_off();
            newSt = LED_STATE_NULL;
            break;
        }
                
        case LED_STATE_POWER_LOW:
        {
            msrcu_app_led_on(LED_R);
            userLedDuration = MSRCU_LED_POWER_LOW_DURATION;
            osTimerStart(msrcuAppLedTimerId, MSRCU_LED_POWER_LOW_ON_TIME);
            break;
        }
        
        case LED_STATE_POWER_EMPTY:
        {
            msrcu_app_led_on(LED_R);
            userLedDuration = MSRCU_LED_POWER_EMPTY_DURATION;
            osTimerStart(msrcuAppLedTimerId, MSRCU_LED_POWER_EMPTY_ON_TIME);
            break;
        }
        
        case LED_STATE_FUNC_VOICE_START:
        {
            msrcu_app_led_on(LED_G);
            break;
        }
        
        case LED_STATE_FUNC_VOICE_STOP:
        {
            msrcu_app_led_off(LED_G);
            newSt = LED_STATE_NULL;
            break;
        }
        
        case LED_STATE_FUNC_MOTION_START:
        {
            msrcu_app_led_on(LED_B);
            break;
        }
        
        case LED_STATE_FUNC_MOTION_STOP:
        {
            msrcu_app_led_off(LED_B);
            newSt = LED_STATE_NULL;
            break;
        }
        
        case LED_STATE_BOND_START:
        {
            msrcu_app_led_on(LED_R);
            userLedDuration = MSRCU_LED_BOND_START_DURATION;
            osTimerStart(msrcuAppLedTimerId, MSRCU_LED_BOND_START_ON_TIME);   
            break;
        }
        
        case LED_STATE_BOND_SUCCESS:
        {
            msrcu_app_led_on(LED_B);
            osTimerStart(msrcuAppLedTimerId, MSRCU_LED_BOND_SUCCESS_ON_TIME);
            break;
        }
        
        case LED_STATE_BOND_FAIL:
        {
            msrcu_app_led_on(LED_R);
            osTimerStart(msrcuAppLedTimerId, MSRCU_LED_BOND_FAIL_ON_TIME);
            break;
        }
        
        case LED_STATE_BOND_CLEAR:
        {
            msrcu_app_led_on(LED_R);
            userLedDuration = MSRCU_LED_BOND_CLEAR_DURATION;
            osTimerStart(msrcuAppLedTimerId, MSRCU_LED_BOND_CLEAR_ON_TIME);            
            break;
        }
        
        case LED_STATE_IR_LEARN_START:
        case LED_STATE_IR_LEARN_SUCCESS:
        case LED_STATE_IR_LEARN_FAIL:
        default:
            return ERR_NOT_SUPPORT;
    }    
    
    userLedSt = newSt;
    MSPRINT("LED set state: 0x%02X.\r\n", userLedSt);
            
    return ERR_NO_ERROR;
}

static void user_rcu_longpress_timer_callback(void const *arg)
{
    userLongpressDuration -= KEY_LONGPRESS_CHECK_INTERVAL;
    
    if(userLongpressDuration <= 0)
    {
        osTimerStop(msrcuAppLongpressTimerId);
        
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

static void user_rcu_adv_timer_callback(void const *arg)
{
    if(BLE_STATE_ADVERTISING == msrcu_app_ble_get_state())
        user_rcu_ble_adv_stop();    
    osTimerStop(msrcuAppAdvTimerId);
}

static void user_rcu_bond_timer_callback(void const *arg)
{
    osTimerStop(msrcuAppBondTimerId);  
    
    userBondEnable = false;
    MSPRINT("Bond fail: time out.\r\n");
    
    if(BLE_STATE_ADVERTISING == msrcu_app_ble_get_state())
        user_rcu_ble_adv_stop();
    
    user_rcu_led_set(LED_STATE_BOND_FAIL);
}

static msrcuErr_t user_rcu_ble_bond_data_save(msrcuBleBondData_t* data)
{                    
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
        memset(&ble_bond_data, 0, sizeof(ble_bond_data));         
        memset(data, 0, sizeof(msrcuBleBondData_t)); 
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
        0x06,//AD Element Length
        0x08,//AD Type: Shortened local name
        'M','S','R','C','U'//AD Data Bytes:"MSRCU"
    };
    uint8_t scanRspData[] = 
    {
        0x03,//AD Element Length
        0x03,//AD Type: Complete list of 16-bit UUIDs
        0x12, 0x18//AD Data UUID: Human Interface Device
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
            
            msrcuBondData.peerAddrType = conInd->peerAddrType;
            memcpy(msrcuBondData.peerAddr.addr, conInd->peerAddr.addr, BLE_ADDR_LEN);
                        
            break;
        }
        
        case EVT_BLE_DISCONNETED:
        {
            msrcuBleDisconInd_t* disconInd = &evt->param.disconInd;
            MSPRINT("Disconnected, idx:%d, reason:0x%02X.\r\n", disconInd->conIndex, disconInd->reason);
            
#if MSRCU_VOICE_ENABLE
            if(!userVoiceIsStop)
            {
                if(!msrcu_app_voice_stop())
                {
                    userVoiceIsStop = true;
                    MSPRINT("Voice stop.\r\n");
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
                }
                else
                    MSPRINT("Motion stop error.\r\n"); 
#if MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE
                msrcu_app_motion_power_off();
#endif                                          
            }
#endif                
            if(msrcuBondData.status)
                user_rcu_ble_adv_start();
            
            break;
        }
        
        case EVT_BLE_CON_PRAM_UPD:
        {
            msrcuBleConParamUpd_t* conParamUpd = &evt->param.conParamUpd;
            MSPRINT("Connection parameter updated, idx:%d, interval=0x%X, latency=%d, timeout=%dms.\r\n", 
                    conParamUpd->conIndex, conParamUpd->conInterval, 
                    conParamUpd->conLatency, conParamUpd->conTimeOut * 10);
            
            break;
        }
            
        case EVT_BLE_HOGPD_NTF_CFG:
        {
            msrcuBleHogpdNtfCfgInd_t* hogpdNtfCfgInd = &evt->param.hogpdNtfCfgInd;
            if(hogpdNtfCfgInd->cfg)
            {
                if(userBondEnable)
                {
                    MSPRINT("Bond success.\r\n");
                    userBondEnable = false;
                    osTimerStop(msrcuAppBondTimerId);
                    user_rcu_led_set(LED_STATE_BOND_SUCCESS);
                    
                    msrcuBondData.status = 1;
                    if(user_rcu_ble_bond_data_save(&msrcuBondData))
                        PRINTD(DBG_TRACE, "bond sata save error.\r\n");
                }
            }
            break;
        }
        
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
            
#if MSRCU_IR_SEND_ENABLE 
            //IR send start
            if((BLE_STATE_IDLE == msrcu_app_ble_get_state()
                    || BLE_STATE_ADVERTISING == msrcu_app_ble_get_state())
                    && userIrSendIsStop)
            {
                userIrCode.protocol = IR_PROT_NEC;
                userIrCode.param.necCode.addL = MSRCU_IR_NEC_ADD_L;
                userIrCode.param.necCode.addH = MSRCU_IR_NEC_ADD_H; 
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
        break;
        
        case EVT_KEY_RELEASE:
        {
            MSPRINT("Key %02d is released.\r\n", param->code);
            
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
//        {
//            if(param->behavior == EVT_KEY_PRESS)
//            {
//#if MSRCU_IR_LEARN_ENABLE
//                if(userIrLearnIsStop)
//                {
//                    userIrLearnIsStop = false;
//                    MSPRINT("IR learn start.\r\n");
//                    if(msrcu_app_ir_learn_start(1))//wait result at user_rcu_ir_callback
//                    {
//                        userIrLearnIsStop = true;
//                        MSPRINT("IR learn start error.\r\n");
//                    }
//                }
//                else
//                {
//                    if(msrcu_app_ir_learn_stop())//result at user_rcu_ir_callback
//                        MSPRINT("IR learn stop error.\r\n");
//                }
//#endif
//            }
//            else if(param->behavior == EVT_KEY_RELEASE){}
//            else if(param->behavior == EVT_KEY_LONG_PRESS){}
//        }
//        break; 

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
                    //msrcu_app_key_hid_send(msrcuKeycodeToHidKeycode(param->code, 0));
#if MSRCU_VOICE_ENABLE 
                    if(userVoiceIsStop)
                    {
#if MSRCU_MOTION_ENABLE 
                        if(!userMotionIsStop)
                        {
                            msrcu_app_motion_stop(); 
#if MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE
                            msrcu_app_motion_power_off();
#endif
                            osTimerStop(msrcuAppMotionTimerId);
                            userMotionIsPause = true;
                            MSPRINT("Motion stop.\r\n");
                            ledSt = LED_STATE_FUNC_MOTION_STOP;
                        }
#endif
                        if(!msrcu_app_voice_start())
                        {
                            userVoiceIsStop = false;
                            MSPRINT("Voice start.\r\n");
                            ledSt = LED_STATE_FUNC_VOICE_START;
                        }
                        else
                            MSPRINT("Voice start error.\r\n");
                    }
#endif
                }
            }
            else if(param->behavior == EVT_KEY_RELEASE)
            {
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
#if MSRCU_MOTION_ENABLE 
                    if(userMotionIsPause)
                    {
#if MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE
                        if(msrcu_app_motion_reinit())
                        {
                            MSPRINT("Motion reinit error.\r\n");
                            break;
                        }
                        msrcu_app_motion_power_on();
#endif
                        msrcu_app_motion_start();
                        userMotionIsPause = false;
                        MSPRINT("Motion start.\r\n");
                        osTimerStart(msrcuAppMotionTimerId, MOTION_TIMER_MS);
                        ledSt = LED_STATE_FUNC_MOTION_START;
                    }
#endif
                }
#endif
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
#if MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE
                        if(msrcu_app_motion_reinit())
                        {
                            MSPRINT("Motion reinit error.\r\n");
                            break;
                        }
                        msrcu_app_motion_power_on();
#endif
                        if(!msrcu_app_motion_start())
                        {
                            userMotionIsStop = false;
                            MSPRINT("Motion start.\r\n");
                            osTimerStart(msrcuAppMotionTimerId, MOTION_TIMER_MS);
                            ledSt = LED_STATE_FUNC_MOTION_START;
                        }
                        else
                            MSPRINT("Motion start error.\r\n");
                    }
                    else
                    {
                        if(!msrcu_app_motion_stop())
                        {
                            userMotionIsStop = true;
                            osTimerStop(msrcuAppMotionTimerId);
                            MSPRINT("Motion stop.\r\n"); 
                            ledSt = LED_STATE_FUNC_MOTION_STOP;
                        }
                        else
                            MSPRINT("Motion stop error.\r\n");
#if MSRCU_MOTION_SENSOR_POWER_CTRL_ENABLE
                        msrcu_app_motion_power_off();
#endif
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
        
#if MSRCU_MOTION_ENABLE
        case KEY_CODE_ENTER:
        {
            if(param->behavior == EVT_KEY_PRESS)
            {
                if(BLE_STATE_READY == msrcu_app_ble_get_state())
                {
                    if(userMotionIsStop)
                        msrcu_app_key_hid_send(msrcuKeycodeToHidKeycode(param->code, 0));
                    else
                    {
                        msg_hogpd_ntf_t *msg = malloc(sizeof(msg_hogpd_ntf_t));
                        if(!msg)
                            return;
                        msg->msg_id = MSG_HOGPD_NTF;
                        msg->conIndex = BLE_CON_IDX;
                        msg->instance = HID_MOUSE_INSTANCE;
                        msg->length = MOUSE_HID_PKG_SIZE;
                        uint8_t data[MOUSE_HID_PKG_SIZE] = {0};
                        data[MOUSE_HID_PKG_KEY_IDX] = MOUSE_BUTTON_LEFT;
//                        data[MOUSE_HID_PKG_X_IDX] = 0;
//                        data[MOUSE_HID_PKG_Y_IDX] = 0;
                        memcpy(msg->data, data, msg->length);
                        msg_put(msg);
                    }
                }
            }
            else if(param->behavior == EVT_KEY_RELEASE)
            {
                if(BLE_STATE_READY == msrcu_app_ble_get_state())
                {
                    msrcu_app_key_hid_send(msrcuKeycodeToHidKeycode(KEY_CODE_NULL, 0));
                    
                    msg_hogpd_ntf_t *msg = malloc(sizeof(msg_hogpd_ntf_t));
                    if(!msg)
                        return;
                    msg->msg_id = MSG_HOGPD_NTF;
                    msg->conIndex = BLE_CON_IDX;
                    msg->instance = HID_MOUSE_INSTANCE;
                    msg->length = MOUSE_HID_PKG_SIZE;
                    uint8_t data[MOUSE_HID_PKG_SIZE] = {0};
//                    data[MOUSE_HID_PKG_KEY_IDX] = MOUSE_BUTTON_NULL;
//                    data[MOUSE_HID_PKG_X_IDX] = 0;
//                    data[MOUSE_HID_PKG_Y_IDX] = 0;
                    memcpy(msg->data, data, msg->length);
                    msg_put(msg);
                }
            }
        }
        break;
#endif       
        case KEY_CODE_UP:
        case KEY_CODE_DOWN:
        case KEY_CODE_LEFT:
        case KEY_CODE_RIGHT:
        //case other key codes...
        
        default:
        {            
            if(param->behavior == EVT_KEY_PRESS)
            {
                if(BLE_STATE_READY == msrcu_app_ble_get_state())
                    msrcu_app_key_hid_send(msrcuKeycodeToHidKeycode(param->code, 0));
            }
            else if(param->behavior == EVT_KEY_RELEASE)
            {
                if(BLE_STATE_READY == msrcu_app_ble_get_state())
                    msrcu_app_key_hid_send(msrcuKeycodeToHidKeycode(KEY_CODE_NULL, 0));
            }
        }
        break;
    }
    
    user_rcu_led_set(ledSt);  
}
#if (MSRCU_IR_SEND_ENABLE || MSRCU_IR_LEARN_ENABLE)
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

#if MSRCU_MOTION_ENABLE
static void user_rcu_motion_timer_callback(void const *arg)
{
    if(!userMotionIsStop && BLE_STATE_READY == msrcu_app_ble_get_state())
    {
        msg_hogpd_ntf_t *msg = malloc(sizeof(msg_hogpd_ntf_t));
        if(!msg)
            return;
        
        msg->msg_id = MSG_HOGPD_NTF;
        msg->conIndex = BLE_CON_IDX;
        msg->instance = HID_MOUSE_INSTANCE;
        msg->length = MOUSE_HID_PKG_SIZE;
        uint8_t data[MOUSE_HID_PKG_SIZE] = {0};
//        data[MOUSE_HID_PKG_KEY_IDX] = MOUSE_BUTTON_NULL;
//        data[MOUSE_HID_PKG_X_IDX] = mouse.x;
//        data[MOUSE_HID_PKG_Y_IDX] = mouse.y;         
        memcpy(msg->data, data, msg->length);
        
        msg_put(msg);
    }
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
    
    memcpy(ble_bond_data[GAP_BOND_DATA].ltk.key, msrcuBondData.ltk.key, BLE_KEY_LEN); 
    ble_bond_data[GAP_BOND_DATA].ediv = msrcuBondData.ediv; 
    memcpy(ble_bond_data[GAP_BOND_DATA].randnb.nb, msrcuBondData.randNb.nb, BLE_RANDOM_NB_LEN);
    ble_bond_data[GAP_BOND_DATA].key_size = msrcuBondData.keySize;                
    
    //user_rcu_ble_bond_data_clear(&msrcuBondData);//for test
    
    //timer init
    err = user_rcu_timer_init();
    if(err)
        return err;
    
    //register callback
    cb->msrcu_app_ble_cb = user_rcu_ble_callback;
    cb->msrcu_app_key_cb = user_rcu_key_callback;
#if (MSRCU_IR_LEARN_ENABLE)
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
    user_rcu_power_timer_callback(NULL);
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
 *	Note: The _main_init in the RTX_CM_lib.h is
 *				main entry routine (OS is initialized
 *				in there).
 */
#if 0
int main (void)//for test
{
	hal_global_post_init();
    
	PRINTD(DBG_TRACE, "----------------\r\n");
	PRINTD(DBG_TRACE, "main start...\r\n");
    
    ble_config(0);
    
    user_rcu_ble_adv_start();
    
	while(1)
    {
		osDelay(1000);
	}
}
#else
int main (void)
{
	//Initialize platform.
	hal_global_post_init();
    
	//RF test mode for RCU production
	user_rcu_rf_test();
    
	//Debug UART port init
    hal_global_debug_uart_init();
	
	PRINTD(DBG_TRACE, "----------------\r\n");
	PRINTD(DBG_TRACE, "main start...\r\n");
	
	//MessageQ for main thread.
	msg_init();
    
	//BLE init
	ble_config(0);
	
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
		msg_t *p_msg;
		
		p_msg = msg_get(osWaitForever);
		if(!p_msg)
			break;
		
		handle_msg(p_msg);
		
		p_msg = msg_free(p_msg);
	}	
}
#endif

