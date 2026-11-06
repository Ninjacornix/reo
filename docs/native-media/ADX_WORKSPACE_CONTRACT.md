# Allocation-free ADX codec workspace contract

Status: approved API/domain, initial implementation frozen before comparator
development, 2026-11-06. This is the codec dependency
of [Window v2](ADX_WINDOW_V2_CONTRACT.md), not a source owner, loop controller,
PCM queue, worker or runtime adapter. Frozen mono/stereo/downmix/control cores
and original oracles remain unchanged. The author has seen their original-word
expectations; any later native freeze must state that exposure honestly.

## API and storage

Namespace `reo::native::adx_workspace`:

```cpp
enum class Route { mono, stereo, downmix_7_over_10 };
struct History { int16_t newest, previous; };
struct State { History left, right; uint16_t key; };
struct Parameters { int16_t coefficient1, coefficient2, multiplier, addend; };
struct PcmOutput { span<int16_t> left, right; };
Admission prepare_into(Route, span<const uint8_t> encoded,
                       int32_t requested_encoded_blocks, PcmOutput) noexcept;
Result execute(Prepared, State initial, Parameters) noexcept;
```

`Admission` has an explicit status and optional privately constructed `Prepared`.
The prepared view records the raw-header marker scan, actual completed prefix,
inspected/consumed byte counts, requested count, route and validated spans. It
performs no allocation, PCM write or state mutation. Unsupported route, excessive
physical span, missing required input, insufficient output or byte overlap
refuses before codec effects. All input/output addresses and byte extents are
checked before inspection; encoded and both output slices must be disjoint.
Downmix still uses two distinct output slices. Mono requires an empty right
slice to avoid an unclaimed output contract.

`execute` has no admission, allocation, I/O, callback, lock or failure result.
It only accepts a prepared stable view, copies small value state into local
histories/key and writes the admitted PCM prefix. The result owns no pointers:
raw signed kernel return, marker side, samples written per plane, completed
blocks/pairs, inspected/consumed encoded bytes, key and selective history-commit
flags/state. It does not publish ring credits or set the predictor odd-result
global. Those remain outside the scalar kernel.

Prepared is a move-only borrowed synchronous view, not a lease/incarnation or storage
owner. Caller storage and bytes remain stable and externally serialized from
admission through execution. No retained callback, asynchronous access or
destructor credit return exists. State/parameters are values; there is no guest
pointer, register file, table-address or runtime dependency. A prepared view may
be moved once into execution while its original input bytes/output slices remain
valid; do not execute a moved-from view. This is a caller precondition, not a
runtime incarnation/duplicate-use detector. It is not a source credit token,
and there is no public default constructor for an invalid view.

## Mechanical bounds

The first physical profile follows the largest approved encoded source and
original PCM storage. Counts below are bytes unless marked samples:

| Storage / work | Bound and derivation |
| --- | --- |
| Encoded physical span | 8,228 = 8,192 capacity + 36 mirror extension. An actual conserved single Source2 data grant is at most 8,192, a stricter owner condition. The codec does not invent those extra 36 valid input bytes. |
| PCM physical plane | 16,576 = 16,384 capacity + 192 extension = 8,288 signed16 samples. A slice beginning inside this plane has only its actual remaining extent. |
| Mono raw physical limit | min(floor(8,228/18), floor(8,288/32)) = 259 ordinary blocks; 4,662 encoded bytes and 8,288 samples. This is a scalar physical ceiling, not a claim the original outer budget requests 259 blocks. |
| Stereo/downmix raw physical limit | min(floor(8,228/36), floor(8,288/32)) = 228 pairs; 8,208 encoded bytes and 7,296 samples per plane. Odd requested count 457 has the same 228 complete pairs but returns 457 on normal completion. |
| Conserved source limit | With at most 8,192 actual bytes, stereo work is at most 227 pairs / 8,172 bytes / 7,264 samples. Apply actual shorter grant/output bounds, not the physical maxima, in Window2. |
| Largest configured request | 2,432 samples = 76 blocks per channel; stereo needs 2,736 encoded bytes and writes 4,864 PCM bytes per plane. Source budget/output position/partial final samples can reduce actual work. |

