# Window2 shared-source composition contract

Status: **design only**, 2026-11-06. No Window2 implementation, composed native
parity, runtime integration, game test or performance result is claimed here.
This refines [the initial proposal](ADX_WINDOW_V2_CONTRACT.md) using the actual
frozen Source2 interface, finite header parser and allocation-free workspace.
No dependency is edited by this design.

## Evidence and current qualification gates

Executable authority is owned File1 `SLUS_207.65`, SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
[Shared39](ADX_SHARED_WINDOW_ORACLE.md) records 39 original transcripts, 35
returned/four explicit cuts; its manifest SHA is
`e41b48940b06b95d5b5641160225e10b0902dd5808d9eaf1dca5b1aa0b127972`.
Those are original-word observations, not Source2 or Window2 native parity.

| Dependency inspected | Identity / proven scope |
| --- | --- |
| `adxt_shared_source/shared_source.hpp` | `cf6b8b7cbc2dff1f619e8f242332cf109ebbad1c810c463f7a3e068967fcf6a9` |
| `adxt_shared_source/shared_source.cpp` | `6327fff621f01afb59506290bf710953f0423b20e46aea58ed2ff99439b55a21` |
| Source2 freeze | `a1eb49209edf71ee13911f556a67be18ae271f658949e2335f33c64fb819f631`; 239 unit assertions plus separate fault/negative checks and real blocked backend retirement checks. The [separate Source-only qualification](ADXT_SHARED_SOURCE_IMPLEMENTATION.md) matches 30 original lifecycle clients /133 records with both compilers; it does not prove composed Window2 behavior. |
| [Finite header](ADX_HEADER_IMPLEMENTATION.md) | Frozen pure parser/math plus Source1-specific HeaderOwner; bundled UCRT LLVM 21.1.8 passes 66 checks/48 original classifications. Only pure helpers/parser are reusable directly with Source2. |
| [Workspace](ADX_WORKSPACE_IMPLEMENTATION.md) | Frozen allocation-free scalar core; bundled UCRT LLVM 21.1.8 passes 284 checks/901 classifications. This proves scalar PCM/state, not a complete window. |

Source2's public `service()` represents **complete `130B78 -> 130800` lifecycle
and refill**. Historical Shared39 calls raw `130800` for its source actions.
The difference is real: public lifecycle service consumes `service_requested`
(`+43`) where a raw refill call can leave it set. Source2's first raw-refill
comparison failure is retained; a new explicit lifecycle-entry source cohort
now matches both compilers. Window2 needs a **new whole-composition original cohort**
using the public lifecycle entry, not flag normalization or relabeling Shared39.
Compare before/after service-request, stop and close consumption as effects.
The [new 133-client original corpus](ADX_WINDOW_V2_ORACLE.md) now provides that
input/replay gate: both compilers agree through6,801,810 instructions, including
the three40,017-sample streams and four explicit partials. Native composed
parity remains unimplemented. Its preserved first lifecycle cohort also shows
why inherited raw-refill error stimuli cannot be relabeled as normal service.

## Owned graph and proposed surface

Use the exact friend class already declared by Source2:
`reo::native::adx_window::v2::StreamWindowOwner`. It receives Source2's single
private `WindowLink` through `take_window_link()`. No other class is granted a
generic mutable loop/state/Ring reference.

| Object | Ownership and authority |
| --- | --- |
| Pipeline construction/binding | Construct exactly one Source2 from the retained immutable ByteView/backend and checked Config. Retain the immutable file-range descriptor used in that construction. It must not be an unverifiable metadata copy attached to an arbitrary Source2. |
| StreamWindowOwner | Strong Source2/control and KeyContext lifetime; private WindowLink; typed header/outer/inner/predictor state; owned PCM ring(s), explicit output-credit ledger and fixed staging. One serialized control domain. |
| Source2 | The only encoded Ring, one producer reservation and one ordered one/two-grant ReadBatch. Provider workers own private results and never mutate loop/decoder/Ring state. |
| WindowLink / LoopDomain | Canonical current loop geometry, sample limit, enable flag, file-target selector and decoder-limit selector. Link alone does not retain the source/backend control owner. |
| ReadBatch | Actual strong storage plus source identity/epoch/batch ID. No automatic credit return or provider join on destruction. |
| PCM owner | One 16,384+192-byte Ring per output channel with real backing, explicit producer and consumer grants. Header PcmGeometry alone is not storage ownership. |
| Encoded/PCM staging | Constructor-budgeted arrays: up to 8,228 encoded physical bytes, 4,096 header bytes and 8,288 signed16 samples per PCM plane. Staging is not a duplicate encoded queue. |

