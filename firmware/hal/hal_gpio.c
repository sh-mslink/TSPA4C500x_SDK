/**
 ****************************************************************************************
 *
 * @file hal_gpio.c
 *
 * @brief Platform GPIO functions  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "in_arm.h"
#include "in_mmap.h"
#include "in_irq.h"
#include "in_debug.h"

#include ".\hal\hal_gpio.h"
#include ".\hal\hal_clk.h"
#include ".\hal\hal_power.h"

/*
 * Types
 ****************************************************************************************
 */

typedef struct {
	void *arg;
	void (*callback)(void *);
} callback_t;

typedef struct {
	int in_use;
	callback_t pin[6];
} gpio_int_grp_0_t;

typedef struct {
	int in_use;
	callback_t pin[9];
} gpio_int_grp_1_t;

typedef struct {
	int in_use;
	callback_t pin[9];
} gpio_int_grp_2_t;

typedef struct {
	int in_use;
	callback_t pin[6];
} gpio_int_grp_3_t;

typedef struct {
	int in_use;
	callback_t pin[2];
} gpio_int_grp_4_t;

/*
 * Static Variables
 ****************************************************************************************
 */

static gpio_int_grp_0_t g_gio_0 = {0};
static gpio_int_grp_1_t g_gio_1 = {0};
static gpio_int_grp_2_t g_gio_2 = {0};
static gpio_int_grp_3_t g_gio_3 = {0};
static gpio_int_grp_4_t g_gio_4 = {0};

/*
 * ISR
 ****************************************************************************************
 */

__irq void Gpio_0_Handler(void)
{
	uint32_t status = gpio_port_0_int_status();

	for (int i = 0; i < 6; i++) {
		if ((status >> i) & 0x1) {
			if (g_gio_0.pin[i].callback) {
				g_gio_0.pin[i].callback(g_gio_0.pin[i].arg);
			}
			gpio_port_0_int_clear(i);
		}
	}
}

__irq void Gpio_1_Handler(void)
{
	uint32_t status = gpio_port_1_int_status();

	for (int i = 0; i < 9; i++) {
		if ((status >> i) & 0x1) {
			if (g_gio_1.pin[i].callback) {
				g_gio_1.pin[i].callback(g_gio_1.pin[i].arg);
			}
			gpio_port_1_int_clear(i);
		}
	}
}

__irq void Gpio_2_Handler(void)
{
	uint32_t status = gpio_port_2_int_status();

	for (int i = 0; i < 9; i++) {
		if ((status >> i) & 0x1) {
			if (g_gio_2.pin[i].callback) {
				g_gio_2.pin[i].callback(g_gio_2.pin[i].arg);
			}
			gpio_port_2_int_clear(i);
		}
	}
}

__irq void Gpio_3_Handler(void)
{
	uint32_t status = gpio_port_3_int_status();

	for (int i = 0; i < 6; i++) {
		if ((status >> i) & 0x1) {
			if (g_gio_3.pin[i].callback) {
				g_gio_3.pin[i].callback(g_gio_3.pin[i].arg);
			}
			gpio_port_3_int_clear(i);
		}
	}
}

__irq void Gpio_4_Handler(void)
{
	uint32_t status = gpio_port_4_int_status();

	for (int i = 0; i < 2; i++) {
		if ((status >> i) & 0x1) {
			if (g_gio_4.pin[i].callback) {
				g_gio_4.pin[i].callback(g_gio_4.pin[i].arg);
			}
			gpio_port_4_int_clear(i);
		}
	}
}

/*
 * APIs
 ****************************************************************************************
 */

