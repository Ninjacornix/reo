# Actor 6CC7C0 update, initialization and peer admission

Static File #1 US research, 2026-11-04. Seven complete original bodies reviewed,
including one shared player predicate. Addresses/offsets hex unless marked
decimal. Actor identity, original action names and timers remain unresolved.
No game, build, attachment, replay or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6CC7C0](../recomp/config/output_ovl/o2/o2_006CC7C0_0x6cc7c0.cpp) | `update_actor_6cc7c0_variant_dispatch_and_fixed_height_candidate` | High mechanics; probable role | Replaces54A=18,byte4zero adds5;clears32/C36/C37/C82/root4E4/CE8,C94mask201,setsBA5=decimal99. SnapshotsXYZ/angles,caches24 at755718,nonnull5A98F0(peer byte3)->BD4.635E20(C8C,0,BCC,BD0),13F nonzero220 contact. Byte4nonzero dispatches7308C0[8],zero7308E0[8]. C82zero68A4A0 root movement,nonzero zerosC0;400 mayforceY=-1280. Positive CE4/CE6 decrement,otherwise clamp0.6347D0,existing3C0 transition callback. No callback count is promoted to global game updates. |
| [o2 0x6CC990](../recomp/config/output_ovl/o2/o2_006CC990_0x6cc990.cpp) | `initialize_actor_6cc7c0_peer_variant_shape_and_health_state_candidate` | High mechanics; probable role |63F6B0 lowbyte binds player4A5C30+10E0*i to24/755718;matrix50,preset180,byte1=1,5530,descriptor0/frame0. Initial C94mask201 is later overwritten wholeword0. F0=1,C80/C82/lowbyteCE6/C9A/B/C260,546=544;pretested trackloop clears1FF+20*i. Shape1A8=730988->730950,1D8=730A08->730990,color729018->730A30[byte4] tothreebanks. SetsY=-1280,19020FFFF,1940,551/5524,BDA100,BDC180,5DF9F0(actor,1). If544<=0,sets4/0/A2/B63,BA51,Y+=20,1A8null,descriptorF/frame0. ClearsBE8 fourbytes and C..13 eightbytes. No null actor/model/variant bound added. |
| [o2 0x6CCBF0](../recomp/config/output_ovl/o2/o2_006CCBF0_0x6ccbf0.cpp) | `dispatch_actor_6cc7c0_primary_one_and_hidden_wait_candidate` | High mechanics; probable role | Tail-dispatches730900[secondary9]. MergedCCC10 phase0/FF enters1,byte1=0,replaces54A7;FF C36=1C. Phase1 only whenCE40 queriesCCD90;nonzero callsCCCB0 position seed,then2/0/AFF/B0. No animation advance or ordinary active-player test in merged wait body. |
| [o2 0x6CCCB0](../recomp/config/output_ovl/o2/o2_006CCCB0_0x6cccb0.cpp) | `seed_actor_6cc7c0_entry_x_yaw_and_peer_or_random_z_candidate` | High mechanics; probable role | X=decimal450,Z=cached755718 peerZ,yaw4000. Consumes random-low16%3;zero retains peerZ,nonzero consumes separate draw and setsZ=decimal5700+100*(random-low16%20). Does not changeY,state ormatrix. No peer-null check here. |
| [o2 0x6CCD90](../recomp/config/output_ovl/o2/o2_006CCD90_0x6ccd90.cpp) | `bind_first_player_in_entry_rectangle_unless_action_code_21_to_24_candidate` | High mechanics; probable role | Pretested four-player scan4A5C30+10E0*i.668FF0 must return0,then Z inclusively decimal5700..7800,X strictly1000..1200. First match writesC26,24/755718,returns1. No match returns normalized324330bit20,which can be1 without binding a new peer. No independent actor activity check. |
| [o2 0x6CD1F0](../recomp/config/output_ovl/o2/o2_006CD1F0_0x6cd1f0.cpp) | `bind_first_player_with_action_code_21_through_24_candidate` | High mechanics; probable role | Pretested same four-player scan,first668FF0 nonzero writesC26,24/755718 andreturns1;exhaustion0. No distance,room or actor-active admission in this body. Opposite predicate fromCCD90. |
| [o2 0x668FF0](../recomp/config/output_ovl/o2/o2_00668FF0_0x668ff0.cpp) | `test_actor_action_code_byte54f_is_21_through_24` | Confirmed/static mechanics | Returns1 exactly unsigned54F equals21,22,23,24;other values0. No activity,health,position or pointer checks. Original action-code meanings unconfirmed. |

Owned primary tables7308C0/7308E0 independently decoded:each six populated
pointers6CC990,6CCBF0,6CD290,6CDCF0,6CDE50,6CD9F0,then twozero words.
Both populated banks happen to match; no unchecked zero slots are called in
this investigation.730900 four secondary pointersCCC10,CCEB0,CCEB0,CCEB0,
all prefixed6C. The internalCCC10 target belongs to catalog6CCBF0 and is not
counted separately.

Related [routes](SYMBOLS_ACTOR_6CC7C0_ROUTES.md),
[motion sequences](SYMBOLS_ACTOR_6CC7C0_SEQUENCES.md), and
[shared controls](SYMBOLS_ACTOR_6CE_SHARED_CONTROLS.md).
