@echo off
call "%~dp0..\vcvars64.bat"
if errorlevel 1 exit /b 1
cd /d "%~dp0\..\.."
if not exist build-ninja\file2-unlock-check mkdir build-ninja\file2-unlock-check
cl /nologo /std:c++20 /EHsc /O2 tools\cheat_check\file2_unlock_tests.cpp /Fo:build-ninja\file2-unlock-check\main.obj /Fe:build-ninja\file2-unlock-check\check.exe
if errorlevel 1 exit /b 1
build-ninja\file2-unlock-check\check.exe %*
