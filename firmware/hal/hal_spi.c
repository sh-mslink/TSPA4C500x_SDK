#include "in_config.h"

#define CFG_NB_SPI (CFG_MSPI_EN+CFG_SSPI_EN)

/**
 ****************************************************************************************
 *
 * @file hal_spi.c
 *
 * @brief SPI driver implementation file  
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

#include ".\hal\hal_spi.h"
#include ".\hal\hal_icache.h"
#include ".\hal\hal_dma.h"

#if CFG_PM_EN
#include ".\hal\hal_power.h"
#endif

#include "cmsis_os.h"

/*
 * Defines
 ****************************************************************************************
 */

#define SPI_FIFO_DEPTH		8
#define SPI_TX_TL	4
#define SPI_RX_TL	4

#if CFG_NB_SPI
/*
 * Structures
 ****************************************************************************************
 */

typedef struct {
	char id;
	char used;
	char dfs;
	char pad;

	int error;
	uint32_t base;
	IRQn_Type irq;

	uint32_t clk_pin;
	uint32_t ssn_pin;
	uint32_t mosi_pin;
	uint32_t miso_pin;

	uint32_t mu[4];
	osMutexId h_mu;
	uint32_t sma[2];
	osSemaphoreId h_sma;

	void *txbuf;
	uint16_t txbuf_len;
	uint16_t txbuf_ofs;

	void *rxbuf;
	uint16_t rxbuf_len;
	uint16_t rxbuf_ofs;

	char slv_stop;
#if CFG_PM_EN
	int pm_state;
	struct pm_module pmd;
#endif

} spi_dev_t;

static spi_dev_t spi_dev[CFG_NB_SPI] = {
#if CFG_MSPI_EN
	{
		.id = MSPI_ID, 
		.used = 0,
		.base = MSPI_BASE,  
		.irq = MSpi_IRQn,

	}, 
#endif
#if CFG_SSPI_EN
	{
		.id = SSPI_ID, 
		.used = 0,
		.base = SSPI_BASE,
		.irq = SSpi_IRQn,
	},
#endif
};

/*
 * Static Functions
 ****************************************************************************************
 */
static void spi_finish(spi_dev_t *pd)
{
	int poll_count = 0; 										

	// Done, wait for not busy
	while(1) {
		uint32_t status = spi_sr(pd->base);
		if ((status & SPI_SR_TFE) && !(status & SPI_SR_BUSY))
			break;
		osDelay(1);
		poll_count += 1;
		if (poll_count > 5) {
			pd->error = SPI_ERR_RESET;
			break;
		}	
	}
	spi_disable(pd->base);		

	if (pd->error == SPI_ERR_RESET) {
		spi_reset(pd->id);
	}
}

/*
 * PIN Mux
 ****************************************************************************************
 */

static void spi_pin_mux_en(spi_dev_t *pd, int en)
{
	if (en) {
		hal_gpio_pin_cfg(pd->clk_pin);
		hal_gpio_pin_cfg(pd->miso_pin);
		hal_gpio_pin_cfg(pd->mosi_pin);
		hal_gpio_pin_cfg(pd->ssn_pin);
	} else {
		hal_gpio_pin_dft(pd->clk_pin);
		hal_gpio_pin_dft(pd->miso_pin);
		hal_gpio_pin_dft(pd->mosi_pin);
		hal_gpio_pin_dft(pd->ssn_pin);
	}
}

