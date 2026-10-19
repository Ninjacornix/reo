@echo off
setlocal
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_RT=%TASK_ROOT%\third_party\PS2Recomp\ps2xRuntime"
set "TASK_BUILD=%TASK_ROOT%\third_party\PS2Recomp\out\build"
set "TASK_OUT=%TASK_ROOT%\build-ninja\m2-scenario\math\selftest"
if not exist "%TASK_OUT%" mkdir "%TASK_OUT%"
call "%~dp0..\vcvars64.bat"
if errorlevel 1 exit /b 1
cl /nologo /MD /EHsc /O2 /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX ^
 /I "%TASK_RT%\include" /I "%TASK_ROOT%\recomp\config\output" ^
 /I "%TASK_ROOT%\recomp\config\output_ovl\o0" ^
 /I "%TASK_RT%\src\lib\Kernel" /I "%TASK_BUILD%\_deps\fmt-src\include" ^
 /I "%TASK_BUILD%\_deps\elfio-src\include" /I "%TASK_BUILD%\_deps\raylib-src\src" ^
 "%~dp0m2_scenario_math_selftest.cpp" ^
 "%TASK_ROOT%\recomp\config\output_ovl\o0\o0_003700C0_0x3700c0.cpp" ^
 "%TASK_ROOT%\recomp\config\output_ovl\o0\o0_00370100_0x370100.cpp" ^
 "%TASK_ROOT%\recomp\config\output\sub_00192190_0x192190.cpp" ^
 "%TASK_ROOT%\recomp\config\output\sub_001921A0_0x1921a0.cpp" ^
 "%TASK_ROOT%\recomp\config\output\sub_0018F340_0x18f340.cpp" ^
 "%TASK_ROOT%\recomp\config\output\sub_0018F470_0x18f470.cpp" ^
 "%TASK_ROOT%\recomp\config\output\sub_0018F570_0x18f570.cpp" ^
 "%TASK_ROOT%\recomp\config\output\sub_0018F710_0x18f710.cpp" ^
 "%TASK_ROOT%\recomp\config\output\sub_0018F7E0_0x18f7e0.cpp" ^
 "%TASK_ROOT%\recomp\config\output\sub_00191280_0x191280.cpp" ^
 "%TASK_ROOT%\recomp\config\output\sub_001921B0_0x1921b0.cpp" ^
 "%TASK_ROOT%\recomp\config\output\sub_0018FDF0_0x18fdf0.cpp" ^
 "%TASK_ROOT%\recomp\config\output\sub_00191500_0x191500.cpp" ^
 /Fo"%TASK_OUT%\\" /Fe"%TASK_OUT%\m2_scenario_math_selftest.exe" ^
 /link "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" ^
 "%TASK_BUILD%\_deps\raylib-build\raylib\Release\raylib.lib" ^
 "%TASK_BUILD%\_deps\raylib-build\raylib\external\glfw\src\glfw.dir\Release\glfw.lib" ^
 "%TASK_BUILD%\_deps\fmt-build\Release\fmt.lib" ^
 "%TASK_BUILD%\_deps\libdwarf-build\src\lib\libdwarf\Release\dwarf.lib" ^
 opengl32.lib gdi32.lib winmm.lib user32.lib shell32.lib ole32.lib advapi32.lib ^
 >"%TASK_OUT%\build.log" 2>&1
if errorlevel 1 (type "%TASK_OUT%\build.log" & exit /b 1)
"%TASK_OUT%\m2_scenario_math_selftest.exe" "%TASK_ROOT%\game_data\SLUS_207.65" "%TASK_ROOT%\build-ninja\m2-scenario\math\original-o0.bin" >"%TASK_OUT%\tests.log" 2>&1
set "TASK_RESULT=%ERRORLEVEL%"
type "%TASK_OUT%\tests.log"
exit /b %TASK_RESULT%
