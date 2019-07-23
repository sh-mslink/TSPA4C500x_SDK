/* **************************** */
#define AHB_TRIG_REG_INTR_STATUS                                          (AHB_TRIG_REG_BASE + 0x0)
#define AHB_TRIG_REG_INTR_STATUS_DEFAULT                                  0x0
#define AHB_TRIG_REG_INTR_STATUS_TIMEOUT                                  (Bit0)
#define AHB_TRIG_REG_INTR_STATUS_TRIG_DONE                                (Bit1)


#define AHB_TRIG_REG_INTR_MASK_STATUS                                     (AHB_TRIG_REG_BASE + 0x4)
#define AHB_TRIG_REG_INTR_MASK_STATUS_DEFAULT                             0x0
#define AHB_TRIG_REG_INTR_MASK_STATUS_TIMEOUT                             (Bit0)
#define AHB_TRIG_REG_INTR_MASK_STATUS_TRIG_DONE                           (Bit1)


#define AHB_TRIG_REG_INTR_CLEAR                                           (AHB_TRIG_REG_BASE + 0x8)
#define AHB_TRIG_REG_INTR_CLEAR_DEFAULT                                   0x0
#define AHB_TRIG_REG_INTR_CLEAR_TIMEOUT                                   (Bit0)
#define AHB_TRIG_REG_INTR_CLEAR_TRIG_DONE                                 (Bit1)


#define AHB_TRIG_REG_INTR_SET                                             (AHB_TRIG_REG_BASE + 0xc)
#define AHB_TRIG_REG_INTR_SET_DEFAULT                                     0x0
#define AHB_TRIG_REG_INTR_SET_TIMEOUT                                     (Bit0)
#define AHB_TRIG_REG_INTR_SET_TRIG_DONE                                   (Bit1)


#define AHB_TRIG_REG_INTR_MASK_SET                                        (AHB_TRIG_REG_BASE + 0x10)
#define AHB_TRIG_REG_INTR_MASK_SET_DEFAULT                                0x0
#define AHB_TRIG_REG_INTR_MASK_SET_TIMEOUT                                (Bit0)
#define AHB_TRIG_REG_INTR_MASK_SET_TRIG_DONE                              (Bit1)


#define AHB_TRIG_REG_INTR_MASK_CLEAR                                      (AHB_TRIG_REG_BASE + 0x14)
#define AHB_TRIG_REG_INTR_MASK_CLEAR_DEFAULT                              0x0
#define AHB_TRIG_REG_INTR_MASK_CLEAR_TIMEOUT                              (Bit0)
#define AHB_TRIG_REG_INTR_MASK_CLEAR_TRIG_DONE                            (Bit1)


#define AHB_TRIG_REG_MISC_CTRL                                            (AHB_TRIG_REG_BASE + 0x40)
#define AHB_TRIG_REG_MISC_CTRL_DEFAULT                                    0x4000
#define AHB_TRIG_REG_MISC_CTRL_CTL_EN                                     (Bit0)
#define AHB_TRIG_REG_MISC_CTRL_CTL_RST_INTRCTRL                           (Bit1)
#define AHB_TRIG_REG_MISC_CTRL_CTL_TIMEOUT_EN                             (Bit4)
#define AHB_TRIG_REG_MISC_CTRL_CTL_TIMEOUT_VAL                            (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_MISC_CTRL_CTL_TIMEOUT_VAL_MASK                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_MISC_CTRL_CTL_TIMEOUT_VAL_SHIFT                      (8)


#define AHB_TRIG_REG_SOFTWARE_TRIG                                        (AHB_TRIG_REG_BASE + 0x48)
#define AHB_TRIG_REG_SOFTWARE_TRIG_DEFAULT                                0x0
#define AHB_TRIG_REG_SOFTWARE_TRIG_CTL_SOFTWARE_TRIG                      (Bit0)


#define AHB_TRIG_REG_CUR_STATE                                            (AHB_TRIG_REG_BASE + 0x80)
#define AHB_TRIG_REG_CUR_STATE_DEFAULT                                    0x0
#define AHB_TRIG_REG_CUR_STATE_STS_CUR_STATE                              (Bit0+Bit1+Bit2+Bit3)
#define AHB_TRIG_REG_CUR_STATE_STS_CUR_STATE_MASK                         (Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_CUR_STATE_STS_CUR_STATE_SHIFT                        (0)
#define AHB_TRIG_REG_CUR_STATE_STS_CUR_TRIG                               (Bit4+Bit5+Bit6+Bit7+Bit8)
#define AHB_TRIG_REG_CUR_STATE_STS_CUR_TRIG_MASK                          (Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_CUR_STATE_STS_CUR_TRIG_SHIFT                         (4)


