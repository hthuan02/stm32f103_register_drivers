/*
 * timer.c
 *
 *  Created on: Oct 20, 2026
 *      Author: huynhthuan
 */

#include "timer.h"

void timer_init(void)
{   
    /* Disable the timer counter */
    TIM2->CR1 &= ~TIM2_CR1_CEN;

    /* Upcounting */
    TIM2->CR1 &= ~TIM2_CR1_DIR;
    
    /* Set up prescaler and auto-reload register (timer.md) */
    TIM2->PSC = 7U;
    TIM2->ARR = 999U;

    /* Force UG bit, generate update event (timer.md)*/
    TIM2->EGR = TIM2_EGR_UG;

    /* Enable the timer counter */
    TIM2->CR1 |= TIM2_CR1_CEN;
}

void delay_ms(uint32_t ms)
{
    while (ms > 0)
    {
        /* Reset counter register */
        TIM2->CNT = 0;

        /* Reset UIF flags skip read-modify, only write */
        TIM2->SR = ~TIM2_SR_UIF; 

        while ((TIM2->SR & TIM2_SR_UIF) == 0U)
        {
        }
         ms--;    
    }
    
}
