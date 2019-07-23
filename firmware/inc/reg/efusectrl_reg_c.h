#ifndef _EFUSECTRL_REG_DEFINES_H
#define _EFUSECTRL_REG_DEFINES_H
/* **************************** */
#define EFUSECTRL_REG_INTR_STATUS                                                          (EFUSECTRL_REG_BASE + 0x0)
#define EFUSECTRL_REG_INTR_STATUS_DEFAULT                                                  0x0
#define EFUSECTRL_REG_INTR_STATUS_READ_DONE_0                                              (Bit0)
#define EFUSECTRL_REG_INTR_STATUS_PROG_DONE_0                                              (Bit1)
#define EFUSECTRL_REG_INTR_STATUS_PROG_BLOCKED_0                                           (Bit2)
#define EFUSECTRL_REG_INTR_STATUS_READ_DONE_1                                              (Bit3)
#define EFUSECTRL_REG_INTR_STATUS_PROG_DONE_1                                              (Bit4)
#define EFUSECTRL_REG_INTR_STATUS_PROG_BLOCKED_1                                           (Bit5)


#define EFUSECTRL_REG_INTR_MASK_STATUS                                                     (EFUSECTRL_REG_BASE + 0x4)
#define EFUSECTRL_REG_INTR_MASK_STATUS_DEFAULT                                             0x0
#define EFUSECTRL_REG_INTR_MASK_STATUS_READ_DONE_0                                         (Bit0)
#define EFUSECTRL_REG_INTR_MASK_STATUS_PROG_DONE_0                                         (Bit1)
#define EFUSECTRL_REG_INTR_MASK_STATUS_PROG_BLOCKED_0                                      (Bit2)
#define EFUSECTRL_REG_INTR_MASK_STATUS_READ_DONE_1                                         (Bit3)
#define EFUSECTRL_REG_INTR_MASK_STATUS_PROG_DONE_1                                         (Bit4)
#define EFUSECTRL_REG_INTR_MASK_STATUS_PROG_BLOCKED_1                                      (Bit5)


#define EFUSECTRL_REG_INTR_CLR                                                             (EFUSECTRL_REG_BASE + 0x8)
#define EFUSECTRL_REG_INTR_CLR_DEFAULT                                                     0x0
#define EFUSECTRL_REG_INTR_CLR_READ_DONE_0                                                 (Bit0)
#define EFUSECTRL_REG_INTR_CLR_PROG_DONE_0                                                 (Bit1)
#define EFUSECTRL_REG_INTR_CLR_PROG_BLOCKED_0                                              (Bit2)
#define EFUSECTRL_REG_INTR_CLR_READ_DONE_1                                                 (Bit3)
#define EFUSECTRL_REG_INTR_CLR_PROG_DONE_1                                                 (Bit4)
#define EFUSECTRL_REG_INTR_CLR_PROG_BLOCKED_1                                              (Bit5)


#define EFUSECTRL_REG_INTR_SET                                                             (EFUSECTRL_REG_BASE + 0xc)
#define EFUSECTRL_REG_INTR_SET_DEFAULT                                                     0x0
#define EFUSECTRL_REG_INTR_SET_READ_DONE_0                                                 (Bit0)
#define EFUSECTRL_REG_INTR_SET_PROG_DONE_0                                                 (Bit1)
#define EFUSECTRL_REG_INTR_SET_PROG_BLOCKED_0                                              (Bit2)
#define EFUSECTRL_REG_INTR_SET_READ_DONE_1                                                 (Bit3)
#define EFUSECTRL_REG_INTR_SET_PROG_DONE_1                                                 (Bit4)
#define EFUSECTRL_REG_INTR_SET_PROG_BLOCKED_1                                              (Bit5)


