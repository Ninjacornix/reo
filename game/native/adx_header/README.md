# Typed ADX header and source admission

An ordinary C++ parser/math core plus `HeaderOwner` over the existing owned
`EncodedSource::DataLease`. No R5900 context, register/word interpreter, guest
pointer, raw ring escape, host cosine or coefficient lookup. This library is not
wired into a game and does not implement full ADXT/loop/clock/RNA ownership.

Pure helpers preserve source signed widths, BE fields, selective failure writes,
history interleave, loop/AINF layouts, actual key-table derivation and fixed
CVT-word semantics. The finite500Hz-filter/rate24000/44100/48000 math follows
the original120F68 polynomial and126510 binary32 operation order. The packed
key table has the owned original SHA-256 documented in `key_table.inc` and the
freeze receipt; this is key derivation data, not a coefficient result table.

Ambient FE_TONEAREST and MXCSR1F80-compatible controls are checked, ignoring
accrued exception bits. Unsupported modes refuse without reconfiguration.
Finite math preserves the caller's environment/status. This is scoped pinned
runtime compatibility under the compiled FP flags, not exceptional PS2 hardware
equivalence; signaling-NaN arithmetic remains unsupported.

`HeaderOwner` copies the actual shared-source grant into fixed4096-byte staging,
parses immutable bytes, and returns the consumed prefix or ungets the whole
borrow. Wrapped short-grant/full-header defer preserves completed selective
configuration. Successful header-byte count is stored before credit return;
state2 follows it. Source/PCM/shared-bank stop or reset is never implicit.

Header owner, shared key context, source and callbacks/snapshot readers require
one externally serialized domain. The boolean reentry guard is not a mutex or
cross-thread synchronization. Hooks are read-only; source/provider callbacks
cannot mutate this state during a header operation. Strong input/context owners
retain actual lifetimes. PCM values here are copied geometry metadata only.

Unsupported pure parser admission has no decoder/context effects. The source
owner must already borrow bytes to inspect them; unsupported owner service
therefore performs an observable Get/Unget pair and reports native unsupported.
It never claims whole-transaction absence of effects or invokes original code
as fallback. Original unsafe/partial domains remain separately recorded.

If source credit return fails, updated parser/header-byte state remains with the
actual lease held. `return_held` is explicit serialized retirement, not rollback
or a proven original recovery. A destructor never silently returns credit from
an arbitrary thread. No output/storage ownership or worker join is invented.

The first profile handles version3/4, encoding3/block18 mono/stereo with bits4;
zero-bits source metadata behavior is retained as an explicit negative control,
not admitted as a working codec. Other format signatures are unsupported before
parser mutation, and missing AHX plugin follows the original rejection path.
Short non-ADX inputs whose original validators overread the declared extent are
refused rather than supplied fabricated bytes.

The native core was written after independent original-oracle exposure, then
frozen before its comparator. No blind-authoring claim. Both GCC/LLVM pass66
units and all48 paired classifications:45 admitted projections plus three
explicit unsupported controls. All state/helper/metadata dictionaries and actual
shared-ring credits match, including three diagnostic observations. The first
actual comparison passed with the frozen algorithm unchanged. Standalone
CMake/Ninja and CTest1/1 also pass.

```text
cmake -S game/native/adx_header -B build-native-sjuni/adx-header-checks
cmake --build build-native-sjuni/adx-header-checks
ctest --test-dir build-native-sjuni/adx-header-checks --output-on-failure
python game/native/adx_header/compare_original.py --compiler g++ --output build-native-sjuni/adx-header-parity-new/gcc
python game/native/adx_header/compare_original.py --compiler clang++ --output build-native-sjuni/adx-header-parity-new/llvm
```

Choose unused output directories; evidence is never overwritten. CMake applies
`-fno-fast-math -ffp-contract=off -frounding-math` to this component's algorithm and
checks. Final receipts are
`build-native-sjuni/adx-header-native-parity-v2/{gcc,llvm}/receipt.json`.

See [complete qualification/limits](../../../docs/native-media/ADX_HEADER_IMPLEMENTATION.md)
and [independent original math/header evidence](../../../docs/native-media/ADX_HEADER_MATH_ORACLE.md).
Future Window v2 still needs shared input ownership, real1152/2240 requests and
long totals, and complete mutating loop transitions before game integration.
