# Shared-source ADXB window and loop contract proposal

Status: source audit and proposed next qualification boundary, 2026-11-06.
This is not an implemented Window v2, new instruction replay, or player test.
The frozen [Window v1](ADX_WINDOW_IMPLEMENTATION.md),
[encoded refill owner](ADXT_REFILL_IMPLEMENTATION.md), and
[header owner](ADX_HEADER_IMPLEMENTATION.md) remain unchanged. Their successful
qualification does not close the ownership and mutating transitions below.

The next complete unit should own **one shared encoded source, its decoder and
PCM reservations, and concrete loop transitions**. Increasing the old window
limits or wrapping it in repeated calls does not provide that unit.

## Executable evidence

Authority: owned `game_data/SLUS_207.65`, SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Boundaries use `recomp/config/outbreak_ghidra_functions.csv`. Generated comments
from `build-native-sjuni/candidate-work-v6/project/recomp/config/output` were
matched to ELF words; this private directory is an audit companion, not a
production dependency. This pass checked 15 complete intervals: 1,181 unique
commented words and 15 omitted zero words, with no missing nonzero word.
Exclusive ends and SHA-256 identities:

| Interval | SHA-256 |
| --- | --- |
| `125370..125458` request geometry | `da81bada36321a3c952587f5a35920e5d366e209591bdd952ad886b37b552bd8` |
| `125518..125698` result/wrap | `6453e1065ab63946b3b6b7a850f1a5cd97d38a96a3fc18e42709b020617092b4` |
| `126670..1266F0` aligned header scanner | `e4b95836ee5776bd904db25347c8051b50e711b676337208230267ec574b32c6` |
| `126F20..126F7C` end-record parser | `10e91f575a9021b7b7ae2107a341d34b8c3570f48708a9b7c9372ec7d3f235f2` |
| `12C9A0..12C9D4` outer reset fields | `e47f91881fa0efda04e085bf1a2b70699e9ce62123f212d2c79488e44fda733c` |
| `12CC80..12CCAC` start header state | `b2e753c41592a5f9876b42739ab73b1f31f51e65ff6bc8e5cdd1f2b4ac07833d` |
| `12CCB0..12CCDC` decoder stop | `2403a7031dfc4dd979d1db714f6aa23774b634efb53a1e07403089c8f874af6d` |
| `12CFD8..12D334` limit callback/input admission | `f659e94d5dc34ea79887c5ab155afbb646258d00b2e36ac72e711e6a9ce647c7` |
| `12D338..12D4FC` publication | `003927f1732877ad02c642fb4ee8668112a3650d4f83e92b3d898e732c3e5645` |
| `1305C0..130608` file progress setter | `ffee783f461feea4cde905f116b1917e15debbed7a274b46b96d6bc2d711cd4c` |
| `133870..133928` first loop snapshot | `0ffe62c1fce3b6b9f9a6c1e28d9562e165f499e7bef5d8b48774004ceec99af0` |
| `133928..133AB8` repeat decoder transition | `808a21d5d0e345a300aa1491a91e5a02eab1d5be56a49e6ecd1b572bbb07dc9a` |
| `133AB8..133B44` file loop target transition | `8795909b800260824798784f9417c1912bf155df5da09c62e4cc5d581037b6f0` |
| `133D10..133FDC` seamless transition | `eec7d5e82acdfb97295123152a554981f3118fe41551d6a0089c29a25df81022` |
| `133FE0..1343B8` ready configuration | `f9941b835b679c4b519c42abc05d1d83674bb0c9899242d5277110bc48ca87da` |

Reuse the field/caller evidence in
[remaining player ownership](ADXT_PLAYER_OWNER_NEXT.md),
[request/result arithmetic](../SYMBOLS_ADXB_DECODE_WINDOW_AND_WRAP_ACCOUNTING.md),
[loop queries](../SYMBOLS_ADXT_LOOP_METADATA_AND_AINF_QUERIES.md), and
[header/loop transitions](../SYMBOLS_ADXT_HEADER_LOOP_AND_DRAIN_TRANSITIONS.md).
The earlier owner inventory predates the subsequent bounded finite
[header math qualification](ADX_HEADER_MATH_ORACLE.md); its historical floating
point blocker is now closed only for that documented finite domain.

