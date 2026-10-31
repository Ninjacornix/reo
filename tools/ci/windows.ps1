param(
    [Parameter(Mandatory=$true)][string]$VulkanHeaders,
    [Parameter(Mandatory=$true)][string]$Output,
    [ValidatePattern('^[0-9a-fA-F]{40}$')][string]$Commit = (& git rev-parse HEAD)
)
$ErrorActionPreference = 'Stop'
$repo = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../..'))
$Output = [IO.Path]::GetFullPath($Output)
$VulkanHeaders = (Resolve-Path -LiteralPath $VulkanHeaders).Path
if (!(Test-Path -LiteralPath (Join-Path $VulkanHeaders 'include/vulkan/vulkan.h'))) {
    throw 'Use the pinned Vulkan-Headers checkout, containing include/vulkan/vulkan.h.'
}
if (Test-Path -LiteralPath $Output) { throw 'Choose a new CI output directory.' }
New-Item -ItemType Directory -Path $Output | Out-Null
$reports = Join-Path $Output 'reports'
$publish = Join-Path $Output 'publish'
$build = Join-Path $Output 'build'
New-Item -ItemType Directory -Path $reports | Out-Null
$priorSdk = $env:VULKAN_SDK
$priorPythonUtf8 = $env:PYTHONUTF8

function Invoke-Recorded([string]$Name, [scriptblock]$Command) {
    & $Command *>&1 | Tee-Object -FilePath (Join-Path $reports ($Name + '.log'))
    if ($LASTEXITCODE -ne 0) { throw "$Name failed with exit $LASTEXITCODE." }
}
function Test-Launcher([string]$Folder, [string]$Name) {
    $testHome = Join-Path $Output ($Name + '-home')
    $start = [Diagnostics.ProcessStartInfo]::new()
    $start.FileName = Join-Path $Folder 'Outbreak.Launcher.exe'
    $start.Arguments = '--data-home "' + $testHome + '" --self-test'
    $start.UseShellExecute = $false
    $start.CreateNoWindow = $true
    $start.WindowStyle = [Diagnostics.ProcessWindowStyle]::Hidden
    $start.RedirectStandardOutput = $true
    $start.RedirectStandardError = $true
    $process = [Diagnostics.Process]::Start($start)
    $stdout = $process.StandardOutput.ReadToEndAsync()
    $stderr = $process.StandardError.ReadToEndAsync()
    try {
        $clock = [Diagnostics.Stopwatch]::StartNew()
        while (!$process.WaitForExit(1000)) {
            if ($clock.Elapsed.TotalSeconds -gt 180) { $process.Kill(); throw "$Name timed out." }
        }
        [IO.File]::WriteAllText((Join-Path $reports ($Name + '-stdout.log')), $stdout.GetAwaiter().GetResult())
        [IO.File]::WriteAllText((Join-Path $reports ($Name + '-stderr.log')), $stderr.GetAwaiter().GetResult())
        if ($process.ExitCode -ne 0) {
            $errorLog = Join-Path $Folder 'launcher-error.log'
            if (Test-Path -LiteralPath $errorLog) {
                Copy-Item -LiteralPath $errorLog -Destination (Join-Path $reports ($Name + '-error.log'))
                Get-Content -LiteralPath $errorLog | Write-Output
            }
            throw "$Name failed with exit $($process.ExitCode)."
        }
        $receipt = Join-Path $Folder 'test-results/self-test.json'
        $result = Get-Content -LiteralPath $receipt -Raw | ConvertFrom-Json
        if (!$result.passed -or $result.checks -lt 1) { throw "$Name did not produce passing self-checks." }
        Copy-Item -LiteralPath $receipt -Destination (Join-Path $reports ($Name + '.json'))
        Write-Output "$Name passed $($result.checks) checks."
    } finally { $process.Dispose() }
}

