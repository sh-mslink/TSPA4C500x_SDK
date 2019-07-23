#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include ".\ble\inb_api.h"

#if (CFG_DBG_IF_UART==1) && (WITH_CONSOLE==1)
#include "..\inc\console.h"

int handle_testSvc_cmd(uint16_t eid, void *pv);

#define MAX_ATT_LEN 24

enum
{
	testSvc_set_format,

	testSvc_cmd_max,
};

const console_cmd_t g_testSvc_cmds[] = {
	{"testSvc_set_format",           1,		testSvc_set_format,		"Usage: %s <format>\r\n" },
};

#endif

enum
{
	TEST_ATT_DECL_INCLUDE = 0,
	TEST_ATT_DECL_CHARACTERISTIC_AA,
	TEST_ATT_CHAR_VAL_AA,
	TEST_ATT_DESC_CHAR_EXT_PROPERTIES,
	TEST_ATT_DESC_CHAR_USER_DESCRIPTION,
	TEST_ALL_DESC_CLIENT_CHAR_CFG,
	TEST_ATT_DESC_SERVER_CHAR_CFG,
	TEST_ATT_DESC_CHAR_PRES_FORMAT,
	TEST_ATT_DESC_CHAR_AGGREGATE_FORMAT,
};

const inb_gatt_att_desc_t g_TestSecondaryAtts[] = {
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

const inb_gatt_att_desc_t g_TestPrimaryAtts[] = {
	[TEST_ATT_DECL_INCLUDE] = 
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
	[TEST_ATT_DECL_CHARACTERISTIC_AA] = 
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
		.ext_perm = INB_ATT_PERM_MASK_EXT,
	},
	[TEST_ATT_CHAR_VAL_AA] = 
	{
		.uuid = "\x00\xAA",//Need to be changed in different services
		.perm = INB_ATT_PERM_MASK_RD |INB_ATT_PERM_MASK_WRITE_COMMAND | INB_ATT_PERM_MASK_WRITE_REQ | INB_ATT_PERM_MASK_IND | INB_ATT_PERM_MASK_NTF,
		//it is max length of value.
		//If ext_perm has RI set, read request indication will be triggered to get value, 
		//or else, value present in database, put data at end of memory block. Attm will allocate memory 
		//for having value in "service memory block". Ensure that size can be allocated into a 16 bits boundary ??
		.max_len = 10,
		.ext_perm = INB_ATT_PERM_MASK_RI,
	},
	[TEST_ATT_DESC_CHAR_EXT_PROPERTIES] = 
	{
		.uuid = "\x00\x29",//INB_ATT_DESC_CHAR_EXT_PROPERTIES,
		.perm = INB_ATT_PERM_MASK_RD,
		//For Characteristic Extended Properties, this field contains 2 byte value
		.max_len = 0x55aa,
		.ext_perm = 0,
	},
	[TEST_ATT_DESC_CHAR_USER_DESCRIPTION] = 
	{
		.uuid = "\x01\x29",//INB_ATT_DESC_CHAR_USER_DESCRIPTION,
		.perm = INB_ATT_PERM_MASK_RD | INB_ATT_PERM_MASK_WRITE_COMMAND | INB_ATT_PERM_MASK_WRITE_REQ,
		//Same as "Characteristic Value Declaration"
		.max_len = 24,
		.ext_perm = INB_ATT_PERM_MASK_RI,
	},
	[TEST_ALL_DESC_CLIENT_CHAR_CFG] = 
	{
		.uuid = "\x02\x29",//INB_ATT_DESC_SERVER_CHAR_CFG,
		.perm = INB_ATT_PERM_MASK_RD | INB_ATT_PERM_MASK_WRITE_COMMAND | INB_ATT_PERM_MASK_WRITE_REQ,
		// Not used Client Characteristic Configuration and Server Characteristic Configuration,
		// this field is not used.
		// Value is get always by RI. 
		.max_len = 0,
		.ext_perm = 0,
	},
	[TEST_ATT_DESC_SERVER_CHAR_CFG] = 
	{
		.uuid = "\x03\x29",//INB_ATT_DESC_SERVER_CHAR_CFG,
		.perm = INB_ATT_PERM_MASK_RD | INB_ATT_PERM_MASK_WRITE_REQ,
		// Not used Client Characteristic Configuration and Server Characteristic Configuration,
		// this field is not used.
		// Value is get always by RI. Same as "DESC_CLIENT_CHAR_CFG"
		.max_len = 0,
		.ext_perm = 0,
	},
	[TEST_ATT_DESC_CHAR_PRES_FORMAT] = 
	{
		.uuid = "\x04\x29",//INB_ATT_DESC_CHAR_PRES_FORMAT,
		.perm = INB_ATT_PERM_MASK_RD,
		//Same as "Characteristic Value Declaration"
		.max_len = 2,
		.ext_perm = INB_ATT_PERM_MASK_RI,
	},	
	[TEST_ATT_DESC_CHAR_AGGREGATE_FORMAT] = 
	{
		.uuid = "\x05\x29",//INB_ATT_DESC_CHAR_AGGREGATE_FORMAT,
		.perm = INB_ATT_PERM_MASK_RD,
		//Same as "Characteristic Value Declaration"
		.max_len = 2,
		.ext_perm = INB_ATT_PERM_MASK_RI,
	},
};

