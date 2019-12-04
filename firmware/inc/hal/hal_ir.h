/**
 ****************************************************************************************
 *
 * @file hal_ir.h
 *
 * @brief IR driver header file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
#ifndef HAL_IR_H
#define HAL_IR_H
#include <stdint.h>
#include "cmsis_os.h"
#include "hal\hal_counter.h"
/**
 * @defgroup HAL HAL driver
 * @brief HAL
 * */

/**
 * @defgroup HAL_IR IR driver
 * @ingroup HAL
 * @brief HAL IR
 * @{
 * */


///IR mode
#define IR_IDLE 0x1 ///< Idle
#define IR_SEND 0x2 ///< Send data
#define IR_RECV 0x4 ///< Recieve data
//#define IR_FREQ 0x8
#define IR_RECV_FREQ 0x10 ///< Reciece data for calculate frequence


#define IR_FREQ_BUF_LEN 6 ///< Buffer length for calculate frequence. Must be divided evenly by 3, and minimum value is 3


//#define IR_MSG_BASE 0x00020000UL ///<Message base
//#define IR_MSG_RECV_STOP 0x1UL ///< Recieve stop message
//#define IR_MSG_SEND_STOP 0x2UL ///< Send stop message

///IR device ID
enum {
    IR0_ID = 0,
    IR_MAX_ID,
};
enum ir_error{
	IR_ERR_OK = 0,
	IR_ERR_INVALID_PARAM = -1,
    IR_ERR_SEM = -2,
};
///IR dev struct  
typedef struct
{
    int id; ///< id
    cnt_dev_t *cnt_dev; ///< Counter device
    int tx_pin; ///tx pin for ir send
    int rx_pin; ///rx pin for ir receive
    uint32_t rising_cnt; ///< Counter clock count for IR carrier rising time. (rising_cnt + failing_cnt)*(ir carrier frequence) = counter clock frequence.
    uint32_t failing_cnt; ///< Counter clock count for IR carrier failing time.
    uint32_t mode; ///< IR device mode
    osSemaphoreId semaphore; ///< semaphore
    osMutexId mutex; ///< mutex
    int cycle_offset; ///<add offset for ir_din_onecycle_value reg, to make it stable
    void (*handler)(uint32_t param); ///< ISR handler
    int used; ///< is device in use

#if CFG_PM_EN
	int power_state;
	struct pm_module pmd;
#endif


} ir_dev_t;

/**
 * @brief Open IR device
 * @param[in] id    IR device id
 * @param[in] cnt_id    Counter device id
 * @param[in] rx_pin    rx pin @see enum cnt_ext_pin
 * @param[in] tx_pin    tx pin @see enum cnt_ext_pin
 * @return Return IR device struct, NUll if failed.
 * */
ir_dev_t *hal_ir_open(int id, int cnt_id, int rx_pin, int tx_pin);

/**
 * @brief Close IR device
 * @param[in] dev   IR device struct
 * */
void hal_ir_close(ir_dev_t* dev);

/** 
 * @brief Start reciece data. Need call @see ir_stop_recv to get last sample.
 * @param[in] dev   IR device struct
 * @param[in] buf   recieve data buffer
 * @param[in] size  buffer size
 * @param[out] out_sz receive size, max value is size.
 * @return  @see enum ir_error for return code.
 * */
int hal_ir_recv(ir_dev_t* dev, uint32_t *buf, int size, uint32_t *out_sz);

/** 
 * @brief Start reciece data for frequence caculation. Need call @see ir_stop_recv to get last sample.
 * @param[in] dev   IR device struct
 * @param[in] buf   recieve data buffer
 * @param[in] size  buffer size
 * @param[out] out_sz receive size, max value is size -1.
 * @return  @see enum ir_error for return code.
 * */
int hal_ir_recv_freq(ir_dev_t *dev, uint32_t *buf, int size, uint32_t *out_sz);

/** 
 * @brief Stop reciece data
 * @param[in] dev   IR device struct
 * @return  @see enum ir_error for return code.
 * */
int hal_ir_stop_recv(ir_dev_t* dev);

/** 
 * @brief Start send data.
 * @param[in] dev   IR device struct
 * @param[in] buf   data buffer
 * @param[in] size  buffer size
 * @return  @see enum ir_error for return code.
 * */
int hal_ir_send(ir_dev_t* dev, uint32_t *buf, int size);

/** 
 * @brief Stop send data
 * @param[in] dev   IR device struct
 * @return  @see enum ir_error for return code.
 * */
int hal_ir_stop_send(ir_dev_t *dev);

/** 
 * @brief Send data and then send repeated data continually
 * @param[in] dev   IR device struct
 * @param[in] buf   data buffer. Won't send data when buf is NULL.
 * @param[in] size  buffer size
 * @param[in] repeat_buf    data buffer
 * @param[in] repeat_size   buffer size
 * @return  @see enum ir_error for return code.
 * */
int hal_ir_send_repeat(ir_dev_t *dev, uint32_t *buf, int size, uint32_t *repeat_buf, int repeat_size);

/** 
 * @brief Set IR carrier clock mannually
 * @param[in] dev   IR device struct
 * @param[in] clk   Carrier clock. Default is 38KHz
 * @return  @see enum ir_error for return code.
 * */
int hal_ir_set_clk(ir_dev_t* dev, uint32_t clk);

int hal_ir_is_stop(ir_dev_t *dev);


/// @} HAL_IR
#endif
