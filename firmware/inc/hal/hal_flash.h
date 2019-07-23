#ifndef HAL_FLASH_H
#define HAL_FLASH_H

#include <stdint.h>
#include "in725_mmap.h"

#define FLASH_SECTOR_SIZE		(1024)
#define FLASH_MAX_NB_SECTOR		(512)

enum {
	FLASH_ERR_OK,
	FLASH_ERR_OUT_OF_RANGE,
	FLASH_ERR_SECTOR_ALIGN,
	FLASH_ERR_PROG_INVALID,
	FLASH_ERR_PROG_510_INVALID,
	FLASH_ERR_PROG_511_INVALID,
	FLASH_ERR_PROG_TIME_OUT,
	FLASH_ERR_ERASE_INVALID,
	FLASH_ERR_ERASE_510_INVALID,
	FLASH_ERR_ERASE_511_INVALID,
	FLASH_ERR_ERASE_TIME_OUT,
	FLASH_ERR_SAFE_TIME_OUT,
};

typedef struct 
{
	volatile uint32_t intr_status;													/* 0x00 */
	volatile uint32_t intr_mask_status;	
	volatile uint32_t intr_clear;	
	volatile uint32_t intr_set;	
	volatile uint32_t intr_mask_set;	
	volatile uint32_t intr_mask_clear;	
	volatile uint32_t reserve1[10];
	volatile uint32_t misc_ctrl;														/* 0x40 */
	volatile uint32_t reserve2[1];	
	volatile uint32_t misc_state;													/* 0x48 */
	volatile uint32_t reserve3[5];	
	volatile uint32_t safe_guard_ctrl;												/* 0x60 */
	volatile uint32_t safe_guard_data;	
	volatile uint32_t safe_guard_status;	
	volatile uint32_t reserve4[5];				
	volatile uint32_t eflash_200ns_counter_val;								/* 0x80 */
	volatile uint32_t wait_readmode_tms_counter_val;
	volatile uint32_t reserve5[2];
	volatile uint32_t wait_prog_op_tnvs_counter_val;						/* 0x90 */
	volatile uint32_t wait_prog_op_tpgs_counter_val;
	volatile uint32_t wait_prog_op_tprog_counter_val;
	volatile uint32_t reserve6[1];
	volatile uint32_t wait_sector_erase_tnvs_counter_val;				/* 0xA0 */
	volatile uint32_t wait_sector_erase_terase_counter_val;
	volatile uint32_t wait_sector_erase_trcv_ser_counter_val;
	volatile uint32_t wait_sector_erase_trw_counter_val;
	volatile uint32_t wait_chip_erase_tnvs_counter_val;
	volatile uint32_t wait_chip_erase_tsce_counter_val;
	volatile uint32_t wait_chip_erase_trcv_cer_counter_val;
	volatile uint32_t wait_chip_erase_trw_counter_val;
	volatile uint32_t wait_prog_op_tnvs_lv_counter_val;
	volatile uint32_t wait_prog_op_tprog_lv_counter_val;
	volatile uint32_t wait_sector_erase_tnvs_lv_counter_val;
	volatile uint32_t wait_sector_erase_terase_lv_counter_val;
	volatile uint32_t wait_chip_erase_tnvs_lv_counter_val;
	volatile uint32_t wait_chip_erase_tsce_lv_counter_val;
	volatile uint32_t reserve7[4];
	volatile uint32_t redun0_state;												/* 0xE8 */
	volatile uint32_t redun1_state;
	volatile uint32_t reserve8[4];
	volatile uint32_t nvr_cfg_crd0_val;											/* 0x100 */
	volatile uint32_t nvr_cfg_crd1_val;
	volatile uint32_t nvr_cfg_crd2_val;
	volatile uint32_t nvr_cfg_crd3_val;
	volatile uint32_t nvr_cfg_crd4_val;
	volatile uint32_t nvr_cfg_crd5_val;
	volatile uint32_t nvr_cfg_crd6_val;
	volatile uint32_t nvr_cfg_crd7_val;											/* 0x11C */
	volatile uint32_t reserve9[2];
	volatile uint32_t fsm_state;														/* 0x128 */
	volatile uint32_t reserve10[5];
	volatile uint32_t sector_erase_ctrl;											/* 0x140 */
	volatile uint32_t chip_erase_ctrl;
	volatile uint32_t reserve11[6];
	volatile uint32_t prog_ctrl;														/* 0x160 */
	volatile uint32_t reserve12;
	volatile uint32_t prog_word0;													/* 0x168 */													
	volatile uint32_t prog_word1;
	volatile uint32_t prog_word2;
	volatile uint32_t prog_word3;
} flashctrl_reg_t;

