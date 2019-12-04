/**
 ****************************************************************************************
 *
 * @file hal_counter.h
 *
 * @brief Counter driver header file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
#ifndef HAL_COUNTER_H
#define HAL_COUNTER_H
/**
 ****************************************************************************************
 * @defgroup HAL_COUNTER Counter  driver  
 * @ingroup HAL
 * @brief  HAL_COUNTER
 * @{
 ****************************************************************************************
 */

#include ".\hal\hal_power.h"
#include "cmsis_os.h"
#include "in_mmap.h"
#include <stdint.h>
//#define APB_CLOCK 32000000

#define CNT0_BASE (0)
#define CNT1_BASE (0x100)
#define CNT2_BASE (0x200)
#define CNT3_BASE (0x300)

#define CNT_CAPTURE_SHIFTIN_MODE 0x0
#define CNT_WAVEFORM_SHITOUT_MODE 0x1
#define CNT_COUNT_MODE 0x0
#define CNT_SHIFT_MODE 0x2
#define CNT_SWITCH_DISABLE 0x0
#define CNT_SWITCH_ENABLE 0x4

#define CNT_CAPTURE_MODE (CNT_CAPTURE_SHIFTIN_MODE | CNT_COUNT_MODE)
#define CNT_WAVAFORM_MODE (CNT_WAVEFORM_SHITOUT_MODE | CNT_COUNT_MODE)
#define CNT_SHIFTIN_MODE (CNT_CAPTURE_SHIFTIN_MODE | CNT_SHIFT_MODE)
#define CNT_SHIFTOUT_MODE (CNT_WAVEFORM_SHITOUT_MODE | CNT_SHIFT_MODE)

//enable_c0
#define CNT_ENABLE 0x1UL
#define CNT_CLK_INV_ENABLE 0x1000UL
#define CNT_CLK_ENABLE 0x2000UL
#define CNT_ROOT_CLK_DIV8 0
#define CNT_ROOT_CLK_DIV4 1
#define CNT_ROOT_CLK_DIV2 2
#define CNT_32K_CLK 3
#define CNT_EXT_CLK0 4
#define CNT_EXT_CLK1 5
#define CNT_EXT_CLK2 6

/* For count0, clk0 is count1, clk1 is count2, clk2 is count3.
    For count1, clk0 is count0, clk1 is count2, clk2 is count3 */
#define CNT_COUNTER_CLK0 7
#define CNT_COUNTER_CLK1 8
#define CNT_COUNTER_CLK2 9

//src_sel_start_c0
#define CNT_EXT_DIN_A 1
#define CNT_EXT_DIN_B 2
#define CNT_GLOBAL_START_TRIGGER 3
#define CNT_SINGLE_START_TRIGGER 4
#define CNT_GLOBAL_STOP_TRIGGER 5
#define CNT_SINGLE_STOP_TRIGGER 6
#define CNT_INNER_DIN0 11
#define CNT_INNER_DIN1 12
#define CNT_INNER_DIN2 13
#define CNT_INNER_DIN3 14
#define CNT_START_SIGNLE_SHIFT 0
#define CNT_STOP_SIGNLE_SHIFT 8
#define CNT_DIN0_SHIFT 16
#define CNT_DIN1_SHIFT 24
#define CNT_RISING_EDGE 0
#define CNT_FALLING_EDGE 0x10UL
#define CNT_BOTH_EDGE 0x20UL

//ctrl_snap_c0  reverse
#define CNT_SNAP_SHADOW_MASK 0x1UL
#define CNT_SNAP_CAPTURE_A_MASK 0x2UL
#define CNT_SNAP_CAPTURE_B_MASK 0x4UL
#define CNT_SNAP_SHIFTIN_DATA_MASK 0x8UL
#define CNT_SNAP_CLEAR_MASK 0x10000UL

//TARGET_REG_CTRL
#define CNT_A2_KEEP_VALUE 0x1UL
#define CNT_A2_RESET_VALUE 0x0UL
#define CNT_A2_STOP_COUNTER 0x2UL
#define CNT_A2_RESTART_COUNTER 0x0UL
#define CNT_B2_KEEP_VALUE 0x4UL
#define CNT_B2_RESET_VALUE 0x0UL
#define CNT_B2_STOP_COUNTER 0x8UL
#define CNT_B2_RESTART_COUNTER 0x0UL
#define CNT_DOUT_A_RESET_VALUE_SHIFT 4
#define CNT_DOUT_B_RESET_VALUE_SHIFT 5

