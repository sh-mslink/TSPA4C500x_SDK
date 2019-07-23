/**
 ****************************************************************************************
 *
 * @file hal_aes.h
 *
 * @brief Advanced Encryption Standard Cryptography Profile
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef HAL_AES_H
#define HAL_AES_H

/**
 ****************************************************************************************
 * @defgroup HAL_AES Advanced Encryption Standard Cryptography Profile  
 * @ingroup HAL
 * @brief  HAL AES
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

#define  	 AES_DATA_BLOCK_OFFSET_INDEX						0x0400
#define 	 AES_CONTEXT_BLOCK_OFFSET_INDEX					0x0800
#define 	 AES_CONTEXT_MEMORY_BLOCK0_INDEX				0x0000
#define 	 AES_CONTEXT_MEMORY_BLOCK1_INDEX				0x0020
#define 	 AES_CONTEXT_MEMORY_BLOCK2_INDEX				0x0030
#define 	 AES_CONTEXT_MEMORY_BLOCK3_INDEX				0x0040
#define 	 AES_CONTEXT_MEMORY_BLOCK4_INDEX				0x0050

#define 	 AES_DATA_BASE													AES_REG_BASE + AES_DATA_BLOCK_OFFSET_INDEX
#define 	 AES_CONTEXT_MEMORY_BLOCK0_BASE					AES_REG_BASE + AES_CONTEXT_BLOCK_OFFSET_INDEX + AES_CONTEXT_MEMORY_BLOCK0_INDEX
#define 	 AES_CONTEXT_MEMORY_BLOCK1_BASE					AES_REG_BASE + AES_CONTEXT_BLOCK_OFFSET_INDEX + AES_CONTEXT_MEMORY_BLOCK1_INDEX
#define 	 AES_CONTEXT_MEMORY_BLOCK2_BASE					AES_REG_BASE + AES_CONTEXT_BLOCK_OFFSET_INDEX + AES_CONTEXT_MEMORY_BLOCK2_INDEX
#define 	 AES_CONTEXT_MEMORY_BLOCK3_BASE					AES_REG_BASE + AES_CONTEXT_BLOCK_OFFSET_INDEX + AES_CONTEXT_MEMORY_BLOCK3_INDEX
#define 	 AES_CONTEXT_MEMORY_BLOCK4_BASE					AES_REG_BASE + AES_CONTEXT_BLOCK_OFFSET_INDEX + AES_CONTEXT_MEMORY_BLOCK4_INDEX

/// AES function status return
typedef enum {
	/// No errors, good status. 
	AES_ERR_OK = 0,
	/// Error, AES driver not initialized
	AES_ERR_NOT_INIT = 1,
	/// Error, AES driver already initialized
	AES_ERR_ALREADY_INIT = 2,
	/// Error, AES bad state 
	AES_ERR_DEV_BAD_STATE = 3,
	/// Error, MAC verification failure 
	AES_ERR_MAC_DOES_NOT_MATCH = 4,
	/// Error, ECC using the HW memory 
	AES_ERR_HW_MEM_USED_BY_ECC = 5
} aes_crypto_status;

/// AES cryptography type
typedef enum {
	/// AES encryption
	AES_CRYPTO_TYPE_ENCRYPT = 1,
	/// AES decryption
	AES_CRYPTO_TYPE_DECRYPT = 0
} aes_crypto_type ;

/// AES cryptography mode
typedef enum {
	/// AES ECB mode (Electronic Codebook mode)
	AES_CRYPTO_MODE_ECB = 0,
	/// AES CBC mode (Cipher Block Chaining mode)
	AES_CRYPTO_MODE_CBC = 1,
	/// AES CTR mode (Counter mode)
	AES_CRYPTO_MODE_CTR = 2,
	/// AES CCM mode (Counter with CBC-MAC mode)
	AES_CRYPTO_MODE_CCM = 3,
	/// AES CMAC mode (Cipher-based Message Authentication Code mode)
	AES_CRYPTO_MODE_CMAC = 4,
	/// AES F8 mode
	AES_CRYPTO_MODE_F8 = 9
} aes_crypto_mode ;

/// AES cryptography key size
typedef enum {
	/// AES 128-bit key size
	AES_KEY_SIZE_128 = 0,
	/// AES 196-bit key size
	AES_KEY_SIZE_196 = 1,
	/// AES 256-bit key size
	AES_KEY_SIZE_256 = 2
} aes_key_size ;

static __inline void aes_set_misc_ctrl_go(void)
{
	uint32_t reg = RD_WORD(AES_REG_MISC_CTRL);
	reg |= AES_REG_MISC_CTRL_GO;
	WR_WORD(AES_REG_MISC_CTRL, reg);
}

static __inline void aes_clr_misc_ctrl_go(void)
{
	uint32_t reg = RD_WORD(AES_REG_MISC_CTRL);
	reg &= ~AES_REG_MISC_CTRL_GO;
	WR_WORD(AES_REG_MISC_CTRL, reg);
}

static __inline void aes_set_misc_ctrl_type(aes_crypto_type type)
{
	uint32_t reg = RD_WORD(AES_REG_MISC_CTRL);
	if(type == AES_CRYPTO_TYPE_ENCRYPT)
		reg |= AES_REG_MISC_CTRL_ENCRYPT;
	else
		reg &= ~(AES_REG_MISC_CTRL_ENCRYPT);

	WR_WORD(AES_REG_MISC_CTRL, reg);
}

static __inline aes_crypto_type aes_get_misc_ctrl_type(void)
{
	uint32_t reg = ((RD_WORD(AES_REG_MISC_CTRL) & AES_REG_MISC_CTRL_ENCRYPT) >> 1);
	if(reg)
		return AES_CRYPTO_TYPE_ENCRYPT;
	else
		return AES_CRYPTO_TYPE_DECRYPT;
}

static __inline void aes_set_misc_ctrl_msg_begin(void)
{
	uint32_t reg = RD_WORD(AES_REG_MISC_CTRL);
	reg |= AES_REG_MISC_CTRL_MSG_BEGIN;
	WR_WORD(AES_REG_MISC_CTRL, reg);
}

static __inline void aes_clr_misc_ctrl_msg_begin(void)
{
	uint32_t reg = RD_WORD(AES_REG_MISC_CTRL);
	reg &= ~AES_REG_MISC_CTRL_MSG_BEGIN;
	WR_WORD(AES_REG_MISC_CTRL, reg);
}

static __inline void aes_set_misc_ctrl_msg_end(void)
{
	uint32_t reg = RD_WORD(AES_REG_MISC_CTRL);
	reg |= AES_REG_MISC_CTRL_MSG_END;
	WR_WORD(AES_REG_MISC_CTRL, reg);
}

static __inline void aes_clr_misc_ctrl_msg_end(void)
{
	uint32_t reg = RD_WORD(AES_REG_MISC_CTRL);
	reg &= ~AES_REG_MISC_CTRL_MSG_END;
	WR_WORD(AES_REG_MISC_CTRL, reg);
}

static __inline void aes_set_misc_ctrl_mode(aes_crypto_mode mode)
{
	uint32_t reg = RD_WORD(AES_REG_MISC_CTRL);
	uint8_t val;
	if(mode == AES_CRYPTO_MODE_ECB)
		val = 0;
	else if(mode == AES_CRYPTO_MODE_CBC)
		val = 1;
	else if(mode == AES_CRYPTO_MODE_CTR)
		val = 2;
	else if(mode == AES_CRYPTO_MODE_CCM)
		val = 3;
	else if(mode == AES_CRYPTO_MODE_CMAC)
		val = 4;
	else if(mode == AES_CRYPTO_MODE_F8)
		val = 9;
	reg &= ~(AES_REG_MISC_CTRL_MODE);
	reg |= ((val & AES_REG_MISC_CTRL_MODE_MASK) << AES_REG_MISC_CTRL_MODE_SHIFT);
	WR_WORD(AES_REG_MISC_CTRL, reg);
}

static __inline aes_crypto_mode aes_get_misc_ctrl_mode(void)
{
	uint32_t reg = ((RD_WORD(AES_REG_MISC_CTRL) & AES_REG_MISC_CTRL_MODE) >> AES_REG_MISC_CTRL_MODE_SHIFT);
	if(reg == 0)
		return AES_CRYPTO_MODE_ECB;
	else if(reg == 1)
		return AES_CRYPTO_MODE_CBC;
	else if(reg == 2)
		return AES_CRYPTO_MODE_CTR;
	else if(reg == 3)
		return AES_CRYPTO_MODE_CCM;
	else if(reg == 4)
		return AES_CRYPTO_MODE_CMAC;
	else
		return AES_CRYPTO_MODE_F8;
}

static __inline void aes_set_misc_ctrl_mac_len(uint8_t length)
{
	uint32_t reg = RD_WORD(AES_REG_MISC_CTRL);
	reg &= ~(AES_REG_MISC_CTRL_MAC_LEN);
	reg |= ((length & AES_REG_MISC_CTRL_MAC_LEN_MASK) << AES_REG_MISC_CTRL_MAC_LEN_SHIFT);
	WR_WORD(AES_REG_MISC_CTRL, reg);
}

static __inline uint8_t aes_get_misc_ctrl_mac_len(void)
{
	return ((RD_WORD(AES_REG_MISC_CTRL) & AES_REG_MISC_CTRL_MAC_LEN) >> AES_REG_MISC_CTRL_MAC_LEN_SHIFT);
}

static __inline void aes_set_misc_ctrl_key_size(aes_key_size size)
{
	uint32_t reg = RD_WORD(AES_REG_MISC_CTRL);
	uint8_t val;
	if(size == AES_KEY_SIZE_128)
		val = 0;
	else if(size == AES_KEY_SIZE_196)
		val = 1;
	else if(size == AES_KEY_SIZE_256)
		val = 2;
	reg &= ~(AES_REG_MISC_CTRL_KEY_SIZE);
	reg |= ((val & AES_REG_MISC_CTRL_KEY_SIZE_MASK) << AES_REG_MISC_CTRL_KEY_SIZE_SHIFT);
	WR_WORD(AES_REG_MISC_CTRL, reg);
}

static __inline aes_key_size aes_get_misc_ctrl_key_size(void)
{
	uint32_t reg = ((RD_WORD(AES_REG_MISC_CTRL) & AES_REG_MISC_CTRL_KEY_SIZE) >> AES_REG_MISC_CTRL_KEY_SIZE_SHIFT);
	if(reg == 0)
		return AES_KEY_SIZE_128;
	else if(reg == 1)
		return AES_KEY_SIZE_196;
	else
		return AES_KEY_SIZE_256;
}

static __inline void aes_set_misc_ctrl_str_ctx(void)
{
	uint32_t reg = RD_WORD(AES_REG_MISC_CTRL);
	reg |= AES_REG_MISC_CTRL_STR_CTX;
	WR_WORD(AES_REG_MISC_CTRL, reg);
}

static __inline void aes_clr_misc_ctrl_str_ctx(void)
{
	uint32_t reg = RD_WORD(AES_REG_MISC_CTRL);
	reg &= ~AES_REG_MISC_CTRL_STR_CTX;
	WR_WORD(AES_REG_MISC_CTRL, reg);
}

static __inline void aes_set_misc_ctrl_ret_ctx(void)
{
	uint32_t reg = RD_WORD(AES_REG_MISC_CTRL);
	reg |= AES_REG_MISC_CTRL_RET_CTX;
	WR_WORD(AES_REG_MISC_CTRL, reg);
}

static __inline void aes_clr_misc_ctrl_ret_ctx(void)
{
	uint32_t reg = RD_WORD(AES_REG_MISC_CTRL);
	reg &= ~AES_REG_MISC_CTRL_RET_CTX;
	WR_WORD(AES_REG_MISC_CTRL, reg);
}

#define AES_CTX_INDEX												0x0000000F

#define AES_BLOCK_INDEX												0x00000003

#define AES_AAD_LENGTH												0x0000007F

static __inline void aes_set_aad_length(uint32_t length)
{
	uint32_t reg = RD_WORD(AES_REG_AAD_LENGTH);
	reg &= ~(AES_REG_AAD_LENGTH_LENGTH);
	reg |= (length & AES_REG_AAD_LENGTH_LENGTH_MASK);
	WR_WORD(AES_REG_AAD_LENGTH, reg);
}

static __inline uint32_t aes_get_aad_length(void)
{
	return (RD_WORD(AES_REG_AAD_LENGTH) & AES_REG_AAD_LENGTH_LENGTH_MASK);
}

#define AES_NUM_BYTES												0x0000007F

static __inline void aes_set_num_bytes(uint32_t num)
{
	uint32_t reg = RD_WORD(AES_REG_NUM_BYTES);
	reg &= ~(AES_REG_NUM_BYTES_NUM_BYTES);
	reg |= (num & AES_REG_NUM_BYTES_NUM_BYTES_MASK);
	WR_WORD(AES_REG_NUM_BYTES, reg);
}

static __inline uint32_t aes_get_num_bytes(void)
{
	return (RD_WORD(AES_REG_NUM_BYTES) & AES_REG_NUM_BYTES_NUM_BYTES_MASK);
}

#define AES_NUM_TOTAL_BYTES											0x0000FFFF

static __inline void aes_set_num_total_bytes(uint32_t num)
{
	uint32_t reg = RD_WORD(AES_REG_NUM_TOTAL_BYTES);
	reg &= ~(AES_REG_NUM_TOTAL_BYTES_NUM_TOTAL_BYTES);
	reg |= (num & AES_REG_NUM_TOTAL_BYTES_NUM_TOTAL_BYTES_MASK);
	WR_WORD(AES_REG_NUM_TOTAL_BYTES, reg);
}

static __inline uint32_t aes_get_num_total_bytes(void)
{
	return (RD_WORD(AES_REG_NUM_TOTAL_BYTES) & AES_REG_NUM_TOTAL_BYTES_NUM_TOTAL_BYTES_MASK);
}

#define AES_TAG_MSG_ADDR											0x0000003F

#define AES_AAD_LEN_TOTAL											0x0000FFFF

static __inline void aes_set_aad_length_total(uint32_t length)
{
	uint32_t reg = RD_WORD(AES_REG_AAD_LEN_TOTAL);
	reg &= ~(AES_REG_AAD_LEN_TOTAL_LEN);
	reg |= (length & AES_REG_AAD_LEN_TOTAL_LEN_MASK);
	WR_WORD(AES_REG_AAD_LEN_TOTAL, reg);
}

static __inline uint32_t aes_get_aad_length_total(void)
{
	return (RD_WORD(AES_REG_AAD_LEN_TOTAL) & AES_REG_AAD_LEN_TOTAL_LEN_MASK);
}

static __inline void write_buf(uint8_t *buf, uint32_t num_bytes, uint32_t start_addr) {
	for (uint32_t j = 0; j < num_bytes; j+=4) {
		*((volatile uint32_t *)(start_addr + j)) = (buf[j]<<24)|(buf[j+1]<<16)|(buf[j+2]<<8)|(buf[j+3]);
	}
}

static __inline void read_buf(uint32_t base, uint32_t num_bytes, uint8_t *out) {
	uint32_t reg;
	for (int i = 0; i < num_bytes; i+=4) {
		reg = *((volatile uint32_t *)(AES_DATA_BASE + i)); 

		out[i] = reg >> 24;
		out[i+1] = reg >> 16;
		out[i+2] = reg >> 8;
		out[i+3] = reg;
	}
}
#define HASH_REG_OFFSET_INTR											0x00000800UL
#define HASH_REG_OFFSET_INTR_EN											0x00000040UL
#define HASH_REG_OFFSET_INTR_CLR										0x00000080UL
#define HASH_REG_OFFSET_INTR_STATUS										0x00000100UL

#define AES_REG_CRYPTO_STATUS							(AES_REG_BASE + 0x20)
#define AES_REG_CRYPTO_STATUS_INTR_EN					0x001
#define AES_REG_CRYPTO_STATUS_INTR_CLR					0x002
#define AES_REG_CRYPTO_STATUS_INTR_STATUS				0x004
#define AES_REG_CRYPTO_STATUS_INTR_STATUS_SHIFT			(2)
#define AES_REG_CRYPTO_STATUS_STATUS					0x100
#define AES_REG_CRYPTO_STATUS_STATUS_SHIFT				(8)
#define AES_REG_CRYPTO_STATUS_MAC_VER					0x200
#define AES_REG_CRYPTO_STATUS_MAC_VER_SHIFT				(9)
	
static __inline void aes_intr_unmask() {
	uint32_t reg = RD_WORD(AES_REG_CRYPTO_STATUS);
	reg |= (AES_REG_CRYPTO_STATUS_INTR_EN);
	WR_WORD(AES_REG_CRYPTO_STATUS, reg);
}

static __inline void aes_intr_mask() {
	uint32_t reg = RD_WORD(AES_REG_CRYPTO_STATUS);
	reg &= ~(AES_REG_CRYPTO_STATUS_INTR_EN);
	WR_WORD(AES_REG_CRYPTO_STATUS, reg);
}
	
static __inline void aes_intr_clr() {
	uint32_t reg = RD_WORD(AES_REG_CRYPTO_STATUS);
	reg |= (AES_REG_CRYPTO_STATUS_INTR_CLR);
	WR_WORD(AES_REG_CRYPTO_STATUS, reg);
}

static __inline uint8_t aes_get_crypto_status_intr_status() {
	return ((RD_WORD(AES_REG_CRYPTO_STATUS) & AES_REG_CRYPTO_STATUS_INTR_STATUS) >> AES_REG_CRYPTO_STATUS_INTR_STATUS_SHIFT);
}

static __inline uint8_t aes_get_crypto_status_status() {
	return ((RD_WORD(AES_REG_CRYPTO_STATUS) & AES_REG_CRYPTO_STATUS_STATUS) >> AES_REG_CRYPTO_STATUS_STATUS_SHIFT);
}

static __inline uint8_t aes_get_crypto_status_mac_ver() {
	return ((RD_WORD(AES_REG_CRYPTO_STATUS) & AES_REG_CRYPTO_STATUS_MAC_VER) >> AES_REG_CRYPTO_STATUS_MAC_VER_SHIFT);
}

static __inline void aes_mem_en(int en) 
{
	WR_WORD(GLOBAL_REG_AES_ECC_MEM_SEL, GLOBAL_REG_AES_ECC_MEM_SEL_CTL_AES_ECC_MEM_SEL);
}

static __inline void hal_aes_execute_crypto(void) {
	aes_set_misc_ctrl_msg_begin();
	aes_set_misc_ctrl_msg_end();
	aes_set_misc_ctrl_str_ctx();
	aes_set_misc_ctrl_ret_ctx();
	aes_set_misc_ctrl_go();
}

/**
 ****************************************************************************************
 * @brief Initialize AES driver for power management and interrupt purposes.
 *
 * @return AES_ERR_OK if aes initializes successfully, error otherwise. @see enum aes_crypto_status.
 ****************************************************************************************
 */
