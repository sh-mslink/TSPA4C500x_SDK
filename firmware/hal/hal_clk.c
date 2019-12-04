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

#include "..\rf\rf_int.h"


/*
 * Global Variables
 ****************************************************************************************
 */

typedef struct {
	int rtc_ready;
	uint32_t rtc_clk;	
	//uint32_t rtc_clk0;	
	float rtc_clk0;	
} clk_dev_t;

static clk_dev_t g_clk = {0};

/*
 * Isr
 ****************************************************************************************
 */

__irq void Calib_Handler()
{
	uint32_t val, cal_result;

	val = RD_WORD(0x44125004);
	cal_result = val & 0x3fffffff;
	val &= ~(0x1 << 30);
	WR_WORD(0x44125004, val); // clear the cal result

#if 1
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
#endif

	uint32_t freq=((uint32_t)(32000000.0f / (cal_result/524288.f)));
	if (g_clk.rtc_clk0 == 0)
		g_clk.rtc_clk0 = freq;
	else 
		g_clk.rtc_clk0=  g_clk.rtc_clk0 *3.0f/4.0f + freq/4.0f;

	g_clk.rtc_clk = (((uint32_t) (g_clk.rtc_clk0*(1+1*(float)CFG_RC_PPM_OFFSET/1e6))) + 8) >> 4 ;

	//g_clk.rtc_clk = ((uint32_t)(32000000.0 / (cal_result/32768.)));
	g_clk.rtc_ready = 1;

	// kick start calibration again
	hal_clk_calib_rc(6);
	
}


/*
 * Call Back
 ****************************************************************************************
 */
static void rtc_call_back(void *arg)
{
#if !CFG_FPGA
	clk_dev_t *pd = (clk_dev_t *)arg;
	/// This is a call back from timer (after 1 second) which indicate RTC should be ready.
	pd->rtc_ready = 1; 

	/// RTC Sleep current optimized
	rf_int_aon_reg_slp_opt(1);

	/// Switch to RTC
	aon_rc_rtc_sw(1);

	/// Change Timer 2 clock source to Rtc
	if (CFG_RTC_EN)
		hal_clk_tim2_set(CFG_RTC_EN);
#endif	// !CFG_FPGA

}

/*
 * APIs
 ****************************************************************************************
 */

int hal_clk_root_set(uint32_t clk_root)
{
	int res = CLK_ERR_NO_ERROR;

#if !CFG_FPGA
	if (clk_root == 32000000) {
		clk_root_mux(0);
	} else if (clk_root == 64000000) {
		clk_root_mux(1);
	} else {
		res = CLK_ERR_INVALID_PARAM;			
	}
#endif	// !CFG_FPGA

	return res;
}

uint32_t hal_clk_root_get(void)
{
#if !CFG_FPGA
	if (clk_root_mux_get() == 1) 
		return 64000000;
	else
		return 32000000;
#else
	return 32000000;
#endif	// !CFG_FPGA

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
#if !CFG_FPGA
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
#else
	int res = CLK_ERR_NO_ERROR;
#endif	// !CFG_FPGA

	return res;
}

uint32_t hal_clk_d0_get(void)
{
#if !CFG_FPGA

	uint32_t clk = hal_clk_root_get();
	uint32_t mux = clk_d0_mux_get();

	if (mux == CLK_D0_DIV2)
		clk /= 2;
	else if (mux == CLK_D0_DIV4)
		clk /= 4;
	else
		clk /= 8;
#else
	uint32_t clk = 32000000;
#endif	// !CFG_FPGA

	return clk;
}

int hal_clk_d1_set(uint32_t d1_clk)
{
#if !CFG_FPGA
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
#else
	int res = CLK_ERR_NO_ERROR;
#endif	// !CFG_FPGA

	return res;
}

uint32_t hal_clk_d1_get(void)
{
#if !CFG_FPGA
	uint32_t clk = hal_clk_root_get();
	uint32_t mux = clk_d1_mux_get();

	if (mux == CLK_D0_DIV2)
		clk /= 2;
	else if (mux == CLK_D0_DIV4)
		clk /= 4;
	else
		clk /= 8;
#else
	uint32_t clk = 16000000;
#endif	// !CFG_FPGA

	return clk;
}

