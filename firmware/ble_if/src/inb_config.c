/**
 ****************************************************************************************
 *
 * @file inb_para.c
 *
 * @brief BLE global parameters source code 
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 *
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "in_config.h"

#include "stdint.h"
#include "string.h"
#include "stdbool.h"

#include "..\inc\inb_config.h"
#include "cmsis_os.h"
/*
 * TYPES DEFINE
 ****************************************************************************************
 */


/*
 * EXTERNAL FUNCTION
 ****************************************************************************************
 */


/*
 * GLOBAL VARIABLES
 ****************************************************************************************
 */
#if CFG_HCI
static bool hciEnable = false;
#endif
/*
 * BLE PARAMETERS
 ****************************************************************************************
 */

/*
 * FUNCTIONS
 ****************************************************************************************
 */
#if CFG_HCI
void hci_enable(void)
{
    hciEnable = true;
}

bool isHciEnable(void)
{
    return hciEnable;
}
#endif

int get_ble_activity_max(void)
{
	return BLE_ACTIVITY_MAX;	
} 

int get_gapm_actv_nb(void)
{
	return BLE_ACTIVITY_MAX;
}

int get_em_ble_rx_desc_nb(void)
{
	return BLE_RX_DESC_NB;
}

int get_em_ble_datarxbuf_nb(void)
{
	return BLE_DATA_BUF_NB_RX;
}

int get_em_ble_tx_desc_nb(void)
{
	return BLE_TX_DESC_NB;
}

int get_em_sdr_cs_nb(void)
{
#if CFG_SDR
	return CFG_SDR_NB_CS;
#else
	return 0;
#endif
}

int get_em_sdr_ptr_nb(void)
{
#if CFG_SDR
	return CFG_SDR_NB_PTR;
#else
	return 0;
#endif
}

int get_em_sdr_tx_desc_nb(void)
{
#if CFG_SDR
	return CFG_SDR_NB_TX_DESC;
#else
	return 0;
#endif
}

int get_em_ble_llcptxbuf_nb(void)
{
	return BLE_LLCPTXBUF_NB;
}

int get_em_ble_advdatatxbuf_nb(void)
{
	return BLE_ADV_BUF_NB_TX;
}


int get_em_ble_acltxbuf_nb(void)
{
	return BLE_ACL_BUF_NB_TX;
}

int get_ble_whitelist_max(void)
{
	return BLE_WHITELIST_MAX;
}

int get_ble_resol_addr_list_max(void)
{
	return BLE_RESOL_ADDR_LIST_MAX;
}

int get_ble_normal_win_size(void)
{
/// Normal Rx window size (in us)
	return BLE_NORMAL_WIN_SIZE;
}

int get_ble_phy_coded_normal_win_size(void)
{
	return BLE_PHY_CODED_NORMAL_WIN_SIZE;
}

int get_ble_duplicate_filter_max(void)
{
#if (BLE_OBSERVER)
	return BLE_DUPLICATE_FILTER_MAX;
#else
	return 0;
#endif
}

int get_ble_ch_assess_rssi_interf_thr(void)
{
	return BLE_CH_ASSESS_RSSI_INTERF_THR;
}

int get_ble_ch_map_update_period(void)
{
	return BLE_CH_MAP_UPDATE_PERIOD;
}

int get_ble_ch_assess_valid_to(void)
{
	return BLE_CH_ASSESS_VALID_TO;
}

int get_ble_ch_reassess_to(void)
{
	return BLE_CH_REASSESS_TO;
}

int get_ble_ch_assess_count_max(void)
{
	return BLE_CH_ASSESS_COUNT_MAX;
}

int get_ble_ch_assess_count_thr_bad(void)
{
	return BLE_CH_ASSESS_COUNT_THR_BAD;
}

int get_ble_ch_assess_count_min(void)
{
	return BLE_CH_ASSESS_COUNT_MIN;
}

int get_l2cc_idx_max(void)
{
	return BLE_CONNECTION_MAX;
}

int get_gattc_idx_max(void)
{
	return BLE_CONNECTION_MAX;
}

int get_ble_connection_max(void)
{
	return BLE_CONNECTION_MAX;
}

uint16_t get_task_max(void)
{
	return TASK_MAX;
}

int get_ble_observer(void)
{
	return BLE_OBSERVER;
}

int get_ble_central(void)
{
	return BLE_CENTRAL;
}

int get_ble_peripheral(void)
{
	return BLE_PERIPHERAL;
}

