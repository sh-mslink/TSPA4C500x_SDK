/**
 ****************************************************************************************
 *
 * @file inb_api.h
 *
 * @brief BLE APIs header file
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef INB_API_H
#define INB_API_H

#include <stdio.h>
#include <stdbool.h>

#include "cmsis_os.h"

#include ".\ble\inb_evt.h"
#include ".\ble\inb_error.h"
#include ".\ble\inb_att.h"
#include ".\ble\inb_gap.h"
#include ".\ble\inb_gap_evt.h"
#include ".\ble\inb_gatt.h"
#include ".\ble\inb_gatt_evt.h"
#include ".\ble\inb_init.h"
#include ".\ble\inb_l2cc.h"
#include ".\ble\inb_l2cc_evt.h"
#include ".\ble\inb_prf.h"
#include ".\ble\inb_sdr.h"
#include ".\ble\prf\inb_prf_bas.h"
#include ".\ble\prf\inb_prf_dis.h"
#include ".\ble\prf\inb_prf_hogp.h"
#include ".\ble\prf\inb_prf_anp.h"
#include ".\ble\prf\inb_prf_pasp.h"

#include "in_debug.h"

#endif	/* INB_API_H */
