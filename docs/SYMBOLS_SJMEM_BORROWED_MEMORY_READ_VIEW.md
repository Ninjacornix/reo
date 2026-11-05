# SJMEM borrowed-memory read stream and typed vtable

Static File #1 US original resident ELF, 2026-11-05; SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. Fifteen full original intervals plus all12ownedvtablewords/identifier/diagnostic inspected. No streamscreated, memoryattached, game, build orruntimeactivity.

Owned23DA18 reads SJMEM Error. Thisis a **borrowed contiguous read view**, distinct fromthe[two-pool SJRB](SYMBOLS_CRI_SJRB_POOL_AND_CHUNK_OWNERSHIP.md). Its vtablePut/Ungetbehaviorisnotinterchangeablewiththatwrite/readring. Offsets/unmarkedconstantshexadecimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x13F2A0](../recomp/config/output/sub_0013F2A0_0x13f2a0.cpp) | `report_owned_SJMEM_error_via_common_stream_diagnostic` | Confirmed complete body and owned vtable/constructor binding | Discardsincomingerror/context;tail13F288(23DA18),owned SJMEM Error. Doesnotthroworstopprocesshere. |
| [0x13F2C0](../recomp/config/output/sub_0013F2C0_0x13f2c0.cpp) | `acquire_SJMEM_module_reference_and_clear_pool_on_first_use` | Confirmed complete body and owned vtable/constructor binding | If224798==0 clears2247A0[480] (32records*24),thenincrementscounter. NoCRIguardhere. |
| [0x13F310](../recomp/config/output/sub_0013F310_0x13f310.cpp) | `release_SJMEM_module_reference_and_clear_on_exact_zero` | Confirmed complete body and owned vtable/constructor binding | Decrements224798 andstoresevenfrom0;exactnew0clears2247A0[480]. Nolivestreamdestructororborrowedbufferfree. |
| [0x13F360](../recomp/config/output/sub_0013F360_0x13f360.cpp) | `create_pooled_SJMEM_read_view_over_borrowed_buffer` | Confirmed complete body and owned vtable/constructor binding | Scans32records2247A0stride24 usingactiveword4;full0. Setsvtable224768,active4=1,identifier8=23DA08,buffer14=a0,capacity18=a1,errorcallback1C=13F2A0/context20=self;13F478reset,returnsrecord. NoNULLbuffer/negativecapacityadmissionorheapownership. |
| [0x13F428](../recomp/config/output/sub_0013F428_0x13f428.cpp) | `destroy_SJMEM_record_without_freeing_borrowed_buffer` | Confirmed complete body and owned vtable/constructor binding | NULLreturns;elsememset24andactive4=0. Vtable/callback/pointerallcleared;noactualbufferfree. |
| [0x13F460](../recomp/config/output/sub_0013F460_0x13f460.cpp) | `get_SJMEM_interface_identifier_pointer` | Confirmed complete body and owned vtable/constructor binding | Returnsword8 initializedtoowned16-byteGUID23DA08. Not a descriptororcurrentreadpointer. |
| [0x13F468](../recomp/config/output/sub_0013F468_0x13f468.cpp) | `set_SJMEM_error_callback_and_context` | Confirmed complete body and owned vtable/constructor binding | a1->1Ccallback,a2->20context;invalidselector/spanpathsusecallback(context,-3). Noimmediatecallback. |
| [0x13F478](../recomp/config/output/sub_0013F478_0x13f478.cpp) | `reset_SJMEM_read_position_and_restore_full_available_count` | Confirmed complete body and owned vtable/constructor binding | position10=0,remainingC=capacity18. Allborrowedbytesbecomereadablepool1;pool0staysunsupportedforwritecapacity. Nozerofill. |
| [0x13F488](../recomp/config/output/sub_0013F488_0x13f488.cpp) | `get_SJMEM_readable_byte_count_or_report_invalid_selector` | Confirmed complete body and owned vtable/constructor binding | Selector1returnsremainingC;0returns0. Otherselectorsoptionallyerrorcallback(context,-3),then0. NoCRIguardinthisgetter. |
| [0x13F4D0](../recomp/config/output/sub_0013F4D0_0x13f4d0.cpp) | `reserve_SJMEM_read_span_and_advance_position_for_selector_one` | Confirmed complete body and owned vtable/constructor binding | UnderCRIguard,selector0publishesnull0span. Selector1takesmin_signed(remainingC,requesteda2),returnsbuffer14+position10,advancespositionanddecreasesremaining. Otherselectorclearsoutputspanandoptionalerror-3. Noextent/negativecountsanitization. |
| [0x13F590](../recomp/config/output/sub_0013F590_0x13f590.cpp) | `accept_SJMEM_returned_chunk_without_mutating_read_position` | Confirmed complete body and owned vtable/constructor binding | Ifchunklength<=0orptrNULLreturn. Otherwiseguard;selectors0/1do nothingandpreservespan. Otherselectorsclearspanandcallback-3. ThisvtablePutChunkdoesnotpublishnewbytesorrestoreconsumeddata. |
| [0x13F628](../recomp/config/output/sub_0013F628_0x13f628.cpp) | `unget_SJMEM_read_span_with_clamped_position_and_pointer_check` | Confirmed complete body and owned vtable/constructor binding | Positive/nonNULLspanonly. UnderCRIguardselector1rewindsposition=max(0,position-length),remaining=min(capacity,remaining+length),thenrequiresnewposition==spanptr-buffer14; mismatchreports-3aftermutation. Selector0reports-3withoutclearing;otherselectorclearsoutputthenreports. Normalpathsleavespansunchanged. |
| [0x13F720](../recomp/config/output/sub_0013F720_0x13f720.cpp) | `query_SJMEM_available_read_span_without_reserving` | Confirmed complete body and owned vtable/constructor binding | Guard;selector1grant=min_signed(remainingC,requested),selector0grant0,otherselectorscallback-3/grant0. Writesgrantthrougha3,returns1iffgrant==requested. Nopositionchange;negativerequestnotlocallyrejected. |
| [0x13F7C8](../recomp/config/output/sub_0013F7C8_0x13f7c8.cpp) | `get_SJMEM_borrowed_buffer_base` | Confirmed complete body and owned vtable/constructor binding | Returnsbuffer14,constructorborrowedpointer. Noownershiptransferorcapacityquery. |
| [0x13F7D0](../recomp/config/output/sub_0013F7D0_0x13f7d0.cpp) | `get_SJMEM_fixed_buffer_capacity` | Confirmed complete body and owned vtable/constructor binding | Returnsword18,unchangedbyread/unget;currentavailabilityiswordC,not1C(whichholdstheerrorcallback). Corrected by the [complete pinned-source comparison](recvx-crosscheck/STREAM_FS_COMPLETE_SCOPE.md), consistentwithoriginal13F478/488/4D0andCVXSJMEMlayout. Noqueryofnativefilesize. |