#define AHB_TRIG_REG_TIMEOUT_STATUS                                       (AHB_TRIG_REG_BASE + 0x90)
#define AHB_TRIG_REG_TIMEOUT_STATUS_DEFAULT                               0x0
#define AHB_TRIG_REG_TIMEOUT_STATUS_STS_TIMEOUT_MEM_ADDR                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define AHB_TRIG_REG_TIMEOUT_STATUS_STS_TIMEOUT_MEM_ADDR_MASK             (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TIMEOUT_STATUS_STS_TIMEOUT_MEM_ADDR_SHIFT            (0)


#define AHB_TRIG_REG_TRIGGER_0_CONF                                       (AHB_TRIG_REG_BASE + 0xc0)
#define AHB_TRIG_REG_TRIGGER_0_CONF_DEFAULT                               0x0
#define AHB_TRIG_REG_TRIGGER_0_CONF_EN                                    (Bit0)
#define AHB_TRIG_REG_TRIGGER_0_CONF_ADDR_OFFSET                           (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_0_CONF_ADDR_OFFSET_MASK                      (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_0_CONF_ADDR_OFFSET_SHIFT                     (4)
#define AHB_TRIG_REG_TRIGGER_0_CONF_NUM_CMDS                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_0_CONF_NUM_CMDS_MASK                         (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_0_CONF_NUM_CMDS_SHIFT                        (16)


#define AHB_TRIG_REG_TRIGGER_1_CONF                                       (AHB_TRIG_REG_BASE + 0xc4)
#define AHB_TRIG_REG_TRIGGER_1_CONF_DEFAULT                               0x0
#define AHB_TRIG_REG_TRIGGER_1_CONF_EN                                    (Bit0)
#define AHB_TRIG_REG_TRIGGER_1_CONF_ADDR_OFFSET                           (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_1_CONF_ADDR_OFFSET_MASK                      (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_1_CONF_ADDR_OFFSET_SHIFT                     (4)
#define AHB_TRIG_REG_TRIGGER_1_CONF_NUM_CMDS                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_1_CONF_NUM_CMDS_MASK                         (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_1_CONF_NUM_CMDS_SHIFT                        (16)


#define AHB_TRIG_REG_TRIGGER_2_CONF                                       (AHB_TRIG_REG_BASE + 0xc8)
#define AHB_TRIG_REG_TRIGGER_2_CONF_DEFAULT                               0x0
#define AHB_TRIG_REG_TRIGGER_2_CONF_EN                                    (Bit0)
#define AHB_TRIG_REG_TRIGGER_2_CONF_ADDR_OFFSET                           (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_2_CONF_ADDR_OFFSET_MASK                      (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_2_CONF_ADDR_OFFSET_SHIFT                     (4)
#define AHB_TRIG_REG_TRIGGER_2_CONF_NUM_CMDS                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_2_CONF_NUM_CMDS_MASK                         (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_2_CONF_NUM_CMDS_SHIFT                        (16)


#define AHB_TRIG_REG_TRIGGER_3_CONF                                       (AHB_TRIG_REG_BASE + 0xcc)
#define AHB_TRIG_REG_TRIGGER_3_CONF_DEFAULT                               0x0
#define AHB_TRIG_REG_TRIGGER_3_CONF_EN                                    (Bit0)
#define AHB_TRIG_REG_TRIGGER_3_CONF_ADDR_OFFSET                           (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_3_CONF_ADDR_OFFSET_MASK                      (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_3_CONF_ADDR_OFFSET_SHIFT                     (4)
#define AHB_TRIG_REG_TRIGGER_3_CONF_NUM_CMDS                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_3_CONF_NUM_CMDS_MASK                         (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_3_CONF_NUM_CMDS_SHIFT                        (16)


#define AHB_TRIG_REG_TRIGGER_4_CONF                                       (AHB_TRIG_REG_BASE + 0xd0)
#define AHB_TRIG_REG_TRIGGER_4_CONF_DEFAULT                               0x0
#define AHB_TRIG_REG_TRIGGER_4_CONF_EN                                    (Bit0)
#define AHB_TRIG_REG_TRIGGER_4_CONF_ADDR_OFFSET                           (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_4_CONF_ADDR_OFFSET_MASK                      (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_4_CONF_ADDR_OFFSET_SHIFT                     (4)
#define AHB_TRIG_REG_TRIGGER_4_CONF_NUM_CMDS                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_4_CONF_NUM_CMDS_MASK                         (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_4_CONF_NUM_CMDS_SHIFT                        (16)


