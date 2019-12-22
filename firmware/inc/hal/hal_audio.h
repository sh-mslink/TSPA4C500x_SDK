/**
 ****************************************************************************************
 *
 * @file hal_audio.h
 *
 * @brief Audio Profile
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef HAL_AUDIO_H
#define HAL_AUDIO_H

/**
 ****************************************************************************************
 * @defgroup HAL_AUDIO Audio Profile  
 * @ingroup HAL
 * @brief  HAL AUDIO
 * @{
 ****************************************************************************************
 */

#include <stdint.h>
#include <math.h>
#include "in_mmap.h"
#include "in_config.h"

/*
 ****************************************************************************************
 * INLINE FUNCTIONS
 ****************************************************************************************
 */
static __inline uint32_t audio_intr_status()
{
	return RD_WORD(AUDIO_REGS_INTR_STATUS);
}

static __inline void audio_intr_clear(uint32_t val)
{
	WR_WORD(AUDIO_REGS_INTR_CLEAR, (val & 0x3FFFFF));
}

static __inline void audio_intr_mask_set(uint32_t val)
{
	WR_WORD(AUDIO_REGS_INTR_MASK_SET, (val & 0x3FFFFF));
}

static __inline void audio_intr_mask_clear(uint32_t val)
{
	WR_WORD(AUDIO_REGS_INTR_MASK_CLEAR, (val & 0x3FFFFF));
}

static __inline void audio_aenc_sreset()
{
 	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLT_AURX_SRESET;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
	reg &= ~AUDIO_REGS_MISC_CTRL0_CTLT_AURX_SRESET;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_aenc_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLT_AENC_EN;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_aenc_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg &= ~AUDIO_REGS_MISC_CTRL0_CTLT_AENC_EN;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_aenc_restart()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLT_AENC_RESTART;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);	
	reg &= ~AUDIO_REGS_MISC_CTRL0_CTLT_AENC_RESTART;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_dec_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLT_ADEC_EN;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_dec_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg &= ~AUDIO_REGS_MISC_CTRL0_CTLT_ADEC_EN;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_dec_restart()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLT_ADEC_RESTART;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);	
	reg &= ~AUDIO_REGS_MISC_CTRL0_CTLT_ADEC_RESTART;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_autx_reset()
{
 	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_SRESET;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg); 
	reg &= ~AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_SRESET;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}
static __inline void audio_autx_reset_spk()
{
 	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_SRESET_SPK;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg); 
	reg &= ~AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_SRESET_SPK;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_tx_out_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_OUT_EN;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_tx_out_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg &= ~(AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_OUT_EN);
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_afifo_en_wr_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_AFIFO_EN_WR;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_afifo_en_wr_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg &= ~(AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_AFIFO_EN_WR);
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_afifo_en_rd_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_AFIFO_EN_RD;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_afifo_en_rd_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg &= ~(AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_AFIFO_EN_RD);
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_autx_sdm_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= (AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_SDM_EN);
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_autx_sdm_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg &= ~(AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_SDM_EN);
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_rx_stereo_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLQ_AURX_STEREO;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_rx_stereo_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg &= ~AUDIO_REGS_MISC_CTRL0_CTLQ_AURX_STEREO;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_aenc_stereo_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLQ_AENC_STEREO;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_aenc_stereo_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg &= ~AUDIO_REGS_MISC_CTRL0_CTLQ_AENC_STEREO;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline uint8_t audio_get_aenc_audio_mode()
{
	return ((RD_WORD(AUDIO_REGS_MISC_CTRL0) & AUDIO_REGS_MISC_CTRL0_CTLQ_AENC_STEREO) > 0) ? 1 : 0;
}

static __inline void audio_adec_stereo_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLQ_ADEC_STEREO;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_adec_stereo_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg &= ~AUDIO_REGS_MISC_CTRL0_CTLQ_ADEC_STEREO;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline uint8_t audio_get_adec_audio_mode()
{
	return ((RD_WORD(AUDIO_REGS_MISC_CTRL0) & AUDIO_REGS_MISC_CTRL0_CTLQ_ADEC_STEREO) > 0) ? 1 : 0;
}

static __inline void audio_tx_stereo_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLQ_AUTX_STEREO;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_tx_stereo_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg &= ~AUDIO_REGS_MISC_CTRL0_CTLQ_AUTX_STEREO;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_tx_i2s_master_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLQ_AUTX_I2SM_SEL;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_tx_i2s_master_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg &= ~AUDIO_REGS_MISC_CTRL0_CTLQ_AUTX_I2SM_SEL;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_tx_i2s_slave_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLQ_AUTX_I2SS_SEL;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_tx_i2s_slave_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg &= ~AUDIO_REGS_MISC_CTRL0_CTLQ_AUTX_I2SS_SEL;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_rx_pdm_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg |= AUDIO_REGS_MISC_CTRL0_CTLT_PDM_EN;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_rx_pdm_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_MISC_CTRL0);
	reg &= ~AUDIO_REGS_MISC_CTRL0_CTLT_PDM_EN;
	WR_WORD(AUDIO_REGS_MISC_CTRL0, reg);
}

static __inline void audio_rx_i2s_byp_all_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL0);
	reg |= AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_I2S_BYP;
	WR_WORD(AUDIO_REGS_AURX_CTRL0, reg);
}

static __inline void audio_rx_i2s_byp_all_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL0);
	reg &= ~AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_I2S_BYP;
	WR_WORD(AUDIO_REGS_AURX_CTRL0, reg);
}

static __inline void audio_rx_in_format_i2s()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL0);
	reg |= AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_IN_FORMAT;
	WR_WORD(AUDIO_REGS_AURX_CTRL0, reg);
}

static __inline void audio_rx_in_format_pdm()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL0);
	reg &= ~AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_IN_FORMAT;
	WR_WORD(AUDIO_REGS_AURX_CTRL0, reg);
}

static __inline void audio_rx_set_cic_dec(uint8_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL0);
	reg &= ~AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_CIC_DEC;
	reg |= ((val & AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_CIC_DEC_MASK) << AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_CIC_DEC_SHIFT);
	WR_WORD(AUDIO_REGS_AURX_CTRL0, reg);
}

