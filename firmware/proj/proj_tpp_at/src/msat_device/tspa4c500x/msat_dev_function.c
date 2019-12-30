/**
 ****************************************************************************************
 *
 * @file msat_dev_function.c
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

/* Include Files
 ****************************************************************************************
 */
#include "msat_dev_system.h"


/* Macro Definition
 ****************************************************************************************
 */

/* Enum Definition
 ****************************************************************************************
 */

/* Struct Definition
 ****************************************************************************************
 */

/* Function Declaration
 ****************************************************************************************
 */
extern void msat_fw_evt_ble_cb(msatEvtBle_t *evt);

msatErr_t msat_dev_function_ble_adv_start(uint16_t interval, uint8_t *data, uint16_t len);
 
/* Global Variable
 ****************************************************************************************
 */
static int msatDevAdvActvIdx = 0;

/* Function Definition
 ****************************************************************************************
 */
msatErr_t msat_dev_function_system_reset(void)
{
    hal_global_sys_reset();
    
    return ERR_NO_ERROR;
}

msatErr_t msat_dev_function_ble_adv_start(uint16_t interval, uint8_t *data, uint16_t len)
{
    int res = INB_ERR_NO_ERROR;
    inb_actv_create_t advCreate = {0};
    inb_actv_start_t advStart = {0};
    
    /// Create activity
    advCreate.option = 0;
    advCreate.own_addr_type = 0;
    advCreate.adv_param.type = ADV_TYPE_LEGACY;
    if(data[2] & 0x01)
        advCreate.adv_param.disc_mode = ADV_MODE_LIM_DISC;
    else
        advCreate.adv_param.disc_mode = ADV_MODE_GEN_DISC;
    advCreate.adv_param.prop = ADV_PROP_UNDIR_CONN;
    advCreate.adv_param.max_tx_pwr = 0;
    advCreate.adv_param.filter_pol = ADV_FILT_ALLOW_SCAN_ANY_CON_ANY;
    advCreate.adv_param.prim_cfg.adv_intv_min = interval;
    advCreate.adv_param.prim_cfg.adv_intv_max = interval;
    advCreate.adv_param.prim_cfg.chnl_map = CHANNEL_37 | CHANNEL_38 | CHANNEL_39;
    advCreate.adv_param.prim_cfg.phy = PHY_LE_1MBPS;
    res = inb_actv_create(&advCreate, &msatDevAdvActvIdx);
    if(res)
    {
        MSPRINT("inb_actv_create failed: 0x%X.\r\n", res);
        return ERR_DEVICE_BLE;
    }
    
    /// Set advertising data
    res = inb_actv_data(msatDevAdvActvIdx, 0, data + 3, len - 3);
    if(res)
    {
        MSPRINT("inb_actv_data failed: 0x%X.\r\n", res);
        
        res = inb_actv_del(msatDevAdvActvIdx);
        if(res)
            MSPRINT("inb_actv_del failed: 0x%X.\r\n", res);
        
        return ERR_DEVICE_BLE;
    }
    
    /// Start activity
    advStart.option = 0;
    advStart.u.adv_param.duration = 0;
    advStart.u.adv_param.max_adv_evt = 0;
    res = inb_actv_start(msatDevAdvActvIdx, &advStart);
    if(res)
    {
        MSPRINT("inb_actv_start failed: 0x%X.\r\n", res);
        
        res = inb_actv_del(msatDevAdvActvIdx);
        if(res)
            MSPRINT("inb_actv_del failed: 0x%X.\r\n", res);
        
        return ERR_DEVICE_BLE;
    }
    
    return ERR_NO_ERROR;
}

msatErr_t msat_dev_function_ble_adv_stop(void)
{
    int res = INB_ERR_NO_ERROR;
    
    res = inb_actv_stop(msatDevAdvActvIdx);
    if(res)
    {
        MSPRINT("adv inb_actv_stop failed: 0x%X.\r\n", res);
        return ERR_DEVICE_BLE;
    }
    
    return ERR_NO_ERROR;
}

uint16_t msat_dev_function_ble_send_cfg_hdl_get(void)
{
    return tpps_get_svc_hdl() + TPP_IDX_NTF_VAL_CFG;
}

uint16_t msat_dev_function_ble_rcv_val_hdl_get(void)
{
    return tpps_get_svc_hdl() + TPP_IDX_WR_DATA_VAL;
}

msatErr_t msat_dev_function_ble_send_data(uint8_t *data, uint16_t len)
{
    int res = INB_ERR_NO_ERROR;
    
    res = tpps_send_notify(0, data, len);
    if(res)
    {
        MSPRINT("tpps_send_notify failed: 0x%X.\r\n", res);
        return ERR_DEVICE_BLE;
    }
    
    return ERR_NO_ERROR;
}

msatErr_t msat_dev_function_ble_disconnect(void)
{
    int res = INB_ERR_NO_ERROR;
    
    res = inb_conn_disconnect(0, 0x16);//BLE_ERROR_CON_TERM_BY_LOCAL_HOST
    if(res)
    {
        MSPRINT("inb_conn_disconnect failed: 0x%X.\r\n", res);
        return ERR_DEVICE_BLE;
    }
    
    return ERR_NO_ERROR;
}
