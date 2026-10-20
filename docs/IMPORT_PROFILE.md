# Import and local-build profile — 2026-10-20

The largest observed opportunities are the native recompiler's source
instrumentation, pathological generated C++ compilation units, and thousands of
small-file operations. ISO extraction and compiler installation matter, but they
do not explain the long first build. The baseline below was collected before
implementation. Measured results are recorded first; the accepted changes are
included in v1.0.11.

## Implemented candidate and measured improvement

The later [compilation update](COMPILATION_PERFORMANCE.md) measures a complete
cold build: 79m31s to 69m45s from scheduling alone, with byte-identical object files,
and 65m09s in a larger-batch experiment excluded after a code difference was found.
Those compilation measurements are separate from
the generation timings below.

The optimized candidate retains the same guest code, compiler optimization/FP
flags, runtime sources, input hashes and refusal checks. It caches regex patterns,
anchors the original expressions at literal candidates, runs independent
generation tasks concurrently, and verifies output files with bounded parallel
hashing. Ten large host registration lists use ordered non-inlined helper chunks.
Large C# file hashes use buffering; existing-build copying hashes in flight, then
still verifies all written outputs before transactional admission.

| Measured work | Old | Candidate | Reduction |
| --- | ---: | ---: | ---: |
| Actual worker preparation, all generation, reconstruction and receipts | 821.86 s | **94.50 s** | **88.5%** |
| Generation function alone | 811.96 s | **64.97 s** | **92.0%** |
| Main registration unit compilation | 6.77 s | **1.47 s** | **78.3%** |
| o2 registration unit compilation | 18.37 s | **3.03 s** | **83.5%** |
| Reused launch-image verification, median of four trials each | 2.30 s | **1.37 s** | **40.6%** |
| Existing-build component import, median of two trials each | 8.72 s | **2.93 s** | **66.4%** |

The worker comparison stops at the C++ compilation boundary: **88.5% is an
import-preparation improvement, not a full first-install speedup**. This original
generation experiment stopped before compilation; the later compilation report
contains the full-build results. The original plan has 2,381 units;
the pathological guest batch's flags were deliberately left unchanged. Normal
cached launches do not regenerate or compile game code.

Old/new C# harnesses use production sources from HEAD and the candidate respectively
and run in old/new/new/old order against the same reference files. Image-cache
runs were 2.26–2.42 s old and 1.35–1.38 s new; existing-build import was 5.81–11.62 s
old and 2.51–3.36 s new. Two-trial medians are limited evidence, not a universal
performance guarantee. The earlier 29 s import outlier is not the comparison
baseline. Cache conditions were not forcibly equalized and some experiments
overlapped other profiling work.

Correctness evidence:

- All 17,549 generated build-input files have the same names. **17,539 are byte
  identical**; the remaining ten are host registration lists with identical
  registration calls and explicit helper invocation order. All guest function
  sources and instruction catalogues are byte identical.
- 8,000 fabricated guard inputs produced identical output or identical refusal
  messages with the old and new source guard.
- All 3,735 compared authored/runtime files and 12 VU code/image files match the
  old worker's outputs byte for byte after reconstruction.
- Native compiled fake-runtime checks verify the chunked registration sequence
  produces the same recorded results. The local-build suite runs 38 tests
  (37 passed, one unrelated optional Linux/compiler check skipped); launcher self-checks
  pass 224/224. Launcher and diagnostic builds have zero warnings/errors.
- Generation and verification errors still prevent publication. Old kits and
  the dirty active dependency checkout were preserved. No game runtime changes,
  gameplay run, compiler flag changes, AV exclusions or forced completions.

Candidate receipts: `build-ninja/import-optimized-20261020/`, including
`generation-final-time.json`, `final-parity.json`, `worker-benchmark/results.json`
and the separately built compiler's `build-manifest.json`. C# comparisons are in
`build-ninja/import-profile-20261020/comparison-{old,new}-{a,b}`. A candidate
`build-inputs-candidate.zip` and resealed kit were retained as evidence; the final
v1.0.11 kit is a separate immutable export. A new kit identity means its outputs require separate admission;
these results do not claim cross-kit cache compatibility.

## Scope and reproducibility

