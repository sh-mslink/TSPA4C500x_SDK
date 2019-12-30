/**
 ****************************************************************************************
 *
 * @file msat_fw_evt.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

/* Include Files
 ****************************************************************************************
 */
#include "msat_dev_system.h"
#include "msat_fw_function.h"
#include "msat_fw_evt.h"

/* Macro Definition
 ****************************************************************************************
 */
#define MSAT_OK     msat_fw_evt_command_out(MSAT_CMD_ID_OUT_OK, NULL, NULL)
#define MSAT_ERR    msat_fw_evt_command_out(MSAT_CMD_ID_OUT_ERROR, NULL, NULL)

/* Enum Definition
 ****************************************************************************************
 */

/* Struct Definition
 ****************************************************************************************
 */

/* Function Declaration
 ****************************************************************************************
 */
static msatErr_t msat_fw_evt_command_in(msatCmdIdIn cmdIn, uint8_t *param, uint16_t paramLen);
msatErr_t msat_fw_evt_command_out(msatCmdIdOut cmdOut, uint8_t *param, uint16_t paramLen);
void msat_fw_evt_ble_cb(msatEvtBle_t *evt);

/* Global Variable
 ****************************************************************************************
 */
static void (*msat_fw_evt_wakeup_app_cb)(void);
static void (*msat_fw_evt_cmd_in_app_cb)(msatEvtCmdIn_t *evt);
static void (*msat_fw_evt_data_in_no_cmd_app_cb)(char* data, uint16_t len);
static void (*msat_fw_evt_ble_app_cb)(msatEvtBle_t *evt);

/* Function Definition
 ****************************************************************************************
 */
//Compare input data with AT command that with no parameters
static bool isCmdNoParam(char *cmd, char *data, uint16_t dataLen)
{
    if(dataLen == strlen(cmd) && !strncmp(cmd, data, strlen(cmd)))
    {
        MSPRINT("=>");
        return true;
    }
    
    return false;
}

//Compare input data with AT command that with parameters and cut out the parameters.
static bool isCmdWithParam(char *cmd, char *data, uint16_t dataLen, uint8_t *param, uint16_t *paramLen)
{
    uint16_t i = 0;
    
    if(dataLen < strlen(cmd))//length error
        return false;
    
    if(data[dataLen - 1] != ')')//must end with ')'
        return false;
    
    *paramLen = 0;
    for(i = 0; i < dataLen - 2; i++)//except one-byte parameter and ')'
    {
        if(data[i] == '(')//must start with '('
        {
            *paramLen = dataLen - 2 - i;
            break;
        }
    }
    
    if(*paramLen)
    {
        if(!memcmp(cmd, data, dataLen - 1 - *paramLen))//compare cmd before "("
        {
            memcpy(param, data + (dataLen - 1 - *paramLen), *paramLen);//cut out the parameters.
            MSPRINT("=");
            return true;
        }
    }
    
    return false;
}

//Check parameters
static bool isParamValid(msatCmdIdIn cmdIn, uint8_t *param, uint16_t paramLen)
{
    if(!param || !paramLen)
        return false;
    
    switch(cmdIn)
    {
        case MSAT_CMD_ID_IN_MODE:
            {
                if(paramLen != 1)
                    return false;
                
                if(param[0] - '0' != MSAT_MODE_PT && param[0] - '0' != MSAT_MODE_OTA)
                    return false;
            }
            break;
        
        case MSAT_CMD_ID_IN_ADV_INTERVAL:
            {
                if(paramLen < 2 || paramLen > 5)
                    return false;
                
                for(uint16_t i = 0; i < paramLen; i++)
                {
                    if(param[i] < '0' || param[i] >'9')
                        return false;
                }
                
                uint16_t intv = atoi((char *)param);
                if(intv < 32 || intv > 16384)
                    return false;
            }
            break;
        
        case MSAT_CMD_ID_IN_ADV_DATA:
            {
                if(paramLen > MSAT_BLE_ADV_DATA_LENGTH_MAX * 2 || paramLen % 2)
                    return false;
                
                for(uint8_t i = 0; i < paramLen; i++)
                {
                    if(param[i] >= '0' && param[i] <= '9')
                        continue;
                    if(param[i] >= 'A' && param[i] <= 'F')
                        continue;
                    
                    return false;
                }
            }
            break;
        
        case MSAT_CMD_ID_IN_ADV_ONOFF:
            {
                if(paramLen != 1)
                    return false;
                
                if(param[0] != '0' && param[0] != '1')
                    return false;
            }
            break;
        
        default:
            return false;
            //break;
    }
    MSPRINT(">");
    return true;
}

