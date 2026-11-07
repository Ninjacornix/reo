# Movie pause and buffering controller

Implemented independent typed cut, File #1 US: complete public pause `1720C8`, nested
transition `172158`, requested-state forwarding `1721E8`, component route
`172250`, buffering controller `172C48` and mode-2 clock step `176D08` with its
actual ratio helpers `176DE8`, `176D68`, `176DB0`, `15BA80` and `10FB18`.
See [implementation and qualification](../../game/native/movie_pause/README.md).

Do not normalize raw pause words, clamp nesting depth or turn frame steps into
host sleeps. Public pause validates the original nonzero actual state, derives
transition 0/1/2 from old/new nonzero pause words, stores the new pause before
forwarding and sets pending after the child returns. Repeated zero is a no-op.
Nested mode 1 increments modulo32 and forwards only at new depth 1; mode 0
decrements modulo32 and forwards only at new depth 0. Mode 2 forwards only in
actual 4. Forwarding requires requested state 3 or 4, performs clock work first
and then sends target 7 / command 8 / raw mode / null extra to the component.
Preserve the child's raw returned status and any intervening state updates.

Mode 2 uses the owned nine-entry picture-rate table. Rate code 0 yields
0/29970; other admitted codes yield 1000/table[code]. The actual signed product
and quotient are narrowed to words. Add the global-frequency scaled step to
both running and auxiliary counters, regardless of their old sentinel values;
separately add the external-denominator scaled step to external accumulation.
Other modes perform no clock writes. Reject an out-of-range rate before effects
in the typed core; do not reproduce an unchecked table read.

Buffering control enters/leaves the actual optional CRI guard chain. An inactive
buffering flag invokes the pause predicate; a nonzero reply sets the flag to 1,
increments episodes modulo32, then applies nested mode 1. An active flag invokes
the resume predicate; a nonzero reply clears the flag before nested mode 0.
Keep requested/actual/pause/depth/buffering/pending/counters distinct.

At this cut, complete buffer predicates, component dispatch and invalid-handle
error handling are declared provider ports, with argument/state observations and
explicit scripted side effects in the original corpus. They are not no-ops and
do not constitute a native stream-readiness or whole error subsystem. Guard
evidence initially uses isolated paired pure hook profiles, not shared scheduler
or thread-priority authority. Native provider failures must retain effects
already published before failure and expose diagnostics; no blind old-snapshot
commit or original fallback is permitted after callbacks.

Freeze original executions before native code. Include zero/nonzero and signed
boundary states, nested overflow/underflow, repeated pause, raw modes, callback
status/side effects, all rate codes and guard depths. Keep the native state typed
and owned, without guest offsets, simulated registers or a second RAM image.
Real movie construction, provider binding, complete buffering/due/skip predicates
and frame/source lifetime still gate stage 3. Stages 4–6 remain required.
