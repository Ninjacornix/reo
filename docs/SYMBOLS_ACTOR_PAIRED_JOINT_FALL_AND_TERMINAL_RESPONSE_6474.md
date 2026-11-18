# Paired joint placement, falling and terminal response647410

Static File #1 US owned o2 analysis, 2026-11-05. Entire647410..648003 and648010..648B9F reviewed through both full instruction slices, all delay slots, admitted branch bodies and exits. [Identity](FUNCTION_INDEX.md). No game execution, builds, live reads or attachment. Addresses/states/masks/descriptors hexadecimal; floor thresholds and animationframes decimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x647410](../recomp/config/output_ovl/o2/o2_00647410_0x647410.cpp) | `update_paired_joint_placement_health_response_fall_and_terminal_variants_candidate` | High complete mechanics; original action name unknown | PartnerB20=18; six-descriptor bank711510. Opposite-yaw alignment, partnernode86Cplacementminusownnode828offset,6681C0health/gaugeselectors2A/2B,signal63terminalselection,ground/fallreleaseandmode188-dependentmotions. Fullorderedcontractsbelow. |
| [o2 0x648010](../recomp/config/output_ovl/o2/o2_00648010_0x648010.cpp) | `update_paired_joint_fall_variant_with_opposite_cancel_admission_and_partner19_candidate` | High complete mechanics; action naming partial | Full648010..648B9F reviewed separately. Same phase-body architecture with explicit substitutions and different cancellation/reset admission below; not a byte-identity claim. |

Prelude:54AOR1F,32FF,saveincomingA.6673C0nonzeroimmediateidle:54F0,548bit1clear,action1/0/1/0,snapshot667370,2050/start0/blend10,activate58C7B0. NonzeroAresolvesE=42EB00+D90*byte(74F251+60hex*B1D). Fixedpoolpointer'snonzerotestisnotvalidindex/lifetimeproof. Class0/E.C26!=own3 changesA0..3toFF,A4to5;otherphasesretained.63EF30(E)==0orownB1E6changesA0..4to5;higherphasesretained. A>=5clears54Abit1. IfchangedfromincomingA,67E230(actor,1)publishesbeforephasebody.

D[i]=711510+8*(6*B99+i);nomembershiporB99boundlocal. Tickinguses58C300(actor,1),resultpredicates signedlow8. Descriptorselection5D50E0usesstart0andblendshown.

| A | Complete phase body |
| --- | --- |
|0|A1,54FB0,D101,snapshot,clearB22/B1E/B9F.663350(148,149)missingusesimmediateidle. SuccessownB24/B1DlinkandE.B1C/B1E1,B1D=own3,B24=own,B20=18.665FC0(yaw,yaw,E.yaw+8000,elapsed1,duration2),clearownroot4E4XYZ. No motionselectionoractivationyet.|
|1|A2,58C7F0,D0/blend10,wrappedyawinterp towardE+8000(1/2),return.|
|2|Tick;positiveA3. Alwayssamewrappedyawinterpaftertick/advance.|
|3|A4,58C7F0,D1/blend-8,activate,yaw=E+8000. Position=transform-vector7117B0byE.model34->86Cmatrix +thatnode.translation30/34/38 -ownmodel34->828.localoffset70/74/78.6681C0(actor,2A)health/gaugeapplication;noaudiocall.|
|4|Tick;resultexact2applies6681C0(actor,2B). SignalB1E63clearsit,setsA=Aandreturnswithoutplacementupdate. Otherwiseupdatespositionwithsameformulaas3using7117C0.|
|5|A6,58C7F0,D3/blend0,activate. IfEnonnullsetsE.B1E4,ownyaw=E+8000. Doesnotrequireanimationcompletionbeforestartingfallphase.|
|6|Tickfirst,thenfloorpolicybelowusesrootY4E8andcanadvanceA7or14.|
|7|A8;if188==0spawns5DE4C0effect41;58C7F0,D4/blend0,noactivation.|
|8|Tick;positiveaction3/10/0/0,snapshot.|
|A|A=B,health544=0,58C7F0,D2/blend0,yaw=E+8000;noactivationorpartnervalidationlocallybeyondprelude.|
|B|Tickpositive:BA0OR120,5F6800(actor,0),54FA0,action4/8/0/0,snapshot,BA0OR1000,67E230(actor,1),clearroot4E4XYZ. Independentlyafterward,frame1E4not<124clearsrender1,evenwhentickresultnonpositive.|
|14|A15,58C7F0,D5/blend-32,noactivation.|
|15|Iftrackflag1F1bit10,clearroot4E4XYZandsetDC=60/(3243CCzero?32:16). Tick;positiveaction1/4A/0/0,snapshot.|
|FF|Cooldown32=60if3243CCzeroelse30.616F20(XYZ,mask3). Returnedtype3selectsaction1/4A/0/0,snapshot,withoutclearing54F/548orselecting2050. Othertypeusesimmediateidle2050/start0/blend10.|
|other|Preludeonly;returns.|

Phase6 floor policy, after animationtick:

