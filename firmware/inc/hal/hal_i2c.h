/**
 ****************************************************************************************
 *
 * @file hal_i2c.h
 *
 * @brief I2C driver header file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
#ifndef HAL_I2C_H
#define HAL_I2C_H

/**
 ****************************************************************************************
 * @defgroup HAL_I2C I2C driver  
 * @ingroup HAL
 * @brief  HAL_I2C
 * @{
 ****************************************************************************************
 */

#include "in_mmap.h"

/*
 * Defines
 ****************************************************************************************
 */

#define I2C_REG_CON_OFS		0x00000000UL
#define I2C_REG_TAR_OFS		0x00000004UL
#define I2C_REG_SAR_OFS		0x00000008UL
#define I2C_REG_DATA_OFS	0x00000010UL
#define I2C_REG_SS_HCNT_OFS	0x00000014UL
#define I2C_REG_SS_LCNT_OFS	0x00000018UL
#define I2C_REG_FS_HCNT_OFS	0x0000001CUL
#define I2C_REG_FS_LCNT_OFS	0x00000020UL
#define I2C_REG_HS_HCNT_OFS	0x00000024UL
#define I2C_REG_HS_LCNT_OFS	0x00000028UL
#define I2C_REG_ISR_OFS		0x0000002CUL
#define I2C_REG_IMR_OFS		0x00000030UL
#define I2C_REG_RISR_OFS		0x00000034UL
#define I2C_REG_RFTL_OFS		0x00000038UL
#define I2C_REG_TFTL_OFS		0x0000003CUL
#define I2C_REG_ICR_OFS		0x00000040UL
#define I2C_REG_ICRU_OFS		0x00000044UL
#define I2C_REG_ICRO_OFS		0x00000048UL
#define I2C_REG_ICTO_OFS		0x0000004CUL
#define I2C_REG_CRR_OFS		0x00000050UL
#define I2C_REG_CTA_OFS		0x00000054UL
#define I2C_REG_CRD_OFS		0x00000058UL
#define I2C_REG_CACT_OFS		0x0000005CUL
#define I2C_REG_CSD_OFS		0x00000060UL
#define I2C_REG_CSAD_OFS		0x00000064UL
#define I2C_REG_CLR_GEN_CALL_OFS		0x00000068UL
#define I2C_REG_ICE_OFS		0x0000006CUL
#define I2C_REG_IS_OFS		0x00000070UL
#define I2C_REG_TXFLR_OFS		0x00000074UL
#define I2C_REG_RXFLR_OFS		0x00000078UL
#define I2C_REG_SDAH_OFS		0x0000007CUL
#define I2C_REG_ABTS_OFS		0x00000080UL
#define I2C_REG_NACK_OFS		0x00000084UL
#define I2C_REG_DMA_CR_OFS		0x00000088UL
#define I2C_REG_DMA_TDLR_OFS		0x0000008CUL
#define I2C_REG_DMA_RDLR_OFS		0x00000090UL
#define I2C_REG_SDAS_OFS		0x00000094UL
#define I2C_REG_ACK_GC_OFS		0x00000098UL
#define I2C_REG_ES_OFS		0x0000009CUL
#define I2C_REG_FS_SPK_OFS		0x000000A0UL
#define I2C_REG_HS_SPK_OFS		0x000000A4UL
#define I2C_REG_ICRD_OFS		0x000000A8UL

#define I2C_FIFO_DEPTH 8
#define I2C_RX_FIFO_TL 4
#define I2C_TX_FIFO_TL 4

enum i2c_id{
	I2C0_ID,
	I2C1_ID,
};

enum i2c_scl {
	I2C_SPEED_100K,
	I2C_SPEED_400K,
};

enum i2c_error {
	I2C_ERR_OK = 0,
	I2C_ERR_INVALID_PARAM = -1,
	I2C_ERR_INVALID_STATE = -2,
	I2C_ERR_RX_UNDER_RUN = -3,
	I2C_ERR_RX_OVER_RUN = -4,
	I2C_ERR_TX_OVER_FLOW = -5,
	I2C_ERR_ADDR_NO_ACK = -6,
	I2C_ERR_TXDATA_NO_ACK = -7,
	I2C_ERR_SDA_STUCK_AT_LOW = -8,
	I2C_ERR_UNKNOWN = -9,
	I2C_ERR_DMA_BUSY = -10,
	I2C_ERR_DMA_FAIL = -11,
	I2C_ERR_DMA_ALLOC_BUF_FAIL = -11,
	I2C_ERR_TMO = -12,
	I2C_ERR_RESET = -13,

