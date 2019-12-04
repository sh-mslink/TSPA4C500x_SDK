#include "in_config.h"
/**
 ****************************************************************************************
 *
 * @file hal_ir.c
 *
 * @brief IR driver implementation file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
#if CFG_COUNTER_EN
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "in_arm.h"
#include "in_mmap.h"
#include "in_irq.h"
#include "in_debug.h"
#include ".\hal\hal_clk.h"
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_counter.h"
#include ".\hal\hal_ir.h"

typedef struct ir_dev_buf{
    uint32_t *out_buf;
    int out_size;
    int out_pos;
    uint32_t *out_repeat_buf;
    int out_repeat_size;
    int out_repeat_pos;
    uint32_t *in_buf;
    int in_size;
    int in_pos;
    uint32_t start_cnt;
    uint32_t freq_start_cnt;
} ir_buf_t;

static void ir0_handler(uint32_t status, void *arg);
static void ir_handler(ir_dev_t *dev, uint32_t status);
static int ir_send_internal(ir_dev_t *dev, uint32_t *buf, int size, uint32_t *repeat_buf, int repeat_size, uint32_t millisec);
static void ir_get_remain_value(ir_dev_t *dev);
static int ir_parse_freq_data(ir_dev_t *dev);
static int ir_parse_data(ir_dev_t *dev);

static ir_dev_t ir_dev[IR_MAX_ID] = {
    {
        .id = IR0_ID,
        .cnt_dev = NULL,
        .used = 0,
        //.clk = 38000,
        .rising_cnt = 200,
        .failing_cnt = 220,
        .cycle_offset = 600,
        .handler = ir0_handler,
        .mode = IR_IDLE,
        //.msg_id = NULL,
    },
};
static ir_buf_t ir_buf[IR_MAX_ID];
osSemaphoreDef(ir0_semaphore);
osMutexDef(ir0_mutex);
//#define IR_CLK 32000

#define IR_IDLE 0x1
#define IR_SEND 0x2
#define IR_RECV 0x4
#define IR_FREQ 0x8


static void ir0_handler(uint32_t status, void *arg)
{
    ir_handler(&ir_dev[0], status);
}

static void ir_handler(ir_dev_t *dev, uint32_t status)
{
    cnt_dev_t *cnt_dev = dev->cnt_dev;
    ir_buf_t * dev_buf = &(ir_buf[dev->id]);
    if (status & CNT_OVERFLOW)
    {
        //PRINTD(DBG_TRACE, "counter overflow \r\n");
    }
    if (dev->mode == IR_RECV)
    {
    
        if (status & CNT_A_UPDATE)
        {
            if (dev_buf->in_pos == 0)
            {
                dev_buf->start_cnt = cnt_get_shadow_reg(cnt_dev->base);
            }
            if ((dev_buf->in_pos + 2 < dev_buf->in_size) && dev_buf->in_buf)
            {
                dev_buf->in_buf[dev_buf->in_pos++] = cnt_get_capture_reg_a0(cnt_dev->base);
                dev_buf->in_buf[dev_buf->in_pos++] = cnt_get_capture_reg_a1(cnt_dev->base);
                dev_buf->in_buf[dev_buf->in_pos++] = cnt_get_capture_reg_a2(cnt_dev->base);
                //PRINTD(DBG_TRACE, " recv\r\n");
            }
            else
            {
                ir_get_remain_value(dev);
                cnt_disable(cnt_dev->base);
                dev->mode = IR_IDLE;
                osSemaphoreRelease(dev->semaphore);
                //PRINTD(DBG_TRACE, "stop recv\r\n");
                //clear?
            }
        }
    }
    else if (dev->mode == IR_RECV_FREQ)
    {
        if (status & CNT_A_UPDATE)
        {
            if (dev_buf->in_pos == 0)
            {
                dev_buf->freq_start_cnt = cnt_get_shadow_reg(cnt_dev->base);
            }
            if (dev_buf->in_pos + 2 < IR_FREQ_BUF_LEN)
            {
                dev_buf->in_buf[dev_buf->in_pos++] = cnt_get_capture_reg_a0(cnt_dev->base);
                dev_buf->in_buf[dev_buf->in_pos++] = cnt_get_capture_reg_a1(cnt_dev->base);
                dev_buf->in_buf[dev_buf->in_pos++] = cnt_get_capture_reg_a2(cnt_dev->base);
                //PRINTD(DBG_TRACE, " freq recv\r\n");
            }
            
            if (dev_buf->in_pos >= IR_FREQ_BUF_LEN - 2)
            {
                cnt_trigger_stop(cnt_dev->base);
                cnt_set_src_edge(cnt_dev->base, (CNT_EXT_DIN_A | CNT_BOTH_EDGE) << CNT_DIN0_SHIFT);
                
                dev->rising_cnt = dev_buf->in_buf[IR_FREQ_BUF_LEN - 2] - dev_buf->in_buf[IR_FREQ_BUF_LEN - 3];
                dev->failing_cnt = dev_buf->in_buf[IR_FREQ_BUF_LEN - 1] - dev_buf->in_buf[IR_FREQ_BUF_LEN - 2];
                if (IR_FREQ_BUF_LEN % 2 != 0)
                {
                    uint32_t tmp = dev->rising_cnt;
                    dev->rising_cnt = dev->failing_cnt;
                    dev->failing_cnt = tmp;
                }
                //PRINTD(DBG_TRACE, " freq recv 0x%x\r\n", in_buf[5]);
                cnt_set_one_cycle_value(cnt_dev->base, dev->rising_cnt + dev->failing_cnt + dev->cycle_offset); //need 2 clk to make it stable
                cnt_set_in_bypass(cnt_dev->base, CNT_IN_BYPASS_B);
                dev->mode = IR_RECV;//get frequecy, go to IR_RECV 
                dev_buf->in_pos = 0;
                //start_cnt = 0;
                //cnt_enable(cnt_dev->base->base);
                cnt_trigger_start(cnt_dev->base);
                //cnt_set_src_edge(cnt_dev->base, 0);
                //PRINTD(DBG_TRACE, "stop freq recv\r\n");
                
                //clear?
            }
        }
    }
    else if (dev->mode == IR_SEND)
    {
        //uint32_t out_offset = cnt_get_reg_offset(out_cnt);
        if (status & CNT_WAVEFORM_STOP)
        {
            cnt_trigger_stop(cnt_dev->base);
            //PRINTD(DBG_TRACE, "send intr\r\n");
            if ((dev_buf->out_pos < dev_buf->out_size - 1) && dev_buf->out_buf)
            { //discard last bit
                cnt_set_target_a(cnt_dev->base, dev_buf->out_buf[dev_buf->out_pos], 10, 
                        dev_buf->out_buf[dev_buf->out_pos] + dev_buf->out_buf[dev_buf->out_pos + 1]);
                
                dev_buf->out_pos += 2;
                //PRINTD(DBG_TRACE, "send intr\r\n");
                cnt_trigger_start(cnt_dev->base);
            }
            else if ((dev_buf->out_repeat_pos < dev_buf->out_repeat_size - 1) && dev_buf->out_repeat_buf) {
                cnt_set_target_a(cnt_dev->base, dev_buf->out_repeat_buf[dev_buf->out_repeat_pos], 10, 
                        dev_buf->out_repeat_buf[dev_buf->out_repeat_pos] + dev_buf->out_repeat_buf[dev_buf->out_repeat_pos + 1]);
                
                dev_buf->out_repeat_pos += 2;
                if (dev_buf->out_repeat_pos >= dev_buf->out_repeat_size - 1)
                    dev_buf->out_repeat_pos = 0;
                //PRINTD(DBG_TRACE, "send intr\r\n");
                cnt_trigger_start(cnt_dev->base);
            } else {
                dev->mode = IR_IDLE;
                dev_buf->out_buf = NULL;
                dev_buf->out_size = 0;
                dev_buf->out_repeat_buf = NULL;
                dev_buf->out_repeat_size = 0;
                
                cnt_disable(cnt_dev->base);
                
                osSemaphoreRelease(dev->semaphore);
                //PRINTD(DBG_TRACE, "stop send\r\n");
            }
        }
    }
}

#if CFG_PM_EN
static int ir_pm_state(void *arg, uint32_t *sleep_duration)
{
    ir_dev_t *pd = (ir_dev_t *)arg;
    
    *sleep_duration = PM_MAX_SLEEP_TIME;
    return pd->power_state;
}

static void ir_pm_down(void *arg, uint32_t sleep_duration)
{
    ir_dev_t *pd = (ir_dev_t *)arg;
    //PRINTD(DBG_TRACE, "%s \n", __func__);
    //hal_gpio_aon_latch(2, pd->rx_pin + 1, 1);// CNT_PIN0 is gpio2_1
    hal_gpio_aon_latch(2,  pd->tx_pin + 1, 1);
    
    return;
}

static void ir_pm_up(void *arg)
{
    ir_dev_t *pd = (ir_dev_t *)arg;
    //PRINTD(DBG_TRACE, "%s \n", __func__);
    // Recover pin mux
    hal_cnt_pin_mux_en(pd->tx_pin, 1);
    //hal_cnt_pin_mux_en(pd->rx_pin, 1);
    hal_gpio_aon_latch(2,  pd->tx_pin + 1, 0);
    hal_cnt_internal_din_pinmux(pd->cnt_dev->id*2, pd->rx_pin);//counter A pin number is cnt_id*2
    hal_cnt_internal_dout_pinmux(pd->cnt_dev->id*2, pd->tx_pin);
}
#endif	// CFG_PM_EN

ir_dev_t *hal_ir_open(int id, int cnt_id, int rx_pin, int tx_pin)
{
    if (id >= IR_MAX_ID || id < 0 || ir_dev[id].used)
        return NULL;
    ir_dev_t *pd = &ir_dev[id];
    pd->used = 1;
    if (tx_pin > 0) {
        if (hal_cnt_pin_chk(tx_pin) != CNT_ERR_OK)
            goto fail;
    }
    if (rx_pin > 0) {
        if (hal_cnt_pin_chk(rx_pin) != CNT_ERR_OK)
            goto fail;
    }
    
    if (tx_pin > 0)
        hal_cnt_pin_mux_en(tx_pin, 1);
    if (rx_pin > 0)
        hal_cnt_pin_mux_en(rx_pin, 1);
    
    pd->semaphore = NULL;
    pd->mutex = NULL;
    pd->cnt_dev = hal_cnt_open(cnt_id, 0);
    if (pd->cnt_dev == NULL)
        goto fail;
    
    if (tx_pin > 0)
        pd->tx_pin = tx_pin;
    if (rx_pin > 0)
        pd->rx_pin = rx_pin;
    
    pd->semaphore = osSemaphoreCreate(osSemaphore(ir0_semaphore), 0);
    if (!pd->semaphore)
        goto fail;
    pd->mutex = osMutexCreate(osMutex(ir0_mutex));
    if (!pd->mutex)
        goto fail;
    
    //pd->cnt_dev = cnt_dev;
    pd->mode = IR_IDLE;
    //pd->msg_id = msg_id;
    hal_cnt_set_handler(pd->cnt_dev, pd->handler, pd);
    
    memset(&ir_buf[id], 0, sizeof(ir_buf[id]));
    
    if (tx_pin > 0)
        hal_cnt_internal_dout_pinmux(cnt_id * 2, tx_pin);
    if (rx_pin > 0)
        hal_cnt_internal_din_pinmux(cnt_id * 2, rx_pin);//counter A pin number is cnt_id * 2
    
    /// PM
#if CFG_PM_EN
    pd->power_state = PM_DEEP_SLEEP;
    pd->pmd.arg = (void *)pd;
    pd->pmd.power_state = ir_pm_state;
    pd->pmd.power_down = ir_pm_down;
    pd->pmd.power_up = ir_pm_up;
    hal_pm_reg_mod(&pd->pmd);
#endif
    return pd;
fail:
    if (pd->cnt_dev) {
        hal_cnt_close(pd->cnt_dev);
        pd->cnt_dev = NULL;
    }
    if (pd->mutex) {
        osMutexDelete(pd->mutex);
        pd->mutex = NULL;
    }
    if (pd->semaphore) {
        osSemaphoreDelete(pd->semaphore);
        pd->semaphore = NULL;
    }
    pd->used = 0;
    return NULL; 
}

void hal_ir_close(ir_dev_t *dev)
{
    ir_dev_t *pd = (ir_dev_t *)dev;
    if (!dev)
        return;
    
    osMutexWait(dev->mutex, osWaitForever);
    hal_cnt_close(dev->cnt_dev);
    dev->cnt_dev = NULL;
    dev->mode = IR_IDLE;
    memset(&ir_buf[dev->id], 0, sizeof(ir_buf[dev->id]));
    osMutexRelease(dev->mutex);
    
    osMutexDelete(dev->mutex);
    osSemaphoreDelete(dev->semaphore);
    hal_cnt_pin_mux_en(pd->tx_pin, 0);
    hal_cnt_pin_mux_en(pd->rx_pin, 0);
#if CFG_PM_EN
    hal_pm_unreg_mod(&pd->pmd);
#endif
    pd->mutex = NULL;
    pd->semaphore = NULL;
    dev->used = 0;
    return;
}

int hal_ir_set_clk(ir_dev_t *dev, uint32_t clk)
{
    if (clk == 0)
    {
        return IR_ERR_INVALID_PARAM;
    }
    osMutexWait(dev->mutex, osWaitForever);
    uint32_t cnt = hal_cnt_get_clk(dev->cnt_dev) / clk;
    dev->rising_cnt = cnt / 2;
    dev->failing_cnt = cnt / 2;
    osMutexRelease(dev->mutex);
    return IR_ERR_OK;
}

static int ir_binary_sem_wait(ir_dev_t *dev, uint32_t millisec)
{
    int ret;
    
    /* 
     * Only use semaphore as a binary sem. osSemaphoreRelease will add sem count without check init count.
     * So here we make sure the count is 0 using osSemaphoreWait(0) , then call  osSemaphoreWait(millisec).   
     */
    if (millisec != 0) {
        do {
            ret = osSemaphoreWait(dev->semaphore, 0);
        } while (ret > 0);
    }
    ret = osSemaphoreWait(dev->semaphore, millisec);
    if (ret < 0)
        return IR_ERR_SEM;
    return IR_ERR_OK;
}

