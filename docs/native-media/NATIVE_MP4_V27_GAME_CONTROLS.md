# V27 game movie skips and Pause controls

The actual game can skip the native opening and scenario playlist, return to
gameplay, open its inventory and Pause menus, and resume actor updates. The
run retires native movie/audio owners with zero source-audio underruns. This
adds control evidence; it does not complete Step 3 or confirm audible sync.

Session: `build-native-sjuni/playtests/native-mp4-v27-controls`, executable
`d0c4005b7627efae1b8cc11e4fd879b3870e542cdef2794fed0057b61bcd70a1` from
the sealed V27 source. PID 272436, creation FILETIME 134386315558616233.
The supervised duration is 309.938 seconds. The DXGI-enabled native frame path
and complete native audio backend are selected explicitly.

After Kevin/Normal selection, Start at 17:14:24 UTC skips the opening. Its last
native ordinal is 888; a new nine-clip generation starts, so this is an early
stop/replacement rather than ordinary EOF. Start at 17:14:47 skips that playlist
at ordinal 583. Captures show gameplay afterward, with no original decoder
fallback or native source error. An additional later short movie is admitted.

Start opens inventory; Circle leaves it. Select opens the visible Pause menu.
All four bounded actor-slot snapshots at 17:16:01 and 17:16:25 are identical,
including animation frames. Circle does not leave this Pause menu; the preserved
receipt named `actors-resumed.json` is another paused observation, not successful
resume evidence. Cross on the highlighted Exit action at 17:17:01 returns to
gameplay, as shown by `captures/after-exit.png`.

After Exit, the movement input is followed by changes in actor slots 0–2.
Kevin's sampled position changes from (8396, approximately 0, 13156) to
(8330.640, approximately 0, 13211.558). NPC animation and autonomous movement
mean not every changed value is attributed solely to controller input. The
paired `actors-after-exit.json` and `actors-after-movement.json` receipts establish
that updates resume after the paused snapshots.

The old raw `4BADF8` byte stays zero while the visible Pause menu is open. It
must not be treated as the native movie's pause state. These game actions test
offline gameplay pause, not pausing an actively playing movie. Native movie
pause/resume has separate actual Media Engine worker/clock tests.

The final movie report has six source generations, 2,558 game-consumed frames,
joined shutdown and no source error. All 1,490 original MWSFD slot observations
are inactive. Audio has 13,910,400 output frames, 11,780,062 signal frames, zero
underruns, hard failures and queue rejections. The 368 packet-log diagnostics
remain recorded. Process-only capture has 14,380,800 frames, peak 22,529 and
no OS discontinuity/timestamp-error flags. Both memory observers retain partial
receipts on normal process exit; the progress receipt retains WinError 299.

An ordinary owned WM_CLOSE ends the test, with no fatal diagnostic. Source and
evidence hashes are in `tools/native_reconstruction/host_movie_v27_controls_qualification.json`.
The user is away; no subjective A/V synchronization or complete room-transition
coverage is claimed.
