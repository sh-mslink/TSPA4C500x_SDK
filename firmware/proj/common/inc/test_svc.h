#ifndef __TEST_SVC_H__
#define __TEST_SVC_H__

int testSvc_add_svc(void);
uint16_t testSvc_get_att_len(uint16_t handle);
void* testSvc_get_att_value(uint16_t handle);
void testSvc_set_att_value(uint16_t handle, uint16_t len, uint16_t offset, void* val);

#if (CFG_DBG_IF_UART==1) && (WITH_CONSOLE==1)
int testSvc_register_console_cmds(void);
#endif

#endif