int hal_clk_d2_set(uint32_t d2_clk)
{
#if !CFG_FPGA
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
#else
	int res = CLK_ERR_NO_ERROR;
#endif	// !CFG_FPGA

	return res;
}

uint32_t hal_clk_d2_get(void)
{
#if !CFG_FPGA
	uint32_t clk = hal_clk_root_get();
	uint32_t mux = clk_d2_mux_get();

	if (mux == CLK_D2_DIV2)
		clk /= 2;
	else if (mux == CLK_D2_DIV4)
		clk /= 4;
	else 
		clk /= 8;
#else
	uint32_t clk = 32000000;
#endif	// !CFG_FPGA
	return clk;
}

int hal_clk_tim1_set(uint32_t tim0_clk)
{
#if !CFG_FPGA

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
#else
	int res = CLK_ERR_NO_ERROR;
#endif	// !CFG_FPGA
	
	return res;
}

uint32_t hal_clk_tim1_get(void)
{
#if !CFG_FPGA
	uint32_t clk = hal_clk_root_get();
	uint32_t mux = clk_timer1_mux_get();

	if (mux == CLK_TIM_DIV4)
		clk /= 4;
	else if (mux == CLK_TIM_DIV8)
		clk /= 8;
	else
		clk /= 16;
#else
	uint32_t clk = 16000000;
#endif	// !CFG_FPGA

	return clk;
}

void hal_clk_tim2_set(int rtc_clk)
{
#if !CFG_FPGA
	clk_timer2_mux(rtc_clk);
#endif	// !CFG_FPGA

}

int hal_clk_hwacc_set(uint32_t hwacc_clk)
{
#if !CFG_FPGA
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
#else

	int res = CLK_ERR_NO_ERROR;

#endif	// !CFG_FPGA
	
	return res;
}

int hal_clk_sadc_set(uint32_t sadc_clk)
{
#if !CFG_FPGA
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
#else
	int res = CLK_ERR_NO_ERROR;
#endif	// !CFG_FPGA
	
	return res;
}

uint32_t hal_clk_sadc_get(void)
{
#if !CFG_FPGA
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
#else
	uint32_t clk = 1000000;
#endif	// !CFG_FPGA

	return clk;
}

int hal_clk_smem_set(uint32_t smem_clk)
{
#if !CFG_FPGA
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

#else

	int res = CLK_ERR_NO_ERROR;

#endif	// !CFG_FPGA
	
	return res;
}

int hal_clk_qspi_set(uint32_t qspi_clk)
{
#if !CFG_FPGA
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
#else
	int res = CLK_ERR_NO_ERROR;
#endif	// !CFG_FPGA
	
	return res;
}

uint32_t hal_clk_qspi_get(void)
{
#if !CFG_FPGA
	uint32_t clk = hal_clk_root_get();
	uint32_t mux = clk_qspi_mux_get();

	if (mux == CLK_QSPI_DIV2)
		clk /= 2;
	else if (mux == CLK_QSPI_DIV4)
		clk /= 4;
	else if (mux == CLK_QSPI_DIV8)
		clk /= 8;
#else
	uint32_t clk = 32000000;
#endif	// !CFG_FPGA

	return clk;
}

int hal_clk_efuse_set(uint32_t efuse_clk)
{
#if !CFG_FPGA
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
#else
	int res = CLK_ERR_NO_ERROR;
#endif	// !CFG_FPGA
	
	return res;
}

void hal_clk_si2s_set(int ext_clk)
{
#if !CFG_FPGA
	clk_slv_i2s_mux(ext_clk);
#endif	// !CFG_FPGA

}

void hal_clk_mi2s_set(uint32_t bit_clk)
{
#if !CFG_FPGA
	uint32_t clk_cpu = hal_clk_root_get();
	uint32_t div = (clk_cpu/bit_clk) & 0xFFF;
	clk_mi2s(div);
#endif	// !CFG_FPGA

}

void hal_clk_audio_codec(int mux)
{
#if !CFG_FPGA
	clk_audio_codec_mux(mux);
#endif	// !CFG_FPGA

}

void hal_clk_efuse_en(int en)
{
#if !CFG_FPGA
	clk_efuse_en(en);		
#endif	// !CFG_FPGA

}

void hal_clk_uart_en(int id, int on)
{
#if !CFG_FPGA
	if (id == UART0_ID) {
		clk_uart0_en(on);
	} else {
		clk_uart1_en(on);
	}
#endif	// !CFG_FPGA

}

