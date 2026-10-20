# Compilation optimization — v1.0.11

The scheduling candidate uses a bounded queue that prioritizes expensive work and can use
up to 32 workers when CPU and memory permit. The generated sources, compiler
optimization/FP flags, source grouping, archive member order and link input order
are unchanged in the scheduling-only comparison.

**v1.0.11 retains the original eight-file batches** and ships the scheduling
improvement: **79m31s to 69m45s (12.3% less time)**. The separate 64-file experiment
finished in 65m09s but changed one guest function's machine code. It was rejected
by the final comparison and is not in the release.

## Measured results

Same Ryzen 5 2600 / 16 GB Windows machine and pinned LLVM/MinGW compiler as the
[import profile](IMPORT_PROFILE.md). The old worker is the unchanged frozen kit
version. The candidate uses the same kit, source workspace and toolchain, with
separate output directories. Generation was not included in these timings.

| Workload | Old, 4 workers | Candidate, up to 7 | Less time |
| --- | ---: | ---: | ---: |
| 32 mixed main/overlay, runtime and backend units | 43.12 s | 32.20 s | **25.3%** |
| All 119 explicitly listed runtime/backend/VU/authored units | 97.61 s | 78.51 s | **19.6%** |
| Warm compiler preparation, example | about 4.8 s | about 2.5 s | about 48% |
| Complete game: 2,381 compiles, PCH, archives and link | 79m31s | 69m45s | **12.3%** |
| Rejected larger-batch experiment: 975 compiles, PCH, archives and link | 79m31s | 65m09s | 18.1%, not shipped |

Seven was the benchmark's upper limit, not a claim that seven processes were
always active. Larger source units reserve more capacity. Preparation is measured
separately; its first candidate call rebuilt a PCH and is excluded from the warm
comparison. Whole-build scheduling metadata is derived from already collected
file sizes to avoid another walk through every generated source.

All objects in both cohorts were **byte-for-byte identical** between old and new:
32/32 and 119/119. There are 139 distinct units across the two overlapping cohorts.
The complete 2,381-unit plan has identical source lists, per-unit options, default
compiler flags and header fingerprints. Final metadata-size hints were checked
against all actual source files.

The first two rows are cohorts; the final two are complete cold object builds.
OS caches were not flushed, the old/new runs were sequential, and timings vary
with machine load. Do not apply either percentage to the entire first installation
or add it to the separate 88.5% import-preparation reduction. The pathological
guest-function inlining experiment remains excluded from production.

The full comparison saved **585.22 seconds**. The candidate reached six concurrent
compiler processes under its seven-process ceiling. All **2,382 output objects**
(including the resource object) are byte-identical. Compile flags, source files,
archive and linker ordering match. Every executable section and the whole image
also match after excluding only the COFF link timestamp, PE checksum and the
CodeView debug-directory timestamp matching that same link time. Code, data,
unwind information, debug GUID and all other bytes remain checked.

The initial executable comparison stopped at the extra debug timestamp. Direct
inspection found only two changed bytes in `.buildid`; they lie in its documented
four-byte `IMAGE_DEBUG_DIRECTORY.TimeDateStamp` field. The comparer was narrowed
to recognize that field through the PE debug directory, rather than masking the
section. A test confirms that changed code or debug GUID bytes still fail parity.
No executable was changed. These results support unchanged gameplay code for
the scheduling change, not a measured gameplay frame-rate claim.

## What changed

- `launcher/BuildResources.cs` chooses an upper limit of 32 from available CPU
  and physical/commit headroom. The Linux launcher requests the same maximum;
  the native worker performs admission using available memory and Linux cgroup
  limits. Smaller machines automatically run fewer jobs.
- `tools/local_build/build_scheduler.py` keeps only admitted work in the executor,
  prioritizes estimated expensive units, and retains original plan order for the
  caller. Reservations are 1.25 GiB for an ordinary unit and 4 GiB for a source
  over 750,000 bytes that is not a registration list. They are scheduling
  estimates, not OS memory limits. A unit can run alone when its estimate exceeds
  the available reservation capacity, avoiding a stalled queue on smaller machines.
- Successful object receipts record `compileSeconds`. This is advisory scheduling
  history only: input/object hashes still decide cache validity. Missing, invalid
  or malformed cost history is ignored. No object is reused because it was fast
  or because its size/mtime matches. A non-object JSON receipt triggers a rebuild,
  preserving the old worker's behavior instead of failing on a dictionary lookup.
