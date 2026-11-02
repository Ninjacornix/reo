function Find-LauncherDotNet {
    # Source builds need the SDK; packaged launchers include their runtime.
    $candidates = @()
    $onPath = Get-Command dotnet -CommandType Application -ErrorAction SilentlyContinue
    if ($onPath) { $candidates += $onPath.Source }
    foreach ($sdkRoot in @($env:DOTNET_ROOT_X64, $env:DOTNET_ROOT, (Join-Path $env:USERPROFILE '.dotnet'))) {
        if ($sdkRoot) { $candidates += Join-Path $sdkRoot 'dotnet.exe' }
    }
    foreach ($candidate in ($candidates | Select-Object -Unique)) {
        if (!(Test-Path -LiteralPath $candidate -PathType Leaf)) { continue }
        try { $sdkVersion = & $candidate --version 2>$null } catch { continue }
        if ($LASTEXITCODE -eq 0 -and "$sdkVersion" -match '^(\d+)\.' -and [int]$Matches[1] -ge 10) {
            return $candidate
        }
    }
    throw '.NET 10 SDK or newer is required to build the launcher. Install it from https://dotnet.microsoft.com/download/dotnet/10.0 (the runtime alone is insufficient), then run StartLauncher.cmd again. User SDKs in %USERPROFILE%\.dotnet are also supported.'
}
