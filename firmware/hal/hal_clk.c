#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_clk.c
 *
 * @brief Platform clock functions  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "in_arm.h"
#include "in_mmap.h"
#include "in_irq.h"
#include "in_debug.h"

#include ".\hal\hal_clk.h"
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_uart.h"
#include ".\hal\hal_i2c.h"
#include ".\hal\hal_i2s.h"
#include ".\hal\hal_pwm.h"
#include ".\hal\hal_efuse.h"
#include ".\hal\hal_power.h"
#include ".\hal\hal_timer.h"

#include "..\bootloader\inc\boot_share.h"

/*
 * Global Variables
 ****************************************************************************************
 */

typedef struct {
	int rtc_ready;
	uint32_t rtc_clk;	
} clk_dev_t;

static clk_dev_t g_clk = {0};

static void aon_reg_slp_opt()
{
// sleep current optimization
#define value_for_0x1080 0x407415
	aon_write(0x1080, (value_for_0x1080 |(1U<<31)));
	aon_write(0x1084,0x402413);	
	aon_write(0x1088,0x637);
}

/*
 * Call Back
 ****************************************************************************************
 */
static void rtc_call_back(void *arg)
{
	clk_dev_t *pd = (clk_dev_t *)arg;
	/// This is a call back from timer (after 1 second) which indicate RTC should be ready.
	pd->rtc_ready = 1; 

	/// Sleep current optimized
	aon_reg_slp_opt();

	/// Switch to RTC
	aon_rc_rtc_sw(1);
	/// Change Timer 2 clock source to Rtc
	if (CFG_TIM2_CLK_RTC)
		hal_clk_tim2_set(CFG_TIM2_CLK_RTC);
}

/*
 * APIs
 ****************************************************************************************
 */

int hal_clk_root_set(uint32_t clk_root)
{
	int res = CLK_ERR_NO_ERROR;

	if (clk_root == 32000000) {
		clk_root_mux(0);
	} else if (clk_root == 64000000) {
		clk_root_mux(1);
	} else {
		res = CLK_ERR_INVALID_PARAM;			
	}

	return res;
}

uint32_t hal_clk_root_get(void)
{
	if (clk_root_mux_get() == 1) 
		return 64000000;
	else
		return 32000000;
}

int hal_clk_cpu_set(uint32_t cpu_clk)
{
	return hal_clk_d2_set(cpu_clk);
}

uint32_t hal_clk_cpu_get(void)
{
	return hal_clk_d2_get();
}

int hal_clk_d0_set(uint32_t d0_clk)
{
	uint32_t clk = hal_clk_root_get();
	uint32_t mux;
	int res = CLK_ERR_NO_ERROR;

	/// D0 domain clock
	if (clk == 64000000) {
		if (d0_clk == 32000000)
			mux = CLK_D0_DIV2;
		else if (d0_clk == 16000000)
			mux = CLK_D0_DIV4;
		else if (d0_clk == 8000000)
			mux = CLK_D0_DIV8;
		else
			res = CLK_ERR_INVALID_PARAM;			
	} else {
		if (d0_clk == 16000000)
			mux = CLK_D0_DIV2;
		else if (d0_clk == 8000000)
			mux = CLK_D0_DIV4;
		else if (d0_clk == 4000000)
			mux = CLK_D0_DIV8;	
		else		
			res = CLK_ERR_INVALID_PARAM;			
	}

	if (res == CLK_ERR_NO_ERROR)
		clk_d0_mux(mux);

	return res;
}

uint32_t hal_clk_d0_get(void)
{
	uint32_t clk = hal_clk_root_get();
	uint32_t mux = clk_d0_mux_get();

	if (mux == CLK_D0_DIV2)
		clk /= 2;
	else if (mux == CLK_D0_DIV4)
		clk /= 4;
	else
		clk /= 8;
       #if CFG_FPGA	
        clk = 32000000;
       #endif
	return clk;
}

