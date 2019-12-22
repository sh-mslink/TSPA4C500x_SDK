#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_ecc.c
 *
 * @brief Platform ECC functions  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

/*
 ****************************************************************************************
 * INCLUDES
 ****************************************************************************************
 */
#if CFG_HASH_EN
#include "in_arm.h"
#include "in_mmap.h"
#include "in_irq.h"
//#include "in_debug.h"

#include ".\hal\hal_clk.h"
#include ".\hal\hal_hash.h"
#if CFG_PM_EN
#include ".\hal\hal_power.h"
#endif

#include "cmsis_os.h"

/*
 ****************************************************************************************
 * IMPLEMENTATION
 ****************************************************************************************
 */

typedef struct {
	int used;
	osMutexId mutex;
	osSemaphoreId semaphore; 
	/// Power 
#if CFG_PM_EN
	int power_state;
	struct pm_module pm;
#endif
} hash_dev_t;

static hash_dev_t hash_dev;

osMutexDef(hash_mutex);
osSemaphoreDef(hash_semaphore);

#if CFG_PM_ENABLE
static int hash_power_state(void *arg, uint32_t *sleep_duration)
{
	hash_dev_t *pd = (hash_dev_t *)arg;
	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->power_state;
}

static void hash_power_down(void *arg, uint32_t sleep_duration)
{
	/// TODO
}
static void hash_power_up(void *arg)
{
	hash_dev_t *pd = (hash_dev_t *)arg;

	/// TODO: pin mux, etc...
}
#endif	/* CFG_PM_ENABLE */


static void hash_isr(hash_dev_t *pd)
{
	hash_intr_clr();
	osSemaphoreRelease(pd->semaphore);
}

__irq void Hash_Handler(void)
{
	hash_isr(&hash_dev);
}

int hal_hash_open() 
{
	hash_dev_t* pd = &hash_dev;

	if(!pd)
		return HASH_ERR_DEV_BAD_STATE;
	if(pd->used)
		return HASH_ERR_ALREADY_INIT;
	pd->used = 1;
	pd->mutex = osMutexCreate(osMutex(hash_mutex));
	if (!pd->mutex)
		goto fail;
	pd->semaphore = osSemaphoreCreate(osSemaphore(hash_semaphore), 0);
	if (!pd->semaphore)
		goto fail;

#if CFG_PM_EN
	pd->pm.power_state = hash_power_state;
	pd->pm.power_down = hash_power_down;
	pd->pm.power_up = hash_power_up;
	pd->pm.arg = (void *)pd; 
	hal_pm_reg_mod(&pd->pm);
	pd->power_state = PM_DEEP_SLEEP;
#endif

	hal_clk_hash_en(1);

	return HASH_ERR_OK;

fail:
	if (pd->mutex) {
		osMutexDelete(pd->mutex);
		pd->mutex = NULL;
	}
	if (pd->semaphore) {
		osSemaphoreDelete(pd->semaphore);	
		pd->semaphore = NULL;
	}
	return HASH_ERR_DEV_BAD_STATE;
}

int hal_hash_close(void) 
{
	hash_dev_t* pd = &hash_dev;

	if (!pd)
		return HASH_ERR_DEV_BAD_STATE;	
	if(!pd->used)
		return HASH_ERR_NOT_INIT;
	pd->used = 0;

	osMutexWait(pd->mutex, osWaitForever);
	osMutexRelease(pd->mutex);

	if (pd->mutex) {
		osMutexDelete(pd->mutex);
		pd->mutex = NULL;
	}	
	if (pd->semaphore) {
		osSemaphoreDelete(pd->semaphore);
		pd->semaphore = NULL;
	}

#if CFG_PM_EN
	hal_pm_unreg_mod(&pd->pm);
#endif

	hal_clk_hash_en(0);
	
	return HASH_ERR_OK;
}

// Use standard initialization variables for each hash type
int hal_hash_start(hash_type type) 
{
	hash_dev_t* pd = &hash_dev;
	if(!pd->used)
		return HASH_ERR_NOT_INIT;


	if(type == HASH_TYPE_MD5) {
		hash_md5_mode();
		hash_data_swap_enable();
		hash_write_hx(0, 0x67452301);
		hash_write_hx(3, 0x10325476);
		hash_write_hx(2, 0x98BADCFE);
		hash_write_hx(1, 0xEFCDAB89);
		hash_len_low_word(0x040);
	}	
	else if(type == HASH_TYPE_SHA1) {
		hash_sha1_mode();
		hash_write_hx(4, 0xC3D2E1F0);
		hash_write_hx(3, 0x10325476);
		hash_write_hx(2, 0x98BADCFE);
		hash_write_hx(1, 0xEFCDAB89);
		hash_write_hx(0, 0x67452301);
		hash_len_low_word(0x040);
	}
	else if(type == HASH_TYPE_SHA256) {
		hash_sha256_mode();
		hash_write_hx(7, 0x5be0cd19);
		hash_write_hx(6, 0x1f83d9ab);
		hash_write_hx(5, 0x9b05688c);
		hash_write_hx(4, 0x510e527f);
		hash_write_hx(3, 0xa54ff53a);
		hash_write_hx(2, 0x3c6ef372);
		hash_write_hx(1, 0xbb67ae85);
		hash_write_hx(0, 0x6a09e667);
		hash_len_low_word(0x040);
	}

	osMutexWait(pd->mutex, osWaitForever);

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif

	return HASH_ERR_OK;	
}

