# Paired RC1 (WPF) and common (Avalonia) launcher captures on one Windows PC.
#
#   powershell -ExecutionPolicy Bypass -File tools\launcher\parity.ps1 -Rc1 "C:\Games\RE Outbreak RC1\Outbreak.Launcher.exe"
#
# The common launcher is published next to the RC1 executable so both resolve the same
# installation (distribution.json, build kit). Each app gets a fresh, separate data folder; your
# own launcher data is never used unless -Seed copies settings and artwork from it (read-only).
# Results: build-launcher\parity\{rc1,common}\<Page>.png. Compare with
#   python tools/launcher/compare_parity.py build-launcher/parity
param(
    [Parameter(Mandatory)][string]$Rc1,
    [string]$Output = '',
    [string]$Seed = '',
    [int]$Delay = 1500
)
$ErrorActionPreference = 'Stop'
$repo = (Resolve-Path (Join-Path $PSScriptRoot '..\..')).Path
$rc1Exe = (Resolve-Path $Rc1).Path
$install = Split-Path $rc1Exe -Parent
if (!$Output) { $Output = Join-Path $repo 'build-launcher\parity' }
$Output = [IO.Path]::GetFullPath($Output)
$common = Join-Path $install 'common-launcher-parity'
Write-Host "Publishing the common launcher to $common"
& dotnet publish (Join-Path $repo 'launcher\desktop\Reo.Launcher.Desktop.csproj') -c Release -r win-x64 --self-contained true -o $common --nologo -v q
if ($LASTEXITCODE) { throw 'Common launcher publish failed.' }
$commonExe = Join-Path $common 'Outbreak.Launcher.exe'
$pages = 'Play','Graphics','Audio','Controller','Saves','Coop','Mods','Cheats','Setup','Launcher','Logs','Developer'
foreach ($app in @(@{ Name = 'rc1'; Exe = $rc1Exe }, @{ Name = 'common'; Exe = $commonExe })) {
    $folder = Join-Path $Output $app.Name
    New-Item -ItemType Directory -Force $folder | Out-Null
    foreach ($page in $pages) {
        # A fresh data folder per capture keeps every page independent of the previous run.
        # Equal-length data paths keep path text (Game files, Saves) directly comparable.
        $data = Join-Path $Output ('data-' + $app.Name.Substring(0, 1))
        if (Test-Path $data) { Remove-Item -Recurse -Force $data }
        New-Item -ItemType Directory -Force $data | Out-Null
        if ($Seed) {
            Copy-Item (Join-Path $Seed 'settings.json') $data -ErrorAction SilentlyContinue
            foreach ($sub in 'artwork','game-fonts','controller-artwork') {
                $source = Join-Path $Seed $sub
                if (Test-Path $source) { Copy-Item -Recurse $source $data }
            }
        }
        $png = Join-Path $folder ($page + '.png')
        if (Test-Path $png) { Remove-Item -Force $png }
        $arguments = @('--data-home', "`"$data`"", '--page', $page, '--screenshot', "`"$png`"")
        if ($app.Name -eq 'common') { $arguments += @('--screenshot-delay', $Delay) }
        Write-Host "$($app.Name) $page"
        $process = Start-Process -FilePath $app.Exe -ArgumentList $arguments -WorkingDirectory $install -PassThru
        if (!$process.WaitForExit(120000)) { $process.Kill(); Write-Warning "$($app.Name) $page timed out" }
        if (!(Test-Path $png)) { Write-Warning "$($app.Name) $page produced no capture" }
    }
}
Write-Host "Captures: $Output"
