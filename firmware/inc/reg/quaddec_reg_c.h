#ifndef _QUADDEC_REG_DEFINES_H
#define _QUADDEC_REG_DEFINES_H
/* **************************** */
#define QUADDEC_REG_INTERRUPT_STATUS                                                                (QUADDEC_REG_BASE + 0x0)
#define QUADDEC_REG_INTERRUPT_STATUS_DEFAULT                                                        0x0
#define QUADDEC_REG_INTERRUPT_STATUS_COUNTER                                                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define QUADDEC_REG_INTERRUPT_STATUS_COUNTER_MASK                                                   (Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INTERRUPT_STATUS_COUNTER_SHIFT                                                  (0)


#define QUADDEC_REG_INTERRUPT_MASK_STATUS                                                           (QUADDEC_REG_BASE + 0x4)
#define QUADDEC_REG_INTERRUPT_MASK_STATUS_DEFAULT                                                   0x0
#define QUADDEC_REG_INTERRUPT_MASK_STATUS_COUNTER                                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define QUADDEC_REG_INTERRUPT_MASK_STATUS_COUNTER_MASK                                              (Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INTERRUPT_MASK_STATUS_COUNTER_SHIFT                                             (0)


#define QUADDEC_REG_INTERRUPT_CLEAR                                                                 (QUADDEC_REG_BASE + 0x8)
#define QUADDEC_REG_INTERRUPT_CLEAR_DEFAULT                                                         0x0
#define QUADDEC_REG_INTERRUPT_CLEAR_COUNTER                                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define QUADDEC_REG_INTERRUPT_CLEAR_COUNTER_MASK                                                    (Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INTERRUPT_CLEAR_COUNTER_SHIFT                                                   (0)


#define QUADDEC_REG_INTERRUPT_SET                                                                   (QUADDEC_REG_BASE + 0xc)
#define QUADDEC_REG_INTERRUPT_SET_DEFAULT                                                           0x0
#define QUADDEC_REG_INTERRUPT_SET_COUNTER                                                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define QUADDEC_REG_INTERRUPT_SET_COUNTER_MASK                                                      (Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INTERRUPT_SET_COUNTER_SHIFT                                                     (0)


#define QUADDEC_REG_INTERRUPT_MASK_SET                                                              (QUADDEC_REG_BASE + 0x10)
#define QUADDEC_REG_INTERRUPT_MASK_SET_DEFAULT                                                      0x0
#define QUADDEC_REG_INTERRUPT_MASK_SET_COUNTER                                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define QUADDEC_REG_INTERRUPT_MASK_SET_COUNTER_MASK                                                 (Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INTERRUPT_MASK_SET_COUNTER_SHIFT                                                (0)


#define QUADDEC_REG_INTERRUPT_MASK_CLEAR                                                            (QUADDEC_REG_BASE + 0x14)
#define QUADDEC_REG_INTERRUPT_MASK_CLEAR_DEFAULT                                                    0x0
#define QUADDEC_REG_INTERRUPT_MASK_CLEAR_COUNTER                                                    (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define QUADDEC_REG_INTERRUPT_MASK_CLEAR_COUNTER_MASK                                               (Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INTERRUPT_MASK_CLEAR_COUNTER_SHIFT                                              (0)


