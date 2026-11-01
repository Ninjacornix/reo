This regression drives the real DTX RPC and RNA control-DMA path, queues
synthetic signed PCM, and checks production mixer output. It reproduces a
stream continuing to play after `PS2RNA_DESTROY`, including old-ring refill
and destruction during a pending drain. Other voices and accepted speech tails
must remain audible.

On a Mac with an existing native Ninja build:

```
python3 tools/audio_transition_check/run.py \
  --sdk third_party/PS2Recomp \
  --runtime-build build-macos/ps2recomp \
  --game-build build-macos/game \
  --out build-ninja/audio-transition-candidate
```

The SDK must contain the existing canonical release patches. The runner stages
only required audio/RPC files, applies patch 0113 in that private copy, compiles
the real sources with the existing runtime compiler flags, and links the fixture
against the existing archive/platform libraries. Source SDK and game binaries
remain unchanged. Logs and source/patch hashes are retained beneath `--out`,
which must be a fresh directory inside this checkout.

Repeat with `--baseline` and another fresh output directory. Baseline exit 1 at
`Destroy silences only the destroyed host voice` is the expected reproduction;
the candidate must exit 0. The fixture uses no owned game data or audio device.
It verifies this lifecycle bug, not the complete reported loading/cutscene/FMV
sequence or the remaining effects slowdown. The C++ fixture is platform-neutral;
the convenience runner has only been validated with the Mac Ninja link format.
