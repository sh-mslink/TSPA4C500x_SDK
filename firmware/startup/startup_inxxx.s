;/**************************************************************************//**
; * @file     startup_ARMCM4.s
; * @brief    CMSIS Core Device Startup File for
; *           ARMCM4 Device Series
; * @version  V1.08
; * @date     23. November 2012
; *
; * @note
; *
; ******************************************************************************/
;/* Copyright (c) 2011 - 2012 ARM LIMITED
;
;   All rights reserved.
;   Redistribution and use in source and binary forms, with or without
;   modification, are permitted provided that the following conditions are met:
;   - Redistributions of source code must retain the above copyright
;     notice, this list of conditions and the following disclaimer.
;   - Redistributions in binary form must reproduce the above copyright
;     notice, this list of conditions and the following disclaimer in the
;     documentation and/or other materials provided with the distribution.
;   - Neither the name of ARM nor the names of its contributors may be used
;     to endorse or promote products derived from this software without
;     specific prior written permission.
;   *
;   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
;   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
;   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
;   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
;   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
;   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
;   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
;   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
;   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
;   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
;   POSSIBILITY OF SUCH DAMAGE.
;   ---------------------------------------------------------------------------*/
;/*
;//-------- <<< Use Configuration file >>> ------------------
;*/
#define SCT_ASM_FILES
#include "..\inc\in_config.h"

; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

;Stack_Size      EQU     0x00000400
Stack_Size      EQU     CFG_STACK_SIZE

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

;Heap_Size       EQU     0x00000C00
Heap_Size       EQU     CFG_HEAP_SIZE

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB

; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              	; Top of Stack
                DCD     Reset_Handler             	; Reset Handler
                DCD     NMI_Handler               	; NMI Handler
                DCD     HardFault_Handler         	; Hard Fault Handler
                DCD     MemManage_Handler        ; MPU Fault Handler
                DCD     BusFault_Handler          	; Bus Fault Handler
                DCD     UsageFault_Handler        	; Usage Fault Handler
                DCD     0                         		; Reserved
                DCD     0                         		; Reserved
                DCD     0                        		; Reserved
                DCD     0                         		; Reserved
                DCD     SVC_Handler               	; SVCall Handler
                DCD     DebugMon_Handler          ; Debug Monitor Handler
                DCD     0                         		; Reserved
                DCD     PendSV_Handler            	; PendSV Handler
                DCD     SysTick_Handler           	; SysTick Handler

                ; External Interrupts
                DCD     DMA0_Handler 			;  0:  DMA0
                DCD     DMA1_Handler 			;  1:  DMA1
                DCD     KB_Handler 			;  2:  Keyboard
                DCD     Hash_Handler 			;  3:  Hash
                DCD     Aes_Handler 			;  4:  Aes
                DCD     Hwacc_Handler 			;  5:  HW Math Accel.
                DCD     Null_Handler 			;  6:  
                DCD     Null_Handler			;  7:  
                DCD     Null_Handler 			;  8:  
                DCD     Null_Handler 			;  9:  
                DCD     Null_Handler 			;  10:  
                DCD     Null_Handler			;  11:  
                DCD     Null_Handler			;  12:  
                DCD     Null_Handler			;  13:  
                DCD     UART0_Handler			;  14:  UART0
                DCD     UART1_Handler			;  15:  UART1
                DCD     SPI0_Handler 			;  16:  SPI0
                DCD     MSPI_Handler 			;  17:  SPI1
                DCD     Efuse_Handler			;  18:  Efuse
                DCD     SSPI_Handler			;  19:  SPI3 (SPI SLAVE)
                DCD     I2C0_Handler			;  20:  I2C0
                DCD     I2C1_Handler			;  21:  I2C1
                DCD     I2S_Master_Handler		;  22:  I2S (MASTER)
                DCD     I2S_Slave_Handler		;  23:  I2S (SLAVE)
                DCD     Ecc_Handler			;  24:  ECC 
                DCD     Null_Handler			;  25:  Reserved
                DCD     TIM1_Handler			;  26:  Timer_1
                DCD     TIM2_Handler			;  27:  Timer_2
                DCD     Null_Handler			;  28:  
                DCD     Null_Handler			;  29:  
                DCD     Null_Handler			;  30:  
                DCD     Null_Handler			;  31:  
                DCD     Null_Handler			;  32:  
                DCD     Null_Handler			;  33:  
                DCD     Null_Handler			;  34:  
                DCD     Sadc_Handler			;  35:  Sensor ADC
                DCD     Calib_Handler			;  36:  Calibration Done
                DCD     PWM0_Handler			;  37:  PWM 0
                DCD     PWM1_Handler			;  38:  PWM 1
                DCD     PWM2_Handler			;  39:  PWM 2
                DCD     PWM3_Handler			;  40:  PWM 3
                DCD     PWM4_Handler			;  41:  PWM 4
                DCD     QD_Handler			;  42:  Quadrature Decoder
                DCD     Counter_Handler		;  43:  Counter
                DCD     WDT_Handler			;  44:  WDT
                DCD     Audio_Handler			;  45:  
                DCD     Null_Handler			;  46:  
                DCD     Null_Handler			;  47:  
                DCD     Null_Handler			;  48:  
                DCD     BLE_Core_Handler		;  49:  BLE Core 
                DCD     Icache_Handler			;  50:  Icache 
                DCD     Null_Handler			;  51:  
                DCD     Null_Handler			;  52:  
                DCD     Null_Handler			;  53:  
                DCD     Null_Handler			;  54:  
                DCD     Null_Handler			;  55:  
                DCD     Null_Handler			;  56:  
                DCD     Null_Handler			;  57:   
                DCD     Null_Handler			;  58:   
                DCD     Null_Handler			;  59:   
                DCD     Null_Handler			;  60:   
                DCD     Null_Handler			;  61:   
                DCD     BOD_Handler			;  62:   
                DCD     XO_Handler			;  63:   
                DCD     Null_Handler			;  64:   
                DCD     SPI_Flash_Handler	;  65:   
                DCD     Global_Irq_Handler	;  66:   
                DCD     Gpio_0_Handler			;  67:  GPIO Group 0 
                DCD     Gpio_1_Handler			;  68:  GPIO Group 1 
                DCD     Gpio_2_Handler			;  69:  GPIO Group 2 
                DCD     Gpio_3_Handler			;  70:  GPIO Group 3 
                DCD     Gpio_4_Handler			;  71:  GPIO Group 4   
