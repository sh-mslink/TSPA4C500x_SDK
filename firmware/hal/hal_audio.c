#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_audio.c
 *
 * @brief Platform adpcm functions  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

/*
 ****************************************************************************************
 * INCLUDES
 ****************************************************************************************
 */
#define GPIO_ENABLED 1
#if CFG_AUDIO_EN
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "in_debug.h"
#include ".\hal\hal_power.h"
#include ".\hal\hal_i2s.h"
#include ".\hal\hal_clk.h"
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_audio.h"
#include "in_mmap.h"
#include "in_arm.h"
#include "in_irq.h"
#include "cmsis_os.h"

/*
 ****************************************************************************************
 * DEFINES
 ****************************************************************************************
 */
// Audio Settings Config	
typedef enum {
	MONO,
	STEREO
} audio_mode_t;										

typedef enum {
	MASTER,
	SLAVE
} audio_i2s_core_t;	

#define AUDIO_TX_CLK_RATE							16000000.0f
//static const int RX_PDM_CIC_DEC_FACTOR[7] = {20, 16, 10, 8, 5, 4, 2};
static const uint32_t RX_PDM_CIC_DEC_OFFSET[7] = {80000, 32768, 5000, 2048, 313, 128, 8};
static const uint8_t RX_PDM_CIC_DEC_SHIFT[7] = {0, 1, 4, 5, 8, 9, 13};
static const uint8_t RX_PDM_DOWNSAMPLES[9] = {200, 160, 100, 80, 50, 40, 25, 20, 10};
static const uint8_t RX_PDM_DOWNSAMPLE_CONFIG[9] = {1, 11, 21, 31, 41, 51, 40, 61, 60};
static const float RX_I2S_DOWNSAMPLES[4] = {0.4f, 0.5f, 0.8f, 1.0f};
static const uint8_t RX_I2S_DOWNSAMPLE_CONFIG[4] = {111, 11, 101, 110};
// RX Path Config 	
typedef enum {
	ENC_INPUT_PDM,
	ENC_INPUT_I2S
} audio_enc_inp_format_t;

typedef enum {
	CIC_DEC_20 = 0,
	CIC_DEC_16 = 1,
	CIC_DEC_10 = 2,
	CIC_DEC_8 = 3,
	CIC_DEC_5 = 4,
	CIC_DEC_4 = 5,
	CIC_DEC_2 = 6
} audio_rx_pdm_cic_dec_ctrl_t;

// TX Path Config 
typedef enum {
	AUDIO_TX_UP8,
	AUDIO_TX_UP4,
	AUDIO_TX_UP2,
	AUDIO_TX_UP0
} audio_tx_up2_filters_ctrl_t;

typedef enum {
	TX_OUT_SIG_DELT,
	TX_OUT_I2S
} audio_tx_out_path_t;

// HW GPIO Control
typedef struct {
	// GPIO_4_0_6 = pdm clk
	// GPIO_2_7_6 = pdm1 data
	// GPIO_2_8_6 = pdm0 data
	uint32_t pdm_clk_pin;
	uint32_t pdm_dat0_pin;
	uint32_t pdm_dat1_pin;
	
	// GPIO_1_3_4 = I2S master clk
	// GPIO_1_4_4 = I2S master wss
	// GPIO_1_5_4 = I2S master sd0
	// GPIO_1_6_4 = I2S master sd1
	uint32_t i2s_m_clk_pin;
	uint32_t i2s_m_ws_pin;
	uint32_t i2s_m_sd0_pin;
	uint32_t i2s_m_sd1_pin;
	
	// GPIO_1_3_5 = I2S slave clk
	// GPIO_1_4_5 = I2S slave wss
	// GPIO_1_5_5 = I2S slave sd0
	// GPIO_1_6_5 = I2S slave sd1	
	uint32_t i2s_s_clk_pin;
	uint32_t i2s_s_ws_pin;
	uint32_t i2s_s_sd0_pin;
	uint32_t i2s_s_sd1_pin;
	uint32_t audio_sd_left;
	uint32_t audio_sd_right;
} audio_gpio_dev_t;

// User Control
typedef struct {
	//RX Path control
	audio_enc_inp_format_t in_format;
	audio_i2s_core_t i2s_core;
	audio_rx_pdm_cic_dec_ctrl_t pdm_cic_dec;	
	uint8_t lpf2_filter_execute;
	uint8_t d5_filter_execute;
	uint8_t filterpath_execute;
	
	//RX Path control - PDM Mic CLK
	uint8_t pdm_l_core;
	uint8_t pdm_r_core;
	uint8_t wss_l_low;
	uint16_t pdm_clk_period;

	// Basic audio control
	float in_rate;	
	float out_rate;	
	uint16_t gain_left;
	uint16_t gain_right;
	audio_mode_t audio_mode;
	uint32_t num_bytes_per_frame;
	uint8_t predict_little_end;
	
	// User status control
	uint8_t enc_used;
	audio_status_t status;
	uint8_t isCalibrated;
	
	osMutexId mutex;
	osSemaphoreId semaphore; 

	/// Power 
#if CFG_PM_EN
	int power_state;
	struct pm_module pm;
#endif
} audio_rx_dev_t;

typedef struct {
	// TX path control
	audio_tx_out_path_t out_path;
	audio_i2s_core_t i2s_core;
	audio_tx_up2_filters_ctrl_t up2_filters;
	float out_clk_rate;	
	uint8_t out_clk_src;

	// Basic audio control
	float in_rate;	
	float out_rate;	
	uint16_t gain_left;
	uint16_t gain_right;
	audio_mode_t audio_mode;
	uint32_t num_bytes_per_frame;
	uint8_t predict_little_end;
	
	// User status control
	uint8_t dec_used;
	uint8_t resample_used;
	audio_status_t status;
	osMutexId mutex;
	osSemaphoreId semaphore; 

	/// Power 
#if CFG_PM_EN
	int power_state;
	struct pm_module pm;
#endif
} audio_tx_dev_t;

// Global Variables
static audio_gpio_dev_t audio_gpio_dev;
static audio_rx_dev_t audio_rx_dev;
static audio_tx_dev_t audio_tx_dev;
osMutexDef(rx_mutex);
osSemaphoreDef(rx_semaphore);
osMutexDef(tx_mutex);
osSemaphoreDef(tx_semaphore);
static int audio_rx_set_filterpath(int is_pdm, float in_rate, float out_rate);
/*
 ****************************************************************************************
 * IMPLEMENTATION
 ****************************************************************************************
 */
// Audio setting calculations
static uint32_t hal_audio_calc_ctlt_autx_out_per(float out_clock_src_rate, float out_rate) {	
	return (uint32_t) ( (out_clock_src_rate / out_rate) - 1.0f );
}

static uint32_t hal_audio_calc_tx_interp32_period(float in_rate) {
	float f = AUDIO_TX_CLK_RATE / in_rate / 2.0f;
	if(f >= 1024.0f)
		f = 1023.0f;
	return (uint32_t) f;
}

static uint32_t hal_audio_calc_tx_vid_nom_rate(float in_rate, float out_rate) {
	audio_tx_dev_t* pd = &audio_tx_dev;
	float val;
	switch(pd->up2_filters) {
		case AUDIO_TX_UP8:
			val = 8.0f;
			break;
		case AUDIO_TX_UP4:
			val = 4.0f;
			break;
		case AUDIO_TX_UP2:
			val = 2.0f;
			break;
		case AUDIO_TX_UP0:
			val = 1.0f;
			break;
	}
	float f = out_rate / in_rate / val * 8388608.0f;		
	if(f >= 8388608.0f)
		f = 8388607.0f;
	return (uint32_t) f;
}

static uint32_t hal_audio_calc_tx_vid_inv_rate(uint32_t vid_nom_rate) {
	double d = pow(2.0, 32.0) / (double)vid_nom_rate;
	uint32_t ans = (uint32_t) d;
	if(ans >= 8192)
		ans = 8191;
	return ans;
}

static uint32_t hal_audio_calc_tx_den(float in_rate) {
	float result = AUDIO_TX_CLK_RATE / in_rate;
	return ((uint32_t)(result*1000) == ((uint32_t)result*1000)) ? (uint32_t)result : AUDIO_TX_CLK_RATE;			// account for float precision
}

