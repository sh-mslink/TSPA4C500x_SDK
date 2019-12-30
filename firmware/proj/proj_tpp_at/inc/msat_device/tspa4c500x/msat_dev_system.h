/**
 ****************************************************************************************
 *
 * @file msat_dev_system.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef MSAT_DEV_SYSTEM_H
#define MSAT_DEV_SYSTEM_H

/* Include Files
 ****************************************************************************************
 */
#include "msat_event.h"

#include ".\ble\inb_api.h"
#include "prf_tpps.h"
#include "cmsis_os.h"
#include "hal_global.h"
#include "hal_power.h"
#include "hal_timer.h"
#include "hal_gpio.h"
#include "hal_uart.h"

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
void msat_dev_system_delay_ms(uint32_t millisec);
msatErr_t msat_dev_system_data_out(uint8_t *buf, uint16_t len);
msatErr_t msat_dev_system_wakeup_out_set(void);
msatErr_t msat_dev_system_wakeup_out_clear(void);
msatErr_t msat_dev_system_init(uint8_t dev);

#endif
