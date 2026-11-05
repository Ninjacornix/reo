# Actor61C3E0 root, surface transitions, and shared state controls

Static File #1 US,2026-11-04. Nineteen complete o2 catalog roles. High-confidence mechanics; original actor/motion/surface-mode taxonomy unknown. No execution/build/attachment/live memory/input/timing. Addresses/IDs/field offsets hexadecimal; explicit dimensions/distances/durations decimal. [Motion sound schedule](SYMBOLS_ACTOR_615C30_AND_61C130_SOUND_CROSSINGS.md), [surface queries](SYMBOLS_ACTOR_STATES.md). Numeric BA3 modes0/1/2 are deliberately retained; apparent surface locomotion does not establish original authored names.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x61C3E0](../recomp/config/output_ovl/o2/o2_0061C3E0_0x61c3e0.cpp) | `dispatch_actor_61c3e0_root_with_surface_modes_and_collision_admission_candidate` | High mechanics; candidate role | Snapshots position/angles; D2C=170, conditional prior-primary0 D28 refresh; clears BA5/C82/32/C36,C94 bit100,54A10. Optional target24 caches distance/yaw;640210, optional13F damage6220C0 and timer reset on result1, health C94 gates; six-target70F9F0 primary dispatch. C82 skips root motion/zerosC0; else622470. Scenario2 slope623960,BA3 flags,6347D0,5A7D00 channels, conditional622770/622B20 surface collision, height limits,622630 pose commit, eventC36 and1B0310. Complete admission below. |
| [o2 0x61C7D0](../recomp/config/output_ovl/o2/o2_0061C7D0_0x61c7d0.cpp) | `initialize_actor_61c3e0_channels_surface_basis_and_saved_activation_candidate` | High mechanics; candidate role | Builds actor50 angles,active/553=1,F0=1,520=-1,channel chain712140->712130=(0,50,10,50);1A8=7120C8 pointer,1D8=712120 pointer. C94|2C5;190=20FFFF,194=0,551=3/552=10. Scene-specific upper heights,optional four-ray6235D0 basis;clearsBE8..BEB,C..13,F7; BDA=B6/BDC=16C,queryD2C. C2B selects hidden(5,C2B-1);saved slot flags select primary4/A5;otherwise(1,0) healthrestore/timerseed. Final motion6242B0. |
| [o2 0x6219A0](../recomp/config/output_ovl/o2/o2_006219A0_0x6219a0.cpp) | `choose_actor_61c3e0_descriptor_action_with_near_bearing_interposition_candidate` | High mechanics; candidate role | First623BD0 handled result exits. Saves old8/9; descriptorhalfBF8+20*C25+2*C26 <FA calls621220;otherwise621610,signed negative exits. Primary1 except secondary2/D with5204/5 setsA=A; primary2 secondary1/2 with520other4/5 setsA=C. Then primary1 distanceBD4<130/bearing outside[-4000,4000] saves9toB and sets9=4;621E60/C367. Selection internals remain helper contracts, not inferred original actions. |
| [o2 0x621B30](../recomp/config/output_ovl/o2/o2_00621B30_0x621b30.cpp) | `route_actor_61c3e0_health_or_motion_completion_candidate` | High mechanics; candidate role | If health544<=0 or C2E>=1000,clamp negative544 to0 and621C40(4,4). Else520==21 ->(1,D),otherwise6219A0. C2E signed comparison; does not apply new damage. |
| [o2 0x621BB0](../recomp/config/output_ovl/o2/o2_00621BB0_0x621bb0.cpp) | `route_actor_61c3e0_secondary_zero_or_four_by_health_candidate` | High mechanics; candidate role | Only secondary0 or4: nonpositive health maps0->(4,2),4->(4,6);positive maps0->(4,3),4->(4,7). Others return. No healthrestore. |
| [o2 0x621C40](../recomp/config/output_ovl/o2/o2_00621C40_0x621c40.cpp) | `transition_actor_61c3e0_state_save_previous_and_reseed_timer_candidate` | High mechanics; candidate role | a0 actor/a1 primary/a2 secondary; saves8/9 toBE8/9,writesnew8/9,A/B0,621E60 timer/variant seed,thenC367. Does not itself choose motion. |
| [o2 0x621C90](../recomp/config/output_ovl/o2/o2_00621C90_0x621c90.cpp) | `seed_actor_61c3e0_phase_variant_by_action_and_bearing_candidate` | High mechanics; candidate role | Writes B only for enumeratedprimary/secondary cases. Primary1 secondary3 RNG&1;7/9/C B=(BD8<0),A B=(BD8>0). Primary2 secondary0 RNG&1. Primary3 secondary0 B=2 for5204/5/1A/1B/1D/1E,elseRNG&1. Primary4 secondary3/7 RNG&7. OtherstatesretainB. |
| [o2 0x621E60](../recomp/config/output_ovl/o2/o2_00621E60_0x621e60.cpp) | `seed_actor_61c3e0_state_timer_then_variant_candidate` | High mechanics; candidate role | Always E0;primary1 secondary<14 bounded20target73FC90table selectsdurationsbelow;primary4 secondary3/7 positivehealth634880(actor,C2A),nonpositive E=-1. Always calls621C90,includingdefault. Divisor unsigned74F200,localzero guard absent,not a measured fault. |
| [o2 0x6220C0](../recomp/config/output_ovl/o2/o2_006220C0_0x6220c0.cpp) | `apply_actor_61c3e0_damage_and_select_reaction_or_descriptor_refresh_candidate` | High mechanics; candidate role | 637490 storedtarget ->11C;B1E1 clears self andtargetB1E6;uncheckedcallback at72B820[141] with(actor,0),sound6,positive138 target666D40,6407D0 damage1000. Classes1/2 storedruntime74F295 slot; savesoldstate. State-dependentreaction/cancel/descriptor refresh below. Returns0,1,2 with distinct caller semantics; no new targetsearch or locally verifiedNULL check. |
| [o2 0x622470](../recomp/config/output_ovl/o2/o2_00622470_0x622470.cpp) | `integrate_actor_61c3e0_root_delta_in_angle_or_surface_basis_candidate` | High mechanics; candidate role | BA3=0 usesactorangles. Nonzero plusstate(1,F) usesactor50basis;elseBA3=1/2 combinesangleswithD18 quaternionmatrix. Unless54Abit8,scaleXZ B4/BC andY1. Clearsbit8,transforms4E4XYZtoC0,scalesF0,addsC0toXYZ. OtherBA3values not locally admitted/rejected; no generic enum claim. |
| [o2 0x622630](../recomp/config/output_ovl/o2/o2_00622630_0x622630.cpp) | `commit_actor_61c3e0_surface_pose_and_consume_extra_displacements_candidate` | High mechanics; candidate role | Rebuildactor50angles,nonzeroBA3 multipliesD18 quaternionmatrix;transformsD8XYZ,addsE4XYZ+transformed toposition,zerosD8..EC. Scene(2,1B)/BA3=2 clampsZ<=11640. Copiespositiontoactor50+30. No normalanimationrootdelta applicationhere. |
| [o2 0x622770](../recomp/config/output_ovl/o2/o2_00622770_0x622770.cpp) | `probe_actor_61c3e0_forward_surface_transition_and_reposition_candidate` | High mechanics; candidate role | Requires positive lengthC0;segmentalongnormalizedC0 at60 for520A/B else100,5795E0 hitmustflags1&100000. Savespriorstate/motion/secondary,sets9=F,A=2ifBA30else3;BA32 dotnormalorientation choosesyaw/order andpossiblehalfturn. Position=hitpoint+normal*(51 for520A/B else101);54Abit1,622630,C367,storesnormalD00/hitD0C. Complete orientation differences below. |
| [o2 0x622B20](../recomp/config/output_ovl/o2/o2_00622B20_0x622b20.cpp) | `probe_actor_61c3e0_surface_basis_boundaries_and_three_segment_continuation_candidate` | High mechanics; candidate role | PositiveC0 length: projectedpoint=P+D00+normalizedC0*(60or100)+C0. BelowD2C/aboveD28 producessecondaryF A2/3 reposition atheight +/-51/101. Otherwise three5795E0 segment attempts withflags1&100000;cases2/3 interpose9F A0/1,case1 basiscontinuation. Nohitrestores44XYZ,6367C0,623850,transition(1,0). Selectednormal/hitbasis andyawdelta committed; detailbelow. |
| [o2 0x6235D0](../recomp/config/output_ovl/o2/o2_006235D0_0x6235d0.cpp) | `probe_four_cardinal_surfaces_and_return_selected_yaw_difference_candidate` | High mechanics; candidate role | a0 actor,a1 optionalnormalout,a2 optionalhitpointout. Four ownedworld-axissegments(P+shortOffset)->(P+longOffset),5795E0 flags1&100000;choose strictlynearest distance<10000. Ifselectedwriteouts andreturnsignedhalf(bearing(P,hit)-yaw). No qualifyinghitreturns0; valid alignedhitcanalso0. Not boolean hit/miss. |
| [o2 0x623850](../recomp/config/output_ovl/o2/o2_00623850_0x623850.cpp) | `probe_actor_61c3e0_along_surface_normal_and_refresh_position_snapshot_candidate` | High mechanics; candidate role | Segmentstart=P+(50*nX,nY,50*nZ),end=P-(100*nX,nY,100*nZ),5795E0 flags1&100000. Admittedhit setsP=hitpoint+D00normal,then44XYZsnapshot=P. No50/100 multiplier onY,notuniformnormaloffset. |
| [o2 0x623960](../recomp/config/output_ovl/o2/o2_00623960_0x623960.cpp) | `adjust_actor_61c3e0_pitch_from_forward_surface_height_candidate` | High mechanics; candidate role | BA5==1 returns;nonzeroBA3 sets90=0. Else rotate(0,50,45)byyaw,querysurfaceatP+offset;typeFFreturns. abs(height-P.Y)in(5,99)computeshorizontal/full distances from(P.X,170,P.Z),192100 angle thenroundtosigned16 PS2turns;uphillnegative/downhillpositivepitch. Otherdifferences90=0;zero fulldistance replaces1e-4. |
| [o2 0x623BD0](../recomp/config/output_ovl/o2/o2_00623BD0_0x623bd0.cpp) | `interpose_actor_61c3e0_scene_two_room23_mask_action_candidate` | High mechanics; candidate role | Onlyscene2/room23,BA30,secondary<12andnotF. Mask4B9C10 bits20/40/80 admits621C40(1,12);setsB85/86/87 priority20then40then80,returns1. Else0. No actorprimary1 admission check in this body. |
| [o2 0x6242B0](../recomp/config/output_ovl/o2/o2_006242B0_0x6242b0.cpp) | `initialize_actor_61c3e0_motion_from_primary_four_recovery_state_candidate` | High mechanics; candidate role | Primary4/secondary3 choosesmotion2C;otherprimary4 chooses30;otherprimarymotion0. All5A85F0 f12/f13=0,then58C7B0reset. Does not change state8/9 itself. |
| [o2 0x6245E0](../recomp/config/output_ovl/o2/o2_006245E0_0x6245e0.cpp) | `clear_actor_61c3e0_compact_tracking_history_fields` | High mechanics; candidate role | ClearsbyteD33 andhalvesD36/D38/D3A/D3C/D3E/D40. Otherworkretained;no externalcalls. |

