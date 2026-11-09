# Native scene matrix curve playback

The native matrix owner now supplies complete selected `6B4BA0` curve advancement
against its canonical sixteen channel records and existing `SceneModels` poses.
This is an offline qualified component, not game installation or Stage4 closure.

Starting playback resets the signed time, segment and sound cursor, copies the
current model pose and enters playback2. Each service call advances one quantum
when the canonical clock-mode flag is zero, two otherwise. Curves interpolate
before incrementing time; strict less-than boundaries advance segments and
trigger at most one sound per quantum. The final sentinel stops playback and
sets progress2. Signed halfword time wraps exactly, and unknown transform modes
preserve the previous matrix. Rotations, local X/Z offsets and vertical offsets
reuse the already qualified finite matrix policy. There is no host-clock catchup.

After a synchronous sound callback the next quantum rereads the selected curve,
model and base pose. The comparison includes a sound callback that changes the
base pose, so a cached copy cannot silently hide that source-visible mutation.
Channel identity and published pose leases remain the existing shared owner.

`SceneModelState.sound_resources` owns128 individually optional resource bytes
from `5C1390` writes at `4A1D70`; this is distinct from model style words at
`49F810`. Missing entries are unknown, while zero is a valid imported byte.
`SceneModels.sound_resource` checks each actual importer write. Nonempty sound
curves require a real admitted sound sink and the selected resource before
initial channel writes. The sink receives the exact matrix translation, byte
resource and low event halfword. The `6B60E0` room remap and actual audio consumer
remain explicit required providers; the oracle captures those call arguments.
There is no successful empty production sound fallback. Provider failures return
an error with prior measured effects retained.

The importer also writes channel byte14hex. `source_type` owns that byte once
and provides a checked setter, without assigning additional unproven meaning.

Fresh current-source LLVMv7/GCCv2 cohorts each pass4,473,214 checks:242,206 complete
original playback calls,176,670 timeline frames, every65,536 signed time values,
all236 authored curve selections, five transform profiles, both tick cadences,
1,200 emitted sound requests and nine missing-owner/profile/failure cases.
All other channel bytes retain guards. Complete original instructions and helper
chains are checked against the owned File1 images. The finite SDK131 math profile
is explicit; physical PS2 exceptional arithmetic is not claimed.

Exact private source copies, build commands and results live in the qualification
and its immutable receipts under `build-native-sjuni`. Earlier failed fixture or
mixed-header attempts remain retained, including the original negative test that
expected a sound refusal before an event became due. The passing final cohorts
use the canonical shared scene record owner, with no pinned legacy headers.

Remaining work includes the outer `5D7F00` actor-interaction/group-transition
service, complete room importing, required sound resolution/output, other scene
callers and actual gameplay acceptance. Renderer submission belongs to Stage5.