// Insert data to be hashed, SW-padding
int hal_hash_process(hash_type type, uint8_t *data, uint32_t data_len)
{
	hash_dev_t* pd = &hash_dev;
	if(!pd->used)
		return HASH_ERR_NOT_INIT;
	
	/// Unmask Interrupt	
	hash_intr_unmask();
	//NVIC_EnableIRQ(Hash_IRQn);
	
	uint8_t chunk[64];
	uint32_t cur_byte = 0;
	uint32_t data_rem = data_len;
	uint64_t bitlen = 8*data_len;

	// while more than 1 chunk of 512 bits in data, write full chunks
	while(data_rem >= 64) {
		for(int i = 0; i < 64; i++, cur_byte++)
			chunk[i] = data[cur_byte];
		data_rem -= 64;
		hash_write_to_port(chunk);
	}
	
	int i = 0;
	// while less than full chunk of 512 bits of data remaining, write data into chunk
	while(data_rem > 0x0) {
		chunk[i++] = data[cur_byte++];
		data_rem --;
	}
	// append 1 bit
	chunk[i++] = 0x80;
	// if the current chunk now has no room for data length (less than 64 bits of space remaining),
	// 		buffer with zeros, write to port, start new chunk for data length
	if(i >= 57) {
		while(i < 64)
			chunk[i++] = 0;
		hash_write_to_port(chunk);
		i = 0;
	}
	// buffer remaining zeroes in current chunk 
	while(i < 64) {
		chunk[i++] = 0;
	}
	
	// write data length into chunk and write it
	if(type == HASH_TYPE_MD5) {			
		i = 56;
		while(bitlen > 0 && i < 64) {
			chunk[i++] = bitlen;
			bitlen = bitlen >> 8;
		}		
	}
	else {
		i = 63;
		while(bitlen > 0) {
			chunk[i--] = bitlen;
			bitlen = bitlen >> 8;
		}		
	}
	hash_write_to_port(chunk);

	/// NVIC Interrupt Enable
	NVIC_SetPriority(Hash_IRQn, IRQ_PRI_Normal);	
	NVIC_EnableIRQ(Hash_IRQn);
		
	/// Wait for write complete
	osSemaphoreWait(pd->semaphore, osWaitForever);

	/// Re-mask Interrupt	
	hash_intr_mask();
	NVIC_DisableIRQ(Hash_IRQn);

	return HASH_ERR_OK;
}
	
// Write hash output to out buffer input
int hal_hash_finish(hash_type type, uint8_t *out)
{
	hash_dev_t* pd = &hash_dev;
	if(!pd->used)
		return HASH_ERR_NOT_INIT;
	
	uint32_t base = SHA_BASE + HASH_REG_OFFSET_HASH_H0;
	uint32_t len;
	// MD-5 hash results come out in big-endian
	if(type == HASH_TYPE_MD5) {
		hash_padding_generation_set();
		len = 16;
		uint32_t buf;
		for(uint32_t i = 0; i < len; i+=4){
			buf = *((volatile uint32_t *)(base + i));
			out[i+3] = buf;
			out[i+2] = buf >> 8;
			out[i+1] = buf >> 16;
			out[i] = buf >> 24;
		}
	}
	// SHA-1 hash results come out in little-endian
	else if(type == HASH_TYPE_SHA1) {
		hash_padding_generation_set();
		len = 5;
		uint32_t *buf = (uint32_t*) out;
		for(uint32_t i = 0; i < len; i++)
			buf[i] = *((volatile uint32_t *)(base + (i*4)));
	}
	// SHA-256 hash results come out in little-endian
	else if(type == HASH_TYPE_SHA256) {
		len = 8;
		uint32_t *buf = (uint32_t*) out;
		for(uint32_t i = 0; i < len; i++)
			buf[i] = *((volatile uint32_t *)(base + (i*4)));
	}
	
	hash_data_swap_disable();
	hash_padding_generation_reset(); 
	hash_pad_block_disable(); 

	osMutexRelease(pd->mutex);

#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif

	return HASH_ERR_OK;
}
#endif 	// CFG_HASH_EN