static __inline uint8_t audio_rx_get_cic_dec()
{
	return ((RD_WORD(AUDIO_REGS_AURX_CTRL0) >> AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_CIC_DEC_SHIFT) & AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_CIC_DEC_MASK);
}

static __inline void audio_rx_set_dc_off(uint32_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL0);
	reg &= ~AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_DC_OFF;
	reg |= ((val & AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_DC_OFF_MASK) << AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_DC_OFF_SHIFT);
	WR_WORD(AUDIO_REGS_AURX_CTRL0, reg);
}

static __inline uint32_t audio_rx_get_dc_off()
{
	return ((RD_WORD(AUDIO_REGS_AURX_CTRL0) >> AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_DC_OFF_SHIFT) & AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_DC_OFF_MASK);
}

static __inline void audio_rx_set_cic_shift(uint8_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL0);
	reg &= ~AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_CIC_SHIFT;
	reg |= ((val & AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_CIC_SHIFT_MASK) << AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_CIC_SHIFT_SHIFT);
	WR_WORD(AUDIO_REGS_AURX_CTRL0, reg);
}

static __inline uint8_t audio_rx_get_cic_shift()
{
	return ((RD_WORD(AUDIO_REGS_AURX_CTRL0) >> AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_CIC_SHIFT_SHIFT) & AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_CIC_SHIFT_MASK);
}	

static __inline void audio_rx_pdm_cic_init(uint8_t audio_pdm_aurx_cic_dec, uint32_t audio_pdm_aurx_cic_dec_offset, uint8_t audio_pdm_aurx_cic_dec_shift)
{
	audio_rx_set_cic_dec(audio_pdm_aurx_cic_dec);
	audio_rx_set_dc_off(audio_pdm_aurx_cic_dec_offset);
	audio_rx_set_cic_shift(audio_pdm_aurx_cic_dec_shift);
}

static __inline void audio_rx_i2s_master_core()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL0);
	reg &= ~AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_I2S_SLAVE;
	WR_WORD(AUDIO_REGS_AURX_CTRL0, reg);
}

static __inline void audio_rx_i2s_slave_core()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL0);
	reg |= AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_I2S_SLAVE;
	WR_WORD(AUDIO_REGS_AURX_CTRL0, reg);
}

static __inline void audio_rx_i2s_byp_ib4_db5_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL0);
	reg |= AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_I2S_D5;
	WR_WORD(AUDIO_REGS_AURX_CTRL0, reg);
}

static __inline void audio_rx_i2s_byp_ib4_db5_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL0);
	reg &= ~AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_I2S_D5;
	WR_WORD(AUDIO_REGS_AURX_CTRL0, reg);
}

static __inline void audio_rx_set_itp_per(uint8_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL1);
	reg &= ~AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_ITP_PER;
	reg |= ((val >> AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_ITP_PER_SHIFT) & AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_ITP_PER_MASK);
	WR_WORD(AUDIO_REGS_AURX_CTRL1, reg);
}

static __inline void audio_rx_lpf2_dec_execute()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL1);
	reg |= AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_LPF2_DEC;
	WR_WORD(AUDIO_REGS_AURX_CTRL1, reg);
}

static __inline void audio_rx_lpf2_dec_bypass()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL1);
	reg &= ~AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_LPF2_DEC;
	WR_WORD(AUDIO_REGS_AURX_CTRL1, reg);
}

static __inline void audio_rx_set_gain_left(uint16_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL1);
	reg &= ~AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_GAINL;
	reg |= ((val & AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_GAINL_MASK) << AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_GAINL_SHIFT);
	WR_WORD(AUDIO_REGS_AURX_CTRL1, reg);
}

static __inline uint16_t audio_rx_get_gain_left() {
	return (RD_WORD(AUDIO_REGS_AURX_CTRL1) >> AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_GAINL_SHIFT) & AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_GAINL_MASK;
}

static __inline void audio_rx_set_gain_right(uint16_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL1);
	reg &= ~AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_GAINR;
	reg |= ((val & AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_GAINR_MASK) << AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_GAINR_SHIFT);
	WR_WORD(AUDIO_REGS_AURX_CTRL1, reg);
}

static __inline uint16_t audio_rx_get_gain_right() {
	return (RD_WORD(AUDIO_REGS_AURX_CTRL1) >> AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_GAINR_SHIFT) & AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_GAINR_MASK;
}

static __inline void audio_rx_set_i2s_delay(uint8_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AURX_CTRL1);
	reg &= ~AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_I2S_DEL;
	reg |= ((val & AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_I2S_DEL_MASK) << AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_I2S_DEL_SHIFT);
	WR_WORD(AUDIO_REGS_AURX_CTRL1, reg);
}

static __inline void audio_rx_set_aenc_pkt_fifo_th(uint8_t thresh)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg &= ~AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_PKT_FIFO_TH;
	reg |= ((thresh >> AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_PKT_FIFO_TH_SHIFT) & AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_PKT_FIFO_TH_MASK);
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_set_aenc_num_samp_per_blk(uint16_t size)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg &= ~AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_SIZE;
	reg |= ((size & AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_SIZE_MASK) << AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_SIZE_SHIFT);
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_set_aenc_mode(uint8_t mode)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg &= ~AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_MODE;
	reg |= ((mode & AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_MODE_MASK) << AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_MODE_SHIFT);
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_set_aenc_fsamppredic()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg |= AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_FSAMPPREDIC;
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_clr_aenc_fsamppredic()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg &= ~AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_FSAMPPREDIC;
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_set_aenc_skip_fsamp()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg |= AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_SKIP_FSAMP;
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_clr_aenc_skip_fsamp()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg &= ~AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_SKIP_FSAMP;
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline uint8_t audio_rx_get_aenc_skip_fsamp()
{
	return ((RD_WORD(AUDIO_REGS_AENC_CTRL0) & AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_SKIP_FSAMP) > 0) ? 1 : 0;
}

