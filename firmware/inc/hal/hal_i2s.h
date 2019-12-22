/**
 ****************************************************************************************
 *
 * @file hal_i2s.h
 *
 * @brief I2S Profile
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */
 
#ifndef HAL_I2S_H
#define HAL_I2S_H

/**
 ****************************************************************************************
 * @defgroup HAL_I2S I2S Profile  
 * @ingroup HAL
 * @brief  HAL I2S
 * @{
 ****************************************************************************************
 */

#include "stdint.h"
#include "in_mmap.h"

/*
 * Defines
 ****************************************************************************************
 */
 
#define I2S_CH0_BASE_OFS	(0x20)
#define I2S_CH1_BASE_OFS	(0x60)
 
#define MI2S_CH0_BASE		(MI2S_BASE + I2S_CH0_BASE_OFS)
#define MI2S_CH1_BASE		(MI2S_BASE + I2S_CH1_BASE_OFS)

#define SI2S_CH0_BASE		(SI2S_BASE + I2S_CH0_BASE_OFS)
#define SI2S_CH1_BASE		(SI2S_BASE + I2S_CH1_BASE_OFS)

#define I2S_REG_IER_OFS		0x00000000UL
#define I2S_REG_IRER_OFS		0x00000004UL
#define I2S_REG_ITER_OFS		0x00000008UL
#define I2S_REG_CER_OFS		0x0000000CUL
#define I2S_REG_CCR_OFS		0x00000010UL
#define I2S_REG_RXFFR_OFS	0x00000014UL
#define I2S_REG_TXFFR_OFS	0x00000018UL
#define I2S_REG_LRBR_OFS	0x00000000UL
#define I2S_REG_LTHR_OFS		0x00000000UL
#define I2S_REG_RRBR_OFS	0x00000004UL
#define I2S_REG_RTHR_OFS	0x00000004UL
#define I2S_REG_RER_OFS		0x00000008UL
#define I2S_REG_TER_OFS		0x0000000CUL
#define I2S_REG_RCR_OFS		0x00000010UL
#define I2S_REG_TCR_OFS		0x00000014UL
#define I2S_REG_ISR_OFS		0x00000018UL
#define I2S_REG_IMR_OFS		0x0000001CUL
#define I2S_REG_ROR_OFS		0x00000020UL
#define I2S_REG_TOR_OFS		0x00000024UL
#define I2S_REG_RFCR_OFS	0x00000028UL
#define I2S_REG_TFCR_OFS		0x0000002CUL
#define I2S_REG_RFF_OFS		0x00000030UL
#define I2S_REG_TFF_OFS		0x00000034UL
#define I2S_REG_RXDMA_OFS	0x000001C0UL
#define I2S_REG_RRXDMA_OFS	0x000001C4UL
#define I2S_REG_TXDMA_OFS	0x000001C8UL
#define I2S_REG_RTXDMA_OFS	0x000001CCUL

/*
 * Enumerations
 ****************************************************************************************
 */

/// I2S Core ID
enum i2s_id {
	/// I2S Master Core.
	MI2S_ID = 1,
	/// I2S Slave Core.
	SI2S_ID = 2,
};

/// I2S Core max word size
enum i2s_word_size {
	/// Max sample word size is 16 bits.
	I2S_WS_16BITS = 16,
	/// Max sample word size is 24 bits.
	I2S_WS_24BITS = 24,
	/// Max sample word size is 32 bits.
	I2S_WS_32BITS = 32
};

/// I2S sample rate 
enum i2s_sr {
	/// Sample rate at 8Khz 
	I2S_SR_8K = 8000,
	/// Sample rate at 16Khz 
	I2S_SR_16K = 16000,
	/// Sample rate at 24Khz 
	I2S_SR_24K = 24000,
	/// Sample rate at 32Khz 
	I2S_SR_32K = 32000,
	/// Sample rate at 36Khz 
	I2S_SR_36K = 36000,
	/// Sample rate at 44.1Khz 
	I2S_SR_44K = 44100,
	/// Sample rate at 48Khz 
	I2S_SR_48K = 48000,
};

/// I2S data type 
enum i2s_type {
	/// Mono data
	I2S_MONO = 1,
	/// Stereo data
	I2S_STEREO,
};

/// Each I2S Core can have 2 Channel 
enum i2s_ch_id {
	/// I2S Channel 1.
	I2S_CH_1,
	/// I2S Channel 2.
	I2S_CH_2,
	/// I2S max channel
	I2S_CH_MAX,
};

/// Each I2S channel can be either TX or RX
enum i2s_ch_dir {
	/// Transmit
	I2S_DIR_TX = 1,
	/// Receive
	I2S_DIR_RX = 2,
};

