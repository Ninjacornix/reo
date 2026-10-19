@echo off
call "%~dp0..\vcvars64.bat"
if errorlevel 1 exit /b 1
cd /d "%~dp0\..\.."
if not exist build-ninja\cheat-check mkdir build-ninja\cheat-check
cl /nologo /std:c++20 /EHsc /O2 tools\cheat_check\main.cpp /Fo:build-ninja\cheat-check\main.obj /Fe:build-ninja\cheat-check\check.exe
if errorlevel 1 exit /b 1
build-ninja\cheat-check\check.exe
