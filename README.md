# HUYNH CONG TU Learning Hub v1.3 Code Examples

**Embedded Systems • Microelectronics • IC Design**

Phiên bản v1.3 bổ sung hệ thống source code cho khóa **Kỹ thuật Vi điều khiển — 8051 / AT89S52**.

- 15 buổi lý thuyết minh họa.
- 10 Lab SOURCE.
- 3 extension/project.
- 4 common headers.
- Code hiển thị trực tiếp trên page và browse được trên GitHub.
- Kế thừa toàn bộ hình minh họa của v1.2.1.

Template dùng **MkDocs Material + GitHub Pages**.

## Chạy trên Windows

```bat
py -m venv .venv
.venv\Scripts\activate
python -m pip install --upgrade pip
pip install -r requirements.txt
mkdocs serve
```

Mở:

```text
http://127.0.0.1:8000/
```

## Kiểm tra trước khi publish

```bat
mkdocs build --strict
```

## Đưa lên GitHub

```bat
git init
git add .
git commit -m "Initial HUYNH CONG TU Learning Hub v1.0"
git branch -M main
git remote add origin https://github.com/YOUR_USERNAME/hct-learning-hub.git
git push -u origin main
```

Workflow `.github/workflows/deploy.yml` sẽ tự tạo branch `gh-pages`.

Sau đó vào **Repository → Settings → Pages → Deploy from a branch → gh-pages → /(root)**.
