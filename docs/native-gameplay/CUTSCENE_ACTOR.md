# Native cutscene actor displacement and pose

`gameplay_world::CutsceneActor` now supplies the admitted6BA880 callback using
the actual canonical Actor, ScriptedActorMotion, local-motion integration and
GridSurfaceOrientation owners. The native implementation stores no original
callback, guest pointer, register context or matrix scratch arena.

The callback runs only with nonzero cinematic pause, primary state6 and cue
phase1/2. Cue phase1 enables visibility and advances to2. Request mask2 selects
secondary23hex and resets the action/request phases. Zero scale-lockB41 enables
the local-motion scale mask. Counted displacement rotates a local forward step
through the existing exact native Euler implementation, adds it to position,
wraps the actor's yaw to16 bits and decrements the32-bit movement count. Exact
zero clears its step, angles and full yaw-step word. Other counter bit patterns
retain the source wrapping/decrement behavior.

Only secondary23hex invokes scripted motion, root-delta integration and pose
rebuilding, in that order. These are concrete native consumers. The pose owner
borrows a native floor grid. Its known unused branch needs no fabricated floor
result. A missing live actor, incompatible typed state, foreign motion owner or
closed World fails visibly. A zero cinematic-pause gate consumes no actor.

Both LLVM and GCC pass1,357,479 World checks and execute7,030,323 original calls.
New cases compare2,304 full callback invocations and3,072 gate combinations,
including all256 cue-phase patterns, all cinematic-pause byte values in the
composed cases, request consumption, visibility, counted movement, signed
angles, wrapped yaw, exact-zero cleanup, motion sampling/root deltas, all pose
axes/translation and forward direction. The composed cases use actual imported
motion/skeleton assets plus the qualified controlled multiple-track container.
Three explicit owner/identity/closure refusals also pass.

The source floor617000 entry is an unexecuted refusal boundary in this fixture.
The composed actors have no requested surface-orientation flag, so this proves
that real no-floor branch. Requested-floor numerical behavior remains covered
by the separate surface-orientation qualifications; actual affected-room
composition and rendering are not claimed here.

Current full scenario comparisons pass425,306,758 checks on each compiler.
The owned asset/construction cohorts and five parent gameplay tests also pass.
Evidence identities are recorded in
`tools/native_reconstruction/native_cutscene_actor_qualification_v1.json`.
Reproduce with the World animation and full scenario verifiers, owned asset
verifier and corresponding native CTest entries, always using fresh output
directories. No game was launched or new speedup measured.

Scheduling remains a separate gate. Ordinary Update workers stop on cinematic
pause; this callback requires that state. Source6BBBA0 performs the linked actor
callback traversal and conditionally rebuilds the pose again afterward. Its
one-time376DB0 operation transforms local collision center1AC through basis50
into previous-center cache1CC; it is collision state, not a shadow renderer.
The pass also owns expiry records and transient fields. Those real caller and
scene lifecycle owners must adopt this callback before game installation.
Step4 remains incomplete.
