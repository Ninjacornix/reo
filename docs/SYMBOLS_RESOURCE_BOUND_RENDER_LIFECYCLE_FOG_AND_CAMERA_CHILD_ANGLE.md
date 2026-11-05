# Resource-bound render lifecycle, fog transition and camera child angles

Static File #1 US owned o2 review, 2026-11-05. Full654720..654D37,654D90..65523B and655240..65544B read, everybranch/delay slot, twoseven-waytablesandexitincluded. [Identity](FUNCTION_INDEX.md). No runtime/build/measurement. Addresses/states/maskshexadecimal;floatvalues/timersdecimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x654720](../recomp/config/output_ovl/o2/o2_00654720_0x654720.cpp) | `update_resource_bound_render_work_parent_identity_child_sampling_and_fade_lifecycle_candidate` | High complete mechanics; original effect name unknown | Parent24resourceinstance/ownerbinding,modes0..6,timerE-=2,childsamplingand1FFexpirytable,ownerstatewaitandbounded30-stepstrengthfade. Fullbranchcontractbelow. |
| [o2 0x654D90](../recomp/config/output_ovl/o2/o2_00654D90_0x654d90.cpp) | `animate_scene_fog_distance_and_rgb_flash_then_restore_selected_fog_candidate` | High complete mechanics; sceneeffectnameunknown | Scene324010/14distanceglobalsand3240D0..D3colors;delay/ten-stepramp/90-steprestore,externalchangebaselinecapture,selectedfogcacheinvalidation/refreshandrecycle. |
| [o2 0x655240](../recomp/config/output_ovl/o2/o2_00655240_0x655240.cpp) | `sample_render_children_and_offset_child_roll_by_camera_direction_angle_candidate` | High complete admittedpath; degenerateangleunknown | LifetimeE-=2;camera3240E0forwardprojectionversuscachedlocaldirection,dot/lengthanglefoldand5/9scaling;samplechildthenaddsignedangletochild34. Zero-lengthproductusesuninitializedincomingregisterangle,explicitlyunresolved. |

## Resource-bound654720

P=wordwork24,requiredwithoutnullcheck. ResourceID=P.byte240;ownerhalf=wordhalf3C5658+60decimal*ID. Onlyowner1..4resolvesO=4A5C30+10E0*(owner-1);otherownersO=null. Saveunsignedwork234asidentityI. Mainunsignedbyte8>=7returns. IdentityvalidmeansP.byte0nonzero,P.half36==I,work.byte5==P.byte240. Release()=652D60(work)children,then651D00(work)recycle;[childsample/releasecontracts](SYMBOLS_CUTSCENE_RESOURCES.md)apply.

| Mode8 | Completebehavior |
| --- | --- |
|0|Copy44XYZto38XYZ;5=P240;clear9/A/B. Flag23Cbit8:hiderender1=0,setmode4,return. Elsemode1,23E=(23C&20)|6;bit4storesOto2C;**fallthroughmode1**.|
|1|IdentityinvalidRelease(). Valid:render1=P.byte1;scaleB4XYZ=P22CXYZ. Flagbit4withOnullsetsmode2andreturns. Bit4+10withO.action2/Bhidesandsetsmode4. Bit4+8withOoutside2/BsetsE0,half12=1. Thenplacement/emissionbelow.|
|2|Release().|
|3|Noadditionalbody.|
|4|Onull->mode2. O.action2/B:ifown9==0andflag23Cbit8set,mode5,C=8;otherwisewait. Ooutside2/B:9=0;flag23Cbit10setsmode1,otherwisewait.|
|5|PredecrementC,newnonnegativewait. Negative:mode1,clearA/B,C0. IfI==75andOnonnull,RNG1lowbitchooses1B8C70(O,14whenbit1else15). Noextrareleaseorplacementthiscall.|
|6|If9==0,waitonlywhileidentityvalidandrenderbyte1nonzero. Otherwise9=1,F0=214/30,andreturn. Existing9!=0:214-=F0;negativeRelease(),else654180(work,-F0).|

Mode1 placement:ifA==0,identitymatrix50;23Cbit1clearcopiesP1C0via191530into50. Transformwork38XYZbyP1C0with1919D0into44XYZ,thenaddP200XYZ. Flag23Cbit2setsA1,soplacementfreezesafterfirstsample. If(23C&44)==44andB0:setB1,6B2680(O,44XYZ),once.

ThenE-=2. Nonnegativecontinueschildsampling. Negative:E=half240,half10=0,dispatchsignedbyte1FFthrough7401B0whenunsignedindex<7;invalidindexusesterminalcase1. Exactexpiryactions:

| 1FF | Action |
| --- | --- |
|0|Continuechildsampling.|
|1/default|Hide,setmode2,return.|
|2|Setmode3,return.|
|3|Hide,setmode4,9=1,return.|
|4|9=1,continuechildsampling.|
|5|Hide,setmode5,C=RNG1&3F;if23Cbit80setdrawRNG1againandstoreroll94lowhalf;return.|
|6|Setmode6,clear9/A,return.|

