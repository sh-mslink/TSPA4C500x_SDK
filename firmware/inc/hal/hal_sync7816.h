/**
 ****************************************************************************************
 *
 * @file hal_sync7816.h
 *
 * @brief Sync7816 driver header file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
#ifndef HAL_SYNC7816_H
#define HAL_SYNC7816_H
#include <stdint.h>
#include "cmsis_os.h"
#include ".\hal\hal_power.h"
#include ".\hal\hal_counter.h"

/**
 * @defgroup HAL_SYNC7816 Synchronous 7816 driver
 * @ingroup HAL
 * @brief HAL SYNC7816
 * @{
 * */

///sync7816 device struct
typedef struct {
	//int id;
	cnt_dev_t* clk_dev; ///< Clock counter device
    cnt_dev_t* rst_dev; ///< Reset counter device
    cnt_dev_t* data_dev; ///< Data counter device
    cnt_dev_t* timer_dev;  ///< Timer counter device
    uint32_t clk; ///<Clock
    int used;   ///< Is device in use
    osSemaphoreId semaphore; ///< semaphore
    osMutexId mutex; ///< mutex
    osSemaphoreId timer_sema;
    int clk_pin;
    int rst_pin;
    int data_pin;
#if CFG_PM_EN
	int power_state;
	struct pm_module pmd;
#endif

} sync7816_dev_t;

enum sync7816_error {
	SYNC7816_ERR_OK = 0,
	SYNC7816_ERR_INVALID_PARAM = -1,
    SYNC7816_ERR_TIMEOUT = -2,
    SYNC7816_ERR_LOCK = -3,
};


/**
 * @brief Init sync7816 device
 * @param[in] clk_pin    Clock pin
 * @param[in] rst_pin    Reset pin
 * @param[in] data_pin    Data pin
 * @param[in] clk   Bus clock
 * @return Sync7816 device struct, NUll if failed.
 * */
sync7816_dev_t* hal_sync7816_open(int clk_pin, int rst_pin, int data_pin, uint32_t clk);
void hal_sync7816_close(sync7816_dev_t* dev);
/**
 * @brief  Send stop signal to device
 * @param[in] dev   sync7816 device struct
 * @return None
 * */
void hal_sync7816_stop(sync7816_dev_t* dev);

/**
 * @brief  Get answer to reset
 * @param[in] dev   sync7816 device struct
 * @param[out] pval  data pointer  of answer to reset
 * @return 0 if successful, otherwise failed
 * */
int hal_sync7816_answer_to_rst(sync7816_dev_t* dev, uint32_t* pval);

/**
 * @brief  Send read command for fm4428 chip
 * @param[in] dev   Sync7816 device struct
 * @param[in] cmd   Command
 * @param[in] addr  Address
 * @param[out] rx_data  Data that read out from bus
 * @param[in] rx_len    Rx bit length. Max value is 32 bit.
 * @return 0 if successful, otherwise failed
 * */
int fm4428_read_cmd(sync7816_dev_t* dev, uint32_t cmd, uint32_t addr, uint32_t *rx_data, uint32_t rx_len);

/**
 * @brief  Read one byte for fm4428 chip
 * @param[in] dev   Sync7816 device struct
 * @param[in] addr  Address
 * @param[in] protect   1 is protect, 0 is not protect.
 * @param[out] rx_data  Data that read out from bus
 * @return 0 if successful, otherwise failed
 * */
int fm4428_read_byte(sync7816_dev_t* dev, uint32_t addr, int protect, uint8_t *rx_data);

/**
 * @brief  Send write command for fm4428 chip
 * @param[in] dev   Sync7816 device struct
 * @param[in] cmd   Command
 * @param[in] addr  Address
 * @param[in] data  Data that write to bus
 * @param[in] wait_clk Wait clock for operation finish
 * @return 0 if successful, otherwise failed
 * */
int fm4428_write_cmd(sync7816_dev_t* dev, uint32_t cmd, uint32_t addr, uint8_t data, uint32_t wait_clk);

/**
 * @brief  Write one byte for fm4428 chip
 * @param[in] dev   Sync7816 device struct
 * @param[in] addr  Address
 * @param[in] data  Data that write to bus
 * @return 0 if successful, otherwise failed
 * */
int fm4428_write_byte(sync7816_dev_t* dev, uint32_t addr, uint8_t data);


/**
 * @brief  Unlock fm4428 chip for write
 * @param[in] dev   Sync7816 device struct
 * @param[in] psc1  psc1 code
 * @param[in] psc2  psc2 code
 * @return 0 if successful, otherwise failed
 * */
int fm4428_unlock(sync7816_dev_t* dev, uint8_t psc1, uint8_t psc2);

/**
 * @brief  Send read command for fm4442 chip
 * @param[in] dev   Sync7816 device struct
 * @param[in] cmd   Command
 * @param[in] addr  Address
 * @param[out] rx_data  Data that read out from bus
 * @param[in] rx_len    Rx bit length. Max value is 16 bit.
 * @return 0 if successful, otherwise failed
 * */
int fm4442_read_cmd(sync7816_dev_t* dev, uint32_t cmd, uint32_t addr, uint32_t *rx_data, uint32_t rx_len);

/**
 * @brief  Send write command for fm4442 chip
 * @param[in] dev   Sync7816 device struct
 * @param[in] cmd   Command
 * @param[in] addr  Address
 * @param[in] data  Data that write to bus
 * @return 0 if successful, otherwise failed
 * */
int fm4442_write_cmd(sync7816_dev_t* dev, uint32_t cmd, uint32_t addr, uint8_t data);


/// @} HAL_SYNC7816
#endif
