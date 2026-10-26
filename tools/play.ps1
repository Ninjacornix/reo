# Play the native build interactively (no time limit).
#   powershell -ExecutionPolicy Bypass -File tools\play.ps1 [-Game file1|file2] [-Iso <owned ISO>] [-ToMainMenu | -ToScenario] [-GpuPresent] [-AsyncVif]
# Mounts the ISO read-only, runs build-ninja\recomp\reo_recomp.exe (File #2:
# reo_recomp_file2.exe) until you close the window, then unmounts. Saves (memory card)
# go to build-ninja\play\saves (File #2: build-ninja\play-file2\saves).
# Test routes use normal-speed startup and pad input at observed guest states.
param(
    [ValidateSet('file1', 'file2')]
    [string]$Game = 'file1',
    [string]$Iso,
    [string]$Elf,
    [switch]$ToMainMenu,
    [switch]$ToScenario,
    [switch]$GpuPresent,
    [switch]$AsyncVif
)
$ErrorActionPreference = 'Stop'
if ($ToMainMenu -and $ToScenario) { throw 'Choose either -ToMainMenu or -ToScenario.' }
if ($AsyncVif -and $env:REO_VIF1_GPU_RESIDENT -eq '1') {
    throw '-AsyncVif cannot share VU memory with REO_VIF1_GPU_RESIDENT=1.'
}
if (($ToMainMenu -or $ToScenario) -and $env:REO_PAD_SCRIPT) {
    throw 'Clear REO_PAD_SCRIPT before using a state-driven test route.'
}
$root = Split-Path -Parent $PSScriptRoot
Set-Location $root
if ($Game -eq 'file2') {
    # The test routes wait for File #1 guest states.
    if ($ToMainMenu -or $ToScenario) { throw 'Test routes are not mapped for File #2 yet.' }
    if (-not $Iso) { $Iso = 'iso\Resident Evil - Outbreak - File #2.iso' }
    if (-not $Elf) { $Elf = 'game_data_file2\SLUS_209.84' }
    $Exe = Join-Path $root 'build-ninja\recomp\reo_recomp_file2.exe'
    $playDir = Join-Path $root 'build-ninja\play-file2'
    # File #2 movies need the GPU decoder (the CPU route runs at ~4 frames/s).
    $GpuPresent = $true
} else {
    if (-not $Iso) { $Iso = 'iso\Resident Evil - Outbreak (v2.00).iso' }
    if (-not $Elf) { $Elf = 'game_data\SLUS_207.65' }
    $Exe = Join-Path $root 'build-ninja\recomp\reo_recomp.exe'
    $playDir = Join-Path $root 'build-ninja\play'
}
if (-not (Test-Path $Exe)) { Write-Error "game not built: $Exe"; exit 2 }
$Iso = (Resolve-Path $Iso).Path
$Elf = (Resolve-Path $Elf).Path
New-Item -ItemType Directory -Force $playDir | Out-Null

Dismount-DiskImage -ImagePath $Iso -ErrorAction SilentlyContinue | Out-Null
$savedEnvironment = @{}
foreach ($key in @('REO_NATURAL', 'REO_ISO', 'REO_TURBO', 'REO_TURBO_UNTIL', 'REO_TEST_ROUTE', 'REO_GS_DISPATCH_PACE', 'REO_GS_SPRITE_DEPTH_PARALLEL', 'REO_GS_GPU_PRESENT', 'REO_GS_BACKEND', 'REO_GS_THREAD', 'REO_VIF1_ASYNC')) {
    $savedEnvironment[$key] = [Environment]::GetEnvironmentVariable($key, 'Process')
}
$img = Mount-DiskImage -ImagePath $Iso -Access ReadOnly -PassThru
try {
    if ($AsyncVif) { $env:REO_VIF1_ASYNC = '1' }
    $drive = $null
    for ($i = 0; $i -lt 10 -and -not $drive; ++$i) {
        Start-Sleep -Milliseconds 300
        $drive = ($img | Get-Volume).DriveLetter
    }
    if (-not $drive) { Write-Error 'ISO mounted without a drive letter (run again)'; exit 2 }
    $discElf = "${drive}:\" + (Split-Path -Leaf $Elf)
    $runElf = if (Test-Path $discElf) { $discElf } else { $Elf }

    if ($GpuPresent) {
        $env:REO_GS_GPU_PRESENT = '1'
        $env:REO_GS_BACKEND = 'parallel'
        $env:REO_GS_THREAD = '1'
        # Movies decode on the GPU (the CPU decoder cannot keep 30 fps; the launcher has no CPU option).
        $env:REO_GPU_MOVIE = '1'
    }
    $env:REO_NATURAL = '1'
    $env:REO_ISO = $Iso
    $env:REO_TURBO = '1'
    [Environment]::SetEnvironmentVariable('REO_TURBO_UNTIL', $null, 'Process')
    # Validated scheduling fix; keep explicit caller overrides for comparisons.
    if ([string]::IsNullOrEmpty($env:REO_GS_DISPATCH_PACE)) {
        $env:REO_GS_DISPATCH_PACE = '2'
    }
    # Full-VRAM validated depth-aware sprite bands restore normal logo cadence.
    if ([string]::IsNullOrEmpty($env:REO_GS_SPRITE_DEPTH_PARALLEL)) {
        $env:REO_GS_SPRITE_DEPTH_PARALLEL = '1'
    }
    if ($ToMainMenu) { $env:REO_TEST_ROUTE = 'main-menu' }
    if ($ToScenario) { $env:REO_TEST_ROUTE = 'scenario' }
    Write-Host "Running $Exe (disc ${drive}:). Close the game window to stop."
    $proc = Start-Process -FilePath $Exe -ArgumentList @('--game', $Game, '--elf', "`"$runElf`"", '--data', "${drive}:\") `
        -WorkingDirectory $playDir -RedirectStandardError (Join-Path $playDir 'stderr.log') `
        -RedirectStandardOutput (Join-Path $playDir 'stdout.log') -PassThru
    $proc.WaitForExit()
    Write-Host "Game exited (code $($proc.ExitCode)). Logs: $playDir"
}
finally {
    foreach ($key in $savedEnvironment.Keys) {
        [Environment]::SetEnvironmentVariable($key, $savedEnvironment[$key], 'Process')
    }
    Dismount-DiskImage -ImagePath $Iso -ErrorAction SilentlyContinue | Out-Null
}