void hal_clk_i2c_en(int id, int on)
{
#if !CFG_FPGA
	if (id == I2C0_ID) {
		clk_i2c0_en(on);
	} else {
		clk_i2c1_en(on);
	}
#endif	// !CFG_FPGA

}

void hal_clk_pwm_en(int id, int on)
{
#if !CFG_FPGA

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
#endif	// !CFG_FPGA

}

void hal_clk_wdt_en(int on)
{
#if !CFG_FPGA
	clk_wdt_en(on);
#endif	// !CFG_FPGA

}

void hal_clk_kb_en(int on)
{
#if !CFG_FPGA
	clk_kb_en(on);
#endif	// !CFG_FPGA

}

void hal_clk_ecc_en(int on)
{
#if !CFG_FPGA
	clk_ecc_en(on);
#endif	// !CFG_FPGA

}

void hal_clk_hash_en(int on)
{
#if !CFG_FPGA
	clk_hash_en(on);
#endif	// !CFG_FPGA

}

void hal_clk_aes_en(int on)
{
#if !CFG_FPGA
	clk_aes_en(on);
#endif	// !CFG_FPGA

}

void hal_clk_counter_en(int on)
{
#if !CFG_FPGA
	clk_counter_en(on);
#endif	// !CFG_FPGA

}

void hal_clk_audio_en(int on)
{
#if !CFG_FPGA
	clk_audio_en(on);
#endif	// !CFG_FPGA

}

void hal_clk_sadc_en(int on)
{
#if !CFG_FPGA
	clk_sadc_en(on);
#endif	// !CFG_FPGA

}

void hal_clk_i2s_en(int id, int on)
{
#if !CFG_FPGA
	if (id == MI2S_ID) {
		clk_mi2s_en(on);
	} else {
		clk_si2s_en(on);
	}
#endif	// !CFG_FPGA

}

void hal_clk_quaddec_en(int on)
{
#if !CFG_FPGA
	clk_quaddec_en(on);
#endif	// !CFG_FPGA

}

void hal_clk_dma_en(int on)
{
#if !CFG_FPGA
	clk_dma_en(on);
#endif	// !CFG_FPGA
}

void hal_clk_ble_en(int on)
{
#if !CFG_FPGA
	clk_ble_en(on);
#endif	// !CFG_FPGA
}

void hal_clk_gpio_intr(int port, int on)
{
#if !CFG_FPGA
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
#endif	// !CFG_FPGA

}

void hal_clk_mspi_en(int on)
{
#if !CFG_FPGA
	clk_mspi_en(on);
#endif	// !CFG_FPGA

}

void hal_clk_sspi_en(int on)
{
#if !CFG_FPGA
	clk_sspi_en(on);
#endif	// !CFG_FPGA

}

void hal_clk_calib_xo(void)
{

}

void hal_clk_calib_rc(int cycles)
{
#if !CFG_FPGA
	uint32_t val;

	WR_WORD(0x44125004, 0);
	val = cycles | (1<<4); // Number of slow clk cycles to be calibrated (2 to the power this number);      
	WR_WORD(0x44125000, val); // start the calibration

	/// Result in the interrupt service routine
#endif	// !CFG_FPGA

	return;
}

void hal_clk_rtc_en(int en)
{
#if !CFG_FPGA
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
		/// Turn on calibration clock
		clk_calib_en(1);

		/// RC Sleep current optimized
		rf_int_aon_reg_slp_opt(0);

		/// Calib rc			
		hal_clk_calib_rc(8);
		/// Enable RC calibration interrupt
		NVIC_ClearPendingIRQ(Calib_IRQn);
		NVIC_SetPriority(Calib_IRQn, IRQ_PRI_Normal);	
		NVIC_EnableIRQ(Calib_IRQn);

		/// Wait for end of calibration
		while (!g_clk.rtc_ready);
	}
#endif	// !CFG_FPGA
}

int hal_clk_rtc_ready(void)
{
#if !CFG_FPGA
	return g_clk.rtc_ready;	
#else
	return 1;
#endif	// !CFG_FPGA

}

uint32_t hal_clk_rtc_get(void)
{
#if !CFG_FPGA
	return g_clk.rtc_clk;
#else
	return 32768;
#endif	// !CFG_FPGA

}

