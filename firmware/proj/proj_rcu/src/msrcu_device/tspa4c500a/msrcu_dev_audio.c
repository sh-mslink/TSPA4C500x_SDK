/**
 ****************************************************************************************
 *
 * @file msrcu_dev_audio.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
/* Include Files
 ****************************************************************************************
 */
#include "msrcu_dev_system.h"
#include "msrcu_dev_ble.h"

/* Macro Definition
 ****************************************************************************************
 */
#define PDM_CLK                 (1600000)

#define VOICE_SAMPLE_RATE       VOICE_SAMPLE_RATE_16K//no use for atv voice
#define VOICE_SAMPLE_GAIN       (256)


#if MSRCU_BLE_VOICE_ATV_ENABLE
#define ADPCM_BLOCK_SAMPLE      ((ATVV_BYTES_PER_FRAME - 6) * 2)
#define ADPCM_BLOCK_SIZE_DEV    (ATVV_BYTES_PER_FRAME - 3)
#define VOICE_BLE_PKG_SIZE      (ATVV_BYTES_PER_CHAR)
#else
#if (VOICE_SAMPLE_RATE == 8000)
#define ADPCM_BLOCK_SAMPLE      (128)
#elif (VOICE_SAMPLE_RATE == 16000)
#define ADPCM_BLOCK_SAMPLE      (475)
#endif

#define ADPCM_BLOCK_SIZE        (uint32_t)(ADPCM_BLOCK_SAMPLE / 2 + 4)
#define ADPCM_BLOCK_SIZE_DEV    (ADPCM_BLOCK_SIZE - 1)

#if (VOICE_SAMPLE_RATE == 8000)
#define VOICE_BLE_PKG_SIZE      (20)
#define VOICE_BLE_PKG_DATA_SIZE (17)
#elif (VOICE_SAMPLE_RATE == 16000)
#define VOICE_BLE_PKG_SIZE      (ADPCM_BLOCK_SIZE + 3)
#define VOICE_BLE_PKG_DATA_SIZE (ADPCM_BLOCK_SIZE)
#endif

#define VOICE_BLE_PKG_HEAD_IDX  (0)
#define VOICE_BLE_BLK_NB_H_IDX  (1)
#define VOICE_BLE_BLK_NB_L_IDX  (2)
#define VOICE_BLE_PKG_DATA_IDX  (3)
#define VOICE_BLE_PKG_HEAD      (0x0A)
#endif

#define AUDIO_HAL_BUF_LENGTH    (CFG_SMEM_AUDIO_RX & 0xFFFF)

enum
{
#if MSRCU_BLE_VOICE_ATV_ENABLE
    AUDIO_ATV_SEARCH_KEY,
    AUDIO_ATV_AUDIO_START,
#endif
    AUDIO_ENC_START,
    AUDIO_ENC_GETSEND,
    AUDIO_ENC_STOP,
};

/* Enum Definition
 ****************************************************************************************
 */

/* Struct Definition
 ****************************************************************************************
 */

/* Function Declaration
 ****************************************************************************************
 */
msrcuErr_t msrcu_dev_audio_stop(void);

/* Global Variable
 ****************************************************************************************
 */
static osThreadDef_t auEncDef;
static osMessageQDef(auEncMsg, 128, NULL);
static osMessageQId msrcuAuEncMsgQId;

static bool gAudioIsStart = false;
static uint16_t gAudioSampleRate = false;//Audio sample rate
static uint16_t gAdpcmBlkNb = 0;//Number of adpcm blocks
static uint8_t gHalAdBuf[AUDIO_HAL_BUF_LENGTH] = {0};//Buffer of hal audio

/* Function Definition
 ****************************************************************************************
 */
#if MSRCU_BLE_VOICE_ATV_ENABLE
void msrcu_dev_audio_atv_set_sample_rate(uint16_t sampleRate)
{
    gAudioSampleRate = sampleRate;
    MSPRINT("ATV set sample rate: %dHz.\r\n", sampleRate);
}
#endif

