# Timed video ownership: implementation and evidence

Status: the prepared native video queue and hardware adapter are implemented
and qualified. Production game selection remains unchanged. This is a stage-3
media boundary, not completion of stage 3 or a measured gameplay speedup.

`VideoFrames` retains the movie Context and uses its authoritative cached clock
to acquire, hold, present or explicitly skip one late picture. Frame stepping
keeps the original cached-clock behavior. `NativeVideoFrames` connects actual
D3D11 decoder outputs to that owner; `NativeFrameSurface` retains the bridge and
exact export ticket until both producer and Vulkan reader fences complete.
Deferred player timing prevents premature publication. Explicit nonblocking
close also covers surfaces still waiting for timestamps; the destructor supplies
the scoped blocking STOP fallback.

## Completed checks

| Evidence | Result and boundary |
| --- | --- |
| Owned original File #1 instructions | GCC and LLVM agree on 218 cases, 662 operations, 812,213 interpreted instructions per compiler and 880 initial/final snapshots. The first 199 cases were frozen before native video existed. |
| Native policy comparison | Zero differences on both compilers. Eight deliberate faults are detected: unstable equal timestamps, scaled ordering, held-as-ready, ignored references, wrong release state, first-versus-second advance, missing running-state gate and missing previous-picture publication. |
| Native owner tests | Producer backpressure, stale/foreign keys, reference retention, bounded skip, pause/resume/frame stepping, actual native source/decoder/PCM Session with a device model, provider failure, reentry, owner retention and shutdown retry. Poll-loop check counts can vary. |
| Standalone regression | All 68 suites pass under GCC 15.2 and LLVM 21.1.8. Existing 40 timing, 401 buffering and 206 audio-command original profiles were also requalified against this exact source manifest. |
| Actual offscreen GPU | Radeon RX 570: D3D11 decoded a verified 512x320 progressive I frame; Vulkan copied its pixels. A real unsignaled renderer fence prevented storage reuse. Signaling allowed retirement and reuse. Shared-clock hold/frame-step and deferred-timestamp close passed. |

The owned input is `NETBIO01.DAT`, byte offset 710572032, length 299008,
independently inventoried as `adxsnd.afs/PS2continue.sfd`. Its SHA-256 is
`f003fe27fc6c402e9e2142a3786828a492bcb26c4b933b8f1a2a944a6d1e94bb`.
The completed GPU readback SHA-256 was
`4eb588549f774d0691a29edd11c5a2865636f6a591245c4ed5dd21f9f8edeaa6`.
This is a stable fixture observation, not independent proof of complete pixel
parity with the PS2 renderer. The deferred-timing test deliberately withholds
timing on this input to exercise the authority protocol; it does not claim this
I frame originally lacked a PES timestamp.

The original public get/map/copy/admission/release bodies execute from the owned
ELF; source-selection transport at `167BD8` is an explicit port. Primitive pool
comparisons omit pure guard observations; joined public-frame cases include
guard/callback snapshots. Legacy public pixel payload and guest pointers are
excluded from the typed native API. Bounded skip does not implement complete
codec decode-skip/recovery or authorize dropping MPEG reference surfaces.

## Reproduction and receipts

The tracked [qualification](../../game/native/movie_timing_context/video_qualification.json)
pins sources, receipts, compiler identities and parent logs. Raw inputs/outputs
and extracted owned assets remain in ignored
`build-native-sjuni/movie-video-frames/`. No game asset is added to the source
tree. Failed original-v1 and GPU-v1 scopes are preserved: these were harness
range/link failures, not observed game failures. The final hardware receipt is
`gpu-v3/receipt.json`, SHA-256
`4f757e54299841e8f70adcf26746400d8e79dc9ad4698131576c0baa290dc3ba`.

For a fresh comparison scope, run the tracked verifier with the chosen compiler:

```powershell
python game/native/movie_timing_context/verify_video_frames.py --cxx <compiler.exe> --output build-native-sjuni/movie-video-frames/<fresh-scope>
```

The original oracle is
`tools/native_reconstruction/movie_video_queue_oracle.py`; its existing receipt
cohorts are checked by the verifier before use. The hardware fixture requires
explicit compatible sealed build inputs and the user's imported data:

```powershell
python tools/native_reconstruction/run_movie_video_gpu.py --kit <sealed-kit> --toolchain <exact-toolchain-root> --data <imported-data-directory> --output build-native-sjuni/movie-video-frames/<fresh-gpu-scope>
```

The runner validates the sealed compile plan, Granite headers/libraries, compiler
and source-preserving allocator provider. It compiles the reviewed allocator
source and import receipt explicitly; it does not stub provider identity or
mutate runtime dependencies. It extracts only the verified owned fixture and
runs without constructing a window, launching the game or opening audio.

## Remaining work

Compose complete movie construction/stop/rebuild and bind the scheduler/game
adapters before selecting this path in the game. Add representative whole-stream
I/P/B and codec skip/recovery validation, real transition/error/restart tests,
monitor presentation and audible A/V synchronization checks. Current audio/video
policy tests establish shared-clock behavior with a device model; they do not
establish audible synchronization or solve the reported movie stutter. No game
speed, rendering mode or diagnostic defaults changed in this slice.