Profiled Windows v1.0.10 at `fcab44c72c5882ddd72d2ce84ca16046954bc894`, using
the unchanged v1.0.6 portable input kit, manifest SHA-256
`9167930286b0ab1c6eff00f260377000b06bb234b29d09fbeae87376d95d5f83`.
The supported NTSC-U ELF SHA-256 starts `06bd5fd7243144cd`; the pinned compiler
is LLVM/MinGW UCRT 20251216 x64.

Machine: Ryzen 5 2600, 6 cores/12 threads, 16 GB RAM, Kingston SATA SSD,
Windows with Defender real-time protection enabled. There was approximately
10 GB free RAM at the start. No user applications were stopped and no protection
or exclusion settings were changed. Filesystem stalls are not attributed to
Defender without an OS-level trace.

The C# harness links the actual launcher import components and redirects storage
into a new private home. The Python profiler invokes the frozen kit's real
generation worker, stops at the compilation boundary, then uses the unchanged
compiler preparation and selected real units. Full fresh generation, download,
extraction, representative compilation, and a reference relink were measured.
There was **no full fresh game compilation or gameplay run**, and no production
build was admitted from the experiments. This is a Windows profile, not Linux
performance evidence.

"Fresh" means a fresh application destination, not an empty OS filesystem cache.
Caches were not forcibly flushed. Process I/O counters are logical I/O, not
physical disk traffic. Timings below are separate component measurements, not
an end-to-end install stopwatch. Nested stages and compiler passes overlap and
must not be added. The console harness does not measure WPF rendering latency.

Developer tools: [tools/import_profile](../tools/import_profile/README.md).
Private receipts are under `build-ninja/import-profile-20261020/`; generated game
sources, binaries, ISO contents, and compiler installations remain ignored.

## Measured stages

| Component | Fresh destination | Reuse / warm measurement |
| --- | ---: | ---: |
| ISO validation and extraction, 85 files / 4.267 GB | 55.44 s | 2.21 s |
| Expand independent input kit, 3,883 files | 13.79 s | 0.002 s |
| Verify expanded input files | 3.05 s | Not separately repeated |
| Download and prepare compiler | 22.17 s | 4.89 s inventory verification |
| Discover an already installed matching compiler | — | 0.002 s |
| Prepare sources and generate all game C++ | **821.86 s (13 min 42 s)** | 9.46 s |
| Compiler preparation, shared headers and PCH | 45.32 s | 5.03 s |
| Ten representative compile units, serial | 74.56 s | Samples only |
| Link using all existing reference objects | 8.19 s | Objects already compiled |
| Create immutable launch-image cache | 3.10 s | 2.25–4.65 s in three repeats |

The first image-cache reuse measurement was 14.75 s; the later repetitions
demonstrate variability, so that outlier is not treated as normal overhead.
One thousand disc-readiness checks took 0.076 s in total: they are not a priority.

## 1. Generation: source instrumentation and small files

Locations: `tools/source_instrumentation/guard_generated_source.hpp`, the patched
PS2Recomp `CodeGenerator::generateFunction` / `source_guard::instrument`, and
`tools/local_build/generate_game.py::{generate,sha}`.

Eighteen native recompiler invocations consumed 695.55 s in total. The largest
were overlay o2 (255.39 s), main (164.35 s), o3 (90.06 s), o4 (66.5 s), and o6
(56.6 s). They execute serially today.

During o2, an external stack sampler observed the active recompiler thread for
80 samples. In 75 samples it was inside source instrumentation, and in 74 it
was inside regex search. These are inclusive samples from one roughly four-second
window, not an exact whole-generation percentage. The sampled o2 duration includes
the sampler overhead; other recompiler processes were not sampled.

The guard constructs regex objects per generated function, repeatedly scans and
copies function text, wraps field accesses, handles masked writes, and rewrites
memory operations. This is a strong CPU optimization target. Cache immutable
patterns, reject absent literal prefixes cheaply, and fuse compatible scans or
replace matching with a bounded parser. Preserve emitted semantics, refusal
rules, instruction ownership, quoted/comment text, and masked-write behavior.
Do not remove the guards to achieve a faster benchmark.

The original root guard and the frozen compiler's proof-source guard were confirmed
identical after formatting through stdin. An earlier path-based comparison was
misleading because clang-format ignores the build directory. The optimized compiler
was built with the frozen owner's other objects unchanged, and a separate patch
records the guard change. Editing the root header alone does not update an already
shipped compiler executable.

