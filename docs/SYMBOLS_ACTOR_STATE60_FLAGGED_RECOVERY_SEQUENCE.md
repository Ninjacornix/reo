# Actor state60 flagged recovery and directional follow-up

Static File #1 US, 2026-11-05. One complete original o2 body reviewed with all branch targets, delay slots and argument contracts. Addresses, phase/state IDs, masks and offsets are hexadecimal; float durations and timer lengths are decimal. No execution, build, attachment, live memory, input or timing. The recovery role is candidate; original action names remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x630750](../recomp/config/output_ovl/o2/o2_00630750_0x630750.cpp) | `run_state60_flagged_motion_recovery_timer_and_directional_finish_candidate` | High mechanics; candidate role | Owned primary-one60 target. Prefix54A18/32FF; consumed reset selectsphaseA. Phase0 visual28/D10=1/snapshot, clearsBA0 maskA8 thenOR18, clearsroots/refreshesB9B. Phase1 selects class motion1024/1025/1026 or recognizes existing1043/1044, initializes548 bit0/B90/B94. Phase2 any full nonzero animation result ->A with1043. PhaseA sets timed directional1043/1044 sequence and local linked-target event;B counts down,C waits positive boundary,D chooses descriptorF7/F8 and refreshesclass,E waits positive boundary,FF returnsbase. Full details below. |

## Entry and initial motion

The primary-one table's state60 pointer is630750. Every call ORs54A18 and writes32FF before reset6673C0. Nonzero reset selectsphaseA and continues its local work immediately. Phase0 selectsphase1, visual54F28/D10=1, snapshots667370, clearsBA0 maskA8 then ORs18, clearsroot4E4/4E8/4EC, refreshes B9B65FAB0, then falls into phase1.

Phase1 incrementsphase2. Existing motion520==1043 or1044 instead setsphaseA without selecting a new motion. Otherwise cached classB9C0/1 selects1024,2->1025,3->1026, with start0/blend10. Other B9C retains existing motion. All paths then set548 bit0, B90=0 and B94=1/D, where D=primary endframe1E8 for clockmode0, otherwise endframe/2. The original floating division has no local zero-end guard; no zero-end case or failure was reproduced. Phase2 advances58C300 at1; any nonzero full returned value selectsphaseA, flags82, motion1043/start0/blend10 and banks. It does not require positive signed-byte or exact1 here.

## Timed directional sequence

PhaseA setsphaseB, visual28, repeats BA0 `clearA8; OR18`, timerC=60 for clockmode0 or30 otherwise. Locally controlled1B0340==1 optionally resolves two linked records: byte148==2 uses149, byte14A==2 uses14B, with the second candidate overwriting the first. It reads runtime byte74F251+60*id, then candidate=42EB00+D90*thatByte. Nonnull result sends37C060(D,candidate.byte3,candidate.halfBBA). There is no local index bound. The runtime table74F251 lies beyond owned o2 file-backed end743100; it was not read as a shipped-data fact.

If motion already1043/1044, phaseA advances it at1. Otherwise it flags82, obtains heading from actorXYZ to model34->node874 translation30 through o0 376E70, and tests unsigned low16(heading-yaw+4000)<8000: true selects1043, false1044, start0/blend10. All phaseA branches activate banks before returning. Geometry and heading helper admission remain separate from original action naming.

PhaseB: old signed C==0 incrementsphaseC; otherwise decrements C. It always advances animation at1, ignoring result. PhaseC advances at1 and only positive signed-byte boundary incrementsphaseD. PhaseD incrementsphaseE, flags82, repeats the same heading test. True applies descriptor710280/start0/blend10; false subtracts8000 yaw and applies710288/start0/blend0. It refreshes class65FAB0 afterward, without a local bank-activation call. PhaseE advances at1; positive signed-byte boundary selectsFF. PhaseFF performs base cancellation. Other phases return after prefix/reset work.

Base cancellation clears54F/548 bit0, selects(primary,secondary,phase,B)=(1,0,1,0), snapshots,2050/start0/blend10 and bank activation. It does not locally clear all BA0 flag changes from earlier phases.

## Owned fixed descriptors and limits

710280: word0=10, halfwords4/6=F7/F7.710288: word0=10, halfwords4/6=F8/F8. These are the final16 bytes of fully owned710260..71028F, SHA256`ace6de8ba1168b371be228c0fd0b1bd5e2426993d98b42239fca2eb81fe67c9d`. No original animation names or exact runtime target types are inferred from those values.

[Class refresh and turn/alignment helpers](SYMBOLS_ACTOR_ACTIONS.md), [animation](SYMBOLS_ANIMATION.md), [heading math](SYMBOLS_OVERLAY_MATH.md) and [reset/snapshot contracts](SYMBOLS_DISPATCH.md) establish dependencies. Runtime target validity, endframe values, request frequencies and performance cost remain unknown. Owned o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Full owned-body audit: 348 original words verified; 28 omitted words all zero/NOP. Zero conflicts or omitted nonzero words.
