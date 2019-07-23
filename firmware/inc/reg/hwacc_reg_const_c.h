/////////////////////////////////////////////////////////////////////////////////
// This file has been automatically generated by register_slave.pl version 35286ec
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

#define NUM_REGS__HWACC_REG  15
/* { reg_const_hwacc_reg, 15, "hwacc_reg"},  */ 
static reg_const_t reg_const_hwacc_reg[NUM_REGS__HWACC_REG] = {
  {/* name */ "intr_status", /* address */ 0x44005000, /* default */ 0x00000000, /* description */ "Interrupt status register bits. \n"}, 
  {/* name */ "intr_mask_status", /* address */ 0x44005004, /* default */ 0x00000000, /* description */ "Interrupt mask status register\n"}, 
  {/* name */ "intr_clear", /* address */ 0x44005008, /* default */ 0x00000000, /* description */ "Clear interrupt status\n"}, 
  {/* name */ "intr_set", /* address */ 0x4400500c, /* default */ 0x00000000, /* description */ "Set interrupt status\n"}, 
  {/* name */ "intr_mask_set", /* address */ 0x44005010, /* default */ 0x00000000, /* description */ "Set interrupt mask\n"}, 
  {/* name */ "intr_mask_clear", /* address */ 0x44005014, /* default */ 0x00000000, /* description */ "Set interrupt mask\n"}, 
  {/* name */ "misc_ctrl", /* address */ 0x44005040, /* default */ 0x00000000, /* description */ "Misc control\n"}, 
  {/* name */ "mem_acc_ctrl", /* address */ 0x44005048, /* default */ 0x00000000, /* description */ "Misc control\n"}, 
  {/* name */ "inverse_ctrl", /* address */ 0x44005058, /* default */ 0x00000000, /* description */ ""}, 
  {/* name */ "inverse_min_pv", /* address */ 0x44005060, /* default */ 0x00000000, /* description */ ""}, 
  {/* name */ "curr_inst_word0", /* address */ 0x44005080, /* default */ 0x00000000, /* description */ "current instruction word 0\n"}, 
  {/* name */ "curr_inst_word1", /* address */ 0x44005084, /* default */ 0x00000000, /* description */ "current instruction word 1\n"}, 
  {/* name */ "curr_inst_word2", /* address */ 0x44005088, /* default */ 0x00000000, /* description */ "current instruction word 2\n"}, 
  {/* name */ "curr_inst_cycle_cnt", /* address */ 0x4400508c, /* default */ 0x00000000, /* description */ "current instruction cycle count\n"}, 
  {/* name */ "current_fault", /* address */ 0x440050a0, /* default */ 0x00000000, /* description */ "current fault status\n"}
};

