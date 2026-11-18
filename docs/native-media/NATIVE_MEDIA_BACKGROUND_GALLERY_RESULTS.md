# Native media: background gallery and room-transition results

Status, 2026-11-09: actual queued gallery playback, ordinary-input room loading,
and normal background shutdown are established for the cases below. This is
additional Stage 3 evidence, not completion of the whole step. The executable
with the seventeen-cue capacity still needs an actual queued-gallery retest and
final presentation/synchronization coverage.

The [qualification record](../../tools/native_reconstruction/native_media_background_gallery_qualification_v1.json)
binds each result to the process creation identity, private executable path and
hash, source revision, sealed build/package receipts, retained logs and analyzer
inputs. The analysis itself launches no game, modifies no existing evidence and
requests no focus or desktop capture.

## Completed game cases

| Session | Candidate and route | Established result | Limits |
| --- | --- | --- | --- |
| `20261109-020831-679` | V33, ordinary menu/Collection, 603.548 s | Exit 0, normal close, joined cue owner, zero final native underruns. | 526 observations include **four foreground samples**, 522 minimized samples. The activating actor is unknown. No queued command accepted. |
| `20261109-022331-902` | V33, private unlocked card, ordinary Collection/movie input, 603.773 s | Full E3 EOF, replay and skip, then a scenario playlist; three queued commands accepted/finished, no cue failures, joined retirement. All 559 window observations minimized, zero foreground samples. | Scenario playlist stops during its third observed clip; this case does not prove a complete playlist. Capacity is the earlier sixteen-cue version. |
| `20261109-030626-335` | V34, private unlocked card, Outbreak scenario with ordinary-input room exercise, 481.869 s | **Room 1 to room 4**, phase 2 and continued actor movement in the destination; exit 0, joined owners, zero final native underruns. All 464 observations minimized, zero foreground samples. | One representative room transition; no destination pixel capture or precise resource-request-to-room mapping. No queued command accepted. |
| `20261109-032345-794` | V34, manual gameplay route, 424.769 s | Normal close/exit 0 and joined retirement. All 403 window observations minimized, zero foreground samples. | Manual door driver fails before any input action. No door or room-transition evidence from this case. |

V33 source revision is `fdfeacf9635977d82ff02f67d512247b894fdc7e`, executable SHA-256
`e8e23c8910fc4fd0a3d87017e3180c0f4febb29db9bfdb179c6e3911b44eecd2`.
V34 source revision is `cd7edfda1b371bfa5ec7576b45a7ee96a18fbf5c`, executable SHA-256
`eb97579809a18870e85af067862c7b088e80bd3c91f10ab321217594d08e55a4`.
Both sealed builds reuse 2,416 of 2,417 verified object units. Source reuse does
not substitute for the separate live results.

The private cards enable progression access for the fixture. The room exercise
returns ordinary pad axes and buttons; it does not teleport actors, change room
state, grant health/ammunition or change game speed. These cases use the actual
launcher core/native-media preparation route without constructing the Avalonia
window; they do not validate the desktop UI route.

## Actual queued movie/audio playback

The V33 gallery's first E3 playback publishes all 6,144 unique pictures, ordinals
0–6,143, with no dropped producer or consumer records. Its maximum measured
producer-publication gap is 41.8765 ms. Replay publishes 3,224 pictures before
the ordinary Circle skip; its maximum gap is 52.0827 ms. A looping menu epoch
contains a 65.4891 ms gap. These are producer observations, not display scanout
or a claim of stutter-free playback.

The subsequent scenario playlist records 451 pictures of clip 0, 90 of clip 1
and 96 of clip 2 before normal close. Native reports retain:

- Cue owner joined, accepted 3, finished 3, pending records 0, failures 0.
- Native audio owner/source joined, 27,800,640 output frames, 21,596,143 signal
  frames, zero underrun frames, hard failures, queue rejections or submix failures.
- Sound RAM retired with no active slots/operations. Its 23 diagnostics and
  optional log refusals remain recorded; they are separate from audio underruns.
- Movie owner joined, eight sources, 16,287 delivered pictures, `error=none`.

