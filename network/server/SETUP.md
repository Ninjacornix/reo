# Local co-op server requirements

The package includes openSNAP source only. Python, pip packages, wheels and
dependency source archives are not included. Only the host needs this setup;
joining a friend's server does not require Python.

Install **Python 3.12, 64-bit**, from https://www.python.org/downloads/windows/
with the Windows Python launcher (`py`) and pip. Then open PowerShell in the
extracted RE: Outbreak launcher folder and run:

```powershell
$serverEnv = Join-Path $env:LOCALAPPDATA 'OutbreakRecomp\launcher\server-python'
py -3.12 -m venv $serverEnv
& (Join-Path $serverEnv 'Scripts\python.exe') -m pip install -r '.\network-server\requirements.txt'
```

This installs the dependencies into your user profile, outside the download
folder. The launcher detects that environment automatically. After setup, use
**Co-op > Host server** normally. Nothing is downloaded or installed by the
launcher. Re-run the pip command after an update changes requirements.txt.

For an existing Python 3.12 environment, install requirements.txt there and set
the user variable **REO_SERVER_PYTHON** to its full `python.exe` path. That
explicit setting takes priority over the default environment. It must include
SQLite, TLS and the listed packages; the launcher checks imports before hosting.

The server source is pinned to openSNAP revision
`f9af55491718a043923225a0895fe60eab76fd7c` with the Outbreak room-query patch.
Upstream: https://github.com/GrenderG/openSNAP
Patch: https://github.com/Ninjacornix/reo/tree/main/network/server/patches
The separately executed server retains its AGPL-3.0 licence in source/LICENSE.
Other game profiles remain source modules needed by the upstream service registry.

Account databases, passwords and logs are created in Local AppData, outside the
application folder. Keep network-server/ beside the launcher. Internet hosting
still requires reachable addressing and firewall/router rules; see the main README.
