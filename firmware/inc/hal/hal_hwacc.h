/**
 ****************************************************************************************
 *
 * @file hal_hwacc.h
 *
 * @brief Hardware Accelerator Profile
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

#ifndef HAL_HWACC_H
#define HAL_HWACC_H

/**
 ****************************************************************************************
 * @defgroup HAL_HWACC Hardware Accelerator Profile  
 * @ingroup HAL
 * @brief  HAL HWACC
 * @{
 ****************************************************************************************
 */

#include <stdint.h>
#include <math.h>
#include "in_mmap.h"
#include "in_config.h"

/*
 ****************************************************************************************
 * INLINE FUNCTIONS
 ****************************************************************************************
 */
 
static __inline uint8_t hwacc_get_intr_status()
{
	return RD_WORD(HWACC_REG_INTR_STATUS);
}
 
static __inline uint8_t hwacc_get_mask_status()
{
	return RD_WORD(HWACC_REG_INTR_MASK_STATUS);
}

static __inline void hwacc_intr_clear()
{
	WR_WORD(HWACC_REG_INTR_CLEAR, (HWACC_REG_INTR_CLEAR_HWACC_DONE | HWACC_REG_INTR_CLEAR_FAULT_DETECTED));
}

static __inline void hwacc_intr_set()
{
	WR_WORD(HWACC_REG_INTR_SET, (HWACC_REG_INTR_SET_HWACC_DONE | HWACC_REG_INTR_SET_FAULT_DETECTED));
}

static __inline void hwacc_mask_clear()
{
	WR_WORD(HWACC_REG_INTR_MASK_CLEAR, (HWACC_REG_INTR_MASK_CLEAR_HWACC_DONE | HWACC_REG_INTR_MASK_CLEAR_FAULT_DETECTED));
}

static __inline void hwacc_mask_set()
{
	WR_WORD(HWACC_REG_INTR_MASK_SET, (HWACC_REG_INTR_MASK_SET_HWACC_DONE | HWACC_REG_INTR_MASK_SET_FAULT_DETECTED));
}

static __inline void hwacc_enable()
{
	uint32_t reg = RD_WORD(HWACC_REG_MISC_CTRL);
	reg |= HWACC_REG_MISC_CTRL_CTL_ENABLE;
	WR_WORD(HWACC_REG_MISC_CTRL, reg);
}

static __inline void hwacc_disable()
{
	uint32_t reg = RD_WORD(HWACC_REG_MISC_CTRL);
	reg &= ~HWACC_REG_MISC_CTRL_CTL_ENABLE;
	WR_WORD(HWACC_REG_MISC_CTRL, reg);
}

static __inline void hwacc_start()
{
	uint32_t reg = RD_WORD(HWACC_REG_MISC_CTRL);
	reg |= HWACC_REG_MISC_CTRL_CTL_START;
	WR_WORD(HWACC_REG_MISC_CTRL, reg);

	reg &= ~HWACC_REG_MISC_CTRL_CTL_START;
	WR_WORD(HWACC_REG_MISC_CTRL, reg);
}

static __inline void hwacc_set_num_inst(uint16_t num_inst)
{
	uint32_t reg = RD_WORD(HWACC_REG_MISC_CTRL);
	reg &= ~HWACC_REG_MISC_CTRL_CTL_NUM_INSTRUCTION;
	reg |= ((num_inst & HWACC_REG_MISC_CTRL_CTL_NUM_INSTRUCTION_MASK) << HWACC_REG_MISC_CTRL_CTL_NUM_INSTRUCTION_SHIFT);
	WR_WORD(HWACC_REG_MISC_CTRL, reg);
}

static __inline void hwacc_set_inst_addr(uint16_t inst_addr)
{
	uint32_t reg = RD_WORD(HWACC_REG_MISC_CTRL);
	reg &= ~HWACC_REG_MISC_CTRL_CTL_INSTRUCTION_ADDRESS;
	reg |= ((inst_addr & HWACC_REG_MISC_CTRL_CTL_INSTRUCTION_ADDRESS_MASK) << HWACC_REG_MISC_CTRL_CTL_INSTRUCTION_ADDRESS_SHIFT);
	WR_WORD(HWACC_REG_MISC_CTRL, reg);
}

static __inline void hwacc_mem_acc_ahb()
{
	WR_WORD(HWACC_REG_MEM_ACC_CTRL, HWACC_REG_MEM_ACC_CTRL_DEFAULT);
}

static __inline void hwacc_mem_acc_comp_core()
{
	WR_WORD(HWACC_REG_MEM_ACC_CTRL, HWACC_REG_MEM_ACC_CTRL_CTL_MEM_A_ACC_SEL | HWACC_REG_MEM_ACC_CTRL_CTL_MEM_B_ACC_SEL | HWACC_REG_MEM_ACC_CTRL_CTL_MEM_C_ACC_SEL | HWACC_REG_MEM_ACC_CTRL_CTL_MEM_D_ACC_SEL);
}