The Python generation manifest separately hashed **17,522 files / 408 MB in
103.54 s**. Across fresh and resumed stage receipts, another 35,136 hash calls
read 821 MB in 8.20 s. The different timings show that opening newly emitted files
and cache/filesystem state matter; SHA arithmetic alone does not explain the
first result. These are nested measurements.

Candidate improvements:

- Hash finalized bytes as they are written, and carry verified digests into the
  transactional generation receipt instead of reopening every output twice.
  Preserve the mutation/integrity guarantees when reusing files.
- Reduce per-function create/rewrite/open cycles. Emit final private header names
  directly; consider deterministic source batches plus a per-function index.
  Recipes and instruction catalogues still need exact function identity.
- Run independent main/overlay recompiler processes concurrently, each with its
  own output directory, and join before common registration/catalogue publication.
  Using only recorded task durations, a greedy two-worker model is about 348 s
  and a four-worker model about 255 s for the **native subprocess portion** versus
  696 s serial. This is a scheduling model, not a measured parallel generation
  result or complete import ETA; shared I/O, dependencies and postprocessing remain.
- On resume, avoid unconditional copying of 3,707 independent source files
  (112 MB): that cost 4.97 s out of the normal 9.46 s resume. Use verified,
  content-stable updates so valid headers/PCHs are not needlessly invalidated.

Source recipes took 0.10 s, queue-control reconstruction 0.01 s, and VU
reconstruction plus its AOT helper about 1.12 s. They are not leading bottlenecks.

## 2. Compilation: two different kinds of oversized function

Location: `tools/local_build/compile_game.py::compile_plan`, generated registration
emission in `generate_game.py`, and the patched recompiler's function emitter.

The actual plan contains 2,381 units: 719 main, 1,539 overlay, 3 extra, 1 legacy,
117 authored/runtime/backend/original units, and 2 generated VU units. Main and
overlay C++ account for about 404 MB of source. Existing batching limits aggregate
units to roughly eight functions / 500 KB, but a single function can exceed the
limit. Shared PCH and up to four compile workers already exist.

### Host registration lists

`overlay632` is **host registration code**, not a character or geometry function:
`register_o2.cpp` contains 32,834 ordered registrations. Its baseline compile
took 18.30 s, of which about 13.7 s was greedy register allocation; compiler-tree
peak working set was 439 MiB.

An experiment split this list into sequential, non-inlined static helper functions:

| Same registration list | Compile | Peak compiler-tree working set |
| --- | ---: | ---: |
| One large function | 18.30 s | 439 MiB |
| Helpers of 256 calls | **3.20 s** | **135 MiB** |
| Helpers of 1,024 calls | 3.37 s | 133 MiB |

The profiling script verifies every original registration call and its order are
preserved. This is a 5.7× sample compile improvement, not a whole-game speedup or
runtime-equivalence proof. It is a concrete, bounded generator change to pursue.
`main0` is another registry; earlier notes calling its allocator cost "geometry"
would be misleading.

For the same registry, removing the PCH took 19.84 s. Also disabling automatic
inlining took 19.92 s with essentially the same object size. Those changes do not
solve the registration-function bottleneck.

### Large guest code

`main693` is a real guest-code batch and was selected because it produced the
largest object in the existing reference build. With normal O2/PCH settings,
the experiment was stopped at **240 s**, still compiling, after reaching about
3.40 GiB compiler-tree working set. This is a lower bound on completion time,
not a measured completed compile.

The same source and PCH with `-fno-inline-functions` completed in **79.19 s**,
using 940 MiB. It retained the existing O2, floating-point and integer flags.
The object was 9,373,651 bytes; the older reference object was 7,362,167 bytes.
That size comparison is contextual, not an equal-run code-size test because the
new baseline experiment never completed. The no-inline experiment also overlapped
a separate resume check and is not an isolated-system benchmark.

This makes selective inlining limits on pathological guest units worth exploring.
It does **not** justify globally disabling inlining: runtime performance and
generated dispatch/yield behavior must be evaluated before release. Splitting a
guest function is substantially riskier than splitting host registration lists;
resume points, function-entry backedges, guest state and memory ordering must
remain correct.

### Parallelism, headers and scheduling

