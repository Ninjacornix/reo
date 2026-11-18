# Support transition and three-segment refinement65B8B0

Static File #1 US owned o2 analysis, 2026-11-05. Entire65B8B0..65C1FB reviewed in two contiguous instruction slices, every branch/delay slot and exit included. [Identity](FUNCTION_INDEX.md). No runtimeaccess,buildorperformanceclaim. Addresses,offsets,flags,statesandanglebandshexadecimal;scalarsdecimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x65B8B0](../recomp/config/output_ovl/o2/o2_0065B8B0_0x65b8b0.cpp) | `refine_actor_support_transition_with_height_gate_three_segments_and_normal_rotation_candidate` | High complete mechanics; original surface/action names unknown | C39/positiveC0gate;candidateheight/D28earlyalignment;threeorderedsegmentcontactsselectnormalrefresh/forward/reversealignment;missrestorespreviousposeandstate4;sharednormalquaternionyawcommit. Fullnumericcontractbelow. |

Notation: currentpositionX=actor38XYZ,previousX=44XYZ,D=actorC0XYZ,oldnormalN=actorD00XYZ. R=101*BC,L=191CC0(D),scaledD=D*(R/L). Initializea12-bytezerovectorZ. C39==1 ororderedL<=0returns;unlike65B560,noseparateC37gateexists. P=D+((X+N)+scaledD),preservingthecomponentadditionorder. ThisincludesunscaledD,notjustnormalizedforwarddistance.

SaveState()copies8/9toBE8/BE9,520toD2C,secondary9toB. Commit()calls65B460(actor);its[local/worlddeltaandmatrixcontract](SYMBOLS_SHARED_BODIES.md)isretained. Bandresponsescallthe[reviewedlateralhelpers](SYMBOLS_ACTOR_FORWARD_PITCH_VISIBILITY_TIMER_AND_LATERAL_PROBES.md)andcanperformtheirownstatechangebeforeearlyreturn.

## CandidateheightbelowD28

IfP.Y<D28:firstSaveState(),setsecondary9=F,A=2,thenB=signedlow16376E70(Z,N),delta=signed16(B-ownyaw). Thesestatewritesprecedeangleadmissionandarenotrolledbackonfallthrough.

- delta[-1000,1000]:yaw=B,Y=D28+R,Commit(),C36=7,return.
- delta[-2FFF,-1001]:65CCF0(actor,B,0)nonzeroreturns. Zero:A+=A(hex10),yaw=B+2000,R/=owned1.4,Y=D28+R,Commit(),C36=7,return.
- delta[1001,2FFF]:same65CCF0mode1;onzeroA+=14(hex20),yaw=B-2000,R/=1.4,Y=D28+R,Commit(),C36=7,return.
- OtherdeltasfallthroughtothreequerieswithsecondaryF/A2alreadystored. NoX/Zwriteontheearlyheightalignmentpaths.

## Threeorderedsegments

BuildB=P-20*N,F=previousX+N,E=F-20*N. Trace(a,b)means5795E0(a,b,outpointH,outnormalV,FFFFFFFF,0,&type),acceptedonlywhennonzeroandboth typebits1and100000set. Anyrejectedcontactcontinues,nextqueryoverwritesoutputs. Ordering:

1. Trace(F,P):acceptedSaveState(),secondaryF,A0,caseK=2.
2. OtherwiseTrace(P,B):acceptedK=1,withoutSaveStateornewsecondary/Aassignmenthere.
3. OtherwiseTrace(B,E):acceptedSaveState(),secondaryF,A1,K=3.
4. Noacceptedtrace:restorecurrentXYZ=previousXYZ;6367C0clearsroutescores/C30;65D1F0attemptssupportsnap;65A9E0(actor,1,4);return. [Routeclear](SYMBOLS_ACTOR_ROUTE_SCORE_UTILITIES.md)and[sharedsupportsnap](SYMBOLS_SHARED_BODIES.md)establishthoseeffects;thisisnotanatomicrollback.

Case1:actorD0CXYZ=H-scaledD via370570;actorD00XYZ=V;5A82A0(actorD18,V,signedbyteBA3),return. Noposition/yawcommit,C36writeoractionassignmentinthisbranchbeyondanyearlierheightbranchwrites. [Quaternionbuilders](SYMBOLS_ACTOR_MODEL_STATE_HELPERS.md)establish5A82A0'smode1/2up-alignment,identityforothermodes.

## Case2: forward contactnormalalignment

B=signedlow16376E70(V,Z),delta=signed16(B-ownyaw). RetainoriginalVcopyW. Modify**X/Zonly**;Yretainspriorvalue:

- [-1000,1000]:yaw=B;X/Z=H.X/Z+W.X/Z*R.
- [-3FFF,-1001]:65CE60(actor,B,0,V)nonzeroreturns. Zero:A+=A,yaw=B+2000,R/=1.4;X/Z=H.X/Z+W.X/Z*R.
- [1001,3FFF]:65CE60(actor,B,1,V)nonzeroreturns. Zero:A+=14,yaw=B-2000,R/=1.4;sameX/Zformula.
- Otherdeltasperformnoneofthesewritesbutstillreachcommoncommitbelow.

## Case3: reverse contactnormalalignment

B=signedlow16376E70(Z,V),delta=signed16(B-ownyaw);replaceRwith96*BC. Acceptedbandsare[-1000,1000],[-3FFF,-1001],[1001,3FFF]. Straightsetsyaw=B. Negativecalls65CE60(actor,B,2,V);zeroreturnincrementsAbyA,setsyaw=B+2000,dividesRby1.4. Positiveusesmode3,A+=14,yaw=B-2000,R/=1.4. Nonzerohelperreturnsearlyexit. ForadmittedbandsX/Z=`H.X/Z - (Bpoint.X/Z-P.X/Z) - V.X/Z*R`,whereBpointistheearlierpointP-20*N;thisretainsoriginalSUBA/MSUBordering. Yunchanged. OtherdeltasstillreachcommoncommitwithoutX/Zwrite.

## Commoncommitaftercases2/3

Commit();5A8220(oldactorD00,V,outquaternionQ);192250(Q,outmatrixM). IfM.float20==exact1,replacewithowned.99999before192110(M.float20). Convertresultanglewith`CVT.W.S(.5+65536*result/binary32(2pi))`,signedlow16;addyaw92withhalfwrap. ThenactorD0CXYZ=H,D00XYZ=V,C36=7. ThequaternionusesactorD00afterCommit,butbeforethefinalnormaloverwrite. Noangleclampforequalityotherthanexact1;zero/oppositedirectionadmissionisinheritedfromthequaternionhelper. Commitprecedesfinalcontactandnormalwrites.

Owned7402F0[4]=`3333b33f`,binary32(1.399999976158142),SHA-256 `55bcbd6097be4e6dbb2e3a87d63d96cb17ed13c4483b7f9a79c7cb115111b3ce`.7402E8[4]=`58ff7f3f`,binary32(.9999899864196777),SHA-256 `123d8636a1f1848411e11f66b7e116d6761284b6ac6af1931a65d408da893c5d`.740330binary32(2pi)identityisrecordedwiththe[lateralprobes](SYMBOLS_ACTOR_FORWARD_PITCH_VISIBILITY_TIMER_AND_LATERAL_PROBES.md).

Thiscontractpreservesthreequeryordering,earlystatewritesandfailedcontacteffects. Itdoesnotmeasurequerycost,confirmwhichsurface/gameactionusesit,orestablishaslowdownfix.
