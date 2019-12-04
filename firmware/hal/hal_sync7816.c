#include "in_config.h"
/**
 ****************************************************************************************
 *
 * @file hal_sync7816.c
 *
 * @brief Sync7816 driver implementation file  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
#if CFG_COUNTER_EN
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "in_arm.h"
#include "in_mmap.h"
#include "in_irq.h"
#include "in_debug.h"

#include ".\hal\hal_sync7816.h"
#include ".\hal\hal_clk.h"
#define SYNC7816_TIMEOUT 1000///< Operation timeout

//volatile static char shiftout_complete = 0;
//volatile static char timer_stop = 0;

static void sync7816_setup_clk(sync7816_dev_t* dev);
static void sync7816_setup_rst(sync7816_dev_t* dev, uint32_t duration);
static int sync7816_get_read_data(sync7816_dev_t* dev, uint32_t *pval, uint32_t bit_len);
static int sync7816_setup_read(sync7816_dev_t* dev, uint32_t start_trigger, uint32_t bit_len);
static void fm4428_setup_write_with_read(sync7816_dev_t* dev, uint32_t val, uint32_t write_len, uint32_t read_len);
static void fm4442_setup_write(sync7816_dev_t* dev, uint32_t val, uint32_t write_len);
static sync7816_dev_t sync7816_dev = {
    .used = 0,
    .clk = 16000,
};

osSemaphoreDef(sync7816_semaphore);
osSemaphoreDef(sync7816_timer_sema);
osMutexDef(sync7816_mutex);


static void sync7816_data_handle(uint32_t status, void *arg)
 {
     sync7816_dev_t *dev = &sync7816_dev;

     //PRINTD(DBG_TRACE, "irq  status %x \r\n",status);
     if (status& CNT_SHIFTOUT_WAVEFORM_END) {
         osSemaphoreRelease(dev->semaphore);

     }

 }
 static void sync7816_timer_handle(uint32_t status, void *arg)
 {
     sync7816_dev_t *dev = &sync7816_dev;

     if (status&CNT_WAVEFORM_STOP) {
         //PRINTD(DBG_TRACE, "timer stop \r\n");
         osSemaphoreRelease(dev->timer_sema);
     }


 }

/* duplicate bit stream, for exsample  b'1101 => b'11110011*/
static uint32_t sync7816_dup_bits(uint32_t val, uint32_t bit_len) 
{
    if (bit_len > 16)
        bit_len = 16;
    uint32_t dup = 0;
    for (int i = 0; i < bit_len; i++) {
        uint32_t bit = (val>>i) & 0x1;
        dup = dup | (bit<<(2*i)) | (bit<<(2*i+1));
    }
    return dup;
}

/* strip bit stream, for exsample b'11110011 => b'1101 */
static uint32_t sync7816_strip_bits(uint32_t val)
{
    uint32_t ret = 0;
    for (int i = 1; i < 32; i += 2) {
        uint32_t tmp = (val>>i)&0x1;
        ret |= tmp<<(i/2);
    }
    return ret;
}

static uint32_t sync7816_msb_to_lsb(uint32_t val)
{
    uint32_t ret = 0;
    for (int i = 0; i < 32; i++) {
        ret <<= 1;
        ret |= val&0x1;
        
        val >>= 1;
    }
    return (ret&0xff)<<24 | (ret&0xff00)<<8 | (ret&0xff0000)>>8 | (ret&0xff000000)>>24;
}
#if CFG_PM_EN
static int sync7816_pm_state(void *arg, uint32_t *sleep_duration)
{
	sync7816_dev_t *pd = (sync7816_dev_t *)arg;

	*sleep_duration = PM_MAX_SLEEP_TIME;
	return pd->power_state;
}

static void sync7816_pm_down(void *arg, uint32_t sleep_duration)
{
    sync7816_dev_t *pd = (sync7816_dev_t *)arg;
    hal_gpio_aon_latch(2, pd->data_pin + 1, 1);// CNT_PIN0 is gpio2_1
    hal_gpio_aon_latch(2,  pd->clk_pin + 1, 1);
    hal_gpio_aon_latch(2,  pd->rst_pin + 1, 1);
	return;
}

