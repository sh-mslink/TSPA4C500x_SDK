#ifndef _SADCCTRL_REG_DEFINES_H
#define _SADCCTRL_REG_DEFINES_H
/* **************************** */
#define SADCCTRL_REG_INTR_STATUS                                                            (SADCCTRL_REG_BASE + 0x0)
#define SADCCTRL_REG_INTR_STATUS_DEFAULT                                                    0x0
#define SADCCTRL_REG_INTR_STATUS_SAMPLE_DONE                                                (Bit0)
#define SADCCTRL_REG_INTR_STATUS_FIFO_FULL                                                  (Bit1)
#define SADCCTRL_REG_INTR_STATUS_FIFO_EMPTY                                                 (Bit2)
#define SADCCTRL_REG_INTR_STATUS_FIFO_ALMOST_FULL                                           (Bit3)


#define SADCCTRL_REG_INTR_MASK_STATUS                                                       (SADCCTRL_REG_BASE + 0x4)
#define SADCCTRL_REG_INTR_MASK_STATUS_DEFAULT                                               0x0
#define SADCCTRL_REG_INTR_MASK_STATUS_SAMPLE_DONE                                           (Bit0)
#define SADCCTRL_REG_INTR_MASK_STATUS_FIFO_FULL                                             (Bit1)
#define SADCCTRL_REG_INTR_MASK_STATUS_FIFO_EMPTY                                            (Bit2)
#define SADCCTRL_REG_INTR_MASK_STATUS_FIFO_ALMOST_FULL                                      (Bit3)


#define SADCCTRL_REG_INTR_CLEAR                                                             (SADCCTRL_REG_BASE + 0x8)
#define SADCCTRL_REG_INTR_CLEAR_DEFAULT                                                     0x0
#define SADCCTRL_REG_INTR_CLEAR_SAMPLE_DONE                                                 (Bit0)
#define SADCCTRL_REG_INTR_CLEAR_FIFO_FULL                                                   (Bit1)
#define SADCCTRL_REG_INTR_CLEAR_FIFO_EMPTY                                                  (Bit2)
#define SADCCTRL_REG_INTR_CLEAR_FIFO_ALMOST_FULL                                            (Bit3)


#define SADCCTRL_REG_INTR_SET                                                               (SADCCTRL_REG_BASE + 0xc)
#define SADCCTRL_REG_INTR_SET_DEFAULT                                                       0x0
#define SADCCTRL_REG_INTR_SET_SAMPLE_DONE                                                   (Bit0)
#define SADCCTRL_REG_INTR_SET_FIFO_FULL                                                     (Bit1)
#define SADCCTRL_REG_INTR_SET_FIFO_EMPTY                                                    (Bit2)
#define SADCCTRL_REG_INTR_SET_FIFO_ALMOST_FULL                                              (Bit3)


#define SADCCTRL_REG_INTR_MASK_SET                                                          (SADCCTRL_REG_BASE + 0x10)
#define SADCCTRL_REG_INTR_MASK_SET_DEFAULT                                                  0x0
#define SADCCTRL_REG_INTR_MASK_SET_SAMPLE_DONE                                              (Bit0)
#define SADCCTRL_REG_INTR_MASK_SET_FIFO_FULL                                                (Bit1)
#define SADCCTRL_REG_INTR_MASK_SET_FIFO_EMPTY                                               (Bit2)
#define SADCCTRL_REG_INTR_MASK_SET_FIFO_ALMOST_FULL                                         (Bit3)


#define SADCCTRL_REG_INTR_MASK_CLEAR                                                        (SADCCTRL_REG_BASE + 0x14)
#define SADCCTRL_REG_INTR_MASK_CLEAR_DEFAULT                                                0x0
#define SADCCTRL_REG_INTR_MASK_CLEAR_SAMPLE_DONE                                            (Bit0)
#define SADCCTRL_REG_INTR_MASK_CLEAR_FIFO_FULL                                              (Bit1)
#define SADCCTRL_REG_INTR_MASK_CLEAR_FIFO_EMPTY                                             (Bit2)
#define SADCCTRL_REG_INTR_MASK_CLEAR_FIFO_ALMOST_FULL                                       (Bit3)


