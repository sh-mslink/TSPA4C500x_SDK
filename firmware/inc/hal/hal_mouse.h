/**
 ****************************************************************************************
 *
 * @file hal_mouse.h
 *
 * @brief Mouse driver header file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */
#ifndef HAL_MOUSE_H
#define HAL_MOUSE_H
#include <stdint.h>
#include "cmsis_os.h"
#include ".\hal\hal_power.h"
/**
 * @defgroup HAL_MOUSE Mouse driver
 * @ingroup HAL
 * @brief HAL MOUSE
 * @{
 * */

///Mouse device ID
typedef enum {
    MOUSE0_ID = 0, ///< ID 0
    MOUSE1_ID, ///< ID 1
    MOUSE2_ID, ///< ID 2
    MOUSE_MAX_ID, ///< Max ID
} mouse_id_t;
enum mouse_error {
	MOUSE_ERR_OK = 0,
	MOUSE_ERR_INVALID_PARAM = -1,
    MOUSE_ERR_PINMUX = -2,
};

///Mouse dev struct  
typedef struct
{
    int id; ///< id
    uint32_t base; ///< reg base address
    osMessageQId msg_id; ///< os message queue id
    osMutexId mutex; ///< mutex
    uint32_t mu[4];
    uint32_t a_pin;
    uint32_t b_pin;
    uint32_t idx_pin;
    uint32_t led_pin;
    int used; ///< is device in use
#if CFG_PM_EN
	int power_state;
	struct pm_module pmd;
    uint32_t misc_ctrl;
    uint32_t intv_setting;
    uint32_t pin_assignment;
    uint32_t report_intv;
    uint32_t cnt_lmt;
    uint32_t idx_ctrl;
    uint32_t led_intv;
    uint16_t curr_cnt;
    int cancel_tim;
    //uint16_t curr_idx_cnt;
#endif

} mouse_dev_t;


//#define APB_CLK 32000000

///irq status
#define MOUSE_IRQ_TRGGER 0x80UL ///< Detect move
#define MOUSE_IRQ_COUNTER_READY 0x1UL ///< Data ready

///msg
#define MOUSE_MSG_BASE 0x00040000UL ///<Message base



static __inline uint32_t mouse_intr_status(void)
{
    return RD_WORD(QUADDEC_REG_INTERRUPT_STATUS);
}
static __inline uint32_t mouse_intr_mask_status(void)
{
    return RD_WORD(QUADDEC_REG_INTERRUPT_MASK_STATUS);
}

static __inline void mouse_intr_clear(uint32_t val)
{
    WR_WORD(QUADDEC_REG_INTERRUPT_CLEAR, val);
}
static __inline void mouse_intr_set(uint32_t val)
{
    WR_WORD(QUADDEC_REG_INTERRUPT_SET, val);
}
static __inline void mouse_intr_mask_clear(uint32_t val)
{
    WR_WORD(QUADDEC_REG_INTERRUPT_MASK_CLEAR, val);
}
static __inline void mouse_intr_mask_set(uint32_t val)
{
    WR_WORD(QUADDEC_REG_INTERRUPT_MASK_SET, val);
}



/*
 *        intval = led<<16 | smaple. 
 *              sample: actual sample interval = (register value + 64) * 2 us
 *              led:     actual early start interval = register value * 1 us.
 *              Register value 0 is invalid. If this field has an effectively longer time than sample_interval field, the LED will always be asserted.
 * */
static __inline void mouse_sample_interval(uint16_t intv)
{
    uint32_t reg = RD_WORD(QUADDEC_REG_INTERVAL_SETTING);
    reg &= ~QUADDEC_REG_INTERVAL_SETTING_CTL_SAMPLE_INTERVAL_M1;
    reg |= intv;
    WR_WORD(QUADDEC_REG_INTERVAL_SETTING,reg);
}
static __inline void mouse_led_interval(uint16_t intv)
{
    uint32_t reg = RD_WORD(QUADDEC_REG_INTERVAL_SETTING);
    reg &= ~QUADDEC_REG_INTERVAL_SETTING_CTL_LED_INTERVAL;
    reg |= intv<<16;
    WR_WORD(QUADDEC_REG_INTERVAL_SETTING,reg);
}
//How many samples the counter value in the register will be updated (and an counter ready interrupt triggered). 
//If value is 0, the counter will be updated every sample. Max value is 0xff
static __inline void mouse_set_report_interval(uint32_t intv)
{
    WR_WORD(QUADDEC_REG_REPORT_INTERVAL,intv);
}

