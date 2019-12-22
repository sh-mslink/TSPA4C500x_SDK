/**
 ****************************************************************************************
 *
 * @file hal_ecc.h
 *
 * @brief Elliptic Curve Cryptography Profile
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef HAL_ECC_H
#define HAL_ECC_H

/**
 ****************************************************************************************
 * @defgroup HAL_ECC Elliptic Curve Cryptography Profile  
 * @ingroup HAL
 * @brief  HAL ECC
 * @{
 ****************************************************************************************
 */

#include "stdint.h"
#include "in_mmap.h"

/*
 ****************************************************************************************
 * DEFINES
 ****************************************************************************************
 */	

#define ECC_CTRL													0x00000000UL
#define ECC_ENTRY_PNT												0x00000004UL
#define ECC_RTN_CODE												0x00000008UL
#define ECC_BUILD_CONFIG											0x0000000CUL
#define ECC_STACK_PNTR												0x00000010UL
#define ECC_INSTR_SINCE_GO											0x00000014UL
#define ECC_CONFIG													0x0000001CUL
#define ECC_STAT													0x00000020UL
#define ECC_FLAGS													0x00000024UL
#define ECC_WATCHDOG												0x00000028UL
#define ECC_CYCLES_SINCE_GO											0x0000002CUL
#define ECC_INDEX_I													0x00000030UL
#define ECC_INDEX_J													0x00000034UL
#define ECC_INDEX_K													0x00000038UL
#define ECC_INDEX_L													0x0000003CUL
#define ECC_IRQ_EN													0x00000040UL
#define ECC_JMP_PROB												0x00000044UL
#define ECC_JMP_PROB_LFSR											0x00000048UL
#define ECC_BANK_SW_A												0x00000050UL
#define ECC_BANK_SW_B												0x00000054UL
#define ECC_BANK_SW_C												0x00000058UL
#define ECC_BANK_SW_D												0x0000005CUL
#define ECC_Reserve1												0x00000000UL
#define ECC_Reserve2												0x00000000UL

#define ECC_CTRL_GO													0x80000000UL
#define ECC_CTRL_STOP												0x08000000UL
#define ECC_CTRL_BASE_RADIX											0x00000700UL
#define ECC_CTRL_PARTIAL_RADIX										0x000000FFUL

static __inline void ecc_go(void)
{
	uint32_t reg = RD_WORD(ECC_BASE + ECC_CTRL);
	reg |= ECC_CTRL_GO;
	WR_WORD(ECC_BASE + ECC_CTRL, reg);
}

static __inline void ecc_halt(void)
{
	uint32_t reg = RD_WORD(ECC_BASE + ECC_CTRL);
	reg |= ECC_CTRL_STOP;
	WR_WORD(ECC_BASE + ECC_CTRL, reg);
}

static __inline void ecc_base_radix(int radix)
{
	uint32_t reg = RD_WORD(ECC_BASE + ECC_CTRL);
	reg &= ~ECC_CTRL_BASE_RADIX;
	reg |= (radix << 8);
	WR_WORD(ECC_BASE + ECC_CTRL, reg);
}

static __inline void ecc_partial_radix(int radix)
{
	uint32_t reg = RD_WORD(ECC_BASE + ECC_CTRL);
	reg &= ~ECC_CTRL_PARTIAL_RADIX;
	reg |= radix;
	WR_WORD(ECC_BASE + ECC_CTRL, reg);
}

#define ECC_ENTRY_PNT_ADDR											0x00000FFFUL

static __inline void ecc_entry_addr(uint32_t addr)
{
	uint32_t reg = RD_WORD(ECC_BASE + ECC_ENTRY_PNT);
	reg &= ~ECC_ENTRY_PNT_ADDR;
	reg |= addr;
	WR_WORD(ECC_BASE + ECC_ENTRY_PNT, reg);
}

static __inline int ecc_rtn_busy(void)
{
	return ((RD_WORD(ECC_BASE + ECC_RTN_CODE) >> 31) & 1);
}

static __inline int ecc_rtn_irq(void)
{
	return ((RD_WORD(ECC_BASE + ECC_RTN_CODE) >> 30) & 1);
}

static __inline int ecc_rtn_zero(void)
{
	return ((RD_WORD(ECC_BASE + ECC_RTN_CODE) >> 28) & 1);
}

