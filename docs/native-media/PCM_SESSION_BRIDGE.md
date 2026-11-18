# Raw-ID PCM session bridge

Status: implemented, isolated composition component; no runtime/backend/device
installation. The bridge owns one native PCM Session and raw-ID metadata. It
implements all eleven reconstructed121 facade operations with typed refusal
results and host composition hooks. The dispatch patch, bootstrap, preparer,
dependency checkout and native PCM arithmetic are unchanged by this work.

The implementation is [session_bridge.hpp](../../game/native/pcm_bridge/session_bridge.hpp)
and [session_bridge.cpp](../../game/native/pcm_bridge/session_bridge.cpp). Read
[PCM_BACKEND_INSTALLATION.md](PCM_BACKEND_INSTALLATION.md) and
[PCM_DEVICE_LIFETIME.md](PCM_DEVICE_LIFETIME.md) before connecting an actual
provider. This component alone does not authorize that installation.

## Exact source and independent comparison

The reference is the unchanged complete `CriAudio.cpp` in reconstructed121,
`build-native-sjuni/dependency-workers-reapply-v2`, based on dependency revision
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f` and receipt SHA-256
`2b8088a430a63517ad2a77910970e37bccf9658e3c7c91ac6525a70b1db0cca8`.
The five source identities in `pcm_owner_oracle.py` are checked before every
comparison; `CriAudio.cpp` is
`39dce6882e561ad69a0112a330ecc4023a98c21365ac2fe8709f838fce4c9a06`.
The active dirty submodule is not a reference input.

The bridge candidate was frozen before differential runs at CPP SHA-256
`fcf284fa46a752f07a2f48a019cce8f6f2df8eae7d864aef787ca46854bc9649`,
header `0b7c0b6f70234110035d05757aa93095ea4176b069f55fd581dee00ade31f9f3`.
The unchanged native core is CPP
`fe31c38f6c276c60c1f1f7cbf5bea2d9132b83c85fd0b49629b0ca721bf4e844`,
header `9fe0aff92070569bfd6744856ea438b92099ec38f1875dc660261ef755b659cb`.
Expected source observations are never regenerated from a native algorithm.

[compare_source.py](../../game/native/pcm_bridge/compare_source.py) transports the
frozen original action transcripts through the bridge and compares:

| Original corpus | Cases | Snapshots | Float values |
| --- | ---: | ---: | ---: |
| PCM owner, original RPC stop/credit callers | 22 | 46 | 16,656 |
| Actual three-to-32 voice traversal and float cancellation | 8 | 49 | 44 |
| Missing/shared channels, voice zero, headless insertion and queries | 19 | 36 | 228 |

The bridge computes its **own** unordered traversal and bucket growth; original
order is asserted, never injected into it. Both GCC/libstdc++ and bundled
LLVM/libc++ reproduce their corresponding original orders, gain-call order,
channel contents/watermarks, cached gains, phase/debt, counters and float bits.
The original fixture hashes are pinned in the comparator. Actual-order outputs
deliberately differ between those libraries; there is no portable sorted-order
claim.

An additional unchanged-source caller transcript,
[source_hooks.inc](../../game/native/pcm_bridge/source_hooks.inc), observes host
poll/gain/bank/master/reset call order, invalid queue admission, a one-second
configure interval capped to one 250 ms advance **before** voice insertion,
zero-frame gain refresh and null renders. Its source executable runs before the
bridge executable; completed source observations are retained separately.
All reference providers and banks are mocks. This establishes candidate-source
behavior, not original EE/IOP or real audio-device equivalence.

## Mapping and operation ordering

The raw voice map accepts numeric zero, retains paused/disabled records, and
performs the same insert/update/erase/clear operations as the original default
`std::unordered_map<uint32_t,...>`. No `reserve`, manual key sort, native slot
order or assumption about a raw-ID allocator substitutes for traversal. Every
voice-map mutation republishes the complete native `set_mix_order` permutation.
Each gain refresh reads every raw voice in that order before applying any frame.
Channel sharing across different voices uses that same explicit order.

Nonzero channel references create **latent**, empty native channels as needed.
They are not source-visible until a valid queue request creates the original
logical channel. A nonzero missing source left channel must starve and accumulate
debt; raw left zero must skip without debt. A missing/zero right with a valid left
in stereo must starve. These behaviors are distinct. The raw right field is
retained even when mono or disabled; it is not passed as an active core stereo
reference in those modes. No channel is reclaimed on voice release, guessed ring
destruction or numeric ID reuse. Reset alone clears the raw channel namespace.

| Operation | Bridge composition |
| --- | --- |
| `ensureHostOutput` | Poll settings, then ensure the supplied provider; no PCM tick. Bank-only startup remains possible. |
| `queue` | Reject zero key/null/zero/odd/over-0x4000 input before provider/poll/tick. For admitted input, ensure output outside state locks, tick once, then insert/mark the channel and enqueue copied PCM16. Queue-full refusal follows the tick and leaves `end_byte` unchanged. |
| `configure` | Exclude same-nonzero-channel stereo before effects; ensure output, tick the **old** configuration/map order once, then create latent channels/raw voice, normalize/configure, store raw fields and publish new order. |
| `consumed` | Tick once **before lookup**, including unknown key zero/999; return zero for unknown or latent channels. |
| `render` | Refresh every gain even for zero frames; select frame clock and run CRI. Release the PCM state lock, mix banks, read master exactly once, then multiply/clamp. Null output still advances CRI and calls bank/master hooks. |
| `queuedSamples` | Inspect visible sample count without ticking. Unknown/latent gives zero. |
| `discard` | No tick. Existing queue empties and consumed becomes queued; unknown is a no-op. |
| `drain` | No tick. Core eligibility preserves the source's existing-playing/nonempty-left rule, including a disabled voice with a nonempty left queue. |
| `release` | No tick. Erase that raw voice, invalidate its native token, republish order and retain all channel queues. |
| `reset` | Reset stream routes, native PCM/maps/clock and raw metadata; preserve cumulative PCM frame statistics, live provider and independent bank voices. |
| `shutdown` | Close admission, wait complete accepted calls, obtain the supplied provider fence, reset routes/PCM, then reset banks. Terminal for this selected session; subsequent mutations refuse. |

The source headless tick runs only while output is not ready and no frame clock
has been selected. It polls settings and then reads supplied monotonic time.
Gains refresh only when at least one headless frame advances. The bridge first
calls `advance_headless(now)` explicitly, then passes the core's **committed
`last_tick_ns`** to the clocked configure/enqueue/consumed method. Passing `now`
again would incorrectly consume a second capped interval after long gaps. New
voice insertion/rehash must happen after that single old-order tick.

The source's gain hook cache remains stale until an actual render boundary;
creating/reconfiguring a record does not fetch its new gain eagerly. Phase,
pause/drain overrides, playing-transition late/skipped resets and unsigned volume
are supplied to the existing qualified core rather than reimplemented here.

## Finite admission domain

`Domain` version 1 declares maximum simultaneous raw voice records, retained
native channel records (including latent references), manual render frames, and
separate finite metadata arenas. PCM queues retain the source's 96,000 samples
per channel and 0x4000-byte input limit. The default is 64 voices/64 channels,
16,384 manual frames and 256 KiB per metadata arena. This is an explicit testable
domain, **not** a bound proved for retail gameplay.

PMR unordered maps allocate from preowned finite arenas with a null upstream.
Temporary maps prime node/bucket allocation classes at construction without
changing the actual maps' initial buckets. Erase/clear reuse pool storage and
preserve the actual map's source-like bucket history. Constructor exhaustion
throws before any provider publication. Runtime metadata exhaustion closes
admission with `metadata_capacity`; it cannot allocate unbounded fallback memory.
The isolated churn check performs 100 complete 32-voice create/release/reset
cycles without an ordinary heap allocation after construction.

New-record count overflow returns `domain_capacity` before the headless tick.
The provider ensure hook may already have run, as it runs outside state locks;
refusal is not a transaction that unwinds output startup. Capacity is not a
signal to retry a legacy queue. Existing source queue fullness is a separate
recoverable `queue_full` result. Invalid input and unsupported self-alias are
explicit refusals. Invalid gains, core counter/clock/token refusal or bounded
metadata exhaustion fault and close the session; accepted effects are not rolled
back or replayed elsewhere.

Remaining domain exclusions/requirements:

- Stereo left and right may not be the same **nonzero** raw channel in one voice.
  Original source can double-pop an aliased deque without a safe empty check;
  the core deliberately excludes this. Zero/zero is a skipped-left case.
- Stream and master gain must be finite in [0,8]. Unsupported stream gains fault
  before frames; unsupported master is only known after CRI and bank work because
  source order reads master there. No late fallback or rollback is promised.
- Counters/generations/clock must remain inside the core's finite domain. A
  signed supplied timestamp is monotonic host nanoseconds, not a PS2 address.
- Optional legacy log/dump/path-counter side effects are not implemented by this
  bridge. Native playback capability must not imply those diagnostics exist.

The actual File #1 allocator interval `[0x001E0000,0x001EFF00)`/stride 0x20
describes 2,040 possible numeric IDs across kinds. It does **not** bound retained
PCM channel records, all source inputs, voice incarnation count or all game
sessions. RNA_CREATE accepts sharing without a distinctness guard, raw allocator
fallback can reuse a numeric key, and channel metadata can outlive ring metadata.
Do not derive an installable capacity profile from that interval alone.

`pre_run_state()` reports whether first use has occurred, health, open admission
and the declared finite domain. Its `complete_runtime_installation_proved` is
always false in this isolated component. First-use/healthy flags are not an
installation token. Before publication an eventual bootstrap must independently
establish exact runtime/build/provider identity, the declared whole-session
capacity and alias/gain domains, ready-state behavior, matching compiler order,
and ExternalWorker registration. There is no real native provider installed here.

## Ownership and fences

Each accepted facade call owns an in-flight lease spanning ensure-output,
serialized CRI work, **and** subsequent bank/master hooks. Shutdown first closes
admission and waits those complete calls, then invokes `stop_join_output` outside
PCM locks. False preserves PCM/banks for a later shutdown retry. Success allows
routes/PCM reset followed by bank reset; repeated successful shutdown is inert.
`close_admission()` is a nonblocking signal only. Neither it nor a ready flag is
a callback fence.

A thread-local linked call stack detects self-shutdown (including synchronous
ensure-output -> render reentry and stop/join hook reentry) and returns
`reentrant_shutdown` instead of waiting on itself. Provider creation runs outside
PCM locks; gain/poll/route hooks retain the original no-PCM-reentry requirement.
The host object is strongly owned. External callers/callback shims must likewise
retain this Session through their last use; the destructor neither invents a
provider fence nor shuts down an unknown device automatically.

The deterministic lifecycle test pauses a call **after** CRI inside bank mixing,
starts shutdown, observes closed admission and no fence/reset yet, then releases
the bank call. It also checks self-shutdown refusal, provider fence failure/retry,
and terminal admission. These tests exercise an abstract host, not raylib's
actual detach/unload path. A future callback shim must zero an output buffer when
render is refused after admission closes; it must never reopen legacy output.

Both compilers pass 6,551 unit assertions. The future Host must serialize provider
creation/readiness/lifecycle internally: several producer calls can enter
`ensure_output()` concurrently, outside PCM locks. Its lifecycle lock must never
be needed by the audio callback. Host gain/poll/route hooks remain non-reentrant;
bank/master hooks run after the PCM lock is released.

The actual raylib lock/fence and runtime unwind rules remain those in
PCM_DEVICE_LIFETIME. No claim is made that an actual provider meets the abstract
`stop_join_output()` promise until its implementation is source-qualified and
tested separately.

## Reproduce

Run with an existing C++20 compiler and ignored output directory:

```powershell
python game/native/pcm_bridge/compare_source.py `
  --cxx C:/msys64/mingw64/bin/g++.exe `
  --output build-native-sjuni/pcm-session-bridge-final/gcc `
  --order-fixture build-native-sjuni/pcm-order-oracle/gcc/fixtures.json `
  --domains-fixture build-native-sjuni/pcm-source-domains/gcc/fixtures.json
```

Use bundled LLVM and its corresponding `llvm` order/domain fixtures for the
second toolchain. Receipts retain compiler/source/fixture identities, commands,
original observations, bridge observations, differences and unit-check output.
No game, audio device, assets, runtime registration or dependency build is needed.
