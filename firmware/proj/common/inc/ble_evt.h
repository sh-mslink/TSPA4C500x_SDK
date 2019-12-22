/**
 ****************************************************************************************
 *
 * @file ble_evt.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef BLE_EVT_H
#define BLE_EVT_H


#include "in_config.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "in_arm.h"
#include "in_debug.h"
#include ".\ble\inb_api.h"
#include "cmsis_os.h"
#include "msg.h"

#include "prf_tppc.h"
#include "prf_tpps.h"
#include "prf_otas.h"


#define BLE_EVT_TRACE   (1)

#if (CFG_DBG_IF_UART && BLE_EVT_TRACE)
#define PRINT_EVT(fmt, ...) do                                      \
                            {                                       \
                                if(DBG_TRACE & CFG_DBG_FLAG)        \
                                    printf(fmt,  ##__VA_ARGS__);    \
                            }                                       \
                            while(0)
#else
#define PRINT_EVT(fmt, ...)
#endif

#define BLE_EVT_GAP_TRACE   (1)
#define BLE_EVT_GATT_TRACE  (0)
#define BLE_EVT_BAS_TRACE   (0)
#define BLE_EVT_DIS_TRACE   (0)
#define BLE_EVT_HOGP_TRACE  (0)


extern inb_ltk_t gBondData;


int handle_default_gap_evt(uint16_t eid, void *pv);
int handle_default_gatt_evt(uint16_t eid, void *pv);
#if (CFG_PRF_BASC_EN || CFG_PRF_BASS_EN)
int handle_default_bas_evt(uint16_t eid, void *pv);
#endif
#if (CFG_PRF_DISC_EN || CFG_PRF_DISS_EN)
int handle_default_dis_evt(uint16_t eid, void *pv);
#endif
#if (CFG_PRF_HOGPBH_EN || CFG_PRF_HOGPRH_EN || CFG_PRF_HOGPD_EN)
int handle_default_hogp_evt(uint16_t eid, void *pv);
#endif

#endif
