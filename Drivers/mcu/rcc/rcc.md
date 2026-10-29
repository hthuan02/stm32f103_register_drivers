# RCC Driver - Configuration Notes

## 1. RCC_CFGR Register

Nhiệm vụ của thanh ghi RCC_CFGR:

- Bit Chọn nguồn cho SYSCLK: `SW` (Software request), `SWS` (Hardware confirm).
- Bộ chia clock `HPRE` (AHB), `HPRE1` (APB1), `HPRE2` (APB2).
- `PLLMUL`: Bộ nhân clock.
- `PLLSRC`: Nguồn clock đầu vào cho PLL -> HSI. Chọn ==0 để /2 HSI (đúng)
- `PLLTPXRE`: Nguồn clock đàu vào PLL -> HSE. Không cần cấu hình

Chỗ tạo bitmask của thanh ghi RCC_CFGR đối với AHB, APB2, APB1. Không cần tạo bitmask ...DIV1
- Vì ...DIV1 có bitmast (0000)
- Nên có thể đặt clear bit trực tiếp Bitmask đó luôn. (&= ~...MASK).

## 2. The alternation of FLASH_ACR when incease clock frequency

- Do thay đổi tần só dao động từ mặc định nguồn clock HSI 8MHz --> PLLCLK 72MHz.
- CPU sẽ chạy nhanh hơn và Flash lưu chương trình không thể tùy ý thay đổi tốc độ đọc để bắt kịp RCC. Buộc phải cấu hình thanh ghi `FLASH_ACR` trước khi cấu hình `RCC`.