#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_hwacc.c
 *
 * @brief Platform adpcm functions  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */

/*
 ****************************************************************************************
 * INCLUDES
 ****************************************************************************************
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "in_mmap.h"
#include "in_arm.h"
#include "in_irq.h"
#include "hal_hwacc.h"

#include "cmsis_os.h"

/*
 ****************************************************************************************
 * IMPLEMENTATION
 ****************************************************************************************
 */

// User Control
typedef struct {	
	uint8_t used;	
	uint16_t num_inst;
	uint32_t inst_offset;
	uint32_t inst_size;
	
	uint8_t intr_status;	
	osMutexId mutex;
	osSemaphoreId semaphore; 

	/// Power 
#if CFG_PM_EN
	int power_state;
	struct pm_module pm;
#endif
} hwacc_dev_t;

static hwacc_dev_t hwacc_dev;
osMutexDef(mutex);
osSemaphoreDef(semaphore);

// Audio Power state config
#if CFG_PM_EN
static int hwacc_power_state(uint32_t *sleep_duration) {
	hwacc_dev_t *pd = &hwacc_dev;
	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->power_state;
}

static void hwacc_power_down(uint32_t sleep_duration) {
	return;
}

static void hwacc_power_up(void) {
	/// TODO: pin mux, etc...
}
#endif	/* CFG_PM_EN */

__irq void Hwacc_Handler()
{
	hwacc_dev_t* pd = &hwacc_dev;
	pd->intr_status = hwacc_get_intr_status();
	hwacc_intr_clear();
	osSemaphoreRelease(pd->semaphore);	
}

// User hwacc setup 
int hal_hwacc_open() {
	hwacc_dev_t* pd = &hwacc_dev;
	if(pd->used)
		return HWACC_ERR_ALREADY_INIT;

	// Initialize state
	pd->used = 1;
	pd->num_inst = 0;
	pd->intr_status = 0;	
	// Initialize instruction offsets based on config file
	pd->inst_offset = CFG_SMEM_HW_ACCEL_INST >> 16;
	pd->inst_size = CFG_SMEM_HW_ACCEL_INST & 0xFFFF;
	// Initialize HWACC memory access control
	hwacc_mem_acc_ahb();
	// Set inverse_min_pivot value corresponding to 1e-10
	hwacc_set_min_pv(0x2EDBE6FF);
	// Enable pivot value search; check_min_pv_on; check zero pv
	hwacc_pv_search_enable();
	hwacc_check_min_pv_enable();
	hwacc_check_zero_pv_enable();

	pd->mutex = osMutexCreate(osMutex(mutex));
	if (!pd->mutex)
		goto fail;
	pd->semaphore = osSemaphoreCreate(osSemaphore(semaphore), 0);
	if (!pd->semaphore)
		goto fail;

#if CFG_PM_ENABLE
	pd->pm.power_state = hwacc_power_state;
	pd->pm.power_down = hwacc_power_down;
	pd->pm.power_up = hwacc_power_up;
	pd->pm.arg = (void *)pd; 
	hal_pm_reg_mod(&pd->pm);
	pd->power_state = PM_DEEP_SLEEP;
#endif

	osMutexWait(pd->mutex, osWaitForever);	
	
	return HWACC_ERR_OK;

fail:
	if (pd->mutex) {
		osMutexDelete(pd->mutex);
		pd->mutex = NULL;
	}
	if (pd->semaphore) {
		osSemaphoreDelete(pd->semaphore);	
		pd->semaphore = NULL;
	}
	return HWACC_ERR_BAD_STATE;
}

int hal_hwacc_close() {
	hwacc_dev_t* pd = &hwacc_dev;
	if(pd->used)
		return HWACC_ERR_NOT_INIT;
	pd->used = 0;
	pd->num_inst = 0;

	osMutexWait(pd->mutex, osWaitForever);
	osMutexRelease(pd->mutex);

	if (pd->mutex) {
		osMutexDelete(pd->mutex);
		pd->mutex = NULL;
	}	
	if (pd->semaphore) {
		osSemaphoreDelete(pd->semaphore);
		pd->semaphore = NULL;
	}

#if CFG_PM_ENABLE
	hal_pm_unreg_mod(&pd->pm);
#endif

	return HWACC_ERR_OK;
}