static void sync7816_pm_up(void *arg)
{
	sync7816_dev_t *pd = (sync7816_dev_t *)arg;
    //hal_cnt_pin_mux_en(pd->clk_pin, 1);
    //hal_cnt_pin_mux_en(pd->rst_pin, 1);
    //hal_cnt_pin_mux_en(pd->data_pin, 1);
    hal_gpio_aon_latch(2, pd->data_pin + 1, 0);// CNT_PIN0 is gpio2_1
    hal_gpio_aon_latch(2,  pd->clk_pin + 1, 0);
    hal_gpio_aon_latch(2,  pd->rst_pin + 1, 0);
    
    hal_cnt_internal_din_pinmux(pd->data_dev->id * 2, pd->data_pin);//use data cnt A pin
    hal_cnt_internal_dout_pinmux(pd->data_dev->id * 2, pd->data_pin);//use data cnt A pin
    hal_cnt_internal_dout_pinmux(pd->clk_dev->id * 2, pd->clk_pin);
    hal_cnt_internal_dout_pinmux(pd->rst_dev->id * 2, pd->rst_pin);
    //PRINTD(DBG_TRACE, "%s \n", __func__);
}
#endif	// CFG_PM_EN
sync7816_dev_t* hal_sync7816_open(int clk_pin, int rst_pin, int data_pin, uint32_t clk)
{
    sync7816_dev_t* dev = &sync7816_dev;
    if (dev->used) {
        return NULL;
    }
    dev->clk_dev = NULL;
    dev->rst_dev = NULL;
    dev->data_dev = NULL;
    dev->timer_dev = NULL;
    dev->semaphore = NULL;
    dev->mutex = NULL;
    dev->timer_sema = NULL;
    int clk_id = CNT0_ID;
    int rst_id = CNT1_ID;
    int data_id = CNT2_ID;
    int timer_id = CNT3_ID;
    
    if (hal_cnt_pin_chk(clk_pin) != CNT_ERR_OK) {
        goto fail;
    }  
    if (hal_cnt_pin_chk(rst_pin) != CNT_ERR_OK) {
        goto fail;
    }   
    if (hal_cnt_pin_chk(data_pin) != CNT_ERR_OK) {
        goto fail;
    }
    dev->clk_pin = clk_pin;
    dev->rst_pin = rst_pin;
    dev->data_pin = data_pin;

    hal_cnt_pin_mux_en(dev->clk_pin, 1);
    hal_cnt_pin_mux_en(dev->rst_pin, 1);
    hal_cnt_pin_mux_en(dev->data_pin, 1);

    dev->clk_dev = hal_cnt_open(clk_id, 0);
    if (dev->clk_dev == NULL)
    {
        goto fail;
    }
    //cnt_set_default(clk_dev);
    dev->rst_dev = hal_cnt_open(rst_id, 0);
    if (dev->rst_dev == NULL)
    {
        goto fail;
    }
    dev->data_dev = hal_cnt_open(data_id, 0);
    if (dev->data_dev == NULL)
    {
        goto fail;
    }
    dev->timer_dev = hal_cnt_open(timer_id, 0);
    if (dev->timer_dev == NULL)
    {
        goto fail;
    }

    hal_cnt_internal_din_pinmux(data_id * 2, dev->data_pin);//use data cnt A pin
    hal_cnt_internal_dout_pinmux(data_id * 2, dev->data_pin);//use data cnt A pin
    hal_cnt_internal_dout_pinmux(clk_id * 2, dev->clk_pin);
    hal_cnt_internal_dout_pinmux(rst_id * 2, dev->rst_pin);


    dev->semaphore = osSemaphoreCreate(osSemaphore(sync7816_semaphore), 0);
    if (!dev->semaphore) {
        goto fail;
    }
    dev->timer_sema = osSemaphoreCreate(osSemaphore(sync7816_timer_sema), 0);
    if (!dev->timer_sema) {
        goto fail;
    }
    dev->mutex = osMutexCreate(osMutex(sync7816_mutex));
    if (!dev->mutex) {
        goto fail;
    }



    dev->clk = clk;
    hal_cnt_set_handler(dev->data_dev, sync7816_data_handle, dev);
    hal_cnt_set_handler(dev->timer_dev, sync7816_timer_handle, dev);

    //shiftout_complete = 0;
    //timer_stop = 0;
    //vcc up

    //16khz clk up  use OUT_A
    cnt_disable(dev->clk_dev->base);
    cnt_disable(dev->rst_dev->base);
    cnt_disable(dev->data_dev->base);
    cnt_disable(dev->timer_dev->base);


#if CFG_PM_EN
	dev->power_state = PM_DEEP_SLEEP;
	dev->pmd.arg = (void *)dev;
	dev->pmd.power_state = sync7816_pm_state;
	dev->pmd.power_down = sync7816_pm_down;
	dev->pmd.power_up = sync7816_pm_up;
	hal_pm_reg_mod(&dev->pmd);
#endif
    return dev;
fail:
    if (dev->clk_dev) {
        hal_cnt_close(dev->clk_dev);
        dev->clk_dev = NULL;
    }
    if (dev->rst_dev) {
        hal_cnt_close(dev->rst_dev);
        dev->rst_dev = NULL;
    }
    if (dev->data_dev) {
        hal_cnt_close(dev->data_dev);
        dev->data_dev = NULL;
    }
    if (dev->timer_dev) {
        hal_cnt_close(dev->timer_dev);
        dev->timer_dev = NULL;
    }

    if (dev->mutex) {
        osMutexDelete(dev->mutex);
        dev->mutex = NULL;
    }
    if (dev->semaphore) {
        osSemaphoreDelete(dev->semaphore);	
        dev->semaphore = NULL;
    }
    if (dev->timer_sema) {
        osSemaphoreDelete(dev->timer_sema);	
        dev->timer_sema = NULL;
    }
    dev->used = 0;
    return NULL;
}
void hal_sync7816_close(sync7816_dev_t* dev)
{
    hal_cnt_close(dev->clk_dev);
    hal_cnt_close(dev->rst_dev);
    hal_cnt_close(dev->data_dev);
    hal_cnt_close(dev->timer_dev);
    osMutexDelete(dev->mutex);
    osSemaphoreDelete(dev->semaphore);
    osSemaphoreDelete(dev->timer_sema);
    hal_cnt_pin_mux_en(dev->clk_pin, 0);
    hal_cnt_pin_mux_en(dev->rst_pin, 0);
    hal_cnt_pin_mux_en(dev->data_pin, 0);
    #if CFG_PM_EN
	hal_pm_unreg_mod(&dev->pmd);
    #endif
    dev->used = 0;
}
static void sync7816_setup_clk(sync7816_dev_t* dev)
{
    cnt_set_mode(dev->clk_dev->base, CNT_WAVAFORM_MODE);
    cnt_set_src_edge(dev->clk_dev->base, 0);
    cnt_set_target_ctrl(dev->clk_dev->base, CNT_A2_RESET_VALUE|CNT_A2_RESTART_COUNTER
            |CNT_B2_KEEP_VALUE|CNT_B2_STOP_COUNTER
            |(0<<CNT_DOUT_A_RESET_VALUE_SHIFT)|(0<<CNT_DOUT_B_RESET_VALUE_SHIFT));

    cnt_set_soft_trigger(dev->clk_dev->base, 0);

    cnt_set_input_mux(dev->clk_dev->base, 0);//use A

    cnt_set_target_a(dev->clk_dev->base, 0, hal_cnt_get_clk(dev->clk_dev) /dev->clk/2, hal_cnt_get_clk(dev->clk_dev)/dev->clk);
    cnt_set_target_b(dev->clk_dev->base, 0, hal_cnt_get_clk(dev->clk_dev) /dev->clk + 10, 0);

    cnt_set_out_bypass(dev->clk_dev->base, CNT_OUT_BYPASS_B);//bypass a and b  review?
    cnt_set_in_bypass(dev->clk_dev->base, CNT_IN_BYPASS_A|CNT_IN_BYPASS_B);
    
    hal_cnt_enable(dev->clk_dev);
    //cnt_trigger_start(clk_cnt);

}

