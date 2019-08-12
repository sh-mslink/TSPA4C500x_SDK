#ifndef __PRF_TPPS_H
#define __PRF_TPPS_H

#include <stdint.h>

#include "prf_tpp_common.h"


extern bool tppsIsConnected;
extern uint16_t g_TppPrimarySvc_shl;
//extern uint16_t g_TppSecondarySvc_shl;

int tpps_add_svc(void);
int tpps_send_notify(int conIdx, uint8_t *buffer , uint8_t len);
void tpps_receive_write(int conIdx, uint8_t *buffer , uint8_t len);

#endif
