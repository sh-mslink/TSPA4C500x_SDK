/**
 ****************************************************************************************
 *
 * @file inb_sdr.h
 *
 * @brief Software Defined Radio  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef INB_SDR_H
#define INB_SDR_H

#include "in_mmap.h"

/*
 * Enumeration
 ****************************************************************************************
 */

enum sdr_mode
{
	MODE_ADDRESSLESS=0x2,
	MODE_BROADCAST = 0x3,
	MODE_PRIVATE = 0x6,
};

enum sdr_phy_rate
{
	PHY_RATE_1M = 0,
	PHY_RATE_2M = 1,
	PHY_RATE_CODED_125K = 2,
	PHY_RATE_CODED_500K = 3,
};

enum sdr_rx_status
{
	/// RX has no error.
	SDR_RX_STATUS_NOERR = 0,
	/// RX has CRC error, packet should be discarded.
	SDR_RX_STATUS_CRCERR = 0x1,
	/// RX has SYNC error, packet should be discarded.
	SDR_RX_STATUS_SYNCERR = 0x2,
};

enum sdr_error
{
	SDR_ERR_OK = 0,
	SDR_ERR_INVALID_PARAM = -1,
	SDR_ERR_TX_DATA_ALLOC = -2,
	SDR_ERR_TX_DESC_ALLOC = -3,
	SDR_ERR_RX_DATA_ALLOC = -4,
	SDR_ERR_RX_DESC_ALLOC = -5,
	SDR_ERR_TX_NOACK = -6,
	SDR_ERR_OS = -7,
	SDR_ERR_NOT_READY = -8,
	SDR_ERR_ABORT = -9,
};

typedef struct {
	/// Rx status, @see enum sdr_rx_status.
	uint8_t status;
	/// Rx current physical rate
	uint8_t phy_rate;
	/// Rx current channel index
	uint8_t ch_idx;
	/// Rx data length
	uint8_t rxlen;
	/// Rx data buffer (this is HW buffer pointer, user should copy data to his own buffer)
	uint8_t *rxbuf;	
	/// RX soruce address
	uint16_t sa;
	uint16_t da;
	/// Rx current Rssi
	int rssi;
} rx_param_t;

/*
 * Inline 
 ****************************************************************************************
 */

static __inline void sdr_abort(void) 
{
	WR_WORD(IPMAC_REG_BLE_ABORT_REQ, (IPMAC_REG_BLE_ABORT_REQ_DEFAULT|IPMAC_REG_BLE_ABORT_REQ_CTL_BLE_ABORT_REQ));		
}

static __inline uint32_t sdr_misc_read(void) 
{
	return RD_WORD(IPMAC_REG_SDR_MISC_CTRL);
}

static __inline void sdr_misc_ctl(int en, int no_ts, int no_fine_ts, int match_da, int match_sa, int slv_sbt, int mstr_abt) 
{
	uint32_t reg = RD_WORD(IPMAC_REG_SDR_MISC_CTRL);

	if (en)
		reg |= IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_EN;
	else
		reg &= ~IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_EN;

	if (no_ts)
		reg |= IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_IGNORE_TIMESTAMP;
	else
		reg &= ~IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_IGNORE_TIMESTAMP;

	if (no_fine_ts)
		reg |= IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_IGNORE_TIMESTAMP_FINE;
	else
		reg &= ~IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_IGNORE_TIMESTAMP_FINE;

	if (match_da)
		reg |= IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_MATCHING_DEST_ADDR;
	else
		reg &= ~IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_MATCHING_DEST_ADDR;

	if (match_sa)
		reg |= IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_MATCHING_SRC_ADDR ;
	else
		reg &= ~IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_MATCHING_SRC_ADDR;

	if (slv_sbt)
		reg |= IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_SLV_ABORT_EVT_SINGLE_CRCERR ;
	else
		reg &= ~IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_SLV_ABORT_EVT_SINGLE_CRCERR;

	if (mstr_abt)
		reg |= IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_MSTR_ABORT_EVT_SINGLE_CRCERR ;
	else
		reg &= ~IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_MSTR_ABORT_EVT_SINGLE_CRCERR;

	WR_WORD(IPMAC_REG_SDR_MISC_CTRL, reg);
}

