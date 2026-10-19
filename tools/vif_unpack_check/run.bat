@echo off
setlocal
rem Coordinator only: [rounds] [fresh output suffix] [runtime build directory]
for %%R in ("%~dp0..\..") do set "TASK_ROOT=%%~fR"
set "TASK_RT=%TASK_ROOT%\third_party\PS2Recomp\ps2xRuntime"
set "TASK_BUILD=%TASK_ROOT%\third_party\PS2Recomp\out\build"
if not "%~3"=="" set "TASK_BUILD=%~f3"
set "TASK_OUT=%TASK_ROOT%\build-ninja\m2-vif-unpack"
set "TASK_ROUNDS=%~1"
if not defined TASK_ROUNDS set "TASK_ROUNDS=11"
set "TASK_SUFFIX=%~2"
if not defined TASK_SUFFIX set "TASK_SUFFIX=validation1"
set "TASK_CAPTURE=%TASK_ROOT%\build-ninja\smoke\20261011-153637-m2-vif-vu-original-baseline"
python "%~dp0compare.py" --check-input "%TASK_CAPTURE%"
if errorlevel 1 exit /b 1
if not exist "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" exit /b 1
for /f "usebackq delims=" %%V in (`"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "TASK_VS_ROOT=%%V"
if not defined TASK_VS_ROOT exit /b 1
call "%TASK_VS_ROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
for %%V in (baseline candidate) do (
    set "TASK_VARIANT=%%V"
    call :compile
    if errorlevel 1 exit /b 1
)
for %%V in (baseline candidate) do (
    "%TASK_OUT%\vif_unpack_%%V.exe" "%TASK_OUT%\%%V-%TASK_SUFFIX%" "%TASK_ROUNDS%" "%TASK_CAPTURE%" 4 >"%TASK_OUT%\%%V-%TASK_SUFFIX%.log" 2>&1
    if errorlevel 1 (
        type "%TASK_OUT%\%%V-%TASK_SUFFIX%.log"
        exit /b 1
    )
)
python "%~dp0compare.py" "%TASK_OUT%\baseline-%TASK_SUFFIX%" "%TASK_OUT%\candidate-%TASK_SUFFIX%"
exit /b %errorlevel%

:compile
set "TASK_SOURCE=%TASK_OUT%\ps2_vif1_interpreter.cpp"
if "%TASK_VARIANT%"=="baseline" set "TASK_SOURCE=%TASK_OUT%\ps2_vif1_interpreter.baseline.cpp"
cl /nologo /MD /EHsc /O2 /std:c++20 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX ^
    /I "%TASK_RT%\include" /I "%TASK_RT%\src\lib" /I "%TASK_RT%\src\lib\Kernel" ^
    /I "%TASK_BUILD%\_deps\fmt-src\include" /I "%TASK_BUILD%\_deps\elfio-src\include" ^
    /I "%TASK_BUILD%\_deps\raylib-src\src" ^
    "%~dp0main.cpp" "%TASK_SOURCE%" ^
    /Fo"%TASK_OUT%\\" /Fe"%TASK_OUT%\vif_unpack_%TASK_VARIANT%.exe" ^
    /link "%TASK_BUILD%\ps2xRuntime\Release\ps2_runtime.lib" ^
    "%TASK_BUILD%\_deps\raylib-build\raylib\Release\raylib.lib" ^
    "%TASK_BUILD%\_deps\raylib-build\raylib\external\glfw\src\glfw.dir\Release\glfw.lib" ^
    "%TASK_BUILD%\_deps\fmt-build\Release\fmt.lib" ^
    "%TASK_BUILD%\_deps\libdwarf-build\src\lib\libdwarf\Release\dwarf.lib" ^
    opengl32.lib gdi32.lib winmm.lib user32.lib shell32.lib ole32.lib advapi32.lib ^
    >"%TASK_OUT%\build-%TASK_VARIANT%.log" 2>&1
if errorlevel 1 (type "%TASK_OUT%\build-%TASK_VARIANT%.log" & exit /b 1)
exit /b 0
