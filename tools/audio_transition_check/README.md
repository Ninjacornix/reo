This regression drives the real DTX RPC and RNA control-DMA path, queues
synthetic signed PCM, and checks production mixer output. It reproduces a
stream continuing to play after `PS2RNA_DESTROY`, including old-ring refill
and destruction during a pending drain. Other voices and accepted speech tails
must remain audible. Real SJX mailbox transfers also reproduce an interrupted
stream draining into a transition. Under RC2's policy, an outstanding producer
chunk with more than 1.5 seconds queued means an intentional cut; shorter tails
and acknowledged natural endings retain their accepted samples.

On a Mac with an existing native Ninja build:

```
python3 tools/audio_transition_check/run.py \
  --sdk third_party/PS2Recomp \
  --runtime-build build-macos/ps2recomp \
  --game-build build-macos/game \
  --out build-ninja/audio-transition-candidate
```

The SDK must contain the existing canonical release patches. The runner stages
only required audio/RPC files, applies patches 0113, 0115 and 0118 in that private copy, compiles
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

`bank_cancel.cpp` checks a separate bank-audio cancellation defect: releasing
current notes must also retire the cancelled sequence, so it cannot schedule
new notes during a loading screen or cutscene. Ordinary in-sequence AllNotesOff
retains its scheduler. Other sequences, masked exact selectors, repeated
cancellation and replacement of flagged requests are covered.

Run with an existing Clang C++20 compiler and your owned imported File #1 data:

```
python tools/audio_transition_check/run_bank.py --sdk <canonical-sdk> \
  --data <owned-file1-data> --compiler <clang++> --out build-ninja/bank-candidate
```

On Windows, put the compiler's runtime DLL directory on `PATH`. Repeat with
`--baseline` and a new output directory; the baseline must fail at `Cancel
retires sequence immediately`. The runner privately applies patch 0114 and
uses the existing headless device/diagnostic boundary. Bank samples come from
the owned archive; the repeating TQ is authored test data. No assets are bundled.
