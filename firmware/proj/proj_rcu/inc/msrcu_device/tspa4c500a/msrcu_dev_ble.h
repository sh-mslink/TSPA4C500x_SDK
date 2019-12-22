/**
 ****************************************************************************************
 *
 * @file msrcu_dev_ble.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef MSRCU_DEV_BLE_H
#define MSRCU_DEV_BLE_H

/* Include Files
 ****************************************************************************************
 */
#include "msrcu_event.h"
#if MSRCU_BLE_VOICE_ATV_ENABLE
#include "prf_atv_task.h"
#endif

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
msrcuBleState_t msrcu_dev_ble_get_state(void);
msrcuErr_t msrcu_dev_ble_init(void (*cb)(msrcuEvtBle_t *evt));
msrcuErr_t msrcu_dev_ble_adv_start(msrcuBleAdv_t* adv);
msrcuErr_t msrcu_dev_ble_adv_stop(void);
msrcuErr_t msrcu_dev_ble_disconnect(void);
msrcuErr_t msrcu_dev_ble_hid_send(msrcuBleHidReport_t *param);

#endif