The original root independently clears BA5 every invocation, unlike actor60F710. It refreshes D28 from global49F78C only when previous primaryBE8=0 and current primary8 nonzero; BA3=2 also sets initialY=D28 on that path. C94 bit100 is reset before dispatch; nonpositivehealthsetsbits201,positivehealthclears201. BA3 is snapshotted toC29. No new source or timer fix is implied.

The root postdispatch collision admission is primary1, A!=0, secondary0..9/B/C/11. When oldsecondaryBE9=F, motion520=A requires rootdelta4E4<0;520=B requires4E4>0;othermotionscontinue. BA3=0/2calls622770,BA3=1calls622B20. These functions can commit pose622630 internally and the root may call622630 again later; each commit consumes/zeros D8..EC so they cannot be naively deduplicated. SecondaryF skips the final rootcommit. BA3=2 capsY atD28; BA3=1 lowerlimitD2C+50 is checked first,otherwise upperlimitD28-50. Interval ordering depends on admitted scene heights; no bad interval or player incident was measured.

Initializer height assignments (scene3243DA,room3243DC; all IDs hex): scene0 ->500;scene2/room1B ->1400;scene2/room1F ->600;scene23/room16 ->-1403. Each writes D28 andglobal49F78C. Other scenes retain existing values. BA3 nonzero6235D0 returns a yawdelta: zero suppresses basis setup even though an aligned hit may have written output vectors. Nonzero return builds D18 via5A82A0(D00,BA3);BA3=1 also setsposition=D0C+D00. No original ?success bool? should replace this contract. BA3=0 initializesD00=(0,1,0); failed/nonzero-mode admission only clearsBA3 and does not execute the defaultnormal branch afterward.

