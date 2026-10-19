@echo off
call "%~dp0..\vcvars64.bat"
if errorlevel 1 exit /b 1
cd /d "%~dp0\..\.."
if not exist build-ninja\usb-keyboard-check mkdir build-ninja\usb-keyboard-check
cl /nologo /std:c++20 /EHsc /W4 /O2 tools\usb_keyboard_check\main.cpp /Fo:build-ninja\usb-keyboard-check\main.obj /Fe:build-ninja\usb-keyboard-check\check.exe
if errorlevel 1 exit /b 1
build-ninja\usb-keyboard-check\check.exe