static __inline uint16_t audio_rx_init_aenc_num_samp_per_blk(int num_bytes_per_frame, int stereo_mode)
{
	uint16_t val;
	if(stereo_mode)
		val = ((num_bytes_per_frame/2 - 3) * 2) + audio_rx_get_aenc_skip_fsamp();
	else
		val = ((num_bytes_per_frame - 3) * 2) + audio_rx_get_aenc_skip_fsamp();
	audio_rx_set_aenc_num_samp_per_blk(val);
	return val;
}

static __inline void audio_rx_set_aenc_predic_end()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg |= AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_PREDIC_END;
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_clr_aenc_predic_end()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg &= ~AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_PREDIC_END;
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline uint8_t audio_rx_get_aenc_predic_end()
{
	return ((RD_WORD(AUDIO_REGS_AENC_CTRL0) & AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_PREDIC_END) > 0) ? 1 : 0;
}

static __inline void audio_rx_set_aenc_lsb4first()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg |= AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_LSB4FIRST;
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_clr_aenc_lsb4first()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg &= ~AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_LSB4FIRST;
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_set_aenc_applepredic()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg |= AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_APPLEPREDIC;
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_clr_aenc_applepredic()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg &= ~AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_APPLEPREDIC;
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_set_aenc_rst_stepidx()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg |= AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_RST_STEPIDX;
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_clr_aenc_rst_stepidx()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg &= ~AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_RST_STEPIDX;
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_set_aenc_rst_predict()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg |= AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_RST_PREDICT;
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_clr_aenc_rst_predict()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg &= ~AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_RST_PREDICT;
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_set_aenc_wr_priority()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg |= AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_WR_PRIORITY;
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_clr_aenc_wr_priority()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AENC_CTRL0);
	reg &= ~AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_WR_PRIORITY;
	WR_WORD(AUDIO_REGS_AENC_CTRL0, reg);
}

static __inline void audio_rx_set_aenc_max_addr()
{
	uint16_t reg = CFG_SMEM_AUDIO_RX & 0xFFF;
	if(reg >= 0x800)
		reg = 0x7FF;
	WR_WORD(AUDIO_REGS_AENC_CTRL1, reg);
}

static __inline uint8_t audio_get_aenc_dma_fifo_rptr()
{
	return ((RD_WORD(AUDIO_REGS_AENC_STAT0) >> AUDIO_REGS_AENC_STAT0_STS_AENC_DMA_FIFO_RPTR_SHIFT) & AUDIO_REGS_AENC_STAT0_STS_AENC_DMA_FIFO_RPTR_MASK);
}

static __inline uint8_t audio_get_aenc_dma_fifo_wptr()
{
	return ((RD_WORD(AUDIO_REGS_AENC_STAT0) >> AUDIO_REGS_AENC_STAT0_STS_AENC_DMA_FIFO_WPTR_SHIFT) & AUDIO_REGS_AENC_STAT0_STS_AENC_DMA_FIFO_WPTR_MASK);
}

static __inline void audio_tx_set_adec_num_samp_per_blk(uint16_t size)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_CTRL0);
	reg &= ~AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_SIZE;
	reg |= ((size & AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_SIZE_MASK) >> AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_SIZE_SHIFT);
	WR_WORD(AUDIO_REGS_ADEC_CTRL0, reg);
}

static __inline void audio_tx_set_adec_mode(uint8_t mode)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_CTRL0);
	reg &= ~AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_MODE;
	reg |= ((mode & AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_MODE_MASK) << AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_MODE_SHIFT);
	WR_WORD(AUDIO_REGS_ADEC_CTRL0, reg);
}

static __inline void audio_tx_set_adec_predicfsamp()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_CTRL0);
	reg |= AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_PREDICFSAMP;
	WR_WORD(AUDIO_REGS_ADEC_CTRL0, reg);
}

static __inline void audio_tx_clr_adec_predicfsamp()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_CTRL0);
	reg &= ~AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_PREDICFSAMP;
	WR_WORD(AUDIO_REGS_ADEC_CTRL0, reg);
}

static __inline uint8_t audio_tx_get_adec_predicfsamp()
{
	return ((RD_WORD(AUDIO_REGS_ADEC_CTRL0) & AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_PREDICFSAMP) > 0) ? 1 : 0;
}

static __inline uint16_t audio_tx_init_adec_num_samp_per_blk(int num_bytes_per_frame, int stereo_mode)
{
	uint16_t val;
	if(stereo_mode)
		val = ((num_bytes_per_frame/2 - 3) * 2) + audio_tx_get_adec_predicfsamp();
	else
		val = (num_bytes_per_frame - 3) + audio_tx_get_adec_predicfsamp();
	audio_tx_set_adec_num_samp_per_blk(val);
	return val;
}

static __inline void audio_tx_set_adec_predic_end()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_CTRL0);
	reg |= AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_PREDIC_END;
	WR_WORD(AUDIO_REGS_ADEC_CTRL0, reg);
}

static __inline void audio_tx_clr_adec_predic_end()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_CTRL0);
	reg &= ~AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_PREDIC_END;
	WR_WORD(AUDIO_REGS_ADEC_CTRL0, reg);
}

static __inline void audio_tx_set_adec_lsb4first()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_CTRL0);
	reg |= AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_LSB4FIRST;
	WR_WORD(AUDIO_REGS_ADEC_CTRL0, reg);
}

static __inline void audio_tx_clr_adec_lsb4first()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_CTRL0);
	reg &= ~AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_LSB4FIRST;
	WR_WORD(AUDIO_REGS_ADEC_CTRL0, reg);
}

static __inline void audio_tx_set_adec_rst_stepidx()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_CTRL0);
	reg |= AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_RST_STEPIDX;
	WR_WORD(AUDIO_REGS_ADEC_CTRL0, reg);
}

static __inline void audio_tx_clr_adec_rst_stepidx()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_CTRL0);
	reg &= ~AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_RST_STEPIDX;
	WR_WORD(AUDIO_REGS_ADEC_CTRL0, reg);
}

static __inline void audio_tx_set_adec_rst_predict()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_CTRL0);
	reg |= AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_RST_PREDICT;
	WR_WORD(AUDIO_REGS_ADEC_CTRL0, reg);
}

static __inline void audio_tx_clr_adec_rst_predict()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_CTRL0);
	reg &= ~AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_RST_PREDICT;
	WR_WORD(AUDIO_REGS_ADEC_CTRL0, reg);
}

