# Fetch and build the pinned PS2Recomp revision, then configure REO.
# See docs/BASELINE.md for why each pin/workaround exists.
#
#   powershell -ExecutionPolicy Bypass -File tools\setup_deps.ps1 [-Build] [-Jobs 6]
#
# -Build also builds reo_recomp with Ninja into build-ninja\ (~45 min at -j 6 on a
# Ryzen 5 2600 / 16 GB). Re-running resumes; interrupted builds keep finished objects.

param([switch]$Build, [int]$Jobs = 6)

$ErrorActionPreference = 'Stop'
$Root = Split-Path -Parent $PSScriptRoot

$PS2RECOMP_REPO = 'https://github.com/sp00nznet/PS2Recomp.git'
$PS2RECOMP_PIN  = 'c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f'   # gitlink in third_party/PS2Recomp
$ELFIO_REPO     = 'https://github.com/serge1/ELFIO.git'
$ELFIO_PIN      = '7d30a22fc5aac06adfe7887ae57f3701b6b5f913'   # GIT_SHALLOW + commit pin fails in FetchContent

function Find-VS {
    $vswhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
    if (Test-Path $vswhere) {
        $vs = & $vswhere -latest -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
        if ($vs) { return $vs }
    }
    throw 'MSVC not found: install the VS 2022 "Desktop development with C++" workload'
}

function Ensure-Checkout($repo, $dir, $pin) {
    if (-not (Test-Path (Join-Path $dir '.git'))) {
        if (Test-Path $dir) { Remove-Item $dir -Recurse -Force }   # empty gitlink placeholder
        git clone $repo $dir
        if ($LASTEXITCODE) { throw "clone failed: $repo" }
    }
    $head = git -C $dir rev-parse HEAD
    if ($head -ne $pin) {
        git -C $dir fetch $repo $pin
        git -C $dir checkout --detach $pin
        if ($LASTEXITCODE) { throw "checkout $pin failed in $dir" }
    }
    Write-Host "[setup] $dir @ $pin"
}

$vs     = Find-VS
$cmext  = Join-Path $vs 'Common7\IDE\CommonExtensions\Microsoft\CMake'
$cmake  = Join-Path $cmext 'CMake\bin\cmake.exe'
$ninja  = Join-Path $cmext 'Ninja\ninja.exe'
$vcvars = Join-Path $vs 'VC\Auxiliary\Build\vcvars64.bat'
foreach ($p in @($cmake, $ninja, $vcvars)) { if (-not (Test-Path $p)) { throw "not found: $p" } }

$ps2  = Join-Path $Root 'third_party\PS2Recomp'
$elfio = Join-Path $Root 'deps\elfio'

Ensure-Checkout $PS2RECOMP_REPO $ps2 $PS2RECOMP_PIN
Ensure-Checkout $ELFIO_REPO $elfio $ELFIO_PIN

# REO-local PS2Recomp patches (the pinned fork is upstream-owned). Idempotent.
foreach ($patch in Get-ChildItem (Join-Path $Root 'third_party\patches\ps2recomp') -Filter *.patch -ErrorAction SilentlyContinue | Sort-Object Name) {
    # PS 5.1 turns native stderr into terminating errors under 'Stop'; the reverse
    # check is *expected* to fail on an unpatched tree, so rely on exit codes here.
    $ErrorActionPreference = 'Continue'
    git -C $ps2 apply --reverse --check $patch.FullName 2>&1 | Out-Null
    $alreadyApplied = ($LASTEXITCODE -eq 0)
    if (-not $alreadyApplied) { git -C $ps2 apply $patch.FullName 2>&1 | Write-Host }
    $applyCode = $LASTEXITCODE
    $ErrorActionPreference = 'Stop'
    if ($alreadyApplied) { Write-Host "[setup] already applied: $($patch.Name)"; continue }
    if ($applyCode) { throw "patch failed: $($patch.Name)" }
    Write-Host "[setup] applied: $($patch.Name)"
}

& $cmake -S $ps2 -B "$ps2\out\build" -G 'Visual Studio 17 2022' -A x64 "-DFETCHCONTENT_SOURCE_DIR_ELFIO=$($elfio -replace '\\','/')"
if ($LASTEXITCODE) { throw 'PS2Recomp configure failed' }
& $cmake --build "$ps2\out\build" --config Release --target ps2_runtime ps2_recomp ps2_analyzer -- /m
if ($LASTEXITCODE) { throw 'PS2Recomp build failed' }

# REO itself uses Ninja: resumable after interruption and ~5x faster than MSBuild here.
$cfg = "`"$cmake`" -S `"$Root`" -B `"$Root\build-ninja`" -G Ninja -DCMAKE_BUILD_TYPE=Release " +
       "-DREO_RECOMP_OPT=/O2 -DREO_RECOMP_PCH=ON `"-DCMAKE_MAKE_PROGRAM=$ninja`""
cmd /c "call `"$vcvars`" >nul && $cfg"
if ($LASTEXITCODE) { throw 'REO configure failed' }

if ($Build) {
    cmd /c "call `"$vcvars`" >nul && `"$ninja`" -C `"$Root\build-ninja`" -j $Jobs reo_recomp"
    if ($LASTEXITCODE) { throw 'reo_recomp build failed' }
}
Write-Host '[setup] done'