//ir_dout_bypass_c0
#define CNT_OUT_BYPASS_A 0x10000UL //Bypass pin A operation(AND, OR and NOT)
#define CNT_OUT_BYPASS_B 0x20000UL //Bypass pin B operation(AND, OR and NOT)

//ir_din_bypass_c0
#define CNT_IN_BYPASS_A 0x1UL
#define CNT_IN_BYPASS_B 0x2UL

//shiftmode_point_en_c0
#define CNT_SHIFTMODE_POINT_EN 0x10000

//waveform_mode_automatic_c0
#define CNT_WAVEFORM_SHIFTOUT_CNT_SHIFT 0
#define CNT_CAPTURE_SHIFTIN_CNT_SHIFT 8
#define CNT_WAVEFORM_SHIFTOUT_AUTO_ENABLE 0x10000UL
#define CNT_CAPTURE_SHIFTIN_AUTO_ENABLE 0x1000000UL

//interrupt
#define CNT0_SHIFT 0
#define CNT1_SHIFT 8
#define CNT2_SHIFT 16
#define CNT3_SHIFT 24
#define CNT_A_UPDATE 1
#define CNT_B_UPDATE 0x2
#define CNT_OVERFLOW 0x4
#define CNT_SHIFTIN_COMPLETE 0x8
#define CNT_SHIFTOUT_COMPLETE 0x10
#define CNT_WAVEFORM_STOP 0x20 //counter value reach a2 or b2
#define CNT_SHIFTIN_CAPTURE_END 0x40 //need enable auto switch
#define CNT_SHIFTOUT_WAVEFORM_END 0x80 //need enable auto swtich

//reset_ctrl_4
#define CNT_RESET_CNT0 0x00000010UL
#define CNT_RESET_CNT1 0x00000020UL
#define CNT_RESET_CNT2 0x00000040UL
#define CNT_RESET_CNT3 0x00000080UL

/* flip bit with mask */
#define FLIP_BIT(val, mask)            \
    do {                               \
        uint32_t _tmp = (~val) & mask; \
        val &= ~mask;                  \
        val |= _tmp;                   \
    } while (0)
#define DUMP_REG(reg, base) PRINTD(DBG_TRACE, #reg " %08x (%x)\n", RD_WORD(reg + base), base)
enum {
    CNT0_ID = 0,
    CNT1_ID,
    CNT2_ID,
    CNT3_ID,
    CNT_MAX_ID,
};
	
enum cnt_ext_pin {
    CNT_PIN0 = 0, ///GPIO2_1
    CNT_PIN1, ///GPIO2_2
    CNT_PIN2, ///GPIO2_3
    CNT_PIN3, ///GPIO2_4
    CNT_PIN4, ///GPIO2_5
    CNT_PIN5, ///GPIO2_6
    CNT_PIN6, ///GPIO2_7
    CNT_PIN7, ///GPIO2_8
    CNT_MAX_PIN,
};
enum cnt_error {
    CNT_ERR_OK = 0,
    CNT_ERR_INVALID_PARAM = -1,
    CNT_ERR_TIMEOUT = -2,
};
typedef struct {
    int id;
    uint32_t base;
    void (*isr_handler)(uint32_t status, void* priv_data);
    void* isr_arg;
    uint32_t clk;
    int clk_div;
    int used;

#if CFG_PM_EN
    int power_state;
    struct pm_module pmd;
#endif

} cnt_dev_t;

typedef void (*CNT_ISR_FUN)(uint32_t, void*);

static __inline void cnt_enable_clk(uint32_t base)
{
    uint32_t reg = RD_WORD(COUNTER_ALL_APB_REG_ENABLE_C0 + base);
    reg |= CNT_CLK_ENABLE;
    WR_WORD(COUNTER_ALL_APB_REG_ENABLE_C0 + base, reg);
}
static __inline void cnt_disable_clk(uint32_t base)
{
    uint32_t reg = RD_WORD(COUNTER_ALL_APB_REG_ENABLE_C0 + base);
    reg &= ~CNT_CLK_ENABLE;
    WR_WORD(COUNTER_ALL_APB_REG_ENABLE_C0 + base, reg);
}
static __inline void cnt_set_clk(uint32_t base, uint32_t val)
{
    uint32_t reg = RD_WORD(COUNTER_ALL_APB_REG_ENABLE_C0 + base);
    reg |= val << 8;
    WR_WORD(COUNTER_ALL_APB_REG_ENABLE_C0 + base, reg);
}

