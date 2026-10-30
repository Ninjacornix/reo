@echo off
setlocal
set "REO_ROOT=%~dp0"
set "REO_LAUNCHER=%~dp0launcher\bin\Release\net8.0-windows\Outbreak.Launcher.exe"
rem Rebuild when the launcher is missing or any of its sources is newer than the built exe.
powershell -NoProfile -ExecutionPolicy Bypass -Command ^
  "$exe = $env:REO_LAUNCHER; if (!(Test-Path -LiteralPath $exe)) { exit 1 };" ^
  "$built = (Get-Item -LiteralPath $exe).LastWriteTimeUtc;" ^
  "$newer = Get-ChildItem -LiteralPath (Join-Path $env:REO_ROOT 'launcher') -Recurse -File -Include *.cs,*.xaml,*.csproj,*.manifest,*.hlsl,*.cpp,*.def,*.ico,*.json,*.md |" ^
  "  Where-Object { $_.FullName -notmatch '\\(bin|obj|artifacts)\\' -and $_.LastWriteTimeUtc -gt $built } | Select-Object -First 1;" ^
  "if ($newer) { exit 1 }"
if errorlevel 1 (
    powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0launcher\build.ps1"
    if errorlevel 1 (
        echo.
        echo The launcher build failed. If the launcher is already open, close it and run this again.
        pause
        exit /b 1
    )
)
start "" "%REO_LAUNCHER%"