static void sync7816_setup_rst(sync7816_dev_t* dev, uint32_t duration)
{

    cnt_set_mode(dev->rst_dev->base, CNT_WAVAFORM_MODE);
    cnt_set_src_edge(dev->rst_dev->base, ((CNT_INNER_DIN0+dev->clk_dev->id)|CNT_RISING_EDGE)<<CNT_START_SIGNLE_SHIFT);
    cnt_set_target_ctrl(dev->rst_dev->base, CNT_B2_KEEP_VALUE|CNT_B2_STOP_COUNTER
            |CNT_A2_RESET_VALUE|CNT_A2_STOP_COUNTER
            |(0<<CNT_DOUT_A_RESET_VALUE_SHIFT)|(0<<CNT_DOUT_B_RESET_VALUE_SHIFT));

    cnt_set_soft_trigger(dev->rst_dev->base, 0);
    cnt_set_input_mux(dev->rst_dev->base, 0xf);//use B(clock B) 
    
    //pull up reset
    cnt_set_target_a(dev->rst_dev->base, duration, hal_cnt_get_clk(dev->clk_dev) /dev->clk/4, 0);
    cnt_set_target_b(dev->rst_dev->base, 0, 0, 0);


    cnt_set_out_bypass(dev->rst_dev->base, CNT_OUT_BYPASS_B|CNT_OUT_BYPASS_A);//bypass a and b  review?
    cnt_set_in_bypass(dev->rst_dev->base, CNT_IN_BYPASS_A|CNT_IN_BYPASS_B);
    hal_cnt_enable(dev->rst_dev);
}
/*only use output A*/
static void sync7816_setup_timer(sync7816_dev_t* dev, uint32_t stop_time, uint32_t rising_time, uint32_t trigger_start)
{

        //16khz clk up  use OUT_A
    //timer_stop = 0;

    cnt_set_mode(dev->timer_dev->base, CNT_WAVAFORM_MODE);
    cnt_set_src_edge(dev->timer_dev->base, trigger_start<<CNT_START_SIGNLE_SHIFT);//todo
    cnt_set_target_ctrl(dev->timer_dev->base, CNT_A2_KEEP_VALUE|CNT_A2_STOP_COUNTER
            |CNT_B2_KEEP_VALUE|CNT_B2_STOP_COUNTER
            |(0<<CNT_DOUT_A_RESET_VALUE_SHIFT)|(0<<CNT_DOUT_B_RESET_VALUE_SHIFT));
    cnt_set_soft_trigger(dev->timer_dev->base, 0);
    cnt_set_input_mux(dev->timer_dev->base, 0);//use A
    cnt_set_shiftmode_ctrl(dev->timer_dev->base, 0);//use A
    cnt_set_target_a(dev->timer_dev->base, 0, rising_time, stop_time);
    cnt_set_target_b(dev->timer_dev->base, 0, 0, 0);
    cnt_set_out_bypass(dev->timer_dev->base, CNT_OUT_BYPASS_B|CNT_OUT_BYPASS_A);
    cnt_set_in_bypass(dev->timer_dev->base, CNT_IN_BYPASS_A|CNT_IN_BYPASS_B);
    hal_cnt_enable(dev->timer_dev);


}


