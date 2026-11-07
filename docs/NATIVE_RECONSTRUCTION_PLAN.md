# Outbreak native reconstruction plan

Status: SJUNI independent core, portable bridge and guarded opt-in runtime adapter
implemented 2026-11-05, with four bounded controlled integration smoke runs;
native resource core, bounded read owner and verified Windows mount/reader pass
the standalone suites with GCC and the pinned LLVM toolchain. The combined native
project now has sixty-five standalone suites, including the independent ADX
control, mono and stereo/downmix block cores, bounded PCM owner and fenced
host-output lifetime owner, raw-ID PCM session bridge and independent movie
picture-position publication and an owned bank playback session. Full transition and wider
real-consumer validation remain in progress.

Current sequencing, updated 2026-11-05: the user authorized committing the
mapping/comparison findings locally and continuing this transition plan. The
research baseline is local commit `733a8ed`. Semantic annotations cover
17,069/17,916 catalogue entries (95.27%); catalogue artifacts and unresolved
purposes remain explicit in the [remaining-work report](STATIC_MAPPING_REMAINING_WORK.md).
This replaces the earlier literal 100% mapping gate. Migration readiness is
assessed per subsystem contract and its dependencies; the mapping percentage
does not establish native correctness or justify removing compatibility code.

The [SJUNI dependency and contract inventory](native-sjuni/README.md) records
the first-stage evidence, implemented native interface, isolated comparisons and
remaining integration blockers. The user subsequently authorized a separate
candidate build and controlled game tests. Its coherent runtime/backend/game
rebuild and four bounded original/native smoke runs passed; results are in the
[candidate test record](native-sjuni/CANDIDATE_VALIDATION.md). No replacement has
been enabled in the player's build, no dependency removed and no game performance
improvement measured. The next resource boundary has an
[inventory and implementation status](native-resources/README.md).

The next integration cut is defined by the [cvFs request review](native-resources/CVFS_REQUEST_BOUNDARY.md):
bounded payload reads beneath retained original admission/completion ownership.
A [fresh source audit](native-resources/DEPENDENCY_INPUT_AUDIT.md) successfully
applied all 120 public dependency patches. It establishes reproducible inputs,
not matching rebuilt libraries or safe pending-request/guest-buffer lifetime.

The [request-owner prototype](native-resources/REQUEST_OWNER_IMPLEMENTATION.md)
now has a bounded native worker, runtime stop/join integration and isolated
verification. Public patch 0120 reapplies as part of the full 121-file series.
The [corrected candidate](native-resources/CANDIDATE_VALIDATION.md) now builds
and completes three bounded opt-out/native/PAK runs with clean window-close exits;
native runs prove joined ownership and at least 256 callback returns. This does
not establish general stop/close or audio/movie equivalence.

