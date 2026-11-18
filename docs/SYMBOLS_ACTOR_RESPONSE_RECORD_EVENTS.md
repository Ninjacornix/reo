# Actor interaction response and record event helpers

Static File #1 US research, 2026-11-04. Each named original body read in full;
large response selector includes all ten dispatch arms and default. No game,
build, replay, attachment or live-memory inspection. Addresses/offsets/IDs are
hexadecimal; explicitly stated counts/float values decimal. Response codes and
packet types retain numbers rather than invented original enum semantics.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5A62D0](../recomp/config/output_ovl/o2/o2_005A62D0_0x5a62d0.cpp) | `select_interaction_response_code_from_actor_policy_and_contact_candidate` | Probable role; full body reviewed | a0 actor,a1 request,a2 auxiliary,f12 threshold T; reads actor24 related pointer before a later a0-null branch, so that branch is not a complete null guard. ByteC27< A dispatches ten internal paths via73E410;other values use default. Returns small code0..5; no original enum labels asserted. Uses actor floatBD4=B,thresholdC3C=C,related class54F,B9B,health544/546 and RNG. Calls5A6A40 and sometimes634C80 with swapped actor pair, so not a pure comparison. Full case contracts below; no direct nonstack writes in this body. |
| [o2 0x5A6A40](../recomp/config/output_ovl/o2/o2_005A6A40_0x5a6a40.cpp) | `test_and_apply_related_actor_interaction_admission_candidate` | Probable role; full body reviewed | a0 source,a1 target,a2 request,a3 aux,f12 value. Null source/target returns0; sourceaction8==2 rejects. Target BA0 bit2000000 rejects; targetBA0 mask178 rejects AND clears source halfBF8+2*target3. Target54F2B/D/B0/A0/90 reject. Otherwise calls634C80 with incoming arguments; returns whether signed lowbyte result is nonzero. Underlying634C80 side effects remain part of contract. |
| [o2 0x5A6B20](../recomp/config/output_ovl/o2/o2_005A6B20_0x5a6b20.cpp) | `conditionally_encode_actor_action_and_flush_changed_record_candidate` | Probable role; full body reviewed | Onlymain1B0310==1 andfull a1!=0 call637C10(actor,signedlow8(a1),outByte). Output initialized0; nonzero calls63ABB0(actor). No packet is explicitly sent here; encoded-record/network meaning inferred from connected call family. |
| [o2 0x5A6B90](../recomp/config/output_ovl/o2/o2_005A6B90_0x5a6b90.cpp) | `update_actor_record_state_and_optional_type33_payload_candidate` | Probable role; full body reviewed | Requires main1B0310 nonzero andactorB9C!=1. Scratch74F210 byte0=lowa2,byte1=710640[signedlow8(a2)],byte3=actorB98. RecordR=74F250+60*B98; interprets signedwordXYZ R10/14/18 asfloats. Type33 additionally scratch4=lowa1/5=0,640050(XYZ,scratch6,0,outByte). AlwaysR22=lowa1,R24/R39=0 then63ABB0(actor). Does not update R XYZ. Types and signed table index are unchecked. |
| [o2 0x5A6CB0](../recomp/config/output_ovl/o2/o2_005A6CB0_0x5a6cb0.cpp) | `update_actor_record_position_from_resolved_interaction_descriptor_candidate` | Probable role; full body reviewed | Requires main1B0310 andactorB9C!=1.581B60(a1,out5F/5E/5D) mustreturnnonzero andout5F!=0. Scratch74F210 stores type a2, mapped710640[signedlow8(type)],actorB98. R=74F250+60*B98;5FE150(XYZ,signedout5E,signedR22),negative signedlow8 result fallsback signedinteger RXYZ convertedfloat. Type23 writes extra auxhalf/signeddescriptor bytes/R40 and640050(XYZ,scratch8,0,out). All admitted typesconvertXYZback withoriginalcvt.w.s,writeR10/14/18,R22/24=descriptorbytes,R3E=lowa3,R39=0,then63ABB0. Position reconstruction and float rounding preserved, no new behavior. |
| [o2 0x5A6E80](../recomp/config/output_ovl/o2/o2_005A6E80_0x5a6e80.cpp) | `send_four_byte_actor_record_event_candidate` | Probable role; full body reviewed | Onlymain1B0310 nonzero andactorB9C!=1. Builds bytes{3,low8(originala2),0,0};681790(2,actorB98,packet,selected actor4BADED). Originala1unused. Packet subtype meaning unresolved; no recordmutation inbody. |
| [o2 0x5A6F00](../recomp/config/output_ovl/o2/o2_005A6F00_0x5a6f00.cpp) | `send_once_actor_event_from_four_scenario_tables_candidate` | Probable role; full body reviewed | Requires main1B0310,actorB9C!=1,B9A==1,unsignedlowa1<4,C2C==0 and681B80(actor)nonzero. Pointer709B50[lowa1] plus scenario3243DA gives eventbyte;5A6E80(actor,0,event),then C2C=1. Does not set latch unless all gatespassed; scenario indexnotboundedhere. |
| [o2 0x5A6FC0](../recomp/config/output_ovl/o2/o2_005A6FC0_0x5a6fc0.cpp) | `send_type33_record_position_event_and_refresh_linked_entity_candidate` | Probable role; full body reviewed | a0 Rrecord,a1 state,a2 auxiliary;requiresmain1B0310 andR2B!=1.5FE150(XYZ,signedlowa1,signedR22) negative signedbytefallsbackintegerRXYZ. Scratch74F210 type33,subtypeE,ownerR0,statea1,auxa2,encodedXYZ640050;1AFDD0(8,scratch,0,4). UpdatesroundedRXYZ,R22/24,R39=0. R1!=FF resolves entity42EB00+D90*R1 then5A8DB0(entity,R). No null/slot bounds here. |

