# BUỔI 15 — Ôn tập & bài tập tổng hợp

**Đọc trước:** Giáo trình trang **61–63**

<div class="week-meta">
<div><small>Track</small><strong>Lý thuyết</strong></div>
<div><small>Platform</small><strong>8051 / AT89S52</strong></div>
<div><small>Workflow</small><strong>PRE → LEC → CALC → VERIFY</strong></div>
</div>

## Mục tiêu

- Kết nối kiến thức số, timer, UART, ADC/DAC và state machine.
- Giải bài có phép tính rõ từng bước.
- Thiết kế hệ nhỏ kèm bộ test.
- Tự đánh giá bằng bằng chứng thay vì số dòng code.

=== "PRE · Đọc trước"

    1. Đọc trang **61–63**.
    2. Gạch chân thanh ghi / khái niệm mới.
    3. Tự làm ví dụ trước khi xem kết quả.
    4. Viết **01 câu hỏi** mang đến lớp.

=== "LEC · Nội dung cốt lõi"

    ### Nhóm bài tính
    - Chuyển đổi số và bit operations.
    - Reload Timer.
    - Baud rate và thời gian truyền.
    - ADC0804 + LM35.
    - DAC0808 và tần số waveform.

    ### Nhóm bài thiết kế
    - Bộ đếm nút 00–99 với debounce.
    - PWM 20 bước.
    - Hệ đo nhiệt độ có timeout và vẫn phục vụ UART.
    - Phân bổ tài nguyên và thiết kế test.

    ### Chuyển sang MCU hiện đại
    Signal, state machine, timing, debounce, timeout và verification vẫn giữ giá trị. GPIO, clock, voltage, peripheral và register phải đọc lại cho nền tảng mới.

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig27-measurement-debug-flow.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig27-measurement-debug-flow.png" alt="Verification và troubleshooting" loading="lazy">
      </a>
      <figcaption>Hình 27. Tư duy kiểm chứng và khoanh vùng lỗi dựa trên phép đo.</figcaption>
    </figure>

=== "ACT · Hoạt động trên lớp"

    **Bài toán:** Chọn một bài đã làm và viết lại specification + test cases độc lập với 8051 để có thể port sang MCU khác.

    Yêu cầu: ghi rõ giả thiết, đơn vị, sơ đồ/timeline và cách kiểm chứng.

=== "SELF-CHECK"

    1. Điều gì giữ nguyên khi chuyển 8051 sang STM32/AVR?
    2. Điều gì không được copy nguyên xi?
    3. Thiết kế tốt cần minh chứng gì ngoài source code?

=== "AFTER · Sau lớp"

    - Hoàn thành engineering note ngắn.
    - Ghi điều đã hiểu, phép tính đã làm và câu hỏi còn vướng.
    - Nếu có mô phỏng, lưu ảnh có nhãn và đơn vị.
    - Không dùng số dự kiến thay số đo.


## Code minh họa

<div class="hct-code-actions">

[💻 Xem project trên GitHub](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W15_Portable_Test_Cases){ .md-button .md-button--primary }
[⬇️ Mở main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/theory/W15_Portable_Test_Cases/main.c){ .md-button }

</div>

```c
#include "common.h"

typedef struct {
    u8 input;
    u8 expected;
} test_case_t;

test_case_t ROM cases[]={
    {35u,0u},
    {42u,1u},
    {40u,1u},
    {38u,0u}
};

void main(void) {
    u8 i;

    /* The table is deliberately platform-independent:
     * the same functional cases can be reused after porting to another MCU. */
    for(i=0;i<4u;i++) {
        P1=cases[i].input;
        P2=cases[i].expected;
    }

    for (;;) { }
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
