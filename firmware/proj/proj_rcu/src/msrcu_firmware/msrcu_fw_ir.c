/**
 ****************************************************************************************
 *
 * @file msrcu_fw_ir.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
/* Include Files
 ****************************************************************************************
 */
#include "msrcu_config.h"
#if (MSRCU_IR_SEND_ENABLE || MSRCU_IR_LEARN_ENABLE)
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500A
#include "msrcu_dev_system.h"
#include "msrcu_dev_ir.h"
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

/* Function Declaration
 ****************************************************************************************
 */

/* Global Variable
 ****************************************************************************************
 */
 
/* Function Definition
 ****************************************************************************************
 */
msrcuErr_t msrcu_fw_ir_init(void (*cb)(msrcuEvtIr_t *evt))
{   
    msrcuErr_t err = ERR_DEVICE;
    msrcuIrEnv_t ir = {0};
    
#if MSRCU_IR_SEND_ENABLE
    ir.necCarrierDutyRatio = MSRCU_IR_NEC_CARRIER_DUTY_RATIO;
    ir.irSendPort = MSRCU_DEV_IR_SEND_GPIO_PORT;
    ir.irSendPin = MSRCU_DEV_IR_SEND_GPIO_PIN;
#endif    
#if MSRCU_IR_LEARN_ENABLE
    ir.irLearnPort = MSRCU_DEV_IR_LEARN_GPIO_PORT;
    ir.irLearnPin = MSRCU_DEV_IR_LEARN_GPIO_PIN;
    ir.irLearnCodeNb = MSRCU_IR_LEARN_NB;
#endif
    
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500A    
    ir.baseClock = CFG_D2_CLK / 1000000;//MHz
    err = msrcu_dev_ir_init(cb, &ir);
#endif
    
    return err;
}

bool msrcu_fw_ir_is_stop(void)
{
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500A
    return msrcu_dev_ir_is_stop();
#else    
    return true;
#endif
}

#if MSRCU_IR_SEND_ENABLE
msrcuErr_t msrcu_fw_ir_send_start(msrcuIrCode_t* code)
{    
    msrcuErr_t err = ERR_DEVICE;
    
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500A
    err = msrcu_dev_ir_send_start(code);
#endif
    
    return err;
}

msrcuErr_t msrcu_fw_ir_send_stop(void)
{    
    msrcuErr_t err = ERR_DEVICE;
    
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500A
    err = msrcu_dev_ir_send_stop();
#endif
    
    return err;
}
#endif

#if MSRCU_IR_LEARN_ENABLE
msrcuErr_t msrcu_fw_ir_learn_start(msrcuIrLrnIdx keyIndex)
{    
    msrcuErr_t err = ERR_DEVICE;
    
    if(keyIndex > MSRCU_IR_LEARN_NB)
        return ERR_VALID_INPUT;
    
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500A
    err = msrcu_dev_ir_learn_start(keyIndex);
#endif
    
    return err;
}

msrcuErr_t msrcu_fw_ir_learn_stop(void)
{    
    msrcuErr_t err = ERR_DEVICE;
    
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500A
    err = msrcu_dev_ir_learn_stop();
#endif
    
    return err;
}
#endif
#endif
