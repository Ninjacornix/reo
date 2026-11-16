# Stage 4 completion plan

Planning baseline: 2026-11-13, commit `54a6b497` plus the existing uncommitted gameplay work. Stage 4 is incomplete. This plan defines implementation and final acceptance; updating the plan does not qualify the current game. The historical baseline below is preserved separately from the current execution priorities and completion ledger.

Finish the stock File #1 US gameplay migration using the launcher's pinned LLVM/MinGW compiler. Integrate complete gameplay paths into one native application, reuse existing implementations, and test changes in proportion to their impact. Stage 4 closes only after all required gameplay is implemented, selected by the launcher candidate, and checked together on the final build.

This plan governs subsequent Stage 4 execution and testing cadence. Earlier GCC/LLVM results remain historical evidence; producing another GCC result is no longer a routine Stage 4 gate. The [modernization direction](../NATIVE_MODERNIZATION_DIRECTION.md) continues to govern architecture and the separation from stages 5 and 6.

Planning decisions: require the shipping LLVM compiler only; build shared production libraries once per coherent change batch; use focused checks while implementing and complete acceptance on the final candidate. Preserve coverage of every supported behavior, while reducing duplicate compiler runs, redundant compilation and unnecessary combinations. Finish the first visible, controllable native room before accumulating more isolated components. Subsequent authorized implementation and its exact evidence are tracked in the completion ledger.

## Scope and completion contract

The supported profile is File #1 US v2.00 / SLUS-20765 on Windows x64, including all five scenarios, supported characters and difficulty choices, ordinary gameplay, offline companion behavior, existing gameplay options, supported save/resume flows and account-free co-op. File #2, other disc revisions, arbitrary mods and unrelated launcher redesign are outside this stage. Preserve original gameplay rules, content, timing and progression unless a deliberate modernization is explicitly documented.

Completion requires all of the following:

- The launcher candidate starts the canonical native session and executes required actor actions, AI, scripts, collision, timers, tasks, inventory, interactions, transitions and cinematics through native owners.
- Every required caller has a concrete implementation. No successful empty provider, test callback, fabricated state, ignored refusal or guest-gameplay fallback fills a gap.
- Required room/scenario content is supported in every context in which the game uses it. All five scenario programs can run; command-table percentages alone cannot satisfy this gate.
- Input, audio/video, UI, networking and save/resume consume and update the same native session. Native state is authoritative; guest RAM is not the gameplay state store.
- The final source and package pass the complete acceptance matrix below, including actual gameplay, saves and co-op. All blocking failures are fixed and affected evidence is rerun.

Full GPU replacement and deletion of the remaining compatibility runtime remain stages 5 and 6. Stage 4 must nevertheless provide a functioning presentation path for actual gameplay acceptance. Resolve this dependency early: a temporary presentation adapter may consume native scene snapshots and existing graphics services, but it may not execute translated game logic or read guest actor state to generate the scene. If that requires a minimum piece of Stage 5 infrastructure, implement that prerequisite before claiming Stage 4 acceptance and record the boundary. Retaining the existing renderer does not waive visible gameplay checks.

## Verified starting point

| Area | Baseline and consequence |
| --- | --- |
| Shipping compiler | `launcher/PortableCompilerSetup.cs` pins LLVM/MinGW UCRT `20251216`, driver `x86_64-w64-mingw32-clang++.exe`, SHA-256 `f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3`. `export_portable_windows.py` and `compile_game.py` enforce the portable route. Use this identity for required game checks. |
| Application | `NativeSession`, `SessionRooms`, `SessionStartup`, `RoomModels` and `SessionResources` exist. Full terminal frame/behavior/physics services and installed native gameplay remain open. V39's save adapter does not replace gameplay. |
| Scripts | Latest actor-population receipts report 370/432 ordinary and 344/432 offline table entries, and 34/171 ordinary versus 27/171 offline full-bank admissions. None of the five EVBs fully admits. These are distinct coverage measures, not completion percentages. |
| Immediate script gaps | The latest static five-EVB ordinary inventory has 43 unsupported records across `0x60`, `0x6C`, `0xD0`, `0x106`, `0x132`, `0x169`, `0x172`, plus one unimplemented zero-payload `0x63` record. Offline inventory has 299 unsupported records plus that profile limit. Further required work can appear through dynamic calls and other assets. |
| Recent work to preserve | Uncommitted dialogue room banks/session integration, scene reset, actor population commands, scene text and ground attachments need classification and integration. Do not assume all uncommitted files have equivalent validation. Separate unrelated launcher, slowdown and movie-decoder changes. |
| Content integration | Remaining cinematic evidence includes 60 too-few-track controlled pairs and 12 missing-model descriptor requests. Resolve actual resource identity and reachability; do not pad tracks or invent asset aliases. |
| Build overhead | `comparison_objects.py` already caches production objects, but its cache key includes all captured native headers. The VM verifier still compiles its original fixture and test translation units on each run. These are specific optimization candidates. |

