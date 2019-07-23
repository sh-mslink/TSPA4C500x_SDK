/**
 ****************************************************************************************
 *
 * @file hal_gpio.h
 *
 * @brief HAL GPIO  
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2019
 *
 ****************************************************************************************
 */
#ifndef HAL_GPIO_H
#define HAL_GPIO_H

/**
 ****************************************************************************************
 * @defgroup HAL_GPIO Platform gpio configuration  
 * @ingroup HAL
 * @brief  HAL_GPIO
 * @{
 ****************************************************************************************
 */

#include "in_mmap.h"

/*
 * Defines
 ****************************************************************************************
 */




#define GPIO_CFG_PIN_SHIFT 0
#define GPIO_CFG_PORT_SHIFT 4
#define GPIO_CFG_MUX_SHIFT 8
#define GPIO_CFG_OE_IE_SHIFT 12
#define GPIO_CFG_PD_PU_SHIFT 16
#define GPIO_CFG_OUTPUT_SHIFT 20
#define GPIO_CFG_WUP_SHIFT 21
#define GPIO_CFG_LATCH_SHIFT 22
#define GPIO_CFG_WUP_POL_SHIFT 23

#define QSPI_CFG_PIN_SHIFT 0
#define QSPI_CFG_PIN_MASK 0xF
#define QSPI_CFG_MUX_SHIFT 4
#define QSPI_CFG_MUX_MASK 0xF
#define QSPI_CFG_OE_IE_SHIFT 8
#define QSPI_CFG_OE_IE_MASK 0xF
#define QSPI_CFG_PD_PU_SHIFT 12
#define QSPI_CFG_PD_PU_MASK 0xF

#define GPIO_PORT_0_INT_SHIFT 6
#define GPIO_PORT_0_INT_MASK 0x3F
#define GPIO_PORT_1_INT_SHIFT 9
#define GPIO_PORT_1_INT_MASK 0x1FF
#define GPIO_PORT_2_INT_SHIFT 9
#define GPIO_PORT_2_INT_MASK 0x1FF
#define GPIO_PORT_3_INT_SHIFT 6
#define GPIO_PORT_3_INT_MASK 0x3F
#define GPIO_PORT_4_INT_SHIFT 2
#define GPIO_PORT_4_INT_MASK 0x3

/*
 * Enumerations
 ****************************************************************************************
 */
enum gpio_port {
	GPIO_PORT_0,
	GPIO_PORT_1,
	GPIO_PORT_2,
	GPIO_PORT_3,
	GPIO_PORT_4,
};

enum gpio_pin {
	GPIO_PIN_0,
	GPIO_PIN_1,
	GPIO_PIN_2,
	GPIO_PIN_3,
	GPIO_PIN_4,
	GPIO_PIN_5,
	GPIO_PIN_6,
	GPIO_PIN_7,
	GPIO_PIN_8,
};

enum gpio_mux {
	GPIO_MUX_0,
	GPIO_MUX_1,
	GPIO_MUX_2,
	GPIO_MUX_3,
	GPIO_MUX_4,
	GPIO_MUX_5,
	GPIO_MUX_6,
};

enum gpio_mux_tbl {
	GPIO_MUX_O_UART_0_RTS = GPIO_MUX_1,
	GPIO_MUX_I_UART_0_CTS = GPIO_MUX_1,
	GPIO_MUX_O_UART_0_TX = GPIO_MUX_1,
	GPIO_MUX_I_WLAN_TX_BKUP0 = GPIO_MUX_1,
	GPIO_MUX_I_WLAN_RX_BKUP0 = GPIO_MUX_1,
	GPIO_MUX_I_UART_0_RX1 = GPIO_MUX_1,
	GPIO_MUX_IO_JTAG_TMS_SWDIO = GPIO_MUX_1,
	GPIO_MUX_I_JTAG_TCKSCK1 = GPIO_MUX_1,
	GPIO_MUX_O_JTAG_TDO = GPIO_MUX_1,
	GPIO_MUX_I_JTAG_TDI1 = GPIO_MUX_1,
	GPIO_MUX_O_UART_1_RTS = GPIO_MUX_1,
	GPIO_MUX_I_UART_1_CTS1 = GPIO_MUX_1,
	GPIO_MUX_O_UART_1_TX = GPIO_MUX_1,
	GPIO_MUX_I_UART1_RX1 = GPIO_MUX_1,
	GPIO_MUX_O_UART_1_TX_BKUP = GPIO_MUX_1,
	GPIO_MUX_O_UART_0_TX_BKUP = GPIO_MUX_1,
	GPIO_MUX_O_UART_0_RX_BKUP = GPIO_MUX_1,
	GPIO_MUX_I_UART_1_RX_BKUP = GPIO_MUX_1,
	GPIO_MUX_O_SPI_MSTR_CLK = GPIO_MUX_1,
	GPIO_MUX_I_SPI_MSTR_MISO1 = GPIO_MUX_1,
	GPIO_MUX_O_SPI_MSTR_MOSI = GPIO_MUX_1,
	GPIO_MUX_O_SPI_MSTR_SSN0 = GPIO_MUX_1,