	I2C_ERR_MAX = -100,
} ;

enum i2c_dir {
	I2C_DIR_WRITE,
	I2C_DIR_READ,
};

/*
 * Inline Functions
 ****************************************************************************************
 */

#define I2C_CON_MASTER_MODE						0x00000001UL
#define I2C_CON_SPEED									0x00000006UL
#define I2C_CON_10BIT_SLAVE						0x00000008UL
#define I2C_CON_SLAVE_DISABLE					0x00000040UL
#define I2C_CON_TX_EMPTY_CTRL					0x00000100UL
#define I2C_CON_RX_FIFO_FULL_HLD_CTRL	0x00000200UL

#define I2C_CON_SPEED_STD						(0x1UL << 1)
#define I2C_CON_SPEED_FAST					(0x2UL << 1)

static __inline void i2c_con_clear(uint32_t i2c_base)
{
	WR_WORD((i2c_base + I2C_REG_CON_OFS), 0);
}

static __inline void i2c_speed(uint32_t i2c_base, int speed)
{
	uint32_t reg = RD_WORD(i2c_base + I2C_REG_CON_OFS);

	reg &= ~I2C_CON_SPEED;	

	if (speed == I2C_SPEED_100K) {
		reg |= I2C_CON_SPEED_STD;
	} else {
		reg |= I2C_CON_SPEED_FAST;
	} 

	WR_WORD(i2c_base + I2C_REG_CON_OFS, reg);
}

static __inline void i2c_master_enable(uint32_t i2c_base)
{
	uint32_t reg = RD_WORD(i2c_base + I2C_REG_CON_OFS);

	reg |= I2C_CON_MASTER_MODE;
	reg |=  I2C_CON_SLAVE_DISABLE;

	WR_WORD(i2c_base + I2C_REG_CON_OFS, reg);
}

static __inline void i2c_slave_enable(uint32_t i2c_base)
{
	uint32_t reg = RD_WORD(i2c_base + I2C_REG_CON_OFS);

	reg &= ~I2C_CON_MASTER_MODE;
	reg &=  ~I2C_CON_SLAVE_DISABLE;

	WR_WORD(i2c_base + I2C_REG_CON_OFS, reg);

}

/*******************  Bit definition for I2C_TAR register  ********************/
#define I2C_TAR												0x000003FFUL					/* bit[0:9] = target address  */

static __inline void i2c_tar(uint32_t i2c_base, uint8_t taddr)
{
	WR_WORD(i2c_base + I2C_REG_TAR_OFS, taddr);
}


/*******************  Bit definition for I2C_SAR register  ********************/
#define I2C_SAR												0x000003FFUL					/* bit[0:9] = Slave address */

static __inline void i2c_sar(uint32_t i2c_base, uint8_t saddr)
{
	WR_WORD(i2c_base + I2C_REG_SAR_OFS, saddr);
}

	
/*******************  Bit definition for I2C_DATA_CMD register  ********************/
#define I2C_DATA											0x000000FFUL					/* bit[0:7] = data */
#define I2C_READ											0x00000100UL					/* bit[8] = 0: write, 1: read */
#define I2C_STOP											0x00000200UL					/* bit[9] = 1: stop, 0: otherwise */

static __inline void i2c_write(uint32_t i2c_base, uint8_t data, int read, int stop)
{
	uint16_t reg;

	reg = data;
	if (read)
		reg |= I2C_READ;
	if (stop)
		reg |= I2C_STOP;

	WR_WORD(i2c_base + I2C_REG_DATA_OFS, reg);
}

static __inline uint8_t i2c_read(uint32_t i2c_base)
{
	return (RD_WORD(i2c_base + I2C_REG_DATA_OFS) & 0xFF);
}


/*******************  Bit definition for I2C_SS_SCL_HCNT register  **********************/
#define I2C_SS_SCL_HCNT								0x0000FFFFUL					/* bit[0:15] = standard speed SCL clock high period count */

static __inline void i2c_ss_scl_hcnt(uint32_t i2c_base, uint16_t hcnt)
{
	WR_WORD(i2c_base + I2C_REG_SS_HCNT_OFS, hcnt);
}

/*********************  Bit definition for I2C_SS_SCL_LCNT register  **********************/
#define I2C_SS_SCL_LCNT								0x0000FFFFUL					/* bit[0:15] = standard speed SCL clock low period count */