/// Each I2S channel word size
enum i2s_ch_word_sz {
	/// Don't care
	I2S_CH_WS_0_BIT = 0,
	/// Channel word size is 12 bits
	I2S_CH_WS_12_BITS,
	/// Channel word size is 16 bits
	I2S_CH_WS_16_BITS,
	/// Channel word size is 20 bits
	I2S_CH_WS_20_BITS,
	/// Channel word size is 24 bits
	I2S_CH_WS_24_BITS,
	/// Channel word size is 32 bits
	I2S_CH_WS_32_BITS,
};

/// I2S driver return code
enum i2s_error {
	/// No error. Good. 
	I2S_ERR_OK = 0,
	/// Error. Invalid param.
	I2S_ERR_INVALID_PARAM = -1,
	/// Error. Invalid state.
	I2S_ERR_INVALID_STATE = -2,
	/// Error. I2S channel RX overflow.
	I2S_ERR_RX_OV = -4,
	/// Error. I2S channel TX overflow.
	I2S_ERR_TX_OV = -5,
	/// Error. DMA is not available.
	I2S_ERR_DMA_NOT_AVAIL = -6,
	/// Error. DMA tranfer.
	I2S_ERR_DMA_TRAN = -7,
} ;

/*
 * Inline Functions
 ****************************************************************************************
 */

static __inline void i2s_enable(uint32_t base)
{
	WR_WORD((base + I2S_REG_IER_OFS), 1);
}

static __inline void i2s_disable(uint32_t base)
{
	WR_WORD((base + I2S_REG_IER_OFS), 0);
}

static __inline void i2s_rx_enable(uint32_t base)
{
	WR_WORD((base + I2S_REG_IRER_OFS), 1);
}

static __inline void i2s_rx_disable(uint32_t base)
{
	WR_WORD((base + I2S_REG_IRER_OFS), 0);
}

static __inline void i2s_tx_enable(uint32_t base)
{
	WR_WORD((base + I2S_REG_ITER_OFS), 1);
}

static __inline void i2s_tx_disable(uint32_t base)
{
	WR_WORD((base + I2S_REG_ITER_OFS), 0);
}

static __inline void i2s_sclk_enable(uint32_t base)
{
	WR_WORD((base + I2S_REG_CER_OFS), 1);
}

static __inline void i2s_sclk_disable(uint32_t base)
{
	WR_WORD((base + I2S_REG_CER_OFS), 0);
}

#define I2S_CCR_SCLKG		0x00000007UL
#define I2S_CCR_WSS			0x00000018UL

#define I2S_CCR_SCLKG_NG	0
#define I2S_CCR_SCLKG_12		1
#define I2S_CCR_SCLKG_16		2
#define I2S_CCR_SCLKG_20		3
#define I2S_CCR_SCLKG_24		4

/// I2S each sample size
#define I2S_CCR_WSS_16		0
#define I2S_CCR_WSS_24		1
#define I2S_CCR_WSS_32		2
static __inline void i2s_sclk_wss(uint32_t base, int wss)
{
	uint32_t reg = RD_WORD(base + I2S_REG_CCR_OFS);
	
	reg &= ~I2S_CCR_WSS;
	reg |= ((wss & 0x3) << 3);

	WR_WORD((base + I2S_REG_CCR_OFS), reg);
}

static __inline void i2s_sclk_gate(uint32_t base, int gated_clk)
{
	uint32_t reg = RD_WORD(base + I2S_REG_CCR_OFS);
	
	reg &= ~I2S_CCR_SCLKG;
	reg |= (gated_clk & 0x7);

	WR_WORD((base + I2S_REG_CCR_OFS), reg);
}

static __inline void i2s_rx_fifo_reset(uint32_t base)
{
	WR_WORD((base + I2S_REG_RXFFR_OFS), 1);
}

static __inline void i2s_tx_fifo_reset(uint32_t base)
{
	WR_WORD((base + I2S_REG_TXFFR_OFS), 1);
}

static __inline uint32_t i2s_chx_lrx_data(uint32_t ch_base)
{
	return RD_WORD(ch_base + I2S_REG_LRBR_OFS);
}

static __inline void i2s_chx_ltx_data(uint32_t ch_base, uint32_t data)
{
	WR_WORD((ch_base + I2S_REG_LTHR_OFS), data);
}

static __inline uint32_t i2s_chx_rrx_data(uint32_t ch_base)
{
	return RD_WORD(ch_base + I2S_REG_RRBR_OFS);
}

