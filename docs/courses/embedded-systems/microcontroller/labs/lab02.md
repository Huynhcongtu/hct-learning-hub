# LAB 02 — Nút nhấn & LED có chống dội

**Đọc trước:** Giáo trình trang **21–23**

<div class="week-meta">
<div><small>Platform</small><strong>AT89S52 · 5 V</strong></div>
<div><small>Clock</small><strong>11.0592 MHz · 12T</strong></div>
<div><small>Flow</small><strong>Keil → Proteus → KIT → Measure</strong></div>
</div>

## Mục tiêu

Biến tín hiệu nút cơ có dội thành một sự kiện nhấn ổn định; giữ nút không phát lặp.

## Kết nối tham chiếu

| Tín hiệu / khối | Kết nối / lưu ý |
|---|---|
| P1.0 | LED active-low |
| P3.2 | Nút xuống GND, kéo lên 10 kΩ |
| Nguồn/clock | Theo mạch tối thiểu Lab 01 |

!!! warning "Trước khi cấp điện"
    Đối chiếu sơ đồ KIT thực. Kiểm tra VCC/GND, chiều linh kiện, reset, clock, điện trở hạn dòng và jumper.

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/labs/lab02-button-debounce.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/labs/lab02-button-debounce.png" alt="Sơ đồ nút nhấn chống dội" loading="lazy">
  </a>
  <figcaption>Minh họa nguyên lý Lab 02 — nút nhấn và LED.</figcaption>
</figure>

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/theory/fig08-debounce-stable-state.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/theory/fig08-debounce-stable-state.png" alt="Mô hình debounce" loading="lazy">
  </a>
  <figcaption>Chỉ công nhận trạng thái sau khi tín hiệu ổn định đủ thời gian.</figcaption>
</figure>

## Quy trình từng bước

1. Đo continuity nút khi chưa cấp nguồn.
2. Xác nhận `KEY=P3.2` và `KEY=1` trước khi đọc.
3. Theo dõi P3.2/P1.0; mỗi nhấn chỉ đổi LED một lần.
4. Giữ nút 3 s; không toggle lặp.
5. Tạo/quan sát xung dội.
6. Đổi số mẫu ổn định 4→1 để so sánh.
7. Thử tối thiểu 20 lần trên KIT.
8. Giải thích lỗi nếu toggle theo mức thay vì event.

## Ca kiểm thử

| Ca thử | Kết quả dự kiến |
|---|---|
| 20 nhấn | 20 lần đổi |
| Giữ 3 s | Một sự kiện |
| Có dội | Không nhiều event |
| Nhấn quá ngắn | Có thể bị loại |
| Nhả rồi nhấn | Release phải ổn định |

## Lỗi thường gặp

| Dấu hiệu | Hướng kiểm tra |
|---|---|
| Một nhấn đổi nhiều lần | Debounce chưa đủ |
| Không nhận nút | Sai dây / chưa thả input |

## Phân tích sau thực hành

1. Vì sao 20 ms không đúng cho mọi nút?
2. Phân biệt state và event.


## Code tham chiếu

<div class="hct-code-actions">

[💻 Xem project trên GitHub](https://github.com/Huynhcongtu/hct-learning-hub/tree/main/code/labs/L02_Button){ .md-button .md-button--primary }
[⬇️ Mở main.c](https://raw.githubusercontent.com/Huynhcongtu/hct-learning-hub/main/code/labs/L02_Button/main.c){ .md-button }

</div>

```c
#include "common.h"
#include "delay.h"
PIN(LED,P1,0); PIN(KEY,P3,2);
void main(void) {
    u8 stable=1,candidate=1,sample,count=0;
    EA=0; LED=1; KEY=1;
    for (;;) {
        sample=KEY;
        if(sample!=candidate) { candidate=sample; count=0; }
        else if(count<4) {
            ++count;
            if(count==4 && stable!=candidate) {
                stable=candidate;
                if(stable==0) LED=!LED;
            }
        }
        delay_ms(5); /* about 20 ms stable, both press and release */
    }
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
