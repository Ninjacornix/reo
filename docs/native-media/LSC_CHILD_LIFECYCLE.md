# Original LSC child construction and reuse

Status: owned-instruction observations and adapter constraints. This does not
install an LSC game binding or establish native playback equivalence.

The independent oracle executes 11,358 original instructions across 42 cases
and 93 allocation/construction/attachment/destruction operations. A separate
verifier checks 358 constraints. The owned ELF and generated instruction
comments are cross-checked by the existing authority reader. Stream counts,
critical sections, diagnostics, memory clearing and lower asynchronous stop are
explicit ports. No game, original scheduler, decoder or device is run.

`13CB50` scans sixteen children starting at `21E110`, with stride `238` hex
(568 bytes). It returns the first child whose active byte is zero, or null when
full. Allocation alone does not reserve that child. This pool is independent of
the C4 table; do not infer that C4 and LSC slot numbers match.

`13CBB0` constructs a child for a supplied stream interface. Null input reports
a diagnostic and returns null before entering the critical section. Otherwise
it enters the original critical helper, allocates, stores the stream at child+8,
and calls the stream vtable at +24 twice, with list selectors 0 and 1. Their
32-bit sum becomes capacity at child+18; the signed wrapped result of shifting
that sum left three and dividing by ten becomes minimum at child+14. The
8192-byte profile yields 6553. Large/negative synthetic counts demonstrate
original wrapping arithmetic; they do not authorize a native allocation.

Construction clears state byte +1 and sixteen **status** words at
child+`50 + slot*20` (hex). The status query `13D228` reads that same offset.
It does not clear all records or initialize every other flag. A deliberately
poisoned free child retains repeat/pause/transfer bytes and sequence fields,
while all sixteen status words clear. Normal BSS construction or the completed
original destructor supplies zeroed storage; this negative case is not evidence
that poisoned children are reachable during ordinary play.

`13CD08` attaches the lower file by storing its argument at child+28. The actual
ADXT constructor calls `13CBB0` at PC `1317C0` with C4+10, stores the result at
C4+94 in the branch delay slot `1317CC`, and later attaches C4+8 through
`13CD08` at `1317E4`. Future binding must validate these links and retain a
generation-scoped child identity rather than treating a pointer as authority.

`13CCB8` accepts null without effects. For a real child it calls `13CF78`, clears
the active byte and clears all 568 bytes through the original memory-clear
boundary. Stop requests the lower asynchronous stop only when child state is
nonzero, a lower file exists and transfer byte +2 equals exactly one. This is a
request, not completion of a native worker. The adapter must fence native output
and join accepted native source work before permitting original storage reuse.
Destroy/reconstruct observations return the same first-free address after the
full clear, while full-pool construction keeps the table unchanged.

One remaining integration gap is the minimum threshold. The actual LSC start
wrapper reads signed C4+3E, shifts by eleven and calls `13D358`; the native live
input currently admits only its default 6553-byte threshold. Existing queue
control semantics alone do not close that live-source admission gap. Broader
source restart, callbacks, queue queries and the complete game service order
also remain required.

See `tools/native_reconstruction/lsc_lifecycle_qualification.json` for exact
source and private observation receipts, and
[the game binding boundaries](LSC_GAME_BINDING_RESEARCH.md) for consumer PCs.