int hal_clk_d1_set(uint32_t d1_clk)
{
	uint32_t clk = hal_clk_root_get();
	uint32_t mux;
	int res = CLK_ERR_NO_ERROR;

	/// D0 domain clock
	if (clk == 64000000) {
		if (d1_clk == 32000000)
			mux = CLK_D1_DIV2;
		else if (d1_clk == 16000000)
			mux = CLK_D1_DIV4;
		else if (d1_clk == 8000000)
			mux = CLK_D1_DIV8;
		else
			res = CLK_ERR_INVALID_PARAM;			
	} else {
		if (d1_clk == 16000000)
			mux = CLK_D0_DIV2;
		else if (d1_clk == 8000000)
			mux = CLK_D0_DIV4;
		else if (d1_clk == 4000000)
			mux = CLK_D0_DIV8;	
		else		
			res = CLK_ERR_INVALID_PARAM;			
	}

	if (res == CLK_ERR_NO_ERROR)
		clk_d1_mux(mux);

	return res;
}

uint32_t hal_clk_d1_get(void)
{
	uint32_t clk = hal_clk_root_get();
	uint32_t mux = clk_d1_mux_get();

	if (mux == CLK_D0_DIV2)
		clk /= 2;
	else if (mux == CLK_D0_DIV4)
		clk /= 4;
	else
		clk /= 8;
       #if CFG_FPGA	
        clk = 16000000;
       #endif
	return clk;
}

int hal_clk_d2_set(uint32_t d2_clk)
{
	uint32_t clk = hal_clk_root_get();
	uint32_t mux;
	int res = CLK_ERR_NO_ERROR;

	/// D0 domain clock
	if (clk == 64000000) {
		if (d2_clk == 64000000)
			mux = CLK_D2_DIV1;
		else if (d2_clk == 32000000)
			mux = CLK_D2_DIV2;
		else if (d2_clk == 16000000)
			mux = CLK_D2_DIV4;
		else if (d2_clk == 8000000)
			mux = CLK_D2_DIV8;
		else
			res = CLK_ERR_INVALID_PARAM;			
	} else {
		if (d2_clk == 32000000)
			mux = CLK_D2_DIV1;
		else if (d2_clk == 16000000)
			mux = CLK_D2_DIV2;
		else if (d2_clk == 8000000)
			mux = CLK_D0_DIV4;	
		else if (d2_clk == 4000000)		
			mux = CLK_D0_DIV8;	
		else
			res = CLK_ERR_INVALID_PARAM;			
	}

	if (res == CLK_ERR_NO_ERROR)
		clk_d2_mux(mux);

	return res;
}

uint32_t hal_clk_d2_get(void)
{
	uint32_t clk = hal_clk_root_get();
	uint32_t mux = clk_d2_mux_get();

	if (mux == CLK_D2_DIV2)
		clk /= 2;
	else if (mux == CLK_D2_DIV4)
		clk /= 4;
	else 
		clk /= 8;
       #if CFG_FPGA	
        clk = 32000000;
       #endif
	return clk;
}

int hal_clk_tim1_set(uint32_t tim0_clk)
{
	uint32_t clk = hal_clk_root_get();
	uint32_t mux;
	int res = CLK_ERR_NO_ERROR;

	if (clk == 64000000) {
		if (tim0_clk == 16000000)
			mux = CLK_TIM_DIV4;
		else if (tim0_clk == 8000000)
			mux = CLK_TIM_DIV8;
		else if (tim0_clk == 4000000)
			mux = CLK_TIM_DIV16;
		else
			res = CLK_ERR_INVALID_PARAM;			
	} else {
		if (tim0_clk == 8000000)
			mux = CLK_TIM_DIV4;
		else if (tim0_clk == 4000000)
			mux = CLK_TIM_DIV8;
		else if (tim0_clk == 2000000)
			mux = CLK_TIM_DIV16;	
		else
			res = CLK_ERR_INVALID_PARAM;			
	}
		
	if (res == CLK_ERR_NO_ERROR)
		clk_timer1_mux(mux);
	
	return res;
}