## Real request domain

Initializer `12A1E8` calls `1328A8(60)`; constructor `1315E0` copies that global
divisor into ADXT `+38`. At `133FE0`, for positive sample rate `R`, divisor `D`,
and block samples `B`, the actual signed-word sequence computes:

```text
q = trunc(R / D)
raw = loop_metadata_positive ? 3*q : trunc(3*q / 2)
request = trunc((raw + 2*B) / (2*B)) * (2*B)
```

The added quantum is literal: an already aligned raw value gains a quantum.
Overflow and division BREAK behavior are not represented by mathematical
unbounded integers. The first proposed profile fixes `D=60`, `B=32`, and the
already qualified header rates:

| Rate | No loop metadata | Positive loop metadata |
| --- | ---: | ---: |
| 24,000 | 640 samples | 1,216 samples |
| 44,100 | 1,152 samples | 2,240 samples |
| 48,000 | 1,216 samples | 2,432 samples |

These six configurations have five distinct request sizes. They are static
source-derived values, not new runtime observations or gameplay frame rates.
The frozen window admits at most 256 requested samples and 4,096 total samples.
It also uses synthetic fixture coefficients; the new owner must consume actual
typed header coefficients/history/key, not inherit those fixture defaults.

The first new domain should include long finite streams and repeated loops;
all evolving word arithmetic and physical extents still need qualification.
Do not assert `INT_MAX` totals are safe: expressions such as `R+B-1`, cumulative
encoded bytes, and loop accumulation have independent signed/wrapped behavior.
Choose and publish the final numeric upper bound after complete original
transactions establish it. Tests must actually cross 4,096 and 8,192 samples.

PCM storage remains 16,384 bytes plus 192 mirror bytes per channel. Encoded
storage remains one sector-sized ring with 36 mirror bytes; start with the
already qualified 2/4/8 KiB capacities. A small encoded grant legitimately
reduces actual admitted codec work; it does not redefine the configured request.
`125370` uses copied working capacity while `125518` wraps against original
capacity, and the latter performs one wrap copy. Their complete geometry,
partial-budget adjustment, marker return and publication need one proof.

## Observable loop order that the owner must preserve

`12CFD8` loads inner/source identities before checking the sample limit. It
invokes the installed limit callback at `12D024` before its normal input Get,
then reloads the end flag. The callback may have consumed input or changed
decoder limits, counters, key/history and header state. It is not a read-only
notification. Source identities cached by the enclosing call must remain valid.

`133870` queries loop start/end positions, snapshots predictor history and key
through `12DA38/124F70`, then resets sample progress, installs the sample span,
sets encoded progress and source sample position, and installs `133928`.
Snapshot history/key fields are distinct from configured key material.

`133928` obtains the actual padding grant and reports a short-grant diagnostic
before returning the entire actual grant to free space. A short grant does not
abort the later accounting changes. It resets progress and source position,
installs the loop span, and restores history/key through `12DA50/124FB0` before
incrementing the loop count. Its mode2 path additionally resets SJMEM and
discards a loop-start prefix; that is not a file-ring rewind. With no file and
loop flag disabled it only removes the sample limit and returns.

File rewind is independently `133AB8 -> 1305C0`. It changes the logical file
progress field `+54`, clamping an overlarge sector request to the source extent;
it does not reset queued encoded bytes, predictor state, or cumulative accepted
bytes. Disabled looping installs an unbounded file target and removes the
decoder limit. The actual `130800` target callback occurs after accepted-prefix
publication/progress updates and reservation clearing, but before later terminal
checks reload state. Replacing this with a deferred generic notification changes
the observed state and branch decisions.

Seamless `133D10` takes two actual data grants before parsing. `126F20` requires
at least 16 bytes and an `8001` record, returning its length in a signed halfword.
`126670` searches two-byte aligned `8000` magic and returns **zero on success**,
with an offset stored as a halfword; missing magic returns `-1`. The new domain
must reject malformed/negative derived extents before unsafe native access,
while preserving original evidence for those excluded cases.

