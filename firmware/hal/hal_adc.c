#include "in_config.h"
/**
 ****************************************************************************************
 *
 * @file hal_adc.c
 *
 * @brief ADC driver implementation file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */
#if CFG_SADC_EN
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include ".\hal\hal_adc.h"
#include ".\hal\hal_efuse.h"
#include ".\hal\hal_power.h"
#include ".\hal\hal_clk.h"
//#include "hal/hal_smem.h"
#include "in_arm.h"
#include "in_debug.h"
#include "in_irq.h"
#include "in_mmap.h"

#define READ_DELAY 200 // is it good?
#define ADC_CLK 1000000
osSemaphoreDef(adc_semaphore);
osMutexDef(adc_mutex);
static adc_dev_t adc_dev = { 0 };
static void adc_read_fifo(adc_dev_t* pd);
static void adc_temp_sensor_enable()
{
    uint32_t reg = aon_read(AON_REG_PMU_MISC_CTRL);
    reg |= AON_REG_PMU_MISC_CTRL_CTL_TEMP_SENS_EN;
    aon_write(AON_REG_PMU_MISC_CTRL, reg);
}
static void adc_temp_sensor_disable()
{
    uint32_t reg = aon_read(AON_REG_PMU_MISC_CTRL);
    reg &= ~AON_REG_PMU_MISC_CTRL_CTL_TEMP_SENS_EN;
    aon_write(AON_REG_PMU_MISC_CTRL, reg);
}

static void adc_vbat_sensor_enable()
{
    uint32_t reg = aon_read(AON_REG_PMU_MISC_CTRL);
    reg |= AON_REG_PMU_MISC_CTRL_CTL_VBAT_SENS_EN;
    aon_write(AON_REG_PMU_MISC_CTRL, reg);
}
static void adc_vbat_sensor_disable()
{
    uint32_t reg = aon_read(AON_REG_PMU_MISC_CTRL);
    reg &= ~AON_REG_PMU_MISC_CTRL_CTL_VBAT_SENS_EN;
    aon_write(AON_REG_PMU_MISC_CTRL, reg);
}
void adc_hw_ch_enable(int ch)
{
    uint32_t reg = aon_read(AON_REG_GPIO_2_ANA_ON);
    switch (ch) {
    case ADC_CH14:
        adc_vbat_sensor_enable();
        break;
    case ADC_CH15:
        adc_temp_sensor_enable();
        break;
    case ADC_CH10:
        reg |= 0x1;
        aon_write(AON_REG_GPIO_2_ANA_ON, reg);
        break;
    case ADC_CH1:
    case ADC_CH2:
    case ADC_CH3:
    case ADC_CH4:
    case ADC_CH5:
    case ADC_CH6:
    case ADC_CH7:
    case ADC_CH8:
        reg |= 0x1 << ch;
        aon_write(AON_REG_GPIO_2_ANA_ON, reg);
        break;
    default:
        break;
    }
}
static void adc_hw_ch_disable(int ch)
{
    uint32_t reg = aon_read(AON_REG_GPIO_2_ANA_ON);
    switch (ch) {
    case ADC_CH14:
        adc_vbat_sensor_disable();
        break;
    case ADC_CH15:
        adc_temp_sensor_disable();
        break;
    case ADC_CH10:
        reg &= ~0x1;
        aon_write(AON_REG_GPIO_2_ANA_ON, reg);
        break;
    case ADC_CH1:
    case ADC_CH2:
    case ADC_CH3:
    case ADC_CH4:
    case ADC_CH5:
    case ADC_CH6:
    case ADC_CH7:
    case ADC_CH8:
        reg &= ~(0x1 << ch);
        aon_write(AON_REG_GPIO_2_ANA_ON, reg);
        break;
    default:
        break;
    }
}
#if CFG_PM_EN
static int adc_pm_state(void* arg, uint32_t* sleep_duration)
{
    adc_dev_t* pd = (adc_dev_t*)arg;

    *sleep_duration = PM_MAX_SLEEP_TIME;
    return pd->power_state;
}

