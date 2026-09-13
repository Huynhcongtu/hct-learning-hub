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
