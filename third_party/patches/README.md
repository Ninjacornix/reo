# Dependency patches

These patches change dependency checkouts; they are stored here so the dependency source and local changes remain reproducible and reviewable.

## PS2Recomp

`tools/setup_deps.ps1` checks out its pinned PS2Recomp commit under `third_party/PS2Recomp`, then applies `ps2recomp/*.patch` in filename order. It checks whether each patch is already applied before applying it again. The patched dependency builds the runtime library used by the game.

The submodule records the upstream base, not the uncommitted patched state. Every required local change must therefore be represented in the patch series. A modified dependency checkout alone is not a reproducible public contribution.

The current series contains patches `0001` through `0095`. Patch `0092` applies
without depending on an unpublished instrumentation include. Patch `0093`
collects the authored host/runtime integration, async VIF1 worker, window
shortcuts and thread-termination wake fix. Its predecessor focused patches are
preserved under `ps2recomp-history/` for review and are not applied twice.
The complete current series has been checked against a fresh pinned worktree.
Patch `0094` makes an explicit function-map range replace a discovered range at
the same address, preventing local regeneration from extending into later data.
Patch `0095` makes integer types and optional stack diagnostics portable to Linux.

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