void msat_fw_evt_wakeup_cb(void)
{
    msat_fw_evt_command_out(MSAT_CMD_ID_OUT_WAKEUP, NULL, NULL);
    
    msat_fw_evt_wakeup_app_cb();
}

msatErr_t msat_fw_evt_data_in_no_cmd(char *data, uint16_t len)
{
    msatErr_t err = ERR_NO_ERROR;
    
    err = msat_fw_function_data_in_no_cmd(data, len);
    if(!err)
        MSAT_OK;
    else
        MSAT_ERR;
    
    msat_fw_evt_data_in_no_cmd_app_cb(data, len);
    
    return err;
}

static uint8_t gParam[MSAT_CMD_LENGTH_MAX] = {0};
msatErr_t msat_fw_evt_data_in(char *buf, uint16_t len)
{
    msatErr_t err = ERR_NO_ERROR;
    char *data;
    uint16_t dataLen = 0;
//    uint8_t *param;
    uint16_t paramLen = 0;
    
    if(!buf || !len)
        return ERR_VALID_INPUT;
    
    //data length is less then MSAT_CMD_HEAD
    if(len < strlen(MSAT_CMD_HEAD))
        goto isNotMsatCmd;
    
    //data head is not MSAT_CMD_HEAD
    if(strncmp((char *)buf, MSAT_CMD_HEAD, strlen(MSAT_CMD_HEAD)))
        goto isNotMsatCmd;
    
    memset(gParam, 0, MSAT_CMD_LENGTH_MAX);
//    param = malloc(MSAT_CMD_LENGTH_MAX);
//    if(!param)
//        return ERR_NO_MEMORY;
    
    dataLen = len - strlen(MSAT_CMD_HEAD);
    data = (char *)buf + strlen(MSAT_CMD_HEAD);
    
    /// CMD with no parameters
    //MSAT_CMD_IN_RESET
    if(isCmdNoParam(MSAT_CMD_IN_RESET, data, dataLen))
        err = msat_fw_evt_command_in(MSAT_CMD_ID_IN_RESET, NULL, NULL);
    //MSAT_CMD_IN_VERSION
    else if(isCmdNoParam(MSAT_CMD_IN_VERSION, data, dataLen))
        err = msat_fw_evt_command_in(MSAT_CMD_ID_IN_VERSION, NULL, NULL);
    //MSAT_CMD_IN_ADV_STATE
    else if(isCmdNoParam(MSAT_CMD_IN_ADV_STATE, data, dataLen))
        err = msat_fw_evt_command_in(MSAT_CMD_ID_IN_ADV_STATE, NULL, NULL);
    //MSAT_CMD_IN_CON_STATE
    else if(isCmdNoParam(MSAT_CMD_IN_CON_STATE, data, dataLen))
        err = msat_fw_evt_command_in(MSAT_CMD_ID_IN_CON_STATE, NULL, NULL);
    //MSAT_CMD_IN_SEND_CFG_STATE
    else if(isCmdNoParam(MSAT_CMD_IN_SEND_CFG_STATE, data, dataLen))
        err = msat_fw_evt_command_in(MSAT_CMD_ID_IN_SEND_CFG_STATE, NULL, NULL);
    //MSAT_CMD_IN_DISCON
    else if(isCmdNoParam(MSAT_CMD_IN_DISCON, data, dataLen))
        err = msat_fw_evt_command_in(MSAT_CMD_ID_IN_DISCON, NULL, NULL);
    
    /// CMD with parameters
    //MSAT_CMD_IN_MODE
    else if(isCmdWithParam(MSAT_CMD_IN_MODE, data, dataLen, gParam, &paramLen))
    {
        if(isParamValid(MSAT_CMD_ID_IN_MODE, gParam, paramLen))
            err = msat_fw_evt_command_in(MSAT_CMD_ID_IN_MODE, gParam, paramLen);
        else
            return MSAT_ERR;
    }
    //MSAT_CMD_IN_ADV_INTERVAL
    else if(isCmdWithParam(MSAT_CMD_IN_ADV_INTERVAL, data, dataLen, gParam, &paramLen))
    {
        if(isParamValid(MSAT_CMD_ID_IN_ADV_INTERVAL, gParam, paramLen))
            err = msat_fw_evt_command_in(MSAT_CMD_ID_IN_ADV_INTERVAL, gParam, paramLen);
        else
            return MSAT_ERR;
    }
    //MSAT_CMD_IN_ADV_DATA
    else if(isCmdWithParam(MSAT_CMD_IN_ADV_DATA, data, dataLen, gParam, &paramLen))
    {
        if(isParamValid(MSAT_CMD_ID_IN_ADV_DATA, gParam, paramLen))
            err = msat_fw_evt_command_in(MSAT_CMD_ID_IN_ADV_DATA, gParam, paramLen);
        else
            return MSAT_ERR;
    }
    //MSAT_CMD_IN_ADV_ONOFF
    else if(isCmdWithParam(MSAT_CMD_IN_ADV_ONOFF, data, dataLen, gParam, &paramLen))
    {
        if(isParamValid(MSAT_CMD_ID_IN_ADV_ONOFF, gParam, paramLen))
            err = msat_fw_evt_command_in(MSAT_CMD_ID_IN_ADV_ONOFF, gParam, paramLen);
        else
            return MSAT_ERR;
    }
    //invalid command
    else
        return MSAT_ERR;
        
//    if(param)
//        free(param);
    
    return err;
    
isNotMsatCmd:
    err = msat_fw_evt_data_in_no_cmd(buf, len);
    
    return err;
}

