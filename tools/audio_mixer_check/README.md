# Audio mixer regression check

Run from the repository root:

```powershell
.\tools\audio_mixer_check\run.bat <owned imported data directory>
```

The same run also compiles the shared host bridge as File #2 and verifies real
CRI PCM at master 100%, 50% and mute, with category levels zero. File #2 leaves
unverified bank and stream categories unclassified; the host master still
controls their mixed output. File #1 retains its observed bank and AFS routing.

To test environment parsing, real Windows shared-memory updates and File #1's
guest hook registrations/forwarding without game data or an audio device:

```powershell
python tools/audio_mixer_check/bridge_check.py --compiler <portable-LLVM-clang++.exe>
```

This compiles both game variants, checks malformed and incomplete IPC updates,
live master changes, stream route reset and the File #1 ADXT/RNA pointer chain.

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
