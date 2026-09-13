# BUỔI 02 — Sơ đồ chân, mạch tối thiểu & bộ nhớ

**Đọc trước:** Giáo trình trang **8–10**

<div class="week-meta">
<div><small>Track</small><strong>Lý thuyết</strong></div>
<div><small>Platform</small><strong>8051 / AT89S52</strong></div>
<div><small>Workflow</small><strong>PRE → LEC → CALC → VERIFY</strong></div>
</div>

## Mục tiêu

- Đọc sơ đồ chân AT89S52 PDIP40.
- Giải thích nguồn, clock, reset và EA.
- Phân biệt dung lượng Flash thực với không gian CODE.
- Phân biệt truy cập trực tiếp SFR và truy cập gián tiếp RAM cao.

=== "PRE · Đọc trước"

    1. Đọc trang **8–10**.
    2. Gạch chân thanh ghi / khái niệm mới.
    3. Tự làm ví dụ trước khi xem kết quả.
    4. Viết **01 câu hỏi** mang đến lớp.

=== "LEC · Nội dung cốt lõi"

    ### AT89S52 tham chiếu
    AT89S52 tương thích tập lệnh 8051, có 8 KiB Flash, 256 byte RAM và Timer 2. Bài cốt lõi ưu tiên Timer 0/1 và GPIO để dễ chuyển đổi.

    ### Mạch tối thiểu
    - VCC 40, GND 20.
    - EA 31 lên VCC khi chạy Flash nội.
    - XTAL1/XTAL2 dùng 11.0592 MHz.
    - RST tích cực cao.
    - Tụ 100 nF đặt gần VCC/GND.

    ### Bộ nhớ
    Không gian CODE có thể địa chỉ hóa 64 KiB nhưng Flash vật lý của AT89S52 chỉ 8 KiB.
    Trong vùng 80H–FFH, truy cập trực tiếp chọn SFR; truy cập gián tiếp có thể chọn RAM cao trên S52.

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig04-at89s52-pinout.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig04-at89s52-pinout.png" alt="Sơ đồ chân AT89S52 PDIP40" loading="lazy">
      </a>
      <figcaption>Hình 4. Sơ đồ chân AT89S52 PDIP 40 nhìn từ trên.</figcaption>
    </figure>

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig05-at89s52-minimum-system.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig05-at89s52-minimum-system.png" alt="Mạch tối thiểu AT89S52" loading="lazy">
      </a>
      <figcaption>Hình 5. Kết nối tối thiểu cho mạch thực hành AT89S52.</figcaption>
    </figure>

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig06-code-ram-sfr-map.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig06-code-ram-sfr-map.png" alt="CODE RAM và SFR trên AT89S52" loading="lazy">
      </a>
      <figcaption>Hình 6. Cách phân biệt CODE, RAM và SFR trên AT89S52.</figcaption>
    </figure>

=== "ACT · Hoạt động trên lớp"

    **Bài toán:** VCC = 5 V nhưng LED không chạy và RST ≈ 5 V liên tục. Xác định thứ tự kiểm tra.

    Yêu cầu: ghi rõ giả thiết, đơn vị, sơ đồ/timeline và cách kiểm chứng.

=== "SELF-CHECK"

    1. P3.0/P3.1 còn là GPIO độc lập khi UART đang hoạt động không?
    2. Vì sao 64 KiB CODE không có nghĩa chip có sẵn 64 KiB Flash?
    3. Tại sao phải kiểm tra EA trước khi sửa code?

=== "AFTER · Sau lớp"

    - Hoàn thành engineering note ngắn.
    - Ghi điều đã hiểu, phép tính đã làm và câu hỏi còn vướng.
    - Nếu có mô phỏng, lưu ảnh có nhãn và đơn vị.
    - Không dùng số dự kiến thay số đo.


## Code minh họa

<div class="hct-code-actions">

[💻 Xem project trên GitHub](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W02_Minimum_System_IO){ .md-button .md-button--primary }
[⬇️ Mở main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/theory/W02_Minimum_System_IO/main.c){ .md-button }

</div>

```c
#include "common.h"

PIN(LED, P1, 0);

void main(void) {
    EA = 0;
    LED = 1; /* active-low LED: OFF */

    for (;;) {
        /* Hardware exercise:
         * verify VCC, GND, EA, RST and clock before debugging code. */
        LED = 0;
        NOP(); NOP(); NOP();
        LED = 1;
        NOP(); NOP(); NOP();
    }
}
```

!!! info
    Code ở mục này là **SUPPLEMENTAL**: ví dụ bổ sung theo nội dung buổi học,
    không phải đoạn mã nguyên văn của giáo trình.

## Checklist

- [ ] Đọc phần được giao
- [ ] Làm phép tính / self-check
- [ ] Có ít nhất một câu hỏi
- [ ] Hoàn thành hoạt động
- [ ] Lưu bằng chứng
