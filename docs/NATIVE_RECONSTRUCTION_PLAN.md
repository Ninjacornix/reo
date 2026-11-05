# Outbreak native reconstruction plan

Status: SJUNI independent core, portable bridge and guarded opt-in runtime adapter
implemented 2026-11-05, with four bounded controlled integration smoke runs;
native resource core, bounded read owner and verified Windows mount/reader pass
the standalone suites with GCC and the pinned LLVM toolchain. The combined native
project now has fourteen passing suites, including the independent ADX
control, mono and stereo/downmix block cores. Full transition and wider
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
decoder and host-output boundaries. Wider resources/
media, gameplay, rendering and final runtime removal remain required.

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
