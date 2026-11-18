# Native AI observation admission

2026-11-10: complete812EF0 and813BD0 now use canonical Actor execution state
and Session RNG. They are components of observation production; the full812540
consumer and6D6240 cache rebuild remain open. V39 is unchanged and Stage4 is
incomplete.

The blocked-state predicate preserves the broader motion and auxiliary04030000
mask; it is distinct from823190's target-busy predicate. The reaction admission
helper uses eight authored character probability columns, both canonical1077
weight-mode bytes and exact FP32 scaling factors. Multiply order and toward-zero
conversion preserve the finite source calculation. Mode0 requires the reference
Actor execution component. Every nonzero mode first checks the same room_memo
and107E gate, then uses the room chance column. A failed room chance writes the
actual room_memo; no unrelated actor state changes.

Chance>=100 consumes no RNG. Lesser positive probabilities consume one actual
Session draw and use inclusive modulo100 comparison, but a zero random word
rejects first. Characters8..255 have no authored chance columns and refuse when
those columns are needed. Early room/memo gates remain available without them or
a reference actor. Missing components/identities refuse explicitly.

Both compilers pass400,434,754 identical checks, including2,887,680 complete
admission comparisons,2,363,390 identical RNG draws and278,784 complete blocked
predicate comparisons. All65,536 initial RNG values, eight characters, four
scaling combinations, all65,536 room values, equal/unequal memo/gate combinations,
byte mode values and actor aliases compare.499 native capability refusals are
separate from the original comparisons. Whole actor ranges preserve unrelated
state. Twelve parent tests pass per compiler, including actual World reference
selection, shared RNG, repeated room suppression, zero RNG and retirement/closure.
`native_gameplay_ai_observation_gates_qualification_v1.json` seals the evidence.

The test fixture freezes the current dependency conversion header for original
CVT.W.S. Native production uses bounded finite C++ conversion and no original
register/memory model. No game launch or performance measurement was used.