static void adc_pm_down(void* arg, uint32_t sleep_duration)
{
    adc_dev_t* pd = (adc_dev_t*)arg;
    pd->ch_en_reg = RD_WORD(SADCCTRL_REG_CHANNEL_EN_CTRL);
    pd->timing_reg = RD_WORD(SADCCTRL_REG_SAMPLE_TIMING_CTRL);
    return;
}

static void adc_pm_up(void* arg)
{
    adc_dev_t* pd = (adc_dev_t*)arg;

    adc_ref_sel(ADC_REF_V1P0);
    uint32_t size = CFG_SMEM_SADC & 0xFFFF;
    adc_fifo_size(size * 2 - 1); //count in samples. One word have two sample.
    adc_fifo_almost_full(size - 1);
    WR_WORD(SADCCTRL_REG_CHANNEL_EN_CTRL, pd->ch_en_reg);
    WR_WORD(SADCCTRL_REG_SAMPLE_TIMING_CTRL, pd->timing_reg);

    #if 0
    uint32_t ch_en = pd->ch_en_reg & 0xffff;
    for (int i = ADC_CH0; i <= ADC_CH14; i++) {
        if (ch_en & 0x1) {
            adc_hw_ch_enable(i);
        }
        ch_en = ch_en >> 1;
    }
    #endif
}
#endif // CFG_PM_EN
adc_dev_t* hal_adc_open(void)
{
    adc_dev_t* pd = &adc_dev;
		uint32_t size;
    if (pd->used)
        return NULL;

    memset(pd, 0, sizeof(adc_dev_t));
    pd->used = 1;

    pd->semaphore = NULL;
    pd->mutex = NULL;
    pd->semaphore = osSemaphoreCreate(osSemaphore(adc_semaphore), 0);
    if (!pd->semaphore) {
        goto fail;
    }
    pd->mutex = osMutexCreate(osMutex(adc_mutex));
    if (!pd->mutex) {
        goto fail;
    }

    hal_clk_sadc_set(ADC_CLK); //need set to 1Mhz
    hal_clk_sadc_en(1);

    adc_ref_sel(ADC_REF_V1P0);

    size = CFG_SMEM_SADC & 0xFFFF;
    if (size > 2) {
        adc_fifo_size(size - 1); //count in samples. One word have two sample.
        adc_fifo_almost_full(size / 2 - 1);
        pd->auto_mode = 1;
    } else {
        pd->auto_mode = 0;
    }
#if CFG_PM_EN
    pd->power_state = PM_DEEP_SLEEP;
    pd->pmd.arg = (void*)pd;
    pd->pmd.power_state = adc_pm_state;
    pd->pmd.power_down = adc_pm_down;
    pd->pmd.power_up = adc_pm_up;
    hal_pm_reg_mod(&pd->pmd);
#endif

    return pd;
fail:
    if (pd->semaphore)
        osSemaphoreDelete(pd->semaphore);
    if (pd->mutex)
        osMutexDelete(pd->mutex);
    pd->used = 0;
    return NULL;
}
void hal_adc_close(adc_dev_t* dev)
{
    if (!dev || !dev->used)
        return;
    osMutexWait(dev->mutex, osWaitForever);

    NVIC_DisableIRQ(Sadc_IRQn);
    adc_vbat_sensor_disable();
    adc_temp_sensor_disable();
    aon_write(AON_REG_GPIO_2_ANA_ON, 0);
    //smem_disable_ch(SMEM_CH5);
    adc_disable();
    adc_force_disable();
    hal_clk_sadc_en(0);
    osMutexRelease(dev->mutex);
    osSemaphoreDelete(dev->semaphore);
    osMutexDelete(dev->mutex);
    dev->semaphore = NULL;
    dev->mutex = NULL;
#if CFG_PM_EN
    hal_pm_unreg_mod(&dev->pmd);
#endif
    dev->used = 0;
}
static uint16_t adc_force_mode_sample(uint8_t ch)
{
    adc_force_ch(ch & 0x7); //fix channel 9 issue
    adc_force_ch(ch);
    adc_force_start(0);
    osDelay(10);
    adc_force_start(1);
    osDelay(10);

    uint16_t adc = adc_cur_adc_val();
    adc_force_start(0);

    /* fix channel 9 issue */
    adc_force_ch(ch & 0x7);
    adc_force_ch(0x0);
    return adc;
}

