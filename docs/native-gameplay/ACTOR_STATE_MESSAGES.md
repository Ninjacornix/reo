# Native actor state and periodic publication

Status: qualified on both compilers; uninstalled. Stage4 remains incomplete.
InstalledV39 is unchanged. No game, physical audio device or window/input action
ran in this checkpoint.

Selector2 now uses the common actor authority/suppression gate and dispatch
owner. It first updates status08000000 from the complete664D00 primary/substate
classification, then captures rawXYZ, status, signed yaw and the selected
player's gauge band. Its declared length is24 and dispatch mode is2, unlike
the earlier messages' mode4. Unknown trailing stack padding is omitted; the
typed native object is not a packed wire format.

The gauge is originalBAC, independently owned by the selected primary rather
than necessarily the actor being published. Its value is optional; a missing
producer/import cannot quietly become zero. Native667F90 uses the eight audited
File#1 US71ADB0 denominators and preserves unsigned-to-float sticky-bit rounding,
division and multiplication order. Native668C80 retains the50/80/90 thresholds.
Other character profiles, missing actors and absent values refuse. The earlier
08000000 mutation remains committed when this later capability is unavailable.
This work does not assign speculative original names to substates or the gauge.

The actual664F60 periodic caller checks pause, clock-byte modulo30, selected
slot and its narrower substate set before reaching selector2. The Owner facade
reads its real bound simulation clock, not the standalone session fallback
byte or a host/presentation timer. It neither adds updates nor changes speed.
The outer66B500 caller's `BehaviorStage::activity_notice` binding remains open;
this qualification does not claim that the live game invokes this facade.

Both compilers pass61,277,948 combined assertions with identical observations:
589,824 direct state-message cases,131,072 periodic cases,65,536 classification
pairs,1,049,104 gauge cases,231,652 message observations,116,869 room lookups,
nine refusal/lifecycle groups and60 actual bound-clock cases. Percentage tests
include every low16-bit value, dispersed full unsigned values, high-bit rounding
boundaries and stock threshold neighborhoods for all eight profiles. Message
tests include raw floating-point payload bits, distinct selected owners,
callback mutation, authority/suppression gates and changed dispatch routes.
Previous health/action/inventory observations remain unchanged. Both parent
builds and all eight integration tests per compiler pass.

Evidence: `native_actor_state_message_qualification_v1.json`. Full original
664D00/664F60/667F90/668C80 bodies execute, with owned instruction-word audits;
the32 denominator bytes match the pinned overlay. The test-only register
surroundings add HI/LO to execute the periodic caller's integer division.
Final room-owner/message sinks remain declared ports. These finite host-float
comparisons do not qualify exceptional physicalPS2 floating-point behavior.

Nine of sixteen actor branches are admitted, including two intentional
no-message cases. Selectors1/3/5/6/8/9/11, gauge writers/import, outer behavior
binding, final transport and semantic native World save/load remain open.
Coherent game installation and representative acceptance are still required.

Follow-up: [behavior activity publication](ACTOR_ACTIVITY_PUBLICATION.md) now
binds that outer activity stage through the native World/frame/behavior and
UpdateOwner. The earlier qualification above remains unchanged; the game itself
is still onV39 and has not installed this composition.
