# Native zero-health entry and behavior consumers

Status: qualified on both compilers; uninstalled. Stage4 is incomplete.
InstalledV39 is unchanged. No game or physical audio device was launched.

The separate65FBA0 entry now lives beside65FCB0 in `ActorRecovery`. It reuses
canonical `response_flags` at143 rather than inventing another flag byte.
Status800 or response-flag8 sets40000800, transfers inventory, selects action4/0
with motion-classA0, captures the low-byte caller phase and action pose, publishes
the actual full snapshot and transfers inventory again. Otherwise it clearsA8,
sets18, selects1/60 with the low-byte phase, snapshots and publishes. Neither
branch adds a UI or animation requirement that the original does not have.

The existing6607D0 status core has an optional typed effect owner. Without it,
the previous required StatusServices callbacks retain their original behavior.
With it, cleanup, snapshot and65FBA0 entry use real native inventory/pose/message
consumers. `ActorRecovery::apply_zero_health` validates the exact canonical World,
Actor and Session before calling that same status core. BehaviorFrameServices
can bind it at the actual zero-health stage, before pending hits and progression.
Foreign worlds, detached actors and closed owners refuse visibly. There is no
copy of the original actor layout or successful fallback after partial effects.

Both compilers pass930,875,421 combined assertions with identical observations.
There are40,960 complete65FBA0 cases and40,960 complete6607D0 cases across all
five owned item banks,80 enabled full-state messages and16 actual primary/
shared-secondary model retirement cases. All90,899 source allocations/releases
balance across the combined suite.

Three native World/frame/behavior compositions bind the real zero-health,
pending-hit gauge, progression, terminal timing and later action7 consumers.
Other actions/frame effects and transition selector5 remain declared providers.
A rejected early snapshot retains the completed transition and inventory;
a rejected later notice retains its pending flag after subsequent behavior.
Twenty-five refusal groups cover delivery, foreign bindings, identity and
shutdown. Fresh original status regressions pass163,840 cases/189,996 ordered
trace words/32,768 RNG requests; behavior passes32,768 cases/2,572,551 trace words
per compiler. Both parent builds and all eight integration tests per compiler
pass. Evidence: `native_actor_zero_health_qualification_v1.json`.

The first fixture had an ambiguous sink name and compared unused descriptor/
gauge cells without matching initialization. Corrected controlled fixtures seed
those inputs explicitly; production retains its unknown-state admission.
Failed and canceled cohorts are preserved. Other actions, actual UI/transport,
state initialization, semantic native saves and representative game installation
remain open.
