# ADX predictor service: original-word dispatch/publication evidence

Status: bounded offline contract evidence, 2026-11-05. This work executed original
instructions from the owned File #1 executable in the unchanged integer oracle.
It did not run the game, build a candidate, open an audio device, decode ADX,
modify a shared engine, or implement a native service adapter.

[adx_service_oracle.py](../../tools/native_reconstruction/adx_service_oracle.py)
executes the complete `135078` service and the real `135068` odd-result helper.
The external mono/stereo decoder calls are explicitly scripted hooks. **15 test
methods pass; 74 cases execute 2,558 original instructions and 54 codec hooks.**
The corpus reaches 65 of 66 admitted body words. Only the alignment NOP at
`13516C` is unreachable through these function entries.

This extends the [predictor control inventory](../SYMBOLS_ADX_PREDICTOR_CONTEXT_AND_WORK_DISPATCH.md)
and [phase/window fixtures](BOUNDARY_INVENTORY.md). It does not replace the
independent [mono](ADX_DECODE_ORACLE.md) and [stereo/downmix](ADX_STEREO_ORACLE.md)
arithmetic oracles: no native decoder is imported to generate these expectations.

## Owned code and instruction boundary

File #1 US `game_data/SLUS_207.65` SHA-256:
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
The existing ELF loader validates this identity before supplying any words.

| Body | Exclusive end | Words | SHA-256 |
| --- | --- | ---: | --- |
| Odd-result helper `135068` | `135078` | 4 | `4344464fd060cf220210248edccd1c24b0fc67868d2d02d621cdc1f375690e14` |
| Predictor service `135078` | `135170` | 62 | `a6ac3b23bfac0c9862d0facae8e02be99f08a69e6e20cb2dda05a10ffd3813bd` |

The service interval includes padding at `13516C`; its returning delay slot is
`135168`. The original helper's returning delay slot `135074` stores one at
`21B7B0`. That helper is **not** a no-op or an emulated diagnostic callback.
Its flag's consumer purpose remains outside this investigation.

All code fetches use owned ELF bytes. The unchanged `sjuni_oracle.py` lower64
integer engine implements the reached loads/stores, word sign extension,
branches, branch-likely annulment and delay slots. No FPU, VU, MAC, division,
decoder, runtime-thread or device extension is needed here. An unknown fetch,
unmapped/straddling access, unaligned ordinary access or instruction-step cap
fails explicitly. Each fixture machine admits one bounded service invocation.

The generated-source word audit reads the private V3 generated reference files,
compares every comment word to the owned ELF, and refuses conflicts or missing
nonzero words. It finds **64 matching comments and two omitted zero words**:
`13514C` is an executed JAL delay NOP; `13516C` is padding. Thus the two omissions
are not omitted service effects. No generated C++ function is executed by this
oracle.

## Measured control contract

The context is a synthetic, aligned 60-byte record. Addresses below are original
field coordinates for documenting this temporary boundary, not a proposed
native object representation.

| Input condition | Original instructions observed |
| --- | --- |
| Phase word `+0C == 1` | Store phase 2 before entering the selected decoder. |
| Phase word `+0C == 2` | Enter the selected decoder without a preliminary phase store. |
| Any other tested phase | Do not call a decoder or modify context/flag/payload. The ordinary stack prologue/epilogue still executes. |
| Mode word `+14 == 1` | Call `1276D8`, the mono lower kernel. |
| Any other tested mode | Call `127FC8`, the existing stereo selector; mode zero is not a no-op in this service. |
| Decoder returned | Store its raw result word at context `+10`, then store phase 3. No decoder-result sign/error admission is applied here. |
| Stereo return has signed remainder `+1` when divided by two | Execute real `135068`, storing one at `21B7B0`. |
| Mono odd return, stereo negative odd return, or stereo even return | Do not call the flag helper. Preserve the old global flag, including an already-set one. |

The signed odd check is the literal original sign-bias/shift/subtract sequence,
not Python's `% 2` result for negative numbers. The tests include `INT_MIN`,
`INT_MIN+1`, `-3..3`, `INT_MAX-1` and `INT_MAX`. For example, stereo `-1` does not
set the flag, while stereo `+1` does. Both still publish phase 3 and the returned
word. The dispatcher is treated as **void**: its final raw `v0` is retained only
under an observation field and must not become a native success/error return.

The service neither checks the context active word nor owns its incarnation.
The separate `135170` pool scan supplies active-record selection and is not
executed here. There is no claim that arbitrary modes/phases are admitted by a
future native adapter; their original behavior is recorded so rejection can
happen before any replacement effects.

## Exact argument and stack evidence

