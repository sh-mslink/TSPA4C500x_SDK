#include <stdlib.h>

#include ".\ble\inb_api.h"
#include "inb_config.h"
#include "rf_int.h"
#include "hal_global.h"
#include "ble_app.h"
#include "ble_evt.h"
#include "msg.h"
#include "cmsis_os.h"
#if CFG_FW_UPD_EN
#include "prf_otas.h"
#endif
#include "prf_tppc.h"
#include "prf_tpps.h"
#ifdef MSRCU
#include "msrcu_app.h"
#endif


void (*ble_app_evt_cb)(inb_evt_t *evt);

#if CFG_BLE_STK_MEM_USAGE_PRF_EN
static void ble_pf_mem_tmr_callback(void const *arg);
osTimerDef(ble_pf_mem, ble_pf_mem_tmr_callback);
#endif

static uint8_t ble_mem_env[CFG_BLE_STK_ENV_MEM_SIZE]__attribute__((aligned (4)));
static uint8_t ble_mem_db[CFG_BLE_STK_DB_MEM_SIZE]__attribute__((aligned (4)));
static uint8_t ble_mem_msg[CFG_BLE_STK_MSG_MEM_SIZE]__attribute__((aligned (4)));
static uint8_t ble_mem_non_rtn[CFG_BLE_STK_NON_RETN_MEM_SIZE] __attribute__((section("non_retn")))__attribute__((aligned (4)));

static int advActvIdx = 0;
static int scanActvIdx = 0;
static int connectActvIdx = 0;


#if CFG_BLE_STK_MEM_USAGE_PRF_EN
static void ble_pf_mem_tmr_callback(void const *arg)
{
    int max_usage;
    inb_mem_usage_t mem_usage;
    
    inb_get_mem_usage(&mem_usage);
    max_usage = inb_get_max_mem_usage();
    
    PRINTD(DBG_TRACE, "[Ble Mem Prf]: --- env = %d, db = %d, msg = %d, non retn = %d, max = %d ---\r\n", mem_usage.retn_mem_env_mem_usage, mem_usage.retn_mem_db_mem_usage, mem_usage.retn_mem_msg_mem_usage, mem_usage.non_retn_mem_usage, max_usage);
    if(mem_usage.retn_mem_env_mem_usage > CFG_BLE_STK_ENV_MEM_SIZE)
        PRINTD(DBG_ERR, "[Ble Mem Prf]: env mem overflow  max:%d used:%d\n",CFG_BLE_STK_ENV_MEM_SIZE, mem_usage.retn_mem_env_mem_usage);
    if(mem_usage.retn_mem_db_mem_usage > CFG_BLE_STK_DB_MEM_SIZE)
        PRINTD(DBG_ERR, "[Ble Mem Prf]: db mem overflow  max:%d used:%d\n",CFG_BLE_STK_DB_MEM_SIZE, mem_usage.retn_mem_db_mem_usage);
    if(mem_usage.retn_mem_msg_mem_usage > CFG_BLE_STK_MSG_MEM_SIZE)
        PRINTD(DBG_ERR, "[Ble Mem Prf]: msg mem overflow  max:%d used:%d\n",CFG_BLE_STK_MSG_MEM_SIZE, mem_usage.retn_mem_msg_mem_usage);
    if(mem_usage.non_retn_mem_usage > CFG_BLE_STK_NON_RETN_MEM_SIZE)
        PRINTD(DBG_ERR, "[Ble Mem Prf]: non retn mem overflow  max:%d used:%d\n",CFG_BLE_STK_NON_RETN_MEM_SIZE, mem_usage.non_retn_mem_usage);
    
    int cfg_max_size = CFG_BLE_STK_ENV_MEM_SIZE + CFG_BLE_STK_DB_MEM_SIZE + CFG_BLE_STK_MSG_MEM_SIZE + CFG_BLE_STK_NON_RETN_MEM_SIZE;
    if(max_usage > cfg_max_size)
        PRINTD(DBG_ERR, "[Ble Mem Prf]: max_usage mem overflow  max:%d used:%d\n",cfg_max_size, max_usage);
}
#endif

