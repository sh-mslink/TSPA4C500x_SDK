#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file spi_flash.c
 *
 * @brief Platform SPI Flash functions  
 *
 * Copyright (C) Inplay Technologies Inc. 2018-2020
 *
 ****************************************************************************************
 */

#if CFG_EXT_SPI_FLASH
#include "stddef.h"
#include "stdint.h"
#include "string.h"

#include "in_mmap.h"
#ifndef KEIL_FLASH_LOAD_TOOL
#include ".\hal\hal_clk.h"
#endif
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_spi.h"
#include ".\hal\hal_icache.h"
#include ".\hal\hal_power.h"

#ifdef KEIL_FLASH_LOAD_TOOL
#include "in_arm.h"
#include "in_irq.h"
#include ".\hal\hal_timer.h"
#endif

#include "spi_flash.h"

#define SPI_FIFO_DEPTH		8

#if CFG_EXT_SPI_FLASH_MXIC
#define SPI_INS_SPEED			4000000
#define SPI_READ_SPEED		2000000
#define SPI_PROG_SPEED		2000000
#define SPI_READ_SIZE			64	// avoid overflow
#define SPI_PROG_SIZE			64	// avoid overflow
#define SPI_SS						0
#define FLASH_MANU_ID			0xC2
#define FLASH_DEVICE_ID		0x13
#define FLASH_PAGE_SIZE		256
#define FLASH_BLOCK_SIZE 	(64 * 1024)
#define FLASH_SECTOR_SIZE (4 * 1024)
#endif

#if CFG_EXT_SPI_FLASH_PUYA
#define SPI_INS_SPEED			1000000
#define SPI_READ_SPEED		2000000
#define SPI_PROG_SPEED		2000000
#define SPI_READ_SIZE			64	// avoid overflow
#define SPI_PROG_SIZE			64	// avoid overflow
#define SPI_SS						0
#define FLASH_MANU_ID			0x85
#define FLASH_DEVICE_ID		0x12
#define FLASH_PAGE_SIZE		256
#define FLASH_BLOCK_SIZE 	(64 * 1024)
#define FLASH_SECTOR_SIZE (4 * 1024)
#endif
#if CFG_EXT_SPI_FLASH_GIGA
#define SPI_INS_SPEED			1000000
#define SPI_READ_SPEED		2000000
#define SPI_PROG_SPEED		2000000
#define SPI_READ_SIZE			64	// avoid overflow
#define SPI_PROG_SIZE			64	// avoid overflow
#define SPI_SS						0
#define FLASH_MANU_ID			0xC8
#define FLASH_DEVICE_ID		0x12
#define FLASH_PAGE_SIZE		256
#define FLASH_BLOCK_SIZE 	(64 * 1024)
#define FLASH_SECTOR_SIZE (4 * 1024)
#endif
/*
 * Timer
 ****************************************************************************************
 */
#ifdef KEIL_FLASH_LOAD_TOOL
static void time_delay(uint32_t us)
{
	uint32_t tick;

	timer_clear_intr(TIM1_BASE);
	NVIC_ClearPendingIRQ(Tim1_IROn);
	NVIC_DisableIRQ(Tim1_IROn);

	timer_disable(TIM1_BASE);
	timer_set_mode(TIM1_BASE, 1);	// one time mode
	timer_intr_mask(TIM1_BASE, 0);	// unmask it
	tick = 32 * us;
	timer_load_count(TIM1_BASE, tick);
	timer_enable(TIM1_BASE);

	while (!(timer_intr_status(TIM1_BASE) & 0x1));

	timer_clear_intr(TIM1_BASE);
	NVIC_ClearPendingIRQ(Tim1_IROn);

	timer_disable(TIM1_BASE);
}
#endif

/*
 * SPI Controller
 ****************************************************************************************
 */