static msrcuErr_t msrcu_dev_audio_ble_package_send(uint8_t *buf, uint8_t len)
{    
//    for(uint32_t i = 0; i < voiceHidPkgSize; i++)
//        MSPRINT("%02X|", buf[i]);
//    MSPRINT("\r\n");
    
    msrcuErr_t err = ERR_NO_ERROR;
    
#if MSRCU_BLE_VOICE_ATV_ENABLE
    atv_task_audio_send(BLE_CON_IDX, buf, len);
#else
    msrcuBleHidReport_t *report;
    
    report = malloc(sizeof(msrcuBleHidReport_t));
    if(!report)
        return ERR_NO_MEMORY;
    
    report->conIndex = BLE_CON_IDX;
    report->instance = HID_VOICE_INSTANCE;
    report->length = len;
    memcpy(report->data, buf, report->length);
    
    err = msrcu_dev_ble_hid_send2(report);
    
    if(report)
        free(report);
#endif
    
    return err;
}

static msrcuErr_t msrcu_dev_audio_adpcm_block_callback(uint8_t *buf)
{
    uint16_t i = 0;
//    for(i = 0; i < ADPCM_BLOCK_SIZE_DEV; i++)
//        MSPRINT("%02X ", buf[i]);
//    MSPRINT("\r\n");
//    int sample = buf[0] * 256 + buf[1];
//    if(sample >= 32768)
//        sample -= 65536;
//    MSPRINT("%d %d", sample, buf[2]);
//    if(sample > 4096 || buf[2] > 88)
//        MSPRINT("--------");
//    MSPRINT("\r\n");
    
    msrcuErr_t err = ERR_NO_ERROR;
    uint8_t *sendBuf = malloc(VOICE_BLE_PKG_SIZE);
    if(!sendBuf)
        return ERR_NO_MEMORY;
    
#if MSRCU_BLE_VOICE_ATV_ENABLE
    uint8_t remainBytes = 0;
    
    //ATV head
    sendBuf[0] = (gAdpcmBlkNb >> 8) & 0xFF;
    sendBuf[1] = gAdpcmBlkNb & 0xFF;
    sendBuf[2] = 0x00;
    
    //1st package
    memcpy(sendBuf + 3, buf, VOICE_BLE_PKG_SIZE - 3);
    err = msrcu_dev_audio_ble_package_send(sendBuf, VOICE_BLE_PKG_SIZE);
    if(err)
        goto out;
    
    //middle packages
    for(i = 0; i < ATVV_BYTES_PER_FRAME / VOICE_BLE_PKG_SIZE - 1; i++)
    {
        memcpy(sendBuf, buf + (VOICE_BLE_PKG_SIZE - 3) + i * VOICE_BLE_PKG_SIZE, VOICE_BLE_PKG_SIZE);
        err = msrcu_dev_audio_ble_package_send(sendBuf, VOICE_BLE_PKG_SIZE);
        if(err)
            goto out;
    }
    
    //check remain bytes for last package
    remainBytes = ATVV_BYTES_PER_FRAME % VOICE_BLE_PKG_SIZE;
    if(remainBytes)
    {
        memcpy(sendBuf, buf + (ATVV_BYTES_PER_FRAME - 3 - remainBytes), remainBytes);
        err = msrcu_dev_audio_ble_package_send(sendBuf, remainBytes);
        if(err)
            goto out;
    }
#else
    sendBuf[VOICE_BLE_PKG_HEAD_IDX] = VOICE_BLE_PKG_HEAD;
    sendBuf[VOICE_BLE_BLK_NB_H_IDX] = (gAdpcmBlkNb >> 8) & 0xFF;
    sendBuf[VOICE_BLE_BLK_NB_L_IDX] = gAdpcmBlkNb & 0xFF;
    
    //1st package
    sendBuf[VOICE_BLE_PKG_DATA_IDX] = buf[1];//match endianness of decoder on peer device
    sendBuf[VOICE_BLE_PKG_DATA_IDX + 1] = buf[0];//match endianness of decoder on peer device
    sendBuf[VOICE_BLE_PKG_DATA_IDX + 2] = 0;
    sendBuf[VOICE_BLE_PKG_DATA_IDX + 3] = buf[2];
    memcpy(sendBuf + VOICE_BLE_PKG_DATA_IDX + 4, buf + 3, VOICE_BLE_PKG_DATA_SIZE - 4);
    err = msrcu_dev_audio_ble_package_send(sendBuf, VOICE_BLE_PKG_SIZE);
    if(err)
        goto out;
    
#if (VOICE_SAMPLE_RATE == 8000)
    //2nd~4th packages
    for(i = 1; i <= 3; i++)
    {
        memcpy(sendBuf + VOICE_BLE_PKG_DATA_IDX, buf + VOICE_BLE_PKG_DATA_SIZE * i - 1, VOICE_BLE_PKG_DATA_SIZE);
        err = msrcu_dev_audio_ble_package_send(sendBuf, VOICE_BLE_PKG_SIZE);
        if(err)
            goto out;
    }
#endif
#endif
    
out:
    if(sendBuf)
        free(sendBuf);
	
    return err;
}

