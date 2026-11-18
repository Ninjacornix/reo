# Bounded native PCM owner

This independent C++20 module owns PCM channels, voices, queue storage and supplied
clock state. It has no PS2Recomp/guest types, device API, environment, global
service, media file, callback or automatic thread. It is not installed in the
game and does not replace the dependency facade or the real audio device owner.

The native core matches the frozen exact-candidate-source PCM fixture in the
admitted domain: **22 cases, 46 snapshots, 16,656 float values**, on GCC and bundled
LLVM/MinGW. Expected values come from the unchanged reconstructed public runtime,
including policies 0113 and 0118; this is not original PS2 hardware parity.
See [the extraction inventory](../../../docs/native-media/PCM_OWNER_EXTRACTION.md).

## Ownership and API

`Session` allocates fixed channel/voice arrays and all channel ring storage at
construction. Defaults: 16 channels, 16 voice records, 96,000 PCM16 samples per
channel, 16 KiB per enqueue, and 16,384 frames per render. Constructor failure
throws before exposing a session; operations allocate no C++ heap storage.
Configuration rejects zero/overflowing limits and requires the frame bound to
cover the existing 12,000-frame headless catch-up interval.

`create_channel` and `create_voice` return distinct opaque handle types. Each has
a weak session identity, slot and nonwrapping generation. Foreign, expired and
stale handles are rejected. Address reuse cannot revive one; a slot retires when
its configured final generation is released. `reset(now)` invalidates all active
handles and clock selection but preserves diagnostic frame counters. `shutdown`
is monotonic and refuses further operations. Handles do not retain the owner.

`configure` binds channels, rate, volume and playing state. Channels must belong
to this session and be exclusively configured to that voice, even when paused or
disabled. Stereo channels must differ; mono/disabled right handles must be empty.
A disabled voice can retain a valid exclusive left handle or clear it. Channel
close refuses while any voice retains it; voice release leaves channels/data
alive. Reconfigure/release explicitly before channel close.

`enqueue(channel, bytes, now)` borrows a stable readable little-endian PCM16 byte
span only for the call, and copies samples into its own ring. Success returns the
absolute **source-byte** end watermark. `consumed(channel, now)` returns actual
popped/skipped/discarded source-byte credit. `inspect` does not advance time;
`copy_samples` copies the exact current queue into an equal-sized caller span.
No method exposes an internal payload pointer.

Valid enqueue/configure/consumed calls preserve the reference's headless advance
ordering. In particular a queue-cap refusal can follow playback progress, so a
failed operation is not universally state-neutral. Invalid/foreign/stale handles,
unsupported alias/mix, malformed input and unrepresentable counters/clock deltas
are rejected before their operation's state/output changes. A typed refusal is
not an invented guest error or permission to retry a second audio backend.

## Clock, rendering and stop policy

Clock is supplied explicitly. `render(stereoSpan)` or `advance_frames(frames)`
selects the frame clock; an empty/zero request selects it without advancing.
`advance_headless(now)` acts only until that clock is selected. Headless math uses
48 kHz integer frame quantization, a 12,000-frame per-call cap, signed backward
time clamping and retained last-tick remainder. Repeated queries can catch up
another capped interval at the same timestamp. Clock differences whose original
`delta*48000` cannot be represented are declined with `clock_limit` before mutation.

Voice frequency uses zero=>48 kHz, then clamps to 8..96 kHz. Rendering retains the
source front, double fractional phase, zero-order hold, paired stereo pops and
late-sample debt. Starved frames produce silence and debt; recovery skips real
samples to repay it, advancing consumed bytes only for those real pops. Volume
uses `min(volume,256)/256/32768` and an explicitly supplied finite gain in `[0,8]`.
CRI output is clamped to `[-1,1]`. Bank mixing and master gain remain external and
must preserve the order documented in the inventory.

**Implicit positive frame requests admit at most two playing, non-disabled voices.** More
returns `unsupported_mix` before output, queues, counters or clock state change.
The source uses unordered-map traversal; three or more terms can change float
summation order. This conservative gate was chosen instead of promising an
unproved mix equivalence. Voice records may exist beyond that bound. An
integration without explicit ordering must select its entire legacy backend
before use if the implicit domain can be exceeded; it must not disable required
voices or fall back per operation into an
unrelated legacy queue. A zero-frame request consumes no voices.

