# HUYNH CONG TU Learning Hub v1.0

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
