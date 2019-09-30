/**
 ****************************************************************************************
 *
 * @file inb_plt.c
 *
 * @brief Porting to support BLE statck source code 
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 *
 ****************************************************************************************
 */
#include "in_config.h"

#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "stdarg.h"

#include "in_arm.h"
#include "in_irq.h"
#include "in_debug.h"
#include "cmsis_os.h"

#include ".\hal\hal_uart.h"
#include ".\hal\hal_smem.h"
#include ".\hal\hal_clk.h"

#if CFG_PM_EN
#include ".\hal\hal_power.h"
#endif
#include "..\inc\inb_config.h"
#include "..\inc\inb_plt.h"
#include ".\ble\inb_api.h"

#if CFG_PM_EN
static struct pm_module g_ble_pm;
#endif

#ifdef ASSERT_DISPLAY
uint8_t assert_display_flag=0;
 char assert_file[16]={0}; 
int assert_line=0;
int assert_param0=0;
int assert_param1=0;
#endif

/**********************************************************************
*
*
*	BLE ISR
*
*
**********************************************************************/
__irq void BLE_Core_Handler()
{
	inb_isr();
}

/**********************************************************************
*
*
*	BLE port
*
*
**********************************************************************/

static void inb_srand(uint32_t seed)
{
	/// Review: 
	///		If already initialie, then comment out the following
	/// 
	srand(seed);
}

static uint32_t inb_rand(void)
{
	return rand();
}

static void *inb_uart_init(void)
{
#if CFG_HCI
    if(!isHciEnable())
        return NULL;
    
	//int id = CFG_HCI_UART_ID;
	void *h_uart;

	h_uart = hal_uart_open(CFG_HCI_UART_ID, CFG_HCI_UART_BAUD, 8, 0, 0, 0, 1, UART_RT_HALF_FULL, CFG_HCI_FC, 0);

	return h_uart;
#else
	return NULL;
#endif	
}

static void inb_uart_deinit(void *hdl)
{
#if CFG_HCI
	hal_uart_close(hdl);
#endif
}

static int inb_uart_write(void *hdl, uint8_t *buffer, uint16_t buffer_len, void *arg, void (*callback)(void *, int, int ))
{
#if CFG_HCI
	int err;

	err = hal_uart_xmit_intr(hdl, buffer, buffer_len, arg, callback);
	return err;
#else
	return UART_ERR_CFG;
#endif
}

static int inb_uart_read(void *hdl, uint8_t *buffer, uint16_t buffer_len, void *arg, void(*callback)(void *, int, int))
{
#if CFG_HCI
	int err;
	err = hal_uart_rcvd_intr(hdl, buffer, buffer_len, arg, callback);
	return err;
#else
	return UART_ERR_CFG;
#endif
}

static int inb_uart_flow_on(void *hdl)
{
#if CFG_HCI
	int err;
	err = hal_uart_flow_on(hdl);
	return err;
#else
	return UART_ERR_CFG;
#endif
}

static int inb_uart_flow_off(void *hdl)
{
#if CFG_HCI
	int err;
	err = hal_uart_flow_off(hdl);
	return err;
#else
	return UART_ERR_CFG;
#endif
}

static void inb_flash_read(uint32_t addr, uint32_t length, uint8_t *buffer)
{
	/// HW XIP will take care of it.
	memcpy(buffer, (void *)addr, length);
}

static void inb_flash_write(uint32_t addr, uint32_t length, uint8_t *buffer)
{
#if CFG_FPGA
	memcpy((void *)addr, buffer, length); 
#else
	/// Review: Need to call BOOT RAM SPI flash write 

#endif
}

static void inb_flash_erase(uint32_t addr, uint32_t length)
{
#if CFG_FPGA
	memset((void *)addr, 0, length);
#else

#endif
}

