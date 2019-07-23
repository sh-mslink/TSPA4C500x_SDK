#ifndef _SPIFLASH_REG_DEFINES_H
#define _SPIFLASH_REG_DEFINES_H
/* **************************** */
#define SPIFLASH_REG_INTR_STATUS                                                                 (SPIFLASH_REG_BASE + 0x0)
#define SPIFLASH_REG_INTR_STATUS_DEFAULT                                                         0x0
#define SPIFLASH_REG_INTR_STATUS_ERR_APB_ACCESS_DURING_DISABLE                                   (Bit0)
#define SPIFLASH_REG_INTR_STATUS_ERR_CACHE_ACCESS_DURING_DISABLE                                 (Bit1)


#define SPIFLASH_REG_INTR_MASK_STATUS                                                            (SPIFLASH_REG_BASE + 0x4)
#define SPIFLASH_REG_INTR_MASK_STATUS_DEFAULT                                                    0x0
#define SPIFLASH_REG_INTR_MASK_STATUS_ERR_APB_ACCESS_DURING_DISABLE                              (Bit0)
#define SPIFLASH_REG_INTR_MASK_STATUS_ERR_CACHE_ACCESS_DURING_DISABLE                            (Bit1)


#define SPIFLASH_REG_INTR_CLR                                                                    (SPIFLASH_REG_BASE + 0x8)
#define SPIFLASH_REG_INTR_CLR_DEFAULT                                                            0x0
#define SPIFLASH_REG_INTR_CLR_ERR_APB_ACCESS_DURING_DISABLE                                      (Bit0)
#define SPIFLASH_REG_INTR_CLR_ERR_CACHE_ACCESS_DURING_DISABLE                                    (Bit1)


#define SPIFLASH_REG_INTR_SET                                                                    (SPIFLASH_REG_BASE + 0xc)
#define SPIFLASH_REG_INTR_SET_DEFAULT                                                            0x0
#define SPIFLASH_REG_INTR_SET_ERR_APB_ACCESS_DURING_DISABLE                                      (Bit0)
#define SPIFLASH_REG_INTR_SET_ERR_CACHE_ACCESS_DURING_DISABLE                                    (Bit1)


#define SPIFLASH_REG_INTR_MASK_SET                                                               (SPIFLASH_REG_BASE + 0x10)
#define SPIFLASH_REG_INTR_MASK_SET_DEFAULT                                                       0x0
#define SPIFLASH_REG_INTR_MASK_SET_ERR_APB_ACCESS_DURING_DISABLE                                 (Bit0)
#define SPIFLASH_REG_INTR_MASK_SET_ERR_CACHE_ACCESS_DURING_DISABLE                               (Bit1)


#define SPIFLASH_REG_INTR_MASK_CLR                                                               (SPIFLASH_REG_BASE + 0x14)
#define SPIFLASH_REG_INTR_MASK_CLR_DEFAULT                                                       0x0
#define SPIFLASH_REG_INTR_MASK_CLR_ERR_APB_ACCESS_DURING_DISABLE                                 (Bit0)
#define SPIFLASH_REG_INTR_MASK_CLR_ERR_CACHE_ACCESS_DURING_DISABLE                               (Bit1)


#define SPIFLASH_REG_SPIFLASH_MISC_CTRL                                                          (SPIFLASH_REG_BASE + 0x20)
#define SPIFLASH_REG_SPIFLASH_MISC_CTRL_DEFAULT                                                  0x0
#define SPIFLASH_REG_SPIFLASH_MISC_CTRL_CTL_SPI_APB_MUX_SEL                                      (Bit0)
#define SPIFLASH_REG_SPIFLASH_MISC_CTRL_CTL_SPI_FLASH_MODE_CONTINOUS                             (Bit1)
#define SPIFLASH_REG_SPIFLASH_MISC_CTRL_CTL_SPI_FLASH_NO_INSTRUCTION_MODE                        (Bit2)
#define SPIFLASH_REG_SPIFLASH_MISC_CTRL_CTL_SPI_FLASH_ENDIAN_PRDATA_SWAP                         (Bit3)
#define SPIFLASH_REG_SPIFLASH_MISC_CTRL_CTL_SPI_FLASH_ADDR_LENGTH                                (Bit4+Bit5+Bit6+Bit7)
#define SPIFLASH_REG_SPIFLASH_MISC_CTRL_CTL_SPI_FLASH_ADDR_LENGTH_MASK                           (Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_SPIFLASH_MISC_CTRL_CTL_SPI_FLASH_ADDR_LENGTH_SHIFT                          (4)
#define SPIFLASH_REG_SPIFLASH_MISC_CTRL_CTL_SPI_WAIT_CYCLE                                       (Bit8+Bit9+Bit10+Bit11)
#define SPIFLASH_REG_SPIFLASH_MISC_CTRL_CTL_SPI_WAIT_CYCLE_MASK                                  (Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_SPIFLASH_MISC_CTRL_CTL_SPI_WAIT_CYCLE_SHIFT                                 (8)
#define SPIFLASH_REG_SPIFLASH_MISC_CTRL_CTL_SPI_TRANS_TYPE                                       (Bit12+Bit13)
#define SPIFLASH_REG_SPIFLASH_MISC_CTRL_CTL_SPI_TRANS_TYPE_MASK                                  (Bit1+Bit0)
#define SPIFLASH_REG_SPIFLASH_MISC_CTRL_CTL_SPI_TRANS_TYPE_SHIFT                                 (12)
#define SPIFLASH_REG_SPIFLASH_MISC_CTRL_CTL_SPI_FLASH_ADDR_SRC                                   (Bit16)
#define SPIFLASH_REG_SPIFLASH_MISC_CTRL_CTL_INTR_RESET                                           (Bit20)


