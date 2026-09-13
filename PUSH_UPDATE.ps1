Set-Location "C:\HCT_LearningHub"

Write-Host "1/4 - Checking site..." -ForegroundColor Cyan
& ".\.venv\Scripts\python.exe" -m mkdocs build --strict
if ($LASTEXITCODE -ne 0) {
    Write-Host "MkDocs build failed. Fix errors before pushing." -ForegroundColor Red
    exit 1
}

Write-Host "2/4 - Git add..." -ForegroundColor Cyan
git add .

Write-Host "3/4 - Commit..." -ForegroundColor Cyan
git commit -m "Rebuild Microcontroller course from QNU source materials"

Write-Host "4/4 - Push..." -ForegroundColor Cyan
git push

Write-Host "Done. GitHub Actions will publish the updated Learning Hub." -ForegroundColor Green
