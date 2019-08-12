#ifndef __PRF_TPPC_H
#define __PRF_TPPC_H

#include <stdint.h>
#include <stdbool.h>

#include "prf_tpp_common.h"


extern bool tppcIsConnected;
extern uint8_t tppServiceHandle;
bool isTppsDevice(uint8_t *advData, uint8_t advLen);
int tppc_cfg_notify(int conIdx, bool enable);
int tppc_send_write(int conIdx, uint8_t *buffer , uint8_t len);
void tppc_receive_notify(int conIdx, uint8_t *buffer , uint8_t len);

#endif
