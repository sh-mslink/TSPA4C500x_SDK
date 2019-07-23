/**
 ****************************************************************************************
 *
 * @file msrcu_fw_ir.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
#ifndef MSRCU_FW_IR_H
#define MSRCU_FW_IR_H

/* Include Files
 ****************************************************************************************
 */
#include "msrcu_event.h"
#if (MSRCU_IR_SEND_ENABLE || MSRCU_IR_LEARN_ENABLE)

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
msrcuErr_t msrcu_fw_ir_init(void (*cb)(msrcuEvtIr_t *evt)); 
bool msrcu_fw_ir_is_stop(void);
#if MSRCU_IR_SEND_ENABLE
msrcuErr_t msrcu_fw_ir_send_start(msrcuIrCode_t* code);
msrcuErr_t msrcu_fw_ir_send_stop(void);
#endif
#if MSRCU_IR_LEARN_ENABLE
msrcuErr_t msrcu_fw_ir_learn_start(msrcuIrLrnIdx keyIndex);
msrcuErr_t msrcu_fw_ir_learn_stop(void);
#endif 
#endif
#endif
