#ifndef _FRONTEND_REGS_DEFINES_H
#define _FRONTEND_REGS_DEFINES_H
/* **************************** */
#define FRONTEND_REGS_FIFO_FLOW_STATUS                                                   (FRONTEND_REGS_BASE + 0x0)
#define FRONTEND_REGS_FIFO_FLOW_STATUS_DEFAULT                                           0x0
#define FRONTEND_REGS_FIFO_FLOW_STATUS_STS_RX_AFIFO_OVERFLOW                             (Bit0)
#define FRONTEND_REGS_FIFO_FLOW_STATUS_STS_RX_AFIFO_UNDERFLOW                            (Bit1)
#define FRONTEND_REGS_FIFO_FLOW_STATUS_STS_TX_AFIFO_OVERFLOW                             (Bit2)
#define FRONTEND_REGS_FIFO_FLOW_STATUS_STS_TX_AFIFO_UNDERFLOW                            (Bit3)


#define FRONTEND_REGS_FIFO_FLOW_CTRL                                                     (FRONTEND_REGS_BASE + 0x4)
#define FRONTEND_REGS_FIFO_FLOW_CTRL_DEFAULT                                             0x0
#define FRONTEND_REGS_FIFO_FLOW_CTRL_CTLT_RX_AFIFO_CLEAR_FLOW                            (Bit0)
#define FRONTEND_REGS_FIFO_FLOW_CTRL_CTLT_TX_AFIFO_CLEAR_FLOW                            (Bit1)


#define FRONTEND_REGS_MISC_CTRL0                                                         (FRONTEND_REGS_BASE + 0x40)
#define FRONTEND_REGS_MISC_CTRL0_DEFAULT                                                 0x8B0B
#define FRONTEND_REGS_MISC_CTRL0_CTLT_RX_AFIFO_EN_WR                                     (Bit0)
#define FRONTEND_REGS_MISC_CTRL0_CTLT_RX_AFIFO_EN_RD                                     (Bit1)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_RX_AFIFO_READ_START                                (Bit2+Bit3+Bit4)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_RX_AFIFO_READ_START_MASK                           (Bit2+Bit1+Bit0)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_RX_AFIFO_READ_START_SHIFT                          (2)
#define FRONTEND_REGS_MISC_CTRL0_CTLT_RX_SRESET_CICDEC4                                  (Bit5)
#define FRONTEND_REGS_MISC_CTRL0_CTLT_RX_SRESET_DDFS                                     (Bit6)
#define FRONTEND_REGS_MISC_CTRL0_CTLT_RX_SRESET_CICDEC2                                  (Bit7)
#define FRONTEND_REGS_MISC_CTRL0_CTLT_TX_AFIFO_EN_WR                                     (Bit8)
#define FRONTEND_REGS_MISC_CTRL0_CTLT_TX_AFIFO_EN_RD                                     (Bit9)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_TX_AFIFO_READ_START                                (Bit10+Bit11+Bit12)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_TX_AFIFO_READ_START_MASK                           (Bit2+Bit1+Bit0)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_TX_AFIFO_READ_START_SHIFT                          (10)
#define FRONTEND_REGS_MISC_CTRL0_CTLT_TX_SRESET_INT                                      (Bit13)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_RX_SWAP_IQ_INPUT                                   (Bit14)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_RX_SWAP_IQ_OUTPUT                                  (Bit15)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_RX_READ_NUM                                        (Bit16+Bit17+Bit18+Bit19)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_RX_READ_NUM_MASK                                   (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_RX_READ_NUM_SHIFT                                  (16)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_RX_READ_DEN                                        (Bit20+Bit21+Bit22+Bit23)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_RX_READ_DEN_MASK                                   (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_RX_READ_DEN_SHIFT                                  (20)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_RX_INV_I_IN                                        (Bit24)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_RX_INV_Q_IN                                        (Bit25)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_TX_DAC_NEG_LP                                      (Bit26)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_TX_DAC_NEG_HP                                      (Bit27)
#define FRONTEND_REGS_MISC_CTRL0_STS_RX_READING                                          (Bit28)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_RX_SAMP_NEG_I                                      (Bit29)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_RX_SAMP_NEG_Q                                      (Bit30)
#define FRONTEND_REGS_MISC_CTRL0_CTLQ_RX_DDFS_BYP                                        (Bit31)


#define FRONTEND_REGS_RX_DC_CTRL0                                                        (FRONTEND_REGS_BASE + 0x44)
#define FRONTEND_REGS_RX_DC_CTRL0_DEFAULT                                                0x800080
#define FRONTEND_REGS_RX_DC_CTRL0_CTLT_RX_DEC4_DC_I                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8)
#define FRONTEND_REGS_RX_DC_CTRL0_CTLT_RX_DEC4_DC_I_MASK                                 (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_DC_CTRL0_CTLT_RX_DEC4_DC_I_SHIFT                                (0)
#define FRONTEND_REGS_RX_DC_CTRL0_CTLT_RX_DEC4_DC_Q                                      (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24)
#define FRONTEND_REGS_RX_DC_CTRL0_CTLT_RX_DEC4_DC_Q_MASK                                 (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_DC_CTRL0_CTLT_RX_DEC4_DC_Q_SHIFT                                (16)


#define FRONTEND_REGS_RX_FIFO_STAT0                                                      (FRONTEND_REGS_BASE + 0x48)
#define FRONTEND_REGS_RX_FIFO_STAT0_DEFAULT                                              0x0
#define FRONTEND_REGS_RX_FIFO_STAT0_STS_RX_AFIFO_WR_PNT_RCK                              (Bit0+Bit1+Bit2+Bit3)
#define FRONTEND_REGS_RX_FIFO_STAT0_STS_RX_AFIFO_WR_PNT_RCK_MASK                         (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_FIFO_STAT0_STS_RX_AFIFO_WR_PNT_RCK_SHIFT                        (0)
#define FRONTEND_REGS_RX_FIFO_STAT0_STS_RX_AFIFO_RD_PNT_RCK                              (Bit4+Bit5+Bit6+Bit7)
#define FRONTEND_REGS_RX_FIFO_STAT0_STS_RX_AFIFO_RD_PNT_RCK_MASK                         (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_FIFO_STAT0_STS_RX_AFIFO_RD_PNT_RCK_SHIFT                        (4)
#define FRONTEND_REGS_RX_FIFO_STAT0_STS_RX_AFIFO_WR_PNT_WCK                              (Bit8+Bit9+Bit10+Bit11)
#define FRONTEND_REGS_RX_FIFO_STAT0_STS_RX_AFIFO_WR_PNT_WCK_MASK                         (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_FIFO_STAT0_STS_RX_AFIFO_WR_PNT_WCK_SHIFT                        (8)
#define FRONTEND_REGS_RX_FIFO_STAT0_STS_RX_AFIFO_RD_PNT_WCK                              (Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_RX_FIFO_STAT0_STS_RX_AFIFO_RD_PNT_WCK_MASK                         (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_FIFO_STAT0_STS_RX_AFIFO_RD_PNT_WCK_SHIFT                        (12)
#define FRONTEND_REGS_RX_FIFO_STAT0_STS_RX_AFIFO_FILL_RCK                                (Bit16+Bit17+Bit18+Bit19)
#define FRONTEND_REGS_RX_FIFO_STAT0_STS_RX_AFIFO_FILL_RCK_MASK                           (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_FIFO_STAT0_STS_RX_AFIFO_FILL_RCK_SHIFT                          (16)
#define FRONTEND_REGS_RX_FIFO_STAT0_CTLT_RX_AFIFO_SNAP                                   (Bit20)


