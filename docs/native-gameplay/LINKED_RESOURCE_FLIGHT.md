# Linked resource flight and pose attachment

Status: implemented native components under current-application integration,
2026-11-12. Stage4 remains incomplete. No game or device was run for this work;
the installed game remains unchanged.

`LinkedResourceFlight` supplies complete583C50 through the canonical64-slot
`PoseWorkPool`, `Actor` and `SceneResources`/`ResourceModel`. There is no second
mutable trajectory or model pose. Phase0 copies the model's authored velocity
and angular increments, then falls through into the timer/contact/integration
step. Signed-halfword narrowing, clock-byte shifts, contact recipient tests,
literal double-cross response, horizontal damping, gravity and delayed stop
retain the original order. Timer expiry still integrates its last frame.
Missing linked models stop this work; foreign or retired capabilities refuse.

`ResourcePoseWork::attach` implements complete5822A0 in the same pool. Nullable
position and matrix leave the actual allocated zero record intact. Descriptor
and kind narrow independently to bytes, lifetime narrows to signed16, and the
descriptor is attached through actual `Catalog`/`Packets`. Allocation or packet
exhaustion does not invent an additional budget or roll back the constructor
prefix. Unsupported bank domains and missing definitions report unavailable.

`ResourceLinkedFlightEffects` supplies real retained-room floor616F20 queries,
bank0 packet attachment,5822A0 burst construction,6B2760 light construction and
packed actor sound. Unknown floor data never becomes a successful floor miss.
Required-provider failures preserve the already executed prefix and stop the
native continuation explicitly.

`TimedLights::create_ungated` implements6B2760/5D8620 over the existing scheduler
and primary light pool. It reuses the already qualified complete5D8630 curve;
the owned720300 template matches7202C0 byte for byte. Unlike6B2680, this entry
has no parent action gate and continues after initial-owner retirement. A full
task pool remains a normal no-effect result. A full light pool is reported and
its newly created task is released, preserving the documented native safeguard
against the original callback's null light write.

`PackedActorAudio` implements complete1BA5E0/1BA4C0/1B91E0/1B8BB0. It follows
exactly one category9 parent reference, retains event-zero distinctions and
randomization, and calls the existing bank/spatial owner with canonical RNG.
Category2/3 tags require an explicit real provider; their byte33 producer is
not guessed. Class routes with unassigned original registers remain unadmitted.
`PoseWeaponEffects` supplies the actual5823E0 firing effect and requires composed
consumers for other reached families.

Both LLVM and GCC pass the following immutable comparisons:

| Cohort | Observed checks and coverage |
| --- | --- |
| `packed-actor-audio-*-v3` |135,004 checks;18,432 full frontend cases;12,192 positional requests;1,179,648 mixed frames and16 nonzero sample values;three refusal groups|
| `linked-resource-flight-*-v1` |2,034,737 checks;262,144 complete583C50 cases;8,192 complete5822A0 constructors;45,460 ordered effect requests;five required-provider refusals|
| `linked-flight-owner-*-v1` |2,118,977 checks including the preceding policies;1,024 actual-owner cases;4,096 flight frames;8,576 actual light ticks;1,048,576 mixed frames;four owner refusal groups|
| `ungated-timed-light-*-v3` |5,503,362 checks;131,072 complete curve states;65,536 gated admissions;3,072 complete lifecycles;97,088 frames including2,048 ungated lifecycles through parent retirement|

The original functions and reached math bodies are instruction-audited against
the pinned owned executable/overlays. Tests use immutable native libraries with
their exact headers; later unrelated parent-header changes are recorded rather
than silently mixed. The timed-light oracle adds an explicit interior-entry
shim for5D8620's unconditional branch/two nops into its complete5D8630 body.
Earlier failed compiler/harness cohorts remain on disk.

The composed flight cohort uses actual owned room grids, converted contact
definitions and real `weapon01.snd`, explicitly bound for the test. Event0x12
produces matching **silent** output with that cue binding. This proves delivery
and PCM agreement for that input, not audible event0x12 playback or a proven
in-game actor-bank assignment. The separate packed frontend cohort demonstrates
nonzero PCM for admitted events.

Full pose service can reach kind20/5846C0 after a burst is constructed. That
consumer, other reached pose families, concrete behavior/phase terminals,
coherent application ownership and installed gameplay acceptance remain
required. The current owner cohort calls the concrete kind9 updater directly;
it does not claim those missing consumers succeeded.
