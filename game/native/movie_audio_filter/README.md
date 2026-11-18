# Native movie audio time filter

The independent typed core reconstructs `177CB0`, `177EB0` and the history and
configuration operations in the [contract](../../../docs/native-media/MOVIE_AUDIO_TIME_FILTER_CONTRACT.md).
It owns a fixed 60-entry history and named state. No guest RAM, register file,
runtime, timer, device or CSV allocation is used by the core.

Original expectations were frozen before this module existed, in
`build-native-sjuni/movie-audio-filter/original-freeze-v6`. All 67 cases,
574 operations and 67 constructors execute actual multiply, signed division,
history, memset and null-buffer CSV helper bodies: 561,990 instructions. Every
non-padding instruction of the main filter is visited. GCC 15.2 and the pinned
LLVM 21.1.8 reproduce all 641 snapshots, including caller input mutations,
complete history, raw pairs, counters, extrema and defined returns. Eight
counterfactuals are detected; admission tests also require numeric failures to
leave live state and input untouched. This is bounded behavior evidence, not
exhaustive proof or a measured stutter fix.

The first comparison rejected a wrong constructor threshold copied from the
earlier static notebook. Actual instructions initialize **200000/1000000**;
the earlier **250000/1000000** annotation was wrong. Failed receipts and the
candidate source snapshot remain under `qualified-gcc-v1/failed-inputs`.
Expectations were not changed to match native code.

The original runner adds independently tested copy/store instructions. Ten ISA
test methods and 624 actual memset cases (292,722 instructions) qualify that
extension separately. Original callee-save state and filter guard bytes are
checked. Five source exclusions retain original BREAKs or out-of-bounds/aliasing
observations rather than fabricated failure parity. Native admission rejects
invalid history, zero divisions on executed arithmetic paths and input/state
pair aliases before publishing effects. Disabled or helper-denominator-one
bypass still occurs before history/numeric validation, as in the original.

Reproduce with `python game/native/movie_audio_filter/verify.py --cxx <compiler>
--output build-native-sjuni/movie-audio-filter/<fresh-scope>`. Each scope preserves
compiler and source identities, original authority hashes, complete transcript,
differences, failed variants and receipt. `manifest.json` and
`qualification.json` record the committed cohort.

No game was launched, real audio device opened or production path selected for
this component. The actual ADXT/counter provider envelope, shared guard ownership,
movie construction, pause/buffering, due/skip, frame/source lifetime, game adapter
and representative transitions remain stage 3 obligations. Gameplay, graphics
and compatibility removal remain stages 4–6.
