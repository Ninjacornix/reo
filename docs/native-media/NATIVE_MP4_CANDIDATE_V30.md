# V30: native source observations and clean repeat

The source-detail diagnostic candidate completes two independent launcher-core
opening/scenario/gameplay runs and normal shutdown. Neither run reproduces the
V29 audio shortage. This candidate changes diagnostic fields, not buffering or
scheduling, so these are clean observations, not evidence of a fix. Step 3 is
still open; the user is away and subjective A/V synchronization is unconfirmed.

Runtime source is `58c7e0c9b5bd22b8b6db9955afd9c7c05f1e8700`. The executable
SHA-256 is `ccaf6c508a63e48aae0225c9bfda07a1386c00da6abf859004aab32b9e2159f2`.
Its SDK131 build takes 170.109 seconds, reusing 2,414 of 2,415 units. Launcher
base source is `a622a0eb`. The repeat additionally enables the existing
`REO_CRI_SERVER_SLOW_MS=20` logger in the explicit native diagnostic route;
its exact launcher source hash is retained in the repeat qualification.

| Observation | First run | Repeat |
| --- | ---: | ---: |
| Session | `20261108-211735-335` | `20261108-213448-449` |
| Duration, seconds | 503.698 | 503.341 |
| Control snapshots | 28,676 | 28,763 |
| Source-known stream rows | 38,316 | 38,420 |
| Dropped snapshots / invalid rows | 0 / 0 | 0 / 0 |
| Maximum service interval, ms | 25.7229 | 21.9068 |
| Native audio underrun frames | 0 | 0 |
| Unique opening pictures | 6,144 | 6,144 |
| Maximum opening publication interval, ms | 39.8469 | 40.7023 |

Both runs retain all opening ordinals 0 through 6,143 with zero backpressure.
Native owners join normally. Source/output failure and retirement evidence is
retained separately from packet-log diagnostics. The source trace now records
encoded ring occupancy, outstanding read identity/progress, decoded/copied
samples and the observation timestamp. These fields can separate an input
shortage from stalled decoding if another incident occurs. A clean interval
cannot identify the cause of the earlier incident.

The repeat's process-only audio capture starts late and covers 244.620 seconds,
not the whole launch. Its zero OS discontinuity/timestamp flags do not establish
audible synchronization. Neither test constructs the Avalonia launcher window.
Independent memory-observer teardown remains partial and explicitly recorded.

The immutable launch/lifecycle receipts are copied inside each session directory
under `build-native-sjuni/launcher-native-prep-v1/sessions/`. Evidence hashes,
native aggregate reports and coverage limits are pinned in
`tools/native_reconstruction/host_movie_v30_source_qualification.json` and
`host_movie_v30b_source_qualification.json`. The historical V29 shortage remains
unexplained. A separately tested native prefetch change must not be described as
its confirmed root-cause fix.
