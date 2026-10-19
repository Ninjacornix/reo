@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
if errorlevel 1 exit /b 1
cd /d "%~dp0\..\.."
if not exist build-ninja\usb-keyboard-check mkdir build-ninja\usb-keyboard-check
cl /nologo /std:c++20 /EHsc /W4 /O2 tools\usb_keyboard_check\main.cpp /Fo:build-ninja\usb-keyboard-check\main.obj /Fe:build-ninja\usb-keyboard-check\check.exe
if errorlevel 1 exit /b 1
build-ninja\usb-keyboard-check\check.exe
