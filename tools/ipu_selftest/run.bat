@echo off
rem IPU self-test (PS2Recomp ps2xRuntime/src/lib/ipu): hand-built MPEG-2 bitstreams through a
rem fake DMA host. Usage: tools\ipu_selftest\run.bat   (needs Visual Studio 2022 Build Tools)
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
set R=%~dp0..\..\third_party\PS2Recomp\ps2xRuntime\src\lib
set O=%~dp0..\..\build-ninja\ipu_selftest
if not exist "%O%" mkdir "%O%"
cl /nologo /EHsc /O2 /std:c++20 /I "%R%" "%~dp0ipu_selftest.cpp" "%R%\ipu\ps2_ipu.cpp" /Fo"%O%\\" /Fe"%O%\ipu_selftest.exe" >"%O%\build.log" 2>&1 || (type "%O%\build.log" & exit /b 1)
"%O%\ipu_selftest.exe"
if errorlevel 1 exit /b 1
cl /nologo /EHsc /O2 /std:c++20 /I "%R%" "%~dp0ipu_idct_selftest.cpp" /Fo"%O%\\" /Fe"%O%\ipu_idct_selftest.exe" >"%O%\idct-build.log" 2>&1 || (type "%O%\idct-build.log" & exit /b 1)
"%O%\ipu_idct_selftest.exe"
if errorlevel 1 exit /b 1
cl /nologo /EHsc /O2 /std:c++20 /I "%R%" "%~dp0ipu_bitreader_selftest.cpp" /Fo"%O%\\" /Fe"%O%\ipu_bitreader_selftest.exe" >"%O%\bitreader-build.log" 2>&1 || (type "%O%\bitreader-build.log" & exit /b 1)
"%O%\ipu_bitreader_selftest.exe"
