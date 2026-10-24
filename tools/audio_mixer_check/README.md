# Audio mixer regression check

Run from the repository root:

```powershell
.\tools\audio_mixer_check\run.bat <owned imported data directory>
```

This copies four audio source/header files from the repository SDK checkout
`third_party/PS2Recomp` into the ignored test output, then checks and applies
the canonical `0103-audio-volume-controls.patch` to that staged copy. The SDK
checkout remains unchanged. Set `REO_AUDIO_TEST_SDK_ROOT` to use another checkout
containing the same unpatched audio sources. Python, Git and Visual Studio C++
build tools must already be available.

The check builds the actual patched `CriAudio.cpp` and `ReoSoundBanks.cpp`. It
substitutes only the host device boundary and unrelated diagnostic calls.
It does not launch the game or access an audio device. Production classification
and volume state come directly from `runtime/audio/mixer.h`.

The check reads `common.snd` and `start.snd` from the user's imported
`NETBIO01.DAT/adxsnd.afs` in memory. No game assets are copied into this tool.
Those are the original menu and character selection banks previously matched
to native captures.

Assertions inspect actual rendered float PCM at 100%, 50% and 0%, master/category
multiplication, independent categories, concurrent voices, planar stereo,
next-block changes, PCM consumption and bank timeline preservation while muted.
They also exercise complete/rejected IPC updates and source classification,
including reused RNA handles and the shared port12 bank fingerprint.

For bank routing tests the same original cues are deliberately loaded into
different ports. This proves routing and gain behavior, rather than claiming
those synthetic assignments were observed in gameplay. Separate live game
verification is still needed for the original ADXT-to-RNA hook and launcher IPC.

Outputs, staged sources and compiler logs stay in the ignored
`build-ninja/audio_mixer_check` directory.
