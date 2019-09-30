#include <stdlib.h>

#include ".\ble\inb_api.h"
#include "ble_test.h"
#include "gap_test.h"
#include "msg.h"
#include "..\inc\test_svc.h"
#ifdef CFG_PROJ_TPPC
#include "prf_tppc.h"
#endif
#ifdef CFG_PROJ_TPPS
#include "prf_tpps.h"
#endif
#ifdef CFG_PROJ_RCU
#include "msrcu_app.h"
#if MSRCU_BLE_VOICE_ATV_ENABLE
#include "prf_atv.h"
#endif

extern void msrcu_dev_ble_evt_cb(inb_evt_t *evt, void *param);
extern msrcuErr_t msrcu_dev_ble_hid_send2(msrcuBleHidReport_t *param);
#if MSRCU_MOTION_ENABLE
extern bool userMotionIsStop;
extern bool userMotionIsPause;
#endif
#endif

extern int handle_default_gap_evt(uint16_t eid, void *pv, void *evt_param);
extern int handle_default_gatt_evt(uint16_t eid, void *pv, void *evt_param);
#ifdef CFG_PROJ_TPPS
extern osTimerId tppsNtfTimerId;
#endif
#if (CFG_PRF_ANPC || CFG_PRF_ANPS)
extern int handle_default_anp_evt(uint16_t eid, void *pv);
#endif
#if (CFG_PRF_BASC || CFG_PRF_BASS)
extern int handle_default_bas_evt(uint16_t eid, void *pv);
#endif
#if (CFG_PRF_DISC || CFG_PRF_DISS)
extern int handle_default_dis_evt(uint16_t eid, void *pv);
#endif
#if (CFG_PRF_HOGPBH || CFG_PRF_HOGPD || CFG_PRF_HOGPRH)
extern int handle_default_hogp_evt(uint16_t eid, void *pv);
#endif
#if (CFG_PRF_PASPC || CFG_PRF_PASPS)
extern int handle_default_pasp_evt(uint16_t eid, void *pv);
#endif

#if CFG_PRF_HOGPD
static const inb_hogpd_cfg_t hogpd_cfg[1] = {
    {
        .svc_features =	INB_HOGPD_CFG_PROTO_MODE | INB_HOGPD_CFG_REPORT_NTF_EN,
        .report_nb = 3,
        .report_char_cfg = {INB_HOGPD_CFG_REPORT_IN | INB_HOGPD_CFG_REPORT_WR,
                INB_HOGPD_CFG_REPORT_IN | INB_HOGPD_CFG_REPORT_WR,
                INB_HOGPD_CFG_REPORT_IN | INB_HOGPD_CFG_REPORT_WR
                , 0, 0},
        .report_id = {1, 2, 3, 0, 0},
        .hid_info = {
            .bcdHID = 0x1002,
            .bCountryCode = 0x21,
            .flags = INB_HIDS_NORM_CONNECTABLE | INB_HIDS_REMOTE_WAKE_CAPABLE,
        },
        .ext_ref = {0},
    }
};
#endif

static uint8_t ble_mem_env[CFG_BLE_STK_ENV_MEM_SIZE];
static uint8_t ble_mem_db[CFG_BLE_STK_DB_MEM_SIZE];
static uint8_t ble_mem_msg[CFG_BLE_STK_MSG_MEM_SIZE];
static uint8_t ble_mem_non_rtn[CFG_BLE_STK_NON_RETN_MEM_SIZE];
volatile static int g_conidx = -1;

uint8_t gSvcChangeCfg = 0;
uint16_t g_conn_latency = 0;
uint16_t g_conn_interval = 0;
uint16_t g_conn_sup_timeout = 0;

inb_set_dev_config_t g_BleCfg = {0};

struct _l2cc_test_env_ g_L2ccTestEnv;

static int advActvIdx = 0;
static int scanActvIdx = 0;
static int connectActvIdx = 0;

