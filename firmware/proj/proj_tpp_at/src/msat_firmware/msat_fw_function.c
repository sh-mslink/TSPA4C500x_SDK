/**
 ****************************************************************************************
 *
 * @file msat_fw_function.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

/* Include Files
 ****************************************************************************************
 */
#include "msat_dev_system.h"
#include "msat_dev_function.h"
#include "msat_fw_device.h"

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
msatMode msat_fw_function_mode_get(void);
msatErr_t msat_fw_function_ble_adv_onoff_set(uint8_t on);
msatErr_t msat_fw_function_ble_adv_onoff_get(uint8_t *isOn);
msatErr_t msat_fw_function_ble_send_cfg_get(uint8_t *isCfg);
static msatErr_t msat_fw_function_ble_send_data(uint8_t *data, uint16_t len);

/* Global Variable
 ****************************************************************************************
 */
static msatMode gMsatMode = MSAT_MODE_NULL;

static uint16_t gMsatAdvLatency = 0;

static uint16_t gMsatAdvLen = 0;
static uint8_t gMsatAdvData[MSAT_BLE_ADV_DATA_LENGTH_MAX] = {0};

static bool gMsatAdvIsOn = false;

static bool gMsatBleIsCon = false;

static bool gMsatBleSendIsCfg = false;

/* Function Definition
 ****************************************************************************************
 */
msatErr_t msat_fw_function_data_in_no_cmd(char *data, uint16_t len)
{
    msatErr_t err = ERR_NO_ERROR;
    
    switch(msat_fw_function_mode_get())
    {
        case MSAT_MODE_PT:
            {
                uint8_t isCfg = 0;
                err = msat_fw_function_ble_send_cfg_get(&isCfg);
                if(err)
                    return err;
                
                if(!isCfg)
                    return ERR_NOT_SUPPORT;
                
                err = msat_fw_function_ble_send_data((uint8_t *)data, len);
                if(err)
                    return err;
            }
            break;
            
        case MSAT_MODE_OTA:
            {
                return ERR_NOT_SUPPORT;
            }
            //break;
        
        default:
            {
                return ERR_NOT_SUPPORT;
            }
            //break;
    }
    
    return err;
}

msatErr_t msat_fw_function_system_reset(void)
{
    MSPRINT("Systerm reset.\r\n");
    
    return msat_dev_function_system_reset();
}

static msatErr_t msat_fw_function_mode_init(void)
{
    msatErr_t err = ERR_NO_ERROR;
    
    switch(msat_fw_function_mode_get())
    {
        case MSAT_MODE_PT:
            {
                gMsatAdvLatency = MSAT_ADV_INTERVAL;
                gMsatAdvLen = strlen(MSAT_ADV_DATA);
                if(gMsatAdvLen > MSAT_BLE_ADV_DATA_LENGTH_MAX)
                    gMsatAdvLen = MSAT_BLE_ADV_DATA_LENGTH_MAX;
                memcpy(gMsatAdvData, MSAT_ADV_DATA, gMsatAdvLen);
            }
            break;
            
        case MSAT_MODE_OTA:
            {
                gMsatAdvLatency = MSAT_ADV_INTERVAL;
                gMsatAdvLen = strlen(MSAT_ADV_DATA);
                if(gMsatAdvLen > MSAT_BLE_ADV_DATA_LENGTH_MAX)
                    gMsatAdvLen = MSAT_BLE_ADV_DATA_LENGTH_MAX;
                memcpy(gMsatAdvData, MSAT_ADV_DATA, gMsatAdvLen);
                
                err = msat_dev_function_ble_adv_start(gMsatAdvLatency, gMsatAdvData, gMsatAdvLen);
                if(!err)
                {
                    MSPRINT("OTA advertising start.\r\n");
                }
                else
                {
                    MSPRINT("OTA advertising start error: %d.\r\n", err);
                    return err;
                }
            }
            break;
        
        default:
            break;
    }
    
    return err;
}

msatErr_t msat_fw_function_mode_set(msatMode mode)
{
    msatErr_t err = ERR_NO_ERROR;
    
    if(!msat_fw_device_is_mode_supported(mode))
        return ERR_NOT_SUPPORT;
    
    if(msat_fw_function_mode_get() == MSAT_MODE_NULL)
    {
        gMsatMode = mode;
        MSPRINT("Mode set: %d.\r\n", msat_fw_function_mode_get());
        
        err = msat_fw_function_mode_init();
        if(err)
            return err;
    }
    else
        return ERR_NOT_SUPPORT;
    
    return ERR_NO_ERROR;
}

msatMode msat_fw_function_mode_get(void)
{
    return gMsatMode;
}

