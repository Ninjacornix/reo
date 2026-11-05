# Model target-angle mode dispatcher6613A0

Static File #1 US owned o2 review, 2026-11-05. Entire6613A0..6621EB (870 original nonzero words plus omitted zero words) read in three contiguous slices, with all seven jump-table targets, recursive paths, delay slots and exits. [Identity](FUNCTION_INDEX.md). No runtime access, builds or performance measurements. Addresses, offsets, state/angle codeshexadecimal; scalar distances/countsdecimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6613A0](../recomp/config/output_ovl/o2/o2_006613A0_0x6613a0.cpp) | `dispatch_actor_model_target_angle_return_tracking_script_and_input_modes_candidate` | High complete branch/call contract; original node/mode names partial | a0actor,a1low8mode0..6. Fixednode874two-angle response; mode0returntoneutral,1targetselection/tracking,2globalpoint/node15response,3no-op,4scriptedpoint/actortracking,5inputoffset,6origin-pointresponse. Mode2computedtargetnotcommittedinsetup and invalidB48targetremain explicit limitations. Fullmechanicsbelow. |

Notation: N=word(actor34+874),parentP=word(actor34+870). `Angle(f)` means original `CVT.W.S(.5 + 65536*f/binary32(2pi))`,usingguestconversionandlow16wherestored. `A(x)` means1920A0(float(x)),retainedasoriginalscalarhelper. `Step(v)`=661160(actor,pointerv),whosecompleteclamps/division/modelupdateare[documented](SYMBOLS_ACTOR_MODEL_NODE_POSITION_AND_ANGLE_RESPONSE.md). `Select(k)`=65F0C0(actor,mode1,width-8000,ordinalk,distance1000),with[sortedtarget/conecontract](SYMBOLS_TARGET_CACHE_REBUILD.md). `Delay()`drawsRNG1 andstoresC30=(30+(low16rand%120))/(3243CC==0?1:2),usingunsigneddivision.

Prelude durationF=12if3243CC==0else6. Ifsignedhalf324200==1 andsigned4BADF8==0,returnimmediately. BA0bit8000 ormask38 forcesmode0. Ifsignedbyte211mask18nonzero andrequestedlow8mode!=0,forcesmode0 andBD1=1. ConvertN.float110/114toincominganglesU/V. NonzeroBE0targetwithbyte0==0 ormodel34==0 iscleared;targetpointeritselfotherwiseassumedvalid. Low8mode>=7returnsaftertheseoperations. Table740370[28] targets mode0=661524,1=661664,2=661B94,3=6621C0(return),4=661CBC,5=661EEC,6=661FE4.

## Mode0: return response toward authored node angles

IfBD1!=0,clearBD1. Ifsigned4BADF8==0,setBD2=10. Otherwise positivewordB60 setsBD2=low16B60,thenBD2=(3243CC==0?signedBD2:trunc(signedBD2/2))+1;nonpositivewordB60setsBD2=10. AfterwardsBD1!=0 orBD2==0 returns. BuildthreehalfvectorAngle(N110),Angle(N114),Angle(N118);Step(vector). NewlyzeroBD2calls661310(actor)toresetangles/counters,targetBE0andC30. Othersreturn. Halfwordwrapandnegativecountersarenotnormalized.

## Mode1: target selection and response

Alwaysfirstcandidate=Select(0),evenwhentrackingalreadyactive. IfBD1==0:

- BD2!=0 recursivelycalls6613A0(actor,0),thenreturns.
- BD2==0,C30!=0 decrementsC30andreturns.
- BD2==0,C30==0 andbothBE0/candidatezero returns. OtherwiseBE0=candidate,BD2=1,Delay(),thencontinues. AnoldnonnullBE0withnewnullcandidatecanthereforebeclearedhere.

IfBE0nonzero,sourcepoint=parentP.translation30XYZ;targetpoint=indexednode552translation30XYZwhen targetmodel820baseentrynonnull,elsetargetroot38XYZ. Computedelta,376E70bearing(source,target)and191CC0(delta). IfA(signed16(bearing-ownyaw))>A(16384),clearBD2/C30. If191CC0scalar>1000,alsoclearBD2/C30. Neitherconditiondirectlyclearstarget.

WhenBD2==0: C30!=0 decrementsC30;C30==0 recandidateswithSelect(1). IfthisequalsBE0,reselectSelect(0);ifdifferentbutnull,reselectSelect(0);differentnonnullretained. SetBD1=0,BE0=result,Delay(). Continueaftereitherpath. NullBE0setsBD1=1,recursivelymode0,andreturns.

