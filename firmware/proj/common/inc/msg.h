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
#if CFG_PRF_HOGPD_EN
    MSG_HOGPD_NTF_SEND,
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

#if CFG_PRF_HOGPD_EN
typedef struct
{
    int msgId;
    int conIdx;
    inb_hogpd_report_info_t report;
}
msg_hogpd_ntf_send_t;
#endif


int msg_init(void);
int msg_put(void* msg);
msg_t* msg_get(uint32_t millisec);
msg_t* msg_free(msg_t *msg);

#endif
