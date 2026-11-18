# Actor 6C45D0 room8/B demo bank and scripted command family

Static File #1 US research, 2026-11-04. Eight complete original bodies reviewed;
seven identical adapters checked and cross-referenced without new aliases.
Addresses/offsets/room IDs/selectors hexadecimal; coordinates and counts decimal.
Named bank bytes are verified, original scene names unresolved. No execution,
attachment, build, replay or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C45D0](../recomp/config/output_ovl/o2/o2_006C45D0_0x6c45d0.cpp) | `dispatch_6c45d0_eight_command_states_and_common_post_steps_candidate` | High mechanics | SignedFCF castunsigned<8 indexes740F20.0/1/2/3/4/5/6/7 call6C46C0/6C4740/6C47B0/6C4780/6C47A0/6C4760/6C4770/6C4790. Invalidskipsdispatch;all66B850,626190,5BE2D0,6261C0(self). |
| [o2 0x6C4740](../recomp/config/output_ovl/o2/o2_006C4740_0x6c4740.cpp) | `set_command_state_two_and_activate_without_motion_route_call` | High mechanics | SetsFCF2,byte1=1,returns. No6257A0 tailcall,unlike6BDC20. |
| [o2 0x6C47B0](../recomp/config/output_ovl/o2/o2_006C47B0_0x6c47b0.cpp) | `classify_command_admission_or_tick_room8_b_demo_script_candidate` | High mechanics | 625630=0 runs6C4830 then6257A0(self,+10A4). Result1FCF3;othernonzeroFCF4,health544=0,6260E0(FB5);bothnonzero684810(self,0). |
| [o2 0x6C4830](../recomp/config/output_ovl/o2/o2_006C4830_0x6c4830.cpp) | `dispatch_room8_four_demo_phases_or_room_b_waypoint_cycle_candidate` | High mechanics | Room1E2=8 maps1150=0/1/2/3 to6C4900/6C49D0/6C4AB0/6C4D30. RoomB calls6C4F30 regardless1150. Otherrooms/phasesreturn. |
| [o2 0x6C4900](../recomp/config/output_ovl/o2/o2_006C4900_0x6c4900.cpp) | `wait_global4_then_resolve_target_enqueue_s28_demo1_bank_and_advance_candidate` | High mechanics; bank name verified | Selectsidleunless80000.4B9C00bit4set:byte1=0,581C50(0,self),snapXYZ=ABC/AC0/AC4,yaw=AC8lowhalf,1AD610(owned740F40 name, C),6C48E0. Bitclearalsofinallybyte1=0. Thus allpathsdeactivate locally,evenafteridle selection. Bankenqueue result is ignored;actualsuccessfulloadnotproved. |
| [o2 0x6C49D0](../recomp/config/output_ovl/o2/o2_006C49D0_0x6c49d0.cpp) | `start_motion_six_then_wait_fcc_and_bank_status_before_phase_advance_candidate` | High mechanics | FD2=0selectsmotion6unless80000,FD2++,FCC1,byte1=1unconditionally,5BF0F0(7,FFFF);fallsinto1.1waitsFCC0,1AD700(C)>=0 then684810(self,1),6C48E0. OtherFD2returns. No original sequenceevent7meaning inferred. |
| [o2 0x6C4AB0](../recomp/config/output_ovl/o2/o2_006C4AB0_0x6c4ab0.cpp) | `tick_64a_64c_64b_fcc_sequence_and_six_counter_events_candidate` | High mechanics | FD2states0..3plusindependentFD3/FC4/FC6 event counter,completebelow. ForcedFB7=FFbeforemotion8 causes resetwhen80000clear. FCC gate advances numericmotions64A,64C repeatedtwice,64B;completionpublishes684810(self,1),6C48E0. Calls are requests,not proven completed demo playback. |
| [o2 0x6C4D30](../recomp/config/output_ovl/o2/o2_006C4D30_0x6c4d30.cpp) | `rotate_motion_three_then_relocate_to_slot_room_b_and_delay_candidate` | High mechanics | SlotR=390210+78*FB5.FD2=0 adds58E4toyaw,selectsmotion3unless80000,FD2++,FCC1,FF4=8000,5BF140(),570370(3),fallsinto1.1selectedplayerBA0bit10000set jumpsdirectlyrelocation;otherwisewaitsFCC0 thenFD2++,byte1=0,returns.2relocatesXYZ7304D0,FD2++,mirrorsXYZ/yawintoR8..14,Rbyte1=B,Rword28=0,FC4=60decimal. Directbitpathincrements1->2 here,so nextcallstate2relocatesagain before3.3predecrementsFC4;post<0FD2++.4returns. Doesnotwriteactor1E2or1150. |