Saved-slot activation uses runtime74F295+60*B98 bits3: nonzero clearsruntime74F270,BA3=0,sets(4,B9E,A5,B0),withsecondaryforced7unless3/7. C2B nonzero instead starts hidden(5,C2B-1,A/B0). Normalactivation(1,0) restores544 from546 only if544<=0,then621E60. Otheractivationpaths do not share that reseed call.

Timer621E60 uses r=low16 RNG and unsignedbyte g=74F200. All formulas below use decimal counts; table indices hex:

| Primary1 secondary | E seed |
| --- | --- |
|0|634AB0(actor)|
|1,5|(r%480+120)/g|
|2|(r&1)+2|
|3|(r%15+15)/g|
|4,A|(r%30+30)/g|
|6,B,D|(r%60+60)/g|
|7,9,C,13|(r%180+120)/g|
|8,E,F,10,11,12|0|

It always runs phasevariant621C90 afterward; this can overwrite B supplied by a caller. 6219A0's temporary save ofoldsecondary intoB before timer reseeding remains subject to that variant policy. This note does not claim exact action enum meaning or a deterministically retained B across every transition.

Damage handler6220C0 publishes the stored target from637490; no localNULLguard before its B1E sideeffect. Callback72B820 indexed by141 remains an external callback contract, with no locally checked index bound. After6407D0(actor,target,1000) returns signedclass k, runtime slot74F295 is written1or2 only for those exactclasses. Saved old8/9 happens even on descriptor-refresh paths. The following table preserves returns and mutation:

