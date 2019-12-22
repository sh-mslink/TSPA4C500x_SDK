/**
 ****************************************************************************************
 *
 * @file hal_keyboard.h
 *
 * @brief Keyboard driver header file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */
#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <stdint.h>
#include "cmsis_os.h"
#include "hal\hal_power.h"
/**
 * @defgroup HAL_KB Keyboard driver
 * @ingroup HAL
 * @brief HAL KB
 * @{
 * */

enum {
	KB_ERR_OK = 0,
	KB_ERR_INVALID_PARAM = -1,

};
/**@section KB_INVL interval config
 * @brief interval config
 * */
typedef enum
{
    KEYBOARD_HALF_MS = 0, ///< half ms
    KEYBOARD_ONE_MS,    ///< 1 ms
    KEYBOARD_TWO_MS,    ///< 2 ms
    KEYBOARD_FOUR_MS,   ///< 4 ms
} kb_interval_t;

///Keyboard ID
enum
{
    KEYBOARD0_ID = 0,
    KEYBOARD_MAX_ID,
};

///Keyboad device struct
typedef struct
{
    int id; ///< device id
    //uint32_t base;
    osMessageQId msg_id; ///< OS message queue id
    int used; ///< is device in use
    uint32_t long_cnt; ///< long press detect threshold
    //uint32_t key_num; ///< key number
    uint8_t row;
    uint8_t col;
    int enable;
    osMutexId mutex; ///< mutex
#if CFG_PM_EN
    osTimerId tim_id;
    int cancel_tim;
	int power_state;
	struct pm_module pmd;
    uint32_t misc_reg;
    uint32_t col_row_reg;
    uint32_t ms_cnt_reg;
#endif


} kb_dev_t;

//#define APB_CLK 32000000 //todo need get it from reg?
#define KB_MAX_KEY_NUM 40 ///< Only support 40
#define KB_MAX_ROW_NUM 6
#define KB_MAX_COL_NUM 10


#define KB_MSG_BASE 0x00010000UL ///<Message base
#define KB_MSG_PRESS (0x1UL) ///< Key press message
#define KB_MSG_RELEASE (0x2UL) ///< Key release message
#define KB_MSG_LONG_PRESS (0x4UL) ///< Long press message


#define KB_ENABLE 0x00000001UL


static __inline void kb_set_half_ms_cnt(uint32_t val)
{
    WR_WORD(KEYBOARD_REG_HALF_MS_CNT, val);
}
static __inline void kb_intr_mask_clear(uint32_t val)
{
    WR_WORD(KEYBOARD_REG_INTR_MASK_CLEAR, val);
}
static __inline void kb_intr_clear(uint32_t val)
{
    WR_WORD(KEYBOARD_REG_INTR_CLEAR, val);
}
static __inline void kb_set_num_col_row(uint32_t val)
{
    WR_WORD(KEYBOARD_REG_NUM_COL_ROW, val);
}
#if 0
static __inline void kb_set_misc_ctrl(uint32_t val)
{
    WR_WORD(KEYBOARD_REG_MISC_CTRL, val);
}
#endif
/**
 * @brief Set scan frequence
 * @param[in] interval   Scan interval @ref KB_INVL. Default is 1ms.
 * */  
static __inline void kb_set_scan_freq(uint32_t val)
{
    uint32_t reg = RD_WORD(KEYBOARD_REG_MISC_CTRL);
    reg &= ~KEYBOARD_REG_MISC_CTRL_CTL_SCAN_FREQ;
    reg |= (val & KEYBOARD_REG_MISC_CTRL_CTL_SCAN_FREQ_MASK) << 4;

    WR_WORD(KEYBOARD_REG_MISC_CTRL, reg);

}
/**
 * @brief Set press debounce time
 * @param[in] ms   Key press debounce filter length, 0ms to 63ms.Default value is 20ms.
 * */ 
static __inline void kb_set_press_deb(uint32_t val)
{
    uint32_t reg = RD_WORD(KEYBOARD_REG_MISC_CTRL);
    reg &= ~KEYBOARD_REG_MISC_CTRL_CTL_PRESS_DEB_LMT;
    reg |= (val & KEYBOARD_REG_MISC_CTRL_CTL_PRESS_DEB_LMT_MASK) << 8;
    WR_WORD(KEYBOARD_REG_MISC_CTRL, reg);

}
/**
 * @brief Set release debounce time
 * @param[in] ms   Key release debounce filter length, 0ms to 63ms.Default value is 20ms.
 * */  
