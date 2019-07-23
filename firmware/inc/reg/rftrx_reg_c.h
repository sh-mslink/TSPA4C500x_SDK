#ifndef _RFTRX_REG_DEFINES_H
#define _RFTRX_REG_DEFINES_H
/* **************************** */
#define RFTRX_REG_CPLL_REG_1TO4                                                              (RFTRX_REG_BASE + 0x80)
#define RFTRX_REG_CPLL_REG_1TO4_DEFAULT                                                      0xCD94490
#define RFTRX_REG_CPLL_REG_1TO4_REG1                                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_CPLL_REG_1TO4_REG1_MASK                                                    (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_CPLL_REG_1TO4_REG1_SHIFT                                                   (0)
#define RFTRX_REG_CPLL_REG_1TO4_REG2                                                         (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_CPLL_REG_1TO4_REG2_MASK                                                    (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_CPLL_REG_1TO4_REG2_SHIFT                                                   (8)
#define RFTRX_REG_CPLL_REG_1TO4_REG3                                                         (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_CPLL_REG_1TO4_REG3_MASK                                                    (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_CPLL_REG_1TO4_REG3_SHIFT                                                   (16)
#define RFTRX_REG_CPLL_REG_1TO4_REG4                                                         (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RFTRX_REG_CPLL_REG_1TO4_REG4_MASK                                                    (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_CPLL_REG_1TO4_REG4_SHIFT                                                   (24)


#define RFTRX_REG_CPLL_REG_5TO6                                                              (RFTRX_REG_BASE + 0x84)
#define RFTRX_REG_CPLL_REG_5TO6_DEFAULT                                                      0x4C00
#define RFTRX_REG_CPLL_REG_5TO6_REG5                                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_CPLL_REG_5TO6_REG5_MASK                                                    (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_CPLL_REG_5TO6_REG5_SHIFT                                                   (0)
#define RFTRX_REG_CPLL_REG_5TO6_REG6                                                         (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_CPLL_REG_5TO6_REG6_MASK                                                    (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_CPLL_REG_5TO6_REG6_SHIFT                                                   (8)


#define RFTRX_REG_CPLL_REG_1TO3_1M                                                           (RFTRX_REG_BASE + 0x88)
#define RFTRX_REG_CPLL_REG_1TO3_1M_DEFAULT                                                   0x5944D0
#define RFTRX_REG_CPLL_REG_1TO3_1M_REG1                                                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_CPLL_REG_1TO3_1M_REG1_MASK                                                 (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_CPLL_REG_1TO3_1M_REG1_SHIFT                                                (0)
#define RFTRX_REG_CPLL_REG_1TO3_1M_REG2                                                      (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_CPLL_REG_1TO3_1M_REG2_MASK                                                 (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_CPLL_REG_1TO3_1M_REG2_SHIFT                                                (8)
#define RFTRX_REG_CPLL_REG_1TO3_1M_REG3                                                      (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_CPLL_REG_1TO3_1M_REG3_MASK                                                 (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_CPLL_REG_1TO3_1M_REG3_SHIFT                                                (16)


#define RFTRX_REG_MPLL_2P4_REG_5TO8                                                          (RFTRX_REG_BASE + 0x90)
#define RFTRX_REG_MPLL_2P4_REG_5TO8_DEFAULT                                                  0x3B841710
#define RFTRX_REG_MPLL_2P4_REG_5TO8_REG5                                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_MPLL_2P4_REG_5TO8_REG5_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_2P4_REG_5TO8_REG5_SHIFT                                               (0)
#define RFTRX_REG_MPLL_2P4_REG_5TO8_REG6                                                     (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_MPLL_2P4_REG_5TO8_REG6_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_2P4_REG_5TO8_REG6_SHIFT                                               (8)
#define RFTRX_REG_MPLL_2P4_REG_5TO8_REG7                                                     (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_MPLL_2P4_REG_5TO8_REG7_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_2P4_REG_5TO8_REG7_SHIFT                                               (16)
#define RFTRX_REG_MPLL_2P4_REG_5TO8_REG8                                                     (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RFTRX_REG_MPLL_2P4_REG_5TO8_REG8_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_2P4_REG_5TO8_REG8_SHIFT                                               (24)


#define RFTRX_REG_MPLL_2P4_REG_9TO12                                                         (RFTRX_REG_BASE + 0x94)
#define RFTRX_REG_MPLL_2P4_REG_9TO12_DEFAULT                                                 0x800D814A
#define RFTRX_REG_MPLL_2P4_REG_9TO12_REG9                                                    (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_MPLL_2P4_REG_9TO12_REG9_MASK                                               (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_2P4_REG_9TO12_REG9_SHIFT                                              (0)
#define RFTRX_REG_MPLL_2P4_REG_9TO12_REG10                                                   (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_MPLL_2P4_REG_9TO12_REG10_MASK                                              (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_2P4_REG_9TO12_REG10_SHIFT                                             (8)
#define RFTRX_REG_MPLL_2P4_REG_9TO12_REG11                                                   (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_MPLL_2P4_REG_9TO12_REG11_MASK                                              (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_2P4_REG_9TO12_REG11_SHIFT                                             (16)
#define RFTRX_REG_MPLL_2P4_REG_9TO12_REG12                                                   (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RFTRX_REG_MPLL_2P4_REG_9TO12_REG12_MASK                                              (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_2P4_REG_9TO12_REG12_SHIFT                                             (24)