static int spi_pin_chk(spi_dev_t *pd)
{
	if (pd->id == MSPI_ID) {

		/// GPIO_3_4 = mstr_clk
		/// GPIO_3_5 = mstr_miso
		/// GPIO_4_0 = mstr_mosi
		/// GPIO_4_1 = mstr_ssn0
		/// GPIO_0_1 = mstr_miso_bkup
		/// GPIO_0_3 = mstr_mosi_bkup
		/// GPIO_0_4 = mstr_clk_bkup
		/// GPIO_3_3 = mstr_ssn3

		/// Sanity check

		/// CLK pin
		if (((CFG_GPIO_3_4 >> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_SPI_MSTR_CLK) 
			pd->clk_pin = CFG_GPIO_3_4;
		else
			pd->clk_pin = 0;

		if (((CFG_GPIO_0_4 >> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_SPI_CLK_BKUP) { 
			if (pd->clk_pin == 0)
				pd->clk_pin = CFG_GPIO_0_4;
			else
				return 0;
		} else {
			if (pd->clk_pin == 0)
				return 0;
		}
		
		/// MISO pin
		if (((CFG_GPIO_3_5 >> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_SPI_MSTR_MISO1) 
			pd->miso_pin = CFG_GPIO_3_5;
		else
			pd->miso_pin = 0;

		if (((CFG_GPIO_0_1 >> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_SPI_MSTR_MISO_BKUP1) { 
			if (pd->miso_pin == 0)
				pd->miso_pin = CFG_GPIO_0_1;
			else
				return 0;
		} else {
			if (pd->miso_pin == 0)
				return 0;
		}

		/// MOSI pin
		if (((CFG_GPIO_4_0 >> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_SPI_MSTR_MOSI) 
			pd->mosi_pin = CFG_GPIO_4_0;
		else
			pd->mosi_pin = 0;

		if (((CFG_GPIO_0_3 >> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_SPI_MSTR_MOSI_BKUP) {
			if (pd->mosi_pin == 0)
				pd->mosi_pin = CFG_GPIO_0_3;
			else
				pd->mosi_pin = 0;
		} else {
			if (pd->mosi_pin == 0)
				return 0;
		}	

		/// SSN pin
		if (((CFG_GPIO_4_1 >> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_SPI_MSTR_SSN0) 
			pd->ssn_pin = 	CFG_GPIO_4_1;
		else
			pd->ssn_pin = 	0;

		if (((CFG_GPIO_2_1 >> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_SPI_MSTR_SSN0_BKUP) 
			if (pd->ssn_pin == 0)
				pd->ssn_pin = 	CFG_GPIO_2_1;
		else
			pd->ssn_pin = 	0;

		if (((CFG_GPIO_3_2 >> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_SPI_MSTR_SSN3_BKUP) 
			if (pd->ssn_pin == 0)
				pd->ssn_pin = 	CFG_GPIO_3_2;
		else
			pd->ssn_pin = 	0;

		if (((CFG_GPIO_3_3 >> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_SPI_MSTR_SSN3) {
			if (pd->ssn_pin == 0)
				pd->ssn_pin = CFG_GPIO_3_3;
			else
				return 0;
		} else {
			if (pd->ssn_pin == 0)
				return 0;
		}
	}

	if (pd->id == SSPI_ID) {

		/// GPIO_3_4 = slv_clk
		/// GPIO_3_5 = slv_miso
		/// GPIO_3_6 = slv_mosi
		/// GPIO_3_7 = slv_ssn

		/// Sanity check
		if (((CFG_GPIO_3_4 >> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_SPI_SLV_CLK) 
			pd->clk_pin = CFG_GPIO_3_4;
		else
			return 0;

		if (((CFG_GPIO_3_5 >> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_SPI_SLV_MISO) 
			pd->miso_pin = CFG_GPIO_3_5;
		else
			return 0;

		if (((CFG_GPIO_4_0 >> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_SPI_SLV_MOSI1) 
			pd->mosi_pin = CFG_GPIO_4_0;
		else
			return 0;

		if (((CFG_GPIO_4_1 >> GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_SPI_SLV_SSN1) 
			pd->ssn_pin = CFG_GPIO_4_1;
		else
			return 0;
	}

	return 1;
}

/*
 * PM
 ****************************************************************************************
 */
#if CFG_PM_EN
static int spi_pm_state(void *arg, uint32_t *sleep_duration)
{
	spi_dev_t *pd = (spi_dev_t *)arg;

	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->pm_state;
}

static void spi_pm_down(void *arg, uint32_t sleep_duration)
{
	return;
}

static void spi_pm_up(void *arg)
{
	//spi_dev_t *pd = (spi_dev_t *)arg;

	//spi_pin_mux_en(pd, 1);
}
#endif

/*
 * ISR
 ****************************************************************************************
 */
static void spi_isr(spi_dev_t *pd)
{
	uint32_t status = spi_intr_status(pd->base);

	// RX fifo full
	if (status & SPI_IT_RXF) {
		uint32_t ofs = pd->rxbuf_ofs;
		uint32_t rxfl = spi_rxfl(pd->base); 

		// Read the FIFO
		if (pd->dfs <= SPI_DFS_8_BITS) {
			uint8_t *buf = (uint8_t *)pd->rxbuf;
			for (int i = 0; i < rxfl; i++) {
				buf[ofs++] = (uint8_t)spi_dr_read(pd->base);
				if (ofs >= pd->rxbuf_len)
					break;								
			}
		} else if (pd->dfs <= SPI_DFS_16_BITS) {
			uint16_t *buf = (uint16_t *)pd->rxbuf;
			for (int i = 0; i < rxfl; i++) {
				buf[ofs++] = (uint16_t)spi_dr_read(pd->base);
				if (ofs >= pd->rxbuf_len)
					break;								
			}
		} else {
			uint32_t *buf = (uint32_t *)pd->rxbuf;
			for (int i = 0; i < rxfl; i++) {
				buf[ofs++] = spi_dr_read(pd->base);
				if (ofs >= pd->rxbuf_len)
					break;								
			}
		}		
		pd->rxbuf_ofs = ofs;

		if (pd->rxbuf_ofs >= pd->rxbuf_len) {	
			// we are done...
			spi_intr_mask(pd->base, SPI_IT_RXF|SPI_IT_RXO|SPI_IT_RXU);
			pd->slv_stop = 1;
			osSemaphoreRelease(pd->h_sma);
		} else {
			// Handle left over
			int n_tl = pd->rxbuf_len - pd->rxbuf_ofs;
			if (n_tl < SPI_RX_TL)
				spi_rxftl(pd->base, (n_tl-1));
		}	
	}

	// RX overflow 
	if (status & SPI_IT_RXO) {	
		/// Clear
		spi_intr_rxo_clr(pd->base);	

		spi_intr_mask(pd->base, SPI_IT_RXF|SPI_IT_RXO|SPI_IT_RXU);
		pd->error = SPI_ERR_RX_OV;
		pd->slv_stop = 1;
		osSemaphoreRelease(pd->h_sma);
	}

	// RX underflow 
	if (status & SPI_IT_RXU) {	
		// Clear
		spi_intr_rxu_clr(pd->base);	

		spi_intr_mask(pd->base, SPI_IT_RXF|SPI_IT_RXO|SPI_IT_RXU);
		pd->error = SPI_ERR_RX_UN;
		pd->slv_stop = 1;
		osSemaphoreRelease(pd->h_sma);
	}

	// TX overflow
	if (status & SPI_IT_TXO) {
		spi_intr_txo_clr(pd->base);		

		spi_intr_mask(pd->base, SPI_IT_TXE);
		pd->error = SPI_ERR_TX_OV;
		pd->slv_stop = 1;
		osSemaphoreRelease(pd->h_sma);
	}

	// TX empty
	if (status & SPI_IT_TXE) {
		if (pd->txbuf_ofs >= pd->txbuf_len) {
			spi_intr_mask(pd->base, SPI_IT_TXE|SPI_IT_TXO);

			if (!pd->rxbuf) {	// Not a TRX 
				pd->slv_stop = 1;
				osSemaphoreRelease(pd->h_sma);
			}
		} else {
			uint32_t ofs = pd->txbuf_ofs;

			// Fill the FIFO
			if (pd->dfs <= SPI_DFS_8_BITS) {
				uint8_t *buf = (uint8_t *)pd->txbuf;
				for (int i = 0; i < SPI_TX_TL; i++) {
					spi_dr_write(pd->base, buf[ofs++]);
					if (ofs >= pd->txbuf_len)
						break;
				}
			} else if (pd->dfs <= SPI_DFS_16_BITS) {
				uint16_t *buf = (uint16_t *)pd->txbuf;
				for (int i = 0; i < SPI_TX_TL; i++) {
					spi_dr_write(pd->base, buf[ofs++]);
					if (ofs >= pd->txbuf_len)
						break;
				}
			} else {
				uint32_t *buf = (uint32_t *)pd->txbuf;
				for (int i = 0; i < SPI_TX_TL; i++) {
					spi_dr_write(pd->base, buf[ofs++]);
					if (ofs >= pd->txbuf_len)
						break;
				}
			}
			pd->txbuf_ofs = ofs;

			int n_tl = pd->txbuf_len - pd->txbuf_ofs;
			if (n_tl < SPI_TX_TL)
				spi_txftl(pd->base, n_tl);
		}
	}
}

__irq void MSPI_Handler(void)
{
	for (int i = 0; i < CFG_NB_SPI; i++)  {
		if (spi_dev[i].id == MSPI_ID) {
			spi_isr(&spi_dev[i]);
			break;
		}
	}
}

__irq void SSPI_Handler(void)
{

	for (int i = 0; i < CFG_NB_SPI; i++)  {
		if (spi_dev[i].id == SSPI_ID) {
			spi_isr(&spi_dev[i]);
			break;
		}
	}
}

/*
 * DMA ISR Callback
 ****************************************************************************************
 */
void spi_dma_isr_cb(int id, void *arg,  int status)
{
	spi_dev_t *pd = (spi_dev_t *)arg;

	if (status & DMA_IT_STATUS_ERR)
		pd->error = SPI_ERR_DMA_ERROR;

	osSemaphoreRelease(pd->h_sma);
}

/*
 * SPI APIs
 ****************************************************************************************
 */

void *hal_spi_open(int id)
{
	spi_dev_t *pd = NULL;

	// Find ID
	for (uint32_t i = 0; i < CFG_NB_SPI; i++) {
		if (spi_dev[i].id == id) {
			if (!spi_dev[i].used) {
				pd = &spi_dev[i];
			} 
		}
	}

	if (!pd)
		return NULL;

	/// Pins check
	if (!spi_pin_chk(pd))
		return NULL;

	// OS
	{
		osMutexDef_t def;
		def.mutex = pd->mu;
		pd->h_mu = osMutexCreate(&def);
		if (!pd->h_mu) {
			return NULL;
		}
	}
	{
		osSemaphoreDef_t def;
		def.semaphore = pd->sma;
		pd->h_sma = osSemaphoreCreate(&def, 0);
		if (!pd->h_sma) {
			goto fail;
		}
	}


	/// Turn on SPI clock
	if (id == MSPI_ID)
		hal_clk_mspi_en(1);
	else 
		hal_clk_sspi_en(1);

	/// enable pin
	spi_pin_mux_en(pd, 1);

#if CFG_PM_EN
	pd->pm_state = PM_DEEP_SLEEP;
	pd->pmd.arg = (void *)pd;
	pd->pmd.power_state = spi_pm_state;
	pd->pmd.power_down = spi_pm_down;
	pd->pmd.power_up = spi_pm_up;
	hal_pm_reg_mod(&pd->pmd);
#endif

	pd->used = 1;
	return (void *)pd;

fail:

	if (pd->h_mu) {
		osMutexDelete(pd->h_mu);
		pd->h_mu = NULL;
	} 

	if (pd->h_sma) {
		osSemaphoreDelete(pd->h_sma);
		pd->h_sma = NULL;
	} 

	return NULL;
}

int hal_spi_close(void *hdl)
{
	spi_dev_t *pd = (spi_dev_t *)hdl;

	if (!pd)
		return SPI_ERR_INVALID_PARAM;

	if (!pd->used)
		return SPI_ERR_INVALID_OPER;

	osMutexWait(pd->h_mu, osWaitForever);

	pd->used = 0;

	/// Disable SPI
	while(1) {
		uint32_t status = spi_sr(pd->base);
		if ((status & SPI_SR_TFE) && !(status & SPI_SR_BUSY))
			break;
	}
	spi_disable(pd->base);		

	osMutexRelease(pd->h_mu);

	// OS release
	osMutexDelete(pd->h_mu);
	pd->h_mu = NULL;
	osSemaphoreDelete(pd->h_sma);
	pd->h_sma = NULL;

	// Pin mux off
	spi_pin_mux_en(pd, 0);

	// Turn off SPI clock
	if (pd->id == MSPI_ID)
		hal_clk_mspi_en(0);
	else 
		hal_clk_sspi_en(0);

#if CFG_PM_EN
	hal_pm_unreg_mod(&pd->pmd);
#endif		

	return SPI_ERR_OK;
}

int hal_spi_tx(void *hdl, int cs, int speed, int phase, int polarity, int dfs, void *buffer, uint16_t buffer_len)
{
	spi_dev_t *pd = (spi_dev_t *)hdl;

	if (!pd)
		return SPI_ERR_INVALID_PARAM;	
	
	if (!pd->used)
		return SPI_ERR_INVALID_OPER;

	if (!buffer)
		return SPI_ERR_INVALID_PARAM;	

	if (buffer_len == 0)
		return SPI_ERR_INVALID_PARAM;	

	if (cs == 1)
		cs = 3;

	osMutexWait(pd->h_mu, osWaitForever);

	// Configure SPI	
	spi_disable(pd->base);
	spi_ctl0(pd->base, SPI_STD_FMT, SPI_TMOD_TX_ONLY, dfs, phase, polarity);
	if (pd->id == MSPI_ID) {
		spi_baud_rate(pd->base, hal_clk_d0_get(), speed); 
		spi_ser(pd->base, 0, cs);
	}
	spi_intr_clr(pd->base);
	spi_intr_mask(pd->base, SPI_IT_ALL);
	int tx_tl;
	if (buffer_len < SPI_TX_TL)
		tx_tl = buffer_len;
	else
		tx_tl = SPI_TX_TL;
	spi_txftl(pd->base, tx_tl);
	spi_enable(pd->base);	

	pd->dfs = dfs;

	pd->rxbuf = NULL;
	pd->rxbuf_len = 0;
	pd->rxbuf_ofs = 0;

	pd->txbuf = buffer;
	pd->txbuf_len = buffer_len;
	pd->txbuf_ofs = 0;
	pd->error = SPI_ERR_OK;

	// Unmask interrupt
	spi_intr_unmask(pd->base, SPI_IT_TXE|SPI_IT_TXO);
	NVIC_SetPriority(pd->irq, IRQ_PRI_High);	
	NVIC_EnableIRQ(pd->irq);

	// Select Slave...Start transfer
	if (pd->id == MSPI_ID) 
		spi_ser(pd->base, 1, cs);

#if CFG_PM_EN
	pd->pm_state = PM_SLEEP;
#endif

	osSemaphoreWait(pd->h_sma, osWaitForever);

	// Disable interrupt
	spi_intr_mask(pd->base, SPI_IT_TXE|SPI_IT_TXO);
	NVIC_DisableIRQ(pd->irq);

	// Done, disable SPI
	spi_finish(pd);

#if CFG_PM_EN
	pd->pm_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}

int hal_spi_rx(void *hdl, int cs, int speed, int phase, int polarity, int dfs, void *buffer, uint16_t buffer_len)
{
	spi_dev_t *pd = (spi_dev_t *)hdl;

	if (!pd)
		return SPI_ERR_INVALID_PARAM;	

	if (!pd->used)
		return SPI_ERR_INVALID_OPER;

	if (!buffer)
		return SPI_ERR_INVALID_PARAM;	

	if (buffer_len == 0)
		return SPI_ERR_INVALID_PARAM;	

	if (cs == 1)
		cs = 3;

	osMutexWait(pd->h_mu, osWaitForever);

	// Configure SPI		
	spi_disable(pd->base);
	spi_ctl0(pd->base, SPI_STD_FMT, SPI_TMOD_RX_ONLY, dfs, phase, polarity);
	if (pd->id == MSPI_ID) {
		spi_baud_rate(pd->base, hal_clk_d0_get(), speed); 
		spi_ndf(pd->base, (buffer_len - 1));
		spi_ser(pd->base, 0, cs);
	}
	spi_intr_clr(pd->base);
	spi_intr_mask(pd->base, SPI_IT_ALL);
	int rx_tl;
	if (buffer_len < SPI_RX_TL)
		rx_tl = buffer_len;
	else
		rx_tl = SPI_RX_TL;
	spi_rxftl(pd->base, (rx_tl-1));
	spi_enable(pd->base);	

	pd->dfs = dfs;

	pd->rxbuf = buffer;
	pd->rxbuf_len = buffer_len;
	pd->rxbuf_ofs = 0;

	pd->txbuf = NULL;
	pd->txbuf_len = 0;
	pd->txbuf_ofs = 0;
	pd->error = SPI_ERR_OK;

	// Unmask interrupt
	spi_intr_unmask(pd->base, SPI_IT_RXU|SPI_IT_RXO|SPI_IT_RXF);
	NVIC_SetPriority(pd->irq, IRQ_PRI_High);	
	NVIC_EnableIRQ(pd->irq);

	/// Select Slave...Start transfer
	if (pd->id == MSPI_ID) {
		spi_dr_write(pd->base, 0);
		spi_ser(pd->base, 1, cs);
	}

#if CFG_PM_EN
	pd->pm_state = PM_SLEEP;
#endif

	osSemaphoreWait(pd->h_sma, osWaitForever);

	// Disable interrupt
	spi_intr_mask(pd->base, SPI_IT_RXU|SPI_IT_RXO|SPI_IT_RXF);
	NVIC_DisableIRQ(pd->irq);

	/// Done, disable SPI
	spi_finish(pd);

#if CFG_PM_EN
	pd->pm_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}

int hal_spi_trx(void *hdl, int cs, int speed, int phase, int polarity, int dfs, void *wbuf, void *rbuf, uint16_t buf_len)
{
	spi_dev_t *pd = (spi_dev_t *)hdl;

	if (!pd)
		return SPI_ERR_INVALID_PARAM;	

	if (!pd->used)
		return SPI_ERR_INVALID_OPER;

	if (!wbuf)
		return SPI_ERR_INVALID_PARAM;	

	if (!rbuf)
		return SPI_ERR_INVALID_PARAM;	

	if (buf_len == 0)
		return SPI_ERR_INVALID_PARAM;

	if (cs == 1)
		cs = 3;
	
	osMutexWait(pd->h_mu, osWaitForever);

	// Configure SPI		
	spi_disable(pd->base);
	spi_ctl0(pd->base, SPI_STD_FMT, SPI_TMOD_TX_AND_RX, dfs, phase, polarity);
	if (pd->id == MSPI_ID) {
		spi_baud_rate(pd->base, hal_clk_d0_get(), speed); 
		spi_ndf(pd->base, (buf_len - 1));
		spi_ser(pd->base, 0, cs);
	}
	spi_intr_clr(pd->base);
	spi_intr_mask(pd->base, SPI_IT_ALL);
	int tl;
	if (buf_len < SPI_RX_TL)
		tl = buf_len;
	else
		tl = SPI_RX_TL;
	spi_rxftl(pd->base, (tl-1));
	if (buf_len < SPI_TX_TL)
		tl = buf_len;
	else
		tl = SPI_TX_TL;
	spi_txftl(pd->base, tl);
	spi_enable(pd->base);	

	pd->dfs = dfs;

	pd->rxbuf = rbuf;
	pd->rxbuf_len = buf_len;
	pd->rxbuf_ofs = 0;

	pd->txbuf = wbuf;
	pd->txbuf_len = buf_len;
	pd->txbuf_ofs = 0;
	pd->error = SPI_ERR_OK;

	// Unmask interrupt
	spi_intr_unmask(pd->base, SPI_IT_ALL);
	NVIC_SetPriority(pd->irq, IRQ_PRI_High);	
	NVIC_EnableIRQ(pd->irq);

	/// Select Slave...Start transfer
	if (pd->id == MSPI_ID)
		spi_ser(pd->base, 1, cs);

#if CFG_PM_EN
	pd->pm_state = PM_SLEEP;
#endif

	osSemaphoreWait(pd->h_sma, osWaitForever);

	// Disable interrupt
	spi_intr_mask(pd->base, SPI_IT_ALL);
	NVIC_DisableIRQ(pd->irq);

	/// Done, disable SPI
	spi_finish(pd);

#if CFG_PM_EN
	pd->pm_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}

int hal_spi_tx_dma(void *h, int cs, int speed, int phase, int polarity, int dfs, void *buffer, uint16_t buffer_len)
{
	spi_dev_t *pd = (spi_dev_t *)h;
	void *h_dma = NULL;

	if (!pd)
		return SPI_ERR_INVALID_PARAM;	

	if (!buffer)
		return SPI_ERR_INVALID_PARAM;	

	if (buffer_len == 0)
		return SPI_ERR_INVALID_PARAM;	

	if (cs == 1)
		cs = 3;

	osMutexWait(pd->h_mu, osWaitForever);

	// Configure SPI	
	spi_disable(pd->base);
	spi_ctl0(pd->base, SPI_STD_FMT, SPI_TMOD_TX_ONLY, dfs, phase, polarity);
	if (pd->id == MSPI_ID) {
		spi_baud_rate(pd->base, hal_clk_d0_get(), speed); 
		spi_ser(pd->base, 0, cs);
	}
	spi_intr_clr(pd->base);
	spi_intr_mask(pd->base, SPI_IT_ALL);
	spi_enable(pd->base);	

	int tx_tl;
	if (pd->id == MSPI_ID) {
		if (buffer_len < SPI_TX_TL)
			tx_tl = buffer_len;
		else
			tx_tl = SPI_TX_TL;
	} else {
		tx_tl = 1;
	}

	// Configure DMA
	int tr_width, msize;
	if (dfs <= SPI_DFS_8_BITS) {
		tr_width = DMA_CTL_TR_WIDTH_8BITS;
	} else if (dfs <= SPI_DFS_16_BITS) {
		tr_width = DMA_CTL_TR_WIDTH_16BITS;
	} else {
		tr_width = DMA_CTL_TR_WIDTH_32BITS;
	}

	if (tx_tl < SPI_TX_TL)
		msize = DMA_CTL_TR_MSIZE_1;
	else
		msize = DMA_CTL_TR_MSIZE_4;

	h_dma = hal_dma_open(DMA0_ID, 
													((pd->id == MSPI_ID) ? DMA_ID_SPI1_TX : DMA_ID_SSPI_TX),
														(uint32_t)buffer, 
															(pd->base + SPI_REG_DR_OFS),  
																buffer_len, 
																	tr_width, tr_width,
																		DMA_ADDR_INC, DMA_ADDR_SAME, 
																			msize, msize, 
																				DMA_AHB_MASTER_MEM, DMA_AHB_MASTER_PERIPH, 
																					DMA_TT_MEM_TO_PERF_FC_DMAC);
	if (!h_dma) {
		pd->error = SPI_ERR_DMA_NOT_AVAIL;
		goto out;
	}	   
	hal_dma_ch_enable(h_dma, (void *)pd, spi_dma_isr_cb);
	pd->error = SPI_ERR_OK;
 	
	// Set TX request level and enable it
	spi_txdma_req_level(pd->base, tx_tl);
	spi_txdma_enable(pd->base);	

	// Select Slave...Start transfer
	if (pd->id == MSPI_ID) 
		spi_ser(pd->base, 1, cs);

#if CFG_PM_EN
	pd->pm_state = PM_SLEEP;
#endif

	osSemaphoreWait(pd->h_sma, osWaitForever);

out:

	// Disable SPI
	spi_finish(pd);

	// Disable DMA
	if (h_dma) {
		hal_dma_ch_disable(h_dma);
		hal_dma_close(h_dma);	

		spi_txdma_disable(pd->base);	
	}


#if CFG_PM_EN
	pd->pm_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}

int hal_spi_rx_dma(void *h, int cs, int speed, int phase, int polarity, int dfs, void *buffer, uint16_t buffer_len)
{
	spi_dev_t *pd = (spi_dev_t *)h;
	void *h_dma = NULL;

	if (!pd)
		return SPI_ERR_INVALID_PARAM;	

	if (!buffer)
		return SPI_ERR_INVALID_PARAM;	

	if (buffer_len == 0)
		return SPI_ERR_INVALID_PARAM;	

	if (cs == 1)
		cs = 3;

	osMutexWait(pd->h_mu, osWaitForever);

	// Configure SPI	
	spi_disable(pd->base);
	spi_ctl0(pd->base, SPI_STD_FMT, SPI_TMOD_RX_ONLY, dfs, phase, polarity);
	if (pd->id == MSPI_ID) {
		spi_baud_rate(pd->base, hal_clk_d0_get(), speed); 
		spi_ser(pd->base, 0, cs);
	}
	spi_intr_clr(pd->base);
	spi_intr_mask(pd->base, SPI_IT_ALL);
	spi_enable(pd->base);	

	int rx_tl;
	if (buffer_len < SPI_RX_TL)
		rx_tl = buffer_len;
	else
		rx_tl = SPI_RX_TL;

	// Configure DMA
	int tr_width, msize;
	if (dfs <= SPI_DFS_8_BITS) {
		tr_width = DMA_CTL_TR_WIDTH_8BITS;
	} else if (dfs <= SPI_DFS_16_BITS) {
		tr_width = DMA_CTL_TR_WIDTH_16BITS;
	} else {
		tr_width = DMA_CTL_TR_WIDTH_32BITS;
	}

	if (rx_tl < SPI_RX_TL)
		msize = DMA_CTL_TR_MSIZE_1;
	else
		msize = DMA_CTL_TR_MSIZE_4;

	h_dma = hal_dma_open(DMA1_ID, 
													((pd->id == MSPI_ID) ? DMA_ID_SPI1_RX : DMA_ID_SSPI_RX),
														(pd->base + SPI_REG_DR_OFS),
															(uint32_t)buffer, 
																buffer_len, 
																	tr_width, tr_width,
																		DMA_ADDR_SAME, DMA_ADDR_INC, 
																			msize, msize, 
																				DMA_AHB_MASTER_PERIPH,  DMA_AHB_MASTER_MEM, 
																					DMA_TT_PERF_TO_MEM_FC_DMAC);
	if (!h_dma) {
		pd->error = SPI_ERR_DMA_NOT_AVAIL;
		goto out;
	}	   
	hal_dma_ch_enable(h_dma, (void *)pd, spi_dma_isr_cb);
	pd->error = SPI_ERR_OK;
 	
	// Set RX request level and enable it
	spi_rxdma_req_level(pd->base, rx_tl);
	spi_rxdma_enable(pd->base);	

	// Select Slave...Start transfer
	if (pd->id == MSPI_ID) { 
		spi_dr_write(pd->base, 0);
		spi_ser(pd->base, 1, cs);
	}

#if CFG_PM_EN
	pd->pm_state = PM_SLEEP;
#endif

	osSemaphoreWait(pd->h_sma, osWaitForever);

out:

	// Disable SPI
	spi_finish(pd);

	// Disable DMA
	if (h_dma) {
		hal_dma_ch_disable(h_dma);
		hal_dma_close(h_dma);	

		spi_rxdma_disable(pd->base);	
	}

#if CFG_PM_EN
	pd->pm_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}

int hal_spi_trx_dma(void *h, int cs, int speed, int phase, int polarity, int dfs, void *wbuf, void *rbuf, uint16_t buffer_len)
{
	spi_dev_t *pd = (spi_dev_t *)h;
	void *h_tx_dma = NULL;
	void *h_rx_dma = NULL;

	if (!pd)
		return SPI_ERR_INVALID_PARAM;	

	if (!wbuf)
		return SPI_ERR_INVALID_PARAM;	

	if (!rbuf)
		return SPI_ERR_INVALID_PARAM;	

	if (buffer_len == 0)
		return SPI_ERR_INVALID_PARAM;	

	if (cs == 1)
		cs = 3;

	osMutexWait(pd->h_mu, osWaitForever);

	// Configure SPI	
	spi_disable(pd->base);
	spi_ctl0(pd->base, SPI_STD_FMT, SPI_TMOD_TX_AND_RX, dfs, phase, polarity);
	if (pd->id == MSPI_ID) {
		spi_baud_rate(pd->base, hal_clk_d0_get(), speed); 
		spi_ser(pd->base, 0, cs);
	}
	spi_intr_clr(pd->base);
	spi_intr_mask(pd->base, SPI_IT_ALL);
	spi_enable(pd->base);	

	int tx_tl, rx_tl;
	if (buffer_len < SPI_TX_TL)
		tx_tl = buffer_len;
	else
		tx_tl = SPI_TX_TL;

	if (buffer_len < SPI_RX_TL)
		rx_tl = buffer_len;
	else
		rx_tl = SPI_RX_TL;

	// Configure TX DMA
	int tr_width, tx_msize, rx_msize ;
	if (dfs <= SPI_DFS_8_BITS) {
		tr_width = DMA_CTL_TR_WIDTH_8BITS;
	} else if (dfs <= SPI_DFS_16_BITS) {
		tr_width = DMA_CTL_TR_WIDTH_16BITS;
	} else {
		tr_width = DMA_CTL_TR_WIDTH_32BITS;
	}

	if (tx_tl < SPI_TX_TL)
		tx_msize = DMA_CTL_TR_MSIZE_1;
	else
		tx_msize = DMA_CTL_TR_MSIZE_4;

	h_tx_dma = hal_dma_open(DMA0_ID, 
														((pd->id == MSPI_ID) ? DMA_ID_SPI1_TX : DMA_ID_SSPI_TX),
															(uint32_t)wbuf, 
																(pd->base + SPI_REG_DR_OFS),  
																	buffer_len, 
																		tr_width, tr_width,
																			DMA_ADDR_INC, DMA_ADDR_SAME, 
																				tx_msize, tx_msize, 
																					DMA_AHB_MASTER_MEM, DMA_AHB_MASTER_PERIPH, 
																						DMA_TT_MEM_TO_PERF_FC_DMAC);
	if (!h_tx_dma) {
		pd->error = SPI_ERR_DMA_NOT_AVAIL;
		goto out;
	}	   
	hal_dma_ch_enable(h_tx_dma, NULL, NULL);

	if (rx_tl < SPI_RX_TL)
		rx_msize = DMA_CTL_TR_MSIZE_1;
	else
		rx_msize = DMA_CTL_TR_MSIZE_4;

	h_rx_dma = hal_dma_open(DMA1_ID, 
														((pd->id == MSPI_ID) ? DMA_ID_SPI1_RX : DMA_ID_SSPI_RX),
															(pd->base + SPI_REG_DR_OFS),
																(uint32_t)rbuf, 
																	buffer_len, 
																		tr_width, tr_width,
																			DMA_ADDR_SAME, DMA_ADDR_INC, 
																				rx_msize, rx_msize, 
																					DMA_AHB_MASTER_PERIPH,  DMA_AHB_MASTER_MEM, 
																						DMA_TT_PERF_TO_MEM_FC_DMAC);
	if (!h_rx_dma) {
		pd->error = SPI_ERR_DMA_NOT_AVAIL;
		goto out;
	}	   
	hal_dma_ch_enable(h_rx_dma, (void *)pd, spi_dma_isr_cb);

	pd->error = SPI_ERR_OK;
 	
	// Set TX request level and enable it
	spi_txdma_req_level(pd->base, tx_tl);
	spi_txdma_enable(pd->base);	

	// Set RX request level and enable it
	spi_rxdma_req_level(pd->base, rx_tl);
	spi_rxdma_enable(pd->base);	

	// Select Slave...Start transfer
	if (pd->id == MSPI_ID) 
		spi_ser(pd->base, 1, cs);

#if CFG_PM_EN
	pd->pm_state = PM_SLEEP;
#endif

	osSemaphoreWait(pd->h_sma, osWaitForever);

out:

	// Disable SPI
	spi_finish(pd);

	// Disable DMA
	if (h_tx_dma) {
		hal_dma_ch_disable(h_tx_dma);
		hal_dma_close(h_tx_dma);	

		spi_txdma_disable(pd->base);	
	}
	
	if (h_rx_dma) {
		hal_dma_ch_disable(h_rx_dma);
		hal_dma_close(h_rx_dma);	

		spi_rxdma_disable(pd->base);	
	}

#if CFG_PM_EN
	pd->pm_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}


static void spi_slv_finish(spi_dev_t *pd)
{
	int poll_count = 0; 										

	// Done, wait for not busy
	while(1) {
		uint32_t status = spi_sr(pd->base);
		if ( !(status & SPI_SR_BUSY))
			break;
		osDelay(1);
		poll_count += 1;
		if (poll_count > 5) {
			pd->error = SPI_ERR_RESET;
			break;
		}	
	}
	spi_disable(pd->base);		

	if (pd->error == SPI_ERR_RESET) {
		spi_reset(pd->id);
	}
}

static int spi_binary_sem_wait(osSemaphoreId sema, uint32_t millisec)
{
    int ret;

    /* 
     * Only use semaphore as a binary sem. osSemaphoreRelease will add sem count without check init count.
     * So here we make sure the count is 0 using osSemaphoreWait(0) , then call  osSemaphoreWait(millisec).   
     */
    if (millisec != 0) {
        do {
            ret = osSemaphoreWait(sema, 0);
        } while (ret > 0);
    }
    ret = osSemaphoreWait(sema, millisec);
	return ret;
}


void hal_spi_slv_stop(void *hdl)
{
	spi_dev_t *pd = (spi_dev_t *)hdl;
	osSemaphoreRelease(pd->h_sma);
	pd->slv_stop = 1;

}

int hal_spi_slv_tx(void *hdl,  int phase, int polarity, int dfs, void *buffer, uint16_t buffer_len, uint16_t *tx_len)
{
	spi_dev_t *pd = (spi_dev_t *)hdl;

	if (!pd)
		return SPI_ERR_INVALID_PARAM;	
	
	if (!pd->used)
		return SPI_ERR_INVALID_OPER;

	if (!buffer)
		return SPI_ERR_INVALID_PARAM;	

	if (buffer_len == 0)
		return SPI_ERR_INVALID_PARAM;	
#if 0
	if (cs == 1)
		cs = 3;
#endif
	osMutexWait(pd->h_mu, osWaitForever);

	// Configure SPI	
	spi_disable(pd->base);
	spi_ctl0(pd->base, SPI_STD_FMT, SPI_TMOD_TX_ONLY, dfs, phase, polarity);
#if 0
	if (pd->id == MSPI_ID) {
		spi_baud_rate(pd->base, hal_clk_d0_get(), speed); 
		spi_ser(pd->base, 0, cs);
	}
#endif
	spi_intr_clr(pd->base);
	spi_intr_mask(pd->base, SPI_IT_ALL);
	int tx_tl;
	if (buffer_len < SPI_TX_TL)
		tx_tl = buffer_len;
	else
		tx_tl = SPI_TX_TL;
	spi_txftl(pd->base, tx_tl);
	spi_enable(pd->base);	
	hal_gpio_ext_int_en((pd->ssn_pin>>GPIO_CFG_PORT_SHIFT) & 0xF, pd->ssn_pin & 0xF, 1, pd, hal_spi_slv_stop);
	spi_pin_mux_en(pd, 1);

	pd->dfs = dfs;

	pd->rxbuf = NULL;
	pd->rxbuf_len = 0;
	pd->rxbuf_ofs = 0;

	pd->txbuf = buffer;
	pd->txbuf_len = buffer_len;
	pd->txbuf_ofs = 0;
	pd->error = SPI_ERR_OK;
	pd->slv_stop = 0;
	// Unmask interrupt
	spi_intr_unmask(pd->base, SPI_IT_TXE|SPI_IT_TXO);
	NVIC_SetPriority(pd->irq, IRQ_PRI_High);	
	NVIC_EnableIRQ(pd->irq);

#if 0
	// Select Slave...Start transfer
	if (pd->id == MSPI_ID) 
		spi_ser(pd->base, 1, cs);
#endif

#if CFG_PM_EN
	pd->pm_state = PM_SLEEP;
#endif
	
	spi_binary_sem_wait(pd->h_sma, osWaitForever);
	//while(!(spi_sr(pd->base) & SPI_SR_BUSY)  &&  (pd->slv_stop == 0));
	//while((spi_sr(pd->base) & SPI_SR_BUSY) && (pd->slv_stop == 0));
	// Disable interrupt
	spi_intr_mask(pd->base, SPI_IT_TXE|SPI_IT_TXO);
	NVIC_DisableIRQ(pd->irq);
	if (tx_len) {
		*tx_len = pd->txbuf_ofs - spi_txfl(pd->base);
	}
	// Done, disable SPI
	spi_slv_finish(pd);
	hal_gpio_ext_int_dis((pd->ssn_pin>>GPIO_CFG_PORT_SHIFT) & 0xF, pd->ssn_pin & 0xF);
	spi_pin_mux_en(pd, 1);//restore pinmux

#if CFG_PM_EN
	pd->pm_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}
int hal_spi_busy(void *hdl)
{
	spi_dev_t *pd = (spi_dev_t *)hdl;
	if (!pd)
		return 0;
	uint32_t status = spi_sr(pd->base);

	return RD_WORD(pd->base + SPI_REG_SSIEN_OFS) && ((status & SPI_SR_BUSY) )  ; 
}

int hal_spi_slv_rx(void *hdl, int phase, int polarity, int dfs, void *buffer, uint16_t buffer_len, uint16_t *rx_len)
{
	spi_dev_t *pd = (spi_dev_t *)hdl;

	if (!pd)
		return SPI_ERR_INVALID_PARAM;	

	if (!pd->used)
		return SPI_ERR_INVALID_OPER;

	if (!buffer)
		return SPI_ERR_INVALID_PARAM;	

	if (buffer_len == 0)
		return SPI_ERR_INVALID_PARAM;	

#if 0
	if (cs == 1)
		cs = 3;
#endif
	osMutexWait(pd->h_mu, osWaitForever);

	// Configure SPI		
	spi_disable(pd->base);
	spi_ctl0(pd->base, SPI_STD_FMT, SPI_TMOD_RX_ONLY, dfs, phase, polarity);
#if 0
	if (pd->id == MSPI_ID) {
		spi_baud_rate(pd->base, hal_clk_d0_get(), speed); 
		spi_ndf(pd->base, (buffer_len - 1));
		spi_ser(pd->base, 0, cs);
	}
#endif
	spi_intr_clr(pd->base);
	spi_intr_mask(pd->base, SPI_IT_ALL);
	int rx_tl;
	if (buffer_len < SPI_RX_TL)
		rx_tl = buffer_len;
	else
		rx_tl = SPI_RX_TL;
	spi_rxftl(pd->base, (rx_tl-1));
	spi_enable(pd->base);	

	pd->dfs = dfs;

	pd->rxbuf = buffer;
	pd->rxbuf_len = buffer_len;
	pd->rxbuf_ofs = 0;

	pd->txbuf = NULL;
	pd->txbuf_len = 0;
	pd->txbuf_ofs = 0;
	pd->error = SPI_ERR_OK;
	pd->slv_stop = 0;

	hal_gpio_ext_int_en((pd->ssn_pin>>GPIO_CFG_PORT_SHIFT) & 0xF, pd->ssn_pin & 0xF, 1, pd, hal_spi_slv_stop);
	spi_pin_mux_en(pd, 1);//restore pinmux

	// Unmask interrupt
	spi_intr_unmask(pd->base, SPI_IT_RXU|SPI_IT_RXO|SPI_IT_RXF);
	NVIC_SetPriority(pd->irq, IRQ_PRI_High);	
	NVIC_EnableIRQ(pd->irq);

#if 0
	/// Select Slave...Start transfer
	if (pd->id == MSPI_ID) {
		spi_dr_write(pd->base, 0);
		spi_ser(pd->base, 1, cs);
	}
#endif

#if CFG_PM_EN
	pd->pm_state = PM_SLEEP;
#endif

	spi_binary_sem_wait(pd->h_sma, osWaitForever);
	//while(!(spi_sr(pd->base) & SPI_SR_BUSY)  &&  (pd->slv_stop == 0));
	//while((spi_sr(pd->base) & SPI_SR_BUSY) && (pd->slv_stop == 0));

	// Disable interrupt
	spi_intr_mask(pd->base, SPI_IT_RXU|SPI_IT_RXO|SPI_IT_RXF);
	NVIC_DisableIRQ(pd->irq);


	if (pd->rxbuf_ofs < buffer_len) {
		uint32_t ofs = pd->rxbuf_ofs;
		uint32_t rxfl = spi_rxfl(pd->base); 

		// Read the FIFO
		if (pd->dfs <= SPI_DFS_8_BITS) {
			uint8_t *buf = (uint8_t *)pd->rxbuf;
			for (int i = 0; i < rxfl; i++) {
				buf[ofs++] = (uint8_t)spi_dr_read(pd->base);
				if (ofs >= pd->rxbuf_len)
					break;								
			}
		} else if (pd->dfs <= SPI_DFS_16_BITS) {
			uint16_t *buf = (uint16_t *)pd->rxbuf;
			for (int i = 0; i < rxfl; i++) {
				buf[ofs++] = (uint16_t)spi_dr_read(pd->base);
				if (ofs >= pd->rxbuf_len)
					break;								
			}
		} else {
			uint32_t *buf = (uint32_t *)pd->rxbuf;
			for (int i = 0; i < rxfl; i++) {
				buf[ofs++] = spi_dr_read(pd->base);
				if (ofs >= pd->rxbuf_len)
					break;								
			}
		}		
		pd->rxbuf_ofs = ofs;
	}
	if (rx_len != NULL) {
		*rx_len = pd->rxbuf_ofs;
	}	
	/// Done, disable SPI
	spi_slv_finish(pd);
	
	hal_gpio_ext_int_dis((pd->ssn_pin>>GPIO_CFG_PORT_SHIFT) & 0xF, pd->ssn_pin & 0xF);
	spi_pin_mux_en(pd, 1);


#if CFG_PM_EN
	pd->pm_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}
#endif	//  (CFG_NB_SPI)

