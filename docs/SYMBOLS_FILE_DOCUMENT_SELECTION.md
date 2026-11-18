# File/document list selection and relative text records

Static File #1 US research, 2026-11-04. Six complete original bodies reviewed.
Addresses/offsets hexadecimal. W=755EC0; P=pointer at755770; resource base755760
is loaded from item_msg/file%03d[e].dat by the already-mapped UI cache loader.
No game/build/replay/attachment/live-memory work. Role labels remain candidates.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6E60A0](../recomp/config/output_ovl/o2/o2_006E60A0_0x6e60a0.cpp) | `tick_admitted_file_document_list_and_page_selection_candidate` | Probable role; full body reviewed | First6E1A60 can close. W0 phases0..3. Phase0 sets755E84, clears P3A94/95/96, calls9C10, stores lowbyte count as half3A9A and clears scroll half3A9C. Phase1 advances on nonzero count or admits close mask8010. Phase2 repeat-input bit1/2 moves row3A96 within0..5 and scroll3A9C within count, with sounds; mask8010 closes, bit20 clears page3A9F, advances phase and calls99A0(row+scroll). Phase3 bit8000 closes, bit10 returns to list; repeat bit8/4 moves page3A9F in0..3A9E-1 and emits1B87E0(A,0). In phases1/2 direct masks400/800 request adjacent UI page through W3DE0. No blocking loading loop. |
| [o2 0x6E6400](../recomp/config/output_ovl/o2/o2_006E6400_0x6e6400.cpp) | `tick_alternate_file_document_list_and_detail_selection_candidate` | Probable role; full body reviewed | Same four-phase/close/page-request layout as60A0, but count comes from4B9D19 or104 when1B82A0(5B) nonzero, and phase2 refreshes that count each tick. Row/scroll navigation has the same six-visible-row bounds. Confirm clears detail index3A9F and enters phase3 without99A0; phase3 only closes/returns, with no per-page horizontal navigation here. Thus its title/page preparation is delegated elsewhere; no assumption that this is the same record loader as60A0. Original1B82A0 body is literal0; alternate branch retained as observed source structure. |
| [o2 0x6E9320](../recomp/config/output_ovl/o2/o2_006E9320_0x6e9320.cpp) | `copy_relative_file_text_span_terminate_and_decode_candidate` | High mechanics; probable role | a0 destination,a1 resource base,a2 start offset,a3 end offset. Copies end-start bytes from base+start to stack+30, appends zero, then6DE220(temp,destination) FF-XOR decoding. Stack allocation130 leaves100 bytes after temp start; there is no local span bound or destination-capacity argument. Valid asset interval/size contracts remain unverified; no demonstrated overflow or runtime failure claim. |
| [o2 0x6E99A0](../recomp/config/output_ovl/o2/o2_006E99A0_0x6e99a0.cpp) | `select_admitted_file_document_record_and_bind_page_offsets_candidate` | Probable role; full body reviewed | a0 admitted ordinal. Clears P3A9E/9F and3B20; null resource755760 exits. Starts record base+4, follows each record word0 as next resource-relative offset. Normal path counts only5709B0(record ordinal)==1 until requested admitted ordinal or total P3A98; alternate1B82A0(5B) path follows a0 links without flag filtering. Reads record words0/4/8/C, sets P3B20=record+C, decodes title span[8,C) intoP3AA0 through9320, writes lowbyte word4 to pagecount3A9E, lowbyte highhalf to3B28, sets3B24=resource+word0. No local out-of-range requested-ordinal rejection or link validation. |
| [o2 0x6E9B10](../recomp/config/output_ovl/o2/o2_006E9B10_0x6e9b10.cpp) | `select_file_document_record_by_unfiltered_ordinal_candidate` | Probable role; full body reviewed | a0 ordinal; clears same page/title pointer fields, null base returns0. Follows exactly a0 relative links from resource+4 using a pretested loop, with no5709B0 filter or total-count guard. Uses identical words0/4/8/C title/page bindings as99A0, then returns1. Nonpositive signed ordinal selects first record without link advances. |
| [o2 0x6E9C10](../recomp/config/output_ovl/o2/o2_006E9C10_0x6e9c10.cpp) | `count_admitted_file_document_records_and_cache_total_candidate` | High mechanics; probable role | Null755760 returns0. Copies resource byte0 into P half3A98, then pretested total-count loop calls1B82A0(5B); nonzero admits every ordinal, otherwise5709B0(ordinal)==1 increments count. Returns admitted count. Total is one unsigned byte, so zero executes no record iterations. Flag meaning comes from caller/resource context rather than an invented original unlock enum. |

The ordinary path's flag query5709B0 is the mapped unbounded byte-bank test at
4B9C80. The shared feature query1B82A0 has an original constant-zero body; this
notebook records both original caller branches without asserting which override
registrations a particular native executable uses. File/resource loading is in
[item/message texture caches](SYMBOLS_ITEM_MESSAGE_TEXTURE_CACHES.md); FF-XOR text
semantics are in [timed message resources](SYMBOLS_TIMED_MESSAGE_RESOURCE_FLOW.md).
Static span or offset preconditions are open contracts, not measured incidents.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
