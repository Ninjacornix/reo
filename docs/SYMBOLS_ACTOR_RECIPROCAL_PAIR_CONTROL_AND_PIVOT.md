# Reciprocal pair control, animation and pivot placement

Static File #1 US, 2026-11-05. Two complete original o2 bodies reviewed with all delay slots and five complete dispatch tables. Addresses, states, flags, and offsets are hexadecimal; float values, yaw increments stated as decimal, and clock factors are decimal. No execution, build, attachment, live memory, input, or timing. This continues the [pair entry and pose correction](SYMBOLS_ACTOR_RECIPROCAL_PAIR_ENTRY_AND_POSE.md) and [control-request policy](SYMBOLS_ACTOR_RECIPROCAL_CONTROL_627770.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x62D550](../recomp/config/output_ovl/o2/o2_0062D550_0x62d550.cpp) | `play_and_position_reciprocal_actor_pair_states98_througha0_candidate` | High mechanics; candidate role | Primary-one states98..A0 share this body. Resolves partner, prefix54A1C, consumed reset restarts0. Null clears own BA080000 and base-cancels/blend0. Category!=1 partner must be primary1 with secondaryA3..AC (AD selects ownA2); other cases base-cancel/blend10. Category1 validates selected FCF and health, may reset partner0/AD toA3. Sets both BA080000. Phase0 visualself16/partner3B/D10self1/clears saved self transform falls into1;1 applies state-indexed paired descriptors after zero-step animation calls;2 advances both at state-specific speed. Every ordinary path then retargets pair positions and applies nodeD correction. Exact admission and tables below. |
| [o2 0x632B30](../recomp/config/output_ovl/o2/o2_00632B30_0x632b30.cpp) | `retarget_related_actor_pair_positions_around_yaw_pivot_candidate` | High mechanics; candidate role | Resolves partner without null guard. Saves pivot=selfXYZ+R(oldYaw)*(23.85,0,3.83). Depending secondary98..A0 and selfBA02000, applies wrapped yaw increment from owned table at original clock factor1/2, copies resulting yaw to partner. Rebuilds yaw basis, sets partnerXYZ=pivot+R(newYaw)*(9.36,0,-13.94), selfXYZ=pivot+R(newYaw)*(-23.85,0,-3.83). Preserves original single-precision matrix operations; does not independently advance animation or use root deltas. Exact numeric increments below. |

## Partner admission and reset order

Complete primary-one table slice712EB0..712ED3 contains nine identical62D550 targets for secondary98..A0, SHA256`536f783a97b924029da72b0506906e7d4ff6634feb8b93ec3e14b3f0978faf9b`. These ordinary callers keep the state-indexed local descriptor and speed selectors initialized. Direct callers with other states are not locally admitted into those table branches; their inherited-register behavior is not given a safe general contract.

Reset6673C0 clears phase0 rather than canceling. Null partner clears own BA0 mask80000 and base-cancels with blend0. A non-category1 partner must have primary1; otherwise base cancellation with blend10. SecondaryA3..AD indexes table73FE60: first ten entriesA3..AC proceed to62D8B0; last AD goes62D6AC, selecting own (1,A2,0,0)/snapshot. Out-of-range secondary base-cancels with blend10. Complete44-byte hash`a12e6a85e9eb840fca460419123c76d65f2c97878d99d9b4e6b6210d52a763d5`.

Category1 partners bypass that primary/secondary restriction. When self ID==selected4BADED, signed partnerFCF outside1/2 clears both BA080000, selects own action1/state0/phases0, snapshots/sends selector1, then normal base cancellation. Partner health544==0 separately clears both flags and base-cancels. Otherwise partner primary1 and secondary0/AD is rewritten toA3/A=B0 without a local partner snapshot/message. Other partner primary/actions are retained. Admitted ordinary execution ORs BA080000 on both.

## Local animation phases and owned tables

