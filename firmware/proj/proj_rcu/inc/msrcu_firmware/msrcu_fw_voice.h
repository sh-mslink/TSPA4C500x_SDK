/**
 ****************************************************************************************
 *
 * @file msrcu_fw_voice.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
#ifndef MSRCU_FW_VOICE_H
#define MSRCU_FW_VOICE_H

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
msrcuErr_t msrcu_fw_voice_init(void); 
bool msrcu_fw_voice_is_stop(void);
msrcuErr_t msrcu_fw_voice_start(void);
msrcuErr_t msrcu_fw_voice_stop(void);
 
#endif 
#endif