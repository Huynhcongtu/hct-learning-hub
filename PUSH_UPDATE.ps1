Set-Location "C:\HCT_LearningHub"
Write-Host "1/4 Build validation..." -ForegroundColor Cyan
& ".\.venv\Scripts\python.exe" -m mkdocs build --strict
if ($LASTEXITCODE -ne 0) { Write-Host "Build failed. Fix before push." -ForegroundColor Red; exit 1 }
Write-Host "2/4 Staging..." -ForegroundColor Cyan
git add .
Write-Host "3/4 Committing..." -ForegroundColor Cyan
git commit -m "Upgrade Learning Hub to v1.2 Illustrated"
Write-Host "4/4 Pushing..." -ForegroundColor Cyan
git push
Write-Host "Done. GitHub Actions will republish the site." -ForegroundColor Green
