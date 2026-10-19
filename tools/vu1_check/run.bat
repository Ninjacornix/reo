@echo off
setlocal
rem Production VU1 interpreter; isolated packet sinks, no game or full-runtime build.
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_RUNTIME=%TASK_ROOT%\third_party\PS2Recomp\ps2xRuntime"
set "TASK_OUT=%TASK_ROOT%\build-ninja\vu1_check"
for /f "usebackq tokens=*" %%V in (`"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "TASK_VS_ROOT=%%V"
if not defined TASK_VS_ROOT exit /b 1
call "%TASK_VS_ROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
if not exist "%TASK_OUT%" mkdir "%TASK_OUT%"
cl /nologo /MD /EHsc /O2 /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX /DREO_VU_ISOLATED_RUNTIME_STUBS=1 ^
    /I "%~dp0stubs" /I "%TASK_RUNTIME%\include" /I "%TASK_RUNTIME%\src\lib" ^
    "%~dp0main.cpp" "%TASK_RUNTIME%\src\lib\ps2_vu1.cpp" ^
    "%TASK_RUNTIME%\src\lib\vu_specialized_route.cpp" "%TASK_RUNTIME%\src\lib\vu_native_geometry_route.cpp" ^
    "%TASK_RUNTIME%\src\lib\vu_cost_attribution.cpp" ^
    /Fo"%TASK_OUT%\\" /Fe"%TASK_OUT%\vu1_check.exe" ^
    >"%TASK_OUT%\build.log" 2>&1
if errorlevel 1 (
    type "%TASK_OUT%\build.log"
    exit /b 1
)
"%TASK_OUT%\vu1_check.exe" %*
exit /b %errorlevel%
