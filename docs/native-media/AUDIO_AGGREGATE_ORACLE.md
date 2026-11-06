# Combined PCM and bank playback reference

Status: source reference completed 2026-11-06; native aggregate comparison is
pending. No game, audio device or runtime worker was started.

[audio_aggregate_oracle.py](../../tools/native_reconstruction/audio_aggregate_oracle.py)
compiles the complete unchanged `CriAudio.cpp` and `ReoSoundBanks.cpp` together
from the qualified 124-patch dependency reconstruction. This closes a reference
gap: the earlier PCM reference replaced bank mixing with a controlled sink,
while the bank reference mixed into an authored buffer. This reference observes
both real playback implementations composing the same output buffer.

The source is the existing host compatibility implementation, not original PS2
instruction execution. Its provenance is the full reapply receipt
`944b72d4cc977ac01d8e7a4459c601f0a331b06c8adbb5048bec45a2963f91cb`.
All six copied implementation/API files must match that receipt before and
after execution. The PCM source is
`c27f088eab74a7a914ddcb32efbda4923d0b174c059f9c5029e6ec20f8096580`;
the bank source is
`e164ba72cc002311d4811d803be2e2df9a6228d5abcaa0c4fa419a31ee09b818`.
No native candidate is imported, read or linked to produce expected results.

## Inputs and observations

The frozen corpus contains **21 cases / 287 actions**. Four tiny synthetic
SCEI/VAG/sequence assets reuse the existing bank reference's input authoring
helper; that helper supplies no playback results. Cases cover mono/stereo PCM
with bank playback, combined gain and master clipping order, all-port gain
sampling, bank mute/mono/volume, PCM pause and drain, release/discard, independent
PCM/bank resets, bank cancellation/replacement, fractional-rate phase, shared
channels, missing-channel catchup, null output, headless ticking, ensure without
a device and complete shutdown.

Each case runs in a fresh process. Source counters and reset semantics are
observed as implemented; the harness does not zero private statistics between
cases. The only clock substitution is the controlled PCM `steady_clock`; the
real standard library supplies all containers and other operations. Runtime
registration/setup stubs always refuse. The host declares no audio device, and
any attempted device creation/playback aborts the check.

Both GCC and the pinned LLVM toolchain produce exactly equal observations:

- 65 render actions and 9,316 exact output float words;
- 10,052 ordered host-hook observations, including 9,856 actual bank-gain calls;
- complete retained PCM samples and voice phase/queue/consumption snapshots;
- bank clock, request age, flags, voice count, port identities and public queries.

The harness copies existing source state without performing bank decoding or
warming its caches merely to inspect them. Seven Python checks validate the
binary transport, complete action coverage, bounds, deterministic input authoring
and refusal to overwrite an existing different frozen input/expectation.

## Frozen evidence

Private output: `build-native-sjuni/audio-aggregate-oracle-v4`.

| Artifact | SHA-256 |
| --- | --- |
| Input manifest | `59a6d270ae310d78444354325b6d8edcd0d4c4891b4283425be38887a304fc91` |
| Completed dual-compiler receipt | `b142dd116ef7c81b03c9795462a324ab413a29baa8d4147c098225adfd20da57` |

The input manifest precedes compilation and hashes all case wire files, the
authored JSON, harness and mock headers. Expected files are source-produced and
immutable within this output cohort. Historical v1 contains an earlier 20-case
GCC-only corpus. Historical v2 retains the subsequent 21-case GCC observations
and an LLVM compile failure caused by including two physical copies of a mock
header. V3 fixes that harness include; V4 adds deterministic PE linking so a
repeat execution reproduces the complete receipt, including executable hashes.
The complete dual-compiler V4 command was repeated successfully without changing
any frozen evidence. Original playback sources and V3/V4 inputs are unchanged.

Run:

```powershell
python -m unittest discover -s tools/native_reconstruction -p test_audio_aggregate_oracle.py
python tools/native_reconstruction/audio_aggregate_oracle.py `
  --checkout build-native-sjuni/dependency-pcm-boot-reapply-v3 `
  --baseline-receipt build-native-sjuni/dependency-pcm-boot-reapply-v3-receipt.json `
  --output build-native-sjuni/audio-aggregate-oracle-v4 `
  --compiler C:/msys64/mingw64/bin/g++.exe `
  --compiler C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe
```

This is a synchronous composition reference. It does not establish device
timing, callback allocation bounds, producer concurrency, RAM capture coherence,
packet transport equivalence or complete media-player migration. Those remain
separate qualification gates for the native aggregate and its runtime adapter.
