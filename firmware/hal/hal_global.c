#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_global.c
 *
 * @brief Platform global functions  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "in_mmap.h"
#include "in_arm.h"
#include "in_debug.h"

#include "boot_share.h"

#include ".\hal\hal_clk.h"
#include ".\hal\hal_power.h"
#include ".\hal\hal_smem.h"
#include ".\hal\hal_uart.h"
#include ".\hal\hal_smem.h"
#include ".\hal\hal_efuse.h"
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_flash.h"
#include ".\hal\hal_global.h"

#include "..\rf\rf_int.h"

#include "cmsis_os.h"


#define GLOBAL_FLASH_SECTOR_SIZE            (4096)
#define GLOBAL_FLASH_SECTOR_ADDR            (0x37E000)

#define GLOBAL_FLASH_ADDR_OFFSET_MAGIC_WORD (0x40)
#define GLOBAL_FLASH_ADDR_MAGIC_WORD        (GLOBAL_FLASH_SECTOR_ADDR + GLOBAL_FLASH_ADDR_OFFSET_MAGIC_WORD)

#define GLOBAL_FLASH_ADDR_OFFSET_CAP_OFFSET (0x44)
#define GLOBAL_FLASH_ADDR_CAP_OFFSET        (GLOBAL_FLASH_SECTOR_ADDR + GLOBAL_FLASH_ADDR_OFFSET_CAP_OFFSET)

#define GLOBAL_FLASH_ADDR_OFFSET_BLE_MAC    (0x46)
#define GLOBAL_FLASH_ADDR_BLE_MAC           (GLOBAL_FLASH_SECTOR_ADDR + GLOBAL_FLASH_ADDR_OFFSET_BLE_MAC)


#if GLOBAL_FLASH_WRITE
static uint8_t gFlashPage[GLOBAL_FLASH_SECTOR_SIZE] = {0};
#endif

/*
 * Debug
 ****************************************************************************************
 */

#if CFG_DBG_EN
#if CFG_DBG_IF_UART
static void *uart_hdl = NULL;

int SER_PutChar(int c)
{
    if(uart_hdl)
        hal_uart_putc(uart_hdl, c);

    return 1;
}
int SER_GetChar(uint8_t *p)
{
    if(uart_hdl)
        hal_uart_rcvd_poll(uart_hdl, p, 1);
    
    return 1;
}
#endif  //CFG_DBG_IF_UART

void HardFault_Handler_C(unsigned long * svc_args, unsigned int lr_value);
 
// HardFault handler wrapper in assembly language.
// It extracts the location of stack frame and passes it to the handler written
// in C as a pointer. We also extract the LR value as second parameter.
__asm void HardFault_Handler(void)
{
    TST    LR, #4
    ITE    EQ
    MRSEQ  R0, MSP
    MRSNE  R0, PSP
    MOV    R1, LR
    B      __cpp(HardFault_Handler_C)
}
 
// HardFault handler in C, with stack frame location and LR value extracted
// from the assembly wrapper as input parameters
void HardFault_Handler_C(unsigned long * hardfault_args, unsigned int lr_value)
{
    unsigned long stacked_r0;
    unsigned long stacked_r1;
    unsigned long stacked_r2;
    unsigned long stacked_r3;
    unsigned long stacked_r12;
    unsigned long stacked_lr;
    unsigned long stacked_pc;
    unsigned long stacked_psr;
    unsigned long cfsr;
    unsigned long bus_fault_address;
    unsigned long memmanage_fault_address;
    
    bus_fault_address       = SCB->BFAR;
    memmanage_fault_address = SCB->MMFAR;
    cfsr                    = SCB->CFSR;
    
    stacked_r0  = ((unsigned long) hardfault_args[0]);
    stacked_r1  = ((unsigned long) hardfault_args[1]);
    stacked_r2  = ((unsigned long) hardfault_args[2]);
    stacked_r3  = ((unsigned long) hardfault_args[3]);
    stacked_r12 = ((unsigned long) hardfault_args[4]);
    stacked_lr  = ((unsigned long) hardfault_args[5]);
    stacked_pc  = ((unsigned long) hardfault_args[6]);
    stacked_psr = ((unsigned long) hardfault_args[7]);
    
    PRINTD (DBG_ERR, "[HardFault]\n");
    PRINTD (DBG_ERR, "- Stack frame:\n"); 
    PRINTD (DBG_ERR, " R0  = %x\n", stacked_r0);
    PRINTD (DBG_ERR, " R1  = %x\n", stacked_r1);
    PRINTD (DBG_ERR, " R2  = %x\n", stacked_r2);
    PRINTD (DBG_ERR, " R3  = %x\n", stacked_r3);
    PRINTD (DBG_ERR, " R12 = %x\n", stacked_r12);
    PRINTD (DBG_ERR, " LR  = %x\n", stacked_lr);
    PRINTD (DBG_ERR, " PC  = %x\n", stacked_pc);
    PRINTD (DBG_ERR, " PSR = %x\n", stacked_psr);
    PRINTD (DBG_ERR, "- FSR/FAR:\n");  
    PRINTD (DBG_ERR, " CFSR = %x\n", cfsr);
    PRINTD (DBG_ERR, " HFSR = %x\n", SCB->HFSR);
    PRINTD (DBG_ERR, " DFSR = %x\n", SCB->DFSR);
    PRINTD (DBG_ERR, " AFSR = %x\n", SCB->AFSR);
    if (cfsr & 0x0080) PRINTD (DBG_ERR, " MMFAR = %x\n", memmanage_fault_address);
    if (cfsr & 0x8000) PRINTD (DBG_ERR, " BFAR = %x\n", bus_fault_address);
    PRINTD (DBG_ERR, "- Misc\n"); 
    PRINTD (DBG_ERR, " LR/EXC_RETURN= %x\n", lr_value);
    
    //while(1); // endless loop
    hal_global_sys_reset();
}
#endif  // CFG_DBG_EN

