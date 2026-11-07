# Native movie audio time filter

Status: isolated native filter implemented and compared on 2026-11-07. Both
compilers match all 641 snapshots (67 constructors and 574 stateful operations)
from 561,990 original instructions. The selected-clock owner still uses declared
providers; the real `165C08` ADXT/counter binding remains required. See the
[implementation and qualification](../../game/native/movie_audio_filter/README.md).

Reconstruct the complete `177EB0` state machine, history operations and relevant
configuration/reset operations. Execute actual `10FAA0` low64 multiplication,
`10FB18` signed division, `177D90`, `178318`, `178378`, `1783D8` and the original
memory-clear body. Freeze original outputs before native filter code. Include
the constructor when its complete helper closure is available. The initial
profile keeps the optional CSV buffer null, executing the actual no-buffer
branch of `178440`/`1785A0`; it does not claim formatting/software-double parity.

Pairs use raw 64-bit numerator/denominator lanes. Helper denominator exactly one
or enabled zero bypasses filtering without updating state. Otherwise preserve
signed maximum input clamping, exact-one pause, distinct zero/nonzero/exact-one
adjustment modes, first/later activation offsets, anchor transitions, cold-zero
history, signed word averages, quantized half-step correction, previous-output
raw-numerator clamping and all counters/error extrema. These are source rules,
not a generic rational-time or wall-clock discipline.

Keep low64 products, modulo word/doubleword arithmetic, signed division truncation
and low32 narrowing explicit. Do not introduce floating-point rounding or change
the game's sample rate. Bound the owned history to its actual 60 entries and
declare admission for index/counter/numeric cases before effects. Preserve source
input mutations as well as output and filter state. Undefined divisions, BREAKs,
out-of-range history or aliasing must be recorded as exclusions/refusals, not
replaced with guessed outputs. No fallback may occur after partial publication.

The native state must use ordinary typed fields and fixed owned storage, without
guest offsets/register files or a second guest RAM image. It receives actual
ADXT and helper-clock observations through owned interfaces. Preserve provider
identity, lifetime, pause/reset order and edition/build qualification when binding
the filter to the selected movie clock. Rendering/display counts are not either
clock source. Real timer ownership and the complete `165C08` envelope remain
separate until independently validated.

The verification engine may add the minimum generic instructions needed for
the actual original memset, with independent vectors first. PCPYH, PCPYLD and SQ
semantics are reviewed against Sony's primary [EE Core Instruction Set Manual,
v6](https://docs.alexrp.com/mips/ee_insns.pdf), printed pages 189, 190 and 287:
halfword replication is per 64-bit half, lower-doubleword combination preserves
source order, and SQ masks the effective address's low four bits. Unknown upper
halves must remain unknown until established. This is verification tooling;
it does not enable a new game rendering/VU path.

Movie due/skip, pause/buffering, construction/reset, frame/source lifetimes,
shared guards and actual game/media transitions still gate stage 3. Stages 4–6
remain required.
