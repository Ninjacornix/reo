# V31 exploratory media clock comparison

The retained V31 opening does not show a large accumulating discrepancy between
the inferred native mixer input cursor and the video ordinal timeline. This is
an exploratory rate comparison, not audible synchronization validation or an
authored phase reference. Step 3 remains open.

The comparison selects movie generation 4 / clip 0 and native output slot 0 /
generation 2 explicitly. The independent C4 resource observation identifies the
E3 soundtrack extent, sector 341548 / 5411 sectors, consistent with the owned
`NETBIO01.DAT/0/410` asset. C4 slots and native output slots remain distinct
namespaces; their numbers are not treated as an identity proof.

For the finite prefix from video seconds 5 through 195, 5,695 publications match
a preceding audio snapshot. The estimate is
`(copied_samples - queued_left) / frequency`, compared with video
`ordinal * 1001 / 30000`. The two channel queue counts agree, and selected rows
have no late/skipped samples or recorded underruns. No selected point exceeds
the real source sample count, excluding padded end-of-stream data. Both input
traces retain zero dropped records and no invalid audio rows.

| Observation | Result |
| --- | --- |
| Median cursor-minus-video difference | -57.933 ms |
| Early median, seconds 5..25 | -56.900 ms |
| Late median, seconds 175..195 | -60.150 ms |
| Late minus early | -3.250 ms |
| Largest preceding-snapshot gap | 17.6604 ms |
| Largest source-observation age | 17.6617 ms |

The early/late difference is smaller than the observation spacing. These
asynchronous counters do not establish a 58 ms audible lag: audio endpoint
buffering, display scanout and the content's intended phase are not measured.
They do not justify adding a timing correction. A stable long-term relationship
also does not exclude individual hitches. No new game was run for this analysis.

The private reproducer is `build-native-sjuni/compare_v31_media_clock_v1.py`.
Its report and per-pair line references are in the original session folder,
`build-native-sjuni/launcher-native-prep-v1/sessions/20261108-221600-845/`, named
`exploratory-media-clock-comparison.json` and
`exploratory-media-clock-pairs.csv`. Hashes and limitations are recorded in
`tools/native_reconstruction/media_clock_comparison_v31.json`.