int start_adv(void)
{
    int res = 0;
	inb_actv_create_t adv = {0};
	uint8_t advData[] = 
    {
        0x02,//AD Element Length
        0x0A,//AD Type: Transmit Power
        0x00,//AD Data: 0dBm
    };   
    uint8_t scanRspData[] = 
    {      
#ifdef CFG_PROJ_TPPS
        0x0B,//AD Element Length
        0x08,//AD Type: Shortened local name
        'T','r','o','p','o','s',' ','T','P','P',//AD Data Bytes: "Tropos TPP"
#else
        0x07,//AD Element Length
        0x08,//AD Type: Shortened local name
        'T','r','o','p','o','s',//AD Data Bytes: "Tropos"
#endif
    };        

	adv.option = 0;
	adv.own_addr_type = 0;
	adv.adv_param.type = ADV_TYPE_LEGACY;
	adv.adv_param.disc_mode = ADV_MODE_LIM_DISC;
	adv.adv_param.prop = ADV_PROP_UNDIR_CONN;
	adv.adv_param.max_tx_pwr = 0;
	adv.adv_param.filter_pol = ADV_FILT_ALLOW_SCAN_ANY_CON_ANY;
	adv.adv_param.prim_cfg.adv_intv_min = 0x20;
	adv.adv_param.prim_cfg.adv_intv_max = 0x20;
	adv.adv_param.prim_cfg.chnl_map = CHANNEL_37|CHANNEL_38|CHANNEL_39;
	adv.adv_param.prim_cfg.phy = PHY_LE_1MBPS;

	res = inb_actv_create(&adv, &advActvIdx);
    if(res)
		return res;

	/// Set advertising data
	res = inb_actv_data(advActvIdx, 0, advData, sizeof(advData));
    if(res)
		return res;

	/// Set scan response data
	res = inb_actv_data(advActvIdx, 1, scanRspData, sizeof(scanRspData));
    if(res)
		return res;

	/// Start advertising
	inb_actv_start_t adv_start = {0};
	adv_start.option = 0;
	adv_start.u.adv_param.duration = 0;
	adv_start.u.adv_param.max_adv_evt = 0;
	res = inb_actv_start(advActvIdx, &adv_start);
    if(res)
        PRINTD(DBG_ERR, "Failed to start advertisement activity...0x%x\r\n", res);
    else
        PRINTD(DBG_ERR, "Advertising start.\r\n");
    
	return res;
}	

int stop_adv(void)
{
    int res = 0;
    
	res = inb_actv_stop(advActvIdx);
    if(res)
        PRINTD(DBG_ERR, "Failed to stop advertisement activity...0x%x\r\n", res);
    else
        PRINTD(DBG_ERR, "Advertising stop.\r\n");
    
    return res;
}

static int create_conncet(void)
{
	int res = 0;    

	inb_actv_create_t cparam;

	memset(&cparam, 0, sizeof(inb_actv_create_t));

	cparam.option = 2;
	cparam.own_addr_type =0;

	res = inb_actv_create(&cparam, &connectActvIdx);
	if (res) {
		PRINTD(DBG_ERR, "Failed to create init activity...0x%x\r\n", res);
	}
    
	return res; 
}

int start_connect(inb_bdaddr_t* addr)
{
	int res = 0;
    
    res = create_conncet();
    if(res)
        return res;
    
	/* start activity */
	inb_actv_start_t sparam;

	memset(&sparam, 0, sizeof(inb_actv_start_t));
	sparam.option = 2;
	sparam.u.init_param.type = INIT_TYPE_DIRECT_CONN_EST;
	sparam.u.init_param.prop = INIT_PROP_1M;
	sparam.u.init_param.conn_tmo = 0;
    
    sparam.u.init_param.scan_param_1m.scan_intv = 16;
	sparam.u.init_param.scan_param_1m.scan_wd = 8;
	sparam.u.init_param.conn_param_1m.conn_intv_min = 6;
	sparam.u.init_param.conn_param_1m.conn_intv_max = 6;
	sparam.u.init_param.conn_param_1m.conn_latency = 0;
	sparam.u.init_param.conn_param_1m.supervision_to = 100;
	sparam.u.init_param.conn_param_1m.ce_len_min = 0x0000;
	sparam.u.init_param.conn_param_1m.ce_len_max = 0xffff;
    
//	sparam.u.init_param.scan_param_coded.scan_intv = 16;
//	sparam.u.init_param.scan_param_coded.scan_wd = 8;
//	sparam.u.init_param.conn_param_2m.conn_intv_min = 80;
//	sparam.u.init_param.conn_param_2m.conn_intv_max = 80;
//	sparam.u.init_param.conn_param_2m.conn_latency = 0;
//	sparam.u.init_param.conn_param_2m.supervision_to = 1000;
//	sparam.u.init_param.conn_param_2m.ce_len_min = 0;
// 	sparam.u.init_param.conn_param_2m.ce_len_max = 512;
    
//	sparam.u.init_param.scan_param_coded.scan_intv = 16;
//	sparam.u.init_param.scan_param_coded.scan_wd = 8;
//	sparam.u.init_param.conn_param_coded.conn_intv_min = 80;
//	sparam.u.init_param.conn_param_coded.conn_intv_max = 80;
//	sparam.u.init_param.conn_param_coded.conn_latency = 0;
//	sparam.u.init_param.conn_param_coded.supervision_to = 1000;
//	sparam.u.init_param.conn_param_coded.ce_len_min = 0;
//	sparam.u.init_param.conn_param_coded.ce_len_max = 512;
    
	memcpy(&sparam.u.init_param.peer_addr, addr, sizeof(inb_bdaddr_t));
    
	res = inb_actv_start(connectActvIdx, &sparam);
	if (res != 0) {
		 PRINTD(DBG_ERR, "Failed to start conncet activity...0x%x\r\n", res);
  
 	} else {
 		 PRINTD(DBG_ERR, "Connect start.\r\n");
 	}
    
	return res;
}

