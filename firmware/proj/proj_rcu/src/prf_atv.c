#include "in_config.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include ".\ble\inb_api.h"
#include "prf_atv.h"
#include "prf_atv_task.h"


#if (MSRCU_VOICE_ENABLE && MSRCU_BLE_VOICE_ATV_ENABLE)

bool atvIsConnected = false;
uint16_t g_AtvPrimarySvc_shl = 0;
//uint16_t g_AtvSecondarySvc_shl = 0;

const inb_gatt_svc_desc_t g_AtvPrimarySvc =
{
	.start_hdl = 0,
	.prop = 0x40,//UUID 128bit
	.uuid = ATVV_SERVICE_UUID,
	.nb_att = ATVV_IDX_NB,
};

//const inb_gatt_svc_desc_t g_AtvSecondarySvc =
//{
//	.start_hdl = 0,
//	.perm = INB_ATT_PERM_MASK_SVC_SECONDARY,
//	.uuid = "\x00\xB0",
//	.nb_att = 2,
//};

const inb_gatt_att_desc_t g_AtvPrimaryAtts[ATVV_IDX_NB] =
{
	[ATVV_IDX_SVC] = 
	{
		//.uuid = "\x02\x28",//INB_ATT_DECL_INCLUDE,
		.uuid = "\x00\x28",//INB_ATT_DECL_PRIMARY_SERVICE,
		.prop = ATT_CHAR_PROP_READ,
		//For Include Declaration, it contains the attribute value, which is include service start handler
		//Other two info will be add by att in rsp pdu
		//End Group Handle = include service end handler
		//Service UUID = get by service start handler
		.max_len = 0,
		.ext_prop = 0x4000,//UUID 128bit
	},
	[ATVV_IDX_CHAR_TX] = 
	{
		.uuid = "\x03\x28",//INB_ATT_DECL_CHARACTERISTIC,
		.prop = ATT_CHAR_PROP_READ,
		//For Characteristic Declaration, it contains attribute value, which is characteristic UUID.
		//Other two info will be add by att in rsp pdu
		//Characteristic Properties = perm & INB_ATT_PERM_MASK_PROP
		//Characteristic Value Attribute Handle = its own handle + 1
		//.max_len = 0xAA00,
		//It's not used as 
		.max_len = 0,
		.ext_prop = 0,
	},
	[ATVV_IDX_CHAR_TX_VAL] = 
	{
		.uuid = ATVV_CHAR_TX_UUID,
		.prop = ATT_CHAR_PROP_WRITE,
		//it is max length of value.
		//If ext_perm has RI set, read request indication will be triggered to get value, 
		//or else, value present in database, put data at end of memory block. Attm will allocate memory 
		//for having value in "service memory block". Ensure that size can be allocated into a 16 bits boundary ??
		.max_len = 20,
		.ext_prop = 0xC000,//UUID 128bit | INB_ATT_PERM_MASK_RI,
	},
	[ATVV_IDX_CHAR_TX_USER_DESP] = 
	{
		.uuid = "\x01\x29",
		.prop = ATT_CHAR_PROP_READ,
		//For Characteristic Extended Properties, this field contains 2 byte value
		.max_len = 0,
		.ext_prop = 0,
	},
	[ATVV_IDX_CHAR_RX] = 
	{
		.uuid = "\x03\x28",
		.prop = ATT_CHAR_PROP_READ,
		//Same as "Characteristic Value Declaration"
		.max_len = 24,
		.ext_prop = ATT_EXT_PROP_RI,
	},
	[ATVV_IDX_CHAR_RX_VAL] = 
	{
		.uuid = ATVV_CHAR_RX_UUID,
		.prop = ATT_CHAR_PROP_NOTIFY,
		// Not used Client Characteristic Configuration and Server Characteristic Configuration,
		// this field is not used.
		// Value is get always by RI. 
		.max_len = 255,
		.ext_prop = 0x4000,//UUID 128bit,
	},
	[ATVV_IDX_CHAR_RX_CFG] = 
	{
		.uuid = "\x02\x29",
		.prop = ATT_CHAR_PROP_READ | ATT_CHAR_PROP_WRITE,
		// Not used Client Characteristic Configuration and Server Characteristic Configuration,
		// this field is not used.
		// Value is get always by RI. Same as "DESC_CLIENT_CHAR_CFG"
		.max_len = 255,
		.ext_prop = 0,
	},
	[ATVV_IDX_CHAR_CTL] = 
	{
		.uuid = "\x03\x28",
		.prop = ATT_CHAR_PROP_READ,
		//Same as "Characteristic Value Declaration"
		.max_len = 24,
		.ext_prop = ATT_EXT_PROP_RI,
	},
	[ATVV_IDX_CHAR_CTL_VAL] = 
	{
		.uuid = ATVV_CHAR_CTL_UUID,
		.prop = ATT_CHAR_PROP_NOTIFY,
		// Not used Client Characteristic Configuration and Server Characteristic Configuration,
		// this field is not used.
		// Value is get always by RI. 
		.max_len = 255,
		.ext_prop = 0x4000,//UUID 128bit,
	},
	[ATVV_IDX_CHAR_CTL_CFG] = 
	{
		.uuid = "\x02\x29",
		.prop = ATT_CHAR_PROP_READ | ATT_CHAR_PROP_WRITE,
		// Not used Client Characteristic Configuration and Server Characteristic Configuration,
		// this field is not used.
		// Value is get always by RI. Same as "DESC_CLIENT_CHAR_CFG"
		.max_len = 255,
		.ext_prop = 0,
	},
};

