# Outbreak server source

Players use **Co-op → Host server** in the launcher. It starts the required
services and shows a copyable address for friends. Missing Python/packages are
prepared automatically in a private environment in your selected data folder on first hosting;
see [setup](SETUP.md). The download includes source rather than a bundled
interpreter or pip packages.
Router/firewall configuration is still necessary for Internet hosting.

`tools/local_build/export_server_source.py` selects verified server source from
the frozen component and writes a format-2 server-manifest.json, requirements.txt
and setup README. `launcher/package-slim.ps1 -Server PATH` verifies that manifest
and excludes interpreters, vendor packages, wheels, databases and source archives.
The older export_server.py remains a maintainer tool for constructing the frozen
reference component; its Python/dependency payload is not shipped in v1.0.6.

The native clients can use [openSNAP](https://github.com/GrenderG/openSNAP), a
separate server project. RC2 pins upstream revision
`1014371ba70d1caa415a09b1fa39f550b1e9cb55`, applies the patches in `patches/`,
and adds the separately executed AGPL native companion in `native/`.
The newer source includes reliable membership callbacks, suppression of late
lobby echoes during gameplay, bounded endpoint state and rotating server logs.
Our File #1 room-ID-zero correction remains applied.

openSNAP and this server patch are licensed under the **GNU Affero General
Public License, version 3**, as provided by the upstream
[LICENSE](https://github.com/GrenderG/openSNAP/blob/1014371ba70d1caa415a09b1fa39f550b1e9cb55/LICENSE).
The server executes separately from the native runtime. Server/vendor binaries,
account databases and credentials are not committed to this repository.

## Apply and test

From this repository's root, using PowerShell, Git and Python 3.11 or newer:

```powershell
git clone https://github.com/GrenderG/openSNAP.git build/server/openSNAP
git -C build/server/openSNAP checkout --detach 1014371ba70d1caa415a09b1fa39f550b1e9cb55
python tools/local_build/export_server_source.py --checkout build/server/openSNAP --output build/server/rc2-component --root .

Push-Location build/server/openSNAP
python -m venv .venv
& .venv/Scripts/python.exe -m pip install -r requirements.txt
$env:PYTHONPATH = "$(Resolve-Path '../rc2-component/source');$PWD"
& .venv/Scripts/python.exe -B -m unittest tests.test_outbreak_plugin tests.test_outbreak2_plugin tests.test_udp_reliability tests.test_udp_server_runtime -q
Pop-Location
& build/server/openSNAP/.venv/Scripts/python.exe -B -m unittest discover -s network/server/tests -v
Remove-Item Env:PYTHONPATH
```

The exporter uses an archive of the pinned commit, applies the complete patch
series and copies the companion; it never changes an existing server checkout.
Run `build/server/rc2-component/source/run.py` for the patched services. Applying
only patch 0001 supplies the roster correction, without native negotiation.
The format-2 manifest hashes code, static APP pages and the upstream signup logo.
Accounts, databases, Python environments and unrelated game patches are excluded.

Use the upstream README for server configuration and operation. Restart the
server after applying the patch; an existing process retains its loaded code
and in-memory sessions.

## Upgrading existing hosting databases (#84)

Patch `0003-sqlite-legacy-schema-migration.patch` fixes the APP service exiting
with `sqlite3.OperationalError: no such column: sort_key` after an upgrade.
The old server stored one row per result; RC2 and v1.0.20 expect one row per
player and board, plus account recovery codes. `CREATE TABLE IF NOT EXISTS`
alone does not upgrade those existing tables.

The patch upgrades the database on the next hosting startup, without resetting
accounts or touching game saves. Existing IDs, names, password records, seeds,
teams and encrypted login keys remain unchanged. Accounts missing the new
recovery-code field receive individual codes; older stores missing the login-key
column receive that column too.

All original result rows and their indexes are retained in `records_legacy_v1`.
The active rankings for both `outbreak` and `outbreak2` are rebuilt in original
submission order: fastest clears retain the winning result's details and time,
and the old per-scenario points boards feed the new per-player total. Rows for
other games or unknown boards stay in the archive without guessing their
ranking rules. New result submissions update the new composite primary key.
Reopening an upgraded database does not replay the archive or change recovery
codes. An existing archive is never overwritten.

Schema inspection and changes run under one `BEGIN IMMEDIATE` transaction. This
serializes the four services' startup and rolls back all schema/data changes if
an upgrade fails. The connection allows up to 30 seconds for another SQLite
writer, and closes its handle after a failed initialization.

The database is `<selected data folder>/hosted-server/opensnap.db` for File #1
and `<selected data folder>/hosted-server-file2/opensnap.db` for File #2. Windows
defaults to `data` beside the launcher; `storage.json` beside the launcher records
a custom location. There is no need to remove or reset these folders with this
patch. Re-export the server component when packaging the fix so its manifest
includes the new patched source; no game rebuild is required for this migration.

Regression checks are included in `network/server/tests/test_database_migration.py`
and run in Server compatibility CI with the exported patched component. They
exercise real SQLite files, retained authentication/recovery, both editions'
rankings, updates after migration, repeated/concurrent startup, rollback after
an injected failure and preservation of an existing archive.

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
