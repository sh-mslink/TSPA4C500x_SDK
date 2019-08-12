#include "in_config.h"

/**
 ****************************************************************************************
 *
 * @file hal_power.c
 *
 * @brief Power management implementation file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "cmsis_os.h"

#include "in_arm.h"
#include "in_config.h"
#include "in_debug.h"
#include "in_irq.h"

#include ".\hal\hal_clk.h"
#include ".\hal\hal_power.h"
#include ".\hal\hal_timer.h"
#include ".\hal\hal_uart.h"
#include ".\hal\hal_global.h"
#include ".\hal\hal_gpio.h"

#if CFG_PM_EN

__irq void TIM2_Handler()
{
	/// clear timer interrupt
	timer_clear_intr(TIM2_BASE);
}

static void tmr2_start(uint32_t usec)
{
	uint32_t tick;
	float rtc = (float)hal_clk_rtc_get();

	if (usec == PM_MAX_SLEEP_TIME) {
		tick = PM_MAX_SLEEP_TIME;
	} else {
		tick = (uint32_t)((rtc/1000000.f) * usec);
	}

	NVIC_ClearPendingIRQ(Tim2_IROn);
	timer_disable(TIM2_BASE);
	timer_set_mode(TIM2_BASE, 1);	
	timer_load_count(TIM2_BASE, tick);
	timer_intr_mask(TIM2_BASE, 0);	/// unmask it
	NVIC_SetPriority(Tim2_IROn, IRQ_PRI_Normal);	
	NVIC_EnableIRQ(Tim2_IROn);
	timer_enable(TIM2_BASE);
}

static void tmr2_stop(void)
{
	timer_disable(TIM2_BASE);
	timer_intr_mask(TIM2_BASE, 1);	
	NVIC_DisableIRQ(Tim2_IROn);
}

/*
 * Sleep timer Functions
 ****************************************************************************************
 */

/// Call from global interrupt service routine
void hal_sleep_timer_intr_handler(void)
{
	uint32_t status = aon_sleep_timer_intr_status();

	if (status & 0x1) {
		aon_sleep_timer_intr_clr(SLEEP_TIMER0_ID);
	} 

	if (status & 0x2) {
		aon_sleep_timer_intr_clr(SLEEP_TIMER1_ID);
	} 
}

static void hal_sleep_timer_start(int id, uint32_t us, int int_en, int wup_en, int reload)
{
	uint32_t tick;
	float rtc = (float)hal_clk_rtc_get();

	if (us == PM_MAX_SLEEP_TIME) {
		tick = PM_MAX_SLEEP_TIME;
	} else {
		tick = (uint32_t)(us * (rtc/1000000.f));
	}

	/// Clear interrupt 
	aon_sleep_timer_intr_clr(id);

	/// Program initial value 	
	aon_sleep_timer_set_init_value(id, tick);

	/// Program interrupt 
	if (int_en) {
		aon_sleep_timer_intr_enable(id);
		NVIC_SetPriority(Global_IRQn, IRQ_PRI_Normal);	
		NVIC_EnableIRQ(Global_IRQn);
	} 

	/// Program wake up 
	if (wup_en) {
		aon_sleep_timer_wup_enable(id);
	} 

	/// Reload
	aon_sleep_timer_reload(id, reload);

	/// Enable it 
	aon_sleep_timer_enable(id);			

	/// Review...
#if 0
	/// Wait until value updated
	uint32_t tick1= 0, count = 0;
	while (1) {
		hal_timer_delay_us(10);

		tick1 = sleep_timer_value(id);
		if ((tick1 >= tick) || (count > 5))
			break;
		else
			count++;
	}

	if (count >= 5)
		uart_write_data(UART0_BASE, 'M');
#endif

	// disable ext wake up 
	uint32_t reg = aon_read(0x1288);
	reg &= ~(1 << 4);
	aon_write(0x1288, reg); 

	return;
}

static void hal_sleep_timer_stop(int id) 
{
	aon_sleep_timer_intr_disable(id);
	aon_sleep_timer_wup_disable(id);

	/// Disable it 
	aon_sleep_timer_disable(id);

	return;
}

