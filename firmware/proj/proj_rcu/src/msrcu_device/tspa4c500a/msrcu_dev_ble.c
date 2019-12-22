/**
 ****************************************************************************************
 *
 * @file msrcu_dev_ble.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
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

/* Enum Definition
 ****************************************************************************************
 */

/* Struct Definition
 ****************************************************************************************
 */

/* Function Declaration
 ****************************************************************************************
 */
static msrcuErr_t msrcu_dev_ble_update_connection_parameter(void);

#if (MSRCU_VOICE_ENABLE && MSRCU_BLE_VOICE_ATV_ENABLE)
extern void atv_task_send_enable(void);
extern void atv_task_send_disable(void);
#endif

/* Global Variable
 ****************************************************************************************
 */
static void (*msrcu_evt_ble_cb)(msrcuEvtBle_t *evt);

static msrcuBleState_t bleSt = BLE_STATE_NULL;
static int actAdvIdx = 0;
static bool conParamUpdFlag = false;

/* Function Definition
 ****************************************************************************************
 */
msrcuBleState_t msrcu_dev_ble_get_state(void)
{
    return bleSt;
}

static void msrcu_dev_ble_set_state(msrcuBleState_t state)
{
    if(bleSt != state)
    {
        bleSt = state;
        MSPRINT("MSRCU BLE STATE: %d\r\n", msrcu_dev_ble_get_state());
        
        if(msrcu_dev_ble_get_state() == BLE_STATE_READY)
        {
            if(conParamUpdFlag)
            {
                msrcu_dev_ble_update_connection_parameter();
                conParamUpdFlag = false;
            }
            
            msrcuEvtBle_t* msBleEvt = malloc(sizeof(msrcuEvtBle_t));
            if(!msBleEvt)
            {
                MSPRINT("%s no memory\r\n", __func__);
                return;
            }
            
            msBleEvt->code = EVT_BLE_RCU_READY;
            
            msrcuBleRcuReady_t *rcuReady = &msBleEvt->param.rcuReady;
            rcuReady->conIndex = BLE_CON_IDX;
            msrcu_evt_ble_cb(msBleEvt);
            
            if(msBleEvt)
                free(msBleEvt);
        }
    }
}

static msrcuErr_t msrcu_dev_ble_update_connection_parameter(void)
{
    inb_conn_param_update_t *p_upd = (inb_conn_param_update_t *)malloc(sizeof(inb_conn_param_update_t));
    if(!p_upd)
        return ERR_NO_MEMORY;
    
    p_upd->intv_min = MSRCU_BLE_CNT_INTERVAL_MIN;
    p_upd->intv_max = MSRCU_BLE_CNT_INTERVAL_MAX;
    p_upd->latency = MSRCU_BLE_CNT_LATENCY;
    p_upd->time_out = MSRCU_BLE_CNT_TIMEOUT;
    p_upd->ce_len_min = 0x0001;
    p_upd->ce_len_max = 0xffff;
    
    int err = inb_conn_param_update(BLE_CON_IDX, p_upd);
    
    if(p_upd)
        free(p_upd);
    
    if(err)
        PRINTD(DBG_TRACE, "inb_conn_param_update error:0x%02X.\r\n", err);
    
    return ERR_NO_ERROR;
}

