#ifndef _FPGA_REG_DEFINES_H
#define _FPGA_REG_DEFINES_H
/* **************************** */
#define FPGA_REG_GIT_VERSION                                                               (FPGA_REG_BASE + 0x10)
#define FPGA_REG_GIT_VERSION_DEFAULT                                                       0x0
#define FPGA_REG_GIT_VERSION_STS_GIT_VER                                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define FPGA_REG_GIT_VERSION_STS_GIT_VER_MASK                                              (Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_GIT_VERSION_STS_GIT_VER_SHIFT                                             (0)
#define FPGA_REG_GIT_VERSION_STS_GIT_UPDATE                                                (Bit31)


#define FPGA_REG_BUILD_DATE                                                                (FPGA_REG_BASE + 0x14)
#define FPGA_REG_BUILD_DATE_DEFAULT                                                        0x0
#define FPGA_REG_BUILD_DATE_STS_DATE_DAY                                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define FPGA_REG_BUILD_DATE_STS_DATE_DAY_MASK                                              (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_BUILD_DATE_STS_DATE_DAY_SHIFT                                             (0)
#define FPGA_REG_BUILD_DATE_STS_DATE_MONTH                                                 (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FPGA_REG_BUILD_DATE_STS_DATE_MONTH_MASK                                            (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_BUILD_DATE_STS_DATE_MONTH_SHIFT                                           (8)
#define FPGA_REG_BUILD_DATE_STS_DATE_YEAR                                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FPGA_REG_BUILD_DATE_STS_DATE_YEAR_MASK                                             (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_BUILD_DATE_STS_DATE_YEAR_SHIFT                                            (16)


#define FPGA_REG_BUILD_TIME                                                                (FPGA_REG_BASE + 0x18)
#define FPGA_REG_BUILD_TIME_DEFAULT                                                        0x0
#define FPGA_REG_BUILD_TIME_STS_TIME_MINUTE                                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define FPGA_REG_BUILD_TIME_STS_TIME_MINUTE_MASK                                           (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_BUILD_TIME_STS_TIME_MINUTE_SHIFT                                          (0)
#define FPGA_REG_BUILD_TIME_STS_TIME_HOUR                                                  (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FPGA_REG_BUILD_TIME_STS_TIME_HOUR_MASK                                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_BUILD_TIME_STS_TIME_HOUR_SHIFT                                            (8)


#define FPGA_REG_FPGA_MODEM_CTRL                                                           (FPGA_REG_BASE + 0x1c)
#define FPGA_REG_FPGA_MODEM_CTRL_DEFAULT                                                   0x0
#define FPGA_REG_FPGA_MODEM_CTRL_CTL_FCS_IQ_SWAP                                           (Bit0)
#define FPGA_REG_FPGA_MODEM_CTRL_CTL_FCS_CONST                                             (Bit1)
#define FPGA_REG_FPGA_MODEM_CTRL_CTL_DAC_BIT_SHIFT                                         (Bit2)
#define FPGA_REG_FPGA_MODEM_CTRL_CTL_DAC_IQ_SWAP                                           (Bit4)
#define FPGA_REG_FPGA_MODEM_CTRL_CTL_RF_BUSY_EN                                            (Bit8)
#define FPGA_REG_FPGA_MODEM_CTRL_CTL_USE_RAM_FREQWORD                                      (Bit12)


#define FPGA_REG_FPGA_CLK_CTRL                                                             (FPGA_REG_BASE + 0x20)
#define FPGA_REG_FPGA_CLK_CTRL_DEFAULT                                                     0x0
#define FPGA_REG_FPGA_CLK_CTRL_CTL_CLK_SWITCH                                              (Bit0)


