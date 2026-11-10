# Native Session activity-mode query

2026-11-10. The complete activity-mode query and its control-receiver binding
are qualified components. Stage4 remains incomplete; installed gameplay is V39.

The existing Session.mode/World.mode alias selects the policy. Mode0 reads the
canonical signed single-mode byte; mode1 reads the distinct signed online-mode
byte. All other main modes return1 without reading either value. Native Session
stores those two facts as optional values until their actual initialization or
network producer supplies them. Unknown does not mean zero.

Control reception now calls this shared native query through its actual Owner,
instead of taking a separate scalar mode argument. Value-only updates and empty
owner batches can proceed when mode state is unknown; an owner update that needs
the missing fact remains unavailable.

Both compilers pass75155916 identical checks. The complete original1AFE70,
1B0300, o9 811770 and o8 810F30 chain executes4086138 queries, including65536
explicit combinations covering all256 main-mode bytes and all signed-byte
values. The original1AFE70 return substitute has been removed. Only the earlier
profile-selection eight-byte clear remains a declared surroundings port.

The merged generated1B0300 file contains neighboring entries as well. Its entire
file remains word-audited, but only1B0300 is entered or claimed in this chain.
Both parent builds and twelve integration tests pass. Actual Owner checks verify
the shared Session fields, signed returns, constant fallback, selective unknown
admission and closure. All previous AI/control comparisons retain their counts.

Evidence: `gameplay-ai-activity-{llvm,gcc}-v1/receipt.json`, corresponding parent/
test logs and `native_gameplay_activity_qualification_v1.json` (SHA256
`13cd9682d4a0a209b1ef341c63e9208ead14d33385725f51473e93dcb236f61f`).

Actual mode initialization/network writers, control service/frame reset, full
AI initialization/observations/goal/action dispatch, input/network/save ownership
and coherent native gameplay installation/acceptance remain open. No game was
launched or performance change measured for this work.