	GPIO_MUX_O_KEYBOARD_0 = GPIO_MUX_2,
	GPIO_MUX_O_KEYBOARD_1 = GPIO_MUX_2,	
	GPIO_MUX_O_KEYBOARD_25 = GPIO_MUX_2,
	GPIO_MUX_O_KEYBOARD_4 = GPIO_MUX_2,
	GPIO_MUX_I_KEYBOARD_22 = GPIO_MUX_2,
	GPIO_MUX_I_KEYBOARD_24 = GPIO_MUX_2,
	GPIO_MUX_O_KEYBOARD_0_BKUP = GPIO_MUX_2,
	GPIO_MUX_O_KEYBOARD_1_BKUP = GPIO_MUX_2,
	GPIO_MUX_O_KEYBOARD_2_BKUP = GPIO_MUX_2,
	GPIO_MUX_O_KEYBOARD_3 = GPIO_MUX_2,
	GPIO_MUX_O_KEYBOARD_4_BKUP = GPIO_MUX_2,
	GPIO_MUX_O_KEYBOARD_5_BKUP = GPIO_MUX_2,
	GPIO_MUX_O_KEYBOARD_5 = GPIO_MUX_2,
	GPIO_MUX_O_KEYBOARD_2 = GPIO_MUX_2,
	GPIO_MUX_I_KEYBOARD_19 = GPIO_MUX_2,
	GPIO_MUX_I_KEYBOARD_18 = GPIO_MUX_2,
	GPIO_MUX_I_KEYBOARD_20 = GPIO_MUX_2,
	GPIO_MUX_I_KEYBOARD_23 = GPIO_MUX_2,
	GPIO_MUX_O_KEYBOARD_3_BKUP = GPIO_MUX_2,
	GPIO_MUX_I_KEYBOARD_27 = GPIO_MUX_2,
	GPIO_MUX_I_KEYBOARD_26 = GPIO_MUX_2,
	GPIO_MUX_I_KEYBOARD_21 = GPIO_MUX_2,

	GPIO_MUX_I_SPI_MSTR_MISO_BKUP1 = GPIO_MUX_3,
	GPIO_MUX_O_SPI_MSTR_MOSI_BKUP = GPIO_MUX_3,
	GPIO_MUX_O_SPI_CLK_BKUP = GPIO_MUX_3,
	GPIO_MUX_I_QD_0_CHA_X0 = GPIO_MUX_3,
	GPIO_MUX_I_QD_0_CHB_X0 = GPIO_MUX_3,
	GPIO_MUX_I_QD_0_IDX_X0 = GPIO_MUX_3,
	GPIO_MUX_I_QD_0_CHA_Y0 = GPIO_MUX_3,
	GPIO_MUX_I_QD_0_CHB_Y0 = GPIO_MUX_3,
	GPIO_MUX_I_QD_0_IDX_Y0 = GPIO_MUX_3,
	GPIO_MUX_O_SPI_MSTR_SSN0_BKUP = GPIO_MUX_3,
	GPIO_MUX_I_QD_0_CHA_Z0 = GPIO_MUX_3,
	GPIO_MUX_I_QD_0_CHB_Z0 = GPIO_MUX_3,
	GPIO_MUX_O_TV_INFRD_OUT = GPIO_MUX_3,
	GPIO_MUX_I_WLAN_TX0 = GPIO_MUX_3,
	GPIO_MUX_I_WLAN_RX0 = GPIO_MUX_3,
	GPIO_MUX_I_SPI_SLV_CLK = GPIO_MUX_3,
	GPIO_MUX_O_SPI_SLV_MISO = GPIO_MUX_3,
	GPIO_MUX_I_SPI_SLV_MOSI1 = GPIO_MUX_3,
	GPIO_MUX_I_SPI_SLV_SSN1 = GPIO_MUX_3,

	GPIO_MUX_IO_I2C_0_SCL = GPIO_MUX_4,
	GPIO_MUX_IO_I2C_0_SDA = GPIO_MUX_4,
	GPIO_MUX_IO_I2C_1_SCL = GPIO_MUX_4,
	GPIO_MUX_IO_I2C_1_SDA = GPIO_MUX_4,
	GPIO_MUX_O_I2S_MSTR_CLK = GPIO_MUX_4,
	GPIO_MUX_IO_I2S_MSTR_WS = GPIO_MUX_4,
	GPIO_MUX_IO_I2S_MSTR_SD0 = GPIO_MUX_4,
	GPIO_MUX_IO_I2S_MSTR_SD1 = GPIO_MUX_4,
	GPIO_MUX_IO_I2C_0_SCL_BKUP = GPIO_MUX_4,
	GPIO_MUX_IO_I2C_0_SDA_BKUP = GPIO_MUX_4,
	GPIO_MUX_IO_COUNTER_1 = GPIO_MUX_4,
	GPIO_MUX_IO_COUNTER_2 = GPIO_MUX_4,
	GPIO_MUX_IO_COUNTER_3 = GPIO_MUX_4,
	GPIO_MUX_IO_COUNTER_4 = GPIO_MUX_4,
	GPIO_MUX_IO_COUNTER_5 = GPIO_MUX_4,
	GPIO_MUX_IO_COUNTER_6 = GPIO_MUX_4,
	GPIO_MUX_IO_COUNTER_7 = GPIO_MUX_4,
	GPIO_MUX_O_SPI_MSTR_SSN3_BKUP = GPIO_MUX_4,
	GPIO_MUX_O_SPI_MSTR_SSN3 = GPIO_MUX_4,
	GPIO_MUX_O_BLE_ACTIVE = GPIO_MUX_4,
	GPIO_MUX_O_BLE_ACTIVE_BKUP = GPIO_MUX_4,
	GPIO_MUX_IO_I2C_1_SCL_BKUP = GPIO_MUX_4,
	GPIO_MUX_IO_I2C_1_SDA_BKUP = GPIO_MUX_4,

