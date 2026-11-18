# PCM missing/shared-channel source domains

Status: exact reconstructed-host-source observations, 2026-11-05. These are
**not original EE/IOP hardware measurements**. No game, native candidate core,
audio device, bank synthesizer or asset was executed. The purpose is to define
additional optional native PCM admission profiles before connecting a backend.

[pcm_source_domains_oracle.py](../../tools/native_reconstruction/pcm_source_domains_oracle.py)
compiles the entire unchanged reconstructed121 `CriAudio.cpp`. It reuses the
pinned [original PCM harness](../../tools/native_reconstruction/pcm_owner_oracle.py)
only for its complete-source include, supplied clock and no-device/bank mocks.
The independent [native PCM core](../../game/native/pcm/README.md) is neither
imported nor inspected to produce expected values.

Both GCC and bundled LLVM/MinGW pass the **19 cases / 36 pre/post observations /
228 rendered float values**, including nine shared-channel cases. Fourteen
source-domain test methods pass. No existing frozen corpus or engine was edited.

## Source identity and observation format

The dependency reconstruction receipt SHA-256 remains
`2b8088a430a63517ad2a77910970e37bccf9658e3c7c91ac6525a70b1db0cca8`.
The source version includes public policies 0113 and 0118. Its complete
`CriAudio.cpp` SHA-256 is
`39dce6882e561ad69a0112a330ecc4023a98c21365ac2fe8709f838fce4c9a06`.
The generator additionally verifies the same frozen `CriAudio.h`, `State.h`,
`RPC.cpp` and `cri_pcm_retire.h` identities as the original PCM owner oracle;
only the complete audio implementation and its headers are compiled here.
This task does not execute the RPC/SJ publication methods.

Each schema-2 artifact separates `inputs` from expected `records`. Input actions
contain raw source IDs, rates/counts, PCM16 samples, supplied timestamps, gains
and calls. Every observed action has its transcript `action_index`, complete
actual `declared_raw_order`, actual `gain_read_order`, rendered float bit
patterns, and complete relevant `pre_state` / `state`:

- All voice records, including paused/disabled/zero-ID records: raw left/right
  references, normalized channels/rate, volume, playing/draining, fractional
  phase bits, late/skipped counts, supplied host gain and source cached gain.
- Every queue's remaining samples in order, queued/consumed byte watermarks and
  sample count; global output/signal/underrun counters.
- Actual unordered-map traversal and bucket metadata, frame-clock selection,
  supplied time and retained last-tick time.

The observations are single-threaded: pre-state capture cannot race a real
device callback. The source still holds its normal mutex during its own calls.
Expected output is the compiled source's output; Python does not implement a
mixer or predict container traversal. Compiles disable FP contraction and retain
the existing supplied-clock/no-device substitution.

## Observed domains

| Source input | Measured behavior |
| --- | --- |
| Playing voice with raw left key zero | Skip the voice before queue lookup. No starvation debt or underrun contribution; phase stays unchanged. Gain is still acquired in the complete per-render traversal. |
| Playing voice with nonzero left key but no queue | Render silence and accrue late-sample debt/underrun frames. Missing queue lookup does not create a channel. Later real samples repay the debt through actual pops. |
| Stereo with right zero or a missing nonzero right queue | Starve without consuming the existing left queue. After both queues become available, repay late debt by paired pops and advance both consumed-byte watermarks. |
| Raw channel count zero | Retain the configured record and queue but skip consumption/debt. Playing can remain true; gain acquisition still includes the record. |
| Raw voice ID zero | `configure(0,...)` creates a real voice and it can play nonzero PCM. `release(0)` removes that record while retaining channel data. Raw ID zero must not be confused with an empty typed native token. |
| Raw channel counts 3 / `UINT_MAX` | Source clamps them to two. Zero frequency becomes 48 kHz; high frequency clamps to 96 kHz. This is raw-facade normalization, not permission to cast arbitrary values to a typed native enum. |
| Distinct voices sharing mono, stereo, one-side or crossed channels | Each voice observes/pops the current shared queue in the actual recorded traversal order. Consumption is not deduplicated per channel or rendered frame. Mixed rates and debt evolve independently per voice. |
| Shared channel plus drain, pause and release | Drain overrides a subsequent false configure until exhaustion; immediate pause of another voice retains its state/queue. Exhausted draining voice stops. Releasing that record retains the shared channel. |

