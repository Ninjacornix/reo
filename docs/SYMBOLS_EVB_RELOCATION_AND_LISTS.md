# EVB relocation, absent-file defaults and halfword index lists

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed.
Addresses/indices/offsetshex. FilenameEVBcrosslink:
[main1D3E90](SYMBOLS_ROOM_SECTION_AND_SOUND_LOADING.md). Originalopcodesand
allcontextfieldidentitiesunresolved. No execution,live memory orenginechanges.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x68C1A0](../recomp/config/output_ovl/o2/o2_0068C1A0_0x68c1a0.cpp) | `reset_evb_script_context_to_owned_default_program_candidate` | High mechanics; probable role | Sets4BACF8/4BAD080,4BACE0/4BACF0=owned7174A8defaultprogram;zeros3pairs4BAD70stride8,4BADA8..B4words. Sets3243E8=1;eighthalves4BAD88=-1,eightbytes4BADB8=i. NoRDTrelocation,4BAD10/20writeorC410call. |
| [o2 0x68C260](../recomp/config/output_ovl/o2/o2_0068C260_0x68c260.cpp) | `relocate_evb_top_level_and_nested_offset_tables_then_initialize_runtime_candidate` | High mechanics; probable role | Resets4BACF8/4BAD100,3243E8=1,4BAD20=4,4BAD080,threecontextpairsandfourwordsA8..B4,eightindexhalves/byteslikeC1A0. RDTbaseword324424:32topwordsnonzeroaddbaseinplace. Forindices10..17hex,nonnullnestedtablewalksnonzerowordstozeroandaddsbaseinplace. Binds4BACE0=top[4BAD10=0],4BACF0=top[4BAD20=4],4BAD40/50=base. Calls5D7CF0,C410(base). Notidempotentoffsetconversion;no fileextentguard. |
| [o2 0x68C410](../recomp/config/output_ovl/o2/o2_0068C410_0x68c410.cpp) | `copy_evb_halfword_index_lists_with_two_distinct_sentinels_and_clear_cache_candidate` | High mechanics; probable role | a0relocatedEVB. Topindices8..Bcopysourcehalvesuntil00FFto4BA420+100*(index-8);indicesA/Bfirstcopyheaderhalves0/2to4BA820+2*(index-A)and4BA824+2*(index-A),advancesource4. TopindicesE/FcopyhalvesuntilFFFFto4BA830+100*(index-E). Finallymemset4B8E80,FF,size800. No nulltabletests,capacitychecksorconversionoftheterminator. |

Owned7174A8firstfourwords[1,A,12,1000020]verifiedfromfile-backedo2;
notinterpretedasacompletescriptororiginalcommandnames.
Relocationmodifiesloadedbytes;callingitonceonrelativeoffsetsisacallercontract,
notaprovenrepeated-relocationbug. 00FFsentinelforfirstfourlistsandFFFFforlast
twowerecheckedthroughbranch/delayslots;thetwoconventionsarenotnormalized.
RDTandcontextarraysareoutsideownedfilebytesandwerenotreadlive.
