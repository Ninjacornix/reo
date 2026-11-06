# Native audio group dispatch evidence

The native dispatcher now matches **81 independently authored original-code
cases**, using 31,169 executed original instructions. GCC 15.2 and bundled
LLVM 21.1.8 agree on every ordered child/guard event, observed service word,
guard depth and final activity/phase table. **Stage 3 remains in progress.**

The [contract](ADXT_SERVICE_GROUP_CONTRACT.md) covers original `132C08`,
`12D678`, `134C58`, `12C798`, `13EEE8` and no-op `1347F8`. Exact owned ELF
words are checked against generated-source comments. Child decoder, ready,
buffer/play/drain, input-end, error, RNA, DTR and DTX operations are explicit
opaque boundaries. This evidence establishes their dispatch/order, not their
complete native integration or the original hardware/priority scheduler.

The original input freeze predates the native implementation. Cases include
all slot positions, signed activity bytes, unsupported phases, every nonzero
busy phase, later-slot activity/phase changes and actual original early-return
execution on child-triggered recursive service. Phase is loaded once per stream;
its input-end and error tails still run if the child changes its phase/activity.
The three16-slot tables are independent. No precomputed active list is used.

Native ownership tests additionally clear the current table entry from inside
its own phase callback, proving that the current child survives through both
tails. They replace a later slot before its visit, check invalid slot rejection,
the shared-clock busy word, independent table indices and allocation-free service
traversal. Both parent Release CTest targets pass. The standalone project now
registers45 suites; this is not a migration percentage.

Three compiling negative controls differ from original execution as required:
accepting any nonzero decoder activity differs1 case, reversing the two stream
tails differs41 cases, and publishing phase2 before decoder service differs29
cases, identically under both compilers.

The first original replay completed the81 cases but failed when writing its
receipt because its helper hashed a Path object rather than its bytes. Its
freeze, helper and raw rows remain under `original-freeze-v1`/`original-v1`.
Only that receipt-hash expression changed before the second pre-native freeze;
no inputs, instruction semantics or child return values changed.

| Artifact under build-native-sjuni/adxt-service-group | Receipt SHA-256 |
| --- | --- |
| original-v2 | `d5ca28253b16b28e1b9f67cd6a4aed25fd0ffba71279cfec7f2f51be51cbda8a` |
| qualified-gcc-v1 | `9082ca27ae8748c51f516f8a1727456f58d5290b67c0a7c13b1842122c251bd3` |
| qualified-llvm-v1 | `3c64d26568672af65c4bbc93eea8a29009034d1e0593749eeb3d99d98ea4d590` |

The checked-in qualification pins source and parent-build identities. The
prepared clock's unowned discard/service branch still refuses: this generic
group must first own actual phased children. Setting a busy word to bypass it
would not complete that integration. File polling is elsewhere. DTR's original
group itself scans32 slots then services DTX; the subsequent DTX facade services
DTX again. Binding each generic boundary to a single pump would lose this order.
The actual transfer children, bank/packet path, LSC, movie consumers and game
transitions remain open. No game ran or audio device opened for these checks.
