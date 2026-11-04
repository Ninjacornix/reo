@echo off
setlocal
call "%~dp0..\vcvars64.bat"
if errorlevel 1 exit /b 1
cd /d "%~dp0\..\.."
set "TASK_STB=third_party\PS2Recomp\out\build\_deps\raylib-src\src\external"
if not "%~1"=="" set "TASK_STB=%~f1\src\external"
if not exist "%TASK_STB%\stb_image_write.h" (
    echo Supply the raylib source folder as the first argument.
    exit /b 1
)
if not exist build-ninja\gs-register-check mkdir build-ninja\gs-register-check
cl /nologo /std:c++20 /EHsc /O2 /Gy /DNOMINMAX /D_CRT_SECURE_NO_WARNINGS /I"%TASK_STB%" tools\gs_register_check\main.cpp runtime\gs\gs_renderer.cpp /Fo:build-ninja\gs-register-check\ /Fe:build-ninja\gs-register-check\check.exe /link /OPT:REF user32.lib gdi32.lib
if errorlevel 1 exit /b 1
build-ninja\gs-register-check\check.exe