- Header fingerprinting filters suffixes before file-stat calls and hashes with
  up to four readers, combining names/digests in exactly the old sorted order.
  Header edits still invalidate users of inline runtime/ISA operations.
- Source-group planning avoids repeated path-relative calculations when no source
  replacements exist, reuses the same per-file size, and retains size hints for
  scheduling. Overrides retain their original validation path. Actual compilation
  still resolves/validates every input and reads its source digest.
- `compile_game.py` and `compile_linux.py` use the shared queue. Both keep their
  existing compile flags and final archive/link construction order. Compiler errors
  remain failures; neither a failed job nor its partial output is admitted.
- Kit refresh and slim-input export include the helper module together with both
  updated compiler workers. Updating just the launcher cannot replace a frozen
  kit's old four-worker compiler.

Existing generated-code PCHs remain enabled. No broad runtime-header preinclude,
new optimization level, fast-math mode, inlining policy or game function rewrite
was introduced to obtain these results. Cached objects still require verified
source/header/compiler/plan fingerprints and matching object hashes.

## Validation and artifacts

- Windows local-build suite: 43 tests, 42 passed and the optional Linux-only check
  skipped. Actual native fixture compilation covers generated groups/PCH creation,
  archive/link, executable result, cache reuse, header edits, object corruption,
  normal compile failure and preflight failure. These are fabricated programs;
  the game was not run.
- WSL native Linux suite: 43 tests, 39 passed and four platform/tool-specific checks
  skipped. The native Linux compile/archive/link/executable/cache test passed.
  This is not a Linux gameplay or GPU performance measurement.
- Launcher builds with zero warnings/errors and passes all 225 self-checks.
- Scheduling tests cover priority, reservation behavior, progress of a large
  standalone unit, error delivery, unchanged caller order, invalid timing history,
  and exact old/new header fingerprints with header-change detection.
- Final Windows local-build suite: 47 tests, 44 passed and three optional checks
  skipped, after rerunning the registration fixture with its compiler runtime
  DLL directory on PATH. The first fixture invocation failed to load that DLL;
  it was a test-environment issue. Native Windows cache checks include malformed
  receipt recovery. All ten targeted Linux checks also pass under WSL, including
  native compile/link, cache reuse and malformed receipt recovery.

The measured full build requested seven workers. Raising the hardware ceiling
from eight to 32 does not change that run's admission decisions; it allows larger
machines to use their available capacity. A 12-job synchronization fixture verifies
admission above eight while existing low-memory tests retain their bounds. No
high-end-machine speedup is claimed without a measurement on that hardware.

Private evidence directories:

- `build-ninja/compile-optimized-20261020`: mixed-cohort results, object parity,
  native checks, final sealed inputs and summary manifest.
- `build-ninja/compile-runtime-optimized-20261020`: complete 119-unit cohort and
  object parity.
- `build-ninja/compile-final-plan-check-20261020`: final 2,381-unit plan, flags,
  header-fingerprint and size-hint checks.

`tools/import_profile/benchmark_compilation.py` reproduces the cohort comparison
using the actual worker's preparation and nested compile function. `--runtime`
selects all explicitly listed units; `--plan-only` stops before compilation.
The earlier `kit-ready` / `build-inputs-ready.zip` candidate is preserved.
The release kit is sealed separately as `slim-release/inputs-v111-release`.
Its identity differs from previous public kits, so completed games from those
kits require rebuilding. No gameplay run or modification of the active dirty
dependency checkout occurred during this work.

## Follow-up compiler experiments

These experiments use private outputs and are **not enabled in the launcher or
release kit**. The full old/new scheduling comparison has completed. They
overlap that build on the same desktop, so timings are observations under load,
not isolated whole-import predictions.

