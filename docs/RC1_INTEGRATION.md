# RC1 integration on develop

The seven requested branches were merged into `develop` in dependency order.
The starting commit was `9d9e089184c16f35caa9169f2805d185dd52e880`.
This integration does not publish RC1 or change `main` or the RC0 release branch.

| Order | Branch | Audited tip |
| --- | --- | --- |
| 1 | `fix/issue-26-scenario-runtime` | `b021125` |
| 2 | `fix/issue-28-dualsense-bluetooth` | `6a13f1e` |
| 3 | `perf/background-video-composition` | `9ac4d30` |
| 4 | `fix/issue-2-rc1-build-paths` | `4d533fa` |
| 5 | `feature/issue-29-file2-unlocks` | `08efc02` |
| 6 | `feature/asset-paks` | `a4f8363` |
| 7 | `feature/launcher-overhaul` | `a06e422` |

The background branch is an ancestor of the build-path fixes, which are an
ancestor of the File #2 unlock branch. Asset PAK support already contains the
scenario runtime fixes. The controller branch includes the portable RC0 build
foundations. Explicit merge commits retain the seven branch histories.

## Integration resolutions

- Keep the newer controller discovery and Bluetooth support, portable packaging
  fixes, and the RC0 validation history alongside background playback.
- Retain game-specific File #2 unlocks and their capability check alongside the
  overhaul's additional cheat controls. Both editions expose six built-ins;
  capability checks still reject unsupported native builds.
- Keep the redesigned Game files page and add the PAK source switch, original
  asset export actions, and manual old-import cleanup. Readiness labels follow
  the selected source, including the inactive edition's measured Play notice.
- Preserve both games' JSON mod configuration and deletion while retaining PAK
  mod import, selection, runtime preparation and source capability checks.
- Preserve both the portable File #2 export closure and the asset-overlay SDK
  requirement in build-kit export.
- Catch invalid ISO data in the merged validation path. Otherwise an invalid
  source could repeatedly restart validation without recording its failure.

## Integration checks

- Clean launcher build through `launcher/build.ps1`, including native controller,
  movie-check and Direct3D preview components; subsequent Release builds have
  zero warnings and errors.
- 1,210 launcher self-checks, including regression checks for the merged File #2
  unlock capability verifier.
- 119 WPF interaction checks: Game files 23, Cheats 20, Mods 57, Launcher 19.
  Game files checks cover ISO/PAK switching, retained source paths, export and
  cleanup controls, invalid-source errors, and launch-time locking.
- 98 local-build Python tests, with 11 environment-dependent skips.
- 13 asset-tool Python tests, with two skips requiring a separately compiled
  virtual-AFS probe.
- Native cheat suite: 55 general checks and 76 File #2 checks, plus the separate
  22-check File #2 progression suite. Randomizer checks also pass.

UI checks use isolated fixture data. No game was launched for this merge, no
complete scenario was replayed, and no final release package or fresh native
game build was produced. The final RC1 inspection and packaging checks remain.

## Items for final RC1 inspection

The follow-up native integration supplies the spoken-subtitle hooks, per-game
Windows audio endpoint selection, maximum results points and infinite escape
time, including their native tests and local-build export inputs. It retains
File #2 progression unlocks and the asset PAK bootstrap. These changes require
fresh native builds; existing game executables do not gain the new behavior from
a launcher update alone.

The File #2 audio follow-up also supplies independent Music, Sound effects,
Voice and Interface routing, with original sound-bank PCM and live IPC checks.
Its launcher rejects older Master-only native builds and requests a rebuild.
See [File #2 audio verification](FILE2_AUDIO.md).

Both editions now receive the bundled Randomizer on first use, disabled by
default. Existing packages and enabled selections are preserved. The per-edition
initialization preference remembers deletion, so visiting Mods does not silently
restore a removed package.

Follow-up checks include the original owned dialogue queues for both games,
original generated countdown services, full-RAM results-point write boundaries,
and real Windows default, selected and missing audio endpoint initialization.
These controlled native checks do not represent a fresh full-game release build.
See [subtitle verification](../tools/subtitle_check/README.md).

Refresh both asset-capable local-build kits and perform the final merged-tree
native rebuild, first-run, cached-launch, scenario and packaging checks before
publishing RC1. See [asset PAK requirements](ASSET_PAKS_IMPLEMENTATION.md),
[prerelease checks](PRERELEASE.md), [scenario verification](SCENARIO_RUNTIME.md)
and [File #2 unlock verification](FILE2_UNLOCKS.md).
