#ifndef _RXTX_SEQ_CTRL_REGISTERS_DEFINES_H
#define _RXTX_SEQ_CTRL_REGISTERS_DEFINES_H
/* **************************** */
#define RXTX_SEQ_CTRL_REGISTERS_MODE_CTRL                                                            (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x0)
#define RXTX_SEQ_CTRL_REGISTERS_MODE_CTRL_DEFAULT                                                    0x1
#define RXTX_SEQ_CTRL_REGISTERS_MODE_CTRL_ENABLE                                                     (Bit0)


#define RXTX_SEQ_CTRL_REGISTERS_OP_CTRL                                                              (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x4)
#define RXTX_SEQ_CTRL_REGISTERS_OP_CTRL_DEFAULT                                                      0x3C
#define RXTX_SEQ_CTRL_REGISTERS_OP_CTRL_ENABLE_WAKEUP_ARM                                            (Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_OP_CTRL_ENABLE_WAKEUP_SW                                             (Bit1)
#define RXTX_SEQ_CTRL_REGISTERS_OP_CTRL_ENABLE_WAKEUP_HW                                             (Bit2)
#define RXTX_SEQ_CTRL_REGISTERS_OP_CTRL_ONLY_WAKEUP_SIGNAL_FROM_SLEEP                                (Bit3)
#define RXTX_SEQ_CTRL_REGISTERS_OP_CTRL_IDLE_WHEN_RX_NO_ACTIVE_SIGS                                  (Bit4)
#define RXTX_SEQ_CTRL_REGISTERS_OP_CTRL_IDLE_WHEN_TX_NO_ACTIVE_SIGS                                  (Bit5)
#define RXTX_SEQ_CTRL_REGISTERS_OP_CTRL_IDLE_TO_RX_2P4G                                              (Bit8)
#define RXTX_SEQ_CTRL_REGISTERS_OP_CTRL_IDLE_TO_RX_5P8G                                              (Bit9)
#define RXTX_SEQ_CTRL_REGISTERS_OP_CTRL_IDLE_TO_TX_2P4G                                              (Bit10)
#define RXTX_SEQ_CTRL_REGISTERS_OP_CTRL_IDLE_TO_TX_5P8G                                              (Bit11)


