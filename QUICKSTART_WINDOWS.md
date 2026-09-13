# QUICK START — Windows

```bat
cd /d C:\HCT_LearningHub
py -m venv .venv
.venv\Scripts\activate
pip install -r requirements.txt
mkdocs serve
```

Mở `http://127.0.0.1:8000/`.

Sửa file `.md` trong VS Code rồi `Ctrl+S`; trình duyệt tự refresh.

Trước khi publish:

```bat
mkdocs build --strict
```