	GPIO_MUX_O_AUDIO_SD_L_BKUP = GPIO_MUX_5,
	GPIO_MUX_O_AUDIO_SD_R_BKUP = GPIO_MUX_5,
	GPIO_MUX_I_I2S_SLV_CLK0 = GPIO_MUX_5,
	GPIO_MUX_IO_I2S_SLV_WS = GPIO_MUX_5,
	GPIO_MUX_IO_I2S_SLV_SD0 = GPIO_MUX_5,
	GPIO_MUX_IO_I2S_SLV_SD1 = GPIO_MUX_5,
	GPIO_MUX_O_PWM_3 = GPIO_MUX_5,
	GPIO_MUX_O_PWM_4 = GPIO_MUX_5,
	GPIO_MUX_O_AUDIO_SD_L = GPIO_MUX_5,
	GPIO_MUX_O_AUDIO_SD_R = GPIO_MUX_5,
	GPIO_MUX_O_32KHZ_CLK = GPIO_MUX_5,
	GPIO_MUX_I_QD_0_IDX_Z0 = GPIO_MUX_5,
	GPIO_MUX_O_QD_0_LED_X = GPIO_MUX_5,
	GPIO_MUX_O_QD_0_LED_Y = GPIO_MUX_5,
	GPIO_MUX_O_QD_0_LED_Z = GPIO_MUX_5,

	GPIO_MUX_O_PWM_0 = GPIO_MUX_6,
	GPIO_MUX_O_PWM_1 = GPIO_MUX_6,
	GPIO_MUX_O_PWM_2 = GPIO_MUX_6,
	GPIO_MUX_O_TX_EN1 = GPIO_MUX_6,
	GPIO_MUX_O_TX_EN1_BKUP = GPIO_MUX_6,
	GPIO_MUX_I_SWD_TRACE_CLK0 = GPIO_MUX_6,
	GPIO_MUX_O_SWD_TRACE_SWO = GPIO_MUX_6,
	GPIO_MUX_O_SWD_TRACE_0 = GPIO_MUX_6,
	GPIO_MUX_O_SWD_TRACE_1 = GPIO_MUX_6,
	GPIO_MUX_O_SWD_TRACE_2 = GPIO_MUX_6,
	GPIO_MUX_O_SWD_TRACE_3 = GPIO_MUX_6,
	GPIO_MUX_O_TX_EN_BKUP = GPIO_MUX_6,
	GPIO_MUX_O_RX_EN_BKUP = GPIO_MUX_6,
	GPIO_MUX_O_RX_EN = GPIO_MUX_6,
	GPIO_MUX_I_PDM_1_DATA0 = GPIO_MUX_6,
	GPIO_MUX_I_PDM_0_DATA0 = GPIO_MUX_6,
	GPIO_MUX_O_WDT_RESET = GPIO_MUX_6,
	GPIO_MUX_O_WDT_RESET_BKUP = GPIO_MUX_6,
	GPIO_MUX_O_TX_EN = GPIO_MUX_6,
	GPIO_MUX_O_32MHZ_CLK_OUT_BKUP = GPIO_MUX_6,
	GPIO_MUX_O_PDM_0_CLK = GPIO_MUX_6,
	GPIO_MUX_O_32MHZ_CLK_OUT = GPIO_MUX_6 | (GPIO_PORT_4 << 4) | (GPIO_PIN_1 << 8),
};

enum qspi_pin {
	QSPI_PIN_0,
	QSPI_PIN_1,
	QSPI_PIN_2,
	QSPI_PIN_3A,
	QSPI_PIN_4,
	QSPI_PIN_5,
	QSPI_PIN_3B,
};

enum qspi_mux {
	QSPI_MUX_0,
	QSPI_MUX_1,
	QSPI_MUX_2,
	QSPI_MUX_3,
	QSPI_MUX_4,
	QSPI_MUX_5,
};

/*
 * Inline Functions
 ****************************************************************************************
 */

static __inline void gpio_port_0_pin_mux(int pin, int mux, int inv)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_0);

	reg &= ~(0x7 << (pin*4));
	reg |= ((mux & 0x7) << (pin*4));
	if (inv)
		reg |= (1 << (pin*4 + 3));
	else
		reg &= ~(1 << (pin*4 + 3));

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_0, reg);
}

static __inline void gpio_port_1_pin_mux(int pin, int mux, int inv)
{
	uint32_t addr;

	if (pin > 7) {
		pin -= 8;
		addr = GLOBAL_REG_PIN_MUX_GPIO_1_CONT;
	} else {
		addr = GLOBAL_REG_PIN_MUX_GPIO_1;
	}

	uint32_t reg = RD_WORD(addr);

	reg &= ~(0x7 << (pin*4));
	reg |= ((mux & 0x7) << (pin*4));
	if (inv)
		reg |= (1 << (pin*4 + 3));
	else
		reg &= ~(1 << (pin*4 + 3));


	WR_WORD(addr, reg);
}

static __inline void gpio_port_2_pin_mux(int pin, int mux, int inv)
{
	uint32_t addr;

	if (pin > 7) {
		pin -= 8;
		addr = GLOBAL_REG_PIN_MUX_GPIO_2_CONT;
	} else {
		addr = GLOBAL_REG_PIN_MUX_GPIO_2;
	}

	uint32_t reg = RD_WORD(addr);

	reg &= ~(0x7 << (pin*4));
	reg |= ((mux & 0x7) << (pin*4));
	if (inv)
		reg |= (1 << (pin*4 + 3));
	else
		reg &= ~(1 << (pin*4 + 3));


	WR_WORD(addr, reg);
}

static __inline void gpio_port_3_pin_mux(int pin, int mux, int inv)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_3);

	reg &= ~(0x7 << (pin*4));
	reg |= ((mux & 0x7) << (pin*4));
	if (inv)
		reg |= (1 << (pin*4 + 3));
	else
		reg &= ~(1 << (pin*4 + 3));

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_3, reg);
}

static __inline void gpio_port_4_pin_mux(int pin, int mux, int inv)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_4);

	reg &= ~(0x7 << (pin*4));
	reg |= ((mux & 0x7) << (pin*4));
	if (inv)
		reg |= (1 << (pin*4 + 3));
	else
		reg &= ~(1 << (pin*4 + 3));

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_4, reg);
}