// The mutex object needs to be able to nested...
static void *inb_os_mutex_create(void)
{
#if 0
	in_ble_mutex_t *p_mutex = NULL;

	for (int i = 0; i < BLE_NB_MUTEX; i++) {
		if (!mutex[i].used) {
			p_mutex = &mutex[i];
			break;
		}
	}

	if (!p_mutex)
		return NULL;

	osMutexDef_t def;

	def.mutex = p_mutex->mutex;

	osMutexId mid = osMutexCreate(&def);
	if (!mid) 
		return NULL;

	p_mutex->mid = mid;
	p_mutex->used = 1;
	
	return (void *)mid;
#else
	return NULL;
#endif
}

static void inb_os_mutex_delete(void *h)
{
#if 0
	in_ble_mutex_t *p_mutex = NULL;

	for (int i = 0; i < BLE_NB_MUTEX; i++) {
		if (mutex[i].used) {
			if (mutex[i].mid == h) {
				p_mutex = &mutex[i];
				break;
			}
		}
	}
	
	if (!p_mutex)
		return;

	osMutexId mid = (osMutexId)h;
	osMutexDelete(mid);

	p_mutex->used = 0;
	p_mutex->mid = 0;
#endif	
}

static void inb_os_mutex_lock(void *h)
{
#if 0
	osMutexId mid = (osMutexId)h;
	osStatus status;

	status = osMutexWait(mid, osWaitForever);
	if (status != osOK) {
		//printf("OSL: lock fail,%d\r\n", res);
	}

	return;
#endif
}

static void inb_os_mutex_unlock(void *h)
{
#if 0
	osMutexId mu = (osMutexId)h;
	osStatus status;

	status = osMutexRelease(mu);
	if (status != osOK) {
		//printf("OSL: lock fail,%d\r\n", res);
	}

	return;
#endif
}

static void *inb_os_semaphore_create(void)	
{
#if 0
#if BLE_NB_SEMAPHORE
	in_ble_semaphore_t *p_semaphore = NULL;

	for (int i = 0; i < BLE_NB_SEMAPHORE; i++) {
		if (!semaphore[i].used) {
			p_semaphore = &semaphore[i];
			break;
		}
	}

	if (!p_semaphore)
		return NULL;

	osSemaphoreDef_t def;

	def.semaphore = p_semaphore->semaphore;

	osSemaphoreId sid = osSemaphoreCreate(&def, 0);	/* lock */
	if (!sid) 
		return NULL;

	p_semaphore->sid = sid;
	p_semaphore->used = 1;
	
	return (void *)sid;

#else

	return NULL;

#endif
#else
	return NULL;
#endif
}

static void inb_os_semaphore_delete(void *h)	
{
#if 0
#if BLE_NB_SEMAPHORE
	in_ble_semaphore_t *p_semaphore = NULL;

	for (int i = 0; i < BLE_NB_SEMAPHORE; i++) {
		if (semaphore[i].used) {
			if (semaphore[i].sid == h) {
				p_semaphore = &semaphore[i];
				break;
			}
		}
	}

	if (!p_semaphore)
		return;

	osSemaphoreId sid = (osSemaphoreId)h;
	osSemaphoreDelete(sid);	

	p_semaphore->used = 0;
	p_semaphore->sid = 0;
#endif

	return;
#endif
}

static int inb_os_semaphore_wait(void *h)	
{
#if 0
	osSemaphoreId sma = (osSemaphoreId)h;
	int res;

	res = osSemaphoreWait(sma, osWaitForever);

	return res;		
#else
	return 0;
#endif
}

static int inb_os_semaphore_release(void *h)	
{
#if 0
	osSemaphoreId sma = (osSemaphoreId)h;
	osStatus status;

	status = osSemaphoreRelease(sma);

	if (status != osOK)
		return -1;

	return 0;		
#else
	return 0;		
#endif
}