Ownedvtable224768..224798,48bytes SHA-256 `480c79ea660f4c2368159bc895abda550cd106d6fbeba924354b2b6bb3fadae5`:

| Offset | Entry | Contract |
| --- | --- | --- |
| 0/4/8 | 0/0/0 | Literalunusedslots. |
| C | 13F428 | Destroyrecord. |
| 10 | 13F460 | Identifierpointer. |
| 14 | 13F478 | Reset. |
| 18 | 13F4D0 | GetChunk. |
| 1C | 13F628 | UngetChunk. |
| 20 | 13F590 | PutChunk. |
| 24 | 13F488 | GetNumData. |
| 28 | 13F720 | Availabilityquery. |
| 2C | 13F468 | Errorcallbackregistration. |

GUID23DA08..23DA18 israw16bytes41EE9EDD7916D211936C0060089448BC. ConstructorcallsnoI/Oanddoesnotclearborroweddata. Immediatelyafterreset,GetChunk1canreadfullcapacity,evenifcallerhasnotperformedapublishoperation. Thisexplainstemporaryheaderconstructioncaller12A458'sfixedmemoryinputstreams; noactualPCMsourcecopyisrequiredforempty/historyonlyuse.

Get/Unget/query use[CRI tag1 wrappers13F258/270](SYMBOLS_CRI_SJRB_POOL_AND_CHUNK_OWNERSHIP.md). Refcount/poolallocation/reset/countgettersaddnolocalguard. Ungetmutatesfirstthencheckspositionequality,soerrorreportisnotrollback. Itclampspositionandremainingindependentlyanddoesnotprovegivenpointerlengthwaslastreservedspan. Selector0getisexplicitnull0withoutreport;selector0Ungetpositivevalidspanreportsinvalidoperation. InvalidPutclearscaller-spanfields,whilevalidPutdoesnot. Thoseownershipdifferencesarepreserved.

Thephysical32recordpoolandfixedcapacityareindependentofhowmanybytesacallerrequests. Negativecounts/lengths/overlapbelongcalleradmission;nosuchlivecallsweremade. NoportableSPSCatomicprotocolorzero-copyperformanceguaranteeisclaimedfromtheseconsolemethods.

Audit: 15 bodies, 325 owned instruction words matched; 2 omitted aligned zero/NOP words, zero omitted nonzero words.
