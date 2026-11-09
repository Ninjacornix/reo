# V38 native movie failure and recovery

Status, 2026-11-09: session `20261109-062828-848` isolates one deliberately
injected native movie failure, returns through the game's normal cleanup/menu
path, completes a fresh E3 playback, and passes subsequent replay/skip and
scenario-playlist/skip controls. Native audio reports zero underruns and all
owners join. This case does not close Step 3 or establish stutter-free rendering.

The [qualification](../../tools/native_reconstruction/native_media_v38_error_recovery_qualification.json)
retains the original **failed generic launcher receipt**, exact error-line
enumeration, source/control traces, recovery chronology and the comparison with
the [first cold native-cache playback](NATIVE_MEDIA_V38_COLD_PLAYBACK.md).
The audit reads completed files only. No game/window/device access, new build,
large asset/executable hash scan or new A/V fit is performed here.

## One intentional failure; original error reporting preserved

The executable remains
`1f6853aad57b6125d6ed3f20d5ed0ddd853fc67fb5a1330da7e8da5b5aa597a5`,
from runtime revision `ad93542da65d327af65422031ee1c4f3d58d35b7` and the same V38
package, SDK and launcher used by the cold case. This process is PID 334268,
creation FILETIME 134386757174200846. Its receipts explicitly enable the movie
fault fixture and leave the audio stall/worker-disable fixtures off.

There is exactly one injection marker, at stderr line 2603:

```text
[NATIVE-HOST-MOVIE-TEST] capability=REO_NATIVE_HOST_MOVIE_TEST_FAIL_V1 generation=4 key=fe761807bc7493769dd7f9720ce6d1cc969f596f76fefc9b5add5385952b153b ordinal=120 fault=one-shot-worker-failure
```

Line 2604 is the only native error/refusal/fatal/fail-style **tag** across both
stdout and stderr: `[NATIVE-HOST-MOVIE-ERROR]`, with the expected injected-worker
failure message. The wider error-like text scan also retains the intentional
capability declaration `original_pcm=refused`, normal final `error=none` reports
and the separate Sound RAM diagnostic report. No additional native failure tag,
installation failure or unexpected error-like line is found. This conclusion
comes from the actual log enumeration, rather than the generic receipt's boolean
error flags alone.

Source inspection binds the marker to the exact E3 key, private background-test
environment, and one-shot `test_fault_consumed` flag. The throw happens after
ordinal 120 is prepared/published but **before** that iteration's timing-row
commit. Generation 4's producer CSV consequently retains ordinals **0–119**;
the capability log/source establish the exceptional ordinal 120. Zero telemetry
drops does not recover an exceptional iteration that never committed its row.
The source catch closes both players, clears prepared assets/textures/pool and
latest-frame ownership, marks that source in error, and keeps the control owner
available for a later fresh start.

The original `native-game-session-check.json` remains `check failed`, with
`native_error=true`, `media_error=true`, and the error status text. The generic
launcher process exits **1**. Its game process exits **0**, without forced cleanup.
The launcher deliberately preserves an observed native-media error even after a
later source succeeds. The separate recovery fixture qualifies the intended
outcome; it does not rewrite the generic failure into a normal-playback success.

## Measured recovery sequence

Times below use the retained input driver's own elapsed clock, rather than
mixing it with QPC or launcher duration.

| Gate | Driver time | Evidence |
| --- | --- | --- |
| First E3 started | 58.672 s | 512×368 native movie; queued native audio mode 4 |
| Returned after failure | 63.734 s | Original gallery viewer/menu state restored |
| Fresh full replay requested | 64.156 s | New E3 source generation 6 |
| Full recovered EOF/menu return | 270.906 s | All 6,144 source ordinals; viewer state restored |
| Another replay requested | 271.297 s | Generation 8 advances through ordinal 131 |
| Replay skip/menu return | 276.375 / 277.437 s | Skip accepted after passing the fault point |
| Scenario play/skip/menu return | 279.734 / 284.797 / 285.859 s | Native scenario playlist and normal return |

All five driver gates pass in 285.859 s. Source-start logs associate generations
4, 6 and 8 with the actual partition 3/member 416 E3 cue. The failure marker never
recurs on the complete replay or later replay.

Generation 6 retains exactly **6,144** unique source ordinals 0–6,143, maximum
publication gap **45.5996 ms**, no publication interval above 50 ms, and maximum
backpressure **0**. The complete-case producer/consumer traces retain 10,984 and
10,965 records, both `dropped=0`. Two later generation-11 menu-loop publication
intervals reach 55.3512 and 52.1553 ms; those are not the recovered E3 generation.