void hal_gpio_pin_cfg(uint32_t pin_cfg)
{
#if !CFG_FPGA
	int pin = pin_cfg & 0xF;
	int port = (pin_cfg >> GPIO_CFG_PORT_SHIFT) & 0xF;
	int mux = (pin_cfg >> GPIO_CFG_MUX_SHIFT) & 0xF;
	int oe = (pin_cfg >> GPIO_CFG_OE_IE_SHIFT) & 0x1;
	int ie = (pin_cfg >> (GPIO_CFG_OE_IE_SHIFT+1)) & 0x1;
	int pd = (pin_cfg >> GPIO_CFG_PD_PU_SHIFT) & 0x1;
	int pu = (pin_cfg >> (GPIO_CFG_PD_PU_SHIFT+1)) & 0x1;
	int output = (pin_cfg >> GPIO_CFG_OUTPUT_SHIFT) & 0x1;
	int wup = (pin_cfg >> GPIO_CFG_WUP_SHIFT) & 0x1;
	int latch = (pin_cfg >> GPIO_CFG_LATCH_SHIFT) & 0x1;
	int wup_pol = (pin_cfg >> GPIO_CFG_WUP_POL_SHIFT) & 0x1;

	hal_gpio_pin_mux(port, pin, mux, 0);
	hal_gpio_pad_oe_ie(port, pin, oe, ie); 
	hal_gpio_pad_pd_pu(port, pin, pd, pu); 
	hal_gpio_pad_pc(port, pin, 1);
	hal_gpio_output(port, pin, 0, output);
	hal_gpio_aon_wup(port, pin, wup, wup_pol);
	hal_gpio_aon_latch(port, pin, latch);
#endif
	return;
}

void hal_gpio_pin_dft(uint32_t pin_cfg)
{
#if !CFG_FPGA
	int pin = pin_cfg & 0xF;
	int port = (pin_cfg >> GPIO_CFG_PORT_SHIFT) & 0xF;

	hal_gpio_pin_mux(port, pin, 0, 0);
	hal_gpio_pad_oe_ie(port, pin, 0, 1); 
	hal_gpio_pad_pd_pu(port, pin, 0, 1); 
	hal_gpio_output(port, pin, 0, 0);
	hal_gpio_aon_wup(port, pin, 0, 0);
	hal_gpio_aon_latch(port, pin, 0);
#endif
	return;
}

void hal_gpio_pin_mux(int port, int pin, int mux, int inv)
{
#if !CFG_FPGA
	if (port == GPIO_PORT_0) {
		gpio_port_0_pin_mux(pin, mux, inv);
	} else if (port == GPIO_PORT_1) {
		gpio_port_1_pin_mux(pin, mux, inv);
	} else if (port == GPIO_PORT_2) {
		gpio_port_2_pin_mux(pin, mux, inv);
	} else if (port == GPIO_PORT_3) {
		gpio_port_3_pin_mux(pin, mux, inv);
	} else {
		gpio_port_4_pin_mux(pin, mux, inv);
	}
#endif	// !CFG_FPGA
	return;
}

void hal_gpio_output(int port, int pin, int high, int en)
{
#if !CFG_FPGA
	if (port == GPIO_PORT_0) {
		gpio_port_0_output(pin, high, en);
	} else if (port == GPIO_PORT_1) {
		gpio_port_1_output(pin, high, en);
	} else if (port == GPIO_PORT_2) {
		gpio_port_2_output(pin, high, en);
	} else if (port == GPIO_PORT_3) {
		gpio_port_3_output(pin, high, en);
	} else {
		gpio_port_4_output(pin, high, en);
	}
#endif	// !CFG_FPGA

	return;
}

int hal_gpio_input(int port, int pin)
{
#if !CFG_FPGA
	int high;

	if (port == GPIO_PORT_0) {
		high = gpio_port_0_input(pin);
	} else if (port == GPIO_PORT_1) {
		high = gpio_port_1_input(pin);
	} else if (port == GPIO_PORT_2) {
		high = gpio_port_2_input(pin);
	} else if (port == GPIO_PORT_3) {
		high = gpio_port_3_input(pin);
	} else {
		high = gpio_port_4_input(pin);
	}

	return high;
#else
	return 1;
#endif	// !CFG_FPGA

}

void hal_gpio_pad_oe_ie(int port, int pin, int oe, int ie)
{
#if !CFG_FPGA
	if (port == GPIO_PORT_0) {
		gpio_port_0_pad_oe_ie(pin, oe, ie);
	} else if (port == GPIO_PORT_1) {
		gpio_port_1_pad_oe_ie(pin, oe, ie);
	} else if (port == GPIO_PORT_2) {
		gpio_port_2_pad_oe_ie(pin, oe, ie);
	} else if (port == GPIO_PORT_3) {
		gpio_port_3_pad_oe_ie(pin, oe, ie);
	} else {
		gpio_port_4_pad_oe_ie(pin, oe, ie);
	}
#endif	// !CFG_FPGA

}

