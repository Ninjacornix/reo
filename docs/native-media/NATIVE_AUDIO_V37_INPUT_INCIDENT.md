# V37: encoded-input completion starvation during recovered movie playback

Status, 2026-11-09: **unexpected audio shortage reproduced; Step 3 remains open.**
Session `20261109-051101-488` completes the intended movie-error recovery, full
replay, subsequent replay/skip and scenario-playlist controls, but records
**107,328 native audio-underrun frames**. Normal exit 0, joined workers and passing
movie-control gates do not make this an audio acceptance pass.

The [qualification record](../../tools/native_reconstruction/native_audio_v37_input_incident_qualification_v1.json)
binds the completed session, exact native/producer traces, diagnostic results,
source code from the sealed V37 kit and the offline analyzer. This analysis
launches no game, accesses no live process/window and changes no existing evidence.

## Measured symptom and affected boundary

The existing audio-control analyzer parses **23,919 global observations** with
zero dropped snapshots, invalid rows or counter/time resets. It locates 134
counter-increase windows totaling 107,328 frames, without multiplying repeated
global counters across stream rows.

The affected source is native slot 0/generation 3, stereo 48 kHz, volume 256,
gain 1, playing and not draining, with 65,536-byte encoded capacity. The first
shortage is bounded by QPC nanoseconds
`292677056549600..292677073077800`; the last increase ends at
`292679623174800`. The complete increase span is **2,566.6252 ms**.

Immediately before the first increase, the PCM queue contains only 32 samples.
The next observation has an empty queue and 928 missing frames. Encoded input
contains only **20 bytes**, and decoded/copied source samples both remain at
8,363,072. An accepted encoded-source request remains in flight. Subsequent
observations continue through the shortage; the maximum controller observation
gap around it is **18.056 ms**. Their source snapshots are freshly observed.

This is distinct from the [fixed guest-service dependency](NATIVE_AUDIO_V37_CONTROLLED_GAME.md):
there is no long missing guest/controller-service interval here. Source polling
continues, but accepted encoded reads do not complete in time. Increasing the
refill thread's visit frequency alone cannot supply those absent bytes.

## Two accepted input requests stop making progress

| Request | First retained pending observation | Last retained pending observation | Observed pending lower bound | Encoded bytes, first → last | Cumulative published bytes |
| --- | --- | --- | --- | --- | --- |
| 50,826 | 292675756167500 ns | 292677223123500 ns | **1,466.9560 ms** | 51,824 → 20 | 9,408,512, unchanged |
| 50,828 | 292677256280700 ns | 292679456237300 ns | **2,199.9566 ms** | 12,924 → 0 | 9,437,184, unchanged |

These are sampled lower bounds, not exact submit-to-completion measurements.
Both requests remain in flight throughout their retained spans while published
input progress stays fixed. The first request completes by the next observation,
publishing 12,288 bytes; a subsequent short read progresses before the second
long pending request.

As input arrives again, the encoded ring refills, decoding/copying resumes and
the unchanged mixer catches up by skipping late source samples. At QPC
`292679639622200` ns, the source has zero remaining late samples and **107,328
skipped samples**, with 7,328 queued PCM samples. The final joined native source
and aggregate reports both retain the same 107,328 underrun frames.

The service worker reports 95,612 actual visits, zero order deferrals and joined
retirement. There is no `NATIVE-AUDIO-SERVICE-ERROR`. Those lifetime counters do
not prove a particular background-thread schedule inside each interval, but the
continuing canonical foreground service and pending input state identify the
read/completion boundary as the bottleneck.

## Movie and control correlation

The shortage occurs during recovered full E3 playback, movie generation 6,
clip 0, **174.2584–176.8250 seconds after its first video publication**. It spans
the neighborhood of picture ordinals 5,222–5,300. All 6,144 source pictures
publish; the maximum publication gap over that full playback is 40.8889 ms,
with zero dropped producer records.

The intended earlier generation-4 injected decoder failure has already returned
through original cleanup and menu recovery. This later shortage is mid-playback,
before finite EOF, not an expected error-cleanup gap or a pending next-clip
header boundary. Successful recovery does not excuse it. Native publication
observations also do not prove physical display pacing.

The launcher check remains failed. Its media-error state includes the expected
injected movie failure, while the nonzero audio-underrun count is an additional,
unexpected failure. No compiler workload was active during this case according
to the test coordinator; that absence does not identify the source of the delay.

## What source inspection establishes

Queued audio preparation currently calls `Clip::prepare(view)` and validates
metadata while retaining the original immutable file-backed view. **Prepared
does not mean resident.** During playback, `Input::Backend` creates a bounded
view for each accepted request and submits it through:

`adxt_refill::AsyncBackend` → `resource_io::AsyncReadOwner` → retained byte view
→ `PinnedFile`.

The asynchronous owner distinguishes queued/active/ready internally, but its
public poll reports pending until the result is ready. The current audio trace
does not expose those inner stages. `PinnedFile` serializes seek plus `ReadFile`
with a mutex. The evidence therefore cannot distinguish:

- A read task waiting to execute.
- A retained-file mutex or seek wait.
- Operating-system file-read latency.
- Worker scheduling or delayed result publication.

The only logged slow game-resource read in this case occurs much earlier, at
QPC `292490419261100..292490592434100` ns. It is not substituted for missing
evidence about these later audio reads. There is no corresponding per-audio-read
stage trace or stack capture establishing their inner cause.

## Next changes and required validation

The smallest diagnostic step is bounded per-request timing for submit, worker
start, provider-read begin/end and publication, retaining request/source offset
identity. That would distinguish scheduling, I/O and publication without blocking
the game or output callback.

A native replacement can remove this class of runtime wait: prepare a bounded,
immutable encoded cue body before publishing readiness, then use an explicitly
resident bounded-memory input path for that admitted profile. The 245 statically
resolved scene/gallery members include a largest file of 22,366,854 bytes;
E3 is 11,081,142 bytes. A per-clip bound and shared memory budget must remain
explicit, with cancellation, immutable ownership and preparation errors tested.
Arbitrary file-backed views must not be treated as nonblocking memory reads.

Larger encoded read-ahead is a separate, bounded resilience option. It can cover
longer measured input delays but does not establish or remove their inner cause.
Any change requires preserved PCM/control behavior, delayed-header and repeat
coverage, joined cancellation/retirement, and complete actual movie/audio retests.

The prior same-executable controlled game test remains valid proof of the
guest-service dependency fix. This incident establishes another open boundary;
neither result overrides the other. Physical audibility, endpoint continuity,
the inner read-delay cause and complete Step 3 acceptance remain unconfirmed.
