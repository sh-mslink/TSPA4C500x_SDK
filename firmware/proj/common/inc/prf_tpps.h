#ifndef __PRF_TPPS_H
#define __PRF_TPPS_H

#include "in_config.h"

#if CFG_PRF_TPPS_EN

#include <stdint.h>
#include "prf_tpp_common.h"


uint16_t tpps_get_svc_hdl(void);
int tpps_add_svc(void);
int tpps_send_notify(int conIdx, uint8_t *buffer , uint8_t len);

#endif

#endif
