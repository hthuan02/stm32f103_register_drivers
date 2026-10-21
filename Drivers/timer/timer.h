/*
 * timer.h
 *
 *  Created on: Oct 20, 2026
 *      Author: huynhthuan
 */


#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>
#define __vo volatile

/**
 *  Offset of TIM register
 */
typedef struct
{
    __vo uint32_t CR1;
    __vo uint32_t CR2;
    __vo uint32_t SMCR;
    __vo uint32_t DIER;
    __vo uint32_t SR;
    __vo uint32_t EGR;
    __vo uint32_t CCMR1;
    __vo uint32_t CCMR2;
    __vo uint32_t CCER;
    __vo uint32_t CNT;
    __vo uint32_t PSC;
    __vo uint32_t ARR;
    /**
     * Register remain unused
     */

}TIM_Typedef;


/**
 *  Timer2 - Memory mapping register
 */
#define TIM2_BASE       0x40000000UL
#define TIM2            ((TIM_Typedef *)TIM2_BASE)

/**
 *  Use bits of timer register
 */
#define TIM2_CR1_CEN        (1UL << 0U)
#define TIM2_CR1_DIR        (1UL << 4U)

#define TIM2_SR_UIF         (1UL << 0U)
#define TIM2_EGR_UG         (1UL << 0U)

#define TIM2_CNT_MASK            0xFFFFUL
#define TIM2_PSC_MASK            0xFFFFUL
#define TIM2_ARR_MASK            0xFFFFUL

void timer_init(void);
void delay_ms(uint32_t ms);

#endif  // TIMER_H
