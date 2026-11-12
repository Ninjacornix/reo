# Native pose projectile callbacks and presets

Status: source comparisons and bounded native ownership contracts. Stage4 remains
incomplete; the installed game still uses the guest-backed gameplay owner. No game,
window, device or power action was used for this work.

The real64-slot `PoseWorkPool` now has typed callback policies for kinds6,12,15,17
and100. `RoomPoseProjectiles` composes6/12/15/100 with the canonical World, retained
room geometry, contact packets/catalog, trails and preset factory. Kind17 has
`RoomTimedPoseProjectiles`. These join the previously qualified callback families;
they do not supply the still-required terminal frame services or action providers.

## Source behavior retained

| Kind/source | Native behavior | Remaining reached capability |
|---|---|---|
|6 /583030|Initial floor cache, packet3/bank1, visible flight; source1.5 scaling truncates toward zero through its software-double conversion; retirement precedes sound7.|Non-null emitter57F990/57FAA0 attachments and actual1B9310 metadata/audio. Actual cleared24 is a known no-emission branch.|
|12 /5831E0|Aim from physical primary record0 through376EF0, initial packet1B and both trails; rotated integration, positive-Z velocity clamp; floor contact, sound7, four descriptor7 presets, then retirement.|Actual1B9310 sound consumer before the four canonical child allocations can complete.|
|15 /584250|Forward speed50, previous-position publication, basis-directed movement, deferred retirement and six actual contact rows.|Actual5DEF90 visual and6B25B0 light. Packed audio and contact packets reuse existing owners.6B25B0 is distinct from the ungated6B2760 timed light.|
|17 /583730|Literal normal/parent trajectories, parentCF2 variant, actual linked timing quantum, previous/current contact spheres, water-first floor queries and ordered trails.|ParentCF2 requires its real producer. Unknown parent state refuses after the reached phase prefix.|
|100 /584760|Initial visual allocation, literal movement and offset vectors, floor clamp, visual positioning and signed timer expiry.|Actual58DA20/shared168 visual lifetime and positioning owner. Missing allocation differs from known pool exhaustion.|

584250's recipient, surface and serial tests gate its sound only: a matching
variant still selects the row's contact descriptor.583730 always requests the
initial mode1 trail; only its mode0 request is conditional.5831E0 emits its four
presets before setting the stop bit and retiring.583030 uses the cached floor
on later calls and retires before its sound call. These distinctions are exercised
by full original-body comparisons, rather than inferred from callback names.

`PresetPoseWork` supplies582720's actual room gate, prepend allocation, packet
request and no-rollback behavior through the same pool. The packetless5828C0
variant shares the typed initializer. The admitted literal index profile is0..13;
this is not a claim about the original table's extent. Unknown indices refuse
after the reached active/category/slot prefix. Negative signed packet descriptors
remain full-width until the concrete catalog boundary, where they refuse instead
of wrapping. Known room mismatch and pool exhaustion remain normal no-effect
outcomes. The full native constructor gates have actual pool/catalog tests;
the original-body initializer cohort covers matching-room successful allocation.

The three appended `PoseWorkState` roles are `travel_speed` (F0 in584250),
`emitter_owner` (24 in582720/5828C0) and `follower_visual` (24 after58DA20).
These are typed family roles, not guest-address payloads. Existing canonical
collision spheres and surface fields are reused. The actual581FE0 clear covers
only1F0; it does not establish large ordinary-actor audio fields33/554. Native
archives are rebuilt or copied with their exact matching headers after the
state-layout change; historical archives are never overlaid with enlarged actors.

## Evidence

Every row below passes with GCC and LLVM. Each cohort freezes production code,
fixtures, helper surroundings and owned instruction words. Native production
contains no guest register context or RAM mirror. Original execution surroundings
are confined to the differential test programs.

| Cohort | Complete cases per compiler | Checks per compiler |
|---|---:|---:|
|`pose-ground-flight-*-v7`|262,144|2,065,624|
|`pose-timed-projectile-*-v4`|327,680|4,140,006|
|`pose-forward-projectile-*-v3`|327,680|2,819,119|
|`pose-surface-follower-*-v1`|262,144|2,129,927|
|`pose-presets-*-v1`|131,072|1,245,428|
|`pose-splitting-arc-*-v2`|262,144|3,276,899|

The sum is1,572,864 cases and15,677,003 checks per compiler. These are controlled
source comparisons, not elapsed game frames or a gameplay completion percentage.
Ordered native refusal tests cover every reached external action boundary.

`room-pose-projectiles-*-v2` adds419 checks per compiler against all six real
NBD/EF banks and imported room walls/floors, real packets and native pose/trail
owners. It checks cached-floor use, retirement before missing audio, non-null
emitter refusal, forward expiry/contact prefixes, missing follower ownership,
eight-frame splitting-arc flight, and preset index/packetless profiles. The graph
is copied from the exact current callback-v8 source/archive snapshot. Earlier
`pose-callbacks-current-*-v8` passes2,233 checks, six banks,380 cloud frames and
six room cases; it includes the timed projectile and real preset factory gates.
The final combined current graph also passes `pose-callbacks-current-*-v9`
(2,233 checks per compiler) and `room-pose-projectiles-current-*-v1` (419 checks
per compiler). Each captures821 source inputs and63 native archives, including
the latest registered dialogue and facial-owner interfaces. The qualification
seal is `tools/native_reconstruction/native_pose_projectiles_qualification_v1.json`.
The subsequent `dialogue-response-parents-*-v1` cohorts pass all30 current parent
contracts with both compilers and no source drift, including the new room-owner
and dialogue-worker targets. Their owned-archive dialogue-worker invocation
passes22 checks per compiler. These still do not select native gameplay in the
installed game.

Failed development cohorts are retained with their logs. In particular, the
source comparisons caught the unconditional mode1 trail and sound-only contact
gates described above. The first ground-flight candidates also exposed the
software-double truncation difference; native finite arithmetic preserves that
result without retaining the original software arithmetic runtime.

## Integration limits

The optional `PoseProjectileActions` interface is an explicit boundary for actual
shared visual/light owners. Missing implementations do not report successful
emissions. `ActorOffsetSound` still requires real actor sound metadata; the generic
native Actor and small pose clear cannot supply invented values. These are
remaining implementation tasks, along with shared168 visual admission/lifetimes,
delayed bursts, application worker adoption and complete native game acceptance.

No diagnostics setting, rendering path, VU selection or game clock was changed.
Continue through the ownership and acceptance gates in[STAGE4_PLAN.md](STAGE4_PLAN.md)
and[STAGE4_INTEGRATION_AUDIT.md](STAGE4_INTEGRATION_AUDIT.md).
