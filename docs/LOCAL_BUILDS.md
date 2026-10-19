# Local build distribution

The precompiled v1.0.0 prerelease has been withdrawn. A replacement downloadable
game is not yet available. Local build-kit verification is in progress.

The public package contains the launcher, independent recompiler, source metadata,
authored runtime sources and independent upstream libraries. The user's verified
disc supplies main/overlay instructions and VU microprogram images. The final
executable, instrumentation copies, instruction witnesses and VU translations are
generated and compiled in Local AppData, then cached outside the installation.

The first setup needs Microsoft C++ Build Tools 2022 and a Windows SDK. The
launcher reuses a compatible installation or offers Microsoft's signed installer.
Installation remains interactive; the launcher does not silently accept licence
terms or reboot Windows. Python is bundled as the pinned official embeddable
distribution. Later launches reuse verified cached outputs without compiling.

## Maintainer workflow

The exporter currently consumes the validated developer build's compilation
database, source-unit inventory and runtime build records. It is not yet a
clean-clone release pipeline. Preserve these inputs when preparing a kit.

1. Export from a frozen source/dependency revision with `tools/local_build/export_kit.py`.
   Use the dependency tree with the published patches applied, including the
   sanitized catalogue headers. Do not substitute dirty generated instruction tables.
2. Include exact independent dependency source/licence trees with
   `export_sdk_sources.py`. Audit any precompiled library before declaring it an
   independent upstream input.
3. Seal a fresh kit with `seal_kit.py` and the pinned Python embeddable ZIP.
   The manifest hashes every input and selects the local generation/compiler worker.
4. Test with a verified disc import in a new private workspace. Compile every
   game-derived object locally, link, then validate the actual launcher-to-room route.
   Check a second launch uses the completed cache and cancellation never admits a
   partial output. Synthetic tests alone are insufficient for publishing a kit.
5. Package the independent kit and self-contained launcher only after those checks.
   Do not copy `reo_recomp.exe`, game objects, translated game shaders, extracted
   assets, developer caches, save data or local artwork into a public package.

Runtime and graphics-backend translation units that include local instruction
witnesses are compiled locally too. Whole-program and specialized VU optimizations
are reconstructed from the verified ELF, preserving their exact image identities.
The historical captured overlay fallback is replaced by dispatch adapters to the
currently loaded, disc-derived overlay; an unresolved adapter fails explicitly.

Build logs and reusable object receipts stay in the private workspace. A cache key
includes the build-kit manifest, supported ELF hash and architecture. Completed
files are hashed and admitted only after the complete pipeline succeeds.

## Publication checks

Run `python tools/publication_audit.py --history`. This rejects known excluded
paths and instruction dumps; it is a technical check, not copyright clearance.
Keep publisher imagery and game-derived code out of documentation captures too.

The published branches were rewritten after withdrawing the prerelease. GitHub
may retain old objects, pull-request refs or cached raw-file URLs after rewriting.
The repository owner must request removal of remaining cached objects through
GitHub Support. Existing third-party clones/downloads cannot be recalled.
