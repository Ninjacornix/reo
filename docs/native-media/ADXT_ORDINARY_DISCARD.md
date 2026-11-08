# Ordinary ADXT serviced discard binding

The private ordinary adapter now includes `133058`, used by the movie audio
frame-step command. The second guest argument is unused by the original body.
It is not a seek request or a consumed-sample count. The successful original
return is zero, including the paused branch's retained RNA diagnostic result.

The new entry uses the same mapped instance, canonical source owner, qualified
Session discard/service/rebase and actual aggregate voice permutation. An
unpaused source does not service the group. A nonzero pause byte, including
`2`, invokes the actual native group before rebasing from fresh queue facts.
Source workers are not additionally polled by this operation. A private output
callback can continue rendering peers; the operation does not retire their
sources, reset the aggregate or seek the input.

The adapter mirrors the resulting per-source clock fields and shared drift/
resynchronization fields. Native control refusal stops the private candidate
with a `discard-rebase` boundary diagnostic. There is no original fallback after
native effects. A handle without a matching active native source keeps the
ordinary adapter's existing forwarding policy.

The existing original serviced-discard comparisons cover the arithmetic and
service envelope; see [the implementation evidence](ADXT_SERVICED_DISCARD_IMPLEMENTATION.md).
The new ABI workflow separately checks no group/diagnostic visit while unpaused,
one visit for pause `1` and `2`, zero return despite distinct large arguments,
fresh clock/tick publication, continued peer consumption and complete finite
PCM baselines. Its original guest/runtime/factory functions remain declared
ports. It does not establish actual in-game frame stepping.

The first new negative-control design removed the native call but left unused
lambda parameters under `-Werror`. Both compilers refused that mutant at compile
time. Those failed runs remain in
`build-native-sjuni/adxt-binding/ordinary-discard-{llvm,gcc}-v1`; that failure is
not credited as detection of the runtime omission. The repaired design consumes
those parameters and must compile before its behavioral result is accepted.

The repaired V2 runs pass all 16 adapter scenarios and detect all four runtime
faults with both compilers. Both actual SDK130 cohorts compile all four adapter/
handle/source/factory objects. The native archive bodies remain unchanged;
their 77-suite qualification is retained rather than claimed as a new run.
The [follow-up qualification](../../tools/native_reconstruction/adxt_ordinary_discard_qualification.json)
identifies the exact source and receipt hashes, including the failed V1 runs.

V18 was sealed from `f4295d04` before this additional entry. Its game run cannot
prove execution of this addition. Step 3 remains open.
