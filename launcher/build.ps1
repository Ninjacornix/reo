param([switch]$Run)
$ErrorActionPreference='Stop'
Push-Location $PSScriptRoot
try {
    $native = Join-Path $PSScriptRoot 'artifacts\native'
    New-Item -ItemType Directory -Force $native | Out-Null
    $vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
    if (!(Test-Path -LiteralPath $vswhere)) { throw 'Visual Studio C++ tools are required to build the controller adapter.' }
    $vsInstall = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
    if (!$vsInstall) { throw 'Visual Studio with the C++ x64 tools was not found.' }
    $vcvars = Join-Path $vsInstall 'VC\Auxiliary\Build\vcvars64.bat'
    if (!(Test-Path -LiteralPath $vcvars)) { throw 'Visual Studio C++ tools are required to build the controller adapter.' }
    $build = Join-Path $native 'build.cmd'
    @"
@echo off
call "$vcvars" >nul 2>nul
if errorlevel 1 exit /b 1
cd /d "$native"
cl /nologo /LD /O2 /MT /EHsc "$PSScriptRoot\native\xinput_bridge.cpp" /link /DEF:"$PSScriptRoot\native\xinput_bridge.def" /OUT:XINPUT1_4.dll user32.lib
exit /b %errorlevel%
"@ | Set-Content -LiteralPath $build
    & cmd /c $build
    if ($LASTEXITCODE) { throw 'Controller adapter build failed.' }
    $shaderOutput = Join-Path $PSScriptRoot 'artifacts\shaders'
    New-Item -ItemType Directory -Force $shaderOutput | Out-Null
    $sdkBin = Join-Path ${env:ProgramFiles(x86)} 'Windows Kits\10\bin'
    $fxc = Get-ChildItem -LiteralPath $sdkBin -Directory | Sort-Object Name -Descending |
        ForEach-Object { Join-Path $_.FullName 'x64\fxc.exe' } | Where-Object { Test-Path -LiteralPath $_ } | Select-Object -First 1
    if (!$fxc) { throw 'Windows SDK shader compiler (fxc.exe) is required for the image preview.' }
    & $fxc /nologo /T ps_2_0 /E main /Fo (Join-Path $shaderOutput 'ColorPreview.ps') (Join-Path $PSScriptRoot 'Shaders\ColorPreview.hlsl')
    if ($LASTEXITCODE) { throw 'Image preview shader build failed.' }
    & dotnet build Reo.Launcher.csproj -c Release --nologo
    if ($LASTEXITCODE) { throw 'Launcher build failed.' }
    $output = Join-Path $PSScriptRoot 'bin\Release\net8.0-windows'
    Copy-Item -LiteralPath (Join-Path $native 'XINPUT1_4.dll') -Destination $output -Force
    if ($Run) { Start-Process -FilePath (Join-Path $output 'Outbreak.Launcher.exe') -WindowStyle Normal }
} finally { Pop-Location }