#define RFTRX_REG_MPLL_2P4_REG_13TO14                                                        (RFTRX_REG_BASE + 0x98)
#define RFTRX_REG_MPLL_2P4_REG_13TO14_DEFAULT                                                0x4A22
#define RFTRX_REG_MPLL_2P4_REG_13TO14_REG13                                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_MPLL_2P4_REG_13TO14_REG13_MASK                                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_2P4_REG_13TO14_REG13_SHIFT                                            (0)
#define RFTRX_REG_MPLL_2P4_REG_13TO14_REG14                                                  (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_MPLL_2P4_REG_13TO14_REG14_MASK                                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_2P4_REG_13TO14_REG14_SHIFT                                            (8)


#define RFTRX_REG_MPLL_5P8_REG_5TO8                                                          (RFTRX_REG_BASE + 0xa0)
#define RFTRX_REG_MPLL_5P8_REG_5TO8_DEFAULT                                                  0x3B84170C
#define RFTRX_REG_MPLL_5P8_REG_5TO8_REG5                                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_MPLL_5P8_REG_5TO8_REG5_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_5P8_REG_5TO8_REG5_SHIFT                                               (0)
#define RFTRX_REG_MPLL_5P8_REG_5TO8_REG6                                                     (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_MPLL_5P8_REG_5TO8_REG6_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_5P8_REG_5TO8_REG6_SHIFT                                               (8)
#define RFTRX_REG_MPLL_5P8_REG_5TO8_REG7                                                     (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_MPLL_5P8_REG_5TO8_REG7_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_5P8_REG_5TO8_REG7_SHIFT                                               (16)
#define RFTRX_REG_MPLL_5P8_REG_5TO8_REG8                                                     (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RFTRX_REG_MPLL_5P8_REG_5TO8_REG8_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_5P8_REG_5TO8_REG8_SHIFT                                               (24)


#define RFTRX_REG_MPLL_5P8_REG_9TO12                                                         (RFTRX_REG_BASE + 0xa4)
#define RFTRX_REG_MPLL_5P8_REG_9TO12_DEFAULT                                                 0x80128144
#define RFTRX_REG_MPLL_5P8_REG_9TO12_REG9                                                    (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_MPLL_5P8_REG_9TO12_REG9_MASK                                               (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_5P8_REG_9TO12_REG9_SHIFT                                              (0)
#define RFTRX_REG_MPLL_5P8_REG_9TO12_REG10                                                   (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_MPLL_5P8_REG_9TO12_REG10_MASK                                              (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_5P8_REG_9TO12_REG10_SHIFT                                             (8)
#define RFTRX_REG_MPLL_5P8_REG_9TO12_REG11                                                   (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_MPLL_5P8_REG_9TO12_REG11_MASK                                              (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_5P8_REG_9TO12_REG11_SHIFT                                             (16)
#define RFTRX_REG_MPLL_5P8_REG_9TO12_REG12                                                   (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RFTRX_REG_MPLL_5P8_REG_9TO12_REG12_MASK                                              (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_5P8_REG_9TO12_REG12_SHIFT                                             (24)


#define RFTRX_REG_MPLL_5P8_REG_13TO14                                                        (RFTRX_REG_BASE + 0xa8)
#define RFTRX_REG_MPLL_5P8_REG_13TO14_DEFAULT                                                0x4888
#define RFTRX_REG_MPLL_5P8_REG_13TO14_REG13                                                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_MPLL_5P8_REG_13TO14_REG13_MASK                                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_5P8_REG_13TO14_REG13_SHIFT                                            (0)
#define RFTRX_REG_MPLL_5P8_REG_13TO14_REG14                                                  (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_MPLL_5P8_REG_13TO14_REG14_MASK                                             (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_5P8_REG_13TO14_REG14_SHIFT                                            (8)


#define RFTRX_REG_MPLL_REG_9_2M                                                              (RFTRX_REG_BASE + 0xac)
#define RFTRX_REG_MPLL_REG_9_2M_DEFAULT                                                      0x44CE
#define RFTRX_REG_MPLL_REG_9_2M_2P4_REG9                                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_MPLL_REG_9_2M_2P4_REG9_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_REG_9_2M_2P4_REG9_SHIFT                                               (0)
#define RFTRX_REG_MPLL_REG_9_2M_5P8_REG9                                                     (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_MPLL_REG_9_2M_5P8_REG9_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_REG_9_2M_5P8_REG9_SHIFT                                               (8)


