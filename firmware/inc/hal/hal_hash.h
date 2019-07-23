/**
 ****************************************************************************************
 *
 * @file hal_hash.h
 *
 * @brief Cryptographic Hash Profile
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef HAL_HASH_H
#define HAL_HASH_H

/**
 ****************************************************************************************
 * @defgroup HAL_HASH Cryptographic Hash Profile 
 * @ingroup HAL
 * @brief  HAL HASH
 * @{
 ****************************************************************************************
 */

#include "stdint.h"
#include "in_mmap.h"

/*
 ****************************************************************************************
 * DEFINES
 ****************************************************************************************
 */				

#define HASH_REG_OFFSET_HASH_H0							0x00000640UL
#define HASH_REG_OFFSET_HASH_H1							0x00000644UL
#define HASH_REG_OFFSET_HASH_H2							0x00000648UL
#define HASH_REG_OFFSET_HASH_H3							0x0000064CUL
#define HASH_REG_OFFSET_HASH_H4							0x00000650UL
#define HASH_REG_OFFSET_HASH_H5							0x00000654UL
#define HASH_REG_OFFSET_HASH_H6							0x00000658UL
#define HASH_REG_OFFSET_HASH_H7							0x0000065CUL
#define HASH_REG_OFFSET_HASH_HX_MASK					0xFFFFFFFFUL
#define HASH_REG_OFFSET_HASH_CONTROL					0x000007C0UL
#define HASH_REG_OFFSET_HASH_CONTROL_MASK				0x00000003UL
#define HASH_REG_OFFSET_HASH_PAD_EN						0x000007C4UL
#define HASH_REG_OFFSET_HASH_PAD_EN_MASK				0x00000001UL
#define HASH_REG_OFFSET_HASH_PAD_CFG					0x000007C8UL
#define HASH_REG_OFFSET_HASH_PAD_CFG_MASK				0x00000004UL
#define HASH_REG_OFFSET_HASH_CUR_LEN_0					0x000007CCUL
#define HASH_REG_OFFSET_HASH_CUR_LEN_1					0x000007D0UL
#define HASH_REG_OFFSET_HASH_CUR_LEN_X_MASK				0xFFFFFFFFUL
#define HASH_REG_OFFSET_HASH_PARAM						0x000007DCUL
#define HASH_REG_OFFSET_HASH_INT_BUSY					0x000007E0UL
#define HASH_REG_OFFSET_HASH_INT_BUSY_MASK				0x00000001UL
#define HASH_REG_OFFSET_HASH_SW_RESET					0x000007E4UL
#define HASH_REG_OFFSET_HASH_SW_RESET_MASK				0x00000001UL
#define HASH_REG_OFFSET_HASH_SWAP						0x000007E8UL
#define HASH_REG_OFFSET_HASH_SWAP_MASK					0x00000001UL
#define HASH_REG_OFFSET_HASH_DIRECT_DATA				0x000007ECUL
#define HASH_REG_OFFSET_HASH_DIRECT_DATA_MASK			0xFFFFFFFFUL


#define HASH_REG_OFFSET_HASH_CONTROL_MD5				0x00000000UL
#define HASH_REG_OFFSET_HASH_CONTROL_SHA1				0x00000001UL
#define HASH_REG_OFFSET_HASH_CONTROL_SHA256				0x00000002UL

/// HASH function type
typedef enum {
	/// HASH type MD-5
	HASH_TYPE_MD5 = 0,
	/// HASH type SHA-1
	HASH_TYPE_SHA1 = 1,
	/// HASH type SHA-256
	HASH_TYPE_SHA256 = 2
} hash_type;

static __inline void hash_md5_mode(void)
{
	uint32_t reg = RD_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_CONTROL);
	reg &= ~(HASH_REG_OFFSET_HASH_CONTROL_MASK);
	reg |= HASH_REG_OFFSET_HASH_CONTROL_MD5;
	WR_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_CONTROL, reg);
}

static __inline void hash_sha1_mode(void)
{
	uint32_t reg = RD_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_CONTROL);
	reg &= ~(HASH_REG_OFFSET_HASH_CONTROL_MASK);
	reg |= HASH_REG_OFFSET_HASH_CONTROL_SHA1;
	WR_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_CONTROL, reg);
}

static __inline void hash_sha256_mode(void)
{
	uint32_t reg = RD_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_CONTROL);
	reg &= ~(HASH_REG_OFFSET_HASH_CONTROL_MASK);
	reg |= HASH_REG_OFFSET_HASH_CONTROL_SHA256;
	WR_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_CONTROL, reg);
}

static __inline void hash_pad_block_enable(void)
{
	uint32_t reg = RD_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_PAD_EN);
	reg |= (HASH_REG_OFFSET_HASH_PAD_EN_MASK);
	WR_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_PAD_EN, reg);
}

static __inline void hash_pad_block_disable(void)
{
	uint32_t reg = RD_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_PAD_EN);
	reg &= ~(HASH_REG_OFFSET_HASH_PAD_EN_MASK);
	WR_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_PAD_EN, reg);
}

static __inline void hash_padding_generation_set(void)
{
	uint32_t reg = RD_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_PAD_CFG);
	reg |= (HASH_REG_OFFSET_HASH_PAD_CFG_MASK);
	WR_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_PAD_CFG, reg);
}

static __inline void hash_padding_generation_reset(void)
{
	uint32_t reg = RD_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_PAD_CFG);
	reg &= ~(HASH_REG_OFFSET_HASH_PAD_CFG_MASK);
	WR_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_PAD_CFG, reg);
}

static __inline void hash_len_low_word(uint32_t len0)
{
	WR_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_CUR_LEN_0, len0);
}

static __inline void hash_len_high_word(uint32_t len1)
{
	WR_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_CUR_LEN_1, len1);
}

