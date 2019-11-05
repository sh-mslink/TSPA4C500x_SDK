/**
 ****************************************************************************************
 *
 * @file msrcu_fw_key.c
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
#include "msrcu_dev_keyboard.h"
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
msrcuErr_t msrcu_fw_key_state_get(uint8_t keyCode, msrcuKeySt *st)
{
    return msrcu_dev_keyboard_state_get(keyCode, st);
}

static msrcuErr_t msrcu_fw_key_matrix_init(uint8_t row, uint8_t col, void (*cb)(msrcuEvtKey_t *evt))
{
    msrcuErr_t err = ERR_DEVICE;
        
    if(row == 0 || col == 0 || cb == NULL) 
        return ERR_VALID_INPUT;
    
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500X
    err = msrcu_dev_keyboard_init(row, col, cb);
#endif
    
    return err;
}

msrcuErr_t msrcu_fw_key_init(void (*cb)(msrcuEvtKey_t *evt))
{
    return msrcu_fw_key_matrix_init(MSRCU_KEY_MATRIX_ROW_NB, MSRCU_KEY_MATRIX_COL_NB, cb);
}

msrcuErr_t msrcu_fw_key_hid_send(uint8_t conIndex, hidKeycode_t code)
{
    msrcuErr_t err = ERR_DEVICE;
    
    msrcuBleHidReport_t *report = malloc(sizeof(msrcuBleHidReport_t));
    if(!report)
        return ERR_NO_MEMORY;
    
    report->conIndex = conIndex;
    report->instance = HID_KEYCODE_INSTANCE;
    report->length = KEYCODE_HID_PKG_SIZE; 
    report->data[KEYCODE_HID_PKG_KB_IDX] = code;
    report->data[KEYCODE_HID_PKG_CD_IDX] = code >> 8;
    
#if MSRCU_DEV == MSRCU_DEV_TSPA4C500X
    err = msrcu_dev_ble_hid_send(report);
#endif
    
    free(report);
    
    return err;
}
