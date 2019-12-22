#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_i2s.c
 *
 * @brief Platform I2s Driver  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
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
#include ".\hal\hal_dma.h"

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
	char pad[1];

	uint32_t base;

	void *buffer[2];
	uint16_t buffer_len;
	uint16_t pad1;

	void *arg;
	void (*callback)(void *arg, int id, int status) ;	

	void *h_dma;
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

	uint32_t mu[4];
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
static void i2s_isr(i2s_ch_t *pch)
{
	if (pch->used) {

		uint32_t status = i2s_chx_intr_status(pch->base);

		if (status & I2S_CHx_IT_RXFO) {
//PRINTD(DBG_TRACE, "I2S: RXFO\r\n");
			i2s_chx_rov_clr(pch->base);
		}

		if (status & I2S_CHx_IT_RXDA) {
			// RX FIFO full, ask dma to transfer data out of RX FIFO 
			hal_dma_src_req(pch->h_dma);
			
			// Don't want interrupt while DMA moving data
			i2s_chx_intr_mask(pch->base, I2S_CHx_IT_RXDA);
		}

		if (status & I2S_CHx_IT_TXFE) {
//PRINTD(DBG_TRACE, "1");

			// TX FIFO empty, ask dma to transfer data from memory to TX FIFO 
			hal_dma_dst_req(pch->h_dma);

			// Don't want interrupt while DMA moving data
			i2s_chx_intr_mask(pch->base, I2S_CHx_IT_TXFE);
		}
						
		if (status & I2S_CHx_IT_TXFO) {
//PRINTD(DBG_TRACE, "I2S: TXFO\r\n");
			i2s_chx_tov_clr(pch->base);		
		}
	}

}

__irq void I2S_Master_Handler(void)
{
	i2s_dev_t *pd = &i2s_dev[0];

	for (int i = 0; i < I2S_CH_MAX; i++) {
		i2s_isr(&pd->ch[i]);
	}
}

__irq void I2S_Slave_Handler(void)
{
#if CFG_MI2S_EN
	i2s_dev_t *pd = &i2s_dev[1];
#else
	i2s_dev_t *pd = &i2s_dev[0];
#endif

	for (int i = 0; i < I2S_CH_MAX; i++) {
		i2s_isr(&pd->ch[i]);
	}
}

/*
 * DMA ISR Callback
 ****************************************************************************************
 */
