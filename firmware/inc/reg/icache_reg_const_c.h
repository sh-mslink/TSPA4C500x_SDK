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

#define NUM_REGS__ICACHE_REG  9
/* { reg_const_icache_reg, 9, "icache_reg"},  */ 
static reg_const_t reg_const_icache_reg[NUM_REGS__ICACHE_REG] = {
  {/* name */ "intr_status", /* address */ 0x44009000, /* default */ 0x00000000, /* description */ "Interrupt status \n"}, 
  {/* name */ "intr_mask_status", /* address */ 0x44009004, /* default */ 0x00000000, /* description */ "Interrupt mask status register\n"}, 
  {/* name */ "intr_clear", /* address */ 0x44009008, /* default */ 0x00000000, /* description */ "Clear interrupt status\n"}, 
  {/* name */ "intr_set", /* address */ 0x4400900c, /* default */ 0x00000000, /* description */ ""}, 
  {/* name */ "intr_mask_set", /* address */ 0x44009010, /* default */ 0x00000000, /* description */ "Set interrupt mask\n"}, 
  {/* name */ "intr_mask_clear", /* address */ 0x44009014, /* default */ 0x00000000, /* description */ "Set interrupt mask\n"}, 
  {/* name */ "misc_ctrl", /* address */ 0x44009018, /* default */ 0x00000000, /* description */ "Set interrupt mask\n"}, 
  {/* name */ "hit_counter", /* address */ 0x44009028, /* default */ 0x00000000, /* description */ "Interrupt status \n"}, 
  {/* name */ "miss_counter", /* address */ 0x4400902c, /* default */ 0x00000000, /* description */ "Interrupt status \n"}
};

field_const_t field_const_icache_reg__intr_status[]  = {
  {/* name */ "sram_clear_done", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "iCache SRAM cleared\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:1]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_icache_reg__intr_mask_status[]  = {
  {/* name */ "sram_clear_done", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "iCache SRAM cleared\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:1]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_icache_reg__intr_clear[]  = {
  {/* name */ "sram_clear_done", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "iCache SRAM cleared\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:1]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_icache_reg__intr_set[]  = {
  {/* name */ "sram_clear_done", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "iCache SRAM cleared\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:1]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_icache_reg__intr_mask_set[]  = {
  {/* name */ "sram_clear_done", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "iCache SRAM cleared\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:1]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_icache_reg__intr_mask_clear[]  = {
  {/* name */ "sram_clear_done", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "iCache SRAM cleared\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:1]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_icache_reg__misc_ctrl[]  = {
  {/* name */ "ctl_cache_en", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "enable cache function\n"}, 
  {/* name */ "ctl_always_req", /* range */ "[1:1]", /* default */ "0x0", /* access */ "read-write", /* description */ "Always request data\n"}, 
  {/* name */ "ctl_sram_clr", /* range */ "[4:4]", /* default */ "0x0", /* access */ "read-write", /* description */ "Clear SRAM. Only effective when cache_enable is de-asserted.\n"}, 
  {/* name */ "ctl_counter_clr", /* range */ "[8:8]", /* default */ "0x0", /* access */ "read-write", /* description */ "Clear internal miss/hit counter. Only effective when cache_enable is asserted.\n"}, 
  {/* name */ "ctl_counter_snap", /* range */ "[9:9]", /* default */ "0x0", /* access */ "read-write", /* description */ "Take a snapshot of the internal miss/hit counter. Only effective when cache_enable is asserted.\n"}, 
  {/* name */ "ctl_rst_intrctrl", /* range */ "[12:12]", /* default */ "0x0", /* access */ "read-write", /* description */ "Synchronous reset interrupt controller\n"}, 
  {/* name */ "dummy_field", /* range */ "[15:13]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_icache_reg__hit_counter[]  = {
  {/* name */ "sts_hit_count", /* range */ "[31:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "Hit counter (populated each time when counter_snap is asserted)\n"}
};
field_const_t field_const_icache_reg__miss_counter[]  = {
  {/* name */ "sts_miss_count", /* range */ "[31:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "miss counter (populated each time when counter_snap is asserted)\n"}
};

field_const_array_t reg_pnt_list__icache_reg[NUM_REGS__ICACHE_REG] = {
  { /* pfield */ field_const_icache_reg__intr_status, /* size */ 2}, 
  { /* pfield */ field_const_icache_reg__intr_mask_status, /* size */ 2}, 
  { /* pfield */ field_const_icache_reg__intr_clear, /* size */ 2}, 
  { /* pfield */ field_const_icache_reg__intr_set, /* size */ 2}, 
  { /* pfield */ field_const_icache_reg__intr_mask_set, /* size */ 2}, 
  { /* pfield */ field_const_icache_reg__intr_mask_clear, /* size */ 2}, 
  { /* pfield */ field_const_icache_reg__misc_ctrl, /* size */ 7}, 
  { /* pfield */ field_const_icache_reg__hit_counter, /* size */ 1}, 
  { /* pfield */ field_const_icache_reg__miss_counter, /* size */ 1}
};