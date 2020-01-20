/**
 ****************************************************************************************
 *
 * @file evb_button.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

/* Include Files
 ****************************************************************************************
 */
#include <stdint.h>
#include <stdbool.h>

#include "msg.h"

#include "evb_button.h"

/* Macro Definition
 ****************************************************************************************
 */
#define EVB_BUTTON_KB_TASK_SIZE 512

#define EVB_BUTTON_ROW  3
#define EVB_BUTTON_COL  5

/* Enum Definition
 ****************************************************************************************
 */

/* Struct Definition
 ****************************************************************************************
 */

/* Function Declaration
 ****************************************************************************************
 */
static void (*evb_button_evt_callback)(uint32_t *code, buttonState *behavior);

/* Global Variable
 ****************************************************************************************
 */
static osMessageQDef(devKbMsg, 5, void);
static osMessageQId devKbMsgQId;
static osThreadDef_t kbDef;
static kb_dev_t* kbDev;

static uint8_t evbButtonPressdNumber = 0;
static buttonState evbButtonState[EVB_BUTTON_ROW * EVB_BUTTON_COL] = {BUTTON_RELEASE};

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

static void evb_button_kb_task(const void *arg)
{
    osEvent osEvt;
    
    while(1)
    {
        osEvt = osMessageGet(devKbMsgQId, osWaitForever);
        if(osEvt.status != osEventMessage)
            continue;
        
        if(isKeyboardMsg(osEvt.value.v))
        {
            uint32_t keyCode = hal_kb_get_key_code(osEvt.value.v);
            uint32_t keyEvt = hal_kb_get_key_evt(osEvt.value.v);
            
            uint32_t code = keyCode + 1;///
            
            switch(keyEvt)
            {
                case KB_MSG_PRESS:
                    {
                        evbButtonState[keyCode] = BUTTON_PRESS;
                        evbButtonPressdNumber++;
                    }
                    break;
                
                case KB_MSG_RELEASE:
                    {
                        evbButtonState[keyCode] = BUTTON_RELEASE;
                        if(evbButtonPressdNumber)
                            evbButtonPressdNumber--;
                    }
                    break;
                
                case KB_MSG_LONG_PRESS:
                    {
                        evbButtonState[keyCode] = BUTTON_LONG_PRESS;
                    }
                    break;
                
                default:
                    break;
            }
            
            evb_button_evt_callback(&code, &evbButtonState[keyCode]);
        }
        else
        {
            PRINTD(DBG_TRACE, "Keyboard MSG ERROR.\r\n");
            continue;
        }
    }
}

uint8_t evb_button_get_pressd_number(void)
{
    return evbButtonPressdNumber;
}

buttonState evb_button_get_state(uint8_t code)
{
    if(code)
        return evbButtonState[code - 1];///
    else
        return BUTTON_RELEASE;
}

void evb_button_init(void (*cb)(uint32_t *code, buttonState *state))
{
    kbDef.pthread = evb_button_kb_task;
    kbDef.instances = 1;
    kbDef.tpriority = osPriorityNormal;
    kbDef.stacksize = EVB_BUTTON_KB_TASK_SIZE;
    
    osThreadId devKbId = osThreadCreate(&kbDef, NULL);
    if(devKbId == NULL)
    {
        PRINTD(DBG_TRACE, "Keyboard task create error.\r\n");
        return; 
    }
    
    devKbMsgQId = osMessageCreate(osMessageQ(devKbMsg), NULL);
    if(devKbMsgQId == NULL)
    {
        PRINTD(DBG_TRACE, "Keyboard message create error.\r\n");
        return; 
    }
    
    kbDev = hal_kb_open(EVB_BUTTON_ROW, EVB_BUTTON_COL, devKbMsgQId);
    if(!kbDev)
    {
        PRINTD(DBG_TRACE, "Keyboard open error.\r\n");
        return;
    }
    
    int res = hal_kb_enable(kbDev);
    if(res)
    {
        PRINTD(DBG_TRACE, "Keyboard_enable error: %d.\r\n", res);
        return;
    }
    
    evbButtonPressdNumber = 0;
    for(uint8_t i = 0; i < EVB_BUTTON_ROW * EVB_BUTTON_COL; i++)
        evbButtonState[i] = BUTTON_RELEASE;
    
    evb_button_evt_callback = cb;
}
