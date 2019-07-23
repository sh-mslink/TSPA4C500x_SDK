#include ".\ble\inb_api.h"

#if (CFG_DBG_IF_UART==1) && (WITH_CONSOLE==1)
#include "..\inc\console.h"
#include "..\inc\test_svc.h"
#include "..\inc\ble_test.h"

extern inb_set_dev_config_t g_BleCfg;
extern struct _l2cc_test_env_ g_L2ccTestEnv;

uint16_t g_mtu;

static __INLINE void DUMP_HEX_DATA(uint8_t *p_val, uint16_t length)
{
	printf("Total read %d bytes:  ", length);
	for (int i=0;i<length;i++)
		printf("0x%02X ", p_val[i]);
	printf("\r\n");
}
enum
{
	disconnect = GAP_EVT_CONN_PHY_UPD+1,

	start_actv,

	register_lepsm,
	conn_param_update,
	
	gap_cmd_max,
};
enum
{
	exec_mtu = GATT_EVT_SDP_SVC+1,

	sdp_all_svc,
	sdp_by_srvUUID,
	sdp_cancel,

	disc_all_prim_svc,
	disc_prim_svc_by_srvUUID,
	relat_disc,
	disc_all_char_of_svc,
	disc_char_by_charUUID,
	disc_all_char_desc,

	read,
	read_long,
	read_by_uuid,
	read_multi,

	write,                        
	write_without_rsp,
	signed_write_without_rsp,
	write_long,
	write_reliable,

	reg_ind_ntf_event,

	send_ind,
	send_ntf,
	send_svc_changed,

	//GATTM interface
	gatt_add_svc,
	gatt_get_svc_perm,
	gatt_set_svc_perm,
	gatt_get_att_perm,
	gatt_set_att_perm,
	gatt_get_att_value,
	gatt_set_att_value,
	
	gatt_cmd_max,
};
enum
{
	lecb_connect  = L2CAP_EVT_LECB_SDU_RECV+1,
	lecb_disconnect,
	lecb_sdu_send,

	lecb_cmd_max,
};


