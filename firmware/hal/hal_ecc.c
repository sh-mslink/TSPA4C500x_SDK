#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_ecc.c
 *
 * @brief Platform ECC functions  
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
#if CFG_ECC_EN
#include "in_arm.h"
#include "in_mmap.h"
#include "in_irq.h"
//#include "in_debug.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "ARMCM4_FP.h"

#include ".\hal\hal_clk.h"
#include ".\hal\hal_ecc.h"
#if CFG_AES_EN
#include ".\hal\hal_aes.h"
#endif
#if CFG_PM_EN
#include ".\hal\hal_power.h"
#endif

#include "cmsis_os.h"

/*
 ****************************************************************************************
 * Declaration
 ****************************************************************************************
 */

static void hal_ecc_init(void);

/*
 ****************************************************************************************
 * IMPLEMENTATION
 ****************************************************************************************
 */

const uint32_t ecc_fw[] = { 
0xf8000009, 0xf8b6fa06, 0xf8bff0af, 0xf898832a, 
0xf8055422, 0xf82128a3, 0xf80bd36d, 0xf8000033,
0xf8000335, 0x000000ff, 0x2000001f, 0x20000021,
0x20000023, 0x20000025, 0x20000027, 0x20000029,
0x2000002b, 0x2000002d, 0x2000002f, 0x20000031,
0x20000104, 0x20000106, 0x20000108, 0x2000010a,
0x2000010c, 0x2000010e, 0x20000110, 0x20000112,
0x20000114, 0x20000116, 0x200002d9, 0x22000098,
0x00000000, 0x22000084, 0x00000000, 0x2200008d,
0x00000000, 0x22000033, 0x00000000, 0x22000035,
0x00000000, 0x220000b5, 0x00000000, 0x220000e2,
0x00000000, 0x220000dd, 0x00000000, 0x220000d5,
0x00000000, 0xc8004400, 0x00000000, 0x48200000,
0x20000037, 0x48200000, 0x44000400, 0x40008200,
0x220000ce, 0x40004400, 0x08c00000, 0x43000680,
0x4000c200, 0x23c00044, 0xd9004000, 0x3300007b,
0x6b000000, 0x3360004c,	0x41000440, 0x40008800,
0x6b008000, 0x33600049, 0x41008040, 0x40000c00,
0x2000003e, 0xd010c040, 0x41000c00, 0x2000003e,
0x6b004000, 0x33600059, 0x41004440, 0x40008a00,
0x6b00d000, 0x33600055, 0x4100d440, 0x40008e80,
0x2000003e, 0x4000d440, 0xd011c040, 0x41000e80,
0x2000003e, 0xd8004440, 0x3340006a, 0x41008800,
0xd810d040, 0x40000c00, 0x31400061, 0xd010c040,
0x40000c00, 0x6b008000, 0x33600067, 0x48200000,
0x41008040, 0x40000c00, 0x2000003e, 0xd010c040,
0x41000c00, 0x2000003e, 0xd8080440, 0x41008a00,
0xd81a8040, 0x40000e80, 0x31400071, 0xd001c440,
0x40008e80, 0x6b00d000, 0x33600077, 0x48200000,
0x4100d440, 0x40008e80, 0x2000003e, 0x4000d440,
0xd011c040, 0x41000e80, 0x2000003e, 0x24000000,
0x33400080, 0xd010c240, 0x40008000, 0x20000083,
0xd010c000, 0x40008240, 0x20000083, 0x24000000,
0x48400000, 0x48200000, 0x220000ce, 0xd0004400,
0x220000b6, 0xd800c400, 0x31400088, 0x2000008c,
0x24000000, 0x48200000, 0x220000ce, 0x220000c5,
0x33400094, 0xd8188040, 0x40008000, 0x20000097,
0xd8188000, 0x40008040, 0x20000097, 0x24000000,
0x40004680, 0x220000a2,	0x40000400, 0x4000d000,
0x40008680, 0x220000a2, 0x4000d200, 0x220000a6,
0x220000a5, 0x24000000, 0x40000200, 0x4000d800,
0x200000a6, 0x44000200, 0xc8004400, 0xc910ca00,
0xc808c000, 0xd0008200, 0xd4018a00, 0x40004400,
0x200000b6, 0x40000200, 0xca004400, 0xc910ca00,
0xc808c000, 0xd0008200, 0xd4018a00, 0x40004400,
0x200000b6, 0x48200000, 0x332000ba, 0xd810c040,
0x40008040, 0x200000bd, 0xd810c040, 0x40000c00,
0x200000bd, 0x40008000, 0xd800c400, 0x334000c2,
0x40008000, 0x200000c4, 0x40000400, 0x200000c4,
0x24000000, 0xd8004400, 0x334000ca, 0xd9004000,
0x48400000, 0x200000cd, 0xd8080400, 0x49400000,
0x200000cd, 0x24000000, 0x40000680, 0x40004400,
0x220000b6, 0x40000200, 0x48200000, 0x4000d400,
0x200000b6, 0x08c00000, 0x40008240, 0x43000200,
0xd808c400, 0x40004800, 0x2200003b, 0x400086c0,
0x24000000, 0x08c00001, 0x45000000, 0x44000400,
0x2200003b, 0x24000000, 0x40008680, 0x43000200,
0x43000640, 0x43000040, 0x44000000, 0x4100c240,
0x5180c000, 0x6a804000, 0x08c00000, 0xd0004400,
0xd4014c40, 0xd91a8800, 0x334000f3, 0x330000ff,
0x40008000, 0x40008840, 0x6a80c800, 0x08c00001,
0x6b004800, 0x336000f7, 0x08c00000, 0x41004400,
0x41004c40, 0x40008200, 0x40008a40, 0x21c000fd,
0x6d204000, 0x11800000, 0x200000eb, 0x51c08000,
0x310000f3, 0x6a80c800, 0x4000d400, 0x24000000,
0x22000134, 0x00000000, 0x2200011f, 0x00000000,
0x22000244, 0x00000000, 0x22000128, 0x00000000,
0x2200011c, 0x00000000, 0x2200016d, 0x00000000,
0x22000118, 0x00000000, 0x220002b8, 0x00000000,
0x220002be, 0x00000000, 0x220002ad, 0x00000000,
0x220001a9, 0x220002c5, 0x220001ae, 0x24000000,
0x48800000, 0x220001d5, 0x24000000, 0x440004c0,
0x220001c7, 0x22000244, 0x2200019b, 0x220001a9,
0x220002c5, 0x220001ae, 0x2200018f, 0x24000000,
0x44000480, 0x440004c0, 0x220001b9, 0x220001c7,
0x220001d5, 0x33c002d6, 0x2200019b, 0x220001a9,
0x220002c5, 0x220001ae, 0x2200018f, 0x24000000,
0x220002d3, 0x3180013a, 0x40003c80, 0x220001b9,
0x220002a1, 0x2000013c, 0x44000480, 0x220001b9,
0x48800000, 0x50a0f800, 0x11a00000, 0x22000194,
0x23e00142, 0x20000156, 0x15fe8000, 0x21e00156,
0x20000147, 0x2200019b, 0x20000147, 0x22000244,
0x2200019b, 0x68e0f800, 0x2000014b, 0x2620014e,
0x220001d5, 0x2000014e, 0x2000014f, 0x28e00145,
0x22000194, 0x20000156, 0x2200019b, 0x20000156,
0x220001a2, 0x20000156, 0x22000244, 0x2200019b,
0x68a0f800, 0x31600161, 0x2000015b, 0x220001d5,
0x33c002d6, 0x2000015e, 0x28a00152, 0x2200019b,
0x20000168, 0x26200165, 0x220001d5, 0x20000164,
0x20000165, 0x28a00154, 0x220001a2, 0x20000168,
0x220001a9, 0x220002c5, 0x220001ae, 0x2200018f,
0x24000000, 0xd902c000, 0x3140018c, 0xd90ac000,
0x3140018c, 0x44000480, 0x4000dc00, 0x220001b9,
0x40005000, 0x220000ad, 0x40000380, 0x40001200,
0x40004000, 0x220000ad, 0x40001200, 0x220000a6,
0x40000340, 0x40003200, 0x4000d800, 0x220000a6,
0x40001200, 0x220000a6, 0x400002c0, 0x40003a00,
0x4000d800, 0x220000a6, 0xd0005c00, 0x220000b6,
0xd0006c00, 0x220000b6, 0xd9007000, 0x2000018e,
0x48000000, 0x2000018e, 0x24000000, 0x40001c00,
0x40008080, 0x40005c00, 0x40008280, 0x24000000,
0x40001200, 0x400040c0, 0x40005000, 0x400002c0,
0x40009000, 0x400004c0, 0x24000000, 0x40002200,
0x400040c0, 0x40006000, 0x400002c0, 0x4000a000,
0x400004c0, 0x24000000, 0x40002200, 0x40004140,
0x40006000, 0x40000340, 0x4000a000, 0x40000540,
0x24000000, 0x40009800, 0x44000200, 0x220000a6,
0x400004c0, 0x24000000, 0x40001a00, 0x40004000,
0x40009a00, 0x220000a6, 0x40000200, 0x400040c0,
0x40005800, 0x40009a00, 0x220000a6, 0x400002c0,
0x24000000, 0x40001200, 0x4000d800, 0x220000a6,
0x40000200, 0x40004080, 0x40005000, 0x4000da00,
0x220000a6, 0x40000280, 0x40009000, 0x4000da00,
0x220000a6, 0x40000480, 0x24000000, 0x40001a00,
0x4000d800, 0x220000a6, 0x40000200, 0x400040c0,
0x40005800, 0x4000da00, 0x220000a6, 0x400002c0,
0x40009800, 0x4000da00, 0x220000a6, 0x400004c0,
0x24000000, 0x40001200, 0x40009800, 0x220000a6,
0x40000700, 0x40001a00, 0x40009000, 0x220000a6,
0x40000300, 0xd80ce400, 0x310001e1, 0x49c00000,
0x200001e2, 0x48c00000, 0x200001e3, 0x2200007c,
0x40000500, 0xd00ce400, 0x220000b6, 0x40000540,
0x4000a000, 0x220000ad, 0x40000740, 0x4000a200,
0x220000a6, 0x40000780, 0x4000e800, 0x4000aa00,
0x220000a6, 0x40000340, 0x40005000, 0x40009a00,
0x220000a6, 0x40000580, 0x40005800, 0x40009200,
0x220000a6, 0x40000700, 0xd81cb380, 0x40007400,
0x2200007c, 0x40000380, 0xd01cb000, 0x40000400,
0x220000b6, 0x400003c0, 0x40007000, 0x220000ad,
0x400005c0, 0x40009000, 0x40009a00, 0x220000a6,
0x40000700, 0x4000ba00, 0x220000a6, 0x40000740,
0xd8006c00, 0x2200007c, 0x4000a200, 0x220000a6,
0x40000200, 0x40004100, 0x42006800, 0x40000400,
0x220000b6, 0xd00d0400, 0x220000b6, 0x40000500,
0x4200ec00, 0x220000b6, 0x40000200, 0xd8144000,
0x40000400, 0x2200007c, 0x40000200, 0x40007000,
0x220000a6, 0x40000500, 0x40007800, 0x4000f200,
0x220000a6, 0xd8140740, 0x4000ec00, 0x2200007c,
0x40000740, 0x6b00e800, 0x33800236, 0x33600231,
0x4000c200, 0xd008e840, 0x40000680, 0x48200000,
0x2000023c, 0x4000c200, 0xd008e800, 0x40000740,
0x48000000, 0x2000023c, 0x33600239, 0x48200000,
0x2000023c, 0x4000c200, 0xd008e800, 0x40000740,
0x4100eb00, 0x4000e000, 0x20000240, 0x40009800,
0x4000f200, 0x220000a6, 0x40000500, 0x24000000,
0x40009a00, 0x40005800, 0x220000a6, 0x42000400,
0x220000b6, 0x40000500, 0x33e00262, 0x40001a00,
0x40004000, 0x220000ad, 0x40000780, 0x42000200,
0x40004400, 0x220000b6, 0xd000f400, 0x220000b6,
0x40000580, 0x40009800, 0x220000ad, 0x400004c0,
0x40003200, 0x4000d800, 0x220000a6, 0x40009a00,
0x220000a6, 0xd0160200, 0x40004400, 0x220000b6,
0x40000580, 0x20000271, 0xd8039a00, 0x40004400,
0x2200007c, 0x40000200, 0xd0039a40, 0x40004c00,
0x220000b6, 0x220000a6, 0x40000440, 0x40000200,
0x42000400, 0x220000b6, 0xd0004400, 0x220000b6,
0x40000580, 0x40001a00, 0x40005800, 0x220000a6,
0x400005c0, 0x4000b000, 0x220000ad, 0x40000380,
0x4000a000, 0x4000ba00, 0x220000a6, 0x400003c0,
0x4000a000, 0x220000ad, 0x40000700, 0x42007c00,
0x220000b6, 0x40000740, 0x42000400, 0x220000b6,
0x400003c0, 0x40007000, 0xd8007c00, 0x2200007c,
0x4000a200, 0x220000a6, 0x40000400, 0x40008100,
0xd00fec00, 0x220000b6, 0xd8007400, 0x2200007c,
0x4000b200, 0x220000a6, 0x400003c0, 0x40005800,
0x220000ad, 0x4000e200, 0x220000a6, 0x42000400,
0x220000b6, 0xd80f0400, 0x2200007c, 0x40000300,
0x4000a000, 0x4000e200, 0x220000a6, 0x40000500,
0x24000000, 0x40001200, 0x40004000, 0x220002aa,
0x40000200, 0x40004080, 0x40005000, 0x220002aa,
0x40000280, 0x24000000, 0x40009200, 0x220000a6,
0x24000000, 0x44000000, 0x08800001, 0x6a800000,
0x43000200, 0xd8080400, 0x2200007c, 0x40000200,
0xd9083000, 0x310002b7, 0x49e00000, 0x24000000,
0x40001dc0, 0xd902b800, 0x310002bd, 0x400055c0,
0xd90bb800, 0x24000000, 0x40001dc0, 0xd902b800,
0x310002c4, 0x40005800, 0xd00a0400, 0x220000b5,
0x24000000, 0x40009800, 0x44000400, 0x08c00000,
0x2200003b, 0x40008000, 0x400004c0, 0x24000000,
0x44000000, 0xd91f0000, 0x330002d2, 0x43000000,
0xd91f0000, 0x330002d2, 0x24000000, 0x220002cc,
0x330002d7, 0x24000000, 0x00000043, 0x00000042,
0x00000041, 0x220002db, 0x00000000, 0x22000338,
0x49800000, 0x220002b8, 0x330002d6, 0x220002be,
0x330002d6, 0x44000480, 0x440004c0, 0x43000100,
0x43000300, 0x43000500, 0x220001b9, 0x220001c7,
0xe007fbc0, 0x330002ec, 0x220001d5, 0x33c002d6,
0x40001700, 0x40001f40, 0x40002680, 0x18000000,
0x4000e000, 0x40005040, 0x40009080, 0x4000e8c0,
0x40005900, 0x40009940, 0x40006180, 0x4000a1c0,
0x19000000, 0x50c03800, 0x50e0f800, 0x159b8000,
0x33400306, 0x3300030e, 0x40001700, 0x4000e100,
0x40005700, 0x4000e300, 0x40009700, 0x4000e500,
0x16980000, 0x2000030f, 0x40001f00, 0x4000e100,
0x40005f00, 0x4000e300, 0x40009f00, 0x4000e500,
0x169c0000, 0x2000030f, 0x16980000, 0x11800000,
0x2200019b, 0x22000244, 0x2200019b, 0x68803800,
0x33600318, 0x6880f800, 0x33600321, 0x2000032e,
0x6880f800, 0x33600328, 0x18000000, 0x40000700,
0x40000a80, 0x40001480, 0x19000000, 0x4000e080,
0x2000032f, 0x18000000, 0x40001f00, 0x40002280,
0x40002c80, 0x19000000, 0x4000e080, 0x2000032f,
0x4000d080, 0x18000000, 0x40003280, 0x40003c80,
0x19000000, 0x2000032f, 0x20000331, 0x220001d5,
0x33c002d6, 0x28800310, 0x2200019b, 0x220001a9,
0x220002c5, 0x220001ae, 0x2200018f, 0x24000000,
0x220002d3, 0x4000fa00, 0x40003fc0, 0x220002d3,
0x400047c0, 0x24000000};
  
