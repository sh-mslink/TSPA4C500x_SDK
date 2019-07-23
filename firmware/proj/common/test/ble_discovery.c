#include "in_config.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "in_arm.h"
#include "in_debug.h"

#include ".\ble\inb_api.h"

#include "cmsis_os.h"

#include "prf_tppc.h"
#include "ble_discovery.h"

//#include "inb_att.h"

/* Macro Definition
 ****************************************************************************************
 */

/* Enum Definition
 ****************************************************************************************
 */

/* Struct Definition
 ****************************************************************************************
 */


/* Global Variable
 ****************************************************************************************
 */
 
msrcuDiscCharDescInfo_t g_tMsrcuDCDIStore;
msrcuDiscCharInfo_t g_tMsrcuDiscCharInfoStore ;


static int msrcu_dev_ble_gatt_discovery_svc(void);
static void user_rcu_discovery_timer_callback(void const *arg);
static int msrcu_dev_ble_gatt_discovery_svc(void);
//static int msrcu_dev_ble_gatt_inc_svc_char(void);
static int msrcu_dev_ble_gatt_char(void);
static int msrcu_dev_ble_gatt_discovery_char(void);

osTimerId msrcuAppDiscoveryTimerId;
osTimerDef(msrcuAppDiscoveryTimerId, user_rcu_discovery_timer_callback);

#define BleDiscTimeoutTime  100 //uint:1ms

msrcuBleDiscState_t g_tBleDiscSt = EVT_BLE_DISC_IDLE;

/* Function Definition
 ****************************************************************************************
 */


msrcuBleDiscState_t msrcu_dev_ble_disc_get_state(void)
{    
    return g_tBleDiscSt;
}

void msrcu_dev_ble_disc_set_state(msrcuBleDiscState_t state)//need to be static
{    
    g_tBleDiscSt = state;    
//    PRINTD(DBG_TRACE, "MSRCU BLE Discovery STATE: %d\r\n", g_tBleDiscSt);
}


void msrcu_dev_ble_disc_start(void)
{
	msrcuAppDiscoveryTimerId = osTimerCreate(osTimer(msrcuAppDiscoveryTimerId), osTimerOnce, NULL);
	if (msrcuAppDiscoveryTimerId == NULL) {
		PRINTD(DBG_TRACE, "failed create timer...\r\n");
//		return ERR_OTHERS;
	}
	else
	{
		PRINTD(DBG_TRACE, "os Timer Create success\r\n");
	}
	
	for(uint8_t i = 0;i<10;i++)
	{
		g_tMsrcuDCDIStore.char_info[i].char_desc_num = 0;
	}	
	
	msrcu_dev_ble_gatt_discovery_svc();
}

void RefreshDiscTimeoutTimer(void)
{
	osTimerStart(msrcuAppDiscoveryTimerId , BleDiscTimeoutTime);
}

extern uint8_t uuid_tpps_characteristics_ntf[16];
static void user_rcu_discovery_timer_callback(void const *arg)
{
	uint8_t status = msrcu_dev_ble_disc_get_state();
	uint16_t handle = 0;
	
	switch(status)
	{
		case EVT_BLE_DISC_IDLE:
		{
			PRINTD(DBG_TRACE, "EVT_BLE_DISC_IDLE\r\n");
//			if( FindHandleForPermitWR(0, &handle , uuid_tpps_characteristics_0) == 0)
//			{
//			  PRINTD(DBG_TRACE, "FindCharValueHandle WR success !!!\r\n");
//				PRINTD(DBG_TRACE, "handle = %d\r\n" , handle);
//			}
  
			//test..............
			if(FindHandleForPermitNTF(0, &handle , uuid_tpps_characteristics_ntf) == 0)
			{
				PRINTD(DBG_TRACE, "FindCharValueHandle NTF success !!!\r\n");
				PRINTD(DBG_TRACE, "handle1 = %d\r\n" , handle);
			
		    tppc_notify_enable(0);
			}

			osTimerDelete(msrcuAppDiscoveryTimerId);
								
		}break;
		
		case EVT_BLE_DISC_SVC_CMP: //
		{
			PRINTD(DBG_TRACE, "EVT_BLE_DISC_SVC_CMP\r\n");
//			msrcu_dev_ble_gatt_inc_svc_char();
			msrcu_dev_ble_gatt_char();
			
		}break;
		
		case EVT_BLE_DISC_INCL_SVC_CMP :  //1
		{
			PRINTD(DBG_TRACE, "EVT_BLE_DISC_INCL_SVC_CMP\r\n");
			msrcu_dev_ble_gatt_char();
			RefreshDiscTimeoutTimer(); //2
		}break;
		
		case EVT_BLE_DISC_CHAR_CMP: //3
		{
			PRINTD(DBG_TRACE, "EVT_BLE_DISC_CHAR_CMP\r\n");
			
			RefreshDiscTimeoutTimer();
			msrcu_dev_ble_gatt_discovery_char();
			
		}break;
		
		case EVT_BLE_DISC_CHAR_DESC_CMP:
		{
			PRINTD(DBG_TRACE, "EVT_BLE_DISC_CHAR_DESC_CMP\r\n");
			RefreshDiscTimeoutTimer();	
		}break;

	  default:
			break;
	}	
}

