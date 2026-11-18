# Pinned raylib native stream provider

Status: authored adapter and source-qualified isolated checks implemented on
2026-11-05. No actual device, game session or integrated native PCM backend was
run by this work. The implementation is
[native_stream_provider.h](../../runtime/audio/native_stream_provider.h) and
[native_stream_provider.cpp](../../runtime/audio/native_stream_provider.cpp).
The [host output owner](AUDIO_OUTPUT_OWNER.md) supplies the separate callback
admission and strong lifetime protocol.

## Implemented lifecycle

`NativeStreamProvider::create` reserves one native candidate for the entire
process. A second factory call is rejected, including after unload or destruction
of the first provider. Unavailable-device and exposed load failures can be
retried on the same instance. This intentionally does not admit arbitrary
runtime replacement or multiple native audio sessions in one process.

`native_stream_callback_slot` is one stable process-local slot for raylib's
no-userdata callback. It is initialized before attachment. Installation must
create the provider and matching owner, register runtime stop/join ownership and
complete backend selection before the game publishes native PCM work. The owner
must publish its strong reference into this exact slot before attach. Foreign
slots and an empty slot are refused.

Attach is lazy. With no ready audio device it returns false with `unavailable`
status and performs no stream creation or callback publication. With a ready
device it preserves the reconstructed source's startup sequence:

```text
SetAudioStreamBufferSizeDefault(512)
LoadAudioStream(48000, 32, 2)
IsAudioStreamValid(stream)
SetAudioStreamCallback(stream, private_trampoline)
PlayAudioStream(stream)
```

A null-buffer load failure returns `load_failed`, publishes no callback and can
be retried. With these fixed positive arguments, exact pinned
`LoadAudioStream`/`IsAudioStreamValid` make validity failure equivalent to a null
returned buffer. The adapter handles that exposed result; it does not repair or
prove the provider's internal allocator/converter failure paths. Once attachment
succeeds, it is idempotent and does not create or play another stream.

This preserves the no-device startup behavior needed for a caller's native
headless operation. The adapter does not advance a headless clock, decide clock
selection, own PCM queues or implement later device hotplug recovery. The global
default-buffer setting matches the existing reconstructed source; it is not
restored, and concurrent stream creation elsewhere must be excluded by complete
backend/lifecycle ownership.

The callback performs only bounded slot dispatch: no allocation, logging,
provider API calls or guest execution is added to its body. Renderer and owner
callback contracts remain independently applicable. Successful owner join calls
the adapter in this order:

1. `detach`: `SetAudioStreamCallback(stream,nullptr)` takes the same audio-system
   mutex as the complete registered callback. Return from this valid, completed
   void call is the source-qualified callback fence.
2. `stop`: `StopAudioStream` after that fence.
3. `unload`: `UnloadAudioStream` after stop; the actual provider untracks the
   buffer under its mutex before freeing converter/buffer storage.

The adapter serializes control separately from callback state and records each
completed stage. It refuses unfenced stop/unload and does not repeat a successful
void operation. It does not turn a readiness check, timeout or an invented return
value into a successful fence. The methods do not catch an uncertain void call
and silently free storage; valid pinned API calls must complete. No implicit
destructor cleanup calls provider APIs.

## Exact source and callback bounds

| Input | Identity |
| --- | --- |
| raylib revision | `c1ab645ca298a2801097931d1079b10ff7eb9df8` |
| `src/raudio.c` SHA-256 | `2d6a2d5b9f86b44b879605f654659c542a317d97477ddfde54683019e8bfeacc` |
| `src/raylib.h` SHA-256 | `5181a1e739762e32cb851ee4dfecd8b51e4861290c38c312c188284677c58bcb` |
| reconstructed121 `CriAudio.cpp` SHA-256 | `39dce6882e561ad69a0112a330ecc4023a98c21365ac2fe8709f838fce4c9a06` |

The startup sequence above comes from reconstructed121 `CriAudio::ensureOutput`,
not the different dirty active runtime. The provider reports the reviewed source
identity to the owner; this does not inspect a loaded library or prove a matching
binary. Installation still needs a coherent candidate manifest, compiled headers
and actual provider object. The separate
[staged provider close-order fix](AUDIO_PROVIDER_CLOSE.md) changes device teardown
while preserving this stream callback/fence source.

The callback bound is derived from `ReadAudioBufferFramesInMixingFormat`, not
from requesting a 512-frame default stream buffer. The exact source allocates
`ma_uint8 inputBuffer[4096]`, computes input capacity using the source format and
channels, clamps requested input frames to that capacity, then calls
`ReadAudioBufferFramesInInternalFormat`. The latter synchronously passes those
frames to the registered callback. Float32 stereo therefore caps one invocation
at `4096 / (4 * 2) = 512` frames. Conversion may make multiple such invocations
for one larger output request. A larger device period can increase the stream's
allocated double buffer without changing this input callback cap.

## Verification performed

[The isolated verifier](../../tools/native_reconstruction/audio_stream_provider/README.md)
passed with GCC 15.2.0 (MSYS2 Rev8) and bundled Clang 21.1.8. Both compile the
complete authored adapter object against the real exact pinned header with
`-std=c++20 -O2 -Wall -Wextra -Werror -pthread`. The tests link that object to
eleven exact source-extracted raylib functions and fake device/converter
primitives. Each compiler passes five independent process cases:

| Case | Observed result |
| --- | --- |
| Complete lifecycle | A paused callback holds the fake device mutex; the actual source callback setter waits before detach. Strong owner/slot retention lasts through release. Stop, untrack, converter destruction and free follow the fence once. Repeated join/control repeats no completed teardown. |
| Headless/load retry | No ready device causes no load or publication. A null-buffer load can retry on the same owner/provider; a later valid load attaches once. Premature stop/unload are refused. |
| Source callback cap | A simulated 1024-frame period makes the actual load function allocate 2048 frames despite default512. The actual mixing-format reader processes 2057 requested frames as five callback invocations, each at most512. |
| Callback self-join | Under the modeled device mutex, callback self-join is refused before provider control; a later outside join completes. |
| Reservation | A second candidate is refused even after destruction of an unused provider; no hidden destructor audio calls occur. |

Receipt: `build-native-sjuni/audio-stream-provider/receipt.json`. It records
source and header hashes, hashes for all extracted functions, exact compiler
commands, object hashes and test outcomes. Generated source remains private.

The synchronization and converter primitives are fake. The internal-format
reader models its callback branch and the outer device callback models the
reviewed held-lock route; the script pins/checks both corresponding source
locations. These tests do not execute miniaudio, actual device scheduling,
resampling, endpoint changes, movie/bank audio, guest producers or the running
game. They are source/API qualification and protocol evidence, not hardware
validation.

## Remaining integration requirements

The application must keep device lifetime fixed and valid while this provider
owns a stream, exclude other teardown/recreation, and successfully join the
stream owner before device close. This adapter never calls `InitAudioDevice` or
`CloseAudioDevice`. A false device-readiness check after an unexpected teardown
would not prove callback retirement. Manual invocation of captured callbacks
and control from other audio callbacks remain outside the admitted contract.

Call start/join outside registry, PCM, bank and guest/RPC locks. Runtime ownership
must retain the owner and stable slot until successful join, and must separately
drain producers before resetting native PCM/bank state. This work changes no
producer dispatch, PCM render order, bank mixing, native backend selection,
candidate exporter, CMake or running-game configuration.