static int create_scan(void)
{
	int res = 0;
	/* create adv activity */
	inb_actv_create_t cparam;
	
	memset(&cparam, 0, sizeof(inb_actv_create_t));

	cparam.option= 1;
	cparam.own_addr_type = 0;

	res = inb_actv_create(&cparam, &scanActvIdx);
	if (res != 0) {
		PRINTD(DBG_ERR, "Failed to create scan activity...0x%x\r\n", res);
		
	} else {
		;//PRINTD(DBG_ERR, "create scan activity.\r\n");
	}
	return res;
}

int start_scan(void)
{
	int res = 0;
    
    res = create_scan();
    if(res)
        return res;
    
	/* start activity */

	inb_actv_start_t sparam;
	memset(&sparam, 0, sizeof(inb_actv_start_t));
	sparam.option= 1;
	sparam.u.scan_param.type = CONN_DISC;
	sparam.u.scan_param.prop = SCAN_PROP_PHY_1M | SCAN_PROP_ACTIVE_1M;
	sparam.u.scan_param.scan_param_1m.scan_intv = 16;
	sparam.u.scan_param.scan_param_1m.scan_wd = 8;
	sparam.u.scan_param.dup_filt_pol = DUPLIC_DIS;
	
	res = inb_actv_start(scanActvIdx, &sparam);
	if (res != 0) {
		PRINTD(DBG_ERR, "Failed to start scan activity...0x%x\r\n", res);
		
	} else {
		PRINTD(DBG_ERR, "Scanning start.\r\n");
	}
	return res;
}

int stop_scan(void)
{
    int res = 0;
    
	res = inb_actv_stop(scanActvIdx);
    if(res)
        PRINTD(DBG_ERR, "Failed to stop scan activity...0x%x\r\n", res);
    else
        PRINTD(DBG_ERR, "Scanning stop.\r\n");
    
    return res;
}

int discovery_service(int conIdx)
{
    int res = 0;

    inb_gatt_disc_t *p_read = (inb_gatt_disc_t*)malloc(sizeof(inb_gatt_disc_t));
    
    if(p_read)
    {
        memset(p_read, 0, sizeof(inb_gatt_disc_t));

        p_read->start_hdl = 0x0001;
        p_read->end_hdl = 0xffff;

        res = inb_gatt_discovery(conIdx, GATT_DISC_ALL_SVC, p_read);
        if(res)
            PRINTD(DBG_ERR, "Discovery service error:0x%02X.\r\n", res);
        
        if(p_read)
            free(p_read);
    }
    
    return res;
}

