/*
 * i2c.c
 *
 *  Created on: Nov 5, 2026
 *      Author: huynhthuan
 */

#include "i2c.h"
#include "../rcc/rcc.h"
#include "../gpio/gpio.h"


void i2c_pins_init(void)
{   
    /* Enable peripheral clock */
    rcc_i2c1_clock_enable();
    rcc_gpiob_clock_enable();
    
    /* Reset PB6 PB7 */
    GPIOB->CRL &= ~(GPIO_CRL_PIN_6 | GPIO_CRL_PIN_7);

    /* Initialize SCL SDA */
    GPIOB->CRL |= GPIO_CRL_PIN_6_50MHZ_AF_OD |
                  GPIO_CRL_PIN_7_50MHZ_AF_OD;
    
}

void i2c_config(void)
{
    /* 1. Disable I2C1 */
    I2C1->CR1 &= ~I2C_CR1_PE;

    /* 2. Select frequency for APB1 = 36Mhz */
    I2C1->CR2 &= ~I2C_CR2_FREQ_MASK;
    I2C1->CR2 |= I2C_CR2_FREQ_36MHZ;

    /* 3. Select transmit mode for I2C */
    I2C1->CCR = 180U;                                   /*!< i2c.md*/

    /* 4. Timing Rise, when LOW - HIGH */
    I2C1->TRISE = 37U;                                  /*!< i2c.md*/

    /* 5. Enable I2C */
    I2C1->CR1 |= I2C_CR1_PE;

    /* 6. Enable ACK */
    I2C1->CR1 |= I2C_CR1_ACK;

}

void i2c_start(void)
{
    I2C1->CR1 |= I2C_CR1_START;

    while ((I2C1->SR1 & I2C_SR1_SB) == 0U)
    {
    }
}

void i2c_stop(void)
{
    I2C1->CR1 |= I2C_CR1_STOP;                          /* !< Stop condition has do not STOP Flag */
}

void i2c_write_address (uint8_t data_bit, uint8_t rw_bit)
{
    I2C1->DR = (data_bit << 1) | (rw_bit & 0x01);

    while ((I2C1->SR1 & I2C_SR1_ADDR) == 0U)
    {
    }
    
    /* Clear SR1 SR2 */
    (void) I2C1->SR1;
    (void) I2C1->SR2;
}

void i2c_write_data(uint8_t data)
{   
    /* Wait Data Register empty, when write data */
    while ((I2C1->SR1 & I2C_SR1_TXE) == 0U)
    {
    }
    
    /* Write data */
    I2C1->DR = data;

    /* Wait write data finished */
    while ((I2C1->SR1 & I2C_SR1_BTF) == 0U)
    {
    }
    
}

uint8_t i2c_read_data (void)
{
    while ((I2C1->SR1 & I2C_SR1_RXNE) == 0U)
    {
    }
    
    return (uint8_t)I2C1->DR;
}
