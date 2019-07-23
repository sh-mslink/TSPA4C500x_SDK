#ifndef __API_CONSOLE__
#define __API_CONSOLE__

typedef struct console_cmd {
	char func[32];
	int16_t paramNum;
	uint16_t evt_id;
	char usage[128];
} console_cmd_t;

typedef int (*cmd_handler_t)(uint16_t eid, void *pv);

int console_init(void);
int start_console(void);
int register_console_cmds(console_cmd_t *pCmds, int count, cmd_handler_t handler);

#endif
