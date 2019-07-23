#ifndef _DBGCAPTURE_REG_DEFINES_H
#define _DBGCAPTURE_REG_DEFINES_H
/* **************************** */
#define DBGCAPTURE_REG_INTR_STATUS                                                  (DBGCAPTURE_REG_BASE + 0x0)
#define DBGCAPTURE_REG_INTR_STATUS_DEFAULT                                          0x0
#define DBGCAPTURE_REG_INTR_STATUS_MEM_WR_WRAP                                      (Bit0+Bit1+Bit2+Bit3+Bit4)
#define DBGCAPTURE_REG_INTR_STATUS_MEM_WR_WRAP_MASK                                 (Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_INTR_STATUS_MEM_WR_WRAP_SHIFT                                (0)
#define DBGCAPTURE_REG_INTR_STATUS_TRIGGERED                                        (Bit5+Bit6+Bit7+Bit8+Bit9)
#define DBGCAPTURE_REG_INTR_STATUS_TRIGGERED_MASK                                   (Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_INTR_STATUS_TRIGGERED_SHIFT                                  (5)


#define DBGCAPTURE_REG_INTR_MASK_STATUS                                             (DBGCAPTURE_REG_BASE + 0x4)
#define DBGCAPTURE_REG_INTR_MASK_STATUS_DEFAULT                                     0x0
#define DBGCAPTURE_REG_INTR_MASK_STATUS_MEM_WR_WRAP                                 (Bit0+Bit1+Bit2+Bit3+Bit4)
#define DBGCAPTURE_REG_INTR_MASK_STATUS_MEM_WR_WRAP_MASK                            (Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_INTR_MASK_STATUS_MEM_WR_WRAP_SHIFT                           (0)
#define DBGCAPTURE_REG_INTR_MASK_STATUS_TRIGGERED                                   (Bit5+Bit6+Bit7+Bit8+Bit9)
#define DBGCAPTURE_REG_INTR_MASK_STATUS_TRIGGERED_MASK                              (Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_INTR_MASK_STATUS_TRIGGERED_SHIFT                             (5)


#define DBGCAPTURE_REG_INTR_CLR                                                     (DBGCAPTURE_REG_BASE + 0x8)
#define DBGCAPTURE_REG_INTR_CLR_DEFAULT                                             0x0
#define DBGCAPTURE_REG_INTR_CLR_MEM_WR_WRAP                                         (Bit0+Bit1+Bit2+Bit3+Bit4)
#define DBGCAPTURE_REG_INTR_CLR_MEM_WR_WRAP_MASK                                    (Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_INTR_CLR_MEM_WR_WRAP_SHIFT                                   (0)
#define DBGCAPTURE_REG_INTR_CLR_TRIGGERED                                           (Bit5+Bit6+Bit7+Bit8+Bit9)
#define DBGCAPTURE_REG_INTR_CLR_TRIGGERED_MASK                                      (Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_INTR_CLR_TRIGGERED_SHIFT                                     (5)


#define DBGCAPTURE_REG_INTR_SET                                                     (DBGCAPTURE_REG_BASE + 0xc)
#define DBGCAPTURE_REG_INTR_SET_DEFAULT                                             0x0
#define DBGCAPTURE_REG_INTR_SET_MEM_WR_WRAP                                         (Bit0+Bit1+Bit2+Bit3+Bit4)
#define DBGCAPTURE_REG_INTR_SET_MEM_WR_WRAP_MASK                                    (Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_INTR_SET_MEM_WR_WRAP_SHIFT                                   (0)
#define DBGCAPTURE_REG_INTR_SET_TRIGGERED                                           (Bit5+Bit6+Bit7+Bit8+Bit9)
#define DBGCAPTURE_REG_INTR_SET_TRIGGERED_MASK                                      (Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_INTR_SET_TRIGGERED_SHIFT                                     (5)


#define DBGCAPTURE_REG_INTR_MASK_SET                                                (DBGCAPTURE_REG_BASE + 0x10)
#define DBGCAPTURE_REG_INTR_MASK_SET_DEFAULT                                        0x0
#define DBGCAPTURE_REG_INTR_MASK_SET_MEM_WR_WRAP                                    (Bit0+Bit1+Bit2+Bit3+Bit4)
#define DBGCAPTURE_REG_INTR_MASK_SET_MEM_WR_WRAP_MASK                               (Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_INTR_MASK_SET_MEM_WR_WRAP_SHIFT                              (0)
#define DBGCAPTURE_REG_INTR_MASK_SET_TRIGGERED                                      (Bit5+Bit6+Bit7+Bit8+Bit9)
#define DBGCAPTURE_REG_INTR_MASK_SET_TRIGGERED_MASK                                 (Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_INTR_MASK_SET_TRIGGERED_SHIFT                                (5)