#define FLASHCTRL_INTR_STATUS_PROG_LINE_DONE 0x00000001UL
#define FLASHCTRL_INTR_STATUS_PROG_SECTOR_DONE 0x00000002UL
#define FLASHCTRL_INTR_STATUS_ERASE_SECTOR_DONE 0x00000004UL
#define FLASHCTRL_INTR_STATUS_ERASE_CHIP_DONE 0x00000008UL
#define FLASHCTRL_INTR_STATUS_SAFEGUARD_ERROR 0x00000010UL
#define FLASHCTRL_INTR_STATUS_SAFEGUARD_TMO 0x00000020UL
#define FLASHCTRL_INTR_STATUS_PROG_INVALID 	0x00000040UL
#define FLASHCTRL_INTR_STATUS_ERASE_INVALID 	0x00000080UL
#define FLASHCTRL_INTR_STATUS_CHIP_ERASE_INVALID 	0x00000100UL
#define FLASHCTRL_INTR_STATUS_PROG_510_INVALID 	0x00000200UL
#define FLASHCTRL_INTR_STATUS_PROG_511_INVALID 	0x00000400UL
#define FLASHCTRL_INTR_STATUS_ERASE_510_INVALID 	0x00000800UL
#define FLASHCTRL_INTR_STATUS_ERASE_511_INVALID 	0x00001000UL
#define FLASHCTRL_INTR_STATUS_ERASE_CHIP_BLOCK 	0x00002000UL

#define FLASHCTRL_SAFEGUARD_CTL_STATUS 0x00000001UL
#define FLASHCTRL_SAFEGUARD_CTL_TMO_VAL 0x000FFFF0UL

#define FLASHCTRL_MISC_CTL_ENABLE 0x00000001UL
#define FLASHCTRL_MISC_CTL_CHIP_ERASE 0x00000010UL
#define FLASHCTRL_MISC_CTL_DISABLE_AHB_CACHE 0x00000040UL
#define FLASHCTRL_MISC_CTL_BYPASS_NVR_CFG 0x00000080UL
#define FLASHCTRL_MISC_CTL_BYPASS_INIT 0x00000100UL
#define FLASHCTRL_MISC_CTL_RESET_FSM 0x00000200UL
#define FLASHCTRL_MISC_CTL_RESET_LAST_READ 0x00000400UL
#define FLASHCTRL_MISC_CTL_AHB_ACCESS_SECTOR_TYPE_SEL 0x00007000UL
#define FLASHCTRL_MISC_CTL_LOW_VOLT 0x00010000UL
#define FLASHCTRL_MISC_CTL_POWER_DOWN 0x00020000UL
#define FLASHCTRL_MISC_CTL_LCK_CFG 0x00040000UL
#define FLASHCTRL_MISC_CTL_PORB 0x00080000UL

#define FLASHCTRL_ERASE_SECTOR_CTL_REQ 		0x00000001UL
#define FLASHCTRL_ERASE_SECTOR_CTL_RETRY 	0x00000006UL
#define FLASHCTRL_ERASE_SECTOR_CTL_TYPE 	0x00000070UL
#define FLASHCTRL_ERASE_SECTOR_CTL_ADDR 	0x007FFF00UL

#define FLASHCTRL_PROG_SECTOR_CTL_TYPE 				0x00000007UL
#define FLASHCTRL_PROG_SECTOR_CTL_ADDR				0x0007FFF0UL
#define FLASHCTRL_PROG_SECTOR_CTL_REQ				0x00100000UL
#define FLASHCTRL_PROG_SECTOR_CTL_LAST_REQ		0x00200000UL

static __inline void flash_delay(uint32_t us)
{
	for (int i = 0; i < (5*us); i++) {
		__nop();
	}			
}

static __inline void flash_safe_guard_timeout(uint32_t tmo)
{
	flashctrl_reg_t *fc = (flashctrl_reg_t *)FLASHCTRL_BASE;
	uint32_t reg = fc->safe_guard_ctrl;

	reg &= ~FLASHCTRL_SAFEGUARD_CTL_TMO_VAL;
	reg |= (tmo & 0xFFFF) << 4;

	fc->safe_guard_ctrl = reg;
}

static __inline void flash_safe_guard_clear_status(void)
{
	flashctrl_reg_t *fc = (flashctrl_reg_t *)FLASHCTRL_BASE;
	uint32_t reg = fc->safe_guard_ctrl;

	reg |= 1;

	fc->safe_guard_ctrl = reg;
}

static __inline int flash_safe_guard_get_status(void)
{
	flashctrl_reg_t *fc = (flashctrl_reg_t *)FLASHCTRL_BASE;
	uint32_t reg = fc->safe_guard_ctrl;

	reg &= 0x1;

	return (int)reg;
}

