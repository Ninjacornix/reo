# Actor authority category control choices

Static File #1 US research, 2026-11-04. Seven complete original bodies reviewed. Addresses/offsets/state IDs hexadecimal; distances and probe quantities explicitly decimal. No execution, attachment, build, replay or engine changes. Categorynumbersareactorbyte4selectors;originalenemy/AItypenameidentitiesarenotclaimed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6A9550](../recomp/config/output_ovl/o2/o2_006A9550_0x6a9550.cpp) | `choose_actor_category_zero_control_from_relation_surface_probe_and_distance_candidate` | High mechanics; behavioral role probable | Nullrelated24returnsafteronlyclearing12byteslocalscratch. Else save8/9,clearA/B;score<FA0 ->6AA3C0(self,1,0). RelatedBA0mask20000000andBD4<=decimal150probes6175E0withlocal(0,110,120),headingtowardtarget;result2sets9A=heading(probeoutput50,zeroXYZ30),enters1/1D. Else6AC200+6AC2E0handledreturns. Probe(0,110,150)atyaw92result1 ->1/12;elseactualXZdistance>150 setsprimary1and6AA300inclinesubstate,near->1/6. Lastdirectstatepaths6AA530+6AC640(0). |
| [o2 0x6A9780](../recomp/config/output_ovl/o2/o2_006A9780_0x6a9780.cpp) | `choose_actor_category_one_control_from_d60_mode_and_target_regions_candidate` | High mechanics; behavioral role probable | Alwayssave8/9,clearA/B. Unsignedadmissionof signedhalfD60<9 dispatchesowned740B10 nineentries;negative/outsidefallscommon6AA530+6AC640(0)withoutselectingnewstate. Modes0/5attemptactionthen1/6;1region/targetdistancebranch;2attemptthen1/E;3/4savedD48pointdistance<=50 ->7/0or7/1,elseattemptthen1/E;6attemptthen1/11;7commononly;8->1/6. Actionattemptis6AC200then6AC2E0;handledskipscommon. Fullmode1contractbelow. |
| [o2 0x6A9AB0](../recomp/config/output_ovl/o2/o2_006A9AB0_0x6a9ab0.cpp) | `choose_actor_category_two_control_from_optional_waypoint_or_target_candidate` | High mechanics; behavioral role probable | Saves8/9,clearsA/B,attempts6AC200+6AC2E0andreturnsifhandled. SignedD5Bnonzero resolves7191F8[signedD58]+decimal10*unsignedBAF,signedXhalf0/Zhalf4;XZdistance<=50 ->1/16,else1/15. D5B0dereferencesrelated24beforelaternulltest;score>=FA0 ->1/4ifXZdistance>150else1/6;other1/A. Directstates6AA530+6AC640(0). No waypoint/targetadmission. |
| [o2 0x6A8F40](../recomp/config/output_ovl/o2/o2_006A8F40_0x6a8f40.cpp) | `set_actor_primary_one_substate_seventeen_without_phase_reset_candidate` | High mechanics; behavioral role probable | Writesbyte8=1,byte9=17only. LeavesphaseA/B,countersC/E,motionandpreviousstateunchanged. Smallbodyisstillthecategory3dispatchcontract. |
| [o2 0x6A9C80](../recomp/config/output_ovl/o2/o2_006A9C80_0x6a9c80.cpp) | `choose_actor_category_four_control_from_target_admission_and_distance_candidate` | High mechanics; behavioral role probable | Nullrelated24returnsunchanged. Else save8/9,clearA/B.6AC200and634C80(self,related,window10000,D55,limit150)success ->6AA3C0(self,2,C),return. Fallbackscore>=FA0 ->1/4ifactualXZdistance>150else1/6;others1/0. Directstatepaths6AA530+6AC640(0). Nullcheckbeforetargetcoordinatesiscompletehere. |
| [o2 0x6A9DC0](../recomp/config/output_ovl/o2/o2_006A9DC0_0x6a9dc0.cpp) | `choose_actor_category_five_control_from_target_score_and_distance_candidate` | High mechanics; behavioral role probable | Saves8/9,clearsA/B,attempts6AC200then6AC2E0,returnifhandled. Fallbackdereferencesrelated24beforelaternulltest;score>=FA0 ->1/4ifXZdistance>150else1/6;other1/0. Directstates6AA530+6AC640(0). Targetnonnullisacallercontract. |
| [o2 0x6A9EE0](../recomp/config/output_ovl/o2/o2_006A9EE0_0x6a9ee0.cpp) | `choose_actor_category_six_control_from_indexed_runtime_bit_candidate` | High mechanics; behavioral role probable | Saves8/9,clearsA/B. Tests4B9C00[unsignedBAF>>5] mask1<<(BAF&1F). Clear ->primary1/sub18;set->primary2/sub7. Then6AA530+6AC640(0). UnsignedbyteBAFkeepswordindex0..7;bitbankmutablebeyondownedfileandnotinterpretedasscenarioassetbitswithoutwriters. |

