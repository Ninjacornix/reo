param(
    [Parameter(Mandatory=$true)][string]$Inputs,
    [Parameter(Mandatory=$true)][string]$KitManifest,
    [Parameter(Mandatory=$true)][string]$Server,
    [Parameter(Mandatory=$true)][string]$Output,
    [string]$Version = '1.0.16'
)
$ErrorActionPreference = 'Stop'
$repo = Split-Path -Parent $PSScriptRoot
$Inputs = (Resolve-Path -LiteralPath $Inputs).Path
$KitManifest = (Resolve-Path -LiteralPath $KitManifest).Path
$Server = (Resolve-Path -LiteralPath $Server).Path
$Output = [IO.Path]::GetFullPath($Output)
if (Test-Path -LiteralPath $Output) { throw 'Choose a new package directory.' }
if ($Version -notmatch '^\d+\.\d+\.\d+$') { throw 'Use a numeric three-part version.' }
$dirty = & git -C $repo status --porcelain --untracked-files=normal --ignore-submodules=dirty
if ($dirty) { throw 'Commit corresponding project sources before packaging.' }
$kit = Get-Content -LiteralPath $KitManifest -Raw | ConvertFrom-Json
if ($kit.format -ne 1 -or $kit.architecture -ne 'win-x64') { throw 'Unsupported input manifest.' }
& (Join-Path $PSScriptRoot 'build.ps1')
if ($LASTEXITCODE) { throw 'Launcher build failed.' }
& dotnet publish (Join-Path $PSScriptRoot 'Reo.Launcher.csproj') -c Release -r win-x64 --self-contained false `
    -o $Output --nologo /p:PublishSingleFile=true /p:SatelliteResourceLanguages=en `
    /p:DebugType=None /p:DebugSymbols=false ("/p:Version=" + $Version)
if ($LASTEXITCODE) { throw 'Single-file launcher publish failed.' }
Copy-Item -LiteralPath (Join-Path $PSScriptRoot 'artifacts/native/XINPUT1_4.dll') -Destination $Output
Copy-Item -LiteralPath (Join-Path $PSScriptRoot 'artifacts/native/reo-movie-check.exe') -Destination $Output
Copy-Item -LiteralPath $Inputs -Destination (Join-Path $Output 'build-inputs.zip')
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
    $text = $text.Replace('(docs/LOCAL_BUILDS.md)', "(https://github.com/Ninjacornix/reo/blob/v$Version/docs/LOCAL_BUILDS.md)")
    [IO.File]::WriteAllText($path, $text, [Text.UTF8Encoding]::new($false))
}
$revision = (& git -C $repo rev-parse HEAD).Trim()
$notices = [Text.StringBuilder]::new()
foreach ($license in Get-ChildItem -LiteralPath (Join-Path $repo 'LICENSES') -File | Sort-Object Name) {
    [void]$notices.AppendLine(('===== ' + $license.Name + ' ====='))
    [void]$notices.AppendLine([IO.File]::ReadAllText($license.FullName))
}
[void]$notices.AppendLine('===== Corresponding source downloads =====')
[void]$notices.AppendLine("https://github.com/Ninjacornix/reo/archive/refs/tags/v$Version.tar.gz")
[void]$notices.AppendLine("https://github.com/Ninjacornix/reo/releases/download/v$Version/RE-Outbreak-v$Version-Dependency-Sources.zip")
[IO.File]::WriteAllText((Join-Path $Output 'THIRD-PARTY-NOTICES.txt'), $notices.ToString(), [Text.UTF8Encoding]::new($false))
$noticePath = Join-Path $Output 'NOTICE.md'
$noticeText = [IO.File]::ReadAllText($noticePath).Replace('(LICENSES/', "(https://github.com/Ninjacornix/reo/blob/$revision/LICENSES/")
[IO.File]::WriteAllText($noticePath, $noticeText, [Text.UTF8Encoding]::new($false))
@{format=2; updateFormat=2; installMode='local-build'; layout='framework-dependent-single-file';
  version=$Version; platform='win-x64'; source='https://github.com/Ninjacornix/reo'; prerelease=$true;
  bundledServer=$false; serverSourceBundled=$true; serverRuntime='external-python';
  automaticServerSetup=$true;
  automaticCompilerSetup=$true;
  revision=(& git -C $repo rev-parse HEAD).Trim();
  kitSha256=(Get-FileHash -LiteralPath $KitManifest -Algorithm SHA256).Hash.ToLowerInvariant();
  inputsSha256=(Get-FileHash -LiteralPath $Inputs -Algorithm SHA256).Hash.ToLowerInvariant();
  validation=@{referencePortableBuildPassed=$true; currentSetupExecuted=$false; gameplayRerun=$true}
} | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath (Join-Path $Output 'distribution.json') -Encoding UTF8
$files = @(Get-ChildItem -LiteralPath $Output -File -Recurse | ForEach-Object {
    if ($_.Extension -in @('.iso','.elf','.obj','.db','.ps2') -or $_.Name -in @('reo_recomp.exe','reo_launcher_game.exe')) {
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