#define AHB_TRIG_REG_TRIGGER_5_CONF                                       (AHB_TRIG_REG_BASE + 0xd4)
#define AHB_TRIG_REG_TRIGGER_5_CONF_DEFAULT                               0x0
#define AHB_TRIG_REG_TRIGGER_5_CONF_EN                                    (Bit0)
#define AHB_TRIG_REG_TRIGGER_5_CONF_ADDR_OFFSET                           (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_5_CONF_ADDR_OFFSET_MASK                      (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_5_CONF_ADDR_OFFSET_SHIFT                     (4)
#define AHB_TRIG_REG_TRIGGER_5_CONF_NUM_CMDS                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_5_CONF_NUM_CMDS_MASK                         (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_5_CONF_NUM_CMDS_SHIFT                        (16)


#define AHB_TRIG_REG_TRIGGER_6_CONF                                       (AHB_TRIG_REG_BASE + 0xd8)
#define AHB_TRIG_REG_TRIGGER_6_CONF_DEFAULT                               0x0
#define AHB_TRIG_REG_TRIGGER_6_CONF_EN                                    (Bit0)
#define AHB_TRIG_REG_TRIGGER_6_CONF_ADDR_OFFSET                           (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_6_CONF_ADDR_OFFSET_MASK                      (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_6_CONF_ADDR_OFFSET_SHIFT                     (4)
#define AHB_TRIG_REG_TRIGGER_6_CONF_NUM_CMDS                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_6_CONF_NUM_CMDS_MASK                         (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_6_CONF_NUM_CMDS_SHIFT                        (16)


#define AHB_TRIG_REG_TRIGGER_7_CONF                                       (AHB_TRIG_REG_BASE + 0xdc)
#define AHB_TRIG_REG_TRIGGER_7_CONF_DEFAULT                               0x0
#define AHB_TRIG_REG_TRIGGER_7_CONF_EN                                    (Bit0)
#define AHB_TRIG_REG_TRIGGER_7_CONF_ADDR_OFFSET                           (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_7_CONF_ADDR_OFFSET_MASK                      (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_7_CONF_ADDR_OFFSET_SHIFT                     (4)
#define AHB_TRIG_REG_TRIGGER_7_CONF_NUM_CMDS                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_7_CONF_NUM_CMDS_MASK                         (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_7_CONF_NUM_CMDS_SHIFT                        (16)


#define AHB_TRIG_REG_TRIGGER_8_CONF                                       (AHB_TRIG_REG_BASE + 0xe0)
#define AHB_TRIG_REG_TRIGGER_8_CONF_DEFAULT                               0x0
#define AHB_TRIG_REG_TRIGGER_8_CONF_EN                                    (Bit0)
#define AHB_TRIG_REG_TRIGGER_8_CONF_ADDR_OFFSET                           (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_8_CONF_ADDR_OFFSET_MASK                      (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_8_CONF_ADDR_OFFSET_SHIFT                     (4)
#define AHB_TRIG_REG_TRIGGER_8_CONF_NUM_CMDS                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_8_CONF_NUM_CMDS_MASK                         (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_8_CONF_NUM_CMDS_SHIFT                        (16)


#define AHB_TRIG_REG_TRIGGER_9_CONF                                       (AHB_TRIG_REG_BASE + 0xe4)
#define AHB_TRIG_REG_TRIGGER_9_CONF_DEFAULT                               0x0
#define AHB_TRIG_REG_TRIGGER_9_CONF_EN                                    (Bit0)
#define AHB_TRIG_REG_TRIGGER_9_CONF_ADDR_OFFSET                           (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_9_CONF_ADDR_OFFSET_MASK                      (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_9_CONF_ADDR_OFFSET_SHIFT                     (4)
#define AHB_TRIG_REG_TRIGGER_9_CONF_NUM_CMDS                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_9_CONF_NUM_CMDS_MASK                         (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_9_CONF_NUM_CMDS_SHIFT                        (16)


#define AHB_TRIG_REG_TRIGGER_10_CONF                                      (AHB_TRIG_REG_BASE + 0xe8)
#define AHB_TRIG_REG_TRIGGER_10_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_10_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_10_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_10_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_10_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_10_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_10_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_10_CONF_NUM_CMDS_SHIFT                       (16)


#define AHB_TRIG_REG_TRIGGER_11_CONF                                      (AHB_TRIG_REG_BASE + 0xec)
#define AHB_TRIG_REG_TRIGGER_11_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_11_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_11_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_11_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_11_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_11_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_11_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_11_CONF_NUM_CMDS_SHIFT                       (16)


#define AHB_TRIG_REG_TRIGGER_12_CONF                                      (AHB_TRIG_REG_BASE + 0xf0)
#define AHB_TRIG_REG_TRIGGER_12_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_12_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_12_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_12_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_12_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_12_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_12_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_12_CONF_NUM_CMDS_SHIFT                       (16)


#define AHB_TRIG_REG_TRIGGER_13_CONF                                      (AHB_TRIG_REG_BASE + 0xf4)
#define AHB_TRIG_REG_TRIGGER_13_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_13_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_13_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_13_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_13_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_13_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_13_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_13_CONF_NUM_CMDS_SHIFT                       (16)


