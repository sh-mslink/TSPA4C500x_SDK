/**
 ****************************************************************************************
 *
 * @file in_arm.h
 *
 * @brief Tropos CPU configuration
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 *
 ****************************************************************************************
 */

#ifndef IN_ARM_H
#define IN_ARM_H

/* --------  Configuration of the Cortex-M4 Processor and Core Peripherals  ------- */
#define __CM4_REV                 		0x0001U   	/* Core revision r0p1 */
#define __MPU_PRESENT             	0         		/* MPU present */
#define __VTOR_PRESENT            	1         		/* VTOR present */
#define __NVIC_PRIO_BITS          	3         		/* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    	0         		/* Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             	1         		/* FPU present */

#include "in_irq.h"
#include "core_cm4.h"                       				/* Processor and core peripherals */

#endif
