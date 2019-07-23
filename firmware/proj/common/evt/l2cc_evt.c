#include "in_config.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "in_arm.h"
#include "in_debug.h"
#include ".\hal\hal_uart.h"
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_power.h"
#include ".\hal\hal_adc.h"
#include ".\ble\inb_api.h"

#include "cmsis_os.h"

int handle_default_l2cc_evt(uint16_t eid, void* pv, void* param)
{
	int ret = 0;

	switch (eid) 
	{
	case L2CAP_EVT_LECB_CONN_REQ:
		{
			inb_evt_lecb_connect_req_t *ind = (inb_evt_lecb_connect_req_t *)pv;
			inb_lecb_connect_cfm_t *p_cfm;
				
			PRINTD(DBG_TRACE, "L2CAP_EVT_LECB_CONN_REQ(%d)==>\r\n", ind->conidx);
			PRINTD(DBG_TRACE, "\t\t PSM: %d\r\n", ind->le_psm);
			PRINTD(DBG_TRACE, "\t\t peer_cid: %d\r\n", ind->peer_cid);
			PRINTD(DBG_TRACE, "\t\t peer_mtu: %d\r\n", ind->peer_mtu);
			PRINTD(DBG_TRACE, "\t\t peer_mps: %d\r\n", ind->peer_mps);

			if (param){
				p_cfm = (inb_lecb_connect_cfm_t *)param;
			}else{
				p_cfm = (inb_lecb_connect_cfm_t *)malloc(sizeof(inb_lecb_connect_cfm_t));
				memset(p_cfm, 0, sizeof(inb_lecb_connect_cfm_t));
				p_cfm->peer_cid = ind->peer_cid;
			}
			ret = inb_lecb_connect_req_cfm(ind->conidx, p_cfm);
			if (!param)		free(p_cfm);
		}
		break;
	case L2CAP_EVT_LECB_CONN_IND:
		{
			inb_evt_lecb_connect_ind_t *ind = (inb_evt_lecb_connect_ind_t *)pv;

			PRINTD(DBG_TRACE, "L2CAP_EVT_LECB_CONN_IND(%d)==>\r\n", ind->conidx);\
			PRINTD(DBG_TRACE, "\t\t status: %d\r\n", ind->lecb_conn_ind.status);
			PRINTD(DBG_TRACE, "\t\t PSM: %d\r\n", ind->lecb_conn_ind.le_psm);
			PRINTD(DBG_TRACE, "\t\t local_cid: %d\r\n", ind->lecb_conn_ind.local_cid);
			PRINTD(DBG_TRACE, "\t\t peer_credit: %d\r\n", ind->lecb_conn_ind.peer_credit);
			PRINTD(DBG_TRACE, "\t\t peer_mtu: %d\r\n", ind->lecb_conn_ind.peer_mtu);
			PRINTD(DBG_TRACE, "\t\t peer_mps: %d\r\n", ind->lecb_conn_ind.peer_mps);
		}
		break;
	case L2CAP_EVT_LECB_DISCONNECT:
		{
			inb_evt_lecb_disconnect_ind_t *ind = (inb_evt_lecb_disconnect_ind_t *)pv;

			PRINTD(DBG_TRACE, "L2CAP_EVT_LECB_DISCONNECT(%d)==>\r\n", ind->conidx);
			PRINTD(DBG_TRACE, "\t\t local_cid: %d\r\n", ind->local_cid);
			PRINTD(DBG_TRACE, "\t\t reason: 0x%02X\r\n", ind->reason);
		}
		break;
	case L2CAP_EVT_LECB_SDU_RECV:
		{
			inb_evt_lecb_sdu_recv_ind_t *ind = (inb_evt_lecb_sdu_recv_ind_t*)pv;
			uint16_t local_cid=0, local_credit=0;

			PRINTD(DBG_TRACE, "L2CAP_EVT_LECB_SDU_RECV(%d)==>\r\n", ind->conidx);
			PRINTD(DBG_TRACE, "\t\t status: %d\r\n", ind->status);
			PRINTD(DBG_TRACE, "\t\t cid: 0x%02X\r\n", ind->sdu.cid);
			PRINTD(DBG_TRACE, "\t\t credit: 0x%02X\r\n", ind->sdu.credit);
			PRINTD(DBG_TRACE, "\t\t data: ");
			for(int i=0;i<ind->sdu.length;i++)	PRINTD(DBG_TRACE, "%02X ", ind->sdu.data[i]);
			PRINTD(DBG_TRACE, "\r\n");

			if (param){
				local_cid = *(uint16_t*)param;
				local_credit = *((uint16_t*)param+1);
			}
			ret = inb_lecb_add_credit(ind->conidx, local_cid, local_credit);
		}
		break;
	default:
		return -1;
	}
    
	return ret;
}