If neither span has a next header, both grants are Unget in reverse order and
seamless enable is cleared. If found in the first span, the second is Unget,
then the first prefix is freed and its suffix Unget. If found in the second,
the entire first is freed, then the second prefix is freed and suffix Unget.
It accumulates decoded samples into ADXT `+A4`, stops/starts ADXB, and executes
header admission once. A header failure/defer clears seamless enable; consumed
prefix and reset effects are not rolled back. Success restores max request and
sample limit and resets sample/encoded progress. Decoder stop/start selectively
resets fields; it is not a whole-object or ring clear.

## Proposed typed ownership and API

Introduce new versions rather than altering frozen Source1/Window1/HeaderOwner1.
Names below are a review proposal, not existing public declarations.

| Owner/API | Responsibility |
| --- | --- |
| `SharedEncodedSource` | One actual SJRB ring, one retained producer grant/provider result, and a bounded ledger of up to two consumer grants. Reuse unchanged AsyncReadOwner/SerialWorker backend semantics and private result staging. No second encoded ring or mutable Ring/backing escape. |
| `ReadBatch` | Move-only strong storage/owner/incarnation token holding one or two ordered grants. Read/copy access only; destructor returns no credit. An outstanding producer may coexist. Validate conservation including every held grant. |
| `finish_batch(plan)` | Exact ordered plans: reverse restore; first-prefix consume after second restore; or whole-first plus second-prefix consume. Prevalidate token identity, counts, order and resources before the first disposition. An unexpected credit failure retains the remaining ledger and faults admission; it never restarts original code. |
| `StreamWindowOwner` | Shared source handle, typed decoder/header/loop state, actual owned PCM queues, fixed codec workspace, request epoch, and completed-frame accounting. All mutations and snapshot callbacks are in one externally serialized domain. |
| `LoopPolicy` | Concrete owned `none`, `first_snapshot`, `file_repeat`, or `seamless` transition. Source target transition is an internal owned action at the actual refill boundary, not arbitrary mutating user reentry. |
| `service_decode(request)` | Execute source-order loop action, acquire real input/PCM grants, decode with preallocated workspace, copy wrap, publish exact prefixes, then acknowledge. Expose inactive/backpressure/unsupported/fault outcomes without a post-effect fallback. |
| `service_source()` | Progress the same source and execute its typed target action at publication. Preserve the distinction between file progress, accepted byte count and decoder position. |
| `consume_pcm(channel, n)` | Explicit queue credit only. Accepted output may drain after stop; it is not a DAC/time claim. |
| `stop`, `request_close`, `finalize_join` | Separate decode admission, normal accepted-I/O publication/drain, and actual provider completion/join. Do not clear other streams, accepted PCM, shared banks or key context. |

Source1 admits one consumer only, has no source-progress mutation API, and its
target hook is read-only/nonreentrant. `reset_quiescent` requires stopped,
drained, unborrowed state. None of those APIs can stand in for these loop actions.
Source2 needs a new qualified ledger and target transition; it must not expose
arbitrary progress mutation to callers. Do not call Source1's private state
through a cast or copy its queued data into an unrelated ring.

The pure qualified header parser can be reused unchanged. A new shared-source
header facade must express two-span disposal and the real stop/start/header
sequence; frozen HeaderOwner1 is hard-typed to Source1 and remains unchanged.
The first profile excludes SJMEM mode2 restart until its different reset/borrow
lifetime is separately proven. File-backed repeat and same-source seamless
transition are the proposed initial closures. LSC filename replacement remains
outside this unit.

## Allocation, arithmetic and admission gates

The existing mono/stereo kernels return allocating vectors. Window1 stages
their output before its read-only limit callback and first real borrow. That
cannot be reused unchanged when a loop changes history and input before decode.
Predecoding the old input, replaying a simulated callback later, or falling back
after loop effects would be incorrect.