//Actual led on = register value * 1 us. 
static __inline void mouse_set_led_setting(uint32_t base, uint32_t intv)
{
    WR_WORD(QUADDEC_REG_INTERVAL_LED_SETTING_M0 + base,intv);
}

static __inline void mouse_set_counter_lmt(uint32_t lmt)
{

    WR_WORD(QUADDEC_REG_COUNTER_LMT,lmt);
}

static __inline void mouse_set_counter_init(uint32_t init)
{
    WR_WORD(QUADDEC_REG_COUNTER_INIT,init);
}

static __inline void mouse_set_counter_clear(uint32_t val)
{
    WR_WORD(QUADDEC_REG_COUNTER_CLEAR,val);
}

//current sample counter value
static __inline uint32_t mouse_get_sample(uint32_t base)
{
    return RD_WORD(QUADDEC_REG_SAMPLE_COUNTER0 + base)&0xff;
}

//sample counter value from last report time 
static __inline uint32_t mouse_get_report(uint32_t base)
{
    return (RD_WORD(QUADDEC_REG_SAMPLE_COUNTER0 + base)>>16)&0xff;
}

static __inline uint32_t mouse_get_db_counter(uint32_t base)
{
    return RD_WORD(QUADDEC_REG_DB_COUNTER_AND_CURRENT_INPUT0 + base);
}

static __inline void mouse_set_index_ctrl(uint32_t val)
{
    WR_WORD(QUADDEC_REG_INDEX_CTRL, val);
} 

static __inline uint32_t mouse_get_index_counter(uint32_t base)
{
    return RD_WORD(QUADDEC_REG_INDEX_COUNTER0 + base);
}
#if 0
static __inline uint32_t mouse_get_misc_ctrl(void)
{
    return RD_WORD(QUADDEC_REG_MISC_CTRL);
}

static __inline void mouse_set_misc_ctrl(uint32_t misc)
{
    WR_WORD(QUADDEC_REG_MISC_CTRL, misc);
}
#endif
static __inline void mouse_set_pin_a(uint32_t base, uint32_t a)
{
    uint32_t reg = RD_WORD(QUADDEC_REG_INPUT_PIN_ASSIGNMENT0 + base);
    reg &= ~QUADDEC_REG_INPUT_PIN_ASSIGNMENT0_CTL_PIN_A_SEL0;
    reg |= a&0x3;
    WR_WORD(QUADDEC_REG_INPUT_PIN_ASSIGNMENT0 + base, reg);
}
static __inline void mouse_set_pin_b(uint32_t base, uint32_t b)
{
    uint32_t reg = RD_WORD(QUADDEC_REG_INPUT_PIN_ASSIGNMENT0 + base);
    reg &= ~QUADDEC_REG_INPUT_PIN_ASSIGNMENT0_CTL_PIN_B_SEL0;
    reg |= (b&0x3)<<4;
    WR_WORD(QUADDEC_REG_INPUT_PIN_ASSIGNMENT0 + base, reg);
}
static __inline void mouse_set_pin_idx(uint32_t base, uint32_t idx)
{
    uint32_t reg = RD_WORD(QUADDEC_REG_INPUT_PIN_ASSIGNMENT0 + base);
    reg &= ~QUADDEC_REG_INPUT_PIN_ASSIGNMENT0_CTL_PIN_IDX_SEL0;
    reg |= (idx&0x3)<<8;
    WR_WORD(QUADDEC_REG_INPUT_PIN_ASSIGNMENT0 + base, reg);
}