static __inline void gpio_port_0_output(int pin, int high, int en)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT);

	if (high)
		reg |= (1 << (pin*2));
	else
		reg &= ~(1 << (pin*2));

	if (en) 
		reg &= ~(1 << ((pin*2) + 1));
	else
		reg |= (1 << ((pin*2) + 1));

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_0_OUTPUT, reg);
}

static __inline void gpio_port_1_output(int pin, int high, int en)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT);

	if (high)
		reg |= (1 << (pin*2));
	else
		reg &= ~(1 << (pin*2));

	if (en) 
		reg &= ~(1 << ((pin*2) + 1));
	else
		reg |= (1 << ((pin*2) + 1));

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_1_OUTPUT, reg);
}

static __inline void gpio_port_2_output(int pin, int high, int en)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT);

	if (high)
		reg |= (1 << (pin*2));
	else
		reg &= ~(1 << (pin*2));

	if (en) 
		reg &= ~(1 << ((pin*2) + 1));
	else
		reg |= (1 << ((pin*2) + 1));

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_2_OUTPUT, reg);
}

static __inline void gpio_port_3_output(int pin, int high, int en)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT);

	if (high)
		reg |= (1 << (pin*2));
	else
		reg &= ~(1 << (pin*2));

	if (en) 
		reg &= ~(1 << ((pin*2) + 1));
	else
		reg |= (1 << ((pin*2) + 1));

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT, reg);
}

static __inline void gpio_port_4_output(int pin, int high, int en)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT);

	/// offset is at bit 18
	pin += 9;

	if (high)
		reg |= (1 << (pin*2));
	else
		reg &= ~(1 << (pin*2));

	if (en) 
		reg &= ~(1 << ((pin*2) + 1));
	else
		reg |= (1 << ((pin*2) + 1));

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_34_OUTPUT, reg);
}

static __inline int gpio_port_0_input(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_01_INPUT_STATUS);

	reg &= GLOBAL_REG_PIN_MUX_GPIO_01_INPUT_STATUS_STS_PIN_MUX_GPIO_0_INPUT;
	pin &= GLOBAL_REG_PIN_MUX_GPIO_01_INPUT_STATUS_STS_PIN_MUX_GPIO_0_INPUT_MASK;
	if ((reg >> (pin + GLOBAL_REG_PIN_MUX_GPIO_01_INPUT_STATUS_STS_PIN_MUX_GPIO_0_INPUT_SHIFT)) & 1)
		return 1;

	return 0;
}

static __inline int gpio_port_1_input(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_01_INPUT_STATUS);

	reg &= GLOBAL_REG_PIN_MUX_GPIO_01_INPUT_STATUS_STS_PIN_MUX_GPIO_1_INPUT;
	pin &= GLOBAL_REG_PIN_MUX_GPIO_01_INPUT_STATUS_STS_PIN_MUX_GPIO_1_INPUT_MASK;
	if ((reg >> (pin + GLOBAL_REG_PIN_MUX_GPIO_01_INPUT_STATUS_STS_PIN_MUX_GPIO_1_INPUT_SHIFT)) & 1)
		return 1;

	return 0;
}

static __inline int gpio_port_2_input(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS);

	reg &= GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_2_INPUT;
	pin &= GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_2_INPUT_MASK;
	if ((reg >> (pin + GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_2_INPUT_SHIFT)) & 1)
		return 1;

	return 0;
}

static __inline int gpio_port_3_input(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS);

	reg &= GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_3_INPUT;
	pin &= GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_3_INPUT_MASK;
	if ((reg >> (pin + GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_3_INPUT_SHIFT)) & 1)
		return 1;

	return 0;
}
	
static __inline int gpio_port_4_input(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS);

	reg &= GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_4_INPUT;
	pin &= GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_4_INPUT_MASK;
	if ((reg >> (pin + GLOBAL_REG_PIN_MUX_GPIO_234_INPUT_STATUS_STS_PIN_MUX_GPIO_4_INPUT_SHIFT)) & 1)
		return 1;

	return 0;
}

static __inline void gpio_port_0_pad_oe_ie(int pin, int oe, int ie)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_0_OE_IE);

	if (oe)
		reg |= (1 << pin);
	else
		reg &= ~(1 << pin);
	
	if (ie)
		reg |= (1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_0_OE_IE_CTL_GPIO_TO_PAD_IE_0_SHIFT));
	else
		reg &= ~(1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_0_OE_IE_CTL_GPIO_TO_PAD_IE_0_SHIFT));
 
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_0_OE_IE, reg);

}

static __inline void gpio_port_1_pad_oe_ie(int pin, int oe, int ie)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_1_OE_IE);

	if (oe)
		reg |= (1 << pin);
	else
		reg &= ~(1 << pin);
	
	if (ie)
		reg |= (1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_1_OE_IE_CTL_GPIO_TO_PAD_IE_1_SHIFT));
	else
		reg &= ~(1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_1_OE_IE_CTL_GPIO_TO_PAD_IE_1_SHIFT));
 
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_1_OE_IE, reg);

}

static __inline void gpio_port_2_pad_oe_ie(int pin, int oe, int ie)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_2_OE_IE);

	if (oe)
		reg |= (1 << pin);
	else
		reg &= ~(1 << pin);
	
	if (ie)
		reg |= (1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_2_OE_IE_CTL_GPIO_TO_PAD_IE_2_SHIFT));
	else
		reg &= ~(1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_2_OE_IE_CTL_GPIO_TO_PAD_IE_2_SHIFT));
 
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_2_OE_IE, reg);

}

static __inline void gpio_port_3_pad_oe_ie(int pin, int oe, int ie)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_3_OE_IE);

	if (oe)
		reg |= (1 << pin);
	else
		reg &= ~(1 << pin);
	
	if (ie)
		reg |= (1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_3_OE_IE_CTL_GPIO_TO_PAD_IE_3_SHIFT));
	else
		reg &= ~(1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_3_OE_IE_CTL_GPIO_TO_PAD_IE_3_SHIFT));
 
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_3_OE_IE, reg);

}

