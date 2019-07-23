#ifndef BLE_TEST_H_
#define BLE_TEST_H_

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

//nclude "drv_test.h"
#include "msg.h"
#include "cmsis_os.h"

#if (CFG_FPGA==1)
#define BLE_MEM_ENV				(8 * 1024)
#define BLE_MEM_DB				(4 * 1024)
#define BLE_MEM_MSG				(8 * 1024)
#define BLE_MEM_NON_RTN		    (4 * 1024)
#else
#define BLE_MEM_ENV				(4 * 1024)
#define BLE_MEM_DB				(2 * 1024)
#define BLE_MEM_MSG				(4 * 1024)
#define BLE_MEM_NON_RTN		    (2 * 1024)
#endif

static const uint8_t bd_address[6] = {0x14, 0x11, 0x11, 0x11, 0x11, 0x11};
static const uint8_t peer_address[6] = {0xE0,0xE3,0x08,0xDC,0x1B,0x00};

/*
 * Global Variables
 ****************************************************************************************
 */

enum {
    GAP_BOND_DATA = 0,
    GAP_BOND_PEER_DATA = 1,
};

union test_cmd {

	struct test {
		uint32_t oper:2;
		uint32_t ch:6;
		uint32_t tx_len:8;
		uint32_t tx_pld:3;
		uint32_t phy:4;
		uint32_t midx:2;
	} u;
		
	uint32_t val;
};

//For L2CC
struct _l2cc_lecb_info_ {
	/// LE Protocol/Service Multiplexer
	uint16_t le_psm;
	/// Peer Channel identifier
	uint16_t cid;
	///  Credit for the LE Credit Based Connection
	uint16_t credit;
	/// Maximum SDU size
	uint16_t mtu;
	/// Maximum Packet size
	uint16_t mps;
};
struct _l2cc_test_env_{
	struct _l2cc_lecb_info_ local;
	struct _l2cc_lecb_info_ peer;
};

void ble_mem_usage_tmr_callback(void const *arg);

int start_adv(void);
int stop_adv(void);
int create_init(int *pActv_idx);
int start_init(int actv_idx);
int create_scan(void);
int start_scan(void);

void ble_event_callback(inb_evt_t *evt);

int ble_test(void);
int ble_stack_init(void);
int ble_config(int role);
void handle_default_msg(msg_t *p_msg);
int handle_default_gatt_evt(uint16_t eid, void* pv, void* param);
int handle_default_l2cc_evt(uint16_t eid, void* pv, void* param);

#endif