static __inline void flash_enable(int en, int cache_en)
{
	flashctrl_reg_t *fc = (flashctrl_reg_t *)FLASHCTRL_BASE;
	uint32_t reg = fc->misc_ctrl;

	if (en)
		reg |= FLASHCTRL_MISC_CTL_ENABLE;
	else
		reg &= ~FLASHCTRL_MISC_CTL_ENABLE;

	if (cache_en)
		reg &= ~FLASHCTRL_MISC_CTL_DISABLE_AHB_CACHE;
	else
		reg |= FLASHCTRL_MISC_CTL_DISABLE_AHB_CACHE;

	fc->misc_ctrl = reg;
}

static __inline void flash_power_on_reset(int reset)
{
	flashctrl_reg_t *fc = (flashctrl_reg_t *)FLASHCTRL_BASE;
	uint32_t reg = fc->misc_ctrl;

	if (reset)
		reg |= FLASHCTRL_MISC_CTL_PORB;
	else
		reg &= ~FLASHCTRL_MISC_CTL_PORB;

	fc->misc_ctrl = reg;

	flash_delay(5000);

}

static __inline void flash_intr_status_clear(void)
{
	flashctrl_reg_t *fc = (flashctrl_reg_t *)FLASHCTRL_BASE;
	fc->intr_clear = 0x3FFFUL;
}

static __inline int flash_start(void)
{
	flashctrl_reg_t *fc = (flashctrl_reg_t *)FLASHCTRL_BASE;
	int res = FLASH_ERR_OK;

	flash_safe_guard_clear_status();
    
	__disable_irq();

    // Program the safe guard data
	fc->safe_guard_data = 0x01234567;
	fc->safe_guard_data = 0xECA86420;
	fc->safe_guard_data = 0x13579BDF;
	fc->safe_guard_data = 0xFEDCBA98;

	/* poll until it is done */
	while (1) {
		if (flash_safe_guard_get_status()) {
			break;
		} else {
			flash_delay(1);
		}
	}

	__enable_irq();

	return res; 
}

static __inline void flash_end(void)
{
	flashctrl_reg_t *fc = (flashctrl_reg_t *)FLASHCTRL_BASE;

	fc->safe_guard_data = 0x66668888;
}

static __inline int flash_erase_sector(int retry, uint32_t sector_nb)
{
	flashctrl_reg_t *fc = (flashctrl_reg_t *)FLASHCTRL_BASE;
	uint32_t reg, addr;
	int res = FLASH_ERR_OK;

	res = flash_start();
	if (res != FLASH_ERR_OK)
		goto out;

	fc->sector_erase_ctrl = 0;
	flash_intr_status_clear();
	addr = (sector_nb & 0x1FF) << 6;	
	reg = FLASHCTRL_ERASE_SECTOR_CTL_REQ | ((retry & 0x3) << 1) | (addr << 8);

	__disable_irq();

	fc->sector_erase_ctrl = reg;
	flash_delay(1);

	flash_end();

	reg = fc->intr_status;
	if (reg & FLASHCTRL_INTR_STATUS_ERASE_INVALID) {
		res = FLASH_ERR_ERASE_INVALID;
		goto out;
	}
	flash_delay(1);
	
	reg = fc->intr_status;
	if (reg & FLASHCTRL_INTR_STATUS_ERASE_510_INVALID) {
		res = FLASH_ERR_ERASE_510_INVALID;
		goto out;
	}
	if (reg & FLASHCTRL_INTR_STATUS_ERASE_511_INVALID) {
		res = FLASH_ERR_ERASE_511_INVALID;
		goto out;
	}

	/* poll until it is done */
	while (1) {
		reg = fc->intr_status;
		if (reg & FLASHCTRL_INTR_STATUS_ERASE_SECTOR_DONE) {
			break;
		} else {
			flash_delay(100);
		}
	}

out:

	fc->sector_erase_ctrl = 0;

	__enable_irq();

	return res;
}

static __inline int flash_prog_sector_internal(void)
{
	flashctrl_reg_t *fc = (flashctrl_reg_t *)FLASHCTRL_BASE;
	int res = FLASH_ERR_OK;
	uint32_t reg;

	reg = fc->intr_status;
	if (reg & FLASHCTRL_INTR_STATUS_PROG_INVALID) {
		res = FLASH_ERR_PROG_INVALID;
		goto out;
	}
	flash_delay(1);

	reg = fc->intr_status;
	if (reg & FLASHCTRL_INTR_STATUS_PROG_510_INVALID) {
		res = FLASH_ERR_PROG_510_INVALID;
		goto out;
	}

	if (reg & FLASHCTRL_INTR_STATUS_PROG_511_INVALID) {
		res = FLASH_ERR_PROG_511_INVALID;
		goto out;
	}

	/* poll until it is done */
	while (1) {
		reg = fc->intr_status;
		if (reg & FLASHCTRL_INTR_STATUS_PROG_LINE_DONE) {
			break;
		} else {
			flash_delay(1);
		}
	}

	while (1 ) {
		reg = fc->intr_status;
		if (reg & FLASHCTRL_INTR_STATUS_PROG_SECTOR_DONE) {
			break;
		} else {
			flash_delay(1);
		}
	}

out:

	return res;
}