int hal_aes_open(void);

/**
 ****************************************************************************************
 * @brief De-Initialize AES driver for power management and interrupt purposes.
 *
 * @return AES_ERR_OK if aes uninitializes successfully, error otherwise. @see enum aes_crypto_status.
 ****************************************************************************************
 */
int hal_aes_close(void);

/**
 ****************************************************************************************
 * @brief Ecc and Aes shared the same HW memory. This is to inform Ecc that Aes currently is using the HW
 * memory.
 * @return 1 if Aes is using the HW memory, 0 otherwise.
 ****************************************************************************************
 */
int hal_aes_is_open(void);

/**
 ****************************************************************************************
 * @brief Set-up and initialize AES cryptography functionality. All fields are required unless otherwise stated.
 *
 * @param[in] aad_length			CCM mode only: Number of bytes in formatted input data minus bytes in formatted payload ("r" - "m" in NIST Special Publication 800-38C)
 * @param[in] num_bytes				Number of bytes in message (CCM mode requires the total number of bytes in formatted input data, see "r" in NIST Special Publication 800-38C)
 * @param[in] num_total_bytes		CCM mode only: Number of bytes in formatted payload only (see "m" in NIST Special Publication 800-38C)
 * @param[in] crypto_type			Cryptography type to apply to message. @see enum aes_crypto_type
 * @param[in] crypto_mode			Cryptography mode to apply to message. @see enum aes_crypto_mode
 * @param[in] mac_length			CCM and CMAC modes only: Number of bytes in MAC
 * @param[in] key_size				AES cryptography key size (128-bit, 192-bit, or 256-bit)
 *
 * @return AES_ERR_OK if aes starts successfully, error otherwise. @see enum aes_crypto_status.
 ****************************************************************************************
 */
