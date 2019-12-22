/**
 ****************************************************************************************
 *
 * @file hogp_evt.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#include "ble_evt.h"


#if (CFG_PRF_HOGPBH_EN || CFG_PRF_HOGPD_EN || CFG_PRF_HOGPRH_EN)


#if BLE_EVT_HOGP_TRACE
#define PRINT_HOGP_EVT  PRINT_EVT
#else
#define PRINT_HOGP_EVT(fmt, ...)
#endif


static uint8_t hid_report_map[] = 
{
    //report ID 1 for key
    0x05, 0x01,     // USAGE_PAGE (Generic Desktop)
    0x09, 0x06,     // USAGE (Keyboard)
    0xA1, 0x01,     // COLLECTION (Application)
        0x85, 0x01,     //   REPORT_ID (1)
        //the 1st byte for USAGE_PAGE Keyboard keycode
        0x05, 0x07,     // USAGE_PAGE
        0x09, 0x00,     // 0x0001//null
        0x15, 0x01,     // LOGICAL_MINIMUM
        0x25, 0x01,     // LOGICAL_MAXIMUM
        0x75, 0x08,     // REPORT_SIZE
        0x95, 0x01,     // REPORT_COUNT
        0x81, 0x00,     // INPUT
        //the 2nd byte for USAGE_PAGE Consumer Devices keycode
        0x05, 0x0C,     // USAGE_PAGE
        0x09, 0x30,     // 0x0100//power
        0x09, 0x42,     // 0x0200//up
        0x09, 0x43,     // 0x0300//down
        0x09, 0x44,     // 0x0400//left
        0x09, 0x45,     // 0x0500//right
        0x09, 0x41,     // 0x0600//enter(select)
        0x0A, 0x24, 0x02,     // 0x0700//back
        0x09, 0xE9,     // 0x0800//vol+
        0x09, 0xEA,     // 0x0900//vol-
        0x0A, 0x21, 0x02,     // 0x0A00//search: for ATV voice
        0x0A, 0x23, 0x02,     // 0x0B00//home
        0x09, 0xE2,     // 0x0C00//mute
        0x09, 0x40,     // 0x0D00//menu
        0x15, 0x01,     // LOGICAL_MINIMUM
        0x25, 0x0D,     // LOGICAL_MAXIMUM
        0x75, 0x08,     // REPORT_SIZE
        0x95, 0x01,     // REPORT_COUNT
        0x81, 0x00,     // INPUT
    0xC0,     //     END_COLLECTION
    
    //report ID 2 for voice
    0x05, 0x01, // USAGE_PAGE (Generic Desktop)
    0x09, 0x06, // USAGE (Keyboard)
    0xA1, 0x01, // COLLECTION (Application)
        0x85, 0x02, // REPORT_ID (2)
        //the 1st byte for voice keycode
        0x05, 0x0C,     // USAGE_PAGE
        0x09, 0x00,     //
        0x09, 0x00,     //
        0x09, 0x00,     //
        0x09, 0x00,     //
        0x09, 0x00,     //
        0x09, 0x00,     //
        0x09, 0x00,     //
        0x09, 0x00,     //
        0x09, 0x00,     //
        0x0A, 0x21, 0x02,     // 0x0A//search
        0x15, 0x01,     // LOGICAL_MINIMUM
        0x25, 0x0A,     // LOGICAL_MAXIMUM
        0x75, 0x08,     // REPORT_SIZE
        0x95, 0x01,     // REPORT_COUNT
        0x81, 0x00,     // INPUT
        0x06, 0x00, 0xFF, // USAGE_PAGE (Vendor Defined Page 1)
        0x09, 0x01, // USAGE (Vendor Usage 1)
        0x15, 0x00, // LOGICAL_MINIMUM (0)
        0x26, 0xFF, 0x00, // LOGICAL_MAXIMUM (255)
        0x75, 0x08, // REPORT_SIZE (8)
#if (MSRCU_BLE_VOICE_SAMPLE_RATE == 16000)
        0x95, 0xF3, // REPORT_COUNT (244 - 1)//(VOICE_BLE_PKG_SIZE - 1)
#elif (MSRCU_BLE_VOICE_SAMPLE_RATE == 8000)
        0x95, 0x13, // REPORT_COUNT (20 - 1)//(VOICE_BLE_PKG_SIZE - 1)
#endif
        0x81, 0x00, // INPUT (Data, Ary, Abs)
    0xC0, // END_COLLECTION
    
    //report id 3 for motion(airmouse)
    0x05, 0x01,     //USAGE_PAGE (Generic Desktop)
    0x09, 0x02,     //USAGE (Mouse)
    0xA1, 0x01,     //COLLECTION (Application)
        0x09, 0x01,     //USAGE (Pointer)
        0xA1, 0x00,     //COLLECTION (Physical)
            0x85, 0x03,     //REPORT_ID (3)
            0x05, 0x09,     //USAGE_PAGE (Button)
            0x19, 0x01,     //USAGE_MINIMUM (Button 1)
            0x29, 0x03,     //USAGE_MAXIMUM (Button 3)
            0x15, 0x00,     //LOGICAL_MINIMUM (0)
            0x25, 0x01,     //LOGICAL_MAXIMUM (1)
            0x95, 0x03,     //REPORT_COUNT (3)
            0x75, 0x01,     //REPORT_SIZE (1)
            0x81, 0x02,     //INPUT (Data,Var,Abs)
            0x95, 0x01,     //REPORT_COUNT (1)
            0x75, 0x05,     //REPORT_SIZE (5)
            0x81, 0x03,     //INPUT (Cnst,Var,Abs)
            0x05, 0x01,     //USAGE_PAGE (Generic Desktop)
            0x09, 0x30,     //USAGE (X)
            0x09, 0x31,     //USAGE (Y)
            0x15, 0x81,     //LOGICAL_MINIMUM (-127)
            0x25, 0x7F,     //LOGICAL_MAXIMUM (127)
            0x75, 0x08,     //REPORT_SIZE (8)
            0x95, 0x02,     //REPORT_COUNT (2)
            0x81, 0x06,     //INPUT (Data,Var,Rel)
        0xc0,     //END_COLLECTION
    0xC0,   //END_COLLECTION
};


int handle_default_hogp_evt(uint16_t eid, void *pv)
{
    int res = INB_ERR_NO_ERROR;
    
    switch(eid) 
    {
        case HOGPBH_EVT_BOOT_REPORT_IND:
            {
                PRINT_HOGP_EVT("HOGPBH_EVT_BOOT_REPORT_IND\r\n");
                
                //inb_hogpbh_boot_report_t *p = (inb_hogpbh_boot_report_t *)pv;
            }
            break;
        
        case HOGPRH_EVT_REPORT_IND:
            {
                PRINT_HOGP_EVT("HOGPRH_EVT_REPORT_IND\r\n");
                
                //inb_hogprh_report_t *p = (inb_hogprh_report_t *)pv;
            }
            break;
        
        case HOGPD_EVT_REPORT_REQ_IND:
            {
                PRINT_HOGP_EVT("HOGPD_EVT_REPORT_REQ_IND\r\n");
                
                inb_evt_hogpd_report_req_ind_t *p = (inb_evt_hogpd_report_req_ind_t *)pv;
                inb_hogpd_report_info_t *cfm = NULL;
                int length = 0;
                
                if(p->operation == INB_HOGPD_OP_REPORT_READ)
                {
                    if(p->report.type == INB_HOGPD_REPORT_MAP)
                    {
                        length = sizeof(hid_report_map);
                        cfm = (inb_hogpd_report_info_t *)malloc(sizeof(inb_hogpd_report_info_t) + length);
                        if(!cfm)
                            return INB_PLT_ERR_NO_MEM;
                        
                        memcpy(&cfm->value, hid_report_map, length);
                        cfm->length = length;
                        cfm->hid_idx = p->report.hid_idx;
                        cfm->type = p->report.type;
                        
                        res = INB_ERR_NO_ERROR;
                    }
                    else
                    {
                        length = 8;
                        cfm = (inb_hogpd_report_info_t *)malloc(sizeof(inb_hogpd_report_info_t) + length);
                        if(!cfm)
                            return INB_PLT_ERR_NO_MEM;
                        
                        cfm->hid_idx = p->report.hid_idx;
                        cfm->idx = p->report.idx;
                        cfm->length = length;
                        cfm->type = p->report.type;
                        memset(&cfm->value[0], 0, length);
                        cfm->value[0] = p->report.hid_idx;
                        cfm->value[1] = p->report.type;
                        cfm->value[2] = p->report.length;
                        cfm->value[3] = p->report.idx;
                        
                        res = INB_ERR_NO_ERROR;
                    }
                }
                else
                {
                    length = 8;
                    cfm = (inb_hogpd_report_info_t *)malloc(sizeof(inb_hogpd_report_info_t) + length);
                    if(!cfm)
                        return INB_PLT_ERR_NO_MEM;
                    
                    cfm->hid_idx = p->report.hid_idx;
                    cfm->idx = p->report.idx;
                    cfm->length = length;
                    cfm->type = p->report.type;
                    memset(&cfm->value[0], 0, length);
                    cfm->value[0] = p->report.hid_idx;
                    cfm->value[1] = p->report.type;
                    cfm->value[2] = p->report.length;
                    cfm->value[3] = p->report.idx;
                    
                    res = INB_ERR_NO_ERROR;
                }
                
                inb_hogpd_report_req_cfm(p->conidx, p->operation, res, cfm);
                if(cfm)
                    free(cfm);
            }
            break;
        
        case HOGPD_EVT_PROTO_MODE_UPD_IND:
            {
                PRINT_HOGP_EVT("HOGPD_EVT_PROTO_MODE_UPD_IND\r\n");
                
                inb_evt_hogpd_proto_mode_req_ind_t *p = (inb_evt_hogpd_proto_mode_req_ind_t *)pv;
                
                res = INB_ERR_NO_ERROR;
                
                inb_hogpd_proto_mode_req_cfm(p->conidx, res, p->hid_idx, p->proto_mode);
            }
            break;
        
        case HOGPD_EVT_NTF_CFG_IND:
            {
                PRINT_HOGP_EVT("HOGPD_EVT_NTF_CFG_IND\r\n");
                
                inb_evt_hogpd_ntf_cfg_ind_t *p = (inb_evt_hogpd_ntf_cfg_ind_t *)pv;
                
                if((p->ntf_cfg[p->conidx] & INB_HOGPD_CFG_MASK ) == INB_HOGPD_CFG_KEYBOARD)
                {
                    PRINT_HOGP_EVT("INB_HOGPD_CFG_KEYBOARD\r\n");
                }
                else if((p->ntf_cfg[p->conidx] & INB_HOGPD_CFG_MASK ) == INB_HOGPD_CFG_MOUSE)
                {
                    PRINT_HOGP_EVT("INB_HOGPD_CFG_MOUSE\r\n");
                }
                else if((p->ntf_cfg[p->conidx] & INB_HOGPD_CFG_REPORT_NTF_EN) != 0)
                {
                    PRINT_HOGP_EVT("INB_HOGPD_CFG_REPORT_NTF_EN\r\n");
                }
            }
            break;
        
        case HOGPD_EVT_CNTL_PT_IND:
            {
                PRINT_HOGP_EVT("HOGPD_EVT_CNTL_PT_IND\r\n");
                
                inb_evt_hogpd_ctnl_pt_ind_t *p = (inb_evt_hogpd_ctnl_pt_ind_t *)pv;
                inb_hogpd_report_info_t *cfm = (inb_hogpd_report_info_t *)malloc(sizeof(inb_hogpd_report_info_t));
                if(!cfm)
                    return INB_PLT_ERR_NO_MEM;
                
                memset(cfm, 0, sizeof(inb_hogpd_report_info_t));
                cfm->hid_idx = p->hid_idx;
                cfm->type = INB_HOGPD_REPORT;
                cfm->length = 0;
                cfm->idx = 0;
                
                res = INB_ERR_NO_ERROR;
                inb_hogpd_report_req_cfm(p->conidx, INB_HOGPD_OP_REPORT_WRITE, res, cfm);
                if(cfm)
                    free(cfm);
            }
            break;
        
        default:
            {
                PRINTD(DBG_TRACE, "HOGP event wrong ID: %d.\r\n", eid);
            }
            break;
    }
    
    return res;
}

#endif
