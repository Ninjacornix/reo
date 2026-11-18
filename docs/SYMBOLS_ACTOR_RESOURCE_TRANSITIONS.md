# Actor selected-resource transitions and quantity helpers

Static File #1 US research, 2026-11-04. See [actor states](SYMBOLS_ACTOR_STATES.md)
for paired dispatcher ownership and [interaction helpers](SYMBOLS_ACTOR_INTERACTIONS.md)
for frame-completion helper contracts. This notebook contains original-byte
reviewed bodies, not runtime measurements. No game, build, replay or attachment
was run.

## Selected-resource action-one state machine

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x674340](../recomp/config/output_ovl/o2/o2_00674340_0x674340.cpp) | `actor_action_one_states38_3e_3f_resource_quantity_transition_candidate` | Probable role; full body reviewed | Paired secondary entries38/3E/3F. Sets BA4 bit100 and uses resource record0x3C5630+60*C7C, actor class B9B, resource class CA8. Reset returns base2050/blend10; phase0 sets54F1C/D10=1/BA8=1, saves transform and ORs BA4 bit00100000 when resource quantity halfword24==0. Resource-class flag bank0x719A60+68*CA8 chooses large motion/quantity phase families. Uses candidate inventory selector0x586310, descriptor quantity versus template capacity0x5B4380, motion200D under temporary B9B0 before class-specific2062..206E, frame-sensitive0x5F4FE0 resource operation and local input cancellation. Complete phase relationships and irregular inherited arguments are recorded below; original action name remains unknown. |

Every value in this phase table is hexadecimal unless shown as a float/blend.
Repeated motion setup means: request200D/blend10 with temporary B9B0, restore
saved B9B, then request listed motion/blend10. Most setup paths set primary track
byte1F0=1, whereas phases2A/54/8C activate all banks. These distinctions are part
of the behavior.

| Phase(s) / original PC | Observed transition |
| --- | --- |
| 0 /0x6745B0 | Initializes as above. Substate3F skips classification, starts phase5 with motion from0x725AD8 +32*resource-class byte at0x719A65+68*CA8. Other states enter1. |
| 1 /0x674678 | Masks resource flags with1E0:20->A,40->32,80->5A,100->78. Comparison to200 cannot match that mask, although it has an original A branch. Unknown flags keep phase1. No enum name is inferred from these bits. |
| A /0x674708 | Calls0x586310(actor,C7C,C) with a2=C inherited from phase-dispatch register setup. Saves C83. Resource quantity==template halfword8 ->FF; otherwise candidate found ->14, none ->C. |
| C /0x674758 | Repeats selection with explicit mode1; equal quantity->FF, candidate found->28, none->FF. |
| FF /0x6747AC | Requests2051/blend10, activates banks, enters action1/substate0/phase1 and saves transform. This differs from reset's2050 request. |
| 14,16,18 /0x6747F0,0x674880,0x674940 | Repeated setup with2064,2066,2067.14 additionally invokes resource operation0x5F4FE0 immediately. Next odd phases15/17/19 advance animation until211 bit40;15->16,19->FF,17->FF when resource flags bit200, otherwise18. |
| 28,2A,2C /0x6749B0,0x674A20,0x674C8C | Repeated setup2064,2065,2067.29 waits211 bit40 then2A;2A activates all banks and enters2B;2D waits211 bit40 thenFF. |
| 2B /0x674A70 | Only substates38/3E/3F have work.3E/3F consume local F78 bit10 into+B FF, advance animation and on211 bit40 invoke resource operation. For resource bit200, result3, cancellation or quantity reaching capacity goesFF; otherwise2C. State38 delegates0x673FE0, with a2=FF for resource bit200, else inherited2C. |
| 32,34 /0x674CFC,0x674D50 | Select candidate using modeC then fallback1, respecting capacity equality. Found ->3C or50, none ultimatelyFF. |
| 3C,3E,40,42 /0x674DA4,0x674E38,0x674EA8,0x674F18 | Repeated setup2064,2062,2066,2063.3C immediately invokes resource operation. Odd phases3D/3F/41 advance on211 bit40 to3E/40/42;43 completes toFF on same flag. |
| 50,52,54,56 /0x674F88,0x674FF8,0x675068,0x6751B0 | Repeated setup2064,2062,2065,2063.51/53 advance on211 bit40 to52/54;54 activates all banks. Phase55 for3E/3F consumes local F78 bit10; on211 bit40, result3/cancellation/capacity ->56. For38 delegates0x674100 with a2=56 inherited from dispatcher.57 waits211 bit40 thenFF. |
| 5A,6E,6F /0x675220,0x675274,0x6752C4 | Select with mode1; capacity equality or no candidate ->FF, else6E. Repeated setup206C, then6F handles local F78 bit10 and invokes resource operation on211 bit40; result3/cancellation/capacity ->FF. |
| 78,8C,8D,8E,8F /0x67537C,0x6753D0,0x675424,0x67551C,0x675568 | Mode1 selection/capacity check; found->8C, none->FF. Repeated setup206D activates all banks;8D invokes resource operation on211 bit40 for3E/3F and result3/cancellation/capacity ->8E. For38 delegates0x674220 with a2=8E inherited from dispatcher.8E repeated setup206E;8F waits211 bit40 thenFF. |
| 5,6 /0x67558C,0x675610 | Substate3F descriptor-motion loop. Positive signed lowbyte animation result: resource-class byte2/7 selects2050/blend10 and6, other classes return1. Phase6 positive signed lowbyte returns1. |
| 7 /0x675634 | Frame gate selector1 at34 for B9B2, otherwise26, speed1. On gate, C7C=C7F, writes record ownership halfword28 as slot+1 or BB4+5, activates resource0x5B18D0 and refreshes CA8. Advances animation; ordered frame204<208 false returns1. No local transition into7 was found in this body. |

