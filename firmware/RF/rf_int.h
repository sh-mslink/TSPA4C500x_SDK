/**
 ****************************************************************************************
 *
 * @file rf_int.h
 *
 * @brief RF internal functions  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
#ifndef RF_INT_H
#define RF_INT_H

void rf_int_rpl_mdm_init(void);
void rf_int_set_tx_power(uint8_t tx_power_code);
void rf_int_prog_pll_trx_trig(uint32_t TRX_at_5G);
void rf_int_gp_ahb_trig_shm(void);
void rf_int_aon_reg_slp_opt(int rtc_en);
void rf_int_sw_pll_trig(void);
void rf_int_aon_reg_opt(void);
void rf_set_tx_power(uint8_t tx_power_code);
void rf_int_suspend(void);
void rf_int_resume(void);

#endif
