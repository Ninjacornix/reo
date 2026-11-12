# Ordinary primary actor postprocessing

The original `66A3A0` pass is separate from common frame `66A2E0`. It visits
eight ordinary primary records, performs equipment/room work, applies surface
transitions, updates head/secondary poses, and then records local actor counters.
The complete pass is being integrated; the following concrete prerequisites are
implemented and independently checked. They do not constitute a full pass or
Stage 4 acceptance on their own.

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

The remaining full-pass integration must bind the actual equipment-use arm
`65EC40`, including reached `65E750/65E880` attack consumers, and call the
qualified head/secondary composition in its original position. It must not
substitute successful generic callbacks or insert this pass into `66A2E0`.
