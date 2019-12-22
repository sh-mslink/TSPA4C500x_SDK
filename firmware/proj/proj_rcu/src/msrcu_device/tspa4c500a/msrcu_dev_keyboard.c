/**
 ****************************************************************************************
 *
 * @file msrcu_dev_keyboard.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

/* Include Files
 ****************************************************************************************
 */
#include "msrcu_dev_system.h"

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
static void (*msrcu_evt_key_cb)(msrcuEvtKey_t *evt);

static osMessageQDef(msrcu_dev_kb_msg, 5, void);
static osMessageQId msrcuDevKbMsgQId;
static osThreadDef_t kbDef;
static kb_dev_t* kbDev;

static msrcuKeySt keySt[MSRCU_KEY_MATRIX_ROW_NB * MSRCU_KEY_MATRIX_COL_NB + 1];

/* Function Definition
 ****************************************************************************************
 */
static bool isKeyboardMsg(uint32_t value)
{
    if((value & (KB_MSG_BASE | (KB_MSG_PRESS << 8)))
            || (value & (KB_MSG_BASE | (KB_MSG_RELEASE << 8)))
            || (value & (KB_MSG_BASE | (KB_MSG_LONG_PRESS << 8))))
        return true;
    else
        return false;
}

msrcuErr_t msrcu_dev_keyboard_state_get(uint8_t keyCode, msrcuKeySt *st)
{
    if(keyCode > MSRCU_KEY_MATRIX_ROW_NB * MSRCU_KEY_MATRIX_COL_NB
            || keyCode == 0)
        return ERR_VALID_INPUT;
    
    if(st == NULL)
        return ERR_VALID_INPUT;
    
    *st = keySt[keyCode];
    
    return ERR_NO_ERROR;
}

static void msrcu_dev_keyboard_task(const void *arg)
{
    osEvent osEvt;
    
    while(1)
    {
        osEvt = osMessageGet(msrcuDevKbMsgQId, osWaitForever);
        if(osEvt.status != osEventMessage)
            continue;
        
        msrcuEvtKey_t* msKeyEvt = (msrcuEvtKey_t*)malloc(sizeof(msrcuEvtKey_t));
        if(msKeyEvt == NULL)
        {
            MSPRINT("ERROR: %s no memory.\r\n", __func__);
            continue;
        }
        
        if(isKeyboardMsg(osEvt.value.v))
        {
            uint32_t keycode = hal_kb_get_key_code(osEvt.value.v);
            uint32_t keyevt = hal_kb_get_key_evt(osEvt.value.v);
            
            msKeyEvt->code = keycode + 1;
            switch(keyevt)
            {
                case KB_MSG_PRESS:
                    msKeyEvt->behavior = EVT_KEY_PRESS;
                    keySt[msKeyEvt->code] = KEY_PRESSED;
                    break;
                
                case KB_MSG_RELEASE:
                    msKeyEvt->behavior = EVT_KEY_RELEASE;
                    keySt[msKeyEvt->code] = KEY_RELEASED;
                    break;
                
                case KB_MSG_LONG_PRESS:
                    msKeyEvt->behavior = EVT_KEY_LONG_PRESS;
                    keySt[msKeyEvt->code] = KEY_PRESSED;
                    break;
                
                default:
                    break;
            }
        }
        else
        {
            MSPRINT("Keyboard MSG ERROR.\r\n");
            continue;
        }
        
        msrcu_evt_key_cb(msKeyEvt);
        
        if(msKeyEvt)
            free(msKeyEvt);
    }
}

msrcuErr_t msrcu_dev_keyboard_init(uint8_t row, uint8_t col, void (*cb)(msrcuEvtKey_t *evt))
{
    msrcuErr_t err = ERR_NO_ERROR;
    
    kbDef.pthread = msrcu_dev_keyboard_task;
    kbDef.instances = 1;
    kbDef.tpriority = osPriorityNormal;
    kbDef.stacksize = MSRCU_DEV_KEYBOARD_TASK_SIZE; 
    
    osThreadId msrcuDevKbId = osThreadCreate(&kbDef, NULL);
    if(msrcuDevKbId == NULL)
        return ERR_OS;
    
    msrcuDevKbMsgQId = osMessageCreate(osMessageQ(msrcu_dev_kb_msg), NULL);
    if(msrcuDevKbMsgQId == NULL)
        return ERR_OS;
    
    for(int i = 0; i < MSRCU_KEY_MATRIX_ROW_NB * MSRCU_KEY_MATRIX_COL_NB + 1; i++)
        keySt[i] = KEY_RELEASED;
    
    kbDev = hal_kb_open(row, col, msrcuDevKbMsgQId);
    if(!kbDev)
        return ERR_DEVICE_DRIVER;
    
    hal_kb_enable(kbDev);
    
    msrcu_evt_key_cb = cb;
    
    return err;
}
