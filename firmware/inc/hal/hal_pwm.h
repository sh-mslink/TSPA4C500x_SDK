/**
 ****************************************************************************************
 *
 * @file hal_pwm.h
 *
 * @brief PWM driver header file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef HAL_PWM_H
#define HAL_PWM_H

/**
 ****************************************************************************************
 * @defgroup HAL_PWM PWM device driver  
 * @ingroup HAL
 * @brief  HAL_PWM
 * @{
 ****************************************************************************************
 */

#include "in_mmap.h"

/*
 * Defines
 ****************************************************************************************
 */
#define PWM_REG_CR_OFS		0x00000000
#define PWM_REG_PR_OFS		0x00000004
#define PWM_REG_HR_OFS		0x00000008
#define PWM_REG_EI_OFS		0x00000010
#define PWM_REG_DI_OFS		0x00000014
#define PWM_REG_RI_OFS		0x00000018
#define PWM_REG_IS_OFS		0x0000001C

/*
 * Inline Functions
 ****************************************************************************************
 */
static __inline void pwm_enable(uint32_t base)
{
	WR_WORD(base + PWM_REG_CR_OFS, 1); 
}

static __inline void pwm_disable(uint32_t base)
{
	WR_WORD(base + PWM_REG_CR_OFS, 1); 
}

static __inline void pwm_config(uint32_t base, uint32_t period_count, uint32_t high_count)
{
	WR_WORD(base + PWM_REG_PR_OFS, period_count);
	WR_WORD(base + PWM_REG_HR_OFS, high_count);
}

static __inline void pwm_hr(uint32_t base, uint32_t high_count)
{
	WR_WORD(base + PWM_REG_HR_OFS, high_count);
}

static __inline void pwm_it_enable(uint32_t base)
{
	WR_WORD(base + PWM_REG_EI_OFS, 1);
}

static __inline void pwm_it_disable(uint32_t base)
{
	WR_WORD(base + PWM_REG_DI_OFS, 1);
}

static __inline uint32_t pwm_it_status(uint32_t base)
{
	return RD_WORD(base + PWM_REG_IS_OFS);
}

/*
 * Enumeration
 ****************************************************************************************
 */

enum pwm_id {
	PWM0_ID = 1,
	PWM1_ID,
	PWM2_ID,
	PWM3_ID,
	PWM4_ID,
};

enum pwm_err {
	PWM_ERR_OK = 0,
	PWM_ERR_INVALID_PARAM = -1,
	PWM_ERR_BAD_STATE = -2,
} ;

/*
 * APIs
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Open PWM driver 
 *				  
 * @param[in] id						PWM Id, @see enum pwm_id.   
 *
 * @return PWM driver handle if successful; NULL otherwise
 ****************************************************************************************
 */
void *hal_pwm_open(int id);

/**
 ****************************************************************************************
 * @brief Close PWM driver 
 *				  
 * @param[in] hdl					PWM handle from the open API
 *
 * @return Driver error return code, @see enum pwm_err 
 ****************************************************************************************
 */
int hal_pwm_close(void *hdl);

/**
 ****************************************************************************************
 * @brief Enable PWM  
 * @note This function can generate interrupt if "callback" function is not NULL.
 *				  
 * @param[in] hdl					PWM handle from the open API
 * @param[in] period_usec	PWM period
 * @param[in] high_usec		PWM high time
 * @param[in] arg					PWM call back function argument
 * @param[in] callback			PWM call back function
 *
 * @return Driver error return code, @see enum pwm_err 
 ****************************************************************************************
 */
int hal_pwm_enable(void *hdl, uint32_t period_usec, uint32_t high_usec, void *arg, void (*callback)(void *) );

/**
 ****************************************************************************************
 * @brief Disable PWM driver 
 *				  
 * @param[in] hdl					PWM handle from the open API
 *
 * @return Driver error return code, @see enum pwm_err 
 ****************************************************************************************
 */
int hal_pwm_disable(void *hdl);

/**
 ****************************************************************************************
 * @brief Adjust PWM driver 
 *				  
 * @param[in] hdl					PWM handle from the open API
 * @param[in] high_usec		PWM adjusted high time
 *
 * @return Driver error return code, @see enum pwm_err 
 ****************************************************************************************
 */
int hal_pwm_adjust(void *hdl, uint32_t high_usec);

/// @} HAL_PWM

#endif	// HAL_PWM_H

