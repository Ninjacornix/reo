# Related actor approach, flight and signal release6578

Static File #1 US owned o2 analysis, 2026-11-05. Entire6578B0..657C43,657C50..65810F and658110..658523 read, including all branch/delay slots, twelve-way table and exits. [Identity](FUNCTION_INDEX.md). No runtimework/build/measurements. Addresses/states/motionshexadecimal; floatvalues/timersdecimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6578B0](../recomp/config/output_ovl/o2/o2_006578B0_0x6578b0.cpp) | `update_related_approach_timed_forward_flight_contact_and_landing_candidate` | High complete mechanics; original action unknown | Related24required,delayE,bank13/14/15motions,300/700distance-scaledA8velocity,frame/heightdescriptor19gate,relatedadmissionthenaction2/3orlanding. |
| [o2 0x657C50](../recomp/config/output_ovl/o2/o2_00657C50_0x657c50.cpp) | `update_related_curved_xyz_flight_turn_and_contact_landing_candidate` | High complete mechanics; original action unknown | Related24required;extendsentrydelaybymotionduration,15.625*clockfactorforwardvelocity,verticalaccelerationandnormalrotationwhileCpositive,cardinalroomtargetyawstepping;sharedcontact/landinggates. |
| [o2 0x658110](../recomp/config/output_ovl/o2/o2_00658110_0x658110.cpp) | `update_related_signal62_contact_hold_signal63_and_timed_release_motion_candidate` | High complete mechanics; original action unknown | Related24required;initialoffset,bank16/17/18contact,partner62/63signals,exacthealth1route,60/100clock-factorholdtimers,ending15motionandselfhealth-dependentexit. Completephasecontractbelow. |

Notation g=unsignedbyte74F200 (nodivisorzeroguard);Motion(k)=65D410(actor,k),whose[bank/statemutationcontract](SYMBOLS_ACTOR_655D40_BASE_STATES_AND_MOTION_TRANSITIONS.md)isretained;Tick=58C300(actor,1),completionpredicatesusesignedlow8. Related=word24checkedonlyatentry. Neitherfirsttwobodyvalidatesrelatedagainthroughphases. Unknownphasesreturn.

## 6578B0 completephases

- A0: A1,Motion13,activate58C7B0,clearB1E,C=0.
- A1:predecrement signedE. NewE>=0ticksandreturns. Negative:A2,Motion14;zeroXYZV;V.Z=(float712610[B]/32)*float(g),rotateVbyunsignedyaw92*2pi/65536,copytoA8/AC/B0. B0setsC40=1.5,otherBsets1.0. **NoTickoractivationafterthistransition**. Bindexesonlyanownedtwofloatprefixwithoutlocalbound.
- A2:BA5=1;positionX+=A8,Z+=B0;noYintegrationhere. Visibility/descriptor/contactpolicybelow. TickpositiveincrementsAandOR115bit1.
- A3:A4,Y=D28,Motion15;noactivation.
- A4:Tickpositivecalls65A2B0baseentry.

Phase2descriptorpolicy:ifC==0 andframe1E4<16 and(Y-170)>owned135.7,clear115bit1,5DA2C0(actor,19,1),C=1. Otherwiseifframe>16 and(Y-170)<135.7,OR115bit1. Originalstrictboundariesarepreserved;frame==16doesneither. IfB1E==1,5AA0C0(actor)admissioncanupdate24/C26;successstoreslowbyte65F410(actor,updated24,0)inB1Fand65A9E0(actor,2,3),returnswithoutTick. FailedadmissioncanitselfclearB1E. OtherpathsTickasabove.

## 657C50 completephases

