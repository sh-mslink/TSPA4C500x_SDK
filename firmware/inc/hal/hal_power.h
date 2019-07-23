/**
 ****************************************************************************************
 *
 * @file hal_power.h
 *
 * @brief HAL power management and sleep timers  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef HAL_POWER_H
#define HAL_POWER_H

/**
 ****************************************************************************************
 * @defgroup HAL_POWER Platform power management and sleep timer  
 * @ingroup HAL
 * @brief  HAL_POWER
 * @{
 ****************************************************************************************
 */

#include <stdint.h>
#include "in_mmap.h"

/*
 * Defines
 ****************************************************************************************
 */
#define PM_MAX_SLEEP_TIME 0xFFFFFFFF

/*
 * Enumerations
 ****************************************************************************************
 */

enum pm_state {
	PM_ACTIVE,
	PM_SLEEP,
	PM_DEEP_SLEEP,
};

enum sleep_timer_id {
	SLEEP_TIMER0_ID,
	SLEEP_TIMER1_ID,
};

enum pm_err {
	PM_ERR_NO_ERROR,
	PM_ERR_INVALID_PARAM = -1,
	PM_ERR_NOT_AVAIL = -2,
	PM_ERR_OS_ERROR = -3,
};

enum em_retn {
	PM_RETN_EM_4K_A = 0x1,
	PM_RETN_EM_4K_B = 0x2,
	PM_RETN_EM_8K_A = 0x4,
	PM_RETN_EM_8K_B = 0x8,
	PM_RETN_EM_16K = 0x10,
	PM_RETN_EM_ALL = 0x1F,
};

enum dm_retn {
	PM_RETN_DM_4K_A = 0x1,
	PM_RETN_DM_4K_B = 0x2,
	PM_RETN_DM_8K = 0x4,
	PM_RETN_DM_16K = 0x8,
	PM_RETN_DM_32K = 0x10,
	PM_RETN_DM_ALL = 0x1F,
};

/*
 * Structures
 ****************************************************************************************
 */
struct pm_module  {
	struct pm_module *prev;
	struct pm_module *next;
	void *arg;
	int (*power_state)(void *arg, uint32_t *slp_dur);
	void (*power_down)(void *arg, uint32_t slp_dur);
	void (*power_up)(void *arg);	
};

/*
 * Inline Functions
 ****************************************************************************************
 */

static __inline uint32_t aon_read(uint32_t addr)
{
	WR_WORD(APB_AON_BRIDGE_REG_OP_CTRL, (addr & APB_AON_BRIDGE_REG_OP_CTRL_CTL_AON_REG_ADDR_MASK));
	while (!(RD_WORD(APB_AON_BRIDGE_REG_OP_CTRL) & APB_AON_BRIDGE_REG_OP_CTRL_STS_AON_REG_RW_DONE));

	return RD_WORD(APB_AON_BRIDGE_REG_RDATA);
}

static __inline void aon_write(uint32_t addr, uint32_t value)
{
	WR_WORD(APB_AON_BRIDGE_REG_WDATA, value);
	addr |= APB_AON_BRIDGE_REG_OP_CTRL_CTL_AON_REG_RD0WR1;
	WR_WORD(APB_AON_BRIDGE_REG_OP_CTRL, addr);
	while (!(RD_WORD(APB_AON_BRIDGE_REG_OP_CTRL) & APB_AON_BRIDGE_REG_OP_CTRL_STS_AON_REG_RW_DONE));
}

static __inline void aon_sleep_timer_set_init_value(int id, uint32_t tick)			
{
	if (id == SLEEP_TIMER0_ID)
		aon_write(AON_REG_AON_TIMER0_INIT_VAL, tick);
	else
		aon_write(AON_REG_AON_TIMER1_INIT_VAL, tick);
}

static __inline uint32_t aon_sleep_timer_get_init_value(int id)			
{
	uint32_t tick;

	if (id == SLEEP_TIMER0_ID)
		tick = aon_read(AON_REG_AON_TIMER0_INIT_VAL);
	else
		tick = aon_read(AON_REG_AON_TIMER1_INIT_VAL);

	return tick;
}

