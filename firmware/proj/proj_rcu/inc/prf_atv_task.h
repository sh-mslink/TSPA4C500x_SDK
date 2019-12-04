#ifndef __PRF_ATV_TASK_H
#define __PRF_ATV_TASK_H

#include <stdint.h>

#include "msrcu_common.h"


#if (MSRCU_VOICE_ENABLE && MSRCU_BLE_VOICE_ATV_ENABLE)

//ATVV_CHAR_TX
#define ATVV_CHAR_TX_ATV_GET_CAPS_LEN   (5)
#define ATVV_CHAR_TX_ATV_GET_CAPS_CMD   (0x0A)

#define ATVV_CHAR_TX_ATV_MIC_OPEN_LEN   (3)
#define ATVV_CHAR_TX_ATV_MIC_OPEN_CMD   (0x0C)

#define ATVV_CHAR_TX_ATV_MIC_CLOSE_LEN  (1)
#define ATVV_CHAR_TX_ATV_MIC_CLOSE_CMD  (0x0D)


//ATVV_CHAR_RX


//ATVV_CHAR_CTL
#define ATVV_CHAR_CTL_AUDIO_STOP_LEN        (1)
#define ATVV_CHAR_CTL_AUDIO_STOP_CMD        (0x00)

#define ATVV_CHAR_CTL_AUDIO_START_LEN       (1)
#define ATVV_CHAR_CTL_AUDIO_START_CMD       (0x04)

#define ATVV_CHAR_CTL_DPAP_SELECT_LEN       (1)
#define ATVV_CHAR_CTL_DPAP_SELECT_CMD       (0x07)

#define ATVV_CHAR_CTL_START_SEARCH_LEN      (1)
#define ATVV_CHAR_CTL_START_SEARCH_CMD      (0x08)

#define ATVV_CHAR_CTL_AUDIO_SYNC_LEN        (3)
#define ATVV_CHAR_CTL_AUDIO_SYNC_CMD        (0x0A)

#define ATVV_CHAR_CTL_GET_CAPS_RESP_LEN     (9)
#define ATVV_CHAR_CTL_GET_CAPS_RESP_CMD     (0x0B)

#define ATVV_CHAR_CTL_MIC_OPEN_ERROR_LEN    (3)
#define ATVV_CHAR_CTL_MIC_OPEN_ERROR_CMD    (0x0C)


//ATVV Version
#define ATVV_VERSION_MAJOR      (0x00)//Version Draft
#define ATVV_VERSION_MINOR      (0x04)//Version 0.4

//ATVV Codecs
#define ATVV_CODECS_8K          (0x0001)//8kHz/16bit
//#define ATVV_CODECS_16K         (0x0002)//16kHz/16bit
#define ATVV_CODECS_8K_16K      (0x0003)//16kHz/16bit & 8kHz/16bit

#if (MSRCU_BLE_VOICE_SAMPLE_RATE == 8000)
#define ATVV_CODECS_SUPPORTED   ATVV_CODECS_8K
#elif (MSRCU_BLE_VOICE_SAMPLE_RATE == 16000)
#define ATVV_CODECS_SUPPORTED   ATVV_CODECS_8K_16K
#endif

//ATVV Bytes/Frame
#define ATVV_BYTES_PER_FRAME    (0x0086)//134

//ATVV Bytes/characteristic
#define ATVV_BYTES_PER_CHAR     (0x0014)//20


void atv_task_send_enable(void);
void atv_task_send_disable(void);
bool atv_task_send_is_enabled(void);
void atv_task_cmd_receive(int conIdx, uint8_t *buffer, uint8_t len);
void atv_task_cmd_send(int conIdx, uint8_t *buffer, uint8_t len);
void atv_task_audio_send(int conIdx, uint8_t *buffer, uint8_t len);

#endif
#endif