The initial production factory starts a fresh source/PCM graph; it does not
import arbitrary guest pointers or numeric Ring snapshots. A separate authored
test bootstrap may use Source2's real PreparedPrefix construction, including
cursor/progress, and real PCM Get/Put operations. It never initializes state
from an expected snapshot. Source2's actual file extent must be known by the
construction binding: its public snapshot does not expose an immutable extent
getter, and an arbitrary current target cannot be treated as that extent.

Validate constructor parameters, allocate Rings/staging/identity storage and
establish failure cleanup **before taking the one-use WindowLink**. Taking the
link marks Source2 bound and is itself an effect; do not let a later allocation
failure silently lose it and then claim the source can be rebound unchanged.

Proposed operations, not existing declarations:

```cpp
WindowResult service_header() noexcept;
WindowResult configure_ready() noexcept;
WindowResult service_decode(const WindowRequest&) noexcept;
SourceServiceResult service_source() noexcept; // Actual complete Source2 service.
Status set_loop_enabled(bool) noexcept;        // Delegates canonical flag.
Status set_source_paused(uint8_t) noexcept;    // Refill pause, not audio clock pause.
PcmReadResult borrow_pcm(uint32_t channel, int32_t maximum) noexcept;
Status finish_pcm(PcmReadLease&, int32_t consumed) noexcept;
Status stop_decode() noexcept;
RetirementResult retire_on_control_thread() noexcept;
Snapshot snapshot() const noexcept;
```

Source and decode service calls remain explicitly scheduled by the caller; do
not add an implicit source poll to every decode call. This is not one call per
game frame. The first codec service is synchronous, following actual
`12D590 -> 125768 -> 125698 -> 135078`; no extra decoder worker or cancellation
interrupt is invented. Source I/O can already be pending before that call.

WindowRequest identity is a newly owned admission/lifetime policy, not a guest
ABI claim. Validate owner/epoch/request and stop state before effects; IDs must
not wrap or rebind to a different source. All calls, views, callbacks and shared
key-context access are externally serialized. A busy boolean detects reentry,
not cross-thread races. Window2 must have exclusive source-control authority
during a transaction; independent mutable Source2 aliases cannot bypass it from
a notification. Provider workers only produce private results.

## Canonical state and header-to-source synchronization

Never keep an independently mutable Window2 `sample_limit`. Snapshot and budget
reads project the canonical `WindowLink.snapshot().sample_limit`. Source2 may
change it during a separate `service_source()` call, including while I/O or a
batch is outstanding. The decoder-limit and file-target action selectors remain
distinct; first-loop predictor capture is not the source file rewind.

Frozen HeaderOwner is hard-typed to Source1. Window2 needs a concrete Source2
facade around unchanged `adx_header::decode_header` and real ReadBatch finish;
do not cast Source2 into Source1 or create another encoded Ring.

For actual one-grant header admission, Get at most 4,096, copy only actual bytes,
and apply pure parsing in the qualified finite domain. Retain original selective
defer/reject effects. A short actual grant with a larger declared fitting header
can update coefficients/history/metadata and still Unget the full grant and
stay in header state. Successful accepted-header count is stored before credit
return; state2 follows it. AHX diagnostic precedes finish; reject diagnostic
follows full return and precedes state4, as in the qualified header contract.

**Canonical geometry is current parsed geometry, not accepted-header-only
geometry.** Original `133AB8` reads current inner loop-start bytes without an
outer-ready-state check. After any admitted parser result, synchronize its
selectively updated loop fields into WindowLink **before diagnostics or
`finish_batch` guard observations**, preserving the current canonical limit,
target and selectors unless that exact original transition changes them.
The valid update can use current `WindowLink.configure(...)` while Source2 is
idle, even with a held batch or pending I/O. Never write the link from inside
a Source2 busy observer or defer this synchronization until the next tick.

This requires proof that all admitted intermediate geometry is representable.
Frozen Source2 rejects negative/reversed geometry and has no public external
fault/invalidate-action operation. If an unsupported header produces invalid
geometry after a consumed seamless prefix, leaving the old target action armed
is not a safe parity claim. Admission must reject that whole composition domain,
and a reviewed terminal drain/disarm policy is required. A possible owned policy
is to retain the last valid geometry, explicitly disarm both selectors through
the concrete link, then stop/drain the source; that is **new fault policy**, not
original equivalence. It needs its own negative/fence tests and must not be
asserted closed by Source2-only qualification.