msatErr_t msat_fw_evt_data_out(char *buf, uint16_t len)
{
    msatErr_t err = ERR_NO_ERROR;
    
    msat_dev_system_wakeup_out_set();
    
    if(MSAT_WAKUP_OUT_DELAY)
        msat_dev_system_delay_ms(MSAT_WAKUP_OUT_DELAY);
    
    err = msat_dev_system_data_out((uint8_t *)buf, len);
    
    msat_dev_system_wakeup_out_clear();
    
    return err;
}

static msatErr_t msat_fw_evt_command_in(msatCmdIdIn cmdIn, uint8_t *param, uint16_t paramLen)
{
    msatErr_t err = ERR_NO_ERROR;
    
    if(!cmdIn || cmdIn >= MSAT_CMD_ID_IN_MAX)
        return ERR_VALID_INPUT;
    
    MSPRINT("CMD in ID:%d, len %d", cmdIn, paramLen);
    if(paramLen)
        MSPRINT(", param \"%s\"", param);
    MSPRINT(".\r\n");
    
    switch(cmdIn)
    {
        case MSAT_CMD_ID_IN_RESET:
            {
                err = msat_fw_function_system_reset();
                if(err)
                    MSAT_ERR;
            }
            break;
        
        case MSAT_CMD_ID_IN_VERSION:
            {
                err = msat_fw_evt_command_out(MSAT_CMD_ID_OUT_VERSION, (uint8_t *)MSAT_VERSION, strlen(MSAT_VERSION));
                if(err)
                    MSAT_ERR;
            }
            break;
        
        case MSAT_CMD_ID_IN_MODE:
            {
                err = msat_fw_function_mode_set((msatMode)(param[0] - '0'));
                if(!err)
                    MSAT_OK;
                else
                    MSAT_ERR;
            }
            break;
        
        case MSAT_CMD_ID_IN_ADV_INTERVAL:
            {
                uint16_t intv = atoi((char *)param);
                err = msat_fw_function_ble_adv_interval_set(intv);
                if(!err)
                    MSAT_OK;
                else
                    MSAT_ERR;
            }
            break;
        
        case MSAT_CMD_ID_IN_ADV_DATA:
            {
                err = msat_fw_function_ble_adv_data_set(param, paramLen);
                if(!err)
                    MSAT_OK;
                else
                    MSAT_ERR;
            }
            break;
        
        case MSAT_CMD_ID_IN_ADV_ONOFF:
            {
                err = msat_fw_function_ble_adv_onoff_set(param[0] - '0');
                if(!err)
                    MSAT_OK;
                else
                    MSAT_ERR;
            }
            break;
        
        case MSAT_CMD_ID_IN_ADV_STATE:
            {
                uint8_t advIsOn = 0;
                err = msat_fw_function_ble_adv_onoff_get(&advIsOn);
                if(err)
                {
                    MSAT_ERR;
                    break;
                }
                
                advIsOn += '0';
                err = msat_fw_evt_command_out(MSAT_CMD_ID_OUT_ADV_STATE, &advIsOn, 1);
                if(err)
                {
                    MSAT_ERR;
                    break;
                }
            }
            break;
        
        case MSAT_CMD_ID_IN_CON_STATE:
            {
                uint8_t isCon = 0;
                err = msat_fw_function_ble_con_state_get(&isCon);
                if(err)
                {
                    MSAT_ERR;
                    break;
                }
                
                isCon += '0';
                err = msat_fw_evt_command_out(MSAT_CMD_ID_OUT_CON_STATE, &isCon, 1);
                if(err)
                {
                    MSAT_ERR;
                    break;
                }
            }
            break;
            
        case MSAT_CMD_ID_IN_SEND_CFG_STATE:
            {
                uint8_t isCfg = 0;
                err = msat_fw_function_ble_send_cfg_get(&isCfg);
                if(err)
                {
                    MSAT_ERR;
                    break;
                }
                
                isCfg += '0';
                err = msat_fw_evt_command_out(MSAT_CMD_ID_OUT_SEND_CFG_STATE, &isCfg, 1);
                if(err)
                {
                    MSAT_ERR;
                    break;
                }
            }
            break;
        
        case MSAT_CMD_ID_IN_DISCON:
            {
                err = msat_fw_function_ble_disconnect();
                if(!err)
                {
                    MSAT_OK;
                    
                    ///
                    msatEvtBle_t cfgEvt = {.code = MSAT_EVT_BLE_SEND_CFG, .param.sendCfg.isEnabled = false,};
                    msat_fw_evt_ble_cb(&cfgEvt);
                    
                    msatEvtBle_t conEvt = {.code = MSAT_EVT_BLE_CON_STATE, .param.conState.isConnected = false,};
                    msat_fw_evt_ble_cb(&conEvt);
                    ///
                }
                else
                    MSAT_ERR;
            }
            break;
        
        default:
            {
                err = ERR_VALID_INPUT;
                MSAT_ERR;
            }
            break;
    }
    
    if(!err)
    {
        msatEvtCmdIn_t *evt = malloc(sizeof(msatEvtCmdIn_t) + paramLen);
        if(!evt)
            return ERR_NO_MEMORY;
        
        evt->id = cmdIn;
        evt->len = paramLen;
        memcpy(evt->param, param, paramLen);
        
        msat_fw_evt_cmd_in_app_cb(evt);
        
        if(evt)
            free(evt);
    }
    
    return err;
}

