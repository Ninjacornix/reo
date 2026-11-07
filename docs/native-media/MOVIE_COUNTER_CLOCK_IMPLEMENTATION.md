# Movie counter and built-in rational query evidence

The native core implements complete admitted counter, predicate, rebase and
built-in query paths through nine owned original File #1 bodies. The original
`175E50` actually executes both predicate children, `175F20` executes its actual
property getter, and built-in queries execute the actual state-admission child.
The getter is exercised for property `0x47`; a general property-table API is not
claimed. No original instruction is replaced by a hook supplying a clock answer.

Two separate counters retain their source gates: active counter requires actual
state 4 with explicit and buffering pause words zero; elapsed counter requires
its raw value to differ from -1 and requested state 4. Additions wrap modulo
32 bits. An admitted zero increment still produces the original write effects.
Rebasing selects active or external accumulation using property `0x47` exactly
equal to one. It writes elapsed origin without sampling time or changing the
elapsed counter.

State admission accepts exactly 4, -4, 6 and -6. Failed admission writes -1/1;
the unavailable built-in writes -2/1; the counter built-in preserves the actual
raw shared frequency, including zero. Eligible contextual queries leave both
supplied output words unchanged. Defined return values and ordered write effects
are compared separately from undefined scratch returns.

The original corpus was frozen before the first native implementation: v1 had
408 cases, then v2 added six explicit paired-counter/write cases before native
code existed. The first native comparison failed because my initial contract
and fixture varied callback selector property `0x0F` instead of rebasing property
`0x47`. Original reads identified offset `0xABC`, and the owned call delay slot
at `175F34` supplies literal `0x47`. The failed candidate, verifier, contract and
original inputs are preserved under `build-native-sjuni/movie-counter-clock/failed-v1-inputs`
and `qualified-{gcc,llvm}-v1`.

The corrected original-only v3 corpus varies properties `0x47` and `0x0F`
independently. It contains 504 cases and 11,481 original executed instructions.
It records that a native candidate already existed and pins that still-incorrect
candidate before the correction. These expanded expectations are not described
as entirely pre-native. Source words and the existing instruction engine remain
unchanged; the correction changes the declared fixture property and native API.

Both GCC 15.2 and pinned LLVM 21.1.8 match every admitted original state result,
raw rational word, defined return and ordered selective write. Original memory
guard bytes and actual lower64 callee-save/stack restoration are checked. Five
counterfactuals detect ignored buffering pause, elapsed-counter gating by actual
state, treating any nonzero property as one, initializing eligible contextual
outputs and normalizing a zero frequency. Seven native boundary checks also cover
invalid-operation refusal before effects. There is no allocation or floating-point
arithmetic in the core.

This is not a full movie controller, selected-clock callback implementation,
cache, ADXT audio filter, due/skip policy, GPU producer/consumer binding or actual
game test. Tick-event frequency and source ownership remain obligations of the
future movie owner. It does not establish a stutter cause or performance gain.
Stage 3 and stages 4–6 remain open.