static void msrcu_dev_audio_task(const void *arg)
{
    osEvent osEvt;
#if !MSRCU_BLE_VOICE_ATV_ENABLE
    static uint8_t hidBuf[VOICE_BLE_PKG_SIZE] = {0};//temp buffer for HID package
#endif
    static uint8_t adBlkBuf[ADPCM_BLOCK_SIZE_DEV] = {0};//temp buffer to store current ADPCM block
    static uint8_t halAdLen = 0;//bytes stored in gHalAdBuf
    static uint32_t byteCt = 0;//total bytes get from hal audio
    static uint32_t adLen = 0;
    uint32_t halBlkCt = 0;
    uint32_t len = 0;//temp len of hal_audio_encode_process
    int res = 0;//temp result
    
    while(1)
    {
		osEvt = osMessageGet(msrcuAuEncMsgQId, osWaitForever);
		if(osEvt.status != osEventMessage)
			continue;
        
        switch(osEvt.value.v)
        {
#if MSRCU_BLE_VOICE_ATV_ENABLE
            case AUDIO_ATV_SEARCH_KEY://ATVV_CHAR_CTL_START_SEARCH
            {
                if(BLE_STATE_READY == msrcu_dev_ble_get_state())
                {
                    uint8_t cmd[ATVV_CHAR_CTL_START_SEARCH_LEN] = {0};
                    cmd[0] = ATVV_CHAR_CTL_START_SEARCH_CMD;
                    atv_task_cmd_send(BLE_CON_IDX, cmd, ATVV_CHAR_CTL_START_SEARCH_LEN);
                }
            }
            break;
            
            case AUDIO_ATV_AUDIO_START://ATVV_CHAR_CTL_AUDIO_START
            {
                if(BLE_STATE_READY == msrcu_dev_ble_get_state())
                {
                    uint8_t cmd[ATVV_CHAR_CTL_AUDIO_START_LEN] = {0};
                    cmd[0] = ATVV_CHAR_CTL_AUDIO_START_CMD;
                    atv_task_cmd_send(BLE_CON_IDX, cmd, ATVV_CHAR_CTL_AUDIO_START_LEN);
                    
                    res = osMessagePut(msrcuAuEncMsgQId, AUDIO_ENC_START, 0);
                    if(res)
                        MSPRINT("AUDIO_ENC_GETSEND MSG put err:%d\r\n", res);
                }
            }
            break;
#endif
            case AUDIO_ENC_START:
            {
                //MSPRINT("AT\r\n");
                if(gAudioIsStart && BLE_STATE_READY == msrcu_dev_ble_get_state())
                {
                    gAdpcmBlkNb = 0;
                    adLen = 0;
                    
#if !MSRCU_BLE_VOICE_ATV_ENABLE
                    //voice start package
                    hidBuf[VOICE_BLE_PKG_HEAD_IDX] = VOICE_BLE_PKG_HEAD;
                    msrcu_dev_audio_ble_package_send(hidBuf, VOICE_BLE_PKG_SIZE);
#endif
                    res = hal_audio_enc_set_config(1, 0, PDM_CLK, gAudioSampleRate, 0, ADPCM_BLOCK_SIZE_DEV, VOICE_SAMPLE_GAIN);
                    MSPRINT("hal_audio_enc_set_config sample rate:%d.\r\n", gAudioSampleRate);
                    
                    if(res)
                    {
                        MSPRINT("hal_audio_enc_set_config err:%d.\r\n", res);
                        break;
                    }
                    
                    res = hal_audio_encode_start();
                    if(res)
                    {
                        MSPRINT("hal_audio_encode_start err:%d.\r\n", res);
                        break;
                    }
                    
                    res = osMessagePut(msrcuAuEncMsgQId, AUDIO_ENC_GETSEND, 0);
                    if(res)
                        MSPRINT("AUDIO_ENC_START MSG put err:%d.\r\n", res);
                }
            }
            break;
            
            case AUDIO_ENC_GETSEND:
            {
                //MSPRINT(".");
                if(gAudioIsStart && BLE_STATE_READY == msrcu_dev_ble_get_state())
                {
                    res = hal_audio_encode_process(gHalAdBuf + halAdLen, AUDIO_HAL_BUF_LENGTH - halAdLen, (uint16_t *)&len);
                    if(res)
                        MSPRINT("hal_audio_encode_process err:%d.\r\n", res);
                        //TODO
//                    MSPRINT("len %d\r\n", len);
                    if(len >= AUDIO_HAL_BUF_LENGTH / 4 * 3)
                        MSPRINT("Voice overflow warning:%d.\r\n", len);
                    if(len >= AUDIO_HAL_BUF_LENGTH - halAdLen)
                        MSPRINT("Voice overflow!!!\r\n");
                        //TODO
//                    for(uint32_t i = 0; i < len; i++)
//                        MSPRINT("%02X ", gHalAdBuf[halAdLen + i]);
//                    MSPRINT("\r\n");

                    adLen += len;
                    halAdLen += len;
                    byteCt += len;
//                    MSPRINT("%d ", byteCt);
                    
                    halBlkCt = 0;
                    while(adLen >= ADPCM_BLOCK_SIZE_DEV)
                    {
//                        MSPRINT("-ad %d, blk %d|0x%02X\r\n", adLen, gAdpcmBlkNb + 1, gAdpcmBlkNb + 1);
//                        for (i = 0; i < ADPCM_BLOCK_SIZE_DEV; i++)
//                            MSPRINT("%02X ", gHalAdBuf[halBlkCt * ADPCM_BLOCK_SIZE_DEV + i]);
//                        MSPRINT("\r\n");
                        memcpy(adBlkBuf, gHalAdBuf + halBlkCt * ADPCM_BLOCK_SIZE_DEV, ADPCM_BLOCK_SIZE_DEV);
                        halBlkCt++;
                        
                        //MSPRINT("gAdpcmBlkNb%d\r\n", gAdpcmBlkNb);
#if MSRCU_BLE_VOICE_ATV_ENABLE
                        if(msrcu_dev_audio_adpcm_block_callback(adBlkBuf))
                        {
                            msrcu_dev_audio_stop();
                            goto jumpOut;
                        }
                        
                        gAdpcmBlkNb++;
                        
                        if(gAdpcmBlkNb && (gAdpcmBlkNb % 15 == 0))//send ATVV_CHAR_CTL_AUDIO_SYNC per 15 block
                        {
                            uint8_t cmd[ATVV_CHAR_CTL_AUDIO_SYNC_LEN] = {0};
                            cmd[0] = ATVV_CHAR_CTL_AUDIO_SYNC_CMD;
                            cmd[1] = (gAdpcmBlkNb >> 8) & 0xFF;
                            cmd[2] = gAdpcmBlkNb & 0xFF;
                            atv_task_cmd_send(BLE_CON_IDX, cmd, ATVV_CHAR_CTL_AUDIO_SYNC_LEN);
                        }
                        
                        if(gAdpcmBlkNb == 0)//roll over
                        {
                            msrcu_dev_audio_stop();
                            goto jumpOut;
                        }
#else
                        gAdpcmBlkNb++;//start from 0x0001
                        if(gAdpcmBlkNb)
                        {
                            if(msrcu_dev_audio_adpcm_block_callback(adBlkBuf))
                            {
                                msrcu_dev_audio_stop();
                                goto jumpOut;
                            }
                        }
                        else//gAdpcmBlkNb reach to 0xFFFF
                        {
                            msrcu_dev_audio_stop();
                            goto jumpOut;
                        }
#endif
                        adLen -= ADPCM_BLOCK_SIZE_DEV;
                    }
                    halAdLen = adLen;
                    memcpy(gHalAdBuf, gHalAdBuf + halBlkCt * ADPCM_BLOCK_SIZE_DEV, halAdLen);
                    
                    res = osMessagePut(msrcuAuEncMsgQId, AUDIO_ENC_GETSEND, 0);
                    if(res)
                        MSPRINT("MSG put err:%d\r\n", res);
                }
            }
jumpOut:
            break;
            
            case AUDIO_ENC_STOP:
            {
                //MSPRINT("AP\r\n");
                res = hal_audio_encode_stop();
                if(res)
                    MSPRINT("AUDIO_ENC_STOP: hal_audio_encode_stop err:%d\r\n", res);
                
#if MSRCU_BLE_VOICE_ATV_ENABLE
                //atv voice stop package
                uint8_t cmd[ATVV_CHAR_CTL_AUDIO_STOP_LEN] = {0};
                cmd[0] = ATVV_CHAR_CTL_AUDIO_STOP_CMD;
                atv_task_cmd_send(BLE_CON_IDX, cmd, ATVV_CHAR_CTL_AUDIO_STOP_LEN);
#else
                //voice stop package
                hidBuf[VOICE_BLE_PKG_HEAD_IDX] = 0;
                if(BLE_STATE_READY == msrcu_dev_ble_get_state())
                    msrcu_dev_audio_ble_package_send(hidBuf, VOICE_BLE_PKG_SIZE);
#endif                
                MSPRINT("ADPCM total bytes: %d.\r\n", byteCt - adLen);
                MSPRINT("Voice time: %fs\r\n", 
                        1.0 * ADPCM_BLOCK_SAMPLE * (byteCt - adLen) / ADPCM_BLOCK_SIZE_DEV / gAudioSampleRate);
                
                byteCt = 0;
            }
            break;
            
            default:
            break;
        }
    }
}

