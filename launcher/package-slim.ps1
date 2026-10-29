param(
    [Parameter(Mandatory=$true)][string]$Inputs,
    [Parameter(Mandatory=$true)][string]$KitManifest,
    [Parameter(Mandatory=$true)][string]$Server,
    [Parameter(Mandatory=$true)][string]$Output,
    [string]$Version = '1.0.19',
    [string]$ReleaseTag = '',
    [string]$InputsFile2 = '',
    [string]$KitManifestFile2 = '',
    [switch]$SelfContained,
    [string]$ValidationReport = '',
    [string]$ValidationReportFile2 = ''
)
$ErrorActionPreference = 'Stop'
$repo = Split-Path -Parent $PSScriptRoot
$Inputs = (Resolve-Path -LiteralPath $Inputs).Path
$KitManifest = (Resolve-Path -LiteralPath $KitManifest).Path
if ([bool]$InputsFile2 -ne [bool]$KitManifestFile2) { throw 'Supply both File #2 inputs and its sealed manifest.' }
if ($InputsFile2) {
    $InputsFile2 = (Resolve-Path -LiteralPath $InputsFile2).Path
    $KitManifestFile2 = (Resolve-Path -LiteralPath $KitManifestFile2).Path
}
$Server = (Resolve-Path -LiteralPath $Server).Path
$Output = [IO.Path]::GetFullPath($Output)
if (Test-Path -LiteralPath $Output) { throw 'Choose a new package directory.' }
if ($Version -notmatch '^\d+\.\d+\.\d+$') { throw 'Use a numeric three-part version.' }
if (!$ReleaseTag) { $ReleaseTag = 'v' + $Version }
if ($ReleaseTag -notmatch '^v\d+\.\d+\.\d+(-[0-9A-Za-z.-]+)?$') { throw 'Invalid release tag.' }
$dirty = & git -C $repo status --porcelain --untracked-files=normal --ignore-submodules=dirty
if ($dirty) { throw 'Commit corresponding project sources before packaging.' }
$kit = Get-Content -LiteralPath $KitManifest -Raw | ConvertFrom-Json
if ($kit.format -ne 1 -or $kit.architecture -ne 'win-x64') { throw 'Unsupported input manifest.' }
if ($kit.elfSha256 -ne '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46') { throw 'The first input manifest must target File #1.' }
if ($InputsFile2) {
    $secondKit = Get-Content -LiteralPath $KitManifestFile2 -Raw | ConvertFrom-Json
    if ($secondKit.format -ne 1 -or $secondKit.architecture -ne 'win-x64' -or
        $secondKit.elfSha256 -ne '5c0411a26247ef9974cd94b844ac5aecbcbf4705db543f51814aeed89da0fd8d') {
        throw 'The second input manifest must target File #2.'
    }
}
Add-Type -AssemblyName System.IO.Compression
Add-Type -AssemblyName System.IO.Compression.FileSystem
function Assert-PayloadManifest([string]$archivePath, [string]$manifestPath) {
    $archive = [IO.Compression.ZipFile]::OpenRead($archivePath)
    try {
        $entries = @($archive.Entries | Where-Object { $_.FullName -ceq 'build-kit.json' })
        if ($entries.Count -ne 1) { throw 'Setup archive must contain exactly one root build-kit.json.' }
        $input = $entries[0].Open(); $hash = [Security.Cryptography.SHA256]::Create()
        try { $actual = ([BitConverter]::ToString($hash.ComputeHash($input))).Replace('-', '').ToLowerInvariant() }
        finally { $input.Dispose(); $hash.Dispose() }
        if ($actual -ne (Get-FileHash -LiteralPath $manifestPath -Algorithm SHA256).Hash.ToLowerInvariant()) {
            throw 'Setup archive does not contain its supplied sealed manifest.'
        }
    } finally { $archive.Dispose() }
}
Assert-PayloadManifest $Inputs $KitManifest
if ($InputsFile2) { Assert-PayloadManifest $InputsFile2 $KitManifestFile2 }
function Read-ValidationProof([string]$reportPath, [string]$manifestPath) {
    if (!$reportPath) { return $null }
    $proof = Get-Content -LiteralPath (Resolve-Path -LiteralPath $reportPath) -Raw | ConvertFrom-Json
    $expected = (Get-FileHash -LiteralPath $manifestPath -Algorithm SHA256).Hash.ToLowerInvariant()
    if ($proof.format -ne 1 -or !$proof.localBuildPassed -or !$proof.inputIntegrityVerified -or $proof.kitSha256 -ne $expected) {
        throw 'Validation must report a completed build and verified inputs bound to the exact sealed kit.'
    }
    return $proof
}
$firstValidation = Read-ValidationProof $ValidationReport $KitManifest
if ($ValidationReportFile2 -and !$InputsFile2) { throw 'File #2 validation requires its input payload.' }
$secondValidation = if ($InputsFile2) { Read-ValidationProof $ValidationReportFile2 $KitManifestFile2 } else { $null }
& (Join-Path $PSScriptRoot 'build.ps1')
if ($LASTEXITCODE) { throw 'Launcher build failed.' }
$selfContainedValue = $SelfContained.IsPresent.ToString().ToLowerInvariant()
# Both layouts publish one launcher executable. Self-contained builds also bundle the
# .NET/WPF native libraries (extracted on first start) instead of leaving ~250 loose DLLs.
$singleFileArgs = @('/p:PublishSingleFile=true')
if ($SelfContained) { $singleFileArgs += @('/p:IncludeNativeLibrariesForSelfExtract=true', '/p:EnableCompressionInSingleFile=true') }
& dotnet publish (Join-Path $PSScriptRoot 'Reo.Launcher.csproj') -c Release -r win-x64 --self-contained $selfContainedValue `
    -o $Output --nologo @singleFileArgs /p:SatelliteResourceLanguages=en `
    /p:DebugType=None /p:DebugSymbols=false ("/p:Version=" + $Version)
