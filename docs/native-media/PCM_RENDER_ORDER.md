# PCM render-order evidence and native contract

Status: exact reconstructed-source offline evidence, 2026-11-05. No game, device,
asset, dependency patch or native-core execution was used by this investigation.
This studies the public reconstructed121 host PCM implementation, **not original
PS2 hardware**. The existing [PCM owner extraction](PCM_OWNER_EXTRACTION.md)
continues to govern raw-handle generations, stop, SJ credit and device lifetime.

The implicit native PCM core's two-playing-voice admission is justified as a
conservative boundary. Three independent contributions can produce different
float results solely because the original unordered-map traversal changed.
An explicit native render order can support a wider domain, but the bridge must
transport the real source order and preserve its mutation/clock boundary.

## Exact source and harness boundary

The [order oracle](../../tools/native_reconstruction/pcm_order_oracle.py) verifies
all five original source identities used by the frozen
[PCM owner oracle](../../tools/native_reconstruction/pcm_owner_oracle.py).
The source root is the independently reconstructed public dependency tree
`build-native-sjuni/dependency-workers-reapply-v2`; it does not use the dirty
active submodule's different audio implementation.

| Input | SHA-256 |
| --- | --- |
| Complete `Kernel/Syscalls/Helpers/CriAudio.cpp` | `39dce6882e561ad69a0112a330ecc4023a98c21365ac2fe8709f838fce4c9a06` |
| Complete `CriAudio.h` | `7103ab05367839041672898c6406ca42a41482bff1640e4a1faecfd7aa52f4be` |
| Complete `Kernel/Syscalls/Helpers/State.h` | `4cab412ab2c6a54e3ff14a6f619ce61c850cae8e3b80d92d86c3bef22eb1b4b8` |
| Complete `Kernel/Syscalls/RPC.cpp` | `050d63e738481ac592429a21ba317fcb28f86f8d47afe48b2ee4ed8c3dc81a9f` |
| Complete `cri_pcm_retire.h` | `b7dc48ac1279f07032fbfd1de39049f0da7fd15fac8d73a4f5708912f022cbc8` |
| Frozen harness provider | `697194d2089779baf86074cf8cce28819607c4f7fd2e7561bcf557ac1d189183` |
| Reconstructed121 receipt | `2b8088a430a63517ad2a77910970e37bccf9658e3c7c91ac6525a70b1db0cca8` |

The complete PCM source is copied byte-for-byte and compiled unchanged. The
existing controlled-clock prefix aliases ordinary standard-library names to the
real implementation while replacing only `steady_clock`. Device readiness is
false; a mock bank/master sink adds no samples. `reoAudioStreamGain` returns
supplied finite per-voice gains and records its actual query order.

No native mixer arithmetic is imported. The source's own `render` produces every
expected float/state observation. Builds use C++20, `-O1 -ffp-contract=off`, with
warnings treated as errors. Source/container behavior is specific to the recorded
compiler/standard-library combination; it is not a portable unordered-map policy.

## What the source and corpus establish

`CriAudio.cpp:37` stores voices in `std::unordered_map<uint32_t,Voice>`.
`renderLocked`, starting at line 56, first queries gains once for **every** voice
record in map order, including paused records. Each requested frame then visits
the same map order, skipping nonplaying/disabled records, accumulating floats
and clipping only the final combined left/right values. No key sort or stable
insertion-order list supplies the original traversal.

The corpus has **8 cases, 49 snapshots and 44 rendered float values** with both
GCC and the bundled LLVM/MinGW. Six cases configure the same three disjoint mono
voices in all permutations. Inputs are PCM samples `+32767`, `-32767`, `+1` and
finite gains `7.7f`, `7.7f`, `0.01f`. Each output is far below clipping, so the
difference cannot be attributed to saturation.

| Actual traversal before render | First output bits | First output value |
| --- | --- | ---: |
| `[30,20,10]`, `[20,30,10]`, `[30,10,20]`, `[10,30,20]` | `35000000` | `4.76837158203125e-7` |
| `[20,10,30]`, `[10,20,30]` | `34a3d70a` | `3.0517577442878974e-7` |

These are measured outputs from the unchanged source. They prove a three-term
association difference in the tested domain; the small magnitude does not by
itself establish an audible defect. Replacing traversal with slot/key order
would change an established arithmetic behavior without a declared tolerance.

The mutation case observes original insert, existing-ID reconfigure, erase,
reinsert, pause, drain, reset and recreate. Existing-ID reconfigure retains order.
Erasure preserves the observed surviving sequence. In both recorded libraries,
reinserted voice 20 appears first in this three-key case. Pause stops consumption
but retains the voice in gain acquisition. `reset` clears records and retains
the current table's bucket allocation in these implementations.

