/*
 * gpio.c
 *
 *  Created on: Oct 20, 2026
 *      Author: huynhthuan
 */


#include "gpio.h"

void gpio_init()
{
    GPIOA->CRH &= ~ (GPIOA_CRH_PA9_MASK |
                     GPIOA_CRH_PA10_MASK);

    // Output, 2Mhz to blink led
    GPIOA->CRH |= (GPIOA_CRH_MODE9_OUTPUT_2MHZ |
                   GPIOA_CRH_CNF9_OUTPUT_PP |
                   GPIOA_CRH_MODE10_OUTPUT_2MHZ |
                   GPIOA_CRH_CNF10_OUTPUT_PP);

}
