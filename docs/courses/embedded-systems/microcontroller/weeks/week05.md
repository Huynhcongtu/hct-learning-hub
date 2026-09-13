# BUỔI 05 — C, GPIO & chống dội

**Đọc trước:** Giáo trình trang **17–23**

<div class="week-meta">
<div><small>Track</small><strong>Lý thuyết</strong></div>
<div><small>Platform</small><strong>8051 / AT89S52</strong></div>
<div><small>Workflow</small><strong>PRE → LEC → CALC → VERIFY</strong></div>
</div>

## Mục tiêu

- Khai báo chân theo chức năng và giữ nguyên bit không liên quan.
- Giải thích quasi-bidirectional của port 8051.
- Phân biệt input active-low với output active-low.
- Thiết kế debounce theo trạng thái ổn định và sự kiện.

=== "PRE · Đọc trước"

    1. Đọc trang **17–23**.
    2. Gạch chân thanh ghi / khái niệm mới.
    3. Tự làm ví dụ trước khi xem kết quả.
    4. Viết **01 câu hỏi** mang đến lớp.

=== "LEC · Nội dung cốt lõi"

    ### GPIO
    8051 dùng cơ chế port khác MCU hiện đại. Để đọc một chân port quasi-bidirectional, phần mềm thường phải “thả” chân bằng cách ghi 1 trước.

    ### Bit operations
    Dùng mask để tránh phá các chân khác:
    - `x & mask` đọc.
    - `x | mask` đặt bit.
    - `x & ~mask` xóa bit.

    ### Chống dội
    Không đảo LED ở mọi vòng lặp khi nút đang giữ. Cần tách:
    - trạng thái mẫu,
    - candidate,
    - stable state,
    - sự kiện nhấn mới.

    Một cấu hình thực hành dùng 4 mẫu × 5 ms ≈ 20 ms để xác nhận ổn định.

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig08-debounce-stable-state.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig08-debounce-stable-state.png" alt="Chống dội theo trạng thái ổn định" loading="lazy">
      </a>
      <figcaption>Hình 8. Chỉ công nhận trạng thái sau khi tín hiệu ổn định đủ thời gian.</figcaption>
    </figure>

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig09-finite-state-machine.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig09-finite-state-machine.png" alt="Máy trạng thái hữu hạn" loading="lazy">
      </a>
      <figcaption>Hình 9. Mô hình trạng thái cho thiết bị điều khiển đơn giản.</figcaption>
    </figure>

=== "ACT · Hoạt động trên lớp"

    **Bài toán:** Thiết kế máy trạng thái nút nhấn sao cho giữ nút 3 s chỉ tạo một sự kiện.

    Yêu cầu: ghi rõ giả thiết, đơn vị, sơ đồ/timeline và cách kiểm chứng.

=== "SELF-CHECK"

    1. Vì sao `P1 && 0x08` không kiểm tra riêng P1.3?
    2. Giữ nút có nên tạo nhiều lần toggle?
    3. Cửa sổ debounce có phải luôn đúng 20 ms?

=== "AFTER · Sau lớp"

    - Hoàn thành engineering note ngắn.
    - Ghi điều đã hiểu, phép tính đã làm và câu hỏi còn vướng.
    - Nếu có mô phỏng, lưu ảnh có nhãn và đơn vị.
    - Không dùng số dự kiến thay số đo.


## Code minh họa

<div class="hct-code-actions">

[💻 Xem project trên GitHub](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W05_GPIO_Debounce){ .md-button .md-button--primary }
[⬇️ Mở main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/theory/W05_GPIO_Debounce/main.c){ .md-button }

</div>

```c
#include "common.h"
#include "delay.h"

PIN(LED,P1,0);
PIN(KEY,P3,2);

void main(void) {
    u8 stable=1, candidate=1, sample, count=0;

    EA=0; LED=1; KEY=1;

    for (;;) {
        sample=KEY;

        if(sample!=candidate) {
            candidate=sample;
            count=0;
        } else if(count<4) {
            ++count;
            if(count==4 && stable!=candidate) {
                stable=candidate;
                if(stable==0) LED=!LED;
            }
        }

        delay_ms(5);
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
