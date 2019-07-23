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
#include ".\ble\prf\inb_prf_pasp.h"

#include "cmsis_os.h"

int handle_default_pasp_evt(uint16_t eid, void *pv)
{
	int ret = -1;

#if (CFG_PRF_PASPC==1) || (CFG_PRF_PASPS==1)
	if ((eid & 0xFF00) == INB_PASP_EVT_CODE) {
		ret = 0;
		PRINTD(DBG_TRACE, "\n%s  id 0x%x\r\n", __func__, eid);
	}

	switch(eid)
	{
	case INB_EVT_PASPS_ALERT_STATUS_NTF_CFG_UPDATE_IND:
	case INB_EVT_PASPS_RINGER_SETTING_NTF_CFG_UPDATE_IND:
		inb_evt_pasps_ntf_cfg_update_ind_t *pInd = (inb_evt_pasps_ntf_cfg_update_ind_t*)pv;
		if (eid == INB_EVT_PASPS_ALERT_STATUS_NTF_CFG_UPDATE_IND)
			PRINTD(DBG_TRACE, "Alert Status config changed to 0x%x\r\n", pInd->ntf_status);
		else
			PRINTD(DBG_TRACE, "Ringer Setting config changed to 0x%x\r\n", pInd->ntf_status);
		break;
	case INB_EVT_PASPS_CMD_IND:
		{
			inb_evt_pasps_cmd_ind_t *pInd = (inb_evt_pasps_cmd_ind_t*)pv;
			if (pInd->cmd == INB_PASP_SILENT_MODE_CMD)
				PRINTD(DBG_TRACE, "===>Silent Moder\r\n");
			if (pInd->cmd == INB_PASP_MUTE_ONCE_CMD)
				PRINTD(DBG_TRACE, "===>Mute Once\r\n");
			if (pInd->cmd == INB_PASP_CANCEL_SILENT_MODE_CMD)
				PRINTD(DBG_TRACE, "===>Silent Normal\r\n");
		}
		break;
	case INB_EVT_PASPC_ALERT_STATUS_UPDATE:
		{
			inb_evt_paspc_alert_status_update_ind_t *pInd = (inb_evt_paspc_alert_status_update_ind_t *)pv;
			PRINTD(DBG_TRACE, "Alert Status updated to %d\r\n", pInd->alert_status);
		}
	case INB_EVT_PASPC_RINGER_SETTING_UPDATE:
		{
			inb_evt_paspc_ringer_setting_update_ind_t *pInd = (inb_evt_paspc_ringer_setting_update_ind_t*)pv;
			PRINTD(DBG_TRACE, "Ringer Setting updated to %d\r\n", pInd->ringer_setting);
		}
		break;
	default:
		break;
	}
#endif

	return ret;
}

