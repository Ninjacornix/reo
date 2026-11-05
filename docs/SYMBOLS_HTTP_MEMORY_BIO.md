# HTTP overlay memory-buffer BIO

Static owned File #1 o6 `nethttp.bin`, runtime ID6/base6E0000, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Complete original catalogue intervals and branch/delay-slot flow reviewed. No target execution, files opened through target code, connections, build or runtime changes. Numbers hexadecimal except ordinary prose; labels proposed static roles. Companion [BIO dispatch](SYMBOLS_HTTP_BIO_DISPATCH_AND_CHAINS.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x6FAB40](../recomp/config/output_ovl/o6/o6_006FAB40_0x6fab40.cpp) | `get_memory_buffer_bio_method_table` | Confirmed complete getter/table binding | Returns owned735200, type401/name memory buffer. Ten words bind write6FAD08/read6FAC28/puts6FAFC8/gets6FAEE0/control6FADC0/create6FAB78/destroy6FABC8. |
| [o6 0x6FAB50](../recomp/config/output_ovl/o6/o6_006FAB50_0x6fab50.cpp) | `create_memory_buffer_bio_from_owned_method` | Confirmed full wrapper | Gets6FAB40 method, calls6F3888 and returns BIO/result; no separate data allocation here. |
| [o6 0x6FAB78](../recomp/config/output_ovl/o6/o6_006FAB78_0x6fab78.cpp) | `initialize_memory_bio_with_owned_growable_buffer_and_empty_read_minus_one` | Confirmed full construction | 6FB3E0 allocation failure returns0; success stores buffer header20, initializedC=1, closePolicy10=1, emptyRead1C=-1 and returns1. |
| [o6 0x6FABC8](../recomp/config/output_ovl/o6/o6_006FABC8_0x6fabc8.cpp) | `destroy_initialized_memory_bio_buffer_when_close_policy_enabled` | Confirmed full guards/destruction | Null BIO returns0. Disabled closePolicy10, uninitializedC or nullstate20 return1; otherwise6FB438 frees header/data, clears20 and returns1. Does not clear initializedC or closePolicy10. |
| [o6 0x6FAC28](../recomp/config/output_ovl/o6/o6_006FAC28_0x6fac28.cpp) | `read_and_consume_memory_bio_prefix_or_return_configured_empty_result` | Confirmed full count/copy/shift/retry flow | Clears retry low nibble; selects signed min(request,length). Nonnull destination and positive selected count copy prefix, reduce length and shift remainder left bytewise. Otherwise nonempty buffer returns selected count WITHOUT consumption. Empty buffer returns configured1C and sets retryRead9 iff nonzero. No local positive-count gate; configured positive result need not mean copied data. |
| [o6 0x6FAD08](../recomp/config/output_ovl/o6/o6_006FAD08_0x6fad08.cpp) | `append_bytes_to_memory_bio_by_growing_buffer` | Confirmed full resize/copy path | Loads buffer20; null source logs lib20/function6F/reason6D and returns-1. Clears retry flags, resizes to oldLength+count via6FB490; result must equal total. Copies count bytes to old end and returns count. No local signed-count/overflow/source-alias guard; caller admission unresolved. |
| [o6 0x6FADC0](../recomp/config/output_ovl/o6/o6_006FADC0_0x6fadc0.cpp) | `control_memory_bio_reset_buffer_ownership_empty_read_result_and_queries` | Confirmed complete130-entry switch | 1 zeroes capacity bytes when data nonnull and sets length0;2 returns length==0;3 returns length and optionally data pointer;8/9 get/set closePolicy10 (lowbit);A returns length;B/C return1.72 destroys prior per policy then adopts pointer as header20 and sets policy, WITHOUT setting initializedC;73 optionally exports header.82 sets emptyRead1C from signed LOW32 integer. All other commands0. Complete table below. |
| [o6 0x6FAEE0](../recomp/config/output_ovl/o6/o6_006FAEE0_0x6faee0.cpp) | `read_memory_bio_line_prefix_reserving_nul_space` | Confirmed full scan/read/termination flow | Clears retry; capacity<=0 returns0. Scans entire buffered content for LF, selects min(capacity-1,line length including LF), calls6FAC28; positive result appends NUL. No LF sets retryRead before call, but callee clears retry flags again. No local destination guard; null destination may reach trailing store if positive result. Runtime admission unknown. |
| [o6 0x6FAFC8](../recomp/config/output_ovl/o6/o6_006FAFC8_0x6fafc8.cpp) | `append_nul_terminated_string_to_memory_bio` | Confirmed complete wrapper | strlen then6FAD08(BIO,text,length); returns result. No local null-source guard or newline insertion. |

Owned table735200 (ten words):

```
00000401 0073B840 006FAD08 006FAC28 006FAFC8
006FAEE0 006FADC0 006FAB78 006FABC8 00000000
```

All130 table73B850 entries1..82 reviewed. Targets:1->6FAE18;2->6FAE38;3->6FAE54;8->6FAE90;9->6FAE98;A->6FAEA4;B/C->6FAEAC;72->6FAE68;73->6FAE80;82->6FAE44;every remaining index->6FAEB4(return0). Outside range also0. SHA-256 `536cf5828369824ed9974b120af3b8d5e0bbaa695ff94bd7588f19eed25e07d1`.

State20 points to [growable header](SYMBOLS_HTTP_GROWABLE_BYTE_BUFFERS.md): length0,data4,capacity8. Reported literal null/negative/configured-result edge cases do not establish runtime input admission or a reproduced failure.

Audit: 296 verified instruction words, zero conflicts, 5 omitted zero words (NOP padding), zero omitted nonzero words.
