# Native NPC startup command consumers

Scenario commands80,81,88,89,8A,8B and8C now consume the canonical Session NPC
descriptors and AI registration owner. The enable commands share684010,
placement uses6841E0 and health/flag commands share6842B0. Command81 disables
the first matching descriptor and removes the first kind1 registration for
that descriptor index through complete681330.

The alias threshold is decimal200. IDs below200 pass directly. IDs200..207
read the Session's eight missing-character values and add200. Commands80/81/88
read full words. Commands89/8A/8B/8C read unsigned halfwords and ignore the upper
half of the payload word. Unknown alias indices refuse at Program admission.
The actual84 producer, including enemy-record remapping, remains open.

Command89 converts three signed integer coordinates to floats, narrows room
to a byte and yaw to a halfword. Command8A assigns eligible health and applies
mask40000000. Command8B applies40000008. Command8C applies80000010 for a nonzero
argument and40000010 for zero. All preserve first-disabled-match behavior.
An eligible template64 with control mode enabled requires known scenario state
before mutation. Its source-specific registration exemption applies to scenario1.

Both LLVM and GCC pass82,282,899 identical checks in the complete current
scenario cohort, including3,584 new ordinary/offline dispatches and19 refusals.
Comparisons exercise alias values across the full byte domain, duplicate
descriptors, enabled/inactive records, signed/unsigned payload handling, full
registration tables, preservation of pending control data and actual complete
original handler bodies. The earlier NPC imports, primitives and inventory
commands also pass. Seven parent integration tests pass under both compilers.

The actual Update worker test executes placement, health/flag changes,
parameterized enable, kind1 registration and aliased disable/unregister in one
native script. Its first fixture omitted the required second script channel.
Adding an idle channel completed that existing two-channel worker contract.
Evidence is sealed in `gameplay_scenario_qualification_v24.json`.
The ledger contains354 ordinary and326 offline bindings out of432, including
original no-op bindings.

NPC model/actor construction, the missing-character producer, enemy record
ownership, real scene startup orchestration and installed native gameplay
acceptance remain open. Installed gameplay remains V39 and Stage4 is incomplete.
These checks launched no game and measured no live performance change.