int prof_init(void)
{
    int ret = 0;
    
#if (CFG_PRF_BASS==1)
	{
		inb_bas_prf_t prf;
		memset(&prf, 0, sizeof(inb_bas_prf_t));
		prf.sec_lvl = ATT_PERM_NO_AUTH;
		prf.bas_nb = 1;
		prf.features[0] = INB_BAS_BATT_LVL_NTF_SUP;	
		prf.batt_level_pres_format[0].unit = INB_ATT_UNIT_PERCENTAGE;
		prf.batt_level_pres_format[0].description = 1;
		prf.batt_level_pres_format[0].format = INB_ATT_FORMAT_UINT8;
		prf.batt_level_pres_format[0].exponent = 0;
		prf.batt_level_pres_format[0].name_space = 1;
		ret = inb_bass_add(&prf);
		if (ret != INB_ERR_NO_ERROR)
			PRINTD(DBG_ERR, "inb_bass_add return %d\r\n", ret);
	}
#endif
#if (CFG_PRF_ANPC==1)
	{
		inb_add_prf_t prf;
		prf.sec_lvl = 0;
		prf.start_hdl = 0;
		inb_anpc_add(&prf);
	}
#endif
#if (CFG_PRF_ANPS==1)
	{
		uint16_t supp_new_alert_cat, supp_unread_alert_cat;

		supp_new_alert_cat = supp_unread_alert_cat = INB_ANP_SUPP_CAT_ID_SPL_ALERT_SUP |INB_ANP_SUPP_CAT_ID_EMAIL_SUP | INB_ANP_SUPP_CAT_ID_NEWS_SUP | \
                                                                                    INB_ANP_SUPP_CAT_ID_CALL_SUP | INB_ANP_SUPP_CAT_ID_MISSED_CALL_SUP | INB_ANP_SUPP_CAT_ID_SMS_MMS_SUP | \
                                                                                    INB_ANP_SUPP_CAT_ID_VOICE_MAIL_SUP | INB_ANP_SUPP_CAT_ID_SCHEDULE_SUP | INB_ANP_SUPP_CAT_ID_HIGH_PRTY_ALERT | \
                                                                                    INB_ANP_SUPP_CAT_ID_INST_MSG;

		ret = inb_anps_add(INB_ATT_PERM_POS_SVC_EKS, supp_new_alert_cat, supp_unread_alert_cat);
		if (ret != INB_ERR_NO_ERROR)
			PRINTD(DBG_ERR, "inb_anps_add return %d\r\n", ret);
	}
#endif
#if (CFG_PRF_PASPS==1)
	{
		enum inb_pasp_alert_status alert_status = INB_PASP_ALERT_STATUS_VAL_MAX;
		enum inb_pasp_ringer_setting ringer_setting = INB_PASP_RINGER_NORMAL;

		if (1){//SP/BV-01-C
			alert_status = 0;
		}

		ret = inb_pasps_add(INB_ATT_PERM_POS_SVC_EKS, alert_status, ringer_setting);
		if (ret != INB_ERR_NO_ERROR)
			PRINTD(DBG_ERR, "inb_pasps_add return %d\r\n", ret);
	}
#endif
#if (CFG_PRF_PASPC==1)
	{
		ret = inb_paspc_add(INB_ATT_PERM_POS_SVC_EKS);
		if (ret != INB_ERR_NO_ERROR)
			PRINTD(DBG_ERR, "inb_paspc_add return %d\r\n", ret);
	}
#endif
#if (CFG_PRF_DISS==1)
	{/// Add device information profiles
		inb_dis_prf_t prf;
		prf.sec_lvl = ATT_PERM_NO_AUTH;
		prf.features = INB_DISS_ALL_FEAT_SUP;
		ret = inb_diss_add(&prf);
		if (ret != INB_ERR_NO_ERROR)
			PRINTD(DBG_ERR, "inb_diss_add return %d\r\n", ret);
	}
#endif
#if (CFG_PRF_HOGPD==1)
	{/// Add HID over GATT
		inb_hogp_prf_t *p_hogp_prf = NULL;
		p_hogp_prf = (inb_hogp_prf_t*)malloc(sizeof(inb_hogp_prf_t));
		p_hogp_prf->multi_instance = 0;

		//Following params are HOGPD only
		p_hogp_prf->check_enc_key_size = false;
		p_hogp_prf->sec_lvl = ATT_PERM_NO_AUTH;
		p_hogp_prf->hids_nb = 1;
	
		memcpy(p_hogp_prf->cfg, hogpd_cfg, sizeof(inb_hogpd_cfg_t));
		
		ret = inb_hogpd_add(p_hogp_prf);
		if (ret != INB_ERR_NO_ERROR)
			PRINTD(DBG_ERR, "inb_hogpd_add return %d\r\n", ret);        
	}
#endif
	
	return ret;
}

void handle_default_ble_evt(inb_evt_t *evt, void *param)
{
	int ret = -1;

	switch (evt->evt_id & 0xFF00) 
	{
	case GAP_EVT_CODE:
		ret = handle_default_gap_evt(evt->evt_id, (void *)&evt->param, param);
		break;
	case GATT_EVT_CODE:
		ret = handle_default_gatt_evt(evt->evt_id, (void *)&evt->param, param);
		break;
	case L2CAP_EVT_CODE:
		ret = handle_default_l2cc_evt(evt->evt_id, (void *)&evt->param, param);
		break;
#if (CFG_PRF_BASC || CFG_PRF_BASS)
	case BAS_EVT_CODE:
		ret = handle_default_bas_evt(evt->evt_id, (void *)&evt->param);
		break;
#endif
#if (CFG_PRF_DISC || CFG_PRF_DISS)    
	case DIS_EVT_CODE:
		ret = handle_default_dis_evt(evt->evt_id, (void *)&evt->param);
		break;
#endif
#if (CFG_PRF_HOGPBH || CFG_PRF_HOGPD || CFG_PRF_HOGPRH)   
	case HOGP_EVT_CODE:
		ret = handle_default_hogp_evt(evt->evt_id, (void *)&evt->param);
		break;
#endif
#if (CFG_PRF_ANPC || CFG_PRF_ANPS)   
	case INB_ANP_EVT_CODE:
		ret = handle_default_anp_evt(evt->evt_id, (void *)&evt->param);
		break;
#endif
#if (CFG_PRF_PASPC || CFG_PRF_PASPS)  
	case INB_PASP_EVT_CODE:
		ret = handle_default_pasp_evt(evt->evt_id, (void *)&evt->param);
		break;
#endif 
	default:
		break;
	}

	if (ret == -1)
		PRINTD(DBG_TRACE, "\n%s  id 0x%x\r\n", __func__, evt->evt_id);	
}