if ($LASTEXITCODE) { throw 'Single-file launcher publish failed.' }
$looseRuntime = @(Get-ChildItem -LiteralPath $Output -File | Where-Object {
    $_.Extension -eq '.dll' -or $_.Name -like 'Outbreak.Launcher.*.json' })
if ($looseRuntime.Count) { throw ('Single-file publish left runtime files beside the launcher: ' + ($looseRuntime.Name -join ', ')) }
Copy-Item -LiteralPath (Join-Path $PSScriptRoot 'artifacts/native/XINPUT1_4.dll') -Destination $Output
Copy-Item -LiteralPath (Join-Path $PSScriptRoot 'artifacts/native/reo-movie-check.exe') -Destination $Output
Copy-Item -LiteralPath $Inputs -Destination (Join-Path $Output 'build-inputs.zip')
if ($InputsFile2) { Copy-Item -LiteralPath $InputsFile2 -Destination (Join-Path $Output 'build-inputs-file2.zip') }
if ($SelfContained) {
    # The single-file bundle embeds runtimeconfig.json; read the copy the publish build wrote.
    $runtimeConfigPath = (& dotnet msbuild (Join-Path $PSScriptRoot 'Reo.Launcher.csproj') -nologo `
        -getProperty:ProjectRuntimeConfigFilePath /p:Configuration=Release /p:RuntimeIdentifier=win-x64 /p:SelfContained=true |
        Select-Object -Last 1).Trim()
    if ($LASTEXITCODE -or !(Test-Path -LiteralPath $runtimeConfigPath)) { throw 'Missing self-contained runtime configuration.' }
    $runtimeConfig = Get-Content -LiteralPath $runtimeConfigPath -Raw | ConvertFrom-Json
    if (!$runtimeConfig.runtimeOptions.includedFrameworks) { throw 'Runtime configuration is not self-contained.' }
    $nuget = if ($env:NUGET_PACKAGES) { $env:NUGET_PACKAGES } else { Join-Path $env:USERPROFILE '.nuget/packages' }
    $runtimeLicenses = Join-Path $Output 'LICENSES'
    New-Item -ItemType Directory -Path $runtimeLicenses -Force | Out-Null
    foreach ($framework in $runtimeConfig.runtimeOptions.includedFrameworks) {
        $package = Join-Path $nuget ($framework.name.ToLowerInvariant() + '.runtime.win-x64/' + $framework.version)
        if (!(Test-Path -LiteralPath $package)) { throw 'Missing self-contained runtime licence package.' }
        Get-ChildItem -LiteralPath $package -File | Where-Object { $_.Name -match '^(LICENSE|THIRD-PARTY-NOTICES)' } | ForEach-Object {
            Copy-Item -LiteralPath $_.FullName -Destination (Join-Path $runtimeLicenses ($framework.name + '-' + $_.Name))
        }
    }
}
$serverManifest = Join-Path $Server 'server-manifest.json'
$serverInfo = Get-Content -LiteralPath $serverManifest -Raw | ConvertFrom-Json
if ($serverInfo.format -ne 2 -or $serverInfo.runtime -ne 'external-python' -or $serverInfo.architecture -ne 'win-x64') {
    throw 'Unsupported server manifest.'
}
$serverOutput = Join-Path $Output 'network-server'
New-Item -ItemType Directory -Path $serverOutput | Out-Null
$serverPaths = [Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
foreach ($entry in $serverInfo.files) {
    $relative = [string]$entry.path
    if ($relative -match '(^/|\\|:|(^|/)\.\.?(/|$))' -or !$serverPaths.Add($relative)) {
        throw 'Invalid server package path.'
    }
    if ($relative -match '(^|/)(vendor|python|wheels|dependency-sources|__pycache__)(/|$)' -or
        [IO.Path]::GetExtension($relative) -in @('.exe','.dll','.pyd','.pyc','.whl','.db')) {
        throw 'Server package must contain source and setup documents only.'
    }
    $inputFile = [IO.Path]::GetFullPath((Join-Path $Server $relative))
    if (!$inputFile.StartsWith($Server + [IO.Path]::DirectorySeparatorChar, [StringComparison]::OrdinalIgnoreCase) -or
        (Get-FileHash -LiteralPath $inputFile -Algorithm SHA256).Hash.ToLowerInvariant() -ne $entry.sha256) {
        throw ('Server package verification failed: ' + $relative)
    }
    $destination = Join-Path $serverOutput $relative
    New-Item -ItemType Directory -Path (Split-Path -Parent $destination) -Force | Out-Null
    Copy-Item -LiteralPath $inputFile -Destination $destination
}
Copy-Item -LiteralPath $serverManifest -Destination $serverOutput
foreach ($document in @('REQUIREMENTS.md','README.md','LICENSE','NOTICE.md')) {
    Copy-Item -LiteralPath (Join-Path $repo $document) -Destination $Output -Force
}
foreach ($document in @('REQUIREMENTS.md','README.md')) {
    $path = Join-Path $Output $document
    $text = [IO.File]::ReadAllText($path).Replace('(network/server/SETUP.md)', '(network-server/README.md)')
    $text = $text.Replace('(docs/LOCAL_BUILDS.md)', "(https://github.com/Ninjacornix/reo/blob/$ReleaseTag/docs/LOCAL_BUILDS.md)")
    $text = $text.Replace('(docs/FILE2_RANDOMIZER.md)', "(https://github.com/Ninjacornix/reo/blob/$ReleaseTag/docs/FILE2_RANDOMIZER.md)")
    [IO.File]::WriteAllText($path, $text, [Text.UTF8Encoding]::new($false))
}
$revision = (& git -C $repo rev-parse HEAD).Trim()
$notices = [Text.StringBuilder]::new()
foreach ($license in Get-ChildItem -LiteralPath (Join-Path $repo 'LICENSES') -File | Sort-Object Name) {
    [void]$notices.AppendLine(('===== ' + $license.Name + ' ====='))
    [void]$notices.AppendLine([IO.File]::ReadAllText($license.FullName))
}
[void]$notices.AppendLine('===== Corresponding source downloads =====')
[void]$notices.AppendLine("https://github.com/Ninjacornix/reo/archive/refs/tags/$ReleaseTag.tar.gz")
[void]$notices.AppendLine("https://github.com/Ninjacornix/reo/releases/download/$ReleaseTag/RE-Outbreak-$ReleaseTag-Dependency-Sources.zip")
[IO.File]::WriteAllText((Join-Path $Output 'THIRD-PARTY-NOTICES.txt'), $notices.ToString(), [Text.UTF8Encoding]::new($false))
$noticePath = Join-Path $Output 'NOTICE.md'
$noticeText = [IO.File]::ReadAllText($noticePath).Replace('(LICENSES/', "(https://github.com/Ninjacornix/reo/blob/$revision/LICENSES/")
[IO.File]::WriteAllText($noticePath, $noticeText, [Text.UTF8Encoding]::new($false))
$publishLayout = if ($SelfContained) { 'self-contained-single-file' } else { 'framework-dependent-single-file' }
$referenceBuildPassed = [bool]$firstValidation -and (!$InputsFile2 -or [bool]$secondValidation)
$roomRoutesPassed = [bool]$firstValidation.roomRoutePassed -and (!$InputsFile2 -or [bool]$secondValidation.roomRoutePassed)
$distribution = @{format=2; updateFormat=2; installMode='local-build'; layout=$publishLayout;
  selfContained=[bool]$SelfContained; releaseTag=$ReleaseTag;
  version=$Version; platform='win-x64'; source='https://github.com/Ninjacornix/reo'; prerelease=$true;
  bundledServer=$false; serverSourceBundled=$true; serverRuntime='external-python';
  automaticServerSetup=$true;
  automaticCompilerSetup=$true;
  revision=(& git -C $repo rev-parse HEAD).Trim();
  kitSha256=(Get-FileHash -LiteralPath $KitManifest -Algorithm SHA256).Hash.ToLowerInvariant();
  inputsSha256=(Get-FileHash -LiteralPath $Inputs -Algorithm SHA256).Hash.ToLowerInvariant();
  validation=@{referencePortableBuildPassed=$referenceBuildPassed; currentSetupExecuted=$false; gameplayRerun=$roomRoutesPassed;
    file1BuildPassed=[bool]$firstValidation; file2BuildPassed=[bool]$secondValidation; pending=!$referenceBuildPassed}
}
if ($InputsFile2) {
    $distribution.file2KitSha256 = (Get-FileHash -LiteralPath $KitManifestFile2 -Algorithm SHA256).Hash.ToLowerInvariant()
    $distribution.file2InputsSha256 = (Get-FileHash -LiteralPath $InputsFile2 -Algorithm SHA256).Hash.ToLowerInvariant()
}
$distribution | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath (Join-Path $Output 'distribution.json') -Encoding UTF8
$files = @(Get-ChildItem -LiteralPath $Output -File -Recurse | ForEach-Object {
    if ($_.Extension -in @('.iso','.elf','.obj','.db','.ps2') -or $_.Name -in @('reo_recomp.exe','reo_recomp_file2.exe','reo_launcher_game.exe')) {
        throw 'Private game content in package.'
    }
    @{path=$_.FullName.Substring($Output.Length+1).Replace('\','/');bytes=$_.Length;
      sha256=(Get-FileHash -LiteralPath $_.FullName -Algorithm SHA256).Hash.ToLowerInvariant()}
})
$files | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath (Join-Path $Output 'package-manifest.json') -Encoding UTF8
Add-Type -AssemblyName System.IO.Compression
Add-Type -AssemblyName System.IO.Compression.FileSystem
$archiveFile = [IO.File]::Open(($Output + '.zip'), [IO.FileMode]::CreateNew)
try {
    $archive = [IO.Compression.ZipArchive]::new($archiveFile, [IO.Compression.ZipArchiveMode]::Create, $true)
    try {
        foreach ($file in Get-ChildItem -LiteralPath $Output -File -Recurse) {
            $relative = $file.FullName.Substring($Output.Length + 1).Replace('\', '/')
            if ($relative -match '(^/|\\|:|(^|/)\.\.?(/|$))') { throw 'Invalid ZIP entry path.' }
            [IO.Compression.ZipFileExtensions]::CreateEntryFromFile(
                $archive, $file.FullName, $relative, [IO.Compression.CompressionLevel]::Optimal) | Out-Null
        }
    } finally { $archive.Dispose() }
} finally { $archiveFile.Dispose() }
((Get-FileHash -LiteralPath ($Output + '.zip') -Algorithm SHA256).Hash.ToLowerInvariant() + '  ' +
    [IO.Path]::GetFileName($Output + '.zip')) | Set-Content -LiteralPath ($Output + '.zip.sha256') -Encoding ASCII
Write-Output $Output
