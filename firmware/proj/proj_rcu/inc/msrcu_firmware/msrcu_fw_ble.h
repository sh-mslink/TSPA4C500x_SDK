/**
 ****************************************************************************************
 *
 * @file msrcu_fw_ble.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
#ifndef MSRCU_FW_BLE_H
#define MSRCU_FW_BLE_H

/* Include Files
 ****************************************************************************************
 */
#include "msrcu_event.h"

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
msrcuErr_t msrcu_fw_ble_init(void (*cb)(msrcuEvtBle_t *evt));
msrcuBleState_t msrcu_fw_ble_get_state(void);
//void msrcu_fw_ble_set_state(msrcuBleState_t state);
msrcuErr_t msrcu_fw_ble_adv_start(msrcuBleAdv_t* adv);
msrcuErr_t msrcu_fw_ble_adv_stop(void);
msrcuErr_t msrcu_fw_ble_disconnect(void);

#endif
