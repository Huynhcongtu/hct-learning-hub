# X01_Keypad

**Status:** SUPPLEMENTAL — mã bổ sung được triển khai từ yêu cầu mô tả trong sổ tay, không phải mã nguyên văn của tài liệu nguồn.

Keypad 4×4: single-key scan, debounce và UART log.

## Build

- AT89S52
- 11.0592 MHz / 12T
- Keil C51
- Build target riêng
- Không định nghĩa `HOST_CHECK` khi chạy MCU

## Verification

Đối chiếu trang mở rộng tương ứng trên Learning Hub.
Mỗi thay đổi phải chạy lại cùng bộ ca thử và ghi bằng chứng.