Baseline evidence: [integration audit](STAGE4_INTEGRATION_AUDIT.md), [session resources](SESSION_RESOURCES.md), [dialogue work](DIALOGUE_ROOM_BANKS.md), [scene entry](SCENE_ENTRY.md), [remaining object pair cases](SCALAR_PREFIX_PLAYBACK.md), [latest script admission](../../build-native-sjuni/actor-population-admission-llvm-v1/receipt.json) and [latest static command inventory](../../build-native-sjuni/actor-population-frontier-v1/receipt.json). Local receipts are private evidence and are not distributed assets.

The [completion ledger](STAGE4_COMPLETION_LEDGER.md) separates the current prepared changes from verified behavior. The [build baseline](STAGE4_BUILD_BASELINE.md) records the existing incremental LLVM route. Prepared collision-frame, actor-control and AI-policy work is useful starting material, but it does not close any final acceptance domain. Resolve incomplete test/implementation pairs before spending time on a comparison run.

## Current execution priorities

The latest fully passing sealed integration cohort is [text-object-startup-llvm-v4](../../build-native-sjuni/stage4-orchestration/text-object-startup-llvm-v4/receipt.json): fourteen selected CTests and nine owned-content cases pass with empty source/archive drift. Timed `132` now uses the real scenario-message bank and startup loader, shared application text cache/lifecycle, and actual linked tasks; failures stop before later frame phases and clock commit. Its [original comparison](../../build-native-sjuni/timed-scene-text-llvm-v2/receipt.json) passes 389,467 checks. Source-ordered room-object import and canonical row-31 aliases also pass a [shared-library original comparison](../../build-native-sjuni/stage4-orchestration/room-objects-missing-shared-llvm-v1/receipt.json). The prior [ordinary camera comparison](../../build-native-sjuni/room-camera-llvm-v6/receipt.json) qualifies the lower camera path across all 166 rooms, not higher modes/tasks, input or presentation. There is still no demonstrated complete playable native frame; later drafts require their own integrated qualification.

Read-only planning review of the subsequent work, 2026-11-13:

| Work now present | Evidence and next requirement |
| --- | --- |
| Higher camera modes, linked tasks, scene provenance and NativeSession/frame binding | The [development comparison](../../build-native-sjuni/stage4-orchestration/room-camera-modes-original-v23/receipt.json) passes 5,984 checks and 2,168 original calls. It combines freshly compiled camera units with earlier archives, so it does not qualify the current application. Camera registration and application tests are prepared; run one coherent build, the lifecycle/worker cases, and the prepared camera and real scene-import comparisons against that build. |
| Zero-mode `63` inventory resources and NativeSession binding | Native text/image/cache/background ownership and VM binding are implemented. The [prepared harness](../../build-native-sjuni/inventory-ui-resources-prepare-llvm-v7/receipt.json) compiles the original and fixture, but has not executed the comparison. Run its archive-backed comparison after the coherent build, including partial failure, retry and reentrant-close cases. Actual inventory drawing remains a separate missing consumer. |
| Analog control | Unintegrated draft with a known mismatch: original input mask `2`, draft `7` for the first remaining failing case. Finish the selector/state branches and the reachable head-target helper before integration. Loading the full original constant data fixed an earlier fixture error; do not change correct native math to compensate for an incomplete oracle. |
| Ordinary actions and product frame | `SessionBehaviorServices::dispatch` still refuses ordinary action execution; additional hit/status and terminal frame providers remain unavailable. The product does not yet demonstrate a visible, controllable native room. These are implementation gaps, not extra testing gates. |

The planning review changes documentation only. Existing implementation workers were asked to hold further edits and runs for this review. Prepared tests, syntax checks and development comparisons retain their stated limits; no new shared-build or gameplay result is claimed.

The earlier [ordinary-camera-startup-llvm-v1](../../build-native-sjuni/stage4-orchestration/ordinary-camera-startup-llvm-v1/receipt.json) remains **failed overall**. Its NativeSession case failed during room installation before `169` could execute because the authored room requires missing audio/effect providers. The corrected controlled-script fixture passes in v2/v3; it does not qualify the unmodified room. [Command 169](../../build-native-sjuni/scenario-enemy-relocation-llvm-v1/receipt.json) independently passes 242,558 checks, 886 original calls and VM dispatches, ten refusal cases and all eight authored records, with an explicit identity check against the passing v2 cohort. Do not substitute an old or failed receipt for a matching current source/build identity.

These measurements identify repeated compilation and integration gaps as current priorities; they do not establish how all time over the preceding days was spent. In this newer batch, the cinematic-camera owned-asset case alone ran in 0.969 seconds. Reducing its content coverage would save little. Measure build, reference-fixture compilation, execution and investigation separately before removing an expensive check.