#define EFUSECTRL_REG_INTR_MASK_SET                                                        (EFUSECTRL_REG_BASE + 0x10)
#define EFUSECTRL_REG_INTR_MASK_SET_DEFAULT                                                0x0
#define EFUSECTRL_REG_INTR_MASK_SET_READ_DONE_0                                            (Bit0)
#define EFUSECTRL_REG_INTR_MASK_SET_PROG_DONE_0                                            (Bit1)
#define EFUSECTRL_REG_INTR_MASK_SET_PROG_BLOCKED_0                                         (Bit2)
#define EFUSECTRL_REG_INTR_MASK_SET_READ_DONE_1                                            (Bit3)
#define EFUSECTRL_REG_INTR_MASK_SET_PROG_DONE_1                                            (Bit4)
#define EFUSECTRL_REG_INTR_MASK_SET_PROG_BLOCKED_1                                         (Bit5)


#define EFUSECTRL_REG_INTR_MASK_CLR                                                        (EFUSECTRL_REG_BASE + 0x14)
#define EFUSECTRL_REG_INTR_MASK_CLR_DEFAULT                                                0x0
#define EFUSECTRL_REG_INTR_MASK_CLR_READ_DONE_0                                            (Bit0)
#define EFUSECTRL_REG_INTR_MASK_CLR_PROG_DONE_0                                            (Bit1)
#define EFUSECTRL_REG_INTR_MASK_CLR_PROG_BLOCKED_0                                         (Bit2)
#define EFUSECTRL_REG_INTR_MASK_CLR_READ_DONE_1                                            (Bit3)
#define EFUSECTRL_REG_INTR_MASK_CLR_PROG_DONE_1                                            (Bit4)
#define EFUSECTRL_REG_INTR_MASK_CLR_PROG_BLOCKED_1                                         (Bit5)


#define EFUSECTRL_REG_MISC_CTRL_0                                                          (EFUSECTRL_REG_BASE + 0x20)
#define EFUSECTRL_REG_MISC_CTRL_0_DEFAULT                                                  0x0
#define EFUSECTRL_REG_MISC_CTRL_0_CTL_EFUSE_EN_0                                           (Bit0)
#define EFUSECTRL_REG_MISC_CTRL_0_CTL_EFUSE_INTR_CLR_0                                     (Bit1)
#define EFUSECTRL_REG_MISC_CTRL_0_CTL_EFUSE_PROG_EN_0                                      (Bit4)


#define EFUSECTRL_REG_MISC_STS_0                                                           (EFUSECTRL_REG_BASE + 0x28)
#define EFUSECTRL_REG_MISC_STS_0_DEFAULT                                                   0x0
#define EFUSECTRL_REG_MISC_STS_0_STS_EFUSE_PROG_BLK_0                                      (Bit0)
#define EFUSECTRL_REG_MISC_STS_0_STS_EFUSE_INIT_RD_BYP_0                                   (Bit20)
#define EFUSECTRL_REG_MISC_STS_0_STS_EFUSE_CURR_STATE_0                                    (Bit24+Bit25+Bit26+Bit27)
#define EFUSECTRL_REG_MISC_STS_0_STS_EFUSE_CURR_STATE_0_MASK                               (Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_MISC_STS_0_STS_EFUSE_CURR_STATE_0_SHIFT                              (24)


#define EFUSECTRL_REG_INIT_RD_VALUE_0_0                                                    (EFUSECTRL_REG_BASE + 0x30)
#define EFUSECTRL_REG_INIT_RD_VALUE_0_0_DEFAULT                                            0x0
#define EFUSECTRL_REG_INIT_RD_VALUE_0_0_STS_EFUSE_INIT_RD_VAL_0_0                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define EFUSECTRL_REG_INIT_RD_VALUE_0_0_STS_EFUSE_INIT_RD_VAL_0_0_MASK                     (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_INIT_RD_VALUE_0_0_STS_EFUSE_INIT_RD_VAL_0_0_SHIFT                    (0)


