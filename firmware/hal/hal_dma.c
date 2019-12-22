#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_dma.c
 *
 * @brief DMA driver implementation file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#include "stdlib.h"
#include "stdio.h"

#include "in_arm.h"
#include "in_irq.h"

#include ".\hal\hal_clk.h"
#include ".\hal\hal_dma.h"

/*
 * Structures
 ****************************************************************************************
 */

typedef struct {
	void *pde;
	uint32_t base;

	char used;
	char chn;
	char ttype;
	char pad[1];

	void *arg;
	void (*callback)(int id, void *arg, int status);
} dma_ch_t;

typedef struct {
	uint32_t base;
	IRQn_Type irq;
	dma_ch_t ch[DMA_MAX_CH_NB];
} dma_dev_t;

static dma_dev_t dma_dev[2] = {
	{ 
		.base = DMA0_BASE,  
		.irq = Dma0_IRQn,
		.ch[0] = {
			.pde = &dma_dev[0],
			.base = DMA0_CH0_BASE,
			.used = 0,
			.chn = 0,
		},
		.ch[1] = {
			.pde = &dma_dev[0],
			.base = DMA0_CH1_BASE,
			.used = 0,
			.chn = 1,
		},
	},
	{
		.base = DMA1_BASE,
		.irq = Dma1_IRQn,
		.ch[0] = {
			.pde = &dma_dev[1],
			.base = DMA1_CH0_BASE,
			.used = 0,
			.chn = 0,
		},
		.ch[1] = {
			.pde = &dma_dev[1],
			.base = DMA1_CH1_BASE,
			.used = 0,
			.chn = 1,
		}
	}
};

/*
 * ISR
 ****************************************************************************************
 */
static void dma_isr(int id, dma_dev_t *pd)
{
	uint32_t status[DMA_MAX_CH_NB] = {0};

	dma_intr_status(pd->base, DMA_MAX_CH_NB, status);

	for (int i = 0; i < DMA_MAX_CH_NB; i++) {
		if (pd->ch[i].callback) {
			pd->ch[i].callback(id, pd->ch[i].arg, status[i]);
		}
	}
	//dma_intr_clr(pd->base, DMA_MAX_CH_NB, status);
}

__irq void DMA0_Handler(void)
{
	dma_dev_t	*pd = &dma_dev[0];

	dma_isr(DMA0_ID, pd);

}

__irq void DMA1_Handler(void)
{
	dma_dev_t	*pd = &dma_dev[1];

	dma_isr(DMA1_ID, pd);
}

/*
 * DMA APIs
 ****************************************************************************************
 */

void *hal_dma_open(int id, int periph_id, uint32_t sar, uint32_t dar, int size, int sdw, int ddw, int sai, int dai, int sbz, int dbz, int sahb, int dahb, int ttype)
{
	int i;
	dma_dev_t *pd = NULL;
	dma_ch_t *pch = NULL;

	if (id == DMA0_ID)
		pd = &dma_dev[0];
	else
		pd = &dma_dev[1];

	for (i = 0; i < DMA_MAX_CH_NB; i++) {
		if (!pd->ch[i].used) {
			pch = &pd->ch[i];
			break;
		}
	}

	if (!pch)
		return NULL;

	// config dma
	dma_enable(pd->base);		
	dma_ch_set_sar(pch->base, sar);			// soruce address
	dma_ch_set_dar(pch->base, dar);			// destination base
 	dma_ch_src_width(pch->base, sdw);
	dma_ch_dst_width(pch->base, ddw);
	dma_ch_src_inc(pch->base, sai);
	dma_ch_dst_inc(pch->base, dai);
	dma_ch_src_msize(pch->base, sbz);
	dma_ch_dst_msize(pch->base, dbz);
	dma_ch_src_ahb_master(pch->base, sahb);
	dma_ch_dst_ahb_master(pch->base, dahb);
	dma_ch_tran_type_fc(pch->base, ttype);
	dma_ch_tran_block_size(pch->base, size);
	dma_ch_hs_src(pch->base, 1);
	dma_ch_hs_dest(pch->base, 1);

	if (id == DMA0_ID) {
		dma_ch_dest_periph_id(pch->base, periph_id);		
	} else {
		dma_ch_src_periph_id(pch->base, periph_id);		
	}

	pch->used = 1;

	return (void *)pch;
}