The [current ordinary script inventory](../../build-native-sjuni/timed-scene-text-frontier-v1/receipt.json) has zero unsupported EVB records, plus the required zero-mode `63` profile limit. Offline execution has 196 unsupported records plus that limit. [Admission](../../build-native-sjuni/timed-scene-text-admission-llvm-v1/receipt.json) is 41 ordinary and 28 offline configured banks out of 171, with five ordinary and no offline entry-1 startup closures admitted. These are different measures; none is a percentage of Stage 4 completion. Real provider readiness and gameplay execution remain separate gates.

The next connected batch has three parts:

1. Complete the ordinary camera-to-input-to-action path and concrete frame consumers. Reuse the imported room cameras, existing projection, fog and visibility owners; connect one shared ordinary/cinematic camera state to actual actor input. Camera import alone is insufficient. Identify the minimum real presentation consumer while implementing this path, so visible movement is not deferred indefinitely.
2. Complete actual offline startup and its application caller. Preserve the qualified `6AD5C0` reset/import, warm ownership, retry and script-provider work; bind actual voice/media, controller routing and remaining startup/frame effects. The launcher or product executable must construct the native application. Test-provided effects do not satisfy this dependency.
3. Close remaining scenario blockers through their existing owners. Preserve qualified `169` and `132`, finish zero-mode `63` including its reachable unpaused UI resource path, then pursue offline `1A0` and each newly exposed dependency. Correctly passing a paused early return does not finish an unimplemented resource/UI path.

These parts feed Milestone 1 and can overlap with bounded scenario work. Do not make a complete opcode table a prerequisite for the first playable room. A batch that exposes a missing runtime dependency should name and resolve that dependency before starting another unrelated component. Save-state ownership can be designed in parallel, but real save acceptance and co-op follow a functioning offline session.

### Immediate implementation queue after planning

| Order | Concrete work | Exit evidence and limit |
| --- | --- | --- |
| A. Reconcile the prepared batch | The text/object v4 cohort, `132` and room-object original comparisons and refreshed admission pass at their recorded identities, alongside the earlier lower-camera/`169` evidence. | Completed for the recorded batches only. Controlled command/task cases do not prove stock room progression or close authored-room provider gaps. |
| B. Complete ordinary control | Finish the `5BE9A0` camera mode/task dispatcher around the prepared lower camera selection/pose path; connect shared camera state to `6621F0` analog input and actual primary/secondary actor actions. | Real input changes the canonical actor, camera and collision state. Camera import, a lower-level test call or an inactive actor fixture cannot close this item. |
| C. Complete startup and application ownership | Retain the qualified `6AD5C0` ordering, missing-type/failure policy and room-object script binding; connect real controller, voice/media and remaining startup effects. Construct `OfflineApplication` from the product executable. | A real launch configuration reaches an active native frame. Explicit refusals remain open wherever supported gameplay reaches them. |
| D. Make the frame visible and complete | Name every remaining World stage, Worker and PhaseEffect consumer; connect the minimum real presentation path, clock, input, UI and pause/close behavior to the same session. | Milestone 1: visible movement, collision and state-changing actions through a private launcher candidate. Test callbacks and guest gameplay are not accepted terminal consumers. |
| E. Expand from that playable path | Preserve qualified `132`; complete zero-mode `63`, offline `1A0` and newly exposed command/provider dependencies in connected scenario batches; integrate action/AI, room transitions and cinematics. | All required content contexts execute through concrete owners, then satisfy Milestones 2 and 3. Audit opcode support, provider readiness and actual execution separately. |
| F. Finish persistence, co-op and release checks | Complete semantic saves and remaining platform consumers, native multi-process co-op, exact launcher packaging and the final matrix. | Milestones 4 through 7 all pass; every required ledger entry is verified against the final candidate. |

B and C may proceed independently after their shared interfaces are settled; D must be designed alongside them. Scenario work in E can proceed where it directly supplies their missing providers. Establish the smallest real integration route before expanding it to the full supported profile; a complete opcode table or a new test framework is not a prerequisite for that first route.

The next execution batches should be concrete:

1. Seal the already prepared camera and inventory-resource integration in one shipping-LLVM build. Run the affected application checks, then the three prepared camera, scene-import and inventory original comparisons using those exact archives. Keep the unfinished analog draft out of the candidate. Refresh script admission only after the resource comparison passes; static admission cannot close inventory presentation.
2. Correct and qualify analog control in its reusable focused build, then connect camera, input, actual action dispatch and collision to an active player. In parallel with that bounded work, enumerate every terminal frame/startup provider and implement the minimum real display/input/audio consumers. Deliver the Milestone 1 launcher route; an inactive-actor fixture or a deliberate missing-provider failure is not the exit.
3. Expand that runnable route through related actions, offline AI, script providers, room changes and cinematic lifecycles. Keep each batch attached to a required application caller. Track save ownership while these interfaces settle; finish saves and co-op against working gameplay, then perform the final candidate matrix.

Do not wait for every unrelated draft to become ready before sealing a coherent ready batch. Conversely, do not use a successful component comparison to bypass a known application blocker. A failed behavioral comparison is a correctness investigation; repeated compilation of unchanged inputs is removable overhead.

## Implementation order and milestone exits

