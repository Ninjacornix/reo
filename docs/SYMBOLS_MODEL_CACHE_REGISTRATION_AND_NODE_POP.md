# Model pointer caches and node free-stack allocation

Static resident executable SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. Five complete original intervals reviewed, including first-loop tests and sentinel writes. Values hexadecimal;2BC/40 counts mean700/64 decimal. No model allocation/loading or target execution.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1B0FB0](../recomp/config/output/sub_001B0FB0_0x1b0fb0.cpp) | `initialize_seven_hundred_model_pointer_cache_slots_to_minus_one` | Confirmed complete static cache/pool contract | Fills2BCwordslots at5698D0 withFFFFFFFF;no release/count publication. |
| [0x1B0FF0](../recomp/config/output/sub_001B0FF0_0x1b0ff0.cpp) | `register_model_pointer_in_first_minus_one_cache_slot` | Confirmed complete static cache/pool contract | Initialjump goes directlyto boundedtest. FirstFFFFFFFF among2BCslots receivesa0. Fullcache nowrite;v0 notassigned asstatus/index. Duplicates allowed. |
| [0x1B1080](../recomp/config/output/sub_001B1080_0x1b1080.cpp) | `initialize_sixty_four_motion_token_cache_slots_to_minus_one` | Confirmed complete static cache/pool contract | Fills40wordslots5697D0 withFFFFFFFF;no heap/token release. |
| [0x1B10C0](../recomp/config/output/sub_001B10C0_0x1b10c0.cpp) | `register_motion_token_in_first_minus_one_cache_slot` | Confirmed complete static cache/pool contract | Initialboundedtest then firstFFFFFFFF among40slots receivesa0;fullnowrite,no status/index assignment. Duplicates allowed. |
| [0x1B1260](../recomp/config/output/sub_001B1260_0x1b1260.cpp) | `pop_and_clear_model_node_freestack_entry_when_count_nonzero` | Confirmed complete static cache/pool contract | Signedhalf4EDD80==0 returns0. Otherwise reads pointerat4ECB70,clearsstackword,advancespointer4,count--,returnsrecord. Negativecount also pops;noorigin/stride/bounds admission. Existing1152record initializer/recycler establishesnodepool role;doesnotzeropopped190-byterecord. |

[Existing model/cache lifecycle](SYMBOLS_CUTSCENE_RESOURCES.md) owns1B1040/1110 invalidate-all-matches,1B1150 nodepool initialization,1B12C0 entire-stack-storage predicate and1B1300 recycling. These insert helpers do not free on exhaustion or report failure. Cache membership and stack-storage presence remain distinct from proven live ownership; no exhaustion/leak or slowdown was reproduced.

Audit: 5 rows, 70 verified owned instruction words; 11 omitted interval words are zero/NOP; 0 omitted nonzero words.
