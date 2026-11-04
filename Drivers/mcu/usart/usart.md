# USART Driver - Configuration Notes

## 1. Modify BRR register by Mantissa and Fraction bits


```c
	/**
	 * 	USART_DIV = PCLK1 / (16 * Baudrate) = 36Mhz / (16 * 9600) = 234.375
	 *  
	 *  - PCLK1: 36MHz (clock bus APB1 - đã cấu hình RCC )
	 *  - Oversampling STM32F10x = 16. Chọn tốc độ baudrate mong muốn; Baudrate = 9600
	 *  - Mantissa [15:4] (Số nguyên) = 234
	 *  - Fraction [3:0] (Số thập phân) = 0.375 * 16 = 6
	 *  - BRR = Mantissa << 4 | Fraction = (234 << 4) | 6 = 3744 | 6 = 3750
     *            0000 1110 1010 0000 (đã << 4)
     *            0000 0000 0000 0110 
     *   OR (|)   ---------------------
     *            0000 1110 1010 0110 = 3750
     * 
     *   -> BRR = 3750         
	 */
```

- OverSampling là cơ chế lấy mẫu, có 2 loại là `OVER8` và `OVER16`. Riêng STMF1 chỉ sử dụng `OVER16`, còn lại có thể sử dụng cả `OVER16` và `OVER8`.

- Vì vậy, đối với STM32F1 có thể tính trực tiếp lấy `pclk_hz / baud` mà không cần tính trung gian qua `mantissa` và `fraction`.