msatErr_t msat_fw_evt_command_out(msatCmdIdOut cmdOut, uint8_t *param, uint16_t paramLen)
{
    msatErr_t err = ERR_NO_ERROR;
    char *data = NULL;
    uint16_t dataLen = strlen(MSAT_CMD_HEAD);
    
    if(!cmdOut || cmdOut >= MSAT_CMD_ID_OUT_MAX)
        return ERR_VALID_INPUT;
    
    switch(cmdOut)
    {
        case MSAT_CMD_ID_OUT_WAKEUP:
            {
                dataLen += strlen(MSAT_CMD_OUT_WAKEUP);
                data = malloc(dataLen);
                if(!data)
                    return ERR_NO_MEMORY;
                memcpy(data, MSAT_CMD_HEAD, strlen(MSAT_CMD_HEAD));
                memcpy(data + strlen(MSAT_CMD_HEAD), MSAT_CMD_OUT_WAKEUP, strlen(MSAT_CMD_OUT_WAKEUP));
            }
            break;
            
        case MSAT_CMD_ID_OUT_OK:
            {
                dataLen += strlen(MSAT_CMD_OUT_OK);
                data = malloc(dataLen);
                if(!data)
                    return ERR_NO_MEMORY;
                memcpy(data, MSAT_CMD_HEAD, strlen(MSAT_CMD_HEAD));
                memcpy(data + strlen(MSAT_CMD_HEAD), MSAT_CMD_OUT_OK, strlen(MSAT_CMD_OUT_OK));
            }
            break;
        
        case MSAT_CMD_ID_OUT_ERROR:
            {
                dataLen += strlen(MSAT_CMD_OUT_ERROR);
                data = malloc(dataLen);
                if(!data)
                    return ERR_NO_MEMORY;
                memcpy(data, MSAT_CMD_HEAD, strlen(MSAT_CMD_HEAD));
                memcpy(data + strlen(MSAT_CMD_HEAD), MSAT_CMD_OUT_ERROR, strlen(MSAT_CMD_OUT_ERROR));
            }
            break;
        
        case MSAT_CMD_ID_OUT_RESET:
            {
                dataLen += strlen(MSAT_CMD_OUT_RESET);
                data = malloc(dataLen);
                if(!data)
                    return ERR_NO_MEMORY;
                memcpy(data, MSAT_CMD_HEAD, strlen(MSAT_CMD_HEAD));
                memcpy(data + strlen(MSAT_CMD_HEAD), MSAT_CMD_OUT_RESET, strlen(MSAT_CMD_OUT_RESET));
            }
            break;
        
        case MSAT_CMD_ID_OUT_VERSION:
            {
                dataLen += strlen(MSAT_CMD_OUT_VERSION) + paramLen;
                data = malloc(dataLen);
                if(!data)
                    return ERR_NO_MEMORY;
                memcpy(data, MSAT_CMD_HEAD, strlen(MSAT_CMD_HEAD));
                memcpy(data + strlen(MSAT_CMD_HEAD), MSAT_CMD_OUT_VERSION, strlen(MSAT_CMD_OUT_VERSION));
                memcpy(data + strlen(MSAT_CMD_HEAD) + strlen(MSAT_CMD_OUT_VERSION), param, paramLen);
            }
            break;
        
        case MSAT_CMD_ID_OUT_ADV_STATE:
            {
                dataLen += strlen(MSAT_CMD_OUT_ADV_STATE) + paramLen;
                data = malloc(dataLen);
                if(!data)
                    return ERR_NO_MEMORY;
                memcpy(data, MSAT_CMD_HEAD, strlen(MSAT_CMD_HEAD));
                memcpy(data + strlen(MSAT_CMD_HEAD), MSAT_CMD_OUT_ADV_STATE, strlen(MSAT_CMD_OUT_ADV_STATE));
                memcpy(data + strlen(MSAT_CMD_HEAD) + strlen(MSAT_CMD_OUT_ADV_STATE), param, paramLen);
            }
            break;
        
        case MSAT_CMD_ID_OUT_CON_STATE:
            {
                dataLen += strlen(MSAT_CMD_OUT_CON_STATE) + paramLen;
                data = malloc(dataLen);
                if(!data)
                    return ERR_NO_MEMORY;
                memcpy(data, MSAT_CMD_HEAD, strlen(MSAT_CMD_HEAD));
                memcpy(data + strlen(MSAT_CMD_HEAD), MSAT_CMD_OUT_CON_STATE, strlen(MSAT_CMD_OUT_CON_STATE));
                memcpy(data + strlen(MSAT_CMD_HEAD) + strlen(MSAT_CMD_OUT_CON_STATE), param, paramLen);
            }
            break;
        
        case MSAT_CMD_ID_OUT_SEND_CFG_STATE:
            {
                dataLen += strlen(MSAT_CMD_OUT_SEND_CFG_STATE) + paramLen;
                data = malloc(dataLen);
                if(!data)
                    return ERR_NO_MEMORY;
                memcpy(data, MSAT_CMD_HEAD, strlen(MSAT_CMD_HEAD));
                memcpy(data + strlen(MSAT_CMD_HEAD), MSAT_CMD_OUT_SEND_CFG_STATE, strlen(MSAT_CMD_OUT_SEND_CFG_STATE));
                memcpy(data + strlen(MSAT_CMD_HEAD) + strlen(MSAT_CMD_OUT_SEND_CFG_STATE), param, paramLen);
            }
            break;
        
        default:
            return ERR_VALID_INPUT;
            //break;
    }
    
    err = msat_fw_evt_data_out(data, dataLen);
    
    if(data)
        free(data);
    
    return err;
}

