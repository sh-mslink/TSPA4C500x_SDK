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

#include "evb_button.h"
#include "evb_led.h"


#define LED_REFRESH_TIME 500//ms


//BLE state flag
static bool advIsOn = false;
static bool bleIsConnected = false;

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

static void button_evt_callback(uint32_t *code, buttonState *state)
{
    switch(*state)
    {
        case BUTTON_PRESS:
            PRINTD(DBG_TRACE, "Button %d press.\r\n", *code);
            break;
        case BUTTON_RELEASE:
            PRINTD(DBG_TRACE, "Button %d release.\r\n", *code);
            break;
        case BUTTON_LONG_PRESS:
            PRINTD(DBG_TRACE, "Button %d long press.\r\n", *code);
            break;
        default:
            break;
    }
    
    switch(*code)
    {
        case 8://Button 8
            {
                if(*state == BUTTON_RELEASE)
                {
                    if(!bleIsConnected)
                    {
                        if(advIsOn)
                        {
                            if(stop_adv())
                                return;
                            //GAP_EVT_ACTIVITY_STOP
                        }
                        else
                        {
                            if(start_adv())
                                return;
                            advIsOn = true;
                        }
                    }
                }
            }
            break;
            
        default:
            break;
    }
}

static void led_tmr_callback(void const *arg)
{
    if(evb_led_on_number_get())
        evb_led_all_set(LED_OFF);
    else
    {
        if(bleIsConnected)
            evb_led_single_set(LED_B, LED_ON);
        else if(advIsOn)
            evb_led_single_set(LED_R, LED_ON);
    }
}

static void ble_app_event_callback(inb_evt_t *evt)
{
    switch(evt->evt_id)
    {
        case GAP_EVT_ACTIVITY_STOP:
            {
                advIsOn = false;
            }
            break;
            
        case GAP_EVT_CONN_REQ:
            {
                inb_evt_conn_req_t *p = (inb_evt_conn_req_t *)evt->param;
                
                PRINTD(DBG_TRACE, "Connected, idx:%d, ", p->conidx);
                PRINTD(DBG_TRACE, "clk accuracy:%d, ", p->clk_accuracy);
                PRINTD(DBG_TRACE, "addr type:%d, ", p->peer_addr_type);
                PRINTD(DBG_TRACE, "addr:0x %02X %02X %02X %02X %02X %02X, ", 
                        p->peer_addr.addr[0], p->peer_addr.addr[1], p->peer_addr.addr[2], 
                        p->peer_addr.addr[3], p->peer_addr.addr[4], p->peer_addr.addr[5]);
                PRINTD(DBG_TRACE, "interval:0x%X, ", p->con_interval);
                PRINTD(DBG_TRACE, "latency:%d, ", p->con_latency);
                PRINTD(DBG_TRACE, "timeout:%dms.\r\n", p->sup_to * 10);
                
                bleIsConnected = true;
            }
            break;
        
        case GAP_EVT_DISCONNECT:
            {
                inb_evt_disc_ind_t *p = (inb_evt_disc_ind_t *)evt->param;
                
                PRINTD(DBG_TRACE, "Disconnected, idx:%d, reason:0x%02X.\r\n", p->conidx, p->reason);
                
                bleIsConnected = false;
                
                if(start_adv())
                    return;
                advIsOn = true;
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

static void board_init(void)
{
    evb_button_init(button_evt_callback);
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
    PRINTD(DBG_TRACE, "Wafer Version: A%d\r\n", wafer_get_version());
    
    //EVB init
    board_init();
    
    //MessageQ for main thread
    msg_init();
    
    //BLE init
    ble_config(false, ble_app_event_callback);
    
    //Start advertisng
    if(start_adv())
        return 0;
    advIsOn = true;
    
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
