#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_efuse.c
 *
 * @brief Platform Efuse functions  
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
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "in_arm.h"
#include "in_mmap.h"
#include "in_irq.h"
#include "in_debug.h"

#include ".\hal\hal_clk.h"
#include ".\hal\hal_efuse.h"

#include "cmsis_os.h"

#if CFG_EFUSE_EN
/*
 ****************************************************************************************
 * IMPLEMENTATION
 ****************************************************************************************
 */

typedef struct {
	int used;
	osMutexId mutex;
} efuse_dev_t;

static efuse_dev_t efuse_dev;

osMutexDef(efuse_mutex);

int hal_efuse_open() 
{
	efuse_dev_t* pd = &efuse_dev;

	if(!pd)
		return EFUSE_ERR_DEV_BAD_STATE;

 	if(pd->used)
 		return EFUSE_ERR_EFUSE_ALREADY_INITIALIZED;

	pd->used = 1;

	pd->mutex = osMutexCreate(osMutex(efuse_mutex));
	if (!pd->mutex)
		goto fail;

	hal_clk_efuse_en(1);

	return EFUSE_ERR_OK;

fail:
	if (pd->mutex) {
		osMutexDelete(pd->mutex);
		pd->mutex = NULL;
	}

	return EFUSE_ERR_DEV_BAD_STATE;
}

int hal_efuse_close(void) 
{
	efuse_dev_t* pd = &efuse_dev;
	if(!pd)
		return EFUSE_ERR_DEV_BAD_STATE;
 	if(!pd->used)
 		return EFUSE_ERR_EFUSE_NOT_INITIALIZED;

	pd->used = 0;

	osMutexWait(pd->mutex, osWaitForever);
	osMutexRelease(pd->mutex);

	if (pd->mutex) {
		osMutexDelete(pd->mutex);
		pd->mutex = NULL;
	}	

	//hal_clk_efuse_en(0);
	
	return EFUSE_ERR_OK;
}

int hal_efuse_read_word(int bank_id, int word_num, uint32_t* out)
{
	efuse_dev_t* pd = &efuse_dev;
	if(!pd)
		return EFUSE_ERR_DEV_BAD_STATE;
 	if(!pd->used)
 		return EFUSE_ERR_EFUSE_NOT_INITIALIZED;

	int id = EFUSE0_ID, addr, sel = 0;
	if(bank_id == 0) 
		id = EFUSE1_ID;
	else if(bank_id == 2)
		sel = 1;
	else if(bank_id != 1)
		return EFUSE_ERR_INVALID_PARAM;

	if(word_num < 0 || word_num > 15)
		return EFUSE_ERR_INVALID_PARAM;

	addr = word_num * 2;

	osMutexWait(pd->mutex, osWaitForever);

	efuse_enable(id);

	efuse_read_bit_start(id, sel, addr, EFUSE_READ_WORD);
	while (!efuse_intr_read_done(id));			
	uint32_t data = efuse_read_value(id);
	efuse_intr_read_done_clr(id);							
	efuse_read_bit_end(id);

	efuse_disable(id);

	osMutexRelease(pd->mutex);

	*out = data;

	return EFUSE_ERR_OK;
}

int hal_efuse_write_word(int bank_id, int word_num, uint32_t data)
{
	efuse_dev_t* pd = &efuse_dev;
	if(!pd)
		return EFUSE_ERR_DEV_BAD_STATE;
 	if(!pd->used)
 		return EFUSE_ERR_EFUSE_NOT_INITIALIZED;

	uint32_t x = 0;
	uint32_t *word = &x;
	int result = hal_efuse_read_word(bank_id, word_num, word);
	if(result != EFUSE_ERR_OK)
		return result;

	int id = EFUSE0_ID, addr, sel = 0;
	if(bank_id == 0) 
		id = EFUSE1_ID;
	else if(bank_id == 2)
		sel = 1;

	addr = word_num * 32;

	osMutexWait(pd->mutex, osWaitForever);

	efuse_prog_enable(id);

	/* prog bit */
	for (int i = 0; i < 32; i++) {
		if (!(((*word)>>i) & 1)) {		// already been written
			if (((data>>i) & 1)) {
				efuse_prog_bit_start(id, addr, sel);
				while (!efuse_intr_prog_done(id));			
				efuse_intr_prog_done_clr(id);							
				efuse_prog_bit_end(id);			
			}
		}
		addr += 1;	 
	}

	/* disable programming */
	efuse_prog_disable(id);

	osMutexRelease(pd->mutex);

	return EFUSE_ERR_OK;
}
#endif	// CFG_EFUSE_EN

int hal_efuse_status_inplay_lock(void) {
	return efuse_get_inplay_efuse_lock();
}

int hal_efuse_status_spiflash(void) {
	return efuse_get_spiflash_present();
}

int hal_efuse_status_feature_sel(void){
	return efuse_get_inplay_feature_sel();
}

int hal_efuse_status_sec_key_sel(void){
	return efuse_get_inplay_security_key_sel();
}

int hal_efuse_status_sec_key_alg(void){
	return efuse_get_inplay_security_key_alg();
}

void hal_efuse_get_uuid(uint32_t* out){
	out[0] = efuse_get_uuid0();
	out[1] = efuse_get_uuid1();
	out[2] = efuse_get_uuid2();
	out[3] = efuse_get_uuid3();
}

int hal_efuse_status_cust_lock(void){
	return efuse_get_cust_efuse_lock();
}

int hal_efuse_status_cm4_dbg(void){
	return ~efuse_get_cm4_dbg_disable();
}

int hal_efuse_status_flash_enc_en(void){
	return efuse_get_flash_encryption_enable();
}

int hal_efuse_status_flash_secure_boot_enable(void){
	return efuse_get_flash_secure_boot_enable();
}

int hal_efuse_status_ram_secure_boot_en(void){
	return efuse_get_ram_secure_boot_enable();
}

int hal_efuse_status_ecc_len_secure_boot(void){
	return efuse_get_ecc_len_secure_boot();
}

int hal_efuse_status_interface_en(void){
	return efuse_get_default_interface_enable();
}

int hal_efuse_status_interface_sel(void){
	return efuse_get_default_interface_selection();
}

int hal_efuse_status_rtc(void){
	return efuse_get_rtc_installed();
}

void hal_efuse_get_customer_id(uint32_t* out) {
	*out = efuse_get_customer_id();
}

