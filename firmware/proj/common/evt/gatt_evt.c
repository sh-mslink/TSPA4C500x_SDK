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

#ifdef CFG_PROJ_TPPC
#include "prf_tppc.h"
#endif

#ifdef CFG_PROJ_TPPS
#include "prf_tpps.h"
extern osTimerId tppsNtfTimerId;
#endif

#include "cmsis_os.h"

int handle_default_gatt_evt(uint16_t eid, void* pv, void* param)
{
	//PRINTD(DBG_TRACE, "\n%s  id 0x%x\r\n", __func__, eid);
	switch (eid)
	{
	case GATT_EVT_DISC_SVC:/// GATT service found indication
		{
			inb_evt_disc_svc_ind_t *ind = (inb_evt_disc_svc_ind_t *)pv;
            
//			PRINTD(DBG_TRACE, "DISC_SVC conidx:%d, start_hal:0x%X, end_hal:0x%X, uuin_len:%d, uuid1:0x%02X, uuid2:0x%02X\r\n",
//                    ind->conidx, ind->start_hdl, ind->end_hdl, ind->uuid_len, ind->uuid[0], ind->uuid[1]);

#ifdef CFG_PROJ_TPPC
            if(!memcmp(ind->uuid, &TPP_SERCICE_UUID, TPP_SERCICE_UUID_LEN))
            {
                PRINTD(DBG_TRACE, "TPP service found!!!\r\n");
                tppServiceHandle = ind->start_hdl + 1;
                tppc_cfg_notify(ind->conidx, true);
            }
#endif
		}
		break;
	case GATT_EVT_DISC_INCL_SVC:/// GATT include service found indication
		{
//			inb_evt_disc_svc_incl_ind_t *ind = (inb_evt_disc_svc_incl_ind_t *)pv;

//          PRINTD(DBG_TRACE, "DISC_INCLUDED_SVC(hdl=%d) on connection %d: \r\n", ind->attr_hdl, ind->conidx);
//          PRINTD(DBG_TRACE, "\t[start_hdl,end_hal] = [%d, %d]\r\n", ind->start_hdl, ind->end_hdl);
//          PRINTD(DBG_TRACE, "\tuuid = 0x%02X%02X \r\n", ind->uuid[1], ind->uuid[0]);
		}
		break;
	case GATT_EVT_DISC_CHAR:/// GATT Characteristic found indication
		{
//			inb_evt_disc_char_ind_t *ind = (inb_evt_disc_char_ind_t *)pv;

//			PRINTD(DBG_TRACE, "DISC_CHAR conidx:%d    attr_hdl:%02X    pointer_hdl:%02X   prop:%02X uuin_len: %d \r\n",ind->conidx,ind->attr_hdl,ind->pointer_hdl, ind->prop, ind->uuid_len);
//			PRINTD(DBG_TRACE, "uuid 0x%02X 0x%02X \n", ind->uuid[0], ind->uuid[1]);
		}
		break;
	case GATT_EVT_DISC_CHAR_DESC:/// GATT Characteristic Descriptor found indication
		{
//			inb_evt_disc_char_desc_ind_t *ind = (inb_evt_disc_char_desc_ind_t *)pv;

//			PRINTD(DBG_TRACE, "DISC_CHAR_DESC (hdl=%02X) on connection %d: \r\n", ind->attr_hdl, ind->conidx);
//			PRINTD(DBG_TRACE, "\tuuid = 0x%02X%02X", ind->uuid[1], ind->uuid[0]);
		}
		break;
	case GATT_EVT_NTF:/// GATT notify indication
		{
			inb_evt_ntf_ind_t *ind = (inb_evt_ntf_ind_t *)pv;

//			PRINTD(DBG_TRACE, "EVT_NTF on connection %d: \r\n", ind->conidx);
//			PRINTD(DBG_TRACE, "\thdl = 0x%02X\r\n", ind->handle);
//			PRINTD(DBG_TRACE, "\tlen = %d\r\n\tvalue: ", ind->length);
//			for (int i=0;i<ind->length;i++)
//				PRINTD(DBG_TRACE, "%02X ", ind->value[i]);
//			PRINTD(DBG_TRACE, "\r\n");
			
#ifdef CFG_PROJ_TPPC
            tppc_receive_notify(ind->conidx, ind->value, ind->length);
            //tppc_send_write(ind->conidx, ind->value, ind->length);
#endif
		}
		break;
	case GATT_EVT_IND:/// GATT indication
		{
//			inb_evt_ind_ind_t *ind = (inb_evt_ind_ind_t *)pv;
//			inb_gatt_indication_cfm(ind->conidx, ind->handle);

//			PRINTD(DBG_TRACE, "EVT_IND on connection %d: \r\n", ind->conidx);
//			PRINTD(DBG_TRACE, "\thdl = 0x%02X\r\n", ind->handle);
//			PRINTD(DBG_TRACE, "\tlen = %d\r\n\tvalue: ", ind->length);
//			for (int i=0;i<ind->length;i++)
//				PRINTD(DBG_TRACE, "%02X ", ind->value[i]);
//			PRINTD(DBG_TRACE, "\r\n");
		}
		break;
	case GATT_EVT_CCC_CHG_IND:/// GATT CCC changed indication  
		{
			inb_evt_ccc_changed_ind_t *ind = (inb_evt_ccc_changed_ind_t*)pv;

//			PRINTD(DBG_TRACE, "EVT_CCC_CHG_IND on connection %d: \r\n", ind->conidx);
//			PRINTD(DBG_TRACE, "\tnew cfg = 0x%02X\r\n", ind->ind_cfg);
			if(param)
				memcpy(param, &ind->ind_cfg, sizeof(ind->ind_cfg));
		}
		break;

	case GATT_EVT_RD_REQ:/// GATT read request indication  
		{
			inb_evt_read_req_ind_t* ind = (inb_evt_read_req_ind_t*)pv;
			if (param){
				inb_gatt_read_req_cfm(ind->conidx, ind->handle, 0/*ATT_ERR_NO_ERROR*/, *(uint16_t*)param, (uint8_t*)param+2);
//				for (int i=0;i<*(uint16_t*)param;i++)
//					PRINTD(DBG_TRACE, "%02X ", *((uint8_t*)param+2+i));
//				PRINTD(DBG_TRACE, "\r\n");
			}else{
				uint8_t value = 0;
				inb_gatt_read_req_cfm(ind->conidx, ind->handle, 0/*ATT_ERR_NO_ERROR*/, sizeof(value), &value);
//				PRINTD(DBG_TRACE, " EVT_RD_REQ conidx:%d  handle:%d value read:0x%x\r\n", ind->conidx, ind->handle, value);
			}
		}
		break;
	case GATT_EVT_WRT_REQ:/// GATT write request indication  
		{
			inb_evt_write_req_ind_t *ind = (inb_evt_write_req_ind_t*)pv;
			inb_gatt_write_req_cfm(ind->conidx, ind->handle, 0/*ATT_ERR_NO_ERROR*/);

//			PRINTD(DBG_TRACE, " EVT_WRT_REQ on connection %d:\r\n", ind->conidx);
//			PRINTD(DBG_TRACE, "\t handle: 0x%02X \r\n",ind->handle); 
//			PRINTD(DBG_TRACE, "\t value length: %d  offset: %d\r\n", ind->length, ind->offset);
//			PRINTD(DBG_TRACE, "\t value to write: ");
//			for (int i=0;i<ind->length;i++)
//				PRINTD(DBG_TRACE, "%02X ", ind->value[i]);
//			PRINTD(DBG_TRACE, "\r\n");
#ifdef CFG_PROJ_TPPS    
            if(ind->handle == g_TppPrimarySvc_shl + 1 + TPP_IDX_NTF_VAL_CFG)
            {
                if(ind->value[1] == 0x00 && ind->value[0] == 0x01)
                {
                    PRINTD(DBG_TRACE, "Notify enable\r\n");
                    osTimerStart(tppsNtfTimerId, 100);//100ms for test 
                }
                else if(ind->value[1] == 0x00 && ind->value[0] == 0x00)
                {
                    PRINTD(DBG_TRACE, "Notify disable\r\n");
                    osTimerStop(tppsNtfTimerId); 
                }
            }          
            else if(ind->handle == g_TppPrimarySvc_shl + 1 + TPP_IDX_WR_DATA_VAL)
            {
                tpps_receive_write(ind->conidx, ind->value, ind->length);
            }
#endif            
		}
		break;
	case GATT_EVT_ATT_INFO_REQ:/// GATT request attribute info  
		{			
			inb_evt_att_info_req_ind_t *ind = (inb_evt_att_info_req_ind_t*)pv;
			uint16_t length = 0;
			if (param)	length = *(uint16_t*)param;
			inb_gatt_att_info_req_cfm(ind->conidx, ind->handle, length, 0/*ATT_ERR_NO_ERROR*/);

//			PRINTD(DBG_TRACE, "EVT_ATT_INFO_REQ on connection %d:\r\n", ind->conidx);
//			PRINTD(DBG_TRACE, "\t handle: 0x%02X \r\n", ind->handle);
//			PRINTD(DBG_TRACE, "\t length: %d \r\n", length);
		}
		break;
	case GATT_EVT_SDP_SVC:/// GATT SDP Service indication
		{
//			inb_evt_sdp_svc_ind_t *ind = (inb_evt_sdp_svc_ind_t *)pv;

//			PRINTD(DBG_TRACE, "EVT_SDP_SVC on connection %d:\r\n", ind->conidx);
//			PRINTD(DBG_TRACE, "\t Service: [%d, %d]\r\n", ind->start_hdl, ind->end_hdl);
//
//			for (int i=0;i<ind->end_hdl-ind->start_hdl;i++){
//				if (ind->info[i].att_type == INB_GATT_SDP_INC_SVC){
//					PRINTD(DBG_TRACE, "\t\t Included Service: handle = [%d, %d] ; uuid = 0x%02X%02X", ind->info[i].inc_svc.start_hdl, ind->info[i].inc_svc.end_hdl, ind->info[i].inc_svc.uuid[1], ind->info[i].inc_svc.uuid[0]);
//				}
//			}

//			PRINTD(DBG_TRACE, "\t\t Characteristic Definition: \r\n");
//			for (int i=0;i<ind->end_hdl-ind->start_hdl;i++){
//				if (ind->info[i].att_type == INB_GATT_SDP_ATT_CHAR)
//					PRINTD(DBG_TRACE, "\t\t\t Declaration: { properties=0x%02X; val_handle=0x%02X }\r\n", ind->info[i].att_char.prop, ind->info[i].att_char.handle);
//				if (ind->info[i].att_type == INB_GATT_SDP_ATT_VAL)
//					PRINTD(DBG_TRACE, "\t\t\t Value: { uuid=0x%02X%02X }\r\n", ind->info[i].att.uuid[1], ind->info[i].att.uuid[0]);
//				if (ind->info[i].att_type == INB_GATT_SDP_ATT_DESC)
//					PRINTD(DBG_TRACE, "\t\t\t Descriptor: { uuid=0x%02X%02X }\r\n\r\n", ind->info[i].att.uuid[1], ind->info[i].att.uuid[0]);
//			}
		}
		break;
	default:
		return -1;
	}
	return 0;
}

