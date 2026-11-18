# Independent original-word movie-position oracle

2026-11-05. This is a finite synthetic execution of owned File #1 instruction
words. No game, movie, decoder, audio device, process attachment, full build or
playback measurement was run. No native picture-position implementation was
inspected or imported to produce expected values. The native prototype was
independently frozen by the parent before this fixture was released for comparison.

Implementation: `tools/native_reconstruction/movie_position_oracle.py` and
`test_movie_position_oracle.py`. It closes the proposed first arithmetic cut in
[the remaining clock boundary](MOVIE_CLOCK_NATIVE_BOUNDARY.md), not the whole
selected-clock, source, pause, due/skip or frame-return controller.

## Frozen evidence

`build-native-sjuni/movie-position-oracle-v1/original-fixture.json`:

* **1129306 bytes**, SHA-256
  **`232d07ee2991cb07f25bc65247db597aa2a85f6080ef8d1bff47c45b5fa94822`**.
* 25 complete publisher cases,30 standalone arithmetic-helper cases;6663 original
  executed instructions.27 helper cases return;3 stop at a reached original
  BREAK. The publisher results have no invented normalized success return.
* Original ELF SHA-256
  `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
  Every admitted body is independently hash checked before interpretation.
* Inputs and actual table word are separate from expected before/after snapshots,
  ordered accesses/writes, complete instruction-visit counters, actual body-entry
  counts and lower64 ABI/MAC snapshots. Actual call-frame guard words are retained.

The frozen fixture was announced before parent comparison with the native core.
Do not replace its expected rows with native outputs. New cases should produce
a separately identified fixture with a new hash before another comparison.

| Original body, end exclusive | Bytes | SHA-256 |
| --- | ---: | --- |
|16F338..16F434 publisher|252|`a9da933b0444e36ca9216439b9987a8c43b35329f1a8018707f1760a43940747`|
|171530..171540 real side-input-enabled getter|16|`fe86d348b236afbb16ed45b2d5206cf8b37db1ce50cd27246e3da791ec753591`|
|171E58..171E64 real side-input counter getter|12|`520d116b70df02845b4cf1f537ef3f05d6c8133d5189643ff392dfc7aae8dd0f`|
|15BA80..15BAEC real product/ratio helper|108|`10fceefc065a3b476f69b6420d7135bb0882e6baf7e106ffe21d58398767edd5`|
|10FB18..1101AC complete signed64 quotient body|1684|`b062fd51648ef4ea2270b845c3cd6b1760a55bfc7f1f3de9fe5e34c703fd0aae`|

The generated reference is
`build-native-sjuni/candidate-work-v6/project/recomp/config/output/`.
All516 distinct instruction comments in these5 bodies match the owned ELF;
2 omitted aligned words are zero. No omitted nonzero word or comment mismatch
was accepted. Raw body hashes include those zeros. The oracle fetches original
words, including omitted zeros, rather than executing generated C++ comments.

Owned rate table240AF0/36bytes is read directly, SHA-256
`a667ab0a5ce47cd7b60cc99ae7013e555d1042649698fecaa52ad08eb3b25f6b`.
Normalization table2381A0/256bytes is likewise original data, SHA-256
`14a5d850c255623f9472e3c650abce0c78d32f0276b315b3a276a0462d97a1ac`.
Both are mapped read-only during original execution. Every case records the
actual selected table word; it is not a duplicated native rate formula.

## Execution and generic ISA closure

The unchanged `sjuni_oracle` lower64 integer engine and `EeMacInstructions` supply
the existing branch, memory, word arithmetic and two-bank multiply/HI/LO behavior.
This oracle adds only generic SLLV/SRLV, DSLL32/DSRL32/DSRA32 and unsigned-word
DIVU instruction semantics. There is no hook for either getter, multiplication,
ratio calculation or full quotient routine. Python integer division implements
one architectural DIVU instruction after its operands are checked; it never
substitutes for10FB18's actual normalization, quotient-digit corrections, sign
handling or branch paths. Branches, likely annulment and delay slots execute;
there are no loop teleports or precomputed whole-function returns.

The runner admits only the exact five owned ranges, bounded disjoint named
synthetic spans and a10000-instruction cap per call. Unknown encodings, reserved
new-instruction fields, writes to owned tables, unmapped accesses, control
transfers in delay slots and unowned call targets fail closed. The engine has no
runtime, scheduler, interrupts, host timer, codec or device implementation.

Hand-calculated microchecks establish word masking/sign extension, variable shift
masking,64-bit arithmetic/logical shifts, DIVU quotient/remainder bank behavior,
secondary-bank preservation and pre-mutation refusal of undefined DIVU-zero.
Separately, exact pinned local recompiler emission templates and original
SLL32/SRL32 macros were extracted and compiled: **204 cases each passed GCC and
LLVM**. This checks emitter consistency for the added generic instruction forms,
not a linked full runtime or compiled complete quotient-body equivalence.
Receipt: `build-native-sjuni/movie-position-emissions-_oq_wyl7/receipt.json`.
The pinned emitter identity is validated through the unchanged MAC oracle's
`implementation_identity()`; the fixture also contains hashes of the three
engine/source files used to generate it.

## Corpus coverage and selective effects

Publisher cases include side input disabled/enabled, all9 owned rate indices,
raw nonboolean flag2, zero/negative/large counters, wrapped counter delta and
delta*1000, signed minimum/maximum scales, positive/negative large products,
negative bias, origin/bias wrap, signed-increasing latest position, and exact
equal/decreasing latest values that preserve the old scale too.

Every enabled publisher case executes the real171530 and171E58 getters, then
15BA80 and10FB18 exactly once. Disabled cases execute171530 and no numeric helper.
Recorded original write order is descriptor10,C,20,24, with enabled-mode
overwrites20,C,24. Main writes are either none or exactlyF00 thenF04. Inner source
fields remain unchanged. Full before/after CC0, D54 and descriptor word views
retain surrounding state; ABI tests verify callee-saved lower64 GPRs, SP/RA,
secondary MAC bank and call-frame guards. Raw publisher v0 remains explicitly
undefined as a public return contract.

Standalone helper cases complement the actual publisher domain: zero/small
quotients, positive/negative signs, high64-bit numerators/denominators, minimum
signed64 magnitude, the MIN64/-1 result bit pattern, normalization paths and
zero-divisor handling. For15BA80, divisor0 returns the original XOR-sign limit,
including zero multiplicands, without entering10FB18. Three direct10FB18
zero-divisor cases actually reach **BREAK7 at10FD58**; their partial state and PC
trace are retained with no fabricated return value or claim that a game trapped.
Architecturally undefined DIVU-zero remains refused if reached; the microtest
for that instruction is separate from these observed original BREAK paths.

Across the fixture, original visits cover all63 words in the publisher range,
all4/3 getter words,26/27 product/ratio words and316/421 quotient words. The
publisher cases alone visit203/421 quotient words. Whole bodies are admitted and
real instructions execute on every taken path; this is **not exhaustive branch
or all-input arithmetic proof**. Unvisited division correction paths and a wider
input sweep remain useful follow-up, not silently covered claims.

The schema deliberately distinguishes the native publisher's input profile from
the broader standalone quotient tests. Publisher rate indices outside0..8,
overlapping/aliasing source/descriptor/stack regions, MMIO, other source providers,
concurrent mutation, upper128 GPR lanes and FPU state are excluded. Invalid
pointer/index cases need original fallback or further evidence in a future live
adapter. The fixture does not authorize changing original movie clocks, dropping
frames, enabling a runtime path or removing consumer fences.

```powershell
python -m unittest discover -s tools/native_reconstruction `
  -p test_movie_position_oracle.py -v

# For a NEW separately frozen fixture; do not overwrite evidence under comparison:
python tools/native_reconstruction/movie_position_oracle.py `
  --output build-native-sjuni/movie-position-oracle-next/original-fixture.json
```

12 tests passed, including the two compiler emission checks. No native core was
used as an oracle. Agreement with this bounded original corpus would establish
the compared picture-position arithmetic/profile only; audio-clock filtering,
start/pause/end control, source lifetimes and full-player parity remain separate.
