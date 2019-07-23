#ifndef _AON_PS_REGS_DEFINES_H
#define _AON_PS_REGS_DEFINES_H
/* **************************** */
#define AON_PS_REGS_AON_ST_WAKEUP_CTRL                                               (AON_PS_REGS_BASE + 0x0)
#define AON_PS_REGS_AON_ST_WAKEUP_CTRL_DEFAULT                                       0x0
#define AON_PS_REGS_AON_ST_WAKEUP_CTRL_PD_DOO_ENABLE                                 (Bit0)


#define AON_PS_REGS_BLE_ST_WAKEUP_CTRL                                               (AON_PS_REGS_BASE + 0x4)
#define AON_PS_REGS_BLE_ST_WAKEUP_CTRL_DEFAULT                                       0x0
#define AON_PS_REGS_BLE_ST_WAKEUP_CTRL_PD_DOO_ENABLE                                 (Bit0)


#define AON_PS_REGS_BO_OUT_WAKEUP_CTRL                                               (AON_PS_REGS_BASE + 0x8)
#define AON_PS_REGS_BO_OUT_WAKEUP_CTRL_DEFAULT                                       0x0
#define AON_PS_REGS_BO_OUT_WAKEUP_CTRL_PD_DOO_ENABLE                                 (Bit0)


#define AON_PS_REGS_MSIO_WAKEUP_CTRL                                                 (AON_PS_REGS_BASE + 0xc)
#define AON_PS_REGS_MSIO_WAKEUP_CTRL_DEFAULT                                         0x0
#define AON_PS_REGS_MSIO_WAKEUP_CTRL_PD_DOO_ENABLE                                   (Bit0)


#define AON_PS_REGS_PD_DOO_SLEEP_CTRL                                                (AON_PS_REGS_BASE + 0x40)
#define AON_PS_REGS_PD_DOO_SLEEP_CTRL_DEFAULT                                        0x0
#define AON_PS_REGS_PD_DOO_SLEEP_CTRL_PD_DOO_CORE_ENABLE                             (Bit0)
#define AON_PS_REGS_PD_DOO_SLEEP_CTRL_FORCE                                          (Bit6)
#define AON_PS_REGS_PD_DOO_SLEEP_CTRL_EM_4K_A_RET_ENABLE                             (Bit8)
#define AON_PS_REGS_PD_DOO_SLEEP_CTRL_EM_4K_B_RET_ENABLE                             (Bit9)
#define AON_PS_REGS_PD_DOO_SLEEP_CTRL_EM_8K_A_RET_ENABLE                             (Bit10)
#define AON_PS_REGS_PD_DOO_SLEEP_CTRL_EM_8K_B_RET_ENABLE                             (Bit11)
#define AON_PS_REGS_PD_DOO_SLEEP_CTRL_EM_16K_A_RET_ENABLE                            (Bit12)
#define AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_4K_A_RET_ENABLE                             (Bit13)
#define AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_4K_B_RET_ENABLE                             (Bit14)
#define AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_8K_RET_ENABLE                               (Bit15)
#define AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_16K_RET_ENABLE                              (Bit16)
#define AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_32K_A_RET_ENABLE                            (Bit17)
#define AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_32K_B_RET_ENABLE                            (Bit18)
#define AON_PS_REGS_PD_DOO_SLEEP_CTRL_DM_32K_C_RET_ENABLE                            (Bit19)
#define AON_PS_REGS_PD_DOO_SLEEP_CTRL_TRIG_RET_ENABLE                                (Bit20)


#define AON_PS_REGS_OFF_DELAY_0_CTRL                                                 (AON_PS_REGS_BASE + 0x80)
#define AON_PS_REGS_OFF_DELAY_0_CTRL_DEFAULT                                         0x4030002
#define AON_PS_REGS_OFF_DELAY_0_CTRL_CLOCK_EN_EARLY                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define AON_PS_REGS_OFF_DELAY_0_CTRL_CLOCK_EN_EARLY_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_OFF_DELAY_0_CTRL_CLOCK_EN_EARLY_SHIFT                            (0)
#define AON_PS_REGS_OFF_DELAY_0_CTRL_ISOLATE                                         (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define AON_PS_REGS_OFF_DELAY_0_CTRL_ISOLATE_MASK                                    (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_OFF_DELAY_0_CTRL_ISOLATE_SHIFT                                   (16)
#define AON_PS_REGS_OFF_DELAY_0_CTRL_RESETN                                          (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define AON_PS_REGS_OFF_DELAY_0_CTRL_RESETN_MASK                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_OFF_DELAY_0_CTRL_RESETN_SHIFT                                    (24)


