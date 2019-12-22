#include "in_config.h"

#if CFG_PRF_TPPS_EN

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include ".\ble\inb_api.h"
#include "prf_tpps.h"


static uint16_t g_TppsPrimarySvc_hdl = 0;

const inb_gatt_svc_desc_t g_TppPrimarySvc =
{
    .start_hdl = 0,
    .prop = (0 << ATT_SVC_PROP_UUID_LEN_SHIFT),
    .uuid = TPP_SERCICE_UUID,
    .nb_att = TPP_IDX_NB,
};

const inb_gatt_att_desc_t g_TppPrimaryAtts[7] =
{
    [TPP_IDX_WR_DATA_CHAR] = 
    {
        .uuid = "\x03\x28",
        .prop = ATT_CHAR_PROP_READ,
        .max_len = 0,
        .ext_prop = (0 << ATT_EXT_PROP_UUID_LEN_SHIFT),
    },
    [TPP_IDX_WR_DATA_VAL] = 
    {
        .uuid = "\x01\xFF",
        .prop = ATT_CHAR_PROP_WRITE_NO_RSP | ATT_CHAR_PROP_WRITE,
        .max_len = 1024,
        .ext_prop = (0 <<ATT_EXT_PROP_UUID_LEN_SHIFT),
    },
    [TPP_IDX_NTF_VAL_CHAR] = 
    {
        .uuid = "\x03\x28",
        .prop = ATT_CHAR_PROP_READ,
        .max_len = 0,
        .ext_prop = (0 << ATT_EXT_PROP_UUID_LEN_SHIFT),
    },
    [TPP_IDX_NTF_VAL] = 
    {
        .uuid = "\x02\xFF",
        .prop = ATT_CHAR_PROP_NOTIFY,
        .max_len = 1024,
        .ext_prop = (0 << ATT_EXT_PROP_UUID_LEN_SHIFT),
    },
    [TPP_IDX_NTF_VAL_CFG] = 
    {
        .uuid = "\x02\x29",
        .prop = ATT_CHAR_PROP_READ | ATT_CHAR_PROP_WRITE,
        .max_len = 0,
        .ext_prop = 0,
    },
};

uint16_t tpps_get_svc_hdl(void)
{
    return (g_TppsPrimarySvc_hdl + 1);
}

int tpps_add_svc(void)
{
    int ret;
    inb_gatt_svc_desc_t *p_svc;
    
    p_svc = (inb_gatt_svc_desc_t*)malloc(sizeof(inb_gatt_svc_desc_t)+g_TppPrimarySvc.nb_att*sizeof(inb_gatt_att_desc_t));
    if(!p_svc)
        return -1;
    memcpy(p_svc, &g_TppPrimarySvc, sizeof(inb_gatt_svc_desc_t));
    memcpy(p_svc->atts, &g_TppPrimaryAtts[0], 7*sizeof(inb_gatt_att_desc_t));
    ret = inb_gatt_add_svc(p_svc, &g_TppsPrimarySvc_hdl);
    if(p_svc) free(p_svc);
    if(ret)
        return ret;
    
    return ret;
}

int tpps_send_notify(int conIdx, uint8_t *buffer , uint8_t len)
{
    int res = 0;
    uint16_t handle = tpps_get_svc_hdl() + TPP_IDX_NTF_VAL;
    
    res = inb_gatt_send_ntf(conIdx, handle, len,buffer);
    if(res)
        PRINTD(DBG_TRACE, "TPPS notity send error: 0x%X\r\n", res);
    else
    {
        PRINTD(DBG_TRACE, "TPPS send, conidx:%d, length=%d, data: 0x", conIdx, len);
//        for(int i = 0; i < len; i++)
//            PRINTD(DBG_TRACE, " %02X", buffer[i]);
        PRINTD(DBG_TRACE, " %02X...", buffer[0]);
        PRINTD(DBG_TRACE, "\r\n");
    }
    
    return res;
}

#endif