#define FPGA_REG_FPGA_TX_RX_EN_EXT                                                         (FPGA_REG_BASE + 0x24)
#define FPGA_REG_FPGA_TX_RX_EN_EXT_DEFAULT                                                 0x0
#define FPGA_REG_FPGA_TX_RX_EN_EXT_CTL_TX_EN_EXT                                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define FPGA_REG_FPGA_TX_RX_EN_EXT_CTL_TX_EN_EXT_MASK                                      (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_TX_RX_EN_EXT_CTL_TX_EN_EXT_SHIFT                                     (0)
#define FPGA_REG_FPGA_TX_RX_EN_EXT_CTL_RX_EN_EXT                                           (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FPGA_REG_FPGA_TX_RX_EN_EXT_CTL_RX_EN_EXT_MASK                                      (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_TX_RX_EN_EXT_CTL_RX_EN_EXT_SHIFT                                     (8)
#define FPGA_REG_FPGA_TX_RX_EN_EXT_CTL_TX_EN_EXT2                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define FPGA_REG_FPGA_TX_RX_EN_EXT_CTL_TX_EN_EXT2_MASK                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_TX_RX_EN_EXT_CTL_TX_EN_EXT2_SHIFT                                    (16)
#define FPGA_REG_FPGA_TX_RX_EN_EXT_CTL_RX_EN_EXT2                                          (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FPGA_REG_FPGA_TX_RX_EN_EXT_CTL_RX_EN_EXT2_MASK                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_TX_RX_EN_EXT_CTL_RX_EN_EXT2_SHIFT                                    (24)


#define FPGA_REG_FPGA_32K_CYCLE_LIMIT                                                      (FPGA_REG_BASE + 0x28)
#define FPGA_REG_FPGA_32K_CYCLE_LIMIT_DEFAULT                                              0x3D103D0
#define FPGA_REG_FPGA_32K_CYCLE_LIMIT_CTL_32K_LOW_DURATION                                 (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FPGA_REG_FPGA_32K_CYCLE_LIMIT_CTL_32K_LOW_DURATION_MASK                            (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_32K_CYCLE_LIMIT_CTL_32K_LOW_DURATION_SHIFT                           (0)
#define FPGA_REG_FPGA_32K_CYCLE_LIMIT_CTL_32K_HIGH_DURATION                                (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FPGA_REG_FPGA_32K_CYCLE_LIMIT_CTL_32K_HIGH_DURATION_MASK                           (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_32K_CYCLE_LIMIT_CTL_32K_HIGH_DURATION_SHIFT                          (16)


#define FPGA_REG_FPGA_IO_BOARD_CTRL                                                        (FPGA_REG_BASE + 0x30)
#define FPGA_REG_FPGA_IO_BOARD_CTRL_DEFAULT                                                0x11F0
#define FPGA_REG_FPGA_IO_BOARD_CTRL_CTL_IO_BOARD_I2C_SEL                                   (Bit0+Bit1+Bit2)
#define FPGA_REG_FPGA_IO_BOARD_CTRL_CTL_IO_BOARD_I2C_SEL_MASK                              (Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_IO_BOARD_CTRL_CTL_IO_BOARD_I2C_SEL_SHIFT                             (0)
#define FPGA_REG_FPGA_IO_BOARD_CTRL_CTL_U2_OE                                              (Bit4)
#define FPGA_REG_FPGA_IO_BOARD_CTRL_CTL_U3_OE                                              (Bit5)
#define FPGA_REG_FPGA_IO_BOARD_CTRL_CTL_U14_OE                                             (Bit6)
#define FPGA_REG_FPGA_IO_BOARD_CTRL_CTL_U15_OE                                             (Bit7)
#define FPGA_REG_FPGA_IO_BOARD_CTRL_CTL_U16_OE                                             (Bit8)
#define FPGA_REG_FPGA_IO_BOARD_CTRL_CTL_HRT_PD                                             (Bit12)
#define FPGA_REG_FPGA_IO_BOARD_CTRL_CTL_HRT_RSTN                                           (Bit13)
#define FPGA_REG_FPGA_IO_BOARD_CTRL_CTL_CODEC_PDN                                          (Bit14)


