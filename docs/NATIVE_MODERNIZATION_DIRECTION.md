# Native modernization and PS2 removal

Direction confirmed by the user on 2026-11-08: modernize the game and remove
PS2-specific machinery. This supersedes treating internal CRI/PS2 routine
parity as a mandatory destination. The original implementation is evidence for
game content and observable behavior; it is not the required native design.

The end product runs game logic and platform systems natively. It does not
execute translated MIPS functions, model EE/IOP registers or guest RAM, emulate
PS2 kernel/RPC services, or feed VU/VIF/GIF/DMA/GS emulation. Renaming, wrapping,
or moving those components does not meet the objective.

Modernize complete boundaries where practical. Convert assets during import,
use ordinary native structures and APIs at runtime, migrate their callers,
then delete the old path. Preserve gameplay rules, content, input behavior,
saves, co-op behavior and original game speed unless a separate deliberate
change is made. Internal slot numbers, transfer protocols, physical buffer
layouts and obsolete device scheduling are not compatibility requirements once
their consumers have moved to native interfaces.

| Stage | Native result and removal target |
| --- | --- |
| 1. Inventory | Use the existing mapping to identify actual callers and data dependencies. Do not wait for a literal 100% label count. |
| 2. Buffer pilot | Reuse the already implemented independent buffer/ownership work where useful. Do not reproduce a CRI buffer API in a new subsystem solely because the old game used it. |
| 3. Resources and media | Load imported assets through native resource IDs. Use native audio mixing and a normal native video player with converted assets. Replace game-level play/stop/pause/skip/finish consumers; remove their old media producer, transfer and scheduling paths. |
| 4. Gameplay and scheduling | Move actors, scenario execution, collision, timers, saves and task ownership into native state and functions. Remove generated guest ABI/register/memory dependencies as callers migrate. |
| 5. Rendering and platform | Convert source graphics into native texture/mesh/animation resources and render through a modern graphics API. Replace VU geometry work and VIF/GIF/DMA/GS submission, plus remaining platform services. |
| 6. Removal and release | Delete obsolete adapters and compatibility execution/hardware components; remove their build/link/package dependencies. Verify clean native builds and representative scenarios, transitions, saves and co-op. |

## Immediate media route

1. Reuse the launcher's existing verified FFmpeg preparation tool and owned
   import parser. Prepare H.264 MP4 video assets locally; never redistribute
   extracted game content in a release. Convert lazily or in a bounded import
   pass so setup does not duplicate the entire imported game unnecessarily.
2. Use the Windows native media stack for the first Windows implementation.
   MP4/H.264 decoding is an implemented OS feature, rather than a new custom
   decoder. A native media session supplies playback scheduling; a raw source
   reader alone does not supply presentation or A/V synchronization.
3. Replace the high-level movie consumer with a small native interface for
   play, pause, resume, skip, finish and error. Keep subtitles, aspect ratio and
   transitions attached to the game's movie cue. The temporary boundary to
   unmigrated game callers is not the final architecture.
4. File #1's inspected SFD catalogue contains no embedded audio packets.
   Associate the actual game audio cues explicitly; converting the video alone
   cannot produce a complete soundtrack. Use the native mixer and native asset
   metadata, converting audio where that simplifies the implementation. Do not
   invent a movie/audio pairing from similar filenames.
5. Test complete playback, audible sync, skip, pause/resume, repeat where used,
   movie-to-game transitions and shutdown. Confirm that the selected native path
   does not invoke the old movie producer, PS2 input/IMAGE transport or decoder.
   Delete each obsolete path after its last caller moves.

In-engine cutscenes are scene animation/rendering work, not movie files. Their
slowdowns need the native gameplay/rendering work; transcoding cannot fix them.

## First concrete result

`probe_mp4_movie.py` extracts one hash-verified member from the existing owned
File #1 import, converts it with the launcher's already cached pinned converter,
and compiles/runs `mp4_decode_probe.cpp` against Windows Media Foundation.
No game, window, audio device or PS2 runtime is involved.

For `adxsnd.afs/PS2continue.sfd`, all 195 independently counted source pictures
are retained. The 299,008-byte SFD becomes a 31,730-byte H.264 MP4. Native
decoding reaches EOF with 195 NV12 pictures at 512x320 and pixel aspect 5:6.
Its normalized sample timestamps match the converted movie within one 100ns
tick. This proves the small native decoder route, not on-screen playback,
hardware acceleration, image-quality equivalence, A/V synchronization or game
integration. Lossy CRF18 is an explicit prototype encoding choice.

The original FFmpeg-demuxed SFD timestamps include repeats/jumps. The first
passthrough experiment failed its timing comparison and is retained. The
successful conversion instead preserves every decoded picture at the sequence
header's declared 30000/1001 cadence. It does not claim to retain literal PES
timestamps or reproduce the old scheduler. The player must anchor its clock to
the first native sample; the probe reports the native offset as well as relative
times. Visible A/V testing remains required before selecting this in the game.

Evidence: `build-native-sjuni/mp4-movie-probe/continue-gcc-v3/receipt.json`.
The two earlier failed experiment directories and source snapshots remain.
The tools and receipt identities are recorded in
`tools/native_reconstruction/mp4_movie_probe_qualification.json`.

## Completion policy

Earlier reconstruction tests and findings remain useful regression evidence.
They do not require retaining a retired implementation, recreating every
internal routine in a replacement, or completing unused old codec/control
profiles before implementing a modern boundary. Add tests for the native design's
actual correctness, resource lifetime and game-facing behavior.

Step 3 remains incomplete: the MP4 proof has no game hook or presentation yet,
and broader native audio/resource transitions remain. The user's conditional
sleep request still applies only after Step 3 actually completes. Stages 4-6
remain required for the whole native game.

Platform references: [Microsoft MPEG-4 support](https://learn.microsoft.com/en-us/windows/win32/medfound/mpeg-4-support-in-media-foundation),
[source reader scope](https://learn.microsoft.com/en-us/windows/win32/medfound/source-reader),
and [native presentation clock](https://learn.microsoft.com/en-us/windows/win32/medfound/presentation-clock).
