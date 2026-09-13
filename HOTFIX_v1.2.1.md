# v1.2.1 Illustrated HOTFIX

## Lỗi đã sửa

Phiên bản v1.2 dùng raw HTML `<img src="...">`. MkDocs mặc định tạo **directory URLs**,
ví dụ:

```text
docs/courses/embedded-systems/microcontroller/weeks/week01.md
```

được xuất thành:

```text
site/courses/embedded-systems/microcontroller/weeks/week01/index.html
```

Do đó đường dẫn ảnh phải lùi **5 cấp** từ trang Week/Lab/Extension:

```text
../../../../../assets/images/...
```

Bản v1.2 trước đó chỉ lùi 4 cấp nên trình duyệt tìm nhầm tại:

```text
/courses/assets/...
```

thay vì:

```text
/assets/...
```

và ảnh bị broken.

v1.2.1 đã tính lại đường dẫn cho toàn bộ:
- trang Home,
- course index,
- Toolchain,
- Illustrations,
- 15 Week pages,
- 10 Lab pages,
- 3 Extension/Project pages.

## Cập nhật

Copy toàn bộ project vào `C:\HCT_LearningHub`, chọn Replace.

Sau đó:

```powershell
cd C:\HCT_LearningHub
.\.venv\Scripts\python.exe -m mkdocs serve
```

Nếu hình đã hiển thị:

```powershell
git add .
git commit -m "Fix illustrated image paths for MkDocs directory URLs"
git push
```