static __inline int hash_busy(void)
{
	return (RD_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_INT_BUSY) & HASH_REG_OFFSET_HASH_INT_BUSY_MASK);
}

static __inline void hash_sw_reset(void)
{
	uint32_t reg = RD_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_SW_RESET);
	reg |= (HASH_REG_OFFSET_HASH_SW_RESET_MASK);
	WR_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_SW_RESET, reg);
}

static __inline void hash_data_swap_enable(void)
{
	uint32_t reg = RD_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_SWAP);
	reg &= ~(HASH_REG_OFFSET_HASH_SWAP_MASK);
	WR_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_SWAP, reg);
}

static __inline void hash_data_swap_disable(void)
{
	uint32_t reg = RD_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_SWAP);
	reg |= (HASH_REG_OFFSET_HASH_SWAP_MASK);
	WR_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_SWAP, reg);
}

#define HASH_REG_OFFSET_DATA_WR_PORT										0x00000900UL

static __inline void hash_write_data(uint32_t data)
{
	while(hash_busy() == 0x1) ;
	WR_WORD(SHA_BASE + HASH_REG_OFFSET_DATA_WR_PORT, data);
}

static __inline void hash_write_hx(int idx, uint32_t data)
{
	WR_WORD((SHA_BASE + HASH_REG_OFFSET_HASH_H0 + (4 * idx)), (data & HASH_REG_OFFSET_HASH_HX_MASK));
}

static __inline uint32_t hash_read_hx(int idx)
{
	return RD_WORD(SHA_BASE + HASH_REG_OFFSET_HASH_H0 + (4 * idx));
}
	
static __inline void hash_write_to_port(uint8_t *chunk) {
	for(int i = 0; i < 64; i+= 4) {
		hash_write_data((chunk[i+3]<<24) | (chunk[i+2]<<16) | (chunk[i+1]<<8) | (chunk[i]));
	}
}

#define HASH_REG_OFFSET_INTR											0x00000800UL
#define HASH_REG_OFFSET_INTR_EN											0x00000040UL
#define HASH_REG_OFFSET_INTR_CLR										0x00000080UL
#define HASH_REG_OFFSET_INTR_STATUS										0x00000100UL
	
static __inline void hash_intr_unmask() {
	uint32_t reg = RD_WORD(SHA_BASE + HASH_REG_OFFSET_INTR);
	reg |= (HASH_REG_OFFSET_INTR_EN);
	WR_WORD(SHA_BASE + HASH_REG_OFFSET_INTR, reg);
}

static __inline void hash_intr_mask() {
	uint32_t reg = RD_WORD(SHA_BASE + HASH_REG_OFFSET_INTR);
	reg &= ~(HASH_REG_OFFSET_INTR_EN);
	WR_WORD(SHA_BASE + HASH_REG_OFFSET_INTR, reg);
}
	
static __inline void hash_intr_clr() {
	uint32_t reg = RD_WORD(SHA_BASE + HASH_REG_OFFSET_INTR);
	reg &= ~(HASH_REG_OFFSET_INTR_CLR);
	WR_WORD(SHA_BASE + HASH_REG_OFFSET_INTR, reg);
}

static __inline uint8_t hash_intr_status() {
	return ((RD_WORD(SHA_BASE + HASH_REG_OFFSET_INTR) & HASH_REG_OFFSET_INTR_STATUS) > 0) ? 1 : 0;
}

/// HASH function status return
typedef enum {
	/// No errors, good status. 
	HASH_ERR_OK = 0,
	/// Error, HASH driver not initialized
	HASH_ERR_NOT_INIT = 1,
	/// Error, HASH driver already initialized
	HASH_ERR_ALREADY_INIT = 2,
	/// Error, HASH bad state 
	HASH_ERR_DEV_BAD_STATE = 3,
	/// Error, invalid HASH parameter. 
	HASH_ERR_INVALID_PARA = 4
} HASH_result_status;

/**
 ****************************************************************************************
 * @brief Initialize hash driver for power management and interrupt purposes.
 *
 * @return HASH_ERR_OK if HASH initializes successfully, error otherwise. @see enum HASH_result_status.
 ****************************************************************************************
 */
int hal_hash_open(void);

/**
 ****************************************************************************************
 * @brief De-Initialize hash driver for power management and interrupt purposes.
 *
 * @return HASH_ERR_OK if HASH uninitializes successfully, error otherwise. @see enum HASH_result_status.
 ****************************************************************************************
 */
int hal_hash_close(void);

/**
 ****************************************************************************************
 * @brief Set-up and initialize hash functionality
 *
 * @param[in] type					Hash functionality type, @see enum hash_type
 *
 * @return HASH_ERR_OK if successful, error otherwise. @see enum HASH_result_status
 ****************************************************************************************
 */
int hal_hash_start(hash_type type);

/**
 ****************************************************************************************
 * @brief Process hash based on input payload
 *
 * @param[in] type					Hash functionality type, @see enum hash_type
 * @param[in] data					Pointer to data to be hashed
 * @param[in] data_len				Length of data to be hashed in bytes
 *
 * @return HASH_ERR_OK if successful, error otherwise. @see enum HASH_result_status
 ****************************************************************************************
 */
int hal_hash_process(hash_type type, uint8_t *data, uint32_t data_len);

/**
 ****************************************************************************************
 * @brief Write hash result to output buffer
 *
 * @param[in] type					Hash functionality type, @see enum hash_type
 * @param[out] out					Pointer to output of HASH result
 *
 * @return HASH_ERR_OK if successful, error otherwise. @see enum HASH_result_status
 ****************************************************************************************
 */
int hal_hash_finish(hash_type type, uint8_t *out);





	
#endif




