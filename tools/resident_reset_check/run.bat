@echo off
setlocal
rem Usage: tools\resident_reset_check\run.bat [PS2Recomp CMake build directory]
rem Build ps2_runtime in Release first. Results stay in ignored build output.
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_TEST=%TASK_ROOT%\third_party\PS2Recomp\ps2xTest"
set "TASK_RT=%TASK_ROOT%\third_party\PS2Recomp\ps2xRuntime"
set "TASK_BUILD=%TASK_ROOT%\third_party\PS2Recomp\out\build"
if not "%~1"=="" set "TASK_BUILD=%~f1"
set "TASK_OUT=%TASK_ROOT%\build-ninja\resident_reset_check"
if not exist "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" (
    echo Missing Release runtime: "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib"
    exit /b 1
)
set "TASK_VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist "%TASK_VSWHERE%" (
    echo Missing Visual Studio locator: "%TASK_VSWHERE%"
    exit /b 1
)
for /f "usebackq delims=" %%V in (`"%TASK_VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "TASK_VS_ROOT=%%V"
if not defined TASK_VS_ROOT (
    echo Visual Studio C++ x64 tools were not found.
    exit /b 1
)
call "%TASK_VS_ROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
if errorlevel 1 exit /b 1
if not exist "%TASK_OUT%" mkdir "%TASK_OUT%"
if errorlevel 1 exit /b 1


cl /nologo /MD /EHsc /O2 /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX ^
    /I "%TASK_RT%\include" ^
    /I "%TASK_RT%\src\lib" ^
    /I "%TASK_RT%\src\lib\Kernel" ^
    /I "%TASK_ROOT%" ^
    /I "%TASK_BUILD%\_deps\fmt-src\include" ^
    /I "%TASK_BUILD%\_deps\elfio-src\include" ^
    /I "%TASK_BUILD%\_deps\raylib-src\src" ^
    "%~dp0main.cpp" ^
    /Fo"%TASK_OUT%\\" /Fe"%TASK_OUT%\resident_reset_check.exe" ^
    /link "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" ^
    "%TASK_BUILD%\_deps\raylib-build\raylib\Release\raylib.lib" ^
    "%TASK_BUILD%\_deps\raylib-build\raylib\external\glfw\src\glfw.dir\Release\glfw.lib" ^
    "%TASK_BUILD%\_deps\fmt-build\Release\fmt.lib" ^
    "%TASK_BUILD%\_deps\libdwarf-build\src\lib\libdwarf\Release\dwarf.lib" ^
    opengl32.lib gdi32.lib winmm.lib user32.lib shell32.lib ole32.lib advapi32.lib ^
    >"%TASK_OUT%\build.log" 2>&1
if errorlevel 1 (
    type "%TASK_OUT%\build.log"
    exit /b 1
)
"%TASK_OUT%\resident_reset_check.exe" >"%TASK_OUT%\tests.log" 2>&1
set "TASK_RESULT=%ERRORLEVEL%"
type "%TASK_OUT%\tests.log"
exit /b %TASK_RESULT%