static __inline void gpio_port_4_pad_oe_ie(int pin, int oe, int ie)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_4_OE_IE);

	if (oe)
		reg |= (1 << pin);
	else
		reg &= ~(1 << pin);
	
	if (ie)
		reg |= (1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_4_OE_IE_CTL_GPIO_TO_PAD_IE_4_SHIFT));
	else
		reg &= ~(1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_4_OE_IE_CTL_GPIO_TO_PAD_IE_4_SHIFT));
 
	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_4_OE_IE, reg);

}

static __inline void gpio_port_0_pad_pd_pu(int pin, int pd, int pu)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_0_PD_PU);
	if (pd)
		reg |= (1 << pin);
	else
		reg &= ~(1 << pin);

	if (pu) 
		reg |= (1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_0_PD_PU_CTL_GPIO_TO_PAD_PU_0_SHIFT));
	else
		reg &= ~(1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_0_PD_PU_CTL_GPIO_TO_PAD_PU_0_SHIFT));

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_0_PD_PU, reg);
}

static __inline void gpio_port_1_pad_pd_pu(int pin, int pd, int pu)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_1_PD_PU);
	if (pd)
		reg |= (1 << pin);
	else
		reg &= ~(1 << pin);

	if (pu) 
		reg |= (1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_1_PD_PU_CTL_GPIO_TO_PAD_PU_1_SHIFT));
	else
		reg &= ~(1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_1_PD_PU_CTL_GPIO_TO_PAD_PU_1_SHIFT));

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_1_PD_PU, reg);
}

static __inline void gpio_port_2_pad_pd_pu(int pin, int pd, int pu)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_2_PD_PU);
	if (pd)
		reg |= (1 << pin);
	else
		reg &= ~(1 << pin);

	if (pu) 
		reg |= (1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_2_PD_PU_CTL_GPIO_TO_PAD_PU_2_SHIFT));
	else
		reg &= ~(1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_2_PD_PU_CTL_GPIO_TO_PAD_PU_2_SHIFT));

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_2_PD_PU, reg);
}

static __inline void gpio_port_3_pad_pd_pu(int pin, int pd, int pu)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_3_PD_PU);
	if (pd)
		reg |= (1 << pin);
	else
		reg &= ~(1 << pin);

	if (pu) 
		reg |= (1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_3_PD_PU_CTL_GPIO_TO_PAD_PU_3_SHIFT));
	else
		reg &= ~(1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_3_PD_PU_CTL_GPIO_TO_PAD_PU_3_SHIFT));

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_3_PD_PU, reg);
}

static __inline void gpio_port_4_pad_pd_pu(int pin, int pd, int pu)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_4_PD_PU);
	if (pd)
		reg |= (1 << pin);
	else
		reg &= ~(1 << pin);

	if (pu) 
		reg |= (1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_4_PD_PU_CTL_GPIO_TO_PAD_PU_4_SHIFT));
	else
		reg &= ~(1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_4_PD_PU_CTL_GPIO_TO_PAD_PU_4_SHIFT));

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_4_PD_PU, reg);
}

static __inline void gpio_port_0_pad_pc(int pin, int on)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_PC_01);

	pin &= GLOBAL_REG_PIN_MUX_GPIO_PC_01_CTL_GPIO_TO_PAD_PC_0_MASK;
	if (on)
		reg |= (1 << pin);
	else
		reg &= ~(1 << pin);

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_PC_01, reg);
}

static __inline void gpio_port_1_pad_pc(int pin, int on)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_PC_01);

	pin &= GLOBAL_REG_PIN_MUX_GPIO_PC_01_CTL_GPIO_TO_PAD_PC_1_MASK;
	if (on)
		reg |= (1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_PC_01_CTL_GPIO_TO_PAD_PC_1_SHIFT));
	else
		reg &= ~(1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_PC_01_CTL_GPIO_TO_PAD_PC_1_SHIFT));

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_PC_01, reg);
}

static __inline void gpio_port_2_pad_pc(int pin, int on)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_PC_234);

	pin &= GLOBAL_REG_PIN_MUX_GPIO_PC_234_CTL_GPIO_TO_PAD_PC_2_MASK;
	if (on)
		reg |= (1 << pin);
	else
		reg &= ~(1 << pin);

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_PC_234, reg);
}

static __inline void gpio_port_3_pad_pc(int pin, int on)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_PC_234);

	pin &= GLOBAL_REG_PIN_MUX_GPIO_PC_234_CTL_GPIO_TO_PAD_PC_3_MASK;
	if (on)
		reg |= (1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_PC_234_CTL_GPIO_TO_PAD_PC_3_SHIFT));
	else
		reg &= ~(1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_PC_234_CTL_GPIO_TO_PAD_PC_3_SHIFT));

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_PC_234, reg);
}

static __inline void gpio_port_4_pad_pc(int pin, int on)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_GPIO_PC_234);

	pin &= GLOBAL_REG_PIN_MUX_GPIO_PC_234_CTL_GPIO_TO_PAD_PC_4_MASK;
	if (on)
		reg |= (1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_PC_234_CTL_GPIO_TO_PAD_PC_4_SHIFT));
	else
		reg &= ~(1 << (pin + GLOBAL_REG_PIN_MUX_GPIO_PC_234_CTL_GPIO_TO_PAD_PC_4_SHIFT));

	WR_WORD(GLOBAL_REG_PIN_MUX_GPIO_PC_234, reg);
}