#define AON_PS_REGS_OFF_DELAY_1_CTRL                                                 (AON_PS_REGS_BASE + 0x84)
#define AON_PS_REGS_OFF_DELAY_1_CTRL_DEFAULT                                         0x7080005
#define AON_PS_REGS_OFF_DELAY_1_CTRL_RET1N                                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define AON_PS_REGS_OFF_DELAY_1_CTRL_RET1N_MASK                                      (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_OFF_DELAY_1_CTRL_RET1N_SHIFT                                     (0)
#define AON_PS_REGS_OFF_DELAY_1_CTRL_POWER_VDD                                       (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define AON_PS_REGS_OFF_DELAY_1_CTRL_POWER_VDD_MASK                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_OFF_DELAY_1_CTRL_POWER_VDD_SHIFT                                 (16)
#define AON_PS_REGS_OFF_DELAY_1_CTRL_POWER_VDM                                       (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define AON_PS_REGS_OFF_DELAY_1_CTRL_POWER_VDM_MASK                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_OFF_DELAY_1_CTRL_POWER_VDM_SHIFT                                 (24)


#define AON_PS_REGS_ON_DELAY_0_CTRL                                                  (AON_PS_REGS_BASE + 0x90)
#define AON_PS_REGS_ON_DELAY_0_CTRL_DEFAULT                                          0xA8
#define AON_PS_REGS_ON_DELAY_0_CTRL_CLOCK_EN_EARLY_PD_DOO                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define AON_PS_REGS_ON_DELAY_0_CTRL_CLOCK_EN_EARLY_PD_DOO_MASK                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_ON_DELAY_0_CTRL_CLOCK_EN_EARLY_PD_DOO_SHIFT                      (0)


#define AON_PS_REGS_ON_DELAY_1_CTRL                                                  (AON_PS_REGS_BASE + 0x94)
#define AON_PS_REGS_ON_DELAY_1_CTRL_DEFAULT                                          0x200200A7
#define AON_PS_REGS_ON_DELAY_1_CTRL_RET1N                                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define AON_PS_REGS_ON_DELAY_1_CTRL_RET1N_MASK                                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_ON_DELAY_1_CTRL_RET1N_SHIFT                                      (0)
#define AON_PS_REGS_ON_DELAY_1_CTRL_POWER_VDD                                        (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define AON_PS_REGS_ON_DELAY_1_CTRL_POWER_VDD_MASK                                   (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_ON_DELAY_1_CTRL_POWER_VDD_SHIFT                                  (16)
#define AON_PS_REGS_ON_DELAY_1_CTRL_POWER_VDM                                        (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define AON_PS_REGS_ON_DELAY_1_CTRL_POWER_VDM_MASK                                   (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_ON_DELAY_1_CTRL_POWER_VDM_SHIFT                                  (24)


#define AON_PS_REGS_DCDC_EN_DELAY_CTRL                                               (AON_PS_REGS_BASE + 0xc0)
#define AON_PS_REGS_DCDC_EN_DELAY_CTRL_DEFAULT                                       0x108
#define AON_PS_REGS_DCDC_EN_DELAY_CTRL_OFF_DELAY                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define AON_PS_REGS_DCDC_EN_DELAY_CTRL_OFF_DELAY_MASK                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_DCDC_EN_DELAY_CTRL_OFF_DELAY_SHIFT                               (0)
#define AON_PS_REGS_DCDC_EN_DELAY_CTRL_ON_DELAY                                      (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AON_PS_REGS_DCDC_EN_DELAY_CTRL_ON_DELAY_MASK                                 (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_DCDC_EN_DELAY_CTRL_ON_DELAY_SHIFT                                (8)


