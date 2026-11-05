# Native stream provider qualification checks

This checks the real authored adapter against the exact pinned `raylib.h`, then
links that object to a fake device API and eleven source-extracted raylib audio
functions. No actual raylib/miniaudio device backend is linked or opened.

From the repository root:

```powershell
python tools/native_reconstruction/audio_stream_provider/verify.py `
  --compiler C:/msys64/mingw64/bin/g++.exe `
  --compiler C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe `
  --output build-native-sjuni/audio-stream-provider
```

The runner verifies exact upstream source/header hashes, generates a private
`qualified_raudio.inc` directly from that source, compiles the production
provider object, and uses it in five isolated test-process modes per compiler.
Separate processes respect the adapter's permanent one-candidate reservation.
The receipt records all inputs, extracted function hashes, object hashes,
compiler identities, commands and results. No upstream source is modified or
generated licensed source committed.

The actual extracted functions cover stream load/validity/default buffer size,
callback replacement, play/stop wrappers, track/untrack, buffer/stream unload,
and the mixing-format reader. Device state, mutex primitives, allocation,
converter and play/stop buffer internals are faked. The internal-format reader
models its callback branch; the script verifies the corresponding branch and
outer device-lock route against hash-qualified source. The complete device
callback and resampler are not executed.

The production object compiles with C++20 and warnings as errors. Only the test
link/compilation suppresses C-style missing-field-initializer warnings from the
exact extracted upstream source. Condition-variable rendezvous select the
paused callback/fence interleaving; no sleeps choose the outcome.

See [implementation boundaries and evidence](../../../docs/native-media/NATIVE_STREAM_PROVIDER.md).
