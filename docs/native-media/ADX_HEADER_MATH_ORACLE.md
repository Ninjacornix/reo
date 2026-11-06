# Bounded original ADX math and full header replay

Status: isolated original-word/current-runtime compatibility proof, 2026-11-06.
The finite500Hz-filter profiles at24/44.1/48kHz now execute the complete
coefficient function and actual small-angle cosine kernel. New full-header
cases reach real prefix return and outer state2. Three out-of-profile cases
remain explicit partial refusals. No game, device, runtime edit, native header
implementation, performance measurement or PS2 exceptional-FPU equivalence is
claimed.

This extends the evidence in [ADX_HEADER_ORACLE.md](ADX_HEADER_ORACLE.md) in
new files only. The old integer engines, old39-case/8-partial cohort and native
refill/window cores remain unchanged. Historical input IDs containing
`COP1-open` are retained for traceability; their actual new result states are
reported rather than inferred from those names.

## What executes

[adx_header_math_oracle.py](../../tools/native_reconstruction/adx_header_math_oracle.py)
executes original integer/control words using the existing bounded engine and a
local FP extension. Each new FP step transfers raw32-bit FPR and lower64-bit
GPR state to a persistent compiled helper. **Python performs no floating-point
arithmetic.** LWC1/SWC1 use the actual mapped memory and store ledger; integer
branches, calls, returns, delay slots and likely annulment remain in the ordinary
runner. Every function call below reaches its actual owned body:

```text
126510 coefficient function
  original CVT.S.W / binary32 arithmetic / SQRT.S
  1223D0 actual cosine wrapper ->120F68 actual small-angle kernel
  original binary32 arithmetic / CVT.W.S / coefficient halfword stores

12D638 ->12CCE0 real SJRB data borrow ->124CD8 ->1249E8
  actual base/version/filter/history/key parsers and key-table derivation
  134EB0 ->126510 ->1223D0 ->120F68
  134ED8 history install ->126AC8 loop ->126D28 AINF
  decode geometry and format publication
  outer real split/PutFree/UngetData ->state2 (or real declared-length defer)
```

The compiled helper implements only the reached FP instruction families. It uses
the pinned actual runtime macro text, actual `Ps2FpuConvertWord` header, actual
GPR extraction/setter helpers and source-derived DIV.S zero handling. It never
calls host `cos`, supplies a coefficient table, skips a callee or fabricates a
math return. Host `sqrtf` appears only because that is the pinned runtime's
literal implementation of an original SQRT.S instruction. Guest software
fallback122708 and argument reduction120AE8 are not replaced by libm.

Original executable identity remains
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Loaded27 complete body hashes are recorded, including:

| Complete interval, exclusive end | SHA-256 |
| --- | --- |
| `126510..12666C` | `9071bc1f23b6d55e342c906cd9df971f1c8fb1faf4c3b776b61cb0acfe9cd832` |
| `1223D0..1224A4` | `1c853c3b8c8b3d8dfdd8e401d55955b60f3b7e276d6f1c2f82c7de51a37755ee` |
| `120F68..1210B8` | `f700e78b1d84eba817294b321975f0877968443cbc2cb8973c146855615e78b2` |

Generated comment audit matches1802 header/helper comments plus134 new math
comments, with26+3 omitted zero words and no missing nonzero word. Complete
body loading is not all-input execution coverage.

## FP instruction qualification

Before function replay, both GCC and LLVM compile a helper containing two modes:
the local generic instruction decoder and **exact audited emitted statements**
for70 owned instruction words. The reference statements come from the actual
generated body/comment pairs and are tied to the pinned current generator and
runtime source. The full raw result is compared: all FPR words, lower64 GPRs,
memory address/value/write flag, FCR31, branch condition and likely flag.

1975 authored micro inputs cover16 reached instruction classes: LWC1/SWC1,
MTC1/MFC1, BC1T/BC1TL, CVT.S.W/CVT.W.S, ADD/SUB/MUL/DIV/SQRT/MOV/NEG.S,
and C.EQ.S. Vectors include signed zero, smallest/largest subnormals, normal
numbers, ±1.5, conversion boundaries, max finite, infinity and quiet/signaling
NaNs. FCR31 conditions/other bits vary. CVT.W.S repeats under all four host
rounding modes and retains fixed raw-bit truncation/saturation. Separate
whole-run branch tests verify executed versus annulled FP delay slots.

Each compiler matches its exact-emission reference on every micro input. The
actual MFC1 `SET_GPR_U32` macro **sign-extends** the word in this runtime; the
extension does not infer zero extension from its name. SQRT.S uses Ft, including
the original distinct-Fs/Ft words46160504 and460C0004. No new FPU instruction was
added to a frozen/shared engine, and an unqualified word refuses before mutation.

Pinned source authority:

- Generator SHA `cf90c94d772b028bc71ebe965a6c3ad29cc9e89f6b22ac481c87e88d868c6f55`.
- Runtime macros SHA `763baab6071c4a10c418a2f9f968e92e4da2e62a1e5ace642593a38d4c734287`.
- `ps2_fpu_convert.h` SHA `db9db81090400ac42fd7e391c0998887c4e922a1cb7c0d77516f47d3d8a9c8f3`.

