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


/* ================================ RCC Register Definitions ==================================*/
/**
 *  @brief RCC Structiure offset 
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

/**
 *  @brief memory mapping
 */
#define RCC_BASE                0x40021000UL
#define RCC                    ((RCC_Typedef *)RCC_BASE)

/**
 *  @brief RCC_CR bits
 *         - Bit chọn bật/tắt nguồn HSI, HSE, PLLCLK
 */
#define RCC_CR_HSION            (1UL << 0U)         /* Bật nguồn clock HSI */
#define RCC_CR_HSEON            (1UL << 16U)        /* Bật nguồn clock HSE */
#define RCC_CR_PLLON            (1UL << 24U)        /* Bật nguồn clock PLLCLK (không phải clock độc lập) */

/**
 * @brief RCC_CFGR bits
 */

/* SW (read-write) */   
#define RCC_CFGR_SW_MASK        (3UL << 0U)
#define RCC_CFGR_SW_HSI         (0UL << 0U)
#define RCC_CFGR_SW_HSE         (1UL << 0U)
#define RCC_CFGR_SW_PLL         (2UL << 0U)

/* SWS (read-only) */
#define RCC_CFGR_SWS_MASK       (3UL << 2U)
#define RCC_CFGR_SWS_HSI        (0UL << 2U)
#define RCC_CFGR_SWS_HSE        (1UL << 2U)
#define RCC_CFGR_SWS_PLL        (2UL << 2U)

/* AHB (rw) */
#define RCC_CFGR_HPRE_MASK      (15UL << 4U)                                  /* 1111: chia 512 */
#define RCC_CFGR_HPRE_DIV1      (0UL << 4U)                                   /* 0000: chia 1 */


/* APB1 (rw) */
#define RCC_CFGR_PPRE1_MASK     (7UL << 8U)                                   /* 111: chia 16 */
#define RCC_CFGR_PPRE1_DIV2     (4UL << 8U)                                   /* 100: chia 2, APB1 tối đa 36Mhz */

/* APB2 (rw) */
#define RCC_CFGR_PPRE2_MASK     (7UL << 11U)                                  /* 111: chia 16, lấy `&= ~` là chia 1 */
#define RcC_CFGR_PPRE2_DIV1     (0UL << 11U)

/* PLLSRC (rw) */
#define RCC_CFGR_PLLSRC         (1UL << 16U)

/* PLLMUL (rw) */
#define RCC_CFGR_PLLMUL_MASK    (15UL << 18U)
#define RCC_CFGR_PLLMUL_X9      (7UL << 18U)                                  /* 1001: nhân 9, tối đa 72Mhz */

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
 * 
 *  @param void
 *  @return void
 */
void rcc_init(void);

#endif /* RCC_H */

