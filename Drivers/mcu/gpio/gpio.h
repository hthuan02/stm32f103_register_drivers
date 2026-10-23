/*
 * gpio.h
 *
 *  Created on: Oct 20, 2026
 *      Author: huynhthuan
 */

#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#define __vo volatile

/**
 *  Offset of GPIO register
 */
typedef struct
{
    __vo uint32_t CRL;
    __vo uint32_t CRH;
    __vo uint32_t IDR;
    __vo uint32_t ODR;
    __vo uint32_t BSRR;
    __vo uint32_t BRR;
    __vo uint32_t LCKR;

}GPIO_Typedef;

/**
 *  Memory mapping GPIO register
 */
#define GPIOA_BASE 0x40010800UL
#define GPIOA ((GPIO_Typedef *)GPIOA_BASE)

/*
 * GPIO - Use bitmask
 */

#define GPIOA_CRH_PA10_MASK     (0x0FUL << 8U)
#define GPIOA_CRH_PA9_MASK      (0x0FUL << 4U)
#define GPIOA_CRL_PA0_MASK      (0x0FUL << 0U)
#define GPIOA_CRL_PA1_MASK      (0x0FUL << 1U)

#define GPIOA_CRH_MODE9_OUTPUT_2MHZ        (2UL << 4U)
#define GPIOA_CRH_CNF9_OUTPUT_PP            0UL
#define GPIOA_CRH_MODE10_OUTPUT_2MHZ       (2UL << 8U)
#define GPIOA_CRH_CNF10_OUTPUT_PP           0UL
#define GPIOA_CRL_CNF0_INPUT_PULL          (2UL << 2U)
#define GPIOA_CRL_CNF1_INPUT_PULL          (2UL << 6U)


/**
 *  Prototype function
 */
void gpio_init(void);

#endif // GPIO_H