Helper compile flags are recorded: C++20, O2, SSE4.1, no fast math, FP contraction
off, rounding-math enabled. The measured private helper startup has host
FE_TONEAREST and MXCSR1F80 (no FTZ/DAZ); unqualified startup rejects. Actual
runtime FP operations can depend on compiler/environment. This proof does not
silently transfer to a game build with different flags, a different host FP
environment or PS2 hardware exception/denormal behavior. Guest FCR changes follow
the literal emitter; hardware exception propagation beyond that implementation
is not invented.

## Frozen cohort and observed results

Inputs were saved before any qualification/function expected observation. Final
private cohort is `build-native-sjuni/adx-header-math-oracle-v4/{gcc,llvm}`:

| Artifact | SHA-256 |
| --- | --- |
| Both `inputs.json` | `ab304db5087b8c476b3e818c60d35da2fbaa9915161b71f6d0615391de0fc843` |
| GCC `original-fixture.json` | `7ffa76de4fe5aa56e4825c1a4a25ed591d5dfefe0331807848498974707a7158` |
| LLVM `original-fixture.json` | `0e2b3fd61fdcad1fe4f6f7fb479165dc6fe706bf12427e5533787371ed8d0d8f` |
| GCC `micro-qualification.json` | `505e34926ec478464ca87abe03d231d77f6b7ba6d48910b1d0919337a9b4322f` |
| LLVM `micro-qualification.json` | `e1e58a04f30f161eab3cda501545024e37a635b7d9d9df43abdc1f0dbcbd4744` |

48 function/header cases give45 returned results and3 explicit partials,
26,340 original instructions and1132 FP steps. **All48 complete observed case
objects match exactly across compilers**, including partial memory/state. The
full corpus combines the original39 input cuts, three finite math functions,
two range/zero-rate math refusals, and four extra full headers at24/48kHz or
with loop/AINF metadata. Artifacts are about13.2MB/compiler, not RAM dumps.

| Rate / filter, decimal Hz | Observed signed16 coefficients |
| --- | --- |
| 24000 /500 | 6687, -2729 |
| 44100 /500 | 7334, -3283 |
| 48000 /500 | 7400, -3342 |

These values are outputs of actual original instructions under the qualified
runtime, not supplied expected coefficients. f20/f21/f22 restore their original
raw caller values on returned paths. Actual final conversion words and stack/
selective field effects remain in the fixture.

There are21 outer header cases:20 return, of which10 reach state2, eight defer
with state1 and two reject with state4; zero-rate remains partial. Nine state2
cases have the intended4-bit/18-byte mono/stereo shape. The tenth is a deliberate
zero-bits negative control: original header still returns with samples-per-block0.
That behavior is **not** a native decoder-format admission.

Successful header paths consume the real96-byte input prefix and return free
credit. Version4 history installs actual interleaved halfwords1234/FEDC/5678/BA98;
complete loop and AINF cases reach their selective stores after coefficient math.
The wrapped54-byte/declared96 case completes coefficient/history/metadata setup
but then returns the full borrow and remains outer state1. It preserves those
selective effects; no whole-object rollback was introduced.

All three partials stop at unowned120AE8: zero-rate outer header, zero-rate math,
and filter8000/rate44100 needing cosine argument reduction. Their real partial
stack, FPR/GPR and held input credit remain captured. Coefficient writes/return
are not fabricated. General range-reduction/software-fallback closure remains
open.

## Explicit exceptional-domain difference

Two signaling-NaN SQRT micro probes differ across compilers. With operand
`7FA12345`, GCC returns quiet `7FE12345`; LLVM retains `7FA12345`, for both owned
SQRT words. Each matches that compiler's exact pinned emission, and both raw
results are preserved. The tests require this difference; no NaN normalization
hides it. All finite admitted whole-function/header cases remain identical.
Consequently this is not a compiler-independent all-NaN arithmetic oracle or a
claim of PS2 hardware exceptional-FPU fidelity.

## Checks and remaining boundary

Sixteen regression checks pass, including both complete1975-case micro replays,
both full48-case original replays, source/helper binary identity, FP callee
restoration, real header admission/prefix return, wrap defer, loop/AINF stores,
conversion/branch controls, preserved sNaN difference and unqualified-word refusal.

```text
python -m unittest discover -s tools/native_reconstruction -p test_adx_header_math_oracle.py -v
python tools/native_reconstruction/adx_header_math_oracle.py --compiler g++ --output build-native-sjuni/adx-header-math-new/gcc
```

Use unused output directories. Prior v1/v2/v3 evidence remains preserved. V2
added complete math comment audit and cached owned-word admission, V3 closed
helper pipes cleanly, V4 adds full24/48kHz and loop/AINF inputs. No earlier
expected cohort or frozen engine was rewritten.

The next native header owner can now target this explicit finite profile and
compare complete state/metadata plus shared-source prefix return. It must define
before-effect admission for malformed/unsupported geometry and retain original
selective effects for its admitted defer/reject domain. Wider rate/filter inputs,
argument reduction, exceptional FP, plugin routes and actual asset population
need their own closure. ADXT loop callback scheduling, clocks and RNA credits,
and Window's request256/total4096 limits versus real1152/2240 requests remain
separate [owner-plan blockers](ADXT_PLAYER_OWNER_NEXT.md). This proof supplies
evidence for that work; it does not wire or replace the player.
