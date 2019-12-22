/**
 ****************************************************************************************
 *
 * @file bas_evt.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#include "ble_evt.h"


#if (CFG_PRF_BASC_EN || CFG_PRF_BASS_EN)


#if BLE_EVT_BAS_TRACE
#define PRINT_BAS_EVT   PRINT_EVT
#else
#define PRINT_BAS_EVT(fmt, ...)
#endif


int handle_default_bas_evt(uint16_t eid, void *pv)
{
    int res = INB_ERR_NO_ERROR;
    
    switch(eid) 
    {
        case BASC_EVT_BATT_LEVEL_IND:
            {
                PRINT_BAS_EVT("BASC_EVT_BATT_LEVEL_IND\r\n");
                
                //inb_evt_basc_batt_level_ind_t *p = (inb_evt_basc_batt_level_ind_t *)pv;
            }
            break;
        
        case BASS_EVT_BATT_LEVEL_NTF_CFG_IND:
            {
                PRINT_BAS_EVT("BASS_EVT_BATT_LEVEL_NTF_CFG_IND\r\n");
                
                //inb_evt_bass_level_ntf_cfg_ind_t *p = (inb_evt_bass_level_ntf_cfg_ind_t *)pv;
            }
            break;
        
        default:
            {
                PRINTD(DBG_TRACE, "BAS event wrong ID: %d.\r\n", eid);
            }
            break;
    }
    
    return res;
}

#endif

