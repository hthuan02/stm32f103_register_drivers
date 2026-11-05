/*
 * stm32_gpio.h
 *
 *  Created on: Nov 5, 2026
 *      Author: huynhthuan
 */

#ifndef STM32_GPIO_H_
#define STM32_GPIO_H_

#include <stdint.h>
#define __vo volatile

/* ================================ GPIO Register Definitions =================================*/
/**
 *  Offset of GPIO register
 */
typedef struct
{
    __vo uint32_t CRL;                  /* Offset: 0x00 */
    __vo uint32_t CRH;                  /* ... */
    __vo uint32_t IDR;
    __vo uint32_t ODR;
    __vo uint32_t BSRR;
    __vo uint32_t BRR;
    __vo uint32_t LCKR;

}GPIO_Typedef;

/**
 *  Memory mapping GPIO register
 */
#define GPIOA_BASE                        0x40010800UL
#define GPIOA                             ((GPIO_Typedef *)GPIOA_BASE)

/*
 * @brief GPIOA bitmask
 */
/* PA0 */
#define GPIOA_CRL_PA0_MASK                (0xFUL << 0U)
#define GPIOA_CRL_CNF0_INPUT_PULL         (2UL << 2U)

/* PA1 */
#define GPIOA_CRL_PA1_MASK                (0xFUL << 4U)
#define GPIOA_CRL_CNF1_INPUT_PULL         (2UL << 6U)

/* PA2_tx */
#define GPIOA_CRL_PA2_MASK                (0xFUL << 8U)
#define GPIOA_CRL_MODE2_OUTPUT_2MHZ       (2UL << 8U)
#define GPIOA_CRL_CNF2_AF_PP              (2UL << 10U)

/* PA3_rx */
#define GPIOA_CRL_PA3_MASK                (0xFUL << 12U)
#define GPIOA_CRL_MODE3_INPUT             0UL
#define GPIOA_CRL_CNF3_INPUT_FLOATING     (1UL << 14U)

/* PA9 */
#define GPIOA_CRH_PA9_MASK                (0xFUL << 4U)
#define GPIOA_CRH_MODE9_OUTPUT_2MHZ       (2UL << 4U)
#define GPIOA_CRH_CNF9_OUTPUT_PP          0UL

/* PA10 */
#define GPIOA_CRH_PA10_MASK               (0x0FUL << 8U)  
#define GPIOA_CRH_MODE10_OUTPUT_2MHZ      (2UL << 8U)
#define GPIOA_CRH_CNF10_OUTPUT_PP         0UL

#endif /* STM32_GPIO_H_ */
