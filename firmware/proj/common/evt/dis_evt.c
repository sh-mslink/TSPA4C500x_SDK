#include "in_config.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "in_arm.h"
#include "in_debug.h"
#include ".\hal\hal_uart.h"
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_power.h"
#include ".\hal\hal_adc.h"
#include ".\ble\inb_api.h"
#include ".\ble\prf\inb_prf_dis.h"

#include "cmsis_os.h"

/// Manufacturer Name Value
#define APP_DIS_MANUFACTURER_NAME       ("Tropos")
#define APP_DIS_MANUFACTURER_NAME_LEN   (6)

/// Model Number String Value
#define APP_DIS_MODEL_NB_STR            ("TSPA4C500x")
#define APP_DIS_MODEL_NB_STR_LEN        (10)

/// Serial Number
#define APP_DIS_SERIAL_NB_STR           ("0123456789")
#define APP_DIS_SERIAL_NB_STR_LEN       (10)

/// Firmware Revision
#define APP_DIS_FIRM_REV_STR            ("1.0.14")
#define APP_DIS_FIRM_REV_STR_LEN        (6)

/// System ID Value - LSB -> MSB
#define APP_DIS_SYSTEM_ID               ("\x01\x23\x45\x67\x89\xAB\xCD\xEF")
#define APP_DIS_SYSTEM_ID_LEN           (8)

/// Hardware Revision String
#define APP_DIS_HARD_REV_STR            ("1.0.0")
#define APP_DIS_HARD_REV_STR_LEN        (5)

/// Software Revision String
#define APP_DIS_SW_REV_STR              ("SDK_0.3.3")
#define APP_DIS_SW_REV_STR_LEN          (9)

/// IEEE
#define APP_DIS_IEEE                    ("\xFF\xEE\xDD\xCC\xBB\xAA")
#define APP_DIS_IEEE_LEN                (6)

/**
 * PNP ID Value - LSB -> MSB
 *      Vendor ID Source : 0x02 (USB Implementer? Forum assigned Vendor ID value)
 *      Vendor ID : 0x045E      (Microsoft Corp)
 *      Product ID : 0x0040
 *      Product Version : 0x0300
 */
#define APP_DIS_PNP_ID                  ("\x03\x04\x00\x00\x00\x00\x00")//("\x03\x00\x02\x00\x00\x04\x00")//("\x02\x5E\x04\x40\x00\x00\x03")
#define APP_DIS_PNP_ID_LEN              (7)


int handle_default_dis_evt(uint16_t eid, void *pv)
{
	int ret = -1;

#if (CFG_PRF_DISC==1) || (CFG_PRF_DISS==1)
	if((eid & 0xFF00) == DIS_EVT_CODE)
    {
		ret = 0;
		//PRINTD(DBG_TRACE, "\n%s  id 0x%x\r\n", __func__, eid);
	}

	switch(eid) 
	{
		case DISS_EVT_VALUE_REQ_IND:
        {
			evt_value_req_ind_t *ind = (evt_value_req_ind_t *)pv;
            // Initialize length
            uint8_t len = 0;
            // Pointer to the data
            uint8_t *data = NULL;
            // Check requested value
            switch(ind->value)
            {
                case INB_DIS_MANUFACTURER_NAME_CHAR:
                {
                    // Set information
                    len = APP_DIS_MANUFACTURER_NAME_LEN;
                    data = (uint8_t *)APP_DIS_MANUFACTURER_NAME;
                }
                break;
                
                case INB_DIS_MODEL_NB_STR_CHAR:
                {
                    // Set information
                    len = APP_DIS_MODEL_NB_STR_LEN;
                    data = (uint8_t *)APP_DIS_MODEL_NB_STR;
                }
                break;

                case INB_DIS_SYSTEM_ID_CHAR:
                {
                    // Set information
                    len = APP_DIS_SYSTEM_ID_LEN;
                    data = (uint8_t *)APP_DIS_SYSTEM_ID;
                }
                break;

                case INB_DIS_PNP_ID_CHAR:
                {
                    // Set information
                    len = APP_DIS_PNP_ID_LEN;
                    data = (uint8_t *)APP_DIS_PNP_ID;
                }
                break;

                case INB_DIS_SERIAL_NB_STR_CHAR:
                {
                    // Set information
                    len = APP_DIS_SERIAL_NB_STR_LEN;
                    data = (uint8_t *)APP_DIS_SERIAL_NB_STR;
                }
                break;

                case INB_DIS_HARD_REV_STR_CHAR:
                {
                    // Set information
                    len = APP_DIS_HARD_REV_STR_LEN;
                    data = (uint8_t *)APP_DIS_HARD_REV_STR;
                }
                break;

                case INB_DIS_FIRM_REV_STR_CHAR:
                {
                    // Set information
                    len = APP_DIS_FIRM_REV_STR_LEN;
                    data = (uint8_t *)APP_DIS_FIRM_REV_STR;
                }
                break;

                case INB_DIS_SW_REV_STR_CHAR:
                {
                    // Set information
                    len = APP_DIS_SW_REV_STR_LEN;
                    data = (uint8_t *)APP_DIS_SW_REV_STR;
                }
                break;

                case INB_DIS_IEEE_CHAR:
                {
                    // Set information
                    len = APP_DIS_IEEE_LEN;
                    data = (uint8_t *)APP_DIS_IEEE;
                }
                break;
                
                default:
                    //ASSERT_ERR(inp, 0);
                    PRINTD(DBG_TRACE, "diss wrong value %d \r\n", ind->value);
                break;
            }
//            PRINTD(DBG_TRACE, "diss len%d data%s\r\n", len, data);
            inb_diss_value_cfm_t *p_cfm = (inb_diss_value_cfm_t *)malloc(sizeof(inb_diss_value_cfm_t) + len);
            p_cfm->length = len;
            p_cfm->value = ind->value;
            memcpy(p_cfm->data, data, len);
            inb_diss_set_value_cfm(ind->conidx, p_cfm);
            free(p_cfm);
        }
        break;
            
		default:
		break;
	}
#endif

	return ret;
}

