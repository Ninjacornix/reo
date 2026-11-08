# Movie audio source through the canonical instance owner

Status: native capability implemented and tested with real source workers and
private output. It is not installed in a game movie graph. Stage 3 remains open.

The earlier `movie_audio_clock::SessionSource` retains a mutable standalone
Session. The game instance facade intentionally owns its Session privately.
Giving the movie a second Session or exporting that private Session would break
the ownership boundary. `movie_instance_audio::Source` implements the existing
`ControlledSource` interface through the same canonical `adxt_control_owner`.
It opens no device, decoder, output producer or additional Session.

## Identity and admission

`Instances::capture_source` mints an opaque capability containing both the stable
instance generation and the replaceable Session source generation. Both keys
remain private to `SourceKey`. A diagnostic start count is not authority. Stop,
replacement, destruction, slot reuse, faults and owner shutdown prevent further
access to the old source. Retaining the movie capability retains its owner, but
does not prevent explicit source join and private output retirement.

Every operation enters the canonical owner's serialized admission. Metadata
queries copy one validated observation while admitted. Estimate, pause and
discard first validate the source, leave admission to read the retained native
service tick, then validate the exact same source again while applying the
operation. Replacement or shutdown between those borrows prevents effects on a
different source. The tick provider must retain native state and perform no
guest callbacks, guest RAM reads, blocking I/O or joins. It must supply the
original service-tick domain; display FPS is not a substitute.

The provider retains itself for an accepted call and refuses concurrent or
nested calls before reading the tick. Failed queries preserve caller outputs.
Before the actual header is ready, status is 1 and sample frequency is zero.
After readiness, frequency comes from that source's actual header. Metadata
queries never sample the service tick.

Pause keeps the original raw argument and updates the stable instance's pause
policy, so replacement inherits it. Discard invokes the same Session's qualified
service/rebase operation and returns the original zero result. Its argument is
not a seek position. Paused discard services the existing group; unpaused
discard does not. Actual group ordering remains the canonical controller's
responsibility, including explicit ordering when more than two sources exist.

## Qualification and limits

Both compilers exercise six workflows with actual synthetic ADX source workers,
decoding and a private stereo callback: early header readiness, clock/control
sharing with a live peer, stop/replacement/reuse, changes during tick sampling,
call lifetime and a query already waiting when shutdown closes admission.
The existing instance, game-control and controller-owner suites are rebuilt
and rerun with the extended class definition. Three compiled counterfactuals
must fail at runtime: following the replacement source, losing persistent pause
and sampling the tick while holding canonical admission.

The validator checks the complete local include closure. Both production units
affected by the extended `Instances` class (`instances.cpp` and `owner.cpp`)
are rebuilt. Their old archives are excluded; all reused archives and unchanged
native inputs are hash checked against the previous 77-suite cohort. This
avoids mixing different class definitions merely because their pimpl ABI is
compatible. The full CMake cohort has not been rebuilt with this extension.

The first LLVM attempt failed because the fixture waited for queued samples
without waiting for actual voice start. That failure and its logs remain in
`build-native-sjuni/movie-instance-audio/llvm-v1`. The corrected fixture waits
for both actual voices to start. This was a test setup correction, not a game
playback fix. The final qualification records the exact successful inputs and
retained runtime failures of the counterfactuals.

Still required: acquire this capability from a validated game handle, supply
the actual runtime tick owner, connect it to movie source controls and the
logical/physical graph, qualify broader ordering and required profiles, then
perform paced movie/audio and lifecycle tests in the coherent game candidate.
This module does not resolve the outstanding cinematic hitch or prove that
native ordinary audio has played in the game.
