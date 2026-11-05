# Extracting the complete host PCM owner

Status: source-qualified boundary review and exact-source offline fixtures,
2026-11-05. No PCM core was extracted, dependency patched, game/device opened or
user asset read. The native ADX kernels and their guarded adapters are separate.

The next complete unit is an instance-owned **PCM channel/voice/render clock**,
replacing the implementation of the reconstructed runtime's whole `CriAudio`
facade. Moving only the render loop would leave the queues, consumed watermark
and stop state inside PS2Recomp. Operating native and legacy queues per-call would
split one playback clock and break SJ credit. Select one backend for the complete
runtime session, before the first voice/queue operation, or retain the whole
existing backend.

The new evidence below is sufficient to start a bounded independent PCM core and
differential consumer. It does not close raw-handle reuse, all concurrent callback
lifetimes or the separate sound-bank mixer, so it is not an extraction-complete or
whole-audio-native claim.

## Exact candidate source, not the dirty active audio tree

Reviewed source: `build-native-sjuni/dependency-workers-v1/ps2xRuntime/src/lib`,
the reconstructed public 121-patch series based on
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f`. This includes
[0113 voice release](../../third_party/patches/ps2recomp/0113-cri-release-destroyed-rna-voices.patch)
and [0118 short-tail stop policy](../../third_party/patches/ps2recomp/0118-audio-keep-short-speech-tails.patch).
The active dependency audio differs, as already recorded in
[BOUNDARY_INVENTORY.md](BOUNDARY_INVENTORY.md). No compiled binary is inferred from
either source directory.

| Source under that lib root | Raw SHA-256 |
| --- | --- |
| `Kernel/Syscalls/Helpers/CriAudio.cpp` | `39dce6882e561ad69a0112a330ecc4023a98c21365ac2fe8709f838fce4c9a06` |
| `Kernel/Syscalls/Helpers/CriAudio.h` | `7103ab05367839041672898c6406ca42a41482bff1640e4a1faecfd7aa52f4be` |
| `Kernel/Syscalls/Helpers/State.h` | `4cab412ab2c6a54e3ff14a6f619ce61c850cae8e3b80d92d86c3bef22eb1b4b8` |
| `Kernel/Syscalls/RPC.cpp` | `050d63e738481ac592429a21ba317fcb28f86f8d47afe48b2ee4ed8c3dc81a9f` |
| `cri_pcm_retire.h` | `b7dc48ac1279f07032fbfd1de39049f0da7fd15fac8d73a4f5708912f022cbc8` |

## State that must move together

Line references in this section refer to the reconstructed source above, not the
different active checkout. No original function mapping or alias is added here.

| Implementation | State and dependency | Required native boundary |
| --- | --- | --- |
| `CriAudio.cpp:24..48`, `Channel` / `Voice` and globals | Channel deque, queued/consumed **byte** counters; voice keys, rate/volume, playing/draining, double phase, late/skipped sample counters; one mutex; global maps. | Move these into one session instance. Keys become generation-bearing native channel/voice tokens; raw guest/RPC handles stay in a temporary bridge. Do not retain guest payload pointers. |
| `queue`, line 198 | Copies planar little-endian PCM16 into an owning deque; rejects zero key/pointer/length, odd bytes or more than `4000` bytes. Per-channel bound is **96,000 samples**, not bytes. | Own samples before return and return an accepted end-byte watermark. Preserve validation/tick/cap ordering; no device initialization or environment reads in core. |
| `configure`, line 234 | Creates/updates voice; clamps channel count to two, frequency to 8..96 kHz (zero defaults to 48 kHz), retains raw unsigned volume; preserves phase on pause/resume. | Typed configuration with explicit modes/rate normalization. Preserve zero-channel disabled behavior if included; do not conflate output-rate normalization with raw RNA frequency used by stop policy. |
| `renderLocked`, line 52 | Mixes fronts, advances source phase, consumes real source halfwords, tracks starvation and late skipping. | A complete deterministic `render(frames, gains, output)` over owned state. No RPC/SJ, scheduler, RAM, bank/device callback or host clock lookup inside it. |
| `tickLocked`, line 121 | Polls settings and advances a headless clock when neither device nor explicit-render clock is selected. Queries can advance playback. | Explicit `advance_headless(nowNs)` and a clock-mode state. The facade must preserve existing call ordering and select one clock, not advance both. |
| `render`, line 186 | Sets explicit-render clock, renders CRI under its lock, releases that lock, mixes bank audio, then applies master gain and clamps. | Core CRI render followed by a host composition stage. Preserve lock/order boundaries; never move bank locks under the PCM queue lock. |
| `drain/discard/release`, lines 264/274/277 | Drain accepted samples; discard sets consumed to queued; release removes one voice but **retains channels**. | Separate operations. Voice close must not invalidate another voice's shared channel. Channel close/generation handling needs a distinct actual lifecycle event. |
| `reset/shutdown`, lines 281/282 | Reset clears voice/channel maps and routes, resets clock selection/last tick; diagnostic output counters persist. Shutdown first stops/unloads host stream, then resets PCM and separately resets banks. | Native session generation invalidation plus host sink stop/quiescence before destruction. Reset is not arbitrary erasure of bank voices. Diagnostic counters need an explicit instance/global policy. |

The header already uses no guest register/RAM types, but its implementation is
still coupled to raylib host setup, environment diagnostics, process-global mixer
callbacks and the separate bank mixer. Renaming that namespace is not ownership
extraction.

## Exact math and control behavior to preserve

Samples are taken from the front before phase advancement. This is zero-order
hold with dropped source samples at higher rates, not linear interpolation.
Each frame adds `frequency/48000.0` to a **double** phase; while phase is at least
one, a whole sample pair is popped and phase decremented. Consumed advances by two
bytes per actual channel pop. Mono duplicates left into both output channels.
Stereo stalls and skips as a pair when either input lacks data.

On starvation, silence occupies output time and the integer part of accumulated
phase becomes `lateSamples`. On refill, real queued samples are popped to pay that
debt before producing more output; these skipped bytes still advance consumed.
Do not advance consumed merely for silent device time. At 96 kHz with too little
input, a residual phase can survive an exhausted consumption loop and contribute
to the following starvation debt.

Gain order is observable: per-stream gain times
`min(volume,256)/256.0f/32768.0f`, sum CRI voices, clamp CRI L/R, release the PCM
lock, add the independent bank mix, multiply master gain, then clamp again. Do
not move master before the first clamp or reset/pause bank audio with a CRI voice.
The fixture's bank hook is an explicit synthetic additive sink, not a bank parity
test.

`configure(false)` retains queue contents and phase. A pending drain changes a
subsequent false configure back to playing; a true configure cancels draining.
Changing playing state clears late/skipped debt but does not reset phase. Drain
only marks an existing playing voice with nonempty left queue; a later empty pair
stops it and clears phase/debt. Discard empties one channel and sets consumed to
queued. Release erases one voice, including pending drain, without deleting
channel queues. These differences are required by candidate policy 0113/0118.

Headless PCM advance uses signed elapsed nanoseconds clamped at zero, integer
`ns*48000/1e9` frames and a per-call maximum of 12,000 frames. It advances lastTick
by integer `frames*1e9/48000`, retaining quantization remainder. Repeated queries
at the same timestamp can catch up another capped interval. `render(nullptr,0)`
selects external-frame clock without consuming samples. A reset restores
headless mode until render/device output is selected again.

RPC's separate `dtxPacedConsumeBudgetBytes` is a **non-host-PCM ring fallback**:
raw/default RNA rate × raw/default channel count × two bytes, divided among
nonzero ring handles; dt is unsigned, capped at 250 ms. A backward timestamp
therefore reaches its cap, unlike the signed-clamped headless PCM clock. Rings in
`g_pcmRings` bypass that paced ring consumption. Do not unify these two formulas
or apply both clocks to an audio ring.

## RPC/SJ credit and stop remain a distinct owner

The successful PCM enqueue site at `RPC.cpp:1028` normalizes the guest source and
record, copies through `ps2_cri_audio::queue`, then stores
`PcmPending{ring,endByte,originalReply,consumedPrefix,replied}`. The input borrow
ends after copying; the original reply identity and credit do not.

The complete `collectSjxReplies` method at line 696 is now exercised offline:

* Whole original chunks become reply-eligible at
  `consumed + 0x6000 >= endByte`, in pending order. This is an IOP-buffer lead,
  not an additional native PCM capacity or proof that samples played audibly.
* Playback retirement is separate. Exact `cri_pcm_retire::plan` computes a
  consumed prefix, rounds nonfinal ready prefixes down to 64-byte boundaries,
  and never creates space from a backward watermark. It updates ring bookkeeping
  while retaining the whole original SJ chunk identity; prefix fragments must
  not be published as new EE free chunks.
* Original replies are written to the actual transfer's work area, bounded by
  `min(128,(wkSize-80)/16)`, with count at offset zero and records at offset 16.
  This guest publication belongs in the RPC adapter, outside a generic PCM core.

Policy `discardUnlessNaturalEnd`, line 61, resolves RNA SJ/SJX handles, counts
unreturned chunks, and compares the larger remaining channel queue to
`(rawSampleFreq or 48000)*3/2` **samples**. Unreturned plus a longer remainder
means release voice and discard distinct rings. Otherwise drain. Raw RNA rate
here is not the clamped render rate. RNA destroy at line 2086 releases the host
voice before erasing metadata, independently of this natural-tail decision.

SJRMT destroy at line 2153 erases runtime ring metadata without an explicit
`CriAudio` channel close; current PCM channel maps can remain until reset. Any
new generation-bearing native mapping must explicitly settle pending credit and
old channel identity at that event. Treating a reused uint32 handle as the same
native channel is not safe admission. This is an unresolved bridge contract,
not evidence that a particular game session hit handle reuse.

## Exact-source fixture, without a game or device

[pcm_owner_oracle.py](../../tools/native_reconstruction/pcm_owner_oracle.py) pins
the five raw source hashes above. It copies the **complete unchanged** reconstructed
`CriAudio.cpp` and header into ignored output, and compiles them in one probe.
Preprocessor namespace indirection supplies a deterministic `steady_clock`; all
other standard-library names resolve to the real implementation. Mock host
functions refuse device readiness, so no device is opened. Gain, bank mix and
diagnostics are explicit hooks. It does not read audio assets or modify source.

Four complete RPC methods are exact-extracted from the pinned source:
`resolveRnaRing`, `discardUnlessNaturalEnd`, `dtxPacedConsumeBudgetBytes` and
`collectSjxReplies`, together with actual small state structs and the original
`0x6000` declaration. They operate on finite synthetic maps and a bounded 1 KiB
wire buffer, with generic checked reads/writes. The exact retire header is also
compiled. No full RPC entry, original EE/IOP instruction or game scheduler is
executed; this reference certifies **current candidate-source behavior** only.

GCC and bundled LLVM/MinGW compile with C++20
`-O1 -Wall -Wextra -Wpedantic -Werror` and produce identical fixtures:
**22 cases / 46 snapshots**, 392,709 bytes, SHA-256
`819470f5433c09a5549fefae5f726012ba9ab34f3cc2e4ed3545007d89bea909`.
Float output and double phase use exact bit-pattern observations. Small remaining
queues are complete; large queues use count plus FNV-1a content digest, avoiding
large traces. This digest is a bounded regression observation, not a cryptographic
proof of equality over all possible contents.

| Concrete vector | Candidate-source observation |
| --- | --- |
| Four mono samples at 48 kHz, render five frames | Eight bytes consumed, final frame starved; mono duplicated. |
| Three samples at 24 kHz, render five frames | Four bytes consumed, phase one half; sample holding preserved. |
| Three samples at 96 kHz, render three frames | Six bytes consumed; late debt three after exhaustion. |
| 100 frames at 44.1 kHz | 91 source samples consumed, nine remain; exact double phase bits captured. |
| Three empty frames, then six-sample refill | Three real samples skipped on recovery, with matching byte credit. |
| Pause after a half-rate frame | Phase retained across pause/resume, queue retained. |
| Drain followed by false configure | Drain wins, queued tail plays, then voice stops. |
| Stop with unreturned data and 72,001 / 72,000 samples at 48 kHz | Longer queue discarded/released; threshold queue drains. Long already-returned data also drains. |
| 96,000 queued samples, then one more sample | Rejected, caller endByte untouched. |
| Headless timestamps 20,833 / 20,834 / 41,666 / 41,667 ns | Consumed bytes 0 / 2 / 2 / 4; backward signed timestamp adds no progress. |
| Headless 500 ms gap, two queries at the same time | Each advances 12,000 frames: consumed bytes 24,000 then 48,000. |
| RPC stereo/two-ring 10 ms / long / backward unsigned intervals | Per-ring budgets 960 / 24,000 / 24,000 bytes. |
| First 16 KiB chunk at consumed zero | Whole chunk reply emitted with zero playback retirement. |
| Second chunk endByte 32 KiB | Reply absent at consumed 4 KiB, present at 8 KiB; first chunk retires only at consumed 16 KiB. |
| Reset/shutdown | PCM state cleared; diagnostic frame counters retained; host/bank actions remain separate. |

Reproduce against any reconstruction with the exact pinned hashes:

```text
python tools/native_reconstruction/pcm_owner_oracle.py --cxx C:/msys64/mingw64/bin/g++.exe --output build-native-sjuni/pcm-owner-oracle/gcc
```

Pass `--dependency` for another reconstructed source root. GCC/LLVM receipts and
fixtures live under `build-native-sjuni/pcm-owner-oracle/{gcc,llvm}`. No native
candidate implementation was used to obtain these outputs.

## Concrete extraction contract and patch plan

Create an independently buildable `game/native/pcm` core with no PS2Recomp,
raylib, RAM/register, environment, file or guest-handle dependencies:

1. One `PcmSession` owns all channels, voices, queue storage and clock state.
   Opaque generation-bearing channel/voice handles include an unforgeable session
   identity. Retire a generation slot rather than wrap; reject foreign/stale
   tokens. Native channel close is separate from voice release. Preallocate
   configured handle/queue capacities; preserve valid accepted PCM byte order.
2. Take byte spans only synchronously on enqueue, copying little-endian PCM16;
   expose explicit accepted endByte, queue-sample count and source-byte consumed
   watermark. Use typed statuses for invalid token, capacity, malformed input and
   allocation admission. Preserve current clock advancement before queue-cap
   rejection; do not claim every failed operation is state-neutral. Avoid the
   legacy deque's possible mid-append allocation failure by reserving storage
   before accepting work, with failure behavior explicitly admitted by the bridge.
3. Pure render and headless-advance operations take gains/time as arguments;
   preserve float/double order and watermark math from the fixtures. Bound frame
   requests and counters. Initial parity domain should exclude counter wrap,
   nonfinite gains and aliased channel consumption. No host callbacks under core
   locks. Device stream setup and bank/master composition stay in a host owner.
4. A joined host owner provides one selected clock, owns the device callback's
   native session lease, and stops/quiesces that callback before reset/destroy.
   No guest callbacks enter the device thread. Guest/RPC producer and device
   consumer operations serialize on the same native session state.

The reproducible dependency patch should replace the implementation behind all
`ps2_cri_audio` facade methods with a thin, versioned backend dispatch. Bootstrap
installs a strongly owned native session **before** any first PCM/RNA operation;
if unavailable, retain the entire current backend for that session. Capture all
callbacks before publication and fail closed on partial installation. Keep old
and new queue maps from operating concurrently on the same rings.

The bridge retains raw RNA/SJRMT/SJX lookup and generation association, the original
pending/reply ledger, 0113/0118 policy, guest publication and existing failure
translation. It calls the independent PCM core for actual queue/voice/watermark
operations. Replace device callback routing as one session-owned operation, not
by replacing a symbol while an old stream callback can still run. Preserve
separate sound-bank mixing and gain ordering until that module receives its own
complete extraction proof. Runtime source edits require a focused reproducible
patch and matching rebuilt library; none was made in this task.

## Gates before integration

* The current map/deque implementation has no global voice/channel bound or
  generation protection. Prove creation/destruction/reset/handle-reuse mapping
  before native backend selection; choose capacity failure translation without
  inventing guest errors or losing chunk return credit.
* Stereo left and right resolving to the same channel can double-pop one deque;
  multiple voices sharing a channel make consumption order depend on unordered
  map traversal. These cases are excluded from current fixture admission, not
  repaired or proven equivalent. First native integration must prove exclusive
  active channel ownership or retain that entire session's legacy backend.
* Multiple independent voices can still have float summation-order differences.
  The fixture covers distinct two-voice release preservation, not all mix orders.
  Establish deterministic order versus required tolerance before claiming bit
  parity for unrestricted multi-voice mixing.
* The fixture does not test real bank synthesis, a raylib stop/unload callback
  fence, device changes, races/reentry, allocation exhaustion, numeric counter
  wrap, complete RPC transport or original EE/IOP hardware. Its clock and sink
  are deliberately substituted. Add lifecycle/race tests around a native owner
  before connecting any host callback.

This unit can remove the host PCM queue/render implementation's PS2Recomp
dependency while leaving a narrow protocol adapter. It does not remove the
remaining original compressed-stream/SJ/ADXT owners or the separate sound-bank
implementation, and it must not be described as an already completed transition.