static __inline void gpio_qspi_pin_mux(int pin, int mux, int inv)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_QSPI);

	reg &= ~(0x7 << (pin * 4));
	reg |= ((mux & 0x7) << (pin*4));
	if (inv)
		reg |= (1 << (pin*4 + 3));
	else
		reg &= ~(1 << (pin*4 + 3));

	WR_WORD(GLOBAL_REG_PIN_MUX_QSPI, reg);
}

static __inline void gpio_qspi_pin_mux_en(int en, int pin_3b)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_QSPI);

	if (pin_3b)
		reg |= GLOBAL_REG_PIN_MUX_QSPI_CTL_QSPI_3A_3B_SEL;
	else
		reg &= ~GLOBAL_REG_PIN_MUX_QSPI_CTL_QSPI_3A_3B_SEL;

	if (en)
		reg |= GLOBAL_REG_PIN_MUX_QSPI_CTL_QSPI_EFUSE0REG1|GLOBAL_REG_PIN_MUX_QSPI_CTL_QSPI_3A_3B_SEL_EFUSE0REG1;
	else
		reg &= ~(GLOBAL_REG_PIN_MUX_QSPI_CTL_QSPI_EFUSE0REG1|GLOBAL_REG_PIN_MUX_QSPI_CTL_QSPI_3A_3B_SEL_EFUSE0REG1);

	WR_WORD(GLOBAL_REG_PIN_MUX_QSPI, reg);
}


static __inline void gpio_qspi_pin_output(int pin, int out, int en)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_PIN_MUX_QSPI_OUTPUT);

	reg &= ~(0x3 << (pin * 2));
	if (out)
		reg |= (1 << (pin * 2));
	else
		reg &= ~(1 << (pin * 2));

	if (en)
		reg &= ~(1 << ((pin *2) + 1));
	else
		reg |= (1 << ((pin *2) + 1));


	WR_WORD(GLOBAL_REG_PIN_MUX_QSPI_OUTPUT, reg);
}

static __inline void gpio_qspi_pin_pad_pc(int pin, int on)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_QSPI_PC);

	if (on)
		reg |= (1 << pin);
	else
		reg &= ~(1 << pin);


	WR_WORD(GLOBAL_REG_QSPI_PC, reg);
}

static __inline void gpio_qspi_pin_pad_oe_ie(int pin, int oe, int ie)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_QSPI_OE_IE_PU_PD);

	if (oe)
		reg |= (1 << pin);
	else
		reg &= ~(1 << pin);

	if (ie)
		reg |= (1 << (pin + GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_IE_SHIFT));
	else
		reg &= ~(1 << (pin + GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_IE_SHIFT));

	WR_WORD(GLOBAL_REG_QSPI_OE_IE_PU_PD, reg);
}

static __inline void gpio_qspi_pin_pad_pu_pd(int pin, int pu, int pd)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_QSPI_OE_IE_PU_PD);
	if (pu)
		reg |= (1 << (pin + GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_PU_SHIFT));
	else
		reg &= ~(1 << (pin + GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_PU_SHIFT));

	if (pd)
		reg |= (1 << (pin + GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_PD_SHIFT));
	else
		reg &= ~(1 << (pin + GLOBAL_REG_QSPI_OE_IE_PU_PD_CTL_QSPI_PD_SHIFT));

	WR_WORD(GLOBAL_REG_QSPI_OE_IE_PU_PD, reg);
}

static __inline uint32_t gpio_port_0_int_status(void)
{
	return ((RD_WORD(GLOBAL_REG_INTR_GPIO_0_STATUS) >> GPIO_PORT_0_INT_SHIFT) & GPIO_PORT_0_INT_MASK);
}

static __inline void gpio_port_0_int_clear(uint32_t pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_0_CLEAR);
	reg |= (1 << pin << GPIO_PORT_0_INT_SHIFT);
	WR_WORD(GLOBAL_REG_INTR_GPIO_0_CLEAR, reg);
}

static __inline void gpio_port_0_int_mask(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_0_MASK_SET);
	reg |= (1 << pin << GPIO_PORT_0_INT_SHIFT);
	WR_WORD(GLOBAL_REG_INTR_GPIO_0_MASK_SET, reg);
}

static __inline void gpio_port_0_int_unmask(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_0_MASK_CLEAR);
	reg |= (1 << pin << GPIO_PORT_0_INT_SHIFT);
	WR_WORD(GLOBAL_REG_INTR_GPIO_0_MASK_CLEAR, reg);
}

static __inline void gpio_port_0_int_polarity(int pin, int rise)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_0_POLARITY);
	if (rise)
		reg &= ~(1 << pin << GPIO_PORT_0_INT_SHIFT);
	else
		reg |= (1 << pin << GPIO_PORT_0_INT_SHIFT);

	WR_WORD(GLOBAL_REG_INTR_GPIO_0_POLARITY, reg);
}

static __inline uint32_t gpio_port_1_int_status(void)
{
	return ((RD_WORD(GLOBAL_REG_INTR_GPIO_1_STATUS) >> GPIO_PORT_1_INT_SHIFT) & GPIO_PORT_1_INT_MASK);
}

static __inline void gpio_port_1_int_clear(uint32_t pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_1_CLEAR);
	reg |= (1 << pin << GPIO_PORT_1_INT_SHIFT);
	WR_WORD(GLOBAL_REG_INTR_GPIO_1_CLEAR, reg);
}

static __inline void gpio_port_1_int_mask(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_1_MASK_SET);
	reg |= (1 << pin << GPIO_PORT_1_INT_SHIFT);
	WR_WORD(GLOBAL_REG_INTR_GPIO_1_MASK_SET, reg);
}

static __inline void gpio_port_1_int_unmask(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_1_MASK_CLEAR);
	reg |= (1 << pin << GPIO_PORT_1_INT_SHIFT);
	WR_WORD(GLOBAL_REG_INTR_GPIO_1_MASK_CLEAR, reg);
}