static unsigned hal_ecc_base_radix(unsigned size)
{
   if (size <= 16)  return 0; /* Error */
   if (size <= 32)  return 2;
   if (size <= 64)  return 3;

   return 0;
}

static unsigned hal_ecc_page_size(unsigned size)
{
   unsigned ret;

   ret = hal_ecc_base_radix(size);
   if (!ret)
      return ret;
   return 8 << ret;
}

static void hal_ecc_load_operand(uint16_t size, uint32_t base, const uint8_t *data)
{
	unsigned i, n;
	uint32_t tmp;

	n = size >> 2;

	if (!data) {
		for (i = 0; i < n; i++) {
			WR_WORD((base + i*4), 0);
		}
		return;
	}

	for (i = 0; i < n; i++) {
		memcpy(&tmp, data + ((n-i-1)<<2) + (size&3), 4);  
		tmp = __REV(tmp);
		WR_WORD((base + i*4), tmp);
	}		

	/* Write the incomplete word, if any. */
	if (size & 3) {
		tmp = 0;
		memcpy((char *)&tmp + sizeof tmp - (size&3), data, size & 3);
		tmp = __REV(tmp);
		WR_WORD((base + i*4), tmp);
		i++;
	}

   /* Zero the remainder of the operand. */
   for (n = hal_ecc_page_size(size) >> 2; i < n; i++) {
		WR_WORD((base + i*4), 0);
   }

   return;
}
 
