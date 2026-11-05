# Actor65A contact reaction, root motion and surface admission

Static File #1 US owned o2 review, 2026-11-05. Full65AED0..65B247,65B250..65B453 and65B560..65B8A7 reviewed, including indirectcallbacksite, every branch, delay slot and return. [Identity](FUNCTION_INDEX.md). No runtimework/build/timingmeasurement. Addresses/states/offsets/maskshexadecimal; distancesdecimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x65AED0](../recomp/config/output_ovl/o2/o2_0065AED0_0x65aed0.cpp) | `apply_actor_65a_contact_damage_and_select_prior_state_dependent_reaction_candidate` | High complete mechanics; original action names partial | Storedreference637490->11C,signalpropagation,callback72B820[type141] with(actor,24),sound6,optional666D40,6407D0damageclassifier(1000),runtimeflag1/2andstatebranchesbelow. Returns0/1/2areadmissioncategories,notuniversalhealthdamageboolean. |
| [o2 0x65B250](../recomp/config/output_ovl/o2/o2_0065B250_0x65b250.cpp) | `transform_actor_root_displacement_with_orientation_state_policy_and_f0_scale_candidate` | High complete numeric contract; unsupportedBA3modeunknown | Buildsstate/BA3dependentmatrix,transformsroot4E4XYZtoC0XYZ,scalesbyF0andaddsposition;54Abit8controlsoneoptionaltransformstep. No timestepreadorrootclearing. |
| [o2 0x65B560](../recomp/config/output_ovl/o2/o2_0065B560_0x65b560.cpp) | `probe_flagged_forward_surface_and_enter_aligned_or_side_surface_action_candidate` | High complete mechanics; original surface type unknown | PositiveC0length/visibilitygates,101*BCsegment,typebits1and100000,normalbearinganglebands andlateralprobes. AcceptedpathsetssecondaryF,A2/C/16,storescontactpoint/normalandpreviousstate. |

## Contactresponse65AED0

R=637490(actor),stored11C. OwnB1E==1 clearsownB1E andwritesR.B1E=6 **withoutnonnullguard**. Dispatchword72B820+4*unsigned141 ascallback(actor,24). Request1B9310(actor,6,0). Positiveword138 calls666D40(R). Class=signedlow8 6407D0(actor,R,1000);class1/2writes74F295+96decimal*B98=1/2. Otherclassesdonotwritethatflag. Savecurrent8/9toBE8/BE9aftertheseeffects. Thisisastoredcontactreference,notnewnearest-targetselection.

DefineSlot()=5A7C40(7125C8,actorCD8),return2withoutresetA/B. DefineTransition(P,S)=set8=P,9=S,clearA/B,return1;itdoesnotcall667370locally.

- Primary2:OR115bit1. Secondary3,A<5:signalnonnullB24.B1E6,667060(actor);140==0return0,otherwiseTransition(3,5). Secondary3,A>=5:Slot(). Othersecondary1/2withactorY>D28:Transition(3,4). Remainingprimary2:class!=0Transition(3,BA3+2);class0Transition(3,0).
- Primary3:class!=0 andsecondary0/1 ->Transition(3,BA3+2);otherwiseSlot().
- Primary4:onlyclass==1 andsecondary1 ->Transition(3,BA3+2);otherwiseSlot().
- Otherprimary:secondary5firstzeros28hexbytesatBF8. Currentprimary1/secondaryF thenSlot(). Otherwiseclass!=0 ->Transition(3,BA3+2). Class0setsprimary3,then140==0secondary0,140==1secondary1,140==2secondaryBA3+2;other140**retainsoldsecondary**. ClearA/B,return1.

No callbackindexboundorcontactlifetimeadmissionislocal. [Damagehelpers](SYMBOLS_ACTOR_5FA100_CONTROL_HELPERS.md), [slotinitializer](SYMBOLS_RECORD_EVENT_SERIALIZATION.md), and [pairedcontrol](SYMBOLS_ACTOR_PAIRED_HEALTH_GAUGE_APPLICATION_AND_CONTROL_EVENTS.md) establishchildcontracts. Owned72B820[32] firsteightcallbacks{635630,635010,635010,635010,635010,635010,635010,635010},SHA-256 `09a9214c7eb88bebfdcbcadedfc62a246f87e12019cfb83891711e7cfc1873d9`;thisboundedprefixdoesnotestablishfull141range. Slotinput7125C8first8bytes=`03ff03ff0305030f`;5A7C40selectsoneoffourpairsusingRNGandinitializestwoslots,notanimationadvance.