static __inline uint32_t sleep_timer_value(int id)			
{
	uint32_t tick;

	if (id == SLEEP_TIMER0_ID)
		tick = RD_WORD(GLOBAL_REG_PD0_AON_TIMER0_CURR_VAL);
	else
		tick = RD_WORD(GLOBAL_REG_PD0_AON_TIMER1_CURR_VAL);

	return tick;
}

static __inline void aon_sleep_timer_enable(int id)			
{

	if (id == SLEEP_TIMER0_ID) {
		aon_write(AON_REG_AON_TIMER0_CTRL, (aon_read(AON_REG_AON_TIMER0_CTRL) | (AON_REG_AON_TIMER0_CTRL_CTL_AON_TIMER0_EN|AON_REG_AON_TIMER0_CTRL_CTL_AON_TIMER0_CLK_EN)));
	} else {
		aon_write(AON_REG_AON_TIMER1_CTRL, (aon_read(AON_REG_AON_TIMER1_CTRL) | (AON_REG_AON_TIMER1_CTRL_CTL_AON_TIMER1_EN|AON_REG_AON_TIMER1_CTRL_CTL_AON_TIMER1_CLK_EN)));
	}
}

static __inline void aon_sleep_timer_disable(int id)			
{
	if (id == SLEEP_TIMER0_ID)
		aon_write(AON_REG_AON_TIMER0_CTRL, (aon_read(AON_REG_AON_TIMER0_CTRL) & ~AON_REG_AON_TIMER0_CTRL_CTL_AON_TIMER0_EN));
	else
		aon_write(AON_REG_AON_TIMER1_CTRL, (aon_read(AON_REG_AON_TIMER1_CTRL) & ~AON_REG_AON_TIMER1_CTRL_CTL_AON_TIMER1_EN));
}

static __inline int aon_sleep_timer_is_enable(int id)			
{
	if (id == SLEEP_TIMER0_ID)
		return ((aon_read(AON_REG_AON_TIMER0_CTRL) & AON_REG_AON_TIMER0_CTRL_CTL_AON_TIMER0_EN) ? 1 : 0);
	else
		return ((aon_read(AON_REG_AON_TIMER1_CTRL) & AON_REG_AON_TIMER1_CTRL_CTL_AON_TIMER1_EN) ? 1 : 0);
}

static __inline void aon_sleep_timer_reload(int id, int en)			
{
	if (en) {
		if (id == SLEEP_TIMER0_ID)
			aon_write(AON_REG_AON_TIMER0_CTRL, (aon_read(AON_REG_AON_TIMER0_CTRL) | AON_REG_AON_TIMER0_CTRL_CTL_AON_TIMER0_RELOAD));
		else
			aon_write(AON_REG_AON_TIMER1_CTRL, (aon_read(AON_REG_AON_TIMER1_CTRL) | AON_REG_AON_TIMER1_CTRL_CTL_AON_TIMER1_RELOAD));
	} else {
		if (id == SLEEP_TIMER0_ID)
			aon_write(AON_REG_AON_TIMER0_CTRL, (aon_read(AON_REG_AON_TIMER0_CTRL) & ~AON_REG_AON_TIMER0_CTRL_CTL_AON_TIMER0_RELOAD));
		else
			aon_write(AON_REG_AON_TIMER1_CTRL, (aon_read(AON_REG_AON_TIMER1_CTRL) & ~AON_REG_AON_TIMER1_CTRL_CTL_AON_TIMER1_RELOAD));
	}
}

static __inline void aon_sleep_timer_intr_enable(int id)			
{
	if (id == SLEEP_TIMER0_ID)
		WR_WORD(GLOBAL_REG_INTR_MASK_CLEAR, (RD_WORD(GLOBAL_REG_INTR_MASK_CLEAR) |GLOBAL_REG_INTR_MASK_CLEAR_AON_TIMER_0));
	else
		WR_WORD(GLOBAL_REG_INTR_MASK_CLEAR, (RD_WORD(GLOBAL_REG_INTR_MASK_CLEAR) |GLOBAL_REG_INTR_MASK_CLEAR_AON_TIMER_1));
}