static __inline void hwacc_pv_search_enable()
{
	uint32_t reg = RD_WORD(HWACC_REG_INVERSE_CTRL);
	reg |= HWACC_REG_INVERSE_CTRL_CTL_PV_SEARCH_ON;
	WR_WORD(HWACC_REG_INVERSE_CTRL, reg);
}

static __inline void hwacc_pv_search_disable()
{
	uint32_t reg = RD_WORD(HWACC_REG_INVERSE_CTRL);
	reg &= ~HWACC_REG_INVERSE_CTRL_CTL_PV_SEARCH_ON;
	WR_WORD(HWACC_REG_INVERSE_CTRL, reg);
}

static __inline void hwacc_check_min_pv_enable()
{
	uint32_t reg = RD_WORD(HWACC_REG_INVERSE_CTRL);
	reg |= HWACC_REG_INVERSE_CTRL_CTL_CHECK_MIN_PV_ON;
	WR_WORD(HWACC_REG_INVERSE_CTRL, reg);
}

static __inline void hwacc_check_min_pv_disable()
{
	uint32_t reg = RD_WORD(HWACC_REG_INVERSE_CTRL);
	reg &= ~HWACC_REG_INVERSE_CTRL_CTL_CHECK_MIN_PV_ON;
	WR_WORD(HWACC_REG_INVERSE_CTRL, reg);
}

static __inline void hwacc_check_zero_pv_enable()
{
	uint32_t reg = RD_WORD(HWACC_REG_INVERSE_CTRL);
	reg |= HWACC_REG_INVERSE_CTRL_CTL_CHECK_ZERO_PV_ON;
	WR_WORD(HWACC_REG_INVERSE_CTRL, reg);
}

static __inline void hwacc_check_zero_pv_disable()
{
	uint32_t reg = RD_WORD(HWACC_REG_INVERSE_CTRL);
	reg &= ~HWACC_REG_INVERSE_CTRL_CTL_CHECK_ZERO_PV_ON;
	WR_WORD(HWACC_REG_INVERSE_CTRL, reg);
}

static __inline void hwacc_set_min_pv(uint32_t min_pv)
{
	WR_WORD(HWACC_REG_INVERSE_MIN_PV, min_pv);
}
 
static __inline uint32_t hwacc_get_curr_inst_word_0()
{
	return RD_WORD(HWACC_REG_CURR_INST_WORD0);
}
 
static __inline uint32_t hwacc_get_curr_inst_word_1()
{
	return RD_WORD(HWACC_REG_CURR_INST_WORD1);
}
 
static __inline uint32_t hwacc_get_curr_inst_word_2()
{
	return RD_WORD(HWACC_REG_CURR_INST_WORD2);
}
 
static __inline uint32_t hwacc_get_curr_inst_cycle_cnt()
{
	return RD_WORD(HWACC_REG_CURR_INST_CYCLE_CNT);
}

/*
 ****************************************************************************************
 * IMPLEMENTATION
 ****************************************************************************************
 */

#define HWACC_MEM_0_BASE_ADDR		0x44007000
#define HWACC_MEM_1_BASE_ADDR		0x44007800
#define HWACC_MEM_2_BASE_ADDR		0x44008000
#define HWACC_MEM_3_BASE_ADDR		0x44008400

typedef enum {	
	/// Matrix copy: (C = B) Copy B from one memory location to another memory location (same or different memory). A is ignored.
	HWACC_OP_COPY = 0,
	/// Matrix addition: (C = A + B) Addition of A/B (each from a different memory), result saved to another memory. A/B/C must have same size.
	HWACC_OP_ADD = 1,
	/// Matrix subtraction: (C = A - B) Subtraction of B from A (each from a different memory), result saved to another memory. A/B/C must have same size.
	HWACC_OP_SUB = 2,
	/// Matrix multiplication: (C = AB) Multiplication of A/B (each from a different memory), result saved to another memory. Dimensions must match.
	HWACC_OP_MUL = 3,
	/// Matrix inversion: (C = A^-1) Inversion of A, result saved to another memory, at return: C = A^-1, A = identity matrix. B is ignored.
	HWACC_OP_INV = 4,
	/// Matrix solve linear equation: (C = A^-1 * B) Solving linear equation (A is a square matrix and B is a vector),
	/// at return: C = A^-1, B = solution to linear equation, A = Identity matrix.
	HWACC_OP_EQU = 5,
	/// Matrix clear: (C = A * 0) C is zero matrix matching size of A. (Clear memory bank and offset of C with size of A).  B is ignored.
	HWACC_OP_CLEAR = 6,
	/// Matrix scale: (C = A * B) Scale A by B (b is a scalar 1x1 matrix).
	HWACC_OP_SCALE = 7,
} hwacc_op_t;