int start_adv(void)
{
    int res = INB_ERR_NO_ERROR;
    inb_actv_create_t advCreate = {0};
    inb_actv_start_t advStart = {0};
    
    uint8_t advData[] = 
    {
        0x02,//AD Element Length
        0x0A,//AD Type: Transmit Power
        0x00,//AD Data: 0dBm
    };
    uint8_t scanRspData[] = 
    {
#if (CFG_PRF_TPPS_EN)
        0x0B,//AD Element Length
        0x08,//AD Type: Shortened local name
        'T','r','o','p','o','s',' ','T','P','P',//AD Data Bytes: "Tropos TPP"
#else
        0x07,//AD Element Length
        0x08,//AD Type: Shortened local name
        'T','r','o','p','o','s',//AD Data Bytes: "Tropos"
#endif
    };
    
    /// Create activity
    advCreate.option = 0;
    advCreate.own_addr_type = 0;
    advCreate.adv_param.type = ADV_TYPE_LEGACY;
    advCreate.adv_param.disc_mode = ADV_MODE_GEN_DISC;
    advCreate.adv_param.prop = ADV_PROP_UNDIR_CONN;
    advCreate.adv_param.max_tx_pwr = 0;
    advCreate.adv_param.filter_pol = ADV_FILT_ALLOW_SCAN_ANY_CON_ANY;
    advCreate.adv_param.prim_cfg.adv_intv_min = 0x20;
    advCreate.adv_param.prim_cfg.adv_intv_max = 0x20;
    advCreate.adv_param.prim_cfg.chnl_map = CHANNEL_37|CHANNEL_38|CHANNEL_39;
    advCreate.adv_param.prim_cfg.phy = PHY_LE_1MBPS;
    res = inb_actv_create(&advCreate, &advActvIdx);
    if(res)
    {
        PRINTD(DBG_ERR, "adv inb_actv_create failed: 0x%X.\r\n", res);
        return res;
    }
    
    /// Set advertising data
    res = inb_actv_data(advActvIdx, 0, advData, sizeof(advData));
    if(res)
    {
        PRINTD(DBG_ERR, "adv inb_actv_data0 failed: 0x%X.\r\n", res);
        return res;
    }
    
    /// Set scan response data
    res = inb_actv_data(advActvIdx, 1, scanRspData, sizeof(scanRspData));
    if(res)
    {
        PRINTD(DBG_ERR, "adv inb_actv_data1 failed: 0x%X.\r\n", res);
        return res;
    }
    
    /// Start activity
    advStart.option = 0;
    advStart.u.adv_param.duration = 0;
    advStart.u.adv_param.max_adv_evt = 0;
    res = inb_actv_start(advActvIdx, &advStart);
    if(res)
    {
        PRINTD(DBG_ERR, "adv inb_actv_start failed: 0x%X.\r\n", res);
        return res;
    }
    else
        PRINTD(DBG_ERR, "Advertising start.\r\n");
    
    return res;
}

int stop_adv(void)
{
    int res = INB_ERR_NO_ERROR;
    
    res = inb_actv_stop(advActvIdx);
    if(res)
    {
        PRINTD(DBG_ERR, "adv inb_actv_stop failed: 0x%X.\r\n", res);
        return res;
    }
    else
        PRINTD(DBG_ERR, "Advertising stop.\r\n");
    
    return res;
}

