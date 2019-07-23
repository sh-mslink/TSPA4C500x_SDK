/* **************************** */
#define HWACC_REG_INTR_STATUS                                                         (HWACC_REG_BASE + 0x0)
#define HWACC_REG_INTR_STATUS_DEFAULT                                                 0x0
#define HWACC_REG_INTR_STATUS_HWACC_DONE                                              (Bit0)
#define HWACC_REG_INTR_STATUS_FAULT_DETECTED                                          (Bit1)


#define HWACC_REG_INTR_MASK_STATUS                                                    (HWACC_REG_BASE + 0x4)
#define HWACC_REG_INTR_MASK_STATUS_DEFAULT                                            0x0
#define HWACC_REG_INTR_MASK_STATUS_HWACC_DONE                                         (Bit0)
#define HWACC_REG_INTR_MASK_STATUS_FAULT_DETECTED                                     (Bit1)


#define HWACC_REG_INTR_CLEAR                                                          (HWACC_REG_BASE + 0x8)
#define HWACC_REG_INTR_CLEAR_DEFAULT                                                  0x0
#define HWACC_REG_INTR_CLEAR_HWACC_DONE                                               (Bit0)
#define HWACC_REG_INTR_CLEAR_FAULT_DETECTED                                           (Bit1)


#define HWACC_REG_INTR_SET                                                            (HWACC_REG_BASE + 0xc)
#define HWACC_REG_INTR_SET_DEFAULT                                                    0x0
#define HWACC_REG_INTR_SET_HWACC_DONE                                                 (Bit0)
#define HWACC_REG_INTR_SET_FAULT_DETECTED                                             (Bit1)


#define HWACC_REG_INTR_MASK_SET                                                       (HWACC_REG_BASE + 0x10)
#define HWACC_REG_INTR_MASK_SET_DEFAULT                                               0x0
#define HWACC_REG_INTR_MASK_SET_HWACC_DONE                                            (Bit0)
#define HWACC_REG_INTR_MASK_SET_FAULT_DETECTED                                        (Bit1)


#define HWACC_REG_INTR_MASK_CLEAR                                                     (HWACC_REG_BASE + 0x14)
#define HWACC_REG_INTR_MASK_CLEAR_DEFAULT                                             0x0
#define HWACC_REG_INTR_MASK_CLEAR_HWACC_DONE                                          (Bit0)
#define HWACC_REG_INTR_MASK_CLEAR_FAULT_DETECTED                                      (Bit1)


#define HWACC_REG_MISC_CTRL                                                           (HWACC_REG_BASE + 0x40)
#define HWACC_REG_MISC_CTRL_DEFAULT                                                   0x0
#define HWACC_REG_MISC_CTRL_CTL_ENABLE                                                (Bit0)
#define HWACC_REG_MISC_CTRL_CTL_START                                                 (Bit1)
#define HWACC_REG_MISC_CTRL_CTL_AUTO_RESET_ON_FAULT                                   (Bit2)
#define HWACC_REG_MISC_CTRL_CTL_RST_INTRCTRL                                          (Bit4)
#define HWACC_REG_MISC_CTRL_CTL_NUM_INSTRUCTION                                       (Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17)
#define HWACC_REG_MISC_CTRL_CTL_NUM_INSTRUCTION_MASK                                  (Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define HWACC_REG_MISC_CTRL_CTL_NUM_INSTRUCTION_SHIFT                                 (8)
#define HWACC_REG_MISC_CTRL_CTL_INSTRUCTION_ADDRESS                                   (Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define HWACC_REG_MISC_CTRL_CTL_INSTRUCTION_ADDRESS_MASK                              (Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define HWACC_REG_MISC_CTRL_CTL_INSTRUCTION_ADDRESS_SHIFT                             (18)


#define HWACC_REG_MEM_ACC_CTRL                                                        (HWACC_REG_BASE + 0x48)
#define HWACC_REG_MEM_ACC_CTRL_DEFAULT                                                0x0
#define HWACC_REG_MEM_ACC_CTRL_CTL_MEM_A_ACC_SEL                                      (Bit0)
#define HWACC_REG_MEM_ACC_CTRL_CTL_MEM_B_ACC_SEL                                      (Bit4)
#define HWACC_REG_MEM_ACC_CTRL_CTL_MEM_C_ACC_SEL                                      (Bit8)
#define HWACC_REG_MEM_ACC_CTRL_CTL_MEM_D_ACC_SEL                                      (Bit12)


#define HWACC_REG_INVERSE_CTRL                                                        (HWACC_REG_BASE + 0x58)
#define HWACC_REG_INVERSE_CTRL_DEFAULT                                                0x0
#define HWACC_REG_INVERSE_CTRL_CTL_PV_SEARCH_ON                                       (Bit0)
#define HWACC_REG_INVERSE_CTRL_CTL_CHECK_MIN_PV_ON                                    (Bit1)
#define HWACC_REG_INVERSE_CTRL_CTL_CHECK_ZERO_PV_ON                                   (Bit2)


#define HWACC_REG_INVERSE_MIN_PV                                                      (HWACC_REG_BASE + 0x60)
#define HWACC_REG_INVERSE_MIN_PV_DEFAULT                                              0x0
#define HWACC_REG_INVERSE_MIN_PV_CTL_MIN_PV                                           (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define HWACC_REG_INVERSE_MIN_PV_CTL_MIN_PV_MASK                                      (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define HWACC_REG_INVERSE_MIN_PV_CTL_MIN_PV_SHIFT                                     (0)