#ifndef KEIL_FLASH_LOAD_TOOL
static void time_delay(uint32_t us)
{
	for (int i = 0; i < (6*us); i++) {
		__nop();
	}			
	
}
static void spi_flash_xip_share(uint32_t ins, int speed, int wait_cycle, int ins_width, int addr_width, int tran_type, int si_fmt)
{
	// Configure SPI 
	spi_disable(QSPI_BASE);
	spi_baud_rate(QSPI_BASE, CFG_QSPI_CLK, speed);
	spi_ctl0(QSPI_BASE, si_fmt, SPI_TMOD_RX_ONLY, 32, 0, 0);
	qspi_spi_ctl(QSPI_BASE, wait_cycle, ins_width, addr_width, tran_type);
	spi_rxftl(QSPI_BASE, 0);
	spi_intr_mask(QSPI_BASE, SPI_IT_ALL);
	spi_intr_unmask(QSPI_BASE, SPI_IT_RXF);
	spi_ndf(QSPI_BASE, 1);
	spi_ser(QSPI_BASE, 1, SPI_SS);//re-enable XIP need set to 1
	spi_enable(QSPI_BASE);		

#if CFG_FPGA
	WR_WORD(0x44123038, 0);
	qspi_single_wire_mode(0);		
#else	
	// four wires
	qspi_single_wire_mode(0);		
#endif

	// Clear icache memory
	icache_clear_mem();

        time_delay(100);//need delay here
        
	// Program glue logic
	qspi_xip_enable(addr_width, wait_cycle, tran_type);
	qspi_xip_ssn(1);
	qspi_xip_ins(ins);

	// Enable icache
	icache_en(1);

	// Review: SPI flash continuous mode
#if 0
	uint32_t reg = RD_WORD(0x44107020);
	reg &= ~1;
	WR_WORD(0x44107020, reg);		// disable glue logic
	reg = (1<<5) | (1<<8);
	WR_WORD(0x4410702C, reg);		// M7 - M0
	
	uint8_t dummy[4];
	qspi_4read_start(0, dummy, 4);
	
	qspi_spi_ctl(SPI0_BASE, 4, QSPI_CMD_WIDTH_0BITS, QSPI_ADDR_WIDTH_32BITS, QSPI_TT_CMD_ADDR_QUAD);
	reg = RD_WORD(0x44107020);
	reg |= 1;
	WR_WORD(0x44107020, reg);		// enable glue logic
	
#endif 
}
#endif
static void spi_config(int speed, int ssn, int fmt, int tmod, int dfs, int ndf, int ins_width, int addr_width, int idle_cycle, int tran_type)
{
	spi_disable(QSPI_BASE);		// disable SPI
#ifndef KEIL_FLASH_LOAD_TOOL
	spi_baud_rate(QSPI_BASE, CFG_QSPI_CLK, speed);
#else
	spi_baud_rate(QSPI_BASE, 32000000, speed);		// default SPI pclk
#endif
	spi_ctl0_clear(QSPI_BASE);
	spi_ctl0(QSPI_BASE, fmt, tmod, dfs, 0, 0);
	if (fmt == SPI_QUAD_FMT) {
		qspi_spi_ctl(QSPI_BASE, idle_cycle, ins_width, addr_width, tran_type);
	}
	spi_txftl(QSPI_BASE, 0);		
	spi_rxftl(QSPI_BASE, 0);		
	if (ndf)
		spi_ndf(QSPI_BASE, (ndf-1));
	spi_ser(QSPI_BASE, 0, ssn);		// disable chip select		
	spi_intr_clr(QSPI_BASE);
	spi_enable(QSPI_BASE);		// enable SPI
}

static void spi_tx(int speed, uint8_t *ins, uint16_t ins_len, uint8_t *data, uint16_t data_len)
{
	int nbytes;

#if CFG_FPGA
	WR_WORD(0x44123038, 1);
#endif
	spi_config(speed, SPI_SS, SPI_STD_FMT, SPI_TMOD_TX_ONLY, 8, 0, 0, 0, 0, 0);
	qspi_single_wire_mode(1);		

	int fifo_size = SPI_FIFO_DEPTH;

	// Fill the FIFO
	if (ins_len) {
		if (ins_len <= fifo_size) {
			nbytes = ins_len;
		} else {
			nbytes = fifo_size;
		}

		for (int i = 0; i < nbytes; i++) {
			spi_dr_write(QSPI_BASE, *ins++);
		}

		ins_len -= nbytes;
		fifo_size -= nbytes;
	}

	if (fifo_size && data_len) {
		if (data_len <= fifo_size) {
			nbytes = data_len;
		} else {
			nbytes = fifo_size;
		}

		for (int i = 0; i < nbytes; i++) {
			spi_dr_write(QSPI_BASE, *data++);
		}

		data_len -= nbytes;
		fifo_size -= nbytes;
	}

	// Enable chip select 
	spi_ser(QSPI_BASE, 1, SPI_SS);			

	while (ins_len) {
		while (!(spi_sr(QSPI_BASE) & SPI_SR_TFNF)); 		// poll until TX FIFO not full
		spi_dr_write(QSPI_BASE, *ins++);
		ins_len -= 1;
	}

	while (data_len) {
		while (!(spi_sr(QSPI_BASE) & SPI_SR_TFNF)); 		// poll until TX FIFO not full
		spi_dr_write(QSPI_BASE, *data++);
		data_len -= 1;
	}

	do {
		uint32_t status = spi_sr(QSPI_BASE);
		if ((status & SPI_SR_TFE) && !(status & SPI_SR_BUSY)) 	// make sure tx empty and not busy 
			break;
	} while(1);

	spi_disable(QSPI_BASE);		// Disable SPI
}