static uint32_t hal_sleep_timer_read_tick(int id)
{
	uint32_t s1, s2;

	// inplay: avoid edge...
	while (1) {
		s1 = sleep_timer_value(id);		
		s2 = sleep_timer_value(id);		
		if (s1 == s2)
			break;
	}	

	return s2;
}

static uint32_t hal_sleep_timer_tick_diff(uint32_t s_tick, uint32_t e_tick)
{
	uint32_t rtc = hal_clk_rtc_get();
	uint32_t diff = 0;

	if (s_tick >= e_tick) {
		diff = (uint32_t)((s_tick - e_tick)/(rtc/1000000.f));
	} else {
		diff = (uint32_t)((s_tick + (0xFFFFFFFF - e_tick))/(rtc/1000000.f));
	}

	return diff;
}

static int hal_sleep_timer_read(int id) __attribute__((unused));
static int hal_sleep_timer_read(int id)
{
	uint32_t init_tick = aon_sleep_timer_get_init_value(id);
	uint32_t tick = sleep_timer_value(id);
	uint32_t rtc = hal_clk_rtc_get();

	if (init_tick >= tick)
		tick = (uint32_t)((init_tick - tick ) /(rtc/1000000.f));
	else 
		tick = (uint32_t)(init_tick/(rtc/1000000.f));

	return tick;
}

/*
 * PM Functions
 ****************************************************************************************
 */

/*
 * Structure
 ****************************************************************************************
 */

typedef struct {
	struct pm_module *head;
	struct pm_module *last;
	int count;
} module_t;

typedef struct {
	char slp_wup;
	char pad[2];
	uint32_t deep_sleep_comp_time_us;

	uint32_t mu[4];
	osMutexId h_mu;

	struct pm_module *ble_mod;
	module_t mod;
} pm_drv_t;

static pm_drv_t g_pm = {0};

/*
 * Shut down and Resume Functions
 ****************************************************************************************
 */