int start_scan(void)
{
    int res = INB_ERR_NO_ERROR;
    inb_actv_create_t scanCreate = {0};
    inb_actv_start_t scanStart = {0};
    
    /// Create activity
    scanCreate.option= 1;
    scanCreate.own_addr_type = 0;
    res = inb_actv_create(&scanCreate, &scanActvIdx);
    if(res)
    {
        PRINTD(DBG_ERR, "scan inb_actv_create failed: 0x%X.\r\n", res);
        return res;
    }
    
    /// Start activity
    memset(&scanStart, 0, sizeof(inb_actv_start_t));
    scanStart.option= 1;
    scanStart.u.scan_param.type = CONN_DISC;
    scanStart.u.scan_param.prop = SCAN_PROP_PHY_1M | SCAN_PROP_ACTIVE_1M;
    scanStart.u.scan_param.scan_param_1m.scan_intv = 16;
    scanStart.u.scan_param.scan_param_1m.scan_wd = 8;
    scanStart.u.scan_param.dup_filt_pol = DUPLIC_DIS;
    res = inb_actv_start(scanActvIdx, &scanStart);
    if(res)
    {
        PRINTD(DBG_ERR, "scan inb_actv_start failed: 0x%X.\r\n", res);
        return res;
    }
        PRINTD(DBG_ERR, "Scanning start.\r\n");
    
    return res;
}

int stop_scan(void)
{
    int res = INB_ERR_NO_ERROR;
    
    res = inb_actv_stop(scanActvIdx);
    if(res)
    {
        PRINTD(DBG_ERR, "scan inb_actv_stop failed: 0x%X.\r\n", res);
        return res;
    }
    else
        PRINTD(DBG_ERR, "Scanning stop.\r\n");
    
    return res;
}

int start_connect(inb_bdaddr_t* addr)
{
    int res = INB_ERR_NO_ERROR;
    inb_actv_create_t connectCreate = {0};
    inb_actv_start_t connectStart = {0};
    
    /// Create activity
    connectCreate.option = 2;
    connectCreate.own_addr_type = 0;
    res = inb_actv_create(&connectCreate, &connectActvIdx);
    if(res)
    {
        PRINTD(DBG_ERR, "connect inb_actv_create failed: 0x%X.\r\n", res);
        return res;
    }
    
    /// Start activity
    connectStart.option = 2;
    connectStart.u.init_param.type = INIT_TYPE_DIRECT_CONN_EST;
    connectStart.u.init_param.prop = INIT_PROP_1M;
    connectStart.u.init_param.conn_tmo = 0;
    
    connectStart.u.init_param.scan_param_1m.scan_intv = 16;
    connectStart.u.init_param.scan_param_1m.scan_wd = 8;
    connectStart.u.init_param.conn_param_1m.conn_intv_min = 32;
    connectStart.u.init_param.conn_param_1m.conn_intv_max = 32;
    connectStart.u.init_param.conn_param_1m.conn_latency = 0;
    connectStart.u.init_param.conn_param_1m.supervision_to = 500;
    connectStart.u.init_param.conn_param_1m.ce_len_min = 0x0000;
    connectStart.u.init_param.conn_param_1m.ce_len_max = 0x0001;
    
    memcpy(&connectStart.u.init_param.peer_addr, addr, sizeof(inb_bdaddr_t));
    
    res = inb_actv_start(connectActvIdx, &connectStart);
    if(res)
    {
        PRINTD(DBG_ERR, "connnect inb_actv_start failed: 0x%X.\r\n", res);
        return res;
    }
    else
        PRINTD(DBG_ERR, "Connect start.\r\n");
    
    return res;
}

int discovery_service(int conIdx)
{
    int res = INB_ERR_NO_ERROR;
    
    inb_gatt_disc_t *p_read = (inb_gatt_disc_t*)malloc(sizeof(inb_gatt_disc_t));
    
    if(p_read)
    {
        memset(p_read, 0, sizeof(inb_gatt_disc_t));
        
        p_read->start_hdl = 0x0001;
        p_read->end_hdl = 0xffff;
    
        res = inb_gatt_discovery(conIdx, GATT_DISC_ALL_SVC, p_read);
//        if(res)
//            PRINTD(DBG_ERR, "inb_gatt_discovery error: 0x%X.\r\n", res);
        
        if(p_read)
            free(p_read);
    }
    
    return res;
}

