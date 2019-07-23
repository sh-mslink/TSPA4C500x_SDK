#ifndef GAP_TEST_H
#define GAP_TEST_H



#include "in_config.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "in_arm.h"
#include "in_debug.h"
#include ".\hal\hal_uart.h"
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_power.h"
#include ".\hal\hal_audio.h"
#include ".\hal\hal_adc.h"
#include ".\ble\inb_api.h"

//#include "drv_test.h"
#include "cmsis_os.h"
 

extern inb_ltk_t ble_bond_data[2];

void dump_addr(inb_bdaddr_t addr);

int handle_default_gap_evt(uint16_t eid, void *pv, void* param);






#endif
