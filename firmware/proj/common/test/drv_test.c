#include "in_config.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include ".\hal\hal_adc.h"
#include ".\hal\hal_audio.h"
#include ".\hal\hal_counter.h"
#include ".\hal\hal_gpio.h"
#include ".\hal\hal_mouse.h"
#include ".\hal\hal_keyboard.h"
#include ".\hal\hal_power.h"
#include ".\hal\hal_sync7816.h"
#include ".\hal\hal_uart.h"
#include ".\hal\hal_counter.h"
#include ".\hal\hal_ir.h"
#include "in_arm.h"
#include "in_debug.h"

#include ".\ble\inb_api.h"

#include "cmsis_os.h"
#include "drv_test.h"

osMessageQDef(app_msg, 10, uint32_t);
static osMessageQId app_msg_q_id = NULL;
//static uint8_t audio_buf[1024] = { 0 };
//static uint32_t ir_buf[64] = { 0 };
static ir_dev_t * ir_dev = NULL;
//static int tst_stop = 1;
//extern void hal_audio_enc_loop(void const* arg);
//#if 0
//void HardFault_Handler(void)  {    
//    /* Go to infinite loop when Hard Fault exception occurs */   
//         if (CoreDebug->DHCSR & 1) {  //check C_DEBUGEN == 1 -> Debugger Connected       
//         __breakpoint(0);  // halt program execution here           
//         }    

//         while (1)    {    }
//}
//#endif
//static void print_to_byte(uint8_t val)
//{
//    uart_xmit_ready(UART0_BASE);
//    uart_write_data(UART0_BASE, val);
//}
//static uint8_t* audio_get_buf(int num_encoded_bytes, int status)
//{
//    if (status != 0 || num_encoded_bytes > sizeof(audio_buf) / sizeof(audio_buf[0])) {
//        return audio_buf;
//    }

//    for (int i = 0; i < num_encoded_bytes; i++) {
//        print_to_byte(audio_buf[i]);
//    }
//    return audio_buf;
//}

//static void audio_pdm_run(void)
//{
//    //hal_audio_enc_set_config(1, 0, 1600000, 16000, 0, 256, 256);
//    //while(tst_stop);
//    hal_audio_encode_start();

//    //PRINTD(DBG_TRACE, "start  %d\n", ret);
//	int i = 1000;
//    int cnt = 0;
//    while (i-- > 0) {
//        uint16_t len = 1024;
//        hal_audio_encode_process(audio_buf, 1024, &len);
//        			PRINTD(DBG_TRACE, "len  %d\n", len);
//        for (int i = 0; i < len; i++) {
//            ;//print_to_byte(audio_buf[i]);
//        }
//        cnt += len;
//        osDelay(5);
//    }
//		hal_audio_encode_stop();
//        PRINTD(DBG_TRACE, "cnt  %d\n", cnt);
//    tst_stop = 1;
//}
//int audio_pdm_test(void)
//{
//    //hal_gpio_pin_cfg(CFG_GPIO_4_0);
//    //hal_gpio_pin_cfg(CFG_GPIO_2_7);
//    //hal_gpio_pin_cfg(CFG_GPIO_2_8);
//    /*
//        uint32_t reg = aon_read(0x7100);
//        reg |= 1<<14;
//        aon_write(0x7100, reg);*/
//    int ret = hal_audio_enc_open();
//    PRINTD(DBG_TRACE, "open  %d\n", ret);
//    hal_audio_enc_set_pdm_mic_inp(0, 1, 0);//0 1 0
//    ret = hal_audio_enc_set_config(1, 0, 1600000, 16000, 0, 256, 256);
//    PRINTD(DBG_TRACE, "config  %d\n", ret); 
//    audio_pdm_run();
//    osDelay(2000);
//    audio_pdm_run();

//    return 0;
//}

//static void adc_pin(int pin)
//{
//    int port = 2;
//    hal_gpio_pin_mux(port, pin, 0, 0);

//    hal_gpio_pad_oe_ie(port, pin, 0, 1);

