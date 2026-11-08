# Native MP4 player

`Player` uses Windows Media Engine for MP4 decoding, scheduling, pause/resume,
seek, loop, end-of-stream and error reporting. It transfers the due video frame
to a normal caller-owned BGRA D3D11 render texture. It has no PS2 runtime, guest
memory, emulated registers, CRI queues, MPEG-2 parser or game-function ABI.

Create it on the graphics owner with a video/BGRA-capable, thread-safe D3D11
device. All controls and destruction use that same serialized owner. `open`
validates a local file and creates a distinct engine/callback lifetime, returning
a generation. Controls and transfers require that generation; late commands for
an older movie refuse before touching the current engine or texture. Callbacks
only count events and acknowledge the platform's stable-state request. They do
not call back into the game or retain a Player pointer.

Open is asynchronous. Poll `snapshot` for readiness, error or EOF, and control
playback through the native API. Render at the application's normal display
cadence: `transfer` returns `updated=false` when there is no new due frame.
The previous texture can then stay on screen. New textures require the normal
D3D11/Vulkan producer/consumer synchronization if used by another API. A frame
transfer does not claim completion of asynchronous GPU writes or consumer reads.

Media Engine's reported dimensions are adjusted for pixel aspect, not the
encoded dimensions. For the tested 512x320/SAR5:6 movie it returns 427x320 and
picture aspect4:3. It scales and letterboxes into the target texture. Use a
target/compositor rectangle with the intended display aspect and display the
result with square pixels; do not apply the source pixel-aspect correction twice.

The first source must come from a prepared local MP4 cache. Runtime transcoding
on the game or graphics thread is not part of this design. Source preparation,
game movie cues, playlists, the compositor binding and separate game ADX audio
cues still need integration. Do not instantiate the old Sofdec/IPU path for a
movie claimed by this replacement. This library is not selected by a game build
yet and does not complete Step 3.

## Actual platform checks

`tools/native_reconstruction/verify_host_movie.py` compiles the production
library source and runs it against the qualified, locally converted owned
`PS2continue.sfd` MP4. GCC and the bundled LLVM compiler each pass:

- Complete native clock-paced playback with195 increasing frame timestamps and
  actual D3D11 texture copies; eight sampled GPU readbacks contain picture data.
- Pause with zero measured clock drift over250ms, resume, seek/restart after EOF
  and native repeat wrapping.
- Invalid-file refusal preserving the active source; invalid volume, negative
  seek and null render-target refusal; stale-source command/transfer refusal.
- Source replacement, shutdown, corrupt-source error reporting and subsequent
  valid-source recovery.
- Local path URL encoding, using a real filename containing spaces and `#`.

The LLVM check also opens a short-lived native window and presents the actual
textures through DXGI. This establishes that native presentation calls succeed,
not independent display-scanout cadence, full-stream image-quality equivalence
or audible A/V synchronization. No game or audio device was used by these
video-only tests. Native clock times are roughly6.55..6.58s for the6.5065s clip,
including startup. No whole-game performance claim is made.

Receipts: `build-native-sjuni/host-movie/{gcc,llvm}-v1/receipt.json`.
Exact inputs/results: `tools/native_reconstruction/host_movie_qualification.json`.
The first compiler error and two geometry-check experiments precede these
receipts; the latter exposed the native API's documented pixel-aspect correction.
Their private binaries/logs are retained where available.

Platform references:
[native video ticks](https://learn.microsoft.com/en-us/windows/win32/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-onvideostreamtick),
[frame transfer and letterboxing](https://learn.microsoft.com/en-us/windows/win32/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-transfervideoframe),
[display-size semantics](https://learn.microsoft.com/en-us/windows/win32/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-getnativevideosize).
