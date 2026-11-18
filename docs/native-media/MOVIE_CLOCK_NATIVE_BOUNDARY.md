# Original movie clock authority and the next native boundary

2026-11-05. Offline File #1 investigation. Only this document was added: no game,
build, process attachment, native implementation, or original-instruction replay
was performed. The owned ELF is `game_data/SLUS_207.65`, SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Statements below distinguish reviewed instruction behavior, proposed interfaces,
and missing evidence.

**The native GPU movie decoder does not own movie playback time.** Existing
`LiveMovieProducer`/`SameOwnerMovieBridge` own native MPEG parsing, hardware decode,
resident images and real consumer fences. Original File #1 code still selects
the clock, publishes positions, starts/pauses components, admits/skips pictures,
and returns frames. Native PCM extraction alone does not replace that authority.

The smallest next closed typed cut is **complete picture-position publication
at `16F338`**, including its real side-input getters and exact product/quotient
semantics. It is smaller and more independently provable than replacing the
whole start/pause/clock/due controller. It does not claim to resolve the measured
stutter or make an independent native movie player. Full controller replacement
requires the additional source, audio-filter, callback and EE floating-point
closure described below.

## Remaining control and clock graph

Offsets are hexadecimal unless stated otherwise. Numeric state/property values
remain literal where original public enum names are not recovered.

| Authority | Reviewed original chain and behavior | Native replacement obligation |
| --- | --- | --- |
| Start request and completion | `15EFB8` prepares source/timing state; `15BFA8→1740A0` starts the supplied source descriptor. `15EE88→173A70` chooses requested3 if property2F is exactly1, otherwise requested4, then sets pending44. It does not assign actual48. `1725E0` and state2/3 handlers wait for component readiness before command6 to component7 and actual4. | Separate requested, actual, pending and provider readiness. A native file open, parsed header or decoded frame is not start completion. |
| Clock initialization | `175A50` initializes callback slots, six rational histories, windows, sentinels, counters and prediction state; it does not sample a clock. `173C70` reconstructs the main object during stop/reuse and restores properties after constructor callbacks. | Preserve reset timing and callback ordering. Retaining the same decoder address or ADXT handle does not preserve every old clock/filter state. |
| Tick source | `163EE0→172480→175D98` advances global22F138 and at most8 registered contexts; `175E00→175E50` advances eligible counters. Counter264 advances only actual4/pause50==0/bufferpause964==0; counter288 independently advances when initialized and requested4. `175E00` refreshes cache only if property47 is exactly1. | Supply the actual admitted tick event and original increment268; do not substitute elapsed host time, display FPS or actor callbacks. Invocation frequency/accuracy is not established as a game-update count. |
| Selection and cache | `176350` returns cached248/24C unless numerator==-5; cache miss uses `176418`. PropertyF selects a callback under optional tag1 hooks; missing slot uses1764B0. `176930` refreshes, rebases elapsed state only when pair changes, stores pair, always sets pending44 and ignores query status. | Preserve cache misses, sentinels, in/out writes, raw callback status and side-effect order. Do not initialize an untouched output to a guessed clock value or drop a sample solely because its status is nonzero. |
| Built-in and external clocks | Slots initially0=1764B0,1=1764F8,2=NULL,3=176558,4=NULL,5=176578. `176670` admits actual4,-4,6,-6. Slot0 gives-2/1 for eligible states, ineligible gives-1/1. Slot1 gives counter264/global22F140. Eligible slot3 leaves output words untouched. Slot5 invokes external290 and conditionally accumulates sample delta into298. | These are different contracts. A native interface needs raw rational bits, write masks and status, not a mandatory valid timestamp. Slot4 and external callbacks require registered-provider lifetime/reentry evidence. |
| Audio clock | Audio creation `165778→165B08` installs slot2=165B48 and selects propertyF2. `165B48` queries only in actual4, retaining the signed-maximum cached child24/28; other admitted states return the cache. `165C08` joins ADXT132160 and original counter17E870/frequency17E998 through177EB0. | Preserve ADXT queue position, estimator/filter state, pause policy and real callback route. A PCM callback's rendered-frame count is not automatically this selected clock. |
| Explicit/nested pause and resume | Public `15F3F0` stores player byte72 after its delegates and optional MWSST notification. `1720C8` stores raw pause50, derives transition0/1/2, invokes172158 and sets pending. `172158` increments/decrements nesting54 for1/0, emitting only at depth1/0; mode2 emits only in actual4. `1721E8` requires requested3/4, calls176D08 then component7 command8. Only mode2 applies the frame-ratio increment. | Distinguish explicit request, nesting depth, provider pause, and player byte. No boolean normalization, clamped depth, automatic host sleep or new resume tick. Preserve integer wrap and exact-one versus nonzero gates. |
| Buffering pause | `172C48` separately toggles964 and counts episodes968, reusing nested transition1/0. Pause/resume predicates172CF8/172E78 compare cached clock against latestF00/F04 with DIFFERENT margin properties44/45 and different positive-numerator admission. Refill/end predicates can also resume. | A decoded queue low-water mark cannot replace original predicates without the full enabled-stream, component, EOF and SJ occupancy contract. |
| Picture position | `16EC90` requests/receives original picture work, then `16F338` publishes metadata and conditionally raises latestF00/F04. `176210` separately adds selected-clock offset subject to denominator and DA4 rules. | Keep latest decoded-position metadata, selected playback clock and public position distinct. F00/F04 is not a picture counter or physical presentation timestamp. |
| Due/admission and skip | `176F30/176F68→1770F0`, `177028`, `177240`, `1772B8` use cache, margins, properties and stateful hysteresis. `178F58` admits an output picture; `170848` tests the second ready picture for public skipping; `16E9B8` separately decides late compressed-picture skip, with optional callback atCD8. `178E10→1773A8` gates initial/baseline output. | Preserve distinct propertyE bypass policies and independent skip/admit paths. Successful GPU decode is not permission to publish/drop a picture. |
| Stop/end/rebuild | `173130` combines configured end ratio, component completion, elapsed limit and position limit. `1733C0/173C10` can leave actual1/requested6. `173B80` optionally stops and reconstructs under temporary global reuse1, then forces reuse0. Public15F388 additionally unlinks/resets input. | Keep component completion, pending callbacks, original frame returns and retained native-image lifetimes separate. A cleared state or returned stop call is not general worker/fence completion. |