#define RFTRX_REG_RX_2P4_REG_1TO4                                                            (RFTRX_REG_BASE + 0xb4)
#define RFTRX_REG_RX_2P4_REG_1TO4_DEFAULT                                                    0x700CFF5C
#define RFTRX_REG_RX_2P4_REG_1TO4_REG1                                                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_RX_2P4_REG_1TO4_REG1_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_2P4_REG_1TO4_REG1_SHIFT                                                 (0)
#define RFTRX_REG_RX_2P4_REG_1TO4_REG2                                                       (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_RX_2P4_REG_1TO4_REG2_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_2P4_REG_1TO4_REG2_SHIFT                                                 (8)
#define RFTRX_REG_RX_2P4_REG_1TO4_REG3                                                       (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_RX_2P4_REG_1TO4_REG3_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_2P4_REG_1TO4_REG3_SHIFT                                                 (16)
#define RFTRX_REG_RX_2P4_REG_1TO4_REG4                                                       (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RFTRX_REG_RX_2P4_REG_1TO4_REG4_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_2P4_REG_1TO4_REG4_SHIFT                                                 (24)


#define RFTRX_REG_RX_2P4_REG_5TO8                                                            (RFTRX_REG_BASE + 0xb8)
#define RFTRX_REG_RX_2P4_REG_5TO8_DEFAULT                                                    0x6000
#define RFTRX_REG_RX_2P4_REG_5TO8_REG5                                                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_RX_2P4_REG_5TO8_REG5_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_2P4_REG_5TO8_REG5_SHIFT                                                 (0)
#define RFTRX_REG_RX_2P4_REG_5TO8_REG6                                                       (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_RX_2P4_REG_5TO8_REG6_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_2P4_REG_5TO8_REG6_SHIFT                                                 (8)
#define RFTRX_REG_RX_2P4_REG_5TO8_REG7                                                       (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_RX_2P4_REG_5TO8_REG7_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_2P4_REG_5TO8_REG7_SHIFT                                                 (16)
#define RFTRX_REG_RX_2P4_REG_5TO8_REG8                                                       (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RFTRX_REG_RX_2P4_REG_5TO8_REG8_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_2P4_REG_5TO8_REG8_SHIFT                                                 (24)


#define RFTRX_REG_RX_5P8_REG_1TO4                                                            (RFTRX_REG_BASE + 0xbc)
#define RFTRX_REG_RX_5P8_REG_1TO4_DEFAULT                                                    0x100FF5C
#define RFTRX_REG_RX_5P8_REG_1TO4_REG1                                                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_RX_5P8_REG_1TO4_REG1_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_5P8_REG_1TO4_REG1_SHIFT                                                 (0)
#define RFTRX_REG_RX_5P8_REG_1TO4_REG2                                                       (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_RX_5P8_REG_1TO4_REG2_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_5P8_REG_1TO4_REG2_SHIFT                                                 (8)
#define RFTRX_REG_RX_5P8_REG_1TO4_REG3                                                       (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_RX_5P8_REG_1TO4_REG3_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_5P8_REG_1TO4_REG3_SHIFT                                                 (16)
#define RFTRX_REG_RX_5P8_REG_1TO4_REG4                                                       (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RFTRX_REG_RX_5P8_REG_1TO4_REG4_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_5P8_REG_1TO4_REG4_SHIFT                                                 (24)


#define RFTRX_REG_RX_5P8_REG_5TO8                                                            (RFTRX_REG_BASE + 0xc0)
#define RFTRX_REG_RX_5P8_REG_5TO8_DEFAULT                                                    0x0
#define RFTRX_REG_RX_5P8_REG_5TO8_REG5                                                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_RX_5P8_REG_5TO8_REG5_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_5P8_REG_5TO8_REG5_SHIFT                                                 (0)
#define RFTRX_REG_RX_5P8_REG_5TO8_REG6                                                       (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_RX_5P8_REG_5TO8_REG6_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_5P8_REG_5TO8_REG6_SHIFT                                                 (8)
#define RFTRX_REG_RX_5P8_REG_5TO8_REG7                                                       (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_RX_5P8_REG_5TO8_REG7_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_5P8_REG_5TO8_REG7_SHIFT                                                 (16)
#define RFTRX_REG_RX_5P8_REG_5TO8_REG8                                                       (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RFTRX_REG_RX_5P8_REG_5TO8_REG8_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_5P8_REG_5TO8_REG8_SHIFT                                                 (24)


#define RFTRX_REG_RX_REG_3_2M                                                                (RFTRX_REG_BASE + 0xc4)
#define RFTRX_REG_RX_REG_3_2M_DEFAULT                                                        0x0
#define RFTRX_REG_RX_REG_3_2M_2P4_REG3                                                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_RX_REG_3_2M_2P4_REG3_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_REG_3_2M_2P4_REG3_SHIFT                                                 (0)
#define RFTRX_REG_RX_REG_3_2M_5P8_REG3                                                       (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_RX_REG_3_2M_5P8_REG3_MASK                                                  (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_REG_3_2M_5P8_REG3_SHIFT                                                 (8)


