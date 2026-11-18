# Native update collision workers

`CollisionWorkers` replaces the native update owner's body-shape and
collision-height service calls with the canonical native body queue and ordered
height pass. Other worker, UI and phase effects remain explicit required owners.
The same adapter works with `run_workers` and the outer `advance` interface.

Scene participants are acquired at each phase after earlier scripts and actor
updates. Additional body frames retain actual actor and pose leases. Height
frames retain auxiliary actors and secondary entity owners alongside their
borrowed component views. A missing secondary lease refuses admission. Geometry
remains owned by the native scene provider for the synchronous invocation.
The adapter rejects a foreign World or a queue belonging to another World.

The real composition is: World updates native local motion and pose, motion
finish registers bodies, the update worker resolves bodies, then primary,
auxiliary and secondary collision heights run. A failed acquisition cannot
reuse an earlier successful report. Body failure also clears the previous
height report, since this invocation did not reach that phase. Exceptions and
partial native failures propagate; owner guards release without rollback or a
legacy retry. Callers must choose explicit recovery for retained queue work.

Both sealed compiler cohorts pass 117 checks using the actual native World,
motion/shape interpolation, polynomial pose rebuild, Grid orientation provider,
body queue, height pass, secondary floor solver, scheduler and update owner.
The auxiliary and secondary actors are acquired from a real native EntityStore.
Checks cover actual body contacts, phase order, independent simulation clock,
leases, acquisition failure, missing leases, explicit recovery, report freshness
and foreign-owner refusal. The remaining behavior and secondary wall effects
are declared fixtures. This cohort executes no original bodies; it composes
components whose source comparisons are recorded separately.

The scenario dependency is explicitly pinned to `cb57fa18` while model bindings
are developed independently. Both private snapshots and binaries are retained
by the [worker qualification](../../tools/native_reconstruction/native_gameplay_collision_workers_qualification_v1.json).
Reproduce with `verify_collision_workers.py --compiler ... --scenario-ref
cb57fa18 --output NEW_PRIVATE_DIRECTORY`.

An earlier integration fixture yielded without establishing a saved script
position and failed its next tick before collision. The corrected fixture uses
an actual begin/yield loop. This was a test-content error, not a game incident.
The whole native gameplay candidate and representative game acceptance remain
Stage 4 requirements. No game was launched by this cohort.
