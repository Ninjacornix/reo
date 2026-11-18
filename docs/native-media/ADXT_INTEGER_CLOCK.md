# ADXT integer ratio queries and mode state

Status: isolated native arithmetic and original-word comparisons, 2026-11-06.
No game hook, actual queue owner, playback timestamp or stutter fix is supplied.
The estimated FP/tick clock at `132160` remains a separate dependency.

[`integer_clock`](../../game/native/adxt_integer_clock) implements the integer
part of four original entries: mode selection `131F28`, RNA/terminal ratio
`131F60`, decoded-minus-queued ratio `132028`, and resynchronization count
`132148`. It uses typed values, with no runtime headers, guest registers,
addresses, callback, allocation, I/O or retained storage. The caller supplies
externally serialized observations; the original ring count getters perform
no local synchronization. This component does not establish a coherent snapshot
of a concurrently changing audio pipeline.

## Preserved behavior

All integer additions, subtractions, products and the counter wrap modulo32.
For active states3/4, the RNA query returns base/48000 through the actual fixed
RNA child. The raw query returns frequency and decoded samples minus RNA
occupied halfwords and channel0 output halfwords, plus `A4` and base `88`.
Each queue's byte count truncates separately before subtraction; combining odd
counts changes the result. An absent output ring contributes zero.

State5 uses total times `trunc(16/reported_depth)` and frequency. Only the raw
query adds `A4`; both add base. The original depth selector returns4,8 or16 for
the admitted typed header modes, including fallback modes. Its caller contains
a division-by-zero BREAK, but none of these complete selector paths produces
zero. Other states return base/1. These are ratios; zero frequency is preserved
as a value rather than divided inside the core.

Mode1 selects5994, mode2 selects5000; all other raw selections preserve the
existing ratio while storing the new mode. The separate count increments once
modulo32. Neither entry advances game time or reads a device clock.

Native admission rejects an unknown query and, only where actually used, queue
counts outside the actual16,384-byte geometry. These are explicit new safety
refusals; the original was not claimed to reject such prepared snapshots.
The current component does not model null/aliasing guest output pointers or
observable store ordering between aliased original fields.

## Original authority and freeze

Authority is owned File1 ELF SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
The new [oracle](../../tools/native_reconstruction/adxt_integer_clock_oracle.py)
pins17 complete source intervals and executes their original instructions,
including original ADXB getters, depth selection, RNA traversal and both actual
SJRB count calls. A source audit matches374 commented words and four omitted
zero words; no nonzero word is missing. Unchanged prior EE/MAC/division engines
are hashed in the input manifest. Queue fields are prepared synthetic snapshots,
not results supplied in place of those executed getters. No sample accounting
algorithm or native result is used to generate expected values.

The132 authored inputs were frozen before original execution. All132 return,
executing8,689 instructions and248 unique addresses. Cases cover all distinct
state branches, long counts, signed raw word boundaries, depth mode/code routes,
separate odd queue lengths, absent output, modular products/offsets, arbitrary
mode selections and counter wrap. This is finite synthetic coverage, not all
possible input values or real scheduling. V1 stopped during source auditing
before replay because a combined interval needed two source companions. V2
splits those authority intervals and retains the same authored cases.

The native core was authored **after inspecting source and this original
corpus**, then frozen before the native comparator. It is not blind
reconstruction. Freeze receipt SHA-256:
`0cacbf321b371d47aa2359d0729835e46c49cab13c45593f277ed9a9dabdca29`.
Core/header/unit/CMake bytes remained unchanged during paired comparisons.

The inputs-only native probe compares numerator, denominator, mode, selected
ratio and count. Full original observations retain callee-save checks, touched
fields, queue state, output guards and instruction/read/write evidence. The
native value contract does not compare volatile registers or intermediate
guest stores. Two deliberate mutations are detected by both compilers: applying
`A4` to RNA queries (55 cases) and combining queue counts before halving (two).

## Verification and receipts

GCC15.2 and the actual bundled UCRT LLVM21.1.8 each pass16 native assertions,
132/132 original comparisons and both negative controls. LLVM driver SHA-256
is `f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3`;
its bundled bin precedes child PATH. Eight Python tests re-execute every frozen
original transcript and check identities and getter paths. An initial test
assertion incorrectly expected guards in count getters; source inspection and
recorded reads showed they have none. The assertion was corrected; original
results and native frozen files were unchanged.

| Artifact | SHA-256 |
| --- | --- |
| `build-native-sjuni/adxt-integer-clock-original-v2/inputs.json` | `5a5ca400685c9677ad5049587d88e6cfe141eb3ac25b6952ed271392b2bcfc23` |
| `input-manifest.json` | `190455142f43f5ce90b2faf9d7767fd952402bdadd7f3c60df47cef748f8fbc6` |
| `expected.json` | `d2acb71e3d5a24526891f83d89b878ecb5fa8d54914e49a6a11eabe3452eb3a2` |
| `manifest.json` | `95b2b5211972ee882f56b5755601e84035c00c87711497c8f605f2598098360f` |
| `build-native-sjuni/adxt-integer-clock-parity-v1/gcc/receipt.json` | `186670754ea6cb50b52569a809c8480b041e95f8e73a5d8bd0905e8db1eeb41f` |
| `build-native-sjuni/adxt-integer-clock-parity-v1/llvm/receipt.json` | `9a49ac7a039d5180425058a0e625d532d930e8f064360d322d1a16d07373ed72` |

Reproduce with fresh private output directories:

```powershell
python tools/native_reconstruction/adxt_integer_clock_oracle.py --output build-native-sjuni/adxt-integer-clock-NEW
python tools/native_reconstruction/adxt_integer_clock_oracle.py --output build-native-sjuni/adxt-integer-clock-NEW --replay
python game/native/adxt_integer_clock/compare_original.py --compiler <exact-compiler> --fixture build-native-sjuni/adxt-integer-clock-NEW --output build-native-sjuni/adxt-integer-clock-parity-NEW
```

The selected `adxt_integer_clock` test passes in both parent standalone Release
CMake projects (`build-native-sjuni/cmake` and `cmake-llvm`). Complete
player integration still requires shared source/window ownership, estimated
clock and pause/rebase semantics, RNA/DTR credits and actual media validation.
See [remaining player ownership](ADXT_PLAYER_OWNER_NEXT.md).
