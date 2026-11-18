# Directional proxy wait and timed hiding

Static File #1 US owned o2 analysis, 2026-11-05. Six complete catalogue bodies, including dispatch-local initializers; [identity](FUNCTION_INDEX.md). No game/process access. IDs/offsets hexadecimal; geometry and timer numerators decimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6A6AD0](../recomp/config/output_ovl/o2/o2_006A6AD0_0x6a6ad0.cpp) | `dispatch_directional_interaction_bank_and_initialize_motion_four` | High complete local mechanics | Sets54A8,taildispatch719790[byteA],noindexbound. Included6A6B00 incrementsA,clip4/0,activate,C37=1. NoC82write. |
| [o2 0x6A6B50](../recomp/config/output_ovl/o2/o2_006A6B50_0x6a6b50.cpp) | `turn_to_interaction_yaw_then_snap_full_goal_pose_and_advance_phase` | High complete local mechanics | Turn6AC130(signedlow16(wordAC8-signedyaw92),step80hex). CompletionincrementsA andcopiesD48/D4C/D50toXYZ. Always tick1. Unlike6A5EB0,positionisnotsteppedbeforeturncompletion;fullXYZsnapthenoccurs. |
| [o2 0x6A6BD0](../recomp/config/output_ovl/o2/o2_006A6BD0_0x6a6bd0.cpp) | `probe_forward_class_one_and_seed_directional_motion_wait` | High complete local mechanics | Rotatedlocal(0,0,60)+XYZ,class1/radius50query5DC570;doesnotclearAB8/AB9first. AB8zero returns. AB8nonzero/AB9!=7 calls6A9490. AB9=7 incrementsA;D45=1 setsB1/clipC,-1 setsB2/clipE,otherB0/clip8;activate, E120/unsigned74F200,D7A1,32FF. Noanimationtickinthisbody. |
| [o2 0x6A6D50](../recomp/config/output_ovl/o2/o2_006A6D50_0x6a6d50.cpp) | `tick_directional_wait_and_expire_through_offset_endpoint_descriptor` | High complete local mechanics; phase-write intent unknown | 54AF/32FF/C94OR201,tick1,predecrementE. Expiry581B60((AD0+10hex)&FF):failure(7,2),kind0->6A9490,kindnonzero->6AC040(actor,node,(AD0+10)&FF). Waiting E>0 comparesB/D45 with exactAbytewrites below. No timer reseed. |
| [o2 0x6A6F60](../recomp/config/output_ovl/o2/o2_006A6F60_0x6a6f60.cpp) | `dispatch_timed_motion_zero_hiding_bank_and_initialize_countdown` | High complete local mechanics | Common54A1F,32FF,C94OR201,taildispatch7197A0[byteA]withoutbound. Included6A6FA0 incrementsA,E120/unsigned74F200,clip0/0,activate. Doesnotexplicitlysetvisible1. |
| [o2 0x6A7000](../recomp/config/output_ovl/o2/o2_006A7000_0x6a7000.cpp) | `advance_motion_and_hide_only_when_positive_countdown_crosses_zero` | High complete local mechanics | Tick1;initialsignedE<=0 returnswithoutvisibilitywrite. Otherwisedecrement/narrow/store;postE<=0clearsbyte1. No phase advance/reseed. Aninitialzeroisnotthesameasacountdowncrossingzero. |

6A6D50's still-waiting writes are to actor **A**, not B. They remain literal rather than being silently corrected into a presumed direction cache:

| Existing B | D45 condition | Actual action |
| --- | --- | --- |
|0|1|A=1,clipC/activate|
|0|-1|A=2,clipE/activate|
|1|0|A=0,clip8/activate|
|1|-1|A=2,clipE/activate|
|2|0|A=0,clip8/activate|
|2|1|A=1,clipC/activate|
|0/1/2|other signedD45|Nochange|
|otherB|any|Nochange|

NoneofthesewaitingbranchesupdatesB. BecauseAisalsousedby719790dispatch,thewritescanselectadifferentphaseonthenextinvocation;exactgameplayintentrequiresmoreevidence,notanassumedbugfix.

Owned719790[4]={6A6B00,6A6B50,6A6BD0,6A6D50},16bytes SHA-256`232b093cfda3b32fa5ffa2baf36fdc9e77bb88b29c7122cd7338ab73cf445a94`.7197A0[2]={6A6FA0,6A7000},8bytes hash`5bbc0b39e88918730d1650d6d610ad5639a0fecd3558e977edb6160526c5d2ae`. These physical windows do not supply missing runtime indexadmission.

[Proxy query/unpack](SYMBOLS_LINKED_INTERACTION_PROXY_QUERIES.md), [motion/route publication](SYMBOLS_ACTOR_MOTION_RESPONSE_INCLINE.md), [turn helper](SYMBOLS_ACTOR_ACTION_ADMISSION_TURN.md), and [authority fallback](SYMBOLS_ACTOR_RESPONSE_TIMERS_AUTHORITY.md) closecalleecontracts.6A6BD0retainingoldAB8/9beforequeryisobservedmechanics,notproofthatqueryleavesstaledataorofanyruntimeincident. Timerarithmetickeepssigned16narrowingandoriginalunguardedunsigneddivisor. No testedfixornewmeasurementclaimed.
