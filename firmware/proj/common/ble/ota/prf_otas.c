#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file in_ota_svc.c
 *
 * @brief Over The Air (OTA) Firmware Download Service
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#if CFG_FW_UPD_EN
/*
 ****************************************************************************************
 * INCLUDES
 ****************************************************************************************
 */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "in_arm.h"
#include "in_debug.h"
#include "in_version.h"
#include "in_fw_upd.h"

#include ".\ble\inb_api.h"
#include ".\ble\inb_att.h"
#include ".\ble\inb_error.h"
#include ".\ble\inb_evt.h"
#include ".\ble\inb_gap.h"
#include ".\ble\inb_gatt.h"
#include ".\ble\inb_gatt_evt.h"


#include ".\hal\hal_global.h"
#include ".\hal\hal_flash.h"

#include "cmsis_os.h"

#include "prf_otas.h"

/*
 ****************************************************************************************
 * Forware Declaration
 ****************************************************************************************
 */

/*
 ****************************************************************************************
 * Defines
 ****************************************************************************************
 */

#define MSG_DNLD_QUE_SIZE 8
/*
 ****************************************************************************************
 * Structures
 ****************************************************************************************
 */

typedef struct {
    uint16_t hdl_svc;
    uint16_t hdl_fw_ver;
    uint16_t hdl_dnld_ctl;
    uint16_t hdl_dnld_data;

    uint16_t max_mtu;
    char busy;
    char pad;
    
    void *h_tid;
    void *h_msg_q;

    int conid;
    fw_dnld_info_t info;
    fw_dnld_data_t dnld;
} ota_svr_t;

typedef struct {
    uint32_t addr;
    uint32_t length;
    uint8_t data[];
} msg_dnld_t;


 
static ota_svr_t g_svr;
static uint32_t msg_q_array[MSG_DNLD_QUE_SIZE];
static char fw_ver[16] = {IN_SDK_VER};
static const inb_gatt_att_desc_t ota_atts[] = {
    [OTA_DECL_CHAR_VER] = {
        .uuid = { 0x03, 0x28 }, 
        .prop = ATT_CHAR_PROP_READ,
        .max_len = 0,
        .ext_prop = (0 << ATT_EXT_PROP_UUID_LEN_SHIFT),
    },
    [OTA_CHAR_VAL_VER] = {
        .uuid = {FW_UPD_ATT_FW_VER_CHAR_UUID }, 
        .prop = ATT_CHAR_PROP_READ,
        .max_len = 16,
        .ext_prop = ATT_EXT_PROP_RI | (2 <<ATT_EXT_PROP_UUID_LEN_SHIFT),
    },

    [OTA_DECL_CHAR_INFO] = {
        .uuid = { 0x03, 0x28 }, 
        .prop = ATT_CHAR_PROP_READ,
        .max_len = 0,
        .ext_prop =  (0 << ATT_EXT_PROP_UUID_LEN_SHIFT),
    },
    [OTA_CHAR_VAL_INFO] = {
        .uuid = {FW_UPD_ATT_FW_INFO_CHAR_UUID}, 
        .prop = ATT_CHAR_PROP_WRITE,
        .max_len = sizeof(fw_dnld_info_t),
        .ext_prop =  (2 << ATT_EXT_PROP_UUID_LEN_SHIFT),
    },
    [OTA_DECL_CHAR_DATA] = {
        .uuid = { 0x03, 0x28 },
        .prop =ATT_CHAR_PROP_READ,
        .max_len = 0,
        .ext_prop = 0,
    },
    [OTA_CHAR_VAL_DATA] = {
        .uuid = { FW_UPD_ATT_FW_DATA_CHAR_UUID}, 
        .prop = ATT_CHAR_PROP_WRITE|ATT_CHAR_PROP_EXT,
        .max_len = sizeof(fw_dnld_data_t) + FW_UPD_DNLD_DATA_MAX_LEN,
        .ext_prop = (2 <<ATT_EXT_PROP_UUID_LEN_SHIFT),
    },
    [OTA_CHAR_DESCR_DECL_DATA] = {
        .uuid = { 0x00, 0x29}, 
        .prop = ATT_CHAR_PROP_READ,
        .max_len = 0x1,
        .ext_prop = 0,
    },    

    [OTA_DECL_CHAR_ERR] = {
        .uuid = { 0x03, 0x28 }, 
        .prop = ATT_CHAR_PROP_READ,
        .max_len = 0,
        .ext_prop = (0 << ATT_EXT_PROP_UUID_LEN_SHIFT),
    },
    [OTA_CHAR_VAL_ERR] = {
        .uuid = {FW_UPD_ATT_FW_ERR_CHAR_UUID },
        .prop = ATT_CHAR_PROP_READ|ATT_CHAR_PROP_NOTIFY,
        .max_len = 8,
        .ext_prop = (2 <<ATT_EXT_PROP_UUID_LEN_SHIFT),
    },
    [OTA_CLIENT_CHAR_CFG_ERR] = {
        .uuid = { 0x02, 0x29 }, //INB_ATT_DESC_SERVER_CHAR_CFG,
        .prop = ATT_CHAR_PROP_READ|ATT_CHAR_PROP_WRITE,
        .max_len = 0,
        .ext_prop = 0,
    },
};
/*
 ****************************************************************************************
 * Static
 ****************************************************************************************
 */

