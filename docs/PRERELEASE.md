# Prerelease packaging

Current target: **v1.0.12**, shown in the launcher as **1.0 Alpha**, marked
prerelease. The tag stays numeric so installed v1.0.11 launchers offer it as an
update; use "RE: Outbreak 1.0 Alpha (v1.0.12)" as the release title. .NET is an
external prerequisite. The server is source-only, with Python/packages prepared
automatically in Local AppData on first hosting (an installed Python 3.12 is
reused when present).

v1.0.12 ships launcher changes (guided Play page and checklist, ISO check before
import, Remove game, Co-op page, LAN discovery, configurable sign-up/game-server
ports, automatic waiting room) and a new kit with compile cache format 2: objects are
keyed by content, so later kits reuse unchanged units. Because its kit identity is
new, this release carries the rebuild marker and every player compiles once.

**Release builds could not start the game before v1.0.12.** No game built from a
release kit had been run end to end. Testing one showed three startup failures, also
present in older release kits:

- The GPU movie install refused the release generator's function assignment: entry
  points 0x170E00/20/48, 0x171944/78/88, 0x1719B4 and 0x1719DC are registered to the
  function whose Ghidra range contains them (`sub_00170DE0`, `sub_00171920`,
  `sub_001719A0`, `sub_001719C8`), while the older developer output registered them to
  the enclosing `sub_00170D90` / `sub_00171880`. Both bodies hold the same original
  instructions and the native replacements carry labels for every one of these entries,
  so `original_transport_route.cpp` now accepts either owner.
- Six helper shaders (`movie_ipu_csc_nv12`, `resident_image_upload`, `clear_setup`,
  `clear_bounds`, `clear_write`, `resident_readback`) were loaded through `__FILE__`, the
  build machine's source path. Release kits now ship them in `shaders/`, copy them to
  `reo-gpu-present/` beside the game, and `shader_location.hpp` prefers that folder,
  falling back to the source tree for developer builds. The executable folder comes from
  `GetModuleFileNameW` (defined in `parallel_backend.cpp`); `_wpgmptr` is empty for
  programs entered through `main`.
- "Original movie DMA has duplicate completion publication" at the first movie: the
  final-tag handoff moved the pending channel publication out of a `std::function` and
  relied on the source being empty. libc++ (the llvm-mingw release toolchain) keeps small
  callables in a moved-from function; MSVC's library empties it, which is why developer
  builds worked. PS2Recomp patch `0097` uses `std::exchange`.

Make the kit from the verified v1.0.11 release kit, the same recompiler and the same
dependency-sources ZIP (SHA-256 5854de0f...7bca7e21):

```
python tools/local_build/refresh_inputs.py --kit build-ninja/slim-release/inputs-v111-release \
  --output <new> --archive <new>.zip --recompiler <inputs-v111-release/tools/ps2_recomp.exe copy> \
  --dependency-sources <RE-Outbreak-v1.0.11-Dependency-Sources.zip> --version 1.0.12 \
  --update-source tools/parallel_gs_backend/movie_runtime/original_transport_route.cpp \
  --update-source tools/parallel_gs_backend/movie_runtime/movie_owner_service.h \
  --update-source tools/parallel_gs_backend/parallel_backend.cpp \
  --update-source tools/parallel_gs_backend/resident_gs/gs_renderer.cpp \
  --update-source third_party/PS2Recomp/ps2xRuntime/src/lib/native_movie_image.inl \
  --add-source tools/parallel_gs_backend/shader_location.hpp \
  --add-shader tools/parallel_gs_backend/movie_runtime/assets/movie_ipu_csc_nv12.spv \
  --add-shader tools/parallel_gs_backend/resident_gs/shaders/{resident_image_upload,clear_setup,clear_bounds,clear_write,resident_readback}.spv
```

Kit: `build-ninja/slim-release/inputs-v112h`, manifest
46026b9516f85064ceb8d8e91607174d876736d6b5a05e8d8978334d35143d3f; archive
`build-inputs-v112h.zip`, SHA-256
1214502b1f8a5ba83f741c9ca5e4e35eca72d970e1763315448505b4b64266d0. Do not use
inputs-v112 to -v112g (earlier cache, scheduler and startup bugs) or the inputs-v111
and inputs-v111-final folders (rejected 64-file batching). Header changes still
invalidate every unit (one global header fingerprint); `.cpp`-only changes rebuild just
those units.

**Rebuild marker.** When a release changes generation/runtime inputs (a new kit
identity), put `<!-- reo:requires-rebuild -->` in the GitHub release notes. The
updater then warns that the game is built again after updating and asks before
installing. Launcher-only releases must not include it.

Use tools/local_build/export_server_source.py --component <frozen-component>
--output <new-folder> --root <repo> to select verified server modules/run.py and
its AGPL licence. The result includes requirements.txt, README.md and a format-2
manifest declaring external-python. Do not ship vendor, python, wheels,
dependency-sources, tests, databases, credentials or developer environments.

Commit corresponding source, then run launcher/package-slim.ps1 with -Inputs,
-KitManifest, -Server <source-only-export>, -Output and -Version 1.0.12. It verifies
the server manifest, publishes a framework-dependent single-file launcher,
consolidates required licence texts into THIRD-PARTY-NOTICES.txt and links GitHub's
source archive for the release tag. Keep LICENSE/NOTICE and the
server's own licence. There must be no top-level LICENSES or sources folder.

The main asset is RE-Outbreak-v1.0.12-Windows-x64.zip. ZIP paths must be relative,
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

Publish the main ZIP/checksum and RE-Outbreak-v1.0.12-Dependency-Sources.zip/checksum.
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

For launcher-only updates, reuse the unchanged current kit and its manifest rather
than re-exporting only to change notice URLs: a new manifest hash means a new kit
identity and a rebuild for every player (since cache format 2, only changed units
compile, but generation still reruns). Export a new kit only when actual
runtime/generator inputs change.

Automatic compiler setup lives in PortableCompilerSetup.cs, pins the official
20251216 UCRT x64 ZIP SHA-256, downloads to Local AppData and admits only verified
x64 components with a complete hashed cache inventory. No user environment variable
is changed. --test-compiler-setup <fresh-home> <receipt> checks cold download, native
compile/link/run, cached reuse and cancellation without compiling the game.
