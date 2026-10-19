@echo off
setlocal
rem Extract and compile the exact private classifier; no runtime/game launches.
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_OUT=%TASK_ROOT%\build-ninja\gs_state_packet_selftest"
set "TASK_VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
for /f "usebackq delims=" %%V in (`"%TASK_VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "TASK_VS_ROOT=%%V"
if not defined TASK_VS_ROOT exit /b 1
call "%TASK_VS_ROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
if errorlevel 1 exit /b 1
if not exist "%TASK_OUT%" mkdir "%TASK_OUT%"
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0extract_gs_state_packet_classifier.ps1" -Source "%TASK_ROOT%\third_party\PS2Recomp\ps2xRuntime\src\lib\ps2_gs_gpu.cpp" -Output "%TASK_OUT%\gs_state_packet_classifier.inc"
if errorlevel 1 exit /b 1
cl /nologo /MD /EHsc /O2 /std:c++20 /I "%TASK_OUT%" "%~dp0gs_state_packet_selftest.cpp" /Fo"%TASK_OUT%\\" /Fe"%TASK_OUT%\gs_state_packet_selftest.exe" >"%TASK_OUT%\build.log" 2>&1
if errorlevel 1 (
    type "%TASK_OUT%\build.log"
    exit /b 1
)
"%TASK_OUT%\gs_state_packet_selftest.exe" >"%TASK_OUT%\tests.log" 2>&1
set "TASK_RESULT=%ERRORLEVEL%"
type "%TASK_OUT%\tests.log"
exit /b %TASK_RESULT%
