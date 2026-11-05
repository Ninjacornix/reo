# Surface mark and table-selected contact effect constructors

Static File #1 US owned o2 analysis, 2026-11-05. Three complete original bodies and owned dispatch data. [Identity](FUNCTION_INDEX.md). Offsets/masks hexadecimal; no execution or visual-success claim.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5DD080](../recomp/config/output_ovl/o2/o2_005DD080_0x5dd080.cpp) | `construct_random_quarter_turn_surface_mark_unless_actor_below_type81_surface_candidate` | Confirmed complete constructor/control flow; asset names unknown | If5E06C0(actor)!=0 return. Allocate652390(resource6), failure returns. Setactive1,class2=6,type3=8,variant4=B,update571DD0,render371EF0,resource204=6/resolved23A,byte30=0,context1F4=392670. Initialize matrix50 from294E00template; RNG1 low16&C000 converted by191F80 and1901A0 Y rotation. Set matrixXYZ to inputactor38/3C/40,1F0=&matrix50,flags200=18193. No652E20 or owner24 assignment. Return not normalized. |
| [o2 0x5DD170](../recomp/config/output_ovl/o2/o2_005DD170_0x5dd170.cpp) | `construct_resource_one_effect_children_with_optional_basis_and_caller_variant_candidate` | Confirmed complete constructor/control flow; asset names unknown | Inputs optionalbasis a0,XYZ a1,variant a2. Allocate652390(1),failure returns;652E20(work,1,-1) random resourcevariant;590760 obtains resource header/group. Active1,update653010,render373070,byte4=low8caller variant,baseXYZ44=input. Default1F0NULL;nonNULLbasis copied64B into50,1F0=&50. Flags200=1A193;652470(work,header,group,-F) builds child matrices with exact signedmask-15. No return normalization, copiedmatrix translation is not reset here. |
| [o2 0x5DD270](../recomp/config/output_ovl/o2/o2_005DD270_0x5dd270.cpp) | `dispatch_nine_contact_effect_styles_and_construct_resource_children_candidate` | Confirmed complete constructor/control flow; asset names unknown | a0context,a1optionalbasis,a2XYZ,a3unsignedmode. Outofrange>=9 returns. Owned jump table below. Normal resource path allocates652390(resource),652E20(...,-1),590760;active1,update653010,render373070,variant4=0,1FF=1,baseXYZ44=input,optional64Bbasis50/1F0. InitializesC=0,E=headerhalf12,10/12=0,byte31=0,1F4=392670,1F8=contextword18,flags200=1A193. For each unsignedheaderhalfC part (8Bstride), allocate651E00;successowner8=work,half2=372720(partbyte4),byte1=partbyte5;work114half[i]=partbyte6,work134ptr[i]=child,count31++. Firstchildflags1A193,others1A993. Failure writesID-1/pointerNULL and continues, leaving prior successful children. No childarray bounds or rollback. |

Owned73EB80[36] jump addresses, SHA-256 `fe9b37dabf0efa35c74adb76288377e21621067c0579bf7b22946641c46a7b70`:

| Mode decimal | Target | Behavior |
| --- | --- | --- |
| 0 |5DD2EC|Normal resourceA.|
| 1 |5DD2F8|Normal resourceC.|
| 2 |5DD300|Normal resourceB.|
| 3 |5DD308|Tail571EC0(originalcontext,basis,XYZ,0,0), no normal path.|
| 4 |5DD3B4|Normal resourceE.|
| 5 |5DD2D8|Normal resourceA if signedcontext halfC==0,else13.|
| 6 |5DD330|Build extra transformedresourceE then independently normalresourceE.|
| 7 |5DD31C|571EC0(originalcontext,basis,XYZ,4,0), no normal path.|
| 8 |5DD3BC|Normal resource11.|

Mode6 first initializes localmatrix, applies370320(0,8000,0,matrix), then1913E0(matrix,inputbasis). Localoffset70B5D0=(0,0,-106.36199951171875) transforms in place byinputbasis and adds inputXYZ.6525C0(matrix,offset,1,E,-1,1A193) attempts the extra child. Its failure does not prevent the subsequent normal E allocation; optionalbasis can only be NULL safely on modes that do not use it earlier. Owned70B5D0[12] SHA-256 `4bc76b8d15b05799b656a042ac1cb85475429aa97731790dd4f9c5e425ed542d`.

[Resource/child constructors](SYMBOLS_CUTSCENE_RESOURCES.md), [scene header accessor](SYMBOLS_SCENE_KEYFRAME_TRACKS_AND_PIECE_CHANNELS.md), [actor-owned effect channels](SYMBOLS_ACTOR_ATTACHED_EFFECT_CHANNELS.md), [surface-mark callback](SYMBOLS_TRACED_SURFACE_MARKS.md), [type81 query](SYMBOLS_ACTOR_VARIANT_E_UPDATE.md) and [matrix math](SYMBOLS_RENDER_MATH.md) establish the called contracts. No owned asset file names or runtime resource residency is inferred from numeric effect IDs. This mapping does not measure particle cost or prove a slowdown cause.