#define FPGA_REG_FPGA_I2S_CTRL                                                             (FPGA_REG_BASE + 0x34)
#define FPGA_REG_FPGA_I2S_CTRL_DEFAULT                                                     0x10303
#define FPGA_REG_FPGA_I2S_CTRL_CTL_I2S_SCLK_HIGH_DURATION                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define FPGA_REG_FPGA_I2S_CTRL_CTL_I2S_SCLK_HIGH_DURATION_MASK                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_I2S_CTRL_CTL_I2S_SCLK_HIGH_DURATION_SHIFT                            (0)
#define FPGA_REG_FPGA_I2S_CTRL_CTL_I2S_SCLK_LOW_DURATION                                   (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define FPGA_REG_FPGA_I2S_CTRL_CTL_I2S_SCLK_LOW_DURATION_MASK                              (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_I2S_CTRL_CTL_I2S_SCLK_LOW_DURATION_SHIFT                             (8)
#define FPGA_REG_FPGA_I2S_CTRL_CTL_I2S_SCLK_TO_PAD                                         (Bit16)


#define FPGA_REG_FPGA_SPI_M0_CTRL                                                          (FPGA_REG_BASE + 0x38)
#define FPGA_REG_FPGA_SPI_M0_CTRL_DEFAULT                                                  0x1
#define FPGA_REG_FPGA_SPI_M0_CTRL_CTL_SPI_M0_SINGLE_MODE                                   (Bit0)


