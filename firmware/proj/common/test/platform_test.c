
#include ".\ble\inb_api.h"

void test0()
{
#if 0

	uint32_t val;
	
	// For test mode and WFI clock gating 
	WR_WORD(0x20c000,0);
	WR_WORD(0x20c004,0);
	
	// GPIO_1_0 = rx
	// GPIO_0_2 = tx
	gpio_set_pin_mux(1, 0, 1, 0);
	gpio_pad_oe_ie(1, 0, 0, 1);
	gpio_pad_pd_pu(1, 0, 0, 1);
	gpio_pad_pc(1, 0, 1);

	gpio_set_pin_mux(0, 2, 1, 0);
	gpio_pad_oe_ie(0, 2, 1, 0);
	gpio_pad_pd_pu(0, 2, 0, 0);
	gpio_pad_pc(0, 2, 1);

#endif
}

void test1()
{
#if 0

		union test_cmd reg;
		reg.val = RD_WORD(0x20c000);
		uint32_t oper = reg.u.oper;
		
		#if allow_sleep
		if 	(RD_WORD(0x20c004)) {
			__DSB();
			__ISB();
			__WFI();
		}
		#endif
		
		if (oper != 0) {
			PRINTD(DBG_ERR, "reg.val = %08x\r\n", reg.val);

			WR_WORD(0x20c000, 0);

			inb_test_mode_t tmode;
			uint16_t nb_rx_pkt = 0;

			tmode.test_mode = oper;
			tmode.channel = reg.u.ch;
			tmode.tx_data_length = reg.u.tx_len; 
			tmode.tx_pkt_payload = reg.u.tx_pld; 
			tmode.phy = reg.u.phy; 
			tmode.modulation_idx = reg.u.midx; 

			if ((res = inb_test(&tmode, &nb_rx_pkt)) != INB_ERR_NO_ERROR) {
				PRINTD(DBG_ERR, "test failed,%d\r\n", res);
			}
			#if allow_sleep
			if (RD_WORD(0x20c004)){
				__DSB();
				__ISB();
				__WFI();
			}
			#endif
			aon_write(0x20c008, nb_rx_pkt);
		}

#endif
}

void test2()
{
#if 0
	
	aon_write(0x7040,0xffffffff);
	WR_WORD(0x441262C0,1);
	WR_WORD(0x44126290, 1);
#endif
}
