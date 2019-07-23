#include "in_config.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include ".\ble\inb_api.h"
#include "prf_tpps.h"


uint16_t g_TppPrimarySvc_shl = 0;
uint16_t g_TppSecondarySvc_shl = 0;

const inb_gatt_svc_desc_t g_TppPrimarySvc =
{
	.start_hdl = 0,
	.perm = 0,//(0x02 << INB_ATT_PERM_POS_SVC_AUTH) & INB_ATT_PERM_MASK_SVC_AUTH,
	.uuid = "\xFF\xFF",
	.nb_att = TPPS_IDX_NB,
};

const inb_gatt_svc_desc_t g_TppSecondarySvc =
{
	.start_hdl = 0,
	.perm = INB_ATT_PERM_MASK_SVC_SECONDARY,
	.uuid = "\x00\xB0",
	.nb_att = 2,
};

const inb_gatt_att_desc_t g_TppPrimaryAtts[7] =
{
	[TPPS_IDX_SVC] = 
	{
		.uuid = "\x02\x28",//INB_ATT_DECL_INCLUDE,
		.perm = INB_ATT_PERM_MASK_RD,
		//For Include Declaration, it contains the attribute value, which is include service start handler
		//Other two info will be add by att in rsp pdu
		//End Group Handle = include service end handler
		//Service UUID = get by service start handler
		.max_len = 0,
		.ext_perm = 0,
	},
	[TPPS_IDX_RX_DATA_CHAR] = 
	{
		.uuid = "\x03\x28",//INB_ATT_DECL_CHARACTERISTIC,
		.perm = INB_ATT_PERM_MASK_RD,
		//For Characteristic Declaration, it contains attribute value, which is characteristic UUID.
		//Other two info will be add by att in rsp pdu
		//Characteristic Properties = perm & INB_ATT_PERM_MASK_PROP
		//Characteristic Value Attribute Handle = its own handle + 1
		//.max_len = 0xAA00,
		//It's not used as 
		.max_len = 0,
		.ext_perm = 0,
	},
	[TPPS_IDX_RX_DATA_VAL] = 
	{
		.uuid = "\x01\xFF",
		.perm = INB_ATT_PERM_MASK_WRITE_COMMAND | INB_ATT_PERM_MASK_WRITE_REQ,
		//it is max length of value.
		//If ext_perm has RI set, read request indication will be triggered to get value, 
		//or else, value present in database, put data at end of memory block. Attm will allocate memory 
		//for having value in "service memory block". Ensure that size can be allocated into a 16 bits boundary ??
		.max_len = 20,
		.ext_perm = INB_ATT_PERM_MASK_RI,
	},
	[TPPS_IDX_RX_DATA_USER_DESP] = 
	{
		.uuid = "\x01\x29",
		.perm = INB_ATT_PERM_MASK_RD,
		//For Characteristic Extended Properties, this field contains 2 byte value
		.max_len = 0,
		.ext_perm = 0,
	},
	[TPPS_IDX_VAL_CHAR] = 
	{
		.uuid = "\x03\x28",
		.perm = INB_ATT_PERM_MASK_RD,
		//Same as "Characteristic Value Declaration"
		.max_len = 24,
		.ext_perm = INB_ATT_PERM_MASK_RI,
	},
	[TPPS_IDX_VAL] = 
	{
		.uuid = "\x02\xFF",
		.perm = INB_ATT_PERM_MASK_NTF,
		// Not used Client Characteristic Configuration and Server Characteristic Configuration,
		// this field is not used.
		// Value is get always by RI. 
		.max_len = 255,
		.ext_perm = 0,
	},
	[TPPS_IDX_VAL_NTF_CFG] = 
	{
		.uuid = "\x02\x29",
		.perm = INB_ATT_PERM_MASK_RD | INB_ATT_PERM_MASK_WRITE_REQ,
		// Not used Client Characteristic Configuration and Server Characteristic Configuration,
		// this field is not used.
		// Value is get always by RI. Same as "DESC_CLIENT_CHAR_CFG"
		.max_len = 255,
		.ext_perm = 0,
	},
};