static uint16_t ota_get_handle(int idx)
{
    ota_svr_t *p_svr = &g_svr;
    return p_svr->hdl_svc + idx + 1;
}

static void fw_dnld_task(const void *arg)
{
    ota_svr_t *p_svr = &g_svr;
    uint32_t tsize = 0;
    int res = OTA_ERR_NO_ERR; 
    uint32_t err_addr = p_svr->info.load_addr;

    PRINTD(DBG_TRACE, "FW Dnld Task...start\n");

    // use message queue for download
    osMessageQDef_t def;
    def.queue_sz = MSG_DNLD_QUE_SIZE;
    def.pool = (void *)msg_q_array;
    p_svr->h_msg_q = osMessageCreate(&def, NULL);
    if (!p_svr->h_msg_q) {
        PRINTD(DBG_ERR, "FW Dnld Task: Failed create msg queue...\n");
        return;
    }

    // make sure ble is not busy
    while (inb_is_ble_busy());

    PRINTD(DBG_TRACE, "FW Dnld Task: Erase(addr=%08x,size=%08x)...\n", p_svr->info.load_addr, p_svr->info.size);
    // Erase Download area
    res = hal_spi_flash_prog(p_svr->info.load_addr, p_svr->info.size, 0, 0, NULL, 0);
    if (res) {
        PRINTD(DBG_ERR, "FW Dnld Task: Failed, Erase(addr=%08x,size=%08x)...%d\n", p_svr->info.load_addr, p_svr->info.size, res);
        return;
    }
        
    p_svr->busy = 1;
    while (1) {
        osEvent evt;

        evt = osMessageGet((osMessageQId)p_svr->h_msg_q, osWaitForever);
        if (evt.status != osEventMessage) { 
            PRINTD(DBG_TRACE, "fw_dnld_task evt error 0x%x\n", evt.status);
            res = OTA_ERR_MSG;
            break;
        }
        
        msg_dnld_t *p_msg = (msg_dnld_t *)evt.value.v;
        if (p_msg) {
            // make sure ble is not busy
            while (inb_is_ble_busy());					
            err_addr = p_msg->addr;
            // Ble is not busy, write to flash
            if (hal_spi_flash_prog(0, 0, p_msg->addr, p_msg->length, p_msg->data, 1)) {
                PRINTD(DBG_TRACE, "flash write fail  addr 0x%x\n", p_msg->addr);
                free(p_msg);
                res = OTA_ERR_IMG_WRITE;
                break;
            }
      
            	
        
            // finish flash write, update length
            tsize += p_msg->length;
            free(p_msg);

            if (tsize >= p_svr->info.size) {	
                // Download done
                PRINTD(DBG_TRACE, "FW Dnld Task...Done\n");
    
                fw_upd_info_t boot;
                boot.upd_magic = FW_UPD_MAGIC_WORD;
                boot.load_addr = p_svr->info.load_addr;
                boot.copy_addr = p_svr->info.copy_addr;
                boot.size = p_svr->info.size;
                if (hal_spi_flash_prog(FW_UPD_INFO_ADDR, FW_UPD_INFO_SIZE, FW_UPD_INFO_ADDR, sizeof(fw_upd_info_t), (uint8_t *)&boot, 1)) {
                    PRINTD(DBG_TRACE, "flash write fail  addr 0x%x\n", FW_UPD_INFO_ADDR);
                    res = OTA_ERR_INFO_WRITE;
                    //goto out;
                }
                PRINTD(DBG_TRACE, "Waiting for restart...\n");
                break;
            }
        }		
    }

    p_svr->busy = 0;

    uint32_t buf[2];
    buf[0] = err_addr;
    buf[1] = res;
    res = inb_gatt_send_ntf(p_svr->conid, ota_get_handle(OTA_CHAR_VAL_ERR), 8, (uint8_t *)buf);
    if (res) {
    PRINTD(DBG_TRACE, "noitfy err res:0x%x\n", res);
    }
    osDelay(100);//send last response
    // Cold boot system
    hal_global_sys_reset();
    return;
}