Primary reviewed notebooks:
[selection/clocks](../SYMBOLS_MOVIE_CLOCKS_AND_TIMECODES.md),
[defaults/ticks](../SYMBOLS_SOFDEC_CLOCK_DEFAULTS_TICKS_AND_ELAPSED_LIMIT.md),
[start/state service](../SYMBOLS_SOFDEC_PENDING_SERVICE_AND_PLAYER_STATE_TRANSITIONS.md),
[pause](../SYMBOLS_SOFDEC_PAUSE_STANDBY_AND_STREAM_SELECTION_APIS.md),
[buffering/end](../SYMBOLS_SOFDEC_BUFFERING_PAUSE_REFILL_AND_COMPLETION.md),
[due/hysteresis](../SYMBOLS_SOFDEC_CLOCK_FRAME_STEP_RATE_AND_PICTURE_ADMISSION.md),
[source/public controls](../SYMBOLS_MOVIE_SOURCE_PAUSE_AND_SCRATCH.md),
[rebuild](../SYMBOLS_SOFDEC_PLAYER_DESTROY_START_AND_REBUILD.md).

## State that cannot be collapsed into one native timestamp

| Original location | Exact role / reset distinction |
| --- | --- |
| Main44,48,4C,50,54 | Pending work; actual state; requested state; raw explicit pause; nested pause count. Independent fields. `1725E0` clears pending before calling providers, reloads actual after its prepass, then writes the handler result. Reentrant callbacks can reschedule pending or change actual. |
| Main964/968/96C | Buffering pause, pause episode count, video stalled flag; separate from explicit pause. |
| Main9A0/B30 property arrays | Current/saved properties. Public175338 uses provider admission175500 before current/saved writes; direct175460 only updates current on admission.175628 is an unchecked load. Property setters are not generic unconditional assignments. |
| MainCC0+0..18 | Clock callbacks0..5 and late-picture callback at18 (mainCD8). Registration stores addresses; it does not prove native provider lifetime or invoke them. |
| CC0+238/23C,240/244,248/24C,250/... | Separate rational records initialized with-5 sentinels.240/244 is latest picture position (mainF00/F04);248/24C is selected cached time (mainF08/F0C). The other cache roles must remain source-labelled until their writers are joined. |
| CC0+260/264/268 | Requested clock-step count, running counter, increment; constructor sets264=0,268=1000decimal. Global22F140 is supplied by global initialization/configuration, not hard-coded60Hz. |
| CC0+26C/270/274 | Requested picture sequence and raw numerator/denominator, published by176FA0; not immediate presentation. |
| CC0+278/27C/280/284/288 | Stateful hysteresis count, tracked query, cached decision, previous query, auxiliary counter. Negative288 admission can initialize it to0. |
| CC0+28C/290/294/298/29C | Elapsed baseline, external callback, previous external sample(-5 initially), accumulated external value, external denominator. Registering/unregistering176808 does not locally reset all history. |
| MainD74/D78,DC4,DE0,DDC | Header-derived numerator/scale, origin, bias, side-input base. Their literal arithmetic and update order remain relevant even when video pixels are native. |
| Audio child24/28,2C,30,34,38; mainF60 filter | Cached audio pair, requested pause, residual, shared-metadata-applied flag, sample correction, independent time-filter state. These are not one PCM cursor. |

