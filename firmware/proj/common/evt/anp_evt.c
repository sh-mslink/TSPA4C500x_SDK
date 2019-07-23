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
#include ".\ble\prf\inb_prf_anp.h"

#include "cmsis_os.h"

int handle_default_anp_evt(uint16_t eid, void *pv)
{
	int ret = -1;

#if (CFG_PRF_ANPC==1) || (CFG_PRF_ANPS==1)
	if ((eid & 0xFF00) == INB_ANP_EVT_CODE) { 	
		ret = 0;
		PRINTD(DBG_TRACE, "\n%s  id 0x%x\r\n", __func__, eid);
	}
	
	switch(eid)
	{
	case INB_EVT_ANPC_NEW_ALERT:
		{
			inb_evt_new_alert_t *ind = (inb_evt_new_alert_t*)pv;
			PRINTD(DBG_TRACE, "[conidx(0x%x),  cat_id(0x%x),  nb_new_alert(0x%x),  info_str_len(0x%x),  str_info(%s)] ", ind->conidx, ind->cat_id, ind->nb_new_alert, ind->info_str_len, (char*)ind->str_info);
		}
		break;
	case INB_EVT_ANPC_UNREAD_ALERT:
		{
			inb_evt_unread_alert_t *ind = (inb_evt_unread_alert_t*)pv;
			PRINTD(DBG_TRACE, "[conidx(0x%x),  cat_id(0x%x),  nb_unread_alert(0x%x)]", ind->conidx, ind->cat_id, ind->nb_unread_alert);
		}
		break;
	case INB_EVT_ANPS_NTF_IMMEDIATE_REQ_IND:
		{
			int ret, i;
			inb_evt_anps_ntf_immediate_req_ind_t *ind = (inb_evt_anps_ntf_immediate_req_ind_t*)pv;
			PRINTD(DBG_TRACE, "INB_EVT_ANPS_NTF_IMMEDIATE_REQ_IND:\r\n");
			PRINTD(DBG_TRACE, "\t\t[conidx(0x%x),  alert_type(0x%x),  cat_id(0x%x)]", ind->conidx, ind->alert_type, ind->cat_id);

			inb_anp_notify_alert_value value = {0};
			int categoryIndex;
			for (i=0;i<10;i++)
			{
				if (ind->cat_id & (1<<i)){
					categoryIndex = i;
					break;
				}
			}

			if (ind->alert_type == INB_ANP_NEW_ALERT){
				value.new_alert.cat_id = categoryIndex;
				value.new_alert.nb_new_alert = 1;
				strcpy(value.new_alert.str_info, "ImmediateAlert");
				value.new_alert.info_str_len = strlen(value.new_alert.str_info);
			}
			else
			{
				value.unread_alert_status.cat_id = categoryIndex;
				value.unread_alert_status.nb_unread_alert = 1;
			}
			ret = inb_anps_notify_alert(ind->conidx, ind->alert_type, value);
			if (ret != INB_ERR_NO_ERROR)
				PRINTD(DBG_ERR, "inb_anps_notify_alert return 0x%x\r\n", ret);
		}
		break;
	case INB_EVT_ANPS_NTF_CAT_STATUS_UPDATE_IND:
		{
			int i;
			inb_evt_anps_ntf_cat_status_update_ind_t *ind = (inb_evt_anps_ntf_cat_status_update_ind_t*)pv;
			const char *categoryInfo[10] = {"simple alert", "email", "news", "call", "missed call", "sms/mms", "voice mail", "schedule", "high priority alert", "instant msg"};

			for (i=0;i<10;i++) {
				if ( ind->cat_id & (1<<i)){
					if (ind->alert_type == INB_ANP_NEW_ALERT)
						PRINTD(DBG_TRACE, "category `%s` for New Alert %s\r\n", categoryInfo[i],  ind->ntf_status == INB_PRF_STOP_NTFIND ? "STOP_NTF" : "START_NTF");
					if (ind->alert_type == INB_ANP_UNREAD_ALERT)
						PRINTD(DBG_TRACE, "category `%s` for Unread Alert %s\r\n", categoryInfo[i],  ind->ntf_status == INB_PRF_STOP_NTFIND ? "STOP_NTF" : "START_NTF");
				}
			}
		}
		break;
	case INB_EVT_ANPS_NTF_STATUS_UPDATE_IND:
		{
			inb_evt_anps_ntf_status_update_ind_t *ind = (inb_evt_anps_ntf_status_update_ind_t*)pv;

			if (ind->alert_type == INB_ANP_NEW_ALERT)
				PRINTD(DBG_TRACE, "Client New Alert Characteristic Configuration Descriptor is updated to `%s`", ind->ntf_status == INB_PRF_STOP_NTFIND ? "STOP_NTF" : "START_NTF");
			if (ind->alert_type == INB_ANP_UNREAD_ALERT)
				PRINTD(DBG_TRACE, "Client Unread Alert Characteristic Configuration Descriptor is updated to `%s`", ind->ntf_status == INB_PRF_STOP_NTFIND ? "STOP_NTF":"START_NTF");
		}
	default:
		break;
	}
#endif

	return ret;
}