//    hal_gpio_pad_pd_pu(port, pin, 0, 0);

//    // gpio_pad_pc(port, pin, 1);
//}
////volatile uint16_t tst_buf[256]={0};
////volatile int tst_pos = 0;
//int adc_automode_test()
//{
//    adc_pin(1);
//    adc_pin(3);
//    adc_dev_t* dev = hal_adc_open();
//    uint16_t buf[256] = { 0 };
//    int sample = 32;
//    hal_adc_auto_mode_enable_ch(dev, ADC_CH14, buf, sample);
//    //hal_adc_auto_mode_enable_ch(dev, ADC_CH15, buf+32, 32);
//    hal_adc_auto_mode_enable_ch(dev, ADC_CH5, buf + sample, sample);
//    hal_adc_auto_mode_enable_ch(dev, ADC_CH3, buf + sample * 2, sample);
//    int i = 3;
//    while (i--) {
//        memset(buf, 0xff, sizeof(buf));
//        hal_adc_auto_mode_start(dev, sample);

//        for (int i = 0; i < sample; i++) {
//            PRINTD(DBG_TRACE, "VBAT  0x%04x \n", buf[i]);
//        }


//        for (int i = sample; i < sample*2; i++) {
//            PRINTD(DBG_TRACE, "CH5   0x%04x \n", buf[i]);
//        }
//        for (int i = sample*2; i < sample*3; i++) {
//            PRINTD(DBG_TRACE, "CH3   0x%04x \n", buf[i]);
//        }
//        //      PRINTD(DBG_TRACE, "\n");
//        for (int i = 0; i < 96; i++) {
//            if (buf[i] == 0xffff)
//                PRINTD(DBG_TRACE, "%d \n", i);
//        }
//        PRINTD(DBG_TRACE, "\n");

//        memset(buf, 0, sizeof(buf));
//        osDelay(1000);
//    }
//    // hal_adc_close(dev);
//    return 0;
//}
//extern void adc_hw_ch_enable(int ch);
//int adc_forcemode_test(void)
//{
//		uint16_t adc;
//    adc_dev_t* dev = hal_adc_open();
//    //adc_hw_ch_enable(15);
//	//hal_adc_force_mode_start(dev, ADC_CH15, &adc);
//    while (1) {
//#if 0
//            for (int i = 0; i < 16 ;i++) {
//                if (i == 8 || i == 9)
//                    continue;
//                for (int j = 0; j < 4; j++) {
//                    uint16_t adc = hal_adc_force_mode_start(dev, i);
//                    PRINTD(DBG_TRACE, "adc id %d 0x%04x\n",i, adc);
//                    }
//                 PRINTD(DBG_TRACE, "\n");
//                //adc_force_disable();
//                osDelay(10);
//            }
//#endif
//#if 1
//        
//				#if 1
//        for (int i = 0; i < 4; i++) {
//            hal_adc_force_mode_start(dev, ADC_CH5, &adc);
//            PRINTD(DBG_TRACE, "adc id %d 0x%04x\n", ADC_CH5, adc);
//        }
//        osDelay(2000);
//        for (int i = 0; i < 4; i++) {
//            hal_adc_force_mode_start(dev, ADC_CH14, &adc);
//            PRINTD(DBG_TRACE, "adc id %d 0x%04x\n", ADC_CH14, adc);
//        }
//        osDelay(2000);
//				#endif
//                
//        for (int i = 0; i < 8; i++) {
//            hal_adc_force_mode_start(dev, ADC_CH15, &adc);
//            PRINTD(DBG_TRACE, "adc id %d 0x%04x\n", ADC_CH15, adc);
//            //osDelay(200);
//        }
//        //                  adc = hal_adc_force_mode_start(dev, 2);
//        // PRINTD(DBG_TRACE, "adc id %d 0x%04x\n",2, adc);
//#endif
//        PRINTD(DBG_TRACE, "\n");
//        PRINTD(DBG_TRACE, "\n");

//        osDelay(1000);
//    }
//    return 0;
//}

