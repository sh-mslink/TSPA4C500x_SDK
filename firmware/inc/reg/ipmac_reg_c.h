#ifndef _IPMAC_REG_DEFINES_H
#define _IPMAC_REG_DEFINES_H
/* **************************** */
#define IPMAC_REG_INTR_STATUS                                                                                            (IPMAC_REG_BASE + 0x0)
#define IPMAC_REG_INTR_STATUS_DEFAULT                                                                                    0x0
#define IPMAC_REG_INTR_STATUS_TODO                                                                                       (Bit0)


#define IPMAC_REG_INTR_MASK_STATUS                                                                                       (IPMAC_REG_BASE + 0x4)
#define IPMAC_REG_INTR_MASK_STATUS_DEFAULT                                                                               0x0
#define IPMAC_REG_INTR_MASK_STATUS_TODO                                                                                  (Bit0)


#define IPMAC_REG_INTR_CLR                                                                                               (IPMAC_REG_BASE + 0x8)
#define IPMAC_REG_INTR_CLR_DEFAULT                                                                                       0x0
#define IPMAC_REG_INTR_CLR_TODO                                                                                          (Bit0)


#define IPMAC_REG_INTR_SET                                                                                               (IPMAC_REG_BASE + 0xc)
#define IPMAC_REG_INTR_SET_DEFAULT                                                                                       0x0
#define IPMAC_REG_INTR_SET_TODO                                                                                          (Bit0)


#define IPMAC_REG_INTR_MASK_SET                                                                                          (IPMAC_REG_BASE + 0x10)
#define IPMAC_REG_INTR_MASK_SET_DEFAULT                                                                                  0x0
#define IPMAC_REG_INTR_MASK_SET_TODO                                                                                     (Bit0)


#define IPMAC_REG_INTR_MASK_CLR                                                                                          (IPMAC_REG_BASE + 0x14)
#define IPMAC_REG_INTR_MASK_CLR_DEFAULT                                                                                  0x0
#define IPMAC_REG_INTR_MASK_CLR_TODO                                                                                     (Bit0)


#define IPMAC_REG_SDR_MISC_CTRL                                                                                          (IPMAC_REG_BASE + 0x200)
#define IPMAC_REG_SDR_MISC_CTRL_DEFAULT                                                                                  0x110300
#define IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_EN                                                                               (Bit0)
#define IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_IGNORE_TIMESTAMP                                                                 (Bit4)
#define IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_IGNORE_TIMESTAMP_FINE                                                            (Bit5)
#define IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_MATCHING_DEST_ADDR                                                               (Bit8)
#define IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_MATCHING_SRC_ADDR                                                                (Bit9)
#define IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_SLV_ABORT_EVT_SINGLE_CRCERR                                                      (Bit12)
#define IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_MSTR_ABORT_EVT_SINGLE_CRCERR                                                     (Bit13)
#define IPMAC_REG_SDR_MISC_CTRL_CTL_SDR_DISABLE_MASK_AFTER_FIRST_MATCH                                                   (Bit16)
#define IPMAC_REG_SDR_MISC_CTRL_CTL_SCHDL_APFM_ERROR_MODE                                                                (Bit20)


#define IPMAC_REG_SDR_MISC_STS                                                                                           (IPMAC_REG_BASE + 0x208)
#define IPMAC_REG_SDR_MISC_STS_DEFAULT                                                                                   0x0
#define IPMAC_REG_SDR_MISC_STS_STS_SDR_TEST                                                                              (Bit0)


#define IPMAC_REG_SDR_DEST_ADDR_TO_MATCH                                                                                 (IPMAC_REG_BASE + 0x210)
#define IPMAC_REG_SDR_DEST_ADDR_TO_MATCH_DEFAULT                                                                         0xFFFF0000
#define IPMAC_REG_SDR_DEST_ADDR_TO_MATCH_CTL_SDR_DEST_ADDR                                                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_SDR_DEST_ADDR_TO_MATCH_CTL_SDR_DEST_ADDR_SHIFT                                                         (0)
//#define IPMAC_REG_SDR_DEST_ADDR_TO_MATCH_CTL_SDR_DEST_ADDR_MASK                                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_SDR_DEST_ADDR_TO_MATCH_CTL_SDR_DEST_ADDR_MASK_MASK                                                     (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_DEST_ADDR_TO_MATCH_CTL_SDR_DEST_ADDR_MASK_SHIFT                                                    (16)


