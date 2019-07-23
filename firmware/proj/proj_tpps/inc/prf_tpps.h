#ifndef __MSRCU_PRF_TPPS_H
#define __MSRCU_PRF_TPPS_H

#include "stdint.h"

///Attributes State Machine
enum
{
    TPPS_IDX_SVC,
    
    TPPS_IDX_RX_DATA_CHAR,
    TPPS_IDX_RX_DATA_VAL,
    TPPS_IDX_RX_DATA_USER_DESP,

    TPPS_IDX_VAL_CHAR,
    TPPS_IDX_VAL,
    TPPS_IDX_VAL_NTF_CFG,

    TPPS_IDX_NB,
};

extern uint16_t g_TppPrimarySvc_shl;
//extern uint16_t g_TppSecondarySvc_shl;

int tpps_add_svc(void);
int tpps_send_notify(uint8_t *buffer , uint8_t len);
int tpps_receive_write(uint8_t *buffer , uint8_t len);

#endif