The corpus records both insertion orders for shared mono and shared stereo,
partial sharing, reversed stereo sides across two distinct voices, and three
mixed-rate voices sharing two channels. All stereo voices have distinct left
and right channels within their own record. These bounded cases do not imply
that every arbitrary sharing graph, queue limit or counter boundary is admitted.

Two additional headless boundaries are explicit:

1. At supplied time 83,334 ns, `consumed(999)` for an absent raw channel returns
   zero **after** advancing an existing 48 kHz voice by four frames and consuming
   eight real bytes from channel 1. It does not create channel 999. A known
   channel query at the same timestamp returns eight without another whole
   frame. A typed invalid-token refusal before advancement is a different API
   contract; any raw facade must preserve the source tick policy explicitly.
2. `configure(20,...)` at 41,667 ns first ticks the already-existing voice 10,
   acquiring only its gain and consuming two samples, then inserts voice 20.
   The observed pre-call order is `[10]`; the new record appears only afterward.
   Its cached mixer gain is initially one while its supplied host gain is 0.75.
   The next render refreshes the complete gain traversal. These two gain fields
   are intentionally separate; source cache representation is not automatically
   a typed native API obligation.

A zero-frame render still selects the frame clock and reads gains for every
record, while advancing no PCM, frame counter or queue watermark. Counter
snapshots remain cumulative across source `reset`, matching the source's
diagnostic-counter retention.

## Same-voice stereo alias is excluded

The generator rejects any stereo configuration whose left and right raw keys
are equal **before generating or executing C++**. No such case is probed.

Static inspection of the exact pinned `renderLocked` explains the boundary:
when both iterators reference the same deque, the late-skip and ordinary
phase-pop paths test nonemptiness, pop left, then pop right. With only one
remaining sample the first pop empties that same deque and the second
`pop_front` has undefined behavior. A second pop cannot be given a trustworthy
expected state by running it. Even configurations that happen to have two
samples available initially do not close their later exhaustion path.

This is distinct from sharing across separate voices: each voice's separate
left/right pair in this corpus remains valid within its own pop, and the next
voice performs new queue availability checks. First native profiles may reject
all self-stereo aliasing instead of inventing a repair or claiming parity for
undefined source behavior.

## Frozen artifacts and reproduction

| Compiler | Fixture bytes | SHA-256 |
| --- | ---: | --- |
| GCC | 148,087 | `15547497f2fa81c1c9f50f40ddc5a67f5b84176dfe3d552e6a939e4a63c86206` |
| Bundled LLVM/MinGW | 148,015 | `b3fcb8285711942c47fa3d644f1d236c8474db5442428d81b1bd911b90edd6e8` |

Outputs live under `build-native-sjuni/pcm-source-domains/{gcc,llvm}`. Fixtures
contain compiler identity; receipts also pin source, generator, mocks/harness
and compile/run outcomes. Whole records differ in container bucket metadata,
while all 36 raw/gain-read orders and all 228 rendered float values coincide
between these two compiler builds for this corpus. This finite agreement does
not establish a universal `unordered_map` order. Native comparisons should
consume each source's recorded order, not reproduce bucket policy by guesswork.

```text
python tools/native_reconstruction/pcm_source_domains_oracle.py --cxx C:/msys64/mingw64/bin/g++.exe --output build-native-sjuni/pcm-source-domains/gcc
```

Repeat with the bundled LLVM/MinGW compiler and the `llvm` output directory,
then run:

```text
python -m unittest discover -s tools/native_reconstruction -p test_pcm_source_domains_oracle.py -v
```

Optional native missing/shared-channel profiles still need independent fixture
comparison and complete ordered traversal before admission. Default-disabled
profile flags do not constitute real backend installation. Raw generation
mapping, channel close/reuse, source credit ownership, a joined device callback,
bank/master composition, concurrent reset/shutdown, real playback and speed
remain outside this source-domain corpus.