static void *inb_os_task_create(char *name, void (*func)(void const *), void *arg)
{
#if 0
	osThreadDef_t def;

	def.pthread = func;
	def.instances = 1;
	if (strcmp(name, "isr") == 0) {
		def.tpriority = osPriorityRealtime;
		def.stacksize = CFG_BLE_ISR_TASK_STKSIZE; 
	} else if (strcmp(name, "stack") == 0) {
		def.tpriority = osPriorityAboveNormal;
		def.stacksize = CFG_BLE_STACK_TASK_STKSIZE; 
	} else if (strcmp(name, "event") == 0) {
		def.tpriority = osPriorityNormal;
		def.stacksize = CFG_BLE_EVENT_TASK_STKSIZE; 
	}

	osThreadId tid;

	tid = osThreadCreate(&def, arg);
	if (!tid) {
		return NULL;
	}

	return (void *)tid;
#else
	return NULL;
#endif
}

static void inb_os_task_delete(void *h)
{
#if 0
	osThreadId tid = (osThreadId)h;
	
	if (tid)
		osThreadTerminate(tid);
#endif
}

static int inb_os_task_wait(void *h)
{
#if 0
	//osThreadId tid = (osThreadId)h;
	osEvent evt;
	int ret;

	evt = osSignalWait(0, osWaitForever);
	
	if (evt.status == osEventSignal) {
		ret = evt.value.signals;		
	} else {
		if (evt.status == osEventTimeout) {
			ret = -1;
		} else {
			if (evt.status == osOK) {
				ret = 0;
			} else {
				ret = -2;
			}
		}
	}

	return ret;
#else
	return 0;
#endif
}

static void inb_os_task_signal(void *h)
{
#if 0
	osThreadId tid = (osThreadId)h;

	// Could signal from ISR
	osSignalSet(tid, 0x1);
#endif
}

#if 0
static void *inb_os_get_task_id(void)
{
	osThreadId id;

	id = osThreadGetId();

	return (void *)id;
}
#endif

static void *inb_os_queue_create(void *q, int q_sz)
{
#if 0
	osMessageQDef_t def;

	def.pool = q;
	def.queue_sz = q_sz;

	osMessageQId qid = osMessageCreate(&def, NULL);
	if (qid == NULL) {
		//printf("OSL: failed create message queue\r\n");
	}

	return (void *)qid;
#else
	return NULL;
#endif
}

static void inb_os_queue_put(void *qid, uint32_t message)
{
#if 0
	osStatus status;

	status = osMessagePut((osMessageQId)qid, message, 0);

	if (status != osOK) {
		//printf("OSL: failed put in the queue, %d\r\n", status);
	}
#endif
}

static uint32_t inb_os_queue_get(void *qid)
{
#if 0
	osEvent evt;

	evt = osMessageGet((osMessageQId)qid, osWaitForever);
	if (evt.status == osEventMessage) {
		return evt.value.v; 		
	} else {
		//printf("OSL: failed get from the queue, %d\r\n", evt.status);

	}

	return 0;
#else
	return 0;
#endif
}

static void inb_irq_disable(void)
{
	NVIC_DisableIRQ(Ble_IRQn);
}

static void inb_irq_enable(void)
{
	NVIC_SetPriority(Ble_IRQn, IRQ_PRI_RealTime);
	NVIC_EnableIRQ(Ble_IRQn);
}

static void inb_plt_init(uint32_t *sz)
{
	hal_clk_ble_en(1);

	uint32_t offset = (CFG_SMEM_BLE>>16) & 0xFFFF;
	*sz = CFG_SMEM_BLE & 0xFFFF; 

	/// Clear the Ble exchange memory
	memset((void *)(SMEM_BASE + offset), 0, *sz);
}


void inb_assert_error(const char *file, int line)
{
	PRINTD(DBG_ERR, "Assert Error, file = %s, line = %d\r\n", file, line);
	
	// TODO
	#ifdef ASSERT_DISPLAY
	if(assert_display_flag == 0)
	{
		strncpy(assert_file,file,16);
		assert_line=line;
		assert_param0=0xffff;
		assert_param1=0xffff;
		assert_display_flag=1;
		
	}
	#endif
}