void *hal_dma_soft_open(int id, uint32_t sar, uint32_t dar, int size, int sdw, int ddw, int sai, int dai, int sbz, int dbz, int sahb, int dahb, int ttype)
{
	int i;
	dma_dev_t *pd = NULL;
	dma_ch_t *pch = NULL;

	if ((ttype != DMA_TT_MEM_TO_PERF_FC_DMAC) && 
			(ttype != DMA_TT_PERF_TO_MEM_FC_DMAC))
		return NULL;


	if (id == DMA0_ID)
		pd = &dma_dev[0];
	else
		pd = &dma_dev[1];

	for (i = 0; i < DMA_MAX_CH_NB; i++) {
		if (!pd->ch[i].used) {
			pch = &pd->ch[i];
			break;
		}
	}

	if (!pch)
		return NULL;

	// config dma
	dma_enable(pd->base);		
	dma_ch_set_sar(pch->base, sar);			// soruce address
	dma_ch_set_dar(pch->base, dar);			// destination base
 	dma_ch_src_width(pch->base, sdw);
	dma_ch_dst_width(pch->base, ddw);
	dma_ch_src_inc(pch->base, sai);
	dma_ch_dst_inc(pch->base, dai);
	dma_ch_src_msize(pch->base, sbz);
	dma_ch_dst_msize(pch->base, dbz);
	dma_ch_src_ahb_master(pch->base, sahb);
	dma_ch_dst_ahb_master(pch->base, dahb);
	dma_ch_tran_type_fc(pch->base, ttype);
	dma_ch_tran_block_size(pch->base, size);
	dma_ch_hs_src(pch->base, 0);			// Software
	dma_ch_hs_dest(pch->base, 0);		// Software

	pch->used = 1;
	pch->ttype = ttype;

	return (void *)pch;
}

void hal_dma_close(void *hdl)
{
	dma_ch_t *pch = (dma_ch_t *)hdl;
	dma_dev_t *pd = NULL;

	if (!pch)
		return;
	
	if (pch->used)	
		pch->used = 0;

	pd = (dma_dev_t *)pch->pde;

	int disable = 1;
	for (int i = 0; i < DMA_MAX_CH_NB; i++) {
		if (pd->ch[i].used) {
			disable = 0;
			break;
		}
	}
	
	if (disable)
		dma_disable(pd->base);
}

int hal_dma_ch_enable(void *hdl, void *arg, void (*callback)(int id, void *arg, int status))
{
	dma_ch_t *pch = (dma_ch_t *)hdl;
	dma_dev_t *pd = NULL;
	uint32_t status[DMA_MAX_CH_NB] = {0}; 

	if (!pch)
		return DMA_ERR_INVALID_PARA;

	if (!pch->used)	
		return DMA_ERR_BAD_STATE;

	/// turn on force on ahb bus clocks 
	clk_force_dma_ctl_clks(1);
	 
	pd = (dma_dev_t *)pch->pde;

	pch->arg = arg;
	pch->callback = callback;
	status[pch->chn] = DMA_IT_STATUS_ALL;
	dma_intr_clr(pd->base, DMA_MAX_CH_NB, status);
	dma_intr_unmask(pd->base, pch->chn, (DMA_IT_STATUS_TFR|DMA_IT_STATUS_ERR));
	NVIC_SetPriority(pd->irq, IRQ_PRI_Normal);	
	NVIC_EnableIRQ(pd->irq);

	// enable channel
	dma_ch_enable(pd->base, pch->chn);
	
	return DMA_ERR_OK;
}