static void spi_trx(int speed, int dfs, uint8_t *ins, uint16_t ins_len, uint8_t *rxb, uint16_t rx_len)
{
	//only support data frame size is 8 or 32 
#if CFG_FPGA
	WR_WORD(0x44123038, 1);
#endif

	if (dfs == SPI_DFS_32_BITS) {
		spi_config(speed, SPI_SS, SPI_STD_FMT, SPI_TMOD_EEPROM_READ, dfs, rx_len/4, 0, 0, 0, 0);
	} else {
		spi_config(speed, SPI_SS, SPI_STD_FMT, SPI_TMOD_EEPROM_READ, dfs, rx_len, 0, 0, 0, 0);
	}
	qspi_single_wire_mode(1);		

	// fill the TX fifo
	if (dfs == SPI_DFS_8_BITS) {
		for (int i = 0; i < ins_len; i++) {
			spi_dr_write(QSPI_BASE, *ins++);
		}
	}

	if (dfs == SPI_DFS_32_BITS) {
		for (int i = 0; i < (ins_len/4); i++) {
			spi_dr_write(QSPI_BASE, *((uint32_t *)ins++));
		}
	}

	// chip select 
	spi_ser(QSPI_BASE, 1, SPI_SS);			

	// read, 
	int count = 0;
	if (dfs == SPI_DFS_8_BITS) {
		uint8_t *rxbuf = rxb;

		do {
			int rxfl = spi_rxfl(QSPI_BASE);
			for (int i = 0; i < rxfl; i++) {
				*rxbuf++ = (uint8_t)spi_dr_read(QSPI_BASE);
			}
			count += rxfl;
		} while (count < rx_len);
	} 

	if (dfs == SPI_DFS_32_BITS) {
		uint32_t *rxbuf = (uint32_t *)rxb;

		do {
			int rxfl = spi_rxfl(QSPI_BASE);
			for (int i = 0; i < rxfl; i++) {
#if 0
				uint32_t data;
				data = spi_dr_read(QSPI_BASE);
				*rxbuf++ = data;
				*rxbuf++ = data>>8;
				*rxbuf++ = data>>16;
				*rxbuf++ = data>>24;
#else
				*rxbuf++ = spi_dr_read(QSPI_BASE);
#endif
			}
			count += rxfl;
		} while (count < (rx_len/4));
	}

	// Disable SPI
	while(1) {
		uint32_t status = spi_sr(QSPI_BASE);
		if ((status & SPI_SR_TFE) && !(status & SPI_SR_BUSY))	// make sure tx empty and not busy 
			break;
	}
	spi_disable(QSPI_BASE);		

	// reverse data aince the SPI fifo is big endian
	if (dfs == SPI_DFS_32_BITS) {
		for (int i = 0; i < (rx_len/4); i++) {
			*((uint32_t *)rxb + i) = __rev(*((uint32_t *)rxb + i));
		}
	}
}

/*
 * SPI Flash Commands
 ****************************************************************************************
 */
#if CFG_EXT_SPI_FLASH_MXIC
static uint8_t read_status(void)
{
	uint8_t ins[1];
	uint8_t ins_rsp[1];

	ins[0] = 0x05;
	spi_trx(SPI_INS_SPEED, SPI_DFS_8_BITS, ins, 1, ins_rsp, 1);

	return ins_rsp[0];
}
#endif