static __inline void audio_tx_set_adec_max_addr()
{
	uint16_t val = CFG_SMEM_AUDIO_TX & 0xFFF;
	if(val >= 0x800)
		val = 0x7FF;
	
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_CTRL0);
	reg &= ~AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_MAX_ADDR;
	reg |= ((val & AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_MAX_ADDR_MASK) << AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_MAX_ADDR_SHIFT);
	WR_WORD(AUDIO_REGS_ADEC_CTRL0, reg);
}

static __inline uint16_t audio_tx_get_adec_max_addr()
{
	return ((RD_WORD(AUDIO_REGS_ADEC_CTRL0) >> AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_MAX_ADDR_SHIFT) & AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_MAX_ADDR_MASK);
}

static __inline void audio_tx_bypass_itpto32_lpf_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL0);
	reg |= AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO32_BYP_LPF;
	WR_WORD(AUDIO_REGS_AUTX_CTRL0, reg);
}

static __inline void audio_tx_bypass_itpto32_lpf_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL0);
	reg &= ~AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO32_BYP_LPF;
	WR_WORD(AUDIO_REGS_AUTX_CTRL0, reg);
}

static __inline void audio_tx_bypass_itpto32_up2_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL0);
	reg |= AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO32_BYP_UP2;
	WR_WORD(AUDIO_REGS_AUTX_CTRL0, reg);
}

static __inline void audio_tx_bypass_itpto32_up2_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL0);
	reg &= ~AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO32_BYP_UP2;
	WR_WORD(AUDIO_REGS_AUTX_CTRL0, reg);
}

static __inline void audio_tx_set_itpto32_per(uint16_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL0);
	reg &= ~AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO32_PER;
	reg |= ((val & AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO32_PER_MASK) << AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO32_PER_SHIFT);
	WR_WORD(AUDIO_REGS_AUTX_CTRL0, reg);
}

static __inline void audio_tx_bypass_itpto64_lpf_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL0);
	reg |= AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO64_BYP_LPF;
	WR_WORD(AUDIO_REGS_AUTX_CTRL0, reg);
}

static __inline void audio_tx_bypass_itpto64_lpf_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL0);
	reg &= ~AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO64_BYP_LPF;
	WR_WORD(AUDIO_REGS_AUTX_CTRL0, reg);
}

static __inline void audio_tx_set_itpto64_per(uint16_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL0);
	reg &= ~AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO64_PER;
	reg |= ((val & AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO64_PER_MASK) << AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO64_PER_SHIFT);
	WR_WORD(AUDIO_REGS_AUTX_CTRL0, reg);
}

static __inline void audio_tx_bypass_itpto128_lpf_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL0);
	reg |= AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO128_BYP_LPF;
	WR_WORD(AUDIO_REGS_AUTX_CTRL0, reg);
}

static __inline void audio_tx_bypass_itpto128_lpf_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL0);
	reg &= ~AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO128_BYP_LPF;
	WR_WORD(AUDIO_REGS_AUTX_CTRL0, reg);
}

static __inline void audio_tx_set_itpto128_per(uint16_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL0);
	reg &= ~AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO128_PER;
	reg |= ((val & AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO128_PER_MASK) << AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO128_PER_SHIFT);
	WR_WORD(AUDIO_REGS_AUTX_CTRL0, reg);
}

static __inline void audio_tx_set_audio_tx_in_dma_sharedmem()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL0);
	reg |= AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_SEL_IN;
	WR_WORD(AUDIO_REGS_AUTX_CTRL0, reg);
}

static __inline void audio_tx_set_audio_tx_in_adpcm()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL0);
	reg &= ~AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_SEL_IN;
	WR_WORD(AUDIO_REGS_AUTX_CTRL0, reg);
}
																						
static __inline void audio_tx_set_vid_nomrate(uint32_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL1);
	reg &= ~AUDIO_REGS_AUTX_CTRL1_CTLQ_AUTX_VID_NOMRATE;
	reg |= ((val & AUDIO_REGS_AUTX_CTRL1_CTLQ_AUTX_VID_NOMRATE_MASK) << AUDIO_REGS_AUTX_CTRL1_CTLQ_AUTX_VID_NOMRATE_SHIFT);
	WR_WORD(AUDIO_REGS_AUTX_CTRL1, reg);
}
																						
static __inline void audio_tx_set_vid_invrate(uint16_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL2);
	reg &= ~AUDIO_REGS_AUTX_CTRL2_CTLQ_AUTX_VID_INVRATE;
	reg |= ((val & AUDIO_REGS_AUTX_CTRL2_CTLQ_AUTX_VID_INVRATE_MASK) << AUDIO_REGS_AUTX_CTRL2_CTLQ_AUTX_VID_INVRATE_SHIFT);
	WR_WORD(AUDIO_REGS_AUTX_CTRL2, reg);
}

static __inline void audio_tx_set_gainr(uint16_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL2);
	reg &= ~AUDIO_REGS_AUTX_CTRL2_CTLQ_AUTX_GAINR;
	reg |= ((val & AUDIO_REGS_AUTX_CTRL2_CTLQ_AUTX_GAINR_MASK) << AUDIO_REGS_AUTX_CTRL2_CTLQ_AUTX_GAINR_SHIFT);
	WR_WORD(AUDIO_REGS_AUTX_CTRL2, reg);
}																			

static __inline void audio_tx_set_out_per(uint8_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL3);
	reg &= ~AUDIO_REGS_AUTX_CTRL3_CTLT_AUTX_OUT_PER;
	reg |= ((val & AUDIO_REGS_AUTX_CTRL3_CTLT_AUTX_OUT_PER_MASK) << AUDIO_REGS_AUTX_CTRL3_CTLT_AUTX_OUT_PER_SHIFT);
	WR_WORD(AUDIO_REGS_AUTX_CTRL3, reg);
}

static __inline void audio_tx_set_gainl(uint16_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_CTRL3);
	reg &= ~AUDIO_REGS_AUTX_CTRL3_CTLQ_AUTX_GAINL;
	reg |= ((val & AUDIO_REGS_AUTX_CTRL3_CTLQ_AUTX_GAINL_MASK) << AUDIO_REGS_AUTX_CTRL3_CTLQ_AUTX_GAINL_SHIFT);
	WR_WORD(AUDIO_REGS_AUTX_CTRL3, reg);
}
																						
