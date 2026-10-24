# Prerelease packaging

Current target: **v1.0.18**, shown in the launcher as **1.0 Alpha**, marked
prerelease; release title "RE: Outbreak 1.0 Alpha (v1.0.18)". Tags stay numeric so
installed launchers offer the update. .NET is an
external prerequisite. The server is source-only, with Python/packages prepared
automatically in Local AppData on first hosting (an installed Python 3.12 is
reused when present).

## v1.0.18

Refresh the frozen v1.0.17 kit with the changed bootstrap, clock observer,
internal-resolution policy, parallel backend and resident GS renderer. Include
the authored timing/warmup headers and generic scanout shader header. Preserve
the frozen SDK, independent libraries, previous source patches and the dirty
working submodule. The dependency source base remains unchanged.

Verification workspace: `build-ninja/release-v118`; native evidence is under
`build-ninja/higher-resolution` and `build-ninja/frame-pacing`. The reference
native executable incrementally recompiles changed authored/graphics units and
reuses unchanged verified game/SDK objects. Validate correspondence against the
sealed kit; a complete cold compilation is not repeated. Include
`<!-- reo:requires-rebuild -->` in release notes.

Tests cover 450 launcher assertions, 14 performance-meter cases, shader task
coverage and selected profiles, Windows timer policy restoration, and actual
Native / 2× / 4× scanout dimensions with independent pixel detail. The latest
fullscreen 2× repeat measured median 33.34 ms, 99th percentile 35.44 ms and maximum
52.55 ms for ordinary game updates. Residual CPU timing spikes remain; do not
claim constant updates or complete driver, scenario or multiplayer stability.
Output above the desktop resolution is subject to Windows window-size limits;
4K output on a 4K display has not been tested.

Sealed kit manifest SHA-256:
`cc558c696ae8be9367ea6e99c94eff62f422972af52417119e8cc11a79de6304`.
Input archive SHA-256:
`9845a96fad91763e59b04908f4ef5fcddd582e620b33811c8df7668586d0dcbe`.
The 60 local-build tests pass with one platform skip; 49 co-op harness tests
pass with one skip. Harness tests do not establish new multiplayer gameplay
coverage.

## v1.0.17

Ship Native / 2× internal resolution, the optional top-right performance counter,
five live audio volume controls, controller rumble and its saved switch, the
fullscreen cursor fix, missing randomized weapon motions and a fresh seed per
solo/host launch. Joining continues to use the host's configuration. Simplify
the Mods/Cheats text and show only the four main readiness checks on Play.

Refresh the frozen v1.0.16 kit. Apply patches `0102-fullscreen-cursor.patch` and
`0103-audio-volume-controls.patch` to that kit's SDK source copy; preserve the
dirty working submodule. Include both patches in the source-update notices.
Replace the independent final presentation shaders with the verified versions
whose push constants include performance readings. Include the new authored
runtime headers; do not distribute a built game or game objects.

Verification workspace: `build-ninja/release-v117`. Actual local launcher-to-room
checks cover 2×/Native, fullscreen, SMAA/direct presentation, the performance
counter on/off, live audio, rumble/cursor checks and randomized grenade launcher
ready/fire behavior. Performance-counter checks pass 14 cases, actual audio
mixing passes 465 cases and the launcher passes 445 assertions. The 2× fullscreen
randomizer run measured about 29.98 gameplay updates/s during ordinary active
gameplay. Keep the RX 570 command-checkpoint compatibility workaround; the
underlying driver/ordering cause has not been demonstrated to be repaired.

The reference executable incrementally reuses unchanged verified generated/SDK
objects and recompiles changed authored/runtime units. Validate source and object
correspondence with the new sealed kit; disclose that a complete cold first-run
compilation is not repeated. Existing co-op verification belongs to v1.0.16;
separate-PC/WAN play, later-room mixed enemies, save/resume and full-scenario
completion remain unverified. Include `<!-- reo:requires-rebuild -->`.

Sealed kit manifest SHA-256:
`ef36a0fec0200a0917211bc983b745dbbe82d0e11b84341a9ac62686fa3bc0f6`.
Input archive SHA-256:
`9ea4222f2ef1a734c0dbdad2a1437876e81d02754c964d09c3795e870b897857`.
The 60 local-build tests pass with one platform skip; the 49 co-op harness
tests pass with one skip. The dependency source base remains unchanged.

## v1.0.16