static void inb_assert_param(const char *file, int line, int param0, int param1)
{
	PRINTD(DBG_ERR, "Assert Param, file = %s, line = %d, param0 = %d, param1 = %d\r\n", file, line, param0, param1);
	// TODO
	#ifdef ASSERT_DISPLAY
	if(assert_display_flag == 0)
	{
		strncpy(assert_file,file,16);
		assert_line=line;
		assert_param0=param0;
		assert_param1=param1;
		assert_display_flag=1;
	}
	#endif
}

static void inb_assert_warn(const char *file, int line, int param0, int param1)
{
	PRINTD(DBG_ERR, "Assert Warn, file = %s, line = %d, param0 = %d, param1 = %d\r\n", file, line, param0, param1);

	#ifdef ASSERT_DISPLAY
	if(assert_display_flag == 0)
	{
		strncpy(assert_file,file,16);
		assert_line=line;
		assert_param0=param0;
		assert_param1=param1;
		assert_display_flag=1;
	}
	#endif
	// TODO
}

static void inb_trace(uint32_t flag, char *fmt, ...)
{
	char str[64];
	va_list args;

	va_start(args, fmt);
	vsnprintf(str, 64, fmt, args);
	va_end(args);
	
	PRINTD(DBG_TRACE, str);		

	return;
}

static void inb_power_register(uint32_t em_end, int (*pow_state)(void *arg, uint32_t *duration), void (*pow_down)(void *arg, uint32_t duration), void (*pow_up)(void * arg))
{
#if CFG_PM_EN

	if (CFG_SMEM_AHB_TRIG_RETN_EN) {
		hal_smem_retn(1, ((CFG_SMEM_AHB_TRIG>>16)&0xFFFF), (CFG_SMEM_AHB_TRIG&0xFFFF));
	}

	if (CFG_SMEM_BLE_RETN_EN) {
		hal_smem_retn(1, ((CFG_SMEM_BLE>>16)&0xFFFF), em_end);
	}

	g_ble_pm.arg = NULL;
	g_ble_pm.power_state = pow_state;
	g_ble_pm.power_down = pow_down;
	g_ble_pm.power_up = pow_up;
	hal_pm_reg_ble_mod(&g_ble_pm);
#endif
}

void *inb_mem_alloc(int size)
{
	return malloc(size);
}

void inb_mem_free(void *ptr)
{
	free(ptr);
	return;
}

void *inb_get_command_pool(void)	/// Not used
{
	return NULL;
}

int inb_get_command_pool_size(void)		/// Not used
{
	return 0;
}

void *inb_get_conn_pool(void)	/// Not used
{
	return NULL;
}

int inb_get_conn_pool_size(void)	/// Not used
{
	return 0;
}

void inb_platform_reset(uint32_t reson)		
{
	// TODO
	__breakpoint(3);
}

uint32_t get_rtc_clk(void)
{
	return hal_clk_rtc_get();
}

const plat_fun_t plat_fun = {
	inb_srand,
	inb_rand,
	inb_uart_init,
	inb_uart_write,
	inb_uart_read,
	inb_uart_flow_on,
	inb_uart_flow_off,
	inb_flash_read,
	inb_flash_write,
	inb_flash_erase,
	inb_os_mutex_create,	/// Not used
	inb_os_mutex_delete,	/// Not used
	inb_os_mutex_lock,		/// Not used
	inb_os_mutex_unlock,	/// Not used

	inb_os_task_create,
	inb_os_task_delete,
	inb_os_task_wait,
	inb_os_task_signal,
	inb_os_queue_create,
	inb_os_queue_put,
	inb_os_queue_get,

	inb_irq_disable,
	inb_irq_enable,
	inb_plt_init,
	inb_assert_error,
	inb_assert_param,
	inb_assert_warn,
	inb_trace,

	inb_power_register,
	inb_os_semaphore_create,
	inb_os_semaphore_delete,
	inb_os_semaphore_wait,
	inb_os_semaphore_release,
	inb_mem_alloc,
	inb_mem_free,

	inb_get_command_pool,
	inb_get_command_pool_size,
	inb_get_conn_pool,
	inb_get_conn_pool_size,

	inb_uart_deinit,
	inb_platform_reset,
};

