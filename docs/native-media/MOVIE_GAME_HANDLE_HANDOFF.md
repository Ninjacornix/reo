# Canonical audio handoff from a game handle

Status: API handoff and prepared-graph composition qualified on both compilers
with declared guest layouts and real native workers. No actual game movie hook
calls this API yet. Stage 3 remains open.

`GameHandles::capture_audio` accepts the validated, generation-scoped `GameKey`
and a retained original service-tick provider. It checks the same map's live key
and calls `movie_instance_audio::Source::capture` outside canonical admission.
The returned interface controls the current native source through its existing
owner. The caller receives neither the instance key nor a mutable Session.

The map still requires one serialized guest controller. Before acquisition,
that controller must inspect the current guest layout and use `find`; the map
does not retain guest RAM or independently reread it from a movie/GPU thread.
A changed child identity, stale game key, pending destruction, cleared map or
nested canonical borrow prevents capture. Source replacement then invalidates
the captured source separately from the stable game handle.

Both compilers pass the existing three handle workflows plus the new movie
handoff workflow. These exercise ready metadata, the real estimator, pause,
serviced discard, source replacement, changed guest identity, public slot reuse
and joined shutdown. Five compiled counterfactuals fail at runtime: using the
file slot as the stream slot, releasing pending children, ignoring a secondary
transfer reservation, ignoring the game key, and capturing inside an already
admitted canonical borrow. They reuse the qualified unchanged native archives
and rebuild the extended instance/controller production units coherently.

The separate graph test supplies that same interface in `GraphConfig.clock.audio`
with `GraphConfig.audio` absent. This existing borrowed-source route opens no
additional audio Session and performs no second audio-group service from movie
service. The test exercises actual asynchronous graph input, movie clock refresh,
native pause and paused discard, rebuild, close, partial video construction
failure and later canonical audio shutdown. Graph retirement detaches its timing
queries while preserving the externally owned voice; explicit canonical shutdown
then retires the real audio source. A real private callback still produces signal
after movie close. Video, helper-clock and component ports are declared models;
this is not GPU playback, presentation pacing or audible A/V evidence.

The graph test's first compilation attempt retained two fixture `main` functions
and used misleading one-line indentation. Those failed compiler logs remain in
`build-native-sjuni/movie-graph-handoff/{llvm,gcc}-v1`. The corrected validator
extracts the existing fixture before its unique main boundary and records the
generated header hash. Both `v2` runs pass. No runtime/game correction is inferred
from fixing that test compilation.

The private candidate recipe includes `movie_instance_audio/source.cpp` whenever
it includes `game_handles.cpp`, preserving the new symbol dependency. V20 is
sealed and unchanged; it does not contain this handoff. A new coherent full build
and runtime tick/handle/graph integration still require adequate disk space and
their own game evidence. The full native CMake cohort has not been rerun.

Exact source and receipt identities are in
[the handoff qualification](../../tools/native_reconstruction/movie_game_handoff_qualification.json).
The earlier [canonical source qualification](MOVIE_CANONICAL_AUDIO_SOURCE.md)
remains separate from these consumer checks. Required live playback, broader
audio profiles, real logical/physical video scheduling, room/resource transitions
and the unresolved cinematic hitch remain in the
[Stage 3 checklist](STAGE3_CLOSURE.md).