#define RFTRX_REG_TX_REG                                                                     (RFTRX_REG_BASE + 0xd0)
#define RFTRX_REG_TX_REG_DEFAULT                                                             0x7F007F
#define RFTRX_REG_TX_REG_TX_2P4_REG1                                                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_TX_REG_TX_2P4_REG1_MASK                                                    (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_TX_REG_TX_2P4_REG1_SHIFT                                                   (0)
#define RFTRX_REG_TX_REG_TX_2P4_REG2                                                         (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_TX_REG_TX_2P4_REG2_MASK                                                    (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_TX_REG_TX_2P4_REG2_SHIFT                                                   (8)
#define RFTRX_REG_TX_REG_TX_5P8_REG1                                                         (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_TX_REG_TX_5P8_REG1_MASK                                                    (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_TX_REG_TX_5P8_REG1_SHIFT                                                   (16)
#define RFTRX_REG_TX_REG_TX_5P8_REG2                                                         (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RFTRX_REG_TX_REG_TX_5P8_REG2_MASK                                                    (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_TX_REG_TX_5P8_REG2_SHIFT                                                   (24)


#define RFTRX_REG_SDADC_REG_1TO4_1M                                                          (RFTRX_REG_BASE + 0xe0)
#define RFTRX_REG_SDADC_REG_1TO4_1M_DEFAULT                                                  0x5588A2
#define RFTRX_REG_SDADC_REG_1TO4_1M_REG1                                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_SDADC_REG_1TO4_1M_REG1_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_1TO4_1M_REG1_SHIFT                                               (0)
#define RFTRX_REG_SDADC_REG_1TO4_1M_REG2                                                     (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_SDADC_REG_1TO4_1M_REG2_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_1TO4_1M_REG2_SHIFT                                               (8)
#define RFTRX_REG_SDADC_REG_1TO4_1M_REG3                                                     (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_SDADC_REG_1TO4_1M_REG3_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_1TO4_1M_REG3_SHIFT                                               (16)
#define RFTRX_REG_SDADC_REG_1TO4_1M_REG4                                                     (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RFTRX_REG_SDADC_REG_1TO4_1M_REG4_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_1TO4_1M_REG4_SHIFT                                               (24)


#define RFTRX_REG_SDADC_REG_1TO4_2M                                                          (RFTRX_REG_BASE + 0xe4)
#define RFTRX_REG_SDADC_REG_1TO4_2M_DEFAULT                                                  0xCCEEA2
#define RFTRX_REG_SDADC_REG_1TO4_2M_REG1                                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_SDADC_REG_1TO4_2M_REG1_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_1TO4_2M_REG1_SHIFT                                               (0)
#define RFTRX_REG_SDADC_REG_1TO4_2M_REG2                                                     (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_SDADC_REG_1TO4_2M_REG2_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_1TO4_2M_REG2_SHIFT                                               (8)
#define RFTRX_REG_SDADC_REG_1TO4_2M_REG3                                                     (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_SDADC_REG_1TO4_2M_REG3_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_1TO4_2M_REG3_SHIFT                                               (16)
#define RFTRX_REG_SDADC_REG_1TO4_2M_REG4                                                     (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RFTRX_REG_SDADC_REG_1TO4_2M_REG4_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_1TO4_2M_REG4_SHIFT                                               (24)


#define RFTRX_REG_SDADC_REG_5TO8_1M                                                          (RFTRX_REG_BASE + 0xe8)
#define RFTRX_REG_SDADC_REG_5TO8_1M_DEFAULT                                                  0x759CF0F0
#define RFTRX_REG_SDADC_REG_5TO8_1M_REG5                                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_SDADC_REG_5TO8_1M_REG5_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_5TO8_1M_REG5_SHIFT                                               (0)
#define RFTRX_REG_SDADC_REG_5TO8_1M_REG6                                                     (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_SDADC_REG_5TO8_1M_REG6_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_5TO8_1M_REG6_SHIFT                                               (8)
#define RFTRX_REG_SDADC_REG_5TO8_1M_REG7                                                     (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_SDADC_REG_5TO8_1M_REG7_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_5TO8_1M_REG7_SHIFT                                               (16)
#define RFTRX_REG_SDADC_REG_5TO8_1M_REG8                                                     (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RFTRX_REG_SDADC_REG_5TO8_1M_REG8_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_5TO8_1M_REG8_SHIFT                                               (24)


#define RFTRX_REG_SDADC_REG_5TO8_2M                                                          (RFTRX_REG_BASE + 0xec)
#define RFTRX_REG_SDADC_REG_5TO8_2M_DEFAULT                                                  0x16387070
#define RFTRX_REG_SDADC_REG_5TO8_2M_REG5                                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_SDADC_REG_5TO8_2M_REG5_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_5TO8_2M_REG5_SHIFT                                               (0)
#define RFTRX_REG_SDADC_REG_5TO8_2M_REG6                                                     (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_SDADC_REG_5TO8_2M_REG6_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_5TO8_2M_REG6_SHIFT                                               (8)
#define RFTRX_REG_SDADC_REG_5TO8_2M_REG7                                                     (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_SDADC_REG_5TO8_2M_REG7_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_5TO8_2M_REG7_SHIFT                                               (16)
#define RFTRX_REG_SDADC_REG_5TO8_2M_REG8                                                     (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RFTRX_REG_SDADC_REG_5TO8_2M_REG8_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_5TO8_2M_REG8_SHIFT                                               (24)