//const inb_gatt_att_desc_t g_AtvSecondaryAtts[] =
//{
//	[0] = 
//	{
//		.uuid = "\x03\x28",//INB_ATT_DECL_CHARACTERISTIC,
//		.perm = INB_ATT_PERM_MASK_RD,
//		//For Characteristic Declaration, it contains attribute value, which is characteristic UUID.
//		//Other two info will be add by att in rsp pdu
//		//Characteristic Properties = perm & INB_ATT_PERM_MASK_PROP
//		//Characteristic Value Attribute Handle = its own handle + 1
//		//.max_len = 0xAA00,
//		//It's not used as 
//		.max_len = 0,
//		.ext_perm = 0,
//	},
//	[1] = 
//	{
//		.uuid = "\x00\xBA",//Need to be changed in different services
//		.perm = INB_ATT_PERM_MASK_RD | INB_ATT_PERM_MASK_WRITE_COMMAND | INB_ATT_PERM_MASK_WRITE_REQ,
//		//it is max length of value.
//		//If ext_perm has RI set, read request indication will be triggered to get value, 
//		//or else, value present in database, put data at end of memory block. Attm will allocate memory 
//		//for having value in "service memory block". Ensure that size can be allocated into a 16 bits boundary ??
//		.max_len = 24,
//		.ext_perm = INB_ATT_PERM_MASK_RI,
//	},
//};

int atv_add_svc(void)
{
	int ret;
	inb_gatt_svc_desc_t *p_svc;
	
//	p_svc = (inb_gatt_svc_desc_t*)malloc(sizeof(inb_gatt_svc_desc_t)+g_AtvSecondarySvc.nb_att*sizeof(inb_gatt_att_desc_t));
//  if(!p_svc) return -1;
//	memcpy(p_svc, &g_AtvSecondarySvc, sizeof(inb_gatt_svc_desc_t));
//	memcpy(p_svc->atts, &g_AtvSecondaryAtts[0], g_AtvSecondarySvc.nb_att*sizeof(inb_gatt_att_desc_t));
//	ret = inb_gatt_add_svc(p_svc, &g_AtvSecondarySvc_shl);
//	if(p_svc) free(p_svc);
//	if(ret) return -1;
	
	p_svc = (inb_gatt_svc_desc_t*)malloc(sizeof(inb_gatt_svc_desc_t)+g_AtvPrimarySvc.nb_att*sizeof(inb_gatt_att_desc_t));
    if(!p_svc) return -1;
	memcpy(p_svc, &g_AtvPrimarySvc, sizeof(inb_gatt_svc_desc_t));
	memcpy(p_svc->atts, &g_AtvPrimaryAtts[0], ATVV_IDX_NB*sizeof(inb_gatt_att_desc_t));	
	ret = inb_gatt_add_svc(p_svc, &g_AtvPrimarySvc_shl);
//    PRINTD(DBG_TRACE, "ATV service handle:%d.\r\n", g_AtvPrimarySvc_shl);
	if(p_svc) free(p_svc);
	if(ret) return -1;
	
	return ret;
}

void atv_voice_char_tx_receive(int conIdx, uint8_t *buffer, uint8_t len)
{
    PRINTD(DBG_TRACE, "ATVV_CHAR_TX receive, conidx:%d, length=%d, data: 0x", conIdx, len);
    for(int i = 0; i < len; i++)
        PRINTD(DBG_TRACE, " %02X", buffer[i]);
//    PRINTD(DBG_TRACE, " %02X...", buffer[0]);
    PRINTD(DBG_TRACE, "\r\n");
    
    atv_task_cmd_receive(conIdx, buffer, len);
}

int atv_voice_char_rx_send(int conIdx, uint8_t *buffer, uint8_t len)
{
    int res = 0;
	uint16_t handle = g_AtvPrimarySvc_shl + 1 + ATVV_IDX_CHAR_RX_VAL;
    
    if(!atvIsConnected)
        return -1;
		
	res = inb_gatt_send_ntf(conIdx, handle, len, buffer);
    if(res)
        PRINTD(DBG_TRACE, "ATVV_CHAR_RX send error: 0x%X\r\n", res);
    else
    {
//        PRINTD(DBG_TRACE, "ATVV_CHAR_RX send, conidx:%d, length=%d, data: 0x", conIdx, len);
//        for(int i = 0; i < len; i++)
//            PRINTD(DBG_TRACE, " %02X", buffer[i]);
//        PRINTD(DBG_TRACE, " %02X...", buffer[0]);
//        PRINTD(DBG_TRACE, "\r\n");
//        PRINTD(DBG_TRACE, "a");
    }
    
    return res;
}
int atv_voice_char_ctl_send(int conIdx, uint8_t *buffer, uint8_t len)
{
    int res = 0;
	uint16_t handle = g_AtvPrimarySvc_shl + 1 + ATVV_IDX_CHAR_CTL_VAL;
    
    if(!atvIsConnected)
        return -1;
		
	res = inb_gatt_send_ntf(conIdx, handle, len, buffer);
    if(res)
        PRINTD(DBG_TRACE, "ATVV_CHAR_CTL send error: 0x%X\r\n", res);
    else
    {        
        if(buffer[0] != ATVV_CHAR_CTL_AUDIO_SYNC_CMD)//avoid SYNC LOG when voice is sending
        {
            PRINTD(DBG_TRACE, "ATVV_CHAR_CTL send, conidx:%d, length=%d, data: 0x", conIdx, len);
            for(int i = 0; i < len; i++)
                PRINTD(DBG_TRACE, " %02X", buffer[i]);
    //        PRINTD(DBG_TRACE, " %02X...", buffer[0]);
            PRINTD(DBG_TRACE, "\r\n");
        }
    }
    
    return res;
}
#endif