The audio-control CSV retains 32,768 snapshots and drops 2,002. Its analyzer finds
zero measured underrun increase in retained coverage; the final native totals
independently report zero for the lifetime. The process-only digital audio
capture records 25,833,600 frames with no packet discontinuities or timestamp
errors. Its 540-second bound expires before game shutdown, hence
`process_exited=false` in that recorder result. Actual game exit is separately
normal; the field must not be rewritten to imply the recorder observed exit.

All sampled old MWSFD player slots are zero, while ordinary-file and queued
native audio modes are observed. Sampling does not prove every old path is
unreachable. Two legacy thread-manager error messages remain in the logs;
their cause is unconfirmed and the report does not call the whole log error-free.
Compiler regression workloads overlap the final gallery portion, after the
first full E3 playback; this is not an isolated performance benchmark.

## Late room transition recovered from the completed V34 recording

The earlier partial observation missed the end of this run. The completed
observer first sees scenario/room `[1,4]` at observer time 405.594 s, phase 3.
It sees phase 2, unpaused and without modal state, at 407.594 s. There are 59
room-4 observations, including 57 phase-2 observations through 463.672 s.

The native room-input log independently changes from room 1 at game-test time
421.541 s (`x=9250`, `z=12964.700`) to room 4 at 424.668 s
(`x=9469.251`, `z=12950.093`), then records continuing destination movement
through 480.239 s. Observer and game-test time origins differ. The native log's
`phase=0..3` is the input exercise cycle, **not** the game's phase field.

The sealed V34 `reo_hw_bridge.cpp` has SHA-256
`bc89559586915089579a4f6dc562217c41b9f12bf885132b3944ff6c81c30343`.
Its `pad2TestRoomSoak` checks original gameplay/loading/modal/pause/actor state
and emits only normal pad input. Its logging gate requires game phase 2 and an
active, eligible actor; later actor coordinates change in room 4. Together with
the external state samples, this establishes a completed, interactive room
transition on the installed native resource/audio path. It does not establish
the destination's final rendered image, every room, or every asset identity.
Native resource logging records at least 256 successful payload reads; the
power-of-two logging cadence does not give an exact final request count or
identify which request supplied room 4.

The game-clock recorder's 300-second window ends before this late transition
and drops 4,087 records. It cannot provide transition timing or continuous game
speed evidence here. Its actor callbacks must not be counted as global updates.

The separate manual driver's 158 retained samples have request byte 3 and false
readiness, and it emits zero actions. The sealed ordinary-input exercise already
allows request 3 during interactive gameplay, so the manual gate is unsuitable
for that state. Its retained exception message is empty and its type is absent:
the receipt does not establish the exception that ended the driver. Preserve
this failed attempt without treating it as a game defect or successful door test.

## Seventeen-cue regression and digital audio timing

Both LLVM and GCC pass all 80 native suites for the seventeen-cue controller,
then all 34 real-asset ordinary-adapter scenarios and ten detected injected
faults. Each adapter receipt binds the same compiler's new native receipt and
the exact manifest. Source/import identity checks remain unchanged. The
[capacity qualification](NATIVE_AUDIO_CUE_CAPACITY_RESULTS.md) retains the
seventeen dense clips, delayed-header test correction and overflow refusal.
These tests use native workers and declared output ports; they are not new
physical-device/game evidence. V34 links this change, but its queued-command
count is zero, so V33 gallery evidence cannot silently qualify the new capacity.

An offline comparison independently decodes the actual E3 audio member using
the pinned FFmpeg and matches five one-second source regions to the owned
process-loopback recording. Anchors cover source times 10.01, 40.04, 80.08,
140.14 and 190.19 s. Both channels exceed correlation 0.99935; every anchor has
the same captured-minus-source offset of **7,102,625 audio frames**. No rate drift
is measured between those checked regions. Sixteen decoder padding frames are
excluded using the source's declared length.

Matched audio arrives 95.845–98.823 ms after native video publication and
77.882–93.563 ms after game handoff. These are digital pipeline observations:
they do not measure final compositor pixels, scanout, speaker/headphone latency
or subjective lip sync. They do not justify a phase correction without final
presentation evidence. The comparison is not an exhaustive PCM equality check.

Historical intermittent video/audio incident causes remain unknown. Clean
retirement, a bounded digital timing match and non-reproduction do not constitute
a controlled root-cause fix. Stage 3 remains open for its remaining coherent
candidate, required consumer and presentation/synchronization gates; stages 4–6
and in-engine cutscene rendering remain separate.
