# Native scene entry

The full `5ECF90` scene entry is under reconstruction. Its descriptor, actor,
object, lighting, facial and speech components have independent qualifications;
they do not establish the remaining room/resource lifecycle calls by themselves.

`gameplay_application::reset_scene_models` composes the complete represented
`5D7D60` reset with its `5BE980` child. It borrows the existing `RoomModels`
saved bank, `SceneModels` current bank, `SceneModelBindings`, sixteen
`SceneMatrixPrograms`, effect `Modulation`, and the canonical `InventoryUi`
request gate. It creates none of those banks. Reset releases binding leases,
restores all128 saved matrices and default styles, clears the sixteen channels
in place, clears modulation, clears the priority-text active gate, releases the
UI request gate, and resets the room camera override timer/phase.

`SceneModelGlobals` supplies previously unowned model controls, the eight
deferred actor cleanup flags, global drawing translation and style override.
Its controls preserve explicit source values without assigning an unproved
renderer meaning. `PriorityTextState` owns only the priority SPK task's active
byte, distinct from the sixteen dialogue records and32 cached-text entries.
Clearing it does not delete a task. The room camera timer and mode are the
existing `SequenceControl::selection` (`3DDDB6`) and `phase` (`3DDDD5`), also
written by script commands 13/16. `reset_camera_override` clears that same state;
the earlier separate `RoomCameraOverride` copy has been removed. Cinematic camera
curves remain distinct. Default `SceneModelGlobals` and `PriorityTextState`
values stay unknown until their actual producers establish them.

The operation rejects closed/busy worlds and mismatched model/binding/program
owners. It is externally serialized by the simulation owner. The separate
`InventoryUi::reset_request_gate` implements the actual `5D7D60` zero producer;
it does not invoke the broader, still separate `604310` resource cleanup path.

The independent comparison executes the complete pinned original `5D7D60` and
`5BE980` bodies, with sixteen bounded96-byte memory-zero primitives. It uses an
actual imported room and saved poses and compares128 slots, every represented
channel field, all reset globals and preserved visibility/sound/remap state.
The current [scene-reset comparison](../../build-native-sjuni/scene-reset-sequence-original-llvm-v2/receipt.json)
passes256 cases /208,657 checks against the shared LLVM application libraries.
It also checks that resetting camera override state is visible to the same
sequence owner used by script conditions, while preserving unrelated fields.
Current scene-entry work must additionally preserve the original requested-room
cache publication **before** room loads; installed asset provenance alone cannot
represent that failure prefix.

The remaining `5ECF90` work includes the movie descriptor merge, room material
retirement/reload, room effect-control startup (`576F10`), full object-motion
entry, and resource2400/scene-text bank startup. These remain explicit pending
owners. This document does not claim full Step4 completion.
