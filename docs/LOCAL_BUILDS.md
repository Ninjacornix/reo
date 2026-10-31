# Local build distribution

The precompiled v1.0.0 prerelease is withdrawn. Portable releases generate game
code locally from the user's verified disc.

In v1.0.8, players choose a supported ISO in the launcher. Import verifies the
disc, downloads and prepares the pinned Windows x64 compiler automatically, then
generates and builds the game. No compiler installation, environment variables or
terminal commands are needed. Progress, approximate stage ETAs and cancellation
are available throughout setup. First compilation still takes substantial time;
completed game builds are cached for later launches.

The manual toolchain paths below are maintainer options. An existing compatible
REO_LLVM_MINGW override remains supported, but ordinary players leave it unset.

The public package contains the launcher, independent recompiler, source metadata,
authored runtime sources and independent upstream libraries. The user's verified
disc supplies main/overlay instructions and VU microprogram images. The final
executable, instrumentation copies, instruction witnesses and VU translations are
generated, compiled and cached in the selected data folder (`data/` beside the launcher by default).

The Windows release must be portable: open the launcher EXE and select an ISO,
without a Windows installer or system toolchain installation. Independent build
tools may be unpacked into a private cache on first use. Later launches reuse
verified cached outputs without compiling.

The portable Windows exporter and compiler worker now support the pinned
LLVM/MinGW UCRT toolchain. Independent libraries and the recompiler are built with
that same toolchain; MSVC C++ archives are not reused. RC0 was tested through the extracted Windows launcher: supported-disc import,
local generation/compilation, actual room entry and cached Play passed for both
games. The test used a path with spaces and non-ASCII characters, an unrelated
working directory and a system-only PATH. Compiler-unavailable cache checks
confirmed completed games launch without compiling again. The compiler was
restored and hash-verified afterward. The Windows ZIP bundles the launcher's
.NET runtime; players do not need a separate .NET installation.