static __inline void aon_sleep_timer_intr_disable(int id)			
{
	if (id == SLEEP_TIMER0_ID)
		WR_WORD(GLOBAL_REG_INTR_MASK_SET, (RD_WORD(GLOBAL_REG_INTR_MASK_SET)|GLOBAL_REG_INTR_MASK_SET_AON_TIMER_0));
	else
		WR_WORD(GLOBAL_REG_INTR_MASK_SET, (RD_WORD(GLOBAL_REG_INTR_MASK_SET)|GLOBAL_REG_INTR_MASK_SET_AON_TIMER_1));
}

static __inline void aon_sleep_timer_intr_clr(int id)			
{
	if (id == SLEEP_TIMER0_ID)
		WR_WORD(GLOBAL_REG_INTR_CLEAR, (RD_WORD(GLOBAL_REG_INTR_CLEAR)|GLOBAL_REG_INTR_CLEAR_AON_TIMER_0));
	else
		WR_WORD(GLOBAL_REG_INTR_CLEAR, (RD_WORD(GLOBAL_REG_INTR_CLEAR)|GLOBAL_REG_INTR_CLEAR_AON_TIMER_1));
}

static __inline uint32_t aon_sleep_timer_intr_status(void)			
{
	return RD_WORD(GLOBAL_REG_INTR_STATUS);
}

static __inline void aon_sleep_timer_wup_enable(int id)			
{
	uint32_t reg = aon_read(AON_REG_AON_TIMER_WAKE_UP_SEL);

	if (reg & AON_REG_AON_TIMER_WAKE_UP_SEL_CTL_AON_TIMER_WAKEUP_EN) {
		uint32_t sel = (reg >> AON_REG_AON_TIMER_WAKE_UP_SEL_CTL_AON_TIMER_WAKEUP_SEL_SHIFT) & AON_REG_AON_TIMER_WAKE_UP_SEL_CTL_AON_TIMER_WAKEUP_SEL_MASK;
		if (sel == 0) {	// Timer 0
			if (id == SLEEP_TIMER1_ID)
				sel = 2;
		} else if (sel == 1) {	// Timer 1
			if (id == SLEEP_TIMER0_ID)
				sel = 2;
		}
		reg &= ~AON_REG_AON_TIMER_WAKE_UP_SEL_CTL_AON_TIMER_WAKEUP_SEL;
		reg |= (sel << AON_REG_AON_TIMER_WAKE_UP_SEL_CTL_AON_TIMER_WAKEUP_SEL_SHIFT);
	} else {
		reg &= ~AON_REG_AON_TIMER_WAKE_UP_SEL_CTL_AON_TIMER_WAKEUP_SEL;
		if (id == SLEEP_TIMER1_ID)
			reg |= (1 << AON_REG_AON_TIMER_WAKE_UP_SEL_CTL_AON_TIMER_WAKEUP_SEL_SHIFT);
		reg |= AON_REG_AON_TIMER_WAKE_UP_SEL_CTL_AON_TIMER_WAKEUP_EN;
	}

	aon_write(AON_REG_AON_TIMER_WAKE_UP_SEL, reg);
}

static __inline void aon_sleep_timer_wup_disable(int id)			
{
	uint32_t reg = aon_read(AON_REG_AON_TIMER_WAKE_UP_SEL);
	uint32_t sel = (reg >> AON_REG_AON_TIMER_WAKE_UP_SEL_CTL_AON_TIMER_WAKEUP_SEL_SHIFT) & AON_REG_AON_TIMER_WAKE_UP_SEL_CTL_AON_TIMER_WAKEUP_SEL_MASK;
	int clear = 1;

	if (id == SLEEP_TIMER0_ID) {
		if (sel == 2) {
			sel = 1;
			clear = 0;
		} else {
			sel = 0;
		}
	}

	if (id == SLEEP_TIMER1_ID) {
		if (sel == 2) {
			sel = 0;
			clear = 0;
		} else {
			sel = 0;
		}
	}

	reg &= ~AON_REG_AON_TIMER_WAKE_UP_SEL_CTL_AON_TIMER_WAKEUP_SEL;
	reg |= (sel << AON_REG_AON_TIMER_WAKE_UP_SEL_CTL_AON_TIMER_WAKEUP_SEL_SHIFT);	
	if (clear)
		reg &= ~AON_REG_AON_TIMER_WAKE_UP_SEL_CTL_AON_TIMER_WAKEUP_EN;

	aon_write(AON_REG_AON_TIMER_WAKE_UP_SEL, reg);
}