int hal_adc_force_mode_start(adc_dev_t* dev, int ch, uint16_t* pval)
{
    /**
     * need about 50ms to switch channel, otherwise get wrong sample value
     */

    if (!dev)
        return ADC_ERR_INVALID_PARAM;
    if (ch >= ADC_CH_MAX || ch < 0)
        return ADC_ERR_INVALID_PARAM;
    osMutexWait(dev->mutex, osWaitForever);
#if CFG_PM_EN
    dev->power_state = PM_SLEEP;
#endif
    adc_hw_ch_enable(ch);

    adc_disable();
    adc_force_enable();

    *pval = adc_force_mode_sample(ch);

    //adc_force_disable();//Should not disable here
    //if (ch == ADC_CH14)
    //    adc_vbat_sensor_disable();
    //if (ch == ADC_CH15)
    //    adc_temp_sensor_disable();
#if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
#endif

    osMutexRelease(dev->mutex);

    return ADC_ERR_OK;
}

int hal_adc_auto_mode_enable_ch(adc_dev_t* dev, int ch, uint16_t* buf, uint16_t buf_sz)
{
    /* auto mode don't support channel 15 */
    if ((ch > ADC_CH15) || (ch < 0) || !dev)
        return ADC_ERR_INVALID_PARAM;
    //adc_dev_t *pd = &adc_dev;
    osMutexWait(dev->mutex, osWaitForever);

    adc_hw_ch_enable(ch);

    dev->buf[ch] = buf;
    dev->buf_len[ch] = buf_sz;
    uint32_t ch_map = adc_get_ch_en();
    ch_map |= 1 << ch;
    adc_set_ch_en(ch_map);
    osMutexRelease(dev->mutex);
    return ADC_ERR_OK;
}
int hal_adc_auto_mode_disable_ch(adc_dev_t* dev, int ch)
{
    /* auto mode don't support channel 15 */
    if ((ch > ADC_CH15) || (ch < 0) || !dev)
        return ADC_ERR_INVALID_PARAM;
    //adc_dev_t *pd = &adc_dev;
    osMutexWait(dev->mutex, osWaitForever);

    dev->buf[ch] = NULL;
    dev->buf_len[ch] = 0;
    uint32_t ch_map = adc_get_ch_en();
    ch_map &= ~(1UL << ch);
    adc_set_ch_en(ch_map);
    adc_hw_ch_disable(ch);
    osMutexRelease(dev->mutex);
    return ADC_ERR_OK;
}

int hal_adc_set_ref(adc_dev_t* dev, int ref)
{
    osMutexWait(dev->mutex, osWaitForever);
    adc_ref_sel(ADC_REF_V1P0);
    osMutexRelease(dev->mutex);
    return ADC_ERR_OK;
}
int hal_adc_auto_mode_config(adc_dev_t* dev, uint8_t ch_intv, uint8_t grp_intv)
{
    if (!dev)
        return ADC_ERR_INVALID_PARAM;
    osMutexWait(dev->mutex, osWaitForever);
    adc_sample_ch_intv(ch_intv);
    adc_sample_grp_intv(grp_intv);
    osMutexRelease(dev->mutex);
    return ADC_ERR_OK;
}

