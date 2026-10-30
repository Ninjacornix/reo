param(
    [Parameter(Mandatory=$true)][string]$OutputDirectory,
    [ValidatePattern('^[A-Za-z0-9][A-Za-z0-9_.-]*$')][string]$Configuration = 'Release'
)
$ErrorActionPreference = 'Stop'
$taskOutput = [IO.Path]::GetFullPath($OutputDirectory)
$taskSource = Join-Path $PSScriptRoot 'graphics_preview.cpp'
$taskHeader = Join-Path $PSScriptRoot 'graphics_preview.h'
foreach ($taskInput in @($taskSource, $taskHeader)) {
    if (!(Test-Path -LiteralPath $taskInput -PathType Leaf)) { throw "Missing GPU preview source: $taskInput" }
}

# These are the same existing C++ build prerequisites used by launcher/build.ps1.
# Building the preview never downloads or installs a compiler, SDK, or game data.
$taskVswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio/Installer/vswhere.exe'
if (!(Test-Path -LiteralPath $taskVswhere)) { throw 'Visual Studio C++ x64 tools and the Windows SDK are required to build the GPU preview.' }
$taskVisualStudio = & $taskVswhere -latest -products '*' -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
if ($LASTEXITCODE -or !$taskVisualStudio) { throw 'Visual Studio C++ x64 tools were not found for the GPU preview.' }
$taskVcRoot = Join-Path $taskVisualStudio 'VC/Tools/MSVC'
$taskVcVersion = Get-ChildItem -LiteralPath $taskVcRoot -Directory |
    Where-Object { $_.Name -match '^\d+\.\d+\.\d+$' } | Sort-Object { [version]$_.Name } -Descending |
    Where-Object { Test-Path -LiteralPath (Join-Path $_.FullName 'bin/Hostx64/x64/cl.exe') } | Select-Object -First 1
if (!$taskVcVersion) { throw 'The Visual Studio x64 C++ compiler is missing.' }
$taskVcBin = Join-Path $taskVcVersion.FullName 'bin/Hostx64/x64'
$taskCompiler = Join-Path $taskVcBin 'cl.exe'

$taskSdkRoot = (Get-ItemProperty -LiteralPath 'HKLM:\SOFTWARE\Microsoft\Windows Kits\Installed Roots' -ErrorAction SilentlyContinue).KitsRoot10
if (!$taskSdkRoot) { $taskSdkRoot = Join-Path ${env:ProgramFiles(x86)} 'Windows Kits/10' }
$taskSdkVersion = Get-ChildItem -LiteralPath (Join-Path $taskSdkRoot 'Include') -Directory |
    Where-Object { $_.Name -match '^\d+\.\d+\.\d+\.\d+$' } | Sort-Object { [version]$_.Name } -Descending |
    Where-Object {
        (Test-Path -LiteralPath (Join-Path $_.FullName 'um/d3d11.h')) -and
        (Test-Path -LiteralPath (Join-Path $taskSdkRoot ('Lib/' + $_.Name + '/um/x64/d3d11.lib'))) -and
        (Test-Path -LiteralPath (Join-Path $taskSdkRoot ('Lib/' + $_.Name + '/ucrt/x64/ucrt.lib')))
    } | Select-Object -First 1
if (!$taskSdkVersion) { throw 'A Windows SDK with Direct3D 11 headers and x64 libraries is required for the GPU preview.' }

New-Item -ItemType Directory -Path $taskOutput -Force | Out-Null
$taskDll = Join-Path $taskOutput 'Reo.GraphicsPreview.dll'
$taskObject = Join-Path $taskOutput 'Reo.GraphicsPreview.obj'
$taskImportLibrary = Join-Path $taskOutput 'Reo.GraphicsPreview.lib'
$taskFlags = @('/nologo','/LD','/MT','/EHsc','/std:c++17','/utf-8','/DUNICODE','/D_UNICODE')
if ($Configuration -eq 'Debug') { $taskFlags += @('/Od','/Z7') } else { $taskFlags += @('/O2','/DNDEBUG') }
$taskFlags += @(
    ('/I' + (Join-Path $taskVcVersion.FullName 'include')),
    ('/I' + (Join-Path $taskSdkVersion.FullName 'shared')),
    ('/I' + (Join-Path $taskSdkVersion.FullName 'um')),
    ('/I' + (Join-Path $taskSdkVersion.FullName 'winrt')),
    ('/I' + (Join-Path $taskSdkVersion.FullName 'ucrt')),
    $taskSource, ('/Fo' + $taskObject), '/link', '/MACHINE:X64', '/INCREMENTAL:NO', '/OPT:REF', '/OPT:ICF',
    ('/OUT:' + $taskDll), ('/IMPLIB:' + $taskImportLibrary),
    ('/LIBPATH:' + (Join-Path $taskVcVersion.FullName 'lib/x64')),
    ('/LIBPATH:' + (Join-Path $taskSdkRoot ('Lib/' + $taskSdkVersion.Name + '/um/x64'))),
    ('/LIBPATH:' + (Join-Path $taskSdkRoot ('Lib/' + $taskSdkVersion.Name + '/ucrt/x64'))),
    'd3d11.lib','dxgi.lib','d3dcompiler.lib','user32.lib'
)
$taskPreviousPath = $env:PATH
try {
    $env:PATH = $taskVcBin + ';' + (Join-Path $taskSdkRoot ('bin/' + $taskSdkVersion.Name + '/x64')) + ';' + $taskPreviousPath
    & $taskCompiler @taskFlags
    if ($LASTEXITCODE -or !(Test-Path -LiteralPath $taskDll)) { throw 'Direct3D 11 preview compilation failed.' }
} finally { $env:PATH = $taskPreviousPath }

$taskReceipt = [ordered]@{
    format = 1
    configuration = $Configuration
    architecture = 'win-x64'
    compiler = $taskCompiler
    windowsSdk = $taskSdkVersion.Name
    sourceSha256 = (Get-FileHash -LiteralPath $taskSource -Algorithm SHA256).Hash.ToLowerInvariant()
    headerSha256 = (Get-FileHash -LiteralPath $taskHeader -Algorithm SHA256).Hash.ToLowerInvariant()
    librarySha256 = (Get-FileHash -LiteralPath $taskDll -Algorithm SHA256).Hash.ToLowerInvariant()
    libraryBytes = (Get-Item -LiteralPath $taskDll).Length
}
$taskReceipt | ConvertTo-Json | Set-Content -LiteralPath (Join-Path $taskOutput 'graphics-preview-build.json') -Encoding utf8