void hal_gpio_pad_pd_pu(int port, int pin, int pd, int pu)
{
#if !CFG_FPGA
	if (port == GPIO_PORT_0) {
		gpio_port_0_pad_pd_pu(pin, pd, pu);
	} else if (port == GPIO_PORT_1) {
		gpio_port_1_pad_pd_pu(pin, pd, pu);
	} else if (port == GPIO_PORT_2) {
		gpio_port_2_pad_pd_pu(pin, pd, pu);
	} else if (port == GPIO_PORT_3) {
		gpio_port_3_pad_pd_pu(pin, pd, pu);
	} else {
		gpio_port_4_pad_pd_pu(pin, pd, pu);
	}
#endif	// !CFG_FPGA

}

void hal_gpio_pad_pc(int port, int pin, int on)
{
#if !CFG_FPGA
	if (port == GPIO_PORT_0) {
		gpio_port_0_pad_pc(pin, on);
	} else if (port == GPIO_PORT_1) {
		gpio_port_1_pad_pc(pin, on);
	} else if (port == GPIO_PORT_2) {
		gpio_port_2_pad_pc(pin, on);
	} else if (port == GPIO_PORT_3) {
		gpio_port_3_pad_pc(pin, on);
	} else {
		gpio_port_4_pad_pc(pin, on);
	}
#endif	// !CFG_FPGA

}

void hal_qspi_pin_cfg(uint32_t pin_cfg)
{
#if !CFG_FPGA
	int pin = pin_cfg & 0xF;
	int mux = (pin_cfg >> QSPI_CFG_MUX_SHIFT) & 0xF;
	int oe = (pin_cfg >> QSPI_CFG_OE_IE_SHIFT) & 0x1;
	int ie = (pin_cfg >> (QSPI_CFG_OE_IE_SHIFT+1)) & 0x1;
	int pd = (pin_cfg >> QSPI_CFG_PD_PU_SHIFT) & 0x1;
	int pu = (pin_cfg >> (QSPI_CFG_PD_PU_SHIFT+1)) & 0x1;

	hal_qspi_pin_mux(pin, mux, 0);
	hal_qspi_pad_oe_ie(pin, oe, ie); 
	hal_qspi_pad_pd_pu(pin, pd, pu); 
	hal_qspi_pad_pc(pin, 1);
#endif	// !CFG_FPGA

	return;
}

void hal_qspi_pin_mux(int pin, int mux, int inv)
{
#if !CFG_FPGA
	gpio_qspi_pin_mux(pin, mux, inv);
#endif	// !CFG_FPGA

	return;
}

void hal_qspi_pin_output(int pin, int out, int en)
{
#if !CFG_FPGA
	gpio_qspi_pin_output(pin, out, en);
#endif	// !CFG_FPGA

	return;
}

void hal_qspi_pad_oe_ie(int pin, int oe, int ie)
{
#if !CFG_FPGA
	gpio_qspi_pin_pad_oe_ie(pin, oe, ie);
#endif	// !CFG_FPGA

}

void hal_qspi_pad_pd_pu(int pin, int pd, int pu)
{
#if !CFG_FPGA
	gpio_qspi_pin_pad_pu_pd(pin, pd, pu);
#endif	// !CFG_FPGA

}

void hal_qspi_pad_pc(int pin, int on)
{
#if !CFG_FPGA
	gpio_qspi_pin_pad_pc(pin, on);
#endif	// !CFG_FPGA

}