#define QUADDEC_REG_MISC_CTRL                                                                       (QUADDEC_REG_BASE + 0x20)
#define QUADDEC_REG_MISC_CTRL_DEFAULT                                                               0x14700700
#define QUADDEC_REG_MISC_CTRL_CTL_QUADDEC_ENABLE                                                    (Bit0+Bit1+Bit2)
#define QUADDEC_REG_MISC_CTRL_CTL_QUADDEC_ENABLE_MASK                                               (Bit2+Bit1+Bit0)
#define QUADDEC_REG_MISC_CTRL_CTL_QUADDEC_ENABLE_SHIFT                                              (0)
#define QUADDEC_REG_MISC_CTRL_CTL_INDEX_EN                                                          (Bit4+Bit5+Bit6)
#define QUADDEC_REG_MISC_CTRL_CTL_INDEX_EN_MASK                                                     (Bit2+Bit1+Bit0)
#define QUADDEC_REG_MISC_CTRL_CTL_INDEX_EN_SHIFT                                                    (4)
#define QUADDEC_REG_MISC_CTRL_CTL_INDEX_POLARITY                                                    (Bit8+Bit9+Bit10)
#define QUADDEC_REG_MISC_CTRL_CTL_INDEX_POLARITY_MASK                                               (Bit2+Bit1+Bit0)
#define QUADDEC_REG_MISC_CTRL_CTL_INDEX_POLARITY_SHIFT                                              (8)
#define QUADDEC_REG_MISC_CTRL_CTL_DEBOUNCE_EN                                                       (Bit12+Bit13+Bit14)
#define QUADDEC_REG_MISC_CTRL_CTL_DEBOUNCE_EN_MASK                                                  (Bit2+Bit1+Bit0)
#define QUADDEC_REG_MISC_CTRL_CTL_DEBOUNCE_EN_SHIFT                                                 (12)
#define QUADDEC_REG_MISC_CTRL_CTL_LED_EN                                                            (Bit16+Bit17+Bit18)
#define QUADDEC_REG_MISC_CTRL_CTL_LED_EN_MASK                                                       (Bit2+Bit1+Bit0)
#define QUADDEC_REG_MISC_CTRL_CTL_LED_EN_SHIFT                                                      (16)
#define QUADDEC_REG_MISC_CTRL_CTL_LED_POLARITY                                                      (Bit20+Bit21+Bit22)
#define QUADDEC_REG_MISC_CTRL_CTL_LED_POLARITY_MASK                                                 (Bit2+Bit1+Bit0)
#define QUADDEC_REG_MISC_CTRL_CTL_LED_POLARITY_SHIFT                                                (20)
#define QUADDEC_REG_MISC_CTRL_CTL_NUM_CLK_IN_US_M1                                                  (Bit24+Bit25+Bit26+Bit27)
#define QUADDEC_REG_MISC_CTRL_CTL_NUM_CLK_IN_US_M1_MASK                                             (Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_MISC_CTRL_CTL_NUM_CLK_IN_US_M1_SHIFT                                            (24)
#define QUADDEC_REG_MISC_CTRL_CTL_MV_DIRECTION                                                      (Bit28+Bit29+Bit30)
#define QUADDEC_REG_MISC_CTRL_CTL_MV_DIRECTION_MASK                                                 (Bit2+Bit1+Bit0)
#define QUADDEC_REG_MISC_CTRL_CTL_MV_DIRECTION_SHIFT                                                (28)


#define QUADDEC_REG_INTERVAL_SETTING                                                                (QUADDEC_REG_BASE + 0x24)
#define QUADDEC_REG_INTERVAL_SETTING_DEFAULT                                                        0x100000
#define QUADDEC_REG_INTERVAL_SETTING_CTL_SAMPLE_INTERVAL_M1                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define QUADDEC_REG_INTERVAL_SETTING_CTL_SAMPLE_INTERVAL_M1_MASK                                    (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INTERVAL_SETTING_CTL_SAMPLE_INTERVAL_M1_SHIFT                                   (0)
#define QUADDEC_REG_INTERVAL_SETTING_CTL_LED_INTERVAL                                               (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define QUADDEC_REG_INTERVAL_SETTING_CTL_LED_INTERVAL_MASK                                          (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INTERVAL_SETTING_CTL_LED_INTERVAL_SHIFT                                         (16)


#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT0                                                           (QUADDEC_REG_BASE + 0x40)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT0_DEFAULT                                                   0x230
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT0_CTL_PIN_A_SEL0                                            (Bit0+Bit1)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT0_CTL_PIN_A_SEL0_MASK                                       (Bit1+Bit0)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT0_CTL_PIN_A_SEL0_SHIFT                                      (0)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT0_CTL_PIN_B_SEL0                                            (Bit4+Bit5)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT0_CTL_PIN_B_SEL0_MASK                                       (Bit1+Bit0)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT0_CTL_PIN_B_SEL0_SHIFT                                      (4)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT0_CTL_PIN_IDX_SEL0                                          (Bit8+Bit9)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT0_CTL_PIN_IDX_SEL0_MASK                                     (Bit1+Bit0)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT0_CTL_PIN_IDX_SEL0_SHIFT                                    (8)


