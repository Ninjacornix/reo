# Private import profiler

Developer diagnostics for [the import profile](../../docs/IMPORT_PROFILE.md).
These tools do not publish a release or start the game. They use real production
import/generation components with isolated output directories. Generated game
code and binaries must stay under ignored `build-ninja/` directories.

Requirements: Windows x64, .NET 8 SDK, Python 3.12, the supported locally owned
ISO, and local reference artifacts. This is not a player installation step.
The current harness expects the frozen v1.0.10 package at
`build-ninja/slim-release/package-v110-final/RE-Outbreak-v1.0.10-Windows-x64`
and the completed reference build at
`build-ninja/portable-release/first-run-output`. Optional relinking also needs
the original objects and response file under `portable-release/first-run`.
Those private artifacts are not downloaded or shipped with these tools.

From the repository root:

```powershell
dotnet build tools/import_profile/ImportProfile.csproj -c Release
$profileRoot = Join-Path $PWD 'build-ninja/import-profile-NEW'
$discPath = 'C:\path\to\supported-disc.iso'
& tools/import_profile/bin/Release/net8.0-windows/ImportProfile.exe $PWD $discPath $profileRoot
python -X utf8 tools/import_profile/profile_worker.py --root $profileRoot --samples 10 --relink
& tools/import_profile/bin/Release/net8.0-windows/ImportProfile.exe --recheck $PWD $profileRoot
python -X utf8 tools/import_profile/profile_followup.py $profileRoot
python -X utf8 tools/import_profile/profile_registrations.py $profileRoot registration-trial
python -X utf8 tools/import_profile/profile_resume.py $profileRoot
```

Each output directory must be new. Allow at least 15 GB of additional free space
for the complete set and tens of minutes for fresh generation. The initial C#
guard requires 10 GiB; followups and optional EXEs need additional headroom.
Do not run workspace-mutating generation/resume experiments concurrently with
compilation against that workspace. Experiments preserve previous output and
do not silently delete it.

- `ImportProfile`: links unchanged production C# files, redirects `Settings.Home`,
  measures disc import, payload/compiler setup, readiness and image caching.
  It may download the pinned compiler into that private home. `--recheck` compares
  hash buffering and an existing-build component fixture with synthetic identity.
  That fixture is not a supported public game build. No selected EXE is run.
- `profile_worker.py`: measures the frozen worker, runs fresh and reused generation,
  then stops at the compiler boundary; separately samples selected units and
  optionally relinks old reference objects. It does not perform a full new build.
- `profile_followup.py`: samples the owned compiler/linker process tree, captures
  Clang traces, and compares registry PCH/inlining plus safe ICF. Stops only its
  own experiment processes below 700 MiB system physical/commit headroom or after
  240 seconds. Every monitored trial now writes a `.metrics.json`, including
  failures; the earliest trial predates that addition.
- `profile_registrations.py`: verifies exact registration call sequence before
  experimenting with ordered helper chunks. Also tries a pathological guest batch;
  a guard/timeout deliberately raises an error instead of claiming completion.
  `--guest-no-inline-only` after the output name skips the completed registry and
  default-guest trials. It never changes production sources or flags.
- `profile_resume.py`: resumes the real generation stage after PCH creation and
  compiles a small unit against the reused PCH, recording success or refusal.
- `build_optimized_recompiler.py <new-output>` builds the changed guard owner
  against the frozen independent compiler objects, retaining a source/object hash
  manifest. It requires the private original independent build; it never edits it.
- `benchmark_candidate.py <private-root>` measures a candidate kit at
  `<private-root>/kit` through fresh/resumed generation, PCH preparation and two
  real registration compiles. It stops before a complete game compilation.
- `benchmark_compilation.py <new-output>` compares the frozen worker with the
  current one on 32 real mixed units and checks byte-identical objects. `--runtime`
  selects all 119 explicitly listed units. `--plan-only` checks all source/option
  lists, header fingerprints and size hints without compiling. It uses the earlier
  private `import-optimized-20261020` kit/workspace; no generation is repeated.
