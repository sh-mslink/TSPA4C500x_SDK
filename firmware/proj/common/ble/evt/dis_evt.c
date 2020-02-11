/**
 ****************************************************************************************
 *
 * @file dis_evt.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#include "ble_evt.h"


#if (CFG_PRF_DISC_EN || CFG_PRF_DISS_EN)


#if BLE_EVT_DIS_TRACE
#define PRINT_DIS_EVT   PRINT_EVT
#else
#define PRINT_DIS_EVT(fmt, ...)
#endif

/// Manufacturer Name Value
#define APP_DIS_MANUFACTURER_NAME       ("Tropos")
#define APP_DIS_MANUFACTURER_NAME_LEN   (6)

/// Model Number String Value
#define APP_DIS_MODEL_NB_STR            ("TSPA4C500x")
#define APP_DIS_MODEL_NB_STR_LEN        (10)

/// Serial Number
#define APP_DIS_SERIAL_NB_STR           ("0123456789")
#define APP_DIS_SERIAL_NB_STR_LEN       (10)

/// Hardware Revision String
#define APP_DIS_HARD_REV_STR            ("1.0.0")
#define APP_DIS_HARD_REV_STR_LEN        (5)

/// Firmware Revision
#define APP_DIS_FIRM_REV_STR            ("2020.02.11")
#define APP_DIS_FIRM_REV_STR_LEN        (10)

/// Software Revision String
#define APP_DIS_SW_REV_STR              ("SDK_0.7.0")
#define APP_DIS_SW_REV_STR_LEN          (9)

/// System ID Value - LSB -> MSB
#define APP_DIS_SYSTEM_ID               ("\x01\x23\x45\x67\x89\xAB\xCD\xEF")
#define APP_DIS_SYSTEM_ID_LEN           (8)

/// IEEE
#define APP_DIS_IEEE                    ("\xFF\xEE\xDD\xCC\xBB\xAA")
#define APP_DIS_IEEE_LEN                (6)

/// PNP ID Value - LSB -> MSB
///     Vendor ID Source : 1 Byte
///     Vendor ID : 2 Bytes
///     Product ID : 2 Bytes
///     Product Version : 2 Bytes
#define APP_DIS_PNP_ID                  ("\x03\x04\x00\x00\x00\x00\x00")
#define APP_DIS_PNP_ID_LEN              (7)


int handle_default_dis_evt(uint16_t eid, void *pv)
{
    int res = INB_ERR_NO_ERROR;
    
    switch(eid) 
    {
        case DISS_EVT_VALUE_REQ_IND:
            {
                PRINT_DIS_EVT("DISS_EVT_VALUE_REQ_IND\r\n");
                
                evt_value_req_ind_t *ind = (evt_value_req_ind_t *)pv;
                
                uint8_t len = 0;
                uint8_t *data = NULL;
                
                switch(ind->value)
                {
                    case INB_DIS_MANUFACTURER_NAME_CHAR:
                        {
                            PRINT_DIS_EVT("INB_DIS_MANUFACTURER_NAME_CHAR\r\n");
                            
                            len = APP_DIS_MANUFACTURER_NAME_LEN;
                            data = (uint8_t *)APP_DIS_MANUFACTURER_NAME;
                        }
                        break;
                    
                    case INB_DIS_MODEL_NB_STR_CHAR:
                        {
                            PRINT_DIS_EVT("INB_DIS_MODEL_NB_STR_CHAR\r\n");
                            
                            len = APP_DIS_MODEL_NB_STR_LEN;
                            data = (uint8_t *)APP_DIS_MODEL_NB_STR;
                        }
                        break;
                    
                    case INB_DIS_SERIAL_NB_STR_CHAR:
                        {
                            PRINT_DIS_EVT("INB_DIS_SERIAL_NB_STR_CHAR\r\n");
                            
                            len = APP_DIS_SERIAL_NB_STR_LEN;
                            data = (uint8_t *)APP_DIS_SERIAL_NB_STR;
                        }
                        break;
                    
                    case INB_DIS_HARD_REV_STR_CHAR:
                        {
                            PRINT_DIS_EVT("INB_DIS_HARD_REV_STR_CHAR\r\n");
                            
                            len = APP_DIS_HARD_REV_STR_LEN;
                            data = (uint8_t *)APP_DIS_HARD_REV_STR;
                        }
                        break;
                    
                    case INB_DIS_FIRM_REV_STR_CHAR:
                        {
                            PRINT_DIS_EVT("INB_DIS_FIRM_REV_STR_CHAR\r\n");
                            
                            len = APP_DIS_FIRM_REV_STR_LEN;
                            data = (uint8_t *)APP_DIS_FIRM_REV_STR;
                        }
                        break;
                    
                    case INB_DIS_SW_REV_STR_CHAR:
                        {
                            PRINT_DIS_EVT("INB_DIS_SW_REV_STR_CHAR\r\n");
                            
                            len = APP_DIS_SW_REV_STR_LEN;
                            data = (uint8_t *)APP_DIS_SW_REV_STR;
                        }
                        break;
                    
                    case INB_DIS_SYSTEM_ID_CHAR:
                        {
                            PRINT_DIS_EVT("INB_DIS_SYSTEM_ID_CHAR\r\n");
                            
                            len = APP_DIS_SYSTEM_ID_LEN;
                            data = (uint8_t *)APP_DIS_SYSTEM_ID;
                        }
                        break;
                    
                    case INB_DIS_IEEE_CHAR:
                        {
                            PRINT_DIS_EVT("INB_DIS_IEEE_CHAR\r\n");
                            
                            len = APP_DIS_IEEE_LEN;
                            data = (uint8_t *)APP_DIS_IEEE;
                        }
                        break;
                    
                    case INB_DIS_PNP_ID_CHAR:
                        {
                            PRINT_DIS_EVT("INB_DIS_PNP_ID_CHAR\r\n");
                            
                            len = APP_DIS_PNP_ID_LEN;
                            data = (uint8_t *)APP_DIS_PNP_ID;
                        }
                        break;
                    
                    default:
                        break;
                }
                
                inb_diss_value_cfm_t *p_cfm = (inb_diss_value_cfm_t *)malloc(sizeof(inb_diss_value_cfm_t) + len);
                if(!p_cfm)
                    return INB_PLT_ERR_NO_MEM;
                p_cfm->length = len;
                p_cfm->value = ind->value;
                memcpy(p_cfm->data, data, len);
                res = inb_diss_set_value_cfm(ind->conidx, p_cfm);
                if(p_cfm)
                    free(p_cfm);
                if(res)
                    return res;
            }
            break;
        
        default:
            {
                PRINTD(DBG_TRACE, "DIS event wrong ID: %d.\r\n", eid);
            }
            break;
    }
    
    return res;
}

#endif

