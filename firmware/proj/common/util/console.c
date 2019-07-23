#include "in_config.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "in_arm.h"
#include "in_debug.h"
#include ".\ble\inb_api.h"
#include "hal\hal_uart.h"
#include "cmsis_os.h"
#include "ble\prf\inb_prf_dis.h"
#include "ble\prf\inb_prf_anp.h"
#include "ble\prf\inb_prf_pasp.h"

#include "..\inc\console.h"
#include "..\inc\test_svc.h"

extern int gap_register_console_cmds(void);
extern int gatt_register_console_cmds(void);

#define MAX_PARAM_NUM 			10
#define MAX_REG_CNT			10

typedef struct console_reg {
	//int (*p_cmd_handler)(uint16_t eid, void *pv);
	cmd_handler_t p_cmd_handler;
	console_cmd_t *p_cmds;
	int count;
} console_reg_t;

static __INLINE void LIST_CMD(console_cmd_t cmds[], int count)
{
	printf("==================:\r\n");
	for (int i=0;i<count;i++) {
		printf("\t%2d) %s - ", i, cmds[i].func);
		printf( cmds[i].usage, cmds[i].func);
	}
}

static __INLINE struct console_cmd* FIND_CMD(console_cmd_t cmds[], int count, char* func)
{
	for(int i=0;i<count;i++){
		if (!strcmp(func, cmds[i].func))
			return &cmds[i];
	}
	
	return NULL;
}

static __INLINE bool CHECK_PARAM_NUM(console_cmd_t *p_cmd, uint16_t length, uint16_t paramNum)
{
	if ((p_cmd->paramNum < 0 && paramNum < abs(p_cmd->paramNum)+length-1) ||//variable length
		(p_cmd->paramNum >= 0 && paramNum < p_cmd->paramNum) ) //fixed length
	{
		return false;
	}
	return true;
}

static __INLINE bool CONVERT_DEC_PARAM(uint16_t *p_val, char* p_param) 
{
	if (!p_param)
		*p_val = 0;
	else {
		*p_val = atoi(p_param);
		if (*p_val==0 && p_param[0] != '0'){
			return false;
		}
	}
	return true;
}

static __INLINE bool CONVERT_HEX_PARAM(uint16_t *p_val, char* p_param) 
{
	long ret;
	char *p;
	
	if (!p_param)
		*p_val = 0;
	else {
		ret = strtol(p_param, &p, 16);
		if (ret==0 && p_param[0] != '0')
			return false;
		*p_val = (uint16_t)ret;
	}
	return true;
}
#if (CFG_DBG_IF_UART==1) && (WITH_CONSOLE==1)
static osThreadId gConsoleThreadId;
static uint16_t g_paramData[MAX_PARAM_NUM+16] = {0};
static char *g_param[MAX_PARAM_NUM+16] = {0};
static char g_InputBuffer[128];

static console_reg_t gp_reg_consoles[MAX_REG_CNT] = {0};
#endif

static void console_thread (void const *arg)
{
	while(1){
		start_console();
	}
}

int console_init(void)
{
#if (CFG_DBG_IF_UART==1) && (WITH_CONSOLE==1) && (CFG_OS_NB_USR_PRIV_TASK!=0)
	/// create console TASK
	osThreadDef_t def;

	def.pthread = console_thread;
	def.instances = 1;
	def.tpriority = osPriorityNormal;
	def.stacksize = CFG_OS_USR_PRIV_TASK_TOTAL_STACK_SIZE;
	gConsoleThreadId = osThreadCreate(&def, NULL);
	if (!gConsoleThreadId) {
		PRINTD(DBG_ERR, "Error: create console task \r\n");
		return -1;
	}
#endif	
	return 0;
}

