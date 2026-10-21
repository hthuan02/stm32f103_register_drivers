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
    __vo uint32_t CR1;          // Offset: 0x00
    __vo uint32_t CR2;          // 0x04
    __vo uint32_t SMCR;         // 0x08
    __vo uint32_t DIER;         // 0x0C
    __vo uint32_t SR;           // 0x10
    __vo uint32_t EGR;          // 0x14
    __vo uint32_t CCMR1;        // 0x18
    __vo uint32_t CCMR2;        // 0x1C
    __vo uint32_t CCER;         // 0x20
    __vo uint32_t CNT;          // 0x24
    __vo uint32_t PSC;          // 0x28
    __vo uint32_t ARR;          // 0x2C
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
