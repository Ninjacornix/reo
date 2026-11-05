# Resident Sofdec: indexed span caches and source counters

Static File #1 US research, 2026-11-04. Owned ELF `game_data/SLUS_207.65`, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. Complete original bodies and delay slots read; no game/build/replay, attachment, live-memory or stream test. Labels describe observed guest operations, not recovered original names.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1674A0](../recomp/config/output/sub_001674A0_0x1674a0.cpp) | `Sofdec_set_indexed_cached_prefix_and_scanned_end_pointer_candidate` | Confirmed complete 26-word body | 169EC8 enters tag1 critical section; stores main1168+74hex*index=original a2 prefix pointer, next word=original a3 scanned-end pointer; 169EE0 leaves. No bounds, type or enabled check. |
| [0x167508](../recomp/config/output/sub_00167508_0x167508.cpp) | `Sofdec_get_indexed_source_data_capacity_candidate` | Confirmed complete 8-word body | Returns main115C+74hex*index, bodyC initialized from source descriptor data capacity. No active/type check. |
| [0x167528](../recomp/config/output/sub_00167528_0x167528.cpp) | `Sofdec_get_indexed_channel_one_requested_byte_counter_candidate` | Confirmed complete 8-word body | Returns main1174+74hex*index, body24 maintained by channel1 move accounting. Requested count can differ from actual move. |
| [0x167548](../recomp/config/output/sub_00167548_0x167548.cpp) | `Sofdec_get_indexed_extent_with_initial_SJ_availability_fallback_candidate` | Confirmed complete 39-word body | Inside optional tagged critical-section hooks reads body20/24. If body20==0 and body24!=0, calls SJ body4 vtable24(channel1) and uses body24+available. Any negative result becomes7FFFFFFF. Otherwise returns body20. No NULL SJ admission on fallback. |
| [0x1675E8](../recomp/config/output/sub_001675E8_0x1675e8.cpp) | `Sofdec_get_enabled_indexed_SJ_or_report_disabled_candidate` | Confirmed complete 24-word body | Zeros *outa2 before checking slot enabled4. Disabled reports FF000401; enabled writes slot14/body4 SJ and returns0, even if SJ pointer itself is NULL. |
| [0x167648](../recomp/config/output/sub_00167648_0x167648.cpp) | `Sofdec_add_to_nonnegative_indexed_channel_one_counter_candidate` | Confirmed complete 12-word body | Adds original a2 to body24 only when old body24>=0. Negative sentinel unchanged; no pending flag, bounds check or critical-section entry. |

Six bodies /117 instruction words. Slot/body layouts follow [construction](SYMBOLS_SOFDEC_EIGHT_STREAM_WORKSPACE_CONSTRUCTION.md) and [SJ moves](SYMBOLS_SOFDEC_BORROWED_SOURCE_AND_SJ_PEEK_MOVE.md). Counters are guest bookkeeping, not a proof of presented frames, clock progress or buffer safety. All owned instruction comments match; omitted aligned words are zero.

Critical-section clarification: full169EC8?12BD78?1416D0?1415E0 and169EE0?12BD90?1416E8?141640 chains force tag1, invoke optional registered enter/leave hooks and update nesting only when hooks exist. They do not save/restore memory through the incoming stack argument. Hook installation, actual synchronization and provider-span lifetime remain caller/runtime contracts.

Full16C7F0settercaller16C914establishessecondwordisanendaddress,notlength;upstream167430accessorrenamedconsistently.
