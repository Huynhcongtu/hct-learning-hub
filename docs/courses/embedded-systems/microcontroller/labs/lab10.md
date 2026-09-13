# LAB 10 — UART với máy tính

**Đọc trước:** Giáo trình trang **31–33**

<div class="week-meta">
<div><small>Platform</small><strong>AT89S52 · 5 V</strong></div>
<div><small>Clock</small><strong>11.0592 MHz · 12T</strong></div>
<div><small>Flow</small><strong>Keil → Proteus → KIT → Measure</strong></div>
</div>

## Mục tiêu

Thiết lập UART 9600 8N1, điều khiển LED bằng command, xử lý invalid input và đo bit time.

## Kết nối tham chiếu

| Tín hiệu / khối | Kết nối / lưu ý |
|---|---|
| P3.1 TXD | RX USB-UART |
| P3.0 RXD | TX USB-UART |
| GND | Chung |
| P1.0 | LED active-low |
| USB-UART power | Tránh hai nguồn 5 V đấu đối nhau |

!!! warning "Trước khi cấp điện"
    Đối chiếu sơ đồ KIT thực. Kiểm tra VCC/GND, chiều linh kiện, reset, clock, điện trở hạn dòng và jumper.

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/labs/lab10-uart-pc.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/labs/lab10-uart-pc.png" alt="Sơ đồ Lab 10 UART PC" loading="lazy">
  </a>
  <figcaption>Minh họa kết nối UART giữa AT89S52 và máy tính.</figcaption>
</figure>

<figure class="hct-figure">
  <a href="../../../../../assets/images/microcontroller/theory/fig12-uart-8n1-a5.png" target="_blank" rel="noopener">
    <img src="../../../../../assets/images/microcontroller/theory/fig12-uart-8n1-a5.png" alt="UART 8N1" loading="lazy">
  </a>
  <figcaption>Khung UART 8N1 dùng để đối chiếu dạng sóng.</figcaption>
</figure>

## Quy trình từng bước

1. Xác nhận USB-UART mức logic phù hợp; terminal 9600 8N1.
2. Kiểm tra TH1/TL1=0xFD, SMOD=0.
3. Boot message sau reset.
4. `1`→ACK ON; `0`→ACK OFF; `?`→STATE.
5. `X`→ERR nhưng giữ state; bỏ CR/LF.
6. Đo bit ~104.167 µs, LSB first.
7. Thử gửi dồn để thấy giới hạn polling.
8. Đề xuất ISR RX + ring buffer.

## Ca kiểm thử

| Ca thử | Kết quả dự kiến |
|---|---|
| 1 | ACK ON |
| 0 | ACK OFF |
| ? | STATE |
| X | ERR/giữ state |
| CR/LF | Bỏ qua |
| Reset | Boot + LED off |

## Lỗi thường gặp

| Dấu hiệu | Hướng kiểm tra |
|---|---|
| Không dữ liệu | COM/TXRX/GND |
| Ký tự rác | Baud/clock |
| Mất lệnh | Polling bị chặn |

## Phân tích sau thực hành

1. 20 byte mất tối thiểu bao lâu ở 9600 8N1?
2. Vì sao invalid command phải giữ output?

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
