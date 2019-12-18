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

const inb_gatt_svc_desc_t g_AtvPrimarySvc =
{
    .start_hdl = 0,
    .prop = (2 << ATT_SVC_PROP_UUID_LEN_SHIFT),
    .uuid = ATVV_SERVICE_UUID,
    .nb_att = ATVV_IDX_NB,
};

const inb_gatt_att_desc_t g_AtvPrimaryAtts[ATVV_IDX_NB] =
{
    [ATVV_IDX_CHAR_TX] =
    {
        .uuid = "\x03\x28",
        .prop = ATT_CHAR_PROP_READ,
        .max_len = 0,
        .ext_prop = (0 << ATT_EXT_PROP_UUID_LEN_SHIFT),
    },
    [ATVV_IDX_CHAR_TX_VAL] =
    {
        .uuid = ATVV_CHAR_TX_UUID,
        .prop = ATT_CHAR_PROP_WRITE,
        .max_len = 20,
        .ext_prop = (2 << ATT_EXT_PROP_UUID_LEN_SHIFT),
    },
    
    [ATVV_IDX_CHAR_RX] =
    {
        .uuid = "\x03\x28",
        .prop = ATT_CHAR_PROP_READ,
        .max_len = 0,
        .ext_prop = (0 << ATT_EXT_PROP_UUID_LEN_SHIFT),
    },
    [ATVV_IDX_CHAR_RX_VAL] =
    {
        .uuid = ATVV_CHAR_RX_UUID,
        .prop = ATT_CHAR_PROP_NOTIFY,
        .max_len = 20,
        .ext_prop = (2 << ATT_EXT_PROP_UUID_LEN_SHIFT),
    },
    [ATVV_IDX_CHAR_RX_CFG] =
    {
        .uuid = "\x02\x29",
        .prop = ATT_CHAR_PROP_READ | ATT_CHAR_PROP_WRITE,
        .max_len = 0,
        .ext_prop = 0,
    },
    
    [ATVV_IDX_CHAR_CTL] =
    {
        .uuid = "\x03\x28",
        .prop = ATT_CHAR_PROP_READ,
        .max_len = 0,
        .ext_prop = (0 << ATT_EXT_PROP_UUID_LEN_SHIFT),
    },
    [ATVV_IDX_CHAR_CTL_VAL] =
    {
        .uuid = ATVV_CHAR_CTL_UUID,
        .prop = ATT_CHAR_PROP_NOTIFY,
        .max_len = 20,
        .ext_prop = (2 << ATT_EXT_PROP_UUID_LEN_SHIFT),
    },
    [ATVV_IDX_CHAR_CTL_CFG] =
    {
        .uuid = "\x02\x29",
        .prop = ATT_CHAR_PROP_READ | ATT_CHAR_PROP_WRITE,
        .max_len = 0,
        .ext_prop = 0,
    },
};

int atv_add_svc(void)
{
    int ret;
    inb_gatt_svc_desc_t *p_svc;
    
    p_svc = (inb_gatt_svc_desc_t*)malloc(sizeof(inb_gatt_svc_desc_t)+g_AtvPrimarySvc.nb_att*sizeof(inb_gatt_att_desc_t));
    if(!p_svc) return -1;
    memcpy(p_svc, &g_AtvPrimarySvc, sizeof(inb_gatt_svc_desc_t));
    memcpy(p_svc->atts, &g_AtvPrimaryAtts[0], ATVV_IDX_NB*sizeof(inb_gatt_att_desc_t));
    ret = inb_gatt_add_svc(p_svc, &g_AtvPrimarySvc_shl);
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
//            PRINTD(DBG_TRACE, " %02X...", buffer[0]);
            PRINTD(DBG_TRACE, "\r\n");
        }
    }
    
    return res;
}
#endif
