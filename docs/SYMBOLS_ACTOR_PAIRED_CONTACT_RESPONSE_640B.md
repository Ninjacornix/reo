# Paired contact response phases and score admission helpers

Static File #1 US, 2026-11-05. Three complete original o2 bodies reviewed, including every phase, initial-entry fallthrough, timer branch and delay slot. No execution, build, attachment, live memory, input or networking. Addresses/offsets/states/flags are hexadecimal; explicit counters and float values below are decimal. Original interaction names remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x640620](../recomp/config/output_ovl/o2/o2_00640620_0x640620.cpp) | `test_actor_c94_bit8_clear_candidate` | Confirmed static mechanics | a0actor. Returns1iffwordC94bit8clear,else0;no mutation/nullcheck. Concrete fieldpredicate,notgenericreturnstub. |
| [o2 0x6409E0](../recomp/config/output_ovl/o2/o2_006409E0_0x6409e0.cpp) | `test_actor_current_player_target_score_against_class_threshold_candidate` | High mechanics; candidate role | a1actor;a0unused. Pointer24mustnonnull andtargetclass2==0; signedscoreBF8+2*targetbyte3 >=4000decimalwhenactorclass3==1,else>=250. Returnsnormalized1/0. No targetindexbound,activityorroomcheck. |
| [o2 0x640B00](../recomp/config/output_ovl/o2/o2_00640B00_0x640b00.cpp) | `update_actor_paired_contact_response_phases_and_partner_signals_candidate` | High mechanics; candidate role | a0actor. Sets54AbitsC,32=FF,handles6673C0resettoidle. ResolvespartnerthroughsnapshotB1D/R1whenphaseA!=0,validatesclass0identityand63EF30policy,andcanpromotephase5/FFbeforephase dispatch. Phases0..9/FFlinkpartner,selectmotiontriplet,align/interpolate,tickanimation,waitB1E63,signalpartner4,thenexitordepartthrough1043. Unknownoriginalactionenum;returnvalueisnotalocalsuccessflag. |

The paired updater saves incomingphaseA before any checks. EverycallORs54AwithC andsetsbyte32=FF. If6673C0 returnsnonzero,it clears54F/548bit1,assigns8/9/A/B=1/0/1/0,snapshots667370,chooses2050start0blend10andactivatesbank58C7B0,thenreturns. It doesnotcallanimationtickonthisresetpath.

For currentphaseA!=0, it reads record`R=74F250+60*B1D`, takesR1asentityslot, and derives partner`42EB00+D90*R1`. There is no FFslot or activebyte check here; arithmeticbasepointeris testedfornullafteraddition,whichdoesnotnormallyvalidate anarrayindex. For sourceclass2==0,partnerC26mustequalsourcebyte3orelsephaseFF. 63EF30(partner) false promotesphases<5to5,butleaveslater/FFstates. B1E==6withphase4andanimationclock1E4notordered<end1ECalsopromotesto5. If anyofthesecheckschangephasefromsavedvalue,it calls67E230(actor,1) BEFOREprocessingthenewphase.

| PhaseA | Concrete work and transition |
| --- | --- |
| 0 | IncrementsAto1,54F=B0,D10=1,snapshots;clearsB22/B1E/B9F. Resolves663350(unsigned148,unsigned149). Nullresultimmediatelyresetsidle2050. Otherwise ownB24=partner,B1D=partnerB98;partnerB1C/B1E=1,partnerB1D=sourcebyte3,partnerB24=source,partnerB20=3;clearsownrootXYZ4E4/8/C. No phase1fallthrough thiscall. |
| 1,2 | Phase1incrementsAto2thenfallsintophase2;phase2incrementsAagain(to3),zerosE/10,58C7F0,selectsdescriptor7110C0+24*B99 withstart0/blend10. SavesXYZintoC40/44/48ANDC34/38/3C,activatesbank. No partnerresolutionisrequiredonphase0entrybutphases1/2useprelude'sresolvedpartner. |
| 3 | IncrementsAto4,calls6681C0(actor,2),thenfallsintophase4duringthesamecall. |
| 4 | Nonzero signedtimer10interpolatesC40->C34 using665E60 withstep8-timer,total8,thenpredecrements10. NonzeroEpredecrements/addsC4Etoyaw;whencounterbecomes0snapsyaw624C80(partner). IfEwaszero,573480(actor,0,f12=12,f13=1)canrearmEfromowned10.0(or10/2when3243CCnonzero),thenC4E=signed16(targetyaw-currentyaw)/E. Ticks58C300(actor,1);signedlow8result2calls6681C0(actor,3). B1E==63clearsB1EandincrementsAto5. |
| 5 | WritespartnerB1E=4,58C7F0,incrementsAto6;descriptor7110C0+8*(3*B99+1),start0/blend10. No nullpartnerguardatstore. |
| 6 | Signedhealth>=2and573480(actor,0,21,1)nonzeroincrementsAto7,58C7F0,selectstripletdescriptorindex2. Otherwise58C300(actor,1);positive signedlow8completionsetsA8. Health<2stilladvancesanimationratherthanchoosingtriplet2. |
| 7 | 58C300(actor,1);positive signedlow8completionsetsAFF. |
| 8 | IncrementsAto9,5D6ED0(actor,0),58C7F0,selects1043start0/blend10. |
| 9 | Ticks58C300(actor,1),positivecompletionclearsBA0bit00040000. Class2==1calls5F6800(actor,0),sets54F=A0/action4/0/0A/0,snapshots,publishes67E230(actor,1). Otherclasses65FBA0(actor,0A). |
| FF | Byte32=60decimalwhen3243CC==0,else30;resets54F/548bit1,action1/0/1/0,snapshot,2050start0/blend10,activatesbank. |
| Other | Returnswithoutadditionalphasebody;initialflags/partnerchecks/publicationmayalreadyhavechangedstate. |

Phase4's interpolationtimer10isnotrearmedlocallyinthephase2initializer,it isclearedthere;laterpartners/animationcommandsmustsetitforinterpolationwork. TimerEusesowned711070float10.0,raw00002041,SHA256`80c8a717ccd70c8809eb78e6a9591c003e11c721fe0ccaf62fd592abda1a5593`. The admittedrearmis5or10withtheobservedwriter;thefunctiondoesnotintroduce agamespeedmultiplier. 3243CCisusedtomatchoriginalcounterregime,notdiagnostics.

The first descriptorbank7110C0..7110D7is24bytes,three8-byteentries: signedhalves`(0060,0,3,3),(0060,0,1,1),(0060,0,2,2)`,SHA256`acaf95bd9c83737644e84436134f22867f3139005c37965577e08185894cce34`. BankB99isuncheckedlocally;thisownedbank0windowdoesnotproveallruntimebankextent. Descriptorsemanticsandbankactivationremainin[animation](SYMBOLS_ANIMATION.md),[savedtransformhelpers](SYMBOLS_DISPATCH.md),and[interpolation/heading](SYMBOLS_ACTOR_ACTIONS.md). Partnerpolicy63EF30isin[snapshothelpers](SYMBOLS_ACTOR_SNAPSHOT_AND_SHARED_CONTROL_HELPERS.md).

The partner-nulltestafterfixedpoolarithmetic and phase5'sunguardedpartnerstore are admissionquestions,not reproducedfaults. Callbackreturnvalues,entitylifetimes,phasewriters,actualtimersandperformancecostwerenotsampled. Original o2base570000SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Full owned-body audit: 482 original words verified; 45 omitted words all zero/NOP; zero conflicts and zero omitted nonzero words.
