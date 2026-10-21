/*
 * rcc.c
 *
 *  Created on: Oct 20, 2026
 *      Author: huynhthuan
 */

#include "rcc.h"

void rcc_init()
{
//    /* 1. Enable HSE = 8 MHz */
//    RCC->CR |= RCC_CR_HSEON;
//
//    while ((RCC->CR & RCC_CR_HSERDY) == 0U)
//    {
//    }
//
//    /* 2. Configure Flash for 72 MHz */
//    FLASH_ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY_2WS;
//
//    /* 3. Configure AHB = /1, APB1 = /2, APB2 = /1 */
//    RCC->CFGR &= ~(RCC_CFGR_HPRE_MASK |
//                   RCC_CFGR_PPRE1_MASK |
//                   RCC_CFGR_PPRE2_MASK);
//
//    RCC->CFGR |= (4UL << 8U);  /* PPRE1 = 100: APB1 /2 */
//
//    /* 4. PLL source = HSE, PLL multiplier = x9 */
//    RCC->CFGR &= ~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLMUL_MASK);
//    RCC->CFGR |= RCC_CFGR_PLLSRC | RCC_CFGR_PLLMUL_X9;
//
//    /* 5. Enable PLL and wait until ready */
//    RCC->CR |= RCC_CR_PLLON;
//
//    while ((RCC->CR & RCC_CR_PLLRDY) == 0U)
//    {
//    }
//
//    /* 6. Select PLL as SYSCLK */
//    RCC->CFGR &= ~(3UL << 0U);
//    RCC->CFGR |= RCC_CFGR_SW_PLL;
//
//    /* 7. Wait until PLL is the active SYSCLK */
//    while ((RCC->CFGR & RCC_CFGR_SWS_MASK) != RCC_CFGR_SWS_PLL)
//    {
//    }

    /* 8. Enable GPIOA and TIM2 peripheral clocks */
    RCC->APB2ENR |= RCC_IOPAEN;
    RCC->APB1ENR |= RCC_TIM2EN;
}
