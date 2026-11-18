# Pinned audio provider shutdown proof

This isolated check extracts the exact `CloseAudioDevice` bodies from pinned
raylib and the staged transform, compiles both against a deterministic contract
mock, and compiles the complete transformed provider as C11 against its actual
headers. It never links the provider into the mock, opens an audio device, or
runs a game.

From the repository root, supply existing C++ drivers (the provider compile
explicitly selects C with `-x c -std=c11`):

```powershell
python tools/native_reconstruction/audio_provider_close/verify.py `
  --compiler C:/msys64/mingw64/bin/g++.exe `
  --compiler C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe `
  --output build-native-sjuni/audio-provider-close
python -m unittest discover -s tools/local_build -p test_audio_output.py -v
```

`receipt.json` records input, patch, transformed source and object hashes,
compiler identities, compilation commands and mock results. Output belongs in
an ignored private build directory. The executable PATH is scoped to each
subprocess so bundled LLVM DLLs are available.

The mock pauses an active callback while it holds the audio lock. A separate
controller releases it only after mock device uninitialization has entered its
wait. No sleeps or scheduling luck select the interleaving. The old order must
observe mutex teardown while the callback remains active; the patched order
must observe the device fence before mutex teardown. The unsafe original case
records the lifetime violation instead of actually destroying a live mutex.
Both cases verify callback join, subsequent context teardown, PCM buffer free
and reset, and the inactive second-close branch.

The verifier also replays the committed dependency patch into a temporary copy
of exact pinned `raudio.c`, checks it changes only the close order, and compares
its close body with `prepare_audio_output.instrument`. The transform itself is
self-contained because candidate preparation executes it without `__file__`.
The new patch is a review/reproduction artifact; no setup script automatically
applies this raylib patch, and no dependency checkout is modified by this check.

See [the evidence and limits](../../../docs/native-media/AUDIO_PROVIDER_CLOSE.md).
