#ifndef __PRF_TPPC_H
#define __PRF_TPPC_H

#include "in_config.h"

#if CFG_PRF_TPPC_EN

#include <stdint.h>
#include <stdbool.h>

#include "prf_tpp_common.h"


int tppc_cfg_notify(int conIdx, uint16_t svcHdl, bool enable);
int tppc_send_write(int conIdx, uint16_t svcHdl, uint8_t *buffer , uint8_t len);

#endif
#endif
