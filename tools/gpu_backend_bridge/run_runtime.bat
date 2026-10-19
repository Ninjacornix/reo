@echo off
setlocal
rem Parent-owned actual FIFO test with mock backend. No native game launch.
rem Usage: run_runtime.bat [runtime-build] [fresh-output-directory]
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_RT=%TASK_ROOT%\third_party\PS2Recomp\ps2xRuntime"
set "TASK_BUILD=%TASK_ROOT%\third_party\PS2Recomp\out\build"
if not "%~1"=="" set "TASK_BUILD=%~f1"
set "TASK_ROUTE=%TASK_ROOT%\build-ninja\m2-gpu-runtime-routing"
if not "%~3"=="" set "TASK_ROUTE=%~f3"
set "TASK_TEST=%~dp0runtime_main.cpp"
if not "%~4"=="" set "TASK_TEST=%~f4"
set "TASK_OUT=%TASK_ROUTE%\runtime-validation1"
if not "%~2"=="" set "TASK_OUT=%~f2"
if exist "%TASK_OUT%" (
    echo Refusing to overwrite existing validation output: "%TASK_OUT%"
    echo Pass a fresh output directory as the second argument.
    exit /b 1
)
if not exist "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" exit /b 1
set "TASK_VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
for /f "usebackq delims=" %%V in (`"%TASK_VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "TASK_VS_ROOT=%%V"
if not defined TASK_VS_ROOT exit /b 1
call "%TASK_VS_ROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
if not exist "%TASK_OUT%" mkdir "%TASK_OUT%"
cl /nologo /MD /EHsc /O2 /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX ^
 /I "%TASK_ROUTE%" /I "%TASK_ROUTE%\runtime\src\lib" /I "%TASK_RT%\include" /I "%TASK_RT%\src\lib" /I "%TASK_RT%\src\lib\Kernel" ^
 /I "%TASK_BUILD%\_deps\fmt-src\include" /I "%TASK_BUILD%\_deps\elfio-src\include" ^
 /I "%TASK_BUILD%\_deps\raylib-src\src" ^
 "%TASK_TEST%" "%TASK_ROUTE%\gs_backend_route.cpp" ^
 "%TASK_ROUTE%\runtime\src\lib\ps2_gs_gpu.cpp" ^
 "%TASK_ROUTE%\runtime\src\lib\ps2_gif_arbiter.cpp" ^
 "%TASK_ROUTE%\runtime\src\lib\ps2_memory.cpp" ^
 /Fo"%TASK_OUT%\\" /Fe"%TASK_OUT%\gpu_runtime_route_check.exe" ^
 /link "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" ^
 "%TASK_BUILD%\_deps\raylib-build\raylib\Release\raylib.lib" ^
 "%TASK_BUILD%\_deps\raylib-build\raylib\external\glfw\src\glfw.dir\Release\glfw.lib" ^
 "%TASK_BUILD%\_deps\fmt-build\Release\fmt.lib" ^
 "%TASK_BUILD%\_deps\libdwarf-build\src\lib\libdwarf\Release\dwarf.lib" ^
 opengl32.lib gdi32.lib winmm.lib user32.lib shell32.lib ole32.lib advapi32.lib ^
 >"%TASK_OUT%\build.log" 2>&1
if errorlevel 1 (type "%TASK_OUT%\build.log" & exit /b 1)
"%TASK_OUT%\gpu_runtime_route_check.exe" >"%TASK_OUT%\run.log" 2>&1
set "TASK_RESULT=%ERRORLEVEL%"
type "%TASK_OUT%\run.log"
exit /b %TASK_RESULT%
