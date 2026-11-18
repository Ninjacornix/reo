# EE timer-mode-gated kernel compatibility patch

Static File #1 US main ELF,2026-11-04. Two complete bodies, full eight-pair record and both copied owned payload identities. [Identity](FUNCTION_INDEX.md). No privileged call, user setting or timer was changed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x11DDA0](../recomp/config/output/sub_0011DDA0_0x11dda0.cpp) | `copy_whole_words_for_timer_mode_gated_kernel_patch_service` | Confirmed full copy loop/table role | Copies unsigned(a2>>2) forward words from a1 to a0, ignores byte remainder, returns0. Installed as selector5A by11DDE8; no overlap or alignment checks. |
| [0x11DDE8](../recomp/config/output/sub_0011DDE8_0x11dde8.cpp) | `install_owned_kernel_compatibility_payload_if_timer_mode_bit_clear` | Confirmed full gate/copy/flush/table sequence; payload internals partial | If register10001810 bit100 set does nothing. Else installs20B3A8 pair0, copies740hex bytes20AC40 to80076000 and28hex bytes20B380 to00082000, FlushCache0/2, installs pair1. For pairs2..7 fetches current entry through11DDD8 and reinstalls that selector/address. No status checks, rollback or broader capability test. |

Eight pairs20B3A8: `(5A,11DDA0),(5B,80076000),(FC,0),(FE,0),(FD,0),(FF,0),(12C,0),(8,0)`.64-byte SHA-256 `2dc1fb647bb7093cbf09da93421f0744e216754374ba72963fbd9bdb42205303`.740hex-byte payload20AC40 hash`91fea21c5fbac87ffaa363b2810520e72a916b9dcd79f35033036a548e19c914`;28hex-byte payload20B380 hash`1c2f1fe1f282c987780e310df26346b33105c89f7d6fea87a537cd0907b60def`. Hashing payloads identifies source carriers; their internal routines are not credited as decompiled semantic functions by this note.

Two bodies /66 instruction words. Boot [11D908](SYMBOLS_EE_KERNEL_PATCHING_TLB_AND_SYSCALL_LOOKUP.md) invokes this before timer initialization. The single MMIO-bit gate is retained literally; no console model, firmware version or active host behavior is inferred from it. All owned comments match; omitted aligned words are zero.
