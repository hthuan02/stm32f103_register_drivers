# I2C Driver - Configuration Notes

## I2C_CCR
`Bluepill có 2 I2C1 & I2C2 dùng bus APB1 36Mhz`

Là thanh ghi chọn tốc độ truyền của giao tiếp I2C, có 3 chế độ
- Standard Mode (Sm): 100Khz
- Fast Mode (Fm): 400Khz
- Fast Mode Plus (Fm+): 1Mhz

```text
    # Standard mode: f_SCL = 100Khz (là FS)
    CCR = PCLK1 / (2 * f_SCL)
        = 36Mhz / (2 * 100KHz) = 180
```

## I2C_TRISE

I2C dùng AF_OpenDrain, luôn kéo xuống LOW mức 0. Nên phải dùng điện trở kéo lên gắn ngoài để kéo lên HIGH mức 1.

- Và khi từ LOW - HIGH không thể kéo ngay lập tức. Cần phải timing, thì thời gian này gọi là `Rise Time(tr)`.
- Thanh ghi I2C_TRISE là thanh ghi cấu hình thời gian SDA SCL kéo từ 0 lên 1.

```text
    # Standard mode: Rise Time max = 1000ns

    f_PCLK1 = 36Mhz
    T_PCLK1 = 1/36MHz = 27.78ns

    TRISE = (tr(max) / T_PCLK1) + 1
          = (1000ns / 27.78ns) + 1 
          = 37
```

```text
    # Fast mode: Rise Time max = 300ns

    f_PCLK1 = 36Mhz
    T_PCLK1 = 1/36MHz = 27.78ns

    TRISE = (tr(max) / T_PCLK1) + 1
          = (1000ns / 300ns) + 1 
          = 11.8
    --> (uint32_t) 11
```

## I2C_START & I2C_STOP
- START: Chờ cờ `SB` == 1, để xác nhận START được tạo, bắt đầu truyền/nhận
- STOP: Không có cờ STOP, hardware tự phát STOP khi == 1

# I2C_DR

Master gửi 7bits address cho Slave & 1 bit ACK để xác nhận việc đọc hoặc ghi
- R/W == 0: Write
- R/W == 1: Read

```c
    // 7 data_bit và 1 rw_bit
    
    // (data_bit << 1) 
    // (<< 1) bit để chừa bit LSB cho rw_bit

    // rw_bit & 0x01
    // Clear 7 bit đầu, & lấy 1 bit cuối làm LSB

    // (data_bit << 1) | (rw_bit & 0x01)

```

# I2C_ADDR

- ADDR (Address sent/matched flag) là cờ báo truyền 7 bit địa chỉ đã hoàn thành.
- Phần cứng của chip quy định khi đọc xong thanh ghi `SR1`, tiếp đến đọc xong thanh ghi `SR1`. Tự động xóa cờ `ADDR` (reset ADDR == 0).

```c
    // Clear SR1 SR2 flags
    (void) I2C1->SR1;
    (void) I2C1->SR2

    // Ép kiểu (void): Nghĩa là không quan tâm đến giá trị.
    // Không ép kiểu (vôid): Truy cập giá trị --> error.
    
    /** Cách 2: Clear SR1 SR2
     *  uint32_t temp;
     *  temp I2C1->SR1;
     *  temp I2C1->SR2;
     * 
     */
```