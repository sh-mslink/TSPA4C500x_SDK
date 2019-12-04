/**
 ****************************************************************************************
 *
 * Auto Generated Project Configuration File
 *
 * @file IN_CONFIG(PROJ_TPPS).H
 *
 * @brief Project Configuration File
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
#ifndef IN_CONFIG_H
#define IN_CONFIG_H

/// @Misc::TSPA4C500X
#define CFG_TSPA4C500X	1
#define CFG_FPGA	0
/// @Misc::OTA
#define CFG_FW_UPD_EN	0
/// @Misc::PM
#define CFG_PM_EN	1
#define CFG_PM_DEEP_SLEEP_THRD	5
#define CFG_PM_DEEP_SLEEP_COMP_TIME	2000
#define CFG_PM_WUP_SLP_TMR	1
#define CFG_PM_WUP_BLE	1
#define CFG_PM_WUP_BROWN_OUT	0
#define CFG_PM_WUP_MIX_SIGNAL	0
#define CFG_PM_RETN_1_4K	1
#define CFG_PM_RETN_2_4K	1
#define CFG_PM_RETN_8K	1
#define CFG_PM_RETN_16K	1
#define CFG_PM_RETN_32K	1
/// @Misc::RAM
#define CFG_RAM_BASE_ADDR	0x201000
#define CFG_RAM_SIZE	0xf000
#define CFG_STACK_SIZE	0x400
#define CFG_HEAP_SIZE	0xc00
/// @Misc::DEBUG
#define DBG_ERR	0x01
#define DBG_WARN	0x02
#define DBG_TRACE	0x04
#define CFG_DBG_EN	1
#define CFG_DBG_IF_UART	1
#define CFG_DBG_IF_UART_PORT	0
#define CFG_DBG_IF_UART_BAUD	115200
#define CFG_DBG_IF_RTT_VIEW	0
#define CFG_DBG_FLAG	0x00000007
/// @Misc::CLOCK
#define CFG_ROOT_CLK	64000000
#define CFG_D0_CLK	32000000
#define CFG_D1_CLK	32000000
#define CFG_D2_CLK	32000000
#define CFG_TIM1_CLK	16000000
#define CFG_HWACC_CLK	32000000
#define CFG_SADC_CLK	1000000
#define CFG_EFUSE_CLK	8000000
#define CFG_SMEM_CLK	32000000
#define CFG_QSPI_CLK	64000000
#define CFG_AUDIO_CODEC_CLK_MUX	0
#define CFG_SI2S_CLK_MUX	1
#define CFG_RTC_EN	0
#define CFG_RTC_CLK	0
#define CFG_RC_PPM_OFFSET 760
/// @Misc::SMEM
/// [0:15]: size
/// [16:31]: address offset
#define CFG_SMEM_BLE	0x408000
#define CFG_SMEM_BLE_RETN_EN	1
#define CFG_SMEM_ANT_RX_DATA	0
#define CFG_SMEM_ANT_RX_DATA_RETN_EN	0
#define CFG_SMEM_AUDIO_RX	0
#define CFG_SMEM_AUDIO_RX_RETN_EN	0
#define CFG_SMEM_AUDIO_TX	0
#define CFG_SMEM_AUDIO_TX_RETN_EN	0
#define CFG_SMEM_HW_ACCEL_INST	0
#define CFG_SMEM_HW_ACCEL_INST_RETN_EN	0
#define CFG_SMEM_SADC	0
#define CFG_SMEM_SADC_RETN_EN	0
#define CFG_SMEM_AHB_TRIG	0x00000040
#define CFG_SMEM_AHB_TRIG_RETN_EN	1
/// @Flash::SPI FLASH
#define CFG_EXT_SPI_FLASH	1
#define CFG_EXT_SPI_FLASH_MXIC	0
#define CFG_EXT_SPI_FLASH_PUYA	1
#define CFG_EXT_SPI_FLASH_GIGA	0
#define CFG_QSPI_PIN_0	0x00002320
#define CFG_QSPI_PIN_1	0x00002111
#define CFG_QSPI_PIN_2	0x00002352
#define CFG_QSPI_PIN_3	0x00002313
#define CFG_QSPI_PIN_4	0x00002324
#define CFG_QSPI_PIN_5	0x00002355
#define CFG_QSPI_SPEED	32000000
#define CFG_EXT_SPI_FLASH_POWER_FROM_602	1
#define CFG_EXT_SPI_FLASH_POWER_ON_SETTLE_TIME	1000
#define CFG_FLASH_BASE_ADDR	0x301000
#define CFG_FLASH_SIZE	0x7f000
/// @Flash::BOOTRAM
#define CFG_BRAM_COLD_BOOT_ADDR	0x00301000
#define CFG_BRAM_BOOT_OPT	1
#define CFG_BRAM_BOOT_WAIT_TIME	1
#define CFG_BRAM_BOOT_GPIO_PORT	0
#define CFG_BRAM_BOOT_GPIO_PIN	0
#define CFG_BRAM_BOOT_GPIO_LEVEL	0
#define CFG_BRAM_SECURE_BOOT_HASH_ADDR	0x0
#define CFG_BRAM_SECURE_BOOT_HASH_SIZE	0x0
#define CFG_BRAM_SECURE_BOOT_ECDSA_SIG	\
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#define CFG_BRAM_RAM_APP_EN	0
#define CFG_BRAM_RAM_APP_FLASH_ADDR	0x0
#define CFG_BRAM_RAM_APP_RAM_ADDR	0x0
#define CFG_BRAM_RAM_APP_SIZE	0x0
#define CFG_BRAM_SSPI_INT_EN	0
#define CFG_BRAM_SSPI_INT_PORT	0
#define CFG_BRAM_SSPI_INT_PIN	0
#define CFG_BRAM_SSPI_INT_LEVEL	0
/// @Peripheral::Peripheral
#define CFG_UART0_EN	1
#define CFG_UART1_EN	0
#define CFG_I2C0_EN	0
#define CFG_I2C1_EN	0
#define CFG_MSPI_EN	0
#define CFG_SSPI_EN	0
#define CFG_MI2S_EN	0
#define CFG_SI2S_EN	0
#define CFG_KB_EN	0
#define CFG_COUNTER_EN	0
#define CFG_ECC_EN	0
#define CFG_AES_EN	0
#define CFG_HASH_EN	0
#define CFG_HWACC_EN	0
#define CFG_WDT_EN	0
#define CFG_AUDIO_EN	0
#define CFG_EFUSE_EN	0
#define CFG_SADC_EN	0
#define CFG_QD_EN	0
#define CFG_PWM0_EN	0
#define CFG_PWM1_EN	0
#define CFG_PWM2_EN	0
#define CFG_PWM3_EN	0
#define CFG_PWM4_EN	0
/// @Peripheral::GPIO
/// [0:3]: Pin number
/// [4:7]: Port number
/// [8:11]: mux number
/// [12]: oe
/// [13]: ie
/// [16]: pd
/// [17]: pu
/// [20]: Output
/// [21]: wup
/// [22]: Latch
/// [23]: wup pol
#define CFG_GPIO_0_0	0x00121200
#define CFG_GPIO_0_1	0x00121001
#define CFG_GPIO_0_2	0x00622202
#define CFG_GPIO_0_3	0x00023403
#define CFG_GPIO_0_4	0x00023404
#define CFG_GPIO_0_5	0x00121005
#define CFG_GPIO_1_0	0x00222010
#define CFG_GPIO_1_1	0x00121111
#define CFG_GPIO_1_2	0x00022112
#define CFG_GPIO_1_3	0x00023113
#define CFG_GPIO_1_4	0x00121214
#define CFG_GPIO_1_5	0x00121215
#define CFG_GPIO_1_6	0x00121216
#define CFG_GPIO_1_7	0x00121217
#define CFG_GPIO_1_8	0x00121018
#define CFG_GPIO_2_0	0x00121020
#define CFG_GPIO_2_1	0x00022021
#define CFG_GPIO_2_2	0x00022022
#define CFG_GPIO_2_3	0x00021123
#define CFG_GPIO_2_4	0x00111424
#define CFG_GPIO_2_5	0x00022125
#define CFG_GPIO_2_6	0x00022026
#define CFG_GPIO_2_7	0x00022427
#define CFG_GPIO_2_8	0x00022628
#define CFG_GPIO_3_0	0x00022030
#define CFG_GPIO_3_1	0x00022031
#define CFG_GPIO_3_2	0x00622232
#define CFG_GPIO_3_3	0x00622233
#define CFG_GPIO_3_4	0x00022034
#define CFG_GPIO_3_5	0x00022035
#define CFG_GPIO_4_0	0x00121640
#define CFG_GPIO_4_1	0x00121041
#ifndef BLE_BUILD_INTERNAL
/// @BLE::BLE
#define CFG_PERIPHERAL
#define CFG_SEC_CON
#define CFG_CON	3
#define CFG_SDR	0
#define CFG_HCI	0
/// @BLE::PLT
#define CFG_BLE_PARAM_BD_ADDR	0x11, 0x11, 0x11, 0x11, 0x11, 0x11
#define CFG_BLE_PARAM_SLP_ALGO_DUR	200
#define CFG_BLE_PARAM_LPC_DRIFT	1000
#define CFG_BLE_PARAM_RADIO_WUP_TIME	625
#define CFG_BLE_PARAM_OSC_WUP_TIME	2500
#define CFG_BLE_PARAM_MAX_SLEEP_DURATION_TIME	0x0000fa00
#define CFG_BLE_PARAM_LPC_32K_EN	0
#define CFG_BLE_PARAM_CODED_PHY_500_EN	0
#define CFG_BLE_PARAM_SLEEP_EN	1
#define CFG_BLE_ADV_NO_DELAY_EN	1
#define CFG_BLE_PARAM_WL_MAX	4
#define CFG_BLE_PARAM_RAL_MAX	3
#define CFG_BLE_PARAM_DUP_FILT_MAX	10
#define CFG_BLE_PARAM_CA_UPD_PER	4
#define CFG_BLE_PARAM_CA_RSSI_THRD	-70
#define CFG_BLE_PARAM_CA_MAX_COUNT	4
#define CFG_BLE_PARAM_CA_MIN_COUNT	-4
#define CFG_BLE_PARAM_CA_BAD_CH_THRD	-2
#define CFG_BLE_ADV_FRAG_NB_TX	5
#define CFG_BLE_ADV_FRAG_SIZE_TX	254
#define CFG_BLE_ADV_BUF_NB_TX	(CFG_CON)
#define CFG_BLE_PARAM_P256_PUB_KEY_VALID	0
#define CFG_BLE_PARAM_P256_PUB_KEY	\
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#define CFG_BLE_PARAM_P256_PRIV_KEY_VALID	0
#define CFG_BLE_PARAM_P256_PRIV_KEY	\
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#define CFG_BLE_PARAM_TRACE_EN	0
#define CFG_BLE_PARAM_TRACE_FLAG	0
#define CFG_BLE_STK_MEM_EN	1
#define CFG_OS_BLE_NB_TASK	3
#define CFG_BLE_STK_MEM_USAGE_PRF_EN	1
#define CFG_BLE_STK_ENV_MEM_SIZE	1024
#define CFG_BLE_STK_DB_MEM_SIZE	1024
#define CFG_BLE_STK_MSG_MEM_SIZE	4096
#define CFG_BLE_STK_NON_RETN_MEM_SIZE	1024
#define CFG_OS_BLE_ISR_TASK_STACK_SIZE	1024
#define CFG_OS_BLE_ISR_TASK_PRIO	3
#define CFG_OS_BLE_STACK_TASK_STACK_SIZE	1768
#define CFG_OS_BLE_STACK_TASK_PRIO	0
#define CFG_OS_BLE_EVT_TASK_STACK_SIZE	1024
#define CFG_OS_BLE_EVT_TASK_PRIO	0
#define CFG_OS_BLE_HCI_TASK_STACK_SIZE	0
#define CFG_OS_BLE_HCI_TASK_PRIO	0
/// @BLE::DEV
#define CFG_BLE_DEV_PRIVACY	0x00
#define CFG_BLE_DEV_RENEW_DURATION	41400
#define CFG_BLE_DEV_IDENTITY_ADDR	0	///Public address
#define CFG_BLE_DEV_STATIC_ADDR	0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#define CFG_BLE_DEV_PAIR_MODE	0x01
#define CFG_BLE_DEV_GAP_START_HANDLE	0
#define CFG_BLE_DEV_GATT_START_HANDLE	0
#define CFG_BLE_DEV_ATT_DEV_NAME_WRT_PERM	0
#define CFG_BLE_DEV_ATT_APPERANCE_WRT_PERM	0
#define CFG_BLE_DEV_ATT_SLV_PREF_PARAM_PRESENT	0
#define CFG_BLE_DEV_ATT_SVC_CHG_FEAT_PRESENT	0
#define CFG_BLE_DEV_SUGG_MAX_TX_OCTETS	251
#define CFG_BLE_DEV_SUGG_MAX_TX_TIME	2120
#define CFG_BLE_DEV_L2CAP_MAX_MTU	2048
#define CFG_BLE_DEV_L2CAP_MAX_MPS	2048
#define CFG_BLE_DEV_L2CAP_MAX_LECB_CONN	2
#define CFG_BLE_DEV_PREF_TX_PHY	0x1
#define CFG_BLE_DEV_PREF_RX_PHY	0x1
#define CFG_BLE_DEV_LOCAL_NAME	"Tropos TPP"
#define CFG_BLE_DEV_LOCAL_APPEARANCE	0x0000
#define CFG_BLE_DEV_SLV_PREF_CONN_MIN_INTV	0x0006
#define CFG_BLE_DEV_SLV_PREF_CONN_MAX_INTV	0x0006
#define CFG_BLE_DEV_SLV_PREF_LATENCY	0x00f9
#define CFG_BLE_DEV_SLV_PREF_SUP_TO	0x0258
#define CFG_BLE_DEV_WL_NB	0
#define CFG_BLE_DEV_PSM_NB	0
#define CFG_BLE_DEV_PSM_PARAMSS	
#define CFG_PRF_ANPC_EN	0
#define CFG_PRF_ANPS_EN	0
#define CFG_PRF_BASC_EN	0
#define CFG_PRF_BASS_EN	0
#define CFG_PRF_BLPC_EN	0
#define CFG_PRF_BLPS_EN	0
#define CFG_PRF_CPPC_EN	0
#define CFG_PRF_CPPS_EN	0
#define CFG_PRF_CSCPC_EN	0
#define CFG_PRF_CSCPS_EN	0
#define CFG_PRF_DISC_EN	0
#define CFG_PRF_DISS_EN	0
#define CFG_PRF_FINDL_EN	0
#define CFG_PRF_FINDT_EN	0
#define CFG_PRF_GLPC_EN	0
#define CFG_PRF_GLPS_EN	0
#define CFG_PRF_HOGPBH_EN	0
#define CFG_PRF_HOGPD_EN	0
#define CFG_PRF_HOGPRH_EN	0
#define CFG_PRF_HRPC_EN	0
#define CFG_PRF_HRPS_EN	0
#define CFG_PRF_HTPC_EN	0
#define CFG_PRF_HTPT_EN	0
#define CFG_PRF_LANC_EN	0
#define CFG_PRF_LANS_EN	0
#define CFG_PRF_PASPC_EN	0
#define CFG_PRF_PASPS_EN	0
#define CFG_PRF_PROXM_EN	0
#define CFG_PRF_PROXR_EN	0
#define CFG_PRF_RSCPC_EN	0
#define CFG_PRF_RSCPS_EN	0
#define CFG_PRF_SCPPC_EN	0
#define CFG_PRF_SCPPS_EN	0
#define CFG_PRF_TIPC_EN	0
#define CFG_PRF_TIPS_EN	0
#define CFG_NB_PRF	0
/// @BLE::ADV
#define CFG_BLE_ADV_SET_NB	0
#endif	// BLE_BUILD_INTERNAL
/// @BLE::ADV
#define CFG_OS_NB_USR_TASK	0
#define CFG_OS_NB_USR_PRIV_TASK	0
#define CFG_OS_USR_PRIV_TASK_TOTAL_STACK_SIZE	0
/// @OS::OS
#define OS_TASKCNT	(2 + CFG_OS_BLE_NB_TASK + CFG_OS_NB_USR_TASK)
#define OS_STKSIZE	256
#define OS_MAINSTKSIZE	512
#define OS_PRIVCNT	(CFG_OS_NB_USR_PRIV_TASK + CFG_OS_BLE_NB_TASK)
#define OS_PRIVSTKSIZE	954
#define OS_TICK	1000
#define OS_ROBINTOUT	5
#define OS_STKCHECK	1
#define OS_STKINIT	0
#define OS_TIMERS	1
#define OS_TIMERSTKSZ	128
#define OS_TIMERPRIO	5
#define OS_CLOCK	CFG_D2_CLK

#endif // IN_CONFIG_H