static __inline void i2c_ss_scl_lcnt(uint32_t i2c_base, uint16_t lcnt)
{
	WR_WORD(i2c_base + I2C_REG_SS_LCNT_OFS, lcnt);
}

/*******************  Bit definition for I2C_FS_SCL_HCNT register  ********************/
#define I2C_FS_SCL_HCNT								0x0000FFFFUL					/* bit[0:15] = Fast mode speed SCL clock high period count */

static __inline void i2c_fs_scl_hcnt(uint32_t i2c_base, uint16_t hcnt)
{
	WR_WORD(i2c_base + I2C_REG_FS_HCNT_OFS, hcnt);
}

/*******************  Bit definition for I2C_FS_SCL_LCNT register  ********************/
#define I2C_FS_SCL_LCNT								0x0000FFFFUL					/* bit[0:15] = Fast mode speed SCL clock low period count */

static __inline void i2c_fs_scl_lcnt(uint32_t i2c_base, uint16_t lcnt)
{
	WR_WORD(i2c_base + I2C_REG_FS_LCNT_OFS, lcnt);
}


/*******************  Bit definition for I2C_INTR_STAT register  ********************/
/*******************  Bit definition for I2C_INTR_MASK register  ********************/
/*******************  Bit definition for I2C_RAW_INTR_STAT register  ********************/
#define I2C_INTR_RX_UNDER								0x00000001UL
#define I2C_INTR_RX_OVER									0x00000002UL
#define I2C_INTR_RX_FULL									0x00000004UL
#define I2C_INTR_TX_OVER									0x00000008UL
#define I2C_INTR_TX_EMPTY								0x00000010UL
#define I2C_INTR_RD_REQ									0x00000020UL
#define I2C_INTR_TX_ABRT									0x00000040UL
#define I2C_INTR_RX_DONE									0x00000080UL
#define I2C_INTR_ACTIVITY									0x00000100UL
#define I2C_INTR_STOP_DET								0x00000200UL
#define I2C_INTR_START_DET								0x00000400UL
//#define I2C_INTR_GEN_CALL								0x00000800UL
//#define I2C_INTR_RESTART_DET							0x00001000UL
#define I2C_INTR_MST_ON_HOLD							0x00002000UL
//#define I2C_INTR_SCL_STUCK_LOW						0x00004000UL
#define I2C_INTR_MASK_ALL								0x00007FFFUL
static __inline uint32_t i2c_intr_status(uint32_t i2c_base)
{
	return RD_WORD(i2c_base + I2C_REG_ISR_OFS);
}

static __inline uint32_t i2c_intr_raw_status(uint32_t i2c_base)
{
	return RD_WORD(i2c_base + I2C_REG_RISR_OFS);
}

static __inline void i2c_intr_mask(uint32_t i2c_base, uint32_t mask)
{
	uint32_t reg = RD_WORD(i2c_base + I2C_REG_IMR_OFS);
	reg &= ~mask;
	WR_WORD(i2c_base + I2C_REG_IMR_OFS, reg);
}

static __inline void i2c_intr_unmask(uint32_t i2c_base, uint32_t unmask)
{
	uint32_t reg = RD_WORD(i2c_base + I2C_REG_IMR_OFS);
	reg |= unmask;
	WR_WORD(i2c_base + I2C_REG_IMR_OFS, reg);
}

static __inline void i2c_intr_clr(uint32_t i2c_base)
{
	RD_WORD(i2c_base + I2C_REG_ICR_OFS);
}

static __inline void i2c_intr_clr_rxu(uint32_t i2c_base)
{
	RD_WORD(i2c_base + I2C_REG_ICRU_OFS);
}

static __inline void i2c_intr_clr_rxo(uint32_t i2c_base)
{
	RD_WORD(i2c_base + I2C_REG_ICRO_OFS);
}

static __inline void i2c_intr_clr_txo(uint32_t i2c_base)
{
	RD_WORD(i2c_base + I2C_REG_ICTO_OFS);
}

static __inline void i2c_intr_clr_req(uint32_t i2c_base)
{
	RD_WORD(i2c_base + I2C_REG_CRR_OFS);
}

static __inline void i2c_intr_clr_abt(uint32_t i2c_base)
{
	RD_WORD(i2c_base + I2C_REG_CTA_OFS);
}

static __inline void i2c_intr_clr_rxd(uint32_t i2c_base)
{
	RD_WORD(i2c_base + I2C_REG_CRD_OFS);
}