Propose a separately qualified `decode_into` workspace interface in a new module
or explicitly reviewed kernel version. It must use the proven scalar arithmetic
and marker/key/history ordering, with caller-owned bounded encoded/PCM storage,
no allocation or failure after accepted mutation, and no guessed codec output.
Do not modify frozen kernels before this interface and its original-word parity
plan are approved. Constructor allocations cover maximum physical ring spans,
two-span header staging, per-channel PCM workspace and every ledger slot.
The final workspace byte/sample bounds must be proved from actual geometry,
not guessed from requested samples. Allocation denial must cover entire service
and loop transitions, not only the scalar codec call.

Admission includes supported typed header domain and ambient FP policy, actual
ring geometry, ordered positive loop extents, checked file-sector bounds,
source/decoder incarnation, complete ledger, and supported counters. Ambient
FP state is not silently changed. Unknown metadata/math/domain is unsupported;
after a real borrow or loop effect, this is an explicit owned result/retained
ledger, not a before-effects original fallback. Loss of a lease token must keep
the owner busy rather than silently returning storage credits from a destructor.
Reset/reuse still requires actual retirement proof; stop is not a worker fence.

## Required new original-execution corpus before native implementation

Freeze authored transcripts before expected observations. Reuse unchanged owned
ELF engines and real SJRB/header/math/predictor words. Keep expected generation
independent of new native code; bounded guard, diagnostics, provider I/O and
unowned RNA/device edges may be explicit hooks, never codec/ring/loop results.

| Cohort | Complete source boundary and required controls |
| --- | --- |
| Ready/request setup | Full `133FE0` with actual getters/setters and metadata, all six rate/loop profiles; complete unchanged admitted RNA facades until explicitly external edges. Cover not-ready return, insufficient channel capability, file/null target and optional extension branches. Do not replace the whole setup by the request formula. |
| Long shared windows | Actual outer dispatch/admission/reserve, `125370`, `135078` plus actual mono/stereo/downmix kernels, `125518`, `12D338`. Use full requests, non-block-aligned end totals, several windows crossing 4,096/8,192/32,768 samples, physical wrap, partial output credit, marker-after-prefix and odd stereo marker results. |
| Producer and consumers | Actual `130800` request/accepted-prefix service interleaved with decode. Preserve legitimate `data+free<capacity`, pending/partial/error completion, and producer grant concurrent with both consumer grants. Record full ledger and exact callback order. |
| File repeat | Actual `12CFD8 -> 133870 -> 133928`, snapshot/restore bodies, real padding Get/Put, plus actual `130800 -> 133AB8 -> 1305C0` publication/rewind path. Exercise first versus repeated loop, non-sector loop offsets, zero/full/short padding diagnostic, loop disabling, and target callback changing a later terminal decision. |
| Seamless next header | Complete `133D10`, `126F20`, `126670`, real two-grant SJRB disposal, stop/start, and actual qualified header/math chain. Header in first/second span, empty second span, neither found, short/invalid end record, reject/defer after prefix consumption, wrapped fitting header, key/history replacement and final continued decode. |
| Negative controls | Malformed signed lengths, arithmetic/extent limits, excluded SJMEM reset, source replacement/stop with held grants, duplicate/foreign tokens, reentry and allocation/provider faults. Original unsafe behavior stays labeled evidence; newly owned rejection/fencing policy is not original equivalence. |

Start with roughly 40–60 bounded transcripts across these families, then expand
when actual branches require it. This is a coverage proposal, not a promised
case count or completed proof. Persist compact state/delta/backing evidence and
whole-RAM hashes where useful; do not create per-case 32 MiB dumps. Record exact
source function/table identities, reached/unreached branches, hooks, partial
executions and instruction counts. A failed or unowned path remains explicit.

Once this original boundary is closed, author/freeze the new native owners
honestly after source-oracle exposure, then develop inputs-only transport and
GCC/LLVM parity plus lifetime/credit/fault tests. Full ADXT player clocks, RNA/DTR
credits, LSC replacement and runtime default enable remain separate stages. This
proposal makes no performance or stutter-fix claim.
