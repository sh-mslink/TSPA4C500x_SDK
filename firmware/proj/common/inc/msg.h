#ifndef __MSG_H__
#define __MSG_H__

#include ".\ble\inb_api.h"

#ifdef CFG_PROJ_RCU
#include "msrcu_common.h"
#endif

/*
 * Enumeration
 ****************************************************************************************
 */
enum
{
    MSG_START_CONNECT,
#ifdef CFG_PROJ_RCU
    MSG_MSRCU_MOTION_MOUSE_SEND,
#endif
};

/*
 * Types
 ****************************************************************************************
 */
typedef struct
{
    int msgId;
}
msg_t;

typedef struct
{
    int msgId;
    inb_bdaddr_t addr;
}
msg_start_connect_t;

#ifdef CFG_PROJ_RCU
typedef struct
{
    int msgId;
    msrcuMouseButton_t button;
    msrcuMotionMouse_t mouse;
}
msg_msrcu_motion_mouse_send_t;
#endif


int msg_init(void);
int msg_put(void* msg);
msg_t* msg_get(uint32_t millisec);
msg_t* msg_free(msg_t *msg);

#endif
