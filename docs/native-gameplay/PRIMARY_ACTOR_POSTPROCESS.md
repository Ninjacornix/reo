# Ordinary primary actor postprocessing

The original `66A3A0` pass is separate from common frame `66A2E0`. It visits
eight ordinary primary records, performs equipment/room work, applies surface
transitions, updates head/secondary poses, and then records local actor counters.
`PrimaryActorPostprocess` now implements that ordering against the canonical
World and scenario owners. Its reached equipment attack consumer remains an
explicit bound capability. This is not Stage 4 acceptance on its own.

`actor_scene_triggers.cpp` implements complete `581870`, including reached
`5C1710 -> 5C2F00`. It walks the actual shared `gameplay_scene::Records` newest
first and examines type `0x85` proxies. The proxy's `source` identity resolves
the original separate descriptor and its authored channel index. The existing
`SceneMatrixPrograms` owns the gate and interaction bytes. Original gate two,
integer polygon containment, and the exact lower/upper/200-unit height rules
admit work; the helper does not add activity, visibility, or record-enabled gates.
It stores the real actor identity on the selected proxy, marks the canonical
room flag halfword and actor auxiliary bit when the source gates admit them, and
writes the actual channel interaction byte. Foreign flags/record/room bindings
refuse. Existing record leases retain their old values across retirement.

`actor_surface_transition.cpp` implements complete `6660B0` with a real native
room `Grid` adapter. Contact bit two or a primary action other than one skips
the floor query. Otherwise it samples actor Y plus 50 and applies the literal
paired sixteen-entry tables at `711810`. Source behavior can map actions even
when the classified surface family is unchanged; those branches are retained.
The status `0x88` rollback, default-to-row-zero cases, action pose snapshot,
phase clearing, and separate `CE2` bit `0x20` write preserve source order.
The actual record-clear owner establishes zero `surface_transition_flags`;
generic actors retain an absent capability until their real producer supplies it.

`gameplay_events::CompletionState::actors` extends the existing canonical
scenario statistics owner with named counters rather than adding a second
mutable statistics block. Existing `Statistics::initialize` clears them through
its original reset. `actor_counters.cpp` preserves signed word to FP32 conversion,
absolute forward root motion, FP32 addition, truncation/saturation, wrapping
increments, status-bit priority, and the source health bins. Both middle health
intervals increment the same middle counter. The original zero/zero health ratio
falls through to the high bin in the admitted scalar surroundings. Uninitialized
statistics refuse counter publication.

Paired source comparisons are retained under `build-native-sjuni`:

* `actor-surface-transition-{gcc,llvm}-v2`: 221,184 complete `6660B0` cases,
  1,622,018 checks, 36,864 declared classified-floor observations, and actual
  original `667370` snapshots. The real Grid adapter also has an empty-room test.
* `actor-postprocess-counters-{gcc,llvm}-v1`: 65,543 complete `66A3A0` counter
  projections and 592,182 checks. Earlier non-counter calls are explicitly
  no-effect observation ports; actual locality and absolute-value bodies run.
  These cases isolate the counter tail and do not qualify its earlier work.
* `actor-scene-triggers-{gcc,llvm}-v3`: complete `581870`, reached dispatch and
  marker, integer polygon helpers, and locality helpers over actual native
  World, Records, channel and flag owners. The cohort covers 512 passes,
  59,908 checks, and 1,194 triggers.

All original source bodies are word-audited against pinned owned ELF/overlays.
Register, RAM and SIMD surroundings exist only in the test artifacts. Failed
earlier versions remain retained. This is finite native arithmetic evidence,
not a physical PS2 exceptional-arithmetic claim or a game execution result.

`primary_actor_postprocess.cpp` visits the eight live primary slots in order,
updates the original offline selected actor, clears auxiliary bit `0x80`, and
handles the status-bit-31 equipment request before its room gate. The known
zero-resource return clears the request without requiring an attack owner.
A nonzero resource requires an `ActorWeaponActions` instance bound to that
World. Its abstract interface supplies no successful default. The subsequent
scene, surface, head/secondary and local-statistics calls consume their actual
owners in source order. Missing reached ownership returns the failing identity
and preserves the completed prefix; the final offline selected-actor reset
occurs only after a completed pass. Invocation guards release on every return.

