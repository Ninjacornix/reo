# Actor 6C20B0 command dispatch and room1/2 route script

Static File #1 US research, 2026-11-04. Nine complete original bodies reviewed;
seven additional identical adapters were checked and cited by plain address.
Addresses, offsets, states and room IDs hexadecimal; coordinates/distances decimal.
No execution, attachment, build, replay or engine changes. Original scenario and
interaction names remain unresolved.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C20B0](../recomp/config/output_ovl/o2/o2_006C20B0_0x6c20b0.cpp) | `dispatch_6c20b0_eight_command_states_and_common_post_steps_candidate` | High mechanics | Signed FCF castunsigned<8 indexesowned740EC0. States0/1/2/3/4/5/6/7 call6C21A0/6C2220/6C2290/6C2260/6C2280/6C2240/6C2250/6C2270. Invalidskipsdispatch;all66B850,626190,5BE2D0,6261C0(self). |
| [o2 0x6C21A0](../recomp/config/output_ovl/o2/o2_006C21A0_0x6c21a0.cpp) | `initialize_room_route_command_state_one_without_phase_reset_candidate` | High mechanics | ClearsFD0..3,8..B,FB8/FB7,setsFCF1;unlessBA0 bit80000 setsidleFB7=0,byte1=1. Does not write1150, room, position or slot record. |
| [o2 0x6C2290](../recomp/config/output_ovl/o2/o2_006C2290_0x6c2290.cpp) | `classify_command_admission_or_tick_room_one_two_script_candidate` | High mechanics | 625630=0 runs6C2310 then6257A0(self,+10A4). Result1FCF3;othernonzeroFCF4,health544=0,6260E0(FB5). Bothnonzero684810(self,0). |
| [o2 0x6C2310](../recomp/config/output_ovl/o2/o2_006C2310_0x6c2310.cpp) | `dispatch_room_one_two_script_by_phase_1150_candidate` | High mechanics | Roomhalf1E2=1 maps1150=0/1 to6C2440/6C24E0;phase2onlyidlesunless80000. Room2 maps0/1/2 to6C2630/6C2840/6C28C0. Otherroom/phasevaluesreturn. |
| [o2 0x6C2440](../recomp/config/output_ovl/o2/o2_006C2440_0x6c2440.cpp) | `idle_until_global_4b9c04_bit_one_then_advance_room_route_phase_candidate` | High mechanics | FD2=0 selectsidleunless80000,FD2++;same-callfallthroughandFD2=1 test4B9C04 bit1,nonzero6C2420. OtherFD2returns. |
| [o2 0x6C24E0](../recomp/config/output_ovl/o2/o2_006C24E0_0x6c24e0.cpp) | `approach_fixed_exit_then_deactivate_and_relocate_actor_to_room_two_candidate` | High mechanics | Owned72FE88 target ->1124,6BD270,selectmotion1unless80000. Unless50<=distance,orselectedplayerBA0bit10000set,byte1=0,room1E2=2,XYZ=72FE98,yawC000,6C2420 then1150=0,6C2B60 save. Otherpathsreturn. No actual room-load completion is proved. |
| [o2 0x6C2630](../recomp/config/output_ovl/o2/o2_006C2630_0x6c2630.cpp) | `place_room_two_actor_then_approach_wait_point_or_skip_on_global400_candidate` | High mechanics | 4B9C04 bit400 set clearsFD0/2/3,1150=2,saves6C2B60,returns. Otherwise FD2=0 selects motion1unless80000,FD2++,setsXYZ72FEA8/yawC000 and falls intoFD2=1 steering to72FEB8 through6BD270. Unless50<=distance,clearsFD0/2/3,1150=1,idlesunless80000,saves6C2B60. FD2>=2returns. |
| [o2 0x6C2840](../recomp/config/output_ovl/o2/o2_006C2840_0x6c2840.cpp) | `wait_global400_then_advance_and_save_room_route_phase_candidate` | High mechanics | 4B9C04bit400set6C2420,6C2B60;otherwiseidlesunless80000. No local timer. |
| [o2 0x6C28C0](../recomp/config/output_ovl/o2/o2_006C28C0_0x6c28c0.cpp) | `tick_six_substate_room_two_two_waypoint_and_motion_d_sequence_candidate` | High mechanics | BoundsFD2<6,dispatches740EE0.0selectmotion1unless80000,FD2++,XYZ72FEE8/yawC000,returns.1/2copy corresponding72FED0 vector into1124,6BD270,selectmotion1unless80000;unless50<=distance FD2++.3FF4=8000,FCC1,FD2++,selectmotionDunless80000.4waitsignedFCC0,thenidleunless80000 andFD2++.5return. No1150increment inbody. |

Common idle/motion selection clears8..B/FB8 only on FB7 change, then writesFB7
andbyte1=1, unlessBA0 bit80000. 6C24E0 reads selected player BA0 from
4A67D0+10E0*byte4BADED, i.e.roster base4A5C30 plusBA0, not a different field.

Reviewed identical adapters, deliberately not additional semantic rows:

| Address | Exact reviewed counterpart |
| --- | --- |
| 6C2220 | 6BDC20:FCF2,byte1=1,tail6257A0(self,+10A4). |
| 6C2240/2250/2260/2270/2280 | 6BDC40/50/60/70/80 respectively. |
| 6C2420 | 6BCB00:clearFD0,increment1150,clearFD2/FD3. |

Owned tables/data from `build-function-index/owned-overlays/o2.bin`,base570000,
SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Span | Values / SHA256 |
| --- | --- |
| 740EC0 length20 | [6C20E8,6C20F8,6C2108,6C2118,6C2158,6C2128,6C2138,6C2148]. `08d343d75c6612e6833d08484988e2134917e48c3b85bc91774d052f5aa6a2a7` |
| 740EE0 length18 | [6C2930,6C29A4,6C29A4,6C2A88,6C2AEC,6C2B44]. `1ac02f2ee30c23c34166b5ee58bead4d17f665a0718e4e9ea7e00660a331442f` |
| 72FE88 lengthC | (5327,-3700,9195). `1e266220c3aa77051809300675c1822c0892df8a2992d84ed5c153c1a11e0dc5` |
| 72FE98/72FEA8 eachlengthC | (4695,-3600,8844). Each`86f2b929d259a7c7a956c1194bea54bc5753f62398bc4242ef3c0b6fa95725a9` |
| 72FEB8/72FEE8 eachlengthC | (4432,-3600,8749). Each`aea90500479e7377dfdbbeff507561eebbfea18852365e522d24d2b1b529fd38` |
| 72FED0 length18 | (4398,-3600,7325),(3951,-3600,7310). `1975efd44b65011d04761ef3d00aeb93eff6367f3426e4f86a2ae9174baf42a6` |

6C2B60 is already mapped in [command/runtime state notes](SYMBOLS_ACTOR_6D6DE0_COMMANDS.md).
See [shared route point helper](SYMBOLS_ACTOR_SCRIPT_POSITION_COMPLETION.md) and
[earlier dispatch adapters](SYMBOLS_ACTOR_6BDA50_COMMAND_FAMILY.md).

Full-body owned-word audit: 9 rows, 567 verified instruction words,
zero conflicts, 65 omitted zero/NOP words, zero omitted nonzero words.
