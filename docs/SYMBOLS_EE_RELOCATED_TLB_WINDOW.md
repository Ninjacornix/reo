# Copied kernel TLB window service

Static File #1 US owned ELF,2026-11-05. Complete body and its relocation context; [identity](FUNCTION_INDEX.md). No kernel code executed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x209FB0](../recomp/config/output/sub_00209FB0_0x209fb0.cpp) | `map_or_remove_two_page_kernel_tlb_window_at_70004000` | Confirmed complete copied-body contract | Carrier relocates to800751A8. Rejects unaligned a0 and unsigned(a0-1)<=FFFFE; therefore admits zero or aligned addresses>=100000, without an upper memory bound. Calls80075158 to probe70004000. Missing mapping plus zero returns0; missing plus nonzero allocates current Wired index and increments Wired without a local48-entry bound. Existing plus zero decrements Wired and replaces that index with PageMask0,EntryHi E0010000+((index-1)<<13),zero EntryLo pair. Nonzero maps a0 and a0+1000 with EntryLo=(page>>6)|1F,PageMask0,EntryHi70004000; returns selected index. |

This is source209E08[330hex] copied to80075000 by [11CF08](SYMBOLS_EE_KERNEL_PATCHING_TLB_AND_SYSCALL_LOOKUP.md), SHA-256 `3812e2924e67b94a294d790deee44b51e4ee7b6eb2bb9aa9899380ce006cd5a2`. J/JAL high bits must be interpreted at the copied PC; generated low075xxx targets are not resident game functions. Probe helper source209F60 is supporting evidence only, with no independent reviewed-function credit here. One body /74 words, owned comments checked. Permissions, actual kernel mapping state and host replacement behavior remain untested.
