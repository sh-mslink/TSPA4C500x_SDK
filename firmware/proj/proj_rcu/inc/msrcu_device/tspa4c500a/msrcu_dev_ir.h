/**
 ****************************************************************************************
 *
 * @file msrcu_dev_ir.h
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef MSRCU_DEV_IR_H
#define MSRCU_DEV_IR_H

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
msrcuErr_t msrcu_dev_ir_init(void (*cb)(msrcuEvtIr_t *evt), msrcuIrEnv_t *ir);
bool msrcu_dev_ir_is_stop(void);
msrcuErr_t msrcu_dev_ir_send_start(msrcuIrCode_t* code);
msrcuErr_t msrcu_dev_ir_send_stop(void);
msrcuErr_t msrcu_dev_ir_learn_start(msrcuIrLrnIdx keyIndex);
msrcuErr_t msrcu_dev_ir_learn_stop(void);

#endif