int handle_gatt_discovery_evt(uint16_t eid, void *pv)
{
	
	switch(eid)
	{
		case GATT_EVT_DISC_SVC :
				{
					PRINTD(DBG_TRACE, "into GATT_EVT_DISC_SVC\r\n");
					
//				 inb_evt_disc_svc_ind_t  *p_param = (inb_evt_disc_svc_ind_t  *)pv;
					
					RefreshDiscTimeoutTimer();
					msrcu_dev_ble_disc_set_state(EVT_BLE_DISC_SVC_CMP);
					
//					PRINTD(DBG_TRACE, "p_param->start_hdl = %d , p_param->end_hdl = %d\r\n" ,p_param->start_hdl , p_param->end_hdl);

				}
				break;
				
				case GATT_EVT_DISC_INCL_SVC:
				{
					PRINTD(DBG_TRACE, "into GATT_EVT_DISC_INCL_SVC\r\n");
					
					msrcu_dev_ble_disc_set_state(EVT_BLE_DISC_INCL_SVC_CMP);
					RefreshDiscTimeoutTimer();
					
				}
				break;
				
				case GATT_EVT_DISC_CHAR:
				{
					PRINTD(DBG_TRACE, "into GATT_EVT_DISC_CHAR\r\n");
					
					struct msrcu_evt_disc_char_ind *p_param = (struct msrcu_evt_disc_char_ind *)pv;
					
//					uint8_t *param = (uint8_t *)pv;
					
//					PRINTD(DBG_TRACE, "found data :");
//					for(uint8_t j = 0 ; j<20;j++)
//					{
//						PRINTD(DBG_TRACE, "%02x ",param[j]);
//					}
//					PRINTD(DBG_TRACE, "\r\n");
					
					
					g_tMsrcuDiscCharInfoStore.char_info[g_tMsrcuDiscCharInfoStore.char_num].conidx  = p_param->conidx ;
					g_tMsrcuDiscCharInfoStore.char_info[g_tMsrcuDiscCharInfoStore.char_num].attr_hdl = p_param->attr_hdl ;
					g_tMsrcuDiscCharInfoStore.char_info[g_tMsrcuDiscCharInfoStore.char_num].pointer_hdl = p_param->pointer_hdl ;
					g_tMsrcuDiscCharInfoStore.char_info[g_tMsrcuDiscCharInfoStore.char_num].prop = p_param->prop ;
					g_tMsrcuDiscCharInfoStore.char_info[g_tMsrcuDiscCharInfoStore.char_num].uuid_len = p_param->uuid_len ;
					memcpy(g_tMsrcuDiscCharInfoStore.char_info[g_tMsrcuDiscCharInfoStore.char_num].uuid ,
								p_param->uuid , p_param->uuid_len );
										
//					PRINTD(DBG_TRACE, "PERM(PRF_MI, ENABLE) = %d\r\n" , PERM(NP, ENABLE));
//					PRINTD(DBG_TRACE, "g_tMsrcuDiscCharInfoStore pointer_hdl  = %d \r\n",g_tMsrcuDiscCharInfoStore.char_info[g_tMsrcuDiscCharInfoStore.char_num].pointer_hdl  );
//					PRINTD(DBG_TRACE, "g_tMsrcuDiscCharInfoStore attr_hdl  = %d \r\n",g_tMsrcuDiscCharInfoStore.char_info[g_tMsrcuDiscCharInfoStore.char_num].attr_hdl );
//					PRINTD(DBG_TRACE, "g_tMsrcuDiscCharInfoStore prop = %d \r\n",g_tMsrcuDiscCharInfoStore.char_info[g_tMsrcuDiscCharInfoStore.char_num].prop);
//					PRINTD(DBG_TRACE, "found uuid :");
//					for(uint8_t j = 0 ; j< g_tMsrcuDiscCharInfoStore.char_info[g_tMsrcuDiscCharInfoStore.char_num ].uuid_len;j++)
//					{
//						PRINTD(DBG_TRACE, "%02x ",g_tMsrcuDiscCharInfoStore.char_info[g_tMsrcuDiscCharInfoStore.char_num].uuid[j]);
//					}
//					PRINTD(DBG_TRACE, "\r\n");
					
					g_tMsrcuDiscCharInfoStore.char_num ++;
					
					msrcu_dev_ble_disc_set_state(EVT_BLE_DISC_CHAR_CMP);
					RefreshDiscTimeoutTimer();

				}
				break;
				
				case GATT_EVT_DISC_CHAR_DESC:
				{
					struct msrcu_evt_disc_char_desc_ind *p_param = (struct msrcu_evt_disc_char_desc_ind *)pv;
					
					uint8_t *param = (uint8_t *)pv;
					
//					PRINTD(DBG_TRACE, "found data :");
//					for(uint8_t j = 0 ; j<20;j++)
//					{
//						PRINTD(DBG_TRACE, "%02x ",param[j]);
//					}
//					PRINTD(DBG_TRACE, "\r\n");
					
					p_param->conidx = param[0];
					p_param->attr_hdl = ((param[1]<<8)&0xff00) | param[2];
					p_param->uuid_len = param[4];
					memcpy(p_param->uuid , &param[5] , p_param->uuid_len);
					
					
					msrcu_dev_ble_disc_set_state(EVT_BLE_DISC_IDLE);
					RefreshDiscTimeoutTimer();
					
					//store
					g_tMsrcuDCDIStore.conidx = p_param->conidx ;
					g_tMsrcuDCDIStore.char_info[g_tMsrcuDCDIStore.conidx].Char[g_tMsrcuDCDIStore.char_info->char_desc_num].attr_hdl  =  p_param->attr_hdl ;
					g_tMsrcuDCDIStore.char_info[g_tMsrcuDCDIStore.conidx].Char[g_tMsrcuDCDIStore.char_info->char_desc_num].uuid_len = p_param->uuid_len ;
					memcpy(g_tMsrcuDCDIStore.char_info[g_tMsrcuDCDIStore.conidx].Char[g_tMsrcuDCDIStore.char_info->char_desc_num].uuid , 
								p_param->uuid ,  p_param->uuid_len);
					
					
//					g_tMsrcuDiscCharDescInfoStore.char_info[g_tMsrcuDiscCharDescInfoStore.char_desc_num ].conidx  = p_param->conidx ;
//					g_tMsrcuDiscCharDescInfoStore.char_info[g_tMsrcuDiscCharDescInfoStore.char_desc_num ].attr_hdl  =  p_param->attr_hdl; 
//					g_tMsrcuDiscCharDescInfoStore.char_info[g_tMsrcuDiscCharDescInfoStore.char_desc_num ].uuid_len = p_param->uuid_len ;
//					memcpy(g_tMsrcuDiscCharDescInfoStore.char_info[g_tMsrcuDiscCharDescInfoStore.char_desc_num].uuid  ,
//									p_param->uuid ,  p_param->uuid_len);
				
//					
//					PRINTD(DBG_TRACE, "p_param->attr_hdl = %d , p_param->uuid_len = %d\r\n" , p_param->attr_hdl, p_param->uuid_len);
//					
//					PRINTD(DBG_TRACE, "g_tMsrcuDiscCharDescInfoStore.char_num = %d\r\n" , g_tMsrcuDiscCharDescInfoStore.char_desc_num);
//				
//					PRINTD(DBG_TRACE, "found uuid :");
//					for(uint8_t j = 0 ; j< p_param->uuid_len;j++)
//					{
//						PRINTD(DBG_TRACE, "%02x ",g_tMsrcuDiscCharDescInfoStore.char_info[g_tMsrcuDiscCharDescInfoStore.char_desc_num].uuid[j]);
//					}
//					PRINTD(DBG_TRACE, "\r\n");	
//					
//					g_tMsrcuDiscCharDescInfoStore.char_desc_num ++;		
					g_tMsrcuDCDIStore.char_info[g_tMsrcuDCDIStore.conidx].char_desc_num ++;					
				}
				break;
		
		default:
			return -1;
	}
    
    return 0;
}

