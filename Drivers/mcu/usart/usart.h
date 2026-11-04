/*
 * usart.h
 *
 *  Created on: Oct 30, 2026
 *      Author: huynhthuan
 */

#ifndef USART_H_
#define USART_H_

#include <stdint.h>

#define __vo volatile

/**
 *  @brief USART offset
 */
typedef struct 
{
    __vo uint32_t SR;
    __vo uint32_t DR;
    __vo uint32_t BRR;
    __vo uint32_t CR1;
    __vo uint32_t CR2;
    __vo uint32_t CR3;
    __vo uint32_t GTPR;
}USART_Typedef;

/** 
 *  @brief USART memory mapped register
 */
#define USART2_BASE         0x40004400UL
#define USART2              ((USART_Typedef *)USART2_BASE)    


/**
 *  @brief USART_SR bits
 */
#define USART_SR_TXE                       (1UL << 7U)                     /* Transmit data register data */
#define USART_SR_TC                        (1UL << 6U)                     /* Transmition complete */
#define USART_SR_RXNE                      (1UL << 5U)                     /* Read data register not empty */

/**
 *  @brief USART_DR bits
 */
#define USART_DR_MASK                      (0x1FFUL)

/**
 *  @brief USART_BRR bits
 *         There are 2 bits used for calculate baoudrate
 */
#define USART_BRR_DIV_FRACTION             (0xFUL)
#define USART_BRR_DIV_MANTISSA             (0xFFFUL << 4U)

/** 
 *  @brief USART_CR1 bits
 */
#define USART_CR1_UE                       (1UL << 13U)                    /* Enable USART */
#define USART_CR1_M                        (1UL << 12U)                    /* Select length Data bits */
#define USART_CR1_PCE                      (1UL << 10U)                    /* Parity control enable */
#define USART_CR1_PS                       (1UL << 9U)                     /* Parity selection */
#define USART_CR1_TE                       (1UL << 3U)                     /* Transmitter enable */
#define USART_CR1_RE                       (1UL << 2U)                     /* Receiver enable */

/**
 *  @brief USART_CR2 bits
 */
#define USART_CR2_STOP_MASK                (3UL << 12U)
#define USART_CR2_STOP_1BIT                (0UL << 12U)
#define USART_CR2_STOP_0_5BIT              (1UL << 12U)
#define USART_CR2_STOP_2BITS               (2UL << 12U)
#define USART_CR2_STOP_1_5BIT              (3UL << 12U)

/**
 *  @brief USART function prototype
 */
void usart2_init (void);
void usart2_frame_config (void);
void usart2_transmit_tx(uint32_t data);
uint32_t usart2_receive_rx(void);

#endif /* USART_H_ */