/*
 * Global ISR
 ****************************************************************************************
 */
__irq void Global_Irq_Handler(void)
{
    uint32_t reg = RD_WORD(GLOBAL_REG_INTR_STATUS);

    if(reg & GLOBAL_REG_INTR_STATUS_AON_TIMER_0)
    {
#if CFG_PM_EN
        hal_sleep_timer_intr_handler();
#endif
    }

    if(reg & GLOBAL_REG_INTR_STATUS_AON_TIMER_1)
    {
#if CFG_PM_EN
        hal_sleep_timer_intr_handler();
#endif
    }
    
    if(reg & GLOBAL_REG_INTR_STATUS_PS_TRANS_DONE)
        ;
    
    if(reg & GLOBAL_REG_INTR_STATUS_EXT_0)
        ;
    
    if(reg & GLOBAL_REG_INTR_STATUS_EXT_1)
        ;
    
    if(reg & GLOBAL_REG_INTR_STATUS_PD_DOO_SLEEP_BLOCK_IRQ)
        ;
    
    if(reg & GLOBAL_REG_INTR_STATUS_OSC_EN)
        ;
    
    /// Clear it
    WR_WORD(GLOBAL_REG_INTR_CLEAR, reg);
}

/*
 * Global FLASH
 ****************************************************************************************
 */
#if GLOBAL_FLASH_WRITE
void hal_global_flash_set(uint32_t magicWord, uint8_t capOffset, inb_addr_t *mac)
{
    memcpy(gFlashPage, (uint8_t*)(GLOBAL_FLASH_SECTOR_ADDR), GLOBAL_FLASH_SECTOR_SIZE);
    
    memcpy(gFlashPage + GLOBAL_FLASH_ADDR_OFFSET_MAGIC_WORD, &magicWord, sizeof(uint32_t));
    memcpy(gFlashPage + GLOBAL_FLASH_ADDR_OFFSET_CAP_OFFSET, &capOffset, sizeof(uint8_t));
    memcpy(gFlashPage + GLOBAL_FLASH_ADDR_OFFSET_BLE_MAC, mac, sizeof(inb_addr_t));
    
    hal_spi_flash_prog(GLOBAL_FLASH_SECTOR_ADDR, GLOBAL_FLASH_SECTOR_SIZE,
            GLOBAL_FLASH_SECTOR_ADDR, GLOBAL_FLASH_SECTOR_SIZE,
            gFlashPage, 0);
}
#endif

uint32_t hal_global_flash_magic_word_get(void)
{
    uint8_t data[4] = {0};
    
    memcpy(&data, (uint8_t*)(GLOBAL_FLASH_ADDR_MAGIC_WORD), sizeof(uint32_t));
    
    return (data[0] | data[1] << 8 | data[2] << 16 | data[3] << 24);
}

uint8_t hal_global_flash_cap_offset_get(void)
{
    uint8_t cap = 0;
    
    memcpy(&cap, (uint8_t*)(GLOBAL_FLASH_ADDR_CAP_OFFSET), sizeof(uint8_t));
    
    return cap;
}

void hal_global_flash_ble_mac_get(inb_addr_t *mac)
{
    inb_addr_t addr = {.addr = CFG_BLE_PARAM_BD_ADDR};
    uint8_t i = 0;
    
    memcpy(&(mac->addr), (uint8_t*)(GLOBAL_FLASH_ADDR_BLE_MAC), sizeof(inb_addr_t));
    
    for(i = 0; i < sizeof(inb_addr_t); i++)
    {
        if(mac->addr[i] != 0xff)
            break;
    }
    
    if(i == sizeof(inb_addr_t))
        memcpy(&(mac->addr), &(addr.addr), sizeof(inb_addr_t));
}

/*
 * Initialization APIs
 ****************************************************************************************
 */
