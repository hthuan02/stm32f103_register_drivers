/*
 * stm32_i2c.h
 *
 *  Created on: Nov 5, 2026
 *      Author: huynhthuan
 */

#ifndef STM32_I2C_H_
#define STM32_I2C_H_

#include <stdint.h>
#define __vo    volatile

/**
 *  @brief I2C Offset
 */
typedef struct
{
    __vo uint32_t CR1;                      /* Offset: 0x00 */
    __vo uint32_t CR2;                      /* 0x04 */
    __vo uint32_t OAR1;                     /* 0x08 */
    __vo uint32_t OAR2;                     /* 0x0C */
    __vo uint32_t DR;                       /* 0x10 */
    __vo uint32_t SR1;                      /* 0x14 */
    __vo uint32_t SR2;                      /* 0x18 */
    __vo uint32_t CCR;                      /* 0x1C */
    __vo uint32_t TRISE;                    /* 0x20 */
}I2C_Typedef;

/**
 * @brief I2C Memory mapped register
 */
#define I2C1_BASE                   0x40005400UL
#define I2C1                        ((I2C_Typedef *) I2C1_BASE)

/**
 *  @brief I2C_CR1 bits
 */
#define I2C_CR1_POS                (1UL << 11U)
#define I2C_CR1_ACK                (1UL << 10U)
#define I2C_CR1_STOP               (1UL << 9U)
#define I2C_CR1_START              (1UL << 8U)
#define I2C_CR1_PE                 (1UL << 0U)

/**
 *  @brief I2C_CR2 bits
 */
#define I2C_CR2_FREQ_MASK          0x3FUL
#define I2C_CR2_FREQ_36MHZ         0x24UL                                    /* The APB1 bus maximum is 36MHz */

/**
 *  @brief I2C bitmask
 */
#define I2C_OAR1_ADDMODE           (1UL << 15U)                              /* Select amount of Slave 7 bit-add or 10 bit-add */
#define I2C_DR_MASK                0xFFUL

#define I2C_SR1_TXE                (1UL << 7U)                               /*!<(r) Data transmit empty */
#define I2C_SR1_RXNE               (1UL << 6U)
#define I2C_SR1_STOPF              (1UL << 5U)
#define I2C_SR1_BTF                (1UL << 2U)                               /* !<(r) Byte transfer finished */
#define I2C_SR1_ADDR               (1UL << 1U)                               /* !<(r) Read status of Address bit & Read/Write bit*/
#define I2C_SR1_SB                 1UL                                       /* !<(r) Read status of START condition */

#define I2C_SR2_TRA                (1UL << 2U)                               /* !<(r) Transmitter/receiver */
#define I2C_SR2_MSL                1UL                                       /* !<(r) Master/Slave mode */

#define I2C_TRISE_MASK             0x3FUL

#endif /* STM32_I2C_H_ */