#define DBGCAPTURE_REG_INTR_MASK_CLR                                                (DBGCAPTURE_REG_BASE + 0x14)
#define DBGCAPTURE_REG_INTR_MASK_CLR_DEFAULT                                        0x0
#define DBGCAPTURE_REG_INTR_MASK_CLR_MEM_WR_WRAP                                    (Bit0+Bit1+Bit2+Bit3+Bit4)
#define DBGCAPTURE_REG_INTR_MASK_CLR_MEM_WR_WRAP_MASK                               (Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_INTR_MASK_CLR_MEM_WR_WRAP_SHIFT                              (0)
#define DBGCAPTURE_REG_INTR_MASK_CLR_TRIGGERED                                      (Bit5+Bit6+Bit7+Bit8+Bit9)
#define DBGCAPTURE_REG_INTR_MASK_CLR_TRIGGERED_MASK                                 (Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_INTR_MASK_CLR_TRIGGERED_SHIFT                                (5)


#define DBGCAPTURE_REG_MISC_CTRL                                                    (DBGCAPTURE_REG_BASE + 0x40)
#define DBGCAPTURE_REG_MISC_CTRL_DEFAULT                                            0x3F000
#define DBGCAPTURE_REG_MISC_CTRL_CTL_DBCAPTURE_EN                                   (Bit0)
#define DBGCAPTURE_REG_MISC_CTRL_CTL_RST_INTRCTRL                                   (Bit1)
#define DBGCAPTURE_REG_MISC_CTRL_CTL_CORE_EN                                        (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define DBGCAPTURE_REG_MISC_CTRL_CTL_CORE_EN_MASK                                   (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_MISC_CTRL_CTL_CORE_EN_SHIFT                                  (4)
#define DBGCAPTURE_REG_MISC_CTRL_CTL_CORE_RESET                                     (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define DBGCAPTURE_REG_MISC_CTRL_CTL_CORE_RESET_MASK                                (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_MISC_CTRL_CTL_CORE_RESET_SHIFT                               (12)


#define DBGCAPTURE_REG_MISC_CTRL_START_STOP                                         (DBGCAPTURE_REG_BASE + 0x44)
#define DBGCAPTURE_REG_MISC_CTRL_START_STOP_DEFAULT                                 0x0
#define DBGCAPTURE_REG_MISC_CTRL_START_STOP_CTL_CORE_START                          (Bit0+Bit1+Bit2+Bit3+Bit4)
#define DBGCAPTURE_REG_MISC_CTRL_START_STOP_CTL_CORE_START_MASK                     (Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_MISC_CTRL_START_STOP_CTL_CORE_START_SHIFT                    (0)
#define DBGCAPTURE_REG_MISC_CTRL_START_STOP_CTL_CORE_FORCE_TRIGGER                  (Bit16+Bit17+Bit18+Bit19+Bit20)
#define DBGCAPTURE_REG_MISC_CTRL_START_STOP_CTL_CORE_FORCE_TRIGGER_MASK             (Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_MISC_CTRL_START_STOP_CTL_CORE_FORCE_TRIGGER_SHIFT            (16)


#define DBGCAPTURE_REG_START_CTRL                                                   (DBGCAPTURE_REG_BASE + 0x48)
#define DBGCAPTURE_REG_START_CTRL_DEFAULT                                           0x222
#define DBGCAPTURE_REG_START_CTRL_CTL_HTRANSI_QUALIF_VAL                            (Bit0+Bit1)
#define DBGCAPTURE_REG_START_CTRL_CTL_HTRANSI_QUALIF_VAL_MASK                       (Bit1+Bit0)
#define DBGCAPTURE_REG_START_CTRL_CTL_HTRANSI_QUALIF_VAL_SHIFT                      (0)
#define DBGCAPTURE_REG_START_CTRL_CTL_HTRANSD_QUALIF_VAL                            (Bit4+Bit5)
#define DBGCAPTURE_REG_START_CTRL_CTL_HTRANSD_QUALIF_VAL_MASK                       (Bit1+Bit0)
#define DBGCAPTURE_REG_START_CTRL_CTL_HTRANSD_QUALIF_VAL_SHIFT                      (4)
#define DBGCAPTURE_REG_START_CTRL_CTL_HTRANSS_QUALIF_VAL                            (Bit8+Bit9)
#define DBGCAPTURE_REG_START_CTRL_CTL_HTRANSS_QUALIF_VAL_MASK                       (Bit1+Bit0)
#define DBGCAPTURE_REG_START_CTRL_CTL_HTRANSS_QUALIF_VAL_SHIFT                      (8)


#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0                                            (DBGCAPTURE_REG_BASE + 0x80)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0_DEFAULT                                    0x0
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0_SEL_0                                      (Bit0+Bit1+Bit2)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0_SEL_0_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0_SEL_0_SHIFT                                (0)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0_SEL_1                                      (Bit4+Bit5+Bit6)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0_SEL_1_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0_SEL_1_SHIFT                                (4)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0_SEL_2                                      (Bit8+Bit9+Bit10)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0_SEL_2_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0_SEL_2_SHIFT                                (8)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0_SEL_3                                      (Bit12+Bit13+Bit14)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0_SEL_3_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0_SEL_3_SHIFT                                (12)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0_SEL_4                                      (Bit16+Bit17+Bit18)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0_SEL_4_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_0_SEL_4_SHIFT                                (16)


