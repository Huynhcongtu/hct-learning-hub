# BUỔI 09 — Dữ liệu dùng chung với ISR

**Đọc trước:** Giáo trình trang **28–30**

<div class="week-meta">
<div><small>Track</small><strong>Lý thuyết</strong></div>
<div><small>Platform</small><strong>8051 / AT89S52</strong></div>
<div><small>Workflow</small><strong>PRE → LEC → CALC → VERIFY</strong></div>
</div>

## Mục tiêu

- Nhận biết race condition giữa main và ISR.
- Giải thích vì sao biến 16 bit không nhất thiết được đọc nguyên tử trên 8051.
- Bảo vệ critical section ngắn.
- Xác định ownership của dữ liệu.

=== "PRE · Đọc trước"

    1. Đọc trang **28–30**.
    2. Gạch chân thanh ghi / khái niệm mới.
    3. Tự làm ví dụ trước khi xem kết quả.
    4. Viết **01 câu hỏi** mang đến lớp.

=== "LEC · Nội dung cốt lõi"

    ### Shared data
    ISR có thể thay đổi biến đúng lúc main đang đọc. Một giá trị 16 bit thường cần nhiều thao tác trên CPU 8 bit.

    ### Critical section
    Nếu cần tạm chặn ngắt:
    1. giữ trạng thái enable cũ;
    2. chặn trong khoảng ngắn;
    3. đọc/ghi dữ liệu;
    4. phục hồi trạng thái cũ.

    ### Ownership
    Giảm chia sẻ dữ liệu tốt hơn việc thêm critical section khắp nơi.

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig11-interrupt-service-flow.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig11-interrupt-service-flow.png" alt="ISR và chương trình chính" loading="lazy">
      </a>
      <figcaption>Hình 11. Quan hệ giữa ISR và luồng chính khi phân tích dữ liệu dùng chung.</figcaption>
    </figure>

=== "ACT · Hoạt động trên lớp"

    **Bài toán:** Phân tích biến tick 16 bit cập nhật trong ISR, đề xuất 2 cách đọc an toàn.

    Yêu cầu: ghi rõ giả thiết, đơn vị, sơ đồ/timeline và cách kiểm chứng.

=== "SELF-CHECK"

    1. volatile có làm phép đọc 16 bit nguyên tử không?
    2. Tại sao phải phục hồi trạng thái ngắt cũ?
    3. Dữ liệu ISR ghi/main đọc cần quy ước gì?

=== "AFTER · Sau lớp"

    - Hoàn thành engineering note ngắn.
    - Ghi điều đã hiểu, phép tính đã làm và câu hỏi còn vướng.
    - Nếu có mô phỏng, lưu ảnh có nhãn và đơn vị.
    - Không dùng số dự kiến thay số đo.


## Code minh họa

<div class="hct-code-actions">

[💻 Xem project trên GitHub](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W09_Shared_Data_ISR){ .md-button .md-button--primary }
[⬇️ Mở main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/theory/W09_Shared_Data_ISR/main.c){ .md-button }

</div>

```c
#include "common.h"

volatile u16 tick=0;

void timer0_isr(void) ISR(1) {
    TH0=0xFC; TL0=0x66;
    ++tick;
}

static u16 tick_snapshot(void) {
    u8 old_ea=EA;
    u16 copy;

    EA=0;
    copy=tick;
    EA=old_ea;

    return copy;
}

void main(void) {
    u16 t;

    EA=0;
    TMOD=(TMOD&0xF0)|1;
    TH0=0xFC; TL0=0x66;
    ET0=1; EA=1; TR0=1;

    for (;;) {
        t=tick_snapshot();
        P1=(u8)t;
        P2=(u8)(t>>8);
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
