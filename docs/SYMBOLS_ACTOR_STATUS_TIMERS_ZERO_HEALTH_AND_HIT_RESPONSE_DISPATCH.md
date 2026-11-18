# Status timers, zero health and pending hit responses

Static File #1 US owned o2 analysis, 2026-11-05. Full660310..6605A7,6607D0..660977,660980..660AEB and660AF0..661103 reviewed with every branch, delay slot and exit. [Identity](FUNCTION_INDEX.md). No runtime work or timing measurements. Numeric states, addresses, offsets and masks hexadecimal; timer intervals/damage amounts decimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x660310](../recomp/config/output_ovl/o2/o2_00660310_0x660310.cpp) | `tick_ba0_status_one_two_damage_and_expiry_with_original_rng_order_candidate` | High complete mechanics; status names unknown | AlwaysdrawsRNG1 before pause/BA0gate. Originalclock interval sets, one-health-unit tickforbit1, five-unit tickforbit2 withhealthfloor1, durationexpiry clearsbit2. Full sequencing below. |
| [o2 0x6607D0](../recomp/config/output_ovl/o2/o2_006607D0_0x6607d0.cpp) | `select_zero_health_action_four_or_recovery_by_status_and_c5e_timer_candidate` | High complete mechanics | Only unpaused,sessionhalf324200!=1,health==0,primary1/2. BA0/BA4 andclass selectterminal4/0,recovery65FBA0,or4/3 afterC5Eexpiry. Doesnotadvanceanimationorclamphealth. |
| [o2 0x660980](../recomp/config/output_ovl/o2/o2_00660980_0x660980.cpp) | `override_pending_hit_response_for_selected_54f_action_classes_candidate` | High complete mechanics | Specific54F/secondary mappings below snapshotandreturn1;54F28onlyzeroshealthandreturns1. Allother0. No implicit same behavior for unlisted54F values. |
| [o2 0x660AF0](../recomp/config/output_ovl/o2/o2_00660AF0_0x660af0.cpp) | `consume_pending_hit_apply_status_inventory_cleanup_health_and_response_state_candidate` | High complete mechanics; original damage taxonomy partial | Consumes13F, handles specialclass0terminal,BA0bit80timer response, ordinaryhealthdamage/high13Dpairedaction, inventory/status cleanup, publicationtype5 andnetworkclass1marker. Complete ordered contract below. |

## 660310 timers and RNG

When3243CC==0: intervalI=20,intervalJ=60,randomdurationL=2400+(low16RNG1%6600). Otherwise I=10,J=30,L=1200+(low16RNG1%3300). This randomdraw is unconditional, before signed4BADF8!=0 orBA0bit400000 returns; those skippedcalls stillconsumeRNG. IfBA0mask18 nonzero andsignedhealth544!=0,clearBA0mask18.

- BA0bit1 andhealth>=2: ifbyte4BAE02%4==0 andbyte4BAE03==0 request665CA0(actor,6). ClampunsignedC60down toI. C60==0 setsI withoutdamage. NonzeroC60 decrements; newlyzero calls65FF70(actor,1,0),withoutimmediateintervalreload. Lowerhealthskips thisentirebit1path.
- BA0bit2: clampunsignedC5Adown to newlydrawnL. C5A==0 returnswithoutclearingbit2. For nonzeroC5A andhealth>=2,clampunsignedC58down toJ. ZeroC58 setsJ;nonzero decrements. NewlyzeroC58 invokes660240(actor); onlynonzeroadmission calls65FF70(actor,5,0),forceshealthto1 ifresultinghealth==0,andrequests665CA0(actor,6).
- Then decrementnonzeroC5A. Newzero orsignedhealth<2 clearsC5A/C58 andcalls6605B0(actor,3),whichclearsBA0bit2 andpublishes. The expiration test follows damage and may therefore seechangedhealth. Bit1 isnotclearedbythisselector.

All counters are per-invocation halfwords. [Periodicadmission](SYMBOLS_PARENT_BOUND_EFFECT_EMISSION_SOUND_AND_FADE.md) establishes660240'smotion/statusgate; [statusclear](SYMBOLS_RESOURCE_EFFECTS_AUX_LISTS.md) establishes6605B0. No pollingwait, walltime or verifiedstatusailmentname is inferred.

## Zerohealth6607D0

Signed4BADF8!=0, signedhalf324200==1,health544!=0 orprimary8outside{1,2} returns. Then:

- BA0mask1F0==0: class1 calls5F6800(actor,0),54F=A0,action4/0/0/0,snapshot667370. OtherclassesrequireBA4bit100,then65FBA0(actor,0);absentbitreturns.
- Mask1F0nonzero andBA0bit80: decrementnonzero unsignedC5E. OnlyC5E==0 **and**BA4bit100 continues; thenBA0OR120,5F6800(actor,0),54F=A0,action4/3/0/0,snapshot.
- Mask1F0nonzero,bit80clear: BA0bit10 setreturns;clearuses sameBA0OR120/cleanup/action4/3/snapshot path,withouttheBA4bit100gate.

