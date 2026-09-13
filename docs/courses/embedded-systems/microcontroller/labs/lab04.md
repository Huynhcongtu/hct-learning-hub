# LAB 04 — LCD 1602 chế độ 4 bit

**Đọc trước:** Giáo trình trang **36–37**

<div class="week-meta">
<div><small>Platform</small><strong>AT89S52 · 5 V</strong></div>
<div><small>Clock</small><strong>11.0592 MHz · 12T</strong></div>
<div><small>Flow</small><strong>Keil → Proteus → KIT → Measure</strong></div>
</div>

## Mục tiêu

Khởi tạo LCD ổn định, gửi lệnh/dữ liệu theo hai nibble và xử lý cập nhật số không để lại ký tự cũ.

## Kết nối tham chiếu

| Tín hiệu / khối | Kết nối / lưu ý |
|---|---|
| VSS/VDD | GND / 5 V |
| V0 | Biến trở 10 kΩ |
| RS/E | P3.5 / P3.4 |
| RW | GND |
| D4–D7 | P2.4–P2.7 |

!!! warning "Trước khi cấp điện"
    Đối chiếu sơ đồ KIT thực. Kiểm tra VCC/GND, chiều linh kiện, reset, clock, điện trở hạn dòng và jumper.

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/labs/lab04-lcd1602-4bit.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/labs/lab04-lcd1602-4bit.png" alt="Sơ đồ Lab 04 LCD1602" loading="lazy">
  </a>
  <figcaption>Minh họa nguyên lý LCD 1602 chế độ 4 bit.</figcaption>
</figure>

## Quy trình từng bước

1. Kiểm tra pin LCD, nguồn, V0, backlight.
2. Nối RS/E/RW/D4–D7.
3. Đọc chuỗi init nibble 3→3→3→2 và lệnh 0x28.
4. Kiểm tra `QNU 8051 LAB` và COUNT.
5. Đo E, RS, D4–D7.
6. Đổi chuỗi thành tên nhóm ASCII.
7. Thử 100→25 và xử lý ký tự dư.
8. Reset/power-cycle ít nhất 3 lần.

## Ca kiểm thử

| Ca thử | Kết quả dự kiến |
|---|---|
| Power-on | Hai dòng đúng |
| 100→025 | Không ký tự dư |
| Reset ×3 | Init ổn định |
| RS data | Mức 1 |
| RW | Luôn 0 |

## Lỗi thường gặp

| Dấu hiệu | Hướng kiểm tra |
|---|---|
| Ô đen, không chữ | Contrast/init |
| Ký tự rác | Sai D4–D7/nibble |
| Lỗi power-on | Delay/init thiếu |

## Phân tích sau thực hành

1. Vì sao ô đen chưa chắc LCD hỏng?
2. Khi nào nên đọc busy flag?

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