const console_cmd_t g_gap_cmds[] = {
	{"disconnect",                              0,					disconnect,				"Usage: %s \r\n" },
	{"start_actv",                               1,					start_actv,				"Usage: %s <0-adv/1-/2-init> \r\n"},
	{"register_lepsm",                        1,					register_lepsm,			"Usage: %s <le_psm>\r\n"},
	{"conn_param_update",                0,					conn_param_update,		"Usage: %s \r\n"},
};
const console_cmd_t g_gatt_cmds[] = {

	{"exec_mtu",                                 0, 				exec_mtu,				"Usage: %s \r\n" },

	{"sdp_all_svc",                               0,					sdp_all_svc,				"Usage: %s \r\n"},
	{"sdp_by_srvUUID",                       -2,/*2+<cnt>-1*/	sdp_by_srvUUID,			"Usage: %s <cnt> <uuid_byte_1> ... <uuid_byte_[cnt]> \r\n"},
	{"sdp_cancel",				    0,					sdp_cancel,				"Usage: %s \r\n"},
	
	{"disc_all_prim_svc",                      0,					disc_all_prim_svc,			"Usage: %s  \r\n"},
	{"disc_prim_svc_by_srvUUID",      -2,/*2+<cnt>-1*/	disc_prim_svc_by_srvUUID,	"Usage: %s <cnt> <uuid_byte_1> ... <uuid_byte_[cnt]> \r\n"},
	{"relat_disc",                                 2,					relat_disc,				"Usage: %s <start_hdl> <end_hdl> \r\n"},
	{"disc_all_char_of_svc",	                 2,					disc_all_char_of_svc,		"Usage: %s <start_hdl> <end_hdl> \r\n"},
	{"disc_char_by_charUUID",            -4/*4+<cnt>-1*/,	disc_char_by_charUUID,	"Usage: %s <cnt> <start_hdl> <end_hdl> <uuid_byte_1> ... <uuid_byte_[cnt]> \r\n"},
	{"disc_all_char_desc",                    2,					disc_all_char_desc,			"Usage: %s <start_hdl> <end_hdl> \r\n"},

	{"read",                                         1,					read,					"Usage: %s <handle> \r\n"},
	{"read_long",                                 2,					read_long,				"Usage: %s <handle> <offset> \r\n"},
	{"read_by_uuid",                          -4/*4+<cnt>-1*/,	read_by_uuid,				"Usage: %s <cnt> <start_hdl> <end_hdl> <uuid_byte_1> ... <uuid_byte_[cnt]> \r\n"},
	{"read_multi",	                              -2/*2+<cnt>-1*/,	read_multi,				"Usage: %s <cnt> <handle_1> <len_1>... <handle_[cnt/2]> <len_[cnt/2]> \r\n"},

	{"write_without_rsp",                      3,					write_without_rsp,			"Usage: %s <cnt> <handle> <offset> \r\n"},
	{"signed_write_without_rsp",	           3,					signed_write_without_rsp,	"Usage: %s <cnt> <handle> <offset> \r\n"},
	{"write",                                        3,					write,					"Usage: %s <cnt> <handle> <offset> \r\n"},
	{"write_long",                                3,					write_long,				"Usage: %s <cnt> <handle> <offset> \r\n"},
	{"write_reliable",                            3,					write_reliable,				"Usage: %s <cnt> <handle> <offset>\r\n"},

	{"reg_ind_ntf_event",                     3,					reg_ind_ntf_event,			"Usage: %s <1-register/0-unregister> <start_hdl> <end_hdl> \r\n"},

	{"send_ind",                                  1,					send_ind,					"Usage: %s <handle> \r\n"},
	{"send_ntf",                                  1,					send_ntf,					"Usage: %s <handle> \r\n"},
	{"send_svc_changed",                   2,					send_svc_changed, 		"Usage: %s <start_hdl> <end_hdl> \r\n"},

	//GATTM cmds
	{"gatt_add_svc",                           0,					gatt_add_svc,				"Usage: %s \r\n"},
	{"gatt_get_svc_perm",                  1,					gatt_get_svc_perm,		"Usage: %s <start_hdl> \r\n"},
	{"gatt_set_svc_perm",                  2,					gatt_set_svc_perm,		"Usage: %s <start_hdl> <perm> \r\n"},
	{"gatt_get_att_perm",                   1,					gatt_get_att_perm,			"Usage: %s <handle> \r\n"},
	{"gatt_set_att_perm",                   3,					gatt_set_att_perm,			"Usage: %s <handle> <perm> <ext_perm> \r\n"},
	{"gatt_get_att_value",                   1,					gatt_get_att_value,			"Usage: %s <handle> \r\n"},
	{"gatt_set_att_value",                   2,					gatt_set_att_value,			"Usage: %s <cnt> <handle> \r\n"},
};
const console_cmd_t g_l2cc_cmds[] = {
	{"lecb_connect",                           1,					lecb_connect, 				"Usage: %s <psm>\r\n"},
	{"lecb_disconnect",	                      0,					lecb_disconnect,			"Usage: %s \r\n"},
	{"lecb_sdu_send",                        1,					lecb_sdu_send,			"Usage: %s <cnt> \r\n"},
};


const uint8_t g_values[30] = {
	0x01, 0x00, 0x02, 0x00, 0x05, 0x06, 0x07, 0x08, 0x09,
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99,
	0x01, 0x23, 0x45, 0x67, 0x89, 0xff, 0xff, 0xff, 0xff
};