The helpers0x673FE0/0x674100/0x674220 receive completion phases in registers set
earlier by the phase dispatcher. A local call-site-only argument read would
incorrectly call these values uninitialized. Conversely, no host argument or
array bounds guard is present for resource indices/C83 in the original body.
The state machine does **not** prove a slowdown cause or permit replacing its
frame gates with one global update count.

## Resource selection, template and operation helpers

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x586220](../recomp/config/output_ovl/o2/o2_00586220_0x586220.cpp) | `select_actor_inventory_slot_by_type_and_positive_quantity_candidate` | Probable role; mechanics verified | a0 actor, lowbyte a1 selection mode, low16 a2 type. Visits four slot bytes C84..C87, skips zero resource IDs, matches resource halfword6. Mode0 selects smallest positive unsigned halfword24, mode1 largest; inclusive comparisons make later equal quantities replace earlier slots. Other modes returnFF with no selection. Does not verify resource active flag or index bounds; returns slot0..3 orFF, not resource ID. |
| [o2 0x586310](../recomp/config/output_ovl/o2/o2_00586310_0x586310.cpp) | `select_actor_inventory_slot_compatible_with_resource_candidate` | Probable role; mechanics verified | a0 actor, lowbyte a1 resource ID, signed low16 a2 compatibility mode. Calls0x5B41E0 on0x3C5630+60*resource, returningFF for zero low signed16 compatibility type. Mode1 chooses smallest positive quantity via0x586220, modeC largest. For C, selected resource quantity must be strictly greater than original resource quantity (signed halfwords here), elseFF. Other modes use unassigned local s2 when choosing min/max, so no general stable contract is established. Template compatibility extra halfword output is not consumed here. |
| [o2 0x5B41E0](../recomp/config/output_ovl/o2/o2_005B41E0_0x5b41e0.cpp) | `lookup_resource_compatibility_type_and_extra_halfword_candidate` | Probable role; mechanics verified | a0 resource pointer, signed low16 a1 requested mode, a2 optional-on-match halfword output. Null resource returns0 without writing output. Calls template resolver0x5B4320 twice; signed template4 must be>=0 and signed6>0. Scans count entries of six bytes at0x74C970 +2*template4, comparing signed entry4 to mode. Match returns signed entry0 and stores entry2 to*a2; unmatched returns0 leaving output untouched. No bounds checks on table span or null output on a matched entry. |
| [o2 0x5B4320](../recomp/config/output_ovl/o2/o2_005B4320_0x5b4320.cpp) | `resolve_resource_template_from_record_pointer_candidate` | Confirmed/static mechanics | Null pointer, signed active byte0==0 or template byte2B==FF returns fallback0x74C750. Otherwise returns0x74BB50+24*unsigned template byte2B. No item-array index is accepted by this entry; it operates on record pointer a0 and does not mutate it. |
| [o2 0x5B4380](../recomp/config/output_ovl/o2/o2_005B4380_0x5b4380.cpp) | `resolve_resource_template_from_resource_id_candidate` | Confirmed/static mechanics | Lowbyte a0 indexes record0x3C5630+60*id. Inactive signed byte0 or template byte2B==FF returns0x74C750; otherwise0x74BB50+24*templateByte. Unlike0x5B4320 it does not accept null pointer and does no explicit zero-ID special case; it reads record0. |
| [o2 0x5F4FE0](../recomp/config/output_ovl/o2/o2_005F4FE0_0x5f4fe0.cpp) | `apply_actor_resource_pair_operation_with_locality_gate_candidate` | Probable role; mechanics verified | a0 actor, lowbyte a1 locality mode, a2/a3 resource IDs, t0 operation argument. Category1 bypasses locality restriction; other categories mode0 only local slot, mode1 only nonlocal slot, with rejected returns-1. Calls0x5B3690(a2,a3,t0). Low signed byte0 returns0 immediately;1 returns1;2 invokes0x5F2180(actor,firstID) and0x5F2330,3 same with secondID. Other lowbytes return0. Except early result0 and locality mode1, ORs D92 bit1000 and saves low bytes DA2/DA3/DA4 for deferred observation. These writes happen even for unrecognized nonzero result. Concrete pair-operation taxonomy awaits core0x5B3690 review. |

