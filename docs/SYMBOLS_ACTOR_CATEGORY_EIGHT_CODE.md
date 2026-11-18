# Actor category eight code-entry controller

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed.
Addresses/offsets hex unless marked decimal. Two connected identical-body
entriesCD20/CFA0 were independently reread but alreadymapped in
[shared bodies](SYMBOLS_SHARED_BODIES.md), so they are notduplicate rows here.
No execution, build, attachment or engine changes; original puzzle name unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6FC9F0](../recomp/config/output_ovl/o2/o2_006FC9F0_0x6fc9f0.cpp) | `tick_actor_category_eight_four_digit_code_entry_candidate` | High mechanics; probable role | SelectedplayerBA0bit20000 or5BA210nonzero forcesphase7;when3DDDB5==9 additionally5BF140. Signedphase4 dispatch742FD0. Phase0->1,playeraction5,task6C=9/5BF0F0(9,FFFF),5A5320(1),clearsdigits14/16/18/1A andselection12,CF20refresh,5A5060(word70,1). Phase1uses5A5380 with3/7when4B9C00bit80else2/7;result3closesmessage5A5050then5A5180 template,otherresultsrefresh5A5060. Phase2word70=DF,5700E0(DF,3C),CFA0cleanup. Phase3word70=74,CD80(actor,9,7,74). Phase4 sets4BAE89=3,buildscodeindexfrom4B9A84bits80/100/200,but6FCC40 delay-slotassignmenta0=3 executesonbothlastbranchpaths;thuscomparesagainst73C93C bytes4,2,8,4 viaCD20. Successsignalsword64and97,5BF140,phase5,C120,audio4F/B3,message75. Failurephase6,messageE1. Phases5/6setstatus3andCFA0;phase7CFA0. No claimthat code selectionbehavior isdefectiveornewlyintroduced. |
| [o2 0x6FCD80](../recomp/config/output_ovl/o2/o2_006FCD80_0x6fcd80.cpp) | `edit_four_task_digits_and_cursor_with_repeat_and_confirm_candidate` | High mechanics; probable role | a0task,a1signedlow16digitmax,a2cancelphase,a3messageID.324228lowFcausessoundB;bits1/2increment/decrementselectedhalf14+2*selection12withwrap0..max. Otherwise324210bits4/8movesselectionclamped0..3. Otherwise4BAE90bit20incrementsphase4,soundC,returnsbeforerefresh;bit10setscancelphase. OrdinarytailCF20refresh,5A5050(message,1),5A5180(globalpointer743154,1,1,50,198). Byte/halfadmissionandtemplateownershipunknown. |
| [o2 0x6FCF20](../recomp/config/output_ovl/o2/o2_006FCF20_0x6fcf20.cpp) | `write_four_digit_template_glyphs_and_selection_markers_candidate` | High mechanics | Readsglobaltemplatepointer743154. Fixedfouriterationsi0..3,selection12choosesmarkerASCII1else7 attemplate+8+6*i. Baseguestglyphwordfromowned73CAF8/9=824F;addsunsignedlowbyteofhalf14+2*i,storesbig-endianpairattemplate+A/B+6*i. Mutates sharedtemplateinplace,doesnotdraw,advancephaseorvalidatepointer. |

Owned742FD0 phases0..7 target6FCA98,6FCB20,6FCBBC,6FCBE0,6FCC04,
6FCCE8,6FCD04,6FCD04. Ownedfour-bytecodes73C930..73C93F are
(4,1,6,1),(4,0,3,2),(4,9,2,7),(4,2,8,4). The finalbranch
at6FCC38targets6FCC44whileits6FCC40delayslotwrites3;bothoutcomes
thereforeselectlastcode. Thisexplicitcontrolflowcheckavoidstrusting
anapparentconditionalfromsourceindentation. Staticbehaviorisnotan
observedincidentorafixrecommendation.

[Scenario event tasks](SYMBOLS_SCENARIO_EVENT_TASKS.md) describesthe
relateddigitcomparison/resourcecleanupanchors. Originalresourceadmission,
playerbuildoverridesandthecurrenttemplatecontentsneedseparateevidence.
