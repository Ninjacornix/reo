# Scripted holds, sound gates and signed-distance sequences

Static File #1 US, 2026-11-05. Five complete original o2 bodies reviewed with all delay slots, literal descriptor data and distinct completion rules. Addresses, fields, masks and state IDs are hexadecimal; float values and elapsed/count values are decimal. No execution, build, attachment, live memory, input or timing. Original action names remain candidates.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x62FD30](../recomp/config/output_ovl/o2/o2_0062FD30_0x62fd30.cpp) | `play_visual37_descriptorf6_at_owned_speed_then_return_base_candidate` | High mechanics; candidate role | Primary-oneB7; no54A/32 prefix. Consumed reset base-cancels. Phase0 visual37/D10=1/snapshot/root clear falls into1. Phase1 sets2/flags82/710240 start0/blend10; no local bank activation. Phase2 advances atowned float73FFB0=1.2000000476837158; exact signed-byte result1 increments3. Phase3/FF base cancellation/blend10. Other phases hold after reset work. |
| [o2 0x630D30](../recomp/config/output_ovl/o2/o2_00630D30_0x630d30.cpp) | `play_visual3f_motion2034_and_emit_sound_at_class_frame_candidate` | High mechanics; candidate role | Primary-oneB8. Prefix54A1F; reset restarts0. Phase0 visual3F/D10=1/snapshot/root clear falls into1. Phase1 sets2/flags82, signedhalf motion71B930=2034 start0/blend10. Phase2 primary frame gate71B840+96*B99+24*B9B atstep1 can call1B8A10(actorXYZ,28); then advances at1, exact signed-byte result1 increments3. Phase3 base cancellation/blend10. No local bank activation after initial motion. |
| [o2 0x630EE0](../recomp/config/output_ovl/o2/o2_00630EE0_0x630ee0.cpp) | `align_scripted_target_wait_then_move_until_signed_root_distance_consumed_candidate` | High mechanics; candidate role | Primary-one61. Prefix54A D/32FF. Reset clears subphaseB, not phaseA. B0 visual38/D10=1/snapshot, target saved XZ/currentY/yaw, clearsA and calls alignmentmode0 once without consuming result. B1 continues until nonzero ->B2/visual40. B2 snaps targetXYZ/yaw,BA8=1/flags82/A0,C48=ACC,timerC=AEA;C0 selectsB4 directly,elseB3/motion2051 blend10/banks. B3 counts down signedC and advancesBA8;old0 selectsB4. B4 calls66C160, subtracts signed rootZ4EC from remainingC48, and ordered remainder<=0 base-cancels/blend10. No absolute-value conversion or animation-boundary exit added. |
| [o2 0x631120](../recomp/config/output_ovl/o2/o2_00631120_0x631120.cpp) | `hold_visual1e_secondary_descriptor_then_external_ff_release_candidate` | High mechanics; candidate role | Primary-one11. Saves B9B before reset; consumed reset base-cancels. Phase0 visual1E/D10=1/snapshot falls into1. Phase1 sets2/BA8=1, temporarilyB9B0 for2051/start0/blend-12, restoresclass then applies710290 atsame start/blend and activatesbanks. Phases2/3 advanceBA8 with no local completion exit. ExternalphaseFF sets4/BA8=1, same temporaryclass base setup and710298/start0/blend0, no local bank activation. Phase4 advances at1 then tests secondarytrack211 bit40 ->5. Phase5 requests2051/blend-18/banks and selects (1,0,1,0)/snapshot. |
| [o2 0x632730](../recomp/config/output_ovl/o2/o2_00632730_0x632730.cpp) | `play_visual42_descriptore3_at_unit_rate_then_return_base_candidate` | High mechanics; candidate role | Primary-one3C. No54A/32 prefix. Consumed reset base-cancels. Phase0 visual42/D10=1/snapshot increments1, no explicit root clear; falls into1. Phase1 increments2,BA8=1, applies710380/start0/blend10 without localflags82 or bank activation. Phase2 advances at1;exact signed-byte result1 increments3. Phase3 base cancellation/blend10. No local loop/frame request. |