void hal_gpio_aon_latch(int port, int pin, int latch)
{
#if !CFG_FPGA

	uint32_t addr;

	if (port == GPIO_PORT_0) {
		addr = AON_REG_GPIO_0_LE_MASKB;
		pin &= AON_REG_GPIO_0_LE_MASKB_CTL_GPIO_0_LE_MASK;
	} else if (port == GPIO_PORT_1) {
		addr = AON_REG_GPIO_1_LE_MASKB;
		pin &= AON_REG_GPIO_1_LE_MASKB_CTL_GPIO_1_LE_MASK;
	} else if (port == GPIO_PORT_2) {
		addr = AON_REG_GPIO_2_LE_MASKB;
		pin &= AON_REG_GPIO_2_LE_MASKB_CTL_GPIO_2_LE_MASK;
	} else if (port == GPIO_PORT_3) {
		addr = AON_REG_GPIO_3_LE_MASKB;
		pin &= AON_REG_GPIO_3_LE_MASKB_CTL_GPIO_3_LE_MASK;
	} else  {
		addr = AON_REG_GPIO_4_LE_MASKB;
		pin &= AON_REG_GPIO_4_LE_MASKB_CTL_GPIO_4_LE_MASK;
	} 

	uint32_t reg = aon_read(addr);
	if (latch)
		reg |= (1 << pin);
	else
		reg &= ~(1 << pin);

	aon_write(addr, reg);
#endif	// !CFG_FPGA

}

void hal_gpio_aon_wup(int port, int pin, int wup, int pol)
{
#if !CFG_FPGA

	uint32_t reg, maskb_addr, wk_addr, pol_addr, wk_shift;

	/// port
	if (port == GPIO_PORT_0) {
		pin &= AON_REG_GPIO_0_LE_MASKB_CTL_GPIO_0_LE_MASK;
		maskb_addr = AON_REG_GPIO_0_LE_MASKB;
		wk_addr = AON_REG_GPIO_WAKEUP_MASK;
		pol_addr = AON_REG_GPIO_WAKEUP_POLARITY;
		wk_shift = 0;
	} else if (port == GPIO_PORT_1) {
		pin &= AON_REG_GPIO_1_LE_MASKB_CTL_GPIO_1_LE_MASK;
		maskb_addr = AON_REG_GPIO_1_LE_MASKB;
		wk_addr = AON_REG_GPIO_WAKEUP_MASK;
		pol_addr = AON_REG_GPIO_WAKEUP_POLARITY;
		wk_shift = 6;
	} else if (port == GPIO_PORT_2) {
		pin &= AON_REG_GPIO_2_LE_MASKB_CTL_GPIO_2_LE_MASK;
		maskb_addr = AON_REG_GPIO_2_LE_MASKB;
		wk_addr = AON_REG_MS_GPIO_WAKEUP_MASK;
		pol_addr = AON_REG_MS_GPIO_WAKEUP_POLARITY;
		wk_shift = 0;
	} else if (port == GPIO_PORT_3) {
		pin &= AON_REG_GPIO_3_LE_MASKB_CTL_GPIO_3_LE_MASK;
		maskb_addr = AON_REG_GPIO_3_LE_MASKB;
		wk_addr = AON_REG_GPIO_WAKEUP_MASK;
		pol_addr = AON_REG_GPIO_WAKEUP_POLARITY;
		wk_shift = 15;
	} else  {
		pin &= AON_REG_GPIO_4_LE_MASKB_CTL_GPIO_4_LE_MASK;
		maskb_addr = AON_REG_GPIO_4_LE_MASKB;
		wk_addr = AON_REG_GPIO_WAKEUP_MASK;
		pol_addr = AON_REG_GPIO_WAKEUP_POLARITY;
		wk_shift = 21;
	} 

	/// DI maskb
	reg = aon_read(maskb_addr);
	if (wup) {
		reg |= (1 << pin);		// latch enable
		reg |= (1 << (pin + AON_REG_GPIO_0_LE_MASKB_CTL_GPIO_0_MASKB_SHIFT)); 	
	} else {
		reg &= ~(1 << pin);
		reg &= ~(1 << (pin + AON_REG_GPIO_0_LE_MASKB_CTL_GPIO_0_MASKB_SHIFT)); 	
	}
	aon_write(maskb_addr, reg);

	/// wake up mask 
	reg = aon_read(wk_addr);
	if (wup) {
		reg &= ~(1 << (pin + wk_shift));
	} else {
		reg |= (1 << (pin + wk_shift));
	}
	aon_write(wk_addr, reg);

	/// wake up polarity 
	reg = aon_read(pol_addr);
	if (wup) {
		if (pol) {
			reg &= ~(1 << (pin + wk_shift));
		} else {
			reg |= (1 << (pin + wk_shift));
		}
	} 
	aon_write(pol_addr, reg);
#endif	// !CFG_FPGA

}