#define SADCCTRL_REG_MISC_CTRL                                                              (SADCCTRL_REG_BASE + 0x40)
#define SADCCTRL_REG_MISC_CTRL_DEFAULT                                                      0x0
#define SADCCTRL_REG_MISC_CTRL_CTL_ENABLE                                                   (Bit0)
#define SADCCTRL_REG_MISC_CTRL_CTL_START                                                    (Bit1)
#define SADCCTRL_REG_MISC_CTRL_CTL_END                                                      (Bit2)
#define SADCCTRL_REG_MISC_CTRL_CTL_RST_INTRCTRL                                             (Bit4)
#define SADCCTRL_REG_MISC_CTRL_CTL_NUM_SAMPLES                                              (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define SADCCTRL_REG_MISC_CTRL_CTL_NUM_SAMPLES_MASK                                         (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_MISC_CTRL_CTL_NUM_SAMPLES_SHIFT                                        (16)


#define SADCCTRL_REG_CHANNEL_EN_CTRL                                                        (SADCCTRL_REG_BASE + 0x44)
#define SADCCTRL_REG_CHANNEL_EN_CTRL_DEFAULT                                                0x10100000
#define SADCCTRL_REG_CHANNEL_EN_CTRL_CTL_CH_EN                                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define SADCCTRL_REG_CHANNEL_EN_CTRL_CTL_CH_EN_MASK                                         (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_CHANNEL_EN_CTRL_CTL_CH_EN_SHIFT                                        (0)
#define SADCCTRL_REG_CHANNEL_EN_CTRL_CTL_SAMPLE_CH_INTERVAL                                 (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define SADCCTRL_REG_CHANNEL_EN_CTRL_CTL_SAMPLE_CH_INTERVAL_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_CHANNEL_EN_CTRL_CTL_SAMPLE_CH_INTERVAL_SHIFT                           (16)
#define SADCCTRL_REG_CHANNEL_EN_CTRL_CTL_SAMPLE_GRP_INTERVAL                                (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define SADCCTRL_REG_CHANNEL_EN_CTRL_CTL_SAMPLE_GRP_INTERVAL_MASK                           (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_CHANNEL_EN_CTRL_CTL_SAMPLE_GRP_INTERVAL_SHIFT                          (24)


#define SADCCTRL_REG_SAMPLE_TIMING_CTRL                                                     (SADCCTRL_REG_BASE + 0x48)
#define SADCCTRL_REG_SAMPLE_TIMING_CTRL_DEFAULT                                             0x1010
#define SADCCTRL_REG_SAMPLE_TIMING_CTRL_CTL_EN2START_DELAY                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define SADCCTRL_REG_SAMPLE_TIMING_CTRL_CTL_EN2START_DELAY_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_SAMPLE_TIMING_CTRL_CTL_EN2START_DELAY_SHIFT                            (0)
#define SADCCTRL_REG_SAMPLE_TIMING_CTRL_CTL_SAMPLE_DELAY                                    (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define SADCCTRL_REG_SAMPLE_TIMING_CTRL_CTL_SAMPLE_DELAY_MASK                               (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_SAMPLE_TIMING_CTRL_CTL_SAMPLE_DELAY_SHIFT                              (8)
#define SADCCTRL_REG_SAMPLE_TIMING_CTRL_CTL_DISABLE_AFTER_SAMPLE                            (Bit16)


#define SADCCTRL_REG_FIFO_CTRL                                                              (SADCCTRL_REG_BASE + 0x4c)
#define SADCCTRL_REG_FIFO_CTRL_DEFAULT                                                      0x10
#define SADCCTRL_REG_FIFO_CTRL_CTL_FIFO_SIZE_M1                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SADCCTRL_REG_FIFO_CTRL_CTL_FIFO_SIZE_M1_MASK                                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_FIFO_CTRL_CTL_FIFO_SIZE_M1_SHIFT                                       (0)


#define SADCCTRL_REG_FIFO_ALMOST_FULL_CTRL                                                  (SADCCTRL_REG_BASE + 0x50)
#define SADCCTRL_REG_FIFO_ALMOST_FULL_CTRL_DEFAULT                                          0x5
#define SADCCTRL_REG_FIFO_ALMOST_FULL_CTRL_CTL_FIFO_ALMOST_FULL_WATER_MARK                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SADCCTRL_REG_FIFO_ALMOST_FULL_CTRL_CTL_FIFO_ALMOST_FULL_WATER_MARK_MASK             (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_FIFO_ALMOST_FULL_CTRL_CTL_FIFO_ALMOST_FULL_WATER_MARK_SHIFT            (0)


