# Complete bank-session reference from unchanged runtime source

Status: independent reference inputs and expected observations frozen,
2026-11-05. The reference is the complete unchanged124 **host-runtime**
`ReoSoundBanks.cpp/.h`, not a PS2 instruction oracle or proof of hardware DSP
accuracy. No native-bank candidate was inspected, imported or linked. No game,
real asset, device, RPC execution or live process memory was used.

[bank_session_oracle.py](../../tools/native_reconstruction/bank_session_oracle.py)
constructs only authored synthetic assets/actions and compiles an observer
around the normal source include. All parser, VAG decode/cache, sequence,
envelope, request selection, commands, mixing and source globals remain the
unchanged implementation. The only host hook is a pure, nonreentrant gain
provider. Python computes no expected PCM, envelope, sequence or state-machine
results. [Nine checks](../../tools/native_reconstruction/test_bank_session_oracle.py)
pass against the frozen source-produced observations.

## Source identity and independent freeze

The source comes from fresh full124 reconstruction
`build-native-sjuni/dependency-pcm-boot-reapply-v3`, based on PS2Recomp
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f`. This bank source is unchanged from
the qualified prior cohort. The dirty active dependency is not substituted.

| Reference input | SHA-256 |
| --- | --- |
| full124 reconstruction receipt | `944b72d4cc977ac01d8e7a4459c601f0a331b06c8adbb5048bec45a2963f91cb` |
| complete `ReoSoundBanks.cpp` | `e164ba72cc002311d4811d803be2e2df9a6228d5abcaa0c4fa419a31ee09b818` |
| complete `ReoSoundBanks.h` | `28963da544d533ae8f04765558ff0665c4dc87c38cfba767a4828705c07616c8` |

Asset/action JSON and its binary transport were frozen before generating
expected data. The separately implemented bank candidate was frozen by the
coordinator before expected-data release; it was not viewed to choose these
results. The final reference cohort is
`build-native-sjuni/bank-session-oracle-v2`. The writer refuses changed frozen
inputs or changed existing expected observations; new reviewed inputs require
a new cohort. A comparator mismatch is not a reason to rewrite expected data.

| Frozen artifact | SHA-256 |
| --- | --- |
| `input-manifest.json` | `1ad80c1cea2c678e0ddeac251fd89b41cfc57c601dd3dd29735a6a3b52adb55b` |
| structured `input.json` | `9a8f9ebe2b650a0233c26edcc2eff13cbce625fb7e37a05ed46ce4990ac7bd8c` |
| binary `input.bin` | `94a2da79aa768d8bdd68279466bf7552f601b1899e0a0b25d928ac494f533862` |
| source-only observer `harness.cpp` | `f4951c6f8e3bff5686957ca38e3f5dd1ffc2cc107223029adcafa596f309d945` |
| GCC `0/expected.json` | `2b0e4010c7197216625fce46838835d58da4af98353bc11d6a6b1d2db2df7d06` |
| LLVM `1/expected.json` | `2b0e4010c7197216625fce46838835d58da4af98353bc11d6a6b1d2db2df7d06` |

## Authored assets and action scope

The finite corpus contains **15 synthetic banks, 18 scenarios and 252 actions**.
HD/BD/TQ bytes are generated from the reviewed source format, not copied from
captures or game data. Existing stock bank checks were consulted; they depend
on owned captures/imports, so their assets were not reused here.

- HD uses reversed `SCEI`/chunk signatures, explicit program/region/sample-set/
  sample/VAG records and small known offsets. Variants include invalid signature,
  invalid sequence count, missing sample record and unsupported velocity curve.
- BD consists of tiny authored three-block VAG clips with nibble patterns,
  filters 0..4, shift fallback, valid end/loop flags, loop start 0 or 28, invalid
  filter and missing-end cases. Actual source decoding supplies every expected
  sample and cache result. A changed-BD bank deliberately retains the same HD
  fingerprint, distinguishing content from that source fingerprint.
- TQ contains notes/groups/note-off, program/volume/expression/pan/pitch,
  one/two-byte waits, loop jump, all-notes/all-sound off, end/wait conditions,
  unsupported command and bounded self-loop. A valid terminal sequence emits
  **1025 events** in the source's 1024-command bound: 1023 AllNotesOff events,
  then AllSoundOff plus End. The source is not silently constrained to1024
  output events.
- A valid HD with 255 matching regions and 255 samples per set resolves
  **65025 sample layers**. Source session playback retains its 48-voice limit;
  the reference records 64977 capacity reports rather than truncating resolution
  or inventing an all-or-nothing refusal.
- Actions use actual `submitBank`, `submitPacket`, `mix`, `reset`, `pendingLoads`,
  `portState` and `seState` APIs, plus direct original `Bank`/`Sequence` probes.
  Wire-load commands include the real packed address/size layout and address
  masking over a small **synthetic** RAM byte vector. It is not a RAM dump or
  guest execution. Already-loaded conditional load, invalid range/port, truncated
  and unknown commands, terminator and valid-prefix effects are retained.

Scenarios cover unloaded/loaded ports, all 14 ports and 16 request slots,
priority/oldest selection, flagged replacement and exact cancellation selectors,
note release tails, immediate stop, unload, bank replacement, default/changed
request controls, port/global volume, pan/pitch, mono/mute and continuing time
while muted. Source `reset()` clears all banks, requests and voices. It is not
renamed into a retain-banks reset; PCM-only reset behavior belongs to its separate
owner/reference, not a fabricated bank-oracle operation.

An explicit frame 1/2/3/4 sequence observes Attack, Decay and Sustain, followed
by cancellation and Release/Off; the exponential variant exercises the other
rate mode. Split rendering and one 600-frame render produce identical PCM and
final state with fixed gains. Scheduler state is observed at the first frame
and around the 200-frame tick boundary at 48 kHz. These are functional arithmetic
observations, not elapsed-time measurements.

## Observation and transport contract

The input binary is a bounded little-endian `RBSO1` transport. It contains the
same named assets/cases/actions as `input.json`; no expected fields are embedded
in the input. Action kinds are reset, bank submit, packet, mix, gain mode,
original Bank/Sequence probe and public query. Mix is bounded to 1200 frames per
call. Source and expected data are separate files.

Each action records its actual return, full stereo **float32 bit patterns**,
ordered gain calls and source state:

| Observation | Captured meaning |
| --- | --- |
| Global state | `frameClock`, `requestAge`, muted/mono, exact unsupported-report counter and pending-load query. |
| Ports | All 14 loaded flags, stored HD fingerprints, volume, retained bank sequence count and public loaded/count queries. Unloaded-but-retained bank data is distinguished from global reset. |
| Requests/sequences | All 224 request records: cursor, wait, program offset, active/has-note; selectors, priority/cancel flags, requested and current controls, age, and public `seState`. Field order is declared in the expected JSON. |
| Voices | Ordered active/inactive records, port/slot/note/group/velocity, all Sample scalar fields, exact double position/step bits, cached bend and full envelope phase/value/countdown/ADSR words. Inactive records retained until the source cleanup boundary are not erased by the observer. |
| Clip ownership | Stable per-case IDs assigned by shared-owner identity, decoded PCM content hash, length, loop flag/start. IDs use weak references, not raw addresses, and do not keep PCM objects alive. Old voice clips after replacement are distinct from the new bank cache, even when HD fingerprints match. |
| Bank/sequence probes | Actual source load/decode validity, decoded PCM16 samples and loop metadata; successive original Sequence results, complete events and scalar state for scripted voices-active arguments. Session cases independently derive that argument through the unchanged full source. |

Sequence private fields are observed through a matching scalar object image:
`uint32 cursor`, `uint16 wait`, `uint8 programOffset`, `bool active,hasNote`.
The unchanged source type is standard-layout/trivially-copyable; size/alignment
are asserted, GCC asserts layout compatibility, and every observed active flag
is checked against the public accessor. Padding is never printed or compared.
This is a qualified observer for these Windows x64 compiler/header cohorts,
not a portable public serialization ABI and not a `private`-macro source edit.

For ordinary small resolutions every Sample record is printed. The 65025-layer
boundary records full count and an all-element scalar FNV hash plus the first 128
records, with `metadata_complete=false`. The hash is observation compression,
not a cryptographic proof of all individual metadata values. Full sample/voice
behavior and the 48-voice output still execute in the reference source.

For every valid non-null positive mix, the hook records **224 calls**, in actual
port 0..13/slot 0..15 traversal, before ticking/rendering. Arguments include the
request's sequence index and current fingerprint. Mode 0 returns 1; mode 1 returns
one of 0,.25,.5,.75,1 from a fixed pure argument function. Null/zero mix performs
no gain calls or state advance. This proves hook sampling/order for the corpus,
not actual host bus routing. Captured `seState` reflects scheduler activity,
so cancellation can return 0 while an accepted note still has a release tail.

Valid commands before a later invalid/unknown command retain their effects.
For example a false packet result can leave mute and port volume changed.
Diagnostics preserve the exact monotonically incremented counter; the source's
32-line stderr cap is not mistaken for the number of refused voices/commands.
Load/report stderr is retained in the receipt, separately from structured
behavioral observations.

## Reproduction and results

From the repository root, using the already qualified source tree/receipt:

```powershell
python tools/native_reconstruction/bank_session_oracle.py `
  --checkout build-native-sjuni/dependency-pcm-boot-reapply-v3 `
  --baseline-receipt build-native-sjuni/dependency-pcm-boot-reapply-v3-receipt.json `
  --output build-native-sjuni/bank-session-oracle-v2 --freeze-only

python tools/native_reconstruction/bank_session_oracle.py `
  --checkout build-native-sjuni/dependency-pcm-boot-reapply-v3 `
  --baseline-receipt build-native-sjuni/dependency-pcm-boot-reapply-v3-receipt.json `
  --output build-native-sjuni/bank-session-oracle-v2 `
  --compiler C:/msys64/mingw64/bin/g++.exe `
  --compiler C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe

