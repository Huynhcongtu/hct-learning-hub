# HUYNH CONG TU Learning Hub — Microcontroller Course v1.1

Bản cập nhật này thay nội dung mẫu trước đây bằng khóa học **Kỹ thuật vi điều khiển – 8051/AT89S52**,
được biên soạn lại theo hai tài liệu nguồn:

1. `01_Giao_trinh_Ky_thuat_vi_dieu_khien(1).docx`
2. `02_Huong_dan_thuc_hanh_tung_buoc(1).docx`

## Cách cập nhật project hiện tại

Giải nén ZIP này rồi copy toàn bộ nội dung vào:

```text
C:\HCT_LearningHub
```

Cho phép **Replace/Overwrite** các file trùng tên.

Sau đó mở PowerShell:

```powershell
cd C:\HCT_LearningHub
.\.venv\Scripts\python.exe -m mkdocs serve
```

Mở:

```text
http://127.0.0.1:8000/
```

Kiểm tra xong:

```powershell
git add .
git commit -m "Rebuild Microcontroller course from QNU source materials"
git push
```

## Cấu trúc mới

```text
docs/courses/embedded-systems/microcontroller/
├── index.md
├── syllabus.md
├── learning-path.md
├── toolchain.md
├── assessment.md
├── source-map.md
├── weeks/
│   ├── week01.md ... week15.md
├── labs/
│   ├── index.md
│   ├── lab01.md ... lab10.md
└── extensions/
    ├── keypad.md
    ├── ds1307.md
    └── thermostat-project.md
```

## Nguyên tắc

- Cấu hình tham chiếu: **AT89S52 PDIP40, 5 V, 11.0592 MHz, lõi 12T**.
- Công cụ: **Keil C51 + Proteus + KIT thực**.
- Website phân biệt rõ:
  - **giá trị dự kiến/tính toán**;
  - **số đo thực tế của sinh viên**.
- Mô phỏng không được xem là thay thế kiểm thử trên KIT.
- Sơ đồ KIT thực tế phải được đối chiếu trước khi dùng bảng chân mẫu.
