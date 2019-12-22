/**
 ****************************************************************************************
 *
 * @file gatt_evt.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#include "ble_evt.h"


#if BLE_EVT_GATT_TRACE
#define PRINT_GATT_EVT  PRINT_EVT
#else
#define PRINT_GATT_EVT(fmt, ...)
#endif


int handle_default_gatt_evt(uint16_t eid, void* pv)
{
    int res = INB_ERR_NO_ERROR;
    
    switch(eid)
    {
        case GATT_EVT_MTU_XCHG_IND:
            {
                PRINT_GATT_EVT("GATT_EVT_MTU_XCHG_IND\r\n");
                
                //inb_evt_mtu_xchg_ind_t *p = (inb_evt_mtu_xchg_ind_t *)pv;
            }
            break;
        
        case GATT_EVT_DISC_SVC:
            {
                PRINT_GATT_EVT("GATT_EVT_DISC_SVC\r\n");
                
                //inb_evt_disc_svc_ind_t *p = (inb_evt_disc_svc_ind_t *)pv;
            }
            break;
        
        case GATT_EVT_DISC_INCL_SVC:
            {
                PRINT_GATT_EVT("GATT_EVT_DISC_INCL_SVC\r\n");
                
                //inb_evt_disc_svc_incl_ind_t *p = (inb_evt_disc_svc_incl_ind_t *)pv;
            }
            break;
        
        case GATT_EVT_DISC_CHAR:
            {
                PRINT_GATT_EVT("GATT_EVT_DISC_CHAR\r\n");
                
                //inb_evt_disc_char_ind_t *p = (inb_evt_disc_char_ind_t *)pv;
            }
            break;
        
        case GATT_EVT_DISC_CHAR_DESC:
            {
                PRINT_GATT_EVT("GATT_EVT_DISC_CHAR_DESC\r\n");
                
                //inb_evt_disc_char_desc_ind_t *p = (inb_evt_disc_char_desc_ind_t *)pv;
            }
            break;
        
        case GATT_EVT_NTF:
            {
                PRINT_GATT_EVT("GATT_EVT_NTF\r\n");
                
                //inb_evt_ntf_ind_t *p = (inb_evt_ntf_ind_t *)pv;
            }
            break;
        
        case GATT_EVT_IND:
            {
                PRINT_GATT_EVT("GATT_EVT_IND\r\n");
                
                inb_evt_ind_ind_t *p = (inb_evt_ind_ind_t *)pv;
                
                inb_gatt_indication_cfm(p->conidx, p->handle);
            }
            break;
        
        case GATT_EVT_CCC_CHG_IND:
            {
                PRINT_GATT_EVT("GATT_EVT_CCC_CHG_IND\r\n");
                
                //inb_evt_ccc_changed_ind_t *p = (inb_evt_ccc_changed_ind_t *)pv;
            }
            break;
        
        case GATT_EVT_RD_REQ:
            {
                PRINT_GATT_EVT("GATT_EVT_RD_REQ\r\n");
                
                inb_evt_read_req_ind_t* p = (inb_evt_read_req_ind_t *)pv;
                uint8_t status = INB_ATT_ERR_REQUEST_NOT_SUPPORTED;
                uint8_t *data = NULL;
                uint16_t data_len = 0;
                
#if CFG_FW_UPD_EN
                status = in_ota_svc_read_hdl(p->handle, &data_len, &data);
#endif
                inb_gatt_read_req_cfm(p->conidx, p->handle, status, data_len, data);
            }
            break;
        
        case GATT_EVT_WRT_REQ:
            {
                PRINT_GATT_EVT("GATT_EVT_WRT_REQ\r\n");
                
                inb_evt_write_req_ind_t *p = (inb_evt_write_req_ind_t*)pv;
                
#if CFG_FW_UPD_EN
                in_ota_svc_write_hdl(p);
#endif
                
                inb_gatt_write_req_cfm(p->conidx, p->handle, INB_ATT_ERR_NO_ERROR);
            }
            break;
        
        case GATT_EVT_ATT_INFO_REQ:
            {
                PRINT_GATT_EVT("GATT_EVT_ATT_INFO_REQ\r\n");
                
                inb_evt_att_info_req_ind_t *p = (inb_evt_att_info_req_ind_t*)pv;
                uint16_t length = 0;
                
#if CFG_FW_UPD_EN
                in_ota_svc_info_req_hdl(p->handle, &length);
#endif
                inb_gatt_att_info_req_cfm(p->conidx, p->handle, length, INB_ATT_ERR_NO_ERROR);
            }
            break;
            
        case GATT_EVT_SDP_SVC:
            {
                PRINT_GATT_EVT("GATT_EVT_SDP_SVC\r\n");
                
                //inb_evt_sdp_svc_ind_t *p = (inb_evt_sdp_svc_ind_t *)pv;
            }
            break;
        
        case GATT_EVT_RD_RSP_IND:
            {
                PRINT_GATT_EVT("GATT_EVT_RD_RSP_IND\r\n");
                
                //inb_evt_read_rsp_ind_t *p = (inb_evt_read_rsp_ind_t *)pv;
            }
            break;
        
        default:
            {
                PRINTD(DBG_TRACE, "GATT event wrong ID: %d.\r\n", eid);
            }
            break;
    }
    
    return res;
}