static __inline void aon_sleep_timer_global_wup_enable(void)			
{
	aon_write(AON_PS_REGS_AON_ST_WAKEUP_CTRL, 1);
}

static __inline void aon_sleep_timer_global_wup_disable(void)			
{
	aon_write(AON_PS_REGS_AON_ST_WAKEUP_CTRL, 0);
}

static __inline void aon_ble_wup_enable(void)			
{
	aon_write(AON_PS_REGS_BLE_ST_WAKEUP_CTRL, 1);
}

static __inline void aon_ble_wup_disable(void)			
{
	aon_write(AON_PS_REGS_BLE_ST_WAKEUP_CTRL, 0);
}

static __inline void aon_brown_out_wup_enable(void)			
{
	aon_write(AON_PS_REGS_BO_OUT_WAKEUP_CTRL, 1);
}

static __inline void aon_brown_out_wup_disable(void)			
{
	aon_write(AON_PS_REGS_BO_OUT_WAKEUP_CTRL, 0);
}

static __inline void aon_mixed_signal_wup_enable(void)			
{
	aon_write(AON_PS_REGS_MSIO_WAKEUP_CTRL, 1);
}

static __inline void aon_mixed_signal_wup_disable(void)			
{
	aon_write(AON_PS_REGS_MSIO_WAKEUP_CTRL, 0);
}

static __inline void aon_gpio_wup_mask(void)			
{
	aon_write(AON_REG_GPIO_WAKEUP_MASK, 0xFFFFFFFF);
	aon_write(AON_REG_MS_GPIO_WAKEUP_MASK, 0xFFFFFFFF);
}

static __inline void aon_deep_sleep_enable(int force)			
{
	uint32_t reg = aon_read(AON_PS_REGS_PD_DOO_SLEEP_CTRL);

	if (force) {
		reg |= AON_PS_REGS_PD_DOO_SLEEP_CTRL_FORCE;
	} else {
		reg &= ~AON_PS_REGS_PD_DOO_SLEEP_CTRL_FORCE;
	}
	reg |= AON_PS_REGS_PD_DOO_SLEEP_CTRL_PD_DOO_CORE_ENABLE;		/* PD_DOO_CORE Sleep */

	aon_write(AON_PS_REGS_PD_DOO_SLEEP_CTRL, reg);
}

static __inline void aon_deep_sleep_disable(void)			
{
	uint32_t reg = aon_read(AON_PS_REGS_PD_DOO_SLEEP_CTRL);

	reg &= ~AON_PS_REGS_PD_DOO_SLEEP_CTRL_PD_DOO_CORE_ENABLE;		

	aon_write(AON_PS_REGS_PD_DOO_SLEEP_CTRL, reg);
}

static __inline void aon_dm_reten(uint32_t retn)			
{
	uint32_t reg = aon_read(AON_PS_REGS_PD_DOO_SLEEP_CTRL);
	if (retn & PM_RETN_DM_4K_A)
		reg |= AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_4K_A_RET_ENABLE;
	else
		reg &= ~AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_4K_A_RET_ENABLE;

	if (retn & PM_RETN_DM_4K_B)
		reg |= AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_4K_B_RET_ENABLE;
	else
		reg &= ~AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_4K_B_RET_ENABLE;

	if (retn & PM_RETN_DM_8K)
		reg |= AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_8K_RET_ENABLE;
	else
		reg &= ~AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_8K_RET_ENABLE;

	if (retn & PM_RETN_DM_16K)
		reg |= AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_16K_RET_ENABLE;
	else
		reg &= ~AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_16K_RET_ENABLE;

	if (retn & PM_RETN_DM_32K)
		reg |= AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_32K_A_RET_ENABLE;
	else
		reg &= ~AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_32K_A_RET_ENABLE;

	aon_write(AON_PS_REGS_PD_DOO_SLEEP_CTRL, reg);
}

