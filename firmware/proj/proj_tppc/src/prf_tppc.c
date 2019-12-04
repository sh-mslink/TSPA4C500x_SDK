#include "in_config.h"
#include "in_debug.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include ".\ble\inb_api.h"
#include "prf_tppc.h"


#define TPPC_RSSI_THRESHOLD (-30)//(-127 ~ +20 dBm)


bool tppcIsConnected = false;
uint8_t tppServiceHandle = 0;


bool isTppsDevice(int8_t rssi, uint8_t *advData, uint8_t advLen)
{
    if(rssi < TPPC_RSSI_THRESHOLD)
        return false;
    
    uint8_t i = 0;
    uint8_t cmpData[] = 
    {
        0x0B,//AD Element Length
        0x08,//AD Type: Shortened local name
        'T','r','o','p','o','s',' ','T','P','P'//AD Data Bytes: "Tropos TPP"
    };
    
    uint8_t cmpLen = sizeof(cmpData);
    
    if(advLen < cmpLen)
        return false;
    
    for(i = 0; i < advLen - cmpLen + 1; i++)
    {
        if(!memcmp(advData + i, cmpData, cmpLen))
            return true;
    }
    
    return false;
}

int tppc_cfg_notify(int conIdx, bool enable)
{
    int res = 0;
    
    if(!tppcIsConnected)
        return -1;
    
    inb_gatt_write_t *cfg = malloc(sizeof(inb_gatt_write_t));
    
    if(cfg)
    {
        cfg->offset = 0;
        cfg->auto_execute = true;
        cfg->handle = tppServiceHandle + TPP_IDX_NTF_VAL_CFG;
        cfg->length = 2;
        if(enable)
            cfg->value[0] = 0x01;
        else
            cfg->value[0] = 0x00;
        cfg->value[1] = 0x00;
        
        res = inb_gatt_write(conIdx, GATT_WRITE, cfg);
        if(res)
            PRINTD(DBG_TRACE, "%s error:0x%X.\r\n", __func__, res);
        else
        {
            if(enable)
                PRINTD(DBG_TRACE, "Notify enable.\r\n");
            else
                PRINTD(DBG_TRACE, "Notify disable.\r\n");
        }
        
        if(cfg)
            free(cfg);
    }
    
    return res;
}

int tppc_send_write(int conIdx, uint8_t *buffer , uint8_t len)
{
    int res = 0;
    
    if(!tppcIsConnected)
        return -1;
    
    inb_gatt_write_t *wrt = malloc(sizeof(inb_gatt_write_t));
    
    if(wrt)
    {
        wrt->offset = 0;
        wrt->auto_execute = false;
        wrt->handle = tppServiceHandle + TPP_IDX_WR_DATA_VAL;
        wrt->length = len;
        memcpy(wrt->value, buffer, len);
        
        res = inb_gatt_write(conIdx, GATT_WRITE_NO_RESPONSE, wrt);
        if(res)
            PRINTD(DBG_TRACE, "TPPC write send error: 0x%X\r\n", res);
        else
        {
            PRINTD(DBG_TRACE, "TPPC send, conidx:%d, length=%d, data: 0x", conIdx, len);
    //        for(int i = 0; i < len; i++)
    //            PRINTD(DBG_TRACE, " %02X", buffer[i]);
            PRINTD(DBG_TRACE, " %02X...", buffer[0]);
            PRINTD(DBG_TRACE, "\r\n");
        }
        
        if(wrt)
            free(wrt);
    }
    
    return 0;
}

void tppc_receive_notify(int conIdx, uint8_t *buffer , uint8_t len)
{
    PRINTD(DBG_TRACE, "TPPC receive, conidx:%d, length=%d, data: 0x", conIdx, len);
//    for(int i = 0; i < len; i++)
//        PRINTD(DBG_TRACE, " %02X", buffer[i]);
    PRINTD(DBG_TRACE, " %02X...", buffer[0]);
    PRINTD(DBG_TRACE, "\r\n");
}