#define RFTRX_REG_SDADC_REG_9TO12_1M                                                         (RFTRX_REG_BASE + 0xf0)
#define RFTRX_REG_SDADC_REG_9TO12_1M_DEFAULT                                                 0x76848484
#define RFTRX_REG_SDADC_REG_9TO12_1M_REG9                                                    (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_SDADC_REG_9TO12_1M_REG9_MASK                                               (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_9TO12_1M_REG9_SHIFT                                              (0)
#define RFTRX_REG_SDADC_REG_9TO12_1M_REG10                                                   (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_SDADC_REG_9TO12_1M_REG10_MASK                                              (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_9TO12_1M_REG10_SHIFT                                             (8)
#define RFTRX_REG_SDADC_REG_9TO12_1M_REG11                                                   (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_SDADC_REG_9TO12_1M_REG11_MASK                                              (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_9TO12_1M_REG11_SHIFT                                             (16)
#define RFTRX_REG_SDADC_REG_9TO12_1M_REG12                                                   (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RFTRX_REG_SDADC_REG_9TO12_1M_REG12_MASK                                              (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_9TO12_1M_REG12_SHIFT                                             (24)


#define RFTRX_REG_SDADC_REG_9TO12_2M                                                         (RFTRX_REG_BASE + 0xf4)
#define RFTRX_REG_SDADC_REG_9TO12_2M_DEFAULT                                                 0x32848484
#define RFTRX_REG_SDADC_REG_9TO12_2M_REG9                                                    (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_SDADC_REG_9TO12_2M_REG9_MASK                                               (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_9TO12_2M_REG9_SHIFT                                              (0)
#define RFTRX_REG_SDADC_REG_9TO12_2M_REG10                                                   (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_SDADC_REG_9TO12_2M_REG10_MASK                                              (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_9TO12_2M_REG10_SHIFT                                             (8)
#define RFTRX_REG_SDADC_REG_9TO12_2M_REG11                                                   (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_SDADC_REG_9TO12_2M_REG11_MASK                                              (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_9TO12_2M_REG11_SHIFT                                             (16)
#define RFTRX_REG_SDADC_REG_9TO12_2M_REG12                                                   (Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define RFTRX_REG_SDADC_REG_9TO12_2M_REG12_MASK                                              (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SDADC_REG_9TO12_2M_REG12_SHIFT                                             (24)


#define RFTRX_REG_AGC_REG                                                                    (RFTRX_REG_BASE + 0x100)
#define RFTRX_REG_AGC_REG_DEFAULT                                                            0x8A1002
#define RFTRX_REG_AGC_REG_REG1                                                               (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_AGC_REG_REG1_MASK                                                          (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_AGC_REG_REG1_SHIFT                                                         (0)
#define RFTRX_REG_AGC_REG_REG2                                                               (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_AGC_REG_REG2_MASK                                                          (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_AGC_REG_REG2_SHIFT                                                         (8)
#define RFTRX_REG_AGC_REG_REG3                                                               (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_AGC_REG_REG3_MASK                                                          (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_AGC_REG_REG3_SHIFT                                                         (16)


#define RFTRX_REG_RFTRX_TEST_MUX_CTRL                                                        (RFTRX_REG_BASE + 0x110)
#define RFTRX_REG_RFTRX_TEST_MUX_CTRL_DEFAULT                                                0x0
#define RFTRX_REG_RFTRX_TEST_MUX_CTRL_BLOCK                                                  (Bit0+Bit1+Bit2+Bit3)
#define RFTRX_REG_RFTRX_TEST_MUX_CTRL_BLOCK_MASK                                             (Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RFTRX_TEST_MUX_CTRL_BLOCK_SHIFT                                            (0)
#define RFTRX_REG_RFTRX_TEST_MUX_CTRL_SUBBLOCK                                               (Bit4+Bit5+Bit6)
#define RFTRX_REG_RFTRX_TEST_MUX_CTRL_SUBBLOCK_MASK                                          (Bit2+Bit1+Bit0)
#define RFTRX_REG_RFTRX_TEST_MUX_CTRL_SUBBLOCK_SHIFT                                         (4)
#define RFTRX_REG_RFTRX_TEST_MUX_CTRL_NODE                                                   (Bit8+Bit9+Bit10)
#define RFTRX_REG_RFTRX_TEST_MUX_CTRL_NODE_MASK                                              (Bit2+Bit1+Bit0)
#define RFTRX_REG_RFTRX_TEST_MUX_CTRL_NODE_SHIFT                                             (8)


#define RFTRX_REG_CPLL_STATUS                                                                (RFTRX_REG_BASE + 0x120)
#define RFTRX_REG_CPLL_STATUS_DEFAULT                                                        0x0
#define RFTRX_REG_CPLL_STATUS_STS_CPLL_LOCKED                                                (Bit0)


#define RFTRX_REG_MPLL_2P4_STATUS                                                            (RFTRX_REG_BASE + 0x128)
#define RFTRX_REG_MPLL_2P4_STATUS_DEFAULT                                                    0x0
#define RFTRX_REG_MPLL_2P4_STATUS_STS_MPLL_2P4_CAL_RESULT                                    (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define RFTRX_REG_MPLL_2P4_STATUS_STS_MPLL_2P4_CAL_RESULT_MASK                               (Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_2P4_STATUS_STS_MPLL_2P4_CAL_RESULT_SHIFT                              (0)
#define RFTRX_REG_MPLL_2P4_STATUS_STS_MPLL_2P4_CRSE_RESULT                                   (Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28)
#define RFTRX_REG_MPLL_2P4_STATUS_STS_MPLL_2P4_CRSE_RESULT_MASK                              (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_2P4_STATUS_STS_MPLL_2P4_CRSE_RESULT_SHIFT                             (20)
#define RFTRX_REG_MPLL_2P4_STATUS_STS_MPLL_2P4_LOCKED                                        (Bit31)


