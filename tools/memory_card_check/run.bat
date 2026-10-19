@echo off
setlocal
cd /d "%~dp0\..\.."
if not exist build-ninja\memory-card-check mkdir build-ninja\memory-card-check
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
if errorlevel 1 exit /b 1
cl /nologo /std:c++20 /EHsc /I . tools\memory_card_check\main.cpp /Fo:build-ninja\memory-card-check\main.obj /Fe:build-ninja\memory-card-check\check.exe
if errorlevel 1 exit /b 1
build-ninja\memory-card-check\check.exe build-ninja\memory-card-check\card-%RANDOM%-%RANDOM%
exit /b %errorlevel%
