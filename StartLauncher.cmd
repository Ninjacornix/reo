@echo off
setlocal
set "REO_LAUNCHER=%~dp0launcher\bin\Release\net8.0-windows\Outbreak.Launcher.exe"
if not exist "%REO_LAUNCHER%" (
    powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0launcher\build.ps1"
    if errorlevel 1 (pause & exit /b 1)
)
start "" "%REO_LAUNCHER%"