static uint32_t hal_audio_calc_tx_num(float in_rate) {
	float result = AUDIO_TX_CLK_RATE / in_rate;
	return ((uint32_t)(result*1000) == ((uint32_t)result*1000)) ? 1 : (uint32_t)in_rate;			// account for float precision
}
static void hal_audio_enc_pdm_dc_offset_cal_get_samples(int num_bytes_per_frame, int isStereo, uint8_t *bufL, uint8_t *bufR) {
	if(isStereo) {
		uint8_t buf[512];
		for(int i = 0; i < num_bytes_per_frame; i++)
			buf[i] = audio_rx_dma_read();		
		
		int x = 0;
		int indL = 0, indR = 0;
		for(int i = 0; i < 3; i++)
			bufL[indL++] = buf[x++];
		for(int i = 0; i < 3; i++)
			bufR[indR++] = buf[x++];
		for(int i = 0; i < num_bytes_per_frame - 6; i++) {
			if(i % 2 == 0)
				bufL[indL++] = buf[x++];
			else
				bufR[indR++] = buf[x++];			
		}
	}
	else {
		for(int i = 0; i < num_bytes_per_frame; i++)
			bufL[i] = audio_rx_dma_read();
	}
}

static float hal_audio_enc_pdm_dc_offset_cal_calc(int num_bytes_per_frame, uint8_t *buf) {	
	float sum = 0;
	int i = 0;
	char tmp_data;	

	long step; /* Quantizer step size */
	signed long predsample; /* Output of ADPCM predictor */
	signed long diffq; /* Dequantized predicted difference */
	int index; /* Index into step size table */

	int Samp;
	unsigned char inCode;
	static int indexTable[16] = { -1, -1, -1, -1, 2, 4, 6, 8, -1, -1, -1, -1, 2, 4,	6, 8, };

	static int stepsizeTable[89] = { 7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21,
	23, 25, 28, 31, 34, 37, 41, 45, 50, 55, 60, 66, 73, 80, 88, 97, 107,
	118, 130, 143, 157, 173, 190, 209, 230, 253, 279, 307, 337, 371, 408,
	449, 494, 544, 598, 658, 724, 796, 876, 963, 1060, 1166, 1282, 1411,
	1552, 1707, 1878, 2066, 2272, 2499, 2749, 3024, 3327, 3660, 4026, 4428,
	4871, 5358, 5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635,
	13899, 15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767 }; 

	predsample = buf[0] + buf[1] * 256;	
	index = buf[2];
	int numSamples = (num_bytes_per_frame - 3) * 2;

	if (predsample > 32767)
			predsample -= 65536;
	sum += predsample;

	for (i = 0; i < numSamples; i++) {
			tmp_data = buf[(i / 2) + 3];
			if (i % 2 == 1)
					inCode = (tmp_data & 0xf0) >> 4;
			else
					inCode = tmp_data & 0x0f;

			step = stepsizeTable[index];

			diffq = step >> 3;
			if (inCode & 4)
					diffq += step;
			if (inCode & 2)
					diffq += step >> 1;
			if (inCode & 1)
					diffq += step >> 2;

			if (inCode & 8)
					predsample -= diffq;
			else
					predsample += diffq;
			/* Check for overflow of the new predicted sample */
			if (predsample > 32767)
					predsample = 32767;
			else if (predsample < -32768)
					predsample = -32768;
			/* Find new quantizer stepsize index by adding the old index
			 to a table lookup using the ADPCM code */
			index += indexTable[inCode];
			/* Check for overflow of the new quantizer step size index */
			if (index < 0)
					index = 0;
			if (index > 88)
					index = 88;
			/* Return the new ADPCM code */
			Samp = predsample;
			sum += Samp;
	}
	sum /= (float)(numSamples + 1);

	return sum;
}

static float hal_audio_enc_pdm_dc_offset_cal_calc_mean(int num_bytes_per_frame, int isStereo) {
	uint8_t bufL[512], bufR[512];	
	hal_audio_enc_pdm_dc_offset_cal_get_samples(num_bytes_per_frame, isStereo, bufL, bufR);
	if(isStereo) {
		float left = hal_audio_enc_pdm_dc_offset_cal_calc(num_bytes_per_frame/2, bufL);
		float right = hal_audio_enc_pdm_dc_offset_cal_calc(num_bytes_per_frame/2, bufR);
		return (left + right) / 2;
	}
	else
		return hal_audio_enc_pdm_dc_offset_cal_calc(num_bytes_per_frame, bufL);
}

static void hal_audio_enc_pdm_dc_offset_feedback(uint32_t error) {	
	uint8_t shift = audio_rx_get_cic_shift();	
	uint32_t old_offset = audio_rx_get_dc_off();
	uint16_t gain = audio_rx_get_gain_left();
	uint32_t new_offset = old_offset + (2 * error * 64 / pow(2, shift) / gain);
	audio_rx_set_dc_off(new_offset);
}
	