__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT     Null_Handler				[WEAK]
                EXPORT     DMA0_Handler  			[WEAK]
                EXPORT     DMA1_Handler 			[WEAK]
                EXPORT     KB_Handler 				[WEAK]
                EXPORT     Hash_Handler 				[WEAK]
                EXPORT     Aes_Handler				[WEAK]
                EXPORT     Hwacc_Handler			[WEAK]
                EXPORT     UART0_Handler 			[WEAK]
                EXPORT     UART1_Handler 			[WEAK]
                EXPORT     SPI0_Handler 				[WEAK]
                EXPORT     MSPI_Handler				[WEAK]
                EXPORT     Efuse_Handler				[WEAK]
                EXPORT     SSPI_Handler 				[WEAK]
                EXPORT     I2C0_Handler 				[WEAK]
                EXPORT     I2C1_Handler 				[WEAK]
                EXPORT     I2S_Master_Handler	[WEAK]
                EXPORT     I2S_Slave_Handler		[WEAK]
                EXPORT     Ecc_Handler				[WEAK]
                EXPORT     TIM1_Handler				[WEAK]
                EXPORT     TIM2_Handler				[WEAK]
                EXPORT     Sadc_Handler				[WEAK]
                EXPORT     Calib_Handler				[WEAK]
                EXPORT     PWM0_Handler			[WEAK]
                EXPORT     PWM1_Handler			[WEAK]
                EXPORT     PWM2_Handler			[WEAK]
                EXPORT     PWM3_Handler			[WEAK]
                EXPORT     PWM4_Handler			[WEAK]
                EXPORT     QD_Handler					[WEAK]
                EXPORT     Counter_Handler			[WEAK]
                EXPORT     WDT_Handler				[WEAK]
                EXPORT     BLE_Core_Handler		[WEAK] 
                EXPORT     Icache_Handler			[WEAK] 
                EXPORT     BOD_Handler				[WEAK] 
                EXPORT     XO_Handler					[WEAK] 
                EXPORT     SPI_Flash_Handler		[WEAK] 
                EXPORT     Global_Irq_Handler			[WEAK] 
                EXPORT     Gpio_0_Handler			[WEAK] 
                EXPORT     Gpio_1_Handler			[WEAK] 
                EXPORT     Gpio_2_Handler			[WEAK] 
                EXPORT     Gpio_3_Handler			[WEAK] 
                EXPORT     Gpio_4_Handler			[WEAK] 
		EXPORT     Audio_Handler			[WEAK] 

Null_Handler					
DMA0_Handler 				
DMA1_Handler 				
KB_Handler 				
Hash_Handler 				
Aes_Handler 					
Hwacc_Handler 					
UART0_Handler 			
UART1_Handler 			
SPI0_Handler 				
MSPI_Handler 				
SPI2_Handler 				
Efuse_Handler 	
SSPI_Handler
I2C0_Handler 				
I2C1_Handler 				
I2S_Master_Handler		
I2S_Slave_Handler
Ecc_Handler
TIM1_Handler				
TIM2_Handler				
Sadc_Handler			
Calib_Handler			
PWM0_Handler				
PWM1_Handler				
PWM2_Handler				
PWM3_Handler				
PWM4_Handler				
QD_Handler					
Counter_Handler					
WDT_Handler					
BLE_Core_Handler
Icache_Handler
BOD_Handler
XO_Handler
SPI_Flash_Handler
Global_Irq_Handler
Gpio_0_Handler
Gpio_1_Handler
Gpio_2_Handler
Gpio_3_Handler
Gpio_4_Handler
Audio_Handler
                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap PROC
                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR
                ENDP

                ALIGN

                ENDIF


                END

