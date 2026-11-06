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
 *  @brief Offset of GPIO register
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
 *  @brief Memory mapped register
 */
#define GPIOA_BASE  0x40010800UL
#define GPIOB_BASE  0x40010C00UL
#define GPIOC_BASE  0x40011000UL
#define GPIOD_BASE  0x40011400UL
#define GPIOE_BASE  0x40011800UL
#define GPIOA   ((GPIO_Typedef *)GPIOA_BASE)
#define GPIOB   ((GPIO_Typedef *)GPIOA_BASE)
#define GPIOC   ((GPIO_Typedef *)GPIOA_BASE)
#define GPIOD   ((GPIO_Typedef *)GPIOA_BASE)
#define GPIOE   ((GPIO_Typedef *)GPIOA_BASE)

/**
 *  @brief CRL bits
 */
#define GPIO_CRL_PIN_0                (0xFUL << 0U)
#define GPIO_CRL_PIN_1                (0xFUL << 4U)
#define GPIO_CRL_PIN_2                (0xFUL << 8U)
#define GPIO_CRL_PIN_3                (0xFUL << 12U)
#define GPIO_CRL_PIN_6                (0xFUL << 24U)
#define GPIO_CRL_PIN_7                (0xFUL << 28U)

/**
 *  @brief CRH bits
 */
#define GPIO_CRH_PIN9                 (0xFUL << 4U)
#define GPIO_CRH_PIN10                (0xFUL << 8U)

/**
 *  @brief CRL bitmask
 */
/* BUTTON 1 2 */
#define GPIO_CRL_CNF0_INPUT_PULL         (2UL << 2U)
#define GPIO_CRL_CNF1_INPUT_PULL         (2UL << 6U)

/* USART2 */
#define GPIO_CRL_MODE2_OUTPUT_2MHZ       (2UL << 8U)
#define GPIO_CRL_CNF2_AF_PP              (2UL << 10U)
#define GPIO_CRL_MODE3_INPUT             0UL
#define GPIO_CRL_CNF3_INPUT_FLOATING     (1UL << 14U)

/* I2C1*/
#define GPIO_CRL_PIN_6_50MHZ_AF_OD       (0xFUL << 24U)                 /* MODE_bits: Output 50MHZ (11) */
#define GPIO_CRL_PIN_7_50MHZ_AF_OD       (0xFUL << 28U)                 /* CNF_bits: AF_OD (11) */

/**
 *  @brief CRH bitmask
 */
/* LED1 */
#define GPIO_CRH_MODE9_OUTPUT_2MHZ       (2UL << 4U)
#define GPIO_CRH_CNF9_OUTPUT_PP          0UL

/* LED2 */
#define GPIO_CRH_MODE10_OUTPUT_2MHZ      (2UL << 8U)
#define GPIO_CRH_CNF10_OUTPUT_PP         0UL


#endif /* STM32_GPIO_H_ */