static void ecc_unload_operand(uint16_t size, uint32_t base, uint8_t *data)
{
	unsigned i, n;
	uint32_t tmp;

   n = size >> 2;

   for (i = 0; i < n; i++) {
      	tmp = RD_WORD((base + i*4));
		tmp = __REV(tmp);
      	memcpy(data+((n-i-1)<<2)+(size&3), &tmp, 4);
   }

   if (size & 3) {
      tmp = RD_WORD((base + i*4));
		tmp = __REV(tmp);
      memcpy(data, (char *)&tmp + sizeof tmp - (size&3), size & 3);
   }

   return;
}

typedef struct {
	int used;
	osMutexId mutex;
	osSemaphoreId semaphore; 
	/// Power 
#if CFG_PM_EN
	int power_state;
	struct pm_module pm;
#endif
} ecc_dev_t;

static ecc_dev_t ecc_dev;

osMutexDef(ecc_mutex);
osSemaphoreDef(ecc_semaphore);

#if CFG_PM_EN
static int ecc_power_state(void *arg, uint32_t *sleep_duration)
{
	ecc_dev_t *pd = (ecc_dev_t *)arg;
	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->power_state;
}

static void ecc_power_down(void *arg, uint32_t sleep_duration)
{
	/// TODO
}
static void ecc_power_up(void *arg)
{
	//ecc_dev_t *pd = (ecc_dev_t *)arg;
	hal_ecc_init();

	/// TODO: pin mux, etc...
}
#endif	/* CFG_PM_EN */