Childsampling:ifP.word23Cbit100set,work23EOR100andA8=signedP238/255;elsework23Eclear100. Iteratei=0..<unsignedwork31:652880(work,word134+4*i,signedhalf114+2*i,signed23E)->byteF4+i. Nochildnullguardherebeyondcallee;half10+=2afterloop. Parent/O/resource/indexlifetimeandcountboundsremaincallercontracts. Mode6uses[654180'sclampedper-childscalarupdate](SYMBOLS_EFFECT_CURVE_TIMING_VARIANTS_AND_SCALAR_FADE.md).

Owned7401D0[28]mainmodes{6547C4,65483C,654B5C,654D20,654B78,654BFC,654C6C},SHA-256 `2aa49ddaa62e2ab1a6b3ca910c1f3120a254133796cafac06eb8fb986cdcf622`;7401B0[28]expiry{654AA8,654A10,654A20,654A2C,654A44,654A50,654A94},SHA-256 `0c844890d8220c6b75117416014cb0e441ee178299ae33cf7eb8801e421f839c`;alltargetsbodiesreviewed.

## Fogtransition654D90

LetN/F=scene324010/324014,andRGB/A=3240D0..D3. Prelude:ifworkA8!=N orAC!=F byoriginalordered equality,orstate8==0,saveN/Fto44/48. Thusconcurrentexternalchangesrefreshtherestorebaseline;ownlastvaluesarecopiedtoA8/ACatcommonexit.

- State0:render1=0,state1,C0,E10,half10=5;velocitiesC0/C4/C8=(6,6,4),accumulatorsCC/D0/D4=0,globalRGBA=0;commonexit.
- State1:predecrementhalf10;negativeentersstate2,butdoesnotperformrampuntilnextcall.
- StateA:state2,C0,E10,velocities(6,6,4),**doesnotclearaccumulators**,fallsintorampthiscall.
- State2:oldCtested<10whileC++isalwaysstored. OldC<10:accumulators+=velocities;capCC/D0at60,D4at40usingoriginalorderedcomparisons;CVT.W.SlowbyteswriteRGB. ComputeD8=(-10000-N)/oldE,DC=(10000-F)/oldE,thenE--;addtoN/F;clampNnotbelow-10000,Fnotabove10000. NozeroEguard. OldC>=10:state3,C90,E0,velocities(binary32two-thirds,two-thirds,four-ninths);commonexit.
- State3:predecrementC. Negative:oldselectedfogID=unsignedbyte3240BD,write3240BD=FF,6B2200(oldID),clearRGB,651D00(work),returnwithoutA8/ACsync. Nonnegative:accumulators=C*velocities,CVT.W.SlowbyteswriteRGB;negative**signedbytes**clamp0. N+=(saved44-N)/(C+1),F+=(saved48-F)/(C+1);clampNnotabove44,Fnotbelow48;commonexit.
- Otherstates:onlyprelude/commonA8=N,AC=Fsync.

[Fogapply](SYMBOLS_LIG_FOG_CONSUMERS_AND_WORK.md)establishes6B2200'sselected-recordrestoreandcachecontract. Noautomaticgameplaypause,rendererpathswitchortimestepnormalizationinthisbody.

Owned740208[4]=`abaa2a3f`,binary32(.6666666865348816),SHA-256 `aeb82ac4087106d84b7036e0988d977b3599ed88aedeb897e09c0c31738ba904`;740200[4]=`398ee33e`,binary32(.4444444477558136),SHA-256 `5385961e762659bbdab1718a7eb53e8999d4b427af9d567b51de792dbd6b1719`.

## Camera-anglechildsampling655240

Copyowned7124D0=(0,0,1)toV. State8==0:state1,byte3=33,render1=1,C8=1;191A40(actorC0XYZ,work50),thenC4=0. **C0/C4werenotlocallyzeroedbeforethistransform**;theinputisexistingC0/C4plusnewC8=1. Thisisnotunconditionallyaninitializedunitforward.

AlwaysE-=2;negativeRelease(). Otherwise191A40(V,globalcamera3240E0),zeroV.Y. Product=191CC0(workC0XYZ)*191CC0(V). Nonzeroproduct:dot191DF0(V,C0)/product->192100;angle=low16CVT.W.S(.5+65536*result/binary32(2pi)). ZeroProductjumpspastangleassignmentandusesincomingcallee-savedregisters0asangle;nohonestfallbackanglecanbeclaimed. Ifsignedangle>4000,angle=8000-angle. signedlow16(5*angle/9)->K.

Iteratei<work31:child=word134+4*i,selector=signedhalf114+2*i;6526F0(work,child,selector)->byteF4+i. NonzerolowbyteaddsKtochildsignedhalf34;zeroleavesangleunchanged. half10+=2afterloop. Calleenullguarddoesnotvalidatethelaterchildwritebeyonditsnonzeroresult. Cameranulls/count/indexinvariantsarenotcheckedlocally.

Owned7124D0[12]=`00000000000000000000803f`,SHA-256 `caccb9a8fbd2401135207066c4b53d6e88467839318ea2f1e8bfadf8fef6844e`;7401F8[4]=`db0fc940`,binary32(2pi),SHA-256 `12d85026b5109a3119231704608d5991a63d8d397d2867a9fc522305810ddb76`.

Thesecompletecontractsretainunresolveddegenerateinputsandoriginalcallbacks. Noeffectexecution,camerabug,framecostorfixwasobserved.