void ble_event_callback(inb_evt_t *evt)
{
	void* param = NULL;
	
	switch(evt->evt_id)
	{
	case GATT_EVT_ATT_INFO_REQ:/// GATT request attribute info  
		//To Do: Could be trigger during prepare write to check if attribute modification is authorized by profile/application or not and to get current attribute length. 
		{
			inb_evt_att_info_req_ind_t *ind = (inb_evt_att_info_req_ind_t*)evt->param;
			param = (uint16_t*)malloc(sizeof(uint16_t));
			*(uint16_t*)param = testSvc_get_att_len(ind->handle);
		}
		break;
	case GATT_EVT_RD_REQ:
		//To Do: get the data from non-volatile memory. Here as a sample, get from test svc 
		{
			inb_evt_read_req_ind_t* ind = (inb_evt_read_req_ind_t*)evt->param;
			param = testSvc_get_att_value(ind->handle);
		}
		break;
	case GATT_EVT_WRT_REQ:/// GATT write request indication  
		//To Do: store the data to non-volatile memory e.g. flash 
		{
			inb_evt_write_req_ind_t *ind = (inb_evt_write_req_ind_t*)evt->param;
			testSvc_set_att_value(ind->handle, ind->length, ind->offset, (void*)ind->value);
		}		
		break;
	case GATT_EVT_CCC_CHG_IND:/// GATT CCC changed indication  
		//To Do: store the "Service Change Client Configuration Descriptor" value in non-volatile memory e.g. flash.
		{
			param = (uint8_t*)malloc(sizeof(gSvcChangeCfg));
			*(uint8_t*)param = gSvcChangeCfg;
		}
		break;
	case GAP_EVT_CONN_REQ:
		///	To Do: when reconnect, get "Service Change Client Configuration Descriptor" value from non-volatile memory
		///	and send back within inb_conn_cfm_t.
		{
			inb_evt_conn_req_t *p_param = (inb_evt_conn_req_t *)evt->param;
			g_conn_latency = p_param->con_latency;
			g_conn_interval = p_param->con_interval;
			g_conn_sup_timeout = p_param->sup_to;
		
			/// issue confirm to accept connection..
			inb_conn_cfm_t *p_cfm = (inb_conn_cfm_t*)malloc(sizeof(inb_conn_cfm_t));
			memset(p_cfm, 0, sizeof(inb_conn_cfm_t));
			p_cfm->auth = AUTH_REQ_NO_MITM_BOND;
			p_cfm->svc_changed_ind_enable = gSvcChangeCfg;
			param = p_cfm;
		}
		break;
	case L2CAP_EVT_LECB_CONN_REQ:
		//To Do: When peer device requests a LE credit connection. Application is to provide Local lecb info
		{
			inb_evt_lecb_connect_req_t *ind = (inb_evt_lecb_connect_req_t *)evt->param;
			g_L2ccTestEnv.peer.cid = ind->peer_cid;
			
			inb_lecb_connect_cfm_t *p_cfm = (inb_lecb_connect_cfm_t*)malloc(sizeof(inb_lecb_connect_cfm_t));
			p_cfm->accept = (ind->le_psm == g_L2ccTestEnv.local.le_psm);
			p_cfm->local_cid = 0;//automatically allocate
			p_cfm->local_credit = floor( (g_BleCfg.max_mtu+g_BleCfg.max_mps+1)/g_BleCfg.max_mps) + 1;
			p_cfm->local_mps = g_BleCfg.max_mps;
			p_cfm->local_mtu = g_BleCfg.max_mtu;
			p_cfm->peer_cid = ind->peer_cid;
			param = p_cfm;
		}
		break;
	case L2CAP_EVT_LECB_CONN_IND:
		//To Do: When LE credit connection is established. Application to store local cid and peer info
		{
			inb_evt_lecb_connect_ind_t *ind = (inb_evt_lecb_connect_ind_t *)evt->param;
			g_L2ccTestEnv.local.cid = ind->lecb_conn_ind.local_cid;
			g_L2ccTestEnv.peer.le_psm= ind->lecb_conn_ind.le_psm;
			g_L2ccTestEnv.peer.credit = ind->lecb_conn_ind.peer_credit;
			g_L2ccTestEnv.peer.mtu = ind->lecb_conn_ind.peer_mtu;
			g_L2ccTestEnv.peer.mps = ind->lecb_conn_ind.peer_mps;
		}
		break;
	case L2CAP_EVT_LECB_DISCONNECT:
		//To Do: When a LE Credit connection is terminated. Application clear lecb peer info.
		{
			g_L2ccTestEnv.local.cid = 0;
			memset(&g_L2ccTestEnv.peer, 0, sizeof(struct _l2cc_lecb_info_));
		}
		break;
	case L2CAP_EVT_LECB_SDU_RECV:
		//To Do: When a complete SDU has been received from peer device. Application to provide local cid + local credit
		{
			inb_evt_lecb_sdu_recv_ind_t *ind = (inb_evt_lecb_sdu_recv_ind_t *)evt->param;
			param = (uint16_t*)malloc(2*sizeof(uint16_t));;
			*((uint16_t*)param) = g_L2ccTestEnv.local.cid;
			*((uint16_t*)param+1) = ind->sdu.credit;
		}
		break;
	default:
		break;
	}
	handle_default_ble_evt(evt,param);
#ifdef CFG_PROJ_RCU
    msrcu_dev_ble_evt_cb(evt,param);
#endif    
	free(param);
}