//int mouse_test(void)
//{
//    mouse_dev_t* dev = hal_mouse_open(0, NULL);
//    if (!dev) {
//        PRINTD(DBG_TRACE, "failed to open mouse\n");
//        return -1;
//    }
//    mouse_sample_interval(0x3ff);
//    mouse_led_interval(0x64);
//    mouse_set_report_interval(0x1000);
//    hal_mouse_enable(dev);
//    return 0;
//}
//extern int stop;
//int sync7816_test(void)
//{

//    
//    sync7816_dev_t* dev = hal_sync7816_open(CNT_PIN0, CNT_PIN2, CNT_PIN4, 16000);
//    if (dev == NULL)
//        return -1;
//    uint8_t val = 0;
//    uint32_t data;
//    //WR_WORD(0x20f800, 1);
//    hal_sync7816_answer_to_rst(dev, &data);
//    
//    PRINTD(DBG_TRACE, "atr= %x\n", data);
//		
//    osDelay(1000);
//		
//    //WR_WORD(0x20f800, 2);
//    hal_sync7816_answer_to_rst(dev, &data);
//    PRINTD(DBG_TRACE, "atr= %x\n", data);
//	//PRINTD(DBG_TRACE, "a\n");	
//    val = 0;
//    osDelay(1000);
//    
//	//while(1);
//    //WR_WORD(0x20f800, 3);
//    fm4428_read_byte(dev, 1, 1, &val);
//    PRINTD(DBG_TRACE, "read byte %x\n", val);
//    osDelay(1000);
//    fm4428_unlock(dev, 0xff, 0xff);
//    osDelay(1000);
//    uint32_t addr = 498;
//    fm4428_read_byte(dev, addr, 1, &val);
//    
//		//while(stop);//no crash
//    PRINTD(DBG_TRACE, "read byte %x\n", val);
//	//while(stop);//	no crash
//    //while(stop);//crash after first read
//    osDelay(1000);
//    //while(stop);
//    //osDelay(10);
//    //while(stop);//crash after first read
//    fm4428_write_byte(dev, addr, val + 1);
//    osDelay(1000);
//    
//    //osDelay(10);
//    fm4428_read_byte(dev, addr, 1, &val);
//    PRINTD(DBG_TRACE, "read byte %x\n", val);
//    //osDelay(1000);
//    
//    //while(stop);
//    //while(stop);// crash after first read
//    hal_sync7816_stop(dev);
//    return 0;
//}

int kb_test(void)
{
    kb_dev_t *dev = hal_kb_open(3, 5, app_msg_q_id);
    if (!dev) {
        PRINTD(DBG_TRACE, "fail to open keyboard \n");  
        return -1;
    }
    hal_kb_enable(dev);
    return 0;
}

//static void ir_send(ir_dev_t *dev)
//{
//    uint32_t len = 16;
//    uint32_t buf[16] = {140000, 70000, 140000, 70000,140000, 70000,140000, 70000,140000, 70000,140000, 70000,140000, 70000,140000, 70000,};

//    
//    int ret = hal_ir_send(dev, buf, len);



//    PRINTD(DBG_TRACE, "len %d ret %d\n", len, ret);
//}

//int ir_send_test()
//{
//    ir_dev_t *dev ;
//    dev= hal_ir_open(IR0_ID, CNT2_ID, CNT_PIN6, CNT_PIN3);
//    if (!dev) {
//        PRINTD(DBG_TRACE, "fail to open ir \n");    
//        return -1;
//    }
//    ir_dev = dev;
//    ir_send(dev);
//    osDelay(1000);
//    
//    ir_send(dev);

//    osDelay(1000);
//    ir_send(dev);
//    hal_ir_close(dev);
//    ir_dev = NULL;
//    return 0;
//}
static void ir_send_repeat(ir_dev_t *dev)
{
    uint32_t len = 16;
    uint32_t buf[16] = {140000, 70000, 140000, 70000,140000, 70000,140000, 70000,140000, 70000,140000, 70000,140000, 70000,140000, 70000,};

    PRINTD(DBG_TRACE, "ir_send_repeat: len %d\n", len);
    int ret = hal_ir_send_repeat(dev, buf, len, buf, len);    
}

