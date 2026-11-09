# V38 first-playback native media evidence

Status, 2026-11-09: session `20261109-062015-774` passes the ordinary background
gallery controls, complete first E3 playback, native audio accounting and joined
shutdown. Five held-out movie-picture/audio regions supply bounded digital A/V
evidence. This is one acceptance case; it does **not** close Step 3 or prove that
all historical stutters are fixed.

The [qualification](../../tools/native_reconstruction/native_media_v38_cold_playback_qualification.json)
binds the source/build/package/launcher receipts, session identity, actual traces,
independent A/V analysis and its exact references. This audit opens completed
files only. Large movie, executable, gray and WAV hashes are inherited from the
already completed verified A/V analysis instead of re-reading those assets while
another capture runs.

## Scope and identity

The game executable SHA-256 is
`1f6853aad57b6125d6ed3f20d5ed0ddd853fc67fb5a1330da7e8da5b5aa597a5`.
Its recorded source revision is
`ad93542da65d327af65422031ee1c4f3d58d35b7`; the linked candidate, matching media
package and published SDK agree. The launcher revision is
`e860b8b612a62cfcdcaca66f619f5fdc0ea84a43`, on
`fix/launcher-progress-overlay`. The actual private executable belongs to PID
331960 with creation FILETIME 134386752214433792. Capture and observer receipts
bind that same identity.

This is a new process with an initially empty **process-local native resident
cache**, and the first complete E3 playback precedes replay. It is not a cold
physical-disk benchmark: no OS file-cache flush or physical-storage state was
measured. All CPU-heavy build/regression cohorts had completed before this case,
according to test coordination. Window/audio capture and the read-only observer
still add load; this remains an instrumented acceptance test. A preceding build
attempt's resource-icon temporary-file rename failure remains retained; its
private-TMP retry completed before this runtime case.

The input-driven gallery fixture passes full E3 EOF/return, replay/skip and
scenario-playlist/skip checks. Neither the fixture nor the observer requests
foreground focus or uses a global keyboard hook. The harness reports normal exit
0 with no forced cleanup, native/media error or deliberate movie/audio fault.

## Complete native playback and ownership

Generation 4 maps explicitly to File #1 partition 3/member 416. All **6,144**
updated ordinals 0–6,143 are present exactly once. Its 6,148 retained producer
observations report maximum backpressure **0**. The complete producer and
consumer traces retain 11,053 and 11,041 records respectively, both with
`dropped=0`. Producer retention includes every updated picture, slow iterations
and periodic observations; it is not every empty worker poll.

The first full E3 movie's maximum publication gap is **66.6394 ms**. Two gaps
exceed 50 ms and none exceed 100 ms. The largest, ordinals 5,050→5,051, includes
33.0373 ms in the recorded readback section and 32.3180 ms outside recorded
iterations. The other, 1,453→1,454, is 56.3923 ms. These delimit measured native
pipeline intervals; they do not identify the inner readback/scheduling cause or
measure final display scanout. A stutter-free claim is unwarranted.

The consumer reports 10,942 fresh frames across the complete case, agreeing with
the movie owner's final delivered-frame count. Maximum recorded borrow, copy
and frame-lease intervals are 0.0354, 6.8977 and 7.2370 ms. Final ownership reports
show:

| Owner | Final evidence |
| --- | --- |
| Native source service | joined; 95,600 accepted visits; one order deferral |
| Native ADXT/output | joined; 19,173,120 output frames; 10,465,423 signal frames; zero underrun frames |
| Output/submix | zero hard failures, queue rejections or submix failures; 39,944 submix calls |
| Native cue owner | joined; accepted 3, finished 3, outstanding records 0, failures 0 |
| Native movie owner | joined; sources 9, delivered frames 10,942, error `none` |
| Sound RAM | retired; active slots 0, active operations 0 |

