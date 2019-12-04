/**
 ****************************************************************************************
 *
 * @file hal_cnt_pwm.h
 *
 * @brief Counter PWM driver header file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
#ifndef HAL_CNT_PWM_H
#define HAL_CNT_PWM_H
/**
 ****************************************************************************************
 * @defgroup HAL_CNT_PWM Counter PWM driver  
 * @ingroup HAL
 * @brief  HAL_CNT_PWM
 * @{
 ****************************************************************************************
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include ".\hal\hal_counter.h"
enum cnt_pwm_err {
	CNT_PWM_ERR_OK = 0,
	CNT_PWM_ERR_INVALID_PARAM = -1,
	CNT_PWM_ERR_IN_USE = -2,
	CNT_PWM_ERR_BAD_STATE = -3,
};
typedef struct
{
    int id; ///< id
    cnt_dev_t *cnt_dev; ///< Counter device
    uint32_t mu[4]; 
    osMutexId mutex;///< mutex
    int used; ///< is device in use
    int busy;
    int pin;
#if CFG_PM_EN
	int power_state;
	struct pm_module pmd;
#endif

} cnt_pwm_dev_t;
enum cnt_pwm_id_t {
    CNT_PWM0 = 0,
    CNT_PWM1,
    CNT_PWM2,
    CNT_PWM3,
    CNT_PWM_MAX,
};

/**
 * @brief Open counter PWM
 * @param[in] id        Timer id @see enum cnt_pwm_id_t.
 * @param[in] pwm_pin   PWM output pin, @see enum cnt_ext_pin.
 * @return Counter PWM device struct, NULL if failed. 
 * */
cnt_pwm_dev_t *hal_cnt_pwm_open(int id, int pwm_pin);

/**
 * @brief Close counter PWM
 * @param[in] pd        Counter PWM device struct.
 * @return None. 
 * */
void hal_cnt_pwm_close(cnt_pwm_dev_t *pd);

/**
 ****************************************************************************************
 * @brief Enable PWM  
 *				  
 * @param[in] pd			Counter PWM device struct
 * @param[in] period_usec	PWM period
 * @param[in] high_usec		PWM high time
 *
 * @return Driver error return code, @see enum cnt_pwm_err 
 ****************************************************************************************/
int hal_cnt_pwm_enable(cnt_pwm_dev_t *pd, uint32_t period_usec, uint32_t high_usec);
/**
 ****************************************************************************************
 * @brief Disable PWM  
 *				  
 * @param[in] pd			Counter PWM device struct
 *
 * @return Driver error return code, @see enum cnt_pwm_err 
 ****************************************************************************************/
int hal_cnt_pwm_disable(cnt_pwm_dev_t *pd);
/// @} HAL_CNT_PWM


#endif
