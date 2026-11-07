# Join the native movie timing owners

Next integration boundary: one prepared live movie timing context joins fresh
clock construction, selected/cache authority, the audio slot/filter, pause and
buffering control, requested-picture publication and picture admission. Freeze
stateful original workflows before implementing this context. This is not the
whole movie constructor, source parser, decoder, frame-return path or stop/rebuild.

The original runner must execute all owned numeric/controller bodies together,
using the normal main/clock/filter/audio-child relation. Keep actual ADXT
estimator and helper-counter observations, full buffer predicates, component
commands and error handling as explicitly declared ports. In particular, a
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