uint32_t hal_clk_tim1_get(void)
{
	uint32_t clk = hal_clk_root_get();
	uint32_t mux = clk_timer1_mux_get();

	if (mux == CLK_TIM_DIV4)
		clk /= 4;
	else if (mux == CLK_TIM_DIV8)
		clk /= 8;
	else
		clk /= 16;

	return clk;
}

void hal_clk_tim2_set(int rtc_clk)
{
	clk_timer2_mux(rtc_clk);
}

int hal_clk_hwacc_set(uint32_t hwacc_clk)
{
	uint32_t clk = hal_clk_root_get();
	uint32_t mux;
	int res = CLK_ERR_NO_ERROR;

	if (clk == 64000000) {
		if (hwacc_clk == 64000000)
			mux = CLK_HWACC_DIV1;
		else if (hwacc_clk == 32000000)
			mux = CLK_HWACC_DIV2;
		else if (hwacc_clk == 16000000)
			mux = CLK_HWACC_DIV4;
		else if (hwacc_clk == 8000000)
			mux = CLK_HWACC_DIV8;
		else
			res = CLK_ERR_INVALID_PARAM;			
	} else {
		if (hwacc_clk == 32000000)
			mux = CLK_HWACC_DIV1;
		else if (hwacc_clk == 16000000)
			mux = CLK_HWACC_DIV2;
		else if (hwacc_clk == 8000000)
			mux = CLK_HWACC_DIV4;
		else if (hwacc_clk == 4000000)
			mux = CLK_HWACC_DIV8;
		else
			res = CLK_ERR_INVALID_PARAM;			
	}
		
	if (res == CLK_ERR_NO_ERROR)
		clk_hwacc_mux(mux);
	
	return res;
}

int hal_clk_sadc_set(uint32_t sadc_clk)
{
	uint32_t clk = hal_clk_root_get();
	uint32_t mux;
	int res = CLK_ERR_NO_ERROR;

	if (clk == 64000000) {
		if (sadc_clk == 16000000)
			mux = CLK_SADC_DIV4;
		else if (sadc_clk == 8000000)
			mux = CLK_SADC_DIV8;
		else if (sadc_clk == 4000000)
			mux = CLK_SADC_DIV16;
		else if (sadc_clk == 2000000)
			mux = CLK_SADC_DIV32;
		else if (sadc_clk == 1000000)
			mux = CLK_SADC_DIV64;
		else
			res = CLK_ERR_INVALID_PARAM;			
	} else {
		if (sadc_clk == 8000000)
			mux = CLK_SADC_DIV4;
		else if (sadc_clk == 4000000)
			mux = CLK_SADC_DIV8;
		else if (sadc_clk == 2000000)
			mux = CLK_SADC_DIV16;
		else if (sadc_clk == 1000000)
			mux = CLK_SADC_DIV32;
		else
			res = CLK_ERR_INVALID_PARAM;			
	}
		
	if (res == CLK_ERR_NO_ERROR)
		clk_sadc_mux(mux);
	
	return res;
}

uint32_t hal_clk_sadc_get(void)
{
	uint32_t clk = hal_clk_root_get();
	uint32_t mux = clk_sadc_mux_get();

	if (mux == CLK_SADC_DIV4)
		clk /= 4;
	else if (mux == CLK_SADC_DIV8)
		clk /= 8;
	else if (mux == CLK_SADC_DIV16)
		clk /= 16;
	else if (mux == CLK_SADC_DIV32)
		clk /= 32;
	else 
		clk /= 64;

	return clk;
}

