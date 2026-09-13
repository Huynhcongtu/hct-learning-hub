# BUỔI 11 — LCD, keypad & LED matrix

**Đọc trước:** Giáo trình trang **36–39**

<div class="week-meta">
<div><small>Track</small><strong>Lý thuyết</strong></div>
<div><small>Platform</small><strong>8051 / AT89S52</strong></div>
<div><small>Workflow</small><strong>PRE → LEC → CALC → VERIFY</strong></div>
</div>

## Mục tiêu

- Khởi tạo LCD 1602 chế độ 4 bit.
- Giải thích DDRAM và RS/E/RW.
- Quét keypad theo hàng/cột.
- Tạo glyph 8×8 và quét LED matrix.

=== "PRE · Đọc trước"

    1. Đọc trang **36–39**.
    2. Gạch chân thanh ghi / khái niệm mới.
    3. Tự làm ví dụ trước khi xem kết quả.
    4. Viết **01 câu hỏi** mang đến lớp.

=== "LEC · Nội dung cốt lõi"

    ### LCD 1602
    Chế độ 4 bit dùng D4–D7. Chuỗi khởi tạo phải đồng bộ giao diện trước khi gửi lệnh bình thường.
    Trong lab mẫu, `RW = 0` và dùng delay thay vì đọc busy flag.

    ### Keypad
    Quét từng hàng rồi đọc cột. Với bàn phím không diode, nhấn nhiều phím có thể tạo ghosting.

    ### LED matrix
    Một glyph 8×8 là tám byte. Mạch quét cần ánh xạ hàng/cột rõ, chỉ bật một hàng mỗi thời điểm và tắt hàng cũ trước khi đổi dữ liệu cột.

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig15-lcd1602-4bit.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig15-lcd1602-4bit.png" alt="LCD 1602 chế độ 4 bit" loading="lazy">
      </a>
      <figcaption>Hình 15. Giao tiếp LCD 1602 ở chế độ bốn bit.</figcaption>
    </figure>

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig16-keypad-4x4-scan.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig16-keypad-4x4-scan.png" alt="Quét keypad 4x4" loading="lazy">
      </a>
      <figcaption>Hình 16. Cách quét bàn phím bốn hàng bốn cột.</figcaption>
    </figure>

    <figure class="hct-figure">
      <a href="../../../../../assets/images/microcontroller/theory/fig17-led-matrix-glyph.png" target="_blank" rel="noopener">
        <img src="../../../../../assets/images/microcontroller/theory/fig17-led-matrix-glyph.png" alt="Glyph LED matrix 8x8" loading="lazy">
      </a>
      <figcaption>Hình 17. Biểu diễn một ký tự bằng tám hàng tám cột.</figcaption>
    </figure>

=== "ACT · Hoạt động trên lớp"

    **Bài toán:** Tạo glyph chữ đầu tên nhóm và mô tả cách phát hiện ảnh bị lật ngang/dọc.

    Yêu cầu: ghi rõ giả thiết, đơn vị, sơ đồ/timeline và cách kiểm chứng.

=== "SELF-CHECK"

    1. Tại sao LCD có ô đen chưa chắc đã hỏng?
    2. Ghosting keypad khác ghosting LED matrix ở điểm nào?
    3. Tại sao kiểm tra một điểm trước khi bật cả matrix?

=== "AFTER · Sau lớp"

    - Hoàn thành engineering note ngắn.
    - Ghi điều đã hiểu, phép tính đã làm và câu hỏi còn vướng.
    - Nếu có mô phỏng, lưu ảnh có nhãn và đơn vị.
    - Không dùng số dự kiến thay số đo.


## Code minh họa

<div class="hct-code-actions">

[💻 Xem project trên GitHub](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/theory/W11_LCD_Keypad_Matrix_Data){ .md-button .md-button--primary }
[⬇️ Mở main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/theory/W11_LCD_Keypad_Matrix_Data/main.c){ .md-button }

</div>

```c
#include "common.h"

/* Data-only example for display-oriented lessons. */
u8 ROM glyph_Q[8]={
    0x3C,0x42,0x81,0x81,
    0x91,0xA1,0x42,0xBC
};

u8 ROM keypad_map[16]={
    '1','2','3','A',
    '4','5','6','B',
    '7','8','9','C',
    '*','0','#','D'
};

void main(void) {
    u8 i=0;

    for (;;) {
        P1=(u8)~glyph_Q[i];
        P2=keypad_map[i & 15u];
        i=(i+1u)&7u;
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