- A0:A1,Motion13,activate,clearB1E,C=0;E+=signedlow16(signedlow16(CVT.W.S(track1EC))/g),withhalfwrap. Negative/authoredmotionlengthandgcallerconstraintsarenotnormalized.
- A1:predecrementE. Negative:A2,Motion14,C=22/g;zeroV,V.Z=15.625*g,rotatebyyawandcopyA8XYZ;D0=float(g). Whethertransitionedorstillwaiting,Tickinthissamecall.
- A2:BA5=1,positionXYZ+=A8XYZ. PredecrementC. IfnewC>0:setC82=1,AC-=D0,D04+=owned.2,normalizeD00XYZwith191D80,5A82A0(D18,D00,1). TargetQ=position+(0,-100,0);targetyaw=65DA50(actor,Q),step=634B20(signed16(targetyaw-ownyaw),signedBDA),addyaw. IfnewC==0:AC=0,BA3=0,C40=(Y-D28)/174. NegativeCskipsthesetwobranches.
- Thenexactlythesameframe/heightdescriptor/contactadmissionpolicyas6578B0,butdescriptorattachmentonlywhenC==0afterthecountdown. Descriptor19setsC=1,whichinteractswiththefollowingcall'spredecrementasoriginal. TickpositiveincrementsAandOR115bit1.
- A3:A4,Y=D28,Motion15;noactivation.
- A4:Tickpositive65A2B0.

[Room/yawhelper](SYMBOLS_ACTOR_SCENE_ONE_ROOM12_PROBES_AND_ALIGNMENT.md)establishes65DA50'sspecificroom/cardinalcontract;thisfunctiondoesnotperformgeneralpathfinding. [Relatedadmission](SYMBOLS_ACTOR_5AA160_PRIMARY_ONE.md)establishes5AA0C0and5AA110flags,notnearest-targetsearch.

## 658110 completephasecontract

Nonnullrelatedrequiredbeforeset54A ORC. A>=Creturns. Ownedtable740230mapsA0->658160,1->658210,2->658280,3->6583F8,4->658444,5->658488,6/7/8/9->return658510,A->6584B0,B->6584C8.

| A | Fullbody |
| --- | --- |
|0|BA5=1,A1,BA3=0;Motion16ifB1F0else17;C82=1. Rotateowned712628by**ownyaw**andsetownXYZ=relatedXYZ+rotatedoffset. Noactivationcall.|
|1|BA5=1,Tick. PositiveA++,copyrelatedXYZdirectly,Motion18,activate,E=1,relatedB1E=62.|
|2|5AA110(actor) low-signedbytezero:A++,relatedB1E63,C=60/g,return. Else relatedhealth544==1:A5,C40=0,Motion1A,return. ElseownB1E5:A4,C=100/g,return. ElseownB1E4orrelated54F!=B0:A3,C=60/g,return. OtherwiseTick;resultexact2predecrementsE;newE<=0 incrementsA,sendsrelated63,C=60/g. Positiveotherthan2doesnotadvance.|
|3|PredecrementC;negativeA5,C40=156.0,Motion1A. Tickalwaysafterwardinthesamecall.|
|4|PredecrementC;negativeA5,Motion1B. Tickalwaysafterwardinthesamecall.|
|5|TickpositiveA=A.|
|6/7/8/9|Noadditionalbody.|
|A|A=B,Motion15,noactivation.|
|B|Tickpositive:selfhealth>0calls65A2B0;else65A9E0(actor,4,0).|

Originalsignalsarebytewritesratherthanacknowledgedqueues;nodispatchloopwaitsforanotheractorinonecall. Health==1inphase2isnot<=1. Phase1'srelated62andphase2's63areseparatefromtheselfB1Esignal4/5tests.

Owned712610[8] floats300,700,SHA-256 `e697a6aa1e62d60baa87c2dd17f45fffc88c58a04a7fd5fb9e085184bd122e2e`;712618[12]=(0,-100,0),SHA-256 `553a99ba38959fb15635005537467fdb04d6906bc901e95e1ac7520e18f893a2`;712628[12]=(0,86.5,-7.300000190734863),SHA-256 `0b4363197e652a90eb09b39b63e58f8d6fec5d250d0c7191580c5be3c996fea8`;740230[48] jumpentriesabove,SHA-256 `9ae161b9fbd2c506a26ecf37f713ed42b59ab972eaf37a41b6ed21f7f0d41dc1`.740328[4] binary32(135.6999969482422),bytes33b30743,SHA-256 `6529ad98be426d0e1deec2f8fbdcafc5764322b67cb3188d0f76ba1cf552a781`;740320[4] binary32(.20000000298023224),bytescdcc4c3e,SHA-256 `5d96a77c55b4ac1eea2d77815396c4349292b85e3b07beaca6aff933e7ef8752`.

No originalactor/actionname,globalupdatefrequency,flightdurationinsecondsorperformancecostwasestablished. Thesestaticcontractsarenotframeratefixes.
