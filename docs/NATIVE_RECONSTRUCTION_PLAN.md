# Outbreak native reconstruction plan

Status: SJUNI independent core, portable bridge and guarded opt-in runtime adapter
implemented 2026-11-05, with four bounded controlled integration smoke runs;
native resource core, bounded read owner and verified Windows mount/reader pass
the standalone suites with GCC and the pinned LLVM toolchain. The combined native
project now has thirty-two standalone suites, including the independent ADX
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
all final results. Complete Window2 integration remains the next gate.
Clocks, RNA/DTR credits, LSC
replacement and actual player integration still follow.

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