int hal_sync7816_answer_to_rst(sync7816_dev_t* dev, uint32_t* pval)
{
    int ret = SYNC7816_ERR_OK;
    osMutexWait(dev->mutex, osWaitForever);
	#if CFG_PM_EN
    dev->power_state = PM_SLEEP;
	#endif
    sync7816_setup_clk(dev);
    //reset
    sync7816_setup_rst(dev, hal_cnt_get_clk(dev->clk_dev) /dev->clk + hal_cnt_get_clk(dev->clk_dev) /1000000*8);//8us dev->clk->clk/1000000*8
    //cnt_set_out_bypass(dev->data_dev->base, CNT_OUT_BYPASS_B|CNT_OUT_BYPASS_A);//bypass a and b  review?
    //cnt_set_in_bypass(dev->data_dev->base, CNT_IN_BYPASS_A|CNT_IN_BYPASS_B);


    sync7816_setup_read(dev, ((CNT_INNER_DIN0+dev->rst_dev->id)| CNT_FALLING_EDGE)<<CNT_START_SIGNLE_SHIFT, 32);


    cnt_trigger_start(dev->clk_dev->base);

    uint32_t val = 0;
    ret = sync7816_get_read_data(dev, &val, 32);
    if (ret !=  SYNC7816_ERR_OK) {
        //PRINTD(DBG_TRACE, "read error\r\n");
        goto out;
    }
    *pval = sync7816_msb_to_lsb(val);
    //PRINTD(DBG_TRACE, "1val data is %08x\r\n",val);
    //PRINTD(DBG_TRACE, "read data is %08x\r\n",*pval);
    cnt_trigger_stop(dev->clk_dev->base);

out:
		#if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
		#endif

    osMutexRelease(dev->mutex);
    return ret;

}





static int sync7816_setup_read(sync7816_dev_t* dev, uint32_t start_trigger, uint32_t bit_len)
{

    cnt_dev_t *data_dev = dev->data_dev;
    cnt_set_mode(data_dev->base, CNT_SHIFTIN_MODE|CNT_SWITCH_ENABLE);

    cnt_set_src_edge(data_dev->base, start_trigger | (CNT_EXT_DIN_A<<CNT_DIN0_SHIFT));
    cnt_set_soft_trigger(data_dev->base, 0);
    cnt_set_input_mux(data_dev->base, 0);//use A
    cnt_set_shiftmode_ctrl(data_dev->base, 0);//use A

    cnt_set_shiftin_bit_num(data_dev->base, bit_len - 1);
    cnt_set_shiftmode_point_en(data_dev->base, CNT_SHIFTMODE_POINT_EN | hal_cnt_get_clk(dev->clk_dev)/dev->clk/2);//half clk time (COUNTER_CLK/SYNC_CLK/2)

    cnt_set_one_bit_count(data_dev->base, hal_cnt_get_clk(dev->clk_dev)/dev->clk);

    cnt_config_switch_mode(data_dev->base, bit_len<<CNT_CAPTURE_SHIFTIN_CNT_SHIFT|0xff<<CNT_WAVEFORM_SHIFTOUT_CNT_SHIFT);
    cnt_set_in_bypass(data_dev->base, CNT_IN_BYPASS_A|CNT_IN_BYPASS_B);

    hal_cnt_enable(data_dev);    
    return SYNC7816_ERR_OK;
}

static int sync7816_get_read_data(sync7816_dev_t* dev, uint32_t *pval, uint32_t bit_len)
{
    uint32_t update = 0;
    uint32_t mask = 0;
    
    if (bit_len > 32)
        bit_len = 32;
    for (int i = 0; i < bit_len; i++) {
        mask <<= 1;
        mask |= 1;
    }

    int wait = 1000000;
    while(wait--) {
        update = cnt_get_shiftin_update(dev->data_dev->base);
        if (update >= mask)
            break;
    }

    //todo cnt_sync here?


    if (wait < 0) {
        *pval = 0;
        PRINTD(DBG_TRACE, "read time out %x\r\n", update);
        return SYNC7816_ERR_TIMEOUT;
    } else if (update > mask) {
        PRINTD(DBG_TRACE, "too much data %x \r\n", update);
    }
    *pval = cnt_get_shiftin_data(dev->data_dev->base);
    //PRINTD(DBG_TRACE, "read val %08x \r\n", *pval);
    return SYNC7816_ERR_OK;
}

void hal_sync7816_stop(sync7816_dev_t* dev)
{
    cnt_dev_t *rst_dev = dev->rst_dev;
    osMutexWait(dev->mutex, osWaitForever);
    cnt_set_target_a(rst_dev->base, hal_cnt_get_clk(dev->clk_dev)/dev->clk, 1, 0);//8us dev->clk->clk/1000000*8
    cnt_trigger_stop(dev->clk_dev->base);
    cnt_disable(dev->clk_dev->base);
    cnt_trigger_stop(rst_dev->base);
    cnt_trigger_start(rst_dev->base);
    #if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
    #endif
    osMutexRelease(dev->mutex);

}


