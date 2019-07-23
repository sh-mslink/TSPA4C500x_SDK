#include <stdlib.h>

#include "gap_test.h"
#include ".\ble\inb_gatt_evt.h"
#include "ble_test.h"
#include "msg.h"

#ifdef CFG_PROJ_RCU
#include "msrcu_app.h"
extern msrcuBleBondData_t msrcuBondData;
#endif

static char gDeviceName[249]={"Tropos"};
static uint16_t gAppearance=0;

inb_ltk_t ble_bond_data[2] = {0};


void dump_addr(inb_bdaddr_t addr)
{
	PRINTD(DBG_ERR, "addr %d %02x:%02x:%02x:%02x:%02x:%02x\r\n", addr.addr_type, addr.addr.addr[0], addr.addr.addr[1], 
		addr.addr.addr[2], addr.addr.addr[3], addr.addr.addr[4], addr.addr.addr[5] );
}

int handle_default_gap_evt(uint16_t eid, void *pv, void *param)
{
	//PRINTD(DBG_TRACE, "\n%s  id 0x%x\r\n", __func__, eid);

	switch(eid) 
	{
		case GAP_EVT_PEER_NAME_IND:
			{
				//GAPM_PEER_NAME_IND
//				inb_evt_peer_name_ind_t *ind = (inb_evt_peer_name_ind_t *)pv;
//				int i=0;
//				 inb_addr_t addr=ind->addr;
//				uint8_t name_len=ind->name_len;
//				uint8_t name[249]={0};
//				memcpy(name, ind->name,name_len);
//				PRINTD(DBG_TRACE, "        device name: ");
//				for(i=0;i<name_len;i++)
//				{
//					PRINTD(DBG_TRACE, "%c", name[i]);
//				}
			}
				break;
		case GAP_EVT_SYNC_ESTABLISHED:
			{
				//GAPM_SYNC_ESTABLISHED_IND
//				inb_evt_sync_established_ind_t *ind = (inb_evt_sync_established_ind_t *)pv;
//				PRINTD(DBG_TRACE, " controller has successfully synchronized with a periodic advertising");
			}
				break;
		case GAP_EVT_RX_SCAN_REQ:
				{
					//GAPM_SCAN_REQUEST_IND
					//not find in doc
//					inb_evt_rx_scan_req_t *ind=(inb_evt_rx_scan_req_t*)pv;
//					inb_bdaddr_t trans_addr=ind->trans_addr;
//					PRINTD(DBG_TRACE, " Receive Scan request information       Transmitter device address : ");
//					dump_addr(ind->trans_addr);
				}
			break;
		case GAP_EVT_ADV_REPORT:
			{
				//inb_evt_adv_rpt_ind_t *ind = (inb_evt_adv_rpt_ind_t *)pv;
				//uint8_t length=temp->length;
				//inb_evt_adv_rpt_ind_t *ind=(void*)malloc(sizeof(inb_evt_adv_rpt_ind_t)+length);
#if 0
				PRINTD(DBG_TRACE, "scan receive 68 ...\r\n");
				if(mode == NO_PAYLOAD)
				{
					if (ind->trans_addr.addr.addr[0] == 0x63/* && ind->info == 0x39*/)
					PRINTD(DBG_ERR, "actv_idx= 0x%x info=0x%x  tx_pwr=0x%x rssi=0x%x length=0x%x data0=0x%x  data1=0x%x data4=0x%x data5=0x%x data6=0x%x\r\n",ind->actv_idx, ind->info, ind->tx_pwr, ind->rssi,ind->length,ind->data[0],ind->data[1],ind->data[4],ind->data[5],ind->data[6]);
					if (memcmp(ind->trans_addr.addr.addr, arduino_bd_address, sizeof(arduino_bd_address)) == 0)
					{

						if (rx_tx_pwr != ind->tx_pwr) {
						rx_tx_pwr = ind->tx_pwr;
						PRINTD(DBG_ERR, "recv data 0x%x\r\n", ind->tx_pwr);
						toggle_led();
						
						}
						if ((ind->length >= 3) && (adv_name_data != ind->data[2])) {
						adv_name_data =ind->data[2];
						PRINTD(DBG_ERR, "=====recv dav data 0x%x=========\r\n", adv_name_data);
						//toggle_led();				
						}
						
					}
				}
				else{
				//arduino test code
				if (ind->trans_addr.addr.addr[0] == 0x63/* && ind->info == 0x39*/)
				{
					PRINTD(DBG_ERR, "actv_idx= 0x%x info=0x%x  tx_pwr=0x%x rssi=0x%x length=0x%x data0=0x%x  data1=0x%x data4=0x%x data5=0x%x data6=0x%x\r\n",ind->actv_idx, ind->info, ind->tx_pwr, ind->rssi,ind->length,ind->data[0],ind->data[1],ind->data[4],ind->data[5],ind->data[6]);
					//PRINTD(DBG_ERR, "actid = %d  pwr=%d data=0x%x rssi=%d\r\n",ind->actv_idx, ind->tx_pwr, ind->length, ind->rssi);
					if (memcmp(ind->trans_addr.addr.addr, arduino_bd_address, sizeof(arduino_bd_address)) == 0)
					{
						PRINTD(DBG_TRACE, "trans_addr\r\n");
						dump_addr(ind->trans_addr);
						
						PRINTD(DBG_TRACE, "target_addr\r\n");
						dump_addr(ind->target_addr);
						if (recv_data != ind->data[5]) {
						recv_data = ind->data[5];
						PRINTD(DBG_ERR, "recv data 0x%x\r\n",ind->data[5]);
						toggle_led();
						}
					}
						
				}

				}
#endif
				//dump_addr(ind->trans_addr);
			}
				break;
		case GAP_EVT_ACTIVITY_STOP:
			{
				inb_evt_act_stop_ind_t *p_para = (inb_evt_act_stop_ind_t *)pv;
				msg_actv_stop_t *msg = (msg_actv_stop_t *)malloc(sizeof(msg_actv_stop_t));
				if (msg) {
					msg->msg_id = MSG_ACTV_STOP;
					msg->actv_idx = p_para->actv_idx;
					msg->actv_type = p_para->actv_type;
					msg->reason = p_para->reason;
					msg->per_adv_stop = p_para->per_adv_stop;
					
					/// Post a message to main task to delete the activity
					msg_put(msg);
					/*status = osMessagePut(h_msg_q_id, (uint32_t)msg, 0) ;
					if (status != osOK) {
						PRINTD(DBG_ERR, "line:%d  OS error,%d\r\n", __LINE__, status);
					}*/
				}
			}
			break;

		case GAP_EVT_DEV_RND_ADDR_INFO:
			{
				//GAPM_DEV_BDADDR_IND
				inb_evt_rnd_addr_ind_t *ind = (inb_evt_rnd_addr_ind_t *)pv;
				PRINTD(DBG_TRACE, "  Random address being used information  addr:");
				dump_addr(ind->addr);
			}
			break;
		case GAP_EVT_KEYPRESS_IND:
			{
				//GAPC_KEY_PRESS_NOTIFICATION_IND
				//not find in doc
				inb_evt_keypress_ind_t *ind = (inb_evt_keypress_ind_t *)pv;
				uint8_t notification_type=ind->notification_type;
				PRINTD(DBG_TRACE, " notification_type :%d",notification_type);
			}
			break;
		case GAP_EVT_GET_DEV_INFO_REQ: 
			{
				inb_evt_get_dev_info_req_t *ind = (inb_evt_get_dev_info_req_t *)pv;
				inb_get_dev_info_cfm_t cfm={0};
				PRINTD(DBG_TRACE, " req :%d",ind->req);	
				cfm.req=ind->req;
				switch (cfm.req)
				{
					case DEV_NAME:
						{
							cfm.u.name.length=strlen(gDeviceName);
							memcpy(cfm.u.name.value,gDeviceName,strlen(gDeviceName));
						}
						break;
					case DEV_APPEARANCE:
						{
							cfm.u.appearance = gAppearance;
						}
						break;
					case DEV_SLV_PREF_PARAMS:
						{
							// Slave preferred Connection interval Min
							cfm.u.slv_pref_params.con_intv_min = 6;
							// Slave preferred Connection interval Max
							cfm.u.slv_pref_params.con_intv_max = 6;
							// Slave preferred Connection latency
							cfm.u.slv_pref_params.slave_latency  = 0;
							// Slave preferred Link supervision timeout
							cfm.u.slv_pref_params.conn_timeout    = 250;
						}
						break;
					default:
						break;
				}
				inb_conn_get_dev_info_cfm(ind->conidx,&cfm);
			}
			break;
		case GAP_EVT_SET_DEV_INFO_REQ:  //not find in doc
			{
				inb_evt_set_dev_info_req_t *ind=(inb_evt_set_dev_info_req_t *)pv;
				inb_set_dev_info_cfm_t cfm;

				cfm.req = ind->req;
				if (ind->req == 0) {	/// name
					memcpy(gDeviceName, ind->info.name.value, ind->info.name.length);
					gDeviceName[ind->info.name.length] = 0;
					PRINTD(DBG_TRACE, " device name : %s\r\n", gDeviceName);
				} else {		/// apperance
					gAppearance = ind->info.appearance;
					PRINTD(DBG_TRACE, " Device Appearance Icon : 0x%02X\r\n",gAppearance);
				}
				cfm.status = 0;
				inb_conn_set_dev_info_cfm(ind->conidx, &cfm);
			}
			break;
		case GAP_EVT_PING_TO_IND:  //not find in doc
			{
				//GAPC_LE_PING_TO_IND   ???
			}
			break;
		case GAP_EVT_SIGNED_COUNTER_UPD:    //not find in doc  
			{
				//GAPC_SIGN_COUNTER_IND
				inb_evt_sign_counter_ind_t *ind = (inb_evt_sign_counter_ind_t *)pv;
				PRINTD(DBG_TRACE, "local_sign_counter :%d  , peer_sign_counter :%d",ind->local_sign_counter,ind->peer_sign_counter);
			}
			break;
		case GAP_EVT_DISCONNECT:
			{
				/// Post a message to main task to re-start activity
				inb_evt_disc_ind_t *p_para = (inb_evt_disc_ind_t *)pv;
				//PRINTD(DBG_TRACE, "(%d) Disconnect, %d\r\n", p_para->conidx, p_para->reason);				

				msg_disc_t *msg = (msg_disc_t *)malloc(sizeof(msg_disc_t));
				if (msg) {
					msg->msg_id = MSG_DISC;
					msg->conidx = p_para->conidx;

					/// Post a message to main task to re-start connection
					msg_put(msg);
					/*status = osMessagePut(h_msg_q_id, (uint32_t)msg, 0) ;
					if (status != osOK) {
						PRINTD(DBG_ERR, "line:%d  OS error,%d\r\n", __LINE__, status);
					}*/
				}
			}
			break;
		case GAP_EVT_CONN_REQ:
			{
				inb_evt_conn_req_t *p_para = (inb_evt_conn_req_t *)pv;

				/// issue confirm to accept connection..
				inb_conn_cfm_t cfm;
				if (param){
					memcpy(&cfm, param, sizeof(inb_conn_cfm_t));
				}else{
					memset(&cfm, 0, sizeof(inb_conn_cfm_t));
					cfm.auth = AUTH_REQ_NO_MITM_BOND;
				}
				inb_conn_cfm(p_para->conidx, &cfm);

				/// Post a message to enable profiles
				msg_connected_t *msg = (msg_connected_t *)malloc(sizeof(msg_connected_t));
				if (msg) {
					msg->msg_id = MSG_CONNECTED;
					msg->conidx = p_para->conidx;
					msg->con_interval = p_para->con_interval;
					msg->con_latency = p_para->con_latency;
					msg->sup_to = p_para->sup_to;
					msg->clk_accuracy = p_para->clk_accuracy;
					msg->peer_addr_type = p_para->peer_addr_type;
					memcpy(msg->peer_addr.addr, p_para->peer_addr.addr, BLE_BDADDR_LEN);

					/// Post a message to main task to re-start connection
					msg_put(msg);
					/*status = osMessagePut(h_msg_q_id, (uint32_t)msg, 0) ;
					if (status != osOK) {
						PRINTD(DBG_ERR, "line:%d  OS error,%d\r\n", __LINE__, status);
					}*/
				}
			}
			break;
		case GAP_EVT_BOND_REQ:
			{
				inb_bond_cfm_t cfm;
				inb_evt_bond_req_ind_t *p_para = (inb_evt_bond_req_ind_t *)pv;

				switch (p_para->request)
				{
					case PAIRING_REQ:
						{
							cfm.request = 	PAIRING_RSP;
							cfm.accept = 1;

							cfm.u.pairing_feat.iocap = IO_CAP_NO_INPUT_NO_OUTPUT;
							cfm.u.pairing_feat.oob = OOB_AUTH_DATA_NOT_PRESENT;
							cfm.u.pairing_feat.auth = AUTH_REQ_NO_MITM_BOND;
							cfm.u.pairing_feat.key_size = 16;
							cfm.u.pairing_feat.ikey_dist = KDIST_ENCKEY|KDIST_IDKEY|KDIST_SIGNKEY;
							cfm.u.pairing_feat.rkey_dist = KDIST_ENCKEY|KDIST_IDKEY|KDIST_SIGNKEY;
							cfm.u.pairing_feat.sec_req = NO_SEC;

						}	
						break;
					case PAIRING_RSP:
						{
							//PRINTD(DBG_TRACE, "\n", p_para->data.);
						}
						break;
					case TK_EXCH:
						{
						    /// Generate a PIN Code- (Between 100000 and 999999)
						    uint32_t pin_code = (100000 + (rand()%900000));
						cfm.accept = 1;

							cfm.request = TK_EXCH;
							memset(cfm.u.tk.key, 0, BLE_KEY_LEN);
							//PRINTD(DBG_TRACE, "pin %06d \n", pin_code);

						    cfm.u.tk.key[0] = (uint8_t)((pin_code & 0x000000FF) >>  0);
						    cfm.u.tk.key[1] = (uint8_t)((pin_code & 0x0000FF00) >>  8);
						    cfm.u.tk.key[2] = (uint8_t)((pin_code & 0x00FF0000) >> 16);
						    cfm.u.tk.key[3] = (uint8_t)((pin_code & 0xFF000000) >> 24);
						}
						break;
					case IRK_EXCH:
						{
						}
						break;
					case CSRK_EXCH:
            cfm.accept = 1;
						{
            cfm.request = CSRK_EXCH;
							for (uint32_t i = 0; i < 16; i+=4) {
								uint32_t rnb = rand();

								cfm.u.csrk.key[i+0] = (uint8_t)rnb;
								cfm.u.csrk.key[i+1] = (uint8_t)(rnb>>8);
								cfm.u.csrk.key[i+2] = (uint8_t)(rnb>>16);
								cfm.u.csrk.key[i+3] = (uint8_t)(rnb>>24);
							}
						}
						break;
					case LTK_EXCH:
            cfm.accept = 1;
						{
            cfm.request = LTK_EXCH;
							for (uint32_t i = 0; i < 8; i+=4) {
								uint32_t rnb = rand();
								cfm.u.ltk.randnb.nb[i+0] = (uint8_t)rnb;
								cfm.u.ltk.randnb.nb[i+1] = (uint8_t)(rnb>>8);
								cfm.u.ltk.randnb.nb[i+2] = (uint8_t)(rnb>>16);
								cfm.u.ltk.randnb.nb[i+3] = (uint8_t)(rnb>>24);
							}

							for (uint32_t i = 0; i < 16; i+=4) {
								uint32_t rnb = rand();

								cfm.u.ltk.ltk.key[i+0] = (uint8_t)rnb;
								cfm.u.ltk.ltk.key[i+1] = (uint8_t)(rnb>>8);
								cfm.u.ltk.ltk.key[i+2] = (uint8_t)(rnb>>16);
								cfm.u.ltk.ltk.key[i+3] = (uint8_t)(rnb>>24);
							}
							cfm.u.ltk.key_size = 16;
							cfm.u.ltk.ediv = (uint16_t)rand() ;           
                    memcpy(&ble_bond_data[GAP_BOND_DATA], (uint8_t*)&cfm.u.ltk, sizeof(inb_ltk_t));            
#ifdef CFG_PROJ_RCU    
                    memcpy(msrcuBondData.ltk.key, cfm.u.ltk.ltk.key, BLE_KEY_LEN); 
                    msrcuBondData.ediv = cfm.u.ltk.ediv; 
                    memcpy(msrcuBondData.randNb.nb, cfm.u.ltk.randnb.nb, BLE_RANDOM_NB_LEN); 
                    msrcuBondData.keySize = cfm.u.ltk.key_size;                                                   
#endif                    
//                    memcpy(&ble_bond_data[GAP_BOND_DATA], (uint8_t*)0x37F000, sizeof(inb_ltk_t));  
//                    PRINTD(DBG_TRACE, "ediv 0x%x\n", ble_bond_data[GAP_BOND_DATA].ediv);
//                    PRINTD(DBG_TRACE, "\n rand ");
//                    for (int i = 0; i < 8; i++) {
//                        PRINTD(DBG_TRACE, "0x%02x ", ble_bond_data[GAP_BOND_DATA].randnb.nb[i]);
//                    }
//                    PRINTD(DBG_TRACE, "\n ");
//                    
//                    PRINTD(DBG_TRACE, "LTK_EXCH\n ");    
//                    PRINTD(DBG_TRACE, "size %d ediv 0x%X\r\n", cfm.u.ltk.key_size,  cfm.u.ltk.ediv);
//                    PRINTD(DBG_TRACE, "ltk 0x" );
//                    for(int i = 0; i < 16; i++)
//                        PRINTD(DBG_TRACE, "%02X ", cfm.u.ltk.ltk.key[i]);
//                    PRINTD(DBG_TRACE, "\r\n rand 0x" );
//                    for(int i = 0; i < 8; i++)
//                        PRINTD(DBG_TRACE, "%02X ", cfm.u.ltk.randnb.nb[i]);
//                    PRINTD(DBG_TRACE, "\r\n");       
						}
						break;
					
						
					case OOB_EXCH:
						break;
					case NC_EXCH:
						break;
					case REPEATED_ATTEMPT:
						break;
					default:
						break;
				}

				inb_conn_bond_cfm(p_para->conidx, &cfm);
			}
			break;
		case GAP_EVT_BOND_IND:
			{
				inb_evt_bond_ind_t *p_para = (inb_evt_bond_ind_t *)pv;
				msg_pair_t *msg = (msg_pair_t *)malloc(sizeof(msg_pair_t));

				if (!msg)
					break;

				msg->msg_id = MSG_PAIR;
				msg->conidx = p_para->conidx;

				switch (p_para->info) {
					case PAIRING_SUCCEED:
            //PRINTD(DBG_TRACE, "pair success...\r\n");
						msg->status = 1;
						break;
					case PAIRING_FAILED:
            //PRINTD(DBG_TRACE, "pair failed...\r\n");
						msg->status = 0;
						break;
					case LTK_EXCH:
                        /// Save the keys
//                        PRINTD(DBG_TRACE, "size %d ediv 0x%X\r\n", p_para->data.ltk.key_size,  p_para->data.ltk.ediv);
//                        PRINTD(DBG_TRACE, "ltk 0x" );
//                        for(int i = 0; i < 16; i++)
//                            PRINTD(DBG_TRACE, "%02X ", p_para->data.ltk.ltk.key[i]);                   
//                        PRINTD(DBG_TRACE, "\r\n rand 0x" );
//                        for(int i = 0; i < 8; i++)
//                            PRINTD(DBG_TRACE, "%02X ", p_para->data.ltk.randnb.nb[i]);
//                        PRINTD(DBG_TRACE, "\r\n");
//                        memcpy(&ble_bond_data[GAP_BOND_PEER_DATA], &p_para->data.ltk, sizeof(ble_bond_data[0]));
						break;	
					case CSRK_EXCH:
						break;
					case IRK_EXCH:
						break;
					default:
						break;
				}

//		        	PRINTD(DBG_ERR, "GAP_EVT_BOND_IND %d\r\n", p_para->info);
		        	if (p_para->info == PAIRING_SUCCEED) {

					/// Post a message to main task to re-start connection
					msg_put(msg);
					/*status = osMessagePut(h_msg_q_id, (uint32_t)msg, 0) ;
					if (status != osOK) {
						PRINTD(DBG_ERR, "line:%d  OS error,%d\r\n", __LINE__, status);
					}*/
		       	 }
			}
			break;
		case GAP_EVT_SECURITY_IND:
#if 1
			{
				inb_evt_security_ind_t* p_para = (inb_evt_security_ind_t*)pv;

				msg_bond_t *msg = (msg_bond_t*)malloc(sizeof(msg_bond_t));
				if (!msg)	break;

				msg->msg_id = MSG_BOND;
				msg->conidx = p_para->conidx;
				msg->auth = p_para->auth;

				/// Post a message to main task to re-start connection
				msg_put(msg);
				/*status = osMessagePut(h_msg_q_id, (uint32_t)msg, 0) ;
				if (status != osOK) {
					PRINTD(DBG_ERR, "line:%d  OS error,%d\r\n", __LINE__, status);
				}*/
			}
#else
				{
					inb_evt_security_ind_t* p_para = (inb_evt_security_ind_t*)pv;
					//PRINTD(DBG_TRACE, "auth level is %d\r\n", p_para->auth);
					if (p_para->auth == AUTH_REQ_NO_MITM_BOND){
						inb_pairing_t bond;

						bond.iocap = IO_CAP_DISPLAY_ONLY;
						bond.oob = OOB_AUTH_DATA_NOT_PRESENT;
						bond.auth = p_para->auth;//AUTH_REQ_MITM_BOND
						bond.key_size = 16;
						bond.ikey_dist = KDIST_ENCKEY | KDIST_IDKEY | KDIST_SIGNKEY;
						bond.rkey_dist = KDIST_ENCKEY | KDIST_IDKEY | KDIST_SIGNKEY;
						bond.sec_req = NO_SEC;
			
						int ret = inb_conn_bond(p_para->conidx, &bond);
						//PRINTD(DBG_TRACE, "inb_conn_bond return 0x%x\r\n", ret);

						{
							osTimerId id;                                            // timer id
							uint32_t  timerDelay;                                    // timer value
							osStatus  status;                                        // function return status

							osTimerDef (Timer, Time_Callback);    
 
							// Create periodic timer
							uint32_t  exec = p_para->conidx;
							id = osTimerCreate (osTimer(Timer), osTimerOnce, &exec);
							if (id)  {
								timerDelay = 1000;
								status = osTimerStart (id, timerDelay);                // start timer
								if (status != osOK)  {
									// Timer could not be started
								} 
							}
						}
					}
				}

#endif
			break;
		case GAP_EVT_ENCRYPT_REQ: {
//		        PRINTD(DBG_TRACE, "GAP_EVT_ENCRYPT_REQ\n");
		        inb_evt_encrypt_req_ind_t* p_para = (inb_evt_encrypt_req_ind_t*)pv;
		        inb_conn_encrypt_cfm_t cfm;
//		        PRINTD(DBG_TRACE, "ediv 0x%x\n", p_para->ediv);
//		        PRINTD(DBG_TRACE, "\n rand ");
//		        for (int i = 0; i < 8; i++) {
//		            PRINTD(DBG_TRACE, "0x%02X ", p_para->rand_nb.nb[i]);
//		        }
//		        PRINTD(DBG_TRACE, "\n ");
		        cfm.found = 0;
		        for (int i = 0; i < sizeof(ble_bond_data) / sizeof(ble_bond_data[0]); i++)
                {
//                    PRINTD(DBG_TRACE, "ediv 0x%x\n", ble_bond_data[i].ediv);
//                    PRINTD(DBG_TRACE, "\n rand ");
//                    for (int i = 0; i < 8; i++) {
//                        PRINTD(DBG_TRACE, "0x%02x ", ble_bond_data[i].randnb.nb[i]);
//                    }
//                    PRINTD(DBG_TRACE, "\n ");
		            if (p_para->ediv == ble_bond_data[i].ediv && !memcmp(p_para->rand_nb.nb, ble_bond_data[i].randnb.nb, BLE_RAND_NB_LEN)) {
		                cfm.found = 1;
		                cfm.key_size = ble_bond_data[i].key_size;
		                memcpy(cfm.ltk.key, ble_bond_data[i].ltk.key, BLE_KEY_LEN);
		                //PRINTD(DBG_TRACE, "get key \n ");
		                break;
		            }
		        }
//		        PRINTD(DBG_TRACE, "ltk size %d \n ltk ", cfm.key_size);
//		        for (int i = 0; i < 16; i++) {
//		            PRINTD(DBG_TRACE, "0x%02x ", cfm.ltk.key[i]);
//		        }
//		        PRINTD(DBG_TRACE, "\n ");
		        inb_conn_req_encrypt_cfm(p_para->conidx, &cfm);
                                                                
                msg_pair_t *msg = (msg_pair_t *)malloc(sizeof(msg_pair_t));
                if(!msg)
                    break;
                msg->msg_id = MSG_PAIR;
                msg->conidx = p_para->conidx;
                msg->status = 1;            
				msg_put(msg);
            
		    } break;
		case GAP_EVT_ENCRYPT_IND:
			{
				//GAPC_ENCRYPT_IND
//				inb_evt_encrypt_ind_t *ind = (inb_evt_encrypt_ind_t *)pv;	
//				PRINTD(DBG_TRACE, "encryption procedure succeed. Authentication  level:  %d\r\n",ind->auth);
			}
			break;
			
		case GAP_EVT_CONN_PARAM_UPD_REQ:
//			PRINTD(DBG_TRACE, "GAP_EVT_CONN_PARAM_UPD_REQ\n");
//       			 inb_evt_conn_param_upd_req_t* p_para = (inb_evt_conn_param_upd_req_t*)pv;
//      			 inb_conn_param_update_cfm(p_para->conidx, 1, 0x1, 0xff);
			break;
		case GAP_EVT_CONN_PARAM_UPD:
			{
				inb_evt_conn_param_upd_t *ind = (inb_evt_conn_param_upd_t *)pv;
				//PRINTD(DBG_TRACE, " Connection parameters updated. Connection interval value:%d ,Connection latency value:%d,Supervision timeout:%d \r\n",ind->con_interval,ind->con_latency,ind->sup_to);
			
				msg_con_param_upd_t *msg = (msg_con_param_upd_t *)malloc(sizeof(msg_con_param_upd_t));
				if (msg) {
					msg->msg_id = MSG_CON_PARAM_UPD;
					msg->conidx = ind->conidx;
					msg->con_interval = ind->con_interval;
					msg->con_latency = ind->con_latency;
					msg->sup_to = ind->sup_to;

					msg_put(msg);
                }
            }
			break;
		case GAP_EVT_CONN_PHY_UPD:
			{
				inb_evt_phy_upd_t *ind = (inb_evt_phy_upd_t *)pv;
				PRINTD(DBG_TRACE, "PHY for transmission:%d,PHY for reception:%d\r\n",ind->phy.tx_phy,ind->phy.rx_phy);
			}
			break;
		default:
			return -1;
	}
    
	return 0;
}








