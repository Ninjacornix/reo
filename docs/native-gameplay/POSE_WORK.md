# Canonical scene pose work

Implementation in progress. This is a component of Stage4, which remains
incomplete. The installed game is V39; none of these changes claim a new game
run, a reproduced slowdown or a measured frame-rate improvement.

`PoseWorkPool` supplies the actual64-entry581F50/581FE0/5820F0/582DE0 domain.
Its actors live in the existing World's EntityStore. The pool owns only physical
budget and list order, with one registration per World. Reset retires identities
and restores the original free-stack order; a retained old actor never retargets
a recycled slot. Callback service follows tail to previous *after* the callback,
including a new occupant's continuation when the physical slot was reused.
Reentrant reset/close/update refuse while a pass runs. Unbound callbacks do not
become a successful visibility update.

The complete582B80 gate is compared across all256 kind bytes and65,536 signed
durations:16,777,216 cases and51,642,604 assertions per compiler. Expiry tests
the narrowed result for exact zero. A negative value is not converted into an
immediate expiry or an invented infinite duration. Unknown authored update kinds
retain the original no-op after the lifetime decrement; recognized kinds require
their concrete consumer.

`ResourcePoseWork` supplies complete5823E0 construction using actual canonical
scene descriptors, templates, ResourceModels, Packets and owned contact content.
The action lookup precedes room admission. Pool exhaustion precedes owner-flag
mutation and template lookup. Construction preserves flag precedence, model
versus caller pose selection, angle copies and full32-bit argument delivery.
Contact-packet exhaustion keeps the work already created. Default lifetime1
expires in its first normal service; an extra render/update interval is not added.

`ResourcePoseUpdates` supplies full582E30 descriptor replacement,582F30 following,
5840F0 contact termination and583550 owner-position countdown. Together with the
real582DF0 visibility callback, these run through the same pool. Source+100 in
the replacement descriptor is hexadecimal256, and source115's stop bit is mask1.
Other recognized update families remain required and unavailable until supplied.

The composed differential passes on LLVM and GCC:4,096 allocation/retirement
cases,2,048 constructors,320 service passes,128 callback retirement/reuse cases
and32,768 resource-update cases, totaling1,343,605 checks per compiler. Lookups
5B4D50/5B4380 are explicit controlled inputs to the original constructor; actual
independently qualified native getters run in the native constructor. Original
5DA2C0 requests are observed while native Packets/Catalog perform actual owned
allocation. These ports do not newly requalify the packet attachment internals.

The comparisons compile against an explicit immutable native ABI snapshot from
SessionRooms v4, retaining its exact headers and copied, hash-verified archives.
Later unrelated parent edits are recorded separately. A separate actual current
CMake contract build/run passes both compilers against the current full source
closure and owned catalog, so the shipping build does not use those snapshot
archives or any original CPU context.

PoseWorkState owns its full root matrix. Contact invocations derive temporary,
retained Basis projections from that one matrix, including stale-actor refusal
and old-query lifetime preservation. They do not update a second canonical basis
or borrow an unrelated actor model's joints. A pose actor's+C selector is its
canonical pose timer; the ordinary actor discriminator is a separate role.

Remaining work includes the firing adapter's current integration, other concrete
pose callbacks, generic/preset constructors, full frame/session adoption,
Stage5 rendering and installed gameplay acceptance.