int get_ble_broadcaster(void)
{
	return BLE_BROADCASTER;
}

int get_ble_atts(void)
{
	return BLE_ATTS;
}

int get_ble_attc(void)
{
	return BLE_ATTC;
}

int get_ble_l2cc(void)
{
	return BLE_L2CC;
}

int get_ble_smpc(void)
{
	return BLE_SMPC;
}

int get_ble_lecb(void)
{
	return BLE_LECB;
}

int get_secure_connections(void)
{
	return SECURE_CONNECTIONS;
}

int get_hz32000(void)
{
	return HZ32000;
}

int get_hci_nb_cmd_pkts(void)
{
	return HCI_NB_CMD_PKTS;
}

int get_ble_prf_max(void)
{
	return CFG_NB_PRF;
}

int get_ble_mesh(void)
{
#ifdef CFG_BLE_MESH
	return 1;
#else
	return 0;
#endif
}

int get_sdr(void)
{
	return CFG_SDR;
}

int get_app_main_task(void)
{
#if CFG_HCI
    if(isHciEnable())
        return 4; /// AHI task number
    else
        return 3; /// embedded task number
#else
	return 3; /// embedded task number
#endif
}

int get_ble_isr_task_stk_size(void)
{
	return CFG_OS_BLE_ISR_TASK_STACK_SIZE/*CFG_BLE_ISR_TASK_STKSIZE*/;
}

int get_ble_isr_task_prio(void)
{
	return CFG_OS_BLE_ISR_TASK_PRIO/*CFG_BLE_ISR_TASK_PRIO*/;
}

int get_ble_task_stk_size(void)
{
	return CFG_OS_BLE_STACK_TASK_STACK_SIZE/*CFG_BLE_TASK_STKSIZE*/;
}

int get_ble_task_prio(void)
{
	return CFG_OS_BLE_STACK_TASK_PRIO/*CFG_BLE_TASK_PRIO*/;
}

int get_ble_evt_task_stk_size(void)
{
	return CFG_OS_BLE_EVT_TASK_STACK_SIZE/*CFG_BLE_EVT_TASK_STKSIZE*/;
}

int get_ble_evt_task_prio(void)
{
	return CFG_OS_BLE_EVT_TASK_PRIO/*CFG_BLE_EVT_TASK_PRIO*/;
}

int get_ble_hci_task_stk_size(void)
{
	return CFG_OS_BLE_HCI_TASK_STACK_SIZE/*CFG_BLE_HCI_TASK_STKSIZE*/;
}

int get_ble_hci_task_prio(void)
{
	return CFG_OS_BLE_HCI_TASK_PRIO/*CFG_BLE_HCI_TASK_PRIO*/;
}

uint32_t get_ble_max_sleep_duration(void)
{
	return CFG_BLE_PARAM_MAX_SLEEP_DURATION_TIME;
}

uint32_t get_ble_adv_frag_size_tx(void)
{
	return BLE_ADV_FRAG_SIZE_TX;	
}

uint32_t get_ble_adv_frag_nb_tx(void)
{
	return BLE_ADV_FRAG_NB_TX;	
}

uint32_t get_em_ble_advdatatxbuf_size(void)
{

	return (BLE_ADV_FRAG_NB_TX*BLE_ADV_FRAG_SIZE_TX);

}

uint8_t get_em_ble_txdesc_index(int act_id, int idx)
{
	return EM_BLE_TXDESC_INDEX(act_id, idx);	
}

uint32_t get_ble_prefetch_time_us(void)
{
	return BLE_PREFETCH_TIME_US/*CFG_BLE_PREFETCH_TIME_US*/;
}

uint32_t get_ble_prefetchabort_time_us(void)
{
	return BLE_PREFETCHABORT_TIME_US/*CFG_BLE_PREFETCHABORT_TIME_US*/;
}

uint32_t get_ble_reservation_time_margin_hus(void)
{
	return BLE_RESERVATION_TIME_MARGIN_HUS;
}

uint32_t get_lld_prog_delay(void)
{
	return LLD_PROG_DELAY/*CFG_LLD_PROG_DELAY*/;
}

uint32_t get_llc_proc_switch_instant_delay(void)
{
	return LLC_PROC_SWITCH_INSTANT_DELAY/*CFG_LLC_PROC_SWITCH_INSTANT_DELAY*/;
}

int get_ble_adv_no_delay(void)
{
	return CFG_BLE_ADV_NO_DELAY_EN;
}