#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL                                                        (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x10)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_DEFAULT                                                0x0
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_VAL_ADA_EN                                         (Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_EN_ADA_EN                                          (Bit1)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_VAL_AGC_EN                                         (Bit2)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_EN_AGC_EN                                          (Bit3)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_VAL_BBA_2P4_EN                                     (Bit4)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_EN_BBA_2P4_EN                                      (Bit5)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_VAL_BBA_5P8_EN                                     (Bit6)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_EN_BBA_5P8_EN                                      (Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_VAL_BGR_EN                                         (Bit8)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_EN_BGR_EN                                          (Bit9)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_VAL_CPLL_EN                                        (Bit10)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_EN_CPLL_EN                                         (Bit11)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_VAL_CPLL_RESETB_TOGGLE                             (Bit12)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_EN_CPLL_RESETB_TOGGLE                              (Bit13)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_VAL_LNA_2P4_EN                                     (Bit18)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_EN_LNA_2P4_EN                                      (Bit19)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_VAL_LNA_5P8_EN                                     (Bit20)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_EN_LNA_5P8_EN                                      (Bit21)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_VAL_MIX_2P4_EN                                     (Bit22)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_EN_MIX_2P4_EN                                      (Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_VAL_MIX_5P8_EN                                     (Bit24)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_EN_MIX_5P8_EN                                      (Bit25)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_VAL_MPLL_2P4_EN                                    (Bit26)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_EN_MPLL_2P4_EN                                     (Bit27)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_VAL_MPLL_2P4_RESETB_TOGGLE                         (Bit28)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_EN_MPLL_2P4_RESETB_TOGGLE                          (Bit29)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_VAL_MPLL_5P8_EN                                    (Bit30)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_0_CTRL_BYP_EN_MPLL_5P8_EN                                     (Bit31)


#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL                                                        (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x14)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_DEFAULT                                                0x0
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_VAL_MPLL_5P8_RESETB_TOGGLE                         (Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_EN_MPLL_5P8_RESETB_TOGGLE                          (Bit1)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_VAL_PA_2P4_EN                                      (Bit2)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_EN_PA_2P4_EN                                       (Bit3)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_VAL_PA_5P8_EN                                      (Bit4)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_EN_PA_5P8_EN                                       (Bit5)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_VAL_SDADC_EN                                       (Bit6)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_EN_SDADC_EN                                        (Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_VAL_RX_FE_AGC_EN                                   (Bit8)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_EN_RX_FE_AGC_EN                                    (Bit9)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_VAL_RX_FE_EN                                       (Bit10)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_EN_RX_FE_EN                                        (Bit11)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_VAL_TX_FE_EN                                       (Bit12)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_EN_TX_FE_EN                                        (Bit13)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_VAL_USE_RF_TX_REGS                                 (Bit14)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_EN_USE_RF_TX_REGS                                  (Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_VAL_MPLL_2P4_RX_EN                                 (Bit16)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_EN_MPLL_2P4_RX_EN                                  (Bit17)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_VAL_MPLL_2P4_TX_EN                                 (Bit18)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_EN_MPLL_2P4_TX_EN                                  (Bit19)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_VAL_MPLL_5P8_RX_EN                                 (Bit20)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_EN_MPLL_5P8_RX_EN                                  (Bit21)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_VAL_MPLL_5P8_TX_EN                                 (Bit22)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_EN_MPLL_5P8_TX_EN                                  (Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_VAL_RFFE_5P8_EN                                    (Bit24)
#define RXTX_SEQ_CTRL_REGISTERS_BYPASS_1_CTRL_BYP_EN_RFFE_5P8_EN                                     (Bit25)


#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS                                                             (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x1c)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_DEFAULT                                                     0x0
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_STATUS                                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_STATUS_MASK                                                 (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_STATUS_SHIFT                                                (0)


#define RXTX_SEQ_CTRL_REGISTERS_CPLL_RESETB_TOGGLE_CTRL                                              (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x24)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_RESETB_TOGGLE_CTRL_DEFAULT                                      0x33
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_RESETB_TOGGLE_CTRL_ENABLE_IDLE_TO_RX_2P4G                       (Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_RESETB_TOGGLE_CTRL_ENABLE_IDLE_TO_RX_5P8G                       (Bit1)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_RESETB_TOGGLE_CTRL_HOLD                                         (Bit4+Bit5+Bit6)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_RESETB_TOGGLE_CTRL_HOLD_MASK                                    (Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_RESETB_TOGGLE_CTRL_HOLD_SHIFT                                   (4)


#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RESETB_TOGGLE_CTRL                                          (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x28)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RESETB_TOGGLE_CTRL_DEFAULT                                  0x33
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RESETB_TOGGLE_CTRL_ENABLE_IDLE_TO_RX_2P4G                   (Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RESETB_TOGGLE_CTRL_ENABLE_IDLE_TO_TX_2P4G                   (Bit1)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RESETB_TOGGLE_CTRL_HOLD                                     (Bit4+Bit5+Bit6)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RESETB_TOGGLE_CTRL_HOLD_MASK                                (Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RESETB_TOGGLE_CTRL_HOLD_SHIFT                               (4)


#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RESETB_TOGGLE_CTRL                                          (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x2c)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RESETB_TOGGLE_CTRL_DEFAULT                                  0x33
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RESETB_TOGGLE_CTRL_ENABLE_IDLE_TO_RX_5P8G                   (Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RESETB_TOGGLE_CTRL_ENABLE_IDLE_TO_TX_5P8G                   (Bit1)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RESETB_TOGGLE_CTRL_HOLD                                     (Bit4+Bit5+Bit6)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RESETB_TOGGLE_CTRL_HOLD_MASK                                (Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RESETB_TOGGLE_CTRL_HOLD_SHIFT                               (4)


#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_CTRL                                               (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x30)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_CTRL_DEFAULT                                       0x7000
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_CTRL_ENABLE_SLEEP_TO_IDLE                          (Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_CTRL_ENABLE_IDLE_TO_SLEEP                          (Bit1)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_CTRL_ENABLE_IDLE_TO_RX_2P4G                        (Bit2)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_CTRL_ENABLE_IDLE_TO_RX_5P8G                        (Bit3)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_CTRL_ENABLE_IDLE_TO_TX_2P4G                        (Bit4)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_CTRL_ENABLE_IDLE_TO_TX_5P8G                        (Bit5)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_CTRL_ENABLE_RX_2P4G_TO_IDLE                        (Bit6)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_CTRL_ENABLE_RX_5P8G_TO_IDLE                        (Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_CTRL_ENABLE_TX_2P4G_TO_IDLE                        (Bit8)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_CTRL_ENABLE_TX_5P8G_TO_IDLE                        (Bit9)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_CTRL_HOLD                                          (Bit12+Bit13+Bit14)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_CTRL_HOLD_MASK                                     (Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_CTRL_HOLD_SHIFT                                    (12)


#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_0_ADDR                                             (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x34)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_0_ADDR_DEFAULT                                     0x0
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_0_ADDR_SLEEP_TO_IDLE                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_0_ADDR_SLEEP_TO_IDLE_MASK                          (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_0_ADDR_SLEEP_TO_IDLE_SHIFT                         (0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_0_ADDR_IDLE_TO_SLEEP                               (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_0_ADDR_IDLE_TO_SLEEP_MASK                          (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_0_ADDR_IDLE_TO_SLEEP_SHIFT                         (8)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_0_ADDR_IDLE_TO_RX_2P4G                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_0_ADDR_IDLE_TO_RX_2P4G_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_0_ADDR_IDLE_TO_RX_2P4G_SHIFT                       (16)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_0_ADDR_IDLE_TO_RX_5P8G                             (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_0_ADDR_IDLE_TO_RX_5P8G_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_0_ADDR_IDLE_TO_RX_5P8G_SHIFT                       (24)


#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_1_ADDR                                             (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x38)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_1_ADDR_DEFAULT                                     0x0
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_1_ADDR_IDLE_TO_TX_2P4G                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_1_ADDR_IDLE_TO_TX_2P4G_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_1_ADDR_IDLE_TO_TX_2P4G_SHIFT                       (0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_1_ADDR_IDLE_TO_TX_5P8G                             (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_1_ADDR_IDLE_TO_TX_5P8G_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_1_ADDR_IDLE_TO_TX_5P8G_SHIFT                       (8)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_1_ADDR_RX_2P4G_TO_IDLE                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_1_ADDR_RX_2P4G_TO_IDLE_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_1_ADDR_RX_2P4G_TO_IDLE_SHIFT                       (16)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_1_ADDR_RX_5P8G_TO_IDLE                             (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_1_ADDR_RX_5P8G_TO_IDLE_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_1_ADDR_RX_5P8G_TO_IDLE_SHIFT                       (24)


#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_2_ADDR                                             (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x3c)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_2_ADDR_DEFAULT                                     0x0
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_2_ADDR_TX_2P4G_TO_IDLE                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_2_ADDR_TX_2P4G_TO_IDLE_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_2_ADDR_TX_2P4G_TO_IDLE_SHIFT                       (0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_2_ADDR_TX_5P8G_TO_IDLE                             (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_2_ADDR_TX_5P8G_TO_IDLE_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_OFFSET_2_ADDR_TX_5P8G_TO_IDLE_SHIFT                       (8)


#define RXTX_SEQ_CTRL_REGISTERS_ADA_EN_DELAY_0_CTRL                                                  (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x80)
#define RXTX_SEQ_CTRL_REGISTERS_ADA_EN_DELAY_0_CTRL_DEFAULT                                          0x1015151
#define RXTX_SEQ_CTRL_REGISTERS_ADA_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_ADA_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_ADA_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_SHIFT                            (0)
#define RXTX_SEQ_CTRL_REGISTERS_ADA_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G                                  (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_ADA_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_ADA_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT                            (8)
#define RXTX_SEQ_CTRL_REGISTERS_ADA_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_ADA_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_ADA_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_SHIFT                            (16)
#define RXTX_SEQ_CTRL_REGISTERS_ADA_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE                                  (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_ADA_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_ADA_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_SHIFT                            (24)


#define RXTX_SEQ_CTRL_REGISTERS_AGC_EN_DELAY_0_CTRL                                                  (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x84)
#define RXTX_SEQ_CTRL_REGISTERS_AGC_EN_DELAY_0_CTRL_DEFAULT                                          0x1015151
#define RXTX_SEQ_CTRL_REGISTERS_AGC_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_AGC_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_AGC_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_SHIFT                            (0)
#define RXTX_SEQ_CTRL_REGISTERS_AGC_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G                                  (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_AGC_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_AGC_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT                            (8)
#define RXTX_SEQ_CTRL_REGISTERS_AGC_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_AGC_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_AGC_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_SHIFT                            (16)
#define RXTX_SEQ_CTRL_REGISTERS_AGC_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE                                  (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_AGC_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_AGC_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_SHIFT                            (24)


#define RXTX_SEQ_CTRL_REGISTERS_BBA_2P4_EN_DELAY_0_CTRL                                              (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x88)
#define RXTX_SEQ_CTRL_REGISTERS_BBA_2P4_EN_DELAY_0_CTRL_DEFAULT                                      0x151
#define RXTX_SEQ_CTRL_REGISTERS_BBA_2P4_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_BBA_2P4_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_BBA_2P4_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_SHIFT                        (0)
#define RXTX_SEQ_CTRL_REGISTERS_BBA_2P4_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_BBA_2P4_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_BBA_2P4_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_SHIFT                        (8)


#define RXTX_SEQ_CTRL_REGISTERS_BBA_5P8_EN_DELAY_0_CTRL                                              (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x8c)
#define RXTX_SEQ_CTRL_REGISTERS_BBA_5P8_EN_DELAY_0_CTRL_DEFAULT                                      0x154
#define RXTX_SEQ_CTRL_REGISTERS_BBA_5P8_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_BBA_5P8_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_BBA_5P8_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT                        (0)
#define RXTX_SEQ_CTRL_REGISTERS_BBA_5P8_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_BBA_5P8_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_BBA_5P8_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_SHIFT                        (8)


#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_0_CTRL                                                  (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x90)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_0_CTRL_DEFAULT                                          0x0
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_SHIFT                            (0)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G                                  (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT                            (8)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_0_CTRL_IDLE_TO_TX_2P4G                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_0_CTRL_IDLE_TO_TX_2P4G_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_0_CTRL_IDLE_TO_TX_2P4G_SHIFT                            (16)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G                                  (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G_SHIFT                            (24)


#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_1_CTRL                                                  (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x94)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_1_CTRL_DEFAULT                                          0x1010101
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_1_CTRL_RX_2P4G_TO_IDLE                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_1_CTRL_RX_2P4G_TO_IDLE_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_1_CTRL_RX_2P4G_TO_IDLE_SHIFT                            (0)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_1_CTRL_RX_5P8G_TO_IDLE                                  (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_1_CTRL_RX_5P8G_TO_IDLE_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_1_CTRL_RX_5P8G_TO_IDLE_SHIFT                            (8)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_1_CTRL_TX_2P4G_TO_IDLE                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_1_CTRL_TX_2P4G_TO_IDLE_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_1_CTRL_TX_2P4G_TO_IDLE_SHIFT                            (16)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_1_CTRL_TX_5P8G_TO_IDLE                                  (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_1_CTRL_TX_5P8G_TO_IDLE_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_BGR_EN_DELAY_1_CTRL_TX_5P8G_TO_IDLE_SHIFT                            (24)


#define RXTX_SEQ_CTRL_REGISTERS_CPLL_EN_DELAY_0_CTRL                                                 (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x98)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_EN_DELAY_0_CTRL_DEFAULT                                         0x10100000
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_SHIFT                           (0)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G                                 (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT                           (8)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE                                 (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_SHIFT                           (16)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE                                 (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_SHIFT                           (24)


#define RXTX_SEQ_CTRL_REGISTERS_CPLL_RESETB_TOGGLE_DELAY_0_CTRL                                      (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x9c)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_RESETB_TOGGLE_DELAY_0_CTRL_DEFAULT                              0x202
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_2P4G                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_2P4G_MASK                 (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_2P4G_SHIFT                (0)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_5P8G                      (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK                 (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_CPLL_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT                (8)


#define RXTX_SEQ_CTRL_REGISTERS_LNA_2P4_EN_DELAY_0_CTRL                                              (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xa8)
#define RXTX_SEQ_CTRL_REGISTERS_LNA_2P4_EN_DELAY_0_CTRL_DEFAULT                                      0x222
#define RXTX_SEQ_CTRL_REGISTERS_LNA_2P4_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_LNA_2P4_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_LNA_2P4_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_SHIFT                        (0)
#define RXTX_SEQ_CTRL_REGISTERS_LNA_2P4_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_LNA_2P4_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_LNA_2P4_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_SHIFT                        (8)


#define RXTX_SEQ_CTRL_REGISTERS_LNA_5P8_EN_DELAY_0_CTRL                                              (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xac)
#define RXTX_SEQ_CTRL_REGISTERS_LNA_5P8_EN_DELAY_0_CTRL_DEFAULT                                      0x222
#define RXTX_SEQ_CTRL_REGISTERS_LNA_5P8_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_LNA_5P8_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_LNA_5P8_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT                        (0)
#define RXTX_SEQ_CTRL_REGISTERS_LNA_5P8_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_LNA_5P8_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_LNA_5P8_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_SHIFT                        (8)


#define RXTX_SEQ_CTRL_REGISTERS_MIX_2P4_EN_DELAY_0_CTRL                                              (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xb0)
#define RXTX_SEQ_CTRL_REGISTERS_MIX_2P4_EN_DELAY_0_CTRL_DEFAULT                                      0x323
#define RXTX_SEQ_CTRL_REGISTERS_MIX_2P4_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_MIX_2P4_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MIX_2P4_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_SHIFT                        (0)
#define RXTX_SEQ_CTRL_REGISTERS_MIX_2P4_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_MIX_2P4_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MIX_2P4_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_SHIFT                        (8)


#define RXTX_SEQ_CTRL_REGISTERS_MIX_5P8_EN_DELAY_0_CTRL                                              (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xb4)
#define RXTX_SEQ_CTRL_REGISTERS_MIX_5P8_EN_DELAY_0_CTRL_DEFAULT                                      0x323
#define RXTX_SEQ_CTRL_REGISTERS_MIX_5P8_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_MIX_5P8_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MIX_5P8_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT                        (0)
#define RXTX_SEQ_CTRL_REGISTERS_MIX_5P8_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_MIX_5P8_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MIX_5P8_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_SHIFT                        (8)


#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RX_EN_DELAY_0_CTRL                                          (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xb8)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RX_EN_DELAY_0_CTRL_DEFAULT                                  0x302
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RX_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RX_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_MASK                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RX_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_SHIFT                    (0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RX_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RX_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_MASK                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RX_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_SHIFT                    (8)


#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_TX_EN_DELAY_0_CTRL                                          (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xbc)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_TX_EN_DELAY_0_CTRL_DEFAULT                                  0x302
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_TX_EN_DELAY_0_CTRL_IDLE_TO_TX_2P4G                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_TX_EN_DELAY_0_CTRL_IDLE_TO_TX_2P4G_MASK                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_TX_EN_DELAY_0_CTRL_IDLE_TO_TX_2P4G_SHIFT                    (0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_TX_EN_DELAY_0_CTRL_TX_2P4G_TO_IDLE                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_TX_EN_DELAY_0_CTRL_TX_2P4G_TO_IDLE_MASK                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_TX_EN_DELAY_0_CTRL_TX_2P4G_TO_IDLE_SHIFT                    (8)


#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_EN_DELAY_0_CTRL                                             (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xc0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_EN_DELAY_0_CTRL_DEFAULT                                     0x3030000
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_SHIFT                       (0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_EN_DELAY_0_CTRL_IDLE_TO_TX_2P4G                             (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_EN_DELAY_0_CTRL_IDLE_TO_TX_2P4G_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_EN_DELAY_0_CTRL_IDLE_TO_TX_2P4G_SHIFT                       (8)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_SHIFT                       (16)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_EN_DELAY_0_CTRL_TX_2P4G_TO_IDLE                             (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_EN_DELAY_0_CTRL_TX_2P4G_TO_IDLE_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_EN_DELAY_0_CTRL_TX_2P4G_TO_IDLE_SHIFT                       (24)


#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RESETB_TOGGLE_DELAY_0_CTRL                                  (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xc4)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RESETB_TOGGLE_DELAY_0_CTRL_DEFAULT                          0x1C1C
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_2P4G                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_2P4G_MASK             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_2P4G_SHIFT            (0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_TX_2P4G                  (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_TX_2P4G_MASK             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_2P4_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_TX_2P4G_SHIFT            (8)


#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_EN_DELAY_0_CTRL                                             (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xc8)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_EN_DELAY_0_CTRL_DEFAULT                                     0x5050000
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT                       (0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G                             (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G_SHIFT                       (8)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_SHIFT                       (16)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_EN_DELAY_0_CTRL_TX_5P8G_TO_IDLE                             (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_EN_DELAY_0_CTRL_TX_5P8G_TO_IDLE_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_EN_DELAY_0_CTRL_TX_5P8G_TO_IDLE_SHIFT                       (24)


#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RESETB_TOGGLE_DELAY_0_CTRL                                  (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xcc)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RESETB_TOGGLE_DELAY_0_CTRL_DEFAULT                          0xA0A
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_5P8G                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT            (0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_TX_5P8G                  (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_TX_5P8G_MASK             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RESETB_TOGGLE_DELAY_0_CTRL_IDLE_TO_TX_5P8G_SHIFT            (8)


#define RXTX_SEQ_CTRL_REGISTERS_PA_2P4_EN_DELAY_0_CTRL                                               (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xd0)
#define RXTX_SEQ_CTRL_REGISTERS_PA_2P4_EN_DELAY_0_CTRL_DEFAULT                                       0x278
#define RXTX_SEQ_CTRL_REGISTERS_PA_2P4_EN_DELAY_0_CTRL_IDLE_TO_TX_2P4G                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_PA_2P4_EN_DELAY_0_CTRL_IDLE_TO_TX_2P4G_MASK                          (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_PA_2P4_EN_DELAY_0_CTRL_IDLE_TO_TX_2P4G_SHIFT                         (0)
#define RXTX_SEQ_CTRL_REGISTERS_PA_2P4_EN_DELAY_0_CTRL_TX_2P4G_TO_IDLE                               (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_PA_2P4_EN_DELAY_0_CTRL_TX_2P4G_TO_IDLE_MASK                          (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_PA_2P4_EN_DELAY_0_CTRL_TX_2P4G_TO_IDLE_SHIFT                         (8)


#define RXTX_SEQ_CTRL_REGISTERS_PA_5P8_EN_DELAY_0_CTRL                                               (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xd4)
#define RXTX_SEQ_CTRL_REGISTERS_PA_5P8_EN_DELAY_0_CTRL_DEFAULT                                       0x212
#define RXTX_SEQ_CTRL_REGISTERS_PA_5P8_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_PA_5P8_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G_MASK                          (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_PA_5P8_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G_SHIFT                         (0)
#define RXTX_SEQ_CTRL_REGISTERS_PA_5P8_EN_DELAY_0_CTRL_TX_5P8G_TO_IDLE                               (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_PA_5P8_EN_DELAY_0_CTRL_TX_5P8G_TO_IDLE_MASK                          (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_PA_5P8_EN_DELAY_0_CTRL_TX_5P8G_TO_IDLE_SHIFT                         (8)


#define RXTX_SEQ_CTRL_REGISTERS_SDADC_EN_DELAY_0_CTRL                                                (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xd8)
#define RXTX_SEQ_CTRL_REGISTERS_SDADC_EN_DELAY_0_CTRL_DEFAULT                                        0x3031313
#define RXTX_SEQ_CTRL_REGISTERS_SDADC_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_SDADC_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_MASK                           (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_SDADC_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_SHIFT                          (0)
#define RXTX_SEQ_CTRL_REGISTERS_SDADC_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G                                (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_SDADC_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK                           (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_SDADC_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT                          (8)
#define RXTX_SEQ_CTRL_REGISTERS_SDADC_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE                                (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_SDADC_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_MASK                           (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_SDADC_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_SHIFT                          (16)
#define RXTX_SEQ_CTRL_REGISTERS_SDADC_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE                                (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_SDADC_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_MASK                           (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_SDADC_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_SHIFT                          (24)


#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_AGC_EN_DELAY_0_CTRL                                            (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xdc)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_AGC_EN_DELAY_0_CTRL_DEFAULT                                    0x4041414
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_AGC_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_AGC_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_MASK                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_AGC_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_SHIFT                      (0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_AGC_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G                            (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_AGC_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_AGC_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT                      (8)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_AGC_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE                            (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_AGC_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_MASK                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_AGC_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_SHIFT                      (16)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_AGC_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE                            (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_AGC_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_MASK                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_AGC_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_SHIFT                      (24)


#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_EN_DELAY_0_CTRL                                                (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xe0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_EN_DELAY_0_CTRL_DEFAULT                                        0x4041414
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_MASK                           (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_EN_DELAY_0_CTRL_IDLE_TO_RX_2P4G_SHIFT                          (0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G                                (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK                           (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT                          (8)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE                                (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_MASK                           (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_EN_DELAY_0_CTRL_RX_2P4G_TO_IDLE_SHIFT                          (16)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE                                (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_MASK                           (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_FE_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_SHIFT                          (24)


#define RXTX_SEQ_CTRL_REGISTERS_TX_FE_EN_DELAY_0_CTRL                                                (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xe4)
#define RXTX_SEQ_CTRL_REGISTERS_TX_FE_EN_DELAY_0_CTRL_DEFAULT                                        0x4041414
#define RXTX_SEQ_CTRL_REGISTERS_TX_FE_EN_DELAY_0_CTRL_IDLE_TO_TX_2P4G                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_TX_FE_EN_DELAY_0_CTRL_IDLE_TO_TX_2P4G_MASK                           (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TX_FE_EN_DELAY_0_CTRL_IDLE_TO_TX_2P4G_SHIFT                          (0)
#define RXTX_SEQ_CTRL_REGISTERS_TX_FE_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G                                (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_TX_FE_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G_MASK                           (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TX_FE_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G_SHIFT                          (8)
#define RXTX_SEQ_CTRL_REGISTERS_TX_FE_EN_DELAY_0_CTRL_TX_2P4G_TO_IDLE                                (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_TX_FE_EN_DELAY_0_CTRL_TX_2P4G_TO_IDLE_MASK                           (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TX_FE_EN_DELAY_0_CTRL_TX_2P4G_TO_IDLE_SHIFT                          (16)
#define RXTX_SEQ_CTRL_REGISTERS_TX_FE_EN_DELAY_0_CTRL_TX_5P8G_TO_IDLE                                (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_TX_FE_EN_DELAY_0_CTRL_TX_5P8G_TO_IDLE_MASK                           (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TX_FE_EN_DELAY_0_CTRL_TX_5P8G_TO_IDLE_SHIFT                          (24)


#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_A_DELAY_0_CTRL                                            (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xe8)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_A_DELAY_0_CTRL_DEFAULT                                    0x5051515
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_A_DELAY_0_CTRL_IDLE_TO_TX_2P4G                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_A_DELAY_0_CTRL_IDLE_TO_TX_2P4G_MASK                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_A_DELAY_0_CTRL_IDLE_TO_TX_2P4G_SHIFT                      (0)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_A_DELAY_0_CTRL_IDLE_TO_TX_5P8G                            (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_A_DELAY_0_CTRL_IDLE_TO_TX_5P8G_MASK                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_A_DELAY_0_CTRL_IDLE_TO_TX_5P8G_SHIFT                      (8)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_A_DELAY_0_CTRL_TX_2P4G_TO_IDLE                            (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_A_DELAY_0_CTRL_TX_2P4G_TO_IDLE_MASK                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_A_DELAY_0_CTRL_TX_2P4G_TO_IDLE_SHIFT                      (16)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_A_DELAY_0_CTRL_TX_5P8G_TO_IDLE                            (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_A_DELAY_0_CTRL_TX_5P8G_TO_IDLE_MASK                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_A_DELAY_0_CTRL_TX_5P8G_TO_IDLE_SHIFT                      (24)


#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_B_DELAY_0_CTRL                                            (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xec)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_B_DELAY_0_CTRL_DEFAULT                                    0x5051515
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_B_DELAY_0_CTRL_IDLE_TO_TX_2P4G                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_B_DELAY_0_CTRL_IDLE_TO_TX_2P4G_MASK                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_B_DELAY_0_CTRL_IDLE_TO_TX_2P4G_SHIFT                      (0)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_B_DELAY_0_CTRL_IDLE_TO_TX_5P8G                            (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_B_DELAY_0_CTRL_IDLE_TO_TX_5P8G_MASK                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_B_DELAY_0_CTRL_IDLE_TO_TX_5P8G_SHIFT                      (8)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_B_DELAY_0_CTRL_TX_2P4G_TO_IDLE                            (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_B_DELAY_0_CTRL_TX_2P4G_TO_IDLE_MASK                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_B_DELAY_0_CTRL_TX_2P4G_TO_IDLE_SHIFT                      (16)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_B_DELAY_0_CTRL_TX_5P8G_TO_IDLE                            (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_B_DELAY_0_CTRL_TX_5P8G_TO_IDLE_MASK                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TX_EN_GPIO_B_DELAY_0_CTRL_TX_5P8G_TO_IDLE_SHIFT                      (24)


#define RXTX_SEQ_CTRL_REGISTERS_RX_EN_GPIO_DELAY_0_CTRL                                              (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xf0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_EN_GPIO_DELAY_0_CTRL_DEFAULT                                      0x5051515
#define RXTX_SEQ_CTRL_REGISTERS_RX_EN_GPIO_DELAY_0_CTRL_IDLE_TO_RX_2P4G                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_RX_EN_GPIO_DELAY_0_CTRL_IDLE_TO_RX_2P4G_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_EN_GPIO_DELAY_0_CTRL_IDLE_TO_RX_2P4G_SHIFT                        (0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_EN_GPIO_DELAY_0_CTRL_IDLE_TO_RX_5P8G                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_RX_EN_GPIO_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_EN_GPIO_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT                        (8)
#define RXTX_SEQ_CTRL_REGISTERS_RX_EN_GPIO_DELAY_0_CTRL_RX_2P4G_TO_IDLE                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_RX_EN_GPIO_DELAY_0_CTRL_RX_2P4G_TO_IDLE_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_EN_GPIO_DELAY_0_CTRL_RX_2P4G_TO_IDLE_SHIFT                        (16)
#define RXTX_SEQ_CTRL_REGISTERS_RX_EN_GPIO_DELAY_0_CTRL_RX_5P8G_TO_IDLE                              (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_RX_EN_GPIO_DELAY_0_CTRL_RX_5P8G_TO_IDLE_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_RX_EN_GPIO_DELAY_0_CTRL_RX_5P8G_TO_IDLE_SHIFT                        (24)


#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_0_CTRL                                       (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xf4)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_0_CTRL_DEFAULT                               0x0
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_0_CTRL_SLEEP_TO_IDLE                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_0_CTRL_SLEEP_TO_IDLE_MASK                    (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_0_CTRL_SLEEP_TO_IDLE_SHIFT                   (0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_0_CTRL_IDLE_TO_SLEEP                         (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_0_CTRL_IDLE_TO_SLEEP_MASK                    (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_0_CTRL_IDLE_TO_SLEEP_SHIFT                   (8)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_2P4G                       (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_2P4G_MASK                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_2P4G_SHIFT                 (16)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_5P8G                       (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT                 (24)


#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_1_CTRL                                       (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xf8)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_1_CTRL_DEFAULT                               0x0
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_1_CTRL_IDLE_TO_TX_2P4G                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_1_CTRL_IDLE_TO_TX_2P4G_MASK                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_1_CTRL_IDLE_TO_TX_2P4G_SHIFT                 (0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_1_CTRL_IDLE_TO_TX_5P8G                       (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_1_CTRL_IDLE_TO_TX_5P8G_MASK                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_1_CTRL_IDLE_TO_TX_5P8G_SHIFT                 (8)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_1_CTRL_RX_2P4G_TO_IDLE                       (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_1_CTRL_RX_2P4G_TO_IDLE_MASK                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_1_CTRL_RX_2P4G_TO_IDLE_SHIFT                 (16)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_1_CTRL_RX_5P8G_TO_IDLE                       (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_1_CTRL_RX_5P8G_TO_IDLE_MASK                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_1_CTRL_RX_5P8G_TO_IDLE_SHIFT                 (24)


#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_2_CTRL                                       (RXTX_SEQ_CTRL_REGISTERS_BASE + 0xfc)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_2_CTRL_DEFAULT                               0x0
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_2_CTRL_TX_2P4G_TO_IDLE                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_2_CTRL_TX_2P4G_TO_IDLE_MASK                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_2_CTRL_TX_2P4G_TO_IDLE_SHIFT                 (0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_2_CTRL_TX_5P8G_TO_IDLE                       (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_2_CTRL_TX_5P8G_TO_IDLE_MASK                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_GP_TRIGGER_TOGGLE_DELAY_2_CTRL_TX_5P8G_TO_IDLE_SHIFT                 (8)


#define RXTX_SEQ_CTRL_REGISTERS_USE_RF_TX_REGS_DELAY_0_CTRL                                          (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x100)
#define RXTX_SEQ_CTRL_REGISTERS_USE_RF_TX_REGS_DELAY_0_CTRL_DEFAULT                                  0x1010101
#define RXTX_SEQ_CTRL_REGISTERS_USE_RF_TX_REGS_DELAY_0_CTRL_IDLE_TO_TX_2P4G                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_USE_RF_TX_REGS_DELAY_0_CTRL_IDLE_TO_TX_2P4G_MASK                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_USE_RF_TX_REGS_DELAY_0_CTRL_IDLE_TO_TX_2P4G_SHIFT                    (0)
#define RXTX_SEQ_CTRL_REGISTERS_USE_RF_TX_REGS_DELAY_0_CTRL_IDLE_TO_TX_5P8G                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_USE_RF_TX_REGS_DELAY_0_CTRL_IDLE_TO_TX_5P8G_MASK                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_USE_RF_TX_REGS_DELAY_0_CTRL_IDLE_TO_TX_5P8G_SHIFT                    (8)
#define RXTX_SEQ_CTRL_REGISTERS_USE_RF_TX_REGS_DELAY_0_CTRL_TX_2P4G_TO_IDLE                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_USE_RF_TX_REGS_DELAY_0_CTRL_TX_2P4G_TO_IDLE_MASK                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_USE_RF_TX_REGS_DELAY_0_CTRL_TX_2P4G_TO_IDLE_SHIFT                    (16)
#define RXTX_SEQ_CTRL_REGISTERS_USE_RF_TX_REGS_DELAY_0_CTRL_TX_5P8G_TO_IDLE                          (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_USE_RF_TX_REGS_DELAY_0_CTRL_TX_5P8G_TO_IDLE_MASK                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_USE_RF_TX_REGS_DELAY_0_CTRL_TX_5P8G_TO_IDLE_SHIFT                    (24)


#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RX_EN_DELAY_0_CTRL                                          (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x104)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RX_EN_DELAY_0_CTRL_DEFAULT                                  0x302
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RX_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RX_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RX_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT                    (0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RX_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RX_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_MASK                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_RX_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_SHIFT                    (8)


#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_TX_EN_DELAY_0_CTRL                                          (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x108)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_TX_EN_DELAY_0_CTRL_DEFAULT                                  0x302
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_TX_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_TX_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G_MASK                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_TX_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G_SHIFT                    (0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_TX_EN_DELAY_0_CTRL_TX_5P8G_TO_IDLE                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_TX_EN_DELAY_0_CTRL_TX_5P8G_TO_IDLE_MASK                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_MPLL_5P8_TX_EN_DELAY_0_CTRL_TX_5P8G_TO_IDLE_SHIFT                    (8)


#define RXTX_SEQ_CTRL_REGISTERS_RFFE_5P8_EN_DELAY_0_CTRL                                             (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x10c)
#define RXTX_SEQ_CTRL_REGISTERS_RFFE_5P8_EN_DELAY_0_CTRL_DEFAULT                                     0x5050404
#define RXTX_SEQ_CTRL_REGISTERS_RFFE_5P8_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RXTX_SEQ_CTRL_REGISTERS_RFFE_5P8_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_RFFE_5P8_EN_DELAY_0_CTRL_IDLE_TO_RX_5P8G_SHIFT                       (0)
#define RXTX_SEQ_CTRL_REGISTERS_RFFE_5P8_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G                             (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RXTX_SEQ_CTRL_REGISTERS_RFFE_5P8_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_RFFE_5P8_EN_DELAY_0_CTRL_IDLE_TO_TX_5P8G_SHIFT                       (8)
#define RXTX_SEQ_CTRL_REGISTERS_RFFE_5P8_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RXTX_SEQ_CTRL_REGISTERS_RFFE_5P8_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_RFFE_5P8_EN_DELAY_0_CTRL_RX_5P8G_TO_IDLE_SHIFT                       (16)
#define RXTX_SEQ_CTRL_REGISTERS_RFFE_5P8_EN_DELAY_0_CTRL_TX_5P8G_TO_IDLE                             (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RXTX_SEQ_CTRL_REGISTERS_RFFE_5P8_EN_DELAY_0_CTRL_TX_5P8G_TO_IDLE_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_RFFE_5P8_EN_DELAY_0_CTRL_TX_5P8G_TO_IDLE_SHIFT                       (24)


#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_0_CTRL                                             (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x200)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_0_CTRL_DEFAULT                                     0x0
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_0_CTRL_BIT_0                                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_0_CTRL_BIT_0_MASK                                  (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_0_CTRL_BIT_0_SHIFT                                 (0)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_0_CTRL_BIT_1                                       (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_0_CTRL_BIT_1_MASK                                  (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_0_CTRL_BIT_1_SHIFT                                 (8)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_0_CTRL_BIT_2                                       (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_0_CTRL_BIT_2_MASK                                  (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_0_CTRL_BIT_2_SHIFT                                 (16)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_0_CTRL_BIT_3                                       (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_0_CTRL_BIT_3_MASK                                  (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_0_CTRL_BIT_3_SHIFT                                 (24)


#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_1_CTRL                                             (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x204)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_1_CTRL_DEFAULT                                     0x0
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_1_CTRL_BIT_4                                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_1_CTRL_BIT_4_MASK                                  (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_1_CTRL_BIT_4_SHIFT                                 (0)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_1_CTRL_BIT_5                                       (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_1_CTRL_BIT_5_MASK                                  (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_1_CTRL_BIT_5_SHIFT                                 (8)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_1_CTRL_BIT_6                                       (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_1_CTRL_BIT_6_MASK                                  (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_1_CTRL_BIT_6_SHIFT                                 (16)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_1_CTRL_BIT_7                                       (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_1_CTRL_BIT_7_MASK                                  (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_1_CTRL_BIT_7_SHIFT                                 (24)


#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_2_CTRL                                             (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x208)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_2_CTRL_DEFAULT                                     0x0
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_2_CTRL_BIT_8                                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_2_CTRL_BIT_8_MASK                                  (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_2_CTRL_BIT_8_SHIFT                                 (0)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_2_CTRL_BIT_9                                       (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_2_CTRL_BIT_9_MASK                                  (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_2_CTRL_BIT_9_SHIFT                                 (8)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_2_CTRL_BIT_10                                      (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_2_CTRL_BIT_10_MASK                                 (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_2_CTRL_BIT_10_SHIFT                                (16)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_2_CTRL_BIT_11                                      (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_2_CTRL_BIT_11_MASK                                 (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_TEST_BUS_MEGA_MUX_2_CTRL_BIT_11_SHIFT                                (24)


#define RXTX_SEQ_CTRL_REGISTERS_CURRENT_STATES                                                       (RXTX_SEQ_CTRL_REGISTERS_BASE + 0x240)
#define RXTX_SEQ_CTRL_REGISTERS_CURRENT_STATES_DEFAULT                                               0x0
#define RXTX_SEQ_CTRL_REGISTERS_CURRENT_STATES_RXTX_SEQ_STATE                                        (Bit0+Bit1+Bit2+Bit3+Bit4)
#define RXTX_SEQ_CTRL_REGISTERS_CURRENT_STATES_RXTX_SEQ_STATE_MASK                                   (Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_CURRENT_STATES_RXTX_SEQ_STATE_SHIFT                                  (0)
#define RXTX_SEQ_CTRL_REGISTERS_CURRENT_STATES_LAST_RXTX_SEQ_STATE                                   (Bit8+Bit9+Bit10+Bit11+Bit12)
#define RXTX_SEQ_CTRL_REGISTERS_CURRENT_STATES_LAST_RXTX_SEQ_STATE_MASK                              (Bit4+Bit3+Bit2+Bit1+Bit0)
#define RXTX_SEQ_CTRL_REGISTERS_CURRENT_STATES_LAST_RXTX_SEQ_STATE_SHIFT                             (8)


#endif // _RXTX_SEQ_CTRL_REGISTERS_DEFINES_H