## Rootmotion65B250

Let M be localmatrix. BA3==0:identity18FDF0(M),370320(pitch90,yaw92,roll94,M). BA3nonzero withprimary1/secondaryF:191500(M,actor50). Otherwise BA3==1 or2:identity,370320(angles,M),192250(actorD18,T),1913E0(M,T). BA3outside0..2withoutprimary1/FcontinuestouseM**withoutlocalinitialization**;calleradmissionremainsunresolved.

Thenprimary2/secondary1or2:18FE60(T,f12=0,f13=C40,f14=0),1913E0(M,T),skipsnormal54Abit8handling. Otherstates:54Abit8clearcalls18FE60(T,B4,B8,BC),1913E0(M,T);bit8setskipsthese. Inthisnormalbranchalwaysclear54Abit8afterward. Numericmatrixhelperorderispreservedwithoutclaimingthechild'soriginalname.

1919D0(actorC0,actor4E4,M);C0/C4/C8each*=actorF0;position38/3C/40+=correspondingC0. Source4E4XYZretained,localdeltaD8/worldE4untouched,nocollisionqueryormatrixtranslationcommitinthisbody. Callerupdatecadence/F0meaningareexternalcontracts.

## Flaggedsurface65B560

Zero12bytelocalvectorZ. C39==1 orC37!=0 returns. Length=191CC0(C0XYZ);orderedlength<=0returns. SetR=101*BC;endpoint=actorXYZ+C0XYZ*(R/length).5795E0(actorXYZ,endpoint,outpointH,outnormalN,FFFFFFFF,0,&type). Miss,typebit1clear,ortypebit100000clearreturns.

BearingB=signedlow16 376E70(N,Z);delta=signed16(B-ownyaw). CopyNtoV. Branches:

| Delta | Position/yaw admission |
| --- | --- |
| [-1000,1000] | ownyaw=B;XYZ=H+V*R;codeK=0. |
| [-2FFF,-1001] |65CCF0(actor,B,0) nonzeroreturns. Otherwiseownyaw=B+2000,rotateVbyowned740300(+pi/4)using191BC0;XYZ=H+V*R;K=A. |
| [1001,2FFF] |65CCF0(actor,B,1) nonzeroreturns. Otherwiseownyaw=B-2000,rotateVbyowned7402F8(7pi/4);XYZ=H+V*R;K=14. |
| other | returnwithoutnewposition/state. |

Acceptedpathsaveold8/9toBE8/BE9,half520toD2C,oldsecondary9toB. Keepprimary8unchanged;setsecondary9=F,A=low8(K+2),54AOR1,65B460(actor),C36=7,copycontactHtoD0C/D10/D14andoriginalnormalNtoD00/D04/D08. ThusnewAis2,C,16forstraight/negative/positivebranches. Contact/normalwritesoccurafter65B460,notbefore. [Lateralprobe](SYMBOLS_ACTOR_FORWARD_PITCH_VISIBILITY_TIMER_AND_LATERAL_PROBES.md) and [sharedposeconsumer](SYMBOLS_SHARED_BODIES.md) establishtheirsideeffects;thefunctiondoesnotcall667370oractivateanimationlocally.

Owned740300[4]=`db0f493f`,binary32(.7853981852531433),SHA-256 `aed98d3c0cbf205fe0e6bd938c77c51b64f226b2ba81ab715f0d045611bae4b0`;7402F8[4]=`e0edaf40`,binary32(5.4977874755859375),SHA-256 `62e89e0e6ffc6853deef2081929f992a31eeb4d710c25b89788853a2e285b6fc`. No safeNaNnormalizationisaddedtopositive-lengthadmission;originalorderedcomparisonsandfloatoperationsarethecontract.

Originalsurface/actionnames,callbackrange,BA3validityandruntimecostremainunknown. Staticmappingdoesnotconfirmabottleneckorfix.
