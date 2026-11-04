@echo off
call "%~dp0..\vcvars64.bat"
if errorlevel 1 exit /b 1
cd /d "%~dp0\..\.."
if not exist build-ninja\native-netcode-check mkdir build-ninja\native-netcode-check
cl /nologo /std:c++20 /EHsc /W4 /WX /O2 tools\native_netcode_check\main.cpp network\native\native_netcode.cpp /Fo:build-ninja\native-netcode-check\ /Fe:build-ninja\native-netcode-check\check.exe
if errorlevel 1 exit /b 1
build-ninja\native-netcode-check\check.exe