static void msrcu_dev_ble_gap_evt(uint16_t eid, void *pv)
{
    msrcuEvtBle_t* msBleEvt = malloc(sizeof(msrcuEvtBle_t));
    if(!msBleEvt)
    {
        MSPRINT("%s no memory\r\n", __func__);
        return;
    }
    
    switch(eid)
    {
        case GAP_EVT_CONN_REQ:
            {
                msrcu_dev_ble_set_state(BLE_STATE_CONNECTED);
                
                inb_evt_conn_req_t *p_para = (inb_evt_conn_req_t *)pv;
                
                if((p_para->con_interval < MSRCU_BLE_CNT_INTERVAL_MIN)
                        || (p_para->con_interval > MSRCU_BLE_CNT_INTERVAL_MAX)
                        || (p_para->con_latency != MSRCU_BLE_CNT_LATENCY)
                        || (p_para->sup_to != MSRCU_BLE_CNT_TIMEOUT))
                    conParamUpdFlag = true;//wait for BLE_STATE_READY
                else
                    conParamUpdFlag = false;
                
                msBleEvt->code = EVT_BLE_CONNETED;
                
                msrcuBleConInd_t* conInd = &msBleEvt->param.conInd;
                conInd->conIndex = p_para->conidx;
                conInd->conInterval = p_para->con_interval;
                conInd->conLatency = p_para->con_latency;
                conInd->conTimeOut = p_para->sup_to;
                conInd->peerAddrType = p_para->peer_addr_type;
                memcpy(conInd->peerAddr.addr, p_para->peer_addr.addr, BLE_BDADDR_LEN);
                
                msrcu_evt_ble_cb(msBleEvt);
            }
            break;
        
        case GAP_EVT_DISCONNECT:
            {
                msrcu_dev_ble_set_state(BLE_STATE_IDLE);
                
                conParamUpdFlag = false;
                
#if (MSRCU_VOICE_ENABLE && MSRCU_BLE_VOICE_ATV_ENABLE)
                atv_task_send_disable();
#endif
                
                msBleEvt->code = EVT_BLE_DISCONNETED;
                
                inb_evt_disc_ind_t *p_para = (inb_evt_disc_ind_t *)pv;
                msrcuBleDisconInd_t* disconInd = &msBleEvt->param.disconInd;
                disconInd->conIndex = p_para->conidx;
                disconInd->reason = (bleError_t)p_para->reason;
                
                msrcu_evt_ble_cb(msBleEvt);
            }
            break;
        
        case GAP_EVT_CONN_PARAM_UPD:
            {
                msBleEvt->code = EVT_BLE_CON_PRAM_UPD;
                
                inb_evt_conn_param_upd_t *p_para = (inb_evt_conn_param_upd_t *)pv;
                
                if((p_para->con_interval < MSRCU_BLE_CNT_INTERVAL_MIN)
                        || (p_para->con_interval > MSRCU_BLE_CNT_INTERVAL_MAX)
                        || (p_para->con_latency != MSRCU_BLE_CNT_LATENCY)
                        || (p_para->sup_to != MSRCU_BLE_CNT_TIMEOUT))
                {
                    if(msrcu_dev_ble_get_state() == BLE_STATE_READY)
                        msrcu_dev_ble_update_connection_parameter();
                    else
                        conParamUpdFlag = true;//wait for BLE_STATE_READY
                }
                
                msrcuBleConParamUpd_t *conParamUpd = &msBleEvt->param.conParamUpd;
                conParamUpd->conIndex = p_para->conidx;
                conParamUpd->conInterval = p_para->con_interval;
                conParamUpd->conLatency = p_para->con_latency;
                conParamUpd->conTimeOut= p_para->sup_to;
                
                msrcu_evt_ble_cb(msBleEvt);
            }
            break;
        
        case GAP_EVT_ENCRYPT_IND:
            {
                msrcu_dev_ble_set_state(BLE_STATE_READY);
            }
            break;
        
        
        default:
            break;
    }
    
    if(msBleEvt)
        free(msBleEvt);
}

