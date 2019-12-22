#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file ram_entry.c
 *
 * @brief RAM functions to support external SPI flash
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "boot_share.h"

#include "in_arm.h"
#include "in_fw_upd.h"

#include ".\hal\hal_power.h"
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_spi.h"
#include ".\hal\hal_efuse.h"
#include ".\hal\hal_clk.h"
#include ".\hal\hal_timer.h"

#if CFG_EXT_SPI_FLASH
#include "spi_flash.h"
#endif	// CFG_EXT_SPI_FLASH

//#define DEBUG

#define BOOTRAM_BOOTCFG_START				0x200F80
#define HASH_CMD_ADDR                   	0xDB000000
#define HASH_RESULT_ADDR              		0x201000
#define HASH_FUNC                           0x00000f15 //hash_calc
#define HASH_FUNC_PARAM                     0x0020e03c //g_rom

typedef struct {
	uint32_t clkd0_enable1;
	uint32_t clkd0_enable2;
	uint32_t clkd1_enable1;
	uint32_t clkd2_enable1;
	uint32_t clk_enbale_1;

	uint32_t clk_ctrl_1;
	uint32_t clk_ctrl_2;	
} clk_t;
typedef union {
	struct {
		uint32_t lock:1;
		uint32_t flash_present:1;
		uint32_t reserve1:2;
		uint32_t feature_sel:4;
		uint32_t sec_key_sel:4;
		uint32_t key_alg:3;
	} u;
	uint32_t word; 	
} efuse_bank0_word0_t;

typedef union {
	struct {
		uint32_t qspi_0_pin_mux:3;	// {2:0}
		uint32_t reserve1:1;			
		uint32_t qspi_2_pin_mux:3;	// [6:4]
		uint32_t reserve2:1;
		uint32_t qspi_3_pin_mux:3;
		uint32_t reserve3:1;
		uint32_t qspi_4_pin_mux:3;
		uint32_t reserve4:1;
		uint32_t qspi_5_pin_mux:3;
		uint32_t reserve5:5;
		uint32_t qspi_3a_3b_sel:1;
		uint32_t reserve6:3;
		uint32_t tvs:3;
	} u;
	uint32_t word; 	
} efuse_bank0_word0_qspi_t;

typedef union {
	struct {
		uint32_t lock:1;
		uint32_t jlink_disable:1;
		uint32_t flash_encrypt:1;
		uint32_t secure_boot:1;
		uint32_t ecc_length:1;
		uint32_t pref_if:1;
		uint32_t inf_def:3;
		uint32_t ram_secure_boot:1;
		uint32_t host_auth:1;
		uint32_t spi_read_speed:2;
		uint32_t secure_boot_w_uuid:1;
		uint32_t reserve1:2;		
		uint32_t rtc_preset:1;
		uint32_t xo_calib_present:1;
		uint32_t xo_cap_n:4;
		uint32_t xo_cap_p:4;
	} u;
	uint32_t word; 	
} efuse_bank2_word0_t;

typedef struct {
	efuse_bank0_word0_t ef00;
	efuse_bank0_word0_qspi_t ef00_qspi;
	efuse_bank2_word0_t ef20;

	spi_flash_cb_t sf_cb;
	boot_config_t *cnf; 

} bootrom_t;

static clk_t g_clk = {0};
#ifdef DEBUG
static int g_test = 0;
#endif

#if CFG_EXT_SPI_FLASH
boot_config_t boot_cfg  __attribute__((section("BOOTCFG"))) = {
	.sspi_intr_enable = CFG_BRAM_SSPI_INT_EN,
	.sspi_intr_gio_grp = CFG_BRAM_SSPI_INT_PORT,
	.sspi_intr_gio_pin = CFG_BRAM_SSPI_INT_PIN,
	.sspi_intr_gio_level = CFG_BRAM_SSPI_INT_LEVEL,
	.hpb_flash_addr = CFG_BRAM_RAM_APP_FLASH_ADDR,
	.hpb_ram_addr = CFG_BRAM_RAM_APP_RAM_ADDR,
	.hpb_size = CFG_BRAM_RAM_APP_SIZE,
	.boot_opt = CFG_BRAM_BOOT_OPT,
	.boot_wait_time = CFG_BRAM_BOOT_WAIT_TIME,
	.boot_gio_grp = CFG_BRAM_BOOT_GPIO_PORT,
	.boot_gio_pin = CFG_BRAM_BOOT_GPIO_PIN,
	.boot_gio_level = CFG_BRAM_BOOT_GPIO_LEVEL,
	.secure_img_addr = CFG_BRAM_SECURE_BOOT_HASH_ADDR,
	.secure_img_size = CFG_BRAM_SECURE_BOOT_HASH_SIZE,
	.secure_signature = {CFG_BRAM_SECURE_BOOT_ECDSA_SIG},
	.magic_word = BOOT_MAGIC_WORD,
};
#endif	//CFG_EXT_SPI_FLASH

