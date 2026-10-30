# STMF103C8T6 Register Drivers

https://docs.google.com/document/d/16FRHLIoe78qfctlE34TOy7OcR2Rvi9QGmCKG_Lbty2o/edit?tab=t.ie2sbbpyxhg0
_(Tài liệu docs được tổng hợp từ RM0008)_

---
## Giới thiệu dự án

Dự án tập trung vào việc nghiên cứu và phát triển các driver ngoại vi cho vi điều khiển **STM32F103C8T6 bằng phương pháp lập trình thanh ghi (register-level programming)**, dựa trên tài liệu tham chiếu *STM32F1 Reference Manual (RM0008)*.

Các driver được xây dựng và kiểm thử trong môi trường **STM32CubeIDE**, nhằm tìm hiểu cách cấu hình thanh ghi, điều khiển phần cứng và quản lý hoạt động của các ngoại vi ở mức thấp, hạn chế phụ thuộc vào các thư viện trừu tượng hóa phần cứng.

## Danh sách driver

Dự án được tổ chức theo từng nhóm ngoại vi:

- **RCC (Reset and Clock Control):** Cấu hình nguồn clock, hệ thống clock và clock cho các ngoại vi.
- **GPIO (General-Purpose Input/Output):** Cấu hình và điều khiển các chân input/output.
- **TIM (Timer):** Cấu hình bộ định thời, bộ đếm và các chức năng liên quan.
- **USART:** Truyền thông nối tiếp bất đồng bộ.
- **SPI:** Truyền thông nối tiếp đồng bộ.
- **I2C:** Giao tiếp giữa các thiết bị ngoại vi sử dụng bus I2C.
- **ADC:** Chuyển đổi tín hiệu tương tự sang dữ liệu số.
- **DMA:** Truyền dữ liệu trực tiếp giữa các vùng nhớ hoặc giữa bộ nhớ và ngoại vi.
- **Interrupt:** Cấu hình và xử lý ngắt từ ngoại vi.

## Cấu trúc tài liệu cho từng driver

Mỗi driver được trình bày theo ba phần chính:

1. **Register Mapping:** Địa chỉ cơ sở, cấu trúc thanh ghi, offset và chức năng của các bit liên quan.
2. **Register Configuration:** Cách cấu hình thanh ghi để thiết lập và điều khiển ngoại vi.
3. **Peripheral Usage:** Ví dụ sử dụng driver trên phần cứng thực tế, kèm theo quá trình kiểm thử và kết quả mong đợi.

## Mục tiêu dự án

- Củng cố kiến thức về kiến trúc vi điều khiển và memory-mapped registers.
- Nâng cao kỹ năng lập trình C ở mức thanh ghi và thiết kế driver ngoại vi.
- Hiểu rõ mối liên hệ giữa cấu hình thanh ghi, hoạt động phần cứng và kết quả thực thi.
- Xây dựng nền tảng cho việc phát triển firmware và hệ thống nhúng ở mức thấp.

---

<details>
  <summary><h2>Driver1: RCC</h2></summary>

## 1. Memory mapping register

## 2. Register Configuration

## 3. Use peripheral

</details>



<details>
  <summary><h2>Driver2: GPIO</h2></summary>
    
## 1. Memory mapping register


## 2. Register Configuration

## 3. Use peripheral
</details>


<details>
  <summary><h2>Driver3: TIMER</h2></summary>
    
</details>


