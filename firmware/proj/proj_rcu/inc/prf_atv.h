#ifndef __PRF_ATV_H
#define __PRF_ATV_H

#include <stdint.h>
#include <stdbool.h>

#include "msrcu_common.h"


#if (MSRCU_VOICE_ENABLE && MSRCU_BLE_VOICE_ATV_ENABLE)

#define ATVV_SERVICE_UUID    "\x64\xB6\x17\xF6\x01\xAF\x7D\xBC\x05\x4F\x21\x5A\x01\x00\x5E\xAB"
#define ATVV_CHAR_TX_UUID    "\x64\xB6\x17\xF6\x01\xAF\x7D\xBC\x05\x4F\x21\x5A\x02\x00\x5E\xAB"
#define ATVV_CHAR_RX_UUID    "\x64\xB6\x17\xF6\x01\xAF\x7D\xBC\x05\x4F\x21\x5A\x03\x00\x5E\xAB"
#define ATVV_CHAR_CTL_UUID   "\x64\xB6\x17\xF6\x01\xAF\x7D\xBC\x05\x4F\x21\x5A\x04\x00\x5E\xAB"

enum
{
    ATVV_IDX_CHAR_TX,
    ATVV_IDX_CHAR_TX_VAL,
    
    ATVV_IDX_CHAR_RX,
    ATVV_IDX_CHAR_RX_VAL,
    ATVV_IDX_CHAR_RX_CFG,
    
    ATVV_IDX_CHAR_CTL,
    ATVV_IDX_CHAR_CTL_VAL,
    ATVV_IDX_CHAR_CTL_CFG,
    
    ATVV_IDX_NB,
};


extern bool atvIsConnected;
extern uint16_t g_AtvPrimarySvc_shl;
//extern uint16_t g_AtvSecondarySvc_shl;

int atv_add_svc(void);
void atv_voice_char_tx_receive(int conIdx, uint8_t *buffer , uint8_t len);
int atv_voice_char_rx_send(int conIdx, uint8_t *buffer, uint8_t len);
int atv_voice_char_ctl_send(int conIdx, uint8_t *buffer, uint8_t len);

#endif
#endif
