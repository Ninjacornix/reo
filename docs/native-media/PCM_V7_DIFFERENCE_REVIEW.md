# V7 PCM differences: measured symptoms and source review

Status: read-only review, 2026-11-05. No game/device run, build, benchmark or
production-code change was performed for this review. Frozen PCM, bank source,
bank candidate and oracle files were not modified. Source work estimates below
are algorithmic counts, not measured CPU durations or a slowdown diagnosis.

V7 proves native PCM execution and clean lifetime completion, but its starvation
and worse sampled movie tail remain unresolved. The strongest source-level
performance differences are repeated capacity-wide validation, gain/control
lock work and a much larger eager arena. The reviewed ordinary PCM arithmetic,
clock suppression and bank/master order retain the selected source contract.
No confirmed arithmetic defect here explains the recorded gaps.

## Measured V7 evidence

Both sessions use source `f4ec2248c9652834c4e6e76dd6be331993d5a6ad`, kit manifest
`736a17112a98725e8c768d823157028c6183e0a8817e1720b7fd56ca1803511f` and executable
`007ae82ac9538b40b27d229db6cec2e83e1ec21ced292dc915be144c0be2fa18`.
The private sessions are `media-legacy-pcm-v7` and `media-native-pcm-v7` under
`build-native-sjuni/playtests`. Their reports, environment and limits are also
summarized in [CANDIDATE_VALIDATION.md](CANDIDATE_VALIDATION.md).

| Observation | Legacy | Native |
| --- | ---: | ---: |
| Run seconds / exit | 454.922 / 0 | 363.546 / 0 |
| Approximate sampled movie return intervals | 18,348 | 17,749 |
| Movie interval p99 | 17.6363 ms | 17.9097 ms |
| Movie intervals above 50 ms | 0 | 4 |
| Maximum sampled movie interval | 34.2693 ms | 1,098.2157 ms |
| Reported PCM output frames | 20,723,040 | 16,990,560 |
| Reported signal frames | 18,735,858 | 14,962,642 |
| Reported starved frames | 0 | 40,256 |

Legacy counts are summed from 431 periodic windows; native counts are its final
cumulative report. They are unequal-duration, unequal-coverage totals. Native
starvation is about 0.237% of its counted output frames, nominally 0.839 seconds
of 48 kHz frame positions. That is **not** a measured device-underrun duration:
the counter marks an output frame where any contributing voice lacks required
source PCM, including a zero-volume voice. It is not an OS audio dropout counter
and does not locate starvation in time.

The native final report at stderr line 8284 records 35,397 callback attempts and
35,397 completions, actual stream start/fence/join, zero hard failures and zero
backend queue rejections. Completed calls include 271,785 configure, 539,397
consumed, 11,188 queue, 35,397 render, 100 ensure, 5 drain, 8 queued-samples, 1 reset
and 1 shutdown. Discard/release have no delivered-body coverage. Facade validation
or stopped calls suppressed before backend delivery are not included in those
totals; zero backend rejections does not attest every caller input.

Native total frames equal its device frame requests exactly: 16,990,560, averaging
480 frames per completed callback. Under these counter semantics, with statistics
preserved across reset, there is no evidence of additional **counted** headless
advancement or manual-render frames in this run. This does not prove every
startup/reset clock transition generally correct or explain starvation.

The four sampled movie gaps have these retained CPU-boundary observations:

| Frame CSV lines | Return interval ms | Between neighboring capture spans ms | Retained movie-work overlap |
| --- | ---: | ---: | --- |
|12370→12371|1098.2157|1097.6546|none|
|12445→12446|422.8647|422.1578|none|
|18971→18972|297.5084|296.8456|none|
|5900→5901|54.6346|54.0529|owner-control 52.1549 ms containing batch-fence 46.7995 ms|

Nested spans are not added together. The first three gaps chiefly lie outside
their neighboring graphics capture work. They cannot be assigned to PCM, GPU,
guest execution or OS descheduling from that fact. Movie-work schema 1 retained
its first 4096 slow events and dropped 14,369 later native events (15,194 legacy),
so absence of an overlapping retained event is incomplete evidence. Native PCM
has no per-window starvation timestamps to correlate with these gaps.

Fresh cards/ordinary confirmations and environment parity do not eliminate
asset/OS cache effects, unequal routes/durations, controls differences or
concurrent development work. The native controls exercise succeeded; the legacy
controls check found another phase and sent no input. These are single-order
private cases, not a matched pause/restart/waveform or causal performance test.