#if CFG_NB_PRF
static int init_prf(void)
{
    int res = INB_ERR_NO_ERROR;
    
#if (CFG_PRF_BASC_EN || CFG_PRF_BASS_EN)
    {
        inb_bas_prf_t *p_bas_prf = (inb_bas_prf_t*)malloc(sizeof(inb_bas_prf_t));
        p_bas_prf->multi_instance = 0;
        
        if(CFG_PRF_BASC_EN)
            res = inb_basc_add(p_bas_prf);
        if(CFG_PRF_BASS_EN)
        {
            p_bas_prf->check_enc_key_size = false;
            p_bas_prf->sec_lvl = ATT_PERM_NO_AUTH;
            p_bas_prf->bas_nb = 1;
            p_bas_prf->features[0] = INB_BAS_BATT_LVL_NTF_SUP;
            p_bas_prf->batt_level_pres_format[0].unit = INB_ATT_UNIT_PERCENTAGE;
            p_bas_prf->batt_level_pres_format[0].description = 1;
            p_bas_prf->batt_level_pres_format[0].format = INB_ATT_FORMAT_UINT8;
            p_bas_prf->batt_level_pres_format[0].exponent = 0;
            p_bas_prf->batt_level_pres_format[0].name_space = 1;
            res = inb_bass_add(p_bas_prf);
        }
        if(res)
        {
            PRINTD(DBG_ERR, "BAS add failed: 0x%X.\r\n", res);
            if(p_bas_prf)
                free(p_bas_prf);
            
            return res;
        }
    }
#endif
#if (CFG_PRF_DISC_EN || CFG_PRF_DISS_EN)
    {
        inb_dis_prf_t *p_dis_prf = (inb_dis_prf_t*)malloc(sizeof(inb_dis_prf_t));
        p_dis_prf->multi_instance = 0;
        
        if(CFG_PRF_DISC_EN)
            res = inb_disc_add(p_dis_prf);
        if(CFG_PRF_DISS_EN)
        {
            p_dis_prf->check_enc_key_size = false;
            p_dis_prf->sec_lvl = ATT_PERM_NO_AUTH;
            p_dis_prf->features = INB_DISS_ALL_FEAT_SUP;
            res = inb_diss_add(p_dis_prf);
        }
        if(res)
        {
            PRINTD(DBG_ERR, "DIS add failed: 0x%X.\r\n", res);
            if(p_dis_prf)
                free(p_dis_prf);
            
            return res;
        }
    }
#endif
#if (CFG_PRF_HOGPBH_EN || CFG_PRF_HOGPRH_EN || CFG_PRF_HOGPD_EN)
    {
        inb_hogp_prf_t *p_hogp_prf = (inb_hogp_prf_t*)malloc(sizeof(inb_hogp_prf_t));
        p_hogp_prf->multi_instance = 0;
        
        if(CFG_PRF_HOGPBH_EN)
            res = inb_hogpbh_add(p_hogp_prf);
        if(CFG_PRF_HOGPRH_EN)
            res = inb_hogprh_add(p_hogp_prf);
        if(CFG_PRF_HOGPD_EN)
        {
            p_hogp_prf->check_enc_key_size = false;
            p_hogp_prf->sec_lvl = ATT_PERM_NO_AUTH;
            p_hogp_prf->hids_nb = 1;
#ifndef MSRCU
            p_hogp_prf->cfg[0].svc_features = INB_HOGPD_CFG_MOUSE | INB_HOGPD_CFG_PROTO_MODE
                    | INB_HOGPD_CFG_BOOT_MOUSE_WR | INB_HOGPD_CFG_REPORT_NTF_EN
                    | INB_HOGPD_CFG_BOOT_KB_WR | INB_HOGPD_CFG_KEYBOARD;
            p_hogp_prf->cfg[0].report_nb = 1;
            p_hogp_prf->cfg[0].report_char_cfg[0] = INB_HOGPD_CFG_REPORT_IN|INB_HOGPD_CFG_REPORT_WR;
            p_hogp_prf->cfg[0].report_id[0] = 1;
#else
            p_hogp_prf->cfg[0].svc_features = INB_HOGPD_CFG_PROTO_MODE | INB_HOGPD_CFG_REPORT_NTF_EN;
            p_hogp_prf->cfg[0].report_nb = 3;
            p_hogp_prf->cfg[0].report_char_cfg[0] = INB_HOGPD_CFG_REPORT_IN|INB_HOGPD_CFG_REPORT_WR;
            p_hogp_prf->cfg[0].report_char_cfg[1] = INB_HOGPD_CFG_REPORT_IN|INB_HOGPD_CFG_REPORT_WR;
            p_hogp_prf->cfg[0].report_char_cfg[2] = INB_HOGPD_CFG_REPORT_IN|INB_HOGPD_CFG_REPORT_WR;
            p_hogp_prf->cfg[0].report_id[0] = 1;
            p_hogp_prf->cfg[0].report_id[1] = 2;
            p_hogp_prf->cfg[0].report_id[2] = 3;
#endif
            p_hogp_prf->cfg[0].hid_info.bcdHID = 0x1002;
            p_hogp_prf->cfg[0].hid_info.bCountryCode = 0x21;
            p_hogp_prf->cfg[0].hid_info.flags = INB_HIDS_NORM_CONNECTABLE | INB_HIDS_REMOTE_WAKE_CAPABLE;
            res = inb_hogpd_add(p_hogp_prf);
        }
        if(res)
        {
            PRINTD(DBG_ERR, "HOGP add failed: 0x%X.\r\n", res);
            if(p_hogp_prf)
                free(p_hogp_prf);
            
            return res;
        }
    }
#endif
#if CFG_FW_UPD_EN
    res = in_ota_svc_add();
    if(res)
    {
        PRINTD(DBG_ERR, "OTAS add failed: 0x%X.\r\n", res);
        return res;
    }
#endif
#if (CFG_PRF_TPPS_EN)
    res = tpps_add_svc();
    if(res)
    {
        PRINTD(DBG_ERR, "TPPS add failed: 0x%X.\r\n", res);
        return res;
    }
#endif
#ifdef MSRCU
#if MSRCU_BLE_VOICE_ATV_ENABLE
    res = atv_add_svc();
    if(res)
    {
        PRINTD(DBG_ERR, "ATV add failed: 0x%X.\r\n", res);
        return res;
    }
#endif
#endif
    
    return res;
}
#endif

