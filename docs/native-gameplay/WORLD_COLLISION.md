# Canonical native primary actor collision

`gameplay_world::collision_view` binds the native postmovement solver directly
to the actor's position/history, response masks, status, controls, room, surface,
material/region and movement byte. `ActorCollision` owns only the additional
collision/pose fields: local center, transformed previous offset, displacement,
radius, contact outputs, joint2 position, route counter and native basis. There
is no second Actor snapshot or guest-layout byte record in this path.

The real canonical include/exclude values are `response_mask` and
`response_value`, also initialized by the primary actor frame. A correction in
the solver therefore updates exactly the fields later consumers read. Native
room grids, authored regions, room objects and dynamic triangles are borrowed
read-only for the synchronous call. Their owners must outlive it.

`update_primary_collision` traverses the native world's eight primary slots,
holding each generation's strong lease. It supplies the current room/pause
context and reports eligibility and source-face recoveries. Missing required
pose/joint/geometry capability returns an explicit partial pass with the failed
actor identity. Earlier actor effects are retained; no legacy solver is rerun.
Inactive/off-room actors preserve the source's early eligibility gates.

The already documented native repair for an original uninitialized face slot
remains distinguished in the result/count; it is not labeled original parity.
Other indeterminate geometry remains unavailable rather than fabricated.

Both compilers pass76820checks across2400canonical actor cases,1857eligible,
101contact and371joint2 paths, with zero error. The unchanged complete6636D0
caller executes with separately qualified native wall/floor/region/footprint
providers. Additional ordered-world cases check missing-pose refusal, partial
progress, disabled-wall cache refresh, inactive actors and missing-joint refusal.
Qualification: [canonical collision](../../tools/native_reconstruction/native_gameplay_world_collision_qualification_v1.json).

This is the primary part of5DA680. Native pose production, auxiliary/secondary
collections, the complete outer collection caller and game installation remain
open. It does not establish a new gameplay performance result or close Stage4.
