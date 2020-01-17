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

#include "evb_led.h"


#define LED_REFRESH_TIME 500//ms

#define TPP_PACK_LENGTH     (20)
#define UART_RX_BUF_LENGTH  (1024)


static bool tppsIsConnected = false;
static bool tppsNtfEnabled = false;

static void led_tmr_callback(void const *arg);
static osTimerId ledTimerId;
static osTimerDef(ledTimer, led_tmr_callback);

static void *uartPtHdl;
static uint8_t uartRxBuf[UART_RX_BUF_LENGTH] = {0};
static osThreadDef_t uartRxDef;


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
        if(tppsNtfEnabled)
            evb_led_single_set(LED_G, LED_ON);
        else if(tppsIsConnected)
            evb_led_single_set(LED_B, LED_ON);
        else
            evb_led_single_set(LED_R, LED_ON);
    }
}

static void tpps_receive_write(int conIdx, uint8_t *buffer, uint8_t len)
{
    PRINTD(DBG_TRACE, "TPPS receive, conidx:%d, length=%d, data: 0x", conIdx, len);
//    for(int i = 0; i < len; i++)
//        PRINTD(DBG_TRACE, " %02X", buffer[i]);
    PRINTD(DBG_TRACE, " %02X...", buffer[0]);
    PRINTD(DBG_TRACE, "\r\n");
    
    int err;
    
    err = hal_uart_xmit_poll(uartPtHdl, buffer, len);
    if(err)
        PRINTD(DBG_TRACE, "TX err %d\r\n", err);
}

static void uart_receive_task(const void *arg)
{
    osEvent osEvt;
    uint32_t rxLen = 0;
    uint32_t i = 0;
    int err;
    
    while(1)
    {
        err = hal_uart_rcvd_intr_tmo(uartPtHdl, uartRxBuf, UART_RX_BUF_LENGTH, &rxLen, osWaitForever);
        if(err)
            PRINTD(DBG_TRACE, "RX err %d\r\n", err);
//        else
//        {
//            PRINTD(DBG_TRACE, "len %d 0x", rxLen);
//            for(i = 0; i < rxLen; i++)
//                PRINTD(DBG_TRACE, "%02X ", uartRxBuf[i]);
//            PRINTD(DBG_TRACE, "\r\n");
//        }
        
        if(!err && rxLen > 0)
        {
            i = 0;
            while(rxLen > TPP_PACK_LENGTH)
            {
                if(tppsNtfEnabled)
                    tpps_send_notify(0, uartRxBuf + i * TPP_PACK_LENGTH, TPP_PACK_LENGTH);
                i++;
                rxLen -= TPP_PACK_LENGTH;
            }
            if(tppsNtfEnabled)
                tpps_send_notify(0, uartRxBuf + i * TPP_PACK_LENGTH, rxLen);
        }
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
                
                tppsIsConnected = true;
            }
            break;
        
        case GAP_EVT_DISCONNECT:
            {
                inb_evt_disc_ind_t *p = (inb_evt_disc_ind_t *)evt->param;
                
                PRINTD(DBG_TRACE, "Disconnected, idx:%d, reason:0x%02X.\r\n", p->conidx, p->reason);
                
                tppsIsConnected = false;
                tppsNtfEnabled = false;
                
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
        
        case GATT_EVT_WRT_REQ:
            {
                inb_evt_write_req_ind_t *p = (inb_evt_write_req_ind_t*)evt->param;
                
                if(p->handle == tpps_get_svc_hdl() + TPP_IDX_NTF_VAL_CFG)
                {
                    if(p->value[1] == 0x00 && p->value[0] == 0x01)
                    {
                        PRINTD(DBG_TRACE, "Notify enable\r\n");
                        tppsNtfEnabled = true;
                    }
                    else if(p->value[1] == 0x00 && p->value[0] == 0x00)
                    {
                        PRINTD(DBG_TRACE, "Notify disable\r\n");
                        tppsNtfEnabled = false;
                    }
                }
                else if(p->handle == tpps_get_svc_hdl() + TPP_IDX_WR_DATA_VAL)
                {
                    tpps_receive_write(p->conidx, p->value, p->length);
                }
            }
        break;
        
        default:
            break;
    }
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
    
    //UART of data passthrough
    uartPtHdl = hal_uart_open(UART1_ID, 115200, 8, 1, 0, 0, 1, UART_RT_HALF_FULL, 0, 0);
    if(uartPtHdl == NULL)
        PRINTD(DBG_TRACE, "UART open error.\r\n");
    
    uartRxDef.pthread = uart_receive_task;
    uartRxDef.instances = 1;
    uartRxDef.tpriority = osPriorityNormal;
    uartRxDef.stacksize = CFG_OS_USR_PRIV_TASK_TOTAL_STACK_SIZE; 
    
    osThreadId uartRxThreadId = osThreadCreate(&uartRxDef, NULL);
    if(uartRxThreadId == NULL)
        PRINTD(DBG_TRACE, "UART receive thread create error.\r\n");
    
    //BLE init
    ble_config(false, ble_app_event_callback);
    
    //Start advertisng
    start_adv();
    
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
