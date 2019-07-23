#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_aes.c
 *
 * @brief Platform AES functions  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

/*
 ****************************************************************************************
 * INCLUDES
 ****************************************************************************************
 */
#if CFG_AES_EN
#include "in_arm.h"
#include "in_mmap.h"
#include "in_irq.h"
//#include "in_debug.h"

#include ".\hal\hal_clk.h"
#include ".\hal\hal_aes.h"
#if CFG_ECC_EN
#include ".\hal\hal_ecc.h"
#endif
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
} aes_dev_t;

static aes_dev_t aes_dev;

osMutexDef(aes_mutex);
osSemaphoreDef(aes_semaphore);

#if CFG_PM_EN
static int aes_power_state(void *arg, uint32_t *sleep_duration)
{
	aes_dev_t *pd = (aes_dev_t *)arg;
	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->power_state;
}

static void aes_power_down(void *arg, uint32_t sleep_duration)
{
	/// TODO
}
static void aes_power_up(void *arg)
{
	//aes_dev_t *pd = (aes_dev_t *)arg;

	/// TODO: pin mux, etc...
}
#endif	/* CFG_PM_EN */


static void aes_isr(aes_dev_t *pd)
{
	aes_intr_clr();
	osSemaphoreRelease(pd->semaphore);
}

__irq void Aes_Handler(void)
{
	aes_isr(&aes_dev);
}

int hal_aes_open() 
{
	aes_dev_t* pd = &aes_dev;

	if(pd->used)
		return AES_ERR_ALREADY_INIT;

#if CFG_ECC_EN
	if (hal_ecc_is_open()) 
		return AES_ERR_HW_MEM_USED_BY_ECC;
#endif

	pd->mutex = osMutexCreate(osMutex(aes_mutex));
	if (!pd->mutex)
		goto fail;
	pd->semaphore = osSemaphoreCreate(osSemaphore(aes_semaphore), 0);
	if (!pd->semaphore)
		goto fail;

#if CFG_PM_EN
	pd->pm.power_state = aes_power_state;
	pd->pm.power_down = aes_power_down;
	pd->pm.power_up = aes_power_up;
	pd->pm.arg = (void *)pd; 
	hal_pm_reg_mod(&pd->pm);
	pd->power_state = PM_DEEP_SLEEP;
#endif

	aes_mem_en(1);

	hal_clk_aes_en(1);

	pd->used = 1;

	return AES_ERR_OK;

fail:
	if (pd->mutex) {
		osMutexDelete(pd->mutex);
		pd->mutex = NULL;
	}
	if (pd->semaphore) {
		osSemaphoreDelete(pd->semaphore);	
		pd->semaphore = NULL;
	}
	return AES_ERR_DEV_BAD_STATE;
}

int hal_aes_close(void) 
{
	aes_dev_t *pd = &aes_dev;

	if (!pd->used)
		return AES_ERR_NOT_INIT;	
	
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

	hal_clk_aes_en(0);	

	return AES_ERR_OK;
}

int hal_aes_is_open(void) 
{
	aes_dev_t *pd = &aes_dev;

	return pd->used;
}

int hal_aes_start(uint32_t aad_length, uint32_t num_bytes, uint32_t num_total_bytes, 
	aes_crypto_type crypto_type, aes_crypto_mode crypto_mode, uint16_t mac_length, aes_key_size key_size) 
{
	aes_dev_t *pd = &aes_dev;
	if(!pd->used)
		return AES_ERR_NOT_INIT;

	aes_set_misc_ctrl_type(crypto_type);
	aes_set_misc_ctrl_mode(crypto_mode);
	aes_set_misc_ctrl_key_size(key_size);

	// HW: length 16 should be inputted as 0x0
	if(mac_length == 16)
		aes_set_misc_ctrl_mac_len(0);
	else
		aes_set_misc_ctrl_mac_len(mac_length);

	aes_set_aad_length(aad_length);
	aes_set_num_bytes(num_bytes);
	aes_set_num_total_bytes(num_total_bytes);

	osMutexWait(pd->mutex, osWaitForever);

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif

	return AES_ERR_OK;
}

