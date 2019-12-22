#ifndef INB_PLT_H
#define INB_PLT_H

#include "stdint.h"


typedef struct _plat_fun {
	void (*srand)(uint32_t seed);
	uint32_t (*rand)(void);
	void *(*uart_init)(void);
	int (*uart_write)(void *hdl, uint8_t *buffer, uint16_t buffer_len, void *arg, void (*callback)(void *, int, int ));
	int (*uart_read)(void *hdl, uint8_t *buffer, uint16_t buffer_len, void *arg, void(*callback)(void *, int, int));
	int (*uart_flow_on)(void *);
	int (*uart_flow_off)(void *);
	void (*flash_read)(uint32_t addr, uint32_t length, uint8_t *buf);
	void (*flash_write)(uint32_t addr, uint32_t length, uint8_t *buf);
	void (*flash_erase)(uint32_t addr, uint32_t length);
	void *(*os_mutex_create)(void);
	void (*os_mutex_delete)(void *hdl);
	void (*os_mutex_lock)(void *hdl);
	void (*os_mutex_unlock)(void *hdl);
	void *(*os_task_create)(char *name, void (*func)(void const *), void *);
	void (*os_task_delete)(void *);
	int (*os_task_wait)(void *h);
	void (*os_task_signal)(void *h);
	void *(*os_queue_create)(void *pv, int size);
	void (*os_queue_put)(void *qid, uint32_t message);
	uint32_t (*os_queue_get)(void *qid);
	void (*ble_irq_disable)(void);
	void (*ble_irq_enable)(void);
	void (*plt_init)(uint32_t *);
	void (*assert_err)(const char *file, int line);
	void (*assert_param)(const char *file, int line, int param0, int param1);
	void (*assert_warn)(const char *file, int line, int param0, int param1);
	void (*trace)(uint32_t flag, char *fmt, ...);
	void (*power_register)(uint32_t em_end, int (*pow_state)(void *arg, uint32_t *duration), void (*pow_down)(void *arg, uint32_t duration), void (*pow_up)(void *arg));
	void *(*os_semaphore_create)(void);	
	void (*os_semaphore_delete)(void *h);	
	int (*os_semaphore_wait)(void *h)	;
	int (*os_semaphore_release)(void *h);
	void *(*mem_alloc)(int size);
	void (*mem_free)(void *ptr);
	void *(*get_cmd_pool)(void);
	int (*get_cmd_pool_size)(void);
	void *(*get_conn_pool)(void);
	int (*get_conn_pool_size)(void);
	void (*uart_deinit)(void *hdl);
	void (*platform_reset)(uint32_t reson);
}  plat_fun_t;

extern const plat_fun_t plat_fun;

#endif	/* INB_PLT_H */
