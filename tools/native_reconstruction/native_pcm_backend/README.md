# Complete native PCM runtime binding checks

These isolated checks compile the authored binding against actual reconstructed
123-patch runtime/backend headers. They separately compile the same binding,
complete patched `CriAudio.cpp` facade/dispatch, bridge, PCM core and real stream
adapter against fake runtime/device/bank surroundings. No game, real audio
device or complete runtime library is executed.

```powershell
python tools/native_reconstruction/native_pcm_backend/verify.py `
  --checkout build-native-sjuni/dependency-pcm-profile-reapply-v1 `
  --baseline-receipt build-native-sjuni/dependency-pcm-profile-reapply-v1-receipt.json `
  --compiler C:/msys64/mingw64/bin/g++.exe `
  --compiler C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe `
  --output build-native-sjuni/native-pcm-backend
```

The tool requires the exact supported owned File #1 ELF, verifies its hash, then
extracts two short identity windows into an ignored private fixture. No game
instruction words are committed. It verifies the relevant dependency files
against the fresh reconstruction receipt and compiles the actual production
object with real headers. The fake-runtime test object is separately compiled;
the fake class layout is not substituted at link time into the real-header
production object.

Each compiler runs 19 independent processes, respecting the stream provider's
one-candidate-per-process reservation. The tests allocate the production
2040-channel/2041-voice domain: 391,680,000 sample-storage bytes plus four MiB
of explicit map metadata and other bookkeeping. No smaller test-only domain
silently substitutes for this profile. Paused-call/callback tests use explicit
condition-variable rendezvous, not sleeps.

`receipt.json` records source/header/fixture identities, compiler commands,
production object hashes, each case's stdout/stderr, and final PCM reports.
The verifier requires all eleven method-completion totals in the complete
lifecycle case and one successful join report per completed binding. Current
public-reset-before-install refusal is a passing negative case, not evidence of
native installation in the existing game boot path.

See [the binding contract and remaining blockers](../../../docs/native-media/NATIVE_PCM_BACKEND.md).
