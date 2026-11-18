# Native canonical actor behavior consumer

`gameplay_world::update_behavior` operates on the same `Actor` and `Session`
used by primary-frame orchestration, health/status, pending hits and input.
`BehaviorFrameServices` is the primary-frame consumer: it intercepts that one
stage, calls native behavior directly, and forwards the remaining required frame
operations to their explicit owners. No generated function or guest RAM bridge
is used by this composition. Hit-timer content is retained by value.

The native flow preserves the two surface calls before transform history is
captured, category-zero saturating invocation counters, pause/selected-authority
gates, shared previous-action snapshots, status/zero-health/hit order, modal
inventory suppression of primary action dispatch, callback-visible action
changes, transition notices and secondary action dispatch. Nonzero actor
categories bypass the initial pause/authority gate but skip the player-control
and primary-dispatch block. Secondary dispatch has its own room/pause gate.
Attachment updates reread status after synchronous providers.

Status timers, zero-health action selection and pending hits call their already
qualified native cores. Surface resolution, progression, interaction, terminal
timers, control/cooperation, individual action bodies and attachment effects
remain required providers. Missing required actions must fail visibly. There is
no default-success implementation, rollback or legacy fallback after effects.
Borrowed effect/frame owners must outlive the synchronous adapter.

Both compilers pass 32,768 comparisons against the complete owned `66B500` body,
plus actual `666D60`, `666DB0` and `1B0310` bodies, covering 2,573,649 ordered
trace words per compiler. Health/status/hit children are **declared native
fixture ports in this cohort**, independently qualified by their earlier full
original-body comparisons. Action table destinations and surface/effect calls
are declared fixture providers; this does not claim their bodies were executed.
The frame-composition check verifies the original behavior callback is bypassed
while the remaining frame ports run and canonical actor counters change.
The canonical world regression separately passes 4,096 original frame/input
comparisons and 75 lifetime checks on both compilers after this composition.

Qualification: [native actor behavior](../../tools/native_reconstruction/native_gameplay_behavior_qualification_v1.json).
The first failed build caught fixture warnings and aggregate construction; a
second successful comparison had a receipt-field bookkeeping error. Retained
final cohorts pass without weakening production compiler warnings. These are
development-harness findings, not observed game incidents.

This native library composition is not installed in V39. That candidate only
selects the nine native save/session hooks beside Stage 3 media. Full action and
surface providers, inventory, other actor families and coherent native gameplay
acceptance remain Stage 4 work.

The subsequent surface cohort removes both surface providers when the frame
adapter receives a native floor owner. `sample_surface` and `resolve_surface`
mutate the same actor directly, retaining type/material/attributes/normal,
sample-height admission, source Y+50/Y+1000 queries, Y+160 fallback, movement
disable and special-status transform rollback. The older constructor retains
explicit required surface providers for profiles without a floor owner; it does
not invent successful geometry. The borrowed native floor must outlive the
adapter. This does not change a game build's selection or original game speed.

Both compilers pass 16,384 surface comparisons against complete original
666580/666450/616ED0/616F20, using the separately-qualified native Grid query
as the declared617000 provider. There are3129special-surface and2331transform
rollback cases per compiler. Synthetic admitted room grids exercise the policy;
they are not a new retail-room performance measurement. The unchanged floor
policy rejects type-bit80 records even for required-type81; the surprising
sample request is preserved, without inventing its gameplay purpose. Existing
valid sample state is independently exercised by resolve-only cases.

Fresh behavior and canonical-world regressions pass after the floor integration.
The frame-composition check supplies a native empty floor and confirms behavior
executes without calling the old surface effects. Qualification:
[native surface composition](../../tools/native_reconstruction/native_gameplay_surfaces_qualification_v1.json).

The subsequent action-snapshot cohort replaces the direct phase-FF snapshot
provider with native `save_action_pose`. Its original `667370` body executes
alongside the complete behavior body; position D94 and yaw DA0 are compared,
including preservation when no snapshot occurs. Both compilers pass 32,768
cases and 2,562,408 ordered trace words. Status/hit child effects retain their
separate declared provider scope. Evidence:
[behavior qualification v2](../../tools/native_reconstruction/native_gameplay_behavior_qualification_v2.json).

The subsequent [activity-publication composition](ACTOR_ACTIVITY_PUBLICATION.md)
replaces the activity provider when supplied the actual native UpdateOwner.
It invokes the real periodic/state publisher through the canonical actor and
clock, preserving partial failure before secondary action dispatch. The same
current behavior still compares against the complete original on both compilers.
Other behavior providers and game installation remain open.

The [pending-hit gauge consumer](ACTOR_HIT_GAUGE.md) subsequently binds actual
gauge mutation through the UpdateOwner and moves D28 cleanup onto the same actor
counter used here. Other hit effects and periodic progression remain explicit.