static void handle_default_ble_evt(inb_evt_t *evt, void *param)
{
    switch (evt->evt_id & 0xFF00) 
    {
        case GAP_EVT_CODE:
            handle_default_gap_evt(evt->evt_id, (void *)&evt->param);
            break;
        case GATT_EVT_CODE:
            handle_default_gatt_evt(evt->evt_id, (void *)&evt->param);
            break;
#if (CFG_PRF_BASC_EN || CFG_PRF_BASS_EN)
        case BAS_EVT_CODE:
            handle_default_bas_evt(evt->evt_id, (void *)&evt->param);
            break;
#endif
#if (CFG_PRF_DISC_EN || CFG_PRF_DISS_EN)
        case DIS_EVT_CODE:
            handle_default_dis_evt(evt->evt_id, (void *)&evt->param);
            break;
#endif
#if (CFG_PRF_HOGPBH_EN || CFG_PRF_HOGPD_EN || CFG_PRF_HOGPRH_EN)
        case HOGP_EVT_CODE:
            handle_default_hogp_evt(evt->evt_id, (void *)&evt->param);
            break;
#endif
        default:
            break;
    }
}

void ble_event_callback(inb_evt_t *evt)
{
    void* param = NULL;
    
    handle_default_ble_evt(evt, param);
    
    ble_app_evt_cb(evt);
    
    if(param)
        free(param);
}

