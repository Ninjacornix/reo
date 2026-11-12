# Room object scene ownership

`gameplay_collision::room_objects::Scene` implements the complete ordinary
`6AD4E0` caller using the existing `InteractionOwner::Lifetime`, canonical
scenario object table, scene entity store, collision proxies and
`SceneModelBindings`. It resets each active record in source order, selects the
current room only when the imported grid is active and control flag1 is set,
constructs the actual instance/proxy family, appends the `6AEE20` dynamic prism,
and increments the source `745D60` count even when the original constructor
naturally returns no instance. Retrying an installed owner refuses instead of
abandoning its handles. Checked retirement releases its own model bindings,
proxies and entity identities.

`Owner::reset_room_grid()` implements the grid-owned portion of `6AD820`:
clear the installed grid and its eight derived mappings while preserving the
scenario placements and their separate occupancy workspace. Installing a grid
does not publish object centers. The complete original comparison exposed an
earlier native mistake here: `6AD860` leaves the centers alone; `6AD260` writes
them only after an instance exists. The premature native center write has been
removed, including on the explicit-shape and exhausted-pool branches.

NativeSession's retained room state now owns this Scene. Its room identity has
a separate one-slot EntityStore, leaving all64 slots of the actual object
instance store available. The Scene uses the same Records, Proxies, SceneModels
and model-binding owner already used by the room scripts. RoomLease aliases
retain this graph and the canonical scenario object table. SessionRooms caches
the real imported wall/floor data before constructing the borrowing Scene.
Room replacement retires the old Scene before the remaining model and entity
owners. RoomInvocation reads the Scene's current dynamic triangles and source
count; retired invocations keep their last readable geometry view and refuse
current-room admission.

The installed owned `r0417300` application profile executes the complete
zero-current-object branch. It still refuses a room with matching placements
because the real initial saved-model-pose producer has not been adopted. The
generic model bank is not repaired with identity matrices. `5D7D60` copies the
saved bank at `4A3C20` into the current bank and sets styles to `FFFFFFFF`;
the earlier cold `5EAEB0` clear establishes zeros only for its own startup
path. The ordinary `5EB780` caller invokes `6AD4E0` after RDT callbacks and
`5EBA30`, before the three model passes. That initial model/asset path remains
the positive-instance application boundary.

The static writer has now been identified precisely: `1CE110:1CE25C` calls
`1CDFE0`; its `1800..1FFF` resource branch passes both bank addresses into
`1D2CB0`. That helper imports each raw skeleton root, rebuilds its nodes and
copies matrices whose full signed static index is nonnegative into both banks
(`1D2EEC..1D2F44`). Owned `r0417300.nbd` contains71 nodes in one root with69
such slots. These are static observations, not yet an admitted native room
model producer or evidence of a runtime launch. A later composition must also
preserve the saved bank across repeated ordinary room loads and cinematic
restoration; recreating an identity bank per room would change that contract.

The independent complete-body comparison uses seven owned room grids from
scenarios1,2,41, each with four declared entry states: normal, nonzero request
fields plus a disabled collision mask, actual `6AD820` grid reset, and an
actually exhausted64-slot instance pool. Controlled identity model poses and
physical remapping are supplied equally to native and original fixtures; they
are not inferred authored startup values. Both compilers pass68,132 checks,
28 complete caller cases,33 selected objects and22 actual instances, with seven
full-pool and seven inactive-grid cases and maximum error0. The comparison
checks all instance fields, object resets, four proxy identities, model poses,
styles, masks, binding targets, dynamic triangles and the source count. Its
ports retain the existing explicitly declared lower math, floor and tracing
contracts; it is not a new full original physics proof.

Exact immutable comparison receipts:
`build-native-sjuni/room-object-scene-{llvm,gcc}-v4/receipt.json`.
Each captures107 source inputs and53 instruction-audited original bodies.
Current application receipts are
`build-native-sjuni/session-rooms-{llvm,gcc}-v5/receipt.json`:21,718 native
checks and31,990 independent original checks, including10,250 complete
wall-loader/mask-helper calls,586 geometry queries and328 hits. These original
calls are separate from the object outer comparison. Both current23-parent
cohorts pass without source drift in
`build-native-sjuni/session-rooms-parents-{llvm,gcc}-v4/receipt.json`, across721
inputs, including the actual pose-work contract and current contact/display
code. Parent v3 stopped at an application-specific harness assertion while
collecting the separate pose target; its retained logs are not a production
failure. The corrected collector follows that target's real Ninja graph and
quoted include closure.

The seal is
`tools/native_reconstruction/native_room_object_scene_qualification_v1.json`.
No game or device was opened, no candidate was installed, and this checkpoint
does not establish complete Stage4 gameplay.
