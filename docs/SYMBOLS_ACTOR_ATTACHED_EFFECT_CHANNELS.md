# Actor-attached effect channels, joint parts and secondary bursts

Static File #1 US, 2026-11-04. Ten complete original o2 bodies plus owned dispatch/policy/joint tables. Hexadecimal addresses/fields/masks; stated counts and float values decimal. High mechanics confidence, semantic roles candidates. No execution, builds, attachment, input or performance measurements. Original actor/scenario names remain unrecovered.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x571EC0](../recomp/config/output_ovl/o2/o2_00571EC0_0x571ec0.cpp) | `create_actor_owned_effect_channel_from_mode_variant_pair_candidate` | High mechanics; role probable | a0owner,a1optionalbasis,a2XYZ,a3mode,t0variant/highflag. Low31variant plusmode indexes8 physical byte pairs708580;652390(resource),652E20(channel),590760 obtains pieces. Setscallback572030,queue373070,mode4=a3,byte5=highbit,C=low16variant,baseXYZ,optional copiedbasis,owner24,flags1A193,652470. No pair/index validation. |
| [o2 0x572030](../recomp/config/output_ovl/o2/o2_00572030_0x572030.cpp) | `tick_actor_owned_effect_channel_parent_state_latch_and_five_tick_mirror_spawn_candidate` | High mechanics; role probable | Phase0 init1/visible,resourceptr,timer12=5,latch1E0=0. Parent24 leavingaction8/9=2/2 latches1. Ordinarybyte5==0 fades visibility withE,terminateswhenlatched,otherwise every5ticks advancesCmod4,rebindspose572290 andcreateshighbitclone571EC0. Highbyte5variant expiresbyE. Pieceupdates6526F0,10+=2;phase2 releases resources/pool. |
| [o2 0x572290](../recomp/config/output_ovl/o2/o2_00572290_0x572290.cpp) | `bind_effect_pose_to_actor_equipment_instance_offset_and_quarter_turn_basis_candidate` | High mechanics; role probable | Owner24 suppliesbyteC7C instanceindex,halfCA8 metadataindex. Instance=word(3C564C+3C*index),basisinstance1C0;offsetfloat metadata719A60+44*ID+38 transformedtheninstance200XYZadded. Localidentity rotated+pi/2Y,-pi/2X,composedwithinstancebasis,copiedwork50;worldbase44=calculatedXYZ. No null/indexguard. |
| [o2 0x5723A0](../recomp/config/output_ovl/o2/o2_005723A0_0x5723a0.cpp) | `create_scenario_one_c_actor_type_one_b_joint_effect_set_and_emitter_candidate` | High mechanics; role probable | Current3243DA==1C,nonnullactorbyte3==1B;incrementsactorD33. Onlyclass0or2continue;class2BBA==8 selects27 joint rows,otherwise25. TriesB9 emitter572A20,then eachrowallocatesresource,jointbasis/offset,callback572690,owner24/2C. Allocationmissesskiprows,notretry. Repeatedcallguard notlocal;D33 increment occursbeforeclassfilter. |
| [o2 0x5725A0](../recomp/config/output_ovl/o2/o2_005725A0_0x5725a0.cpp) | `emit_three_to_six_parent_height_ground_particles_candidate` | High mechanics; role probable | a0actor,a1XYZ;RNG&3+3attempts6525D0(B9,callback572D10). Success typeB/mode80/variant5=3,visibility0,floorE8=actorY+5,C=RNG&7,owner24. Allocationmissescontinue. Doesnotuse jointselectiontable or setowner2C. |
| [o2 0x572690](../recomp/config/output_ovl/o2/o2_00572690_0x572690.cpp) | `tick_joint_bound_effect_looping_piece_program_and_owner_room_lifetime_candidate` | High mechanics; role probable | Owner24 null/offcurrentroom forcesphase2;nonnulloffroom alsoD33=0. Three-arm708740:phase0 visible1/phase1,internalupdatecopies64byteboundmatrix1F0 to50,transformsD8offsetinto44;ifE<0reload240/reset10. Eachpiece5727D0 yieldsF4;E-=2,10+=2. Phase2alreadyknown5729F0releasealias. |
| [o2 0x5727D0](../recomp/config/output_ovl/o2/o2_005727D0_0x5727d0.cpp) | `apply_joint_effect_piece_program_rgb_transform_and_optional_camera_offset_candidate` | High mechanics; role probable | a0work,a1piece,a2selector. Nullpiece/selector0returns0. Program5903E0/590790/5909E0 yieldslocalXYZ/angles/scale. Optionalbasis1F0 transformsXYZ,addbase44,pieceRGB=work208/20C/210. Mode4high80 addswork94toangleZ;otherwisetemporarilyaddsmatrixtranslation80XYZ,652CE0(...,20),subtractsagain. Writesangles30..36/scales38..40,returns1. NoGPUsubmission. |
| [o2 0x572A20](../recomp/config/output_ovl/o2/o2_00572A20_0x572a20.cpp) | `tick_owner_effect_flags_for_periodic_single_and_six_or_ten_joint_bursts_candidate` | High mechanics; role probable | Null/offroomowner24clearsnonnullD33,releasesresources/pool. C37bit1timerexpiryspawns572BB0(mode0),reload15..30decimal. Bit2elsebit4spawns6 mode1 workers(normal/highselector);bit8elsebit10spawns10 mode2. Bitsnotclearedhere. Atmost17 helpercallsperinvocation when allgroupsadmitted,notmeasuredfrequency. |
| [o2 0x572BB0](../recomp/config/output_ovl/o2/o2_00572BB0_0x572bb0.cpp) | `spawn_random_policy_joint_particle_with_mode_delay_and_parent_floor_candidate` | High mechanics; role probable | a0actor,a1mode,a2highflag. Threepointerpolicy708780[low8mode],RNG&F selectsjointbyte;high80adds5. B9worker572D10 success:typeB/mode80,variant5=low8mode,visibility0,flooractorY+5,joint32,delayC=RNG&F+signed708790[mode],owner24/2C,randomhalf9C. Returnswork/null. Low7selectorbitsarenotusedforjointselection. |
| [o2 0x572D10](../recomp/config/output_ovl/o2/o2_00572D10_0x572d10.cpp) | `dispatch_randomized_joint_or_base_particle_into_local_motion_floor_update_candidate` | High mechanics; role probable | Three-arm708798. Phase0init1/visible;random even frameoffset(RNG&E)<signed240 else0 adjustsE/10. Variant5==3jittersbase44by[-7,8];othersparentjointmatrix820[32]by[-15,16]. Initializesyaw,gravity-.98,variantvelocityranges,fade. Callsalreadyreviewed5730C0sameinvocation;phase1sameupdate,phase2existing5731F0release. No localwaitonpreviouslyassignedC. |

