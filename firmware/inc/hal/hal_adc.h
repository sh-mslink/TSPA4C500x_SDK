/**
 ****************************************************************************************
 *
 * @file hal_adc.h
 *
 * @brief ADC driver header file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
#ifndef HAL_ADC
#define HAL_ADC
#include <stdint.h>
#include "in_mmap.h"
#include "cmsis_os.h"
#include ".\hal\hal_power.h"

#define ADC_INTR_SAMPLE_DONE 0x00000001UL
#define ADC_INTR_FIFO_FULL   0x00000002UL
#define ADC_INTR_FIFO_EMPTY   0x00000004UL
#define ADC_INTR_FIFO_ALMOST_FULL   0x00000008UL

enum {
    ADC_CH0 = 0, ///ADC_CH_IN
    ADC_CH1,   ///GPIO_2_1
    ADC_CH2,   ///GPIO_2_2
    ADC_CH3,   ///GPIO_2_3
    ADC_CH4,   ///GPIO_2_4
    ADC_CH5,   ///GPIO_2_5
    ADC_CH6,   ///GPIO_2_6
    ADC_CH7,   ///GPIO_2_7
    ADC_CH8,   ///GPIO_2_8
    ADC_CH9,
    ADC_CH10,  ///GPIO_2_0
    ADC_CH11,
    ADC_CH12,
    ADC_CH13,
    ADC_CH14,  ///VBAT
    ADC_CH15,  ///temp sensor
    ADC_CH_MAX,
};
enum adc_error {
	ADC_ERR_OK = 0,
	ADC_ERR_INVALID_PARAM = -1,
    ADC_ERR_EFUSE = -2,
    ADC_ERR_SMEM = -3,
    
};
typedef struct {
    int used;
    osSemaphoreId semaphore;
    osMutexId mutex;
    uint16_t* buf[ADC_CH_MAX];
    uint16_t buf_len[ADC_CH_MAX];
    uint16_t buf_pos[ADC_CH_MAX];
    int auto_mode;
    #if CFG_PM_EN
	int power_state;
	struct pm_module pmd;
    uint32_t ch_en_reg;
    uint32_t timing_reg;
    #endif
} adc_dev_t;



static __inline uint32_t adc_intr_status(void)
{
    return RD_WORD(SADCCTRL_REG_INTR_STATUS);
}
static __inline uint32_t adc_intr_mask_status(void)
{
    return RD_WORD(SADCCTRL_REG_INTR_MASK_STATUS);
}
static __inline void adc_intr_clear(uint32_t reg)
{
    WR_WORD(SADCCTRL_REG_INTR_CLEAR, reg);
}
static __inline void adc_intr_set(uint32_t reg)
{
    WR_WORD(SADCCTRL_REG_INTR_SET, reg);
}
static __inline void adc_intr_mask_clear(uint32_t reg)
{
    WR_WORD(SADCCTRL_REG_INTR_MASK_CLEAR, reg);
}
static __inline void adc_intr_mask_set(uint32_t reg)
{
    WR_WORD(SADCCTRL_REG_INTR_MASK_SET, reg);
}


static __inline void adc_enable(void)
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_MISC_CTRL);
    reg |= SADCCTRL_REG_MISC_CTRL_CTL_ENABLE;
    WR_WORD(SADCCTRL_REG_MISC_CTRL, reg);
}
static __inline void adc_disable(void)
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_MISC_CTRL);
    reg &= ~SADCCTRL_REG_MISC_CTRL_CTL_ENABLE;
    WR_WORD(SADCCTRL_REG_MISC_CTRL, reg);
}
static __inline void adc_start(uint8_t val)
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_MISC_CTRL);
    reg &= ~SADCCTRL_REG_MISC_CTRL_CTL_START;
    reg |= (val&0x1) << 1;
    WR_WORD(SADCCTRL_REG_MISC_CTRL, reg);
}
static __inline void adc_stop(uint8_t val)
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_MISC_CTRL);
    reg &= ~SADCCTRL_REG_MISC_CTRL_CTL_END;
    //WR_WORD(SADCCTRL_REG_MISC_CTRL, reg);
    reg |= (val&0x1) << 2;
    WR_WORD(SADCCTRL_REG_MISC_CTRL, reg);
}
static __inline void adc_reset(uint8_t val)
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_MISC_CTRL);
    reg &= ~SADCCTRL_REG_MISC_CTRL_CTL_RST_INTRCTRL;
    //WR_WORD(SADCCTRL_REG_MISC_CTRL, reg);
    reg |= (val&0x1) << 4;
    WR_WORD(SADCCTRL_REG_MISC_CTRL, reg);
}

static __inline void adc_num_sample(uint16_t val)
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_MISC_CTRL);
    reg &= ~SADCCTRL_REG_MISC_CTRL_CTL_NUM_SAMPLES;
    reg |= val<<16;
    WR_WORD(SADCCTRL_REG_MISC_CTRL, reg);
}


static __inline void adc_set_ch_en(uint16_t val)
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_CHANNEL_EN_CTRL);
    reg &= ~SADCCTRL_REG_CHANNEL_EN_CTRL_CTL_CH_EN;
    reg |= val;
    WR_WORD(SADCCTRL_REG_CHANNEL_EN_CTRL, reg);
}
static __inline uint32_t adc_get_ch_en(void)
{
    return RD_WORD(SADCCTRL_REG_CHANNEL_EN_CTRL) & SADCCTRL_REG_CHANNEL_EN_CTRL_CTL_CH_EN;
}
static __inline void adc_sample_ch_intv(uint8_t val)
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_CHANNEL_EN_CTRL);
    reg &= ~SADCCTRL_REG_CHANNEL_EN_CTRL_CTL_SAMPLE_CH_INTERVAL;
    reg |= val<<16;
    WR_WORD(SADCCTRL_REG_CHANNEL_EN_CTRL, reg);
}
static __inline void adc_sample_grp_intv(uint8_t val)
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_CHANNEL_EN_CTRL);
    reg &= ~SADCCTRL_REG_CHANNEL_EN_CTRL_CTL_SAMPLE_GRP_INTERVAL;
    reg |= val<<24;
    WR_WORD(SADCCTRL_REG_CHANNEL_EN_CTRL, reg);
}
static __inline void adc_start_delay(uint8_t val)
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_SAMPLE_TIMING_CTRL);
    reg &= ~SADCCTRL_REG_SAMPLE_TIMING_CTRL_CTL_EN2START_DELAY;
    reg |= val;
    WR_WORD(SADCCTRL_REG_SAMPLE_TIMING_CTRL, reg);
}
static __inline void adc_sample_delay(uint8_t val)
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_SAMPLE_TIMING_CTRL);
    reg &= ~SADCCTRL_REG_SAMPLE_TIMING_CTRL_CTL_SAMPLE_DELAY;
    reg |= val<<8;
    WR_WORD(SADCCTRL_REG_SAMPLE_TIMING_CTRL, reg);
}

static __inline void adc_disable_after_sample(uint8_t val)
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_SAMPLE_TIMING_CTRL);
    reg &= ~SADCCTRL_REG_SAMPLE_TIMING_CTRL_CTL_DISABLE_AFTER_SAMPLE;
    reg |= val<<8;
    WR_WORD(SADCCTRL_REG_SAMPLE_TIMING_CTRL, reg);
}

static __inline void adc_fifo_size(uint16_t reg)
{
    WR_WORD(SADCCTRL_REG_FIFO_CTRL, reg);
}
static __inline void adc_fifo_almost_full(uint16_t reg)
{
    WR_WORD(SADCCTRL_REG_FIFO_ALMOST_FULL_CTRL, reg);
}

static __inline uint8_t adc_cur_ch()
{
    return RD_WORD(SADCCTRL_REG_STATUS)&SADCCTRL_REG_STATUS_STS_CURR_CH;
}
static __inline uint16_t adc_fifo_cnt()
{
    return (RD_WORD(SADCCTRL_REG_STATUS)&SADCCTRL_REG_STATUS_STS_FIFO_CNT)>>4;
}

static __inline uint16_t adc_fifo_data()
{
    return RD_WORD(SADCCTRL_REG_FIFO_VAL);
}

static __inline void adc_force_enable()
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_FORCE_CTRL);
    reg |= SADCCTRL_REG_FORCE_CTRL_CTL_FORCE_EN;
    WR_WORD(SADCCTRL_REG_FORCE_CTRL, reg);    
}

static __inline void adc_force_disable()
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_FORCE_CTRL);
    reg &= ~SADCCTRL_REG_FORCE_CTRL_CTL_FORCE_EN;
    WR_WORD(SADCCTRL_REG_FORCE_CTRL, reg);    
}

static __inline void adc_force_ch(uint8_t val)
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_FORCE_CTRL);
    reg &= ~SADCCTRL_REG_FORCE_CTRL_CTL_FORCE_CH;
    reg |= (val&0xf) << 4;
    WR_WORD(SADCCTRL_REG_FORCE_CTRL, reg);    
}

static __inline void adc_force_start(uint8_t val)
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_FORCE_CTRL);
    reg &= ~SADCCTRL_REG_FORCE_CTRL_CTL_FORCE_START;
    reg |= (val&0x1) << 8;
    WR_WORD(SADCCTRL_REG_FORCE_CTRL, reg);    
}

static __inline uint16_t adc_cur_adc_val()
{
    return RD_WORD(SADCCTRL_REG_CURR_ADC_VAL);
}


#define ADC_REF_SEL_MASK 0x000000E0UL
#define ADC_REF_V1P0  0
#define ADC_REF_VBAT_DIV2  1
#define ADC_REF_CH0 2
#define ADC_REF_CH2 3
#define ADC_REF_CH4 4
#define ADC_REF_CH6 5
#define ADC_REF_CH8 6
#define ADC_REF_CH10 7

static __inline void adc_ref_sel(uint32_t val)
{
    uint32_t reg = RD_WORD(SADCCTRL_REG_SENSOR_ADC_REG1TO3);
    reg &= ~ADC_REF_SEL_MASK;
    reg |= (val&0x7)<<5;
    WR_WORD(SADCCTRL_REG_SENSOR_ADC_REG1TO3, reg);
}

/** 
 * @brief Open ADC device.
 * @return Return ADC device struct, NUll if failed.
 * */