int hal_ir_send(ir_dev_t *dev, uint32_t *buf, int size)
{
    osMutexWait(dev->mutex, osWaitForever);
#if CFG_PM_EN
    dev->power_state = PM_SLEEP;
#endif
    NVIC_SetPriority(Counter_IRQn, IRQ_PRI_AboveNormal);
    NVIC_EnableIRQ(Counter_IRQn);
    hal_cnt_intr_unmask(dev->cnt_dev);
    ir_send_internal(dev, buf, size, NULL, 0, osWaitForever);
    
    //NVIC_DisableIRQ(Counter_IRQn);
    //cnt_disable(dev->cnt_dev->base);
    //dev->mode = IR_IDLE;
    cnt_dev_t *cnt_dev = dev->cnt_dev;
    hal_cnt_intr_mask(cnt_dev);
    cnt_disable(cnt_dev->base);
    dev->mode = IR_IDLE;
#if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
#endif
    osMutexRelease(dev->mutex);
        return IR_ERR_OK;
}

int hal_ir_send_repeat(ir_dev_t *dev, uint32_t *buf, int size, uint32_t *repeat_buf, int repeat_size)
{
    int ret;
    osMutexWait(dev->mutex, osWaitForever);
    NVIC_SetPriority(Counter_IRQn, IRQ_PRI_AboveNormal);
    NVIC_EnableIRQ(Counter_IRQn);
    hal_cnt_intr_unmask(dev->cnt_dev);
#if CFG_PM_EN
    dev->power_state = PM_SLEEP;
#endif
    ret = ir_send_internal(dev, buf, size, repeat_buf, repeat_size, osWaitForever);
    //NVIC_DisableIRQ(Counter_IRQn);
    //cnt_disable(dev->cnt_dev->base);
    //dev->mode = IR_IDLE;
    cnt_dev_t *cnt_dev = dev->cnt_dev;
    hal_cnt_intr_mask(cnt_dev);
    cnt_disable(cnt_dev->base);
    dev->mode = IR_IDLE;
    
#if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
#endif
    osMutexRelease(dev->mutex);
    return ret;
}