#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1                                            (DBGCAPTURE_REG_BASE + 0x84)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1_DEFAULT                                    0x0
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1_SEL_5                                      (Bit0+Bit1+Bit2)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1_SEL_5_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1_SEL_5_SHIFT                                (0)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1_SEL_6                                      (Bit4+Bit5+Bit6)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1_SEL_6_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1_SEL_6_SHIFT                                (4)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1_SEL_7                                      (Bit8+Bit9+Bit10)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1_SEL_7_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1_SEL_7_SHIFT                                (8)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1_SEL_8                                      (Bit12+Bit13+Bit14)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1_SEL_8_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1_SEL_8_SHIFT                                (12)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1_SEL_9                                      (Bit16+Bit17+Bit18)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1_SEL_9_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_TRIG_SEL_1_SEL_9_SHIFT                                (16)


#define DBGCAPTURE_REG_CORE_0_TRIG_COND                                             (DBGCAPTURE_REG_BASE + 0x88)
#define DBGCAPTURE_REG_CORE_0_TRIG_COND_DEFAULT                                     0x0
#define DBGCAPTURE_REG_CORE_0_TRIG_COND_VAL                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_0_TRIG_COND_VAL_MASK                                    (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_TRIG_COND_VAL_SHIFT                                   (0)


#define DBGCAPTURE_REG_CORE_0_TRIG_MASK                                             (DBGCAPTURE_REG_BASE + 0x8c)
#define DBGCAPTURE_REG_CORE_0_TRIG_MASK_DEFAULT                                     0x0
#define DBGCAPTURE_REG_CORE_0_TRIG_MASK_VAL                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_0_TRIG_MASK_VAL_MASK                                    (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_TRIG_MASK_VAL_SHIFT                                   (0)


#define DBGCAPTURE_REG_CORE_0_DATA_SRC_SEL                                          (DBGCAPTURE_REG_BASE + 0x90)
#define DBGCAPTURE_REG_CORE_0_DATA_SRC_SEL_DEFAULT                                  0x0
#define DBGCAPTURE_REG_CORE_0_DATA_SRC_SEL_VAL                                      (Bit0+Bit1+Bit2+Bit3)
#define DBGCAPTURE_REG_CORE_0_DATA_SRC_SEL_VAL_MASK                                 (Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_DATA_SRC_SEL_VAL_SHIFT                                (0)


#define DBGCAPTURE_REG_CORE_0_QUAL_CONTROL                                          (DBGCAPTURE_REG_BASE + 0x94)
#define DBGCAPTURE_REG_CORE_0_QUAL_CONTROL_DEFAULT                                  0x10000
#define DBGCAPTURE_REG_CORE_0_QUAL_CONTROL_QUAL_SEL                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8)
#define DBGCAPTURE_REG_CORE_0_QUAL_CONTROL_QUAL_SEL_MASK                            (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_QUAL_CONTROL_QUAL_SEL_SHIFT                           (0)
#define DBGCAPTURE_REG_CORE_0_QUAL_CONTROL_QUAL_OR0AND1                             (Bit12)
#define DBGCAPTURE_REG_CORE_0_QUAL_CONTROL_QUAL_FORCE                               (Bit16)


#define DBGCAPTURE_REG_CORE_0_STATUS                                                (DBGCAPTURE_REG_BASE + 0x98)
#define DBGCAPTURE_REG_CORE_0_STATUS_DEFAULT                                        0x0
#define DBGCAPTURE_REG_CORE_0_STATUS_STATE                                          (Bit0+Bit1)
#define DBGCAPTURE_REG_CORE_0_STATUS_STATE_MASK                                     (Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_STATUS_STATE_SHIFT                                    (0)
#define DBGCAPTURE_REG_CORE_0_STATUS_READ_DATA_VALID                                (Bit4)


#define DBGCAPTURE_REG_CORE_0_ADDR                                                  (DBGCAPTURE_REG_BASE + 0x9c)
#define DBGCAPTURE_REG_CORE_0_ADDR_DEFAULT                                          0x0
#define DBGCAPTURE_REG_CORE_0_ADDR_NXT_WR_ADDR                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define DBGCAPTURE_REG_CORE_0_ADDR_NXT_WR_ADDR_MASK                                 (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_ADDR_NXT_WR_ADDR_SHIFT                                (0)
#define DBGCAPTURE_REG_CORE_0_ADDR_LAST_RD_ADDR                                     (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_0_ADDR_LAST_RD_ADDR_MASK                                (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_ADDR_LAST_RD_ADDR_SHIFT                               (16)


#define DBGCAPTURE_REG_CORE_0_NUM_DATA                                              (DBGCAPTURE_REG_BASE + 0xa0)
#define DBGCAPTURE_REG_CORE_0_NUM_DATA_DEFAULT                                      0x0
#define DBGCAPTURE_REG_CORE_0_NUM_DATA_NUM_DATA                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define DBGCAPTURE_REG_CORE_0_NUM_DATA_NUM_DATA_MASK                                (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_NUM_DATA_NUM_DATA_SHIFT                               (0)