No67E230publication is directlycalledinthisbody; child65FBA0hasitsownpublicationcontract.

## 660980 exact overrides

Each state assignmentclearsA/Bandsnapshots667370,return1,unlessotherwise stated:

| 54F | Additional gate and resulting behavior |
| --- | --- |
| B | Onlysecondary9==47:byte140=2,action3/0/0/0. |
| 31 | action3/15/0/0. |
| 27 | action3/14/0/0. |
| 30 | secondaryC5 ->action1/C7/0/0;secondaryC8 ->action1/CA/0/0;otherreturns0. |
| 28 | health544=0,return1;noactionchangeorsnapshot. |
| 1A | action3/12/0/0. |
| other | return0withoutmutation. |

## Pendingresponse660AF0 complete order

Signed4BADF8!=0 orbyte4BAE8D!=0 clears13F andreturns. Otherwise13F==0 returns. Nonzeroconsumes13F=0 andORs115bit1 **before**followingadmissionchecks.

1. Class0,150==2,13D==9 special:BA0OR40000800,health0,BA0OR20,5F6800(actor,0),54F=A0,action4/0/0/0,snapshot,OR115bit1,publish67E230(actor,5),return. ThisprecedestheordinaryBA0rejection.
2. BA0mask200008 rejects. Class1 requires1B0110(local4BADED)!=0. BD0!=0 with148==0 rejects. Alreadyconsumed13F/115writesremain.
3. BA0bit80 branch: decrementtimerC5E bysignedhalf(71ADA0+2*byte140). Theadmissioncomparison usessigned16(oldC5E)-signedtableamount;nonpositiveforcesC5E=1,positive storeslow16(oldunsigned-amount). Clamp13D>=10hex to1;setaction3/13D/0/0,snapshot,OR115bit1,return. Noordinarydamage/inventorypathfollows.
4. Ordinarybranch: when148==0 and1B0340(actor)==1, inspectword4A67D0+10E0*(149&3)bit80;set requests37C060(25,byte(4A67C8+10E0*full149),0). Thefirstindexismasked,thelaterindexisnot. Then143bit2 withBA0bit400000clear calls6606D0(actor,1);143bit4 withsamebitclear calls6606D0(actor,2),sequentially.
5. ClearC64/AB8/AD4. Localauthority1B0340==1 calls5F4FD0. Class0 action1/16 checksownerhalf3C5658+60decimal*C7A againstown3+1; mismatchcalls67FF80(actor,2,C7A). Class0 action1/24 calls67FF80(actor,1,C7F),then5F5C50(actor,0,C7F),withC7F rereadafterfirstcall. Class0 action2/B setsBA0bit80000000,65E710(actor). Allclasses666620clearBA0bit80000,666D90clearclass0D28. Nonzero14E applies660060(actor,unsigned14E,0). Localauthoritycalls6DF160(actor);allclasses6689E0(actor). Localauthorityand143bit1clearsetsbyte3B84F4=1.
6. Ifunsigned13D>=80: BA0bit800000 ormaskB8 rejects. Otherwise660980(actor)override/nonzeroreturnends. Nohandledoverride setsaction5/(13D-80 lowbyte)/0/0,snapshot,zeros18hex bytesatB1Cvia107C68,thencommontail. No65FF70healthdamagecallonthishigh13Dpath.
7. If13D<80: savesignedhealthH. Positiveword138requests665CA0(actor,3). Always65FF70(actor,unsignedhalf138,0). Nonzeroresultsetshealth0then660980override;handledoverride returnswithhealth0. OtherwiseifH>=2restorehealth1,selectaction3/13D/0/0,snapshot,publishtype5. Zero65FF70resultalsoallows660980first,thenunhandledselectssameaction3/snapshot/publishtype5withouthealthrewrite. Bothunhandledpathsreachcommontail.
8. CommontailORs115bit1. If1B0310()==1 andclass1,temporarilyORBA0bit10000000,publish67E230(actor,5),thenclearbit. Otherclasses/modesreturn. Thisclass1publicationcanfollowtheordinarytype5publication;notdeduplicated.

Owned71ADA0[32] rawbytes `f4012c01e80300000000000000000000a04e0200c02c0400c089010000460500`,SHA-256 `369031626292a6ee66c0b95e575d6fe7da9673073be930d0f517417d94ec070f`. Firstthree signedhalvesare500,300,1000;thisboundedprefixdoesnotestablishthefull140rangeortreatfollowingbytesasmoreauthoredtimerrows. No140indexboundislocal.

[Health/gaugeapplication](SYMBOLS_ACTOR_PAIRED_HEALTH_GAUGE_APPLICATION_AND_CONTROL_EVENTS.md), [field/terminalhelpers](SYMBOLS_ACTOR_POSE_QUEUE_RESOURCE_USE_AND_TERMINAL_HELPERS.md), and [resourcecleanup](SYMBOLS_INVENTORY_REQUEST_APPLICATION.md) supportchildcontracts. Numericunresolvedcallsremainexplicit;originalhit/statusnamesandcalleradmissionarepartial. Thesecontracts establishnoperformancebottleneck,playbacksymptomorfix.