static __inline void audio_tx_set_adec_pcm_freq_den(uint16_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_RATE_CTRL0);
	reg &= ~AUDIO_REGS_ADEC_RATE_CTRL0_CTLQ_ADEC_PCM_FREQ_DEN;
	reg |= ((val & AUDIO_REGS_ADEC_RATE_CTRL0_CTLQ_ADEC_PCM_FREQ_DEN_MASK) << AUDIO_REGS_ADEC_RATE_CTRL0_CTLQ_ADEC_PCM_FREQ_DEN_SHIFT);
	WR_WORD(AUDIO_REGS_ADEC_RATE_CTRL0, reg);
}

static __inline void audio_tx_set_adec_pcm_freq_num(uint16_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_RATE_CTRL0);
	reg &= ~AUDIO_REGS_ADEC_RATE_CTRL0_CTLQ_ADEC_PCM_FREQ_NUM;
	reg |= ((val & AUDIO_REGS_ADEC_RATE_CTRL0_CTLQ_ADEC_PCM_FREQ_NUM_MASK) << AUDIO_REGS_ADEC_RATE_CTRL0_CTLQ_ADEC_PCM_FREQ_NUM_SHIFT);
	WR_WORD(AUDIO_REGS_ADEC_RATE_CTRL0, reg);
}

static __inline void audio_rx_enable_rd_dma_ack()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_DMA_CTRL0);
	reg |= AUDIO_REGS_ADEC_DMA_CTRL0_CTLQ_REG_DMA_RD_ACK;
	WR_WORD(AUDIO_REGS_ADEC_DMA_CTRL0, reg);
}

static __inline void audio_rx_disable_rd_dma_ack()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_DMA_CTRL0);
	reg &= ~AUDIO_REGS_ADEC_DMA_CTRL0_CTLQ_REG_DMA_RD_ACK;
	WR_WORD(AUDIO_REGS_ADEC_DMA_CTRL0, reg);
}

static __inline void audio_tx_enable_wr_dma_ack()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_DMA_CTRL0);
	reg |= AUDIO_REGS_ADEC_DMA_CTRL0_CTLQ_REG_DMA_WR_ACK;
	WR_WORD(AUDIO_REGS_ADEC_DMA_CTRL0, reg);
}

static __inline void audio_tx_disable_wr_dma_ack()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_ADEC_DMA_CTRL0);
	reg &= ~AUDIO_REGS_ADEC_DMA_CTRL0_CTLQ_REG_DMA_WR_ACK;
	WR_WORD(AUDIO_REGS_ADEC_DMA_CTRL0, reg);
}
																						
static __inline uint16_t audio_get_adec_bytes_in_ram()
{
	return ((RD_WORD(AUDIO_REGS_ADEC_DMA_STAT0) & AUDIO_REGS_ADEC_DMA_STAT0_STS_ADEC_BYTES_IN_RAM));
}
																						
static __inline uint16_t audio_get_aenc_dma_rd_req()
{
	return ((RD_WORD(AUDIO_REGS_ADEC_DMA_STAT0) & AUDIO_REGS_ADEC_DMA_STAT0_STS_AENC_DMA_RD_REQ) > 0) ? 1 : 0;
}

static __inline uint8_t audio_get_adec_dma_fifo_full()
{
	return ((RD_WORD(AUDIO_REGS_ADEC_DMA_STAT0) & AUDIO_REGS_ADEC_DMA_STAT0_STS_ADEC_DMA_FIFO_FULL) > 0) ? 1 : 0;
}

static __inline uint16_t audio_get_aenc_bytes_in_ram()
{
	return ((RD_WORD(AUDIO_REGS_ADEC_DMA_STAT0) >> AUDIO_REGS_ADEC_DMA_STAT0_STS_AENC_BYTES_IN_RAM_SHIFT) & AUDIO_REGS_ADEC_DMA_STAT0_STS_AENC_BYTES_IN_RAM_MASK);
}
																						
static __inline uint16_t audio_get_adec_dma_wr_req()
{
	return ((RD_WORD(AUDIO_REGS_ADEC_DMA_STAT0) & AUDIO_REGS_ADEC_DMA_STAT0_STS_ADEC_DMA_WR_REQ) > 0) ? 1 : 0;
}

static __inline uint8_t audio_get_aenc_dma_fifo_full()
{
	return ((RD_WORD(AUDIO_REGS_ADEC_DMA_STAT0) & AUDIO_REGS_ADEC_DMA_STAT0_STS_AENC_DMA_FIFO_FULL) > 0) ? 1 : 0;
}
																						
static __inline uint32_t audio_rx_dma_read()
{
	return RD_WORD(AUDIO_REGS_DMA_READ);
}
																						
static __inline void audio_tx_dma_write(uint32_t data)
{
	WR_WORD(AUDIO_REGS_ADEC_DMA_WRITE, data);
}
																						
static __inline void audio_rx_pdm_init_clk0(uint8_t audio_pdm_clk_period, uint8_t wss_l_low)
{
	uint32_t reg = 0;
	reg |= audio_pdm_clk_period;
	uint32_t val = (reg + 1) / 2;
	reg |= (val << AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_FALL_SHIFT);
	val = val / 2;
	uint8_t x = 0xFF;
	reg &= ~(x << AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_LCNT_SHIFT);
	reg &= ~(x << AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_RCNT_SHIFT);
	if(wss_l_low) {
		reg |= ((val) << AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_LCNT_SHIFT);
		reg |= ((val * 3) << AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_RCNT_SHIFT);
	}
	else {
		reg |= ((val) << AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_RCNT_SHIFT);
		reg |= ((val * 3) << AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_LCNT_SHIFT);
	}
	WR_WORD(AUDIO_REGS_PDM_CTRL0, reg);
}
																						
static __inline void audio_rx_pdm_init_clk1(uint8_t audio_pdm_clk_period, uint8_t pdm_l_core, uint8_t pdm_r_core)
{
	uint32_t reg = (audio_pdm_clk_period | (uint32_t) (pdm_l_core << 8) | (uint32_t)(pdm_l_core << 9));
	WR_WORD(AUDIO_REGS_PDM_CTRL1, reg);
}
																						