__asm void cold_boot_jump(uint32_t start_addr)
{
	; r0 = SP location
	mov r1, r0
	add r0, r0, #4
	ldr r0, [r0]
	ldr sp, [r1] 
	isb
	bx r0
}

__asm void warm_boot_jump(uint32_t pcr, uint32_t stk)
{
	; r0 = prog ptr
	; r1 = stack ptr
	mov sp, r1		
	orr r0, r0, #1
	isb
	bx r0
}

static void clk_cfg_save(void)
{
#if !CFG_FPGA
	g_clk.clkd0_enable1 = 	RD_WORD(GLOBAL_REG_CLKD0_ENABLE_1);
	g_clk.clkd0_enable2 = 	RD_WORD(GLOBAL_REG_CLKD0_ENABLE_2);
	g_clk.clkd1_enable1 = 	RD_WORD(GLOBAL_REG_CLKD1_ENABLE_1);
	g_clk.clkd2_enable1 = 	RD_WORD(GLOBAL_REG_CLKD2_ENABLE_1);
	g_clk.clk_enbale_1 = 	RD_WORD(GLOBAL_REG_CLK_ENABLE_1);

	g_clk.clk_ctrl_1 = 	RD_WORD(GLOBAL_REG_CLK_CTRL_1);
	g_clk.clk_ctrl_2 = 	RD_WORD(GLOBAL_REG_CLK_CTRL_2);
#endif
}

static void clk_cfg_retore(void)
{
#if !CFG_FPGA
	WR_WORD(GLOBAL_REG_CLKD0_ENABLE_1, g_clk.clkd0_enable1);
	WR_WORD(GLOBAL_REG_CLKD0_ENABLE_2, g_clk.clkd0_enable2);
	WR_WORD(GLOBAL_REG_CLKD1_ENABLE_1, g_clk.clkd1_enable1);
	WR_WORD(GLOBAL_REG_CLKD2_ENABLE_1, g_clk.clkd2_enable1);
	WR_WORD(GLOBAL_REG_CLK_ENABLE_1, g_clk.clk_enbale_1);

	WR_WORD(GLOBAL_REG_CLK_CTRL_1, g_clk.clk_ctrl_1);
	WR_WORD(GLOBAL_REG_CLK_CTRL_2, g_clk.clk_ctrl_2);
#endif
}

#if CFG_EXT_SPI_FLASH
static void time_delay(uint32_t us)
{
	for (int i = 0; i < (6*us); i++) {
		__nop();
	}			
	
}

static void spi_flash_power_on(void)
{
#if !CFG_FPGA
	/// Turn on power
	aon_qspi_vddio(1);
	/// Wait
	time_delay(CFG_EXT_SPI_FLASH_POWER_ON_SETTLE_TIME);
#endif
}

static int boot_spi_flash_open(void)
{
#if !CFG_FPGA
	int qspi_need_pin_cfg = 0;

	/// external SPI flash
	if (!efuse_get_spiflash_present()) {
		/// Somehow user still configure for ext. SPI flash. maybe testing
		qspi_need_pin_cfg = 1;
	}

#if (CFG_EXT_SPI_FLASH_POWER_FROM_602) 
	if (qspi_need_pin_cfg) {
		/// Need to make sure that external SPI flash power is controlled by the HW
		spi_flash_power_on();
	}
#endif
		
	/// QSPI pin mux
	spi_flash_pin_mux(qspi_need_pin_cfg);		
#endif

	/// 
	if (!spi_flash_init()) {
		return 0;
	}

	return 1;
}

static int boot_spi_flash_close(void)
{
	spi_flash_deinit();

	return 1;
}

static int boot_spi_flash_erase(uint32_t addr, uint32_t size)
{
	if (!spi_flash_sector_erase(addr, size))
		return 0;

	return 1;
}

static int boot_spi_flash_prog(uint32_t addr, uint8_t *data, uint32_t data_len)
{
    if (addr == HASH_CMD_ADDR) {
        void (*fun)(uint8_t *hash, void *pbr) = (void (*)(uint8_t *hash, void *pbr))HASH_FUNC;
        bootrom_t *param = (bootrom_t*)HASH_FUNC_PARAM;
				param->ef20.word = RD_WORD(0x44104030);
				param->cnf = (boot_config_t *)(BOOTRAM_BOOTCFG_START);
        fun((uint8_t*)HASH_RESULT_ADDR, ( void *)HASH_FUNC_PARAM);  
          
    } else {
			spi_flash_prog_page(addr, data, data_len);

			// verify it ??? your decision...
			if (spi_flash_verify(addr, data_len, data) != (addr + data_len))
				return 0;
    }
	return 1;
}

