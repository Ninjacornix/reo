# Large keyed ADX block requests: original-word and adapter evidence

Status: bounded offline evidence, 2026-11-05. No game, audio device, media asset
or candidate build was executed for this work. The owned executable supplies
instruction words and its nibble table; all encoded bytes and predictor state
are synthetic.

A root-owned read-only pool observation reported stereo request counts 210 and
300, alongside count 2, in
`build-native-sjuni/playtests/adx-mono-pcm-v4/adx-predictor-snapshots.json`.
Those pool reads are **not atomic invocation-argument captures**, and they do not
prove which kernel call, source extent or lifetime was admitted. They motivate
coverage beyond the original 16-block native admission limit. Their values are
not used as expected PCM or imported into the offline fixture.

## Original execution and unchanged engines

[adx_large_block_oracle.py](../../tools/native_reconstruction/adx_large_block_oracle.py)
reuses the unchanged machines from the [mono](ADX_DECODE_ORACLE.md) and
[stereo/downmix](ADX_STEREO_ORACLE.md) oracles. Their original constructors and
`MAX_BLOCKS=16` globals remain intact. The new wrapper first constructs a valid
zero-count machine, before any original instruction executes, then remaps only
its own synthetic input/output spans and changes its requested-count register
and fixture metadata. Original code, integer/MAC/DIV semantics, run loop,
memory-access observation and output snapshot methods are reused unchanged.

The wrapper separately admits count **1..513**, at most 9,234 synthetic encoded
bytes, and finite disjoint output spans. It seeds canonical signed-halfword GPR
arguments and full sign-extended caller argument words matching `135078`'s
`LH`/`SW` publication. This avoids confusing the small stereo corpus's optional
low-halfword packing experiment with the guarded adapter's canonical admission.

Every original instruction in every block loop executes. There are no loop
teleports, native decoder calls, cached PCM expectations or source instruction
substitutions. Each call has a finite two-million-instruction cap. The fixture
records per-PC execution counts whose sum equals the reported instruction count.

| Owned range | SHA-256 |
| --- | --- |
| File #1 US ELF | `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46` |
| Mono `1276D8..<1278B4` | `f68258d902ba372da0e477288c3a3b98a396a07b3c43bb28e55fb5805348b115` |
| Normal stereo `127C80..<127FC8` | `4a4e6da9bbda1a2a0b83c2f7bb31e777aeeb912c751b0a8a0694ce16c366f9ff` |
| Downmix `1278B8..<127C7C` | `fece7d5c5d7dc0148717351d200c67d845e0242f5e7b93c01cfc19db7c2687ab` |
| Signed nibble table `239BE8`, 64 bytes | `67ec51eb0fd90d668661957e826ec5f7834c84c2e7a586f9cf185e0ec7d4808f` |

The existing four engine/module files are hashed before and after generation;
generation refuses any source or global-bound change. Their identities remain:

| Reused file | SHA-256 |
| --- | --- |
| `sjuni_oracle.py` | `9d71114ffb0d8b2826012517c8d381d5ba2cdb5dd602c1f48e12450d99697d95` |
| `ee_mac_oracle.py` | `0466ee2828bcc268deafbb9ed93d8e7096cd0b89fa0ed489af28cae0120128cd` |
| `adx_decode_oracle.py` | `8c8bafce4e231c5a91fa1736956c4a0e1cedf555c2c304b323184386101f122f` |
| `adx_stereo_oracle.py` | `f66047d0ee59114cdf80d5d1e1bb4833aa566b35c9a7dea7e9d24930ad428c17` |

## Frozen corpus

The **21 cases execute 5,625,317 original instructions and 220,896 PCM halfword
stores**. They reach all 119 mono words, all 210 normal stereo words and 239
downmix words. The two downmix zero-divisor BREAK delay slots remain annulled
because the original divisor is ten, as established by the small oracle.

- Mono, normal stereo and downmix each run full requests 17, 210, 300, 511, 512
  and 513. Odd stereo requests return the original requested word while decoding
  only whole pairs; the unpaired encoded block remains unread.
- A mono marker follows 210 decoded blocks in a request for 512.
- A right-channel marker follows 150 decoded stereo pairs in an odd request for
  511. The left header's key advance occurs before the right marker, without
  decoding the current pair's PCM.
