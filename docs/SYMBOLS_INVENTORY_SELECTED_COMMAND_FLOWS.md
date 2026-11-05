# Selected inventory commands and deferred actor-state flows

Static File #1 US, 2026-11-04. Seven complete original o2 command bodies. Hexadecimal addresses/fields/masks andphasecodes;counts/distance/secondsnotinferredfromlocaltimers. High mechanics confidence, roles candidate. Noexecution,builds,attachment,liveinputorperformanceclaims. Allsevennontrivialphysicaltargets70C620areclosedhere;return1stub5F30C0isaplainverifiedalias.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5F30D0](../recomp/config/output_ovl/o2/o2_005F30D0_0x5f30d0.cpp) | `start_selected_resource_action_two_f_when_template_and_actor_flags_admit_candidate` | High mechanics; role probable | a0actor,a1slotbytepointer.5F1C50(mode1)and5F1F10flagquerygate;BA0&1B8orstate9==2Fskips. AdmittedC7F=*slot,D92|40,action1/2F/phases0,667370,notify1,sound6ifcurrentC7Cdiffers. **Allnormalpathsreturn1**,includingqueuedactionandblockedpaths. |
| [o2 0x5F31C0](../recomp/config/output_ovl/o2/o2_005F31C0_0x5f31c0.cpp) | `handle_selected_resource_self_or_near_actor_use_with_slot_cleanup_candidate` | High mechanics; role probable | UIphaseG=3B85A5,auxselectionU=3B85A2. Templateflag4absentforcesG1. G0uses selfU0ornearactorU1withturninitializationandaction1/21;5F1FA0effectcodesdriveclearslot/compactandlocalstatistics. G1optional5B2770/64AED0prehookthenappliestoself. OtherGreturns0;detailsbelow. |
| [o2 0x5F34D0](../recomp/config/output_ovl/o2/o2_005F34D0_0x5f34d0.cpp) | `sequence_selected_resource_pre_action_then_actor_substate_three_e_candidate` | High mechanics; role probable | Guard5F1C50(mode3)blockedforcesGFF. G0admission586440maystart1/2F,54F17,G1orifalreadycurrentstart1/3E,54F1C,G2. G1waits54F17then1/3E;G2waits54F1CthenGFF. FFreturns1;pending0. Noresourcepairclassificationoractualrecipeexecutionhere. |
| [o2 0x5F3EA0](../recomp/config/output_ovl/o2/o2_005F3EA0_0x5f3ea0.cpp) | `handle_selected_resource_pair_immediate_recipe_or_deferred_action_and_cleanup_candidate` | High mechanics; role probable | G0requiresactorF78bit20andBA080clear. Classifyselected+secondaryslotpair5B3DD0,saveCAA/CAB,5F3690mayreorderthem. Certainrecipeclassesforceimmediatepath;othernonzeroactioncodesenqueue1/40/G1. Immediate5B28F0resultsremovefirst/secondslotwithcurrentequipmentdetachandcompact. G1waits54F17/1Cbeforecompletion. Fullcontractbelow. |
| [o2 0x5F4310](../recomp/config/output_ovl/o2/o2_005F4310_0x5f4310.cpp) | `show_selected_resource_description_with_fixed_scene_message_counter_candidate` | High mechanics; role probable | SlotbyteÃ¢â€ â€™3C5630+3C*ID,6E1A30(record)descriptionpointer. Stores743650,half743548=78;6EC980(pointer,78),return1. Actorargumentunused. Fixed80bytecopy/countersemanticsbelongcallee. |
| [o2 0x5F4370](../recomp/config/output_ovl/o2/o2_005F4370_0x5f4370.cpp) | `sequence_selected_resource_disassociation_request_reply_and_action_two_five_candidate` | High mechanics; role probable | Guard5F1C50(mode6),sixphase73EE50. Detachesmatchingcurrentinstance,G2launchesaction1/24/notificationrequests;G3waitsF7810andrequestorofflinepath;G4consumesB34/B35replyortimer;G5launches1/25. Numericrequestdeliveryunknown;network/droplabelnotproven. |
| [o2 0x5F4660](../recomp/config/output_ovl/o2/o2_005F4660_0x5f4660.cpp) | `guard_mode_seven_then_delegate_selected_resource_use_command_candidate` | Confirmed routing; role probable |5F1C50(actor,7)nonzeroreturn1;else5F31C0(actor,originalslotpointer),preservesreturn. Noindependentmutationorstatecode. |

Selected-slotpointerSbelongsactor;G=byte3B85A5,U=byte3B85A2.5F3020controllercallscommandsandflushesD92notificationafterwards;commandsmayalsoexplicitlynotifyearlier. Booleanmeaningmustcomefromthatcontroller'scaller,notfromnamealone. Resourcequery5F1F10returns0/1only,sobranchv==2in5F30D0isunreachablethroughpresentcallee;activeflag1mustbeadmittedforitsequip-likeaction.5F30D0neverrewrites54Flocally.

5F31C0:

-First5B43F0(*S,4)==0forcesG1. BA018withG!=0orU!=0returns1. UnknownGotherthan0/1returns0.
-G0/U0usesactoritselfastarget. G0/U1guardmode9;onadmissionC7F=*S,action1/21/phases0,667370,notify1,666960(actor,2,f12=100decimal)choosestarget. MissingtargetclearsC/C4Eandreturns1;nonnull377000givesyaw,C=5orAdepending3243CC,C4E=signed16yawdiff/C. OtherUreturns0.
-Then5F1FA0(*S,actor,target,1). Result2clears*S,5F2330(actor),andwhenauthority1incrementsunsignedhalf3B84E8. Result1sameauthoritystatincrementwithoutslotclear. Othercodesnomutationhere. TheseG0handledpathsreturn1.
-G1setsC82/C7F=*S.5B2770(ID,actor)nonzeroadds5F1B40gate;blockedreturns1.64AED0(actor,ID)nonzeroandauthority1calls5F4FD0. Regardlessordinaryprehookresult,5F1FA0(ID,actor,actor,1). Result2clears*S/compacts;allresultsreturn1. Noactualeffectsuccessclaimfollowsfromreturn1.

5F34D0:G0requires586440(actor,*S)!=0,elsedone1. DifferingcurrentIDsetsC7F,*G++(to1),D92|40,action1/2F/phases0,667370,notify1,then54F17. MatchingcurrentsetsG2,54F1C,action1/3E/phases0,notify. G1while54F17returns0;aftercompletionG++2,action1/3E,notify,withoutanew54Fassignment. G2while54F1Cwaits0;elseGFFbutthatinvocationstillreturns0,nextFFreturns1. GuardfailureGFFreturns1immediately. UnknownGreturns0. ThiscallbackdoesnotresetGfornextoperation.

5F3EA0:G0withoutF7820returns0. BA080orinvalid5B3DD0pairplaysresidentbank0event3andreturns1. SecondaryU<4usesactorC84+U;U>=4onlyB98<6permitsC88,othercategoriesreturn1. StoresselectedIDCAA/secondaryCAB;5F3690(actor,&CAA,&CAB)mayreorder. Originalrecipeclass7/8/16/17overridesdeferredresult0,evenifclassifierhadreturnedFF. RemainingFFplaysevent3/done1. OthernonzeroresultstartsC7F=CAA,54F1C,action1/40/phases0,667370,setsB=codebeforeexplicitnotify1,G1,F78clear20,bank0event0,return0.

Immediateclassifier0path:unlessrecipeclass16/17,ifcurrentC7CequalsCAAorCABdetach5B1A90(current),clearC7C/CA8. DA2=originalselected*S,DA3=actualsecondaryslotID;5B28F0(*S,secondaryID)usesactualslotorder,notreorderedCAA/CAB. Result0bank0event3. Result1sound5,6ECA70(actor),bank0event0. Result2sound5,if*S==currentdetach/clearcurrent,clear*S,5F2330,6ECA70,event0. Result3sound5,detach/clearcurrentifmatchingsecondary,clearsecondaryC84+UorC88,5F2330,6ECA70,event0. Otherresultsonlyreturn0. G1returns0while54F1C/17,otherwise1. Resident1B8800/8830aresoundevents,notUIcloseoperations;noautomaticUIteardownisinferred.

5F4370sixphases,guardfailurealways1;G>=6returns0:

| G | Original behavior |
| --- | --- |
|0|SetG2. IfC7Cnonzeroequals*S,D92|40,C7F=C7C,5B1A90(current),C7C/CA8=0. Return0,phase1isskippedbythisentrypath. |
|1|Wait54F17;elseG2. Return0. Externalentry/updatesmayreachthisphase;noassumedautomatic0->1. |
|2|G3,C7F=*S,action1/24/phases0,667370,notify1,67FF80(actor,2,ID);mode1B02D0==1also5B1610(ID,FF). Return0. |
|3|state9!=24returns1. F7810setÃ¢â€ â€™67FF80(actor,1,C7F),G4,timer12=4B0. Submode1B0310==0overridesG5.64C5A0(actor);return0. |
|4|state9!=24returns1. Submode!=1returns0. Inmode1,nonzeroB34withB35!=DA7clearsB34. B34==1calls5F5C50(actor,0,C7F),G5;==2setsG3;otherdecrementssignedtimer12when!=0,exact0setsG3. FinallyB34=0,return0. |
|5|state9!=24returns1;elseaction1/25/phases0,667370,notify1,return1. Gnotclearedhere. |

5F4310descriptioncallee6E1A30iscoveredin [inventoryresourcequeryadapters](SYMBOLS_INVENTORY_CURSOR_CONTROL.md). Sideeffecthelper67FF80publishesnumericrequests;actualownedprocessexternalcommunicationsarenotperformedbythisresearch. [Actorresourceadmission](SYMBOLS_ACTOR_RESOURCE_ACTION_ADMISSION.md)showscorrespondingnon-UIactioninitializers.

Ownedo2base570000SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:73EE50..73EE67sixjumpwords5F43CC,5F4418,5F4434,5F44AC,5F452C,5F45FC;SHA256`b8e3134c8059cca66c82a4658c1ba2793d61d622f1ede56f6c97d0473cc45f51`. Dispatchmenuwordsarein [specialcapacity/pickup](SYMBOLS_INVENTORY_SPECIAL_CAPACITY_AND_PICKUP.md). Lowerresource/recipequeriesare [inventoryrecipes](SYMBOLS_INVENTORY_USE_RECIPES.md);pairdeferreddecisionis [classifier](SYMBOLS_RESOURCE_PAIR_DEFERRED_ACTION_CLASSIFIER.md). Originalfeaturelabels,callbackfrequencyandcostremainunknown.

Owned-word audit:7 rows,785 distinct instruction words verified,90 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited. Plainbyte-equivalentaliasesarenotnewsemanticrows.
