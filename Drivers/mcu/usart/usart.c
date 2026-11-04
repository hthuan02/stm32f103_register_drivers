/*
 * usart.c
 *
 *  Created on: Oct 30, 2026
 *      Author: huynhthuan
 */

#include "usart.h"
#include "../rcc/rcc.h"
#include "../gpio/gpio.h"

/**
 *  @brief Initializes USART clock and pins.
 *        
 *         This function enable the clock for USART2 and 
 *         configures PA2, PA3 pins for use peripherals.
 */
void usart2_init (void)
{
    /* Enable clock for USART2 */
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    /* Reset PA2 PA3*/
    GPIOA->CRL &= ~(GPIOA_CRL_PA2_MASK | GPIOA_CRL_PA3_MASK);
    
    /* PA2_tx */
    GPIOA->CRL |= GPIOA_CRL_MODE2_OUTPUT_2MHZ;
    GPIOA->CRL |= GPIOA_CRL_CNF2_AF_PP;

    /* PA3_rx */
    GPIOA->CRL |= GPIOA_CRL_MODE3_INPUT;
    GPIOA->CRL |= GPIOA_CRL_CNF3_INPUT_FLOATING;

}

/** 
 *  @brief Calculate baudrate USART_BRR functions.
 *         
 *         This function calculate USART_BRR depend on Mantissa and Fraction bits.
 *         It uses the mantissa and fraction is 16x for Oversampling mode of STM32F1.
 * 
 *  @param pclk_hz      Peripherals clock frequency.
 *  @param baud         Baudrate (bit / second).
 * 
 *  @return usart_brr
 */
static uint32_t usart2_calculate_baudrate (uint32_t pclk_hz, uint32_t baud)
{
    uint32_t mantissa = 0;
    uint32_t fraction = 0;
    uint32_t usart_brr = 0;

    if (pclk_hz == 0 || baud == 0)
    {
        return 0U;
    }
    
   
    // Oversampling = 16
    uint32_t usart_div = pclk_hz / (16U * baud);
    mantissa = usart_div;
    fraction = (pclk_hz / baud) - (mantissa * 16U);

    usart_brr = ((mantissa << 4U) & USART_BRR_DIV_MANTISSA) |
                 (fraction & USART_BRR_DIV_FRACTION);

    return usart_brr;

}

/**
 *  @brief Modify USART frame.
 * 
 *         Modify USART frame, The a frame USART include 
 *         (START bits - DATA bits - PARITY bits - STOP bits).
 */
void usart2_frame_config (void)
{
    /* 1. Disable USART2 */
    USART2->CR1 &= ~USART_CR1_UE;

    /* 2. Modify Baudrate */
    USART2->BRR = usart2_calculate_baudrate (36000000U, 9600U);

    /* 3. Frame usart config */
    USART2->CR1 &= ~USART_CR1_M;                            /* Select data bit is 8 bits */
    USART2->CR1 &= ~USART_CR1_PCE;                          /* No uses parity bit */
    USART2->CR2 |= USART_CR2_STOP_1BIT;                     /* Uses 1 bit for stop bit */
    
    /* 4. Enable TE RE & USART2 */
    USART2->CR1 |= USART_CR1_TE | USART_CR1_RE;
    USART2->CR1 |= USART_CR1_UE;
}

/**
 *  @brief Transmitter USART function
 * 
 *  @param data
 */
void usart2_transmit_char(uint32_t data)
{
    while ((USART2->SR & USART_SR_TXE) == 0)
    {
    }

    USART2->DR = data;
}
/**
 *  @brief Receiver USART function
 *          
 *  @param data
 */
uint32_t usart2_receive_char(void)
{
    while ((USART2->SR & USART_SR_RXNE) == 0)
    {
    }
    
    uint32_t data = (uint32_t) USART2->DR;

    return data;
}

void usart2_transmit_string(const char *str)
{   
    /* Kiểm tra con trỏ */
    if (str == NULL)
    {
        return;
    }
    
    /* Kiểm tra kí tự kết thúc */
    while (*str != '\0')
    {
        usart2_transmit_char((uint32_t) *str);
        str++;                                                      /* Hậu tố, tăng kí tự tiếp theo */ 
    }
    
}