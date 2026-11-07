# Native pause, nesting, buffering control and clock step

The typed controller implements the [reviewed cut](../../../docs/native-media/MOVIE_PAUSE_CONTROLLER_CONTRACT.md)
through raw pause transitions, independent nesting, fixed component command,
buffering flags/counts and the complete mode-2 integer clock step. It owns named
state and retained provider ports, without guest RAM, registers or runtime types.

Before native code existed, 305 cases / 316 operations executed 35,875 original
instructions, including public validation, every pause/step helper, the actual
signed product/division and the complete optional CRI guard chain. Both compilers
match complete state, defined returned statuses, provider arguments and the state
observed at each provider boundary. All nine rate codes, signed frequency
boundaries, sentinel increments, overflow/underflow and stateful repeated calls
are represented. Ten deliberate faults are detected, with 14 additional checks
for admission, reentry, retained ownership and failed-provider partial effects.
The first GCC verification failed compiling a counterfactual due to warning
formatting; this was a verifier issue. Native behavior matched already. The
failed scope and source snapshot remain; its warning is not counted as detecting
the intended behavioral fault.

Complete buffering predicates, component dispatch and error handling are
explicit ports. The comparison is of their controller, not a claim that those
subsystems execute natively. Paired pure guard hooks have isolated depth/tag
evidence, not shared global synchronization/priority authority. Authored callback
updates are applied before continuing; no old snapshot can erase them. Public
pending is written after its child returns. Native provider failures retain
already published state and expose a separate failure status, and buffer guards
are still paired. Rate-index refusal precedes effects when the call would reach
the unchecked original table. These refusals are not original error-path parity.

Run `python game/native/movie_pause/verify.py --cxx <compiler> --output
build-native-sjuni/movie-pause/<fresh-scope>` to compare the frozen original
corpus and negative controls. The standalone CMake test exercises the provider
failure boundary. `manifest.json` and `qualification.json` record source,
compiler, original evidence and full-project checks.

No game or real device was opened, and this component is not selected in the
player's build. A single owned movie context must still bind these fields to
the selected/audio clocks and real components. Movie construction/reset, full
buffering/due/skip predicates, shared guards and source/frame lifetime remain
stage 3 obligations, followed by stages 4–6.