int ble_stack_init()
{
    int res = 0;
    
    if(!CFG_BLE_STK_MEM_EN)
        return INB_PLT_ERR_INVALID_CONFIG;
    
    inb_param_t b_cfg = {
        //.bd_addr = {CFG_BLE_PARAM_BD_ADDR},
        .sleep_algo_dur = CFG_BLE_PARAM_SLP_ALGO_DUR,
        .lpc_drift = CFG_BLE_PARAM_LPC_DRIFT,
        .radio_wakeup_time = CFG_BLE_PARAM_RADIO_WUP_TIME,
        .osc_wakeup_time = CFG_BLE_PARAM_OSC_WUP_TIME,
        .ext_wakeup_time = 0,
        .coded_phy_500_en = CFG_BLE_PARAM_CODED_PHY_500_EN,
        .sleep_en = CFG_BLE_PARAM_SLEEP_EN,
        .ext_wakeup_en = 0,
        .pub_key_valid = CFG_BLE_PARAM_P256_PUB_KEY_VALID,
        .pub_key = {CFG_BLE_PARAM_P256_PUB_KEY},
        .priv_key_valid = CFG_BLE_PARAM_P256_PRIV_KEY_VALID,
        .priv_key = {CFG_BLE_PARAM_P256_PRIV_KEY},
        .trace_flag = CFG_BLE_PARAM_TRACE_FLAG
    };
    hal_global_flash_ble_mac_get((inb_addr_t *)b_cfg.bd_addr);
    
    inb_mem_t m_cfg = {
        .retn_mem_env_start_addr = (uint32_t)ble_mem_env,
        .retn_mem_env_size = CFG_BLE_STK_ENV_MEM_SIZE,
        .retn_mem_db_start_addr = (uint32_t)ble_mem_db,
        .retn_mem_db_size = CFG_BLE_STK_DB_MEM_SIZE,
        .retn_mem_msg_start_addr = (uint32_t)ble_mem_msg,
        .retn_mem_msg_size = CFG_BLE_STK_MSG_MEM_SIZE,
        .non_retn_mem_start_addr = (uint32_t)ble_mem_non_rtn,
        .non_retn_mem_size = CFG_BLE_STK_NON_RETN_MEM_SIZE,
    };
    
    /// Initialize BLE stack
    res = inb_init(&b_cfg, &m_cfg);
    
    return res;
}

int ble_config(bool isHciMode, void (*cb)(inb_evt_t *evt))
{
    int res = INB_ERR_NO_ERROR;
    
    if(isHciMode)
        hci_enable();
    
    if((res = ble_stack_init()) != INB_ERR_NO_ERROR)
    {
        PRINTD(DBG_ERR, "inb_init failed, 0x%02X\r\n", res);
        return res;
    }
    
    if(isHciMode)
        return 0;
    
#if CFG_BLE_STK_MEM_USAGE_PRF_EN
    osTimerId tim_id = osTimerCreate(osTimer(ble_pf_mem), osTimerPeriodic, NULL);
    if(tim_id == NULL)
    {
        res = INB_PLT_ERR_OS_TMR_CREATE;
        PRINTD(DBG_ERR, "ERR: ble timer creat failed \n");
        return res;
    }
    osTimerStart(tim_id, 10000);
#endif
    
    if((res = inb_api_init(ble_event_callback)) != INB_ERR_NO_ERROR)
    {
        PRINTD(DBG_ERR, "inb_api_init failed, 0x%02X\r\n", res);
        return res;
    }
    
    if((res = inb_reset()) != INB_ERR_NO_ERROR)
    {
        PRINTD(DBG_ERR, "inb_reset failed, 0x%02X\r\n", res);
        return res;
    }
    
    inb_set_dev_config_t d_cfg =
    {
        .renew_dur = CFG_BLE_DEV_RENEW_DURATION,
        .addr.addr = {CFG_BLE_DEV_STATIC_ADDR},
        .irk.key = {0},
        .privacy_cfg = CFG_BLE_DEV_PRIVACY,
        .pairing_mode = CFG_BLE_DEV_PAIR_MODE,
        .gap_start_hdl = CFG_BLE_DEV_GAP_START_HANDLE,
        .gatt_start_hdl = CFG_BLE_DEV_GATT_START_HANDLE,
        .att_devname_write_perm = CFG_BLE_DEV_ATT_DEV_NAME_WRT_PERM,
        .att_apperance_write_perm = CFG_BLE_DEV_ATT_APPERANCE_WRT_PERM,
        .att_slv_pref_conn_param_present = CFG_BLE_DEV_ATT_SLV_PREF_PARAM_PRESENT,
        .svc_change_feat_present = CFG_BLE_DEV_ATT_SVC_CHG_FEAT_PRESENT,
        .sugg_max_tx_octets = CFG_BLE_DEV_SUGG_MAX_TX_OCTETS,
        .sugg_max_tx_time = CFG_BLE_DEV_SUGG_MAX_TX_TIME,
        .max_mtu = CFG_BLE_DEV_L2CAP_MAX_MTU,
        .max_mps = CFG_BLE_DEV_L2CAP_MAX_MPS,
        .max_nb_lecb = CFG_BLE_DEV_L2CAP_MAX_LECB_CONN,
        .tx_pref_phy = CFG_BLE_DEV_PREF_TX_PHY,
        .rx_pref_phy = CFG_BLE_DEV_PREF_RX_PHY,
    };
#if defined(OBSERVER)
    d_cfg.role = ROLE_OBSERVER;
#elif defined(CFG_BROADCASTER)
    d_cfg.role = ROLE_BROADCASTER;
#elif defined(CFG_CENTRAL)
    d_cfg.role = ROLE_CENTRAL;
#elif defined(CFG_PERIPHERAL)
    d_cfg.role = ROLE_PERIPHERAL;
#elif defined(CFG_ALL)
    d_cfg.role = ROLE_ALL;
#endif
    if((res = inb_set_dev_config(&d_cfg)) != INB_ERR_NO_ERROR)
    {
        PRINTD(DBG_ERR, "inb_set_dev_config failed, 0x%02X\r\n", res);
        return res;
    }
    
#if CFG_NB_PRF
    if((res = init_prf()) != INB_ERR_NO_ERROR)
    {
        PRINTD(DBG_ERR, "init_prf failed, 0x%02X\r\n", res);
        return res;
    }
#endif
    
    ble_app_evt_cb = cb;
    
    inb_addr_t mac = {0};
    hal_global_flash_ble_mac_get(&mac);
    PRINTD(DBG_ERR, "BLE MAC: 0x %02X %02X %02X %02X %02X %02X\r\n", 
            mac.addr[0], mac.addr[1], mac.addr[2], mac.addr[3], mac.addr[4], mac.addr[5]);
    
    return 0;
}