Original handle validation169E30 accepts any nonzero state, including negative
error states, and stores the last candidate pointer. It is not a generation or
pool-membership proof. The original8-slot registry and borrowed ADXT reuse handle
have no new native lifetime token. A future `MovieKey{session,generation}` and
separate timeline epoch must be adapter-owned, tied to confirmed source/start/
rebuild/discontinuity events. Do not mint an epoch from every clock query, GOP or
backward rational value. Exact seek/loop/reset admission still needs the joined
source/frame-return lifecycle; existing native GPU generation and GS epoch are
not interchangeable with a clock reset.

## Concrete next complete typed contract: picture-position publication

Proposed standalone operation, not implemented here:

`publish_picture_position(PicturePositionInput, LatestPosition) -> PicturePositionWrites`

It owns all branches and selective writes of `16F338`. Typed inputs carry raw
signed32 header numeratorD74/scaleD78, originDC4, biasDE0, old latestF00/F04,
side-input enabled observation, side counter/baseDDC and picture rate code3C.
The real getters are tiny:171530 reads main1B30→child9D8 and tests nonzero;
171E58 reads the same child→A08. They need no timer, callback, OS, GPU or device.
An adapter must obtain these actual values from its owned source state, rather
than fabricate counters. A native-only caller supplies the same explicit typed
observations from its source owner.

Exact output contract:

1. Always write descriptor10=scale, C=wrap32(header-origin+bias),20=header,
   24=wrap32(header+bias), in original order.
2. If side input is enabled, compute delta=wrap32(counter-base), then the second
   multiplier as wrap32(1000decimal*delta). `15BA80(scale,multiplier,rate)` forms
   a signed32×signed32 product, performs the original signed64 quotient, then
   narrows/sign-extends low32. Write20=that result, then C/24=result+bias modulo32.
   Rate is the owned table240AF0[picture3C], not an invented host frame period.
3. Only when descriptorC is signed-greater than old latest numerator, write
   latestF00=C andF04=descriptor10. Equality/decrease preserves BOTH old words,
   even if the scale changed. This is not a rational maximum and must not become
   one through a generic rational-time library.
4. Return a selective write/result structure, including whether latest changed.
   Original16F338 has no documented normalized public success return; its raw
   scratch v0 must not be promoted to a native success API or used as new policy.

The initial native admission profile should require an owned live generation,
properly bounded/disjoint original context/descriptor spans, and, when side
input is enabled, a rate index inside the owned nine-word table. Out-of-profile
pointer alias/index cases retain original selection until proven; do not mutate
RAM and then retry original. The typed core has no guest pointers, runtime,
virtual source, audio device, clock callback or global singleton. Preserve raw
wrap/compare semantics independently of whether a host considers those rational
values sensible. This boundary closes publication arithmetic, not timestamp
derivation16D8A0/16DB20/16F230 or subsequent due/return authority.

Independent acceptance corpus before integration should cover side input on/off,
all9 owned rates, equal/decreasing/increasing latest values, scale changes without
latest update, signed boundaries, wrapped delta*1000 and wrapped offset/bias,
negative quotient truncation, unchanged guard bytes and exact descriptor/latest
write masks. Freeze original-word expected outputs before comparing a new core.
Original getters, ratio helper and quotient body must execute, not be replaced by
hooks returning expected arithmetic. This is a feasible research cut, not a
claim that its roughly62 described instructions are a measured performance cost.

## Can the existing EE oracle prove it without fake hooks?

**Some scalar clock slices fit unchanged instruction support; the full proposed
publisher and due controller do not yet.** This was established by static opcode
and dependency inspection, not by executing them in this investigation.