int ir_send_repeat_test(void)
{
    ir_dev = hal_ir_open(IR0_ID, CNT2_ID, CNT_PIN6, CNT_PIN3);
    if (!ir_dev) {
        PRINTD(DBG_TRACE, "fail to open ir \n");    
    }
    hal_ir_set_clk(ir_dev, 38000); 
    ir_send_repeat(ir_dev);
//    osDelay(1000);
//    //ir_send_repeat(dev);
//    hal_ir_close(dev);
//    ir_dev = NULL;
    
    return 0;
}

//static void ir_recv(ir_dev_t *dev)
//{
//    //uint32_t buf[64] = {0};
//    uint32_t sz = 0;
//    PRINTD(DBG_TRACE, "start recv \n");
//    hal_ir_recv(dev, ir_buf, sizeof(ir_buf)/sizeof(ir_buf[0]), &sz);
//    //uint32_t sz = hal_ir_parse_data(dev);
//    PRINTD(DBG_TRACE, "sz %d \n", sz);
//    PRINTD(DBG_TRACE, "rising %d failing %d \n", dev->rising_cnt, dev->failing_cnt); 
//    for (int i = 0; i < sz; i++) {
//        PRINTD(DBG_TRACE, "%d ", ir_buf[i]);
//    }
//    PRINTD(DBG_TRACE, "\n");    
//}
//int ir_recv_test(void)
//{
//    ir_dev_t *dev ;
//    dev= hal_ir_open(IR0_ID, CNT2_ID, CNT_PIN2, CNT_PIN4);
//    if (!dev) {
//        PRINTD(DBG_TRACE, "fail to open ir \n");    
//    }
//    ir_dev = dev;
//    ir_recv(dev);
//    osDelay(1000);
//    ir_recv(dev);
//    osDelay(1000);
//    ir_recv(dev);
//    hal_ir_close(dev);
//    ir_dev = NULL;
//    return 0;
//}

//static void ir_recv_freq(ir_dev_t *dev)
//{
//    //uint32_t buf[256] = {0};
//    uint32_t sz = 0;
//    PRINTD(DBG_TRACE, "start recv freq\n");
//    hal_ir_recv_freq(dev, ir_buf, sizeof(ir_buf)/sizeof(ir_buf[0]), &sz);
//    //uint32_t sz = hal_ir_parse_data(dev);
//    PRINTD(DBG_TRACE, "sz %d \n", sz);
//    PRINTD(DBG_TRACE, "rising %d failing %d \n", dev->rising_cnt, dev->failing_cnt); 
//    for (int i = 0; i < sz; i++) {
//        PRINTD(DBG_TRACE, "%d ", ir_buf[i]);
//    }
//    PRINTD(DBG_TRACE, "\n");    
//    
//}
//int ir_recv_freq_test(void)
//{
//    ir_dev_t *dev ;
//    dev= hal_ir_open(IR0_ID, CNT2_ID, CNT_PIN2, CNT_PIN4);
//    if (!dev) { 
//        PRINTD(DBG_TRACE, "fail to open ir \n");    
//        return -1;
//    }
//    ir_dev = dev;
//    ir_recv_freq(dev);
//    
//    osDelay(1000);
//    ir_recv_freq(dev);
//    osDelay(1000);
//    ir_recv_freq(dev);
//    hal_ir_close(dev);
//    ir_dev = NULL;
//    return 0;
//}
static void drv_test_task(const void *arg)
{
	while (1) {
		PRINTD(DBG_TRACE, "drv_test_task\r\n");
		osEvent evt;

		evt = osMessageGet(app_msg_q_id, osWaitForever);
		if (evt.status != osEventMessage) {
			PRINTD(DBG_TRACE, "evt is  not msg 0x%x...\r\n", evt.status);
			continue;
		}
		PRINTD(DBG_TRACE, "get msg\r\n");

		uint32_t msg = evt.value.v;
		if (msg & KB_MSG_BASE) {
			uint32_t keycode = hal_kb_get_key_code(msg);
			uint32_t keyevt = hal_kb_get_key_evt(msg);
			
			PRINTD(DBG_TRACE, "keycode %d  evt 0x%x...\r\n", keycode, keyevt);
            if (keyevt == KB_MSG_PRESS)
            {
                PRINTD(DBG_TRACE, "PRESS\r\n");
            }
            else if (keyevt == KB_MSG_RELEASE)
            {
                PRINTD(DBG_TRACE, "RELEASE\r\n");
            }
		} 
	}    
}
int drv_test_init(void)
{
    app_msg_q_id = osMessageCreate(osMessageQ(app_msg), NULL);
    osThreadDef_t def;

    def.pthread = drv_test_task;
    def.instances = 1;
    def.tpriority = (osPriority)0;
    def.stacksize = 512; 

    osThreadCreate(&def, NULL);
    
    return 0;
}

