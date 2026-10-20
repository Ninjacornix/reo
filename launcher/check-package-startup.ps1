param(
    [Parameter(Mandatory=$true)][string]$Root,
    [Parameter(Mandatory=$true)][string]$Output
)
$ErrorActionPreference = 'Stop'
$Root = (Resolve-Path -LiteralPath $Root).Path
$Output = [IO.Path]::GetFullPath($Output)
if (Test-Path -LiteralPath $Output) { throw 'Choose a new diagnostic output directory.' }
if (!(Test-Path -LiteralPath (Join-Path $Root 'distribution.json'))) {
    throw 'Use the extracted release package, not development build output.'
}
New-Item -ItemType Directory -Path $Output | Out-Null
$screenshot = Join-Path $Output 'startup.png'
$start = [Diagnostics.ProcessStartInfo]::new()
$start.FileName = Join-Path $Root 'Outbreak.Launcher.exe'
$start.WorkingDirectory = $Output
$start.UseShellExecute = $false
$start.Arguments = '--screenshot "' + $screenshot + '" --page Graphics'
$process = [Diagnostics.Process]::Start($start)
try {
    if (!$process.WaitForExit(30000)) {
        $process.Kill()
        throw 'Packaged launcher startup timed out.'
    }
    if ($process.ExitCode -ne 0) { throw ('Packaged launcher failed: exit ' + $process.ExitCode) }
    $bytes = [IO.File]::ReadAllBytes($screenshot)
    if ($bytes.Length -lt 1000 -or [BitConverter]::ToString($bytes, 0, 8) -ne '89-50-4E-47-0D-0A-1A-0A') {
        throw 'Launcher did not render its settings window.'
    }
    @{passed=$true; exitCode=$process.ExitCode; screenshotBytes=$bytes.Length;
      differentWorkingDirectory=$true; gameplayRun=$false} |
        ConvertTo-Json | Set-Content -LiteralPath (Join-Path $Output 'startup-check.json') -Encoding UTF8
    Get-Content -LiteralPath (Join-Path $Output 'startup-check.json')
} finally { $process.Dispose() }
