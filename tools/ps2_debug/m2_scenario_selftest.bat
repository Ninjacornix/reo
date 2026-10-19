@echo off
setlocal
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_RT=%TASK_ROOT%\third_party\PS2Recomp\ps2xRuntime"
set "TASK_BUILD=%TASK_ROOT%\third_party\PS2Recomp\out\build"
set "TASK_OUT=%TASK_ROOT%\build-ninja\m2-scenario\selftest"
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
if errorlevel 1 exit /b 1
if not exist "%TASK_OUT%" mkdir "%TASK_OUT%"
cl /nologo /MD /EHsc /O2 /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX ^
 /I "%TASK_RT%\include" /I "%TASK_ROOT%\recomp\config\output" ^
 /I "%TASK_ROOT%\recomp\config\output_ovl\o1" ^
 /I "%TASK_RT%\src\lib\Kernel" /I "%TASK_BUILD%\_deps\fmt-src\include" ^
 /I "%TASK_BUILD%\_deps\elfio-src\include" /I "%TASK_BUILD%\_deps\raylib-src\src" ^
 "%~dp0m2_scenario_selftest.cpp" ^
 "%TASK_ROOT%\recomp\config\output\sub_001F73B0_0x1f73b0.cpp" ^
 "%TASK_ROOT%\recomp\config\output_ovl\o1\o1_00588200_0x588200.cpp" ^
 /Fo"%TASK_OUT%\\" /Fe"%TASK_OUT%\m2_scenario_selftest.exe" ^
 /link "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" ^
 "%TASK_BUILD%\_deps\raylib-build\raylib\Release\raylib.lib" ^
 "%TASK_BUILD%\_deps\raylib-build\raylib\external\glfw\src\glfw.dir\Release\glfw.lib" ^
 "%TASK_BUILD%\_deps\fmt-build\Release\fmt.lib" ^
 "%TASK_BUILD%\_deps\libdwarf-build\src\lib\libdwarf\Release\dwarf.lib" ^
 opengl32.lib gdi32.lib winmm.lib user32.lib shell32.lib ole32.lib advapi32.lib ^
 >"%TASK_OUT%\build.log" 2>&1
if errorlevel 1 (type "%TASK_OUT%\build.log" & exit /b 1)
"%TASK_OUT%\m2_scenario_selftest.exe" >"%TASK_OUT%\tests.log" 2>&1
set "TASK_RESULT=%ERRORLEVEL%"
type "%TASK_OUT%\tests.log"
exit /b %TASK_RESULT%
