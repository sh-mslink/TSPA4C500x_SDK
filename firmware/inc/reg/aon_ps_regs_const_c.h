/////////////////////////////////////////////////////////////////////////////////
// This file has been automatically generated by register_slave.pl version dc9b7d3
/////////////////////////////////////////////////////////////////////////////////

// type declaration
#ifndef __REG_CONST_T
#define __REG_CONST_T

#ifndef REG_CONST_NAME_STRING_MAX_LEN   
#define REG_CONST_NAME_STRING_MAX_LEN 64
#endif // REG_CONST_NAME_STRING_MAX_LEN
#ifndef REG_CONST_DESC_STRING_MAX_LEN
#define REG_CONST_DESC_STRING_MAX_LEN 512
#endif // REG_CONST_DESC_STRING_MAX_LEN
typedef struct {
	char name[REG_CONST_NAME_STRING_MAX_LEN];
	DWORD address;
	DWORD def;
	char desc[REG_CONST_DESC_STRING_MAX_LEN];
} reg_const_t;
typedef struct {
	char name[REG_CONST_NAME_STRING_MAX_LEN];
	char range[32];
	char def[32];
	char access[32];
	char desc[REG_CONST_DESC_STRING_MAX_LEN];
} field_const_t;
typedef struct {
	field_const_t *pfield;
	DWORD size;
} field_const_array_t;
#endif // __REG_CONST_T

#define NUM_REGS__AON_PS_REGS  24
/* { reg_const_aon_ps_regs, 24, "aon_ps_regs"},  */ 
static reg_const_t reg_const_aon_ps_regs[NUM_REGS__AON_PS_REGS] = {
  {/* name */ "aon_st_wakeup_ctrl", /* address */ 0x00007000, /* default */ 0x00000000, /* description */ "Controls the wakeup enable for the Always On Sleep Timer (AON_ST)\n"}, 
  {/* name */ "ble_st_wakeup_ctrl", /* address */ 0x00007004, /* default */ 0x00000000, /* description */ "Controls the wakeup enable for the BLE Sleep Timer (BLE_ST)\n"}, 
  {/* name */ "bo_out_wakeup_ctrl", /* address */ 0x00007008, /* default */ 0x00000000, /* description */ "Controls the wakeup enable for the bo_out (Brown Out Detector)\n"}, 
  {/* name */ "msio_wakeup_ctrl", /* address */ 0x0000700c, /* default */ 0x00000000, /* description */ "Controls the wakeup enable for the MSIO (Mixed Signal IO)\n"}, 
  {/* name */ "pd_doo_sleep_ctrl", /* address */ 0x00007040, /* default */ 0x00000000, /* description */ "Controls the sleep and retention options for the DOO\n"}, 
  {/* name */ "off_delay_0_ctrl", /* address */ 0x00007080, /* default */ 0x04030002, /* description */ "Controls the delays for turning OFF power\n"}, 
  {/* name */ "off_delay_1_ctrl", /* address */ 0x00007084, /* default */ 0x07080005, /* description */ "Controls the delays for turning OFF power\n"}, 
  {/* name */ "on_delay_0_ctrl", /* address */ 0x00007090, /* default */ 0x000000a8, /* description */ "Controls the delays for turning ON power\n"}, 
  {/* name */ "on_delay_1_ctrl", /* address */ 0x00007094, /* default */ 0x200200a7, /* description */ "Controls the delays for turning ON power\n"}, 
  {/* name */ "dcdc_en_delay_ctrl", /* address */ 0x000070c0, /* default */ 0x00000108, /* description */ "Controls the delays for DCDC_EN\n"}, 
  {/* name */ "xo_en_delay_ctrl", /* address */ 0x000070c8, /* default */ 0x00001907, /* description */ "Delay control for the xo_en signal\n"}, 
  {/* name */ "clk_32mhz_rc_en_delay_ctrl", /* address */ 0x000070cc, /* default */ 0x00000107, /* description */ "Delay control for the clk_32mhz_rc_en signal\n"}, 
  {/* name */ "auto_amp_ctrl_en_delay_ctrl", /* address */ 0x000070d4, /* default */ 0x00002107, /* description */ "Delay control for the auto_amp_ctrl_en signal\n"}, 
  {/* name */ "auto_amp_ctrl_rb_delay_ctrl", /* address */ 0x000070d8, /* default */ 0x00002307, /* description */ "Delay control for the auto_amp_ctrl_rb signal\n"}, 
  {/* name */ "qspi_vddio_en_delay_ctrl", /* address */ 0x000070dc, /* default */ 0x00002307, /* description */ "Delay control for the qspi_vddio_en signal\n"}, 
  {/* name */ "sensor_vddio_en_delay_ctrl", /* address */ 0x000070e0, /* default */ 0x00002307, /* description */ "Delay control for the sensor_vddio_en signal\n"}, 
  {/* name */ "misc_bypass_0_ctrl", /* address */ 0x00007100, /* default */ 0x0000a502, /* description */ "Bypass controls for misc signals\n"}, 
  {/* name */ "raw_wakeup_bits", /* address */ 0x00007200, /* default */ 0x00000000, /* description */ "Raw Wakeup Bits\n"}, 
  {/* name */ "pd_wakeup_bits", /* address */ 0x00007204, /* default */ 0x00000000, /* description */ "Individual Power Domain Wakeup Bits\n"}, 
  {/* name */ "serviced_request", /* address */ 0x00007210, /* default */ 0x00000000, /* description */ "Serviced Request Status Bits\n"}, 
  {/* name */ "active_request", /* address */ 0x00007220, /* default */ 0x00000000, /* description */ "Active Request Status Bits\n"}, 
  {/* name */ "last_request", /* address */ 0x00007230, /* default */ 0x00000000, /* description */ "Last Request Status Bits\n"}, 
  {/* name */ "logic_fsm_states", /* address */ 0x00007240, /* default */ 0x00000000, /* description */ "Current Logic FSM States\n"}, 
  {/* name */ "power_fsm_states", /* address */ 0x00007244, /* default */ 0x00000000, /* description */ "Current Power FSM States\n"}
};