#define ECC_RTN_REASON_NORMAL_STOP									0
#define ECC_RTN_REASON_INVALID_OP_CODE								1
#define ECC_RTN_REASON_STACK_OVF									2
#define ECC_RTN_REASON_STACK_UNF									3
#define ECC_RTN_REASON_WDT											4
#define ECC_RTN_REASON_HOST_REQ										5

static __inline int ecc_rtn_reason(void)
{
	return ((RD_WORD(ECC_BASE + ECC_RTN_CODE) >> 16) & 0xFF);
}

static __inline void ecc_stack_pntr_clear(void)
{
	WR_WORD(ECC_BASE + ECC_STACK_PNTR, 0);
}

#define ECC_CONFIG_ENDIAN_SWAP										(1 << 26)

static __inline void ecc_config_endian_swap(void)
{
	uint32_t reg = RD_WORD(ECC_BASE + ECC_CONFIG);
	reg ^= ECC_CONFIG_ENDIAN_SWAP;
	WR_WORD(ECC_BASE + ECC_CONFIG, reg);
}

#define ECC_STAT_DONE												0x40000000UL

static __inline uint32_t ecc_stat(void)
{
	return RD_WORD(ECC_BASE + ECC_STAT);
}

static __inline void ecc_stat_ack_irq(void)
{
	uint32_t reg = RD_WORD(ECC_BASE + ECC_STAT);
	reg |= (1<<30);
	WR_WORD(ECC_BASE + ECC_STAT, reg);
}

static __inline void ecc_irq_enable(void)
{
	uint32_t reg = RD_WORD(ECC_BASE + ECC_IRQ_EN);
	reg |= (1<<30);
	WR_WORD(ECC_BASE + ECC_IRQ_EN, reg);
}

static __inline void ecc_irq_disable(void)
{
	uint32_t reg = RD_WORD( + ECC_IRQ_EN);
	reg &= ~(1 << 30);
	WR_WORD(ECC_BASE + ECC_IRQ_EN, reg);
}

static __inline void ecc_flag_clear(void)
{
	WR_WORD(ECC_BASE + ECC_FLAGS, 0);
}

static __inline void ecc_stack_clear(void)
{
	WR_WORD(ECC_BASE + ECC_STACK_PNTR, 0);
}

static __inline void ecc_mem_en(int en)
{
	WR_WORD(GLOBAL_REG_AES_ECC_MEM_SEL, GLOBAL_REG_AES_ECC_MEM_SEL_DEFAULT);
}

#define ECC_A0_BASE												(ECC_BASE + 0x400)
#define ECC_B0_BASE												(ECC_BASE + 0x800)
#define ECC_C0_BASE												(ECC_BASE + 0xC00)
#define ECC_D0_BASE												(ECC_BASE + 0x1000)

#define ECC_FW_BASE												(ECC_BASE + 0x4000)

#define ECC_FW_ENTRY_CALC_MP                                     0x10
#define ECC_FW_ENTRY_CALC_R_INV                                  0x11
#define ECC_FW_ENTRY_CALC_R_SQR                                  0x12
#define ECC_FW_ENTRY_IS_A_M3                                     0x1d
#define ECC_FW_ENTRY_IS_P_EQUAL_Q                                0x1b
#define ECC_FW_ENTRY_IS_P_REFLECT_Q                              0x1c
#define ECC_FW_ENTRY_MODADD                                      0xb
#define ECC_FW_ENTRY_MODDIV                                      0xd
#define ECC_FW_ENTRY_MODINV                                      0xe
#define ECC_FW_ENTRY_MODMULT                                     0xa
#define ECC_FW_ENTRY_MODSUB                                      0xc
#define ECC_FW_ENTRY_MULT                                        0x13
#define ECC_FW_ENTRY_PADD                                        0x17
#define ECC_FW_ENTRY_PADD_STD_PRJ                                0x18
#define ECC_FW_ENTRY_PDBL                                        0x15
#define ECC_FW_ENTRY_PDBL_STD_PRJ                                0x16
#define ECC_FW_ENTRY_PMULT                                       0x14
#define ECC_FW_ENTRY_PVER                                        0x19
#define ECC_FW_ENTRY_REDUCE                                      0xf
#define ECC_FW_ENTRY_SHAMIR                                      0x1e
#define ECC_FW_ENTRY_STD_PRJ_TO_AFFINE                           0x1a