#define RFTRX_REG_MPLL_5P8_STATUS                                                            (RFTRX_REG_BASE + 0x130)
#define RFTRX_REG_MPLL_5P8_STATUS_DEFAULT                                                    0x0
#define RFTRX_REG_MPLL_5P8_STATUS_STS_MPLL_5P8_CAL_RESULT                                    (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19)
#define RFTRX_REG_MPLL_5P8_STATUS_STS_MPLL_5P8_CAL_RESULT_MASK                               (Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_5P8_STATUS_STS_MPLL_5P8_CAL_RESULT_SHIFT                              (0)
#define RFTRX_REG_MPLL_5P8_STATUS_STS_MPLL_5P8_CRSE_RESULT                                   (Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28)
#define RFTRX_REG_MPLL_5P8_STATUS_STS_MPLL_5P8_CRSE_RESULT_MASK                              (Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_5P8_STATUS_STS_MPLL_5P8_CRSE_RESULT_SHIFT                             (20)
#define RFTRX_REG_MPLL_5P8_STATUS_STS_MPLL_5P8_LOCKED                                        (Bit31)


#define RFTRX_REG_XO_STATUS                                                                  (RFTRX_REG_BASE + 0x138)
#define RFTRX_REG_XO_STATUS_DEFAULT                                                          0x0
#define RFTRX_REG_XO_STATUS_STS_XO_GT_TARGET                                                 (Bit0)
#define RFTRX_REG_XO_STATUS_STS_XO_STATUS                                                    (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9)
#define RFTRX_REG_XO_STATUS_STS_XO_STATUS_MASK                                               (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_XO_STATUS_STS_XO_STATUS_SHIFT                                              (4)


#define RFTRX_REG_RFTRX_MISC_CTRL                                                            (RFTRX_REG_BASE + 0x13c)
#define RFTRX_REG_RFTRX_MISC_CTRL_DEFAULT                                                    0x10
#define RFTRX_REG_RFTRX_MISC_CTRL_RX_CM_MEASURE_EN                                           (Bit0)
#define RFTRX_REG_RFTRX_MISC_CTRL_CTL_CLK_XO_X2_TO_DIGI_EN                                   (Bit4)
#define RFTRX_REG_RFTRX_MISC_CTRL_CTL_CLK_CPLL_TO_DIGI_EN                                    (Bit8)
#define RFTRX_REG_RFTRX_MISC_CTRL_CTL_CLK_CPLL_TO_SADC_EN_FORCE                              (Bit12)


#define RFTRX_REG_MPLL_2P4_REG_1TO4                                                          (RFTRX_REG_BASE + 0x140)
#define RFTRX_REG_MPLL_2P4_REG_1TO4_DEFAULT                                                  0x4B10000
#define RFTRX_REG_MPLL_2P4_REG_1TO4_REG1                                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_MPLL_2P4_REG_1TO4_REG1_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_2P4_REG_1TO4_REG1_SHIFT                                               (0)
#define RFTRX_REG_MPLL_2P4_REG_1TO4_REG2                                                     (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_MPLL_2P4_REG_1TO4_REG2_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_2P4_REG_1TO4_REG2_SHIFT                                               (8)
#define RFTRX_REG_MPLL_2P4_REG_1TO4_REG3                                                     (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_MPLL_2P4_REG_1TO4_REG3_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_2P4_REG_1TO4_REG3_SHIFT                                               (16)
#define RFTRX_REG_MPLL_2P4_REG_1TO4_REG4                                                     (Bit24+Bit25+Bit26+Bit27)
#define RFTRX_REG_MPLL_2P4_REG_1TO4_REG4_MASK                                                (Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_2P4_REG_1TO4_REG4_SHIFT                                               (24)


#define RFTRX_REG_MPLL_5P8_REG_1TO4                                                          (RFTRX_REG_BASE + 0x144)
#define RFTRX_REG_MPLL_5P8_REG_1TO4_DEFAULT                                                  0x0
#define RFTRX_REG_MPLL_5P8_REG_1TO4_REG1                                                     (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_MPLL_5P8_REG_1TO4_REG1_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_5P8_REG_1TO4_REG1_SHIFT                                               (0)
#define RFTRX_REG_MPLL_5P8_REG_1TO4_REG2                                                     (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_MPLL_5P8_REG_1TO4_REG2_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_5P8_REG_1TO4_REG2_SHIFT                                               (8)
#define RFTRX_REG_MPLL_5P8_REG_1TO4_REG3                                                     (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_MPLL_5P8_REG_1TO4_REG3_MASK                                                (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_5P8_REG_1TO4_REG3_SHIFT                                               (16)
#define RFTRX_REG_MPLL_5P8_REG_1TO4_REG4                                                     (Bit24+Bit25+Bit26+Bit27)
#define RFTRX_REG_MPLL_5P8_REG_1TO4_REG4_MASK                                                (Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_MPLL_5P8_REG_1TO4_REG4_SHIFT                                               (24)