These are completion gates, not a requirement to serialize every task. Milestone 1 establishes the integration target. Milestones 2 through 4 can overlap once their shared ownership contracts are agreed; save-state design should begin while those contracts are being settled. Co-op implementation starts after offline gameplay is playable. Packaging stays usable throughout, with its final seal after the required systems are integrated. Final acceptance follows all implementation gates.

### Milestone 0 Establish one current baseline

Preserve the existing working tree before integrating anything. Record source changes, untracked gameplay files, dependency changes and the selected launcher/build-kit identity. Retain unrelated work without including it in the Stage 4 implementation by accident. Review the recent uncommitted gameplay groups against their receipts; integrate coherent groups rather than resetting them or rebuilding their implementations from scratch.

Create one completion ledger, maintained with the implementation. Each entry records the required behavior or caller, current native owner, actual application call site, missing dependencies, content/context coverage, focused test, final acceptance case, status and source identity. Use states `missing`, `implemented`, `integrated`, `verified`; only the last state counts toward completion.

Populate the ledger from all `Worker`, `PhaseEffect`, world stages, behavior/action dispatch, AI goals/actions, script/provider requirements, scene/resource lifecycles, input/media/transport hosts and save callers. Reconcile historical open items with newer implementations. Classify unused legacy/debug branches only after establishing they have no required supported-profile caller; absence from one recorded playthrough is insufficient.

Establish the LLVM incremental build and fast regression baseline. Record preparation, compilation, linking, execution and evidence-writing times separately. Discover registered test identities instead of encoding an expected total such as 17 or 18. Preserve requirements for specific tests so automatic discovery cannot hide a deleted test.

Exit: one reproducible LLVM baseline, an owned gap list, explicit acceptance cases and a decision about the native-to-renderer boundary. Do not block this milestone on a fresh dual-compiler qualification of all historical modules.

### Milestone 1 Run a complete native frame in a real room

Implement concrete terminal `PhaseServices`, world services, `BehaviorServices::dispatch` and collision participants underneath the existing decorators. Every dispatched stage must identify its real effect owner. Reuse existing motion, status, hit, gauge, model, postprocess, collision and navigation implementations.

Wire native launch configuration, actual roster and placement producers, normalized platform input, the simulation clock and a real native application loop. Compose `SessionStartup`, room assets and `SessionResources` against the same World/Update identity. Bind direct Stage 3 media services and the minimum real presentation consumer needed for the selected route.

Use the already admitted `r0417300` content to expose integration failures quickly. Exercise an active player and real collision, not only inactive actors or script stepping. Initially guard unavailable routes with explicit failures in a private candidate; do not fall back to original gameplay and report success. The room fixture does not count as a complete scenario launch.

Exit: ordinary input causes visible native movement and collision; real actions change native inventory/health/state; scripts and clocks advance at the correct cadence; pause and shutdown work; evidence identifies native execution and no guest-gameplay fallback. A runnable integration target must exist before further long sequences of isolated component milestones.

The first implementation batch should finish the prepared session composition, qualify its actual control/actor-service consumers, and enumerate every terminal provider it still reaches. Then complete the action dispatch and input-to-movement path, actual launch roster, phase workers and minimum presentation needed for this exit. A test that deliberately stops at an unimplemented analog/action provider is useful boundary evidence, but cannot satisfy the exit. Likewise, fixture callback tables do not establish which original action destinations are implemented. Determine required action IDs from actual producers and source tables, and attach each to a concrete native consumer.

### Milestone 2 Complete scenario execution and ordinary gameplay

Expand from that working frame while completing the script/provider and actor/action ledgers together. Batch related commands by their real owner rather than treating each opcode as an independent project. The earlier `60`, `D0` and offline `1A8` blockers now have scoped passing evidence; preserve that work and use the current execution priorities and ledger to select the remaining blockers. The zero branch of `63` needs actual resource/UI cleanup; positive-branch support is insufficient.

Cover all required player actions and character-specific abilities; enemy and NPC construction, behavior and retirement; offline AI observation, goal redispatch, action execution, pathing and room changes; interaction, combat, damage, recovery and death; items, weapons, reloading, inventory use/exchange and puzzles; scenario events, outcomes and statistics. Include active inventory/UI states rather than relying on the qualified cold-close path.

Finish the reached effect consumers in the same application: ground attachments, inherited trails, delayed bursts, projectile variants, lights, spatial/audio consumers and shared pool lifetimes. Reuse the existing typed owners and bind them to actual frame callers. CPU-side effect lifetime is Stage 4 work; GPU implementation remains at the presentation boundary.

Audit every authored script record and dynamic selection rule in the supported corpus, not only prefixes before the first unsupported instruction. Build the bank/context matrix for all 166 rooms and five scenario EVBs. A bank need not execute in a context the game never uses, but every such exclusion must have caller evidence. Add dynamically selected resources, actions and callbacks to the same ledger.

