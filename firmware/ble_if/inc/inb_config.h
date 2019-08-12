/**
 ****************************************************************************************
 *
 * @file inb_config.h
 *
 * @brief BLE config parameters header file 
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 *
 ****************************************************************************************
 */
#ifndef INB_CONFIG_H
#define INB_CONFIG_H

/// Broadcaster
#if (defined(CFG_BROADCASTER) || defined(CFG_PERIPHERAL) || defined(CFG_ALLROLES))
#define BLE_BROADCASTER      1
#else
#define BLE_BROADCASTER      0
#endif // (defined(CFG_BROADCASTER) || defined(CFG_PERIPHERAL) || defined(CFG_ALLROLES))

/// Observer
#if (defined(CFG_OBSERVER) || defined(CFG_CENTRAL) || defined(CFG_ALLROLES))
#define BLE_OBSERVER      1
#else
#define BLE_OBSERVER      0
#endif // (defined(CFG_OBSERVER) || defined(CFG_CENTRAL) || defined(CFG_ALLROLES))

/// Central
#if (defined(CFG_CENTRAL) || defined(CFG_ALLROLES))
#define BLE_CENTRAL      1
#else
#define BLE_CENTRAL      0
#endif // (defined(CFG_CENTRAL) || defined(CFG_ALLROLES))

/// Peripheral
#if (defined(CFG_PERIPHERAL) || defined(CFG_ALLROLES))
#define BLE_PERIPHERAL      1
#else
#define BLE_PERIPHERAL      0
#endif // (defined(CFG_PERIPHERAL) || defined(CFG_ALLROLES))

#if ((BLE_BROADCASTER+BLE_OBSERVER+BLE_PERIPHERAL+BLE_CENTRAL) == 0)
#error "No application role defined"
#endif // ((BLE_BROADCASTER+BLE_OBSERVER+BLE_PERIPHERAL+BLE_CENTRAL) == 0)

#define BLE_ACTIVITY_MAX          (CFG_CON)

/// Maximum number of simultaneous connections
#if (BLE_CENTRAL || BLE_OBSERVER)
#define BLE_CONNECTION_MAX      (CFG_CON)
#elif (BLE_PERIPHERAL)
#define BLE_CONNECTION_MAX      (1)
#else
#define BLE_CONNECTION_MAX      (0)
#endif /* #if (BLE_CENTRAL) */

#if defined(CFG_SEC_CON)
#define SECURE_CONNECTIONS        (1)
#else // !defined(CFG_SEC_CON)
#define SECURE_CONNECTIONS        (0)
#endif // defined(CFG_SEC_CON)

#if CFG_HCI
#define HCI_TL_SUPPORT      1
#else //defined(CFG_HCITL)
#define HCI_TL_SUPPORT      0
#endif //defined(CFG_HCITL)

/// Use 32K Hz Clock if set to 1 else 32,768k is used
#define HZ32000 	CFG_BLE_PARAM_LPC_32K_EN

#define TASK_MASK (9 + CFG_NB_PRF + 1)

#define HCI_NB_CMD_PKTS   (5 * HCI_TL_SUPPORT)

#define BLE_NORMAL_WIN_SIZE              14

#define BLE_PHY_CODED_NORMAL_WIN_SIZE   (BLE_NORMAL_WIN_SIZE * 8)

/// RSSI threshold for interference detection (in dBm)
#define BLE_CH_ASSESS_RSSI_INTERF_THR   (CFG_BLE_PARAM_CA_RSSI_THRD)

/// Channel map update period (in sec)
#define BLE_CH_MAP_UPDATE_PERIOD         (CFG_BLE_PARAM_CA_UPD_PER)

/// Maximum duration without receiving a packet before considering a channel quality unknown  (in slots) (2 secs)
#define BLE_CH_ASSESS_VALID_TO       0x1900

/// Maximum duration without receiving a packet before reintroducing a channel to the map (in slots) (20 secs)
#define BLE_CH_REASSESS_TO           0x7D00

/// Maximum counter value for channel assessment
#define BLE_CH_ASSESS_COUNT_MAX      (CFG_BLE_PARAM_CA_MAX_COUNT)