#define EFUSECTRL_REG_INIT_RD_VALUE_0_1                                                    (EFUSECTRL_REG_BASE + 0x34)
#define EFUSECTRL_REG_INIT_RD_VALUE_0_1_DEFAULT                                            0x0
#define EFUSECTRL_REG_INIT_RD_VALUE_0_1_STS_EFUSE_INIT_RD_VAL_0_1                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define EFUSECTRL_REG_INIT_RD_VALUE_0_1_STS_EFUSE_INIT_RD_VAL_0_1_MASK                     (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_INIT_RD_VALUE_0_1_STS_EFUSE_INIT_RD_VAL_0_1_SHIFT                    (0)


#define EFUSECTRL_REG_READ_CTRL_0                                                          (EFUSECTRL_REG_BASE + 0x40)
#define EFUSECTRL_REG_READ_CTRL_0_DEFAULT                                                  0x0
#define EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_REQ_0                                     (Bit0)
#define EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_ADDR_0                                    (Bit4+Bit5+Bit6+Bit7+Bit8)
#define EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_ADDR_0_MASK                               (Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_ADDR_0_SHIFT                              (4)
#define EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_EFUSE_SEL_0                               (Bit12+Bit13)
#define EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_EFUSE_SEL_0_MASK                          (Bit1+Bit0)
#define EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_EFUSE_SEL_0_SHIFT                         (12)
#define EFUSECTRL_REG_READ_CTRL_0_CTL_EFUSE_READ_MODE_0                                    (Bit16)


#define EFUSECTRL_REG_READ_VAL_0                                                           (EFUSECTRL_REG_BASE + 0x44)
#define EFUSECTRL_REG_READ_VAL_0_DEFAULT                                                   0x0
#define EFUSECTRL_REG_READ_VAL_0_STS_EFUSE_READ_VAL_0                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define EFUSECTRL_REG_READ_VAL_0_STS_EFUSE_READ_VAL_0_MASK                                 (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_READ_VAL_0_STS_EFUSE_READ_VAL_0_SHIFT                                (0)


#define EFUSECTRL_REG_PROG_CTRL_0                                                          (EFUSECTRL_REG_BASE + 0x50)
#define EFUSECTRL_REG_PROG_CTRL_0_DEFAULT                                                  0x0
#define EFUSECTRL_REG_PROG_CTRL_0_CTL_EFUSE_PROG_REQ_0                                     (Bit0)
#define EFUSECTRL_REG_PROG_CTRL_0_CTL_EFUSE_PROG_BIT_ADDR_0                                (Bit4+Bit5+Bit6+Bit7)
#define EFUSECTRL_REG_PROG_CTRL_0_CTL_EFUSE_PROG_BIT_ADDR_0_MASK                           (Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_PROG_CTRL_0_CTL_EFUSE_PROG_BIT_ADDR_0_SHIFT                          (4)
#define EFUSECTRL_REG_PROG_CTRL_0_CTL_EFUSE_PROG_ADDR_0                                    (Bit8+Bit9+Bit10+Bit11+Bit12)
#define EFUSECTRL_REG_PROG_CTRL_0_CTL_EFUSE_PROG_ADDR_0_MASK                               (Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_PROG_CTRL_0_CTL_EFUSE_PROG_ADDR_0_SHIFT                              (8)
#define EFUSECTRL_REG_PROG_CTRL_0_CTL_EFUSE_PROG_EFUSE_SEL_0                               (Bit16+Bit17)
#define EFUSECTRL_REG_PROG_CTRL_0_CTL_EFUSE_PROG_EFUSE_SEL_0_MASK                          (Bit1+Bit0)
#define EFUSECTRL_REG_PROG_CTRL_0_CTL_EFUSE_PROG_EFUSE_SEL_0_SHIFT                         (16)


