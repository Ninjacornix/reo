# HTTP query API and library lifecycle

Static File #1 US research, 2026-11-04. Catalogue **o6**, runtime id **6**, base **0x6E0000**, owned **nethttp.bin**, SHA-256 **68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117**. All listed bodies and25-entry getter table were reviewed against the owned instruction words. No game, network request, build, replay or live attachment occurred. Complements [operation and setter API](SYMBOLS_HTTP_OPERATION_API.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x6E3068](../recomp/config/output_ovl/o6/o6_006E3068_0x6e3068.cpp) | `request_async_http_transaction_cancel_requiring_async_mode_candidate` | Probable cancellation role; full body reviewed | Context+38 must be nonzero,otherwise stores-1004 at+20/returns-1. Sets cancellation+3C=1, calls6E62E0 only when worker+5C!=-1;returns0. Differs from6E4D90: enforces async flag and does not additionally invoke resident1D97E0 for state2. No completion wait locally. |
| [o6 0x6E30B8](../recomp/config/output_ovl/o6/o6_006E30B8_0x6e30b8.cpp) | `query_http_transfer_progress_for_method_candidate` | Probable progress query; full body reviewed | Method+B4==4(PUT) returns unsigned32 word+88;other methods return64-bit+100 response progress. No synchronization or common unit conversion. |
| [o6 0x6E30D8](../recomp/config/output_ovl/o6/o6_006E30D8_0x6e30d8.cpp) | `query_http_method_three_progress_or_unsigned32_sentinel_candidate` | Confirmed static mechanics; API intent partial | Method+B4==3(POST) returns unsigned32+88;otherwise constructs64-bit result00000000FFFFFFFF using sign-extendedLUIFFFF thenDSRL32. Preserve literal different method test from6E30B8; not a universal total-byte query. |
| [o6 0x6E3100](../recomp/config/output_ovl/o6/o6_006E3100_0x6e3100.cpp) | `query_http_expected_response_body_length64_candidate` | Probable expected-length query | Loads64-bit context+118. Meaning corroborated by body reader; no validity or completion check. |
| [o6 0x6E3108](../recomp/config/output_ovl/o6/o6_006E3108_0x6e3108.cpp) | `initialize_http_library_binary_semaphore_then_subsystem_candidate` | Probable library lifecycle; full body reviewed | Creates semaphore114620 with initial/max words1 at descriptor+4/+8 and name pointer73A0E0,stores id734DF8. Create==-1=>-1. Otherwise6E6310 result0=>0,other=>-1. No explicit semaphore cleanup on delegated initialization failure, and no idempotence guard locally. Descriptor fields not written in this body retain caller/runtime uncertainty. |
| [o6 0x6E3170](../recomp/config/output_ovl/o6/o6_006E3170_0x6e3170.cpp) | `shutdown_http_library_subsystems_and_binary_semaphore_candidate` | Probable library lifecycle; full body reviewed | Calls6E72D0 ignoring result, deletes semaphore734DF8,negative=>-1. Then6E6318 must return0;finally6EB380 result0=>0,other=>-1. Does not reset stored semaphore id, and exits early after checked failures. Detailed delegated subsystem lifetime is not inferred. |
| [o6 0x6E31C8](../recomp/config/output_ovl/o6/o6_006E31C8_0x6e31c8.cpp) | `set_three_http_default_worker_stack_priority_pairs_candidate` | Confirmed static mechanics | a0 stack size,a1 priority. Unsigned(priority-1)<127 accepts1..127;else-1 without writes. Success sets three pairs at734C28..3C to identical size/priority,returns0. No size>=4096 check here, unlike per-context setter optionC; caller constraints differ. |
| [o6 0x6E45A0](../recomp/config/output_ovl/o6/o6_006E45A0_0x6e45a0.cpp) | `get_http_context_options_into_checked_output_cells_candidate` | Probable query API; full body/owned table reviewed | a0 context,a1 selector<25,guest variadic output pointers. Returns0 on success;invalid selector/output cell stores-1004 at context+20 and returns-1. Single outputs are32-bit; two-output cases validate both pointers before writes. Pointer values are borrowed views,not cloned allocations; no GP restoration/callback invocation or lock here. Table detailed below. |

Getter table0x73A1D0 uses the same selector space as the setter but has different supported cases. All returned pointers retain context ownership.

| Hex selector | Output(s) |
| --- | --- |
| 00 | User-agent pointer+0. |
| 01 | Version+8. |
| 02 | Method+B4. |
| 03 | Parsed URL pointer+B8. |
| 04 | Alternate parsed URL pointer+90. |
| 05 | Request header list+BC. |
| 06 | Body pointer+C0 and32-bit length+C4 (does not return ownership flags). |
| 07 | Deadline+C. |
| 08 | Deadline+10. |
| 09 | Logical inverse of async word+38. |
| 0A | Completion callback+68 and argument+6C. |
| 0B | Chunk callback+120 and argument+124. |
| 0C | Stack size+54 and priority+58. |
| 0D | Context words+30 and+34; setter for this selector is unsupported. |
| 0E | Word+174. |
| 0F | Progress callback+78 and argument+7C. |
| 10 | Chunk size+84. |
| 11 | Output handle+CC. |
| 12 | Output callback+D0. |
| 13 | Unsupported; setter removes a named header. |
| 14 | Word+D8. |
| 15 | Connection deadline+40. |
| 16 | Logical inverse of coordinator async word+B0. |
| 17 | Coordinator callback+A4 and argument+A8. |
| 18 | Output callback+D0 and argument+17C. |

The two different method-specific progress queries and asymmetric selector support are preserved literally. They must not be normalized into a guessed higher-level API without caller evidence. Counts and lifecycle observations remain static; none establishes a measured wait or gameplay slowdown.
