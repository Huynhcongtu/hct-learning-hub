# Project — Bộ giám sát nhiệt độ có hysteresis

## Thành phần
LM35 + ADC0804 + LCD + LED active-low mô phỏng quạt + UART monitor.

## Chức năng
- đọc ADC;
- hiển thị nhiệt độ;
- hysteresis;
- telemetry UART;
- ADC timeout → báo lỗi và đưa tải về trạng thái an toàn.

## Ca thử tham chiếu
Dùng chuỗi Vin:

1. `0.35 V`
2. `0.42 V`
3. `0.40 V`
4. `0.38 V`

Kỳ vọng:

```text
OFF → ON → giữ ON → OFF
```

Ngưỡng mẫu của học liệu: **42 °C bật / 38 °C tắt**.

## Quy trình
1. Lab 06 phải đạt trước.
2. Lập bảng pin/Timer.
3. Kiểm tra LCD không ghi đè chân tải.
4. Thêm output và UART.
5. Test từng khối.
6. Test hysteresis.
7. Cố ý mất clock ADC → timeout, không treo.
8. Phân biệt RAW ADC trên UART và nhiệt độ trên LCD.
9. Đo response time.

## Bản nâng cao
Thiết kế không chặn với system tick, UART RX ISR, ring buffer, timeout và lịch cập nhật LCD.

## Hồ sơ bàn giao
Specification, resource table, schematic, source+HEX, Proteus, test matrix, measurements, video ngắn, một quyết định thiết kế và một giới hạn còn tồn tại.
