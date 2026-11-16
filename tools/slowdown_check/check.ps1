param([string]$OutputDirectory = '')
$ErrorActionPreference = 'Stop'
$repo = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../..'))
$output = if ($OutputDirectory) { [IO.Path]::GetFullPath($OutputDirectory) } else { Join-Path $repo 'build-slowdown-check' }
New-Item -ItemType Directory -Force -Path $output | Out-Null
. (Join-Path $repo 'launcher/dotnet-sdk.ps1')
$dotnet = Find-LauncherDotNet
$vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio/Installer/vswhere.exe'
$vs = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
if (!$vs) { throw 'Visual Studio x64 C++ tools are required for this developer check.' }
$vcvars = Join-Path $vs 'VC/Auxiliary/Build/vcvars64.bat'
$source = Join-Path $PSScriptRoot 'fixture.cpp'
$fixture = Join-Path $output 'fixture.exe'
$build = Join-Path $output 'build.cmd'
@"
@echo off
call "$vcvars" >nul 2>nul
if errorlevel 1 exit /b 1
cd /d "$output"
cl /nologo /std:c++17 /EHsc /O2 /MT "$source" /Fe:"$fixture"
exit /b %errorlevel%
"@ | Set-Content -LiteralPath $build
& cmd /c $build
if ($LASTEXITCODE) { throw 'Synthetic native recorder fixture build failed.' }
$previousFixture = $env:REO_SLOWDOWN_FIXTURE
try {
    $env:REO_SLOWDOWN_FIXTURE = $fixture
    & $dotnet run --project (Join-Path $repo 'launcher/cross-tests') -- --slowdown-check
    if ($LASTEXITCODE) { throw 'Slowdown checks failed.' }
} finally { $env:REO_SLOWDOWN_FIXTURE = $previousFixture }