static int ir_send_internal(ir_dev_t *dev, uint32_t *buf, int size, uint32_t *repeat_buf, int repeat_size, uint32_t millisec)
{
    if ((buf == NULL) && (repeat_buf == NULL))
        return IR_ERR_INVALID_PARAM;
    if (buf && (size < 2))
        return IR_ERR_INVALID_PARAM;
    if (repeat_buf && (repeat_size < 2))
        return IR_ERR_INVALID_PARAM;
    
    //osMutexWait(dev->mutex, osWaitForever);
    dev->mode = IR_SEND;
    ir_buf_t * dev_buf = &(ir_buf[dev->id]);
    
    memset(dev_buf, 0, sizeof(*dev_buf));
    dev_buf->out_buf = buf;
    if (!buf)
        dev_buf->out_size = 0;
    else
        dev_buf->out_size = size/2*2;
    //dev_buf->out_pos = 0;  
    
    dev_buf->out_repeat_buf = repeat_buf;
    if (!repeat_buf)
        dev_buf->out_repeat_size = 0;
    else
        dev_buf->out_repeat_size = repeat_size/2*2;
    //dev_buf->out_repeat_pos = 0;
    
    cnt_dev_t *cnt_dev = dev->cnt_dev;
    cnt_disable(cnt_dev->base);
    
    cnt_set_mode(cnt_dev->base, CNT_WAVAFORM_MODE);
    cnt_set_src_edge(cnt_dev->base, 0);
    
    cnt_set_target_ctrl(cnt_dev->base, CNT_A2_KEEP_VALUE | CNT_A2_STOP_COUNTER | CNT_B2_RESET_VALUE | CNT_B2_RESTART_COUNTER | (0 << CNT_DOUT_A_RESET_VALUE_SHIFT) | (0 << CNT_DOUT_B_RESET_VALUE_SHIFT));
    cnt_set_soft_trigger(cnt_dev->base, 0);
    
    /*A is IR data, B is IR clk*/
    if (buf) {
        cnt_set_target_a(cnt_dev->base, dev_buf->out_buf[dev_buf->out_pos], 1000, 
                dev_buf->out_buf[dev_buf->out_pos] + dev_buf->out_buf[dev_buf->out_pos + 1]); // 0 start
        dev_buf->out_pos += 2;
    } else {
        cnt_set_target_a(cnt_dev->base, dev_buf->out_repeat_buf[dev_buf->out_repeat_pos], 1000, 
                dev_buf->out_repeat_buf[dev_buf->out_repeat_pos] + dev_buf->out_repeat_buf[dev_buf->out_repeat_pos + 1]);
        dev_buf->out_repeat_pos += 2;
    }
    //out_pos += 2;
    
    /* set IR clk */
    cnt_set_target_b(cnt_dev->base, 0, dev->failing_cnt, dev->rising_cnt + dev->failing_cnt);
    
    cnt_set_out_bypass(cnt_dev->base, 0x0); //1 is bypass
    
    cnt_enable(cnt_dev->base);
    cnt_trigger_start(cnt_dev->base);
    //osMutexRelease(dev->mutex);
    //int ret = osSemaphoreWait(dev->semaphore, millisec);
    
    int ret = ir_binary_sem_wait(dev, millisec);
    
    return ret;
}

