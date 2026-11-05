# Bounded movie-owner CPU elapsed timing

`runtime/media/movie_timing.h` is a default-off, single-owner diagnostic. Set
`REO_MOVIE_TIMING_FILE` to a session-owned output file in a future coherently
rebuilt candidate. The existing V6 executable does not contain this addition.
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
aggregates. Only spans of at least2,000,000ns retain detail, up to4096 events per
owner. Later slow events increment the drop counter and still update aggregates;
unread records are not overwritten. Invalid reversed intervals/boundary IDs are
counted separately; arithmetic saturates at UINT64_MAX and sets a visible flag.
There is no per-span allocation, formatting, output or GPU query. Disabled spans
read no clock and create no file. The fixed storage remains part of the owner
object even when disabled; this is bounded diagnostic memory, not a rolling
incident recorder.

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
The exporter appends owner sections with schema1, owner-start nanoseconds, epoch,
limits/loss/invalid/saturation metadata, all boundary aggregates, a CSV header,
slow-event rows and `# owner_complete=1 retained=...`. It then checks stream error,
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
  --output build-native-sjuni/movie-timing-checks-v1 `
  --kit build-native-sjuni/candidate-inputs-v6 `
  --toolchain C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64
```

`--toolchain` may instead use `REO_LLVM_MINGW`. The supplied external compiler
must match the sealed plan SHA. The actual object check copies the three changed
headers and the unchanged sealed `movie_owner_service.cpp` into a private tree,
then compiles against the sealed V6 include cohort. It does not edit that cohort,
link libraries, construct a runtime, open a device, launch the game or execute a
GPU fence. Tests supply timestamps and failure injection; they do not reproduce
the user's stutter.

Validation on2026-11-05: GCC and LLVM deterministic checks passed, with identical
CSV SHA-256`8d1a6063951f2d00f0521edb4f95c54662c1bd5d65c8685bad6de330bc2efa17`.
They check disabled/null/empty paths, zero producer allocation, exact threshold,
aggregates/identities, invalid intervals, capacity loss, saturation, no file before
export, append/idempotence, RAII unwind and open/write/flush/close failures. Actual
matching-header object compilation passed with compiler SHA-256
`f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3`.
Receipt: `build-native-sjuni/movie-timing-checks-v1/movie-timing-18kpnf0s/receipt.json`.
No game or full build was run for this work.