msatErr_t msat_fw_function_ble_adv_interval_set(uint16_t advIntv)
{
    msatErr_t err = ERR_NO_ERROR;
    
    if(msat_fw_function_mode_get() != MSAT_MODE_PT)
        return ERR_NOT_SUPPORT;
    
    gMsatAdvLatency = advIntv;
    MSPRINT("gMsatAdvLatency: 0x%X.\r\n", gMsatAdvLatency);
    
    uint8_t advIsOn = 0;
    err = msat_fw_function_ble_adv_onoff_get(&advIsOn);
    if(!err && advIsOn)
    {
        err = msat_fw_function_ble_adv_onoff_set(0);
        if(err)
            return err;
        err = msat_fw_function_ble_adv_onoff_set(1);
        if(err)
            return err;
    }
    
    return err;
}

msatErr_t msat_fw_function_ble_adv_data_set(uint8_t *advData, uint16_t advLen)
{
    msatErr_t err = ERR_NO_ERROR;
    uint16_t i = 0;
    
    if(msat_fw_function_mode_get() != MSAT_MODE_PT)
        return ERR_NOT_SUPPORT;
    
    for(i = 0; i < advLen / 2; i++)
    {
        int tmp;
        sscanf((char *)advData + 2 * i, "%2X", &tmp);
        gMsatAdvData[i] = tmp;
    }
    MSPRINT("gMsatAdvData set:");
    for(i = 0; i < advLen / 2; i++)
        MSPRINT(" %02X", gMsatAdvData[i]);
    MSPRINT(".\r\n");
    
    ///TODO ?? adv data check
    
    gMsatAdvLen = advLen / 2;
    MSPRINT("gMsatAdvLen set: %d.\r\n", gMsatAdvLen);
    
    uint8_t advIsOn = 0;
    err = msat_fw_function_ble_adv_onoff_get(&advIsOn);
    if(!err && advIsOn)
    {
        err = msat_fw_function_ble_adv_onoff_set(0);
        if(err)
            return err;
        err = msat_fw_function_ble_adv_onoff_set(1);
        if(err)
            return err;
    }
    
    return err;
}

msatErr_t msat_fw_function_ble_adv_onoff_set(uint8_t on)
{
    msatErr_t err = ERR_NO_ERROR;
    
    if(msat_fw_function_mode_get() != MSAT_MODE_PT)
        return ERR_NOT_SUPPORT;
    
    uint8_t advIsOn = 0;
    err = msat_fw_function_ble_adv_onoff_get(&advIsOn);
    if(err)
        return err;
    
    if(on)//set on
    {
        if(advIsOn)//already on, stop at first
        {
            err = msat_dev_function_ble_adv_stop();
            if(!err)
            {
                MSPRINT("Advertising stop.\r\n");
                
                gMsatAdvIsOn = false;
                MSPRINT("gMsatAdvIsOn set: FALSE.\r\n");
            }
            else
            {
                MSPRINT("Advertising stop error: %d.\r\n", err);
                return err;
            }
        }
        
        err = msat_dev_function_ble_adv_start(gMsatAdvLatency, gMsatAdvData, gMsatAdvLen);
        if(!err)
        {
            MSPRINT("Advertising start.\r\n");
            
            gMsatAdvIsOn = true;
            MSPRINT("gMsatAdvIsOn set: TRUE.\r\n");
        }
        else
        {
            MSPRINT("Advertising start error: %d.\r\n", err);
            return err;
        }
    }
    else//set off
    {
        if(!advIsOn)
        {
            MSPRINT("Advertising already stoped.\r\n");
            return ERR_NO_ERROR;
        }
        
        err = msat_dev_function_ble_adv_stop();
        if(!err)
        {
            MSPRINT("Advertising stop.\r\n");
            
            gMsatAdvIsOn = false;
            MSPRINT("gMsatAdvIsOn set: FALSE.\r\n");
        }
        else
        {
            MSPRINT("Advertising stop error: %d.\r\n", err);
            return err;
        }
    }
    
    return err;
}

msatErr_t msat_fw_function_ble_adv_onoff_get(uint8_t *isOn)
{
    if(msat_fw_function_mode_get() != MSAT_MODE_PT)
        return ERR_NOT_SUPPORT;
    
    if(gMsatAdvIsOn)
        *isOn = 1;
    else
        *isOn = 0;
    
    return ERR_NO_ERROR;
}