#define DBGCAPTURE_REG_CORE_0_RDATA                                                 (DBGCAPTURE_REG_BASE + 0xb0)
#define DBGCAPTURE_REG_CORE_0_RDATA_DEFAULT                                         0x0
#define DBGCAPTURE_REG_CORE_0_RDATA_DATA                                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_0_RDATA_DATA_MASK                                       (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_0_RDATA_DATA_SHIFT                                      (0)


#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0                                            (DBGCAPTURE_REG_BASE + 0xc0)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0_DEFAULT                                    0x0
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0_SEL_0                                      (Bit0+Bit1+Bit2)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0_SEL_0_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0_SEL_0_SHIFT                                (0)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0_SEL_1                                      (Bit4+Bit5+Bit6)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0_SEL_1_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0_SEL_1_SHIFT                                (4)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0_SEL_2                                      (Bit8+Bit9+Bit10)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0_SEL_2_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0_SEL_2_SHIFT                                (8)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0_SEL_3                                      (Bit12+Bit13+Bit14)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0_SEL_3_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0_SEL_3_SHIFT                                (12)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0_SEL_4                                      (Bit16+Bit17+Bit18)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0_SEL_4_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_0_SEL_4_SHIFT                                (16)


#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1                                            (DBGCAPTURE_REG_BASE + 0xc4)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1_DEFAULT                                    0x0
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1_SEL_5                                      (Bit0+Bit1+Bit2)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1_SEL_5_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1_SEL_5_SHIFT                                (0)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1_SEL_6                                      (Bit4+Bit5+Bit6)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1_SEL_6_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1_SEL_6_SHIFT                                (4)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1_SEL_7                                      (Bit8+Bit9+Bit10)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1_SEL_7_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1_SEL_7_SHIFT                                (8)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1_SEL_8                                      (Bit12+Bit13+Bit14)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1_SEL_8_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1_SEL_8_SHIFT                                (12)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1_SEL_9                                      (Bit16+Bit17+Bit18)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1_SEL_9_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_TRIG_SEL_1_SEL_9_SHIFT                                (16)


#define DBGCAPTURE_REG_CORE_1_TRIG_COND                                             (DBGCAPTURE_REG_BASE + 0xc8)
#define DBGCAPTURE_REG_CORE_1_TRIG_COND_DEFAULT                                     0x0
#define DBGCAPTURE_REG_CORE_1_TRIG_COND_VAL                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_1_TRIG_COND_VAL_MASK                                    (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_TRIG_COND_VAL_SHIFT                                   (0)


#define DBGCAPTURE_REG_CORE_1_TRIG_MASK                                             (DBGCAPTURE_REG_BASE + 0xcc)
#define DBGCAPTURE_REG_CORE_1_TRIG_MASK_DEFAULT                                     0x0
#define DBGCAPTURE_REG_CORE_1_TRIG_MASK_VAL                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_1_TRIG_MASK_VAL_MASK                                    (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_TRIG_MASK_VAL_SHIFT                                   (0)


#define DBGCAPTURE_REG_CORE_1_DATA_SRC_SEL                                          (DBGCAPTURE_REG_BASE + 0xd0)
#define DBGCAPTURE_REG_CORE_1_DATA_SRC_SEL_DEFAULT                                  0x0
#define DBGCAPTURE_REG_CORE_1_DATA_SRC_SEL_VAL                                      (Bit0+Bit1+Bit2+Bit3)
#define DBGCAPTURE_REG_CORE_1_DATA_SRC_SEL_VAL_MASK                                 (Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_DATA_SRC_SEL_VAL_SHIFT                                (0)


#define DBGCAPTURE_REG_CORE_1_QUAL_CONTROL                                          (DBGCAPTURE_REG_BASE + 0xd4)
#define DBGCAPTURE_REG_CORE_1_QUAL_CONTROL_DEFAULT                                  0x10000
#define DBGCAPTURE_REG_CORE_1_QUAL_CONTROL_QUAL_SEL                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8)
#define DBGCAPTURE_REG_CORE_1_QUAL_CONTROL_QUAL_SEL_MASK                            (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_QUAL_CONTROL_QUAL_SEL_SHIFT                           (0)
#define DBGCAPTURE_REG_CORE_1_QUAL_CONTROL_QUAL_OR0AND1                             (Bit12)
#define DBGCAPTURE_REG_CORE_1_QUAL_CONTROL_QUAL_FORCE                               (Bit16)


#define DBGCAPTURE_REG_CORE_1_STATUS                                                (DBGCAPTURE_REG_BASE + 0xd8)
#define DBGCAPTURE_REG_CORE_1_STATUS_DEFAULT                                        0x0
#define DBGCAPTURE_REG_CORE_1_STATUS_STATE                                          (Bit0+Bit1)
#define DBGCAPTURE_REG_CORE_1_STATUS_STATE_MASK                                     (Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_STATUS_STATE_SHIFT                                    (0)
#define DBGCAPTURE_REG_CORE_1_STATUS_READ_DATA_VALID                                (Bit4)


