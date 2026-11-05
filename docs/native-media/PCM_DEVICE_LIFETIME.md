# PCM device callback lifetime boundary

Status: source-qualified audit, 2026-11-05. This does not run a device or establish
an implemented native PCM backend. The current standalone PCM Session has no
device callback; its caller must quiesce external users before destruction.

The sealed candidate uses raylib revision `c1ab645ca298a2801097931d1079b10ff7eb9df8`,
`raudio.c` SHA-256
`2d6a2d5b9f86b44b879605f654659c542a317d97477ddfde54683019e8bfeacc`.
The [source-preserving audio transform](../../tools/local_build/prepare_audio_output.py)
changes only initialization/device selection. It does not change the callback,
buffer-list or unload functions discussed here. The active dependency's different
CriAudio implementation must not substitute for the reconstructed 121-patch source.

## Existing fence mechanism

In that exact `raudio.c`:

- `OnSendAudioDataToDevice` holds `AUDIO.System.lock` while traversing tracked
  buffers and calling `ReadAudioBufferFramesInMixingFormat`.
- That reader calls `ReadAudioBufferFramesInInternalFormat`, which invokes the
  buffer's `callback` before returning. The same audio-system mutex therefore
  remains held throughout the registered stream callback.
- `SetAudioStreamCallback` acquires the same mutex before replacing the callback.
  For this callback route, setting it to null from a different thread waits for
  an earlier invocation to return and prevents later registered invocations.
- `UnloadAudioBuffer` first calls `UntrackAudioBuffer`, which acquires that mutex,
  removes the buffer from the tracked list, and clears its list links. Only after
  returning does unload destroy the converter and free the buffer storage.

This gives a source-level callback fence for a valid tracked stream under that
provider. It is stronger than merely setting a playing flag. It does not cover
manual calls to a captured callback pointer, a concurrent second unload,
unverified provider versions, device reinitialization races, callbacks from a
different API, or calling detach/unload from the callback itself.

The reconstructed `CriAudio::shutdown` calls Stop/Unload before resetting its
queue maps; it does not hold the CRI queue mutex across those provider calls.
That order matters: the callback holds the audio-system mutex and then acquires
the CRI/PCM mutex. An owner holding the PCM mutex while requesting a provider
detach/unload could invert those locks and deadlock.

## Required native host owner order

1. Select one complete backend for the session before its first PCM operation.
   Capture the native owner and register runtime stop/join ownership before
   publishing a callback. Do not mix old and new queue maps for one stream.
2. Give the callback a strongly owned native session lease. Preserve bank mixing
   and master-gain order separately. Keep guest callbacks off the device thread.
3. Request stop by closing producer admission. A nonblocking stop request must
   not attempt provider unload, wait for itself, or destroy a retained lease.
4. Join guest producers, then detach/stop/unload the stream from a non-callback
   owner thread, without holding a registry, PCM, bank or guest lock. Verify the
   actual provider route/version and fence completion.
5. Only after that fence, reset/destroy queue state and release the callback's
   native owner. A failed fence must retain the owner and report incomplete
   shutdown rather than claim joined lifetime or free storage still in use.

Host-only race tests should force an active callback to pause, request shutdown,
prove the owner remains alive, then release the callback and observe the real
fence before destruction. Real provider tests must additionally exercise repeated
open/close and device changes. A mocked fence proves the owner protocol only.

Raw RNA/SJRMT/SJX generation mapping, unknown-ID clock advancement, channel
destruction and explicit multi-voice summation order remain separate bridge
requirements in [the extraction inventory](PCM_OWNER_EXTRACTION.md). Native
queue handles alone do not solve those guest protocol lifetimes.