static __inline void audio_rdsm_dma_sel_audiotx()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_SM_CTRL0);
	reg |= AUDIO_REGS_AUTX_SM_CTRL0_CTLQ_SM_DMA_RD_SEL;
	WR_WORD(AUDIO_REGS_AUTX_SM_CTRL0, reg);
}

static __inline void audio_rdsm_dma_sel_adpcm()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_SM_CTRL0);
	reg &= ~AUDIO_REGS_AUTX_SM_CTRL0_CTLQ_SM_DMA_RD_SEL;
	WR_WORD(AUDIO_REGS_AUTX_SM_CTRL0, reg);
}

static __inline void audio_rdsm_autx_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_SM_CTRL0);
	reg |= AUDIO_REGS_AUTX_SM_CTRL0_CTLT_AUTX_SM_EN;
	WR_WORD(AUDIO_REGS_AUTX_SM_CTRL0, reg);
}

static __inline void audio_rdsm_autx_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_SM_CTRL0);
	reg &= ~AUDIO_REGS_AUTX_SM_CTRL0_CTLT_AUTX_SM_EN;
	WR_WORD(AUDIO_REGS_AUTX_SM_CTRL0, reg);
}

static __inline void audio_rdsm_set_max_addr()
{
	uint16_t val = (CFG_SMEM_AUDIO_RX & 0xFFF) / 4;
	if(val >= 0x800)
		val = 0x7FF;
	
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_SM_CTRL0);
	reg &= ~AUDIO_REGS_AUTX_SM_CTRL0_CTLQ_AUTX_MAX_ADDR;
	WR_WORD(AUDIO_REGS_AUTX_SM_CTRL0, val);
}

static __inline uint16_t audio_rdsm_get_max_addr()
{
	return ((RD_WORD(AUDIO_REGS_AUTX_SM_CTRL0) >> AUDIO_REGS_AUTX_SM_CTRL0_CTLQ_AUTX_MAX_ADDR_SHIFT) & AUDIO_REGS_AUTX_SM_CTRL0_CTLQ_AUTX_MAX_ADDR_MASK);
}

static __inline uint16_t audio_rdsm_get_rd_buf_samps()
{
	return ((RD_WORD(AUDIO_REGS_AUTX_SM_STAT0) >> AUDIO_REGS_AUTX_SM_STAT0_STS_AUTX_RD_BUF_SAMPS_SHIFT) & AUDIO_REGS_AUTX_SM_STAT0_STS_AUTX_RD_BUF_SAMPS_MASK);
}

static __inline uint16_t audio_rdsm_get_pkt_fifo_fill()
{
	return ((RD_WORD(AUDIO_REGS_AUTX_SM_STAT0) >> AUDIO_REGS_AUTX_SM_STAT0_STS_AUTX_PKT_FIFO_FILL_SHIFT) & AUDIO_REGS_AUTX_SM_STAT0_STS_AUTX_PKT_FIFO_FILL_MASK);
}

static __inline uint16_t audio_rdsm_get_dma_fifo_fill()
{
	return ((RD_WORD(AUDIO_REGS_AUTX_SM_STAT0) >> AUDIO_REGS_AUTX_SM_STAT0_STS_AUTX_DMA_FIFO_FILL_SHIFT) & AUDIO_REGS_AUTX_SM_STAT0_STS_AUTX_DMA_FIFO_FILL_MASK);
}
																						
static __inline void audio_wrsm_dma_sel_audiotx()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_WRSM_CTRL0);
	reg |= AUDIO_REGS_AUTX_WRSM_CTRL0_CTLQ_SM_DMA_WR_SEL;
	WR_WORD(AUDIO_REGS_AUTX_WRSM_CTRL0, reg);
}

static __inline void audio_wrsm_dma_sel_adpcm()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_WRSM_CTRL0);
	reg &= ~AUDIO_REGS_AUTX_WRSM_CTRL0_CTLQ_SM_DMA_WR_SEL;
	WR_WORD(AUDIO_REGS_AUTX_WRSM_CTRL0, reg);
}

static __inline void audio_wrsm_autx_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_WRSM_CTRL0);
	reg |= AUDIO_REGS_AUTX_WRSM_CTRL0_CTLT_WRSM_EN;
	WR_WORD(AUDIO_REGS_AUTX_WRSM_CTRL0, reg);
}

static __inline void audio_wrsm_autx_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_WRSM_CTRL0);
	reg &= ~AUDIO_REGS_AUTX_WRSM_CTRL0_CTLT_WRSM_EN;
	WR_WORD(AUDIO_REGS_AUTX_WRSM_CTRL0, reg);
}

static __inline void audio_wrsm_autx_pull_enable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_WRSM_CTRL0);
	reg |= AUDIO_REGS_AUTX_WRSM_CTRL0_CTLT_WRSM_PULL_EN;
	WR_WORD(AUDIO_REGS_AUTX_WRSM_CTRL0, reg);
}

static __inline void audio_wrsm_autx_pull_disable()
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_WRSM_CTRL0);
	reg &= ~AUDIO_REGS_AUTX_WRSM_CTRL0_CTLT_WRSM_PULL_EN;
	WR_WORD(AUDIO_REGS_AUTX_WRSM_CTRL0, reg);
}

static __inline void audio_wrsm_set_max_addr()
{
	uint16_t val = (CFG_SMEM_AUDIO_TX & 0xFFF) / 4;
	if(val >= 0x800)
		val = 0x7FF;
	
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_WRSM_CTRL0);
	reg &= ~AUDIO_REGS_AUTX_WRSM_CTRL0_CTLT_WRSM_MAX_ADDR;
	WR_WORD(AUDIO_REGS_AUTX_WRSM_CTRL0, val);
}

static __inline uint16_t audio_wrsm_get_max_addr()
{
	return ((RD_WORD(AUDIO_REGS_AUTX_WRSM_CTRL0) >> AUDIO_REGS_AUTX_WRSM_CTRL0_CTLT_WRSM_MAX_ADDR_SHIFT) & AUDIO_REGS_AUTX_WRSM_CTRL0_CTLT_WRSM_MAX_ADDR_MASK);
}
																						
