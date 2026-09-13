# Kỹ thuật Vi điều khiển

**Microcontroller Engineering · 8051 / AT89S52**

<div class="hct-course-banner" markdown>

## Từ nguyên lý → thiết kế → mô phỏng → đo kiểm

Khóa học được tổ chức từ hai học liệu QNU: **Giáo trình Kỹ thuật vi điều khiển** và
**Hướng dẫn thực hành Kỹ thuật vi điều khiển**. Trọng tâm là 8051 với cấu hình tham chiếu
**AT89S52, 5 V, 11.0592 MHz, lõi 12T, Keil C51 và Proteus**.

</div>

<figure class="hct-figure">
  <a href="../../../assets/images/microcontroller/theory/fig01-embedded-system.png" target="_blank" rel="noopener">
    <img src="../../../assets/images/microcontroller/theory/fig01-embedded-system.png" alt="Hệ thống nhúng gồm cảm biến bộ xử lý và cơ cấu chấp hành" loading="lazy">
  </a>
  <figcaption>Hình 1. Mô hình hệ thống nhúng dùng xuyên suốt khóa học — từ tín hiệu vào đến điều khiển đầu ra.</figcaption>
</figure>

## Kết quả học tập

Sau khi hoàn thành lộ trình, sinh viên cần có khả năng:

1. Giải thích cấu trúc 8051, không gian mã/dữ liệu và vai trò các thanh ghi.
2. Đọc và phân tích các lệnh Assembly cơ bản.
3. Viết chương trình C51 điều khiển GPIO và ngoại vi.
4. Tính toán Timer và baud rate từ clock thực.
5. Dùng ngắt, timeout, máy trạng thái và lập lịch không chặn.
6. Giao tiếp LED 7 đoạn, LCD, keypad, LED matrix, ADC, DAC, UART, IR và I²C.
7. Xây dựng một hệ thống nhỏ có **yêu cầu, phép đo và ca kiểm thử**.
8. Phân biệt rõ **giá trị dự kiến** với **số đo thực tế**.

## Hai tuyến học

<div class="hct-grid" markdown>

<div class="hct-card" markdown>
### 📘 Lý thuyết · 15 buổi
Tổ chức theo bản đồ đọc của giáo trình, từ hệ thống nhúng đến thiết kế và kiểm thử.

[**Bắt đầu Buổi 01 →**](weeks/week01.md)
</div>

<div class="hct-card" markdown>
### 🧪 Thực hành · 10 bài
Mỗi bài: chuẩn bị → Keil → Proteus → KIT → đo → báo cáo.

[**Xem lộ trình Lab →**](labs/index.md)
</div>

<div class="hct-card" markdown>
### 🧩 Mở rộng & Project
Keypad 4×4, DS1307 và bộ giám sát nhiệt độ có hysteresis.

[**Project Thermostat →**](extensions/thermostat-project.md)
</div>

</div>

## Cấu hình tham chiếu

| Hạng mục | Cấu hình |
|---|---|
| MCU | AT89S52, PDIP 40 |
| Logic | 5 V |
| Clock | 11.0592 MHz |
| Core timing | 12T |
| IDE/compiler | Keil C51 |
| Simulation | Proteus |
| Verification | Multimeter, oscilloscope / logic analyzer, KIT thực |
| Programming | Bộ nạp tương thích đúng AT89S52 |

!!! warning "Không thay sơ đồ KIT bằng bảng chân mẫu"
    Bảng chân trên Learning Hub là cấu hình tham chiếu. Nếu KIT của phòng thực hành có jumper,
    latch, transistor hoặc bus riêng, sinh viên phải lập **phiếu ánh xạ KIT** trước khi chạy bài.

## Learning model

<div class="hct-path">
<span>PRE</span><b>→</b><span>LEC</span><b>→</b><span>CALC</span><b>→</b><span>SIM</span><b>→</b><span>LAB</span><b>→</b><span>VERIFY</span><b>→</b><span>REFLECT</span>
</div>

- **PRE**: đọc đúng trang được giao và trả lời self-check.
- **LEC**: giải thích nguyên lý và tình huống thiết kế.
- **CALC**: tính timer, baud, ADC/DAC, dòng và tần số.
- **SIM**: kiểm tra giả thuyết trên Proteus.
- **LAB**: chạy trên KIT.
- **VERIFY**: đo tín hiệu và đối chiếu yêu cầu.
- **REFLECT**: ghi lỗi, nguyên nhân, cách sửa và giới hạn còn lại.