#define SADCCTRL_REG_STATUS                                                                 (SADCCTRL_REG_BASE + 0x60)
#define SADCCTRL_REG_STATUS_DEFAULT                                                         0x0
#define SADCCTRL_REG_STATUS_STS_CURR_CH                                                     (Bit0+Bit1+Bit2+Bit3)
#define SADCCTRL_REG_STATUS_STS_CURR_CH_MASK                                                (Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_STATUS_STS_CURR_CH_SHIFT                                               (0)
#define SADCCTRL_REG_STATUS_STS_FIFO_CNT                                                    (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18)
#define SADCCTRL_REG_STATUS_STS_FIFO_CNT_MASK                                               (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_STATUS_STS_FIFO_CNT_SHIFT                                              (4)
#define SADCCTRL_REG_STATUS_STS_MAIN_SM                                                     (Bit20+Bit21+Bit22+Bit23)
#define SADCCTRL_REG_STATUS_STS_MAIN_SM_MASK                                                (Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_STATUS_STS_MAIN_SM_SHIFT                                               (20)
#define SADCCTRL_REG_STATUS_STS_CORE_SM                                                     (Bit24+Bit25+Bit26+Bit27)
#define SADCCTRL_REG_STATUS_STS_CORE_SM_MASK                                                (Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_STATUS_STS_CORE_SM_SHIFT                                               (24)


#define SADCCTRL_REG_FIFO_VAL                                                               (SADCCTRL_REG_BASE + 0x80)
#define SADCCTRL_REG_FIFO_VAL_DEFAULT                                                       0x0
#define SADCCTRL_REG_FIFO_VAL_STS_FIFO_RDATA                                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define SADCCTRL_REG_FIFO_VAL_STS_FIFO_RDATA_MASK                                           (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_FIFO_VAL_STS_FIFO_RDATA_SHIFT                                          (0)


#define SADCCTRL_REG_FORCE_CTRL                                                             (SADCCTRL_REG_BASE + 0x90)
#define SADCCTRL_REG_FORCE_CTRL_DEFAULT                                                     0x0
#define SADCCTRL_REG_FORCE_CTRL_CTL_FORCE_EN                                                (Bit0)
#define SADCCTRL_REG_FORCE_CTRL_CTL_FORCE_CH                                                (Bit4+Bit5+Bit6+Bit7)
#define SADCCTRL_REG_FORCE_CTRL_CTL_FORCE_CH_MASK                                           (Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_FORCE_CTRL_CTL_FORCE_CH_SHIFT                                          (4)
#define SADCCTRL_REG_FORCE_CTRL_CTL_FORCE_START                                             (Bit8)


#define SADCCTRL_REG_CURR_ADC_VAL                                                           (SADCCTRL_REG_BASE + 0x98)
#define SADCCTRL_REG_CURR_ADC_VAL_DEFAULT                                                   0x0
#define SADCCTRL_REG_CURR_ADC_VAL_STS_CUR_ADC_VAL                                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define SADCCTRL_REG_CURR_ADC_VAL_STS_CUR_ADC_VAL_MASK                                      (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_CURR_ADC_VAL_STS_CUR_ADC_VAL_SHIFT                                     (0)


#define SADCCTRL_REG_SENSOR_ADC_REG1TO3                                                     (SADCCTRL_REG_BASE + 0xc0)
#define SADCCTRL_REG_SENSOR_ADC_REG1TO3_DEFAULT                                             0x0
#define SADCCTRL_REG_SENSOR_ADC_REG1TO3_CTL_SENSOR_ADC_REG1                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define SADCCTRL_REG_SENSOR_ADC_REG1TO3_CTL_SENSOR_ADC_REG1_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_SENSOR_ADC_REG1TO3_CTL_SENSOR_ADC_REG1_SHIFT                           (0)
#define SADCCTRL_REG_SENSOR_ADC_REG1TO3_CTL_SENSOR_ADC_REG2                                 (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define SADCCTRL_REG_SENSOR_ADC_REG1TO3_CTL_SENSOR_ADC_REG2_MASK                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SADCCTRL_REG_SENSOR_ADC_REG1TO3_CTL_SENSOR_ADC_REG2_SHIFT                           (8)


#endif // _SADCCTRL_REG_DEFINES_H