static __inline void audio_wrsm_set_pull_den(uint16_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_WRSM_CTRL1);
	reg &= ~AUDIO_REGS_AUTX_WRSM_CTRL1_CTLQ_WRSM_PULL_DEN;
	reg |= ((val & AUDIO_REGS_AUTX_WRSM_CTRL1_CTLQ_WRSM_PULL_DEN_MASK) << AUDIO_REGS_AUTX_WRSM_CTRL1_CTLQ_WRSM_PULL_DEN_SHIFT);
	WR_WORD(AUDIO_REGS_AUTX_WRSM_CTRL1, reg);
}

static __inline void audio_wrsm_set_pull_num(uint16_t val)
{
	uint32_t reg = RD_WORD(AUDIO_REGS_AUTX_WRSM_CTRL1);
	reg &= ~AUDIO_REGS_AUTX_WRSM_CTRL1_CTLQ_WRSM_PULL_NUM;
	reg |= ((val & AUDIO_REGS_AUTX_WRSM_CTRL1_CTLQ_WRSM_PULL_NUM_MASK) << AUDIO_REGS_AUTX_WRSM_CTRL1_CTLQ_WRSM_PULL_NUM_SHIFT);
	WR_WORD(AUDIO_REGS_AUTX_WRSM_CTRL1, reg);
}
																						
static __inline uint16_t audio_wrsm_get_wr_buf_samps()
{
	return ((RD_WORD(AUDIO_REGS_AUTX_WRSM_STAT0) >> AUDIO_REGS_AUTX_WRSM_STAT0_STS_AUTX_WR_BUF_SAMPS_SHIFT) & AUDIO_REGS_AUTX_WRSM_STAT0_STS_AUTX_WR_BUF_SAMPS_MASK);
}

static __inline uint16_t audio_wrsm_get_dmafifo_wfill()
{
	return ((RD_WORD(AUDIO_REGS_AUTX_WRSM_STAT0) >> AUDIO_REGS_AUTX_WRSM_STAT0_STS_WRSM_DMAFIFO_WFILL_SHIFT) & AUDIO_REGS_AUTX_WRSM_STAT0_STS_WRSM_DMAFIFO_WFILL_MASK);
}

static __inline uint16_t audio_wrsm_get_outfifo_fill()
{
	return ((RD_WORD(AUDIO_REGS_AUTX_WRSM_STAT0) >> AUDIO_REGS_AUTX_WRSM_STAT0_STS_WRSM_OUTFIFO_FILL_SHIFT) & AUDIO_REGS_AUTX_WRSM_STAT0_STS_WRSM_OUTFIFO_FILL_MASK);
}

static __inline uint16_t audio_wrsm_get_samps_in_mem()
{
	return ((RD_WORD(AUDIO_REGS_AUTX_WRSM_STAT0) >> AUDIO_REGS_AUTX_WRSM_STAT0_STS_WRSM_SAMPS_IN_MEM_SHIFT) & AUDIO_REGS_AUTX_WRSM_STAT0_STS_WRSM_SAMPS_IN_MEM_MASK);
}

/*
 ****************************************************************************************
 * IMPLEMENTATION
 ****************************************************************************************
 */

/// Audio function status return
typedef enum {
	/// No error. Good status. 
	AUDIO_ERR_OK = 0,
	/// Error, AUDIO driver not initialized
	AUDIO_ERR_NOT_INIT = 1,
	/// Error, AUDIO driver already initialized
	AUDIO_ERR_ALREADY_INIT = 2,
	/// Error, AUDIO bad state 
	AUDIO_ERR_DEV_BAD_STATE = 3,
	/// Error, invalid AUDIO parameter. 
	AUDIO_ERR_INVALID_PARA = 4,
	/// Error, current operation block.
	AUDIO_ERR_OP_BLOCKED = 5,
	/// Error, configuration not initialized.
	AUDIO_ERR_NO_AUDIO_CONFIG = 6,
	/// Error, HW GPIO configuration error.
	AUDIO_ERR_BAD_HW_GPIO_CONFIG = 7,
	/// Error, Audio interrupt trigger.
	AUDIO_ERR_AUDIO_HW_INTR = 8,
} audio_status_t;

