# Actor61C3E0 primary-two linked target actions and goal setup

Static File #1 US,2026-11-04. Six complete catalog roles including mergeddispatcher/firststateandtwoconnectedsetuphelpers. High-confidence mechanics; original authored actions and actor type remain unknown. No execution/build/attachment/live memory/input/timing. Numeric addresses/IDs/field offsetshexadecimal;explicitlengths/countsdecimal. [Root/transitions](SYMBOLS_ACTOR_61C3E0_ROOT_SURFACES_AND_SHARED_CONTROLS.md), [motionadapter](SYMBOLS_ACTOR_61C3E0_MOTION_SELECTION_AND_TRACKING.md), [primary-onegoalconsumers](SYMBOLS_ACTOR_61C3E0_PRIMARY_ONE.md). Literal5DA2C0modeIDsretained; naminganoriginalattack/grabwouldrequireadditionalasset/calleradmission.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x61F080](../recomp/config/output_ovl/o2/o2_0061F080_0x61f080.cpp) | `dispatch_actor_61c3e0_primary_two_and_tick_merged_motion18_19_action_candidate` | High mechanics; candidate role | A0active1/allcolorsFF;uncheckedfour-target70FA70tail. Interior61F0D0A0clear115bit1,motion18ifBnonzeroelse19,5DA2C0mode4/5(arg1),reset;A1rate7290F8+12*BA1signedpositivecompletionsets115bit1/6219A0;A=CclearsA0. Dispatcher/interiorcountonce. |
| [o2 0x61F1E0](../recomp/config/output_ovl/o2/o2_0061F1E0_0x61f1e0.cpp) | `tick_actor_61c3e0_primary_two_target_node_scaled_action_candidate` | High mechanics; candidate role | Requires target24. A0->1,623E70 point=targetmodelnode3translation/reset,clear115bit1/5DA2C0mode6(arg1). A1tickchannel2positive->(1,D),thenA2;A2calls624200,unsignedlow8positive sets115bit1->(1,D),A2. BothphasesapplyC40Zscale toownnode28localbasiswhen!=1. A=C/Dcalls6244B0. |
| [o2 0x61F3A0](../recomp/config/output_ovl/o2/o2_0061F3A0_0x61f3a0.cpp) | `tick_actor_61c3e0_primary_two_motion1c_target_height_scaled_action_candidate` | High mechanics; candidate role | Requires target24. A0motion1C/reset,C40=(selfY-targetnode20Y-19)/95,clear115bit1,5DA2C0mode7(arg1). A1channel2tickpositive->115bit1/(1,D)/A2;elseB1E1and5AA0C0nonzero->(2,3). Then ownnode28Zscale follows triangularframecurve around36 ifC40!=1. A=C/Dsharedtransition. |
| [o2 0x61F590](../recomp/config/output_ovl/o2/o2_0061F590_0x61f590.cpp) | `tick_actor_61c3e0_primary_two_target_link_motion1d_1e_action_candidate` | High mechanics; candidate role | Requires target24;seed(0,0,-38). A0motion1D/reset,E4,624C80yawrotatesoffset,setsownXZ=targetXZ+offset,D321. A1B1E4ortarget54F!=B0->A2/motion1E;else exacttickstatus2decrementsE,<=0targetB1E63/A2/motion1E. Exactframe18D320/spawncallback57E0B0->type24. Dynamicnode16/targetnode20heightscale;A2completionpositive health->(1,D)/A2,nonpositive->(3,4);exactframe10D321/scaleinterpolation. A=Cclears0. |
| [o2 0x623E70](../recomp/config/output_ovl/o2/o2_00623E70_0x623e70.cpp) | `prepare_actor_61c3e0_goal_distance_scale_and_pitch_blended_action_candidate` | High mechanics; candidate role | a0actor/a1goalXYZ. Builds originbyBA3 (0P+offset,1P+50*normal,2P-offset),measuresdistance+100,scaleC40=(distance+100)/450when<=600elseownedcap. Computesmode-relativepitch. Exactpitch-4000motion1B;0motion1A;(-4000,0)motion1AwithFDsecondarytrackblendandA2;remainingmotion1BforBA32else1A,scale1. Detailsbelow. |
| [o2 0x624C80](../recomp/config/output_ovl/o2/o2_00624C80_0x624c80.cpp) | `read_actor_61c3e0_world_yaw_from_surface_basis_or_actor_angles_candidate` | High mechanics; candidate role | BA3!=2returnssignedyaw92. BA32rotatesowned70FBF0vectorbyunsignedyaw,transformsbyD18quaternionmatrix,376E70(zero,transformed)returnsigned16. Doesnotstoreyaworadvanceanimation. |