Nonnulltarget:661110(target,target552,outQ).191430(localM,parentP). CopyN.float11C/120/124asreferenceR. TransformQby191A40(Q,M),addM.translation30XYZ.376EF0(outangles,R,Q). Negatefirstangle;second-=Angle(N114);third=Angle(N118). IfBD1!=1,compareA(first-BD8)andA(second-BDA): whenfirsterror>seconderror,BD2=CVT.W.S(1+A(firsterror)/(6144/F));elseBD2=CVT.W.S(1+A(seconderror)/(8192/F)). SetBD1=1,Step(outangles). No targetpointerboundsorselectednode-nullguardaddedbeyondoriginalchecks.

## Mode2: global point and node15 response

IfBD1==2 andBD2!=0:predecrementBD2,advanceBD8+=BD4andBDA+=BD6,constructangles(BD8,BDA,Angle(N.floatF0)),call58C750(actor,node15,angles),return. ThispathdoesnotcallStep.

OtherwisecopyglobalXYZ4A6D48toQ,add170toY;661110(actor,node15,outR),376EF0(outangles,R,Q),negatefirst,second-=ownyaw92,BD1=2,return. **The calculatedstackanglesarenotcopiedtoBD4/BD6/BD8/BDAorpassedtoStepinthissetupbranch.** BD2isnotinitializedhere. Theirintendedconsumptionrequirescaller/context;noneisinvented.

## Mode4: scripted point/actor tracking

PositivewordB60:BD2=low16B60,then(3243CC==0?signedBD2:trunc(signedBD2/2))+1;BD1=4. ThisinitializationoccursoneverypositiveB60call. WordB60==0 recursivelymode0andreturns. NegativewordB60retainspriorcounter/modebutstillcontinuestargetcalculation.

TargetQselection: B48==0 copiesactorB54/B58/B5C. B48==1 calls661110(B4Cactor,node0,outT),661110(B4Cactor,node2,outQ),thenreplacesQ.Y=T.Y+float(signedwordB50). OtherB48valuescontinuetotransformationwithouta localQinitialization;validscriptadmissionremainsunknown.

661110(actor,node15,outR),191430(localM,parentP);transformRby191A40andaddM.translation;transformQby191A40andaddsameM.translation.376EF0(outangles,R,Q),negatefirst,second-=Angle(N114),third=Angle(N118);Step(outangles). No targetactorlifetimecheckonB4C.

## Mode5: input-offset response

IfBD1!=5,setBD1=5,BD2=1,BD8=U,BDA=V. Firsttarget=U+signedlow16(CVT.W.S(float(6144*signedhalfFA6)/127));second=V-signedlow16(CVT.W.S(float(8192*signedhalfFA4)/127));third=Angle(N.floatF0). Step(target). U/Varefreshlyconvertednode110/114thiscall,notcachedBD8/BDA. Inputhalvesarenotlocallyclamped;Stepappliesitsownanglelimits.

## Mode6: origin-point response

IfBD1==6 andBD2!=0:predecrementBD2,advanceBD8+=BD4,BDA+=BD6,construct(BD8,BDA,Angle(N.floatF0)),Step(vector),return. StepitselfalsodecrementsBD2,sooriginaldoubledecrementisretained;predecrementtozeroisreplacedby1insideStepbeforeitsdecrement.

OtherwiseQ=(0,170,0),661110(actor,node15,outR),376EF0(outangles,R,Q),negatefirst,second-=ownyaw. IfBD1!=6,compareA(firsttarget)andA(secondtarget) **withoutsubtractingcurrentanglesforthiscomparison**. FirstgreaterselectsBD2=CVT.W.S(1+A(firsttarget-BD8)/(6144/F));elseselectsCVT.W.S(1+A(secondtarget-BDA)/(8192/F)). SetBD1=6,Step(outangles). Setupdoesnotlocallyinitializeoutangles' thirdhalf;StepusesthefirsttwoonlyandcomputesitsownthirdrotationfromN118. Noassumptionthat376EF0suppliesallthreeisneeded.

Owned740370[28] SHA-256 `c356a97ad40f8419425a61f73fd8e73de6abcb14af67bc87e1d94917dda55b64`;alltargetsbodiesread.712B20[16] words{120,0,30,0},SHA-256 `a26ba195c7b699bfa7f0dd6552f418f10f1478eff9ea0eeba91563f5f143ae4e`;only120/30wordsusedforDelayhere.740470binary32(2pi)identityisdocumentedwiththeStephelper. Dynamicglobal4A6D48isreadasanaddressedruntimeinput,notclaimedcapturedliveevidence.

This completes the static function contract while preserving unknown script modes, node names and original target-angle intent. It doesnotprovetotalframefrequency,cost,animationqualityoranyslowdowncause/fix.