Phase0 sets visual54F16 for self,3B for partner, selfD10=1, clears own saved transform6673A0, increments phase1 and falls through. Phase1 increments to2 and selects descriptor indexes below. It first calls58C300(0) on self then partner, ORs track flags82 on both, applies self base710150 / partner base7101A0 +8*index with start0/blend10, and activates both banks. Phase2 calls animation on partner first, then self, at the speed below. Other phases skip animation selection/advance and continue postwork.

| Own secondary | Descriptor index for both | Phase2 speed |
| --- | --- | --- |
|98|0|1|
|99|4|1|
|9A|5|1|
|9B|2|1.2000000476837158|
|9C|2|1.2000000476837158|
|9D|2|1.2000000476837158|
|9E|3|1|
|9F|3|1|
|A0|3|1|

Complete descriptor-selector table73FE30..73FE53 targets62D95C,62D968,62D974,62D980,62D98C,62D998,62D9A4,62D9B0,62D9BC; hash`25b2a827ca5bd52b11c865f59690e249575f936e48554f5c5e66aa5abead1532`. Complete speed table73FE00..73FE23 targets62DA84,62DA94,62DAA4,62DAB4,62DAC0,62DACC,62DAD8,62DAE8,62DAF8; hash`6e6bc7224d93b78c9d8785423267160b2e06491ddcda18de95dacac932dd10e1`. Non-unit speed is literal float73FFB0 bits3F99999A, preserving original speed rather than an optimization.

After all ordinary phase paths, own secondary99/9A explicitly clears root deltas on both; other states retain them. It always calls632B30(self), then6328C0(self), even after selecting new descriptors in phase1. Early rejection paths skip this postwork. Neither helper's call count is a global game-update count.

## Pivot placement and turn table

632B30 creates an identity/yaw basis through18FDF0/o0 370320 and rotates local vectors through191A40. It captures the pivot using the old yaw before modifying yaw, then rebuilds the basis from the new yaw to position each actor. World XYZ stores occur for both actors; partner yaw is overwritten with self's new yaw. Y offsets are0, so partner's final Y becomes the captured self Y. The caller's earlier partner Y is not automatically preserved here.

Clock factorq is1 for3243CC==0,2 otherwise. All yaw differences below are decimal units multiplied byq and narrowed to signed16 before addition/subtraction:

| State | BA02000 clear | BA02000 set |
| --- | --- | --- |
|98|0|0|
|99|-204|-204|
|9A|+204|+204|
|9B|0|0|
|9C|-128|-384|
|9D|+128|+384|
|9E|0|0|
|9F|-96|-288|
|A0|+96|+288|

Complete clear-flag table73FF20..73FF43 targets632E64,632D78,632DA8,632E64,632DD8,632DF8,632E64,632E18,632E40; hash`1d91d372a5c34497766b4bf72224ffddd471e386c7f0b553e1498e15111ab454`. Complete set-flag table73FF50..73FF73 targets632E64,632C4C,632C7C,632E64,632CAC,632CD4,632E64,632CFC,632D24; hash`f4bcfef6cc399c44ba1ab61f653eaa54b6cfc7e1621c247f0e882addd10a06d4`.

Owned scalar window73FF78..73FFA3 has float words(-3.83,0,-23.85,0,-13.94,0,9.36,0,3.83,0,23.85), rounded here to two decimal places. Full44-byte hash`760eecf824dab5e62fd0ec93fd138b141a261b8bab79c5fa42fe0cfdc01d775d`. The six live scalar reads retain original float bits; host rounded constants or a direct trigonometric shortcut are not established as equivalent.

The pivot helper has no local null guard. 62D550's resolved partner is checked, but632B30 resolves again; broader link lifetime/concurrency invariants are outside this static pass. No null mutation, crash, performance bottleneck, or controlled fix has been observed. Original action names, pair pivot physical intent and runtime frequency remain unknown. Owned o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Full owned-body audit: 646 original words verified; 33 omitted words all zero/NOP. Zero conflicts or omitted nonzero words.
