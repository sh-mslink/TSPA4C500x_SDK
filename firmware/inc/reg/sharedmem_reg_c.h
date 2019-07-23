#ifndef _SHAREDMEM_REG_DEFINES_H
#define _SHAREDMEM_REG_DEFINES_H
/* **************************** */
#define SHAREDMEM_REG_MISC_CTRL                                             (SHAREDMEM_REG_BASE + 0x0)
#define SHAREDMEM_REG_MISC_CTRL_DEFAULT                                     0x2
#define SHAREDMEM_REG_MISC_CTRL_CTL_ENABLE                                  (Bit0)
#define SHAREDMEM_REG_MISC_CTRL_CTL_RDATA_VALID_IF_DISABLE                  (Bit1)


#define SHAREDMEM_REG_CLNT0_CTRL0                                           (SHAREDMEM_REG_BASE + 0x40)
#define SHAREDMEM_REG_CLNT0_CTRL0_DEFAULT                                   0x1
#define SHAREDMEM_REG_CLNT0_CTRL0_ENABLE                                    (Bit0)
#define SHAREDMEM_REG_CLNT0_CTRL0_ENABLE_PANIC                              (Bit4)
#define SHAREDMEM_REG_CLNT0_CTRL0_FORCE_PANIC                               (Bit5)
#define SHAREDMEM_REG_CLNT0_CTRL0_ADDR_OFFSET0                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define SHAREDMEM_REG_CLNT0_CTRL0_ADDR_OFFSET0_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT0_CTRL0_ADDR_OFFSET0_SHIFT                        (8)


#define SHAREDMEM_REG_CLNT0_CTRL1                                           (SHAREDMEM_REG_BASE + 0x44)
#define SHAREDMEM_REG_CLNT0_CTRL1_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT0_CTRL1_ADDR_OFFSET1                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT0_CTRL1_ADDR_OFFSET1_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT0_CTRL1_ADDR_OFFSET1_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT0_CTRL1_INNER_OFFSET1                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT0_CTRL1_INNER_OFFSET1_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT0_CTRL1_INNER_OFFSET1_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT0_CTRL2                                           (SHAREDMEM_REG_BASE + 0x48)
#define SHAREDMEM_REG_CLNT0_CTRL2_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT0_CTRL2_ADDR_OFFSET2                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT0_CTRL2_ADDR_OFFSET2_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT0_CTRL2_ADDR_OFFSET2_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT0_CTRL2_INNER_OFFSET2                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT0_CTRL2_INNER_OFFSET2_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT0_CTRL2_INNER_OFFSET2_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT1_CTRL0                                           (SHAREDMEM_REG_BASE + 0x50)
#define SHAREDMEM_REG_CLNT1_CTRL0_DEFAULT                                   0x1
#define SHAREDMEM_REG_CLNT1_CTRL0_ENABLE                                    (Bit0)
#define SHAREDMEM_REG_CLNT1_CTRL0_ENABLE_PANIC                              (Bit4)
#define SHAREDMEM_REG_CLNT1_CTRL0_FORCE_PANIC                               (Bit5)
#define SHAREDMEM_REG_CLNT1_CTRL0_ADDR_OFFSET0                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define SHAREDMEM_REG_CLNT1_CTRL0_ADDR_OFFSET0_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT1_CTRL0_ADDR_OFFSET0_SHIFT                        (8)


#define SHAREDMEM_REG_CLNT1_CTRL1                                           (SHAREDMEM_REG_BASE + 0x54)
#define SHAREDMEM_REG_CLNT1_CTRL1_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT1_CTRL1_ADDR_OFFSET1                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT1_CTRL1_ADDR_OFFSET1_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT1_CTRL1_ADDR_OFFSET1_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT1_CTRL1_INNER_OFFSET1                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT1_CTRL1_INNER_OFFSET1_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT1_CTRL1_INNER_OFFSET1_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT1_CTRL2                                           (SHAREDMEM_REG_BASE + 0x58)
#define SHAREDMEM_REG_CLNT1_CTRL2_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT1_CTRL2_ADDR_OFFSET2                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT1_CTRL2_ADDR_OFFSET2_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT1_CTRL2_ADDR_OFFSET2_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT1_CTRL2_INNER_OFFSET2                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT1_CTRL2_INNER_OFFSET2_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT1_CTRL2_INNER_OFFSET2_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT2_CTRL0                                           (SHAREDMEM_REG_BASE + 0x60)
#define SHAREDMEM_REG_CLNT2_CTRL0_DEFAULT                                   0x1
#define SHAREDMEM_REG_CLNT2_CTRL0_ENABLE                                    (Bit0)
#define SHAREDMEM_REG_CLNT2_CTRL0_ENABLE_PANIC                              (Bit4)
#define SHAREDMEM_REG_CLNT2_CTRL0_FORCE_PANIC                               (Bit5)
#define SHAREDMEM_REG_CLNT2_CTRL0_ADDR_OFFSET0                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define SHAREDMEM_REG_CLNT2_CTRL0_ADDR_OFFSET0_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT2_CTRL0_ADDR_OFFSET0_SHIFT                        (8)


