@echo off
setlocal
rem Coordinator only. Builds one isolated fixture; never builds/launches a game.
rem Arguments: [Release runtime build directory] [fresh output suffix].
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_RT=%TASK_ROOT%\third_party\PS2Recomp\ps2xRuntime"
set "TASK_BUILD=%TASK_ROOT%\third_party\PS2Recomp\out\build"
if not "%~1"=="" set "TASK_BUILD=%~f1"
set "TASK_SUFFIX=%~2"
if not defined TASK_SUFFIX set "TASK_SUFFIX=validation1"
set "TASK_OUT=%TASK_ROOT%\build-ninja\m2-vif-worker-prototype\%TASK_SUFFIX%"
if exist "%TASK_OUT%" (
    echo Output already exists; choose a fresh suffix.
    exit /b 2
)
if not exist "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" exit /b 2
for /f "usebackq delims=" %%V in (`"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "TASK_VS_ROOT=%%V"
if not defined TASK_VS_ROOT exit /b 2
call "%TASK_VS_ROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
if errorlevel 1 exit /b 2
mkdir "%TASK_OUT%"
python "%~dp0manifest.py" "%TASK_OUT%\source-manifest.json"
if errorlevel 1 exit /b 2
cl /nologo /MD /EHsc /O2 /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX ^
    /I "%TASK_RT%\include" /I "%TASK_RT%\src\lib\Kernel" ^
    /I "%TASK_BUILD%\_deps\fmt-src\include" ^
    /I "%TASK_BUILD%\_deps\elfio-src\include" ^
    /I "%TASK_BUILD%\_deps\raylib-src\src" ^
    "%~dp0main.cpp" /Fo"%TASK_OUT%\\" /Fe"%TASK_OUT%\vif_worker_check.exe" ^
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
"%TASK_OUT%\vif_worker_check.exe" "%TASK_OUT%\state" >"%TASK_OUT%\tests.log" 2>&1
set "TASK_RESULT=%ERRORLEVEL%"
type "%TASK_OUT%\tests.log"
if not "%TASK_RESULT%"=="0" exit /b %TASK_RESULT%
python "%~dp0compare.py" "%TASK_OUT%\state"
exit /b %ERRORLEVEL%
