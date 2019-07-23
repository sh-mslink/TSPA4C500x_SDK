#ifndef _AUDIO_REGS_DEFINES_H
#define _AUDIO_REGS_DEFINES_H
/* **************************** */
#define AUDIO_REGS_INTR_STATUS                                                 (AUDIO_REGS_BASE + 0x0)
#define AUDIO_REGS_INTR_STATUS_DEFAULT                                         0x0
#define AUDIO_REGS_INTR_STATUS_INTR                                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define AUDIO_REGS_INTR_STATUS_INTR_MASK                                       (Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_INTR_STATUS_INTR_SHIFT                                      (0)


#define AUDIO_REGS_INTR_MASK_STATUS                                            (AUDIO_REGS_BASE + 0x4)
#define AUDIO_REGS_INTR_MASK_STATUS_DEFAULT                                    0x0
#define AUDIO_REGS_INTR_MASK_STATUS_INTR                                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define AUDIO_REGS_INTR_MASK_STATUS_INTR_MASK                                  (Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_INTR_MASK_STATUS_INTR_SHIFT                                 (0)


#define AUDIO_REGS_INTR_CLEAR                                                  (AUDIO_REGS_BASE + 0x8)
#define AUDIO_REGS_INTR_CLEAR_DEFAULT                                          0x0
#define AUDIO_REGS_INTR_CLEAR_INTR                                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define AUDIO_REGS_INTR_CLEAR_INTR_MASK                                        (Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_INTR_CLEAR_INTR_SHIFT                                       (0)


#define AUDIO_REGS_INTR_SET                                                    (AUDIO_REGS_BASE + 0xc)
#define AUDIO_REGS_INTR_SET_DEFAULT                                            0x0
#define AUDIO_REGS_INTR_SET_INTR                                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define AUDIO_REGS_INTR_SET_INTR_MASK                                          (Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_INTR_SET_INTR_SHIFT                                         (0)


#define AUDIO_REGS_INTR_MASK_SET                                               (AUDIO_REGS_BASE + 0x10)
#define AUDIO_REGS_INTR_MASK_SET_DEFAULT                                       0x0
#define AUDIO_REGS_INTR_MASK_SET_INTR                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define AUDIO_REGS_INTR_MASK_SET_INTR_MASK                                     (Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_INTR_MASK_SET_INTR_SHIFT                                    (0)


#define AUDIO_REGS_INTR_MASK_CLEAR                                             (AUDIO_REGS_BASE + 0x14)
#define AUDIO_REGS_INTR_MASK_CLEAR_DEFAULT                                     0x0
#define AUDIO_REGS_INTR_MASK_CLEAR_INTR                                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define AUDIO_REGS_INTR_MASK_CLEAR_INTR_MASK                                   (Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_INTR_MASK_CLEAR_INTR_SHIFT                                  (0)


#define AUDIO_REGS_MISC_CTRL0                                                  (AUDIO_REGS_BASE + 0x40)
#define AUDIO_REGS_MISC_CTRL0_DEFAULT                                          0x1E000
#define AUDIO_REGS_MISC_CTRL0_CTLT_AURX_SRESET                                 (Bit0)
#define AUDIO_REGS_MISC_CTRL0_CTLT_AENC_EN                                     (Bit1)
#define AUDIO_REGS_MISC_CTRL0_CTLT_AENC_RESTART                                (Bit2)
#define AUDIO_REGS_MISC_CTRL0_CTLT_ADEC_EN                                     (Bit3)
#define AUDIO_REGS_MISC_CTRL0_CTLT_ADEC_RESTART                                (Bit4)
#define AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_SRESET                                 (Bit5)
#define AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_SRESET_SPK                             (Bit6)
#define AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_OUT_EN                                 (Bit7)
#define AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_AFIFO_EN_WR                            (Bit8)
#define AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_AFIFO_EN_RD                            (Bit9)
#define AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_RFB_EN                                 (Bit10)
#define AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_RFB_SRESET                             (Bit11)
#define AUDIO_REGS_MISC_CTRL0_CTLT_AUTX_SDM_EN                                 (Bit12)
#define AUDIO_REGS_MISC_CTRL0_CTLQ_AURX_STEREO                                 (Bit13)
#define AUDIO_REGS_MISC_CTRL0_CTLQ_AENC_STEREO                                 (Bit14)
#define AUDIO_REGS_MISC_CTRL0_CTLQ_ADEC_STEREO                                 (Bit15)
#define AUDIO_REGS_MISC_CTRL0_CTLQ_AUTX_STEREO                                 (Bit16)
#define AUDIO_REGS_MISC_CTRL0_CTLQ_AUTX_I2SM_SEL                               (Bit17)
#define AUDIO_REGS_MISC_CTRL0_CTLQ_AUTX_I2SS_SEL                               (Bit18)
#define AUDIO_REGS_MISC_CTRL0_CTLT_PDM_EN                                      (Bit19)
#define AUDIO_REGS_MISC_CTRL0_CTLT_PDM_CLEAR                                   (Bit20)
#define AUDIO_REGS_MISC_CTRL0_CTLT_PDM_CLK_EN                                  (Bit21)
#define AUDIO_REGS_MISC_CTRL0_CTLT_INTR_SRESET                                 (Bit24)


