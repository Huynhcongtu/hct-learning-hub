$ErrorActionPreference = "Stop"
$Root = Split-Path -Parent (Split-Path -Parent $MyInvocation.MyCommand.Path)

$Targets = @()
$Targets += Get-ChildItem "$Root\labs\*\main.c"
$Targets += Get-ChildItem "$Root\theory\*\main.c"
$Targets += Get-ChildItem "$Root\extensions\*\main.c"
$Targets += Get-Item "$Root\templates\C51_Empty\main.c"

foreach ($Main in $Targets) {
    Write-Host "Checking $($Main.FullName)" -ForegroundColor Cyan
    gcc -DHOST_CHECK -std=c99 -Wno-main -Wno-unused-function -Wno-unused-variable -fsyntax-only $Main.FullName
    if ($LASTEXITCODE -ne 0) { exit 1 }
}
Write-Host "All HOST_CHECK syntax tests passed." -ForegroundColor Green