int hal_aes_start(uint32_t aad_length, uint32_t num_bytes, uint32_t num_total_bytes, aes_crypto_type crypto_type, aes_crypto_mode crypto_mode, uint16_t mac_length, aes_key_size key_size);

/**
 ****************************************************************************************
 * @brief Process AES cryptography based on input payloads. All fields are required unless otherwise stated.
 *
 * @param[in] msg					Pointer to message (CCM mode requires the formatted input defined as "B" in NIST Special Publication 800-38C)
 * @param[in] key					Pointer to AES Key
 * @param[in] iv					Pointer to initialization vector. All modes except CCM and CMAC require this field
 * @param[in] MAC					Pointer to message authentication code. Only decryption in CCM and CMAC modes requires this field
 * @param[in] salt					Pointer to salt key. Only required for mode F8
 * @param[in] ctr_blk				Pointer to counter block. Only required in modes CCM(see "Ctr0" in NIST Special Publication 800-38C) and CTR("CTRBLK" in RFC 3686)
 *
 * @return AES_ERR_OK if aes processes successfully, error otherwise. @see enum aes_crypto_status.
 ****************************************************************************************
 */
int hal_aes_process(uint8_t *msg, uint8_t *key, uint8_t *iv, uint8_t *MAC, uint8_t *salt, uint8_t *ctr_blk);

/**
 ****************************************************************************************
 * @brief Write AES result to output buffer
 *
 * @param[out] out					Pointer to output of AES result. Result will be same length as provided above in "num_bytes" field
 *
 * @return AES_ERR_OK if encryption completes or MAC is verified, error otherwise. @see enum aes_crypto_status.
 ****************************************************************************************
 */
int hal_aes_finish(uint8_t *out);




#endif