Theprimary-twodispatcher setsactive/colorsbeforetargethandlerscheck24;NULLtargetdoesnotmean thewholeparentcallbackwaswithoutsideeffects. Mergedfirststateusesnosuchtargetpointergate. 61F1E0firstphasepositivecompletiondoesnotset115bit1,whereasitsalternateblendphasecompletiondoes. Both transition(1,D)thenoverwriteA2. Root/statehelper621C40alreadyreseedstimer/variantandC367;A2overwritecomesafterthatcall. 61F3A0also mayswitch toprimary2/secondary3throughB1E/5AA0C0while stillapplyingthenode28scaleafterward.

61F3A0scaleformula: C40=(selfY-69-targetnode20Y+50)/95=(selfY-targetnode20Y-19)/95. Withframef<=36,Zscale=1+(C40-1)*f/36;elseC40-(C40-1)*(f-36)/36. Nolocalclamporfinitenesscheck. Thischangesactoranimationnode28localbasis,notrenderresolutionorengineframepacing. Itdoesnotestablishasafeoptimization.

61F590phase1dynamicC40=(ownnode16Y-targetnode20Y)/(50*ownB8). A2Zscale=(C40-(C40-1)*currentframe/totalframes1E8)/ownBC. Theseoriginaldivisorsarenotlocallyguarded;caller/modelscaleandmotionlengthadmissionareunknown,notmeasuredfaults. Phase1testsexacttickstatus2forfourloops;positivecompletionisusedonlyinphase2. Exactframe18spawn/type24andframe10D32writearesingle-invocationequalitytests,nogenericframecrossinggate. Callbackpresence/costfrequencywerenotmeasured.

Goalsetup623E70usesownedvectoroffset70FBC0 and referencevector70FBB0. BA30origin=P+offset;BA31origin=P+50*D00;BA32origin=P-offset. DistanceisfullXYZdistancebetween goalandthatcomputedorigin,then+100. If<=600,C40=distance/450;otherwiseownedcap73FD38. Itcomputesdirectionangles376EF0;BA30pitchdifferenceusesactor90,BA31transformsgoal-originthroughnormal-derivedbasisbeforeanglequery,BA32negatespitch. Signedrelativepitch s policy:

| s | Setup |
| --- | --- |
|-4000|623D90 motion1B/start0,retainsdistanceC40|
|0|motion1A/start0,retainsdistanceC40|
|-3FFF..-1|motion1A/start0;weight=1-(-s)/16384;forallunsignedtrackcount524 setflag8,stage1FC2,time1F4=0,weight1F8,savecurrent4E4XYZto4FCXYZ. AddmotionFDtrack1through58CE40,blendweights58CE00 fromtrack0weightand1-weight;A2|
|other|motion1BifBA32else1A,start0;C40=1|

Theall-trackloopchecksitscountbeforefirstbody;count0performsnoiterations. No underflow/infinite-loopcandidateisinferred. Theexactboundarypitch-4000andzeropathsretaincomputedscale,whilethefallbackexplicitlyresets1. 624200waspreviouslymapped:[relatedactorblendtick](SYMBOLS_SHARED_BODIES.md) is a plaincrossreferencehere,andisnotcountedasnewrole. Itadvances/combinestracksandconsumesrootdelta;donotreplacewithone58C300call.

Owned data (base570000):

| Owned span | All values | SHA256 |
| --- | --- | --- |
|70FA70..70FA7F|61F0D0, 61F1E0, 61F3A0, 61F590|`708a6b5665b2c5f3fea76b95b496add798b5d201d4eed8b3a29f166be15fa8f9`|
|70FB28..70FB33|0.0, 0.0, -38.0|`4f977b0ec2d012606c0b265d455767f58da00b009625a40e8c7b9190038f754e`|
|70FBB0..70FBBB|0.0, 1.0, 0.0|`3695fc5961dab4c804313662c5662248a3536224fb1dd93f8fb23304c437ff0c`|
|70FBC0..70FBCB|0.0, 50.0, 0.0|`7172df77b303e46ca00fe5abb2eec644399efb7c6f0eb5ce722c539c4672d7c2`|
|70FBF0..70FBFB|0.0, 0.0, 1.0|`caccb9a8fbd2401135207066c4b53d6e88467839318ea2f1e8bfadf8fef6844e`|
|73FD38..73FD3B|1.3333333730697632|`6f4cd532e8c154c45c348ae70bd34e9a5dffdb04411785cb9aa4d5f2ff1ce765`|

Owned o2 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Runtimeactoridentity/targetownership/motionadmission/callfrequencyandperformancerootcauseunknown. Noengine or sharedindexmutation.

Owned-word audit: 6 complete catalog bodies,756 original instruction words verified,51 omitted zero/NOP words,zero conflicts and zero omitted nonzero words. Fullowneddispatch/seed/literalspanshashed;liveannotation/note/linkchecks clean;no sharedindexmutation.
