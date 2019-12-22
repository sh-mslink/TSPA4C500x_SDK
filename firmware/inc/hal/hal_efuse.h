/**
 ****************************************************************************************
 *
 * @file hal_efuse.h
 *
 * @brief eFuse Profile
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */
 
#ifndef HAL_EFUSE_H
#define HAL_EFUSE_H

/**
 ****************************************************************************************
 * @defgroup HAL_EFUSE eFuse Profile  
 * @ingroup HAL
 * @brief  HAL eFuse
 * @{
 ****************************************************************************************
 */

#include <stdint.h>
#include "in_mmap.h"

/*
 ****************************************************************************************
 * DEFINES
 ****************************************************************************************
 */					

/// eFuse ID control
typedef enum {
	/// eFuse controller 0.
	EFUSE0_ID,
	/// eFuse controller 1.
	EFUSE1_ID
} efuse_id ;

static __inline int efuse_intr_read_done(int id)
{
	if (id == EFUSE0_ID)
		return (RD_WORD(EFUSECTRL_REG_INTR_STATUS) &  EFUSECTRL_REG_INTR_STATUS_READ_DONE_0);
	else
		return (RD_WORD(EFUSECTRL_REG_INTR_STATUS) &  EFUSECTRL_REG_INTR_STATUS_READ_DONE_1);
}

static __inline int efuse_intr_prog_done(int id)
{
	if (id == EFUSE0_ID)
		return (RD_WORD(EFUSECTRL_REG_INTR_STATUS) & EFUSECTRL_REG_INTR_STATUS_PROG_DONE_0);
	else
		return (RD_WORD(EFUSECTRL_REG_INTR_STATUS) & EFUSECTRL_REG_INTR_STATUS_PROG_DONE_1);
}

static __inline void efuse_intr_read_done_clr(int id)
{
	if (id == EFUSE0_ID)
		WR_WORD(EFUSECTRL_REG_INTR_CLR, EFUSECTRL_REG_INTR_CLR_READ_DONE_0);
	else
		WR_WORD(EFUSECTRL_REG_INTR_CLR, EFUSECTRL_REG_INTR_CLR_READ_DONE_1);
}

static __inline void efuse_intr_prog_done_clr(int id)
{
	if (id == EFUSE0_ID)
		WR_WORD(EFUSECTRL_REG_INTR_CLR, EFUSECTRL_REG_INTR_CLR_PROG_DONE_0);
	else
		WR_WORD(EFUSECTRL_REG_INTR_CLR, EFUSECTRL_REG_INTR_CLR_PROG_DONE_1);
}

static __inline void efuse_enable(int id)
{
	if (id == EFUSE0_ID)
		WR_WORD(EFUSECTRL_REG_MISC_CTRL_0, EFUSECTRL_REG_MISC_CTRL_0_CTL_EFUSE_EN_0);
	else
		WR_WORD(EFUSECTRL_REG_MISC_CTRL_1, EFUSECTRL_REG_MISC_CTRL_1_CTL_EFUSE_EN_1);

}

static __inline void efuse_disable(int id)
{
	if (id == EFUSE0_ID)
		WR_WORD(EFUSECTRL_REG_MISC_CTRL_0, 0);
	else
		WR_WORD(EFUSECTRL_REG_MISC_CTRL_1, 0);

}

static __inline void efuse_prog_enable(int id)
{
	if (id == EFUSE0_ID)
		WR_WORD(EFUSECTRL_REG_MISC_CTRL_0, EFUSECTRL_REG_MISC_CTRL_0_CTL_EFUSE_EN_0 | EFUSECTRL_REG_MISC_CTRL_0_CTL_EFUSE_PROG_EN_0);
	else
		WR_WORD(EFUSECTRL_REG_MISC_CTRL_1, EFUSECTRL_REG_MISC_CTRL_1_CTL_EFUSE_EN_1 | EFUSECTRL_REG_MISC_CTRL_1_CTL_EFUSE_PROG_EN_1);
}

static __inline void efuse_prog_disable(int id)
{
	if (id == EFUSE0_ID)
		WR_WORD(EFUSECTRL_REG_MISC_CTRL_0, 0);
	else
		WR_WORD(EFUSECTRL_REG_MISC_CTRL_1, 0);
}

