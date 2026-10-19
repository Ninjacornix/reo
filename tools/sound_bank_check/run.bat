@echo off
setlocal
rem Compile only the private bank helper/probe; never builds or launches the game.
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_HELPERS=%TASK_ROOT%\third_party\PS2Recomp\ps2xRuntime\src\lib\Kernel\Syscalls\Helpers"
set "TASK_OUT=%TASK_ROOT%\build-ninja\sound_bank_check"
if "%~1"=="" (
    echo Usage: tools\sound_bank_check\run.bat ^<completed capture directory^> [Kevin-confirm capture directory]
    exit /b 1
)
for /f "usebackq tokens=*" %%V in (`"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "TASK_VS_ROOT=%%V"
if not defined TASK_VS_ROOT exit /b 1
call "%TASK_VS_ROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
if not exist "%TASK_OUT%" mkdir "%TASK_OUT%"
cl /nologo /MD /EHsc /O2 /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX ^
    /I "%TASK_HELPERS%" "%~dp0main.cpp" "%TASK_HELPERS%\ReoSoundBanks.cpp" ^
    /Fo"%TASK_OUT%\\" /Fe"%TASK_OUT%\sound_bank_check.exe" ^
    >"%TASK_OUT%\build.log" 2>&1
if errorlevel 1 (
    type "%TASK_OUT%\build.log"
    exit /b 1
)
if "%~2"=="" (
    "%TASK_OUT%\sound_bank_check.exe" "%~1"
) else (
    "%TASK_OUT%\sound_bank_check.exe" "%~1" "%~2"
)
exit /b %errorlevel%