Original requests 640/1,152/1,216/2,240/2,432 and a 40,017-sample stream must not
be confused with a single scalar call's physical work. The codec holds no stream
total or cumulative counter; future owners preserve long accounting separately.
The physical limits bound scan/execution even when requested count is large.
An earlier marker may admit a large positive request with only its complete
prefix and marker headers present. Do not reject a first mono marker requiring
two bytes or a right stereo marker requiring twenty merely because the nominal
request would require more media. Unmarked missing input still refuses.

## Original arithmetic and selective effects

Mechanical authority is owned File1 ELF
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`:
mono `1276D8`, stereo `127C80`, downmix `1278B8`, selector `127FC8`.
Reuse the reviewed expressions and original-word identities documented in
[mono](../../game/native/adx_block/README.md),
[stereo](../../game/native/adx_stereo/README.md),
[large direct oracle](ADX_LARGE_BLOCK_ORACLE.md), and
[shared original transaction](ADX_SHARED_WINDOW_ORACLE.md).

The implementation is ordinary named C++ expressions: big-endian raw header;
high/low signed nibbles; XOR key then 13-bit scale plus one; signed16 predictor
products widened then explicitly reduced to low32; unsigned low32 sum before
manual arithmetic shift by 12; unsigned-word excitation add; signed clamp;
history shift; low32 key multiply/add then mask to 15 bits. Preserve source
order, including initial unsigned16 keys and signed16 multipliers/addends.
No floating point, host standard-codec library, expected-result lookup or
arithmetic change in frozen code is authorized.

Normal mono completion returns the original signed request and commits its
history pair. A mono marker preserves prefix PCM/key but does not commit the
caller's history pair, even after a nonempty prefix. Nonpositive mono requests
write no PCM and return the exact request with unchanged-value history commit.

Stereo count is divided by two with signed truncation to zero. Normal completion
returns the original request, including positive odd and negative values, and
commits both histories. Left marker returns twice the completed pair prefix.
Right marker advances the left key once before either channel payload of that
pair is decoded; it returns the same even completed prefix and commits neither
history. Prefix PCM/key effects survive either marker. Downmix clips each
channel first, then computes `(7*(left+right))/10` with signed truncation and
final clamp, writing the identical mixed sample into both planes. The temporary
product is bounded by [-458752,458738]. No forced global downmix selection.

## Relation to mutating loops

Storage budgeting must finish before an accepted loop mutation. Actual source
`125370` derives a count from the real post-loop grant and PCM reservation. The
future owner must prove preparation is admitted for its chosen whole domain,
or retain an owned fault if an invariant fails after a mutation. The codec
preparation step can then inspect the actual new marker prefix without
using stale pre-loop input/key/history or simulating a mutating callback.

The codec alone cannot prove the future owner's invariants. If an unexpected
source/provider/ledger condition violates them after loop effects, the owner
retains its ledger and reports an owned invariant fault; it cannot restart the
original call. This API removes late allocation/resource refusal. It does not
claim rollback or make malformed media/foreign storage safe by ignoring bounds.
Source2's canonical shared sample limit must be read by Window2 after the actual
source target action; no independently cached limit is introduced here.

## Qualification plan before integration

Author/freeze implementation and meaningful synthetic units before developing
the new comparator, recording that the author already saw original results.
Then transport authored inputs only through actual native entrypoints. Expected
values remain original-word observations, never frozen native decoder calls.

Reuse the frozen direct mono/stereo/downmix and large-count corpora where they
fit this physical profile; oversized cases become explicit refusal controls,
not truncated successful decodes. Add bounded direct original-word cases for
76-block/channel full requests, exact physical edges, minimal marker inputs,
normal odd/nonpositive counts, clipping, low-word predictor wrap, key overflow
and right-marker partial advancement. Freeze those authored inputs before new
expected replay using unchanged original instruction engines.

Project actual codec-entry state/media from Window1 and Shared39 original
transactions, retaining all original state/marker distinctions. If whole-service
wrap/publication makes isolated-kernel output ambiguous, execute a separate
owned original direct kernel call from the captured input/state; do not guess a
kernel expected result by undoing later effects. Publish the projection and its
exclusions explicitly. Test exact PCM prefix, untouched output suffix/guards,
key/history and raw return, plus precise inspected/consumed extents.

GCC and LLVM checks must include global allocation denial over admission and
execution, insufficient spans and aliases with unchanged output/state, bounded
shift/product edge cases and stable-view execution. Do not link allocating
frozen codec implementations into the qualified workspace or substitute their
results for the original oracle. Source2/Window2 integration, PCM publication,
worker lifetime, actual audio and performance tests remain outside this module.
