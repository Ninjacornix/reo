@echo off
rem Load the x64 MSVC environment from any installed Visual Studio edition
rem (Community, Professional, Enterprise or Build Tools), found with vswhere.
rem Usage from a tool script: call "%~dp0..\vcvars64.bat" || exit /b 1
if defined VCToolsInstallDir exit /b 0
set "REO_VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist "%REO_VSWHERE%" (
    echo Visual Studio locator not found: "%REO_VSWHERE%"
    exit /b 1
)
set "REO_VS_ROOT="
for /f "usebackq delims=" %%V in (`"%REO_VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "REO_VS_ROOT=%%V"
if not defined REO_VS_ROOT (
    echo Visual Studio C++ x64 tools were not found.
    exit /b 1
)
call "%REO_VS_ROOT%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
exit /b %errorlevel%
