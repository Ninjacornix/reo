@echo off
setlocal
if "%~3"=="" (
    echo Usage: run-check.bat CAPTURE_DIR FRESH_RESULTS_DIR FACTORY_DIR [RUNTIME_ROOT]
    exit /b 2
)
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_RUNTIME=%TASK_ROOT%\third_party\PS2Recomp\ps2xRuntime"
if not "%~4"=="" for %%D in ("%~f4\.") do set "TASK_RUNTIME=%%~fD"
set "TASK_LIB=%TASK_RUNTIME%\src\lib"
set "TASK_OUT=%TASK_ROOT%\build-ninja\vu-whole-check"
for %%D in ("%~f1\.") do set "TASK_CAPTURE=%%~fD"
for %%D in ("%~f2\.") do set "TASK_RESULTS=%%~fD"
for %%D in ("%~f3\.") do set "TASK_FACTORY=%%~fD"
for %%D in ("%TASK_CAPTURE%" "%TASK_RESULTS%" "%TASK_FACTORY%") do (
    if /I "%%~fD"=="%TASK_OUT%" (
        echo The build directory is reserved: "%TASK_OUT%"
        exit /b 2
    )
)
if exist "%TASK_RESULTS%" (
    echo Fresh results directory required: "%TASK_RESULTS%"
    exit /b 2
)
call "%TASK_ROOT%\tools\vcvars64.bat"
if errorlevel 1 exit /b 1
set "TASK_COMPILER=cl.exe"
set "TASK_FLAGS="
where clang-cl.exe >nul 2>nul
if not errorlevel 1 (
    set "TASK_COMPILER=clang-cl.exe"
    set "TASK_FLAGS=--target=x86_64-pc-windows-msvc /clang:-msse4.1"
)
if not exist "%TASK_OUT%" mkdir "%TASK_OUT%"
"%TASK_COMPILER%" %TASK_FLAGS% /nologo /MD /EHsc /O2 /fp:precise /std:c++20 ^
    /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX /DREO_VU_ISOLATED_RUNTIME_STUBS=1 ^
    /I "%TASK_ROOT%\tools\vu1_check\stubs" /I "%TASK_RUNTIME%\include" ^
    /I "%TASK_LIB%" /I "%TASK_FACTORY%" /I "%TASK_ROOT%\tools\vu_whole_aot" ^
    "%~dp0check.cpp" "%TASK_LIB%\ps2_vu1.cpp" "%TASK_LIB%\vu_whole_program.cpp" ^
    "%TASK_LIB%\vu_specialized_route.cpp" "%TASK_LIB%\vu_native_geometry_route.cpp" ^
    "%TASK_LIB%\vu_cost_attribution.cpp" "%TASK_FACTORY%\reo_vu_whole_registered_generated.cpp" ^
    /Fo"%TASK_OUT%\\" /Fe"%TASK_OUT%\check.exe" >"%TASK_OUT%\build.log" 2>&1
if errorlevel 1 (
    type "%TASK_OUT%\build.log"
    exit /b 1
)
"%TASK_OUT%\check.exe" "%TASK_CAPTURE%" "%TASK_RESULTS%" >"%TASK_OUT%\check.log" 2>&1
if errorlevel 1 (
    type "%TASK_OUT%\check.log"
    exit /b 1
)
findstr /B /C:"PASS " "%TASK_OUT%\check.log"
exit /b 0
