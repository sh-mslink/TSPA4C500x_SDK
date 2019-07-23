#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_i2s.c
 *
 * @brief Platform I2s Driver  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#define CFG_NB_I2S		(CFG_MI2S_EN + CFG_SI2S_EN)

/*
 * Includes
 ****************************************************************************************
 */

#if CFG_NB_I2S
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "in_arm.h"
#include "in_mmap.h"
#include "in_irq.h"
#include "in_debug.h"

#include ".\hal\hal_clk.h"
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_i2s.h"

#if CFG_PM_EN
#include ".\hal\hal_power.h"
#endif	/* CFG_PM_EN */

#include "cmsis_os.h"

/*
 * Defines
 ****************************************************************************************
 */

#define I2S_FIFO_DEPTH	8
#define I2S_RX_FIFO_TL 	4
#define I2S_TX_FIFO_TL 	4

/*
 * Structures
 ****************************************************************************************
 */

typedef struct {
	char used;
	char buffer_idx;
	char dir;
	char ch_ws;

	char type;
	char pad[3];

	uint32_t base;

	void *buffer[2];
	uint16_t buffer_oft;
	uint16_t buffer_len;

	void *arg;
	void (*callback)(void *arg, int id, int status) ;	

} i2s_ch_t;

typedef struct {
	char id;
	char used;
	char wss;
	char pad[3];

	uint32_t base;
	IRQn_Type irq;

	uint32_t clk_pin;
	uint32_t ws_pin;
	uint32_t sd0_pin;
	uint32_t sd1_pin;

	uint8_t mu[16];
	osMutexId h_mu;

	i2s_ch_t ch[2];	

	/// Power 
#if CFG_PM_EN
	int power_state;
	struct pm_module pmd;
#endif
} i2s_dev_t;


static i2s_dev_t i2s_dev[CFG_NB_I2S] = {
#if CFG_MI2S_EN 	
	{
		.id = MI2S_ID,
		.used = 0,
		.base = MI2S_BASE,
		.irq = I2sm_IRQn,

		.ch[0].used = 0,
		.ch[0].buffer_idx = 0,
		.ch[0].base = MI2S_CH0_BASE,
		.ch[1].used = 0,
		.ch[1].buffer_idx = 0,
		.ch[1].base = MI2S_CH1_BASE,

	},
#endif	/* CFG_MI2S */
#if CFG_SI2S_EN	
	{
		.id = SI2S_ID,
		.used = 0,
		.base = SI2S_BASE,
		.irq = I2ss_IRQn,

		.ch[0].used = 0,
		.ch[0].buffer_idx = 0,
		.ch[0].base = SI2S_CH0_BASE,
		.ch[1].used = 0,
		.ch[1].buffer_idx = 0,
		.ch[1].base = SI2S_CH1_BASE,
	},
#endif	/* CFG_SI2S */
};

/*
 * Pin Mux
 ****************************************************************************************
 */

static void i2s_pin_mux_en(i2s_dev_t *pd, int en)
{
	if (en) {
		hal_gpio_pin_cfg(pd->clk_pin);
		hal_gpio_pin_cfg(pd->ws_pin);
		if (pd->sd0_pin)
			hal_gpio_pin_cfg(pd->sd0_pin);
		if (pd->sd1_pin)
			hal_gpio_pin_cfg(pd->sd1_pin);
	} else {
		hal_gpio_pin_dft(pd->clk_pin);
		hal_gpio_pin_dft(pd->ws_pin);
		hal_gpio_pin_dft(pd->sd0_pin);
		hal_gpio_pin_dft(pd->sd1_pin);
	}
}