The same six ordinary generated units took about 43.5 s serial, 23.37 s with two
workers and 19.55 s with four. The longest registry limited this small set; this
does not establish full-build scaling. The ten-unit sample also included extra,
legacy, authored, backend, runtime and VU sources, ranging from 0.6 to 18.4 s.
The 240-second guest outlier prevents a credible full-build ETA from averages.

Priorities within `compile_plan`:

- Schedule measured expensive units early so the last giant unit does not hold
  up the end of the build. Record unit duration and compiler-tree peak memory.
- Make admission memory-aware per unit: a nominal 2 GB worker budget is smaller
  than the observed 3.4 GiB outlier. More jobs can increase paging or failures.
- On machines with ample RAM, allow more than four workers. Both launcher and
  worker limits need coordination; changing only the launcher cannot remove the
  worker's hard cap. Do not raise it blindly on this 16 GB machine.
- Initial preparation spent 28.94 s hashing 3,687 headers / 143 MB; repeat hashing
  took 0.91 s. An indexed dependency manifest and reuse of verified inputs can
  reduce repeated walks. Do not ignore reconstructed or transitive dependencies.
- A profiled warm preparation spent much of its instrumented time in pathlib
  containment checks and stat calls. Resolve/validate each distinct path once
  per immutable plan rather than repeating it per source. The cProfile run took
  9.98 s versus about 5 s without profiling, so its percentages are diagnostic.
- Audit a separate PCH or independently prebuilt subset for the 119 explicitly listed
  units. Do not ship reconstructed game instructions as "runtime" prebuilts.

A real generation resume was executed after PCH creation, followed by actual
compilation of `main87`. The PCH was reused unchanged and compilation passed.
The current recipe plan reconstructs no header destinations. A suspected
recipe-header/PCH invalidation issue was therefore **not reproduced**. That
contention-affected resume took 67.67 s and is not used as the normal resume time.

## 3. Disc extraction and tool setup

Locations: `launcher/DiscImport.cs::Extract`, `DiscImage.cs::Copy`,
`PortableCompilerSetup.cs::{Ensure,Download,Valid}`, `LocalBuildPayload.cs::ExpandPayload`.

Three NETBIO files total 4,240,791,552 bytes: **99.37% of extracted bytes**. A
virtual ISO-file-slice layer could eliminate most first-import copying and duplicate
disk usage. It is not safe to simply omit these files today: CD host mappings and
direct AFS/Sofdec/NETBIO readers still open extracted paths. Relevant readers
include runtime `Kernel/Stubs/Helpers/Support.h::{registerCdFile,readHostRange,
readCdSectors}` and `recomp/overrides/reo_override.cpp`.

A smaller step is to extract the validated ELF and BIN overlays first and overlap
bulk assets with generation and compiler setup. Final readiness must wait for all
assets and hashes. Twelve backwards seeks were counted in disc entry order;
offset-order extraction may help rotational disks, but its benefit on this SSD
was not measured. Copying already uses a 1 MiB buffer and hashes during extraction.

Compiler setup downloads a 181.3 MB official ZIP but selects only the x64 subset:
5,601 files / 467.3 MB expanded. Selected entries account for about 124.3 MB of
compressed entry data. A separately pinned slim toolchain asset could avoid
roughly 57 MB of download, subject to packaging/provenance/licence work. It should
not inflate the main launcher ZIP again. Existing compatible installations already
avoid downloading.

Other candidates are verified resumable downloads, hashing during download,
and buffer reuse rather than allocating 64 KB per extracted file. The kit expansion
allocated about 297 MB and compiler setup about 402 MB cumulatively; these are
allocations, not simultaneous resident memory. Download resumption requires
server range/identity checks and final SHA validation. Setup can overlap other
work after ISO compatibility validation, with cancellation propagated to all tasks.

## 4. Existing builds, hashing and launch-image copies

Locations: `launcher/LocalGameBuild.cs::{Sha,Ready}`, `ExistingGameBuild.cs`,
`GameImageCache.cs::{Hash,Prepare}`, and `launcher/native` adapter build scripts.

For the 866,714,624-byte reference EXE, repeated default `File.OpenRead` SHA took
1.11–1.12 s and about 211,602 read operations. A 1 MiB sequential FileStream
took 0.67–0.69 s and 829 reads; explicit 1 MiB incremental hashing took
0.63–0.64 s and 828 reads. All digests matched. Buffered hashing is a low-risk,
measured candidate for the shared hash helpers, with cancellation retained.