Owned primary-one table pointers admitB7->62FD30,B8->630D30,61->630EE0,11->631120,3C->632730. The byteA phase graph and byteB subphase graph are not interchangeable:630EE0 clears/usesA internally for alignment while B controls its outer sequence. Other handlers here dispatch onA.

## Literal descriptor and frame data

| Owned bytes | Decoded content | SHA256 |
| --- | --- | --- |
|710240..710247|word0=10, halfwords4/6=F6/F6|`3e2e66c3d290422848ffe9f1641b93f44712ac9840af0801d07f47d328e31fcc`|
|710290..71029F|two descriptors word0=10; halfwords4/6=101/0 then102/0|`5195400b2276b8b6645bd013570b899c01d86ce3f9b7c3b005d8f55386102040`|
|710380..710387|word0=10, halfwords4/6=E3/E3|`7665e7c93a37c0b8b5380c281755427727e68f05d3cb1faa241c7d2831ee8a5e`|
|71B930..71B931|signed motion half2034|`0b0bd7ca2acebad288fe09c9d9595f1f1c8e91de8d0a6762dad9f009f2f8240d`|

Descriptors710290/298 have halfword6=0, unlike plain repeated animation IDs elsewhere; they are not relabeled as simply animation101/102. [Animation application](SYMBOLS_ANIMATION.md) reads those original fields and applies their descriptor semantics.

Complete192-byte frame window71B840..71B8FF contains eight rows of six floats, SHA256`8777fcaab9adb1765a78b35d531e061637258cf2028c1111f07f1a2b18245967`:

| B99 / B9B row interpretation | Six float columns |
| --- | --- |
|0 /0|34,34,30,36,26,28|
|0 /1|34,34,30,36,26,28|
|0 /2|34,36,44,48,48,28|
|0 /3|34,36,44,48,48,28|
|1 /0|20,34,30,36,26,28|
|1 /1|20,34,30,36,26,28|
|1 /2|34,36,44,48,48,28|
|1 /3|34,36,44,48,48,28|

630D30 reads only column0 at B99*96+B9B*24. No local category bounds are checked; this covers the explicit two-by-four row interpretation only. Sound admission occurs before animation advancement at track0/eventframe/step1 via573480; successful gate emits sound28 at current actorXYZ, without an extra RNG draw in this body. See [frame-gate contracts](SYMBOLS_TASK_FLAGS.md).

## External completion and signed arithmetic

631120 deliberately holds phases2/3; no animation boundary locally changes phaseFF. That phase requires an external writer or a distinct entry. The startup temporarily zeroes B9B only during2051 selection, restoring its saved entry value before the descriptor call. FF release repeats that pattern. Phase4 reads secondary track flags211 bit40 after advancing, not primary track1F1. Phase5's transient phase6 is overwritten by final action1/state0/phase1 selection. This body's final reset does not clear54F or548 through the common base-cancellation sequence; its explicit final stores/calls are retained exactly.

630EE0's initial timer is signedhalfAEA. PhaseB3 decrements any nonzero signed timer and only observes expiry on a later oldtimer0 call. In B4, remainingC48 is reduced by signed rootZ, not absolute displacement. It tests ordered remainder<=0; unordered values do not complete. Negative rootZ increases remaining distance. No runtime negative/invalid-value case or stall is claimed. Locomotion66C160 remains a separate [mapped actor helper](SYMBOLS_ACTOR_ACTIONS.md).

Where called, common base cancellation clears54F/548 bit0, selects(1,0,1,0), snapshots, motion2050/start0/blend10, activatesbanks. Presence of this sequence is stated per branch; it is not inferred for631120's final action reset. No global-clock/render changes or optimization were made. Caller/script phase writers, actual asset behavior, event frequency and performance cost remain unknown. Owned o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Full owned-body audit: 557 original words verified; 33 omitted words all zero/NOP. Zero conflicts or omitted nonzero words.