#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT1                                                           (QUADDEC_REG_BASE + 0x44)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT1_DEFAULT                                                   0x230
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT1_CTL_PIN_A_SEL1                                            (Bit0+Bit1)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT1_CTL_PIN_A_SEL1_MASK                                       (Bit1+Bit0)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT1_CTL_PIN_A_SEL1_SHIFT                                      (0)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT1_CTL_PIN_B_SEL1                                            (Bit4+Bit5)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT1_CTL_PIN_B_SEL1_MASK                                       (Bit1+Bit0)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT1_CTL_PIN_B_SEL1_SHIFT                                      (4)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT1_CTL_PIN_IDX_SEL1                                          (Bit8+Bit9)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT1_CTL_PIN_IDX_SEL1_MASK                                     (Bit1+Bit0)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT1_CTL_PIN_IDX_SEL1_SHIFT                                    (8)


#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT2                                                           (QUADDEC_REG_BASE + 0x48)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT2_DEFAULT                                                   0x230
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT2_CTL_PIN_A_SEL2                                            (Bit0+Bit1)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT2_CTL_PIN_A_SEL2_MASK                                       (Bit1+Bit0)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT2_CTL_PIN_A_SEL2_SHIFT                                      (0)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT2_CTL_PIN_B_SEL2                                            (Bit4+Bit5)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT2_CTL_PIN_B_SEL2_MASK                                       (Bit1+Bit0)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT2_CTL_PIN_B_SEL2_SHIFT                                      (4)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT2_CTL_PIN_IDX_SEL2                                          (Bit8+Bit9)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT2_CTL_PIN_IDX_SEL2_MASK                                     (Bit1+Bit0)
#define QUADDEC_REG_INPUT_PIN_ASSIGNMENT2_CTL_PIN_IDX_SEL2_SHIFT                                    (8)


#define QUADDEC_REG_REPORT_INTERVAL                                                                 (QUADDEC_REG_BASE + 0x4c)
#define QUADDEC_REG_REPORT_INTERVAL_DEFAULT                                                         0x0
#define QUADDEC_REG_REPORT_INTERVAL_CTL_REPORT_INTERVAL_M1                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define QUADDEC_REG_REPORT_INTERVAL_CTL_REPORT_INTERVAL_M1_MASK                                     (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_REPORT_INTERVAL_CTL_REPORT_INTERVAL_M1_SHIFT                                    (0)


#define QUADDEC_REG_COUNTER_LMT                                                                     (QUADDEC_REG_BASE + 0x50)
#define QUADDEC_REG_COUNTER_LMT_DEFAULT                                                             0x80007FFF
#define QUADDEC_REG_COUNTER_LMT_CTL_COUNTER_UPPER_LIMIT                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define QUADDEC_REG_COUNTER_LMT_CTL_COUNTER_UPPER_LIMIT_MASK                                        (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_COUNTER_LMT_CTL_COUNTER_UPPER_LIMIT_SHIFT                                       (0)
#define QUADDEC_REG_COUNTER_LMT_CTL_COUNTER_LOWER_LIMIT                                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define QUADDEC_REG_COUNTER_LMT_CTL_COUNTER_LOWER_LIMIT_MASK                                        (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_COUNTER_LMT_CTL_COUNTER_LOWER_LIMIT_SHIFT                                       (16)