static __inline void kb_set_release_deb(uint32_t val)
{
    uint32_t reg = RD_WORD(KEYBOARD_REG_MISC_CTRL);
    reg &= ~KEYBOARD_REG_MISC_CTRL_CTL_RELEASE_DEB_LMT;
    reg |= (val & KEYBOARD_REG_MISC_CTRL_CTL_RELEASE_DEB_LMT_MASK) << 16;
    WR_WORD(KEYBOARD_REG_MISC_CTRL, reg);

}
/**
 * @brief Set sample threshold counter
 * @param[in] cnt   Sample threshold counter. If sample >= this values, the sample value is available. 
 * */ 
static __inline void kb_set_sample_th(uint32_t val)
{
    uint32_t reg = RD_WORD(KEYBOARD_REG_MISC_CTRL);
    reg &= ~KEYBOARD_REG_MISC_CTRL_CTL_SAMPLE_VALID_THRESHOLD;
    reg |= (val & KEYBOARD_REG_MISC_CTRL_CTL_SAMPLE_VALID_THRESHOLD_MASK) << 24;
    WR_WORD(KEYBOARD_REG_MISC_CTRL, reg);
}

static __inline void  kb_enable()
{
    uint32_t reg = RD_WORD(KEYBOARD_REG_MISC_CTRL);
    reg |= KB_ENABLE;
    WR_WORD(KEYBOARD_REG_MISC_CTRL, reg);
}
static __inline void  kb_disable()
{
    uint32_t reg = RD_WORD(KEYBOARD_REG_MISC_CTRL);
    reg &= ~KB_ENABLE;
    WR_WORD(KEYBOARD_REG_MISC_CTRL, reg);
}
static __inline void kb_reset()
{
    uint32_t val = RD_WORD(GLOBAL_REG_RESET_CTRL_1);
    
    WR_WORD(GLOBAL_REG_RESET_CTRL_1, val & (~0x2)); //GLOBAL_REG_RESET_CTRL_1_CTL_RESET_1_D0_CPU_KEYBOARD_RSTN_REG
    osDelay(10);
    WR_WORD(GLOBAL_REG_RESET_CTRL_1, val | 0x2);
}
/**
 * @brief Set row num and col num
 * @param[in] dev   Keyboard device struct
 * @param[in] row   Row number
 * @param[in] col   Col number
 * @return 0 if successful, otherwise failed
 * */     
int hal_kb_set_row_col(kb_dev_t *dev, uint32_t row, uint32_t col);


/**
 * @brief Enable keyboad module
 * @param[in] dev   Keyboard device struct
 * @param[in] enable   1 is enable, 0 is disable. 
 * @return 0 if successful, otherwise failed
 * */  
int hal_kb_enable(kb_dev_t *dev);

/**
 * @brief Set long press threshold count
 * @param[in] dev   Keyboard device struct
 * @param[in] cnt   If sample >= this values, long press message will be send. 
 * @return 0 if successful, otherwise failed
 * */
int hal_kb_set_longpress_cnt(kb_dev_t *dev, uint32_t cnt);


/**
 * @brief Open keyboard device
 * @param[in] row   Row number
 * @param[in] col   Col number 
 * @param[in] msgid OS message queue id
 * @return kb device struce, NULL if failed
 * */
kb_dev_t *hal_kb_open(uint8_t row, uint8_t col, osMessageQId msgid);

/**
 * @brief Close keyboard device
 * @param[in] dev   Keyboard device struct
 * */
void hal_kb_close(kb_dev_t *dev);

/**
 * @brief Get key event
 * @param[in] p     Message data.
 * @return Key event @see KB_MSG_PRESS KB_MSG_RELEASE KB_MSG_LONG_PRESS
 * */
uint32_t hal_kb_get_key_evt(uint32_t p);

/**
 * @brief Get key code
 * @param[in] p     Message data.
 * @return Key code.
 * */
uint32_t hal_kb_get_key_code(uint32_t p);
/// @} HAL_KB

#endif