Exit: all five scenario programs and every required room/context admit with concrete providers; required actor and AI handlers have actual callers; ordinary gameplay runs through native execution. Scene-dependent startup and progression also require Milestone 3. This remains an implementation milestone until the final playthrough matrix passes.

### Milestone 3 Complete room changes and cinematic lifecycles

Implement `591920`'s persistent resource reset/rebind and connect it to room replacement, actor/model lifetime, collision ownership and shared inventory. Preserve the requested-room cache publication and source-visible failure prefixes where they matter. Exercise rooms with positive object instances as well as the simpler zero-instance fixture.

Complete the `5ECF90` scene-entry lifecycle: descriptor merge, room material retirement/reload, `576F10` room effect startup, object-motion entry, resource2400 and scene text. Adopt the existing reset, model, actor/object, light, camera, projection, facial, speech and media owners in one application lifetime. Complete `5EB6D0` finish ordering, including I/O completion, streams, motion defaults, script reset, room setup, dialogue-bank refresh and per-primary finalization.

Resolve the outstanding asset/track cases using actual scene selection and original consumer behavior. Implement required behavior where reachable; document proven unused combinations separately. No invented model, disabled animation, guessed voice pairing or blanket successful missing-asset return may satisfy the gate.

Exercise entry, normal completion, skip, pause where supported, interrupted playback, room changes during teardown, source failures, retries and restoration of ordinary actors/control. Validate text/dialogue and inventory presentation through actual user-facing consumers, not only retained text buffers.

Exit: gameplay-to-cinematic-to-gameplay and room-away/return sequences retain correct state, restore control, retire old generations and do not leak tasks, voices, models or resources. Every required scene/content refusal is resolved.

### Milestone 4 Complete native saves and platform consumers

Implement semantic native session capture and restore for the game's supported save points. Preserve scenario selection, actor/inventory state, flags, progression, RNG/options and the task/script/timer continuation state required by each save route. Serialize stable IDs and values, reconstruct references transactionally, and validate inputs. Opaque guest-memory sections and the nine-hook adapter do not establish native World restoration.

Reuse the existing legacy codec/import evidence. Preserve supported legacy save compatibility and temporary-save semantics, including the scenario selector mapping. Locate the actual gameplay save trigger and test it through ordinary interaction; setting a test flag or saving only options is not acceptance. Implement durable host writes, replacement, error reporting and recovery without modifying the user's existing card during development tests.

Finish controller sampling, edge/repeat/remap behavior, focus loss, disconnect/reconnect, menu/gameplay ownership and supported input devices. Connect native audio/video play, pause, skip, finish, errors, real audio tick and joined teardown. Port remaining frontend/options/pause/save flows that still depend on translated gameplay code. Retain the existing launcher's user experience and helper build tools where they already work.

Exit: a fresh native process loads real saved gameplay and continues correctly; temporary-save consume/rewrite behavior works; corrupt/missing/write-failed saves recover; input and media controls work through the launcher candidate with no guest-state authority.

### Milestone 5 Complete native co-op integration

Begin implementation after playable offline gameplay exists. Reuse the existing transport where appropriate, and replace RAM/register/runtime-based world synchronization with typed events into the canonical World and Update. Implement authority checks, entity generations, outgoing drains, scene/resource events and room ownership transitions. Preserve account-free host/join, direct IP and LAN behavior.

Check two real processes and the supported party capacity. Cover joining/starting, movement, combat, damage, item exchange, shared triggers, room changes, cinematics, disconnect/timeouts and teardown. Exercise loss, duplication, reordering, stale entities and invalid or unauthorized messages. Distinguish state that must agree from local presentation state in comparisons.

Host-loss behavior must be defined and tested; adding seamless host migration is not required unless the supported product contract already promises it. Existing internet/NAT features must remain functional, but a new relay service or unrelated networking redesign is outside this implementation plan.

Exit: actual peers operate the native session without the old guest world adapter or a mandatory community-server account. A loopback protocol unit test alone does not satisfy co-op acceptance.

### Milestone 6 Integrate the final launcher candidate

Keep a private launcher candidate usable from Milestone 1 onward. At this milestone, export and link the complete native gameplay graph with the exact shipping toolchain, matching dependency libraries, runtime DLLs and production optimization/FP flags. Make native gameplay the selected path in that candidate; no developer-only hook selection should be needed to obtain the intended result.

Instrument missing-provider/refusal/fallback counts, simulation clocks, task lifetimes and selected gameplay entry with bounded diagnostics. Audit the gameplay dependency closure for R5900Context, PS2Runtime, RAM projection, original dispatch, guest kernel/RPC and generated gameplay bodies. A symbol scan is supporting evidence; review actual reachable calls and boundary ownership. Legitimate historical no-ops need source justification rather than being classified as missing implementations.

Remove obsolete Stage 4 adapters once their callers have migrated. Keep the separate remaining rendering/platform compatibility dependencies documented for stages 5 and 6. Rebuild from clean or fully identity-verified inputs so the candidate cannot pass by linking a stale historical archive. Record source, assets, toolchain, compile options, dependencies and executable identity.