static __inline void i2c_intr_clr_activity(uint32_t i2c_base)
{
	RD_WORD(i2c_base + I2C_REG_CACT_OFS);
}

static __inline void i2c_intr_clr_stop(uint32_t i2c_base)
{
	RD_WORD(i2c_base + I2C_REG_CSD_OFS);
}

static __inline void i2c_intr_clr_start(uint32_t i2c_base)
{
	RD_WORD(i2c_base + I2C_REG_CSAD_OFS);
}

/*******************  Bit definition for I2C_RX_TL register  ********************/
#define I2C_RX_TL											0x000000FFUL				/* bit[0:15] = Receive FIFO Threshold Level */

static __inline void i2c_rx_fifo_tl(uint32_t i2c_base, uint8_t level)
{
	WR_WORD(i2c_base + I2C_REG_RFTL_OFS, level);
}

static __inline uint8_t i2c_get_rx_fifo_tl(uint32_t i2c_base)
{
	return (RD_WORD(i2c_base + I2C_REG_RFTL_OFS) & 0xFF);
}

/*******************  Bit definition for I2C_TX_TL register  ********************/
#define I2C_TX_TL											0x000000FFUL				/* bit[0:15] = Transmit FIFO Threshold Level */

static __inline void i2c_tx_fifo_tl(uint32_t i2c_base, uint16_t level)
{
	WR_WORD(i2c_base + I2C_REG_TFTL_OFS, level);
}

static __inline uint8_t i2c_get_tx_fifo_tl(uint32_t i2c_base)
{
	return (RD_WORD(i2c_base + I2C_REG_TFTL_OFS) & 0xFF);
}


/*******************  Bit definition for I2C_ENABLE_STATUS register  ********************/
#define I2C_ES_ENABLE											0x00000001UL			/* bit[0] = I2C Enable Status */
#define I2C_ES_SLV_DISABLE_BUSY						0x00000002UL			/* bit[1] = Slave disable while busy */
#define I2C_ES_SLV_RX_DATA_LOST						0x00000004UL			/* bit[2] = Slave received data lost */
static __inline uint32_t i2c_enable_status(uint32_t i2c_base)
{
	return (RD_WORD(i2c_base + I2C_REG_ES_OFS));
}

/*******************  Bit definition for I2C_ENABLE register  ********************/
#define I2C_ENABLE											0x00000001UL			/* bit[0] = Enable I2C */
#define I2C_ABORT												0x00000002UL			/* bit[1] = Abort operation in progress */

static __inline void i2c_enable(uint32_t i2c_base)
{
	uint32_t reg = RD_WORD(i2c_base + I2C_REG_ICE_OFS); 
	reg |= 0x1UL;
	WR_WORD(i2c_base + I2C_REG_ICE_OFS, reg);
}

static __inline void i2c_disable(uint32_t i2c_base)
{
	uint32_t reg = RD_WORD(i2c_base + I2C_REG_ICE_OFS); 
	reg &= ~0x1UL;
	WR_WORD(i2c_base + I2C_REG_ICE_OFS, reg);

	//while (i2c_enable_status(i2c_base) & I2C_ES_ENABLE);	
}

static __inline void i2c_abort(uint32_t i2c_base, int enable)
{
	uint32_t reg = RD_WORD(i2c_base + I2C_REG_ICE_OFS); 
	if (enable)
		reg |= I2C_ABORT;
	else
		reg &= ~I2C_ABORT;

	WR_WORD(i2c_base + I2C_REG_ICE_OFS, reg);
}



/*******************  Bit definition for I2C_STATUS register  ********************/
#define I2C_STATUS_ACTIVITY							0x00000001UL			/* bit[0] = Activity */
#define I2C_STATUS_TFNF									0x00000002UL			/* bit[1] = TX FIFO not full */
#define I2C_STATUS_TFE										0x00000004UL			/* bit[2] = TX FIFO empty */
#define I2C_STATUS_RFNE									0x00000008UL			/* bit[3] = RX FIFO not empty */
#define I2C_STATUS_RFF									0x00000010UL			/* bit[4] = RX FIFO full */

static __inline uint32_t i2c_status(uint32_t i2c_base)
{
	return (RD_WORD(i2c_base + I2C_REG_IS_OFS));
}

/*******************  Bit definition for I2C_FLR register  ********************/
static __inline uint8_t i2c_rx_fifo_level(uint32_t i2c_base)
{
	return (RD_WORD(i2c_base + I2C_REG_RXFLR_OFS) & 0xF);	
}