#define EFUSECTRL_REG_COUNTER_CTRL_0_0                                                     (EFUSECTRL_REG_BASE + 0x60)
#define EFUSECTRL_REG_COUNTER_CTRL_0_0_DEFAULT                                             0x1004010
#define EFUSECTRL_REG_COUNTER_CTRL_0_0_CTL_EFUSE_CNT_INIT_0                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define EFUSECTRL_REG_COUNTER_CTRL_0_0_CTL_EFUSE_CNT_INIT_0_MASK                           (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_COUNTER_CTRL_0_0_CTL_EFUSE_CNT_INIT_0_SHIFT                          (0)
#define EFUSECTRL_REG_COUNTER_CTRL_0_0_CTL_EFUSE_CNT_TRDS_0                                (Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define EFUSECTRL_REG_COUNTER_CTRL_0_0_CTL_EFUSE_CNT_TRDS_0_MASK                           (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_COUNTER_CTRL_0_0_CTL_EFUSE_CNT_TRDS_0_SHIFT                          (10)
#define EFUSECTRL_REG_COUNTER_CTRL_0_0_CTL_EFUSE_CNT_TFS_0                                 (Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define EFUSECTRL_REG_COUNTER_CTRL_0_0_CTL_EFUSE_CNT_TFS_0_MASK                            (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_COUNTER_CTRL_0_0_CTL_EFUSE_CNT_TFS_0_SHIFT                           (20)


#define EFUSECTRL_REG_COUNTER_CTRL_0_1                                                     (EFUSECTRL_REG_BASE + 0x64)
#define EFUSECTRL_REG_COUNTER_CTRL_0_1_DEFAULT                                             0x1004010
#define EFUSECTRL_REG_COUNTER_CTRL_0_1_CTL_EFUSE_CNT_TPP_0                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define EFUSECTRL_REG_COUNTER_CTRL_0_1_CTL_EFUSE_CNT_TPP_0_MASK                            (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_COUNTER_CTRL_0_1_CTL_EFUSE_CNT_TPP_0_SHIFT                           (0)
#define EFUSECTRL_REG_COUNTER_CTRL_0_1_CTL_EFUSE_CNT_TEH_0                                 (Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define EFUSECTRL_REG_COUNTER_CTRL_0_1_CTL_EFUSE_CNT_TEH_0_MASK                            (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_COUNTER_CTRL_0_1_CTL_EFUSE_CNT_TEH_0_SHIFT                           (10)
#define EFUSECTRL_REG_COUNTER_CTRL_0_1_CTL_EFUSE_CNT_TESR_0                                (Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define EFUSECTRL_REG_COUNTER_CTRL_0_1_CTL_EFUSE_CNT_TESR_0_MASK                           (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_COUNTER_CTRL_0_1_CTL_EFUSE_CNT_TESR_0_SHIFT                          (20)


#define EFUSECTRL_REG_COUNTER_CTRL_0_2                                                     (EFUSECTRL_REG_BASE + 0x68)
#define EFUSECTRL_REG_COUNTER_CTRL_0_2_DEFAULT                                             0x4010
#define EFUSECTRL_REG_COUNTER_CTRL_0_2_CTL_EFUSE_CNT_TRPW_0                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define EFUSECTRL_REG_COUNTER_CTRL_0_2_CTL_EFUSE_CNT_TRPW_0_MASK                           (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_COUNTER_CTRL_0_2_CTL_EFUSE_CNT_TRPW_0_SHIFT                          (0)
#define EFUSECTRL_REG_COUNTER_CTRL_0_2_CTL_EFUSE_CNT_TRC_MOD_0                             (Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define EFUSECTRL_REG_COUNTER_CTRL_0_2_CTL_EFUSE_CNT_TRC_MOD_0_MASK                        (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_COUNTER_CTRL_0_2_CTL_EFUSE_CNT_TRC_MOD_0_SHIFT                       (10)