static __inline void sdr_misc_write(uint32_t reg) 
{
	WR_WORD(IPMAC_REG_SDR_MISC_CTRL, reg);
}

static __inline void sdr_restart_ctl(int no_match, int sigl_match, uint32_t us) 
{
	uint32_t reg = RD_WORD(IPMAC_REG_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH);

	if (no_match)
		reg |= IPMAC_REG_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_CTL_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH;
	else
		reg &= ~IPMAC_REG_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_CTL_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH;

	if (sigl_match)
		reg |= IPMAC_REG_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_CTL_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_SINGLE;
	else
		reg &= ~IPMAC_REG_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_CTL_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_SINGLE;

	reg &= ~IPMAC_REG_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_CTL_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_IDLE_LMT;
	reg |= (us & IPMAC_REG_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_CTL_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_IDLE_LMT_MASK) << 
						IPMAC_REG_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_CTL_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_IDLE_LMT_SHIFT;

	WR_WORD(IPMAC_REG_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH, reg);

}

static __inline void sdr_rx_da_ctl(uint16_t da, uint16_t mask) 
{
	uint32_t reg = da | (mask << IPMAC_REG_SDR_DEST_ADDR_TO_MATCH_CTL_SDR_DEST_ADDR_MASK_SHIFT);
	WR_WORD(IPMAC_REG_SDR_DEST_ADDR_TO_MATCH, reg);
}

static __inline void sdr_rx_sa_ctl(int idx, uint16_t sa, uint16_t mask) 
{
	uint32_t reg = sa | (mask << IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_0_CTL_SDR_SRC_ADDR_0_MASK_SHIFT);
	WR_WORD((IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_0 + idx * 4), reg);
}

static __inline uint16_t sdr_tx_da_addr(void)
{
	return ((RD_WORD(IPMAC_REG_SDR_TX_ADDR) >> IPMAC_REG_SDR_TX_ADDR_STS_SDR_TX_DEST_ADDR_SHIFT) & IPMAC_REG_SDR_TX_ADDR_STS_SDR_TX_DEST_ADDR_MASK);
}

static __inline uint16_t sdr_tx_sa_addr(void)
{
	return (RD_WORD(IPMAC_REG_SDR_TX_ADDR) & IPMAC_REG_SDR_TX_ADDR_STS_SDR_TX_SRC_ADDR_MASK);
}

static __inline uint16_t sdr_rx_da_addr(void)
{
	return ((RD_WORD(IPMAC_REG_SDR_RX_ADDR) >> IPMAC_REG_SDR_RX_ADDR_STS_SDR_RX_DEST_ADDR_SHIFT) & IPMAC_REG_SDR_RX_ADDR_STS_SDR_RX_DEST_ADDR_MASK);
}

static __inline uint16_t sdr_rx_sa_addr(void)
{
	return (RD_WORD(IPMAC_REG_SDR_RX_ADDR) & IPMAC_REG_SDR_RX_ADDR_STS_SDR_RX_SRC_ADDR_MASK);
}

/*
 * APIs
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief SDR initialization function 
 *	@Note: This function is called by the BLE stack. Application shouldn't call this function.
 *
 * @param[in] pv								Pointer to the ROM function tables
 *
 * @return Possible return @see enum sdr_err. 
 ****************************************************************************************
 */

int sdr_init(void *pv);

/**
 ****************************************************************************************
 * @brief SDR de-initialization function 
 *	@Note: This function is called by the BLE stack. Application shouldn't call this function.
 *
 * @param[in] pv								Pointer to the ROM function tables
 *
 * @return Possible return @see enum sdr_err. 
 ****************************************************************************************
 */
