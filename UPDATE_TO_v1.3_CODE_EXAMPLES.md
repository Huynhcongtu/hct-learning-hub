# Upgrade to v1.3 Code Examples

Phiên bản này kế thừa v1.2.1 Illustrated và bổ sung hệ thống mã nguồn.

## Bổ sung

- `code/common/`: 4 header nguồn.
- `code/labs/`: 10 chương trình tham chiếu SOURCE.
- `code/theory/`: 15 project SUPPLEMENTAL.
- `code/extensions/`: 3 project SUPPLEMENTAL.
- `code/templates/`: project khung.
- `code/tools/`: kiểm tra cú pháp HOST_CHECK.
- Trang `Code Examples` trong Learning Hub.
- Inline syntax-highlighted code ở 15 buổi + 10 Lab + 3 trang mở rộng.

## Cập nhật project đang chạy

Copy toàn bộ nội dung ZIP vào:

```text
C:\HCT_LearningHub
```

chọn Replace.

Kiểm tra:

```powershell
cd C:\HCT_LearningHub
.\.venv\Scripts\python.exe -m mkdocs serve
```

Sau đó:

```powershell
git add .
git commit -m "Upgrade Learning Hub to v1.3 Code Examples"
git push
```
