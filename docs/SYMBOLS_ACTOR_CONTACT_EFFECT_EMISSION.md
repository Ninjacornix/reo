# Actor contact visual effect transform and emission dispatch

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed, with owned dispatch and selection tables. Addresses/offsets/type IDs hexadecimal; explicit iteration counts and physical values decimal. No target execution, attachment, build, replay or engine changes. A construction or allocator call is an attempted effect, not proof of visible output or timing cost.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x634DF0](../recomp/config/output_ovl/o2/o2_00634DF0_0x634df0.cpp) | `rotate_local_xyz_offset_by_actor_euler_angles_candidate` | High mechanics; visual-effect role probable | a0actor,a1inputXYZ,a2outputXYZ. Copiesthreeinputfloatstoscratch;370320(actorhalf90/92/94,basis),1919D0(input,basis),copiesthreeresultfloatstooutput. No translation, normalization, activity/null admission; scratchallowssameinput/output. |
| [o2 0x635010](../recomp/config/output_ovl/o2/o2_00635010_0x635010.cpp) | `construct_actor_contact_visual_effect_transform_and_select_emitter_candidate` | High mechanics; visual-effect role probable | a0actor,a1mode low8. Selectsr=low16random&3,node/signedZpairfromownedtablebyactor13Eandmode;copies64bytesfrommodel34->node820+4*nodeID. Capturesmatrixtranslationaspoint;rotateslocaloffsetvia634DF0andadds. C29=1/2convertsZtoY=2*ZandZ0;otherB1F==2negatesZ. Buildsnewbasis191820fromnegativeactor12CXYZwithYforced0andup(0,1,0). Effecttype starts141withcategory/BBA/13E/140remaps;category1Bpositionadjust5725A0;calls5DCD70(actor,basis,point,type). Full branch contracts below;notacollisionquery. |
| [o2 0x5DCD70](../recomp/config/output_ovl/o2/o2_005DCD70_0x5dcd70.cpp) | `dispatch_actor_contact_effect_type_to_bounded_emission_helpers_candidate` | High mechanics; visual-effect role probable | a0optionalowner,a1matrix,a2XYZ,a3unsignedtype. Type>=Dreturns. Own13-entryjumpdispatchmaps0/9toreturn;1/2/4/5/8/Bdirecteffectallocatorpaths,3->5DD170,6nonnullowner->5DD6F0withowner142,7->5DE540,A->5E0280,Cthreejitteredemissions. Fulltypeallocation/parametercontractsbelow. Failuregenerallyreturnswithoutrollback;novisibleoutputguarantee. |

635010 selected-pair source, ordered exact cases:

| low8 mode | Pair address |
| --- | --- |
| 13 | 72B8E0+8*unsigned13E+2*r |
| 1D | 72B880+8*unsigned13E+2*r |
| 2B andhalfBBA!=0 | 72B8B0+8*unsigned13E+2*r |
| Other,including2B/BBA0 | 72B250+decimal24*mode+8*unsigned13E+2*r |

Pairbyte0isunsignedmodelnodeID,byte1issignedlocalZoffset. LocalX/Ystart0. Mode13dividesthealready-zeroYby2;itdoesnot halve the selectedZvalue. C29=1/2thenY=2*Z,Z=0;otherwiseB1F==2negatesZ. Mode13tableandC29transformarethusseparate. Matrixcopycount8pairsalwayscopies64bytes;later18FDF0resetslocalmatrixbefore191820rebuildsorientation. Savednodeworldpositionisnotlostbythatreset.

635010 effecttype remapping in control order:

- Startunsignedactor141. Ifitwas9andunsignedcategory3!=1,replace3.
- Category3==1: type9->7;type3with13E=0and140=2also->7;otherretained.
- Category6/7/A/12/24: type1or3->8;otherretained.
- Category1B:5725A0(actor,&point),typeretained.
- Category2BwithBBA!=0andtype!=6:13E==4 ->C,elseB.
- Othercategory/typecombinationsretained.5DCD70thenadmitstype< D.

5DCD70 completed dispatch table. M=originala1matrix,P=originala2point; allallocatorpathsuseflags1A193andparametersshown. Selector IDs and effects remain numeric without original visual subtype names.

| Type | Destination / full local work |
| --- | --- |
| 0,9 | Return |
| 1 | 6525C0(M,P,0,0,-1,1A193) |
| 2 | 6525D0(M,P,0,66,0,1A193,callback653E80);nonnullresult half23E=20,floatEC=15 |
| 3 | 5DD170(M,P,0) |
| 4 | 6525C0(M,P,0,84,0,1A193) |
| 5 | 6525D0(M,P,0,78,0,1A193,callback6533C0) |
| 6 | Nullownerreturns;else5DD6F0(owner,M,P,unsignedowner142) |
| 7 | 5DE540 withpreservedowner/M/Parguments;nocounterloopinthisdispatcher |
| 8 | 6525D0(M,P,0,73,0,1A193,callback653E80);nonnulluniformscaleB4/B8/BC=(decimal10+random%6)/10,half23E=24,floatEC=15 |
| A | 5E0280 withpreservedowner/M/Parguments |
| B | 6525C0(M,P,0,2A,-1,1A193) |
| C | Exactly3attempts6525C0(M,jitteredP,0,0,-1,1A193);eachXYZ=Paxis+(randomlow16&1F)-decimal16,independentrandomperaxis |

Owned jump words73EB40..73EB73 inindexorder:5DD054,5DCDB8,5DCDE0,5DCE20,5DCE38,5DCE60,5DCE90,5DCEA8,5DCEB8,5DD054,5DCF48,5DD034,5DCF58.52-byteSHA256 `2f93080a472a563ffc1f612bdc845bb54945ab5046cb61a0f8ad3291b6944b27`.

The635010selectionbytesarefullylistedandhashedin [effect selection tables](SYMBOLS_ACTOR_CONTACT_EFFECT_TABLES.md). Physicalspansmustnotbereadasvalidmode/13Erangeswithoutcalleradmission. Model34andnodepointervalidityalsoarenotcheckedlocally. [Contact response routing](SYMBOLS_ACTOR_TARGET_REGIONS_CONTACT_ROUTING.md) uses72B820callbacks:0->635630(onejrra/NOPbody,checkedasplaincross-reference),1..21->635010. Thuscallbackpreparationisan effect-producingpath beforedamageclassification,notanothercollisionfinder. Classifier6407D0andstoredreference637490areseparatein [damage admission](SYMBOLS_ACTOR_CONTACT_DAMAGE_ADMISSION.md).

No allocator counts outside typeC are multiplied here and no looping-to-zero stall is inferred. Effects attempted by delegated helpers require their own argument/loop admission evidence. In particular earlier5DDF50 underflow/stall hypothesis was disproved by its initial branch skipping the first decrement; nothing in this notebook revives that claim.

Full-body owned-word audit: 3 rows, 567 verified instruction words, zero conflicts, 26 omitted zero/NOP words, zero omitted nonzero words.