void hal_gpio_aon_out(int port, int pin)
{
#if !CFG_FPGA

	uint32_t addr, reg, shift;

	if (port == GPIO_PORT_0) {
		pin &= AON_REG_GPIO_01_AON_SEL_CTL_GPIO_0_AON_SEL_MASK;
		addr = AON_REG_GPIO_01_AON_SEL;
		shift = AON_REG_GPIO_01_AON_SEL_CTL_GPIO_0_AON_SEL_SHIFT;
	} else if (port == GPIO_PORT_1) {
		pin &= AON_REG_GPIO_01_AON_SEL_CTL_GPIO_1_AON_SEL_MASK;
		addr = AON_REG_GPIO_01_AON_SEL;
		shift = AON_REG_GPIO_01_AON_SEL_CTL_GPIO_1_AON_SEL_SHIFT;
	} else if (port == GPIO_PORT_2) {
		pin &= AON_REG_GPIO_2_ANA_ON_CTL_GPIO_2_ANA_ON_MASK;
		addr = AON_REG_GPIO_2_ANA_ON;
		shift = AON_REG_GPIO_2_ANA_ON_CTL_GPIO_2_ANA_ON_SHIFT;
	} else if (port == GPIO_PORT_3) {
		pin &= AON_REG_GPIO_34_AON_SEL_CTL_GPIO_3_AON_SEL_MASK;
		addr = AON_REG_GPIO_34_AON_SEL;
		shift = AON_REG_GPIO_34_AON_SEL_CTL_GPIO_3_AON_SEL_SHIFT;
	} else  {
		pin &= AON_REG_GPIO_34_AON_SEL_CTL_GPIO_4_AON_SEL_MASK;
		addr = AON_REG_GPIO_34_AON_SEL;
		shift = AON_REG_GPIO_34_AON_SEL_CTL_GPIO_4_AON_SEL_SHIFT;
	} 
	
	reg = aon_read(addr);
	reg |= 1 << (pin + shift);
	aon_write(addr, reg);
#endif	// !CFG_FPGA

}

