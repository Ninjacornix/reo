# Host audio stream lifetime owner

This C++20 component owns callback admission and one provider stream's teardown.
It does not open a device, implement raylib bindings, own PCM/bank state, or call
`CloseAudioDevice`. It is not installed into the running game.

Read [the contract and integration limits](../../../docs/native-media/AUDIO_OUTPUT_OWNER.md)
before supplying a provider or renderer. `CallbackSlot` must have stable storage
through successful join and every trampoline caller. One slot admits one owner.
The provider keeps its existing device/audio-system synchronization; callbacks
never need the owner's provider-lifecycle mutex.

Run the isolated fake-provider tests from the repository root:

```powershell
python game/native/audio_output/verify.py `
  --compiler C:/msys64/mingw64/bin/g++.exe `
  --compiler C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe `
  --output build-native-sjuni/audio-output-owner
```

The runner compiles with C++20, optimization and warnings as errors. It runs only
fake provider/renderer code and records source hashes, compiler identities and
commands in `receipt.json`. Condition-variable rendezvous select both admission
orders and the callback/detach interleaving; no sleeps select a test outcome.