## Explicit resource-pair action40 transition

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x675710](../recomp/config/output_ovl/o2/o2_00675710_0x675710.cpp) | `actor_action_one_state40_explicit_resource_pair_transition_candidate` | Probable role; full body reviewed | Uses record0x3C5630+60*CAA and pair bytes CAA/CAB, not C7C/C84[C83] selection. ORs BA4 bit100; any reset returns base2050/blend10. Initializes54F1C/D10=1/BA8=1 and CAC=old+B, phase1. Ten-entry table0x7405B0 has setup work only for CAC1/3/5/6/7/8/9, requesting substate2F/B40 first if C7C differs from CAA. Phase1 converts CAC to10*CAC and remaps14->64,28->6E,5A->32. Plays explicit resource-operation motion families and checks quantity/capacity, preserving local/global cancellation; detailed branches below. Original combine/reload taxonomy remains candidate. |

The two large handlers share motion patterns but have different data ownership,
phase values, cancellation rules, template lookup contracts and exit actions.
No whole-function identity or blanket consolidation is justified by similarity.
All phase values below are hexadecimal. Repeated setup is200D/blend10 while
B9B is temporarily0, restore saved B9B, then the listed motion. PhaseA's2064
blend is6; other listed second requests use10.

| Phase(s) / original PC | Observed transition |
| --- | --- |
| 0 /0x675948 | Sets CAC=old+B. Original ten-entry table: indices1/3/5/6/7/8/9 compare C7C versus CAA. Different IDs set D92 bit40, C7F=CAA and action1/substate2F/B40; others leave phase1. Values0/2/4 and>=A have no such preselection work. |
| 1 /0x6759F0 | Sets+A=10*CAC, ORs BA4 bit00100000 when selected C7C record quantity==0; phase14->64,28->6E,5A->32. Values unsupported by the outer phase switch keep their resulting phase. |
| FF /0x675A84 | Requests2051/blend10, activates banks and enters action1/substate0/phase1. Reset path instead requests2050/blend10. |
| A,C,E /0x675AC8,0x675B50,0x675BC0 | Setup2064/blend6 then immediate0x5F4FE0(actor,0,CAA,CAB,1); B waits211 bit40->C; setup2066, D waits211 bit40->E. At E, resource-class flag200 returns base2050/blend10; otherwise setup2067 and F waits211 bit40->FF. |
| 1E,20,22,24 /0x675CB0,0x675D38,0x675DA8,0x675E18 | Setup2064 plus immediate pair operation, then2062,2066,2063. Odd phases1F/21/23 wait211 bit40 before advancing;25 waits that flag->FF. |
| 32,34,35,36,37 /0x675E88,0x675EF8,0x675F48,0x676010,0x6760C0 | Setup2064 then2065, with all-bank activation for2065.33 waits211 bit40->34.35 advances animation; after211 bit40 pair result3, cancellation or quantity==capacity enters36. Local actor cancellation uses F78 bit10 OR global byte0x3B85A4==1, storing+B FF. At36, CAC9 immediately returns base2050/blend10; otherwise setup2067.37 waits211 bit40->FF. |
| 3C,3D,3E,3F /0x6760E4,0x676130,0x676154,0x6761A0 | Setup2064;3D's211-bit40 transition writes phase34, **not3E**. Original3E setup2062 and3F's211-bit40 transition writes36. No local transition to3E from3D is assumed. |
| 40,41,42,43 /0x6761C4,0x676214,0x6762DC,0x676328 | Setup2065/all-bank activation.41 pair-operation/capacity/local-or-global cancellation loop like35, completing to42. Setup2063;43 waits211 bit40->FF. |
| 46,47 /0x67634C,0x67639C | Setup206C/all-bank activation.47 pair-operation/capacity/local-or-global cancellation loop like35, completing directlyFF. |
| 50,51,52,53 /0x676464,0x6764B4,0x67657C,0x6765C8 | Setup206D/all-bank activation.51 pair-operation/capacity/local-or-global cancellation loop completes52; setup206E, then53 waits211 bit40->FF. |
| 64,6E /0x6765EC,0x676634 | Both call0x5F4FE0(actor,0,CAA,CAB,FF), ignoring result; enter action1/substate0/phase1, save transform and notify1. These branches do not select a new motion themselves. |

