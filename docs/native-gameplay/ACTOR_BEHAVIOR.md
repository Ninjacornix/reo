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
