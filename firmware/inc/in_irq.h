/**
 ****************************************************************************************
 *
 * @file in_irq.h
 *
 * @brief Tropos chipset IRQ number
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 *
 ****************************************************************************************
 */
#ifndef IN_IRQ_H
#define IN_IRQ_H

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */
typedef enum IRQn
{
	/* -------------------  Cortex-M4 Processor Exceptions Numbers  ------------------- */
	NonMaskableInt_IRQn           	= -14,      /*  2 Non Maskable Interrupt */
	HardFault_IRQn                		= -13,      /*  3 HardFault Interrupt */
	MemoryManagement_IRQn      = -12,      /*  4 Memory Management Interrupt */
	BusFault_IRQn                 		= -11,      /*  5 Bus Fault Interrupt */
	UsageFault_IRQn               		= -10,      /*  6 Usage Fault Interrupt */
	SVCall_IRQn                   		=  -5,      /* 11 SV Call Interrupt */
	DebugMonitor_IRQn            	=  -4,      /* 12 Debug Monitor Interrupt */
	PendSV_IRQn                   		=  -2,      /* 14 Pend SV Interrupt */
	SysTick_IRQn                  		=  -1,      /* 15 System Tick Interrupt */

	/* ----------------------  TSPA4C500A Specific Interrupt Numbers  --------------------- */
	Dma0_IRQn 								= 0,
	Dma1_IRQn 								= 1,
	Keyboard_IRQn							= 2,
	Hash_IRQn								= 3,
	Aes_IRQn									= 4,
	Hwacc_IRQn								= 5,
	Uart0_IRQn								= 14,
	Uart1_IRQn								= 15,
	Spi0_IRQn								= 16,
	MSpi_IRQn								= 17,
	Efuse_IRQn								= 18,
	SSpi_IRQn									= 19,
	I2c0_IRQn								= 20,
	I2c1_IRQn								= 21,
	I2sm_IRQn								= 22,
	I2ss_IRQn									= 23,
	Ecc_IRQn									= 24,
	Tim1_IROn 								= 26,
	Tim2_IROn 								= 27,
	Sadc_IRQn								= 35,
	Calib_IRQn								= 36,
	Pwm0_IRQn 								= 37,
	Pwm1_IRQn								= 38,
	Pwm2_IRQn 								= 39,
	Pwm3_IRQn								= 40,
	Pwm4_IRQn 								= 41,
	Quad_IRQn								= 42,
	Counter_IRQn							= 43,
	Wdt_IRQn									= 44,
	Audio_IRQn								= 45,
	Ble_IRQn 									= 49,
	ICache_IRQn							= 50,
	BOD_IRQn								= 62,
	XO_IRQn									= 63,
	Spiflash_IRQn							= 65,
	Global_IRQn								= 66,
	Gpio0_IRQn								= 67,
	Gpio1_IRQn								= 68,
	Gpio2_IRQn								= 69,
	Gpio3_IRQn								= 70,
	Gpio4_IRQn								= 71,
} IRQn_Type;

/*
 * ==========================================================================
 * ---------- Interrupt Priorityr Definition --------------------------------
 * ==========================================================================
 */
#define IRQ_PRI_RealTime 0
#define IRQ_PRI_Highest 1
#define IRQ_PRI_High 2
#define IRQ_PRI_AboveNormal 3
#define IRQ_PRI_Normal 4
#define IRQ_PRI_BelowNormal 5
#define IRQ_PRI_Low 6
#define IRQ_PRI_Lowest 7

#endif