static __inline void aon_em_reten(int en, uint32_t retn)			
{
	uint32_t reg = aon_read(AON_PS_REGS_PD_DOO_SLEEP_CTRL);

	if (en) {
		if (retn & PM_RETN_EM_4K_A)
			reg |= AON_PS_REGS_PD_DOO_SLEEP_CTRL_EM_4K_A_RET_ENABLE;

		if (retn & PM_RETN_EM_4K_B)
			reg |= AON_PS_REGS_PD_DOO_SLEEP_CTRL_EM_4K_B_RET_ENABLE;

		if (retn & PM_RETN_EM_8K_A)
			reg |= AON_PS_REGS_PD_DOO_SLEEP_CTRL_EM_8K_A_RET_ENABLE;

		if (retn & PM_RETN_EM_8K_B)
			reg |= AON_PS_REGS_PD_DOO_SLEEP_CTRL_EM_8K_B_RET_ENABLE;

		if (retn & PM_RETN_EM_16K)
			reg |= AON_PS_REGS_PD_DOO_SLEEP_CTRL_EM_16K_A_RET_ENABLE;
	} else {
		if (retn & PM_RETN_EM_4K_A)
			reg &= ~AON_PS_REGS_PD_DOO_SLEEP_CTRL_EM_4K_A_RET_ENABLE;

		if (retn & PM_RETN_EM_4K_B)
			reg &= ~AON_PS_REGS_PD_DOO_SLEEP_CTRL_EM_4K_B_RET_ENABLE;

		if (retn & PM_RETN_EM_8K_A)
			reg &= ~AON_PS_REGS_PD_DOO_SLEEP_CTRL_EM_8K_A_RET_ENABLE;

		if (retn & PM_RETN_EM_8K_B)
			reg &= ~AON_PS_REGS_PD_DOO_SLEEP_CTRL_EM_8K_B_RET_ENABLE;

		if (retn & PM_RETN_EM_16K)
			reg &= ~AON_PS_REGS_PD_DOO_SLEEP_CTRL_EM_16K_A_RET_ENABLE;
	}

	aon_write(AON_PS_REGS_PD_DOO_SLEEP_CTRL, reg);
}

static __inline void aon_trig_mem_retn_en(int en)			
{
	uint32_t reg = aon_read(AON_PS_REGS_PD_DOO_SLEEP_CTRL);
	if (en)
		reg |= AON_PS_REGS_PD_DOO_SLEEP_CTRL_TRIG_RET_ENABLE;
	else
		reg &= ~AON_PS_REGS_PD_DOO_SLEEP_CTRL_TRIG_RET_ENABLE;

	aon_write(AON_PS_REGS_PD_DOO_SLEEP_CTRL, reg);
}

static __inline void wic_en(int en)			
{
	if (en) {
		WR_WORD(GLOBAL_REG_CM4_WIC_EN_REQ, 1);
		while (!(RD_WORD(GLOBAL_REG_CM4_WIC_EN_ACK) & GLOBAL_REG_CM4_WIC_EN_ACK_STS_CM4_WIC_EN_ACK));
	} else {
		WR_WORD(GLOBAL_REG_CM4_WIC_EN_REQ, 0);
	}
}

static __inline void aon_qspi_vddio(int en)
{
	uint32_t reg = aon_read(AON_PS_REGS_MISC_BYPASS_0_CTRL);
	if (en) {
		reg &= ~AON_PS_REGS_MISC_BYPASS_0_CTRL_QSPI_VDDIO_EN_EN;
		reg |= AON_PS_REGS_MISC_BYPASS_0_CTRL_QSPI_VDDIO_EN_VAL;
	} else {
		reg |= AON_PS_REGS_MISC_BYPASS_0_CTRL_QSPI_VDDIO_EN_EN;
		reg &= ~AON_PS_REGS_MISC_BYPASS_0_CTRL_QSPI_VDDIO_EN_VAL;
	}
	aon_write(AON_PS_REGS_MISC_BYPASS_0_CTRL, reg);
}

