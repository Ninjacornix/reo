param(
    [Parameter(Mandatory=$true)][string]$Kit,
    [Parameter(Mandatory=$true)][string]$Server,
    [Parameter(Mandatory=$true)][string]$ValidationReport,
    [Parameter(Mandatory=$true)][string]$Output,
    [string]$Version = '1.0.1',
    [switch]$Zip
)
$ErrorActionPreference = 'Stop'
$repo = Split-Path -Parent $PSScriptRoot
$Kit = (Resolve-Path -LiteralPath $Kit).Path
$Server = (Resolve-Path -LiteralPath $Server).Path
$serverManifest = Get-Content -LiteralPath (Join-Path $Server 'server-manifest.json') -Raw | ConvertFrom-Json
if ($serverManifest.format -ne 1 -or $serverManifest.architecture -ne 'win-x64') { throw 'Unsupported portable server component.' }
foreach ($file in $serverManifest.files) {
    if ([IO.Path]::IsPathRooted($file.path) -or $file.path.Contains(':') -or
        @($file.path -split '[/\\]' | Where-Object { $_ -in @('', '.', '..') }).Count) { throw 'Invalid server component path.' }
    $inputPath = [IO.Path]::GetFullPath((Join-Path $Server $file.path))
    if (!$inputPath.StartsWith($Server.TrimEnd('\') + '\', [StringComparison]::OrdinalIgnoreCase) -or
        [IO.Path]::GetExtension($inputPath) -in @('.db', '.sqlite', '.iso', '.elf', '.obj') -or
        (Get-FileHash -LiteralPath $inputPath -Algorithm SHA256).Hash.ToLowerInvariant() -ne $file.sha256) { throw 'Server component verification failed.' }
}
$Output = [IO.Path]::GetFullPath($Output)
if (Test-Path -LiteralPath $Output) { throw 'Choose a new package directory.' }
if ($Version -notmatch '^\d+\.\d+\.\d+$') { throw 'Use a numeric three-part version.' }
$dirty = & git -C $repo status --porcelain --untracked-files=normal --ignore-submodules=dirty
if ($dirty) { throw 'Commit the project sources before creating the corresponding-source archive.' }
$manifestFile = Join-Path $Kit 'build-kit.json'
$manifest = Get-Content -LiteralPath $manifestFile -Raw | ConvertFrom-Json
$proof = Get-Content -LiteralPath $ValidationReport -Raw | ConvertFrom-Json
$kitHash = (Get-FileHash -LiteralPath $manifestFile -Algorithm SHA256).Hash.ToLowerInvariant()
if ($proof.format -ne 1 -or !$proof.localBuildPassed -or !$proof.roomRoutePassed -or $proof.kitSha256 -ne $kitHash) {
    throw 'A passing first-run build and room-route report for this exact sealed kit is required.'
}
if ($manifest.format -ne 1 -or $manifest.architecture -ne 'win-x64') { throw 'Unsupported build kit.' }
if ($manifest.toolchain -eq 'msvc') {
    throw 'This development kit depends on a system compiler. Public packaging requires the portable toolchain first.'
}
if (!(Test-Path -LiteralPath (Join-Path $Kit 'notices/independent-sdk-sources.zip'))) {
    throw 'Include the exact independent dependency source/licence archive before sealing.'
}
function KitPath([string]$relative) {
    if (!$relative -or [IO.Path]::IsPathRooted($relative) -or $relative.Contains(':') -or
        @($relative -split '[/\\]' | Where-Object { $_ -in @('', '.', '..') }).Count) {
        throw 'Invalid build-kit file path.'
    }
    $path = [IO.Path]::GetFullPath((Join-Path $Kit $relative))
    if (!$path.StartsWith($Kit.TrimEnd('\') + '\', [StringComparison]::OrdinalIgnoreCase)) { throw 'Kit path escapes root.' }
    if ([IO.Path]::GetFileName($relative) -in @('reo_recomp.exe','reo_launcher_game.exe') -or
        [IO.Path]::GetExtension($relative) -in @('.iso','.elf','.bin','.obj')) { throw 'Private game content in build kit.' }
    return $path
}
foreach ($file in $manifest.files) {
    $path = KitPath $file.path
    if ((Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash.ToLowerInvariant() -ne $file.sha256) {
        throw ('Build-kit input hash mismatch: ' + $file.path)
    }
}
& (Join-Path $PSScriptRoot 'build.ps1')
if ($LASTEXITCODE) { throw 'Launcher build failed.' }
& dotnet publish (Join-Path $PSScriptRoot 'Reo.Launcher.csproj') -c Release -r win-x64 --self-contained true -o $Output --nologo /p:DebugType=None /p:DebugSymbols=false ("/p:Version=" + $Version)
if ($LASTEXITCODE) { throw 'Launcher publish failed.' }
Copy-Item -LiteralPath (Join-Path $PSScriptRoot 'artifacts/native/XINPUT1_4.dll') -Destination $Output
$targetKit = Join-Path $Output 'build-kit'
New-Item -ItemType Directory -Path $targetKit | Out-Null
foreach ($file in $manifest.files) {
    $destination = Join-Path $targetKit $file.path
    New-Item -ItemType Directory -Path (Split-Path -Parent $destination) -Force | Out-Null
    Copy-Item -LiteralPath (KitPath $file.path) -Destination $destination
}
Copy-Item -LiteralPath $manifestFile -Destination $targetKit
$serverTarget = Join-Path $Output 'network-server'
New-Item -ItemType Directory -Path $serverTarget | Out-Null
foreach ($file in $serverManifest.files) {
    $destination = Join-Path $serverTarget $file.path
    New-Item -ItemType Directory -Path (Split-Path -Parent $destination) -Force | Out-Null
    Copy-Item -LiteralPath (Join-Path $Server $file.path) -Destination $destination
}
Copy-Item -LiteralPath (Join-Path $Server 'server-manifest.json') -Destination $serverTarget
Copy-Item -LiteralPath (Join-Path $repo 'README.md') -Destination $Output
Copy-Item -LiteralPath (Join-Path $repo 'LICENSES') -Destination $Output -Recurse
$licenses = Join-Path $Output 'LICENSES'
$runtimeConfig = Get-Content -LiteralPath (Join-Path $Output 'Outbreak.Launcher.runtimeconfig.json') -Raw | ConvertFrom-Json
$nuget = if ($env:NUGET_PACKAGES) { $env:NUGET_PACKAGES } else { Join-Path $env:USERPROFILE '.nuget/packages' }
foreach ($framework in $runtimeConfig.runtimeOptions.includedFrameworks) {
    $package = Join-Path $nuget ($framework.name.ToLowerInvariant() + '.runtime.win-x64/' + $framework.version)
    if (!(Test-Path -LiteralPath $package)) { throw 'Missing self-contained runtime licence package.' }
    Get-ChildItem -LiteralPath $package -File | Where-Object { $_.Name -match '^(LICENSE|THIRD-PARTY-NOTICES)' } | ForEach-Object {
        Copy-Item -LiteralPath $_.FullName -Destination (Join-Path $licenses ($framework.name + '-' + $_.Name))
    }
}
$sourceOffer = Join-Path $Output 'sources'
New-Item -ItemType Directory -Path $sourceOffer | Out-Null
& git -C $repo archive HEAD --format=tar ('--output=' + (Join-Path $sourceOffer 'project-source.tar'))
if ($LASTEXITCODE) { throw 'Corresponding project source archive failed.' }
@{ format=2; updateFormat=2; installMode='local-build'; version=$Version; platform='win-x64';
   source='https://github.com/Ninjacornix/reo'; prerelease=$true; revision=(& git -C $repo rev-parse HEAD).Trim();
   kitSha256=$kitHash } | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath (Join-Path $Output 'distribution.json') -Encoding UTF8
'PRERELEASE: First setup generates and compiles the game from your own ISO. Compiler setup may be required. No game executable or assets are included.' |
    Set-Content -LiteralPath (Join-Path $Output 'Read me.txt') -Encoding UTF8
$files = @(Get-ChildItem -LiteralPath $Output -File -Recurse | ForEach-Object {
    @{path=$_.FullName.Substring($Output.Length+1).Replace('\','/');bytes=$_.Length;
      sha256=(Get-FileHash -LiteralPath $_.FullName -Algorithm SHA256).Hash.ToLowerInvariant()}
})
$files | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath (Join-Path $Output 'package-manifest.json') -Encoding UTF8
if ($Zip) {
    Compress-Archive -LiteralPath $Output -DestinationPath ($Output + '.zip') -CompressionLevel Optimal
    ((Get-FileHash -LiteralPath ($Output + '.zip') -Algorithm SHA256).Hash.ToLowerInvariant() + '  ' + [IO.Path]::GetFileName($Output + '.zip')) |
        Set-Content -LiteralPath ($Output + '.zip.sha256') -Encoding ASCII
}
Write-Output $Output