The concrete proposed fault-retirement order uses the existing private link:
between serialized source calls, configure the last valid geometry with
`sample_limit=-1`, `target=INT32_MAX`, and both selectors `none`; preserve the
invalid Header state separately. Then call `begin_shutdown`, finish only proven
remaining grants, and service the already accepted provider result before the
actual final join. A private provider worker cannot publish between disarm and
stop. `INT32_MAX` exceeds the admitted physical file-sector extent, so even an
existing read-only target hook cannot run at that target during drain. No new
decode or I/O submission is allowed. Accepted bytes can still publish as part
of draining; this is explicit new fault policy, not rollback or parity.

This sequence applies only when the link is valid and idle and the source
ledger/provider protocol remains sound. A lost token, wrong result identity,
post-credit ledger fault, busy or invalid link can prevent normal retirement;
retain ownership and report the blocked fence rather than declaring success.
Its complete composition/fault tests remain required before implementation
qualification.

## Ready configuration and numeric profile

Initial profile: file-backed tag0, actual source capacity **8,192+36 bytes**,
mono/stereo with 18-byte blocks/32 samples, version3/4 finite header profile,
rates 24/44.1/48 kHz and filter500, supported ambient FP environment, and absent
optional inner `B0` child. Source1's 2/4 KiB evidence does not qualify Source2's
new two-consumer ledger at those capacities.

| Header rate | Non-loop request | Positive-loop-metadata request |
| --- | ---: | ---: |
| 24,000 | 640 | 1,216 |
| 44,100 | 1,152 | 2,240 |
| 48,000 | 1,216 | 2,432 |

Preserve complete `133FE0` request/configuration and `12CC10`'s real helper
effects: inner `B4=request`, `B8=trunc(request/96)`, `C0=request`,
`C4=trunc(request/1536)`. No clipping to256 or resetting at4,096. Long native
qualification must reach40,017 samples on mono/stereo/downmix and cross
4,096/8,192/32,768 through actual repeated windows and publication.

Proposed positive-total domain is at most `INT32_MAX-31` for the original
`remaining+block-1` expression, plus **separate checked bounds for every evolving
counter and branch expression**. This is a proposed proof domain, not existing
large-limit qualification. Before a possible loop effect, budget worst-case
sample increments up to2,432, encoded increments up to2,736 on stereo, loop
counter increments and seamless accumulated-sample updates using wider checked
arithmetic. Recheck exact derived budgets before stores. Reserve all possible
admitted post-loop outcomes, not just the pre-loop limit/history. Counter-limit
refusal must occur before its first original effect; no silent word saturation,
arbitrary counter reset or claim that a signed `INT_MAX` total is safe.

Header loop sample positions must fit the admitted total and ordered positive
loop span; byte geometry and computed source targets must fit the bound file
domain or an explicit supported sentinel. Original `1307A8` accepts arbitrary
nonnegative targets, whereas Source2 intentionally narrows them to extent or
`INT32_MAX`; outside-profile original values remain exclusions. Divisor60 is a
request-sizing parameter, not gameplay speed.

Keep distinct quantities: raw completed encoded blocks, raw codec PCM samples,
`125518` partial-budget-adjusted samples, outer total-clamped publication,
source consumed encoded bytes, accepted file bytes, decoded cumulative samples,
position, sample/encoded progress and seamless accumulator. Do not derive any
clock or consumed-device credit from these counts.

## Ordered transaction and effect boundaries

Each result reports the last completed phase and actual held credits; it does
not label every non-success “no effects.”

