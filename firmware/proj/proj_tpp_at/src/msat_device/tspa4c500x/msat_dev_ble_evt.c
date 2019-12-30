/**
 ****************************************************************************************
 *
 * @file msat_dev_ble_evt.c
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
extern void msat_fw_evt_ble_cb(msatEvtBle_t *evt);

/* Global Variable
 ****************************************************************************************
 */
static msatEvtBle_t bleEvt = {.code = MSAT_EVT_BLE_NULL, .param = {0}};

/* Function Definition
 ****************************************************************************************
 */
void msat_dev_ble_evt_cb(inb_evt_t *evt)
{
    switch(evt->evt_id)
    {
        case GAP_EVT_CONN_REQ:
            {
                bleEvt.code = MSAT_EVT_BLE_CON_STATE;
                bleEvt.param.conState.isConnected = true;
                msat_fw_evt_ble_cb(&bleEvt);
            }
            break;
        
        case GAP_EVT_DISCONNECT:
            {
                inb_evt_disc_ind_t *p = (inb_evt_disc_ind_t *)evt->param;
                
                bleEvt.code = MSAT_EVT_BLE_SEND_CFG;
                bleEvt.param.sendCfg.isEnabled = false;
                msat_fw_evt_ble_cb(&bleEvt);
                
                bleEvt.code = MSAT_EVT_BLE_CON_STATE;
                bleEvt.param.conState.isConnected = false;
                msat_fw_evt_ble_cb(&bleEvt);
            }
            break;
            
        case GATT_EVT_WRT_REQ:
            {
                inb_evt_write_req_ind_t *p = (inb_evt_write_req_ind_t*)evt->param;
                
                if(p->handle == msat_dev_function_ble_send_cfg_hdl_get())
                {
                    if(p->value[1] == 0x00 && p->value[0] == 0x01)
                    {
                        bleEvt.code = MSAT_EVT_BLE_SEND_CFG;
                        bleEvt.param.sendCfg.isEnabled = true;
                        msat_fw_evt_ble_cb(&bleEvt);
                    }
                    else if(p->value[1] == 0x00 && p->value[0] == 0x00)
                    {
                        bleEvt.code = MSAT_EVT_BLE_SEND_CFG;
                        bleEvt.param.sendCfg.isEnabled = false;
                        msat_fw_evt_ble_cb(&bleEvt);
                    }
                }
                else if(p->handle == msat_dev_function_ble_rcv_val_hdl_get())
                {
                    bleEvt.code = MSAT_EVT_BLE_RCV_DATA;
                    bleEvt.param.rcvData.len = p->length;
                    memcpy(&bleEvt.param.rcvData.data, p->value, p->length);
                    msat_fw_evt_ble_cb(&bleEvt);
                }
            }
            break;
        
        default:
            break;
    }
}