`set_mix_order(span<const Voice>)` admits larger disjoint mixes by declaring a
complete permutation of all allocated voice records, including paused/disabled
ones. It validates membership, uniqueness and coverage before changing order,
using preallocated storage. An invalid declaration retains the previous order.
Create/release/cut/reset invalidates it; subsequent larger implicit rendering
refuses before effects until the owner republishes a valid order. Channel close
and existing-voice reconfiguration do not change record traversal.

The bridge must transport the actual old/new source traversal at the correct
operation boundary. Legacy configure ticks **before** inserting a new raw-ID
record. Stage a new inactive native record with the old surviving order for that
single advance, configure it once, then publish the new traversal. Advancing then
calling another clocked operation at the same time can consume two capped
intervals. The [original order study](../../../docs/native-media/PCM_RENDER_ORDER.md)
documents this transaction and compiler-specific bucket differences. Native code
does not simulate hash buckets or infer order from slot/raw-ID numbers.

The standalone target disables floating-point contraction (MSVC uses strict FP);
do not build this core with fast-math or permit different contraction rules in a
future embedded compile plan without new parity evidence. The current two-term
domain uses finite two-term addition; the initial 22-case frozen fixture did not
render two simultaneously playing voices. A separate exact-source supplement
now checks that domain below. Neither corpus establishes arbitrary three-voice
summation or permits switching to legacy queues after native publication.

Typed invalid handles are refused before clock advancement. The legacy raw-ID
`consumed` query ticks before looking up an unknown ID; a future facade must
preserve that tick policy explicitly or exclude such calls from its admission.

`drain` retains accepted PCM and keeps playing through a subsequent false
configure, stopping on exhaustion. `configure(false)` alone retains phase/queue;
playing transitions clear late/skipped debt. `discard` clears one queue and sets
consumed=queued. `release` invalidates only a voice handle. `stop(voice, unreturned,
rawRate)` models current short-tail policy: unreturned data plus more than
`(rawRate or 48000)*3/2` queued samples cuts/releases the voice and discards its
channels; otherwise it drains. A cut makes that voice handle stale. Raw stop rate
is deliberately separate from the clamped render rate.

The separate `paced_budget` helper preserves the old non-host-PCM ring arithmetic
(raw/default rate/channels, unsigned dt, 250 ms cap and active-ring divisor). It
does not run automatically and does not introduce a second clock into Session.

## Synchronization and lifecycle

Each operation holds the session's mutex. There are no callbacks or provider I/O
under that lock, and no retained caller buffers. Queue/voice/frame work is bounded
by construction limits. There is no private worker to join. A real host owner
must stop producers and fence/join every device callback before destroying the
Session. `shutdown` invalidates handles and serializes existing calls; it cannot
make an external thread's later call through a destroyed object safe.

Byte/counter and late-skip headroom is admitted before advancement. Slots retire
instead of wrapping generations; source-byte counters refuse exhaustion instead
of silently reusing a watermark. These typed boundaries are explicit native
admission, not claims of new original error semantics.

## Standalone validation

```text
cmake -S game/native/pcm -B build-native-sjuni/pcm-cmake
cmake --build build-native-sjuni/pcm-cmake
ctest --test-dir build-native-sjuni/pcm-cmake --output-on-failure
```

Standalone contract checks cover 172 assertions: stale/foreign/address-reused
handles, generation retirement, finite capacities/ring wrap, alias and >2-voice
refusal before mutation, allocation-free operations, invalid clock/counter/input,
pause/drain/stop/release, reset/shutdown and concurrent producer/render callers.
The concurrency test joins callers before shutdown/destruction.

```text
python game/native/pcm/tests/compare_fixture.py --cxx C:/msys64/mingw64/bin/g++.exe --output build-native-sjuni/pcm-native-compare/gcc
```

The driver also runs those unit checks and compares all 46 frozen snapshots.
Use bundled LLVM/MinGW's compiler path and another output folder for the same
comparison. Both builds use C++20 `-O1 -ffp-contract=off -Wall -Wextra -Wpedantic
-Werror`. Expected fixture SHA-256 is pinned to
`819470f5433c09a5549fefae5f726012ba9ab34f3cc2e4ed3545007d89bea909`;
the original fixture engine/transcript remains unchanged. GCC/LLVM receipts are
`build-native-sjuni/pcm-native-compare/{gcc,llvm}/receipt.json`.

