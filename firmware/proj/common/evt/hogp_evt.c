#include "in_config.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "in_arm.h"
#include "in_debug.h"
#include ".\hal\hal_uart.h"
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_power.h"
#include ".\hal\hal_adc.h"
#include ".\ble\inb_api.h"
#include ".\ble\prf\inb_prf_hogp.h"

#include "cmsis_os.h"

#include "msrcu_app.h"

static uint8_t hid_report_map[] = 
{
    //report ID 1 for key
    0x05, 0x01,     // USAGE_PAGE (Generic Desktop)
    0x09, 0x06,     // USAGE (Keyboard)
    0xa1, 0x01,     // COLLECTION (Application)
        0x85, 0x01,     //   REPORT_ID (1)
        //the 1st byte for USAGE_PAGE Keyboard keycode
        0x05, 0x07,     // USAGE_PAGE
        0x09, 0x66,     // 0x0001//power
        0x09, 0x52,     // 0x0002//up
        0x09, 0x51,     // 0x0003//down
        0x09, 0x50,     // 0x0004//left
        0x09, 0x4f,     // 0x0005//right
        0x09, 0x58,     // 0x0006//ok
        0x09, 0xf1,     // 0x0007//back
        0x09, 0x80,     // 0x0008//vol+
        0x09, 0x81,     // 0x0009//vol-
        0x15, 0x01,     // LOGICAL_MINIMUM
        0x25, 0x09,     // LOGICAL_MAXIMUM
        0x75, 0x08,     // REPORT_SIZE
        0x95, 0x01,     // REPORT_COUNT
        0x81, 0x00,     // INPUT
        //the 2nd byte for USAGE_PAGE Consumer Devices keycode
        0x05, 0x0c,     // USAGE_PAGE
        0x0A, 0x21, 0x02,     // 0x0100//search: for ATV voice
        0x0A, 0x23, 0x02,     // 0x0200//home
        0x09, 0xe2,     // 0x0300//mute
        0x09, 0x40,     // 0x0400//menu
        0x15, 0x01,     // LOGICAL_MINIMUM
        0x25, 0x04,     // LOGICAL_MAXIMUM
        0x75, 0x08,     // REPORT_SIZE
        0x95, 0x01,     // REPORT_COUNT
        0x81, 0x00,     // INPUT
    0xc0,     //     END_COLLECTION
    
    //report ID 2 for voice
    0x05, 0x01, // USAGE_PAGE (Generic Desktop)
    0x09, 0x06, // USAGE (Keyboard)
    0xa1, 0x01, // COLLECTION (Application)
        0x85, 0x02, // REPORT_ID (2)
        //the 1st byte for voice keycode
        0x05, 0x0c,     // USAGE_PAGE
        0x09, 0x00,     //
        0x09, 0x00,     //
        0x09, 0x00,     //
        0x09, 0x00,     //
        0x09, 0x00,     //
        0x09, 0x00,     //
        0x09, 0x00,     //
        0x09, 0x00,     //
        0x09, 0x00,     //
        0x0A, 0x21, 0x02,     // 0x0a//search
        0x15, 0x01,     // LOGICAL_MINIMUM
        0x25, 0x0a,     // LOGICAL_MAXIMUM
        0x75, 0x08,     // REPORT_SIZE
        0x95, 0x01,     // REPORT_COUNT
        0x81, 0x00,     // INPUT
        0x06, 0x00, 0xff, // USAGE_PAGE (Vendor Defined Page 1)
        0x09, 0x01, // USAGE (Vendor Usage 1)
        0x15, 0x00, // LOGICAL_MINIMUM (0)
        0x26, 0xff, 0x00, // LOGICAL_MAXIMUM (255)
        0x75, 0x08, // REPORT_SIZE (8)
        0x95, 0xf3, // REPORT_COUNT (244 - 1)//(VOICE_BLE_PKG_SIZE - 1)
//        0x95, 0x13, // REPORT_COUNT (20 - 1)//(VOICE_BLE_PKG_SIZE - 1)
        0x81, 0x00, // INPUT (Data, Ary, Abs)
    0xc0, // END_COLLECTION
    
    //report id 3 for motion(airmouse)
    0x05, 0x01,     //USAGE_PAGE (Generic Desktop)
    0x09, 0x02,     //USAGE (Mouse)
    0xa1, 0x01,     //COLLECTION (Application)
        0x09, 0x01,     //USAGE (Pointer)
        0xa1, 0x00,     //COLLECTION (Physical)
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
            0x25, 0x7f,     //LOGICAL_MAXIMUM (127)
            0x75, 0x08,     //REPORT_SIZE (8)
            0x95, 0x02,     //REPORT_COUNT (2)
            0x81, 0x06,     //INPUT (Data,Var,Rel)
        0xc0,     //END_COLLECTION
    0xc0,   //END_COLLECTION
};


