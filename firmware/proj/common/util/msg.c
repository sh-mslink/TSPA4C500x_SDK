#include <stdlib.h>

#include "msg.h"

//MessageQ for main thread.
static osMessageQId mainMsgQId = NULL;
osMessageQDef(mMsg, 32, void);

int msg_init(void)
{
    mainMsgQId = osMessageCreate(osMessageQ(mMsg), NULL);
    
    return 0;
}

int msg_put(void* msg)
{
    int status = 0;
    
    /// Post a message to main task 
    if(mainMsgQId)
    {
        status = osMessagePut(mainMsgQId, (uint32_t)msg, 0);
        if(status != osOK)
            PRINTD(DBG_ERR, "msg_put OS error, 0x%X\r\n", status);
    }
    
    return status;
}

msg_t* msg_get(uint32_t millisec)
{
    osEvent evt;
    
    if(mainMsgQId)
    {
        evt = osMessageGet(mainMsgQId, millisec);
        if(evt.status != osEventMessage)
        {
            PRINTD(DBG_TRACE, "evt is  not msg 0x%x...\r\n", evt.status);
            return NULL;
        }
        return (msg_t*)evt.value.p;
    }
    
    return NULL;
}

msg_t* msg_free(msg_t *msg)
{
    if(msg)
        free(msg);
    
    return NULL;
}