| Phase | Concrete required order / observable boundary |
| --- | --- |
| Admission | Validate identity, control scope, geometry/counter/FP domain and full fixed resources. There is no per-service allocation. Before a borrow or loop mutation, refusals can be before-effects. |
| Decoder limit | At actual `12CFD8` limit test, run the concrete canonical selector before the normal input Get. Preserve cached source/inner identities and reload current end flag afterward. |
| First snapshot | `133870`: snapshot actual predictor history/key first; then reset sample progress, set loop-span limit, encoded/source positions and repeat selector. Configured key and snapshot key are different fields. |
| Repeat | `133928`: actual padding Get, short diagnostic if necessary, Put the actual whole padding grant, then reset accounting/position, restore key/history and increment loop count. No Ring reset or file rewind is folded into this action. |
| Input and output grants | Normal input ReadBatch is acquired from the same Source2 Ring. Acquire actual PCM free grants in channel order using the source `12CEB8` contract. The first grant determines the original available/offset fields; do not invent a minimum across channels. |
| Budget and codec | Execute exact `125370` geometry. Copy actual post-loop input into fixed owned scratch; prepare the workspace on these bytes and current value state; move once into execution. No old-input predecode, late vector allocation or fake codec result. |
| Result | Preserve selective PCM/key/history effects, `125518` partial-sample correction and single wrap copy; perform predictor acknowledgement `135048`, default completion `124840`, then inner-ready publication in source order. |
| Encoded publication | At `12D338`, first return consumed encoded prefix and Unget the unread suffix through Source2's real finish plan. This precedes PCM notifications/publication. |
| PCM publication | For each channel: split its actual grant, emit the read-only PCM observation before Put-data, then Put the published prefix and Unget unused free suffix, in order. These operations are not stereo atomic. |
| Counters and acknowledgement | After per-channel publication, update decoded/encoded/position/progress fields with the distinct source counts, then `125278` acknowledgement. No acknowledgement before its required credit effects. |

Source2 service is its own transaction. After a verified completed result, it
publishes the accepted prefix, updates file progress/cumulative bytes and clears
the producer reservation, runs the actual typed file-target action, then reloads
state for terminal checks. Enabled looping rewinds progress; disabled looping
writes canonical decoder limit-1 before source target`INT32_MAX`. Window2 must
observe that mutation, not replay it later. This must retain the physical-end
pair's source-state2 versus3 difference and complete lifecycle flag consumption.

## Seamless two-grant transaction

Use `borrow_batch({two,INT32_MAX,INT32_MAX})`; both actual Gets occur even when
the second returns zero. A pending producer can coexist with both positive
consumer grants. Stable source conservation is:

```text
data + free + entire_held_producer + held_consumer0 + held_consumer1 = 8192
```

Mirror bytes are physical storage, not extra logical credit. Keep grant identity,
order and independent span boundaries. `126F20` parses the first end record;
`126670` searches each source span on its own two-byte alignment and returns
zero on success. Do not concatenate spans to invent a cross-boundary magic.

| Source result | Exact Source2 finish plan |
| --- | --- |
| No next header / invalid end record in admitted safe domain | `restore_reverse`: second Unget, then first. |
| Header found in first | `consume_first_prefix_restore_second`: restore second, consume first prefix, restore first suffix. |
| Header found in second | `consume_second_prefix_consume_first`: consume all first, consume second prefix, restore second suffix. |
| Normal one-grant header/decode | `consume_single_prefix`; zero prefix restores the whole grant through the exact plan. |

Finish preflight validates all dispositions before returning any credit; actual
Ring operations still perform them. Ring.completed is not proof an Unget
restored the expected position. On unexpected post-step failure, retain the
remaining ledger rather than retrying a whole plan.

After successful seamless prefix disposition, accumulate decoded samples into
the seamless accumulator, selectively stop/start the decoder, and attempt actual
header admission once. Rejection/defer preserves consumed-prefix/reset/selective
parse effects and clears seamless enable. Success restores the prior configured
max request, applies the new total limit and clears sample/encoded progress.
Do not rerun all ready configuration or reset source queues. Current header rate
can change without original RNA reconfiguration; preserve that raw decoder
observation and prior ready parameters separately, with no audible clock claim.

Missing magic restores the nested callback's grants; the enclosing input service
then resumes and may consume end-marker/padding. Whole-call rollback is false.

## PCM storage, padding and consumer credit

Window2 owns actual strong storage and real producer/read leases. Read lease
destruction never returns credit; finishing requires the same live owner and
stamp. A notification view may retain storage lifetime but is not a consumption
credit or an immutable historical snapshot. Reads and retention follow the
same serialized control/lifetime contract; no asynchronous raw pointer escapes.

Initially admit matching mono/stereo PCM geometry and explicitly synchronized
channel credit. The original reservation uses the first channel's grant, so
asymmetric grants cannot be “fixed” by taking a minimum. Reject/retain an owned
fault at the appropriate effect phase until asymmetric behavior is qualified.
Downmix still owns/publishes both original output planes.

