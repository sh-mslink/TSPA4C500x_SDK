/**
 ****************************************************************************************
 *
 * @file hal_timer.h
 *
 * @brief Generic timer header file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef HAL_TIMER_H
#define HAL_TIMER_H

/**
 ****************************************************************************************
 * @defgroup HAL_TIM timer driver  
 * @ingroup HAL
 * @brief  HAL_TIM
 * @{
 ****************************************************************************************
 */

#include "in_mmap.h"

/*
 * Defines
 ****************************************************************************************
 */

#define TMR_REG_LCR_OFS		0x00000000UL
#define TMR_REG_CCR_OFS		0x00000004UL
#define TMR_REG_CTR_OFS		0x00000008UL
#define TMR_REG_EOI_OFS		0x0000000CUL
#define TMR_REG_ISR_OFS		0x00000010UL
#define TMR_REG_RISR_OFS	0x000000A8UL

#define TIMX_CR_ENABLE 		0x0000001UL
#define TIMX_CR_MODE_FIX		0x0000002UL
#define TIMX_CR_IT_MASK 		0x0000004UL
#define TIMX_CR_PWM 			0x0000008UL

/*
 * Inline Functions
 ****************************************************************************************
 */

static __inline void timer_enable(uint32_t base)
{
	uint32_t reg = RD_WORD(base + TMR_REG_CTR_OFS);
	reg |= TIMX_CR_ENABLE;
	WR_WORD(base + TMR_REG_CTR_OFS, reg);
}

static __inline void timer_disable(uint32_t base)
{
	uint32_t reg = RD_WORD(base + TMR_REG_CTR_OFS);
	reg &= ~TIMX_CR_ENABLE;

	WR_WORD(base + TMR_REG_CTR_OFS, reg);
}

static __inline void timer_set_mode(uint32_t base, int free_run)
{
	uint32_t reg = RD_WORD(base + TMR_REG_CTR_OFS);

	if (free_run)
		reg &= ~TIMX_CR_MODE_FIX;
	else
		reg |= TIMX_CR_MODE_FIX;

	WR_WORD(base + TMR_REG_CTR_OFS, reg);
}

static __inline void timer_intr_mask(uint32_t base, int mask)
{
	uint32_t reg = RD_WORD(base + TMR_REG_CTR_OFS);
	if (mask) {
		reg |= TIMX_CR_IT_MASK;
	} else {
		reg &= ~TIMX_CR_IT_MASK;
	}
	WR_WORD(base + TMR_REG_CTR_OFS, reg);
}

static __inline void timer_load_count(uint32_t base, uint32_t count)
{
	WR_WORD(base + TMR_REG_LCR_OFS, count);
}

static __inline uint32_t timer_get_load_count(uint32_t base)
{
	return RD_WORD(base + TMR_REG_LCR_OFS);
}

static __inline uint32_t timer_get_count(uint32_t base)
{
	return RD_WORD(base + TMR_REG_CCR_OFS);
}

static __inline void timer_clear_intr(uint32_t base)
{
	RD_WORD(base + TMR_REG_EOI_OFS);
}

static __inline uint32_t timer_intr_status(uint32_t base)
{
	return RD_WORD(base + TMR_REG_ISR_OFS);
}

static __inline uint32_t timer_intr_raw_status(uint32_t base, int tim_n)
{
	return (RD_WORD(base + TMR_REG_RISR_OFS) & (1 << tim_n));
}

/*
 * Enumeratios
 ****************************************************************************************
 */

enum tim_id {
	TIM1_ID = 0,
	TIM2_ID,
};

enum tim_err {
	TIM_ERR_OK = 0,
	TIM_ERR_INVALID_PARAM = -1,
	TIM_ERR_IN_USE = -2,
	TIM_ERR_BAD_STATE = -3,
} ;

/*
 * Functions
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Check if timer is active.
 *	@note This function will be called by the PM to check if the timer is active.  If it is active, the PM will not 
 *				go into deep sleep mode. 
 *
 *
 * @return 1: timer is active; 0: otherwise. 
 ****************************************************************************************
 */
int hal_timer_busy(void);

/**
 ****************************************************************************************
 * @brief Run Timer once function
 * @note This function is not context safe.  Use it with care.
 * @note This function will set the timer to run user's specified time and then it will disable itself once times up.
 *				User will be informed thru the provided call back function.  The call back function will be called in the 
 *				interrupt context.  
 *
 * @param[in] msec					Millisecond duration.   
 * @param[in] arg						Pointer to user's own context to be passed back to user. 
 * @param[in] tmr_cb				Pointer to user's provided call back function.   
 *
 * @return  @see enum tim_err
 ****************************************************************************************
 */
int hal_timer_once(uint32_t msec, void *arg, void (*tmr_cb)(void *));

/**
 ****************************************************************************************
 * @brief Run Timer periodic function
 * @note This function is not context safe.  Use it with care.
 * @note This function will set the timer to run user's specified time periodically. User will be informed thru 
 *				the provided call back function after each period.  The call back function will be called in the 
 *				interrupt context.  
 *
 * @param[in] msec					Millisecond duration.   
 * @param[in] arg						Pointer to user's own context to be passed back to user. 
 * @param[in] tmr_cb				Pointer to user's provided call back function.   
 *
 * @return  @see enum tim_err
 ****************************************************************************************
 */
int hal_timer_period_start(uint32_t msec, void *arg, void (*tmr_cb)(void *));

/**
 ****************************************************************************************
 * @brief Stop Timer periodic function
 * @note This function is not context safe.  Use it with care.
 *
 * @return  @see enum tim_err
 ****************************************************************************************
 */
int hal_timer_period_stop(void);

/**
 ****************************************************************************************
 * @brief start timer profile function
 * @note This function is not context safe.  Use it with care.
 *
 * @param[in,out] tick_for_us		Pointer to return current timer's ticks for one microsecond.   
 *
 * @return  @see enum tim_err
 ****************************************************************************************
 */
int hal_timer_profile_start(uint32_t *tick_for_us);

/**
 ****************************************************************************************
 * @brief timer profiler read current tick function.
 * @note This function is not context safe.  Use it with care.
 * @note The read back ticks divided by the "tick_for_us" from the "profile_start" function to get the exact time.
 *
 *
 * @return  Current timer ticks.
 ****************************************************************************************
 */
uint32_t hal_timer_profile_get_tick(void);

/**
 ****************************************************************************************
 * @brief timer profiler stop function.
 * @note This function is not context safe.  Use it with care.
 *
 *
 * @return  @see enum tim_err
 ****************************************************************************************
 */
int hal_timer_profile_end(void);

/**
 ****************************************************************************************
 * @brief timer delaye function
 * @note This function is not context safe.  Use it with care.
 *
 * @param[in] usec					Delay time in Microsecond.   
 *
 * @return  @see enum tim_err
 ****************************************************************************************
 */
int hal_timer_delay_us(uint32_t usec);

/**
 ****************************************************************************************
 * @brief Return the OS tick
 *
 * @return  Current OS tick 
 ****************************************************************************************
 */
uint32_t hal_timer_get_systick(void);

/// @} HAL_WDT

#endif	// HAL_TIMER_H
