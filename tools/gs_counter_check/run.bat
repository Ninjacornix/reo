@echo off
setlocal
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_RT=%TASK_ROOT%\third_party\PS2Recomp\ps2xRuntime"
set "TASK_BUILD=%TASK_ROOT%\third_party\PS2Recomp\out\build"
set "TASK_OUT=%TASK_ROOT%\build-ninja\gs_counter_check"
if not "%~1"=="" set "TASK_OUT=%TASK_OUT%-%~1"
rem Python interpreter: REO_PYTHON if set, otherwise python on PATH.
set "TASK_PY=python"
if defined REO_PYTHON set "TASK_PY=%REO_PYTHON%"
set "TASK_VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
for /f "usebackq delims=" %%V in (`"%TASK_VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "TASK_VS_ROOT=%%V"
if not defined TASK_VS_ROOT exit /b 1
call "%TASK_VS_ROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
if errorlevel 1 exit /b 1
if not exist "%TASK_OUT%" mkdir "%TASK_OUT%"
for %%V in (baseline candidate) do (
 cl /nologo /MD /EHsc /O2 /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX ^
 /I "%TASK_RT%\include" /I "%TASK_RT%\src\lib\Kernel" ^
 /I "%TASK_BUILD%\_deps\fmt-src\include" /I "%TASK_BUILD%\_deps\elfio-src\include" ^
 /I "%TASK_BUILD%\_deps\raylib-src\src" ^
 "%~dp0main.cpp" "%TASK_ROOT%\build-ninja\m2-gs-counters\%%V.cpp" ^
 /Fo"%TASK_OUT%\\" /Fe"%TASK_OUT%\%%V.exe" ^
 /link "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" ^
 "%TASK_BUILD%\_deps\raylib-build\raylib\Release\raylib.lib" ^
 "%TASK_BUILD%\_deps\raylib-build\raylib\external\glfw\src\glfw.dir\Release\glfw.lib" ^
 "%TASK_BUILD%\_deps\fmt-build\Release\fmt.lib" ^
 "%TASK_BUILD%\_deps\libdwarf-build\src\lib\libdwarf\Release\dwarf.lib" ^
 opengl32.lib gdi32.lib winmm.lib user32.lib shell32.lib ole32.lib advapi32.lib ^
 >"%TASK_OUT%\%%V-build.log" 2>&1
 if errorlevel 1 (type "%TASK_OUT%\%%V-build.log" & exit /b 1)
)
set "REO_GS_NO_PARALLEL="
set "REO_GS_NO_FASTPATH="
set "REO_GS_TRI_PALETTE_CACHE=0"
set "REO_GS_EARLY_TESTS=0"
for %%M in (serial parallel) do (
 if "%%M"=="serial" (set "REO_GS_TRI_PARALLEL=0") else (set "REO_GS_TRI_PARALLEL=1")
 for %%V in (baseline candidate) do (
  "%TASK_OUT%\%%V.exe" --dump "%TASK_OUT%\%%V-%%M.vram" --bench 0 >"%TASK_OUT%\%%V-%%M.log" 2>&1
  if errorlevel 1 (type "%TASK_OUT%\%%V-%%M.log" & exit /b 1)
 )
 for /L %%R in (1,1,9) do (
  for %%V in (baseline candidate) do (
   "%TASK_OUT%\%%V.exe" --bench 16 >"%TASK_OUT%\%%V-%%M-bench-%%R.log" 2>&1
   if errorlevel 1 (type "%TASK_OUT%\%%V-%%M-bench-%%R.log" & exit /b 1)
  )
 )
)
"%TASK_PY%" -X utf8 "%~dp0compare.py" "%TASK_OUT%"
exit /b %ERRORLEVEL%