#define FRONTEND_REGS_TX_FIFO_STAT0                                                      (FRONTEND_REGS_BASE + 0x4c)
#define FRONTEND_REGS_TX_FIFO_STAT0_DEFAULT                                              0x0
#define FRONTEND_REGS_TX_FIFO_STAT0_STS_TX_AFIFO_WR_PNT_RCK                              (Bit0+Bit1+Bit2+Bit3)
#define FRONTEND_REGS_TX_FIFO_STAT0_STS_TX_AFIFO_WR_PNT_RCK_MASK                         (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_TX_FIFO_STAT0_STS_TX_AFIFO_WR_PNT_RCK_SHIFT                        (0)
#define FRONTEND_REGS_TX_FIFO_STAT0_STS_TX_AFIFO_RD_PNT_RCK                              (Bit4+Bit5+Bit6+Bit7)
#define FRONTEND_REGS_TX_FIFO_STAT0_STS_TX_AFIFO_RD_PNT_RCK_MASK                         (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_TX_FIFO_STAT0_STS_TX_AFIFO_RD_PNT_RCK_SHIFT                        (4)
#define FRONTEND_REGS_TX_FIFO_STAT0_STS_TX_AFIFO_WR_PNT_WCK                              (Bit8+Bit9+Bit10+Bit11)
#define FRONTEND_REGS_TX_FIFO_STAT0_STS_TX_AFIFO_WR_PNT_WCK_MASK                         (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_TX_FIFO_STAT0_STS_TX_AFIFO_WR_PNT_WCK_SHIFT                        (8)
#define FRONTEND_REGS_TX_FIFO_STAT0_STS_TX_AFIFO_RD_PNT_WCK                              (Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_TX_FIFO_STAT0_STS_TX_AFIFO_RD_PNT_WCK_MASK                         (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_TX_FIFO_STAT0_STS_TX_AFIFO_RD_PNT_WCK_SHIFT                        (12)
#define FRONTEND_REGS_TX_FIFO_STAT0_STS_TX_AFIFO_FILL_RCK                                (Bit16+Bit17+Bit18+Bit19)
#define FRONTEND_REGS_TX_FIFO_STAT0_STS_TX_AFIFO_FILL_RCK_MASK                           (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_TX_FIFO_STAT0_STS_TX_AFIFO_FILL_RCK_SHIFT                          (16)
#define FRONTEND_REGS_TX_FIFO_STAT0_CTLT_TX_AFIFO_SNAP                                   (Bit20)


#define FRONTEND_REGS_DC_ACC_CTRL                                                        (FRONTEND_REGS_BASE + 0x50)
#define FRONTEND_REGS_DC_ACC_CTRL_DEFAULT                                                0x0
#define FRONTEND_REGS_DC_ACC_CTRL_CTLQ_DC_ACC_CNT                                        (Bit0+Bit1+Bit2)
#define FRONTEND_REGS_DC_ACC_CTRL_CTLQ_DC_ACC_CNT_MASK                                   (Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DC_ACC_CTRL_CTLQ_DC_ACC_CNT_SHIFT                                  (0)


#define FRONTEND_REGS_DC_ACC_STAT0                                                       (FRONTEND_REGS_BASE + 0x54)
#define FRONTEND_REGS_DC_ACC_STAT0_DEFAULT                                               0x0
#define FRONTEND_REGS_DC_ACC_STAT0_STS_DC_ACC_I                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define FRONTEND_REGS_DC_ACC_STAT0_STS_DC_ACC_I_MASK                                     (Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DC_ACC_STAT0_STS_DC_ACC_I_SHIFT                                    (0)
#define FRONTEND_REGS_DC_ACC_STAT0_STS_DC_ACC_DONE                                       (Bit28)


#define FRONTEND_REGS_DC_ACC_STAT1                                                       (FRONTEND_REGS_BASE + 0x58)
#define FRONTEND_REGS_DC_ACC_STAT1_DEFAULT                                               0x0
#define FRONTEND_REGS_DC_ACC_STAT1_STS_DC_ACC_Q                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define FRONTEND_REGS_DC_ACC_STAT1_STS_DC_ACC_Q_MASK                                     (Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DC_ACC_STAT1_STS_DC_ACC_Q_SHIFT                                    (0)


#define FRONTEND_REGS_MISC_CTRL1                                                         (FRONTEND_REGS_BASE + 0x5c)
#define FRONTEND_REGS_MISC_CTRL1_DEFAULT                                                 0x1000000
#define FRONTEND_REGS_MISC_CTRL1_CTLT_TX_LP_FRC_EN                                       (Bit0)
#define FRONTEND_REGS_MISC_CTRL1_CTLT_TX_HP_FRC_EN                                       (Bit1)
#define FRONTEND_REGS_MISC_CTRL1_CTLQ_TX_LP_FRC_DAT                                      (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_MISC_CTRL1_CTLQ_TX_LP_FRC_DAT_MASK                                 (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_MISC_CTRL1_CTLQ_TX_LP_FRC_DAT_SHIFT                                (8)
#define FRONTEND_REGS_MISC_CTRL1_CTLQ_TX_HP_FRC_DAT                                      (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define FRONTEND_REGS_MISC_CTRL1_CTLQ_TX_HP_FRC_DAT_MASK                                 (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_MISC_CTRL1_CTLQ_TX_HP_FRC_DAT_SHIFT                                (16)
#define FRONTEND_REGS_MISC_CTRL1_CTLQ_RX_LONGRANGE_FRC                                   (Bit24)
#define FRONTEND_REGS_MISC_CTRL1_CTLQ_RX_LONGRANGE_VAL                                   (Bit25)
#define FRONTEND_REGS_MISC_CTRL1_CTLQ_TX_RATE_FRC                                        (Bit26)
#define FRONTEND_REGS_MISC_CTRL1_CTLQ_TX_RATE_VAL                                        (Bit27)
#define FRONTEND_REGS_MISC_CTRL1_CTLQ_TX_BAND_FRC                                        (Bit28)
#define FRONTEND_REGS_MISC_CTRL1_CTLQ_TX_BAND_VAL                                        (Bit29)