Theowner6A9490dispatches719880categories0/8/A->6A9550,1->6A9780,2->6A9AB0,3->6A8F40,4->6A9C80,5->6A9DC0,6->6A9EE0,7->previouslyreviewed6A9F80,9->previouslyreviewed6AA130,B->0. Theseareclosedtargetbodies,notnewaliasesforeachrepeatedtableentry.

6A9780 mode1 fullflow:

1. Ifrelated24isnullandsignedscoreBF8+20*C25+2*C26<FA0,choose1/6,theninitialize/publish.
2. Otherwiseattempt6AC200+6AC2E0;handledreturns.
3. ReadrelatedXZandactualXZdistance. Ifoldsub9==D,choose1/6.
4. Otherwise6AA250(self,related)false ->1/6. Regiontrueanddistance<=decimal50 ->1/6;regiontrueanddistance>50 ->1/D.

A nullrelatedwithscore>=FA0canfallthroughtothecoordinateswithoutanotherlocalguard.6A9AB0and6A9DC0similarlyreadafallbacktargetbeforetheirlatertest;thesearecalleradmissiongaps,notconfirmedcrashes.6A9C80rejectsnullupfront. A successfulactionhelpermayhaveselectedprimary2;itsreturnpathdoesnotrunthesubsequentdefaultinitializeragain.

6A9550firstsurfaceprobeuses6175E0(actor,XYZ(0,110,120),headingtoRelated,&local60,&local50). Onresult2,itcallssignedturnheading376E70(local50,zeroedlocal30),not376E70(local50,relatedXYZ). Thezeroed30vectorissource-observed;itscoordinateconvention/intendedworldmeaningisunknown. SecondprobeusesXYZ(0,110,150),currentyaw,andresult1enters1/12. No surface subtypeoriginalenumisassignedtothosereturnnumbers.

Owned740B10..740B33 ninejumpwordsforD60=0..8:6A97DC,6A9810,6A9900,6A9934,6A99B4,6A97DC,6A9A38,6A9A7C,6A9A6C.36-byteSHA256 `f4b1e44103acdada947d2fd648409c1cc0e0590b5e661aba850897b560c41818`;ownedo2base570000SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Fulljumpadmissionisseparatefromunboundedwaypointroot7191F8[signedD58]andBAFrecordindexinthecategory2path; no fullwaypointtablecoverageisclaimedhere.

Commonrelation-scoreaddressBF8+20*C25+2*C26usesunsignedselectorsandreadsasignedhalf. Alreadyreviewed [admission and action choice](SYMBOLS_ACTOR_ACTION_ADMISSION_TURN.md), [state entry](SYMBOLS_ACTOR_ACTION_STATE_INITIALIZATION.md), [authority/timer helpers](SYMBOLS_ACTOR_RESPONSE_TIMERS_AUTHORITY.md) and[target regions](SYMBOLS_ACTOR_TARGET_REGIONS_CONTACT_ROUTING.md) supplythelocalcalleecontracts. Nothingherechangesoriginalgame speed,provesupdatefrequencyoridentifiesameasuredbottleneck.

Full-body owned-word audit: 7 rows, 619 verified instruction words, zero conflicts, 28 omitted zero/NOP words, zero omitted nonzero words.
