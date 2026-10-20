param(
    [Parameter(Mandatory=$true)][string]$Inputs,
    [Parameter(Mandatory=$true)][string]$KitManifest,
    [Parameter(Mandatory=$true)][string]$Server,
    [Parameter(Mandatory=$true)][string]$Output,
    [string]$Version = '1.0.4'
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
Copy-Item -LiteralPath $Inputs -Destination (Join-Path $Output 'build-inputs.zip')
$serverManifest = Join-Path $Server 'server-manifest.json'
$serverInfo = Get-Content -LiteralPath $serverManifest -Raw | ConvertFrom-Json
if ($serverInfo.format -ne 1 -or $serverInfo.architecture -ne 'win-x64') {
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
$licenses = Join-Path $Output 'LICENSES'
New-Item -ItemType Directory -Path $licenses -Force | Out-Null
Get-ChildItem -LiteralPath (Join-Path $repo 'LICENSES') | Copy-Item -Destination $licenses -Recurse -Force
$source = Join-Path $Output 'sources'
New-Item -ItemType Directory -Path $source | Out-Null
& git -C $repo archive HEAD --format=tar ('--output=' + (Join-Path $source 'project-source.tar'))
if ($LASTEXITCODE) { throw 'Source archive failed.' }
@{format=2; updateFormat=2; installMode='local-build'; layout='framework-dependent-single-file';
  version=$Version; platform='win-x64'; source='https://github.com/Ninjacornix/reo'; prerelease=$true;
  bundledServer=$true;
  revision=(& git -C $repo rev-parse HEAD).Trim();
  kitSha256=(Get-FileHash -LiteralPath $KitManifest -Algorithm SHA256).Hash.ToLowerInvariant();
  inputsSha256=(Get-FileHash -LiteralPath $Inputs -Algorithm SHA256).Hash.ToLowerInvariant();
  validation=@{referencePortableBuildPassed=$true; currentSetupExecuted=$false; gameplayRerun=$false}
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