#define EFUSECTRL_REG_MISC_CTRL_1                                                          (EFUSECTRL_REG_BASE + 0xa0)
#define EFUSECTRL_REG_MISC_CTRL_1_DEFAULT                                                  0x0
#define EFUSECTRL_REG_MISC_CTRL_1_CTL_EFUSE_EN_1                                           (Bit0)
#define EFUSECTRL_REG_MISC_CTRL_1_CTL_EFUSE_INTR_CLR_1                                     (Bit1)
#define EFUSECTRL_REG_MISC_CTRL_1_CTL_EFUSE_PROG_EN_1                                      (Bit4)


#define EFUSECTRL_REG_MISC_STS_1                                                           (EFUSECTRL_REG_BASE + 0xa8)
#define EFUSECTRL_REG_MISC_STS_1_DEFAULT                                                   0x0
#define EFUSECTRL_REG_MISC_STS_1_STS_EFUSE_PROG_BLK_1                                      (Bit0)
#define EFUSECTRL_REG_MISC_STS_1_STS_EFUSE_INIT_RD_BYP_1                                   (Bit20)
#define EFUSECTRL_REG_MISC_STS_1_STS_EFUSE_CURR_STATE_1                                    (Bit24+Bit25+Bit26+Bit27)
#define EFUSECTRL_REG_MISC_STS_1_STS_EFUSE_CURR_STATE_1_MASK                               (Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_MISC_STS_1_STS_EFUSE_CURR_STATE_1_SHIFT                              (24)


#define EFUSECTRL_REG_INIT_RD_VALUE_1_0                                                    (EFUSECTRL_REG_BASE + 0xb0)
#define EFUSECTRL_REG_INIT_RD_VALUE_1_0_DEFAULT                                            0x0
#define EFUSECTRL_REG_INIT_RD_VALUE_1_0_STS_EFUSE_INIT_RD_VAL_1_0                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define EFUSECTRL_REG_INIT_RD_VALUE_1_0_STS_EFUSE_INIT_RD_VAL_1_0_MASK                     (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_INIT_RD_VALUE_1_0_STS_EFUSE_INIT_RD_VAL_1_0_SHIFT                    (0)


#define EFUSECTRL_REG_INIT_RD_VALUE_1_1                                                    (EFUSECTRL_REG_BASE + 0xb4)
#define EFUSECTRL_REG_INIT_RD_VALUE_1_1_DEFAULT                                            0x0
#define EFUSECTRL_REG_INIT_RD_VALUE_1_1_STS_EFUSE_INIT_RD_VAL_1_1                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define EFUSECTRL_REG_INIT_RD_VALUE_1_1_STS_EFUSE_INIT_RD_VAL_1_1_MASK                     (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_INIT_RD_VALUE_1_1_STS_EFUSE_INIT_RD_VAL_1_1_SHIFT                    (0)


#define EFUSECTRL_REG_READ_CTRL_1                                                          (EFUSECTRL_REG_BASE + 0xc0)
#define EFUSECTRL_REG_READ_CTRL_1_DEFAULT                                                  0x0
#define EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_REQ_1                                     (Bit0)
#define EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_ADDR_1                                    (Bit4+Bit5+Bit6+Bit7+Bit8)
#define EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_ADDR_1_MASK                               (Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_ADDR_1_SHIFT                              (4)
#define EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_EFUSE_SEL_1                               (Bit12+Bit13)
#define EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_EFUSE_SEL_1_MASK                          (Bit1+Bit0)
#define EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_EFUSE_SEL_1_SHIFT                         (12)
#define EFUSECTRL_REG_READ_CTRL_1_CTL_EFUSE_READ_MODE_1                                    (Bit16)


#define EFUSECTRL_REG_READ_VAL_1                                                           (EFUSECTRL_REG_BASE + 0xc4)
#define EFUSECTRL_REG_READ_VAL_1_DEFAULT                                                   0x0
#define EFUSECTRL_REG_READ_VAL_1_STS_EFUSE_READ_VAL_1                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define EFUSECTRL_REG_READ_VAL_1_STS_EFUSE_READ_VAL_1_MASK                                 (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_READ_VAL_1_STS_EFUSE_READ_VAL_1_SHIFT                                (0)