msrcuErr_t msrcu_dev_audio_init(void)
{
    if(!msrcuEnv.enVoice)
        return ERR_NOT_SUPPORT;
    
    //device hal
    if(hal_audio_enc_open())
        return ERR_DEVICE_DRIVER; 
    if(hal_audio_enc_set_pdm_mic_inp(0, 1, 0))//left channel PDM_DATA0
        return ERR_DEVICE_DRIVER; 
    if(hal_audio_enc_set_predict_endianness(0))//big endian
        return ERR_DEVICE_DRIVER;
    
    //audio task & msg
    msrcuAuEncMsgQId = osMessageCreate(osMessageQ(auEncMsg), NULL);
    if(msrcuAuEncMsgQId == NULL)
        return ERR_OS;
    auEncDef.pthread = msrcu_dev_audio_task;
    auEncDef.instances = 1;
    auEncDef.tpriority = osPriorityNormal;
    auEncDef.stacksize = MSRCU_DEV_AUDIO_TASK_SIZE; 
    osThreadId msrcuDevAuEncId = osThreadCreate(&auEncDef, NULL);
    if(msrcuDevAuEncId == NULL)
        return ERR_OS; 
    
    gAudioSampleRate = VOICE_SAMPLE_RATE;
    
    return ERR_NO_ERROR;
}

