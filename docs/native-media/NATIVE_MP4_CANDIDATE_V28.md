# V28: real launcher core path and native media retest

The real `GameSession.Launch` path prepares and starts native media from an
ISO-selected source, completes the opening and nine-clip scenario, reaches bar
gameplay, and exits normally. Native resource, ordinary ADX, complete audio and
MP4 selection are observed. No Avalonia launcher window is constructed.

Runtime source: `9d8e7611f7e86756143a356663ddffa406f3e43f`, SDK131. All 2,415
units rebuild without a seeded object cache in 1,827.937 seconds. Executable
SHA-256: `6bb5aa20bd68c760bf90cf3b69064009aea316e1f6a3fb2cb0948edee29db8ac`.
This includes the [public time correction](NATIVE_MP4_PUBLIC_TIME.md), but the
route does not identify a specific live time-query invocation or connect that
correction to a historical stutter.

Launcher changes remain locally on `fix/launcher-progress-overlay`, through
`bec6ebe1`. The first test exposes a missing imported-resource selection for
ISO sources: movies install but audio refuses with installation status 4
(`memory_unavailable`). Its overly permissive smoke receipt incorrectly labels
movie selection and early normal exit as a pass. That receipt is preserved and
explicitly superseded. The corrected environment installs the full composition;
the next test is closed early because unfocused test input does not advance
character selection. The third enables existing private-pad diagnostic input
and completes the actual route. The stricter smoke check requires the resource,
audio and movie handshakes, requested duration, and normal retirement.

Final game: PID 273656, creation FILETIME 134386372366505627. The launcher uses
its verified private image with the executable hash above, private test data and
private saves. The receipt records 501.696 seconds, normal close, exit 0 and
no native installation/refusal error. This is a launch/lifecycle pass, not a
clean-audio or Step 3 completion gate.

The opening publishes all 6,144 unique ordinals 0–6,143, maximum same-clip
publication interval 39.1872 ms, zero backpressure. The nine scenario clips
publish all 2,870 ordinals, ending at 2,869. The movie owner joins with 11,625
delivered frames across five source generations and `error=none`. Both native
traces report zero dropped records. All eight original MWSFD slots remain zero
in all 427 read-only state samples. A retained screenshot shows bar gameplay.

The largest public-frame observation gap, 542.9971 ms, is an observer pause:
all 16 consumer requests during it receive fresh frames, maximum spacing
33.7523 ms. Desktop screenshots pause this observer. Native traces are correlated
before classifying gaps; the raw observation alone is not a movie freeze.

Audio is **not clean**: 22,973,280 output frames, 20,846,574 signal frames and
**120,448 source-underrun frames**, with zero hard failures, queue rejections or
submix failures. Native source/output owners join; sound RAM retires with zero
active slots/operations. Its 205 packet-log diagnostics remain separate.
Process-only capture contains 20,127,840 PCM frames, peak 22,529, with zero OS
discontinuity/timestamp flags. Those flags do not negate application underruns.
The aggregate does not locate their time, source, or cause. No fix is claimed.

Twenty launcher protocol checks pass. The Windows desktop build succeeds with
its existing warnings. Evidence is under `build-native-sjuni/launcher-native-prep-v1`,
especially `sessions/20261108-194707-685/launcher-media-analysis.json`, native
traces, observer receipts, screenshots and process-only audio. Source/evidence
hashes, including both failed/limited tests, are pinned in
`tools/native_reconstruction/host_movie_v28_launcher_qualification.json`.

The user is away; subjective A/V sync remains unconfirmed. Required source
profiles, broader controls/resource transitions and the
[retirement audit](MEDIA_RETIREMENT_AUDIT.md) remain open. Step 3 is incomplete;
the conditional PC sleep action has not run.