const inb_gatt_svc_desc_t g_TestSecondarySvc = {
	.start_hdl = 0,
	.perm = INB_ATT_PERM_MASK_SVC_SECONDARY,
	.uuid = "\x00\xB0",
	.nb_att = 2,
};

const inb_gatt_svc_desc_t g_TestPrimarySvc = {
	.start_hdl = 0,
	.perm = 0,//(0x02 << INB_ATT_PERM_POS_SVC_AUTH) & INB_ATT_PERM_MASK_SVC_AUTH,
	.uuid = "\x00\xA0",
	.nb_att = 8,
};

typedef struct 
{
    /// Format, @see enum inb_pres_fmt
    uint8_t format;
    /// Exponent
    uint8_t exponent;
    /// Unit (The Unit is a UUID), @see enum inb_common_uuid
    uint16_t unit;
    /// Name space, 1- SIG assigned
    uint8_t name_space;
    /// Description
    uint16_t description;
}__attribute__ ((packed)) inb_char_pres_fmt_packed_t;

struct present_format_t
{
	char name[10];
	struct _format_pkg_{
		uint16_t len;
		inb_char_pres_fmt_packed_t format;
	}format_pkg;
	char value[28+1];
};

const static struct present_format_t g_PresentFormat[] = {
	[0] = {"boolean",	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_BOOL, .exponent=0,.name_space=1}}, 		"\x01\x00\x01"},
	[1] = {"2bit", 		{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_2BIT, .exponent=0,.name_space=1}}, 			"\x01\x00\x02"},
	[2] = {"nibble",	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_NIBBLE, .exponent=0,.name_space=1}},		"\x01\x00\x0a"},
	[3] = {"uint8",		{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_UINT8, .exponent=0,.name_space=1}},		"\x01\x00\xaa"},
	[4] = {"uint12",	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_UINT12, .exponent=0,.name_space=1}},		"\x02\x00\xaa\x0a"},
	[5] = {"uint16",	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_UINT16, .exponent=0,.name_space=1}},		"\x02\x00\x00\x00"},
	[6] = {"uint24", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_UINT24, .exponent=0,.name_space=1}},		"\x03\x00\xaa\xaa\xaa"},
	[7] = {"uint32", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_UINT32, .exponent=0,.name_space=1}},		"\x04\x00\xaa\xaa\xaa\xaa"},
	[8] = {"uint48", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_UINT48, .exponent=0,.name_space=1}},		"\x06\x00\xaa\xaa\xaa\xaa\xaa\xaa"},
	[9] = {"uint64", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_UINT64, .exponent=0,.name_space=1}},		"\x08\x00\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"},
	[10] = {"unit128", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_UINT128, .exponent=0,.name_space=1}},		"\x10\x00\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"},
	[11] = {"sint8", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_SINT8, .exponent=0,.name_space=1}},		"\x01\x00\xaa"},
	[12] = {"sint12", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_SINT12, .exponent=0,.name_space=1}},		"\x02\x00\xaa\x0a"},
	[13] = {"sint16",	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_SINT16, .exponent=0,.name_space=1}},		"\x02\x00\xaa\xaa"},
	[14] = {"sint24", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_SINT24, .exponent=0,.name_space=1}},		"\x03\x00\xaa\xaa\xaa"},
	[15] = {"sint32", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_SINT32, .exponent=0,.name_space=1}},		"\x04\x00\xaa\xaa\xaa\xaa"},
	[16] = {"sint48", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_SINT48, .exponent=0,.name_space=1}},		"\x06\x00\xaa\xaa\xaa\xaa\xaa\xaa"},
	[17] = {"sint64", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_SINT64, .exponent=0,.name_space=1}},		"\x08\x00\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"},
	[18] = {"sint128",	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_SINT128, .exponent=0,.name_space=1}},		"\x10\x00\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"},
	[19] = {"float32", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_FLOAT32, .exponent=0,.name_space=1}},		"\x04\x00\xaa\xaa\xaa\xaa"},
	[20] = {"float64", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_FLOAT64, .exponent=0,.name_space=1}},		"\x08\x00\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"},
	[21] = {"SFLOAT", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_SFLOAT, .exponent=0,.name_space=1}},		"\x02\x00\xaa\xaa"},
	[22] = {"FLOAT", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_FLOAT, .exponent=0,.name_space=1}},		"\x04\x00\xaa\xaa\xaa\xaa\xaa\xaa"},
	[23] = {"duint16", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_DUINT16, .exponent=0,.name_space=1}},		"\x04\x00\xaa\xaa\xaa\xaa\xaa\xaa"},
	[24] = {"utf8", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_UTF8S, .exponent=0,.name_space=1}},		"\x07\x00\xef\xbb\xbf\x74\x65\x73\x74"},
	[25] = {"utf16", 	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_UTF16S, .exponent=0,.name_space=1}},		"\x0a\x00\xff\xfe\x74\x00\x65\x00\x73\x00\x74\x00"},
	[26] = {"struct",	{7, {.unit=INB_ATT_UNIT_UNITLESS, .description=1, .format=INB_ATT_FORMAT_STRUCT, .exponent=0,.name_space=1}},		"\x18\x00\x61\x62\x63\x64\x65\x66\x67\x68\x69\x6a\x6b\x6c\x6d\x6e\x6f\x70\x71\x72\x73\x74\x75\x76\x77\x78\x79\x7a"},
};

