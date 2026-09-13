# Common headers

Các header trong thư mục này được trích từ phụ lục mã của sổ tay thực hành.

- `common.h`: kiểu dữ liệu, macro `PIN`, `ISR`, `ROM`, `NOP` và nhánh `HOST_CHECK`.
- `delay.h`: delay blocking dùng Timer 0, cấu hình 11.0592 MHz / 12T.
- `lcd.h`: LCD 1602 chế độ 4 bit, RW nối GND.
- `uart.h`: UART mode 1, Timer 1 mode 2, 9600 baud với TH1 = 0xFD.

!!! Important
`delay.h` sở hữu Timer 0. Không gọi `delay_ms()` đồng thời với chương trình đang dùng Timer 0 ISR.