adc_dev_t* hal_adc_open(void);

/** 
 * @brief Close ADC device.
 * @param[in] dev   ADC device struct.
 * */
void hal_adc_close(adc_dev_t *dev);

/** 
 * @brief Start force mode.
 * @param[in] dev   ADC device struct.
 * @param[in] ch    channel.
 * @param[out] pval  ADC value pointer.
 * @return @see enum adc_error for return code.
 * */
int hal_adc_force_mode_start(adc_dev_t* dev, int ch, uint16_t *pval);

/** 
 * @brief Enable channel in auto mode.
 * @param[in] dev   ADC device struct.
 * @param[in] ch    Channel.
 * @param[in] buf   Buffer for this channel.
 * @param[in] buf_sz    Buffer size for this channel
 * @return @see enum adc_error for return code.
 * */
int hal_adc_auto_mode_enable_ch(adc_dev_t* dev, int ch, uint16_t *buf, uint16_t buf_sz);

/** 
 * @brief Disable channel in auto mode.
 * @param[in] dev   ADC device struct.
 * @param[in] ch    Channel.
 * @return @see enum adc_error for return code.
 * */
int hal_adc_auto_mode_disable_ch(adc_dev_t* dev, int ch);

/** 
 * @brief Config auto mode.
 * @param[in] dev   ADC device struct.
 * @param[in] ch_intv    Channel interval.
 * @param[in] grp_intv  Group interval.
 * @return @see enum adc_error for return code.
 * */