The [original lifecycle oracle](native-resources/DVCI_LIFECYCLE_ORACLE.md)
executes both complete stop-cap paths and subsequent slot reuse with explicit
external hooks. It confirms why asynchronous guest-target publication needs a
stronger incarnation/reservation contract. The current implementation cut keeps
the original synchronous RPC/guest ownership and adds exact in-file reads from
a verified actual plain-PAK layout. Its native mount/reader is tested separately;
the default-off game adapter now has a linked V3 candidate and a bounded clean
PAK session proving successful native reads. Three of the four quiescent DVCI
scalar entries also have executed-body evidence; comparison and broader coverage
remain open. The [media inventory](native-media/BOUNDARY_INVENTORY.md),
[stereo oracle](native-media/ADX_STEREO_ORACLE.md) and
[PCM owner extraction](native-media/PCM_OWNER_EXTRACTION.md) define the current
decoder and host-output boundaries. The [media candidate record](native-media/CANDIDATE_VALIDATION.md)
tracks actual decoder admission and the completed V6 original/native opening
movie pair. Native mono and stereo bodies execute; sampled movie presentation
gaps decrease but unresolved movie/transition stalls remain. The
[movie-stutter investigation](native-media/MOVIE_STUTTER_INVESTIGATION.md)
retains the user's observation and distinguishes measured stalls from suspects.
Complete PCM [session dispatch](native-media/PCM_BACKEND_DISPATCH.md),
[output ownership](native-media/AUDIO_OUTPUT_OWNER.md) and the
[pinned stream provider](native-media/NATIVE_STREAM_PROVIDER.md) have isolated
evidence. The [raw-ID session bridge](native-media/PCM_SESSION_BRIDGE.md)
also reproduces both toolchains' actual mix traversal and source-hook ordering;
they now form a complete default-off PCM backend. Its coherent V7 build includes
the provider shutdown ordering fix and public dependency patches through 0123.
The private original/native opening runs both exit cleanly; the native run proves
actual callback execution, whole-backend selection and joined output ownership.
It also records 40,256 starved output frames and four sampled movie intervals
above 50 ms, compared with zero in this bounded original-backend run. This is
an unresolved regression observation, not a proven cause or an accepted default.
The [candidate record](native-media/CANDIDATE_VALIDATION.md#complete-pcm-backend-v7)
preserves counts, build identity and coverage limits. Stage 3 remains in progress:
bank/RPC producer ownership, compressed stream ownership, movie clocks and wider
resource/media transitions still require reconstruction and validation. Gameplay,
rendering and final runtime removal remain required afterward.

The [bank session](native-media/BANK_SESSION_IMPLEMENTATION.md) reuses the
source-qualified host bank/sequence/VAG algorithms behind explicit session state,
whole-producer leases, reset epochs and allocation-free render scratch/retirement.
Its 123 isolated assertions pass with GCC and LLVM, including the standalone
Release CMake target. Independent original-source comparison now matches all
252 actions, 13,004 float words and 12,768 gain calls with both compilers, without
changing the frozen core. The [integration review](native-media/BANK_BACKEND_INTEGRATION_REVIEW.md)
defines aggregate PCM/bank/RPC selection and shutdown ordering. The subsequent
budgeted bank pilot passes 218 accounting/lifetime assertions and the same
original regression with both compilers; its [independent review](native-media/BANK_BUDGET_V2_REVIEW.md)
finds no confirmed allocator/lifetime defect within the documented domain.
Requested allocation bytes and asset counts are bounded, including retained
control blocks and old clips; this does not claim an OS memory limit. Production
packet capture and runtime integration remain required.

The [injected aggregate audio owner](native-media/NATIVE_AUDIO_AGGREGATE.md)
now supplies one complete V2 PCM/bank selection, admitted render-to-bank token,
outer-drain/provider-fence ordering and retained pre-clear reports. Both compilers
pass 12 lifecycle modes and actual SDK-header objects. The independent combined
source reference matches all 9,316 output float words and 10,052 ordered hooks;
raw observations retain 14 declared post-shutdown closed-query sentinel
differences. This remains an inert composition requiring qualified capture,
SDK companion integration and coherent game validation.

The [grouped bank adapter](native-media/NATIVE_BANK_GROUP_CAPTURE.md) now captures
HD/BD/TQ with one versioned batch after budget admission, without changing the
frozen packet adapter or bank DSP. Both compilers preserve the original bank
corpus and detect missing grouping/relock with negative controls. Public patch
0125 adds the [explicit RAM companion](native-media/NATIVE_SOUND_RAM_CAPTURE_DISPATCH.md)
for earlier ABI/transport/query/status access. Its reviewed source-order fixes,
32 companion cases, existing regression suites and actual SDK objects pass;
the complete126-patch series reapplies. Production writer/capture qualification
and rebuilt game selection remain open.

The [native SJRB ring core](native-media/SJRB_IMPLEMENTATION.md) now owns backing
and chunk incarnations and preserves the admitted two-pool/wrap-copy contract.
Both compilers match 30 original cases / 165 calls, including the constructor's
actual 16,384-byte PCM capacity plus 192-byte extension. A prior smaller synthetic
case had been mislabeled as the actual byte geometry; corrected independent
fixtures retain the earlier evidence unchanged. Global pool/module lifetime and
the full ADXT player, source/refill and playback clocks remain open.

The [native ADX window owner](native-media/ADX_WINDOW_IMPLEMENTATION.md) now
composes those actual rings, keyed codecs and predictor control through one
bounded acquire/decode/publication transaction. Both compilers reproduce all
33 original cases, including 52 PCM callback boundaries and full physical-byte
observations. Its 86 unit assertions also check allocation failure before
borrowing, no allocation after observable borrowing, stale requests and accepted
PCM drain after stop. The combined standalone CMake target passes with both
toolchains. Header/refill/loop, playback clock and RNA credit ownership remain
required before this can replace the complete compressed-stream player.

The [original encoded-refill oracle](native-media/ADXT_REFILL_ORACLE.md) now
executes complete refill/lifecycle and actual SJRB operations across 29 frozen
cases. It confirms pending free grants, later accepted-prefix publication and
deferred stop ordering, while exposing why raw reset/reuse needs a new safe
ownership contract. The [native encoded-refill owner](native-media/ADXT_REFILL_IMPLEMENTATION.md)
now owns one real ring, retained producer/consumer credits and private bounded
asynchronous read results. Both compilers pass its ownership assertions and
25 admitted source projections plus four explicit safety-refusal controls;
standalone CMake checks pass. Raw unpublished free-space bytes are deliberately
outside that comparison. Window sharing, headers, loop policy and actual
resource/player integration remain separate.

The [header oracle](native-media/ADX_HEADER_ORACLE.md) adds 31 completed
integer/short/reject cases and eight explicitly partial tag0 executions. The
subsequent [bounded math/header proof](native-media/ADX_HEADER_MATH_ORACLE.md)
executes original coefficient/cosine bodies under qualified current-runtime FP
operations: 45 returned cases and three explicit partials, with all 48 case
observations equal across compilers. Finite admitted headers now reach real
prefix return/state2. No invented coefficient or trig result is substituted;
exceptional PS2 FPU behavior and the unowned reduction paths remain unproven.
Native header/player integration, loop transitions and playback/credit clocks
remain required.

The [native header owner](native-media/ADX_HEADER_IMPLEMENTATION.md) now shares
the actual encoded source and preserves prefix returns, selective header effects
and diagnostic ordering. Both compilers pass66 ownership/parser/FP assertions
and the48-case comparison:45 admitted projections and three explicit refusals
of unowned original math paths. This is a finite header contract, not a complete
stream player or general PS2 FPU replacement.

Actual [disc configuration seals](native-media/CD_RAM_CONFIGURATION_SEAL.md)
and a conservative [graphics capture gate](native-media/CPU_RAM_CAPTURE_GATE.md)
now have dual-compiler isolated evidence. They are prerequisites for coherent
audio capture, not a qualified runtime factory. The graphics profile refuses
backings with advanced parent ownership; grouped capture, the earlier SDK
transport/ABI/status chain, coherent rebuilt selection and real-game validation
remain required.

The [cooperating Pad writer](native-media/PAD_RAM_CAPTURE_COORDINATION.md) adds
fair waiting-copy admission and guards the actual independent input writer.
Both compilers pass133 assertions, actual Pad/init/shutdown fixtures and full
bridge/Service objects. Overflow withdraws capture after draining copies while
preserving every original input write. The
[writer catalogue](native-media/NATIVE_SOUND_RAM_WRITER_CATALOGUE.md) records the
remaining execution/configuration conditions; the
[address validator](native-media/NATIVE_SOUND_ADDRESS_DOMAIN.md) refuses unsafe
aliases without issuing read authority.

Public patch0126 now supplies the [actual selected-renderer profile](native-media/GS_SOUND_RAM_PROFILE.md).
The full127-patch source series reapplies; both compilers pass concurrency,
cancellation, prior-audio regressions and actual source objects with qualified
sealed inputs. The [RuntimeMemory provider](native-media/NATIVE_SOUND_RAM_MEMORY_OWNER.md)
implements private real-capability acquisition and bounded copies, with130
protocol assertions, real packet/bank integration and whole actual-header
objects per compiler. Those protocol fixtures explicitly substitute acquisition
contexts; the [coherent V11 pair](native-media/COMPLETE_AUDIO_CANDIDATE_V11.md)
now observes actual acquisition, complete publication, packet/PCM activity and
normal retired teardown. Both runs reach gameplay/control checks and exit0.
Native records zero underruns in this bounded run; a separate unsupported read
diagnostic and wider domain/performance validation remain open. The
[file identity helper](native-media/NATIVE_SOUND_BUILD_IDENTITY.md) records actual
source/native file hashes without treating them as RAM authority.

The [shared-window original corpus](native-media/ADX_SHARED_WINDOW_ORACLE.md)
now executes35 returned transcripts and preserves four explicit cuts across39
cases, including40,017-sample streams, real request sizes, two simultaneous
consumer grants and source-order loop/target mutations. Its
[shared-source contract](native-media/ADXT_SHARED_SOURCE_CONTRACT.md) defines the
new ledger and canonical limit state. The [allocation-free codec workspace](native-media/ADX_WORKSPACE_IMPLEMENTATION.md)
now passes 284 unit assertions and 901 original comparisons with GCC and the
actual bundled UCRT LLVM toolchain, including real request sizes and long-stream
kernel inputs. Its prepared input remains a synchronous borrowed view; Source2
and Window2 must supply storage, credits and effect ordering. The
[shared source owner](native-media/ADXT_SHARED_SOURCE_IMPLEMENTATION.md) now
matches 30 independently authored original lifecycle/refill clients under both
compilers, including two simultaneous consumers and pending I/O. Its raw-refill
boundary mismatch is preserved separately; the qualified API uses the complete
lifecycle service. The [Window2 composition contract](native-media/ADX_SHARED_WINDOW_CONTRACT.md)
now has a [new 133-client lifecycle/PCM original corpus](native-media/ADX_WINDOW_V2_ORACLE.md),
with identical transcripts on both compilers and all three long streams reaching
40,017. Its native owner remains design work requiring complete transaction proof.
The new partial-final and asymmetric PCM probes define the physical ownership
gate; unpublished extension bytes cannot be equated with logical credit.
The [owned PCM store](native-media/ADX_PCM_STORE_IMPLEMENTATION.md) now passes
3,574 ownership checks and90 storage-only original projections on both compilers,
including retained padding and injected partial-credit failure. It supplies a
storage component, not complete Window2 or decoder equivalence.
Its [phased v2](native-media/ADX_PCM_STORE_V2_IMPLEMENTATION.md) now separates raw
stores/wrap from publication so encoded-input credit can be returned between
them. Both compilers pass3,601 checks and90 final/intermediate original storage
comparisons; a negative observation catches30 ordering errors despite matching
all final results. The [composed Window2 owner](native-media/ADX_WINDOW_V2_IMPLEMENTATION.md)
now joins actual Source2, header/loop control, workspace and phased PCM storage.
Both compilers pass 996 owner assertions, 123 admitted original clients / 8,034
observations, private numeric/credit/lifetime failure controls and an ordering
negative whose stable results still match. Ten original clients remain excluded;
the documented live-grant/cache relation is not raw guest-memory ABI equivalence.
This independent owner is in the native test suite, not the game. The separate
[prepared estimated clock](native-media/ADXT_ESTIMATED_CLOCK_IMPLEMENTATION.md)
now matches127 admitted original clients /132 operations, including observed
control-boundary state, and passes explicit refusal/FP/reentry/negative controls
with both compilers. It supplies no device timestamp or actual queue ownership.
Stage 3 still requires final-sector/LSC source support, RNA/DTR credits, actual
clock/player integration and media validation before advancing.
The [source geometry/route audit](native-media/ADX_SOURCE_GEOMETRY_AND_ROUTE_GATE.md)
finds91 whole-sector and8,819 partial-sector ADX member references. It keeps
logical lengths separate from actual AFS/file, memory and LSC routes; no padding
or broader source admission is inferred from the archive inventory.
The [retained AFS range binder](native-media/AFS_SOURCE_RANGE_IMPLEMENTATION.md)
now reconstructs original table parsing/resolution and deferred-open range
arithmetic:67 cases and22,228 parsed entries match with both compilers. Actual
sector extents can retain parent bytes separately from logical member lengths;
the original sentinel branch's unsafe nonzero-start result remains flagged.
This closes that bounded range gate, not the partition/LSC/player lifetime.
The subsequent [actual asset graph validation](native-media/ADX_ACTUAL_ASSET_STREAM_VALIDATION.md)
binds all8,910 identified ADX references from the owned ISO and fully decodes,
drains and joins6,706 distinct non-looping payloads with both compilers. All
result rows and per-channel digests match between compilers. Loop-bearing
assets, device output and complete player behavior remain separate gates.
Independent flag/count inputs then exposed a native ready-predicate defect.
The [separate r1 correction](native-media/ADX_READY_FLAG_IMPLEMENTATION.md) reads
the original signed enable halfword, and passes48 new clients plus123 prior
clients and996 inherited checks with both compilers. The frozen implementation
differs on24 new clients and remains a documented negative control. Select
exactly one owner implementation in an executable; the game still selects none.
The [actual loop-cycle run](native-media/ADX_ACTUAL_LOOP_STREAM_VALIDATION.md)
then exercises all80 distinct loop-bearing payloads (89 references) with the
corrected owner. Both compilers produce the same two complete cycles per
channel and actual joins. Timing-dependent following-cycle prefixes differ on18
rows and remain explicitly recorded. Player/output/LSC integration still gates
stage 3 completion; stages 4-6 have not been declared complete.
The [native buffering/drain control](native-media/ADXT_PLAYBACK_CONTROL_IMPLEMENTATION.md)
now passes318 admitted original clients with exact final control fields, queue
positions, traffic totals and complete physical PCM bytes on both compilers.
All330 original clients return;12 uneven-channel states remain explicit native
exclusions. Its51 ownership checks cover pending transfer stop, wrapped silence,
held leases, reentry and retained post-effect faults. The original inhibited
admission still sets the started byte without starting playback; the first
incorrect native interpretation and failed comparisons remain preserved.
This cut has a concrete phased PCM bridge, but Window2 still owns its private
PCM graph. Output copy/consumption credits, full pause/clock composition, LSC
replacement and actual player integration still follow.

The [single-resource player composition](native-media/ADXT_PLAYER_COMPOSITION_IMPLEMENTATION.md)
now connects the actual worker/decoder/PCM/control graph to a private native
output session and the existing output lifetime owner. Both compilers retain
all48 ready-flag and123 admitted original decoder clients, pass the48-case
short/long/rate/channel matrix and concrete blocked-source/concurrent-callback/
failed-provider retirement checks. The full finite actual-asset corpus binds
all8,910 references and copies6,706 distinct non-looping payloads with exact
sample/digest equality to the prior qualified native decoder, zero model
underruns/skips and real source joins. The output provider is an offline model.
Production output is process-wide and requires shared per-stream ownership;
the isolated player is not installed. Logical PAK tails, LSC, complete clocks,
movie consumers and actual game/media validation still gate stage 3. Stages 4–6
remain required; no runtime dependency is removed by these standalone checks.

The [shared stream output owner](native-media/ADXT_SHARED_OUTPUT_IMPLEMENTATION.md)
now provides one renderer/provider with independent stream generations and
retirement. Its isolated tests preserve peer playback and queues, reproduce
ordered mixed float words and retain failed-fence state. An additional fixture
uses the actual NativeStreamProvider/static slot and reviewed raylib functions
with model device primitives. Connecting the compressed players and existing
bank aggregate to this shared ownership remains required; it is not a selected
runtime backend or actual-device qualification.

The [shared-output player composition](native-media/ADXT_SHARED_PLAYER_IMPLEMENTATION.md)
now connects the actual compressed players to that session. Both compilers
validate peer progress during a blocked source join, retained decoder credit
after a real output-copy refusal, constructor rollback, and two actual decoder
workers through the actual provider/static slot with reviewed raylib functions
and model device primitives. One persistent session now services all 6,706
distinct finite payloads with exact prior native-decoder prefix digests, actual
per-source joins and one final model-provider unload. Bank/packet ownership,
complete clocks, LSC, logical PAK tails and actual game/media validation remain
required before stage 3 completes. No compatibility runtime has been removed.

The [live clock/player composition](native-media/ADXT_CLOCKED_PLAYER_IMPLEMENTATION.md)
now binds actual decoder/PCM/output observations to the unchanged qualified
clock. Both compilers match138 measurement-derived original operations and
detect15 stale pre-resume snapshot errors under controlled callback progress.
Actual pause preserves peer consumption, nonboolean arguments retain original
behavior, and unsupported FP/service states refuse before output effects.
The complete global ADXB/16-ADXT/RNA service order and movie-clock consumers
remain unqualified; the already-busy branch is not a substitute for that work.
Bank/packet aggregation, LSC, logical PAK tails and actual game/media validation
still gate stage 3, followed by stages 4–6.

The [verified imported source integration](native-media/IMPORTED_ADXT_SOURCE_IMPLEMENTATION.md)
now resolves all8,910 base File1 ADX references from actual retained imported
archives without opening the ISO. Both compilers fully decode6,706 distinct
finite payloads through the clocked player/shared output, matching the prior
native PCM baseline and all source/clock/join observations. This supersedes the
earlier blanket logical-PAK-tail blocker for these full base archives: real
sector tails are retained. Standalone replacements, overlays and other editions
remain separate. Original global audio scheduling, bank/packet integration,
LSC, movies and actual game/media validation still gate stage 3. No runtime
dependency has been removed, and stages 4–6 remain required.

The [native audio dispatch envelopes](native-media/ADXT_SERVICE_GROUP_IMPLEMENTATION.md)
now match81 independently frozen original cases and31,169 original instructions
under both compilers. Live independent slot tables, single phase dispatch,
ordered input/error tails and busy reentry are qualified. Strong per-call leases
survive current-slot removal; traversal allocates nothing. Children remain
explicit ports: actual phased decoder/player/RNA and32-DTR/8-DTX ownership,
file polling and clock consumers still require integration. This does not close
the prepared clock's unowned-service branch or complete stage 3.

The [native transfer group owners](native-media/ADXT_TRANSFER_GROUPS_IMPLEMENTATION.md)
now extend that original comparison through all32 DTR and8 DTX slots, including
both DTX scans per outer service. Both compilers match128 original cases and
82,740 original instructions with live membership, retained current children
and allocation-free traversal. Individual transfer/credit protocols and actual
phased native child bindings remain open. Dispatch validation is not a device
frame, complete audio migration or permission to remove the compatibility runtime.

The [actual phased finite players](native-media/ADXT_PHASED_PLAYER_IMPLEMENTATION.md)
now bind real source/decoder/control/RNA-prime/atomic-copy work to those groups.
Both compilers replay all 6,706 unique finite imported payloads with exact native
PCM baseline/terminal-clock results and clean actual source/producer/provider
fences. Phase boundaries, held-credit failures, independent slots, three-peer
order and a blocked source join are qualified. Native finite transport is an
explicit replacement for hardware transfers; general guest file/LSC/RPC
protocols are not relabeled native. Production enrollment, serviced discard
clocks, bank/packet output, movies and game transitions still gate stage 3.

The [native finite media control owner](native-media/ADXT_CONTROL_SESSION_IMPLEMENTATION.md)
now owns enrollment, all service memberships, clocks/keys, actual players and one
output provider behind session/generation keys. Both compilers validate collision/
stale-key refusal, failed-open mix-order restoration, pending-source index
retention, peer output and provider-fence retries. Its actual imported corpus
again matches all 6,706 finite PCM payloads and terminal clock/fence observations.
This replaces the manual test driver, not the remaining guest game ABI. Serviced
discard, bank/packet output, LSC, movies and game transitions still gate stage 3.

The [complete serviced-discard oracle and completion core](native-media/ADXT_SERVICED_DISCARD_IMPLEMENTATION.md)
now execute93 original cases through all group envelopes and match92 admitted
native cases under both exact FP toolchains. Fresh post-service queues and the
actual guarded service attempt are required; the inactive raw clock retains
base/1 behavior. One zero-frequency case stays outside native admission. The
canonical private player/control-session service binding remains to be qualified
before enabling that branch. This is not a completed game/media migration.

The [canonical serviced-clock binding](native-media/ADXT_SERVICE_BINDING_IMPLEMENTATION.md)
now supplies the actual private group/target and publishes into that same native
player. Both compilers match60 measurement-derived original operations, detect12
stale private-factory snapshots and preserve source-poll separation. The extended
owner again passes all 6,706 distinct finite imported payloads and actual lifetime
fences. The raw player still refuses unowned service. Complete looping playback,
LSC/seamless, bank/packet output, movies and game ABI/transition validation still
gate stage 3; gameplay, graphics/platform work and runtime removal follow.

The [integer raw-clock extraction](native-media/ADXT_INTEGER_CLOCK.md) now
matches 132 original-word cases with both compilers, including actual RNA/ring
getters and modulo accounting. It consumes prepared queue observations and does
not own queue synchronization, the estimated floating-point/tick clock or device
time. Those clocks and output credits remain required for the full player.
The [estimated-clock original oracle](native-media/ADXT_ESTIMATED_CLOCK_ORACLE.md)
adds 131 authored cases /136 operations under both exact toolchains:135 complete
operations and one explicit service cut. All1,128 emitted-FP micro comparisons
match. Native estimated-clock ownership and complete service integration remain
open; the literal float threshold behavior is preserved without rounding it to
nominal milliseconds.

The [owned asset inventory](native-media/FILE1_AUDIO_ASSET_COMPATIBILITY.md)
identifies 8,910 ADX references within the finite header profile. The
[bank loader map](native-media/FILE1_BANK_RESOURCE_LOADER_MAP.md) ties 103 complete
packed HD/BD/TQ tuples to the actual original submission path; all observed
rounded parts fit the individual limit. These are metadata/source findings,
not parser/DSP, simultaneous-budget or live playback qualification.

The default-off movie-position adapter also has a coherent V8 original/native
opening pair: at least 8,192 successful native publications, movement/menu
observations and clean closes. Its [candidate record](native-media/CANDIDATE_VALIDATION.md#known-caller-movie-position-publication-v8)
retains seven sampled native movie gaps above 50 ms and longer original
transition gaps; no performance improvement or complete media migration is claimed.

The objective is to reconstruct Outbreak so its game logic and platform services
run without a PS2 execution or hardware compatibility layer. The symbol map
provides the starting evidence. Progress comes from replacing complete subsystem
contracts and moving their state into native ownership.

The first milestone is one verified native subsystem: **SJUNI stream-buffer
management**, connected to the existing game through a temporary adapter.
Its bounded scope and the [Code Veronica cross-check](recvx-crosscheck/README.md)
make it a useful starting point. This milestone proves the reconstruction
process; it does not by itself remove PS2Recomp from the game.

The [regular loop player](native-media/ADXT_REGULAR_LOOP_PLAYER_IMPLEMENTATION.md)
now passes all 89 imported loop references /80 distinct payloads through actual
native control, decoder and accepted output copies with both compilers. A
queued-PCM boundary refusal led to a separate request-sizing revision that
preserves protected samples; two complete loop cycles match the prior decoder
baseline. All 50 standalone suites and the 6,706-payload finite regression pass.
This does not complete stage 3: LSC/seamless, bank/packet output, movie controls,
game ABI selection and actual media transitions remain. Stages 4–6 remain open.

The [owned LSC filename queue](native-media/LSC_QUEUE_IMPLEMENTATION.md) now
matches all 339 operations from 53 pre-native original cases with both compilers,
including mutable notification order, stale-slot queries and repeat/sequence
wrap. Its 111 ownership checks and new parent suite pass. Lower file operations
remain explicit ports; actual retained segment I/O and seamless/audio/movie
consumer integration still require implementation. Stage 3 remains open.

The [prepared seamless sequence owner](native-media/ADX_IMMUTABLE_SEQUENCE_IMPLEMENTATION.md)
now passes all 6,706 distinct finite payloads across 421 actual imported sequences
with both compilers, including complete accepted per-clip PCM, accumulated clocks
and joined source/output ownership. Four new negative controls and all 52 parent
suites pass. This is a fixed immutable sequence; dynamic LSC sources, bank/packet
output, movie controls and game/media transitions still gate stage 3. Stages 4–6
remain required.

The [bounded live queued ADX source](native-media/ADXT_DYNAMIC_LSC_SOURCE_IMPLEMENTATION.md)
now uses the actual native worker/ring/decoder/player graph. Both compilers pass
all 6,706 finite payloads across 421 queued sequences, with complete per-clip PCM,
accumulated clocks and source/output fences matching the earlier decoder baseline.
Late enqueue, delayed next headers, queue pause/repeat, callback enqueue, foreign
bindings, source errors and blocked retirement are covered. Four detected
counterfactuals and all 53 parent suites pass. The admitted source lifetime is
one-use; general restart/error recovery and original global scheduler parity
remain explicit boundaries. Bank/packet aggregation, movie controls, game ABI
integration and actual media transitions still gate stage 3; stages 4–6 remain.

The [shared stream/bank/packet output owner](native-media/SHARED_STREAM_BANK_OUTPUT_IMPLEMENTATION.md)
now preserves stream PCM, bank addition and master gain in one fenced callback.
Both compilers pass 298 composition assertions, five detected counterfactuals,
an actual blocked-LSC/decoded-peer/bank owner test and all 55 standalone suites.
Existing finite, regular-loop, fixed-sequence and live-sequence imported corpus
regressions pass with no cross-compiler output differences. This graph is still
isolated: game capture/gain binding, original global scheduler parity, movie
controls/lifetimes and coherent game/media transitions remain before stage 3
completes. No runtime component has been removed; stages 4–6 remain required.

The [movie counter/query core](native-media/MOVIE_COUNTER_CLOCK_IMPLEMENTATION.md)
now matches 504 original cases through nine owned bodies with both compilers.
Original execution caught and corrected an initial property-binding mistake:
rebasing uses property 0x47, independently of callback selector 0x0F. Defined
returns, raw rational words and ordered selective writes match; five detected
counterfactuals and all 56 standalone suites pass. This does not provide selected
callback/cache authority, ADXT filtering, due/skip policy or movie frame/source
ownership. Those integrations and game/media transitions still gate stage 3;
stages 4–6 remain open.

The [owned selected movie clock](native-media/MOVIE_SELECTED_CLOCK_IMPLEMENTATION.md)
now matches 546 original cases through 22 owned bodies with both compilers,
including cache, external history, raw status, callback-time facts and guard
snapshots. Callback self-removal remains fenced; seven detected counterfactuals
and all 57 standalone suites pass. Actual local scratch is an explicit opaque
input, and guard seeds describe the isolated serialized profile. Real ADXT audio
filtering, shared CRI guard/scheduler integration, movie construction/reset,
pause/buffering, due/skip, frame/source lifetime and game transitions still gate
stage 3. No movie override is enabled, and stages 4–6 remain open.

The [movie audio filter](../game/native/movie_audio_filter/README.md) now matches
67 constructors and 574 stateful operations through actual original integer,
history and memory-clear helpers. The [owned audio-clock envelope](../game/native/movie_audio_clock/README.md)
matches 315 wrapper/cache operations across 89 cases with both compilers and
retains the real native Session through an opaque stream key. Its separate
source/decoder/estimator/cache owner check and all 60 standalone suites pass.
These comparisons corrected the earlier threshold and inactive-output contract
annotations; failed candidates and unchanged original expectations are retained.
Actual live clock/tick binding, movie lifecycle, game integration and stages 4–6
remain required. Neither component is selected in the player's build.

The [pause and buffering controller](../game/native/movie_pause/README.md) now
matches all 316 original operations across 305 cases, including nested/raw pause,
callback state updates, optional guard ordering and complete integer frame-step
work. Ten deliberate faults and 14 provider-boundary checks are detected with
both compilers; all 61 standalone suites pass. Complete buffer predicates,
component/error binding, shared scheduler ownership and one coherent movie
context remain required; this isolated controller does not complete stage 3.

The [fresh movie clock constructor](../game/native/movie_clock_initialize/README.md)
now initializes the complete owned clock state. Two original compiler cohorts,
frozen before native implementation, produce identical results across four
stale-memory cases. Native construction matches all 168 normalized words and
detects eight deliberate faults; all 62 standalone suites pass. This is fresh
clock construction, not live stop/rebuild, property restoration or frame/source
retirement. One coherent movie owner and complete media transition validation
still gate stage 3; stages 4–6 remain open.

The [picture admission arithmetic](../game/native/movie_admission/README.md)
now matches 336 original operations across 330 cases through the complete
ratio/slack, auxiliary and hysteresis bodies. Both compilers detect 12 deliberate
faults; 11 boundary checks preserve refusals and host FP state, and all 63
standalone suites pass. The cached-clock query remains an explicit value
boundary, with original incidental FP effects recorded separately. Public bypass
policies, skip/frame-return paths, one coherent movie owner and real transition
validation still gate stage 3. Stages 4–6 remain open.

The [prepared owned timing context](../game/native/movie_timing_context/README.md)
now joins clock construction, selection/cache, audio filtering, pause/buffering,
picture requests and admission. Both compilers match 40 joined original
workflows / 210 operations and 250 snapshots, including callback observations
and actual nested original queries. Shared guard state and counter publication
before callbacks are measured at that boundary. Ten deliberate faults and 32
safety checks are detected; prior affected corpora and all 65 standalone suites
pass. A real native source/decoder/estimator test also preserves cache on stale
source refusal and retains Session ownership through explicit join. Components,
full predicates, source/frame fences, movie start/stop/rebuild and real game
integration remain required; this prepared context does not complete stage 3.

## Target architecture

The native executable owns game state, resource loading, scheduling, rendering,
audio, input and networking. PAK files supply the imported game assets. Original
asset encodings and the game's own scenario/script interpreters may remain;
they do not require executing PS2 instructions.

The ISO is an import source in the intended end state. Any current direct-disc
reads must first be identified and migrated before claiming that a session can
run entirely from PAK files. Packaging assets and reconstructing executable
logic are separate milestones.

Native subsystem implementations use ordinary C++ structures and interfaces.
During migration, adapters translate between those interfaces and the remaining
guest memory, register context, callbacks and runtime services. Those adapters
remain explicit dependencies until their callers have also been migrated.

## First milestone with SJUNI

### Recover the complete contract

Start from the [SJUNI notebook](SYMBOLS_CRI_SJUNI_LINKED_CHUNK_POOLS.md),
the [reviewed crosswalk](recvx-crosscheck/CROSSWALK.md#sjuni) and the
[central function index](FUNCTION_INDEX.md). Target File #1 US SLUS-20765 first;
File #2 requires its own address and behavior verification.

Trace construction, destruction, reset, queue operations and every consumer of
the object. Include indirect calls through its vtable, direct reads/writes of
fields, escaped pointers and shared globals. A function's callers alone do not
capture all dependencies on its memory layout.

Write down the contract before implementing it:

- Four lists of borrowed pointer/length spans and an external node free list.
- Object/node lifetime, pool exhaustion and ownership of payload storage.
- Whole-span removal, mode-1 splitting, and adjacent-span merging.
- The distinction between byte counts, queued-node counts and free-node counts.
- Error callbacks, callback reentry, signed arithmetic and input admission.
- The original critical-section and scheduling requirements at each operation.

Keep Outbreak's behavior authoritative where CVX differs. For example, the
reviewed work-size conversion uses signed truncation, and the default error
path differs from CVX's permanent loop. Close unresolved contracts needed by
this subsystem before replacing it. Record unresolved dependencies at the
adapter boundary rather than silently treating them as native behavior.

### Implement the native core

Define an interface for stream creation, reset, reservation, publication,
return and queries. Express span ownership and callback behavior explicitly.
Keep the implementation independent of `R5900Context`, `PS2Runtime`, PS2Recomp
headers, fixed guest addresses and guest syscall wrappers.

Preserve the established semantics before introducing algorithm changes.
Renaming generated routines or retaining a simulated register file inside a
new C++ module would not meet this milestone's native-core requirement.

### Connect the temporary adapter

Route the selected original entry points to the native core through an adapter
that owns guest-pointer conversion, callback translation and synchronization.
Choose a consistent state owner. If remaining guest callers still read or
write object fields directly, preserve their observable layout and updates,
or migrate those accesses before switching ownership.

Document which consumers still require the adapter and how each will move to
native interfaces. Keep the existing implementation available for comparison
and recovery while the replacement is being validated.

### Verify behavior and integration

Compare identical operation sequences against the existing implementation,
checking returned spans, queue order, counts, errors and state transitions.
Exercise reset, partial reads, split/merge modes, exhausted pools, returned
chunks and the input edge cases admitted by real callers. Include callback and
synchronization behavior rather than testing only the happy-path queue logic.

Then exercise real consumers: audio and movie streaming, resource transitions,
pause/resume, repeated loading and shutdown. Compare observable results and
progress, and investigate any divergence before enabling the replacement by
default. Measure performance separately; correct reconstruction does not
guarantee a speedup.

### Complete the milestone

The deliverable consists of a documented contract, an independent native core,
the integration adapter, behavior comparisons and a remaining-dependency list.
The milestone is complete when the selected consumers operate correctly through
that boundary and the native core builds without PS2Recomp dependencies.

Retire the adapter only after all consumers of its guest representation have
moved to native interfaces. Remove compatibility code only when its last user
is gone and the affected paths have passed validation.

## Expand by subsystem

Use the dependency map to choose the order after SJUNI. Existing native PAK,
audio, input, network and graphics work should be reused where its interface
and behavior meet the reconstruction requirements.

| Stage | Main work | Evidence required to advance |
| --- | --- | --- |
| Dependency inventory | Connect mapped functions to state, callers, callbacks, overrides and runtime services. | A defined boundary and list of consumers for each selected subsystem. |
| SJUNI pilot | Implement the independent core and temporary adapter. | Behavior comparisons, real-consumer integration and a remaining-dependency list. |
| Resources and media | Extend native PAK/resource interfaces; reconstruct file streaming, decoder ownership and audio/movie controls. | Matching loading/completion behavior, audio/movie output and lifecycle transitions. |
| Gameplay and scheduling | Reconstruct session state, actors, collision, scenario/script execution, timers, callbacks and task ownership. | Scenario progression, saves, controls and co-op behavior preserved without guest-state dependencies in migrated modules. |
| Graphics and platform services | Move scene submission and remaining system services to native interfaces. Replace dependencies on VU/VIF/GIF/DMA and GS hardware simulation. | Matching geometry, animation, materials, draw order, effects, UI and timing through the native path. |
| Remove compatibility runtime | Migrate the final callers, retire adapters and remove unused build/runtime components. | Clean builds and representative gameplay with no remaining PS2 execution or hardware compatibility dependency. |

Larger systems can be divided into smaller complete contracts. A migrated leaf
function is useful progress, but it does not mean its entire parent subsystem
has been reconstructed.

## Preserve game behavior during migration

Keep guest/native ownership explicit at every boundary. Preserve original
callback order, data units, arithmetic, resource lifetime and completion rules.
Reconstruct scheduling in terms of required ordering and progress before
replacing guest threads with host tasks. A mutex alone does not reproduce all
thread-priority, wakeup and callback semantics.

Validate cross-system behavior as dependencies move: room changes, movie/audio
transitions, save/load, scenario completion and multiplayer synchronization.
Separate deliberate gameplay changes from equivalence work so a behavior
change can be traced to its purpose.

For each subsystem, record its status as mapped, contract reviewed, native core
implemented, adapter integrated, behavior validated, callers migrated or
compatibility dependency removed. Record build/test identity and remaining
dependencies alongside the status. These are distinct milestones.

## Completion criteria

The game reaches the intended architecture when:

- Game execution no longer requires PS2 instruction translation, simulated CPU
  registers or a guest-addressed RAM model.
- Platform services no longer depend on PS2 syscall, kernel or IOP/RPC emulation.
- The scene path uses native rendering interfaces without PS2 hardware simulation.
- Imported PAK content supplies required assets without live ISO reads.
- The build and packaged game no longer link or require PS2Recomp's execution
  runtime, generated game-function ABI or migration adapters.
- Supported gameplay, saves, media, controls and co-op pass the applicable
  validation for each supported edition.

Moving inherited runtime files into another folder does not satisfy these
criteria. Dependencies are removed when their services and consumers have been
reconstructed, regardless of how files or libraries are named.

## Related work

- [Symbol mapping overview](SYMBOLS.md) and [function index](FUNCTION_INDEX.md).
- [Completed CVX comparison](recvx-crosscheck/COMPLETE_SCOPE_REPORT.md), including Outbreak's
  ring counters, DTX shutdown gates and PS2RNA control differences.
- [Native asset rendering work](M2_NATIVE_ASSET_RENDERER.md).
- [Native networking work](NATIVE_NETCODE.md).

The current task is extending the native resource/file-stream boundary while
widening SJUNI consumer and lifetime coverage. Its independent core/portable
bridge and known-hook continuations have passed isolated checks and a separate
candidate has passed bounded real-consumer smoke runs. Replace and validate each service before retiring
the PS2 compatibility components that supply it.


## Checkpoint: native movie audio controls

The requested audio-control scope is implemented and qualified: requested and
buffering pause/resume call the same native audio Session used by clock queries;
frame stepping reconciles the original frame ratio, residual and filter; native
owner tests cover repeated buffering/user pauses, failures, stale/foreign keys
and shutdown retry. Both compilers match 206 original movie-policy cases/810
operations, and all 67 standalone suites pass. See the
[audio control contract](native-media/MOVIE_AUDIO_CONTROL_CONTRACT.md) and
[qualification](../game/native/movie_timing_context/audio_commands_qualification.json).

This is a prepared native control boundary. The production game path has not
been switched to it, and its output-device validation uses a callback model.
The subsequent video ownership/publication scope is recorded below. Complete
movie construction/stop/rebuild, scheduler/adapter binding and representative
in-game transitions remain in stage 3. Stages 4-6 remain open.

## Checkpoint: native timed video ownership

The prepared movie Context now owns a timed video pool. Decoded frames use its
existing clock for hold/present and a bounded late-frame skip decision; physical
storage remains retained until actual producer and renderer fences complete.
Opaque owner/incarnation keys protect reuse, and close also retires frames still
waiting for authoritative timestamps. Pause/resume and frame-step tests join the
actual native audio Session with an output-device model.

Both GCC and LLVM match 218 original cases, 662 operations and 880 initial/final
snapshots, with eight deliberate faults detected. The first 199 cases were frozen
before the native candidate. All 68 standalone suites pass on both compilers.
An offscreen hardware test decoded an owned 512x320 File #1 movie I frame on the
Radeon RX 570 and proved that a real unsignaled renderer fence prevents reuse;
it also checked safe reuse, shared-clock hold/step and deferred-timestamp close.
See the [results and reproduction notes](native-media/MOVIE_VIDEO_FRAMES_RESULTS.md)
and [qualification](../game/native/movie_timing_context/video_qualification.json).

This closes the prepared video queue/ownership scope. It has not been selected
by the production game, and neither monitor presentation nor audible A/V sync
has been validated. The next implementation scope is complete movie
construction/stop/rebuild: compose source, demux/decode, timing, audio and video
owners, then bind their scheduler/game adapters and validate real transitions.
Full codec skip/recovery and representative whole-stream I/P/B validation also
remain. Stage 3 remains open; no compatibility components have been removed.

## Checkpoint: prepared native movie lifecycle

The native lifecycle module now implements original construction/start/stop/
rebuild/destroy orchestration and a separate physical owner that waits for source,
audio and GPU retirement before creating a new generation. Both compilers match
176 pre-native original cases/179 operations/355 initial and final snapshots;
eight deliberate faults are detected. All 69 standalone suites pass under both
compilers. Actual native source/audio/frame tests cover blocked reads, pending
rendering, stale keys, reentry, partial construction, shutdown and rebuild.

An offscreen RX 570 test rebuilt two actual source/parser/clock/decoder/frame
graphs. A real unsignaled renderer fence prevented replacement; the rebuilt
graph decoded identical first-frame pixels. No game window or audio device was
opened. See the [results](native-media/MOVIE_LIFECYCLE_RESULTS.md),
[contract](native-media/MOVIE_LIFECYCLE_CONTRACT.md) and
[qualification](../game/native/movie_lifecycle/qualification.json).

This is a prepared ownership implementation. The logical original policy and
physical owner still require their scheduler/game command adapter. The existing
program-stream parser handles video PES, so audio currently requires an
independently demuxed native ADX view. The hardware probe also confirmed that
later pictures in the owned clip can lack individual PES timestamps; the strict
prepared graph refuses those rather than guessing. The successful GPU evidence
therefore covers first-frame decode, stop, retirement and reconstruction, not
whole-movie playback.

The next gates are source-qualified picture timestamp reconstruction and native
Sofdec audio routing, then logical/physical scheduler binding and representative
whole-movie/game transitions with audible A/V synchronization. Stage 3 remains
open; stages 4-6 and compatibility removal have not been claimed complete.

## Current checkpoint: native timestamps and complete short video

Temporal reconciliation now matches 83 original cases/399 operations, and the
joined timecode/baseline/latest policy matches 121 original cases/507 operations,
under both compilers. Six deliberate faults are rejected by each comparison.
All 70 standalone suites pass with GCC and LLVM, including a fresh independent
LLVM native build using explicit tools and no private game-build headers.

The real RX 570 pipeline decodes and presents all 195 pictures of the owned short
SFD after graph reconstruction: 12 I, 55 P and 128 B pictures by independent
selected-payload prefix counting. Actual producer/reader fences and matching
first-frame readback remain checked. This removes the earlier missing-PES-time
first-frame limit for this profile. See the
[timestamp results](native-media/MOVIE_TIMESTAMP_RESULTS.md) and
[qualification](../game/native/movie_timestamp/qualification.json).

An all-member route inventory verifies all 201 File #1 SFD payload hashes and
packet extents. None contains audio C0-DF or BD packets. Thus the remaining audio
route for this edition is the separate native ADX/game-output path, not a new
embedded SFD audio decoder. Other editions remain separately admitted.

The user has asked to continue until stage 3 closes. The
[closure checklist](native-media/STAGE3_CLOSURE.md) tracks consumer integration
and validation gates without inventing a completion percentage. Broader movie
profiles, logical/physical scheduler and game command binding, separate ADX/
output integration, the retained unsupported-read diagnostic and a coherent
candidate with resource/media transitions remain. These offline tests opened no
game window or audio device; stage 3 is still open.
