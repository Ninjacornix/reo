# Seventeen-cue native admission

The native controller now retains seventeen outstanding cues: one initial
request plus the original scene collector's sixteen additional iterations.
Prepared cues wait when the separate sixteen-slot transfer queue is full.
They retain their preparation tickets and pending-header fence until space
opens; they are neither dropped nor repeatedly registered. The eighteenth
outstanding cue returns an explicit capacity result.

The [original producer audit](SCENE_QUEUED_AUDIO_CAPACITY.md) establishes this
local collector limit under its documented count-ownership assumptions. It
does not establish every authored scene's maximum or exclude arbitrary
indirect mutation. No game speed, decoder format, rendering path, public
header or legacy queue layout changes.

Both compilers pass all 80 native suites with manifest
`native_cue_capacity_manifest_v2.json`. The focused regression fills the lower
queue, retains the seventeenth preparation, and decodes all 69,649 samples per
channel. Preparing the final clip in advance or delaying its metadata until
the preceding clips progress yields identical channel PCM digests. The test
also checks one submitted source, seventeen registered assets and overflow
refusal without losing accepted entries.

The first full attempts pass 79 suites but time out in the new delayed case:
the test incorrectly waits for the last partial ADPCM block before releasing
the next header. Its diagnostic retains payload 65,536, one pending cue and
sixteen registrations. The corrected test waits for earlier-clip progress,
checks that EOF remains held, then releases metadata and verifies the complete
result. The implementation is unchanged between those two cohorts. Both
failed manifests/logs and the focused diagnostic source/binary remain private.

Qualification is `tools/native_reconstruction/native_cue_capacity_qualification_v1.json`.
Build/test evidence is under `build-native-sjuni/media-cue-capacity-results-{llvm,gcc}-v2`.
These are native workers with declared output ports. The coherent game build
and retest of the capacity extension remain separate from this qualification.
V33's actual gallery run accepted and finished three queued preparations with
joined shutdown, but uses the preceding sixteen-cue implementation.
