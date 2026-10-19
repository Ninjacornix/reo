@echo off
setlocal
rem Coordinator only: [sprites=16] [rounds=9] [cache=1] [parallel=0] [label=validation1]
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_RT=%TASK_ROOT%\third_party\PS2Recomp\ps2xRuntime"
set "TASK_BUILD=%TASK_ROOT%\third_party\PS2Recomp\out\build"
set "TASK_SOURCE_DIR=%TASK_ROOT%\build-ninja\m2-gs-sprite-depth-parallel"
set "TASK_BENCH=16"
set "TASK_ROUNDS=9"
set "TASK_CACHE=1"
set "TASK_PARALLEL=0"
set "TASK_LABEL=textured-validation1"
if not "%~1"=="" set "TASK_BENCH=%~1"
if not "%~2"=="" set "TASK_ROUNDS=%~2"
if not "%~3"=="" set "TASK_CACHE=%~3"
if not "%~4"=="" set "TASK_PARALLEL=%~4"
if not "%~5"=="" set "TASK_LABEL=%~5"
set "TASK_OUT=%TASK_SOURCE_DIR%\%TASK_LABEL%"
if not exist "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" exit /b 1
if not exist "%TASK_SOURCE_DIR%\ps2_gs_rasterizer.candidate2.cpp" exit /b 1
if not exist "%TASK_SOURCE_DIR%\ps2_gs_rasterizer.cpp" exit /b 1
set "TASK_VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
for /f "usebackq delims=" %%V in (`"%TASK_VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "TASK_VS_ROOT=%%V"
if not defined TASK_VS_ROOT exit /b 1
call "%TASK_VS_ROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
if errorlevel 1 exit /b 1
if not exist "%TASK_OUT%" mkdir "%TASK_OUT%"
copy /y "%TASK_SOURCE_DIR%\ps2_gs_rasterizer.cpp" "%TASK_OUT%\selected_source.cpp" >nul
set "TASK_VARIANT=baseline"
set "TASK_DEFINE=/DREO_SPRITE_DEPTH_CANDIDATE"
call :compile
if errorlevel 1 exit /b 1
copy /y "%TASK_SOURCE_DIR%\ps2_gs_rasterizer.candidate2.cpp" "%TASK_OUT%\selected_source.cpp" >nul
set "TASK_VARIANT=candidate"
set "TASK_DEFINE=/DREO_SPRITE_DEPTH_CANDIDATE /DREO_SPRITE_TEXTURE_DEPTH_CANDIDATE"
call :compile
if errorlevel 1 exit /b 1
set "REO_GS_NO_PARALLEL="
set "REO_GS_NO_FASTPATH="
set "REO_GS_NO_TEXEL_CACHE="
set "REO_GS_TRI_PROBE_AT="
set "REO_GS_PIPELINE_AT="
set "REO_SPR_PROFILE_AT="
set "REO_GS_TRI_PALETTE_CACHE=%TASK_CACHE%"
set "REO_GS_EARLY_TESTS=0"
set "REO_GS_TRI_PARALLEL=%TASK_PARALLEL%"
set "REO_GS_SPRITE_DEPTH_PARALLEL=1"
"%TASK_OUT%\baseline.exe" --dump "%TASK_OUT%\baseline.vram" --bench %TASK_BENCH% --rounds %TASK_ROUNDS% >"%TASK_OUT%\baseline.log" 2>&1
if errorlevel 1 (type "%TASK_OUT%\baseline.log" & exit /b 1)
"%TASK_OUT%\candidate.exe" --dump "%TASK_OUT%\candidate.vram" --bench %TASK_BENCH% --rounds %TASK_ROUNDS% >"%TASK_OUT%\candidate.log" 2>&1
if errorlevel 1 (type "%TASK_OUT%\candidate.log" & exit /b 1)
python "%~dp0compare-textured.py" "%TASK_OUT%"
exit /b %errorlevel%

:compile
cl /nologo /MD /EHsc /O2 /fp:precise /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX ^
    %TASK_DEFINE% ^
    /I "%TASK_OUT%" /I "%TASK_RT%\include" /I "%TASK_RT%\src\lib\Kernel" ^
    /I "%TASK_BUILD%\_deps\fmt-src\include" /I "%TASK_BUILD%\_deps\elfio-src\include" ^
    /I "%TASK_BUILD%\_deps\raylib-src\src" ^
    "%~dp0textured_main.cpp" /Fo"%TASK_OUT%\%TASK_VARIANT%.obj" /Fe"%TASK_OUT%\%TASK_VARIANT%.exe" ^
    /link "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" ^
    "%TASK_BUILD%\_deps\raylib-build\raylib\Release\raylib.lib" ^
    "%TASK_BUILD%\_deps\raylib-build\raylib\external\glfw\src\glfw.dir\Release\glfw.lib" ^
    "%TASK_BUILD%\_deps\fmt-build\Release\fmt.lib" ^
    "%TASK_BUILD%\_deps\libdwarf-build\src\lib\libdwarf\Release\dwarf.lib" ^
    opengl32.lib gdi32.lib winmm.lib user32.lib shell32.lib ole32.lib advapi32.lib ^
    >"%TASK_OUT%\build-%TASK_VARIANT%.log" 2>&1
if errorlevel 1 (type "%TASK_OUT%\build-%TASK_VARIANT%.log" & exit /b 1)
exit /b 0
