#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_i2c.c
 *
 * @brief Platform I2c Driver  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#define CFG_NB_I2C (CFG_I2C0_EN + CFG_I2C1_EN)

/*
 * Includes
 ****************************************************************************************
 */

#if CFG_NB_I2C
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "in_arm.h"
#include "in_mmap.h"
#include "in_irq.h"
#include "in_debug.h"

#include ".\hal\hal_clk.h"
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_i2c.h"
#include ".\hal\hal_dma.h"

#if CFG_PM_EN
#include ".\hal\hal_power.h"
#endif

#include "cmsis_os.h"

/*
 * Structures
 ****************************************************************************************
 */

typedef struct {
	char id;
	char used;
	char dir;
	char slv;

	uint32_t scl_pin;
	uint32_t sda_pin;

	uint32_t base;
	IRQn_Type irq;
	
	uint32_t mu[4];
	osMutexId h_mu;
	uint32_t sma[2];
	osSemaphoreId h_sma; 

	int error;
	uint8_t *buffer;
	uint16_t buffer_len;
	uint16_t buffer_idx;
	int stop;

#if CFG_PM_EN
	int power_state;
	struct pm_module pmd;
#endif

} i2c_dev_t;

static i2c_dev_t i2c_dev[CFG_NB_I2C] = {
#if CFG_I2C0_EN 	
	{
		.id = I2C0_ID,
		.used = 0,
		.base = I2C0_BASE,
		.irq = I2c0_IRQn,
	},
#endif
#if CFG_I2C1_EN	
	{
		.id = I2C1_ID,
		.used = 0,
		.base = I2C1_BASE,
		.irq = I2c1_IRQn,
	},
#endif	
};

/*
 * Static Functions
 ****************************************************************************************
 */

static void i2c_scl_cnt(i2c_dev_t *pd, int speed)
{
	if (speed == I2C_SPEED_100K) {
		i2c_ss_scl_hcnt(pd->base, 128);
		i2c_ss_scl_lcnt(pd->base, 150);
	} else {
		i2c_fs_scl_hcnt(pd->base, 20/*32*/);
		i2c_fs_scl_lcnt(pd->base, 28/*40*/);
	}
} 

static void i2c_finish(i2c_dev_t *pd)
{
	int poll_count = 0; 										

	/// Wait for activity finish
	while (i2c_intr_raw_status(pd->base) & I2C_INTR_ACTIVITY) {
		i2c_intr_clr_activity(pd->base);
		osDelay(1);
		poll_count += 1;
		if (poll_count > 5) {
			pd->error = I2C_ERR_RESET;
			break;
		}	
	}
	
	/// Finish, Disable I2c
	if (pd->error != I2C_ERR_RESET) {
		i2c_disable(pd->base);			
		while (i2c_enable_status(pd->base) & I2C_ES_ENABLE) {
			osDelay(1);
			poll_count += 1;
			if (poll_count > 5) {
				pd->error = I2C_ERR_RESET;
				break;
			}	
		}	
	}

	if (pd->error == I2C_ERR_RESET) {
		i2c_reset(pd->id);
	}
}

static void i2c_pin_mux_en(i2c_dev_t *pd, int en)
{
	if (en) {
		hal_gpio_pin_cfg(pd->scl_pin);
		hal_gpio_pin_cfg(pd->sda_pin);
	} else {
		hal_gpio_pin_dft(pd->scl_pin);
		hal_gpio_pin_dft(pd->sda_pin);
	}
}

