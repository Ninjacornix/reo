@echo off
setlocal
rem Stage and compile actual patched audio sources; never build or launch the game.
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_OUT=%TASK_ROOT%\build-ninja\audio_mixer_check"
set "TASK_STAGE=%TASK_OUT%\sdk\ps2xRuntime\src\lib\Kernel\Syscalls\Helpers"
if "%~1"=="" (
    echo Usage: tools\audio_mixer_check\run.bat ^<owned imported data directory^>
    exit /b 1
)
for /f "usebackq tokens=*" %%V in (`"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "TASK_VS_ROOT=%%V"
if not defined TASK_VS_ROOT exit /b 1
call "%TASK_VS_ROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
python "%~dp0prepare_sources.py"
if errorlevel 1 exit /b 1
cl /nologo /MD /EHsc /O2 /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX ^
    /I "%TASK_ROOT%\tools" /I "%TASK_STAGE%" /I "%~dp0." ^
    "%~dp0main.cpp" "%TASK_STAGE%\CriAudio.cpp" "%TASK_STAGE%\ReoSoundBanks.cpp" ^
    /Fo"%TASK_OUT%\\" /Fe"%TASK_OUT%\audio_mixer_check.exe" ^
    >"%TASK_OUT%\build.log" 2>&1
if errorlevel 1 (
    type "%TASK_OUT%\build.log"
    exit /b 1
)
"%TASK_OUT%\audio_mixer_check.exe" "%~1"
exit /b %errorlevel%