#define SPIFLASH_REG_SPIFLASH_ADDR_OFFSET                                                        (SPIFLASH_REG_BASE + 0x28)
#define SPIFLASH_REG_SPIFLASH_ADDR_OFFSET_DEFAULT                                                0x0
#define SPIFLASH_REG_SPIFLASH_ADDR_OFFSET_CTL_SPI_FLASH_ADDR_OFFSET                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define SPIFLASH_REG_SPIFLASH_ADDR_OFFSET_CTL_SPI_FLASH_ADDR_OFFSET_MASK                         (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_SPIFLASH_ADDR_OFFSET_CTL_SPI_FLASH_ADDR_OFFSET_SHIFT                        (0)


#define SPIFLASH_REG_SPIFLASH_CONT_MODE_CTRL                                                     (SPIFLASH_REG_BASE + 0x2c)
#define SPIFLASH_REG_SPIFLASH_CONT_MODE_CTRL_DEFAULT                                             0x0
#define SPIFLASH_REG_SPIFLASH_CONT_MODE_CTRL_CTL_SPIFLASH_CONT_MODE_BYTE                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define SPIFLASH_REG_SPIFLASH_CONT_MODE_CTRL_CTL_SPIFLASH_CONT_MODE_BYTE_MASK                    (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_SPIFLASH_CONT_MODE_CTRL_CTL_SPIFLASH_CONT_MODE_BYTE_SHIFT                   (0)
#define SPIFLASH_REG_SPIFLASH_CONT_MODE_CTRL_CTL_SPIFLASH_ATTACH_CONT_MODE_BYTE                  (Bit8)


#define SPIFLASH_REG_SPIFLASH_INSTRUCTION                                                        (SPIFLASH_REG_BASE + 0x30)
#define SPIFLASH_REG_SPIFLASH_INSTRUCTION_DEFAULT                                                0x0
#define SPIFLASH_REG_SPIFLASH_INSTRUCTION_CTL_SPI_FLASH_INSTRUCTION                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define SPIFLASH_REG_SPIFLASH_INSTRUCTION_CTL_SPI_FLASH_INSTRUCTION_MASK                         (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_SPIFLASH_INSTRUCTION_CTL_SPI_FLASH_INSTRUCTION_SHIFT                        (0)


#define SPIFLASH_REG_SPIFLASH_SLV_SEL                                                            (SPIFLASH_REG_BASE + 0x40)
#define SPIFLASH_REG_SPIFLASH_SLV_SEL_DEFAULT                                                    0x0
#define SPIFLASH_REG_SPIFLASH_SLV_SEL_CTL_SPI_FLASH_SLAVE_SEL                                    (Bit0+Bit1+Bit2+Bit3)
#define SPIFLASH_REG_SPIFLASH_SLV_SEL_CTL_SPI_FLASH_SLAVE_SEL_MASK                               (Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_SPIFLASH_SLV_SEL_CTL_SPI_FLASH_SLAVE_SEL_SHIFT                              (0)