#define EFUSECTRL_REG_PROG_CTRL_1                                                          (EFUSECTRL_REG_BASE + 0xd0)
#define EFUSECTRL_REG_PROG_CTRL_1_DEFAULT                                                  0x0
#define EFUSECTRL_REG_PROG_CTRL_1_CTL_EFUSE_PROG_REQ_1                                     (Bit0)
#define EFUSECTRL_REG_PROG_CTRL_1_CTL_EFUSE_PROG_BIT_ADDR_1                                (Bit4+Bit5+Bit6+Bit7)
#define EFUSECTRL_REG_PROG_CTRL_1_CTL_EFUSE_PROG_BIT_ADDR_1_MASK                           (Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_PROG_CTRL_1_CTL_EFUSE_PROG_BIT_ADDR_1_SHIFT                          (4)
#define EFUSECTRL_REG_PROG_CTRL_1_CTL_EFUSE_PROG_ADDR_1                                    (Bit8+Bit9+Bit10+Bit11+Bit12)
#define EFUSECTRL_REG_PROG_CTRL_1_CTL_EFUSE_PROG_ADDR_1_MASK                               (Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_PROG_CTRL_1_CTL_EFUSE_PROG_ADDR_1_SHIFT                              (8)
#define EFUSECTRL_REG_PROG_CTRL_1_CTL_EFUSE_PROG_EFUSE_SEL_1                               (Bit16+Bit17)
#define EFUSECTRL_REG_PROG_CTRL_1_CTL_EFUSE_PROG_EFUSE_SEL_1_MASK                          (Bit1+Bit0)
#define EFUSECTRL_REG_PROG_CTRL_1_CTL_EFUSE_PROG_EFUSE_SEL_1_SHIFT                         (16)


#define EFUSECTRL_REG_COUNTER_CTRL_1_0                                                     (EFUSECTRL_REG_BASE + 0xe0)
#define EFUSECTRL_REG_COUNTER_CTRL_1_0_DEFAULT                                             0x1004010
#define EFUSECTRL_REG_COUNTER_CTRL_1_0_CTL_EFUSE_CNT_INIT_1                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define EFUSECTRL_REG_COUNTER_CTRL_1_0_CTL_EFUSE_CNT_INIT_1_MASK                           (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_COUNTER_CTRL_1_0_CTL_EFUSE_CNT_INIT_1_SHIFT                          (0)
#define EFUSECTRL_REG_COUNTER_CTRL_1_0_CTL_EFUSE_CNT_TRDS_1                                (Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define EFUSECTRL_REG_COUNTER_CTRL_1_0_CTL_EFUSE_CNT_TRDS_1_MASK                           (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_COUNTER_CTRL_1_0_CTL_EFUSE_CNT_TRDS_1_SHIFT                          (10)
#define EFUSECTRL_REG_COUNTER_CTRL_1_0_CTL_EFUSE_CNT_TFS_1                                 (Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define EFUSECTRL_REG_COUNTER_CTRL_1_0_CTL_EFUSE_CNT_TFS_1_MASK                            (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_COUNTER_CTRL_1_0_CTL_EFUSE_CNT_TFS_1_SHIFT                           (20)