static __inline int flash_prog_sector(uint32_t sector, uint8_t *data, uint16_t data_len)
{
	flashctrl_reg_t *fc = (flashctrl_reg_t *)FLASHCTRL_BASE;
	int lines = data_len>>4;
	int left = data_len&0xF;
	int res = FLASH_ERR_OK;
	uint32_t addr,reg;

	for (int i = 0; i < lines; i++) {

		fc->prog_word0 = *data++ | (*data++ << 8) | (*data++ << 16) | (*data++ <<24);
		fc->prog_word1 = *data++ | (*data++ << 8) | (*data++ << 16) | (*data++ <<24);
		fc->prog_word2 = *data++ | (*data++ << 8) | (*data++ << 16) | (*data++ <<24);
		fc->prog_word3 = *data++ | (*data++ << 8) | (*data++ << 16) | (*data++ <<24);

		res = flash_start();
		if (res != FLASH_ERR_OK)
			break;

		fc->prog_ctrl = 0;	
		flash_intr_status_clear();
		addr = ((sector & 0x1FF) << 6) | i;

		reg = (addr << 4) |FLASHCTRL_PROG_SECTOR_CTL_REQ | FLASHCTRL_PROG_SECTOR_CTL_LAST_REQ; 

		__disable_irq();

		fc->prog_ctrl = reg;	
		flash_delay(1);

		flash_end();

		res = flash_prog_sector_internal();

		__enable_irq();

		if (res != FLASH_ERR_OK)
			break;
	}

	if (res == FLASH_ERR_OK) {
		if (left) {
			int shift = 0;
			int word_idx = 0;
			uint32_t word[4] = {0};

			for (int i = 0; i < left; i++) {
				word[word_idx] |= *data++ >> (shift * 8);
				shift += 1;
				if (shift == 3) {
					shift = 0;
					word_idx += 1;
				}
			}

			fc->prog_word0 = word[0];
			fc->prog_word1 = word[1];
			fc->prog_word2 = word[2];
			fc->prog_word3 = word[3];

			res = flash_start();
			if (res == FLASH_ERR_OK) {
				fc->prog_ctrl = 0;	
				flash_intr_status_clear();
				addr = ((sector & 0x1FF) << 6) | (lines+1);
				reg = (addr << 4) |FLASHCTRL_PROG_SECTOR_CTL_REQ | FLASHCTRL_PROG_SECTOR_CTL_LAST_REQ; 

				__disable_irq();

				fc->prog_ctrl = reg;	
				flash_delay(1);

				flash_end();

				res = flash_prog_sector_internal();

				__enable_irq();
			}
		}
	}

	return res;
}

/*****

	Flash Cache

*****/
#define CACHE_INTR_STATUS					(FLASHCACHE_BASE + 0x0)
#define CACHE_INTR_CLR						(FLASHCACHE_BASE + 0x8)
#define CACHE_MISC_CTL						(FLASHCACHE_BASE + 0x18)

static __inline void cache_enable(void)
{
	uint32_t misc = RD_WORD(CACHE_MISC_CTL);

	/* Disable controller before flush the cache */
	if (misc & 1) {
		misc &= ~1;
		WR_WORD(CACHE_MISC_CTL, misc);
	}
	
	/* Clear intr status */
	uint32_t reg = RD_WORD(CACHE_INTR_STATUS);
	if (reg & 1)
		WR_WORD(CACHE_INTR_CLR, 1);

	/* Flush it */
	misc |= 0x10;
	WR_WORD(CACHE_MISC_CTL, misc);
	flash_delay(5);

	/* Check to see it is finished */
	while (1) {
		reg = RD_WORD(CACHE_INTR_STATUS);
		if (reg & 1) {
			WR_WORD(CACHE_INTR_CLR, 1);
			break;
		}
		flash_delay(2);
	}

	/* Enable Cache */
	misc &= ~0x10;
	misc |= 0x1;
	WR_WORD(CACHE_MISC_CTL, misc);
	
}

/*****

	Flash APIs

*****/
void hal_flash_open(int safe_tmo);
int hal_flash_write(int start_sector, uint8_t *buffer, uint32_t buffer_len);
int hal_flash_erase(int start_sector, int nb_sector);
#endif
