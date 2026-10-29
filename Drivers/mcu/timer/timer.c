/*
 * timer.c
 *
 *  Created on: Oct 20, 2026
 *      Author: huynhthuan
 */

#include "timer.h"

void timer_init(void)
{
    TIM2->CR1 &= ~TIM2_CR1_CEN;
    TIM2->CR1 &= ~TIM2_CR1_DIR;

    /**  Co 4 nguon clock doc lap HSI, HSE, LSI, LSE
     * 	 Blue pill dung HSE 8MHz, PLL mach nhan/chia clock (x2 x4...x9)
     * 	 PLL nhan lam Output clock -> Dung PLL nhu nguon clock 8*9 = 72MHz
     *   -> Neu chua config PLL, mac dinh dung HSE 8MHz
     *
     *   PSC = 7
     *   8 000 000 / 8 = 1 000 000Hz
     *   T = 1/f = 1/1 000 000 = 0.000001s = 0.001ms
     *
     *   ARR = 999
     *   1 T(chu ky) -> 1tick = 0.001ms
     *                  10tick = 0.01 ms
     *                  100tick = 0.1ms
     *                  1000tick = 1ms
     * - Lay 1ms, de delay_ms(1000) chinh xac
     */
    TIM2->PSC = 7U;
    TIM2->ARR = 999U;

    /**
     *  UG (Update Generation)
     * - Dùng software set bit UG = 1 -> Ép timer cập nhật sự kiện (UEV)
     * - Reload lại thanh ghi CNT, PSC, ARR.
     * - Hardware tự động xóa bit UG sau khi xử lý.
     */
    TIM2->EGR = TIM2_EGR_UG;
    TIM2->CR1 |= TIM2_CR1_CEN;
}

void delay_ms(uint32_t ms)
{
    while (ms > 0)
    {
        /* Reset counter register */
        TIM2->CNT = 0;

        /* Reset UIF flags skip read-modify, only write */
        TIM2->SR = ~TIM2_SR_UIF; // 

        /* Wait until the UIF flags = 1 */
        /** 
         *  bitmask (TIM2_SR_UIF):     0x00000001
         *  reset UIF flags:           0x11111110
         ~ 
         */

        while ((TIM2->SR & TIM2_SR_UIF) == 0U)
        {
			/*
			 *  - When the timer counts 1ms, decrement ms (ms--)
			 *  Ex: delay_ms(1000) -> 999 -> ... -> 0
			 */
        }
         ms--;    
    }
    
}