static void ecc_isr(ecc_dev_t *pd)
{
	ecc_stat_ack_irq();
	osSemaphoreRelease(pd->semaphore);
}

__irq void Ecc_Handler(void)
{
	ecc_isr(&ecc_dev);
}

static void ecc_download_fw(void)
{
	int i = 0; 
	uint32_t base = ECC_FW_BASE;

	//printf("FW SIZE = %d\r\n", sizeof(ecc_fw));

	for (i = 0; i < sizeof(ecc_fw)/4; i++) {
		WR_WORD(base, ecc_fw[i]);
		base += 4;		
	}

	return;
}

static void hal_ecc_init(void)
{
	int i;

	/// download firmware
	ecc_download_fw();

	/// Clear operand memory
	uint32_t base = ECC_A0_BASE;

	for (i = 0; i < (0x400/4) ; i++) {
		WR_WORD(base, 0);
		base += 4;
	}

	base = ECC_B0_BASE;
	for (i = 0; i < (0x400/4) ; i++) {
		WR_WORD(base, 0);
		base += 4;
	}

	base = ECC_C0_BASE;
	for (i = 0; i < (0x400/4) ; i++) {
		WR_WORD(base, 0);
		base += 4;
	}

	base = ECC_D0_BASE;
	for (i = 0; i < (0x400/4) ; i++) {
		WR_WORD(base, 0);
		base += 4;
	}

}

int hal_ecc_is_open(void) 
{
	ecc_dev_t* pd = &ecc_dev;

	return pd->used;
}

int hal_ecc_open() 
{
	hal_ecc_init();
	ecc_dev_t* pd = &ecc_dev;

	if(!pd)
		return ECC_ERR_DEV_BAD_STATE;

	if(pd->used)
		return ECC_ERR_ALREADY_INIT;

#if CFG_AES_EN
	if (hal_aes_is_open())
		return ECC_ERR_HW_MEM_USED_BY_AES;
#endif

	pd->mutex = osMutexCreate(osMutex(ecc_mutex));
	if (!pd->mutex)
		goto fail;
	pd->semaphore = osSemaphoreCreate(osSemaphore(ecc_semaphore), 0);
	if (!pd->semaphore)
		goto fail;

#if CFG_PM_EN
	pd->pm.power_state = ecc_power_state;
	pd->pm.power_down = ecc_power_down;
	pd->pm.power_up = ecc_power_up;
	pd->pm.arg = (void *)pd; 
	hal_pm_reg_mod(&pd->pm);
	pd->power_state = PM_DEEP_SLEEP;
#endif

	ecc_mem_en(1);

	hal_clk_ecc_en(1)	;

	pd->used = 1;

	return ECC_ERR_OK;

fail:
	if (pd->mutex) {
		osMutexDelete(pd->mutex);
		pd->mutex = NULL;
	}
	if (pd->semaphore) {
		osSemaphoreDelete(pd->semaphore);	
		pd->semaphore = NULL;
	}
	return ECC_ERR_DEV_BAD_STATE;
}