The final case inserts 32 voices through the real configure API, with a separate
observation after each insertion. Automatic bucket growth is observed as
`13,29,59` for GCC and `5,11,23,47` for bundled LLVM. It then renders, erases and
reinserts one record. A bridge cannot assume that the two libraries have the
same bucket/traversal policy, nor infer traversal from raw-ID sorting. Thirty-two
is a synthetic test extent, not a measured maximum voice count in the game.

## Fixture layout and replay input

Schema 2 separates `inputs` from `records`. `inputs[]` contains named cases and
ordered action objects: reset, supplied gain bits, bounded repeated PCM16 queue,
configure with explicit raw IDs/rate/volume/playing state, release, drain and
render/observe. `input_transcript()` is the sole action authority;
`action_program()` emits the original C++ API calls from it. There is no decoder,
game asset or native expected-output calculation in this transport.

Each matching record's `declared_raw_order` is sampled **before** its render.
The post-render `gain_read_order`, PCM float bits, queue counts/source-byte
watermarks, voice phase/debt and frame counters are observations. An independent
native comparison can map that observed pre-render raw-ID sequence to its current
opaque voice handles, declare the order, replay the requested render, and compare
all post-render state. It must not derive PCM expectations from the native core.
Zero-frame observations still exercise source gain acquisition, but consume no
PCM. The input-to-observation sequence is checked before a fixture is accepted.

| Compiler | Driver SHA-256 | Fixture SHA-256 / bytes |
| --- | --- | --- |
| GCC | `51911fb398529fa19769da935279c1a8a56f1c3508b2df295624aaa3dae34aa5` | `86aef42be64adbed4b6fcd43045348f19691a0de8b1323b13858f08c5494ee10` / 340,874 |
| LLVM/MinGW | `f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3` | `361d4d35971e692ee4b5e62fff0edcce4f3d985f61b627f4b295a15394440c4d` / 340,855 |

Receipts and fixtures stay under `build-native-sjuni/pcm-order-oracle/{gcc,llvm}`.
All six test methods pass, rebuilding the unchanged-source corpus with both
available compilers under a separate ignored tests directory. They check source
identity, the measured association counterexample, complete traversal/gain order,
mutation/pause/reset behavior, rehash coverage and rejection of mismatched input
or malformed evidence.

```text
python tools/native_reconstruction/pcm_order_oracle.py --cxx C:/msys64/mingw64/bin/g++.exe --output build-native-sjuni/pcm-order-oracle/gcc
python -m unittest discover -s tools/native_reconstruction -p test_pcm_order_oracle.py -v
```

## Native API and integration requirements

An explicit native order should be a bounded complete permutation of the current
opaque voice handles, including paused/disabled records. Validate owner identity,
generation, uniqueness and completeness before replacing an existing order.
Foreign, stale, duplicate or missing handles must refuse before output/clock/
queue changes. Voice creation/release/reset and cut-stop invalidate the prior
declaration; callers must republish a complete order before a wider mix advances.
Existing-record reconfiguration does not itself change legacy map traversal.
Keep the default implicit-order admission conservative until a complete explicit
order is available. No implementation or native comparison is claimed here.

The host facade needs one synchronized transaction around source-map metadata,
native handles, gain capture, clock advancement and order publication. In
particular, source `configure` at lines 234–236 calls `tickLocked()` **before**
`voices[rawID]` inserts a new record. A rehash can change surviving order during
that insertion. The preceding headless interval belongs to the **old** traversal;
the new order applies after the insertion. Publishing the new map order before
the clocked configure can therefore change already-due PCM.

Calling `advance_headless(now)` and then a clocked configure at the same timestamp
is not a general workaround: each call can advance another capped 250 ms when
catch-up remains. Possible designs include a single before/after order transaction
or staging an inert native record while retaining old contributing order for the
one permitted clock advancement, followed by atomic post-insertion publication.
These are integration requirements/design candidates, not verified facade code.

Likewise, source `consumed(rawID)` at line 273 advances headless time before a
missing raw-channel lookup returns zero. A typed invalid-handle API that refuses
before effects has a different admission contract. The facade must preserve that
single advancement for unknown raw queries or explicitly exclude them; a blind
second tick on known queries can also double catch-up. Gain values must be
captured at the original boundary without invoking guest callbacks on a device
thread or changing bank/master ordering.

Raw RNA/SJRMT/SJX incarnation association, shared/aliased channel exclusion,
bounded allocation/error translation, stop/device callback fences and all callers
remain open. Whole-session selection must precede native queue publication;
switching into unrelated legacy queues after a rejected native operation cannot
recover already-published ownership. No playback, performance, speaker waveform,
hardware parity or complete-media migration follows from this source corpus.