#define EFUSECTRL_REG_COUNTER_CTRL_1_1                                                     (EFUSECTRL_REG_BASE + 0xe4)
#define EFUSECTRL_REG_COUNTER_CTRL_1_1_DEFAULT                                             0x1004010
#define EFUSECTRL_REG_COUNTER_CTRL_1_1_CTL_EFUSE_CNT_TPP_1                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define EFUSECTRL_REG_COUNTER_CTRL_1_1_CTL_EFUSE_CNT_TPP_1_MASK                            (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_COUNTER_CTRL_1_1_CTL_EFUSE_CNT_TPP_1_SHIFT                           (0)
#define EFUSECTRL_REG_COUNTER_CTRL_1_1_CTL_EFUSE_CNT_TEH_1                                 (Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define EFUSECTRL_REG_COUNTER_CTRL_1_1_CTL_EFUSE_CNT_TEH_1_MASK                            (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_COUNTER_CTRL_1_1_CTL_EFUSE_CNT_TEH_1_SHIFT                           (10)
#define EFUSECTRL_REG_COUNTER_CTRL_1_1_CTL_EFUSE_CNT_TESR_1                                (Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define EFUSECTRL_REG_COUNTER_CTRL_1_1_CTL_EFUSE_CNT_TESR_1_MASK                           (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_COUNTER_CTRL_1_1_CTL_EFUSE_CNT_TESR_1_SHIFT                          (20)


#define EFUSECTRL_REG_COUNTER_CTRL_1_2                                                     (EFUSECTRL_REG_BASE + 0xe8)
#define EFUSECTRL_REG_COUNTER_CTRL_1_2_DEFAULT                                             0x4010
#define EFUSECTRL_REG_COUNTER_CTRL_1_2_CTL_EFUSE_CNT_TRPW_1                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define EFUSECTRL_REG_COUNTER_CTRL_1_2_CTL_EFUSE_CNT_TRPW_1_MASK                           (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_COUNTER_CTRL_1_2_CTL_EFUSE_CNT_TRPW_1_SHIFT                          (0)
#define EFUSECTRL_REG_COUNTER_CTRL_1_2_CTL_EFUSE_CNT_TRC_MOD_1                             (Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define EFUSECTRL_REG_COUNTER_CTRL_1_2_CTL_EFUSE_CNT_TRC_MOD_1_MASK                        (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_COUNTER_CTRL_1_2_CTL_EFUSE_CNT_TRC_MOD_1_SHIFT                       (10)


#define EFUSECTRL_REG_INPLAY_INIT_RD_VAL                                                   (EFUSECTRL_REG_BASE + 0x100)
#define EFUSECTRL_REG_INPLAY_INIT_RD_VAL_DEFAULT                                           0x0
#define EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_EFUSE_LOCK                             (Bit0)
#define EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_SPIFLASH_PRESENT                              (Bit1)
#define EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_FEATURE_SEL                            (Bit4+Bit5+Bit6+Bit7)
#define EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_FEATURE_SEL_MASK                       (Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_FEATURE_SEL_SHIFT                      (4)
#define EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_SECURITY_KEY_SEL                       (Bit8+Bit9+Bit10+Bit11)
#define EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_SECURITY_KEY_SEL_MASK                  (Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_SECURITY_KEY_SEL_SHIFT                 (8)
#define EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_SECURITY_KEY_ALG                       (Bit12+Bit13+Bit14)
#define EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_SECURITY_KEY_ALG_MASK                  (Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_INPLAY_INIT_RD_VAL_STS_INPLAY_SECURITY_KEY_ALG_SHIFT                 (12)


