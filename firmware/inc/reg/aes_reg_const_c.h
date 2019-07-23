/////////////////////////////////////////////////////////////////////////////////
// This file has been automatically generated by register_slave.pl version a8eabd3
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

#define NUM_REGS__AES_REG  8
/* { reg_const_aes_reg, 8, "aes_reg"},  */ 
static reg_const_t reg_const_aes_reg[NUM_REGS__AES_REG] = {
  {/* name */ "misc_ctrl", /* address */ 0x44018000, /* default */ 0x00000000, /* description */ "misc control\n"}, 
  {/* name */ "ctx_index", /* address */ 0x44018004, /* default */ 0x00000000, /* description */ "Index of context page to store/retrieve from\n"}, 
  {/* name */ "block_index", /* address */ 0x44018008, /* default */ 0x00000000, /* description */ "Index in msg memory of 1st block of msg\n"}, 
  {/* name */ "aad_length", /* address */ 0x4401800c, /* default */ 0x00000000, /* description */ "Number of AD bytes in current operation (CCM, GCM only)\n"}, 
  {/* name */ "num_bytes", /* address */ 0x44018010, /* default */ 0x00000000, /* description */ "Number of bytes of msg in current operation\n"}, 
  {/* name */ "num_total_bytes", /* address */ 0x44018014, /* default */ 0x00000000, /* description */ "Total number of bytes of msg (not incl AAD)\n"}, 
  {/* name */ "tag_msg_addr", /* address */ 0x44018018, /* default */ 0x00000000, /* description */ "Tag message address\n"}, 
  {/* name */ "aad_len_total", /* address */ 0x4401801c, /* default */ 0x00000000, /* description */ "AD total length\n"}
};

field_const_t field_const_aes_reg__misc_ctrl[]  = {
  {/* name */ "go", /* range */ "[0:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "Kick off the process\n"}, 
  {/* name */ "encrypt", /* range */ "[1:1]", /* default */ "0x0", /* access */ "read-write", /* description */ "1 = encrypt,  0 = decrypt\n"}, 
  {/* name */ "msg_begin", /* range */ "[2:2]", /* default */ "0x0", /* access */ "read-write", /* description */ "beginning of the message\n"}, 
  {/* name */ "msg_end", /* range */ "[3:3]", /* default */ "0x0", /* access */ "read-write", /* description */ "end of the message\n"}, 
  {/* name */ "mode", /* range */ "[7:4]", /* default */ "0x0", /* access */ "read-write", /* description */ "0 - pECB_MODE  = `ELP_AES_BLK_MODE_ECB\n1 - pCBC_MODE  = `ELP_AES_BLK_MODE_CBC,\n2 - pCTR_MODE  = `ELP_AES_BLK_MODE_CTR,\n3 - pCCM_MODE  = `ELP_AES_BLK_MODE_CCM,\n4 - pCMAC_MODE = `ELP_AES_BLK_MODE_OMAC,\n5 - ELP_AES_BLK_MODE_GCM,\n6 - pXCBC_MODE = `ELP_AES_BLK_MODE_XCBC,\n7 - ELP_AES_BLK_MODE_OFB,\n8 - ELP_AES_BLK_MODE_CFB,\n9 - pF8_MODE   = `ELP_AES_BLK_MODE_F8;\n\n"}, 
  {/* name */ "mac_len", /* range */ "[11:8]", /* default */ "0x0", /* access */ "read-write", /* description */ "length of the MAC in bytes (?)\n\n"}, 
  {/* name */ "key_size", /* range */ "[13:12]", /* default */ "0x0", /* access */ "read-write", /* description */ "key size: 0 - 128 bits\n1 - 196 bits\n2 - 256 bits\nother value: invalid\n\n"}, 
  {/* name */ "str_ctx", /* range */ "[14:14]", /* default */ "0x0", /* access */ "read-write", /* description */ "Store engine's internal context out to mem\n"}, 
  {/* name */ "ret_ctx", /* range */ "[15:15]", /* default */ "0x0", /* access */ "read-write", /* description */ "Retrieve engine's internal context from mem\n"}, 
  {/* name */ "inv_key", /* range */ "[16:16]", /* default */ "0x0", /* access */ "read-write", /* description */ "Keys retrieved or used are inverse keys\n"}, 
  {/* name */ "str_inv_key", /* range */ "[17:17]", /* default */ "0x0", /* access */ "read-write", /* description */ "Store generated inv keys into ctx mem \n"}, 
  {/* name */ "str_tag2msg", /* range */ "[18:18]", /* default */ "0x0", /* access */ "read-write", /* description */ "Store tag to specified address in msg memory\n"}, 
  {/* name */ "gmac", /* range */ "[19:19]", /* default */ "0x0", /* access */ "read-write", /* description */ "Enable GMAC mode\n"}, 
  {/* name */ "dummy_field", /* range */ "[23:20]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aes_reg__ctx_index[]  = {
  {/* name */ "index", /* range */ "[3:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "Index of context page to store/retrieve from\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:4]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aes_reg__block_index[]  = {
  {/* name */ "index", /* range */ "[1:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "Index in msg memory of 1st block of msg\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:2]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aes_reg__aad_length[]  = {
  {/* name */ "length", /* range */ "[6:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "Number of AD bytes in current operation (CCM, GCM only)\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:7]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aes_reg__num_bytes[]  = {
  {/* name */ "num_bytes", /* range */ "[6:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "Number of bytes of msg in current operation\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:7]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aes_reg__num_total_bytes[]  = {
  {/* name */ "num_total_bytes", /* range */ "[15:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "Total number of bytes of msg (not incl AAD)\n"}
};
field_const_t field_const_aes_reg__tag_msg_addr[]  = {
  {/* name */ "addr", /* range */ "[5:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "Tag message address\n"}, 
  {/* name */ "dummy_field", /* range */ "[7:6]", /* default */ "0x0", /* access */ "no-access", /* description */ ""}
};
field_const_t field_const_aes_reg__aad_len_total[]  = {
  {/* name */ "len", /* range */ "[15:0]", /* default */ "0x0", /* access */ "read-write", /* description */ "AD total length\n"}
};

field_const_array_t reg_pnt_list__aes_reg[NUM_REGS__AES_REG] = {
  { /* pfield */ field_const_aes_reg__misc_ctrl, /* size */ 14}, 
  { /* pfield */ field_const_aes_reg__ctx_index, /* size */ 2}, 
  { /* pfield */ field_const_aes_reg__block_index, /* size */ 2}, 
  { /* pfield */ field_const_aes_reg__aad_length, /* size */ 2}, 
  { /* pfield */ field_const_aes_reg__num_bytes, /* size */ 2}, 
  { /* pfield */ field_const_aes_reg__num_total_bytes, /* size */ 1}, 
  { /* pfield */ field_const_aes_reg__tag_msg_addr, /* size */ 2}, 
  { /* pfield */ field_const_aes_reg__aad_len_total, /* size */ 1}
};