int hal_ir_stop_send(ir_dev_t *dev)
{
    if (!dev)
        return IR_ERR_INVALID_PARAM;
    osSemaphoreRelease(dev->semaphore);
    
    return IR_ERR_OK;
}

static void ir_recv_stop(ir_dev_t *dev)
{
    cnt_dev_t *cnt_dev = dev->cnt_dev;
    cnt_trigger_stop(cnt_dev->base);
    cnt_set_src_edge(cnt_dev->base, 0);
    cnt_set_snap_ctrl(cnt_dev->base, 0xf);
    osDelay(10);
    ir_get_remain_value(dev);
    hal_cnt_intr_mask(cnt_dev);
    cnt_disable(cnt_dev->base);
} 

int hal_ir_recv(ir_dev_t *dev, uint32_t *buf, int size, uint32_t *out_sz)
{
    if (buf == NULL || size <= 0 || out_sz == NULL)
        return IR_ERR_INVALID_PARAM;
    osMutexWait(dev->mutex, osWaitForever);
#if CFG_PM_EN
    dev->power_state = PM_SLEEP;
#endif
    dev->mode = IR_RECV;
    
    ir_buf_t * dev_buf = &(ir_buf[dev->id]);
    memset(dev_buf, 0, sizeof(*dev_buf));
    dev_buf->in_buf = buf;
    dev_buf->in_size = size;
    
    cnt_dev_t *cnt_dev = dev->cnt_dev;
    memset(buf, 0, size * sizeof(uint32_t));
    cnt_disable(cnt_dev->base);
    
    cnt_set_mode(cnt_dev->base, CNT_CAPTURE_MODE);
    
    cnt_set_src_edge(cnt_dev->base, (CNT_EXT_DIN_A | CNT_BOTH_EDGE) << CNT_START_SIGNLE_SHIFT |
                (CNT_EXT_DIN_A | CNT_BOTH_EDGE) << CNT_DIN0_SHIFT);
    cnt_set_soft_trigger(cnt_dev->base, 0);
    cnt_set_one_cycle_value(cnt_dev->base, dev->rising_cnt + dev->failing_cnt + dev->cycle_offset); //need 2 clk to make it stable
    
    /* enable overflow for capture, otherwise will get old value */
    cnt_set_capture_overflow(cnt_dev->base, 0x3f);//1--> rewrite, 0--> discard. 
    
    /* need use IR moudle */
    cnt_set_in_bypass(cnt_dev->base, CNT_IN_BYPASS_B);  //use A
    cnt_set_input_mux(cnt_dev->base, 0);  
    
    //cnt_enable(timer, 1);
    NVIC_SetPriority(Counter_IRQn, IRQ_PRI_AboveNormal);
    NVIC_EnableIRQ(Counter_IRQn);
    hal_cnt_intr_unmask(cnt_dev);
    cnt_enable(cnt_dev->base);
    
    int ret = ir_binary_sem_wait(dev, osWaitForever);
    
    //NVIC_DisableIRQ(Counter_IRQn);
    //cnt_disable(dev->cnt_dev->base);
    
    ir_recv_stop(dev);
    *out_sz = ir_parse_data(dev);
    dev->mode = IR_IDLE;
    #if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
    #endif
    osMutexRelease(dev->mutex);
    return ret;
}