Raw block output can exceed the final published sample prefix. Preserve original
unpublished padding and wrap/mirror effects for admitted cases; never write
staging directly into bytes belonging to an unread PCM grant. Prove physical
and logical write ownership, including partial final budgets and tail padding,
before copying raw workspace PCM into Ring storage. The new original corpus
covers small non-block-aligned free space with partial final budgets and
asymmetric channels, distinguishing legal extension writes from clobbering
queued data. See its measured total33/free96 and asymmetric64/32 cases. It is a
composition gate, not a proven original bug or permission to truncate codec
output silently. The private workspace alone does not close this issue.
The separate [owned PCM store](ADX_PCM_STORE_IMPLEMENTATION.md) now qualifies
this storage boundary, including90 original partial-tail projections and explicit
credit/lifetime faults. Window2 must still connect it at the actual reserve,
codec, wrap and publication phases; storage-only parity cannot stand in for
whole-owner effect ordering or decoder equivalence.

Stop closes future decode admission while accepted PCM remains drainable.
Frame/presentation/PCM queue counters are not DAC completion. Native RNA/DTR
credit, output-rate authority, drain-silence policy and movie clocks remain
separate owner boundaries.

## Failure, retirement and negative matrix

After any Get, callback, loop mutation, parsed selective write, PCM store or
credit return, failure is an **owned partial transaction**. Keep source batch,
per-channel remaining output grants, current predictor/header/loop state and
last completed disposition in the fault snapshot. Never fall back to the
original routine, reset a Ring, silently roll back accepted PCM, or restart the
whole operation. An explicit full restore is valid only while all its original
ledger portions are still held and the exact plan is valid.

Source2 stop/close retains accepted result publication; do not call backend
cancel at ordinary stop. Explicit control-thread retirement finishes proven
credits, drains accepted work, then requests actual source shutdown/join outside
provider/Ring/guest locks. A lost token or unproven provider/credit fault can
leave normal finalization busy. Keep storage/control alive and report that;
emergency destruction is separate terminal policy, not a fabricated join or a
normal gameplay stop. Shared banks/key context and other streams are not reset.

| Admission / negative case | Required observation or policy |
| --- | --- |
| Five request sizes / all six rate-loop configurations | Exact ready parameters and full2,240/2,432 work; no clipping. |
| Long40,017 and near proposed numeric ceiling | Monotonic distinct counters; no reset; overflow refusal before its first effect. Boundary arithmetic still needs new original cases. |
| Lifecycle versus raw refill | New explicit130B78-entry cohort; compare before/after service-request and stop/close consumption, no normalized fields. |
| Pending full/partial/error provider plus two consumers | Full held producer credit, actual data bytes, ordered plans, no unpublished raw-backing parity claim. |
| Header first/second span, absent magic, short safe end marker | Exact independent searches and ordered restores/discards; no invented concatenation. |
| Negative signed end extent / unqualified math / null file / insufficient-channel diagnostic | Preserve original partial evidence; outside admitted whole-composition profile, never successful parity. |
| Header defer/reject with updated loop fields | Canonical geometry synchronized before finish/diagnostic observations; invalid geometry requires reviewed fault/disarm handling. |
| Source target while loop enable changes | Current enable/header/limit used inside source publication; physical-end enabled/disabled state difference retained. |
| PCM backpressure, wrap, partial final samples | Correct raw-versus-published samples, exact write extents, no writes into unread consumer credit. |
| Asymmetric PCM / invalid output identity | Explicit unsupported/fault phase; no minimum-channel repair or unrelated credit return. |
| Stale/foreign/moved/lost token, ID exhaustion | Before-disposition rejection or retained busy ledger; no destructor credit and no epoch reuse. |
| Allocation failure / unsupported FP environment | Construction/budgeting before link consumption and first mutation; admitted service/codec has no allocation. Unsupported post-loop input keeps an owned fault. |
| Observer reentry / concurrent control access | Reentry refusal; cross-thread unsynchronized use is outside contract. No provider worker touches owner state. |
| Post-first-channel or post-input-credit fault | Earlier accepted effects remain; exact remaining ledger retained; no false whole-plan rollback. |
| Stop/close/join with pending provider or read leases | Accepted publication/drain retained; actual provider fence required, not inferred from stop or payload copy. |

Before composed parity is claimed, close the composition gates above and freeze
the new lifecycle-entry original inputs before observations. Qualification then
needs complete state/PCM/backing/credit/callback order against that cohort,
allocation denial over whole transactions, fault/lifetime controls and both GCC
and the actual bundled UCRT LLVM compiler. A Source2-only match, header match or
901 scalar matches cannot substitute for this whole-owner proof. SJMEM mode2,
LSC replacement, arbitrary math/divisor domains, optional resampler child,
device credits, estimated FP/tick clocks and full native player integration
remain outside the initial contract.
