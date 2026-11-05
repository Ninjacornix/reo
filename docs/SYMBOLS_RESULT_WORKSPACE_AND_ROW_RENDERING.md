# Result workspace loading, text decoding and sprite/rectangle row rendering

Static File #1 US, 2026-11-04. Eight complete original o2 bodies. Mechanics confidence is high; result/UI role names are candidates grounded by the owned `result.tex` and result-table filenames and observed consumers. No target execution, builds, attachment, live memory, input or performance measurements. Addresses/field offsets/key IDs are hexadecimal. Explicit array counts and coordinate values are decimal.

W=word7436F8 points at the result workspace. The loader sets it from324424 and clears540 bytes. Texture handles occupy W+C..23; event-list input W+4C, decoded text scratch W+50, special-item table W+90 and new-fact table W+B4. These are observed offsets, not a fully recovered original struct. Partial-load behavior and unbounded source/selector inputs remain explicit.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x600860](../recomp/config/output_ovl/o2/o2_00600860_0x600860.cpp) | `load_result_texture_pack_and_register_six_offset_images_candidate` | High mechanics; role probable | Sets registry key2600;readsresult.tex into32440C,decodes1AF5D0(source,source+100000). On successfulreadregisterssiximages2600..2605fromowned70DF70offsets,andstoresresolvedhandlesW+C. Clearsfiveglobalflagsand6DDD70(0). Read0skipsregistrationandflagreset. No size admission or decompressed output bound here. |
| [o2 0x600950](../recomp/config/output_ovl/o2/o2_00600950_0x600950.cpp) | `initialize_result_workspace_and_load_event_special_item_new_fact_tables_candidate` | High mechanics; role probable | W=324424,memset540,600860,stores32442C atW4C;reads evelist.dat there,spitem.dat atbase+returnedfirstsize,newfact.dat atnext+returnedsecondsize. Noalignment,readfailurebranchoraggregatecapacitycheck. Then1D3BC0 and37C4C0(0). |
| [o2 0x602C20](../recomp/config/output_ovl/o2/o2_00602C20_0x602c20.cpp) | `emit_result_descriptor_rows_using_indexed_atlas_or_solid_fill_candidate` | High mechanics; renderer role probable | a0rows12B,a1signedcount,a2color,a3texturemode. Pretested loop;rowbyte2==0 selects atlas70CBB0[sign16row0],texturehandleW+C+4*atlas.word0,paletteadmission andsprite. Nonzerobyte2emitscoloredrectangle. Optionalbyte3reversesU only;noatlas/workspaceboundsorallocation. |
| [o2 0x602E60](../recomp/config/output_ovl/o2/o2_00602E60_0x602e60.cpp) | `emit_result_descriptor_rows_with_shared_texture_uv_override_candidate` | High mechanics; renderer role probable | a0rows,a1shared12Btexture/UVparams,a2signedcount,a3color,t0texturemode. Samegeometry/solidpathas602C20,butalltexturedrowsusetheunchangedsharedparams(word0texturebank,halves4/6UV,8/Aextent),ratherthanrow0atlaslookup. Sharedparameterpointerdoesnotadvanceperrow. |
| [o2 0x603080](../recomp/config/output_ovl/o2/o2_00603080_0x603080.cpp) | `decode_result_event_text_by_page_and_row_xor_ff_to_workspace_candidate` | Confirmed mechanics; text role probable | a0page,a1row. Source=W4C+1000*page+40*row;strlen10B158(source),copyeachbyteXORFFtoW50,appendNUL,returnW50. No64-bytecapacitycheck,sourceboundorpage/rowmask. LengthqueryusesencodedNULbeforeXOR;sourceNULnotdecodedasFF. |
| [o2 0x603170](../recomp/config/output_ovl/o2/o2_00603170_0x603170.cpp) | `emit_result_animated_prompt_and_two_static_rows_then_advance_frame_modulo_thirty_two_candidate` | Confirmed mechanics; prompt role probable |Sharedtextureparamsbank5,U=W31C,V0,width32,height25;602E60(row70D698,count1,colorFF804000,mode0),602C20(rows70D680,count2,colorFFFFFFFF,mode0). Then31C=(31C+1)&1F. Noinputreadorframe-pacingboundary. |
| [o2 0x603200](../recomp/config/output_ovl/o2/o2_00603200_0x603200.cpp) | `emit_result_indexed_animated_icon_row_and_advance_frame_modulo_thirty_two_candidate` | Confirmed mechanics; UI role probable | a0low16selector;row=70D510+12*(selector+5),sharedtexturebank5/U=W31C/V0/width32/height32,colorFF804000,mode0,count1. Calls602E60then31C=(31C+1)&1F. Noselectorbound;separateinvocationsadvancesharedframeagain. |
| [o2 0x603290](../recomp/config/output_ovl/o2/o2_00603290_0x603290.cpp) | `count_three_mask_selected_result_codes_other_than_two_candidate` | Confirmed mechanics; code meanings unknown | ClearsW526;fori0..2,ifW525bit(1<<i)andword(W530+4*i)!=2,incrementbyte526. Doesnotreturnacountcontract,clearinputs,orvalidateunrelatedflags. |

600860 sets the current registry key through1CD1C0(2600) before reading; it does not destroy all existing textures. The compressed input is at32440C and output exactly100000 bytes later, with no output-length argument supplied by this wrapper. For each six-entryoffset,1CCB90(key,output+offset) is followed by1CD250(key),whosepossiblyzeroresultisstoredinW+C+4*i. It does not check each registration result before proceeding. Onlyaftertheloopdoesitclear4BAE7E/4BAE7C/4BAE7D/4BADF8/4BAE9Aandcall6DDD70(0). AreadfailureleavesWclearfromtheouter600950butdoesnotperformtheseglobalresets.