int fm4428_read_cmd(sync7816_dev_t* dev, uint32_t cmd, uint32_t addr, uint32_t *rx_data, uint32_t rx_len)
{
    int ret = SYNC7816_ERR_OK;
    uint32_t val = cmd&0x3f;
    val |= (addr&0xff)<<8 | (addr<<2)&0xc0;
    osMutexWait(dev->mutex, osWaitForever);
    #if CFG_PM_EN
    dev->power_state = PM_SLEEP;
    #endif
    //PRINTD(DBG_TRACE, "write  %08x\r\n", val);
    cnt_trigger_stop(dev->data_dev->base);
    cnt_trigger_stop(dev->clk_dev->base);
    cnt_trigger_stop(dev->rst_dev->base);
    cnt_disable(dev->data_dev->base);
    //shiftout_complete = 0;

   
    fm4428_setup_write_with_read(dev, val,24,rx_len);
    hal_cnt_sync(dev->data_dev, CNT_SNAP_SHIFTIN_DATA_MASK);
    //delay(10);

    
    cnt_trigger_start(dev->clk_dev->base);
    if (osSemaphoreWait(dev->semaphore, SYNC7816_TIMEOUT) <= 0) {
        PRINTD(DBG_TRACE, "%s:send time out\r\n", __func__);
        ret = SYNC7816_ERR_TIMEOUT;
        goto out;
    }
    #if 0
    int wait = SYNC7816_TIMEOUT;
    while(wait--) {
        if (shiftout_complete) {
            shiftout_complete = 0;
            break;
        }
    }
    if (wait < 0) {
        PRINTD(DBG_TRACE, "%s:send time out\r\n", __func__);
        return -1;
    }
    #endif


    //val=0;
    ret = sync7816_get_read_data(dev, rx_data, rx_len);
    if (ret != SYNC7816_ERR_OK) {
        PRINTD(DBG_TRACE, "get read data err %d\r\n", ret);
    }
out:
#if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
    #endif
    osMutexRelease(dev->mutex);
    return ret;
}
int fm4428_read_byte(sync7816_dev_t* dev, uint32_t addr, int protect, uint8_t *data)
{
    uint32_t p = 0;
    uint32_t rx = 0;
    int ret = SYNC7816_ERR_OK;
    //PRINTD(DBG_TRACE, "%s \n", __func__);
    #if CFG_PM_EN
    dev->power_state = PM_SLEEP;
    #endif
    if (protect) {
        ret = fm4428_read_cmd(dev, 0xc, addr, &rx, 9 + 1);//one clk to stable
        p = rx & 0x1;
        rx >>= 1;
        rx &= 0xff;
 
    } else {
        ret = fm4428_read_cmd(dev, 0xe, addr, &rx, 8 + 1);
        rx &= 0xff;
    }
    
    //PRINTD(DBG_TRACE, "read  data is %08x\r\n",*rx);
    //PRINTD(DBG_TRACE, "read data is %08x  %d\r\n",sync7816_msb_to_lsb(*rx), p);  
    if (ret != SYNC7816_ERR_OK) {
        goto out;
    }
    *data = sync7816_msb_to_lsb(rx);
    //PRINTD(DBG_TRACE, "read data is %08x  %d\r\n",data, p);  
out:
#if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
    #endif
    return ret;
}


static void fm4428_setup_write_with_read(sync7816_dev_t* dev, uint32_t val, uint32_t write_len, uint32_t read_len)
{
    
    sync7816_setup_rst(dev, hal_cnt_get_clk(dev->clk_dev)/dev->clk*write_len + hal_cnt_get_clk(dev->clk_dev)/dev->clk/4);
    sync7816_setup_clk(dev);


    //IO

    cnt_set_mode(dev->data_dev->base, CNT_SHIFTOUT_MODE|CNT_SWITCH_ENABLE);
    
    cnt_set_src_edge(dev->data_dev->base, (CNT_EXT_DIN_A<<CNT_DIN0_SHIFT)|
        ((CNT_INNER_DIN0+dev->rst_dev->id)|CNT_RISING_EDGE)<<CNT_START_SIGNLE_SHIFT);
    cnt_set_soft_trigger(dev->data_dev->base, 0);

    cnt_set_input_mux(dev->data_dev->base, 0);//use A
    cnt_set_shiftmode_ctrl(dev->data_dev->base, 0);//use A

    cnt_set_shiftout_bit_num(dev->data_dev->base, write_len-1);
   
    cnt_set_shiftmode_point_en(dev->data_dev->base, CNT_SHIFTMODE_POINT_EN | hal_cnt_get_clk(dev->clk_dev)/dev->clk/2);//SHIFTMODE_POINT_EN COUNTER_CLK/SYNC_CLK/2

    cnt_set_shiftout_data(dev->data_dev->base, val);
    cnt_set_shiftout_data_valid(dev->data_dev->base, 1);
   

    cnt_set_one_bit_count(dev->data_dev->base, hal_cnt_get_clk(dev->clk_dev)/dev->clk);
    cnt_config_switch_mode(dev->data_dev->base, CNT_CAPTURE_SHIFTIN_AUTO_ENABLE|
            (write_len)<<CNT_WAVEFORM_SHIFTOUT_CNT_SHIFT|read_len<<CNT_CAPTURE_SHIFTIN_CNT_SHIFT);
    cnt_set_out_bypass(dev->data_dev->base, CNT_OUT_BYPASS_B|CNT_OUT_BYPASS_A);
    cnt_set_in_bypass(dev->data_dev->base, CNT_IN_BYPASS_A|CNT_IN_BYPASS_B);


    cnt_set_shiftin_bit_num(dev->data_dev->base, read_len - 1);//read_len - 1
    

    hal_cnt_enable(dev->data_dev);
}