int handle_gap_cmd(uint16_t eid, void *pv)
{
	uint16_t *p_param = (uint16_t*)pv;
	int ret = 0;
	uint16_t cnt;

	switch(eid)
	{
	case disconnect:
		{
			ret = inb_conn_disconnect(*p_param, 0);
		}
		break;
	case start_actv:
		{//Usage: %s <0-adv/1-/2-init>
			if (*p_param == 0){
				ret = start_adv();
			}else if (*p_param == 1){
				create_scan();
				start_scan();
			}else if (*p_param == 2){
				int actv_idx;
				if (create_init(&actv_idx))
					return -1;
				if (start_init(actv_idx))
					return -1;				
			}
		}
		break;
	case conn_param_update:
		{//Usage: %s 
			extern uint16_t g_conn_latency;
			extern uint16_t g_conn_interval;
			extern uint16_t g_conn_sup_timeout;

			inb_conn_param_update_t *p_upd = (inb_conn_param_update_t*)malloc(sizeof(inb_conn_param_update_t));

			p_upd->latency = g_conn_latency+1;
			p_upd->ce_len_max = 512;
			p_upd->ce_len_min = 0;
			p_upd->intv_max = 80;
			p_upd->intv_min = 80;
			p_upd->time_out = g_conn_sup_timeout;
			
			ret = inb_conn_param_update(*p_param, p_upd);
		}
		break;
	case register_lepsm:
		{//Usage: %s <lepsm>
			inb_lepsm_param_t * p_psm = (inb_lepsm_param_t *)malloc(sizeof(inb_lepsm_param_t));
			p_psm->lepsm = *p_param;
			g_L2ccTestEnv.local.le_psm = *p_param;
			p_psm->sec_lvl = 0;//NO_AUTH
			p_psm->full_key_size = false;
			ret = inb_register_lepsm(p_psm);
			free(p_psm);
		}
		break;
	default:
		return 0;
	}

	if (ret){
		printf("exec error: 0x%x\r\n", ret);
		return -1;
	}

	return 1;
}