int hal_hwacc_write_matrix(hwacc_matrix_desc_t *matrix, float *head) {
	hwacc_dev_t* pd = &hwacc_dev;
	if(!pd->used)
		return HWACC_ERR_NOT_INIT;

	if (matrix->mem_block==0)
		memcpy((float*)(HWACC_MEM_0_BASE_ADDR + (matrix->offset << 2)), head, (matrix->ncols*matrix->nrows)<<2);
	else if (matrix->mem_block==1)
		memcpy((float*)(HWACC_MEM_1_BASE_ADDR + (matrix->offset << 2)), head, (matrix->ncols*matrix->nrows)<<2);
	else if (matrix->mem_block==2)
		memcpy((float*)(HWACC_MEM_2_BASE_ADDR + (matrix->offset << 2)), head, (matrix->ncols*matrix->nrows)<<2);
	else
		memcpy((float*)(HWACC_MEM_3_BASE_ADDR + (matrix->offset << 2)), head, (matrix->ncols*matrix->nrows)<<2);	
	
	return HWACC_ERR_OK;
}

int hal_hwacc_read_matrix(hwacc_matrix_desc_t *matrix, float *head) {
	hwacc_dev_t* pd = &hwacc_dev;
	if(!pd->used)
		return HWACC_ERR_NOT_INIT;

	if (matrix->mem_block==0)
		memcpy(head, (float*)(HWACC_MEM_0_BASE_ADDR + (matrix->offset<<2)), (matrix->ncols*matrix->nrows)<<2);
	else if (matrix->mem_block==1)
		memcpy(head, (float*)(HWACC_MEM_1_BASE_ADDR + (matrix->offset<<2)), (matrix->ncols*matrix->nrows)<<2);
	else if (matrix->mem_block==2)
		memcpy(head, (float*)(HWACC_MEM_2_BASE_ADDR + (matrix->offset<<2)), (matrix->ncols*matrix->nrows)<<2);
	else
		memcpy(head, (float*)(HWACC_MEM_3_BASE_ADDR + (matrix->offset<<2)), (matrix->ncols*matrix->nrows)<<2);	
	
	return HWACC_ERR_OK;	
}

static int hal_hwacc_matrix_op_dim_check(hwacc_matrix_desc_t *matrix_C, hwacc_matrix_desc_t *matrix_A, hwacc_matrix_desc_t *matrix_B, hwacc_op_t op) {
	if(op == HWACC_OP_COPY) {
		if((matrix_C->nrows != matrix_B->nrows) || (matrix_C->ncols != matrix_B->ncols))
			return HWACC_ERR_DIMENSION_MISMATCH;
	}
	else if(op == HWACC_OP_ADD) {
		if((matrix_C->nrows != matrix_B->nrows) || (matrix_C->ncols != matrix_B->ncols) || (matrix_C->nrows != matrix_A->nrows) || (matrix_C->ncols != matrix_A->ncols))
			return HWACC_ERR_DIMENSION_MISMATCH;
	}
	else if(op == HWACC_OP_SUB) {
		if((matrix_C->nrows != matrix_B->nrows) || (matrix_C->ncols != matrix_B->ncols) || (matrix_C->nrows != matrix_A->nrows) || (matrix_C->ncols != matrix_A->ncols))
			return HWACC_ERR_DIMENSION_MISMATCH;
	}
	else if(op == HWACC_OP_MUL) {
		if((matrix_C->ncols != matrix_B->ncols) || (matrix_C->nrows != matrix_A->nrows)|| (matrix_B->nrows != matrix_A->ncols) || (matrix_B->nrows != matrix_A->ncols))
			return HWACC_ERR_DIMENSION_MISMATCH;
	}
	else if(op == HWACC_OP_INV) {
		if((matrix_C->nrows != matrix_A->nrows) || (matrix_C->ncols != matrix_A->ncols))
			return HWACC_ERR_DIMENSION_MISMATCH;
	}
	else if(op == HWACC_OP_EQU) {
		if((matrix_C->ncols != matrix_A->ncols) || (matrix_C->nrows != matrix_A->nrows)|| (matrix_B->nrows != matrix_A->ncols) || (matrix_B->ncols != 1))
			return HWACC_ERR_DIMENSION_MISMATCH;
	}	
	else if(op == HWACC_OP_CLEAR) {
		if((matrix_C->nrows != matrix_A->nrows) || (matrix_C->ncols != matrix_A->ncols))
			return HWACC_ERR_DIMENSION_MISMATCH;	
	}
	else if(op == HWACC_OP_SCALE) {
		if((1 != matrix_B->nrows) || (1 != matrix_B->ncols) || (matrix_C->nrows != matrix_A->nrows) || (matrix_C->ncols != matrix_A->ncols))
			return HWACC_ERR_DIMENSION_MISMATCH;	
	}
	else
		return HWACC_ERR_BAD_INPUT;
	return HWACC_ERR_OK;
}