int handle_default_hogp_evt(uint16_t eid, void *pv)
{
    int ret = -1;
    int status = INB_ERR_NO_ERROR;
    
#if (CFG_PRF_HOGPBH_EN) || (CFG_PRF_HOGPD_EN) || (CFG_PRF_HOGPRH_EN)
    if((eid & 0xFF00) == HOGP_EVT_CODE)
    {
        ret = 0;
        //PRINTD(DBG_TRACE, "\n%s  id 0x%x\r\n", __func__, eid);
    }
    
    switch(eid) 
    {
        case HOGPD_EVT_REPORT_REQ_IND:
        {
            inb_hogpd_report_info_t *cfm= NULL;
            int length = 0;
            inb_evt_hogpd_report_req_ind_t *p_para = (inb_evt_hogpd_report_req_ind_t *)pv;
            
            //PRINTD(DBG_TRACE, "HOGPD_EVT_REPORT_REQ_IND\r\n");
            
            if(p_para->operation == INB_HOGPD_OP_REPORT_READ)
            {
                if(p_para->report.type == INB_HOGPD_REPORT_MAP)
                {
                    length = sizeof(hid_report_map);
                    cfm = (inb_hogpd_report_info_t *)malloc(sizeof(inb_hogpd_report_info_t) + length);
                    if(!cfm)
                    {
                        PRINTD(DBG_TRACE, "no mem \n");
                        break;
                    }
                    memcpy(&cfm->value, hid_report_map, length);
                    status = INB_ERR_NO_ERROR;
                    cfm->length = length;
                    cfm->hid_idx = p_para->report.hid_idx;;
                    cfm->type = p_para->report.type;
                }
                else
                {
                    uint16_t len = 8;
                    cfm = (inb_hogpd_report_info_t *)malloc(sizeof(inb_hogpd_report_info_t) + len);
                    if(!cfm)
                    {
                        PRINTD(DBG_TRACE, "no mem \n");
                        break;
                    }
                    cfm->hid_idx = p_para->report.hid_idx;
                    cfm->idx = p_para->report.idx;
                    cfm->length = len;
                    cfm->type = p_para->report.type;
                    memset(&cfm->value[0], 0, len); 
                    cfm->value[0] = p_para->report.hid_idx;
                    cfm->value[1] = p_para->report.type;
                    cfm->value[2] = p_para->report.length;
                    cfm->value[3] = p_para->report.idx;
                    
                    status = INB_ERR_NO_ERROR;
                }
            }
            else
            {
                uint16_t len = 8;
                cfm = (inb_hogpd_report_info_t *)malloc(sizeof(inb_hogpd_report_info_t) + len);
                if(!cfm)
                {
                    PRINTD(DBG_TRACE, "no mem \n");
                    break;
                }
                cfm->hid_idx = p_para->report.hid_idx;
                cfm->idx = p_para->report.idx;
                cfm->length = len;
                cfm->type = p_para->report.type;
                memset(&cfm->value[0], 0, len); 
                cfm->value[0] = p_para->report.hid_idx;
                cfm->value[1] = p_para->report.type;
                cfm->value[2] = p_para->report.length;
                cfm->value[3] = p_para->report.idx;
                
                status = INB_ERR_NO_ERROR;
            }
            
            inb_hogpd_report_req_cfm(p_para->conidx, p_para->operation, status, cfm);
            
            if(cfm)
                free(cfm);
        }
        break;
        
        case HOGPD_EVT_PROTO_MODE_UPD_IND:
        {
            inb_evt_hogpd_proto_mode_req_ind_t *p_para = (inb_evt_hogpd_proto_mode_req_ind_t *)pv;
            status = INB_ERR_NO_ERROR;
            
            //PRINTD(DBG_TRACE, "HOGPD_EVT_PROTO_MODE_UPD_IND\r\n");
            
            inb_hogpd_proto_mode_req_cfm(p_para->conidx, status, p_para->hid_idx, p_para->proto_mode);
        }
        break;
        
        case HOGPD_EVT_NTF_CFG_IND:
        {
            inb_evt_hogpd_ntf_cfg_ind_t *param = (inb_evt_hogpd_ntf_cfg_ind_t *)pv;
            
            //PRINTD(DBG_TRACE, "HOGPD_EVT_NTF_CFG_IND, cfg 0x%X\r\n", param->ntf_cfg[param->conidx]);
            
            if((param->ntf_cfg[param->conidx] & INB_HOGPD_CFG_MASK ) == INB_HOGPD_CFG_KEYBOARD)
            {
                //PRINTD(DBG_TRACE, "INB_HOGPD_CFG_KEYBOARD\r\n");
                /*
                byte 0 modifier keys
                byte 1 reserved
                byte 2 ~ 7  keycode 1~6
                */
//                inb_hogpd_report_info_t *report = malloc(sizeof(inb_hogpd_report_info_t) + 3);
//                if(!report)
//                {
//                    PRINTD(DBG_TRACE, " no mem line%d\n",__LINE__);
//                    break;
//                }
//                memset(report, 0, sizeof(inb_hogpd_report_info_t) + 5);
//                report->hid_idx = param->conidx;
//                report->length = 3;
//                report->idx = 2;
//                report->type = INB_HOGPD_BOOT_KEYBOARD_INPUT_REPORT;
//				report->type = INB_HOGPD_REPORT;
//                report->value[2] = 0x0A;
//                inb_hogpd_report_upd_req(param->conidx, report);
//                free(report);
            }
            else if((param->ntf_cfg[param->conidx] & INB_HOGPD_CFG_MASK ) == INB_HOGPD_CFG_MOUSE)
            {
                //PRINTD(DBG_TRACE, "INB_HOGPD_CFG_MOUSE\r\n");
                /*
                byte 0 :
                    bit 0: button 1
                    bit 1: button 2
                    bit 2: button 3
                    bit 4~7 device spec
                byte 1 x displacement
                byte 2 y displacement
                3 to 8 optional device spec
                */
//                inb_hogpd_report_info_t *report = malloc(sizeof(inb_hogpd_report_info_t) + 8);
//                if(!report)
//                {
//                    PRINTD(DBG_TRACE, " no mem line%d\n",__LINE__);
//                    break;
//                }
//                memset(report, 0, sizeof(inb_hogpd_report_info_t) + 8);
//                report->hid_idx = param->conidx;
//                report->length = 8;
//                report->idx = 0;
//                report->type = INB_HOGPD_BOOT_MOUSE_INPUT_REPORT;
//                report->value[1] = 20;
//                inb_hogpd_report_upd_req(param->conidx, report);
//                free(report);
            }
            else if((param->ntf_cfg[param->conidx] & INB_HOGPD_CFG_REPORT_NTF_EN ) != 0)
            {
                //PRINTD(DBG_TRACE, "INB_HOGPD_CFG_REPORT_NTF_EN\r\n");
                
                //set report_char_cfg to INB_HOGPD_CFG_REPORT_IN|INB_HOGPD_CFG_REPORT_WR
//                inb_hogpd_report_info_t *report = malloc(sizeof(inb_hogpd_report_info_t) + 2);
//                if(!report)
//                {
//                    PRINTD(DBG_TRACE, " no mem line%d\n",__LINE__);
//                    break;
//                }
//                
//                memset(report, 0, sizeof(inb_hogpd_report_info_t) + 2);
//                report->hid_idx = param->conidx;
//                report->length = 2;
//                report->idx = 0;
//                report->type = INB_HOGPD_REPORT;
//                memset(report->value, 0, report->length);
//                report->value[0] = 0x0A;
//                inb_hogpd_report_upd_req(param->conidx, report);
//                free(report);	
            }
        }
        break;
        
        case HOGPD_EVT_CNTL_PT_IND:
        {
            inb_hogpd_report_info_t *cfm= NULL;
            inb_evt_hogpd_ctnl_pt_ind_t *p_para = (inb_evt_hogpd_ctnl_pt_ind_t *)pv;
            
            //PRINTD(DBG_TRACE, "HOGPD_EVT_CNTL_PT_IND, pt 0x%X\r\n", p_para->hid_ctnl_pt);
            
            cfm = (inb_hogpd_report_info_t *)malloc(sizeof(inb_hogpd_report_info_t));
            if(!cfm)
            {
                PRINTD(DBG_TRACE, "no mem \n");
                break;
            }
            memset(cfm, 0, sizeof(inb_hogpd_report_info_t));
            cfm->hid_idx = p_para->hid_idx;
            //cfm->idx = 0;
            
            //cfm->conidx = p_para->conidx;//app_hid_env.conidx;
            /// Operation requested (read/write @see enum hogpd_op)
            //cfm->operation = INB_HOGPD_OP_REPORT_WRITE;
            /// Status of the request
            //cfm->status = GAP_ERR_NO_ERROR;
            /// Report Info
            //req->report;
            /// HIDS Instance
            cfm->hid_idx = p_para->conidx;
            /// type of report (@see enum hogpd_report_type)
            cfm->type = 0xFF;//-1; outside 
            /// Report Length (uint8_t)
            cfm->length = 0;
            /// Report Instance - 0 for boot reports and report map
            cfm->idx = 0;
            /// Report data
            status = INB_ERR_NO_ERROR;
            
            inb_hogpd_report_req_cfm(p_para->conidx, INB_HOGPD_OP_REPORT_WRITE, status, cfm);
            
            if(cfm)
                free(cfm);
        }
        break;
        
        default:
        break;
    }
#endif
    
    return ret;
}