int hal_clk_smem_set(uint32_t smem_clk)
{
	uint32_t clk = hal_clk_root_get();
	uint32_t mux;
	int res = CLK_ERR_NO_ERROR;

	if (clk == 64000000) {
		if (smem_clk == 64000000)
			mux = CLK_SMEM_DIV1;
		else if (smem_clk == 32000000)
			mux = CLK_SMEM_DIV2;
		else if (smem_clk == 16000000)
			mux = CLK_SMEM_DIV4;
		else if (smem_clk == 8000000)
			mux = CLK_SMEM_DIV8;
		else
			res = CLK_ERR_INVALID_PARAM;			
	} else {
		if (smem_clk == 32000000)
			mux = CLK_SMEM_DIV1;
		else if (smem_clk == 16000000)
			mux = CLK_SMEM_DIV2;
		else if (smem_clk == 8000000)
			mux = CLK_SMEM_DIV4;
		else if (smem_clk == 4000000)
			mux = CLK_SMEM_DIV8;
		else
			res = CLK_ERR_INVALID_PARAM;			
	}
		
	if (res == CLK_ERR_NO_ERROR)
		clk_smem_mux(mux);
	
	return res;
}

int hal_clk_qspi_set(uint32_t qspi_clk)
{
	uint32_t clk = hal_clk_root_get();
	uint32_t mux;
	int res = CLK_ERR_NO_ERROR;

	if (clk == 64000000) {
		if (qspi_clk == 64000000)
			mux = CLK_QSPI_DIV1;
		else if (qspi_clk == 32000000)
			mux = CLK_QSPI_DIV2;
		else if (qspi_clk == 16000000)
			mux = CLK_QSPI_DIV4;
		else if (qspi_clk == 8000000)
			mux = CLK_QSPI_DIV8;
		else
			res = CLK_ERR_INVALID_PARAM;			
	} else {
		if (qspi_clk == 32000000)
			mux = CLK_QSPI_DIV1;
		else if (qspi_clk == 16000000)
			mux = CLK_QSPI_DIV2;
		else if (qspi_clk == 8000000)
			mux = CLK_QSPI_DIV4;
		else if (qspi_clk == 4000000)
			mux = CLK_QSPI_DIV8;
		else
			res = CLK_ERR_INVALID_PARAM;			
	}
		
	if (res == CLK_ERR_NO_ERROR)
		clk_qspi_mux(mux);
	
	return res;
}

uint32_t hal_clk_qspi_get(void)
{
	uint32_t clk = hal_clk_root_get();
	uint32_t mux = clk_qspi_mux_get();

	if (mux == CLK_QSPI_DIV2)
		clk /= 2;
	else if (mux == CLK_QSPI_DIV4)
		clk /= 4;
	else if (mux == CLK_QSPI_DIV8)
		clk /= 8;

	return clk;
}

int hal_clk_efuse_set(uint32_t efuse_clk)
{
	uint32_t clk = hal_clk_root_get();
	uint32_t mux;
	int res = CLK_ERR_NO_ERROR;

	if (clk == 64000000) {
		if (efuse_clk == 16000000)
			mux = CLK_EFUSE_DIV4;
		else if (efuse_clk == 8000000)
			mux = CLK_EFUSE_DIV8;
		else
			res = CLK_ERR_INVALID_PARAM;			
	} else {
		if (efuse_clk == 8000000)
			mux = CLK_EFUSE_DIV4;
		else if (efuse_clk == 4000000)
			mux = CLK_EFUSE_DIV8;
		else
			res = CLK_ERR_INVALID_PARAM;			
	}
		
	if (res == CLK_ERR_NO_ERROR)
		clk_efuse_mux(mux);
	
	return res;
}

void hal_clk_si2s_set(int ext_clk)
{
	clk_slv_i2s_mux(ext_clk);
}

void hal_clk_mi2s_set(uint32_t bit_clk)
{
	uint32_t clk_cpu = hal_clk_root_get();
	uint32_t div = (clk_cpu/bit_clk) & 0xFFF;
	clk_mi2s(div);
}

void hal_clk_audio_codec(int mux)
{
	clk_audio_codec_mux(mux);
}