| Candidate slice | Current bounded-engine feasibility |
| --- | --- |
|175EC0,175EF8,176670,175628,1769B0; complete175E50 with real predicate children;175F20 with real175628 | Integer loads/stores, branches, additions and real owned child bodies fit the existing SJUNI lower64 instruction engine. They need a dedicated bounded range/call runner and synthetic memory/state snapshots, not device hooks.175EF8 specifically receives BOTH main a0 and clock-block a1. |
|16F338 with side input disabled, including real171530 | No arithmetic-service hook is needed on this path. It is only a branch-specific result, not complete function/domain proof. |
|Complete16F338→171530/171E58→15BA80→10FB18 | Existing `EeMacInstructions` supports primary/secondary multiply and HI/LO moves, but lower64 engine lacks required DSLL32/DSRL32/DSRA32;10FB18 additionally needs variable word shifts and DIVU. The stereo mixin adds signedDIV only. Explicit BREAK/undefined-operation admission also needs an honest policy. No full closure exists merely because the math resembles a host division. |
|1501E8 rational cross-product comparator | Both MAC banks already have support, but DSLL32/DSRL32 are still required. Complete comparator corpus can follow independently tested generic instruction additions. |
|176350 cache-hit /176418 arbitrary selection | Cache hit is an integer subset. Cache miss executes optional guard hooks, property selection and arbitrary registered callback. A fully declared real provider or explicit callback request/response boundary is required; replacing it with a constant-clock hook is not full clock proof. |
|1770F0/1772B8 due/hysteresis | Reach EE single-precision conversions/arithmetic/comparison and exact equality/NaN branches; existing integer/MAC/DIV engines do not model that FPU contract. A Python float or host-double rewrite would not independently establish original parity. |
|165C08/177EB0 audio filter chain | Also depends on ADXT estimator, actual hardware-counter input and64-bit product/division/filter/history semantics. Treat external samples as declared inputs only at an explicit cut, not as proof the complete source/filter ran. |

Engine files inspected: `sjuni_oracle.py` SHA-256
`9d71114ffb0d8b2826012517c8d381d5ba2cdb5dd602c1f48e12450d99697d95`,
`ee_mac_oracle.py` SHA-256
`0466ee2828bcc268deafbb9ed93d8e7096cd0b89fa0ed489af28cae0120128cd`,
`adx_stereo_oracle.py` SHA-256
`f66047d0ee59114cdf80d5d1e1bb4833aa566b35c9a7dea7e9d24930ad428c17`.
Their existing bounded entry runners do not admit arbitrary movie addresses.
Extend/combine generic instruction support with independent microtests and a new
owned-body runner; do not alter old frozen corpora, teleport loops or substitute
15BA80/10FB18 numerical answers. See
[ratio helper semantics](../SYMBOLS_MWSFD_INTEGER_PRODUCT_RATIO_HELPERS.md) and
[64-bit quotient review](../SYMBOLS_RESIDENT_64BIT_DIVISION.md).

## What closes the wider controller after that cut

A later typed `MovieClockPolicy` needs raw rational pairs plus output-write masks,
literal actual/requested/pause/buffering/pending fields, selected source IDs,
all cache/accumulator/hysteresis records, configured increments/rates/margins and
timeline identity. Distinct commands are initialize, source/start request,
service tick, explicit/nested/buffering pause transition, selected sample/cache
refresh, position publication, picture due/skip request and stop/rebuild. Its
result must distinguish a request from completion and expose selective effects.

Guard entry/leave, provider sampling, property admission, component commands,
error notifications and source/frame ownership remain explicit ordered ports
until independently native. They are not no-ops. `176418` selects under optional
tag1 hooks; `176578` checks running state after its external callback, so a native
continuation must re-observe callback-mutated state. `176930` may consume output
scratch words a callback left untouched; model in/out values/write masks, not
uninitialized C++ locals. `1725E0` reloads actual after callbacks. Original error
callbacks can run before169C10 negates positive actual state. A transaction that
blindly writes an old full snapshot after such calls would erase real effects.

The [guard chain](../SYMBOLS_SOFDEC_GLOBAL_LIFECYCLE_ERROR_RECORDS_AND_CRITICAL_SECTIONS.md)
is optional registered tag hooks, not guaranteed mutexes or interrupt save/
restore. Original numeric functions can be preempted in the cooperative runtime;
existing GPU numerical continuations preserve context/stack/RA, release guest
execution while waiting on real owner requests, and resume original controllers.
A new adapter must preserve the chosen call boundary's reentry/return order and
real ownership. Native clock arithmetic is not permission to move component
callbacks onto an arbitrary worker or replace original waiting with a host timer.

