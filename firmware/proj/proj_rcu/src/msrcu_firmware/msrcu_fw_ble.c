/**
 ****************************************************************************************
 *
 * @file msrcu_fw_ble.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
 
/* Include Files
 ****************************************************************************************
 */
#include "msrcu_config.h"
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500X
#include "msrcu_dev_ble.h"
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
msrcuErr_t msrcu_fw_ble_init(void (*cb)(msrcuEvtBle_t *evt))
{
    msrcuErr_t err = ERR_DEVICE;  
    
    if(!cb)
        return ERR_VALID_INPUT;
    
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500X
    err = msrcu_dev_ble_init(cb);
#endif
    
    return err;
}

msrcuBleState_t msrcu_fw_ble_get_state(void)
{
    return msrcu_dev_ble_get_state();
}

//void msrcu_fw_ble_set_state(msrcuBleState_t state)
//{
//    msrcu_dev_ble_set_state(state);
//}

msrcuErr_t msrcu_fw_ble_adv_start(msrcuBleAdv_t* adv)
{
    msrcuErr_t err = ERR_DEVICE;
    
    if(!adv)
        return ERR_VALID_INPUT;
    
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500X
    err = msrcu_dev_ble_adv_start(adv);
#endif
    
    return err;
}

msrcuErr_t msrcu_fw_ble_adv_stop(void)
{
    msrcuErr_t err = ERR_DEVICE;

#if MSRCU_DEV == MSRCU_DEV_TSPA4C500X
    err = msrcu_dev_ble_adv_stop();
#endif
    
    return err;
}

msrcuErr_t msrcu_fw_ble_disconnect(void)
{
    msrcuErr_t err = ERR_DEVICE;

#if MSRCU_DEV == MSRCU_DEV_TSPA4C500X
    err = msrcu_dev_ble_disconnect();
#endif
    
    return err;
}
