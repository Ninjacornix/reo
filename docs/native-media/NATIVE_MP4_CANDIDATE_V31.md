# V31: native read-ahead game retest

The native 64 KiB encoded-source profile completes opening/scenario playback,
reaches bar gameplay and closes normally after 501.741 seconds. Native source
and output owners join. Recorded audio underruns, hard failures, queue
rejections and submix failures are zero. This validates the new profile on this
route; it does not identify the historical intermittent incident's root cause
or complete Step 3. Subjective A/V synchronization remains unconfirmed.

Runtime implementation is `ac8109f3e0c4577edf8828eed59625a0111c1372`, launcher
source `a35c5ddb`. The sealed SDK131 build takes 179.141 seconds. Executable
SHA-256 is `3289aefe15aac05198a2b2d1836e458835f758607bcfef557972be056bbdcdc1`.
The normal build reserve is retained; superseded artifacts and identical old
payloads were cleaned/consolidated before this build.

The native audio trace exports 28,754 control snapshots with no drops or invalid
rows, including 38,300 source-known stream observations. All known source
capacities are 65,536 bytes, confirming the selected profile in the running
candidate. Maximum controller observation interval is 27.9221 ms. Final output
totals are 22,987,200 frames and 20,932,050 signal frames, with zero underruns.
RAM ownership retires with zero active slots/operations; 201 packet-log
diagnostics remain separately reported rather than being relabelled as success
or audio failure.

All 6,144 opening pictures publish, ordinals 0 through 6,143, maximum publication
interval 51.7246 ms and zero backpressure. The nine scenario clips publish all
2,870 pictures, ordinals 0 through 2,869. The largest within-clip scenario
interval is 40.4976 ms. The title-loop maximum is 52.53 ms. These retained shorter
intervals are not a claim of perfectly uniform presentation; the earlier roughly
0.8-second producer stall does not reproduce. The native movie owner joins with
five source generations, 11,670 delivered frames and no error.

The 430-second memory observer completes with 41,021 progress records, 427 state
observations and no errors. Original MWSFD slots are zero in all those samples.
A separate identity-checked capture at 484.261 seconds after process creation
shows Kevin and NPCs in Jack's Bar; its public movie handle is zero and final
frame ordinal is 2,869. The before/after state samples are retained separately.
The main observer alone does not cover that final room interval.

Process-only audio capture covers 486.412 seconds after its later start, with
23,295,360 PCM frames, peak 22,529, RMS 2,655.931 and zero OS discontinuity or
timestamp flags. It ends when the owned game exits. No microphone or endpoint
mix is captured. This evidence does not establish subjective audible sync or
cover the entire process lifetime.

The [native read-ahead qualification](NATIVE_AUDIO_PREFETCH.md) separately
demonstrates improved tolerance to a controlled blocked source read. V30 already
has two clean runs without this buffering change, so one clean V31 run is not a
controlled treatment effect for the historical shortage. Required queued-audio
consumers, broader transitions, A/V validation and effect/shared-initializer
accounting remain open. Renderer and guest-control interfaces remain explicit
staged migrations.

Evidence is pinned in
`tools/native_reconstruction/host_movie_v31_prefetch_qualification.json`.
The immutable session bundle, copied launch/lifecycle receipt, final room image
and PCM capture are in
`build-native-sjuni/launcher-native-prep-v1/sessions/20261108-221600-845`.
Neither this harness nor prior launcher-core runs construct the Avalonia UI.
