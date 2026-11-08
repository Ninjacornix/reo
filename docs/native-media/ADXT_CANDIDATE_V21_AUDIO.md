# V21 ordinary native audio and third-source refusal

The private V21 game test produces audio and reaches the opening in-engine bar
scene. It then stops at a room transition when a third source is started and its
raw mixer route is missing. This is a failed game validation, not Step 3 closure.

The sealed source revision is `0072a41f1aa82736245506e06082043a48195959`.
The kit manifest SHA-256 is
`859e6d9f9e328cec1f54d9a6f8fc8303d2c0640a8abd64a592f8673558c6d87c`;
the linked executable SHA-256 is
`b59fbd9abb2f86ebcbb648841c2bcad8e67df65716119ea92b6678789f30e356`.
All 2,413 units were built with matching SDK130 inputs, no reused objects and the
normal 4 GiB free-space reserve. The build took 1,264.844 seconds.

Evidence stays in `build-native-sjuni/playtests/adxt-ordinary-v21`. Its owned
process is PID 242076, creation identity `134386038641033691`, with a private
executable copy. The run lasts 478.640 seconds. Two short focused inputs select
Kevin and Normal; no subsequent movie-skip input was sent. Captures retain the
character menu, blood opening and in-engine bar scene. At stderr line 8559:

```text
[NATIVE-ADXT-REFUSAL] boundary=active-raw-route-missing address=0020f3c8 status=0; no original-source fallback
```

The supervisor reports `native-failure` despite process exit zero. The final
complete audio report records 21,985,440 output frames, 19,992,711 signal frames,
zero underrun frames, zero hard failures and zero queue rejections. Source and
output owners join; all 45,803 private submix calls succeed. Native source state
also advances to playback phase 3. These are actual selected-native-source
observations. The signal counter combines sources and bank output; it does not
attribute every nonzero frame to ADXT alone or establish waveform/A/V parity.
The next candidate adds a separate joined private-source statistics report.

The independent media observer retains 914 partial samples. The broader control
capture retains 458 samples, including bounded RNA records, before the owned
process exits. Its original failure receipt is retained. Stable asynchronous
records show RNA routes `1e0140`, `1e0160` and `1e0180`; these are read-only
observations, not atomic snapshots, runtime host-map contents or call counts.

The offline movie analysis retains full schema-2 aggregates plus 4,159 recent or
longest slow events; 20,970 other slow events lack individual detail. Invalid
interval and saturation counters are zero. Maximum measured spans are 53.3366 ms
for owner control, 38.6808 ms for batch fence and 9.9950 ms for decode. There are
two CPU presentation-return intervals at least 50 ms: 107.6663 and 69.5604 ms.
The latter overlaps one retained 53.3366 ms owner-control span. This establishes
elapsed observations, not causal responsibility or physical scanout timing.
No initializer stage timing line was recorded. The prior end-of-movie hitch is
not declared fixed or reproduced by these observations.

The actual runtime's `dtxConsumeActivePs2RnaStreamsLocked` configures every RNA
row in its unsorted host table before skipping muted rows. Replacing the entire
ordinary group also skips that metadata registration. A separate metadata-only
handoff is being qualified against that original traversal; the read-only PCM
order capability and the three-source membership guard remain in place.

Exact evidence hashes and limitations are in `movie-work-analysis.json`,
`movie-work-analysis.md`, `audio-candidate-analysis.json`, `run.json` and the two
sampler receipts beside the traces. The stderr SHA-256 is
`7baa3d6713e02a4baffc775f55be0252c5693da1882432667c18387174c65a7b`.

Step 3 still needs actual three-source integration, broader source lifecycles,
movie graph binding, resource/room transitions and complete audio/video tests.
The PC has not been put to sleep.