Quantity comparisons use signed record halfword24 and template halfword8 from
0x5B4380(record byte2). The latter helper takes an item ID, not a template index,
so this nested lookup contract remains explicit. There are no local null/index
checks. The phase3D->34 jump is a static behavior finding, not a proven bug:
normal reachability and expected content would have to be established before a
candidate correction.

## Adjacent alternate locomotion and direct-track handlers

These handlers follow the resource transitions in original code order. Numeric
motion1010..1017 is evidence; no swimming/climbing original enum is asserted.
A shared clock/helper does not make their update frequency global.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x676690](../recomp/config/output_ovl/o2/o2_00676690_0x676690.cpp) | `actor_action_one_states48_49_direct_motion_bank_and_fb8_candidate` | Probable role; mechanics verified | Reset clears phase; initializes54F20/D10=1/BA8=1 and saved transform. State48 clears CE0 and sets CE1=boolean B99, then flags82 and direct track0x58BEA0(actor,pointer518,signed522,0,0);49 uses CE1=A and pointer51C. Phase2 advances at1; only signed lowbyte result exactly1 plus primary active byte1F0==0 increments wrapping byte FB8. No local transition when incrementing FB8 and no pointer/count guard. |
| [o2 0x6767F0](../recomp/config/output_ovl/o2/o2_006767F0_0x6767f0.cpp) | `actor_action_one_state4a_motion1010_hold_candidate` | Probable role; mechanics verified | ORs54A bit10. Reset only clears phase and returns this tick. Phase0 sets54F21/D10=1/BA8=1, clears saved transform via0x6673A0, selects1010/blend30 and activates banks. Phase1 advances at1, ignoring result; no local automatic completion. |
| [o2 0x6768B0](../recomp/config/output_ovl/o2/o2_006768B0_0x6768b0.cpp) | `actor_action_one_states4b_4c_turn_motion1013_1014_candidate` | Probable role; mechanics verified | ORs54A bit10; reset enters action1/substate4A with phases0 and saved transform.4B subtracts computed0x65F580 turn step from yaw,4C adds, before phase dispatch. Phase0 sets54F21/D10=1/BA8=1, clears saved transform and root deltas, requests1013/1014 respectively with blend20 and activates banks. Phase1 advances at1, no local completion. |
| [o2 0x676A00](../recomp/config/output_ovl/o2/o2_00676A00_0x676a00.cpp) | `actor_action_one_states4d_4e_4f_motion1011_candidate` | Probable role; mechanics verified | ORs54A bit10; reset enters4A.4E subtracts turn step,4F adds,4D leaves yaw. Phases0/1 increment to2, set54F22/D10=1/BA8=1 and clear saved transform. If current motion520!=1011 selects1011/blend40 and activates banks; if already selected skips those calls. Falls into animation advance at1 immediately on setup tick as well as phase2. No local completion. |
| [o2 0x676B50](../recomp/config/output_ovl/o2/o2_00676B50_0x676b50.cpp) | `actor_action_one_states50_51_52_motion1015_candidate` | Probable role; mechanics verified | Separately reviewed variant:51 subtracts turn step,52 adds,50 unchanged. Reset enters4A; setup54F24/D10=1/BA8=1, clears saved transform, phases0/1->2. Motion1015/blend40 is requested and banks activated only if different; animation advances at1 on setup and phase2. Does not locally end on an animation boundary. |
| [o2 0x676CA0](../recomp/config/output_ovl/o2/o2_00676CA0_0x676ca0.cpp) | `actor_action_one_states53_54_55_motion1012_candidate` | Probable role; mechanics verified | ORs54A bit10; reset enters4A.54 adds turn step and55 subtracts, reversing signs relative to neighboring three-state groups.53 leaves yaw. Phase0 increments to1; phase1 setup sets54F23/D10=1/BA8=1 and clears saved transform, conditionally selects1012/blend30 and activates banks, then advances at1. Unlike neighbors it does not write phase2 during phase1, so local setup can repeat on later phase1 calls. Existing phase2 directly advances. No completion transition in body. |
| [o2 0x676DE0](../recomp/config/output_ovl/o2/o2_00676DE0_0x676de0.cpp) | `actor_action_one_state56_align_mode0_and_motion1016_candidate` | Probable role; mechanics verified | ORs54A17/32 FF; reset clears phase. Initializes54F21/D10=1/BA8=1, saves transform, clears root deltas and starts0x66DD50(mode0) using preexisting target fields. Other unmatched phases continue alignment until return1->phase1. Then flags82,1016/blend20, bank activation; phase2 requires signed lowbyte animation result exactly1 to advance3. Phase3 enters4A with phases0 and saved transform. |
| [o2 0x676F30](../recomp/config/output_ovl/o2/o2_00676F30_0x676f30.cpp) | `actor_action_one_state57_align_mode3_and_motion1017_candidate` | Probable role; mechanics verified | ORs54A17/32 FF; reset immediately enters4A. Initializes54F21/D10=1/BA8=1, saved transform and cleared root deltas, aligns with0x66DD50(mode3), then flags82/1017/blend20/bank activation. Phase2 accepts any nonzero full animation result ->FF. FF clears54F/548 bit1 and returns base2050/blend16. Distinct reset, admission and return semantics from state56. |