/*
 ****************************************************************************************
 * APIs
 ****************************************************************************************
 */

int in_ota_svc_add(void)
{
    ota_svr_t *p_svr = &g_svr;
    int res = INB_ERR_NO_ERROR;
    uint16_t hdl;
    uint8_t svc_uuid[] = {FW_UPD_ATT_SVC_UUID};
    //uint8_t char_fw_ver_uuid[] = {FW_UPD_ATT_FW_VER_CHAR_UUID};
    //uint8_t char_fw_dnld_ctl_uuid[] = {FW_UPD_ATT_FW_INFO_CHAR_UUID};
    //uint8_t char_fw_dnld_data_uuid[] = {FW_UPD_ATT_FW_DATA_CHAR_UUID};
    ////uint8_t char_fw_dnld_err_uuid[] = {FW_UPD_ATT_FW_ERR_CHAR_UUID};

    int nb_att = sizeof(ota_atts)/sizeof(ota_atts[0]);
    inb_gatt_svc_desc_t *p_svc_desc = malloc(sizeof(inb_gatt_svc_desc_t) + nb_att * sizeof(inb_gatt_att_desc_t));

    if (!p_svc_desc)
        return INB_PLT_ERR_NO_MEM;

    /// Service Definition
    p_svc_desc->start_hdl = 0;	
    p_svc_desc->prop = (2 << ATT_SVC_PROP_UUID_LEN_SHIFT);		
    memcpy(p_svc_desc->uuid, svc_uuid, sizeof(svc_uuid));
    p_svc_desc->nb_att = nb_att;		
    memcpy(p_svc_desc->atts, &ota_atts[0], nb_att * sizeof(inb_gatt_att_desc_t));
    res = inb_gatt_add_svc(p_svc_desc, &hdl);

    if (res != INB_ERR_NO_ERROR) {
        PRINTD(DBG_ERR, "FW Dnld: Failed Add Srvice...%d\n", res);
        free(p_svc_desc);
        return res;
    }

    // Set each handle
    p_svr->hdl_svc = hdl;
    p_svr->hdl_fw_ver = hdl + OTA_CHAR_VAL_VER + 1;
    p_svr->hdl_dnld_ctl = hdl + OTA_CHAR_VAL_INFO + 1;
    p_svr->hdl_dnld_data = hdl+OTA_CHAR_VAL_DATA + 1;		

    free(p_svc_desc);

    return res;
}

void in_ota_mtu_xchg_hdl(uint16_t max_mtu)
{
    ota_svr_t *p_svr = &g_svr;
    
    p_svr->max_mtu = max_mtu;
}	

int in_ota_svc_read_hdl(uint16_t hdl, uint16_t *rd_data_len, uint8_t **rd_data)
{
    ota_svr_t *p_svr = &g_svr;
    int character = hdl - p_svr->hdl_svc - 1;
    int status = INB_ATT_ERR_INVALID_HANDLE;
    switch (character) {
        case OTA_CHAR_VAL_VER: {
    
            PRINTD(DBG_TRACE, "FW Dnld: Read Firmware Version\n");
            char sdk_ver[] = 	IN_SDK_VER;

            strcpy(fw_ver, sdk_ver);

            // Read firmware version number
            *rd_data_len	= 16;
            *rd_data = (uint8_t *)fw_ver;
            status = INB_ERR_NO_ERROR;
        }
        break;
        default:
            break;
    }

    return status;
}

int in_ota_svc_info_req_hdl(uint16_t hdl, uint16_t *length)
{
    ota_svr_t *p_svr = &g_svr;

    if (hdl == p_svr->hdl_dnld_data) {
        *length = sizeof(fw_dnld_data_t) + FW_UPD_DNLD_DATA_MAX_LEN ;
        return INB_ERR_NO_ERROR;
    }

    return INB_ATT_ERR_INVALID_HANDLE;
}

