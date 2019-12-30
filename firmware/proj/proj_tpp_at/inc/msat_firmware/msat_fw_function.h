/**
 ****************************************************************************************
 *
 * @file msat_fw_function.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef MSAT_FW_FUNCTION_H
#define MSAT_FW_FUNCTION_H


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
msatErr_t msat_fw_function_data_in_no_cmd(char *data, uint16_t len);
msatErr_t msat_fw_function_system_reset(void);
msatErr_t msat_fw_function_mode_set(msatMode mode);
msatErr_t msat_fw_function_ble_adv_interval_set(uint16_t advIntv);
msatErr_t msat_fw_function_ble_adv_data_set(uint8_t *advData, uint16_t advLen);
msatErr_t msat_fw_function_ble_adv_onoff_set(uint8_t on);
msatErr_t msat_fw_function_ble_adv_onoff_get(uint8_t *isOn);
msatErr_t msat_fw_function_ble_con_state_set(uint8_t con);
msatErr_t msat_fw_function_ble_con_state_get(uint8_t *isCon);
msatErr_t msat_fw_function_ble_send_cfg_set(uint8_t cfg);
msatErr_t msat_fw_function_ble_send_cfg_get(uint8_t *isCfg);
msatErr_t msat_fw_function_ble_disconnect(void);

#endif
