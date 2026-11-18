# Complete native PCM runtime binding checks

These isolated checks compile the authored binding against actual reconstructed
124-patch runtime/backend headers. They separately compile the same binding,
complete patched `CriAudio.cpp` facade/dispatch, bridge, PCM core and real stream
adapter against fake runtime/device/bank surroundings. No game, real audio
device or complete runtime library is executed.

```powershell
python tools/native_reconstruction/native_pcm_backend/verify.py `
  --checkout build-native-sjuni/dependency-pcm-boot-reapply-v3 `
  --baseline-receipt build-native-sjuni/dependency-pcm-boot-reapply-v3-receipt.json `
  --compiler C:/msys64/mingw64/bin/g++.exe `
  --compiler C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe `
  --output build-native-sjuni/native-pcm-backend-124
```

The tool requires the exact supported owned File #1 ELF, verifies its hash, then
extracts two short identity windows into an ignored private fixture. No game
instruction words are committed. It verifies the relevant dependency files
against the fresh reconstruction receipt and compiles the actual production
object with real headers. The fake-runtime test object is separately compiled;
the fake class layout is not substituted at link time into the real-header
production object.

Each compiler runs 20 independent processes, respecting the stream provider's
one-candidate-per-process reservation. The tests allocate the production
2040-channel/2041-voice domain: 391,680,000 sample-storage bytes plus four MiB
of explicit map metadata and other bookkeeping. No smaller test-only domain
silently substitutes for this profile. Paused-call/callback tests use explicit
condition-variable rendezvous, not sleeps.

`receipt.json` records source/header/fixture identities, compiler commands,
production object hashes, each case's stdout/stderr, and final PCM reports.
The verifier requires all eleven method-completion totals in the complete
lifecycle and boot-setup cases, and one successful join report per completed
binding. The boot case uses exact extracted124 runtime lease/run-seal methods
and RPC layout clear/set/snapshot/reset bodies, forms the profile from the
snapshot, then installs and executes the complete binding. Registration, RAM,
guest scope, RPC containers and device/bank surroundings remain fake.
Ordinary public-reset-before-install refusal remains a passing negative case.
The separate [boot transaction qualification](../../../docs/native-media/PCM_BOOT_SETUP.md)
checks the runtime's nine setup/first-use/install/run/stop race cases; these
integration tests do not replace that qualification or show actual game output.

See [the binding contract and remaining blockers](../../../docs/native-media/NATIVE_PCM_BACKEND.md).