int hal_ir_recv_freq(ir_dev_t *dev, uint32_t *buf, int size, uint32_t *out_sz)
{
    if (buf == NULL || size <= IR_FREQ_BUF_LEN)
        return IR_ERR_INVALID_PARAM;
    
    osMutexWait(dev->mutex, osWaitForever);
#if CFG_PM_EN
    dev->power_state = PM_SLEEP;
#endif
    
    ir_buf_t * dev_buf = &(ir_buf[dev->id]);
    memset(dev_buf, 0, sizeof(*dev_buf));
    dev->mode = IR_RECV_FREQ;
    
    cnt_dev_t *cnt_dev = dev->cnt_dev;
    memset(buf, 0, size * sizeof(uint32_t));
    dev_buf->in_buf = buf;
    dev_buf->in_size = size;
    cnt_disable(cnt_dev->base);
    
    cnt_set_mode(cnt_dev->base, CNT_CAPTURE_MODE);
    
    cnt_set_src_edge(cnt_dev->base, (CNT_EXT_DIN_A | CNT_BOTH_EDGE) << CNT_START_SIGNLE_SHIFT |
                (CNT_EXT_DIN_A | CNT_BOTH_EDGE) << CNT_DIN0_SHIFT);
    cnt_set_soft_trigger(cnt_dev->base, 0);
    
    /* enable overflow for capture, otherwise will get old value */
    cnt_set_capture_overflow(cnt_dev->base, 0x3f);//1--> rewrite, 0--> discard.
    
    cnt_set_in_bypass(cnt_dev->base, CNT_IN_BYPASS_B|CNT_IN_BYPASS_A); 
    cnt_set_input_mux(cnt_dev->base, 0);   
    
    NVIC_SetPriority(Counter_IRQn, IRQ_PRI_AboveNormal);
    NVIC_EnableIRQ(Counter_IRQn);
    hal_cnt_intr_unmask(cnt_dev);
    
    cnt_enable(cnt_dev->base);
    
    int ret = ir_binary_sem_wait(dev, osWaitForever);
    
    ir_recv_stop(dev);
    
    *out_sz = ir_parse_freq_data(dev);
    dev->mode = IR_IDLE;
    
#if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
#endif
    osMutexRelease(dev->mutex);
    return ret;
}