#define SHAREDMEM_REG_CLNT2_CTRL1                                           (SHAREDMEM_REG_BASE + 0x64)
#define SHAREDMEM_REG_CLNT2_CTRL1_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT2_CTRL1_ADDR_OFFSET1                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT2_CTRL1_ADDR_OFFSET1_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT2_CTRL1_ADDR_OFFSET1_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT2_CTRL1_INNER_OFFSET1                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT2_CTRL1_INNER_OFFSET1_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT2_CTRL1_INNER_OFFSET1_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT2_CTRL2                                           (SHAREDMEM_REG_BASE + 0x68)
#define SHAREDMEM_REG_CLNT2_CTRL2_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT2_CTRL2_ADDR_OFFSET2                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT2_CTRL2_ADDR_OFFSET2_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT2_CTRL2_ADDR_OFFSET2_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT2_CTRL2_INNER_OFFSET2                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT2_CTRL2_INNER_OFFSET2_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT2_CTRL2_INNER_OFFSET2_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT3_CTRL0                                           (SHAREDMEM_REG_BASE + 0x70)
#define SHAREDMEM_REG_CLNT3_CTRL0_DEFAULT                                   0x1
#define SHAREDMEM_REG_CLNT3_CTRL0_ENABLE                                    (Bit0)
#define SHAREDMEM_REG_CLNT3_CTRL0_ENABLE_PANIC                              (Bit4)
#define SHAREDMEM_REG_CLNT3_CTRL0_FORCE_PANIC                               (Bit5)
#define SHAREDMEM_REG_CLNT3_CTRL0_ADDR_OFFSET0                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define SHAREDMEM_REG_CLNT3_CTRL0_ADDR_OFFSET0_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT3_CTRL0_ADDR_OFFSET0_SHIFT                        (8)


#define SHAREDMEM_REG_CLNT3_CTRL1                                           (SHAREDMEM_REG_BASE + 0x74)
#define SHAREDMEM_REG_CLNT3_CTRL1_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT3_CTRL1_ADDR_OFFSET1                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT3_CTRL1_ADDR_OFFSET1_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT3_CTRL1_ADDR_OFFSET1_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT3_CTRL1_INNER_OFFSET1                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT3_CTRL1_INNER_OFFSET1_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT3_CTRL1_INNER_OFFSET1_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT3_CTRL2                                           (SHAREDMEM_REG_BASE + 0x78)
#define SHAREDMEM_REG_CLNT3_CTRL2_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT3_CTRL2_ADDR_OFFSET2                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT3_CTRL2_ADDR_OFFSET2_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT3_CTRL2_ADDR_OFFSET2_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT3_CTRL2_INNER_OFFSET2                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT3_CTRL2_INNER_OFFSET2_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT3_CTRL2_INNER_OFFSET2_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT4_CTRL0                                           (SHAREDMEM_REG_BASE + 0x80)
#define SHAREDMEM_REG_CLNT4_CTRL0_DEFAULT                                   0x1
#define SHAREDMEM_REG_CLNT4_CTRL0_ENABLE                                    (Bit0)
#define SHAREDMEM_REG_CLNT4_CTRL0_ENABLE_PANIC                              (Bit4)
#define SHAREDMEM_REG_CLNT4_CTRL0_FORCE_PANIC                               (Bit5)
#define SHAREDMEM_REG_CLNT4_CTRL0_ADDR_OFFSET0                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define SHAREDMEM_REG_CLNT4_CTRL0_ADDR_OFFSET0_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT4_CTRL0_ADDR_OFFSET0_SHIFT                        (8)