/// ECC function status return
typedef enum {
	/// No errors, good status. 
	ECC_ERR_OK = 0,
	/// Error, ECC driver not initialized
	ECC_ERR_NOT_INIT = 1,
	/// Error, ECC driver already initialized
	ECC_ERR_ALREADY_INIT = 2,
	/// Error, ECC bad state 
	ECC_ERR_DEV_BAD_STATE = 3,
	/// Error, ECC operation returned abnormal stop condition. 
	ECC_ERR_NON_NORMAL_STOP = 4,
	/// Error, invalid elliptic curve (EC) point. Point is not on elliptic curve. 
	ECC_ERR_INVALID_POINT = 5,
	/// Error, invalid ECC size parameter. 
	ECC_ERR_INVALID_PARA = 6,
	/// Error, AES using the HW memory 
	ECC_ERR_HW_MEM_USED_BY_AES = 7
} ecc_result_status;

/**
 ****************************************************************************************
 * @brief Initialize ECC driver for power management and interrupt purposes.
 *
 * @return ECC_ERR_OK if ECC initializes successfully, error otherwise. @see enum ecc_result_status.
 ****************************************************************************************
 */
int hal_ecc_open(void);

/**
 ****************************************************************************************
 * @brief De-Initialize ECC driver for power management and interrupt purposes.
 *
 * @return ECC_ERR_OK if ECC uninitializes successfully, error otherwise. @see enum ecc_result_status.
 ****************************************************************************************
 */
int hal_ecc_close(void);

/**
 ****************************************************************************************
 * @brief Ecc and Aes shared the same HW memory. This is to inform AES that Ecc currently is using the HW
 * memory.
 *
 * @return 1 if Ecc is using the HW memory, 0 otherwise.
 ****************************************************************************************
 */
int hal_ecc_is_open(void);

/**
 ****************************************************************************************
 * @brief Computes the modular inverse of r.
 *			(1/(r mod m))
 *
 * @param[in] size		Key size.
 * @param[in] m			Pointer to the modulus of the underlying field.
 * @param[out] r_inv	Pointer to the output result, modular inverse of r.
 *
 * @return ECC_ERR_OK if successful, otherwise failed. @see enum ecc_result_status 
 ****************************************************************************************
 */
int hal_ecc_r_inv_mod_m(uint16_t size, const uint8_t *m, uint8_t *r_inv);

/**
 ****************************************************************************************
 * @brief Computes the Montgomery residue constant.
 *			(m')
 *
 * @param[in] size		Key size.
 * @param[in] r_inv		Pointer to the Montgomery precomputed value, modular inverse of r. 
 * @param[in] m			Pointer to the modulus of the underlying field.
 * @param[out] mp		Pointer to the output result, Montgomery residue constant.
 *
 * @return ECC_ERR_OK if successful, otherwise failed. @see enum ecc_result_status 
 ****************************************************************************************
 */
int hal_ecc_m_prime(uint16_t size, const uint8_t *r_inv, const uint8_t *m, uint8_t *mp);

/**
 ****************************************************************************************
 * @brief Computes the Montgomery residue conversion constant.
 *			(r^2) mod m
 *
 * @param[in] size		Key size.
 * @param[in] r_inv		Pointer to the Montgomery precomputed value, modular inverse of r. 
 * @param[in] m			Pointer to the modulus of the underlying field.
 * @param[out] r_sqr	Pointer to the output result, Montgomery residue conversion constant.
 *
 * @return ECC_ERR_OK if successful, otherwise failed. @see enum ecc_result_status 
 ****************************************************************************************
 */
int hal_ecc_r_sqr_mod_m(uint16_t size, const uint8_t *r_inv, const uint8_t *m, uint8_t *r_sqr);

/**
 ****************************************************************************************
 * @brief Multiplies two integers, each of a size contained in the operand size set, over the modular field m.
 *			(x * y) mod m
 *
 * @param[in] size		Key size.
 * @param[in] x			Pointer to the first operand of this modular multiplication expression.
 * @param[in] y			Pointer to the second operand of this modular multiplication expression.
 * @param[in] m			Pointer to the modulus of the underlying field.
 * @param[in] mp		Pointer to the Montgomery residue constant.
 * @param[in] r_sqr		Pointer to the Montgomery residue conversion constant.
 * @param[out] c		Pointer to the output result, modular product of input x and y.
 *
 * @return ECC_ERR_OK if successful, otherwise failed. @see enum ecc_result_status 
 ****************************************************************************************
 */
int hal_ecc_mod_mult(uint16_t size, const uint8_t *x, const uint8_t *y, const uint8_t *m, const uint8_t *mp, const uint8_t *r_sqr, uint8_t *c);

