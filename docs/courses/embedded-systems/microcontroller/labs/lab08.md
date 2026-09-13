# LAB 08 — PWM & tải điện áp thấp

**Đọc trước:** Giáo trình trang **26 và 46–47**

<div class="week-meta">
<div><small>Platform</small><strong>AT89S52 · 5 V</strong></div>
<div><small>Clock</small><strong>11.0592 MHz · 12T</strong></div>
<div><small>Flow</small><strong>Keil → Proteus → KIT → Measure</strong></div>
</div>

## Mục tiêu

Tạo PWM 20 bước bằng timer auto-reload, thay duty theo nút và bảo đảm tải tắt khi reset.

## Kết nối tham chiếu

| Tín hiệu / khối | Kết nối / lưu ý |
|---|---|
| P1.0 | Qua 74HCT14 tới Gate MOSFET |
| Gate | 100 Ω + pull-down 100 kΩ |
| Motor | 5 V + diode flyback |
| P3.2 | Nút pull-up 10 kΩ |
| Ground | Logic/tải chung có kiểm soát |

!!! warning "Trước khi cấp điện"
    Đối chiếu sơ đồ KIT thực. Kiểm tra VCC/GND, chiều linh kiện, reset, clock, điện trở hạn dòng và jumper.

## Quy trình từng bước

1. Chưa nối motor; đo trước/sau inverter; reset→Gate thấp.
2. Đọc TH0=0xA4 và 20 phase; tự tính.
3. Đo duty 50%, chu kỳ ~1.997 ms theo cấu hình mẫu.
4. Thử 0/35/50/100%.
5. Ghi DC ở 0/100%.
6. Kiểm tra MOSFET/diode rồi mới nối motor.
7. Đo VCC khi motor start.
8. Nộp waveform + duty table + reset test.

## Ca kiểm thử

| Ca thử | Kết quả dự kiến |
|---|---|
| 0% | Gate thấp |
| 35% | 7/20 |
| 50% | 10/20 |
| 100% | Gate cao |
| Reset | Gate thấp |
| Giữ nút | Không auto-repeat |

## Lỗi thường gặp

| Dấu hiệu | Hướng kiểm tra |
|---|---|
| Motor chạy khi reset | Polarity/pull-down |
| Duty đọc ngược | Điểm đo trước/sau inverter |
| Reset lúc start | Nguồn/nhiễu/mass |

## Phân tích sau thực hành

1. Vì sao 20 bước có 21 giá trị kể cả 0/100?
2. Duty có bằng % tốc độ motor không?

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
