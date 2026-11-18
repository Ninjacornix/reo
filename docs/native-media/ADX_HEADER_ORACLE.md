# Original ADX header proof and open coefficient boundary

Status: bounded original-word integer/ownership evidence, 2026-11-06.
**Successful ordinary tag0 header initialization remains incomplete.** No game,
audio device, real asset parse, native header core, full build or new EE/FPU
instruction implementation was run. This work preserves partial evidence instead
of substituting coefficient/trig results to force successful admission.

## Original path and state authority

Owned executable `game_data/SLUS_207.65`, SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Catalogue `recomp/config/outbreak_ghidra_functions.csv` supplies exclusive body
ends. Generated audit companion is
`build-native-sjuni/candidate-work-v6/project/recomp/config/output`; its comments
are checked against owned words, not assumed to be current runtime semantics.

```text
12D638 outer state1 -> 12CCE0
  real SJRB GetData(max4096)
  grant<16 -> UngetData and return
  124CD8: actual BE8000 -> 1249E8
    inner header half+2=1
    126798 base -> inner+C..+18 + local header length
    type<5 ordinary ADX:
      126918 version/control ->1250A0 key ->134F28 predictor key
      126898 filter ->126990 history to stack
      134EB0 ->126510 coefficient math (OPEN)
      134ED8 predictor history (not reached in partial corpus)
      126AC8 loop /126D28 AINF (not reached in partial corpus)
      inner tag+98=0; copy decode geometry+50..+64; clear+8C
      return signed header-length halfword
  outer result0 or result>grant -> UngetData; retain header state1
  result<0 -> UngetData, diagnostic, state4
  accepted -> header-byte count+98, real split/PutFree/UngetData, state2
```

The fit check on the **declared full header length** follows the compound parser,
not its individual field setup. In the wrapped case a real 54-byte first grant
contains enough fixed fields to reach coefficient setup while declaring96 bytes.
It stops at the same FPU boundary before outer admission/fit handling. The case
name `outer-wrap-short-first-span` describes that shorter grant, not a claim that
the outer service already deferred it. Native whole-header admission and selective
effects must be specified explicitly rather than inferred from this check.

Base parser preserves raw BE32 rate/total, signed byte arithmetic for block/bits,
zero-bit samples-per-block0, and low-halfword(headerOffset+4) wrap. Version/filter/
history parsers have distinct fixed-length and signed declared-offset checks.
Many failed/deferred calls leave inner header-state/base fields changed. Loop
and AINF returns are ignored later by `1249E8`, so their selective clearing and
partial metadata writes matter. See existing
[base/header mapping](../SYMBOLS_ADXB_DECODER_LIFETIME_HEADER_AND_PHASE.md),
[metadata mapping](../SYMBOLS_ADX_HEADER_HISTORY_LOOP_AND_AINF.md),
[key selection](../SYMBOLS_ADXB_KEY_SELECTION_SNAPSHOT_AND_PCM_CALLBACKS.md) and
[outer ownership](../SYMBOLS_ADXB_HEADER_INPUT_AND_OUTPUT_SERVICE.md).

## Frozen original execution

[adx_header_oracle.py](../../tools/native_reconstruction/adx_header_oracle.py)
reuses unchanged integer/MAC/division/branch engines and bounded runner. It loads
complete original header/helper/SJRB bodies and actual signature validators for
non-ADX rejection. Prepared outer/inner/predictor records are explicitly synthetic;
this is not decoder-pool construction or an admitted game header.

Authored inputs were saved before original replay:

- `build-native-sjuni/adx-header-oracle-v1/original-fixture-inputs.json`, SHA-256
  `a643baf7e599a25f403d9b7fa986aa6669566b08228f7b73f4b02cfe1d427eaa`.
- `build-native-sjuni/adx-header-oracle-v1/original-fixture.json`, 4,100,046 bytes,
  SHA-256 `0e14d00464193c3585c377c8e38118b127bb38257030bc95cc13d3c9188f2d60`.
- 39 cases, 31 returned integer/short/reject cuts, eight partial ordinary ADX
  executions. 16,082 original instructions, 1,256 distinct visited words.