#define FPGA_REG_FPGA_SPI_FLASH_CTRL                                                       (FPGA_REG_BASE + 0x3c)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_DEFAULT                                               0x32100F3
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SPI_FLASH_WP_N                                    (Bit0)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SPI_FLASH_HOLD_N                                  (Bit1)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SPI_MASTER_SS_N                                   (Bit4+Bit5+Bit6+Bit7)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SPI_MASTER_SS_N_MASK                              (Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SPI_MASTER_SS_N_SHIFT                             (4)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SPI_MASTER_SS_N_SEL                               (Bit8+Bit9+Bit10+Bit11)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SPI_MASTER_SS_N_SEL_MASK                          (Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SPI_MASTER_SS_N_SEL_SHIFT                         (8)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SSI_MASTER0_SSN0_MUX                              (Bit12+Bit13)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SSI_MASTER0_SSN0_MUX_MASK                         (Bit1+Bit0)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SSI_MASTER0_SSN0_MUX_SHIFT                        (12)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SSI_MASTER0_SSN1_MUX                              (Bit16+Bit17)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SSI_MASTER0_SSN1_MUX_MASK                         (Bit1+Bit0)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SSI_MASTER0_SSN1_MUX_SHIFT                        (16)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SSI_MASTER0_SSN2_MUX                              (Bit20+Bit21)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SSI_MASTER0_SSN2_MUX_MASK                         (Bit1+Bit0)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SSI_MASTER0_SSN2_MUX_SHIFT                        (20)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SSI_MASTER0_SSN3_MUX                              (Bit24+Bit25)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SSI_MASTER0_SSN3_MUX_MASK                         (Bit1+Bit0)
#define FPGA_REG_FPGA_SPI_FLASH_CTRL_CTL_SSI_MASTER0_SSN3_MUX_SHIFT                        (24)


#define FPGA_REG_FPGA_RX_CTRL                                                              (FPGA_REG_BASE + 0x80)
#define FPGA_REG_FPGA_RX_CTRL_DEFAULT                                                      0x18460
#define FPGA_REG_FPGA_RX_CTRL_CTL_GAIN_RX                                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define FPGA_REG_FPGA_RX_CTRL_CTL_GAIN_RX_MASK                                             (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_RX_CTRL_CTL_GAIN_RX_SHIFT                                            (0)
#define FPGA_REG_FPGA_RX_CTRL_CTL_SDM_EN                                                   (Bit10)
#define FPGA_REG_FPGA_RX_CTRL_CTL_SDM_DITHER_GAIN                                          (Bit11+Bit12)
#define FPGA_REG_FPGA_RX_CTRL_CTL_SDM_DITHER_GAIN_MASK                                     (Bit1+Bit0)
#define FPGA_REG_FPGA_RX_CTRL_CTL_SDM_DITHER_GAIN_SHIFT                                    (11)
#define FPGA_REG_FPGA_RX_CTRL_CTL_SDM_DITHER_ORDER                                         (Bit13+Bit14)
#define FPGA_REG_FPGA_RX_CTRL_CTL_SDM_DITHER_ORDER_MASK                                    (Bit1+Bit0)
#define FPGA_REG_FPGA_RX_CTRL_CTL_SDM_DITHER_ORDER_SHIFT                                   (13)
#define FPGA_REG_FPGA_RX_CTRL_CTL_SDM_MOD_INDEX                                            (Bit15+Bit16)
#define FPGA_REG_FPGA_RX_CTRL_CTL_SDM_MOD_INDEX_MASK                                       (Bit1+Bit0)
#define FPGA_REG_FPGA_RX_CTRL_CTL_SDM_MOD_INDEX_SHIFT                                      (15)
#define FPGA_REG_FPGA_RX_CTRL_CTL_SDM_MUX_SEL                                              (Bit17+Bit18)
#define FPGA_REG_FPGA_RX_CTRL_CTL_SDM_MUX_SEL_MASK                                         (Bit1+Bit0)
#define FPGA_REG_FPGA_RX_CTRL_CTL_SDM_MUX_SEL_SHIFT                                        (17)
#define FPGA_REG_FPGA_RX_CTRL_CTL_RX_CLK_SEL_FRC                                           (Bit19)
#define FPGA_REG_FPGA_RX_CTRL_CTL_RX_CLK_SEL_VAL                                           (Bit20)


#define FPGA_REG_FPGA_RX_STAT                                                              (FPGA_REG_BASE + 0x84)
#define FPGA_REG_FPGA_RX_STAT_DEFAULT                                                      0x0
#define FPGA_REG_FPGA_RX_STAT_STS_SDM_MUX_OUT_I                                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define FPGA_REG_FPGA_RX_STAT_STS_SDM_MUX_OUT_I_MASK                                       (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_RX_STAT_STS_SDM_MUX_OUT_I_SHIFT                                      (0)
#define FPGA_REG_FPGA_RX_STAT_STS_SDM_MUX_OUT_Q                                            (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30)
#define FPGA_REG_FPGA_RX_STAT_STS_SDM_MUX_OUT_Q_MASK                                       (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_RX_STAT_STS_SDM_MUX_OUT_Q_SHIFT                                      (16)


#define FPGA_REG_FPGA_EXT_WAKEUP_CNT_CTRL                                                  (FPGA_REG_BASE + 0x90)
#define FPGA_REG_FPGA_EXT_WAKEUP_CNT_CTRL_DEFAULT                                          0x80001000
#define FPGA_REG_FPGA_EXT_WAKEUP_CNT_CTRL_CTL_WAKEUP_CNT_LMT                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30)
#define FPGA_REG_FPGA_EXT_WAKEUP_CNT_CTRL_CTL_WAKEUP_CNT_LMT_MASK                          (Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_EXT_WAKEUP_CNT_CTRL_CTL_WAKEUP_CNT_LMT_SHIFT                         (0)
#define FPGA_REG_FPGA_EXT_WAKEUP_CNT_CTRL_CTL_WAKEUP_CNT_CLR                               (Bit31)


#define FPGA_REG_FPGA_EXT_GPO_CTRL                                                         (FPGA_REG_BASE + 0x98)
#define FPGA_REG_FPGA_EXT_GPO_CTRL_DEFAULT                                                 0xA
#define FPGA_REG_FPGA_EXT_GPO_CTRL_CTL_EXT_GPO_VAL                                         (Bit0+Bit1+Bit2+Bit3)
#define FPGA_REG_FPGA_EXT_GPO_CTRL_CTL_EXT_GPO_VAL_MASK                                    (Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_EXT_GPO_CTRL_CTL_EXT_GPO_VAL_SHIFT                                   (0)


#define FPGA_REG_FPGA_EXT_GPI_STS                                                          (FPGA_REG_BASE + 0x9c)
#define FPGA_REG_FPGA_EXT_GPI_STS_DEFAULT                                                  0x0
#define FPGA_REG_FPGA_EXT_GPI_STS_STS_EXT_GPI_VAL                                          (Bit0+Bit1+Bit2+Bit3)
#define FPGA_REG_FPGA_EXT_GPI_STS_STS_EXT_GPI_VAL_MASK                                     (Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_EXT_GPI_STS_STS_EXT_GPI_VAL_SHIFT                                    (0)


#define FPGA_REG_FPGA_PDM_MIC_MISC_CTRL                                                    (FPGA_REG_BASE + 0x100)
#define FPGA_REG_FPGA_PDM_MIC_MISC_CTRL_DEFAULT                                            0x0
#define FPGA_REG_FPGA_PDM_MIC_MISC_CTRL_CTL_PDM_DATA_SRC                                   (Bit0)
#define FPGA_REG_FPGA_PDM_MIC_MISC_CTRL_CTL_PDM_MEM_EN                                     (Bit4)
#define FPGA_REG_FPGA_PDM_MIC_MISC_CTRL_CTL_PDM_MEM_CLK_EDGE                               (Bit5)
#define FPGA_REG_FPGA_PDM_MIC_MISC_CTRL_CTL_PDM_MEM_LSB_FIRST                              (Bit6)
#define FPGA_REG_FPGA_PDM_MIC_MISC_CTRL_CTL_PDM_MEM_STEREO                                 (Bit7)


#define FPGA_REG_FPGA_PDM_MEM_MIC_START_ADDR                                               (FPGA_REG_BASE + 0x104)
#define FPGA_REG_FPGA_PDM_MEM_MIC_START_ADDR_DEFAULT                                       0x0
#define FPGA_REG_FPGA_PDM_MEM_MIC_START_ADDR_CTL_PDM_MEM_START_ADDR                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FPGA_REG_FPGA_PDM_MEM_MIC_START_ADDR_CTL_PDM_MEM_START_ADDR_MASK                   (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_PDM_MEM_MIC_START_ADDR_CTL_PDM_MEM_START_ADDR_SHIFT                  (0)


#define FPGA_REG_FPGA_PDM_MEM_MIC_END_ADDR                                                 (FPGA_REG_BASE + 0x108)
#define FPGA_REG_FPGA_PDM_MEM_MIC_END_ADDR_DEFAULT                                         0x0
#define FPGA_REG_FPGA_PDM_MEM_MIC_END_ADDR_CTL_PDM_MEM_END_ADDR                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FPGA_REG_FPGA_PDM_MEM_MIC_END_ADDR_CTL_PDM_MEM_END_ADDR_MASK                       (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_PDM_MEM_MIC_END_ADDR_CTL_PDM_MEM_END_ADDR_SHIFT                      (0)


#define FPGA_REG_FPGA_PDM_MEM_WRITE_INIT_ADDR                                              (FPGA_REG_BASE + 0x10c)
#define FPGA_REG_FPGA_PDM_MEM_WRITE_INIT_ADDR_DEFAULT                                      0x0
#define FPGA_REG_FPGA_PDM_MEM_WRITE_INIT_ADDR_CTL_PDM_MEM_WRITE_INIT_ADDR                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FPGA_REG_FPGA_PDM_MEM_WRITE_INIT_ADDR_CTL_PDM_MEM_WRITE_INIT_ADDR_MASK             (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_PDM_MEM_WRITE_INIT_ADDR_CTL_PDM_MEM_WRITE_INIT_ADDR_SHIFT            (0)


#define FPGA_REG_FPGA_PDM_MEM_WDATA                                                        (FPGA_REG_BASE + 0x110)
#define FPGA_REG_FPGA_PDM_MEM_WDATA_DEFAULT                                                0x0
#define FPGA_REG_FPGA_PDM_MEM_WDATA_CTL_PDM_MEM_WDATA                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FPGA_REG_FPGA_PDM_MEM_WDATA_CTL_PDM_MEM_WDATA_MASK                                 (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_PDM_MEM_WDATA_CTL_PDM_MEM_WDATA_SHIFT                                (0)


#define FPGA_REG_FPGA_CAPTURE_PDM_SADDR                                                    (FPGA_REG_BASE + 0x114)
#define FPGA_REG_FPGA_CAPTURE_PDM_SADDR_DEFAULT                                            0x0
#define FPGA_REG_FPGA_CAPTURE_PDM_SADDR_CTL_CAPTURE_PDM_SADDR                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FPGA_REG_FPGA_CAPTURE_PDM_SADDR_CTL_CAPTURE_PDM_SADDR_MASK                         (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_CAPTURE_PDM_SADDR_CTL_CAPTURE_PDM_SADDR_SHIFT                        (0)


#define FPGA_REG_FPGA_CAPTURE_PDM_SIZE                                                     (FPGA_REG_BASE + 0x118)
#define FPGA_REG_FPGA_CAPTURE_PDM_SIZE_DEFAULT                                             0xFFF
#define FPGA_REG_FPGA_CAPTURE_PDM_SIZE_CTL_CAPTURE_PDM_SIZE                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define FPGA_REG_FPGA_CAPTURE_PDM_SIZE_CTL_CAPTURE_PDM_SIZE_MASK                           (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_CAPTURE_PDM_SIZE_CTL_CAPTURE_PDM_SIZE_SHIFT                          (0)


#define FPGA_REG_FPGA_CAPTURE_PDM_EN                                                       (FPGA_REG_BASE + 0x11c)
#define FPGA_REG_FPGA_CAPTURE_PDM_EN_DEFAULT                                               0x1
#define FPGA_REG_FPGA_CAPTURE_PDM_EN_CTL_CAPTURE_PDM_EN                                    (Bit0)


#define FPGA_REG_FPGA_CAPTURE_PDM_RDATA                                                    (FPGA_REG_BASE + 0x120)
#define FPGA_REG_FPGA_CAPTURE_PDM_RDATA_DEFAULT                                            0x0
#define FPGA_REG_FPGA_CAPTURE_PDM_RDATA_CTL_CAPTURE_PDM_RDATA                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define FPGA_REG_FPGA_CAPTURE_PDM_RDATA_CTL_CAPTURE_PDM_RDATA_MASK                         (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define FPGA_REG_FPGA_CAPTURE_PDM_RDATA_CTL_CAPTURE_PDM_RDATA_SHIFT                        (0)


#define FPGA_REG_FPGA_CAPTURE_FULL                                                         (FPGA_REG_BASE + 0x124)
#define FPGA_REG_FPGA_CAPTURE_FULL_DEFAULT                                                 0x0
#define FPGA_REG_FPGA_CAPTURE_FULL_CTL_CAPTURE_FULL                                        (Bit0)


#define FPGA_REG_FPGA_UART_RX_CTRL                                                         (FPGA_REG_BASE + 0x140)
#define FPGA_REG_FPGA_UART_RX_CTRL_DEFAULT                                                 0x0
#define FPGA_REG_FPGA_UART_RX_CTRL_CTL_DISABLE_UART0_RX                                    (Bit0)
#define FPGA_REG_FPGA_UART_RX_CTRL_CTL_DISABLE_UART1_RX                                    (Bit1)


#endif // _FPGA_REG_DEFINES_H