int hal_ecc_close(void) 
{
	ecc_dev_t *pd = &ecc_dev;

	if (!pd)
		return ECC_ERR_DEV_BAD_STATE;	
	if(!pd->used)
		return ECC_ERR_NOT_INIT;
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
	
	hal_clk_ecc_en(0);

	return ECC_ERR_OK;	
}

static int ecc_start(uint16_t size, int fun_idx)
{
	ecc_dev_t *pd = &ecc_dev;
	unsigned radix;
	int err = ECC_ERR_OK;

	radix = hal_ecc_base_radix(size);

	/* Clear flag */
	ecc_flag_clear();

	/* Clear stack */
	ecc_stack_clear();

	/* Endian Swap */
	//HAL_ecc_config_endian_swap(ECC);

	/* Entry point */
	ecc_entry_addr(fun_idx);

	/* Disable interrupt */
	//ecc_irq_disable();

	/* Base radix */
	ecc_base_radix(radix);

	/* partial radix */
	ecc_partial_radix(((size & (size - 1)) ? (size+3)/4 : 0));

	/* Go */
	ecc_go();

#if CFG_PM_EN
	pd->power_state = PM_SLEEP;
#endif

	/// Unmask Interrupt	
	ecc_irq_enable();
	NVIC_SetPriority(Ecc_IRQn, IRQ_PRI_Normal);	
	NVIC_EnableIRQ(Ecc_IRQn);
		
	/// Wait for write complete
	osSemaphoreWait(pd->semaphore, osWaitForever);

	/// Re-mask Interrupt	
	ecc_irq_disable();
	NVIC_DisableIRQ(Ecc_IRQn);

	/* Poll STAT */
	//while (!(ecc_stat() & ECC_STAT_DONE));
#if CFG_PM_EN
	pd->power_state = PM_DEEP_SLEEP;
#endif

	/* Ack */
	//ecc_stat_ack_irq();

	/* REASON */
	if (ecc_rtn_reason() != ECC_RTN_REASON_NORMAL_STOP) {
		err = ECC_ERR_NON_NORMAL_STOP;
	}

	return err;
}

int hal_ecc_r_inv_mod_m(uint16_t size, const uint8_t *m, uint8_t *r_inv)
{
	uint32_t base;
	int err = ECC_ERR_OK;
	ecc_dev_t *pd = &ecc_dev;

	if (hal_ecc_base_radix(size) == 0)
		return ECC_ERR_INVALID_PARA;

	osMutexWait(pd->mutex, osWaitForever);

	/// m ==> D0	
	base = ECC_D0_BASE;
	hal_ecc_load_operand(size, base, m);

	err = ecc_start(size, ECC_FW_ENTRY_CALC_R_INV);

	if (err != ECC_ERR_OK)
		goto out;

	/// C0 ==> r_inv
	base = ECC_C0_BASE;
	ecc_unload_operand(size, base, r_inv);

out:
	osMutexRelease(pd->mutex);
	return err;
}

int hal_ecc_m_prime(uint16_t size, const uint8_t *r_inv, const uint8_t *m, uint8_t *mp)
{
	uint32_t base, radix, offset;
	int err = ECC_ERR_OK;
	ecc_dev_t *pd = &ecc_dev;

	if ((radix = hal_ecc_base_radix(size)) == 0)
		return ECC_ERR_INVALID_PARA;

	if (radix == 2)
		offset = 0x20;
	else 
		offset = 0x40;

	osMutexWait(pd->mutex, osWaitForever);

	/// r_inv ==> C0	
	base = ECC_C0_BASE;
	hal_ecc_load_operand(size, base, r_inv);

	/// m ==> D0	
	base = ECC_D0_BASE;
	hal_ecc_load_operand(size, base, m);

	err = ecc_start(size, ECC_FW_ENTRY_CALC_MP);

	if (err != ECC_ERR_OK)
		goto out;

	/// D1 ==> mp
	base = ECC_D0_BASE + offset;
	ecc_unload_operand(size, base, mp);

out:
	osMutexRelease(pd->mutex);
	return err;
}

int hal_ecc_r_sqr_mod_m(uint16_t size, const uint8_t *r_inv, const uint8_t *m, uint8_t *r_sqr)
{
	uint32_t base, radix, offset;
	int err = ECC_ERR_OK;
	ecc_dev_t *pd = &ecc_dev;

	if ((radix = hal_ecc_base_radix(size)) == 0)
		return ECC_ERR_INVALID_PARA;

	if (radix == 2)
		offset = 0x20;
	else 
		offset = 0x40;
	
	osMutexWait(pd->mutex, osWaitForever);

	/// r_inv ==> C0	
	base = ECC_C0_BASE;
	hal_ecc_load_operand(size, base, r_inv);

	/// m ==> D0	
	base = ECC_D0_BASE;
	hal_ecc_load_operand(size, base, m);

	err = ecc_start(size, ECC_FW_ENTRY_CALC_R_SQR);

	if (err != ECC_ERR_OK)
		goto out;

	/// D3 ==> r_sqr
	base = ECC_D0_BASE + (3 * offset);
	ecc_unload_operand(size, base, r_sqr);

out:
	osMutexRelease(pd->mutex);
	return err;
}