static __inline void efuse_prog_bit_start(int id, uint32_t bit_adr, int sel)
{
	if (id == EFUSE0_ID)
		WR_WORD(EFUSECTRL_REG_PROG_CTRL_0, EFUSECTRL_REG_PROG_CTRL_0_CTL_EFUSE_PROG_REQ_0 | 
			((bit_adr << EFUSECTRL_REG_PROG_CTRL_0_CTL_EFUSE_PROG_BIT_ADDR_0_SHIFT) & (EFUSECTRL_REG_PROG_CTRL_0_CTL_EFUSE_PROG_BIT_ADDR_0 | EFUSECTRL_REG_PROG_CTRL_0_CTL_EFUSE_PROG_ADDR_0)) |
			((sel & EFUSECTRL_REG_PROG_CTRL_0_CTL_EFUSE_PROG_EFUSE_SEL_0_MASK) << EFUSECTRL_REG_PROG_CTRL_0_CTL_EFUSE_PROG_EFUSE_SEL_0_SHIFT) );
	else
		WR_WORD(EFUSECTRL_REG_PROG_CTRL_1, EFUSECTRL_REG_PROG_CTRL_1_CTL_EFUSE_PROG_REQ_1 | 
			((bit_adr << EFUSECTRL_REG_PROG_CTRL_1_CTL_EFUSE_PROG_BIT_ADDR_1_SHIFT) & (EFUSECTRL_REG_PROG_CTRL_1_CTL_EFUSE_PROG_BIT_ADDR_1 | EFUSECTRL_REG_PROG_CTRL_1_CTL_EFUSE_PROG_ADDR_1)) |
			((sel & EFUSECTRL_REG_PROG_CTRL_1_CTL_EFUSE_PROG_EFUSE_SEL_1_MASK) << EFUSECTRL_REG_PROG_CTRL_1_CTL_EFUSE_PROG_EFUSE_SEL_1_SHIFT) );
}

static __inline void efuse_prog_bit_end(int id)
{
	if (id == EFUSE0_ID)
		WR_WORD(EFUSECTRL_REG_PROG_CTRL_0, 0);
	else
		WR_WORD(EFUSECTRL_REG_PROG_CTRL_1, 0);
}

#define EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_MODE_0_MASK                              (Bit0)
#define EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_MODE_0_SHIFT                             (16)

#define EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_MODE_1_MASK                              (Bit0)
#define EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_MODE_1_SHIFT                             (16)

#define EFUSE_READ_HWORD 0
#define EFUSE_READ_WORD 1

static __inline void efuse_read_bit_start(int id, int sel, uint32_t addr, int size)
{
	if (id == EFUSE0_ID)
		WR_WORD(EFUSECTRL_REG_READ_CTRL_0, (EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_REQ_0 | 
			((addr & EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_ADDR_0_MASK) << EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_ADDR_0_SHIFT) | 
			((sel & EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_EFUSE_SEL_0_MASK) << EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_EFUSE_SEL_0_SHIFT) | 
			((size & EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_MODE_0_MASK) << EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_MODE_0_SHIFT) ) );
	else
		WR_WORD(EFUSECTRL_REG_READ_CTRL_1, (EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_REQ_1 | 
			((addr & EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_ADDR_1_MASK) << EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_ADDR_1_SHIFT) | 
			((sel & EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_EFUSE_SEL_1_MASK) << EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_EFUSE_SEL_1_SHIFT) | 
			((size & EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_MODE_1_MASK) << EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_MODE_1_SHIFT) ) );
}

static __inline void efuse_read_bit_end(int id)
{
	if (id == EFUSE0_ID)
		WR_WORD(EFUSECTRL_REG_READ_CTRL_0, 0);
	else
		WR_WORD(EFUSECTRL_REG_READ_CTRL_1, 0);
}

static __inline uint32_t efuse_read_value(int id)
{
	if (id == EFUSE0_ID)
		return RD_WORD(EFUSECTRL_REG_READ_VAL_0);
	else
		return RD_WORD(EFUSECTRL_REG_READ_VAL_1);
}

