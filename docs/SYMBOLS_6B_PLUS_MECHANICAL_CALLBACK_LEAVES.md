# Mechanical callback leaves and unchanged tail adapters above6B0000

Static File #1 US owned o2 analysis, 2026-11-05.23tinycompletebodies, **mechanicalcoverageonly**, noindependentgameplay-rolecredit. [Identity](FUNCTION_INDEX.md). No execution.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| Classified [o2 0x6B4B90](../recomp/config/output_ovl/o2/o2_006B4B90_0x6b4b90.cpp) | `empty_return_callback` | Confirmed mechanical only | jr ra; zero/NOP delay, no local writes. |
| Classified [o2 0x6B60D0](../recomp/config/output_ovl/o2/o2_006B60D0_0x6b60d0.cpp) | `empty_return_callback` | Confirmed mechanical only | jr ra; zero/NOP delay, no local writes. |
| Classified [o2 0x6C1BC0](../recomp/config/output_ovl/o2/o2_006C1BC0_0x6c1bc0.cpp) | `return_zero_adapter` | Confirmed mechanical only | jr ra; delay-slot v0=0; no other writes. |
| Classified [o2 0x6C2240](../recomp/config/output_ovl/o2/o2_006C2240_0x6c2240.cpp) | `tail_adapter_to625930` | Confirmed mechanical only | j625930; zero/NOP delay; arguments unchanged. |
| Classified [o2 0x6C2250](../recomp/config/output_ovl/o2/o2_006C2250_0x6c2250.cpp) | `tail_adapter_to625c50` | Confirmed mechanical only | j625C50; zero/NOP delay; arguments unchanged. |
| Classified [o2 0x6C2260](../recomp/config/output_ovl/o2/o2_006C2260_0x6c2260.cpp) | `tail_adapter_to625670` | Confirmed mechanical only | j625670; zero/NOP delay; arguments unchanged. |
| Classified [o2 0x6C2270](../recomp/config/output_ovl/o2/o2_006C2270_0x6c2270.cpp) | `retry_work10a4_tail_adapter` | Confirmed mechanical only | j6257A0; delay-slot a1=a0+10A4; originalactor a0 unchanged. |
| Classified [o2 0x6C2280](../recomp/config/output_ovl/o2/o2_006C2280_0x6c2280.cpp) | `empty_return_callback` | Confirmed mechanical only | jr ra; zero/NOP delay; no local writes. |
| Classified [o2 0x6C2D40](../recomp/config/output_ovl/o2/o2_006C2D40_0x6c2d40.cpp) | `tail_adapter_to625930` | Confirmed mechanical only | j625930; zero/NOP delay; arguments unchanged. |
| Classified [o2 0x6C2D50](../recomp/config/output_ovl/o2/o2_006C2D50_0x6c2d50.cpp) | `tail_adapter_to625c50` | Confirmed mechanical only | j625C50; zero/NOP delay; arguments unchanged. |
| Classified [o2 0x6C2D60](../recomp/config/output_ovl/o2/o2_006C2D60_0x6c2d60.cpp) | `tail_adapter_to625670` | Confirmed mechanical only | j625670; zero/NOP delay; arguments unchanged. |
| Classified [o2 0x6C2D70](../recomp/config/output_ovl/o2/o2_006C2D70_0x6c2d70.cpp) | `retry_work10a4_tail_adapter` | Confirmed mechanical only | j6257A0; delay-slot a1=a0+10A4; originalactor a0 unchanged. |
| Classified [o2 0x6C2D80](../recomp/config/output_ovl/o2/o2_006C2D80_0x6c2d80.cpp) | `empty_return_callback` | Confirmed mechanical only | jr ra; zero/NOP delay; no local writes. |
| Classified [o2 0x6C4760](../recomp/config/output_ovl/o2/o2_006C4760_0x6c4760.cpp) | `tail_adapter_to625930` | Confirmed mechanical only | j625930; zero/NOP delay; arguments unchanged. |
| Classified [o2 0x6C4770](../recomp/config/output_ovl/o2/o2_006C4770_0x6c4770.cpp) | `tail_adapter_to625c50` | Confirmed mechanical only | j625C50; zero/NOP delay; arguments unchanged. |
| Classified [o2 0x6C4780](../recomp/config/output_ovl/o2/o2_006C4780_0x6c4780.cpp) | `tail_adapter_to625670` | Confirmed mechanical only | j625670; zero/NOP delay; arguments unchanged. |
| Classified [o2 0x6C4790](../recomp/config/output_ovl/o2/o2_006C4790_0x6c4790.cpp) | `retry_work10a4_tail_adapter` | Confirmed mechanical only | j6257A0; delay-slot a1=a0+10A4; originalactor a0 unchanged. |
| Classified [o2 0x6C47A0](../recomp/config/output_ovl/o2/o2_006C47A0_0x6c47a0.cpp) | `empty_return_callback` | Confirmed mechanical only | jr ra; zero/NOP delay; no local writes. |
| Classified [o2 0x6C53F0](../recomp/config/output_ovl/o2/o2_006C53F0_0x6c53f0.cpp) | `tail_adapter_to625930` | Confirmed mechanical only | j625930; zero/NOP delay; arguments unchanged. |
| Classified [o2 0x6C5400](../recomp/config/output_ovl/o2/o2_006C5400_0x6c5400.cpp) | `tail_adapter_to625c50` | Confirmed mechanical only | j625C50; zero/NOP delay; arguments unchanged. |
| Classified [o2 0x6C5410](../recomp/config/output_ovl/o2/o2_006C5410_0x6c5410.cpp) | `tail_adapter_to625670` | Confirmed mechanical only | j625670; zero/NOP delay; arguments unchanged. |
| Classified [o2 0x6C5420](../recomp/config/output_ovl/o2/o2_006C5420_0x6c5420.cpp) | `retry_work10a4_tail_adapter` | Confirmed mechanical only | j6257A0; delay-slot a1=a0+10A4; originalactor a0 unchanged. |
| Classified [o2 0x6C5430](../recomp/config/output_ovl/o2/o2_006C5430_0x6c5430.cpp) | `empty_return_callback` | Confirmed mechanical only | jr ra; zero/NOP delay; no local writes. |

[Shared command target/retry transitions](SYMBOLS_ACTOR_COMMAND_TRANSITIONS.md) and [commandfamilyconsumers](SYMBOLS_CONNECTED_COMMAND_PHASE_AND_RETRY_ADAPTERS.md) supplycontexts. Tailtargetsarealreadyreviewed;theseleavesdonotaddindependentlogic. Emptycallbackslotsarenotunknownfunctionsemanticsrequiringinventednames, buttheyalsodonotproveasubsystemisfullyunderstood.
