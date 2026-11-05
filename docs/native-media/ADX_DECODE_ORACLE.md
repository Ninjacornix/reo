# Original-word keyed mono ADX decode oracle

Status: bounded offline instruction execution and independently checked scalar
instruction semantics, 2026-11-05. No game, audio device, compressed asset or live
process was used. No production/runtime/dependency source was changed.

The complete original File #1 US `main:001276D8` kernel now produces PCM in an
offline oracle: **104 cases, 97,057 interpreted steps, 4,032 PCM samples written,
all 119 instruction addresses reached**. This is independent evidence for a future
native mono implementation. A separately written
[native block kernel](../../game/native/adx_block/README.md) subsequently matched
all 104 fixtures with GCC and LLVM without changing its independently frozen
algorithm. That comparison does not establish live replacement parity,
performance benefit, stereo/COP1 parity or a complete media player.

This closes the positive-mono instruction gap identified in
[BOUNDARY_INVENTORY.md](BOUNDARY_INVENTORY.md). Its original SJ/ADXB/ADXT/RNA
ownership, stop and timing gates still apply. Existing authoritative mapping:
[keyed CPU block decoders](../SYMBOLS_ADX_KEYED_CPU_BLOCK_DECODERS.md).

## Instruction extension and independent checks

[ee_mac_oracle.py](../../tools/native_reconstruction/ee_mac_oracle.py) composes a
small scalar extension over the unchanged `sjuni_oracle.Machine.instruction`.
It supports `MULT/MULTU`, `MULT1/MULTU1`, `MADD/MADDU`, `MADD1/MADDU1` and
move-to/from both HI/LO banks. Other MMI encodings remain unsupported. It models
architectural results, not multiplication latency or pipeline cycles; the EE
interlock is not a game/device scheduler in this harness.