## Reviewed source identity

The current relevant files match V7's frozen source commit after newline
normalization. Actual byte hashes inspected here:

| File | SHA-256 |
| --- | --- |
| [PCM core](../../game/native/pcm/pcm.cpp) | `fe31c38f6c276c60c1f1f7cbf5bea2d9132b83c85fd0b49629b0ca721bf4e844` |
| [PCM bridge](../../game/native/pcm_bridge/session_bridge.cpp) | `fcf284fa46a752f07a2f48a019cce8f6f2df8eae7d864aef787ca46854bc9649` |
| [runtime binding](../../recomp/overrides/native_pcm/runtime_adapter.cpp) | `29a1393f77137ba7c8b8a6f551a1b4888e1cfebfa6b5de0726e4d762e7cbc7f4` |
| [output owner](../../game/native/audio_output/audio_output_owner.cpp) | `ead835bd2d09fc427808e99cd374d0e6b4e8e3633c9d98324bc6f21db5f5dc16` |
| [stream provider](../../runtime/audio/native_stream_provider.cpp) | `8bb9a6d99cd81e2b9d24f4ac8d1984ac878f447aee0962de2a631d43e19fe8bf` |
| unchanged124 `CriAudio.cpp` | `c27f088eab74a7a914ddcb32efbda4923d0b174c059f9c5029e6ec20f8096580` |

The legacy source is the qualified full124 reconstruction at
`build-native-sjuni/dependency-pcm-boot-reapply-v3`, not the different active
dependency. Its method bodies are the selected comparison, with the same
dispatch/public boot transaction used by V7.

## Source-confirmed work and synchronization differences

Let `R` be actual raw voice records, including paused/disabled records, and let
`C=2041` be the declared voice-slot capacity. V7 does not report the actual
record-count high-water mark, so it must not be invented from capacity.

| Path / exact reference | Difference and implication |
| --- | --- |
| Bridge`refresh_gains`, lines105–121; core`gain`, line369 | The bridge reads all R gains in map order, stages/validates them, then takes the core mutex and validates a weak/session/generation handle separately for each gain. Legacy `renderLocked`, line 57, reads gains into its existing records under one PCM mutex. Native adds lock/refcount/validation work; cost is unmeasured. |
| Bridge `order`, line 100; core `set_mix_order`, line 267 | Every render gain refresh and every successful configure republishes order. The core counts active slots across all C, checks each supplied handle and checks duplicates with an R² loop before copying the order. Existing-voice configure does this even if map membership/order did not change. |
| Core `preflight_frames`, line 87 | A positive valid ordered render still traverses all C slots in its playing-domain check and all C again for counter safety. It does not limit these passes to the ordered records. |
| Core `frames_locked`, line 116 | **The sample loop uses `mix_order_count=R` when explicitly ordered. It does not mix all 2041 slots for every frame.** Compared with legacy map traversal/hash lookups/deques, indexed ring storage can remove other work. Do not extrapolate a capacity-per-sample slowdown. |
| Host `ensure_output`, binding line 101; output Owner `start`, line 60 | Queue/configure invoke serialized ensure outside PCM data locks. Even an already attached stream takes the ensure mutex and Owner lifecycle/strong-reference path and updates cache atomics. Legacy `ensureOutput`, line 111, has a cheap `ready` early return. These are frequent producer-path differences, not measured stalls. |
| Bridge `tick`, line 123; core `clock/enqueue/configure/consumed` | Device-ready tick still polls settings, reads time and locks core for clock state. Queue/configure/consumed then enter additional core methods/clock snapshots under the bridge data mutex. Legacy performs the corresponding tick/state work inside one PCM mutex. Headless ordering remains semantically necessary; removing query-driven progress indiscriminately would be wrong. |
| Native admission/leases | Registry/binding admission, atomic backend and output gates, bridge gate accounting, strong/weak owner leases and notify operations provide lifetime proof at extra cost. The direct device callback avoids a facade registry trip, but gains the slot/Owner/Backend/bridge route. None of these costs has been individually timed. |
| Storage/copy | Native eagerly allocates 391,680,000 sample bytes plus 4 MiB metadata and bookkeeping, versus legacy queues that grow with actual data. Native scalar ring writes/reads replace deque operations. V7 records no resident-set/page-fault or per-copy timings, so memory-related timing attribution is unknown. |
| Buffer clearing | The backend clears bounded output before bridge admission/failure handling, and the core clears again before mixing; legacy has its own one render clear. Raylib also clears its buffers. This is a smaller confirmed duplicate-work opportunity; removing failure silence would be a semantic regression. |

