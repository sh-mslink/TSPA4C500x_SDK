/**
 ****************************************************************************************
 *
 * @file msrcu_dev_audio.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef MSRCU_DEV_AUDIO_H
#define MSRCU_DEV_AUDIO_H

/* Include Files
 ****************************************************************************************
 */
#include "msrcu_event.h"
#if MSRCU_VOICE_ENABLE

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
msrcuErr_t msrcu_dev_audio_init(void);
#if MSRCU_BLE_VOICE_ATV_ENABLE
msrcuErr_t msrcu_dev_audio_atv_start(void);
#endif
msrcuErr_t msrcu_dev_audio_start(void);
msrcuErr_t msrcu_dev_audio_stop(void);
#endif

#endif 