#if CFG_EXT_SPI_FLASH_PUYA
static uint16_t read_status(void)
{
	uint8_t ins[1];
	uint8_t ins_rsp[2];

	ins[0] = 0x05;
	spi_trx(SPI_INS_SPEED, SPI_DFS_8_BITS, ins, 1, ins_rsp, 2);
	
	return (ins_rsp[0]|(ins_rsp[1]<<8));
}
#endif
#if CFG_EXT_SPI_FLASH_GIGA
static uint8_t read_status(void)
{
	uint8_t ins[1];
	uint8_t ins_rsp[1];

	ins[0] = 0x05;
	spi_trx(SPI_INS_SPEED, SPI_DFS_8_BITS, ins, 1, ins_rsp, 1);
	
	return (ins_rsp[0]);
}
#endif
static void write_enable(void)
{
	uint8_t ins[1];

	ins[0] = 0x06;
	spi_tx(SPI_INS_SPEED, ins, 1, NULL, 0);

	// poll WEL bit 
	while (!(read_status() & 0x2));
}

static void write_disable(void)
{
	uint8_t ins[1];

	ins[0] = 0x04;
	spi_tx(SPI_INS_SPEED, ins, 1, NULL, 0);

	// poll WEL bit 
	while (read_status() & 0x2);
}
#if CFG_EXT_SPI_FLASH_GIGA
static void write_status(uint8_t status)
{
	uint8_t ins[2];

	ins[0] = 0x01;
	ins[1] = (uint8_t)status;

	write_enable();
	spi_tx(SPI_INS_SPEED, ins, 2, NULL, 0);
	write_disable();
}

#endif
#if CFG_EXT_SPI_FLASH_MXIC
static void write_status(uint8_t status)
{
	uint8_t ins[2];

	ins[0] = 0x01;
	ins[1] = (uint8_t)status;

	write_enable();
	spi_tx(SPI_INS_SPEED, ins, 2, NULL, 0);
	write_disable();
}

#endif

#if CFG_EXT_SPI_FLASH_PUYA
static void write_status(uint16_t status)
{
	uint8_t ins[3];

	ins[0] = 0x01;
	ins[1] = (uint8_t)status;
	ins[2] = (uint8_t)(status>>8);

	write_enable();
	spi_tx(SPI_INS_SPEED, ins, 3, NULL, 0);
	write_disable();
}

#endif

static void erase_sector(uint32_t address)
{
	uint8_t ins[4];

	ins[0] = 0x20;
	ins[1] = (uint8_t)(address>>16);
	ins[2] = (uint8_t)(address>>8);
	ins[3] = (uint8_t)(address);;

	write_enable();
	spi_tx(SPI_INS_SPEED, ins, 4, NULL, 0);

	// poll WIP bit 
	while (read_status() & 1);
}

static void erase_block(uint32_t address)
{
	uint8_t ins[4];

	ins[0] = 0xD8;
	ins[1] = (uint8_t)(address>>16);
	ins[2] = (uint8_t)(address>>8);
	ins[3] = (uint8_t)(address);;

	write_enable();
	spi_tx(SPI_INS_SPEED, ins, 4, NULL, 0);

	// poll WIP bit 
	while (read_status() & 1);
}

static void erase_chip(void)
{
	uint8_t ins[1];

	ins[0] = 0xC7;

	write_enable();

	spi_tx(SPI_INS_SPEED, ins, 1, NULL, 0);

	// poll WIP bit 
	while (read_status() & 1);
}

static void prog_data(uint32_t address, uint8_t *data, uint16_t data_len)
{
	uint8_t ins[4];

	ins[0] = 0x02;
	ins[1] = (uint8_t)(address>>16);
	ins[2] = (uint8_t)(address>>8);
	ins[3] = (uint8_t)(address);

	write_enable();

	spi_tx(SPI_PROG_SPEED, ins, 4, data, data_len);

	// poll WIP bit 
	while (read_status() & 1);
}

static void read_data(uint32_t address, uint8_t *data, uint16_t data_len)
{
	uint8_t ins[4];
	
	ins[0] = (uint8_t)(address);
	ins[1] = (uint8_t)(address>>8);
	ins[2] = (uint8_t)(address>>16);
	ins[3] = 0x03;

	spi_trx(SPI_READ_SPEED, SPI_DFS_32_BITS, ins, 4, data, data_len);
}

