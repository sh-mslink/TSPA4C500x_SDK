/**
 ****************************************************************************************
 *
 * @file hal_oled.h
 *
 * @brief OLED Profile
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef HAL_OLED_H
#define HAL_OLED_H

/**
 ****************************************************************************************
 * @defgroup HAL_OLED OLED Profile 
 * @ingroup HAL
 * @brief  HAL OLED
 * @{
 ****************************************************************************************
 */

#include "stdint.h"
#include "in_mmap.h"

#define X_WIDTH 								128
#define Y_WIDTH 								64
#define NUM_PAGES								8
#define OLED_I2C_ADDRESS				0x3c
#define OLED_I2C_CORE						I2C1_ID
#define WR_OP_DATA							0x40
#define WR_OP_CMD								0x00

/// OLED function status return
typedef enum {
	/// No errors, good status. 
	OLED_ERR_OK = 0,
	/// Error, OLED driver not initialized
	OLED_ERR_NOT_INIT = 1,
	/// Error, OLED driver already initialized
	OLED_ERR_ALREADY_INIT = 2,	
	/// Error, OLED bad state 
	OLED_ERR_DEV_BAD_STATE = 3,
	/// Error, invalid OLED parameter. 
	OLED_ERR_INVALID_PARA = 4,
	/// Error, I2C failure. 
	OLED_ERR_I2C_FAIL = 4
} oled_result_status;	
 
/**
 ****************************************************************************************
 * @brief Initialize OLED driver.
 *
 * @param[in] i2c_driver								Pointer to i2c driver struct provided by i2c_open
 *
 * @return OLED_ERR_OK if OLED initializes successfully, error otherwise. @see enum oled_result_status.
 ****************************************************************************************
 */
int hal_oled_open(void *i2c_driver);
 
/**
 ****************************************************************************************
 * @brief De-initialize OLED driver.
 *
 * @return OLED_ERR_OK if OLED De-initializes successfully, error otherwise. @see enum oled_result_status.
 ****************************************************************************************
 */
int hal_oled_close(void);
 
/**
 ****************************************************************************************
 * @brief Turn OLED screen on or off. Pixel data remains regardless of screen state.
 *
 * @param[in] on									1 to turn screen on, 0 to turn off, error otherwise
 *
 * @return OLED_ERR_OK if OLED screen power setting is successful, error otherwise. @see enum oled_result_status.
 ****************************************************************************************
 */
int hal_oled_screen_power(uint8_t on);

/**
 ****************************************************************************************
 * @brief Draw RSSI value.
 *
 * @return OLED_ERR_OK if OLED draw is successful, error otherwise. @see enum oled_result_status.
 ****************************************************************************************
 */
int hal_oled_draw_RSSI(void);
 
/**
 ****************************************************************************************
 * @brief Clear OLED screen of pixels. OLED maintains state (on or off)
 *
 * @return OLED_ERR_OK if OLED clear screen is successful, error otherwise. @see enum oled_result_status.
 ****************************************************************************************
 */
int hal_oled_clr_screen(void);
 
/**
 ****************************************************************************************
 * @brief Draw Inplay logo on OLED.
 *
 * @return OLED_ERR_OK if OLED draw is successful, error otherwise. @see enum oled_result_status.
 ****************************************************************************************
 */
int hal_oled_draw_inplay(void);
 
/**
 ****************************************************************************************
 * @brief Set connection status.
 *
 * @param[in] isConnected					0 to set not-connected status, 1 to set connected status, otherwise error
 *
 * @return OLED_ERR_OK if OLED draw is successful, error otherwise. @see enum oled_result_status.
 ****************************************************************************************
 */
int hal_oled_set_connection_status(uint8_t isConnected);
 
/**
 ****************************************************************************************
 * @brief Draw connection status.
 *
 * @return OLED_ERR_OK if OLED draw is successful, error otherwise. @see enum oled_result_status.
 ****************************************************************************************
 */
int hal_oled_draw_connection_status(void);
 
/**
 ****************************************************************************************
 * @brief Set RSSI value.
 *
 * @param[in] val									RSSI value to be drawn on OLED. Only supports values >= -999 and values <= 999
 *
 * @return OLED_ERR_OK if OLED draw is successful, error otherwise. @see enum oled_result_status.
 ****************************************************************************************
 */
int hal_oled_set_RSSI(int16_t val);

/**
 ****************************************************************************************
 * @brief Draw RSSI value.
 *
 * @return OLED_ERR_OK if OLED draw is successful, error otherwise. @see enum oled_result_status.
 ****************************************************************************************
 */
int hal_oled_draw_RSSI(void);


/**
 ****************************************************************************************
 * @brief draw string
 *@param[in] 		x   
 @param[in] 		y   
 
 * @param[in] 		ch   string to draw
 *
 * @return OLED_ERR_OK if OLED draw is successful, error otherwise. @see enum oled_result_status.
 ****************************************************************************************
 */

int hal_oled_draw_8x16(unsigned char x, unsigned char y, char ch[]);

/**
 ****************************************************************************************
 * @brief draw symbols
 *@param[in] 		x   
 @param[in] 		y   
 
 * @param[in] 		ch   symbols to draw
 *
 * @return OLED_ERR_OK if OLED draw is successful, error otherwise. @see enum oled_result_status.
 ****************************************************************************************
 */

int hal_oled_draw_symbols_16x32(unsigned char x, unsigned char y, char ch[]) ;

#endif /* OLED_H_ */
