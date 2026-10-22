# Dependency patches

These patches change dependency checkouts; they are stored here so the dependency source and local changes remain reproducible and reviewable.

## PS2Recomp

`tools/setup_deps.ps1` checks out its pinned PS2Recomp commit under `third_party/PS2Recomp`, then applies `ps2recomp/*.patch` in filename order. It checks whether each patch is already applied before applying it again. The patched dependency builds the runtime library used by the game.

The submodule records the upstream base, not the uncommitted patched state. Every required local change must therefore be represented in the patch series. A modified dependency checkout alone is not a reproducible public contribution.

The current series contains patches `0001` through `0099`. Patch `0092` applies
without depending on an unpublished instrumentation include. Patch `0093`
collects the authored host/runtime integration, async VIF1 worker, window
shortcuts and thread-termination wake fix. Its predecessor focused patches are
preserved under `ps2recomp-history/` for review and are not applied twice.
The complete current series has been checked against a fresh pinned worktree.
Patch `0094` makes an explicit function-map range replace a discovered range at
the same address, preventing local regeneration from extending into later data.
Patch `0095` makes integer types and optional stack diagnostics portable to Linux.
Patch `0096` speeds up source instrumentation (see the v1.0.11 notes). Patch `0097` clears
the pending movie DMA publication explicitly when the final tag takes it over: a moved-from
`std::function` is not guaranteed empty, and with libc++ (the llvm-mingw release toolchain) a
leftover copy stopped every release-built game at its first GPU movie.

Patches `0098` and `0099` remove source-guard overhead that slowed the whole game while no
source owner is bound, which is always the case in release builds. Profiling showed the
original CPU movie decoder (needed on GPUs without a hardware MPEG-2 decoder, such as AMD
RDNA 4) at 4-5 frames per second against the stream's 29.97, and gameplay advancing about
9 game updates per second instead of 30. With both patches and the matching inline paths in
`tools/parallel_gs_backend/resident_geometry/guarded_source_overlay.hpp`, a Ryzen 5 2600
plays movies at 27-31 fps (23-25 in the heaviest scene) and gameplay at 29.6 updates/s:

- `0098` (runtime): generated register/context accessors take an inline plain copy while no
  owner is bound, which is when the guarded lookup finds no target and does exactly that
  copy; resident-wait switches are read from the environment once instead of on every
  memory-mapped register write; and `refuseUnguardedSource` stops the game if code emitted
  without guards runs while an owner is bound.
- `0099` (generator): `PS2RECOMP_UNGUARDED_RANGES` names guest address ranges emitted
  without source instrumentation. `tools/local_build/generate_game.py` passes the game's
  libmpeg decoder, 0x142000-0x147FFF, to the main and extra passes (95 functions). No source
  owner reads it, and owners are only bound by the resident GPU geometry path, which release
  launchers leave off. Those bodies are wrapped in the new `ps2_plain_access_begin.hpp` /
  `ps2_plain_access_end.hpp` (generated from `ps2_runtime_macros.h`): a compile batch shares a
  translation unit, and an earlier instrumented file would otherwise leave the guarded
  register/memory accessor macros in effect.

Locally generated game bodies, including instrumented original IRQ functions,
remain excluded. Applying the runtime patches is not a substitute for generating
game code from the user's supported disc. Experimental graphics source builds
still require their matching local generated bodies and graphics dependencies;
see [the build guide](../../docs/BUILDING.md).

When updating the dependency:

1. Start with a separate checkout at the recorded base; keep active build checkouts intact.
2. Apply the existing series and verify the result.
3. Export the new focused dependency change as the next numbered patch.
4. Apply the entire series to another clean checkout and run the affected checks.

Keep the dependency's license and attribution. Do not run checkout/reset over somebody else's modified submodule to test a series.

Patch 0096 optimizes source-guard matching without changing its patterns or
refusal rules. It must be compiled into the independent recompiler used in a
new kit; changing the separate root header does not update an old tool binary.
The import benchmark compares all generated guest files and ordered registration
results against the pre-patch tool; see [the report](../../docs/IMPORT_PROFILE.md).

## paraLLEl-GS

`parallel-gs/` contains graphics dependency patches. The ordinary setup script does **not** apply this series or build its full GPU dependency graph. A GPU build must use the matching source revision, libraries and patch series. Do not assume that the PS2Recomp setup also configures paraLLEl-GS.

Some current GPU integration paths remain local experiments; see [the build guide](../../docs/BUILDING.md). Changes still present only in a local dependency tree need a reproducible patch before release.

The runtime witness catalogues contain addresses only in published metadata.
After extracting your own supported ELF, generate their instruction words locally:

```powershell
python tools/local_build/generate_catalogues.py --elf game_data/SLUS_207.65 --manifest recomp/config/local_source_catalogues.json --output third_party/PS2Recomp/ps2xRuntime/src/lib/local_source_catalogues
```

Do this after applying the runtime patch series and before compiling affected
runtime sources. These generated `.inc` files must remain local.

Patch 0100 adds optional 64 MB native memory backing for enemy assets while retaining the original 32 MB console heap, stack and reported RAM size. CPU memory helpers, disc reads and DMA paths use the configured backing size. The default remains 32 MB. The Randomizer requests the additional bank before guest execution.