The hooks observe arguments only after the original JAL delay slot executes.
Input/count/output pointer words are loaded with original word sign extension;
coefficient, multiplier and addend halfwords are signed. The synthetic count
corpus includes negative/zero/odd/large words without asking a real decoder to
access those spans.

| ABI coordinate | Mono `1276D8` | Stereo selector `127FC8` |
| --- | --- | --- |
| `a0` | Encoded input `context+18` | Encoded input `context+18` |
| `a1` | Requested word `context+1C` | Requested word `context+1C` |
| `a2` | Left output `context+20` | Left output `context+20` |
| `a3` | Address of history `context+28` | Address of left history `context+28` |
| `t0` | Signed coefficient at `+30` | Right output `context+24` |
| `t1` | Signed coefficient at `+32` | Address of right history `context+2C` |
| `t2` | Address of key `context+34` | Signed coefficient at `+30` |
| `t3` | Signed multiplier at `+36` | Signed coefficient at `+32` |
| Caller stack `+00` | Signed addend word from `+38` | Key address `context+34` |
| Caller stack `+08` | Untouched | Signed multiplier word from `+36` |
| Caller stack `+10` | Untouched | Signed addend word from `+38` |
| Original return PC | `1350E8` | `135128` |

The service allocates **64 stack bytes**. Incoming `s0`, `s1` and `ra` lower64
values are saved at frame offsets `20`, `28` and `30`; the other frame bytes
remain untouched except the mode-specific 32-bit argument slots above. The
tests compare the complete final frame, untouched holes, a lower guard and the
original caller-stack guard. Saved-register, return-address and SP restoration
are checked even when a scripted codec clobbers caller-saved registers.

Those checks establish this service's frame under the stated synchronous hook
ABI. They do not supply a lower kernel's stack effects or full volatile/MAC
register equivalence. The codec-specific ABI fixture remains the source for
those adapters' selective-write validation.

## Scripted effects and lifetime implications

Every memory write carries an origin: `original`, `scripted_codec`, or
`scripted_reentry_effect`. Optional codec effects write fixed synthetic PCM,
history and key values; they are neither a decoder implementation nor a claim
that the scripted returned count corresponds to those bytes. The original
service itself writes only phase/completed fields and, on the positive-odd
stereo path, the global flag. It never copies PCM.

The hook can apply separately identified scalar effects corresponding to
cancel, release, busy request or acknowledgement before returning. These are
**explicit scripted mutations**, not execution of those entire original callees,
not actual callback reentry, and not a race/scheduler experiment:

- A scripted cancel changes phase to zero and clears the eight history bytes.
  The subsequently executed original service still stores the kernel result and
  phase 3. The cleared history remains cleared; an independently changed key is
  retained.
- A scripted whole-record release clears all 60 bytes. The original service
  still publishes completed and phase 3 through its cached context address,
  leaving the synthetic active word zero.
- A busy request or acknowledgement effect leaves processing phase 2 unchanged;
  the service then publishes ready normally.

These observations show that the service has no post-decoder phase/incarnation
check. They do **not** establish whether real locks, task serialization or caller
ordering permit such mutations during an actual codec call. A native owner must
settle that scheduling boundary before an asynchronous commit; cancellation is
not proven to join work, and resetting a record cannot be treated as a fence.

## Corpus and reproduction

```text
python -m unittest discover -s tools/native_reconstruction -p test_adx_service_oracle.py -v
python tools/native_reconstruction/adx_service_oracle.py --audit-generated
```

The default audited fixture is
`build-native-sjuni/adx-service-fixtures.json`, **739,681 bytes**, SHA-256
`2ece8cd061280fca02b5cf648f9ca70fd8073e8d6118b451a1130ffd2fe09954`.
Generation is deterministic for the same tool/ELF/reference bytes. Its embedded
tool and engine digests qualify reproduction; `--audit-generated` also adds the
source-word reconciliation to the JSON. Running without that switch omits the
audit section and therefore produces a different whole-document hash.

The 74 cases comprise 28 phase/mode combinations, 22 signed-result cases,
14 requested-count cases and ten explicit synthetic payload/reentry-effect
cases. Each records initial/final context, full frame and guards, payload probes,
input identity, original word PCs, memory reads/writes and observed hook arguments.
The tests independently assert routing, arithmetic classification, selective
stores and ABI frames instead of importing a candidate native implementation.

For a future typed native service comparison, convert raw fields into explicit
buffer tokens/owned spans at an admitted boundary; compare phase/completed,
global flag action, hook route and parameters, and exact selective effects.
Codec refusal must be resolved before replacement publication or represented as
an explicit new native refusal that does not masquerade as an original service
return. Preserve the existing selector's choice; do not switch downmix modes as
an optimization. Real buffer leases, context generations, join/cancel, stream
publication, playback clocks, audible output and performance remain unresolved
by this bounded service corpus.
