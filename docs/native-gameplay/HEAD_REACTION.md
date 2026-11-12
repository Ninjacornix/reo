# Humanoid head reactions

Status: qualified on both compilers; uninstalled. Stage4 remains incomplete.

The native head owner implements `67C100`, all seven `6613A0` modes,
`661160`, `661310`, `661110`, `376EF0`, and `65F0C0`. Its typed state belongs
to the canonical Actor. Targets are generation-checked World identities;
selection uses the existing TargetMetricCache and fifty-slot linked-model pool.
It does not keep a second actor layout or execute original instructions.

The source session gate is signed16 `session_state` (`324200`), separate from
World mode (`3243F2`). The animation gate at actor `211` is primary channel
one's timing flags, not a new actor mode. The shared scripted relation fields
and canonical health/status bytes remain their existing owners. The target node
at `552` is distinct from the metric point at `551`.

Head publication clamps pitch to +/-6143 and yaw to +/-8191, divides the
remaining signed displacement by the signed tick count, and preserves the
original narrowing and decrement order. It resets only the local matrix axes,
leaving sampled parameters, caches, translation, and fourth components intact.
The real `193260` rebuild includes the head's child and sibling branches, using
the parent scale. New immutable snapshots preserve old publication leases.

Several source quirks are deliberate. The third input angle to `661160` is
ignored in favor of the currently sampled head roll. Mode2's first call prepares
camera angles and returns after changing the mode; it does not publish them.
Its continuation changes only local axes and leaves world matrices untouched.
Retargeting clears the transition mode even when the second candidate differs.
Modes5/6 prepare authored default roll in their input angle records, but the
common transition helper still consumes sampled roll. These are source comparisons,
not proposed changes to game behavior.

`CinematicActorReactions` is the actual separate `5ECBE0` pass: eight temporary
players, then the auxiliary list, each gated by active and visible. Head work
precedes the existing `61A820` secondary pose owner. A missing required component
retains the completed prefix, identifies the failed actor, and releases traversal
guards. The ordinary head policy reproduces the head-selection portion of
`66A3A0`; `finish_ordinary_actor_reactions` composes it with secondary pose work.
The wider ordinary callback has separate prelude and statistics owners.

The primary storage clear `66A730` zeros all eight 0x10E0-byte records. The NPC
constructor grants cleared humanoid head state after the actual
`682D10` record clear, including the known-zero target node552. First primary
initialization establishes its head owner; later default/model reloads preserve
existing reaction state. Scene copies retain the independent typed Actor state.

The standalone qualifier is
`tools/native_reconstruction/animation/verify_head_reaction.py`. It word-audits
complete original bodies against the pinned File1 US ELF and owned o0/o2
overlays, seals transitive source copies, and runs the original bodies only in
test surroundings. Three actual skeletons supply head matrices and metadata.
The final direct-compile LLVM/GCC outputs are
`build-native-sjuni/head-reaction-{llvm,gcc}-v8/receipt.json`.

Each cohort passes 1,205,826 checks and 2,167,149 original calls. It covers
65,536 position-to-angle vectors, 768 transitions, 192 resets,
1,440 full mode updates, 672 scripted wrappers, 38,400 target queries over real
native primary/auxiliary/linked owners, 1,024 mode1 updates including RNG,
1,024 related-actor mode4 updates, and 64 complete cinematic passes. The 73,728
ordinary head choices execute complete `66A3A0` with explicit test-only prelude,
secondary, local-control, and head-call observation ports. That projection does
not qualify its wider callback effects. Cinematic comparisons execute actual
head work followed by the original character-zero secondary no-work branch;
secondary dynamics have their separate complete-body qualification.

The combined source and receipt seal is
`tools/native_reconstruction/native_head_reaction_qualification_v1.json`.
Both current CMake parent cohorts also pass all twelve selected tests without
source drift (`reaction-script-parents-{llvm,gcc}-v2`). These include primary/NPC
construction, independent scripted target-node state and retained leases, model
assets, World, target metrics, co-op, collision workers, AI and script regressions.

Earlier failed cohorts remain retained. They caught the initial mode2 return,
the retarget transition reset, and motion-class25's direct tracking branch;
only class2 applies the two selected-motion reset exceptions. Finite FP32
arithmetic, available published models, real target metadata, and explicit scene
camera input are required. Relation modes without an authored endpoint refuse.
Game installation, full scene scheduling, remaining enemy-specific target-node
producers, and whole Stage4 acceptance remain separate work. No game, renderer,
audio, input, device, or power action was used for this qualification.
