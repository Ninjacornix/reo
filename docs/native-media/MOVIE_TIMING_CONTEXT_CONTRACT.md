# Join the native movie timing owners

Implemented prepared integration boundary: one prepared live movie timing context joins fresh
clock construction, selected/cache authority, the audio slot/filter, pause and
buffering control, requested-picture publication and picture admission. Freeze
stateful original workflows before implementing this context. This is not the
whole movie constructor, source parser, decoder, frame-return path or stop/rebuild.

The original runner must execute all owned numeric/controller bodies together,
using the normal main/clock/filter/audio-child relation. Keep actual ADXT
estimator and helper-counter observations, full buffer predicates in the initial profile, component
commands and error handling as explicitly declared ports. The complete buffering
profile described below replaces those predicate ports. In particular, a
prepared component command port does not secretly execute real audio/video
pause. Record that obligation rather than claiming whole media equivalence.

Clock counters, pending work and selected cache have one authoritative owner.
Pause nesting/episodes and admission tracking remain distinct owned fields.
Use typed, bounded control patches to synchronize controller boundaries;
reject busy/invalid patches before effects. Do not write old complete snapshots
over callback effects. Queries performed from an admitted component callback
must observe pause/step state already published before that callback.

The selected and buffering controllers must share the same retained optional
guard state. A buffering command can synchronously query the selected clock
while guard depth is already nonzero. Two unrelated per-controller depth/tag
copies cannot reproduce that call. Qualify paired pure serialized hook behavior,
including nested calls and initial nonzero depths; do not infer global scheduler,
thread priority or arbitrary reentry correctness from it.

Context operations retain themselves and their providers during callbacks.
Only explicitly qualified nested queries may reenter; mutations and retirement
must fail busy before effects. A timing-context detach is not a movie/source/
device/frame fence. Actual source retirement, provider completion and GPU frame
returns remain independent obligations before live stop/rebuild is implemented.

Properties and actual/requested state observations in this prepared profile are
inputs from their still external owners, not a native replacement for original
property admission or the movie start/end state machine. Preserve the different
property-E policies of `176F68` and `177028`, raw statuses and opaque scratch.
Native code must contain typed state and ordinary interfaces, with guest layout
conversion restricted to the verification fixture and eventual temporary adapter.

After this join passes original workflows and real native source/estimator tests,
continue through complete buffering/skip/publication predicates, component pause,
source/frame ownership, stop/rebuild and coherent game/media transition tests.
Stage 3 remains open until those are validated. Gameplay, graphics/platform
migration and complete compatibility removal remain stages 4–6.

## Complete buffering profile

`Config.buffering` or `observe_buffering` supplies a retained, typed buffering
owner. Its predicates run inside the existing pause controller and shared guard;
they query the same authoritative cached clock. Component commands and errors
remain explicit external boundaries. Movie facts are stable during these calls:
queue/helper callbacks may not mutate movie properties or reenter the Context.
This is a serialized profile, not qualification of the original global scheduler.

The complete original `172CF8`, `172E78`, `172F58`, `172FF8`, and `1730B0` bodies
establish distinct pause and resume rules. Property F is the clock selector,
not a separate boolean. Nonzero video/audio settings gate component completion;
exactly-one settings gate stalls, peeks and refill checks. Every stream end flag
can release buffering. Pause requires actual state 4, no user pause, and positive
current and adjusted horizon numerators; resume has no positivity restriction.
Margins are signed microsecond ratios with low-word subtraction. Refill computes
wrapped 32-bit capacity times 80 before signed division by 100. Only video has an
absolute refill fallback. These details must survive integration.

Pause peeks fixed streams 2 and 0; refill uses separately selected video/audio
indices. Disabled or absent peek queues report zero without a guard or call;
missing refill providers and out-of-range selected slots refuse instead of
inventing queue counts. Peek uses at most two spans, not total availability.
`UniBufferQueue` and `RingBufferQueue` retain actual native queues. The former
also retains the supplied region catalogue/source owner. No released payload
pointer escapes: copy lengths and return second then first. All producers and
observers must use the same external serialization. The shared movie peek guard
is paired even on provider refusal. Queue-core hooks must be pure and nonthrowing.

A refused predicate preserves buffering flags, nesting and episode counts while
retaining earlier measured clock effects. It does not dispatch pause/resume.
A Context detach still does not retire source workers, audio devices or frames.
Complete skip/frame publication, audio/video command binding, full construction,
stop/rebuild and coherent game integration remain stage-3 obligations.
