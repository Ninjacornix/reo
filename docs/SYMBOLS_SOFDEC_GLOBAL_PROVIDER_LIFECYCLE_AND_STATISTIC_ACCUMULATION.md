# Resident Sofdec: global provider lifecycle and statistic accumulation

Static File #1 US research, 2026-11-05. Owned ELF `game_data/SLUS_207.65`, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. All original bodies and delay slots read with connected callers. No game/build/replay, attachment, live memory or clock test.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x175A38](../recomp/config/output/sub_00175A38_0x175a38.cpp) | `Sofdec_initialize_global_tick_and_frequency_triple_candidate` | Confirmed complete 4-word body | 169A68passesglobal22F138andconfig4. Storesrecord0/4=0,8=originala1.22F138tickand22F140frequencyconsumersconnected;nofrequencyvalueinferredfromconstructoralone. |
| [0x175A48](../recomp/config/output/sub_00175A48_0x175a48.cpp) | `Sofdec_noop_global_tick_lifecycle_hook_candidate` | Confirmed complete 1-word body | JRRAwithzero-delayword;169B38callsglobalclockrecordduringfinalization. OriginalAPIidentityunknown,noreturnvalueassignmentorresourcecleanup. |
| [0x177470](../recomp/config/output/sub_00177470_0x177470.cpp) | `Sofdec_accumulate_signed64_sample_sum_min_max_and_count_candidate` | Confirmed complete 15-word body | Countword18++;qword0+=original64bita1;8=signedmin(old8,a1),10=signedmax(old10,a1).177450initial8=MAX,10=0meansall-negativesamplesleave max0. Timerunitsarecaller-specific. |
| [0x1774B0](../recomp/config/output/sub_001774B0_0x1774b0.cpp) | `Sofdec_copy_fifteen_provider_pointers_and_invoke_slot_zero_candidate` | Confirmed complete 38-word body | Copies60bytesoriginalsourcearraytooriginaldestviaunaligned64bitoperations+wordtail;then177560(SOURCE,slot0),notcopiedDEST.169A68copiesconfig0to22F148. StopsatNULL/errorinchild. |
| [0x177548](../recomp/config/output/sub_00177548_0x177548.cpp) | `Sofdec_finalize_global_providers_through_method_slot_one_candidate` | Confirmed complete 6-word body | Tail177560(originaltable,1).169B38passes22F148;doesnotclearproviderarray. |
| [0x177560](../recomp/config/output/sub_00177560_0x177560.cpp) | `Sofdec_call_selected_provider_method_until_null_error_or_fifteen_entries_candidate` | Confirmed complete 32-word body | Atmost15pointers;NULLterminatesnotjustskips. Eachnonnulltable[originalindex]calledwithfourzeroargs;nonzerostops/returned,otherwisenext. Initialcounter0testbeforebody,signed<15;nosixteenthload. No methodindexbounds orNULLmethodcheck. |

6 bodies / 96 original instruction words. Globalproviderregistrationandclocklifecycleareconnectedthrough169A68/169B38. The no-op body retains mechanical classification, not a fabricated cleanup effect. Statistic units require individual caller evidence. All comments match owned words; omitted aligned words zero.