/**
 ****************************************************************************************
 * @brief Adds two integers, each of a size contained in the operand size set, over the modular
 *			(x + y) mod m
 *
 * @param[in] size		Key size.
 * @param[in] x			Pointer to the first operand of this modular addition expression.
 * @param[in] y			Pointer to the second operand of this modular addition expression.
 * @param[in] m			Pointer to the modulus of the underlying field.
 * @param[out] c		Pointer to the output result, modular sum of input x and y.
 *
 * @return ECC_ERR_OK if successful, otherwise failed. @see enum ecc_result_status 
 ****************************************************************************************
 */
int hal_ecc_mod_add(uint16_t size, const uint8_t *x, const uint8_t *y, const uint8_t *m, uint8_t *c);

/**
 ****************************************************************************************
 * @brief Subtracts two integers, each of a size contained in the operand size set, over the modular field m.
 *			(x - y) mod m
 *
 * @param[in] size		Key size.
 * @param[in] x			Pointer to the first operand of this modular subtraction expression.
 * @param[in] y			Pointer to the second operand of this modular subtraction expression.
 * @param[in] m			Pointer to the modulus of the underlying field.
 * @param[out] c		Pointer to the output result, modular difference of input x and y.
 *
 * @return ECC_ERR_OK if successful, otherwise failed. @see enum ecc_result_status 
 ****************************************************************************************
 */
int hal_ecc_mod_sub(uint16_t size, const uint8_t *x, const uint8_t *y, const uint8_t *m, uint8_t *c);

/**
 ****************************************************************************************
 * @brief Divides one integer by another, each of a size contained in the operand size set, over the modular field m.
 *			(y / x) mod m
 *
 * @param[in] size		Key size.
 * @param[in] y			Pointer to the first operand of this modular division expression.
 * @param[in] x			Pointer to the second operand of this modular division expression.
 * @param[in] m			Pointer to the modulus of the underlying field.
 * @param[out] c		Pointer to the output result, modular difference of input x and y.
 *
 * @return ECC_ERR_OK if successful, otherwise failed. @see enum ecc_result_status 
 ****************************************************************************************
 */
int hal_ecc_mod_div(uint16_t size, const uint8_t *y, const uint8_t *x, const uint8_t *m, uint8_t *c);

/**
 ****************************************************************************************
 * @brief Calculates the inversion of an integer, of a size contained in the operand size set, over the modular field m.
 *			(1 / x) mod m
 *
 * @param[in] size		Key size.
 * @param[in] x			Pointer to the operand of this modular inversion expression.
 * @param[in] m			Pointer to the modulus of the underlying field.
 * @param[out] c		Pointer to the output result, modular inversion of input x.
 *
 * @return ECC_ERR_OK if successful, otherwise failed. @see enum ecc_result_status 
 ****************************************************************************************
 */
int hal_ecc_mod_inv(uint16_t size, const uint8_t *x, const uint8_t *m, uint8_t *c);

/**
 ****************************************************************************************
 * @brief Computes the ECC Point Multiplication over the curve y^2 = x^3 + ax + b mod p.
 *			R = 2P
 *
 * @param[in] size		Key size.
 * @param[in] Px		Pointer to the x coordinate of the operand.
 * @param[in] Py		Pointer to the y coordinate of the operand.
 * @param[in] a			Curve parameter, a.
 * @param[in] w			Random blinding value, w.
 * @param[in] p			Curve prime modulus, p.
 * @param[in] mp		Montgomery precomputed value, p'.
 * @param[in] r_sqr		Montgomery precomputed value, (r^2) mod p.
 * @param[in] k			Key, k.
 * @param[out] Rx		Pointer to the x coordinate of the result.
 * @param[out] Ry		Pointer to the y coordinate of the result.
 *
 * @return ECC_ERR_OK if successful, otherwise failed. @see enum ecc_result_status 
 ****************************************************************************************
 */
int hal_ecc_pmult(uint16_t size, const uint8_t *Px, const uint8_t *Py, const uint8_t *a, const uint8_t *w, const uint8_t *p, const uint8_t *mp, const uint8_t *r_sqr, const uint8_t *k, uint8_t *Rx, uint8_t *Ry);

