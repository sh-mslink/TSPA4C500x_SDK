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
#include "msg.h"
#include "ble_app.h"
#include "ble_evt.h"

#include "evb_led.h"

#include "msat_app.h"
#include "msat_dev_ble_evt.h"


#define LED_REFRESH_TIME 500//ms


static bool msatAdvIsOn = false;
static bool msatBleIsCon = false;
static bool msatSendIsCfg = false;
static bool msatIsOta = false;

static void led_tmr_callback(void const *arg);
static osTimerId ledTimerId;
static osTimerDef(ledTimer, led_tmr_callback);


static int handle_main_msg(msg_t *msg)
{
    switch(msg->msgId)
    {
        default:
            break;
    }
    
    return 0;
}

static void led_tmr_callback(void const *arg)
{
    if(evb_led_on_number_get())
        evb_led_all_set(LED_OFF);
    else
    {
        if(msatIsOta)
            evb_led_all_set(LED_ON);
        else if(msatSendIsCfg)
            evb_led_single_set(LED_G, LED_ON);
        else if(msatBleIsCon)
            evb_led_single_set(LED_B, LED_ON);
        else if(msatAdvIsOn)
            evb_led_single_set(LED_R, LED_ON);
    }
}

static void ble_app_event_callback(inb_evt_t *evt)
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
    
    msat_dev_ble_evt_cb(evt);
}

static void msat_user_evt_ble_cb(msatEvtBle_t *evt)
{
    switch(evt->code)
    {
        case MSAT_EVT_BLE_CON_STATE:
            {
                PRINTD(DBG_TRACE, "MSAT_EVT_BLE_CON_STATE\r\n");
                
                msatBleIsCon = evt->param.conState.isConnected;
                msatAdvIsOn = false;
            }
            break;
        
        case MSAT_EVT_BLE_SEND_CFG:
            {
                PRINTD(DBG_TRACE, "MSAT_EVT_BLE_SEND_CFG\r\n");
                
                msatSendIsCfg = evt->param.sendCfg.isEnabled;
            }
            break;
        
        case MSAT_EVT_BLE_RCV_DATA:
            {
                PRINTD(DBG_TRACE, "MSAT_EVT_BLE_RCV_DATA\r\n");
                
                PRINTD(DBG_TRACE, "BLE receive, len %d, data", evt->param.rcvData.len);
                for(uint16_t i = 0; i < evt->param.rcvData.len; i++)
                    MSPRINT(" %02X", evt->param.rcvData.data[i]);
                PRINTD(DBG_TRACE, ".\r\n");
            }
            break;
        
        default:
            break;
    }
}

static void msat_user_evt_no_cmd_cb(char *data, uint16_t len)
{
    PRINTD(DBG_TRACE, "MSAT NO CMD, len %d, data", len);
    for(uint16_t i = 0; i < len; i++)
        MSPRINT(" %02X", data[i]);
    PRINTD(DBG_TRACE, ".\r\n");
}

static void msat_user_evt_cmd_in_cb(msatEvtCmdIn_t *evt)
{
    switch(evt->id)
    {
        case MSAT_CMD_ID_IN_RESET:
            {
                PRINTD(DBG_TRACE, "MSAT_CMD_ID_IN_RESET\r\n");
            }
            break;
        
        case MSAT_CMD_ID_IN_VERSION:
            {
                PRINTD(DBG_TRACE, "MSAT_CMD_ID_IN_VERSION\r\n");
            }
            break;
        
        case MSAT_CMD_ID_IN_MODE:
            {
                PRINTD(DBG_TRACE, "MSAT_CMD_ID_IN_MODE\r\n");
                
                if(evt->param[0] - '0' == MSAT_MODE_OTA)
                    msatIsOta = true;
            }
            break;
        
        case MSAT_CMD_ID_IN_ADV_INTERVAL:
            {
                PRINTD(DBG_TRACE, "MSAT_CMD_ID_IN_ADV_INTERVAL\r\n");
            }
            break;
        
        case MSAT_CMD_ID_IN_ADV_DATA:
            {
                PRINTD(DBG_TRACE, "MSAT_CMD_ID_IN_ADV_DATA\r\n");
            }
            break;
        
        case MSAT_CMD_ID_IN_ADV_ONOFF:
            {
                PRINTD(DBG_TRACE, "MSAT_CMD_ID_IN_ADV_ONOFF\r\n");
                
                msatAdvIsOn = evt->param[0] - '0';
            }
            break;
        
        case MSAT_CMD_ID_IN_ADV_STATE:
            {
                PRINTD(DBG_TRACE, "MSAT_CMD_ID_IN_ADV_STATE\r\n");
            }
            break;
        
        case MSAT_CMD_ID_IN_CON_STATE:
            {
                PRINTD(DBG_TRACE, "MSAT_CMD_ID_IN_CON_STATE\r\n");
            }
            break;
        
        default:
            break;
    }
}

static void msat_user_evt_wakeup_cb(void)
{
    PRINTD(DBG_TRACE, "MSAT WAKEUP\r\n");
}

static void board_init(void)
{
    evb_led_init();
    
    ledTimerId = osTimerCreate(osTimer(ledTimer), osTimerPeriodic, NULL);
    if(ledTimerId == NULL)
        PRINTD(DBG_TRACE, "Timer ledTimerId create failed.\r\n");
    osTimerStart(ledTimerId, LED_REFRESH_TIME);
}

/*
 * main: This is actually main task. 
 *  Note: The _main_init in the RTX_CM_lib.h is 
 *              main entry routine (OS is initialized 
 *              in there).
 */
int main (void)
{
    //Initialize platform
    hal_global_post_init();
    
#if (CFG_PDT_HCI || CFG_PDT_TX)
    //BLE production test
    ble_production_test();
#endif
    
    //Debug UART init
    hal_global_debug_uart_init();
    
    //Main LOG
    PRINTD(DBG_TRACE, "----------------\r\n");
    PRINTD(DBG_TRACE, "main start...\r\n");
    PRINTD(DBG_TRACE, "Wafer Version: %02X\r\n", chip_get_id() & 0xff);
    
    //EVB init
    board_init();
    
    //MessageQ for main thread.
    msg_init();
    
    //BLE init
    ble_config(false, ble_app_event_callback);
    
    //MSAT init
    static msatEvtCallback_t msatCb = 
    {
        .wupCb = &msat_user_evt_wakeup_cb,
        .cmdInCb = &msat_user_evt_cmd_in_cb,
        .noCmdCb = &msat_user_evt_no_cmd_cb,
        .bleCb = &msat_user_evt_ble_cb,
    };
    
    msatErr_t err = msat_app_init(&msatCb);
    if(err)
    {
        PRINTD(DBG_TRACE, "MSAT init failed, error %d\r\n", err);
        return 0;
    }
    else
        PRINTD(DBG_TRACE, "MSAT init success.\r\n");
    
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