static __inline void cnt_set_mode(uint32_t base, uint32_t mode)
{
    WR_WORD(COUNTER_ALL_APB_REG_MODE_SEL_C0 + base, mode);
}
static __inline void cnt_set_src_edge(uint32_t base, uint32_t src_edge)
{
    WR_WORD(COUNTER_ALL_APB_REG_SRC_SEL_EDGE_C0 + base, src_edge);
}
static __inline void cnt_set_target_ctrl(uint32_t base, uint32_t ctrl)
{
    WR_WORD(COUNTER_ALL_APB_REG_TARGET_REG_CTRL_C0 + base, ctrl);
}
static __inline void cnt_set_soft_trigger(uint32_t base, uint32_t trigger)
{
    WR_WORD(COUNTER_ALL_APB_REG_SOFT_TRIGGER_CTRL_C0 + base, trigger);
}
static __inline void cnt_set_target_a(uint32_t base, uint32_t a0, uint32_t a1, uint32_t a2)
{
    WR_WORD(COUNTER_ALL_APB_REG_TARGET_REG_A0_C0 + base, a0);
    WR_WORD(COUNTER_ALL_APB_REG_TARGET_REG_A1_C0 + base, a1);
    WR_WORD(COUNTER_ALL_APB_REG_TARGET_REG_A2_C0 + base, a2);
}
static __inline void cnt_set_target_b(uint32_t base, uint32_t b0, uint32_t b1, uint32_t b2)
{
    WR_WORD(COUNTER_ALL_APB_REG_TARGET_REG_B0_C0 + base, b0);
    WR_WORD(COUNTER_ALL_APB_REG_TARGET_REG_B1_C0 + base, b1);
    WR_WORD(COUNTER_ALL_APB_REG_TARGET_REG_B2_C0 + base, b2);
}
static __inline void cnt_set_out_bypass(uint32_t base, uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_IR_DOUT_BYPASS_C0 + base, val);
}
static __inline void cnt_set_in_bypass(uint32_t base, uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_IR_DIN_BYPASS_C0 + base, val);
}
static __inline void cnt_set_input_mux(uint32_t base, uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_MUX_SEL_C0 + base, val);
}
static __inline void cnt_set_shiftmode_ctrl(uint32_t base, uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_SHIFTMODE_CTRL_C0 + base, val);
}

/* shiftin n bits*/
static __inline void cnt_set_shiftin_bit_num(uint32_t base, uint32_t n)
{
    WR_WORD(COUNTER_ALL_APB_REG_SHIFTIN_DATA_CTRL_BITCNTS_C0 + base, n);
}

/* enable and sample point*/
static __inline void cnt_set_shiftmode_point_en(uint32_t base, uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_SHIFTMODE_POINT_EN_C0 + base, val);
}

static __inline void cnt_set_one_bit_count(uint32_t base, uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_SWITCH_MODE_ONEBIT_CNTS_C0 + base, val);
}

static __inline void cnt_set_one_cycle_value(uint32_t base, uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_IR_DIN_ONECYCLE_VALUE_A_C0 + base, val);
}
static __inline void cnt_config_switch_mode(uint32_t base, uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_WAVEFORM_MODE_AUTOMATIC_C0 + base, val);
}

static __inline uint32_t cnt_get_shiftin_update(uint32_t base)
{
    return RD_WORD(COUNTER_ALL_APB_REG_SHIFTIN_DATABITS_UPDATED_C0 + base);
}

static __inline uint32_t cnt_get_shiftin_data(uint32_t base)
{
    return RD_WORD(COUNTER_ALL_APB_REG_SHIFTIN_DATA_C0 + base);
}
/* shiftout n bits, start from zero*/
static __inline void cnt_set_shiftout_bit_num(uint32_t base, uint32_t n)
{
    WR_WORD(COUNTER_ALL_APB_REG_SHIFTOUT_DATA_CTRL_BITCNTS_C0 + base, n);
}
static __inline void cnt_set_shiftout_data(uint32_t base, uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_SHIFTOUT_DATA_C0 + base, val);
}
static __inline void cnt_set_shiftout_data_valid(uint32_t base, uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_SHIFTOUT_DATA_VALID_C0 + base, val);
}