static void fm4428_setup_write(sync7816_dev_t* dev, uint32_t val, uint32_t bit_len)
{
    
    sync7816_setup_rst(dev, hal_cnt_get_clk(dev->clk_dev)/dev->clk*bit_len + hal_cnt_get_clk(dev->clk_dev)/dev->clk/4);
    sync7816_setup_clk(dev);


    //IO


    cnt_set_mode(dev->data_dev->base, CNT_SHIFTOUT_MODE|CNT_SWITCH_ENABLE);
    cnt_set_src_edge(dev->data_dev->base, 
        ((CNT_INNER_DIN0+dev->rst_dev->id)|CNT_RISING_EDGE)<<CNT_START_SIGNLE_SHIFT);
    cnt_set_soft_trigger(dev->data_dev->base, 0);


    cnt_set_input_mux(dev->data_dev->base, 0);//use A
    cnt_set_shiftmode_ctrl(dev->data_dev->base, 0);//use A


    cnt_set_shiftout_bit_num(dev->data_dev->base, bit_len-1);
   
    cnt_set_shiftmode_point_en(dev->data_dev->base, CNT_SHIFTMODE_POINT_EN|0x10);//SHIFTMODE_POINT_EN

    cnt_set_shiftout_data(dev->data_dev->base, val);
    cnt_set_shiftout_data_valid(dev->data_dev->base, 1);
   

    cnt_set_one_bit_count(dev->data_dev->base, hal_cnt_get_clk(dev->clk_dev)/dev->clk);
    cnt_config_switch_mode(dev->data_dev->base, 
            bit_len<<CNT_WAVEFORM_SHIFTOUT_CNT_SHIFT|0xff<<CNT_CAPTURE_SHIFTIN_CNT_SHIFT);
    cnt_set_out_bypass(dev->data_dev->base, CNT_OUT_BYPASS_B|CNT_OUT_BYPASS_A);
    cnt_set_in_bypass(dev->data_dev->base, CNT_IN_BYPASS_A|CNT_IN_BYPASS_B);






    hal_cnt_enable(dev->data_dev);
}
int fm4428_write_cmd(sync7816_dev_t* dev, uint32_t cmd, uint32_t addr, uint8_t data, uint32_t wait_clk)
{
    int ret = SYNC7816_ERR_OK;
    uint32_t val = cmd&0x3f;
    val |= (addr&0xff)<<8 | (addr<<2)&0xc0;
    val |= ((uint32_t)data)<<16;
    //PRINTD(DBG_TRACE, "fm4428_write_cmd  %x %x %x  %d\r\n", cmd, addr, data, wait_clk);
    //PRINTD(DBG_TRACE, "write  %08x\r\n", val);
    osMutexWait(dev->mutex, osWaitForever);
    #if CFG_PM_EN
    dev->power_state = PM_SLEEP;
    #endif
    cnt_trigger_stop(dev->data_dev->base);
    cnt_trigger_stop(dev->clk_dev->base);
    cnt_trigger_stop(dev->rst_dev->base);
    cnt_disable(dev->data_dev->base);
    cnt_disable(dev->timer_dev->base);
    //shiftout_complete = 0;
    //timer_stop = 0;

    
    fm4428_setup_write(dev, val, 24);
    sync7816_setup_timer(dev, hal_cnt_get_clk(dev->clk_dev)/dev->clk*wait_clk, 10, 0);


    
    cnt_trigger_start(dev->clk_dev->base);
    cnt_trigger_start(dev->timer_dev->base);

#if 0
    int wait = SYNC7816_TIMEOUT;
    while(wait--) {
        if (shiftout_complete > 0) {
            shiftout_complete = 0;
            break;
        }
    }
    if (wait < 0) {
        PRINTD(DBG_TRACE, "%s:send time out\r\n", __func__);
        return -1;
    }

    if (osSemaphoreWait(dev->semaphore, SYNC7816_TIMEOUT) <= 0) {
        PRINTD(DBG_TRACE, "%s:send time out\r\n", __func__);
        return SYNC7816_ERR_TIMEOUT;
    }

    wait = SYNC7816_TIMEOUT;
    while(wait--) {
        if (timer_stop > 0) {
            timer_stop = 0;
            break;
        }
    }
    if (wait < 0) {
        PRINTD(DBG_TRACE, "time time out\r\n");
        return -1;
    }
#endif
    if (osSemaphoreWait(dev->timer_sema, SYNC7816_TIMEOUT) <= 0) {
        PRINTD(DBG_TRACE, "%s:timer timeout error\r\n", __func__);
        ret = SYNC7816_ERR_TIMEOUT;
        goto out;
    }

out:
#if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
    #endif
    osMutexRelease(dev->mutex);
    return ret;
}


int fm4428_write_byte(sync7816_dev_t* dev, uint32_t addr, uint8_t data)
{
    return fm4428_write_cmd(dev, 0x33,addr, data, 220);
}

int fm4428_unlock(sync7816_dev_t* dev, uint8_t psc1, uint8_t psc2)
{
    uint8_t val;
    fm4428_read_byte(dev, 1021, 1,&val);
    //PRINTD(DBG_TRACE, "read byte %x\n", val);
    if (val == 0)
        return SYNC7816_ERR_INVALID_PARAM;

    for (int i = 0; i < 8; i++) {
        if ((val>>i) & 0x1) {
            val &= ~(1<<i);
            break;
        }
    }

    fm4428_write_cmd(dev, 0x32,1021, val, 220);
  
    fm4428_write_cmd(dev, 0xd,1022, psc1, 100);
   
    fm4428_write_cmd(dev, 0xd,1023, psc2, 100);

    fm4428_write_byte(dev, 1021, 0xff);

    fm4428_read_byte(dev, 1021, 1,&val);

    //PRINTD(DBG_TRACE, "read byte %x\n", val);
    if (val != 0xff) {
        PRINTD(DBG_TRACE, "fm4428 unlock error %x\n", val);
        return SYNC7816_ERR_LOCK;
    }
    return SYNC7816_ERR_OK;
}

