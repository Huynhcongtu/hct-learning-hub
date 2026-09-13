# LAB 05 — LED matrix 8×8

**Đọc trước:** Giáo trình trang **39**

<div class="week-meta">
<div><small>Platform</small><strong>AT89S52 · 5 V</strong></div>
<div><small>Clock</small><strong>11.0592 MHz · 12T</strong></div>
<div><small>Flow</small><strong>Keil → Proteus → KIT → Measure</strong></div>
</div>

## Mục tiêu

Tạo glyph 8×8, quét hàng bằng timer và kiểm chứng cực tính/giới hạn dòng.

## Kết nối tham chiếu

| Tín hiệu / khối | Kết nối / lưu ý |
|---|---|
| P2.0–P2.7 | Qua 4.7 kΩ tới PNP chọn hàng |
| P1.0–P1.7 | Qua 2.2 kΩ tới cathode cột |
| Glyph bit | Bit 1 = điểm sáng; driver đảo khi xuất |

!!! warning "Trước khi cấp điện"
    Đối chiếu sơ đồ KIT thực. Kiểm tra VCC/GND, chiều linh kiện, reset, clock, điện trở hạn dòng và jumper.

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/labs/lab05-led-matrix.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/labs/lab05-led-matrix.png" alt="Sơ đồ Lab 05 LED matrix" loading="lazy">
  </a>
  <figcaption>Minh họa nguyên lý LED matrix 8×8.</figcaption>
</figure>

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/theory/fig17-led-matrix-glyph.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/theory/fig17-led-matrix-glyph.png" alt="Glyph 8x8" loading="lazy">
  </a>
  <figcaption>Biểu diễn ký tự bằng tám hàng tám cột.</figcaption>
</figure>

## Quy trình từng bước

1. Vẽ glyph và tính 8 byte.
2. Xác định pin matrix bằng datasheet/diode test.
3. Thử một điểm rồi dịch hàng/cột.
4. Chạy glyph Q; kiểm tra lật.
5. Đo ~1 ms/hàng, frame ~8 ms.
6. Tạo glyph riêng.
7. Kiểm tra dòng khi nhiều điểm sáng.
8. Giải thích tắt hàng→đổi cột→bật hàng.

## Ca kiểm thử

| Ca thử | Kết quả dự kiến |
|---|---|
| Điểm dịch cột | Đúng bit |
| Điểm dịch hàng | Đúng hàng |
| Glyph Q | Đúng hướng |
| Full glyph | Không quá dòng |
| Frame | ~8 ms + overhead |

## Lỗi thường gặp

| Dấu hiệu | Hướng kiểm tra |
|---|---|
| Ảnh lật | Ánh xạ ngược |
| Ghosting | Không tắt hàng |
| Một hàng tối | Pin/PNP/resistor |

## Phân tích sau thực hành

1. Vì sao cần kiểm tra dòng tức thời?
2. Khi ảnh lật nên sửa mapping hay glyph?


## Code tham chiếu

<div class="hct-code-actions">

[💻 Xem project trên GitHub](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/labs/L05_Matrix){ .md-button .md-button--primary }
[⬇️ Mở main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/labs/L05_Matrix/main.c){ .md-button }

</div>

```c
#include "common.h"
/* Logical bit 1 = illuminated. P2 rows through PNP, P1 cathode columns. */
u8 ROM glyph[8]={0x3C,0x42,0x81,0x81,0x91,0xA1,0x42,0xBC};
void timer0_isr(void) ISR(1) {
    static u8 row=0;
    TH0=0xFC; TL0=0x66;
    P2=0xFF; P1=(u8)~glyph[row];
    P2=(u8)~(1u<<row); row=(row+1)&7;
}
void main(void) {
    EA=0; P1=0xFF; P2=0xFF;
    TMOD=(TMOD&0xF0)|1; TH0=0xFC; TL0=0x66;
    TF0=0; ET0=1; EA=1; TR0=1;
    for (;;) { }
}
```

!!! note "Nguồn"
    Đây là chương trình tham chiếu **SOURCE** từ sổ tay thực hành.
    Các header cần thiết được đặt cùng thư mục project để đúng quy ước mỗi bài là một target riêng.

## Bằng chứng nộp

- source C + header;
- HEX vừa build;
- project/schematic Proteus;
- bảng ca thử có **số đo thực**;
- waveform/ảnh đo có đơn vị;
- ảnh KIT nếu đã thử;
- mô tả ít nhất một lỗi và cách xử lý.

!!! info
    Nếu mới hoàn thành mô phỏng, phải ghi rõ **“chưa thử KIT”**.