static __inline void efuse0_set_prog_ctrl_reg(uint32_t val)
{
	WR_WORD(EFUSECTRL_REG_PROG_CTRL_0, val);
}

static __inline void efuse1_set_prog_ctrl_reg(uint32_t val)
{
	WR_WORD(EFUSECTRL_REG_PROG_CTRL_1, val);
}

static __inline uint32_t efuse0_get_prog_ctrl_reg(void)
{
	return RD_WORD(EFUSECTRL_REG_PROG_CTRL_0);
}

static __inline uint32_t efuse1_get_prog_ctrl_reg(void)
{
	return RD_WORD(EFUSECTRL_REG_PROG_CTRL_1);
}

static uint32_t efuse_read_word(int id, int sel, uint8_t addr)
{
	uint32_t data;

	efuse_enable(id);
	efuse_read_bit_start(id, sel, addr, EFUSE_READ_WORD);
	while (!efuse_intr_read_done(id));			
	data = efuse_read_value(id);
	efuse_intr_read_done_clr(id);							
	efuse_read_bit_end(id);
	efuse_disable(id);

	return data;
}

static __inline uint32_t efuse_get_inplay_init_rd_val(void)
{
	return RD_WORD(EFUSECTRL_REG_INPLAY_INIT_RD_VAL);
}

static __inline uint32_t efuse_get_inplay_efuse_lock(void)
{
	return (efuse_get_inplay_init_rd_val() & EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_EFUSE_LOCK);
}

static __inline uint32_t efuse_get_spiflash_present(void)
{
	return ((efuse_get_inplay_init_rd_val() & EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_SPIFLASH_PRESENT) >> 1);
}

static __inline uint32_t efuse_get_inplay_feature_sel(void)
{
	return ((efuse_get_inplay_init_rd_val() & EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_FEATURE_SEL_MASK) >> EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_FEATURE_SEL_SHIFT);
}

static __inline uint32_t efuse_get_inplay_security_key_sel(void)
{
	return ((efuse_get_inplay_init_rd_val() & EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_SECURITY_KEY_SEL_MASK) >> EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_SECURITY_KEY_SEL_SHIFT);
}

static __inline uint32_t efuse_get_inplay_security_key_alg(void)
{
	return ((efuse_get_inplay_init_rd_val() & EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_SECURITY_KEY_ALG_MASK) >> EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_SECURITY_KEY_ALG_SHIFT);
}

static __inline uint32_t efuse_get_uuid0(void)
{
	return RD_WORD(EFUSECTRL_REG_UUID0);
}

static __inline uint32_t efuse_get_uuid1(void)
{
	return RD_WORD(EFUSECTRL_REG_UUID1);
}

static __inline uint32_t efuse_get_uuid2(void)
{
	return RD_WORD(EFUSECTRL_REG_UUID2);
}

static __inline uint32_t efuse_get_uuid3(void)
{
	return RD_WORD(EFUSECTRL_REG_UUID3);
}

static __inline uint32_t efuse_get_cust_init_rd_val(void)
{
	return RD_WORD(EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE);
}

static __inline uint32_t efuse_get_cust_efuse_lock(void)
{
	return (efuse_get_cust_init_rd_val() & EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_CUSTOMER_EFUSE_LOCK);
}

static __inline uint32_t efuse_get_cm4_dbg_disable(void)
{
	return ((efuse_get_cust_init_rd_val() & EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_CM4_DBG_DISABLE) >> 1);
}

static __inline uint32_t efuse_get_flash_encryption_enable(void)
{
	return ((efuse_get_cust_init_rd_val() & EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_FLASH_ENCRYPTION_ENABLE) >> 2);
}

static __inline uint32_t efuse_get_flash_secure_boot_enable(void)
{
	return ((efuse_get_cust_init_rd_val() & EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_FLASH_SECURE_BOOT_ENABLE) >> 3);
}

static __inline uint32_t efuse_get_ram_secure_boot_enable(void)
{
	return ((efuse_get_cust_init_rd_val() & EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_RAM_SECURE_BOOT_ENABLE) >> 4);
}