#define DBGCAPTURE_REG_CORE_1_ADDR                                                  (DBGCAPTURE_REG_BASE + 0xdc)
#define DBGCAPTURE_REG_CORE_1_ADDR_DEFAULT                                          0x0
#define DBGCAPTURE_REG_CORE_1_ADDR_NXT_WR_ADDR                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define DBGCAPTURE_REG_CORE_1_ADDR_NXT_WR_ADDR_MASK                                 (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_ADDR_NXT_WR_ADDR_SHIFT                                (0)
#define DBGCAPTURE_REG_CORE_1_ADDR_LAST_RD_ADDR                                     (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_1_ADDR_LAST_RD_ADDR_MASK                                (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_ADDR_LAST_RD_ADDR_SHIFT                               (16)


#define DBGCAPTURE_REG_CORE_1_NUM_DATA                                              (DBGCAPTURE_REG_BASE + 0xe0)
#define DBGCAPTURE_REG_CORE_1_NUM_DATA_DEFAULT                                      0x0
#define DBGCAPTURE_REG_CORE_1_NUM_DATA_NUM_DATA                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define DBGCAPTURE_REG_CORE_1_NUM_DATA_NUM_DATA_MASK                                (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_NUM_DATA_NUM_DATA_SHIFT                               (0)


#define DBGCAPTURE_REG_CORE_1_RDATA                                                 (DBGCAPTURE_REG_BASE + 0xf0)
#define DBGCAPTURE_REG_CORE_1_RDATA_DEFAULT                                         0x0
#define DBGCAPTURE_REG_CORE_1_RDATA_DATA                                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_1_RDATA_DATA_MASK                                       (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_1_RDATA_DATA_SHIFT                                      (0)


#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0                                            (DBGCAPTURE_REG_BASE + 0x100)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0_DEFAULT                                    0x0
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0_SEL_0                                      (Bit0+Bit1+Bit2)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0_SEL_0_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0_SEL_0_SHIFT                                (0)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0_SEL_1                                      (Bit4+Bit5+Bit6)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0_SEL_1_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0_SEL_1_SHIFT                                (4)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0_SEL_2                                      (Bit8+Bit9+Bit10)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0_SEL_2_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0_SEL_2_SHIFT                                (8)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0_SEL_3                                      (Bit12+Bit13+Bit14)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0_SEL_3_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0_SEL_3_SHIFT                                (12)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0_SEL_4                                      (Bit16+Bit17+Bit18)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0_SEL_4_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_0_SEL_4_SHIFT                                (16)


#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1                                            (DBGCAPTURE_REG_BASE + 0x104)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1_DEFAULT                                    0x0
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1_SEL_5                                      (Bit0+Bit1+Bit2)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1_SEL_5_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1_SEL_5_SHIFT                                (0)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1_SEL_6                                      (Bit4+Bit5+Bit6)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1_SEL_6_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1_SEL_6_SHIFT                                (4)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1_SEL_7                                      (Bit8+Bit9+Bit10)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1_SEL_7_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1_SEL_7_SHIFT                                (8)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1_SEL_8                                      (Bit12+Bit13+Bit14)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1_SEL_8_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1_SEL_8_SHIFT                                (12)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1_SEL_9                                      (Bit16+Bit17+Bit18)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1_SEL_9_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_TRIG_SEL_1_SEL_9_SHIFT                                (16)


#define DBGCAPTURE_REG_CORE_2_TRIG_COND                                             (DBGCAPTURE_REG_BASE + 0x108)
#define DBGCAPTURE_REG_CORE_2_TRIG_COND_DEFAULT                                     0x0
#define DBGCAPTURE_REG_CORE_2_TRIG_COND_VAL                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_2_TRIG_COND_VAL_MASK                                    (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_TRIG_COND_VAL_SHIFT                                   (0)


#define DBGCAPTURE_REG_CORE_2_TRIG_MASK                                             (DBGCAPTURE_REG_BASE + 0x10c)
#define DBGCAPTURE_REG_CORE_2_TRIG_MASK_DEFAULT                                     0x0
#define DBGCAPTURE_REG_CORE_2_TRIG_MASK_VAL                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_2_TRIG_MASK_VAL_MASK                                    (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_TRIG_MASK_VAL_SHIFT                                   (0)


#define DBGCAPTURE_REG_CORE_2_DATA_SRC_SEL                                          (DBGCAPTURE_REG_BASE + 0x110)
#define DBGCAPTURE_REG_CORE_2_DATA_SRC_SEL_DEFAULT                                  0x0
#define DBGCAPTURE_REG_CORE_2_DATA_SRC_SEL_VAL                                      (Bit0+Bit1+Bit2+Bit3)
#define DBGCAPTURE_REG_CORE_2_DATA_SRC_SEL_VAL_MASK                                 (Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_DATA_SRC_SEL_VAL_SHIFT                                (0)


#define DBGCAPTURE_REG_CORE_2_QUAL_CONTROL                                          (DBGCAPTURE_REG_BASE + 0x114)
#define DBGCAPTURE_REG_CORE_2_QUAL_CONTROL_DEFAULT                                  0x10000
#define DBGCAPTURE_REG_CORE_2_QUAL_CONTROL_QUAL_SEL                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8)
#define DBGCAPTURE_REG_CORE_2_QUAL_CONTROL_QUAL_SEL_MASK                            (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_QUAL_CONTROL_QUAL_SEL_SHIFT                           (0)
#define DBGCAPTURE_REG_CORE_2_QUAL_CONTROL_QUAL_OR0AND1                             (Bit12)
#define DBGCAPTURE_REG_CORE_2_QUAL_CONTROL_QUAL_FORCE                               (Bit16)


