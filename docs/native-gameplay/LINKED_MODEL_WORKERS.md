# Native linked model worker adoption

`gameplay_update::LinkedModelWorkers` now adopts the actual376B80 model pass
at Worker::scenario_model_poses. It composes with the existing PhaseServices
chain, canonical Update Owner and actual World pool. Unrelated workers and
phase effects retain required providers; this is not a completed scene loop.

The layer owns the root selection/observation state, concrete File1 correction
scales and an immutable floor-grid lease. A World admits one such model-worker
owner. Duplicate bindings, missing floors, closed/foreign Update owners and
stale roots refuse. Closure releases the registration so a replacement owner
can bind. A failed pass retains its preceding effects, reports failed progress
and clears its result; there is no successful legacy retry.

Ordinary Update resets last-pass evidence at the start of workers. A cinematic
pause skips the actual model stage, leaving progress never_run and no fresh
result. Explicit cinematic callers may invoke this same stage after their
actor callback pass. Native pose snapshots are published by the actual model
owner; invoking the actor callback alone is not a pose-publication claim.

Both compiler owned-asset cohorts pass13,265 checks. They retain all89 native
motion member reads,750 raw block slots and128 original loader routing cases.
Sixteen actual native constructed-actor updates use the new worker to publish
real model snapshots. A further ordinary Update runs the bound actor and model
passes at their real positions; its paused predecessor skips the model pass
and clears previous evidence. Worker contracts cover duplicate/foreign/closed
ownership, forwarding of remaining phase operations, stale roots, missing
models, failed-result clearing, registration replacement and joined closure.
The initial ordinary-worker fixture omitted its required scenario identity;
statistics initialization refused it. The fixture now supplies that actual
producer state before running workers.

Fresh original model comparisons pass195,138 checks per compiler:256 passes,
426 visible actors including212 inactive-visible actors,298 corrections,
18 dependent root copies,816 pool cases and41,856 joints. They execute1,526,661
original calls. Current original worker/outer phase regressions also pass on
both compilers:2,048 worker cases and4,096 phase cases. Required child/effect
ports remain declared in that ordering fixture. All six parent CTest entries
pass on each compiler.

The old original-comparison source list lacked the recently added material,
linked actor, scripted animation and surface dependencies. Its current native
closure now includes them, and the model comparison likewise includes current
World/Session/AI dependencies plus the current SDK conversion header. These
are reproducible current-source comparisons, with no private-header fallback.

Reproduce the asset/worker composition with verify_scripted_motion_assets.py,
the model comparison with animation/verify_linked_models.py and the outer
ordering comparison with verify_gameplay_update.py, explicit compilers and
fresh output directories. The source/build/evidence seal is
native_linked_model_workers_qualification_v1.json.

Actual cutscene phase/lifecycle callers, authored root selection, remaining
worker families and game installation remain open. No game was launched or
speedup measured. Step4 remains incomplete and the PC stays awake.
