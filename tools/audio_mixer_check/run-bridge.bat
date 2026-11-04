@echo off
setlocal
call "%~dp0..\vcvars64.bat"
if errorlevel 1 exit /b 1
for %%R in ("%~dp0..\..") do set "REO_BRIDGE_ROOT=%%~fR"
set "REO_BRIDGE_OUT=%REO_BRIDGE_ROOT%\build-ninja\audio_bridge_check"
if not exist "%REO_BRIDGE_OUT%" mkdir "%REO_BRIDGE_OUT%"
cl /nologo /MD /EHsc /O2 /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX /DREO_GAME_FILE1 ^
    "%~dp0bridge_check.cpp" "%~dp0bridge_api_consumer.cpp" ^
    /Fo"%REO_BRIDGE_OUT%\\" /Fe"%REO_BRIDGE_OUT%\file1.exe" >"%REO_BRIDGE_OUT%\file1-build.log" 2>&1
if errorlevel 1 (
    type "%REO_BRIDGE_OUT%\file1-build.log"
    exit /b 1
)
"%REO_BRIDGE_OUT%\file1.exe" 2>&1
if errorlevel 1 exit /b 1
cl /nologo /MD /EHsc /O2 /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX /DREO_GAME_FILE2 ^
    "%~dp0bridge_check.cpp" "%~dp0bridge_api_consumer.cpp" ^
    /Fo"%REO_BRIDGE_OUT%\\" /Fe"%REO_BRIDGE_OUT%\file2.exe" >"%REO_BRIDGE_OUT%\file2-build.log" 2>&1
if errorlevel 1 (
    type "%REO_BRIDGE_OUT%\file2-build.log"
    exit /b 1
)
"%REO_BRIDGE_OUT%\file2.exe" 2>&1
exit /b %errorlevel%