- A downmix left marker follows 105 complete pairs in a request for 512.

Parameters include extreme signed coefficients/history/key steps, longer key
recurrences, normal predictor coefficients and nonzero initial MAC banks. Early
markers retain prior PCM/key effects without publishing either external history
pair. Downmix duplicates its clipped mixed PCM while retaining unmixed predictor
history, matching the separate normal path's histories/key for the same input.

Each case carries the original PCM/history/key result and full original ABI
evidence: initial and final 80-byte mono or 112-byte stereo frame, caller's
32 argument/guard bytes, lower stack guard, initial lower64 GPR values, final
saved-state checks, actual final PC and the original JR branch PC derived from
the executed owned word. Final volatile GPR/MAC values remain observations;
they are not replacement ABI obligations.

`proposed_adapter_count_admitted` is a **count-only annotation**. It is false for
all three count-513 cases. It neither overrides other identity/range/lifetime
guards nor claims those larger calls should be admitted natively.

Frozen artifact:
`build-native-sjuni/adx-large-block-fixtures.json`, **34,839,826 bytes**, SHA-256
`b49e2df608718db12b325903c46b2c1c132fcdf67c4472d0b10d06a90a84d514`.
The expected artifact was frozen before adapter comparison; no native decoder
arithmetic changed to match it.

```text
python tools/native_reconstruction/adx_large_block_oracle.py
python -m unittest discover -s tools/native_reconstruction -p test_adx_large_block_oracle.py -v
```

Eight test methods pass. Tests use the generated frozen artifact, so generation
precedes test discovery on a fresh checkout.

## Guarded native adapter expansion

The production changes are restricted to the two existing adapter `.cpp` files:
raise the positive count cap from 16 to **512** and update the installation log's
declared count range. No `.h`/`.hpp`, decoder arithmetic, selector/global,
bootstrap, CMake, preparer or default-activation change is part of this cut.
The native decoders remain the independently frozen implementations.

| Admitted maximum | Mono | Stereo/downmix |
| --- | ---: | ---: |
| Requested blocks | 512 | 512, meaning 256 whole pairs |
| Encoded span | 9,216 bytes | 9,216 bytes |
| Output samples | 16,384 | 8,192 per channel |
| Output storage | 32,768 bytes | Two 16,384-byte planes |
| External history | 4 bytes | Two 4-byte pairs |
| Mutable key | 2 bytes | 2 bytes |
| Original dead stack frame | 80 bytes | 112 bytes |

The [new large runner](../../recomp/overrides/native_adx_block/tests/run_large_checks.py)
transports the frozen expected bytes to the actual adapter/native core. It
does not implement PCM arithmetic or synthesize an expected original frame.
Its host harness seeds exact original GPRs/frame/arguments, compares the complete
32 MiB synthetic RAM with original expected changed segments and unchanged
sentinels, and compares the selective full mock context. Both GCC and bundled
LLVM/MinGW pass:

- **18 native large cases**: six mono and twelve stereo/downmix, including all
  long-prefix marker cases.
- **Three count-513 original-once refusals**, verifying unchanged RAM/context
  upon original entry. The original is a controlled sentinel in this refusal
  test; the separate corpus supplies the real original count-513 execution.
- **20 expanded-range/alias refusals**, eight mono and twelve stereo/downmix,
  checking near-end input/output extents and overlaps that become relevant at
  the larger count. Each reaches the original once before replacement effects.

Receipts are `build-native-sjuni/adx-large-adapter-checks/{gcc,llvm}/receipt.json`.
The existing host drivers also pass with both compilers, including all small
original fixtures, allocation/failure reuse, original-once refusal, identity,
binding, stop/partial-publication and numeric/default-off checks, plus actual
patched-runtime-header object compilation. Those receipts are under
`adx-block-adapter-checks/{gcc,llvm}-large-bound` and
`adx-stereo-adapter-checks/{gcc,llvm}-large-bound`.

The larger region is still synchronous: no intermediate guest preemption,
arbitrary manual-call lifetime, device timing or concurrent cancellation
equivalence is established. All identity, authentic guest-scope, 32 MiB extent,
alignment, pairwise alias, protected text/table, stack and stop guards remain.
No actual native activity, audible quality or performance improvement follows
from these host checks. A matching rebuilt private candidate and controlled
game evidence are still required.
