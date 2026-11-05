# Bounded movie-owner CPU elapsed timing

`runtime/media/movie_timing.h` is a default-off, single-owner diagnostic. Set
`REO_MOVIE_TIMING_FILE` to a session-owned output file in a future coherently
rebuilt candidate. Sealed V7 uses schema1; this schema2 change applies only to a
future coherent rebuild. No sealed SDK/work directory was modified.
It does not change playback clocks, scheduling, retries, queue depth, decoder
arithmetic, fence waits, rendering or pixel readback.

The actual `MovieOwnerServiceTarget` owns the recorder and lends a pointer to its
`LiveMovieProducer`. Only serialized GS-owner operations write it. CPU compressed
input producers never access it. Existing owner-thread guards remain in force;
the recorder has no mutex, thread admission or global registry. The owning
runtime must retain/join the GS worker and cancel the producer before destroying
the target. A retained producer after cancellation must not resume GPU work or
dereference its borrowed recorder. These are existing lifecycle requirements,
not new cross-thread lifetime proof.

Every admitted span updates fixed count, elapsed-sum, maximum and slow-count
aggregates. Only spans of at least2,000,000ns retain detail. Schema2 keeps the
**most recent4096 slow completions plus the longest64** over the owner lifetime.
Each qualifying completion receives a sequence ID, starting at1 per owner. The
recent ring replaces its oldest entry. Longest retention ranks elapsed duration
descending, with earlier sequence winning ties. One event may occupy both sets.
No fast poll consumes a detail slot or slow-event sequence ID.

Producer operations use fixed arrays, at most64 comparisons when a longest-set
candidate is inserted/replaced, and no allocation, formatting, I/O, lock, sort or
GPU query. The usual full-top-set rejection is constant work. Invalid reversed
intervals/boundary IDs are counted separately. Disabled spans read no clock and
create no file; fixed bounded storage remains in the owner object.

Unique retention is the union, never4096+64 blindly. Metadata records observed
slow completions, recent/longest/unique counts and exact missing count
(`slow_events_seen-retained_unique`). Aggregate-sum saturation has its own visible
flag and does not destroy independently exact event counts. On sequence exhaustion
the recorder cannot assign another unique ID: detail sets freeze, aggregates
continue to saturate safely, `sequence_saturated=1`/`missing_count_exact=0` are
exported, and `dropped_slow_events=UINT64_MAX` is an unknown sentinel. The analyzer
reports that missing count as unknown, not as a measured UINT64_MAX loss.

| Boundary | Exact measurement / identity |
| --- | --- |
| `owner_control` | Admitted `runControl` callback from just before invocation through return/unwind; generation is the value before the callback, possibly0 for opening, serial0. Includes nested spans, owner initialization or control work. Does not include FIFO queue delay before invocation. |
| `decode` / `output` | Corresponding actual `LiveMovieProducer` method call after generation/owner admission, including parser/submit/readiness work it performs; original generation and event serial. Every invocation aggregates; short repeated polls generate no detail or text. |
| `release_partial_fence` | Existing nonretired partial-upload fence wait in original queue release; original generation and DMA serial. |
| `batch_fence` | Existing final IMAGE batch submission fence wait; generation and original output-event serial, rather than an invented single DMA serial for a multi-fragment batch. |
| `upload_fence` | Existing nonbatched `waitUploadComplete` fence wait; generation and DMA serial. |

Each span's CPU steady-clock nanoseconds use the same clock/units as
`FrameTrace`; absolute timestamps can join completed frame traces. Elapsed time
includes descheduling and any blocking inside the boundary. It is not CPU busy
time, GPU execution time, actual display scanout or proof of a bottleneck.
Nested aggregates overlap: do not sum them into total runtime. Exception unwind
records elapsed time without claiming that the operation completed successfully.
Readiness reason transitions, time since first retry, input queue depth,
standalone original-frame release fences, source reads and FIFO enqueue times
are not instrumented by this first addition.