int hal_ecc_mod_mult(uint16_t size, const uint8_t *x, const uint8_t *y, const uint8_t *m, const uint8_t *mp, const uint8_t *r_sqr, uint8_t *c)
{
	uint32_t base, radix, offset;
	int err = ECC_ERR_OK;
	ecc_dev_t *pd = &ecc_dev;

	if ((radix = hal_ecc_base_radix(size)) == 0)
		return ECC_ERR_INVALID_PARA;

	if (radix == 2)
		offset = 0x20;
	else 
		offset = 0x40;

	osMutexWait(pd->mutex, osWaitForever);

	/// x ==> A0	
	base = ECC_A0_BASE;
	hal_ecc_load_operand(size, base, x);
	
	/// y ==> B0	
	base = ECC_B0_BASE;
	hal_ecc_load_operand(size, base, y);

	/// m ==> D0	
	base = ECC_D0_BASE;
	hal_ecc_load_operand(size, base, m);

	/// mp ==> D1	
	base = ECC_D0_BASE + offset;
	hal_ecc_load_operand(size, base, mp);

	/// r_sqr ==> D3	
	base = ECC_D0_BASE + (3 * offset);
	hal_ecc_load_operand(size, base, r_sqr);

	err = ecc_start(size, ECC_FW_ENTRY_MODMULT);

	if (err != ECC_ERR_OK)
		goto out;

	/// A0 ==> c
	base = ECC_A0_BASE;
	ecc_unload_operand(size, base, c);

out:
	osMutexRelease(pd->mutex);
	return err;
}

int hal_ecc_mod_add(uint16_t size, const uint8_t *x, const uint8_t *y, const uint8_t *m, uint8_t *c)
{
	uint32_t base;
	int err = ECC_ERR_OK;
	ecc_dev_t *pd = &ecc_dev;

	if (hal_ecc_base_radix(size) == 0)
		return ECC_ERR_INVALID_PARA;

	osMutexWait(pd->mutex, osWaitForever);

	/// x ==> A0	
	base = ECC_A0_BASE;
	hal_ecc_load_operand(size, base, x);
	
	/// y ==> B0	
	base = ECC_B0_BASE;
	hal_ecc_load_operand(size, base, y);

	/// m ==> D0	
	base = ECC_D0_BASE;
	hal_ecc_load_operand(size, base, m);

	err = ecc_start(size, ECC_FW_ENTRY_MODADD);

	if (err != ECC_ERR_OK)
		goto out;

	/// A0 ==> c
	base = ECC_A0_BASE;
	ecc_unload_operand(size, base, c);

out:
	osMutexRelease(pd->mutex);
	return err;
}

int hal_ecc_mod_sub(uint16_t size, const uint8_t *x, const uint8_t *y, const uint8_t *m, uint8_t *c)
{
	uint32_t base;
	int err = ECC_ERR_OK;
	ecc_dev_t *pd = &ecc_dev;

	if (hal_ecc_base_radix(size) == 0)
		return ECC_ERR_INVALID_PARA;

	osMutexWait(pd->mutex, osWaitForever);

	/// x ==> A0	
	base = ECC_A0_BASE;
	hal_ecc_load_operand(size, base, x);
	
	/// y ==> B0	
	base = ECC_B0_BASE;
	hal_ecc_load_operand(size, base, y);

	/// m ==> D0	
	base = ECC_D0_BASE;
	hal_ecc_load_operand(size, base, m);

	err = ecc_start(size, ECC_FW_ENTRY_MODSUB);

	if (err != ECC_ERR_OK)
		goto out;

	/// A0 ==> c
	base = ECC_A0_BASE;
	ecc_unload_operand(size, base, c);

out:
	osMutexRelease(pd->mutex);
	return err;
}


int hal_ecc_mod_div(uint16_t size, const uint8_t *y, const uint8_t *x, const uint8_t *m, uint8_t *c)
{
	uint32_t base;
	int err = ECC_ERR_OK;
	ecc_dev_t *pd = &ecc_dev;

	if (hal_ecc_base_radix(size) == 0)
		return ECC_ERR_INVALID_PARA;

	osMutexWait(pd->mutex, osWaitForever);

	/// y ==> C0
	base = ECC_C0_BASE;
	hal_ecc_load_operand(size, base, y);
	
	/// x ==> A0	
	base = ECC_A0_BASE;
	hal_ecc_load_operand(size, base, x);

	/// m ==> D0	
	base = ECC_D0_BASE;
	hal_ecc_load_operand(size, base, m);

	err = ecc_start(size, ECC_FW_ENTRY_MODDIV);

	if (err != ECC_ERR_OK)
		goto out;

	/// C0 ==> c
	base = ECC_C0_BASE;
	ecc_unload_operand(size, base, c);

out:
	osMutexRelease(pd->mutex);
	return err;
}

int hal_ecc_mod_inv(uint16_t size, const uint8_t *x, const uint8_t *m, uint8_t *c)
{
	uint32_t base;
	int err = ECC_ERR_OK;
	ecc_dev_t *pd = &ecc_dev;

	if (hal_ecc_base_radix(size) == 0)
		return ECC_ERR_INVALID_PARA;

	osMutexWait(pd->mutex, osWaitForever);

	/// x ==> A0	
	base = ECC_A0_BASE;
	hal_ecc_load_operand(size, base, x);

	/// m ==> D0	
	base = ECC_D0_BASE;
	hal_ecc_load_operand(size, base, m);

	err = ecc_start(size, ECC_FW_ENTRY_MODINV);

	if (err != ECC_ERR_OK)
		goto out;

	/// C0 ==> c
	base = ECC_C0_BASE;
	ecc_unload_operand(size, base, c);

out:
	osMutexRelease(pd->mutex);
	return err;
}