static __inline void gpio_port_1_int_polarity(int pin, int rise)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_1_POLARITY);
	if (rise)
		reg &= ~(1 << pin << GPIO_PORT_1_INT_SHIFT);
	else
		reg |= (1 << pin << GPIO_PORT_1_INT_SHIFT);

	WR_WORD(GLOBAL_REG_INTR_GPIO_1_POLARITY, reg);
}

static __inline uint32_t gpio_port_2_int_status(void)
{
	return ((RD_WORD(GLOBAL_REG_INTR_GPIO_2_STATUS) >> GPIO_PORT_2_INT_SHIFT) & GPIO_PORT_2_INT_MASK);
}

static __inline void gpio_port_2_int_clear(uint32_t pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_2_CLEAR);
	reg |= (1 << pin << GPIO_PORT_1_INT_SHIFT);
	WR_WORD(GLOBAL_REG_INTR_GPIO_2_CLEAR, reg);
}

static __inline void gpio_port_2_int_mask(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_2_MASK_SET);
	reg |= (1 << pin << GPIO_PORT_1_INT_SHIFT);
	WR_WORD(GLOBAL_REG_INTR_GPIO_2_MASK_SET, reg);
}

static __inline void gpio_port_2_int_unmask(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_2_MASK_CLEAR);
	reg |= (1 << pin << GPIO_PORT_1_INT_SHIFT);
	WR_WORD(GLOBAL_REG_INTR_GPIO_2_MASK_CLEAR, reg);
}

static __inline void gpio_port_2_int_polarity(int pin, int rise)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_2_POLARITY);
	if (rise)
		reg &= ~(1 << pin << GPIO_PORT_2_INT_SHIFT);
	else
		reg |= (1 << pin << GPIO_PORT_2_INT_SHIFT);

	WR_WORD(GLOBAL_REG_INTR_GPIO_2_POLARITY, reg);
}

static __inline uint32_t gpio_port_3_int_status(void)
{
	return ((RD_WORD(GLOBAL_REG_INTR_GPIO_3_STATUS) >> GPIO_PORT_3_INT_SHIFT) & GPIO_PORT_3_INT_MASK);
}

static __inline void gpio_port_3_int_clear(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_3_CLEAR);
	reg |= (1 << pin << GPIO_PORT_3_INT_SHIFT);
	WR_WORD(GLOBAL_REG_INTR_GPIO_3_CLEAR, reg);
}

static __inline void gpio_port_3_int_mask(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_3_MASK_SET);
	reg |= (1 << pin << GPIO_PORT_3_INT_SHIFT);
	WR_WORD(GLOBAL_REG_INTR_GPIO_3_MASK_SET, reg);
}

static __inline void gpio_port_3_int_unmask(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_3_MASK_CLEAR);
	reg |= (1 << pin << GPIO_PORT_3_INT_SHIFT);
	WR_WORD(GLOBAL_REG_INTR_GPIO_3_MASK_CLEAR, reg);
}

static __inline void gpio_port_3_int_polarity(int pin, int rise)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_3_POLARITY);
	if (rise)
		reg &= ~(1 << pin << GPIO_PORT_3_INT_SHIFT);
	else
		reg |= (1 << pin << GPIO_PORT_3_INT_SHIFT);

	WR_WORD(GLOBAL_REG_INTR_GPIO_3_POLARITY, reg);
}

static __inline uint32_t gpio_port_4_int_status(void)
{
	return ((RD_WORD(GLOBAL_REG_INTR_GPIO_4_STATUS) >> GPIO_PORT_4_INT_SHIFT) & GPIO_PORT_4_INT_MASK);
}

static __inline void gpio_port_4_int_clear(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_4_CLEAR);
	reg |= (1 << pin << GPIO_PORT_4_INT_SHIFT);
	WR_WORD(GLOBAL_REG_INTR_GPIO_4_CLEAR, reg);
}

static __inline void gpio_port_4_int_mask(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_4_MASK_SET);
	reg |= (1 << pin << GPIO_PORT_4_INT_SHIFT);
	WR_WORD(GLOBAL_REG_INTR_GPIO_4_MASK_SET, reg);
}

static __inline void gpio_port_4_int_unmask(int pin)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_4_MASK_CLEAR);
	reg |= (1 << pin << GPIO_PORT_4_INT_SHIFT);
	WR_WORD(GLOBAL_REG_INTR_GPIO_4_MASK_CLEAR, reg);
}

static __inline void gpio_port_4_int_polarity(int pin, int rise)
{
	uint32_t reg = RD_WORD(GLOBAL_REG_INTR_GPIO_4_POLARITY);
	if (rise)
		reg &= ~(1 << pin << GPIO_PORT_4_INT_SHIFT);
	else
		reg |= (1 << pin << GPIO_PORT_4_INT_SHIFT);

	WR_WORD(GLOBAL_REG_INTR_GPIO_4_POLARITY, reg);
}