static void adc_clean_fifo()
{
    int cnt = adc_fifo_cnt();
    //PRINTD(DBG_TRACE, "cnt %d\n", cnt);
    cnt++; //first sample has already load to register
    while (cnt-- > 0) {
        adc_fifo_data();
        int wait = READ_DELAY;
        while (wait-- > 0)
            ;
    }
}
int hal_adc_auto_mode_start(adc_dev_t* dev, uint16_t sample_num)
{
    if (!dev)
        return ADC_ERR_INVALID_PARAM;
    if (!dev->auto_mode)
        return ADC_ERR_SMEM;
    osMutexWait(dev->mutex, osWaitForever);
    adc_force_disable();
    adc_enable();
    //adc_read_fifo(dev);
    memset(dev->buf_pos, 0, sizeof(dev->buf_pos));
    adc_num_sample(sample_num);
    adc_intr_mask_clear(0xf);
    adc_intr_mask_set(ADC_INTR_FIFO_EMPTY);
	NVIC_SetPriority(Sadc_IRQn, IRQ_PRI_High);	
    NVIC_EnableIRQ(Sadc_IRQn);

#if CFG_PM_EN
    dev->power_state = PM_SLEEP;
#endif

    /* 
     * Only use semaphore as a binary sem. osSemaphoreRelease will add sem count without check init count.
     * So here we make sure the count is 0 using osSemaphoreWait(0) , then call  osSemaphoreWait(millisec).   
     */
    int ret;
    do {
        ret = osSemaphoreWait(dev->semaphore, 0);
    } while (ret > 0);
    adc_clean_fifo();
    adc_start(0);
    osDelay(10);
    adc_start(1);
    osSemaphoreWait(dev->semaphore, osWaitForever);
    adc_start(0);
    //adc_disable();
    NVIC_DisableIRQ(Sadc_IRQn);

#if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
#endif
    osMutexRelease(dev->mutex);

    return ADC_ERR_OK;
}

int hal_adc_stream_mode_start(adc_dev_t* dev)
{
    if (!dev)
        return ADC_ERR_INVALID_PARAM;
    if (!dev->auto_mode)
        return ADC_ERR_SMEM;
    osMutexWait(dev->mutex, osWaitForever);
    adc_force_disable();
    adc_enable();
    //adc_read_fifo(dev);
    //memset(dev->buf_pos, 0, sizeof(dev->buf_pos));
    adc_num_sample(0);
    adc_intr_mask_clear(0xf);
    adc_intr_mask_set(ADC_INTR_FIFO_EMPTY);

#if CFG_PM_EN
    dev->power_state = PM_SLEEP;
#endif

    /* 
     * Only use semaphore as a binary sem. osSemaphoreRelease will add sem count without check init count.
     * So here we make sure the count is 0 using osSemaphoreWait(0) , then call  osSemaphoreWait(millisec).   
     */
    adc_clean_fifo();
    adc_start(0);
    osDelay(10);
    adc_start(1);
    //osSemaphoreWait(dev->semaphore, osWaitForever);
    adc_start(0);
    //adc_disable();
    osMutexRelease(dev->mutex);

    return ADC_ERR_OK;
}

int hal_adc_auto_mode_stop(adc_dev_t* dev)
{
    osSemaphoreRelease(dev->semaphore);
    osMutexWait(dev->mutex, osWaitForever);
#if CFG_PM_EN
    dev->power_state = PM_SLEEP;
#endif
    adc_stop(0);
    osDelay(10);
    adc_stop(1);
    adc_disable();
#if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
#endif
    osMutexRelease(dev->mutex);
    return ADC_ERR_OK;
}

int hal_adc_calib_temp(adc_dev_t* dev, int32_t temp, int16_t* poffset)
{
    if (!dev)
        return ADC_ERR_INVALID_PARAM;
    osMutexWait(dev->mutex, osWaitForever);

    //int ret = 0;

    adc_disable();
    adc_force_enable();
    adc_hw_ch_enable(ADC_CH15);

#if CFG_PM_EN
    dev->power_state = PM_SLEEP;
#endif

    /* wait 4 sample for stable */
    for (int i = 0; i < 4; i++) {
        adc_force_mode_sample(ADC_CH15);
    }

    int n = 32; // n is from 32 to 128(2**5 to 2**7)
    uint32_t accu_val = 0;
    for (int i = 0; i < n; i++) {
        uint16_t val = adc_force_mode_sample(ADC_CH15);
        accu_val += val;
    }
    //accu_val >>= 0;
    uint32_t temp_offset = accu_val + temp * 64;

    *poffset = temp_offset - 23040;

    adc_force_disable();
#if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
#endif

    osMutexRelease(dev->mutex);

    return ADC_ERR_OK;
}