- `benchmark_full_compilation.py <new-output>` runs both complete workers,
  including fresh PCHs, all 2,381 compilations, archives and linking. It redirects
  only output locations into separate old/new directories, records subprocess
  timings and concurrency, and compares every output object hash. Allow at least
  5 GiB additional space and substantially longer than the sample benchmarks.
  `compare_compiled_outputs.py <same-output>` then compares the linked PE images,
  excluding the COFF timestamp, PE checksum and matching CodeView debug-directory
  timestamp from the normalized digest. It requires all other section contents
  and layouts to match. Neither tool runs
  the game or flushes operating-system caches.
- `benchmark_inlining.py <new-output> --units main31 --thresholds default 75 75 default`
  compares LLVM inlining budgets using recorded real-unit commands and the same
  source/PCH. It retains O2 and floating-point flags. These are experimental
  objects, not release inputs; faster compilation does not establish equal
  gameplay performance.
- `outline_source_access.py`, `outline_instruction_inputs.py`, and
  `outline_field_access.py` prepare isolated header experiments under
  `build-ninja`. `compile_coldpath_candidate.py` builds their private PCH and
  selected real units. They never edit the active dependency checkout.
- `benchmark_shared_pch.py <new-output>` tests Clang's shared PCH code generation,
  including its required companion object, without changing a production plan.
  A successful consumer compilation alone is not a link or gameplay validation.
- `benchmark_access_execution.py <new-output>` executes actual access-wrapper
  headers with separate CPU-only/no-owner fixture bindings under several inlining
  policies. Register-result parity and execution timings are recorded. It does
  not exercise a game, GPU ownership, or the real guest scheduler.
- `outline_memory_wrap.py <new-candidate>` and `check_memory_wrap.py <candidate>`
  isolate RAM-boundary slow paths and compare original/candidate memory helpers
  natively across boundary, alias, random and 128-bit cases.
- `benchmark_unity_batches.py <new-output>` compares original and larger bounded
  batches with unchanged flags. `compare_unity_functions.py <same-output>` then
  compares guest instruction bodies after masking COFF relocations. Its result
  also checks named relocation references, but excludes local section targets,
  exception tables and whole-game proof. `--max-bytes` and `--batch-size` are
  experimental cohort controls, not production defaults.
- `benchmark_batched_compilation.py <new-output> --after <full-comparison-root>`
  waits for the complete scheduling comparison, verifies its executable parity,
  then compiles and links the complete 64-file/500 KB plan with empty object
  caches. It may NTFS-compress completed reference artifacts before timing to
  recover disk space; it never deletes them. `compare_batched_outputs.py
  <reference-old-root> <batched-root>` checks all source flags/coverage and guest
  instruction bodies with the same stated local-reference limits.
- `profile_compile_stages.py <new-output> --unit main31` records a Clang time trace
  with unchanged optimization flags and checks the object against the reference.
  Nested compiler-pass totals must not be added together.
- `inline_lazy_candidate.py` and `shared_memory_callbacks_candidate.py` prepare
  isolated header prototypes. `benchmark_memory_callbacks.py <candidate>
  <new-output>` checks CPU-only no-owner memory operations using the actual guard
  bodies and synthetic external bindings. The shared-callback prototype is
  excluded after a measured execution slowdown; these are not release tools.
- `ImportProfile --compare <repo> <original-profile-root> <simple-label>` measures
  existing-build/image-cache components against the earlier synthetic fixture.
  It discards only its own trial cache after admission to bound disk usage.
  Set the MSBuild `ProductionRoot` property to a separate HEAD source snapshot
  when building a baseline harness; each harness links its own production sources.

The first worker's direct-child counters do not include descendant compiler CPU
or memory. Followup tree sampling does; Clang traces provide pass timings. Nested
spans/pass totals overlap, logical I/O is not physical drive traffic, and caches
are not flushed. Default trial timings may include sampling/profiling overhead.
Use a separate fresh workspace for each comparison and report failures/outliers.