int ble_stack_init()
{
    int res = 0;
    
	if (!CFG_BLE_STK_MEM_EN)
		return INB_PLT_ERR_INVALID_CONFIG;

	/// Stack
	inb_param_t b_cfg = {
		.bd_addr = {CFG_BLE_PARAM_BD_ADDR},
		.sleep_algo_dur = CFG_BLE_PARAM_SLP_ALGO_DUR,
		.lpc_drift = CFG_BLE_PARAM_LPC_DRIFT,
		.radio_wakeup_time = CFG_BLE_PARAM_RADIO_WUP_TIME,
		.osc_wakeup_time = CFG_BLE_PARAM_OSC_WUP_TIME,
		.ext_wakeup_time = 0,
		.coded_phy_500_en = CFG_BLE_PARAM_CODED_PHY_500_EN,
		.sleep_en = CFG_BLE_PARAM_SLEEP_EN,
		.ext_wakeup_en = 0,
		.pub_key_valid = CFG_BLE_PARAM_P256_PUB_KEY_VALID,
		.pub_key = {CFG_BLE_PARAM_P256_PUB_KEY},
		.priv_key_valid = CFG_BLE_PARAM_P256_PRIV_KEY_VALID,
		.priv_key = {CFG_BLE_PARAM_P256_PRIV_KEY},
		.trace_flag = CFG_BLE_PARAM_TRACE_FLAG
	};
	inb_mem_t m_cfg = {
		.retn_mem_env_start_addr = (uint32_t)ble_mem_env,
		.retn_mem_env_size = CFG_BLE_STK_ENV_MEM_SIZE,
		.retn_mem_db_start_addr = (uint32_t)ble_mem_db,
		.retn_mem_db_size = CFG_BLE_STK_DB_MEM_SIZE,
		.retn_mem_msg_start_addr = (uint32_t)ble_mem_msg,
		.retn_mem_msg_size = CFG_BLE_STK_MSG_MEM_SIZE,
		.non_retn_mem_start_addr = (uint32_t)ble_mem_non_rtn,
		.non_retn_mem_size = CFG_BLE_STK_NON_RETN_MEM_SIZE,
	};

	/// Initialize BLE stack
    res = inb_init(&b_cfg, &m_cfg);
    
    return res;
}

int ble_config(int role)
{
    int res;
    
	if ((res = ble_stack_init()) != INB_ERR_NO_ERROR) {
		PRINTD(DBG_ERR, "failed init stack, %d\r\n", res);
            return 1;		
	}

	/// Initialize BLE APIs
	if ((res = inb_api_init(ble_event_callback)) != INB_ERR_NO_ERROR) {
		PRINTD(DBG_ERR, "failed init api, %d\r\n", res);
		return 1;
	}

	/// Reset BLE stack
	if ((res = inb_reset()) != INB_ERR_NO_ERROR) {
		PRINTD(DBG_ERR, "failed ble reset, %d\r\n", res);
		return 1;
	}		
	
	/// Configure device
	//inb_set_dev_config_t cfg = {0};
    if(role)
        g_BleCfg.role = ROLE_CENTRAL;
    else
        g_BleCfg.role = ROLE_PERIPHERAL;
	g_BleCfg.renew_dur = CFG_BLE_DEV_RENEW_DURATION;
    g_BleCfg.pairing_mode = PAIRING_LEGACY;
	g_BleCfg.att_slv_pref_conn_param_present = 1;
	g_BleCfg.svc_change_feat_present = 1;
    g_BleCfg.sugg_max_tx_octets = 251;
    g_BleCfg.sugg_max_tx_time = 2120;
    g_BleCfg.max_mtu = 2048;
    g_BleCfg.max_mps = 2048;
	g_BleCfg.max_nb_lecb = 2;
	g_BleCfg.tx_pref_phy = PHY_LE_1MBPS;
	g_BleCfg.rx_pref_phy = PHY_LE_1MBPS;
	g_BleCfg.att_devname_write_perm = WRITE_NO_AUTH;
	g_BleCfg.att_apperance_write_perm = WRITE_NO_AUTH;
	//cfg.privacy_cfg=1 << 2;
	if (inb_set_dev_config(&g_BleCfg) != INB_ERR_NO_ERROR){
		return 0;
	}
	
	prof_init();

#ifdef CFG_PROJ_RCU
#if MSRCU_BLE_VOICE_ATV_ENABLE   
	if(!role)
        atv_add_svc();
#endif
#endif
    
#ifdef CFG_PROJ_TPPS    
	if(!role)
        tpps_add_svc();
#endif
    
    return 0;
}

