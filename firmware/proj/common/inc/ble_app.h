#ifndef BLE_APP_H_
#define BLE_APP_H_

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

#include "msg.h"
#include "cmsis_os.h"


void ble_mem_usage_tmr_callback(void const *arg);

int start_adv(void);
int stop_adv(void);
int start_connect(inb_bdaddr_t* addr);
int create_scan(void);
int start_scan(void);
int stop_scan(void);
int discovery_service(int conIdx);

void ble_event_callback(inb_evt_t *evt);

int ble_stack_init(void);
int ble_config(bool isHciMode, void (*cb)(inb_evt_t *evt));
#if (CFG_PDT_HCI || CFG_PDT_TX)
void ble_production_test(void);
#endif
#endif
