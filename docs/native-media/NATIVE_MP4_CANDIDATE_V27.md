# V27 matched native movie frame-path comparison

Both tested frame paths play the complete opening and scenario playlist, reach
the bar and retire cleanly with zero source-audio underruns. The earlier large
movie publication stall does not reproduce in either run. This is a successful
retest, not a confirmed decoder/driver fix or Step 3 completion.

Both use source `c5556a5b054be19f404ac964c52e1024ae814f7c`, executable SHA-256
`d0c4005b7627efae1b8cc11e4fd879b3870e542cdef2794fed0057b61bcd70a1`,
SDK131 and the same complete prepared MP4 cache. Building takes 174.344 seconds
after normal input verification, with 2 modified units and 2,413 verified reused
objects. The normal 4 GiB start reserve remains enforced. The first attempt stops
before compilation for insufficient space; reversible compression permits resume.

| Observation | Software/WIC | DXGI-enabled |
| --- | ---: | ---: |
| Private session | `native-mp4-v27` | `native-mp4-v27-dxgi` |
| PID / creation FILETIME | 276364 / 134386302582158119 | 273836 / 134386308181927334 |
| Supervised duration, seconds | 507.656 | 541.734 |
| Opening native publications / unique ordinals | 6,144 / 6,144 | 6,144 / 6,144 |
| Opening first / last ordinal | 0 / 6,143 | 0 / 6,143 |
| Largest opening publication interval, ms | 39.1757 | 46.9211 |
| Native movie source generations | 5 | 6 |
| Game-consumed native frames, all sources | 11,559 | 12,057 |
| Original MWSFD slot observations / nonzero | 2,472 / 0 | 2,639 / 0 |
| Audio output frames | 23,161,440 | 25,024,320 |
| Audio signal frames | 21,134,610 | 22,863,517 |
| Source-audio underrun frames | 0 | 0 |
| Audio hard failures / queue rejections | 0 / 0 | 0 / 0 |

Kevin selection is scheduled at 129 seconds and Normal at 142 seconds from each
process launch. Actual command times differ by less than 30 ms between runs.
The later bar dwell differs by about 34 seconds and the DXGI run starts an
additional short movie, so total frame counts are not treated as a performance
comparison. Both scenario playlists reach ordinal 2,869, the final picture of
their 2,870-picture nine-clip sequence. Captures show subsequent gameplay. Both
receive an ordinary owned WM_CLOSE, report joined movie/audio owners, and exit
with no fatal diagnostic. No independent scanout or subjective A/V proof follows.

## Observer gaps versus actual delivery

The software progress CSV's largest opening gap is 232.2764 ms at public frames
3,188–3,195. Its observer itself misses 211.1312 ms. During that interval the
consumer records seven requests, **all with fresh frames**, at no more than
33.6254 ms spacing. Native publication continues normally. This observation
does not establish a movie freeze.

The DXGI CSV's largest opening gap is 125.304 ms at frames 2,582–2,585. Its
consumer likewise obtains three fresh frames at no more than 33.3524 ms spacing.
The analyzer classifies these as observer sampling gaps with continued fresh
consumer frames. It retains the raw observations and bounds rather than deleting
them. Other short public-frame intervals near 73 ms remain observations; producer
timing and independent display cadence must not be conflated.

The analyzer now reports publication epochs separately across source, clip and
loop changes. It never counts time spent in another clip as a same-clip freeze.
Seven regression cases cover absent traces, incomplete observations, source/loop
boundaries, periodic heartbeat fields and an observer stall while delivery stays
healthy. Both producer/consumer traces report zero dropped rows; presentation
trace retention remains recorded in each analysis.

## Audio and limits

Process-only captures contain 23,803,680 and 25,440,960 stereo PCM frames,
respectively, with peak 22,529 and no OS discontinuity/timestamp-error flags.
Application source-underrun totals are independently zero; OS flags alone do not
establish that. Packet-log diagnostics remain recorded (219 / 259) and are not
relabelled audio hard failures. Memory observers preserve their partial receipts
and process-exit/WinError 299 teardown errors.

The user is away. Audible synchronization is unconfirmed. Earlier V25/V26 stalls
and underruns remain historical evidence whose cause is unknown; absence in
these runs does not prove that either path fixes them. The software path remains
an explicit comparison option, and DXGI remains the default. Game control/error
transitions, packaging, the effect-MOV consumer and retirement of remaining media
bridges are still required before Step 3 closes.

Results are pinned in `tools/native_reconstruction/host_movie_v27_game_qualification.json`.
The detailed session analyses are `native-movie-analysis-v3.json` (software) and
`native-movie-analysis-v2.json` (DXGI); earlier analyses remain preserved.