static void ir_get_remain_value(ir_dev_t *dev)
{
    cnt_dev_t *cnt_dev = dev->cnt_dev;
    ir_buf_t * dev_buf = &(ir_buf[dev->id]);
    uint32_t cap_sta = cnt_get_capture_status(cnt_dev->base);
    
    if (dev_buf->in_buf)
    {
        //uint32_t tmp;
        /* need enable capture overflow */
        if ((cap_sta & 0x1) && (dev_buf->in_pos < dev_buf->in_size)) {
            dev_buf->in_buf[dev_buf->in_pos++] = cnt_get_capture_reg_a0(cnt_dev->base);
        }
        if ((cap_sta & 0x2) && (dev_buf->in_pos < dev_buf->in_size)) {
            dev_buf->in_buf[dev_buf->in_pos++] = cnt_get_capture_reg_a1(cnt_dev->base);
        }
        if ((cap_sta & 0x4) && (dev_buf->in_pos < dev_buf->in_size)) {                     
            dev_buf->in_buf[dev_buf->in_pos++] = cnt_get_capture_reg_a2(cnt_dev->base);
        }
    }
}

int hal_ir_stop_recv(ir_dev_t *dev)
{
    if (!dev)
        return IR_ERR_INVALID_PARAM;
    osSemaphoreRelease(dev->semaphore);
    return IR_ERR_OK;
}

