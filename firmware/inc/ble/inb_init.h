/**
 ****************************************************************************************
 *
 * @file inb_init.h
 *
 * @brief BLE stack initialization functions
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef INB_INIT_H
#define INB_INIT_H

/**
 ****************************************************************************************
 * @defgroup INB_INI BLE stack initialization paramters and APIs   
 * @ingroup BLE
 * @brief  BLE stack initialization parameters and APIs
 * @{
 ****************************************************************************************
 */

#include <stdint.h>

/*
 * Structures
 ****************************************************************************************
 */

typedef struct 
{
	/// Device BD address
	uint8_t bd_addr[6];
	/// Duration of sleep and wake-up algorithm in microsecond (software time).
	///		- 0: default (200 us)
	uint16_t sleep_algo_dur;
	/// Low power clock drift in ppm: 
	///		-	0: default (500 ppm)
	uint16_t lpc_drift;
	/// Time to wake up Radio Module in microsecond:
	///		- 0: default (625 us)					
	uint16_t radio_wakeup_time;
	/// Time for stabilization of the high frequency oscillator following a sleep-timer expiry (in us)
	///		- 0: default (5000 us)
	uint16_t osc_wakeup_time;
	/// Time for stabilization of the high frequency oscillator following an external wake-up request (in us)
	///		- 0: default (5000 us)
	uint16_t ext_wakeup_time;
	/// Enable LE coded phy 500 kbps
	int coded_phy_500_en;
	/// Enable BLE deep sleep feature
	int sleep_en;
	/// 	Enable BLE deep sleep external wake-up support
	int ext_wakeup_en;
	/// Public key is valid
	int pub_key_valid;
	/// Public key
	uint8_t pub_key[64];
	/// Private key is valid
	int priv_key_valid;
	/// Private key
	uint8_t priv_key[32];
	/// BLE trace bit field:
	///		- 0: kernel messages
	///		- 1: kernel timer
	///		- 2: kernel event
	///		- 3: memory allocation and deallocation
	///		- 4: Sleep mode
	///		- 5: Software Assert
	///		- 6: Programming of the exchange table, updating of the event counter and handling of "End of Event" interrupt
	///		- 7: BLE Control structure
	///		- 8: Not used
	///		- 9: Processing of RX descriptors at each LLD driver
	///		- 10: LLCP transmission, reception and acknowledgment
	///		- 11: Not used
	///		- 12: L2CAP transmission, reception and acknowledgment
	///		- 13: Scheduling request, cancellation, shift and remove
	///		- 14: LLC state transition
	///		- 15: Not used
	///		- 16: Not used	
	///		- 17: Advertising pdu
	///		- 18: ACL pdu
	uint32_t trace_flag;

} inb_param_t;

typedef struct 
{
	/// Address of retention memory block for enviromental variables 
	uint32_t retn_mem_env_start_addr;
	/// Size of retention memory block for enviromental variables 
	uint32_t retn_mem_env_size;

	/// Address of retention memory block for data base variables (profiles)
	uint32_t retn_mem_db_start_addr;
	/// Size of retention memory block for enviromental variables 
	uint32_t retn_mem_db_size;

	/// Address of retention memory block for messages variables 
	uint32_t retn_mem_msg_start_addr;
	/// Size of retention memory block for messages variables 
	uint32_t retn_mem_msg_size;

	/// Address of non-retention memory block for temporry variables 
	uint32_t non_retn_mem_start_addr;
	/// Size of non-retention memory block for temporary variables 
	uint32_t non_retn_mem_size;

} inb_mem_t;

typedef struct 
{
	/// Retention memory usage for enviromental variables 
	uint16_t retn_mem_env_mem_usage;

	/// Retention memory usage for database variables 
	uint16_t retn_mem_db_mem_usage;

	/// Retention memory usage for messages variables 
	uint16_t retn_mem_msg_mem_usage;

	/// Non retention memory usage 
	uint16_t non_retn_mem_usage;

} inb_mem_usage_t;

/*
 * APIs
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Initialize BLE stack functions
 *
 * Application should first provide a large block of memory to the BLE stack and then call "inb_get_mem_usage"
 * to poll each block memory usage. It can then adjust the memory blocks to achieve the best memory usage. 
 *
 * @param[in] p_param				Parameters related to the platform
 * @param[in] p_mem				Allocated memory for the BLE stack  
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_init(inb_param_t *p_param, inb_mem_t *p_mem);

/**
 ****************************************************************************************
 * @brief BLE Call from the BLE isr to service interrupt
 *
 * @param[in] void					No paramters
 *
 * @return no return 
 ****************************************************************************************
 */
void inb_isr(void);

/**
 ****************************************************************************************
 * @brief Initialize BLE APIs 
 *
 * This is only for the embedded host software. For HCI based application (host on another CPU), there is
 * no need to call this function.
 *
 * @param[in] evt_cb				Call back functions for BLE stack events.  Most of the events are triggered by the
 *												peer devices.
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
int inb_api_init(void (*evt_cb)(inb_evt_t *evt));

/**
 ****************************************************************************************
 * @brief Get the memory usage of each block 
 *
 * @note The function returns the current usage of memory. It is not the max memory usage.   
 *
 * @param[out] p_mem_usage	Current memory usage for each block. 
 *
 * @return INB_ERR_NO_ERROR if successful, otherwise failed. @see enum inb_err_t 
 ****************************************************************************************
 */
void inb_get_mem_usage(inb_mem_usage_t *p_mem_usage);

/**
 ****************************************************************************************
 * @brief Get the maximum memory usage 
 *
 * @param[in] void					No paramters
 *
 * @return The maximum memory usage for the time being. 
 ****************************************************************************************
 */
uint32_t inb_get_max_mem_usage(void);

/**
 ****************************************************************************************
 * @brief Check if BLE is in the middle of transaction 
 *
 * @param[in] void					No paramters
 *
 * @return 1: BLE is busy, 0: Otherwise 
 ****************************************************************************************
 */
int inb_is_ble_busy(void);


/// @} INB_INI

#endif	/* INB_PLT_H */

