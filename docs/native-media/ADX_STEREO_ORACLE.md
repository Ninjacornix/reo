# Original-word keyed ADX stereo/downmix oracle

Status: bounded offline original-instruction evidence, 2026-11-05. No game,
media asset, audio device, live process or runtime build was used. The only
production inputs read are the owned executable's instruction words and its
signed-nibble table. No existing interpreter, native core, runtime or dependency
source was changed.

[adx_stereo_oracle.py](../../tools/native_reconstruction/adx_stereo_oracle.py)
executes the complete original normal stereo, downmix and selector bodies. The
frozen corpus has **522 cases, 931,435 interpreted instructions, 36,096 PCM
halfword stores and 476 reached instruction addresses out of 479 body words**.
All **17 test methods pass**, including independent scalar division checks and
the exact local division emitter compiled with GCC and LLVM. These measurements
describe the harness, not game performance or a live replacement.

The three bodies and their original contracts were previously reviewed in
[keyed CPU block decoders](../SYMBOLS_ADX_KEYED_CPU_BLOCK_DECODERS.md).
The [media boundary inventory](BOUNDARY_INVENTORY.md) still governs compressed
and PCM borrow lifetimes, publication, scheduler ownership, cancellation and
runtime admission. This oracle does not close those integration requirements.

## Owned text and table identity

Owned File #1 US `game_data/SLUS_207.65` SHA-256:
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
The existing `Elf` loader rejects a different input hash. No instruction arrays
or recovered asset bytes are embedded in the authored helper.

| Complete body | Exclusive end | Words | Body SHA-256 |
| --- | --- | ---: | --- |
| `main:00127C80`, separate PCM planes | `00127FC8` | 210 | `4a4e6da9bbda1a2a0b83c2f7bb31e777aeeb912c751b0a8a0694ce16c366f9ff` |
| `main:001278B8`, downmix and duplicate | `00127C7C` | 241 | `fece7d5c5d7dc0148717351d200c67d845e0242f5e7b93c01cfc19db7c2687ab` |
| `main:00127FC8`, selector | `00128038` | 28 | `5aea6cbb34fbefae1bf0c40ffd7fceb604766e1fe011b46c9aaad5ed5dd8439e` |

The four-byte alignment NOP at `127C7C` is outside the downmix body. A hash
covering downmix through `127C80` therefore differs; no body instruction is
omitted. A test compares every body word against the existing generated source's
PC/word comments independently of interpreting it.

The 64-byte table at `239BE8` has SHA-256
`67ec51eb0fd90d668661957e826ec5f7834c84c2e7a586f9cf185e0ec7d4808f`.
All sixteen signed words are checked as
`0,1,2,3,4,5,6,7,-8,-7,-6,-5,-4,-3,-2,-1`.
The selector reads the original global word address `20C7A8`; the harness admits
that four-byte word as read-only synthetic state.

## Instruction model and the division gap

The harness composes the unchanged
[integer engine](../../tools/native_reconstruction/sjuni_oracle.py) and frozen
[EE MAC extension](../../tools/native_reconstruction/ee_mac_oracle.py).
The integer engine has no SPECIAL `DIV` implementation. The new stereo module
therefore adds one small `EeDivInstructions` layer; it does not replace or amend
either shared engine and imports no native decoder algorithm.