int handle_gatt_cmd(uint16_t eid, void *pv)
{
	uint16_t *p_param = (uint16_t*)pv;
	int ret = 0;
	inb_gatt_read_t* p_read=NULL;
	inb_gatt_read_value_t readVal;
	inb_gatt_read_rsp_t *p_read_rsp=NULL;
	uint16_t cnt;

	switch(eid)
	{
	case exec_mtu:
		{
			ret = inb_gatt_exc_mtu(*p_param, &g_mtu);
			if (!ret)
				printf( "MTU = %d\r\n", g_mtu);
		}
		break;
	case sdp_all_svc:
		{//Usage: %s
			inb_gatt_sdp_t * p_sdp = (inb_gatt_sdp_t*)malloc(sizeof(inb_gatt_sdp_t));
			p_sdp->start_hdl = 1;
			p_sdp->end_hdl = 0xffff;
			ret = inb_gatt_sdp(*p_param, GATT_SDP_DISC_SVC_ALL, p_sdp);
			free(p_sdp);
		}
		break;
	case sdp_by_srvUUID:
		{//Usage: %s <cnt> hdl> <end_hdl> <uuid_byte_1> ... <uuid_byte_[len]>
			cnt = *p_param++;
			inb_gatt_sdp_t * p_sdp = (inb_gatt_sdp_t*)malloc(sizeof(inb_gatt_sdp_t) + cnt);
			p_sdp->start_hdl = 1;
			p_sdp->end_hdl = 0xffff;
			p_sdp->uuid_len = cnt;
			for (int i=0;i<cnt;i++)
				p_sdp->uuid[i] = (uint8_t)(*p_param++);
			ret = inb_gatt_sdp(*p_param, GATT_SDP_DISC_SVC, p_sdp);
			free(p_sdp);
		}
		break;
	case sdp_cancel:
		{//Usage: %s
			inb_gatt_sdp_t * p_sdp = (inb_gatt_sdp_t*)malloc(sizeof(inb_gatt_sdp_t));
			p_sdp->start_hdl = 1;
			p_sdp->end_hdl = 0xffff;
			ret = inb_gatt_sdp(*p_param, GATT_SDP_DISC_CANCEL, p_sdp);
		}
		break;
	case disc_all_prim_svc:
		{//Usage: %s 
			inb_gatt_disc_t * p_disc = (inb_gatt_disc_t*)malloc(sizeof(inb_gatt_disc_t));
			p_disc->start_hdl = 1;
			p_disc->end_hdl = 0xffff;
			ret = inb_gatt_discovery(*p_param, GATT_DISC_ALL_SVC, p_disc);
			free(p_disc);
		}		
		break;
	case disc_prim_svc_by_srvUUID:
		{//Usage: %s <cnt> <uuid_byte_1> ... <uuid_byte_[cnt]>
			cnt = *p_param++;
			inb_gatt_disc_t * p_disc = (inb_gatt_disc_t*)malloc(sizeof(inb_gatt_disc_t) + cnt);
			p_disc->start_hdl = 1;
			p_disc->end_hdl = 0xffff;
			p_disc->uuid_len = cnt;
			for (int i=0;i<cnt;i++)
				p_disc->uuid[i] = (uint8_t)(*p_param++);
			ret = inb_gatt_discovery(*p_param, GATT_DISC_BY_UUID_SVC, p_disc);
			free(p_disc);
		}
		break;
	case relat_disc:
		{//Usage: %s <start_hdl> <end_hdl>
			inb_gatt_disc_t * p_disc = (inb_gatt_disc_t*)malloc(sizeof(inb_gatt_disc_t));
			p_disc->start_hdl = *p_param++;
			p_disc->end_hdl = *p_param++;
			ret = inb_gatt_discovery(*p_param, GATT_DISC_INCLUDED_SVC, p_disc);
			free(p_disc);
		}
		break;
	case disc_all_char_of_svc:
		{//Usage: %s <start_hdl> <end_hdl>
			inb_gatt_disc_t * p_disc = (inb_gatt_disc_t*)malloc(sizeof(inb_gatt_disc_t));
			p_disc->start_hdl = *p_param++;
			p_disc->end_hdl = *p_param++;
			ret = inb_gatt_discovery(*p_param, GATT_DISC_ALL_CHAR, p_disc);
			free(p_disc);
		}
		break;
	case disc_char_by_charUUID:
		{//Usage: %s <cnt> <start_hdl> <end_hdl> <uuid_byte_1> ... <uuid_byte_[cnt]>
			cnt = *p_param++;
			inb_gatt_disc_t * p_disc = (inb_gatt_disc_t*)malloc(sizeof(inb_gatt_disc_t) + cnt);
			p_disc->start_hdl = *p_param++;
			p_disc->end_hdl = *p_param++;
			p_disc->uuid_len = cnt;
			for (int i=0;i<cnt;i++)
				p_disc->uuid[i] = (uint8_t)(*p_param++);
			ret = inb_gatt_discovery(*p_param, GATT_DISC_BY_UUID_CHAR, p_disc);
			free(p_disc);
		}
		break;
	case disc_all_char_desc:
		{//Usage: %s <start_hdl> <end_hdl> \r\n
			inb_gatt_disc_t * p_disc = (inb_gatt_disc_t*)malloc(sizeof(inb_gatt_disc_t));
			p_disc->start_hdl = *p_param++;
			p_disc->end_hdl = *p_param++;
			ret = inb_gatt_discovery(*p_param, GATT_DISC_DESC_CHAR, p_disc);
			free(p_disc);		
		}
		break;
	case read:
		{//Usage: %s <handle>
			p_read = (inb_gatt_read_t*)malloc(sizeof(inb_gatt_read_t));
			p_read->req.simple.handle = *p_param++;
			p_read->req.simple.length = 0;
			p_read->req.simple.offset = 0;
				
			readVal.nb = 1;
			readVal.pRsp = (inb_gatt_read_rsp_t*)malloc(sizeof(inb_gatt_read_rsp_t)+g_mtu);
			p_read_rsp = readVal.pRsp;
			p_read_rsp->offset = p_read->req.simple.offset;
			//Before read, it is the length of buffer allocated. After read, it means length of data actually read
			p_read_rsp->length = g_mtu;
				
			ret = inb_gatt_read(*p_param, GATT_READ, p_read, &readVal);
			DUMP_HEX_DATA(p_read_rsp->value, p_read_rsp->length);
			free(p_read);
		}
		break;
	case read_long:
		{//Usage: %s <handle> <offset> 
			p_read = (inb_gatt_read_t*)malloc(sizeof(inb_gatt_read_t));
			p_read->req.simple.handle = *p_param++;
			p_read->req.simple.offset = *p_param++;
			
			readVal.nb = 1;
			readVal.pRsp = (inb_gatt_read_rsp_t*)malloc(sizeof(inb_gatt_read_rsp_t)+g_mtu);
			p_read_rsp = readVal.pRsp;
			do {
				p_read_rsp->offset = p_read->req.simple.offset;
				//??If p_read_rsp->length = g_mtu, it read less?? need more test
				p_read_rsp->length = g_mtu-1;
				ret = inb_gatt_read(*p_param, GATT_READ_LONG, p_read, &readVal);
				if (!ret)
					DUMP_HEX_DATA(p_read_rsp->value, p_read_rsp->length);	
				p_read->req.simple.offset += p_read_rsp->length;
			}while(!ret && p_read_rsp->length != 0);
			free(readVal.pRsp);
		}
		break;
	case read_by_uuid:
		{//Usage: %s <cnt> <start_hdl> <end_hdl> <uuid_byte_1> ... <uuid_byte_[cnt]>
			cnt = *p_param++;
			p_read = (inb_gatt_read_t*)malloc(sizeof(inb_gatt_read_t)+cnt);
			p_read->req.by_uuid.uuid_len = cnt;
			p_read->req.by_uuid.start_hdl = *p_param++;
			p_read->req.by_uuid.end_hdl = *p_param++;
			for (int i=0;i<cnt;i++)
				p_read->req.by_uuid.uuid[i] = *p_param++;

			readVal.nb = 1;
			readVal.pRsp = (inb_gatt_read_rsp_t*)malloc(sizeof(inb_gatt_read_rsp_t)+g_mtu);
			p_read_rsp = readVal.pRsp;
			p_read_rsp->offset = 0;
			p_read_rsp->length = g_mtu;
			ret = inb_gatt_read(*p_param, GATT_READ_BY_UUID, p_read, &readVal);
			if (!ret)
				DUMP_HEX_DATA(p_read_rsp->value, p_read_rsp->length);
			free(p_read);
			free(readVal.pRsp);
		}
		break;
	case read_multi:
		{//Usage: %s <cnt> <handle_1> <len_1>... <handle_[cnt/2]> <len_[cnt/2]>
			cnt = *p_param++;
			p_read = (inb_gatt_read_t*)malloc(sizeof(inb_gatt_read_t)+(cnt/2)*sizeof(inb_gatt_read_multiple_t));
			p_read->nb = cnt/2;
			for (int i=0;i<p_read->nb;i++){
				p_read->req.multiple[i].handle = *p_param++;
				p_read->req.multiple[i].len = *p_param++;
			}

			readVal.nb = p_read->nb;
			readVal.pRsp = (inb_gatt_read_rsp_t*)malloc(readVal.nb*(sizeof(inb_gatt_read_rsp_t)+g_mtu));
			p_read_rsp = readVal.pRsp;
			uint8_t *p = (uint8_t*)p_read_rsp;
			for (int i=0;i<p_read->nb;i++){
				inb_gatt_read_rsp_t* rsp = (inb_gatt_read_rsp_t*)p;
				rsp->offset = 0;
				rsp->length = g_mtu;
				p += sizeof(inb_gatt_read_rsp_t)+g_mtu;
			}
			ret = inb_gatt_read(*p_param, GATT_READ_MULTIPLE, p_read, &readVal);
			if (!ret){
				uint8_t *p = (uint8_t*)p_read_rsp;
				for (int i=0;i<p_read->nb;i++){
					inb_gatt_read_rsp_t* rsp = (inb_gatt_read_rsp_t*)p;

					DUMP_HEX_DATA(rsp->value, rsp->length); 
					
					p += sizeof(inb_gatt_read_rsp_t)+g_mtu;
				}
			}
			free(p_read);
			free(readVal.pRsp);
		}
		break;
	case write:
	case write_without_rsp:
	case signed_write_without_rsp:
	case write_long:
	case write_reliable:
		{//Usage: %s <cnt> <handle> <offset>
			cnt = *p_param++;
			inb_gatt_write_t * p_write = (inb_gatt_write_t*)malloc(sizeof(inb_gatt_write_t)+cnt);

			if (eid == write_reliable)
				p_write->auto_execute = false;
			else
				p_write->auto_execute = true;
			p_write->handle = *p_param++;
			p_write->offset = *p_param++;
			p_write->length = cnt;
			memcpy(p_write->value, g_values, cnt);

			if (eid == write_long || eid == write_reliable)
				ret = inb_gatt_write(*p_param,  GATT_WRITE, p_write);
			else
				ret = inb_gatt_write(*p_param,  GATT_WRITE_NO_RESPONSE+eid-write_without_rsp, p_write);
			free(p_write);

			if (eid == write_reliable)
				inb_gatt_excute_write(*p_param, !ret);	
		}
		break;
	case reg_ind_ntf_event:
		{//Usage: %s <1-register/0-unregister> <start_hdl> <end_hdl>
			ret = inb_gatt_register_ind_ntf_event(*(p_param+3), (bool)*p_param, *(p_param+1), *(p_param+2));
		}
		break;
	case send_ind:
		{//Usage: %s <handle>
			uint16_t *pData = (uint16_t*)testSvc_get_att_value(*p_param);
			if (pData){
				ret = inb_gatt_send_ind(*(p_param+1), *(p_param), *pData, (uint8_t*)(pData+1));
			}
		}
		break;
	case send_ntf:
		{//Usage: %s <handle>
			uint16_t *pData = (uint16_t*)testSvc_get_att_value(*p_param);
			if (pData){
				ret = inb_gatt_send_ntf(*(p_param+1), *p_param, *pData, (uint8_t*)(pData+1));
			}
		}
		break;
	case send_svc_changed:
		{//Usage: %s <start_hdl> <end_hdl>
			ret = inb_gatt_send_svc_changed(*(p_param+2), *(p_param), *(p_param+1));
		}
		break;
	case gatt_add_svc:
		{//Usage: %s 
			ret = testSvc_add_svc();
		}
		break;
	case gatt_get_svc_perm:
		{//Usage: %s <start_hdl>
			uint8_t perm;
			inb_gatt_get_svc_perm(*p_param, &perm);
			if (!ret)
				printf("Permission is 0x%02X\r\n", perm);
		}
		break;
	case gatt_set_svc_perm:
		{//Usage: %s <start_hdl> <perm>
			ret = inb_gatt_set_svc_perm(*p_param, *(p_param+1));
		}
		break;
	case gatt_get_att_perm:
		{//Usage: %s <handle>
			inb_att_perm_t  perm;
			ret = inb_gatt_get_att_perm(*p_param, &perm );
			if (!ret){
				printf("Permission is 0x%02X\r\n", perm.perm);
				printf("Ext Permission is 0x%02X\r\n", perm.ext_perm);
			}
		}
		break;
	case gatt_set_att_perm:
		{//Usage: %s <handle> <perm> <ext_perm>
			ret = inb_gatt_set_att_perm(*p_param, *(p_param+1), *(p_param+2));
		}
		break;
	case gatt_get_att_value:
		{//Usage: %s <handle>
			inb_att_val_t * p_att_val = (inb_att_val_t*)malloc(sizeof(inb_att_val_t)+g_mtu-1);
			p_att_val->handle = *p_param++;
			p_att_val->length = g_mtu-1;
			ret = inb_gatt_get_att_value(p_att_val->handle, p_att_val);
			if (!ret)
				DUMP_HEX_DATA(p_att_val->value, p_att_val->length);
			free(p_att_val);
		}
		break;
	case gatt_set_att_value:
		{//Usage: %s <cnt> <handle>
			cnt = *p_param++;
			ret = inb_gatt_set_att_value(*p_param, cnt, (uint8_t*)g_values);
		}
		break;
	default:
		return 0;
	}

	if (ret){
		printf("exec error: 0x%x\r\n", ret);
		return -1;
	}

	return 1;
}