static uint16_t manu_dev_id(void)
{
	uint8_t ins[4];
	uint8_t ins_rsp[2];

	ins[0] = 0x90;
	ins[1] = 0x00;
	ins[2] = 0x00;
	ins[3] = 0x00;

	spi_trx(SPI_INS_SPEED, SPI_DFS_8_BITS, ins, 4, ins_rsp, 2);

	// manufacture + device ID
	return (ins_rsp[0] | (ins_rsp[1] << 8));
}

/*
 * SPI Flash APIs
 ****************************************************************************************
 */
int spi_flash_init(void)
{
#ifdef KEIL_FLASH_LOAD_TOOL
	//int has_flash = 0;
	//int qspi_need_cfg = 0;

	/// Disable XIP mode
	qspi_xip_disable();
	icache_en(0);

	if (CFG_EXT_SPI_FLASH_POWER_FROM_602) {
		/// Turn on power
		aon_qspi_vddio(1);
		/// Wait
		if (CFG_EXT_SPI_FLASH_POWER_ON_SETTLE_TIME)
			time_delay(CFG_EXT_SPI_FLASH_POWER_ON_SETTLE_TIME);
	}
		
	/// QSPI pin mux
	spi_flash_pin_mux(1);		

#endif

	uint16_t manu_id = manu_dev_id();

//printf("id=%04x\r\n", manu_id);

	if (manu_id != (FLASH_MANU_ID | (FLASH_DEVICE_ID << 8))) 
		return 0;

#if CFG_EXT_SPI_FLASH_MXIC
	uint8_t status;

	status = read_status();
	if (!(status & 0x40)) {
		status |= 0x40;
		write_status(status);
	}
#endif
#if CFG_EXT_SPI_FLASH_GIGA
	uint8_t status;

	status = read_status();
	if (!(status & 0x40)) {
		status |= 0x40;
		//write_status(status);
	}
#endif
#if CFG_EXT_SPI_FLASH_PUYA
	uint16_t status;

	status = read_status();
	if (!(status & 0x200)) {
		status |= 0x200;
		write_status(status);
	}
#endif

	return 1;
}

void spi_flash_deinit(void)
{
	// Nothing to do
}

int spi_flash_chip_erase(void)
{
	erase_chip();	
	return 1;
}

#ifndef KEIL_FLASH_LOAD_TOOL
int spi_flash_sector_erase(uint32_t addr, uint32_t size)
{
	while (size) {
		erase_sector(addr);
		addr += FLASH_SECTOR_SIZE;
		if (size >= FLASH_SECTOR_SIZE)
			size -= FLASH_SECTOR_SIZE;
		else
			break;
	}

	return 1;
}
#else
int spi_flash_sector_erase(uint32_t addr)
{
	erase_sector(addr);
	return 1;
}
#endif

void spi_flash_read(uint32_t addr, uint8_t *data, uint32_t data_len)
{
	int nbytes;

	while (data_len) {
		if (data_len >= SPI_READ_SIZE)
			nbytes = SPI_READ_SIZE;
		else
			nbytes = data_len;				
		
		read_data(addr, data, nbytes);
		addr += nbytes;
		data += nbytes;
		data_len -= nbytes;
	}	
}

int spi_flash_prog_page(uint32_t addr, uint8_t *data, uint32_t data_len)
{
	int nbytes;

	while (data_len) {
		if (data_len >= SPI_PROG_SIZE)
			nbytes = SPI_PROG_SIZE;
		else
			nbytes = data_len;

		prog_data(addr, data, nbytes);

		addr += nbytes;
		data += nbytes;
		data_len -= nbytes;
	}
	
	return 1;
}

uint32_t spi_flash_verify(uint32_t addr, int size, uint8_t *data)
{
	int nbytes, ok = 1;
	uint32_t offset = 0, saddr = addr;

	while (size) {
		/// By initialized below to 0 cuases linker to link in the C library "memset" function which
		/// not only increase the code size, but also crashed the system  if the "memset" address 
		/// is not ready to be accessed yet (Boot and SPI flash is not ready).   
		uint8_t buf[SPI_READ_SIZE];

		if (size >= SPI_READ_SIZE)
			nbytes = SPI_READ_SIZE;
		else
			nbytes = size;

		read_data(addr, buf, nbytes);

		for (int i = 0; i < nbytes; i++) {
			if (*(data+offset) != buf[i]) {
				ok = 0;
				break;
			}
			offset += 1;
		}

		if (!ok)
			break;
		addr += nbytes;
		size -= nbytes;
	}			

	return (saddr+offset);
}