#define SPIFLASH_REG_SPI_FLASH_RD_ADDR                                                           (SPIFLASH_REG_BASE + 0x60)
#define SPIFLASH_REG_SPI_FLASH_RD_ADDR_DEFAULT                                                   0x0
#define SPIFLASH_REG_SPI_FLASH_RD_ADDR_CTL_SPI_FLASH_RD_ADDR                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define SPIFLASH_REG_SPI_FLASH_RD_ADDR_CTL_SPI_FLASH_RD_ADDR_MASK                                (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_SPI_FLASH_RD_ADDR_CTL_SPI_FLASH_RD_ADDR_SHIFT                               (0)


#define SPIFLASH_REG_SPI_FLASH_CURR_RD_ADDR                                                      (SPIFLASH_REG_BASE + 0x64)
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_ADDR_DEFAULT                                              0x0
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_ADDR_STS_SPI_FLASH_CURR_RD_ADDR                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_ADDR_STS_SPI_FLASH_CURR_RD_ADDR_MASK                      (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_ADDR_STS_SPI_FLASH_CURR_RD_ADDR_SHIFT                     (0)


#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_0                                                     (SPIFLASH_REG_BASE + 0x80)
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_0_DEFAULT                                             0x0
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_0_VALUE                                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_0_VALUE_MASK                                          (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_0_VALUE_SHIFT                                         (0)


#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_1                                                     (SPIFLASH_REG_BASE + 0x84)
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_1_DEFAULT                                             0x0
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_1_VALUE                                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_1_VALUE_MASK                                          (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_1_VALUE_SHIFT                                         (0)


#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_2                                                     (SPIFLASH_REG_BASE + 0x88)
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_2_DEFAULT                                             0x0
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_2_VALUE                                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_2_VALUE_MASK                                          (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_2_VALUE_SHIFT                                         (0)


#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_3                                                     (SPIFLASH_REG_BASE + 0x8c)
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_3_DEFAULT                                             0x0
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_3_VALUE                                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_3_VALUE_MASK                                          (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_SPI_FLASH_CURR_RD_VAL_3_VALUE_SHIFT                                         (0)


#define SPIFLASH_REG_SPI_FLASH_CNTR_STATE                                                        (SPIFLASH_REG_BASE + 0xa0)
#define SPIFLASH_REG_SPI_FLASH_CNTR_STATE_DEFAULT                                                0x0
#define SPIFLASH_REG_SPI_FLASH_CNTR_STATE_STS_SPI_FLASH_CNTR_FSM_STATE                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define SPIFLASH_REG_SPI_FLASH_CNTR_STATE_STS_SPI_FLASH_CNTR_FSM_STATE_MASK                      (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_SPI_FLASH_CNTR_STATE_STS_SPI_FLASH_CNTR_FSM_STATE_SHIFT                     (0)
#define SPIFLASH_REG_SPI_FLASH_CNTR_STATE_STS_SPI_FLASH_CNTR_APB_STATE                           (Bit8+Bit9+Bit10)
#define SPIFLASH_REG_SPI_FLASH_CNTR_STATE_STS_SPI_FLASH_CNTR_APB_STATE_MASK                      (Bit2+Bit1+Bit0)
#define SPIFLASH_REG_SPI_FLASH_CNTR_STATE_STS_SPI_FLASH_CNTR_APB_STATE_SHIFT                     (8)


#define SPIFLASH_REG_SSI_CLK_RATIO                                                               (SPIFLASH_REG_BASE + 0xb0)
#define SPIFLASH_REG_SSI_CLK_RATIO_DEFAULT                                                       0x0
#define SPIFLASH_REG_SSI_CLK_RATIO_CTL_SSI_2_D0_CLK_RATIO                                        (Bit0+Bit1)
#define SPIFLASH_REG_SSI_CLK_RATIO_CTL_SSI_2_D0_CLK_RATIO_MASK                                   (Bit1+Bit0)
#define SPIFLASH_REG_SSI_CLK_RATIO_CTL_SSI_2_D0_CLK_RATIO_SHIFT                                  (0)
#define SPIFLASH_REG_SSI_CLK_RATIO_CTL_SSI_2_CACHE_CLK_RATIO                                     (Bit4+Bit5)
#define SPIFLASH_REG_SSI_CLK_RATIO_CTL_SSI_2_CACHE_CLK_RATIO_MASK                                (Bit1+Bit0)
#define SPIFLASH_REG_SSI_CLK_RATIO_CTL_SSI_2_CACHE_CLK_RATIO_SHIFT                               (4)
#define SPIFLASH_REG_SSI_CLK_RATIO_CTL_SSI_2_D0_CLK_RATIO_MANUAL                                 (Bit8)
#define SPIFLASH_REG_SSI_CLK_RATIO_CTL_SSI_2_CACHE_CLK_RATIO_MANUAL                              (Bit9)
#define SPIFLASH_REG_SSI_CLK_RATIO_STS_SSI_2_D0_CLK_RATIO_AUTO                                   (Bit12+Bit13)
#define SPIFLASH_REG_SSI_CLK_RATIO_STS_SSI_2_D0_CLK_RATIO_AUTO_MASK                              (Bit1+Bit0)
#define SPIFLASH_REG_SSI_CLK_RATIO_STS_SSI_2_D0_CLK_RATIO_AUTO_SHIFT                             (12)
#define SPIFLASH_REG_SSI_CLK_RATIO_STS_SSI_2_CACHE_CLK_RATIO_AUTO                                (Bit16+Bit17)
#define SPIFLASH_REG_SSI_CLK_RATIO_STS_SSI_2_CACHE_CLK_RATIO_AUTO_MASK                           (Bit1+Bit0)
#define SPIFLASH_REG_SSI_CLK_RATIO_STS_SSI_2_CACHE_CLK_RATIO_AUTO_SHIFT                          (16)


#define SPIFLASH_REG_ICACHE_DEC_MISC_CTRL                                                        (SPIFLASH_REG_BASE + 0xc0)
#define SPIFLASH_REG_ICACHE_DEC_MISC_CTRL_DEFAULT                                                0x0
#define SPIFLASH_REG_ICACHE_DEC_MISC_CTRL_CTL_FLASH_DATA_ENC_EN                                  (Bit0)


#define SPIFLASH_REG_REG_ENC_MISC_CTRL                                                           (SPIFLASH_REG_BASE + 0xd0)
#define SPIFLASH_REG_REG_ENC_MISC_CTRL_DEFAULT                                                   0x0
#define SPIFLASH_REG_REG_ENC_MISC_CTRL_CTL_REG_ENC_DEC_EN                                        (Bit0)
#define SPIFLASH_REG_REG_ENC_MISC_CTRL_CTL_REG_ENC0DEC1                                          (Bit1)


#define SPIFLASH_REG_REG_ENC_ADDR                                                                (SPIFLASH_REG_BASE + 0xd4)
#define SPIFLASH_REG_REG_ENC_ADDR_DEFAULT                                                        0x0
#define SPIFLASH_REG_REG_ENC_ADDR_CTL_REG_ENC_INIT_ADDR                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define SPIFLASH_REG_REG_ENC_ADDR_CTL_REG_ENC_INIT_ADDR_MASK                                     (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_REG_ENC_ADDR_CTL_REG_ENC_INIT_ADDR_SHIFT                                    (0)


#define SPIFLASH_REG_REG_ENC_CURR_ADDR                                                           (SPIFLASH_REG_BASE + 0xd8)
#define SPIFLASH_REG_REG_ENC_CURR_ADDR_DEFAULT                                                   0x0
#define SPIFLASH_REG_REG_ENC_CURR_ADDR_STS_REG_ENC_CURR_ADDR                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define SPIFLASH_REG_REG_ENC_CURR_ADDR_STS_REG_ENC_CURR_ADDR_MASK                                (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_REG_ENC_CURR_ADDR_STS_REG_ENC_CURR_ADDR_SHIFT                               (0)


#define SPIFLASH_REG_REG_ENC_DEC_VAL                                                             (SPIFLASH_REG_BASE + 0xe0)
#define SPIFLASH_REG_REG_ENC_DEC_VAL_DEFAULT                                                     0x0
#define SPIFLASH_REG_REG_ENC_DEC_VAL_CTL_REG_ENC_DATA                                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define SPIFLASH_REG_REG_ENC_DEC_VAL_CTL_REG_ENC_DATA_MASK                                       (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_REG_ENC_DEC_VAL_CTL_REG_ENC_DATA_SHIFT                                      (0)


#define SPIFLASH_REG_REG_ENC_DEC_RESULT                                                          (SPIFLASH_REG_BASE + 0xe4)
#define SPIFLASH_REG_REG_ENC_DEC_RESULT_DEFAULT                                                  0x0
#define SPIFLASH_REG_REG_ENC_DEC_RESULT_STS_REG_ENC_RESULT                                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define SPIFLASH_REG_REG_ENC_DEC_RESULT_STS_REG_ENC_RESULT_MASK                                  (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SPIFLASH_REG_REG_ENC_DEC_RESULT_STS_REG_ENC_RESULT_SHIFT                                 (0)


#endif // _SPIFLASH_REG_DEFINES_H