571EC0 byte-pair address=708580+2*(fullmode+(t0&7FFFFFFF));firstbyte resource,secondchannel. Fullmode storedlow8work4;variant highbitstoredBooleanwork5. Dynamicprogramfield1F4 derives allocation/resource helper,notexplicitlyassignedhere.590760 writes two words onstack used652470(work,word0,word1,byte7123A0[resource]). Parent24 is actor;optionalbasis copies64bytes to50 and1F0pointsatcopy,else1F0=0. No promisedBoolean return.

572030 phase1 first checksparentstateandlatches1E0 foreveronce not2/2;it doesnotrequireparentalive/nonnullguard. Byte9 0initializes1,visible1,currentXYZ=base44;otherbyte9besides1skipsupdate. Ordinaryvariantbyte5==0:visible1 decrementsE,negativehides;latchedparententersphase2/byte9=0/hiddenandreturnsbeforepieces. Otherwisepredecrements12,<=0reload5,C++,C>=4resets0,572290(work),571EC0(parent,basis1F0,base44,work4,t0=C|80000000). Clonevariant5nonzero simplyE-- andnegativeenters2/hidden. Activepiecesloopbyte31 with selector114+2i,pointer134+4i;6526F0returnbyteÃƒÂ¢Ã¢â‚¬Â Ã¢â‚¬â„¢F4+i.10+=2. Phase2 calls652D60then651D00;unknownphasesreturn.