/*
 * APIs
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief  Power Management initialization function.  
 *
 * @param[in] slp_wup		Sleep timer can wake up system from deep sleep; 1: yes, 0: no.
 * @param[in] ble_wup		BLE can wake up system from deep slee; 1: yes, 0: no.
 * @param[in] bod_wup		Brown out can wake up system from deep slee; 1: yes, 0: no.
 * @param[in] mix_wup		Mixed signal can wake up system from deep slee; 1: yes, 0: no.
 * @param[in] dm_retn		Data memory retention flag; @see enum dm_retn.
 *
 * @return  @see enum pm_err
 ****************************************************************************************
 */
int hal_pm_init(int slp_wup, int ble_wup, int bod_wup, int mix_wup, uint32_t dm_retn);

/**
 ****************************************************************************************
 * @brief  Exchange memory retention function.  
 *
 * @param[in] retn		Exchange memory retention flag; @see enum em_retn.
 *
 * @return  No return
 ****************************************************************************************
 */
void hal_pm_em_reten(uint32_t retn);

/**
 ****************************************************************************************
 * @brief  Data memory retention function.  
 *
 * @param[in] retn		Data memory retention flag; @see enum dm_retn.
 *
 * @return  No return
 ****************************************************************************************
 */
void hal_pm_dm_reten(uint32_t retn);

/**
 ****************************************************************************************
 * @brief  Register power module function.  
 *
 * @param[in] module				A pointer to the PM module structure, @see struct pm_module  
 *
 * @return  @see enum pm_err
 ****************************************************************************************
 */
int hal_pm_reg_mod(struct pm_module *module);

/**
 ****************************************************************************************
 * @brief  Unregister power module function.  
 *
 * @param[in] module				A pointer to the PM module structure, @see struct pm_module  
 *
 * @return  @see enum pm_err
 ****************************************************************************************
 */
int hal_pm_unreg_mod(struct pm_module *module);

/**
 ****************************************************************************************
 * @brief  Sleep timer interrupt handler.  
 * @note This is called from global isr handler. 
 *
 * @return  NO return
 ****************************************************************************************
 */
void hal_sleep_timer_intr_handler(void);

/**
 ****************************************************************************************
 * @brief  System shutdown and resume function.
 * @note This function is designed to be called by the OS idle routine.  The shut down procedure are as follows:
 *					1. Mask all the interrupts,
 *					1. Call each driver or application's power state function to find the power state and sleep time,
 *					2. If power state is active, then unmask interrupt and return to OS,
 *					3. If power state is sleep, then call arm's WFI to shut down CPU clock. Once any interrupt happens,
 *						WFI will finish and this function will unmask interrupt and return the sleep time to OS,
 *					5. If power state is deep sleep, then save the context and ask HW to remove power,
 *					6. Once HW resume, boot ram will recover clock, XIP, then jump to this function,  This function will
 *						call each driver and application register power up function to resume system and then it will
 *						unmask interrupt and return the deep sleep time to the OS.
 *
 * @param[in] os_sleep				Time in millisecond that Os is idle
 *
 * @return  Final sleep time.
 ****************************************************************************************
 */
uint32_t hal_pm_suspend_and_resume(uint32_t os_sleep);

/**
 ****************************************************************************************
 * @brief  Register BLE power module function.  
 *
 * @param[in] module				A pointer to the PM module structure, @see struct pm_module  
 *
 * @return  @see enum pm_err
 ****************************************************************************************
 */
int hal_pm_reg_ble_mod(struct pm_module *module);

/**
 ****************************************************************************************
 * @brief  Unregister BLE power module function.  
 *
 * @param[in] module				A pointer to the PM module structure, @see struct pm_module  
 *
 * @return  @see enum pm_err
 ****************************************************************************************
 */
int hal_pm_unreg_ble_mod(struct pm_module *module);

/// @} HAL_POWER

#endif		// HAL_POWER_H 