Push-Location $repo
try {
    # The checker uses Vulkan headers only; neither the loader nor a GPU is
    # required to compile it. Windows directory names are case insensitive.
    $env:VULKAN_SDK = $VulkanHeaders
    $env:PYTHONUTF8 = '1'
    Invoke-Recorded 'launcher-build' { & (Join-Path $repo 'launcher/build.ps1') -OutputDirectory $build }
    Test-Launcher $build 'launcher-self-test'
    Invoke-Recorded 'audio-bridge' { & (Join-Path $repo 'tools/audio_mixer_check/run-bridge.bat') }
    Invoke-Recorded 'native-cheats' { & (Join-Path $repo 'tools/cheat_check/run.bat') }
    Invoke-Recorded 'file2-unlocks' { & (Join-Path $repo 'tools/cheat_check/run-file2-unlocks.bat') }
    Invoke-Recorded 'launcher-publish' {
        & dotnet publish launcher/Reo.Launcher.csproj -c Release -r win-x64 --self-contained true `
            -o $publish --nologo /p:DebugType=None /p:DebugSymbols=false
    }
    foreach ($native in @('XINPUT1_4.dll', 'reo-movie-check.exe')) {
        Copy-Item -LiteralPath (Join-Path $build $native) -Destination $publish
    }
    foreach ($native in @('XINPUT1_4.dll', 'reo-movie-check.exe', 'Reo.GraphicsPreview.dll')) {
        $file = Join-Path $publish $native
        if (!(Test-Path -LiteralPath $file) -or (Get-Item -LiteralPath $file).Length -lt 1024) {
            throw "The published launcher is missing $native."
        }
    }
    $licenses = Join-Path $publish 'LICENSES'
    New-Item -ItemType Directory -Path $licenses -Force | Out-Null
    Get-ChildItem -LiteralPath (Join-Path $repo 'LICENSES') | Copy-Item -Destination $licenses -Recurse
    $runtime = Get-Content -LiteralPath (Join-Path $publish 'Outbreak.Launcher.runtimeconfig.json') -Raw | ConvertFrom-Json
    $nuget = if ($env:NUGET_PACKAGES) { $env:NUGET_PACKAGES } else { Join-Path $env:USERPROFILE '.nuget/packages' }
    foreach ($framework in $runtime.runtimeOptions.includedFrameworks) {
        $package = Join-Path $nuget ($framework.name.ToLowerInvariant() + '.runtime.win-x64/' + $framework.version)
        if (!(Test-Path -LiteralPath $package)) { throw 'The published runtime licence package is missing.' }
        Get-ChildItem -LiteralPath $package -File | Where-Object { $_.Name -match '^(LICENSE|THIRD-PARTY-NOTICES)' } | ForEach-Object {
            Copy-Item -LiteralPath $_.FullName -Destination (Join-Path $licenses ($framework.name + '-' + $_.Name))
        }
    }
    @{ format=2; version='1.0.20'; releaseTag=('ci-' + $Commit.Substring(0,12)); platform='win-x64';
       prerelease=$true; kind='launcher-preview'; revision=$Commit; containsGameBuildKits=$false } |
        ConvertTo-Json | Set-Content -LiteralPath (Join-Path $publish 'distribution.json') -Encoding UTF8
    & git archive HEAD --format=zip ('--output=' + (Join-Path $publish 'project-source.zip'))
    if ($LASTEXITCODE -ne 0) { throw 'The corresponding project source archive failed.' }
    @'
CI LAUNCHER PREVIEW - not a playable release package.

Extract the complete ZIP and open Outbreak.Launcher.exe. The .NET runtime and
native launcher helpers are included. Game build kits, game executables, ISOs,
extracted models, fonts, textures, videos and personal data are not included.
Use a complete official release for game installation. This preview checks
launcher compilation and asset-free behavior; it does not certify gameplay.
'@ | Set-Content -LiteralPath (Join-Path $publish 'Read me.txt') -Encoding UTF8
    Test-Launcher $publish 'published-self-test'
    $previewFiles = @(Get-ChildItem -LiteralPath $publish | Where-Object Name -Ne 'test-results' | Select-Object -ExpandProperty FullName)
    Compress-Archive -LiteralPath $previewFiles -DestinationPath (Join-Path $Output 'reo-launcher-preview-win-x64.zip')
    @{ passed=$true; commit=$Commit; gameDataUsed=$false; gameplayRun=$false;
       nativeComponents=@('XINPUT1_4.dll','reo-movie-check.exe','Reo.GraphicsPreview.dll') } |
        ConvertTo-Json | Set-Content -LiteralPath (Join-Path $reports 'windows-ci.json') -Encoding UTF8
} finally {
    $env:VULKAN_SDK = $priorSdk
    $env:PYTHONUTF8 = $priorPythonUtf8
    Pop-Location
}
