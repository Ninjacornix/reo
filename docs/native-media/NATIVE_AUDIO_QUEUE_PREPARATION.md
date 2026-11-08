# Native queued-audio preparation and decoder handoff

The native cue-preparation worker and delayed-next-header handoff are implemented
and qualified. This advances the remaining queued-audio boundary; it is not yet
bound to the game's cue commands and does not complete Step 3. The latest game
executable remains the separately tested V31 candidate.

`audio_clip_loader::Loader` accepts retained immutable source views and prepares
sealed native clips on one bounded worker. Submit/poll/release do not perform
header reads on the game thread. Opaque tickets carry owner identity and a
generation; a released older job cannot publish into a reused slot. Stop closes
admission without waiting for an active read, and off-thread join drains actual
source ownership. Completed clip leases can outlive their ticket. Source and
allocation failures are explicit results, not successful empty clips.

An accepted next cue may still be preparing when the current clip reaches its
end. The native input now accepts a bounded `preparing_assets` count. While that
count is nonzero, its decoder waits at the next-header boundary instead of
reporting EOF. The owner must publish the prepared clip before decreasing the
count; failed preparation requires an error/cancellation path. The property does
not supply invented source bytes, decoded samples or elapsed progress.

Both LLVM and GCC pass all 79 native suites. Each executes 148 dedicated loader
checks covering blocked reads, stale tickets, queue overflow, cancellation,
source lifetime through join, parsing/allocation failures and destruction
outside the result lock. The combined control-session test delays the actual
second header read while continuing real native source/player service. It then
matches all 32,000 first-payload samples and both channel digests against the
prepared-in-advance comparison, with zero recorded output underruns. These are
standalone real-worker tests with a declared output provider, not game/device
or owned asset catalogue coverage.

Two private LLVM source mutations are detected: removing the decoder's pending
preparation fence fails the control-session check; removing the loader's stale
publication guard fails the loader check. The positive comparison passes both
suites before mutation. The verifier copies sources into fresh owned output and
does not weaken the working implementation. Earlier copy/configuration failures
are preserved. The inherited native-only manifest omitted nine existing project
dependencies outside `game/native`; the successful negative check explicitly
pins/copies those dependencies and the revised verifier. The old manifest is
not described as covering those additional files.

Implementation is `3e0163f4ce1faf1760713338609c86306f2fb9b4`. Source hashes,
complete native receipts, negative-check receipts and limits are recorded in
`tools/native_reconstruction/queued_preparation_qualification_v1.json`.
Native cohorts are under
`build-native-sjuni/media-queued-preparation-results-{llvm,gcc}-v2`; private fault
evidence is under `build-native-sjuni/queued-audio-checks/preparation-faults-llvm-v4`.

Next work is the actual consumer replacement: audit required owned cue extents
against clip admission, resolve AFS/name cues into native resource IDs, bind
enqueue/start/count/repeat/reset/stop to the native owner, and test its source
retirement and game transitions. Existing clip admission still refuses certain
headers, inline-loop metadata and incompatible output. Do not enable the route
by deleting those checks or by running the original LSC producer underneath it.
Where required content needs conversion, prepare a modern native asset and its
metadata during import. Game-visible controls remain temporary interfaces;
the old physical queue layouts and device protocols are not the destination.