static int boot_spi_flash_read(uint32_t addr, uint8_t *data, uint32_t data_len)
{
	spi_flash_read(addr, data, data_len);	
	uint32_t reg = RD_WORD(0x441070D0);
	if ((reg & 0x3) == 0x3) {
        WR_WORD(0x441070D4, (addr>>2));
	}
	return 1;
}
#else	// CFG_EXT_SPI_FLASH
static int boot_spi_flash_open_stub(void)
{
	return 1;
}

static int boot_spi_flash_close_stub(void)
{
	return 1;
}

static int boot_spi_flash_erase_stub(uint32_t addr, uint32_t size)
{
	return 1;
}

static int boot_spi_flash_prog_stub(uint32_t addr, uint8_t *data, uint32_t data_len)
{
	return 1;
}

static int boot_spi_flash_read_stub(uint32_t addr, uint8_t *data, uint32_t data_len)
{
	return 1;
}
#endif	// CFG_EXT_SPI_FLASH

#if CFG_EXT_SPI_FLASH
static void qspi_set_up(int cold_boot)
{
#if !CFG_FPGA
	int qspi_need_pin_cfg = 0;

	/// external SPI flash efuse bit is not set
	if (!efuse_get_spiflash_present()) {
		/// Somehow user still configure for ext. SPI flash. maybe testing
		qspi_need_pin_cfg = 1;
	}

#if CFG_EXT_SPI_FLASH_POWER_FROM_602
	/// Ext. SPI flash power controlled by HW.
	///		1. for not having "ext flash present" efuse bit and
	if (cold_boot && qspi_need_pin_cfg) {
		/// Power on ext. spi flash
		spi_flash_power_on();
	}	
#endif

	if (!cold_boot)
		qspi_need_pin_cfg = 1;

	/// QSPI pin mux
	spi_flash_pin_mux(qspi_need_pin_cfg);		

	/// QSPI core clock
	if (cold_boot)
		spi_flash_clk();

	/// If secure flash, turn on icache decoding
	//if (efuse_get_flash_secure_boot_enable())
	if (efuse_get_flash_encryption_enable())//turn on icache dec when flash is encripted
		spi_flash_icache_dec(1);
#endif

	/// XIP enable
	spi_flash_xip_enable(CFG_QSPI_SPEED);

}
#endif	// CFG_EXT_SPI_FLASH

#if CFG_FW_UPD_EN
void boot_fw_update(void) __attribute__((section("FW_UPD")));
static uint8_t fw_data[1024] __attribute__((section("FW_UPD")));
void boot_fw_update(void)
{
	fw_upd_info_t info;
	spi_flash_read(FW_UPD_INFO_ADDR, (uint8_t *)&info, sizeof(fw_upd_info_t));
	if (info.upd_magic == FW_UPD_MAGIC_WORD) {
		uint32_t from_addr = info.load_addr;
		uint32_t to_addr = info.copy_addr;
		uint32_t size = info.size;

		// erase
		spi_flash_sector_erase(to_addr, size);

		while (size) {
			int nbytes;

			if (size < 1024)
				nbytes = size;
			else
				nbytes = 1024;

			spi_flash_read(from_addr, fw_data, nbytes);
			spi_flash_prog_page(to_addr, fw_data, nbytes);

			from_addr += nbytes;
			to_addr += nbytes;
			size -= nbytes;
		}
	
		// clear control
		memset((void *)&info, 0, sizeof(fw_upd_info_t));	
		spi_flash_prog_page(FW_UPD_INFO_ADDR, (uint8_t *)&info, sizeof(fw_upd_info_t));

		// cold boot
		//aon_reset_chip();
	
	}
}

void boot_load_fw_upd_code(void)
{
	// Load from flash to rom
	spi_flash_read(0x1000, (uint8_t *)FW_UPD_CODE_START, FW_UPD_CODE_SIZE);

	// call it
	boot_fw_update();

}	
#endif	// CFG_FW_UPD_EN

static void boot_cold(void)
{
#if !CFG_FPGA
	/// Clock configure
	clk_cfg();

	/// Clock off
	clk_off();

	/// force SPI flash clock on
	clk_force_spiflash_ctl_clk();

#if CFG_EXT_SPI_FLASH
#if CFG_FW_UPD_EN
	boot_load_fw_upd_code();
#endif	// CFG_OTA_EN

	/// QSPI set up and enable XIP mode
	qspi_set_up(1);

	/// Ram app
#if CFG_BRAM_RAM_APP_EN 
	{
		if (!efuse_get_ram_secure_boot_enable()) {
			/// Not secure Ram app, copy from flash to ram thru XIP
			memcpy((void *)CFG_BRAM_RAM_APP_RAM_ADDR, (void *)CFG_BRAM_RAM_APP_FLASH_ADDR, CFG_BRAM_RAM_APP_SIZE); 
		}
		// Set vector table offset
		SCB->VTOR = CFG_BRAM_RAM_APP_RAM_ADDR & SCB_VTOR_TBLOFF_Msk; 

		cold_boot_jump(CFG_BRAM_RAM_APP_RAM_ADDR);
		/// never return
	}	
#endif
#endif	// CFG_EXT_SPI_FLASH
#endif

	// Set vector table offset
	SCB->VTOR = CFG_BRAM_COLD_BOOT_ADDR & SCB_VTOR_TBLOFF_Msk; 

	// branch to ...
	cold_boot_jump(CFG_BRAM_COLD_BOOT_ADDR);
	// never return...
}