## Complete response policy table for5A62D0

A=source actor,O=pointerA24,B=floatA.BD4,C=floatA.C3C,T=incomingf12.
Q=5A6A40(A,O,request,aux,T);R=634C80(O,A,8000,aux,T). Both may have
side effects. Every random draw is low16 from1AEC80(1). These are policy
branches, not measured event frequencies.500 below is decimal.

| C27 | Internal entry | Ordered result selection |
| --- | --- | --- |
| 0 | 5A6344 | Qtrue->4;else B>T->1;else3. |
| 1 | 5A69D8 | Default:Qtrue->4;else B>T->1;else0. Also used forC27>=A. |
| 2 | 5A6384 | B>500->1. Else random bit1 ANDQ ANDR->4. Else B<C andO54F in1..4->2;else3. |
| 3 | 5A643C | B>500->1. Else random bit1 ANDQ AND(O.B9B==2 ORR)->4. Else B<C andclass1..4->2;else3. |
| 4 | 5A650C | Drawn=RNG%A,t=(RNG&3)+3. Qtrue->4. Else A8in3/4 andn<t->2;else0. |
| 5 | 5A65A4 | Drawn/t asabove beforethreshold. B>500->1;Qtrue->4;A8in3/4 andn<t->2;else3. |
| 6 | 5A6664 | Independently reviewed same current mechanics aspolicy4, including two draws andfallback0. |
| 7 | 5A66FC | B>500->1;random bit1 ANDQ ANDR->4;B<C andO54Fin1..4->2;O54F==80->5;else3. |
| 8 | 5A67C8 | B>500->1;random bit1 ANDQ AND(O.B9B==2 ORR)->4;B<C andclass1..4->2;class80->5;else3. |
| 9 | 5A68AC | SignedO544 <0.5*signedO546:random bit1 ANDQ ANDR->4,elseclass80->5,else3. Other healthbranch:B>500->1;B<C andclass1..4->2;elserandombit1->1,zero->2. |

Internal entries belong to5A62D0 and are not counted as separate functions.
The labels do not establish damage, stagger, network-delivery guarantees or a
slowdown cause. Main1B0310 is the previously mapped boolean predicate on signed
session byte3243FB in1/2; it is not an unrestricted mode number.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Instruction words verified against owned file-backed o2, virtual base570000.
