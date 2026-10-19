# REO File #1 smoke run against a user-owned ISO (never copied or committed).
#
#   powershell -ExecutionPolicy Bypass -File tools\smoke_test.ps1 -Iso <path.iso> [-Seconds 60] [-Trace]
#       [-Env 'REO_NATURAL=1;REO_PEEK=0x209D34,0x316598'] [-Label natural]
#
# -Env sets extra environment variables for the run only (recorded in summary.txt).
# Separate entries with ';' (values may contain commas).
# Mounts the ISO read-only, runs reo_recomp with --data <drive>:\ for a fixed time,
# captures stdout/stderr under build\smoke\<timestamp>\, then kills the process and unmounts.
# Exit code: 0 = running at timeout and closed cleanly, 1 = early exit/crash/forced kill, 2 = setup error.

param(
    [Parameter(Mandatory)][string]$Iso,
    [int]$Seconds = 60,
    [string]$Elf = 'game_data\SLUS_207.65',
    [switch]$Trace,
    [string[]]$Env = @(),
    [string]$Label = '',
    [string]$ExePath = '',
    [Alias('FastBoot')][switch]$SkipIntro,
    [switch]$ToMainMenu,
    [switch]$ToScenario
)

$ErrorActionPreference = 'Stop'
if ($ToMainMenu -and $ToScenario) { throw 'Choose either -ToMainMenu or -ToScenario.' }
$Root = Split-Path -Parent $PSScriptRoot
$Exe  = @('build-ninja\recomp\reo_recomp.exe', 'build\recomp\Release\reo_recomp.exe') |
    ForEach-Object { Join-Path $Root $_ } | Where-Object { Test-Path $_ } | Select-Object -First 1
if ($ExePath) { $Exe = (Resolve-Path (Join-Path $Root $ExePath)).Path }
if (-not $Exe) { Write-Error 'reo_recomp.exe not found in build-ninja\ or build\'; exit 2 }
$Elf  = Join-Path $Root $Elf
$Iso  = (Resolve-Path $Iso).Path

foreach ($p in @($Exe, $Elf)) { if (-not (Test-Path $p)) { Write-Error "missing: $p"; exit 2 } }

$runName = (Get-Date -Format 'yyyyMMdd-HHmmss') + $(if ($Label) { "-$Label" } else { '' })
$OutDir = Join-Path (Split-Path -Parent (Split-Path -Parent $Exe)) ("smoke\" + $runName)
# @(...) keeps a single NAME=VALUE pair as a list of pairs (PowerShell unrolls a lone pair).
$envPairs = @(foreach ($kv in ($Env | ForEach-Object { $_ -split ';' } | Where-Object { $_ })) {
    $k, $v = $kv -split '=', 2
    if (-not $k -or $null -eq $v) { Write-Error "bad -Env entry '$kv' (want NAME=VALUE)"; exit 2 }
    ,@($k, $v)
})
if ($ToMainMenu -or $ToScenario) {
    if ($env:REO_PAD_SCRIPT -or @($envPairs | Where-Object { $_[0] -in @('REO_PAD_SCRIPT', 'REO_TEST_ROUTE') }).Count) {
        throw 'State-driven route switches cannot be combined with REO_PAD_SCRIPT or an explicit REO_TEST_ROUTE.'
    }
    $envPairs += ,@('REO_NATURAL', '1')
    $envPairs += ,@('REO_TEST_ROUTE', $(if ($ToScenario) { 'scenario' } else { 'main-menu' }))
}
# Normal-speed startup also overrides inherited test turbo. Legacy -SkipIntro
# remains accepted so existing callers do not fail; it no longer accelerates.
$envPairs += ,@('REO_TURBO', '1')
$envPairs += ,@('REO_TURBO_UNTIL', '')
$savedEnvironment = @{}
foreach ($key in @('REO_TRACE', 'REO_TRACE_FILE', 'REO_ISO') + @($envPairs | ForEach-Object { $_[0] })) {
    if (-not $savedEnvironment.ContainsKey($key)) {
        $savedEnvironment[$key] = [Environment]::GetEnvironmentVariable($key, 'Process')
    }
}
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
    $env:REO_ISO = $Iso  # raw sector access for the CDVD HLE (reo::CDVD)
    foreach ($p in $envPairs) { Set-Item -Path "Env:$($p[0])" -Value $p[1] }

    # Working directory = $OutDir so ./saves (memory card) stays inside the run folder.
    # Boot the ELF from the disc root when present: the HW bridge's CDVD maps the ELF's
    # directory (captured inside loadELF), so this makes it see the whole disc.
    $discElf = "${drive}:\" + (Split-Path -Leaf $Elf)
    if (Test-Path $discElf) {
        if ((Get-FileHash $discElf).Hash -ne (Get-FileHash $Elf).Hash) { Write-Error "ELF on disc differs from $Elf"; exit 2 }
        $runElf = $discElf
    } else { $runElf = $Elf }
    $runArgs = @('--game', 'file1', '--elf', "`"$runElf`"", '--data', "${drive}:\")
    $sw = [Diagnostics.Stopwatch]::StartNew()
    $proc = Start-Process -FilePath $Exe -ArgumentList $runArgs -WorkingDirectory $OutDir `
        -RedirectStandardOutput $stdout -RedirectStandardError $stderr -PassThru -WindowStyle Hidden
    $null = $proc.Handle   # cache the handle so ExitCode is populated after exit

    $exited = $proc.WaitForExit($Seconds * 1000)
    $elapsed = [math]::Round($sw.Elapsed.TotalSeconds, 1)
    if (-not $exited) {
        # Ask the window to close first so the runtime shuts down (flushes traces/logs).
        $how = 'closed'
        if (-not ($proc.CloseMainWindow() -and $proc.WaitForExit(10000))) {
            Stop-Process -Id $proc.Id -Force
            $proc.WaitForExit()
            $how = 'killed'
        }
        $result = "RUNNING at timeout (${Seconds}s), $how, exit code $($proc.ExitCode)"
        $code = if ($how -eq 'closed' -and $proc.ExitCode -eq 0) { 0 } else { 1 }
    } else {
        $result = ('EXITED after {0}s, code {1} (0x{1:X8})' -f $elapsed, $proc.ExitCode)
        $code = 1
    }
} finally {
    foreach ($key in $savedEnvironment.Keys) {
        [Environment]::SetEnvironmentVariable($key, $savedEnvironment[$key], 'Process')
    }
    Dismount-DiskImage -ImagePath $Iso | Out-Null
}

$summary = @(
    "result:  $result",
    "exe:     $Exe",
    "elf:     $Elf",
    "iso:     $Iso",
    "env:     $(@($envPairs | ForEach-Object { $_[0] + '=' + $_[1] }) -join ' ')$(if ($Trace) { ' REO_TRACE=1' })",
    "commit:  $(git -C $Root rev-parse --short HEAD) ($(git -C $Root branch --show-current))$(if (git -C $Root status --porcelain --untracked-files=no) { ' +dirty' })",
    "stdout:  $((Get-Item $stdout).Length) bytes",
    "stderr:  $((Get-Item $stderr).Length) bytes"
)
$summary | Set-Content -Encoding utf8 (Join-Path $OutDir 'summary.txt')
$summary | Write-Host
Write-Host "--- last 25 stdout lines ($OutDir)"
Get-Content $stdout -Tail 25
exit $code