python -m unittest discover -s tools/native_reconstruction -p test_bank_session_oracle.py -v
```

GCC 15.2.0 (MSYS2 Rev8) and bundled Clang 21.1.8 independently compile the complete
normal source include and produce **identical 5,588,049-byte expected files**:
**13,004 float32 output words and 12,768 gain-call observations** across the corpus.
The release arithmetic flags match the portable build: C++20, `-O2 -DNDEBUG
-msse4.1 -fms-extensions -fno-fast-math -ffp-contract=off
-fno-strict-aliasing -fwrapv`. Warnings are errors except the unchanged source's
existing misleading-indentation warning; its code is not patched to suppress it.
The receipt records exact commands/compiler versions, executable/source/input/
expected hashes and reference stdout/stderr. Input/source hashes are rechecked.

The final receipt is `build-native-sjuni/bank-session-oracle-v2/receipt.json`.
Its SHA-256 is
`6d62e4a31d663db997de0677c2db48e348e2a7a0347c7b440476b082f1ff5136`.
A later native comparator must verify the independently frozen candidate first,
then transport the same actions and map equivalent logical observations. It must
report mismatches and representation exclusions explicitly; it must not derive
expected DSP from the candidate or silently normalize source differences away.

## Limits

This preserves the selected existing host bank implementation; it does not
prove original HSYN/SPU accuracy, real-bank compatibility or audible quality.
There is no hardware sample clock, device scheduling, latency, CPU-profile or
performance result. Source `reportAudioPaths` is included unchanged but not
invoked, and its optional path logging is disabled. Allocation failure, thread
races/reentrant gain hooks, every malformed header/control value, numeric-clock
exhaustion and arbitrary bank sizes are outside this finite corpus. Direct
private-state retention observations can be stricter than the public API;
representation changes need an explicit comparison mapping, not pointer or
padding equality. No new native bank implementation or game integration is
claimed by the oracle alone.
