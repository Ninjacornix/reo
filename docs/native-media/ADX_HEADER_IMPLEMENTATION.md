# Native tag0 header owner

Status: isolated typed implementation and qualification complete, 2026-11-06.
No runtime adapter, game/full build or native-player completion claim. The independent
[math/header cohort](ADX_HEADER_MATH_ORACLE.md) was already observed; the native
core was frozen before its new comparator, without a blind-authoring claim.

The unit has a pure typed parser and a serialized `HeaderOwner` that
uses the existing `EncodedSource::DataLease`. It owns no second encoded ring,
has no guest addresses/register arrays/runtime headers, and retains no raw
header pointer. A fixed4096-byte staging buffer receives read-only lease bytes;
all retained metadata is copied into typed values.

Pure helpers preserve original integer widths, selective failure writes,
version-specific history/loop/AINF layouts and actual key-table derivation.
Decoder state holds parsed header fields, configured versus current predictor
keys, predictor history/coefficient values, loop/AINF metadata and copied PCM
geometry. PCM geometry is metadata only; this unit neither allocates PCM nor
claims ownership of a future Window v2 output buffer.

The first full math profile is encoding3, mono/stereo, block18, bits4 (plus the
explicit original zero-bits metadata negative control), version3/4, filter500,
and rate24000/44100/48000. Standalone integer helper profiles remain broader
where their original-word cases establish exact signed/BE behavior. Original
zero-rate/argument-reduction partials remain unsupported by the full native
parser before decoder/key-state effects. Unsupported input is not converted to
guessed coefficients or a false original-equivalence claim.

Coefficient generation uses readable named binary32 operations in original
order: actual small-angle120F68 polynomial bit constants, original sqrt and
coefficient scaling/conversion. It uses no host cosine or coefficient lookup.
The key table is the actual1024 halfword table239360..239B60, identity
`eb7433da1be18cc81b0523fafbf76266e10b915311bff270bba75090103a3740`;
its provenance and packed-byte identity must be retained with the implementation.

Ambient FP admission precedes decoder-state writes: FE_TONEAREST and MXCSR
rounding/masks/FTZ/DAZ compatible with1F80, ignoring accrued exception-status
bits. The unit does not force an unsupported caller environment to match the
oracle. It preserves the caller's FP status/environment around its finite math.
Original host exception accumulation and unclaimed source FCR state are excluded
from native-equivalence projection rather than normalized into an invented
guest-FPU object. Signaling-NaN equivalence remains unproven and unsupported.

`HeaderOwner::service` borrows min4096/capacity from the actual shared source,
copies its actual grant, and invokes the pure parser. For admitted short/defer/
reject cases it preserves source-selective state effects and uses exact consumed
prefix/remaining suffix credit. Wrapped54/declared96 must parse/configure first,
then unget the whole borrow and remain outer state1; no generic rollback.
Accepted header-byte count precedes prefix return; state2 follows credit return.
Error diagnostics observe the original ordering around inner effects/input return
and state4. Hooks are synchronous, read-only and nonreentrant.

The frozen source cannot expose input bytes without an actual data borrow.
Therefore an unsupported full profile can be before **parser-state/publication**
effects while still having observable Get/Unget guard activity. The owner returns
the entire lease and reports unsupported; it never claims no whole-transaction
ring effects or calls original fallback afterward. Pure-parser refusal controls
can be genuinely before all parser effects on immutable supplied input. This
distinction was reviewed explicitly before implementation.

The header owner retains the actual source strongly and explicitly returns each
consumer credit. It never silently returns a lease from an arbitrary destructor,
resets an unrelated stream, discards PCM/shared banks, seeks a source or claims a
stop/join fence. A failed credit return remains owned/fail-closed with explicit
retirement instead of fallback. All owner and shared-source calls require one
externally serialized control domain; provider workers access only their owned
result buffers.

