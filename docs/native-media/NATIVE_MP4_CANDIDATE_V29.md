# V29: audio shortage isolated during regular servicing

The native `GameSession` route completes opening/scenario playback and bar
gameplay, then exits normally in 501.615 seconds. The new audio-control trace
exports 28,682 snapshots with zero drops or invalid rows. Native source/output
owners join; hard failures, queue rejections and submix failures remain zero.
Step 3 is incomplete; subjective A/V sync is unconfirmed while the user is away.

Runtime source is `9166a4af82a6073644cf7be59edf7afe25dbd39c`, launcher source
`a622a0eb`. The executable SHA-256 is
`d83e930e08e72dfc8ae54cbe90e0448bff6567dc8f439d9a202f50ad7c06eb96`.
The SDK131 build takes 189.297 seconds and reuses 2,414 of 2,415 units. This adds
diagnostic observations; it does not change audio refill or scheduling policy.

There are 17,376 measured source-underrun frames. All increases occur in 23
observation windows within a 383.3659 ms interval, QPC nanoseconds
`262038693304800..262039076670700`. The affected stream is native slot 1,
generation 1. Its queue empties, its late-sample counter increases, and subsequent
PCM is skipped to catch up. Endpoint gain is 1 and playback remains active.
These observations do not independently establish subjective audibility.

Audio control observations continue every 16.602–16.7745 ms during the shortage;
the maximum interval over the entire capture is 44.7949 ms. This rules out a
long missing-control interval as the explanation of this incident. It does not
rule out source-worker scheduling, input I/O, decoder or refill behavior.
Do not replace the scheduler solely on the basis of the older aggregate counts.

The shortage occurs about 0.9 seconds into the first scenario clip. Native movie
consumer requests still obtain fresh pictures. The first correlated producer
interval is 34.2231 ms. The nearest independent C4 observations retain slot 1's
request at root-relative sector 10,413 for 2,546 sectors. The owned asset
inventory has one matching root-relative extent: `NETBIO01.DAT/0/10`,
`adxsnd.afs/s010100a.adx`, 5,212,998 bytes, stereo 48 kHz, 4,633,715 samples.
This is an extent-based candidate identification; the canonical filename was
not separately traced. A controller/source snapshot is needed to distinguish
encoded-input completion from decoder/refill work before choosing a fix.

All 6,144 opening pictures publish, ordinals 0–6,143, maximum producer interval
58.683 ms and zero backpressure. The movie owner joins with five source
generations, 11,601 delivered frames and no error. Original MWSFD slots remain
zero in all 384 state samples. The memory observer's partial teardown and
WinError 299 remain recorded. Process-only audio capture contains 18,007,680
PCM frames, peak 22,529, with zero OS discontinuity/timestamp flags; it ends
when the owned process exits after 376.016 seconds of capture. Those flags do
not negate application underruns. Packet-log diagnostics remain separately
recorded as 205 observations.

The new analyzer preserves short shortages, avoids multiplying aggregate counts
across streams, and handles replacement, counter resets, dropped observations
and truncated rows. Seven regression tests pass. Source/evidence identities
are pinned in `tools/native_reconstruction/host_movie_v29_audio_qualification.json`.
Private evidence is in
`build-native-sjuni/launcher-native-prep-v1/sessions/20261108-203823-363`.
Lower underrun totals than V28 are not proof of an improvement or a fix.