#define AON_PS_REGS_XO_EN_DELAY_CTRL                                                 (AON_PS_REGS_BASE + 0xc8)
#define AON_PS_REGS_XO_EN_DELAY_CTRL_DEFAULT                                         0x1907
#define AON_PS_REGS_XO_EN_DELAY_CTRL_OFF_DELAY                                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define AON_PS_REGS_XO_EN_DELAY_CTRL_OFF_DELAY_MASK                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_XO_EN_DELAY_CTRL_OFF_DELAY_SHIFT                                 (0)
#define AON_PS_REGS_XO_EN_DELAY_CTRL_ON_DELAY                                        (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AON_PS_REGS_XO_EN_DELAY_CTRL_ON_DELAY_MASK                                   (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_XO_EN_DELAY_CTRL_ON_DELAY_SHIFT                                  (8)


#define AON_PS_REGS_CLK_32MHZ_RC_EN_DELAY_CTRL                                       (AON_PS_REGS_BASE + 0xcc)
#define AON_PS_REGS_CLK_32MHZ_RC_EN_DELAY_CTRL_DEFAULT                               0x107
#define AON_PS_REGS_CLK_32MHZ_RC_EN_DELAY_CTRL_OFF_DELAY                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define AON_PS_REGS_CLK_32MHZ_RC_EN_DELAY_CTRL_OFF_DELAY_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_CLK_32MHZ_RC_EN_DELAY_CTRL_OFF_DELAY_SHIFT                       (0)
#define AON_PS_REGS_CLK_32MHZ_RC_EN_DELAY_CTRL_ON_DELAY                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AON_PS_REGS_CLK_32MHZ_RC_EN_DELAY_CTRL_ON_DELAY_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_CLK_32MHZ_RC_EN_DELAY_CTRL_ON_DELAY_SHIFT                        (8)


#define AON_PS_REGS_AUTO_AMP_CTRL_EN_DELAY_CTRL                                      (AON_PS_REGS_BASE + 0xd4)
#define AON_PS_REGS_AUTO_AMP_CTRL_EN_DELAY_CTRL_DEFAULT                              0x2107
#define AON_PS_REGS_AUTO_AMP_CTRL_EN_DELAY_CTRL_OFF_DELAY                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define AON_PS_REGS_AUTO_AMP_CTRL_EN_DELAY_CTRL_OFF_DELAY_MASK                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_AUTO_AMP_CTRL_EN_DELAY_CTRL_OFF_DELAY_SHIFT                      (0)
#define AON_PS_REGS_AUTO_AMP_CTRL_EN_DELAY_CTRL_ON_DELAY                             (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AON_PS_REGS_AUTO_AMP_CTRL_EN_DELAY_CTRL_ON_DELAY_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_AUTO_AMP_CTRL_EN_DELAY_CTRL_ON_DELAY_SHIFT                       (8)


#define AON_PS_REGS_AUTO_AMP_CTRL_RB_DELAY_CTRL                                      (AON_PS_REGS_BASE + 0xd8)
#define AON_PS_REGS_AUTO_AMP_CTRL_RB_DELAY_CTRL_DEFAULT                              0x2307
#define AON_PS_REGS_AUTO_AMP_CTRL_RB_DELAY_CTRL_OFF_DELAY                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define AON_PS_REGS_AUTO_AMP_CTRL_RB_DELAY_CTRL_OFF_DELAY_MASK                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_AUTO_AMP_CTRL_RB_DELAY_CTRL_OFF_DELAY_SHIFT                      (0)
#define AON_PS_REGS_AUTO_AMP_CTRL_RB_DELAY_CTRL_ON_DELAY                             (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AON_PS_REGS_AUTO_AMP_CTRL_RB_DELAY_CTRL_ON_DELAY_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_AUTO_AMP_CTRL_RB_DELAY_CTRL_ON_DELAY_SHIFT                       (8)


#define AON_PS_REGS_QSPI_VDDIO_EN_DELAY_CTRL                                         (AON_PS_REGS_BASE + 0xdc)
#define AON_PS_REGS_QSPI_VDDIO_EN_DELAY_CTRL_DEFAULT                                 0x2307
#define AON_PS_REGS_QSPI_VDDIO_EN_DELAY_CTRL_OFF_DELAY                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define AON_PS_REGS_QSPI_VDDIO_EN_DELAY_CTRL_OFF_DELAY_MASK                          (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_QSPI_VDDIO_EN_DELAY_CTRL_OFF_DELAY_SHIFT                         (0)
#define AON_PS_REGS_QSPI_VDDIO_EN_DELAY_CTRL_ON_DELAY                                (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AON_PS_REGS_QSPI_VDDIO_EN_DELAY_CTRL_ON_DELAY_MASK                           (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_QSPI_VDDIO_EN_DELAY_CTRL_ON_DELAY_SHIFT                          (8)