int hal_dma_soft_ch_enable(void *hdl, void *arg, void (*callback)(int id, void *arg, int status))
{
	dma_ch_t *pch = (dma_ch_t *)hdl;
	dma_dev_t *pd = NULL;
	uint32_t status[DMA_MAX_CH_NB] = {0}; 

	if (!pch)
		return DMA_ERR_INVALID_PARA;

	if (!pch->used)	
		return DMA_ERR_BAD_STATE;

	/// turn on force on ahb bus clocks 
	clk_force_dma_ctl_clks(1);
	 
	pd = (dma_dev_t *)pch->pde;

	pch->arg = arg;
	pch->callback = callback;
	status[pch->chn] = DMA_IT_STATUS_ALL;
	dma_intr_clr(pd->base, DMA_MAX_CH_NB, status);
	if (pch->ttype == DMA_TT_MEM_TO_PERF_FC_DMAC) { 	
		dma_intr_unmask(pd->base, pch->chn, DMA_IT_STATUS_TFR|DMA_IT_STATUS_DSTT);
	} else {
		dma_intr_unmask(pd->base, pch->chn, DMA_IT_STATUS_TFR|DMA_IT_STATUS_SRCT);
	}
	NVIC_SetPriority(pd->irq, IRQ_PRI_Normal);	
	NVIC_EnableIRQ(pd->irq);

	// enable channel
	dma_ch_enable(pd->base, pch->chn);
	
	return DMA_ERR_OK;
}

int hal_dma_ch_disable(void *hdl)
{
	dma_ch_t *pch = (dma_ch_t *)hdl;
	dma_dev_t *pd = NULL;

	if (!pch)
		return DMA_ERR_INVALID_PARA;

	if (!pch->used)	
		return DMA_ERR_BAD_STATE;

	pd = (dma_dev_t *)pch->pde;

	// disable channel
	dma_ch_disable(pd->base, pch->chn);

	dma_intr_mask(pd->base, pch->chn, DMA_IT_STATUS_ALL);
	NVIC_DisableIRQ(pd->irq);

	pch->arg = NULL;
	pch->callback = NULL;

	/// turn off force on ahb bus clock
	clk_force_dma_ctl_clks(0);

	return DMA_ERR_OK;
}

int hal_dma_switch_buffer(void *hdl, int sa_da, uint32_t buffer_addr)
{
	dma_ch_t *pch = (dma_ch_t *)hdl;
	dma_dev_t *pd = NULL;

	if (!pch)
		return DMA_ERR_INVALID_PARA;

	if (!pch->used)	
		return DMA_ERR_BAD_STATE;

	pd = (dma_dev_t *)pch->pde;

	if (sa_da) {
		dma_ch_set_sar(pch->base, buffer_addr);			// soruce address
	} else {
		dma_ch_set_dar(pch->base, buffer_addr);			// destination base
	}

	// enable channel
	dma_ch_enable(pd->base, pch->chn);

	return DMA_ERR_OK;
}

int hal_dma_src_req(void *hdl)
{
	dma_ch_t *pch = (dma_ch_t *)hdl;
	dma_dev_t *pd = NULL;

	if (!pch)
		return DMA_ERR_INVALID_PARA;

	if (!pch->used)	
		return DMA_ERR_BAD_STATE;

	pd = (dma_dev_t *)pch->pde;

	dma_sw_src_req(pd->base, pch->chn);
	dma_sw_src_sreq(pd->base, pch->chn);

	return DMA_ERR_OK;
}

int hal_dma_dst_req(void *hdl)
{
	dma_ch_t *pch = (dma_ch_t *)hdl;
	dma_dev_t *pd = NULL;

	if (!pch)
		return DMA_ERR_INVALID_PARA;

	if (!pch->used)	
		return DMA_ERR_BAD_STATE;

	pd = (dma_dev_t *)pch->pde;

	dma_sw_dst_req(pd->base, pch->chn);
	dma_sw_dst_sreq(pd->base, pch->chn);

	return DMA_ERR_OK;
}

uint32_t hal_dma_get_tran_len(void *hdl)
{
	dma_ch_t *pch = (dma_ch_t *)hdl;

	if (!pch)
		return DMA_ERR_INVALID_PARA;

	if (!pch->used)	
		return DMA_ERR_BAD_STATE;

	return dma_ch_get_tran_block_size(pch->base);
}

