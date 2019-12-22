/**
 ****************************************************************************************
 *
 * @file hal_cnt_timer.h
 *
 * @brief Counter timer driver header file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */
#ifndef HAL_CNT_TIMER_H
#define HAL_CNT_TIMER_H
/**
 ****************************************************************************************
 * @defgroup HAL_CNT_TIMER Counter Timer driver  
 * @ingroup HAL
 * @brief  HAL_CNT_TIMER
 * @{
 ****************************************************************************************
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include ".\hal\hal_counter.h"
enum cnt_tim_err {
	CNT_TIM_ERR_OK = 0,
	CNT_TIM_ERR_INVALID_PARAM = -1,
	CNT_TIM_ERR_IN_USE = -2,
	CNT_TIM_ERR_BAD_STATE = -3,
};
typedef struct
{
    int id; ///< id
    cnt_dev_t *cnt_dev; ///< Counter device
    uint32_t sma[2];
    osSemaphoreId semaphore; ///< semaphore
    uint32_t mu[4]; 
    osMutexId mutex;///< mutex
    int used; ///< is device in use
    int busy;
    void (*callback)(void*);
    void *arg;
    int onetime;
#if CFG_PM_EN
	int power_state;
	struct pm_module pmd;
#endif

} cnt_timer_dev_t;
enum cnt_timer_id_t {
    CNT_TIMER0 = 0,
    CNT_TIMER1,
    CNT_TIMER2,
    CNT_TIMER3,
    CNT_TIMER_MAX,
};

/**
 * @brief Open counter timer
 * @param[in] id    Timer id @see enum cnt_timer_id_t.
 * @return Counter timer device struct, NULL if failed. 
 * */
cnt_timer_dev_t *hal_cnt_timer_open(int id);

/**
 * @brief Open counter timer
 * @param[in] pd    Counter timer device struct.
 * @return None. 
 * */
void hal_cnt_timer_close(cnt_timer_dev_t *pd);


/**
 * @brief Run Timer once function
 * @param[in] pd                    Counter timer device struct.
 * @param[in] msec					Millisecond duration.   
 * @param[in] arg					Pointer to user's own context to be passed back to user. 
 * @param[in] tmr_cb				Pointer to user's provided call back function. This function is called in ISR context.
 * @return  @see enum cnt_tim_err
 * */
int hal_cnt_timer_once(cnt_timer_dev_t *pd, uint32_t msec, void *arg, void (*tmr_cb)(void *));

/**
 ****************************************************************************************
 * @brief Run Timer periodic function
 * @param[in] pd            Counter timer device struct.
 * @param[in] msec			Millisecond duration.   
 * @param[in] arg			Pointer to user's own context to be passed back to user. 
 * @param[in] tmr_cb		Pointer to user's provided call back function. This function is called in ISR context.  
 *
 * @return  @see enum cnt_tim_err
 ****************************************************************************************
 */
int hal_cnt_timer_period_start(cnt_timer_dev_t *pd, uint32_t msec, void *arg, void (*tmr_cb)(void *));
/**
 ****************************************************************************************
 * @brief Stop Timer periodic function
 * @param[in] pd    Counter timer device struct.
 * @return  @see enum tim_err
 ****************************************************************************************
 */
int hal_cnt_timer_period_stop(cnt_timer_dev_t *pd);
/// @} HAL_CNT_TIMER


#endif