- Source audit matches1,802 comments plus26 omitted zero words, no omitted
  nonzero word. Loaded original bytes and all unchanged engine identities are
  pinned in the fixture. No coefficient result or successful header outcome is
  scripted.

The corpus covers complete outer lengths0/1/15/16/19, bad magic and AHX-without-
plugin rejection, bad/signed declared offset, mono/stereo/version4, configured/
fallback/derived key paths, zero rate/bits partials; complete base/version/filter/
history/loop/AINF/key helper cases including signed bytes, BE32 values, halfword
wrap, short returns, partial clearing and corrected final loop word `base+14`.
The AHX case is a **negative control**, not an AHX plugin/native admission claim.

Sixteen checks in
[test_adx_header_oracle.py](../../tools/native_reconstruction/test_adx_header_oracle.py)
pass, including deep exact replay of all39 cases, source/engine identity,
unchanged sentinel ranges, real ring return/held credit, selected key stores,
metadata layouts and exact partial failure. Run:

```text
python -m unittest discover -s tools/native_reconstruction -p test_adx_header_oracle.py -v
```

Use an unused `--output` path for new cohorts; earlier inputs/output are refused.

## Exact partial failure and retained evidence

All eight partial executions stop at **`126514`, word `E7B60038`,
`SWC1 f22,0x38(sp)`**, with `UnknownInstruction` for opcode39hex. This is the
coefficient function's FPU save prologue, before coefficient numerical operations.
No FPR, FP store or math return is fabricated. The actual preceding `addiu sp,-64`
and all caller stores remain observed; the function has not returned and ABI
restoration/return value is not claimed.

For a normal96-byte input the actual outer data borrow is still held:
data0/free1952 plus held96 equals2048. Inner base/version/filter fields and
predictor key writes are present. Predictor history and coefficients retain
their old sentinel bytes; loop/AINF and final decode-geometry publication have
not happened. The wrapped partial holds54 bytes, leaving42 data bytes. These
are useful intermediate observations, not completed or safely reusable sessions.

External hooks are only synchronous observation guards/diagnostics, bounded
generic memset/memcpy/memcmp, and the actual owned `%08X` formatter boundary
`10A830` used by key selection. That hook accepts only format pointer239BB0,
the verified literal, eight uppercase u32 hex digits plus NUL into bounded stack.
Actual `124558` still executes every key-table recurrence; no key result is
supplied. The table239360..239B60 has SHA-256
`eb7433da1be18cc81b0523fafbf76266e10b915311bff270bba75090103a3740`.
No codec/plugin or math/FPU hook is installed.

## FPU and math closure still required

| Original interval | Identity / exact dependency |
| --- | --- |
| `1249E8..124CD4` | `abd26f34e1ee76095d22edc9b9343598ad81058013d7d2761d6e1a897250b982` |
| `124CD8..124E3C` | `2a4735a8f0b3f84fc4ab932eb34e63c8dcaadcda802c3c584faa19f8970aab51` |
| `12CCE0..12CEB8` | `3027230bd9bdc3f8478350ce97813f064a4c36da9006bcea571457c9f34cea7d` |
| `134EB0..134ED4` | `8cbc9ebaa48c7a1c0b466706a145ed4dbde8a696e9aab8b9c344c1dd909b0a14`; integer tail to126510 with rate/filter and coefficient output pointers |
| `126510..12666C` | `9071bc1f23b6d55e342c906cd9df971f1c8fb1faf4c3b776b61cb0acfe9cd832`; original FP sequence and coefficient halfword stores |
| `1223D0..1224A4` | `1c853c3b8c8b3d8dfdd8e401d55955b60f3b7e276d6f1c2f82c7de51a37755ee`; actual cosine wrapper, direct120F68 or argument reduction120AE8 then120F68/121920 |
| `120F68..1210B8` | `f700e78b1d84eba817294b321975f0877968443cbc2cb8973c146855615e78b2`; complete small-argument cosine kernel, no external math call |
| `120AE8..120E98` | `4ad12a171da9d2695269667ccbb0f9710d78a5efc5ff03b55d79dd093f8d070c`; reaches1210B8 and1224A8, requiring their own closure if admitted |
| `121920..121A24` | `8837af734bc8825b84dd148c02169bba6003e38bfa58dbb344fa97c0518fbf25`; alternate kernel, no external calls |
| `122708..12271C` | `76a67099109886707be5ec03ea65e607376eac3e3b37e29b5a4a9d22b0edf945`; actual tail120E98, not a host-libm oracle hook |
| `120E98..120F64` | `7a3a6762a210fd2acf990140bdbf879d3ead40138732a3929cf63ba8109523a3`; original fallback body with integer/FP paths, no external calls |

