#include "in_config.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "in_arm.h"
#include "in_debug.h"
#include "hal_uart.h"
#include "hal_gpio.h"
#include "hal_power.h"
#include "hal_ir.h"
#include "hal_audio.h"
#include "hal_clk.h"
#include "hal_keyboard.h"
#include "hal_global.h"

#include "cmsis_os.h"

#include "msg.h"
#include "ble_test.h"
#include "gap_test.h"

#include "prf_tpps.h"


//Timer for tpps notification
void tpps_ntf_tmr_callback(void const *arg);
osTimerId tppsNtfTimerId;
osTimerDef(tppsNtfTimer, tpps_ntf_tmr_callback);

void tpps_ntf_tmr_callback(void const *arg)
{
    static uint8_t testData[20] = {0};
    static uint8_t i = 0;
    msg_tpps_ntf_t *msg;
    
    if(!tppsIsConnected)
    {
        osTimerStop(tppsNtfTimerId);
        return;
    }
    
    msg = malloc(sizeof(msg_tpps_ntf_t));
    if(!msg)
    {
        PRINTD(DBG_TRACE, "%s no memory.\r\n", __func__);
        return;
    }
    
    testData[0] = i++;
    msg->msg_id = MSG_TPPS_NTF;
    msg->conIndex = 0;
    msg->length = 20;
    memcpy(msg->data, testData, msg->length);
    
    msg_put(msg);
}

int handle_msg(msg_t *p_msg)
{
	//PRINTD(DBG_TRACE, "main evt %d...\r\n", p_msg->msg_id);
	
	switch (p_msg->msg_id) 
	{
        default:
            handle_default_msg(p_msg);
            break;
	}
    return 0;
}

/*
 * main: This is actually main task. 
 *	Note: The _main_init in the RTX_CM_lib.h is 
 *				main entry routine (OS is initialized 
 *				in there).
 */

int main (void)
{
	//Initialize platform.
	hal_global_post_init();
    
	PRINTD(DBG_TRACE, "----------------\r\n");
	PRINTD(DBG_TRACE, "main start...\r\n");

	//MessageQ for main thread.
	msg_init();

    //Timer for send notification
	tppsNtfTimerId = osTimerCreate(osTimer(tppsNtfTimer), osTimerPeriodic, NULL);
	if(tppsNtfTimerId == NULL)
    {
		PRINTD(DBG_TRACE, "Timer tppsNtfTimerId create failed.\r\n");
		return 0;
	}
    
    //BLE init
    ble_config(0);
    
    //Start advertisng
    if(start_adv())
        return 0;
    
    //Wait for message
	while(1)
    {        
		msg_t *p_msg;
        
        p_msg = msg_get(osWaitForever);
		if(!p_msg)
			break;

		handle_msg(p_msg);
		
		p_msg = msg_free(p_msg);
	}	
}



