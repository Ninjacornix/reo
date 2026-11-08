# Native MP4 game integration

Status: native worker tested; game adapter selects and creates a movie object.
The first two game candidates expose registry and cue lookup refusals, described
below. Successful in-game playback is still pending. Step 3 is incomplete.

The replacement owns Windows Media Engine and D3D11 on a native thread. Game
movie cues select prepared, hash-verified MP4 assets. Playback no longer needs
an SFD source, MPEG-2 parser, CRI movie queues, PS2 input/image transfers or their
decoder/scheduler. The original immutable method table is only the temporary
call boundary to game logic which has not migrated in Stage 4.

The native session exposes start, append, stop, pause, loop, status and immutable
BGRA frames with source generations. Two engines preload consecutive playlist
clips. Three CPU frame slots bound the handoff; retaining all three applies
backpressure instead of overwriting a frame held by the renderer. Source errors
retire the affected pipeline and allow a subsequent source on the same owner.
The runtime owns shutdown/join; the native thread never accesses guest memory
or calls translated game code.

The adapter keeps a 64-byte public proxy in the existing game arena, followed
by a renderer image. It does not construct the old movie object or its decoder
children. Imported archive/member numbers only resolve existing game cues to
native resource IDs: playback performs no source-archive reads or conversion.
The admitted File #1 executable window, public method pointers, configuration,
arena, runtime and current game-thread identity are checked before selection.

V23 freshly builds all 2,415 units in 1,311.922 seconds, then refuses startup
because its all-original registry expectation excludes the existing exact
feed-end continuation and CRI timing wrappers. V24 preserves and admits those
reviewed entries, rebuilding two units and revalidating/reusing 2,413 objects.
It selects the native owner and creates a 512x448 game movie object, then refuses
member 419 before starting a source. The lookup incorrectly compared the stored
physical container path with the logical AFS label. Its native source/audio/
output owners join, with no movie source started. Its zero exit code is not
successful playback: the retained log contains the refusal and runtime error.

The corrected cue adapter resolves the bounded, read-only public partition
descriptor's physical container and sector range to an imported native key.
It does not open or stream that source range. The generated map covers all 201
owned references and preflight verifies every required native key/frame count.
This is a temporary game cue boundary; native playback still uses only the
prepared MP4. In-game validation of this correction is pending.

The game still renders through its existing graphics pipeline. A separate,
explicit bridge converts native BGRA square-pixel frames into that renderer's
requested pixel grid and tile order. This bridge is not the native renderer and
must be removed with Stage 5. Its copy remains leased until the game's existing
renderer release boundary. All converted File #1 movie shapes have 4:3 display
aspect despite their different coded dimensions. Native playback uses square
pixels; the temporary renderer bridge restores the old requested grid once.

The separate `eff_mov/*.mov` effect-image path still uses IPU services. Its
shared initialization must remain until those rendering consumers migrate.
This replacement does not claim to remove that separate dependency.

## Qualification

Both GCC and the bundled LLVM compiler passed actual Windows-native playback:

- Two complete 195-picture clips, 390 observed frames, ordered through EOF.
- Pause/resume with zero measured paused-clock drift over 200ms.
- Preloaded clip transition gaps of 46.9ms (GCC) and 31.9ms (LLVM), measured at
  the CPU frame handoff; these are not display-scanout timings.
- Replacement and stale-control refusal; immediate start/stop cannot resurrect
  a stopped source. A retained frame survives source retirement unchanged.
- A verified but undecodable test asset reports a source error without
  terminating the owner, then a valid source plays successfully.
- Holding all three frame slots bounds memory; releasing them resumes progress.
- Independent renderer landmarks check channels, aspect resampling and tile
  order. Malformed output dimensions refuse before writing.

Evidence is pinned in
`tools/native_reconstruction/host_movie_session_qualification.json`. The actual
SDK131 adapter object compiles against the audited dependency cohort. Neither
the worker tests nor that compile launch the game or establish audible sync.

Private selection uses a coherent candidate built with `--host-movie`, plus
`REO_NATIVE_HOST_MOVIE=1` and `REO_NATIVE_HOST_MOVIE_CACHE=<complete cache>`.
Selection skips the old GPU movie and old movie-position installation. A missing
cache or failed installation is an explicit launch error, never an implicit
fallback labelled native playback. Normal launcher packaging is still pending.

Next validation must select this owner in the game, play the full opening with
its native audio, exercise skip/pause/repeat/error and room transitions, inspect
joined shutdown, and compare the reported cinematic stutter. No performance
improvement or Step 3 completion is claimed before those tests.

The private audio observer uses Windows process loopback for the identity-checked
test process tree, following Microsoft's
[application-loopback interface](https://github.com/microsoft/Windows-classic-samples/tree/main/Samples/ApplicationLoopback).
It does not select an endpoint mix or microphone. The native helper independently
checks the held process's creation time and executable, writes a bounded PCM WAV
and per-packet QPC/device-position/flag CSV, and reports capture errors explicitly.
Wrong creation-time and executable tests refuse before opening capture/output.
The actual silent-process test completes with 48,000 frames, peak PCM16 value 1,
RMS 0.479, zero discontinuity flags and zero timestamp errors. Nonzero values at
that amplitude are conversion dither, not an audible-signal claim. Evidence:
`build-native-sjuni/host-movie/process-audio-self-v2/receipt.json`. This is capture
plumbing evidence; actual game soundtrack/synchronization still needs validation.
