/**
 ****************************************************************************************
 *
 * @file system_inxxx.c
 *
 * @brief ARM system initialization  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 *
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup HAL
 * @{
 ****************************************************************************************
 */
#include "in_config.h"

#include "stdint.h"
#include "stdio.h"

#include "in_arm.h"
#include ".\hal\hal_global.h"

#if CFG_FPGA
extern void adi_tuner_start(void);
#endif

/*----------------------------------------------------------------------------
  System Core Clock Variable
 *----------------------------------------------------------------------------*/
void SystemInit (void)
{
#if (__FPU_USED == 1)
	SCB->CPACR |= ((3UL << 10*2) |                 /* set CP10 Full Access */
	               (3UL << 11*2)  );               /* set CP11 Full Access */
#endif

#ifdef UNALIGNED_SUPPORT_DISABLE
	SCB->CCR |= SCB_CCR_UNALIGN_TRP_Msk;
#endif

#if CFG_FPGA
	SCB->VTOR = CFG_BRAM_COLD_BOOT_ADDR & SCB_VTOR_TBLOFF_Msk; 
	adi_tuner_start();
#else
	hal_global_pre_init();
#endif

}
/// @} HAL

