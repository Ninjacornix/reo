# Actor 6D action selection and contact transitions

Static File #1 US research, 2026-11-04. Seven complete original bodies
reviewed. Addresses and offsets are hex unless marked decimal. Actor identity,
original response enums and timer units remain unknown. No target execution or
engine changes; no measured slowdown cause is asserted.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6D15C0](../recomp/config/output_ovl/o2/o2_006D15C0_0x6d15c0.cpp) | `advance_actor_6d_zero_health_two_motion_hold_candidate` | High mechanics; probable role | Each call32FF,C94mask201,54Abit4. Phase0 enters1,clears544,38B0 descriptor12/frame0,5A8060 refresh and byte74F295+60*B98=1. Phase1 advances58C300; positive signed-lowbyte result enters2,descriptor14/frame0,58C7B0. Phase2 keeps advancing. External phase5 replaces with2/descriptor14/frame0/58C7B0. Other phases return. No delete or explicit death enum here. |
| [o2 0x6D1700](../recomp/config/output_ovl/o2/o2_006D1700_0x6d1700.cpp) | `choose_actor_6d_random_primary_one_substate_candidate` | High mechanics; probable role | Saves old8/9 atBE8/BE9,clears A/B. Old state1/2 consumes random-low1;other states unsigned random-low16%3. Writes selected value to byteBA0 (not whole actor flagword),then8=1/9=BA0,calls1C60 timer initialization,C36=7. Distinct random calls inside1C60 retained. |
| [o2 0x6D17C0](../recomp/config/output_ovl/o2/o2_006D17C0_0x6d17c0.cpp) | `choose_actor_6d_peer_interaction_state_from_alignment_policy_candidate` | High mechanics; probable role | Null actor24 returns without write. Otherwise saves8/9,clears A/B; signed metricBF8+14*C25+2*C26<decimal250 or signed12>0 calls1700 and returns. BA3 modes0/1/2 set BBC=decimal600/250/100 and5A62D0 request3FFC/3FFC/10000,aux3;unknown modes retain BBC and inherited request argument. Response selection details below. After any selected primary1, signed BD8 outside inclusive-2000..2000 stores selected secondary in B and substitutes1/5. Calls1C60 and C36=7. Response helper has policy/RNG side effects, so selection is not a pure distance function. |
| [o2 0x6D1DA0](../recomp/config/output_ovl/o2/o2_006D1DA0_0x6d1da0.cpp) | `dispatch_actor_6d_contact_classification_and_response_state_candidate` | High mechanics; probable role |637490 contact->actor11C. Initiator B1E==1 clears it and sets contactB1E=6.5A9AA0(contact byte3) bearing plus4000,wrapped then>>15 ->B1F0/1. Calls72B820[actor141](actor,7),sound1B9310(actor,6,0),666D40(contact) only when word138>0,then6407D0(actor,contact,decimal1000). Classification1/2 writes corresponding byte74F295+60*B98. Saves8/9 and routes via2050/20E0 or special primary-state/pulse paths below. Returns1 after ordinary phase reset,2 after pulse adapter; no original damage enum. |
| [o2 0x6D2050](../recomp/config/output_ovl/o2/o2_006D2050_0x6d2050.cpp) | `select_actor_6d_classified_response_state_from_alignment_and_health_candidate` | High mechanics; probable role | BA3=0:actor140==2 ->4/0;other140 values ->4/5 when signed544<=0,else4/3. BA3=1 ->3/1;BA3=2 ->3/2. Other modes leave8/9 unchanged. Does not clear phases,save state or select animation. |
| [o2 0x6D20E0](../recomp/config/output_ovl/o2/o2_006D20E0_0x6d20e0.cpp) | `select_actor_6d_unclassified_response_state_with_health_fallback_candidate` | High mechanics; probable role | Signed544<=0 delegates2050. Positive health and140!=2 ->3/0. Positive health/140==2 uses BA30->4/0,1->3/1,2->3/2;unknown mode leaves8/9. No phase writes. |
| [o2 0x6D2180](../recomp/config/output_ovl/o2/o2_006D2180_0x6d2180.cpp) | `apply_actor_6d_alignment_scaled_animation_root_to_position_candidate` | High mechanics; probable role | BA30 builds Euler matrix. Nonzero BA3 with state1/7 copies actor matrix50;other mode1/2 builds Euler and composes quaternionD18 matrix through1913E0. Other modes reach later work without initializing the local basis here. Unless54Abit8,composes scale(B4,1,BC);always clears54Abit8. Transforms animation-root4E4 into C0XYZ,scales byF0,adds to actorXYZ38. Does not clear root4E4,commit actor matrix translation or query collision. Distinct from2340 local/world-delta consumption. |

17C0 response code table, numbers hex except distances marked decimal:

| Response | Selected state and additional conditions |
| --- | --- |
| 1 | 1/4 |
| 2 | 1/3 |
| 3 | BA30,BD4<decimal200,BD8 outside(-4000,4000),peer BA0bit2000000 clear and old primary!=2 ->2/3. Otherwise BD4<BBC ->1/3;BA32 and decimal100<=BD4<200 permits random-low2==0 ->1/6;remaining ->1/4. |
| 4 | Peer BA0bit2000000 set ->1/3. Otherwise BA30:BD4<250 ->2/0,BD4<600 ->2/1,else1/4. BA31:BD4<250 transforms owned731600=(0,0,1) through191A40(actorMatrix50); resulting Y<=0.5 ->2/0,else1/3;distance>=250 ->1/4. BA32:BD4<100 ->2/2,else1/4. Distances decimal. Other alignment modes preserve prior8/9 before common turn override. |
| Other | 1/3 |

1DA0 routing: old primary2/secondary1 becomes4/0. Other primary2 uses2050
for nonzero classification,20E0 for0. Old primary3 with nonzero classification
and secondary0 calls2050;other primary3 cases call5A7C40(owned7315C8,actorCD8)
and return2 without clearing phases. Old primary4,class1,secondary0/3 stays4
and adds2 to secondary;other primary4 cases use that pulse/return2. Remaining
primaries with secondary6/7 also pulse/return2;others use2050/20E0 by nonzero
classification. Ordinary paths clear A/B and return1. Owned7315C8 four signed
halves are decimal-222 each;5A7C40 copies them as its numeric field contract.

The contact dispatch and locomotion root application are separate original
bodies. No claim about their callback frequency, hotness or responsibility for
the captured slowdown follows from static mapping.

Related [surface probes](SYMBOLS_ACTOR_6D_SURFACE_PROBES.md),
[alignment helpers](SYMBOLS_ACTOR_6D_ALIGNMENT_MOTION.md), and
[response policy](SYMBOLS_ACTOR_RESPONSE_RECORD_EVENTS.md).
