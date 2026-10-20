# Prerelease packaging

Current target: **v1.0.9**, marked prerelease. .NET is an external
prerequisite. The server is source-only, with Python/packages prepared
automatically in Local AppData on first hosting.

For this launcher-only update, reuse the frozen v1.0.6 build-inputs6.zip and
inputs6/build-kit.json. Export a new kit with tools/local_build/export_slim_inputs.py
only when generator/runtime inputs change. Required generation/runtime inputs
remain in build-inputs.zip; the compiler and large corresponding-source archive
are excluded. The ZIP expands into Local AppData automatically during import.

Use tools/local_build/export_server_source.py --component <frozen-component>
--output <new-folder> --root <repo> to select verified server modules/run.py and
its AGPL licence. The result includes requirements.txt, README.md and a format-2
manifest declaring external-python. Do not ship vendor, python, wheels,
dependency-sources, tests, databases, credentials or developer environments.

Commit corresponding source, then run launcher/package-slim.ps1 with -Inputs,
-KitManifest, -Server <source-only-export>, -Output and -Version 1.0.9. It verifies
the server manifest, publishes a framework-dependent single-file launcher,
consolidates required licence texts into THIRD-PARTY-NOTICES.txt and links GitHub's
source archive for the release tag. Keep LICENSE/NOTICE and the
server's own licence. There must be no top-level LICENSES or sources folder.

The main asset is RE-Outbreak-v1.0.9-Windows-x64.zip. ZIP paths must be relative,
use / separators and place Outbreak.Launcher.exe at the root. Reject absolute
paths, traversal, drive prefixes, duplicate names and unexpected files. Extract
the final ZIP into a fresh folder and verify all inventory, server and nested
input paths, sizes and SHA-256 hashes.

Run launcher/check-package-startup.ps1 -Root <extracted-folder> -Output <new-folder>
on the actual extracted release. It renders the Graphics page from a different
working directory and requires exit 0 plus a PNG. This does not run a game/server.
For server integration, use --test-coop-host <source-export> <receipt> with
REO_SERVER_PYTHON pointing to an installed Python 3.12 environment for the override
path, or a missing path to exercise automatic provisioning in the isolated test
home. It verifies cold setup and a cached restart. Owned services use isolated
ports/accounts and are shut down afterward.

Publish the main ZIP/checksum and RE-Outbreak-v1.0.9-Dependency-Sources.zip/checksum.
Use GitHub's automatic source archives for the project; do not add a duplicate
Project-Source.tar asset. Ordinary players only need the main ZIP. No source
archives belong inside the application or server folder. Server setup downloads
the pinned uv tool, verifies archive/executable hashes and installs Python/packages
privately on first hosting. Compiler setup is automatic during import; .NET remains a launcher prerequisite.
Keep the frozen dependency sources matched to
binaries and preserve the dirty developer submodule.

Inspect all nested archives for private game data. Disclose omitted checks in the
release notes, use a new immutable tag targeting the full source SHA, and verify
remote asset hashes/sizes before publishing. No game/setup pass may be invented.
Native Linux is not a release asset.

ISO checks: --test-disc-import <receipt> runs synthetic rejection/accepted-import
cases without game data. --check-iso <iso> <receipt> performs read-only real-image
validation without extraction, compilation or gameplay. Require rejection before
creating cache files, verify a supported reference when available, and retain
the exact executable SHA-256 gate. SYSTEM.CNF VER is not the disc revision.

For launcher-only updates, reuse the unchanged v1.0.6 build-inputs6.zip and manifest
rather than re-exporting only to change notices URLs: a new manifest hash would
force needless full-game recompilation. The matching SDK source release URL remains
valid. Export a new kit only when actual runtime/generator inputs change.

Automatic compiler setup lives in PortableCompilerSetup.cs, pins the official
20251216 UCRT x64 ZIP SHA-256, downloads to Local AppData and admits only verified
x64 components with a complete hashed cache inventory. No user environment variable
is changed. --test-compiler-setup <fresh-home> <receipt> checks cold download, native
compile/link/run, cached reuse and cancellation without compiling the game.
