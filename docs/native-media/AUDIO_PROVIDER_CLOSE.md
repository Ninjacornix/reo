# Audio provider close order

Source audit and isolated verification completed on 2026-11-05. This fixes a
provider shutdown lifetime error for future rebuilt candidates. It does not
report a newly reproduced game crash, a measured gameplay speedup, or completion
of the full native transition.

## Finding and exact boundary

Pinned raylib `raudio.c:525`, `CloseAudioDevice`, destroys `AUDIO.System.lock`
before calling `ma_device_uninit`. Its `OnSendAudioDataToDevice` definition at
line 2487 takes that lock before traversing the buffer list, including when the
list is empty. Therefore removing streams alone does not retire this callback's
dependency on the lock.

The local miniaudio implementation establishes the required Windows fence:

- `miniaudio.h:8927–8959` documents device uninitialization as stopping the device
  and prohibits calling it from a callback because that would deadlock. It also
  marks concurrent device use during uninitialization unsafe.
- `miniaudio.h:42153–42188` sets the device state to uninitialized, signals the
  worker wake event, and waits for the worker for non-asynchronous backends
  **before** calling the backend's device-uninit hook.
- `miniaudio.h:16371–16375` implements the Windows thread wait with
  `WaitForSingleObject(INFINITE)` followed by `CloseHandle`.
- `miniaudio.h:40571–40584` classifies a backend with read/write callbacks or a
  device data loop as non-asynchronous. WASAPI installs read/write callbacks at
  23599–23600, DirectSound installs its loop at 25358, and WinMM installs
  read/write callbacks at 26455–26456. These shipped Windows backend paths
  therefore take the worker join before return. This is a source-qualified
  conclusion for this pinned provider, not a claim about every miniaudio backend
  or future revision.

Shutdown must be initiated outside the audio callback, after callers have
serialized their use of device APIs. This patch does not add that application
serialization or authorize shutdown from inside a callback.

## Change and reproducibility

[prepare_audio_output.py](../../tools/local_build/prepare_audio_output.py) now
requires exactly one reviewed close sequence and stages this order:

```c
ma_device_uninit(&AUDIO.System.device);
ma_mutex_uninit(&AUDIO.System.lock);
ma_context_uninit(&AUDIO.System.context);
```

The original endpoint selection and fallback behavior, readiness reset, PCM
buffer free, pointer reset and size reset are preserved. The transform refuses
changed or duplicated sequences and works under the candidate preparer's
`exec` call without `__file__` or runtime patch-file reads. The upstream checkout
is read-only. A fresh matching C11 provider object must be built and linked into
a new candidate; the document or patch cannot change an existing executable.
Previously sealed V6 candidates remain unchanged and do not include this fix.

The close-only patch is
[0000-stop-device-before-audio-mutex-uninit.patch](../../third_party/patches/raylib/0000-stop-device-before-audio-mutex-uninit.patch).
It is not added to an automatic raylib setup workflow. The existing staged
provider transform applies the same reviewed replacement; apply neither path
twice to already modified source.

| Input | Identity |
| --- | --- |
| raylib revision | `c1ab645ca298a2801097931d1079b10ff7eb9df8` |
| original `src/raudio.c` SHA-256 | `2d6a2d5b9f86b44b879605f654659c542a317d97477ddfde54683019e8bfeacc` |
| `src/external/miniaudio.h` SHA-256 | `7cc33503a3b8ea3ecd6e4a0c337f7a07e1058dd69623b38ddd0daccab347c406` |
| close-only patch SHA-256 | `d286ef3b5dba91bcd542e5ec4f82fb74ab00649cc6a26bd3d468a3d7a3eb0a79` |
| fully transformed provider SHA-256 (staged Windows file) | `bde6dea9c96bdc9caa95b040871bd2b43ea80c65808f081dc6403564e5ba765c` |

## Verification and limits

[The isolated verifier](../../tools/native_reconstruction/audio_provider_close/README.md)
passed with GCC 15.2.0 (MSYS2 Rev8) and bundled LLVM Clang 21.1.8. Each compiler
compiled and ran the extracted original and patched close functions in the
deterministic mock:

| Case | Unsafe mutex teardown observed | Device wait observed | Callback joined | Checks |
| --- | --- | --- | --- | --- |
| Original | 1 | 1 | 1 | Pass (expected counterexample) |
| Patched | 0 | 1 | 1 | Pass |

The mock preserves the relevant dependency and join contract while deliberately
avoiding actual mutex-use-after-destruction. It demonstrates the ordering defect
and the fix under that contract, not actual hardware scheduling or a reproduced
Windows audio failure. Both compilers also compiled the complete transformed
`raudio.c`, including real miniaudio and endpoint-selection headers, into a C11
object with the existing 5 ms/two-period settings. No provider was linked into a
running application and no device was opened. Six focused audio transform/build
unit tests passed, including no-`__file__` execution, source preservation,
stable staging mtime, changed/duplicate close rejection, and C language flags.

The private receipt is `build-native-sjuni/audio-provider-close/receipt.json`.
It contains exact compiler commands and object hashes. A future candidate still
requires a coherent rebuild and actual audio/movie lifecycle validation; this
isolated result does not establish completion of that broader validation.