#define QUADDEC_REG_COUNTER_INIT                                                                    (QUADDEC_REG_BASE + 0x54)
#define QUADDEC_REG_COUNTER_INIT_DEFAULT                                                            0x0
#define QUADDEC_REG_COUNTER_INIT_CTL_COUNTER_INIT_VALUE                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define QUADDEC_REG_COUNTER_INIT_CTL_COUNTER_INIT_VALUE_MASK                                        (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_COUNTER_INIT_CTL_COUNTER_INIT_VALUE_SHIFT                                       (0)
#define QUADDEC_REG_COUNTER_INIT_CTL_COUNTER_IDX_INIT_VALUE                                         (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define QUADDEC_REG_COUNTER_INIT_CTL_COUNTER_IDX_INIT_VALUE_MASK                                    (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_COUNTER_INIT_CTL_COUNTER_IDX_INIT_VALUE_SHIFT                                   (16)


#define QUADDEC_REG_COUNTER_CLEAR                                                                   (QUADDEC_REG_BASE + 0x5c)
#define QUADDEC_REG_COUNTER_CLEAR_DEFAULT                                                           0x0
#define QUADDEC_REG_COUNTER_CLEAR_CTL_CLR_SMPL_COUNTER                                              (Bit0)
#define QUADDEC_REG_COUNTER_CLEAR_CTL_CLR_DB_COUNTER                                                (Bit4)
#define QUADDEC_REG_COUNTER_CLEAR_CTL_CLR_IDX_DETECT_COUNTER                                        (Bit8)
#define QUADDEC_REG_COUNTER_CLEAR_CTL_CLR_IDX_PATTERN_MATCH_COUNTER                                 (Bit9)
#define QUADDEC_REG_COUNTER_CLEAR_CTL_CLR_IDX_PATTERN_MISMATCH_COUNTER                              (Bit10)
#define QUADDEC_REG_COUNTER_CLEAR_CTL_CLR_IDX_INIT_VAL_MISMATCH_COUNTER                             (Bit11)


#define QUADDEC_REG_SAMPLE_COUNTER0                                                                 (QUADDEC_REG_BASE + 0x60)
#define QUADDEC_REG_SAMPLE_COUNTER0_DEFAULT                                                         0x0
#define QUADDEC_REG_SAMPLE_COUNTER0_STS_SAMPLE_COUNTER0                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define QUADDEC_REG_SAMPLE_COUNTER0_STS_SAMPLE_COUNTER0_MASK                                        (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_SAMPLE_COUNTER0_STS_SAMPLE_COUNTER0_SHIFT                                       (0)
#define QUADDEC_REG_SAMPLE_COUNTER0_STS_REPORT_SAMPLE_COUNTER0                                      (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define QUADDEC_REG_SAMPLE_COUNTER0_STS_REPORT_SAMPLE_COUNTER0_MASK                                 (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_SAMPLE_COUNTER0_STS_REPORT_SAMPLE_COUNTER0_SHIFT                                (16)


#define QUADDEC_REG_SAMPLE_COUNTER1                                                                 (QUADDEC_REG_BASE + 0x64)
#define QUADDEC_REG_SAMPLE_COUNTER1_DEFAULT                                                         0x0
#define QUADDEC_REG_SAMPLE_COUNTER1_STS_SAMPLE_COUNTER1                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define QUADDEC_REG_SAMPLE_COUNTER1_STS_SAMPLE_COUNTER1_MASK                                        (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_SAMPLE_COUNTER1_STS_SAMPLE_COUNTER1_SHIFT                                       (0)
#define QUADDEC_REG_SAMPLE_COUNTER1_STS_REPORT_SAMPLE_COUNTER1                                      (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define QUADDEC_REG_SAMPLE_COUNTER1_STS_REPORT_SAMPLE_COUNTER1_MASK                                 (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_SAMPLE_COUNTER1_STS_REPORT_SAMPLE_COUNTER1_SHIFT                                (16)


