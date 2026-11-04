# Audio mixer regression check

Run from the repository root:

```powershell
.\tools\audio_mixer_check\run.bat <owned File1 data directory> [owned File2 data directory]
```

The run compiles each game's production host bridge and verifies actual CRI
stream and sound-bank PCM at Master and category levels of 100%, 50% and mute.
Supply both owned data directories to include each game's original sound banks.
Without the second argument, the File #2 stream PCM tests still run and its owned
bank checks report a skip. See [File #2 routing evidence](../../docs/FILE2_AUDIO.md).

To test environment parsing, real Windows shared-memory updates and both games'
guest hook registrations/forwarding without game data or an audio device:

```powershell
python tools/audio_mixer_check/bridge_check.py --compiler <portable-LLVM-clang++.exe>
```

This compiles both game variants, checks malformed and incomplete IPC updates,
live channel changes, stream route reset and the production ADXT/RNA pointer
chain at each edition's hook address. The original guest functions are stubbed
at this boundary; forwarding, continuation guards and pointer bounds are checked.

This copies four audio source/header files from the repository SDK checkout
`third_party/PS2Recomp` into the ignored test output, then checks and applies
the canonical `0103-audio-volume-controls.patch` to that staged copy. The SDK
checkout remains unchanged. Set `REO_AUDIO_TEST_SDK_ROOT` to use another checkout
containing the same unpatched audio sources. Python, Git and Visual Studio C++
build tools must already be available.

The check builds the actual patched `CriAudio.cpp` and `ReoSoundBanks.cpp`. It
substitutes only the host device boundary and unrelated diagnostic calls.
It does not launch the game or access an audio device. Production classification,
volume state and host bridge come directly from `runtime/audio/`.

The check reads File #1's `common.snd` and `start.snd` from the user's imported
`NETBIO01.DAT/adxsnd.afs` in memory. File #2's banks come from `NETBIO00.DAT/0`
(ROM AFS): common, selection, player voice, NPC and weapon banks. No game assets
are copied into this tool. These banks and ports were matched to original
File #2 call sites and retained native load logs.

Assertions inspect actual rendered float PCM at 100%, 50% and 0%, master/category
multiplication, independent categories, concurrent voices, planar stereo,
next-block changes, PCM consumption and bank timeline preservation while muted.
They also exercise complete/rejected IPC updates and source classification,
including reused RNA handles and each game's distinct port12 selection-bank
fingerprint. Enemy audio reusing port12 remains Sound effects.

For bank routing tests the same original cues are deliberately loaded into
different ports. This proves routing and gain behavior, rather than claiming
those synthetic assignments were observed in gameplay. Launcher WPF interaction
tests separately verify real slider-to-IPC publishing, including File #2 reset
and minimum window size. A rebuilt full-game run is still needed to verify the
complete path during gameplay; these checks do not claim a full scenario run.

Outputs, staged sources and compiler logs stay in the ignored
`build-ninja/audio_mixer_check` directory.
