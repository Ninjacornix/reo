@echo off
setlocal
rem Coordinator only: [runtime build] [rasterizer source] [benchmark count] [palette cache0/1]
rem Compile isolated rasterizer object first; the runtime archive then supplies
rem its other objects without extracting its original rasterizer definition.
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_RT=%TASK_ROOT%\third_party\PS2Recomp\ps2xRuntime"
set "TASK_BUILD=%TASK_ROOT%\third_party\PS2Recomp\out\build"
if not "%~1"=="" set "TASK_BUILD=%~f1"
set "TASK_SOURCE=%TASK_ROOT%\build-ninja\m2-triangle-parallel\ps2_gs_rasterizer.cpp"
if not "%~2"=="" set "TASK_SOURCE=%~f2"
set "TASK_BENCH=16"
if not "%~3"=="" set "TASK_BENCH=%~3"
set "TASK_CACHE=1"
if not "%~4"=="" set "TASK_CACHE=%~4"
set "TASK_OUT=%TASK_ROOT%\build-ninja\gs_triangle_parallel_check"
if not exist "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" exit /b 1
if not exist "%TASK_SOURCE%" exit /b 1
findstr /C:"REO_GS_TRI_PARALLEL" "%TASK_SOURCE%" >nul
if errorlevel 1 (echo Missing parallel prototype in "%TASK_SOURCE%" & exit /b 1)
set "TASK_VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
for /f "usebackq delims=" %%V in (`"%TASK_VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "TASK_VS_ROOT=%%V"
if not defined TASK_VS_ROOT exit /b 1
call "%TASK_VS_ROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
if errorlevel 1 exit /b 1
if not exist "%TASK_OUT%" mkdir "%TASK_OUT%"
cl /nologo /MD /EHsc /O2 /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX ^
    /I "%TASK_RT%\include" /I "%TASK_RT%\src\lib\Kernel" ^
    /I "%TASK_BUILD%\_deps\fmt-src\include" /I "%TASK_BUILD%\_deps\elfio-src\include" ^
    /I "%TASK_BUILD%\_deps\raylib-src\src" ^
    "%~dp0main.cpp" "%TASK_SOURCE%" ^
    /Fo"%TASK_OUT%\\" /Fe"%TASK_OUT%\gs_triangle_parallel_check.exe" ^
    /link "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" ^
    "%TASK_BUILD%\_deps\raylib-build\raylib\Release\raylib.lib" ^
    "%TASK_BUILD%\_deps\raylib-build\raylib\external\glfw\src\glfw.dir\Release\glfw.lib" ^
    "%TASK_BUILD%\_deps\fmt-build\Release\fmt.lib" ^
    "%TASK_BUILD%\_deps\libdwarf-build\src\lib\libdwarf\Release\dwarf.lib" ^
    opengl32.lib gdi32.lib winmm.lib user32.lib shell32.lib ole32.lib advapi32.lib ^
    >"%TASK_OUT%\build.log" 2>&1
if errorlevel 1 (type "%TASK_OUT%\build.log" & exit /b 1)
set "REO_GS_NO_PARALLEL="
set "REO_GS_NO_FASTPATH="
set "REO_GS_TRI_PALETTE_CACHE=%TASK_CACHE%"
set "REO_GS_EARLY_TESTS=0"
set "REO_GS_TRI_PARALLEL=0"
"%TASK_OUT%\gs_triangle_parallel_check.exe" --dump "%TASK_OUT%\serial.vram" --bench %TASK_BENCH% >"%TASK_OUT%\serial.log" 2>&1
if errorlevel 1 (type "%TASK_OUT%\serial.log" & exit /b 1)
set "REO_GS_TRI_PARALLEL=1"
"%TASK_OUT%\gs_triangle_parallel_check.exe" --dump "%TASK_OUT%\parallel.vram" --bench %TASK_BENCH% >"%TASK_OUT%\parallel.log" 2>&1
if errorlevel 1 (type "%TASK_OUT%\parallel.log" & exit /b 1)
python "%~dp0compare.py" "%TASK_OUT%"
if errorlevel 1 exit /b 1
findstr /C:"BENCH" /C:"independent_checks" "%TASK_OUT%\serial.log" "%TASK_OUT%\parallel.log"
exit /b 0