#define QUADDEC_REG_SAMPLE_COUNTER2                                                                 (QUADDEC_REG_BASE + 0x68)
#define QUADDEC_REG_SAMPLE_COUNTER2_DEFAULT                                                         0x0
#define QUADDEC_REG_SAMPLE_COUNTER2_STS_SAMPLE_COUNTER2                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define QUADDEC_REG_SAMPLE_COUNTER2_STS_SAMPLE_COUNTER2_MASK                                        (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_SAMPLE_COUNTER2_STS_SAMPLE_COUNTER2_SHIFT                                       (0)
#define QUADDEC_REG_SAMPLE_COUNTER2_STS_REPORT_SAMPLE_COUNTER2                                      (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define QUADDEC_REG_SAMPLE_COUNTER2_STS_REPORT_SAMPLE_COUNTER2_MASK                                 (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_SAMPLE_COUNTER2_STS_REPORT_SAMPLE_COUNTER2_SHIFT                                (16)


#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT0                                                   (QUADDEC_REG_BASE + 0x6c)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT0_DEFAULT                                           0x0
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT0_STS_DOUBLE_DISPLACEMENT_COUNTER0                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT0_STS_DOUBLE_DISPLACEMENT_COUNTER0_MASK             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT0_STS_DOUBLE_DISPLACEMENT_COUNTER0_SHIFT            (0)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT0_STS_CURRENT_QUADA0                                (Bit8)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT0_STS_CURRENT_QUADB0                                (Bit9)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT0_STS_CURRENT_QUADIDX0                              (Bit10)


#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT1                                                   (QUADDEC_REG_BASE + 0x70)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT1_DEFAULT                                           0x0
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT1_STS_DOUBLE_DISPLACEMENT_COUNTER1                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT1_STS_DOUBLE_DISPLACEMENT_COUNTER1_MASK             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT1_STS_DOUBLE_DISPLACEMENT_COUNTER1_SHIFT            (0)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT1_STS_CURRENT_QUADA1                                (Bit8)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT1_STS_CURRENT_QUADB1                                (Bit9)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT1_STS_CURRENT_QUADIDX1                              (Bit10)


#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT2                                                   (QUADDEC_REG_BASE + 0x74)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT2_DEFAULT                                           0x0
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT2_STS_DOUBLE_DISPLACEMENT_COUNTER2                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT2_STS_DOUBLE_DISPLACEMENT_COUNTER2_MASK             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT2_STS_DOUBLE_DISPLACEMENT_COUNTER2_SHIFT            (0)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT2_STS_CURRENT_QUADA2                                (Bit8)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT2_STS_CURRENT_QUADB2                                (Bit9)
#define QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT2_STS_CURRENT_QUADIDX2                              (Bit10)


#define QUADDEC_REG_INDEX_CTRL                                                                      (QUADDEC_REG_BASE + 0x78)
#define QUADDEC_REG_INDEX_CTRL_DEFAULT                                                              0x1
#define QUADDEC_REG_INDEX_CTRL_INDEX_RESET_EN                                                       (Bit0)
#define QUADDEC_REG_INDEX_CTRL_CTL_INDEX_PATTERN_LEN                                                (Bit4+Bit5+Bit6)
#define QUADDEC_REG_INDEX_CTRL_CTL_INDEX_PATTERN_LEN_MASK                                           (Bit2+Bit1+Bit0)
#define QUADDEC_REG_INDEX_CTRL_CTL_INDEX_PATTERN_LEN_SHIFT                                          (4)
#define QUADDEC_REG_INDEX_CTRL_CTL_INDEX_PATTERN0                                                   (Bit8+Bit9)
#define QUADDEC_REG_INDEX_CTRL_CTL_INDEX_PATTERN0_MASK                                              (Bit1+Bit0)
#define QUADDEC_REG_INDEX_CTRL_CTL_INDEX_PATTERN0_SHIFT                                             (8)
#define QUADDEC_REG_INDEX_CTRL_CTL_INDEX_PATTERN1                                                   (Bit12+Bit13)
#define QUADDEC_REG_INDEX_CTRL_CTL_INDEX_PATTERN1_MASK                                              (Bit1+Bit0)
#define QUADDEC_REG_INDEX_CTRL_CTL_INDEX_PATTERN1_SHIFT                                             (12)
#define QUADDEC_REG_INDEX_CTRL_CTL_INDEX_PATTERN2                                                   (Bit16+Bit17)
#define QUADDEC_REG_INDEX_CTRL_CTL_INDEX_PATTERN2_MASK                                              (Bit1+Bit0)
#define QUADDEC_REG_INDEX_CTRL_CTL_INDEX_PATTERN2_SHIFT                                             (16)
#define QUADDEC_REG_INDEX_CTRL_CTL_INDEX_PATTERN3                                                   (Bit20+Bit21)
#define QUADDEC_REG_INDEX_CTRL_CTL_INDEX_PATTERN3_MASK                                              (Bit1+Bit0)
#define QUADDEC_REG_INDEX_CTRL_CTL_INDEX_PATTERN3_SHIFT                                             (20)