static void fm4442_setup_write_with_read(sync7816_dev_t* dev, uint32_t val, uint32_t write_len, uint32_t read_len)
{
    

    if(write_len>30 || read_len>16)
        PRINTD(DBG_TRACE, "len is too large \r\n");

    //IO
    




    
    cnt_dev_t *data_cnt = dev->data_dev;
    cnt_set_mode(data_cnt->base, CNT_SHIFTOUT_MODE|CNT_SWITCH_ENABLE);
    cnt_set_src_edge(data_cnt->base, (CNT_EXT_DIN_A<<CNT_DIN0_SHIFT)|
        ((CNT_INNER_DIN0+dev->timer_dev->id)|CNT_RISING_EDGE)<<CNT_START_SIGNLE_SHIFT);
    cnt_set_soft_trigger(data_cnt->base, 0);

    cnt_set_input_mux(data_cnt->base, 0);//use A
    cnt_set_shiftmode_ctrl(data_cnt->base, 0);//use A

    cnt_set_shiftout_bit_num(data_cnt->base, write_len + 2 - 1);
   
    cnt_set_shiftmode_point_en(data_cnt->base, CNT_SHIFTMODE_POINT_EN | hal_cnt_get_clk(dev->clk_dev)/dev->clk/4);//SHIFTMODE_POINT_EN COUNTER_CLK/SYNC_CLK/2

    uint32_t dup_val = sync7816_dup_bits(val, write_len/2);
    dup_val <<= 2;
    dup_val |= 0x1;
    cnt_set_shiftout_data(data_cnt->base, dup_val);//dup_val
    cnt_set_shiftout_data_valid(data_cnt->base, 1);
    //DUMP_REG(COUNTER_ALL_APB_REG_SHIFTOUT_DATA_C0, offset);

    cnt_set_one_bit_count(data_cnt->base, hal_cnt_get_clk(dev->clk_dev)/dev->clk/2);
    cnt_config_switch_mode(data_cnt->base, CNT_CAPTURE_SHIFTIN_AUTO_ENABLE|
            (write_len*2+4)<<CNT_WAVEFORM_SHIFTOUT_CNT_SHIFT|(read_len*2)<<CNT_CAPTURE_SHIFTIN_CNT_SHIFT);
    cnt_set_out_bypass(data_cnt->base, CNT_OUT_BYPASS_B|CNT_OUT_BYPASS_A);//bypass a and b
    cnt_set_in_bypass(data_cnt->base, CNT_IN_BYPASS_A|CNT_IN_BYPASS_B);


    cnt_set_shiftin_bit_num(data_cnt->base, read_len*2 - 1);//read_len - 1
    //WR_WORD(COUNTER_ALL_APB_REG_SHIFTMODE_POINT_EN_C0 + offset, SHIFTMODE_POINT_EN | COUNTER_CLK/SYNC_CLK/2);

    hal_cnt_enable(dev->data_dev);
    
}



