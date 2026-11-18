# Native pending movie service and transitions

`game/native/movie_service` reconstructs prepared File #1 US `1725E0` pending
service, `1726F8` prepass and connected state handlers through `172BE0`, source
availability/default selection, and `173210` completion composition. Native
records and explicit providers have no guest-memory, runtime, graphics, device
or file dependency.

One visit requires actual state 1..4 and nonzero pending. Pending clears before
the first counter call. Initial states 2..4 broadcast then update shared state;
actual is reloaded afterward. Callback changes to actual/requested and newly
scheduled pending work survive according to original saved-local ordering.
State 4 tests completion transition and buffering before request 6. The start
provider's status does not undo original state 4 publication. Source flags use
literal equality with 1; completion combines raw cached words; signed-negative
shared source flags latch once. Counter differences retain 64-bit wrap.

This prepared record owns two shared source flags. Optional external shared
object absence, global registration, pointer validation, error callbacks and
undefined original return registers remain outside this core. The API returns
no invented success. Declared ports are counter/statistics, broadcast, shared
update, source extent/requested count, start, completion transition and buffering.
Scripted comparisons do not establish real provider behavior or game ownership.
Service does not advance clocks per packet, pump, display frame or UI event.

The owned `SLUS_207.65` SHA-256 is
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
The oracle executes complete connected bodies, the original seven-entry table,
property setters/getters and cached component loads. Only declared external
ports are scripted; every callback argument and entry state is retained.
Both worker compilers produce identical original results: 515 cases, 518
operations, 1,523,025 instructions each. LLVM reference generation began before
native `service.cpp` existed; later GCC repetition records that it existed.
Neither reference calls native code.

Native comparisons check 3,481 ordered state/event rows with zero differences
on both compilers. Five deliberate faults are detected: clearing rescheduled
work, using stale state, omitting shared work, inferring readiness and ignoring
a completion transition. V1's original harness failed due to missing provider
registration in the interpreter transfer loop; its source/failed receipt remain
retained. V2 fixes that declaration without changing owned bodies.

| Receipt below `build-native-sjuni/movie-service` | SHA-256 |
| --- | --- |
| `original-llvm-v2/receipt.json` | `e0baefa615e2078fb38fb76f2114b2ace1e8caf164647c49ed8fa4ad69b3e9ca` |
| `original-gcc-v2/receipt.json` | `810896fdde954b25fc9b1a1b56249b07bccae79d6cfb11b3999b4cf83fd9ebc5` |
| `qualified-llvm-v1/receipt.json` | `01c9931b3ade5a058a9939db70b1122c880726c8422d247223a8fca404d57abb` |
| `qualified-gcc-v1/receipt.json` | `095ed8ccbcc855a95ca9b893afada52472c1c3ba3edf34fc3b74b5b01dfa564e` |
