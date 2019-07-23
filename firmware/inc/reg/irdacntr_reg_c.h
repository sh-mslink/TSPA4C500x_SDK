/* **************************** */
#define IRDACNTR_REG_INTR_STATUS                                                 (IRDACNTR_REG_BASE + 0x0)
#define IRDACNTR_REG_INTR_STATUS_DEFAULT                                         0x0
#define IRDACNTR_REG_INTR_STATUS_TX_DONE                                         (Bit0)


#define IRDACNTR_REG_INTR_MASK_STATUS                                            (IRDACNTR_REG_BASE + 0x4)
#define IRDACNTR_REG_INTR_MASK_STATUS_DEFAULT                                    0x0
#define IRDACNTR_REG_INTR_MASK_STATUS_TX_DONE                                    (Bit0)


#define IRDACNTR_REG_INTR_CLEAR                                                  (IRDACNTR_REG_BASE + 0x8)
#define IRDACNTR_REG_INTR_CLEAR_DEFAULT                                          0x0
#define IRDACNTR_REG_INTR_CLEAR_TX_DONE                                          (Bit0)


#define IRDACNTR_REG_INTR_SET                                                    (IRDACNTR_REG_BASE + 0xc)
#define IRDACNTR_REG_INTR_SET_DEFAULT                                            0x0
#define IRDACNTR_REG_INTR_SET_TX_DONE                                            (Bit0)


#define IRDACNTR_REG_INTR_MASK_SET                                               (IRDACNTR_REG_BASE + 0x10)
#define IRDACNTR_REG_INTR_MASK_SET_DEFAULT                                       0x0
#define IRDACNTR_REG_INTR_MASK_SET_TX_DONE                                       (Bit0)


#define IRDACNTR_REG_INTR_MASK_CLEAR                                             (IRDACNTR_REG_BASE + 0x14)
#define IRDACNTR_REG_INTR_MASK_CLEAR_DEFAULT                                     0x0
#define IRDACNTR_REG_INTR_MASK_CLEAR_TX_DONE                                     (Bit0)


#define IRDACNTR_REG_MISC_CTRL                                                   (IRDACNTR_REG_BASE + 0x40)
#define IRDACNTR_REG_MISC_CTRL_DEFAULT                                           0x0
#define IRDACNTR_REG_MISC_CTRL_CTL_ENABLE                                        (Bit0)
#define IRDACNTR_REG_MISC_CTRL_CTL_OP_MODE                                       (Bit1)
#define IRDACNTR_REG_MISC_CTRL_CTL_RST_INTRCTRL                                  (Bit4)


#define IRDACNTR_REG_TX_CTRL                                                     (IRDACNTR_REG_BASE + 0x44)
#define IRDACNTR_REG_TX_CTRL_DEFAULT                                             0x50030
#define IRDACNTR_REG_TX_CTRL_START                                               (Bit0)
#define IRDACNTR_REG_TX_CTRL_CTL_TX_MOD_USE_CLK                                  (Bit4)
#define IRDACNTR_REG_TX_CTRL_CTL_TX_MOD_USE_COMPLETE_CLK                         (Bit5)
#define IRDACNTR_REG_TX_CTRL_CTL_TX_MOD_IN_STREAM_POLARITY_INV                   (Bit8)
#define IRDACNTR_REG_TX_CTRL_CTL_TX_STREAM_CNT_UNIT                              (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define IRDACNTR_REG_TX_CTRL_CTL_TX_STREAM_CNT_UNIT_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IRDACNTR_REG_TX_CTRL_CTL_TX_STREAM_CNT_UNIT_SHIFT                        (12)


#define IRDACNTR_REG_TX_MOD_CLK_CTRL                                             (IRDACNTR_REG_BASE + 0x48)
#define IRDACNTR_REG_TX_MOD_CLK_CTRL_DEFAULT                                     0x8C046
#define IRDACNTR_REG_TX_MOD_CLK_CTRL_CTL_TX_MOD_CLK_HIGH_PERIOD                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define IRDACNTR_REG_TX_MOD_CLK_CTRL_CTL_TX_MOD_CLK_HIGH_PERIOD_MASK             (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IRDACNTR_REG_TX_MOD_CLK_CTRL_CTL_TX_MOD_CLK_HIGH_PERIOD_SHIFT            (0)
#define IRDACNTR_REG_TX_MOD_CLK_CTRL_CTL_TX_MOD_CLK_LOW_PERIOD                   (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define IRDACNTR_REG_TX_MOD_CLK_CTRL_CTL_TX_MOD_CLK_LOW_PERIOD_MASK              (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IRDACNTR_REG_TX_MOD_CLK_CTRL_CTL_TX_MOD_CLK_LOW_PERIOD_SHIFT             (12)


#define IRDACNTR_REG_SM_CTRL                                                     (IRDACNTR_REG_BASE + 0x60)
#define IRDACNTR_REG_SM_CTRL_DEFAULT                                             0x0
#define IRDACNTR_REG_SM_CTRL_CTL_TX_SM_ADDR_OFFSET                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define IRDACNTR_REG_SM_CTRL_CTL_TX_SM_ADDR_OFFSET_MASK                          (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IRDACNTR_REG_SM_CTRL_CTL_TX_SM_ADDR_OFFSET_SHIFT                         (0)