An existing-build component import took 29.04 s with about 3.315 GiB of logical
reads: source validation, copying, target hashing and final target validation.
Importing that already-admitted cache took 1.13 s. This used a real-size reference
PE and DLLs with a synthetic component-fixture identity; the public importer does
not admit that fixture as a game. It was never executed.

Hash while copying; pass a verified artifact/receipt under a stable read lease
through the current operation rather than rehashing identical bytes immediately.
Preserve change detection, transactional publication, compatibility and companions.
Do not replace integrity verification with size/mtime alone.

The launch-image cache hashes both source and cached EXE even on reuse, accounting
for about 1.658 GiB logical reads each time. It can reuse verified results within
one launch without weakening checks. Its identity also includes `XINPUT1_4.dll`:
v1.0.9 and v1.0.10 adapter DLLs have different hashes/timestamps despite unchanged
source, which can cause another full 866 MB image copy. Use reproducible adapter
builds or separate immutable game and launcher-adapter identities. Same-volume
hardlinks are an option only between controlled immutable cache objects, with
copy fallback; do not link an arbitrary mutable user-selected EXE into the cache.
The first completed build also copies from build output into its ready folder
before the separate launch-image copy. A shared immutable artifact store could
avoid those repeated large-file copies while keeping staging and rollback safe.

## Progress reporting and remaining measurement limits

`MainWindow.Import.cs::BeginDiscImport` estimates compilation ETA from completed
unit counts. A sub-second unit and the observed multi-minute unit each count as
one, so the estimate can be misleading near a long tail. Record stage and unit
durations, identify the active generation substage, and weight ETA using prior
timings with an explicit estimating state. Keep UI updates throttled and retain
cancellation. This improves useful feedback; it is not a throughput speedup.

The WPF progress handler and OS file/antivirus/storage behavior were not separately
traced. Representative import stages run off the UI thread, but this console
profile cannot establish responsiveness on another machine. Network throughput,
rotational storage, memory pressure, and full-build unit distributions need their
own measurements before a universal install time can be promised.

## 5. Link and output size are secondary

Full reference linking took 8.19 s. A separate warm-cache `--icf=safe` experiment
took 2.14 s with about 2.14 GiB peak compiler/linker-tree working set and reduced
the EXE from 866.7 MB to 859.7 MB. Different cache states prevent calling this a
link-speed improvement. The size saving was less than 1%; gameplay was not tested.

The reference PE has 747 MB of raw `.text` and 106 MB of `.rdata`, versus roughly
12 MB of COFF symbol/string data. Stripping debug/symbol data cannot explain or
remove most of its footprint. Investigate duplicated generated/helper machine
code or outlining only with code-size and runtime evidence; section sizes alone
do not establish which helper causes expansion. Linker flag changes are below
generation and pathological compilation in priority.

## Recommended implementation order

| Priority | Change | Evidence / limit |
| --- | --- | --- |
| 1 | Optimize source-guard scans and parallelize independent generation | Minutes of observed generation; preserve all source safety checks |
| 2 | Chunk host registration lists | 18.3 → 3.2 s sample; exact call order checked |
| 3 | Control pathological guest-unit compilation, memory and scheduling | Baseline >240 s / 3.4 GiB; no-inline sample 79 s / 940 MiB, runtime tradeoff unresolved |
| 4 | Buffered hash helpers and consolidate duplicate in-operation verification | Equivalent hashes measured; integrity and race protection stay |
| 5 | Content-stable source prep / indexed generation outputs | Thousands of opens, hashes, rewrites and resume copies |
| 6 | Overlap setup/extraction/generation; later virtualize ISO file access | 55 s extraction, 22 s setup; current readers need extracted files |
| 7 | Slim compiler download, safe additional PCH/prebuilds, larger-machine concurrency | Potential gains; not yet benchmarked end to end |
| 8 | Linker/code-size changes | Small observed link/ICF opportunity relative to above |

Keep launcher-only releases on the existing kit identity. Batch generator/worker
changes into one new kit after validation so users do not repeatedly rebuild.
Compare emitted-source/refusal fixtures for generation changes, strict resume and
cache-tamper scenarios for I/O changes, and game speed/correctness for compiler
changes. Only a complete fresh build on the candidate kit can establish the new
first-install ETA. No whole-build speedup percentage is claimed by this profile.
