# V35 native movie/audio pacing retest

Completed session `20261109-033631-629` runs for 424.8529499 seconds and closes
normally with all media owners joined. The full E3 movie publishes every ordinal
`0..6143`. Its largest publication interval is **72.3295 ms**, with one other
interval above 50 ms and none above 100 ms. This is a measured short delay,
not a stutter-free result. The earlier large video/audio incidents do not
reproduce here; their root causes and fixes remain unconfirmed.

The sealed root revision is `4dc0e82bb66a2a7e76e21e1a98d485fc06f3e645`;
executable SHA256 is
`fbe53cc5c3784ae4825be82a07b46e47ab75428f473b6ad5f324e5234bb663f8`.
This test uses actual native movies and queued companion audio through the
launcher-core route. Compilation/kit preparation overlaps the late run, and
window-only capture and process-audio recording also add work. This is a
functional/pacing retest under that load, not an isolated benchmark.

## Movie observations

The producer retains 10,912 rows and consumer 10,889, both with `dropped=0`.
Consumer rows include 10,769 fresh-frame acquisitions, matching the final native
delivered-frame total. Zero drops means no loss from those bounded trace
buffers; producer recording still omits most fast empty polls. Ordinal resets
split repeated menu loops into separate epochs. Startup, cue replacement and
loop boundaries are excluded from within-epoch publication-gap counts.

Across all epochs there are seven publication intervals strictly above 50 ms,
none above 100 ms, and no recorded backpressure. The complete E3 epoch is
generation 4, clip 0, producer CSV lines `364..6507`, with 6,144 publications,
6,144 unique consecutive ordinals and zero backpressure.

| Generation / ordinals | Producer CSV lines | Publication interval (ms) | Largest measured section in the interval |
| --- | --- | ---: | --- |
| 4 / 5769 → 5770 | 6133 → 6134 | 72.3295 | Readback 39.0854 ms |
| 9 / 12 → 13 | 9644 → 9645 | 59.7824 | Readback 26.1893 ms |
| 9 / 28 → 29 | 7845 → 7846 | 59.5228 | Readback 26.5391 ms |
| 9 / 80 → 81 | 9107 → 9108 | 58.7336 | Wake 22.5488 ms |
| 9 / 180 → 181 | 9208 → 9209 | 57.2646 | Wake 24.6534 ms |
| 9 / 93 → 94 | 9120 → 9121 | 53.9926 | Transfer 13.6416 ms |
| 4 / 939 → 940 | 1303 → 1304 | 52.2598 | Wake 14.7721 ms |

Generation 9 is the later repeating menu source; equal ordinal ranges in
different loops are distinct epochs. These five late delays do not belong to
the full E3 playback.

The largest E3 interval is QPC nanoseconds
`287037555541900..287037627871400`. The following frame's measured wake,
transfer and readback sections take 1.0031, 0.2891 and 39.0854 ms respectively.
Another 31.9457 ms lies outside retained iteration spans, including ordinary
frame cadence, unrecorded work and possible scheduling. It is not evidence
that the worker was idle for that time. Three consumer requests occur inside
the interval, one obtaining a fresh picture; the game continues requesting
frames while the next publication is delayed.

The readback section contains `CopyResource`, staging-resource `Map`, CPU pixel
copies and `Unmap`, plus possible thread scheduling. The trace localizes the
largest measured operation bucket but cannot distinguish GPU wait, driver,
memory copying or preemption inside it. No inner root cause is established.

| Maximum retained section | E3 generation 4 (ms) | Entire run (ms) |
| --- | ---: | ---: |
| Wake / condition wait | 17.4294 | 26.3750 |
| Controls | 3.2754 | 19.4538 |
| State / source and target preparation | 10.2553 | 28.7947 |
| Transfer | 15.1045 | 30.0313 |
| Readback | 39.0854 | 39.0854 |
| Publication | 0.0282 | 0.0319 |

These maxima occur at different iterations and must not be summed into a
single hitch. Wake includes the intended condition wait and scheduling;
controls/state include initialization work on startup. Maximum consumer borrow
time is 0.0403 ms, pixel-copy section 5.6633 ms and frame lease 38.7950 ms over
the entire run. The last figure includes later game/render work before release;
it is not all CPU conversion time. No producer backpressure is recorded.

## Audio and historical comparison

The complete native audio report records 18,940,320 output frames, zero source
underrun frames, zero hard failures, zero queue rejections and zero submix
failures. Source/output owners join. The cue owner accepts and finishes three
commands, reports no failures and joins.

The audio-control trace contains 23,696 snapshots, zero drops, invalid rows or
counter/time resets. The existing analyzer finds zero shortage windows and zero
measured underrun increase. Its last output count is 18,939,360; the final owner
total covers the remaining 960 frames and still reports zero underruns.
Process-only loopback recording also has zero OS discontinuity/timestamp-error
flags and ends on actual process exit. Those OS flags alone would not rule out
application underruns; here the native totals provide the separate evidence.

The [V26](NATIVE_MP4_CANDIDATE_V26.md) incident had an 841.3405 ms producer
publication gap and an independently sampled 830.546 ms public-picture freeze.
The [V29](NATIVE_MP4_CANDIDATE_V29.md) audio incident accumulated 17,376 underrun
frames within 383.3659 ms despite regular controller service. Neither signature
is reproduced in V35. Different routes, source revisions and concurrent load
prevent treating the smaller V35 intervals as a controlled causal improvement.

This analysis does not establish final scanout timing, subjective audibility,
A/V synchronization or complete Step 3 closure. It reads completed evidence
only, without game execution, process access, input or window actions.

Evidence is `build-native-sjuni/native-media-v35-pacing-v1/analysis.json` and the
completed session above. The qualification binds those files, analysis helpers,
sealed V35 source files, build/package receipts and historical incident sources.
Reproduce into a fresh output directory:

```powershell
python tools/native_reconstruction/analyze_media_pacing.py --session build-native-sjuni/launcher-native-prep-v1/sessions/20261109-033631-629 --output build-native-sjuni/native-media-v35-pacing-recheck
```
