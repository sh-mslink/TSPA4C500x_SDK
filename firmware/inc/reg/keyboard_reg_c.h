#ifndef _KEYBOARD_REG_DEFINES_H
#define _KEYBOARD_REG_DEFINES_H
/* **************************** */
#define KEYBOARD_REG_INTR_STATUS                                           (KEYBOARD_REG_BASE + 0x0)
#define KEYBOARD_REG_INTR_STATUS_DEFAULT                                   0x0
#define KEYBOARD_REG_INTR_STATUS_KEY_UPDATE                                (Bit0)


#define KEYBOARD_REG_INTR_MASK_STATUS                                      (KEYBOARD_REG_BASE + 0x4)
#define KEYBOARD_REG_INTR_MASK_STATUS_DEFAULT                              0x0
#define KEYBOARD_REG_INTR_MASK_STATUS_KEY_UPDATE                           (Bit0)


#define KEYBOARD_REG_INTR_CLEAR                                            (KEYBOARD_REG_BASE + 0x8)
#define KEYBOARD_REG_INTR_CLEAR_DEFAULT                                    0x0
#define KEYBOARD_REG_INTR_CLEAR_KEY_UPDATE                                 (Bit0)


#define KEYBOARD_REG_INTR_SET                                              (KEYBOARD_REG_BASE + 0xc)
#define KEYBOARD_REG_INTR_SET_DEFAULT                                      0x0
#define KEYBOARD_REG_INTR_SET_KEY_UPDATE                                   (Bit0)


#define KEYBOARD_REG_INTR_MASK_SET                                         (KEYBOARD_REG_BASE + 0x10)
#define KEYBOARD_REG_INTR_MASK_SET_DEFAULT                                 0x0
#define KEYBOARD_REG_INTR_MASK_SET_KEY_UPDATE                              (Bit0)


#define KEYBOARD_REG_INTR_MASK_CLEAR                                       (KEYBOARD_REG_BASE + 0x14)
#define KEYBOARD_REG_INTR_MASK_CLEAR_DEFAULT                               0x0
#define KEYBOARD_REG_INTR_MASK_CLEAR_KEY_UPDATE                            (Bit0)


#define KEYBOARD_REG_MISC_CTRL                                             (KEYBOARD_REG_BASE + 0x40)
#define KEYBOARD_REG_MISC_CTRL_DEFAULT                                     0x101030
#define KEYBOARD_REG_MISC_CTRL_CTL_ENABLE                                  (Bit0)
#define KEYBOARD_REG_MISC_CTRL_CTL_RST_INTR_CTRL                           (Bit1)
#define KEYBOARD_REG_MISC_CTRL_CTL_SCAN_FREQ                               (Bit4+Bit5)
#define KEYBOARD_REG_MISC_CTRL_CTL_SCAN_FREQ_MASK                          (Bit1+Bit0)
#define KEYBOARD_REG_MISC_CTRL_CTL_SCAN_FREQ_SHIFT                         (4)
#define KEYBOARD_REG_MISC_CTRL_CTL_PRESS_DEB_LMT                           (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define KEYBOARD_REG_MISC_CTRL_CTL_PRESS_DEB_LMT_MASK                      (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define KEYBOARD_REG_MISC_CTRL_CTL_PRESS_DEB_LMT_SHIFT                     (8)
#define KEYBOARD_REG_MISC_CTRL_CTL_RELEASE_DEB_LMT                         (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22)
#define KEYBOARD_REG_MISC_CTRL_CTL_RELEASE_DEB_LMT_MASK                    (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define KEYBOARD_REG_MISC_CTRL_CTL_RELEASE_DEB_LMT_SHIFT                   (16)
#define KEYBOARD_REG_MISC_CTRL_CTL_SAMPLE_VALID_THRESHOLD                  (Bit24+Bit25+Bit26+Bit27+Bit28)
#define KEYBOARD_REG_MISC_CTRL_CTL_SAMPLE_VALID_THRESHOLD_MASK             (Bit4+Bit3+Bit2+Bit1+Bit0)
#define KEYBOARD_REG_MISC_CTRL_CTL_SAMPLE_VALID_THRESHOLD_SHIFT            (24)


#define KEYBOARD_REG_NUM_COL_ROW                                           (KEYBOARD_REG_BASE + 0x44)
#define KEYBOARD_REG_NUM_COL_ROW_DEFAULT                                   0x404
#define KEYBOARD_REG_NUM_COL_ROW_CTL_NUM_COL                               (Bit0+Bit1+Bit2+Bit3+Bit4)
#define KEYBOARD_REG_NUM_COL_ROW_CTL_NUM_COL_MASK                          (Bit4+Bit3+Bit2+Bit1+Bit0)
#define KEYBOARD_REG_NUM_COL_ROW_CTL_NUM_COL_SHIFT                         (0)
#define KEYBOARD_REG_NUM_COL_ROW_CTL_NUM_ROW                               (Bit8+Bit9+Bit10+Bit11+Bit12)
#define KEYBOARD_REG_NUM_COL_ROW_CTL_NUM_ROW_MASK                          (Bit4+Bit3+Bit2+Bit1+Bit0)
#define KEYBOARD_REG_NUM_COL_ROW_CTL_NUM_ROW_SHIFT                         (8)