Ship the separate global weapon, ammunition and common-item pools, corrected pickup model hierarchy/material handling, expanded experimental enemy roster, protocol-3 host plans, DualSense health lights and corrected ammunition/progression cheats. Preserve progression keys, starting equipment and original scripted enemy families. Scripted enemy identity is captured before native reconstruction can clear its behavior; this prevents different maximum health on network peers.

Refresh the frozen v1.0.15 kit with the authored cheat/mod headers and new `runtime/mods/global_items.h`; update `metadata/overlay_maps/ovl9.csv` with the two original G/Thanatos continuation entries. Preserve the frozen SDK and existing dirty submodule. Do not copy an unrelated locally rebuilt SDK into the release.

Final kit manifest SHA-256: `99211d381dca110cc6044472a8ea04938985981f0e34f8f55119d2d38e34e957`.
Input archive SHA-256: `91d0b38473ad2e7ac06e0f110e1bdac7251a51df7cca21b204f39b81915d3db5`.
The corresponding frozen dependency archive is unchanged and is renamed for this release. Include `<!-- reo:requires-rebuild -->` in release notes.

Verification workspace: `build-ninja/release-v116`. Regeneration reproduced all existing ordinary guest bodies byte-for-byte; the only ordinary changes were two added original o9 functions and their registration. The local native test executable reuses verified unchanged game/SDK objects and freshly compiles the authored bootstrap plus those two functions; this is a source-equivalence/object-reuse check, not a second full clean compilation. Native fixtures, 375 launcher assertions, 60 local-build tests (one Windows skip) and 49 co-op harness tests (one skip) pass. Offline checks covered pickup/equip/firing, health/infection/ammunition cheats, unlock menus and fullscreen window bounds.

Two real native clients in a private loopback network room verified movement, pickup ownership/removal, duplicate prevention and ammunition updates. An initial combat mismatch is retained as failed evidence. The corrected 419.9-second repeat had matching enemy maximum health and eventual damage agreement. Combat updates can still arrive several seconds late during grabs. Later-room mixed-species combat, separate-PC/WAN play, reconnects, save/resume and full scenario completion remain unverified. Preserve those limits in the release notes.

## v1.0.15

Ship the unified `examples/mods/randomizer.json` package and the Mods UI, including migration of the retired samples and removal of Practice Mode. Native hooks add item/gun and seeded enemy spawn randomization, persistent spawn choices, original entrance handoffs, host-controlled settings and an optional 32 MB native asset bank.

Refresh `inputs-v113f` using its unchanged recompiler, replacing `recomp/reo_bootstrap.cpp`, `recomp/overrides/reo_hw_bridge.cpp`, `recomp/overrides/reo_missing_entries.cpp` and the eight runtime files in patch `0100-optional-native-asset-bank.patch`. Add `recomp/overrides/reo_mods.h` and the three `runtime/mods/*.h` headers. Keep generated instruction catalogues from the previous kit rather than copying local developer witness tables. Preserve the dirty submodule.

Apply `0101-unbound-source-witness-fast-path.patch` to the frozen SDK copy and update `tools/parallel_gs_backend/resident_geometry/guarded_source_overlay.hpp`. Ordinary CPU execution skips instruction/store witnesses only when neither a bound source owner (including tombstones) nor the first-entry audit needs them. The main repository's working submodule keeps its existing edits; the independent patch reproduces the changes in a sealed kit.

Normal player builds generate plain CPU game code for every executable and overlay pass. `generate_game.py --source-audit` explicitly enables developer source witnesses. Exact tracked inputs for the 25 authored audit/IRQ helper recipes are generated separately; their base and result hashes remain enforced. They are excluded from the ordinary gameplay source groups. The bootstrap rejects graphics source auditing with a player build rather than claiming to provide witnesses it did not generate.

Kit manifest SHA-256: `18e04105d5c2a980d74e2a17a0706fc46dab6c15cbe7d6c6608fd3052cce58c8`.
Input archive SHA-256: `0d3aa0a01db13da091fcb99503167cb331b44944f110b47f54c64ab95e95d45d`.
The frozen dependency source archive is unchanged; additional matching SDK patches remain in the input kit's `notices/source-updates`. New runtime headers require a full compilation and the release notes must contain `<!-- reo:requires-rebuild -->`.

Verification workspace: `build-ninja/release-v115`; the existing `release-v112/verify/work` supplies resumable object storage. No built game is distributed. Full scenario completion, save/resume and mixed-enemy co-op gameplay are unverified and must remain disclosed.

