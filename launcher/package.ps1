param(
    [string]$NativeExe = '',
    [string]$Version = '1.0.0',
    [string]$Output = '',
    [switch]$SkipBuild,
    [switch]$Prerelease,
    [switch]$Zip
)
$ErrorActionPreference = 'Stop'
throw 'Publishing precompiled game executables is disabled. Use the local-build-kit packaging path after its source and toolchain audit. Legacy packages remain local only.'

if ($Version -notmatch '^v?\d+\.\d+(\.\d+)?$') { throw 'Use a stable release version, for example 0.2.0.' }
$Version = $Version.TrimStart('v')
$repo = Split-Path -Parent $PSScriptRoot
if (!$NativeExe) { $NativeExe = Join-Path $repo 'build-ninja/recomp/reo_recomp.exe' }
$NativeExe = (Resolve-Path -LiteralPath $NativeExe).Path
if (!$Output) { $Output = Join-Path $repo ('dist/RE-Outbreak-win-x64-' + (Get-Date -Format 'yyyyMMdd-HHmmss')) }
$Output = [IO.Path]::GetFullPath($Output)
if (Test-Path -LiteralPath $Output) { throw 'Choose a new output directory; existing packages are never overwritten.' }
if (!$SkipBuild) { & (Join-Path $PSScriptRoot 'build.ps1'); if ($LASTEXITCODE) { throw 'Launcher build failed.' } }
$adapter = Join-Path $PSScriptRoot 'artifacts/native/XINPUT1_4.dll'
if (!(Test-Path -LiteralPath $adapter)) { throw 'Build the launcher input adapter first.' }
$shaders = Join-Path (Split-Path -Parent $NativeExe) 'reo-gpu-present'
$modules = @('present_opaque.vert.spv','present_native.frag.spv','present_smaa_edge.frag.spv','present_smaa_weights.frag.spv','present_smaa_blend.frag.spv')
foreach ($module in $modules) { if (!(Test-Path -LiteralPath (Join-Path $shaders $module))) { throw "Missing presentation shader: $module" } }
& dotnet publish (Join-Path $PSScriptRoot 'Reo.Launcher.csproj') -c Release -r win-x64 --self-contained true -o $Output --nologo /p:DebugType=None /p:DebugSymbols=false
if ($LASTEXITCODE) { throw 'Self-contained launcher publish failed.' }
Copy-Item -LiteralPath $adapter -Destination (Join-Path $Output 'XINPUT1_4.dll')
$game = Join-Path $Output 'games/file1'
New-Item -ItemType Directory -Path (Join-Path $game 'reo-gpu-present') -Force | Out-Null
Copy-Item -LiteralPath $NativeExe -Destination (Join-Path $game 'reo_recomp.exe')
$sdk = Join-Path ${env:ProgramFiles(x86)} 'Windows Kits/10/bin'
$mt = Get-ChildItem -LiteralPath $sdk -Directory | Sort-Object Name -Descending |
    ForEach-Object { Join-Path $_.FullName 'x64/mt.exe' } | Where-Object { Test-Path -LiteralPath $_ } | Select-Object -First 1
if (!$mt) { throw 'Windows SDK manifest tool was not found.' }
& $mt -nologo -manifest (Join-Path $PSScriptRoot 'native.manifest') ('-outputresource:' + (Join-Path $game 'reo_recomp.exe') + ';#1')
if ($LASTEXITCODE) { throw 'Native UTF-8 path manifest could not be embedded.' }
foreach ($module in $modules) { Copy-Item -LiteralPath (Join-Path $shaders $module) -Destination (Join-Path $game 'reo-gpu-present') }
# App-local redistributable CRT; the player's PC does not need a compiler.
$vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio/Installer/vswhere.exe'
$vs = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
$crt = Get-ChildItem -LiteralPath (Join-Path $vs 'VC/Redist/MSVC') -Directory | Sort-Object Name -Descending |
    ForEach-Object { Join-Path $_.FullName 'x64/Microsoft.VC143.CRT' } | Where-Object { Test-Path -LiteralPath $_ } | Select-Object -First 1
