# Actor 6D alignment change and fall handlers

Static File #1 US research, 2026-11-04. Five complete original bodies reviewed.
Addresses and offsets are hex unless marked decimal. Original action and actor
identity unconfirmed. No target execution or changes to game speed/rendering.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6CFE50](../recomp/config/output_ovl/o2/o2_006CFE50_0x6cfe50.cpp) | `advance_actor_6d_descriptor_four_fall_to_lower_height_candidate` | High mechanics; probable role | Phase0->1,descriptor4/frame0. Phase1 positive signed animation result ->2,BA51,C40=currentY-(D2C+decimal166),exact0 replaced owned7410A0(~0.001),3C70(heightC40,velocity-10),then signed E*=bytefactor,descriptor5/frame0. Phase2 BA51,AC-=D0,Y+=AC,advances animation at20/E; E is not decremented here. Positive result or Y<D2C+166 enters3,BA5/BA3=0,5A8420(actor,D00),Y=D2C,descriptor6,C36=7. Phase3 positive result calls17C0 when544>0,else1BB0(actor,4,5). Other phases return. |
| [o2 0x6D0070](../recomp/config/output_ovl/o2/o2_006D0070_0x6d0070.cpp) | `advance_actor_6d_surface_transition_motion_and_restore_substate_candidate` | High mechanics; probable role | Every call BA51,54AmaskD,32FF;unsigned phase<7 uses owned741020. Phase0/1 start descriptor2/3,phase4,C821;phase2 starts descriptor2,phase5;phase3 descriptor2,phase6. Phases4/5/6 advance until positive signed result,save8/9 atBE8/BE9,restore secondary fromB,phase1,B0,C821. Selector3243DA29/3243DC25 additionally E&=F. Calls3A70(actor,restored secondary). Phase4 refreshes quaternionD18 using currentBA3 and3370 support snap. Phase5 toggles BA3:1->0,otherwise1,refreshes quaternion. Phase6 toggles1->2,otherwise1,refreshes quaternion. All finish C36=7;every path copies currentXYZ to80/84/88,including phase>=7. No primary change in this body. |
| [o2 0x6D0380](../recomp/config/output_ovl/o2/o2_006D0380_0x6d0380.cpp) | `interpolate_actor_6d_to_cached_pose_and_restore_saved_state_candidate` | High mechanics; probable role | Each call replaces54A with5 and setsC821. Phase0 enters1,CBC=decimal20,divides CB0XYZ and signed CC0 by20,selects descriptor1/frame0 through38B0,58C7B0. Phase1 advances animation,adds deltas toXYZ/yaw,predecrements CBC. Post<=0 snaps XYZ=CA4,yaw=CBE,restores action bytes fromCC2..CC5 and timersC/E fromCC6/CC8. Not a frame-clock rate estimate; saved values define destination/state. |
| [o2 0x6D0BE0](../recomp/config/output_ovl/o2/o2_006D0BE0_0x6d0be0.cpp) | `advance_actor_6d_reorienting_fall_and_health_response_candidate` | High mechanics; probable role | Phase0 descriptor19,phase1,C=20/factor,A8XYZ=5*factor*D00 thenAC=0 (overwritingY component),D0=factor. Phase1 subtractsD0 fromAC,adds A8XYZ to position,predecrements C:positive reducesD00.Y by owned741098(~0.2),normalizes and rebuilds mode1 quaternion;exact0 clears horizontalA8/B0,setsD00.Y=-2,normalizes/rebuilds. Negative C skips these orientation changes. Positive animation result ->2,BA51,C40=currentY-(D2C+owned741090~22.8),exact0->7410A0;clearsBA3,5A8420,3C70(C40,currentAC),descriptor1A,58C7B0. Phase2 integrates Y,predecrements E;only post<0 enters3,BA50,Y=D2C,descriptor1B;always advances at1 afterwards. Phase3 positive animation result selects4/1 when544>0,else4/2 through1BB0. |
| [o2 0x6D0F00](../recomp/config/output_ovl/o2/o2_006D0F00_0x6d0f00.cpp) | `advance_actor_6d_direct_fall_and_health_response_candidate` | High mechanics; probable role | Phase0 descriptor16/phase1. Phase1 positive result ->2,BA51,C40=currentY-(D2C+~22.8),exact0->0.001,BA30/5A8420,3C70(C40,-10),descriptor17/58C7B0. Phase2 integratesAC-=D0,Y+=AC and predecrements E;post<0 ->3,BA50,Y=D2C,descriptor18,then animation advances at1. Phase3 positive result calls1BB0 to4/1 or4/2 by signed544>0. Independently reviewed distinct from0BE0: no initial horizontal movement/reorientation stage. |

Owned741020 phase pointers are00C4,00E4,0104,0124,0144,01E8,02A0,
all prefixed6D. Signed animation completion checks in these handlers require
result>0, not merely nonzero. All countdown entry targets and endpoint tests
were followed; no invented underflow or stall diagnosis.

Related [surface probes](SYMBOLS_ACTOR_6D_SURFACE_PROBES.md),
[state selection](SYMBOLS_ACTOR_6D_STATE_SELECTION.md), and
[alignment helpers](SYMBOLS_ACTOR_6D_ALIGNMENT_MOTION.md).