The primary [Sony EE Core Instruction Set Manual v6, DIV, printed page 51](https://docs.alexrp.com/mips/ee_insns.pdf)
defines signed word division with quotient in LO and remainder in HI, each
sign-extended to lower64. Inputs must be canonical sign-extended words. The
remainder has the dividend's sign; `INT_MIN/-1` gives `INT_MIN,0`. The manual
leaves a zero divisor's arithmetic result undefined. The local pinned emitter
chooses a zero result, but this oracle rejects zero **before any state change**.
Reserved rd/shift encodings and noncanonical inputs also fail before mutation.
No latency, interlock, pipeline scheduling or upper128-lane behavior is modeled.

The downmix body sets `t2=10` at `127A04` and never changes it in its sample loop.
Original `DIV` instructions at `127AD8` and `127BD8` therefore use divisor ten.
The preceding `BEQL` checks at `127AC8` and `127BC8` are false and annul the
`BREAK` delay slots at `127ACC` and `127BCC`. These two trap words are present in
the owned body but are not executed or replaced. Unknown instructions still
raise `UnknownInstruction`; they are never substituted with codec arithmetic.

[test_adx_stereo_oracle.py](../../tools/native_reconstruction/test_adx_stereo_oracle.py)
checks independently calculated positive/negative quotient and remainder,
negative fractional truncation, signed extremes, overflow, unchanged GPRs and
secondary MAC bank, and rejection without mutation. It additionally extracts
the exact `SPECIAL_DIV` emission template from the hash-pinned local generator,
compiles it with both GCC and LLVM using C++20 and warnings as errors, and
compares **170 nonzero-divisor vectors per compiler**. This is separate from
the hand-calculated tests and does not execute an original game function.

Pinned local ISA source SHA-256 values remain:

| File | SHA-256 |
| --- | --- |
| `third_party/PS2Recomp/ps2xRecomp/src/lib/code_generator.cpp` | `cf90c94d772b028bc71ebe965a6c3ad29cc9e89f6b22ac481c87e88d868c6f55` |
| `third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime_macros.h` | `763baab6071c4a10c418a2f9f968e92e4da2e62a1e5ace642593a38d4c734287` |

These identify the inspected local semantics, not the complete linked runtime.
The separate ignored emission receipt is
`build-native-sjuni/adx-stereo-div-checks/receipt.json`.

## Synthetic memory and actual ABI

The memory model admits only disjoint finite spans: at most sixteen encoded
blocks, two independently guarded PCM16 planes, four history halves, one key
halfword, the owned table, selector flag and a bounded stack. Sources, table and
selector flag cannot be written. Output, history and key guards are mapped for
post-call inspection but are never admitted as kernel-accessible memory.
An entire load/store must fit inside one admitted span. Short encoded input,
undersized output, bad alignment, unknown transfer and instruction-limit
exhaustion fail closed. There is no external function substitution in any body.

The actual entry arguments are `a0=input`, `a1=requested`, `a2=left PCM`,
`a3=left history`, `t0=right PCM`, `t1=right history`, `t2=coefficient1`,
`t3=coefficient2`; caller stack offsets `0,+8,+16` carry key pointer, multiplier
and addend. The coefficients and key-step values use their signed low16 bits.
Cases deliberately poison their unused high halves, proving both direct
kernels and selector normalize the halfword arguments. All four lower64 MAC
bank values are explicitly initialized, including nonzero sentinels.

Every case records the defined signed32 return, full PCM capacities including
unused sentinel tails, all history/key/flag values, input/table hashes and
guards. It also records the exact ordered PCM stores, per-region load/store
counts and ranges, reached PCs, per-PC counts, MAC/DIV counts, and restored SP,
RA and lower64 callee-saved GPR sentinels. Volatile registers and final MAC banks
are observations rather than extra ABI promises. Aliased buffers, wrapping
guest-address ranges, arbitrary upper128 lanes and unbounded counts are outside
this harness.

## Corpus and preserved edge behavior

There are 87 cases per entry/flag variant: direct normal, direct downmix,
selector with flag `0`, `1`, `80000000`, and `FFFFFFFF`.
Each variant covers all sixteen repeated signed nibbles, all 256 ordered
high/low nibble combinations in each channel, scale/key boundaries, signed
coefficient/history extremes, clipping in both directions, initial MAC state,
one through eight pairs, positive odd counts, nonpositive counts including
`INT_MIN`, markers on either channel after zero/one/two completed pairs,
halfword argument packing and an unused PCM tail.

The complete original instruction runs preserve the less obvious contracts:

- The return on ordinary completion is the original requested block count,
  including an odd count. Requested one processes no pair and still returns one.
- A left marker advances no key for that pair. A right marker advances the left
  block's key before stopping, without decoding that pair's left payload or
  storing PCM. Earlier PCM/key effects remain.
- A marker exit does not publish either channel's accumulated histories, even
  after earlier complete pairs. The four caller history halves remain their
  original values; key updates already performed remain visible.
- Downmix clamps each predicted channel first, truncates the signed result of
  `7*(left+right)/10` toward zero, clamps again and duplicates it to both planes.
  Its histories retain the individual channel samples. For clamped `32767` and
  `-32768`, output is zero while the individual histories retain those limits.
- Selector flag zero takes the separate-channel kernel; every tested nonzero
  flag takes downmix. The selector does not modify its global flag.

All 210 normal words are reached. Downmix reaches 239 of 241 words, excluding
only the two annulled zero-divisor traps. Selector reaches 27 of 28 words,
excluding the NOP at `128014` skipped by its unconditional tail jump. This is
finite instruction coverage, not a proof over every input value or alias layout.

## Reproduce and frozen evidence

From the checkout, with the owned ELF available:

```powershell
python -m unittest discover -s tools/native_reconstruction -p test_adx_stereo_oracle.py -v
python tools/native_reconstruction/adx_stereo_oracle.py
```

The division emission test uses the checkout's known GCC and bundled LLVM
locations explicitly; unavailable compilers fail the test rather than claiming
a pass. Only the emitted scalar microtest is compiled. The generators and
fixtures require Python for developer verification; no player runtime dependency
or integration is introduced.

Frozen independently before the native stereo comparator read the fixture:

| Artifact | SHA-256 |
| --- | --- |
| `tools/native_reconstruction/adx_stereo_oracle.py` | `f66047d0ee59114cdf80d5d1e1bb4833aa566b35c9a7dea7e9d24930ad428c17` |
| `tools/native_reconstruction/test_adx_stereo_oracle.py` | `ca383b6f26953e023bbcc578ae7c5d495b4ec5d36b6e8df2d4526d1801632380` |
| `build-native-sjuni/adx-stereo-fixtures.json` | `a02fc85b996feb650751407a5a2e5fc9cd8104fd1c5d9fe4278864cf4027f6b0` |
| unchanged `sjuni_oracle.py` | `9d71114ffb0d8b2826012517c8d381d5ba2cdb5dd602c1f48e12450d99697d95` |
| unchanged `ee_mac_oracle.py` | `0466ee2828bcc268deafbb9ed93d8e7096cd0b89fa0ed489af28cae0120128cd` |

The ignored JSON contains exact inputs/results, per-body hashes and coverage,
tool hashes and pinned local ISA references. It is reproducible from the three
authored files plus the existing engines and owned ELF. The native implementation
was written independently by another agent and its source/header hashes frozen
before this fixture was supplied; its comparison is reported separately. No
native source was read or imported to obtain these oracle results.

The subsequent independent
[native stereo comparison](../../game/native/adx_stereo/README.md) passed all
522 cases and 36,096 PCM halfword outputs with both GCC and LLVM without changing
the frozen native algorithm/header. Its receipts are
`build-native-sjuni/adx-stereo-compare/{gcc,llvm}/receipt.json`. That comparison
includes complete output capacities and ordered stores within each plane; the
oracle additionally records cross-plane store order, which native disjoint
vectors do not expose as an ABI. Neither result admits aliased buffers or
establishes a guest/runtime replacement.

## Separate adapter ABI review

A later adapter review adds **three ABI tests** to the test module (20 total
passing test methods). It preserves the frozen PCM generator and JSON hashes
above. The earlier test hash is the historical PCM-freeze identity, not the
expanded test module. A separate original-word export can be reproduced with:

```powershell
python tools/native_reconstruction/test_adx_stereo_oracle.py --export-abi build-native-sjuni/adx-stereo-abi-fixtures.json
```

This produces 522 original ABI cases with SHA-256
`2973e5606dfa1eefcc24c5007c55294cec770bb7910983a08293b7408a22e275`.
The expanded test/export module has SHA-256
`075b41e2c473d226c451bcc424af71601be9557c719f7036f144300678b082f2`.
The exporter hashes and refuses to overwrite the frozen PCM fixture. It captures
the actual original writes at their PCs, complete 112-byte dead frame, caller
argument bytes, final lower64 GPRs and observed final JR. It does not synthesize
the frame from the native implementation. The `original_abi_case` helper also
accepts any explicit nine uint64 saved-register values and an initial frame fill,
which the separate tests vary. Final `branch_pc` and cleared delay flag follow
the inspected generated JR protocol; hardware cycles and upper lanes remain
outside the interpreter.

For either direct kernel, let `F = incoming SP - 70h`. The original lower64 saves
occupy `F+20h,+28h,...,+60h`, in order `s0..s7,fp`. Both bodies restore them and
incoming SP; RA is not changed. The final eight bytes `F+68h..6Fh` are untouched.
The original local words are:

| Frame offset | Separate-channel body | Downmix body |
| --- | --- | --- |
| `00h` | requested count | requested count |
| `04h` | left history pointer | left history pointer |
| `08h` | right history pointer | right history pointer |
| `0Ch` | multiplier sign-extended from its caller-stack halfword | same |
| `10h` | addend sign-extended from its caller-stack halfword | same |
| `14h` | completed pairs, initialized zero; updated at `127F7C` | target pair count |
| `18h` | target pair count | untouched |
| `1Ch` | untouched | untouched |

Normal returns through `JR RA` at `127FC0`, whose delay slot `127FC4` restores
SP by `70h`; downmix uses `127C74` and `127C78`. The generated return sets
`pc = incoming RA`, `branch_pc` to the corresponding JR and `in_delay_slot=false`.
History publication order is previous left, newest left, previous right, newest
right (`127F84/8C/94/98`, or `127C38/40/48/4C`). The right-marker path's left key
store precedes any PCM for that pair. An ABI-preserving disjoint transaction can
publish those ordinary RAM bytes together only with no callbacks or suspension
inside commit; no equivalence for overlapping buffers or watched device memory
follows.

The existing caller `135078` builds these arguments at `1350F0..135124` and
calls the unchanged selector. At return `135128..135140`, it consumes v0 to store
the reported count and test its signed odd remainder; the odd case invokes
`135068`. Its object remains in restored s0, and the later epilogue restores
s1/SP/RA. The other volatile operands used after the call are assigned afresh.
This supports the stated ordinary ABI boundary for this caller; the reference
search does not prove every indirect caller or arbitrary context is equivalent.

The original generated kernels contain resumable preemption boundaries at
normal `127DD8/127D08` and downmix `127A18/127948`. A bounded synchronous native
call does not reproduce those intermediate scheduling points. Interior-PC
dispatch must retain the captured original, rather than restarting a canonical
entry. The original selector's stack argument normalization and flag access
remain original code when only the lower entries are intercepted.

Review of the new lower-entry adapter found its mode-specific frame words,
saved slots, return PC, JR `branch_pc`, key-on-right-marker rule and unchanged
history-on-marker behavior consistent with this evidence. This shares the mono
pilot's deliberately narrower ABI: volatile GPR/MAC results are not reconstructed,
and a guest-depth check proves ownership scope rather than authoritative context
identity. Mock full-context equality must therefore mean equality to the stated
selective ABI update, not equality to every original volatile observation.
Linked-runtime, scheduling and live-call admission require separate evidence.

The completed
[guarded adapter checks](../../recomp/overrides/native_adx_stereo/README.md)
now pass **33 driver commands with each of GCC and LLVM**, including actual
patched-header object compilation. The 166 positive direct-kernel cases use the
separate original final frame bytes, original addresses and saved-GPR inputs,
then compare all synthetic RAM and the selective context update. Additional
checks cover 232 refusals, 40 traced native calls, allocation refusal/reuse,
both entry bindings, body/table mutation, stop and four partial-publication
stages. Both final receipts match the reviewed source hashes; no stale source
entries or failed commands remain. The independently reviewed production
adapter SHA-256 is
`32b007c6a494d03eca05486af22c236675a4e2dea0ddd301eb48d4f7d7abc340`.
No blocking discrepancy was found within its stated disjoint synchronous ABI
domain. This review did not run or link the game.
