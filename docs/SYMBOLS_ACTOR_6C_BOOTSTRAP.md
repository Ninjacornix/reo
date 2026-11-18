# Actor 6C normal update and initialization

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed.
Addresses/offsets/states hex; physical scalars decimal. Identity/original enums
unresolved. No target execution, live data, profiling or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C5690](../recomp/config/output_ovl/o2/o2_006C5690_0x6c5690.cpp) | `update_actor_6c_state_collision_alignment_and_motion_candidate` | High mechanics; probable role | Copies170toD28,XYZto44,rotation90..96toA0..A6;54A10,BA5/C82/32/C360.5A9EF0(actor,24),640210(actor);if13FandA230nonzero then9F70,5A6B20(actor,2). SavesBA3toC29;copiesdefaultshapeintoC70..7Cand1AC..1B8. Health544<=0C94|201else&~201;then&~108. Dispatch730600[unsigned8]. UnlessC82A710transformsrootmotion;elsememsetC0XYZ0.6347D0,5A7D00(actor,7305D0,CD8). NonzeroBA3setsBA5=1. Primary1/secondary1/A!=0 invokesAB70formodes0/2,ADB0mode1. Mode2clampsY<=D2C. Exceptprimary1secondary6/7,mode1clampsYto[D28+50,D2C-50]ordered,thenA900commit. Finally5A6B20(actor,signedC36). Scalar50decimal. |
| [o2 0x6C5980](../recomp/config/output_ovl/o2/o2_006C5980_0x6c5980.cpp) | `initialize_actor_6c_shape_motion_alignment_and_record_restoration_candidate` | High mechanics; probable role | BuildsEuler90/92/94to50,byte1=1,F0=1,C800,520=-1,C2E0,BA50,C94|245,1A80,1D8=owned730700,defaultshape;190=20FFFF,1940,CE8/CFC0. SetsceilingD2Cby scenario/room;616ED0(actor,XYZ,FF),174==1queries616F20for170,D28=170. 55218/5511D,zeroBE8fourbytes,C..13eightbytes,D5A1,BA3fromrecord74F270+60*B98. Variant1forces1/D,A/B0,BA3=3,health544=546andrecord74F26Chalf=546,Y=-2800. Otherbranchesbelow. Normalcompletion9F70,C36=1;C2Bspecialbranchearlyreturns. |
| [o2 0x6C5E00](../recomp/config/output_ovl/o2/o2_006C5E00_0x6c5e00.cpp) | `evaluate_actor_6c_primary_one_policy_then_dispatch_secondary_candidate` | High mechanics; probable role | 635E20(actor,C8C,18,f12=BCC,f13=BD0),then730520[unsigned9](actor). Seventeenownedtargets5E60,5FA0,6080,6120,61F0,64E0,66F0,6870,6AF0,6BB0,6CC0,6D70,70A0,71C0,7340,74D0,78D0. Noindexguard;policyreturnunusedbutsideeffectsretained. |

5980 ceilingD2C:scenario0 orscenario29/room46->decimal400;
scenario29/room3F->600;other->float49F78C. Scenario/roomIDshex.
Otherinitializationbranches in precedence order aftervariant1:

- Health544<=0:8/9=4/0,A=5,B0;formsstackXYZ=actorXYZ+(0,-1000,0),
  butonlywritesactorY=170when174!=FF,else-4000;X/Zunchanged.
- C2Bnonzero:motionbyte755708[C2B]selectedviaA610step0;8=5,9=C2B,A/B0,
  byte1=0,earlyreturnwithout9F70/C36.755708isoutsideownedo2filedata;
  no content or validlength was invented.
- BA3=1/2:queryB6D0(actor,D00,D0C). Nonzeroresultinitializesquaternion;
  mode1XYZ=D0C+D00,yaw=heading(D00,zero),then1/0,A/B0,BA51,motion0step0,
  activate. Mode2keepsposition/yaw. ZeroresultsetsBA3=0thenfallsinto
  ordinarygroundstate;itdoesnotinitializeD00inthatbranch.
- OtherBA3initializesD00=(0,1,0). BA3=0sets1/0,A/B0,motion0step0activate;
  BA3=3sets1/B,A/B0,BA51,motion2step48activate;othermodeskeepstate.

Owneddata:728FC8->730780twoshapepointers730760/730770,thenzeros.
Floatshapes(0,45,0,48)/(0,0,-48,48);updateusesfirst,66F0usessecond.
730750->730700descriptor.730600primarytableelevenentries:
5980,5E00,7B90,8220,8FE0,9460,5AA040fourtimes,9900,thenzero.
730520seventeensecondaryentrieslistedabove,nextwordzero.
No tableboundsprovenfromtrailingzeros;callercontractsretained.

Update5690skipsofcommitforprimary1secondary6/7and50-unitmode1height
marginareexplicitstaticbranches. They do not prove why a playtest lagged.
Related [collision](SYMBOLS_ACTOR_6C_ALIGNMENT_COLLISION.md),
[primaryonehandlers](SYMBOLS_ACTOR_6C_PRIMARY_ONE.md),and
[crossingsequences](SYMBOLS_ACTOR_6C_CROSSING_SEQUENCES.md).
