# TIM2 Driver — Configuration Notes

## 1. Prescaler and Auto-Reload Registers

- We have four main clock sources: HSI, HSE, LSI, and LSE.
- However, the `Blue Pill` board uses HSI, HSE, and PLL (the PLL is not an independent clock source).
- If we don't configure the RCC, the system will use the HSI clock at 8 MHz by default.

We have the following frequency:

HSI = 8 MHz

```text
    PSC = 8
    8,000,000 / 8 = 1,000,000 Hz
    T = 1/f = 1/1,000,000 = 0.000001 s = 0.001 ms

    ARR = 1000
    1 T  -> 1 tick = 0.001 ms
            10 ticks = 0.01 ms
            100 ticks = 0.1 ms
            1000 ticks = 1 ms
    Take a period (T) of 1 ms, exactly for delay_ms(1000).

    Because the timer counts from 0 to the ARR register value, we must subtract one.
    So:
        PSC: 7
        ARR: 999
```
## 2. Force UG bit of EGR register

```text
/**
 *  UG (Update Generation)
 * - Dùng software set bit UG = 1 -> Ép timer cập nhật sự kiện (UEV)
 * - Reload lại thanh ghi CNT, PSC, ARR.
 * - Hardware tự động xóa bit UG sau khi xử lý.
 */

```
