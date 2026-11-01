param([switch]$Run, [string]$OutputDirectory = '')
$ErrorActionPreference='Stop'
Push-Location $PSScriptRoot
try {
    # Source builds need the SDK; the self-contained launcher needs no installed runtime.
    # Also find a user installation when an older system dotnet is first on PATH.
    $dotnetCandidates = @()
    $onPath = Get-Command dotnet -CommandType Application -ErrorAction SilentlyContinue
    if ($onPath) { $dotnetCandidates += $onPath.Source }
    foreach ($root in @($env:DOTNET_ROOT_X64, $env:DOTNET_ROOT, (Join-Path $env:USERPROFILE '.dotnet'))) {
        if ($root) { $dotnetCandidates += Join-Path $root 'dotnet.exe' }
    }
    $dotnet = $null
    foreach ($candidate in ($dotnetCandidates | Select-Object -Unique)) {
        if (!(Test-Path -LiteralPath $candidate -PathType Leaf)) { continue }
        try { $sdkVersion = & $candidate --version 2>$null } catch { continue }
        if ($LASTEXITCODE -eq 0 -and "$sdkVersion" -match '^(\d+)\.' -and [int]$Matches[1] -ge 10) {
            $dotnet = $candidate
            break
        }
    }
    if (!$dotnet) {
        throw '.NET 10 SDK or newer is required to build the launcher. Install it from https://dotnet.microsoft.com/download/dotnet/10.0 (the runtime alone is insufficient), then run StartLauncher.cmd again. User SDKs in %USERPROFILE%\.dotnet are also supported.'
    }
    Write-Host "Building with .NET SDK $sdkVersion ($dotnet)"
    $native = Join-Path $PSScriptRoot 'artifacts\native'
    New-Item -ItemType Directory -Force $native | Out-Null
    $vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
    if (!(Test-Path -LiteralPath $vswhere)) { throw 'Visual Studio C++ tools are required to build the controller adapter.' }
    $vsInstall = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
    if (!$vsInstall) { throw 'Visual Studio with the C++ x64 tools was not found.' }
    $vcvars = Join-Path $vsInstall 'VC\Auxiliary\Build\vcvars64.bat'
    if (!(Test-Path -LiteralPath $vcvars)) { throw 'Visual Studio C++ tools are required to build the controller adapter.' }
    # The movie decoder check needs only the Vulkan headers; it loads the system loader at run time.
    $vulkanInclude = if ($env:VULKAN_SDK) { Join-Path $env:VULKAN_SDK 'Include' } else { '' }
    if (!$vulkanInclude -or !(Test-Path -LiteralPath (Join-Path $vulkanInclude 'vulkan\vulkan.h'))) {
        throw 'The Vulkan SDK (VULKAN_SDK) is required to build the movie decoder check.'
    }
    $build = Join-Path $native 'build.cmd'
    @"
@echo off
call "$vcvars" >nul 2>nul
if errorlevel 1 exit /b 1
cd /d "$native"
cl /nologo /LD /O2 /MT /EHsc "$PSScriptRoot\native\xinput_bridge.cpp" /link /DEF:"$PSScriptRoot\native\xinput_bridge.def" /OUT:XINPUT1_4.dll user32.lib
if errorlevel 1 exit /b 1
cl /nologo /O2 /MT /EHsc /std:c++17 /I"$vulkanInclude" "$PSScriptRoot\native\movie_decoder_check.cpp" /Fe:reo-movie-check.exe d3d11.lib dxgi.lib ole32.lib
exit /b %errorlevel%
"@ | Set-Content -LiteralPath $build
    & cmd /c $build
    if ($LASTEXITCODE) { throw 'Controller adapter or movie decoder check build failed.' }
    $output = if ($OutputDirectory) { [IO.Path]::GetFullPath($OutputDirectory) } else { Join-Path $PSScriptRoot 'bin\Release\net10.0\win-x64' }
    & $dotnet build desktop/Reo.Launcher.Desktop.csproj -c Release -r win-x64 --self-contained true --nologo --output $output
    if ($LASTEXITCODE) { throw 'Launcher build failed.' }
    Copy-Item -LiteralPath (Join-Path $native 'XINPUT1_4.dll') -Destination $output -Force
    Copy-Item -LiteralPath (Join-Path $native 'reo-movie-check.exe') -Destination $output -Force
    if ($Run) { Start-Process -FilePath (Join-Path $output 'Outbreak.Launcher.exe') -WindowStyle Normal }
} finally { Pop-Location }
