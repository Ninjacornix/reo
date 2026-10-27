# Local co-op server

Enable **Co-op > Host server**, then click **Start server** in the launcher.
On first use it prepares Python 3.12 and the packages in requirements.txt, then
starts the four services automatically. Setup needs Internet access and shows
progress in the launcher; the Start server button becomes **Cancel** during setup.
Later starts reuse the installed environment, including when offline.

The application ZIP contains server source only. Setup downloads go under
`data/` beside the launcher by default, or the folder selected under **Game files > Storage**:

- `server-tools/`: pinned, hash-verified uv setup tool and its download cache.
- `server-python-runtime/`: private Python runtime downloaded by uv.
- `server-python/<requirements-hash>/`: installed server packages and setup receipt.
- `hosted-server/`: account database and service logs.

No administrator installer, PATH change or system-wide pip installation is used.
The launcher never installs packages into another application's Python environment.
Changing requirements creates a separate managed environment. Interrupted setup
can be retried. Details are in `server-python/setup.log` under the launcher data
folder; network/download failures leave the server stopped with an error message.
Joining a friend's server does not need any Python setup or these downloads.

Advanced users can set **REO_SERVER_PYTHON** to an existing Python 3.12 executable
with the dependencies already installed. If that environment is unavailable or
missing packages, the launcher prepares its private environment instead of
modifying the existing one. requirements.txt lists the pinned package versions.

The setup tool is uv 0.13.3 from https://github.com/astral-sh/uv/releases/tag/0.13.3;
the launcher pins both archive and executable SHA-256 hashes. Python downloads
use uv's managed Python distributions; packages come from https://pypi.org/simple.

The server source is pinned to openSNAP revision
`f9af55491718a043923225a0895fe60eab76fd7c` with the Outbreak room-query patch.
Upstream: https://github.com/GrenderG/openSNAP
Patch: https://github.com/Ninjacornix/reo/tree/main/network/server/patches
The separately executed server retains its AGPL-3.0 licence in source/LICENSE.
Other game profiles remain source modules needed by the upstream service registry.

Keep network-server/ beside the launcher. Internet hosting still requires a
reachable LAN/VPN/public address and firewall/router rules; see the main README.