#define QUADDEC_REG_INDEX_COUNTER0                                                                  (QUADDEC_REG_BASE + 0x7c)
#define QUADDEC_REG_INDEX_COUNTER0_DEFAULT                                                          0x0
#define QUADDEC_REG_INDEX_COUNTER0_STS_INDEX_DETECT_COUNTER0                                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define QUADDEC_REG_INDEX_COUNTER0_STS_INDEX_DETECT_COUNTER0_MASK                                   (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INDEX_COUNTER0_STS_INDEX_DETECT_COUNTER0_SHIFT                                  (0)
#define QUADDEC_REG_INDEX_COUNTER0_STS_INDEX_PATTERN_MATCH_COUNTER0                                 (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define QUADDEC_REG_INDEX_COUNTER0_STS_INDEX_PATTERN_MATCH_COUNTER0_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INDEX_COUNTER0_STS_INDEX_PATTERN_MATCH_COUNTER0_SHIFT                           (8)
#define QUADDEC_REG_INDEX_COUNTER0_STS_INDEX_PATTERN_MISMATCH_COUNTER0                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define QUADDEC_REG_INDEX_COUNTER0_STS_INDEX_PATTERN_MISMATCH_COUNTER0_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INDEX_COUNTER0_STS_INDEX_PATTERN_MISMATCH_COUNTER0_SHIFT                        (16)
#define QUADDEC_REG_INDEX_COUNTER0_STS_INDEX_INIT_VAL_MISMATCH_COUNTER0                             (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define QUADDEC_REG_INDEX_COUNTER0_STS_INDEX_INIT_VAL_MISMATCH_COUNTER0_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INDEX_COUNTER0_STS_INDEX_INIT_VAL_MISMATCH_COUNTER0_SHIFT                       (24)


#define QUADDEC_REG_INDEX_COUNTER1                                                                  (QUADDEC_REG_BASE + 0x80)
#define QUADDEC_REG_INDEX_COUNTER1_DEFAULT                                                          0x0
#define QUADDEC_REG_INDEX_COUNTER1_STS_INDEX_DETECT_COUNTER1                                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define QUADDEC_REG_INDEX_COUNTER1_STS_INDEX_DETECT_COUNTER1_MASK                                   (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INDEX_COUNTER1_STS_INDEX_DETECT_COUNTER1_SHIFT                                  (0)
#define QUADDEC_REG_INDEX_COUNTER1_STS_INDEX_PATTERN_MATCH_COUNTER1                                 (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define QUADDEC_REG_INDEX_COUNTER1_STS_INDEX_PATTERN_MATCH_COUNTER1_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INDEX_COUNTER1_STS_INDEX_PATTERN_MATCH_COUNTER1_SHIFT                           (8)
#define QUADDEC_REG_INDEX_COUNTER1_STS_INDEX_PATTERN_MISMATCH_COUNTER1                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define QUADDEC_REG_INDEX_COUNTER1_STS_INDEX_PATTERN_MISMATCH_COUNTER1_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INDEX_COUNTER1_STS_INDEX_PATTERN_MISMATCH_COUNTER1_SHIFT                        (16)
#define QUADDEC_REG_INDEX_COUNTER1_STS_INDEX_INIT_VAL_MISMATCH_COUNTER1                             (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define QUADDEC_REG_INDEX_COUNTER1_STS_INDEX_INIT_VAL_MISMATCH_COUNTER1_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INDEX_COUNTER1_STS_INDEX_INIT_VAL_MISMATCH_COUNTER1_SHIFT                       (24)