static void cap_offset_set(void)
{
    uint8_t cap = 0;
    uint32_t reg = aon_read(0x1250);
    
    memcpy(&cap, (uint8_t*)(GLOBAL_FLASH_ADDR_CAP_OFFSET), 1);
    
    cap &= 0xf;
    if (cap > 0xf)
        cap = 0xf;
    
    cap = (cap << 4) | cap;
    reg &= ~0xffUL;
    aon_write(0x1250, reg | (cap&0xff));
}

void hal_global_pre_init(void)
{
#if !CFG_FPGA
    rf_int_aon_reg_opt();
    
    /// **** Configure clock ****
    /// Timer
    hal_clk_tim1_set(CFG_TIM1_CLK);
    
    /// HW acc
    hal_clk_hwacc_set(CFG_HWACC_CLK);
    
    /// Sadc
    hal_clk_sadc_set(CFG_SADC_CLK);
    
    /// Efuse
    hal_clk_efuse_set(CFG_EFUSE_CLK);
    
    /// Smem
    hal_clk_smem_set(CFG_SMEM_CLK);
#endif  // !CFG_FPGA

    /// **** Configure shared memory ****
    hal_smem_init();
}

void hal_global_debug_uart_init(void)
{
#if CFG_DBG_EN
#if CFG_DBG_IF_UART
    uart_hdl = hal_uart_open(CFG_DBG_IF_UART_PORT, CFG_DBG_IF_UART_BAUD, 8, 1, 0, 0, 0, 0, 0, 1);
#endif  // CFG_DBG_IF_UART
#endif  // CFG_DBG_EN
}

void hal_global_post_init(void)
{
    cap_offset_set();
    
    /// **** RTC ****
    /// Note: There is a 1 second wait before RTC settle down.
#if !CFG_FPGA
    hal_clk_rtc_en(CFG_RTC_EN);
#endif
    
    /// Disable BLE external wakeup (Software will wake it up)
    aon_ble_ext_wup(0);
    
    /// Assign data ram access priority
    data_ram_access_prio(DATA_RAM_ACCESS_PRIO_3, DATA_RAM_ACCESS_PRIO_2, DATA_RAM_ACCESS_PRIO_1);
    
#if CFG_PM_EN
    uint32_t dm_retn = 0;
    if(CFG_PM_RETN_1_4K)
        dm_retn |= PM_RETN_DM_4K_A;
    if(CFG_PM_RETN_2_4K)
        dm_retn |= PM_RETN_DM_4K_B;
    if(CFG_PM_RETN_8K)
        dm_retn |= PM_RETN_DM_8K;
    if(CFG_PM_RETN_16K)
        dm_retn |= PM_RETN_DM_16K;
    if(CFG_PM_RETN_32K)
        dm_retn |= PM_RETN_DM_32K;
    
    int res;
    res = hal_pm_init(CFG_PM_WUP_SLP_TMR, CFG_PM_WUP_BLE, CFG_PM_WUP_BROWN_OUT, CFG_PM_WUP_MIX_SIGNAL, dm_retn);
    if (res != PM_ERR_NO_ERROR) {
        PRINTD(DBG_ERR, "[Init]: Failed PM initialization...%d\r\n", res);
        while(1);   // Halt it here...
    }
#endif
}

void hal_global_sys_reset(void)
{
    // Disable all interrupt
    __set_PRIMASK(1);
    __set_FAULTMASK(0);
    
    // Switch RTC back to RC
    aon_rc_rtc_sw(0);
    for (int i = 0; i < (6*100); i++)
        __nop();
    
    // Reset...
    aon_reset_chip();
    
    // never return...
}

/*
 * PM system wide HW saving and restoring
 ****************************************************************************************
 */

#if CFG_PM_EN
static uint32_t systick_val;
static uint32_t syspri2_val;
static uint32_t syspri3_val;

void hal_global_suspend(void)
{
    boot_ram_entry_t entry = (boot_ram_entry_t)(BOOTRAM_CODE_START|1);// 1 is for the thumb instruction
    entry(PM_SAVE_CLK_CFG, NULL);
    
    /// save gpio configuration
    //hal_gpio_suspend();//move to hal_pm_suspend_and_resume
    
    /// save the Systick Reload Value 
    systick_val =  SysTick->LOAD;
    syspri2_val = RD_WORD(0xE000ED1C);
    syspri3_val = RD_WORD(0xE000ED20);
    
    /// RF suspend
    rf_int_suspend();
}

void hal_global_resume(void)
{
// Did it in the boot ram.
//#if CFG_IN602
//	SCB->VTOR = CFG_BRAM_COLD_BOOT_ADDR & SCB_VTOR_TBLOFF_Msk; 
//#endif
    
    hal_smem_init();
    
    /// restore gpio configuration
    hal_gpio_resume();
    
    SysTick->LOAD = systick_val;
    WR_WORD(0xE000ED1C, syspri2_val);
    WR_WORD(0xE000ED20, syspri3_val);
    
    /// RF resume
    rf_int_resume();
}
#endif  // CFG_PM_EN

