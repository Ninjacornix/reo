# Actor related-target admission and route-score update

Static File #1 US research, 2026-11-04. Six complete original bodies reviewed.
Addresses/offsets/flags hex; explicitly described scalar distances/countsdecimal.
Original policy/actor enums and score units unresolved. No execution, attachment,
live table reads, profiling, replay or fixes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x635640](../recomp/config/output_ovl/o2/o2_00635640_0x635640.cpp) | `select_actor_related_target_from_pool_priority_and_route_scores_candidate` | High mechanics; probable role | B9C==1returns0beforewrites. Resets scratch7445C8=0,7445D0=7F,7445B8=decimal100000000. BA4=0runs5890;1runs5890then5BB0onlyifnochoice;2runs5BB0then5890onlyifnochoice;othernoscan. Nochoice->0. Choicecopiespool/slottoC25/C26;pool0related24=4A5C30+10E0*slot,BD8=5A9B10(actor,targetsignedbyte3),BD4=5A9950;pool1related24=417090+1170*slot,BD8=5A9E70,BD4=5A9D20. C94|800,returns1. Poolindex/slotboundsremainsearchcontracts. |
| [o2 0x635890](../recomp/config/output_ovl/o2/o2_00635890_0x635890.cpp) | `select_first_admitted_four_pool_target_by_priority_or_score_candidate` | High mechanics; probable role | a0actor,a1signed16scorethreshold. FouractorBB6..BB9priorityslotbytes. IfC32==0,prepassD60eligibilityeach;firsteligiblewith5A9950(actor,signedslot)-unsignedhalf72F8E0[actor3]<=100decimalandtargetBA0bit20000000clearwins,sets scratchpool0/slot,zerosfirstfourBF8halves,selectedscore1FFF. Otherwisefullpass/reusedeligibility;firstvalidslotwhoseBF8[slot]>thresholdand(C94bit40orabs(targetY-actorY)<170decimal)wins. No nearestminimumoverpool;firstadmittedtableorder. |
| [o2 0x635BB0](../recomp/config/output_ovl/o2/o2_00635BB0_0x635bb0.cpp) | `select_closest_ten_pool_target_above_score_threshold_candidate` | High mechanics; probable role | a0actor,a1signed16threshold;loops10decimalactors417090+1170*i. Rejects666080(target,0)nonzero orC0C[i]<=threshold. Distance5A9D20stored7445BC. Firsteligiblewhensentinel7Facceptedwithoutheighttest;replacementrequiresstrictsmalldistanceand(C94bit40orabsY<170decimal). Storespool1/slot/distance7445C8/D0/B8. Tiesretainfirst;noheighttestaddedtoinitialselection. |
| [o2 0x635D60](../recomp/config/output_ovl/o2/o2_00635D60_0x635d60.cpp) | `admit_same_room_four_pool_target_excluding_policy_and_class_a_candidate` | High mechanics; probable role | a0actor,a1signed16slot->4A5C30+10E0*slot. Return-1if1E2differs,666080(target,0)nonzero,targetBA0bit8,6689B0(target)nonzero,orclass54F==A;otherwise1. No slotboundsguardorownactorexclusionadded. |
| [o2 0x635E20](../recomp/config/output_ovl/o2/o2_00635E20_0x635e20.cpp) | `throttle_actor_four_pool_score_update_after_three_saturation_events_candidate` | High mechanics; probable role | Passesactor,a1,a2,f12/f13throughF40unless6BB010(actor)nonzeroandactor3==1. Thengatesignedbyte755350[C26]>=3:zeroBF8[C26]andreturn;otherwiseF40,ifpostBF8[C26]>=FA0incrementscounterbyte. No C25pooltest/C26indexboundinthisbody. Counteroutsideowneddata,notreadlive. |
| [o2 0x635F40](../recomp/config/output_ovl/o2/o2_00635F40_0x635f40.cpp) | `update_actor_two_pool_route_scores_or_hold_selected_target_candidate` | High mechanics; probable role | a0actor,a1policyvalue,a2modelnode,f12/f13parameters. B9C1ora1zeroreturn. C94bit20predecC30;nonnegativezerosfourBF8andtenC0C,setsBF8[C26&3]=1FFF,predecC32clamp>=0,returns. Negativeclearsbit20/C30,thenordinarypathC320,copy64bytesfromactor34+820+4*(a2&FF),usesfinalXYZat30,clearsscratch2x10matrix744610,744600=-1,7445F8=7FFF. Fourpoolandoptionaltenpoolloopsbelow. No generalrootcauseorcostclaim. |

635F40 ordinary update complete loop contract:

- Fourpool4A5C30+10E0*i,i0..3. 666080(target,0)nonzero,class54F=A,orBA0bit8
  ->ownBF8[i]=0. Same1E2andtargetbyte1nonzero->636410(actor,target,policy,
  copiednodeXYZ,t0=0,t1=i,f12/f13preserved). OtherwiseactorB9A!=0 computes
  distance5A9950,convertsunsigned32using2^31split,636BB0(actor,distance,
  C8A,t0=i,a3=0). B9A0->BF8[i]=0.
- IfownBA4==0,return;otherwisetenpool417090+1170*i,i0..9. Targetbyte0zero
  orBA0bit80->C0C[i]=0. Differentroom/inactivebyte1 withownB9A!=0 invokes
  distance5A9D20->636BB0(actor,distance,C8A,t0=i,a3=1);B9A0zeroscore.
- Same1E2andtargetbyte1nonzero invokes666080(target,0);**nonzeroreturn
  exitsentireF40**,notjustskipthisslot. Otherwisecalls636410(actor,target,
  policy,copiednodeXYZ,t0=1,t1=i,preservedfloats).

636410/636BB0 score arithmetic and6BB010/6689B0/666080 predicate mechanics
remain independently scoped dependencies;this notebook preserves their call
arguments without inventing event names or pure-function guarantees.

Owned72F8E0firstfourunsignedhalvesare0.635890indexesbyactorbyte3;
no full classrange or remainingtableextent inferred. Poolarrays,scratch7445xx,
744610andcounter755350areoutsidefile-backedo2andwerenotinspectedlive.
Thefirstpasspriority/firstselectionheightasymmetryandF40earlyexitwerechecked
throughbranch/delayslots. Selectionfrequency/activepoolcontentsremainunknown.
Related[actor6Cbootstrap](SYMBOLS_ACTOR_6C_BOOTSTRAP.md),
[scoreutilities](SYMBOLS_ACTOR_ROUTE_SCORE_UTILITIES.md),and
[pointqueries](SYMBOLS_RUNTIME_ROUTE_POINT_NEIGHBORS.md).