Export occurs explicitly in the target destructor **after `stop()` cancels and
retires movie work and resets decoder resources**. No file opens during playback.
The exporter appends schema2 owner sections with owner-start nanoseconds, epoch,
limits/retention/exactness/loss/invalid/saturation metadata and all aggregates.
Only at teardown, it sorts a64-entry top-set copy by sequence and merges it with
the already ordered recent ring. CSV rows are in completion sequence order and
contain `sequence,retention,boundary,generation,serial,begin_ns,end_ns,elapsed_ns`.
Retention is `recent`, `longest` or `recent+longest`; a shared event is exported
once. The trailer's retained count is this unique union. The existing stderr
success receipt also uses unique retained and missing counts. It then checks stream error,
flush and close. A successful close produces one stderr `exported owner` line;
open/write/flush/close failure produces `export failed` and never reports success.
Repeated export calls retain the first result and do not duplicate a section.

Append preserves earlier owner epochs and preexisting incomplete bytes. Readers
must start at a schema marker, treat a section without its matching trailer as
partial, and inspect stderr for export failures. A serialized trailer alone is
not proof that flush/close succeeded or that bytes reached persistent storage;
failure may leave some/all rows and even a trailer. No truncation/repair or
deletion is performed. Hard termination before teardown can leave no new timing
section. A4095-byte path limit fails visibly and leaves recording unavailable.
The caller must provide a private path: concurrent processes/owners writing the
same file are unsupported, and the file intentionally has no global locking.

Run the isolated checks with both installed host compilers and the exact sealed
dependency/compiler cohort:

```powershell
python tools/native_reconstruction/movie_timing/run_checks.py `
  --output build-native-sjuni/movie-timing-schema2-checks `
  --kit build-native-sjuni/candidate-inputs-v7 `
  --toolchain C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64
```

`--toolchain` may instead use `REO_LLVM_MINGW`. The supplied external compiler
must match the sealed plan SHA. The actual object check copies the three changed
headers and the unchanged sealed `movie_owner_service.cpp` into a small private tree,
then compiles against the sealed V7/124-patch include cohort. It does not edit that cohort,
link libraries, construct a runtime, open a device, launch the game or execute a
GPU fence. Tests supply timestamps and failure injection; they do not reproduce
the user's stutter.

Validation on2026-11-05: GCC and LLVM deterministic checks passed, with identical
CSV SHA-256`45f65f8ab5118170dfbb0aeb7f803671a08a565c06c8acb2bc22d80766cb4f2e`.
They check disabled/null/empty paths, zero producer allocation, exact threshold,
aggregates/identities, invalid intervals, recent rolling order, early50ms and
late7ms synthetic spikes after4196 events, longest/recent union deduplication,
precise missing counts, aggregate-sum saturation with exact counts, sequence
exhaustion, no file before export, append/idempotence, RAII unwind and all four
export failure stages. Actual
matching-header object compilation passed with compiler SHA-256
`f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3`.
Receipt: `build-native-sjuni/movie-timing-schema2-checks/movie-timing-f2bxmgr6/receipt.json`.
No game or full build was run for this work.

## Why the retention changed

Read-only evidence from completed private `media-legacy-pcm-v7` shows the schema1
limitation, without establishing a GPU or stutter cause. Epoch4 reports4,859,727
owner controls,4,821,157 decode calls,9635 batch-fence calls, and19,290 total
slow observations (nested boundaries remain separate observations). Every
batch-fence observation met the2ms threshold. The first4096 detail rows were retained;
15,194 later slow observations had aggregate data but no individual timestamps.
Those late details cannot be recovered from that completed V7 file. Maximum
elapsed values remain52.1403ms owner-control,12.7972ms decode and21.8070ms batch
fence, each including descheduling; none identifies a GPU bottleneck by itself.

Private evidence: `build-native-sjuni/playtests/media-legacy-pcm-v7/movie-work.csv`,
233208 bytes, SHA-256
`43fc606b3c4b4e561ff71f5c2ad269fdd5c0568307ff3a96bb26afaa67790726`.
Its existing analysis JSON is1107915 bytes, SHA-256
`c998a4d62ea2122dbead5e463a3712c05e7b42bb3b4ea0173287ef453a1807cd`;
the completed run receipt SHA-256 is
`99847e1a4069ae42f5241beefbedc1a39685af0611e0738db41dba57c5606d32`.
The updated offline analyzer still reads schema1, including its honest losses.
Schema2 tests are synthetic; no new playback measurement is claimed. Recent/top
retention improves future evidence, but cannot guarantee every visible hitch:
thresholds, uninstrumented work, finite history, hard termination and export
failures remain explicit limits.
