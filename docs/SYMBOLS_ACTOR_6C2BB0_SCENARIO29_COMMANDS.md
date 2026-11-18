# Actor 6C2BB0 command family and scenario29 room50/4C script

Static File #1 US research, 2026-11-04. Seven complete original bodies reviewed;
seven identical entry/adapters also checked and cited as plain cross-references.
Addresses/offsets/room/scenario IDs hexadecimal; coordinates/distances decimal.
No execution, attachment, build, replay or engine changes. Numeric scenario29
and room IDs are observed; original scenario names remain unresolved.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C2BB0](../recomp/config/output_ovl/o2/o2_006C2BB0_0x6c2bb0.cpp) | `dispatch_6c2bb0_eight_command_states_and_common_post_steps_candidate` | High mechanics | SignedFCF castunsigned<8 indexes740F00. States0/1/2/3/4/5/6/7 call6C2CA0/6C2D20/6C2D90/6C2D60/6C2D80/6C2D40/6C2D50/6C2D70. Invalidskipsdispatch;all66B850,626190,5BE2D0,6261C0(self). |
| [o2 0x6C2D90](../recomp/config/output_ovl/o2/o2_006C2D90_0x6c2d90.cpp) | `classify_command_admission_or_tick_scenario29_room_script_candidate` | High mechanics | 625630=0 calls6C2E10 then6257A0(self,+10A4). Result1FCF3;othernonzeroFCF4,health544=0,6260E0(FB5). Bothnonzero684810(self,0). |
| [o2 0x6C2E10](../recomp/config/output_ovl/o2/o2_006C2E10_0x6c2e10.cpp) | `tick_room_script_only_when_scenario_3243da_equals29` | High mechanics | Half3243DA=29 calls6C2E50(self);otherwise nohandler. No state advance or write inwrapper. |
| [o2 0x6C2E50](../recomp/config/output_ovl/o2/o2_006C2E50_0x6c2e50.cpp) | `dispatch_scenario29_room50_phases_or_room4c_fcc_motion_eight_candidate` | High mechanics | Room50:1150=0/1/2 ->6C2FD0/6C3060/6C3130. Room4C phase0 setsFD4=64D,1155=1,FCC1,FB7=FF,selectsmotion8unless80000,then incrementsFD1 (not1150). Room4C phase1 waitsFCC0 thenrepeatsFD4/1155/FCC/FB7 writes andmotion8selection,withoutphaseincrement. Phase2andotherroom/phasevaluesreturn. Exactcounterdifferencepreservedwithout runtimefailureclaim. |
| [o2 0x6C2FD0](../recomp/config/output_ovl/o2/o2_006C2FD0_0x6c2fd0.cpp) | `initialize_idle_and_immediately_advance_scenario29_phase_candidate` | High mechanics | FD2=0 selectsidleunless80000,FD2++;same-callfallthroughandFD2=1 unconditionally6C2420,which increments1150andclearsFD0/2/3. OtherFD2returns. |
| [o2 0x6C3060](../recomp/config/output_ovl/o2/o2_006C3060_0x6c3060.cpp) | `approach_scenario29_fixed_position_and_advance_within50_candidate` | High mechanics | Copies72FEF8 XYZto1124,6BD270,selectsmotion1unless80000;unless50<=distance,6C2420. No local room or slot-record write. |
| [o2 0x6C3130](../recomp/config/output_ovl/o2/o2_006C3130_0x6c3130.cpp) | `rotate_then_relocate_actor_and_write_room4c_slot_record_candidate` | High mechanics | SlotR=390210+78*FB5. FD2=0 selectsmotion3unless80000,FD2=1,FCC1,FF4=4000,returns.1waitsignedFCC0,thenFD2=2,byte1=0,returns.2setsXYZ72FF08,FD2=3,mirrorsXYZtoR8/C/10,yawBC90toactor92/R14,Rbyte1=4C,Rword28=0.3returns. Does not write actor1E2,1150 or reactivatebyte1. Actualroomtransitioncompletionrequiresothercode. |

Motion changes use the established FB7 selector, clear8..B/FB8 on change and
writebyte1=1 unlessBA0bit80000. ForcedFB7=FF precedes the ownership flag gate in
room4C; it still happens when flag80000 prevents localmotionwrites. Room4C
phase0 incrementsFD1, so it does not locally proceed tophase1 by1150. This is
an exact static observation, not a reproduced symptom or proposed fix.

Reviewed identical bodies excluded from new semantic rows:

| Address | Counterpart |
| --- | --- |
| 6C2CA0 | 6C21A0 command-state-one initializer,1150unchanged. |
| 6C2D20 | 6BDC20 state2 plus tail6257A0(self,+10A4). |
| 6C2D40/50/60/70/80 | 6BDC40/50/60/70/80 respectively. |

Owned740F00 length20 eightinternal targets:
`[6C2BE8,6C2BF8,6C2C08,6C2C18,6C2C58,6C2C28,6C2C38,6C2C48]`;
SHA256`1b3031caa21339c39bbbc6e030525bd8af69fdf7ae5199f16c087f57d55f93dc`.
Owned72FEF8 lengthC XYZ(6187,0,9355),SHA256
`9f69dc6440ad04a37b15787e15a3b17d131a938b768d2202a9a5e0666e693941`;
72FF08 lengthC XYZ(4200,-1200,9241),SHA256
`285edb900023bbb682ac0c95aefb28519914c41ec3b6dbdda7d2dd80b51744f3`.
Owned image
`build-function-index/owned-overlays/o2.bin`,base570000,
SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.
See [room1/2 script and shared adapters](SYMBOLS_ACTOR_6C20B0_ROOM_ROUTE_COMMANDS.md)
and [route helper](SYMBOLS_ACTOR_SCRIPT_POSITION_COMPLETION.md).

Full-body owned-word audit: 7 rows, 319 verified instruction words,
zero conflicts, 42 omitted zero/NOP words, zero omitted nonzero words.
