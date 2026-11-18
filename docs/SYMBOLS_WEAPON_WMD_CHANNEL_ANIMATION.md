# Weapon WMD loading, six-part channel curves and model matrices

Static File #1 US research, 2026-11-04. Four complete original bodies reviewed.
Addresses/offsets/selectors hexadecimal; part/channel countsdecimal.
WMDresourceidentitycomesfromownedfilenameandmainweaponbankcallers. Original
weaponpartnamesremainunknown. No execution, attachment, build, replay or changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6B4420](../recomp/config/output_ovl/o2/o2_006B4420_0x6b4420.cpp) | `select_actor_weapon_wmd_channel_set_and_reset_curve_completion_candidate` | High mechanics; WMD identity verified | ActorbyteC7Cnonzeroresolvespointer3C564C+3C*C7C;nullreturns. Actorbyte2nonzerodisablesworkbyte9andreturns. Otherwisework9=1,base28=749180+800*actor3. a1=0selectsWMDword0/4whenrecordhalf3C5654+3C*C7Cnonzero,elseword20/24;a1=1selects8/C,2selects10/14,others18/1C. PairchoicebyactorB99zero/nonzero. Nullselectedoffsetdisables9;otherwiseclearswork10 and38..3E,24=base+offset. |
| [o2 0x6B45C0](../recomp/config/output_ovl/o2/o2_006B45C0_0x6b45c0.cpp) | `tick_owned_weapon_instance_six_parts_six_wmd_channels_and_matrices_candidate` | High mechanics; partroles unknown | Calls5932F0 visibility/ownerupdate;requiresinstance23Cbit20000. Ownerhalf3C5658+3C*240in1..4withownerBA0bit200copiesdefaultmatricesforcount3DBB14[242],flags30[i]=1. Owneroutside1..4sets9=0. State9=1evaluatessixparts,eachsixchannelsvia6B4A30,buildsrotationfromchannels3..5andtranslation0..2,advancehalf10+=2;allcompletionmasks3Fsets9=0. Fullstate0andcurvecontractsbelow. |
| [o2 0x6B4A30](../recomp/config/output_ovl/o2/o2_006B4A30_0x6b4a30.cpp) | `evaluate_float_time_pairs_linear_and_mark_end_candidate` | High mechanics | a0keys(floatvalue,signedwordtime),a1signedtime,a2signedcount,a3done. Scanfirstkeytime>a1. Firstkeyreturnsfirstvalue;pastendsets*done=1,returnlastvalue. Betweenkeyslinearinterpolation. Count0setsdoneandreads[a0-8];negativecounttakesfirstvaluepath. Caller/assetpositivecountandorderedtimescontractsremainunproved,withoutfaultclaim. Doesnotclear*doneonotherpaths. |
| [o2 0x6B4AE0](../recomp/config/output_ovl/o2/o2_006B4AE0_0x6b4ae0.cpp) | `load_slot_weapon_wmd_into_cleared_2048_byte_buffer_candidate` | High mechanics; filename verified | a0slot,a1weaponselection. Alwayszero800bytesat749180+800*slot. IfactorC7Cat4A68AC+10E0*slotnonzero,formatownedwp%02d.wmd pathwithselection,1CC8F0(path,buffer,1,0). Loadresultignored;noasset-sizevalidationhere. Slotnotlocallybounded. |

WMDmatrixworkdetail: eachparti=0..5usescompletionbyte38+i. Mask3Fskips;
nullpartoffsetsets3F. Nonnullpartchanneldata=base28+partoffset, six pairs of
(channeloffset,keycount), eachmissingoffsetmarksitsbit. Otherchannelscall
6B4A30(base+offset,signedhalf10,count,&done);done marksbit. All six outputfloats
start0eachcall. 1902D0 buildsoutputmatrix40+40*i fromlastthreefloats, copies
defaultmatrix3C9230+180*model242+820+40*i tostack,1900E0extractstranslationto
stack100..108,then190060writesfirstthreechannelfloatsintooutputtranslation.
The extracteddefaulttranslationisnotreadagaininthereviewedbody.

State9=0 clears timer10and38..3E. It thenreadsunsignedownerhalf:nonzeroreturns;
zeroalsoimmediatelyreturnsbecausethen<5. Thuslaterdefaultcopyloop6B477C..47FC
isunreachableunderthoselocaltests. SeparateearlierownerBA0bit200restoreloop
isreachableandhasaninitialcounttest;zero/negativecountskips. No automatic
runtimefault,performanceorintendedcorrectionisclaimed.

Ownedfilename740C90length22:`data/rom/motion/weapon/wp%02d.wmd\0`,SHA256
`038af9f646af8d6e774b4c19b2b5e39dceeef99ad768e515a0359f157946b1e3`.
Callerproof:main1D3A70/1D3B00load/queue`weapon%02d`soundbanksandcall6B4AE0,
documentedin[weaponbankloading](SYMBOLS_ROOM_SECTION_AND_SOUND_LOADING.md).
Animationcrossingconsumer596470calls6B4420withselectors0..3,documentedin
[crossingevents](SYMBOLS_ANIMATION_CROSSING_EVENTS.md).
749180and3C9230aremutableguestwork,notdecodedasownedconstantWMDassets.
6B4B90isanotherreviewedjrra/NOPbody,leftasplaincrossreferenceforcentralaliases.

Full-body owned-word audit: four rows, 443 verified instruction words,
zero conflicts, 24 omitted zero/NOP words, zero omitted nonzero words.