int handle_l2cc_cmd(uint16_t eid, void *pv)
{
	uint16_t *p_param = (uint16_t*)pv;
	int ret = 0;
	uint16_t cnt;

	switch(eid)
	{
	case lecb_connect:
		{//Usage: %s <psm>
			inb_lecb_connect_ind_t *p_ind = (inb_lecb_connect_ind_t *)malloc(sizeof(inb_lecb_connect_ind_t));
			inb_lecb_connect_t *p_LecbConn = (inb_lecb_connect_t*)malloc(sizeof(inb_lecb_connect_t));
			p_LecbConn->le_psm = *p_param++;
			p_LecbConn->local_mtu = g_BleCfg.max_mtu;
			p_LecbConn->local_cid = 0;
			p_LecbConn->local_credit = floor((g_BleCfg.max_mtu+g_BleCfg.max_mps+1)/g_BleCfg.max_mps) + 1;
			p_LecbConn->local_mps = g_BleCfg.max_mps;
			ret = inb_lecb_connect(*p_param, p_LecbConn, p_ind);
			if (!ret)
			{
				g_L2ccTestEnv.local.cid = p_ind->local_cid;
				g_L2ccTestEnv.local.credit = p_LecbConn->local_credit;
				g_L2ccTestEnv.local.le_psm = p_LecbConn->le_psm;
				g_L2ccTestEnv.local.mps = p_LecbConn->local_mps;
				g_L2ccTestEnv.local.mtu = p_LecbConn->local_mtu;
				g_L2ccTestEnv.peer.credit = p_ind->peer_credit;
				g_L2ccTestEnv.peer.le_psm = p_ind->le_psm;
				g_L2ccTestEnv.peer.mps = p_ind->peer_mps;
				g_L2ccTestEnv.peer.mtu = p_ind->peer_mtu;
				PRINTD(DBG_TRACE, "\t\t local psm: 0x%02X\r\n", p_ind->le_psm);
				PRINTD(DBG_TRACE, "\t\t local cid: %d\r\n", p_ind->local_cid);
				PRINTD(DBG_TRACE, "\t\t peer credit: %d\r\n", p_ind->peer_credit);
				PRINTD(DBG_TRACE, "\t\t peer mps: %d\r\n", p_ind->peer_mps);
				PRINTD(DBG_TRACE, "\t\t peer mtu: %d\r\n", p_ind->peer_mtu);
				PRINTD(DBG_TRACE, "\t\t status: 0x%02X\r\n", p_ind->status);
			}
			free(p_ind);
			free(p_LecbConn);
		}
		break;
	case lecb_disconnect:
		{//Usage: %s 
			ret  = inb_lecb_disconnect(*p_param, g_L2ccTestEnv.local.cid);
		}
		break;
	case lecb_sdu_send:
		{//Usage: %s <cnt>
			ret = inb_lecb_sdu_send(*(p_param+1), g_L2ccTestEnv.local.cid, (uint8_t*)g_values, *(p_param));
		}
		break;
	default:
		return 0;
	}

	if (ret){
		printf("exec error: 0x%x\r\n", ret);
		return -1;
	}

	return 1;
}

int gap_register_console_cmds(void)
{
	return register_console_cmds((console_cmd_t*)g_gap_cmds, sizeof(g_gap_cmds)/sizeof(console_cmd_t), handle_gap_cmd);
}
int gatt_register_console_cmds(void)
{
	return register_console_cmds((console_cmd_t*)g_gatt_cmds, sizeof(g_gatt_cmds)/sizeof(console_cmd_t), handle_gatt_cmd);
}
int l2cap_register_console_cmds(void)
{
	return register_console_cmds((console_cmd_t *)g_l2cc_cmds, sizeof(g_l2cc_cmds)/sizeof(console_cmd_t), handle_l2cc_cmd);
}


#endif