if (!$crt) { throw 'The Visual C++ redistributable DLL directory was not found.' }
foreach ($dll in @('msvcp140.dll','msvcp140_atomic_wait.dll','vcruntime140.dll','vcruntime140_1.dll')) {
    Copy-Item -LiteralPath (Join-Path $crt $dll) -Destination $Output
    Copy-Item -LiteralPath (Join-Path $crt $dll) -Destination $game
}
Copy-Item -LiteralPath (Join-Path $repo 'LICENSES') -Destination $Output -Recurse -Force
$licenses = Join-Path $Output 'LICENSES'
$licenseSources = @(
    @('PS2Recomp', (Join-Path $repo 'third_party/PS2Recomp')),
    @('raylib', (Join-Path $repo 'third_party/PS2Recomp/out/build/_deps/raylib-src')),
    @('fmt', (Join-Path $repo 'third_party/PS2Recomp/out/build/_deps/fmt-src')),
    @('ELFIO', (Join-Path $repo 'third_party/PS2Recomp/out/build/_deps/elfio-src')),
    @('libdwarf', (Join-Path $repo 'third_party/PS2Recomp/out/build/_deps/libdwarf-src')),
    @('GLFW', (Join-Path $repo 'third_party/PS2Recomp/out/build/_deps/raylib-src/src/external/glfw')),
    @('Granite', (Join-Path $repo 'build-ninja/parallel-gs-source/Granite'))
)
$graniteThirdParty = Join-Path $repo 'build-ninja/parallel-gs-source/Granite/third_party'
if (Test-Path -LiteralPath $graniteThirdParty) {
    foreach ($folder in (Get-ChildItem -LiteralPath $graniteThirdParty -Directory)) {
        $licenseSources += ,@(('Granite-' + $folder.Name), $folder.FullName)
    }
}
# Use the versions actually published, rather than a different installed .NET SDK.
$runtimeConfig = Get-Content -LiteralPath (Join-Path $Output 'Outbreak.Launcher.runtimeconfig.json') -Raw | ConvertFrom-Json
foreach ($framework in $runtimeConfig.runtimeOptions.includedFrameworks) {
    $packageId = $framework.name.ToLowerInvariant() + '.runtime.win-x64'
    $nugetRoot = if ($env:NUGET_PACKAGES) { $env:NUGET_PACKAGES } else { Join-Path $env:USERPROFILE '.nuget/packages' }
    $packageFolder = Join-Path $nugetRoot ($packageId + '/' + $framework.version)
    if (!(Test-Path -LiteralPath $packageFolder)) { throw "Missing runtime license package: $packageId $($framework.version)" }
    $licenseSources += ,@($framework.name, $packageFolder)
}
foreach ($pair in $licenseSources) {
    if (Test-Path -LiteralPath $pair[1]) {
        Get-ChildItem -LiteralPath $pair[1] -File | Where-Object { $_.Name -match '^(LICENSE|COPYING|NOTICE|THIRD-PARTY-NOTICES)' } | ForEach-Object {
            Copy-Item -LiteralPath $_.FullName -Destination (Join-Path $licenses ($pair[0] + '-' + $_.Name)) -Force
        }
    }
}
$parallelLicense = Join-Path $repo 'build-ninja/parallel-gs-source/COPYING.LGPLv3'
if (Test-Path -LiteralPath $parallelLicense) { Copy-Item -LiteralPath $parallelLicense -Destination (Join-Path $licenses 'parallel-gs-LGPLv3.txt') }
$revision = (& git -C $repo rev-parse HEAD).Trim()
$dirty = [bool](& git -C $repo status --porcelain)
@{format=1;updateFormat=1;version=$Version;platform='win-x64';source='https://github.com/Ninjacornix/reo';revision=$revision;development=$dirty;prerelease=[bool]$Prerelease;
    games=@(@{id='file1';executable='games/file1/reo_recomp.exe';elf='SLUS_207.65';elfSha256='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';nativeSha256=(Get-FileHash -LiteralPath (Join-Path $game 'reo_recomp.exe') -Algorithm SHA256).Hash.ToLowerInvariant()})} |
    ConvertTo-Json -Depth 6 | Set-Content -LiteralPath (Join-Path $Output 'distribution.json') -Encoding UTF8
@'
RE: Outbreak - Windows x64

Open Outbreak.Launcher.exe, choose Game files, and select your own ISO.
File #1 supports the NTSC-U v2.00 disc (SLUS-20765).
The launcher imports the files once. Keep the ISO: sector reads use it directly.
No mounting, compiler, SDK, BIOS download, or .NET installation is required.
A Vulkan-capable GPU and its current graphics driver are required.
Settings, imports, memory cards and logs are stored in your Local AppData folder.
File #2 gameplay is not included in this package.

Project/source: https://github.com/Ninjacornix/reo
See LICENSE, NOTICE.md, LICENSES and the included .NET third-party notices.
Online setup and known limits are in README.md.
'@ | Set-Content -LiteralPath (Join-Path $Output 'Read me.txt') -Encoding UTF8
Copy-Item -LiteralPath (Join-Path $repo 'README.md') -Destination (Join-Path $Output 'README.md')
if ($Prerelease) { 'PRERELEASE: Graphics, performance, audio and online play remain experimental.' | Set-Content -LiteralPath (Join-Path $Output 'PRERELEASE.txt') -Encoding UTF8 }
$files = @(Get-ChildItem -LiteralPath $Output -File -Recurse | ForEach-Object {
    @{path=$_.FullName.Substring($Output.Length+1).Replace('\','/');bytes=$_.Length;sha256=(Get-FileHash -LiteralPath $_.FullName -Algorithm SHA256).Hash.ToLowerInvariant()}
})
$files | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath (Join-Path $Output 'package-manifest.json') -Encoding UTF8
if ($Zip) {
    Compress-Archive -LiteralPath $Output -DestinationPath ($Output + '.zip') -CompressionLevel Optimal
    $hash = (Get-FileHash -LiteralPath ($Output + '.zip') -Algorithm SHA256).Hash.ToLowerInvariant()
    ($hash + '  ' + [IO.Path]::GetFileName($Output + '.zip')) | Set-Content -LiteralPath ($Output + '.zip.sha256') -Encoding ASCII
}
Write-Output $Output
