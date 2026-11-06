# Native audio service group contract

This cut reconstructs the complete scheduling/dispatch envelopes at File1
`132C08`, `12D678`, `134C58`, `12C798`, `13EEE8` and the no-op `1347F8`.
It does not relabel their opaque decoder, playback, file-tail, RNA or transfer
children as implemented. Original owned words remain authoritative.

The outer CRI guard is entered before checking the shared service word. Any
nonzero word returns through guard leave. Otherwise publish1, leave, reenter,
service all16 decoder slots, publish2, service all16 stream slots, publish3,
enter the RNA guard, service all16 RNA slots, leave RNA, service DTR then DTX,
clear the shared word and leave CRI. The16-slot tables are independent; their
indices need not correspond. Only signed activity byte1 is admitted.

Tables are visited live in ascending index order, never from a precomputed
active list. Each active stream reads its phase once:1 ready,2 buffering,
3 playing,4 draining,5 no-op, other signed byte values no phase work. Input-end
propagation then error propagation always run for the same retained stream,
even if the phase callback changes its activity/phase or table membership.
No changed phase is dispatched again in the same visit.

The native owner retains strong per-call child references. A callback can replace
or clear later table entries under the serialized control owner; those changes
are observed when their index is reached. Removing the current entry cannot
destroy the in-flight object. No allocation occurs in service traversal. It
neither joins sources nor invokes device callbacks. Child methods are noexcept;
their own pending/error state is retained by their owners, not turned into an
unproven short-circuit of the original group sequence.

The service word is the retained shared clock context's actual service_busy
word, not a fabricated busy override for clock admission. Clock in_call is a
separate prepared-operation guard. The group does not hold it through child
calls. Child-triggered recursive service performs the original guard/check/
leave early-return sequence and preserves the outer service phase. Guards
provide synchronization only; they must not call user callbacks themselves.
One externally serialized control owner governs tables, clocks and children.

Actual source/file polling is outside these envelopes. Port-only comparisons
establish dispatch/ordering, not a working global audio pipeline. Production
selection requires owned phased decoder/player/RNA children, file polling,
bank/packet integration, clock service consumers and controlled media validation.