| Experiment | Observed result | Decision |
| --- | --- | --- |
| Outline owned-access slow paths | `main31` 35.21 s versus the earlier reference 33.64 s | No demonstrated gain; excluded |
| Outline instruction-input bookkeeping | `main31` 40.47 s | Excluded |
| Prevent inlining of complete field-read/write helpers | `main31` 39.09 s | Excluded |
| Shared PCH code generation | PCH 4.38 s, companion object 5.66 s, `main5` 1.42 s, `main31` 38.06 s | No demonstrated heavy-unit gain; excluded |
| LLVM inline and inline-hint thresholds of 75 | Paired `main31`: reference 35.52 / 36.01 s; candidate 30.16 / 29.88 s | 16.1% less time in this repeated unit experiment; runtime impact unverified |
| Thresholds of 75 on the largest unit | `main693` 455.14 s versus full-baseline 537.89 s | 15.4% less time; not a paired isolated comparison |
| Thresholds of 0 / 25 | `main31` 22.48 / 29.02 s | Preliminary only; runtime impact unverified |
| Thresholds of 0 on the largest unit | `main693` 390.18 s | Experimental; runtime impact unverified |

Both repeated default objects were byte-identical, as were both repeated
threshold-75 objects. The two policies produce different machine code: the main
text section shrank from 1,089,152 to 921,808 bytes. This is why the threshold
change cannot be admitted based only on compile timings. O2, floating-point
options and source checks are retained, but runtime speed still needs evidence.

A CPU-only execution fixture subsequently compiled the actual frozen access and
instruction-scope headers against separate no-owner test bindings. Default
execution averaged 0.678 s; thresholds 75 and 0 averaged 0.709 and 0.703 s, while
`-fno-inline-functions` averaged 1.212 s (about 79% slower). Result registers
matched. This is a small desktop microbenchmark with a concurrent build, not a
gameplay/GPU measurement, but it is sufficient reason to reject blanket disabling
of inlining. No inlining-policy change was admitted.

The RAM-boundary slow-path prototype passed 10,610 native boundary, alias and
random-access comparisons across 8/16/32/64/128-bit accesses. Its tested heavy-unit
compile took 43.76 s under the later build load; no speedup was established, and
it remains excluded.

