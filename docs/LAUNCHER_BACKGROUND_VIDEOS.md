# Launcher demonstration backgrounds

In **Launcher**, turn off **Background movies** to use the normal
placeholder images. The setting applies immediately, is shared by both editions
and stays saved across restarts. Disabling it closes both video decoders and
cancels pending video preparation; switching games cannot restart movies while it
is off. Re-enabling it restores the selected edition's playlist and bookmarks.

The launcher derives each supported game's two title-menu demonstration movies
from its private disc import. File #1 uses `PS2demo03/04.sfd` from the nested
`adxsnd.afs`; File #2 uses the verified `PS2demo01/02.sfd` entries in
`adxsnd_usa.afs`. File #2's sound archive has no useful filename table, so its
revision-specific indices are checked against the archive count and the exact
SHA-256 of each original clip. Opening and ending movies are excluded.

The supported ELF revision and the import's game identity must match. Nested AFS
extents are checked against their containing archive before extraction. Only the
two small clips are copied; the launcher never loads an entire NETBIO archive
into memory.

## Conversion and storage

Preparation runs away from the UI and does not block game import/build/play.
The launcher obtains the pinned Gyan FFmpeg 9.0.2 essentials ZIP on first use,
verifies its size and SHA-256, extracts its private executable and notices, then
verifies the executable SHA-256. It uses neither PATH nor a system installation.
The optional first-use download is about 109 MiB. Streamed downloading has an
eight-minute deadline and is canceled when the launcher closes.

Conversion maps only the first video stream, removes audio, subtitles, data and
metadata, and encodes H.264/yuv420p MP4 at CRF 20 with the medium preset and
fast-start metadata. MPEG-2's 4:3 display aspect is retained. Two conversion
threads keep preparation light.
Cancellation kills and waits for the owned converter process.

`<import>/background-videos-v1/videos.json` records the game, supported ELF,
original clip hashes and generated MP4 sizes/hashes. Manifest format 2 regenerates
the earlier veryfast/CRF 23 cache once. Relative MP4 names make the
cache portable. Later launches verify and reuse the cache. Staging is private
and the manifest is published last; incomplete files never become a playlist.
No game video is shipped with a release or added to source control.

## Interaction and layout decisions

The existing WPF game-library layout, typography, native window and controls are
retained. The only new visual surface sits behind the foreground and its existing
horizontal/vertical readability gradients. Two passive MediaElements alternate;
the next fades over the previous opaque frame over 800 ms. The image remains
underneath, avoiding an empty background during preparation or playback failure.
Videos have their own opacity layer (100% on Play) and a lighter horizontal
gradient; they no longer inherit the cover image's 46% opacity.
The vertical fade retains readability toward the bottom of the window.
The entire background scene, including the fallback cover image and gradients,
is hidden outside Play; every other page uses the normal solid window color.
Leaving Play closes the decoders and records the timestamp; returning resumes it.

- Selecting a game immediately closes the previous edition's media and selects
  only the new edition's playlist. Asynchronous preparation cannot restore a
  stale selection.
- Switching away records each game's clip and position in memory; switching back
  resumes that point. Minimize/restore and game launch/return also preserve it.
  Inactive decoders are still closed, rather than playing behind another game.
- Playback loops without controls, seeking interactions, context menus or focus.
  Both players are also muted with volume zero; MP4s have no audio stream.
- Missing clips, unavailable networking/converter, invalid caches, and decoder
  errors retain the image fallback and do not interrupt the launcher.
- Windows reduced-motion settings use the static image. Minimizing, launching
  or running the game closes the decoders; restoring resumes the chosen game.
- Game removal and storage changes cancel preparation, await its completion and
  close media before touching the files. Shared converter files are included
  when removing shared tools.

Only actual downloading or conversion shows the one-time preparation activity;
ordinary cache verification does not flash the conversion banner. Conversion
runs below normal process priority. Hidden input controls refresh at the slower
device cadence while native input publication stays at 60 Hz. Ambient case
rotation/lighting runs at 30 fps; direct interaction retains its normal cadence.
Navigating to or from Play uses a short foreground fade instead of a synchronous
software snapshot of the video and 3D scene.

## Verification

Build with `launcher/build.ps1`. Run the shared checks for bounded AFS parsing,
archive revision checks, cross-game cache rejection, path traversal, same-length
cache corruption and cancellation before process start:

```powershell
dotnet run --project launcher/cross-tests -c Release
& 'launcher/bin/Release/net10.0/win-x64/Outbreak.Launcher.exe' `
  --headless-check 'C:/private/video-verification'
```

The headless check exercises decoding, duration, pause/resume, end and stop using
a generated silent clip when the pinned converter is already cached. It does not
download the converter just to run a test. The report records `mediaChecked`.

For owned-disc integration, import both supported games through Game files and
verify all four converted clips, game switching, independent resume positions,
minimize/restore and missing-media fallback. Inspect MP4s with `ffprobe` to confirm
H.264, 4:3 display aspect, original duration and no audio streams. The old WPF
`--test-background-playback` diagnostic is retired; the measurements below are
historical results from that frontend.

### Composition cost (2026-10-29, RX 570, 2560x1440 at 125%)

GPU "3D" utilisation of the launcher process, from `\GPU Engine(pid_*engtype_3D)`
while `--measure-background-performance` ran (medians, roughly +/-2 points between runs):

| Build | Static image | Live video |
| --- | --- | --- |
| Before | ~12% | ~30% |
| Cached beam/floor blurs and shades | ~10% | ~25% |
| Window being moved or resized (held) | - | ~0% |

Ablation runs showed that the cost is the WPF scene redrawn over the video every frame,
not drawing the video itself. Hiding the video layer, or laying it out at half or quarter
size and scaling it up, did not reduce it. A visible 320x240 video area halved it.
Caching the whole Play page saved about 5 more points but was not adopted: `BitmapCache`
renders text without ClearType. While the window is moved or resized
(`WM_ENTERSIZEMOVE`/`WM_EXITSIZEMOVE`) the movie pauses on its current frame and the
cases stop animating with a steady light, so the render thread does not fall behind
the compositor; both resume where they stopped.