#define HWACC_REG_CURR_INST_WORD0                                                     (HWACC_REG_BASE + 0x80)
#define HWACC_REG_CURR_INST_WORD0_DEFAULT                                             0x0
#define HWACC_REG_CURR_INST_WORD0_STS_CURRENT_INST_WORD_0                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define HWACC_REG_CURR_INST_WORD0_STS_CURRENT_INST_WORD_0_MASK                        (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define HWACC_REG_CURR_INST_WORD0_STS_CURRENT_INST_WORD_0_SHIFT                       (0)


#define HWACC_REG_CURR_INST_WORD1                                                     (HWACC_REG_BASE + 0x84)
#define HWACC_REG_CURR_INST_WORD1_DEFAULT                                             0x0
#define HWACC_REG_CURR_INST_WORD1_STS_CURRENT_INST_WORD_1                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define HWACC_REG_CURR_INST_WORD1_STS_CURRENT_INST_WORD_1_MASK                        (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define HWACC_REG_CURR_INST_WORD1_STS_CURRENT_INST_WORD_1_SHIFT                       (0)


#define HWACC_REG_CURR_INST_WORD2                                                     (HWACC_REG_BASE + 0x88)
#define HWACC_REG_CURR_INST_WORD2_DEFAULT                                             0x0
#define HWACC_REG_CURR_INST_WORD2_STS_CURRENT_INST_WORD_2                             (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15+Bit16+Bit17+Bit18+Bit19+Bit20+Bit21+Bit22+Bit23+Bit24+Bit25+Bit26+Bit27+Bit28+Bit29+Bit30+Bit31)
#define HWACC_REG_CURR_INST_WORD2_STS_CURRENT_INST_WORD_2_MASK                        (Bit31+Bit30+Bit29+Bit28+Bit27+Bit26+Bit25+Bit24+Bit23+Bit22+Bit21+Bit20+Bit19+Bit18+Bit17+Bit16+Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define HWACC_REG_CURR_INST_WORD2_STS_CURRENT_INST_WORD_2_SHIFT                       (0)


#define HWACC_REG_CURR_INST_CYCLE_CNT                                                 (HWACC_REG_BASE + 0x8c)
#define HWACC_REG_CURR_INST_CYCLE_CNT_DEFAULT                                         0x0
#define HWACC_REG_CURR_INST_CYCLE_CNT_STS_CURRENT_INST_CYCLE_COUNT                    (Bit0+Bit1+Bit2+Bit3+Bit4+Bit5+Bit6+Bit7+Bit8+Bit9+Bit10+Bit11+Bit12+Bit13+Bit14+Bit15)
#define HWACC_REG_CURR_INST_CYCLE_CNT_STS_CURRENT_INST_CYCLE_COUNT_MASK               (Bit15+Bit14+Bit13+Bit12+Bit11+Bit10+Bit9+Bit8+Bit7+Bit6+Bit5+Bit4+Bit3+Bit2+Bit1+Bit0)
#define HWACC_REG_CURR_INST_CYCLE_CNT_STS_CURRENT_INST_CYCLE_COUNT_SHIFT              (0)


#define HWACC_REG_CURRENT_FAULT                                                       (HWACC_REG_BASE + 0xa0)
#define HWACC_REG_CURRENT_FAULT_DEFAULT                                               0x0
#define HWACC_REG_CURRENT_FAULT_STS_MEM_A_ADDR_OVFL                                   (Bit0)
#define HWACC_REG_CURRENT_FAULT_STS_MEM_B_ADDR_OVFL                                   (Bit1)
#define HWACC_REG_CURRENT_FAULT_STS_MEM_C_ADDR_OVFL                                   (Bit2)
#define HWACC_REG_CURRENT_FAULT_STS_MEM_D_ADDR_OVFL                                   (Bit3)
#define HWACC_REG_CURRENT_FAULT_STS_MEM_COPY_RW_ADDR_OVERLAP                          (Bit4)
#define HWACC_REG_CURRENT_FAULT_STS_SIZE_OUT_BOUND_SOURCE_1                           (Bit5)
#define HWACC_REG_CURRENT_FAULT_STS_SIZE_OUT_BOUND_SOURCE_2                           (Bit6)
#define HWACC_REG_CURRENT_FAULT_STS_ADD_SUB_SIZE_MISMATCH                             (Bit7)
#define HWACC_REG_CURRENT_FAULT_STS_MUL_SIZE_MISMATCH                                 (Bit8)
#define HWACC_REG_CURRENT_FAULT_STS_MEM_NOT_UNIQUE                                    (Bit9)
#define HWACC_REG_CURRENT_FAULT_STS_WRONG_SCALER_SIZE                                 (Bit10)
#define HWACC_REG_CURRENT_FAULT_STS_INITIAL_OFFSET_OVERFLOW_SOURCE_1                  (Bit11)
#define HWACC_REG_CURRENT_FAULT_STS_INITIAL_OFFSET_OVERFLOW_SOURCE_2                  (Bit12)
#define HWACC_REG_CURRENT_FAULT_STS_INITIAL_OFFSET_OVERFLOW_MEM_W                     (Bit13)
#define HWACC_REG_CURRENT_FAULT_STS_PV_TOO_SMALL                                      (Bit14)
#define HWACC_REG_CURRENT_FAULT_STS_PV_EQUAL_ZERO                                     (Bit15)
#define HWACC_REG_CURRENT_FAULT_STS_SOURCE_NOT_SYMMETRIC                              (Bit16)
#define HWACC_REG_CURRENT_FAULT_STS_VECTOR_SIZE_MISMATCH                              (Bit17)
#define HWACC_REG_CURRENT_FAULT_STS_TRANSPOSE_VIOLATION                               (Bit18)
#define HWACC_REG_CURRENT_FAULT_STS_DIVIDE_BY_0_TRIGGERED                             (Bit19)


