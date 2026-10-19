@echo off
setlocal
rem Coordinator only: optional runtime-build and benchmark packets.
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_RT=%TASK_ROOT%\third_party\PS2Recomp\ps2xRuntime"
set "TASK_BUILD=%TASK_ROOT%\third_party\PS2Recomp\out\build"
if not "%~1"=="" set "TASK_BUILD=%~f1"
set "TASK_BENCH=16"
if not "%~2"=="" set "TASK_BENCH=%~2"
set "TASK_OUT=%TASK_ROOT%\build-ninja\m2-gs-triangle-batch"
if not exist "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" exit /b 1
set "TASK_VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
for /f "usebackq delims=" %%V in (`"%TASK_VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "TASK_VS_ROOT=%%V"
if not defined TASK_VS_ROOT exit /b 1
call "%TASK_VS_ROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
cl /nologo /MD /EHsc /O2 /fp:precise /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX ^
    /I "%TASK_RT%\include" /I "%TASK_RT%\src\lib" /I "%TASK_RT%\src\lib\Kernel" ^
    /I "%TASK_BUILD%\_deps\fmt-src\include" /I "%TASK_BUILD%\_deps\elfio-src\include" ^
    /I "%TASK_BUILD%\_deps\raylib-src\src" ^
    "%~dp0main.cpp" "%TASK_OUT%\ps2_gs_gpu.cpp" "%TASK_OUT%\ps2_gs_rasterizer.cpp" ^
    /Fo"%TASK_OUT%\\" /Fe"%TASK_OUT%\gs_triangle_batch_check.exe" ^
    /link "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" ^
    "%TASK_BUILD%\_deps\raylib-build\raylib\Release\raylib.lib" ^
    "%TASK_BUILD%\_deps\raylib-build\raylib\external\glfw\src\glfw.dir\Release\glfw.lib" ^
    "%TASK_BUILD%\_deps\fmt-build\Release\fmt.lib" ^
    "%TASK_BUILD%\_deps\libdwarf-build\src\lib\libdwarf\Release\dwarf.lib" ^
    opengl32.lib gdi32.lib winmm.lib user32.lib shell32.lib ole32.lib advapi32.lib ^
    >"%TASK_OUT%\build.log" 2>&1
if errorlevel 1 (type "%TASK_OUT%\build.log" & exit /b 1)
set "REO_GS_NO_PARALLEL="
set "REO_GS_TRI_PROBE_AT="
set "REO_GS_PIPELINE_AT="
set "REO_GS_TRI_PALETTE_CACHE=1"
set "REO_GS_EARLY_TESTS=0"
set "REO_GS_TRI_BATCH=0"
"%TASK_OUT%\gs_triangle_batch_check.exe" --dump "%TASK_OUT%\off.vram" --bench %TASK_BENCH% >"%TASK_OUT%\off.log" 2>&1
if errorlevel 1 (type "%TASK_OUT%\off.log" & exit /b 1)
set "REO_GS_TRI_BATCH=1"
"%TASK_OUT%\gs_triangle_batch_check.exe" --dump "%TASK_OUT%\on.vram" --bench %TASK_BENCH% >"%TASK_OUT%\on.log" 2>&1
if errorlevel 1 (type "%TASK_OUT%\on.log" & exit /b 1)
python "%~dp0compare.py" "%TASK_OUT%"
exit /b %errorlevel%