#if MSRCU_BLE_VOICE_ATV_ENABLE
msrcuErr_t msrcu_dev_audio_atv_start(void)
{
    if(!msrcuEnv.enVoice)
        return ERR_NOT_SUPPORT;
    
    if(osMessagePut(msrcuAuEncMsgQId, AUDIO_ATV_SEARCH_KEY, 0))
        return ERR_OS;
    
    return ERR_NO_ERROR;
}
#endif

msrcuErr_t msrcu_dev_audio_start(void)
{
    if(!msrcuEnv.enVoice)
        return ERR_NOT_SUPPORT;
    
#if MSRCU_BLE_VOICE_ATV_ENABLE
    if(osMessagePut(msrcuAuEncMsgQId, AUDIO_ATV_AUDIO_START, 0))
#else
    if(osMessagePut(msrcuAuEncMsgQId, AUDIO_ENC_START, 0))
#endif
        return ERR_OS;
    
    gAudioIsStart = true;
    return ERR_NO_ERROR; 
}

msrcuErr_t msrcu_dev_audio_stop(void)
{
    if(!msrcuEnv.enVoice)
        return ERR_NOT_SUPPORT;
    
    if(osMessagePut(msrcuAuEncMsgQId, AUDIO_ENC_STOP, 0))
        return ERR_OS;
    
    gAudioIsStart = false;
    return ERR_NO_ERROR; 
}