uint16_t g_TestSecondarySvc_shl = 0;
uint16_t g_TestPrimarySvc_shl = 0;
int g_pres_format_index = 0;

uint8_t gTestSvcBuf[12] = {0};

struct _written_data_
{
	uint16_t handle;
	uint16_t len;
	uint8_t pData[];
}__attribute__ ((packed)) *gp_AttWrittenData[2] = {0};

int testSvc_add_svc()
{
	int ret;
			
	inb_gatt_svc_desc_t *p_svc = (inb_gatt_svc_desc_t*)malloc(sizeof(inb_gatt_svc_desc_t)+g_TestSecondarySvc.nb_att*sizeof(inb_gatt_att_desc_t));
	memcpy(p_svc, &g_TestSecondarySvc, sizeof(inb_gatt_svc_desc_t));
	memcpy(p_svc->atts, &g_TestSecondaryAtts[0], g_TestSecondarySvc.nb_att*sizeof(inb_gatt_att_desc_t));
	ret = inb_gatt_add_svc(p_svc, &g_TestSecondarySvc_shl);
	free(p_svc);
	if (ret)	return -1;
	printf("start handle for 'Secondary Service' is 0x%02X\r\n", g_TestSecondarySvc_shl);
			
	p_svc = (inb_gatt_svc_desc_t*)malloc(sizeof(inb_gatt_svc_desc_t)+g_TestPrimarySvc.nb_att*sizeof(inb_gatt_att_desc_t));
	memcpy(p_svc, &g_TestPrimarySvc, sizeof(inb_gatt_svc_desc_t));
	memcpy(p_svc->atts, &g_TestPrimaryAtts[0], g_TestPrimarySvc.nb_att*sizeof(inb_gatt_att_desc_t));
	p_svc->atts[0].max_len = g_TestSecondarySvc_shl;//Need to set to attribute handle of included service 
	//p_svc->atts[1].ext_perm |= INB_ATT_PERM_MASK_EXT;
	//p_svc->atts[1].max_len = 0xBB00;// Need to be changed in differrent services
	//*((uint16_t*)p_svc->atts[2].uuid) = 0xBB00;// Need to be changed in differrent services
	ret = inb_gatt_add_svc(p_svc, &g_TestPrimarySvc_shl);
	free(p_svc);
	if (ret)	return -1;
	printf("start handle for 'Primary Service' is 0x%02X\r\n", g_TestPrimarySvc_shl);
	
#if (CFG_DBG_IF_UART==1) && (WITH_CONSOLE==1)
	register_console_cmds((console_cmd_t*)g_testSvc_cmds, sizeof(g_testSvc_cmds)/sizeof(console_cmd_t), handle_testSvc_cmd);
#endif
	return ret;
}

