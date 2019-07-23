#ifndef _APB_AON_BRIDGE_REG_DEFINES_H
#define _APB_AON_BRIDGE_REG_DEFINES_H
/* **************************** */
#define APB_AON_BRIDGE_REG_OP_CTRL                                       (APB_AON_BRIDGE_REG_BASE + 0x8)
#define APB_AON_BRIDGE_REG_OP_CTRL_DEFAULT                               0x0
#define APB_AON_BRIDGE_REG_OP_CTRL_CTL_AON_REG_ADDR                      (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define APB_AON_BRIDGE_REG_OP_CTRL_CTL_AON_REG_ADDR_MASK                 (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define APB_AON_BRIDGE_REG_OP_CTRL_CTL_AON_REG_ADDR_SHIFT                (0)
#define APB_AON_BRIDGE_REG_OP_CTRL_CTL_AON_REG_RD0WR1                    (Bit16)
#define APB_AON_BRIDGE_REG_OP_CTRL_STS_AON_REG_RW_DONE                   (Bit20)


#define APB_AON_BRIDGE_REG_WDATA                                         (APB_AON_BRIDGE_REG_BASE + 0xc)
#define APB_AON_BRIDGE_REG_WDATA_DEFAULT                                 0x0
#define APB_AON_BRIDGE_REG_WDATA_CTL_AON_REG_WDATA                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define APB_AON_BRIDGE_REG_WDATA_CTL_AON_REG_WDATA_MASK                  (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define APB_AON_BRIDGE_REG_WDATA_CTL_AON_REG_WDATA_SHIFT                 (0)


#define APB_AON_BRIDGE_REG_RDATA                                         (APB_AON_BRIDGE_REG_BASE + 0x10)
#define APB_AON_BRIDGE_REG_RDATA_DEFAULT                                 0x0
#define APB_AON_BRIDGE_REG_RDATA_STS_AON_REG_RDATA                       (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define APB_AON_BRIDGE_REG_RDATA_STS_AON_REG_RDATA_MASK                  (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define APB_AON_BRIDGE_REG_RDATA_STS_AON_REG_RDATA_SHIFT                 (0)


#define APB_AON_BRIDGE_REG_STATUS                                        (APB_AON_BRIDGE_REG_BASE + 0x18)
#define APB_AON_BRIDGE_REG_STATUS_DEFAULT                                0x0
#define APB_AON_BRIDGE_REG_STATUS_STS_AON_BRIDGE_STATUS                  (Bit0+Bit1+Bit2)
#define APB_AON_BRIDGE_REG_STATUS_STS_AON_BRIDGE_STATUS_MASK             (Bit2+Bit1+Bit0)
#define APB_AON_BRIDGE_REG_STATUS_STS_AON_BRIDGE_STATUS_SHIFT            (0)


#endif // _APB_AON_BRIDGE_REG_DEFINES_H

