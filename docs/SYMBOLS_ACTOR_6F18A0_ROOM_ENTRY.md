# Actor 6F18A0 room-entry placement and staged actions

Static File #1 US research, 2026-11-04. Four complete original bodies reviewed, including merged6F6850. Addresses/offsets hex unless marked decimal; constants are preserved as guest integers where useful. Original room/action meanings unknown. No execution, build, attachment or engine edits.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6F6810](../recomp/config/output_ovl/o2/o2_006F6810_0x6f6810.cpp) | `dispatch_actor_6f18a0_primary_nine_and_initialize_room_entry_candidate` | High mechanics; probable role | Sets54A=F,32FF,C94|201, taildispatch73C1A8[9]. Internal6850 A0->1,B0,byte1=1,553=1,AB8/AB9=0; resource byte74F274+60*B98 selects placement. Always5705F0(50,1,0). For ID<10 calls581730(1,ID,actor),581DC0(ID) range0..6 dispatch742ED0:0 common snap;1 C1;2/3/4 descriptor0/blend0,C=90/factor;5/6 C1+6B5920. Common snap yawAC8/XYZABC. ID>=10 setsE=120/factor and6B10; result0 selectssecondary2/descriptor3 then early return; result1 secondary1/descriptor6 then early return; other selectssecondary2/descriptor3 then common snap. A1 advances,decrements C;expiryA2/descriptor12/blend10;alwaysC82=1. A2 nonzero advance ->77E0 then6367C0. |
| [o2 0x6F6B10](../recomp/config/output_ovl/o2/o2_006F6B10_0x6f6b10.cpp) | `place_actor_6f18a0_at_room_specific_entry_and_return_action_class_candidate` | High mechanics; probable role | Room51 sets X integer1B21,Y0,Z23D0,yaw8000,returns0. Room53 uses4B9C04bit40000000: set ->X1B21,Y0,Z22FA,yaw0,return0;clear ->Z22D6,return1. Room56 setsX20ED,Y400 decimal,Z1FDC,yaw8000,return0. Room5B uses4B9C0Cbit1000: set ->X20ED,Y400,Z1F6B,yaw0,return0;clear ->X20EC,Y400,Z1F31,yaw0,return1. Other rooms call581730(2,(a1low8-10)&FF,actor),return2. No heading interpolation or room-name guess. |
| [o2 0x6F6CE0](../recomp/config/output_ovl/o2/o2_006F6CE0_0x6f6ce0.cpp) | `tick_actor_6f18a0_primary_nine_secondary_one_room_event_candidate` | High mechanics; probable role | A0 advances until frame>=26 decimal, thenA1. Room53 signals5703E0(3E,1),room5B signals(6C,1), each5BF1B0(0,0,30/factor,f12=2); other rooms just advance phase. A1 advances until1F1bit40 ->A2,C120/factor,descriptor3/frame0/blend10. A2 advances and decrements C;post<=0 calls77E0 then6367C0. Other phases return. |
| [o2 0x6F6ED0](../recomp/config/output_ovl/o2/o2_006F6ED0_0x6f6ed0.cpp) | `tick_actor_6f18a0_primary_nine_secondary_two_timed_hold_candidate` | High mechanics; probable role | A0->1,C180/factor. A1 predecrements C;post<=0 calls77E0 then6367C0. All phases, including setup and reset calls, subsequently58C300(1) then5705F0(50,1,0). Preserves animation/event work after reset rather than implying an immediate return. |

Owned73C1A8 contains internal6850,6CE0,6ED0. Owned742ED0 query cases
0..6 target6A48,6978,691C,691C,691C,695C,695C within6F. The differing
early-return paths after6B10 retain its literal room coordinates, while the
other/default path overwrites position with ABC. This distinction is observed
control flow; no claim about intended scenario behavior follows.

Related [goal interaction](SYMBOLS_ACTOR_6F18A0_GOAL_INTERACTION.md) and
[bootstrap](SYMBOLS_ACTOR_6F18A0_BOOTSTRAP.md). Runtime admission and cost
remain unknown.
