# Authored region planes, work callback selection and kind83 proxy dispatch

Static File #1 US research, 2026-11-04. Five complete original bodies reviewed. Hexadecimal addresses/fields/masks;32region/34policyrecord counts and floatY10 explicit decimal. Mechanics confidence high; semantic roles probable. No execution, builds, live memory, attachment or slowdown claims.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x574010](../recomp/config/output_ovl/o2/o2_00574010_0x574010.cpp) | `test_point_plus_y10_against_six_authored_region_planes_candidate` | High mechanics; role probable | a0 XYZ,a1 region R;null returns0. Converts signedint verticesR4/10/1C/28/34/40/4C/58 tofloat. Sixspecifictriangleplanes via370640 then573FB0(point+Y10,planeVertex,normal);anyinvalidnormalorpositive-dotreturns0,allpass1. Fullfaceorderingbelow; no axis-aligned box/convex authored-data guarantee. |
| [o2 0x574680](../recomp/config/output_ovl/o2/o2_00574680_0x574680.cpp) | `select_highest_priority_containing_region_halfword_or_default_candidate` | High mechanics; role probable | a0 optionalXYZ. Null->unsignedhalf3C3D70. Else32regionrecords3C3000+68*i,requiresbyte0nonzero,byte1bit1set,574010(point,record)==1. Strictprioritybyte0>bestselects,soequalprioritykeepsfirst. Returnselectedrecordhalf2,or3C3D70ifnone. No index/actorstatewrites. |
| [o2 0x574790](../recomp/config/output_ovl/o2/o2_00574790_0x574790.cpp) | `dispatch_work_class_callback_through_owned_or_default_table_candidate` | High mechanics; role probable | a0 work W. If1B02D0()==1 andW.byte100nonzero table708BB0,else708B80;indexunsignedW.byte2,calltarget(W),propagateresult. No index/nulltargetguard. Fullphysical12entrytablesbelow,notprovenvalidclasscount. |
| [o2 0x574820](../recomp/config/output_ovl/o2/o2_00574820_0x574820.cpp) | `initialize_work_owner_flags_from_random_masks_and_mutable_policy_table_candidate` | High mechanics; role probable | a0 work W;ownerW.byte100. RNGselectsoptionalflagsW64/W68 andoneof40..42. Then34mutable4-byterows708AF0:policybyte3controlsflag60+row,policy3randomizedinplace0/1. Policy1calls5705F0(flag,1,owner),policy2ORssessionwordbanks4B9C00/4B9C40. Addsflagbit4000to4B9B48andwhen1B02D0()==1also4B9B88/4B9BC8,then5B93B0(W). Exactrandom/rowcontractbelow. |
| [o2 0x5DCA90](../recomp/config/output_ovl/o2/o2_005DCA90_0x5dca90.cpp) | `dispatch_first_active_kind83_proxy_when_point_is_outside_polygon_candidate` | High mechanics; role probable | a0 XYZ,a1 actor,a2 low8ID. ConvertsinputX/Zguestcvt.w.s,walks3B5160next28;firstactivebyte3Cnodekind30==83andbyte44==ID,370960(node,intXZ,4). Nonzero geometryresultreturnswithoutdispatch;zero assignsnode34=actorand5C1710(node),thenreturns. Doesnotcontinuepastfirsteligibleproxyorapplyglobal3B5150disable/height/busy/priority/3Ewrite. |

574010facevertexoffsettriples,inorder:(4,28,10),(4,10,34),(4,34,28),(4C,58,40),(4C,1C,58),(4C,40,1C). Eachvertexisthreeconsecutivesigned32wordsconvertedtofloat.370640normalizestrianglecrossbeforeitsnonzerotest;failedreturns0.573FB0computesdot((point+Y10)-firstVertex,normal),returns1forpositiveorunorderedand0forordered<=0;nonnull1rejects. ThelastfacetestBooleanisinvertedtoreturn1onlyitszeroaftertheotherfivepass. No plane caching, SIMD batch, radius ordynamic outputisimplementedhere. RegionR0/1activity/flagtestsbelong574680,notthispredicate.

574820firstRNGcall1AEC80(0):mask=(low16result&6)>>1;bit1 ->5705F0(W64,1,owner),bit2 ->5705F0(W68,1,owner). SecondRNG1AEC80(2):index=(low16&3)-1;if>=0request5705F0(40+index,1,owner),otherwise skip. Exactly34rowsat708AF0stride4;onlysignedbyte3read/mutated. Policy3firstbecomeslow16RNG1AEC80(1)&1,inplaceglobaltable;then0skip,1per-ownerflag,2directORbothwordbanks,othersskip. Directflag60+row selectswordbyflag>>5,bitflag&1F;writeboth4B9C00/4B9C40. Otherthreebytesperrowarenotinterpretedbythisbody. Mutatingpolicy3makeslatercallsdependentonearlierstatic-tablechanges;noalwaysrerandomizesclaim.

5DCA90hasanoppositegeometrygatefromthecommon5DC570pointselector:itsfirsteligiblekind83node dispatcheswhen370960returns0. Thecallbackis [linked proxy dispatcher](SYMBOLS_LINKED_INTERACTION_PROXY_QUERIES.md),soquerycanperformactorstatechanges. Itleaves3Eunchangedandcannotbeassumedread-only oridenticalto5DC570withdifferenttype.

Owned o2base570000SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Physical span | Exact words hexadecimal | SHA256 |
| --- | --- | --- |
| 708B80..708BAF | 574820,5B93B0,574C80,575110,575540,575F80,5762E0,574A10,574B40,575B00,575D50,5B93B0 | `faf273854d3de9d6a2040aa511365738f10cb2af7857655b2c4065bd288b9aa1` |
| 708BB0..708BDF | 5B93B0,5B93B0,5B93B0,5B93B0,5B93B0,575F80,5B93B0,5B93B0,5B93B0,5B93B0,5B93B0,576A60 | `df32a6cba05c73eb5cddb035c938ca55abd21da0f5345805a8839eda15b91ae4` |
| 708AF0..708B77 | 1010002,20004,30104,1020005,3000006,3000007,8,50009,10109,209,A,300000B,2010B,100000C,301010C,E,105010E,10,3040016,2030116,20216,10018,3000019,10119,201001A,11A,300001B,201001C,2011C,21C,1E,1011E,1001F,20020 | `984c8e08d689e4162b6087f418b685f2365597ba24eaace8ee51692ca143f6a8` |

Physicalcallbacktablescontainrepeated5B93B0entries;functioncoverageisnotincreasedforeachpointer. Nonzero physicalcallbacktargets574A10/B40/C80,575110/5540/5B00/5D50/5F80,5762E0/6A60areseparatebodyreviewgaps;thisdispatchrowdoesnotclaimthemclosed. Geometryprimitivecontractsare [overlaymath](SYMBOLS_OVERLAY_MATH.md). Runtime3C3000regioncontentsarenotdecodedfromtheo2blob. No livegeometry,visualregionnameorcallbackcostisclaimed.

Owned-word audit:5 rows,662 distinct instruction words verified,20 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited.