void handle_default_msg(msg_t *p_msg)
{
	uint8_t conidx = 0;
	static int actv_del = 0;

	switch (p_msg->msg_id)
	{
	case MSG_ACTV_STOP:
		{
            //PRINTD(DBG_TRACE, "msg actv stop.....\r\n");
			msg_actv_stop_t *p = (msg_actv_stop_t *)p_msg;
            
			inb_actv_del(p->actv_idx);
			actv_del = 1;
		}
		break;
        
//    case MSG_START_CONNECT:
//        {
//            //PRINTD(DBG_TRACE, "msg start connect...\r\n");
//			msg_start_connect_t *p = (msg_start_connect_t *)p_msg;
//            
//            start_connect(&p->addr);
//        }
//        break;
        
	case MSG_DISC:
		{
            //PRINTD(DBG_TRACE, "msg disc.....\r\n");
			msg_disc_t *p = (msg_disc_t *)p_msg;

			g_conidx = -1;
			if(actv_del)
            {
				actv_del = 0;
				conidx = 0;
#if defined(CFG_PROJ_TPPC)
                PRINTD(DBG_TRACE, "Disconnected, idx:%d, reason:0x%02X.\r\n", p->conidx, p->reason);
                if(start_scan())
                    return;
#elif defined(CFG_PROJ_TPPS)
                PRINTD(DBG_TRACE, "Disconnected, idx:%d, reason:0x%02X.\r\n", p->conidx, p->reason);
                osTimerStop(tppsNtfTimerId); 	
                if(start_adv())
                    return;
#endif            
			}
		}
		break;
        
	case MSG_CONNECTED:
		{
			//PRINTD(DBG_TRACE, "msg connected...\r\n");
			msg_connected_t *p = (msg_connected_t *)p_msg;
					
			conidx = p->conidx;
			g_conidx = conidx;
            
#ifdef CFG_PROJ_RCU
            osDelay(100);
            
            uint16_t mtu = 251;
            uint16_t err = inb_gatt_exc_mtu(p->conidx, &mtu);
            if(err)
                PRINTD(DBG_TRACE, "inb_gatt_exc_mtu ERROR:0x%X\r\n", err);
#else
            PRINTD(DBG_TRACE, "Connected, idx:%d, ", p->conidx);
            PRINTD(DBG_TRACE, "addr type:%d, ", p->peer_addr_type);
            PRINTD(DBG_TRACE, "addr:0x %02X %02X %02X %02X %02X %02X, ", 
                    p->peer_addr.addr[0], p->peer_addr.addr[1], p->peer_addr.addr[2], 
                    p->peer_addr.addr[3], p->peer_addr.addr[4], p->peer_addr.addr[5]);
            PRINTD(DBG_TRACE, "interval:%d, ", p->con_interval);
            PRINTD(DBG_TRACE, "latency:%d, ", p->con_latency);
            PRINTD(DBG_TRACE, "timeout:%d.\r\n", p->sup_to);
#endif
            
#ifdef CFG_PROJ_TPPC
            discovery_service(p->conidx);
#endif
		}
		break;
        
    case MSG_CON_PARAM_UPD_REQ:
    {
		//PRINTD(DBG_TRACE, "msg con param upd req...\r\n");
        osDelay(1000);//for stabilization
        
        msg_con_param_upd_req_t *p = (msg_con_param_upd_req_t *)p_msg;        
        inb_conn_param_update_t *p_upd = (inb_conn_param_update_t *)malloc(sizeof(inb_conn_param_update_t));
        if(!p_upd)
            return;
        
        p_upd->intv_min = p->interval_min;
        p_upd->intv_max = p->interval_max;
        p_upd->latency = p->latency;
        p_upd->time_out = p->time_out;
        p_upd->ce_len_min = p->ce_len_min;
        p_upd->ce_len_max = p->ce_len_max;
        
        int err = inb_conn_param_update(p->conidx, p_upd);
        if(err)
        {
            PRINTD(DBG_TRACE, "inb_conn_param_update error:0x%02X.\r\n", err);
        }
        else
            PRINTD(DBG_TRACE, "Request to update connection parameters.\r\n");
        
        if(p_upd)
            free(p_upd);
    }
    break;
        
    case MSG_CON_PARAM_UPD:
    {
		//PRINTD(DBG_TRACE, "msg con param upd...\r\n");
    }
    break;
        
	case MSG_PAIR:
    {
		//PRINTD(DBG_TRACE, "msg pair.....\r\n");
		#if  0
			if (cfg.role == ROLE_CENTRAL){
				int actv_idx = 0;
				if (create_init(&actv_idx))
					return 0;
				if (start_init(actv_idx))
					return 0;
			}
		#endif
            
        msg_pair_t *p = (msg_pair_t *)p_msg;

        if(p->status)
        {
#if CFG_PRF_BASS
        /// Enable Battery Service...
            inb_bass_enable_req_t req;

            req.ntf_cfg = CLI_STOP_NTFIND;
            req.old_batt_lvl[0] = 0;
            if(inb_bass_enable(conidx, &req) != INB_ERR_NO_ERROR)
                ;//PRINTD(DBG_TRACE, "inb_bass_enable fail.\r\n");
            else
                ;//PRINTD(DBG_TRACE, "inb_bass_enable success.\r\n");
#endif      
            
#if CFG_PRF_DISS
            /// Enable Device Information Service...
#endif
#if CFG_PRF_HOGPD
            /// Enable HOGPD Profiles
            uint16_t ntf_cfg[3];
            ntf_cfg[0] = INB_HOGPD_CFG_REPORT_NTF_EN
                    | (INB_HOGPD_CFG_REPORT_NTF_EN << 1)
                    | (INB_HOGPD_CFG_REPORT_NTF_EN << 2);
//                uint16_t ntf_cfg[3];
//                ntf_cfg[0] = INB_HOGPD_CFG_REPORT_NTF_EN;
//                ntf_cfg[1] = INB_HOGPD_CFG_REPORT_NTF_EN << 1;
//                ntf_cfg[2] = INB_HOGPD_CFG_REPORT_NTF_EN << 2;
            if(inb_hogpd_enable(conidx, ntf_cfg) != INB_ERR_NO_ERROR)
                ;//PRINTD(DBG_TRACE, "inb_hogpd_enable fail.\r\n");
            else
                ;//PRINTD(DBG_TRACE, "inb_hogpd_enable success.\r\n");
#endif                
        }
        else
        {
            ;//PRINTD(DBG_TRACE, "fail...\r\n");
        }
    }
		break;
	case MSG_BOND:
		break;
    
#if CFG_PRF_HOGPD 
    case MSG_HOGPD_NTF:
    {
#ifdef CFG_PROJ_RCU
//        PRINTD(DBG_TRACE, "msg hogpd ntf...\r\n");
        msg_hogpd_ntf_t *p = (msg_hogpd_ntf_t *)p_msg;
        msrcuBleHidReport_t report = {0};
#if MSRCU_MOTION_ENABLE             
        if(p->instance == HID_MOUSE_INSTANCE)
        {
            if(!userMotionIsStop && !userMotionIsPause)
            {
                //send button
                if(p->data[MOUSE_HID_PKG_KEY_IDX] != MOUSE_BUTTON_NULL)
                {
                    report.conIndex = p->conIndex;
                    report.instance = p->instance;
                    report.length = p->length;
                    memcpy(report.data, p->data, p->length);
                    msrcuErr_t err = msrcu_dev_ble_hid_send2(&report);
//                    if(err)
//                        MSPRINT("msrcu_dev_ble_hid_send2 ERR:%d\r\n", err);
                    break;
                }
                
                //pause mouse when KEY_CODE_ENTER is pressed
//                msrcuKeySt st = KEY_RELEASED;
//                msrcu_app_key_state_get(KEY_CODE_ENTER, &st);
//                if(st == KEY_PRESSED)
//                    break;
                
                //send mouse
                msrcuMotionMouse_t mouse = {0};
                if(!msrcu_app_motion_get_data(NULL, NULL, &mouse))
                {    
//                    MSPRINT("x %d,y %d\r\n", mouse.x, mouse.y);
                    if(mouse.x || mouse.y)//mouse move
                    {
//                        MSPRINT("x %d,y %d\r\n", mouse.x, mouse.y);
                        report.conIndex = p->conIndex;
                        report.instance = p->instance;
                        report.length = p->length;
                        memcpy(report.data, p->data, p->length); 
                        report.data[MOUSE_HID_PKG_KEY_IDX] = p->data[MOUSE_HID_PKG_KEY_IDX];
                        report.data[MOUSE_HID_PKG_X_IDX] = mouse.x;
                        report.data[MOUSE_HID_PKG_Y_IDX] = mouse.y; 
                        
                        msrcuErr_t err = msrcu_dev_ble_hid_send2(&report);
//                        if(err)
//                            MSPRINT("msrcu_dev_ble_hid_send2 ERR:%d\r\n", err);
                    }
                }
                else
                    MSPRINT("Motion get data error.\r\n");
            }
        }
        else
#endif       
        {        
            report.conIndex = p->conIndex;
            report.instance = p->instance;
            report.length = p->length;
            memcpy(report.data, p->data, p->length);             
            
            msrcuErr_t err = msrcu_dev_ble_hid_send2(&report);
//            if(err)
//                MSPRINT("msrcu_dev_ble_hid_send2 ERR:%d\r\n", err);
        }
#endif        
    }  
    break;
#endif 
#ifdef CFG_PROJ_TPPS
    case MSG_TPPS_NTF:
    {
        //PRINTD(DBG_TRACE, "msg tpps ntf...\r\n");
        msg_tpps_ntf_t *p = (msg_tpps_ntf_t *)p_msg;
        tpps_send_notify(p->conIndex, p->data, p->length);
    }
    break;
#endif
	default:
		break;
	}
}