5723A0 attempts anemitterresourceB9 regardlessjointallocationoutcomes:visibility0,mode80,typeB,callback572A20,queue373070,owner24,C0. Jointrows0..24ordinary,0..26onlyclass2/BBA8. Eachresource652390(rowhalf0),652E20(resource,0),590760thencallback572690/queue373070,typeB,mode4=rowindex,1F0=actor34->820[rowhalf2],copybasis50,localoffsetD8=rowfloat4/8/C,flags1A193,652470(...,0),owner24/2C=actor. No localrollbackofearliersuccessesafterlaterallocationmisses.

572690 roomguardexecutesbeforeuncheckedphase-tablejump,includingnullownerforcing2. The64-bytecopyuses8iterationscopying8bytes;basisnormalsnotrecomputedhere. LocaloffsetD8 transformedbyexternalbasis1F0 into base44withoutaddingbasistranslationinthat1919D0call;piecehelper'sordinarymodepathappliestranslationtemporarilyaround652CE0. HalfE<0reload240andreset10repeatsanimationindefinitelywhileparentroomadmitted. Piecehelper5727D0 initializeszeroXYZ/unitScale/threeanglehalfwords,5903E0(work,params,half206,selector-1),590790and5909E0. Itcopiesfourhalfwordsangles30..36;fourthlocalhalfhasnoexplicitzeroassignmentbeforecalleeupdates,soinitializationdependshelpercontract. Returned1meansadmittedpieceprocessing,notactualvisibility/drawconfirmation.

572A20 bit1periodiccallusesmode0/high0;bit2sixmode1/high0 takespriorityoverbit4sixmode1/high80. Bit8tenmode2/high0takespriorityoverbit10tenmode2/high80. RNGpolicyselectionsareindependent,so six/tenattemptscanpickrepeatedjoints;loopcounterlow7 passedtoa2isdiscardedby572BB0excepthighbit. Maximumlocalhelperattempts1+6+10=17;eachhelperhasoneallocationattempt. SavedCcountsdownonlywhenC37bit1set. No channelbitsclear,wallclockunit,emitterupdatefrequencyoractiveownerboundproven.

572D10 phase0 byte5!=3 getsjointtranslationfromword(actor34+820+4*joint32)andindependentintegerjitter[-15,16]eachXYZ;variant3usesbase44and[-7,8]. Randomyaw234,randomhalf94,CC/D4/C0=0,D0=-.98. Variantvelocity(C4,C8):0=(RNG&3,(RNG&3)/10),1=(1+(RNG&3),(RNG&F)/10),2=(3+(RNG&7),(RNG&1F)/10),3=(3+(RNG&3),(RNG&1F)/10). UnknownvariantsretainpreviousC4/C8aftercommoninit. F0=.05;5730C0integratesmotion/floorand573260updatespieces. Theemitter'sassignedhalfCisnotconsultedinthisphase0dispatcher;itsdownstreamhelpermayuseotherfields. Existing [task flags/effect motion](SYMBOLS_TASK_FLAGS.md) closes5730C0/5731F0/573260withoutnewduplicaterows.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Span | Exact content | SHA256 |
| --- | --- | --- |
|708580..70858F|Eightbytepairshex(13,0),(13,1),(13,2),(A,0),(D,0),(D,1),(D,2),(D,3)|`6241dfb96eff4ef2fc385f9951f1b215f940fcd6cb460f226a29bbef7c289199`|
|708590..70873F|27sixteen-byte(resourcehalf,joint half,XYZfloat)rows;fullrawwordsbelow|`fa23a0a1dc5e9df2fd61c18e990ad0e3a907a0a7efb73c5b87f55ebe00a8c000`|
|708740..70874B|5726E0,5726F0,5729F0jumpwords|`a52d3fe73b7f4cec0c4f09f634f76b2d5a96de1b03ef0c00ee84387bfc7b21e5`|
|708750..70875F|Decimalbytes10,3,11,20,21,7,4,17,14,12,13,18,16,10,11,21|`e6669e90532b21595db06a1e40c299879ccc6c176877e66b0a5697286fc81ea1`|
|708760..70876F|Decimalbytes22,23,24,25,26,25,24,23,22,23,24,25,26,25,24,23|`d75ccff77d942f0e86b867a61e4e0416297de08a39704786d83a5dc2833c6663`|
|708770..70877F|Decimalbytes26,25,26,25,25,26,25,26,26,25,26,25,25,26,25,26|`730cd28843f60e04778ed8f44db8bd2b6230e98e885da0654c2fa8777bd4398d`|
|708780..70878B|708750,708760,708770datapointers|`1d6b0fc4ee5201e5f0d6d35f6d4d48858dce1c81c572b42845aec47b07fd353e`|
|708790..708793|Signedbytes0,4,8,0;onlyfirst3usedbyobservedmode0/1/2callers|`adff0cd522b1f4a95483a36943fc7b35b84b3b4a82f8e9223d54434a4c8163a8`|
|708798..7087A3|572D30,5730C0,5731F0jumpwords|`b23fbc4afe8b51ebc8aaa454e95df2da7d83f1fc232f1ca74e490a7fe616e9d6`|
|73DE08..73DE2F|Five8-byte(float,zero)slots:pi/2,-pi/2,.05,-.98,0(singleprecision)|`be6d125834dba81b3824cc5a342bdb22e6414668fc13f7cd72f032dc8897fba9`|