static __inline void i2s_chx_rtx_data(uint32_t ch_base, uint32_t data)
{
	WR_WORD((ch_base + I2S_REG_RTHR_OFS), data);
}

static __inline void i2s_chx_rx_enable(uint32_t ch_base)
{
	WR_WORD((ch_base + I2S_REG_RER_OFS), 1);
}

static __inline void i2s_chx_rx_disable(uint32_t ch_base)
{
	WR_WORD((ch_base + I2S_REG_RER_OFS), 0);
}

static __inline void i2s_chx_tx_enable(uint32_t ch_base)
{
	WR_WORD((ch_base + I2S_REG_TER_OFS), 1);
}

static __inline void i2s_chx_tx_disable(uint32_t ch_base)
{
	WR_WORD((ch_base + I2S_REG_TER_OFS), 0);
}

#define I2S_CHx_RCR_WLEN		0x00000007UL

#define I2S_CHx_WLEN_0		0
#define I2S_CHx_WLEN_12		1
#define I2S_CHx_WLEN_16		2
#define I2S_CHx_WLEN_20		3
#define I2S_CHx_WLEN_24		4
#define I2S_CHx_WLEN_32		5

static __inline void i2s_chx_rx_wlen(uint32_t ch_base, int word_len)
{
	WR_WORD((ch_base + I2S_REG_RCR_OFS), (word_len & 0x7));
}

#define I2S_CHx_TCR_WLEN		0x00000007UL

static __inline void i2s_chx_tx_wlen(uint32_t ch_base, int word_len)
{
	WR_WORD((ch_base + I2S_REG_TCR_OFS), (word_len & 0x7));
}

#define I2S_CHx_IT_RXDA	0x00000001UL
#define I2S_CHx_IT_RXFO	0x00000002UL
#define I2S_CHx_IT_TXFE		0x00000010UL
#define I2S_CHx_IT_TXFO	0x00000020UL	
#define I2S_CHx_IT_ALL		0x00000033UL	

static __inline uint32_t i2s_chx_intr_status(uint32_t ch_base)
{
	return (RD_WORD(ch_base + I2S_REG_ISR_OFS));
}

static __inline void i2s_chx_intr_mask(uint32_t ch_base, uint32_t mask)
{
	uint32_t reg = RD_WORD(ch_base + I2S_REG_IMR_OFS);
	reg |= mask;
	WR_WORD((ch_base + I2S_REG_IMR_OFS), reg); 
}

static __inline void i2s_chx_intr_unmask(uint32_t ch_base, uint32_t mask)
{
	uint32_t reg = RD_WORD(ch_base + I2S_REG_IMR_OFS);
	reg &= ~mask;
	WR_WORD((ch_base + I2S_REG_IMR_OFS), reg); 
}

static __inline void i2s_chx_rov_clr(uint32_t ch_base)
{
	RD_WORD(ch_base + I2S_REG_ROR_OFS);
}

static __inline void i2s_chx_tov_clr(uint32_t ch_base)
{
	RD_WORD(ch_base + I2S_REG_TOR_OFS);
}

#define I2S_CHx_RFCR_RXCHDT		0x0000000FUL
static __inline void i2s_chx_rfifo_tl(uint32_t ch_base, uint32_t tl)
{
	WR_WORD((ch_base + I2S_REG_RFCR_OFS), (tl & 0xF)); 
}

#define I2S_CHx_TFCR_TXCHDT		0x0000000FUL
static __inline void i2s_chx_tfifo_tl(uint32_t ch_base, uint32_t tl)
{
	WR_WORD((ch_base + I2S_REG_TFCR_OFS), (tl & 0xF)); 
}

static __inline void i2s_chx_rfifo_flush(uint32_t ch_base)
{
	WR_WORD((ch_base + I2S_REG_RFF_OFS), 1); 
}

static __inline void i2s_chx_tfifo_flush(uint32_t ch_base)
{
	WR_WORD((ch_base + I2S_REG_TFF_OFS), 1); 
}

static __inline void i2s_sd_oe(int id, int ch_id, int oe)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_I2S_OEN_CTRL);
	if (id == MI2S_ID) {
		if (ch_id == I2S_CH_1) {
			if (oe) {
				reg &= ~GLOBAL_REG_I2S_OEN_CTRL_CTL_I2S_MASTER_SD0_OEN;
			} else {
				reg |= GLOBAL_REG_I2S_OEN_CTRL_CTL_I2S_MASTER_SD0_OEN;
			}
		} else {
			if (oe) {
				reg &= ~GLOBAL_REG_I2S_OEN_CTRL_CTL_I2S_MASTER_SD1_OEN;
			} else {
				reg |= GLOBAL_REG_I2S_OEN_CTRL_CTL_I2S_MASTER_SD1_OEN;
			}
		}
	} else {
		if (oe) {
			reg &= ~GLOBAL_REG_I2S_OEN_CTRL_CTL_I2S_SLAVE_SD_OEN;
		} else {
			reg |= GLOBAL_REG_I2S_OEN_CTRL_CTL_I2S_SLAVE_SD_OEN;
		}
	}
	WR_WORD(GLOBAL_REG_I2S_OEN_CTRL, reg); 
}