/*
return: 	0 - cmd skipped  
		1 - cmd handled correctly
	     -1 - cmd handled with error
*/
static int invoke_console_cmd(cmd_handler_t p_cmd_handler, console_cmd_t cmds[], int count, char *func, int param_num)
{
	int ret, i;
	uint8_t *p_buffer;
	bool result;

#if (CFG_DBG_IF_UART==1) && (WITH_CONSOLE==1) && (CFG_OS_NB_USR_PRIV_TASK!=0)
	
	memset(g_paramData, 0, sizeof(g_paramData));

	if( !strcmp(func, "?")){
		LIST_CMD(cmds, count);
		return 1;
	}

	console_cmd_t *p_cmd = FIND_CMD(cmds, count,  func);
	if (!p_cmd)
		return 0;

	if (!CONVERT_DEC_PARAM(&g_paramData[0], g_param[0]) && !CONVERT_HEX_PARAM(&g_paramData[0], g_param[0]+1) ){
		printf("Error: Int Param\r\n");
		return -1;
	}

	if (!CHECK_PARAM_NUM(p_cmd, g_paramData[0], param_num))	{
		printf(p_cmd->usage, p_cmd->func);
		return -1;
	}

	for (i=1;i<param_num;i++){
		if (*(g_param[i]) == 'H' || *(g_param[i]) == 'h')
			result = CONVERT_HEX_PARAM(&g_paramData[i], g_param[i]+1);
		else
			result = CONVERT_DEC_PARAM(&g_paramData[i], g_param[i]);
		if (!result){
			printf(p_cmd->usage, p_cmd->func);
			return -1;
		}
	}

	//Assume connection index is 0. If not, change it here.
	g_paramData[param_num] = 0;
	//inb_event_add(p_cmd->evt_id, (1+param_num)*sizeof(uint16_t), g_paramData);
	if (p_cmd_handler)
		return p_cmd_handler(p_cmd->evt_id, g_paramData);

#endif
	return 1;
}

int start_console(void)
{
	char *p;
	int ret = 0;
	char *func;
	int param_num=0;
	
#if (CFG_DBG_IF_UART==1) && (WITH_CONSOLE==1) && (CFG_OS_NB_USR_PRIV_TASK!=0)
	
	memset(g_InputBuffer, 0, sizeof(g_InputBuffer));		
	gets(g_InputBuffer);		
	if (g_InputBuffer[0] == 0) {
		printf("%c", '$');
		return 0;
	}

	memset(g_param, 0, sizeof(g_param));
	
	func = strtok(g_InputBuffer, " ");

	while (1){
		g_param[param_num] = strtok(NULL, " ");
		if (g_param[param_num] == NULL)
			break;
		param_num++;
	}

	for (int i=0;i<MAX_REG_CNT;i++){
		if (gp_reg_consoles[i].p_cmds != NULL)
			ret |= invoke_console_cmd(gp_reg_consoles[i].p_cmd_handler, gp_reg_consoles[i].p_cmds , gp_reg_consoles[i].count, func, param_num);
	}
	//ret |= invoke_console_cmd(g_gatt_cmds, sizeof(g_gatt_cmds)/sizeof(g_gatt_cmds[0]), func, param_num);
	//ret |= invoke_console_cmd(g_gap_cmds, sizeof(g_gap_cmds)/sizeof(g_gap_cmds[0]), func, param_num);

	if (ret == 0)
		printf("Invalid command, type '?' for help!\r\n");

	printf("%c", '$');

	/*printf("\n%s (", func);
	for (int i=0;i<param_num;i++){
		printf("%s", param[i]);
		if ( i != param_num-1)
			printf(", ");
	}
	printf(")\r\n");*/

#endif
	return 0;
}

/*
Returns: 0 - success; else -fail
*/
int register_console_cmds(console_cmd_t *pCmds, int count, cmd_handler_t handler)
{
#if (CFG_DBG_IF_UART==1) && (WITH_CONSOLE==1) && (CFG_OS_NB_USR_PRIV_TASK!=0)
	for (int i=0;i<MAX_REG_CNT;i++)
	{
		if (gp_reg_consoles[i].p_cmds == NULL){
			gp_reg_consoles[i].p_cmd_handler = handler;
			gp_reg_consoles[i].p_cmds = pCmds;
			gp_reg_consoles[i].count = count;
			return 0;
		}
	}
#endif
	return 1;
}

