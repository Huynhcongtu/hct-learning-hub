Set-Location "C:\HCT_LearningHub"

Write-Host "1/4  Site build..." -ForegroundColor Cyan
& ".\.venv\Scripts\python.exe" -m mkdocs build --strict
if ($LASTEXITCODE -ne 0) {
    Write-Host "MkDocs build failed. Fix before push." -ForegroundColor Red
    exit 1
}

Write-Host "2/4  git add..." -ForegroundColor Cyan
git add .

Write-Host "3/4  commit..." -ForegroundColor Cyan
git commit -m "Upgrade Learning Hub to v1.3 Code Examples"

Write-Host "4/4  push..." -ForegroundColor Cyan
git push

Write-Host "Done." -ForegroundColor Green