#define AUDIO_REGS_AURX_CTRL0                                                  (AUDIO_REGS_BASE + 0x44)
#define AUDIO_REGS_AURX_CTRL0_DEFAULT                                          0xA027109
#define AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_I2S_BYP                                (Bit0)
#define AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_IN_FORMAT                              (Bit1)
#define AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_CIC_DEC                                (Bit2+Bit3+Bit4)
#define AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_CIC_DEC_MASK                           (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_CIC_DEC_SHIFT                          (2)
#define AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_DC_OFF                                 (Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22)
#define AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_DC_OFF_MASK                            (Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_DC_OFF_SHIFT                           (5)
#define AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_CIC_SHIFT                              (Bit23+Bit24+Bit25+Bit26)
#define AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_CIC_SHIFT_MASK                         (Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_CIC_SHIFT_SHIFT                        (23)
#define AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_I2S_SHIFT                              (Bit27+Bit28+Bit29)
#define AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_I2S_SHIFT_MASK                         (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_I2S_SHIFT_SHIFT                        (27)
#define AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_I2S_SLAVE                              (Bit30)
#define AUDIO_REGS_AURX_CTRL0_CTLQ_AURX_I2S_D5                                 (Bit31)


#define AUDIO_REGS_AURX_CTRL1                                                  (AUDIO_REGS_BASE + 0x48)
#define AUDIO_REGS_AURX_CTRL1_DEFAULT                                          0x31004064
#define AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_ITP_PER                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6)
#define AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_ITP_PER_MASK                           (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_ITP_PER_SHIFT                          (0)
#define AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_LPF2_DEC                               (Bit7)
#define AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_GAINL                                  (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_GAINL_MASK                             (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_GAINL_SHIFT                            (8)
#define AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_GAINR                                  (Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_GAINR_MASK                             (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_GAINR_SHIFT                            (18)
#define AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_I2S_DEL                                (Bit28+Bit29+Bit30)
#define AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_I2S_DEL_MASK                           (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AURX_CTRL1_CTLQ_AURX_I2S_DEL_SHIFT                          (28)


