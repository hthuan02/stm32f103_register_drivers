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

/* ================================ FLASH Access Control Registers ============================*/

/**
 *  @brief Memory mapped FLASH_ACR register
 */
#define FLASH_BASE              0x40022000UL
#define FLASH_ACR               (*(volatile uint32_t *) FLASH_BASE)

/**
 *  @brief FLASH_ACR bits (rw)
 */
#define FLASH_ACR_LATENCY_MASK  (3UL << 0U)
#define FLASH_ACR_LATENCY_2WS   (2UL << 0U)
#define FLASH_ACR_PRFTBE        (1UL << 4U)


/* ================================ RCC Register Definitions ==================================*/
/**
 *  @brief RCC Structure offset 
 */
typedef struct
{
    __vo uint32_t CR;                               /* Offset: 0x00 */ 
    __vo uint32_t CFGR;                             /* Offset: 0x04 */
    __vo uint32_t CIR;                              /* Offset: 0x08 */
    __vo uint32_t APB2RSTR;                         /* Offset: 0x0C */
    __vo uint32_t APB1RSTR;                         /* Offset: 0x10 */
    __vo uint32_t AHBENR;                           /* Offset: 0x14 */
    __vo uint32_t APB2ENR;                          /* Offset: 0x18 */
    __vo uint32_t APB1ENR;                          /* Offset: 0x1C */
    __vo uint32_t BDCR;                             /* Offset: 0x20 */
    __vo uint32_t CSR;                              /* Offset: 0x24 */
} RCC_Typedef;

/**
 *  @brief Memory mapping
 */
#define RCC_BASE                0x40021000UL
#define RCC                     ((RCC_Typedef *)RCC_BASE)

/**
 *  @brief RCC_CR bits
 */
#define RCC_CR_HSION            (1UL << 0U)         /* Turn on the HSI clock source (rw)  */
#define RCC_CR_HSIRDY           (1UL << 1U)         /* Check bit the HSI clock source is ready (r) */

#define RCC_CR_HSEON            (1UL << 16U)        /* (rw) */
#define RCC_CR_HSERDY           (1UL << 17U)        /* (r) */

#define RCC_CR_PLLON            (1UL << 24U)        /* (rw) */
#define RCC_CR_PLLRDY           (1UL << 25U)        /* (r) */

/**
 * @brief RCC_CFGR bits (rw)
 *        Select clock source for SYSCLK (HSI, HSE or PLL)
 * 
 */
/* SW */   
#define RCC_CFGR_SW_MASK        (3UL << 0U)
#define RCC_CFGR_SW_HSI         (0UL << 0U)
#define RCC_CFGR_SW_HSE         (1UL << 0U)
#define RCC_CFGR_SW_PLL         (2UL << 0U)

/* SWS */
#define RCC_CFGR_SWS_MASK       (3UL << 2U)
#define RCC_CFGR_SWS_HSI        (0UL << 2U)
#define RCC_CFGR_SWS_HSE        (1UL << 2U)
#define RCC_CFGR_SWS_PLL        (2UL << 2U)

/* AHB */
#define RCC_CFGR_HPRE_MASK      (15UL << 4U)        /* 1111: divide 512 */
#define RCC_CFGR_HPRE_DIV1      (0UL << 4U)         /* 0000: divide 1 */


/* APB1 */
#define RCC_CFGR_PPRE1_MASK     (7UL << 8U)         /* 111: divide 16 */
#define RCC_CFGR_PPRE1_DIV2     (4UL << 8U)         /* 100: divide 2, the APB1 have max frequency 36Mhz */

/* APB2 */
#define RCC_CFGR_PPRE2_MASK     (7UL << 11U)        /* 111: divide 16 , take `&= ~` is divide 1 */
#define RCC_CFGR_PPRE2_DIV1     (0UL << 11U)

/* PLLSRC */
#define RCC_CFGR_PLLSRC_HSI     (0UL << 16U)
#define RCC_CFGR_PLLSRC_HSE     (1UL << 16U)

/* PLLXTPRE */
#define RCC_CFGR_PLLXTPRE_HSE_NO_DIV       (0UL << 17U)
#define RCC_CFGR_PLLXTPRE_HSE_DIV2         (1UL << 17U) 

/* PLLMUL */
#define RCC_CFGR_PLLMUL_MASK    (15UL << 18U)
#define RCC_CFGR_PLLMUL_X9      (7UL << 18U)       /* 1001: multi 9, max frequency 72Mhz */

/**
 *  @brief RCC_APB2 bits
 */
#define RCC_APB2ENR_IOPAEN              (1UL << 2U)
#define RCC_APB2ENR_IOPBEN              (1UL << 3U)
#define RCC_APB2ENR_IOPCEN              (1UL << 4U)

/**
 *  @brief RCC_APB1 bits
 */
#define RCC_APB1ENR_TIM2EN              (1UL << 0U)

/**
 *  @brief Function prototype
 *  @param void
 *  @return void
 */
void rcc_init(void);

#endif /* RCC_H */