/*
 * Exported Functions
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Config GPIO from the user's configuration settings .
 *
 * @param[in] pin_cfg				Pin configuration from the configuration tool.  
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
void hal_gpio_pin_cfg(uint32_t pin_cfg);

/**
 ****************************************************************************************
 * @brief Restore GPIO pin to its default state.
 *
 * @param[in] pin_cfg				Pin information.  
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
void hal_gpio_pin_dft(uint32_t pin_cfg);

/**
 ****************************************************************************************
 * @brief Config GPIO pin mux.
 *
 * @param[in] port					Port number, @see enum gpio_port.  
 * @param[in] pin						Pin number, @see enum gpio_pin.
 * @param[in] mux					Mux number, @see enum gpio_mux.
 * @param[in] inv						Invert pin, 1: inverted, 0: otherwise.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
void hal_gpio_pin_mux(int port, int pin, int mux, int inv);

/**
 ****************************************************************************************
 * @brief Config GPIO to output.
 *
 * @param[in] port					Port number, @see enum gpio_port.  
 * @param[in] pin						Pin number, @see enum gpio_pin.
 * @param[in] high					1: HIGH output, 0: otherwise.
 * @param[in] en						1: Enable, 0: otherwise.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
void hal_gpio_output(int port, int pin, int high, int en);

/**
 ****************************************************************************************
 * @brief Config GPIO to input.
 *
 * @param[in] port					Port number, @see enum gpio_port.  
 * @param[in] pin						Pin number, @see enum gpio_pin.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
int hal_gpio_input(int port, int pin);

/**
 ****************************************************************************************
 * @brief Config GPIO PAD as output or input.
 *
 * @param[in] port					Port number, @see enum gpio_port.  
 * @param[in] pin						Pin number, @see enum gpio_pin.
 * @param[in] oe						1: Ouput enable, 0: otherwise.
 * @param[in] ie						1: Input enable, 0: otherwise.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
void hal_gpio_pad_oe_ie(int port, int pin, int oe, int ie);

/**
 ****************************************************************************************
 * @brief Config GPIO PAD as pull up or pull down.
 * @note If neither pull up or down, then the pin is floating
 *
 * @param[in] port					Port number, @see enum gpio_port.  
 * @param[in] pin						Pin number, @see enum gpio_pin.
 * @param[in] pd						1: Pull down, 0: otherwise.
 * @param[in] pu						1: Pull up, 0: otherwise.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
void hal_gpio_pad_pd_pu(int port, int pin, int pd, int pu);

/**
 ****************************************************************************************
 * @brief Config GPIO PAD drive strength.
 * @note There are two drive strength. Pick the one that is suitable.
 *
 * @param[in] port					Port number, @see enum gpio_port.  
 * @param[in] pin						Pin number, @see enum gpio_pin.
 * @param[in] on						1: Change it, 0: otherwise.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
void hal_gpio_pad_pc(int port, int pin, int on);

/**
 ****************************************************************************************
 * @brief Config QSPI GPIO pin mux.
 *
 * @param[in] pin						Pin number, @see enum qspi_pin.
 * @param[in] mux					Mux number, @see enum qspi_mux.
 * @param[in] inv						Invert pin, 1: inverted, 0: otherwise.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
void hal_qspi_pin_mux(int pin, int mux, int inv);

/**
 ****************************************************************************************
 * @brief Config QSPI pin output.
 *
 * @param[in] pin						Pin number, @see enum qspi_pin.
 * @param[in] mux					
 * @param[in] inv						Invert pin, 1: inverted, 0: otherwise.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
void hal_qspi_pin_output(int pin, int out, int en);
void hal_qspi_pad_oe_ie(int pin, int oe, int ie);
void hal_qspi_pad_pd_pu(int pin, int pd, int pu);
void hal_qspi_pad_pc(int pin, int on);

/**
 ****************************************************************************************
 * @brief Latch GPIO pin state during deep sleep.
 *
 * @param[in] port					Port number, @see enum gpio_port.
 * @param[in] pin						Pin number, @see enum gpio_pin.
 * @param[in] latch					1: Latch the pin state, 0: otherwise.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
void hal_gpio_aon_latch(int port, int pin, int latch);

/**
 ****************************************************************************************
 * @brief Config GPIO pin as wake up pin during deep sleep.
 *
 * @param[in] port					Port number, @see enum gpio_port.
 * @param[in] pin						Pin number, @see enum gpio_pin.
 * @param[in] wup					1: Wake up pin, 0: otherwise.
 * @param[in] polarity				1: Pin level high as wake up, 0: otherwise.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
void hal_gpio_aon_wup(int port, int pin, int wup, int pol);

/**
 ****************************************************************************************
 * @brief Config GPIO pin as output during deep sleep.
 *
 * @param[in] port					Port number, @see enum gpio_port.
 * @param[in] pin						Pin number, @see enum gpio_pin.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
void hal_gpio_aon_out(int port, int pin);

/**
 ****************************************************************************************
 * @brief Enable GPIO pin as external interrupt.
 * @note The call back is happened at the interrupt context, so most of the OS functions can't be called.	
 *
 * @param[in] port					Port number, @see enum gpio_port.
 * @param[in] pin						Pin number, @see enum gpio_pin.
 * @param[in] pol						1: HIgh trigger interrupt, 0: otherwise.
 * @param[in] arg						Call back function input parameter.
 * @param[in] callback				Call back function from caller.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
void hal_gpio_ext_int_en(int port, int pin, int pol, void *arg, void (*callback)(void *));

/**
 ****************************************************************************************
 * @brief Disable GPIO pin as external interrupt.
 *
 * @param[in] port					Port number, @see enum gpio_port.
 * @param[in] pin						Pin number, @see enum gpio_pin.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
void hal_gpio_ext_int_dis(int port, int pin);

/**
 ****************************************************************************************
 * @brief Mask GPIO pin interrupt.
 *
 * @param[in] port					Port number, @see enum gpio_port.
 * @param[in] pin						Pin number, @see enum gpio_pin.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
void hal_gpio_ext_int_mask(int port, int pin);

/**
 ****************************************************************************************
 * @brief Unmask GPIO pin interrupt.
 *
 * @param[in] port					Port number, @see enum gpio_port.
 * @param[in] pin						Pin number, @see enum gpio_pin.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */
void hal_gpio_ext_int_unmask(int port, int pin);

/**
 ****************************************************************************************
 * @brief GPIO pin configuration store before power down.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */

void hal_gpio_suspend(void);

/**
 ****************************************************************************************
 * @brief GPIO pin configuration restore after power up.
 *
 *
 * @return This function return NULL. 
 ****************************************************************************************
 */

void hal_gpio_resume(void);


/// @} HAL_GPIO

#endif // HAL_GPIO_H