// DEFAULT INITIALIZATION
/**
 ****************************************************************************************
 * @brief Initialize encode functionality.
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_enc_open(void);

/**
 ****************************************************************************************
 * @brief Initialize decode functionality.
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_dec_open(void);

/**
 ****************************************************************************************
 * @brief Initialize resample functionality.
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_resample_open(void);

/**
 ****************************************************************************************
 * @brief Clean-up encode functionality.
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_enc_close(void);

/**
 ****************************************************************************************
 * @brief Clean-up decode functionality.
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_dec_close(void);

/**
 ****************************************************************************************
 * @brief Clean-up resample functionality.
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_resample_close(void);

// CONFIGURATION SET 
/**
 ****************************************************************************************
 * @brief Configure PDM mic input control.
 *
 * @param[in] pdm_l_core						0 if pdm left input is connected to pin pdm data 0, 1 if connected to pin pdm data 1.
 * @param[in] pdm_r_core						0 if pdm right input is connected to pin pdm data 0, 1 if connected to pin pdm data 1.
 * @param[in] wss_l_low							0 if pdm left input is set during word select signal low, 1 if set during signal high. 
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_enc_set_pdm_mic_inp(int pdm_l_core, int pdm_r_core, int wss_l_low);

/**
 ****************************************************************************************
 * @brief Configure encode frame header endianness.
 *
 * @param[in] is_little_end					1 if frame header predict bytes in little-endian format, 0 if big-endian format.
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_enc_set_predict_endianness(int is_little_end);

/**
 ****************************************************************************************
 * @brief Configure decode frame header endianness.
 *
 * @param[in] is_little_end					1 if frame header predict bytes in little-endian format, 0 if big-endian format.
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_dec_set_predict_endianness(int is_little_end);

/**
 ****************************************************************************************
 * @brief Configure audio_control encode function settings.
 *
 * @param[in] is_pdm								1 if audio encode input is PDM mic, 0 if input is I2S mic.
 * @param[in] is_I2S_master					1 if audio encode input is I2S mic connected to I2S master core, 0 if input is I2S mic connected to I2S slave core, otherwise don't care.
 * @param[in] in_rate								Audio encode microphone input sampling rate in float format. 
 * @param[in] is_stereo							1 if audio sample format is stereo, 0 if format is mono.
 * @param[in] out_rate							Audio encode output encoded data rate in float format.
 * @param[in] bytes_per_frame				Number of total bytes per encoded audio frame. Max 512 bytes. 
 * @param[in] gain									Left/Right gain setting. 
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_enc_set_config(int is_pdm, int is_I2S_master, float in_rate, float out_rate, int is_stereo, int bytes_per_frame, int gain);
/**
 ****************************************************************************************
 * @brief Configure audio_control decode function settings.
 *
 * @param[in] is_i2s								1 if audio decode output is i2s output path, 0 if output is sigma delta output path.
 * @param[in] is_I2S_master					1 if audio decode output is I2S connected to I2S master core, 0 if output is I2S connected to I2S slave core, otherwise don't care.
 * @param[in] in_rate								Audio input encoded data rate in float format. 
 * @param[in] is_stereo							1 if audio sample format is stereo, 0 if format is mono.
 * @param[in] out_rate							Audio decode output decoded data rate in float format.
 * @param[in] out_clk_src						Audio decode clock rate source. 0 if source is I2S Master, 1 if source is I2S Slave, 2 if source is PDM clock.
 *																	If clock source is PDM, hardware will internally configure clock. 
 *																	If clock source is I2S Master or I2S Slave, user must generate and/or supply clock signal.
 * @param[in] out_clk_rate					Audio decode clock rate used to generate audio decode out rate in float format.
 * @param[in] bytes_per_frame				Number of total bytes per decoded audio frame. Max 512 bytes. 
 * @param[in] gain									Left/Right gain setting. 
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_dec_set_config(int is_i2s, int is_I2S_master, float in_rate, float out_rate, uint8_t out_clk_src, float out_clk_rate, int is_stereo, int bytes_per_frame, int gain);

/**
 ****************************************************************************************
 * @brief Configure audio_control resample function settings.
 *
 * @param[in] in_rate								Audio resample input sampling rate in float format. 
 * @param[in] is_stereo							1 if audio sample format is stereo, 0 if format is mono.
 * @param[in] out_rate							Audio resample output sampling rate in float format.
 * @param[in] gain									Left/Right gain setting. 
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_resample_set_config(float in_rate, float out_rate, int is_stereo, int gain);

/**
 ****************************************************************************************
 * @brief Configure audio_control resample function settings.
 *
 * @param[in] in_rate								Audio resample input sampling rate in float format. 
 * @param[in] is_stereo							1 if audio sample format is stereo, 0 if format is mono.
 * @param[in] out_rate							Audio resample output sampling rate in float format.
 * @param[in] gain									Left/Right gain setting. 
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_resample_set_config(float in_rate, float out_rate, int is_stereo, int gain);

/**
 ****************************************************************************************
 * @brief Calibrate PDM Encoder DC Offset. Must be called after hal_audio_enc_set_config. 
 * 				Once called, user must execute function again to re-calibrate.
 *
 * @param[in] bytes_per_frame				Number of total bytes per encoded audio frame. Max 512 bytes. 
 * @param[in] is_stereo							1 if audio sample format is stereo, 0 if format is mono.
 * @param[in] num_frames_skip				Number of initial frames to skip when sampling dc offset
 * @param[in] num_frames_samp				Number of frames to measure when sampling dc offset
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_enc_pdm_dc_offset_cal(int bytes_per_frame, int is_stereo, int num_frames_skip, int num_frames_samp);

// START
/**
 ****************************************************************************************
 * @brief Begin encode audio functionality based on current configuration.
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_encode_start(void);

/**
 ****************************************************************************************
 * @brief Request encoded data.
 *
 * @param[in] out_buf								Pointer to the output location where encoded data is to be written.
 * @param[in] buf_sz							Buffer size.
 * @param[out] in_size							Pointer to the requested number of encoded bytes of data. 
 *																	Location will be updated upon return with actual number of bytes written to output buffer.
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_encode_process(uint8_t* out_buf, uint32_t buf_sz, uint16_t* in_size);

/**
 ****************************************************************************************
 * @brief Begin decode audio functionality based on current configuration and input data.
 *
 * @param[in] in_buf								Pointer to the input location of encoded data to be decoded.
 * @param[in] buf_size							Buffer size
 * @param[out] in_size							return with actual number of bytes inserted into audio hardware.
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_decode_start(uint8_t* in_buf, uint16_t buf_size, uint16_t* in_size);

/**
 ****************************************************************************************
 * @brief Provide audio hardware with additional encoded data to be decoded.
 *
 * @param[in] in_buf								Pointer to the input encoded data to be decoded.
 * @param[in] buf_size							Buffer size
 * @param[out] in_size							return with actual number of bytes inserted into audio hardware.
 *																	
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_decode_process(uint8_t* in_buf, uint16_t buf_size, uint16_t* in_size);

/**
 ****************************************************************************************
 * @brief Execute resample audio functionality based on current configuration and input data.
 *
 * @param[in] in_buf								Pointer to the input audio data to be resampled.
 * @param[in] in_size								Pointer to the requested number of bytes of data to be resampled.
 * @param[out] out_buf							Pointer to the output location where resampled data will be written.
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_resample_process(uint32_t* in_buf, uint16_t* in_size, uint32_t* out_buf);

// STOP 
/**
 ****************************************************************************************
 * @brief Stop encode audio functionality.
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_encode_stop(void);

/**
 ****************************************************************************************
 * @brief Stop decode audio functionality.
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_decode_stop(void);

/**
 ****************************************************************************************
 * @brief Stop resample audio functionality.
 *
 * @return AUDIO_ERR_OK if successful, error otherwise. @see enum audio_status_t.
 ****************************************************************************************
 */
int hal_audio_resample_stop(void);
/// @} HAL_AUDIO	
#endif