6C4AB0 details, all branch/delay paths reviewed:

| FD2 | Behavior |
| --- | --- |
| 0 | FD4=64A,1155=1,FCC1,FB7FF,selectmotion8unless80000,FC4/FC6/FC8=0,FD2++;falls1. |
| 1 | OnFCC0incrementFC8;count>=3setsFD2=2 andreturns tocounterwork. Lowercountsetsyaw271C,FD4=64C,1155=1,FCC1,FB7FF,selectmotion8unless80000. |
| 2 | FD2++,FD4=64B,1155=1,FCC1,FB7FF,selectmotion8unless80000. |
| 3 | FCC0publishesselector1,6C48E0,andreturnsskippingeventcounter;otherwisecounterwork. |
| other | Counterwork only. |

Counterwork runswhenFD3=0. Compare signedFC4 with7304C0[signedFC6];equality
atFC4=12 additionally1B93B0(bankC,event0,owner0). Equalitycalls
5BF0F0(7304B8[FC6],FFFF),FC6++;newFC6>=6setsFD3=1. ThenFC4++.
Owned thresholds(decimal)[0,18,226,406,496,0],eventshex[6,6,5,4,4,0]. The final
zero is literal, not assumed to be a sentinel; no local sorted-table check.
No host blocking loop or measured counter cadence is asserted.

Reviewed aliases:6C46C0=6C21A0;6C4760/4770/4780/4790/47A0=
6BDC40/50/60/70/80;6C48E0=6BCB00. Commonmotionselection/ownershipflag
contracts are in[earlier room script](SYMBOLS_ACTOR_6C20B0_ROOM_ROUTE_COMMANDS.md).
Waypoint consumer6C4F30 is reviewed separately in
[roomB route](SYMBOLS_ACTOR_ROOM_B_WAYPOINT_CYCLE.md).

Owned data: `build-function-index/owned-overlays/o2.bin`,base570000,SHA256
`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

| Span | Values / SHA256 |
| --- | --- |
| 740F20 length20 | [6C4608,6C4618,6C4628,6C4638,6C4678,6C4648,6C4658,6C4668]. `980a755ca23a3f7501620c4f3337c9b0fba8f85d7f5a8f27462cf4d75975bb79` |
| 740F40 length10 | ASCII`s28_demo1` followedsevenzero bytes (full16-bytecopyinput). `0371dc211b515d3904e5f6b96d9b98199e4d761de107efbe766257bc6552770c` |
| 7304B8 length6 | bytes[6,6,5,4,4,0]. `4d9312015c2341b60aa86e78abb222e5b7ec8d05ccd254d589d4e96b459b2fba` |
| 7304C0 lengthC | signedhalves(decimal)[0,18,226,406,496,0]. `d85b3e39fec3f6f150e1a90291d59005534a2275e1775e2522cc44a1db37d84e` |
| 7304D0 lengthC | XYZ(5743,800,2655). `84aa0c9e997eb597c4212ff2b715a2e1bb9419fb149216633fa6535eea581fc2` |

Full-body owned-word audit: 8 rows, 471 verified instruction words,
zero conflicts, 50 omitted zero/NOP words, zero omitted nonzero words.
