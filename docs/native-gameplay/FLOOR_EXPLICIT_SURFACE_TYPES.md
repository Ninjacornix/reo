# Explicit floor surface types

2026-11-09: corrected native `response::floor_at`; not installed in the game.
The previous generic floor qualification did not exercise explicit high-bit
types. Its claim remains bounded to the recorded cases.

Original617000 at6170B0–6170DC distinguishes two paths. A generic255 request
rejects triangle flag80. An explicit matching type jumps past that exclusion.
The earlier native predicate applied both conditions and therefore rejected
every explicit81 water query used by the actor surface-effect callback5EA970.
The corrected predicate retains the generic exclusion and admits the matching
explicit type.

Fresh LLVM/GCC v8 comparisons each pass270963 checks, all366 owned grid assets,
and all65536 combinations of triangle type/request bytes. Original617000 and
its point-in-triangle bodies are word-audited against the owned overlay; vector
math and cell selection remain declared oracle surroundings. Both runs report
zero maximum contact error. Source copies and receipts are retained privately;
the structured qualification records their identities. This is offline behavior
evidence, not a runtime slowdown reproduction or a Stage4 completion claim.