static void msrcu_dev_ble_gatt_evt(uint16_t eid, void *pv)
{
    switch(eid)
    {
        case GATT_EVT_WRT_REQ:
            {
                inb_evt_write_req_ind_t *p_para = (inb_evt_write_req_ind_t*)pv;
                
#if (MSRCU_VOICE_ENABLE && MSRCU_BLE_VOICE_ATV_ENABLE)
                static bool ntfCfg[2] = {false, false};
                if(p_para->handle == atv_get_svc_hdl() + ATVV_IDX_CHAR_TX_VAL)
                {
                    atv_voice_char_tx_receive(p_para->conidx, p_para->value, p_para->length);
                }
                else if(p_para->handle == atv_get_svc_hdl() + ATVV_IDX_CHAR_RX_CFG)
                {
                    if(p_para->value[1] == 0x00 && p_para->value[0] == 0x01)
                    {
                        PRINTD(DBG_TRACE, "ATVV_CHAR_RX notify enable\r\n");
                        ntfCfg[0] = true;
                        if(ntfCfg[0] && ntfCfg[1])
                            atv_task_send_enable();
                    }
                    else if(p_para->value[1] == 0x00 && p_para->value[0] == 0x00)
                    {
                        PRINTD(DBG_TRACE, "ATVV_CHAR_RX notify disable\r\n");
                        ntfCfg[0] = false;
                        atv_task_send_disable();
                    }
                }
                else if(p_para->handle == atv_get_svc_hdl() + ATVV_IDX_CHAR_CTL_CFG)
                {
                    if(p_para->value[1] == 0x00 && p_para->value[0] == 0x01)
                    {
                        PRINTD(DBG_TRACE, "ATVV_CHAR_CTL notify enable\r\n");
                        ntfCfg[1] = true;
                        if(ntfCfg[0] && ntfCfg[1])
                            atv_task_send_enable();
                    }
                    else if(p_para->value[1] == 0x00 && p_para->value[0] == 0x00)
                    {
                        PRINTD(DBG_TRACE, "ATVV_CHAR_CTL notify disable\r\n");
                        ntfCfg[1] = false;
                        atv_task_send_disable();
                    }
                }
#endif
            }
            break;
        
        default:
            break;
    }
}

static void msrcu_dev_ble_hogp_evt(uint16_t eid, void *pv)
{
    switch(eid)
    {
        case HOGPD_EVT_NTF_CFG_IND:
            {
                inb_evt_hogpd_ntf_cfg_ind_t *param = (inb_evt_hogpd_ntf_cfg_ind_t *)pv;
                
                if((param->ntf_cfg[param->conidx] & INB_HOGPD_CFG_REPORT_NTF_EN) != 0)
                {
                    if(param->ntf_cfg[param->conidx] == 
                            (INB_HOGPD_CFG_REPORT_NTF_EN 
                            | (INB_HOGPD_CFG_REPORT_NTF_EN << 1) 
                            | (INB_HOGPD_CFG_REPORT_NTF_EN << 2)))
                    {
                        msrcu_dev_ble_set_state(BLE_STATE_READY);
                    }
                }
            }
        break;
        
        default:
            break;
    }
}

void msrcu_dev_ble_evt_cb(inb_evt_t *evt, void *param)
{
    switch(evt->evt_id & 0xFF00)
    {
        case GAP_EVT_CODE:
            msrcu_dev_ble_gap_evt(evt->evt_id, (void *)&evt->param);
            break;
        
        case GATT_EVT_CODE:
            msrcu_dev_ble_gatt_evt(evt->evt_id, (void *)&evt->param);
            break;
        
        case BAS_EVT_CODE:
            break;
        
        case DIS_EVT_CODE:
            break;
        
        case HOGP_EVT_CODE:
            msrcu_dev_ble_hogp_evt(evt->evt_id, (void *)&evt->param);
            break;
        
        default:
            break;
    }
}

msrcuErr_t msrcu_dev_ble_init(void (*cb)(msrcuEvtBle_t *evt))
{
    msrcu_evt_ble_cb = cb;
    
    msrcu_dev_ble_set_state(BLE_STATE_IDLE);
    
    return ERR_NO_ERROR;
}