int hal_aes_process(uint8_t *msg, uint8_t *key, uint8_t *iv, uint8_t *MAC, uint8_t *salt, uint8_t *ctr_blk) 
{
	aes_dev_t *pd = &aes_dev;
	if(!pd->used)
		return AES_ERR_NOT_INIT;

	aes_crypto_mode mode = aes_get_misc_ctrl_mode();

	// Write to BLOCK0 (Keys)
	aes_key_size key_size = aes_get_misc_ctrl_key_size();
	if(key_size == AES_KEY_SIZE_128)
		write_buf(key, 16, AES_CONTEXT_MEMORY_BLOCK0_BASE);
	else if(key_size == AES_KEY_SIZE_196)
		write_buf(key, 24, AES_CONTEXT_MEMORY_BLOCK0_BASE);
	else
		write_buf(key, 32, AES_CONTEXT_MEMORY_BLOCK0_BASE);

	// Write to BLOCK1
	if(mode == AES_CRYPTO_MODE_F8)
		write_buf(salt, 16, AES_CONTEXT_MEMORY_BLOCK1_BASE);
	
	// Write to BLOCK2
	if(mode == AES_CRYPTO_MODE_CTR || mode == AES_CRYPTO_MODE_CCM) {
		write_buf(ctr_blk, 16, AES_CONTEXT_MEMORY_BLOCK2_BASE);
	}

	// Write to BLOCK3
	if(mode == AES_CRYPTO_MODE_ECB || mode == AES_CRYPTO_MODE_CBC) 
		write_buf(iv, 16, AES_CONTEXT_MEMORY_BLOCK3_BASE);
	else if(mode == AES_CRYPTO_MODE_CCM) {
		uint8_t iv[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
		write_buf(iv, 16, AES_CONTEXT_MEMORY_BLOCK3_BASE);
	}
	else if (mode == AES_CRYPTO_MODE_F8)
		write_buf(iv, 16, AES_CONTEXT_MEMORY_BLOCK3_BASE);	

	// Write to BLOCK4
	if (mode == AES_CRYPTO_MODE_CCM || mode == AES_CRYPTO_MODE_CMAC) {
		uint8_t mac_length = aes_get_misc_ctrl_mac_len();
		write_buf(MAC, mac_length, AES_CONTEXT_MEMORY_BLOCK4_BASE);		
	}

	// Write to DATA block
	uint32_t num_bytes = aes_get_num_bytes();
	write_buf(msg, num_bytes, AES_DATA_BASE );

	hal_aes_execute_crypto();

	/// Unmask Interrupt	
	aes_intr_unmask();
	NVIC_SetPriority(Aes_IRQn, IRQ_PRI_Normal);	
	NVIC_EnableIRQ(Aes_IRQn);
		
	/// Wait for write complete
	osSemaphoreWait(pd->semaphore, osWaitForever);

	/// Re-mask Interrupt	
	aes_intr_mask();
	NVIC_DisableIRQ(Aes_IRQn);

	return AES_ERR_OK;
}

int hal_aes_finish(uint8_t *out) 
{	
	aes_dev_t *pd = &aes_dev;
	if(!pd->used)
		return AES_ERR_NOT_INIT;

	int result;
	aes_crypto_mode mode = aes_get_misc_ctrl_mode();
	if((mode == AES_CRYPTO_MODE_CCM || mode == AES_CRYPTO_MODE_CMAC) && aes_get_misc_ctrl_type() == AES_CRYPTO_TYPE_DECRYPT && !aes_get_crypto_status_mac_ver())
		result = AES_ERR_MAC_DOES_NOT_MATCH;
	else
		result = AES_ERR_OK;
	
	/* clear go bit */
	aes_clr_misc_ctrl_go();

	/* read data */
	read_buf(AES_DATA_BASE, aes_get_num_bytes(), out);

	osMutexRelease(pd->mutex);

#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif
	
	return result;
}
#endif	// CFG_AES_EN