const inb_gatt_att_desc_t g_TppSecondaryAtts[] =
{
	[0] = 
	{
		.uuid = "\x03\x28",//INB_ATT_DECL_CHARACTERISTIC,
		.perm = INB_ATT_PERM_MASK_RD,
		//For Characteristic Declaration, it contains attribute value, which is characteristic UUID.
		//Other two info will be add by att in rsp pdu
		//Characteristic Properties = perm & INB_ATT_PERM_MASK_PROP
		//Characteristic Value Attribute Handle = its own handle + 1
		//.max_len = 0xAA00,
		//It's not used as 
		.max_len = 0,
		.ext_perm = 0,
	},
	[1] = 
	{
		.uuid = "\x00\xBA",//Need to be changed in different services
		.perm = INB_ATT_PERM_MASK_RD | INB_ATT_PERM_MASK_WRITE_COMMAND | INB_ATT_PERM_MASK_WRITE_REQ,
		//it is max length of value.
		//If ext_perm has RI set, read request indication will be triggered to get value, 
		//or else, value present in database, put data at end of memory block. Attm will allocate memory 
		//for having value in "service memory block". Ensure that size can be allocated into a 16 bits boundary ??
		.max_len = 24,
		.ext_perm = INB_ATT_PERM_MASK_RI,
	},
};

int tpps_add_svc(void)
{
	int ret;
//	uint8_t value[2+2+INB_UUID_16_LEN];
	inb_gatt_svc_desc_t *p_svc;
			
	p_svc = (inb_gatt_svc_desc_t*)malloc(sizeof(inb_gatt_svc_desc_t)+g_TppSecondarySvc.nb_att*sizeof(inb_gatt_att_desc_t));
	memcpy(p_svc, &g_TppSecondarySvc, sizeof(inb_gatt_svc_desc_t));
	memcpy(p_svc->atts, &g_TppSecondaryAtts[0], g_TppSecondarySvc.nb_att*sizeof(inb_gatt_att_desc_t));
	ret = inb_gatt_add_svc(p_svc, &g_TppSecondarySvc_shl);
	if(p_svc) free(p_svc);
	if (ret) return -1;
//	printf("start handle for 'Secondary Service' is 0x%02X\r\n", g_TppSecondarySvc_shl);
			
	p_svc = (inb_gatt_svc_desc_t*)malloc(sizeof(inb_gatt_svc_desc_t)+g_TppPrimarySvc.nb_att*sizeof(inb_gatt_att_desc_t));
	memcpy(p_svc, &g_TppPrimarySvc, sizeof(inb_gatt_svc_desc_t));
	memcpy(p_svc->atts, &g_TppPrimaryAtts[0], 7*sizeof(inb_gatt_att_desc_t));	
	ret = inb_gatt_add_svc(p_svc, &g_TppPrimarySvc_shl);
	if(p_svc) free(p_svc);
	if (ret) return -1;
	//printf("start handle for 'Primary Service' is 0x%02X\r\n", g_TppPrimarySvc_shl);
	
#if (CFG_DBG_IF_UART==1) && (WITH_CONSOLE==1)
	register_console_cmds((console_cmd_t*)g_testSvc_cmds, sizeof(g_testSvc_cmds)/sizeof(console_cmd_t), handle_testSvc_cmd);
#endif
	return ret;
}

int tpps_send_notify(uint8_t *buffer , uint8_t len)
{
    uint8_t res;
	uint16_t handle = g_TppPrimarySvc_shl + TPPS_IDX_VAL_NTF_CFG;
	
	//printf("tpps_notify_send():handle= %d \r\n", handle);
	
	res = inb_gatt_send_ntf(0,handle,len,buffer);
    if(res)
        PRINTD(DBG_TRACE, "TPPS notity send error: 0x%X", res);
    else
    {        
        PRINTD(DBG_TRACE, "TPPS send, length=%d, data: 0x", len);
//        for(int i = 0; i < len; i++)
//            PRINTD(DBG_TRACE, " %02X", buffer[i]);
        PRINTD(DBG_TRACE, " %02X...", buffer[0]);
        PRINTD(DBG_TRACE, "\r\n");
    }
    
    return 0;
}

int tpps_receive_write(uint8_t *buffer , uint8_t len)
{
    PRINTD(DBG_TRACE, "TPPS receive, length=%d, data: 0x", len);
    for(int i = 0; i < len; i++)
        PRINTD(DBG_TRACE, " %02X", buffer[i]);
    PRINTD(DBG_TRACE, "\r\n");
    
    return 0;
}