Resource/queuehelpersarein [cutscene resources](SYMBOLS_CUTSCENE_RESOURCES.md),equipmentinstanceposemetadataisalsoseenin [placement resource binding](SYMBOLS_ACTOR_PLACEMENT_RESOURCE_BINDING.md). No original effectnames,sceneidentity,measuredspawnfrequencyorenginefixisclaimed.

27jointrowsrawfourwords;low/highhalvesword0areresource/joint,otherwordsIEEE754XYZbits. Hexadecimalordinals/words.

| Ordinal | Raw words |
| --- | --- |
|0|000A00A0,C01AE148,40F0F5C3,00000000|
|1|000A00A1,C166147B,BE6147AE,00000000|
|2|000300A2,410CF5C3,C1207AE1,00000000|
|3|000300A3,C1100000,C1A11EB8,00000000|
|4|000300A4,3FA3D70A,C1C00000,00000000|
|5|000B00A5,410570A4,41635C29,00000000|
|6|000B00A6,C0F66666,416B851F,00000000|
|7|000B00A7,C15D47AE,4132147B,00000000|
|8|001400A8,C0533333,41500000,00000000|
|9|001500A9,408CCCCD,4104F5C3,00000000|
|A|000700AA,BE570A3D,C212F5C3,00000000|
|B|000400AB,3F400000,C1A5999A,00000000|
|C|000A00AC,4191999A,40C66666,00000000|
|D|000300AD,00000000,00000000,00000000|
|E|001100AE,412EE148,BECCCCCD,00000000|
|F|001100AF,C19ACCCD,BF23D70A,00000000|
|10|001200B0,C086B852,BEE147AE,00000000|
|11|000800B1,00000000,00000000,00000000|
|12|000D00B2,41228F5C,3F19999A,00000000|
|13|000E00B3,40B4CCCD,C078F5C3,00000000|
|14|001100B6,C0D0A3D7,C07851EC,00000000|
|15|000C00B7,40A00000,4088F5C3,00000000|
|16|000E00B8,411E6666,400F5C29,00000000|
|17|000500BA,00000000,00000000,00000000|
|18|000B00BB,C0B00000,41400000,00000000|
|19|000E00B4,4174CCCD,3F7851EC,00000000|
|1A|000F00B5,40C33333,BF99999A,00000000|

Owned-word audit:10 rows,1082 distinct instruction words verified,42 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited.
