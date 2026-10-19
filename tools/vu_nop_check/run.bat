@echo off
setlocal
rem Root coordinator runs this. No native executable or full-runtime build.
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_RUNTIME=%TASK_ROOT%\third_party\PS2Recomp\ps2xRuntime"
set "TASK_OUT=%TASK_ROOT%\build-ninja\m2-vu-nop"
set "TASK_ROUNDS=%~1"
if not defined TASK_ROUNDS set "TASK_ROUNDS=11"
set "TASK_SUFFIX=%~2"
if not defined TASK_SUFFIX set "TASK_SUFFIX=validation1"
set "TASK_WEIGHTED=%TASK_ROOT%\build-ninja\smoke\20261011-185621-m2-weighted-room-baseline\vu1-kevin"
set "TASK_STATIC=%TASK_ROOT%\build-ninja\smoke\20261011-181645-m2-depth-wake-original-room-check\vu1-room"
for /f "usebackq tokens=*" %%V in (`"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "TASK_VS_ROOT=%%V"
if not defined TASK_VS_ROOT exit /b 1
call "%TASK_VS_ROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
cl /nologo /MD /EHsc /O2 /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX /DREO_VU_ISOLATED_RUNTIME_STUBS=1 ^
    /I "%TASK_ROOT%\tools\vu1_check\stubs" /I "%TASK_RUNTIME%\include" /I "%TASK_RUNTIME%\src\lib" ^
    "%~dp0main.cpp" "%TASK_OUT%\ps2_vu1.baseline.cpp" ^
    "%TASK_RUNTIME%\src\lib\vu_specialized_route.cpp" "%TASK_RUNTIME%\src\lib\vu_native_geometry_route.cpp" ^
    "%TASK_RUNTIME%\src\lib\vu_cost_attribution.cpp" ^
    /Fo"%TASK_OUT%\\" /Fe"%TASK_OUT%\vu_nop_baseline.exe" ^
    >"%TASK_OUT%\build-baseline.log" 2>&1
if errorlevel 1 (
    type "%TASK_OUT%\build-baseline.log"
    exit /b 1
)
cl /nologo /MD /EHsc /O2 /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX /DREO_VU_ISOLATED_RUNTIME_STUBS=1 ^
    /I "%TASK_ROOT%\tools\vu1_check\stubs" /I "%TASK_RUNTIME%\include" /I "%TASK_RUNTIME%\src\lib" ^
    "%~dp0main.cpp" "%TASK_OUT%\ps2_vu1.cpp" ^
    "%TASK_RUNTIME%\src\lib\vu_specialized_route.cpp" "%TASK_RUNTIME%\src\lib\vu_native_geometry_route.cpp" ^
    "%TASK_RUNTIME%\src\lib\vu_cost_attribution.cpp" ^
    /Fo"%TASK_OUT%\\" /Fe"%TASK_OUT%\vu_nop_candidate.exe" ^
    >"%TASK_OUT%\build-candidate.log" 2>&1
if errorlevel 1 (
    type "%TASK_OUT%\build-candidate.log"
    exit /b 1
)
"%TASK_OUT%\vu_nop_baseline.exe" "%TASK_OUT%\baseline-%TASK_SUFFIX%" "%TASK_ROUNDS%" "%TASK_WEIGHTED%" "%TASK_STATIC%" >"%TASK_OUT%\baseline-%TASK_SUFFIX%.log" 2>&1
if errorlevel 1 (
    type "%TASK_OUT%\baseline-%TASK_SUFFIX%.log"
    exit /b 1
)
"%TASK_OUT%\vu_nop_candidate.exe" "%TASK_OUT%\candidate-%TASK_SUFFIX%" "%TASK_ROUNDS%" "%TASK_WEIGHTED%" "%TASK_STATIC%" >"%TASK_OUT%\candidate-%TASK_SUFFIX%.log" 2>&1
if errorlevel 1 (
    type "%TASK_OUT%\candidate-%TASK_SUFFIX%.log"
    exit /b 1
)
python "%~dp0compare.py" "%TASK_OUT%\baseline-%TASK_SUFFIX%" "%TASK_OUT%\candidate-%TASK_SUFFIX%"
exit /b %errorlevel%