field_const_t field_const_hwacc_reg__intr_status[]  = {
  {/* name */ "hwacc_done", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "Hardware computation finished\n"}, 
  {/* name */ "fault_detected", /* range */ "[1:1]", /* default */ "0x0", /* access */ "read-only", /* description */ "Configuration error detected\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:2]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_hwacc_reg__intr_mask_status[]  = {
  {/* name */ "hwacc_done", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "Hardware computation finished\n"}, 
  {/* name */ "fault_detected", /* range */ "[1:1]", /* default */ "0x0", /* access */ "read-only", /* description */ "Configuration error detected\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:2]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_hwacc_reg__intr_clear[]  = {
  {/* name */ "hwacc_done", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "Hardware computation finished\n"}, 
  {/* name */ "fault_detected", /* range */ "[1:1]", /* default */ "0x0", /* access */ "read-write", /* description */ "Configuration error detected\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:2]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_hwacc_reg__intr_set[]  = {
  {/* name */ "hwacc_done", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "Hardware computation finished\n"}, 
  {/* name */ "fault_detected", /* range */ "[1:1]", /* default */ "0x0", /* access */ "read-write", /* description */ "Configuration error detected\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:2]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_hwacc_reg__intr_mask_set[]  = {
  {/* name */ "hwacc_done", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "Hardware computation finished\n"}, 
  {/* name */ "fault_detected", /* range */ "[1:1]", /* default */ "0x0", /* access */ "read-write", /* description */ "Configuration error detected\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:2]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_hwacc_reg__intr_mask_clear[]  = {
  {/* name */ "hwacc_done", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "Hardware computation finished\n"}, 
  {/* name */ "fault_detected", /* range */ "[1:1]", /* default */ "0x0", /* access */ "read-write", /* description */ "Configuration error detected\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:2]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_hwacc_reg__misc_ctrl[]  = {
  {/* name */ "ctl_enable", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "Enable the whole block\n"}, 
  {/* name */ "ctl_start", /* range */ "[1:1]", /* default */ "0x0", /* access */ "read-write", /* description */ "A toggle between 0 -> 1 will start the computation\n"}, 
  {/* name */ "ctl_auto_reset_on_fault", /* range */ "[2:2]", /* default */ "0x0", /* access */ "read-write", /* description */ ""}, 
  {/* name */ "ctl_rst_intrctrl", /* range */ "[4:4]", /* default */ "0x0", /* access */ "read-write", /* description */ "Reset interrupt controller\n"}, 
  {/* name */ "ctl_num_instruction", /* range */ "[17:8]", /* default */ "0x0", /* access */ "read-write", /* description */ "Number of instruction to perform\n"}, 
  {/* name */ "ctl_instruction_address", /* range */ "[31:18]", /* default */ "0x0", /* access */ "read-write", /* description */ "Start address of the instruction\n"}
};
field_const_t field_const_hwacc_reg__mem_acc_ctrl[]  = {
  {/* name */ "ctl_mem_a_acc_sel", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "0 - ahb, 1 - computation core\n"}, 
  {/* name */ "ctl_mem_b_acc_sel", /* range */ "[4:4]", /* default */ "0x0", /* access */ "read-write", /* description */ "0 - ahb, 1 - computation core\n"}, 
  {/* name */ "ctl_mem_c_acc_sel", /* range */ "[8:8]", /* default */ "0x0", /* access */ "read-write", /* description */ "0 - ahb, 1 - computation core\n"}, 
  {/* name */ "ctl_mem_d_acc_sel", /* range */ "[12:12]", /* default */ "0x0", /* access */ "read-write", /* description */ "0 - ahb, 1 - computation core\n"}, 
  {/* name */ "dummy_field", /* range */ "[15:13]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_hwacc_reg__inverse_ctrl[]  = {
  {/* name */ "ctl_pv_search_on", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ ""}, 
  {/* name */ "ctl_check_min_pv_on", /* range */ "[1:1]", /* default */ "0x0", /* access */ "read-write", /* description */ ""}, 
  {/* name */ "ctl_check_zero_pv_on", /* range */ "[2:2]", /* default */ "0x0", /* access */ "read-write", /* description */ ""}, 
  {/* name */ "dummy_field", /* range */ "[7:3]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_hwacc_reg__inverse_min_pv[]  = {
  {/* name */ "ctl_min_pv", /* range */ "[31:0]", /* default */ "0x0", /* access */ "read-write", /* description */ ""}
};
field_const_t field_const_hwacc_reg__curr_inst_word0[]  = {
  {/* name */ "sts_current_inst_word_0", /* range */ "[31:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "Current instruction\n"}
};
field_const_t field_const_hwacc_reg__curr_inst_word1[]  = {
  {/* name */ "sts_current_inst_word_1", /* range */ "[31:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "Current instruction\n"}
};
field_const_t field_const_hwacc_reg__curr_inst_word2[]  = {
  {/* name */ "sts_current_inst_word_2", /* range */ "[31:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "Current instruction\n"}
};
field_const_t field_const_hwacc_reg__curr_inst_cycle_cnt[]  = {
  {/* name */ "sts_current_inst_cycle_count", /* range */ "[15:0]", /* default */ "0x0", /* access */ "read-only", /* description */ "Current instruction\n"}
};
field_const_t field_const_hwacc_reg__current_fault[]  = {
  {/* name */ "sts_mem_a_addr_ovfl", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_mem_b_addr_ovfl", /* range */ "[1:1]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_mem_c_addr_ovfl", /* range */ "[2:2]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_mem_d_addr_ovfl", /* range */ "[3:3]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_mem_copy_rw_addr_overlap", /* range */ "[4:4]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_size_out_bound_source_1", /* range */ "[5:5]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_size_out_bound_source_2", /* range */ "[6:6]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_add_sub_size_mismatch", /* range */ "[7:7]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_mul_size_mismatch", /* range */ "[8:8]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_mem_not_unique", /* range */ "[9:9]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_wrong_scaler_size", /* range */ "[10:10]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_initial_offset_overflow_source_1", /* range */ "[11:11]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_initial_offset_overflow_source_2", /* range */ "[12:12]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_initial_offset_overflow_mem_w", /* range */ "[13:13]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_pv_too_small", /* range */ "[14:14]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_pv_equal_zero", /* range */ "[15:15]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_source_not_symmetric", /* range */ "[16:16]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_vector_size_mismatch", /* range */ "[17:17]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_transpose_violation", /* range */ "[18:18]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "sts_divide_by_0_triggered", /* range */ "[19:19]", /* default */ "0x0", /* access */ "read-only", /* description */ ""}, 
  {/* name */ "dummy_field", /* range */ "[23:20]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};

field_const_array_t reg_pnt_list__hwacc_reg[NUM_REGS__HWACC_REG] = {
  { /* pfield */ field_const_hwacc_reg__intr_status, /* size */ 3}, 
  { /* pfield */ field_const_hwacc_reg__intr_mask_status, /* size */ 3}, 
  { /* pfield */ field_const_hwacc_reg__intr_clear, /* size */ 3}, 
  { /* pfield */ field_const_hwacc_reg__intr_set, /* size */ 3}, 
  { /* pfield */ field_const_hwacc_reg__intr_mask_set, /* size */ 3}, 
  { /* pfield */ field_const_hwacc_reg__intr_mask_clear, /* size */ 3}, 
  { /* pfield */ field_const_hwacc_reg__misc_ctrl, /* size */ 6}, 
  { /* pfield */ field_const_hwacc_reg__mem_acc_ctrl, /* size */ 5}, 
  { /* pfield */ field_const_hwacc_reg__inverse_ctrl, /* size */ 4}, 
  { /* pfield */ field_const_hwacc_reg__inverse_min_pv, /* size */ 1}, 
  { /* pfield */ field_const_hwacc_reg__curr_inst_word0, /* size */ 1}, 
  { /* pfield */ field_const_hwacc_reg__curr_inst_word1, /* size */ 1}, 
  { /* pfield */ field_const_hwacc_reg__curr_inst_word2, /* size */ 1}, 
  { /* pfield */ field_const_hwacc_reg__curr_inst_cycle_cnt, /* size */ 1}, 
  { /* pfield */ field_const_hwacc_reg__current_fault, /* size */ 21}
};