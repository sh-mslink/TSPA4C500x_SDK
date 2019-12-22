#include "in_config.h"

#define CFG_NB_UART (CFG_UART0_EN + CFG_UART1_EN)

/**
 ****************************************************************************************
 *
 * @file hal_uart.c
 *
 * @brief Platform uart functions  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#if CFG_NB_UART
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "in_arm.h"
#include "in_mmap.h"
#include "in_irq.h"
#include "in_debug.h"

#include ".\hal\hal_gpio.h"
#include ".\hal\hal_clk.h"
#include ".\hal\hal_uart.h"
#if CFG_PM_EN
#include ".\hal\hal_power.h"
#endif
#include ".\hal\hal_dma.h"

#include "cmsis_os.h"

/*
 * Structures
 ****************************************************************************************
 */

typedef struct {
	char id;
	char used;
	char no_intr;
	char pad;

	int error;
	uint32_t base;	
	IRQn_Type irq;

	uint32_t rts_pin;
	uint32_t cts_pin;
	uint32_t tx_pin;
	uint32_t rx_pin;

	/// OS 
	uint32_t tx_mu[4];
	osMutexId h_tx_mu;
	uint32_t rx_mu[4];
	osMutexId h_rx_mu;

	uint32_t tx_sma[2];
	osSemaphoreId h_tx_sma; 
	uint32_t rx_sma[2];
	osSemaphoreId h_rx_sma;
	uint32_t bk_sma[2];
	osSemaphoreId h_bk_sma;

	/// Uart configure paramters
	uint32_t baud_rate;

	char data_len;
	char stop_bit;
	char parity_en;
	char even_parity;
	
	char fifo_enable;
	char fifo_rx_thold;
	char fifo_rx_thold_nb;
	char fc;

	/// TX
	void *h_tx_dma;
	uint8_t *tx_buffer;
	uint32_t tx_buffer_len;
	uint32_t tx_buffer_ofs;
	void *tx_callback_arg;
	void (*tx_callback)(void *arg, int length, int error);

	/// RX
	void *h_rx_dma;
	uint8_t *rx_buffer;
	uint32_t rx_buffer_len;
	uint32_t rx_buffer_ofs;
	int rx_no_wait;
	void *rx_callback_arg;
	void (*rx_callback)(void *arg, int length, int error);

	/// Power 
#if CFG_PM_EN
	uint32_t uart_int_en;
	int power_state;
	struct pm_module pm;
#endif
} uart_dev_t;

static uart_dev_t uart_dev[CFG_NB_UART] = {
#if CFG_UART0_EN
	{
		.id = UART0_ID,
		.used = 0,
		.base = UART0_BASE,
		.irq = Uart0_IRQn,
	},
#endif	
#if CFG_UART1_EN
	{
		.id = UART1_ID,
		.used = 0,
		.base = UART1_BASE,
		.irq = Uart1_IRQn,
	},
#endif	
};

/*
 * Pin Mux
 ****************************************************************************************
 */