__asm void shutdown_and_resume(void)
{
	push	{r0-r12, lr}	; store general register	
	mrs r0, primask	; store special register
	mrs r1, basepri
	mrs r2, faultmask
	mrs r3, control
	mrs r4, msp
	mrs r5, psp
	push {r0-r5}
	mov  r0, #0x100C	; AON write SP
	movt r0, #0x4411
	str   sp, [r0, #0]
	mov  r0, #0x1008	
	movt r0, #0x4411
	mov	r1, #0x11A0
	orr r1, r1, #0x10000		
	str r1, [r0, #0]
loop1
	ldr r1, [r0]
	tst r1, #0x100000	
	beq loop1
	mov  r0, #0x100C	; AON write PC
	movt r0, #0x4411
	ldr r1, =resume
	orr r1, r1, #0x80000000		
	str   r1, [r0, #0]
	mov  r0, #0x1008	
	movt r0, #0x4411
	mov	r1, #0x11A4
	orr r1, r1, #0x10000		
	str r1, [r0, #0]
loop2
	ldr r1, [r0, #0]
	tst r1, #0x100000	
	beq loop2
	ldr r0, = 0x441262c0
	mov r1, #0x1
	str r1, [r0, #0]				; Sleep
forever
	b forever
resume
;	bkpt #0x3
	pop {r0-r5}
	msr psp, r5
	msr msp, r4
	msr control, r3
	msr faultmask, r2
	msr basepri, r1
	msr primask, r0
	pop {r0-r12, lr}	
	bx lr
}

/*
 * APIs
 ****************************************************************************************
 */

int hal_pm_init(int slp_wup, int ble_wup, int bod_wup, int mix_wup, uint32_t dm_retn)
{
	pm_drv_t *pd = &g_pm;

	/// mutex protect PM modules list
	osMutexDef_t def;
	def.mutex = pd->mu;
	pd->h_mu = osMutexCreate(&def);
	if (!pd->h_mu) {
		return PM_ERR_OS_ERROR;
	}

	aon_gpio_wup_mask();
	aon_deep_sleep_enable(1);

	if (slp_wup) {
		aon_sleep_timer_global_wup_enable();
		pd->slp_wup = 1;
	} else {
		aon_sleep_timer_global_wup_disable();
		pd->slp_wup = 0;
	}

	if (ble_wup)	
		aon_ble_wup_enable();
	else
		aon_ble_wup_disable();

	if (bod_wup)
		aon_brown_out_wup_enable();
	else
		aon_brown_out_wup_disable();
		
	if (mix_wup)
		aon_mixed_signal_wup_enable();
	else
		aon_mixed_signal_wup_disable();

	/// DM retention
	aon_dm_reten(dm_retn);

	/// Enable trig memory retention
	aon_trig_mem_retn_en(1);

	/// Sleep timer free running
	hal_sleep_timer_start(SLEEP_TIMER1_ID, PM_MAX_SLEEP_TIME, 0, 0, 1);

	/// enable WIC
	wic_en(1);

	pd->deep_sleep_comp_time_us = CFG_PM_DEEP_SLEEP_COMP_TIME;

	return PM_ERR_NO_ERROR;
}

void hal_pm_em_reten(uint32_t retn)
{
	aon_em_reten(1, retn);
	return;
}
  
void hal_pm_dm_reten(uint32_t retn)
{
	aon_dm_reten(retn);
	return;
}

int hal_pm_reg_mod(struct pm_module *module)
{
	pm_drv_t *pd = &g_pm;
	module_t *mm = &pd->mod;

	if (!module)
		return PM_ERR_INVALID_PARAM;

	osMutexWait(pd->h_mu, osWaitForever);
	
	if (mm->head == NULL) {
		mm->head = module;
 		mm->last = module;
		module->prev = NULL;
		module->next = NULL;
	} else {
		mm->last->next = module;
		module->prev = mm->last;
		module->next = NULL;
		mm->last = module;
 	}
	mm->count += 1;

	osMutexRelease(pd->h_mu);

	return PM_ERR_NO_ERROR;
}

int hal_pm_unreg_mod(struct pm_module *module)
{
	pm_drv_t *pd = &g_pm;
	module_t *mm = &pd->mod;

	if (!module)
		return PM_ERR_INVALID_PARAM;

	osMutexWait(pd->h_mu, osWaitForever);

	if (module == mm->head) {
		mm->head = module->next;
		if (mm->head)
			mm->head->prev = NULL;
	} 

	if (module == mm->last) {
		mm->last = module->prev;
		if (mm->last)
			mm->last->next = NULL;
	}

	if ((module != mm->head) && (module != mm->last)) {
		if (module->next)
			module->next->prev = module->prev;
		if (module->prev)
			module->prev->next = module->next;
	}

	osMutexRelease(pd->h_mu);
  
	return PM_ERR_NO_ERROR;
}

int hal_pm_reg_ble_mod(struct pm_module *module)
{
	pm_drv_t *pd = &g_pm;
	pd->ble_mod = module;

	return PM_ERR_NO_ERROR;
}

int hal_pm_unreg_ble_mod(struct pm_module *module)
{
	pm_drv_t *pd = &g_pm;

	pd->ble_mod = NULL;

	return PM_ERR_NO_ERROR;
}

uint32_t hal_pm_suspend_and_resume(uint32_t os_sleep_ms)
{
	pm_drv_t *pd = &g_pm;
	module_t *p_mod = &pd->mod;
	int sleep_state = PM_DEEP_SLEEP;
	uint32_t sleep_time_us, final_sleep_time_us;
	uint32_t s_tick, e_tick, time_elapse;

	//uint32_t rtc = hal_clk_rtc_get();

	uint32_t pri_mask = __get_PRIMASK();
	uint32_t fault_mask = __get_FAULTMASK();

//debug_gpio_2_6(1);

	/// mask interrupt 
	__set_PRIMASK(1);
	__set_FAULTMASK(0);

	if (os_sleep_ms == 0xFFFF)
		sleep_time_us = PM_MAX_SLEEP_TIME;
	else
		sleep_time_us = (os_sleep_ms * 1000);

	/// Get a start time stamp...
	s_tick = hal_sleep_timer_read_tick(SLEEP_TIMER1_ID);

	/// OS in idle state and scheduler is stop 
	/// loop thru all the register modules 
	struct pm_module *next = p_mod->head;
	while (next) {
		int state;
		if (next->power_state) {
			uint32_t duration;
			state = next->power_state(next->arg, &duration);
			if (state == PM_ACTIVE) {			
				sleep_state = PM_ACTIVE;
				break;
			} else if (state == PM_SLEEP) {	
				sleep_state = PM_SLEEP;
				if (duration != PM_MAX_SLEEP_TIME) {
					if ((duration * 1000) < sleep_time_us)
						sleep_time_us = duration * 1000;
				}
			} else {
				if (sleep_state == PM_DEEP_SLEEP) {
					if (duration != PM_MAX_SLEEP_TIME) {
						if ((duration * 1000) < sleep_time_us)
							sleep_time_us = duration * 1000;
					}
				}
			}
		}
		next = next->next;
	}

	/// check BLE sleep state
	if (pd->ble_mod) {
		int state;
		uint32_t slot;
		state = pd->ble_mod->power_state(pd->ble_mod->arg, &slot);
		if (sleep_state == PM_SLEEP) {
			if (state == PM_ACTIVE)
				sleep_state = state;
		} else if (sleep_state == PM_DEEP_SLEEP) {
			if (state < PM_DEEP_SLEEP)
				sleep_state = state; 
		} else {
			// active, nothing to do...
		}

		if (slot != PM_MAX_SLEEP_TIME) {
			uint32_t slot_in_us = (uint32_t)((slot * 312.5) + 0.5);
			if (slot_in_us < sleep_time_us)
				sleep_time_us = slot_in_us;
		}
	}				

	if (sleep_state == PM_DEEP_SLEEP) {
		/// If RTC enable, make sure we already wait more than 1 second before going into deep sleep
		if (!hal_clk_rtc_ready()) {
			sleep_state = PM_SLEEP;
		} 
		/// If platform timer is been used, then we shouldn't go into deep sleep
		if (hal_timer_busy()) {
			sleep_state = PM_SLEEP;
		}

		/// If deep sleep, make sure the time interval exceed the deep sleep threshold
		if (sleep_time_us < (CFG_PM_DEEP_SLEEP_THRD*1000)) 	{
			sleep_state = PM_SLEEP;
		}
	}

	/// If active, no sleep
	if (sleep_state == PM_ACTIVE) 
	{	
		final_sleep_time_us = 0;	
	} 

	/// If sleep, issue WFI to turn off ARM
	if (sleep_state == PM_SLEEP) {
		/// Get a end time stamp
		e_tick = hal_sleep_timer_read_tick(SLEEP_TIMER1_ID);
		time_elapse = hal_sleep_timer_tick_diff(s_tick, e_tick);

		if (sleep_time_us == PM_MAX_SLEEP_TIME) {
			s_tick = hal_sleep_timer_read_tick(SLEEP_TIMER1_ID);
			tmr2_start(sleep_time_us);
			__wfi();
			tmr2_stop();  
			e_tick = hal_sleep_timer_read_tick(SLEEP_TIMER1_ID);
			final_sleep_time_us = hal_sleep_timer_tick_diff(s_tick, e_tick);
		} else if (sleep_time_us > time_elapse) {
			s_tick = hal_sleep_timer_read_tick(SLEEP_TIMER1_ID);
			tmr2_start((sleep_time_us - time_elapse));
			__wfi();
			tmr2_stop();  
			e_tick = hal_sleep_timer_read_tick(SLEEP_TIMER1_ID);
			final_sleep_time_us = hal_sleep_timer_tick_diff(s_tick, e_tick);
		} else {
			final_sleep_time_us = time_elapse;
		}
	} 

	/// If deep sleep, shut off chip 
	if (sleep_state == PM_DEEP_SLEEP) 
	{
		uint32_t pre_sleep_time_us, post_sleep_time_us;
		
		e_tick = hal_sleep_timer_read_tick(SLEEP_TIMER1_ID);
		pre_sleep_time_us = hal_sleep_timer_tick_diff(s_tick, e_tick);

		// sleep time should account for software delays.
		sleep_time_us -= pd->deep_sleep_comp_time_us;

		if (sleep_time_us >= (CFG_PM_DEEP_SLEEP_THRD * 1000)) {
			/// shut down start...
			s_tick = hal_sleep_timer_read_tick(SLEEP_TIMER1_ID);

            hal_gpio_suspend();

			/// call each module shut down routine 
			next = p_mod->head;
			while (next) {
				if (next->power_down) {
					next->power_down(next->arg, (sleep_time_us/1000));
				}
				next = next->next;
			}

			/// store global registers and etc...
			hal_global_suspend();

			/// call BLE shut down
			if (pd->ble_mod) {
				uint32_t slot = (uint32_t)((sleep_time_us/312.5) + 0.5);
				pd->ble_mod->power_down(pd->ble_mod->arg, slot);
			}
			e_tick = hal_sleep_timer_read_tick(SLEEP_TIMER1_ID);
			pre_sleep_time_us += hal_sleep_timer_tick_diff(s_tick, e_tick);

			/// shut down and resume
			s_tick = hal_sleep_timer_read_tick(SLEEP_TIMER1_ID);
			if (pd->slp_wup)
				hal_sleep_timer_start(SLEEP_TIMER0_ID, sleep_time_us, 0, 1, 0);
			shutdown_and_resume();
			if (pd->slp_wup)
				hal_sleep_timer_stop(SLEEP_TIMER0_ID);
			e_tick = hal_sleep_timer_read_tick(SLEEP_TIMER1_ID);
          //rtc = hal_clk_rtc_get();//shutdown_and_resume doesn't save float register, get rtc again 
			final_sleep_time_us = hal_sleep_timer_tick_diff(s_tick, e_tick);  

			//debug_gpio_2_4(0);

			/// resume start...
			s_tick = hal_sleep_timer_read_tick(SLEEP_TIMER1_ID);
			/// call BLE resume
			if (pd->ble_mod) {
				pd->ble_mod->power_up(pd->ble_mod->arg);
			}
			/// Call each module resume routine 
			next = p_mod->head;
			while (next) {
				if (next->power_up) {
					next->power_up(next->arg);
				}
				next = next->next;
			}				
			/// restoer global egisters and etc... */
			hal_global_resume();				
			e_tick = hal_sleep_timer_read_tick(SLEEP_TIMER1_ID);
			post_sleep_time_us = hal_sleep_timer_tick_diff(s_tick, e_tick);

			/// update SW compensation time, if possible
			//if (final_sleep_time_us > sleep_time_us) { 	/// no early wake up
				/// update it 
			// bootram to system is about 492us
				pd->deep_sleep_comp_time_us = post_sleep_time_us + 800 /*+ (final_sleep_time_us - sleep_time_us)*/;
			//} 

			/// update final sleep time
			final_sleep_time_us += pre_sleep_time_us + post_sleep_time_us;

//GPIO_3_2_TRX();

		} else {
			s_tick = hal_sleep_timer_read_tick(SLEEP_TIMER1_ID);
			tmr2_start(sleep_time_us);
			__wfi();
			tmr2_stop();
			e_tick = hal_sleep_timer_read_tick(SLEEP_TIMER1_ID);
			final_sleep_time_us = hal_sleep_timer_tick_diff(s_tick, e_tick);  
		}
	}

	/* unmask interrupt */
	__set_PRIMASK(pri_mask);
	__set_FAULTMASK(fault_mask);

	//debug_gpio_2_6(0);

	return (uint32_t )((final_sleep_time_us/1000.) + 0.5);
}
#endif	// CFG_PM_EN