The independent `tests/compare_mix.py` supplement runs the unchanged exact
reference implementation before the frozen native core. GCC and LLVM each match
12 additional two-voice cases / 12 full snapshots / 192 rendered float values:
mono/stereo, reversed configure order, distinct rates/volumes, nonbinary gain,
drain and pause. The native core remains at SHA-256
`6261381c762e7be05aabbc212e7c131e398d3f671a5e35d71203df07b67db0bd`
for the original bounded core. Its explicit-order extension was independently
frozen before the new traversal fixtures were inspected, at core SHA-256
`5f86dd08b10b2ed8dd0bec1b0d11f83237ad0210b776d556de0b9f9a5d86f8eb`
and header `9ad103002c108ec07fce0f1d868d6ceaa5a95f990a45bd10b86d42cd34bcef83`.
No candidate algorithm change was needed. Original expected snapshots and
compile-input identities are retained in
`build-native-sjuni/pcm-mix-compare/{gcc,llvm}`; these are mocked-clock/no-device
observations, not hardware or live-output equivalence.

`tests/compare_order.py` transports the original structured actions and declared
pre-render traversal into that unchanged frozen extension. GCC and LLVM each
match their own original 8 cases / 49 snapshots / 44 float values, including
three-term cancellation, mutation/reset and 32-voice rehash sequences. Complete
queue/voice/counter fields and rendered float bits match. Native bucket counts
and gain callback traversal are deliberately outside this API; the supplied
gain values and actual declared order determine its output. Receipts live in
`build-native-sjuni/pcm-order-compare/{gcc,llvm}`. Headless insertion transactions,
shared channels, the device fence and real facade remain separate gates.

## Optional missing/shared-channel domains

`Config::allow_missing_channels` and `allow_shared_channels` default to false.
With explicit admission, an empty left handle represents the source's zero-left
skip: no PCM, phase or starvation debt advances for that voice. A nonzero latent
channel with no queued samples, or stereo with an empty right handle, instead
accrues debt. Foreign/stale nonempty handles are still refused. Distinct voices
may share queues only with the sharing flag; consuming shared voices require a
valid explicit order even when there are only two. Closing a queue still refuses
until every configured voice releases it. Stereo self-aliasing remains refused.

This extension was frozen before the new expected corpus was inspected, at
core/header SHA-256
`fe31c38f6c276c60c1f1f7cbf5bea2d9132b83c85fd0b49629b0ca721bf4e844` /
`9fe0aff92070569bfd6744856ea438b92099ec38f1875dc660261ef755b659cb`.
The [source-domain oracle](../../../docs/native-media/PCM_SOURCE_DOMAINS.md) and
`tests/compare_source_domains.py` check 19 original cases, 36 operations,
72 pre/post states and 228 PCM float values with GCC and LLVM. Actual native
queue contents, watermarks, phase/debt, clock/remainder, gain cache and counters
match. The test bridge supplies original raw-ID metadata and traversal, stages
new inactive records across configure's single old-order tick, and preserves
unknown-query advancement. It does not calculate expected PCM or use legacy
queue storage. Neither an installed raw-ID bridge nor a real device is exercised.

The earlier single/two/ordered corpora are retained as regression checks for
this extension. Raw protocol generation mapping, finite-capacity error policy,
provider callback fencing and a complete selected backend remain integration
work. Supporting shared queues is not permission to invent defined behavior for
the source's possible same-queue stereo empty-pop path.

The test bridge reuses only the pinned authored action transcript and exact RPC
credit publication/retire code around native consumed-byte results. Stop and
paced-budget calls execute native policy methods. Channel/voice diagnostic mirrors
are refreshed from actual native state and never drive rendering. Expected
results are read from the frozen fixture, not regenerated from the native core.

This comparison proves the stated PCM/timing/stop subset; reusing RPC publication
in the test bridge is **not** a native RPC/SJ migration. Real dependency backend
selection, raw RNA/SJRMT/SJX generation mapping, sound banks, device callback fence,
game activity and performance remain separate unimplemented integration gates.