The tracked portable builds measured 12.8 and 14.3 original game updates/s while presentation reported 60 calls/s. The earlier working native build uses plain generated gameplay and measured 30.00 updates/s. The corrected portable code measured 29.95 updates/s over a read-only 20-second room sample (`sessions/20261022-222853-561/live-clock.json`); presentation counts do not establish gameplay speed. Generated-source verification confirms the same 17,503 ordinary source paths and 17,487 plain guest bodies, with no per-instruction tracking in those bodies. All 60 local-build tests pass (one Linux-only test skipped on Windows). Native source-witness checks pass 985 synthetic binding cases covering enabled audits, owners/tombstones, RAM/MMIO/wrapping writes, faults and 128-bit values. Item fixtures verify byte-for-byte preservation of scenario-key and personal pickup records across seeds.

## v1.0.13

**Movies on GPUs without a hardware MPEG-2 decoder.** An RX 9060 XT system (and its
Ryzen 7000 integrated Radeon) exposes no D3D11 MPEG-2 VLD profile, so the GPU movie route
stopped at the first movie ("Initialize full hardware MPEG2 VLD"). The launcher now runs
`reo-movie-check.exe` (`launcher/native/movie_decoder_check.cpp`, built by `build.ps1`)
before each launch: it repeats Granite's device choice through Vulkan and the
`Mpeg2VldCore` acceptance test on that adapter's LUID, and `GameSession` sets
`REO_GPU_MOVIE=1` only on a clear yes. `tools/diagnostics/video_decoder_probe.cpp` lists
every adapter's decoder profiles for support reports.

**CPU movie and gameplay speed.** The original CPU decoder ran at 4-5 fps and gameplay
advanced about 9 game updates per second on a Ryzen 5 2600: every generated instruction
and register access went through source-guard instrumentation, and every memory-mapped
register write called `getenv`. Fixes: PS2Recomp patches `0098` (inline unbound paths,
cached switches, `refuseUnguardedSource`) and `0099` (`PS2RECOMP_UNGUARDED_RANGES`,
`ps2_plain_access_begin/end.hpp`), the inline unbound read in `guarded_source_overlay.hpp`,
and `generate_game.py` passing the libmpeg range 0x142000-0x147FFF to the main and extra
passes (95 functions). Measured on the Ryzen 5 2600: CPU movies 27-31 fps (23-25 in the
heaviest title-movie scene; stream 29.97); first room reached at 57 s instead of 101 s;
gameplay 29.6 game updates/s instead of 9.0 (`clock_units` in the gameplay route's
`clock.csv`). Check that rate in future release tests.

Compiling the inline accessors costs more: `main693` (the 1.1 MB generated outlier) now
takes over 20 minutes alone and peak compiler memory is higher.

Kit: refreshed from `inputs-v112h` with the patched recompiler
(`build-ninja/recompiler-unguarded`, `code_generator.cpp` per patch 0099, other objects from
the shipped recompiler; a control build of the unpatched source reproduced the shipped
object byte for byte):

```
python tools/local_build/refresh_inputs.py --kit build-ninja/slim-release/inputs-v112h \
  --output <new> --archive <new>.zip --recompiler build-ninja/recompiler-unguarded/ps2_recomp.exe \
  --dependency-sources <RE-Outbreak-v1.0.12-Dependency-Sources.zip> --version 1.0.13 \
  --update-source third_party/PS2Recomp/ps2xRuntime/src/lib/parent_natural_runtime.h \
  --update-source third_party/PS2Recomp/ps2xRuntime/src/lib/parent_natural_dispatch.cpp \
  --update-source third_party/PS2Recomp/ps2xRuntime/src/lib/source_instruction_access.hpp \
  --update-source third_party/PS2Recomp/ps2xRuntime/src/lib/resident_vif_live_hooks.cpp \
  --update-source tools/parallel_gs_backend/resident_geometry/guarded_source_overlay.hpp \
  --add-source third_party/PS2Recomp/ps2xRuntime/include/ps2_plain_access_begin.hpp \
  --add-source third_party/PS2Recomp/ps2xRuntime/include/ps2_plain_access_end.hpp
```

Kit `build-ninja/slim-release/inputs-v113f`, manifest
29d3e480ab9f183f1d9e4f76e1ac7fdcffe0ac327167b052ce1c3bfe4019f36a; archive
`build-inputs-v113f.zip`, SHA-256
2c7d45bb839c162aae8f9a214c5bf31b1e5d925bf096dea4f5d6fbe161860873. Headers changed, so
updating players rebuild every unit once.

## v1.0.12

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