int hal_adc_measure_temp(adc_dev_t* dev, int32_t* pval)
{
    if (!dev)
        return ADC_ERR_INVALID_PARAM;
    osMutexWait(dev->mutex, osWaitForever);

    int ret = 0;
    if (hal_efuse_open() != EFUSE_ERR_OK) {
        osMutexRelease(dev->mutex);
        return ADC_ERR_EFUSE;
    }

    uint32_t efuse_offset = 0;
    ret = hal_efuse_read_word(EFUSE_BANK_0, 15, &efuse_offset);
    hal_efuse_close();
    if (ret != EFUSE_ERR_OK) {
        osMutexRelease(dev->mutex);
        return ADC_ERR_EFUSE;
    }

    adc_disable();
    adc_force_enable();
    adc_hw_ch_enable(ADC_CH15);

#if CFG_PM_EN
    dev->power_state = PM_SLEEP;
#endif

    /* wait 4 sample for stable */
    for (int i = 0; i < 4; i++) {
        adc_force_mode_sample(ADC_CH15);
    }

    int n = 32; // n is from 8 to 128(2**3 to 2**7)
    int32_t accu_val = 0;
    for (int i = 0; i < n; i++) {
        uint16_t val = adc_force_mode_sample(ADC_CH15);
        accu_val += val;
    }

    efuse_offset &= 0xffff;
    int32_t temp_offset = (int16_t)efuse_offset + 23040;

    int32_t tf6 = temp_offset - accu_val;
    int32_t t = (tf6 >= 0) ? ((tf6 + 32) >> 6) : -1 * ((-tf6 + 32) >> 6);

    *pval = t;

    adc_force_disable();
#if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
#endif

    osMutexRelease(dev->mutex);

    return ADC_ERR_OK;
}