/// Counter threshold to consider a channel bad
#define BLE_CH_ASSESS_COUNT_THR_BAD  (CFG_BLE_PARAM_CA_BAD_CH_THRD)

/// Minimum counter value for channel assessment
#define BLE_CH_ASSESS_COUNT_MIN      (CFG_BLE_PARAM_CA_MIN_COUNT)

/// Maximum number of ADV reports in the HCI queue to Host
#define BLE_MAX_NB_ADV_REP_FRAG       (4 * HCI_TL_SUPPORT)

#define BLE_WHITELIST_MAX           			(CFG_BLE_PARAM_WL_MAX)

#define BLE_RESOL_ADDR_LIST_MAX     	(CFG_BLE_PARAM_RAL_MAX)

#define BLE_RX_DESC_NB               			(6)

/// Number of TX descriptors per BLE connection [2|3|4]
#define BLE_NB_TX_DESC_PER_CON          2

/// Number of advertising or scan response data fragments in extended advertising PDU chain
#define BLE_ADV_FRAG_NB_TX           (CFG_BLE_ADV_FRAG_NB_TX) //(5)
/// Size of advertising or scan response data fragments in extended advertising PDU chain
#define BLE_ADV_FRAG_SIZE_TX        (CFG_BLE_ADV_FRAG_SIZE_TX)// (254)

/// Number of TX descriptors per advertising set
#define BLE_NB_TX_DESC_PER_ADV          (2+BLE_ADV_FRAG_NB_TX)

#if (BLE_NB_TX_DESC_PER_CON > BLE_NB_TX_DESC_PER_ADV)
#define BLE_NB_TX_DESC_PER_ACT          (BLE_NB_TX_DESC_PER_CON)
#else //(BLE_NB_TX_DESC_PER_CON > BLE_NB_TX_DESC_PER_ADV)
#define BLE_NB_TX_DESC_PER_ACT          (BLE_NB_TX_DESC_PER_ADV)
#endif //(BLE_NB_TX_DESC_PER_CON > BLE_NB_TX_DESC_PER_ADV)

#define BLE_TX_DESC_NB               			((BLE_NB_TX_DESC_PER_ACT * BLE_ACTIVITY_MAX))

#define BLE_LLCPTXBUF_NB        				(2*BLE_ACTIVITY_MAX)

/// Number of advertising data buffers
#define BLE_ADV_BUF_NB_TX            			(CFG_BLE_ADV_BUF_NB_TX)//(BLE_ACTIVITY_MAX)

/// Number of RX data buffers (common for all activities)
#define BLE_DATA_BUF_NB_RX           		(BLE_RX_DESC_NB + 3)

/// Number of TX ACL data buffers
#if !CFG_SDR
#define BLE_ACL_BUF_NB_TX            			(BLE_ACTIVITY_MAX + 2)
#else
#define BLE_ACL_BUF_NB_TX            			((BLE_ACTIVITY_MAX + 2) + \
																			(CFG_SDR_NB_TX_BUF))
#endif

#if (BLE_OBSERVER)
#define BLE_DUPLICATE_FILTER_MAX    	(CFG_BLE_PARAM_DUP_FILT_MAX)
#endif //(BLE_OBSERVER)

#define TASK_MAX 										(10 + CFG_NB_PRF)

#if (BLE_CENTRAL || BLE_PERIPHERAL)
#define BLE_L2CM                    1
#define BLE_L2CC                    1
#define BLE_ATTC                    1
#define BLE_ATTS                    1
#define BLE_ATTM                    1
#define BLE_GATTM                   1
#define BLE_GATTC                   1
#define BLE_SMPC						1
#define BLE_LECB						1
#else //(BLE_CENTRAL || BLE_PERIPHERAL)
#define BLE_L2CM                    0
#define BLE_L2CC                    0
#define BLE_ATTC                    0
#define BLE_ATTS                    0
#define BLE_ATTM                    0
#define BLE_GATTM                   0
#define BLE_GATTC                   0
#define BLE_SMPC						0
#define BLE_LECB						0
#endif //(BLE_CENTRAL || BLE_PERIPHERAL)

#if CFG_HCI
void hci_enable(void);
bool isHciEnable(void);
#endif

#endif	/* INB_CONFIG_H */