| Existing state | Admission/result |
| --- | --- |
|primary2,secondary3,A<2|Optional B24 targetB1E=6;667060(actor),return0;doesnotseedtimer|
|primary2,secondary3,A>=2|5A7C40(70FAE8,CD8),return2|
|primary2,othersecondary|Sets115bit1; BA3nonzero AND k!=0 ->(3,BA3+2);else chooseprimary3 secondary by140 (0->0,1->1,2->BA3+2,otherretainssecondary). SelectedpathA/B0,return1|
|primary3|BA3nonzero,secondary0/1,k!=0 ->(3,BA3+2);else secondary4 ->(3,5);others descriptorrefresh/return2|
|primary4|k==1 and secondary1/5 ->(3,BA3+2);others descriptorrefresh/return2|
|otherprimary,secondaryF|Descriptorrefresh/return2|
|otherprimary,othersecondary|BA3nonzero AND k!=0 ->(3,BA3+2);else secondaryE ->(3,5);elseprimary3 with140 selector asabove. SelectedpathA/B0,return1|

Root onreturn1reseeds timer/variant,then emits event2;return2also emits2 but doesnotreseed;0emitsneither. Common leadingdamage/sound callbacks have alreadyoccurred even whenreturn0. Healthclassk=0 is not locally ?no damage?:6407D0 performs its own update before returning authority/reaction classification. No confirmed player-damage or slowdown event is inferred.

622770 uses positiveC0 length as admission and probes P to P+normalize(C0)*L (L=60for520A/B else100). Bothcollisionflags1/100000 are required. It setssecondaryF andphase2forBA3zero,3otherwise. BA3=2 compares dot(D00,hitnormal) exactly0:zero uses bearing(normal,zero),nonzero uses bearing(zero,normal); motionA/B adds/subtracts4000. OtherBA3 uses first ordering. Exactzero branch later subtracts8000 fromyaw after622630commit. Positionuseshitpoint+normal*51 for520A/B or normal*101 otherwise. This is not a generic reflection or normalized-plane solver.

