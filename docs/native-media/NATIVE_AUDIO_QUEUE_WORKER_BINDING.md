# Native queue feeder callback binding checks

Both compiler cohorts pass the focused actual ordinary-adapter checks for the
independent native queue feeder. The fixture uses real imported audio, the
production `ordinary_runtime.cpp`, real canonical owner admission, cue queue,
metadata loader, decoder/source workers and output submix. It supplies declared
runtime/factory/registration ports; it does not link the production composite
worker or run a game/device.

The fixture captures the exact callbacks registered by the adapter:

```cpp
bool reader(const Owner*, uint32_t&, shared_ptr<void>&) noexcept;
Instances::Status work(const shared_ptr<void>&, Instances&, uint32_t) noexcept;
```

It calls the reader outside native owner admission, retaining its opaque
binding context, then calls the captured work and native instance service under
the real owner. The cached tick is an actual prior guest-group observation.
No synthetic host-clock tick is introduced.

| Scenario | Required observations |
| --- | --- |
| `native_queue_feed` | A real loader task is held on a blocking immutable view. The actual queued ABI request remains pending behind it. After release, the native callback commits the prepared header and completes all **189,476 samples per channel**, matching independently qualified PCM digests, without another guest group call. Pause/resume, stop/reset, and queue-to-file feeder removal pass. |
| `native_queue_destroy` | Native metadata completion/playback and pause/resume pass, then original child destruction closes/removes the native feeder before its key is released. A retained binding context cannot service the invalid old key; post-destroy native work is harmless or defers pending order publication. Closing refuses further reader/work admission and owners join. |
| `native_queue_order` | A third real game key is adopted without publishing a replacement summation order. Even after the queued source's header is ready, native work returns `order_required`, preserving the pending header and unpoisoned queue. Explicit native order publication releases the work, after which the full finite stream/digests and lifecycle checks pass. This case has one playing queued source and two other constructed keys; it does not claim three simultaneous queued voices. |

During native reader/work/refill phases the fixture protects the complete
32 MiB guest RAM allocation with `PAGE_NOACCESS`. It also compares all bytes
before and after those phases. The cached tick remains frozen; only the later
explicit guest group used for the queue-to-file transition advances it.
Foreign owner identity is refused by the reader; a foreign native instance
domain and null work context are refused by native work. Before the first
actual guest-group tick, the reader refuses admission. Paused playback does
not consume output despite continued native service.

The pending-header gate occupies a separate loader job, while the ABI-enqueued
cue retains its actual verified imported member. It therefore proves that the
registered native feeder commits asynchronous queue metadata; simply calling
the decoder's instance service cannot satisfy that test. The private fault
removes `native_queues[record.handle.slot]=queue` from an otherwise matching
adapter copy. Both compiler cohorts detect that fault. Production source is
not mutated for the fault run.

Final v2 cohorts compile the same production adapter SHA256
`5096f8f723548b6a7fb614144bc1246b9c92be4ca2530aca2f3210b6e88223b7`
and fixture SHA256
`6ea2726ee924dfa5b2dabed44695a9a38617a9125484a3ca48af426abe45bcdd`.
Their receipts are:

- LLVM: `build-native-sjuni/adxt-binding/native-queue-feeder-llvm-v2/receipt.json`,
  SHA256 `0f909d73f986f17f06199ac30e89277b72455fca9b5767faeda641c5a12d1a03`.
- GCC: `build-native-sjuni/adxt-binding/native-queue-feeder-gcc-v2/receipt.json`,
  SHA256 `b53217a79295441950e5d383c6b7714011b25761f248f0fca1c58a57c646d46e`.

The earlier v1 cohorts passed the first two scenarios and the fault check;
v2 adds pending-order coverage. All immutable imported file identities remain
unchanged. Source snapshots, compiler identities, fixture inputs and linked
archive hashes are retained with each receipt.

The focused verifier reuses the qualified native-80 audio/core archives rather
than rebuilding them. The current host-movie session source has the later V36
private fault diagnostic, so its old archive is explicitly **excluded** from
this audio-only link. The verifier permits only that exact identified source
drift and checks every other native source and retained archive identity.
This is not a claim that the current complete native project passed a fresh
80-suite run. The archive cohort and the older full ordinary-adapter regression
remain separately identified.

Run `verify_adxt_native_queue_feeder.py --help` for the required compiler,
native receipt/manifest, qualified baseline fixture, owned import and fresh
output arguments. Use `--detect-missing-feeder` to run the private fault check.
No Python/developer installation is part of the player's feature.

Actual independent worker/thread timing, a two-second withheld guest-service
comparison, full ordinary-adapter regression, coherent candidate/game retests
and the outstanding V36 resource/audio incident are separate gates. These
focused binding checks do not close Step 3 or establish a game slowdown fix.