#define AON_PS_REGS_SENSOR_VDDIO_EN_DELAY_CTRL                                       (AON_PS_REGS_BASE + 0xe0)
#define AON_PS_REGS_SENSOR_VDDIO_EN_DELAY_CTRL_DEFAULT                               0x2307
#define AON_PS_REGS_SENSOR_VDDIO_EN_DELAY_CTRL_OFF_DELAY                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define AON_PS_REGS_SENSOR_VDDIO_EN_DELAY_CTRL_OFF_DELAY_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_SENSOR_VDDIO_EN_DELAY_CTRL_OFF_DELAY_SHIFT                       (0)
#define AON_PS_REGS_SENSOR_VDDIO_EN_DELAY_CTRL_ON_DELAY                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AON_PS_REGS_SENSOR_VDDIO_EN_DELAY_CTRL_ON_DELAY_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AON_PS_REGS_SENSOR_VDDIO_EN_DELAY_CTRL_ON_DELAY_SHIFT                        (8)


#define AON_PS_REGS_MISC_BYPASS_0_CTRL                                               (AON_PS_REGS_BASE + 0x100)
#define AON_PS_REGS_MISC_BYPASS_0_CTRL_DEFAULT                                       0xA502
#define AON_PS_REGS_MISC_BYPASS_0_CTRL_LOW_VOLTAGE_EN_VAL                            (Bit0)
#define AON_PS_REGS_MISC_BYPASS_0_CTRL_LOW_VOLTAGE_EN_EN                             (Bit1)
#define AON_PS_REGS_MISC_BYPASS_0_CTRL_ENABLE_CLOCK_GATE                             (Bit2)
#define AON_PS_REGS_MISC_BYPASS_0_CTRL_DCDC_EN_VAL                                   (Bit4)
#define AON_PS_REGS_MISC_BYPASS_0_CTRL_DCDC_EN_EN                                    (Bit5)
#define AON_PS_REGS_MISC_BYPASS_0_CTRL_XO_EN_VAL                                     (Bit8)
#define AON_PS_REGS_MISC_BYPASS_0_CTRL_XO_EN_EN                                      (Bit9)
#define AON_PS_REGS_MISC_BYPASS_0_CTRL_CLK_32MHZ_RC_EN_VAL                           (Bit10)
#define AON_PS_REGS_MISC_BYPASS_0_CTRL_CLK_32MHZ_RC_EN_EN                            (Bit11)
#define AON_PS_REGS_MISC_BYPASS_0_CTRL_QSPI_VDDIO_EN_VAL                             (Bit12)
#define AON_PS_REGS_MISC_BYPASS_0_CTRL_QSPI_VDDIO_EN_EN                              (Bit13)
#define AON_PS_REGS_MISC_BYPASS_0_CTRL_SENSOR_VDDIO_EN_VAL                           (Bit14)
#define AON_PS_REGS_MISC_BYPASS_0_CTRL_SENSOR_VDDIO_EN_EN                            (Bit15)


#define AON_PS_REGS_RAW_WAKEUP_BITS                                                  (AON_PS_REGS_BASE + 0x200)
#define AON_PS_REGS_RAW_WAKEUP_BITS_DEFAULT                                          0x0
#define AON_PS_REGS_RAW_WAKEUP_BITS_GPIO                                             (Bit0)
#define AON_PS_REGS_RAW_WAKEUP_BITS_AON_ST                                           (Bit1)
#define AON_PS_REGS_RAW_WAKEUP_BITS_BLE_ST                                           (Bit2)
#define AON_PS_REGS_RAW_WAKEUP_BITS_BO_OUT                                           (Bit3)
#define AON_PS_REGS_RAW_WAKEUP_BITS_MSIO                                             (Bit4)


#define AON_PS_REGS_PD_WAKEUP_BITS                                                   (AON_PS_REGS_BASE + 0x204)
#define AON_PS_REGS_PD_WAKEUP_BITS_DEFAULT                                           0x0
#define AON_PS_REGS_PD_WAKEUP_BITS_PD_DOO_CORE                                       (Bit0)