msrcuErr_t msrcu_dev_ble_adv_start(msrcuBleAdv_t* adv)
{
    inb_actv_create_t inbAdv = {0};
    
    switch(adv->pduType)
    {
        case ADV_IND:
            inbAdv.adv_param.disc_mode = ADV_MODE_GEN_DISC;
            inbAdv.adv_param.prop = ADV_PROP_UNDIR_CONN;
            break;
        
        case ADV_DIRECT_IND:
            inbAdv.adv_param.disc_mode = ADV_MODE_NON_DISC;
            inbAdv.adv_param.prop = ADV_PROP_DIR_CONN;
            break; 
            
        default:
            return ERR_VALID_INPUT;
    }
    
    if(adv->channel & ADV_CHANNEL_37)
        inbAdv.adv_param.prim_cfg.chnl_map |= CHANNEL_37;
    if(adv->channel & ADV_CHANNEL_38)
        inbAdv.adv_param.prim_cfg.chnl_map |= CHANNEL_38;
    if(adv->channel & ADV_CHANNEL_39)
        inbAdv.adv_param.prim_cfg.chnl_map |= CHANNEL_39;
    
    inbAdv.option = 0;
    inbAdv.own_addr_type = 0;
    inbAdv.adv_param.type = ADV_TYPE_LEGACY;
    inbAdv.adv_param.max_tx_pwr = 0;
    inbAdv.adv_param.filter_pol = ADV_FILT_ALLOW_SCAN_ANY_CON_ANY;
    inbAdv.adv_param.peer_addr.addr_type = adv->peerAddrType;
    memcpy(inbAdv.adv_param.peer_addr.addr.addr, adv->peerAddr.addr, BLE_ADDR_LEN);
    inbAdv.adv_param.prim_cfg.adv_intv_min = adv->intvMin;
    inbAdv.adv_param.prim_cfg.adv_intv_max = adv->intvMax;
    inbAdv.adv_param.prim_cfg.phy = PHY_LE_1MBPS;
    
    if(inb_actv_create(&inbAdv, &actAdvIdx) != INB_ERR_NO_ERROR)
        return ERR_OTHERS;
    
    if(adv->pduType != ADV_DIRECT_IND)
    {
        if(inb_actv_data(actAdvIdx, 0, adv->advData, adv->advDataLen) != INB_ERR_NO_ERROR)
            return ERR_OTHERS;
        if(inb_actv_data(actAdvIdx, 1, adv->scanRspData, adv->scanRspDataLen) != INB_ERR_NO_ERROR)
            return ERR_OTHERS;
    }
    
    inb_actv_start_t adv_start = {0};
    adv_start.option = 0;
    adv_start.u.adv_param.duration = 0;
    adv_start.u.adv_param.max_adv_evt = 0;
    if(inb_actv_start(actAdvIdx, &adv_start) != INB_ERR_NO_ERROR)
        return ERR_OTHERS;
    
    msrcu_dev_ble_set_state(BLE_STATE_ADVERTISING);
    
    return ERR_NO_ERROR;
}

msrcuErr_t msrcu_dev_ble_adv_stop(void)
{
    if(inb_actv_stop(actAdvIdx) != INB_ERR_NO_ERROR) 
        return ERR_OTHERS;
    
    msrcu_dev_ble_set_state(BLE_STATE_IDLE);
    
    return ERR_NO_ERROR;
}

msrcuErr_t msrcu_dev_ble_disconnect(void)
{
    if(inb_conn_disconnect(BLE_CON_IDX, BLE_ERROR_CON_TERM_BY_LOCAL_HOST))
        return ERR_OTHERS;
    
    msrcu_dev_ble_set_state(BLE_STATE_IDLE);
    
    inb_evt_disc_ind_t *p_para = malloc(sizeof(p_para));
    if(p_para == NULL)
        return ERR_NO_MEMORY;
    
    p_para->conidx = BLE_CON_IDX;
    p_para->reason = BLE_ERROR_CON_TERM_BY_LOCAL_HOST;
    
    msrcu_dev_ble_gap_evt(GAP_EVT_DISCONNECT, p_para);
    
    if(p_para)
        free(p_para);
    
    return ERR_NO_ERROR;
}

msrcuErr_t msrcu_dev_ble_hid_send(msrcuBleHidReport_t *param)
{
    if(BLE_STATE_READY != msrcu_dev_ble_get_state())
        return ERR_NOT_SUPPORT;
    
    if(!param)
        return ERR_VALID_INPUT;
    
    inb_hogpd_report_info_t *report = malloc(sizeof(inb_hogpd_report_info_t) + param->length);
    if(!report)
        return ERR_NO_MEMORY;
    
    report->hid_idx = param->conIndex;
    report->length = param->length;
    report->idx = param->instance;
    report->type = INB_HOGPD_REPORT;
    memcpy(report->value, param->data, param->length);
    //MSPRINT("%d,%d,%d,%d, ", report->hid_idx, report->length, report->idx, report->type);
    int err = inb_hogpd_report_upd_req(param->conIndex, report);
    
    if(report)
        free(report);
    
    if(!err)
        return ERR_NO_ERROR;
    else
    {
        MSPRINT("hogpd send error: 0x%X\r\n", err);
        return ERR_OTHERS;
    }
}