static int uart_pin_chk(uart_dev_t *pd, int fc)
{
	if (pd->id == UART0_ID) {
		// GPIO_0_0 = rts
		// GPIO_0_1 = cts
		// GPIO_0_2 = tx
		// GPIO_1_0 = rx
		// GPIO_2_3 = tx_bkup
		// GPIO_2_5 = rx_bkup

		// Sanity check

		// flow control
		if (fc) {		
			// Need RTX and CTS pins
			if (((CFG_GPIO_0_0>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_UART_0_RTS) {
				pd->rts_pin = CFG_GPIO_0_0;
			} else {
				return 0;
			}
			if (((CFG_GPIO_0_1>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_UART_0_CTS) {
				pd->cts_pin = CFG_GPIO_0_1;
			} else {
				return 0;
			}
		}

		// TX pin
		if (((CFG_GPIO_0_2>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_UART_0_TX) {
			if (((CFG_GPIO_2_3>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_UART_0_TX_BKUP)
				return 0;
			pd->tx_pin =  CFG_GPIO_0_2;
		} else {
			if (((CFG_GPIO_2_3>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_UART_0_TX_BKUP) {
				pd->tx_pin =  CFG_GPIO_2_3;
			} else {
				// No uart TX pin configure
				return 0;
			}
		}

		// RX pin
		if (((CFG_GPIO_1_0>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_UART_0_RX1) {
			if (((CFG_GPIO_2_5>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_UART_0_RX_BKUP)
				return 0;
			pd->rx_pin =  CFG_GPIO_1_0;
		} else {
			if (((CFG_GPIO_2_5>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_UART_0_RX_BKUP) {
				pd->rx_pin =  CFG_GPIO_2_5;
			} else {
				// No uart RX pin configure
				return 0;
			}
		}
	}

	if (pd->id == UART1_ID) {
		// GPIO_1_5 = rts
		// GPIO_1_6 = cts
		// GPIO_1_7 = tx
		// GPIO_1_8 = rx
		// GPIO_2_1 = tx_bkup
		// GPIO_2_7 = rx_bkup

		// Sanity check

		// flow control
		if (fc) {		
			// Need RTX and CTS pins
			if (((CFG_GPIO_1_5>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_UART_1_RTS) {
				pd->rts_pin = CFG_GPIO_1_5;
			} else {
				return 0;
			}
			if (((CFG_GPIO_1_6>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_UART_1_CTS1) {
				pd->cts_pin = CFG_GPIO_1_6;
			} else {
				return 0;
			}
		}

		// TX pin
		if (((CFG_GPIO_1_7>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_UART_1_TX) {
			if (((CFG_GPIO_2_1>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_UART_1_TX_BKUP)
				return 0;
			pd->tx_pin =  CFG_GPIO_1_7;
		} else {
			if (((CFG_GPIO_2_1>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_O_UART_1_TX_BKUP) {
				pd->tx_pin =  CFG_GPIO_2_1;
			} else {
				// No uart TX pin configure
				return 0;
			}
		}

		// RX pin
		if (((CFG_GPIO_1_8>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_UART1_RX1) {
			if (((CFG_GPIO_2_7>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_UART_1_RX_BKUP)
				return 0;
			pd->rx_pin =  CFG_GPIO_1_8;
		} else {
			if (((CFG_GPIO_2_7>>GPIO_CFG_MUX_SHIFT) & 0xF) == GPIO_MUX_I_UART_1_RX_BKUP) {
				pd->rx_pin =  CFG_GPIO_2_7;
			} else {
				// No uart RX pin configure
				return 0;
			}
		}
	}

	return 1;
}

static void uart_pin_mux_en(uart_dev_t *pd, int en)
{
	if (en) {
		if (pd->fc) {
			hal_gpio_pin_cfg(pd->rts_pin);
			hal_gpio_pin_cfg(pd->cts_pin);
		}
		hal_gpio_pin_cfg(pd->tx_pin);
		hal_gpio_pin_cfg(pd->rx_pin);
	} else {
		if (pd->fc) {
			hal_gpio_pin_dft(pd->rts_pin);
			hal_gpio_pin_dft(pd->cts_pin);
		}
		hal_gpio_pin_dft(pd->tx_pin);
		hal_gpio_pin_dft(pd->rx_pin);
	}
}

/*
 * PM
 ****************************************************************************************
 */

#if CFG_PM_EN
static int uart_power_state(void *arg, uint32_t *sleep_duration)
{
	uart_dev_t *pd = (uart_dev_t *)arg;
	*sleep_duration = 0xFFFF;

	return pd->power_state;
}

static void uart_power_down(void *arg, uint32_t sleep_duration)
{
	uart_dev_t *pd = (uart_dev_t *)arg;

	if (!pd->no_intr)
		pd->uart_int_en = uart_intr_enable_get(pd->base);

	return;
}
static void uart_power_up(void *arg)
{
	uart_dev_t *pd = (uart_dev_t *)arg;

	/// Set baud rate
	uart_set_baud(pd->base, hal_clk_d0_get(), pd->baud_rate);
	
	/// Set stop bits, parity, even, data_len
	uart_set_lcr(pd->base, pd->stop_bit, pd->parity_en, pd->even_parity, pd->data_len);

	/// Set FIFO control 
	uart_set_fcr(pd->base, pd->fifo_enable, 0, pd->fifo_rx_thold, 0);

	/// Set Flow control
	uart_auto_fc(pd->base, pd->fc);

	
	
	/// Pin mux
	//uart_pin_mux_en(pd, 1);

	/// Restore interrupt
	if (!pd->no_intr) {
		uart_intr_enable(pd->base, pd->uart_int_en);
		NVIC_SetPriority(pd->irq, IRQ_PRI_High);	
		NVIC_EnableIRQ(pd->irq);
	}
}
#endif	// CFG_PM_EN 

/*
 * Isr
 ****************************************************************************************
 */

static void uart_isr_handler(uart_dev_t *pd)
{
	uint32_t iid;

	iid = uart_intr_status(pd->base);

	if (iid == UART_IT_ID_LINE_STATUS) {
		uint32_t lsr = uart_line_status(pd->base);

//PRINTD(DBG_ERR, "lsr=%08X\r\n", lsr);

		/// Disable UART LINE interrupt
		uart_intr_disable(pd->base, UART_IER_ELSI);

		if (lsr & UART_LSR_BI) {

			if (pd->h_bk_sma)
				osSemaphoreRelease(pd->h_bk_sma);
		} else {
			if (pd->h_rx_dma) {
				// Disable DMA
				hal_dma_ch_disable(pd->h_rx_dma);
				hal_dma_close(pd->h_rx_dma);
				pd->h_rx_dma = NULL;
			}

			if (lsr & UART_LSR_OE)
				pd->error = UART_ERR_OE;
			if (lsr & UART_LSR_PE)
				pd->error = UART_ERR_PE;
			if (lsr & UART_LSR_FE)
				pd->error = UART_ERR_FE;

			if (pd->rx_callback) {
				pd->rx_callback(pd->rx_callback_arg, 0, pd->error);
#if CFG_PM_EN
				pd->power_state = PM_DEEP_SLEEP;
#endif
			} else {
				if (pd->h_rx_sma)
					osSemaphoreRelease(pd->h_rx_sma);
			}
		}
	} 

	if (iid == UART_IT_ID_RCVR_DATA) {
		if (!pd->h_rx_dma) {
			uint16_t oft = pd->rx_buffer_ofs;

			for (int i = 0; i < pd->fifo_rx_thold_nb; i++) {
				if (oft >= pd->rx_buffer_len)   	
					break;
				pd->rx_buffer[oft] = uart_read_data(pd->base);
				oft += 1;
			}

			if (oft < pd->rx_buffer_len) {
				pd->rx_buffer_ofs = oft;
			} else {
				/// Disable UART RX interrupt
				uart_intr_disable(pd->base, UART_IER_ERBFI);

				/// Call back to user
				if (pd->rx_callback) { 
					pd->rx_callback(pd->rx_callback_arg, oft, UART_ERR_OK);
#if CFG_PM_EN
					pd->power_state = PM_DEEP_SLEEP;
#endif
				} else {
					pd->error = UART_ERR_OK;
					if (pd->h_rx_sma)
						osSemaphoreRelease(pd->h_rx_sma);
				}
			}
		}
	}

	if (iid == UART_IT_ID_CHAR_TIME_OUT) {
		uint16_t oft = pd->rx_buffer_ofs;

		if (pd->h_rx_dma) {
			// Read the total size that DMA tranfer
			oft = hal_dma_get_tran_len(pd->h_rx_dma);
//PRINTD(DBG_TRACE, "Uart Dma: size = %d\n", oft);
			// Disable DMA
			hal_dma_ch_disable(pd->h_rx_dma);
			hal_dma_close(pd->h_rx_dma);
			pd->h_rx_dma = NULL;
		}

		while (uart_line_status(pd->base) & UART_LSR_DR) {
			if (oft >= pd->rx_buffer_len)   	
				break;

			pd->rx_buffer[oft] = uart_read_data(pd->base);
			oft += 1;
		}			
		pd->rx_buffer_ofs = oft;
		if ((oft >= pd->rx_buffer_len) || pd->rx_no_wait) {
			
//PRINTD(DBG_TRACE, "Uart: rx size = %d\n", oft);

			/// Disable UART RX interrupt
			uart_intr_disable(pd->base, UART_IER_ERBFI);

			/// Call back to user
			if (pd->rx_callback) { 
				pd->rx_callback(pd->rx_callback_arg, oft, UART_ERR_OK);
#if CFG_PM_EN
				pd->power_state = PM_DEEP_SLEEP;
#endif
			} else {
				pd->error = UART_ERR_OK;
				if (pd->h_rx_sma)
					osSemaphoreRelease(pd->h_rx_sma);
			}
		}
	} 

	if (iid == UART_IT_ID_THR_EMPTY) {
		uint16_t oft = pd->tx_buffer_ofs;

		while (uart_usr(pd->base) & UART_USR_TFNF) {
			if (oft >= pd->tx_buffer_len) 
				break;
			uart_write_data(pd->base, pd->tx_buffer[oft]);
			oft += 1;
		}

		if (oft < pd->tx_buffer_len) {
			pd->tx_buffer_ofs = oft;
		} else {
			/// Disable UART TX interrupt
			uart_intr_disable(pd->base, UART_IER_ETBEI);

			/// Call back to user
			if (pd->tx_callback) { 
				pd->tx_callback(pd->tx_callback_arg, oft, UART_ERR_OK);
#if CFG_PM_EN
				pd->power_state = PM_DEEP_SLEEP;
#endif
			} else {
				pd->error = UART_ERR_OK;
				if (pd->h_tx_sma)
					osSemaphoreRelease(pd->h_tx_sma);
			}
		}
	}

	if (iid == UART_IT_ID_MODEM_STATUS) {		
		uint32_t msr = uart_modem_status(pd->base);
		//TODO???

	}

	if (iid == UART_IT_ID_BUSY_DET) {		
		uint32_t usr = uart_usr(pd->base);
		//TODO???
	}
} 

__irq void UART0_Handler(void)
{
	for (int i = 0; i < CFG_NB_UART; i++) {
		if (uart_dev[i].id == UART0_ID)
			uart_isr_handler(&uart_dev[i]);		
	}
}

__irq void UART1_Handler(void)
{
	for (int i = 0; i < CFG_NB_UART; i++) {
		if (uart_dev[i].id == UART1_ID)
			uart_isr_handler(&uart_dev[i]);		
	}
}

/*
 * Dma
 ****************************************************************************************
 */
static void uart_dma_isr_cb(int id, void *arg, int status)
{
	uart_dev_t *pd = (uart_dev_t *)arg;
	
	
	if (status & DMA_IT_STATUS_ERR) {
PRINTD(DBG_ERR, "Dma Error intr...\n");
		pd->error = UART_ERR_DMA;
	}

	if (id == DMA1_ID) {
//PRINTD(DBG_ERR, "Dma RX intr...\n");
		//RX dma
		// This should not happened
		if (pd->h_rx_dma) {
			// Disable DMA
			hal_dma_ch_disable(pd->h_rx_dma);
			hal_dma_close(pd->h_rx_dma);
			pd->h_rx_dma = NULL;

			if (pd->rx_callback) { 
				pd->rx_callback(pd->rx_callback_arg, 0, UART_ERR_DMA);
#if CFG_PM_EN
				pd->power_state = PM_DEEP_SLEEP;
#endif
			} else {
				if (pd->h_rx_sma)
					osSemaphoreRelease(pd->h_rx_sma);
			}
		}	
	}

	if (id == DMA0_ID) {
		// TX dma completed
		if (pd->h_tx_dma) {
			// Disable DMA
			hal_dma_ch_disable(pd->h_tx_dma);
			hal_dma_close(pd->h_tx_dma);
			pd->h_tx_dma = NULL;
 
			// Make sure Uart is not busy before we exit 
			while (uart_usr(pd->base) & UART_USR_BUSY);

			if (pd->tx_callback) { 
				pd->tx_callback(pd->tx_callback_arg, pd->tx_buffer_len, pd->error);
#if CFG_PM_EN
				pd->power_state = PM_DEEP_SLEEP;
#endif
			} else {
				if (pd->h_tx_sma)
					osSemaphoreRelease(pd->h_tx_sma);
			}
		}
	}
}

/*
 * APIs
 ****************************************************************************************
 */

void *hal_uart_open(int id, int baud_rate, int data_len, int stop_bit, int parity_en, int even_parity, int fifo_enable, int fifo_rx_thold, int fc, int no_intr)
{
	uart_dev_t *pd;
	int i;

	if (!baud_rate)
		return NULL;

	if ((data_len < 5) || (data_len > 8))
		return NULL;

	for (i = 0; i < CFG_NB_UART; i++) {
		if ((uart_dev[i].id == id) && (uart_dev[i].used == 0)) {
			pd = &uart_dev[i];
			break;
		}
	}

	if (!pd)
		return NULL;

	// Check pin mux
	if (!uart_pin_chk(pd, fc))
		return NULL;

	/// OS
	{
		osMutexDef_t def;
		def.mutex = pd->tx_mu;
		pd->h_tx_mu = osMutexCreate(&def);
		if (!pd->h_tx_mu) {
			return NULL;
		}

		def.mutex = pd->rx_mu;
		pd->h_rx_mu = osMutexCreate(&def);
		if (!pd->h_rx_mu) {
			goto fail;
		}
	}

	{
		osSemaphoreDef_t def;
		def.semaphore = (void *)pd->tx_sma;
		pd->h_tx_sma = osSemaphoreCreate(&def, 0);
		if (!pd->h_tx_sma) {
			goto fail;
		}
		def.semaphore = (void *)pd->rx_sma;
		pd->h_rx_sma = osSemaphoreCreate(&def, 0);
		if (!pd->h_rx_sma) {
			goto fail;
		}
		def.semaphore = (void *)pd->bk_sma;
		pd->h_bk_sma = osSemaphoreCreate(&def, 0);
		if (!pd->h_bk_sma) {
			goto fail;
		}

	}

        /// Save Uart Configuration
	pd->baud_rate = baud_rate;
	pd->data_len = data_len;
	pd->stop_bit = stop_bit;
	pd->parity_en = parity_en;
	pd->even_parity = even_parity;
	pd->fifo_enable = fifo_enable;
	pd->fifo_rx_thold = fifo_rx_thold;
	pd->fc = fc;
	pd->no_intr = no_intr;

    
	// enable uart clock
	hal_clk_uart_en(pd->id, 1);

	// enable uart pin mux
	uart_pin_mux_en(pd, 1);

	/// Set baud rate
	uart_set_baud(pd->base, hal_clk_d0_get(), baud_rate);
	
	/// Set stop bits, parity, even, data_len
	uart_set_lcr(pd->base, stop_bit, parity_en, even_parity, data_len);

	/// Set FIFO control 
	uart_set_fcr(pd->base, fifo_enable, 0, fifo_rx_thold, 1);

	/// Set Flow control
	uart_auto_fc(pd->base, fc);

	/// Mask all interrupt
	uart_intr_disable(pd->base, UART_IER_ETBEI|UART_IER_ELSI|UART_IER_ERBFI|UART_IER_EDSSI);
	if (!no_intr) {
		NVIC_ClearPendingIRQ(pd->irq);
		NVIC_SetPriority(pd->irq, IRQ_PRI_High);	
		NVIC_EnableIRQ(pd->irq);
	}	

	if (fifo_rx_thold == UART_RT_QUARTER_FULL) {
		pd->fifo_rx_thold_nb = UART_FIFO_DEPTH/4;
	} else if (fifo_rx_thold == UART_RT_HALF_FULL) {
		pd->fifo_rx_thold_nb = UART_FIFO_DEPTH/2;
	} else if (fifo_rx_thold == UART_RT_2_LESS_FULL) {
		pd->fifo_rx_thold_nb = UART_FIFO_DEPTH-2;
	} else {
		pd->fifo_rx_thold_nb = 1;
	}

#if CFG_PM_EN
	pd->pm.power_state = uart_power_state;
	pd->pm.power_down = uart_power_down;
	pd->pm.power_up = uart_power_up;
	pd->pm.arg = (void *)pd; 
	hal_pm_reg_mod(&pd->pm);
	pd->power_state = PM_DEEP_SLEEP;
#endif

	pd->used = 1;
	return ((void *)pd);

fail:

	if (pd->h_tx_mu) {
		osMutexDelete(pd->h_tx_mu);
		pd->h_tx_mu = NULL;
	}

	if (pd->h_rx_mu) {
		osMutexDelete(pd->h_rx_mu);
		pd->h_rx_mu = NULL;
	}	

	if (pd->h_tx_sma) {
		osSemaphoreDelete(pd->h_tx_sma);
		pd->h_tx_sma = NULL;
	}

	if (pd->h_rx_sma) {
		osSemaphoreDelete(pd->h_rx_sma);
		pd->h_rx_sma = NULL;
	}
	if (pd->h_bk_sma) {
		osSemaphoreDelete(pd->h_bk_sma);
		pd->h_bk_sma = NULL;
	}
	return NULL;
}

void hal_uart_close(void *hdl)
{
	uart_dev_t *pd = (uart_dev_t *)hdl;

	if (!pd)
		return;

	pd->used = 0;	

	// Set pin mux to default to prevent further receive
	uart_pin_mux_en(pd, 0);

	// make sure uart is not busy
	while (uart_usr(pd->base) & 0x1);

	// disable interrupt
	NVIC_DisableIRQ(pd->irq);
	uart_intr_disable(pd->base, UART_IER_ETBEI|UART_IER_ERBFI|UART_IER_ELSI);
	NVIC_ClearPendingIRQ(pd->irq);

	// disable fifo
	uart_fifo_disable(pd->base);	

	// set baud to 0 to close uart
	uart_set_baud(pd->base, hal_clk_d0_get(), 0);
	
	if (pd->h_rx_dma) {
		// Disable DMA
		hal_dma_ch_disable(pd->h_rx_dma);
		hal_dma_close(pd->h_rx_dma);
		pd->h_rx_dma = NULL;
	}

	if (pd->h_tx_mu) {
		osMutexDelete(pd->h_tx_mu);
		pd->h_tx_mu = NULL;
	}

	if (pd->h_rx_mu) {
		osMutexDelete(pd->h_rx_mu);
		pd->h_rx_mu = NULL;
	}	

	if (pd->h_tx_sma) {
		osSemaphoreDelete(pd->h_tx_sma);
		pd->h_tx_sma = NULL;
	}

	if (pd->h_rx_sma) {
		osSemaphoreDelete(pd->h_rx_sma);
		pd->h_rx_sma = NULL;
	}
	if (pd->h_bk_sma) {
		osSemaphoreDelete(pd->h_bk_sma);
		pd->h_bk_sma = NULL;
	}
#if CFG_PM_EN
	hal_pm_unreg_mod(&pd->pm);
#endif

	// clock
	hal_clk_uart_en(pd->id, 0);
}

void hal_uart_putc(void *hdl, char c)
{
	uart_dev_t *pd = (uart_dev_t *)hdl;

	uart_xmit_ready(pd->base);
	uart_write_data(pd->base, c);
}

int hal_uart_xmit_poll(void *hdl, uint8_t *buffer, uint32_t buffer_len)
{
	uart_dev_t *pd = (uart_dev_t *)hdl;
	int err = UART_ERR_OK;

	if (!pd)
		return UART_ERR_INVALID_PARAM; 	

	if (!buffer)
		return UART_ERR_INVALID_PARAM; 	

	osMutexWait(pd->h_tx_mu, osWaitForever);
	for (int i = 0; i < buffer_len; i++) {
		uart_xmit_ready(pd->base);
		uart_write_data(pd->base, buffer[i]);
	}
	osMutexRelease(pd->h_tx_mu);

	return err;
}

int hal_uart_rcvd_poll(void *hdl, uint8_t *buffer, uint32_t buffer_len)
{
	uart_dev_t *pd = (uart_dev_t *)hdl;
	int err = UART_ERR_OK;

	if (!pd)
		return UART_ERR_INVALID_PARAM; 	

	if (!buffer)
		return UART_ERR_INVALID_PARAM; 	

	osMutexWait(pd->h_rx_mu, osWaitForever);
	for (int i = 0; i < buffer_len; i++) {
		uart_rcvd_ready(pd->base);
		buffer[i] = uart_read_data(pd->base);
	}
	osMutexRelease(pd->h_rx_mu);

	return err;
}

int hal_uart_xmit_intr(void *hdl, uint8_t *buffer, uint32_t buffer_len, void *cb_arg, void (*callback)(void *arg, int length, int error))
{
	uart_dev_t *pd = (uart_dev_t *)hdl;
	int err = UART_ERR_OK;

	if (!pd)
		return UART_ERR_INVALID_PARAM; 	

	if (!buffer)
		return UART_ERR_INVALID_PARAM; 	

	if (pd->no_intr)
		return UART_ERR_INVALID_PARAM; 	

	osMutexWait(pd->h_tx_mu, osWaitForever);

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif

	pd->tx_buffer = buffer;
	pd->tx_buffer_len = buffer_len;
	pd->tx_buffer_ofs = 0;
	pd->tx_callback_arg = cb_arg;
	pd->tx_callback = callback;

	/// THR empty Interrupt 
	uart_intr_enable(pd->base, UART_IER_ETBEI);		

	if (!callback) {
		osSemaphoreWait(pd->h_tx_sma, osWaitForever);
		err = pd->error;
#if CFG_PM_EN
		pd->power_state = PM_DEEP_SLEEP;
#endif
	} else {
		err = UART_ERR_PEND;
	}

	osMutexRelease(pd->h_tx_mu);
	return err;
}
int hal_uart_clear_rx_fifo(void* hdl)
{
	uart_dev_t *pd = (uart_dev_t *)hdl;
	int err = UART_ERR_OK;

	if (!pd)
		return UART_ERR_INVALID_PARAM; 	
	osMutexWait(pd->h_rx_mu, osWaitForever);
	while (uart_line_status(pd->base) & UART_LSR_DR) {
		uart_read_data(pd->base);
	}	
	osMutexRelease(pd->h_rx_mu);
	return err;

}

int hal_uart_rcvd_intr(void *hdl, uint8_t *buffer, uint32_t buffer_len, void *cb_arg, void (*callback)(void *arg, int length, int error))
{
	uart_dev_t *pd = (uart_dev_t *)hdl;
	int err = UART_ERR_OK;

	if (!pd)
		return UART_ERR_INVALID_PARAM; 	

	if (!buffer)
		return UART_ERR_INVALID_PARAM; 	

	if (pd->no_intr)
		return UART_ERR_INVALID_PARAM; 	

	osMutexWait(pd->h_rx_mu, osWaitForever);

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif

	pd->rx_buffer = buffer;
	pd->rx_buffer_len = buffer_len;
	pd->rx_buffer_ofs = 0;
	pd->rx_callback_arg = cb_arg;
	pd->rx_callback = callback;
	pd->rx_no_wait = 0;

	/// THR empty, Line 
	uart_intr_enable(pd->base, (UART_IER_ERBFI | UART_IER_ELSI));		

	if (!callback) {
		osSemaphoreWait(pd->h_rx_sma, osWaitForever);
		err = pd->error;
#if CFG_PM_EN
		pd->power_state = PM_DEEP_SLEEP;
#endif
	} else {
		err = UART_ERR_PEND;
	}

	osMutexRelease(pd->h_rx_mu);
	return err;
}
int hal_uart_rcvd_intr_tmo(void *hdl, uint8_t *buffer, uint32_t buffer_len, uint32_t *rx_len, uint32_t tmo)
{
	uart_dev_t *pd = (uart_dev_t *)hdl;
	int err = UART_ERR_OK;

	if (!pd)
		return UART_ERR_INVALID_PARAM; 	

	if (!buffer || !buffer_len)
		return UART_ERR_INVALID_PARAM; 	
	
	if (!tmo)
		return UART_ERR_INVALID_PARAM; 	

	if (pd->no_intr)
		return UART_ERR_INVALID_PARAM; 	

	osMutexWait(pd->h_rx_mu, osWaitForever);

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif
	pd->fifo_rx_thold_nb--;//need left one byte in FIFO to trigger timeout IRQ

	pd->rx_buffer = buffer;
	pd->rx_buffer_len = buffer_len;
	pd->rx_buffer_ofs = 0;
	pd->rx_callback_arg = NULL;
	pd->rx_callback = NULL;
	pd->rx_no_wait = 1;

	/// THR empty, Line 
	uart_intr_enable(pd->base, (UART_IER_ERBFI | UART_IER_ELSI));		

	osSemaphoreWait(pd->h_rx_sma, tmo);
	uart_intr_disable(pd->base, UART_IER_ERBFI| UART_IER_ELSI);

	pd->fifo_rx_thold_nb++;
	err = pd->error;
#if CFG_PM_EN
		pd->power_state = PM_DEEP_SLEEP;
#endif
	*rx_len = pd->rx_buffer_ofs;
	osMutexRelease(pd->h_rx_mu);
	return err;
}

int hal_uart_flow_on(void *hdl)
{
	uart_dev_t *pd = (uart_dev_t *)hdl;

	if (!pd)
		return UART_ERR_INVALID_PARAM; 	

	uart_rts_on(pd->base);

	return UART_ERR_OK;
}

int hal_uart_flow_off(void *hdl)
{
	uart_dev_t *pd = (uart_dev_t *)hdl;

	if (!pd)
		return UART_ERR_INVALID_PARAM; 	

	uart_rts_off(pd->base);

	return UART_ERR_OK;
}

int hal_uart_wait_break(void *hdl)
{
	uart_dev_t *pd = (uart_dev_t *)hdl;
	
	if (!pd)
		return UART_ERR_INVALID_PARAM; 	

	uart_intr_enable(pd->base, UART_IER_ELSI);		
	
	osSemaphoreWait(pd->h_bk_sma, osWaitForever);
	
	return UART_ERR_OK;
}

int hal_uart_xmit_dma(void *hdl, uint8_t *buffer, uint32_t buffer_len, void *arg, void (*callback)(void *arg, int length, int error))
{
	uart_dev_t *pd = (uart_dev_t *)hdl;
	int err = UART_ERR_OK;

	if (!pd)
		return UART_ERR_INVALID_PARAM; 	

	if (!buffer)
		return UART_ERR_INVALID_PARAM; 	

	if (buffer_len == 0)
		return UART_ERR_INVALID_PARAM; 	

	// DMA burst size	
	int burst_size;
	if (pd->fifo_rx_thold_nb == UART_FIFO_DEPTH/4) {
		burst_size = DMA_CTL_TR_MSIZE_4;
	} else if (pd->fifo_rx_thold_nb == UART_FIFO_DEPTH/2) {
		burst_size = DMA_CTL_TR_MSIZE_8;
	} else if (pd->fifo_rx_thold_nb == UART_FIFO_DEPTH-2) {
		burst_size = DMA_CTL_TR_MSIZE_8;
	} else {
		burst_size = DMA_CTL_TR_MSIZE_1;
	}

	osMutexWait(pd->h_tx_mu, osWaitForever);

	// Find a available DMA channel
	pd->h_tx_dma = hal_dma_open(DMA0_ID, 
												((pd->id == UART0_ID) ? DMA_ID_UART0_TX : DMA_ID_UART1_TX),
													(uint32_t)buffer,
														(uint32_t)(pd->base + UART_REG_THR_OFS), 
															buffer_len,
																DMA_CTL_TR_WIDTH_8BITS, 
																	DMA_CTL_TR_WIDTH_8BITS,
																		DMA_ADDR_INC, 
																			DMA_ADDR_SAME, 
																				burst_size, 
																					burst_size,
																						DMA_AHB_MASTER_MEM,  
																							DMA_AHB_MASTER_PERIPH, 
																								DMA_TT_MEM_TO_PERF_FC_DMAC);
	if (!pd->h_tx_dma) {
		err = UART_DMA_NOT_AVAIL;
		goto out;
	}												

	// Prepare...
	pd->tx_buffer = buffer;
	pd->tx_buffer_len = buffer_len;
	pd->tx_buffer_ofs = 0;
	pd->tx_callback_arg = arg;
	pd->tx_callback = callback;
	pd->error = err;
#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif

	// DMA channel enable
	hal_dma_ch_enable(pd->h_tx_dma, (void *)pd, uart_dma_isr_cb);

	if (!callback) {
		// Block call	
		osSemaphoreWait(pd->h_tx_sma, osWaitForever);
		err = pd->error;
#if CFG_PM_EN
		pd->power_state = PM_DEEP_SLEEP;
#endif
	} else {
		err = UART_ERR_PEND;
	}

out:

	osMutexRelease(pd->h_tx_mu);

	return err;
}

int hal_uart_rcvd_dma(void *hdl, uint8_t *buffer, uint32_t buffer_len, uint32_t *actual_rx_len, void *arg, void (*callback)(void *arg, int length, int error))
{
	uart_dev_t *pd = (uart_dev_t *)hdl;
	int err = UART_ERR_OK;

	if (!pd)
		return UART_ERR_INVALID_PARAM; 	

	if (!buffer)
		return UART_ERR_INVALID_PARAM; 	

	if (buffer_len == 0)
		return UART_ERR_INVALID_PARAM; 	

	//
	// DMA burst size needs to be less than the uart's threshold value.  This is to make sure that we always have data
	//			in the FIFO to trigger the time out for the case where actual RX length is not the same as the user's request.
	//.	
	int burst_size;
	if (pd->fifo_rx_thold_nb == UART_FIFO_DEPTH/4) {
		burst_size = DMA_CTL_TR_MSIZE_1;
	} else if (pd->fifo_rx_thold_nb == UART_FIFO_DEPTH/2) {
		burst_size = DMA_CTL_TR_MSIZE_4;
	} else if (pd->fifo_rx_thold_nb == UART_FIFO_DEPTH-2) {
		burst_size = DMA_CTL_TR_MSIZE_8;
	} else {
		// This will not satisfy the time out condition
		return UART_ERR_INVALID_PARAM; 	
	}

	osMutexWait(pd->h_rx_mu, osWaitForever);

	if (actual_rx_len)
		*actual_rx_len = 0;

	// Find a available DMA channel
	pd->h_rx_dma = hal_dma_open(DMA1_ID, 
												((pd->id == UART0_ID) ? DMA_ID_UART0_RX : DMA_ID_UART1_RX),
													(uint32_t)(pd->base + UART_REG_RBR_OFS),
														(uint32_t)buffer, 
															buffer_len,
																DMA_CTL_TR_WIDTH_8BITS, 
																	DMA_CTL_TR_WIDTH_8BITS,
																		DMA_ADDR_SAME, 
																			DMA_ADDR_INC, 
																				burst_size, 
																					burst_size,
																						DMA_AHB_MASTER_PERIPH,  
																							DMA_AHB_MASTER_MEM, 
																								DMA_TT_PERF_TO_MEM_FC_DMAC);
	if (!pd->h_rx_dma) {
		err = UART_DMA_NOT_AVAIL;
		goto out;
	}						

	// Prepare...
	pd->rx_buffer = buffer;
	pd->rx_buffer_len = buffer_len;
	pd->rx_buffer_ofs = 0;
	pd->rx_callback_arg = arg;
	pd->rx_callback = callback;
	pd->rx_no_wait = 1;
	pd->error = err;						

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif

	// Uart: enable RX interrupt (including time out) and line status 
	uart_intr_enable(pd->base, (UART_IER_ERBFI | UART_IER_ELSI));		

	// DMA channel enable 
	hal_dma_ch_enable(pd->h_rx_dma, (void *)pd, uart_dma_isr_cb);

	if (!callback) {		
		// Block call 
		osSemaphoreWait(pd->h_rx_sma, osWaitForever);
		err = pd->error;
		if (actual_rx_len)
			*actual_rx_len = pd->rx_buffer_ofs;
#if CFG_PM_EN
		pd->power_state = PM_DEEP_SLEEP;
#endif
	} else {
		// Non-block call
		err = UART_ERR_PEND;
	}

out:

	osMutexRelease(pd->h_rx_mu);

	return err;
}

int hal_uart_rcvd_dma_tmo(void *hdl, uint8_t *buffer, uint32_t buffer_len, uint32_t *actual_rx_len, uint32_t tmo)
{
	uart_dev_t *pd = (uart_dev_t *)hdl;
	int err = UART_ERR_OK;

	if (!pd)
		return UART_ERR_INVALID_PARAM; 	

	if (!buffer)
		return UART_ERR_INVALID_PARAM; 	

	if (buffer_len == 0)
		return UART_ERR_INVALID_PARAM; 	

	//
	// DMA burst size needs to be less than the uart's threshold value.  This is to make sure that we always have data
	//			in the FIFO to trigger the time out for the case where actual RX length is not the same as the user's request.
	//.	
	int burst_size;
	if (pd->fifo_rx_thold_nb == UART_FIFO_DEPTH/4) {
		burst_size = DMA_CTL_TR_MSIZE_1;
	} else if (pd->fifo_rx_thold_nb == UART_FIFO_DEPTH/2) {
		burst_size = DMA_CTL_TR_MSIZE_4;
	} else if (pd->fifo_rx_thold_nb == UART_FIFO_DEPTH-2) {
		burst_size = DMA_CTL_TR_MSIZE_8;
	} else {
		// This will not satisfy the time out condition
		return UART_ERR_INVALID_PARAM; 	
	}

	osMutexWait(pd->h_rx_mu, osWaitForever);

	if (actual_rx_len)
		*actual_rx_len = 0;

	// Find a available DMA channel
	pd->h_rx_dma = hal_dma_open(DMA1_ID, 
												((pd->id == UART0_ID) ? DMA_ID_UART0_RX : DMA_ID_UART1_RX),
													(uint32_t)(pd->base + UART_REG_RBR_OFS),
														(uint32_t)buffer, 
															buffer_len,
																DMA_CTL_TR_WIDTH_8BITS, 
																	DMA_CTL_TR_WIDTH_8BITS,
																		DMA_ADDR_SAME, 
																			DMA_ADDR_INC, 
																				burst_size, 
																					burst_size,
																						DMA_AHB_MASTER_PERIPH,  
																							DMA_AHB_MASTER_MEM, 
																								DMA_TT_PERF_TO_MEM_FC_DMAC);
	if (!pd->h_rx_dma) {
		err = UART_DMA_NOT_AVAIL;
		goto out;
	}						

	// Prepare...
	pd->rx_buffer = buffer;
	pd->rx_buffer_len = buffer_len;
	pd->rx_buffer_ofs = 0;
	pd->rx_callback_arg = NULL;
	pd->rx_callback = NULL;
	pd->rx_no_wait = 1;
	pd->error = err;						

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif

	// Uart: enable RX interrupt (including time out) and line status 
	uart_intr_enable(pd->base, (UART_IER_ERBFI | UART_IER_ELSI));		

	// DMA channel enable 
	hal_dma_ch_enable(pd->h_rx_dma, (void *)pd, uart_dma_isr_cb);

		
	// Block call 
	osSemaphoreWait(pd->h_rx_sma, tmo);
	err = pd->error;
	if (actual_rx_len)
		*actual_rx_len = pd->rx_buffer_ofs;
	//uart_intr_disable(pd->base, (UART_IER_ERBFI | UART_IER_ELSI));
	if (pd->h_rx_dma) {
		// Disable DMA
		hal_dma_ch_disable(pd->h_rx_dma);
		hal_dma_close(pd->h_rx_dma);
		pd->h_rx_dma = NULL;
	}
#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif
	
out:

	osMutexRelease(pd->h_rx_mu);

	return err;
}

#endif	/* CFG_NB_UART */ 