static void boot_warm(uint32_t addr)
{
	/// resume address
	uint32_t stk = aon_read(0x11A0);
	uint32_t pcr = aon_read(0x11A4);

	/// clear the warm boot bit
	pcr &= ~0x80000000;
	//aon_write(0x11A4, pcr);

#if !CFG_FPGA
	/// Restore clock configuration
	clk_cfg_retore();

	/// force SPI flash clock on
	clk_force_spiflash_ctl_clk();

#if CFG_EXT_SPI_FLASH
	/// make sure efuse registers had been updated by the HW
	efuse_hw_upd_wait();

	/// QSPI set up and enable XIP mode
	qspi_set_up(0);

	/// Secure Ram app???
#endif	// CFG_EXT_SPI_FLASH
#endif

	// Set vector table offset
	SCB->VTOR = CFG_BRAM_COLD_BOOT_ADDR & SCB_VTOR_TBLOFF_Msk; 

	// Set floating point
	SCB->CPACR |= ((3UL << 10*2) |     /* set CP10 Full Access */
	               (3UL << 11*2)  );               /* set CP11 Full Access */

	// branch
	warm_boot_jump(pcr, stk);

	// never return
}

#if CFG_EXT_SPI_FLASH
#if CFG_FW_UPD_EN
static void spi_flash_rt_prog_page(void *pv) __attribute__((section("FW_UPD")));
#endif
static void spi_flash_rt_prog_page(void *pv)
{
	// disable XIP 
	spi_flash_xip_disable();

	// program spi flash
	spi_flash_rt_write_t *p = (spi_flash_rt_write_t *)pv;

	p->status = STATUS_OK;

	// erase
	if (!spi_flash_sector_erase(p->erase_addr, p->erase_len)) {
		p->status = STATUS_ERASE_FAIL;
		return;
	}

	// program
	spi_flash_prog_page(p->data_addr, p->data, p->data_len);
	

	// verify
	if (p->verify) {
		if (spi_flash_verify(p->data_addr, p->data_len, p->data) != (p->data_addr + p->data_len))
			p->status = STATUS_VERIFY_FAIL;
	}

	// reenable XIP
	spi_flash_xip_enable(CFG_QSPI_SPEED);

	return;
}
#endif	// CFG_EXT_SPI_FLASH

void boot_ram_entry(int reason, void *pv) __attribute__((section("ram_start")));
void boot_ram_entry(int reason, void *pv)
{
	switch (reason) {
		case SPI_FLASH_CB:
			{
#if CFG_EXT_SPI_FLASH
				spi_flash_cb_t *pcb = (spi_flash_cb_t *)pv;
				pcb->sflash_open = boot_spi_flash_open;
				pcb->sflash_close = boot_spi_flash_close;
				pcb->sflash_erase = boot_spi_flash_erase;
				pcb->sflash_prog = boot_spi_flash_prog;
				pcb->sflash_read = boot_spi_flash_read;
#else	// CFG_EXT_SPI_FLASH
				spi_flash_cb_t *pcb = (spi_flash_cb_t *)pv;
				pcb->sflash_open = boot_spi_flash_open_stub;
				pcb->sflash_close = boot_spi_flash_close_stub;
				pcb->sflash_erase = boot_spi_flash_erase_stub;
				pcb->sflash_prog = boot_spi_flash_prog_stub;
				pcb->sflash_read = boot_spi_flash_read_stub;
#endif	// CFG_EXT_SPI_FLASH
			}	
			break;
		case COLD_BOOT:
#ifdef DEBUG
			while(!g_test);
#endif
			boot_cold();
			break;
		case WARM_BOOT:
#ifdef DEBUG
			while(!g_test);
#endif
			boot_warm((uint32_t)pv);
			break;
		case SPI_FLASH_RT_WRITE:
#if CFG_EXT_SPI_FLASH
			spi_flash_rt_prog_page(pv);			
#endif	// CFG_EXT_SPI_FLASH
			break;
		case PM_SAVE_CLK_CFG:
			clk_cfg_save();
			break;
		default:
			break;
	}

	return;
}