void spi_flash_pin_mux(int need_pin_mux)
{
	/// Pin mux configure
	int pin_3b = 0;
	uint32_t pin_cfg[6];

	pin_cfg[0] = CFG_QSPI_PIN_0;
	pin_cfg[1] = CFG_QSPI_PIN_1;
	pin_cfg[2] = CFG_QSPI_PIN_2;
	pin_cfg[3] = CFG_QSPI_PIN_3;
	pin_cfg[4] = CFG_QSPI_PIN_4;
	pin_cfg[5] = CFG_QSPI_PIN_5;

	for (int i = 0; i < 6; i++) {
		int pin;
		int mux;
		int oe;
		int ie;
		int pd;
		int pu;

		pin = pin_cfg[i] & 0xF;
		mux = (pin_cfg[i] >> QSPI_CFG_MUX_SHIFT) & 0xF;
		oe = (pin_cfg[i] >> QSPI_CFG_OE_IE_SHIFT) & 0x1;
		ie = (pin_cfg[i] >> (QSPI_CFG_OE_IE_SHIFT+1)) & 0x1;
		pd = (pin_cfg[i] >> QSPI_CFG_PD_PU_SHIFT) & 0x1;
		pu = (pin_cfg[i] >> (QSPI_CFG_PD_PU_SHIFT+1)) & 0x1;

		if (need_pin_mux)
			gpio_qspi_pin_mux(pin, mux, 0);
		gpio_qspi_pin_pad_oe_ie(pin, oe, ie);
		gpio_qspi_pin_pad_pu_pd(pin, pu, pd);
		gpio_qspi_pin_pad_pc(pin, 1);

		if (pin == 6)
			pin_3b = 1;
	}

	/// Enable the pin mux
	if (need_pin_mux)
		gpio_qspi_pin_mux_en(1, pin_3b);
}

#ifndef KEIL_FLASH_LOAD_TOOL
void spi_flash_clk(void)
{
	uint32_t mux = clk_root_mux_get();
	uint32_t mux1;

	if (mux == 1) {
		if (CFG_QSPI_CLK == 64000000)
			mux1 = CLK_QSPI_DIV1;
		else if (CFG_QSPI_CLK == 32000000)
			mux1 = CLK_QSPI_DIV2;
		else if (CFG_QSPI_CLK == 16000000)
			mux1 = CLK_QSPI_DIV4;
		else if (CFG_QSPI_CLK == 8000000)
			mux1 = CLK_QSPI_DIV8;
	} else {
		if (CFG_QSPI_CLK == 32000000)
			mux1 = CLK_QSPI_DIV1;
		else if (CFG_QSPI_CLK == 16000000)
			mux1 = CLK_QSPI_DIV2;
		else if (CFG_QSPI_CLK == 8000000)
			mux1 = CLK_QSPI_DIV4;
		else if (CFG_QSPI_CLK == 4000000)
			mux1 = CLK_QSPI_DIV8;
	}
		
	clk_qspi_mux(mux1);
	
	return;
}

void spi_flash_xip_enable(uint32_t speed)
{
#if CFG_EXT_SPI_FLASH_MXIC
	spi_flash_xip_share(0xEB, speed, 6, QSPI_CMD_WIDTH_8BITS, QSPI_ADDR_WIDTH_24BITS, QSPI_TT_CMD_STD_ADDR_QUAD, SPI_QUAD_FMT);
#endif

#if CFG_EXT_SPI_FLASH_PUYA
	spi_flash_xip_share(0xEB, speed, 6, QSPI_CMD_WIDTH_8BITS, QSPI_ADDR_WIDTH_24BITS, QSPI_TT_CMD_STD_ADDR_QUAD, SPI_QUAD_FMT);
#endif
#if CFG_EXT_SPI_FLASH_GIGA
	spi_flash_xip_share(0x3B, speed, 8, QSPI_CMD_WIDTH_8BITS, QSPI_ADDR_WIDTH_24BITS, QSPI_TT_CMD_STD_ADDR_STD, SPI_DUAL_FMT);
#endif

}

void spi_flash_xip_disable(void)
{
	// disable xip mode
	qspi_xip_disable();

	// disable icache
	icache_en(0);
}
#endif	// !KEIL_FLASH_LOAD_TOOL
#endif 	// CFG_EXT_SPI_FLASH