int hal_ecc_pmult(uint16_t size, const uint8_t *Px, const uint8_t *Py, const uint8_t *a, const uint8_t *w, const uint8_t *p, const uint8_t *mp, const uint8_t *r_sqr, const uint8_t *k, uint8_t *Rx, uint8_t *Ry)
{
	uint32_t base, radix, offset;
	int err = ECC_ERR_OK;
	ecc_dev_t *pd = &ecc_dev;

	if ((radix = hal_ecc_base_radix(size)) == 0)
		return ECC_ERR_INVALID_PARA;

	if (radix == 2)
		offset = 0x20;
	else 
		offset = 0x40;

	osMutexWait(pd->mutex, osWaitForever);

	/// Px ==>A2
	base = ECC_A0_BASE + (2 * offset);
	hal_ecc_load_operand(size, base, Px);
	
	/// Py ==> B2	
	base = ECC_B0_BASE + (2 * offset);
	hal_ecc_load_operand(size, base, Py);

	/// a ==> A6	
	base = ECC_A0_BASE + (6 * offset);
	hal_ecc_load_operand(size, base, a);

	/// k ==> D7	
	base = ECC_D0_BASE + (7 * offset);
	hal_ecc_load_operand(size, base, k);

	/// w ==> A7
	base = ECC_A0_BASE + (7 * offset);
	hal_ecc_load_operand(size, base, w);

	/// p ==> D0
	base = ECC_D0_BASE;
	hal_ecc_load_operand(size, base, p);

	/// p' ==> D1
	base = ECC_D0_BASE + offset;
	hal_ecc_load_operand(size, base, mp);

	/// r^2 mod p ==> D3
	base = ECC_D0_BASE + (3 * offset);
	hal_ecc_load_operand(size, base, r_sqr);

	err = ecc_start(size, ECC_FW_ENTRY_PMULT);

	if (err != ECC_ERR_OK)
		goto out;

	/// A2 ==> Rx
	base = ECC_A0_BASE + (2 * offset);
	ecc_unload_operand(size, base, Rx);

	/// B2 ==> Ry
	base = ECC_B0_BASE + (2 * offset);
	ecc_unload_operand(size, base, Ry);

out:
	osMutexRelease(pd->mutex);
	return err;
}

int hal_ecc_padd(uint16_t size, const uint8_t *Px, const uint8_t *Py, const uint8_t *Qx, const uint8_t *Qy, const uint8_t *a, const uint8_t *p, const uint8_t *mp, const uint8_t *r_sqr, uint8_t *Rx, uint8_t *Ry)
{
	uint32_t base, radix, offset;
	int err = ECC_ERR_OK;
	ecc_dev_t *pd = &ecc_dev;

	if ((radix = hal_ecc_base_radix(size)) == 0)
		return ECC_ERR_INVALID_PARA;

	if (radix == 2)
		offset = 0x20;
	else 
		offset = 0x40;

	osMutexWait(pd->mutex, osWaitForever);

	/// Px ==>A2
	base = ECC_A0_BASE + (2 * offset);
	hal_ecc_load_operand(size, base, Px);
	
	/// Py ==> B2	
	base = ECC_B0_BASE + (2 * offset);
	hal_ecc_load_operand(size, base, Py);

	/// Qx ==>A3
	base = ECC_A0_BASE + (3 * offset);
	hal_ecc_load_operand(size, base, Qx);
	
	/// Qy ==> B3	
	base = ECC_B0_BASE + (3 * offset);
	hal_ecc_load_operand(size, base, Qy);

	/// a ==> A6	
	base = ECC_A0_BASE + (6 * offset);
	hal_ecc_load_operand(size, base, a);

	/// p ==> D0
	base = ECC_D0_BASE;
	hal_ecc_load_operand(size, base, p);

	/// p' ==> D1
	base = ECC_D0_BASE + offset;
	hal_ecc_load_operand(size, base, mp);

	/// r^2 mod p ==> D3
	base = ECC_D0_BASE + (3 * offset);
	hal_ecc_load_operand(size, base, r_sqr);

	err = ecc_start(size, ECC_FW_ENTRY_PADD);

	if (err != ECC_ERR_OK)
		goto out;

	/// A2 ==> Rx
	base = ECC_A0_BASE + (2 * offset);
	ecc_unload_operand(size, base, Rx);

	/// B2 ==> Ry
	base = ECC_B0_BASE + (2 * offset);
	ecc_unload_operand(size, base, Ry);

out:
	osMutexRelease(pd->mutex);
	return err;
}


