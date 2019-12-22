#include "in_config.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "in_arm.h"
#include "in_debug.h"
#include "hal_global.h"

#include "cmsis_os.h"

#include "msg.h"
#include "ble_app.h"
#include "ble_evt.h"


static int handle_main_msg(msg_t *msg)
{
    switch(msg->msgId)
    {
        default:
            break;
    }
    
    return 0;
}

void ble_app_event_callback(inb_evt_t *evt)
{
    switch(evt->evt_id)
    {
        case GAP_EVT_CONN_REQ:
            {
                inb_evt_conn_req_t *p = (inb_evt_conn_req_t *)evt->param;
                
                PRINTD(DBG_TRACE, "Connected, idx:%d, ", p->conidx);
                PRINTD(DBG_TRACE, "addr type:%d, ", p->peer_addr_type);
                PRINTD(DBG_TRACE, "addr:0x %02X %02X %02X %02X %02X %02X, ", 
                        p->peer_addr.addr[0], p->peer_addr.addr[1], p->peer_addr.addr[2], 
                        p->peer_addr.addr[3], p->peer_addr.addr[4], p->peer_addr.addr[5]);
                PRINTD(DBG_TRACE, "interval:0x%X, ", p->con_interval);
                PRINTD(DBG_TRACE, "latency:%d, ", p->con_latency);
                PRINTD(DBG_TRACE, "timeout:%dms.\r\n", p->sup_to * 10);
            }
            break;
        
        case GAP_EVT_DISCONNECT:
            {
                inb_evt_disc_ind_t *p = (inb_evt_disc_ind_t *)evt->param;
                
                PRINTD(DBG_TRACE, "Disconnected, idx:%d, reason:0x%02X.\r\n", p->conidx, p->reason);
                
                if(start_adv())
                    return;
            }
            break;
        
        case GAP_EVT_LE_PKT_SIZE_IND:
            {
                inb_evt_le_pkt_size_t *p = (inb_evt_le_pkt_size_t*)evt->param;
                
                PRINTD(DBG_TRACE, "Peer max packet size, idx:%d, TX: %d Bytes %dms, RX: %d Bytes %dms.\r\n", 
                        p->conidx, p->max_tx_octets, p->max_tx_time, p->max_rx_octets, p->max_rx_time);
            }
            break;
        
        case GAP_EVT_CONN_PARAM_UPD:
            {
                inb_evt_conn_param_upd_t *p = (inb_evt_conn_param_upd_t*)evt->param;
                
                PRINTD(DBG_TRACE, "Connection parameters updated, idx:%d, interval:0x%X, latency:%d, timeout:%dms.\r\n", 
                        p->conidx, p->con_interval, p->con_latency, p->sup_to * 10);
            }
            break;
        
        default:
            break;
    }
}

/*
 * main: This is actually main task. 
 *  Note: The _main_init in the RTX_CM_lib.h is 
 *              main entry routine (OS is initialized 
 *              in there).
 */
int main (void)
{
    //Initialize platform.
    hal_global_post_init();
    
    PRINTD(DBG_TRACE, "----------------\r\n");
    PRINTD(DBG_TRACE, "main start...\r\n");
    PRINTD(DBG_TRACE, "Wafer Version: %02X\r\n", chip_get_id() & 0xff);
    
    //MessageQ for main thread.
    msg_init();
    
    //BLE init
    ble_config();
    
    //Start advertisng
    if(start_adv())
        return 0;
    
    //Wait for message
    while(1)
    {
        msg_t *msg;
        
        msg = msg_get(osWaitForever);
        
        handle_main_msg(msg);
        
        if(msg)
            msg = msg_free(msg);
    }
}
