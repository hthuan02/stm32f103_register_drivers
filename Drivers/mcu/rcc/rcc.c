/*
 * rcc.c
 *
 *  Created on: Oct 20, 2026
 *      Author: huynhthuan
 */

#include "rcc.h"

/**
 *  @brief Initialize PLLCLK peripheral clock
 */
void rcc_pllclk_init(void)
{
    /* Configure Flash for 72 MHz */
    FLASH_ACR |= FLASH_ACR_PRFTBE;

    FLASH_ACR &= ~FLASH_ACR_LATENCY_MASK;                               /* Reset bits */
    FLASH_ACR |= FLASH_ACR_LATENCY_2WS;
    // FLASH_ACR = (FLASH_ACR & ~FLASH_ACR_LATENCY_MASK) | FLASH_ACR_LATENCY_2WS;	

    /* 1. Select HSE enable clock resource */
    RCC->CR |= RCC_CR_HSEON;

	while ((RCC->CR & RCC_CR_HSERDY) == 0U)
	{
	}

    /* Configure divider: AHB = /1, APB1 = /2, APB2 = /1 */
    RCC->CFGR &= ~(RCC_CFGR_HPRE_MASK |
                    RCC_CFGR_PPRE1_MASK |
                    RCC_CFGR_PPRE2_MASK);

    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;

    /* PLL entry source = HSE, PLL multiplier = x9 */
    RCC->CFGR &= ~(RCC_CFGR_PLLSRC_HSE |
                   RCC_CFGR_PLLXTPRE_HSE_NO_DIV |
                   RCC_CFGR_PLLMUL_MASK);                             /* Reset bits */

    RCC->CFGR |= RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMUL_X9;

    /* 2. Select PLL clock source */
    RCC->CR |= RCC_CR_PLLON;

    while ((RCC->CR & RCC_CR_PLLRDY) == 0U)
    {
    }

    /* 3. Select entry clock source for SYSCLK */
    RCC->CFGR &= ~RCC_CFGR_SW_MASK;                                  /* Reset bits */
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    /* Wait until PLL is the active SYSCLK */
    while ((RCC->CFGR & RCC_CFGR_SWS_MASK) != RCC_CFGR_SWS_PLL)
    {
    }
}

/**
 *  @brief Enable GPIOA peripheral clock
 */
void rcc_gpioa_clock_enable(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
}

/**
 *  @brief Enable GPIOB peripheral clock
 */
void rcc_gpiob_clock_enable(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
}

/**
 *  @brief Enable TIMER2 peripheral clock
 */
void rcc_timer2_clock_enable(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
}

/**
 *  @brief Enable USART2 peripheral clock
 */
void rcc_usart2_clock_enable(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
}