#define SHAREDMEM_REG_CLNT4_CTRL1                                           (SHAREDMEM_REG_BASE + 0x84)
#define SHAREDMEM_REG_CLNT4_CTRL1_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT4_CTRL1_ADDR_OFFSET1                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT4_CTRL1_ADDR_OFFSET1_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT4_CTRL1_ADDR_OFFSET1_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT4_CTRL1_INNER_OFFSET1                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT4_CTRL1_INNER_OFFSET1_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT4_CTRL1_INNER_OFFSET1_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT4_CTRL2                                           (SHAREDMEM_REG_BASE + 0x88)
#define SHAREDMEM_REG_CLNT4_CTRL2_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT4_CTRL2_ADDR_OFFSET2                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT4_CTRL2_ADDR_OFFSET2_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT4_CTRL2_ADDR_OFFSET2_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT4_CTRL2_INNER_OFFSET2                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT4_CTRL2_INNER_OFFSET2_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT4_CTRL2_INNER_OFFSET2_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT5_CTRL0                                           (SHAREDMEM_REG_BASE + 0x90)
#define SHAREDMEM_REG_CLNT5_CTRL0_DEFAULT                                   0x1
#define SHAREDMEM_REG_CLNT5_CTRL0_ENABLE                                    (Bit0)
#define SHAREDMEM_REG_CLNT5_CTRL0_ENABLE_PANIC                              (Bit4)
#define SHAREDMEM_REG_CLNT5_CTRL0_FORCE_PANIC                               (Bit5)
#define SHAREDMEM_REG_CLNT5_CTRL0_ADDR_OFFSET0                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define SHAREDMEM_REG_CLNT5_CTRL0_ADDR_OFFSET0_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT5_CTRL0_ADDR_OFFSET0_SHIFT                        (8)


#define SHAREDMEM_REG_CLNT5_CTRL1                                           (SHAREDMEM_REG_BASE + 0x94)
#define SHAREDMEM_REG_CLNT5_CTRL1_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT5_CTRL1_ADDR_OFFSET1                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT5_CTRL1_ADDR_OFFSET1_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT5_CTRL1_ADDR_OFFSET1_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT5_CTRL1_INNER_OFFSET1                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT5_CTRL1_INNER_OFFSET1_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT5_CTRL1_INNER_OFFSET1_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT5_CTRL2                                           (SHAREDMEM_REG_BASE + 0x98)
#define SHAREDMEM_REG_CLNT5_CTRL2_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT5_CTRL2_ADDR_OFFSET2                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT5_CTRL2_ADDR_OFFSET2_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT5_CTRL2_ADDR_OFFSET2_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT5_CTRL2_INNER_OFFSET2                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT5_CTRL2_INNER_OFFSET2_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT5_CTRL2_INNER_OFFSET2_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT6_CTRL0                                           (SHAREDMEM_REG_BASE + 0xa0)
#define SHAREDMEM_REG_CLNT6_CTRL0_DEFAULT                                   0x1
#define SHAREDMEM_REG_CLNT6_CTRL0_ENABLE                                    (Bit0)
#define SHAREDMEM_REG_CLNT6_CTRL0_ENABLE_PANIC                              (Bit4)
#define SHAREDMEM_REG_CLNT6_CTRL0_FORCE_PANIC                               (Bit5)
#define SHAREDMEM_REG_CLNT6_CTRL0_ADDR_OFFSET0                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define SHAREDMEM_REG_CLNT6_CTRL0_ADDR_OFFSET0_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT6_CTRL0_ADDR_OFFSET0_SHIFT                        (8)


