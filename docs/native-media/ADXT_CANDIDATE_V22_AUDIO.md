# V22 three-source native audio retest

V22 passes the room transition that stopped V21. Two read-only samples show
three C4 sources in playback state 3 together, at 458.672 and 459.672 seconds in
the control capture. The three-source membership guard remains enabled. The
game reaches the bar with its HUD and responds to an owned movement input.
This confirms the missing-route correction for this exercised case, not complete
waveform, game, timing or Step 3 equivalence.

The sealed game source is `1690d61ffaa169b707a14da963b2216ea9fa48e0`, with matching
131-patch SDK sources. Kit SHA-256:
`70ee8b7394319c836c773a858267a86aed5c63132312ee93588335a8df2f9d83`.
Executable SHA-256:
`cf3837e1aa331963fe12f0cfa302088e61f1621fff721a6f41eeb6330b6a98bc`.
All 2,413 units are freshly built, no objects reused, in 1,324.562 seconds.
The normal 4 GiB build-start reserve is retained. The later bounded minimum
extension and observation-tool changes do not alter this sealed executable.

The private session is `build-native-sjuni/playtests/adxt-ordinary-v22`, PID
257456, creation identity `134386083327785920`. It runs from 10:45:32 to
10:57:47 UTC for 734.766 seconds. Two short Cross inputs select Kevin and Normal;
the movie is not skipped. Focused captures retain startup, menus, the cinematic
and bar. An Up input moves the local actor from approximately
`(8364.501, 0, 13173.024)` to `(8450.749, 0, 13059.738)` in the retained actor
snapshots. NPC changes and input timing are asynchronous observations.

The explicit source-only joined report records:

```text
[NATIVE-ADXT-SOURCE-REPORT] joined=1 frames=34180800 signal_frames=32026716 underrun_frames=0
```

The complete output report has the same frame/signal/underrun totals, zero hard
failures, zero queue rejections, joined source/output owners, and 71,210 submix
calls with zero submix failures. Do not add these reports: the complete output
already contains the private source mix. RAM retirement reports no active slots
or operations. Its 1,451 packet-log diagnostic refusals remain recorded; they
are not silently reclassified as audio failures or erased. The asynchronous VIF
worker reports all 126,279 submitted operations completed with zero failures.

An owned WM_CLOSE request ends the game. The supervisor records exit zero,
zero fatal diagnostics and outcome `exited-no-fatal-diagnostic`; its generic
`runVerdict` remains `not-evaluated`. That verdict is not rewritten into a
whole-game pass. Original shutdown emits `PS2 Thread Exit`, followed by the
joined reports. No game or compiler remains running after this test.

The broad sampler completes 600 records; a later inventory observation completes
60 records. The independent 2 Hz observer retains 1,421 partial samples and its
original WinError 299 during process teardown. These are not atomic snapshots or
invocation counts. Start opens the inventory; the captured global and source
pause flags remain zero. This does not validate actual audio pause/resume.

The finalized movie trace retains 4,160 recent/longest slow events and lacks
individual details for 19,658 other slow events; invalid and saturation counters
are zero. Maximum owner-control, batch-fence and decode spans are 57.1365,
19.0051 and 10.0721 ms. Four CPU presentation-return intervals exceed 50 ms:
139.2810, 349.2186, 61.0472 and 78.0996. The 61.0472 ms interval overlaps a
57.1365 ms owner-control span. Nesting and host descheduling prevent assigning
that elapsed time as a root cause. Different input timing, duration and cache
history prevent treating the V21/V22 timing difference as a controlled stutter
performance comparison. The end-of-movie stutter remains unresolved.

The read-only LSC capture measures original capacities 272,384 bytes for the
stereo handles and 53,248 for mono, with default minimums 217,907 and 42,598.
These exceed the native live input's 8 KiB profile. Larger actual source/window
buffers, broader LSC/external-SJ/callback lifecycles, actual native movie graph
binding, pause/skip/reopen/error transitions and full A/V validation remain
Step 3 requirements. The PC has not been put to sleep.

Exact receipt/evidence hashes are in
`tools/native_reconstruction/adxt_v22_game_qualification.json` and the completed
session's movie/audio analysis files.
