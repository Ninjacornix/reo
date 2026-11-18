# Original EE cache range synchronization

Static File #1 US research, 2026-11-04. Original **SLUS_207.65**, SHA-256 **06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46**. Complete original bodies reviewed; no cache instruction or game executed. Labels retain literal cache operation numbers rather than assuming a native equivalent.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x114E70](../recomp/config/output/sub_00114E70_0x114e70.cpp) | `scan_EE_data_cache_ways_and_apply_opcode14_to_inclusive_address_range_candidate` | Confirmed full tag scan and operations | For line-index0..FC0 step40, scans both ways via cache10(index+0/index+1), sync and CP0TagLo. Reconstructs address=(TagLo&FFFFF000)+index; unsigned inclusive a0<=address<=a1 triggers cache14 for that way, surrounded by sync. Scans all64 indices/two ways even for narrow or empty ranges. Cache14 architectural meaning/native implementation is not inferred from its numeric identity alone. |
| [0x114F18](../recomp/config/output/sub_00114F18_0x114f18.cpp) | `guard_and_align_EE_cache_opcode14_range_scan_candidate` | Confirmed full wrapper and lower callee | Saves CP0Status bit10000. If set, calls11D660; masks both input bounds down to64-byte boundaries; calls114E70; if saved bit set, tails11D6B8. Preserves original conditional critical-mode restoration. No reversed-bound check or native cost measurement. |
| [0x114FB0](../recomp/config/output/sub_00114FB0_0x114fb0.cpp) | `scan_EE_data_cache_ways_and_apply_opcode16_to_inclusive_address_range_candidate` | Confirmed full independent body | Same two-way tag reconstruction and unsigned inclusive bounds as114E70, but cache16 replaces14. Complete catalogue interval reviewed separately. Different cache operations must not be collapsed because the loops look alike. |
| [0x115058](../recomp/config/output/sub_00115058_0x115058.cpp) | `guard_and_align_EE_cache_opcode16_range_scan_candidate` | Confirmed full paired wrapper | Same saved Status10000 and11D660/11D6B8 conditional bracket, aligns both bounds withFFFFFFC0, calls114FB0. DTX uses it before observing payload and around submission. Native synchronization needs current override/runtime evidence, not direct replay of console cache semantics. |

Addresses, masks, offsets and cache opcodes are hexadecimal except spelled counts. These are original console implementation roles, not a claim that native recompilation executes a hardware cache scan or that these functions caused any recorded slowdown.

Related: [DTX sequence and DMA contracts](SYMBOLS_CRI_DTX_TRANSFER_CONTEXT_AND_ACKNOWLEDGEMENT.md), [central index](FUNCTION_INDEX.md).
