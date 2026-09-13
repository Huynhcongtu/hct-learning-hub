# Source Image Map — v1.2 Illustrated

Tất cả hình trong `docs/assets/images/microcontroller/` được trích từ hai tài liệu nguồn do người dùng cung cấp.

| Nhóm | File web | Nội dung |
|---|---|---|
| Theory Figure 1 | `theory/fig01-embedded-system.png` | Hệ thống điều khiển gồm cảm biến, bộ xử lý và cơ cấu chấp hành |
| Theory Figure 2 | `theory/fig02-bit-weights-a5.png` | Trọng số của tám bit trong byte A5H |
| Theory Figure 3 | `theory/fig03-8051-functional-blocks.png` | Các khối chức năng chính của kiến trúc 8051 |
| Theory Figure 4 | `theory/fig04-at89s52-pinout.png` | Sơ đồ chân AT89S52 PDIP 40 nhìn từ trên |
| Theory Figure 5 | `theory/fig05-at89s52-minimum-system.png` | Kết nối tối thiểu cho mạch thực hành AT89S52 |
| Theory Figure 6 | `theory/fig06-code-ram-sfr-map.png` | Cách phân biệt CODE, RAM và SFR trên AT89S52 |
| Theory Figure 7 | `theory/fig07-build-sim-program-flow.png` | Chuỗi tạo chương trình để mô phỏng và nạp |
| Theory Figure 8 | `theory/fig08-debounce-stable-state.png` | Chỉ công nhận trạng thái sau khi tín hiệu ổn định đủ thời gian |
| Theory Figure 9 | `theory/fig09-finite-state-machine.png` | Mô hình trạng thái cho thiết bị điều khiển đơn giản |
| Theory Figure 10 | `theory/fig10-timer-fc66-overflow.png` | Timer bắt đầu từ FC66H và tràn sau 922 lần đếm |
| Theory Figure 11 | `theory/fig11-interrupt-service-flow.png` | CPU phục vụ ISR rồi quay lại chương trình chính |
| Theory Figure 12 | `theory/fig12-uart-8n1-a5.png` | Khung UART 8N1 của byte A5H |
| Theory Figure 13 | `theory/fig13-seven-segment-map.png` | Tên các đoạn và bảng mã anode chung của cấu hình mẫu |
| Theory Figure 14 | `theory/fig14-four-digit-multiplex.png` | Quét bốn digit và dành khoảng tắt khi thay mã đoạn |
| Theory Figure 15 | `theory/fig15-lcd1602-4bit.png` | Giao tiếp LCD 1602 ở chế độ bốn bit |
| Theory Figure 16 | `theory/fig16-keypad-4x4-scan.png` | Cách quét bàn phím bốn hàng bốn cột |
| Theory Figure 17 | `theory/fig17-led-matrix-glyph.png` | Biểu diễn một ký tự bằng tám hàng tám cột |
| Theory Figure 18 | `theory/fig18-adc-quantization.png` | Lượng tử hóa điện áp thành các mức số |
| Theory Figure 19 | `theory/fig19-lm35-adc0804-lcd.png` | Chuỗi đo nhiệt độ với LM35, ADC0804 và LCD |
| Theory Figure 20 | `theory/fig20-dac0808-current-to-voltage.png` | DAC0808 cần tầng chuyển dòng sang điện áp |
| Theory Figure 21 | `theory/fig21-pwm-duty-cycle.png` | Cùng chu kỳ nhưng duty khác nhau tạo mức tác động trung bình khác nhau |
| Theory Figure 22 | `theory/fig22-reset-safe-power-stage.png` | Tầng công suất có trạng thái tắt khi MCU reset |
| Theory Figure 23 | `theory/fig23-quadrature-encoder.png` | Hai kênh A và B của encoder tăng dần |
| Theory Figure 24 | `theory/fig24-ir-receiver-nec.png` | Bộ thu hồng ngoại tách sóng mang trước khi MCU giải mã |
| Theory Figure 25 | `theory/fig25-i2c-pullups.png` | Hai đường I²C có điện trở kéo lên riêng |
| Theory Figure 26 | `theory/fig26-external-sram-address-latch.png` | Tách địa chỉ thấp khỏi bus P0 khi ghép SRAM ngoài |
| Theory Figure 27 | `theory/fig27-measurement-debug-flow.png` | Trình tự khoanh vùng lỗi dựa trên phép đo |
| Theory Figure 28 | `theory/fig28-temperature-hysteresis.png` | Hai ngưỡng khác nhau ngăn đầu ra đổi liên tục quanh một mức nhiệt |
| Practical/Extension | `labs/lab01-minimum-system.png` | Lab 01 — Mạch tối thiểu và chớp LED |
| Practical/Extension | `labs/lab02-button-debounce.png` | Lab 02 — Nút nhấn và LED |
| Practical/Extension | `labs/lab03-four-digit-seven-segment.png` | Lab 03 — Quét bốn LED 7 đoạn |
| Practical/Extension | `labs/lab04-lcd1602-4bit.png` | Lab 04 — LCD 1602 chế độ 4 bit |
| Practical/Extension | `labs/lab05-led-matrix.png` | Lab 05 — LED matrix 8×8 |
| Practical/Extension | `labs/lab08-pwm-motor-driver.png` | Lab 08 — PWM và tải điện áp thấp |
| Practical/Extension | `labs/lab09-nec-ir.png` | Lab 09 — Điều khiển hồng ngoại NEC |
| Practical/Extension | `labs/lab10-uart-pc.png` | Lab 10 — UART với máy tính |
| Practical/Extension | `extensions/ext-keypad-4x4.png` | Mở rộng — Keypad 4×4 |
| Practical/Extension | `extensions/ext-ds1307-i2c.png` | Mở rộng — DS1307 qua I²C |
| Practical/Extension | `extensions/project-thermostat-hysteresis.png` | Project — Ca thử thermostat hysteresis |
