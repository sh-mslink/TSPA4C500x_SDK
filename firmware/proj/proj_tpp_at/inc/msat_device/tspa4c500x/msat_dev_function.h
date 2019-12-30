/**
 ****************************************************************************************
 *
 * @file msat_dev_funciton.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef MSAT_DEV_FUNCTION_H
#define MSAT_DEV_FUNCTION_H


/* Include Files
 ****************************************************************************************
 */

/* Macro Definition
 ****************************************************************************************
 */

/* Enum Definition
 ****************************************************************************************
 */

/* Struct Definition
 ****************************************************************************************
 */

/* Global Variable
 ****************************************************************************************
 */

/* Function Declaration
 ****************************************************************************************
 */
msatErr_t msat_dev_function_system_reset(void);
msatErr_t msat_dev_function_ble_adv_start(uint16_t interval, uint8_t *data, uint16_t len);
msatErr_t msat_dev_function_ble_adv_stop(void);
uint16_t msat_dev_function_ble_send_cfg_hdl_get(void);
uint16_t msat_dev_function_ble_rcv_val_hdl_get(void);
msatErr_t msat_dev_function_ble_send_data(uint8_t *data, uint16_t len);
msatErr_t msat_dev_function_ble_disconnect(void);

#endif