Exit: the exact launcher/package path runs the integrated native game and is ready for the final acceptance matrix. Publication or changing the user's normal selected build is not implied by preparing and testing this candidate.

### Milestone 7 Complete final acceptance and close Stage 4

Run the complete matrix below on the final candidate. Fix failures and rerun the affected tests and dependency closure. A core scheduler, ABI, source-asset interpretation or state-layout change invalidates broader results and requires the corresponding broader rerun. A final isolated copy edit does not require replaying the game.

Write one final validation record tying each completion-ledger item and acceptance case to actual results. Preserve failures as diagnostic history, but only current passing evidence closes a requirement. Update the main plan and integration status only after all required entries are verified. Keep the PC awake.

## Testing cadence using the shipping compiler

Use the pinned LLVM/MinGW driver for required native tests, component integration, candidate builds and final acceptance. GCC is optional for a specific compiler-sensitive investigation or later portability work; do not rerun the whole suite on GCC automatically. Preserve the launcher's .NET and existing native-helper toolchains: this decision concerns the native game, not converting every build tool to Clang.

Keep production floating-point behavior and ABI settings aligned with the exported compile plan. Do not enable fast-math or change game timing to make tests faster. A diagnostic sanitizer configuration can supplement checks only if the pinned toolchain supports it; determine availability before making it a requirement. Native lifetime, bounds and stale-reference checks remain required independently of sanitizer support.

| When | Required checks | Work avoided |
| --- | --- | --- |
| Each implementation batch | Incremental compile of affected targets; focused behavioral/boundary regressions; the fast application smoke where relevant. Run small existing CTests freely when already built. | Full-game rebuild, GCC duplicate, whole VM oracle, new copies of every historical asset/source snapshot. |
| A subsystem becomes integrated | Its real owned-content cases, relevant original comparisons, failure/lifetime cases and affected callers in the actual native application. Batch a coherent set of commands or consumers in one run. | Repeating untouched subsystem qualification and rebuilding a large original fixture for every tiny helper. |
| A milestone or shared core changes | Broader native regression, affected integration routes and content admission. Scheduler/state/ABI changes expand the impacted set. | Automatic repetition merely because a document or test-count label changed. |
| Final candidate | Full required LLVM native suite, required original-comparison suites, complete content/context audit, real launcher/gameplay/save/co-op matrix and dependency audit on the recorded source/package. | Second-compiler duplication and unsupported-profile testing. |

Every required behavior must be checked; every possible integer, actor, room, RNG and difficulty combination does not need an exhaustive Cartesian product. Use equivalence classes, boundary values, mutation/lifetime cases, deterministic seeds and actual authored content. Retain exhaustive sweeps when the domain is cheap or a subtle arithmetic/dispatch rule warrants them. Reuse existing passing exhaustive proofs when their complete inputs are unchanged. Full final validation includes the required heavy suites once for the final source, with results reused only under a complete matching identity.

Select checks by what changed:

| Change | Minimum relevant validation | Escalation trigger |
| --- | --- | --- |
| Documentation or status correction | Check links and claims against recorded evidence. | No build or gameplay rerun unless source behavior also changed. |
| Test-fixture correction only | Rebuild/run that fixture and its affected owned cases; capture the new fixture identity. | A failure reveals a production defect or an unsupported required content path. Keep those separate from fixture repair. |
| Local gameplay handler | Focused independent behavior/reference cases, boundary/failure cases and its real application caller; refresh relevant content admission. | Shared state, scheduling, dispatch or provider contracts change. |
| Shared header, owner or lifetime | Incremental rebuild of every dependent target, affected original comparisons and caller/lifecycle cases. | ABI, scheduler, RNG/clock or serialization changes require a wider dependency-based regression. |
| Content importer or resource selection | Audit all affected authored records and dynamic selectors, plus malformed/missing inputs and application use. | New resource families or context-dependent branches expand the matrix. |
| Final gameplay integration/package | Full required LLVM suite, owned cases, required original comparisons and all final acceptance routes. | A final fix invalidates its dependent evidence; rerun that scope, expanding for core changes. |

For representative coverage, list the actual semantic branches first. Exercise every scenario, character ability, difficulty-specific rule, required room/context and resource family. Combine equivalent full-playthrough configurations and use targeted cases for the remaining branches; pairwise selection alone cannot prove a rare progression interaction. Keep complete cheap content scans. Do not sample away known failing assets, rare reachable callbacks, save corruption, reentrant close, or network authority/lifetime boundaries.

An original-body comparison is especially useful for arithmetic, dispatch, timing, RNG and mutation order. A modern native replacement does not have to reproduce retired PS2 buffer layouts, kernel calls or internal scheduling; qualify its game-facing contract and ownership instead, in accordance with the modernization direction. Record which check supplies independent evidence for each required behavior. Compilation, a matching implementation-shaped fixture and assertion totals are insufficient on their own.