The primary [Sony EE Core Instruction Set Manual, version 6.0](https://studylib.net/doc/28989088/ee-insns)
(April 2002), pages 142–145 and 154–157, specifies canonical sign-extended word
sources, 32-bit products accumulated as 64-bit bit patterns, independently
sign-extended result halves, optional destination and the separate pipeline-1
bank. The oracle rejects noncanonical source words before mutation. MADD1's
description contains an inconsistent HI0/LO0 phrase; its operation diagram uses
the upper bank, agreeing with the local implementation. No inference about
undefined operands or hardware cycle timing is admitted.

[test_ee_mac_oracle.py](../../tools/native_reconstruction/test_ee_mac_oracle.py)
contains independently calculated product-half and accumulator expectations:
negative products, signed extremes, low-half sign extension, high-half sign
extension, carry and full 64-bit wrap, optional `rd=0`, destination/source alias,
unsigned interpretation with sign-extended result halves, bank isolation,
arbitrary lower64 bank moves and noncanonical/reserved-encoding rejection.
MADD reconstructs its accumulator from each half's **low 32 bits**, not by treating
the sign-extended LO as a full low64 addend. Reads/writes to bank1 cannot affect
bank0. The eight test methods pass.

One of those tests additionally extracts the exact eight local recompiler MAC
emission templates, for both explicit and omitted `rd`, and the exact local
`Ps2HiLoToU64` / `Ps2SignExt32ToU64` helpers. It compiles a small lower64 context
harness and compares **192 executions** with the oracle. This checks consistency
with the recompiler separately from the manually calculated expectations. It
does not link the runtime, run a game function or establish SIMD upper-lane parity.
GCC C++20 `-O1 -Wall -Wextra -Wpedantic -Werror` passes. An unavailable GCC causes
this optional compilation check to be explicitly skipped, not reported as passed.

The source identity check pins:

| Inspected local source | SHA-256 |
| --- | --- |
| [code_generator.cpp](../../third_party/PS2Recomp/ps2xRecomp/src/lib/code_generator.cpp:1523) | `cf90c94d772b028bc71ebe965a6c3ad29cc9e89f6b22ac481c87e88d868c6f55` |
| [ps2_runtime_macros.h](../../third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime_macros.h:50) | `763baab6071c4a10c418a2f9f968e92e4da2e62a1e5ace642593a38d4c734287` |

Both files match the independently reconstructed public c46d1c7d + 0001..0120
tree under `build-native-sjuni/dependency-workers-v1`. Other active audio files
do differ, as recorded in the inventory; matching these two ISA files does not
certify an entire dependency build. The generator/template checker refuses a
changed reference hash. Its ignored receipt is
`build-native-sjuni/ee-mac-emission-check/receipt.json`.

Owned kernel comments at `12777C` and `1277B8` emit signed `MULT` with explicit
destination and `MULT1` with explicit destination respectively, matching the
extension. The complete mono body actually reaches only signed `MULT/MULT1`;
MADD and bank-move microtests support the extension but are **not** claimed as
kernel execution coverage. Later source in the same generated C++ file belongs
to other functions and is excluded by the owned entry/end boundary.

## Complete original-word execution boundary

[adx_decode_oracle.py](../../tools/native_reconstruction/adx_decode_oracle.py)
fetches every executed instruction from the owned ELF, using the unchanged
integer engine plus the tested MAC extension. No native ADX algorithm or
`AdxDecoder` implementation is imported. There are no substituted function calls:
the complete mono kernel has none. Read access to its static signed-nibble table
is explicitly limited to that owned 64-byte region. Writes there are rejected.

| Owned input | Identity |
| --- | --- |
| File #1 US ELF | `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46` |
| Kernel `1276D8..1278B4`, end exclusive, 476 bytes | `f68258d902ba372da0e477288c3a3b98a396a07b3c43bb28e55fb5805348b115` |
| Table `239BE8..239C28`, end exclusive | `67ec51eb0fd90d668661957e826ec5f7834c84c2e7a586f9cf185e0ec7d4808f` |
| Unchanged `sjuni_oracle.py` | `9d71114ffb0d8b2826012517c8d381d5ba2cdb5dd602c1f48e12450d99697d95` |

The ELF loader rejects content with another hash. Reconciliation against the
generated source comments verifies **119 matching words, zero omitted words,
zero conflicts** for the complete owner. Neither instruction bytes nor copied
instruction arrays are distributed in the new tools/fixtures.

All inputs are authored synthetic bytes and explicit state. The admitted test
domain has disjoint, aligned, ordinary encoded/output/history/key/stack regions;
requested signed32 count is at most 16; finite encoded storage is at most 288
bytes and PCM capacity at most 512 samples. Positive-count cases include marker
headers with only their two header bytes mapped, so payload reads after a marker
would fail. Nonpositive-count cases map no encoded storage. Every MAC bank is
initialized and recorded, with an additional nonzero-bank case; none is assumed
to hold an earlier zero/unkeyed/COP1 result.

Unknown instructions, external transfers, noncanonical MAC operands, unmapped
or straddling access, writes outside admitted destinations, and finite step-limit
exhaustion abort. Output red zones and encoded bytes remain read-only. A deliberately
undersized synthetic buffer is an oracle error, not an original status code or
a claim that the original kernel rolls back earlier writes. No nonscalar operation
was required or emulated by a fabricated result.

## Cases and observed effects

The 104 fixtures include all 256 high/low nibble pairs, each signed nibble in both
positions, header/scale boundaries with five initial key values, extreme signed
history/coefficient pairs, signed multiplier/addend extremes, up to 16 blocks,
markers before and after completed blocks, zero/negative/minimum-signed counts,
and explicitly nonzero initial MAC banks.

Nine [decode tests](../../tools/native_reconstruction/test_adx_decode_oracle.py)
pass. Simple zero-predictor expectations independently check nibble order,
sign extension, scale `+1` and both saturation bounds. Other tests check actual
memory effects, marker path, immutable input/red zones, ABI restoration, bounded
rejection and deterministic complete-body fixture generation.

Observed original distinctions that the native implementation must retain:

* A successful ordinary block emits 32 little-endian PCM16 samples. The full
  fixture contains every output sample and exact halfword-store offset/value,
  plus a PCM hash; counts are not inferred from a host decoder's result.
* A marker at the first header returns zero without key, PCM or external-history
  writes. A marker after earlier blocks retains their PCM and key updates but
  skips external history publication. History cannot be committed per block if
  that would alter this early exit.
* Count zero/negative returns that original signed count. It still reads both
  history halfwords and the stack addend and rewrites unchanged history, while
  making no encoded, key or PCM access.
* Normal return restores the original saved registers and stack. Internal cursor,
  processed index and final MAC registers are recorded for investigation, but
  are explicitly outside the native public return contract.

This is bit-level evidence for the admitted scalar domain, not a proof over all
parameter combinations. In particular aliasing buffers, arbitrary original
addresses, source/output wrap, concurrency/reentry, stereo kernels, float kernels,
loop restoration, source refill, SJ publication, callbacks, device time and stream
stop/close remain outside it.

## Reproduction and native consumer interface

```text
python -m unittest discover -s tools/native_reconstruction -p test_ee_mac_oracle.py -v
python tools/native_reconstruction/adx_decode_oracle.py
python -m unittest discover -s tools/native_reconstruction -p test_adx_decode_oracle.py -v
```

Default output: `build-native-sjuni/adx-decode-fixtures.json`, schema 1,
1,366,429 bytes, SHA-256
`11785ce1d02f0355e54c38df58216911ca33d1ca8fbeaa6a2528c539a27eb6bb`.
The receipt pins the tool hashes, exact source/table identity and scope. Repeating
generation produces the same document for unchanged sources and owned ELF.

For each `cases[]` record, initialize the native core from `input`:
`encoded_hex`, `requested_i32`, `history_i16`, `coefficients_i16`, `key_u16`,
`multiplier_i16`, `addend_i16` and `output_capacity_samples`. Initialize caller
output bytes to `A5`. Compare `expected.return_i32`, all `state.pcm_i16`,
`state.history_i16`, `state.key_u16`, output guard and input hashes; use
`pcm_stores` and per-region read/write summaries for stricter selective-write
checks. `observations_not_abi` must not be promoted to native API obligations.

No native implementation was used to generate these expected values. A future
comparison must consume this fixture rather than derive expectations from the
candidate. Admission still belongs outside an original synchronous owner: do not
redirect unsupported/aliased inputs after partial publication, replace the
original phase/result owner, or claim a native whole-player transition from a
successful kernel comparison.
