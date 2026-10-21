/*
 * rcc.h
 *
 *  Created on: Oct 20, 2026
 *      Author: huynhthuan
 */

#ifndef RCC_H
#define RCC_H

#include <stdint.h>

#define __vo volatile

/*
 * RCC register structure
 */
typedef struct
{
    __vo uint32_t CR;           // Offset: 0x00
    __vo uint32_t CFGR;         // Offset: 0x04
    __vo uint32_t CIR;          // Offset: 0x08
    __vo uint32_t APB2RSTR;     // Offset: 0x0C
    __vo uint32_t APB1RSTR;     // Offset: 0x10
    __vo uint32_t AHBENR;       // Offset: 0x14
    __vo uint32_t APB2ENR;      // Offset: 0x18
    __vo uint32_t APB1ENR;      // Offset: 0x1C
    __vo uint32_t BDCR;         // Offset: 0x20
    __vo uint32_t CSR;          // Offset: 0x24
} RCC_Typedef;

/*
 * RCC memory mapping
 */
#define RCC_BASE                0x40021000UL
#define RCC                    ((RCC_Typedef *)RCC_BASE)

/*
 * Peripheral clock enable
 */
#define RCC_IOPAEN              (1UL << 2U)
#define RCC_IOPBEN              (1UL << 3U)
#define RCC_IOPCEN              (1UL << 4U)
#define RCC_TIM2EN              (1UL << 0U)

/*
 * FLASH Access Control Register
 */
#define FLASH_ACR               (*(volatile uint32_t *)0x40022000UL)

/* FLASH_ACR bits */
#define FLASH_ACR_LATENCY_2WS   (2UL << 0U)
#define FLASH_ACR_PRFTBE        (1UL << 4U)

/*
 * RCC_CR bits
 */
#define RCC_CR_HSION            (1UL << 0U)
#define RCC_CR_HSIRDY           (1UL << 1U)
#define RCC_CR_HSEON            (1UL << 16U)
#define RCC_CR_HSERDY           (1UL << 17U)
#define RCC_CR_PLLON            (1UL << 24U)
#define RCC_CR_PLLRDY           (1UL << 25U)

/*
 * RCC_CFGR bits
 */
#define RCC_CFGR_SW_MASK        (3UL << 0U)
#define RCC_CFGR_SW_PLL         (2UL << 0U)

#define RCC_CFGR_SWS_MASK       (3UL << 2U)
#define RCC_CFGR_SWS_PLL        (2UL << 2U)

#define RCC_CFGR_HPRE_MASK      (15UL << 4U)
#define RCC_CFGR_PPRE1_MASK     (7UL << 8U)
#define RCC_CFGR_PPRE2_MASK     (7UL << 11U)

#define RCC_CFGR_PPRE1_DIV2     (4UL << 8U)

#define RCC_CFGR_PLLSRC         (1UL << 16U)
#define RCC_CFGR_PLLMUL_MASK    (15UL << 18U)
#define RCC_CFGR_PLLMUL_X9      (7UL << 18U)

/*
 * Function prototype
 */
void rcc_init(void);

#endif /* RCC_H */