void hal_gpio_ext_int_clear(int port, int pin)
{
#if !CFG_FPGA

	if (port == GPIO_PORT_0) {
		gpio_port_0_int_clear(pin);
	} else if (port == GPIO_PORT_1) {
		gpio_port_1_int_clear(pin);
	} else if (port == GPIO_PORT_2) {
		gpio_port_2_int_clear(pin);
	} else if (port == GPIO_PORT_3) {
		gpio_port_3_int_clear(pin);
	} else if (port == GPIO_PORT_4) {
		gpio_port_4_int_clear(pin);
	}
#endif	// !CFG_FPGA

}
void hal_gpio_ext_int_en(int port, int pin, int pol, void *arg, void (*callback)(void *))
{
#if !CFG_FPGA

	/// Turn on gpio intr ctrl clock
	hal_clk_gpio_intr(port, 1);

	if (port == GPIO_PORT_0) {
		g_gio_0.pin[pin].arg = arg;
		g_gio_0.pin[pin].callback = callback;
		g_gio_0.in_use |= (1 << pin);

		/// mux - gpio, no inv
		gpio_port_0_pin_mux(pin, 0, 0);

		/// output - off
		gpio_port_0_output(pin, 0, 0);

		/// pad - ie
		gpio_port_0_pad_oe_ie(pin, 0, 1);

		/// pad - no pull
		gpio_port_0_pad_pd_pu(pin, 0, 0);

		/// polarity
		gpio_port_0_int_polarity(pin, pol);
		gpio_port_0_int_clear(pin);
		gpio_port_0_int_unmask(pin);
        NVIC_SetPriority(Gpio0_IRQn, IRQ_PRI_Normal);
		NVIC_EnableIRQ(Gpio0_IRQn);
	} else if (port == GPIO_PORT_1) {
		g_gio_1.pin[pin].arg = arg;
		g_gio_1.pin[pin].callback = callback;
		g_gio_1.in_use |= (1 << pin);

		/// mux - gpio, no inv
		gpio_port_1_pin_mux(pin, 0, 0);

		/// output - off
		gpio_port_1_output(pin, 0, 0);

		/// pad - ie
		gpio_port_1_pad_oe_ie(pin, 0, 1);

		/// pad - no pull
		gpio_port_1_pad_pd_pu(pin, 0, 0);

		/// polarity
		gpio_port_1_int_polarity(pin, pol);
		gpio_port_1_int_clear(pin);
		gpio_port_1_int_unmask(pin);
        	NVIC_SetPriority(Gpio1_IRQn, IRQ_PRI_Normal);
		NVIC_EnableIRQ(Gpio1_IRQn);
		
	} else if (port == GPIO_PORT_2) {
		g_gio_2.pin[pin].arg = arg;
		g_gio_2.pin[pin].callback = callback;
		g_gio_2.in_use |= (1 << pin);

		/// mux - gpio, no inv
		gpio_port_2_pin_mux(pin, 0, 0);

		/// output - off
		gpio_port_2_output(pin, 0, 0);

		/// pad - ie
		gpio_port_2_pad_oe_ie(pin, 0, 1);

		/// pad - no pull
		gpio_port_2_pad_pd_pu(pin, 0, 0);

		/// polarity
		gpio_port_2_int_polarity(pin, pol);
		gpio_port_2_int_clear(pin);
		gpio_port_2_int_unmask(pin);
        NVIC_SetPriority(Gpio2_IRQn, IRQ_PRI_Normal);
		NVIC_EnableIRQ(Gpio2_IRQn);
	} else if (port == GPIO_PORT_3) {
		g_gio_3.pin[pin].arg = arg;
		g_gio_3.pin[pin].callback = callback;
		g_gio_3.in_use |= (1 << pin);

		/// mux - gpio, no inv
		gpio_port_3_pin_mux(pin, 0, 0);

		/// output - off
		gpio_port_3_output(pin, 0, 0);

		/// pad - ie
		gpio_port_3_pad_oe_ie(pin, 0, 1);

		/// pad - no pull
		gpio_port_3_pad_pd_pu(pin, 0, 0);

		/// polarity
		gpio_port_3_int_polarity(pin, pol);
		gpio_port_3_int_clear(pin);
		gpio_port_3_int_unmask(pin);
        NVIC_SetPriority(Gpio3_IRQn, IRQ_PRI_Normal);
		NVIC_EnableIRQ(Gpio3_IRQn);
	} else  {
		g_gio_4.pin[pin].arg = arg;
		g_gio_4.pin[pin].callback = callback;
		g_gio_4.in_use |= (1 << pin);

		/// mux - gpio, no inv
		gpio_port_4_pin_mux(pin, 0, 0);

		/// output - off
		gpio_port_4_output(pin, 0, 0);

		/// pad - ie
		gpio_port_4_pad_oe_ie(pin, 0, 1);

		/// pad - no pull
		gpio_port_4_pad_pd_pu(pin, 0, 0);

		/// polarity
		gpio_port_4_int_polarity(pin, pol);
		gpio_port_4_int_clear(pin);
		gpio_port_4_int_unmask(pin);
        NVIC_SetPriority(Gpio4_IRQn, IRQ_PRI_Normal);
		NVIC_EnableIRQ(Gpio4_IRQn);
	} 
#endif	// !CFG_FPGA

}