600950 deliberatelyusesreturnedreadlengthsascursorswithoutalignment. Firstreturn0makesW90==W4C;secondreturn0makesWB4==W90. Thewrapperstillattemptsthesubsequentreadsandcalls1D3BC0/37C4C0,soitdoesnotreportatransactionalsuccess/failure. Properhosttranslationmustretainorconsciouslyvalidatecapacityandpartialfailurecontractsusingcallerassets;thoseassetbyteswerenotprovidedbytheownedoverlay.

Descriptor rows are12bytes: signedhalf0atlasindex,signedbyte2kind,signedbyte3Ureverse,andfour signedhalves4/6/8/Ageometry. Texturedpathpassesgeometryhalvesunchangedtoa20Bstackdescriptorforresident1AB860. ItsetsGSregister63=10000,6C=0,admitspossiblyrewrittenhandle19D720(1,&handle),register4=handle,andselects1AF1E0(4,5)whenmode0,otherwise(4,1). Colorisfulla2for602C20/fulldataa3for602E60. UVusesunsignedhalves:normalU0=u,U1=u+width-1;reversedU0=u+width-1,U1=u. V0=v,V1=v+height-1. UVsarehalfwordstoreswithoutclamp. Nulltexturedhandleonlyskipsthatrow;theloopcontinues.

Forrowkindbyte2nonzero,texturemode/atlaslookup/paletteadmissionareskipped. Itforces1AF1E0(4,5),formsrectangleendpoints(x,y,x+width,y+height)fromsignedgeometryhalves,narrowshalfwordwrites,setscolor,andcalls1ABB60. Texture/rectanglepathsarenotinterchangeabledespiteasharedrowlayout. Bothloopsstartfromcounttest,sozero/negativecountemitsnothing;rowpointerincrementsCeachiteration. Neitherloopsuntilasentinelorsorts/batchesrows.

Boundeddatafromownedo2base570000SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:

| Exact span | Original values / role | SHA256 |
| --- | --- | --- |
|70DF70..70DF87,sixwords|Texturepackbyteoffsets0,10500,20A00,30F00,35400,45840(hex)|715a7411c1a7d31959900ae8945a4fd2db7bd5eaa48ac060730fea989271d617|
|70D680..70D697,two12Brows|Signedhalves(113,0,432,396,160,32);(16,0,455,400,112,24),all decimal|2b535f620ed588fffe6ccb6f3c97b8cc8875a98fa4be1bc28798ccfa756fff97|
|70D698..70D6A3,one12Brow|Signedhalves(102,0,439,400,146,25),decimal;602E60overrideignoresitsatlasindex102|26041a4204f6af863b605e38fa502b61d6a393dd68a2db0dfa6a7dd0ea7b3818|
|70CC70..70CC7B,atlas16|wordtexture0,UV(0,224),extent(120,24),decimal|71f2638c2e25db7011449600c5675c26d2560423fdfa3f81ca6e2abd1f60a801|
|70D0FC..70D107,atlas113|wordtexture1,UV(0,160),extent(160,32),decimal|947b674a96e0ab3bda9d0bd02f326f6bec33d1d77b7f6eb4dd129d19639a1733|

Thesearethedirectfixedatlasrowsusedby603170'stwostaticrows,notafullyrecoveredatlasextent. Arbitraryrowselectorsrequiretheirownasset/tableadmission;noextraentrieswerelabeledjusttoextendcoverage. 603200'sselector-specificrowdataremainsboundedbycallersstilltobereviewed.

FullNUL-terminatedownedfilenames,includingterminatorinthehash:

| Address | Filename | Bytes | SHA256 |
| --- | --- | --- | --- |
|73F530|data\\rom\\scene\\pit_tex\\result.tex|34|8144311d40f355518e9d47977ac9eb966aa75bd7a402e86ae66322428afb6584|
|73F560|data\\rom\\scene\\item_msg\\evelist.dat|36|6561b952746e8607e537390a58318c9865f6eeb8fb8cb7a3539638e7cc429ad4|
|73F590|data\\rom\\scene\\item_msg\\spitem.dat|35|8ae220f1a20e15302ed5651576f6df969650aa72e5beca42c15f7c6d3cc93551|
|73F5C0|data\\rom\\scene\\item_msg\\newfact.dat|36|76e0eff9d70ee1a144aab9948f7e5b7226c96660908341b5602ba66e2bf83b49|

Theouterresultandsaveflowis [scenario exit/movie/result flow](SYMBOLS_SCENARIO_EXIT_MOVIE_RESULT_FLOW.md). Resident1AB860/1ABB60andpaletteadmissionretaintheirexistingindependentlymappedcontracts. Thetextlengthprimitiveis [dispatch and library helpers](SYMBOLS_DISPATCH.md). Noactualresultassetswereopened,decompressedorrendered,andnocostclaimfollowsfromstaticrowcounts.

Owned-word audit: eight complete rows, 517 original instruction words verified, 10 omitted zero/NOP words, zero conflicts and zero omitted nonzero words. Both fixed atlas rows, all three fixed descriptor rows, all six pack offsets and four complete filename strings were decoded/hash checked. Source links/live IDs/current annotations clean; no shared index mutation.