static __inline void mouse_enable(int id)
{
    uint32_t reg = RD_WORD(QUADDEC_REG_MISC_CTRL);
    id &= 0x7;
    reg |= 0x1UL<<id;
    WR_WORD(QUADDEC_REG_MISC_CTRL, reg);
    
}
static __inline void mouse_disable(int id)
{
    uint32_t reg = RD_WORD(QUADDEC_REG_MISC_CTRL);
    id &= 0x7;
    uint32_t mask = 0x1UL<<id;
    reg &= ~mask;
    WR_WORD(QUADDEC_REG_MISC_CTRL, reg);
    
}
static __inline void mouse_led_enable(int id)
{
    uint32_t reg = RD_WORD(QUADDEC_REG_MISC_CTRL);
    id &= 0x7;
    reg |= 0x1UL<<(id+16);
    WR_WORD(QUADDEC_REG_MISC_CTRL, reg);
    
}
static __inline void mouse_led_disable(int id)
{
    uint32_t reg = RD_WORD(QUADDEC_REG_MISC_CTRL);
    id &= 0x7;
    uint32_t mask = 0x1UL<<(id+16);
    reg &= ~mask;
    WR_WORD(QUADDEC_REG_MISC_CTRL, reg);
    
}
static __inline void mouse_idx_enable(int id)
{
    uint32_t reg = RD_WORD(QUADDEC_REG_MISC_CTRL);
    id &= 0x7;
    reg |= 0x1UL<<(id+4);
    WR_WORD(QUADDEC_REG_MISC_CTRL, reg);
    
}
static __inline void mouse_idx_disable(int id)
{
    uint32_t reg = RD_WORD(QUADDEC_REG_MISC_CTRL);
    id &= 0x7;
    uint32_t mask = 0x1UL<<(id+4);
    reg &= ~mask;
    WR_WORD(QUADDEC_REG_MISC_CTRL, reg);
    
}
static __inline void mouse_debounce_enable(int id)
{
    uint32_t reg = RD_WORD(QUADDEC_REG_MISC_CTRL);
    id &= 0x7;
    reg |= 0x1UL<<(id+12);
    WR_WORD(QUADDEC_REG_MISC_CTRL, reg);
    
}
static __inline void mouse_debounce_disable(int id)
{
    uint32_t reg = RD_WORD(QUADDEC_REG_MISC_CTRL);
    id &= 0x7;
    uint32_t mask = 0x1UL<<(id+12);
    reg &= ~mask;
    WR_WORD(QUADDEC_REG_MISC_CTRL, reg);
    
}
static __inline void mouse_clk_num_in_us(uint8_t num)
{
    uint32_t reg = RD_WORD(QUADDEC_REG_MISC_CTRL);
    reg &= ~QUADDEC_REG_MISC_CTRL_CTL_NUM_CLK_IN_US_M1;
    reg |= (num&0xf)<<24;
    WR_WORD(QUADDEC_REG_MISC_CTRL, reg);
    
}
/**
 * @brief Open mouse device
 * @param[in] id    Device id
 * @param[in] msg   OS message queue id
 * @return Mouse device struct, NULL if failed
 * */
mouse_dev_t* hal_mouse_open(int id, osMessageQId msg);

/**
 * @brief Set mouse pin
 * @param[in] dev    Device struct
 * @param[in] a     Pin a
 * @param[in] b     Pin b
 * @param[in] idx     Pin index
 * @return  @see enum mouse_error for return code.
 * */
int hal_mouse_set_pin(mouse_dev_t* dev, uint32_t a, uint32_t b, uint32_t idx);

/**
 * @brief Enable device
 * @param[in] dev    Device struct
 * @return  @see enum mouse_error for return code.
 * */
int hal_mouse_enable(mouse_dev_t* dev);
/**
 * @brief Disable device
 * @param[in] dev    Device struct
 * @return  @see enum mouse_error for return code.
 * */
int hal_mouse_disable(mouse_dev_t* dev);

/**
 * @brief Close device
 * @param[in] dev    Device struct
 * */
void hal_mouse_close(mouse_dev_t* dev);

/**
 * @brief Get mouse move count
 * @param[in] p    Message data
 * @return mouse move count
 * */
uint32_t hal_mouse_get_cnt(uint32_t p);

/// @} HAL_MOUSE
#endif