msatErr_t msat_fw_function_ble_con_state_set(uint8_t con)
{
    if(msat_fw_function_mode_get() != MSAT_MODE_PT)
        return ERR_NOT_SUPPORT;
    
    if(con)
    {
        MSPRINT("BLE is connected.\r\n");
        
        ///
        gMsatAdvIsOn = false;
        MSPRINT("gMsatAdvIsOn set: FALSE.\r\n");
        ///
        
        gMsatBleIsCon = true;
        MSPRINT("gMsatBleIsCon set: TRUE.\r\n");
    }
    else
    {
        MSPRINT("BLE is disconnected.\r\n");
        
        gMsatBleIsCon = false;
        MSPRINT("gMsatBleIsCon set: FALSE.\r\n");
    }
    
    return ERR_NO_ERROR;
}

msatErr_t msat_fw_function_ble_con_state_get(uint8_t *isCon)
{
    if(msat_fw_function_mode_get() != MSAT_MODE_PT)
        return ERR_NOT_SUPPORT;
    
    if(gMsatBleIsCon)
        *isCon = 1;
    else
        *isCon = 0;
    
    return ERR_NO_ERROR;
}

msatErr_t msat_fw_function_ble_send_cfg_set(uint8_t cfg)
{
    msatErr_t err = ERR_NO_ERROR;
    uint8_t isCfg = 0;
    
    if(msat_fw_function_mode_get() != MSAT_MODE_PT)
        return ERR_NOT_SUPPORT;
    
    err = msat_fw_function_ble_send_cfg_get(&isCfg);
    if(err)
        return err;
    
    if(cfg && isCfg)
    {
        MSPRINT("BLE send is already enabled.\r\n");
        return ERR_NO_ERROR;
    }
    else if(!cfg && !isCfg)
    {
        MSPRINT("BLE send is already disabled.\r\n");
        return ERR_NO_ERROR;
    }
    
    if(cfg)
    {
        MSPRINT("BLE send enabled.\r\n");
        
        gMsatBleSendIsCfg = true;
        MSPRINT("gMsatBleSendIsCfg set: TRUE.\r\n");
    }
    else
    {
        MSPRINT("BLE send disabled.\r\n");
        
        gMsatBleSendIsCfg = false;
        MSPRINT("gMsatBleSendIsCfg set: FALSE.\r\n");
    }
    
    return ERR_NO_ERROR;
}

msatErr_t msat_fw_function_ble_send_cfg_get(uint8_t *isCfg)
{
    if(msat_fw_function_mode_get() != MSAT_MODE_PT)
        return ERR_NOT_SUPPORT;
    
    if(gMsatBleSendIsCfg)
        *isCfg = 1;
    else
        *isCfg = 0;
    
    return ERR_NO_ERROR;
}

static msatErr_t msat_fw_function_ble_send_data(uint8_t *data, uint16_t len)
{
    msatErr_t err = ERR_NO_ERROR;
    uint16_t bytes = len;
    uint16_t i = 0;
    
    if(msat_fw_function_mode_get() != MSAT_MODE_PT)
        return ERR_NOT_SUPPORT;
    
    uint8_t isCfg = 0;
    err = msat_fw_function_ble_send_cfg_get(&isCfg);
    if(err)
        return err;
    
    if(!isCfg)
        return ERR_NOT_SUPPORT;
    
    for(i = 0; i <= len / MSAT_BLE_PT_DATA_LENGTH_MAX; i++)
    {
        if(!bytes)
            break;
        
        if(bytes >= MSAT_BLE_PT_DATA_LENGTH_MAX)
        {
            err = msat_dev_function_ble_send_data(
                    data + i * MSAT_BLE_PT_DATA_LENGTH_MAX, 
                    MSAT_BLE_PT_DATA_LENGTH_MAX);
            
            bytes -= MSAT_BLE_PT_DATA_LENGTH_MAX;
        }
        else
        {
            err = msat_dev_function_ble_send_data(
                    data + i * MSAT_BLE_PT_DATA_LENGTH_MAX, 
                    bytes);
        }
        
        if(err)
            return err;
    }
    
    return err;
}

msatErr_t msat_fw_function_ble_disconnect(void)
{
    msatErr_t err = ERR_NO_ERROR;
    
    if(msat_fw_function_mode_get() != MSAT_MODE_PT)
        return ERR_NOT_SUPPORT;
    
    uint8_t isCon = 0;
    err = msat_fw_function_ble_con_state_get(&isCon);
    if(err)
        return err;
    
    if(!isCon)
    {
        MSPRINT("BLE is already disconnected.\r\n");
        return ERR_NO_ERROR;
    }
    
    err = msat_dev_function_ble_disconnect();
    if(!err)
    {
        MSPRINT("BLE disconnect.\r\n");
    }
    else
    {
        MSPRINT("BLE disconnect error: %d.\r\n", err);
        return err;
    }
    
    return err;
}