#define QUADDEC_REG_INDEX_COUNTER2                                                                  (QUADDEC_REG_BASE + 0x84)
#define QUADDEC_REG_INDEX_COUNTER2_DEFAULT                                                          0x0
#define QUADDEC_REG_INDEX_COUNTER2_STS_INDEX_DETECT_COUNTER2                                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define QUADDEC_REG_INDEX_COUNTER2_STS_INDEX_DETECT_COUNTER2_MASK                                   (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INDEX_COUNTER2_STS_INDEX_DETECT_COUNTER2_SHIFT                                  (0)
#define QUADDEC_REG_INDEX_COUNTER2_STS_INDEX_PATTERN_MATCH_COUNTER2                                 (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define QUADDEC_REG_INDEX_COUNTER2_STS_INDEX_PATTERN_MATCH_COUNTER2_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INDEX_COUNTER2_STS_INDEX_PATTERN_MATCH_COUNTER2_SHIFT                           (8)
#define QUADDEC_REG_INDEX_COUNTER2_STS_INDEX_PATTERN_MISMATCH_COUNTER2                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define QUADDEC_REG_INDEX_COUNTER2_STS_INDEX_PATTERN_MISMATCH_COUNTER2_MASK                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INDEX_COUNTER2_STS_INDEX_PATTERN_MISMATCH_COUNTER2_SHIFT                        (16)
#define QUADDEC_REG_INDEX_COUNTER2_STS_INDEX_INIT_VAL_MISMATCH_COUNTER2                             (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define QUADDEC_REG_INDEX_COUNTER2_STS_INDEX_INIT_VAL_MISMATCH_COUNTER2_MASK                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INDEX_COUNTER2_STS_INDEX_INIT_VAL_MISMATCH_COUNTER2_SHIFT                       (24)


#define QUADDEC_REG_INTERVAL_LED_SETTING_M0                                                         (QUADDEC_REG_BASE + 0x88)
#define QUADDEC_REG_INTERVAL_LED_SETTING_M0_DEFAULT                                                 0x0
#define QUADDEC_REG_INTERVAL_LED_SETTING_M0_O_SAMPLE_NUM_EN_LED_M0                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define QUADDEC_REG_INTERVAL_LED_SETTING_M0_O_SAMPLE_NUM_EN_LED_M0_MASK                             (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INTERVAL_LED_SETTING_M0_O_SAMPLE_NUM_EN_LED_M0_SHIFT                            (0)


#define QUADDEC_REG_INTERVAL_LED_SETTING_M1                                                         (QUADDEC_REG_BASE + 0x8c)
#define QUADDEC_REG_INTERVAL_LED_SETTING_M1_DEFAULT                                                 0x0
#define QUADDEC_REG_INTERVAL_LED_SETTING_M1_O_SAMPLE_NUM_EN_LED_M1                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define QUADDEC_REG_INTERVAL_LED_SETTING_M1_O_SAMPLE_NUM_EN_LED_M1_MASK                             (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INTERVAL_LED_SETTING_M1_O_SAMPLE_NUM_EN_LED_M1_SHIFT                            (0)


#define QUADDEC_REG_INTERVAL_LED_SETTING_M2                                                         (QUADDEC_REG_BASE + 0x90)
#define QUADDEC_REG_INTERVAL_LED_SETTING_M2_DEFAULT                                                 0x0
#define QUADDEC_REG_INTERVAL_LED_SETTING_M2_O_SAMPLE_NUM_EN_LED_M2                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define QUADDEC_REG_INTERVAL_LED_SETTING_M2_O_SAMPLE_NUM_EN_LED_M2_MASK                             (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define QUADDEC_REG_INTERVAL_LED_SETTING_M2_O_SAMPLE_NUM_EN_LED_M2_SHIFT                            (0)


#endif // _QUADDEC_REG_DEFINES_H

