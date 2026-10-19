@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
if errorlevel 1 exit /b 1
cd /d "%~dp0\..\.."
if not exist build-ninja\snap-iop-check mkdir build-ninja\snap-iop-check
cl /nologo /std:c++20 /EHsc /W4 /O2 tools\snap_iop_check\main.cpp network\native\snap_iop_transport.cpp /Fo:build-ninja\snap-iop-check\ /Fe:build-ninja\snap-iop-check\check.exe /link ws2_32.lib
if errorlevel 1 exit /b 1
build-ninja\snap-iop-check\check.exe %*