`HeaderOwner`, its shared `KeyContext`, the shared source and all snapshot/hook
reads are thread-confined or serialized under the same external owner domain.
The plain `busy_` boolean prevents synchronous mutation/reentry; it supplies no
cross-thread synchronization. A callback cannot concurrently inspect or mutate
another owner using the same key context. Key module-reference/fallback values
are typed context state, not a reconstruction of the original global module's
entire initialization/shutdown lifecycle.

Credit failure is a fail-closed native error, not an original recovery proof.
The decoder and accepted header-byte count can already be updated when a source
return fails; the actual lease remains held, outer state has not advanced to2,
and further service refuses until explicit `return_held`. That action returns
remaining input credit without rolling back parser state. Healthy admitted
source/lease operations cannot invalidate that token through the public API;
recovery from a corrupted source/callback contract is outside paired equivalence.

Private finite coefficient computation is staged during admission before the
first decoder/key-state write. The pure parser has no callbacks during that
stage; actual coefficient/history/metadata assignment retains source order.
This prevents unsupported FP/profile failures from leaving invented partial
state. Original intermediate FPR/host exception observation is not claimed.

Qualification transports the48 frozen original inputs through the real pure
helpers/math/header-source owner. It compares typed metadata, actual shared-ring
credits, diagnostic observations and helper returns; raw guest pointers are
normalized only to their established role/equality relationships. Stack/register
artifacts, host exception flags and deliberately unsupported partial domains
remain explicit exclusions. Wider math, headers in actual assets, Window
request/total expansion, mutating ADXT loops, clocks and RNA credits remain open.

## Qualification and frozen identity

Both GCC and LLVM pass66 checks, including actual shared-source prefix return,
wrapped54/declared96 selective defer, real lease/source lifetime, diagnostic
ordering and reentry refusal; pure signed/BE metadata/key behavior; ambient FP
mode refusal and exact caller status restoration; and allocation denied across
a whole header service. No service-path allocation or decoder interpreter is
introduced. Standalone CMake/Ninja builds16 units/actions and CTest1/1 passes.

The core/dependencies were frozen honestly after original48-case exposure and
before comparator development, then remained unchanged through comparison:

| Source | SHA-256 |
| --- | --- |
| `adx_header.cpp` | `124147ce7fed57c895c080ece20aae8c8231c67eae07816b481895d4d34f38d4` |
| `adx_header.hpp` | `3a882ddf1e7dd979529c53c9824dcc362d544c3de39304d1d42e0bec44ebfb49` |
| `frozen_identity.json` | `23a0e6fd75654f2ddf95a9076bab5c4faa7fb1588058199f95f750dd84bbe97e` |

The input-only runner passes all48 classifications on both compilers:45 admitted
original projections and three deliberate unsupported-profile controls for the
original unowned120AE8 partials. Full typed decoder/helper/metadata dictionaries,
actual ring counters/totals, key-context values and three diagnostic observations
match; the baseline scalar subset alone contains1152 observations. Full-header
cases use the genuine shared source/DataLease; helper-only cases do not borrow
or fabricate an input transaction. No expected output reaches the C++ runner.
The original projection is written before native compilation/output.

Final receipts, each with retained authored input/native output and compiler,
transport, comparator, fixture and freeze identities:

- `build-native-sjuni/adx-header-native-parity-v2/gcc/receipt.json`, SHA-256
  `859086d461e330cfc0bc6ff6879f23b9d7db65e114cbb0242b8fb83997fbf76f`.
- `build-native-sjuni/adx-header-native-parity-v2/llvm/receipt.json`, SHA-256
  `e887115941f2af9699e005c406c5f856bff0612c2f7e287113d1376ee5af9217`.
- Standalone `build-native-sjuni/adx-header-cmake-gcc/Testing/Temporary/LastTest.log`.

V1 retained a compiler-only transport indentation warning failure. V2 fixes only
that runner formatting; the first executed paired comparison passed with the
frozen core unchanged. Per-compiler final parity evidence is below0.47MB.
