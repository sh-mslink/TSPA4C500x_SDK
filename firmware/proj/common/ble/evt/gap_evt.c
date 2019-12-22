/**
 ****************************************************************************************
 *
 * @file gap_evt.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#include "ble_evt.h"


#if BLE_EVT_GAP_TRACE
#define PRINT_GAP_EVT   PRINT_EVT
#else
#define PRINT_GAP_EVT(fmt, ...)
#endif


static char gDevName[249] = {CFG_BLE_DEV_LOCAL_NAME};
static uint16_t gDevAppearance = CFG_BLE_DEV_LOCAL_APPEARANCE;

inb_ltk_t gBondData = {0};


int handle_default_gap_evt(uint16_t eid, void *pv)
{
    int res = INB_ERR_NO_ERROR;
    
    switch(eid)
    {
        case GAP_EVT_PEER_NAME_IND:
            {
                PRINT_GAP_EVT("GAP_EVT_PEER_NAME_IND\r\n");
                
                //inb_evt_peer_name_ind_t *p = (inb_evt_peer_name_ind_t*)pv;
            }
            break;
        
        case GAP_EVT_SYNC_ESTABLISHED:
            {
                PRINT_GAP_EVT("GAP_EVT_SYNC_ESTABLISHED\r\n");
                
                //inb_evt_sync_established_ind_t *p = (inb_evt_sync_established_ind_t*)pv;
            }
            break;
        
        case GAP_EVT_RX_SCAN_REQ:
            {
                PRINT_GAP_EVT("GAP_EVT_RX_SCAN_REQ\r\n");
                
                //inb_evt_rx_scan_req_t *p = (inb_evt_rx_scan_req_t*)pv;
            }
            break;
        
        case GAP_EVT_ADV_REPORT:
            {
                PRINT_GAP_EVT("GAP_EVT_ADV_REPORT\r\n");
                
                //inb_evt_adv_rpt_ind_t *p = (inb_evt_adv_rpt_ind_t*)pv;
            }
            break;
        
        case GAP_EVT_ACTIVITY_STOP:
            {
                PRINT_GAP_EVT("GAP_EVT_ACTIVITY_STOP\r\n");
                
                inb_evt_act_stop_ind_t *p = (inb_evt_act_stop_ind_t *)pv;
                
                inb_actv_del(p->actv_idx);
            }
            break;
        
        case GAP_EVT_DEV_RND_ADDR_INFO:
            {
                PRINT_GAP_EVT("GAP_EVT_DEV_RND_ADDR_INFO\r\n");
                
                //inb_evt_write_req_ind_t *p = (inb_evt_write_req_ind_t*)pv;
            }
            break;
        
        case GAP_EVT_KEYPRESS_IND:
            {
                PRINT_GAP_EVT("GAP_EVT_KEYPRESS_IND\r\n");
                
                //inb_evt_rnd_addr_ind_t *p = (inb_evt_rnd_addr_ind_t*)pv;
            }
            break;
        
        case GAP_EVT_GET_DEV_INFO_REQ:
            {
                PRINT_GAP_EVT("GAP_EVT_GET_DEV_INFO_REQ\r\n");
                
                inb_evt_get_dev_info_req_t *p = (inb_evt_get_dev_info_req_t *)pv;
                inb_get_dev_info_cfm_t cfm = {0};
                
                cfm.req = p->req;
                switch(cfm.req)
                {
                    case DEV_NAME:
                        {
                            cfm.u.name.length = strlen(gDevName);
                            memcpy(cfm.u.name.value, gDevName, strlen(gDevName));
                        }
                        break;
                    case DEV_APPEARANCE:
                        {
                            cfm.u.appearance = gDevAppearance;
                        }
                        break;
                    case DEV_SLV_PREF_PARAMS:
                        {
                            cfm.u.slv_pref_params.con_intv_min = CFG_BLE_DEV_SLV_PREF_CONN_MIN_INTV;
                            cfm.u.slv_pref_params.con_intv_max = CFG_BLE_DEV_SLV_PREF_CONN_MAX_INTV;
                            cfm.u.slv_pref_params.slave_latency  = CFG_BLE_DEV_SLV_PREF_LATENCY;
                            cfm.u.slv_pref_params.conn_timeout = CFG_BLE_DEV_SLV_PREF_SUP_TO;
                        }
                        break;
                    case DEV_CTL_ADDR_RESOL:
                        break;
                    default:
                        break;
                }
                inb_conn_get_dev_info_cfm(p->conidx, &cfm);
            }
            break;
        
        case GAP_EVT_SET_DEV_INFO_REQ:
            {
                PRINT_GAP_EVT("GAP_EVT_SET_DEV_INFO_REQ\r\n");
                
                inb_evt_set_dev_info_req_t *p = (inb_evt_set_dev_info_req_t *)pv;
                inb_set_dev_info_cfm_t cfm = {0};
                
                cfm.req = p->req;
                switch(cfm.req)
                {
                    case DEV_NAME:
                        {
                            memcpy(gDevName, p->info.name.value, p->info.name.length);
                            gDevName[p->info.name.length] = 0;
                        }
                        break;
                    case DEV_APPEARANCE:
                        {
                            gDevAppearance = p->info.appearance;
                        }
                        break;
                    case DEV_SLV_PREF_PARAMS:
                        break;
                    case DEV_CTL_ADDR_RESOL:
                        break;
                    default:
                        break;
                }
                cfm.status = 0;
                inb_conn_set_dev_info_cfm(p->conidx, &cfm);
            }
            break;
        
        case GAP_EVT_DISCONNECT:
            {
                PRINT_GAP_EVT("GAP_EVT_DISCONNECT\r\n");
                
                //inb_evt_disc_ind_t *p = (inb_evt_disc_ind_t*)pv;
            }
            break;
        
        case GAP_EVT_CONN_REQ:
            {
                PRINT_GAP_EVT("GAP_EVT_CONN_REQ\r\n");
                
                inb_evt_conn_req_t *p = (inb_evt_conn_req_t *)pv;
                inb_conn_cfm_t cfm = {0};
                
                inb_conn_cfm(p->conidx, &cfm);
            }
            break;
        
        case GAP_EVT_PING_TO_IND:
            {
                PRINT_GAP_EVT("GAP_EVT_PING_TO_IND\r\n");
                
                //inb_evt_ping_to_ind_t *p = (inb_evt_ping_to_ind_t*)pv;
            }
            break;
            
        case GAP_EVT_SIGNED_COUNTER_UPD:
            {
                PRINT_GAP_EVT("GAP_EVT_SIGNED_COUNTER_UPD\r\n");
                
                //inb_evt_sign_counter_ind_t *p = (inb_evt_sign_counter_ind_t*)pv;
            }
            break;
            
        case GAP_EVT_SECURITY_IND:
            {
                PRINT_GAP_EVT("GAP_EVT_SECURITY_IND\r\n");
                
                //inb_evt_security_ind_t *p = (inb_evt_security_ind_t*)pv;
            }
            break;
            
        case GAP_EVT_ENCRYPT_REQ:
            {
                PRINT_GAP_EVT("GAP_EVT_ENCRYPT_REQ\r\n");
                
                inb_evt_encrypt_req_ind_t *p = (inb_evt_encrypt_req_ind_t *)pv;
                inb_conn_encrypt_cfm_t cfm = {0};
                
                if(p->ediv == gBondData.ediv && !memcmp(p->rand_nb.nb, gBondData.randnb.nb, BLE_RAND_NB_LEN))
                {
                    cfm.found = 1;
                    cfm.key_size = gBondData.key_size;
                    memcpy(cfm.ltk.key, gBondData.ltk.key, BLE_KEY_LEN);
                }
                
                inb_conn_req_encrypt_cfm(p->conidx, &cfm);
            }
            break;
        
        case GAP_EVT_ENCRYPT_IND:
            {
                PRINT_GAP_EVT("GAP_EVT_ENCRYPT_IND\r\n");
                
                inb_evt_encrypt_ind_t *p = (inb_evt_encrypt_ind_t*)pv;
                
#if CFG_PRF_BASS_EN
                /// Enable Battery Service...
                inb_bass_enable_req_t req = {0};
                
                req.ntf_cfg = CLI_STOP_NTFIND;
                req.old_batt_lvl[0] = 0;
                if(inb_bass_enable(p->conidx, &req) != INB_ERR_NO_ERROR)
                    ;//PRINTD(DBG_TRACE, "inb_bass_enable fail.\r\n");
                else
                    ;//PRINTD(DBG_TRACE, "inb_bass_enable success.\r\n");
#endif
                
#if CFG_PRF_DISS_EN
                /// Enable Device Information Service...
#endif
                
#if CFG_PRF_HOGPD_EN
                /// Enable HOGPD Service...
                uint16_t ntf_cfg[3] = {0};
                ntf_cfg[0] = INB_HOGPD_CFG_REPORT_NTF_EN
                        | (INB_HOGPD_CFG_REPORT_NTF_EN << 1)
                        | (INB_HOGPD_CFG_REPORT_NTF_EN << 2);
                if(inb_hogpd_enable(p->conidx, ntf_cfg) != INB_ERR_NO_ERROR)
                    ;//PRINTD(DBG_TRACE, "inb_hogpd_enable fail.\r\n");
                else
                    ;//PRINTD(DBG_TRACE, "inb_hogpd_enable success.\r\n");
#endif
            }
            break;
        
        case GAP_EVT_BOND_REQ:
            {
                PRINT_GAP_EVT("GAP_EVT_BOND_REQ\r\n");
                
                inb_evt_bond_req_ind_t *p = (inb_evt_bond_req_ind_t *)pv;
                inb_bond_cfm_t cfm = {0};
                
                switch(p->request)
                {
                    case PAIRING_REQ:
                        {
                            PRINT_GAP_EVT("PAIRING_REQ\r\n");
                            
                            cfm.request = PAIRING_RSP;
                            if(CFG_BLE_DEV_PAIR_MODE)
                            {
                                cfm.accept = 1;
                                cfm.u.pairing_feat.iocap = IO_CAP_NO_INPUT_NO_OUTPUT; 
                                cfm.u.pairing_feat.oob = OOB_AUTH_DATA_NOT_PRESENT;
                                cfm.u.pairing_feat.auth = AUTH_REQ_NO_MITM_BOND; 
                                cfm.u.pairing_feat.key_size = BLE_KEY_LEN;
                                cfm.u.pairing_feat.ikey_dist = KDIST_ENCKEY | KDIST_IDKEY | KDIST_SIGNKEY;
                                cfm.u.pairing_feat.rkey_dist = KDIST_ENCKEY | KDIST_IDKEY | KDIST_SIGNKEY;
                                cfm.u.pairing_feat.sec_req = NO_SEC;
                            }
                            else
                                cfm.accept = 0;
                        }
                        break;
                    
                    case PAIRING_RSP:
                        {
                            PRINT_GAP_EVT("PAIRING_RSP\r\n");
                        }
                        break;
                    
                    case PAIRING_SUCCEED:
                        {
                            PRINT_GAP_EVT("PAIRING_SUCCEED\r\n");
                        }
                        break;
                    
                    case PAIRING_FAILED:
                        {
                            PRINT_GAP_EVT("PAIRING_FAILED\r\n");
                        }
                        break;
                    
                    case TK_EXCH:
                        {
                            PRINT_GAP_EVT("TK_EXCH\r\n");
                            
                            cfm.request = TK_EXCH;
                            cfm.accept = 1;
                            
                            uint32_t pin_code = (100000 + (rand()%900000));
                            cfm.u.tk.key[0] = (uint8_t)((pin_code & 0x000000FF) >>  0);
                            cfm.u.tk.key[1] = (uint8_t)((pin_code & 0x0000FF00) >>  8);
                            cfm.u.tk.key[2] = (uint8_t)((pin_code & 0x00FF0000) >> 16);
                            cfm.u.tk.key[3] = (uint8_t)((pin_code & 0xFF000000) >> 24);
                        }
                        break;
                    
                    case IRK_EXCH:
                        {
                            PRINT_GAP_EVT("IRK_EXCH\r\n");
                        }
                        break;
                    
                    case CSRK_EXCH:
                        {
                            PRINT_GAP_EVT("CSRK_EXCH\r\n");
                            
                            cfm.request = CSRK_EXCH;
                            cfm.accept = 1;
                            for(uint32_t i = 0; i < BLE_KEY_LEN; i += 4)
                            {
                                uint32_t rnb = rand();
                                cfm.u.csrk.key[i+0] = (uint8_t)rnb;
                                cfm.u.csrk.key[i+1] = (uint8_t)(rnb>>8);
                                cfm.u.csrk.key[i+2] = (uint8_t)(rnb>>16);
                                cfm.u.csrk.key[i+3] = (uint8_t)(rnb>>24);
                            }
                        }
                        break;
                    
                    case LTK_EXCH:
                        {
                            PRINT_GAP_EVT("LTK_EXCH\r\n");
                            
                            cfm.request = LTK_EXCH;
                            cfm.accept = 1;
                            
                            for(uint32_t i = 0; i < BLE_RAND_NB_LEN; i += 4)
                            {
                                uint32_t rnb = rand();
                                cfm.u.ltk.randnb.nb[i+0] = (uint8_t)rnb;
                                cfm.u.ltk.randnb.nb[i+1] = (uint8_t)(rnb>>8);
                                cfm.u.ltk.randnb.nb[i+2] = (uint8_t)(rnb>>16);
                                cfm.u.ltk.randnb.nb[i+3] = (uint8_t)(rnb>>24);
                            }
                            for(uint32_t i = 0; i < BLE_KEY_LEN; i += 4)
                            {
                                uint32_t rnb = rand();
                                cfm.u.ltk.ltk.key[i+0] = (uint8_t)rnb;
                                cfm.u.ltk.ltk.key[i+1] = (uint8_t)(rnb>>8);
                                cfm.u.ltk.ltk.key[i+2] = (uint8_t)(rnb>>16);
                                cfm.u.ltk.ltk.key[i+3] = (uint8_t)(rnb>>24);
                            }
                            cfm.u.ltk.key_size = BLE_KEY_LEN;
                            cfm.u.ltk.ediv = (uint16_t)rand();
                            
                            memcpy(&gBondData, &(cfm.u.ltk), sizeof(inb_ltk_t));
#ifdef CFG_PROJ_RCU    
                            extern msrcuBleBondData_t msrcuBondData;
                            memcpy(msrcuBondData.ltk.key, cfm.u.ltk.ltk.key, BLE_KEY_LEN);
                            msrcuBondData.ediv = cfm.u.ltk.ediv; 
                            memcpy(msrcuBondData.randNb.nb, cfm.u.ltk.randnb.nb, BLE_RANDOM_NB_LEN); 
                            msrcuBondData.keySize = cfm.u.ltk.key_size;
#endif 
                        }
                        break;
                    
                    case REPEATED_ATTEMPT:
                        {
                            PRINT_GAP_EVT("REPEATED_ATTEMPT\r\n");
                        }
                        break;
                    
                    case OOB_EXCH:
                        {
                            PRINT_GAP_EVT("OOB_EXCH\r\n");
                        }
                        break;
                    
                    case NC_EXCH:
                        {
                            PRINT_GAP_EVT("NC_EXCH\r\n");
                        }
                        break;
                    
                    default:
                        break;
                }
                inb_conn_bond_cfm(p->conidx, &cfm);
            }
            break;
        
        case GAP_EVT_BOND_IND:
            {
                PRINT_GAP_EVT("GAP_EVT_BOND_IND\r\n");
                
                inb_evt_bond_ind_t *p = (inb_evt_bond_ind_t *)pv;
                
                switch(p->info)
                {
                    case PAIRING_REQ:
                        {
                            PRINT_GAP_EVT("PAIRING_REQ\r\n");
                        }
                        break;
                    
                    case PAIRING_RSP:
                        {
                            PRINT_GAP_EVT("PAIRING_RSP\r\n");
                        }
                        break;
                    
                    case PAIRING_SUCCEED:
                        {
                            PRINT_GAP_EVT("PAIRING_SUCCEED\r\n");
                        }
                        break;
                    
                    case PAIRING_FAILED:
                        {
                            PRINT_GAP_EVT("PAIRING_FAILED\r\n");
                        }
                        break;
                    
                    case TK_EXCH:
                        {
                            PRINT_GAP_EVT("TK_EXCH\r\n");
                        }
                        break;
                    
                    case IRK_EXCH:
                        {
                            PRINT_GAP_EVT("IRK_EXCH\r\n");
                        }
                        break;
                    
                    case CSRK_EXCH:
                        {
                            PRINT_GAP_EVT("CSRK_EXCH\r\n");
                        }
                        break;
                    
                    case LTK_EXCH:
                        {
                            PRINT_GAP_EVT("LTK_EXCH\r\n");
                        }
                        break;
                    
                    case REPEATED_ATTEMPT:
                        {
                            PRINT_GAP_EVT("REPEATED_ATTEMPT\r\n");
                        }
                        break;
                    
                    case OOB_EXCH:
                        {
                            PRINT_GAP_EVT("OOB_EXCH\r\n");
                        }
                        break;
                    
                    case NC_EXCH:
                        {
                            PRINT_GAP_EVT("NC_EXCH\r\n");
                        }
                        break;
                    
                    default:
                        break;
                }
            }
            break;
        
        case GAP_EVT_CONN_PARAM_UPD_REQ:
            {
                PRINT_GAP_EVT("GAP_EVT_CONN_PARAM_UPD_REQ\r\n");
                
                inb_evt_conn_param_upd_req_t *p = (inb_evt_conn_param_upd_req_t *)pv;
                
                inb_conn_param_update_cfm(p->conidx, true, 0x0, 0xFFFF);
            }
            break;
        
        case GAP_EVT_CONN_PARAM_UPD:
            {
                PRINT_GAP_EVT("GAP_EVT_CONN_PARAM_UPD\r\n");
                
                //inb_evt_conn_param_upd_t *p = (inb_evt_conn_param_upd_t*)pv;
            }
            break;
        
        case GAP_EVT_CONN_PHY_UPD:
            {
                PRINT_GAP_EVT("GAP_EVT_CONN_PHY_UPD\r\n");
                
                //inb_evt_phy_upd_t *p = (inb_evt_phy_upd_t*)pv;
            }
            break;
        
        case GAP_EVT_LE_PKT_SIZE_IND:
            {
                PRINT_GAP_EVT("GAP_EVT_LE_PKT_SIZE_IND\r\n");
                
                //inb_evt_le_pkt_size_t *p = (inb_evt_le_pkt_size_t*)pv;
            }
            break;
        
        default:
            {
                PRINTD(DBG_TRACE, "GAP event wrong ID: %d.\r\n", eid);
            }
            break;
    }
    
    return res;
}