#define RFTRX_REG_TRX_SPARE                                                                  (RFTRX_REG_BASE + 0x150)
#define RFTRX_REG_TRX_SPARE_DEFAULT                                                          0x0
#define RFTRX_REG_TRX_SPARE_STS_TRX_SPARE                                                    (Bit0+Bit1)
#define RFTRX_REG_TRX_SPARE_STS_TRX_SPARE_MASK                                               (Bit1+Bit0)
#define RFTRX_REG_TRX_SPARE_STS_TRX_SPARE_SHIFT                                              (0)


#define RFTRX_REG_PLL_TRIG_MISC_CTRL                                                         (RFTRX_REG_BASE + 0x180)
#define RFTRX_REG_PLL_TRIG_MISC_CTRL_DEFAULT                                                 0x1
#define RFTRX_REG_PLL_TRIG_MISC_CTRL_CTL_PLL_TRIG_ENABLE                                     (Bit0)
#define RFTRX_REG_PLL_TRIG_MISC_CTRL_CTL_PLL_TRIG_APB_ACCESS_ENABLE                          (Bit4)


#define RFTRX_REG_PLL_TRIG_MISC_STATUS                                                       (RFTRX_REG_BASE + 0x188)
#define RFTRX_REG_PLL_TRIG_MISC_STATUS_DEFAULT                                               0x0
#define RFTRX_REG_PLL_TRIG_MISC_STATUS_STS_PLL_TRIG_CURR_STATE                               (Bit0+Bit1)
#define RFTRX_REG_PLL_TRIG_MISC_STATUS_STS_PLL_TRIG_CURR_STATE_MASK                          (Bit1+Bit0)
#define RFTRX_REG_PLL_TRIG_MISC_STATUS_STS_PLL_TRIG_CURR_STATE_SHIFT                         (0)


#define RFTRX_REG_RX_2P4_PLL_TRIG_CTRL                                                       (RFTRX_REG_BASE + 0x1c0)
#define RFTRX_REG_RX_2P4_PLL_TRIG_CTRL_DEFAULT                                               0x10001
#define RFTRX_REG_RX_2P4_PLL_TRIG_CTRL_ENABLE                                                (Bit0)
#define RFTRX_REG_RX_2P4_PLL_TRIG_CTRL_BASE_ADDR                                             (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define RFTRX_REG_RX_2P4_PLL_TRIG_CTRL_BASE_ADDR_MASK                                        (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_2P4_PLL_TRIG_CTRL_BASE_ADDR_SHIFT                                       (4)
#define RFTRX_REG_RX_2P4_PLL_TRIG_CTRL_RIGHT_SHIFT                                           (Bit16)


#define RFTRX_REG_RX_5P8_PLL_TRIG_CTRL                                                       (RFTRX_REG_BASE + 0x1c8)
#define RFTRX_REG_RX_5P8_PLL_TRIG_CTRL_DEFAULT                                               0x10001
#define RFTRX_REG_RX_5P8_PLL_TRIG_CTRL_ENABLE                                                (Bit0)
#define RFTRX_REG_RX_5P8_PLL_TRIG_CTRL_BASE_ADDR                                             (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define RFTRX_REG_RX_5P8_PLL_TRIG_CTRL_BASE_ADDR_MASK                                        (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_RX_5P8_PLL_TRIG_CTRL_BASE_ADDR_SHIFT                                       (4)
#define RFTRX_REG_RX_5P8_PLL_TRIG_CTRL_RIGHT_SHIFT                                           (Bit16)


#define RFTRX_REG_TX_2P4_PLL_TRIG_CTRL                                                       (RFTRX_REG_BASE + 0x1d0)
#define RFTRX_REG_TX_2P4_PLL_TRIG_CTRL_DEFAULT                                               0x10801
#define RFTRX_REG_TX_2P4_PLL_TRIG_CTRL_ENABLE                                                (Bit0)
#define RFTRX_REG_TX_2P4_PLL_TRIG_CTRL_BASE_ADDR                                             (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define RFTRX_REG_TX_2P4_PLL_TRIG_CTRL_BASE_ADDR_MASK                                        (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_TX_2P4_PLL_TRIG_CTRL_BASE_ADDR_SHIFT                                       (4)
#define RFTRX_REG_TX_2P4_PLL_TRIG_CTRL_RIGHT_SHIFT                                           (Bit16)


#define RFTRX_REG_TX_5P8_PLL_TRIG_CTRL                                                       (RFTRX_REG_BASE + 0x1d8)
#define RFTRX_REG_TX_5P8_PLL_TRIG_CTRL_DEFAULT                                               0x10001
#define RFTRX_REG_TX_5P8_PLL_TRIG_CTRL_ENABLE                                                (Bit0)
#define RFTRX_REG_TX_5P8_PLL_TRIG_CTRL_BASE_ADDR                                             (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define RFTRX_REG_TX_5P8_PLL_TRIG_CTRL_BASE_ADDR_MASK                                        (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_TX_5P8_PLL_TRIG_CTRL_BASE_ADDR_SHIFT                                       (4)
#define RFTRX_REG_TX_5P8_PLL_TRIG_CTRL_RIGHT_SHIFT                                           (Bit16)