Using completed V7 calls, configure plus render gives 307,182 known order updates.
The active-slot count pass alone corresponds to
`307182 * 2041 = 626958462` source-level slot visits, regardless of zero-frame
renders. If every render is positive, preflight adds
`35397 * 2 * 2041 = 144490554` visits. Callback frame histograms were not captured;
the qualified maximum of 512 frames and total 16,990,560 imply at least 33,185
positive calls. Thus the preflight estimate is bounded at
135,461,170–144,490,554 visits rather than presented as an observed exact count.
These counts omit other paths and do not count generated instructions, cache
misses or elapsed time. They identify a reproducible optimization/benchmark
target. They do not explain a 1.098-second gap without timing evidence. Duplicate
checking scales with R, which was not captured; capacity cannot stand in for
measured R.

### Lock paths and preserved bank separation

Raylib's reviewed `OnSendAudioDataToDevice` holds its audio-system lock over the
registered callback in both modes. In legacy mode the callback obtains the
legacy PCM mutex, renders, releases it, then takes the unchanged bank mutex
inside bank mixing. Native follows:

```text
audio-system lock
  slot snapshot lock (short; released)
  output/backend atomic leases
  bridge admission lock (short; released)
  bridge data lock -> core lock(s) -> CRI render
  release bridge/core locks
  unchanged bank mutex/mix -> master gain/final clamp
  release lifetime leases
```

Producers commonly enter the facade under guest/RPC locks, then bridge/core
locks. Neither callback may take those guest/RPC locks. Native provider start is
outside the bridge data lock; cached `output_ready` is atomic and never calls
provider status/control under that lock. Join closes admission/drains before
calling a provider fence, with no PCM/bank/guest lock held. This review found no
new demonstrated inversion on that path. Timing is still required to distinguish
contention waiting from work or descheduling.

The unchanged bank mixer remains common work: 224 gain samples per valid mix,
sequence ticks, allocation/voice/envelope work and its mutex. Its callback is
still within raylib's outer audio-system lock. Native holds a **lifetime lease**
through bank/master work, not the PCM data mutex. Moving bank work under that
mutex or joining it from a callback would change the reviewed safety/order.
Independent bank/RPC producers remain outside complete PCM producer admission.

## Semantic paths checked against the selected legacy source

- Front-before-advance sampling, double fractional phase, paired stereo pops,
  missing-channel starvation, debt repayment by real pops and consumed-byte
  watermarks match the admitted source model. Starvation is counted before bank
  mixing, independently of whether a final speaker sample is audible.
- Both clamp channel count, default/normalize rates, retain paused phase and
  queues, cancel drain on true configure and finish an accepted drain on empty
  input. Exact124 `drain`, lines280–287, clears **late** debt only; native core
  lines435–447 does the same. Both preserve skipped-history there. Playing-state
  transition reset is a different configure operation.
- The bridge ticks the old configuration/order before inserting/updating a raw
  voice and uses a frozen last-tick argument to avoid a second implicit advance.
  Unknown consumed queries still tick before returning zero. Existing raw-order/
  missing/shared-channel fixtures support these finite contracts; they do not
  prove every runtime input graph.
- Core frame clock, atomic live-output suppression and reset retain the source
  distinction between headless and callback advancement. A first output attempt
  reserves suppression before callback publication; ready stays reserved until
  a real fence. The V7 frame totals give no positive evidence of a double clock.
- All R gains are read in actual map order before rendering; ordered float sums,
  CRI clamp, unlock, bank mix, master and final clamp retain their order. Numeric
  gains/capacity/render/alias restrictions are explicit native admission limits.
  V7's zero hard-failure report excludes an observed delivered-body refusal of
  those types, not every possible semantic mismatch or caller-side rejection.

This source comparison does not establish real speaker waveform equality or
complete raw-ID incarnation/guest credit ownership. Existing Source/Bridge/Core
oracles and the runtime binding checks remain the right regression references.

### Diagnostic behavior differs despite equal environment settings

Native selection bypasses legacy `tickLocked` periodic CRI windows, first/play/
position logs, per-voice path reports and producer PCM capture in legacy queue.
The native backend instead emits final counters. V7 metadata confirms **five
legacy PCM files totaling 3,387,456 bytes versus none native**, and 11 legacy
first plus 11 play logs versus none native. This is a real difference in enabled work and in
available evidence; matching environment strings alone do not equalize it.

