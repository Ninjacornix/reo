# Portable Outbreak server component

Players use **Co-op → Host server** in the launcher. It starts the required
services and shows a copyable address for friends; no manual Python setup is
needed in the portable package. Router/firewall configuration is still necessary
for Internet hosting. The following commands are maintainer instructions.

`tools/local_build/export_server.py` exports the pinned server plus this patch,
official embeddable Python and pinned dependencies into a new immutable component
directory. It includes the full patched server source, dependency source archives
and notices, verifies Python/dependency digests, checks portable imports, and seals
`server-manifest.json`. `launcher/package-local.ps1 -Server PATH` verifies and
copies that component into the portable release. No account database, credentials
or developer virtual environment is packaged.

The native clients can use [openSNAP](https://github.com/GrenderG/openSNAP), a
separate server project. This directory contains one patch against upstream
revision `f9af55491718a043923225a0895fe60eab76fd7c`.

openSNAP and this server patch are licensed under the **GNU Affero General
Public License, version 3**, as provided by the upstream
[LICENSE](https://github.com/GrenderG/openSNAP/blob/f9af55491718a043923225a0895fe60eab76fd7c/LICENSE).
The server executes separately from the native runtime. Server/vendor binaries,
account databases and credentials are not committed to this repository.

## Apply and test

From this repository's root, using PowerShell, Git and Python 3.11 or newer:

```powershell
$outbreakServerPatch = (Resolve-Path 'network/server/patches/0001-outbreak-current-room-query.patch').Path
git clone https://github.com/GrenderG/openSNAP.git build/server/openSNAP
git -C build/server/openSNAP checkout --detach f9af55491718a043923225a0895fe60eab76fd7c
git -C build/server/openSNAP apply --check $outbreakServerPatch
git -C build/server/openSNAP apply $outbreakServerPatch

Push-Location build/server/openSNAP
python -m venv .venv
& .venv/Scripts/python.exe -m pip install -r requirements.txt
& .venv/Scripts/python.exe -m unittest tests.test_outbreak_plugin tests.test_outbreak2_plugin
Pop-Location
```

Check whether the patch is already applied with
`git -C build/server/openSNAP apply --reverse --check $outbreakServerPatch`.
Use the upstream README for server configuration and operation. Restart the
server after applying the patch; an existing process retains its loaded code
and in-memory sessions.

## What it fixes

After a scenario, the original File #1 meeting-room code queries the roster
with room ID `0`, meaning its current room. The File #1 server handler
previously looked up literal room `0` and returned an empty roster. The patch
resolves this request using the authenticated caller's actual room, matching
the existing File #2 implementation. The response still echoes ID `0` and
preserves member names, profiles and pagination. Explicit room IDs and callers
without a current room retain their existing behavior.

Both new regression tests fail against the pinned handler. With the patch,
all **60 File #1 and File #2 tests pass**, covering room changes, unrelated
callers, unknown IDs and four-player pagination. Native test sessions 018 and
020 used the patched server; session 018 specifically captured all four
original clients querying ID `0` and receiving their real four-member roster.
Session 020 separately verified four-player room membership and synchronized
movement. The roster fix alone does not establish gameplay synchronization.