#define AON_PS_REGS_SERVICED_REQUEST                                                 (AON_PS_REGS_BASE + 0x210)
#define AON_PS_REGS_SERVICED_REQUEST_DEFAULT                                         0x0
#define AON_PS_REGS_SERVICED_REQUEST_GPIO_WAKEUP                                     (Bit0)
#define AON_PS_REGS_SERVICED_REQUEST_AON_ST_WAKEUP                                   (Bit1)
#define AON_PS_REGS_SERVICED_REQUEST_BLE_ST_WAKEUP                                   (Bit2)
#define AON_PS_REGS_SERVICED_REQUEST_BO_OUT_WAKEUP                                   (Bit3)
#define AON_PS_REGS_SERVICED_REQUEST_MSIO_WAKEUP                                     (Bit4)
#define AON_PS_REGS_SERVICED_REQUEST_PD_DOO_SLEEP                                    (Bit8)


#define AON_PS_REGS_ACTIVE_REQUEST                                                   (AON_PS_REGS_BASE + 0x220)
#define AON_PS_REGS_ACTIVE_REQUEST_DEFAULT                                           0x0
#define AON_PS_REGS_ACTIVE_REQUEST_GPIO_WAKEUP                                       (Bit0)
#define AON_PS_REGS_ACTIVE_REQUEST_AON_ST_WAKEUP                                     (Bit1)
#define AON_PS_REGS_ACTIVE_REQUEST_BLE_ST_WAKEUP                                     (Bit2)
#define AON_PS_REGS_ACTIVE_REQUEST_BO_OUT_WAKEUP                                     (Bit3)
#define AON_PS_REGS_ACTIVE_REQUEST_MSIO_WAKEUP                                       (Bit4)
#define AON_PS_REGS_ACTIVE_REQUEST_PD_DOO_SLEEP                                      (Bit8)


#define AON_PS_REGS_LAST_REQUEST                                                     (AON_PS_REGS_BASE + 0x230)
#define AON_PS_REGS_LAST_REQUEST_DEFAULT                                             0x0
#define AON_PS_REGS_LAST_REQUEST_GPIO_WAKEUP                                         (Bit0)
#define AON_PS_REGS_LAST_REQUEST_AON_ST_WAKEUP                                       (Bit1)
#define AON_PS_REGS_LAST_REQUEST_BLE_ST_WAKEUP                                       (Bit2)
#define AON_PS_REGS_LAST_REQUEST_BO_OUT_WAKEUP                                       (Bit3)
#define AON_PS_REGS_LAST_REQUEST_MSIO_WAKEUP                                         (Bit4)
#define AON_PS_REGS_LAST_REQUEST_PD_DOO_SLEEP                                        (Bit8)


#define AON_PS_REGS_LOGIC_FSM_STATES                                                 (AON_PS_REGS_BASE + 0x240)
#define AON_PS_REGS_LOGIC_FSM_STATES_DEFAULT                                         0x0
#define AON_PS_REGS_LOGIC_FSM_STATES_MAIN_FSM_STATE                                  (Bit0+Bit1+Bit2)
#define AON_PS_REGS_LOGIC_FSM_STATES_MAIN_FSM_STATE_MASK                             (Bit2+Bit1+Bit0)
#define AON_PS_REGS_LOGIC_FSM_STATES_MAIN_FSM_STATE_SHIFT                            (0)


#define AON_PS_REGS_POWER_FSM_STATES                                                 (AON_PS_REGS_BASE + 0x244)
#define AON_PS_REGS_POWER_FSM_STATES_DEFAULT                                         0x0
#define AON_PS_REGS_POWER_FSM_STATES_PD_DOO_CORE_IN_ON_STATE                         (Bit0)
#define AON_PS_REGS_POWER_FSM_STATES_PD_DOO_CORE_IN_OFF_STATE                        (Bit1)
#define AON_PS_REGS_POWER_FSM_STATES_PD_DOO_CORE_GOING_TO_ON_STATE                   (Bit2)
#define AON_PS_REGS_POWER_FSM_STATES_PD_DOO_CORE_GOING_TO_OFF_STATE                  (Bit3)


#endif // _AON_PS_REGS_DEFINES_H

