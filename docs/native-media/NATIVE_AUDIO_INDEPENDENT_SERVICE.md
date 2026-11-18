# Native audio refill independent of guest scheduling

Status, 2026-11-09: the native controller/source/decoder/refill worker passes
controlled offline starvation tests on LLVM and GCC. Actual SDK integration and
controlled game acceptance are separate gates. This document does not close
Step 3 or claim all historical stutters are fixed.

The [qualification record](../../tools/native_reconstruction/native_audio_independent_service_qualification_v1.json)
binds the exact production worker block, strict compiler commands, unchanged
qualified native-core libraries, inputs, test sources and results. The runner
compiles the actual marked block from `native_sound_ram/composite_backend.cpp`;
the worker implementation is not mirrored in the fixture.

## Measured scheduling weakness

V36 session `20261109-035604-197` reports 90,208 native source-underrun frames.
The first affected native slot/generation, 0/6, is playing, not draining, at
48 kHz and full gain. Its encoded source ring remains near 62 KiB of its
65,536-byte capacity. This is not an encoded-input shortage or an EOF exemption.

Before the first shortage, at QPC 288,179.2833919 s, the PCM queue contains
8,192 samples and underrun count is zero. The next controller observation is
548.9063 ms later, after the native output has advanced 26,400 frames and the
underrun counter has risen by exactly **26,400 − 8,192 = 18,208**. The next
1.4005-second observation gap advances a further 67,200 output frames. Those
facts establish a refill/controller-service gap; separate source/resource
evidence owns the attribution of work that delayed the guest.

The old `SourceWorker` was an external-worker shutdown/join facade. It did not
run a servicing thread. An asynchronous worker performed file reads, while
source polling, decode, PCM copying and playback controls still depended on
guest hook `132C08` reaching `Binding::service`. A larger encoded ring protects
against bounded read delays while decoding continues; it cannot refill a PCM
queue when the decoder/controller itself is not being called. The existing
[64 KiB read-ahead test](NATIVE_AUDIO_PREFETCH.md) therefore covered a different
boundary and was not a fix for arbitrary controller gaps.

The PCM mixer counts an underrun only when a contributing playing voice lacks
samples. Its draining-and-empty branch stops that voice before the starvation
branch. Neither device errors nor a canonical EOF-drain label can erase this
playing-source shortage. Its late-sample/skipped-sample accounting remains intact.

## Ownership and scheduling change

`SourceWorker` now owns a native thread requesting service every four
milliseconds. It obtains an owner-matched, retained native context and the last
actual guest tick before controller admission. It then services registered
native cue feeders and `Instances::service` under the existing canonical
`Owner::run` fence. It reads no guest RAM, adopts no guest handles, imports or
mirrors no guest clocks and generates no synthetic game tick.

Repeated service with the same tick is allowed by the existing native group:
there is no per-tick decode guard. The preserved service divisor determines
bounded decode request size; it does not require decoder/refill work to stop
between guest updates. All source, decoder, output and pending-header capacities
still provide backpressure. Pause and start-inhibit controls continue through
the same serialized native owner.

Cue metadata is part of this boundary. Servicing the decoder alone cannot
commit a delayed header or a seventeenth prepared cue after a sixteen-slot lower
queue frees space. The retained context supplies native cue-feeder work before
instance service. Required order publication remains authoritative: a worker
defers `order_required` and never invents a summation order. A closed owner or
stopping retained context ends servicing normally.

The callback pair is registered from the ordinary binding into the composite
backend. Its default is absent, so PCM-only profiles acquire no new linker
dependency on the ordinary binding. The callback code is process stable;
owner identity and active/stopping state govern each retained context.

Shutdown signals the service thread and closes controller admission, joins the
thread outside guest/controller scopes, then joins actual native sources. A
worker already waiting behind an admitted operation cannot run it after closure.
The joined report records actual native service visits and order deferrals.
Unexpected service failure remains an explicit candidate error, not an old-path
fallback or counter reset.

## Controlled regression results

| Case | Baseline | Native independent service |
| --- | --- | --- |
| Real owned E3 ADX, two seconds of callbacks with guest service withheld | 87,808 underrun frames after its 8,192-sample queue empties | Zero underrun/skipped frames; all first 96,000 source frames match the ordinarily serviced native reference exactly |
| Seventeen short clips, seventeenth metadata read released after 300 ms, two seconds without guest service | Decoder-only worker loses 30,464 frames; final header remains uncommitted | Cue feeder plus decoder worker registers all seventeen, preserves all 69,649 payload samples, reaches EOF and records zero underrun/skipped frames |
| Pause and start inhibit | Separate command checks | Silent callbacks while paused/inhibited; unconsumed queue and pause state remain, resume emits source PCM |
| Three-source order and paused peer | Unknown order deliberately withheld | Worker defers until explicit order; paused third peer remains unconsumed |
| Shutdown behind admitted control | Worker deliberately waits on canonical gate | Join waits for release; queued service has no effects after closure; thread and actual sources join |

Final LLVM fixture: 4,338 checks. Final GCC fixture: 3,589 checks. Check totals
include bounded asynchronous priming observations and can vary between cohorts.
Both use 480-frame callbacks at 48 kHz and preserve tick 7 and service divisor 30
through the ordinary withholding case. No game, UI or physical audio device is
constructed by these regressions.

The exact PCM reference is the unchanged native graph with ordinary servicing.
An independent FFmpeg decode is retained as a separate comparison and differs
from that existing native output by up to **589 integer PCM units** over the
first two seconds. This work changes servicing policy, not codec math, and does
not claim bit equality with FFmpeg. Initial fixtures that incorrectly demanded
one-unit agreement, or supplied an unsupported 960-frame callback, are retained
with their failures; the corrected fixture uses supported 480-frame callbacks
and reports the independent decoder difference explicitly.

The worker's four-millisecond wake is a scheduling request, not a deadline
guarantee. Whole-process/OS stalls, blocked controller admission or exhausted
encoded input can still cause shortages. Production callback registration,
ordinary handle/cue lifetime integration and game presentation remain separate
integration evidence; these isolated tests supply the causal service-policy
comparison without substituting for those gates.
