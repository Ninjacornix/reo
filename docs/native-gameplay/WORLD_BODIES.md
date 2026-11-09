# Canonical actor body registration and solve

`WorldBodies` is the native consumer of the already qualified body solver. The
real `MotionFrameServices` calls `finish_motion`, which registers native entity
identities. The original `5DA620` argument order matters: a1 is collision class,
a2 is the source mask. The native registration stores mask before class. The
usual motion call therefore registers class 1, mask 3; a nonselected online
player registers class 1, mask 0 and can still be another actor's target.

The adapter references the canonical actor's position, previous position,
direction, shape, priority, separation counter, contact byte, peer and summary.
It retains actual actor and model-pose leases through the solve. Unregistered
actors do not require model poses. Native auxiliary owners may supply additional
views while retaining their own leases for the synchronous call.

Before mutation it checks the roster again after all pose callbacks. A retired
identity never targets its replacement. Missing poses, stale registrations and
invalid joint profiles leave the bounded queue available for explicit recovery;
they do not trigger a legacy retry. Reentry cannot drain or mutate the active
queue. Registration capacity remains 32, including duplicate registrations.
Boundary ownership also uses a generation-qualified identity.

Both compiler cohorts pass 39 integration/lifetime checks, including the real
World frame and motion caller, the class/mask distinction, exact pause value 1,
queue exhaustion, callback reentry, callback exceptions, missing poses, missing
joints and retirement during pose acquisition. The underlying original solver
comparison remains the separate actor-view qualification. This adapter cohort
does not claim a new original-body comparison or a game installation.

Evidence: [World body consumer qualification](../../tools/native_reconstruction/native_gameplay_world_bodies_qualification_v1.json).

Native pose import and auxiliary-owner installation remain required. This
component alone does not close Stage 4.