#define FRONTEND_REGS_RX_AGC_CTRL0                                                       (FRONTEND_REGS_BASE + 0x60)
#define FRONTEND_REGS_RX_AGC_CTRL0_DEFAULT                                               0x119E080
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_INIT_GAIN_CODE                                    (Bit0+Bit1+Bit2+Bit3)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_INIT_GAIN_CODE_MASK                               (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_INIT_GAIN_CODE_SHIFT                              (0)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_MAX_GAIN_CODE                                     (Bit4+Bit5+Bit6+Bit7)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_MAX_GAIN_CODE_MASK                                (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_MAX_GAIN_CODE_SHIFT                               (4)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_MIN_GAIN_CODE                                     (Bit8+Bit9+Bit10+Bit11)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_MIN_GAIN_CODE_MASK                                (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_MIN_GAIN_CODE_SHIFT                               (8)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_WINDOW_TIMING                                     (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_WINDOW_TIMING_MASK                                (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_WINDOW_TIMING_SHIFT                               (12)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_SETTLING_TIMING                                   (Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_SETTLING_TIMING_MASK                              (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_SETTLING_TIMING_SHIFT                             (18)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_TOO_HIGH_TH                                       (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_TOO_HIGH_TH_MASK                                  (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_TOO_HIGH_TH_SHIFT                                 (24)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_AGC_SRESET                                        (Bit30)
#define FRONTEND_REGS_RX_AGC_CTRL0_CTL_AGC_AUTO_SRESET                                   (Bit31)


#define FRONTEND_REGS_RX_AGC_CTRL1                                                       (FRONTEND_REGS_BASE + 0x64)
#define FRONTEND_REGS_RX_AGC_CTRL1_DEFAULT                                               0x85F785
#define FRONTEND_REGS_RX_AGC_CTRL1_CTL_ULTRA_HIGH_TH                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTL_ULTRA_HIGH_TH_MASK                                (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTL_ULTRA_HIGH_TH_SHIFT                               (0)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTL_TOO_LOW_TH                                        (Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTL_TOO_LOW_TH_MASK                                   (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTL_TOO_LOW_TH_SHIFT                                  (6)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTL_ULTRA_LOW_TH                                      (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTL_ULTRA_LOW_TH_MASK                                 (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTL_ULTRA_LOW_TH_SHIFT                                (12)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTL_TOO_HIGH_GAIN_STEP                                (Bit18+Bit19+Bit20+Bit21)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTL_TOO_HIGH_GAIN_STEP_MASK                           (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTL_TOO_HIGH_GAIN_STEP_SHIFT                          (18)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTL_ULTRA_HIGH_GAIN_STEP                              (Bit22+Bit23+Bit24+Bit25)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTL_ULTRA_HIGH_GAIN_STEP_MASK                         (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTL_ULTRA_HIGH_GAIN_STEP_SHIFT                        (22)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTLQ_AGC_SEL_IN                                       (Bit28+Bit29)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTLQ_AGC_SEL_IN_MASK                                  (Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_CTRL1_CTLQ_AGC_SEL_IN_SHIFT                                 (28)


#define FRONTEND_REGS_RX_AGC_CTRL2                                                       (FRONTEND_REGS_BASE + 0x68)
#define FRONTEND_REGS_RX_AGC_CTRL2_DEFAULT                                               0x110421
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_TOO_LOW_GAIN_STEP                                 (Bit0+Bit1+Bit2+Bit3)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_TOO_LOW_GAIN_STEP_MASK                            (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_TOO_LOW_GAIN_STEP_SHIFT                           (0)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_ULTRA_LOW_GAIN_STEP                               (Bit4+Bit5+Bit6+Bit7)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_ULTRA_LOW_GAIN_STEP_MASK                          (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_ULTRA_LOW_GAIN_STEP_SHIFT                         (4)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_OPPOSITE_GAIN_ADJUST                              (Bit8)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_GAIN_FREEZE                                       (Bit9)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_GAIN_FREEZE_AFTER_SYNC                            (Bit10)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_SWAP_HIGH_LOW_INPUT                               (Bit11)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_RESET_TO_INIT_GAIN                                (Bit12)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_GAIN_CODE_CHANGE_PULSE_WIDTH                      (Bit16+Bit17)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_GAIN_CODE_CHANGE_PULSE_WIDTH_MASK                 (Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_GAIN_CODE_CHANGE_PULSE_WIDTH_SHIFT                (16)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_RX_AGC_GAIN_RESET_RX_DISABLE                      (Bit20)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_RX_AGC_GAIN_RESET_RX_DISABLE_VAL                  (Bit24+Bit25+Bit26+Bit27)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_RX_AGC_GAIN_RESET_RX_DISABLE_VAL_MASK             (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_CTRL2_CTL_RX_AGC_GAIN_RESET_RX_DISABLE_VAL_SHIFT            (24)


#define FRONTEND_REGS_RX_AGC_STAT0                                                       (FRONTEND_REGS_BASE + 0x6c)
#define FRONTEND_REGS_RX_AGC_STAT0_DEFAULT                                               0x0
#define FRONTEND_REGS_RX_AGC_STAT0_CTL_AGC_GAIN_CODE_FREEZE                              (Bit0)
#define FRONTEND_REGS_RX_AGC_STAT0_STS_AGC_GAIN_CODE                                     (Bit1+Bit2+Bit3+Bit4)
#define FRONTEND_REGS_RX_AGC_STAT0_STS_AGC_GAIN_CODE_MASK                                (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_STAT0_STS_AGC_GAIN_CODE_SHIFT                               (1)
#define FRONTEND_REGS_RX_AGC_STAT0_STS_AGC_THERMAL_GAIN_CODE                             (Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define FRONTEND_REGS_RX_AGC_STAT0_STS_AGC_THERMAL_GAIN_CODE_MASK                        (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_AGC_STAT0_STS_AGC_THERMAL_GAIN_CODE_SHIFT                       (5)


#define FRONTEND_REGS_AGC_GAIN_LUT0                                                      (FRONTEND_REGS_BASE + 0x70)
#define FRONTEND_REGS_AGC_GAIN_LUT0_DEFAULT                                              0x1F3F7FFF
#define FRONTEND_REGS_AGC_GAIN_LUT0_CTL_THERMAL_GAIN_CODE_LUT0                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_AGC_GAIN_LUT0_CTL_THERMAL_GAIN_CODE_LUT0_MASK                      (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_AGC_GAIN_LUT0_CTL_THERMAL_GAIN_CODE_LUT0_SHIFT                     (0)


#define FRONTEND_REGS_AGC_GAIN_LUT1                                                      (FRONTEND_REGS_BASE + 0x74)
#define FRONTEND_REGS_AGC_GAIN_LUT1_DEFAULT                                              0x103070F
#define FRONTEND_REGS_AGC_GAIN_LUT1_CTL_THERMAL_GAIN_CODE_LUT1                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_AGC_GAIN_LUT1_CTL_THERMAL_GAIN_CODE_LUT1_MASK                      (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_AGC_GAIN_LUT1_CTL_THERMAL_GAIN_CODE_LUT1_SHIFT                     (0)


#define FRONTEND_REGS_AGC_GAIN_LUT2                                                      (FRONTEND_REGS_BASE + 0x78)
#define FRONTEND_REGS_AGC_GAIN_LUT2_DEFAULT                                              0xFFFFFFFF
#define FRONTEND_REGS_AGC_GAIN_LUT2_CTL_THERMAL_GAIN_CODE_LUT2                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_AGC_GAIN_LUT2_CTL_THERMAL_GAIN_CODE_LUT2_MASK                      (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_AGC_GAIN_LUT2_CTL_THERMAL_GAIN_CODE_LUT2_SHIFT                     (0)


#define FRONTEND_REGS_RSSI_CTRL0                                                         (FRONTEND_REGS_BASE + 0x80)
#define FRONTEND_REGS_RSSI_CTRL0_DEFAULT                                                 0x600C3000
#define FRONTEND_REGS_RSSI_CTRL0_CTL_RSSI_OFFSET                                         (Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18)
#define FRONTEND_REGS_RSSI_CTRL0_CTL_RSSI_OFFSET_MASK                                    (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RSSI_CTRL0_CTL_RSSI_OFFSET_SHIFT                                   (9)
#define FRONTEND_REGS_RSSI_CTRL0_CTL_RSSI_MIN                                            (Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30)
#define FRONTEND_REGS_RSSI_CTRL0_CTL_RSSI_MIN_MASK                                       (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RSSI_CTRL0_CTL_RSSI_MIN_SHIFT                                      (19)


#define FRONTEND_REGS_RSSI_CTRL1                                                         (FRONTEND_REGS_BASE + 0x84)
#define FRONTEND_REGS_RSSI_CTRL1_DEFAULT                                                 0x6A79DF0
#define FRONTEND_REGS_RSSI_CTRL1_CTL_RSSI_LUT0                                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8)
#define FRONTEND_REGS_RSSI_CTRL1_CTL_RSSI_LUT0_MASK                                      (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RSSI_CTRL1_CTL_RSSI_LUT0_SHIFT                                     (0)
#define FRONTEND_REGS_RSSI_CTRL1_CTL_RSSI_LUT1                                           (Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define FRONTEND_REGS_RSSI_CTRL1_CTL_RSSI_LUT1_MASK                                      (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RSSI_CTRL1_CTL_RSSI_LUT1_SHIFT                                     (9)
#define FRONTEND_REGS_RSSI_CTRL1_CTL_RSSI_LUT2                                           (Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26)
#define FRONTEND_REGS_RSSI_CTRL1_CTL_RSSI_LUT2_MASK                                      (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RSSI_CTRL1_CTL_RSSI_LUT2_SHIFT                                     (18)


#define FRONTEND_REGS_RSSI_CTRL2                                                         (FRONTEND_REGS_BASE + 0x88)
#define FRONTEND_REGS_RSSI_CTRL2_DEFAULT                                                 0x542ED94
#define FRONTEND_REGS_RSSI_CTRL2_CTL_RSSI_LUT3                                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8)
#define FRONTEND_REGS_RSSI_CTRL2_CTL_RSSI_LUT3_MASK                                      (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RSSI_CTRL2_CTL_RSSI_LUT3_SHIFT                                     (0)
#define FRONTEND_REGS_RSSI_CTRL2_CTL_RSSI_LUT4                                           (Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define FRONTEND_REGS_RSSI_CTRL2_CTL_RSSI_LUT4_MASK                                      (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RSSI_CTRL2_CTL_RSSI_LUT4_SHIFT                                     (9)
#define FRONTEND_REGS_RSSI_CTRL2_CTL_RSSI_LUT5                                           (Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26)
#define FRONTEND_REGS_RSSI_CTRL2_CTL_RSSI_LUT5_MASK                                      (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RSSI_CTRL2_CTL_RSSI_LUT5_SHIFT                                     (18)


#define FRONTEND_REGS_RSSI_CTRL3                                                         (FRONTEND_REGS_BASE + 0x8c)
#define FRONTEND_REGS_RSSI_CTRL3_DEFAULT                                                 0x31DF126
#define FRONTEND_REGS_RSSI_CTRL3_CTL_RSSI_LUT6                                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8)
#define FRONTEND_REGS_RSSI_CTRL3_CTL_RSSI_LUT6_MASK                                      (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RSSI_CTRL3_CTL_RSSI_LUT6_SHIFT                                     (0)
#define FRONTEND_REGS_RSSI_CTRL3_CTL_RSSI_LUT7                                           (Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define FRONTEND_REGS_RSSI_CTRL3_CTL_RSSI_LUT7_MASK                                      (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RSSI_CTRL3_CTL_RSSI_LUT7_SHIFT                                     (9)
#define FRONTEND_REGS_RSSI_CTRL3_CTL_RSSI_LUT8                                           (Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26)
#define FRONTEND_REGS_RSSI_CTRL3_CTL_RSSI_LUT8_MASK                                      (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RSSI_CTRL3_CTL_RSSI_LUT8_SHIFT                                     (18)


#define FRONTEND_REGS_RSSI_STAT0                                                         (FRONTEND_REGS_BASE + 0x90)
#define FRONTEND_REGS_RSSI_STAT0_DEFAULT                                                 0x0
#define FRONTEND_REGS_RSSI_STAT0_CTL_RSSI_FREEZE                                         (Bit0)
#define FRONTEND_REGS_RSSI_STAT0_STS_RSSI                                                (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define FRONTEND_REGS_RSSI_STAT0_STS_RSSI_MASK                                           (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RSSI_STAT0_STS_RSSI_SHIFT                                          (4)


#define FRONTEND_REGS_RX_CIC_SNAP                                                        (FRONTEND_REGS_BASE + 0xc0)
#define FRONTEND_REGS_RX_CIC_SNAP_DEFAULT                                                0x0
#define FRONTEND_REGS_RX_CIC_SNAP_STS_RX_CIC_SNAP_I                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8)
#define FRONTEND_REGS_RX_CIC_SNAP_STS_RX_CIC_SNAP_I_MASK                                 (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_CIC_SNAP_STS_RX_CIC_SNAP_I_SHIFT                                (0)
#define FRONTEND_REGS_RX_CIC_SNAP_STS_RX_CIC_SNAP_Q                                      (Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define FRONTEND_REGS_RX_CIC_SNAP_STS_RX_CIC_SNAP_Q_MASK                                 (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_RX_CIC_SNAP_STS_RX_CIC_SNAP_Q_SHIFT                                (9)


#define FRONTEND_REGS_DPU_CTRL0                                                          (FRONTEND_REGS_BASE + 0xe0)
#define FRONTEND_REGS_DPU_CTRL0_DEFAULT                                                  0xA000
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_RX_EN                                            (Bit0)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_TX_EN                                            (Bit1)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_MEM_REG_EN                                       (Bit2)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_REG_TRIG                                         (Bit3)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_TRIG_SOURCE                                      (Bit4+Bit5+Bit6)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_TRIG_SOURCE_MASK                                 (Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_TRIG_SOURCE_SHIFT                                (4)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_CAPTURE_SEL                                      (Bit8+Bit9)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_CAPTURE_SEL_MASK                                 (Bit1+Bit0)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_CAPTURE_SEL_SHIFT                                (8)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_TX_STOP                                          (Bit10)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_CAPTURE_ACK                                      (Bit11)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_POST_TRIG                                        (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_POST_TRIG_MASK                                   (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_POST_TRIG_SHIFT                                  (12)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_CAP_MSB_PER                                      (Bit28+Bit29)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_CAP_MSB_PER_MASK                                 (Bit1+Bit0)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_CAP_MSB_PER_SHIFT                                (28)
#define FRONTEND_REGS_DPU_CTRL0_CTL_DPU_PB_EN                                            (Bit30)


#define FRONTEND_REGS_DPU_MEM_ADDR                                                       (FRONTEND_REGS_BASE + 0xe4)
#define FRONTEND_REGS_DPU_MEM_ADDR_DEFAULT                                               0x0
#define FRONTEND_REGS_DPU_MEM_ADDR_CTL_DPU_MEM_ADDR                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define FRONTEND_REGS_DPU_MEM_ADDR_CTL_DPU_MEM_ADDR_MASK                                 (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_MEM_ADDR_CTL_DPU_MEM_ADDR_SHIFT                                (0)


#define FRONTEND_REGS_DPU_MEM_ADDR_STAT0                                                 (FRONTEND_REGS_BASE + 0xe8)
#define FRONTEND_REGS_DPU_MEM_ADDR_STAT0_DEFAULT                                         0x0
#define FRONTEND_REGS_DPU_MEM_ADDR_STAT0_STS_DPU_MEM_ADDR                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define FRONTEND_REGS_DPU_MEM_ADDR_STAT0_STS_DPU_MEM_ADDR_MASK                           (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_MEM_ADDR_STAT0_STS_DPU_MEM_ADDR_SHIFT                          (0)


#define FRONTEND_REGS_DPU_MEM_WDATA                                                      (FRONTEND_REGS_BASE + 0xec)
#define FRONTEND_REGS_DPU_MEM_WDATA_DEFAULT                                              0x0
#define FRONTEND_REGS_DPU_MEM_WDATA_CTL_DPU_MEM_WDATA                                    (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_DPU_MEM_WDATA_CTL_DPU_MEM_WDATA_MASK                               (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_MEM_WDATA_CTL_DPU_MEM_WDATA_SHIFT                              (0)


#define FRONTEND_REGS_DPU_MEM_RDATA                                                      (FRONTEND_REGS_BASE + 0xf0)
#define FRONTEND_REGS_DPU_MEM_RDATA_DEFAULT                                              0x0
#define FRONTEND_REGS_DPU_MEM_RDATA_STS_DPU_MEM_RDATA                                    (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_DPU_MEM_RDATA_STS_DPU_MEM_RDATA_MASK                               (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_MEM_RDATA_STS_DPU_MEM_RDATA_SHIFT                              (0)


#define FRONTEND_REGS_DPU_CTRL1                                                          (FRONTEND_REGS_BASE + 0xf4)
#define FRONTEND_REGS_DPU_CTRL1_DEFAULT                                                  0x0
#define FRONTEND_REGS_DPU_CTRL1_CTLQ_DPU_MEM_START_ADDR                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define FRONTEND_REGS_DPU_CTRL1_CTLQ_DPU_MEM_START_ADDR_MASK                             (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_CTRL1_CTLQ_DPU_MEM_START_ADDR_SHIFT                            (0)


#define FRONTEND_REGS_DPU_CTRL2                                                          (FRONTEND_REGS_BASE + 0xf8)
#define FRONTEND_REGS_DPU_CTRL2_DEFAULT                                                  0x3FFF
#define FRONTEND_REGS_DPU_CTRL2_CTLQ_DPU_MEM_LAST_ADDR                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define FRONTEND_REGS_DPU_CTRL2_CTLQ_DPU_MEM_LAST_ADDR_MASK                              (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_CTRL2_CTLQ_DPU_MEM_LAST_ADDR_SHIFT                             (0)


#define FRONTEND_REGS_DPU_STAT0                                                          (FRONTEND_REGS_BASE + 0xfc)
#define FRONTEND_REGS_DPU_STAT0_DEFAULT                                                  0x0
#define FRONTEND_REGS_DPU_STAT0_STS_DPU_RX_STATE                                         (Bit0+Bit1)
#define FRONTEND_REGS_DPU_STAT0_STS_DPU_RX_STATE_MASK                                    (Bit1+Bit0)
#define FRONTEND_REGS_DPU_STAT0_STS_DPU_RX_STATE_SHIFT                                   (0)
#define FRONTEND_REGS_DPU_STAT0_STS_DPU_TX_STATE                                         (Bit4+Bit5)
#define FRONTEND_REGS_DPU_STAT0_STS_DPU_TX_STATE_MASK                                    (Bit1+Bit0)
#define FRONTEND_REGS_DPU_STAT0_STS_DPU_TX_STATE_SHIFT                                   (4)
#define FRONTEND_REGS_DPU_STAT0_STS_DPU_CAP_ADDR                                         (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define FRONTEND_REGS_DPU_STAT0_STS_DPU_CAP_ADDR_MASK                                    (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_STAT0_STS_DPU_CAP_ADDR_SHIFT                                   (8)
#define FRONTEND_REGS_DPU_STAT0_STS_DPU_CAP_WRAP                                         (Bit24)


#define FRONTEND_REGS_DPU_AFIFO_CTRL0                                                    (FRONTEND_REGS_BASE + 0x104)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_DEFAULT                                            0x1
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_CTLQ_DPU_ADC_FIFO_RD_EMPTY_DEL                     (Bit0+Bit1)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_CTLQ_DPU_ADC_FIFO_RD_EMPTY_DEL_MASK                (Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_CTLQ_DPU_ADC_FIFO_RD_EMPTY_DEL_SHIFT               (0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_CTLT_DPU_ADC_FIFO_SNAP                             (Bit2)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_CTLT_DPU_ADC_FIFO_CLEAR_FLOW                       (Bit3)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_WR_PNT_RCK                        (Bit4+Bit5+Bit6+Bit7)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_WR_PNT_RCK_MASK                   (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_WR_PNT_RCK_SHIFT                  (4)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_RD_PNT_RCK                        (Bit8+Bit9+Bit10+Bit11)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_RD_PNT_RCK_MASK                   (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_RD_PNT_RCK_SHIFT                  (8)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_WR_PNT_WCK                        (Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_WR_PNT_WCK_MASK                   (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_WR_PNT_WCK_SHIFT                  (12)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_RD_PNT_WCK                        (Bit16+Bit17+Bit18+Bit19)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_RD_PNT_WCK_MASK                   (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_RD_PNT_WCK_SHIFT                  (16)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_FILL_RCK                          (Bit20+Bit21+Bit22+Bit23)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_FILL_RCK_MASK                     (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_FILL_RCK_SHIFT                    (20)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_OVERFLOW                          (Bit24)
#define FRONTEND_REGS_DPU_AFIFO_CTRL0_STS_DPU_ADC_FIFO_UNDERFLOW                         (Bit25)


#define FRONTEND_REGS_DPU_AFIFO_CTRL1                                                    (FRONTEND_REGS_BASE + 0x108)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_DEFAULT                                            0x1
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_CTLQ_DPU_RX_FIFO_RD_EMPTY_DEL                      (Bit0+Bit1)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_CTLQ_DPU_RX_FIFO_RD_EMPTY_DEL_MASK                 (Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_CTLQ_DPU_RX_FIFO_RD_EMPTY_DEL_SHIFT                (0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_CTLT_DPU_RX_FIFO_SNAP                              (Bit2)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_CTLT_DPU_RX_FIFO_CLEAR_FLOW                        (Bit3)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_WR_PNT_RCK                         (Bit4+Bit5+Bit6+Bit7)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_WR_PNT_RCK_MASK                    (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_WR_PNT_RCK_SHIFT                   (4)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_RD_PNT_RCK                         (Bit8+Bit9+Bit10+Bit11)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_RD_PNT_RCK_MASK                    (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_RD_PNT_RCK_SHIFT                   (8)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_WR_PNT_WCK                         (Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_WR_PNT_WCK_MASK                    (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_WR_PNT_WCK_SHIFT                   (12)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_RD_PNT_WCK                         (Bit16+Bit17+Bit18+Bit19)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_RD_PNT_WCK_MASK                    (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_RD_PNT_WCK_SHIFT                   (16)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_FILL_RCK                           (Bit20+Bit21+Bit22+Bit23)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_FILL_RCK_MASK                      (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_FILL_RCK_SHIFT                     (20)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_OVERFLOW                           (Bit24)
#define FRONTEND_REGS_DPU_AFIFO_CTRL1_STS_DPU_RX_FIFO_UNDERFLOW                          (Bit25)


#define FRONTEND_REGS_DPU_AFIFO_CTRL2                                                    (FRONTEND_REGS_BASE + 0x10c)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_DEFAULT                                            0xC000001
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_CTLQ_DPU_DAC_FIFO_RD_EMPTY_DEL                     (Bit0+Bit1)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_CTLQ_DPU_DAC_FIFO_RD_EMPTY_DEL_MASK                (Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_CTLQ_DPU_DAC_FIFO_RD_EMPTY_DEL_SHIFT               (0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_CTLT_DPU_DAC_FIFO_SNAP                             (Bit2)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_CTLT_DPU_DAC_FIFO_CLEAR_FLOW                       (Bit3)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_WR_PNT_RCK                        (Bit4+Bit5+Bit6+Bit7)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_WR_PNT_RCK_MASK                   (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_WR_PNT_RCK_SHIFT                  (4)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_RD_PNT_RCK                        (Bit8+Bit9+Bit10+Bit11)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_RD_PNT_RCK_MASK                   (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_RD_PNT_RCK_SHIFT                  (8)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_WR_PNT_WCK                        (Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_WR_PNT_WCK_MASK                   (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_WR_PNT_WCK_SHIFT                  (12)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_RD_PNT_WCK                        (Bit16+Bit17+Bit18+Bit19)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_RD_PNT_WCK_MASK                   (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_RD_PNT_WCK_SHIFT                  (16)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_FILL_RCK                          (Bit20+Bit21+Bit22+Bit23)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_FILL_RCK_MASK                     (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_FILL_RCK_SHIFT                    (20)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_OVERFLOW                          (Bit24)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_STS_DPU_DAC_FIFO_UNDERFLOW                         (Bit25)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_CTLQ_DPU_DAC_FILL_START                            (Bit26+Bit27+Bit28)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_CTLQ_DPU_DAC_FILL_START_MASK                       (Bit2+Bit1+Bit0)
#define FRONTEND_REGS_DPU_AFIFO_CTRL2_CTLQ_DPU_DAC_FILL_START_SHIFT                      (26)


#define FRONTEND_REGS_FPGA                                                               (FRONTEND_REGS_BASE + 0x140)
#define FRONTEND_REGS_FPGA_DEFAULT                                                       0x7
#define FRONTEND_REGS_FPGA_CTLQ_FPGA_RW_INPLAY_SEL                                       (Bit0)
#define FRONTEND_REGS_FPGA_CTLQ_FPGA_SEL_DAC                                             (Bit1)
#define FRONTEND_REGS_FPGA_CTLQ_FPGA_TX_RATE                                             (Bit2)


#define FRONTEND_REGS_ANTENNA_MISC_CTRL                                                  (FRONTEND_REGS_BASE + 0x180)
#define FRONTEND_REGS_ANTENNA_MISC_CTRL_DEFAULT                                          0x0
#define FRONTEND_REGS_ANTENNA_MISC_CTRL_CTL_ANTENNA_RX_CTL_EN                            (Bit0)
#define FRONTEND_REGS_ANTENNA_MISC_CTRL_CTL_ANTENNA_TX_CTL_EN                            (Bit1)
#define FRONTEND_REGS_ANTENNA_MISC_CTRL_CTL_DEFAULT_ANTENNA                              (Bit4+Bit5+Bit6+Bit7)
#define FRONTEND_REGS_ANTENNA_MISC_CTRL_CTL_DEFAULT_ANTENNA_MASK                         (Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_MISC_CTRL_CTL_DEFAULT_ANTENNA_SHIFT                        (4)
#define FRONTEND_REGS_ANTENNA_MISC_CTRL_CTL_ANTENNA_EN                                   (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_MISC_CTRL_CTL_ANTENNA_EN_MASK                              (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_MISC_CTRL_CTL_ANTENNA_EN_SHIFT                             (16)


#define FRONTEND_REGS_ANTENNA_0_START_END_TIME                                           (FRONTEND_REGS_BASE + 0x190)
#define FRONTEND_REGS_ANTENNA_0_START_END_TIME_DEFAULT                                   0x0
#define FRONTEND_REGS_ANTENNA_0_START_END_TIME_START_TIME                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_ANTENNA_0_START_END_TIME_START_TIME_MASK                           (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_0_START_END_TIME_START_TIME_SHIFT                          (0)
#define FRONTEND_REGS_ANTENNA_0_START_END_TIME_END_TIME                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_0_START_END_TIME_END_TIME_MASK                             (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_0_START_END_TIME_END_TIME_SHIFT                            (16)


#define FRONTEND_REGS_ANTENNA_1_START_END_TIME                                           (FRONTEND_REGS_BASE + 0x194)
#define FRONTEND_REGS_ANTENNA_1_START_END_TIME_DEFAULT                                   0x0
#define FRONTEND_REGS_ANTENNA_1_START_END_TIME_START_TIME                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_ANTENNA_1_START_END_TIME_START_TIME_MASK                           (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_1_START_END_TIME_START_TIME_SHIFT                          (0)
#define FRONTEND_REGS_ANTENNA_1_START_END_TIME_END_TIME                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_1_START_END_TIME_END_TIME_MASK                             (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_1_START_END_TIME_END_TIME_SHIFT                            (16)


#define FRONTEND_REGS_ANTENNA_2_START_END_TIME                                           (FRONTEND_REGS_BASE + 0x198)
#define FRONTEND_REGS_ANTENNA_2_START_END_TIME_DEFAULT                                   0x0
#define FRONTEND_REGS_ANTENNA_2_START_END_TIME_START_TIME                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_ANTENNA_2_START_END_TIME_START_TIME_MASK                           (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_2_START_END_TIME_START_TIME_SHIFT                          (0)
#define FRONTEND_REGS_ANTENNA_2_START_END_TIME_END_TIME                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_2_START_END_TIME_END_TIME_MASK                             (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_2_START_END_TIME_END_TIME_SHIFT                            (16)


#define FRONTEND_REGS_ANTENNA_3_START_END_TIME                                           (FRONTEND_REGS_BASE + 0x19c)
#define FRONTEND_REGS_ANTENNA_3_START_END_TIME_DEFAULT                                   0x0
#define FRONTEND_REGS_ANTENNA_3_START_END_TIME_START_TIME                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_ANTENNA_3_START_END_TIME_START_TIME_MASK                           (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_3_START_END_TIME_START_TIME_SHIFT                          (0)
#define FRONTEND_REGS_ANTENNA_3_START_END_TIME_END_TIME                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_3_START_END_TIME_END_TIME_MASK                             (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_3_START_END_TIME_END_TIME_SHIFT                            (16)


#define FRONTEND_REGS_ANTENNA_4_START_END_TIME                                           (FRONTEND_REGS_BASE + 0x1a0)
#define FRONTEND_REGS_ANTENNA_4_START_END_TIME_DEFAULT                                   0x0
#define FRONTEND_REGS_ANTENNA_4_START_END_TIME_START_TIME                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_ANTENNA_4_START_END_TIME_START_TIME_MASK                           (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_4_START_END_TIME_START_TIME_SHIFT                          (0)
#define FRONTEND_REGS_ANTENNA_4_START_END_TIME_END_TIME                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_4_START_END_TIME_END_TIME_MASK                             (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_4_START_END_TIME_END_TIME_SHIFT                            (16)


#define FRONTEND_REGS_ANTENNA_5_START_END_TIME                                           (FRONTEND_REGS_BASE + 0x1a4)
#define FRONTEND_REGS_ANTENNA_5_START_END_TIME_DEFAULT                                   0x0
#define FRONTEND_REGS_ANTENNA_5_START_END_TIME_START_TIME                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_ANTENNA_5_START_END_TIME_START_TIME_MASK                           (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_5_START_END_TIME_START_TIME_SHIFT                          (0)
#define FRONTEND_REGS_ANTENNA_5_START_END_TIME_END_TIME                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_5_START_END_TIME_END_TIME_MASK                             (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_5_START_END_TIME_END_TIME_SHIFT                            (16)


#define FRONTEND_REGS_ANTENNA_6_START_END_TIME                                           (FRONTEND_REGS_BASE + 0x1a8)
#define FRONTEND_REGS_ANTENNA_6_START_END_TIME_DEFAULT                                   0x0
#define FRONTEND_REGS_ANTENNA_6_START_END_TIME_START_TIME                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_ANTENNA_6_START_END_TIME_START_TIME_MASK                           (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_6_START_END_TIME_START_TIME_SHIFT                          (0)
#define FRONTEND_REGS_ANTENNA_6_START_END_TIME_END_TIME                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_6_START_END_TIME_END_TIME_MASK                             (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_6_START_END_TIME_END_TIME_SHIFT                            (16)


#define FRONTEND_REGS_ANTENNA_7_START_END_TIME                                           (FRONTEND_REGS_BASE + 0x1ac)
#define FRONTEND_REGS_ANTENNA_7_START_END_TIME_DEFAULT                                   0x0
#define FRONTEND_REGS_ANTENNA_7_START_END_TIME_START_TIME                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_ANTENNA_7_START_END_TIME_START_TIME_MASK                           (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_7_START_END_TIME_START_TIME_SHIFT                          (0)
#define FRONTEND_REGS_ANTENNA_7_START_END_TIME_END_TIME                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_7_START_END_TIME_END_TIME_MASK                             (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_7_START_END_TIME_END_TIME_SHIFT                            (16)


#define FRONTEND_REGS_ANTENNA_8_START_END_TIME                                           (FRONTEND_REGS_BASE + 0x1b0)
#define FRONTEND_REGS_ANTENNA_8_START_END_TIME_DEFAULT                                   0x0
#define FRONTEND_REGS_ANTENNA_8_START_END_TIME_START_TIME                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_ANTENNA_8_START_END_TIME_START_TIME_MASK                           (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_8_START_END_TIME_START_TIME_SHIFT                          (0)
#define FRONTEND_REGS_ANTENNA_8_START_END_TIME_END_TIME                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_8_START_END_TIME_END_TIME_MASK                             (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_8_START_END_TIME_END_TIME_SHIFT                            (16)


#define FRONTEND_REGS_ANTENNA_9_START_END_TIME                                           (FRONTEND_REGS_BASE + 0x1b4)
#define FRONTEND_REGS_ANTENNA_9_START_END_TIME_DEFAULT                                   0x0
#define FRONTEND_REGS_ANTENNA_9_START_END_TIME_START_TIME                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_ANTENNA_9_START_END_TIME_START_TIME_MASK                           (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_9_START_END_TIME_START_TIME_SHIFT                          (0)
#define FRONTEND_REGS_ANTENNA_9_START_END_TIME_END_TIME                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_9_START_END_TIME_END_TIME_MASK                             (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_9_START_END_TIME_END_TIME_SHIFT                            (16)


#define FRONTEND_REGS_ANTENNA_10_START_END_TIME                                          (FRONTEND_REGS_BASE + 0x1b8)
#define FRONTEND_REGS_ANTENNA_10_START_END_TIME_DEFAULT                                  0x0
#define FRONTEND_REGS_ANTENNA_10_START_END_TIME_START_TIME                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_ANTENNA_10_START_END_TIME_START_TIME_MASK                          (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_10_START_END_TIME_START_TIME_SHIFT                         (0)
#define FRONTEND_REGS_ANTENNA_10_START_END_TIME_END_TIME                                 (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_10_START_END_TIME_END_TIME_MASK                            (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_10_START_END_TIME_END_TIME_SHIFT                           (16)


#define FRONTEND_REGS_ANTENNA_11_START_END_TIME                                          (FRONTEND_REGS_BASE + 0x1bc)
#define FRONTEND_REGS_ANTENNA_11_START_END_TIME_DEFAULT                                  0x0
#define FRONTEND_REGS_ANTENNA_11_START_END_TIME_START_TIME                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_ANTENNA_11_START_END_TIME_START_TIME_MASK                          (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_11_START_END_TIME_START_TIME_SHIFT                         (0)
#define FRONTEND_REGS_ANTENNA_11_START_END_TIME_END_TIME                                 (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_11_START_END_TIME_END_TIME_MASK                            (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_11_START_END_TIME_END_TIME_SHIFT                           (16)


#define FRONTEND_REGS_ANTENNA_12_START_END_TIME                                          (FRONTEND_REGS_BASE + 0x1c0)
#define FRONTEND_REGS_ANTENNA_12_START_END_TIME_DEFAULT                                  0x0
#define FRONTEND_REGS_ANTENNA_12_START_END_TIME_START_TIME                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_ANTENNA_12_START_END_TIME_START_TIME_MASK                          (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_12_START_END_TIME_START_TIME_SHIFT                         (0)
#define FRONTEND_REGS_ANTENNA_12_START_END_TIME_END_TIME                                 (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_12_START_END_TIME_END_TIME_MASK                            (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_12_START_END_TIME_END_TIME_SHIFT                           (16)


#define FRONTEND_REGS_ANTENNA_13_START_END_TIME                                          (FRONTEND_REGS_BASE + 0x1c4)
#define FRONTEND_REGS_ANTENNA_13_START_END_TIME_DEFAULT                                  0x0
#define FRONTEND_REGS_ANTENNA_13_START_END_TIME_START_TIME                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_ANTENNA_13_START_END_TIME_START_TIME_MASK                          (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_13_START_END_TIME_START_TIME_SHIFT                         (0)
#define FRONTEND_REGS_ANTENNA_13_START_END_TIME_END_TIME                                 (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_13_START_END_TIME_END_TIME_MASK                            (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_13_START_END_TIME_END_TIME_SHIFT                           (16)


#define FRONTEND_REGS_ANTENNA_14_START_END_TIME                                          (FRONTEND_REGS_BASE + 0x1c8)
#define FRONTEND_REGS_ANTENNA_14_START_END_TIME_DEFAULT                                  0x0
#define FRONTEND_REGS_ANTENNA_14_START_END_TIME_START_TIME                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_ANTENNA_14_START_END_TIME_START_TIME_MASK                          (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_14_START_END_TIME_START_TIME_SHIFT                         (0)
#define FRONTEND_REGS_ANTENNA_14_START_END_TIME_END_TIME                                 (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_14_START_END_TIME_END_TIME_MASK                            (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_14_START_END_TIME_END_TIME_SHIFT                           (16)


#define FRONTEND_REGS_ANTENNA_15_START_END_TIME                                          (FRONTEND_REGS_BASE + 0x1cc)
#define FRONTEND_REGS_ANTENNA_15_START_END_TIME_DEFAULT                                  0x0
#define FRONTEND_REGS_ANTENNA_15_START_END_TIME_START_TIME                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FRONTEND_REGS_ANTENNA_15_START_END_TIME_START_TIME_MASK                          (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_15_START_END_TIME_START_TIME_SHIFT                         (0)
#define FRONTEND_REGS_ANTENNA_15_START_END_TIME_END_TIME                                 (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_15_START_END_TIME_END_TIME_MASK                            (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_15_START_END_TIME_END_TIME_SHIFT                           (16)


#define FRONTEND_REGS_ANTENNA_SHM_ADDR_UPPER_LMT                                         (FRONTEND_REGS_BASE + 0x1e0)
#define FRONTEND_REGS_ANTENNA_SHM_ADDR_UPPER_LMT_DEFAULT                                 0x7FFF
#define FRONTEND_REGS_ANTENNA_SHM_ADDR_UPPER_LMT_CTL_SHM_ADDR_LMT                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define FRONTEND_REGS_ANTENNA_SHM_ADDR_UPPER_LMT_CTL_SHM_ADDR_LMT_MASK                   (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_SHM_ADDR_UPPER_LMT_CTL_SHM_ADDR_LMT_SHIFT                  (0)
#define FRONTEND_REGS_ANTENNA_SHM_ADDR_UPPER_LMT_CTL_RX_DATA_RD_ADDR                     (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30)
#define FRONTEND_REGS_ANTENNA_SHM_ADDR_UPPER_LMT_CTL_RX_DATA_RD_ADDR_MASK                (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_SHM_ADDR_UPPER_LMT_CTL_RX_DATA_RD_ADDR_SHIFT               (16)


#define FRONTEND_REGS_ANTENNA_RX_NUM_DATA                                                (FRONTEND_REGS_BASE + 0x1e8)
#define FRONTEND_REGS_ANTENNA_RX_NUM_DATA_DEFAULT                                        0x0
#define FRONTEND_REGS_ANTENNA_RX_NUM_DATA_STS_RX_NUM_DATA                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define FRONTEND_REGS_ANTENNA_RX_NUM_DATA_STS_RX_NUM_DATA_MASK                           (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_RX_NUM_DATA_STS_RX_NUM_DATA_SHIFT                          (0)
#define FRONTEND_REGS_ANTENNA_RX_NUM_DATA_STS_RX_DATA_CURR_ADDR                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30)
#define FRONTEND_REGS_ANTENNA_RX_NUM_DATA_STS_RX_DATA_CURR_ADDR_MASK                     (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_RX_NUM_DATA_STS_RX_DATA_CURR_ADDR_SHIFT                    (16)
#define FRONTEND_REGS_ANTENNA_RX_NUM_DATA_STS_RX_DATA_RDY                                (Bit31)


#define FRONTEND_REGS_ANTENNA_RX_DATA                                                    (FRONTEND_REGS_BASE + 0x1f0)
#define FRONTEND_REGS_ANTENNA_RX_DATA_DEFAULT                                            0x0
#define FRONTEND_REGS_ANTENNA_RX_DATA_STS_RX_DATA                                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FRONTEND_REGS_ANTENNA_RX_DATA_STS_RX_DATA_MASK                                   (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FRONTEND_REGS_ANTENNA_RX_DATA_STS_RX_DATA_SHIFT                                  (0)


#endif // _FRONTEND_REGS_DEFINES_H