void i2s_dma_isr_cb(int id, void *arg,  int status)
{
	i2s_ch_t *pch = (i2s_ch_t *) arg;

	if (status & DMA_IT_STATUS_SRCT) {
		// Data move from i2s RX to the memory completed, 
		// Enable RX full interrupt
		i2s_chx_intr_unmask(pch->base, I2S_CHx_IT_RXDA);
	}

	if (status & DMA_IT_STATUS_DSTT) {
		// Data move from memory to the i2s TX completed, 
		// Enable TX empty interrupt
		i2s_chx_intr_unmask(pch->base, I2S_CHx_IT_TXFE);

	}

	if (status & DMA_IT_STATUS_TFR) {
		// Current user's buffer completed
		// Switch buffer
		int sa_da = (pch->dir == I2S_DIR_RX) ? 0 : 1;
		int idx = pch->buffer_idx ^ 1;
		hal_dma_switch_buffer(pch->h_dma, sa_da,  (uint32_t)pch->buffer[idx]);

		// call back to user 
		int res = I2S_ERR_OK;
		if (status & DMA_IT_STATUS_ERR)
			res = I2S_ERR_DMA_TRAN;

		if (pch->callback) {
			pch->callback(pch->arg, pch->buffer_idx, res);
		}

		pch->buffer_idx = idx;
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

	/// disable channel
	i2s_chx_rx_disable(pd->ch[0].base);
	i2s_chx_rx_disable(pd->ch[1].base);
	i2s_chx_tx_disable(pd->ch[0].base);
	i2s_chx_tx_disable(pd->ch[1].base);

	/// Enable block
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

int hal_i2s_ch_en(void *hdl, int ch_id, int dir, int ch_word_sz, void *buffer0, void *buffer1, uint16_t buffer_len, void *arg, void (*callback)(void * arg, int id, int status) )
{
	i2s_dev_t *pd = (i2s_dev_t *)hdl;
	i2s_ch_t *pch = NULL;
	uint32_t ch_base;
	int res = I2S_ERR_OK;

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

	// i2s use dma; otherwise it will not work
	int tr_width;

	if (ch_word_sz <= I2S_CH_WS_16_BITS) {
		tr_width = DMA_CTL_TR_WIDTH_16BITS;
	} else if (ch_word_sz <= I2S_CH_WS_32_BITS) {
		tr_width = DMA_CTL_TR_WIDTH_32BITS;
	} else {
		res = I2S_ERR_INVALID_PARAM;
		goto out;
	}

	if (dir == I2S_DIR_RX) {
		for (int i = 0; i < 2; i++) {
			pch->h_dma = hal_dma_soft_open(i,	// DMA Id 
																	(pd->base + I2S_REG_RXDMA_OFS),  	// Source Address
																		(uint32_t)buffer0,  							// Destination Address
																			buffer_len, 									// Total buffer length 
																				tr_width, tr_width,						// Single transfer size
																					DMA_ADDR_SAME, DMA_ADDR_INC, 	// Address 
																						DMA_CTL_TR_MSIZE_8, DMA_CTL_TR_MSIZE_8, 	// Burst transfer size (left and right together)
																							DMA_AHB_MASTER_PERIPH, DMA_AHB_MASTER_MEM, // AHB master
																								DMA_TT_PERF_TO_MEM_FC_DMAC);	// Transfer control
			if (pch->h_dma)
				break;
		}

	} else {
		for (int i = 0; i < 2; i++) {
			pch->h_dma = hal_dma_soft_open(i,	// DMA Id 
																	(uint32_t)buffer0,  									// Source Address
																		(pd->base + I2S_REG_TXDMA_OFS),	// Destination Address
																			buffer_len, 										// Total buffer length 
																				tr_width, tr_width,							// Single transfer size
																					DMA_ADDR_INC, DMA_ADDR_SAME, 	// Address 
																						DMA_CTL_TR_MSIZE_8, DMA_CTL_TR_MSIZE_8, 	// Burst transfer size (left and right together)
																							DMA_AHB_MASTER_MEM, DMA_AHB_MASTER_PERIPH, // AHB master
																								DMA_TT_MEM_TO_PERF_FC_DMAC);	// Transfer control
			if (pch->h_dma)
				break;
		}
	}

	if (pch->h_dma) {
		hal_dma_soft_ch_enable(pch->h_dma, (void *)pch, i2s_dma_isr_cb);
	}else {
		res = I2S_ERR_DMA_NOT_AVAIL;
		goto out;
	}	   

	pch->used = 1;
	pch->dir = dir;

	ch_base = pch->base;
	/// Disable channel
	i2s_chx_tx_disable(ch_base);
	i2s_chx_rx_disable(ch_base);
	if (dir == I2S_DIR_RX) {
		i2s_chx_rfifo_flush(ch_base);
		i2s_chx_rx_wlen(ch_base, ch_word_sz);
		i2s_chx_rfifo_tl(ch_base, (I2S_RX_FIFO_TL-1));
		i2s_chx_rx_enable(ch_base);
		i2s_sd_oe(pd->id, ch_id, 0);	 
		//i2s_rx_enable(pd->base);		
	} else {
		i2s_chx_tfifo_flush(ch_base);
		i2s_chx_tx_wlen(ch_base, ch_word_sz);
		i2s_chx_tfifo_tl(ch_base, (I2S_TX_FIFO_TL-1));
		i2s_chx_tx_enable(ch_base);	
		//i2s_tx_enable(pd->base);		
		i2s_sd_oe(pd->id, ch_id, 1);
	}

	pch->buffer_idx = 0;
	pch->buffer[0] = buffer0;
	pch->buffer[1] = buffer1;
	pch->buffer_len = buffer_len;
	pch->arg = arg;
	pch->callback = callback;

	/// Unmask interrupt to let dma handle it
	if (dir == I2S_DIR_RX) {
		i2s_chx_intr_unmask(ch_base, I2S_CHx_IT_RXDA|I2S_CHx_IT_RXFO);
	} else {
		i2s_chx_intr_unmask(ch_base, I2S_CHx_IT_TXFE|I2S_CHx_IT_TXFO);
	}
	NVIC_SetPriority(pd->irq, IRQ_PRI_Normal);	
	NVIC_EnableIRQ(pd->irq);

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif

out:
	osMutexRelease(pd->h_mu);
	return res;
}

int hal_i2s_ch_dis(void *hdl, int ch_id)
{
	i2s_dev_t *pd = (i2s_dev_t *)hdl;
	i2s_ch_t *pch;
	uint32_t ch_base;
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

	if (pch->h_dma) {
		hal_dma_ch_disable(pch->h_dma);
		hal_dma_close(pch->h_dma);	
	}

	ch_base = pch->base;
	if (pch->dir == I2S_DIR_RX) {
		i2s_chx_rx_disable(ch_base);													
		i2s_chx_intr_mask(ch_base, I2S_CHx_IT_RXDA|I2S_CHx_IT_RXFO);
	} else {
		i2s_chx_tx_disable(ch_base);	
		i2s_chx_intr_mask(ch_base, I2S_CHx_IT_TXFE|I2S_CHx_IT_TXFO);
		i2s_sd_oe(pd->id, ch_id, 0);	 
	}
	NVIC_DisableIRQ(pd->irq);

	pch->used = 0;

#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif
	
	osMutexRelease(pd->h_mu);
	
	return res;
}

#endif 	// CFG_NB_I2S