static int i2s_pin_chk(i2s_dev_t *pd)
{
	if (pd->id == MI2S_ID) {

		/// GPIO_1_3 = mstr_clk
		/// GPIO_1_4 = mstr_ws
		/// GPIO_1_5 = mstr_sd0
		/// GPIO_1_6 = mstr_sd1

		/// Sanity check

		/// CLK pin
		if (((CFG_GPIO_1_3>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_I2S_MSTR_CLK) 
			pd->clk_pin = CFG_GPIO_1_3;
		else
			return 0;

		/// WS
		if (((CFG_GPIO_1_4>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_MSTR_WS) 
			pd->ws_pin = CFG_GPIO_1_4;
		else
			return 0;

		/// SD0
		if (((CFG_GPIO_1_5>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_MSTR_SD0)  
			pd->sd0_pin = CFG_GPIO_1_5;
		else
			pd->sd0_pin = 0;

		/// SD1
		if (((CFG_GPIO_1_6>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_MSTR_SD1)  
			pd->sd1_pin = CFG_GPIO_1_6;
		else
			pd->sd1_pin = 0;
	
		if (!(pd->sd0_pin || pd->sd1_pin))
			return 0; 
	}

	if (pd->id == SI2S_ID) {

		/// GPIO_1_3 = slv_clk
		/// GPIO_1_4 = slv_ws
		/// GPIO_1_5 = slv_sd0
		/// GPIO_1_6 = slv_sd1

		/// Sanity check

		/// CLK pin
		if (((CFG_GPIO_1_3>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_I2S_SLV_CLK0) 
			pd->clk_pin = CFG_GPIO_1_3;
		else
			return 0;

		/// WS
		if (((CFG_GPIO_1_4>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_SLV_WS) 
			pd->ws_pin = CFG_GPIO_1_4;
		else
			return 0;

		/// SD0
		if (((CFG_GPIO_1_5>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_SLV_SD0)  
			pd->sd0_pin = CFG_GPIO_1_5;
		else
			pd->sd0_pin = 0;

		if (((CFG_GPIO_1_7>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2S_SLV_SD1)  
			pd->sd1_pin = CFG_GPIO_1_7;
		else
			pd->sd1_pin = 0;

		if (!(pd->sd0_pin || pd->sd1_pin))
			return 0; 

	}

	return 1;
}

/*
 * PM
 ****************************************************************************************
 */

#if CFG_PM_EN
static int i2s_pm_state(void *arg, uint32_t *sleep_duration)
{
	i2s_dev_t *pd = (i2s_dev_t *)arg;

	if (pd->ch[0].used || pd->ch[1].used) 
		pd->power_state = PM_SLEEP;
	else
		pd->power_state = PM_DEEP_SLEEP;


	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->power_state;
}

static void i2s_pm_down(void *arg, uint32_t sleep_duration)
{
	/// TODO
}
static void i2s_pm_up(void *arg)
{
	i2s_dev_t *pd = (i2s_dev_t *)arg;

	/// Enable it
	i2s_enable(pd->base);	

	/// Word size
	i2s_sclk_wss(pd->base, pd->wss);

	/// Clock
	if (pd->id == MI2S_ID) {
		i2s_sclk_enable(pd->base);
	}

	/// Direction
	i2s_tx_fifo_reset(pd->base);
	i2s_rx_fifo_reset(pd->base);
	i2s_tx_enable(pd->base);		
	i2s_rx_enable(pd->base);		

	/// Pins enable
	//i2s_pin_mux_en(pd, 1);
}
#endif	/* CFG_PM_ENABLE */

/*
 * ISR
 ****************************************************************************************
 */
static void i2s_isr(i2s_dev_t *pd)
{
	int i, ii;

	for (i = 0; i < I2S_CH_MAX; i++) {
		i2s_ch_t *pch = &pd->ch[i];

		if (pch->used) {
			uint32_t base = pch->base;
			uint32_t status = i2s_chx_intr_status(base);

			if (status & I2S_CHx_IT_RXFO) {
//PRINTD(DBG_TRACE, "I2S: RXFO\r\n");
				i2s_chx_rov_clr(base);

				if ((pch->dir == I2S_DIR_RX) && pch->callback)
					pch->callback(pch->arg, pch->buffer_idx, I2S_ERR_RX_OV);
			}

			if (status & I2S_CHx_IT_RXDA) {
				/// Read data out first
				uint32_t data1[I2S_RX_FIFO_TL], data2[I2S_RX_FIFO_TL];
				
				for (ii = 0; ii < I2S_RX_FIFO_TL; ii++) {
					data1[ii] = i2s_chx_lrx_data(base);		// left channel
					data2[ii] = i2s_chx_rrx_data(base);		// right channel
				}

				/// Copy to the buffer
				int idx = pch->buffer_idx;
				uint16_t oft = pch->buffer_oft;

				if (pch->ch_ws <= I2S_CH_WS_16_BITS) {
					uint16_t *data = (uint16_t *)pch->buffer[idx];
					for (int ii = 0; ii < I2S_RX_FIFO_TL; ii++) {
						if (pch->type == I2S_MONO) {
							*data++ = data1[ii];		
							oft += 1;
						} else {
							*data++ = data1[ii];		
							*data++ = data2[ii];		
							oft += 2;
						}
						if (oft >= pch->buffer_len) {
							if ((pch->dir == I2S_DIR_RX) && pch->callback)
								pch->callback(pch->arg, idx, I2S_ERR_OK);

							idx ^= 1;
							data = (uint16_t *)pch->buffer[idx];
							oft = 0;
						}
					}
				} else {
					uint32_t *data = (uint32_t *)pch->buffer[idx];
					for (int ii = 0; ii < I2S_RX_FIFO_TL; ii++) {
						if (pch->type == I2S_MONO) {
							*data++ = data1[ii];		
							oft += 1;
						} else {
							*data++ = data1[ii];		
							*data++ = data2[ii];		
							oft += 2;
						}
						if (oft >= pch->buffer_len) {
							if ((pch->dir == I2S_DIR_RX) && pch->callback)
								pch->callback(pch->arg, idx, I2S_ERR_OK);

							idx ^= 1;
							data = (uint32_t *)pch->buffer[idx];
							oft = 0;
						}
					}
				}
				pch->buffer_idx = idx;
				pch->buffer_oft = oft;
			}

			if (status & I2S_CHx_IT_TXFE) {
				int idx = pch->buffer_idx;
				uint16_t oft = pch->buffer_oft;

				if (pch->ch_ws <= I2S_CH_WS_16_BITS) {
					uint16_t *data = (uint16_t *)pch->buffer[idx];
					for (int ii = 0; ii < I2S_TX_FIFO_TL; ii++) {
						if (pch->type == I2S_MONO) {
							i2s_chx_ltx_data(base, *data);
							i2s_chx_rtx_data(base, *data++);
							oft += 1;
						} else {
							i2s_chx_ltx_data(base, *data++);
							i2s_chx_rtx_data(base, *data++);
							oft += 2;
						}

						if (oft >= pch->buffer_len) {
							if ((pch->dir == I2S_DIR_TX) && pch->callback)
								pch->callback(pch->arg, idx, I2S_ERR_OK);

							idx ^= 1;
							data = (uint16_t *)pch->buffer[idx];
							oft = 0;
						}
					}
				} else {
					uint32_t *data = (uint32_t *)pch->buffer[idx];
					for (int ii = 0; ii < I2S_TX_FIFO_TL; ii++) {
						if (pch->type == I2S_MONO) {
							i2s_chx_ltx_data(base, *data);
							i2s_chx_rtx_data(base, *data++);
							oft += 1;
						} else {
							i2s_chx_ltx_data(base, *data++);
							i2s_chx_rtx_data(base, *data++);
							oft += 2;
						}

						if (oft >= pch->buffer_len) {
							if ((pch->dir == I2S_DIR_TX) && pch->callback)
								pch->callback(pch->arg, idx, I2S_ERR_OK);

							idx ^= 1;
							data = (uint32_t *)pch->buffer[idx];
							oft = 0;
						}
					}
				}
				pch->buffer_idx = idx;
				pch->buffer_oft = oft;
			}
						
			if (status & I2S_CHx_IT_TXFO) {
//PRINTD(DBG_TRACE, "I2S: TXFO\r\n");
				i2s_chx_tov_clr(base);		
				if ((pch->dir == I2S_DIR_TX) && pch->callback)
					pch->callback(pch->arg, pch->buffer_idx, I2S_ERR_TX_OV);
			}
		}
	}
}

__irq void I2S_Master_Handler(void)
{
	for (int i = 0; i < CFG_NB_I2S; i++)  {
		if (i2s_dev[i].id == MI2S_ID) {
			i2s_isr(&i2s_dev[i]);
			break;
		}
	}
}

__irq void I2S_Slave_Handler(void)
{
	for (int i = 0; i < CFG_NB_I2S; i++)  {
		if (i2s_dev[i].id == SI2S_ID) {
			i2s_isr(&i2s_dev[i]);
			break;
		}
	}

}

/*
 * APIs
 ****************************************************************************************
 */

void *hal_i2s_open(int id, int sr, int word_sz) 
{
	i2s_dev_t* pd = NULL;

	for (int i = 0; i < CFG_NB_I2S; i++) {
		if ((i2s_dev[i].id == id) && (!i2s_dev[i].used)) {
			pd = &i2s_dev[i];
			break;
		}
	}

	if(!pd)
		return NULL;

	osMutexDef_t def;
	def.mutex = pd->mu;
	pd->h_mu = osMutexCreate(&def);
	if (!pd->h_mu) {
		return NULL;
	}

	/// Pins check
	if (!i2s_pin_chk(pd))
		return NULL;

	/// Clock 
	hal_clk_i2s_en(id, 1);

	/// Disable it
	i2s_disable(pd->base);
	i2s_rx_disable(pd->base);	
	i2s_tx_disable(pd->base);	
	i2s_rx_fifo_reset(pd->base);
	i2s_tx_fifo_reset(pd->base);

	if (id == MI2S_ID) {
		/// Master serial clock; sample rate * word size * left & right channel 
		uint32_t serial_clk = sr * word_sz * 2;		
		hal_clk_mi2s_set(serial_clk);
	}

	if (id == SI2S_ID) {
		/// Slave serial clock
		hal_clk_si2s_set(CFG_SI2S_CLK_MUX);
	}

	/// Word size
	if (word_sz == 16)
		pd->wss = I2S_CCR_WSS_16;
	else if (word_sz == 24)
		pd->wss = I2S_CCR_WSS_24;
	else
		pd->wss = I2S_CCR_WSS_32;
	i2s_sclk_wss(pd->base, pd->wss);

	/// sclk output 
	if (id == MI2S_ID)
		i2s_sclk_enable(pd->base);

	/// Enable it
	i2s_rx_enable(pd->base);
	i2s_tx_enable(pd->base);
	i2s_enable(pd->base);	

	/// Pins enable
	i2s_pin_mux_en(pd, 1);

#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
	pd->pmd.arg = (void *)pd;
	pd->pmd.power_state = i2s_pm_state;
	pd->pmd.power_down = i2s_pm_down;
	pd->pmd.power_up = i2s_pm_up;
	hal_pm_reg_mod(&pd->pmd);
#endif	/* CFG_PM_ENABLE */

	pd->used = 1;

	return (void *)pd;
}

int hal_i2s_close(void *hdl) 
{
	i2s_dev_t *pd = (i2s_dev_t *)hdl;

	if (pd == NULL)
		return I2S_ERR_INVALID_PARAM;

	if (!pd->used)
		return I2S_ERR_INVALID_PARAM;

	pd->used = 0;

	osMutexDelete(pd->h_mu);

	/// disable controller
	i2s_rx_disable(pd->base);	
	i2s_tx_disable(pd->base);	
	i2s_disable(pd->base);

	/// Clk 
	hal_clk_i2s_en(pd->id, 0);

	/// Pins
	i2s_pin_mux_en(pd, 0);

#if CFG_PM_ENABLE
	hal_pm_unreg_mod(&pd->pmd);
#endif	/* CFG_PM_ENABLE */

	return I2S_ERR_OK;
}

int hal_i2s_ch_en(void *hdl, int ch_id, int dir, int ch_word_sz, int type, void *buffer0, void *buffer1, uint16_t buffer_len, void *arg, void (*callback)(void * arg, int id, int status) )
{
	i2s_dev_t *pd = (i2s_dev_t *)hdl;
	i2s_ch_t *pch = NULL;
	uint32_t base;

	if (pd == NULL)
		return I2S_ERR_INVALID_PARAM;

	if (!pd->used)
		return I2S_ERR_INVALID_STATE;

	if (ch_id >= I2S_CH_MAX)	
		return I2S_ERR_INVALID_PARAM;

	if ((pd->id == SI2S_ID) && (ch_id == I2S_CH_2))
		return I2S_ERR_INVALID_PARAM;

	pch = &pd->ch[ch_id];
	if (pch->used) 
		return I2S_ERR_INVALID_STATE;

	osMutexWait(pd->h_mu, osWaitForever);

	pch->used = 1;
	pch->dir = dir;
	pch->ch_ws = ch_word_sz;
	pch->type = type;

	base = pch->base;
	/// Disable channel
	i2s_chx_tx_disable(base);
	i2s_chx_rx_disable(base);
	if (dir == I2S_DIR_RX) {
		i2s_chx_rfifo_flush(base);
		i2s_chx_rx_wlen(base, ch_word_sz);
		i2s_chx_rfifo_tl(base, I2S_RX_FIFO_TL);
		i2s_chx_rx_enable(base);
		i2s_sd_oe(pd->id, ch_id, 0);	 
		//i2s_rx_enable(pd->base);		
	} else {
		i2s_chx_tfifo_flush(base);
		i2s_chx_tx_wlen(base, ch_word_sz);
		i2s_chx_tfifo_tl(base, I2S_TX_FIFO_TL);
		i2s_chx_tx_enable(base);	
		//i2s_tx_enable(pd->base);		
		i2s_sd_oe(pd->id, ch_id, 1);
	}

	if (buffer0 && buffer1 && buffer_len) {
		pch->buffer_idx = 0;
		pch->buffer_oft = 0;
		pch->buffer[0] = buffer0;
		pch->buffer[1] = buffer1;
		pch->buffer_len = buffer_len;
		pch->arg = arg;
		pch->callback = callback;

		/// Unmask interrupt to let isr handle it
		if (dir == I2S_DIR_RX) {
			i2s_chx_intr_unmask(base, I2S_CHx_IT_RXDA|I2S_CHx_IT_RXFO);
		} else {
			i2s_chx_intr_unmask(base, I2S_CHx_IT_TXFE|I2S_CHx_IT_TXFO);
		}
		NVIC_SetPriority(pd->irq, IRQ_PRI_Highest);	
		NVIC_EnableIRQ(pd->irq);
	}

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return I2S_ERR_OK;
}

int hal_i2s_ch_dis(void *hdl, int ch_id)
{
	i2s_dev_t *pd = (i2s_dev_t *)hdl;
	i2s_ch_t *pch;
	uint32_t base;
	int res = I2S_ERR_OK;

	if (pd == NULL)
		return I2S_ERR_INVALID_PARAM;

	if (!pd->used)
		return I2S_ERR_INVALID_PARAM;

	if (ch_id >= I2S_CH_MAX)	
		return I2S_ERR_INVALID_PARAM;

	pch = &pd->ch[ch_id];
	if (!pch->used) 
		return I2S_ERR_INVALID_STATE;

	osMutexWait(pd->h_mu, osWaitForever);

	base = pch->base;
	if (pch->dir == I2S_DIR_RX) {
		i2s_chx_rx_disable(base);													
		i2s_chx_intr_mask(base, I2S_CHx_IT_RXDA|I2S_CHx_IT_RXFO);
	} else {
		i2s_chx_tx_disable(base);	
		i2s_chx_intr_mask(base, I2S_CHx_IT_TXFE|I2S_CHx_IT_TXFO);
		i2s_sd_oe(pd->id, ch_id, 0);	 
	}

	pch->used = 0;

#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif
	
	osMutexRelease(pd->h_mu);
	
	return res;
}
#endif 	// CFG_NB_I2S