static __inline uint8_t i2c_tx_fifo_level(uint32_t i2c_base)
{
	return (RD_WORD(i2c_base + I2C_REG_TXFLR_OFS) & 0xF);	
}

/*******************  Bit definition for I2C_TX_ABRT_SOURCE register  ********************/
#define I2C_ABRT_ADDR_NOACK				0x00000001UL
#define I2C_ABRT_TXDATA_NOACK			0x00000008UL
#define I2C_ABRT_SLVFLUSH_TXFIFO	0x00002000UL
#define I2C_ABRT_SLV_ARBLOST			0x00004000UL
#define I2C_ABRT_SLVRD_INTX				0x00008000UL
#define I2C_ABRT_USER_ABRT				0x00010000UL
#define I2C_ABRT_SDA_STUCK_AT_LOW	0x00020000UL
#define I2C_ABRT_TX_FLUSH_CNT			0xFF800000UL

static __inline uint32_t i2c_abt_source(uint32_t i2c_base)
{
	return (RD_WORD(i2c_base + I2C_REG_ABTS_OFS));
}

/*******************  Bit definition for I2C DMA Control register  ********************/
#define I2C_TX_DMA_EN						0x00000002UL
#define I2C_RX_DMA_EN						0x00000001UL

static __inline void i2c_dma_tx_enable(uint32_t i2c_base)
{
	uint32_t reg = RD_WORD(i2c_base + I2C_REG_DMA_CR_OFS); 
	reg |= I2C_TX_DMA_EN;
	WR_WORD(i2c_base + I2C_REG_DMA_CR_OFS, reg);
}

static __inline void i2c_dma_tx_disable(uint32_t i2c_base)
{
	uint32_t reg = RD_WORD(i2c_base + I2C_REG_DMA_CR_OFS); 
	reg &= ~I2C_TX_DMA_EN;
	WR_WORD(i2c_base + I2C_REG_DMA_CR_OFS, reg);
}

static __inline void i2c_dma_rx_enable(uint32_t i2c_base)
{
	uint32_t reg = RD_WORD(i2c_base + I2C_REG_DMA_CR_OFS); 
	reg |= I2C_RX_DMA_EN;
	WR_WORD(i2c_base + I2C_REG_DMA_CR_OFS, reg);
}

static __inline void i2c_dma_rx_disable(uint32_t i2c_base)
{
	uint32_t reg = RD_WORD(i2c_base + I2C_REG_DMA_CR_OFS); 
	reg &= ~I2C_RX_DMA_EN;
	WR_WORD(i2c_base + I2C_REG_DMA_CR_OFS, reg);
}


/*******************  Bit definition for I2C DMA Data Level register  ********************/
static __inline void i2c_dma_tx_data_level(uint32_t i2c_base, uint32_t level)
{
	WR_WORD(i2c_base + I2C_REG_DMA_TDLR_OFS, (level & 0xF));
}

static __inline void i2c_dma_rx_data_level(uint32_t i2c_base, uint32_t level)
{
	WR_WORD(i2c_base + I2C_REG_DMA_RDLR_OFS, (level & 0xF));
}

static __inline void i2c_reset(int id)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_RESET_CTRL_1);

	// Toggle 1-0-1 to reset
	if (id == I2C0_ID) {
		reg &= ~GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_I2C_0_IC_RSTN_REG;
	} else {
		reg &= ~GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_I2C_1_IC_RSTN_REG;
	}
	WR_WORD(GLOBAL_REG_RESET_CTRL_1, reg);
	if (id == I2C0_ID) {
		reg |= GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_I2C_0_IC_RSTN_REG;
	} else {
		reg |= GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_I2C_1_IC_RSTN_REG;
	}
	WR_WORD(GLOBAL_REG_RESET_CTRL_1, reg);
}

/******************************************************************************/
/*                                                                            */
/*                      Inter-integrated Circuit Interface                    */
/*                                                                            */
/******************************************************************************/

/**
 ****************************************************************************************
 * @brief Open the I2c driver
 *
 * @param[in] id					The I2c controller ID, @see enum i2c_id.   
 *
 * @return Handle to the I2c driver, NULL means open failed. 
 ****************************************************************************************
 */

void *hal_i2c_open(int id);

/**
 ****************************************************************************************
 * @brief Close the I2c driver
 *
 * @param[in] hdl					The handle from the previous "open" function.   
 *
 * @return This function has no return. 
 ****************************************************************************************
 */

void hal_i2c_close(void *hdl);

