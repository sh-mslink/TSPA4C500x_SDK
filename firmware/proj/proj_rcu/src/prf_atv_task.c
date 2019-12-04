#include "in_debug.h"

#include "prf_atv_task.h"


#if (MSRCU_VOICE_ENABLE && MSRCU_BLE_VOICE_ATV_ENABLE)

extern void msrcu_dev_audio_atv_set_sample_rate(uint16_t sampleRate);

extern void user_rcu_voice_start(void);
extern void user_rcu_voice_stop(void);

extern int atv_voice_char_rx_send(int conIdx, uint8_t *buffer, uint8_t len);
extern int atv_voice_char_ctl_send(int conIdx, uint8_t *buffer, uint8_t len);

void atv_task_cmd_send(int conIdx, uint8_t *buffer, uint8_t len);

static bool atvSendEnable = false;

static void set_caps_resp_cmd(uint8_t *cmd)
{
    cmd[0] = ATVV_CHAR_CTL_GET_CAPS_RESP_CMD;
    cmd[1] = ATVV_VERSION_MAJOR;
    cmd[2] = ATVV_VERSION_MINOR;
    cmd[3] = (ATVV_CODECS_SUPPORTED >> 8) & 0xff;
    cmd[4] = (ATVV_CODECS_SUPPORTED) & 0xff;
    cmd[5] = (ATVV_BYTES_PER_FRAME >> 8) & 0xff;
    cmd[6] = (ATVV_BYTES_PER_FRAME) & 0xff;
    cmd[7] = (ATVV_BYTES_PER_CHAR >> 8) & 0xff;
    cmd[8] = (ATVV_BYTES_PER_CHAR) & 0xff;
}

void atv_task_send_enable(void)
{
    atvSendEnable = true;
}

void atv_task_send_disable(void)
{
    atvSendEnable = false;
}

bool atv_task_send_is_enabled(void)
{
    return atvSendEnable;
}

void atv_task_cmd_receive(int conIdx, uint8_t *buffer, uint8_t len)
{
    if(buffer == NULL || len == 0)
        return;
    
    switch(buffer[0])
    {
        case ATVV_CHAR_TX_ATV_GET_CAPS_CMD:
        {
//            if(len != ATVV_CHAR_TX_ATV_GET_CAPS_LEN)
//                break;
            PRINTD(DBG_TRACE, "ATV version:0x%02X%02X.\r\n", buffer[1], buffer[2]);
            PRINTD(DBG_TRACE, "ATV codecs supported:0x%02X%02X.\r\n", buffer[3], buffer[4]);
        
            uint8_t rspCmd[ATVV_CHAR_CTL_GET_CAPS_RESP_LEN] = {0};
            set_caps_resp_cmd(rspCmd);
            atv_task_cmd_send(conIdx, rspCmd, ATVV_CHAR_CTL_GET_CAPS_RESP_LEN);
            
            break;
        }
        
        case ATVV_CHAR_TX_ATV_MIC_OPEN_CMD:
        {
//            if(len != ATVV_CHAR_TX_ATV_MIC_OPEN_LEN)
//                break;
            PRINTD(DBG_TRACE, "ATV MIC open with codec:0x%02X%02X.\r\n", buffer[1], buffer[2]);
            
            if(buffer[1] == 0x00 && buffer[2] == 0x01)
            {
                msrcu_dev_audio_atv_set_sample_rate(8000);
                user_rcu_voice_start();
            }
            else if(buffer[1] == 0x00 && buffer[2] == 0x02)
            {
                msrcu_dev_audio_atv_set_sample_rate(16000);
                user_rcu_voice_start();
            }
            else
                PRINTD(DBG_TRACE, "ATV MIC open codec error.\r\n");
            
            break;
        }
        
        case ATVV_CHAR_TX_ATV_MIC_CLOSE_CMD:
        {
//            if(len != ATVV_CHAR_TX_ATV_MIC_CLOSE_LEN)
//                break;
            PRINTD(DBG_TRACE, "ATV MIC close.\r\n");
            
            user_rcu_voice_stop();
            
            break;
        }
        
        default:
            break;
    }
}

void atv_task_cmd_send(int conIdx, uint8_t *buffer, uint8_t len)
{
    if(!atv_task_send_is_enabled())
        return;
    
    atv_voice_char_ctl_send(conIdx, buffer, len);
}

void atv_task_audio_send(int conIdx, uint8_t *buffer, uint8_t len)
{
    if(!atv_task_send_is_enabled())
        return;
    
    atv_voice_char_rx_send(conIdx, buffer, len);
}
#endif