#define AHB_TRIG_REG_TRIGGER_14_CONF                                      (AHB_TRIG_REG_BASE + 0xf8)
#define AHB_TRIG_REG_TRIGGER_14_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_14_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_14_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_14_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_14_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_14_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_14_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_14_CONF_NUM_CMDS_SHIFT                       (16)


#define AHB_TRIG_REG_TRIGGER_15_CONF                                      (AHB_TRIG_REG_BASE + 0xfc)
#define AHB_TRIG_REG_TRIGGER_15_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_15_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_15_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_15_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_15_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_15_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_15_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_15_CONF_NUM_CMDS_SHIFT                       (16)


#define AHB_TRIG_REG_TRIGGER_16_CONF                                      (AHB_TRIG_REG_BASE + 0x100)
#define AHB_TRIG_REG_TRIGGER_16_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_16_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_16_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_16_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_16_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_16_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_16_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_16_CONF_NUM_CMDS_SHIFT                       (16)


#define AHB_TRIG_REG_TRIGGER_17_CONF                                      (AHB_TRIG_REG_BASE + 0x104)
#define AHB_TRIG_REG_TRIGGER_17_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_17_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_17_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_17_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_17_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_17_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_17_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_17_CONF_NUM_CMDS_SHIFT                       (16)


#define AHB_TRIG_REG_TRIGGER_18_CONF                                      (AHB_TRIG_REG_BASE + 0x108)
#define AHB_TRIG_REG_TRIGGER_18_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_18_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_18_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_18_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_18_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_18_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_18_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_18_CONF_NUM_CMDS_SHIFT                       (16)


#define AHB_TRIG_REG_TRIGGER_19_CONF                                      (AHB_TRIG_REG_BASE + 0x10c)
#define AHB_TRIG_REG_TRIGGER_19_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_19_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_19_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_19_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_19_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_19_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_19_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_19_CONF_NUM_CMDS_SHIFT                       (16)


#define AHB_TRIG_REG_TRIGGER_20_CONF                                      (AHB_TRIG_REG_BASE + 0x110)
#define AHB_TRIG_REG_TRIGGER_20_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_20_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_20_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_20_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_20_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_20_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_20_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_20_CONF_NUM_CMDS_SHIFT                       (16)


#define AHB_TRIG_REG_TRIGGER_21_CONF                                      (AHB_TRIG_REG_BASE + 0x114)
#define AHB_TRIG_REG_TRIGGER_21_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_21_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_21_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_21_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_21_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_21_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_21_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_21_CONF_NUM_CMDS_SHIFT                       (16)


#define AHB_TRIG_REG_TRIGGER_22_CONF                                      (AHB_TRIG_REG_BASE + 0x118)
#define AHB_TRIG_REG_TRIGGER_22_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_22_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_22_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_22_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_22_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_22_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_22_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_22_CONF_NUM_CMDS_SHIFT                       (16)


#define AHB_TRIG_REG_TRIGGER_23_CONF                                      (AHB_TRIG_REG_BASE + 0x11c)
#define AHB_TRIG_REG_TRIGGER_23_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_23_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_23_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_23_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_23_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_23_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_23_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_23_CONF_NUM_CMDS_SHIFT                       (16)


#define AHB_TRIG_REG_TRIGGER_24_CONF                                      (AHB_TRIG_REG_BASE + 0x120)
#define AHB_TRIG_REG_TRIGGER_24_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_24_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_24_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_24_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_24_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_24_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_24_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_24_CONF_NUM_CMDS_SHIFT                       (16)


#define AHB_TRIG_REG_TRIGGER_25_CONF                                      (AHB_TRIG_REG_BASE + 0x124)
#define AHB_TRIG_REG_TRIGGER_25_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_25_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_25_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_25_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_25_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_25_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_25_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_25_CONF_NUM_CMDS_SHIFT                       (16)


#define AHB_TRIG_REG_TRIGGER_26_CONF                                      (AHB_TRIG_REG_BASE + 0x128)
#define AHB_TRIG_REG_TRIGGER_26_CONF_DEFAULT                              0x0
#define AHB_TRIG_REG_TRIGGER_26_CONF_EN                                   (Bit0)
#define AHB_TRIG_REG_TRIGGER_26_CONF_ADDR_OFFSET                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AHB_TRIG_REG_TRIGGER_26_CONF_ADDR_OFFSET_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_26_CONF_ADDR_OFFSET_SHIFT                    (4)
#define AHB_TRIG_REG_TRIGGER_26_CONF_NUM_CMDS                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AHB_TRIG_REG_TRIGGER_26_CONF_NUM_CMDS_MASK                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AHB_TRIG_REG_TRIGGER_26_CONF_NUM_CMDS_SHIFT                       (16)


