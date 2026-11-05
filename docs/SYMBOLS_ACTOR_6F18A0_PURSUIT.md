# Actor 6F18A0 pursuit and target admission

Static File #1 US research, 2026-11-04. Five complete original bodies reviewed.
Addresses/offsets hex unless marked decimal. Primary-state ownership follows
owned73C100:6F47B0 is primary6;6F56E0 is primary7. This distinction prevents
inventing state names from source order. No execution, build or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6F47B0](../recomp/config/output_ovl/o2/o2_006F47B0_0x6f47b0.cpp) | `dispatch_actor_6f18a0_primary_six_target_tracking_candidate` | High routing; probable role | Caches actor24 in75A108; null target calls77E0 and returns. Unless D68, copies target XYZ to C44..C4C, then unchecked73C158[actor9] calls4840 or4D90. After dispatch5705F0(50,1,0). The bootstrap primary table places this at primary6, not primary7. |
| [o2 0x6F4840](../recomp/config/output_ovl/o2/o2_006F4840_0x6f4840.cpp) | `tick_actor_6f18a0_direct_pursuit_with_detour_and_motion_switch_candidate` | High mechanics; probable role | OR115bit1. A0/FF enters1, clearsD68, aligns toward C44 with7FF8; failure startsA2/descriptor7 and58C780, returns. FF alsoC3640. Aligned start selects descriptor3 unless motionC8. A1:5510 nonzero becomes initial frame for descriptor4 after58C7F0, setssecondary1, chooses B via73C220[random&7], clears115 and returns. Otherwise advances animation; selected BF8[C26]<FA resets77E0, target query634C00(170,4718,0) accepts ->7B50,8350 accepts ->primary1/secondary4/AFF/B0. A2 waits for nonzero animation then A3/descriptor3/C=4/factor; A3 predecrements C, on expiry A1 and yaw XOR8000. Common path uses7F10 trace; nonzero selects detour via634160 when D68 false, E expired, D54>=1E, or XZ distance<=100; seeds E=600/factor,D68=1. Zero clearsD68, may query a node near target, then overwrites C44 X/Z with target X/Z. C83 selects636D90 turning variant; original order and early returns retained. |
| [o2 0x6F4D90](../recomp/config/output_ovl/o2/o2_006F4D90_0x6f4d90.cpp) | `tick_actor_6f18a0_alternate_pursuit_retarget_and_motion_impulse_candidate` | High mechanics; probable role | A0/FF enters1, clearsD68; FF draws B from73C220 andC3640. Failed initial7FF8 alignment ->A3/descriptor7/115bit1/58C780. Aligned start selects descriptor4 unless motionC9, then clears115. A1 advances and pretested scans four players excludingC26 using634C00(170,4718); first acceptance rewrites24/C26/cached peer andA5. Otherwise8350 mayprimary1/secondary4;5610(B) result1/2 startsA2/descriptor5/blend5/115bit1, result3 selectsA5. A2 any nonzero animation entersprimary1 all substates0. A3 animation completion ->A4/descriptor4/C4/factor; A4 expiry ->A1,flip yaw,clear115. A5 rounded frame &7FFE in E/1E/2C entersA6,115bit1,D60=6,D4=owned742EF0=-0.3,sound33,descriptor6/frame16/blend10. A6 advances;1F1bit40 resets77E0; otherwise frame>=36 and D60>0 adds D60 to4EC then D4 toD60. Common detour path mirrors4840, but non-C83 turn uses t0=1. No identity/action or hotspot asserted. |
| [o2 0x6F5510](../recomp/config/output_ovl/o2/o2_006F5510_0x6f5510.cpp) | `choose_actor_6f18a0_pursuit_motion_transition_frame_candidate` | High mechanics; probable role | BD4<=300 decimal returns0. Above300, motion other thanC8 returns1. MotionC8 rounds1E4 using guest cvt.w.s/unsigned branch, keeps lowbyte &7E; masked frame1A->2A,30->18,3E->1A,6C->28, otherwise0. Source also tests8C->18, but &7E prevents that equality. Records literal mechanics without interpreting unreachable case as a player defect. |
| [o2 0x6F5610](../recomp/config/output_ovl/o2/o2_006F5610_0x6f5610.cpp) | `filter_actor_6f18a0_pursuit_class_by_target_metric_and_distance_candidate` | High mechanics; probable role | a1 supplies class; if selected signed BF8[C26]<FA returns original a1. Otherwise only lowbyte1/2/3 can survive, with BD4<=decimal300/150/200 respectively; admitted result is that class, else0. No state writes. Original class meanings remain unknown. |

Owned73C158 contains4840,4D90. Weighted bytes73C220 are1,2,2,2,3,3,3,3.
Motion comparisons use owned halves73C586=C8 and73C58C=C9; these are
original motion IDs, not claims about an original animation name.

The common trace path preserves its counter and near-waypoint admission:
D68 may hold an existing detour; D54 is the bootstrap repeated-XZ-cell count.
Neither a repeated cell nor a nonzero trace result proves a captured stall.
Related [shared controls](SYMBOLS_ACTOR_6F18A0_SHARED_CONTROLS.md) and
[bootstrap](SYMBOLS_ACTOR_6F18A0_BOOTSTRAP.md) cover their observed contracts.
No runtime path frequency, original actor identity or slowdown cause is established.
