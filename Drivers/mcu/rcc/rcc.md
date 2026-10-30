# RCC Driver - Configuration Notes

## 1. RCC_CFGR Register

Nhiệm vụ của thanh ghi RCC_CFGR:

- Bit Chọn nguồn cho SYSCLK: `SW` (Software request), `SWS` (Hardware confirm).
- Bộ chia clock `HPRE` (AHB), `HPRE1` (APB1), `HPRE2` (APB2).
- `PLLMUL`: Bộ nhân clock.
- `PLLSRC`: Nguồn clock đầu vào cho PLL 
    + ==0, Chọn HSI /2 (đúng vs tree diagram)
    + ==1, Chọn HSE
- `PLLTPXRE`: Chia HSE
    + ==0, HSE/1
    + ==1, HSE/2

Chỗ tạo bitmask của thanh ghi RCC_CFGR đối với AHB, APB2, APB1. Không cần tạo bitmask ...DIV1
- Vì ...DIV1 có bitmast (0000)
- Nên có thể đặt clear bit trực tiếp Bitmask đó luôn. (&= ~...MASK).

## 2. The alternation of FLASH_ACR when incease clock frequency

- Do thay đổi tần só dao động từ mặc định nguồn clock HSI 8MHz --> PLLCLK 72MHz.
- CPU sẽ chạy nhanh hơn và Flash lưu chương trình không thể tùy ý thay đổi tốc độ đọc để bắt kịp RCC. Buộc phải cấu hình thanh ghi `FLASH_ACR` trước khi cấu hình `RCC`.

`PRFTBE`: cho phép nạp trước lệnh từ Flash (Giảm thời gian chờ trong khi nạp dữ liệu).
`LATENCY`: quy định số wait states khi đọc Flash; với SYSCLK 72 MHz, cần 2 wait states.

## 3. Uses while loop as checking condition 

- while1, while 2 chỉ có 1 bit (0 or 1): Nên lọc bit, chờ đến khi bật đúng bit gọi ra thì thoát while.

- while có 2 bit (00 01 10 11): Nên lọc bit + check điều kiện của bit hiện tại nếu == thì thoát while.