void hal_clk_efuse_en(int en)
{
	clk_efuse_en(en);		
}

void hal_clk_uart_en(int id, int on)
{
	if (id == UART0_ID) {
		clk_uart0_en(on);
	} else {
		clk_uart1_en(on);
	}
}

void hal_clk_i2c_en(int id, int on)
{
	if (id == I2C0_ID) {
		clk_i2c0_en(on);
	} else {
		clk_i2c1_en(on);
	}
}

void hal_clk_pwm_en(int id, int on)
{
	if (id == PWM0_ID) {
		clk_pwm0_en(on);
	} else if (id == PWM1_ID) {
		clk_pwm1_en(on);
	} else if (id == PWM2_ID) {
		clk_pwm2_en(on);
	} else if (id == PWM3_ID) {
		clk_pwm3_en(on);
	} else if (id == PWM4_ID) {
		clk_pwm4_en(on);
	} else {
		return;
	}
}

void hal_clk_wdt_en(int on)
{
	clk_wdt_en(on);
}

void hal_clk_kb_en(int on)
{
	clk_kb_en(on);
}

void hal_clk_ecc_en(int on)
{
	clk_ecc_en(on);
}

void hal_clk_hash_en(int on)
{
	clk_hash_en(on);
}

void hal_clk_aes_en(int on)
{
	clk_aes_en(on);
}

void hal_clk_counter_en(int on)
{
	clk_counter_en(on);
}

void hal_clk_audio_en(int on)
{
	clk_audio_en(on);
}

void hal_clk_sadc_en(int on)
{
	clk_sadc_en(on);
}

void hal_clk_i2s_en(int id, int on)
{
	if (id == MI2S_ID) {
		clk_mi2s_en(on);
	} else {
		clk_si2s_en(on);
	}
}

void hal_clk_quaddec_en(int on)
{
	clk_quaddec_en(on);
}

void hal_clk_dma_en(int on)
{
	clk_dma_en(on);
}

void hal_clk_ble_en(int on)
{
	clk_ble_en(on);
}

void hal_clk_gpio_intr(int port, int on)
{
	if (port == GPIO_PORT_0)
		clk_gpio_0_intr_en(on);
	else if (port == GPIO_PORT_1)
		clk_gpio_1_intr_en(on);
	else if (port == GPIO_PORT_2)
		clk_gpio_2_intr_en(on);
	else if (port == GPIO_PORT_3)
		clk_gpio_3_intr_en(on);
	else 
		clk_gpio_4_intr_en(on);
}

void hal_clk_mspi_en(int on)
{
	clk_mspi_en(on);
}

void hal_clk_sspi_en(int on)
{
	clk_sspi_en(on);
}

void hal_clk_calib_xo(void)
{

}

void hal_clk_calib_rtc(void)
{
	/// TODO: RC calibration

	g_clk.rtc_clk = CFG_RTC_CLK;
}

void hal_clk_rtc_en(int en)
{
	if (en) {
		if (!aon_is_rtc_en()) {
			aon_rtc_en(1);
		}
		/// kick start timer for 1 second
		hal_timer_once(1000, (void *)&g_clk, rtc_call_back); 

		/// Set the RTC calue
		if (efuse_get_rtc_installed()) {
			if (efuse_rtc_32khz_clk()) {
		
				g_clk.rtc_clk = 32000;
			} else {
				g_clk.rtc_clk = 32768;
			}		
		} else {
			if (CFG_RTC_EN) {
				g_clk.rtc_clk = CFG_RTC_CLK;
			} 
		}
	} else {
		/// RC - TODO
		/// Sleep current optimized
		aon_reg_slp_opt();
		hal_clk_calib_rtc();
	}
}

int hal_clk_rtc_ready(void)
{
	return g_clk.rtc_ready;	
}

uint32_t hal_clk_rtc_get(void)
{
	return g_clk.rtc_clk;
}