The version-2 audio-control trace contains **23,987** snapshots, zero dropped or
invalid rows, no counter/time reset, and zero measured shortage windows. Its last
output/underrun counters agree with the final native report. All observed stream
late/skipped counters are zero. Some cached source snapshots retain a request-in-
flight flag across later controller samples with an unchanged source-observation
timestamp. That does not prove the underlying request remained pending until
each later controller sample and supplies no individual-request latency bound.

Runtime warnings remain visible: the normal window-close path prints
`Error during program execution: PS2 Thread Exit`, followed by joined owners and
exit 0. Sound RAM reports 23 diagnostics and 23 refused `log` operations, with
first diagnostic/refusal code 1540. These lines are retained rather than erased
by the successful output/source counters. No source-service error marker appears.

## Independent picture and audio checks

The hash-pinned prepared E3 MP4 and independently decoded 6,144-picture grayscale
reference are the same verified source used by the earlier
[window-picture investigation](NATIVE_MOVIE_WINDOW_PICTURE_TIMING.md). The actual
window capture contains **6,977** samples. Geometry is refitted using separate
calibration picture 2,685; the five regions below are held out from that fit.
Every candidate comparison searches all reference pictures. Audio matches both
channels of independent source PCM in a one-second region at each anchor.

| Source anchor | Selected picture | Picture correlation | Conditional audio minus first-picture interval |
| --- | --- | --- | --- |
| 300 | 291 | 0.99420 | [−4.57, +45.47] ms |
| 1,200 | 1,208 | 0.98717 | [−32.22, +17.82] ms |
| 2,400 | 2,403 | 0.99591 | [−24.78, +25.26] ms |
| 4,200 | 4,210 | 0.98769 | [−30.22, +19.82] ms |
| 5,700 | 5,689 | 0.99758 | [−21.13, +45.58] ms |

The intervals bracket the selected capture and a preceding unambiguously
different picture, retaining the 0.01 correlation ambiguity convention and
geometry perturbations. They are conditional on the matches, monotonic playback
and compositor API timestamp semantics. They are not statistical confidence,
physical display/speaker measurements or subjective lip-sync confirmation.

The five audio anchors have **0 ms measured source-QPC phase span** at retained
precision, supporting no accumulated rate drift at those checked regions.
Audio follows native publication by 95.34–97.49 ms and frame handoff by
62.12–88.22 ms. Those are digital pipeline observations; no phase correction is
applied. Full-body preparation has therefore preserved the checked first-playback
content/timing relationship in this case, rather than only passing a warm replay.

## Capture continuity and background limits

The process-audio packet timestamps contain **seven gaps** beyond a two-frame
tolerance: approximately 300.1407, 690, 490, 20, 40, 1,820 and 3.5141 ms. Returned
packet flags are zero. Each matched one-second audio template avoids these gaps,
but the complete WAV storage timeline is not proven continuous. Captured-minus-
source sample offsets change from 2,747,105 to 2,723,585 and 2,720,705; the analysis
maps through each actual packet QPC and never invents continuous WAV time.

During E3, window-capture coverage has one **750.6098 ms** interval between samples
928→929. Native publication's maximum remains 66.6394 ms. The capture gap does
not establish a game/display freeze. Signed readback-QPC minus compositor stamps
include 6,052 negative observations, ranging −14.7944 to +8.8442 ms; their cause
is unconfirmed and no offset correction is invented. Native zero-underrun
accounting, captured-packet gaps and physical audio continuity are separate facts.

The observer retains **404** read-only records with no errors. All have a visible
owned window and zero owned foreground windows. All eight original MWSFD player
slots are zero in every sampled record; registry/callback end markers match.
These guest observations are non-atomic and sampled. Separately, every retained
window-capture foreground count is zero and the helper reports no desktop read
or focus request. None of this claims continuous unsampled focus/state coverage.

The first-playback native-cache boundary, complete source progression, joined
ownership and checked digital content/timing pass here. Error recovery and room
transition acceptance remain separate cases. Historical stutter attribution,
physical/perceptual synchronization and all remaining Step 3 gates remain open.
