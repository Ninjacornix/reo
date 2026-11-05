# Actor 6CC7C0 waypoint and special-player pursuit

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed.
Addresses/offsets hex unless marked decimal. Roles remain candidates; no target
execution, engine changes or measured incident cause.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6CCEB0](../recomp/config/output_ovl/o2/o2_006CCEB0_0x6cceb0.cpp) | `advance_actor_6cc7c0_waypoint_route_or_special_player_transition_candidate` | High mechanics; probable role |1F0 nonzero immediately selects5/0/AFF/B0,advances58C300 at1,returns. Otherwise phaseFF selects633AA0 waypointC44/C9B,seeds E from730938[random-low2]/factor,C36=3B,then phase0->1;selects descriptor0 via050 unless motion730A44. Phase1 computes XZdistance;whenCE40 and636CF0(C44,6388) rejects,enters3,CE4=240/factor,descriptor2+(4BADE8&1),blendA,58C780,returns. Distance<=150 otherwise refreshes633AA0 without copying C9B toC9A. Turns636D90 with C83 step2D8/t0=0 or16C/t0=1,angle3FFC,then58C300 at1. Phase2 completion reset0C0. Phase3 completion ->1,C=6/factor,yaw XOR8000,descriptor0/frame0/blend0. Seeded E is not decremented in this body. |
| [o2 0x6CD9F0](../recomp/config/output_ovl/o2/o2_006CD9F0_0x6cd9f0.cpp) | `dispatch_actor_6cc7c0_primary_five_with_peer_position_snapshot_candidate` | High routing | Copies cached755718 peerXYZ toactorC44 then tail-dispatches730920[byte9]. One populated pointerCDA30,thenzero. No null peer check. Subsequent handler1F0 may rebind peer after this snapshot,so it is not automatically the newly selected player's position. |
| [o2 0x6CDA30](../recomp/config/output_ovl/o2/o2_006CDA30_0x6cda30.cpp) | `advance_actor_6cc7c0_special_player_pursuit_and_reverse_motion_candidate` | High mechanics; probable role |1F0 lowbyte0 resets0C0/returns. Phase0/FF enters1;FF C36=40. CE40 plus636CF0(C44,6388) rejection enters2,CE4=240/factor,descriptor2+(4BADE8&1),blendA,58C780. Accepted/defaultphase0 selects descriptor0 unless ownedmotion100decimal. Phase1 repeats same direction admission;otherwise advances at1,requires640640 then634C80(actor,cachedPeer,decimal500,5550,0) to call1D0 preset. Phase2 animation completion ->1,yaw XOR8000,descriptor0/blend0. Common turn when no early return:C83 usesBDC/1FFE/t0=0,otherwiseBDA/6AA4/t0=1;adds returned yaw delta. |

Owned730938 signed-half E values decimal240,360,480,600. Descriptor0 motion
comparison uses owned730A44=decimal100. No count of these actor callbacks is
interpreted as a global update or display rate.

Related [bootstrap](SYMBOLS_ACTOR_6CC7C0_BOOTSTRAP.md) and
[sequences](SYMBOLS_ACTOR_6CC7C0_SEQUENCES.md).
