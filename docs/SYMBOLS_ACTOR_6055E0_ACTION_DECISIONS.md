# Actor6055E0 action decisions and transition interposition

Static File #1 US, 2026-11-04. Four complete original o2 bodies. High-confidence branch mechanics, candidate action roles. No target execution/build/attachment/live memory/input/timing. Addresses, IDs and offsets are hexadecimal; distances and explicit counts are decimal. Numeric policy results retain their original unknown enum identities. Shared timer/motion contracts: [shared helpers](SYMBOLS_ACTOR_6055E0_SHARED_HELPERS.md); consumers: [root/primary1](SYMBOLS_ACTOR_6055E0_ROOT_AND_PRIMARY_ONE.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x608EA0](../recomp/config/output_ovl/o2/o2_00608EA0_0x608ea0.cpp) | `choose_actor_6055e0_primary_one_idle_or_roam_by_rng_candidate` | High mechanics; candidate role | Saves8/9->BE8/9,primary1,A/B0. RNG16%A<7 setsBA0=0;elseBA0=1. On firstbranch,oldsecondary1 setsA5beforewritingnewsecondaryBA0. Calls609970,setsC36=1. No targetrequired. |
| [o2 0x608F50](../recomp/config/output_ovl/o2/o2_00608F50_0x608f50.cpp) | `choose_actor_6055e0_close_target_transition_by_current_motion_candidate` | High mechanics; candidate role | Saves8/9,primary1/secondary3,A/B0. Ifmotion520==11 selectssecondary2,B3instead. Calls609970,setsC36=1. No targetlookuporhealthcheck. |
| [o2 0x608FC0](../recomp/config/output_ovl/o2/o2_00608FC0_0x608fc0.cpp) | `choose_actor_6055e0_target_action_from_cached_metrics_predicates_and_rng_candidate` | High mechanics; candidate role | Requiresword24;otherwiseunchanged. TargetBA0bit2000000 forcesprimary1secondaryA/BbyRNG. Else cachedbearing,targetyaw,distance,5A6A40/5AA110,target54F selectprimary1/2secondaryactions. DoesnotclearA/B,reseedtimers,savepreviousstateorsetC36;outer609250suppliesthose. |
| [o2 0x609250](../recomp/config/output_ovl/o2/o2_00609250_0x609250.cpp) | `choose_actor_6055e0_next_action_with_policy_cached_target_and_turn_interposition_candidate` | High mechanics; candidate role | Requiresword24. SavesBE8/9,clearsA/B. Cachedcell<FA andoldsecondary!=5 ->608EA0. Else5A62D0(actor,500,2AA8,11)signedbytepolicycode selectsdistance/height/bearing/RNGactions. Priorstateandnewbearingscaninterposemotiontransitionsecondary6/C. Calls609970/C36=1exceptearlytargetNULL/idlehelper. No per-call wait loop. |

608EA0 uses RNG16 modulo10,threshold7. The common oldsecondary1 branch preservesA5 when returningtoidle,allowing605A20'sseparatemotion10phase;itdoesnotpreserveA5whenrandomroamselected. Both helpers keep the original oldstate snapshots,then609970alsochoosesBbycurrentstate. In608F50,its explicitB3survives because609890 does not seedBforprimary1secondary2.

608FC0 target-action selection (T=word24,d=cachedfloatBD4,b=signedBD8,h=sign16(rawcachedtargetbearing-T.yaw)):

| Ordered decision | Writes / further test |
| --- | --- |
|TargetBA0bit2000000|primary1,secondaryA whenRNG16&1,elseB;earlyreturn|
|d>=300 and5A6A40(actor,T,distance500,yaw1554,mask11)!=0|primary2,secondary0|
|5A6A40(actor,T,distance200,yaw2AA8,mask11)!=0|primary2;secondary1onlyif5AA110!=0,pitch90==0,hstrictly(-4000,4000);else0|
|Otherwise|primary1;target54F==3 ->secondary5|
|d>800|RNGlow4<6 ->secondary4,else5|
|500<d<=800|secondary4|
|d<=500,RNGlow3<2|secondaryC,12=1;5AA110==0changessecondary0;otherwiseB=1onlyifd<300andhstrictly(-4000,4000),else0|
|d<=500,remainingRNGlow3<5|secondaryA|
|Remaining|secondaryB|

Targetpredicate semantics retain [cached target metrics](SYMBOLS_CACHED_TARGET_METRICS.md) andexistingdistance/yawadmissionhelpers;no fresh spatialsearch isassertedbyreadingcachedfields. Branches are ordered;fallbacks retain earlier stores,including12=1evenifsecondarychanges0.

609250 reads signedhalf BF8+14*C25+2*C26. If<FAandoldsecondary!=5,itcalls608EA0andreturns;thathelperoverwritesBE8/9withcurrentunchanged8/9,butalsoownstheidle/randomtimerpolicy. Otherwise code=sign8(5A62D0(actor,500,2AA8,11)):

| Code | Candidate action selection |
| --- | --- |
|1|primary1;target54F==3 ->secondary5;d>800 chooses4whenRNGlow4<6,else5;d<=800 ->secondary4|
|2|primary1;RNGlow1 ->secondary7when1,else8|
|3|TargetBA0bit2000000 ->primary1secondaryA/B. Else detailed close/height/orientationconditions below|
|4|Calls608FC0,thencommoninterposition/timerwork|
|Other|IfbyteC27==0calls608FC0;otherwiseprimary1secondaryA/BbyRNG|

Code3 first computes h fromrawcachedtargetbearing minus targetyaw. A close joint candidate requiresd<200,absoluteYdifference<20,targetBA0bit800000clear,5AA110!=0,bstrictly(-4000,4000),hstrictly(-4000,4000):select(2,1). Else d<500andbstrictly(-3000,3000)selects(2,0). Remainingcasesselect(1,A/B)byRNG. These are observed numeric thresholds;originalattacktypesnotinferred.

The following turn-transition interposition runs after the initial selection. For old(1,9) and code3/4, ifnewsecondarynot9/8, then whenbwithin[-1555,1555] jumps directly to609970,keepingtheselectedstate. Otherwise12=(newprimary==2),B=newsecondary,andstatebecomes(1,C). This path differs from the ordinarylaterthreshold[-1000,1000]. Next, old(1,5) transitioningtoanotherprimary1secondary places thenewsecondary inB andselects(1,6). Finally code3/4,secondarynot9/8andboutside[-1000,1000] caninterpose(1,C),with12indicatingthenewprimarywas2andBthenewsecondary. The common ending calls609970 then setsC36=1;the helper may overwriteBonlyforits documented currentstatecases.

All target-dependent entry points locally checkword24 before dereferencing;the downstreamcachedslotselectorsC25/C26andactor/modelpolicypointersremaincallercontracts. These bodies choose state once percall;nonecontainsanunboundedtargetsearchorwait. Noactualcalleradmission,framefrequency,AIcostorincidentcausewasmeasured. Alloriginalinstructionwordsareboundtotheownedo2filebase570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Owned-word audit:four complete bodies,517 original instruction words verified,32 omitted zero/NOP words,zero conflicts and zero omitted nonzero words. CurrentliveIDs/actualannotations/links/diffclean; no shared index mutation.