static int msrcu_dev_ble_gatt_discovery_svc(void)
{
		int error = 0;

		inb_gatt_disc_t *p_read=(inb_gatt_disc_t*)malloc(sizeof(inb_gatt_disc_t));
		memset(p_read, 0, sizeof(inb_gatt_disc_t));

		p_read->start_hdl = 0x0001;
		p_read->end_hdl = 0xffff;
	
			error = inb_gatt_discovery(0,GATT_DISC_ALL_SVC,p_read);
				PRINTD(DBG_TRACE, "inb_gatt_discovery : error = %d",error);
    
    return error;
}

//static int msrcu_dev_ble_gatt_inc_svc_char(void)
//{
//		int error = 0;
//	
//		inb_gatt_disc_t *p_read=(inb_gatt_disc_t*)malloc(sizeof(inb_gatt_disc_t));
//		memset(p_read, 0, sizeof(inb_gatt_disc_t));

//		p_read->start_hdl = 0x0001;
//		p_read->end_hdl = 0xffff;
//	
//		error = inb_gatt_discovery(0,GATT_DISC_INCLUDED_SVC,p_read);
////			PRINTD(DBG_TRACE, "inb_gatt_discovery : error = %d",error);
//    
//    return error;
//}

static int msrcu_dev_ble_gatt_char(void)
{
		int error = 0;
	
		inb_gatt_disc_t *p_read=(inb_gatt_disc_t*)malloc(sizeof(inb_gatt_disc_t));
		memset(p_read, 0, sizeof(inb_gatt_disc_t));

		p_read->start_hdl = 0x0001;
		p_read->end_hdl = 0xffff;
	
		error = inb_gatt_discovery(0,GATT_DISC_ALL_CHAR,p_read);
//			PRINTD(DBG_TRACE, "inb_gatt_discovery : error = %d",error);
    
    return error;
}