622B20 uses the sameL/R=51or101 but has upper/lowerheightboundary paths and three ordered segment attempts. Define V=C0,N=D00,P=currentXYZ,Q=P+N+normalize(V)*L+V,U=Q-20*N,R0=old44XYZ+N. Queries are (R0,Q), then(Q,U), then(U,R0-20*N), each requiring flags1/100000. First validhitinterposessecondaryF/phase0,type2;secondcontinuesexistingstate,type1;thirdinterposesF/phase1,type3. Ifnohit,restoresold44XYZ,6367C0,623850,transition(1,0). Type1setsD0C=hitpoint-normalizedV*L andnewnormal,buildsD18thenreturns. Types2/3updateyawandposition,622630commit;then5A8220/192250computeorientationchangeand192110-derivedyawdelta,writehit/normal/C367. Exact matrixcoefficient1 is replacedowned0.999989986 beforeanglehelper;zero-lengthcleanup differsfrom623960. Full MADD/MSUBinstructionorder retained; this summary is a candidate geometric description,not a substitute algebraic implementation.

Owned data below establishes initializer-pointer and four-ray tables. Pointerslots/records may be mutable during actual execution; initial file bytes alone do not establish current content. Physical shadowdescriptor70FAE8 is8B,usedby5A7C40; no original fieldnames guessed.

| Owned span | Values | SHA256 |
| --- | --- | --- |
|70F9F0..70FA07|61C7D0, 61CB50, 61F080, 61F8C0, 620170, 620A80|`6e2312a0fb38daa83f53addcf2ae98edc70f84cc1d41d7173ba8333f3d2740ec`|
|73FC90..73FCDF|621EBC, 621ECC, 621F0C, 621F28, 621F68, 621ECC, 621FA8, 621FE8, 6220A4, 621FE8, 621F68, 621FA8, 621FE8, 621FA8, 6220A4, 6220A4, 6220A4, 6220A4, 6220A4, 622028|`eeac1b9d10ea97fd88a8568779d6bf3bfa9f56a4e73b2d51960b118bc5fd1a56`|
|70FAE8..70FAEF|4, FF, 4, FF, 4, 5, 4, A|`55683253af579101ba6e6f99949cad46cda17806cf753bdff1a5b72759be445f`|
|70FB40..70FB6F|1000.0, 0.0, 0.0, -1000.0, 0.0, 0.0, 0.0, 0.0, 1000.0, 0.0, 0.0, -1000.0|`317373b320ba78cec92bf10611850891e80ebd0b4ddeff3600b6d7155ac242b8`|
|70FB70..70FB9F|-100.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 0.0, 100.0|`e904fecfeb8110e1bce23998eca07b129f9cebe48f8c450ed89f129fed153390`|
|70FBA0..70FBAB|0.0, 50.0, 45.0|`789e09e6ed1637862548a46ed81498d8b7241464f7a513c3a70f612ad420b13b`|
|7120C8..7120CB|712090|`f1941c1d58129ddf47c85dc66f43f01698a9646586f2f421237c0aed0f41a00e`|
|712120..712123|7120D0|`d837153d22259cb416c79793e13733c17b410bc88b185586872b1ddcf497f520`|
|712140..712143|712130|`035500ca4e53a066e175bfebf27a6966753ca47e7420b79ecc88f537972f5ba4`|
|712130..71213F|0.0, 50.0, 10.0, 50.0|`af027e3d29321426696f10c3d3e96fb249ebca848f18db1bc845daf92763bbac`|
|73FD48..73FD4B|0.9999899864196777|`123d8636a1f1848411e11f66b7e116d6761284b6ac6af1931a65d408da893c5d`|
|73FD40..73FD43|9.999999747378752e-05|`0f2f3591427956b004ca17393783192e0f81858c06bb5496aa2cea004f1ee863`|
|73FD60..73FD63|6.2831854820251465|`12d85026b5109a3119231704608d5991a63d8d397d2867a9fc522305810ddb76`|

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Full19bodyreview includes every original nonzero instruction. Callback index141 domain, helper621220/621610 selection policies, authored animation IDs, native override admission, actual actor update rate, scene trigger, and performance attribution remain unknown. No runtime-cause or optimized-path proof is claimed.

Owned-word audit: nineteen complete catalog bodies,2,426 original instruction words verified,148 omitted zero/NOP words,zero conflicts and zero omitted nonzero words. Fullsix-targetrootdispatch/twenty-targettimerphase/four-ray tables and channel pointer chain hashed. Live note/actual annotation/link checks clean; no shared index mutation.