Audio closure specifically requires
[ADXT132028/132160](../SYMBOLS_ADXT_SAMPLE_POSITION_AND_ESTIMATED_CLOCK.md): decoded
samples minus RNA occupancy and output queue, offsets/base, optional service-tick
estimate and drift rebase. Tick20F3C4 has interrupt AND public-service producers;
it is not proven a fixed-frequency display count. Sofdec then joins that result
with17E870/17E998 through the
[177EB0 filter](../SYMBOLS_SOFDEC_AUDIO_TIME_FILTER_AND_CSV_MEMORY.md), with anchored
prediction, exact pause/mode gates, history and raw-output clamp. The
[audio slot2/cache](../SYMBOLS_SOFDEC_AUDIO_CREATION_PAUSE_AND_CLOCK_CACHE.md) and
[original hardware-counter extension](../SYMBOLS_SOFDEC_HARDWARE_COUNTER_CLOCK_AND_UNIT_CONVERSION.md)
must remain separate. The current typed PCM core or a device's consumed-frame
counter supplies useful observations, but neither alone is that filtered clock.

## Owned-source audit for this boundary

Reference generated bodies were read from
`build-native-sjuni/candidate-work-v6/project/recomp/config/output/`.19 selected
bodies had1086 distinct instruction comments matching owned ELF words;13 omitted
aligned words were zero, with no omitted nonzero words or comment mismatches.
This verifies source-word identity, not runtime or numerical parity. Raw hashes
below cover catalogue `[start,end)` bytes, including omitted zero alignment.

| Owned interval | SHA-256 |
| --- | --- |
|16F338..16F434|`a9da933b0444e36ca9216439b9987a8c43b35329f1a8018707f1760a43940747`|
|171530..171540|`fe86d348b236afbb16ed45b2d5206cf8b37db1ce50cd27246e3da791ec753591`|
|171E58..171E64|`520d116b70df02845b4cf1f537ef3f05d6c8133d5189643ff392dfc7aae8dd0f`|
|15BA80..15BAEC|`10fceefc065a3b476f69b6420d7135bb0882e6baf7e106ffe21d58398767edd5`|
|10FB18..1101AC|`b062fd51648ef4ea2270b845c3cd6b1760a55bfc7f1f3de9fe5e34c703fd0aae`|
|175A50..175C50|`4239555a0189dccae97c91e84fd795ee1f3257327fb8abdd76b485be69c462c7`|
|175E50..175EBC|`aac7dc286b54877766d1d7b330ff4c3416458836ffd9f797cf61b5cbce2643f4`|
|176350..17639C|`64c0e6b0d6f6ef5720112d50f61979fabe3b97b88b6d80362507aeb0756c8922`|
|176418..1764AC|`6d098ec032b55e6cb228068f4ef38f5e64180429cae1e11d94f12b53fffa87a7`|
|176578..17666C|`f2e57da39b6386cbdfeed6ab084b0779c6efc484b43b44c2d93ca2278254e677`|
|165B48..165C04|`3ed713e5d0d4e775106fef29b52e2ed161ab655702411bb19e940f91c04cc34a`|
|165C08..165CB0|`aa65067c5297fb43c6380fe3c082af4fc376244fd32b367357a3f095e3966571`|
|1770F0..17723C|`f762febdc33a11f5aa66146320b0f9b89b2fc3c8a2e962b86c6465904405a3ee`|
|1772B8..1773A4|`fb64fddd4439c423c8fef726c3530f349f762f7fabca3c44b3bd97c5b397d013`|
|1501E8..15022C|`b3d358958c7d3a656308036df516a6305c12049050523cbbf667ff8839137301`|

The other audited leaves are175EC0,175EF8,175628,172158. Owned rate table
240AF0/36bytes has SHA-256
`a667ab0a5ce47cd7b60cc99ae7013e555d1042649698fecaa52ad08eb3b25f6b`;
signed-quotient normalization table2381A0/256bytes has SHA-256
`14a5d850c255623f9472e3c650abce0c78d32f0276b315b3a276a0462d97a1ac`.
No comparison to another game's behavior is needed to establish these owned
Outbreak contracts; unrelated shared-library similarities are not substituted
for the missing callback, arithmetic, lifecycle or replay evidence.
