# SRD request counters and current I/O breadcrumb queries

Static File #1 US resident ELF, 2026-11-05. Owned SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. Complete original catalogue intervals and branch delay slots reviewed against owned words. Source-only; no file/audio/RPC/game/build execution. Offsets and unmarked constants hexadecimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1381E8](../recomp/config/output/sub_001381E8_0x1381e8.cpp) | `get_SRD_terminal_and_cancel_transition_counter` | Confirmed complete local role; original public name candidate | Returns21BBE4.1379D0/137BA0 increment on cancelled/reset requests and transitions out of state2 to terminal outcomes;137738 can also increment after synchronous completion. Thus not solely successful-completion count and not elapsed-time metric. |
| [0x1381F8](../recomp/config/output/sub_001381F8_0x1381f8.cpp) | `get_SRD_accepted_disc_or_file_read_submission_counter` | Confirmed complete local role; original public name candidate | Returns21BBE0. Disc101788 result1 and host read1385D8 nonnegative acceptance increment it and enter state2. Acceptance is not completed bytes, sectors or successful final outcome. |
| [0x138228](../recomp/config/output/sub_00138228_0x138228.cpp) | `get_SRD_current_IO_breadcrumb` | Confirmed complete local role; original public name candidate | Returns21BBF4, whose existing138208 setter first copies prior value to21BBF0. No atomic paired history read or timestamp. |

[Existing CRI request workers](SYMBOLS.md) contain the already indexed1379D0/137BA0/138208 entries. The two counter roles follow exact write sites in those workers rather than naming arbitrary increments as locks or frame counters. In particular21BBE4 counts more transitions than successful reads, and21BBE0 records accepted submission before completion.

No runtime counter value, storage stall or diagnostic report was captured during this static pass. Getters do not themselves pump workers or request RPC.

Audit: 3 bodies, 12 owned instruction words matched; 0 omitted zero/NOP words, zero omitted nonzero words.