`primary-actor-postprocess-{gcc,llvm}-v7` execute the complete original
`66A3A0` body over the same eight-actor cohorts. Each compiler passes 61,726
checks over 544 complete passes, including 32 repeated-frame continuations,
1,752 controlled equipment-boundary calls, 993 classified-floor observations,
11 refusal proofs, and 4,361 retained-model lifetime checks. Sixteen original
bodies are word-audited, and all 184 source files remain unchanged during each
comparison. Real owned P00 skeletons, canonical Records, channel/flag owners,
imported native collision Grids, head resets, no-work secondary selections,
and statistics participate. The floor reference port returns the same Grid
classification; the original floor-classification implementation is not
requalified by this cohort. Nontrivial secondary dynamics and head tracking
retain their separate complete-body qualification.

The outer cohort deliberately declares the equipment attack as a controlled
boundary. Actual `65EC40`, including reached `65E750/65E880` attack consumers,
still needs its concrete bound owner. The native worker refuses that reached
work until supplied. The CMake `reo_native_actor_postprocess` target includes
both the actual scene-trigger and outer-worker implementations and passes a
fresh private GCC build.

The authoritative ordinary caller `5FED00` runs model passes `3769F0`,
`376AE0`, and `376B80` before `66A3A0`, then calls `6832F0`. Initial room
setup `5EB780` uses the same four-pass sequence. Integration must retain these
positions; `66A2E0` is a separate phase.

`gameplay_update::ActorPostprocessWorkers` adopts the worker at the existing
`Worker::primary_actor_postprocess` position in `Owner::run_workers`. It
constructs the actual pass from that exact Update owner's World, flags, and
completion statistics. The scene program must bind the same records, flags,
and room reference. Foreign or closed Update owners refuse. Remaining phases,
buttons and effects retain their explicitly supplied owner, and a reached
postprocess refusal propagates rather than being counted as completed work.
The last detailed report survives a failure and clears at the next queue-reset
phase or explicit adapter close.

The adapter's focused test executes 32 canonical Update traversals, verifies
model phases precede postprocessing and hit regions follow it, and observes
the shared statistics owner advance. It also checks foreign identity,
missing-attack refusal, known-zero continuation, report reset, owner close,
and retained actor lifetime. Other frame workers are declared test
surroundings; this does not qualify their gameplay behavior. The focused
fixture uses the already proved session-one head fast return and an unchanged
secondary selection. The complete outer cohort above checks real head resets
with owned model assets separately.

The original paired immutable CMake snapshots
`actor-postprocess-workers-{gcc,llvm}-v4` each pass 977 checks over those 32
canonical owner traversals at that checkpoint. The receipts retain their
complete source manifests and explicitly record concurrent changes to stream
channels and the separate model-worker adapter. Those unrelated changes are
outside this adoption proof; the combined current parent cohort verifies
their final composition. Earlier failed build snapshots remain retained.

The adapter now also owns the actual
[auxiliary postprocess](AUXILIARY_ACTOR_POSTPROCESS.md) stage and its dedicated
report. Its updated canonical fixture begins with the actual
[ordinary primary bootstrap](PRIMARY_ACTOR_RECORDS.md), traverses three real
auxiliary actors including an off-room node, and verifies inactive-node
refusal and the selected-primary room gate.

Paired immutable Release CMake snapshots
`actor-postprocess-workers-{gcc,llvm}-v5` each pass 1,079 combined worker
checks over 32 actual Update traversals and 17,115 bootstrap checks over 64
Worlds. The v2 adoption seal retains exact domain hashes and reports the
unrelated concurrent stream, cutscene and resource-owner changes instead of
claiming they were included in that immutable snapshot.
