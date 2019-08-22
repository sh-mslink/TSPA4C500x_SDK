#ifndef __MSG_H__
#define __MSG_H__

#include ".\ble\inb_api.h"

/*
 * Enumeration
 ****************************************************************************************
 */
enum {
	MSG_ACTV_STOP,
	//MSG_START_CONNECT,
	MSG_DISC,	
	MSG_CONNECTED,
    MSG_CON_PARAM_UPD_REQ,
    MSG_CON_PARAM_UPD,
	MSG_PAIR,
	MSG_HOGPD_NTF,
	MSG_BOND,
	MSG_TPPS_NTF,
	MSG_ATV_AUDIO_END,
	MSG_ATV_AUDIO_START,
};
/*
 * Types
 ****************************************************************************************
 */
typedef struct {
	int msg_id;
} msg_t;

//typedef struct {
//	int msg_id;
//	inb_bdaddr_t addr;
//} msg_start_connect_t;

typedef struct {
	int msg_id;
	uint8_t actv_idx;
	uint8_t actv_type;
	uint8_t reason;
	uint8_t per_adv_stop;
} msg_actv_stop_t;

typedef struct {
	int msg_id;
	int conidx;
    uint8_t reason;
} msg_disc_t;

typedef struct {
	int msg_id;
	uint8_t conidx;
	uint16_t con_interval;
	uint16_t con_latency;
	uint16_t sup_to;
	uint8_t clk_accuracy;
	uint8_t peer_addr_type;
	inb_addr_t peer_addr;
} msg_connected_t;

typedef struct {
	int msg_id;
	uint8_t conidx;
	uint16_t interval_min;
	uint16_t interval_max;
	uint16_t latency;
	uint16_t time_out;
    uint16_t ce_len_min;
    uint16_t ce_len_max;
} msg_con_param_upd_req_t;

typedef struct {
	int msg_id;
	uint8_t conidx;
	uint16_t con_interval;
	uint16_t con_latency;
	uint16_t sup_to;
} msg_con_param_upd_t;

typedef struct {
	int msg_id;
	uint8_t conidx;
	uint8_t status;
} msg_pair_t;

typedef struct {
	int msg_id;
	uint8_t conidx;
	
	/// Authentication level, @see ble_auth.
	uint8_t auth;
} msg_bond_t;

typedef struct
{
	int msg_id;
    uint8_t conIndex;
    uint8_t instance;//related to HID Report ID
    uint8_t length;
    uint8_t data[244];
}
msg_hogpd_ntf_t;

typedef struct
{
	int msg_id;
    uint8_t conIndex;
    uint8_t length;
    uint8_t data[20];
}
msg_tpps_ntf_t;

extern osMessageQId h_msg_q_id;
int msg_init(void);
int msg_put(void* msg);
msg_t* msg_get(uint32_t millisec);
msg_t* msg_free(msg_t *p_msg);

#endif