int hal_adc_measure_vbat(adc_dev_t* dev, int32_t* pval)
{
    if (!dev)
        return ADC_ERR_INVALID_PARAM;
    osMutexWait(dev->mutex, osWaitForever);

    int ret = 0;
    if (hal_efuse_open() != EFUSE_ERR_OK) {
        osMutexRelease(dev->mutex);
        return ADC_ERR_EFUSE;
    }
    uint32_t efuse_val = 0;
    ret = hal_efuse_read_word(EFUSE_BANK_0, 14, &efuse_val);
    hal_efuse_close();
    if (ret != EFUSE_ERR_OK) {
        osMutexRelease(dev->mutex);
        return ADC_ERR_EFUSE;
    }

    adc_disable();
    adc_force_enable();
    adc_hw_ch_enable(ADC_CH14);

#if CFG_PM_EN
    dev->power_state = PM_SLEEP;
#endif

    /* wait 4 sample for stable */
    for (int i = 0; i < 4; i++) {
        adc_force_mode_sample(ADC_CH14);
    }

    int n = 32; // n is from 8 to 128(2**3 to 2**7)
    uint32_t accu_val = 0;
    for (int i = 0; i < n; i++) {
        uint16_t val = adc_force_mode_sample(ADC_CH14);
        accu_val += val;
    }

    int16_t efuse_slope = efuse_val & 0xffff;
    int16_t efuse_offset = efuse_val >> 16;
    uint32_t slope = 20480 + efuse_slope;

    uint32_t v0 = slope * accu_val;
    uint32_t v1 = (v0 + (1 << 17)) >> 18;

    *pval = (int16_t)v1 + efuse_offset; // real votage is *pval/1024.0

    adc_force_disable();
#if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
#endif

    osMutexRelease(dev->mutex);

    return ADC_ERR_OK;
}
#if 0
int hal_adc_measure_analog_ch(adc_dev_t* dev, int ch, int16_t* pval)
{
    if (!dev)
        return ADC_ERR_INVALID_PARAM;
    if (ch < 0 || ch > ADC_CH10)
        return ADC_ERR_INVALID_PARAM;
    osMutexWait(dev->mutex, osWaitForever);

    int ret = 0;
    if (hal_efuse_open() != EFUSE_ERR_OK) {
        osMutexRelease(dev->mutex);
        return ADC_ERR_EFUSE;
    }
    uint32_t efuse_val = 0;
    ret = hal_efuse_read_word(EFUSE_BANK_0, 14, &efuse_val); //todo
    hal_efuse_close();
    if (ret != EFUSE_ERR_OK) {
        osMutexRelease(dev->mutex);
        return ADC_ERR_EFUSE;
    }

    adc_ref_sel(ADC_REF_V1P0);
    adc_disable();
    adc_force_enable();
    adc_hw_ch_enable(ch);

#if CFG_PM_EN
    dev->power_state = PM_SLEEP;
#endif

    /* wait 4 sample for stable */
    for (int i = 0; i < 4; i++) {
        adc_force_mode_sample(ch);
    }

    int n = 32; // n is from 8 to 128(2**3 to 2**7)
    uint32_t accu_val = 0;
    for (int i = 0; i < n; i++) {
        uint16_t val = adc_force_mode_sample(ch);
        accu_val += val;
    }

    int16_t efuse_slope = efuse_val & 0xffff;
    int16_t efuse_offset = efuse_val >> 16;
    uint32_t slope = 8192 + efuse_slope;

    uint32_t v0 = slope * accu_val;
    uint32_t v1 = (v0 + (1 << 17)) >> 18;

    *pval = (int16_t)v1 + efuse_offset; // real votage is *pval/1024.0

    adc_force_disable();
#if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
#endif

    osMutexRelease(dev->mutex);

    return ADC_ERR_OK;
}
#endif
void temp_tx_cal(uint32_t base_addr, int temp)
{
    uint32_t ch;
    uint32_t word1, sc1;
    //uint32_t word2, sc2;

    // disable pll_trig control
    WR_WORD(0x46A031EC, 0);

    // enable CPU to access the PLL trig mem
    WR_WORD(0x46A03180, 0x10);

    for (ch = 0; ch < 40; ch++) {
        // word 1 and word2: Byte3: PA; Byte 2: HP SC; Byte 1: DCDC settings; Byte 0: PLL

        // for TX 1M
        sc1 = 0xc6;
        sc1 = sc1 - (ch >> 1) + (ch >> 3);

        //sc2 = 0xff; // for TX 2M mode
        if (temp >= 100) {
            word1 = 0x1700c1b6 + (sc1 << 16);
            //word2 = 0x1b00c1b6 + (sc2 << 16); // to be decided
        } else if (temp >= 75) {
            word1 = 0x1700c1a6 + (sc1 << 16);
            //word2 = 0x1b00c1a6 + (sc2 << 16); // to be decided
        } else if (temp >= 40) {
            word1 = 0x1700c196 + (sc1 << 16);
            //word2 = 0x1b00c196 + (sc2 << 16); // to be decided
        } else {
            word1 = 0x1700c186 + (sc1 << 16);
            //word2 = 0x1b00c186 + (sc2 << 16); // to be decided
        }
        WR_WORD(base_addr + 0xc * ch + 0x4, word1);
    }
    // enable trig to control freq, lod, hp_scale, and pa gain
    WR_WORD(0x46A031EC, 0x1111);

    // enable the whole PLL trig
    WR_WORD(0x46A03180, 0x1);
}
void temp_rx_cal(uint32_t base_addr, int temp)
{
    uint32_t ch;
    //uint32_t word0 = 0x04B08000, word1 = 0x04B00000, word2;
    uint32_t word2;

    // disable pll_trig control
    WR_WORD(0x46A031EC, 0);

    // enable CPU to access the PLL trig mem
    WR_WORD(0x46A03180, 0x10);

    word2 = (temp == 55) ? 0x0c1b6 : 0x0c1a6;

    for (ch = 0; ch < 40; ch++) {
        WR_WORD(base_addr + 0xc * ch + 0x8, word2);
    }
    // enable trig to control freq, lod, hp_scale, and pa gain
    WR_WORD(0x46A031EC, 0x1111);

    // enable the whole PLL trig
    WR_WORD(0x46A03180, 0x1);
}
int temp_rx_cal_hysteries(int current_temp, int old_temp_range)
{
    int temp_range, decided_range;

    // hysteries up threshold
    if (current_temp > 55) {
        temp_range = 55;
    } else
        temp_range = 0;

    decided_range = (temp_range > old_temp_range) ? temp_range : old_temp_range;

    // hysteries low threshold
    if (current_temp < 50) {
        temp_range = 0;
    } else
        temp_range = 55;

    decided_range = (temp_range < decided_range) ? temp_range : decided_range;

    // If the decision is not same as old one, then update
    if (decided_range != old_temp_range) {
        // do RX MPLL calibrations here
        temp_rx_cal(0x46a05000, decided_range);
    }

    return decided_range;
}