static __inline void i2s_txdma_start(uint32_t base)
{
	WR_WORD((base + I2S_REG_TXDMA_OFS), 0);
}

/*
 * APIs 
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Initialize I2S driver.
 *
 * @param[in] id 						I2s core Id, @see enum i2s_id
 * @param[in] sr 						Sample rate, @see enum i2s_sample_rate. This is only related to I2s master.
 * @param[in] word_sz 				Max. word size for left and right word select, @see enum i2s_word_size.   
 *
 * @return Handle to the I2s driver, NULL means open failed. 
 ****************************************************************************************
 */
void *hal_i2s_open(int id, int sr, int word_sz);

/**
 ****************************************************************************************
 * @brief Close I2S driver.
 *
 * @param[in] hdl					The handle from the previous "open" function.   
 *
 * @return @see enum i2s_error for the possible return code. 
 *
 ****************************************************************************************
 */
int hal_i2s_close(void *hdl) ;

/**
 ****************************************************************************************
 * @brief Enable I2S channel.
 * @note
 *			1. For Slave I2S, there is only 1 channel,
 *			2. For ADPCM with I2S input or output, specify buffers and length to 0,
 *			3. The movement of the I2s data are as follow:
 *					1.	Initially, user should allocate two buffers with the same length,
 *					2.	For TX, user should fill both buffers before calling this function,  The data should be organized 
 *						by left channel first and then followed by the right channel data.  For mono data, there is no 
 * 					need to duplicate the same data.  For channel data size is 12 bits, user should use 16 bits buffer 
 *						with 	the lower 12 bits to store data, For data size are 20 or 24 bits, user should use 32 bits buffer
 *						with the lower 20 or 24 bits to store data.     
 *					3.	Driver enables I2s HW,
 *					4. When HW finish the first buffer, driver will call user's provided call back function to inform user
 *						that the first buffer is ready to be either read (RX) or write (TX),  
 *					5.	While user handles the first buffer, the driver will hand over the second buffer to the HW for it 
 *						to either consume (TX) or fill (RX) the second buffer.
 *					6.	The step 4 and 5 will continue switching between first and second buffers (ping and pong) until 
 *						user stop the operation,
 *					7.	The RX data has the same format as TX data which means the left channel data followed by right
 *						channel data, 
 *					8.	The driver's call back is in the interrupt context, so user should off load the processing to the
 *						other context.	     
 *
 * @param[in] hdl					The handle from the previous "open" function.   
 * @param[in] ch_id				Channel Id, @see enum i2s_ch_id. Master can have 2 channels. Slave can have
 *											only 1 channel.
 * @param[in] dir 					Direction, @see enum i2s_ch_dir.  Each channel can be either TX or RX.  
 * @param[in] ch_word_sz		Each channel's left and right word size, @see enum i2s_ch_word_sz.
 * @param[in] buffer0			Pointer to the first buffer. Can be either 16 or 32 bits buffer depends on the 
 *											word size. 
 * @param[in] buffer1			Pointer to the second buffer. The same as buffer 0.
 * @param[in] buffer_len		The length of the buffer.   
 * @param[in] arg					Call back argument provided by the caller.
 * @param[in] callback			Call back function provided by the caller.  
 *												1. arg - user's provided argument,
 *												1. id - the buffer index, 0 or 1,
 *												2. status - @see enum i2s_error.
 * 
 * @return @see enum i2s_error for the possible return code. 
 *
 ****************************************************************************************
 */
int hal_i2s_ch_en(void *hdl, int ch_id, int dir, int ch_word_sz, void *buffer0, void *buffer1, uint16_t buffer_len, void *arg, void (*callback)(void * arg, int id, int status) );

/**
 ****************************************************************************************
 * @brief Disable I2S channel.
 *
 * @param[in] hdl					The handle from the previous "open" function.   
 * @param[in] ch_id				Channel Id, @see enum i2s_ch_id.
 *
 * @return @see enum i2s_error for the possible return code. 
 *
 ****************************************************************************************
 */
int hal_i2s_ch_dis(void *hdl, int ch_id);

#endif
