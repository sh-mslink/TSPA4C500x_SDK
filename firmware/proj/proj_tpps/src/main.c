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

#ifdef CFG_PROJ_TPPS
#define ROLE    0  
#endif

//Timer for tpps notification
void tpps_ntf_tmr_callback(void const *arg);
osTimerId tppsNtfTimerId;
osTimerDef(tppsNtfTimer, tpps_ntf_tmr_callback);

void tpps_ntf_tmr_callback(void const *arg)
{
    static uint8_t testData[20] = {0};
    static uint8_t i = 0;
    msg_tpps_ntf_t *msg;
    
    msg = malloc(sizeof(msg_tpps_ntf_t));
    if(!msg)
        PRINTD(DBG_TRACE, "%s no memory.\r\n", __func__);
    
    testData[0] = i++;
    msg->msg_id = MSG_TPPS_NTF;
    msg->length = 20;
    memcpy(msg->data, testData, msg->length);
    
    msg_put(msg);    
}

#if (CFG_MEMORY_TRACK==1)
//Timer for memory track, optional
osTimerDef(bmem, ble_mem_usage_tmr_callback);

void ble_mem_usage_tmr_callback(void const *arg)
{
	int max;
	inb_mem_usage_t muse;

	inb_get_mem_usage(&muse);
	max = inb_get_max_mem_usage();

	PRINTD(DBG_TRACE, "--- mem: %d,%d,%d,%d,%d ---\r\n", muse.retn_mem_env_mem_usage, muse.retn_mem_db_mem_usage, muse.retn_mem_msg_mem_usage, muse.non_retn_mem_usage, max);
}
#endif

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

	tppsNtfTimerId = osTimerCreate(osTimer(tppsNtfTimer), osTimerPeriodic, NULL);
	if(tppsNtfTimerId == NULL)
    {
		PRINTD(DBG_TRACE, "Timer tppsNtfTimerId create failed.\r\n");
		return 0;
	}
    
    //BLE init
    ble_config(ROLE);
    
    if(!ROLE)
    {
		if(start_adv())
			return 0;
	} 
    else
        return 0;
                    
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


