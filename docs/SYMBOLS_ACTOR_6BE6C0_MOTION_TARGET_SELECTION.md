# Actor 6BE6C0 motion and roster action selection helpers

Static File #1 US research, 2026-11-04. Nine complete original bodies reviewed.
Addresses, offsets and state selectors hexadecimal; distances/counts decimal.
Original actor and action names remain unknown. No execution, attachment, build,
replay or engine changes. Return quirks are preserved as observed mechanics.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C0400](../recomp/config/output_ovl/o2/o2_006C0400_0x6c0400.cpp) | `count_motion_joints_then_select_signed_motion_and_refresh_pose_candidate` | High mechanics | Advances global half7556F8 from0 while below unsigned byte[actor51C]+1; loop only increments counter, no joint writes. Sign-narrows a1 to16 bits,6346C0(actor,a1,a2,a3,f12),58C7B0(actor). Other motion arguments remain supplied by caller. |
| [o2 0x6C0470](../recomp/config/output_ovl/o2/o2_006C0470_0x6c0470.cpp) | `refresh_actor_target_binding_and_select_next_action_candidate` | High mechanics | ClearsCF5,6C05D0. Lowbyte result0 orFF setsC26=0; positive1..3 leaves previousC26 unchanged. Resolves word24/global7556E8 fromC26 and roster base4A5C30/stride10E0,6C0700,OR115 bit1; installs shape/descriptor fields below. a1 lowbyte=1 additionally58C300(rate728FF0+12*BA1). No claim that the returned nearest index becomes the binding. |
| [o2 0x6C05D0](../recomp/config/output_ovl/o2/o2_006C05D0_0x6c05d0.cpp) | `scan_four_roster_candidates_with_previous_selected_flag_gate_candidate` | High mechanics; intended gate unknown | Starts best999999 float and selectedFF; scans four records. Reject666080(actor,0), then tests BA0 bit8 on roster[selected] (initially indexFF, not current index), then6689B0(current). Uses5A9950(self,signed currentindex) and strictclosest update. Returns selected index orFF. The unusual previous-selection address is literal static behavior; its live validity is unproven. |
| [o2 0x6C0700](../recomp/config/output_ovl/o2/o2_006C0700_0x6c0700.cpp) | `choose_actor_action_tuple_from_target_status_motion_and_distance_candidate` | High mechanics | Global7556E8 target rejected by6689B0/666080/BA0 bit8 sets tuple8/9/A/B=(1,4,FF,0). Matching motion72FE50 sets(1,0,FF,0). Otherwise6C0880 may install primary2 and exit. Motions66/67/70 use6C0AD0 threshold800, select owned72FC80 row2/3 on zero/nonzero; others threshold500 choose row0/1. RNGstream1&7 selects byte9; primary8=1,A=FF,B=0. |
| [o2 0x6C0880](../recomp/config/output_ovl/o2/o2_006C0880_0x6c0880.cpp) | `admit_first_priority_target_and_install_primary_two_action_candidate` | High mechanics | Requires640640 lowbyte nonzero. Four BB6..BB9 entries select roster records; skip fullBA0==178 or666080 nonzero. Calls6C09A0(self,BD4), not with candidate. First result!=FF installs primary8=2,secondary9=result,A=FF,B=0,C26=priority ordinal,word24=roster[BB6+ordinal],returns1. No success returns0. No nearest-distance search here. |
| [o2 0x6C09A0](../recomp/config/output_ovl/o2/o2_006C09A0_0x6c09a0.cpp) | `classify_primary_two_action_from_z_distance_motion_and_cooldowns_candidate` | High mechanics | Requires640640 lowbyte. ActorZ<3860 returns2; otherwise f12 must satisfy<=1100. Motions66/67/70:<=700 returns1, else<=900 returns3, elseFF. Other motions:CEE=0 and<=700 returns0; otherwiseCF0>0 returns0,else2. Ordered comparisons preserved, no target writes. |
| [o2 0x6C0AD0](../recomp/config/output_ovl/o2/o2_006C0AD0_0x6c0ad0.cpp) | `find_first_admitted_roster_with_metric_below_threshold_plus_one_candidate` | High mechanics | Requires640640 lowbyte orFF. Four roster entries:666080=0,BA0 bit8 clear,6689B0=0;5A98F0(self,signedindex)<f12 returnsindex+1 immediately. None returns0. This is first admitted, not nearest. |
| [o2 0x6C0BD0](../recomp/config/output_ovl/o2/o2_006C0BD0_0x6c0bd0.cpp) | `choose_random_primary_secondary_tuple_or_force_primary_two_for_field4_candidate` | High mechanics | If6C0F00 returns1 exit. RNGstream1&F indexes four-byte72FCB0 rows; copies firsttwo bytes to8/9,A=FF,B=0,CF5=1. Actorbyte4=1 overrides8=2,9=0. |
| [o2 0x6C0F00](../recomp/config/output_ovl/o2/o2_006C0F00_0x6c0f00.cpp) | `enter_idle_action_with_random_timer_when_global_640640_disallows_candidate` | High mechanics | If640640 lowbyte nonzero returns0. Otherwise tuple(1,0,0,0),timerhalfE=owned72FCA0[RNGstream1&3]/unsigned74F200,returns1. Division semantics and nonzero-factor expectation retained. |

6C0470 installs word1A8=owned72FD38 (pointer72FD00),word1D8=owned72FDE8
(pointer72FD40). It loads pointer728FFC->72FE00, then that pointer's first word
as a shape pointer; its four floats becomeC70..C7C, copied to1AC..1B8 and1BC..1C8.
Asset validity and exact collision shape semantics are not inferred from pointers.

Owned table spans from `build-function-index/owned-overlays/o2.bin`, base570000,
SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Span | Values / SHA256 |
| --- | --- |
| 72FC80 length20 | Four eight-byte rows[0,0,0,0,4,4,4,4],[3,3,3,3,3,3,3,3],[4,4,4,4,4,4,4,4],[4,4,4,4,4,4,4,0]. `1930f3f9e77e7c0944732260112a810e9cf2815b60d8e7c9cbb943a71d90bffe` |
| 72FCA0 length8 | Signed halves[100,120,120,150] decimal. `50a0e0dc3947c5b34474def08222fbc0267524a04568dbd5ceb51bee00e3a6b3` |
| 72FCB0 length40 | Sixteen four-byte tuples: seven[2,0,0,0],six[2,1,0,0],two[2,2,0,0],one[1,0,0,1]. `16d5bf543c187069f12fc5e1f2034e9fb64e2a05a745a3cb27f602b97f0a8cbd` |

Selector bounds are established where explicitly stated; other table and pointer
admissions remain caller/asset contracts. No original action labels or performance
conclusions follow from the numeric thresholds alone.

Full-body owned-word audit: 9 rows, 556 verified instruction words,
zero conflicts, 19 omitted zero/NOP words, zero omitted nonzero words.
