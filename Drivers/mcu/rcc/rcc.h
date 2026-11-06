/*
 * rcc.h
 *
 *  Created on: Oct 20, 2026
 *      Author: huynhthuan
 */

#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>
#include "../../../Inc/stm32_rcc.h"

/**
 *  @brief RCC enable clock prototype function
 */
void rcc_pllclk_init(void);
void rcc_gpioa_clock_enable(void);
void rcc_gpiob_clock_enable(void);
void rcc_timer2_clock_enable(void);
void rcc_usart2_clock_enable(void);
void rcc_i2c1_clock_enable(void);

#endif /* RCC_H_ */