field_const_t field_const_aon_ps_regs__aon_st_wakeup_ctrl[]  = {
  {/* name */ "pd_doo_enable", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "If set, this will enable the AON_ST to wakeup the DOO domain\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:1]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aon_ps_regs__ble_st_wakeup_ctrl[]  = {
  {/* name */ "pd_doo_enable", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "If set, this will enable the BLE_ST to wakeup the DOO domains\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:1]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aon_ps_regs__bo_out_wakeup_ctrl[]  = {
  {/* name */ "pd_doo_enable", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "If set, this will enable the bo_out to wakeup the DOO domains\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:1]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aon_ps_regs__msio_wakeup_ctrl[]  = {
  {/* name */ "pd_doo_enable", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "If set, this will enable the MSIO to wakeup the doo domains\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:1]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aon_ps_regs__pd_doo_sleep_ctrl[]  = {
  {/* name */ "pd_doo_core_enable", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "Enables PD_DOO_CORE Sleep\n"}, 
  {/* name */ "force", /* range */ "[6:6]", /* default */ "0x0", /* access */ "read-write", /* description */ "Force the Sleep (ignores wakeup)\n"}, 
  {/* name */ "em_4k_a_ret_enable", /* range */ "[8:8]", /* default */ "0x0", /* access */ "read-write", /* description */ "Enables the Exchange Memory 4K A memory retention\n"}, 
  {/* name */ "em_4k_b_ret_enable", /* range */ "[9:9]", /* default */ "0x0", /* access */ "read-write", /* description */ "Enables the Exchange Memory 4K B memory retention\n"}, 
  {/* name */ "em_8k_a_ret_enable", /* range */ "[10:10]", /* default */ "0x0", /* access */ "read-write", /* description */ "Enables the Exchange Memory 8K A memory retention\n"}, 
  {/* name */ "em_8k_b_ret_enable", /* range */ "[11:11]", /* default */ "0x0", /* access */ "read-write", /* description */ "Enables the Exchange Memory 8K B memory retention\n"}, 
  {/* name */ "em_16k_a_ret_enable", /* range */ "[12:12]", /* default */ "0x0", /* access */ "read-write", /* description */ "Enables the Exchange Memory 16K A memory retention\n"}, 
  {/* name */ "dm_4k_a_ret_enable", /* range */ "[13:13]", /* default */ "0x0", /* access */ "read-write", /* description */ "Enables the ID Memory 4K A memory retention\n"}, 
  {/* name */ "dm_4k_b_ret_enable", /* range */ "[14:14]", /* default */ "0x0", /* access */ "read-write", /* description */ "Enables the ID Memory 4K B memory retention\n"}, 
  {/* name */ "dm_8k_ret_enable", /* range */ "[15:15]", /* default */ "0x0", /* access */ "read-write", /* description */ "Enables the ID Memory 8K memory retention\n"}, 
  {/* name */ "dm_16k_ret_enable", /* range */ "[16:16]", /* default */ "0x0", /* access */ "read-write", /* description */ "Enables the ID Memory 16K memory retention\n"}, 
  {/* name */ "dm_32k_a_ret_enable", /* range */ "[17:17]", /* default */ "0x0", /* access */ "read-write", /* description */ "Enables the ID Memory 32K A memory retention\n"}, 
  {/* name */ "dm_32k_b_ret_enable", /* range */ "[18:18]", /* default */ "0x0", /* access */ "read-write", /* description */ "Enables the ID Memory 32K B memory retention\n"}, 
  {/* name */ "dm_32k_c_ret_enable", /* range */ "[19:19]", /* default */ "0x0", /* access */ "read-write", /* description */ "Enables the ID Memory 32K C memory retention\n"}, 
  {/* name */ "trig_ret_enable", /* range */ "[20:20]", /* default */ "0x0", /* access */ "read-write", /* description */ "Enables the Trig memory retention\n"}, 
  {/* name */ "dummy_field", /* range */ "[23:21]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aon_ps_regs__off_delay_0_ctrl[]  = {
  {/* name */ "clock_en_early", /* range */ "[7:0]", /* default */ "0x2", /* access */ "read-write", /* description */ "Number of clocks before setting clock_en_early to low (clock_en is +1 of this value)\n"}, 
  {/* name */ "isolate", /* range */ "[23:16]", /* default */ "0x3", /* access */ "read-write", /* description */ "Number of clock cycles before enabling the isolation cells\n"}, 
  {/* name */ "resetn", /* range */ "[31:24]", /* default */ "0x4", /* access */ "read-write", /* description */ "Number of clock cycles before asserting RESETN\n"}
};
field_const_t field_const_aon_ps_regs__off_delay_1_ctrl[]  = {
  {/* name */ "ret1n", /* range */ "[7:0]", /* default */ "0x5", /* access */ "read-write", /* description */ "Number of clock cycles before applying RET1N\n"}, 
  {/* name */ "power_vdd", /* range */ "[23:16]", /* default */ "0x8", /* access */ "read-write", /* description */ "Number of clock cycles before disabling the VDD DOOPD LDO\n"}, 
  {/* name */ "power_vdm", /* range */ "[31:24]", /* default */ "0x7", /* access */ "read-write", /* description */ "Number of clock cycles before disabling the memory power supplies to use the VDD DOOPD LDO (em_4k_a_en_b as an example)\nThis also controls the delay for the retention enable signal (em_4k_a_ret_en_b as an example) if the memory will be retained\nSince the retention enable has to be applied first, its delay is always -1 of this value\n\n"}
};
field_const_t field_const_aon_ps_regs__on_delay_0_ctrl[]  = {
  {/* name */ "clock_en_early_pd_doo", /* range */ "[7:0]", /* default */ "0xa8", /* access */ "read-write", /* description */ "Number of clock cycles before setting clock_en_early to high for DOO domain (clock_en is +1, isolate is -2, resetn is -1)\n"}
};
field_const_t field_const_aon_ps_regs__on_delay_1_ctrl[]  = {
  {/* name */ "ret1n", /* range */ "[7:0]", /* default */ "0xa7", /* access */ "read-write", /* description */ "Number of clock cycles before removing RET1N\n"}, 
  {/* name */ "power_vdd", /* range */ "[23:16]", /* default */ "0x2", /* access */ "read-write", /* description */ "Number of clock cycles before enabling the VDD DOOPD LDO\n"}, 
  {/* name */ "power_vdm", /* range */ "[31:24]", /* default */ "0x20", /* access */ "read-write", /* description */ "Number of clock cycles before enabling the memory power supplies to use the VDD DOOPD LDO (em_4k_a_en_b as an example)\nThis also controls the delay for the retention enable signal (em_4k_a_ret_en_b as an example)\nSince the retention enable needs to be applied after the switch to the VDD DOOPD LDO, its delay is always +1 of this value\n\n"}
};
field_const_t field_const_aon_ps_regs__dcdc_en_delay_ctrl[]  = {
  {/* name */ "off_delay", /* range */ "[7:0]", /* default */ "0x8", /* access */ "read-write", /* description */ "Number of clock cycles before disabling the DCDC_EN\n"}, 
  {/* name */ "on_delay", /* range */ "[15:8]", /* default */ "0x1", /* access */ "read-write", /* description */ "Number of clock cycles before enabling the DCDC_EN\n"}
};
field_const_t field_const_aon_ps_regs__xo_en_delay_ctrl[]  = {
  {/* name */ "off_delay", /* range */ "[7:0]", /* default */ "0x7", /* access */ "read-write", /* description */ "Number of clock cycles before disabling the xo_en\n"}, 
  {/* name */ "on_delay", /* range */ "[15:8]", /* default */ "0x19", /* access */ "read-write", /* description */ "Number of clock cycles before turning on the xo_en\n"}
};
field_const_t field_const_aon_ps_regs__clk_32mhz_rc_en_delay_ctrl[]  = {
  {/* name */ "off_delay", /* range */ "[7:0]", /* default */ "0x7", /* access */ "read-write", /* description */ "Number of clock cycles before disabling the clk_32mhz_rc_en\n"}, 
  {/* name */ "on_delay", /* range */ "[15:8]", /* default */ "0x1", /* access */ "read-write", /* description */ "Number of clock cycles before turning on the clk_32mhz_rc_en\n"}
};
field_const_t field_const_aon_ps_regs__auto_amp_ctrl_en_delay_ctrl[]  = {
  {/* name */ "off_delay", /* range */ "[7:0]", /* default */ "0x7", /* access */ "read-write", /* description */ "Number of clock cycles before disabling the auto_amp_ctrl_en\n"}, 
  {/* name */ "on_delay", /* range */ "[15:8]", /* default */ "0x21", /* access */ "read-write", /* description */ "Number of clock cycles before turning on the auto_amp_ctrl_en\n"}
};
field_const_t field_const_aon_ps_regs__auto_amp_ctrl_rb_delay_ctrl[]  = {
  {/* name */ "off_delay", /* range */ "[7:0]", /* default */ "0x7", /* access */ "read-write", /* description */ "Number of clock cycles before disabling the auto_amp_ctrl_rb\n"}, 
  {/* name */ "on_delay", /* range */ "[15:8]", /* default */ "0x23", /* access */ "read-write", /* description */ "Number of clock cycles before turning on the auto_amp_ctrl_rb\n"}
};
field_const_t field_const_aon_ps_regs__qspi_vddio_en_delay_ctrl[]  = {
  {/* name */ "off_delay", /* range */ "[7:0]", /* default */ "0x7", /* access */ "read-write", /* description */ "Number of clock cycles before disabling the qspi_vddio_en\n"}, 
  {/* name */ "on_delay", /* range */ "[15:8]", /* default */ "0x23", /* access */ "read-write", /* description */ "Number of clock cycles before turning on the qspi_vddio_en\n"}
};
field_const_t field_const_aon_ps_regs__sensor_vddio_en_delay_ctrl[]  = {
  {/* name */ "off_delay", /* range */ "[7:0]", /* default */ "0x7", /* access */ "read-write", /* description */ "Number of clock cycles before disabling the sensor_vddio_en\n"}, 
  {/* name */ "on_delay", /* range */ "[15:8]", /* default */ "0x23", /* access */ "read-write", /* description */ "Number of clock cycles before turning on the sensor_vddio_en\n"}
};
field_const_t field_const_aon_ps_regs__misc_bypass_0_ctrl[]  = {
  {/* name */ "low_voltage_en_val", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "Bypass value for low_voltage_en\n"}, 
  {/* name */ "low_voltage_en_en", /* range */ "[1:1]", /* default */ "0x1", /* access */ "read-write", /* description */ "Bypass enable for low_voltage_en\n"}, 
  {/* name */ "enable_clock_gate", /* range */ "[2:2]", /* default */ "0x0", /* access */ "read-write", /* description */ "If set, allows the AON PS to gate its own clock while waiting for an event to enable it again\n"}, 
  {/* name */ "dcdc_en_val", /* range */ "[4:4]", /* default */ "0x0", /* access */ "read-write", /* description */ "Bypass value for dcdc_switch_en\n"}, 
  {/* name */ "dcdc_en_en", /* range */ "[5:5]", /* default */ "0x0", /* access */ "read-write", /* description */ "Bypass enable for dcdc_switch_en\n"}, 
  {/* name */ "xo_en_val", /* range */ "[8:8]", /* default */ "0x1", /* access */ "read-write", /* description */ "Bypass value for xo_en\n"}, 
  {/* name */ "xo_en_en", /* range */ "[9:9]", /* default */ "0x0", /* access */ "read-write", /* description */ "Bypass enable for xo_en\n"}, 
  {/* name */ "clk_32mhz_rc_en_val", /* range */ "[10:10]", /* default */ "0x1", /* access */ "read-write", /* description */ "Bypass value for clk_32mhz_rc_en\n"}, 
  {/* name */ "clk_32mhz_rc_en_en", /* range */ "[11:11]", /* default */ "0x0", /* access */ "read-write", /* description */ "Bypass enable for clk_32mhz_rc_en\n"}, 
  {/* name */ "qspi_vddio_en_val", /* range */ "[12:12]", /* default */ "0x0", /* access */ "read-write", /* description */ "Bypass value for qspi_vddio_en\n"}, 
  {/* name */ "qspi_vddio_en_en", /* range */ "[13:13]", /* default */ "0x1", /* access */ "read-write", /* description */ "Bypass enable for qspi_vddio_en\n"}, 
  {/* name */ "sensor_vddio_en_val", /* range */ "[14:14]", /* default */ "0x0", /* access */ "read-write", /* description */ "Bypass value for sensor_vddio_en\n"}, 
  {/* name */ "sensor_vddio_en_en", /* range */ "[15:15]", /* default */ "0x1", /* access */ "read-write", /* description */ "Bypass enable for sensor_vddio_en\n"}
};
field_const_t field_const_aon_ps_regs__raw_wakeup_bits[]  = {
  {/* name */ "gpio", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "GPIO wakeup raw status\n"}, 
  {/* name */ "aon_st", /* range */ "[1:1]", /* default */ "0x0", /* access */ "read-only", /* description */ "AON_ST wakeup raw status\n"}, 
  {/* name */ "ble_st", /* range */ "[2:2]", /* default */ "0x0", /* access */ "read-only", /* description */ "BLE_ST wakeup raw status\n"}, 
  {/* name */ "bo_out", /* range */ "[3:3]", /* default */ "0x0", /* access */ "read-only", /* description */ "bo_out wakeup raw status\n"}, 
  {/* name */ "msio", /* range */ "[4:4]", /* default */ "0x0", /* access */ "read-only", /* description */ "msio wakeup raw status\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:5]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aon_ps_regs__pd_wakeup_bits[]  = {
  {/* name */ "pd_doo_core", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "Indicates PD_DOO_CORE domain currently has a wakeup active\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:1]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aon_ps_regs__serviced_request[]  = {
  {/* name */ "gpio_wakeup", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "Indicates GPIO wakeup has been serviced\n"}, 
  {/* name */ "aon_st_wakeup", /* range */ "[1:1]", /* default */ "0x0", /* access */ "read-only", /* description */ "Indicates AON_ST wakeup has been serviced\n"}, 
  {/* name */ "ble_st_wakeup", /* range */ "[2:2]", /* default */ "0x0", /* access */ "read-only", /* description */ "Indicates BLE_ST wakeup has been serviced\n"}, 
  {/* name */ "bo_out_wakeup", /* range */ "[3:3]", /* default */ "0x0", /* access */ "read-only", /* description */ "Indicates bo_out wakeup has been serviced\n"}, 
  {/* name */ "msio_wakeup", /* range */ "[4:4]", /* default */ "0x0", /* access */ "read-only", /* description */ "msio wakeup has been serviced\n"}, 
  {/* name */ "pd_doo_sleep", /* range */ "[8:8]", /* default */ "0x0", /* access */ "read-only", /* description */ "Indicates DOO sleep has been serviced\n"}, 
  {/* name */ "dummy_field", /* range */ "[15:9]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aon_ps_regs__active_request[]  = {
  {/* name */ "gpio_wakeup", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "Indicates GPIO wakeup is active request\n"}, 
  {/* name */ "aon_st_wakeup", /* range */ "[1:1]", /* default */ "0x0", /* access */ "read-only", /* description */ "Indicates AON_ST wakeup is active request\n"}, 
  {/* name */ "ble_st_wakeup", /* range */ "[2:2]", /* default */ "0x0", /* access */ "read-only", /* description */ "Indicates BLE_ST wakeup is active request\n"}, 
  {/* name */ "bo_out_wakeup", /* range */ "[3:3]", /* default */ "0x0", /* access */ "read-only", /* description */ "Indicates bo_out wakeup is active request\n"}, 
  {/* name */ "msio_wakeup", /* range */ "[4:4]", /* default */ "0x0", /* access */ "read-only", /* description */ "msio wakeup is active request\n"}, 
  {/* name */ "pd_doo_sleep", /* range */ "[8:8]", /* default */ "0x0", /* access */ "read-only", /* description */ "Indicates DOO sleep is active request\n"}, 
  {/* name */ "dummy_field", /* range */ "[15:9]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aon_ps_regs__last_request[]  = {
  {/* name */ "gpio_wakeup", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "Indicates GPIO wakeup was last request\n"}, 
  {/* name */ "aon_st_wakeup", /* range */ "[1:1]", /* default */ "0x0", /* access */ "read-only", /* description */ "Indicates AON_ST wakeup was last request\n"}, 
  {/* name */ "ble_st_wakeup", /* range */ "[2:2]", /* default */ "0x0", /* access */ "read-only", /* description */ "Indicates BLE_ST wakeup was last request\n"}, 
  {/* name */ "bo_out_wakeup", /* range */ "[3:3]", /* default */ "0x0", /* access */ "read-only", /* description */ "Indicates bo_out wakeup was last request\n"}, 
  {/* name */ "msio_wakeup", /* range */ "[4:4]", /* default */ "0x0", /* access */ "read-only", /* description */ "msio wakeup was last request\n"}, 
  {/* name */ "pd_doo_sleep", /* range */ "[8:8]", /* default */ "0x0", /* access */ "read-only", /* description */ "Indicates DOO sleep was last request\n"}, 
  {/* name */ "dummy_field", /* range */ "[15:9]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aon_ps_regs__logic_fsm_states[]  = {
  {/* name */ "main_fsm_state", /* range */ "[2:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "0 = RESET\n1 = READY\n2 = TRANS\n3 = RESET_TO_READY\n4 = READY_TO_TRANS\n5 = TRANS_TO_READY\n\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:3]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aon_ps_regs__power_fsm_states[]  = {
  {/* name */ "pd_doo_core_in_on_state", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "If 1, indicates PD_DOO_CORE is ON\n"}, 
  {/* name */ "pd_doo_core_in_off_state", /* range */ "[1:1]", /* default */ "0x0", /* access */ "read-only", /* description */ "If 1, indicates PD_DOO_CORE is OFF\n"}, 
  {/* name */ "pd_doo_core_going_to_on_state", /* range */ "[2:2]", /* default */ "0x0", /* access */ "read-only", /* description */ "If 1, indicates PD_DOO_CORE is going to ON\n"}, 
  {/* name */ "pd_doo_core_going_to_off_state", /* range */ "[3:3]", /* default */ "0x0", /* access */ "read-only", /* description */ "If 1, indicates PD_DOO_CORE is going to OFF\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:4]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};

field_const_array_t reg_pnt_list__aon_ps_regs[NUM_REGS__AON_PS_REGS] = {
  { /* pfield */ field_const_aon_ps_regs__aon_st_wakeup_ctrl, /* size */ 2}, 
  { /* pfield */ field_const_aon_ps_regs__ble_st_wakeup_ctrl, /* size */ 2}, 
  { /* pfield */ field_const_aon_ps_regs__bo_out_wakeup_ctrl, /* size */ 2}, 
  { /* pfield */ field_const_aon_ps_regs__msio_wakeup_ctrl, /* size */ 2}, 
  { /* pfield */ field_const_aon_ps_regs__pd_doo_sleep_ctrl, /* size */ 16}, 
  { /* pfield */ field_const_aon_ps_regs__off_delay_0_ctrl, /* size */ 3}, 
  { /* pfield */ field_const_aon_ps_regs__off_delay_1_ctrl, /* size */ 3}, 
  { /* pfield */ field_const_aon_ps_regs__on_delay_0_ctrl, /* size */ 1}, 
  { /* pfield */ field_const_aon_ps_regs__on_delay_1_ctrl, /* size */ 3}, 
  { /* pfield */ field_const_aon_ps_regs__dcdc_en_delay_ctrl, /* size */ 2}, 
  { /* pfield */ field_const_aon_ps_regs__xo_en_delay_ctrl, /* size */ 2}, 
  { /* pfield */ field_const_aon_ps_regs__clk_32mhz_rc_en_delay_ctrl, /* size */ 2}, 
  { /* pfield */ field_const_aon_ps_regs__auto_amp_ctrl_en_delay_ctrl, /* size */ 2}, 
  { /* pfield */ field_const_aon_ps_regs__auto_amp_ctrl_rb_delay_ctrl, /* size */ 2}, 
  { /* pfield */ field_const_aon_ps_regs__qspi_vddio_en_delay_ctrl, /* size */ 2}, 
  { /* pfield */ field_const_aon_ps_regs__sensor_vddio_en_delay_ctrl, /* size */ 2}, 
  { /* pfield */ field_const_aon_ps_regs__misc_bypass_0_ctrl, /* size */ 13}, 
  { /* pfield */ field_const_aon_ps_regs__raw_wakeup_bits, /* size */ 6}, 
  { /* pfield */ field_const_aon_ps_regs__pd_wakeup_bits, /* size */ 2}, 
  { /* pfield */ field_const_aon_ps_regs__serviced_request, /* size */ 7}, 
  { /* pfield */ field_const_aon_ps_regs__active_request, /* size */ 7}, 
  { /* pfield */ field_const_aon_ps_regs__last_request, /* size */ 7}, 
  { /* pfield */ field_const_aon_ps_regs__logic_fsm_states, /* size */ 2}, 
  { /* pfield */ field_const_aon_ps_regs__power_fsm_states, /* size */ 5}
};