void msat_fw_evt_ble_cb(msatEvtBle_t *evt)
{
    switch(evt->code)
    {
        case MSAT_EVT_BLE_CON_STATE:
            {
                uint8_t setCon = 0;
                if(evt->param.conState.isConnected)
                    setCon = 1;
                
                uint8_t isCon = 0;
                if(msat_fw_function_ble_con_state_get(&isCon))
                    return;
                
                if(isCon == setCon)//no need to set
                    return;
                
                if(msat_fw_function_ble_con_state_set(setCon))
                    return;
                
                ///
                if(setCon)
                {
                    uint8_t isOn = '0';
                    if(msat_fw_evt_command_out(MSAT_CMD_ID_OUT_ADV_STATE, &isOn, 1))
                        return;
                }
                ///
                
                setCon += '0';
                if(msat_fw_evt_command_out(MSAT_CMD_ID_OUT_CON_STATE, &setCon, 1))
                    return;
            }
            break;
        
        case MSAT_EVT_BLE_SEND_CFG:
            {
                uint8_t setCfg = 0;
                if(evt->param.sendCfg.isEnabled)
                    setCfg = 1;
                
                uint8_t isCfg = 0;
                if(msat_fw_function_ble_send_cfg_get(&isCfg))
                    return;
                
                if(isCfg == setCfg)//no need to set
                    return;
                    
                if(msat_fw_function_ble_send_cfg_set(setCfg))
                    return;
                
                setCfg += '0';
                if(msat_fw_evt_command_out(MSAT_CMD_ID_OUT_SEND_CFG_STATE, &setCfg, 1))
                    return;
            }
            break;
        
        case MSAT_EVT_BLE_RCV_DATA:
            {
                if(msat_fw_evt_data_out((char*)&evt->param.rcvData.data, evt->param.rcvData.len))
                    return;
            }
            break;
        
        default:
            break;
    }
    
    msat_fw_evt_ble_app_cb(evt);
}

msatErr_t msat_fw_evt_cb_set(msatEvtCallback_t *cb)
{
    msat_fw_evt_wakeup_app_cb = cb->wupCb;
    msat_fw_evt_cmd_in_app_cb = cb->cmdInCb;
    msat_fw_evt_data_in_no_cmd_app_cb = cb->noCmdCb;
    msat_fw_evt_ble_app_cb = cb->bleCb;
    
    return ERR_NO_ERROR;
}