#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL                                                     (EFUSECTRL_REG_BASE + 0x104)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_DEFAULT                                             0x0
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_0_PIN_MUX_SEL                              (Bit0+Bit1+Bit2)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_0_PIN_MUX_SEL_MASK                         (Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_0_PIN_MUX_SEL_SHIFT                        (0)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_2_PIN_MUX_SEL                              (Bit4+Bit5+Bit6)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_2_PIN_MUX_SEL_MASK                         (Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_2_PIN_MUX_SEL_SHIFT                        (4)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_3_PIN_MUX_SEL                              (Bit8+Bit9+Bit10)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_3_PIN_MUX_SEL_MASK                         (Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_3_PIN_MUX_SEL_SHIFT                        (8)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_4_PIN_MUX_SEL                              (Bit12+Bit13+Bit14)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_4_PIN_MUX_SEL_MASK                         (Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_4_PIN_MUX_SEL_SHIFT                        (12)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_5_PIN_MUX_SEL                              (Bit16+Bit17+Bit18)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_5_PIN_MUX_SEL_MASK                         (Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_5_PIN_MUX_SEL_SHIFT                        (16)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_3A_3B_SEL                                  (Bit24)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_TVSL                                       (Bit28+Bit29+Bit30)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_TVSL_MASK                                  (Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_QSPI_PIN_MUX_SEL_STS_QSPI_TVSL_SHIFT                                 (28)


#define EFUSECTRL_REG_UUID0                                                                (EFUSECTRL_REG_BASE + 0x110)
#define EFUSECTRL_REG_UUID0_DEFAULT                                                        0x0
#define EFUSECTRL_REG_UUID0_STS_UUID_31_0                                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define EFUSECTRL_REG_UUID0_STS_UUID_31_0_MASK                                             (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_UUID0_STS_UUID_31_0_SHIFT                                            (0)


#define EFUSECTRL_REG_UUID1                                                                (EFUSECTRL_REG_BASE + 0x114)
#define EFUSECTRL_REG_UUID1_DEFAULT                                                        0x0
#define EFUSECTRL_REG_UUID1_STS_UUID_63_32                                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define EFUSECTRL_REG_UUID1_STS_UUID_63_32_MASK                                            (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_UUID1_STS_UUID_63_32_SHIFT                                           (0)


#define EFUSECTRL_REG_UUID2                                                                (EFUSECTRL_REG_BASE + 0x118)
#define EFUSECTRL_REG_UUID2_DEFAULT                                                        0x0
#define EFUSECTRL_REG_UUID2_STS_UUID_95_64                                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define EFUSECTRL_REG_UUID2_STS_UUID_95_64_MASK                                            (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_UUID2_STS_UUID_95_64_SHIFT                                           (0)


#define EFUSECTRL_REG_UUID3                                                                (EFUSECTRL_REG_BASE + 0x11c)
#define EFUSECTRL_REG_UUID3_DEFAULT                                                        0x0
#define EFUSECTRL_REG_UUID3_STS_UUID_127_96                                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define EFUSECTRL_REG_UUID3_STS_UUID_127_96_MASK                                           (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_UUID3_STS_UUID_127_96_SHIFT                                          (0)


#define EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE                                               (EFUSECTRL_REG_BASE + 0x140)
#define EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_DEFAULT                                       0x0
#define EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_CUSTOMER_EFUSE_LOCK                       (Bit0)
#define EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_CM4_DBG_DISABLE                           (Bit1)
#define EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_FLASH_ENCRYPTION_ENABLE                   (Bit2)
#define EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_FLASH_SECURE_BOOT_ENABLE                  (Bit3)
#define EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_RAM_SECURE_BOOT_ENABLE                    (Bit4)
#define EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_ECC_LEN_SECURE_BOOT                       (Bit5)
#define EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_DEFAULT_IF_EN                             (Bit8)
#define EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_DEFAULT_IF_SEL                            (Bit12+Bit13+Bit14)
#define EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_DEFAULT_IF_SEL_MASK                       (Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_DEFAULT_IF_SEL_SHIFT                      (12)
#define EFUSECTRL_REG_CUSTOMER_INIT_RD_VALUE_STS_RTC_NOT_INSTALLED                         (Bit16)


#define EFUSECTRL_REG_CUSTOMER_ID                                                          (EFUSECTRL_REG_BASE + 0x144)
#define EFUSECTRL_REG_CUSTOMER_ID_DEFAULT                                                  0x0
#define EFUSECTRL_REG_CUSTOMER_ID_STS_CUSTOMER_ID                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define EFUSECTRL_REG_CUSTOMER_ID_STS_CUSTOMER_ID_MASK                                     (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define EFUSECTRL_REG_CUSTOMER_ID_STS_CUSTOMER_ID_SHIFT                                    (0)


#endif // _EFUSECTRL_REG_DEFINES_H

