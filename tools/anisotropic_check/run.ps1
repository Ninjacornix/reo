param([string]$Build = 'build-ninja')
$ErrorActionPreference = 'Stop'
$repo = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../..'))
if (![IO.Path]::IsPathRooted($Build)) { $Build = Join-Path $repo $Build }
$out = Join-Path $Build 'anisotropic-check'
New-Item -ItemType Directory -Force $out | Out-Null
$granite = Join-Path $repo 'build-ninja/parallel-gs-source/Granite'
$vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio/Installer/vswhere.exe'
$vs = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
$vcvars = Join-Path $vs 'VC/Auxiliary/Build/vcvars64.bat'
$includes = @("$repo/tools/parallel_gs_backend/resident_gs", "$repo/build-ninja/parallel-gs-source/gs", "$granite/vulkan", "$granite/util", "$granite/math", "$granite/application/global", "$granite/third_party/volk", "$granite/third_party/khronos/vulkan-headers/include")
$flags = ($includes | ForEach-Object { '/I"' + $_ + '"' }) -join ' '
$libs = @("$Build/recomp/reo_parallel_gs_resident_native.lib")
$base = Join-Path $repo 'build-ninja/m2-gpu-gs-adapter/out/parallel-gs'
$libs += @('gs/Release/parallel-gs.lib','Granite/vulkan/Release/granite-vulkan.lib','Granite/third_party/Release/granite-volk.lib','Granite/util/Release/granite-util.lib','Granite/math/Release/granite-math.lib') | ForEach-Object { Join-Path $base $_ }
$link = ($libs | ForEach-Object { '"' + $_ + '"' }) -join ' '
$command = @"
@echo off
call "$vcvars" >nul 2>nul
if errorlevel 1 exit /b 1
cd /d "$out"
cl /nologo /EHsc /O2 /MD /std:c++17 /fp:precise /DNOMINMAX /DGRANITE_SHIPPING /DHAVE_WSI_DXGI_INTEROP $flags "$PSScriptRoot/main.cpp" /Fe:anisotropic_check.exe /link /STACK:16777216 $link advapi32.lib comdlg32.lib d3d11.lib dxgi.lib dxguid.lib gdi32.lib kernel32.lib ole32.lib oleaut32.lib shell32.lib user32.lib uuid.lib winmm.lib winspool.lib
exit /b %errorlevel%
"@
$bat = Join-Path $out 'build.cmd'
[IO.File]::WriteAllText($bat,$command)
& cmd /c $bat
if ($LASTEXITCODE) { throw 'GPU texture fixture build failed.' }
if (Get-Process reo_recomp*,reo_launcher_game -ErrorAction SilentlyContinue) { throw 'Close the game before the isolated GPU check.' }
$previous = $env:REO_TEXTURE_ANISOTROPY
$filter = $env:REO_TEXTURE_FILTER
try {
    $env:REO_TEXTURE_FILTER = 'linear'
    foreach ($level in @(1,2,4,8,16)) {
        $env:REO_TEXTURE_ANISOTROPY = "$level"
        & (Join-Path $out 'anisotropic_check.exe') (Join-Path $out "$level.rgba")
        if ($LASTEXITCODE) { throw "GPU texture fixture failed at ${level}x." }
    }
    $original = [IO.File]::ReadAllBytes((Join-Path $out '1.rgba'))
    $results = foreach ($level in @(2,4,8,16)) {
        $filtered = [IO.File]::ReadAllBytes((Join-Path $out "$level.rgba"))
        $before = 0.0; $after = 0.0; $different = 0; $protected = 0
        for ($y=8; $y -lt 112; $y++) { for ($x=8; $x -lt 112; $x++) {
            $at = 4 * ($y*256+$x)
            $before += [math]::Pow($original[$at]-127.5,2)
            $after += [math]::Pow($filtered[$at]-127.5,2)
            if ($original[$at] -ne $filtered[$at]) { $different++ }
            foreach ($offset in @((128*4),(128*256*4),(128*4+128*256*4))) {
                for ($c=0;$c -lt 4;$c++) { if($original[$at+$offset+$c] -ne $filtered[$at+$offset+$c]) { $protected++ } }
            }
        } }
        if ($different -eq 0 -or $protected -ne 0) { throw "Filtering scope failed at ${level}x: differences=$different protected=$protected" }
        if ($level -eq 16 -and $after -gt $before*0.2) { throw '16x filtering failed to reduce stripe aliasing by 80%.' }
        [pscustomobject]@{level=$level;changedPixels=$different;protectedDifferences=$protected;aliasEnergyRatio=$after/$before}
    }
    $results | ConvertTo-Json | Set-Content (Join-Path $out 'result.json')
    $results | Format-Table
    foreach ($mode in @(1,2,3)) {
        foreach ($level in @(1,16)) {
            $env:REO_TEXTURE_ANISOTROPY = "$level"
            & (Join-Path $out 'anisotropic_check.exe') (Join-Path $out "clamp$mode-$level.rgba") $mode
            if ($LASTEXITCODE) { throw "Clamp sampler fixture failed: mode=$mode level=$level" }
        }
        $reference = [IO.File]::ReadAllBytes((Join-Path $out "clamp$mode-1.rgba"))
        $enhanced = [IO.File]::ReadAllBytes((Join-Path $out "clamp$mode-16.rgba"))
        $changes=0
        for ($y=8;$y -lt 112;$y++) { for($x=8;$x -lt 112;$x++) {
            $at=4*($y*256+$x)
            if ($reference[$at] -ne $enhanced[$at]) { $changes++ }
            if (($mode -band 1) -and $x -gt 24 -and $enhanced[$at] -ne $reference[$at]) { throw 'Anisotropic clamp crossed a horizontal texture edge.' }
        } }
        if ($mode -eq 2 -and $changes -eq 0) { throw 'Clamp-T anisotropic sampling did not run.' }
        "PASS clamp mode=$mode changedPixels=$changes"
    }
} finally { $env:REO_TEXTURE_ANISOTROPY=$previous; $env:REO_TEXTURE_FILTER=$filter }
