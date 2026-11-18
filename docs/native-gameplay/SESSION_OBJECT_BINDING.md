# Retained scenario objects in publication and reception

NativeSession now owns a concrete `ActorReception` bound to its same World.
SessionRooms connects its retained actual scenario placement owner to both that
receiver and Update's existing StatePublication before returning an installed
room capability. The application PUBLIC-links the real reception library.
`SessionRooms::objects()` exposes that identical typed owner for subsequent
object construction; it does not parse a second mutable table.

`Owner::bind_room_objects(scenario, shared_ptr<const room_objects::Owner>)`
requires an open, idle World/Update/task graph, an initialized table and the
canonical selected scenario. Binding a different table over a live same-scenario
binding refuses; callers must explicitly unbind first. A shared table lease
outlives caller references. Changing the canonical scenario immediately makes
the old binding unavailable. Update close releases its binding. The receiver
has the corresponding retained mutable binding with World/open/scope checks.
Existing explicitly borrowed constructor APIs remain compatible.

First geometry installation also checks the Update/World idle boundary before
resource import or collision-mask mutation. Cached installed geometry can be
retained by actual frame consumers while the owner runs. Required late binding
cannot be silently replaced with a successful missing-provider response.

The new owned-input test constructs an actual typed ActorMessageQueue and runs
Update's type9 room-object publication through the concrete receiver. It verifies
coordinate capture before a later mutation, queued reception into the same
canonical table, signed-byte endpoint coordinates, independent foreign-table
preservation, scenario mismatch, uninitialized input, double-owner refusal,
scheduler-callback busy refusal and shared table lifetime after caller release.
This is native queue composition evidence. It does not claim a host network
transport or newly qualify the already-tested original message handlers.

Paired receipts are
`build-native-sjuni/session-rooms-{llvm,gcc}-v4/receipt.json`:21,574 native checks
and31,846 checks in the independent original-body executable, including the same
10,250 complete wall-loader/mask-helper calls. Both current22-parent cohorts
pass without source drift in
`build-native-sjuni/session-rooms-parents-{llvm,gcc}-v2/receipt.json`.
These exact snapshots include the current pose-work Actor ABI and precede the
camera near/far field-name correction; the binding code does not use those
camera parameters. The prior RoomResources v3 checkpoint remains separately
sealed. The new seal is
`tools/native_reconstruction/native_session_object_binding_qualification_v1.json`.

Actual6AD4E0 outer construction and model/proxy lifetime application adoption
remain the next cut. Existing `InteractionOwner::Lifetime` and
`SceneModelBindings` provide the concrete lower owners. Initial current model
poses require their actual producer:5D7D60 copies the saved pose bank and sets
styles toFFFFFFFF; it does not initialize identities. Cold5EAEB0 clears both
pose banks before that reset, while later room/model initialization remains a
separate producer. No arbitrary identity pose is admitted by this binding cut.
