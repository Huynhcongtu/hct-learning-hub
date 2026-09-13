# HCT Learning Hub — Code Examples

Bộ mã nguồn cho khóa học **Kỹ thuật Vi điều khiển — 8051 / AT89S52**.

## Cấu trúc

```text
code/
├── common/       # Header dùng chung trích từ sổ tay thực hành
├── theory/       # 15 ví dụ minh họa theo 15 buổi lý thuyết
├── labs/         # 10 chương trình tham chiếu L01–L10
├── extensions/   # Keypad, DS1307, Thermostat
├── templates/    # Project khung cho sinh viên
└── tools/        # Công cụ kiểm tra cú pháp HOST_CHECK
```

## Hai loại mã trong repository

### SOURCE — mã nguồn từ học liệu

`code/labs/L01...L10` và `code/common/*.h` được lấy từ **Hướng dẫn thực hành Kỹ thuật vi điều khiển**.
Các file này giữ nguyên nội dung chương trình tham chiếu của tài liệu.

### SUPPLEMENTAL — mã minh họa bổ sung

`code/theory/` và `code/extensions/` được biên soạn bổ sung để website có project có thể đọc, sửa và thử.
Chúng bám cấu hình và yêu cầu của học liệu nhưng **không được trình bày như mã nguyên văn từ tài liệu nguồn**.

## Nền tảng tham chiếu

- AT89S52 PDIP40
- 5 V
- 11.0592 MHz
- classic 12T
- Keil C51
- Proteus
- KIT thực

## Quy tắc sử dụng

Mỗi thư mục Lab là **một target riêng**. Không ghép nhiều `main.c` vào cùng project.

Khi build trên Keil C51:

1. Tạo project mới cho đúng thư mục.
2. Chọn AT89S52.
3. Đặt Xtal = 11.0592 MHz.
4. Thêm `main.c`.
5. Bật **Create HEX File**.
6. Không định nghĩa `HOST_CHECK`.
7. Build/Rebuild và xác nhận HEX mới.

`HOST_CHECK` chỉ dùng để kiểm tra cú pháp trên máy tính, không mô phỏng hành vi ngoại vi 8051.