Before final validation, classify each historical suite against the completion ledger: required gameplay behavior, supporting evidence for unchanged internals, or a retired/unsupported profile. Required behavior retains an independent check and its application acceptance case. A retired guest protocol or unused physical layout does not become a release requirement merely because an old exhaustive verifier exists. Record the reason and supporting caller evidence for every exclusion. This classification reduces redundant work without dropping supported gameplay. Final validation still runs the relevant complete native suite and required original comparisons, followed by actual launcher, scenario, save and co-op acceptance.

Keep tests independent enough to catch implementation mistakes: original comparisons where behavior is subtle, known expected game rules for modern replacements, and actual gameplay outcomes. Mirroring the same mistaken field mapping in both fixture and implementation does not establish correctness. For migrated systems, test observable behavior and native lifetime rather than reproducing unused PS2 padding, slots, callbacks or transfer protocols.

## Concrete ways to reduce implementation time

1. **Integrate complete paths early.** Each batch must remove a completion-ledger gap and connect to a real caller. Prefer finishing frame/action execution and scenario launch over adding more standalone helpers with no application user.
2. **Reuse the existing native graph.** Do not create second worlds, clocks, inventories, audio owners or model pools. Modernize complete boundaries where useful; original routines are evidence, not a mandatory one-function-at-a-time architecture.
3. **Use one compiler and one integration queue.** Stop routine GCC qualification. One integrator owns the shared current build and batches broad validation after coherent changes.
4. **Improve cache invalidation if timing justifies it.** The current global header digest can invalidate unrelated objects. Prefer incremental CMake/Ninja dependencies or per-translation-unit dependency manifests, retaining compiler, flags, target/sysroot, relevant headers/generated inputs and object hashes. Never reuse an object based only on its `.cpp` timestamp.
5. **Cache expensive oracle inputs as well as production objects.** Reuse compiled original/reference objects and split the large test translation unit into stable domain groups where measured compile cost warrants it. Keys must cover fixture sources, original bodies, transitive includes, compiler/options and all compiled-in data. Verify any cache change with an independent clean result before trusting it.
6. **Prepare assets once.** Cache validated immutable archive indexes and test corpora by identity. Retain manifests and relevant changed sources rather than copying entire trees per small task. Keep compiled-library and header versions coherent.
7. **Avoid concurrent source drift.** If multiple agents are used during implementation, assign separate files/domains or isolated worktrees/build directories. Shared interfaces and CMake registration have one owner. Freeze an integration source snapshot before long comparisons; queue later edits for the next cohort.
8. **Bound harness work.** Add timing and fix the largest measured cost in one initial optimization batch, then return to gameplay. Do not build a new testing framework merely to replace functioning receipts. Stop a tool change if it adds maintenance without a measured benefit.
9. **Use ordinary-input integration routes with state-based waits.** Reuse qualified launch/input helpers. Detect ready states and fail boundedly instead of accumulating long fixed sleeps. Headless execution accelerates development; actual presentation/input/audio remain final acceptance requirements.
10. **Keep one current status.** Update the completion ledger and a short milestone summary. Link existing evidence instead of writing another long narrative for every helper. Report implemented/integrated/verified separately and record the next concrete blocker.

Apply these changes in order: remove routine GCC duplication, reuse the incremental LLVM build, move from individual helpers to caller-connected batches, and use focused admission/handler checks during development. Optimize cache infrastructure only after those changes expose a measured remaining bottleneck. The existing warm VM receipt already reports 132/132 production-object cache hits; replacing that functioning cache is not the first priority. Use the lightweight current-bank admission probe when only command/provider coverage needs refreshing; use the large original VM comparison when interpreter, parser, control flow or affected behavior requires it.

Every batch should end with a reviewable change, its affected test results, the exact remaining integration blocker and an updated ledger entry. If a provider is missing, work on that dependency before accumulating more unrelated component milestones. Shared-header or ABI edits must be compiled into all affected libraries and executables before comparison results are accepted. Parallel workers may prepare independent changes, but one integrator controls shared interface edits, build inputs and evidence collection.

Removing the duplicate compiler can save roughly one of two equivalent compiler jobs, not half of total project time. Implementation, integration, content investigation and game acceptance remain. Set timing targets after Milestone 0 measures these categories; do not promise a finish date from commit counts or arithmetic-check totals.

Track a small time summary with each coherent batch: changed targets, production compile/link time, reference compile time, test execution time, investigation time and the newly closed application requirement. Reuse existing receipts for timings instead of creating another reporting system. Increase build parallelism only after checking available memory and measuring a representative batch; simultaneous agent builds can increase contention. Keep cheap regression checks running and optimize the largest observed repeated cost. A batch that produces only more standalone helpers or a fresh receipt without closing a required caller is a signal to change the work selection.

Measured examples from the current records make the first optimizations specific:

| Observation | Action |
| --- | --- |
| The text/object shared-header rebuild took 199.77 seconds and failed on a missing source registration; its later passing 14-test group took 2.61 seconds and the nine owned cases together took about 1.26 seconds. The final 1.16-second build was a no-work seal. | Register production units with their integration batch, batch shared-header edits, and retain the cheap tests. Do not mistake the no-work seal for a cold-build speedup. |
| The timed-text original and fixture took 6.06 and 5.55 seconds to compile, 0.22 seconds to link, and 0.33 seconds to execute 389,467 checks. | Reuse matching production archives and unchanged original objects; compile only changed fixture inputs. Removing most assertions would barely improve this iteration. |
| The analog worker reports roughly 36 seconds for a fresh 129-object isolated build versus 4–5 seconds for incremental driver/oracle rebuilds, with execution below one second. | Keep one configured development build per lane. Preserve receipts per run without creating a fresh native build for every failed case. These are worker-reported timings, not a complete multi-day performance profile. |

Reduce duplicate builds and equivalent combinations, not required behavior. Keep all cheap authored-content scans; select expensive playthrough combinations by documented semantic coverage. Do not remove the known failing analog case, partial-resource failures, stale/reentrant lifetime checks, real save recovery or network authority tests. Historical successful checks may be reused only when their relevant source, dependencies, compiler/options, fixtures and data match. Final package acceptance is still required.

If delegated implementation is later used, a useful split is one application/frame integrator, one script/action/AI lane and one room/cinematic/resource lane. Bring save/input/media and networking work into those lanes as their dependencies stabilize. Every lane delivers a caller-connected change and focused evidence; the integrator owns final package validation. The planning task itself does not launch agents or implementation.

## Final acceptance matrix

| Area | Required final evidence |
| --- | --- |
| Build and selection | Clean launcher-compatible build with the pinned LLVM toolchain; fresh package launch and cached relaunch; native session selected; complete source/dependency identity; no stale archive substitution. |
| Native execution | Required frame/action/script/AI/physics paths use native state. Zero unhandled required providers, unsupported required commands or silent guest-gameplay fallbacks. Review call paths as well as counters. |
| Full content | All 166 rooms and five scenario EVBs audited/imported in required contexts; actual assets and dynamically selected callbacks resolved. All required scene/model/motion/text/audio combinations supported. Every exclusion has evidence and does not remove supported gameplay. |
| Scenario completion | Complete all five scenarios through normal input on the native candidate, covering their distinct progression/puzzles/events/endings as applicable. Record branch-specific tests for alternate required routes; one completion per scenario does not cover every branch. |
| Characters and difficulty | Instantiate and exercise every supported player/companion/enemy family and character-specific ability. Check every difficulty-specific rule/asset branch with targeted cases; use a documented representative matrix for full playthrough combinations. |
| Frame and gameplay | Movement, collision/floors, combat, hit/recovery/death, inventory/item exchange, weapon families, interactions, AI cooperation/pathing, event/task order and RNG behavior. Verify game speed independent of display rate, load and pause. |
| Rooms and cinematics | Room changes and returns, positive movable-object rooms, queued/repeated cinematics, control restoration, camera/facial/object/lighting/text behavior, media completion/skip/error and retained-resource teardown. Include the previously unresolved asset families. |
| Input and UI | Real supported controllers/keyboard, remapping, focus loss, disconnect/reconnect, pause/options/inventory/dialogue/save UI and restored control. No global input injection needed by the product. |
| Saves and resume | Real supported save triggers, restart into saved gameplay, temporary-save/resume/rewrite, legacy import, options/progression persistence, corrupt/truncated/missing/write-failed save recovery. Compare semantic state and subsequent behavior; an options-only round trip is insufficient. |
| Media | Stage 3 ownership/lifetime regressions on the integrated graph; actual cues, voice/dialogue, pause/skip/end and room/cinematic transitions; no new starvation or timing regression. Keep known Stage 5 presentation limits explicit. |
| Co-op | Account-free host/join using actual peers, supported party capacity, shared gameplay/room/cinematic events, authority and stale-reference checks, disconnect/loss/reorder/duplicate/invalid-message cases and clean teardown. |
| Stability and shutdown | Repeated room/scene/session transitions, full-session exercise, resource-failure recovery, normal close during active work, joined workers and bounded steady-state resources. Set a workload and measurable limits before running; use occupancy/leak evidence rather than FPS alone. |
| Final review | Every required completion-ledger entry is verified against the final source. No remaining gameplay refusal is relabeled as Stage 5/6 work. Record the exact residual rendering/runtime dependencies and pass the final targeted reruns after fixes. |

The final result is a fully implemented and checked Stage 4 for the declared profile. A first playable room, high opcode coverage, a large assertion count, a passed save hook or an uninstalled library is an intermediate result and cannot close it.

The final validation record must identify the candidate source/package and compiler, map every required ledger entry to current passing evidence, list justified scope exclusions, and show zero unresolved required implementation or acceptance failures. If a test cannot run, a required device/peer is unavailable, or a reachable path still refuses, that requirement remains open. Do not substitute a planned test, a controlled fixture or a historical different-source pass for final acceptance.