static int ir_parse_data(ir_dev_t *dev)
{
    ir_buf_t * dev_buf = &(ir_buf[dev->id]);
    if (dev_buf->in_pos == 0)
        return 0;
#if 0
    PRINTD(DBG_TRACE, " in_pos %d\r\n", dev_buf->in_pos);
    PRINTD(DBG_TRACE, " start %d\r\n", dev_buf->start_cnt);
    for (int i = 0; i < dev_buf->in_pos; i++)
    {
        PRINTD(DBG_TRACE, " 0x%x ", dev_buf->in_buf[i]);
    }
    PRINTD(DBG_TRACE, " \r\n");
#endif
    for (int i = dev_buf->in_pos - 1; i > 0; i--)
    {
        dev_buf->in_buf[i] = dev_buf->in_buf[i] - dev_buf->in_buf[i - 1];
    }
    dev_buf->in_buf[0] = dev_buf->in_buf[0] - dev_buf->start_cnt;
#if 0
    /* remove offset */
    for (int i = 0; i < in_pos; i++)
    {
        if (i % 2 == 0)
        {
            in_buf[i] -= dev->cycle_offset;
        }
        else
        {
            in_buf[i] += dev->cycle_offset;
        }
    }
#endif
    return dev_buf->in_pos;
}

static int ir_parse_freq_data(ir_dev_t *dev)
{
    ir_buf_t * dev_buf = &(ir_buf[dev->id]);
    if (dev_buf->in_pos <= 1)
        return 0;
    
#if 0
    PRINTD(DBG_TRACE, " in_pos %d\r\n", in_pos);
    PRINTD(DBG_TRACE, " start %d\r\n", freq_start_cnt);
    for (int i = 0; i < in_pos; i++)
    {
        PRINTD(DBG_TRACE, " 0x%x ", in_buf[i]);
    }
    PRINTD(DBG_TRACE, " \r\n");
#endif
    int len = dev_buf->in_pos - 1;
    /* discard buf[0] */
    for (int i = 0; i < len; i++)
    {
        dev_buf->in_buf[i] = dev_buf->in_buf[i + 1];
    }
    
    for (int i = len - 1; i > 0; i--)
    {
        dev_buf->in_buf[i] = dev_buf->in_buf[i] - dev_buf->in_buf[i - 1];
    }
    dev_buf->in_buf[0] = dev_buf->in_buf[0] - dev_buf->freq_start_cnt;
#if 0
    /* remove offset */
    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0)
        {
            in_buf[i] -= dev->cycle_offset;
        }
        else
        {
            in_buf[i] += dev->cycle_offset;
        }
    }
#endif
    return len;
}

int hal_ir_is_stop(ir_dev_t *dev)
{
    return dev->mode == IR_IDLE;
}

uint32_t ir_get_evt(uint32_t p)
{
    return (p >> 8) & 0xff;
}

#endif

