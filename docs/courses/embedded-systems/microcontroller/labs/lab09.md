# LAB 09 — Hồng ngoại NEC

**Đọc trước:** Giáo trình trang **49**

<div class="week-meta">
<div><small>Platform</small><strong>AT89S52 · 5 V</strong></div>
<div><small>Clock</small><strong>11.0592 MHz · 12T</strong></div>
<div><small>Flow</small><strong>Keil → Proteus → KIT → Measure</strong></div>
</div>

## Mục tiêu

Đo/giải mã NEC chuẩn, kiểm tra byte bù và phân biệt test logic với test đường quang.

## Kết nối tham chiếu

| Tín hiệu / khối | Kết nối / lưu ý |
|---|---|
| IR OUT | P3.2 active-low |
| P1.0 | LED active-low |
| P3.1 TXD | RX terminal |
| Timer 0 | Đo pulse |
| Timer 1 | Baud 9600 |

!!! warning "Trước khi cấp điện"
    Đối chiếu sơ đồ KIT thực. Kiểm tra VCC/GND, chiều linh kiện, reset, clock, điện trở hạn dòng và jumper.

## Quy trình từng bước

1. Tra đúng pin receiver.
2. Terminal 9600 8N1; kiểm tra NEC READY.
3. Mô phỏng có thể dùng pulse logic để test decoder.
4. Đo leader ~9 ms low + ~4.5 ms high.
5. `00 FF 45 BA` → CMD45, LED on.
6. `00 FF 46 B9` → LED off; complement sai phải reject.
7. Dùng remote thật và ghi mã thực.
8. Test repeat/frame cắt.

## Ca kiểm thử

| Ca thử | Kết quả dự kiến |
|---|---|
| 00 FF 45 BA | CMD45/on |
| 00 FF 46 B9 | CMD46/off |
| Complement sai | Reject |
| Repeat | Bỏ qua bản mẫu |
| Frame cắt | Timeout/reject |

## Lỗi thường gặp

| Dấu hiệu | Hướng kiểm tra |
|---|---|
| Không nhận | Protocol/pin/clock |
| Mã khác nhãn | Remote khác |
| Sai ngẫu nhiên | Nguồn/dung sai/polling |

## Phân tích sau thực hành

1. Vì sao pulse test chưa chứng minh cự ly IR?
2. Repeat frame khác full frame thế nào?

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