/**
 ****************************************************************************************
 * @brief I2c master read function.
 *
 * @param[in] hdl					The handle from the previous "open" function.   
 * @param[in] speed				The I2c serial clock rate, @see enum i2c_scl.   
 * @param[in] tar					The slave address.
 * @param[in] buffer			The pointer to the received buffer.
 * @param[in] buffer_len		The receive buffer length.
 * @param[in] tmo				The time out value in millisecond for the master to wait for slave.
 *
 * @return @see enum i2c_error for the possible return code. 
 ****************************************************************************************
 */
int hal_mi2c_read(void *hdl, int speed, uint8_t tar, uint8_t *buffer, uint16_t buffer_len, uint32_t tmo);
int hal_mi2c_read_dma(void *hdl, int speed, uint8_t tar, uint8_t *buffer, uint16_t buffer_len, uint32_t tmo);

/**
 ****************************************************************************************
 * @brief I2c master write function.
 *
 * @param[in] hdl					The handle from the previous "open" function.   
 * @param[in] speed				The I2c serial clock rate, @see enum i2c_scl.   
 * @param[in] tar					The slave address.
 * @param[in] buffer			The pointer to the transmit buffer.
 * @param[in] buffer_len		The transmit buffer length.
 * @param[in] tmo				The time out value in millisecond for the master to wait for slave.
 *
 * @return @see enum i2c_error for the possible return code. 
 ****************************************************************************************
 */
int hal_mi2c_write(void *hdl, int speed, uint8_t tar, uint8_t *buffer, uint16_t buffer_len, uint32_t tmo);	
int hal_mi2c_write_dma(void *hdl, int speed, uint8_t tar, uint8_t *buffer, uint16_t buffer_len, uint32_t tmo);

/**
 ****************************************************************************************
 * @brief I2c slave read function.
 *
 * @param[in] hdl					The handle from the previous "open" function.   
 * @param[in] speed				The I2c serial clock rate, @see enum i2c_scl.   
 * @param[in] sar					The slave address.
 * @param[in] buffer			The pointer to the receive buffer.
 * @param[in] buffer_len		The receive buffer length.
 * @param[in] tmo				The time out value in millisecond for the master to wait for slave.
 *
 * @return @see enum i2c_error for the possible return code. 
 *
 ****************************************************************************************
 */

int hal_si2c_read(void *hdl, int speed, uint8_t sar, uint8_t *buffer, uint16_t buffer_len, uint32_t tmo);
int hal_si2c_read_dma(void *hdl, int speed, uint8_t sar, uint8_t *buffer, uint16_t buffer_len, uint32_t tmo);

/**
 ****************************************************************************************
 * @brief I2c slave write function.
 *
 * @param[in] hdl					The handle from the previous "open" function.   
 * @param[in] speed				The I2c serial clock rate, @see enum i2c_scl.   
 * @param[in] sar					The slave address.
 * @param[in] buffer			The pointer to the transmit buffer.
 * @param[in] buffer_len		The transmit buffer length.
 * @param[in] tmo				The time out value in millisecond for the master to wait for slave.
 *
 * @return @see enum i2c_error for the possible return code. 
 ****************************************************************************************
 */

int hal_si2c_write(void *hdl, int speed, uint8_t sar, uint8_t *buffer, uint16_t buffer_len, uint32_t tmo);
int hal_si2c_write_dma(void *hdl, int speed, uint8_t sar, uint8_t *buffer, uint16_t buffer_len, uint32_t tmo);


/**
 ****************************************************************************************
 * @brief I2c master write and read function.
 * @note This function write wr_len bytes, then read rd_len bytes. It doesn't send STOP after write.
 * @param[in] hdl					The handle from the previous "open" function.   
 * @param[in] speed				The I2c serial clock rate, @see enum i2c_scl.   
 * @param[in] tar					The slave address.
 * @param[in] wr_buf			The pointer to the write buffer.
 * @param[in] wr_len		    The write buffer length.
 * @param[out] rd_buf			The pointer to the read buffer.
 * @param[in] rd_len		    The read buffer length.
 * @param[in] tmo				The time out value in millisecond for the master to wait for slave.
 *
 * @return @see enum i2c_error for the possible return code. 
 ****************************************************************************************
 */
int hal_mi2c_write_read(void *hdl, int speed, uint8_t tar, uint8_t *wr_buf, uint16_t wr_len, uint8_t *rd_buf, uint16_t rd_len, uint32_t tmo);
/// @} HAL_I2C

#endif	// HAL_I2C_H
