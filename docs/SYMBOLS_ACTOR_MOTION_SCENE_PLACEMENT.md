# Actor motion events and scene-record placement

Static File #1 US research, 2026-11-04. Five complete original bodies reviewed.
Addresses/offsets hex unless marked decimal. Actor identity and original record
category/action enums remain unknown. No execution, attachment, build or engine
changes. Scene traversal is observed original linked-list traversal, not a claim
about malformed data in a player session.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6F8900](../recomp/config/output_ovl/o2/o2_006F8900_0x6f8900.cpp) | `dispatch_actor_6f18a0_motion_crossing_audio_and_collision_events_candidate` | High mechanics; probable role | a0 actor,f12 animation step. Nonzero halfBBA delegates707E90 with inherited arguments and returns. Otherwise dispatches19 literal motion IDs:65 onlyprimary9;66,C8,C9,CB,12C,12D,136..139,190..196, plus explicitCD no-op. Calls crossing-gated audio5A92E0(frame,actor,base,variantcount,step) and collision update5A96F0(frame,actor,mode,descriptor,step). C8 emits frame2A/58/80 base0 parity1;C9 frames18/2A same. CB splitsprimary9/8/other: frame14 descriptor87 only for8/9, additional14 descriptor6E except9; then16/base7/count0. 12C uses4/base33/parity1,20/descriptor6C,22/base7;12D uses4/base33/parity1,9A/base8/count0,A0/descriptor79. 136 frame24/base3;137 frame0 mode2 plusaudio0/base0/parity1;138 descriptor89 at0;139 audio4/base33/parity1,18/descriptor82,1E/base7. Motions190..195 base30/parity1 atA,6,6,A,8,4;196 audio0/base32,4A/base5,C2/base4. 65 primary9 frame14 descriptor87,16 mode2,16 audio7;66 frame0/base35. No sound rendered or timing measured. |
| [o2 0x6F8DD0](../recomp/config/output_ovl/o2/o2_006F8DD0_0x6f8dd0.cpp) | `place_actor_from_last_matching_category_zero_scene_record_candidate` | High mechanics; probable role | a0 actor,a1 low8 recordID,a2 low8 action mode. If signed3B5150==80 returns. Scans linked3B5160 via28, retains LAST category byte30==0 with word40==ID; no matching record returns. Extracts translation of model slot word4C via49FA10+40*slot,storesactorABB. Word60 type0 uses scene/session mask4B9E24+12*3243DC and ID bit or mode5 to choose AB9=70B190[word50]+1F,ACC168;otherwise AB9=table+1. Type1 AB9=2F ifmode5 else1A,ACC168. Type3 AB9=30 ifmode5 else29,ACC168. Type2/other retain AB9. AB9 1A/29 uses offset70B0A0+12*word50;others70B070. Rotates offset by slot matrix and adds translation;setsAC8/yaw fromword58,copiesXYZtoABC,AB8=1. No independent list-cycle, ID or slot bounds check. |
| [o2 0x6F90B0](../recomp/config/output_ovl/o2/o2_006F90B0_0x6f90b0.cpp) | `place_actor_from_last_matching_category_one_scene_record_candidate` | High mechanics; probable role | Same global80 rejection and last-match traversal, but category30==1 and word40==low8 a1. AB9=owned70A750[word6C]; recordhalf86!=FFFF signals5703E0(id,1) and overridesAB9=31. Word6C<8 dispatch742F00:cases0/7 copyword4CXYZ,yawword58,ACC=unsignedword70 float;1 yaw=word58-8000,rotate70B1A0+12*B99 andaddrecordXYZ,ACC0,ABB=word78;2/4 rotate70B200+12*B99 andcopyyaw,ACC fromword70;3/5 same separately emitted body;6 copiesXYZ/yaw then570CC0(actor,B) and returns before AB8=1. Out-of-range type stillsetsAB8=1 afterinitialAB9/event work. Other ordinary casespublishABC andAB8; no original placement/action labels asserted. |
| [o2 0x6F9440](../recomp/config/output_ovl/o2/o2_006F9440_0x6f9440.cpp) | `place_actor_from_category_six_record_selected_by_id_and_side_bit_candidate` | High mechanics; probable role | Rejects signed3B5150==80. Scans linked scene list retaining last category6,word4C in4/5,word54==(a1low8&7F), and side compatibility:4 requiresbit80clear,5 requiresbit80set. Builds yaw matrix fromword48,rotates70B270+12*actorB99,adds model-slot word60 translation. Replaces Y with signed integerword20 convertedfloat. PublishesABC,yaw/AC8,ACC200 decimal,ABBslot,AB8=1;AB9=10 fortype4,elseF. No candidate match leaves actor unchanged. |
| [o2 0x6F9600](../recomp/config/output_ovl/o2/o2_006F9600_0x6f9600.cpp) | `initialize_actor_room_and_dispatch_matching_scene_placement_candidate` | High routing; probable role | a0 actor,a1 low16room,a2 placementID,a3 low8mode. Placement only whenroom==3243DC:mode1/5 ->8DD0(actor,ID,mode),mode2/6 ->90B0(actor,ID),mode4 ->9440(actor,ID); other modes skip. All paths write actor1E2=originala1low16 and812170(actor,1). Placement early returns do not suppress this final room/publication call. |

Owned742F00 targets918C,9200,9284,932C,9284,932C,93D4,918C within6F.
Owned70A750 bytes for these eight cases are7,8,14,17,1B,1C,7,2D.
The code computes AB9 before checking word6C<8; observed table bytes are
evidence, not a newly inferred caller range guarantee. All three placement
searches continue after a match and therefore select the final matching list
entry. Registry count80 is an equality check, not a general upper bound.

Audio/count semantics are inherited from
[crossing events](SYMBOLS_ENTITY_CROSSING_EVENTS.md): count1 selects global
parity, count0 the literal base ID. Collision mode0 clears the entire115 byte
and selects a descriptor, while mode2 ORs bit1. These operations cannot be
collapsed into a generic sound-only event. No measured cost or incident cause
is established. The connected actor family is documented in
[bootstrap](SYMBOLS_ACTOR_6F18A0_BOOTSTRAP.md).
