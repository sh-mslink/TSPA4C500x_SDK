#ifndef _ICACHE_REG_DEFINES_H
#define _ICACHE_REG_DEFINES_H
/* **************************** */
#define ICACHE_REG_INTR_STATUS                                       (ICACHE_REG_BASE + 0x0)
#define ICACHE_REG_INTR_STATUS_DEFAULT                               0x0
#define ICACHE_REG_INTR_STATUS_SRAM_CLEAR_DONE                       (Bit0)


#define ICACHE_REG_INTR_MASK_STATUS                                  (ICACHE_REG_BASE + 0x4)
#define ICACHE_REG_INTR_MASK_STATUS_DEFAULT                          0x0
#define ICACHE_REG_INTR_MASK_STATUS_SRAM_CLEAR_DONE                  (Bit0)


#define ICACHE_REG_INTR_CLEAR                                        (ICACHE_REG_BASE + 0x8)
#define ICACHE_REG_INTR_CLEAR_DEFAULT                                0x0
#define ICACHE_REG_INTR_CLEAR_SRAM_CLEAR_DONE                        (Bit0)


#define ICACHE_REG_INTR_SET                                          (ICACHE_REG_BASE + 0xc)
#define ICACHE_REG_INTR_SET_DEFAULT                                  0x0
#define ICACHE_REG_INTR_SET_SRAM_CLEAR_DONE                          (Bit0)


#define ICACHE_REG_INTR_MASK_SET                                     (ICACHE_REG_BASE + 0x10)
#define ICACHE_REG_INTR_MASK_SET_DEFAULT                             0x0
#define ICACHE_REG_INTR_MASK_SET_SRAM_CLEAR_DONE                     (Bit0)


#define ICACHE_REG_INTR_MASK_CLEAR                                   (ICACHE_REG_BASE + 0x14)
#define ICACHE_REG_INTR_MASK_CLEAR_DEFAULT                           0x0
#define ICACHE_REG_INTR_MASK_CLEAR_SRAM_CLEAR_DONE                   (Bit0)


#define ICACHE_REG_MISC_CTRL                                         (ICACHE_REG_BASE + 0x18)
#define ICACHE_REG_MISC_CTRL_DEFAULT                                 0x0
#define ICACHE_REG_MISC_CTRL_CTL_CACHE_EN                            (Bit0)
#define ICACHE_REG_MISC_CTRL_CTL_ALWAYS_REQ                          (Bit1)
#define ICACHE_REG_MISC_CTRL_CTL_SRAM_CLR                            (Bit4)
#define ICACHE_REG_MISC_CTRL_CTL_COUNTER_CLR                         (Bit8)
#define ICACHE_REG_MISC_CTRL_CTL_COUNTER_SNAP                        (Bit9)
#define ICACHE_REG_MISC_CTRL_CTL_RST_INTRCTRL                        (Bit12)


#define ICACHE_REG_HIT_COUNTER                                       (ICACHE_REG_BASE + 0x28)
#define ICACHE_REG_HIT_COUNTER_DEFAULT                               0x0
#define ICACHE_REG_HIT_COUNTER_STS_HIT_COUNT                         (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define ICACHE_REG_HIT_COUNTER_STS_HIT_COUNT_MASK                    (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define ICACHE_REG_HIT_COUNTER_STS_HIT_COUNT_SHIFT                   (0)


#define ICACHE_REG_MISS_COUNTER                                      (ICACHE_REG_BASE + 0x2c)
#define ICACHE_REG_MISS_COUNTER_DEFAULT                              0x0
#define ICACHE_REG_MISS_COUNTER_STS_MISS_COUNT                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define ICACHE_REG_MISS_COUNTER_STS_MISS_COUNT_MASK                  (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define ICACHE_REG_MISS_COUNTER_STS_MISS_COUNT_SHIFT                 (0)


#endif // _ICACHE_REG_DEFINES_H