The legacy dump occurs on its producer path under the PCM mutex; it is not a
device callback. Its extra work does not prove why either run was faster/slower.
For future performance comparison, use matched diagnostic capabilities or turn
those optional legacy captures/logs off in both sessions and collect one common
bounded timing/counter protocol. Absence of native legacy windows must never be
reported as zero native starvation.

## Prioritized next controlled checks

1. **Establish the next binary's PCM0 baseline first.** Validate V8's changed
   movie position/timing probes with native PCM off, then use the same frozen
   binary/route/actions/duration for PCM0/1 in balanced repeated order. Record
   cache/warmup policy and use quiet runs without compilers/copies or other
   controlled background work. Do not combine a bank-owner
   switch or an unrelated PCM optimization into this attribution test.
2. **Add bounded shared-clock incident evidence before another causal claim.**
   Record callback arrival/frame count, wait/hold times for bridge/core/bank
   boundaries, producer operation durations, R/high-water counts, queue levels,
   clock mode/ready and starvation deltas. Use preallocated bounded telemetry
   with drop counters and no callback I/O. Attest clock origin/frequency against
   movie timestamps; do not assume two timestamp APIs share an epoch. Preserve
   recent and longest incidents rather than only the first 4096 events.
3. **Measure the identified source work offline before changing it.** Replay
   frozen complete-host PCM/bridge transcripts with matching release flags,
   controlled clocks/gains and R varied independently of capacity C. Time
   construction separately from steady configure/consumed/render. Include
   sparse R at capacity 2041, then larger R. Report core/order/gain/lock counts
   and timing distributions; verify unchanged output/order/watermarks throughout.
   No game/device is needed for this initial test.
4. **Separate starvation from callback execution cost.** A timestamped empty
   queue during producer inactivity suggests a different next check than a
   populated queue blocked behind a long lock/CPU span. Keep bank elapsed work,
   nested waits and scheduler descheduling separate. V7 has no data to choose
   among them, and its three largest movie gaps lack retained overlapping work.
5. **Only then test one source-preserving optimization.** Candidates are cached
   order until membership/rehash changes, a maintained active-slot set/count,
   linear permutation validation and batched gain/order commit under one core
   lock. Keep gain sampling for paused/disabled/zero-left records and exact
   float order, tick-before-configure behavior, handle generations and failure
   silence. A cheap already-ready ensure path and duplicate-clear reduction
   are later small checks. Do not reduce proven capacity just to improve a test
   or remove admission/fence safety based on assumed timing cost.

No proposed check has been run by this review. The current native tail and
starvation remain acceptance failures, while the actual lifetime/execution
evidence remains valid. A successful fix/retest and matched evidence are required
before attributing responsibility or enabling the backend by default.

Evidence JSON hashes at review time:

| Session / report | SHA-256 |
| --- | --- |
| legacy PCM analysis | `250d70bc393c7550b510e21f2000a515d5567b48f90cbb63a27add1d8bd1dda1` |
| native PCM analysis | `7e81741f6f5c33dbc1c258fc0dd81194b868d7833c322f749eafc908400db306` |
| legacy movie pacing | `eeea0b22f4c541837f714d0e07f47d45b6cb8b8922e70dae9a55ad94f558e84c` |
| native movie pacing | `a92f5fbde5cf183cf43e230753420f7ccf57fefe85400ff94e3ce1c29dd212d7` |
| legacy movie work | `c998a4d62ea2122dbead5e463a3712c05e7b42bb3b4ea0173287ef453a1807cd` |
| native movie work | `5767593d05422d55c2eacd338e63724ca029b04b34e13ce696b967656d98927e` |

Each report retains its raw log/frame/work-file hashes and process identity.
Read-only source references: [bridge](../../game/native/pcm_bridge/session_bridge.cpp),
[core](../../game/native/pcm/pcm.cpp),
[binding](../../recomp/overrides/native_pcm/runtime_adapter.cpp),
[output owner](../../game/native/audio_output/audio_output_owner.cpp),
[gain routing](../../runtime/audio/mixer.h), [host controls](../../runtime/audio/host_bridge.h),
[source-domain evidence](PCM_SOURCE_DOMAINS.md),
[render-order evidence](PCM_RENDER_ORDER.md), and
[binding/lifecycle evidence](NATIVE_PCM_BACKEND.md).