int temp_tx_cal_hysteries(int current_temp, int old_temp_range)
{
    int temp_range, decided_range;
    // hysteries up threshold
    if (current_temp > 100) {
        temp_range = 100;
    } else if (current_temp > 75) {
        temp_range = 75;
    } else if (current_temp > 40) {
        temp_range = 40;
    } else
        temp_range = 0;

    decided_range = (temp_range > old_temp_range) ? temp_range : old_temp_range;
    // hysteries low threshold
    if (current_temp < 35) {
        temp_range = 0;
    } else if (current_temp < 70) {
        temp_range = 40;
    } else if (current_temp < 95) {
        temp_range = 75;
    } else
        temp_range = 100;

    decided_range = (temp_range < decided_range) ? temp_range : decided_range;

    // If the decision is not same as old one, then update
    if (decided_range != old_temp_range) {
        // do TX MPLL calibrations here
        temp_tx_cal(0x46a05200, decided_range);
    }

    return decided_range;
}

int hal_adc_stream_mode_process(adc_dev_t* dev, uint16_t *data, uint8_t *ch, int len)
{
    if (!dev)
        return ADC_ERR_INVALID_PARAM;
    osMutexWait(dev->mutex, osWaitForever);

	
	int cnt = 0;
	if (len <= 0)
		return ADC_ERR_INVALID_PARAM;
	uint32_t status = adc_intr_status();
	if (status & (ADC_INTR_FIFO_ALMOST_FULL | ADC_INTR_FIFO_FULL)) {
		cnt = adc_fifo_cnt();
		cnt++; 
		if (len < cnt)
			cnt = len;
	    for (int i = 0; i < cnt; i++) {
	        uint16_t val = adc_fifo_data();
            if (ch) {
                ch[i] =  val >> 12;;
            }
	        if (data) {
	        	data[i] = val & 0xfff;
	        }
	     
	        int wait = READ_DELAY;
	        while (wait-- > 0);
	    }		
	}

	adc_intr_clear(status);
	osMutexRelease(dev->mutex);
    return cnt;
}


static void adc_read_fifo(adc_dev_t* pd)
{
    int cnt = adc_fifo_cnt();
    //PRINTD(DBG_TRACE, "cnt %d\n", cnt);
    cnt++; //first sample has already load to register
    while (cnt-- > 0) {
        uint16_t val = adc_fifo_data();
        //PRINTD(DBG_TRACE, "val 0x%04x\n", val);
        //uint16_t ch_msb = val>>12;
        uint8_t ch = val >> 12;
        //tst_buf[tst_pos++] = val;
        if (pd->buf && pd->buf[ch] && (pd->buf_pos[ch] < pd->buf_len[ch])) {
            pd->buf[ch][pd->buf_pos[ch]] = val & 0xfff;
            pd->buf_pos[ch]++;
        }

        //while (cnt && adc_fifo_cnt() == cnt);

        int wait = READ_DELAY;
        while (wait-- > 0);
    }
}
__irq void Sadc_Handler(void)
{
    /* Don't add too much print function in irq handler, will lost sample */
    uint32_t status = adc_intr_status();
    adc_dev_t* pd = &adc_dev;
    //PRINTD(DBG_TRACE, "adc 0x%x\n", status);

    if (status & ADC_INTR_SAMPLE_DONE) {
        adc_read_fifo(pd);
        if (pd->semaphore) {
            osSemaphoreRelease(pd->semaphore);
        }
    } else if (status & (ADC_INTR_FIFO_ALMOST_FULL | ADC_INTR_FIFO_FULL)) {
        adc_read_fifo(pd);
    }

    adc_intr_clear(status);
    //PRINTD(DBG_TRACE, "adc 0x%x\n", status);
}

#endif
