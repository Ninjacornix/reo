# Actor 703300 animation, admission and contact controls

Static File #1 US research, 2026-11-04. Twelve complete original bodies
reviewed, including their branch delay slots. Addresses and offsets are hex
unless marked decimal. Actor identity, original state names and callback enums
remain unknown. No target execution or engine changes; no slowdown diagnosis.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x706260](../recomp/config/output_ovl/o2/o2_00706260_0x706260.cpp) | `select_actor_703300_transition_frame_from_motion_c8_candidate` | High mechanics; probable role | BD4<=decimal300 returns0. Otherwise motion!=C8 returns1, including the branch delay value. MotionC8 converts frame1E4 through guest cvt.w.s/unsigned branch then masks FF: frame1A->2A,30->18,3E->1A,6C->28,8C->18; every other lowbyte returns0. This is an exact frame test, not frame crossing. |
| [o2 0x706E70](../recomp/config/output_ovl/o2/o2_00706E70_0x706e70.cpp) | `set_actor_703300_track_flags_and_animation_descriptor_candidate` | High mechanics; probable role | a0 actor, a1 signed-low16 descriptor, a2 lowbyte track flag bank, f12 initial frame, f13 blend. Calls706F90 first, then copies73DA28[5*bank+i] to1FF+20*i for pretested actor51C->byte1 tracks. Converts blend through guest cvt.w.s with explicit unsigned2^31 handling and calls707010(actor,descriptor,converted blend,original frame), then58C7B0. No factor multiplication of blend in this wrapper. |
| [o2 0x707010](../recomp/config/output_ovl/o2/o2_00707010_0x707010.cpp) | `apply_actor_703300_motion_descriptor_to_unmasked_tracks_candidate` | High mechanics; probable role | Signed-low16 descriptor addresses a six-byte record73DCB0+6*d; signed half+4 is the motion ID. Pretested loop over actor51C->byte1 tracks skips nonzero1FF+20*i. Otherwise calls58B9A0(actor,inherited a1,motionID,unsigned-low16 track,f12 initial frame,f13 unsigned-converted original a2), then writes motionID to1F2+20*i. The call-site a1 is the asset pointer loaded for loop count, not a newly invented bank argument. All tracks use the same descriptor halfword. |
| [o2 0x707110](../recomp/config/output_ovl/o2/o2_00707110_0x707110.cpp) | `reset_actor_703300_route_defaults_or_health_threshold_transition_candidate` | High mechanics; probable role | Clears D65/D48/C2E, restores shape1A8=73C454 and1D8=73C52C and shared72905C->word4 color into C70/1AC/1BC. If byte4 nonzero and signed544<=signedD4E, sets D4E=544-decimal1000 and state2/4/AFF/B0. Otherwise707210 performs ordinary weighted selection. No direct animation start here. |
| [o2 0x707210](../recomp/config/output_ovl/o2/o2_00707210_0x707210.cpp) | `choose_actor_703300_weighted_default_route_after_admission_candidate` | High mechanics; probable role | Returns immediately if707BA0 accepts its fallback. Otherwise707770 performs reversed-yaw player query, whose return is unused; separate random-low4 chooses four bytes73DA40[4*i] into8..B, then A becomesFF. A second random-low2 selects signed-half E from73DA80 divided by byte74F200. Owned rows are ten1/0/0/0, two2/0/0/0, one2/3/0/0, two5/0/0/0, one5/1/0/0. Preserve the ignored query's possible side effects. |
| [o2 0x707310](../recomp/config/output_ovl/o2/o2_00707310_0x707310.cpp) | `choose_actor_703300_distance_variant_weighted_action_candidate` | High mechanics; probable role | 707BA0 fallback first. Random-low4 selects row in73DA90 +80*byte4 +40*(BD4>decimal300). Copies row bytes0..2 to8..A then overwrites A=FF/B=0; row byte3 becomes D65. Selected2/3 with D50 nonzero becomes6/1. Second random-low3 seeds signed C from73DCA0/factor; D6B records resulting C==0. D65 nonzero seeds D48=decimal180/factor; zero clears D48. Selected6/1 then uses706260 to start descriptor4 at returned nonzero frame/blend decimal10, or replaces secondary1 with0 on zero. No timer or random draws merged. |
| [o2 0x707770](../recomp/config/output_ovl/o2/o2_00707770_0x707770.cpp) | `query_actor_703300_four_players_with_reversed_yaw_candidate` | High mechanics; probable role | Temporarily XORs yaw8000, pretested scan of four player records4A5C30+10E0*i via634C00(actor,player,distance decimal500,angle5550,argument14). First accepted query returns index0..3; exhaustion returns-1. Restores yaw with XOR on both paths. No persistent turn. |
| [o2 0x707870](../recomp/config/output_ovl/o2/o2_00707870_0x707870.cpp) | `dispatch_actor_703300_contact_response_and_primary_transitions_candidate` | High mechanics; probable role |640640 nonzero plus13D==B sets544=1. Calls634880(C2A),637490; caches returned contact75A4F0 and actor11C. 377000 supplies direction, quantized yaw difference becomes B1F0..7; restores shape1D8, sets10=8/factor, calls666D40(contact) and72B820[141](actor,2B). Unless13E==4, divides word138 by5, calls636EB0(C24), and C94bit20 setsC36=58.6407D0(actor,contact,decimal500) classification drives state:1 ->4/0/AFF/B0,32FF,666D00 and optional byte4-gated events9C plus9B when13D==B else9A;2 ->707B50, then clearsC94bit20; other ->3/1/AFF/B0. For13E==4,707C40 result1 returns0, result2 clears both CD8/CFC pulse selectors and restores CD8 from73D9E0 via5A7C40 then returns1; zero follows classification. Result contracts depend on helpers; no damage enum inferred. |
| [o2 0x707B50](../recomp/config/output_ovl/o2/o2_00707B50_0x707b50.cpp) | `select_actor_703300_primary_two_secondary_three_candidate` | High mechanics; probable role | Consumes1AEC80(1), stores low4 at75A500, sets8/9/A=2/3/FF. Does not clear B or use the random value to choose state in this body. |
| [o2 0x707BA0](../recomp/config/output_ovl/o2/o2_00707BA0_0x707ba0.cpp) | `enter_actor_703300_primary_five_when_admission_query_rejects_candidate` | High mechanics; probable role |640640 lowbyte nonzero returns0 without state writes. Zero sets8=5 and9/A/B=0, seeds E from73DA80[random-low2]/factor, returns1. Timer bank decimal120,180,180,300. Exact meaning of admission query remains unknown. |
| [o2 0x707C40](../recomp/config/output_ovl/o2/o2_00707C40_0x707c40.cpp) | `classify_actor_703300_contact_window_for_motion_321_candidate` | High mechanics; probable role | Motion equals owned73DCCC (decimal211) ->1. Motion differs from owned73DD3E (decimal321) ->0. For motion321, frame1E4<decimal110 or>decimal240 ->1, inclusive110..240 ->2. Delay slots preserve lower and upper endpoints. |
| [o2 0x707CB0](../recomp/config/output_ovl/o2/o2_00707CB0_0x707cb0.cpp) | `advance_actor_703300_two_serial_track_offset_pulses_candidate` | High mechanics; probable role | Pretested two records atCD8+14*i. SelectorCE8=0 returns from the whole function, so second record is skipped when first idle. State1 decrements unsigned timerCEA and moves to2 at0; state2 seeds offsetsCD8/CDA and negative stepsCE0/CE2 from owned73DC90 signed halves(decimal-4500,2300,10), scales steps by factor and seeds byte timer10/factor, then3. State3 adds steps and decrements timer, clearing selector and both offsets at0. Each processed nonzero selector calls58C750(actor,unsignedCE9,record CD8). Unknown selector still calls that adapter. Initial zero countdown wraps as byte; no defect or runtime cost claim. |

Owned track flag bank73DA28 begins decimal
`0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0`.
Owned73DA90 has four sixteen-row banks addressed by the two observed selectors;
all256 bytes were checked. Their distinct secondary0/1/3 and D65 bytes are
retained rather than assigned original action names. The eight signed-half
timers73DCA0 are decimal120,180,240,240,300,480,0,0. Zero entries explain the
explicit D6B branch without establishing an error.

Owned six-byte descriptors73DCB0..73DD5D (29 records) have motion IDs decimal
110,101,100,210,211,202,112,120,121,122,204,402,400,401,404,403,405,310,311,
102,312,205,409,321,330,320,203,407,408. Only descriptor24 has first half1,
descriptor25 first half2; remaining first/second halves are0. This body reads
only the final halfword. Descriptor/track bounds remain caller/asset contracts.

706F90 and706C40 already have mappings as identical-body aliases in the live
notes, so this notebook does not add duplicate rows. Original animation frame
windows remain separate from game-update and presentation observations.

Related [bootstrap](SYMBOLS_ACTOR_703300_BOOTSTRAP.md) and
[route states](SYMBOLS_ACTOR_703300_ROUTE_STATES.md).
