# First-time build performance

The [compilation measurements](COMPILATION_PERFORMANCE.md) include a complete
cold build: scheduling alone reduced 79m31s to 69m45s (12.3% less time), with all
2,382 objects byte-identical. This is the compilation improvement in v1.0.11.
The larger-batch experiment finished in 65m09s but changed one guest function's
machine code; it is excluded from the release.
Scheduling, bounded concurrency and planning changed; compiler flags and guest
sources were preserved.

The broader [import profile](IMPORT_PROFILE.md) measures fresh extraction,
compiler setup, all generation, ten compile samples, pathological units, cache
hashing, and relinking. It supersedes the small sample below for prioritization.
The candidate reduces the real worker's preparation/generation from 13 min 42 s
to 1 min 34 s (88.5%), with byte-identical guest sources. Generator scans,
parallel generation/verification, ordered registration chunks and buffered C#
hashing are implemented. This is not a full first-compilation measurement, and
these changes are included in v1.0.11.

A completed compatible game build is the fastest path: no compiler work is needed.
Game files > Use existing build accepts reo_recomp.exe from a completed launcher
build with its local-build.json record and companion files. It validates the exact
kit/game/architecture and output hashes, copies into the local cache transactionally,
and skips compilation on the next launch. It does not run the selected EXE during
validation. A supported ISO remains required for game assets. A receipt is an
integrity/compatibility record, not a publisher signature or a malware check.

Existing local caches are found automatically. The import action helps move a
completed build from another folder or an earlier installation using the same kit.
Keep the entire ready folder. A bare EXE or an incompatible older kit cannot be
silently treated as compatible. A failed or cancelled import preserves the prior
build and source folder.

## What the implementation already does

- Reuses verified complete games and completed object files after interruption.
- Precompiles shared generated-code headers.
- Groups generated functions into batches, normally eight functions up to about
  500 KB of source per compilation unit; large individual functions remain large.
- The v1.0.10 kit compiled up to four units in parallel. The v1.0.11 worker
  admits up to 32 with CPU/memory limits and large-unit reservations.
  The measured full build requested seven; larger-machine gains are unmeasured.
- Uses the pinned native Windows x64 compiler with O2 and existing floating-point
  and integer-behavior flags. This update does not lower game optimization.

The previous complete reference build compiled 2,381 units. Its private object
files total about 1.26 GB. The current portable plan has 119 authored/runtime units
plus generated groups and seven independent archive inputs. Counts alone do not
establish which stage consumes most wall time.

## Small profiling sample, 2026-10-20

Two existing reference units were compiled separately with the pinned compiler,
shared PCH, unchanged O2 flags and Clang time tracing. No full game was rebuilt or
launched. These are samples from an older frozen reference, not a prediction for
all PCs or the whole game.

| Unit | Wall time | Frontend | Backend | Register allocator |
| --- | ---: | ---: | ---: | ---: |
| main0 | 8.750 s | 1.713 s | 5.821 s | 4.559 s |
| main5 | 1.891 s | 0.879 s | 0.883 s | 0.014 s |

Compiler totals and pass timings are nested/overlapping; do not add these columns.
`main0` is host registration code, rather than guest geometry. It spends much
of its time in machine-code register allocation. The
smaller unit has a different balance, including about 0.538 s in LLVM optimization.
This argues against assuming that changing one optimization level fixes every unit.

An earlier PCH comparison for a small sample measured 3.485 s without and 1.625 s
with shared headers. Another heavier sample improved only from 9.672 to 8.390 s.
PCH is already enabled. Object files were not byte-identical in those comparisons;
these measurements are not a correctness or gameplay-equivalence proof.

## Remaining candidates

1. Improve cold scheduling estimates for functions whose optimizer cost is high
   despite a modest source size. Any future change needs another measured comparison.
   Larger batches also need the single-function code difference resolved before admission.
2. Investigate emitting smaller functions or reducing temporary-register pressure
   for pathological generated functions. Guest resume points, yield behavior and
   floating-point/integer semantics must remain identical.
3. Evaluate further PCH/frontend improvements for non-generated units, with compiled
   output comparisons. Broad preincludes can change macro/include behavior and
   are not enabled by the current scheduling update.
4. Prebuild additional independent runtime components where they do not contain or
   depend on reconstructed game instruction data. Much upstream code is already
   prebuilt; the remaining safe subset and actual time saved need an audit.

Changing generator/worker inputs creates a new kit identity and can invalidate
cached objects/games. Launcher-only releases continue to reuse the frozen v1.0.6
inputs rather than forcing an unnecessary full rebuild. The complete scheduling
comparison measures compilation, not the download-to-play first-install duration.

References: [Clang time tracing](https://clang.llvm.org/docs/ClangCommandLineReference.html#cmdoption-clang-ftime-trace),
[precompiled headers](https://clang.llvm.org/docs/PCHInternals.html),
[LLVM register allocation](https://llvm.org/docs/CodeGenerator.html#register-allocation),
and [memory-aware parallel builds](https://llvm.org/docs/CMake.html).