#define SHAREDMEM_REG_CLNT6_CTRL1                                           (SHAREDMEM_REG_BASE + 0xa4)
#define SHAREDMEM_REG_CLNT6_CTRL1_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT6_CTRL1_ADDR_OFFSET1                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT6_CTRL1_ADDR_OFFSET1_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT6_CTRL1_ADDR_OFFSET1_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT6_CTRL1_INNER_OFFSET1                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT6_CTRL1_INNER_OFFSET1_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT6_CTRL1_INNER_OFFSET1_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT6_CTRL2                                           (SHAREDMEM_REG_BASE + 0xa8)
#define SHAREDMEM_REG_CLNT6_CTRL2_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT6_CTRL2_ADDR_OFFSET2                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT6_CTRL2_ADDR_OFFSET2_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT6_CTRL2_ADDR_OFFSET2_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT6_CTRL2_INNER_OFFSET2                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT6_CTRL2_INNER_OFFSET2_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT6_CTRL2_INNER_OFFSET2_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT7_CTRL0                                           (SHAREDMEM_REG_BASE + 0xb0)
#define SHAREDMEM_REG_CLNT7_CTRL0_DEFAULT                                   0x1
#define SHAREDMEM_REG_CLNT7_CTRL0_ENABLE                                    (Bit0)
#define SHAREDMEM_REG_CLNT7_CTRL0_ENABLE_PANIC                              (Bit4)
#define SHAREDMEM_REG_CLNT7_CTRL0_FORCE_PANIC                               (Bit5)
#define SHAREDMEM_REG_CLNT7_CTRL0_ADDR_OFFSET0                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define SHAREDMEM_REG_CLNT7_CTRL0_ADDR_OFFSET0_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT7_CTRL0_ADDR_OFFSET0_SHIFT                        (8)


#define SHAREDMEM_REG_CLNT7_CTRL1                                           (SHAREDMEM_REG_BASE + 0xb4)
#define SHAREDMEM_REG_CLNT7_CTRL1_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT7_CTRL1_ADDR_OFFSET1                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT7_CTRL1_ADDR_OFFSET1_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT7_CTRL1_ADDR_OFFSET1_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT7_CTRL1_INNER_OFFSET1                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT7_CTRL1_INNER_OFFSET1_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT7_CTRL1_INNER_OFFSET1_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT7_CTRL2                                           (SHAREDMEM_REG_BASE + 0xb8)
#define SHAREDMEM_REG_CLNT7_CTRL2_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT7_CTRL2_ADDR_OFFSET2                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT7_CTRL2_ADDR_OFFSET2_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT7_CTRL2_ADDR_OFFSET2_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT7_CTRL2_INNER_OFFSET2                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT7_CTRL2_INNER_OFFSET2_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT7_CTRL2_INNER_OFFSET2_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT8_CTRL0                                           (SHAREDMEM_REG_BASE + 0xc0)
#define SHAREDMEM_REG_CLNT8_CTRL0_DEFAULT                                   0x1
#define SHAREDMEM_REG_CLNT8_CTRL0_ENABLE                                    (Bit0)
#define SHAREDMEM_REG_CLNT8_CTRL0_ENABLE_PANIC                              (Bit4)
#define SHAREDMEM_REG_CLNT8_CTRL0_FORCE_PANIC                               (Bit5)
#define SHAREDMEM_REG_CLNT8_CTRL0_ADDR_OFFSET0                              (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21)
#define SHAREDMEM_REG_CLNT8_CTRL0_ADDR_OFFSET0_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT8_CTRL0_ADDR_OFFSET0_SHIFT                        (8)


#define SHAREDMEM_REG_CLNT8_CTRL1                                           (SHAREDMEM_REG_BASE + 0xc4)
#define SHAREDMEM_REG_CLNT8_CTRL1_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT8_CTRL1_ADDR_OFFSET1                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT8_CTRL1_ADDR_OFFSET1_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT8_CTRL1_ADDR_OFFSET1_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT8_CTRL1_INNER_OFFSET1                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT8_CTRL1_INNER_OFFSET1_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT8_CTRL1_INNER_OFFSET1_SHIFT                       (16)


#define SHAREDMEM_REG_CLNT8_CTRL2                                           (SHAREDMEM_REG_BASE + 0xc8)
#define SHAREDMEM_REG_CLNT8_CTRL2_DEFAULT                                   0x0
#define SHAREDMEM_REG_CLNT8_CTRL2_ADDR_OFFSET2                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13)
#define SHAREDMEM_REG_CLNT8_CTRL2_ADDR_OFFSET2_MASK                         (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT8_CTRL2_ADDR_OFFSET2_SHIFT                        (0)
#define SHAREDMEM_REG_CLNT8_CTRL2_INNER_OFFSET2                             (Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29)
#define SHAREDMEM_REG_CLNT8_CTRL2_INNER_OFFSET2_MASK                        (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define SHAREDMEM_REG_CLNT8_CTRL2_INNER_OFFSET2_SHIFT                       (16)


#endif // _SHAREDMEM_REG_DEFINES_H

