# Resident Sofdec: stream command gates, availability and property flags

Static File #1 US research, 2026-11-04. Owned ELF `game_data/SLUS_207.65`, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. Complete original bodies and delay slots read; no game/build/replay, attachment, live-memory or stream test. Labels describe observed guest operations, not recovered original names.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x167BC0](../recomp/config/output/sub_00167BC0_0x167bc0.cpp) | `Sofdec_return_zero_stream_adapter_candidate` | Confirmed complete 2-word body | Returns0 only. API purpose unresolved; no invented work. |
| [0x167BC8](../recomp/config/output/sub_00167BC8_0x167bc8.cpp) | `Sofdec_mark_main_pending_and_return_zero_candidate` | Confirmed complete 4-word body | Sets main44=1; returns0. |
| [0x167BD8](../recomp/config/output/sub_00167BD8_0x167bd8.cpp) | `Sofdec_dispatch_command_B_only_for_disabled_slot_candidate` | Confirmed complete 22-word body | Slot enabled4 NONZERO returns0. Otherwise tail177BE0(main,slot4C,commandBhex,originala2,NULL). The apparently inverted gate is literal; do not describe as enabled-stream dispatch. |
| [0x167C30](../recomp/config/output/sub_00167C30_0x167c30.cpp) | `Sofdec_dispatch_command_C_for_disabled_slot_and_mark_pending_candidate` | Confirmed complete 27-word body | Enabled slot returns0; disabled calls177BE0(main,slot4C,Chex,originala2,NULL). Always sets main44=1 afterward; returns child result or0. |
| [0x167D20](../recomp/config/output/sub_00167D20_0x167d20.cpp) | `Sofdec_sum_indexed_channel_one_two_span_lengths_candidate` | Confirmed complete 10-word body | 166FE8 peek channel1 into local record; returns firstlen4+secondlenC. Does not retain provider ownership. |
| [0x167D48](../recomp/config/output/sub_00167D48_0x167d48.cpp) | `Sofdec_sum_indexed_channel_zero_two_span_lengths_candidate` | Confirmed complete 10-word body | 166FD0 peek channel0; returns firstlen4+secondlenC. |
| [0x167D70](../recomp/config/output/sub_00167D70_0x167d70.cpp) | `Sofdec_validate_handle_and_set_property_31_candidate` | Confirmed complete 23-word body | 169E30 invalid reports169C10(NULL,FF000161); valid calls175460(main,31hex,1),returns0. No original flag-name identity. |
| [0x167DD0](../recomp/config/output/sub_00167DD0_0x167dd0.cpp) | `Sofdec_get_property_31_as_boolean_candidate` | Confirmed complete 8-word body | 175628(main,31hex), returns value!=0. No handle validation here. |
| [0x167DF0](../recomp/config/output/sub_00167DF0_0x167df0.cpp) | `Sofdec_get_property_31_or_38_as_boolean_candidate` | Confirmed complete 17-word body | Returns1 iff175628(property31) or property38 nonzero, else0. |
| [0x167E38](../recomp/config/output/sub_00167E38_0x167e38.cpp) | `Sofdec_get_property_31_or_39_as_boolean_candidate` | Confirmed complete 17-word body | Returns1 iff property31 or39 nonzero, else0. No broader pause/end-of-stream identity established. |

Ten bodies /140 instruction words. Command forwarding belongs to the slot/configuration dispatcher, not a platform control or network request performed during research. Literal property IDs are retained until connected call sites establish their meanings. All owned comments match; omitted aligned words are zero.