#define AUDIO_REGS_AENC_CTRL0                                                  (AUDIO_REGS_BASE + 0x4c)
#define AUDIO_REGS_AENC_CTRL0_DEFAULT                                          0x31E0FDA
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_PKT_FIFO_TH                            (Bit0+Bit1+Bit2)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_PKT_FIFO_TH_MASK                       (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_PKT_FIFO_TH_SHIFT                      (0)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_SIZE                                   (Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_SIZE_MASK                              (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_SIZE_SHIFT                             (3)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_MODE                                   (Bit14+Bit15)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_MODE_MASK                              (Bit1+Bit0)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_MODE_SHIFT                             (14)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_FSAMPPREDIC                            (Bit17)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_SKIP_FSAMP                             (Bit18)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_PREDIC_END                             (Bit19)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_LSB4FIRST                              (Bit20)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_APPLEPREDIC                            (Bit21)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_RST_STEPIDX                            (Bit22)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_RST_PREDICT                            (Bit23)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_WR_PRIORITY                            (Bit24+Bit25+Bit26+Bit27)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_WR_PRIORITY_MASK                       (Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AENC_CTRL0_CTLQ_AENC_WR_PRIORITY_SHIFT                      (24)


#define AUDIO_REGS_AENC_CTRL1                                                  (AUDIO_REGS_BASE + 0x50)
#define AUDIO_REGS_AENC_CTRL1_DEFAULT                                          0x7FF
#define AUDIO_REGS_AENC_CTRL1_CTLQ_AENC_MAX_ADDR                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10)
#define AUDIO_REGS_AENC_CTRL1_CTLQ_AENC_MAX_ADDR_MASK                          (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AENC_CTRL1_CTLQ_AENC_MAX_ADDR_SHIFT                         (0)


#define AUDIO_REGS_AENC_STAT0                                                  (AUDIO_REGS_BASE + 0x54)
#define AUDIO_REGS_AENC_STAT0_DEFAULT                                          0x0
#define AUDIO_REGS_AENC_STAT0_STS_AENC_PKT_FIFO_FILL                           (Bit0+Bit1+Bit2+Bit3)
#define AUDIO_REGS_AENC_STAT0_STS_AENC_PKT_FIFO_FILL_MASK                      (Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AENC_STAT0_STS_AENC_PKT_FIFO_FILL_SHIFT                     (0)
#define AUDIO_REGS_AENC_STAT0_STS_AENC_DMA_FIFO_RPTR                           (Bit4+Bit5+Bit6)
#define AUDIO_REGS_AENC_STAT0_STS_AENC_DMA_FIFO_RPTR_MASK                      (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AENC_STAT0_STS_AENC_DMA_FIFO_RPTR_SHIFT                     (4)
#define AUDIO_REGS_AENC_STAT0_STS_AENC_DMA_FIFO_WPTR                           (Bit8+Bit9+Bit10)
#define AUDIO_REGS_AENC_STAT0_STS_AENC_DMA_FIFO_WPTR_MASK                      (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AENC_STAT0_STS_AENC_DMA_FIFO_WPTR_SHIFT                     (8)
#define AUDIO_REGS_AENC_STAT0_STS_AENC_PK_STATE                                (Bit12+Bit13+Bit14)
#define AUDIO_REGS_AENC_STAT0_STS_AENC_PK_STATE_MASK                           (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AENC_STAT0_STS_AENC_PK_STATE_SHIFT                          (12)
#define AUDIO_REGS_AENC_STAT0_STS_AENC_IN_STATE                                (Bit16+Bit17+Bit18)
#define AUDIO_REGS_AENC_STAT0_STS_AENC_IN_STATE_MASK                           (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AENC_STAT0_STS_AENC_IN_STATE_SHIFT                          (16)


#define AUDIO_REGS_ADEC_CTRL0                                                  (AUDIO_REGS_BASE + 0x58)
#define AUDIO_REGS_ADEC_CTRL0_DEFAULT                                          0x3FF9C1FB
#define AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_SIZE                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10)
#define AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_SIZE_MASK                              (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_SIZE_SHIFT                             (0)
#define AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_MODE                                   (Bit12+Bit13)
#define AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_MODE_MASK                              (Bit1+Bit0)
#define AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_MODE_SHIFT                             (12)
#define AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_PREDICFSAMP                            (Bit14)
#define AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_PREDIC_END                             (Bit15)
#define AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_LSB4FIRST                              (Bit16)
#define AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_RST_STEPIDX                            (Bit17)
#define AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_RST_PREDICT                            (Bit18)
#define AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_MAX_ADDR                               (Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_MAX_ADDR_MASK                          (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_ADEC_CTRL0_CTLQ_ADEC_MAX_ADDR_SHIFT                         (19)


#define AUDIO_REGS_ADEC_CTRL1                                                  (AUDIO_REGS_BASE + 0x5c)
#define AUDIO_REGS_ADEC_CTRL1_DEFAULT                                          0x7F81000
#define AUDIO_REGS_ADEC_CTRL1_CTLQ_ADEC_RD_PRIORITY                            (Bit10+Bit11+Bit12+Bit13)
#define AUDIO_REGS_ADEC_CTRL1_CTLQ_ADEC_RD_PRIORITY_MASK                       (Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_ADEC_CTRL1_CTLQ_ADEC_RD_PRIORITY_SHIFT                      (10)
#define AUDIO_REGS_ADEC_CTRL1_CTLQ_ADEC_DMA_REQ_LIM                            (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AUDIO_REGS_ADEC_CTRL1_CTLQ_ADEC_DMA_REQ_LIM_MASK                       (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_ADEC_CTRL1_CTLQ_ADEC_DMA_REQ_LIM_SHIFT                      (16)


#define AUDIO_REGS_ADEC_STAT0                                                  (AUDIO_REGS_BASE + 0x60)
#define AUDIO_REGS_ADEC_STAT0_DEFAULT                                          0x0
#define AUDIO_REGS_ADEC_STAT0_STS_ADEC_PCM_READING                             (Bit12)
#define AUDIO_REGS_ADEC_STAT0_STS_ADEC_PK_STATE                                (Bit13+Bit14+Bit15)
#define AUDIO_REGS_ADEC_STAT0_STS_ADEC_PK_STATE_MASK                           (Bit2+Bit1+Bit0)
#define AUDIO_REGS_ADEC_STAT0_STS_ADEC_PK_STATE_SHIFT                          (13)
#define AUDIO_REGS_ADEC_STAT0_STS_ADEC_IN_STATE                                (Bit16+Bit17+Bit18)
#define AUDIO_REGS_ADEC_STAT0_STS_ADEC_IN_STATE_MASK                           (Bit2+Bit1+Bit0)
#define AUDIO_REGS_ADEC_STAT0_STS_ADEC_IN_STATE_SHIFT                          (16)


#define AUDIO_REGS_AUTX_CTRL0                                                  (AUDIO_REGS_BASE + 0x64)
#define AUDIO_REGS_AUTX_CTRL0_DEFAULT                                          0xE0A6298
#define AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO32_BYP_LPF                        (Bit0)
#define AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO32_BYP_UP2                        (Bit1)
#define AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO32_PER                            (Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO32_PER_MASK                       (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO32_PER_SHIFT                      (2)
#define AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO64_BYP_LPF                        (Bit12)
#define AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO64_PER                            (Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO64_PER_MASK                       (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO64_PER_SHIFT                      (13)
#define AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO128_BYP_LPF                       (Bit22)
#define AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO128_PER                           (Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30)
#define AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO128_PER_MASK                      (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_ITPTO128_PER_SHIFT                     (23)
#define AUDIO_REGS_AUTX_CTRL0_CTLQ_AUTX_SEL_IN                                 (Bit31)


#define AUDIO_REGS_AUTX_CTRL1                                                  (AUDIO_REGS_BASE + 0x68)
#define AUDIO_REGS_AUTX_CTRL1_DEFAULT                                          0x100000
#define AUDIO_REGS_AUTX_CTRL1_CTLQ_AUTX_VID_NOMRATE                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22)
#define AUDIO_REGS_AUTX_CTRL1_CTLQ_AUTX_VID_NOMRATE_MASK                       (Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_CTRL1_CTLQ_AUTX_VID_NOMRATE_SHIFT                      (0)


#define AUDIO_REGS_AUTX_CTRL2                                                  (AUDIO_REGS_BASE + 0x6c)
#define AUDIO_REGS_AUTX_CTRL2_DEFAULT                                          0x8001000
#define AUDIO_REGS_AUTX_CTRL2_CTLQ_AUTX_VID_INVRATE                            (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12)
#define AUDIO_REGS_AUTX_CTRL2_CTLQ_AUTX_VID_INVRATE_MASK                       (Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_CTRL2_CTLQ_AUTX_VID_INVRATE_SHIFT                      (0)
#define AUDIO_REGS_AUTX_CTRL2_CTLQ_AUTX_GAINR                                  (Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define AUDIO_REGS_AUTX_CTRL2_CTLQ_AUTX_GAINR_MASK                             (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_CTRL2_CTLQ_AUTX_GAINR_SHIFT                            (22)


#define AUDIO_REGS_AUTX_CTRL3                                                  (AUDIO_REGS_BASE + 0x70)
#define AUDIO_REGS_AUTX_CTRL3_DEFAULT                                          0x200400
#define AUDIO_REGS_AUTX_CTRL3_CTLT_AUTX_OUT_PER                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define AUDIO_REGS_AUTX_CTRL3_CTLT_AUTX_OUT_PER_MASK                           (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_CTRL3_CTLT_AUTX_OUT_PER_SHIFT                          (0)
#define AUDIO_REGS_AUTX_CTRL3_CTLT_AUTX_AFIFO_SNAP                             (Bit8)
#define AUDIO_REGS_AUTX_CTRL3_CTLQ_AUTX_AFIFO_READ_START                       (Bit9+Bit10+Bit11)
#define AUDIO_REGS_AUTX_CTRL3_CTLQ_AUTX_AFIFO_READ_START_MASK                  (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_CTRL3_CTLQ_AUTX_AFIFO_READ_START_SHIFT                 (9)
#define AUDIO_REGS_AUTX_CTRL3_CTLQ_AUTX_AFIFO_KEEP_READ                        (Bit12)
#define AUDIO_REGS_AUTX_CTRL3_CTLT_AUTX_AFIFO_CLEAR_FLOW                       (Bit13)
#define AUDIO_REGS_AUTX_CTRL3_CTLQ_AUTX_GAINL                                  (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25)
#define AUDIO_REGS_AUTX_CTRL3_CTLQ_AUTX_GAINL_MASK                             (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_CTRL3_CTLQ_AUTX_GAINL_SHIFT                            (16)


#define AUDIO_REGS_AUTX_AFIFO_STAT0                                            (AUDIO_REGS_BASE + 0x74)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_DEFAULT                                    0x0
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_WR_PNT_RCK                  (Bit0+Bit1+Bit2+Bit3)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_WR_PNT_RCK_MASK             (Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_WR_PNT_RCK_SHIFT            (0)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_RD_PNT_RCK                  (Bit4+Bit5+Bit6+Bit7)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_RD_PNT_RCK_MASK             (Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_RD_PNT_RCK_SHIFT            (4)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_WR_PNT_WCK                  (Bit8+Bit9+Bit10+Bit11)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_WR_PNT_WCK_MASK             (Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_WR_PNT_WCK_SHIFT            (8)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_RD_PNT_WCK                  (Bit12+Bit13+Bit14+Bit15)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_RD_PNT_WCK_MASK             (Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_RD_PNT_WCK_SHIFT            (12)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_FILL_RCK                    (Bit16+Bit17+Bit18+Bit19)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_FILL_RCK_MASK               (Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_FILL_RCK_SHIFT              (16)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_OVERFLOW                    (Bit20)
#define AUDIO_REGS_AUTX_AFIFO_STAT0_STS_AUTX_AFIFO_UNDERFLOW                   (Bit21)


#define AUDIO_REGS_AUTX_RFB_CTRL0                                              (AUDIO_REGS_BASE + 0x78)
#define AUDIO_REGS_AUTX_RFB_CTRL0_DEFAULT                                      0xCC8C6A3
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_TARGET_LEN                     (Bit0+Bit1+Bit2+Bit3)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_TARGET_LEN_MASK                (Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_TARGET_LEN_SHIFT               (0)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_PLOOP_DC                       (Bit4+Bit5+Bit6+Bit7)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_PLOOP_DC_MASK                  (Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_PLOOP_DC_SHIFT                 (4)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_LOOPBW                         (Bit8+Bit9+Bit10)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_LOOPBW_MASK                    (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_LOOPBW_SHIFT                   (8)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DIF_MAF                        (Bit11+Bit12+Bit13)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DIF_MAF_MASK                   (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DIF_MAF_SHIFT                  (11)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DIF_GAIN_LO                    (Bit14+Bit15+Bit16)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DIF_GAIN_LO_MASK               (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DIF_GAIN_LO_SHIFT              (14)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DIF_GAIN_HI                    (Bit17+Bit18+Bit19)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DIF_GAIN_HI_MASK               (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DIF_GAIN_HI_SHIFT              (17)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DIF_GAIN_DEL                   (Bit20+Bit21+Bit22)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DIF_GAIN_DEL_MASK              (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DIF_GAIN_DEL_SHIFT             (20)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DC_DEC                         (Bit23+Bit24+Bit25)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DC_DEC_MASK                    (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DC_DEC_SHIFT                   (23)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DC_MAF                         (Bit26+Bit27+Bit28)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DC_MAF_MASK                    (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_RFB_CTRL0_CTLQ_AUTX_RFB_DC_MAF_SHIFT                   (26)


#define AUDIO_REGS_AUTX_RFB_CTRL1                                              (AUDIO_REGS_BASE + 0x7c)
#define AUDIO_REGS_AUTX_RFB_CTRL1_DEFAULT                                      0x319
#define AUDIO_REGS_AUTX_RFB_CTRL1_CTLQ_AUTX_RFB_DC_GAIN_LO                     (Bit0+Bit1+Bit2)
#define AUDIO_REGS_AUTX_RFB_CTRL1_CTLQ_AUTX_RFB_DC_GAIN_LO_MASK                (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_RFB_CTRL1_CTLQ_AUTX_RFB_DC_GAIN_LO_SHIFT               (0)
#define AUDIO_REGS_AUTX_RFB_CTRL1_CTLQ_AUTX_RFB_DC_GAIN_HI                     (Bit3+Bit4+Bit5)
#define AUDIO_REGS_AUTX_RFB_CTRL1_CTLQ_AUTX_RFB_DC_GAIN_HI_MASK                (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_RFB_CTRL1_CTLQ_AUTX_RFB_DC_GAIN_HI_SHIFT               (3)
#define AUDIO_REGS_AUTX_RFB_CTRL1_CTLQ_AUTX_RFB_DC_FB_DIS                      (Bit6)
#define AUDIO_REGS_AUTX_RFB_CTRL1_CTLQ_AUTX_RFB_ACC_MAF                        (Bit7+Bit8+Bit9)
#define AUDIO_REGS_AUTX_RFB_CTRL1_CTLQ_AUTX_RFB_ACC_MAF_MASK                   (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_RFB_CTRL1_CTLQ_AUTX_RFB_ACC_MAF_SHIFT                  (7)
#define AUDIO_REGS_AUTX_RFB_CTRL1_CTLT_AUTX_RFB_FREEZE_STAT                    (Bit10)


#define AUDIO_REGS_AUTX_RFB_STAT0                                              (AUDIO_REGS_BASE + 0x80)
#define AUDIO_REGS_AUTX_RFB_STAT0_DEFAULT                                      0x0
#define AUDIO_REGS_AUTX_RFB_STAT0_STS_AUTX_RFB_AVG_DC                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define AUDIO_REGS_AUTX_RFB_STAT0_STS_AUTX_RFB_AVG_DC_MASK                     (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_RFB_STAT0_STS_AUTX_RFB_AVG_DC_SHIFT                    (0)
#define AUDIO_REGS_AUTX_RFB_STAT0_STS_AUTX_RFB_AVG_DIF                         (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26)
#define AUDIO_REGS_AUTX_RFB_STAT0_STS_AUTX_RFB_AVG_DIF_MASK                    (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_RFB_STAT0_STS_AUTX_RFB_AVG_DIF_SHIFT                   (16)


#define AUDIO_REGS_AUTX_RFB_STAT1                                              (AUDIO_REGS_BASE + 0x84)
#define AUDIO_REGS_AUTX_RFB_STAT1_DEFAULT                                      0x0
#define AUDIO_REGS_AUTX_RFB_STAT1_STS_AUTX_RFB_ILOOP                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22)
#define AUDIO_REGS_AUTX_RFB_STAT1_STS_AUTX_RFB_ILOOP_MASK                      (Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_RFB_STAT1_STS_AUTX_RFB_ILOOP_SHIFT                     (0)


#define AUDIO_REGS_AUTX_RFB_STAT2                                              (AUDIO_REGS_BASE + 0x88)
#define AUDIO_REGS_AUTX_RFB_STAT2_DEFAULT                                      0x0
#define AUDIO_REGS_AUTX_RFB_STAT2_STS_AUTX_RFB_FB_RATE                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define AUDIO_REGS_AUTX_RFB_STAT2_STS_AUTX_RFB_FB_RATE_MASK                    (Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_RFB_STAT2_STS_AUTX_RFB_FB_RATE_SHIFT                   (0)


#define AUDIO_REGS_AUTX_SDM_CTRL0                                              (AUDIO_REGS_BASE + 0x8c)
#define AUDIO_REGS_AUTX_SDM_CTRL0_DEFAULT                                      0x11030
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_SDM_DITHER_GAIN                    (Bit0+Bit1)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_SDM_DITHER_GAIN_MASK               (Bit1+Bit0)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_SDM_DITHER_GAIN_SHIFT              (0)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_SDM_DITHER_ORDER                   (Bit2+Bit3)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_SDM_DITHER_ORDER_MASK              (Bit1+Bit0)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_SDM_DITHER_ORDER_SHIFT             (2)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_SDM_MOD_INDEX                      (Bit4+Bit5)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_SDM_MOD_INDEX_MASK                 (Bit1+Bit0)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_SDM_MOD_INDEX_SHIFT                (4)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_SDM_MUX_SEL                        (Bit6+Bit7)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_SDM_MUX_SEL_MASK                   (Bit1+Bit0)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_SDM_MUX_SEL_SHIFT                  (6)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_SDITP128_PER                       (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_SDITP128_PER_MASK                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_SDITP128_PER_SHIFT                 (8)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_CIC_ITP_PER                        (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_CIC_ITP_PER_MASK                   (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_CIC_ITP_PER_SHIFT                  (16)
#define AUDIO_REGS_AUTX_SDM_CTRL0_CTLQ_AUTX_SDITP128_BYP                       (Bit24)


#define AUDIO_REGS_AUTX_SDM_STAT0                                              (AUDIO_REGS_BASE + 0x90)
#define AUDIO_REGS_AUTX_SDM_STAT0_DEFAULT                                      0x0
#define AUDIO_REGS_AUTX_SDM_STAT0_STS_AUTX_SDM_MUX_OUT_L                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14)
#define AUDIO_REGS_AUTX_SDM_STAT0_STS_AUTX_SDM_MUX_OUT_L_MASK                  (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_SDM_STAT0_STS_AUTX_SDM_MUX_OUT_L_SHIFT                 (0)
#define AUDIO_REGS_AUTX_SDM_STAT0_STS_AUTX_SDM_MUX_OUT_R                       (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30)
#define AUDIO_REGS_AUTX_SDM_STAT0_STS_AUTX_SDM_MUX_OUT_R_MASK                  (Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_SDM_STAT0_STS_AUTX_SDM_MUX_OUT_R_SHIFT                 (16)


#define AUDIO_REGS_ADEC_RATE_CTRL0                                             (AUDIO_REGS_BASE + 0x94)
#define AUDIO_REGS_ADEC_RATE_CTRL0_DEFAULT                                     0x103E8
#define AUDIO_REGS_ADEC_RATE_CTRL0_CTLQ_ADEC_PCM_FREQ_DEN                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AUDIO_REGS_ADEC_RATE_CTRL0_CTLQ_ADEC_PCM_FREQ_DEN_MASK                 (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_ADEC_RATE_CTRL0_CTLQ_ADEC_PCM_FREQ_DEN_SHIFT                (0)
#define AUDIO_REGS_ADEC_RATE_CTRL0_CTLQ_ADEC_PCM_FREQ_NUM                      (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define AUDIO_REGS_ADEC_RATE_CTRL0_CTLQ_ADEC_PCM_FREQ_NUM_MASK                 (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_ADEC_RATE_CTRL0_CTLQ_ADEC_PCM_FREQ_NUM_SHIFT                (16)


#define AUDIO_REGS_ADEC_DMA_CTRL0                                              (AUDIO_REGS_BASE + 0xc0)
#define AUDIO_REGS_ADEC_DMA_CTRL0_DEFAULT                                      0x0
#define AUDIO_REGS_ADEC_DMA_CTRL0_CTLQ_REG_DMA_RD_ACK                          (Bit0)
#define AUDIO_REGS_ADEC_DMA_CTRL0_CTLQ_REG_DMA_WR_ACK                          (Bit1)


#define AUDIO_REGS_ADEC_DMA_STAT0                                              (AUDIO_REGS_BASE + 0xc4)
#define AUDIO_REGS_ADEC_DMA_STAT0_DEFAULT                                      0x0
#define AUDIO_REGS_ADEC_DMA_STAT0_STS_ADEC_BYTES_IN_RAM                        (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define AUDIO_REGS_ADEC_DMA_STAT0_STS_ADEC_BYTES_IN_RAM_MASK                   (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_ADEC_DMA_STAT0_STS_ADEC_BYTES_IN_RAM_SHIFT                  (0)
#define AUDIO_REGS_ADEC_DMA_STAT0_STS_AENC_DMA_RD_REQ                          (Bit12)
#define AUDIO_REGS_ADEC_DMA_STAT0_STS_AENC_DMA_RD_ACK                          (Bit13)
#define AUDIO_REGS_ADEC_DMA_STAT0_STS_ADEC_DMA_FIFO_FULL                       (Bit14)
#define AUDIO_REGS_ADEC_DMA_STAT0_STS_AENC_BYTES_IN_RAM                        (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27)
#define AUDIO_REGS_ADEC_DMA_STAT0_STS_AENC_BYTES_IN_RAM_MASK                   (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_ADEC_DMA_STAT0_STS_AENC_BYTES_IN_RAM_SHIFT                  (16)
#define AUDIO_REGS_ADEC_DMA_STAT0_STS_ADEC_DMA_WR_REQ                          (Bit28)
#define AUDIO_REGS_ADEC_DMA_STAT0_STS_ADEC_DMA_WR_ACK                          (Bit29)
#define AUDIO_REGS_ADEC_DMA_STAT0_STS_AENC_DMA_FIFO_FULL                       (Bit30)


#define AUDIO_REGS_DMA_READ                                                    (AUDIO_REGS_BASE + 0xc8)
#define AUDIO_REGS_DMA_READ_DEFAULT                                            0x0
#define AUDIO_REGS_DMA_READ_DMA_RD_DAT                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define AUDIO_REGS_DMA_READ_DMA_RD_DAT_MASK                                    (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_DMA_READ_DMA_RD_DAT_SHIFT                                   (0)


#define AUDIO_REGS_ADEC_DMA_WRITE                                              (AUDIO_REGS_BASE + 0xcc)
#define AUDIO_REGS_ADEC_DMA_WRITE_DEFAULT                                      0x0
#define AUDIO_REGS_ADEC_DMA_WRITE_DMA_WR_DAT                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define AUDIO_REGS_ADEC_DMA_WRITE_DMA_WR_DAT_MASK                              (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_ADEC_DMA_WRITE_DMA_WR_DAT_SHIFT                             (0)


#define AUDIO_REGS_PDM_CTRL0                                                   (AUDIO_REGS_BASE + 0xd0)
#define AUDIO_REGS_PDM_CTRL0_DEFAULT                                           0x3010203F
#define AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_PERIOD                                   (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_PERIOD_MASK                              (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_PERIOD_SHIFT                             (0)
#define AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_FALL                                     (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_FALL_MASK                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_FALL_SHIFT                               (8)
#define AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_LCNT                                     (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_LCNT_MASK                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_LCNT_SHIFT                               (16)
#define AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_RCNT                                     (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_RCNT_MASK                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_PDM_CTRL0_CTLQ_PDM_RCNT_SHIFT                               (24)


#define AUDIO_REGS_PDM_CTRL1                                                   (AUDIO_REGS_BASE + 0xd4)
#define AUDIO_REGS_PDM_CTRL1_DEFAULT                                           0x31
#define AUDIO_REGS_PDM_CTRL1_CTLQ_PDM_VCNT                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define AUDIO_REGS_PDM_CTRL1_CTLQ_PDM_VCNT_MASK                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_PDM_CTRL1_CTLQ_PDM_VCNT_SHIFT                               (0)
#define AUDIO_REGS_PDM_CTRL1_CTLQ_PDM_LSEL                                     (Bit8)
#define AUDIO_REGS_PDM_CTRL1_CTLQ_PDM_RSEL                                     (Bit9)


#define AUDIO_REGS_AUTX_SM_CTRL0                                               (AUDIO_REGS_BASE + 0xd8)
#define AUDIO_REGS_AUTX_SM_CTRL0_DEFAULT                                       0x7FF10
#define AUDIO_REGS_AUTX_SM_CTRL0_CTLQ_SM_DMA_RD_SEL                            (Bit0)
#define AUDIO_REGS_AUTX_SM_CTRL0_CTLT_AUTX_SM_EN                               (Bit1)
#define AUDIO_REGS_AUTX_SM_CTRL0_CTLT_AUTX_SM_RESTART                          (Bit2)
#define AUDIO_REGS_AUTX_SM_CTRL0_CTLQ_AUTX_WR_PRIORITY                         (Bit4+Bit5)
#define AUDIO_REGS_AUTX_SM_CTRL0_CTLQ_AUTX_WR_PRIORITY_MASK                    (Bit1+Bit0)
#define AUDIO_REGS_AUTX_SM_CTRL0_CTLQ_AUTX_WR_PRIORITY_SHIFT                   (4)
#define AUDIO_REGS_AUTX_SM_CTRL0_CTLQ_AUTX_MAX_ADDR                            (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18)
#define AUDIO_REGS_AUTX_SM_CTRL0_CTLQ_AUTX_MAX_ADDR_MASK                       (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_SM_CTRL0_CTLQ_AUTX_MAX_ADDR_SHIFT                      (8)


#define AUDIO_REGS_AUTX_SM_STAT0                                               (AUDIO_REGS_BASE + 0xdc)
#define AUDIO_REGS_AUTX_SM_STAT0_DEFAULT                                       0x0
#define AUDIO_REGS_AUTX_SM_STAT0_STS_AUTX_RD_BUF_SAMPS                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define AUDIO_REGS_AUTX_SM_STAT0_STS_AUTX_RD_BUF_SAMPS_MASK                    (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_SM_STAT0_STS_AUTX_RD_BUF_SAMPS_SHIFT                   (0)
#define AUDIO_REGS_AUTX_SM_STAT0_STS_AUTX_PKT_FIFO_FILL                        (Bit12+Bit13+Bit14)
#define AUDIO_REGS_AUTX_SM_STAT0_STS_AUTX_PKT_FIFO_FILL_MASK                   (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_SM_STAT0_STS_AUTX_PKT_FIFO_FILL_SHIFT                  (12)
#define AUDIO_REGS_AUTX_SM_STAT0_STS_AUTX_DMA_FIFO_FILL                        (Bit16+Bit17+Bit18+Bit19+Bit20)
#define AUDIO_REGS_AUTX_SM_STAT0_STS_AUTX_DMA_FIFO_FILL_MASK                   (Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_SM_STAT0_STS_AUTX_DMA_FIFO_FILL_SHIFT                  (16)


#define AUDIO_REGS_AUTX_WRSM_CTRL0                                             (AUDIO_REGS_BASE + 0xe0)
#define AUDIO_REGS_AUTX_WRSM_CTRL0_DEFAULT                                     0x7F8FFE50
#define AUDIO_REGS_AUTX_WRSM_CTRL0_CTLQ_SM_DMA_WR_SEL                          (Bit0)
#define AUDIO_REGS_AUTX_WRSM_CTRL0_CTLT_WRSM_EN                                (Bit1)
#define AUDIO_REGS_AUTX_WRSM_CTRL0_CTLT_WRSM_RESTART                           (Bit2)
#define AUDIO_REGS_AUTX_WRSM_CTRL0_CTLT_WRSM_PULL_EN                           (Bit3)
#define AUDIO_REGS_AUTX_WRSM_CTRL0_CTLQ_WRSM_PULL_START_LIM                    (Bit4+Bit5)
#define AUDIO_REGS_AUTX_WRSM_CTRL0_CTLQ_WRSM_PULL_START_LIM_MASK               (Bit1+Bit0)
#define AUDIO_REGS_AUTX_WRSM_CTRL0_CTLQ_WRSM_PULL_START_LIM_SHIFT              (4)
#define AUDIO_REGS_AUTX_WRSM_CTRL0_CTLT_WRSM_RD_PRIORITY                       (Bit6+Bit7+Bit8)
#define AUDIO_REGS_AUTX_WRSM_CTRL0_CTLT_WRSM_RD_PRIORITY_MASK                  (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_WRSM_CTRL0_CTLT_WRSM_RD_PRIORITY_SHIFT                 (6)
#define AUDIO_REGS_AUTX_WRSM_CTRL0_CTLT_WRSM_MAX_ADDR                          (Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define AUDIO_REGS_AUTX_WRSM_CTRL0_CTLT_WRSM_MAX_ADDR_MASK                     (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_WRSM_CTRL0_CTLT_WRSM_MAX_ADDR_SHIFT                    (9)
#define AUDIO_REGS_AUTX_WRSM_CTRL0_CTLQ_WRSM_DMA_REQ_LIM                       (Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30)
#define AUDIO_REGS_AUTX_WRSM_CTRL0_CTLQ_WRSM_DMA_REQ_LIM_MASK                  (Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_WRSM_CTRL0_CTLQ_WRSM_DMA_REQ_LIM_SHIFT                 (20)


#define AUDIO_REGS_AUTX_WRSM_CTRL1                                             (AUDIO_REGS_BASE + 0xe4)
#define AUDIO_REGS_AUTX_WRSM_CTRL1_DEFAULT                                     0x303E8
#define AUDIO_REGS_AUTX_WRSM_CTRL1_CTLQ_WRSM_PULL_DEN                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AUDIO_REGS_AUTX_WRSM_CTRL1_CTLQ_WRSM_PULL_DEN_MASK                     (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_WRSM_CTRL1_CTLQ_WRSM_PULL_DEN_SHIFT                    (0)
#define AUDIO_REGS_AUTX_WRSM_CTRL1_CTLQ_WRSM_PULL_NUM                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define AUDIO_REGS_AUTX_WRSM_CTRL1_CTLQ_WRSM_PULL_NUM_MASK                     (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_WRSM_CTRL1_CTLQ_WRSM_PULL_NUM_SHIFT                    (16)


#define AUDIO_REGS_AUTX_WRSM_STAT0                                             (AUDIO_REGS_BASE + 0xe8)
#define AUDIO_REGS_AUTX_WRSM_STAT0_DEFAULT                                     0x0
#define AUDIO_REGS_AUTX_WRSM_STAT0_STS_AUTX_WR_BUF_SAMPS                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11)
#define AUDIO_REGS_AUTX_WRSM_STAT0_STS_AUTX_WR_BUF_SAMPS_MASK                  (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_WRSM_STAT0_STS_AUTX_WR_BUF_SAMPS_SHIFT                 (0)
#define AUDIO_REGS_AUTX_WRSM_STAT0_STS_WRSM_DMAFIFO_WFILL                      (Bit12+Bit13+Bit14+Bit15)
#define AUDIO_REGS_AUTX_WRSM_STAT0_STS_WRSM_DMAFIFO_WFILL_MASK                 (Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_WRSM_STAT0_STS_WRSM_DMAFIFO_WFILL_SHIFT                (12)
#define AUDIO_REGS_AUTX_WRSM_STAT0_STS_WRSM_OUTFIFO_FILL                       (Bit16+Bit17+Bit18)
#define AUDIO_REGS_AUTX_WRSM_STAT0_STS_WRSM_OUTFIFO_FILL_MASK                  (Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_WRSM_STAT0_STS_WRSM_OUTFIFO_FILL_SHIFT                 (16)
#define AUDIO_REGS_AUTX_WRSM_STAT0_STS_WRSM_SAMPS_IN_MEM                       (Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define AUDIO_REGS_AUTX_WRSM_STAT0_STS_WRSM_SAMPS_IN_MEM_MASK                  (Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AUDIO_REGS_AUTX_WRSM_STAT0_STS_WRSM_SAMPS_IN_MEM_SHIFT                 (20)


#endif // _AUDIO_REGS_DEFINES_H

