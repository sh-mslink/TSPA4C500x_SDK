#ifndef _GLOBAL_REG_DEFINES_H
#define _GLOBAL_REG_DEFINES_H
/* **************************** */
#define GLOBAL_REG_INTR_STATUS                                                                                             (GLOBAL_REG_BASE + 0x0)
#define GLOBAL_REG_INTR_STATUS_DEFAULT                                                                                     0x0
#define GLOBAL_REG_INTR_STATUS_AON_TIMER_0                                                                                 (Bit0)
#define GLOBAL_REG_INTR_STATUS_AON_TIMER_1                                                                                 (Bit1)
#define GLOBAL_REG_INTR_STATUS_PS_TRANS_DONE                                                                               (Bit2)
#define GLOBAL_REG_INTR_STATUS_EXT_0                                                                                       (Bit3)
#define GLOBAL_REG_INTR_STATUS_EXT_1                                                                                       (Bit4)
#define GLOBAL_REG_INTR_STATUS_PD_DOO_SLEEP_BLOCK_IRQ                                                                      (Bit5)
#define GLOBAL_REG_INTR_STATUS_OSC_EN                                                                                      (Bit6)


#define GLOBAL_REG_INTR_MASK_STATUS                                                                                        (GLOBAL_REG_BASE + 0x4)
#define GLOBAL_REG_INTR_MASK_STATUS_DEFAULT                                                                                0x0
#define GLOBAL_REG_INTR_MASK_STATUS_AON_TIMER_0                                                                            (Bit0)
#define GLOBAL_REG_INTR_MASK_STATUS_AON_TIMER_1                                                                            (Bit1)
#define GLOBAL_REG_INTR_MASK_STATUS_PS_TRANS_DONE                                                                          (Bit2)
#define GLOBAL_REG_INTR_MASK_STATUS_EXT_0                                                                                  (Bit3)
#define GLOBAL_REG_INTR_MASK_STATUS_EXT_1                                                                                  (Bit4)
#define GLOBAL_REG_INTR_MASK_STATUS_PD_DOO_SLEEP_BLOCK_IRQ                                                                 (Bit5)
#define GLOBAL_REG_INTR_MASK_STATUS_OSC_EN                                                                                 (Bit6)


#define GLOBAL_REG_INTR_CLEAR                                                                                              (GLOBAL_REG_BASE + 0x8)
#define GLOBAL_REG_INTR_CLEAR_DEFAULT                                                                                      0x0
#define GLOBAL_REG_INTR_CLEAR_AON_TIMER_0                                                                                  (Bit0)
#define GLOBAL_REG_INTR_CLEAR_AON_TIMER_1                                                                                  (Bit1)
#define GLOBAL_REG_INTR_CLEAR_PS_TRANS_DONE                                                                                (Bit2)
#define GLOBAL_REG_INTR_CLEAR_EXT_0                                                                                        (Bit3)
#define GLOBAL_REG_INTR_CLEAR_EXT_1                                                                                        (Bit4)
#define GLOBAL_REG_INTR_CLEAR_PD_DOO_SLEEP_BLOCK_IRQ                                                                       (Bit5)
#define GLOBAL_REG_INTR_CLEAR_OSC_EN                                                                                       (Bit6)


#define GLOBAL_REG_INTR_SET                                                                                                (GLOBAL_REG_BASE + 0xc)
#define GLOBAL_REG_INTR_SET_DEFAULT                                                                                        0x0
#define GLOBAL_REG_INTR_SET_AON_TIMER_0                                                                                    (Bit0)
#define GLOBAL_REG_INTR_SET_AON_TIMER_1                                                                                    (Bit1)
#define GLOBAL_REG_INTR_SET_PS_TRANS_DONE                                                                                  (Bit2)
#define GLOBAL_REG_INTR_SET_EXT_0                                                                                          (Bit3)
#define GLOBAL_REG_INTR_SET_EXT_1                                                                                          (Bit4)
#define GLOBAL_REG_INTR_SET_PD_DOO_SLEEP_BLOCK_IRQ                                                                         (Bit5)
#define GLOBAL_REG_INTR_SET_OSC_EN                                                                                         (Bit6)


#define GLOBAL_REG_INTR_MASK_SET                                                                                           (GLOBAL_REG_BASE + 0x10)
#define GLOBAL_REG_INTR_MASK_SET_DEFAULT                                                                                   0x0
#define GLOBAL_REG_INTR_MASK_SET_AON_TIMER_0                                                                               (Bit0)
#define GLOBAL_REG_INTR_MASK_SET_AON_TIMER_1                                                                               (Bit1)
#define GLOBAL_REG_INTR_MASK_SET_PS_TRANS_DONE                                                                             (Bit2)
#define GLOBAL_REG_INTR_MASK_SET_EXT_0                                                                                     (Bit3)
#define GLOBAL_REG_INTR_MASK_SET_EXT_1                                                                                     (Bit4)
#define GLOBAL_REG_INTR_MASK_SET_PD_DOO_SLEEP_BLOCK_IRQ                                                                    (Bit5)
#define GLOBAL_REG_INTR_MASK_SET_OSC_EN                                                                                    (Bit6)


#define GLOBAL_REG_INTR_MASK_CLEAR                                                                                         (GLOBAL_REG_BASE + 0x14)
#define GLOBAL_REG_INTR_MASK_CLEAR_DEFAULT                                                                                 0x0
#define GLOBAL_REG_INTR_MASK_CLEAR_AON_TIMER_0                                                                             (Bit0)
#define GLOBAL_REG_INTR_MASK_CLEAR_AON_TIMER_1                                                                             (Bit1)
#define GLOBAL_REG_INTR_MASK_CLEAR_PS_TRANS_DONE                                                                           (Bit2)
#define GLOBAL_REG_INTR_MASK_CLEAR_EXT_0                                                                                   (Bit3)
#define GLOBAL_REG_INTR_MASK_CLEAR_EXT_1                                                                                   (Bit4)
#define GLOBAL_REG_INTR_MASK_CLEAR_PD_DOO_SLEEP_BLOCK_IRQ                                                                  (Bit5)
#define GLOBAL_REG_INTR_MASK_CLEAR_OSC_EN                                                                                  (Bit6)


#define GLOBAL_REG_INTR_RESET                                                                                              (GLOBAL_REG_BASE + 0x18)
#define GLOBAL_REG_INTR_RESET_DEFAULT                                                                                      0x0
#define GLOBAL_REG_INTR_RESET_INTR_RESET                                                                                   (Bit0)


#define GLOBAL_REG_CHIP_ID                                                                                                 (GLOBAL_REG_BASE + 0x1c)
#define GLOBAL_REG_CHIP_ID_DEFAULT                                                                                         0x188602A0
#define GLOBAL_REG_CHIP_ID_SUBVERSION                                                                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define GLOBAL_REG_CHIP_ID_SUBVERSION_MASK                                                                                 (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_CHIP_ID_SUBVERSION_SHIFT                                                                                (0)
#define GLOBAL_REG_CHIP_ID_VERSION                                                                                         (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define GLOBAL_REG_CHIP_ID_VERSION_MASK                                                                                    (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_CHIP_ID_VERSION_SHIFT                                                                                   (8)
#define GLOBAL_REG_CHIP_ID_MONTH                                                                                           (Bit20+Bit21+Bit22+Bit23)
#define GLOBAL_REG_CHIP_ID_MONTH_MASK                                                                                      (Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_CHIP_ID_MONTH_SHIFT                                                                                     (20)
#define GLOBAL_REG_CHIP_ID_YEAR                                                                                            (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define GLOBAL_REG_CHIP_ID_YEAR_MASK                                                                                       (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_CHIP_ID_YEAR_SHIFT                                                                                      (24)


#define GLOBAL_REG_PLLTRIG_MEM_EMA_CONTROL                                                                                 (GLOBAL_REG_BASE + 0x20)
#define GLOBAL_REG_PLLTRIG_MEM_EMA_CONTROL_DEFAULT                                                                         0x13
#define GLOBAL_REG_PLLTRIG_MEM_EMA_CONTROL_CTL_PLLTRIG_RAM_EMA                                                             (Bit0+Bit1+Bit2)
#define GLOBAL_REG_PLLTRIG_MEM_EMA_CONTROL_CTL_PLLTRIG_RAM_EMA_MASK                                                        (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PLLTRIG_MEM_EMA_CONTROL_CTL_PLLTRIG_RAM_EMA_SHIFT                                                       (0)
#define GLOBAL_REG_PLLTRIG_MEM_EMA_CONTROL_CTL_PLLTRIG_RAM_EMAW                                                            (Bit4+Bit5)
#define GLOBAL_REG_PLLTRIG_MEM_EMA_CONTROL_CTL_PLLTRIG_RAM_EMAW_MASK                                                       (Bit1+Bit0)
#define GLOBAL_REG_PLLTRIG_MEM_EMA_CONTROL_CTL_PLLTRIG_RAM_EMAW_SHIFT                                                      (4)


#define GLOBAL_REG_ASYNC_RST_SET                                                                                           (GLOBAL_REG_BASE + 0x40)
#define GLOBAL_REG_ASYNC_RST_SET_DEFAULT                                                                                   0x1
#define GLOBAL_REG_ASYNC_RST_SET_CTL_ASYNC_RST_GLOBAL_SET                                                                  (Bit0)


#define GLOBAL_REG_DATA_CODE_MEM_SWITCH                                                                                    (GLOBAL_REG_BASE + 0x68)
#define GLOBAL_REG_DATA_CODE_MEM_SWITCH_DEFAULT                                                                            0x0
#define GLOBAL_REG_DATA_CODE_MEM_SWITCH_CTL_DATA_CODE_MEM_SWITCH0_4K                                                       (Bit0)
#define GLOBAL_REG_DATA_CODE_MEM_SWITCH_CTL_DATA_CODE_MEM_SWITCH4_8K                                                       (Bit1)
#define GLOBAL_REG_DATA_CODE_MEM_SWITCH_CTL_DATA_CODE_MEM_SWITCH8_16K                                                      (Bit2)
#define GLOBAL_REG_DATA_CODE_MEM_SWITCH_CTL_DATA_CODE_MEM_SWITCH16_32K                                                     (Bit3)
#define GLOBAL_REG_DATA_CODE_MEM_SWITCH_CTL_DATA_CODE_MEM_SWITCH32_64K                                                     (Bit4)
#define GLOBAL_REG_DATA_CODE_MEM_SWITCH_CTL_DATA_CODE_MEM_SWITCH64_96K                                                     (Bit5)
#define GLOBAL_REG_DATA_CODE_MEM_SWITCH_CTL_DATA_CODE_MEM_SWITCH96_128K                                                    (Bit6)
#define GLOBAL_REG_DATA_CODE_MEM_SWITCH_CTL_DPU_MEM_EN                                                                     (Bit8)


#define GLOBAL_REG_AES_ECC_MEM_SEL                                                                                         (GLOBAL_REG_BASE + 0x70)
#define GLOBAL_REG_AES_ECC_MEM_SEL_DEFAULT                                                                                 0x0
#define GLOBAL_REG_AES_ECC_MEM_SEL_CTL_AES_ECC_MEM_SEL                                                                     (Bit0)


#define GLOBAL_REG_NMI_CTRL                                                                                                (GLOBAL_REG_BASE + 0xc0)
#define GLOBAL_REG_NMI_CTRL_DEFAULT                                                                                        0x1
#define GLOBAL_REG_NMI_CTRL_CTL_WDT_INTR_NMI                                                                               (Bit0)


#define GLOBAL_REG_PIN_MUX_GPIO_0                                                                                          (GLOBAL_REG_BASE + 0x100)
#define GLOBAL_REG_PIN_MUX_GPIO_0_DEFAULT                                                                                  0x0
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_0_SEL                                                                 (Bit0+Bit1+Bit2)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_0_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_0_SEL_SHIFT                                                           (0)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_0_INV                                                                 (Bit3)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_1_SEL                                                                 (Bit4+Bit5+Bit6)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_1_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_1_SEL_SHIFT                                                           (4)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_1_INV                                                                 (Bit7)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_2_SEL                                                                 (Bit8+Bit9+Bit10)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_2_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_2_SEL_SHIFT                                                           (8)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_2_INV                                                                 (Bit11)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_3_SEL                                                                 (Bit12+Bit13+Bit14)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_3_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_3_SEL_SHIFT                                                           (12)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_3_INV                                                                 (Bit15)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_4_SEL                                                                 (Bit16+Bit17+Bit18)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_4_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_4_SEL_SHIFT                                                           (16)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_4_INV                                                                 (Bit19)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_5_SEL                                                                 (Bit20+Bit21+Bit22)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_5_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_5_SEL_SHIFT                                                           (20)
#define GLOBAL_REG_PIN_MUX_GPIO_0_CTL_PIN_MUX_GPIO_0_5_INV                                                                 (Bit23)


