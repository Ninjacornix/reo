# Actual cinematic primary action dispatch

Status: bounded native67BE90/67BC90/67BE60/5D6D00 composition qualified on
both compilers; uninstalled. Step4 remains incomplete. Installed game stays V39.

The source call-order audit corrects the previous generic callback experiment:
`712C10[6]` selects67BE90 for the action-six secondary pass. It does not select
linked callback6BA880. `PrimaryCutsceneAction` now implements the actual primary/
NPC handler; `CutsceneActor` again admits only its linked category2 consumer.
Both reuse the counted movement/request helpers without merging their gates.

Cue0 resets action/substates, root delta and the canonical primary channels,
leaving the cue unchanged. The source clears twelve records; native Playback
owns five admitted channels and has no reserved seven-record tail. Secondary
channels and model curve bindings remain intact. Cue1 publishes visibility,
advances cue2 and clears action substates. **Both cue1 and cue2** execute the
request/timer/movement helper followed by selected animation. Other cues still
propagate auxiliary-status bit2 to contact bit40. The earlier static mapping
incorrectly described cue2 as animation-only; the mapping and documentation are
corrected using full original execution.

The first nonzero signed timer alone runs per call. Decrement wraps through its
16-bit representation; exact zero hands off the next duration. The paired-node
helper uses the actual ordinary/style endpoint constants, unsigned total duration
and ordered float arithmetic. It writes local Y at nodes24/26 only when model
kind0 and nonzero pause admit it. Missing required models and nonfinite arithmetic
fail visibly before timer decrement. This action has no outer pause/activity gate.
Its caller66A2E0 owns later root integration and actor-basis publication.

`primary-action-six-{llvm,gcc}-v3` execute complete owned bodies and existing
World/NPC/linked/event/descriptor comparisons. New coverage includes9,216 actual
primary handler calls,1,536 channel resets,6,144 composed timer calls and393,220
timer sweeps. The sweeps cover every signed16-bit remaining counter for all three
modes and both style tables, with every nonzero unsigned total represented.
Animation is disabled in those sweeps so it cannot overwrite and hide a wrong
offset. Sequential1/1/1 timers verify no same-call fallthrough. Missing-model,
channel, identity and wrong-family boundaries are explicit native refusals.
The primary packed-header lookup remains the declared bounded metadata identity
port; original packing, routing, curves, channel logic and arithmetic run.
Each final cohort passes10,454,734 checks with24,332,214 original calls.
All five dependent actor-asset, target-metric, cooperative-event, collision-worker
and AI-owner tests also pass on both compilers.

`primary-action-owner-{llvm,gcc}-v2` then execute112 actual temporary player
construction/model scopes:112 actual action resets and448 animation/root/basis
ticks, followed by bank cleanup, temporary generation reset, selected resource
release, canonical return and224 reinitializations. These pass150,804 checks.
Two genuinely detached Playback copies also reset their owned channels without
inventing a model, while subsequent required animation fails visibly. Motion
assignment is controlled by actual compatible clip cardinality; these tests do
not establish stock event actor/key mapping or the full traversal.

The static dispatch audit is `cinematic-actor-dispatch-audit-v1/receipt.json`.
Fourteen complete bodies and the actual dispatch/offset tables are pinned. In
particular,67C250 is unrelated face/matrix resource bookkeeping;5ECB80 is the
temporary model publication traversal.5ECAE0 calls secondary-link restoration
before common frames;5ECBE0 separately services reaction/secondary-pose work.
Those remaining owners, actual scene scheduling, all scene objects and installed
gameplay/save/co-op/shutdown acceptance are still required. No performance gain
or measured slowdown cause is inferred.

Combined evidence: `native_primary_cutscene_action_qualification_v1.json`.