#define DBGCAPTURE_REG_CORE_2_STATUS                                                (DBGCAPTURE_REG_BASE + 0x118)
#define DBGCAPTURE_REG_CORE_2_STATUS_DEFAULT                                        0x0
#define DBGCAPTURE_REG_CORE_2_STATUS_STATE                                          (Bit0+Bit1)
#define DBGCAPTURE_REG_CORE_2_STATUS_STATE_MASK                                     (Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_STATUS_STATE_SHIFT                                    (0)
#define DBGCAPTURE_REG_CORE_2_STATUS_READ_DATA_VALID                                (Bit4)


#define DBGCAPTURE_REG_CORE_2_ADDR                                                  (DBGCAPTURE_REG_BASE + 0x11c)
#define DBGCAPTURE_REG_CORE_2_ADDR_DEFAULT                                          0x0
#define DBGCAPTURE_REG_CORE_2_ADDR_NXT_WR_ADDR                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define DBGCAPTURE_REG_CORE_2_ADDR_NXT_WR_ADDR_MASK                                 (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_ADDR_NXT_WR_ADDR_SHIFT                                (0)
#define DBGCAPTURE_REG_CORE_2_ADDR_LAST_RD_ADDR                                     (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_2_ADDR_LAST_RD_ADDR_MASK                                (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_ADDR_LAST_RD_ADDR_SHIFT                               (16)


#define DBGCAPTURE_REG_CORE_2_NUM_DATA                                              (DBGCAPTURE_REG_BASE + 0x120)
#define DBGCAPTURE_REG_CORE_2_NUM_DATA_DEFAULT                                      0x0
#define DBGCAPTURE_REG_CORE_2_NUM_DATA_NUM_DATA                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define DBGCAPTURE_REG_CORE_2_NUM_DATA_NUM_DATA_MASK                                (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_NUM_DATA_NUM_DATA_SHIFT                               (0)


#define DBGCAPTURE_REG_CORE_2_RDATA                                                 (DBGCAPTURE_REG_BASE + 0x130)
#define DBGCAPTURE_REG_CORE_2_RDATA_DEFAULT                                         0x0
#define DBGCAPTURE_REG_CORE_2_RDATA_DATA                                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_2_RDATA_DATA_MASK                                       (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_2_RDATA_DATA_SHIFT                                      (0)


#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0                                            (DBGCAPTURE_REG_BASE + 0x140)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0_DEFAULT                                    0x0
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0_SEL_0                                      (Bit0+Bit1+Bit2)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0_SEL_0_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0_SEL_0_SHIFT                                (0)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0_SEL_1                                      (Bit4+Bit5+Bit6)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0_SEL_1_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0_SEL_1_SHIFT                                (4)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0_SEL_2                                      (Bit8+Bit9+Bit10)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0_SEL_2_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0_SEL_2_SHIFT                                (8)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0_SEL_3                                      (Bit12+Bit13+Bit14)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0_SEL_3_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0_SEL_3_SHIFT                                (12)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0_SEL_4                                      (Bit16+Bit17+Bit18)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0_SEL_4_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_0_SEL_4_SHIFT                                (16)


#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1                                            (DBGCAPTURE_REG_BASE + 0x144)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1_DEFAULT                                    0x0
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1_SEL_5                                      (Bit0+Bit1+Bit2)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1_SEL_5_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1_SEL_5_SHIFT                                (0)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1_SEL_6                                      (Bit4+Bit5+Bit6)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1_SEL_6_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1_SEL_6_SHIFT                                (4)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1_SEL_7                                      (Bit8+Bit9+Bit10)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1_SEL_7_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1_SEL_7_SHIFT                                (8)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1_SEL_8                                      (Bit12+Bit13+Bit14)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1_SEL_8_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1_SEL_8_SHIFT                                (12)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1_SEL_9                                      (Bit16+Bit17+Bit18)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1_SEL_9_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_TRIG_SEL_1_SEL_9_SHIFT                                (16)


#define DBGCAPTURE_REG_CORE_3_TRIG_COND                                             (DBGCAPTURE_REG_BASE + 0x148)
#define DBGCAPTURE_REG_CORE_3_TRIG_COND_DEFAULT                                     0x0
#define DBGCAPTURE_REG_CORE_3_TRIG_COND_VAL                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_3_TRIG_COND_VAL_MASK                                    (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_TRIG_COND_VAL_SHIFT                                   (0)


#define DBGCAPTURE_REG_CORE_3_TRIG_MASK                                             (DBGCAPTURE_REG_BASE + 0x14c)
#define DBGCAPTURE_REG_CORE_3_TRIG_MASK_DEFAULT                                     0x0
#define DBGCAPTURE_REG_CORE_3_TRIG_MASK_VAL                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_3_TRIG_MASK_VAL_MASK                                    (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_TRIG_MASK_VAL_SHIFT                                   (0)