static __inline uint32_t efuse_get_ecc_len_secure_boot(void)
{
	return ((efuse_get_cust_init_rd_val() & EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_ECC_LEN_SECURE_BOOT) >> 5);
}

static __inline uint32_t efuse_get_default_interface_enable(void)
{
	return ((efuse_get_cust_init_rd_val() & EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_DEFAULT_IF_EN) >> 8);
}

static __inline uint32_t efuse_get_default_interface_selection(void)
{
	return ((efuse_get_cust_init_rd_val() & EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_DEFAULT_IF_SEL_MASK) >> EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_DEFAULT_IF_SEL_SHIFT);
}

static __inline int efuse_get_rtc_installed(void)
{
	return ((efuse_get_cust_init_rd_val() >> 16) & 1);
}

static __inline int efuse_rtc_32khz_clk(void)
{
	return ((RD_WORD(EFUSECTRL_REG_INIT_RD_VALUE_0_0) >> 14) & 1);
}

static __inline uint32_t efuse_get_customer_id(void)
{
	return RD_WORD(EFUSECTRL_REG_CUSTOMER_ID);
}

static __inline void efuse_hw_upd_wait(void)
{
	uint32_t reg;

	do {
		reg = RD_WORD(EFUSECTRL_REG_MISC_STS_0);
		if (((reg >> EFUSECTRL_REG_MISC_STS_0_STS_EFUSE_CURR_STATE_0_SHIFT) & EFUSECTRL_REG_MISC_STS_0_STS_EFUSE_CURR_STATE_0_MASK) == 0xC)
			break;
	} while(1);

	do {
		reg = RD_WORD(EFUSECTRL_REG_MISC_STS_1);
		if (((reg >> EFUSECTRL_REG_MISC_STS_1_STS_EFUSE_CURR_STATE_1_SHIFT) & EFUSECTRL_REG_MISC_STS_1_STS_EFUSE_CURR_STATE_1_MASK) == 0xC)
			break;
	} while(1);

	return;

}

/// eFuse ID control
typedef enum {
	/// eFuse bank 0.
	EFUSE_BANK_0,
	/// eFuse bank 1.
	EFUSE_BANK_1,
	/// eFuse bank 2.
	EFUSE_BANK_2,
} efuse_bank_id;

/// eFuse status result
typedef enum {
	/// No error. Good. 
	EFUSE_ERR_OK = 0,
	/// Error. Invalid param.
	EFUSE_ERR_INVALID_PARAM = -1,
	/// Error. Bad state.
	EFUSE_ERR_DEV_BAD_STATE = -2,
	/// Error. eFuse not initialized
	EFUSE_ERR_EFUSE_NOT_INITIALIZED = -3,
	/// Error. eFuse already initialized
	EFUSE_ERR_EFUSE_ALREADY_INITIALIZED = -4,
} efuse_result_status;

/**
 ****************************************************************************************
 * @brief Initialize eFuse driver.
 *
 * @return EFUSE_ERR_OK if eFuse initializes successfully, error otherwise. @see enum efuse_result_status.
 ****************************************************************************************
 */
int hal_efuse_open(void);

/**
 ****************************************************************************************
 * @brief Stop and cleanup eFuse driver.
 *
 * @return EFUSE_ERR_OK if efuse uninitializes successfully, error otherwise. @see enum efuse_result_status.
 ****************************************************************************************
 */
int hal_efuse_close(void);

/**
 ****************************************************************************************
 * @brief Read eFuse word.
 *
 * @param[in] bank_id		eFuse bank ID number to be read.
 * @param[in] word_num		eFuse bank word number to be read.
 * @param[in] out			Pointer to write location of eFuse word.
 *
 * @return EFUSE_ERR_OK if eFuse read word is successful, error otherwise. @see enum efuse_result_status.
 ****************************************************************************************
 */
int hal_efuse_read_word(int bank_id, int word_num, uint32_t* out);

/**
 ****************************************************************************************
 * @brief Write eFuse word.
 *
 * @param[in] bank_id		eFuse bank ID number to be read.
 * @param[in] word_num		eFuse bank word number to be read.
 * @param[in] data			Data to be written to eFuse word.
 *
 * @return EFUSE_ERR_OK if eFuse write word is successful, error otherwise. @see enum efuse_result_status.
 ****************************************************************************************
 */