void sdr_deinit(void *pv);

/**
 ****************************************************************************************
 * @brief SDR master transfer function 
 *
 * @param[in] mode									Transfer mode, @see enum sdr_mode
 * @param[in] aa										Access address (common address shared by all the nodes)
 * @param[in] chn									Channel index (0 ~ 39),
 * @param[in] txr										Tx physical rate, @see enum sdr_phy_rate.
 * @param[in] rxr										Rx physical rate, @see enum sdr_phy_rate.
 * @param[in] mst_a									Master address (source address)
 * @param[in] slv_a									Slave address (destination address)
 * @param[in] rx_da_mask							Slave's packets destination address mask for each address bit; 
 *																		1: match, 
 *																		0: don't care
 * @param[in] tx_len									Application data buffer length,
 * @param[in] tx_buf									Pointer to application data buffer,
 * @param[in,out] actual_tx_bytes			Actual transmit bytes,
 * @param[in] arg										Application provided argument (can be NULL)
 * @param[in] rx_callback							Application provided master's RX handling function.
 *																@note: The RX handling call back function is in the interrupt context. 
 *																			 
 *
 * @return Possible return @see enum sdr_err. 
 ****************************************************************************************
 */

int sdr_mstr_to_slv(char mode, uint32_t aa, char chn, char txr, char rxr, uint16_t mst_a, uint16_t slv_a, uint16_t rx_da_mask, uint16_t tx_len, uint8_t *tx_buf, uint16_t *actual_tx_bytes, void *arg, void(*rx_callback)(void *arg, rx_param_t *para));

/**
 ****************************************************************************************
 * @brief SDR slave transfer function 
 * @note: SDR slave can't initiate transfer, it has to wait for the masters.  At most 8 potential masters can
 *				receive responses from the slave, but only one will actually receive the slave's response.      
 *
 * @param[in] mode									Transfer mode, @see enum sdr_mode
 * @param[in] aa										Access address (common address shared by all the nodes)
 * @param[in] chn									Channel index (0 ~ 39),
 * @param[in] txr										Tx physical rate, @see enum sdr_phy_rate.
 * @param[in] rxr										Rx physical rate, @see enum sdr_phy_rate.
 * @param[in] rxw_sz								Rx window size (specify how long to wait for master's transfer); 
 *																	bit[15]: unit; 0=us, 1=312.5 us 
 *																	bit[0-14]: value, 
 * @param[in] slv_a									Slave address (your own address)
 * @param[in] rx_da_mask							Master's packets destination address mask for each address bit; 
 *																		1: match, 
 *																		0: don't care
 * @param[in] nb_mstr								Number of master devices that slave may response to (MAX=8).
 * @param[in] mst_a[8]							Master devices' address that slave may response to. 
 * @param[in] mst_a_mask[8]					Master devices' address mask (each address bits) that slave may response to:
 *																		1: match, 
 *																		0: don't care
 * @param[in] tx_len[8]							Application (Transmit) data buffer length for each master,
 * @param[in] tx_buf[8]							Application (Transmit) data buffer for each master,
 * @param[in,out] actual_tx_bytes[8]		Actual transmit bytes for one of the master,
 * @param[in] arg										Application provided argument (can be NULL)
 * @param[in] rx_callback							Application provided slave's RX handling function.
 *																@note: The RX handling call back function is in the interrupt context. 
 *																			 
 *
 * @return Possible return @see enum sdr_err. 
 ****************************************************************************************
 */

int sdr_slv_to_mstr(char mode, uint32_t aa, char chn, char txr, char rxr, uint16_t rxw_sz, uint16_t slv_a, uint16_t rx_da_mask, char nb_mstr, uint16_t mst_a[8], uint16_t mst_a_mask[8],  uint16_t tx_len[8], uint8_t *tx_buf[8], uint16_t actual_tx_bytes_array[8], void *arg, void(*rx_callback)(void *arg, rx_param_t *para));

#endif