-188==0:616F20(XYZ,FF);threshold=returnedheight-owned.1. IfcurrentY+rootY<threshold: A++,rootY=0,Y=threshold. Querytypeignored.
-188!=0: samequery;returnedtype0or2usesidenticalthresholdgate/A7transition. Other types useupperheight184-220: nextY<thatsetsA14,rootY0,Y=184-220. ThenindependentlyifcurrentY>184ANDcurrentY+rootY<=184,requests1B8D70(actor,2)surfaceaudio. NoordinaryYintegrationhere;caller/rootmotionownsit.

Allordinaryphaseexitsreturnwithoutacommonpartner-offsetcopy. Originaltiming, signedcompletion, initialization-withoutactivationandpreludepublicationorderingare retained;thebodydoesnotproveglobalupdatefrequency.

Owned711510[96] contains12eight-byterecords(two6-recordwindows). Half0/2are60/0exceptD4whichis10/0;half4==half6andIDs{3,4,5,6,1F4,2,35,36,37,38,1F4,34}. SHA-256 `9e582c757887b6cd82f41b8c85be427af25605979c88e68064a7c86d7b95e017`. Packedfieldsarenotrenamedmodel/start/endwithoutdecoderproof.7117B0[12]and7117C0[12]bothbinary32(-1.7,13,1.5),SHA-256 `d2be2a7439186db712b3befc99a3b3ea45ae02150ef7e6ae7b84898677580195`each.740178[4]=.1bytes`cdcccc3d`,SHA-256 `fb360f7241a770dc32cade9a1d1273c92b13bd4959b1c130931312b7fe95e63f`.72F7C8[8]mappingselectors2A/2B=`2a2a00002b2b0000`,SHA-256 `ffdac3753665c3606b3bed2fab2c7fad74800f4bcc9e22c909e3508274c40092`.

[Pairedhealth/gaugeapplication](SYMBOLS_ACTOR_PAIRED_HEALTH_GAUGE_APPLICATION_AND_CONTROL_EVENTS.md), [precedingpairedalignment](SYMBOLS_ACTOR_PAIRED_JOINT_ALIGNMENT_AND_GROUND_RELEASE_6467.md), [yawinterpolation](SYMBOLS_ACTOR_ACTIONS.md), [effect41](SYMBOLS_EFFECT_BURST_CONSTRUCTION.md), [surfaceaudio](SYMBOLS_ACTOR_SOUND_REQUEST_ROUTING.md) and [stateclassification](SYMBOLS_ACTOR_SNAPSHOT_AND_SHARED_CONTROL_HELPERS.md) establishchildren. No pairedactionwasobserved, no audio/healthlossmeasured, and no slowdowncauseorfixwasconfirmed.

##648010 full variant contract

Both full instruction slices were read independently; the following describes the complete relation to the647410 phase table above, including every differing admission and phase operation. Shared phases retain all flags, tick/result tests, node pointers, health/terminal writes, floor predicates, frame124 visibility gate, clock-mode DCwrite, publication order and FF recovery detailed above.

- Reset6673C0nonzero selectsaction1/4A/0/0,snapshot andreturns. It doesnotclear54F/548,select2050oractivate.
- Class0/E.C26mismatchforcesA0..4to5,retaininghigherphases.63EF30(E)==0orB1E6forcesA0..3toFF,A4to5,higherunchanged. These two cancellation policies differ from647410 and from one another. Null computed partner arithmetic still only setsFF before later E.C26/63EF30 accesses; no safe null admission is claimed.
- Phase0partnerlinkusesB20=19. Missing663350partnerselectsaction1/4A/0/0,snapshot andreturns,withalreadyset54F=B0retained. Success still wraps yaw towardpartner+8000 atelapsed1/duration2 andclearsrootXYZ. Phase0doesnotfallthrough.
- D[i]now711570+8*(6*B99+i). Phase1D0blend0 (647410uses10). Phases3/4placementuses7117D0/7117E0respectively;numericvectorsmatchtheotherentrybutidentitiesretained. Health/gauge6681C0selectors2C/2Dreplace2A/2B.
- Remainingphases2,5,6,7,8,A,B,14,15,FFandunknown phasebehavior followthecomplete table/floorpolicyabove without omitted specialcases. No commonpartner-offsetcopyexists.

Owned711570[96] SHA-256 `5fcfa20bef2e8edd687d6ea9edc014771ecd243a5b948889670efc80afce70ea`: samepackedliteralhalfstructure,IDs{7,4,5,6,1F4,2,39,36,37,38,1F4,34}.7117D0[12]and7117E0[12]both(-1.7,13,1.5),SHA-256 `d2be2a7439186db712b3befc99a3b3ea45ae02150ef7e6ae7b84898677580195`each.72F7D0[8]selector2C/2Drecords=`2c2c00002d2d0000`,SHA-256 `3ad8395d823f14a27352d3e394987e0e7e8aa4a3f765122138e08ccf1cec5e7e`. No asset-name or runtime-admission inference is added from their equality.
