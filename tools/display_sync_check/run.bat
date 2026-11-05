@echo off
setlocal
set "REO_ROOT=%~dp0..\.."
set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
for /f "usebackq tokens=*" %%i in (`"%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "REO_VS=%%i"
if not defined REO_VS exit /b 1
if not exist "%VULKAN_SDK%\include\vulkan\vulkan.h" exit /b 1
call "%REO_VS%\VC\Auxiliary\Build\vcvars64.bat" >nul
if errorlevel 1 exit /b 1
if not exist "%REO_ROOT%\build-ninja\display-sync-check" mkdir "%REO_ROOT%\build-ninja\display-sync-check"
pushd "%REO_ROOT%\build-ninja\display-sync-check"
cl /nologo /std:c++17 /EHsc /W4 /D_CRT_SECURE_NO_WARNINGS /I"%REO_ROOT%" /I"%VULKAN_SDK%\include" "%REO_ROOT%\tools\parallel_gs_backend\display_sync_check.cpp" /Fe:display_sync_check.exe
if errorlevel 1 (popd & exit /b 1)
display_sync_check.exe
set "REO_RESULT=%errorlevel%"
popd
exit /b %REO_RESULT%