int hal_hwacc_insert_inst(hwacc_matrix_desc_t *matrix_C, int C_symm, hwacc_matrix_desc_t *matrix_A, int A_trans, hwacc_matrix_desc_t *matrix_B, int B_trans, hwacc_op_t op) {
	hwacc_dev_t* pd = &hwacc_dev;
	if(!pd->used)
		return HWACC_ERR_NOT_INIT;

	if(pd->inst_size < ((pd->num_inst + 1) * 0xC))
		return HWACC_ERR_INST_OVERFLOW;

	int result = hal_hwacc_matrix_op_dim_check(matrix_C, matrix_A, matrix_B, op);
	if(result != HWACC_ERR_OK)
		return result;
	
	// Write word index 0: result matrix descriptor
	uint32_t reg = (matrix_C->mem_block & 0x3) | ((matrix_C->offset & 0x1FF) << 2) | ((C_symm & 0x1) << 20) | ((((int)op) & 0x7) << 29);
	WR_WORD((0x44140000 + pd->inst_offset + (pd->num_inst * 0xC)), reg);

	// Write word index 1: matrix A descriptor
	if(op == HWACC_OP_COPY)
		reg = 0;
	else if(op == HWACC_OP_CLEAR)
		reg = ((matrix_A->nrows & 0xF) << 11) | ((matrix_A->ncols & 0xF) << 16) | (1 << 21);
	else
		reg = (matrix_A->mem_block & 0x3) | ((matrix_A->offset & 0x1FF) << 2) | ((matrix_A->nrows & 0x1F) << 11) | ((matrix_A->ncols & 0x1F) << 16) | ((A_trans & 0x1) << 21);
	WR_WORD((0x44140000 + pd->inst_offset + (pd->num_inst * 0xC) + 0x4), reg);

	// Write word index 2: matrix B descriptor
	if(op == HWACC_OP_INV || op == HWACC_OP_CLEAR)
		reg = 0;
	else
		reg = (matrix_B->mem_block & 0x3) | ((matrix_B->offset & 0x1FF) << 2) | ((matrix_B->nrows & 0x1F) << 11) | ((matrix_B->ncols & 0x1F) << 16) | ((B_trans & 0x1) << 21);
	WR_WORD((0x44140000 + pd->inst_offset + (pd->num_inst * 0xC) + 0x8), reg);
	
	pd->num_inst++;
	
	return HWACC_ERR_OK;
}

int hal_hwacc_execute(void) {
	hwacc_dev_t* pd = &hwacc_dev;
	if(!pd->used)
		return HWACC_ERR_NOT_INIT;
	
	// Enable HWACC block
	hwacc_enable();	
	// Set HWACC memory access to computation core
	hwacc_mem_acc_comp_core();
	// Initialize number of instruction operations
	hwacc_set_num_inst(pd->num_inst);
	
	// Enable interrupts
	hwacc_mask_clear();
	NVIC_EnableIRQ(Hwacc_IRQn);	
	
	// Start HWACC computation
	hwacc_start();
	
	/// Wait for execution complete
	osSemaphoreWait(pd->semaphore, osWaitForever);
	
	// Disable interrupts
	hwacc_mask_set();
	NVIC_DisableIRQ(Hwacc_IRQn);
	
	// Set HWACC memory access to AHB
	hwacc_mem_acc_ahb();
	
	pd->num_inst = 0;
	
	if(pd->intr_status != 1)
		return HWACC_ERR_CONFIG_ERROR;
	else
		return HWACC_ERR_OK;
}

