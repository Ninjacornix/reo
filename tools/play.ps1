# Play the native build interactively (no time limit).
#   powershell -ExecutionPolicy Bypass -File tools\play.ps1 [-Iso <owned ISO>] [-SkipIntro]
# Mounts the ISO read-only, runs build-ninja\recomp\reo_recomp.exe until you close the
# window, then unmounts. Saves (memory card) go to build-ninja\play\saves.
# -SkipIntro fast-forwards the boot logos (test-only REO_TURBO) until the title movie.
param(
    [string]$Iso = 'iso\Resident Evil - Outbreak (v2.00).iso',
    [string]$Elf = 'game_data\SLUS_207.65',
    [switch]$SkipIntro
)
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
Set-Location $root
$Exe = Join-Path $root 'build-ninja\recomp\reo_recomp.exe'
if (-not (Test-Path $Exe)) { Write-Error "game not built: $Exe"; exit 2 }
$Iso = (Resolve-Path $Iso).Path
$Elf = (Resolve-Path $Elf).Path
$playDir = Join-Path $root 'build-ninja\play'
New-Item -ItemType Directory -Force $playDir | Out-Null

Dismount-DiskImage -ImagePath $Iso -ErrorAction SilentlyContinue | Out-Null
$img = Mount-DiskImage -ImagePath $Iso -Access ReadOnly -PassThru
try {
    $drive = $null
    for ($i = 0; $i -lt 10 -and -not $drive; ++$i) {
        Start-Sleep -Milliseconds 300
        $drive = ($img | Get-Volume).DriveLetter
    }
    if (-not $drive) { Write-Error 'ISO mounted without a drive letter (run again)'; exit 2 }
    $discElf = "${drive}:\" + (Split-Path -Leaf $Elf)
    $runElf = if (Test-Path $discElf) { $discElf } else { $Elf }

    $env:REO_NATURAL = '1'
    $env:REO_ISO = $Iso
    if ($SkipIntro) { $env:REO_TURBO = '8'; $env:REO_TURBO_UNTIL = '0x22F18C' }
    Write-Host "Running $Exe (disc ${drive}:). Close the game window to stop."
    $proc = Start-Process -FilePath $Exe -ArgumentList @('--game', 'file1', '--elf', "`"$runElf`"", '--data', "${drive}:\") `
        -WorkingDirectory $playDir -RedirectStandardError (Join-Path $playDir 'stderr.log') `
        -RedirectStandardOutput (Join-Path $playDir 'stdout.log') -PassThru
    $proc.WaitForExit()
    Write-Host "Game exited (code $($proc.ExitCode)). Logs: $playDir"
}
finally {
    Remove-Item Env:REO_NATURAL, Env:REO_ISO, Env:REO_TURBO, Env:REO_TURBO_UNTIL -ErrorAction SilentlyContinue
    Dismount-DiskImage -ImagePath $Iso -ErrorAction SilentlyContinue | Out-Null
}
