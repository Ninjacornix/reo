# REO File #1 smoke run against a user-owned ISO (never copied or committed).
#
#   powershell -ExecutionPolicy Bypass -File tools\smoke_test.ps1 -Iso <path.iso> [-Seconds 60] [-Trace]
#
# Mounts the ISO read-only, runs reo_recomp with --data <drive>:\ for a fixed time,
# captures stdout/stderr under build\smoke\<timestamp>\, then kills the process and unmounts.
# Exit code: 0 = still running at timeout (no crash), 1 = exited/crashed early, 2 = setup error.

param(
    [Parameter(Mandatory)][string]$Iso,
    [int]$Seconds = 60,
    [string]$Elf = 'game_data\SLUS_207.65',
    [switch]$Trace
)

$ErrorActionPreference = 'Stop'
$Root = Split-Path -Parent $PSScriptRoot
$Exe  = @('build-ninja\recomp\reo_recomp.exe', 'build\recomp\Release\reo_recomp.exe') |
    ForEach-Object { Join-Path $Root $_ } | Where-Object { Test-Path $_ } | Select-Object -First 1
if (-not $Exe) { Write-Error 'reo_recomp.exe not found in build-ninja\ or build\'; exit 2 }
$Elf  = Join-Path $Root $Elf
$Iso  = (Resolve-Path $Iso).Path

foreach ($p in @($Exe, $Elf)) { if (-not (Test-Path $p)) { Write-Error "missing: $p"; exit 2 } }

$OutDir = Join-Path (Split-Path -Parent (Split-Path -Parent $Exe)) ("smoke\" + (Get-Date -Format 'yyyyMMdd-HHmmss'))
New-Item -ItemType Directory -Force $OutDir | Out-Null
$stdout = Join-Path $OutDir 'stdout.log'
$stderr = Join-Path $OutDir 'stderr.log'

$img = Mount-DiskImage -ImagePath $Iso -Access ReadOnly -PassThru
try {
    $drive = ($img | Get-Volume).DriveLetter
    if (-not $drive) { Write-Error 'ISO mounted without a drive letter'; exit 2 }

    if ($Trace) {
        $env:REO_TRACE = '1'
        $env:REO_TRACE_FILE = Join-Path $OutDir 'trace.bin'
    }

    # Working directory = $OutDir so ./saves (memory card) stays inside the run folder.
    $runArgs = @('--game', 'file1', '--elf', "`"$Elf`"", '--data', "${drive}:\")
    $sw = [Diagnostics.Stopwatch]::StartNew()
    $proc = Start-Process -FilePath $Exe -ArgumentList $runArgs -WorkingDirectory $OutDir `
        -RedirectStandardOutput $stdout -RedirectStandardError $stderr -PassThru -WindowStyle Normal
    $null = $proc.Handle   # cache the handle so ExitCode is populated after exit

    $exited = $proc.WaitForExit($Seconds * 1000)
    $elapsed = [math]::Round($sw.Elapsed.TotalSeconds, 1)
    if (-not $exited) {
        Stop-Process -Id $proc.Id -Force
        $proc.WaitForExit()
        $result = "RUNNING at timeout (${Seconds}s), killed"
        $code = 0
    } else {
        $result = ('EXITED after {0}s, code {1} (0x{1:X8})' -f $elapsed, $proc.ExitCode)
        $code = 1
    }
} finally {
    Remove-Item Env:REO_TRACE, Env:REO_TRACE_FILE -ErrorAction SilentlyContinue
    Dismount-DiskImage -ImagePath $Iso | Out-Null
}

$summary = @(
    "result:  $result",
    "exe:     $Exe",
    "elf:     $Elf",
    "iso:     $Iso",
    "stdout:  $((Get-Item $stdout).Length) bytes",
    "stderr:  $((Get-Item $stderr).Length) bytes"
)
$summary | Set-Content -Encoding utf8 (Join-Path $OutDir 'summary.txt')
$summary | Write-Host
Write-Host "--- last 25 stdout lines ($OutDir)"
Get-Content $stdout -Tail 25
exit $code
