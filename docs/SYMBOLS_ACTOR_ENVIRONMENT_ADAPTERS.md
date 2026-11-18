# Actor category five through nine environment adapters

Static File #1 US research, 2026-11-04. Four complete original bodies reviewed.
Addresses/offsets hex unless marked decimal. No execution, build, attachment or
engine changes. Category8 is reviewed separately with its digit-input helpers.
Original scenario and effect identities remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6FC580](../recomp/config/output_ovl/o2/o2_006FC580_0x6fc580.cpp) | `tick_actor_category_five_scene_and_actor_vertical_offset_candidate` | High mechanics; probable role | Pretestedplayercount4BAEA0 scan setsadmissionwhenanyroom3E actor666080(actor,0)lowbytezero;withoutadmissionforcesphase4=2. Phase0->1,savesreturnphase5,setsE=word60,byte3=63,C=-2000 decimal ifword68nonzeroelse0;foractiveactorlist3B5854 skipsbyte5==1A,otheractivebyte0/1actorsY=C4+C. Phase1word68nonzeroincrementsCby10,atC>=1900snaps1100;zerodecrements10,atC<-4199snaps-3000. Iteratesmodelgroups49EEF0 headercountbyte3,baseIDs4A1A10+group,count49EEF4+group;exceptabsolute slot5 writes slotY=4A3C54+40*slot+C. RepeatsactorYpass,predecrementsE;post<=0 phase2. Phase2signals5703E0(word64,1),clearsrecord;phase63restoresphase5andbyte3=63;otherphasesreturn. Literalwrapthresholds andfiniteadmission assumptions retained. |
| [o2 0x6FC890](../recomp/config/output_ovl/o2/o2_006FC890_0x6fc890.cpp) | `start_actor_category_six_selected_player_room_transition_candidate` | High mechanics; probable role | ClosesgameplayUI6E1430,audioB8,581AF0(0)sceneRecord. Setsrecord44=actorword60,48=selectedplayerindex+1,34=4A5C30+10E0*4BADED,3E=scene31. Signals5705F0(actorword64,1,actor100),then5C1710(sceneRecord). Doesnotclearoriginalcontrollerrecordinthisbody;transitionownershipunknown. |
| [o2 0x6FC950](../recomp/config/output_ovl/o2/o2_006FC950_0x6fc950.cpp) | `emit_actor_category_seven_five_optional_positioned_effects_candidate` | High call contract; probable effect role | Pretestedfivewordsactor60..70. NonzeroID selectsindexID-1;calls5DEE20(position73CA40+12*index,signedhalf73CAB0[index],word73CAD0[index]). Then5B93B0 clearsrecord. Indexrange andoriginaleffectidentityrequirecallerassets;notanunboundedparticleloop. |
| [o2 0x6FD060](../recomp/config/output_ovl/o2/o2_006FD060_0x6fd060.cpp) | `signal_actor_category_nine_random_variant_and_completion_flags_candidate` | High mechanics; probable role | random(0)low16 shifted6 then&3 picks0..3;signalsone5705F0(flag26..29,1,actor100),thenalwaysflag59set,clearsrecord5B93B0. Eachselectedbranchretainsownerbyte100;nooriginalreward/itemmeaningasserted. |

Category5 preservesalloriginalgroup/list scans andskipsabsolute modelslot5;
staticcoverage doesnotestablish howmany records arepresent orwhichroom
activatesit. Category7'sfirstownedposition73CA40 is (4995,600,9544)
decimal;ownedparameter arraysare distinct. No unsupported arrayextent
isinferredfromthe fivecontrollerargumentwords.

Related[category dispatch](SYMBOLS_ACTOR_AUDIO_CATEGORY_DISPATCH.md) and
[category0..3 cleanup](SYMBOLS_ACTOR_CATEGORY_ZERO_TO_THREE.md).
