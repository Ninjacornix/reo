# V25 native MP4 game test

The native MP4 route now plays in the actual game, including title playlists,
repeating title/character backgrounds, the complete opening, the nine-clip
scenario sequence and its transition into the bar. This is successful consumer
integration, not Step 3 completion: a measured handoff stall, source-audio
underruns, remaining controls and packaging still need work.

The sealed source is `648637729c43b466f4e994e592230c8188a7ce7d`.
The executable SHA-256 is
`739d349c442e9d32fb1ed3123982ec0e4f07d50a0eeaf3f806c0eb806afb47b3`.
The matching SDK131 candidate builds in 183.922 seconds, retaining the normal
4 GiB start reserve. The ordinary worker checks every input/object signature;
only the modified native cue adapter needs recompilation. The complete parent
build and verified cache provenance remain in the private build receipts.

The private session `build-native-sjuni/playtests/native-mp4-v25` runs from
15:15:21 to 15:27:37 UTC on 2026-11-08, 735.219 seconds. Its PID is 263220,
creation identity 134386245218018061. Native media selection is explicit;
`REO_GPU_MOVIE=0`. No experimental geometry/VU path is enabled by tracing.

The game selects 25 native movie entries and all 201 prepared references.
The adapter resolves real container ranges to native resource keys; playback
uses MP4s and Windows Media Engine, without opening/feeding the original SFD.
The six source starts include a six-clip playlist, two independent single-clip
loops, the 6,144-picture opening, a nine-clip scenario playlist and a final
single clip. The native owner reports 12,180 delivered game frames and joined
shutdown, with `error=none`. Two identical shutdown report lines represent one
owner; their counters are not added.

All 2,985 bounded control observations show the eight original MWSFD player
slots inactive. Captures show the character screen, opening, scenario sequence
and gameplay. The player actor's position changes after controlled inputs;
NPC combat and asynchronous snapshots prevent assigning every displacement
solely to those inputs. A normal, owned WM_CLOSE ends the test.

## Remaining measured problems

The 100 Hz public-frame observer retains 69,769 samples. During the opening,
frame 4,270 stays published for 528.5488ms, then advances to 4,286. Its CSV
evidence is at lines 27,448 and 27,499. Observer sample spacing in that interval
never exceeds 10.5548ms and the longest memory read is 0.1424ms. This is not an
observer scheduling gap.

The corresponding presentation-loop observations continue: maximum start gap
17.4441ms, maximum observed span 0.8809ms in the incident window. That locates
the symptom outside a half-second presentation-loop freeze. It does not prove
whether the native producer, readback, game movie service or guest scheduling
delayed the frame. The renderer can keep presenting an old image while another
stage stalls. Separate native-producer and consumer timestamps are next.

The complete native audio output reports 34,109,760 frames, 31,842,899 signal
frames and **100,736 source underrun frames**, with zero hard failures and queue
rejections. All source/output owners join; RAM retirement has no active slots
or operations. The 1,456 packet-log diagnostic refusals remain recorded and
separate from audio failures. Aggregate underruns have no per-event timestamps
and cannot be assigned to this video incident. The earlier V22 run had zero
source underruns, but different timing/duration prevents a controlled regression
or root-cause claim from those totals alone.

Process-only audio capture records 34,709,280 stereo frames, PCM16 peak 22,529
and RMS 2,875.116, with no OS capture discontinuity or timestamp-error flags.
Those flags concern capture and do not erase the application's source underruns.
The user was away from the PC; audible synchronization is unconfirmed.

## Evidence limits

The presentation trace retains 32,768 rows and reports 9,910 dropped later rows.
It covers the named opening incident; it is not complete session coverage.
The high-frequency observer retains its teardown WinError 299 and partial
receipt. The control observer completes its bounded 600-second window. Audio
capture finalizes on target-process exit.

The supervisor's historical `run.json` calls this a native failure because the
new generic execution-error classifier also matched the runtime's normal
`PS2 Thread Exit` shutdown message. The corrected classifier has a regression
check for that exact normal message. The new analysis reports zero fatal
diagnostics and `exited-no-fatal-diagnostic`; the original receipt is preserved.
That outcome is not converted into a whole-game or Step 3 pass.

`tools/native_reconstruction/analyze_host_movie_playtest.py` produces the
completed session's `native-movie-analysis.json`, including evidence hashes,
incident references, original-slot observations and both audio reports.