void hal_gpio_ext_int_dis(int port, int pin)
{
#if !CFG_FPGA

	if (port == GPIO_PORT_0) {
		g_gio_0.in_use &= ~(1 << pin);
		gpio_port_0_int_mask(pin);
		if (g_gio_0.in_use == 0) {
			
			hal_clk_gpio_intr(0, 0);
            NVIC_DisableIRQ(Gpio0_IRQn);
                    
		}
		/// pad - ie
		gpio_port_0_pad_oe_ie(pin, 0, 0);
	} else if (port == GPIO_PORT_1) {
		g_gio_1.in_use &= ~(1 << pin);
		gpio_port_1_int_mask(pin);
		if (g_gio_1.in_use == 0) {
			
			hal_clk_gpio_intr(1, 0);
            NVIC_DisableIRQ(Gpio1_IRQn);
		}
		/// pad - ie
		gpio_port_1_pad_oe_ie(pin, 0, 0);
	} else if (port == GPIO_PORT_2) {
		g_gio_2.in_use &= ~(1 << pin);
		gpio_port_2_int_mask(pin);
		if (g_gio_2.in_use == 0) {
			
			hal_clk_gpio_intr(2, 0);
            NVIC_DisableIRQ(Gpio2_IRQn);
		}
		/// pad - ie
		gpio_port_2_pad_oe_ie(pin, 0, 0);
	} else if (port == GPIO_PORT_3) {
		g_gio_3.in_use &= ~(1 << pin);
		gpio_port_3_int_mask(pin);
		if (g_gio_3.in_use == 0) {
			
			hal_clk_gpio_intr(3, 0);
            NVIC_DisableIRQ(Gpio3_IRQn);
		}
		/// pad - ie
		gpio_port_3_pad_oe_ie(pin, 0, 0);
	} else  {
		g_gio_4.in_use &= ~(1 << pin);
		gpio_port_4_int_mask(pin);
		if (g_gio_4.in_use == 0) {
			
			hal_clk_gpio_intr(4, 0);
            NVIC_DisableIRQ(Gpio4_IRQn);
		}
		/// pad - ie
		gpio_port_4_pad_oe_ie(pin, 0, 0);
	} 
#endif	// !CFG_FPGA

}

void hal_gpio_ext_int_mask(int port, int pin)
{
#if !CFG_FPGA

	if (port == GPIO_PORT_0) {
		gpio_port_0_int_mask(pin);
	} else if (port == GPIO_PORT_1) {
		gpio_port_1_int_mask(pin);
	} else if (port == GPIO_PORT_2) {
		gpio_port_2_int_mask(pin);
	} else if (port == GPIO_PORT_3) {
		gpio_port_3_int_mask(pin);
	} else  {
		gpio_port_4_int_mask(pin);
	} 
#endif	// !CFG_FPGA

}

void hal_gpio_ext_int_unmask(int port, int pin)
{
#if !CFG_FPGA

	if (port == GPIO_PORT_0) {
		gpio_port_0_int_unmask(pin);
	} else if (port == GPIO_PORT_1) {
		gpio_port_1_int_unmask(pin);
	} else if (port == GPIO_PORT_2) {
		gpio_port_2_int_unmask(pin);
	} else if (port == GPIO_PORT_3) {
		gpio_port_3_int_unmask(pin);
	} else  {
		gpio_port_4_int_unmask(pin);
	} 
#endif	// !CFG_FPGA

}

#if CFG_PM_EN

struct gpio_pm_regs {
	uint32_t gpio0_pin_mux;
	uint32_t gpio1_pin_mux;
	uint32_t gpio1_cont_pin_mux;
	uint32_t gpio2_pin_mux;
	uint32_t gpio2_cont_pin_mux;
	uint32_t gpio3_pin_mux;
	uint32_t gpio4_pin_mux;

	uint32_t gpio0_output;
	uint32_t gpio1_output;
	uint32_t gpio2_output;
	uint32_t gpio34_output;

	uint32_t gpio0_oe_ie;
	uint32_t gpio1_oe_ie;
	uint32_t gpio2_oe_ie;
	uint32_t gpio3_oe_ie;
	uint32_t gpio4_oe_ie;

	uint32_t gpio0_pd_pu;
	uint32_t gpio1_pd_pu;
	uint32_t gpio2_pd_pu;
	uint32_t gpio3_pd_pu;
	uint32_t gpio4_pd_pu;

	uint32_t gpio01_pc;
	uint32_t gpio234_pc;

	uint32_t gpio0_int_pol;
	uint32_t gpio1_int_pol;
	uint32_t gpio2_int_pol;
	uint32_t gpio3_int_pol;
	uint32_t gpio4_int_pol;
};

static struct gpio_pm_regs g_reg;

