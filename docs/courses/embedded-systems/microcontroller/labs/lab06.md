# LAB 06 — ADC0804 & LM35

**Đọc trước:** Giáo trình trang **40–43**

<div class="week-meta">
<div><small>Platform</small><strong>AT89S52 · 5 V</strong></div>
<div><small>Clock</small><strong>11.0592 MHz · 12T</strong></div>
<div><small>Flow</small><strong>Keil → Proteus → KIT → Measure</strong></div>
</div>

## Mục tiêu

Khởi động chuyển đổi ADC, đọc dữ liệu, xử lý timeout và kiểm chứng phép đo LM35.

## Kết nối tham chiếu

| Tín hiệu / khối | Kết nối / lưu ý |
|---|---|
| DB0–DB7 | P1.0–P1.7 |
| RD/WR | P3.6/P3.7 |
| INTR | P3.2 |
| Vin+ | LM35 OUT |
| VREF/2 | 1.280 V đã đo |
| LCD | Theo Lab 04 |

!!! warning "Trước khi cấp điện"
    Đối chiếu sơ đồ KIT thực. Kiểm tra VCC/GND, chiều linh kiện, reset, clock, điện trở hạn dòng và jumper.

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/theory/fig19-lm35-adc0804-lcd.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/theory/fig19-lm35-adc0804-lcd.png" alt="LM35 ADC0804 LCD" loading="lazy">
  </a>
  <figcaption>Chuỗi đo nhiệt độ với LM35, ADC0804 và LCD.</figcaption>
</figure>

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/theory/fig18-adc-quantization.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/theory/fig18-adc-quantization.png" alt="Lượng tử hóa ADC" loading="lazy">
  </a>
  <figcaption>Lượng tử hóa điện áp thành các mức số.</figcaption>
</figure>

## Quy trình từng bước

1. Dựng ADC+clock RC; đo VREF/2.
2. Nối bus/control, kiểm tra AGND/DGND.
3. Đọc chu kỳ WR→INTR→RD.
4. Thử Vin 0.25/0.40/0.60 V.
5. Đo conversion timing.
6. Cố ý mất clock; phải timeout.
7. Thay bằng LM35 và nhiệt kế tham chiếu.
8. Lập bảng raw code, voltage, temperature, error.

## Ca kiểm thử

| Ca thử | Kết quả dự kiến |
|---|---|
| 0.25 V | Code ~25 |
| 0.40 V | ~40 |
| 0.60 V | ~60 |
| Mất clock | Timeout |
| Đổi VREF/2 | Phải tính lại hệ số |

## Lỗi thường gặp

| Dấu hiệu | Hướng kiểm tra |
|---|---|
| Luôn 255 | Bus/Vin/reference |
| Timeout | Clock/WR/CS/INTR |
| Sai ~×2 | Nhầm VREF/2/VFS |

## Phân tích sau thực hành

1. Vì sao guard loop không phải timeout ms hiệu chuẩn?
2. Nguồn sai số nhiệt độ gồm gì?

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