#define DBGCAPTURE_REG_CORE_3_DATA_SRC_SEL                                          (DBGCAPTURE_REG_BASE + 0x150)
#define DBGCAPTURE_REG_CORE_3_DATA_SRC_SEL_DEFAULT                                  0x0
#define DBGCAPTURE_REG_CORE_3_DATA_SRC_SEL_VAL                                      (Bit0+Bit1+Bit2+Bit3)
#define DBGCAPTURE_REG_CORE_3_DATA_SRC_SEL_VAL_MASK                                 (Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_DATA_SRC_SEL_VAL_SHIFT                                (0)


#define DBGCAPTURE_REG_CORE_3_QUAL_CONTROL                                          (DBGCAPTURE_REG_BASE + 0x154)
#define DBGCAPTURE_REG_CORE_3_QUAL_CONTROL_DEFAULT                                  0x10000
#define DBGCAPTURE_REG_CORE_3_QUAL_CONTROL_QUAL_SEL                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8)
#define DBGCAPTURE_REG_CORE_3_QUAL_CONTROL_QUAL_SEL_MASK                            (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_QUAL_CONTROL_QUAL_SEL_SHIFT                           (0)
#define DBGCAPTURE_REG_CORE_3_QUAL_CONTROL_QUAL_OR0AND1                             (Bit12)
#define DBGCAPTURE_REG_CORE_3_QUAL_CONTROL_QUAL_FORCE                               (Bit16)


#define DBGCAPTURE_REG_CORE_3_STATUS                                                (DBGCAPTURE_REG_BASE + 0x158)
#define DBGCAPTURE_REG_CORE_3_STATUS_DEFAULT                                        0x0
#define DBGCAPTURE_REG_CORE_3_STATUS_STATE                                          (Bit0+Bit1)
#define DBGCAPTURE_REG_CORE_3_STATUS_STATE_MASK                                     (Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_STATUS_STATE_SHIFT                                    (0)
#define DBGCAPTURE_REG_CORE_3_STATUS_READ_DATA_VALID                                (Bit4)


#define DBGCAPTURE_REG_CORE_3_ADDR                                                  (DBGCAPTURE_REG_BASE + 0x15c)
#define DBGCAPTURE_REG_CORE_3_ADDR_DEFAULT                                          0x0
#define DBGCAPTURE_REG_CORE_3_ADDR_NXT_WR_ADDR                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define DBGCAPTURE_REG_CORE_3_ADDR_NXT_WR_ADDR_MASK                                 (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_ADDR_NXT_WR_ADDR_SHIFT                                (0)
#define DBGCAPTURE_REG_CORE_3_ADDR_LAST_RD_ADDR                                     (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_3_ADDR_LAST_RD_ADDR_MASK                                (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_ADDR_LAST_RD_ADDR_SHIFT                               (16)


#define DBGCAPTURE_REG_CORE_3_NUM_DATA                                              (DBGCAPTURE_REG_BASE + 0x160)
#define DBGCAPTURE_REG_CORE_3_NUM_DATA_DEFAULT                                      0x0
#define DBGCAPTURE_REG_CORE_3_NUM_DATA_NUM_DATA                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define DBGCAPTURE_REG_CORE_3_NUM_DATA_NUM_DATA_MASK                                (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_NUM_DATA_NUM_DATA_SHIFT                               (0)


#define DBGCAPTURE_REG_CORE_3_RDATA                                                 (DBGCAPTURE_REG_BASE + 0x170)
#define DBGCAPTURE_REG_CORE_3_RDATA_DEFAULT                                         0x0
#define DBGCAPTURE_REG_CORE_3_RDATA_DATA                                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_3_RDATA_DATA_MASK                                       (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_3_RDATA_DATA_SHIFT                                      (0)


#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0                                            (DBGCAPTURE_REG_BASE + 0x180)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0_DEFAULT                                    0x0
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0_SEL_0                                      (Bit0+Bit1+Bit2)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0_SEL_0_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0_SEL_0_SHIFT                                (0)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0_SEL_1                                      (Bit4+Bit5+Bit6)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0_SEL_1_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0_SEL_1_SHIFT                                (4)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0_SEL_2                                      (Bit8+Bit9+Bit10)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0_SEL_2_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0_SEL_2_SHIFT                                (8)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0_SEL_3                                      (Bit12+Bit13+Bit14)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0_SEL_3_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0_SEL_3_SHIFT                                (12)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0_SEL_4                                      (Bit16+Bit17+Bit18)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0_SEL_4_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_0_SEL_4_SHIFT                                (16)


