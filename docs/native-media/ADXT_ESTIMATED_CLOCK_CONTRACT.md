# Native estimated ADXT clock contract

Status: implementation contract, 2026-11-06. This boundary consumes prepared,
externally serialized queue observations; it does not own an audio device or
assert real consumed-sample timing. Original authority and frozen reference
cases are in [the original clock evidence](ADXT_ESTIMATED_CLOCK_ORACLE.md).

Reconstruct estimate, centiseconds, pause/resume, and only the already-busy
service branch of discard/rebase. Keep per-stream estimate/tick origins,
signed pause byte and RNA play byte separate from shared selection, ratio,
resynchronization count, rebase selector, service-busy word and drift bits.
Shared state must outlive its stream clocks. All access is externally serialized;
reentry must refuse before effects. No host time, frame count, guessed device
timestamp, guest address, generated ABI or runtime FP helper belongs in the core.

Use the existing integer core's actual prepared decoded-minus-queued ratio.
Keep modulo32 additions, subtractions, products, counter and tick wrap. Convert
low words to signed binary32 in original statement order; do not rewrite the
drift expression, apply an epsilon, use double intermediates, or symmetrize the
60ms test. An out-of-range drift may update the estimate origin while returning
the old estimate. Only rebase selector1 uses recursive raw mode and increments
the counter. A terminal estimate uses signed conversion without the unsigned
baseline correction used by pause/rebase. Preserve these distinctions.

Pause compares the full signed argument to the sign-extended prior byte, writes
the low byte under the observed critical boundary, and changes RNA play/tick
origin only in active states3/4. Argument1 pauses; every other changed argument
resumes. Raw-mode baseline conversion restores the previous shared selection.
Discard with pause byte0 is a no-op; otherwise its diagnostic precedes the
already-busy service critical enter/leave, then baseline/tick rebasing. A service
word0 reaches unowned workers in original evidence: refuse before effects in
this version, and retain that original partial as an exclusion.

Admit only nearest-rounding, masked exceptions, no FTZ/DAZ for FP work. Preserve
the caller's FP environment including accrued flags. Zero divisors needed by an
FP path are explicit native refusals before effects, even where original runtime
emission completes with infinity. No such refusal is original parity. Raw integer
queries can retain a zero denominator when no FP operation uses it. No allocation,
I/O, sleep, worker submission, device call or external mutable control callback
may occur in the clock transaction. Hooks are synchronous read-only observations.

Qualification requires typed state/output/control-order comparisons against the
frozen original cases with both exact compilers, explicit zero/service/FP
refusals, reentry and allocation denial, and meaningful expression-order/rebase
negatives. FPR/FCR scratch registers, raw guest write order/ABI, unowned worker
service, queue ownership and actual player/device integration remain separate.
