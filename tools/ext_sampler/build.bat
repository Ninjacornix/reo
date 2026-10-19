@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" >nul 2>&1
if not exist "%~dp0..\..\build-ninja\ext_sampler" mkdir "%~dp0..\..\build-ninja\ext_sampler"
cl /nologo /O2 /EHsc /std:c++20 "%~dp0main.cpp" /Fo"%~dp0..\..\build-ninja\ext_sampler\\" /Fe"%~dp0..\..\build-ninja\ext_sampler\ext_sampler.exe" /link dbghelp.lib