void hal_gpio_suspend(void)
{
	g_reg.gpio0_pin_mux = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_0);		
	g_reg.gpio1_pin_mux = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_1);		
	g_reg.gpio1_cont_pin_mux = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_1_CONT);		
	g_reg.gpio2_pin_mux = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_2);		
	g_reg.gpio2_cont_pin_mux = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_2_CONT);		
	g_reg.gpio3_pin_mux = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_3);
	g_reg.gpio4_pin_mux = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_4);
		
	g_reg.gpio0_output = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT);
	g_reg.gpio1_output = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT);
	g_reg.gpio2_output = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT);
	g_reg.gpio34_output = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT);

	g_reg.gpio0_oe_ie = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_0_OE_IE);
	g_reg.gpio1_oe_ie = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_1_OE_IE);
	g_reg.gpio2_oe_ie = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_2_OE_IE);
	g_reg.gpio3_oe_ie = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_3_OE_IE);
	g_reg.gpio4_oe_ie = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_4_OE_IE);

	g_reg.gpio0_pd_pu = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_0_PD_PU);
	g_reg.gpio1_pd_pu = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_1_PD_PU);
	g_reg.gpio2_pd_pu = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_2_PD_PU);
	g_reg.gpio3_pd_pu = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_3_PD_PU);
	g_reg.gpio4_pd_pu = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_4_PD_PU);

	g_reg.gpio01_pc = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_PC_01);
	g_reg.gpio234_pc = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_PC_234);

	g_reg.gpio0_int_pol = RD_WORD(GLOBAL_REG_INTR_GPIO_0_POLARITY);
	g_reg.gpio1_int_pol = RD_WORD(GLOBAL_REG_INTR_GPIO_1_POLARITY);
	g_reg.gpio2_int_pol = RD_WORD(GLOBAL_REG_INTR_GPIO_2_POLARITY);
	g_reg.gpio3_int_pol = RD_WORD(GLOBAL_REG_INTR_GPIO_3_POLARITY);
	g_reg.gpio4_int_pol = RD_WORD(GLOBAL_REG_INTR_GPIO_4_POLARITY);

}

void hal_gpio_resume(void)
{
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_0, g_reg.gpio0_pin_mux);		
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_1, g_reg.gpio1_pin_mux );		
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_1_CONT, g_reg.gpio1_cont_pin_mux);		
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_2, g_reg.gpio2_pin_mux);		
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_2_CONT, g_reg.gpio2_cont_pin_mux);		
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_3, g_reg.gpio3_pin_mux);
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_4, g_reg.gpio4_pin_mux);
		
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT, g_reg.gpio0_output);
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT, g_reg.gpio1_output);
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT, g_reg.gpio2_output);
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT, g_reg.gpio34_output);

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_0_OE_IE, g_reg.gpio0_oe_ie);
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_1_OE_IE, g_reg.gpio1_oe_ie);
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_2_OE_IE, g_reg.gpio2_oe_ie);
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_3_OE_IE, g_reg.gpio3_oe_ie);
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_4_OE_IE, g_reg.gpio4_oe_ie);

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_0_PD_PU, g_reg.gpio0_pd_pu);
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_1_PD_PU, g_reg.gpio1_pd_pu);
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_2_PD_PU, g_reg.gpio2_pd_pu);
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_3_PD_PU, g_reg.gpio3_pd_pu);
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_4_PD_PU, g_reg.gpio4_pd_pu);

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_PC_01, g_reg.gpio01_pc);
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_PC_234, g_reg.gpio234_pc);

	WR_WORD(GLOBAL_REG_INTR_GPIO_0_POLARITY, g_reg.gpio0_int_pol);
	WR_WORD(GLOBAL_REG_INTR_GPIO_1_POLARITY, g_reg.gpio1_int_pol);
	WR_WORD(GLOBAL_REG_INTR_GPIO_2_POLARITY, g_reg.gpio2_int_pol);
	WR_WORD(GLOBAL_REG_INTR_GPIO_3_POLARITY, g_reg.gpio3_int_pol);
	WR_WORD(GLOBAL_REG_INTR_GPIO_4_POLARITY, g_reg.gpio4_int_pol);
}
#endif
