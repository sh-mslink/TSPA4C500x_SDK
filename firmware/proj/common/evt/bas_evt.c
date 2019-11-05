#include "in_config.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "in_arm.h"
#include "in_debug.h"
#include ".\hal\hal_uart.h"
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_power.h"
#include ".\hal\hal_adc.h"
#include ".\ble\inb_api.h"
#include ".\ble\prf\inb_prf_bas.h"

#include "cmsis_os.h"

int handle_default_bas_evt(uint16_t eid, void *pv)
{
    int ret = -1;
    
#if (CFG_PRF_BASC_EN) || (CFG_PRF_BASS_EN)
    if((eid & 0xFF00) == BAS_EVT_CODE)
    {
        ret = 0;
        //PRINTD(DBG_TRACE, "\n%s  id 0x%x\r\n", __func__, eid);
    }
    
    switch(eid)
    {
        default:
        break;
    }
#endif
    
    return ret;
}