#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1                                            (DBGCAPTURE_REG_BASE + 0x184)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1_DEFAULT                                    0x0
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1_SEL_5                                      (Bit0+Bit1+Bit2)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1_SEL_5_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1_SEL_5_SHIFT                                (0)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1_SEL_6                                      (Bit4+Bit5+Bit6)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1_SEL_6_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1_SEL_6_SHIFT                                (4)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1_SEL_7                                      (Bit8+Bit9+Bit10)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1_SEL_7_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1_SEL_7_SHIFT                                (8)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1_SEL_8                                      (Bit12+Bit13+Bit14)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1_SEL_8_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1_SEL_8_SHIFT                                (12)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1_SEL_9                                      (Bit16+Bit17+Bit18)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1_SEL_9_MASK                                 (Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_TRIG_SEL_1_SEL_9_SHIFT                                (16)


#define DBGCAPTURE_REG_CORE_4_TRIG_COND                                             (DBGCAPTURE_REG_BASE + 0x188)
#define DBGCAPTURE_REG_CORE_4_TRIG_COND_DEFAULT                                     0x0
#define DBGCAPTURE_REG_CORE_4_TRIG_COND_VAL                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_4_TRIG_COND_VAL_MASK                                    (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_TRIG_COND_VAL_SHIFT                                   (0)


#define DBGCAPTURE_REG_CORE_4_TRIG_MASK                                             (DBGCAPTURE_REG_BASE + 0x18c)
#define DBGCAPTURE_REG_CORE_4_TRIG_MASK_DEFAULT                                     0x0
#define DBGCAPTURE_REG_CORE_4_TRIG_MASK_VAL                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_4_TRIG_MASK_VAL_MASK                                    (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_TRIG_MASK_VAL_SHIFT                                   (0)


#define DBGCAPTURE_REG_CORE_4_DATA_SRC_SEL                                          (DBGCAPTURE_REG_BASE + 0x190)
#define DBGCAPTURE_REG_CORE_4_DATA_SRC_SEL_DEFAULT                                  0x0
#define DBGCAPTURE_REG_CORE_4_DATA_SRC_SEL_VAL                                      (Bit0+Bit1+Bit2+Bit3)
#define DBGCAPTURE_REG_CORE_4_DATA_SRC_SEL_VAL_MASK                                 (Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_DATA_SRC_SEL_VAL_SHIFT                                (0)


#define DBGCAPTURE_REG_CORE_4_QUAL_CONTROL                                          (DBGCAPTURE_REG_BASE + 0x194)
#define DBGCAPTURE_REG_CORE_4_QUAL_CONTROL_DEFAULT                                  0x10000
#define DBGCAPTURE_REG_CORE_4_QUAL_CONTROL_QUAL_SEL                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8)
#define DBGCAPTURE_REG_CORE_4_QUAL_CONTROL_QUAL_SEL_MASK                            (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_QUAL_CONTROL_QUAL_SEL_SHIFT                           (0)
#define DBGCAPTURE_REG_CORE_4_QUAL_CONTROL_QUAL_OR0AND1                             (Bit12)
#define DBGCAPTURE_REG_CORE_4_QUAL_CONTROL_QUAL_FORCE                               (Bit16)


#define DBGCAPTURE_REG_CORE_4_STATUS                                                (DBGCAPTURE_REG_BASE + 0x198)
#define DBGCAPTURE_REG_CORE_4_STATUS_DEFAULT                                        0x0
#define DBGCAPTURE_REG_CORE_4_STATUS_STATE                                          (Bit0+Bit1)
#define DBGCAPTURE_REG_CORE_4_STATUS_STATE_MASK                                     (Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_STATUS_STATE_SHIFT                                    (0)
#define DBGCAPTURE_REG_CORE_4_STATUS_READ_DATA_VALID                                (Bit4)


#define DBGCAPTURE_REG_CORE_4_ADDR                                                  (DBGCAPTURE_REG_BASE + 0x19c)
#define DBGCAPTURE_REG_CORE_4_ADDR_DEFAULT                                          0x0
#define DBGCAPTURE_REG_CORE_4_ADDR_NXT_WR_ADDR                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define DBGCAPTURE_REG_CORE_4_ADDR_NXT_WR_ADDR_MASK                                 (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_ADDR_NXT_WR_ADDR_SHIFT                                (0)
#define DBGCAPTURE_REG_CORE_4_ADDR_LAST_RD_ADDR                                     (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_4_ADDR_LAST_RD_ADDR_MASK                                (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_ADDR_LAST_RD_ADDR_SHIFT                               (16)


#define DBGCAPTURE_REG_CORE_4_NUM_DATA                                              (DBGCAPTURE_REG_BASE + 0x1a0)
#define DBGCAPTURE_REG_CORE_4_NUM_DATA_DEFAULT                                      0x0
#define DBGCAPTURE_REG_CORE_4_NUM_DATA_NUM_DATA                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define DBGCAPTURE_REG_CORE_4_NUM_DATA_NUM_DATA_MASK                                (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_NUM_DATA_NUM_DATA_SHIFT                               (0)


#define DBGCAPTURE_REG_CORE_4_RDATA                                                 (DBGCAPTURE_REG_BASE + 0x1b0)
#define DBGCAPTURE_REG_CORE_4_RDATA_DEFAULT                                         0x0
#define DBGCAPTURE_REG_CORE_4_RDATA_DATA                                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define DBGCAPTURE_REG_CORE_4_RDATA_DATA_MASK                                       (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define DBGCAPTURE_REG_CORE_4_RDATA_DATA_SHIFT                                      (0)


#endif // _DBGCAPTURE_REG_DEFINES_H

