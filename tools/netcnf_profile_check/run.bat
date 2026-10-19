@echo off
setlocal
cd /d "%~dp0\..\.."
if not exist "build-ninja\netcnf-profile-check" mkdir "build-ninja\netcnf-profile-check"
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" >nul
if errorlevel 1 exit /b 1
cl /nologo /std:c++17 /EHsc /W4 tools\netcnf_profile_check\main.cpp network\native\netcnf_profile.cpp /Fe:build-ninja\netcnf-profile-check\netcnf_profile_check.exe /Fo:build-ninja\netcnf-profile-check\
if errorlevel 1 exit /b 1
build-ninja\netcnf-profile-check\netcnf_profile_check.exe