#if (CFG_PDT_HCI || CFG_PDT_TX)
void ble_production_test(void)
{
    int port, pin, level;
    
#if CFG_PDT_HCI
#if !CFG_HCI
    #error "CFG_HCI is disabled."
#else
    port = CFG_PDT_HCI_PORT;
    pin = CFG_PDT_HCI_PIN;
    level = CFG_PDT_HCI_LEVEL;
    
    hal_gpio_pin_mux(port, pin, 0, 0);
    hal_gpio_pad_oe_ie(port, pin, 0, 1);
    if(level)
        hal_gpio_pad_pd_pu(port, pin, 1, 0);
    else
        hal_gpio_pad_pd_pu(port, pin, 0, 1);
    
    if(level == hal_gpio_input(port, pin))
    {
        ble_config(true, NULL);
        
        while(level == hal_gpio_input(port, pin));//wait for HCI communication
            
        hal_global_sys_reset();
    }
#endif
#endif
    
#if CFG_PDT_TX
    port = CFG_PDT_TX_PORT;
    pin = CFG_PDT_TX_PIN;
    level = CFG_PDT_TX_LEVEL;
    
    hal_gpio_pin_mux(port, pin, 0, 0);
    hal_gpio_pad_oe_ie(port, pin, 0, 1);
    if(level)
        hal_gpio_pad_pd_pu(port, pin, 1, 0);
    else
        hal_gpio_pad_pd_pu(port, pin, 0, 1);
    
    if(level == hal_gpio_input(port, pin))
    {
        ble_config(false, NULL);
        
        rf_em_init();
        rf_int_prog_pll_trx_trig(0);
        rf_int_rpl_mdm_init();
        rf_int_tx_carrier_test(1, 19);//2440MHz
        
        while(level == hal_gpio_input(port, pin));//sending TX carrier continuously
        
        hal_global_sys_reset();
    }
#endif
}
#endif