## Complete source progression does not mean every picture was handed off

The temporary legacy-renderer bridge uses a **latest-frame pointer**, not a FIFO.
Its three CPU buffers protect held leases, but an unborrowed picture can be
replaced by its successor. The game frame action returns unavailable when no
serial newer than the released one exists; otherwise it copies the current
latest picture and its original ordinal. This can produce a repeated old picture
at one poll and omit a picture at the next, even when source publication is
complete and the game continues polling.

The actual cold and recovery traces show that limitation:

| Measurement | Cold generation 4 | Recovered generation 6 |
| --- | --- | --- |
| Source pictures published | 6,144 | 6,144 |
| Game frame requests | 6,150 | 6,150 |
| Unique fresh game handoffs | 6,102 | 6,095 |
| Produced ordinals without a retained handoff | 42 | 49 |
| Maximum request begin gap | 35.3839 ms | 34.7890 ms |
| Maximum fresh begin / release gap | 67.6918 / 67.7405 ms | 67.1214 / 67.5523 ms |
| Maximum fresh ordinal jump | 2 | 2 |

Every omitted ordinal in both cases has **no consumer borrow timestamp between
its publication and the successor's publication**. This is consistent with the
measured latest-pointer replacement boundary. These are actual missing native
game handoffs, not missing telemetry or an automatically harmless outcome.
The exact single-ordinal lists, source publication windows, preceding/following
consumer rows, and begin/release intervals are retained in the qualification's
referenced handoff comparison.

None of those omission intervals overlaps a process-audio timestamp gap or a
window-capture coverage gap above 100 ms, even with a ±150 ms comparison margin.
CPU presentation returns continue near the omission intervals: their maximum
adjacent interval is 28.9267 ms in the cold case and 17.7671 ms in recovery. These
return timestamps do not tag which source picture reached physical scanout.

Bounded reads of nearby coarse window images find identical adjacent movie-region
samples in both cases. Sparse approximately 20 Hz capture, static source imagery
and absent per-present source tags prevent proving the exact visual hold for
each omission. The measured 67 ms fresh-handoff gaps and single-picture misses
remain a renderer-interface follow-up; the complete-source/EOF claim must not be
restated as “all 6,144 pictures displayed.” This audit does not expand that
follow-up into a new native-presentation rewrite or physical all-frame gate.

## Audio, retirement and background observations

The version-2 audio-control trace contains **23,917** snapshots, zero dropped or
invalid rows, no counter/time reset and no shortage windows. Every observed
late/skipped stream counter is zero. Its final output/underrun counters match the
native reports:

| Owner | Final evidence |
| --- | --- |
| Source service | joined; 95,470 visits; one order deferral |
| ADXT/output | joined; 19,116,960 output frames; 10,658,862 signal frames; zero underrun frames |
| Output/submix | zero hard failures, queue rejections or submix failures; 39,827 calls |
| Cue owner | joined; accepted 4, finished 4, outstanding records 0, failures 0 |
| Movie owner | joined; sources 11, fresh frames delivered 10,858, final error `none` |
| Sound RAM | retired; active slots 0, active operations 0 |

The movie delivered count agrees with all-generation fresh consumer handoffs;
it is distinct from the producer's 10,928 publication records. Sound RAM retains
24 diagnostics/refused `log` operations and first code 1540. Normal shutdown again
prints `PS2 Thread Exit` before the joined-owner reports and game exit 0. These
warnings are preserved alongside the successful native accounting.

The read-only observer retains **403** non-atomic records, with no errors, a
visible owned window in every record and zero owned foreground windows. All
eight original MWSFD player slots are zero in every sampled record. The window
helper retains **6,968** samples, zero foreground observations, and reports no
desktop read or focus request.

Capture continuity remains separate from native audio accounting. Window
coverage intervals above 100 ms are 366.9650, 150.1227, 567.1401 and 417.0064 ms.
Process-audio packets contain four timestamp gaps beyond a two-frame tolerance:
299.8776, 550, 370 and 4.7258 ms, despite zero returned packet flags. These are
retained coverage/storage limitations, not automatically native underruns or
confirmed physical audio/display freezes.

The separate cold-playback case owns the five held-out picture/PCM timing
matches. No new correlation here establishes physical/perceptual synchronization,
all-frame display cadence or historical stutter root causes. Recovery, clean
native accounting and bounded ownership pass; the explicit renderer handoff
limit and the remaining Step 3 cases remain visible.