#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_0                                                                                (IPMAC_REG_BASE + 0x220)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_0_DEFAULT                                                                        0xFFFF0000
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_0_CTL_SDR_SRC_ADDR_0                                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_0_CTL_SDR_SRC_ADDR_0_MASK                                                        (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_0_CTL_SDR_SRC_ADDR_0_SHIFT                                                       (0)
//#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_0_CTL_SDR_SRC_ADDR_0_MASK                                                        (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_0_CTL_SDR_SRC_ADDR_0_MASK_MASK                                                   (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_0_CTL_SDR_SRC_ADDR_0_MASK_SHIFT                                                  (16)


#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_1                                                                                (IPMAC_REG_BASE + 0x224)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_1_DEFAULT                                                                        0xFFFF0000
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_1_CTL_SDR_SRC_ADDR_1                                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_1_CTL_SDR_SRC_ADDR_1_MASK                                                        (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_1_CTL_SDR_SRC_ADDR_1_SHIFT                                                       (0)
//#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_1_CTL_SDR_SRC_ADDR_1_MASK                                                        (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_1_CTL_SDR_SRC_ADDR_1_MASK_MASK                                                   (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_1_CTL_SDR_SRC_ADDR_1_MASK_SHIFT                                                  (16)


#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_2                                                                                (IPMAC_REG_BASE + 0x228)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_2_DEFAULT                                                                        0xFFFF0000
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_2_CTL_SDR_SRC_ADDR_2                                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_2_CTL_SDR_SRC_ADDR_2_MASK                                                        (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_2_CTL_SDR_SRC_ADDR_2_SHIFT                                                       (0)
//#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_2_CTL_SDR_SRC_ADDR_2_MASK                                                        (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_2_CTL_SDR_SRC_ADDR_2_MASK_MASK                                                   (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_2_CTL_SDR_SRC_ADDR_2_MASK_SHIFT                                                  (16)


#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_3                                                                                (IPMAC_REG_BASE + 0x22c)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_3_DEFAULT                                                                        0xFFFF0000
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_3_CTL_SDR_SRC_ADDR_3                                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_3_CTL_SDR_SRC_ADDR_3_MASK                                                        (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_3_CTL_SDR_SRC_ADDR_3_SHIFT                                                       (0)
//#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_3_CTL_SDR_SRC_ADDR_3_MASK                                                        (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_3_CTL_SDR_SRC_ADDR_3_MASK_MASK                                                   (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_3_CTL_SDR_SRC_ADDR_3_MASK_SHIFT                                                  (16)


#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_4                                                                                (IPMAC_REG_BASE + 0x230)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_4_DEFAULT                                                                        0xFFFF0000
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_4_CTL_SDR_SRC_ADDR_4                                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_4_CTL_SDR_SRC_ADDR_4_MASK                                                        (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_4_CTL_SDR_SRC_ADDR_4_SHIFT                                                       (0)
//#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_4_CTL_SDR_SRC_ADDR_4_MASK                                                        (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_4_CTL_SDR_SRC_ADDR_4_MASK_MASK                                                   (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_4_CTL_SDR_SRC_ADDR_4_MASK_SHIFT                                                  (16)


#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_5                                                                                (IPMAC_REG_BASE + 0x234)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_5_DEFAULT                                                                        0xFFFF0000
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_5_CTL_SDR_SRC_ADDR_5                                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_5_CTL_SDR_SRC_ADDR_5_MASK                                                        (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_5_CTL_SDR_SRC_ADDR_5_SHIFT                                                       (0)
//#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_5_CTL_SDR_SRC_ADDR_5_MASK                                                        (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_5_CTL_SDR_SRC_ADDR_5_MASK_MASK                                                   (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_5_CTL_SDR_SRC_ADDR_5_MASK_SHIFT                                                  (16)


#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_6                                                                                (IPMAC_REG_BASE + 0x238)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_6_DEFAULT                                                                        0xFFFF0000
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_6_CTL_SDR_SRC_ADDR_6                                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_6_CTL_SDR_SRC_ADDR_6_MASK                                                        (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_6_CTL_SDR_SRC_ADDR_6_SHIFT                                                       (0)
//#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_6_CTL_SDR_SRC_ADDR_6_MASK                                                        (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_6_CTL_SDR_SRC_ADDR_6_MASK_MASK                                                   (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_6_CTL_SDR_SRC_ADDR_6_MASK_SHIFT                                                  (16)


#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_7                                                                                (IPMAC_REG_BASE + 0x23c)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_7_DEFAULT                                                                        0xFFFF0000
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_7_CTL_SDR_SRC_ADDR_7                                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_7_CTL_SDR_SRC_ADDR_7_MASK                                                        (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_7_CTL_SDR_SRC_ADDR_7_SHIFT                                                       (0)
//#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_7_CTL_SDR_SRC_ADDR_7_MASK                                                        (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_7_CTL_SDR_SRC_ADDR_7_MASK_MASK                                                   (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_SRC_ADDR_TO_MATCH_7_CTL_SDR_SRC_ADDR_7_MASK_SHIFT                                                  (16)


#define IPMAC_REG_SDR_ADDR_MATCH_STS                                                                                     (IPMAC_REG_BASE + 0x240)
#define IPMAC_REG_SDR_ADDR_MATCH_STS_DEFAULT                                                                             0x0
#define IPMAC_REG_SDR_ADDR_MATCH_STS_STS_SDR_DEST_ADDR_MATCH                                                             (Bit0)
#define IPMAC_REG_SDR_ADDR_MATCH_STS_STS_SDR_SRC_ADDR_MATCH                                                              (Bit4)
#define IPMAC_REG_SDR_ADDR_MATCH_STS_STS_SDR_SRC_ADDR_MATCH_SEL                                                          (Bit8+Bit9+Bit10)
#define IPMAC_REG_SDR_ADDR_MATCH_STS_STS_SDR_SRC_ADDR_MATCH_SEL_MASK                                                     (Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_ADDR_MATCH_STS_STS_SDR_SRC_ADDR_MATCH_SEL_SHIFT                                                    (8)


#define IPMAC_REG_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH                                                                    (IPMAC_REG_BASE + 0x244)
#define IPMAC_REG_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_DEFAULT                                                            0x103
#define IPMAC_REG_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_CTL_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH                            (Bit0)
#define IPMAC_REG_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_CTL_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_SINGLE                     (Bit1)
#define IPMAC_REG_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_CTL_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_IDLE_LMT                   (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define IPMAC_REG_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_CTL_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_IDLE_LMT_MASK              (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_CTL_SDR_RESTART_DUE_TO_RX_ADDR_MISMATCH_IDLE_LMT_SHIFT             (4)


#define IPMAC_REG_SDR_BROADCAST_MODE_CTL                                                                                 (IPMAC_REG_BASE + 0x250)
#define IPMAC_REG_SDR_BROADCAST_MODE_CTL_DEFAULT                                                                         0x33
#define IPMAC_REG_SDR_BROADCAST_MODE_CTL_CTL_SDR_BROADCAST_MODE_ET_VALUE                                                 (Bit0+Bit1+Bit2)
#define IPMAC_REG_SDR_BROADCAST_MODE_CTL_CTL_SDR_BROADCAST_MODE_ET_VALUE_MASK                                            (Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_BROADCAST_MODE_CTL_CTL_SDR_BROADCAST_MODE_ET_VALUE_SHIFT                                           (0)
#define IPMAC_REG_SDR_BROADCAST_MODE_CTL_CTL_SDR_BROADCAST_MODE_RFU_VALUE                                                (Bit4+Bit5+Bit6)
#define IPMAC_REG_SDR_BROADCAST_MODE_CTL_CTL_SDR_BROADCAST_MODE_RFU_VALUE_MASK                                           (Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_BROADCAST_MODE_CTL_CTL_SDR_BROADCAST_MODE_RFU_VALUE_SHIFT                                          (4)


#define IPMAC_REG_SDR_PRIVATE_MODE_CTL                                                                                   (IPMAC_REG_BASE + 0x254)
#define IPMAC_REG_SDR_PRIVATE_MODE_CTL_DEFAULT                                                                           0x466
#define IPMAC_REG_SDR_PRIVATE_MODE_CTL_CTL_SDR_PRIVATE_MODE_ET_VALUE                                                     (Bit0+Bit1+Bit2)
#define IPMAC_REG_SDR_PRIVATE_MODE_CTL_CTL_SDR_PRIVATE_MODE_ET_VALUE_MASK                                                (Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_PRIVATE_MODE_CTL_CTL_SDR_PRIVATE_MODE_ET_VALUE_SHIFT                                               (0)
#define IPMAC_REG_SDR_PRIVATE_MODE_CTL_CTL_SDR_PRIVATE_MODE_RFU_VALUE                                                    (Bit4+Bit5+Bit6)
#define IPMAC_REG_SDR_PRIVATE_MODE_CTL_CTL_SDR_PRIVATE_MODE_RFU_VALUE_MASK                                               (Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_PRIVATE_MODE_CTL_CTL_SDR_PRIVATE_MODE_RFU_VALUE_SHIFT                                              (4)
#define IPMAC_REG_SDR_PRIVATE_MODE_CTL_CTL_SDR_PRIVATE_MODE_ACK_RFU_VALUE                                                (Bit8+Bit9+Bit10)
#define IPMAC_REG_SDR_PRIVATE_MODE_CTL_CTL_SDR_PRIVATE_MODE_ACK_RFU_VALUE_MASK                                           (Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_PRIVATE_MODE_CTL_CTL_SDR_PRIVATE_MODE_ACK_RFU_VALUE_SHIFT                                          (8)


#define IPMAC_REG_SDR_RX_ADDR                                                                                            (IPMAC_REG_BASE + 0x268)
#define IPMAC_REG_SDR_RX_ADDR_DEFAULT                                                                                    0x0
#define IPMAC_REG_SDR_RX_ADDR_STS_SDR_RX_SRC_ADDR                                                                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_SDR_RX_ADDR_STS_SDR_RX_SRC_ADDR_MASK                                                                   (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_RX_ADDR_STS_SDR_RX_SRC_ADDR_SHIFT                                                                  (0)
#define IPMAC_REG_SDR_RX_ADDR_STS_SDR_RX_DEST_ADDR                                                                       (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_SDR_RX_ADDR_STS_SDR_RX_DEST_ADDR_MASK                                                                  (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_RX_ADDR_STS_SDR_RX_DEST_ADDR_SHIFT                                                                 (16)


#define IPMAC_REG_SDR_TX_ADDR                                                                                            (IPMAC_REG_BASE + 0x26c)
#define IPMAC_REG_SDR_TX_ADDR_DEFAULT                                                                                    0x0
#define IPMAC_REG_SDR_TX_ADDR_STS_SDR_TX_SRC_ADDR                                                                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_SDR_TX_ADDR_STS_SDR_TX_SRC_ADDR_MASK                                                                   (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_TX_ADDR_STS_SDR_TX_SRC_ADDR_SHIFT                                                                  (0)
#define IPMAC_REG_SDR_TX_ADDR_STS_SDR_TX_DEST_ADDR                                                                       (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_SDR_TX_ADDR_STS_SDR_TX_DEST_ADDR_MASK                                                                  (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_TX_ADDR_STS_SDR_TX_DEST_ADDR_SHIFT                                                                 (16)


#define IPMAC_REG_SDR_CUS_HEADER_TX_MISC_CTRL                                                                            (IPMAC_REG_BASE + 0x280)
#define IPMAC_REG_SDR_CUS_HEADER_TX_MISC_CTRL_DEFAULT                                                                    0x0
#define IPMAC_REG_SDR_CUS_HEADER_TX_MISC_CTRL_CTL_SDR_TX_CUSDEF_HEADER                                                   (Bit0)
#define IPMAC_REG_SDR_CUS_HEADER_TX_MISC_CTRL_CTL_SDR_TX_CUSDEF_HEADER_LEN_M1                                            (Bit4+Bit5+Bit6+Bit7+Bit8)
#define IPMAC_REG_SDR_CUS_HEADER_TX_MISC_CTRL_CTL_SDR_TX_CUSDEF_HEADER_LEN_M1_MASK                                       (Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_CUS_HEADER_TX_MISC_CTRL_CTL_SDR_TX_CUSDEF_HEADER_LEN_M1_SHIFT                                      (4)
#define IPMAC_REG_SDR_CUS_HEADER_TX_MISC_CTRL_CTL_SDR_TX_CUSDEF_HEADER_PAYLOAD_LEN                                       (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define IPMAC_REG_SDR_CUS_HEADER_TX_MISC_CTRL_CTL_SDR_TX_CUSDEF_HEADER_PAYLOAD_LEN_MASK                                  (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_CUS_HEADER_TX_MISC_CTRL_CTL_SDR_TX_CUSDEF_HEADER_PAYLOAD_LEN_SHIFT                                 (12)


#define IPMAC_REG_SDR_CUS_HEADER_TX_VALUE                                                                                (IPMAC_REG_BASE + 0x284)
#define IPMAC_REG_SDR_CUS_HEADER_TX_VALUE_DEFAULT                                                                        0x0
#define IPMAC_REG_SDR_CUS_HEADER_TX_VALUE_CTL_SDR_TX_CUSDEF_HEADER_VAL                                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_SDR_CUS_HEADER_TX_VALUE_CTL_SDR_TX_CUSDEF_HEADER_VAL_MASK                                              (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_CUS_HEADER_TX_VALUE_CTL_SDR_TX_CUSDEF_HEADER_VAL_SHIFT                                             (0)


#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL                                                                            (IPMAC_REG_BASE + 0x2a0)
#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_DEFAULT                                                                    0x0
#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_CTL_SDR_RX_CUSDEF_HEADER                                                   (Bit0)
#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_CTL_SDR_RX_CUSDEF_HEADER_PAYLOAD_LEN_LSB0MSB1_FIRST                        (Bit1)
#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_CTL_SDR_RX_CUSDEF_HEADER_LEN_M1                                            (Bit4+Bit5+Bit6+Bit7+Bit8)
#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_CTL_SDR_RX_CUSDEF_HEADER_LEN_M1_MASK                                       (Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_CTL_SDR_RX_CUSDEF_HEADER_LEN_M1_SHIFT                                      (4)
#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_CTL_SDR_RX_CUSDEF_HEADER_PAYLOAD_ADDITIONAL_LEN                            (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_CTL_SDR_RX_CUSDEF_HEADER_PAYLOAD_ADDITIONAL_LEN_MASK                       (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_CTL_SDR_RX_CUSDEF_HEADER_PAYLOAD_ADDITIONAL_LEN_SHIFT                      (12)


#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_2                                                                          (IPMAC_REG_BASE + 0x2a4)
#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_2_DEFAULT                                                                  0x0
#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_2_CTL_SDR_RX_CUSDEF_HEADER_PAYLOAD_LEN_1ST_BIT_OFFSET                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_2_CTL_SDR_RX_CUSDEF_HEADER_PAYLOAD_LEN_1ST_BIT_OFFSET_MASK                 (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_2_CTL_SDR_RX_CUSDEF_HEADER_PAYLOAD_LEN_1ST_BIT_OFFSET_SHIFT                (0)
#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_2_CTL_SDR_RX_CUSDEF_HEADER_PAYLOAD_LEN_LAST_BIT_OFFSET                     (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_2_CTL_SDR_RX_CUSDEF_HEADER_PAYLOAD_LEN_LAST_BIT_OFFSET_MASK                (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_CUS_HEADER_RX_MISC_CTRL_2_CTL_SDR_RX_CUSDEF_HEADER_PAYLOAD_LEN_LAST_BIT_OFFSET_SHIFT               (12)


#define IPMAC_REG_SDR_CUS_HEADER_RX_VALUE                                                                                (IPMAC_REG_BASE + 0x2b0)
#define IPMAC_REG_SDR_CUS_HEADER_RX_VALUE_DEFAULT                                                                        0x0
#define IPMAC_REG_SDR_CUS_HEADER_RX_VALUE_STS_SDR_RX_CUSDEF_HEADER_VAL                                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_SDR_CUS_HEADER_RX_VALUE_STS_SDR_RX_CUSDEF_HEADER_VAL_MASK                                              (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_CUS_HEADER_RX_VALUE_STS_SDR_RX_CUSDEF_HEADER_VAL_SHIFT                                             (0)


#define IPMAC_REG_SDR_CUS_HEADER_PAYLOAD_LEN_VAL                                                                         (IPMAC_REG_BASE + 0x2b4)
#define IPMAC_REG_SDR_CUS_HEADER_PAYLOAD_LEN_VAL_DEFAULT                                                                 0x0
#define IPMAC_REG_SDR_CUS_HEADER_PAYLOAD_LEN_VAL_STS_SDR_RX_CUSDEF_HEADER_PAYLOAD_LEN                                    (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define IPMAC_REG_SDR_CUS_HEADER_PAYLOAD_LEN_VAL_STS_SDR_RX_CUSDEF_HEADER_PAYLOAD_LEN_MASK                               (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SDR_CUS_HEADER_PAYLOAD_LEN_VAL_STS_SDR_RX_CUSDEF_HEADER_PAYLOAD_LEN_SHIFT                              (0)


#define IPMAC_REG_MDM_ADDITION                                                                                           (IPMAC_REG_BASE + 0x500)
#define IPMAC_REG_MDM_ADDITION_DEFAULT                                                                                   0x0
#define IPMAC_REG_MDM_ADDITION_CTL_MDM_TEST                                                                              (Bit0)


#define IPMAC_REG_BLE_ADDITION                                                                                           (IPMAC_REG_BASE + 0x600)
#define IPMAC_REG_BLE_ADDITION_DEFAULT                                                                                   0x0
#define IPMAC_REG_BLE_ADDITION_CTL_BLE_CNTL_TIMER_USE_RXPATHDLY                                                          (Bit0)


#define IPMAC_REG_BLE_ABORT_REQ                                                                                          (IPMAC_REG_BASE + 0x604)
#define IPMAC_REG_BLE_ABORT_REQ_DEFAULT                                                                                  0x4040
#define IPMAC_REG_BLE_ABORT_REQ_CTL_BLE_ABORT_REQ                                                                        (Bit0)
#define IPMAC_REG_BLE_ABORT_REQ_CTL_BLE_ABORT_PULSE_DUR                                                                  (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define IPMAC_REG_BLE_ABORT_REQ_CTL_BLE_ABORT_PULSE_DUR_MASK                                                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_BLE_ABORT_REQ_CTL_BLE_ABORT_PULSE_DUR_SHIFT                                                            (4)
#define IPMAC_REG_BLE_ABORT_REQ_CTL_BLE_ABORT_ERROR_FLAG_SET                                                             (Bit12+Bit13+Bit14+Bit15+Bit16)
#define IPMAC_REG_BLE_ABORT_REQ_CTL_BLE_ABORT_ERROR_FLAG_SET_MASK                                                        (Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_BLE_ABORT_REQ_CTL_BLE_ABORT_ERROR_FLAG_SET_SHIFT                                                       (12)
#define IPMAC_REG_BLE_ABORT_REQ_STS_BLE_ABORT_PACKET_CNTL_STATE                                                          (Bit20+Bit21+Bit22+Bit23+Bit24+Bit25)
#define IPMAC_REG_BLE_ABORT_REQ_STS_BLE_ABORT_PACKET_CNTL_STATE_MASK                                                     (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_BLE_ABORT_REQ_STS_BLE_ABORT_PACKET_CNTL_STATE_SHIFT                                                    (20)


#define IPMAC_REG_SPARE                                                                                                  (IPMAC_REG_BASE + 0x7fc)
#define IPMAC_REG_SPARE_DEFAULT                                                                                          0x0
#define IPMAC_REG_SPARE_CTL_RW_BLE_BB_SPARE                                                                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_SPARE_CTL_RW_BLE_BB_SPARE_MASK                                                                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SPARE_CTL_RW_BLE_BB_SPARE_SHIFT                                                                        (0)
#define IPMAC_REG_SPARE_CTL_RW_MDM_SPARE                                                                                 (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_SPARE_CTL_RW_MDM_SPARE_MASK                                                                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SPARE_CTL_RW_MDM_SPARE_SHIFT                                                                           (8)
#define IPMAC_REG_SPARE_CTL_IPMAC_SPARE                                                                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_SPARE_CTL_IPMAC_SPARE_MASK                                                                             (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SPARE_CTL_IPMAC_SPARE_SHIFT                                                                            (16)


#define IPMAC_REG_IPMAC_MISC_CNTL                                                                                        (IPMAC_REG_BASE + 0x800)
#define IPMAC_REG_IPMAC_MISC_CNTL_DEFAULT                                                                                0x10
#define IPMAC_REG_IPMAC_MISC_CNTL_CTL_IPMAC_EN                                                                           (Bit0)
#define IPMAC_REG_IPMAC_MISC_CNTL_CTL_IPMAC_SUSPEND                                                                      (Bit1)
#define IPMAC_REG_IPMAC_MISC_CNTL_CTL_IPMAC_MODE_MSTR0SLV1                                                               (Bit2)
#define IPMAC_REG_IPMAC_MISC_CNTL_CTL_IPMAC_SOFT_RST                                                                     (Bit3)
#define IPMAC_REG_IPMAC_MISC_CNTL_CTL_IPMAC_CRC_EN                                                                       (Bit4)
#define IPMAC_REG_IPMAC_MISC_CNTL_CTL_IPMAC_WHIT_EN                                                                      (Bit5)
#define IPMAC_REG_IPMAC_MISC_CNTL_CTL_IPMAC_WHIT_INIT_VALUE_FORCE                                                        (Bit6)
#define IPMAC_REG_IPMAC_MISC_CNTL_CTL_IPMAC_TX_RATE                                                                      (Bit8+Bit9)
#define IPMAC_REG_IPMAC_MISC_CNTL_CTL_IPMAC_TX_RATE_MASK                                                                 (Bit1+Bit0)
#define IPMAC_REG_IPMAC_MISC_CNTL_CTL_IPMAC_TX_RATE_SHIFT                                                                (8)
#define IPMAC_REG_IPMAC_MISC_CNTL_CTL_IPMAC_RX_RATE                                                                      (Bit12+Bit13)
#define IPMAC_REG_IPMAC_MISC_CNTL_CTL_IPMAC_RX_RATE_MASK                                                                 (Bit1+Bit0)
#define IPMAC_REG_IPMAC_MISC_CNTL_CTL_IPMAC_RX_RATE_SHIFT                                                                (12)
#define IPMAC_REG_IPMAC_MISC_CNTL_CTL_IPMAC_EX_TABLE_ADDR_OFFSET                                                         (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30)
#define IPMAC_REG_IPMAC_MISC_CNTL_CTL_IPMAC_EX_TABLE_ADDR_OFFSET_MASK                                                    (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_IPMAC_MISC_CNTL_CTL_IPMAC_EX_TABLE_ADDR_OFFSET_SHIFT                                                   (16)


#define IPMAC_REG_IPMAC_TIMING_CTRL                                                                                      (IPMAC_REG_BASE + 0x808)
#define IPMAC_REG_IPMAC_TIMING_CTRL_DEFAULT                                                                              0x4010
#define IPMAC_REG_IPMAC_TIMING_CTRL_CTL_IPMAC_US_CNT_LMT                                                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define IPMAC_REG_IPMAC_TIMING_CTRL_CTL_IPMAC_US_CNT_LMT_MASK                                                            (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_IPMAC_TIMING_CTRL_CTL_IPMAC_US_CNT_LMT_SHIFT                                                           (0)
#define IPMAC_REG_IPMAC_TIMING_CTRL_CTL_IPMAC_FINE_CNT_LMT                                                               (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_IPMAC_TIMING_CTRL_CTL_IPMAC_FINE_CNT_LMT_MASK                                                          (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_IPMAC_TIMING_CTRL_CTL_IPMAC_FINE_CNT_LMT_SHIFT                                                         (8)


#define IPMAC_REG_IPMAC_TIMING_ADJUST_CTRL                                                                               (IPMAC_REG_BASE + 0x80c)
#define IPMAC_REG_IPMAC_TIMING_ADJUST_CTRL_DEFAULT                                                                       0x20010
#define IPMAC_REG_IPMAC_TIMING_ADJUST_CTRL_CTL_IPMAC_SF_EVNT_PRE_START_GAP                                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define IPMAC_REG_IPMAC_TIMING_ADJUST_CTRL_CTL_IPMAC_SF_EVNT_PRE_START_GAP_MASK                                          (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_IPMAC_TIMING_ADJUST_CTRL_CTL_IPMAC_SF_EVNT_PRE_START_GAP_SHIFT                                         (0)
#define IPMAC_REG_IPMAC_TIMING_ADJUST_CTRL_CTL_IPMAC_SF_EVNT_PRE_START_GAP_FINE                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_IPMAC_TIMING_ADJUST_CTRL_CTL_IPMAC_SF_EVNT_PRE_START_GAP_FINE_MASK                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_IPMAC_TIMING_ADJUST_CTRL_CTL_IPMAC_SF_EVNT_PRE_START_GAP_FINE_SHIFT                                    (16)


#define IPMAC_REG_IPMAC_TIMING_ADJUST_SLV_CTRL                                                                           (IPMAC_REG_BASE + 0x810)
#define IPMAC_REG_IPMAC_TIMING_ADJUST_SLV_CTRL_DEFAULT                                                                   0x20001
#define IPMAC_REG_IPMAC_TIMING_ADJUST_SLV_CTRL_CTL_IPMAC_SLV_BEACON_SYNC_FOUND_SF_DURATION_CNT_INIT_VAL                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define IPMAC_REG_IPMAC_TIMING_ADJUST_SLV_CTRL_CTL_IPMAC_SLV_BEACON_SYNC_FOUND_SF_DURATION_CNT_INIT_VAL_MASK             (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_IPMAC_TIMING_ADJUST_SLV_CTRL_CTL_IPMAC_SLV_BEACON_SYNC_FOUND_SF_DURATION_CNT_INIT_VAL_SHIFT            (0)
#define IPMAC_REG_IPMAC_TIMING_ADJUST_SLV_CTRL_CTL_IPMAC_SLV_BEACON_SYNC_FOUND_FINE_CNT_INIT_VAL                         (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_IPMAC_TIMING_ADJUST_SLV_CTRL_CTL_IPMAC_SLV_BEACON_SYNC_FOUND_FINE_CNT_INIT_VAL_MASK                    (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_IPMAC_TIMING_ADJUST_SLV_CTRL_CTL_IPMAC_SLV_BEACON_SYNC_FOUND_FINE_CNT_INIT_VAL_SHIFT                   (16)


#define IPMAC_REG_EVNT_CNTL_STS                                                                                          (IPMAC_REG_BASE + 0x818)
#define IPMAC_REG_EVNT_CNTL_STS_DEFAULT                                                                                  0x0
#define IPMAC_REG_EVNT_CNTL_STS_STS_IPMAC_EVNT_CNTL_MSTR_MAIN_CURR_STATE                                                 (Bit0+Bit1+Bit2+Bit3)
#define IPMAC_REG_EVNT_CNTL_STS_STS_IPMAC_EVNT_CNTL_MSTR_MAIN_CURR_STATE_MASK                                            (Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_EVNT_CNTL_STS_STS_IPMAC_EVNT_CNTL_MSTR_MAIN_CURR_STATE_SHIFT                                           (0)
#define IPMAC_REG_EVNT_CNTL_STS_STS_IPMAC_EVNT_CNTL_MSTR_MAIN_CURR_SLV_IDX                                               (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10)
#define IPMAC_REG_EVNT_CNTL_STS_STS_IPMAC_EVNT_CNTL_MSTR_MAIN_CURR_SLV_IDX_MASK                                          (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_EVNT_CNTL_STS_STS_IPMAC_EVNT_CNTL_MSTR_MAIN_CURR_SLV_IDX_SHIFT                                         (4)
#define IPMAC_REG_EVNT_CNTL_STS_STS_IPMAC_EVNT_CNTL_SLV_MAIN_CURR_STATE                                                  (Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_EVNT_CNTL_STS_STS_IPMAC_EVNT_CNTL_SLV_MAIN_CURR_STATE_MASK                                             (Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_EVNT_CNTL_STS_STS_IPMAC_EVNT_CNTL_SLV_MAIN_CURR_STATE_SHIFT                                            (12)
#define IPMAC_REG_EVNT_CNTL_STS_STS_IPMAC_EVNT_CNTL_SLV_MAIN_SLV_IDX                                                     (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22)
#define IPMAC_REG_EVNT_CNTL_STS_STS_IPMAC_EVNT_CNTL_SLV_MAIN_SLV_IDX_MASK                                                (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_EVNT_CNTL_STS_STS_IPMAC_EVNT_CNTL_SLV_MAIN_SLV_IDX_SHIFT                                               (16)


#define IPMAC_REG_SF_CNT_STS                                                                                             (IPMAC_REG_BASE + 0x820)
#define IPMAC_REG_SF_CNT_STS_DEFAULT                                                                                     0x0
#define IPMAC_REG_SF_CNT_STS_STS_IPMAC_CUR_SF_DURATION                                                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define IPMAC_REG_SF_CNT_STS_STS_IPMAC_CUR_SF_DURATION_MASK                                                              (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SF_CNT_STS_STS_IPMAC_CUR_SF_DURATION_SHIFT                                                             (0)
#define IPMAC_REG_SF_CNT_STS_STS_IPMAC_CUR_SF_DURATION_CNT                                                               (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30)
#define IPMAC_REG_SF_CNT_STS_STS_IPMAC_CUR_SF_DURATION_CNT_MASK                                                          (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SF_CNT_STS_STS_IPMAC_CUR_SF_DURATION_CNT_SHIFT                                                         (16)


#define IPMAC_REG_PREAMBLE_VALUE_LR                                                                                      (IPMAC_REG_BASE + 0x828)
#define IPMAC_REG_PREAMBLE_VALUE_LR_DEFAULT                                                                              0x0
#define IPMAC_REG_PREAMBLE_VALUE_LR_CTL_IPMAC_PREAMBLE_LRANGE                                                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_PREAMBLE_VALUE_LR_CTL_IPMAC_PREAMBLE_LRANGE_MASK                                                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_PREAMBLE_VALUE_LR_CTL_IPMAC_PREAMBLE_LRANGE_SHIFT                                                      (0)


#define IPMAC_REG_PREAMBLE_VALUE_1M2M                                                                                    (IPMAC_REG_BASE + 0x82c)
#define IPMAC_REG_PREAMBLE_VALUE_1M2M_DEFAULT                                                                            0x0
#define IPMAC_REG_PREAMBLE_VALUE_1M2M_CTL_IPMAC_PREAMBLE_1M_SYNC0                                                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_PREAMBLE_VALUE_1M2M_CTL_IPMAC_PREAMBLE_1M_SYNC0_MASK                                                   (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_PREAMBLE_VALUE_1M2M_CTL_IPMAC_PREAMBLE_1M_SYNC0_SHIFT                                                  (0)
#define IPMAC_REG_PREAMBLE_VALUE_1M2M_CTL_IPMAC_PREAMBLE_1M_SYNC1                                                        (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_PREAMBLE_VALUE_1M2M_CTL_IPMAC_PREAMBLE_1M_SYNC1_MASK                                                   (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_PREAMBLE_VALUE_1M2M_CTL_IPMAC_PREAMBLE_1M_SYNC1_SHIFT                                                  (8)
#define IPMAC_REG_PREAMBLE_VALUE_1M2M_CTL_IPMAC_PREAMBLE_2M_SYNC0                                                        (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_PREAMBLE_VALUE_1M2M_CTL_IPMAC_PREAMBLE_2M_SYNC0_MASK                                                   (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_PREAMBLE_VALUE_1M2M_CTL_IPMAC_PREAMBLE_2M_SYNC0_SHIFT                                                  (16)
#define IPMAC_REG_PREAMBLE_VALUE_1M2M_CTL_IPMAC_PREAMBLE_2M_SYNC1                                                        (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_PREAMBLE_VALUE_1M2M_CTL_IPMAC_PREAMBLE_2M_SYNC1_MASK                                                   (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_PREAMBLE_VALUE_1M2M_CTL_IPMAC_PREAMBLE_2M_SYNC1_SHIFT                                                  (24)


#define IPMAC_REG_TX_PWR_DELAY                                                                                           (IPMAC_REG_BASE + 0x838)
#define IPMAC_REG_TX_PWR_DELAY_DEFAULT                                                                                   0x10101010
#define IPMAC_REG_TX_PWR_DELAY_CTL_IPMAC_TX_PWRUP_DLY_1M                                                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_TX_PWR_DELAY_CTL_IPMAC_TX_PWRUP_DLY_1M_MASK                                                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_TX_PWR_DELAY_CTL_IPMAC_TX_PWRUP_DLY_1M_SHIFT                                                           (0)
#define IPMAC_REG_TX_PWR_DELAY_CTL_IPMAC_TX_PWRUP_DLY_2M                                                                 (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_TX_PWR_DELAY_CTL_IPMAC_TX_PWRUP_DLY_2M_MASK                                                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_TX_PWR_DELAY_CTL_IPMAC_TX_PWRUP_DLY_2M_SHIFT                                                           (8)
#define IPMAC_REG_TX_PWR_DELAY_CTL_IPMAC_TX_PWRUP_DLY_500K                                                               (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_TX_PWR_DELAY_CTL_IPMAC_TX_PWRUP_DLY_500K_MASK                                                          (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_TX_PWR_DELAY_CTL_IPMAC_TX_PWRUP_DLY_500K_SHIFT                                                         (16)
#define IPMAC_REG_TX_PWR_DELAY_CTL_IPMAC_TX_PWRUP_DLY_125K                                                               (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_TX_PWR_DELAY_CTL_IPMAC_TX_PWRUP_DLY_125K_MASK                                                          (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_TX_PWR_DELAY_CTL_IPMAC_TX_PWRUP_DLY_125K_SHIFT                                                         (24)


#define IPMAC_REG_TX_ANT_DELAY                                                                                           (IPMAC_REG_BASE + 0x83c)
#define IPMAC_REG_TX_ANT_DELAY_DEFAULT                                                                                   0x10
#define IPMAC_REG_TX_ANT_DELAY_CTL_IPMAC_TX_ANT_DELAY                                                                    (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_TX_ANT_DELAY_CTL_IPMAC_TX_ANT_DELAY_MASK                                                               (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_TX_ANT_DELAY_CTL_IPMAC_TX_ANT_DELAY_SHIFT                                                              (0)


#define IPMAC_REG_WHITENING_CRC_INIT_VALUE                                                                               (IPMAC_REG_BASE + 0x840)
#define IPMAC_REG_WHITENING_CRC_INIT_VALUE_DEFAULT                                                                       0x1010
#define IPMAC_REG_WHITENING_CRC_INIT_VALUE_CTL_IPMAC_WHIT_INIT_VALUE                                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6)
#define IPMAC_REG_WHITENING_CRC_INIT_VALUE_CTL_IPMAC_WHIT_INIT_VALUE_MASK                                                (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_WHITENING_CRC_INIT_VALUE_CTL_IPMAC_WHIT_INIT_VALUE_SHIFT                                               (0)
#define IPMAC_REG_WHITENING_CRC_INIT_VALUE_CTL_IPMAC_CRC_INIT_VALUE                                                      (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_WHITENING_CRC_INIT_VALUE_CTL_IPMAC_CRC_INIT_VALUE_MASK                                                 (Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_WHITENING_CRC_INIT_VALUE_CTL_IPMAC_CRC_INIT_VALUE_SHIFT                                                (8)


#define IPMAC_REG_SYNC_WORD                                                                                              (IPMAC_REG_BASE + 0x848)
#define IPMAC_REG_SYNC_WORD_DEFAULT                                                                                      0x10
#define IPMAC_REG_SYNC_WORD_CTL_IPMAC_SYNC_WORD                                                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_SYNC_WORD_CTL_IPMAC_SYNC_WORD_MASK                                                                     (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SYNC_WORD_CTL_IPMAC_SYNC_WORD_SHIFT                                                                    (0)


#define IPMAC_REG_LR_TX_CTL                                                                                              (IPMAC_REG_BASE + 0x850)
#define IPMAC_REG_LR_TX_CTL_DEFAULT                                                                                      0x3
#define IPMAC_REG_LR_TX_CTL_CTL_IPMAC_LR_FEC_ENC_EN                                                                      (Bit0)
#define IPMAC_REG_LR_TX_CTL_CTL_IPMAC_LR_PMAP_EN                                                                         (Bit1)


#define IPMAC_REG_CH_IDX                                                                                                 (IPMAC_REG_BASE + 0x858)
#define IPMAC_REG_CH_IDX_DEFAULT                                                                                         0x1
#define IPMAC_REG_CH_IDX_CTL_IPMAC_CH_IDX                                                                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define IPMAC_REG_CH_IDX_CTL_IPMAC_CH_IDX_MASK                                                                           (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_CH_IDX_CTL_IPMAC_CH_IDX_SHIFT                                                                          (0)


#define IPMAC_REG_RX_PWR_DELAY                                                                                           (IPMAC_REG_BASE + 0x860)
#define IPMAC_REG_RX_PWR_DELAY_DEFAULT                                                                                   0x10101010
#define IPMAC_REG_RX_PWR_DELAY_CTL_IPMAC_RX_PWRUP_DLY_1M                                                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_RX_PWR_DELAY_CTL_IPMAC_RX_PWRUP_DLY_1M_MASK                                                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_RX_PWR_DELAY_CTL_IPMAC_RX_PWRUP_DLY_1M_SHIFT                                                           (0)
#define IPMAC_REG_RX_PWR_DELAY_CTL_IPMAC_RX_PWRUP_DLY_2M                                                                 (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_RX_PWR_DELAY_CTL_IPMAC_RX_PWRUP_DLY_2M_MASK                                                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_RX_PWR_DELAY_CTL_IPMAC_RX_PWRUP_DLY_2M_SHIFT                                                           (8)
#define IPMAC_REG_RX_PWR_DELAY_CTL_IPMAC_RX_PWRUP_DLY_LR                                                                 (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_RX_PWR_DELAY_CTL_IPMAC_RX_PWRUP_DLY_LR_MASK                                                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_RX_PWR_DELAY_CTL_IPMAC_RX_PWRUP_DLY_LR_SHIFT                                                           (16)
#define IPMAC_REG_RX_PWR_DELAY_CTL_IPMAC_RX_ANT_DELAY                                                                    (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_RX_PWR_DELAY_CTL_IPMAC_RX_ANT_DELAY_MASK                                                               (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_RX_PWR_DELAY_CTL_IPMAC_RX_ANT_DELAY_SHIFT                                                              (24)


#define IPMAC_REG_RX_SYNC_WIN_SIZE                                                                                       (IPMAC_REG_BASE + 0x868)
#define IPMAC_REG_RX_SYNC_WIN_SIZE_DEFAULT                                                                               0x100010
#define IPMAC_REG_RX_SYNC_WIN_SIZE_CTL_IPMAC_RX_SYNC_WIN_SIZE_1M                                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_RX_SYNC_WIN_SIZE_CTL_IPMAC_RX_SYNC_WIN_SIZE_1M_MASK                                                    (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_RX_SYNC_WIN_SIZE_CTL_IPMAC_RX_SYNC_WIN_SIZE_1M_SHIFT                                                   (0)
#define IPMAC_REG_RX_SYNC_WIN_SIZE_CTL_IPMAC_RX_SYNC_WIN_SIZE_2M                                                         (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_RX_SYNC_WIN_SIZE_CTL_IPMAC_RX_SYNC_WIN_SIZE_2M_MASK                                                    (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_RX_SYNC_WIN_SIZE_CTL_IPMAC_RX_SYNC_WIN_SIZE_2M_SHIFT                                                   (16)


#define IPMAC_REG_RX_SYNC_WIN_SIZE_LR                                                                                    (IPMAC_REG_BASE + 0x86c)
#define IPMAC_REG_RX_SYNC_WIN_SIZE_LR_DEFAULT                                                                            0x10
#define IPMAC_REG_RX_SYNC_WIN_SIZE_LR_CTL_IPMAC_RX_SYNC_WIN_SIZE_LR                                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_RX_SYNC_WIN_SIZE_LR_CTL_IPMAC_RX_SYNC_WIN_SIZE_LR_MASK                                                 (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_RX_SYNC_WIN_SIZE_LR_CTL_IPMAC_RX_SYNC_WIN_SIZE_LR_SHIFT                                                (0)


#define IPMAC_REG_MSTR_BCN_TX_STS                                                                                        (IPMAC_REG_BASE + 0x940)
#define IPMAC_REG_MSTR_BCN_TX_STS_DEFAULT                                                                                0x0
#define IPMAC_REG_MSTR_BCN_TX_STS_STS_IPMAC_MSTR_TMP_BCA_PDULEN_TX                                                       (Bit0)
#define IPMAC_REG_MSTR_BCN_TX_STS_STS_IPMAC_MSTR_TMP_BC_PDULEN_TX                                                        (Bit1)
#define IPMAC_REG_MSTR_BCN_TX_STS_STS_IPMAC_MSTR_TMP_SLV_PDULEN_TX                                                       (Bit2)
#define IPMAC_REG_MSTR_BCN_TX_STS_STS_IPMAC_MSTR_TMP_SLV_PDULEN_IDX                                                      (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10)
#define IPMAC_REG_MSTR_BCN_TX_STS_STS_IPMAC_MSTR_TMP_SLV_PDULEN_IDX_MASK                                                 (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_MSTR_BCN_TX_STS_STS_IPMAC_MSTR_TMP_SLV_PDULEN_IDX_SHIFT                                                (4)
#define IPMAC_REG_MSTR_BCN_TX_STS_STS_IPMAC_MSTR_TMP_BCA_PDU_TX                                                          (Bit12)
#define IPMAC_REG_MSTR_BCN_TX_STS_STS_IPMAC_MSTR_TMP_BC_PDU_TX                                                           (Bit13)
#define IPMAC_REG_MSTR_BCN_TX_STS_STS_IPMAC_MSTR_TMP_SLV_PDU_TX                                                          (Bit14)
#define IPMAC_REG_MSTR_BCN_TX_STS_STS_IPMAC_MSTR_TMP_SLV_PDU_IDX                                                         (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22)
#define IPMAC_REG_MSTR_BCN_TX_STS_STS_IPMAC_MSTR_TMP_SLV_PDU_IDX_MASK                                                    (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_MSTR_BCN_TX_STS_STS_IPMAC_MSTR_TMP_SLV_PDU_IDX_SHIFT                                                   (16)
#define IPMAC_REG_MSTR_BCN_TX_STS_STS_IPMAC_MSTR_TMP_TX_DONE                                                             (Bit28)


#define IPMAC_REG_MSTR_BCN_RX_STS                                                                                        (IPMAC_REG_BASE + 0x948)
#define IPMAC_REG_MSTR_BCN_RX_STS_DEFAULT                                                                                0x0
#define IPMAC_REG_MSTR_BCN_RX_STS_STS_IPMAC_MSTR_TMP_RX_CI                                                               (Bit0)
#define IPMAC_REG_MSTR_BCN_RX_STS_STS_IPMAC_MSTR_TMP_RX_RSSI                                                             (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define IPMAC_REG_MSTR_BCN_RX_STS_STS_IPMAC_MSTR_TMP_RX_RSSI_MASK                                                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_MSTR_BCN_RX_STS_STS_IPMAC_MSTR_TMP_RX_RSSI_SHIFT                                                       (4)
#define IPMAC_REG_MSTR_BCN_RX_STS_STS_IPMAC_MSTR_TMP_RX_TERM1                                                            (Bit12+Bit13+Bit14)
#define IPMAC_REG_MSTR_BCN_RX_STS_STS_IPMAC_MSTR_TMP_RX_TERM1_MASK                                                       (Bit2+Bit1+Bit0)
#define IPMAC_REG_MSTR_BCN_RX_STS_STS_IPMAC_MSTR_TMP_RX_TERM1_SHIFT                                                      (12)
#define IPMAC_REG_MSTR_BCN_RX_STS_STS_IPMAC_MSTR_TMP_RX_TERM2                                                            (Bit16+Bit17+Bit18)
#define IPMAC_REG_MSTR_BCN_RX_STS_STS_IPMAC_MSTR_TMP_RX_TERM2_MASK                                                       (Bit2+Bit1+Bit0)
#define IPMAC_REG_MSTR_BCN_RX_STS_STS_IPMAC_MSTR_TMP_RX_TERM2_SHIFT                                                      (16)
#define IPMAC_REG_MSTR_BCN_RX_STS_STS_IPMAC_MSTR_TMP_RX_PKT_TYPE                                                         (Bit20)
#define IPMAC_REG_MSTR_BCN_RX_STS_STS_IPMAC_MSTR_TMP_RX_REQ_EXTRA_NON_PRIVATE                                            (Bit26)
#define IPMAC_REG_MSTR_BCN_RX_STS_STS_IPMAC_MSTR_TMP_RX_REQ_EXTRA_PRIVATE                                                (Bit27)


#define IPMAC_REG_MSTR_BCN_RX_STS2                                                                                       (IPMAC_REG_BASE + 0x94c)
#define IPMAC_REG_MSTR_BCN_RX_STS2_DEFAULT                                                                               0x0
#define IPMAC_REG_MSTR_BCN_RX_STS2_STS_IPMAC_MSTR_TMP_RX_LLID                                                            (Bit8+Bit9)
#define IPMAC_REG_MSTR_BCN_RX_STS2_STS_IPMAC_MSTR_TMP_RX_LLID_MASK                                                       (Bit1+Bit0)
#define IPMAC_REG_MSTR_BCN_RX_STS2_STS_IPMAC_MSTR_TMP_RX_LLID_SHIFT                                                      (8)
#define IPMAC_REG_MSTR_BCN_RX_STS2_STS_IPMAC_MSTR_TMP_RX_RSV0                                                            (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18)
#define IPMAC_REG_MSTR_BCN_RX_STS2_STS_IPMAC_MSTR_TMP_RX_RSV0_MASK                                                       (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_MSTR_BCN_RX_STS2_STS_IPMAC_MSTR_TMP_RX_RSV0_SHIFT                                                      (12)
#define IPMAC_REG_MSTR_BCN_RX_STS2_STS_IPMAC_MSTR_TMP_RX_RSV1                                                            (Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_MSTR_BCN_RX_STS2_STS_IPMAC_MSTR_TMP_RX_RSV1_MASK                                                       (Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_MSTR_BCN_RX_STS2_STS_IPMAC_MSTR_TMP_RX_RSV1_SHIFT                                                      (20)
#define IPMAC_REG_MSTR_BCN_RX_STS2_STS_IPMAC_MSTR_TMP_RX_SYNC_FOUND                                                      (Bit24)


#define IPMAC_REG_MSTR_BCN_RX_STS3                                                                                       (IPMAC_REG_BASE + 0x950)
#define IPMAC_REG_MSTR_BCN_RX_STS3_DEFAULT                                                                               0x0
#define IPMAC_REG_MSTR_BCN_RX_STS3_STS_IPMAC_MSTR_TMP_HEADER_CRC_ERR                                                     (Bit12)
#define IPMAC_REG_MSTR_BCN_RX_STS3_STS_IPMAC_MSTR_TMP_PAYLOAD_CRC_ERR                                                    (Bit13)
#define IPMAC_REG_MSTR_BCN_RX_STS3_STS_IPMAC_MSTR_TMP_RX_SYNC_ERR                                                        (Bit14)
#define IPMAC_REG_MSTR_BCN_RX_STS3_STS_IPMAC_MSTR_TMP_RX_ERR                                                             (Bit15)
#define IPMAC_REG_MSTR_BCN_RX_STS3_STS_IPMAC_MSTR_TMP_RX_DONE                                                            (Bit16)


#define IPMAC_REG_SLV_RESP_RX_CTL                                                                                        (IPMAC_REG_BASE + 0x964)
#define IPMAC_REG_SLV_RESP_RX_CTL_DEFAULT                                                                                0x0
#define IPMAC_REG_SLV_RESP_RX_CTL_CTL_IPMAC_SLV_RESP_RX_PKT_ADDR                                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define IPMAC_REG_SLV_RESP_RX_CTL_CTL_IPMAC_SLV_RESP_RX_PKT_ADDR_MASK                                                    (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_RESP_RX_CTL_CTL_IPMAC_SLV_RESP_RX_PKT_ADDR_SHIFT                                                   (0)


#define IPMAC_REG_SLV_RESP_RX_STS                                                                                        (IPMAC_REG_BASE + 0x980)
#define IPMAC_REG_SLV_RESP_RX_STS_DEFAULT                                                                                0x0
#define IPMAC_REG_SLV_RESP_RX_STS_STS_IPMAC_SLV_TMP_RESP_RX_CI                                                           (Bit0)
#define IPMAC_REG_SLV_RESP_RX_STS_STS_IPMAC_SLV_TMP_RESP_RX_RSSI                                                         (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define IPMAC_REG_SLV_RESP_RX_STS_STS_IPMAC_SLV_TMP_RESP_RX_RSSI_MASK                                                    (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_RESP_RX_STS_STS_IPMAC_SLV_TMP_RESP_RX_RSSI_SHIFT                                                   (4)
#define IPMAC_REG_SLV_RESP_RX_STS_STS_IPMAC_SLV_TMP_RESP_RX_TERM1                                                        (Bit12+Bit13+Bit14)
#define IPMAC_REG_SLV_RESP_RX_STS_STS_IPMAC_SLV_TMP_RESP_RX_TERM1_MASK                                                   (Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_RESP_RX_STS_STS_IPMAC_SLV_TMP_RESP_RX_TERM1_SHIFT                                                  (12)
#define IPMAC_REG_SLV_RESP_RX_STS_STS_IPMAC_SLV_TMP_RESP_RX_TERM2                                                        (Bit16+Bit17+Bit18)
#define IPMAC_REG_SLV_RESP_RX_STS_STS_IPMAC_SLV_TMP_RESP_RX_TERM2_MASK                                                   (Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_RESP_RX_STS_STS_IPMAC_SLV_TMP_RESP_RX_TERM2_SHIFT                                                  (16)
#define IPMAC_REG_SLV_RESP_RX_STS_STS_IPMAC_SLV_TMP_RESP_RX_PKT_TYPE                                                     (Bit20)
#define IPMAC_REG_SLV_RESP_RX_STS_STS_IPMAC_SLV_TMP_RESP_RX_SLV_IDX                                                      (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30)
#define IPMAC_REG_SLV_RESP_RX_STS_STS_IPMAC_SLV_TMP_RESP_RX_SLV_IDX_MASK                                                 (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_RESP_RX_STS_STS_IPMAC_SLV_TMP_RESP_RX_SLV_IDX_SHIFT                                                (24)


#define IPMAC_REG_SLV_RESP_RX_STS2                                                                                       (IPMAC_REG_BASE + 0x984)
#define IPMAC_REG_SLV_RESP_RX_STS2_DEFAULT                                                                               0x0
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_EXTRA                                                       (Bit0)
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_EXTRA_PRIVATE                                               (Bit1)
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_NESN                                                        (Bit2)
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_SN                                                          (Bit3)
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_NESN_BCA                                                    (Bit4)
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_REQ_EXTRA_NON_PRIVATE                                       (Bit5)
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_REQ_EXTRA_PRIVATE                                           (Bit6)
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_SYNC_FOUND                                                  (Bit7)
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_LLID                                                        (Bit8+Bit9)
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_LLID_MASK                                                   (Bit1+Bit0)
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_LLID_SHIFT                                                  (8)
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_RSV0                                                        (Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26)
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_RSV0_MASK                                                   (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_RSV0_SHIFT                                                  (20)
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_RSV1                                                        (Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_RSV1_MASK                                                   (Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_RESP_RX_STS2_STS_IPMAC_SLV_TMP_RESP_RX_RSV1_SHIFT                                                  (28)


#define IPMAC_REG_SLV_RESP_RX_STS3                                                                                       (IPMAC_REG_BASE + 0x988)
#define IPMAC_REG_SLV_RESP_RX_STS3_DEFAULT                                                                               0x0
#define IPMAC_REG_SLV_RESP_RX_STS3_STS_IPMAC_SLV_TMP_RESP_RX_PAYLOAD_LEN                                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define IPMAC_REG_SLV_RESP_RX_STS3_STS_IPMAC_SLV_TMP_RESP_RX_PAYLOAD_LEN_MASK                                            (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_RESP_RX_STS3_STS_IPMAC_SLV_TMP_RESP_RX_PAYLOAD_LEN_SHIFT                                           (0)


#define IPMAC_REG_SLV_BCN_RX_STS                                                                                         (IPMAC_REG_BASE + 0x990)
#define IPMAC_REG_SLV_BCN_RX_STS_DEFAULT                                                                                 0x0
#define IPMAC_REG_SLV_BCN_RX_STS_STS_IPMAC_SLV_TMP_BCN_RX_CI                                                             (Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS_STS_IPMAC_SLV_TMP_BCN_RX_RSSI                                                           (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define IPMAC_REG_SLV_BCN_RX_STS_STS_IPMAC_SLV_TMP_BCN_RX_RSSI_MASK                                                      (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS_STS_IPMAC_SLV_TMP_BCN_RX_RSSI_SHIFT                                                     (4)
#define IPMAC_REG_SLV_BCN_RX_STS_STS_IPMAC_SLV_TMP_BCN_RX_TERM1                                                          (Bit12+Bit13+Bit14)
#define IPMAC_REG_SLV_BCN_RX_STS_STS_IPMAC_SLV_TMP_BCN_RX_TERM1_MASK                                                     (Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS_STS_IPMAC_SLV_TMP_BCN_RX_TERM1_SHIFT                                                    (12)
#define IPMAC_REG_SLV_BCN_RX_STS_STS_IPMAC_SLV_TMP_BCN_RX_TERM2                                                          (Bit16+Bit17+Bit18)
#define IPMAC_REG_SLV_BCN_RX_STS_STS_IPMAC_SLV_TMP_BCN_RX_TERM2_MASK                                                     (Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS_STS_IPMAC_SLV_TMP_BCN_RX_TERM2_SHIFT                                                    (16)
#define IPMAC_REG_SLV_BCN_RX_STS_STS_IPMAC_SLV_TMP_BCN_PKT_TYPE                                                          (Bit20)
#define IPMAC_REG_SLV_BCN_RX_STS_STS_IPMAC_SLV_TMP_BCN_NUM_SLV                                                           (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30)
#define IPMAC_REG_SLV_BCN_RX_STS_STS_IPMAC_SLV_TMP_BCN_NUM_SLV_MASK                                                      (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS_STS_IPMAC_SLV_TMP_BCN_NUM_SLV_SHIFT                                                     (24)


#define IPMAC_REG_SLV_BCN_RX_STS2                                                                                        (IPMAC_REG_BASE + 0x994)
#define IPMAC_REG_SLV_BCN_RX_STS2_DEFAULT                                                                                0x0
#define IPMAC_REG_SLV_BCN_RX_STS2_STS_IPMAC_SLV_TMP_BCN_SF_CNT                                                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define IPMAC_REG_SLV_BCN_RX_STS2_STS_IPMAC_SLV_TMP_BCN_SF_CNT_MASK                                                      (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS2_STS_IPMAC_SLV_TMP_BCN_SF_CNT_SHIFT                                                     (0)
#define IPMAC_REG_SLV_BCN_RX_STS2_STS_IPMAC_SLV_TMP_BCN_SF_DURATION                                                      (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22)
#define IPMAC_REG_SLV_BCN_RX_STS2_STS_IPMAC_SLV_TMP_BCN_SF_DURATION_MASK                                                 (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS2_STS_IPMAC_SLV_TMP_BCN_SF_DURATION_SHIFT                                                (8)
#define IPMAC_REG_SLV_BCN_RX_STS2_STS_IPMAC_SLV_TMP_BCN_EMERG_BIT                                                        (Bit24)
#define IPMAC_REG_SLV_BCN_RX_STS2_STS_IPMAC_SLV_TMP_BCN_BCA_PRESENT                                                      (Bit25)
#define IPMAC_REG_SLV_BCN_RX_STS2_STS_IPMAC_SLV_TMP_BCN_BC_PRESENT                                                       (Bit26)
#define IPMAC_REG_SLV_BCN_RX_STS2_STS_IPMAC_SLV_TMP_BCN_NESN_P                                                           (Bit27)


#define IPMAC_REG_SLV_BCN_RX_STS3                                                                                        (IPMAC_REG_BASE + 0x998)
#define IPMAC_REG_SLV_BCN_RX_STS3_DEFAULT                                                                                0x0
#define IPMAC_REG_SLV_BCN_RX_STS3_STS_IPMAC_SLV_TMP_BCN_EXTRA_PRESENT                                                    (Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS3_STS_IPMAC_SLV_TMP_BCN_EXTRA_PRIVATE                                                    (Bit1)
#define IPMAC_REG_SLV_BCN_RX_STS3_STS_IPMAC_SLV_TMP_BCN_EXTRA_SLV_IDX                                                    (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10)
#define IPMAC_REG_SLV_BCN_RX_STS3_STS_IPMAC_SLV_TMP_BCN_EXTRA_SLV_IDX_MASK                                               (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS3_STS_IPMAC_SLV_TMP_BCN_EXTRA_SLV_IDX_SHIFT                                              (4)
#define IPMAC_REG_SLV_BCN_RX_STS3_STS_IPMAC_SLV_TMP_BCN_EXTRA_RATE                                                       (Bit12+Bit13)
#define IPMAC_REG_SLV_BCN_RX_STS3_STS_IPMAC_SLV_TMP_BCN_EXTRA_RATE_MASK                                                  (Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS3_STS_IPMAC_SLV_TMP_BCN_EXTRA_RATE_SHIFT                                                 (12)


#define IPMAC_REG_SLV_BCN_RX_STS4                                                                                        (IPMAC_REG_BASE + 0x9b0)
#define IPMAC_REG_SLV_BCN_RX_STS4_DEFAULT                                                                                0x0
#define IPMAC_REG_SLV_BCN_RX_STS4_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_PRESENT_VALID                                            (Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS4_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_PRESENT                                                  (Bit1)
#define IPMAC_REG_SLV_BCN_RX_STS4_STS_IPMAC_SLV_TMP_BCN_NESN_VALID                                                       (Bit2)
#define IPMAC_REG_SLV_BCN_RX_STS4_STS_IPMAC_SLV_TMP_BCN_NESN                                                             (Bit3)
#define IPMAC_REG_SLV_BCN_RX_STS4_STS_IPMAC_SLV_TMP_BCN_BCA_PDU_LEN                                                      (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define IPMAC_REG_SLV_BCN_RX_STS4_STS_IPMAC_SLV_TMP_BCN_BCA_PDU_LEN_MASK                                                 (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS4_STS_IPMAC_SLV_TMP_BCN_BCA_PDU_LEN_SHIFT                                                (4)
#define IPMAC_REG_SLV_BCN_RX_STS4_STS_IPMAC_SLV_TMP_BCN_BCA_PDU_LEN_VALID                                                (Bit16)
#define IPMAC_REG_SLV_BCN_RX_STS4_STS_IPMAC_SLV_TMP_BCN_BC_PDU_LEN                                                       (Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define IPMAC_REG_SLV_BCN_RX_STS4_STS_IPMAC_SLV_TMP_BCN_BC_PDU_LEN_MASK                                                  (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS4_STS_IPMAC_SLV_TMP_BCN_BC_PDU_LEN_SHIFT                                                 (20)
#define IPMAC_REG_SLV_BCN_RX_STS4_STS_IPMAC_SLV_TMP_BCN_BC_PDU_LEN_VALID                                                 (Bit30)


#define IPMAC_REG_SLV_BCN_RX_STS5                                                                                        (IPMAC_REG_BASE + 0x9b4)
#define IPMAC_REG_SLV_BCN_RX_STS5_DEFAULT                                                                                0x0
#define IPMAC_REG_SLV_BCN_RX_STS5_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_LEN                                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define IPMAC_REG_SLV_BCN_RX_STS5_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_LEN_MASK                                                 (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS5_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_LEN_SHIFT                                                (0)
#define IPMAC_REG_SLV_BCN_RX_STS5_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_LEN_VALID                                                (Bit12)


#define IPMAC_REG_SLV_BCN_RX_STS6                                                                                        (IPMAC_REG_BASE + 0x9c0)
#define IPMAC_REG_SLV_BCN_RX_STS6_DEFAULT                                                                                0x0
#define IPMAC_REG_SLV_BCN_RX_STS6_STS_IPMAC_SLV_TMP_BCN_BCA_PDULEN_RX                                                    (Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS6_STS_IPMAC_SLV_TMP_BCN_BC_PDULEN_RX                                                     (Bit1)
#define IPMAC_REG_SLV_BCN_RX_STS6_STS_IPMAC_SLV_TMP_BCN_SLV_PDULEN_RX                                                    (Bit2)
#define IPMAC_REG_SLV_BCN_RX_STS6_STS_IPMAC_SLV_TMP_BCN_BCA_PDU_RX                                                       (Bit3)
#define IPMAC_REG_SLV_BCN_RX_STS6_STS_IPMAC_SLV_TMP_BCN_BC_PDU_RX                                                        (Bit4)
#define IPMAC_REG_SLV_BCN_RX_STS6_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_RX                                                       (Bit5)
#define IPMAC_REG_SLV_BCN_RX_STS6_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_LOC_IDX                                                  (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define IPMAC_REG_SLV_BCN_RX_STS6_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_LOC_IDX_MASK                                             (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS6_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_LOC_IDX_SHIFT                                            (8)


#define IPMAC_REG_SLV_BCN_RX_STS7                                                                                        (IPMAC_REG_BASE + 0x9c4)
#define IPMAC_REG_SLV_BCN_RX_STS7_DEFAULT                                                                                0x0
#define IPMAC_REG_SLV_BCN_RX_STS7_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_NUM_BIT_SKIP                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18)
#define IPMAC_REG_SLV_BCN_RX_STS7_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_NUM_BIT_SKIP_MASK                                        (Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS7_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_NUM_BIT_SKIP_SHIFT                                       (0)


#define IPMAC_REG_SLV_BCN_RX_STS8                                                                                        (IPMAC_REG_BASE + 0x9c8)
#define IPMAC_REG_SLV_BCN_RX_STS8_DEFAULT                                                                                0x0
#define IPMAC_REG_SLV_BCN_RX_STS8_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_NUM_BIT_SKIP_POST                                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18)
#define IPMAC_REG_SLV_BCN_RX_STS8_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_NUM_BIT_SKIP_POST_MASK                                   (Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_STS8_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_NUM_BIT_SKIP_POST_SHIFT                                  (0)


#define IPMAC_REG_SLV_BCN_RX_BCA_PDU_HEAD                                                                                (IPMAC_REG_BASE + 0x9d0)
#define IPMAC_REG_SLV_BCN_RX_BCA_PDU_HEAD_DEFAULT                                                                        0x0
#define IPMAC_REG_SLV_BCN_RX_BCA_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_BCA_PDU_LLID                                             (Bit0+Bit1)
#define IPMAC_REG_SLV_BCN_RX_BCA_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_BCA_PDU_LLID_MASK                                        (Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_BCA_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_BCA_PDU_LLID_SHIFT                                       (0)
#define IPMAC_REG_SLV_BCN_RX_BCA_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_BCA_PDU_SN                                               (Bit4)
#define IPMAC_REG_SLV_BCN_RX_BCA_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_BCA_PDU_RSV                                              (Bit8+Bit9+Bit10+Bit11+Bit12)
#define IPMAC_REG_SLV_BCN_RX_BCA_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_BCA_PDU_RSV_MASK                                         (Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_BCA_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_BCA_PDU_RSV_SHIFT                                        (8)


#define IPMAC_REG_SLV_BCN_RX_BC_PDU_HEAD                                                                                 (IPMAC_REG_BASE + 0x9d4)
#define IPMAC_REG_SLV_BCN_RX_BC_PDU_HEAD_DEFAULT                                                                         0x0
#define IPMAC_REG_SLV_BCN_RX_BC_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_BC_PDU_LLID                                               (Bit0+Bit1)
#define IPMAC_REG_SLV_BCN_RX_BC_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_BC_PDU_LLID_MASK                                          (Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_BC_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_BC_PDU_LLID_SHIFT                                         (0)
#define IPMAC_REG_SLV_BCN_RX_BC_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_BC_PDU_SN                                                 (Bit4)
#define IPMAC_REG_SLV_BCN_RX_BC_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_BC_PDU_RSV                                                (Bit8+Bit9+Bit10+Bit11+Bit12)
#define IPMAC_REG_SLV_BCN_RX_BC_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_BC_PDU_RSV_MASK                                           (Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_BC_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_BC_PDU_RSV_SHIFT                                          (8)


#define IPMAC_REG_SLV_BCN_RX_SLV_PDU_HEAD                                                                                (IPMAC_REG_BASE + 0x9d8)
#define IPMAC_REG_SLV_BCN_RX_SLV_PDU_HEAD_DEFAULT                                                                        0x0
#define IPMAC_REG_SLV_BCN_RX_SLV_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_LLID                                             (Bit0+Bit1)
#define IPMAC_REG_SLV_BCN_RX_SLV_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_LLID_MASK                                        (Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_SLV_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_LLID_SHIFT                                       (0)
#define IPMAC_REG_SLV_BCN_RX_SLV_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_SN                                               (Bit4)
#define IPMAC_REG_SLV_BCN_RX_SLV_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_RSV                                              (Bit8+Bit9+Bit10+Bit11+Bit12)
#define IPMAC_REG_SLV_BCN_RX_SLV_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_RSV_MASK                                         (Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_SLV_BCN_RX_SLV_PDU_HEAD_STS_IPMAC_SLV_TMP_BCN_SLV_PDU_RSV_SHIFT                                        (8)


#define IPMAC_REG_SLV_BCN_RX_ERR_DONE                                                                                    (IPMAC_REG_BASE + 0x9e0)
#define IPMAC_REG_SLV_BCN_RX_ERR_DONE_DEFAULT                                                                            0x0
#define IPMAC_REG_SLV_BCN_RX_ERR_DONE_STS_IPMAC_SLV_TMP_BCN_RX_HEADER_CRC_ERR                                            (Bit0)
#define IPMAC_REG_SLV_BCN_RX_ERR_DONE_STS_IPMAC_SLV_TMP_BCN_RX_LENPDU_CRC_ERR                                            (Bit1)
#define IPMAC_REG_SLV_BCN_RX_ERR_DONE_STS_IPMAC_SLV_TMP_BCN_RX_BCA_CRC_ERR                                               (Bit2)
#define IPMAC_REG_SLV_BCN_RX_ERR_DONE_STS_IPMAC_SLV_TMP_BCN_RX_BC_CRC_ERR                                                (Bit3)
#define IPMAC_REG_SLV_BCN_RX_ERR_DONE_STS_IPMAC_SLV_TMP_BCN_RX_SLV_CRC_ERR                                               (Bit4)
#define IPMAC_REG_SLV_BCN_RX_ERR_DONE_STS_IPMAC_SLV_TMP_RESP_RX_HEADER_CRC_ERR                                           (Bit5)
#define IPMAC_REG_SLV_BCN_RX_ERR_DONE_STS_IPMAC_SLV_TMP_RESP_RX_PAYLOAD_CRC_ERR                                          (Bit6)
#define IPMAC_REG_SLV_BCN_RX_ERR_DONE_STS_IPMAC_SLV_TMP_RESP_RX_ERR                                                      (Bit7)
#define IPMAC_REG_SLV_BCN_RX_ERR_DONE_STS_IPMAC_SLV_TMP_RESP_RX_SYNC_ERR                                                 (Bit8)
#define IPMAC_REG_SLV_BCN_RX_ERR_DONE_STS_IPMAC_SLV_TMP_RESP_RX_DONE                                                     (Bit9)
#define IPMAC_REG_SLV_BCN_RX_ERR_DONE_STS_IPMAC_SLV_TMP_TX_ERR                                                           (Bit12)
#define IPMAC_REG_SLV_BCN_RX_ERR_DONE_STS_IPMAC_SLV_TMP_TX_DONE                                                          (Bit13)


#define IPMAC_REG_TRX_STS                                                                                                (IPMAC_REG_BASE + 0xa00)
#define IPMAC_REG_TRX_STS_DEFAULT                                                                                        0x0
#define IPMAC_REG_TRX_STS_STS_IPMAC_TMP_TX_EN                                                                            (Bit0)
#define IPMAC_REG_TRX_STS_STS_IPMAC_TMP_RX_EN                                                                            (Bit1)
#define IPMAC_REG_TRX_STS_STS_IPMAC_TMP_TX_DATA                                                                          (Bit2)
#define IPMAC_REG_TRX_STS_STS_IPMAC_TMP_TX_DATA_EN                                                                       (Bit3)
#define IPMAC_REG_TRX_STS_STS_IPMAC_TMP_RATE                                                                             (Bit4+Bit5)
#define IPMAC_REG_TRX_STS_STS_IPMAC_TMP_RATE_MASK                                                                        (Bit1+Bit0)
#define IPMAC_REG_TRX_STS_STS_IPMAC_TMP_RATE_SHIFT                                                                       (4)


#define IPMAC_REG_TRX_STS_SYNC_WORD                                                                                      (IPMAC_REG_BASE + 0xa04)
#define IPMAC_REG_TRX_STS_SYNC_WORD_DEFAULT                                                                              0x0
#define IPMAC_REG_TRX_STS_SYNC_WORD_STS_IPMAC_TMP_SYNC_WORD                                                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_TRX_STS_SYNC_WORD_STS_IPMAC_TMP_SYNC_WORD_MASK                                                         (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_TRX_STS_SYNC_WORD_STS_IPMAC_TMP_SYNC_WORD_SHIFT                                                        (0)


#define IPMAC_REG_FREQ_SEL_CTL0                                                                                          (IPMAC_REG_BASE + 0xa10)
#define IPMAC_REG_FREQ_SEL_CTL0_DEFAULT                                                                                  0x0
#define IPMAC_REG_FREQ_SEL_CTL0_CTL_IPMAC_FREQ_WORD_AUX_CH_IDX                                                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define IPMAC_REG_FREQ_SEL_CTL0_CTL_IPMAC_FREQ_WORD_AUX_CH_IDX_MASK                                                      (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_SEL_CTL0_CTL_IPMAC_FREQ_WORD_AUX_CH_IDX_SHIFT                                                     (0)
#define IPMAC_REG_FREQ_SEL_CTL0_CTL_IPMAC_FREQ_SEL_HOPINT                                                                (Bit8+Bit9+Bit10+Bit11+Bit12)
#define IPMAC_REG_FREQ_SEL_CTL0_CTL_IPMAC_FREQ_SEL_HOPINT_MASK                                                           (Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_SEL_CTL0_CTL_IPMAC_FREQ_SEL_HOPINT_SHIFT                                                          (8)
#define IPMAC_REG_FREQ_SEL_CTL0_CTL_IPMAC_FREQ_SEL_HOP_SEL                                                               (Bit16)
#define IPMAC_REG_FREQ_SEL_CTL0_CTL_IPMAC_FREQ_SEL_CS_FORMAT                                                             (Bit20+Bit21+Bit22+Bit23+Bit24)
#define IPMAC_REG_FREQ_SEL_CTL0_CTL_IPMAC_FREQ_SEL_CS_FORMAT_MASK                                                        (Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_SEL_CTL0_CTL_IPMAC_FREQ_SEL_CS_FORMAT_SHIFT                                                       (20)
#define IPMAC_REG_FREQ_SEL_CTL0_CTL_IPMAC_FREQ_SEL_FH_EN                                                                 (Bit28)


#define IPMAC_REG_FREQ_SEL_CTL1                                                                                          (IPMAC_REG_BASE + 0xa14)
#define IPMAC_REG_FREQ_SEL_CTL1_DEFAULT                                                                                  0x0
#define IPMAC_REG_FREQ_SEL_CTL1_CTL_IPMAC_FREQ_SEL_LLCHMAP_LSB                                                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_SEL_CTL1_CTL_IPMAC_FREQ_SEL_LLCHMAP_LSB_MASK                                                      (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_SEL_CTL1_CTL_IPMAC_FREQ_SEL_LLCHMAP_LSB_SHIFT                                                     (0)


#define IPMAC_REG_FREQ_SEL_CTL2                                                                                          (IPMAC_REG_BASE + 0xa18)
#define IPMAC_REG_FREQ_SEL_CTL2_DEFAULT                                                                                  0x0
#define IPMAC_REG_FREQ_SEL_CTL2_CTL_IPMAC_FREQ_SEL_LLCHMAP_MSB                                                           (Bit0+Bit1+Bit2+Bit3+Bit4)
#define IPMAC_REG_FREQ_SEL_CTL2_CTL_IPMAC_FREQ_SEL_LLCHMAP_MSB_MASK                                                      (Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_SEL_CTL2_CTL_IPMAC_FREQ_SEL_LLCHMAP_MSB_SHIFT                                                     (0)
#define IPMAC_REG_FREQ_SEL_CTL2_CTL_IPMAC_FREQ_SEL_HOP_REMAP_DSB                                                         (Bit8)
#define IPMAC_REG_FREQ_SEL_CTL2_CTL_IPMAC_FREQ_SEL_ADVCHMAP                                                              (Bit12+Bit13+Bit14)
#define IPMAC_REG_FREQ_SEL_CTL2_CTL_IPMAC_FREQ_SEL_ADVCHMAP_MASK                                                         (Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_SEL_CTL2_CTL_IPMAC_FREQ_SEL_ADVCHMAP_SHIFT                                                        (12)


#define IPMAC_REG_FREQ_SEL_STS                                                                                           (IPMAC_REG_BASE + 0xa20)
#define IPMAC_REG_FREQ_SEL_STS_DEFAULT                                                                                   0x0
#define IPMAC_REG_FREQ_SEL_STS_STS_IPMAC_TMP_FREQ_WORD                                                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6)
#define IPMAC_REG_FREQ_SEL_STS_STS_IPMAC_TMP_FREQ_WORD_MASK                                                              (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_SEL_STS_STS_IPMAC_TMP_FREQ_WORD_SHIFT                                                             (0)
#define IPMAC_REG_FREQ_SEL_STS_STS_IPMAC_TMP_FREQ_BAND                                                                   (Bit8)


#define IPMAC_REG_FREQ_WORD_BAND_0123                                                                                    (IPMAC_REG_BASE + 0xa40)
#define IPMAC_REG_FREQ_WORD_BAND_0123_DEFAULT                                                                            0x0
#define IPMAC_REG_FREQ_WORD_BAND_0123_BAND0                                                                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_FREQ_WORD_BAND_0123_BAND0_MASK                                                                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_0123_BAND0_SHIFT                                                                        (0)
#define IPMAC_REG_FREQ_WORD_BAND_0123_BAND1                                                                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_FREQ_WORD_BAND_0123_BAND1_MASK                                                                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_0123_BAND1_SHIFT                                                                        (8)
#define IPMAC_REG_FREQ_WORD_BAND_0123_BAND2                                                                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_FREQ_WORD_BAND_0123_BAND2_MASK                                                                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_0123_BAND2_SHIFT                                                                        (16)
#define IPMAC_REG_FREQ_WORD_BAND_0123_BAND3                                                                              (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_WORD_BAND_0123_BAND3_MASK                                                                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_0123_BAND3_SHIFT                                                                        (24)


#define IPMAC_REG_FREQ_WORD_BAND_4567                                                                                    (IPMAC_REG_BASE + 0xa44)
#define IPMAC_REG_FREQ_WORD_BAND_4567_DEFAULT                                                                            0x0
#define IPMAC_REG_FREQ_WORD_BAND_4567_BAND0                                                                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_FREQ_WORD_BAND_4567_BAND0_MASK                                                                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_4567_BAND0_SHIFT                                                                        (0)
#define IPMAC_REG_FREQ_WORD_BAND_4567_BAND1                                                                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_FREQ_WORD_BAND_4567_BAND1_MASK                                                                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_4567_BAND1_SHIFT                                                                        (8)
#define IPMAC_REG_FREQ_WORD_BAND_4567_BAND2                                                                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_FREQ_WORD_BAND_4567_BAND2_MASK                                                                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_4567_BAND2_SHIFT                                                                        (16)
#define IPMAC_REG_FREQ_WORD_BAND_4567_BAND3                                                                              (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_WORD_BAND_4567_BAND3_MASK                                                                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_4567_BAND3_SHIFT                                                                        (24)


#define IPMAC_REG_FREQ_WORD_BAND_891011                                                                                  (IPMAC_REG_BASE + 0xa48)
#define IPMAC_REG_FREQ_WORD_BAND_891011_DEFAULT                                                                          0x0
#define IPMAC_REG_FREQ_WORD_BAND_891011_BAND0                                                                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_FREQ_WORD_BAND_891011_BAND0_MASK                                                                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_891011_BAND0_SHIFT                                                                      (0)
#define IPMAC_REG_FREQ_WORD_BAND_891011_BAND1                                                                            (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_FREQ_WORD_BAND_891011_BAND1_MASK                                                                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_891011_BAND1_SHIFT                                                                      (8)
#define IPMAC_REG_FREQ_WORD_BAND_891011_BAND2                                                                            (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_FREQ_WORD_BAND_891011_BAND2_MASK                                                                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_891011_BAND2_SHIFT                                                                      (16)
#define IPMAC_REG_FREQ_WORD_BAND_891011_BAND3                                                                            (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_WORD_BAND_891011_BAND3_MASK                                                                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_891011_BAND3_SHIFT                                                                      (24)


#define IPMAC_REG_FREQ_WORD_BAND_12131415                                                                                (IPMAC_REG_BASE + 0xa4c)
#define IPMAC_REG_FREQ_WORD_BAND_12131415_DEFAULT                                                                        0x0
#define IPMAC_REG_FREQ_WORD_BAND_12131415_BAND0                                                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_FREQ_WORD_BAND_12131415_BAND0_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_12131415_BAND0_SHIFT                                                                    (0)
#define IPMAC_REG_FREQ_WORD_BAND_12131415_BAND1                                                                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_FREQ_WORD_BAND_12131415_BAND1_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_12131415_BAND1_SHIFT                                                                    (8)
#define IPMAC_REG_FREQ_WORD_BAND_12131415_BAND2                                                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_FREQ_WORD_BAND_12131415_BAND2_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_12131415_BAND2_SHIFT                                                                    (16)
#define IPMAC_REG_FREQ_WORD_BAND_12131415_BAND3                                                                          (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_WORD_BAND_12131415_BAND3_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_12131415_BAND3_SHIFT                                                                    (24)


#define IPMAC_REG_FREQ_WORD_BAND_16171819                                                                                (IPMAC_REG_BASE + 0xa50)
#define IPMAC_REG_FREQ_WORD_BAND_16171819_DEFAULT                                                                        0x0
#define IPMAC_REG_FREQ_WORD_BAND_16171819_BAND0                                                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_FREQ_WORD_BAND_16171819_BAND0_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_16171819_BAND0_SHIFT                                                                    (0)
#define IPMAC_REG_FREQ_WORD_BAND_16171819_BAND1                                                                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_FREQ_WORD_BAND_16171819_BAND1_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_16171819_BAND1_SHIFT                                                                    (8)
#define IPMAC_REG_FREQ_WORD_BAND_16171819_BAND2                                                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_FREQ_WORD_BAND_16171819_BAND2_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_16171819_BAND2_SHIFT                                                                    (16)
#define IPMAC_REG_FREQ_WORD_BAND_16171819_BAND3                                                                          (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_WORD_BAND_16171819_BAND3_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_16171819_BAND3_SHIFT                                                                    (24)


#define IPMAC_REG_FREQ_WORD_BAND_20212223                                                                                (IPMAC_REG_BASE + 0xa54)
#define IPMAC_REG_FREQ_WORD_BAND_20212223_DEFAULT                                                                        0x0
#define IPMAC_REG_FREQ_WORD_BAND_20212223_BAND0                                                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_FREQ_WORD_BAND_20212223_BAND0_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_20212223_BAND0_SHIFT                                                                    (0)
#define IPMAC_REG_FREQ_WORD_BAND_20212223_BAND1                                                                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_FREQ_WORD_BAND_20212223_BAND1_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_20212223_BAND1_SHIFT                                                                    (8)
#define IPMAC_REG_FREQ_WORD_BAND_20212223_BAND2                                                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_FREQ_WORD_BAND_20212223_BAND2_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_20212223_BAND2_SHIFT                                                                    (16)
#define IPMAC_REG_FREQ_WORD_BAND_20212223_BAND3                                                                          (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_WORD_BAND_20212223_BAND3_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_20212223_BAND3_SHIFT                                                                    (24)


#define IPMAC_REG_FREQ_WORD_BAND_24252627                                                                                (IPMAC_REG_BASE + 0xa58)
#define IPMAC_REG_FREQ_WORD_BAND_24252627_DEFAULT                                                                        0x0
#define IPMAC_REG_FREQ_WORD_BAND_24252627_BAND0                                                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_FREQ_WORD_BAND_24252627_BAND0_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_24252627_BAND0_SHIFT                                                                    (0)
#define IPMAC_REG_FREQ_WORD_BAND_24252627_BAND1                                                                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_FREQ_WORD_BAND_24252627_BAND1_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_24252627_BAND1_SHIFT                                                                    (8)
#define IPMAC_REG_FREQ_WORD_BAND_24252627_BAND2                                                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_FREQ_WORD_BAND_24252627_BAND2_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_24252627_BAND2_SHIFT                                                                    (16)
#define IPMAC_REG_FREQ_WORD_BAND_24252627_BAND3                                                                          (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_WORD_BAND_24252627_BAND3_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_24252627_BAND3_SHIFT                                                                    (24)


#define IPMAC_REG_FREQ_WORD_BAND_28293031                                                                                (IPMAC_REG_BASE + 0xa5c)
#define IPMAC_REG_FREQ_WORD_BAND_28293031_DEFAULT                                                                        0x0
#define IPMAC_REG_FREQ_WORD_BAND_28293031_BAND0                                                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_FREQ_WORD_BAND_28293031_BAND0_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_28293031_BAND0_SHIFT                                                                    (0)
#define IPMAC_REG_FREQ_WORD_BAND_28293031_BAND1                                                                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_FREQ_WORD_BAND_28293031_BAND1_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_28293031_BAND1_SHIFT                                                                    (8)
#define IPMAC_REG_FREQ_WORD_BAND_28293031_BAND2                                                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_FREQ_WORD_BAND_28293031_BAND2_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_28293031_BAND2_SHIFT                                                                    (16)
#define IPMAC_REG_FREQ_WORD_BAND_28293031_BAND3                                                                          (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_WORD_BAND_28293031_BAND3_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_28293031_BAND3_SHIFT                                                                    (24)


#define IPMAC_REG_FREQ_WORD_BAND_32333435                                                                                (IPMAC_REG_BASE + 0xa60)
#define IPMAC_REG_FREQ_WORD_BAND_32333435_DEFAULT                                                                        0x0
#define IPMAC_REG_FREQ_WORD_BAND_32333435_BAND0                                                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_FREQ_WORD_BAND_32333435_BAND0_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_32333435_BAND0_SHIFT                                                                    (0)
#define IPMAC_REG_FREQ_WORD_BAND_32333435_BAND1                                                                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_FREQ_WORD_BAND_32333435_BAND1_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_32333435_BAND1_SHIFT                                                                    (8)
#define IPMAC_REG_FREQ_WORD_BAND_32333435_BAND2                                                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_FREQ_WORD_BAND_32333435_BAND2_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_32333435_BAND2_SHIFT                                                                    (16)
#define IPMAC_REG_FREQ_WORD_BAND_32333435_BAND3                                                                          (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_WORD_BAND_32333435_BAND3_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_32333435_BAND3_SHIFT                                                                    (24)


#define IPMAC_REG_FREQ_WORD_BAND_36373839                                                                                (IPMAC_REG_BASE + 0xa64)
#define IPMAC_REG_FREQ_WORD_BAND_36373839_DEFAULT                                                                        0x0
#define IPMAC_REG_FREQ_WORD_BAND_36373839_BAND0                                                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_FREQ_WORD_BAND_36373839_BAND0_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_36373839_BAND0_SHIFT                                                                    (0)
#define IPMAC_REG_FREQ_WORD_BAND_36373839_BAND1                                                                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_FREQ_WORD_BAND_36373839_BAND1_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_36373839_BAND1_SHIFT                                                                    (8)
#define IPMAC_REG_FREQ_WORD_BAND_36373839_BAND2                                                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_FREQ_WORD_BAND_36373839_BAND2_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_36373839_BAND2_SHIFT                                                                    (16)
#define IPMAC_REG_FREQ_WORD_BAND_36373839_BAND3                                                                          (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_WORD_BAND_36373839_BAND3_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_36373839_BAND3_SHIFT                                                                    (24)


#define IPMAC_REG_FREQ_WORD_BAND_40414243                                                                                (IPMAC_REG_BASE + 0xa68)
#define IPMAC_REG_FREQ_WORD_BAND_40414243_DEFAULT                                                                        0x0
#define IPMAC_REG_FREQ_WORD_BAND_40414243_BAND0                                                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_FREQ_WORD_BAND_40414243_BAND0_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_40414243_BAND0_SHIFT                                                                    (0)
#define IPMAC_REG_FREQ_WORD_BAND_40414243_BAND1                                                                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_FREQ_WORD_BAND_40414243_BAND1_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_40414243_BAND1_SHIFT                                                                    (8)
#define IPMAC_REG_FREQ_WORD_BAND_40414243_BAND2                                                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_FREQ_WORD_BAND_40414243_BAND2_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_40414243_BAND2_SHIFT                                                                    (16)
#define IPMAC_REG_FREQ_WORD_BAND_40414243_BAND3                                                                          (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_WORD_BAND_40414243_BAND3_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_40414243_BAND3_SHIFT                                                                    (24)


#define IPMAC_REG_FREQ_WORD_BAND_44454647                                                                                (IPMAC_REG_BASE + 0xa6c)
#define IPMAC_REG_FREQ_WORD_BAND_44454647_DEFAULT                                                                        0x0
#define IPMAC_REG_FREQ_WORD_BAND_44454647_BAND0                                                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_FREQ_WORD_BAND_44454647_BAND0_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_44454647_BAND0_SHIFT                                                                    (0)
#define IPMAC_REG_FREQ_WORD_BAND_44454647_BAND1                                                                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_FREQ_WORD_BAND_44454647_BAND1_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_44454647_BAND1_SHIFT                                                                    (8)
#define IPMAC_REG_FREQ_WORD_BAND_44454647_BAND2                                                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_FREQ_WORD_BAND_44454647_BAND2_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_44454647_BAND2_SHIFT                                                                    (16)
#define IPMAC_REG_FREQ_WORD_BAND_44454647_BAND3                                                                          (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_WORD_BAND_44454647_BAND3_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_44454647_BAND3_SHIFT                                                                    (24)


#define IPMAC_REG_FREQ_WORD_BAND_48495051                                                                                (IPMAC_REG_BASE + 0xa70)
#define IPMAC_REG_FREQ_WORD_BAND_48495051_DEFAULT                                                                        0x0
#define IPMAC_REG_FREQ_WORD_BAND_48495051_BAND0                                                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_FREQ_WORD_BAND_48495051_BAND0_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_48495051_BAND0_SHIFT                                                                    (0)
#define IPMAC_REG_FREQ_WORD_BAND_48495051_BAND1                                                                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_FREQ_WORD_BAND_48495051_BAND1_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_48495051_BAND1_SHIFT                                                                    (8)
#define IPMAC_REG_FREQ_WORD_BAND_48495051_BAND2                                                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_FREQ_WORD_BAND_48495051_BAND2_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_48495051_BAND2_SHIFT                                                                    (16)
#define IPMAC_REG_FREQ_WORD_BAND_48495051_BAND3                                                                          (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_WORD_BAND_48495051_BAND3_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_48495051_BAND3_SHIFT                                                                    (24)


#define IPMAC_REG_FREQ_WORD_BAND_52535455                                                                                (IPMAC_REG_BASE + 0xa74)
#define IPMAC_REG_FREQ_WORD_BAND_52535455_DEFAULT                                                                        0x0
#define IPMAC_REG_FREQ_WORD_BAND_52535455_BAND0                                                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_FREQ_WORD_BAND_52535455_BAND0_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_52535455_BAND0_SHIFT                                                                    (0)
#define IPMAC_REG_FREQ_WORD_BAND_52535455_BAND1                                                                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_FREQ_WORD_BAND_52535455_BAND1_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_52535455_BAND1_SHIFT                                                                    (8)
#define IPMAC_REG_FREQ_WORD_BAND_52535455_BAND2                                                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_FREQ_WORD_BAND_52535455_BAND2_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_52535455_BAND2_SHIFT                                                                    (16)
#define IPMAC_REG_FREQ_WORD_BAND_52535455_BAND3                                                                          (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_WORD_BAND_52535455_BAND3_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_52535455_BAND3_SHIFT                                                                    (24)


#define IPMAC_REG_FREQ_WORD_BAND_56575859                                                                                (IPMAC_REG_BASE + 0xa78)
#define IPMAC_REG_FREQ_WORD_BAND_56575859_DEFAULT                                                                        0x0
#define IPMAC_REG_FREQ_WORD_BAND_56575859_BAND0                                                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_FREQ_WORD_BAND_56575859_BAND0_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_56575859_BAND0_SHIFT                                                                    (0)
#define IPMAC_REG_FREQ_WORD_BAND_56575859_BAND1                                                                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_FREQ_WORD_BAND_56575859_BAND1_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_56575859_BAND1_SHIFT                                                                    (8)
#define IPMAC_REG_FREQ_WORD_BAND_56575859_BAND2                                                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_FREQ_WORD_BAND_56575859_BAND2_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_56575859_BAND2_SHIFT                                                                    (16)
#define IPMAC_REG_FREQ_WORD_BAND_56575859_BAND3                                                                          (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_WORD_BAND_56575859_BAND3_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_56575859_BAND3_SHIFT                                                                    (24)


#define IPMAC_REG_FREQ_WORD_BAND_60616263                                                                                (IPMAC_REG_BASE + 0xa7c)
#define IPMAC_REG_FREQ_WORD_BAND_60616263_DEFAULT                                                                        0x0
#define IPMAC_REG_FREQ_WORD_BAND_60616263_BAND0                                                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define IPMAC_REG_FREQ_WORD_BAND_60616263_BAND0_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_60616263_BAND0_SHIFT                                                                    (0)
#define IPMAC_REG_FREQ_WORD_BAND_60616263_BAND1                                                                          (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define IPMAC_REG_FREQ_WORD_BAND_60616263_BAND1_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_60616263_BAND1_SHIFT                                                                    (8)
#define IPMAC_REG_FREQ_WORD_BAND_60616263_BAND2                                                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define IPMAC_REG_FREQ_WORD_BAND_60616263_BAND2_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_60616263_BAND2_SHIFT                                                                    (16)
#define IPMAC_REG_FREQ_WORD_BAND_60616263_BAND3                                                                          (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define IPMAC_REG_FREQ_WORD_BAND_60616263_BAND3_MASK                                                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define IPMAC_REG_FREQ_WORD_BAND_60616263_BAND3_SHIFT                                                                    (24)


#endif // _IPMAC_REG_DEFINES_H