int hal_efuse_write_word(int bank_id, int word_num, uint32_t data);

/**
 ****************************************************************************************
 * @brief Check Tropos eFuse lock.
 *
 * @return 1 if eFuse is locked for future writes, 0 if not locked.
 ****************************************************************************************
 */
int hal_efuse_status_inplay_lock(void);

/**
 ****************************************************************************************
 * @brief Check if external spiflash is present.
 *
 * @return 1 if external spiflash is present, 0 if not present.
 ****************************************************************************************
 */
int hal_efuse_status_spiflash(void);

/**
 ****************************************************************************************
 * @brief Return Tropos feature set selection.
 *
 * @return Tropos feature set selection.
 ****************************************************************************************
 */
int hal_efuse_status_feature_sel(void);

/**
 ****************************************************************************************
 * @brief Return Tropos security key selection.
 *
 * @return Tropos security key selection.
 ****************************************************************************************
 */
int hal_efuse_status_sec_key_sel(void);

/**
 ****************************************************************************************
 * @brief Return Tropos security key algorithm selection.
 *
 * @return Tropos security key algorithm selection.
 ****************************************************************************************
 */
int hal_efuse_status_sec_key_alg(void);
/**
 ****************************************************************************************
 * @brief Return eFuse UUID.
 *
 * @param[in] out			Pointer to write location of eFuse UUID. Result written in Big Endian format.
 ****************************************************************************************
 */
void hal_efuse_get_uuid(uint32_t* out);

/**
 ****************************************************************************************
 * @brief Check customer eFuse lock.
 *
 * @return 1 if eFuse is locked for future writes, 0 if not locked.
 ****************************************************************************************
 */
int hal_efuse_status_cust_lock(void);

/**
 ****************************************************************************************
 * @brief Check if CM4 debugging port is enabled.
 *
 * @return 1 if CM4 debugging port is enabled, 0 if disabled.
 ****************************************************************************************
 */
int hal_efuse_status_cm4_dbg(void);

/**
 ****************************************************************************************
 * @brief Check if flash data encryption is enabled.
 *
 * @return 1 if flash data encryption is enabled, 0 if disabled.
 ****************************************************************************************
 */
int hal_efuse_status_flash_enc_en(void);

/**
 ****************************************************************************************
 * @brief Check if flash secure boot is enabled.
 *
 * @return 1 if flash secure boot is enabled, 0 if disabled.
 ****************************************************************************************
 */
int hal_efuse_status_flash_secure_boot_enable(void);

/**
 ****************************************************************************************
 * @brief Check if RAM secure boot is enabled.
 *
 * @return 1 if RAM secure boot is enabled, 0 if disabled.
 ****************************************************************************************
 */
int hal_efuse_status_ram_secure_boot_en(void);

/**
 ****************************************************************************************
 * @brief Check secure boot ECC key length.
 *
 * @return 0 if secure boot ECC key length if 192-bits, 1 if key length is 256-bits.
 ****************************************************************************************
 */
int hal_efuse_status_ecc_len_secure_boot(void);

/**
 ****************************************************************************************
 * @brief Check if eFuse default interface is enabled.
 *
 * @return 1 if eFuse default interface is enabled, 0 if disabled.
 ****************************************************************************************
 */
int hal_efuse_status_interface_en(void);

/**
 ****************************************************************************************
 * @brief Return eFuse default interface selection.
 *
 * @return Default eFuse interface selection.
 ****************************************************************************************
 */
int hal_efuse_status_interface_sel(void);

/**
 ****************************************************************************************
 * @brief Check if real-time clock (RTC) is enabled.
 *
 * @return 1 if RTC is installed, 0 if not installed.
 ****************************************************************************************
 */
int hal_efuse_status_rtc(void);

/**
 ****************************************************************************************
 * @brief Return customer ID.
 *
 * @param[in] out			Pointer to write location of eFuse customer id.
 ****************************************************************************************
 */
void hal_efuse_get_customer_id(uint32_t* out);


#endif