void testSvc_set_att_value(uint16_t handle, uint16_t len, uint16_t offset, void* val)
{
	int i;
	uint8_t *pOrigin=NULL;

	if (g_TestPrimarySvc_shl == 0)
		return;
	
	for (i=0;i<sizeof(gp_AttWrittenData)/sizeof(gp_AttWrittenData[0]);i++)
		if (gp_AttWrittenData[i] == NULL || gp_AttWrittenData[i]->handle == handle)
			break;

	if (i != sizeof(gp_AttWrittenData)/sizeof(gp_AttWrittenData[0])){
		if(gp_AttWrittenData[i] == NULL){
			gp_AttWrittenData[i] = (struct _written_data_*)malloc(sizeof(struct _written_data_)+len);
			gp_AttWrittenData[i]->len = 0;
			offset = 0;
		}else if (offset+len > gp_AttWrittenData[i]->len){
			pOrigin = gp_AttWrittenData[i]->pData;
			gp_AttWrittenData[i] = (struct _written_data_*)malloc(sizeof(struct _written_data_)+len+offset);
			memcpy((uint8_t *)gp_AttWrittenData[i]->pData, pOrigin, offset);
			gp_AttWrittenData[i]->len = offset;
			free(pOrigin);
		}else{
			gp_AttWrittenData[i]->len -= len;
		}
		gp_AttWrittenData[i]->handle = handle;
		gp_AttWrittenData[i]->len += len;
		memcpy((uint8_t *)gp_AttWrittenData[i]->pData+offset, val, len);
	}
}

uint16_t testSvc_get_att_len(uint16_t handle)
{
	if (g_TestPrimarySvc_shl == 0)
		return 0;

	if (handle > g_TestSecondarySvc_shl && handle < g_TestPrimarySvc_shl){
		return *((uint16_t*)g_PresentFormat[sizeof(g_PresentFormat)/sizeof(struct present_format_t)-1].value);

	}else if (handle > g_TestPrimarySvc_shl ) {
		switch(handle - g_TestPrimarySvc_shl - 1)
		{
		case TEST_ATT_DECL_CHARACTERISTIC_AA://INB_ATT_DECL_CHARACTERISTIC
			return 5;
		case TEST_ATT_CHAR_VAL_AA://Characteristic Value
			return *((uint16_t*)g_PresentFormat[g_pres_format_index].value);
		case TEST_ATT_DESC_CHAR_USER_DESCRIPTION://INB_ATT_DESC_CHAR_USER_DESCRIPTION
			return *((uint16_t*)g_PresentFormat[g_pres_format_index].value);
		case TEST_ATT_DESC_CHAR_PRES_FORMAT://INB_ATT_DESC_CHAR_PRES_FORMAT
			return g_PresentFormat[g_pres_format_index].format_pkg.len;
		case TEST_ATT_DESC_CHAR_AGGREGATE_FORMAT://INB_ATT_DESC_CHAR_AGGREGATE_FORMAT
			return 2;
		case TEST_ATT_DESC_SERVER_CHAR_CFG:
			return 1;
		default:
			break;
		}
	}
	return 0;
}