Required transport/arithmetic includes LWC1/SWC1, MTC1/MFC1, CVT.S.W/CVT.W.S,
MOV/ADD/SUB/MUL/DIV/SQRT/NEG single precision, FP condition/branch and likely
delay annulment. Wider closure needs actual kernels/argument reduction and
exception paths. Using Python float, host `cos`, a supplied coefficient table,
or skipping these calls would not establish original-word header parity.

## Existing local FPU authority and next bounded proof

Repository inspection found useful existing fixes, not a reusable full original-
word FPU machine:

- `third_party/PS2Recomp/ps2xRecomp/src/lib/code_generator.cpp`, SHA-256
  `cf90c94d772b028bc71ebe965a6c3ad29cc9e89f6b22ac481c87e88d868c6f55`,
  emits SQRT.S from **Ft**, and special DIV.S zero handling. Original12652C
  `46160504` uses Ft22→Fd20;1265E8 `460C0004` uses Ft12→Fd0. Patch
  [0031](../../third_party/patches/ps2recomp/0031-r5900-sqrt-ft-operand.patch)
  includes exact opcode emitter regression tests. This avoids repeating the
  historical Fs/Ft bug.
- `ps2_runtime_macros.h`, SHA-256
  `763baab6071c4a10c418a2f9f968e92e4da2e62a1e5ace642593a38d4c734287`,
  uses host single-precision operations and `sqrtf`; this is current runtime
  implementation authority, not a proof of all EE exceptional arithmetic.
- `ps2_fpu_convert.h`, SHA-256
  `db9db81090400ac42fd7e391c0998887c4e922a1cb7c0d77516f47d3d8a9c8f3`,
  implements raw-bit CVT.W.S fixed truncation/sign saturation. Patch
  [0091](../../third_party/patches/ps2recomp/0091-ee-cvt-word-fixed-truncation.patch)
  makes it the runtime macro; a plain host rounding cast is not interchangeable.
- [Historical D48 evidence](../DIVERGENCES.md) records coefficient validation at
  24/44.1/48kHz after the SQRT fix and a particular PCM comparison. Those are
  prior results, not newly reproduced whole-header or all-input EE-FPU proof.
  `tools/repair_generated_sqrt.py` checks emitted operands, not full arithmetic.

The next smallest bounded proof is complete126510 plus actual1223D0 and the
actual120F68 kernel for declared positive finite rate/filter profiles that stay
on its small-angle path, with raw FPR save/restore, condition state and every
binary32 step. Start with explicit24/44.1/48kHz and filter500 inputs, then
conversion/branch boundaries. Execute the full original/generated slice with
matching current runtime macros, compare both compilers and independently
qualify instruction transport/rounding. Any unexpected reduction/fallback target
must refuse and preserve partial evidence until that complete body is included;
do not return a guessed value. Clearly distinguish compatibility with the pinned
recompiled runtime from stronger PS2 hardware exceptional-FPU equivalence.

Only after that closure can successful `1249E8→12CCE0` be replayed through
history/loop/AINF setup, header prefix/free return and outer state2, and then
compared to a separately frozen native header owner. The source-derived
1152/2240 request versus256, total>4096, shared encoded credits and mutating loop
callback blockers from [ADXT_PLAYER_OWNER_NEXT.md](ADXT_PLAYER_OWNER_NEXT.md)
remain in force. No engine, frozen window/refill core or runtime file was changed.