static __inline uint32_t cnt_get_shadow_reg(uint32_t base)
{
    return RD_WORD(COUNTER_ALL_APB_REG_SHADOW_REG_C0 + base);
}
static __inline uint32_t cnt_get_capture_reg_a0(uint32_t base)
{
    return RD_WORD(COUNTER_ALL_APB_REG_CAPTURE_REG_A0_C0 + base);
}
static __inline uint32_t cnt_get_capture_reg_a1(uint32_t base)
{
    return RD_WORD(COUNTER_ALL_APB_REG_CAPTURE_REG_A1_C0 + base);
}
static __inline uint32_t cnt_get_capture_reg_a2(uint32_t base)
{
    return RD_WORD(COUNTER_ALL_APB_REG_CAPTURE_REG_A2_C0 + base);
}
static __inline uint32_t cnt_get_capture_status(uint32_t base)
{
    return RD_WORD(COUNTER_ALL_APB_REG_CAPTURE_REG_STATUS_C0 + base);
}
static __inline void cnt_set_capture_overflow(uint32_t base, uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_CAPTURE_REG_OVERFLOW_CTRL_C0 + base, val);
}
static __inline uint32_t cnt_get_din_mux()
{
    return RD_WORD(COUNTER_ALL_APB_REG_DIN_MUX_SEL);
}
static __inline uint32_t cnt_get_dout_mux()
{
    return RD_WORD(COUNTER_ALL_APB_REG_DOUT_MUX_SEL);
}
static __inline void cnt_set_din_mux(uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_DIN_MUX_SEL, val);
}
static __inline void cnt_set_dout_mux(uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_DOUT_MUX_SEL, val);
}
static __inline void cnt_set_dout_enable_ctrl(uint32_t base, uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_DOUT_ENABLE_CTRL + base, val);
}

static __inline void cnt_enable(uint32_t base)
{
    uint32_t reg = RD_WORD(COUNTER_ALL_APB_REG_ENABLE_C0 + base);

    reg |= CNT_ENABLE;
    WR_WORD(COUNTER_ALL_APB_REG_ENABLE_C0 + base, reg);
}
static __inline void cnt_disable(uint32_t base)
{
    uint32_t reg = RD_WORD(COUNTER_ALL_APB_REG_ENABLE_C0 + base);
    reg &= ~CNT_ENABLE;
    WR_WORD(COUNTER_ALL_APB_REG_ENABLE_C0 + base, reg);
}
static __inline void cnt_trigger_start(uint32_t base)
{
    unsigned int reg = RD_WORD(COUNTER_ALL_APB_REG_SINGLE_START_TRIGGER_C0 + base);
    WR_WORD(COUNTER_ALL_APB_REG_SINGLE_START_TRIGGER_C0 + base, ~reg);
}
static __inline void cnt_trigger_stop(uint32_t base)
{
    unsigned int reg = RD_WORD(COUNTER_ALL_APB_REG_SINGLE_STOP_TRIGGER_C0 + base);
    WR_WORD(COUNTER_ALL_APB_REG_SINGLE_STOP_TRIGGER_C0 + base, ~reg);
}
static __inline void cnt_set_snap_ctrl(uint32_t base, uint32_t mask)
{
    uint32_t snap = RD_WORD(COUNTER_ALL_APB_REG_CTRL_SNAP_C0 + base);
    FLIP_BIT(snap, mask);
    WR_WORD(COUNTER_ALL_APB_REG_CTRL_SNAP_C0 + base, snap);
}
static __inline void cnt_reset(int id)
{
    uint32_t reg;
    reg = RD_WORD(GLOBAL_REG_RESET_CTRL_4);
    uint32_t mask = 0x1UL << (4 + id);
    reg &= ~mask;
    WR_WORD(GLOBAL_REG_RESET_CTRL_4, reg);

    /* need 2 nop at least. */
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();

    WR_WORD(GLOBAL_REG_RESET_CTRL_4, reg | mask);
}
static __inline uint32_t cnt_snap_status(uint32_t base)
{
    return RD_WORD(COUNTER_ALL_APB_REG_SNAP_STATUS_C0 + base);
}
static __inline uint32_t cnt_intr_status(void)
{
    return RD_WORD(COUNTER_ALL_APB_REG_INTR_STATUS);
}
static __inline uint32_t cnt_intr_mask_status(void)
{
    return RD_WORD(COUNTER_ALL_APB_REG_INTR_MASK_STATUS);
}
static __inline void cnt_intr_clear(uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_INTR_CLR, val);
}
static __inline void cnt_intr_set(uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_INTR_SET, val);
}
static __inline void cnt_intr_mask_set(uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_INTR_MASK_SET, val);
}
static __inline void cnt_intr_mask_clear(uint32_t val)
{
    WR_WORD(COUNTER_ALL_APB_REG_INTR_MASK_CLR, val);
}