// Audio HW GPIO Config
static int audio_enc_pin_mux_chk() {
	audio_gpio_dev_t* gpio = &audio_gpio_dev;
	audio_rx_dev_t* pd = &audio_rx_dev;
	if(!pd->enc_used)
		return AUDIO_ERR_NOT_INIT;	
	
	// Sanity check
	if(pd->in_format == ENC_INPUT_PDM) {
		if (((CFG_GPIO_4_0>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_PDM_0_CLK) 
			gpio->pdm_clk_pin = CFG_GPIO_4_0;
		else
			goto fail;

		if (((CFG_GPIO_2_7>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_PDM_1_DATA0) 
			gpio->pdm_dat1_pin = CFG_GPIO_2_7;
		else
			gpio->pdm_dat1_pin = 0;

		if (((CFG_GPIO_2_8>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_PDM_0_DATA0) 
			gpio->pdm_dat0_pin = CFG_GPIO_2_8;
		else
			gpio->pdm_dat0_pin = 0;

		if (!gpio->pdm_dat0_pin && !gpio->pdm_dat1_pin)
			goto fail;
	}
	else if(pd->in_format == ENC_INPUT_I2S) {
		if(pd->i2s_core == MASTER) {
			if (((CFG_GPIO_1_3>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_I2S_MSTR_CLK) 
				gpio->i2s_m_clk_pin = CFG_GPIO_1_3;
			else
				goto fail;
			
			if (((CFG_GPIO_1_4>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_MSTR_WS) 
				gpio->i2s_m_ws_pin = CFG_GPIO_1_4;
			else
				goto fail;

			if (((CFG_GPIO_1_5>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_MSTR_SD0) 
				gpio->i2s_m_sd0_pin = CFG_GPIO_1_5;
			else
				gpio->i2s_m_sd0_pin = 0;

			if (((CFG_GPIO_1_6>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_MSTR_SD1) 
				gpio->i2s_m_sd1_pin = CFG_GPIO_1_6;
			else
				gpio->i2s_m_sd1_pin = 0;

			if (!gpio->i2s_m_sd0_pin && !gpio->i2s_m_sd1_pin)
				goto fail;
		}
		else if(pd->i2s_core == SLAVE) {
			if (((CFG_GPIO_1_3>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_I2S_SLV_CLK0) 
				gpio->i2s_s_clk_pin = CFG_GPIO_1_3;
			else
				goto fail;
			
			if (((CFG_GPIO_1_4>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_SLV_WS) 
				gpio->i2s_s_ws_pin = CFG_GPIO_1_4;
			else
				goto fail;

			if (((CFG_GPIO_1_5>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_SLV_SD0) 
				gpio->i2s_s_sd0_pin = CFG_GPIO_1_5;
			else
				gpio->i2s_s_sd0_pin = 0;

			if (((CFG_GPIO_1_6>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_SLV_SD1) 
				gpio->i2s_s_sd1_pin = CFG_GPIO_1_6;
			else
				gpio->i2s_s_sd1_pin = 0;

			if (!gpio->i2s_s_sd0_pin && !gpio->i2s_s_sd1_pin)
				goto fail;
		}
		else return AUDIO_ERR_DEV_BAD_STATE;
	}
	else return AUDIO_ERR_DEV_BAD_STATE;
	
	return AUDIO_ERR_OK;
	
	fail:
		return AUDIO_ERR_BAD_HW_GPIO_CONFIG;
}

static int audio_enc_pin_mux_enable() {
	audio_gpio_dev_t* gpio = &audio_gpio_dev;
	audio_rx_dev_t* pd = &audio_rx_dev;
	if(!pd->enc_used)
		return AUDIO_ERR_NOT_INIT;	
	
	int result = audio_enc_pin_mux_chk();
	if(result != AUDIO_ERR_OK)
		return result;
	
	if(pd->in_format == ENC_INPUT_PDM) {
		hal_gpio_pin_cfg(gpio->pdm_clk_pin);
		if (gpio->pdm_dat0_pin)
			hal_gpio_pin_cfg(gpio->pdm_dat0_pin);
		if (gpio->pdm_dat1_pin)
			hal_gpio_pin_cfg(gpio->pdm_dat1_pin);
	}
	else if(pd->in_format == ENC_INPUT_I2S) {
		if(pd->i2s_core == MASTER) {
			hal_gpio_pin_cfg(gpio->i2s_m_clk_pin);
			hal_gpio_pin_cfg(gpio->i2s_m_ws_pin);
			if (gpio->i2s_m_sd0_pin)
				hal_gpio_pin_cfg(gpio->i2s_m_sd0_pin);
			if (gpio->i2s_m_sd1_pin)
				hal_gpio_pin_cfg(gpio->i2s_m_sd1_pin);
		}
		else if(pd->i2s_core == SLAVE) {
			hal_gpio_pin_cfg(gpio->i2s_s_clk_pin);
			hal_gpio_pin_cfg(gpio->i2s_s_ws_pin);
			if (gpio->i2s_s_sd0_pin)
				hal_gpio_pin_cfg(gpio->i2s_s_sd0_pin);
			if (gpio->i2s_s_sd1_pin)
				hal_gpio_pin_cfg(gpio->i2s_s_sd1_pin);
		}
		else return AUDIO_ERR_DEV_BAD_STATE;
	}
	else return AUDIO_ERR_DEV_BAD_STATE;
	
	hal_clk_audio_en(1);
	
	return AUDIO_ERR_OK;
}

static int audio_enc_pin_mux_disable() {
	audio_gpio_dev_t* gpio = &audio_gpio_dev;
	audio_rx_dev_t* pd = &audio_rx_dev;
	if(!pd->enc_used)
		return AUDIO_ERR_NOT_INIT;	
	
	int result = audio_enc_pin_mux_chk();
	if(result != AUDIO_ERR_OK)
		return result;
	
	if(pd->in_format == ENC_INPUT_PDM) {
		hal_gpio_pin_dft(gpio->pdm_clk_pin);
		if (gpio->pdm_dat0_pin)
			hal_gpio_pin_dft(gpio->pdm_dat0_pin);
		if (gpio->pdm_dat1_pin)
			hal_gpio_pin_dft(gpio->pdm_dat1_pin);
	}
	else if(pd->in_format == ENC_INPUT_I2S) {
		if(pd->i2s_core == MASTER) {
			hal_gpio_pin_dft(gpio->i2s_m_clk_pin);
			hal_gpio_pin_dft(gpio->i2s_m_ws_pin);
			if (gpio->i2s_m_sd0_pin)
				hal_gpio_pin_dft(gpio->i2s_m_sd0_pin);
			if (gpio->i2s_m_sd1_pin)
				hal_gpio_pin_dft(gpio->i2s_m_sd1_pin);
		}
		else if(pd->i2s_core == SLAVE) {
			hal_gpio_pin_dft(gpio->i2s_s_clk_pin);
			hal_gpio_pin_dft(gpio->i2s_s_ws_pin);
			if (gpio->i2s_s_sd0_pin)
				hal_gpio_pin_dft(gpio->i2s_s_sd0_pin);
			if (gpio->i2s_s_sd1_pin)
				hal_gpio_pin_dft(gpio->i2s_s_sd1_pin);
		}
		else return AUDIO_ERR_DEV_BAD_STATE;
	}
	else return AUDIO_ERR_DEV_BAD_STATE;
	
	if(audio_rx_dev.enc_used == 0 && audio_tx_dev.dec_used == 0 && audio_tx_dev.resample_used == 0)
		hal_clk_audio_en(0);
	
	return AUDIO_ERR_OK;
}

static int audio_dec_pin_mux_chk() {
	audio_gpio_dev_t* gpio = &audio_gpio_dev;
	audio_tx_dev_t* pd = &audio_tx_dev;
	if(!pd->dec_used)
		return AUDIO_ERR_NOT_INIT;	
	// Sanity check
	if(pd->out_path == TX_OUT_I2S) {
		if(pd->i2s_core == MASTER) {
			if (((CFG_GPIO_1_3>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_I2S_MSTR_CLK) 
				gpio->i2s_m_clk_pin = CFG_GPIO_1_3;
			else
				goto fail;
			
			if (((CFG_GPIO_1_4>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_MSTR_WS) 
				gpio->i2s_m_ws_pin = CFG_GPIO_1_4;
			else
				goto fail;

			if (((CFG_GPIO_1_5>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_MSTR_SD0) 
				gpio->i2s_m_sd0_pin = CFG_GPIO_1_5;
			else
				gpio->i2s_m_sd0_pin = 0;

			if (((CFG_GPIO_1_6>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_MSTR_SD1) 
				gpio->i2s_m_sd1_pin = CFG_GPIO_1_6;
			else
				gpio->i2s_m_sd1_pin = 0;

			if (!gpio->i2s_m_sd0_pin && !gpio->i2s_m_sd1_pin)
				goto fail;
		}
		else if(pd->i2s_core == SLAVE) {
			if (((CFG_GPIO_1_3>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_I2S_SLV_CLK0) 
				gpio->i2s_s_clk_pin = CFG_GPIO_1_3;
			else
				goto fail;
			
			if (((CFG_GPIO_1_4>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_SLV_WS) 
				gpio->i2s_s_ws_pin = CFG_GPIO_1_4;
			else
				goto fail;

			if (((CFG_GPIO_1_5>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_SLV_SD0) 
				gpio->i2s_s_sd0_pin = CFG_GPIO_1_5;
			else
				gpio->i2s_s_sd0_pin = 0;

			if (((CFG_GPIO_1_6>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_SLV_SD1) 
				gpio->i2s_s_sd1_pin = CFG_GPIO_1_6;
			else
				gpio->i2s_s_sd1_pin = 0;

			if (!gpio->i2s_s_sd0_pin && !gpio->i2s_s_sd1_pin)
				goto fail;
		}
		else return AUDIO_ERR_DEV_BAD_STATE;
	}
	else if(pd->out_path == TX_OUT_SIG_DELT) {
		if (((CFG_GPIO_2_1>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_AUDIO_SD_L) 
			gpio->audio_sd_left = CFG_GPIO_2_1;
		else
			goto fail;
		
		if (((CFG_GPIO_2_3>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_AUDIO_SD_R) 
			gpio->audio_sd_right = CFG_GPIO_2_3;
		else
			goto fail;
	}
	else return AUDIO_ERR_DEV_BAD_STATE;
	
	return AUDIO_ERR_OK;
	
	fail:
		return AUDIO_ERR_BAD_HW_GPIO_CONFIG;
}

static int audio_dec_pin_mux_enable() {
	audio_gpio_dev_t* gpio = &audio_gpio_dev;
	audio_tx_dev_t* pd = &audio_tx_dev;
	if(!pd->dec_used)
		return AUDIO_ERR_NOT_INIT;	
	
	int result = audio_dec_pin_mux_chk();
	if(result != AUDIO_ERR_OK)
		return result;
	
	if(pd->out_path == TX_OUT_I2S) {
		if(pd->i2s_core == MASTER) {
			hal_gpio_pin_cfg(gpio->i2s_m_clk_pin);
			hal_gpio_pin_cfg(gpio->i2s_m_ws_pin);
			if (gpio->i2s_m_sd0_pin)
				hal_gpio_pin_cfg(gpio->i2s_m_sd0_pin);
			if (gpio->i2s_m_sd1_pin)
				hal_gpio_pin_cfg(gpio->i2s_m_sd1_pin);
		}
		else if(pd->i2s_core == SLAVE) {
			hal_gpio_pin_cfg(gpio->i2s_s_clk_pin);
			hal_gpio_pin_cfg(gpio->i2s_s_ws_pin);
			if (gpio->i2s_s_sd0_pin)
				hal_gpio_pin_cfg(gpio->i2s_s_sd0_pin);
			if (gpio->i2s_s_sd1_pin)
				hal_gpio_pin_cfg(gpio->i2s_s_sd1_pin);
		}
		else return AUDIO_ERR_DEV_BAD_STATE;
	}
	else if(pd->out_path == TX_OUT_SIG_DELT) {
		hal_gpio_pin_cfg(gpio->audio_sd_left);
		hal_gpio_pin_cfg(gpio->audio_sd_right);
	}
	else return AUDIO_ERR_DEV_BAD_STATE;
	
	hal_clk_audio_en(1);
	
	return AUDIO_ERR_OK;
}

static int audio_dec_pin_mux_disable() {
	audio_gpio_dev_t* gpio = &audio_gpio_dev;
	audio_tx_dev_t* pd = &audio_tx_dev;
	if(!pd->dec_used)
		return AUDIO_ERR_NOT_INIT;	
	
	int result = audio_dec_pin_mux_chk();
	if(result != AUDIO_ERR_OK)
		return result;
	
	if(pd->out_path == TX_OUT_I2S) {
		if(pd->i2s_core == MASTER) {
			hal_gpio_pin_dft(gpio->i2s_m_clk_pin);
			hal_gpio_pin_dft(gpio->i2s_m_ws_pin);
			if (gpio->i2s_m_sd0_pin)
				hal_gpio_pin_dft(gpio->i2s_m_sd0_pin);
			if (gpio->i2s_m_sd1_pin)
				hal_gpio_pin_dft(gpio->i2s_m_sd1_pin);
		}
		else if(pd->i2s_core == SLAVE) {
			hal_gpio_pin_dft(gpio->i2s_s_clk_pin);
			hal_gpio_pin_dft(gpio->i2s_s_ws_pin);
			if (gpio->i2s_s_sd0_pin)
				hal_gpio_pin_dft(gpio->i2s_s_sd0_pin);
			if (gpio->i2s_s_sd1_pin)
				hal_gpio_pin_dft(gpio->i2s_s_sd1_pin);
		}
		else return AUDIO_ERR_DEV_BAD_STATE;
	}
	else if(pd->out_path == TX_OUT_SIG_DELT) {
		hal_gpio_pin_dft(gpio->audio_sd_left);
		hal_gpio_pin_dft(gpio->audio_sd_right);
	}
	else return AUDIO_ERR_DEV_BAD_STATE;	
	
	if(audio_rx_dev.enc_used == 0 && audio_tx_dev.dec_used == 0 && audio_tx_dev.resample_used == 0)
		hal_clk_audio_en(0);
	
	return AUDIO_ERR_OK;
}
#if 0
static void hal_audio_clear_enc_buf(void)
{
    uint32_t bytes = audio_get_aenc_bytes_in_ram();

    for (uint32_t i = 0; i < bytes; i++) {
        audio_rx_dma_read();
    }
    
}
#endif
// Audio HW Configuration 
static void hal_audio_encoder_restart() {
	audio_aenc_sreset();
	audio_aenc_restart();	
    //hal_audio_clear_enc_buf();
}

static void hal_audio_decoder_restart() {
	audio_dec_restart();
	audio_autx_reset();
	audio_autx_reset_spk();
}

static int hal_audio_rx_apply_config() {	
	audio_rx_dev_t* pd = &audio_rx_dev;
	if(!pd->enc_used)
		return AUDIO_ERR_NOT_INIT;

	/* adec_dma_ctrl0: set read register to automatically update pointer */
	audio_rx_enable_rd_dma_ack();

	/* misc_ctrl0: mono vs stereo */
	if(pd->audio_mode == MONO) {
		audio_aenc_stereo_disable();
		audio_rx_stereo_disable();
	}
	else {
		audio_aenc_stereo_enable();
		audio_rx_stereo_enable();
	}
	int is_pdm = (pd->in_format == ENC_INPUT_PDM) ? 1: 0;
	audio_rx_set_filterpath(is_pdm, pd->in_rate, pd->out_rate);
	/* aenc_ctrl0: set num samples per block */
	audio_rx_init_aenc_num_samp_per_blk(pd->num_bytes_per_frame, pd->audio_mode);

	if(pd->predict_little_end )
		audio_rx_set_aenc_predic_end();
	else
		audio_rx_clr_aenc_predic_end();


	/* aurx_ctrl1: config encoder parameters (gain/decimation) */
	audio_rx_set_itp_per(100);
	audio_rx_set_i2s_delay(3);
	audio_rx_set_gain_left(pd->gain_left);
	audio_rx_set_gain_right(pd->gain_right);
	
	/* aurx_ctrl0: config input mic format */
	if(pd->in_format == ENC_INPUT_PDM) {
		audio_rx_in_format_pdm();
		audio_rx_pdm_init_clk0(pd->pdm_clk_period, pd->wss_l_low);
		audio_rx_pdm_init_clk1(pd->pdm_clk_period, pd->pdm_l_core, pd->pdm_r_core);		
	
		/* aurx_ctrl0: config RX PDM filtering */
		if(!pd->isCalibrated)													// Only apply default DC Offset values if user has not calibrated
			audio_rx_pdm_cic_init(pd->pdm_cic_dec, RX_PDM_CIC_DEC_OFFSET[pd->pdm_cic_dec], RX_PDM_CIC_DEC_SHIFT[pd->pdm_cic_dec]);
	}
	else {
		audio_rx_in_format_i2s();		
		if(pd->i2s_core == MASTER)
			audio_rx_i2s_master_core();
		else
			audio_rx_i2s_slave_core();
	}
		
	/* aurx_ctrl1: config RX filtering */
	if(pd->lpf2_filter_execute == 1)
		audio_rx_lpf2_dec_execute();
	else
		audio_rx_lpf2_dec_bypass();
		
	/* aurx_ctrl0: config RX filtering */
	if(pd->d5_filter_execute == 1)
		audio_rx_i2s_byp_ib4_db5_disable();
	else
		audio_rx_i2s_byp_ib4_db5_enable();
	
	/* aurx_ctrl0: config RX filtering */
	if(pd->filterpath_execute == 1)
		audio_rx_i2s_byp_all_disable();
	else
		audio_rx_i2s_byp_all_enable();
	
	audio_rx_set_aenc_max_addr();
	
	return AUDIO_ERR_OK;
}

static int hal_audio_tx_apply_config() {
	audio_tx_dev_t *pd = &audio_tx_dev;
	if(!(pd->dec_used || pd->resample_used))
		return AUDIO_ERR_NOT_INIT;
	
	/* global reg: clk_ctrl_1: Set Clock mux for Audio Speaker/SD clock */
	uint32_t reg = RD_WORD(GLOBAL_REG_CLK_CTRL_1);
	reg &= ~(0x3 << 23);
	reg |= (pd->out_clk_src << 23);
	WR_WORD(GLOBAL_REG_CLK_CTRL_1, reg);
	
	/* Generate clock source if PDM clock */
	if(pd->out_clk_src == 2) {
		uint32_t val = (64000000.0f / pd->in_rate) - 1;
		audio_rx_pdm_init_clk0(val, 0);
	}
	
	/* autx_ctrl3: set FIFO output sample rate */
	uint32_t val = hal_audio_calc_ctlt_autx_out_per(pd->out_clk_rate, pd->out_rate);
	audio_tx_set_out_per(val);
	audio_tx_set_gainl(pd->gain_left);

	/* adec_rate_ctrl0: config decoder denominator/numerator */
	audio_tx_set_adec_pcm_freq_num(hal_audio_calc_tx_num(pd->in_rate));
	audio_tx_set_adec_pcm_freq_den(hal_audio_calc_tx_den(pd->in_rate));
	
	uint32_t VNR = hal_audio_calc_tx_vid_nom_rate(pd->in_rate, pd->out_rate);
	uint32_t VIR = hal_audio_calc_tx_vid_inv_rate(VNR);

	/* autx_ctrl1: audio tx vid nominal rate */
	audio_tx_set_vid_nomrate(VNR);

	/* autx_ctrl2: audio tx vid inverse rate */
	audio_tx_set_vid_invrate(VIR);
	audio_tx_set_gainr(pd->gain_right);
	
	/* autx_ctrl0: tx datapath filters */
	val = hal_audio_calc_tx_interp32_period(pd->in_rate);
	audio_tx_set_itpto32_per(val);
	audio_tx_set_itpto64_per(val/2);
	audio_tx_set_itpto128_per(val/4);
	audio_tx_bypass_itpto32_lpf_disable();
	audio_tx_bypass_itpto32_up2_disable();
	audio_tx_bypass_itpto64_lpf_disable();
	audio_tx_bypass_itpto128_lpf_disable();

	/* autx_ctrl0: tx datapath filters */
	switch(pd->up2_filters) {
		case AUDIO_TX_UP8:
			break;
		case AUDIO_TX_UP4:
			audio_tx_bypass_itpto128_lpf_enable();
			break;
		case AUDIO_TX_UP2:
			audio_tx_bypass_itpto128_lpf_enable();
			audio_tx_bypass_itpto64_lpf_enable();
			break;
		case AUDIO_TX_UP0:
			audio_tx_bypass_itpto128_lpf_enable();
			audio_tx_bypass_itpto64_lpf_enable();
			audio_tx_bypass_itpto32_lpf_enable();
			audio_tx_bypass_itpto32_up2_enable();
			break;
	}

	/* misc_ctrl0: mono vs stereo */
	if(pd->audio_mode == MONO) {
		audio_adec_stereo_disable();
		audio_tx_stereo_disable();
	}
	else {
		audio_adec_stereo_enable();
		audio_tx_stereo_enable();
	}
	
	/* adec_dma_ctrl0: set write register to automatically update pointer */
	audio_tx_enable_wr_dma_ack();
	
	/* adec_ctrl0: set num samples per block */
	audio_tx_init_adec_num_samp_per_blk(pd->num_bytes_per_frame, pd->audio_mode);
	
	/* autx_sm_ctrl0: set audio tx path control to adpcm */
	audio_rdsm_dma_sel_adpcm();
	
	/* autx_wrsm_ctrl0: set audio tx path control to adpcm */
	audio_wrsm_dma_sel_adpcm();
	if(pd->dec_used) {
		/* misc_ctrl0: enable: asynchronous TX FIFO, I2S slave core */
		if(pd->out_path == TX_OUT_I2S) {
			if(pd->i2s_core == MASTER){
				audio_tx_i2s_master_enable();
				audio_tx_i2s_slave_disable();
			}
			else{
				audio_tx_i2s_master_disable();
				audio_tx_i2s_slave_enable();
			}
		}
		else
			audio_autx_sdm_enable();
		audio_afifo_en_wr_enable();	
		audio_afifo_en_rd_enable();
		
		audio_tx_set_adec_max_addr();
	}

	else if(pd->resample_used) {
		// RX 		
		/* adec_dma_ctrl0: set read register to automatically update pointer */
		audio_rx_enable_rd_dma_ack();
		
		/* misc_ctrl0: mono vs stereo */
		if(pd->audio_mode == MONO) {
			audio_aenc_stereo_disable();
			audio_rx_stereo_disable();
		}
		else {
			audio_aenc_stereo_enable();
			audio_rx_stereo_enable();
		}
		
		// RESAMPLE 
		
		/* autx_wrsm_ctrl1: config resample denominator/numerator */
		audio_wrsm_set_pull_den(hal_audio_calc_tx_den(pd->in_rate));
		audio_wrsm_set_pull_num(hal_audio_calc_tx_num(pd->in_rate));
		
		/* autx_ctrl0: Select input into Audio Tx datapath */
		audio_tx_set_audio_tx_in_dma_sharedmem();
		
		/* autx_wrsm_ctrl0: Audio Tx Write Shared Memory Interface Controls */
		audio_wrsm_dma_sel_audiotx();
		audio_wrsm_autx_enable();
		audio_wrsm_set_max_addr();						// DY: set max buffer size to 64 by YGRYGR request
		
		/* autx_sm_ctrl0: Audio Tx Read Shared Memory Interface Controls */
		audio_rdsm_dma_sel_audiotx();
		audio_rdsm_autx_enable();
		audio_rdsm_set_max_addr();						// DY: set max buffer size to 64 by YGRYGR request
	}
	
	return AUDIO_ERR_OK;
}

static int audio_rx_set_filterpath(int is_pdm, float in_rate, float out_rate) {	
	audio_rx_dev_t* pd = &audio_rx_dev;
	int config = 0;
	float cur, best;
	if(!pd->enc_used)
		return AUDIO_ERR_NOT_INIT;
	
	if(is_pdm) {
		if(((in_rate / 10.0f) < (out_rate - 500.0f)) || ((in_rate / 200.0f) > (out_rate + 500.0f)))
			return AUDIO_ERR_INVALID_PARA;
		best = in_rate;
		for(int i = 0; i < 9; i++) {
			cur = fabs((in_rate / RX_PDM_DOWNSAMPLES[i]) - out_rate);
			if(cur >= best)
				break;
			else {
				best = cur;
				config = RX_PDM_DOWNSAMPLE_CONFIG[i];
			}
		}
		pd->pdm_cic_dec = (audio_rx_pdm_cic_dec_ctrl_t)(config/10);
		pd->lpf2_filter_execute = (config % 10) ? 1 : 0;
		pd->d5_filter_execute = 1;
		pd->filterpath_execute = 1;
	}
	else {
		if((in_rate < (out_rate - 500.0f)) || ((in_rate * 4.0f / 10.0f) > (out_rate + 500.0f)))
			return AUDIO_ERR_INVALID_PARA;
		best = in_rate;
		for(int i = 0; i < 4; i++) {
			cur = fabs((in_rate * RX_I2S_DOWNSAMPLES[i]) - out_rate);
			if(cur >= best)
				break;
			else {
				best = cur;
				config = RX_I2S_DOWNSAMPLE_CONFIG[i];
			}
		}
		pd->d5_filter_execute = (config / 100) ? 1 : 0;
		pd->lpf2_filter_execute = ((config / 10) % 10) ? 1 : 0;
		pd->filterpath_execute = (config % 10) ? 1 : 0;
	}
	
	return AUDIO_ERR_OK;
}

// Audio Power state config
#if CFG_PM_EN
static int audio_enc_power_state(void *arg, uint32_t *sleep_duration) {
	audio_rx_dev_t *pd = &audio_rx_dev;
	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->power_state;
}

static void audio_enc_power_down(void *arg, uint32_t sleep_duration) {
    //PRINTD(DBG_TRACE, "%s \n", __func__);
	return;
}

static void audio_enc_power_up(void *arg) {
	/// TODO: pin mux, etc...
   // PRINTD(DBG_TRACE, "%s \n", __func__);
    //audio_enc_pin_mux_enable();
    hal_audio_rx_apply_config();
}

static int audio_dec_power_state(void *arg, uint32_t *sleep_duration) {
	audio_tx_dev_t *pd = &audio_tx_dev;
	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->power_state;
}

static void audio_dec_power_down(void *arg, uint32_t sleep_duration) {
	return;
}

static void audio_dec_power_up(void *arg) {
	/// TODO: pin mux, etc...
}

static int audio_resample_power_state(void *arg,uint32_t *sleep_duration) {
	audio_tx_dev_t* pd = &audio_tx_dev;
	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->power_state;
}

static void audio_resample_power_down(void *arg,uint32_t sleep_duration) {
	return;
}

static void audio_resample_power_up(void *arg) {
	/// TODO: pin mux, etc...
}
#endif	/* CFG_PM_EN */
// Audio interrupt setup 
__irq void Audio_Handler(void) {
	uint32_t status = audio_intr_status();
	audio_intr_clear(0x3FFFFF);
	audio_rx_dev.status = AUDIO_ERR_AUDIO_HW_INTR;
	audio_tx_dev.status = AUDIO_ERR_AUDIO_HW_INTR;
	PRINTD(DBG_TRACE, "irq 0x%x\n", status);

}

// User audio setup 
int hal_audio_enc_open() {
	audio_rx_dev_t* pd = &audio_rx_dev;

	if(audio_rx_dev.enc_used != 0 || audio_tx_dev.resample_used != 0)
		return AUDIO_ERR_OP_BLOCKED;
		
	// User status control
	pd->enc_used = 1;	
	pd->status = AUDIO_ERR_OK;
	pd->isCalibrated = 0;
	
	//RX Path control
	pd->in_format = ENC_INPUT_PDM;
	pd->i2s_core = MASTER;
	pd->lpf2_filter_execute = 1;
	pd->d5_filter_execute = 1;
	pd->filterpath_execute = 1;
	
	//RX Path control - PDM
	pd->pdm_cic_dec = CIC_DEC_10;
	pd->pdm_l_core = 0;
	pd->pdm_r_core = 0;
	pd->wss_l_low = 1;
	pd->pdm_clk_period = 39;

	// Basic audio control
	pd->in_rate = 1600000;	
	pd->out_rate = 16000;	
	pd->gain_left = 32;
	pd->gain_right = 32;
	pd->audio_mode = MONO;
	pd->num_bytes_per_frame = 64;
	pd->predict_little_end = 1;
    
	pd->mutex = osMutexCreate(osMutex(rx_mutex));
	if (!pd->mutex)
		goto fail;
	pd->semaphore = osSemaphoreCreate(osSemaphore(rx_semaphore), 0);
	if (!pd->semaphore)
		goto fail;	
    
#if CFG_PM_EN
	pd->pm.power_state = audio_enc_power_state;
	pd->pm.power_down = audio_enc_power_down;
	pd->pm.power_up = audio_enc_power_up;
	pd->pm.arg = (void *)pd; 
	hal_pm_reg_mod(&pd->pm);
	pd->power_state = PM_DEEP_SLEEP;
#endif
	
  hal_clk_audio_en(1);

	return AUDIO_ERR_OK;

fail:
	if (pd->mutex) {
		osMutexDelete(pd->mutex);
		pd->mutex = NULL;
	}
	if (pd->semaphore) {
		osSemaphoreDelete(pd->semaphore);	
		pd->semaphore = NULL;
	}

	return AUDIO_ERR_DEV_BAD_STATE;
}

int hal_audio_dec_open() {
	audio_tx_dev_t* pd = &audio_tx_dev;

	if(audio_tx_dev.resample_used != 0 || audio_tx_dev.dec_used != 0)
		return AUDIO_ERR_OP_BLOCKED;
	
	// User status control
	pd->dec_used = 1;
	pd->resample_used = 0;
	pd->status = AUDIO_ERR_OK;
	
	// TX path control
	pd->out_path = TX_OUT_I2S;
	pd->i2s_core = MASTER;
	pd->up2_filters = AUDIO_TX_UP8;
	pd->out_clk_rate = 2000000;	
	pd->out_clk_src = 0;

	// Basic audio control
	pd->in_rate = 16000;	
	pd->out_rate = 16000;	
	pd->gain_left = 32;
	pd->gain_right = 32;
	pd->audio_mode = MONO;	
	pd->num_bytes_per_frame = 64;
	pd->predict_little_end = 1;

	pd->mutex = osMutexCreate(osMutex(tx_mutex));
	if (!pd->mutex)
		goto fail;
	pd->semaphore = osSemaphoreCreate(osSemaphore(tx_semaphore), 0);
	if (!pd->semaphore)
		goto fail;

    
#if CFG_PM_EN
	pd->pm.power_state = audio_dec_power_state;
	pd->pm.power_down = audio_dec_power_down;
	pd->pm.power_up = audio_dec_power_up;
	pd->pm.arg = (void *)pd; 
	hal_pm_reg_mod(&pd->pm);
	pd->power_state = PM_DEEP_SLEEP;
#endif
	
	hal_clk_audio_en(1);
	
	return AUDIO_ERR_OK;

fail:
	if (pd->mutex) {
		osMutexDelete(pd->mutex);
		pd->mutex = NULL;
	}
	if (pd->semaphore) {
		osSemaphoreDelete(pd->semaphore);	
		pd->semaphore = NULL;
	}

	return AUDIO_ERR_DEV_BAD_STATE;
}

int hal_audio_resample_open() {
	audio_tx_dev_t* pd = &audio_tx_dev;

	if(audio_rx_dev.enc_used != 0 || pd->resample_used != 0 || pd->dec_used != 0)
		return AUDIO_ERR_OP_BLOCKED;
	
	// User status control
	pd->dec_used = 0;
	pd->resample_used = 1;
	pd->status = AUDIO_ERR_OK;
	
	// TX path control
	pd->up2_filters = AUDIO_TX_UP8;

	// Basic audio control
	pd->in_rate = 44100;	
	pd->out_rate = 48000;	
	pd->i2s_core = SLAVE;
	pd->gain_left = 32;
	pd->gain_right = 32;
	pd->audio_mode = MONO;	
	pd->num_bytes_per_frame = 64;
	pd->predict_little_end = 1;

	pd->mutex = osMutexCreate(osMutex(tx_mutex));
	if (!pd->mutex)
		goto fail;
	pd->semaphore = osSemaphoreCreate(osSemaphore(tx_semaphore), 0);
	if (!pd->semaphore)
		goto fail;

    
#if CFG_PM_EN
	pd->pm.power_state = audio_resample_power_state;
	pd->pm.power_down = audio_resample_power_down;
	pd->pm.power_up = audio_resample_power_up;
	pd->pm.arg = (void *)pd; 
	hal_pm_reg_mod(&pd->pm);
	pd->power_state = PM_DEEP_SLEEP;
#endif
	
	hal_clk_audio_en(1);
	
	return AUDIO_ERR_OK;

fail:
	if (pd->mutex) {
		osMutexDelete(pd->mutex);
		pd->mutex = NULL;
	}
	if (pd->semaphore) {
		osSemaphoreDelete(pd->semaphore);	
		pd->semaphore = NULL;
	}

	return AUDIO_ERR_DEV_BAD_STATE;
}

int hal_audio_enc_close() {
	audio_rx_dev_t *pd = &audio_rx_dev;
	
	if(pd == NULL)
		return AUDIO_ERR_DEV_BAD_STATE;
	if(!pd->enc_used)
		return AUDIO_ERR_NOT_INIT;

	osMutexWait(pd->mutex, osWaitForever);	
	osMutexRelease(pd->mutex);
		
	/// Free semaphore and mutex
	osMutexDelete(pd->mutex);
	osSemaphoreDelete(pd->semaphore);	

	pd->enc_used = 0;
	pd->status = AUDIO_ERR_OK;

#if CFG_PM_EN
	hal_pm_unreg_mod(&pd->pm);
#endif
	
	audio_enc_pin_mux_disable();
	if(audio_rx_dev.enc_used == 0 && audio_tx_dev.dec_used == 0 && audio_tx_dev.resample_used == 0)
		hal_clk_audio_en(0);


	return AUDIO_ERR_OK;
}

int hal_audio_dec_close() {
	audio_tx_dev_t *pd = &audio_tx_dev;
	if(pd == NULL)
		return AUDIO_ERR_DEV_BAD_STATE;
	if(!pd->dec_used)
		return AUDIO_ERR_NOT_INIT;

	osMutexWait(pd->mutex, osWaitForever);	
	osMutexRelease(pd->mutex);
		
	/// Free semaphore and mutex
	osMutexDelete(pd->mutex);
	osSemaphoreDelete(pd->semaphore);	

	pd->dec_used = 0;
	pd->status = AUDIO_ERR_OK;

#if CFG_PM_EN
	hal_pm_unreg_mod(&pd->pm);
#endif
	
	audio_dec_pin_mux_disable();
	if(audio_rx_dev.enc_used == 0 && audio_tx_dev.dec_used == 0 && audio_tx_dev.resample_used == 0)
		hal_clk_audio_en(0);

	return AUDIO_ERR_OK;
}

int hal_audio_resample_close() {
	audio_tx_dev_t* pd = &audio_tx_dev;
	if(pd == NULL)
		return 0;
	if(!pd->resample_used)
		return AUDIO_ERR_NOT_INIT;

	osMutexWait(pd->mutex, osWaitForever);	
	//osMutexWait(pd->mutex, osWaitForever);	

	osMutexRelease(pd->mutex);
	//osMutexRelease(pd->mutex);
		
	/// Free semaphore and mutex
	osMutexDelete(pd->mutex);
	osSemaphoreDelete(pd->semaphore);	

	pd->resample_used = 0;
	pd->status = AUDIO_ERR_OK;

#if CFG_PM_EN
	hal_pm_unreg_mod(&pd->pm);
#endif
	
	audio_dec_pin_mux_disable();
	if(audio_rx_dev.enc_used == 0 && audio_tx_dev.dec_used == 0 && audio_tx_dev.resample_used == 0)
		hal_clk_audio_en(0);

	return AUDIO_ERR_OK;
}

// User audio settings configuration
int hal_audio_enc_set_pdm_mic_inp(int pdm_l_core, int pdm_r_core, int wss_l_low) {
	audio_rx_dev_t* pd = &audio_rx_dev;
	if(!pd->enc_used)
		return AUDIO_ERR_NOT_INIT;	
	if(pd->pdm_l_core > 1 || pd->pdm_r_core > 1 || pd->wss_l_low > 1)
		return AUDIO_ERR_INVALID_PARA;	
	
	pd->pdm_l_core = pdm_l_core;
	pd->pdm_r_core = pdm_r_core;
	pd->wss_l_low = wss_l_low;
	
	return AUDIO_ERR_OK;
}

int hal_audio_enc_set_predict_endianness(int is_little_end) {
	audio_rx_dev_t* pd = &audio_rx_dev;
	if(!pd->enc_used)
		return AUDIO_ERR_NOT_INIT;

	osMutexWait(pd->mutex, osWaitForever);
	
	pd->predict_little_end = is_little_end;
	if(is_little_end)
		audio_rx_set_aenc_predic_end();
	else
		audio_rx_clr_aenc_predic_end();
	
	osMutexRelease(pd->mutex);	
	
	return AUDIO_ERR_OK;
}

int hal_audio_dec_set_predict_endianness(int is_little_end) {
	audio_tx_dev_t* pd = &audio_tx_dev;
	if(!pd->dec_used)
		return AUDIO_ERR_NOT_INIT;

	osMutexWait(pd->mutex, osWaitForever);
	
	pd->predict_little_end = is_little_end;
	if(is_little_end) {
		audio_tx_set_adec_predic_end();
		audio_tx_set_adec_lsb4first();
	}
	else {
		audio_tx_clr_adec_predic_end();
		audio_tx_clr_adec_lsb4first();
	}
	
	osMutexRelease(pd->mutex);	
	
	return AUDIO_ERR_OK;	
}


int hal_audio_enc_set_config(int is_pdm, int is_I2S_master, float in_rate, float out_rate, int is_stereo, int bytes_per_frame, int gain) {
	audio_rx_dev_t* pd = &audio_rx_dev;
    int ret = AUDIO_ERR_OK;
	if(!pd->enc_used)
		return AUDIO_ERR_NOT_INIT;
	if(bytes_per_frame > 512)
		return AUDIO_ERR_INVALID_PARA;	

	osMutexWait(pd->mutex, osWaitForever);
	#if CFG_PM_EN
	pd->power_state = PM_SLEEP;//todo: need check this
    #endif
	//RX Path control
	pd->in_format = (is_pdm) ? ENC_INPUT_PDM : ENC_INPUT_I2S;
	pd->i2s_core = (is_I2S_master) ? MASTER : SLAVE;
	if(is_pdm)		
		pd->pdm_clk_period = (64000000.0f / in_rate) - 1;
	
	// Basic audio control
	pd->in_rate = in_rate;	
	pd->out_rate = out_rate;	
	pd->gain_left = gain;
	pd->gain_right = gain;
	pd->audio_mode = (is_stereo) ? STEREO : MONO;
	pd->num_bytes_per_frame = bytes_per_frame;	
		
	// Final return status depends on HW GPIO setup
	if(GPIO_ENABLED == 1) {
		ret = audio_enc_pin_mux_enable();
		if(ret != AUDIO_ERR_OK)
			goto fail;
	}
	
	// Apply config to HW
	hal_audio_rx_apply_config();
	#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
    #endif	
	osMutexRelease(pd->mutex);	
	
	return AUDIO_ERR_OK;
fail:
	#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
    #endif
	osMutexRelease(pd->mutex);	
	
	return ret;    
}

int hal_audio_dec_set_config(int is_i2s, int is_I2S_master, float in_rate, float out_rate, uint8_t out_clk_src, float out_clk_rate, int is_stereo, int bytes_per_frame, int gain) {
	audio_tx_dev_t* pd = &audio_tx_dev;
	if(!pd->dec_used)
		return AUDIO_ERR_NOT_INIT;
	if(bytes_per_frame > 512)
		return AUDIO_ERR_INVALID_PARA;	

	osMutexWait(pd->mutex, osWaitForever);

	// TX path control
	if(is_i2s) {
		pd->out_path = TX_OUT_I2S;
		pd->i2s_core = (is_I2S_master) ? MASTER : SLAVE;
	}
	else
		pd->out_path = TX_OUT_SIG_DELT;
	pd->out_clk_src = out_clk_src;
	pd->out_clk_rate = out_clk_rate;
	pd->up2_filters = (in_rate > 32000 && is_stereo == STEREO) ? AUDIO_TX_UP4 : AUDIO_TX_UP8;
	
	// Basic audio control
	pd->in_rate = in_rate;	
	pd->out_rate = out_rate;	
	pd->gain_left = gain;
	pd->gain_right = gain;
	pd->audio_mode = (is_stereo) ? STEREO : MONO;
	pd->num_bytes_per_frame = bytes_per_frame;	
	
	// Final return status depends on HW GPIO setup
	if(GPIO_ENABLED == 1) {
		int gpio_status = audio_dec_pin_mux_enable();
		if(gpio_status != AUDIO_ERR_OK)
			return gpio_status;	
	}
	
	// Apply config to HW
	hal_audio_tx_apply_config();
	
	osMutexRelease(pd->mutex);	
	
	return AUDIO_ERR_OK;	
}

int hal_audio_resample_set_config(float in_rate, float out_rate, int is_stereo, int gain) {
	audio_tx_dev_t* pd = &audio_tx_dev;
	if(!pd->resample_used)
		return AUDIO_ERR_NOT_INIT;

	osMutexWait(pd->mutex, osWaitForever);
	
	// TX path control
	if(is_stereo) {
		pd->audio_mode = STEREO;
		pd->up2_filters = AUDIO_TX_UP4;			
	}
	else {
		pd->audio_mode = MONO;
		pd->up2_filters = AUDIO_TX_UP8;
	}

	// Basic audio control
	pd->in_rate = in_rate;	
	pd->out_rate = out_rate;	
	pd->gain_left = gain;
	pd->gain_right = gain;
	pd->audio_mode = (is_stereo) ? STEREO : MONO;
	
	// Apply config to HW
	hal_audio_tx_apply_config();
	
	osMutexRelease(pd->mutex);	
	
	return AUDIO_ERR_OK;
}

int hal_audio_enc_pdm_dc_offset_cal(int bytes_per_frame, int is_stereo, int num_frames_skip, int num_frames_samp) {
	audio_rx_dev_t* pd = &audio_rx_dev;
	if(!pd->enc_used)
		return AUDIO_ERR_NOT_INIT;

	osMutexWait(pd->mutex, osWaitForever);	
	
	pd->isCalibrated = 1;
	
	float error = 0;
	int loops = 0;
	int sum = 0;
	int done = 0;
	
	hal_audio_encode_start();	
	while(!done) {
		while(audio_get_aenc_bytes_in_ram() < bytes_per_frame);
		uint32_t num_bytes_encoded = audio_get_aenc_bytes_in_ram();
		error = hal_audio_enc_pdm_dc_offset_cal_calc_mean(bytes_per_frame, is_stereo);
		
		if(loops >= num_frames_skip) {
			sum += error;
			if(loops >= num_frames_skip + num_frames_samp) {
				sum /= num_frames_samp;
				hal_audio_enc_pdm_dc_offset_feedback(sum);
				done = 1;
			}
		}
		loops++;
	}
	
	hal_audio_encode_stop();	
	
	osMutexRelease(pd->mutex);	
	
	return AUDIO_ERR_OK;
}

// START 
int hal_audio_encode_start() {
	audio_rx_dev_t* pd = &audio_rx_dev;
	if(!pd->enc_used)
		return AUDIO_ERR_NOT_INIT;
	
	pd->status = AUDIO_ERR_OK;
	osMutexWait(pd->mutex, osWaitForever);
#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif

	NVIC_SetPriority(Audio_IRQn, IRQ_PRI_Normal);	
    NVIC_EnableIRQ(Audio_IRQn);
	audio_intr_mask_clear(0x3FFFFF);
	
    //audio_rx_enable_clk();
    if (pd->in_format == ENC_INPUT_PDM) {
        audio_rx_pdm_enable();
        //osDelay(500);	
    }
    audio_rx_enable_rd_dma_ack();

    hal_audio_encoder_restart();//Must call restart after audio_rx_pdm_enable and audio_rx_enable_rd_dma_ack

	audio_aenc_enable();


	osMutexRelease(pd->mutex);
	return pd->status;
}

int hal_audio_encode_process(uint8_t* out_buf, uint32_t buf_sz, uint16_t* in_size) {
	audio_rx_dev_t* pd = &audio_rx_dev;
	if(!pd->enc_used)
		return AUDIO_ERR_NOT_INIT;
	osMutexWait(pd->mutex, osWaitForever);
	uint16_t aenc_ram_num_bytes = audio_get_aenc_bytes_in_ram();
	if (aenc_ram_num_bytes > buf_sz)
		aenc_ram_num_bytes = buf_sz;
	for(uint16_t i = 0; i < aenc_ram_num_bytes; i++)
		out_buf[i] = audio_rx_dma_read();
	
	*in_size = aenc_ram_num_bytes;
	osMutexRelease(pd->mutex);
	return pd->status;
}

int hal_audio_decode_start(uint8_t* in_buf, uint16_t buf_size, uint16_t* in_size) {
	audio_tx_dev_t* pd = &audio_tx_dev;
	if(!pd->dec_used)
		return AUDIO_ERR_NOT_INIT;
	
	pd->status = AUDIO_ERR_OK;
	osMutexWait(pd->mutex, osWaitForever);

	NVIC_SetPriority(Audio_IRQn, IRQ_PRI_Normal);	
	NVIC_EnableIRQ(Audio_IRQn);
	audio_intr_mask_clear(0x3FFFFF);

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif

	uint16_t adec_ram_num_bytes = audio_get_adec_bytes_in_ram(), max_wr_size = audio_tx_get_adec_max_addr();
	uint16_t wr_size = (max_wr_size - adec_ram_num_bytes < buf_size) ? (max_wr_size - adec_ram_num_bytes) : (buf_size);
	for(uint16_t i = 0; i < wr_size; i++)
		audio_tx_dma_write(in_buf[i]);
	
	*in_size = wr_size;
	
	audio_dec_enable();
	audio_tx_out_enable();
	osMutexRelease(pd->mutex);
	return pd->status;
}

int hal_audio_decode_process(uint8_t* in_buf, uint16_t buf_size, uint16_t* in_size) {
	audio_tx_dev_t* pd = &audio_tx_dev;
	if(!pd->dec_used)
		return AUDIO_ERR_NOT_INIT;

	uint16_t adec_ram_num_bytes = audio_get_adec_bytes_in_ram(), max_wr_size = audio_tx_get_adec_max_addr();
	uint16_t wr_size = (max_wr_size - adec_ram_num_bytes < buf_size) ? (max_wr_size - adec_ram_num_bytes) : (buf_size);
	for(uint16_t i = 0; i < wr_size; i++)
		audio_tx_dma_write(in_buf[i]);
	
	*in_size = wr_size;
	return pd->status;
}

int hal_audio_resample_process(uint32_t* in_buf, uint16_t* in_size, uint32_t* out_buf) {
	audio_tx_dev_t* pd = &audio_tx_dev;
	if(!pd->resample_used)
		return AUDIO_ERR_NOT_INIT;

	pd->status = AUDIO_ERR_OK;
	osMutexWait(pd->mutex, osWaitForever);
	
	NVIC_SetPriority(Audio_IRQn, IRQ_PRI_Normal);	
	NVIC_EnableIRQ(Audio_IRQn);
	audio_intr_mask_clear(0x3FFFFF);

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif
		
	// WRITES
	uint16_t in_ptr = 0, out_ptr = 0;
	uint32_t buf = 0, val;	
	
	// Write PCM samples into Write DMA Interface before starting resampling (half buffer size)
	uint16_t wr_max_size = audio_wrsm_get_max_addr();
	uint16_t wr_size = wr_max_size / 2;
	while(buf < wr_size) {
		audio_tx_dma_write(in_buf[in_ptr++]);
		buf = audio_wrsm_get_samps_in_mem();
	}	
	
	/* autx_wrsm_ctrl0: Start resampling */
	audio_wrsm_autx_pull_enable();
	
	// Loop: Fill TX path input if not full, pull out TX path output if data available
	while(in_ptr < *in_size) {		
		buf = audio_wrsm_get_samps_in_mem();		
		if(buf < wr_size)
			audio_tx_dma_write(in_buf[in_ptr++]);
		
		buf = audio_rdsm_get_rd_buf_samps();		
		if(buf > 0) {
			val = audio_rx_dma_read();
			out_buf[out_ptr++] = val;
		}
	}
	/* autx_wrsm_ctrl0: Stop resampling from input */                                                                                        
	audio_wrsm_autx_pull_disable();
	
	// Continue pulling data from output until all data in TX path has been resampled
	buf = audio_rdsm_get_rd_buf_samps();
	while(buf > 0) {
		val = audio_rx_dma_read();
		out_buf[out_ptr++] = val;		
		buf = audio_rdsm_get_rd_buf_samps();
	}
	
	hal_audio_resample_stop();
	
	*in_size = out_ptr;
	
	return pd->status;
}
// STOP
int hal_audio_encode_stop() {
	audio_rx_dev_t* pd = &audio_rx_dev;
	if(!pd->enc_used)
		return AUDIO_ERR_NOT_INIT;
    osMutexWait(pd->mutex, osWaitForever);
	audio_aenc_disable();
	audio_rx_pdm_disable();	
	audio_rx_disable_rd_dma_ack();
	
	NVIC_DisableIRQ(Audio_IRQn);
	audio_intr_mask_set(0x3FFFFF);

    //hal_audio_encoder_restart();// move to hal_audio_encode_start
#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif
    
	osMutexRelease(pd->mutex);
	
	
	
	return pd->status;
}

int hal_audio_decode_stop() {
	audio_tx_dev_t* pd = &audio_tx_dev;
	if(!pd->dec_used)
		return AUDIO_ERR_NOT_INIT;
    osMutexWait(pd->mutex, osWaitForever);
	//audio_tx_disable_clk();	

	audio_dec_disable();
	audio_autx_sdm_disable();
	audio_tx_out_disable();
	audio_afifo_en_wr_disable();
	audio_afifo_en_rd_disable();
	audio_tx_i2s_master_disable();
	audio_tx_i2s_slave_disable();

	audio_tx_disable_wr_dma_ack();
	
	NVIC_DisableIRQ(Audio_IRQn);
	audio_intr_mask_set(0x3FFFFF);
	
#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->mutex);
	
	hal_audio_decoder_restart();
	
	return pd->status;
}

int hal_audio_resample_stop() {
	audio_tx_dev_t* pd = &audio_tx_dev;
	if(!pd->dec_used)
		return AUDIO_ERR_NOT_INIT;
	osMutexWait(pd->mutex, osWaitForever);
	//audio_rx_disable_clk();
	//audio_tx_disable_clk();
	
	audio_aenc_disable();
	audio_dec_disable();
	audio_tx_out_disable();
	audio_rx_pdm_disable();
	audio_afifo_en_wr_disable();
	audio_afifo_en_rd_disable();
	
	audio_rx_disable_rd_dma_ack();
	audio_tx_disable_wr_dma_ack();
	audio_rdsm_autx_disable();
	audio_wrsm_autx_disable();
	audio_wrsm_autx_pull_disable();
	
	NVIC_DisableIRQ(Audio_IRQn);
	audio_intr_mask_set(0x3FFFFF);
	
#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif
	osMutexRelease(pd->mutex);
	
	return pd->status;
}


#endif





	