int in_ota_svc_write_hdl(inb_evt_write_req_ind_t *ind)
{
    ota_svr_t *p_svr = &g_svr;
    int character = ind->handle - p_svr->hdl_svc - 1;
    int status = INB_ATT_ERR_INVALID_HANDLE;
    static int lenReceived = 0;
    
    //PRINTD(DBG_TRACE, "handle %d\n", hdl);
    switch (character) {
        case OTA_CHAR_VAL_INFO: {
            // Download parameters

            if (ind->length == sizeof(fw_dnld_info_t)) {
                //fw_dnld_info_t *p_val = (fw_dnld_info_t*)data;
                
                if (!p_svr->busy) {
                    memcpy(&p_svr->info, ind->value, sizeof(fw_dnld_info_t));
                    p_svr->conid = ind->conidx;
                    fw_dnld_info_t *p_val = &p_svr->info;
                    PRINTD(DBG_TRACE, "loadAddr:0x%x  cpoyAddr:0x%x size:0x%x\n", p_val->load_addr, p_val->copy_addr, p_val->size);
                    lenReceived = 0;
                    /// launch download task
                    osThreadDef_t def;
                    def.pthread = fw_dnld_task;
                    def.instances = 1;
                    def.tpriority = osPriorityNormal;
                    def.stacksize = 0; 
                    p_svr->h_tid = osThreadCreate(&def, (void *)p_svr);
                    if (!p_svr->h_tid) {
                        return INB_ATT_ERR_APP_ERROR;
                    }
                } 
            }
            status = INB_ERR_NO_ERROR;
        } 
        break;
        case OTA_CHAR_VAL_DATA: {
            // Download data
        
            // Data format:
            // =======|=======|=======|=======|=======|=======|=======|=======|======
            //  Addr 0  Addr 1  Addr 2  Addr 3  Size 0  Size 1  Size 2  Size 3  Data....
            uint8_t *data = ind->value;
            uint32_t addr = data[0]|(data[1]<<8)|(data[2]<<16)|(data[3]<<24);
            uint32_t length = ind->length - 4;//data[4]|(data[5]<<8)|(data[6]<<16)|(data[7]<<24);
            lenReceived += length;
            PRINTD(DBG_TRACE, "addr:0x%x  %%%.2f \n", addr, 100.0 * lenReceived / g_svr.info.size);
            //PRINTD(DBG_TRACE, "addr:0x%x  length %d  data_length %d \n", addr, length, ind->length );
            msg_dnld_t *p_msg = (msg_dnld_t *)malloc(sizeof(msg_dnld_t) + length);
            if (!p_msg)
                return INB_ATT_ERR_APP_ERROR;
                
            p_msg->addr = addr;
            p_msg->length = length;
            memcpy(p_msg->data, (data+4), length);
            //PRINTD(DBG_TRACE, "data  0x%x:0x%x\n",p_msg->data[0], p_msg->data[length-1]);
            osMessagePut(p_svr->h_msg_q, (uint32_t)p_msg, osWaitForever); 

            status = INB_ERR_NO_ERROR;
        }
        break;
        default:
            break; 
    }
    return status;
}
#if 0
void test()
{
    ota_svr_t *p_svr = &g_svr;
        
            
            fw_dnld_info_t * p_val = &p_svr->info;
            p_val->load_addr = 0x3400f0;
            p_val->copy_addr = 0x302000;
            p_val->size = 0x21ec0;
        
         {
            //memcpy(&p_svr->info, data, sizeof(fw_dnld_info_t));
            //fw_dnld_info_t *p_val = &p_svr->info;
            PRINTD(DBG_TRACE, "loadAddr:0x%x  cpoyAddr:0x%x size:0x%x\n", p_val->load_addr, p_val->copy_addr, p_val->size);
            /// launch download task
            osThreadDef_t def;
            def.pthread = fw_dnld_task;
            def.instances = 1;
            def.tpriority = osPriorityNormal;
            def.stacksize = 0; 
            osThreadId h_tid = osThreadCreate(&def, NULL);
            if (!h_tid) {
                return;
            }
        } 
    

    osDelay(1000);
    // Download data
     {
        // Data format:
        //	======|======|======|======|======|======|======|======|======
        //	Addr 0		Addr 1	 Addr 2		Addr 3	 Size 0		Size 1	 Size 2		Size 3	 Data....
        
        uint32_t data_length = 20 + 4;
        uint32_t addr = p_val->load_addr;
        uint32_t sz = p_val->size;
        while (sz > 0) {
        //uint32_t addr = data[0]|(data[1]<<8)|(data[2]<<16)|(data[3]<<24);
        uint32_t length =data_length - 4;//data[4]|(data[5]<<8)|(data[6]<<16)|(data[7]<<24);
        //PRINTD(DBG_TRACE, "addr:0x%x  length %d  data_length %d data0x%x\n", addr, length, data_length,data[data_length-1] );
        msg_dnld_t *p_msg = (msg_dnld_t *)malloc(sizeof(msg_dnld_t) + length);
        if (!p_msg)
            return;
            
        p_msg->addr = addr;
        p_msg->length = length;
        //memcpy(p_msg->data, (data+4), length);
        memset(p_msg->data, 0xa5, length);
        //PRINTD(DBG_TRACE, "data  0x%x:0x%x\n",p_msg->data[0], p_msg->data[length-1]);
        osMessagePut(p_svr->h_msg_q, (uint32_t)p_msg, osWaitForever); 

        sz -= length;
        addr += length;
        osDelay(500);
        }
        return;
    } 
}
#endif
#endif	// CFG_FW_UPD_EN