/**
 ****************************************************************************************
 * @brief Computes the ECC Point Addition over the curve y^2 = x^3 + ax + b mod p.
 *			R = P + Q
 *
 * @param[in] size		Key size.
 * @param[in] Px		Pointer to the x coordinate of the first operand.
 * @param[in] Py		Pointer to the y coordinate of the first operand.
 * @param[in] Qx		Pointer to the x coordinate of the second operand.
 * @param[in] Qy		Pointer to the y coordinate of the second operand.
 * @param[in] a			Curve parameter, a.
 * @param[in] p			Curve prime modulus, p.
 * @param[in] mp		Montgomery precomputed value, p'.
 * @param[in] r_sqr		Montgomery precomputed value, (r^2) mod p.
 * @param[out] Rx		Pointer to the x coordinate of the result.
 * @param[out] Ry		Pointer to the y coordinate of the result.
 *
 * @return ECC_ERR_OK if successful, otherwise failed. @see enum ecc_result_status 
 ****************************************************************************************
 */
int hal_ecc_padd(uint16_t size, const uint8_t *Px, const uint8_t *Py, const uint8_t *Qx, const uint8_t *Qy, const uint8_t *a, const uint8_t *p, const uint8_t *mp, const uint8_t *r_sqr, uint8_t *Rx, uint8_t *Ry);

/**
 ****************************************************************************************
 * @brief Computes the EC Point Doubling over the curve y2 = x3 + ax + b mod p.
 *			R = 2P
 *
 * @param[in] size		Key size.
 * @param[in] Px		Pointer to the x coordinate of the operand.
 * @param[in] Py		Pointer to the y coordinate of the operand.
 * @param[in] a			Curve parameter, a.
 * @param[in] p			Curve prime modulus, p.
 * @param[in] mp		Montgomery precomputed value, p'.
 * @param[in] r_sqr		Montgomery precomputed value, (r^2) mod p.
 * @param[out] Rx		Pointer to the x coordinate of the result.
 * @param[out] Ry		Pointer to the y coordinate of the result.
 *
 * @return ECC_ERR_OK if successful, otherwise failed. @see enum ecc_result_status 
 ****************************************************************************************
 */
int hal_ecc_pdbl(uint16_t size, const uint8_t *Px, const uint8_t *Py, const uint8_t *a, const uint8_t *p, const uint8_t *mp, const uint8_t *r_sqr, uint8_t *Rx, uint8_t *Ry);

/**
 ****************************************************************************************
 * @brief Computes y2 == x3 + ax + b mod p and verified LHS == RHS.
 *
 * @param[in] size		Key size.
 * @param[in] Px		Pointer to the x coordinate of the operand.
 * @param[in] Py		Pointer to the y coordinate of the operand.
 * @param[in] a			Curve parameter, a.
 * @param[in] p			Curve prime modulus, p.
 * @param[in] mp		Montgomery precomputed value, p'.
 * @param[in] r_sqr		Montgomery precomputed value, (r^2) mod p.
 *
 * @return ECC_ERR_OK if verified point, otherwise failed. @see enum ecc_result_status 
 ****************************************************************************************
 */
int hal_ecc_pver(uint16_t size, const uint8_t *Px, const uint8_t *Py, const uint8_t *a, const uint8_t *b, const uint8_t *p, const uint8_t *mp, const uint8_t *r_sqr);

/**
 ****************************************************************************************
 * @brief Calculate R = kP + lQ using Shamir's Trick
 *
 * @param[in] size		Key size.
 * @param[in] Px		Pointer to the x coordinate of the first operand.
 * @param[in] Py		Pointer to the y coordinate of the first operand.
 * @param[in] Qx		Pointer to the x coordinate of the second operand.
 * @param[in] Qy		Pointer to the y coordinate of the second operand.
 * @param[in] a			Curve parameter, a.
 * @param[in] k			Multiplier associated with point P.
 * @param[in] l			Multiplier associated with point Q.
 * @param[in] p			Curve prime modulus, p.
 * @param[in] mp		Montgomery precomputed value, p'.
 * @param[in] r_sqr		Montgomery precomputed value, (r^2) mod p.
 * @param[out] Rx		Pointer to the x coordinate of the result.
 * @param[out] Ry		Pointer to the y coordinate of the result.
 *
 * @return ECC_ERR_OK if successful, otherwise failed. @see enum ecc_result_status 
 ****************************************************************************************
 */
int hal_ecc_shamir(uint16_t size, const uint8_t *Px, const uint8_t *Py, const uint8_t *Qx, const uint8_t *Qy, const uint8_t *a, const uint8_t *k, const uint8_t *l, 
/// @} HAL_ECC												const uint8_t *p, const uint8_t *mp, const uint8_t *r_sqr, uint8_t *Rx, uint8_t *Ry);

#endif
