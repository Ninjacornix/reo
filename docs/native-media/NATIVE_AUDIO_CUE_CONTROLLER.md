# Native queued-audio consumer binding

The finite queued-cue controller and File #1 engine command adapter are
implemented. Both compilers pass the complete 80-suite native project. Private
declared-port tests exercise real imported audio through the adapter; this is
not yet evidence that a new game candidate exercised those queued commands.
Step 3 remains open.

`audio_cue_queue::Queue` accepts retained native resource views and cue IDs,
prepares metadata on the shared bounded loader, and feeds ready clips to the
native player. Its pending-header fence preserves accepted next clips while
their preparation is incomplete. At most 16 cues are outstanding. The controller
contains no guest pointers, emulated queue objects, original file producers,
RPC or hardware transport. Its operations share the native instance owner's
serialized admission and never wait for source reads there.

Stop cancels metadata tickets and requests real source retirement. Replacement
waits for the previous read/output ownership to drain. A blocked-source test
checks that the second source cannot open until the first read is released,
then checks all 4,097 replacement samples. A failed preload leaves an unrelated
ordinary voice running. The shared metadata worker joins after the canonical
source/device owners and emits an explicit retirement report without reading
guest RAM.

The game adapter resolves checked AFS descriptors to retained extents in the
same verified native mount. Enqueue, start, count, playlist repeat, stopped reset,
stop and child destruction use native owners. The selected profile now has
22 entries and advertises `queued_assets=finite_native`. The filename entry
accepts mounted root filenames; this does not establish arbitrary named-member
resolution. Existing raw-memory/file producers and nonzero before-PCM callbacks
remain refused rather than invoking an original producer.

Ordinary embedded-loop preference persists across finite playlist playback.
It does not implicitly repeat that playlist; native playlist repeat is explicit.
The stable owner records source kind independently of the decoder's transient
seamless flag, which can clear at end of input. Explicit inline-loop requests
on finite sequence sources still fail admission, and ordinary playback reapplies
its own saved loop preference afterward. The first 80-suite attempt caught the
transient-identity mistake and an obsolete test expectation; those failed logs
and their original manifest remain available.

The standalone paired delayed/prepared playlist comparison checks 32,000
samples and both channel digests, pending metadata, cancellation, overflow,
channel/header refusal, repeat changes and ownership. The real adapter cases
cover finite playback, the full E3 soundtrack, append, repeat and two malformed
AFS descriptors. Finite PCM results compare against the independent, previously
qualified imported-asset baseline: 189,476 samples/channel for the short stereo
cue and 9,849,840 for E3. Controls use zero original calls during queued playback;
the later ordinary Stop control retains its existing metadata cleanup. Final
source/metadata join is checked with guest memory inaccessible.

Evidence is under `build-native-sjuni/media-cue-controller-results-{llvm,gcc}-v2`
and `build-native-sjuni/adxt-binding/ordinary-cue-controller-{llvm,gcc}-v1`.
The adapter also compiles against the actual audited SDK131 headers in
`ordinary-queued-cues-actual131-llvm-v2`. Complete ordinary-adapter regression
now passes all 34 scenarios and detects all 10 injected faults on each compiler;
its immutable-import statistics and manifest remain unchanged. Evidence is in
`ordinary-cue-controller-regression-{llvm,gcc}-v1` and
`tools/native_reconstruction/native_cue_controller_qualification_v1.json`.
The next coherent game retest remains a separate gate. The existing
89 inline-loop asset refusals remain unchanged; this finite profile does not
claim their queued playback or establish their actual game usage.