#define RFTRX_REG_SOFTWARE_PLL_TRIG_CTRL                                                     (RFTRX_REG_BASE + 0x1e0)
#define RFTRX_REG_SOFTWARE_PLL_TRIG_CTRL_DEFAULT                                             0x0
#define RFTRX_REG_SOFTWARE_PLL_TRIG_CTRL_ENABLE                                              (Bit0)
#define RFTRX_REG_SOFTWARE_PLL_TRIG_CTRL_BASE_ADDR                                           (Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define RFTRX_REG_SOFTWARE_PLL_TRIG_CTRL_BASE_ADDR_MASK                                      (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_SOFTWARE_PLL_TRIG_CTRL_BASE_ADDR_SHIFT                                     (4)
#define RFTRX_REG_SOFTWARE_PLL_TRIG_CTRL_TRIGGER                                             (Bit16)
#define RFTRX_REG_SOFTWARE_PLL_TRIG_CTRL_RATE                                                (Bit20)
#define RFTRX_REG_SOFTWARE_PLL_TRIG_CTRL_FREQ_BAND                                           (Bit21)
#define RFTRX_REG_SOFTWARE_PLL_TRIG_CTRL_TX_RX                                               (Bit22)


#define RFTRX_REG_TX_SCALE_HP_LP                                                             (RFTRX_REG_BASE + 0x1e8)
#define RFTRX_REG_TX_SCALE_HP_LP_DEFAULT                                                     0x809A80
#define RFTRX_REG_TX_SCALE_HP_LP_CTL_TX_SCALE_LP_1M                                          (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_TX_SCALE_HP_LP_CTL_TX_SCALE_LP_1M_MASK                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_TX_SCALE_HP_LP_CTL_TX_SCALE_LP_1M_SHIFT                                    (0)
#define RFTRX_REG_TX_SCALE_HP_LP_CTL_TX_SCALE_HP                                             (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define RFTRX_REG_TX_SCALE_HP_LP_CTL_TX_SCALE_HP_MASK                                        (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_TX_SCALE_HP_LP_CTL_TX_SCALE_HP_SHIFT                                       (8)
#define RFTRX_REG_TX_SCALE_HP_LP_CTL_TX_SCALE_LP_2M                                          (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23)
#define RFTRX_REG_TX_SCALE_HP_LP_CTL_TX_SCALE_LP_2M_MASK                                     (Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_TX_SCALE_HP_LP_CTL_TX_SCALE_LP_2M_SHIFT                                    (16)


#define RFTRX_REG_TRX_PLL_TRIG_MUX_CTRL                                                      (RFTRX_REG_BASE + 0x1ec)
#define RFTRX_REG_TRX_PLL_TRIG_MUX_CTRL_DEFAULT                                              0x1111
#define RFTRX_REG_TRX_PLL_TRIG_MUX_CTRL_CTL_TRIG_TO_CTRL_MPLL_FREQ                           (Bit0)
#define RFTRX_REG_TRX_PLL_TRIG_MUX_CTRL_CTL_TRIG_TO_CTRL_MPLL_VCO_BUF_LDO                    (Bit4)
#define RFTRX_REG_TRX_PLL_TRIG_MUX_CTRL_CTL_TRIG_TO_CTRL_TX_HP_SCALE_FACTOR                  (Bit8)
#define RFTRX_REG_TRX_PLL_TRIG_MUX_CTRL_CTL_TRIG_TO_CTRL_PA_GAIN                             (Bit12)


#define RFTRX_REG_EN_CPLL_NON_2M_RX                                                          (RFTRX_REG_BASE + 0x1f8)
#define RFTRX_REG_EN_CPLL_NON_2M_RX_DEFAULT                                                  0x0
#define RFTRX_REG_EN_CPLL_NON_2M_RX_CTL_EN_CPLL_NON_2M_RX                                    (Bit0)


#define RFTRX_REG_PMU_TRX_ID                                                                 (RFTRX_REG_BASE + 0x200)
#define RFTRX_REG_PMU_TRX_ID_DEFAULT                                                         0x0
#define RFTRX_REG_PMU_TRX_ID_STS_PMU_ID                                                      (Bit0+Bit1+Bit2+Bit3)
#define RFTRX_REG_PMU_TRX_ID_STS_PMU_ID_MASK                                                 (Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_PMU_TRX_ID_STS_PMU_ID_SHIFT                                                (0)
#define RFTRX_REG_PMU_TRX_ID_STS_TRX_ID                                                      (Bit4+Bit5+Bit6+Bit7)
#define RFTRX_REG_PMU_TRX_ID_STS_TRX_ID_MASK                                                 (Bit3+Bit2+Bit1+Bit0)
#define RFTRX_REG_PMU_TRX_ID_STS_TRX_ID_SHIFT                                                (4)


#endif // _RFTRX_REG_DEFINES_H