#define KEYBOARD_REG_HALF_MS_CNT                                           (KEYBOARD_REG_BASE + 0x48)
#define KEYBOARD_REG_HALF_MS_CNT_DEFAULT                                   0xFA0
#define KEYBOARD_REG_HALF_MS_CNT_CTL_HALF_MS_CNT                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define KEYBOARD_REG_HALF_MS_CNT_CTL_HALF_MS_CNT_MASK                      (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define KEYBOARD_REG_HALF_MS_CNT_CTL_HALF_MS_CNT_SHIFT                     (0)


#define KEYBOARD_REG_STATUS_A01                                            (KEYBOARD_REG_BASE + 0x50)
#define KEYBOARD_REG_STATUS_A01_DEFAULT                                    0x0
#define KEYBOARD_REG_STATUS_A01_KEY_VALUE0                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define KEYBOARD_REG_STATUS_A01_KEY_VALUE0_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define KEYBOARD_REG_STATUS_A01_KEY_VALUE0_SHIFT                           (0)
#define KEYBOARD_REG_STATUS_A01_MULTI_KEY0                                 (Bit8)
#define KEYBOARD_REG_STATUS_A01_PRESS_RELEASE0                             (Bit9)
#define KEYBOARD_REG_STATUS_A01_KEY_VALUE1                                 (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define KEYBOARD_REG_STATUS_A01_KEY_VALUE1_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define KEYBOARD_REG_STATUS_A01_KEY_VALUE1_SHIFT                           (12)
#define KEYBOARD_REG_STATUS_A01_MULTI_KEY1                                 (Bit20)
#define KEYBOARD_REG_STATUS_A01_PRESS_RELEASE1                             (Bit21)


#define KEYBOARD_REG_STATUS_A23                                            (KEYBOARD_REG_BASE + 0x54)
#define KEYBOARD_REG_STATUS_A23_DEFAULT                                    0x0
#define KEYBOARD_REG_STATUS_A23_KEY_VALUE2                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define KEYBOARD_REG_STATUS_A23_KEY_VALUE2_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define KEYBOARD_REG_STATUS_A23_KEY_VALUE2_SHIFT                           (0)
#define KEYBOARD_REG_STATUS_A23_MULTI_KEY2                                 (Bit8)
#define KEYBOARD_REG_STATUS_A23_PRESS_RELEASE2                             (Bit9)
#define KEYBOARD_REG_STATUS_A23_KEY_VALUE3                                 (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define KEYBOARD_REG_STATUS_A23_KEY_VALUE3_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define KEYBOARD_REG_STATUS_A23_KEY_VALUE3_SHIFT                           (12)
#define KEYBOARD_REG_STATUS_A23_MULTI_KEY3                                 (Bit20)
#define KEYBOARD_REG_STATUS_A23_PRESS_RELEASE3                             (Bit21)


#define KEYBOARD_REG_STATUS_B01                                            (KEYBOARD_REG_BASE + 0x58)
#define KEYBOARD_REG_STATUS_B01_DEFAULT                                    0x0
#define KEYBOARD_REG_STATUS_B01_KEY_VALUE0                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define KEYBOARD_REG_STATUS_B01_KEY_VALUE0_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define KEYBOARD_REG_STATUS_B01_KEY_VALUE0_SHIFT                           (0)
#define KEYBOARD_REG_STATUS_B01_MULTI_KEY0                                 (Bit8)
#define KEYBOARD_REG_STATUS_B01_PRESS_RELEASE0                             (Bit9)
#define KEYBOARD_REG_STATUS_B01_KEY_VALUE1                                 (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define KEYBOARD_REG_STATUS_B01_KEY_VALUE1_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define KEYBOARD_REG_STATUS_B01_KEY_VALUE1_SHIFT                           (12)
#define KEYBOARD_REG_STATUS_B01_MULTI_KEY1                                 (Bit20)
#define KEYBOARD_REG_STATUS_B01_PRESS_RELEASE1                             (Bit21)


#define KEYBOARD_REG_STATUS_B23                                            (KEYBOARD_REG_BASE + 0x5c)
#define KEYBOARD_REG_STATUS_B23_DEFAULT                                    0x0
#define KEYBOARD_REG_STATUS_B23_KEY_VALUE2                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define KEYBOARD_REG_STATUS_B23_KEY_VALUE2_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define KEYBOARD_REG_STATUS_B23_KEY_VALUE2_SHIFT                           (0)
#define KEYBOARD_REG_STATUS_B23_MULTI_KEY2                                 (Bit8)
#define KEYBOARD_REG_STATUS_B23_PRESS_RELEASE2                             (Bit9)
#define KEYBOARD_REG_STATUS_B23_KEY_VALUE3                                 (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define KEYBOARD_REG_STATUS_B23_KEY_VALUE3_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define KEYBOARD_REG_STATUS_B23_KEY_VALUE3_SHIFT                           (12)
#define KEYBOARD_REG_STATUS_B23_MULTI_KEY3                                 (Bit20)
#define KEYBOARD_REG_STATUS_B23_PRESS_RELEASE3                             (Bit21)


#endif // _KEYBOARD_REG_DEFINES_H