int hal_adc_auto_mode_config(adc_dev_t* dev, uint8_t ch_intv, uint8_t grp_intv);

/** 
 * @brief Start auto mode.
 * @param[in] dev   ADC device struct.
 * @param[in] sample_num    Sample number.
 * @return @see enum adc_error for return code.
 * */
int hal_adc_auto_mode_start(adc_dev_t* dev, uint16_t sample_num);

/** 
 * @brief Stop auto mode.
 * @param[in] dev   ADC device struct.
 * @return @see enum adc_error for return code.
 * */
int hal_adc_auto_mode_stop(adc_dev_t* dev);

/** 
 * @brief Set ADC reference.
 * @param[in] dev   ADC device struct.
 * @param[in] ref   @see ADC_REF_V1P0
 * @return @see enum adc_error for return code.
 * */
int hal_adc_set_ref(adc_dev_t* dev, int ref);//todo 

/** 
 * @brief read temperature. Need burn calibration value to efuse first.
 * @param[in] dev   ADC device struct.
 * @param[in] pval  temperature
 * @return @see enum adc_error for return code.
 * */
int hal_adc_measure_temp(adc_dev_t* dev, int32_t* pval);
/** 
 * @brief read VBAT. Need burn calibration value to efuse first.
 * @param[in] dev   ADC device struct.
 * @param[in] pval  VBAT
 * @return @see enum adc_error for return code.
 * */
int hal_adc_measure_vbat(adc_dev_t* dev, int32_t* pval);

/** 
 * @brief Start stream mode. This is a special auto mode, it continue sample data, until call hal_adc_auto_mode_stop.
 * @param[in] dev   ADC device struct.
 * @return @see enum adc_error for return code.
 * */

int hal_adc_stream_mode_start(adc_dev_t* dev);

/** 
 * @brief Get data and channel in stream mode
 * @param[in] dev   ADC device struct.
 * @param[in] data   ADC data buffer, all channel data is in this buffer.
 * @param[in] ch   ADC channel buffer, it indicates channel in data buffer.
 * @param[in] len   buffer length.
 * @return @see enum adc_error for return code.
 * */
int hal_adc_stream_mode_process(adc_dev_t* dev, uint16_t *data, uint8_t *ch, int len);


#endif

