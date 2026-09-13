# Update to HUYNH CONG TU Learning Hub v1.2 Illustrated

Phiên bản này là **project hoàn chỉnh**, không chỉ là patch.

## Nội dung mới

- 28 hình lý thuyết trích trực tiếp từ Giáo trình Kỹ thuật vi điều khiển.
- 8 sơ đồ Lab chính có hình trong sổ tay nguồn.
- 3 hình mở rộng/project.
- Hình được gắn vào đúng 15 buổi lý thuyết, 10 Lab và 3 trang mở rộng.
- Mỗi hình có caption, alt text, lazy loading và bấm để phóng to.
- Có trang **Thư viện hình minh họa**.
- Giữ giao diện Navy–Gold và GitHub Pages workflow.

## Cập nhật project đang dùng

Giải nén rồi copy toàn bộ nội dung vào `C:\HCT_LearningHub`, chọn **Replace files in destination**.

```powershell
cd C:\HCT_LearningHub
.\.venv\Scripts\python.exe -m mkdocs serve
```

Kiểm tra xong:

```powershell
.\.venv\Scripts\python.exe -m mkdocs build --strict
git add .
git commit -m "Upgrade Learning Hub to v1.2 Illustrated"
git push
```