//#ifdef DRV_FLASH_TEST
//#define PAGE_SIZE 256
//static unsigned char buf[PAGE_SIZE];                           
//static unsigned char erase_buf[PAGE_SIZE]; 
//extern uint32_t flash_test_fun_list[];
//extern uint32_t flash_test_fun_len;

//int flash_fun_test(void)
//{
//    while(1) {
//	for (int i = 0; i < flash_test_fun_len; i++) {
//        void (*fun)(int) =  (void (*)(int))flash_test_fun_list[i];
//        fun(0);
//        osDelay(100);
//    }

//    }
//}
//int flash_test(void)
//{
//    //if (!spi_flash_init())
//     //   return -1;


//    uint32_t ret = 0;
//    uint32_t n;
//    uint32_t addr = 0x00000;
//    uint32_t len = 0x80000;
//	uint32_t err = 0;
//	//return;
//		for (n = 0; n < PAGE_SIZE; n++) {
//		erase_buf[n] = 0xFF;
//	}
//	//return -3;
//	for (n = 0; n < PAGE_SIZE; n++) {
//		buf[n] = (unsigned char)n;
//	}
//    	uint32_t pri_mask = __get_PRIMASK();


//	/// mask interrupt 
//	__set_PRIMASK(1);

//	spi_flash_xip_disable();
//	//spi_flash_deinit();

//	for (n = (addr); n < (addr + len); n += 0x1000) {
//		spi_flash_sector_erase(n, 0x1000);                          // Test Sector Erase
//	}

//	for (n = addr; n < (addr + len); n += PAGE_SIZE) {
//		unsigned long res;
//		res = spi_flash_verify(n, PAGE_SIZE, erase_buf);
//		if (res != (n+PAGE_SIZE)) {

//			ret = -1;
//      goto out;
//		}
//	}
//	
//  //  PRINTD(DBG_TRACE, "Erase Verify %d \r\n",ret);
//	for (n = addr; n < (addr + len); n += PAGE_SIZE) {
//		spi_flash_prog_page(n, buf, PAGE_SIZE); // Test Page Programming
//	}

//	for (n = addr; n < (addr + len); n += PAGE_SIZE) {
//		unsigned long res;
//		res = spi_flash_verify(n, PAGE_SIZE, buf);
//		if (res != (n+PAGE_SIZE)) {
//			ret = -1;
//			break;
//		}
//	}
//    //PRINTD(DBG_TRACE, "Program Verify %d \r\n",ret);
//out:
//    spi_flash_xip_enable();
//    __set_PRIMASK(pri_mask);
//		return ret;
//    
//}
//#endif
//#if 0
//int sleep_test(void)
//{
//    hal_gpio_pin_cfg(CFG_GPIO_0_2);
//    hal_gpio_pin_cfg(CFG_GPIO_2_1);
//    //WR_WORD(0x20FFF8, 0);
//    //WR_WORD(0x20FFF4, 0);
//    return 0;
//}

//void pm_trace(int index, uint32_t value)
//{
//    //if (index < 16)
//    //    WR_WORD(0x20FF80 + index*4, value);

//    
//}
//#endif