static __inline void cnt_intr_sw_reset()
{
    WR_WORD(COUNTER_ALL_APB_REG_INTR_SRESET, 1);
    WR_WORD(COUNTER_ALL_APB_REG_INTR_SRESET, 0);
}
/**
 * @brief Open counter device
 * @param[in] id    Counter ID
 * @param[in] clk   When use XO, clk can be 32000000, 16000000, 8000000. When use RC, clk can be 16000000, 8000000, 4000000.
 *			      If clk is 0, counter clock is set to default value. It is 32MHz in XO mode, 16MHZ in RC mode
 * @return  Counter device struct, NULL if failed
 * */
cnt_dev_t* hal_cnt_open(int id, uint32_t clk);

/**
 * @brief Close counter device
 * @param[in] dev    Counter device struct
 * */
void hal_cnt_close(cnt_dev_t* dev);

/**
 * @brief Synchronize status registers manually. Will block until register finish update
 * @param[in] dev    Counter device struct
 * @param[in] mask  Register mask
 * @return @see enum cnt_error for return code. 
 * */
int hal_cnt_sync(cnt_dev_t* dev, uint32_t mask);

/**
 * @brief Set interrupt mask
 * @param[in] dev    Counter device struct
 * @return @see enum cnt_error for return code. 
 * */
int hal_cnt_intr_mask(cnt_dev_t* dev);

/**
 * @brief Set interrupt unmask
 * @param[in] dev    Counter device struct
 * @return @see enum cnt_error for return code. 
 * */
int hal_cnt_intr_unmask(cnt_dev_t* dev);

/**
 * @brief Set pin mux
 * @param[in] pin_id    pin id @see enum cnt_ext_pin.
 * @param[in] en    enable or disable pin
 * @return @see enum cnt_error for return code. 
 * */
int hal_cnt_pin_mux_en(int pin_id, int en);

/**
 * @brief Set din pin mux
 * @param[in] inner_pin     pin id @see enum cnt_ext_pin.
 * @param[in] ext_pin    pin id @see enum cnt_ext_pin.
 * @return @see enum cnt_error for return code. 
 * */
int hal_cnt_internal_din_pinmux(int inner_pin, int ext_pin);

/**
 * @brief Set dout pin mux
 * @param[in] inner_pin     pin id @see enum cnt_ext_pin.
 * @param[in] ext_pin    pin id @see enum cnt_ext_pin.
 * @return @see enum cnt_error for return code. 
 * */
int hal_cnt_internal_dout_pinmux(int inner_pin, int ext_pin);

/**
 * @brief Enable counter
 * @param[in] dev    Counter device struct
 * @return @see enum cnt_error for return code. 
 * */
int hal_cnt_enable(cnt_dev_t* dev);

/**
 * @brief Disable counter
 * @param[in] dev    Counter device struct
 * @return @see enum cnt_error for return code. 
 * */
int hal_cnt_disable(cnt_dev_t* dev);

/**
 * @brief Get counter clock frequency
 * @param[in] dev    Counter device struct
 * @return Counter clock frequency, 0 if failed
 * */
uint32_t hal_cnt_get_clk(cnt_dev_t* dev);

/**
 * @brief Check counter pinmux
 * @param[in] pin_id     pin id @see enum cnt_ext_pin.
 * @return @see enum cnt_error for return code. 
 * */
int hal_cnt_pin_chk(int pin_id);

/**
 * @brief Set ISR handler
 * @param[in] dev    Counter device struct.
 * @param[in] fun   Callback function.
 * @param[in] arg   Callback fucntion arguments.
 * @return @see enum cnt_error for return code. 
 * */
void hal_cnt_set_handler(cnt_dev_t* dev, CNT_ISR_FUN fun, void* arg);
/// @} HAL_COUNTER


#endif
