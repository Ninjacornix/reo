# Native behavior activity publication

Status: qualified native composition on both compilers; uninstalled. Stage4
remains incomplete. InstalledV39 is unchanged; no game/audio device was launched.

`BehaviorFrameServices` now accepts the actual borrowed UpdateOwner as its
`ActivityPublication` consumer. At the existing66B500 activity stage,
`update_behavior` calls through that Owner into the real664F60 periodic gate
and selector2 publisher. It uses the canonical entity identity, session and
simulation clock. A foreign world, detached actor, retired actor lease or closed
Owner refuses. The Owner must outlive the adapter. Callers without this binding
still require their explicit activity provider; nothing silently succeeds.

Publication occurs after the primary action and before800000/auxiliary-status
cleanup, secondary action dispatch and attachment work. A message can observe
the new primary-action position and the earlier status bits. A missing gauge
or rejected sink stops the pass after the preceding mutations; it does not run
secondary dispatch, complete the World frame, roll back or retry through legacy
code. The original clock is read without adding an update. World still resets
the canonical744638 suppression word before each primary invocation.

The current source passes61,281,324 combined assertions on both compilers with
identical observations.481 native World/frame/behavior composition and direct
suppression cases produce eight actual state-sink observations. Five failure/
ownership groups cover sink refusal, missing gauge, foreign/detached actors,
retired leases and a closed Owner with a live replacement actor. The480 frame
cases span both modes, all60 valid clock subticks, pause and initial suppression
values. The standalone fallback byte deliberately contradicts the bound clock.
Other frame/action effects are declared providers; healthy actors leave every
health/hit effect unentered in this composition fixture.

A separate fresh comparison passes32,768 cases and2,572,551 ordered trace words
per compiler against complete original66B500 and actual666D60/666DB0/667370/
1B0310. That cohort keeps status/hit children as declared native fixture ports
and action/surface/effect frontiers as explicit providers, as before. It checks
the existing unbound constructor and behavior path; it does not claim full
transitive original action-body coverage. Both parent builds and all eight
integration tests per compiler pass.

Exact source/build identities: `native_actor_activity_binding_qualification_v1.json`.
The preceding actor-state qualification remains an immutable earlier checkpoint.
Gauge writers/import, remaining messages, other behavior frontiers, final
transport, semantic native World save/load, game installation and representative
acceptance remain Stage4 work.
