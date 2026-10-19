@echo off
setlocal
rem Coordinator only. This script compiles/runs synthetic fixtures, not the game.
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_RT=%TASK_ROOT%\third_party\PS2Recomp\ps2xRuntime"
set "TASK_BUILD=%TASK_ROOT%\third_party\PS2Recomp\out\build"
if not "%~1"=="" set "TASK_BUILD=%~f1"
set "TASK_OUT=%TASK_ROOT%\build-ninja\m2-clut-shadow-proposal"
if not exist "%TASK_OUT%\source-manifest.json" exit /b 1
set "TASK_RESULTS=%TASK_OUT%\validation2"
if not "%~2"=="" set "TASK_RESULTS=%~f2"
rem Never overwrite a prior failure or parity artifact. Choose a fresh results directory.
if exist "%TASK_RESULTS%" exit /b 1
mkdir "%TASK_RESULTS%"
if errorlevel 1 exit /b 1
set "TASK_VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
for /f "usebackq delims=" %%V in (`"%TASK_VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "TASK_VS_ROOT=%%V"
if not defined TASK_VS_ROOT exit /b 1
call "%TASK_VS_ROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
cl /nologo /MD /EHsc /O2 /std:c++20 /DNOMINMAX "%~dp0core.cpp" /Fo"%TASK_RESULTS%\core.obj" /Fe"%TASK_RESULTS%\core.exe" >"%TASK_RESULTS%\core-build.log" 2>&1
if errorlevel 1 (type "%TASK_RESULTS%\core-build.log" & exit /b 1)
"%TASK_RESULTS%\core.exe" >"%TASK_RESULTS%\core.log" 2>&1
if errorlevel 1 (type "%TASK_RESULTS%\core.log" & exit /b 1)
cl /nologo /MD /EHsc /O2 /fp:precise /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX ^
    /I "%TASK_RT%\include" /I "%TASK_RT%\src\lib" /I "%TASK_RT%\src\lib\Kernel" ^
    /I "%TASK_BUILD%\_deps\fmt-src\include" /I "%TASK_BUILD%\_deps\elfio-src\include" ^
    /I "%TASK_BUILD%\_deps\raylib-src\src" ^
    "%~dp0integration.cpp" "%TASK_OUT%\ps2_gs_gpu.cpp" "%TASK_OUT%\ps2_gs_rasterizer.cpp" ^
    /Fo"%TASK_RESULTS%\\" /Fe"%TASK_RESULTS%\integration.exe" ^
    /link "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" ^
    "%TASK_BUILD%\_deps\raylib-build\raylib\Release\raylib.lib" ^
    "%TASK_BUILD%\_deps\raylib-build\raylib\external\glfw\src\glfw.dir\Release\glfw.lib" ^
    "%TASK_BUILD%\_deps\fmt-build\Release\fmt.lib" ^
    "%TASK_BUILD%\_deps\libdwarf-build\src\lib\libdwarf\Release\dwarf.lib" ^
    opengl32.lib gdi32.lib winmm.lib user32.lib shell32.lib ole32.lib advapi32.lib ^
    >"%TASK_RESULTS%\integration-build.log" 2>&1
if errorlevel 1 (type "%TASK_RESULTS%\integration-build.log" & exit /b 1)
set "REO_GS_CLUT_SHADOW_AT=0"
set "REO_GS_CLUT_SHADOW_SECONDS=60"
set "REO_GS_CLUT_SHADOW_COUNT=64"
set "REO_GS_CLUT_SHADOW_LOG_LIMIT=64"
set "REO_GS_CLUT_SHADOW_ZBP=224"
set "REO_GS_TRI_PROBE_AT="
set "REO_GS_PIPELINE_AT="
set "REO_GS_TRI_BATCH=0"
set "REO_GS_CLUT_SHADOW=0"
"%TASK_RESULTS%\integration.exe" "%TASK_RESULTS%\off.vram" >"%TASK_RESULTS%\off.log" 2>&1
if errorlevel 1 (type "%TASK_RESULTS%\off.log" & exit /b 1)
set "REO_GS_CLUT_SHADOW=1"
"%TASK_RESULTS%\integration.exe" "%TASK_RESULTS%\on.vram" >"%TASK_RESULTS%\on.log" 2>&1
if errorlevel 1 (type "%TASK_RESULTS%\on.log" & exit /b 1)
python "%~dp0compare.py" "%TASK_RESULTS%"
exit /b %errorlevel%