Shared PCH code generation follows the
[Clang documented companion-object procedure](https://prereleases.llvm.org/11.0.0/rc2/tools/clang/docs/ReleaseNotes.html#new-compiler-flags).
The accompanying object must be linked; this experiment did not link or run a
game. Its additional generation cost did not improve the tested heavy unit.

Receipts are in `build-ninja/compile-coldpaths-20261020`,
`build-ninja/compile-inlining-20261020`, and
`build-ninja/compile-shared-pch-20261020`. The separate full comparison is under
`build-ninja/compile-full-20261020`. Its final report must disclose these concurrent
experiments instead of presenting the desktop as an isolated benchmark machine.

## Larger generated-source batches: experiment excluded

The private experiment groups up to **64** ordinary generated files
instead of eight, retaining the existing **500,000-byte** cap. The independent
runtime units, standalone legacy group, per-function optimization exceptions,
source overrides and explicit custom group limits are unchanged.

The first 32-file candidate reduced the complete real plan from **2,381 to 1,038
compiler invocations**; the selected 64-file candidate reduces it to **975**.
Every source remains present in the same group-relative order; compiler flags and
the 119 explicitly listed units are unchanged. This count reduction is not a
56% time-saving claim.

A repeated old/merged/merged/old experiment over 72 real main functions measured
40.36 / 34.37 / 35.75 / 41.35 seconds. Means are **40.85 → 35.06 seconds (14.2%
less time)**. The experiment reduces nine original units to three bounded units
and runs them sequentially, alongside the existing full-build benchmark.

All 72 guest instruction bodies compare equal after masking COFF linker
relocations, in both merged runs. This comparison does not verify relocation
targets or exception metadata and is not a complete executable comparison.
A separate native fixture compiled, linked and executed both grouping policies,
checking 40 mutually referencing functions, ordered function-pointer calls and
observable side effects. Both produced the expected result; its generated units
fell from five to two with 32 files, and to one with 64 files. Two policy tests verify that options, exclusions, special
units and explicit custom limits remain intact.

Implementation: `compilation_batches.py`, `export_kit.py`, `refresh_inputs.py`,
and `export_slim_inputs.py`. Receipts: `build-ninja/compile-unity-20261020`.
No existing immutable kit was edited. The complete experimental build finished;
the separate 2,381-unit comparison measures only the prior scheduling change.

## Additional iterations: overlays and wrapper compilation

The completed old baseline attributes 13,635.6 compiler-process seconds to
overlay units out of 18,994.4 seconds overall (about 72%). These are summed
process durations, not additional wall time.

The overlay sample contains 70 real guest functions. With the existing 500 KB
cap, nine original compiles become six:

| Trial | Original | Larger batches |
| --- | ---: | ---: |
| First / second | 132.058 s | 120.346 s |
| Fourth / third | 134.276 s | 124.031 s |
| Mean | 133.167 s | 122.189 s |

This is **8.2% less time** in the repeated sample. All 70 guest instruction
bodies and named relocation references match in both merged runs. The earlier
72-main-function sample also matches named references. Local section references
and exception tables are not certified by that comparison.

Raising the cap to 1 MB reduced the same sample to three compiler invocations,
but increased its mean time from 125.427 to 128.781 seconds (2.7% more).
The cap remains **500 KB**. The native grouping fixture now also throws through
40 linked functions and verifies every destructor runs during unwinding; both
grouping policies pass.

A Clang time trace of `main31` produced a byte-identical object. Of its 47.90
seconds, 43.88 were in the compiler backend, including 25.97 in optimization
and 17.89 in code generation. These nested totals overlap. Changing one trivial
lazy-wrapper inlining annotation preserved the guest body but took 47.45 seconds;
it was not adopted.

A separate private experiment shares memory callback types instead of
instantiating a different lambda callback for every instruction. This compiled
`main31` in 20.00 seconds, but changed its machine code. In a repeated CPU-only
fixture using the real guard/RAM helper bodies and external no-owner bindings,
execution averaged **1.168 to 1.379 seconds (18.1% slower)**. Results matched,
but the runtime slowdown excludes this candidate. Forcing those guards inline
instead took 132.19 seconds to compile and also changed code; it is excluded.
Neither variant changes the active runtime or release inputs.

The full 64-file/500 KB compilation completed under
`build-ninja/compile-batched-full-20261020`: **3,909.185 seconds**, 975 fresh
compilations plus resource, archives and link, reaching six concurrent compiler
processes. This saves **14m22s (18.1%)** against the original schedule/batches,
and **4m36s (6.6%)** against the scheduling-only candidate. It is not a whole-import
measurement and does not describe the shipped package.

The final strict comparison **failed** for one function:
`sub_001187A0_0x1187a0`, whose instruction body changed from 82,762 to 82,855 bytes,
with two additional named relocations. The other **17,584 of 17,585** guest bodies
and their named references match. All 17,620 source-file/flag records, 120 explicit
runtime/resource objects, and flattened linker source order match.

Different code does not establish a bug or a slowdown, but it also cannot establish
the requested unchanged runtime behavior/performance. This experiment is therefore
excluded from v1.0.11, rather than treating successful compilation as equivalence.
The release preserves the original grouping and the completed scheduling-only
comparison's byte-identical objects and normalized executable. Local reference
payloads and exception tables were not independently certified by the batching
comparer, and no gameplay run was performed.

The source workspace and compiler settings were unchanged. Concurrent verification,
package preparation and reversible compression of inactive benchmark files occurred
on the same desktop. These observations are not isolated hardware benchmarks.
The last unit, containing a single 311 KB function, illustrates a remaining limit
of file-size-based cold scheduling: small source files can still compile slowly.
No further scheduling experiment was added to this release.

Two final cache safeguards do not change the measured cold compilation path:
non-dictionary object receipts trigger rebuilding, and the generation receipt
includes the new registration helper. The raised hardware ceiling is also inert
at the benchmark's seven-job request. Source correspondence was checked against
the frozen worker, and Windows/Linux cache recovery checks passed.

The instruction comparer now checks named call/data relocations separately;
a native COFF test deliberately changes a call target and verifies that it is
detected despite identical masked instruction bytes. Extended relocation counts
follow [LLVM's COFF reader](https://llvm.org/doxygen/COFFObjectFile_8cpp_source.html).
This strengthens the evidence without claiming to certify every local data
reference or gameplay behavior.

The final batch-count comparison held the 500 KB limit fixed and tested 32
against 64 files directly: 41.728 / 40.928 / 40.201 / 41.263 seconds in
reference/candidate/candidate/reference order. Means are **41.496 versus 40.565
seconds (2.2% less time)**. All 72 sampled guest bodies and named references match.
An earlier 8-versus-64 sample measured 49.151 versus 40.568 seconds (17.5% less
time), but neither figure is a complete-build prediction. The byte cap limits
batch size for large functions; only 63 further compiler processes disappear
between the 32- and 64-file complete plans. The native call/exception fixture and
policy tests passed again with the selected 64-file policy.
