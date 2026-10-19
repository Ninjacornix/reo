@echo off
setlocal
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul
if errorlevel 1 exit /b 1
cd /d "%~dp0\..\.."
if not exist build-ninja\ee-count-check mkdir build-ninja\ee-count-check
cl /nologo /std:c++20 /EHsc /W4 /O2 tools\ee_count_check\main.cpp /Fo:build-ninja\ee-count-check\main.obj /Fe:build-ninja\ee-count-check\check.exe >build-ninja\ee-count-check\build.log 2>&1
if errorlevel 1 (
  type build-ninja\ee-count-check\build.log
  exit /b 1
)
build-ninja\ee-count-check\check.exe >build-ninja\ee-count-check\tests.log 2>&1
set "TASK_RESULT=%ERRORLEVEL%"
type build-ninja\ee-count-check\tests.log
exit /b %TASK_RESULT%
