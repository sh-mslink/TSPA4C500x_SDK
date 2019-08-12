#include <stdlib.h>

#include "msg.h"

//MessageQ for main thread.
osMessageQId h_msg_q_id = NULL;
osMessageQDef(bmsg, 32, void);

int msg_init(void)
{
	h_msg_q_id = osMessageCreate(osMessageQ(bmsg), NULL);
    
    return 0;
}

int msg_put(void* msg)
{
	int status = 0;
	
	/// Post a message to main task 
	if (h_msg_q_id != NULL){
		status = osMessagePut(h_msg_q_id, (uint32_t)msg, 0);
		if (status != osOK) {
			PRINTD(DBG_ERR, "line:%d  OS error,%d\r\n", __LINE__, status);
		}
	}
	return status;
}

msg_t* msg_get(uint32_t millisec)
{
	osEvent evt;
	
	if (h_msg_q_id != NULL){
		evt = osMessageGet(h_msg_q_id, millisec);
		if (evt.status != osEventMessage) {
			PRINTD(DBG_TRACE, "evt is  not msg 0x%x...\r\n", evt.status);
			return NULL;
		}
		return (msg_t*)evt.value.p;
	}
	return NULL;
}

msg_t* msg_free(msg_t *p_msg)
{
	if (p_msg)
		free(p_msg);
	return NULL;
}
