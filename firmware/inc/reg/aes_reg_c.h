#ifndef _AES_REG_DEFINES_H
#define _AES_REG_DEFINES_H
/* **************************** */
#define AES_REG_MISC_CTRL                                        (AES_REG_BASE + 0x0)
#define AES_REG_MISC_CTRL_DEFAULT                                0x0
#define AES_REG_MISC_CTRL_GO                                     (Bit0)
#define AES_REG_MISC_CTRL_ENCRYPT                                (Bit1)
#define AES_REG_MISC_CTRL_MSG_BEGIN                              (Bit2)
#define AES_REG_MISC_CTRL_MSG_END                                (Bit3)
#define AES_REG_MISC_CTRL_MODE                                   (Bit4+Bit5+Bit6+Bit7)
#define AES_REG_MISC_CTRL_MODE_MASK                              (Bit3+Bit2+Bit1+Bit0)
#define AES_REG_MISC_CTRL_MODE_SHIFT                             (4)
#define AES_REG_MISC_CTRL_MAC_LEN                                (Bit8+Bit9+Bit10+Bit11)
#define AES_REG_MISC_CTRL_MAC_LEN_MASK                           (Bit3+Bit2+Bit1+Bit0)
#define AES_REG_MISC_CTRL_MAC_LEN_SHIFT                          (8)
#define AES_REG_MISC_CTRL_KEY_SIZE                               (Bit12+Bit13)
#define AES_REG_MISC_CTRL_KEY_SIZE_MASK                          (Bit1+Bit0)
#define AES_REG_MISC_CTRL_KEY_SIZE_SHIFT                         (12)
#define AES_REG_MISC_CTRL_STR_CTX                                (Bit14)
#define AES_REG_MISC_CTRL_RET_CTX                                (Bit15)
#define AES_REG_MISC_CTRL_INV_KEY                                (Bit16)
#define AES_REG_MISC_CTRL_STR_INV_KEY                            (Bit17)
#define AES_REG_MISC_CTRL_STR_TAG2MSG                            (Bit18)
#define AES_REG_MISC_CTRL_GMAC                                   (Bit19)


#define AES_REG_CTX_INDEX                                        (AES_REG_BASE + 0x4)
#define AES_REG_CTX_INDEX_DEFAULT                                0x0
#define AES_REG_CTX_INDEX_INDEX                                  (Bit0+Bit1+Bit2+Bit3)
#define AES_REG_CTX_INDEX_INDEX_MASK                             (Bit3+Bit2+Bit1+Bit0)
#define AES_REG_CTX_INDEX_INDEX_SHIFT                            (0)


#define AES_REG_BLOCK_INDEX                                      (AES_REG_BASE + 0x8)
#define AES_REG_BLOCK_INDEX_DEFAULT                              0x0
#define AES_REG_BLOCK_INDEX_INDEX                                (Bit0+Bit1)
#define AES_REG_BLOCK_INDEX_INDEX_MASK                           (Bit1+Bit0)
#define AES_REG_BLOCK_INDEX_INDEX_SHIFT                          (0)


#define AES_REG_AAD_LENGTH                                       (AES_REG_BASE + 0xc)
#define AES_REG_AAD_LENGTH_DEFAULT                               0x0
#define AES_REG_AAD_LENGTH_LENGTH                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6)
#define AES_REG_AAD_LENGTH_LENGTH_MASK                           (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AES_REG_AAD_LENGTH_LENGTH_SHIFT                          (0)


#define AES_REG_NUM_BYTES                                        (AES_REG_BASE + 0x10)
#define AES_REG_NUM_BYTES_DEFAULT                                0x0
#define AES_REG_NUM_BYTES_NUM_BYTES                              (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6)
#define AES_REG_NUM_BYTES_NUM_BYTES_MASK                         (Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AES_REG_NUM_BYTES_NUM_BYTES_SHIFT                        (0)


#define AES_REG_NUM_TOTAL_BYTES                                  (AES_REG_BASE + 0x14)
#define AES_REG_NUM_TOTAL_BYTES_DEFAULT                          0x0
#define AES_REG_NUM_TOTAL_BYTES_NUM_TOTAL_BYTES                  (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AES_REG_NUM_TOTAL_BYTES_NUM_TOTAL_BYTES_MASK             (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AES_REG_NUM_TOTAL_BYTES_NUM_TOTAL_BYTES_SHIFT            (0)


#define AES_REG_TAG_MSG_ADDR                                     (AES_REG_BASE + 0x18)
#define AES_REG_TAG_MSG_ADDR_DEFAULT                             0x0
#define AES_REG_TAG_MSG_ADDR_ADDR                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5)
#define AES_REG_TAG_MSG_ADDR_ADDR_MASK                           (Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AES_REG_TAG_MSG_ADDR_ADDR_SHIFT                          (0)


#define AES_REG_AAD_LEN_TOTAL                                    (AES_REG_BASE + 0x1c)
#define AES_REG_AAD_LEN_TOTAL_DEFAULT                            0x0
#define AES_REG_AAD_LEN_TOTAL_LEN                                (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define AES_REG_AAD_LEN_TOTAL_LEN_MASK                           (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define AES_REG_AAD_LEN_TOTAL_LEN_SHIFT                          (0)


#endif // _AES_REG_DEFINES_H