static int i2c_pin_chk(i2c_dev_t *pd)
{
	if (pd->id == I2C0_ID) {

		// GPIO_0_0 = scl
		// GPIO_0_1 = sda
		// GPIO_1_7 = scl_bkup
		// GPIO_1_8 = sda_bkup

		// Sanity check

		// SCL pin
		if (((CFG_GPIO_0_0>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2C_0_SCL) {
			if (((CFG_GPIO_1_7>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2C_0_SCL_BKUP)
				return 0;
			pd->scl_pin =  CFG_GPIO_0_0;
		} else {
			if (((CFG_GPIO_1_7>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2C_0_SCL_BKUP) {
				pd->scl_pin =  CFG_GPIO_1_7;
			} else {
				// No i2c SCL pin configure
				return 0;
			}
		}
		
		// SDA pin
		if (((CFG_GPIO_0_1>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2C_0_SDA) {
			if (((CFG_GPIO_1_8>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2C_0_SDA_BKUP)
				return 0;
			pd->sda_pin =  CFG_GPIO_0_1;
		} else {
			if (((CFG_GPIO_1_8>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2C_0_SDA_BKUP) {
				pd->sda_pin =  CFG_GPIO_1_8;
			} else {
				// No i2c SDA pin configure
				return 0;
			}
		}
	}

	if (pd->id == I2C1_ID) {

		// GPIO_0_3 = scl
		// GPIO_0_4 = sda
		// GPIO_4_0 = scl_bkup
		// GPIO_4_1 = sda_bkup

		// Sanity check

		// SCL pin
		if (((CFG_GPIO_0_3>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2C_1_SCL) {
			if (((CFG_GPIO_4_0>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2C_1_SCL_BKUP) {
				return 0;
			} else {
				pd->scl_pin =  CFG_GPIO_0_3;
			}
		} else {
			if (((CFG_GPIO_4_0>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2C_1_SCL_BKUP) {
				pd->scl_pin =  CFG_GPIO_4_0;
			} else {
				// No i2c SCL pin configure
				return 0;
			}
		}
		
		// SDA pin
		if (((CFG_GPIO_0_4>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2C_1_SDA) {
			if (((CFG_GPIO_4_1>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2C_1_SDA_BKUP) {
				return 0;
			} else {
				pd->sda_pin =  CFG_GPIO_0_4;
			}
		} else {
			if (((CFG_GPIO_4_1>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_IO_I2C_1_SDA_BKUP) {
				pd->sda_pin =  CFG_GPIO_4_1;
			} else {
				// No i2c SDA pin configure
				return 0;
			}
		}
	}

	return 1;
}

/*
 * PM CALLBACK
 ****************************************************************************************
 */

#if CFG_PM_EN
static int i2c_pm_state(void *arg, uint32_t *sleep_duration)
{
	i2c_dev_t *pd = (i2c_dev_t *)arg;

	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->power_state;
}

static void i2c_pm_down(void *arg, uint32_t sleep_duration)
{
	return;
}

static void i2c_pm_up(void *arg)
{
	//i2c_dev_t *pd = (i2c_dev_t *)arg;

	// Recover pin mux
	//i2c_pin_mux_en(pd, 1);
}
#endif	// CFG_PM_EN

/*
 * DMA CALLBACK
 ****************************************************************************************
 */

static void i2c_dma_callback(int id, void *arg, int status)
{
	i2c_dev_t *pd = (i2c_dev_t *)arg;

	if (status & DMA_IT_STATUS_TFR) {
		pd->error = I2C_ERR_OK;
	} else {
		pd->error = I2C_ERR_DMA_FAIL;
	}

	if (pd->slv) {
		if (pd->dir == I2C_DIR_READ)
			osSemaphoreRelease(pd->h_sma);
	} else {
		if (pd->dir == I2C_DIR_READ) {
			if (id == DMA1_ID) {
				osSemaphoreRelease(pd->h_sma);
			}
		} else {
			osSemaphoreRelease(pd->h_sma);
		}
	}
}

/*
 * ISR
 ****************************************************************************************
 */

static void i2c_isr(i2c_dev_t *pd)
{
	uint32_t status;

	status = i2c_intr_status(pd->base);
//PRINTD(DBG_TRACE, "[%d]: status:%08x\r\n", pd->id, status);

	if (status & I2C_INTR_TX_ABRT) {
		///  TX ABRT Clear
		i2c_intr_clr_abt(pd->base);			

		uint32_t reason = i2c_abt_source(pd->base);
//PRINTD(DBG_ERR, "[%d]: abort:%08x\r\n", pd->id, reason);

		int err = pd->error;
		if (reason & I2C_ABRT_ADDR_NOACK) {
			pd->error = I2C_ERR_ADDR_NO_ACK;
		} else if (reason & I2C_ABRT_TXDATA_NOACK) {
			pd->error = I2C_ERR_TXDATA_NO_ACK;
		} else if (reason & I2C_ABRT_SDA_STUCK_AT_LOW) {
			pd->error = I2C_ERR_SDA_STUCK_AT_LOW;
		} else if (reason & I2C_ABRT_USER_ABRT) {
			pd->error = err;
		} else {
			pd->error = I2C_ERR_UNKNOWN;
		}
		
		i2c_intr_mask(pd->base, I2C_INTR_TX_ABRT);
		osSemaphoreRelease(pd->h_sma);
	}

	if (status & I2C_INTR_RX_UNDER) {
	
		i2c_intr_clr_rxu(pd->base);	/// RX Under Clear
//PRINTD(DBG_ERR, "[%d]: rx under\r\n", pd->id);
	}

	if (status & I2C_INTR_RX_OVER) {
		i2c_intr_clr_rxo(pd->base);	/// RX Over Clear
//PRINTD(DBG_ERR, "[%d]: rx over\r\n", pd->id);

		pd->error = I2C_ERR_RX_OVER_RUN;
		i2c_intr_mask(pd->base, I2C_INTR_RX_FULL|I2C_INTR_RX_OVER|I2C_INTR_RX_UNDER);
		osSemaphoreRelease(pd->h_sma);
	}

	if (status & I2C_INTR_RX_FULL) {
		int idx = pd->buffer_idx;
		uint32_t rx_bytes = i2c_rx_fifo_level(pd->base);

		for (int i = 0; i < rx_bytes; i++) {
			uint8_t data = i2c_read(pd->base);
			if (idx < pd->buffer_len)
				pd->buffer[idx++] = data;
		}
		pd->buffer_idx = idx;

		if (idx >= pd->buffer_len) {
			i2c_intr_mask(pd->base, I2C_INTR_RX_FULL|I2C_INTR_RX_OVER|I2C_INTR_RX_UNDER);
			osSemaphoreRelease(pd->h_sma);
		} else {
			if (!pd->slv) {		// Master read
				int nbytes;
				int len = pd->buffer_len - idx;

				if (len >= I2C_RX_FIFO_TL) {
					nbytes =  I2C_RX_FIFO_TL;
				} else {
					nbytes = len;
					i2c_rx_fifo_tl(pd->base, (nbytes-1));
				}

				for (int i = 0; i < nbytes; i++) {
					if ((idx + i) == pd->buffer_len - 1) {
						i2c_write(pd->base, 0, 1, pd->stop);		/// Write Stop bit 
					} else {
						i2c_write(pd->base, 0, 1, 0);
					}
				}
			}
		}
	}

	if (status & I2C_INTR_TX_EMPTY) {
		int idx = pd->buffer_idx;
		int len = (pd->buffer_len - idx);
		int nbytes;

		if (len > I2C_TX_FIFO_TL)
			nbytes =  I2C_TX_FIFO_TL;
		else
			nbytes = len;
			
		if (len <= 0) {
			i2c_intr_mask(pd->base, I2C_INTR_TX_EMPTY|I2C_INTR_TX_OVER);
			osSemaphoreRelease(pd->h_sma);
		} else {
			for (int i = 0; i < nbytes; i++) {
				if (idx == (pd->buffer_len - 1))
					i2c_write(pd->base, pd->buffer[idx], 0, pd->stop);	// Stop
				else
					i2c_write(pd->base, pd->buffer[idx], 0, 0);
				idx++;
			}
			pd->buffer_idx = idx;
		}	
	}

	if (status & I2C_INTR_TX_OVER) {
		i2c_intr_clr_txo(pd->base);		/// TX Over Clear
//PRINTD(DBG_ERR, "[%d]: tx over\r\n", pd->id);

		pd->error = I2C_ERR_TX_OVER_FLOW;	
		osSemaphoreRelease(pd->h_sma);
	}

	/// Slave: First byte of transmission
	if (status & I2C_INTR_RD_REQ) {
		i2c_intr_clr_req(pd->base);		/// RD REQ Clear

		/// Slave mode only...
		if (pd->slv == 3) {		
			/// DMA 	
			osSemaphoreRelease(pd->h_sma);
		} else {
			/// Fill in FIFO
			int idx = pd->buffer_idx;
			int len = pd->buffer_len - idx;
			int nbytes;

			if (len < I2C_FIFO_DEPTH) { 
				nbytes = len;
			} else {
				nbytes = I2C_FIFO_DEPTH;
			}

			for (int i = 0; i < nbytes; i++) {
				i2c_write(pd->base, pd->buffer[idx++], 0, 0);
			}

			pd->buffer_idx = idx;
		}

	}

	/// Slave: Last byte of transmission
	if (status & I2C_INTR_RX_DONE) {
		i2c_intr_clr_rxd(pd->base);
		osSemaphoreRelease(pd->h_sma);
 	}

	if (status & I2C_INTR_ACTIVITY) {
		i2c_intr_clr_activity(pd->base);	/// Activity Clear
	}

	if (status & I2C_INTR_STOP_DET) {
		i2c_intr_clr_stop(pd->base);		/// Stop DET Clear		
	}

	if (status & I2C_INTR_START_DET) {
		i2c_intr_clr_start(pd->base);		/// Start DET Clear
	}
}

__irq void I2C0_Handler(void)
{
	for (int i = 0; i < CFG_NB_I2C; i++) {
		if (i2c_dev[i].id == I2C0_ID) {
			i2c_isr(&i2c_dev[i]);
			break;
		}
	}
}

__irq void I2C1_Handler(void)
{
	for (int i = 0; i < CFG_NB_I2C; i++) {
		if (i2c_dev[i].id == I2C1_ID) {
			i2c_isr(&i2c_dev[i]);
			break;
		}
	}
}

/*
 * APIs
 ****************************************************************************************
 */

void *hal_i2c_open(int id)
{
	i2c_dev_t *pd = NULL;

	for (int i = 0; i < CFG_NB_I2C; i++) {
		if ((i2c_dev[i].id == id) && (i2c_dev[i].used == 0)) {
			pd = &i2c_dev[i];
			break;
		}
	}

	if (!pd)
		return NULL;

	/// Pin mux
	if (!i2c_pin_chk(pd))
		return NULL;

	/// Mutex and Semaphore
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
			osMutexDelete(pd->h_mu);
			return NULL;
		}
	}

	/// Set pin mux
	i2c_pin_mux_en(pd, 1);

	/// Clk 
	hal_clk_i2c_en(id, 1);

	/// PM
#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
	pd->pmd.arg = (void *)pd;
	pd->pmd.power_state = i2c_pm_state;
	pd->pmd.power_down = i2c_pm_down;
	pd->pmd.power_up = i2c_pm_up;
	hal_pm_reg_mod(&pd->pmd);
#endif

	pd->used = 1;

	return (void *)pd;
}

void hal_i2c_close(void *hdl)
{
	//int i;
	i2c_dev_t *pd = (i2c_dev_t *)hdl;

	if (!pd)
		return;

	pd->used = 0;	

	/// Free semaphore and mutex
	osMutexDelete(pd->h_mu);
	osSemaphoreDelete(pd->h_sma);	

	/// Clk 
	hal_clk_i2c_en(pd->id, 0);

	/// Pin mux
	i2c_pin_mux_en(pd, 0);
	
#if CFG_PM_EN
	hal_pm_unreg_mod(&pd->pmd);
#endif

	return;
}

int hal_mi2c_read(void *hdl, int speed, uint8_t tar, uint8_t *buffer, uint16_t buffer_len, uint32_t tmo)
{
	i2c_dev_t *pd = (i2c_dev_t *)hdl;
	int rd_bytes, wait_ret;

	if (!pd) 
		return I2C_ERR_INVALID_PARAM;

	if (!pd->used)
		return I2C_ERR_INVALID_STATE;


	osMutexWait(pd->h_mu, osWaitForever);

	pd->slv = 0;
	pd->error = I2C_ERR_OK;
	pd->dir = I2C_DIR_READ;
	pd->buffer = buffer;
	pd->buffer_len = buffer_len;
	pd->buffer_idx = 0;	
	pd->stop = 1;

	i2c_disable(pd->base);
	i2c_con_clear(pd->base);
	i2c_master_enable(pd->base);	
	i2c_tar(pd->base, tar);
	i2c_speed(pd->base, speed);
	i2c_scl_cnt(pd, speed);
	i2c_intr_clr(pd->base);												/// Clear all the interrupt
	i2c_intr_mask(pd->base, I2C_INTR_MASK_ALL);		/// Mask all the interrupt
	// Set FIFO threshold
	if (buffer_len <  I2C_FIFO_DEPTH) { 
		rd_bytes = buffer_len;
	} else {
		rd_bytes = I2C_RX_FIFO_TL;
	}
	i2c_rx_fifo_tl(pd->base, (rd_bytes-1));
	i2c_intr_unmask(pd->base, I2C_INTR_RX_FULL|I2C_INTR_RX_OVER|I2C_INTR_RX_UNDER);
	i2c_enable(pd->base);												/// All set, enable controller
	NVIC_SetPriority(pd->irq, IRQ_PRI_High);	
	NVIC_EnableIRQ(pd->irq);

	// program fifo to kick start read 
	for (int i = 0; i < rd_bytes; i++) {
		if (i == (buffer_len - 1)) {
			i2c_write(pd->base, 0, 1, 1);		/// Write Stop bit 
		} else {
			i2c_write(pd->base, 0, 1, 0);		  
		}
	}

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif
		
	/// Wait for complete
	wait_ret = osSemaphoreWait(pd->h_sma, tmo);
	if (wait_ret == 0) {
		pd->error = I2C_ERR_TMO;
	}

	/// Disable interrupt
	i2c_intr_mask(pd->base, I2C_INTR_MASK_ALL);		
	NVIC_DisableIRQ(pd->irq);

	/// Wait for activity finish
	//while (i2c_intr_raw_status(pd->base) & I2C_INTR_ACTIVITY) {
	//	i2c_intr_clr_activity(pd->base);
	//}

	/// Finish, Disable I2c
	i2c_finish(pd);

#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}

int hal_mi2c_write(void *hdl, int speed, uint8_t tar, uint8_t *buffer, uint16_t buffer_len, uint32_t tmo)
{
	i2c_dev_t *pd = (i2c_dev_t *)hdl;
	int wait_ret;

	if (!pd) 
		return I2C_ERR_INVALID_PARAM;

	if (!pd->used)
		return I2C_ERR_INVALID_STATE;
	
	osMutexWait(pd->h_mu, osWaitForever);

	pd->slv = 0;
	pd->error = I2C_ERR_OK;
	pd->dir = I2C_DIR_WRITE;
	pd->buffer = buffer;
	pd->buffer_len = buffer_len;
	pd->buffer_idx = 0;	
	pd->stop = 1;

	i2c_disable(pd->base);
	i2c_con_clear(pd->base);
	i2c_master_enable(pd->base);	
	i2c_tar(pd->base, tar);
	i2c_speed(pd->base, speed);
	i2c_scl_cnt(pd, speed);
	i2c_intr_clr(pd->base);												/// Clear all the interrupt
	i2c_intr_mask(pd->base, I2C_INTR_MASK_ALL);		/// Mask all the interrupt
	// Set FIFO threshold
	if (buffer_len <  I2C_FIFO_DEPTH) { 
		i2c_tx_fifo_tl(pd->base, buffer_len);
	} else {
		i2c_tx_fifo_tl(pd->base, I2C_TX_FIFO_TL);
	}
	i2c_intr_unmask(pd->base, I2C_INTR_TX_EMPTY|I2C_INTR_TX_OVER|I2C_INTR_TX_ABRT);
	i2c_enable(pd->base);												/// All set, enable controller
	NVIC_SetPriority(pd->irq, IRQ_PRI_High);	
	NVIC_EnableIRQ(pd->irq);

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif
		
	/// Wait for complete
	wait_ret = osSemaphoreWait(pd->h_sma, tmo);
	if (wait_ret == 0) 
		pd->error = I2C_ERR_TMO;

	/// Disable interrupt
	i2c_intr_mask(pd->base, I2C_INTR_MASK_ALL);		
	NVIC_DisableIRQ(pd->irq);

	/// Finish, Disable I2c
	i2c_finish(pd);

#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}
int hal_mi2c_write_read(void *hdl, int speed, uint8_t tar, uint8_t *wr_buf, uint16_t wr_len, uint8_t *rd_buf, uint16_t rd_len, uint32_t tmo)
{
	i2c_dev_t *pd = (i2c_dev_t *)hdl;
	int wait_ret;
	int rd_bytes;

	if (!pd) 
		return I2C_ERR_INVALID_PARAM;

	if (!pd->used)
		return I2C_ERR_INVALID_STATE;
	
	osMutexWait(pd->h_mu, osWaitForever);

	pd->slv = 0;
	pd->error = I2C_ERR_OK;
	pd->dir = I2C_DIR_WRITE;
	pd->buffer = wr_buf;
	pd->buffer_len = wr_len;
	pd->buffer_idx = 0;	
	pd->stop = 0;

	i2c_disable(pd->base);
	i2c_con_clear(pd->base);
	i2c_master_enable(pd->base);	
	i2c_tar(pd->base, tar);
	i2c_speed(pd->base, speed);
	i2c_restart_enable(pd->base);
	i2c_scl_cnt(pd, speed);
	i2c_intr_clr(pd->base);												/// Clear all the interrupt
	i2c_intr_mask(pd->base, I2C_INTR_MASK_ALL);		/// Mask all the interrupt
	// Set FIFO threshold
	if (wr_len <  I2C_FIFO_DEPTH) { 
		i2c_tx_fifo_tl(pd->base, wr_len);
	} else {
		i2c_tx_fifo_tl(pd->base, I2C_TX_FIFO_TL);
	}

	// Set FIFO threshold
	if (rd_len <  I2C_FIFO_DEPTH) { 
		rd_bytes = rd_len;
	} else {
		rd_bytes = I2C_RX_FIFO_TL;
	}
	i2c_rx_fifo_tl(pd->base, (rd_bytes-1));
		
	i2c_intr_unmask(pd->base, I2C_INTR_TX_EMPTY|I2C_INTR_TX_OVER|I2C_INTR_TX_ABRT);
	i2c_enable(pd->base);												/// All set, enable controller
	NVIC_SetPriority(pd->irq, IRQ_PRI_High);	
	NVIC_EnableIRQ(pd->irq);

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif
		
	/// Wait for complete
	wait_ret = osSemaphoreWait(pd->h_sma, tmo);

	
	if (wait_ret == 0) 
		pd->error = I2C_ERR_TMO;

	if (pd->error == I2C_ERR_OK ) {
		//pd->slv = 0;
		//pd->error = I2C_ERR_OK;
		pd->dir = I2C_DIR_READ;
		pd->buffer = rd_buf;
		pd->buffer_len = rd_len;
		pd->buffer_idx = 0;	
		pd->stop = 1;


		i2c_intr_unmask(pd->base, I2C_INTR_RX_FULL|I2C_INTR_RX_OVER|I2C_INTR_RX_UNDER);


		// program fifo to kick start read 
		for (int i = 0; i < rd_bytes; i++) {
			if (i == (rd_len - 1)) {
				i2c_write(pd->base, 0, 1, 1);		/// Write Stop bit 
			} else {
				i2c_write(pd->base, 0, 1, 0);		  
			}
		}
			
		/// Wait for complete
		wait_ret = osSemaphoreWait(pd->h_sma, tmo);
		if (wait_ret == 0) {
			pd->error = I2C_ERR_TMO;
		}

	}

	/// Disable interrupt
	i2c_intr_mask(pd->base, I2C_INTR_MASK_ALL);		
	NVIC_DisableIRQ(pd->irq);

	/// Finish, Disable I2c
	i2c_finish(pd);

#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}
int hal_si2c_read(void *hdl, int speed, uint8_t sar, uint8_t *buffer, uint16_t buffer_len, uint32_t tmo)
{
	i2c_dev_t *pd = (i2c_dev_t *)hdl;
	int wait_ret;

	if (!pd) 
		return I2C_ERR_INVALID_PARAM;

	if (!pd->used)
		return I2C_ERR_INVALID_STATE;

	osMutexWait(pd->h_mu, osWaitForever);

	pd->slv = 1;
	pd->error = I2C_ERR_OK;
	pd->dir = I2C_DIR_READ;
	pd->buffer = buffer;
	pd->buffer_len = buffer_len;
	pd->buffer_idx = 0;
	pd->stop = 1;

	i2c_disable(pd->base);
	i2c_con_clear(pd->base);
	i2c_slave_enable(pd->base);
	i2c_speed(pd->base, speed);
	i2c_sar(pd->base, sar);											/// Slave address						
	i2c_intr_clr(pd->base);												/// Clear all the interrupt
	i2c_intr_mask(pd->base, I2C_INTR_MASK_ALL);		/// Mask all the interrupt
	// Set FIFO threshold
	if (buffer_len <  I2C_FIFO_DEPTH) { 
		i2c_rx_fifo_tl(pd->base, (buffer_len-1));
	} else {
		i2c_rx_fifo_tl(pd->base, (I2C_RX_FIFO_TL-1));
	}
	i2c_intr_unmask(pd->base, I2C_INTR_RX_FULL|I2C_INTR_RX_OVER|I2C_INTR_RX_UNDER);
	i2c_enable(pd->base);												/// All set, enable controller
	NVIC_SetPriority(pd->irq, IRQ_PRI_High);	
	NVIC_EnableIRQ(pd->irq);
	
#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif

	/// Wait for complete
	wait_ret = osSemaphoreWait(pd->h_sma, tmo);
	if (wait_ret == 0)
		pd->error = I2C_ERR_TMO;

	/// Disable interrupt
	i2c_intr_mask(pd->base, I2C_INTR_MASK_ALL);		
	NVIC_DisableIRQ(pd->irq);

	/// Finish, Disable I2c
	i2c_finish(pd);

#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}

int hal_si2c_write(void *hdl, int speed, uint8_t sar, uint8_t *buffer, uint16_t buffer_len, uint32_t tmo)
{
	i2c_dev_t *pd = (i2c_dev_t *)hdl;
	int wait_ret;

	if (!pd) 
		return I2C_ERR_INVALID_PARAM;

	if (!pd->used)
		return I2C_ERR_INVALID_STATE;

	osMutexWait(pd->h_mu, osWaitForever);

	pd->slv = 1;
	pd->error = I2C_ERR_OK;
	pd->dir = I2C_DIR_WRITE;
	pd->buffer = buffer;
	pd->buffer_len = buffer_len;
	pd->buffer_idx = 0;
	pd->stop = 1;

	i2c_disable(pd->base);
	i2c_con_clear(pd->base);
	i2c_slave_enable(pd->base);
	i2c_speed(pd->base, speed);
	i2c_sar(pd->base, sar);											/// Slave address						
	i2c_intr_clr(pd->base);												/// Clear all the interrupt
	i2c_intr_mask(pd->base, I2C_INTR_MASK_ALL);		/// Mask all the interrupt
	i2c_intr_unmask(pd->base, I2C_INTR_RD_REQ|I2C_INTR_RX_DONE);
	i2c_enable(pd->base);												/// All set, enable controller
	NVIC_SetPriority(pd->irq, IRQ_PRI_High);	
	NVIC_EnableIRQ(pd->irq);
	
#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif

	/// Wait for complete
	wait_ret = osSemaphoreWait(pd->h_sma, tmo);
	if (wait_ret == 0) 
		pd->error = I2C_ERR_TMO;

	/// Disable interrupt
	i2c_intr_mask(pd->base, I2C_INTR_MASK_ALL);		
	NVIC_DisableIRQ(pd->irq);

	/// Wait for activity finish
	//while (i2c_intr_raw_status(pd->base) & I2C_INTR_ACTIVITY) {
	//	i2c_intr_clr_activity(pd->base);
	//}

	/// Finish, Disable I2c
	i2c_finish(pd);

#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}

int hal_mi2c_read_dma(void *hdl, int speed, uint8_t tar, uint8_t *buffer, uint16_t buffer_len, uint32_t tmo)
{
	i2c_dev_t *pd = (i2c_dev_t *)hdl;
	void *h_dma_tx = NULL, *h_dma_rx = NULL;
	int dma_burst_size, i2c_burst_size;	
	uint16_t *i2c_cmd_buf = (uint16_t *)malloc((buffer_len * 2));
	int wait_ret;

	if (!i2c_cmd_buf)
		return I2C_ERR_DMA_ALLOC_BUF_FAIL;

	if (!pd) 
		return I2C_ERR_INVALID_PARAM;

	if (!pd->used)
		return I2C_ERR_INVALID_STATE;
	
	osMutexWait(pd->h_mu, osWaitForever);

	pd->slv = 0;
	pd->error = I2C_ERR_OK;
	pd->dir = I2C_DIR_READ;
	pd->stop = 1;
	/// Set DMA read/write burst size
	if (buffer_len <  4) { 
		dma_burst_size = DMA_CTL_TR_MSIZE_1;
		i2c_burst_size = 1;
	} else {
		dma_burst_size = DMA_CTL_TR_MSIZE_4;
		i2c_burst_size = 4;
	}

	/// I2c READ set
	for (int i = 0; i < buffer_len; i++) {
		i2c_cmd_buf[i] = I2C_READ;
	} 		
	/// I2c STOP set
	i2c_cmd_buf[buffer_len-1] |= I2C_STOP;

	// DMA set up to fill I2c FIFO with read command
	h_dma_tx = hal_dma_open(DMA0_ID, 
										((pd->id == I2C0_ID) ? DMA_ID_I2C0_TX : DMA_ID_I2C1_TX),
											(uint32_t)i2c_cmd_buf, (pd->base + I2C_REG_DATA_OFS), 
												buffer_len, 
												DMA_CTL_TR_WIDTH_16BITS, DMA_CTL_TR_WIDTH_16BITS,
													DMA_ADDR_INC, DMA_ADDR_SAME, 
														dma_burst_size, dma_burst_size, 
															DMA_AHB_MASTER_MEM,  DMA_AHB_MASTER_PERIPH, 
																DMA_TT_MEM_TO_PERF_FC_DMAC);
	if (!h_dma_tx) {
		pd->error = I2C_ERR_DMA_BUSY;
		goto out;
	}

	/// DMA set up to fill the user's buffer with I2c receive data 
	h_dma_rx = hal_dma_open(DMA1_ID, 
											((pd->id == I2C0_ID) ? DMA_ID_I2C0_RX : DMA_ID_I2C1_RX),
												(pd->base + I2C_REG_DATA_OFS), (uint32_t)buffer, 
												buffer_len, 
												DMA_CTL_TR_WIDTH_8BITS, DMA_CTL_TR_WIDTH_8BITS,
													DMA_ADDR_SAME, DMA_ADDR_INC, 
														dma_burst_size, dma_burst_size, 
															DMA_AHB_MASTER_PERIPH, DMA_AHB_MASTER_MEM, 
																DMA_TT_PERF_TO_MEM_FC_DMAC);
	if (!h_dma_rx) {
		pd->error = I2C_ERR_DMA_BUSY;
		goto out;
	}

	// Dma channel enable
	hal_dma_ch_enable(h_dma_tx, NULL, NULL);
	hal_dma_ch_enable(h_dma_rx, (void *)pd, i2c_dma_callback);

	// I2c set up
	i2c_disable(pd->base);
	i2c_con_clear(pd->base);
	i2c_master_enable(pd->base);	
	i2c_tar(pd->base, tar);
	i2c_speed(pd->base, speed);
	i2c_scl_cnt(pd, speed);
	i2c_intr_clr(pd->base);												/// Clear all the interrupt
	// Set FIFO threshold
	i2c_rx_fifo_tl(pd->base, 0);
	i2c_tx_fifo_tl(pd->base, 0);

	// Unmake interrupt
	//i2c_intr_unmask(pd->base, I2C_INTR_TX_EMPTY|I2C_INTR_TX_OVER|I2C_INTR_RX_FULL|I2C_INTR_RX_OVER|I2C_INTR_RX_UNDER);

	// I2c DMA requet enable
	i2c_dma_tx_enable(pd->base);
	i2c_dma_rx_enable(pd->base);

	// I2c DMA burst size	set
	i2c_dma_tx_data_level(pd->base, (i2c_burst_size-1));
	i2c_dma_rx_data_level(pd->base, (i2c_burst_size-1));
	i2c_enable(pd->base);												/// All set, enable controller

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif
		
	/// Wait for DMA receive complete interrupt
	wait_ret = osSemaphoreWait(pd->h_sma, tmo);
	if (wait_ret == 0) {	/// Time out
		pd->error = I2C_ERR_TMO;
		goto out;
	}

out:

	/// Check I2c activity completed interrupt
 	//while (i2c_intr_raw_status(pd->base) & I2C_INTR_ACTIVITY) {
	//	i2c_intr_clr_activity(pd->base);
	//}

	//i2c_intr_mask(pd->base, I2C_INTR_TX_EMPTY|I2C_INTR_TX_OVER|I2C_INTR_RX_FULL|I2C_INTR_RX_OVER|I2C_INTR_RX_UNDER);
	/// I2c DMA request disable
	i2c_dma_tx_disable(pd->base);
	i2c_dma_rx_disable(pd->base);

	/// DMA disable
	if (h_dma_tx) {
		hal_dma_ch_disable(h_dma_tx);
		hal_dma_close(h_dma_tx);
	}

	if (h_dma_rx) {
		hal_dma_ch_disable(h_dma_rx);
		hal_dma_close(h_dma_rx);
	}

	if (i2c_cmd_buf) {
		free(i2c_cmd_buf);
	}	

	/// Finish, Disable I2c
	i2c_finish(pd);

#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}

int hal_mi2c_write_dma(void *hdl, int speed, uint8_t tar, uint8_t *buffer, uint16_t buffer_len, uint32_t tmo)
{
	i2c_dev_t *pd = (i2c_dev_t *)hdl;
	void *h_dma = NULL;
	int dma_burst_size, i2c_burst_size;	
	uint16_t *i2c_cmd_buf = (uint16_t *)malloc((buffer_len * 2));
	int wait_ret;

	if (!i2c_cmd_buf)
		return I2C_ERR_DMA_ALLOC_BUF_FAIL;

	if (!pd) 
		return I2C_ERR_INVALID_PARAM;

	if (!pd->used)
		return I2C_ERR_INVALID_STATE;

	osMutexWait(pd->h_mu, osWaitForever);

	pd->slv = 0;
	pd->error = I2C_ERR_OK;
	pd->dir = I2C_DIR_WRITE;
	pd->stop = 1;
	/// Set DMA read/write burst size
	if (buffer_len <  4) { 
		dma_burst_size = DMA_CTL_TR_MSIZE_1;
		i2c_burst_size = 1;
	} else {
		dma_burst_size = DMA_CTL_TR_MSIZE_4;
		i2c_burst_size = 4;
	}

	/// Fill the WRITE cmd 
	for (int i = 0; i < buffer_len; i++) {
		i2c_cmd_buf[i] = buffer[i];
	} 		
	/// Set the STOP cmd
	i2c_cmd_buf[buffer_len-1] |= I2C_STOP;

	// DMA configuration
	h_dma = hal_dma_open(DMA0_ID, 
										((pd->id == I2C0_ID) ? DMA_ID_I2C0_TX : DMA_ID_I2C1_TX),
											(uint32_t)i2c_cmd_buf, (pd->base + I2C_REG_DATA_OFS), 
												buffer_len, 
												DMA_CTL_TR_WIDTH_16BITS, DMA_CTL_TR_WIDTH_16BITS,
													DMA_ADDR_INC, DMA_ADDR_SAME, 
														dma_burst_size, dma_burst_size, 
															DMA_AHB_MASTER_MEM,  DMA_AHB_MASTER_PERIPH, 
																DMA_TT_MEM_TO_PERF_FC_DMAC);
	if (!h_dma) {
		pd->error = I2C_ERR_DMA_BUSY;
		goto out;
	}

	// Dma channel enable
	hal_dma_ch_enable(h_dma, (void *)pd, i2c_dma_callback);

	i2c_disable(pd->base);
	i2c_con_clear(pd->base);
	i2c_master_enable(pd->base);	
	i2c_tar(pd->base, tar);
	i2c_speed(pd->base, speed);
	i2c_scl_cnt(pd, speed);
	i2c_intr_clr(pd->base);													/// Clear all the interrupt
	//i2c_intr_mask(pd->base, I2C_INTR_MASK_ALL);		/// Mask all the interrupt
	// Set FIFO threshold
	// Note: Set to 0 to trigger dma request
	i2c_tx_fifo_tl(pd->base, 0);
	// Unmask interrupt
	//i2c_intr_unmask(pd->base, I2C_INTR_TX_EMPTY|I2C_INTR_TX_OVER|I2C_INTR_TX_ABRT);
	//NVIC_EnableIRQ(pd->irq);

	// I2c DMA request enable
	i2c_dma_tx_enable(pd->base);

	// I2c DMA burst size set	
	i2c_dma_tx_data_level(pd->base, i2c_burst_size);

	i2c_enable(pd->base);												/// All set, enable controller

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif
		
	/// Wait for DMA complete interrupt
	wait_ret = osSemaphoreWait(pd->h_sma, tmo);
	if (wait_ret == 0) {
		pd->error = I2C_ERR_TMO;
		goto out;
	}

out:

	/// Wait for activity finish
	//while (i2c_intr_raw_status(pd->base) & I2C_INTR_ACTIVITY) {
	//	i2c_intr_clr_activity(pd->base);
	//}

	//i2c_intr_mask(pd->base, I2C_INTR_TX_EMPTY|I2C_INTR_TX_OVER|I2C_INTR_TX_ABRT);
	/// I2c dma request disable
	i2c_dma_tx_disable(pd->base);

	// Dma channel disable
	if (h_dma) {
		hal_dma_ch_disable(h_dma);
		hal_dma_close(h_dma);
	}

	if (i2c_cmd_buf) {
		free(i2c_cmd_buf);
	}	

	/// Finish, Disable I2c
	i2c_finish(pd);

#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}

int hal_si2c_write_dma(void *hdl, int speed, uint8_t sar, uint8_t *buffer, uint16_t buffer_len, uint32_t tmo)
{
	i2c_dev_t *pd = (i2c_dev_t *)hdl;
	void *h_dma = NULL;
	int dma_burst_size, i2c_burst_size, wait_ret;	

	if (!pd) 
		return I2C_ERR_INVALID_PARAM;

	if (!pd->used)
		return I2C_ERR_INVALID_STATE;

	osMutexWait(pd->h_mu, osWaitForever);

	pd->slv = 3;
	pd->error = I2C_ERR_OK;
	pd->dir = I2C_DIR_WRITE;
	pd->stop = 1;
	/// Set DMA read/write burst size
	if (buffer_len <  4) { 
		dma_burst_size = DMA_CTL_TR_MSIZE_1;
		i2c_burst_size = 1;
	} else {
		dma_burst_size = DMA_CTL_TR_MSIZE_4;
		i2c_burst_size = 4;
	}
	
	i2c_disable(pd->base);
	i2c_con_clear(pd->base);
	i2c_slave_enable(pd->base);
	i2c_speed(pd->base, speed);
	i2c_sar(pd->base, sar);												/// Slave address						
	i2c_intr_clr(pd->base);		
	i2c_intr_mask(pd->base, I2C_INTR_MASK_ALL);
	i2c_intr_unmask(pd->base, I2C_INTR_RD_REQ);
	NVIC_SetPriority(pd->irq, IRQ_PRI_High);	
	NVIC_EnableIRQ(pd->irq);
	i2c_enable(pd->base);												/// All set, enable controller

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif

	/// Wait for MASTER READ REQ interrupt
	wait_ret = osSemaphoreWait(pd->h_sma, tmo);
	if (wait_ret == 0) {	// Time out
		pd->error = I2C_ERR_TMO;
		goto out;
	}

	/// Got MASTER READ REQ interrupt, set up DMA
	h_dma = hal_dma_open(DMA0_ID, 
										((pd->id == I2C0_ID) ? DMA_ID_I2C0_TX : DMA_ID_I2C1_TX),
											(uint32_t)buffer, (pd->base + I2C_REG_DATA_OFS), 
												buffer_len, 
												DMA_CTL_TR_WIDTH_8BITS, DMA_CTL_TR_WIDTH_8BITS,
													DMA_ADDR_INC, DMA_ADDR_SAME, 
														dma_burst_size, dma_burst_size, 
															DMA_AHB_MASTER_MEM,  DMA_AHB_MASTER_PERIPH, 
																DMA_TT_MEM_TO_PERF_FC_DMAC);
	if (!h_dma) {
		pd->error = I2C_ERR_DMA_BUSY;
		goto out;
	}

	/// Dma channel enable
	hal_dma_ch_enable(h_dma, NULL, NULL);

	/// I2c DMA request enable
	i2c_dma_tx_enable(pd->base);

	/// I2c DMA burst size	
	i2c_dma_tx_data_level(pd->base, i2c_burst_size);

	/// Unmask MASTER READ REQ DONE interrupt 
	i2c_intr_unmask(pd->base, I2C_INTR_RX_DONE);

	/// Wait for MASTER READ REQ DONE interrupt
	wait_ret = osSemaphoreWait(pd->h_sma, tmo);
	if (wait_ret == 0) {	// Time out
		pd->error = I2C_ERR_TMO;
		goto out;
	}

out:

	/// I2c DMA request disable
	i2c_dma_tx_disable(pd->base);

	/// Disable interrupt 
	i2c_intr_mask(pd->base, I2C_INTR_RD_REQ|I2C_INTR_RX_DONE);
	NVIC_DisableIRQ(pd->irq);

	/// Dma channel disable
	if (h_dma) {
		hal_dma_ch_disable(h_dma);
		hal_dma_close(h_dma);
	}

	/// Finish, Disable I2c
	i2c_finish(pd);

#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}

int hal_si2c_read_dma(void *hdl, int speed, uint8_t sar, uint8_t *buffer, uint16_t buffer_len, uint32_t tmo)
{
	i2c_dev_t *pd = (i2c_dev_t *)hdl;
	void *h_dma = NULL;
	int dma_burst_size, i2c_burst_size;	
	int wait_ret;

	if (!pd) 
		return I2C_ERR_INVALID_PARAM;

	if (!pd->used)
		return I2C_ERR_INVALID_STATE;

	osMutexWait(pd->h_mu, osWaitForever);

	pd->slv = 3;
	pd->error = I2C_ERR_OK;
	pd->dir = I2C_DIR_READ;
	pd->stop = 1;
	/// Set up DMA read burst size
	if (buffer_len <  4) { 
		dma_burst_size = DMA_CTL_TR_MSIZE_1;
		i2c_burst_size = 1;
	} else {
		dma_burst_size = DMA_CTL_TR_MSIZE_4;
		i2c_burst_size = 4;
	}

	/// Set up DMA for read
	h_dma = hal_dma_open(DMA1_ID, 
										((pd->id == I2C0_ID) ? DMA_ID_I2C0_RX : DMA_ID_I2C1_RX),
											(pd->base + I2C_REG_DATA_OFS), (uint32_t)buffer, 
												buffer_len, 
												DMA_CTL_TR_WIDTH_8BITS, DMA_CTL_TR_WIDTH_8BITS,
													DMA_ADDR_SAME, DMA_ADDR_INC, 
														dma_burst_size, dma_burst_size, 
															DMA_AHB_MASTER_PERIPH, DMA_AHB_MASTER_MEM, 
																DMA_TT_PERF_TO_MEM_FC_DMAC);
	if (!h_dma) {
		pd->error = I2C_ERR_DMA_BUSY;
		goto out;
	}

	/// Dma channel enable
	hal_dma_ch_enable(h_dma, (void *)pd, i2c_dma_callback);

	i2c_disable(pd->base);
	i2c_con_clear(pd->base);
	i2c_slave_enable(pd->base);
	i2c_speed(pd->base, speed);
	i2c_sar(pd->base, sar);												/// Slave address						
	i2c_intr_clr(pd->base);												/// Clear all the interrupt
	i2c_rx_fifo_tl(pd->base, 0);
	//i2c_intr_unmask(pd->base, I2C_INTR_RX_FULL|I2C_INTR_RX_OVER|I2C_INTR_RX_UNDER);
	/// I2c DMA request enable 
	i2c_dma_rx_enable(pd->base);
	// I2c DMA burst size	
	i2c_dma_rx_data_level(pd->base, (i2c_burst_size-1));
	i2c_enable(pd->base);												/// All set, enable controller

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif

	/// Wait for DMA complete interrupt
	wait_ret = osSemaphoreWait(pd->h_sma, tmo);
	if (wait_ret == 0) {
		pd->error = I2C_ERR_TMO;
		goto out;
	}

out:

	///i2c_intr_mask(pd->base, I2C_INTR_RX_FULL|I2C_INTR_RX_OVER|I2C_INTR_RX_UNDER);
	/// I2c DMA request disable
	i2c_dma_rx_disable(pd->base);

	if (h_dma) {
		/// Dma channel disable
		hal_dma_ch_disable(h_dma);
		/// DMA close
		hal_dma_close(h_dma);
	}

	/// Finish, Disable I2c
	i2c_disable(pd->base);			
	int poll_count = 0; 										
	while (i2c_enable_status(pd->base) & I2C_ES_ENABLE) {
		osDelay(1);
		poll_count += 1;
		if (poll_count > 5) {
			pd->error = I2C_ERR_RESET;
			break;
		}	
	}	

	if (pd->error == I2C_ERR_RESET) {
		i2c_reset(pd->id);
	}

#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif

	osMutexRelease(pd->h_mu);

	return pd->error;
}
#endif	/* CFG_NB_I2C */