void* testSvc_get_att_value(uint16_t handle)
{
	int i;

	if (g_TestPrimarySvc_shl == 0)
		return NULL;
	
	for (i=0;i<sizeof(gp_AttWrittenData)/sizeof(struct _written_data_);i++)
		if (gp_AttWrittenData[i] != NULL && gp_AttWrittenData[i]->handle == handle)
			return (void*)&(gp_AttWrittenData[i]->len);

	if (handle > g_TestSecondarySvc_shl && handle < g_TestPrimarySvc_shl){
		
		return (void*)g_PresentFormat[sizeof(g_PresentFormat)/sizeof(struct present_format_t)-1].value;

	}else if (handle > g_TestPrimarySvc_shl ) {
		switch(handle - g_TestPrimarySvc_shl - 1)
		{
		case TEST_ATT_DECL_CHARACTERISTIC_AA://INB_ATT_DECL_CHARACTERISTIC
			break;
		case TEST_ATT_CHAR_VAL_AA://Characteristic Value
			return (void*)g_PresentFormat[g_pres_format_index].value;
		case TEST_ATT_DESC_CHAR_USER_DESCRIPTION://INB_ATT_DESC_CHAR_USER_DESCRIPTION
			return (void*)g_PresentFormat[sizeof(g_PresentFormat)/sizeof(struct present_format_t)-1].value;
		case TEST_ATT_DESC_CHAR_PRES_FORMAT://INB_ATT_DESC_CHAR_PRES_FORMAT
			return (void*)&g_PresentFormat[g_pres_format_index].format_pkg;
		case TEST_ATT_DESC_CHAR_AGGREGATE_FORMAT://INB_ATT_DESC_CHAR_AGGREGATE_FORMAT
			{
				*((uint16_t*)gTestSvcBuf) = 2;
				*((uint16_t*)gTestSvcBuf+1) = g_TestPrimarySvc_shl+TEST_ATT_DESC_CHAR_PRES_FORMAT+1;
				return (void*)gTestSvcBuf;
			}
		case TEST_ALL_DESC_CLIENT_CHAR_CFG:
			return (void*)g_PresentFormat[5].value;
		case TEST_ATT_DESC_SERVER_CHAR_CFG:
			return (void*)g_PresentFormat[0].value;
		default:
			break;
		}
	}
	return NULL;
}

#if (CFG_DBG_IF_UART==1) && (WITH_CONSOLE==1)
int handle_testSvc_cmd(uint16_t eid, void *pv)
{
	uint16_t *p_param = (uint16_t*)pv;
	int i, ret = 0;
	uint16_t cnt;

	switch(eid)
	{
	case testSvc_set_format:
		#if 1
		{
			if (*p_param < sizeof(g_PresentFormat)/sizeof(struct present_format_t))
				g_pres_format_index = *p_param;
			break;
		}
		#else
		for (i=0;i<sizeof(g_PresentFormat)/sizeof(struct present_format_t);i++){
			if (!strcmp(p_param, g_PresentFormat[i].name)){
				g_pres_format_index = i;
				break;
			}
		}
		if (i==sizeof(g_PresentFormat)/sizeof(struct present_format_t))		return -1;
		break;
		#endif
	default:
		return 0;
	}
	return 1;
}
#endif