int fm4442_read_cmd(sync7816_dev_t* dev, uint32_t cmd, uint32_t addr, uint32_t *rx_data, uint32_t rx_len)
{
    int ret = SYNC7816_ERR_OK;
    uint32_t val = cmd&0xff;
    val |= (addr&0xff)<<8;
    osMutexWait(dev->mutex, osWaitForever);
    PRINTD(DBG_TRACE, "write  %08x\r\n", val);
    #if CFG_PM_EN
    dev->power_state = PM_SLEEP;
    #endif
    cnt_trigger_stop(dev->data_dev->base);
    cnt_trigger_stop(dev->clk_dev->base);
    
    cnt_trigger_stop(dev->timer_dev->base);
    cnt_disable(dev->data_dev->base);  

    sync7816_setup_clk(dev);  
    fm4442_setup_write_with_read(dev, val, 24, rx_len);
    sync7816_setup_timer(dev, hal_cnt_get_clk(dev->clk_dev)/dev->clk*3, hal_cnt_get_clk(dev->clk_dev)/dev->clk*3/4, (CNT_INNER_DIN0+dev->clk_dev->id)|CNT_RISING_EDGE);//3 clk?
    hal_cnt_sync(dev->data_dev, CNT_SNAP_SHIFTIN_DATA_MASK);
    uint32_t refill = sync7816_dup_bits(val>>12, 12);
    PRINTD(DBG_TRACE, "refill  %08x\r\n", refill);
    refill |= 0x2000000;
 
    //int wait = SYNC7816_TIMEOUT;
    osDelay(10);

    
    cnt_trigger_start(dev->clk_dev->base);
   

    if (osSemaphoreWait(dev->timer_sema, SYNC7816_TIMEOUT) <= 0) {
        PRINTD(DBG_TRACE, "%s:timer timeout error\r\n", __func__);
        ret = SYNC7816_ERR_TIMEOUT;
        goto out;
    }
    #if 0    
    while(wait--) {
        if (timer_stop) {
            timer_stop = 0;
            break;
        }
    }
    if (wait < 0) {
        PRINTD(DBG_TRACE, "%s:send time out\r\n", __func__);
        return -1;
    }
    #endif
    
    cnt_set_shiftout_data(dev->data_dev->base, refill);//dup_val
    cnt_set_shiftout_data_valid(dev->data_dev->base, 1);
 

    //val=0;
    sync7816_get_read_data(dev, rx_data, rx_len*2);
    PRINTD(DBG_TRACE, "read back data is %08x\r\n",*rx_data);
    PRINTD(DBG_TRACE, "read data is %08x\r\n",sync7816_strip_bits(*rx_data));
    PRINTD(DBG_TRACE, "read data is %08x\r\n",sync7816_msb_to_lsb(sync7816_strip_bits(*rx_data)));

out:
#if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
    #endif
    osMutexRelease(dev->mutex);
    return ret;
}
int fm4442_write_cmd(sync7816_dev_t* dev, uint32_t cmd, uint32_t addr, uint8_t data)
{
	int ret = SYNC7816_ERR_OK;
    uint32_t val = cmd&0xff;
    val |= (addr&0xff)<<8;
    val |= ((uint32_t)data)<<16;
    osMutexWait(dev->mutex, osWaitForever);
    PRINTD(DBG_TRACE, "write  %08x\r\n", val);
    cnt_dev_t *data_cnt = dev->data_dev;
    #if CFG_PM_EN
    dev->power_state = PM_SLEEP;
    #endif
    cnt_trigger_stop(data_cnt->base);
    cnt_trigger_stop(dev->clk_dev->base);

    cnt_trigger_stop(dev->rst_dev->base);
    cnt_disable(data_cnt->base);  

    sync7816_setup_clk(dev);  
    fm4442_setup_write(dev, val, 24);
    sync7816_setup_timer(dev, hal_cnt_get_clk(dev->clk_dev)/dev->clk*3, hal_cnt_get_clk(dev->clk_dev)/dev->clk*3/4, (CNT_INNER_DIN0+dev->clk_dev->id)|CNT_RISING_EDGE);//3 clk?

    uint32_t refill = sync7816_dup_bits(val>>12, 12);
    //PRINTD(DBG_TRACE, "refill  %08x\r\n", refill);
    refill |= 0x2000000;
 
    //int wait = SYNC7816_TIMEOUT;
    osDelay(10);

    
    cnt_trigger_start(dev->clk_dev->base);
   

    if (osSemaphoreWait(dev->timer_sema, SYNC7816_TIMEOUT) <= 0) {
        PRINTD(DBG_TRACE, "%s:timer timeout error\r\n", __func__);
        ret = SYNC7816_ERR_TIMEOUT;
        goto out;
    }
    #if 0   
    while(wait--) {
        if (timer_stop) {
            timer_stop = 0;
            break;
        }
    }
    if (wait < 0) {
        PRINTD(DBG_TRACE, "%s:send time out\r\n", __func__);
        return -1;
    }
    #endif
    cnt_set_shiftout_data(data_cnt->base, refill);//dup_val
    cnt_set_shiftout_data_valid(data_cnt->base, 1);

out:
#if CFG_PM_EN
    dev->power_state = PM_DEEP_SLEEP;
    #endif
    osMutexRelease(dev->mutex);
    return ret;
}

static void fm4442_setup_write(sync7816_dev_t* dev, uint32_t val, uint32_t write_len)
{
    
   //uint32_t offset = cnt_get_reg_offset(dev->data_dev);
   cnt_dev_t *data_cnt = dev->data_dev;
    cnt_set_mode(data_cnt->base, CNT_SHIFTOUT_MODE|CNT_SWITCH_ENABLE);
    cnt_set_src_edge(data_cnt->base,
        ((CNT_INNER_DIN0+dev->timer_dev->id)|CNT_RISING_EDGE)<<CNT_START_SIGNLE_SHIFT);
    cnt_set_soft_trigger(data_cnt->base, 0);

    cnt_set_input_mux(data_cnt->base, 0);//use A
    cnt_set_shiftmode_ctrl(data_cnt->base, 0);//use A

    cnt_set_shiftout_bit_num(data_cnt->base, write_len + 2 - 1);
   


    uint32_t dup_val = sync7816_dup_bits(val, write_len/2);
    dup_val <<= 2;
    dup_val |= 0x1;
    cnt_set_shiftout_data(data_cnt->base, dup_val);//dup_val
    cnt_set_shiftout_data_valid(data_cnt->base, 1);
 

    cnt_set_one_bit_count(data_cnt->base, hal_cnt_get_clk(dev->clk_dev)/dev->clk/2);
    cnt_config_switch_mode(data_cnt->base, 
            (write_len*2+4)<<CNT_WAVEFORM_SHIFTOUT_CNT_SHIFT|0xff<<CNT_CAPTURE_SHIFTIN_CNT_SHIFT);
    cnt_set_out_bypass(data_cnt->base, CNT_OUT_BYPASS_B|CNT_OUT_BYPASS_A);//bypass a and b
    cnt_set_in_bypass(data_cnt->base, CNT_IN_BYPASS_A|CNT_IN_BYPASS_B);



    hal_cnt_enable(dev->data_dev);


}



#endif