static int msrcu_dev_ble_gatt_discovery_char(void)
{
		int error = 0;
	
		inb_gatt_disc_t *p_read=(inb_gatt_disc_t*)malloc(sizeof(inb_gatt_disc_t));
		memset(p_read, 0, sizeof(inb_gatt_disc_t));

		p_read->start_hdl = 0x0001;
		p_read->end_hdl = 0xffff;
	
		error = inb_gatt_discovery(0,GATT_DISC_DESC_CHAR,p_read);
//			PRINTD(DBG_TRACE, "inb_gatt_discovery : error = %d",error);
    
    return error;
}


static int BufferCmp(uint8_t *buf1 , uint8_t *buf2 , uint16_t len
)
{
	uint8_t i = 0;
	
	for(i = 0 ; i<len ; i++)
	{
		if(buf1[i] != buf2[i])
		{
			return -1;
		}
	}
    
	return 0 ;
}

int FindHandleForPermitWR(uint8_t condix, uint16_t* handle , uint8_t *uuid)
{
	uint16_t char_index = 0;// , desc_index = 0;
	
	//uint8_t buf[2] = {0x01,0x29};         /// Characteristic user description
	
	for(char_index = 0 ;char_index<g_tMsrcuDCDIStore.char_info[condix].char_desc_num  ; char_index++)
	{
		if(BufferCmp(g_tMsrcuDCDIStore.char_info[condix].Char[char_index].uuid  ,uuid, 
			g_tMsrcuDCDIStore.char_info[condix].Char[char_index].uuid_len  )==0)
		{
					*handle = g_tMsrcuDCDIStore.char_info[condix].Char[char_index].attr_hdl ;

					return 0;
		}
	}
    
	return -1;	
}

int FindHandleForPermitNTF(uint8_t condix, uint16_t* handle , uint8_t *uuid )
{
	uint16_t char_index , desc_index;
	
	uint8_t buf[2] = {0x02,0x29};     /// Client characteristic configuration
	
	for(char_index = 0 ;char_index < g_tMsrcuDCDIStore.char_info[condix].char_desc_num  ; char_index++)
	{
		if(BufferCmp(g_tMsrcuDCDIStore.char_info[condix].Char[char_index].uuid  ,uuid, 
			g_tMsrcuDCDIStore.char_info[condix].Char[char_index].uuid_len  )==0)
		{
			desc_index = char_index;
			
			for(;desc_index <g_tMsrcuDCDIStore.char_info[condix].char_desc_num  ; desc_index++)
			{
				if(BufferCmp(g_tMsrcuDCDIStore.char_info[condix].Char[desc_index].uuid , buf, 
				g_tMsrcuDCDIStore.char_info[condix].Char[desc_index].uuid_len )==0 )
				{
					*handle = g_tMsrcuDCDIStore.char_info[condix].Char[desc_index].attr_hdl ;
				
					return 0;
				}
			}
		}
	}

	return -1;
}