#define GLOBAL_REG_PIN_MUX_GPIO_1                                                                                          (GLOBAL_REG_BASE + 0x104)
#define GLOBAL_REG_PIN_MUX_GPIO_1_DEFAULT                                                                                  0x11110
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_0_SEL                                                                 (Bit0+Bit1+Bit2)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_0_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_0_SEL_SHIFT                                                           (0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_0_INV                                                                 (Bit3)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_1_SEL                                                                 (Bit4+Bit5+Bit6)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_1_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_1_SEL_SHIFT                                                           (4)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_1_INV                                                                 (Bit7)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_2_SEL                                                                 (Bit8+Bit9+Bit10)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_2_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_2_SEL_SHIFT                                                           (8)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_2_INV                                                                 (Bit11)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_3_SEL                                                                 (Bit12+Bit13+Bit14)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_3_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_3_SEL_SHIFT                                                           (12)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_3_INV                                                                 (Bit15)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_4_SEL                                                                 (Bit16+Bit17+Bit18)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_4_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_4_SEL_SHIFT                                                           (16)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_4_INV                                                                 (Bit19)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_5_SEL                                                                 (Bit20+Bit21+Bit22)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_5_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_5_SEL_SHIFT                                                           (20)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_5_INV                                                                 (Bit23)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_6_SEL                                                                 (Bit24+Bit25+Bit26)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_6_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_6_SEL_SHIFT                                                           (24)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_6_INV                                                                 (Bit27)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_7_SEL                                                                 (Bit28+Bit29+Bit30)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_7_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_7_SEL_SHIFT                                                           (28)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CTL_PIN_MUX_GPIO_1_7_INV                                                                 (Bit31)


#define GLOBAL_REG_PIN_MUX_GPIO_1_CONT                                                                                     (GLOBAL_REG_BASE + 0x108)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CONT_DEFAULT                                                                             0x0
#define GLOBAL_REG_PIN_MUX_GPIO_1_CONT_CTL_PIN_MUX_GPIO_1_8_SEL                                                            (Bit0+Bit1+Bit2)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CONT_CTL_PIN_MUX_GPIO_1_8_SEL_MASK                                                       (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CONT_CTL_PIN_MUX_GPIO_1_8_SEL_SHIFT                                                      (0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_CONT_CTL_PIN_MUX_GPIO_1_8_INV                                                            (Bit3)


#define GLOBAL_REG_PIN_MUX_GPIO_2                                                                                          (GLOBAL_REG_BASE + 0x110)
#define GLOBAL_REG_PIN_MUX_GPIO_2_DEFAULT                                                                                  0x0
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_0_SEL                                                                 (Bit0+Bit1+Bit2)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_0_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_0_SEL_SHIFT                                                           (0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_0_INV                                                                 (Bit3)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_1_SEL                                                                 (Bit4+Bit5+Bit6)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_1_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_1_SEL_SHIFT                                                           (4)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_1_INV                                                                 (Bit7)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_2_SEL                                                                 (Bit8+Bit9+Bit10)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_2_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_2_SEL_SHIFT                                                           (8)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_2_INV                                                                 (Bit11)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_3_SEL                                                                 (Bit12+Bit13+Bit14)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_3_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_3_SEL_SHIFT                                                           (12)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_3_INV                                                                 (Bit15)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_4_SEL                                                                 (Bit16+Bit17+Bit18)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_4_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_4_SEL_SHIFT                                                           (16)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_4_INV                                                                 (Bit19)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_5_SEL                                                                 (Bit20+Bit21+Bit22)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_5_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_5_SEL_SHIFT                                                           (20)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_5_INV                                                                 (Bit23)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_6_SEL                                                                 (Bit24+Bit25+Bit26)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_6_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_6_SEL_SHIFT                                                           (24)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_6_INV                                                                 (Bit27)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_7_SEL                                                                 (Bit28+Bit29+Bit30)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_7_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_7_SEL_SHIFT                                                           (28)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CTL_PIN_MUX_GPIO_2_7_INV                                                                 (Bit31)


#define GLOBAL_REG_PIN_MUX_GPIO_2_CONT                                                                                     (GLOBAL_REG_BASE + 0x114)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CONT_DEFAULT                                                                             0x0
#define GLOBAL_REG_PIN_MUX_GPIO_2_CONT_CTL_PIN_MUX_GPIO_2_8_SEL                                                            (Bit0+Bit1+Bit2)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CONT_CTL_PIN_MUX_GPIO_2_8_SEL_MASK                                                       (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CONT_CTL_PIN_MUX_GPIO_2_8_SEL_SHIFT                                                      (0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_CONT_CTL_PIN_MUX_GPIO_2_8_INV                                                            (Bit3)


#define GLOBAL_REG_PIN_MUX_GPIO_3                                                                                          (GLOBAL_REG_BASE + 0x118)
#define GLOBAL_REG_PIN_MUX_GPIO_3_DEFAULT                                                                                  0x0
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_0_SEL                                                                 (Bit0+Bit1+Bit2)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_0_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_0_SEL_SHIFT                                                           (0)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_0_INV                                                                 (Bit3)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_1_SEL                                                                 (Bit4+Bit5+Bit6)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_1_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_1_SEL_SHIFT                                                           (4)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_1_INV                                                                 (Bit7)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_2_SEL                                                                 (Bit8+Bit9+Bit10)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_2_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_2_SEL_SHIFT                                                           (8)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_2_INV                                                                 (Bit11)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_3_SEL                                                                 (Bit12+Bit13+Bit14)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_3_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_3_SEL_SHIFT                                                           (12)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_3_INV                                                                 (Bit15)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_4_SEL                                                                 (Bit16+Bit17+Bit18)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_4_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_4_SEL_SHIFT                                                           (16)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_4_INV                                                                 (Bit19)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_5_SEL                                                                 (Bit20+Bit21+Bit22)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_5_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_5_SEL_SHIFT                                                           (20)
#define GLOBAL_REG_PIN_MUX_GPIO_3_CTL_PIN_MUX_GPIO_3_5_INV                                                                 (Bit23)


#define GLOBAL_REG_PIN_MUX_GPIO_4                                                                                          (GLOBAL_REG_BASE + 0x120)
#define GLOBAL_REG_PIN_MUX_GPIO_4_DEFAULT                                                                                  0x0
#define GLOBAL_REG_PIN_MUX_GPIO_4_CTL_PIN_MUX_GPIO_4_0_SEL                                                                 (Bit0+Bit1+Bit2)
#define GLOBAL_REG_PIN_MUX_GPIO_4_CTL_PIN_MUX_GPIO_4_0_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_4_CTL_PIN_MUX_GPIO_4_0_SEL_SHIFT                                                           (0)
#define GLOBAL_REG_PIN_MUX_GPIO_4_CTL_PIN_MUX_GPIO_4_0_INV                                                                 (Bit3)
#define GLOBAL_REG_PIN_MUX_GPIO_4_CTL_PIN_MUX_GPIO_4_1_SEL                                                                 (Bit4+Bit5+Bit6)
#define GLOBAL_REG_PIN_MUX_GPIO_4_CTL_PIN_MUX_GPIO_4_1_SEL_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_4_CTL_PIN_MUX_GPIO_4_1_SEL_SHIFT                                                           (4)
#define GLOBAL_REG_PIN_MUX_GPIO_4_CTL_PIN_MUX_GPIO_4_1_INV                                                                 (Bit7)


#define GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT                                                                                   (GLOBAL_REG_BASE + 0x124)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT_DEFAULT                                                                           0xAAA
#define GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT_CTL_PIN_MUX_GPIO_0_0_OUTPUT                                                       (Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT_CTL_PIN_MUX_GPIO_0_0_OEN                                                          (Bit1)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT_CTL_PIN_MUX_GPIO_0_1_OUTPUT                                                       (Bit2)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT_CTL_PIN_MUX_GPIO_0_1_OEN                                                          (Bit3)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT_CTL_PIN_MUX_GPIO_0_2_OUTPUT                                                       (Bit4)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT_CTL_PIN_MUX_GPIO_0_2_OEN                                                          (Bit5)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT_CTL_PIN_MUX_GPIO_0_3_OUTPUT                                                       (Bit6)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT_CTL_PIN_MUX_GPIO_0_3_OEN                                                          (Bit7)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT_CTL_PIN_MUX_GPIO_0_4_OUTPUT                                                       (Bit8)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT_CTL_PIN_MUX_GPIO_0_4_OEN                                                          (Bit9)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT_CTL_PIN_MUX_GPIO_0_5_OUTPUT                                                       (Bit10)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT_CTL_PIN_MUX_GPIO_0_5_OEN                                                          (Bit11)


#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT                                                                                   (GLOBAL_REG_BASE + 0x128)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_DEFAULT                                                                           0x2AAAA
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_0_OUTPUT                                                       (Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_0_OEN                                                          (Bit1)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_1_OUTPUT                                                       (Bit2)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_1_OEN                                                          (Bit3)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_2_OUTPUT                                                       (Bit4)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_2_OEN                                                          (Bit5)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_3_OUTPUT                                                       (Bit6)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_3_OEN                                                          (Bit7)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_4_OUTPUT                                                       (Bit8)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_4_OEN                                                          (Bit9)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_5_OUTPUT                                                       (Bit10)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_5_OEN                                                          (Bit11)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_6_OUTPUT                                                       (Bit12)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_6_OEN                                                          (Bit13)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_7_OUTPUT                                                       (Bit14)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_7_OEN                                                          (Bit15)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_8_OUTPUT                                                       (Bit16)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT_CTL_PIN_MUX_GPIO_1_8_OEN                                                          (Bit17)


#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT                                                                                   (GLOBAL_REG_BASE + 0x12c)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_DEFAULT                                                                           0x2AAAA
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_0_OUTPUT                                                       (Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_0_OEN                                                          (Bit1)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_1_OUTPUT                                                       (Bit2)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_1_OEN                                                          (Bit3)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_2_OUTPUT                                                       (Bit4)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_2_OEN                                                          (Bit5)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_3_OUTPUT                                                       (Bit6)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_3_OEN                                                          (Bit7)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_4_OUTPUT                                                       (Bit8)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_4_OEN                                                          (Bit9)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_5_OUTPUT                                                       (Bit10)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_5_OEN                                                          (Bit11)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_6_OUTPUT                                                       (Bit12)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_6_OEN                                                          (Bit13)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_7_OUTPUT                                                       (Bit14)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_7_OEN                                                          (Bit15)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_8_OUTPUT                                                       (Bit16)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT_CTL_PIN_MUX_GPIO_2_8_OEN                                                          (Bit17)


#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT                                                                                  (GLOBAL_REG_BASE + 0x130)
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_DEFAULT                                                                          0x280AAA
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_CTL_PIN_MUX_GPIO_3_0_OUTPUT                                                      (Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_CTL_PIN_MUX_GPIO_3_0_OEN                                                         (Bit1)
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_CTL_PIN_MUX_GPIO_3_1_OUTPUT                                                      (Bit2)
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_CTL_PIN_MUX_GPIO_3_1_OEN                                                         (Bit3)
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_CTL_PIN_MUX_GPIO_3_2_OUTPUT                                                      (Bit4)
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_CTL_PIN_MUX_GPIO_3_2_OEN                                                         (Bit5)
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_CTL_PIN_MUX_GPIO_3_3_OUTPUT                                                      (Bit6)
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_CTL_PIN_MUX_GPIO_3_3_OEN                                                         (Bit7)
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_CTL_PIN_MUX_GPIO_3_4_OUTPUT                                                      (Bit8)
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_CTL_PIN_MUX_GPIO_3_4_OEN                                                         (Bit9)
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_CTL_PIN_MUX_GPIO_3_5_OUTPUT                                                      (Bit10)
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_CTL_PIN_MUX_GPIO_3_5_OEN                                                         (Bit11)
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_CTL_PIN_MUX_GPIO_4_0_OUTPUT                                                      (Bit18)
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_CTL_PIN_MUX_GPIO_4_0_OEN                                                         (Bit19)
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_CTL_PIN_MUX_GPIO_4_1_OUTPUT                                                      (Bit20)
#define GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT_CTL_PIN_MUX_GPIO_4_1_OEN                                                         (Bit21)


#define GLOBAL_REG_PIN_MUX_GPIO_01_INPUT_STATUS                                                                            (GLOBAL_REG_BASE + 0x134)
#define GLOBAL_REG_PIN_MUX_GPIO_01_INPUT_STATUS_DEFAULT                                                                    0x0
#define GLOBAL_REG_PIN_MUX_GPIO_01_INPUT_STATUS_STS_PIN_MUX_GPIO_0_INPUT                                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define GLOBAL_REG_PIN_MUX_GPIO_01_INPUT_STATUS_STS_PIN_MUX_GPIO_0_INPUT_MASK                                              (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_01_INPUT_STATUS_STS_PIN_MUX_GPIO_0_INPUT_SHIFT                                             (0)
#define GLOBAL_REG_PIN_MUX_GPIO_01_INPUT_STATUS_STS_PIN_MUX_GPIO_1_INPUT                                                   (Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28)
#define GLOBAL_REG_PIN_MUX_GPIO_01_INPUT_STATUS_STS_PIN_MUX_GPIO_1_INPUT_MASK                                              (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_01_INPUT_STATUS_STS_PIN_MUX_GPIO_1_INPUT_SHIFT                                             (20)


#define GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS                                                                           (GLOBAL_REG_BASE + 0x138)
#define GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_DEFAULT                                                                   0x0
#define GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_2_INPUT                                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10)
#define GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_2_INPUT_MASK                                             (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_2_INPUT_SHIFT                                            (0)
#define GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_3_INPUT                                                  (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_3_INPUT_MASK                                             (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_3_INPUT_SHIFT                                            (12)
#define GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_4_INPUT                                                  (Bit24+Bit25)
#define GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_4_INPUT_MASK                                             (Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_4_INPUT_SHIFT                                            (24)


#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL                                                                                (GLOBAL_REG_BASE + 0x13c)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_DEFAULT                                                                        0x84001F
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_I_KEYBOARD_DEFAULT                                                         (Bit0)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_UART_0_CTS_DEFAULT                                                         (Bit1)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_UART_0_RX_DEFAULT                                                          (Bit2)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_UART_1_CTS_DEFAULT                                                         (Bit3)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_UART_1_RX_DEFAULT                                                          (Bit4)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_QD_CHA_X_DEFAULT                                                           (Bit5)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_QD_CHB_X_DEFAULT                                                           (Bit6)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_QD_IDX_X_DEFAULT                                                           (Bit7)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_QD_CHA_Y_DEFAULT                                                           (Bit8)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_QD_CHB_Y_DEFAULT                                                           (Bit9)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_QD_IDX_Y_DEFAULT                                                           (Bit10)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_QD_CHA_Z_DEFAULT                                                           (Bit11)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_QD_CHB_Z_DEFAULT                                                           (Bit12)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_QD_IDX_Z_DEFAULT                                                           (Bit13)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_PDM_0_DEFAULT                                                              (Bit14)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_PDM_1_DEFAULT                                                              (Bit15)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_ISO7816_CLK_DEFAULT                                                        (Bit16)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_ISO7816_RST_DEFAULT                                                        (Bit17)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_JTAG_SWD_CLK_DEFAULT                                                       (Bit18)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_JTAG_TDI_DEFAULT                                                           (Bit19)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_SWD_TRACE_CLK_DEFAULT                                                      (Bit20)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_JTAG_RESET_DEFAULT                                                         (Bit21)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_SPI_0_CLK_DEFAULT                                                          (Bit22)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_SPI_0_SS_DEFAULT                                                           (Bit23)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_SPI_0_MOSI_DEFAULT                                                         (Bit24)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_PIN_MUX_RX_TX_EN_SEL                                                       (Bit25+Bit26+Bit27)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_PIN_MUX_RX_TX_EN_SEL_MASK                                                  (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_PIN_MUX_RX_TX_EN_SEL_SHIFT                                                 (25)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_PIN_MUX_TEST_SEL                                                           (Bit28+Bit29+Bit30+Bit31)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_PIN_MUX_TEST_SEL_MASK                                                      (Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_CTL_PIN_MUX_TEST_SEL_SHIFT                                                     (28)


#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_2                                                                              (GLOBAL_REG_BASE + 0x140)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_2_DEFAULT                                                                      0xD
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_2_CTL_I_SPI_MSTR_MISO_DEFAULT                                                  (Bit0)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_2_CTL_I_SPI_SLV_CLK_DEFAULT                                                    (Bit1)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_2_CTL_I_SPI_SLV_SSN_DEFAULT                                                    (Bit2)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_2_CTL_I_SPI_SLV_MOSI_DEFAULT                                                   (Bit3)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_2_CTL_I_WLAN_TX_DEFAULT                                                        (Bit4)
#define GLOBAL_REG_PIN_MUX_DEFAULT_TEST_SEL_2_CTL_I_WLAN_RX_DEFAULT                                                        (Bit5)


#define GLOBAL_REG_I2S_OEN_CTRL                                                                                            (GLOBAL_REG_BASE + 0x144)
#define GLOBAL_REG_I2S_OEN_CTRL_DEFAULT                                                                                    0x7
#define GLOBAL_REG_I2S_OEN_CTRL_CTL_I2S_MASTER_SD0_OEN                                                                     (Bit0)
#define GLOBAL_REG_I2S_OEN_CTRL_CTL_I2S_MASTER_SD1_OEN                                                                     (Bit1)
#define GLOBAL_REG_I2S_OEN_CTRL_CTL_I2S_SLAVE_SD_OEN                                                                       (Bit2)


#define GLOBAL_REG_PIN_MUX_GPIO_0_OE_IE                                                                                    (GLOBAL_REG_BASE + 0x148)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OE_IE_DEFAULT                                                                            0x3F0000
#define GLOBAL_REG_PIN_MUX_GPIO_0_OE_IE_CTL_GPIO_TO_PAD_OE_0                                                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OE_IE_CTL_GPIO_TO_PAD_OE_0_MASK                                                          (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OE_IE_CTL_GPIO_TO_PAD_OE_0_SHIFT                                                         (0)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OE_IE_CTL_GPIO_TO_PAD_IE_0                                                               (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OE_IE_CTL_GPIO_TO_PAD_IE_0_MASK                                                          (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_0_OE_IE_CTL_GPIO_TO_PAD_IE_0_SHIFT                                                         (16)


#define GLOBAL_REG_PIN_MUX_GPIO_1_OE_IE                                                                                    (GLOBAL_REG_BASE + 0x14c)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OE_IE_DEFAULT                                                                            0x1FF000A
#define GLOBAL_REG_PIN_MUX_GPIO_1_OE_IE_CTL_GPIO_TO_PAD_OE_1                                                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OE_IE_CTL_GPIO_TO_PAD_OE_1_MASK                                                          (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OE_IE_CTL_GPIO_TO_PAD_OE_1_SHIFT                                                         (0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OE_IE_CTL_GPIO_TO_PAD_IE_1                                                               (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OE_IE_CTL_GPIO_TO_PAD_IE_1_MASK                                                          (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_OE_IE_CTL_GPIO_TO_PAD_IE_1_SHIFT                                                         (16)


#define GLOBAL_REG_PIN_MUX_GPIO_2_OE_IE                                                                                    (GLOBAL_REG_BASE + 0x150)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OE_IE_DEFAULT                                                                            0x3FF0000
#define GLOBAL_REG_PIN_MUX_GPIO_2_OE_IE_CTL_GPIO_TO_PAD_OE_2                                                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OE_IE_CTL_GPIO_TO_PAD_OE_2_MASK                                                          (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OE_IE_CTL_GPIO_TO_PAD_OE_2_SHIFT                                                         (0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OE_IE_CTL_GPIO_TO_PAD_IE_2                                                               (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OE_IE_CTL_GPIO_TO_PAD_IE_2_MASK                                                          (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_OE_IE_CTL_GPIO_TO_PAD_IE_2_SHIFT                                                         (16)


#define GLOBAL_REG_PIN_MUX_GPIO_3_OE_IE                                                                                    (GLOBAL_REG_BASE + 0x154)
#define GLOBAL_REG_PIN_MUX_GPIO_3_OE_IE_DEFAULT                                                                            0x3F0000
#define GLOBAL_REG_PIN_MUX_GPIO_3_OE_IE_CTL_GPIO_TO_PAD_OE_3                                                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define GLOBAL_REG_PIN_MUX_GPIO_3_OE_IE_CTL_GPIO_TO_PAD_OE_3_MASK                                                          (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_3_OE_IE_CTL_GPIO_TO_PAD_OE_3_SHIFT                                                         (0)
#define GLOBAL_REG_PIN_MUX_GPIO_3_OE_IE_CTL_GPIO_TO_PAD_IE_3                                                               (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define GLOBAL_REG_PIN_MUX_GPIO_3_OE_IE_CTL_GPIO_TO_PAD_IE_3_MASK                                                          (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_3_OE_IE_CTL_GPIO_TO_PAD_IE_3_SHIFT                                                         (16)


#define GLOBAL_REG_PIN_MUX_GPIO_4_OE_IE                                                                                    (GLOBAL_REG_BASE + 0x158)
#define GLOBAL_REG_PIN_MUX_GPIO_4_OE_IE_DEFAULT                                                                            0x30000
#define GLOBAL_REG_PIN_MUX_GPIO_4_OE_IE_CTL_GPIO_TO_PAD_OE_4                                                               (Bit0+Bit1)
#define GLOBAL_REG_PIN_MUX_GPIO_4_OE_IE_CTL_GPIO_TO_PAD_OE_4_MASK                                                          (Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_4_OE_IE_CTL_GPIO_TO_PAD_OE_4_SHIFT                                                         (0)
#define GLOBAL_REG_PIN_MUX_GPIO_4_OE_IE_CTL_GPIO_TO_PAD_IE_4                                                               (Bit16+Bit17)
#define GLOBAL_REG_PIN_MUX_GPIO_4_OE_IE_CTL_GPIO_TO_PAD_IE_4_MASK                                                          (Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_4_OE_IE_CTL_GPIO_TO_PAD_IE_4_SHIFT                                                         (16)


#define GLOBAL_REG_PIN_MUX_GPIO_0_PD_PU                                                                                    (GLOBAL_REG_BASE + 0x160)
#define GLOBAL_REG_PIN_MUX_GPIO_0_PD_PU_DEFAULT                                                                            0x3F0000
#define GLOBAL_REG_PIN_MUX_GPIO_0_PD_PU_CTL_GPIO_TO_PAD_PD_0                                                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define GLOBAL_REG_PIN_MUX_GPIO_0_PD_PU_CTL_GPIO_TO_PAD_PD_0_MASK                                                          (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_0_PD_PU_CTL_GPIO_TO_PAD_PD_0_SHIFT                                                         (0)
#define GLOBAL_REG_PIN_MUX_GPIO_0_PD_PU_CTL_GPIO_TO_PAD_PU_0                                                               (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define GLOBAL_REG_PIN_MUX_GPIO_0_PD_PU_CTL_GPIO_TO_PAD_PU_0_MASK                                                          (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_0_PD_PU_CTL_GPIO_TO_PAD_PU_0_SHIFT                                                         (16)


#define GLOBAL_REG_PIN_MUX_GPIO_1_PD_PU                                                                                    (GLOBAL_REG_BASE + 0x164)
#define GLOBAL_REG_PIN_MUX_GPIO_1_PD_PU_DEFAULT                                                                            0x1FF0000
#define GLOBAL_REG_PIN_MUX_GPIO_1_PD_PU_CTL_GPIO_TO_PAD_PD_1                                                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8)
#define GLOBAL_REG_PIN_MUX_GPIO_1_PD_PU_CTL_GPIO_TO_PAD_PD_1_MASK                                                          (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_PD_PU_CTL_GPIO_TO_PAD_PD_1_SHIFT                                                         (0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_PD_PU_CTL_GPIO_TO_PAD_PU_1                                                               (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24)
#define GLOBAL_REG_PIN_MUX_GPIO_1_PD_PU_CTL_GPIO_TO_PAD_PU_1_MASK                                                          (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_1_PD_PU_CTL_GPIO_TO_PAD_PU_1_SHIFT                                                         (16)


#define GLOBAL_REG_PIN_MUX_GPIO_2_PD_PU                                                                                    (GLOBAL_REG_BASE + 0x168)
#define GLOBAL_REG_PIN_MUX_GPIO_2_PD_PU_DEFAULT                                                                            0x7FF0000
#define GLOBAL_REG_PIN_MUX_GPIO_2_PD_PU_CTL_GPIO_TO_PAD_PD_2                                                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10)
#define GLOBAL_REG_PIN_MUX_GPIO_2_PD_PU_CTL_GPIO_TO_PAD_PD_2_MASK                                                          (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_PD_PU_CTL_GPIO_TO_PAD_PD_2_SHIFT                                                         (0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_PD_PU_CTL_GPIO_TO_PAD_PU_2                                                               (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26)
#define GLOBAL_REG_PIN_MUX_GPIO_2_PD_PU_CTL_GPIO_TO_PAD_PU_2_MASK                                                          (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_2_PD_PU_CTL_GPIO_TO_PAD_PU_2_SHIFT                                                         (16)


#define GLOBAL_REG_PIN_MUX_GPIO_3_PD_PU                                                                                    (GLOBAL_REG_BASE + 0x16c)
#define GLOBAL_REG_PIN_MUX_GPIO_3_PD_PU_DEFAULT                                                                            0x3F0000
#define GLOBAL_REG_PIN_MUX_GPIO_3_PD_PU_CTL_GPIO_TO_PAD_PD_3                                                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define GLOBAL_REG_PIN_MUX_GPIO_3_PD_PU_CTL_GPIO_TO_PAD_PD_3_MASK                                                          (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_3_PD_PU_CTL_GPIO_TO_PAD_PD_3_SHIFT                                                         (0)
#define GLOBAL_REG_PIN_MUX_GPIO_3_PD_PU_CTL_GPIO_TO_PAD_PU_3                                                               (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define GLOBAL_REG_PIN_MUX_GPIO_3_PD_PU_CTL_GPIO_TO_PAD_PU_3_MASK                                                          (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_3_PD_PU_CTL_GPIO_TO_PAD_PU_3_SHIFT                                                         (16)


#define GLOBAL_REG_PIN_MUX_GPIO_4_PD_PU                                                                                    (GLOBAL_REG_BASE + 0x170)
#define GLOBAL_REG_PIN_MUX_GPIO_4_PD_PU_DEFAULT                                                                            0x30000
#define GLOBAL_REG_PIN_MUX_GPIO_4_PD_PU_CTL_GPIO_TO_PAD_PD_4                                                               (Bit0+Bit1)
#define GLOBAL_REG_PIN_MUX_GPIO_4_PD_PU_CTL_GPIO_TO_PAD_PD_4_MASK                                                          (Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_4_PD_PU_CTL_GPIO_TO_PAD_PD_4_SHIFT                                                         (0)
#define GLOBAL_REG_PIN_MUX_GPIO_4_PD_PU_CTL_GPIO_TO_PAD_PU_4                                                               (Bit16+Bit17)
#define GLOBAL_REG_PIN_MUX_GPIO_4_PD_PU_CTL_GPIO_TO_PAD_PU_4_MASK                                                          (Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_4_PD_PU_CTL_GPIO_TO_PAD_PU_4_SHIFT                                                         (16)


#define GLOBAL_REG_PIN_MUX_GPIO_PC_01                                                                                      (GLOBAL_REG_BASE + 0x178)
#define GLOBAL_REG_PIN_MUX_GPIO_PC_01_DEFAULT                                                                              0x0
#define GLOBAL_REG_PIN_MUX_GPIO_PC_01_CTL_GPIO_TO_PAD_PC_0                                                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define GLOBAL_REG_PIN_MUX_GPIO_PC_01_CTL_GPIO_TO_PAD_PC_0_MASK                                                            (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_PC_01_CTL_GPIO_TO_PAD_PC_0_SHIFT                                                           (0)
#define GLOBAL_REG_PIN_MUX_GPIO_PC_01_CTL_GPIO_TO_PAD_PC_1                                                                 (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24)
#define GLOBAL_REG_PIN_MUX_GPIO_PC_01_CTL_GPIO_TO_PAD_PC_1_MASK                                                            (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_PC_01_CTL_GPIO_TO_PAD_PC_1_SHIFT                                                           (16)


#define GLOBAL_REG_PIN_MUX_GPIO_PC_234                                                                                     (GLOBAL_REG_BASE + 0x17c)
#define GLOBAL_REG_PIN_MUX_GPIO_PC_234_DEFAULT                                                                             0x0
#define GLOBAL_REG_PIN_MUX_GPIO_PC_234_CTL_GPIO_TO_PAD_PC_2                                                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10)
#define GLOBAL_REG_PIN_MUX_GPIO_PC_234_CTL_GPIO_TO_PAD_PC_2_MASK                                                           (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_PC_234_CTL_GPIO_TO_PAD_PC_2_SHIFT                                                          (0)
#define GLOBAL_REG_PIN_MUX_GPIO_PC_234_CTL_GPIO_TO_PAD_PC_3                                                                (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_PIN_MUX_GPIO_PC_234_CTL_GPIO_TO_PAD_PC_3_MASK                                                           (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_PC_234_CTL_GPIO_TO_PAD_PC_3_SHIFT                                                          (12)
#define GLOBAL_REG_PIN_MUX_GPIO_PC_234_CTL_GPIO_TO_PAD_PC_4                                                                (Bit24+Bit25)
#define GLOBAL_REG_PIN_MUX_GPIO_PC_234_CTL_GPIO_TO_PAD_PC_4_MASK                                                           (Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_GPIO_PC_234_CTL_GPIO_TO_PAD_PC_4_SHIFT                                                          (24)


#define GLOBAL_REG_PIN_MUX_QSPI                                                                                            (GLOBAL_REG_BASE + 0x184)
#define GLOBAL_REG_PIN_MUX_QSPI_DEFAULT                                                                                    0x0
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_0_SEL                                                                     (Bit0+Bit1+Bit2)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_0_SEL_MASK                                                                (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_0_SEL_SHIFT                                                               (0)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_0_INV                                                                     (Bit3)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_1_SEL                                                                     (Bit4+Bit5+Bit6)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_1_SEL_MASK                                                                (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_1_SEL_SHIFT                                                               (4)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_1_INV                                                                     (Bit7)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_2_SEL                                                                     (Bit8+Bit9+Bit10)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_2_SEL_MASK                                                                (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_2_SEL_SHIFT                                                               (8)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_2_INV                                                                     (Bit11)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_3A_SEL                                                                    (Bit12+Bit13+Bit14)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_3A_SEL_MASK                                                               (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_3A_SEL_SHIFT                                                              (12)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_3A_INV                                                                    (Bit15)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_4_SEL                                                                     (Bit16+Bit17+Bit18)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_4_SEL_MASK                                                                (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_4_SEL_SHIFT                                                               (16)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_4_INV                                                                     (Bit19)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_5_SEL                                                                     (Bit20+Bit21+Bit22)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_5_SEL_MASK                                                                (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_5_SEL_SHIFT                                                               (20)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_5_INV                                                                     (Bit23)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_3B_SEL                                                                    (Bit24+Bit25+Bit26)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_3B_SEL_MASK                                                               (Bit2+Bit1+Bit0)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_3B_SEL_SHIFT                                                              (24)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_PIN_MUX_QSPI_3B_INV                                                                    (Bit27)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_QSPI_3A_3B_SEL                                                                         (Bit29)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_QSPI_3A_3B_SEL_EFUSE0REG1                                                              (Bit30)
#define GLOBAL_REG_PIN_MUX_QSPI_CTL_QSPI_EFUSE0REG1                                                                        (Bit31)


#define GLOBAL_REG_PIN_MUX_QSPI_OUTPUT                                                                                     (GLOBAL_REG_BASE + 0x188)
#define GLOBAL_REG_PIN_MUX_QSPI_OUTPUT_DEFAULT                                                                             0x2AAA
#define GLOBAL_REG_PIN_MUX_QSPI_OUTPUT_CTL_PIN_MUX_QSPI_0_OUTPUT                                                           (Bit0)
#define GLOBAL_REG_PIN_MUX_QSPI_OUTPUT_CTL_PIN_MUX_QSPI_0_OEN                                                              (Bit1)
#define GLOBAL_REG_PIN_MUX_QSPI_OUTPUT_CTL_PIN_MUX_QSPI_1_OUTPUT                                                           (Bit2)
#define GLOBAL_REG_PIN_MUX_QSPI_OUTPUT_CTL_PIN_MUX_QSPI_1_OEN                                                              (Bit3)
#define GLOBAL_REG_PIN_MUX_QSPI_OUTPUT_CTL_PIN_MUX_QSPI_2_OUTPUT                                                           (Bit4)
#define GLOBAL_REG_PIN_MUX_QSPI_OUTPUT_CTL_PIN_MUX_QSPI_2_OEN                                                              (Bit5)
#define GLOBAL_REG_PIN_MUX_QSPI_OUTPUT_CTL_PIN_MUX_QSPI_3A_OUTPUT                                                          (Bit6)
#define GLOBAL_REG_PIN_MUX_QSPI_OUTPUT_CTL_PIN_MUX_QSPI_3A_OEN                                                             (Bit7)
#define GLOBAL_REG_PIN_MUX_QSPI_OUTPUT_CTL_PIN_MUX_QSPI_4_OUTPUT                                                           (Bit8)
#define GLOBAL_REG_PIN_MUX_QSPI_OUTPUT_CTL_PIN_MUX_QSPI_4_OEN                                                              (Bit9)
#define GLOBAL_REG_PIN_MUX_QSPI_OUTPUT_CTL_PIN_MUX_QSPI_5_OUTPUT                                                           (Bit10)
#define GLOBAL_REG_PIN_MUX_QSPI_OUTPUT_CTL_PIN_MUX_QSPI_5_OEN                                                              (Bit11)
#define GLOBAL_REG_PIN_MUX_QSPI_OUTPUT_CTL_PIN_MUX_QSPI_3B_OUTPUT                                                          (Bit12)
#define GLOBAL_REG_PIN_MUX_QSPI_OUTPUT_CTL_PIN_MUX_QSPI_3B_OEN                                                             (Bit13)


#define GLOBAL_REG_QSPI_PC                                                                                                 (GLOBAL_REG_BASE + 0x18c)
#define GLOBAL_REG_QSPI_PC_DEFAULT                                                                                         0x0
#define GLOBAL_REG_QSPI_PC_CTL_QSPI_PC                                                                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6)
#define GLOBAL_REG_QSPI_PC_CTL_QSPI_PC_MASK                                                                                (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_QSPI_PC_CTL_QSPI_PC_SHIFT                                                                               (0)


#define GLOBAL_REG_QSPI_OE_IE_PU_PD                                                                                        (GLOBAL_REG_BASE + 0x190)
#define GLOBAL_REG_QSPI_OE_IE_PU_PD_DEFAULT                                                                                0x3F353F
#define GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_OE                                                                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6)
#define GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_OE_MASK                                                                       (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_OE_SHIFT                                                                      (0)
#define GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_IE                                                                            (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_IE_MASK                                                                       (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_IE_SHIFT                                                                      (8)
#define GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_PU                                                                            (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22)
#define GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_PU_MASK                                                                       (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_PU_SHIFT                                                                      (16)
#define GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_PD                                                                            (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30)
#define GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_PD_MASK                                                                       (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_PD_SHIFT                                                                      (24)


#define GLOBAL_REG_CLKD0_ENABLE_1                                                                                          (GLOBAL_REG_BASE + 0x1c0)
#define GLOBAL_REG_CLKD0_ENABLE_1_DEFAULT                                                                                  0x1C3FFEBF
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_EFUSE_CLK                                                             (Bit0)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_RXTX_SEQ_REGS_CLK                                                     (Bit1)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_SPIFLASH_CTRL_PCLK                                                    (Bit2)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_CPU_I_KEYBOARD_CLK_FREE                                               (Bit3)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_CPU_I_KEYBOARD_CLK_GATED                                              (Bit4)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_SECURITY_CORE_PCLK                                                    (Bit5)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_SSI_MAS0_CLK                                                          (Bit7)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_CPU_I_SSI_MASTER1_SSI_CLK                                             (Bit8)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_INTRCTRL_CLK                                                          (Bit9)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_CPU_I_SSI_SLAVE0_SSI_CLK                                              (Bit10)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_CPU_I_WDT_TCLK                                                        (Bit11)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_CPU_I_I2C_0_IC_CLK                                                    (Bit12)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_CPU_I_I2C_1_IC_CLK                                                    (Bit13)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_CPU_I_TIMERS_0_TIMER_1_CLK                                            (Bit14)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_CPU_I_TIMERS_0_TIMER_2_CLK                                            (Bit15)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_PWM0_PCLK                                                             (Bit16)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_PWM1_PCLK                                                             (Bit17)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_PWM2_PCLK                                                             (Bit18)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_PWM3_PCLK                                                             (Bit19)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_PWM4_PCLK                                                             (Bit20)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_COUNTER_TOP_PCLK                                                      (Bit21)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_AUDIO_AURX_CLK                                                        (Bit23)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_AUDIO_AUTX_CLK                                                        (Bit24)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_AUDIO_64M_CLK                                                         (Bit25)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_SADC_CLK                                                              (Bit26)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_CPU_I_I2S_MASTER_SCLK                                                 (Bit27)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_CPU_I_I2S_SLAVE_SCLK                                                  (Bit28)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_AUDIO_SPK_CLK                                                         (Bit29)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_AUDIO_SD_CLK                                                          (Bit30)
#define GLOBAL_REG_CLKD0_ENABLE_1_CTL_CLKD0_ENABLE_1_32M_TTM                                                               (Bit31)


#define GLOBAL_REG_CLKD0_ENABLE_2                                                                                          (GLOBAL_REG_BASE + 0x1c4)
#define GLOBAL_REG_CLKD0_ENABLE_2_DEFAULT                                                                                  0xFFEFFFFE
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_CLK_QUADDEC                                                           (Bit0)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_QUADDEC_TOP_PCLK                                                      (Bit1)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_CLK_EM                                                                (Bit2)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_SADCCTRL_TOP_PCLK                                                     (Bit3)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_AUDIO_TOP_PCLK                                                        (Bit4)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_DMAC_REQ_MUX_PCLK                                                     (Bit5)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_EFUSECTRL_TOP_PCLK                                                    (Bit6)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_KEYBOARD_TOP_PCLK                                                     (Bit7)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_GPIO_PCLK                                                             (Bit8)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_I2C_0_PCLK                                                            (Bit9)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_I2C_1_PCLK                                                            (Bit10)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_I2S_MASTER_PCLK                                                       (Bit11)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_I2S_SLAVE_PCLK                                                        (Bit12)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_SSI_MASTER0_PCLK                                                      (Bit13)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_SSI_MASTER1_PCLK                                                      (Bit14)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_SSI_SLAVE0_PCLK                                                       (Bit15)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_TIMERS_0_PCLK                                                         (Bit16)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_UART_0_PCLK                                                           (Bit17)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_UART_1_PCLK                                                           (Bit18)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_WDT_PCLK                                                              (Bit19)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_APB_AON_BRIDGE_PCLK                                                   (Bit21)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_ECC_FW_RAM_CLK                                                        (Bit22)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_ECC_MEM_A_CLK                                                         (Bit23)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_ECC_MEM_B_CLK                                                         (Bit24)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_ECC_MEM_C_CLK                                                         (Bit25)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_ECC_MEM_D_CLK                                                         (Bit26)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_SHM_MEM_0_CLK                                                         (Bit27)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_SHM_MEM_1_CLK                                                         (Bit28)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_SHM_MEM_2_CLK                                                         (Bit29)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_SHM_MEM_3_CLK                                                         (Bit30)
#define GLOBAL_REG_CLKD0_ENABLE_2_CTL_CLKD0_ENABLE_2_SHM_MEM_4_CLK                                                         (Bit31)


#define GLOBAL_REG_CLKD1_ENABLE_1                                                                                          (GLOBAL_REG_BASE + 0x1c8)
#define GLOBAL_REG_CLKD1_ENABLE_1_DEFAULT                                                                                  0xFF9300B
#define GLOBAL_REG_CLKD1_ENABLE_1_CTL_CLKD1_ENABLE_1_COUNTER_HCLK                                                          (Bit0)
#define GLOBAL_REG_CLKD1_ENABLE_1_CTL_CLKD1_ENABLE_1_AHBTRG_TOP_PCLK                                                       (Bit1)
#define GLOBAL_REG_CLKD1_ENABLE_1_CTL_CLKD1_ENABLE_1_BLE_I_MDM_CORE_CLK                                                    (Bit3)
#define GLOBAL_REG_CLKD1_ENABLE_1_CTL_CLKD1_ENABLE_1_BLE_I_MDM_PCLK                                                        (Bit12)
#define GLOBAL_REG_CLKD1_ENABLE_1_CTL_CLKD1_ENABLE_1_BLE_I_CLK_ANT                                                         (Bit13)
#define GLOBAL_REG_CLKD1_ENABLE_1_CTL_CLKD1_ENABLE_1_BLE_I_BB_MASTER1_GCLK                                                 (Bit16)
#define GLOBAL_REG_CLKD1_ENABLE_1_CTL_CLKD1_ENABLE_1_BLE_I_BB_MASTER_CLK                                                   (Bit18)
#define GLOBAL_REG_CLKD1_ENABLE_1_CTL_CLKD1_ENABLE_CLK_PLLTRIG_MEM                                                         (Bit19)
#define GLOBAL_REG_CLKD1_ENABLE_1_CTL_CLKD1_ENABLE_PCLK_PLLTRIG                                                            (Bit20)
#define GLOBAL_REG_CLKD1_ENABLE_1_CTL_CLKD1_ENABLE_PLLTRIG                                                                 (Bit21)
#define GLOBAL_REG_CLKD1_ENABLE_1_CTL_CLKD1_ENABLE_CPU_I_CLK_AHBTRG                                                        (Bit22)
#define GLOBAL_REG_CLKD1_ENABLE_1_CTL_CLKD1_ENABLE_TRXSEQ_I_REGS_CLK                                                       (Bit23)
#define GLOBAL_REG_CLKD1_ENABLE_1_CTL_CLKD1_ENABLE_TRXSEQ_I_MAIN_CLK                                                       (Bit24)
#define GLOBAL_REG_CLKD1_ENABLE_1_CTL_CLKD1_ENABLE_TRXSEQ_I_MAIN_CLK_FREE                                                  (Bit25)
#define GLOBAL_REG_CLKD1_ENABLE_1_CTL_CLKD1_ENABLE_TRXSEQ_I_CNTR_CLK                                                       (Bit26)
#define GLOBAL_REG_CLKD1_ENABLE_1_CTL_CLKD1_ENABLE_BLE_FE_PCLK                                                             (Bit27)


#define GLOBAL_REG_CLKD2_ENABLE_1                                                                                          (GLOBAL_REG_BASE + 0x1d0)
#define GLOBAL_REG_CLKD2_ENABLE_1_DEFAULT                                                                                  0x1D
#define GLOBAL_REG_CLKD2_ENABLE_1_CTL_CLKD2_ENABLE_1_ROMCRC_CLK                                                            (Bit0)
#define GLOBAL_REG_CLKD2_ENABLE_1_CTL_CLKD2_ENABLE_1_CPU_I_CM4_HCLK                                                        (Bit2)
#define GLOBAL_REG_CLKD2_ENABLE_1_CTL_CLKD2_ENABLE_1_CPU_I_CM4_FCLK                                                        (Bit3)
#define GLOBAL_REG_CLKD2_ENABLE_1_CTL_CLKD2_ENABLE_1_CPU_I_CM4_STCLK                                                       (Bit4)


#define GLOBAL_REG_CLK_ENABLE_1                                                                                            (GLOBAL_REG_BASE + 0x1d4)
#define GLOBAL_REG_CLK_ENABLE_1_DEFAULT                                                                                    0x4080240
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_AON_PERIPH_REG_CLK                                                        (Bit6)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_CALIB_REG_CLK                                                             (Bit7)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_CALIB_REF_CLK                                                             (Bit8)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_SHAREDMEM_TOP_CLK                                                         (Bit9)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_HWACC_MEM                                                                 (Bit10)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_HWACC_HCLK                                                                (Bit11)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_MBIST_CTRL_1                                                              (Bit12)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_MBIST_CTRL_2                                                              (Bit13)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_MBIST_CTRL_3                                                              (Bit14)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_MBIST_CTRL_4                                                              (Bit15)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_MBIST_CTRL_5                                                              (Bit16)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_MBIST_CTRL_6                                                              (Bit17)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_MBIST_CTRL_7                                                              (Bit18)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_CLK_EM2SHM                                                                (Bit19)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_IPM_FREE                                                                  (Bit20)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_GPIO_0_INTR_CLK                                                           (Bit21)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_GPIO_1_INTR_CLK                                                           (Bit22)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_GPIO_2_INTR_CLK                                                           (Bit23)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_GPIO_3_INTR_CLK                                                           (Bit24)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_GPIO_4_INTR_CLK                                                           (Bit25)
#define GLOBAL_REG_CLK_ENABLE_1_CTL_CLK_ENABLE_1_EFUSE_1_CLK                                                               (Bit26)


#define GLOBAL_REG_CLK_FORCE_ON_1                                                                                          (GLOBAL_REG_BASE + 0x1e0)
#define GLOBAL_REG_CLK_FORCE_ON_1_DEFAULT                                                                                  0x0
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_GCLK_SADC                                                             (Bit0)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_APB_AON_BRIDGE_CLK                                                    (Bit1)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_EH2H_CM4_TO_D0_HCLK                                                   (Bit2)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_AHB_D0_HCLK                                                           (Bit3)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_EH2H_D0_TO_D1_HCLK                                                    (Bit4)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_APB_D0_1_HCLK                                                         (Bit5)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_APB_D0_2_HCLK                                                         (Bit6)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_APB_D0_3_HCLK                                                         (Bit7)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_ICM_DATA_CODE_RAM_CLK                                                 (Bit8)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_ICM_ICACHE_CLK                                                        (Bit9)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_ICM_BOOT_ROM_CLK                                                      (Bit10)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_AHB_SLV_MUX_CLK                                                       (Bit11)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_AHB_DEFSLV_CLK                                                        (Bit12)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_EH2H_CM4_TO_D0_CLK                                                    (Bit13)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_EH2H_D0_TO_D1_CLK                                                     (Bit14)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_AHB_D1_CLK                                                            (Bit15)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_APB_D1_CLK                                                            (Bit16)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_BOOTROM_CLK                                                           (Bit18)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_ICACHE_TOP_CLK                                                        (Bit19)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_SPIFLASH_CTRL_CLK                                                     (Bit20)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_DATA_CODE_SRAM_A_CLK                                                  (Bit21)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_DATA_CODE_SRAM_B_CLK                                                  (Bit22)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_FLASH_DMA_CLK                                                         (Bit23)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_SECURITY_CORE_CLK                                                     (Bit24)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_DMAC_REQ_MUX_CLK                                                      (Bit25)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_RAM_CACHE_TAG_CLK                                                     (Bit26)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_RAM_CACHE_DATA_CLK                                                    (Bit27)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_FRONTEND_WRAP_CLK                                                     (Bit28)
#define GLOBAL_REG_CLK_FORCE_ON_1_CTL_CLK_FORCE_ON_1_D0_ICACHE_TOP_CLK                                                     (Bit29)


#define GLOBAL_REG_CLK_FORCE_ON_2                                                                                          (GLOBAL_REG_BASE + 0x1e4)
#define GLOBAL_REG_CLK_FORCE_ON_2_DEFAULT                                                                                  0x400000
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DC_RAM_0_CLK                                                          (Bit0)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DC_RAM_1_CLK                                                          (Bit1)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DC_RAM_2_CLK                                                          (Bit2)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DC_RAM_3_CLK                                                          (Bit3)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DC_RAM_4_CLK                                                          (Bit4)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DMAC_0_CLK                                                            (Bit5)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DMAC_1_CLK                                                            (Bit6)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_AHBTRG_HCLK                                                           (Bit7)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_RFTRX_REG_TOP_PCLK                                                    (Bit8)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_IPM_MSTR_CLK                                                          (Bit9)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_IPM_SLV_CLK                                                           (Bit10)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_IPM_COMMON_CLK                                                        (Bit11)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DBGCAP_CLK                                                            (Bit12)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DBGCAP_0_CLK                                                          (Bit13)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DBGCAP_1_CLK                                                          (Bit14)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DBGCAP_2_CLK                                                          (Bit15)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DBGCAP_3_CLK                                                          (Bit16)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DBGCAP_4_CLK                                                          (Bit17)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DBGCAP_PCLK                                                           (Bit18)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_D2_COUNTER_HCLK                                                       (Bit19)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_PLLTRIG_GATED_FORCE_ON                                                           (Bit20)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CPU_I_CLK_GATED_AHBTRG_FORCE_ON                                                      (Bit21)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_D1_BLE_I_BB_HCLK                                                      (Bit22)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_RXADC_CLK                                                             (Bit23)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DIV2_RXADC_CLK                                                        (Bit24)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DIV4_RXADC_CLK                                                        (Bit25)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_TXDAC_CLK                                                             (Bit26)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_DIV4_TXDAC_CLK                                                        (Bit27)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_FRONTEND_RXAGC_CLK                                                    (Bit28)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_D2_M2_AHB_HCLK                                                        (Bit29)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_D2_M1_AHB_CM4I_HCLK                                                   (Bit30)
#define GLOBAL_REG_CLK_FORCE_ON_2_CTL_CLK_FORCE_ON_2_D2_M1_AHB_CM4D_HCLK                                                   (Bit31)


#define GLOBAL_REG_CLK_FORCE_ON_3                                                                                          (GLOBAL_REG_BASE + 0x1e8)
#define GLOBAL_REG_CLK_FORCE_ON_3_DEFAULT                                                                                  0x400
#define GLOBAL_REG_CLK_FORCE_ON_3_CTL_CLK_FORCE_ON_3_MDM_RX_GCLK                                                           (Bit0)
#define GLOBAL_REG_CLK_FORCE_ON_3_CTL_CLK_FORCE_ON_3_MDM_RXDL_GCLK                                                         (Bit1)
#define GLOBAL_REG_CLK_FORCE_ON_3_CTL_CLK_FORCE_ON_3_MDM_RXCOR_GCLK                                                        (Bit2)
#define GLOBAL_REG_CLK_FORCE_ON_3_CTL_CLK_FORCE_ON_3_MDM_RXCOR_LR_GCLK                                                     (Bit3)
#define GLOBAL_REG_CLK_FORCE_ON_3_CTL_CLK_FORCE_ON_3_MDM_RXGFSK_GCLK                                                       (Bit4)
#define GLOBAL_REG_CLK_FORCE_ON_3_CTL_CLK_FORCE_ON_3_MDM_RXGFSK_LR_GCLK                                                    (Bit5)
#define GLOBAL_REG_CLK_FORCE_ON_3_CTL_CLK_FORCE_ON_3_MDM_TX_GCLK                                                           (Bit6)
#define GLOBAL_REG_CLK_FORCE_ON_3_CTL_CLK_FORCE_ON_3_MDM_TXGFSK_GCLK                                                       (Bit7)
#define GLOBAL_REG_CLK_FORCE_ON_3_CTL_CLK_FORCE_ON_3_BLE_I_BB_MASTER2_GCLK                                                 (Bit8)
#define GLOBAL_REG_CLK_FORCE_ON_3_CTL_CLK_FORCE_ON_3_BLE_I_BB_CRYPT_GCLK                                                   (Bit9)
#define GLOBAL_REG_CLK_FORCE_ON_3_CTL_CLK_FORCE_ON_3_BLE_I_BB_HGCLK                                                        (Bit10)


#define GLOBAL_REG_CLK_FORCE_OFF_1                                                                                         (GLOBAL_REG_BASE + 0x1f0)
#define GLOBAL_REG_CLK_FORCE_OFF_1_DEFAULT                                                                                 0x0
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_GCLK_SADC                                                           (Bit0)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_APB_AON_BRIDGE_CLK                                                  (Bit1)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_EH2H_CM4_TO_D0_HCLK                                                 (Bit2)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_AHB_D0_HCLK                                                         (Bit3)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_EH2H_D0_TO_D1_HCLK                                                  (Bit4)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_APB_D0_1_HCLK                                                       (Bit5)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_APB_D0_2_HCLK                                                       (Bit6)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_APB_D0_3_HCLK                                                       (Bit7)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_ICM_DATA_CODE_RAM_CLK                                               (Bit8)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_ICM_ICACHE_CLK                                                      (Bit9)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_ICM_BOOT_ROM_CLK                                                    (Bit10)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_AHB_SLV_MUX_CLK                                                     (Bit11)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_AHB_DEFSLV_CLK                                                      (Bit12)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_EH2H_CM4_TO_D0_CLK                                                  (Bit13)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_EH2H_D0_TO_D1_CLK                                                   (Bit14)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_AHB_D1_CLK                                                          (Bit15)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_APB_D1_CLK                                                          (Bit16)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_BOOTROM_CLK                                                         (Bit18)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_ICACHE_TOP_CLK                                                      (Bit19)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_SPIFLASH_CTRL_CLK                                                   (Bit20)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_DATA_CODE_SRAM_A_CLK                                                (Bit21)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_DATA_CODE_SRAM_B_CLK                                                (Bit22)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_FLASH_DMA_CLK                                                       (Bit23)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_SECURITY_CORE_CLK                                                   (Bit24)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_DMAC_REQ_MUX_CLK                                                    (Bit25)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_RAM_CACHE_TAG_CLK                                                   (Bit26)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_RAM_CACHE_DATA_CLK                                                  (Bit27)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_FRONTEND_WRAP_CLK                                                   (Bit28)
#define GLOBAL_REG_CLK_FORCE_OFF_1_CTL_CLK_FORCE_OFF_1_D0_ICACHE_TOP_CLK                                                   (Bit29)


#define GLOBAL_REG_CLK_FORCE_OFF_2                                                                                         (GLOBAL_REG_BASE + 0x1f4)
#define GLOBAL_REG_CLK_FORCE_OFF_2_DEFAULT                                                                                 0x0
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DC_RAM_0_CLK                                                        (Bit0)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DC_RAM_1_CLK                                                        (Bit1)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DC_RAM_2_CLK                                                        (Bit2)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DC_RAM_3_CLK                                                        (Bit3)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DC_RAM_4_CLK                                                        (Bit4)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DMAC_0_CLK                                                          (Bit5)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DMAC_1_CLK                                                          (Bit6)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_AHBTRG_HCLK                                                         (Bit7)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_RFTRX_REG_TOP_PCLK                                                  (Bit8)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_IPM_MSTR_CLK                                                        (Bit9)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_IPM_SLV_CLK                                                         (Bit10)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_IPM_COMMON_CLK                                                      (Bit11)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DBGCAP_CLK                                                          (Bit12)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DBGCAP_0_CLK                                                        (Bit13)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DBGCAP_1_CLK                                                        (Bit14)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DBGCAP_2_CLK                                                        (Bit15)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DBGCAP_3_CLK                                                        (Bit16)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DBGCAP_4_CLK                                                        (Bit17)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DBGCAP_PCLK                                                         (Bit18)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_D2_COUNTER_HCLK                                                     (Bit19)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_PLLTRIG_GATED_FORCE_OFF                                                         (Bit20)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CPU_I_CLK_GATED_AHBTRG_FORCE_OFF                                                    (Bit21)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_D1_BLE_I_BB_HCLK                                                    (Bit22)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_RXADC_CLK                                                           (Bit23)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DIV2_RXADC_CLK                                                      (Bit24)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DIV4_RXADC_CLK                                                      (Bit25)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_TXDAC_CLK                                                           (Bit26)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_DIV4_TXDAC_CLK                                                      (Bit27)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_FRONTEND_RXAGC_CLK                                                  (Bit28)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_D2_M2_AHB_HCLK                                                      (Bit29)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_D2_M1_AHB_CM4I_HCLK                                                 (Bit30)
#define GLOBAL_REG_CLK_FORCE_OFF_2_CTL_CLK_FORCE_OFF_2_D2_M1_AHB_CM4D_HCLK                                                 (Bit31)


#define GLOBAL_REG_CLK_FORCE_OFF_3                                                                                         (GLOBAL_REG_BASE + 0x1f8)
#define GLOBAL_REG_CLK_FORCE_OFF_3_DEFAULT                                                                                 0x0
#define GLOBAL_REG_CLK_FORCE_OFF_3_CTL_CLK_FORCE_OFF_3_MDM_RX_GCLK                                                         (Bit0)
#define GLOBAL_REG_CLK_FORCE_OFF_3_CTL_CLK_FORCE_OFF_3_MDM_RXDL_GCLK                                                       (Bit1)
#define GLOBAL_REG_CLK_FORCE_OFF_3_CTL_CLK_FORCE_OFF_3_MDM_RXCOR_GCLK                                                      (Bit2)
#define GLOBAL_REG_CLK_FORCE_OFF_3_CTL_CLK_FORCE_OFF_3_MDM_RXCOR_LR_GCLK                                                   (Bit3)
#define GLOBAL_REG_CLK_FORCE_OFF_3_CTL_CLK_FORCE_OFF_3_MDM_RXGFSK_GCLK                                                     (Bit4)
#define GLOBAL_REG_CLK_FORCE_OFF_3_CTL_CLK_FORCE_OFF_3_MDM_RXGFSK_LR_GCLK                                                  (Bit5)
#define GLOBAL_REG_CLK_FORCE_OFF_3_CTL_CLK_FORCE_OFF_3_MDM_TX_GCLK                                                         (Bit6)
#define GLOBAL_REG_CLK_FORCE_OFF_3_CTL_CLK_FORCE_OFF_3_MDM_TXGFSK_GCLK                                                     (Bit7)
#define GLOBAL_REG_CLK_FORCE_OFF_3_CTL_CLK_FORCE_OFF_3_BLE_I_BB_MASTER2_GCLK                                               (Bit8)
#define GLOBAL_REG_CLK_FORCE_OFF_3_CTL_CLK_FORCE_OFF_3_BLE_I_BB_CRYPT_GCLK                                                 (Bit9)
#define GLOBAL_REG_CLK_FORCE_OFF_3_CTL_CLK_FORCE_OFF_3_BLE_I_BB_HGCLK                                                      (Bit10)


#define GLOBAL_REG_CLK_CTRL_1                                                                                              (GLOBAL_REG_BASE + 0x200)
#define GLOBAL_REG_CLK_CTRL_1_DEFAULT                                                                                      0x6000880
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_D0_CLK                                                                    (Bit0+Bit1)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_D0_CLK_MASK                                                               (Bit1+Bit0)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_D0_CLK_SHIFT                                                              (0)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_D0_SEL_TMR0_CLK                                                               (Bit2+Bit3)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_D0_SEL_TMR0_CLK_MASK                                                          (Bit1+Bit0)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_D0_SEL_TMR0_CLK_SHIFT                                                         (2)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_D0_SEL_32KRC_RTC_CLK                                                          (Bit4)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_BLE_CLK_FORCE                                                             (Bit5)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_BLE_CLK_FORCE_VAL                                                         (Bit6)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_HWACC_CLK                                                                 (Bit7+Bit8+Bit9)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_HWACC_CLK_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_HWACC_CLK_SHIFT                                                           (7)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_64MXO_OR_32MRC                                                            (Bit10)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_D2_CLK                                                                    (Bit11+Bit12+Bit13)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_D2_CLK_MASK                                                               (Bit2+Bit1+Bit0)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_D2_CLK_SHIFT                                                              (11)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_D1_DIV2_4_8_CLKS                                                          (Bit15+Bit16)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_D1_DIV2_4_8_CLKS_MASK                                                     (Bit1+Bit0)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_D1_DIV2_4_8_CLKS_SHIFT                                                    (15)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_D0_SADC_CLK                                                               (Bit18+Bit19+Bit20+Bit21)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_D0_SADC_CLK_MASK                                                          (Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_D0_SADC_CLK_SHIFT                                                         (18)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_D0_I2S_SLAVE_SCLK_FROM_PAD                                                (Bit22)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_D0_AUDIO_SPK_SD_CLK                                                       (Bit23+Bit24)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_D0_AUDIO_SPK_SD_CLK_MASK                                                  (Bit1+Bit0)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_D0_AUDIO_SPK_SD_CLK_SHIFT                                                 (23)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_EFUSE_CLK                                                                 (Bit25)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_SHM_CLK                                                                   (Bit26+Bit27+Bit28)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_SHM_CLK_MASK                                                              (Bit2+Bit1+Bit0)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_SHM_CLK_SHIFT                                                             (26)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_RXAGC_CLK                                                                 (Bit29)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_TXDAC_DIV_CLK_FORCE                                                       (Bit30)
#define GLOBAL_REG_CLK_CTRL_1_CTL_CLK_CTRL_1_SEL_TXDAC_DIV_CLK_FORCE_VAL                                                   (Bit31)


#define GLOBAL_REG_CLK_CTRL_2                                                                                              (GLOBAL_REG_BASE + 0x204)
#define GLOBAL_REG_CLK_CTRL_2_DEFAULT                                                                                      0x1100014
#define GLOBAL_REG_CLK_CTRL_2_CTL_CLK_CTRL_2_INT_DIV_VALUE                                                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_CLK_CTRL_2_CTL_CLK_CTRL_2_INT_DIV_VALUE_MASK                                                            (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_CLK_CTRL_2_CTL_CLK_CTRL_2_INT_DIV_VALUE_SHIFT                                                           (0)
#define GLOBAL_REG_CLK_CTRL_2_CTL_CLK_CTRL_2_ALLOW_CM4_TO_GATE_HCLK                                                        (Bit12)
#define GLOBAL_REG_CLK_CTRL_2_CTL_CLK_CTRL_2_ALLOW_CM4_DEEPSLEEP_TO_USE_32K_FOR_FCLK                                       (Bit13)
#define GLOBAL_REG_CLK_CTRL_2_CTL_CLK_CTRL_2_SEL_FAST_OR_32K_FOR_CM4_FCLK                                                  (Bit14)
#define GLOBAL_REG_CLK_CTRL_2_CTL_CLK_CTRL_2_ALLOW_CM4_SLEEPDEEP_TO_GATE_FCLK                                              (Bit15)
#define GLOBAL_REG_CLK_CTRL_2_CTL_CLK_CTRL_2_ALLOW_CM4_LOCKUP_TO_RESET_CM4                                                 (Bit17)
#define GLOBAL_REG_CLK_CTRL_2_CTL_CLK_CTRL_2_SEL_CALIB_REF_CLK                                                             (Bit18)
#define GLOBAL_REG_CLK_CTRL_2_CTL_CLK_CTRL_2_SEL_SSIMAS0_CLK                                                               (Bit20+Bit21+Bit22)
#define GLOBAL_REG_CLK_CTRL_2_CTL_CLK_CTRL_2_SEL_SSIMAS0_CLK_MASK                                                          (Bit2+Bit1+Bit0)
#define GLOBAL_REG_CLK_CTRL_2_CTL_CLK_CTRL_2_SEL_SSIMAS0_CLK_SHIFT                                                         (20)
#define GLOBAL_REG_CLK_CTRL_2_CTL_CLK_CTRL_2_SEL_TTM_CLK                                                                   (Bit24+Bit25+Bit26)
#define GLOBAL_REG_CLK_CTRL_2_CTL_CLK_CTRL_2_SEL_TTM_CLK_MASK                                                              (Bit2+Bit1+Bit0)
#define GLOBAL_REG_CLK_CTRL_2_CTL_CLK_CTRL_2_SEL_TTM_CLK_SHIFT                                                             (24)


#define GLOBAL_REG_RESET_CTRL_1                                                                                            (GLOBAL_REG_BASE + 0x280)
#define GLOBAL_REG_RESET_CTRL_1_DEFAULT                                                                                    0xFFBDFFF
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_MEM_RSTN_SHM_REG                                                            (Bit0)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_KEYBOARD_RSTN_REG                                                       (Bit1)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_GPIO_DBCLK_RSTN_REG                                                     (Bit2)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_TIMERS_0_TIMER_1_RSTN_REG                                               (Bit3)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_TIMERS_0_TIMER_2_RSTN_REG                                               (Bit4)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_TIMERS_0_TIMER_3_RSTN_REG                                               (Bit5)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_TIMERS_0_TIMER_4_RSTN_REG                                               (Bit6)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_TIMERS_0_TIMER_5_RSTN_REG                                               (Bit7)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_TIMERS_0_TIMER_6_RSTN_REG                                               (Bit8)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_TIMERS_0_TIMER_7_RSTN_REG                                               (Bit9)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_TIMERS_0_TIMER_8_RSTN_REG                                               (Bit10)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_SSI_MASTER0_SSI_RSTN_REG                                                (Bit11)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_SSI_MASTER1_SSI_RSTN_REG                                                (Bit12)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_SSI_SLAVE0_SSI_RSTN_REG                                                 (Bit14)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_WDT_RSTN_REG                                                            (Bit15)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_I2C_0_IC_RSTN_REG                                                       (Bit16)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_I2C_1_IC_RSTN_REG                                                       (Bit17)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_I2S_MASTER_SRESETN_REG                                                      (Bit19)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_I2S_SLAVE_SRESETN_REG                                                       (Bit20)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_HWACC_RSTN_REG                                                              (Bit21)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_AUDIO_AURX_RSTN_REG                                                         (Bit22)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_AUDIO_AUTX_RSTN_REG                                                         (Bit23)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_AUDIO_SPK_RSTN_REG                                                          (Bit24)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_AUDIO_64M_RSTN_REG                                                          (Bit25)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_SADC_RSTN_REG                                                               (Bit26)
#define GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_AHB_RSTN_REG                                                                (Bit27)


#define GLOBAL_REG_RESET_CTRL_2                                                                                            (GLOBAL_REG_BASE + 0x284)
#define GLOBAL_REG_RESET_CTRL_2_DEFAULT                                                                                    0x7FFFF
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_1_D1_BLE_MDM_RSTN_REG                                                            (Bit0)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_1_D1_BLE_MDM_PRESETN_REG                                                         (Bit1)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_1_D1_BLE_HRESETN_REG                                                             (Bit2)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_1_D1_BLE_CRYPT_RSTN_REG                                                          (Bit3)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_1_D1_BLE_MASTER_RSTN_REG                                                         (Bit4)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_2_D1_SHM_RSTN_REG                                                                (Bit5)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_2_D1_PRST_N_PLLTRIG_RSTN_REG                                                     (Bit6)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_2_D1_RST_N_PLLTRIG_RSTN_REG                                                      (Bit7)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_2_D1_RST_N_PLLTRIG_MEM_RSTN_REG                                                  (Bit8)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_2_D1_TRXSEQ_MAIN_RSTN_REG                                                        (Bit9)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_2_D1_TRXSEQ_REGS_RSTN_REG                                                        (Bit10)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_2_D1_TRXSEQ_CNTR_RSTN_REG                                                        (Bit11)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_2_D1_AHBTRG_RSTN_REG                                                             (Bit12)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_2_D1_BLE_FE_PRST_RSTN_REG                                                        (Bit13)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_2_D1_BLE_I_RST_N_ANT_REG                                                         (Bit14)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_2_D1_BLE_IPM_REG                                                                 (Bit15)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_2_D1_AHB_RSTN_REG                                                                (Bit16)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_2_D1_BLE_IPMAC_REG                                                               (Bit17)
#define GLOBAL_REG_RESET_CTRL_2_CTL_RESET_2_D1_BLE_RFTRX_REG                                                               (Bit18)


#define GLOBAL_REG_RESET_CTRL_3                                                                                            (GLOBAL_REG_BASE + 0x288)
#define GLOBAL_REG_RESET_CTRL_3_DEFAULT                                                                                    0x7FF
#define GLOBAL_REG_RESET_CTRL_3_CTL_RESET_1_D2_CPU_CM4_PORESETN_RSTN_REG                                                   (Bit0)
#define GLOBAL_REG_RESET_CTRL_3_CTL_RESET_1_D2_CPU_FCTRL_RSTN_REG                                                          (Bit1)
#define GLOBAL_REG_RESET_CTRL_3_CTL_RESET_1_D2_CPU_EFUSE_RSTN_REG                                                          (Bit2)
#define GLOBAL_REG_RESET_CTRL_3_CTL_RESET_1_D2_CPU_EFUSE_1_RSTN_REG                                                        (Bit3)
#define GLOBAL_REG_RESET_CTRL_3_CTL_RESET_1_D2_MEM_DC_RAM_RSTN_REG                                                         (Bit4)
#define GLOBAL_REG_RESET_CTRL_3_CTL_RESET_1_RXADC_RSTN_REG                                                                 (Bit5)
#define GLOBAL_REG_RESET_CTRL_3_CTL_RESET_1_RXAGC_RSTN_REG                                                                 (Bit6)
#define GLOBAL_REG_RESET_CTRL_3_CTL_RESET_1_TXDAC_RSTN_REG                                                                 (Bit7)
#define GLOBAL_REG_RESET_CTRL_3_CTL_RESET_1_AON_PERIPH_RSTN_REG                                                            (Bit8)
#define GLOBAL_REG_RESET_CTRL_3_CTL_RESET_3_ROMCRC_RSTN_REG                                                                (Bit9)
#define GLOBAL_REG_RESET_CTRL_3_CTL_RESET_3_D2_AHB_RSTN_REG                                                                (Bit10)


#define GLOBAL_REG_RESET_CTRL_4                                                                                            (GLOBAL_REG_BASE + 0x28c)
#define GLOBAL_REG_RESET_CTRL_4_DEFAULT                                                                                    0x1FFFF
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_4_D0_QUADDEC_RSTN_REG                                                            (Bit0)
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_4_D0_EM_RSTN_REG                                                                 (Bit1)
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_4_RSTN_CLK2CALIB_REG                                                             (Bit2)
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_4_RSTN_CALIB_REF_CLK_REG                                                         (Bit3)
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_COUNTER0_REG                                                                     (Bit4)
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_COUNTER1_REG                                                                     (Bit5)
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_COUNTER2_REG                                                                     (Bit6)
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_COUNTER3_REG                                                                     (Bit7)
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_4_RSTN_MBIST_CTRL_1_REG                                                          (Bit8)
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_4_RSTN_MBIST_CTRL_2_REG                                                          (Bit9)
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_4_RSTN_MBIST_CTRL_3_REG                                                          (Bit10)
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_4_RSTN_MBIST_CTRL_4_REG                                                          (Bit11)
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_4_RSTN_MBIST_CTRL_5_REG                                                          (Bit12)
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_4_RSTN_MBIST_CTRL_6_REG                                                          (Bit13)
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_4_RSTN_MBIST_CTRL_7_REG                                                          (Bit14)
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_4_RSTN_DBGCAP_PCLK_REG                                                           (Bit15)
#define GLOBAL_REG_RESET_CTRL_4_CTL_RESET_4_RSTN_DBGCAP_D2_REG                                                             (Bit16)


#define GLOBAL_REG_MISC_CTRL                                                                                               (GLOBAL_REG_BASE + 0x290)
#define GLOBAL_REG_MISC_CTRL_DEFAULT                                                                                       0x0
#define GLOBAL_REG_MISC_CTRL_MISC_CTRL_IDDQ_EN_REG                                                                         (Bit0)


#define GLOBAL_REG_SPIFLASH_SPI_M0_SINGLE_MODE_CTRL                                                                        (GLOBAL_REG_BASE + 0x294)
#define GLOBAL_REG_SPIFLASH_SPI_M0_SINGLE_MODE_CTRL_DEFAULT                                                                0x1
#define GLOBAL_REG_SPIFLASH_SPI_M0_SINGLE_MODE_CTRL_CTL_SPIFLASH_SPI_M0_SINGLE_MODE                                        (Bit0)


#define GLOBAL_REG_TEST_MUX_SEL_0                                                                                          (GLOBAL_REG_BASE + 0x2a0)
#define GLOBAL_REG_TEST_MUX_SEL_0_DEFAULT                                                                                  0x0
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_0                                                                       (Bit0+Bit1+Bit2)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_0_MASK                                                                  (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_0_SHIFT                                                                 (0)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_1                                                                       (Bit4+Bit5+Bit6)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_1_MASK                                                                  (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_1_SHIFT                                                                 (4)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_2                                                                       (Bit8+Bit9+Bit10)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_2_MASK                                                                  (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_2_SHIFT                                                                 (8)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_3                                                                       (Bit12+Bit13+Bit14)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_3_MASK                                                                  (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_3_SHIFT                                                                 (12)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_4                                                                       (Bit16+Bit17+Bit18)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_4_MASK                                                                  (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_4_SHIFT                                                                 (16)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_5                                                                       (Bit20+Bit21+Bit22)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_5_MASK                                                                  (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_5_SHIFT                                                                 (20)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_6                                                                       (Bit24+Bit25+Bit26)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_6_MASK                                                                  (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_6_SHIFT                                                                 (24)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_7                                                                       (Bit28+Bit29+Bit30)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_7_MASK                                                                  (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_0_CTL_TEST_MUX_SEL_7_SHIFT                                                                 (28)


#define GLOBAL_REG_TEST_MUX_SEL_1                                                                                          (GLOBAL_REG_BASE + 0x2a4)
#define GLOBAL_REG_TEST_MUX_SEL_1_DEFAULT                                                                                  0x0
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_8                                                                       (Bit0+Bit1+Bit2)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_8_MASK                                                                  (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_8_SHIFT                                                                 (0)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_9                                                                       (Bit4+Bit5+Bit6)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_9_MASK                                                                  (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_9_SHIFT                                                                 (4)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_10                                                                      (Bit8+Bit9+Bit10)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_10_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_10_SHIFT                                                                (8)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_11                                                                      (Bit12+Bit13+Bit14)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_11_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_11_SHIFT                                                                (12)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_12                                                                      (Bit16+Bit17+Bit18)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_12_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_12_SHIFT                                                                (16)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_13                                                                      (Bit20+Bit21+Bit22)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_13_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_13_SHIFT                                                                (20)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_14                                                                      (Bit24+Bit25+Bit26)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_14_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_14_SHIFT                                                                (24)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_15                                                                      (Bit28+Bit29+Bit30)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_15_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_1_CTL_TEST_MUX_SEL_15_SHIFT                                                                (28)


#define GLOBAL_REG_TEST_MUX_SEL_2                                                                                          (GLOBAL_REG_BASE + 0x2a8)
#define GLOBAL_REG_TEST_MUX_SEL_2_DEFAULT                                                                                  0x0
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_16                                                                      (Bit0+Bit1+Bit2)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_16_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_16_SHIFT                                                                (0)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_17                                                                      (Bit4+Bit5+Bit6)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_17_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_17_SHIFT                                                                (4)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_18                                                                      (Bit8+Bit9+Bit10)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_18_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_18_SHIFT                                                                (8)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_19                                                                      (Bit12+Bit13+Bit14)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_19_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_19_SHIFT                                                                (12)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_20                                                                      (Bit16+Bit17+Bit18)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_20_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_20_SHIFT                                                                (16)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_21                                                                      (Bit20+Bit21+Bit22)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_21_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_21_SHIFT                                                                (20)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_22                                                                      (Bit24+Bit25+Bit26)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_22_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_22_SHIFT                                                                (24)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_23                                                                      (Bit28+Bit29+Bit30)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_23_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_2_CTL_TEST_MUX_SEL_23_SHIFT                                                                (28)


#define GLOBAL_REG_TEST_MUX_SEL_3                                                                                          (GLOBAL_REG_BASE + 0x2ac)
#define GLOBAL_REG_TEST_MUX_SEL_3_DEFAULT                                                                                  0x0
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_24                                                                      (Bit0+Bit1+Bit2)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_24_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_24_SHIFT                                                                (0)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_25                                                                      (Bit4+Bit5+Bit6)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_25_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_25_SHIFT                                                                (4)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_26                                                                      (Bit8+Bit9+Bit10)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_26_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_26_SHIFT                                                                (8)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_27                                                                      (Bit12+Bit13+Bit14)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_27_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_27_SHIFT                                                                (12)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_28                                                                      (Bit16+Bit17+Bit18)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_28_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_28_SHIFT                                                                (16)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_29                                                                      (Bit20+Bit21+Bit22)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_29_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_29_SHIFT                                                                (20)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_30                                                                      (Bit24+Bit25+Bit26)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_30_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_30_SHIFT                                                                (24)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_31                                                                      (Bit28+Bit29+Bit30)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_31_MASK                                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SEL_3_CTL_TEST_MUX_SEL_31_SHIFT                                                                (28)


#define GLOBAL_REG_TEST_MUX_SHIFT                                                                                          (GLOBAL_REG_BASE + 0x2b0)
#define GLOBAL_REG_TEST_MUX_SHIFT_DEFAULT                                                                                  0x0
#define GLOBAL_REG_TEST_MUX_SHIFT_CTL_TEST_MUX_SHIFT_0                                                                     (Bit0+Bit1+Bit2+Bit3+Bit4)
#define GLOBAL_REG_TEST_MUX_SHIFT_CTL_TEST_MUX_SHIFT_0_MASK                                                                (Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SHIFT_CTL_TEST_MUX_SHIFT_0_SHIFT                                                               (0)
#define GLOBAL_REG_TEST_MUX_SHIFT_CTL_TEST_MUX_SHIFT_1                                                                     (Bit8+Bit9+Bit10+Bit11+Bit12)
#define GLOBAL_REG_TEST_MUX_SHIFT_CTL_TEST_MUX_SHIFT_1_MASK                                                                (Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SHIFT_CTL_TEST_MUX_SHIFT_1_SHIFT                                                               (8)
#define GLOBAL_REG_TEST_MUX_SHIFT_CTL_TEST_MUX_SHIFT_2                                                                     (Bit16+Bit17+Bit18+Bit19+Bit20)
#define GLOBAL_REG_TEST_MUX_SHIFT_CTL_TEST_MUX_SHIFT_2_MASK                                                                (Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SHIFT_CTL_TEST_MUX_SHIFT_2_SHIFT                                                               (16)
#define GLOBAL_REG_TEST_MUX_SHIFT_CTL_TEST_MUX_SHIFT_3                                                                     (Bit24+Bit25+Bit26+Bit27+Bit28)
#define GLOBAL_REG_TEST_MUX_SHIFT_CTL_TEST_MUX_SHIFT_3_MASK                                                                (Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SHIFT_CTL_TEST_MUX_SHIFT_3_SHIFT                                                               (24)


#define GLOBAL_REG_TEST_MUX_SHIFT_1                                                                                        (GLOBAL_REG_BASE + 0x2b4)
#define GLOBAL_REG_TEST_MUX_SHIFT_1_DEFAULT                                                                                0x0
#define GLOBAL_REG_TEST_MUX_SHIFT_1_CTL_TEST_MUX_SHIFT_4                                                                   (Bit0+Bit1+Bit2+Bit3+Bit4)
#define GLOBAL_REG_TEST_MUX_SHIFT_1_CTL_TEST_MUX_SHIFT_4_MASK                                                              (Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_TEST_MUX_SHIFT_1_CTL_TEST_MUX_SHIFT_4_SHIFT                                                             (0)


#define GLOBAL_REG_SLEEP_CTRL                                                                                              (GLOBAL_REG_BASE + 0x2c0)
#define GLOBAL_REG_SLEEP_CTRL_DEFAULT                                                                                      0x0
#define GLOBAL_REG_SLEEP_CTRL_SLEEP_REQ                                                                                    (Bit0)


#define GLOBAL_REG_CM4_HADDRI_MUX_CTL                                                                                      (GLOBAL_REG_BASE + 0x2d0)
#define GLOBAL_REG_CM4_HADDRI_MUX_CTL_DEFAULT                                                                              0x0
#define GLOBAL_REG_CM4_HADDRI_MUX_CTL_EN                                                                                   (Bit0)
#define GLOBAL_REG_CM4_HADDRI_MUX_CTL_SRC_SEL                                                                              (Bit1)
#define GLOBAL_REG_CM4_HADDRI_MUX_CTL_MUX_SEL                                                                              (Bit4+Bit5)
#define GLOBAL_REG_CM4_HADDRI_MUX_CTL_MUX_SEL_MASK                                                                         (Bit1+Bit0)
#define GLOBAL_REG_CM4_HADDRI_MUX_CTL_MUX_SEL_SHIFT                                                                        (4)


#define GLOBAL_REG_CM4_WIC_EN_REQ                                                                                          (GLOBAL_REG_BASE + 0x2d8)
#define GLOBAL_REG_CM4_WIC_EN_REQ_DEFAULT                                                                                  0x0
#define GLOBAL_REG_CM4_WIC_EN_REQ_CTL_CM4_WIC_EN_REQ                                                                       (Bit0)


#define GLOBAL_REG_CM4_WIC_EN_ACK                                                                                          (GLOBAL_REG_BASE + 0x2dc)
#define GLOBAL_REG_CM4_WIC_EN_ACK_DEFAULT                                                                                  0x0
#define GLOBAL_REG_CM4_WIC_EN_ACK_STS_CM4_WIC_EN_ACK                                                                       (Bit0)


#define GLOBAL_REG_OSC_EN_STATUS                                                                                           (GLOBAL_REG_BASE + 0x2e0)
#define GLOBAL_REG_OSC_EN_STATUS_DEFAULT                                                                                   0x0
#define GLOBAL_REG_OSC_EN_STATUS_STS_OSC_EN                                                                                (Bit0)
#define GLOBAL_REG_OSC_EN_STATUS_STS_RADIO_EN                                                                              (Bit1)


#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0                                                                             (GLOBAL_REG_BASE + 0x304)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_DEFAULT                                                                     0x13131313
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_0_4K_EMA                                                         (Bit0+Bit1+Bit2)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_0_4K_EMA_MASK                                                    (Bit2+Bit1+Bit0)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_0_4K_EMA_SHIFT                                                   (0)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_0_4K_EMAW                                                        (Bit4+Bit5)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_0_4K_EMAW_MASK                                                   (Bit1+Bit0)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_0_4K_EMAW_SHIFT                                                  (4)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_4_8K_EMA                                                         (Bit8+Bit9+Bit10)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_4_8K_EMA_MASK                                                    (Bit2+Bit1+Bit0)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_4_8K_EMA_SHIFT                                                   (8)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_4_8K_EMAW                                                        (Bit12+Bit13)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_4_8K_EMAW_MASK                                                   (Bit1+Bit0)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_4_8K_EMAW_SHIFT                                                  (12)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_8_16K_EMA                                                        (Bit16+Bit17+Bit18)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_8_16K_EMA_MASK                                                   (Bit2+Bit1+Bit0)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_8_16K_EMA_SHIFT                                                  (16)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_8_16K_EMAW                                                       (Bit20+Bit21)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_8_16K_EMAW_MASK                                                  (Bit1+Bit0)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_8_16K_EMAW_SHIFT                                                 (20)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_16_32K_EMA                                                       (Bit24+Bit25+Bit26)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_16_32K_EMA_MASK                                                  (Bit2+Bit1+Bit0)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_16_32K_EMA_SHIFT                                                 (24)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_16_32K_EMAW                                                      (Bit28+Bit29)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_16_32K_EMAW_MASK                                                 (Bit1+Bit0)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_0_CTL_DC_RAM_16_32K_EMAW_SHIFT                                                (28)


#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1                                                                             (GLOBAL_REG_BASE + 0x308)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_DEFAULT                                                                     0x131313
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_32_64K_EMA                                                       (Bit0+Bit1+Bit2)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_32_64K_EMA_MASK                                                  (Bit2+Bit1+Bit0)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_32_64K_EMA_SHIFT                                                 (0)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_32_64K_EMAW                                                      (Bit4+Bit5)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_32_64K_EMAW_MASK                                                 (Bit1+Bit0)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_32_64K_EMAW_SHIFT                                                (4)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_64_96K_EMA                                                       (Bit8+Bit9+Bit10)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_64_96K_EMA_MASK                                                  (Bit2+Bit1+Bit0)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_64_96K_EMA_SHIFT                                                 (8)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_64_96K_EMAW                                                      (Bit12+Bit13)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_64_96K_EMAW_MASK                                                 (Bit1+Bit0)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_64_96K_EMAW_SHIFT                                                (12)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_96_128K_EMA                                                      (Bit16+Bit17+Bit18)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_96_128K_EMA_MASK                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_96_128K_EMA_SHIFT                                                (16)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_96_128K_EMAW                                                     (Bit20+Bit21)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_96_128K_EMAW_MASK                                                (Bit1+Bit0)
#define GLOBAL_REG_DATA_CODE_MEM_EMA_CONTROL_1_CTL_DC_RAM_96_128K_EMAW_SHIFT                                               (20)


#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0                                                                                (GLOBAL_REG_BASE + 0x30c)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_DEFAULT                                                                        0x13131313
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_0_EMA                                                      (Bit0+Bit1+Bit2)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_0_EMA_MASK                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_0_EMA_SHIFT                                                (0)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_0_EMAW                                                     (Bit4+Bit5)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_0_EMAW_MASK                                                (Bit1+Bit0)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_0_EMAW_SHIFT                                               (4)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_1_EMA                                                      (Bit8+Bit9+Bit10)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_1_EMA_MASK                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_1_EMA_SHIFT                                                (8)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_1_EMAW                                                     (Bit12+Bit13)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_1_EMAW_MASK                                                (Bit1+Bit0)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_1_EMAW_SHIFT                                               (12)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_2_EMA                                                      (Bit16+Bit17+Bit18)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_2_EMA_MASK                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_2_EMA_SHIFT                                                (16)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_2_EMAW                                                     (Bit20+Bit21)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_2_EMAW_MASK                                                (Bit1+Bit0)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_2_EMAW_SHIFT                                               (20)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_3_EMA                                                      (Bit24+Bit25+Bit26)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_3_EMA_MASK                                                 (Bit2+Bit1+Bit0)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_3_EMA_SHIFT                                                (24)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_3_EMAW                                                     (Bit28+Bit29)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_3_EMAW_MASK                                                (Bit1+Bit0)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_0_CTL_ICACHE_RAM_DATA_3_EMAW_SHIFT                                               (28)


#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_1                                                                                (GLOBAL_REG_BASE + 0x310)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_1_DEFAULT                                                                        0x13
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_1_CTL_ICACHE_RAM_TAG_EMA                                                         (Bit0+Bit1+Bit2)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_1_CTL_ICACHE_RAM_TAG_EMA_MASK                                                    (Bit2+Bit1+Bit0)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_1_CTL_ICACHE_RAM_TAG_EMA_SHIFT                                                   (0)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_1_CTL_ICACHE_RAM_TAG_EMAW                                                        (Bit4+Bit5)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_1_CTL_ICACHE_RAM_TAG_EMAW_MASK                                                   (Bit1+Bit0)
#define GLOBAL_REG_ICACHE_MEM_EMA_CONTROL_1_CTL_ICACHE_RAM_TAG_EMAW_SHIFT                                                  (4)


#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_0                                                                                   (GLOBAL_REG_BASE + 0x314)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_0_DEFAULT                                                                           0x13
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_0_CTL_ECC_RAM_FW_EMA                                                                (Bit0+Bit1+Bit2)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_0_CTL_ECC_RAM_FW_EMA_MASK                                                           (Bit2+Bit1+Bit0)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_0_CTL_ECC_RAM_FW_EMA_SHIFT                                                          (0)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_0_CTL_ECC_RAM_FW_EMAW                                                               (Bit4+Bit5)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_0_CTL_ECC_RAM_FW_EMAW_MASK                                                          (Bit1+Bit0)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_0_CTL_ECC_RAM_FW_EMAW_SHIFT                                                         (4)


#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1                                                                                   (GLOBAL_REG_BASE + 0x318)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_DEFAULT                                                                           0x13131313
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_A_EMA                                                                 (Bit0+Bit1+Bit2)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_A_EMA_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_A_EMA_SHIFT                                                           (0)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_A_EMAW                                                                (Bit4+Bit5)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_A_EMAW_MASK                                                           (Bit1+Bit0)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_A_EMAW_SHIFT                                                          (4)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_B_EMA                                                                 (Bit8+Bit9+Bit10)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_B_EMA_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_B_EMA_SHIFT                                                           (8)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_B_EMAW                                                                (Bit12+Bit13)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_B_EMAW_MASK                                                           (Bit1+Bit0)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_B_EMAW_SHIFT                                                          (12)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_C_EMA                                                                 (Bit16+Bit17+Bit18)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_C_EMA_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_C_EMA_SHIFT                                                           (16)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_C_EMAW                                                                (Bit20+Bit21)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_C_EMAW_MASK                                                           (Bit1+Bit0)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_C_EMAW_SHIFT                                                          (20)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_D_EMA                                                                 (Bit24+Bit25+Bit26)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_D_EMA_MASK                                                            (Bit2+Bit1+Bit0)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_D_EMA_SHIFT                                                           (24)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_D_EMAW                                                                (Bit28+Bit29)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_D_EMAW_MASK                                                           (Bit1+Bit0)
#define GLOBAL_REG_ECC_MEM_EMA_CONTROL_1_CTL_ECC_RAM_D_EMAW_SHIFT                                                          (28)


#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL                                                                                   (GLOBAL_REG_BASE + 0x31c)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_DEFAULT                                                                           0x13131313
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_A_EMA                                                               (Bit0+Bit1+Bit2)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_A_EMA_MASK                                                          (Bit2+Bit1+Bit0)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_A_EMA_SHIFT                                                         (0)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_A_EMAW                                                              (Bit4+Bit5)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_A_EMAW_MASK                                                         (Bit1+Bit0)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_A_EMAW_SHIFT                                                        (4)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_B_EMA                                                               (Bit8+Bit9+Bit10)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_B_EMA_MASK                                                          (Bit2+Bit1+Bit0)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_B_EMA_SHIFT                                                         (8)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_B_EMAW                                                              (Bit12+Bit13)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_B_EMAW_MASK                                                         (Bit1+Bit0)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_B_EMAW_SHIFT                                                        (12)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_C_EMA                                                               (Bit16+Bit17+Bit18)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_C_EMA_MASK                                                          (Bit2+Bit1+Bit0)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_C_EMA_SHIFT                                                         (16)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_C_EMAW                                                              (Bit20+Bit21)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_C_EMAW_MASK                                                         (Bit1+Bit0)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_C_EMAW_SHIFT                                                        (20)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_D_EMA                                                               (Bit24+Bit25+Bit26)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_D_EMA_MASK                                                          (Bit2+Bit1+Bit0)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_D_EMA_SHIFT                                                         (24)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_D_EMAW                                                              (Bit28+Bit29)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_D_EMAW_MASK                                                         (Bit1+Bit0)
#define GLOBAL_REG_HWACC_MEM_EMA_CONTROL_CTL_HWACC_RAM_D_EMAW_SHIFT                                                        (28)


#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0                                                                                (GLOBAL_REG_BASE + 0x324)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_DEFAULT                                                                        0x13131313
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_0_EMA                                                            (Bit0+Bit1+Bit2)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_0_EMA_MASK                                                       (Bit2+Bit1+Bit0)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_0_EMA_SHIFT                                                      (0)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_0_EMAW                                                           (Bit4+Bit5)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_0_EMAW_MASK                                                      (Bit1+Bit0)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_0_EMAW_SHIFT                                                     (4)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_1_EMA                                                            (Bit8+Bit9+Bit10)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_1_EMA_MASK                                                       (Bit2+Bit1+Bit0)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_1_EMA_SHIFT                                                      (8)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_1_EMAW                                                           (Bit12+Bit13)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_1_EMAW_MASK                                                      (Bit1+Bit0)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_1_EMAW_SHIFT                                                     (12)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_2_EMA                                                            (Bit16+Bit17+Bit18)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_2_EMA_MASK                                                       (Bit2+Bit1+Bit0)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_2_EMA_SHIFT                                                      (16)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_2_EMAW                                                           (Bit20+Bit21)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_2_EMAW_MASK                                                      (Bit1+Bit0)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_2_EMAW_SHIFT                                                     (20)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_3_EMA                                                            (Bit24+Bit25+Bit26)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_3_EMA_MASK                                                       (Bit2+Bit1+Bit0)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_3_EMA_SHIFT                                                      (24)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_3_EMAW                                                           (Bit28+Bit29)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_3_EMAW_MASK                                                      (Bit1+Bit0)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_0_CTL_SHMEM_RAM_3_EMAW_SHIFT                                                     (28)


#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_A                                                                                (GLOBAL_REG_BASE + 0x328)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_A_DEFAULT                                                                        0x13
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_A_CTL_SHMEM_RAM_4_EMA                                                            (Bit0+Bit1+Bit2)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_A_CTL_SHMEM_RAM_4_EMA_MASK                                                       (Bit2+Bit1+Bit0)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_A_CTL_SHMEM_RAM_4_EMA_SHIFT                                                      (0)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_A_CTL_SHMEM_RAM_4_EMAW                                                           (Bit4+Bit5)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_A_CTL_SHMEM_RAM_4_EMAW_MASK                                                      (Bit1+Bit0)
#define GLOBAL_REG_SHARED_MEM_EMA_CONTROL_A_CTL_SHMEM_RAM_4_EMAW_SHIFT                                                     (4)


#define GLOBAL_REG_ROM_EMA_CONTROL                                                                                         (GLOBAL_REG_BASE + 0x32c)
#define GLOBAL_REG_ROM_EMA_CONTROL_DEFAULT                                                                                 0x103103
#define GLOBAL_REG_ROM_EMA_CONTROL_CTL_BOOT_ROM_ROM0_EMA                                                                   (Bit0+Bit1+Bit2)
#define GLOBAL_REG_ROM_EMA_CONTROL_CTL_BOOT_ROM_ROM0_EMA_MASK                                                              (Bit2+Bit1+Bit0)
#define GLOBAL_REG_ROM_EMA_CONTROL_CTL_BOOT_ROM_ROM0_EMA_SHIFT                                                             (0)
#define GLOBAL_REG_ROM_EMA_CONTROL_CTL_BOOT_ROM_ROM0_PGEN                                                                  (Bit4)
#define GLOBAL_REG_ROM_EMA_CONTROL_CTL_BOOT_ROM_ROM0_KEN                                                                   (Bit8)
#define GLOBAL_REG_ROM_EMA_CONTROL_CTL_BOOT_ROM_ROM1_EMA                                                                   (Bit12+Bit13+Bit14)
#define GLOBAL_REG_ROM_EMA_CONTROL_CTL_BOOT_ROM_ROM1_EMA_MASK                                                              (Bit2+Bit1+Bit0)
#define GLOBAL_REG_ROM_EMA_CONTROL_CTL_BOOT_ROM_ROM1_EMA_SHIFT                                                             (12)
#define GLOBAL_REG_ROM_EMA_CONTROL_CTL_BOOT_ROM_ROM1_PGEN                                                                  (Bit16)
#define GLOBAL_REG_ROM_EMA_CONTROL_CTL_BOOT_ROM_ROM1_KEN                                                                   (Bit20)


#define GLOBAL_REG_TRX_SEQ_MISC                                                                                            (GLOBAL_REG_BASE + 0x340)
#define GLOBAL_REG_TRX_SEQ_MISC_DEFAULT                                                                                    0x0
#define GLOBAL_REG_TRX_SEQ_MISC_CTL_TRX_WAKEUP_ARM                                                                         (Bit0)


#define GLOBAL_REG_PD0_MISC_STATUS                                                                                         (GLOBAL_REG_BASE + 0x3c0)
#define GLOBAL_REG_PD0_MISC_STATUS_DEFAULT                                                                                 0x0
#define GLOBAL_REG_PD0_MISC_STATUS_STS_BOD_OUT_1P2                                                                         (Bit0)
#define GLOBAL_REG_PD0_MISC_STATUS_STS_PMU_SPARE                                                                           (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_PD0_MISC_STATUS_STS_PMU_SPARE_MASK                                                                      (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PD0_MISC_STATUS_STS_PMU_SPARE_SHIFT                                                                     (4)


#define GLOBAL_REG_PD0_AON_TIMER0_CURR_VAL                                                                                 (GLOBAL_REG_BASE + 0x3c4)
#define GLOBAL_REG_PD0_AON_TIMER0_CURR_VAL_DEFAULT                                                                         0x0
#define GLOBAL_REG_PD0_AON_TIMER0_CURR_VAL_STS_AON_TIMER0_CURR_VAL                                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define GLOBAL_REG_PD0_AON_TIMER0_CURR_VAL_STS_AON_TIMER0_CURR_VAL_MASK                                                    (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PD0_AON_TIMER0_CURR_VAL_STS_AON_TIMER0_CURR_VAL_SHIFT                                                   (0)


#define GLOBAL_REG_PD0_AON_TIMER1_CURR_VAL                                                                                 (GLOBAL_REG_BASE + 0x3c8)
#define GLOBAL_REG_PD0_AON_TIMER1_CURR_VAL_DEFAULT                                                                         0x0
#define GLOBAL_REG_PD0_AON_TIMER1_CURR_VAL_STS_AON_TIMER1_CURR_VAL                                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define GLOBAL_REG_PD0_AON_TIMER1_CURR_VAL_STS_AON_TIMER1_CURR_VAL_MASK                                                    (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PD0_AON_TIMER1_CURR_VAL_STS_AON_TIMER1_CURR_VAL_SHIFT                                                   (0)


#define GLOBAL_REG_PD0_GPIO_WAKEUP_0                                                                                       (GLOBAL_REG_BASE + 0x3cc)
#define GLOBAL_REG_PD0_GPIO_WAKEUP_0_DEFAULT                                                                               0x0
#define GLOBAL_REG_PD0_GPIO_WAKEUP_0_STS_GPIO_0_WAKUP                                                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define GLOBAL_REG_PD0_GPIO_WAKEUP_0_STS_GPIO_0_WAKUP_MASK                                                                 (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PD0_GPIO_WAKEUP_0_STS_GPIO_0_WAKUP_SHIFT                                                                (0)
#define GLOBAL_REG_PD0_GPIO_WAKEUP_0_STS_GPIO_1_WAKUP                                                                      (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16)
#define GLOBAL_REG_PD0_GPIO_WAKEUP_0_STS_GPIO_1_WAKUP_MASK                                                                 (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PD0_GPIO_WAKEUP_0_STS_GPIO_1_WAKUP_SHIFT                                                                (8)


#define GLOBAL_REG_PD0_GPIO_WAKEUP_STS2                                                                                    (GLOBAL_REG_BASE + 0x3d0)
#define GLOBAL_REG_PD0_GPIO_WAKEUP_STS2_DEFAULT                                                                            0x0
#define GLOBAL_REG_PD0_GPIO_WAKEUP_STS2_STS_GPIO_3_WAKUP                                                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define GLOBAL_REG_PD0_GPIO_WAKEUP_STS2_STS_GPIO_3_WAKUP_MASK                                                              (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PD0_GPIO_WAKEUP_STS2_STS_GPIO_3_WAKUP_SHIFT                                                             (0)
#define GLOBAL_REG_PD0_GPIO_WAKEUP_STS2_STS_GPIO_4_WAKUP                                                                   (Bit8+Bit9)
#define GLOBAL_REG_PD0_GPIO_WAKEUP_STS2_STS_GPIO_4_WAKUP_MASK                                                              (Bit1+Bit0)
#define GLOBAL_REG_PD0_GPIO_WAKEUP_STS2_STS_GPIO_4_WAKUP_SHIFT                                                             (8)


#define GLOBAL_REG_PD0_MS_GPIO_WAKEUP_STS                                                                                  (GLOBAL_REG_BASE + 0x3d4)
#define GLOBAL_REG_PD0_MS_GPIO_WAKEUP_STS_DEFAULT                                                                          0x0
#define GLOBAL_REG_PD0_MS_GPIO_WAKEUP_STS_STS_MS_GPIO_WAKUP                                                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8)
#define GLOBAL_REG_PD0_MS_GPIO_WAKEUP_STS_STS_MS_GPIO_WAKUP_MASK                                                           (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PD0_MS_GPIO_WAKEUP_STS_STS_MS_GPIO_WAKUP_SHIFT                                                          (0)
#define GLOBAL_REG_PD0_MS_GPIO_WAKEUP_STS_STS_BOD_WAKEUP_STATUS                                                            (Bit12)


#define GLOBAL_REG_PD0_GPIO_01_DIN                                                                                         (GLOBAL_REG_BASE + 0x3d8)
#define GLOBAL_REG_PD0_GPIO_01_DIN_DEFAULT                                                                                 0x0
#define GLOBAL_REG_PD0_GPIO_01_DIN_STS_GPIO_0_DIN                                                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define GLOBAL_REG_PD0_GPIO_01_DIN_STS_GPIO_0_DIN_MASK                                                                     (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PD0_GPIO_01_DIN_STS_GPIO_0_DIN_SHIFT                                                                    (0)
#define GLOBAL_REG_PD0_GPIO_01_DIN_STS_GPIO_1_DIN                                                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24)
#define GLOBAL_REG_PD0_GPIO_01_DIN_STS_GPIO_1_DIN_MASK                                                                     (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PD0_GPIO_01_DIN_STS_GPIO_1_DIN_SHIFT                                                                    (16)


#define GLOBAL_REG_PD0_GPIO_234_DIN                                                                                        (GLOBAL_REG_BASE + 0x3dc)
#define GLOBAL_REG_PD0_GPIO_234_DIN_DEFAULT                                                                                0x0
#define GLOBAL_REG_PD0_GPIO_234_DIN_STS_GPIO_2_DIN                                                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10)
#define GLOBAL_REG_PD0_GPIO_234_DIN_STS_GPIO_2_DIN_MASK                                                                    (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PD0_GPIO_234_DIN_STS_GPIO_2_DIN_SHIFT                                                                   (0)
#define GLOBAL_REG_PD0_GPIO_234_DIN_STS_GPIO_3_DIN                                                                         (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_PD0_GPIO_234_DIN_STS_GPIO_3_DIN_MASK                                                                    (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_PD0_GPIO_234_DIN_STS_GPIO_3_DIN_SHIFT                                                                   (12)
#define GLOBAL_REG_PD0_GPIO_234_DIN_STS_GPIO_4_DIN                                                                         (Bit24+Bit25)
#define GLOBAL_REG_PD0_GPIO_234_DIN_STS_GPIO_4_DIN_MASK                                                                    (Bit1+Bit0)
#define GLOBAL_REG_PD0_GPIO_234_DIN_STS_GPIO_4_DIN_SHIFT                                                                   (24)


#define GLOBAL_REG_RF_BUSY_CTRL                                                                                            (GLOBAL_REG_BASE + 0x3e8)
#define GLOBAL_REG_RF_BUSY_CTRL_DEFAULT                                                                                    0x1
#define GLOBAL_REG_RF_BUSY_CTRL_CTL_RF_BUSY_FORCE                                                                          (Bit0)
#define GLOBAL_REG_RF_BUSY_CTRL_CTL_RF_BUSY_FORCE_VAL                                                                      (Bit1)


#define GLOBAL_REG_BLE_ADDITIONAL_CONTROL                                                                                  (GLOBAL_REG_BASE + 0x3f8)
#define GLOBAL_REG_BLE_ADDITIONAL_CONTROL_DEFAULT                                                                          0x0
#define GLOBAL_REG_BLE_ADDITIONAL_CONTROL_CTL_BLE_PHASE_MATCH_SOFT_RESET                                                   (Bit0)
#define GLOBAL_REG_BLE_ADDITIONAL_CONTROL_CTL_BLE_TX_EN_2_DLY                                                              (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_BLE_ADDITIONAL_CONTROL_CTL_BLE_TX_EN_2_DLY_MASK                                                         (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_BLE_ADDITIONAL_CONTROL_CTL_BLE_TX_EN_2_DLY_SHIFT                                                        (4)
#define GLOBAL_REG_BLE_ADDITIONAL_CONTROL_CTL_GLB_SPARE                                                                    (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define GLOBAL_REG_BLE_ADDITIONAL_CONTROL_CTL_GLB_SPARE_MASK                                                               (Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_BLE_ADDITIONAL_CONTROL_CTL_GLB_SPARE_SHIFT                                                              (12)


#define GLOBAL_REG_BLE_ADDITIONAL_STATUS                                                                                   (GLOBAL_REG_BASE + 0x3fc)
#define GLOBAL_REG_BLE_ADDITIONAL_STATUS_DEFAULT                                                                           0x0
#define GLOBAL_REG_BLE_ADDITIONAL_STATUS_STS_BLE_PHASE_MATCH_RDY                                                           (Bit0)


#define GLOBAL_REG_WDT_PWM_CONTROL                                                                                         (GLOBAL_REG_BASE + 0x408)
#define GLOBAL_REG_WDT_PWM_CONTROL_DEFAULT                                                                                 0x0
#define GLOBAL_REG_WDT_PWM_CONTROL_CTL_PWM_0_WDT_TRIGGER                                                                   (Bit0+Bit1)
#define GLOBAL_REG_WDT_PWM_CONTROL_CTL_PWM_0_WDT_TRIGGER_MASK                                                              (Bit1+Bit0)
#define GLOBAL_REG_WDT_PWM_CONTROL_CTL_PWM_0_WDT_TRIGGER_SHIFT                                                             (0)
#define GLOBAL_REG_WDT_PWM_CONTROL_CTL_PWM_1_WDT_TRIGGER                                                                   (Bit4+Bit5)
#define GLOBAL_REG_WDT_PWM_CONTROL_CTL_PWM_1_WDT_TRIGGER_MASK                                                              (Bit1+Bit0)
#define GLOBAL_REG_WDT_PWM_CONTROL_CTL_PWM_1_WDT_TRIGGER_SHIFT                                                             (4)
#define GLOBAL_REG_WDT_PWM_CONTROL_CTL_PWM_2_WDT_TRIGGER                                                                   (Bit8+Bit9)
#define GLOBAL_REG_WDT_PWM_CONTROL_CTL_PWM_2_WDT_TRIGGER_MASK                                                              (Bit1+Bit0)
#define GLOBAL_REG_WDT_PWM_CONTROL_CTL_PWM_2_WDT_TRIGGER_SHIFT                                                             (8)
#define GLOBAL_REG_WDT_PWM_CONTROL_CTL_PWM_3_WDT_TRIGGER                                                                   (Bit12+Bit13)
#define GLOBAL_REG_WDT_PWM_CONTROL_CTL_PWM_3_WDT_TRIGGER_MASK                                                              (Bit1+Bit0)
#define GLOBAL_REG_WDT_PWM_CONTROL_CTL_PWM_3_WDT_TRIGGER_SHIFT                                                             (12)
#define GLOBAL_REG_WDT_PWM_CONTROL_CTL_PWM_4_WDT_TRIGGER                                                                   (Bit16+Bit17)
#define GLOBAL_REG_WDT_PWM_CONTROL_CTL_PWM_4_WDT_TRIGGER_MASK                                                              (Bit1+Bit0)
#define GLOBAL_REG_WDT_PWM_CONTROL_CTL_PWM_4_WDT_TRIGGER_SHIFT                                                             (16)


#define GLOBAL_REG_ROMCRC_CTRL                                                                                             (GLOBAL_REG_BASE + 0x440)
#define GLOBAL_REG_ROMCRC_CTRL_DEFAULT                                                                                     0x0
#define GLOBAL_REG_ROMCRC_CTRL_CTL_ROMCRC_EN                                                                               (Bit0)


#define GLOBAL_REG_ROMCRC_STS                                                                                              (GLOBAL_REG_BASE + 0x444)
#define GLOBAL_REG_ROMCRC_STS_DEFAULT                                                                                      0x0
#define GLOBAL_REG_ROMCRC_STS_STS_ROMCRC_DONE                                                                              (Bit0)
#define GLOBAL_REG_ROMCRC_STS_STS_ROMCRC_ERR                                                                               (Bit1)


#define GLOBAL_REG_MBIST_MODE                                                                                              (GLOBAL_REG_BASE + 0x800)
#define GLOBAL_REG_MBIST_MODE_DEFAULT                                                                                      0x0
#define GLOBAL_REG_MBIST_MODE_CTL_MBIST_MODE                                                                               (Bit0)


#define GLOBAL_REG_MBIST_START                                                                                             (GLOBAL_REG_BASE + 0x804)
#define GLOBAL_REG_MBIST_START_DEFAULT                                                                                     0x0
#define GLOBAL_REG_MBIST_START_CTL_START_MBIST_1_CTRLR                                                                     (Bit0)
#define GLOBAL_REG_MBIST_START_CTL_START_MBIST_2_CTRLR                                                                     (Bit1)
#define GLOBAL_REG_MBIST_START_CTL_START_MBIST_3_CTRLR                                                                     (Bit2)
#define GLOBAL_REG_MBIST_START_CTL_START_MBIST_4_CTRLR                                                                     (Bit3)
#define GLOBAL_REG_MBIST_START_CTL_START_MBIST_5_CTRLR                                                                     (Bit4)
#define GLOBAL_REG_MBIST_START_CTL_START_MBIST_6_CTRLR                                                                     (Bit5)
#define GLOBAL_REG_MBIST_START_CTL_START_MBIST_7_CTRLR                                                                     (Bit6)


#define GLOBAL_REG_MBIST_MEMORY_TEN                                                                                        (GLOBAL_REG_BASE + 0x808)
#define GLOBAL_REG_MBIST_MEMORY_TEN_DEFAULT                                                                                0x7FFFFF
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_SRAM_32K_DC_TEN                                                                    (Bit0)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_SRAM_CACHE_TAG_TEN                                                                 (Bit1)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_SRAM_16K_DC_TEN                                                                    (Bit2)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_SRAM_CACHE_DATA_0_TEN                                                              (Bit3)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_SRAM_CACHE_DATA_1_TEN                                                              (Bit4)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_SRAM_4K_0_DC_TEN                                                                   (Bit5)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_SRAM_4K_1_DC_TEN                                                                   (Bit6)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_SRAM_8K_DC_TEN                                                                     (Bit7)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_SRAM0_SHM_TEN                                                                      (Bit8)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_SRAM1_SHM_TEN                                                                      (Bit9)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_SRAM2_SHM_TEN                                                                      (Bit10)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_SRAM3_SHM_TEN                                                                      (Bit11)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_SRAM4_SHM_TEN                                                                      (Bit12)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_SRAM_ECC_FW_TEN                                                                    (Bit13)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_RF_HWACC_A_TEN                                                                     (Bit14)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_RF_HWACC_B_TEN                                                                     (Bit15)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_RF_HWACC_C_TEN                                                                     (Bit16)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_RF_HWACC_D_TEN                                                                     (Bit17)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_RF_ECC_A_TEN                                                                       (Bit18)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_RF_ECC_B_TEN                                                                       (Bit19)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_RF_ECC_C_TEN                                                                       (Bit20)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_RF_ECC_D_TEN                                                                       (Bit21)
#define GLOBAL_REG_MBIST_MEMORY_TEN_CTL_RF_PLLTRIG_TEN                                                                     (Bit22)


#define GLOBAL_REG_MBIST_BG                                                                                                (GLOBAL_REG_BASE + 0x80c)
#define GLOBAL_REG_MBIST_BG_DEFAULT                                                                                        0x1
#define GLOBAL_REG_MBIST_BG_CTL_MBIST_BG                                                                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define GLOBAL_REG_MBIST_BG_CTL_MBIST_BG_MASK                                                                              (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_MBIST_BG_CTL_MBIST_BG_SHIFT                                                                             (0)


#define GLOBAL_REG_MBIST_USE_ALT_DATA                                                                                      (GLOBAL_REG_BASE + 0x810)
#define GLOBAL_REG_MBIST_USE_ALT_DATA_DEFAULT                                                                              0x0
#define GLOBAL_REG_MBIST_USE_ALT_DATA_CTL_USE_ALT_DATA_MBIST                                                               (Bit0)


#define GLOBAL_REG_STS_MBIST_PASS_FAIL                                                                                     (GLOBAL_REG_BASE + 0x814)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_DEFAULT                                                                             0x0
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_SRAM_32K_DC_FAIL_MBIST_1_CTRLR                                            (Bit0)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_SRAM_CACHE_TAG_FAIL_MBIST_2_CTRLR                                         (Bit1)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_SRAM_CACHE_DATA_0_FAIL_MBIST_2_CTRLR                                      (Bit2)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_SRAM_CACHE_DATA_1_FAIL_MBIST_2_CTRLR                                      (Bit3)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_RF_HWACC_A_FAIL_MBIST_2_CTRLR                                             (Bit4)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_RF_HWACC_B_FAIL_MBIST_2_CTRLR                                             (Bit5)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_RF_HWACC_C_FAIL_MBIST_2_CTRLR                                             (Bit6)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_RF_HWACC_D_FAIL_MBIST_2_CTRLR                                             (Bit7)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_SRAM_16K_DC_FAIL_MBIST_3_CTRLR                                            (Bit8)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_SRAM_4K_0_DC_FAIL_MBIST_3_CTRLR                                           (Bit9)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_SRAM_4K_1_DC_FAIL_MBIST_3_CTRLR                                           (Bit10)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_SRAM_8K_DC_FAIL_MBIST_3_CTRLR                                             (Bit11)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_SRAM0_SHM_FAIL_MBIST_4_CTRLR                                              (Bit12)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_SRAM1_SHM_FAIL_MBIST_4_CTRLR                                              (Bit13)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_SRAM2_SHM_FAIL_MBIST_4_CTRLR                                              (Bit14)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_SRAM4_SHM_FAIL_MBIST_5_CTRLR                                              (Bit15)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_SRAM3_SHM_FAIL_MBIST_6_CTRLR                                              (Bit16)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_RF_PLLTRIG_FAIL_MBIST_6_CTRLR                                             (Bit17)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_SRAM_ECC_FW_FAIL_MBIST_7_CTRLR                                            (Bit18)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_RF_ECC_A_FAIL_MBIST_7_CTRLR                                               (Bit19)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_RF_ECC_B_FAIL_MBIST_7_CTRLR                                               (Bit20)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_RF_ECC_C_FAIL_MBIST_7_CTRLR                                               (Bit21)
#define GLOBAL_REG_STS_MBIST_PASS_FAIL_STS_MBIST_RF_ECC_D_FAIL_MBIST_7_CTRLR                                               (Bit22)


#define GLOBAL_REG_STS_MBIST_DONE                                                                                          (GLOBAL_REG_BASE + 0x818)
#define GLOBAL_REG_STS_MBIST_DONE_DEFAULT                                                                                  0x0
#define GLOBAL_REG_STS_MBIST_DONE_STS_MBIST_TEST_DONE_MBIST_1_CTRLR                                                        (Bit0)
#define GLOBAL_REG_STS_MBIST_DONE_STS_MBIST_TEST_DONE_MBIST_2_CTRLR                                                        (Bit1)
#define GLOBAL_REG_STS_MBIST_DONE_STS_MBIST_TEST_DONE_MBIST_3_CTRLR                                                        (Bit2)
#define GLOBAL_REG_STS_MBIST_DONE_STS_MBIST_TEST_DONE_MBIST_4_CTRLR                                                        (Bit3)
#define GLOBAL_REG_STS_MBIST_DONE_STS_MBIST_TEST_DONE_MBIST_5_CTRLR                                                        (Bit4)
#define GLOBAL_REG_STS_MBIST_DONE_STS_MBIST_TEST_DONE_MBIST_6_CTRLR                                                        (Bit5)
#define GLOBAL_REG_STS_MBIST_DONE_STS_MBIST_TEST_DONE_MBIST_7_CTRLR                                                        (Bit6)


#define GLOBAL_REG_MBIST_CTRL_1                                                                                            (GLOBAL_REG_BASE + 0x81c)
#define GLOBAL_REG_MBIST_CTRL_1_DEFAULT                                                                                    0x0
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_MARCH_Y_ALG_MBIST_1_CTRLR                                                       (Bit0)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_COL_MARCH_ALG_MBIST_1_CTRLR                                                     (Bit1)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_WRITE_DATA_ALG_MBIST_1_CTRLR                                                    (Bit2)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_READ_DATA_ALG_MBIST_1_CTRLR                                                     (Bit3)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_MARCH_Y_ALG_MBIST_2_CTRLR                                                       (Bit4)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_COL_MARCH_ALG_MBIST_2_CTRLR                                                     (Bit5)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_MARCH_Y_ALG_MBIST_3_CTRLR                                                       (Bit8)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_COL_MARCH_ALG_MBIST_3_CTRLR                                                     (Bit9)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_WRITE_DATA_ALG_MBIST_3_CTRLR                                                    (Bit10)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_READ_DATA_ALG_MBIST_3_CTRLR                                                     (Bit11)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_MARCH_Y_ALG_MBIST_4_CTRLR                                                       (Bit12)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_COL_MARCH_ALG_MBIST_4_CTRLR                                                     (Bit13)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_WRITE_DATA_ALG_MBIST_4_CTRLR                                                    (Bit14)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_READ_DATA_ALG_MBIST_4_CTRLR                                                     (Bit15)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_MARCH_Y_ALG_MBIST_5_CTRLR                                                       (Bit16)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_COL_MARCH_ALG_MBIST_5_CTRLR                                                     (Bit17)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_WRITE_DATA_ALG_MBIST_5_CTRLR                                                    (Bit18)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_READ_DATA_ALG_MBIST_5_CTRLR                                                     (Bit19)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_MARCH_Y_ALG_MBIST_6_CTRLR                                                       (Bit20)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_COL_MARCH_ALG_MBIST_6_CTRLR                                                     (Bit21)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_WRITE_DATA_ALG_MBIST_6_CTRLR                                                    (Bit22)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_READ_DATA_ALG_MBIST_6_CTRLR                                                     (Bit23)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_MARCH_Y_ALG_MBIST_7_CTRLR                                                       (Bit24)
#define GLOBAL_REG_MBIST_CTRL_1_CTL_ENABLE_COL_MARCH_ALG_MBIST_7_CTRLR                                                     (Bit25)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_1                                                                                 (GLOBAL_REG_BASE + 0x820)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_1_DEFAULT                                                                         0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_1_STS_SRAM_32K_DC_MARCH_Y_ALG_FAIL_MBIST_1_CTRLR                                  (Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_1_STS_SRAM_32K_DC_COL_MARCH_ALG_FAIL_MBIST_1_CTRLR                                (Bit1)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_1_STS_SRAM_32K_DC_READ_DATA_ALG_FAIL_MBIST_1_CTRLR                                (Bit2)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_1_STS_SRAM_32K_DC_MARCH_Y_ALG_FAILING_ADDR_MBIST_1_CTRLR                          (Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_1_STS_SRAM_32K_DC_MARCH_Y_ALG_FAILING_ADDR_MBIST_1_CTRLR_MASK                     (Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_1_STS_SRAM_32K_DC_MARCH_Y_ALG_FAILING_ADDR_MBIST_1_CTRLR_SHIFT                    (3)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_1_STS_SRAM_32K_DC_COL_MARCH_ALG_FAILING_ADDR_MBIST_1_CTRLR                        (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_1_STS_SRAM_32K_DC_COL_MARCH_ALG_FAILING_ADDR_MBIST_1_CTRLR_MASK                   (Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_1_STS_SRAM_32K_DC_COL_MARCH_ALG_FAILING_ADDR_MBIST_1_CTRLR_SHIFT                  (16)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_2                                                                                 (GLOBAL_REG_BASE + 0x824)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_2_DEFAULT                                                                         0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_2_STS_SRAM_32K_DC_READ_DATA_ALG_FAILING_ADDR_MBIST_1_CTRLR                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_2_STS_SRAM_32K_DC_READ_DATA_ALG_FAILING_ADDR_MBIST_1_CTRLR_MASK                   (Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_2_STS_SRAM_32K_DC_READ_DATA_ALG_FAILING_ADDR_MBIST_1_CTRLR_SHIFT                  (0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_2_STS_SRAM_CACHE_TAG_MARCH_Y_ALG_FAIL_MBIST_2_CTRLR                               (Bit13)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_2_STS_SRAM_CACHE_TAG_COL_MARCH_ALG_FAIL_MBIST_2_CTRLR                             (Bit14)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_2_STS_SRAM_CACHE_TAG_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR                       (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_2_STS_SRAM_CACHE_TAG_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR_MASK                  (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_2_STS_SRAM_CACHE_TAG_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR_SHIFT                 (16)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_3                                                                                 (GLOBAL_REG_BASE + 0x828)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_3_DEFAULT                                                                         0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_3_STS_SRAM_CACHE_TAG_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_3_STS_SRAM_CACHE_TAG_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR_MASK                (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_3_STS_SRAM_CACHE_TAG_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR_SHIFT               (0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_3_STS_SRAM_16K_DC_MARCH_Y_ALG_FAIL_MBIST_3_CTRLR                                  (Bit24)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_3_STS_SRAM_16K_DC_COL_MARCH_ALG_FAIL_MBIST_3_CTRLR                                (Bit25)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_3_STS_SRAM_16K_DC_READ_DATA_ALG_FAIL_MBIST_3_CTRLR                                (Bit26)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_4                                                                                 (GLOBAL_REG_BASE + 0x82c)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_4_DEFAULT                                                                         0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_4_STS_SRAM_16K_DC_MARCH_Y_ALG_FAILING_ADDR_MBIST_3_CTRLR                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_4_STS_SRAM_16K_DC_MARCH_Y_ALG_FAILING_ADDR_MBIST_3_CTRLR_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_4_STS_SRAM_16K_DC_MARCH_Y_ALG_FAILING_ADDR_MBIST_3_CTRLR_SHIFT                    (0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_4_STS_SRAM_16K_DC_COL_MARCH_ALG_FAILING_ADDR_MBIST_3_CTRLR                        (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_4_STS_SRAM_16K_DC_COL_MARCH_ALG_FAILING_ADDR_MBIST_3_CTRLR_MASK                   (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_4_STS_SRAM_16K_DC_COL_MARCH_ALG_FAILING_ADDR_MBIST_3_CTRLR_SHIFT                  (12)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_5                                                                                 (GLOBAL_REG_BASE + 0x830)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_5_DEFAULT                                                                         0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_5_STS_SRAM_16K_DC_READ_DATA_ALG_FAILING_ADDR_MBIST_3_CTRLR                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_5_STS_SRAM_16K_DC_READ_DATA_ALG_FAILING_ADDR_MBIST_3_CTRLR_MASK                   (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_5_STS_SRAM_16K_DC_READ_DATA_ALG_FAILING_ADDR_MBIST_3_CTRLR_SHIFT                  (0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_5_STS_SRAM_CACHE_DATA_0_MARCH_Y_ALG_FAIL_MBIST_2_CTRLR                            (Bit12)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_5_STS_SRAM_CACHE_DATA_0_COL_MARCH_ALG_FAIL_MBIST_2_CTRLR                          (Bit13)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_5_STS_SRAM_CACHE_DATA_0_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR                    (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_5_STS_SRAM_CACHE_DATA_0_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR_MASK               (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_5_STS_SRAM_CACHE_DATA_0_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR_SHIFT              (16)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_6                                                                                 (GLOBAL_REG_BASE + 0x834)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_6_DEFAULT                                                                         0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_6_STS_SRAM_CACHE_DATA_0_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_6_STS_SRAM_CACHE_DATA_0_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR_MASK             (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_6_STS_SRAM_CACHE_DATA_0_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR_SHIFT            (0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_6_STS_SRAM_CACHE_DATA_1_MARCH_Y_ALG_FAIL_MBIST_2_CTRLR                            (Bit24)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_6_STS_SRAM_CACHE_DATA_1_COL_MARCH_ALG_FAIL_MBIST_2_CTRLR                          (Bit25)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_7                                                                                 (GLOBAL_REG_BASE + 0x838)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_7_DEFAULT                                                                         0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_7_STS_SRAM_CACHE_DATA_1_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR                    (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_7_STS_SRAM_CACHE_DATA_1_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR_MASK               (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_7_STS_SRAM_CACHE_DATA_1_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR_SHIFT              (0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_7_STS_SRAM_CACHE_DATA_1_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR                  (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_7_STS_SRAM_CACHE_DATA_1_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR_MASK             (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_7_STS_SRAM_CACHE_DATA_1_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR_SHIFT            (12)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_8                                                                                 (GLOBAL_REG_BASE + 0x83c)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_8_DEFAULT                                                                         0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_8_STS_SRAM_4K_0_DC_MARCH_Y_ALG_FAIL_MBIST_3_CTRLR                                 (Bit12)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_8_STS_SRAM_4K_0_DC_COL_MARCH_ALG_FAIL_MBIST_3_CTRLR                               (Bit13)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_8_STS_SRAM_4K_0_DC_READ_DATA_ALG_FAIL_MBIST_3_CTRLR                               (Bit14)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_8_STS_SRAM_4K_0_DC_MARCH_Y_ALG_FAILING_ADDR_MBIST_3_CTRLR                         (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_8_STS_SRAM_4K_0_DC_MARCH_Y_ALG_FAILING_ADDR_MBIST_3_CTRLR_MASK                    (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_8_STS_SRAM_4K_0_DC_MARCH_Y_ALG_FAILING_ADDR_MBIST_3_CTRLR_SHIFT                   (16)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_9                                                                                 (GLOBAL_REG_BASE + 0x840)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_9_DEFAULT                                                                         0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_9_STS_SRAM_4K_0_DC_COL_MARCH_ALG_FAILING_ADDR_MBIST_3_CTRLR                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_9_STS_SRAM_4K_0_DC_COL_MARCH_ALG_FAILING_ADDR_MBIST_3_CTRLR_MASK                  (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_9_STS_SRAM_4K_0_DC_COL_MARCH_ALG_FAILING_ADDR_MBIST_3_CTRLR_SHIFT                 (0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_9_STS_SRAM_4K_0_DC_READ_DATA_ALG_FAILING_ADDR_MBIST_3_CTRLR                       (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_9_STS_SRAM_4K_0_DC_READ_DATA_ALG_FAILING_ADDR_MBIST_3_CTRLR_MASK                  (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_9_STS_SRAM_4K_0_DC_READ_DATA_ALG_FAILING_ADDR_MBIST_3_CTRLR_SHIFT                 (12)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_9_STS_SRAM_4K_1_DC_MARCH_Y_ALG_FAIL_MBIST_3_CTRLR                                 (Bit24)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_9_STS_SRAM_4K_1_DC_COL_MARCH_ALG_FAIL_MBIST_3_CTRLR                               (Bit25)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_9_STS_SRAM_4K_1_DC_READ_DATA_ALG_FAIL_MBIST_3_CTRLR                               (Bit26)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_10                                                                                (GLOBAL_REG_BASE + 0x844)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_10_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_10_STS_SRAM_4K_1_DC_MARCH_Y_ALG_FAILING_ADDR_MBIST_3_CTRLR                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_10_STS_SRAM_4K_1_DC_MARCH_Y_ALG_FAILING_ADDR_MBIST_3_CTRLR_MASK                   (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_10_STS_SRAM_4K_1_DC_MARCH_Y_ALG_FAILING_ADDR_MBIST_3_CTRLR_SHIFT                  (0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_10_STS_SRAM_4K_1_DC_COL_MARCH_ALG_FAILING_ADDR_MBIST_3_CTRLR                      (Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_10_STS_SRAM_4K_1_DC_COL_MARCH_ALG_FAILING_ADDR_MBIST_3_CTRLR_MASK                 (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_10_STS_SRAM_4K_1_DC_COL_MARCH_ALG_FAILING_ADDR_MBIST_3_CTRLR_SHIFT                (10)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_10_STS_SRAM_4K_1_DC_READ_DATA_ALG_FAILING_ADDR_MBIST_3_CTRLR                      (Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_10_STS_SRAM_4K_1_DC_READ_DATA_ALG_FAILING_ADDR_MBIST_3_CTRLR_MASK                 (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_10_STS_SRAM_4K_1_DC_READ_DATA_ALG_FAILING_ADDR_MBIST_3_CTRLR_SHIFT                (21)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_11                                                                                (GLOBAL_REG_BASE + 0x848)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_11_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_11_STS_SRAM_8K_DC_MARCH_Y_ALG_FAIL_MBIST_3_CTRLR                                  (Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_11_STS_SRAM_8K_DC_COL_MARCH_ALG_FAIL_MBIST_3_CTRLR                                (Bit1)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_11_STS_SRAM_8K_DC_READ_DATA_ALG_FAIL_MBIST_3_CTRLR                                (Bit2)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_11_STS_SRAM_8K_DC_MARCH_Y_ALG_FAILING_ADDR_MBIST_3_CTRLR                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_11_STS_SRAM_8K_DC_MARCH_Y_ALG_FAILING_ADDR_MBIST_3_CTRLR_MASK                     (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_11_STS_SRAM_8K_DC_MARCH_Y_ALG_FAILING_ADDR_MBIST_3_CTRLR_SHIFT                    (4)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_11_STS_SRAM_8K_DC_COL_MARCH_ALG_FAILING_ADDR_MBIST_3_CTRLR                        (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_11_STS_SRAM_8K_DC_COL_MARCH_ALG_FAILING_ADDR_MBIST_3_CTRLR_MASK                   (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_11_STS_SRAM_8K_DC_COL_MARCH_ALG_FAILING_ADDR_MBIST_3_CTRLR_SHIFT                  (16)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_12                                                                                (GLOBAL_REG_BASE + 0x84c)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_12_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_12_STS_SRAM_8K_DC_READ_DATA_ALG_FAILING_ADDR_MBIST_3_CTRLR                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_12_STS_SRAM_8K_DC_READ_DATA_ALG_FAILING_ADDR_MBIST_3_CTRLR_MASK                   (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_12_STS_SRAM_8K_DC_READ_DATA_ALG_FAILING_ADDR_MBIST_3_CTRLR_SHIFT                  (0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_12_STS_SRAM0_SHM_MARCH_Y_ALG_FAIL_MBIST_4_CTRLR                                   (Bit12)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_12_STS_SRAM0_SHM_COL_MARCH_ALG_FAIL_MBIST_4_CTRLR                                 (Bit13)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_12_STS_SRAM0_SHM_READ_DATA_ALG_FAIL_MBIST_4_CTRLR                                 (Bit14)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_12_STS_SRAM0_SHM_MARCH_Y_ALG_FAILING_ADDR_MBIST_4_CTRLR                           (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_12_STS_SRAM0_SHM_MARCH_Y_ALG_FAILING_ADDR_MBIST_4_CTRLR_MASK                      (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_12_STS_SRAM0_SHM_MARCH_Y_ALG_FAILING_ADDR_MBIST_4_CTRLR_SHIFT                     (16)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_13                                                                                (GLOBAL_REG_BASE + 0x850)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_13_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_13_STS_SRAM0_SHM_COL_MARCH_ALG_FAILING_ADDR_MBIST_4_CTRLR                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_13_STS_SRAM0_SHM_COL_MARCH_ALG_FAILING_ADDR_MBIST_4_CTRLR_MASK                    (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_13_STS_SRAM0_SHM_COL_MARCH_ALG_FAILING_ADDR_MBIST_4_CTRLR_SHIFT                   (0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_13_STS_SRAM0_SHM_READ_DATA_ALG_FAILING_ADDR_MBIST_4_CTRLR                         (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_13_STS_SRAM0_SHM_READ_DATA_ALG_FAILING_ADDR_MBIST_4_CTRLR_MASK                    (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_13_STS_SRAM0_SHM_READ_DATA_ALG_FAILING_ADDR_MBIST_4_CTRLR_SHIFT                   (12)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_13_STS_SRAM1_SHM_MARCH_Y_ALG_FAIL_MBIST_4_CTRLR                                   (Bit24)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_13_STS_SRAM1_SHM_COL_MARCH_ALG_FAIL_MBIST_4_CTRLR                                 (Bit25)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_13_STS_SRAM1_SHM_READ_DATA_ALG_FAIL_MBIST_4_CTRLR                                 (Bit26)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_14                                                                                (GLOBAL_REG_BASE + 0x854)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_14_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_14_STS_SRAM1_SHM_MARCH_Y_ALG_FAILING_ADDR_MBIST_4_CTRLR                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_14_STS_SRAM1_SHM_MARCH_Y_ALG_FAILING_ADDR_MBIST_4_CTRLR_MASK                      (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_14_STS_SRAM1_SHM_MARCH_Y_ALG_FAILING_ADDR_MBIST_4_CTRLR_SHIFT                     (0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_14_STS_SRAM1_SHM_COL_MARCH_ALG_FAILING_ADDR_MBIST_4_CTRLR                         (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_14_STS_SRAM1_SHM_COL_MARCH_ALG_FAILING_ADDR_MBIST_4_CTRLR_MASK                    (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_14_STS_SRAM1_SHM_COL_MARCH_ALG_FAILING_ADDR_MBIST_4_CTRLR_SHIFT                   (12)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_14_STS_SRAM1_SHM_READ_DATA_ALG_FAILING_ADDR_MBIST_4_CTRLR                         (Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_14_STS_SRAM1_SHM_READ_DATA_ALG_FAILING_ADDR_MBIST_4_CTRLR_MASK                    (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_14_STS_SRAM1_SHM_READ_DATA_ALG_FAILING_ADDR_MBIST_4_CTRLR_SHIFT                   (22)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_15                                                                                (GLOBAL_REG_BASE + 0x858)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_15_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_15_STS_SRAM2_SHM_MARCH_Y_ALG_FAIL_MBIST_4_CTRLR                                   (Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_15_STS_SRAM2_SHM_COL_MARCH_ALG_FAIL_MBIST_4_CTRLR                                 (Bit1)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_15_STS_SRAM2_SHM_READ_DATA_ALG_FAIL_MBIST_4_CTRLR                                 (Bit2)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_15_STS_SRAM2_SHM_MARCH_Y_ALG_FAILING_ADDR_MBIST_4_CTRLR                           (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_15_STS_SRAM2_SHM_MARCH_Y_ALG_FAILING_ADDR_MBIST_4_CTRLR_MASK                      (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_15_STS_SRAM2_SHM_MARCH_Y_ALG_FAILING_ADDR_MBIST_4_CTRLR_SHIFT                     (4)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_15_STS_SRAM2_SHM_COL_MARCH_ALG_FAILING_ADDR_MBIST_4_CTRLR                         (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_15_STS_SRAM2_SHM_COL_MARCH_ALG_FAILING_ADDR_MBIST_4_CTRLR_MASK                    (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_15_STS_SRAM2_SHM_COL_MARCH_ALG_FAILING_ADDR_MBIST_4_CTRLR_SHIFT                   (16)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_16                                                                                (GLOBAL_REG_BASE + 0x85c)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_16_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_16_STS_SRAM2_SHM_READ_DATA_ALG_FAILING_ADDR_MBIST_4_CTRLR                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_16_STS_SRAM2_SHM_READ_DATA_ALG_FAILING_ADDR_MBIST_4_CTRLR_MASK                    (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_16_STS_SRAM2_SHM_READ_DATA_ALG_FAILING_ADDR_MBIST_4_CTRLR_SHIFT                   (0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_16_STS_SRAM4_SHM_MARCH_Y_ALG_FAIL_MBIST_5_CTRLR                                   (Bit12)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_16_STS_SRAM4_SHM_COL_MARCH_ALG_FAIL_MBIST_5_CTRLR                                 (Bit13)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_16_STS_SRAM4_SHM_READ_DATA_ALG_FAIL_MBIST_5_CTRLR                                 (Bit14)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_16_STS_SRAM4_SHM_MARCH_Y_ALG_FAILING_ADDR_MBIST_5_CTRLR                           (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_16_STS_SRAM4_SHM_MARCH_Y_ALG_FAILING_ADDR_MBIST_5_CTRLR_MASK                      (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_16_STS_SRAM4_SHM_MARCH_Y_ALG_FAILING_ADDR_MBIST_5_CTRLR_SHIFT                     (16)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_17                                                                                (GLOBAL_REG_BASE + 0x860)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_17_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_17_STS_SRAM4_SHM_COL_MARCH_ALG_FAILING_ADDR_MBIST_5_CTRLR                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_17_STS_SRAM4_SHM_COL_MARCH_ALG_FAILING_ADDR_MBIST_5_CTRLR_MASK                    (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_17_STS_SRAM4_SHM_COL_MARCH_ALG_FAILING_ADDR_MBIST_5_CTRLR_SHIFT                   (0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_17_STS_SRAM4_SHM_READ_DATA_ALG_FAILING_ADDR_MBIST_5_CTRLR                         (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_17_STS_SRAM4_SHM_READ_DATA_ALG_FAILING_ADDR_MBIST_5_CTRLR_MASK                    (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_17_STS_SRAM4_SHM_READ_DATA_ALG_FAILING_ADDR_MBIST_5_CTRLR_SHIFT                   (12)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_17_STS_SRAM_ECC_FW_MARCH_Y_ALG_FAIL_MBIST_7_CTRLR                                 (Bit24)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_17_STS_SRAM_ECC_FW_COL_MARCH_ALG_FAIL_MBIST_7_CTRLR                               (Bit25)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_18                                                                                (GLOBAL_REG_BASE + 0x864)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_18_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_18_STS_SRAM_ECC_FW_MARCH_Y_ALG_FAILING_ADDR_MBIST_7_CTRLR                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_18_STS_SRAM_ECC_FW_MARCH_Y_ALG_FAILING_ADDR_MBIST_7_CTRLR_MASK                    (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_18_STS_SRAM_ECC_FW_MARCH_Y_ALG_FAILING_ADDR_MBIST_7_CTRLR_SHIFT                   (0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_18_STS_SRAM_ECC_FW_COL_MARCH_ALG_FAILING_ADDR_MBIST_7_CTRLR                       (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_18_STS_SRAM_ECC_FW_COL_MARCH_ALG_FAILING_ADDR_MBIST_7_CTRLR_MASK                  (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_18_STS_SRAM_ECC_FW_COL_MARCH_ALG_FAILING_ADDR_MBIST_7_CTRLR_SHIFT                 (12)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_19                                                                                (GLOBAL_REG_BASE + 0x868)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_19_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_19_STS_SRAM3_SHM_MARCH_Y_ALG_FAIL_MBIST_6_CTRLR                                   (Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_19_STS_SRAM3_SHM_COL_MARCH_ALG_FAIL_MBIST_6_CTRLR                                 (Bit1)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_19_STS_SRAM3_SHM_READ_DATA_ALG_FAIL_MBIST_6_CTRLR                                 (Bit2)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_19_STS_SRAM3_SHM_MARCH_Y_ALG_FAILING_ADDR_MBIST_6_CTRLR                           (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_19_STS_SRAM3_SHM_MARCH_Y_ALG_FAILING_ADDR_MBIST_6_CTRLR_MASK                      (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_19_STS_SRAM3_SHM_MARCH_Y_ALG_FAILING_ADDR_MBIST_6_CTRLR_SHIFT                     (4)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_19_STS_SRAM3_SHM_COL_MARCH_ALG_FAILING_ADDR_MBIST_6_CTRLR                         (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_19_STS_SRAM3_SHM_COL_MARCH_ALG_FAILING_ADDR_MBIST_6_CTRLR_MASK                    (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_19_STS_SRAM3_SHM_COL_MARCH_ALG_FAILING_ADDR_MBIST_6_CTRLR_SHIFT                   (16)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_20                                                                                (GLOBAL_REG_BASE + 0x86c)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_20_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_20_STS_SRAM3_SHM_READ_DATA_ALG_FAILING_ADDR_MBIST_6_CTRLR                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_20_STS_SRAM3_SHM_READ_DATA_ALG_FAILING_ADDR_MBIST_6_CTRLR_MASK                    (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_20_STS_SRAM3_SHM_READ_DATA_ALG_FAILING_ADDR_MBIST_6_CTRLR_SHIFT                   (0)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_21                                                                                (GLOBAL_REG_BASE + 0x870)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_21_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_21_STS_RF_HWACC_A_MARCH_Y_ALG_FAIL_MBIST_2_CTRLR                                  (Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_21_STS_RF_HWACC_A_COL_MARCH_ALG_FAIL_MBIST_2_CTRLR                                (Bit1)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_21_STS_RF_HWACC_A_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_21_STS_RF_HWACC_A_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR_MASK                     (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_21_STS_RF_HWACC_A_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR_SHIFT                    (4)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_21_STS_RF_HWACC_A_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR                        (Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_21_STS_RF_HWACC_A_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR_MASK                   (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_21_STS_RF_HWACC_A_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR_SHIFT                  (13)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_22                                                                                (GLOBAL_REG_BASE + 0x874)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_22_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_22_STS_RF_HWACC_B_MARCH_Y_ALG_FAIL_MBIST_2_CTRLR                                  (Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_22_STS_RF_HWACC_B_COL_MARCH_ALG_FAIL_MBIST_2_CTRLR                                (Bit1)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_22_STS_RF_HWACC_B_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_22_STS_RF_HWACC_B_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR_MASK                     (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_22_STS_RF_HWACC_B_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR_SHIFT                    (4)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_22_STS_RF_HWACC_B_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR                        (Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_22_STS_RF_HWACC_B_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR_MASK                   (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_22_STS_RF_HWACC_B_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR_SHIFT                  (13)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_23                                                                                (GLOBAL_REG_BASE + 0x878)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_23_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_23_STS_RF_HWACC_C_MARCH_Y_ALG_FAIL_MBIST_2_CTRLR                                  (Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_23_STS_RF_HWACC_C_COL_MARCH_ALG_FAIL_MBIST_2_CTRLR                                (Bit1)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_23_STS_RF_HWACC_C_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_23_STS_RF_HWACC_C_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR_MASK                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_23_STS_RF_HWACC_C_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR_SHIFT                    (4)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_23_STS_RF_HWACC_C_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR                        (Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_23_STS_RF_HWACC_C_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR_MASK                   (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_23_STS_RF_HWACC_C_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR_SHIFT                  (13)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_24                                                                                (GLOBAL_REG_BASE + 0x87c)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_24_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_24_STS_RF_HWACC_D_MARCH_Y_ALG_FAIL_MBIST_2_CTRLR                                  (Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_24_STS_RF_HWACC_D_COL_MARCH_ALG_FAIL_MBIST_2_CTRLR                                (Bit1)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_24_STS_RF_HWACC_D_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_24_STS_RF_HWACC_D_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR_MASK                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_24_STS_RF_HWACC_D_MARCH_Y_ALG_FAILING_ADDR_MBIST_2_CTRLR_SHIFT                    (4)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_24_STS_RF_HWACC_D_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR                        (Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_24_STS_RF_HWACC_D_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR_MASK                   (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_24_STS_RF_HWACC_D_COL_MARCH_ALG_FAILING_ADDR_MBIST_2_CTRLR_SHIFT                  (13)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_25                                                                                (GLOBAL_REG_BASE + 0x880)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_25_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_25_STS_RF_ECC_A_MARCH_Y_ALG_FAIL_MBIST_7_CTRLR                                    (Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_25_STS_RF_ECC_A_COL_MARCH_ALG_FAIL_MBIST_7_CTRLR                                  (Bit1)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_25_STS_RF_ECC_A_MARCH_Y_ALG_FAILING_ADDR_MBIST_7_CTRLR                            (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_25_STS_RF_ECC_A_MARCH_Y_ALG_FAILING_ADDR_MBIST_7_CTRLR_MASK                       (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_25_STS_RF_ECC_A_MARCH_Y_ALG_FAILING_ADDR_MBIST_7_CTRLR_SHIFT                      (4)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_25_STS_RF_ECC_A_COL_MARCH_ALG_FAILING_ADDR_MBIST_7_CTRLR                          (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_25_STS_RF_ECC_A_COL_MARCH_ALG_FAILING_ADDR_MBIST_7_CTRLR_MASK                     (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_25_STS_RF_ECC_A_COL_MARCH_ALG_FAILING_ADDR_MBIST_7_CTRLR_SHIFT                    (12)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_26                                                                                (GLOBAL_REG_BASE + 0x884)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_26_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_26_STS_RF_ECC_B_MARCH_Y_ALG_FAIL_MBIST_7_CTRLR                                    (Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_26_STS_RF_ECC_B_COL_MARCH_ALG_FAIL_MBIST_7_CTRLR                                  (Bit1)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_26_STS_RF_ECC_B_MARCH_Y_ALG_FAILING_ADDR_MBIST_7_CTRLR                            (Bit4+Bit5+Bit6+Bit7+Bit8)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_26_STS_RF_ECC_B_MARCH_Y_ALG_FAILING_ADDR_MBIST_7_CTRLR_MASK                       (Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_26_STS_RF_ECC_B_MARCH_Y_ALG_FAILING_ADDR_MBIST_7_CTRLR_SHIFT                      (4)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_26_STS_RF_ECC_B_COL_MARCH_ALG_FAILING_ADDR_MBIST_7_CTRLR                          (Bit12+Bit13+Bit14+Bit15+Bit16)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_26_STS_RF_ECC_B_COL_MARCH_ALG_FAILING_ADDR_MBIST_7_CTRLR_MASK                     (Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_26_STS_RF_ECC_B_COL_MARCH_ALG_FAILING_ADDR_MBIST_7_CTRLR_SHIFT                    (12)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_27                                                                                (GLOBAL_REG_BASE + 0x888)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_27_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_27_STS_RF_ECC_C_MARCH_Y_ALG_FAIL_MBIST_7_CTRLR                                    (Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_27_STS_RF_ECC_C_COL_MARCH_ALG_FAIL_MBIST_7_CTRLR                                  (Bit1)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_27_STS_RF_ECC_C_MARCH_Y_ALG_FAILING_ADDR_MBIST_7_CTRLR                            (Bit4+Bit5+Bit6+Bit7+Bit8)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_27_STS_RF_ECC_C_MARCH_Y_ALG_FAILING_ADDR_MBIST_7_CTRLR_MASK                       (Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_27_STS_RF_ECC_C_MARCH_Y_ALG_FAILING_ADDR_MBIST_7_CTRLR_SHIFT                      (4)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_27_STS_RF_ECC_C_COL_MARCH_ALG_FAILING_ADDR_MBIST_7_CTRLR                          (Bit12+Bit13+Bit14+Bit15+Bit16)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_27_STS_RF_ECC_C_COL_MARCH_ALG_FAILING_ADDR_MBIST_7_CTRLR_MASK                     (Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_27_STS_RF_ECC_C_COL_MARCH_ALG_FAILING_ADDR_MBIST_7_CTRLR_SHIFT                    (12)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_28                                                                                (GLOBAL_REG_BASE + 0x88c)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_28_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_28_STS_RF_ECC_D_MARCH_Y_ALG_FAIL_MBIST_7_CTRLR                                    (Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_28_STS_RF_ECC_D_COL_MARCH_ALG_FAIL_MBIST_7_CTRLR                                  (Bit1)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_28_STS_RF_ECC_D_MARCH_Y_ALG_FAILING_ADDR_MBIST_7_CTRLR                            (Bit4+Bit5+Bit6+Bit7+Bit8)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_28_STS_RF_ECC_D_MARCH_Y_ALG_FAILING_ADDR_MBIST_7_CTRLR_MASK                       (Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_28_STS_RF_ECC_D_MARCH_Y_ALG_FAILING_ADDR_MBIST_7_CTRLR_SHIFT                      (4)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_28_STS_RF_ECC_D_COL_MARCH_ALG_FAILING_ADDR_MBIST_7_CTRLR                          (Bit12+Bit13+Bit14+Bit15+Bit16)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_28_STS_RF_ECC_D_COL_MARCH_ALG_FAILING_ADDR_MBIST_7_CTRLR_MASK                     (Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_28_STS_RF_ECC_D_COL_MARCH_ALG_FAILING_ADDR_MBIST_7_CTRLR_SHIFT                    (12)


#define GLOBAL_REG_STS_MBIST_CONTROLLERS_29                                                                                (GLOBAL_REG_BASE + 0x890)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_29_DEFAULT                                                                        0x0
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_29_STS_RF_PLLTRIG_MARCH_Y_ALG_FAIL_MBIST_6_CTRLR                                  (Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_29_STS_RF_PLLTRIG_COL_MARCH_ALG_FAIL_MBIST_6_CTRLR                                (Bit1)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_29_STS_RF_PLLTRIG_READ_DATA_ALG_FAIL_MBIST_6_CTRLR                                (Bit2)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_29_STS_RF_PLLTRIG_MARCH_Y_ALG_FAILING_ADDR_MBIST_6_CTRLR                          (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_29_STS_RF_PLLTRIG_MARCH_Y_ALG_FAILING_ADDR_MBIST_6_CTRLR_MASK                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_29_STS_RF_PLLTRIG_MARCH_Y_ALG_FAILING_ADDR_MBIST_6_CTRLR_SHIFT                    (4)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_29_STS_RF_PLLTRIG_COL_MARCH_ALG_FAILING_ADDR_MBIST_6_CTRLR                        (Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_29_STS_RF_PLLTRIG_COL_MARCH_ALG_FAILING_ADDR_MBIST_6_CTRLR_MASK                   (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_29_STS_RF_PLLTRIG_COL_MARCH_ALG_FAILING_ADDR_MBIST_6_CTRLR_SHIFT                  (12)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_29_STS_RF_PLLTRIG_READ_DATA_ALG_FAILING_ADDR_MBIST_6_CTRLR                        (Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_29_STS_RF_PLLTRIG_READ_DATA_ALG_FAILING_ADDR_MBIST_6_CTRLR_MASK                   (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MBIST_CONTROLLERS_29_STS_RF_PLLTRIG_READ_DATA_ALG_FAILING_ADDR_MBIST_6_CTRLR_SHIFT                  (20)


#define GLOBAL_REG_CTL_MEM_DFT_OBSRV_CTRL                                                                                  (GLOBAL_REG_BASE + 0x900)
#define GLOBAL_REG_CTL_MEM_DFT_OBSRV_CTRL_DEFAULT                                                                          0x0
#define GLOBAL_REG_CTL_MEM_DFT_OBSRV_CTRL_CTL_MEM_DFT_OBSRV_CTRL_SEL                                                       (Bit0+Bit1+Bit2+Bit3+Bit4)
#define GLOBAL_REG_CTL_MEM_DFT_OBSRV_CTRL_CTL_MEM_DFT_OBSRV_CTRL_SEL_MASK                                                  (Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_CTL_MEM_DFT_OBSRV_CTRL_CTL_MEM_DFT_OBSRV_CTRL_SEL_SHIFT                                                 (0)


#define GLOBAL_REG_STS_MEM_DFT_OBSRV_CTRL                                                                                  (GLOBAL_REG_BASE + 0x904)
#define GLOBAL_REG_STS_MEM_DFT_OBSRV_CTRL_DEFAULT                                                                          0x0
#define GLOBAL_REG_STS_MEM_DFT_OBSRV_CTRL_STS_MEM_DFT_OBSRV_CTRL                                                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define GLOBAL_REG_STS_MEM_DFT_OBSRV_CTRL_STS_MEM_DFT_OBSRV_CTRL_MASK                                                      (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_STS_MEM_DFT_OBSRV_CTRL_STS_MEM_DFT_OBSRV_CTRL_SHIFT                                                     (0)


#define GLOBAL_REG_AHB_CTRL_1                                                                                              (GLOBAL_REG_BASE + 0x980)
#define GLOBAL_REG_AHB_CTRL_1_DEFAULT                                                                                      0x1121
#define GLOBAL_REG_AHB_CTRL_1_CTL_ICM_D2_DATA_CODE_RAM_PRIORITY                                                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define GLOBAL_REG_AHB_CTRL_1_CTL_ICM_D2_DATA_CODE_RAM_PRIORITY_MASK                                                       (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_AHB_CTRL_1_CTL_ICM_D2_DATA_CODE_RAM_PRIORITY_SHIFT                                                      (0)
#define GLOBAL_REG_AHB_CTRL_1_CTL_ICM_D2_ICACHE_PRIORITY                                                                   (Bit8+Bit9)
#define GLOBAL_REG_AHB_CTRL_1_CTL_ICM_D2_ICACHE_PRIORITY_MASK                                                              (Bit1+Bit0)
#define GLOBAL_REG_AHB_CTRL_1_CTL_ICM_D2_ICACHE_PRIORITY_SHIFT                                                             (8)
#define GLOBAL_REG_AHB_CTRL_1_CTL_ICM_D2_BOOT_ROM_PRIORITY                                                                 (Bit12+Bit13)
#define GLOBAL_REG_AHB_CTRL_1_CTL_ICM_D2_BOOT_ROM_PRIORITY_MASK                                                            (Bit1+Bit0)
#define GLOBAL_REG_AHB_CTRL_1_CTL_ICM_D2_BOOT_ROM_PRIORITY_SHIFT                                                           (12)
#define GLOBAL_REG_AHB_CTRL_1_CTL_AHB_D1_PAUSE                                                                             (Bit16)
#define GLOBAL_REG_AHB_CTRL_1_CTL_AHB_D2_M2_PAUSE                                                                          (Bit20)


#define GLOBAL_REG_AHB_CTRL_STATUS                                                                                         (GLOBAL_REG_BASE + 0x984)
#define GLOBAL_REG_AHB_CTRL_STATUS_DEFAULT                                                                                 0x0
#define GLOBAL_REG_AHB_CTRL_STATUS_STS_AHB_D0_WT_MASK                                                                      (Bit0+Bit1+Bit2+Bit3)
#define GLOBAL_REG_AHB_CTRL_STATUS_STS_AHB_D0_WT_MASK_MASK                                                                 (Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_AHB_CTRL_STATUS_STS_AHB_D0_WT_MASK_SHIFT                                                                (0)
#define GLOBAL_REG_AHB_CTRL_STATUS_STS_AHB_D0_WT_APS                                                                       (Bit4)


#define GLOBAL_REG_INTR_GPIO_0_STATUS                                                                                      (GLOBAL_REG_BASE + 0xa00)
#define GLOBAL_REG_INTR_GPIO_0_STATUS_DEFAULT                                                                              0x0
#define GLOBAL_REG_INTR_GPIO_0_STATUS_IRQ                                                                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_INTR_GPIO_0_STATUS_IRQ_MASK                                                                             (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_0_STATUS_IRQ_SHIFT                                                                            (0)


#define GLOBAL_REG_INTR_GPIO_0_MASK_STATUS                                                                                 (GLOBAL_REG_BASE + 0xa04)
#define GLOBAL_REG_INTR_GPIO_0_MASK_STATUS_DEFAULT                                                                         0x0
#define GLOBAL_REG_INTR_GPIO_0_MASK_STATUS_IRQ                                                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_INTR_GPIO_0_MASK_STATUS_IRQ_MASK                                                                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_0_MASK_STATUS_IRQ_SHIFT                                                                       (0)


#define GLOBAL_REG_INTR_GPIO_0_CLEAR                                                                                       (GLOBAL_REG_BASE + 0xa08)
#define GLOBAL_REG_INTR_GPIO_0_CLEAR_DEFAULT                                                                               0x0
#define GLOBAL_REG_INTR_GPIO_0_CLEAR_IRQ                                                                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_INTR_GPIO_0_CLEAR_IRQ_MASK                                                                              (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_0_CLEAR_IRQ_SHIFT                                                                             (0)


#define GLOBAL_REG_INTR_GPIO_0_SET                                                                                         (GLOBAL_REG_BASE + 0xa0c)
#define GLOBAL_REG_INTR_GPIO_0_SET_DEFAULT                                                                                 0x0
#define GLOBAL_REG_INTR_GPIO_0_SET_IRQ                                                                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_INTR_GPIO_0_SET_IRQ_MASK                                                                                (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_0_SET_IRQ_SHIFT                                                                               (0)


#define GLOBAL_REG_INTR_GPIO_0_MASK_SET                                                                                    (GLOBAL_REG_BASE + 0xa10)
#define GLOBAL_REG_INTR_GPIO_0_MASK_SET_DEFAULT                                                                            0x0
#define GLOBAL_REG_INTR_GPIO_0_MASK_SET_IRQ                                                                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_INTR_GPIO_0_MASK_SET_IRQ_MASK                                                                           (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_0_MASK_SET_IRQ_SHIFT                                                                          (0)


#define GLOBAL_REG_INTR_GPIO_0_MASK_CLEAR                                                                                  (GLOBAL_REG_BASE + 0xa14)
#define GLOBAL_REG_INTR_GPIO_0_MASK_CLEAR_DEFAULT                                                                          0x0
#define GLOBAL_REG_INTR_GPIO_0_MASK_CLEAR_IRQ                                                                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_INTR_GPIO_0_MASK_CLEAR_IRQ_MASK                                                                         (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_0_MASK_CLEAR_IRQ_SHIFT                                                                        (0)


#define GLOBAL_REG_INTR_GPIO_0_POLARITY                                                                                    (GLOBAL_REG_BASE + 0xa18)
#define GLOBAL_REG_INTR_GPIO_0_POLARITY_DEFAULT                                                                            0x0
#define GLOBAL_REG_INTR_GPIO_0_POLARITY_IRQ                                                                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_INTR_GPIO_0_POLARITY_IRQ_MASK                                                                           (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_0_POLARITY_IRQ_SHIFT                                                                          (0)


#define GLOBAL_REG_INTR_GPIO_1_STATUS                                                                                      (GLOBAL_REG_BASE + 0xa20)
#define GLOBAL_REG_INTR_GPIO_1_STATUS_DEFAULT                                                                              0x0
#define GLOBAL_REG_INTR_GPIO_1_STATUS_IRQ                                                                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_INTR_GPIO_1_STATUS_IRQ_MASK                                                                             (Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_1_STATUS_IRQ_SHIFT                                                                            (0)


#define GLOBAL_REG_INTR_GPIO_1_MASK_STATUS                                                                                 (GLOBAL_REG_BASE + 0xa24)
#define GLOBAL_REG_INTR_GPIO_1_MASK_STATUS_DEFAULT                                                                         0x0
#define GLOBAL_REG_INTR_GPIO_1_MASK_STATUS_IRQ                                                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_INTR_GPIO_1_MASK_STATUS_IRQ_MASK                                                                        (Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_1_MASK_STATUS_IRQ_SHIFT                                                                       (0)


#define GLOBAL_REG_INTR_GPIO_1_CLEAR                                                                                       (GLOBAL_REG_BASE + 0xa28)
#define GLOBAL_REG_INTR_GPIO_1_CLEAR_DEFAULT                                                                               0x0
#define GLOBAL_REG_INTR_GPIO_1_CLEAR_IRQ                                                                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_INTR_GPIO_1_CLEAR_IRQ_MASK                                                                              (Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_1_CLEAR_IRQ_SHIFT                                                                             (0)


#define GLOBAL_REG_INTR_GPIO_1_SET                                                                                         (GLOBAL_REG_BASE + 0xa2c)
#define GLOBAL_REG_INTR_GPIO_1_SET_DEFAULT                                                                                 0x0
#define GLOBAL_REG_INTR_GPIO_1_SET_IRQ                                                                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_INTR_GPIO_1_SET_IRQ_MASK                                                                                (Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_1_SET_IRQ_SHIFT                                                                               (0)


#define GLOBAL_REG_INTR_GPIO_1_MASK_SET                                                                                    (GLOBAL_REG_BASE + 0xa30)
#define GLOBAL_REG_INTR_GPIO_1_MASK_SET_DEFAULT                                                                            0x0
#define GLOBAL_REG_INTR_GPIO_1_MASK_SET_IRQ                                                                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_INTR_GPIO_1_MASK_SET_IRQ_MASK                                                                           (Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_1_MASK_SET_IRQ_SHIFT                                                                          (0)


#define GLOBAL_REG_INTR_GPIO_1_MASK_CLEAR                                                                                  (GLOBAL_REG_BASE + 0xa34)
#define GLOBAL_REG_INTR_GPIO_1_MASK_CLEAR_DEFAULT                                                                          0x0
#define GLOBAL_REG_INTR_GPIO_1_MASK_CLEAR_IRQ                                                                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_INTR_GPIO_1_MASK_CLEAR_IRQ_MASK                                                                         (Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_1_MASK_CLEAR_IRQ_SHIFT                                                                        (0)


#define GLOBAL_REG_INTR_GPIO_1_POLARITY                                                                                    (GLOBAL_REG_BASE + 0xa38)
#define GLOBAL_REG_INTR_GPIO_1_POLARITY_DEFAULT                                                                            0x0
#define GLOBAL_REG_INTR_GPIO_1_POLARITY_IRQ                                                                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_INTR_GPIO_1_POLARITY_IRQ_MASK                                                                           (Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_1_POLARITY_IRQ_SHIFT                                                                          (0)


#define GLOBAL_REG_INTR_GPIO_2_STATUS                                                                                      (GLOBAL_REG_BASE + 0xa40)
#define GLOBAL_REG_INTR_GPIO_2_STATUS_DEFAULT                                                                              0x0
#define GLOBAL_REG_INTR_GPIO_2_STATUS_IRQ                                                                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_INTR_GPIO_2_STATUS_IRQ_MASK                                                                             (Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_2_STATUS_IRQ_SHIFT                                                                            (0)


#define GLOBAL_REG_INTR_GPIO_2_MASK_STATUS                                                                                 (GLOBAL_REG_BASE + 0xa44)
#define GLOBAL_REG_INTR_GPIO_2_MASK_STATUS_DEFAULT                                                                         0x0
#define GLOBAL_REG_INTR_GPIO_2_MASK_STATUS_IRQ                                                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_INTR_GPIO_2_MASK_STATUS_IRQ_MASK                                                                        (Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_2_MASK_STATUS_IRQ_SHIFT                                                                       (0)


#define GLOBAL_REG_INTR_GPIO_2_CLEAR                                                                                       (GLOBAL_REG_BASE + 0xa48)
#define GLOBAL_REG_INTR_GPIO_2_CLEAR_DEFAULT                                                                               0x0
#define GLOBAL_REG_INTR_GPIO_2_CLEAR_IRQ                                                                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_INTR_GPIO_2_CLEAR_IRQ_MASK                                                                              (Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_2_CLEAR_IRQ_SHIFT                                                                             (0)


#define GLOBAL_REG_INTR_GPIO_2_SET                                                                                         (GLOBAL_REG_BASE + 0xa4c)
#define GLOBAL_REG_INTR_GPIO_2_SET_DEFAULT                                                                                 0x0
#define GLOBAL_REG_INTR_GPIO_2_SET_IRQ                                                                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_INTR_GPIO_2_SET_IRQ_MASK                                                                                (Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_2_SET_IRQ_SHIFT                                                                               (0)


#define GLOBAL_REG_INTR_GPIO_2_MASK_SET                                                                                    (GLOBAL_REG_BASE + 0xa50)
#define GLOBAL_REG_INTR_GPIO_2_MASK_SET_DEFAULT                                                                            0x0
#define GLOBAL_REG_INTR_GPIO_2_MASK_SET_IRQ                                                                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_INTR_GPIO_2_MASK_SET_IRQ_MASK                                                                           (Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_2_MASK_SET_IRQ_SHIFT                                                                          (0)


#define GLOBAL_REG_INTR_GPIO_2_MASK_CLEAR                                                                                  (GLOBAL_REG_BASE + 0xa54)
#define GLOBAL_REG_INTR_GPIO_2_MASK_CLEAR_DEFAULT                                                                          0x0
#define GLOBAL_REG_INTR_GPIO_2_MASK_CLEAR_IRQ                                                                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_INTR_GPIO_2_MASK_CLEAR_IRQ_MASK                                                                         (Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_2_MASK_CLEAR_IRQ_SHIFT                                                                        (0)


#define GLOBAL_REG_INTR_GPIO_2_POLARITY                                                                                    (GLOBAL_REG_BASE + 0xa58)
#define GLOBAL_REG_INTR_GPIO_2_POLARITY_DEFAULT                                                                            0x0
#define GLOBAL_REG_INTR_GPIO_2_POLARITY_IRQ                                                                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define GLOBAL_REG_INTR_GPIO_2_POLARITY_IRQ_MASK                                                                           (Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_2_POLARITY_IRQ_SHIFT                                                                          (0)


#define GLOBAL_REG_INTR_GPIO_3_STATUS                                                                                      (GLOBAL_REG_BASE + 0xa60)
#define GLOBAL_REG_INTR_GPIO_3_STATUS_DEFAULT                                                                              0x0
#define GLOBAL_REG_INTR_GPIO_3_STATUS_IRQ                                                                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_INTR_GPIO_3_STATUS_IRQ_MASK                                                                             (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_3_STATUS_IRQ_SHIFT                                                                            (0)


#define GLOBAL_REG_INTR_GPIO_3_MASK_STATUS                                                                                 (GLOBAL_REG_BASE + 0xa64)
#define GLOBAL_REG_INTR_GPIO_3_MASK_STATUS_DEFAULT                                                                         0x0
#define GLOBAL_REG_INTR_GPIO_3_MASK_STATUS_IRQ                                                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_INTR_GPIO_3_MASK_STATUS_IRQ_MASK                                                                        (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_3_MASK_STATUS_IRQ_SHIFT                                                                       (0)


#define GLOBAL_REG_INTR_GPIO_3_CLEAR                                                                                       (GLOBAL_REG_BASE + 0xa68)
#define GLOBAL_REG_INTR_GPIO_3_CLEAR_DEFAULT                                                                               0x0
#define GLOBAL_REG_INTR_GPIO_3_CLEAR_IRQ                                                                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_INTR_GPIO_3_CLEAR_IRQ_MASK                                                                              (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_3_CLEAR_IRQ_SHIFT                                                                             (0)


#define GLOBAL_REG_INTR_GPIO_3_SET                                                                                         (GLOBAL_REG_BASE + 0xa6c)
#define GLOBAL_REG_INTR_GPIO_3_SET_DEFAULT                                                                                 0x0
#define GLOBAL_REG_INTR_GPIO_3_SET_IRQ                                                                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_INTR_GPIO_3_SET_IRQ_MASK                                                                                (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_3_SET_IRQ_SHIFT                                                                               (0)


#define GLOBAL_REG_INTR_GPIO_3_MASK_SET                                                                                    (GLOBAL_REG_BASE + 0xa70)
#define GLOBAL_REG_INTR_GPIO_3_MASK_SET_DEFAULT                                                                            0x0
#define GLOBAL_REG_INTR_GPIO_3_MASK_SET_IRQ                                                                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_INTR_GPIO_3_MASK_SET_IRQ_MASK                                                                           (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_3_MASK_SET_IRQ_SHIFT                                                                          (0)


#define GLOBAL_REG_INTR_GPIO_3_MASK_CLEAR                                                                                  (GLOBAL_REG_BASE + 0xa74)
#define GLOBAL_REG_INTR_GPIO_3_MASK_CLEAR_DEFAULT                                                                          0x0
#define GLOBAL_REG_INTR_GPIO_3_MASK_CLEAR_IRQ                                                                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_INTR_GPIO_3_MASK_CLEAR_IRQ_MASK                                                                         (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_3_MASK_CLEAR_IRQ_SHIFT                                                                        (0)


#define GLOBAL_REG_INTR_GPIO_3_POLARITY                                                                                    (GLOBAL_REG_BASE + 0xa78)
#define GLOBAL_REG_INTR_GPIO_3_POLARITY_DEFAULT                                                                            0x0
#define GLOBAL_REG_INTR_GPIO_3_POLARITY_IRQ                                                                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define GLOBAL_REG_INTR_GPIO_3_POLARITY_IRQ_MASK                                                                           (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_3_POLARITY_IRQ_SHIFT                                                                          (0)


#define GLOBAL_REG_INTR_GPIO_4_STATUS                                                                                      (GLOBAL_REG_BASE + 0xa80)
#define GLOBAL_REG_INTR_GPIO_4_STATUS_DEFAULT                                                                              0x0
#define GLOBAL_REG_INTR_GPIO_4_STATUS_IRQ                                                                                  (Bit0+Bit1+Bit2+Bit3)
#define GLOBAL_REG_INTR_GPIO_4_STATUS_IRQ_MASK                                                                             (Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_4_STATUS_IRQ_SHIFT                                                                            (0)


#define GLOBAL_REG_INTR_GPIO_4_MASK_STATUS                                                                                 (GLOBAL_REG_BASE + 0xa84)
#define GLOBAL_REG_INTR_GPIO_4_MASK_STATUS_DEFAULT                                                                         0x0
#define GLOBAL_REG_INTR_GPIO_4_MASK_STATUS_IRQ                                                                             (Bit0+Bit1+Bit2+Bit3)
#define GLOBAL_REG_INTR_GPIO_4_MASK_STATUS_IRQ_MASK                                                                        (Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_4_MASK_STATUS_IRQ_SHIFT                                                                       (0)


#define GLOBAL_REG_INTR_GPIO_4_CLEAR                                                                                       (GLOBAL_REG_BASE + 0xa88)
#define GLOBAL_REG_INTR_GPIO_4_CLEAR_DEFAULT                                                                               0x0
#define GLOBAL_REG_INTR_GPIO_4_CLEAR_IRQ                                                                                   (Bit0+Bit1+Bit2+Bit3)
#define GLOBAL_REG_INTR_GPIO_4_CLEAR_IRQ_MASK                                                                              (Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_4_CLEAR_IRQ_SHIFT                                                                             (0)


#define GLOBAL_REG_INTR_GPIO_4_SET                                                                                         (GLOBAL_REG_BASE + 0xa8c)
#define GLOBAL_REG_INTR_GPIO_4_SET_DEFAULT                                                                                 0x0
#define GLOBAL_REG_INTR_GPIO_4_SET_IRQ                                                                                     (Bit0+Bit1+Bit2+Bit3)
#define GLOBAL_REG_INTR_GPIO_4_SET_IRQ_MASK                                                                                (Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_4_SET_IRQ_SHIFT                                                                               (0)


#define GLOBAL_REG_INTR_GPIO_4_MASK_SET                                                                                    (GLOBAL_REG_BASE + 0xa90)
#define GLOBAL_REG_INTR_GPIO_4_MASK_SET_DEFAULT                                                                            0x0
#define GLOBAL_REG_INTR_GPIO_4_MASK_SET_IRQ                                                                                (Bit0+Bit1+Bit2+Bit3)
#define GLOBAL_REG_INTR_GPIO_4_MASK_SET_IRQ_MASK                                                                           (Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_4_MASK_SET_IRQ_SHIFT                                                                          (0)


#define GLOBAL_REG_INTR_GPIO_4_MASK_CLEAR                                                                                  (GLOBAL_REG_BASE + 0xa94)
#define GLOBAL_REG_INTR_GPIO_4_MASK_CLEAR_DEFAULT                                                                          0x0
#define GLOBAL_REG_INTR_GPIO_4_MASK_CLEAR_IRQ                                                                              (Bit0+Bit1+Bit2+Bit3)
#define GLOBAL_REG_INTR_GPIO_4_MASK_CLEAR_IRQ_MASK                                                                         (Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_4_MASK_CLEAR_IRQ_SHIFT                                                                        (0)


#define GLOBAL_REG_INTR_GPIO_4_POLARITY                                                                                    (GLOBAL_REG_BASE + 0xa98)
#define GLOBAL_REG_INTR_GPIO_4_POLARITY_DEFAULT                                                                            0x0
#define GLOBAL_REG_INTR_GPIO_4_POLARITY_IRQ                                                                                (Bit0+Bit1+Bit2+Bit3)
#define GLOBAL_REG_INTR_GPIO_4_POLARITY_IRQ_MASK                                                                           (Bit3+Bit2+Bit1+Bit0)
#define GLOBAL_REG_INTR_GPIO_4_POLARITY_IRQ_SHIFT                                                                          (0)


#define GLOBAL_REG_GPIO_0_4_INTR_RESET                                                                                     (GLOBAL_REG_BASE + 0xaa0)
#define GLOBAL_REG_GPIO_0_4_INTR_RESET_DEFAULT                                                                             0x0
#define GLOBAL_REG_GPIO_0_4_INTR_RESET_CTL_GPIO_0_INTR_RESET                                                               (Bit0)
#define GLOBAL_REG_GPIO_0_4_INTR_RESET_CTL_GPIO_1_INTR_RESET                                                               (Bit1)
#define GLOBAL_REG_GPIO_0_4_INTR_RESET_CTL_GPIO_2_INTR_RESET                                                               (Bit2)
#define GLOBAL_REG_GPIO_0_4_INTR_RESET_CTL_GPIO_3_INTR_RESET                                                               (Bit3)
#define GLOBAL_REG_GPIO_0_4_INTR_RESET_CTL_GPIO_4_INTR_RESET                                                               (Bit4)


#define GLOBAL_REG_CPLL_ADDITIONAL_CTRL                                                                                    (GLOBAL_REG_BASE + 0xac0)
#define GLOBAL_REG_CPLL_ADDITIONAL_CTRL_DEFAULT                                                                            0x0
#define GLOBAL_REG_CPLL_ADDITIONAL_CTRL_CTL_CPLL_REG_USE_1M_CONFIG_IN_1M_TRX                                               (Bit0)
#define GLOBAL_REG_CPLL_ADDITIONAL_CTRL_CTL_CPLL_REG_FORCE_USE_1M_CONFIG                                                   (Bit1)


#endif // _GLOBAL_REG_DEFINES_H