typedef struct {
	/// HWACC memory block matrix is stored in
	uint8_t mem_block;
	/// Matrix data start location offset in 4-byte intervals
	uint16_t offset;
	/// Number of rows in matrix
	uint8_t nrows;
	/// Number of cols in matrix
	uint8_t ncols;
} hwacc_matrix_desc_t;

/// HWACC function status return
typedef enum {
	/// No error. Good status. 
	HWACC_ERR_OK = 0,
	/// Hardware configuration error detected. 
	HWACC_ERR_CONFIG_ERROR = 1,
	/// Instruction overflow detected. Too many instructions inserted.
	HWACC_ERR_INST_OVERFLOW = 2, 
	/// HWACC driver already initialized with hwacc_open().
	HWACC_ERR_ALREADY_INIT = 3,
	/// HWACC driver not yet initialized with hwacc_open().
	HWACC_ERR_NOT_INIT = 4,
	/// HWACC unable to initialize.
	HWACC_ERR_BAD_STATE = 5,
	/// Matrix dimension mismatch within instruction operation.
	HWACC_ERR_DIMENSION_MISMATCH = 6,
	/// HWACC input issue.
	HWACC_ERR_BAD_INPUT = 7,
	/// Hardware configuration error detected.
} hwacc_status_t;

// DEFAULT INITIALIZATION
/**
 ****************************************************************************************
 * @brief Initialize hardware accelerator driver.
 *
 * @param[in] inst_offset			HWACC instruction Shared Memory offset.
 *
 * @return HWACC_ERR_OK if successful, error otherwise. @see enum hwacc_status_t.
 ****************************************************************************************
 */
int hal_hwacc_open(void);

/**
 ****************************************************************************************
 * @brief Clean-up hardware accelerator driver.
 *
 * @return HWACC_ERR_OK if successful, error otherwise. @see enum hwacc_status_t.
 ****************************************************************************************
 */
int hal_hwacc_close(void);

/**
 ****************************************************************************************
 * @brief Write matrix into hardware accelerator memory blocks.
 *
 * @param[in] matrix				Pointer to matrix descriptor object of new matrix to be written. @see enum hwacc_matrix_desc_t.
 * @param[in] head					Pointer to data of new matrix in row-major format. Data should be size 4-bytes per matrix index.
 *
 * @return HWACC_ERR_OK if successful, error otherwise. @see enum hwacc_status_t.
 ****************************************************************************************
 */
int hal_hwacc_write_matrix(hwacc_matrix_desc_t *matrix, const float *head);

/**
 ****************************************************************************************
 * @brief Read matrix data from hardware accelerator memory blocks.
 *
 * @param[in] matrix				Pointer to matrix descriptor object of matrix to be read. @see enum hwacc_matrix_desc_t.
 * @param[in] head					Pointer to data of new matrix in row-major format. Data will be size 4-bytes per matrix index.
 *
 * @return HWACC_ERR_OK if successful, error otherwise. @see enum hwacc_status_t.
 ****************************************************************************************
 */
int hal_hwacc_read_matrix(hwacc_matrix_desc_t *matrix, float *head);

/**
 ****************************************************************************************
 * @brief Insert instruction into queue
 *
 * @param[in] matrix_C			Pointer to matrix descriptor object of output matrix C. @see enum hwacc_matrix_desc_t.
 * @param[in] C_symm				1 if result matrix is symmetric (using this property saves HW operations).
 * @param[in] matrix_A			Pointer to matrix descriptor object of input matrix A. @see enum hwacc_matrix_desc_t.
 * @param[in] A_trans				1 if input matrix A needs to be transposed for the operation.
 * @param[in] matrix_B			Pointer to matrix descriptor object of input matrix B. @see enum hwacc_matrix_desc_t.
 * @param[in] B_trans				1 if input matrix B needs to be transposed for the operation.
 * @param[in] op						Instruction operation. @see enum hwacc_op_t.
 *
 * @return HWACC_ERR_OK if successful, error otherwise. @see enum hwacc_status_t.
 ****************************************************************************************
 */
int hal_hwacc_insert_inst(hwacc_matrix_desc_t *matrix_C, int C_symm, hwacc_matrix_desc_t *matrix_A, int A_trans, hwacc_matrix_desc_t *matrix_B, int B_trans, hwacc_op_t op);

/**
 ****************************************************************************************
 * @brief Execute HW Accelerator instructions in queue
 *
 * @return HWACC_ERR_OK if successful, error otherwise. @see enum hwacc_status_t.
 ****************************************************************************************
 */
int hal_hwacc_execute(void);

#endif


