/*
 * gpio.c
 *
 *  Created on: Oct 20, 2026
 *      Author: huynhthuan
 */


#include "gpio.h"
#include "../rcc/rcc.h"

void gpio_init()
{
	/* Enable GPIOA peripheral clock */
    rcc_gpioa_clock_enable();

    GPIOA->CRH &= ~ (GPIO_CRH_PIN9 |
                     GPIO_CRH_PIN10);
    
    GPIOA->CRL &= ~GPIO_CRL_PIN_0;

    // Output, 2Mhz to blink led
    GPIOA->CRH |= (GPIO_CRH_MODE9_OUTPUT_2MHZ |
                   GPIO_CRH_CNF9_OUTPUT_PP |
                   GPIO_CRH_MODE10_OUTPUT_2MHZ |
                   GPIO_CRH_CNF10_OUTPUT_PP);
    
   
    GPIOA->CRL |= GPIO_CRL_CNF0_INPUT_PULL |
                  GPIO_CRL_CNF1_INPUT_PULL;
    
                  
     GPIOA->ODR |= (1UL << 0U |
                    1UL << 1U);

}   