int hal_ecc_pdbl(uint16_t size, const uint8_t *Px, const uint8_t *Py, const uint8_t *a, const uint8_t *p, const uint8_t *mp, const uint8_t *r_sqr, uint8_t *Rx, uint8_t *Ry)
{
	uint32_t base, radix, offset;
	int err = ECC_ERR_OK;
	ecc_dev_t *pd = &ecc_dev;

	if ((radix = hal_ecc_base_radix(size)) == 0)
		return ECC_ERR_INVALID_PARA;

	if (radix == 2)
		offset = 0x20;
	else 
		offset = 0x40;

	osMutexWait(pd->mutex, osWaitForever);

	/// Px ==>A3
	base = ECC_A0_BASE + (3 * offset);
	hal_ecc_load_operand(size, base, Px);
	
	/// Py ==> B3	
	base = ECC_B0_BASE + (3 * offset);
	hal_ecc_load_operand(size, base, Py);

	/// a ==> A6	
	base = ECC_A0_BASE + (6 * offset);
	hal_ecc_load_operand(size, base, a);

	/// p ==> D0
	base = ECC_D0_BASE;
	hal_ecc_load_operand(size, base, p);

	/// p' ==> D1
	base = ECC_D0_BASE + offset;
	hal_ecc_load_operand(size, base, mp);

	/// r^2 mod p ==> D3
	base = ECC_D0_BASE + (3 * offset);
	hal_ecc_load_operand(size, base, r_sqr);

	err = ecc_start(size, ECC_FW_ENTRY_PDBL);

	if (err != ECC_ERR_OK)
		goto out;

	/// A2 ==> Rx
	base = ECC_A0_BASE + (2 * offset);
	ecc_unload_operand(size, base, Rx);

	/// B2 ==> Ry
	base = ECC_B0_BASE + (2 * offset);
	ecc_unload_operand(size, base, Ry);

out:
	osMutexRelease(pd->mutex);
	return err;
}

int hal_ecc_pver(uint16_t size, const uint8_t *Px, const uint8_t *Py, const uint8_t *a, const uint8_t *b, const uint8_t *p, const uint8_t *mp, const uint8_t *r_sqr)
{
	uint32_t base, radix, offset;
	int err = ECC_ERR_OK;
	ecc_dev_t *pd = &ecc_dev;

	if ((radix = hal_ecc_base_radix(size)) == 0)
		return ECC_ERR_INVALID_PARA;

	if (radix == 2)
		offset = 0x20;
	else 
		offset = 0x40;

	osMutexWait(pd->mutex, osWaitForever);

	/// Px ==>A2
	base = ECC_A0_BASE + (2 * offset);
	hal_ecc_load_operand(size, base, Px);
	
	/// Py ==> B2	
	base = ECC_B0_BASE + (2 * offset);
	hal_ecc_load_operand(size, base, Py);

	/// a ==> A6	
	base = ECC_A0_BASE + (6 * offset);
	hal_ecc_load_operand(size, base, a);

	/// b ==> A7	
	base = ECC_A0_BASE + (7 * offset);
	hal_ecc_load_operand(size, base, b);

	/// p ==> D0
	base = ECC_D0_BASE;
	hal_ecc_load_operand(size, base, p);

	/// p' ==> D1
	base = ECC_D0_BASE + offset;
	hal_ecc_load_operand(size, base, mp);

	/// r^2 mod p ==> D3
	base = ECC_D0_BASE + (3 * offset);
	hal_ecc_load_operand(size, base, r_sqr);

	err = ecc_start(size, ECC_FW_ENTRY_PVER);

	if (err != ECC_ERR_OK)
		goto out;

	/* ZERO */
	if (!ecc_rtn_zero())  {
		err = ECC_ERR_INVALID_POINT;
	}

out:
	osMutexRelease(pd->mutex);
	return err;
}

int hal_ecc_shamir(uint16_t size, const uint8_t *Px, const uint8_t *Py, const uint8_t *Qx, const uint8_t *Qy, const uint8_t *a, const uint8_t *k, const uint8_t *l, 
												const uint8_t *p, const uint8_t *mp, const uint8_t *r_sqr, uint8_t *Rx, uint8_t *Ry)
{
	uint32_t base, radix, offset;
	int err = ECC_ERR_OK;
	ecc_dev_t *pd = &ecc_dev;

	if ((radix = hal_ecc_base_radix(size)) == 0)
		return ECC_ERR_INVALID_PARA;

	if (radix == 2)
		offset = 0x20;
	else 
		offset = 0x40;

	osMutexWait(pd->mutex, osWaitForever);

	/// Px ==>A2
	base = ECC_A0_BASE + (2 * offset);
	hal_ecc_load_operand(size, base, Px);
	
	/// Py ==> B2	
	base = ECC_B0_BASE + (2 * offset);
	hal_ecc_load_operand(size, base, Py);

	/// Qx ==>A3
	base = ECC_A0_BASE + (3 * offset);
	hal_ecc_load_operand(size, base, Qx);
	
	/// Qy ==> B3	
	base = ECC_B0_BASE + (3 * offset);
	hal_ecc_load_operand(size, base, Qy);

	/// a ==> A6	
	base = ECC_A0_BASE + (6 * offset);
	hal_ecc_load_operand(size, base, a);

	/// k ==> A7	
	base = ECC_A0_BASE + (7 * offset);
	hal_ecc_load_operand(size, base, k);

	/// l ==> D7	
	base = ECC_D0_BASE + (7 * offset);
	hal_ecc_load_operand(size, base, l);

	/// p ==> D0
	base = ECC_D0_BASE;
	hal_ecc_load_operand(size, base, p);

	/// p' ==> D1
	base = ECC_D0_BASE + offset;
	hal_ecc_load_operand(size, base, mp);

	/// r^2 mod p ==> D3
	base = ECC_D0_BASE + (3 * offset);
	hal_ecc_load_operand(size, base, r_sqr);

	err = ecc_start(size, ECC_FW_ENTRY_SHAMIR);

	if (err != ECC_ERR_OK)
		goto out;

	/// A2 ==> Rx
	base = ECC_A0_BASE + (2 * offset);
	ecc_unload_operand(size, base, Rx);

	/// B2 ==> Ry
	base = ECC_B0_BASE + (2 * offset);
	ecc_unload_operand(size, base, Ry);

out:
	osMutexRelease(pd->mutex);
	return err;
}
#endif 	// CFG_ECC_EN
