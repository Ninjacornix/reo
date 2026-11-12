# Canonical application room resources

`gameplay_application::SessionRooms` is the first production implementation of
`gameplay_contact_world::RoomResources`. It borrows one shared `NativeSession`,
resolves the actual scenario `_H.BIN` resource ordinals, and supplies retained
`RoomInvocation` objects to native contact and resource-flight consumers.
It introduces no second World, Session, Update, flag bank or scene-record pool.

For installed `RoomId{41,73,0}`, it imports owned `w0417300.bin` and
`g0417300.bin` through the existing qualified grid importer, RDT section16
through the existing region importer, and actual `obj041.dat`/`r041.sto`
through the canonical room-object importer. The scenario placement owner is
retained once per NativeSession and reused across room generations and provider
facades. Each room generation caches its immutable geometry once. Missing or
malformed resources refuse; no empty replacement grid is admitted.

The first `retain(73)` performs the actual wall-resource installation before
returning a query capability. Callers compose that capability before gameplay
commands requiring collision-mask state. Repeated retention and multiple
SessionRooms facades share the installed geometry and do not repeat its reset.
The initial constrained room script has no collision-mask producers.

The source mask word3C2748 is now `Session::collision_disabled_mask`. A generic
Session starts unknown. Complete wall loader6161E0 writes zero at616250;
successful production wall installation performs that exact producer. The
native5DCB90 set and5DCB60 clear helpers preserve the32-bit result of
`0x1000 << ((selector+16)&31)`, including wrapped and zero-result shifts. A
read/modify/write command refuses unknown initial state. No generic startup
zero is assumed. The runtime filter reads that canonical word and each actual
SceneMatrixPrograms channel's `source_type` and `contact.gate`; `progress` is
not used as the collision gate.

NativeSession's opaque RoomLease retains the application and actual room graph.
Room replacement explicitly closes the old graph and retires its native
EntityStore identity even while invocations retain it. `current()` checks that
generation, canonical room/scenario, application lifetime and matrix-owner
availability. Closing only the matrix owner also invalidates queries. Immutable
geometry and the last filter view remain readable after retirement. A returned
matrix-program lease itself keeps World/Update/flags and old room backing alive;
it does not merely retain a reference into an already-destroyed application.

Object admission is deliberately constrained by actual construction ownership.
Original745D60 counts6AD4E0-created instances, rather than all imported scenario
placements. Owned r0417300 has five placements elsewhere in its scenario and
none in this room. Its actual current instance count and dynamic triangles are
known zero, and RDT section14 is absent. Rooms with matching placements currently
refuse until their real grid/model/proxy lifecycle is composed. The instance
count is not inferred from the global five placements. This is the next required
room-owner cut, together with binding that same retained object owner into
Update's publication and reception consumers.

Paired final receipts are
`build-native-sjuni/session-rooms-{llvm,gcc}-v3/receipt.json`. Each captures670
source/header/CMake inputs and54 native archive identities without drift. Native
tests pass21,542 checks, four room generations,586 real geometry queries and328
hits, including the actual flight consumer and production contact-room retention.
Separate original comparison executables pass31,814 checks and10,250 complete
original calls:6161E0/619A50 installation plus5DCB60/5DCB90 mask mutations.
All97 instruction comments across those complete bodies match the owned overlay.
The original-code executable is test-only; production has no original CPU,
register or RAM-model engine.

The v1 qualifiers failed only because their initial harness assumed geometry
members existed in the script-only inventory. The corrected harness independently
reads the actual AFS directory and `_H.BIN` ordinals and hashes all five resource
payloads. v2 passed; v3 adds the early matrix-owner closure refusal and exact
retained-program lifetime checks. Failed and prior receipts remain intact.

Both current22-parent cohorts pass across680 captured inputs without drift:
`build-native-sjuni/session-rooms-parents-{llvm,gcc}-v1/receipt.json`.
The seal is `tools/native_reconstruction/native_session_rooms_qualification_v1.json`.
Production game selection, remaining scripts and full frame services, movable
object construction, input/network/media hosts and semantic saves remain open
Stage4 acceptance requirements.