File #2's final portable native also repeated actual randomized pickup, equip,
firing and enemy reconstruction/combat/death checks. See
[File #2 validation](FILE2_RANDOMIZER.md) for exact scope and remaining limits.
These results establish the tested Windows machine and routes, rather than all
hardware, discs, scenarios, saves or multiplayer sessions.
Legacy MSVC development kits continue to require existing Microsoft tools; the
launcher never installs them.

## Maintainer workflow

For an audited generation-only update, `tools/local_build/refresh_inputs.py`
creates a new kit from a fully verified old kit and an explicitly supplied rebuilt
independent recompiler. It updates generation/compiler workers, ordered registration
chunking, the scheduling helper and the corresponding source-guard patch.
The release keeps the original eight-file batches; runtime/library inputs remain
unchanged. Supply fresh `--output` and optional `--archive` paths. Never overwrite
a sealed kit or substitute a compiler from a different source revision. For a
release, supply `--dependency-sources` and `--version` together to record the
matching separately published source archive and its digest. See
[the measured import comparison](IMPORT_PROFILE.md) for parity checks and the
completed build comparisons. The script does not publish releases.

RC2 networking adds compiled source units. When refreshing a pre-RC2 kit, copy
`native_netcode.cpp/.h`, `game_netcode.h` and `world_sync.cpp/.h` from
`network/native/` with `--add-source`, update the transport and the edition's
network override, and add both `.cpp` units to **both** compile plans:

```text
--add-unit network/native/native_netcode.cpp=network/native/snap_iop_transport.cpp
--add-unit network/native/world_sync.cpp=network/native/snap_iop_transport.cpp
```

Each new unit inherits the existing transport unit's audited include/define
options. A fresh CMake export already includes these units. RC1's frozen server
component is rejected by the RC2 exporter; use `--checkout` at the pinned server
revision described in [the server workflow](../network/server/README.md).

The exporter currently consumes the validated developer build's compilation
database, source-unit inventory and runtime build records. It is not yet a
clean-clone release pipeline. Preserve these inputs when preparing a kit.

1. Export from a frozen source/dependency revision with `tools/local_build/export_kit.py`.
   Use the dependency tree with the published patches applied, including the
   sanitized catalogue headers. Do not substitute dirty generated instruction tables.
2. Include exact independent dependency source/licence trees with
   `export_sdk_sources.py`. Audit any precompiled library before declaring it an
   independent upstream input.
   For Windows, build independent components with
   `tools/local_build/windows_sdk/CMakeLists.txt`, then run
   `export_portable_windows.py` with the pinned toolchain archive, MinGW libraries
   and matching recompiler. Preserve the `.cfg` compiler files and runtime DLLs.
3. Seal a fresh kit with `seal_kit.py` and the pinned Python embeddable ZIP.
   The manifest hashes every input and selects the local generation/compiler worker.
4. Test with a verified disc import in a new private workspace. Compile every
   game-derived object locally, link, then validate the actual launcher-to-room route.
   Check a second launch uses the completed cache and cancellation never admits a
   partial output. Synthetic tests alone are insufficient for publishing a kit.
5. Package the independent kit and self-contained launcher only after those checks.
   Do not copy `reo_recomp.exe`, game objects, translated game shaders, extracted
   assets, developer caches, save data or local artwork into a public package.

An explicitly requested **build-only prerelease** may use
`package-local.ps1 -BuildOnlyPrerelease` without another room run. It still
requires a completed build, verified correspondence between compiled and sealed
inputs, a matching manifest hash and all source/licence inventory checks.
Record `roomRoutePassed=false` and disclose the omitted validation in the
release notes; do not turn an omitted run into a passing result.

See [prerelease preparation](PRERELEASE.md) for artifact naming, source notices
and publication steps. Packaging a source snapshot is separate from producing a
playable download; do not label an unfinished platform as a release asset.

The Co-op hosting component is exported separately with
`tools/local_build/export_server.py --checkout PINNED_OPENSNAP --python-zip PYTHON_ZIP --output NEW_DIRECTORY`.
Use native Windows x64 Python 3.12 for that exporter. It produces a portable
Python/server component with the patched AGPL source, dependency sources/notices,
and a hashed `server-manifest.json`. Pass it as `-Server` to
`launcher/package-local.ps1`; never copy a running server's virtual environment,
database or developer `.env`. The launcher owns service startup/stop and keeps
persistent hosting data outside the portable application.

Runtime and graphics-backend translation units that include local instruction
witnesses are compiled locally too. Whole-program and specialized VU optimizations
are reconstructed from the verified ELF, preserving their exact image identities.
The historical captured overlay fallback is replaced by dispatch adapters to the
currently loaded, disc-derived overlay; an unresolved adapter fails explicitly.

Build logs and reusable object receipts stay in the private workspace. A cache key
includes the build-kit manifest, supported ELF hash and architecture. Completed
files are hashed and admitted only after the complete pipeline succeeds.

**Long paths.** Windows long paths are off by default, so Python opens files through
the 259-character limit. Build files nest about 180 characters below the data folder
and kit sources about 250, which broke rc0 builds in data folders over ~80 characters.
`tools/local_build/long_paths.py` gives the rule: `build_game.py` turns its kit, disc,
work and output roots into extended (`\\?\`) paths, so every derived Python path is
extended; anything handed to a native tool (recompiler config/arguments, compiler
arguments, response files, generated `#include` lines, `PATH`) goes through `native()`.
LLVM and the patched recompiler lengthen ordinary paths themselves. Build paths only
through `pathlib`: an extended path does not treat `/` as a separator. Windows still
refuses to start a program, or run it in a folder, past 259 characters; the launcher
therefore rejects data folders longer than 150 characters before building.

## Linux

Native Linux implementation has started in [launcher/linux](../launcher/linux/README.md),
but no playable Linux release is available. The disc extraction,
function metadata, source recipes and VU reconstruction are shared Python tools.
A Linux kit must supply its own native recompiler, runtime/dependency libraries,
Clang build worker and platform-specific manifest. It must generate the same game
code from the same supported disc; no Windows SDK libraries or game objects should
be bundled as a shortcut.

The Windows launcher is WPF; the new Linux frontend uses Qt. Windows-only input,
display, movie decoding and thread/scheduler paths also
need Linux implementations and gameplay validation. Running under Wine/Proton
would be a separate compatibility target, not evidence of a native Linux port.
No Linux download should be offered until the same installation and room-route
checks pass on Linux hardware.

## Publication checks

Run `python tools/publication_audit.py --history`. This rejects known excluded
paths and instruction dumps; it is a technical check, not copyright clearance.
Keep publisher imagery and game-derived code out of documentation captures too.

The published branches were rewritten after withdrawing the prerelease. GitHub
may retain old objects, pull-request refs or cached raw-file URLs after rewriting.
The repository owner must request removal of remaining cached objects through
GitHub Support. Existing third-party clones/downloads cannot be recalled.
