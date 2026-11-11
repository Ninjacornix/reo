# Native CPU scene-entry teardown

`PrimaryActorModels::release_scene_entry` now supplies the admitted5F0C00 CPU
sequence: visit exactly the first four canonical roster slots, run each cache
retirement5EC270, then perform the actual shared family0 release1B1DF0. The
operation does not read asset content. Bank preparation here only clones bounded
immutable state during the loading phase. Asset-loading mode and ordinary actor
population do not change the source's four-slot traversal.

One World/model-owner guard covers the complete phase. Missing native actors are
no-ops only when their cache cannot require a live target. A stale live row refuses
before another slot is touched. Later failures report the visited/retired prefix,
the failing slot when applicable and whether shared cleanup completed. A caller
must latch such a failure; detached models are not ready for gameplay updates.

This composition exposed a host lifetime requirement: a shared publication can
replace bank leases on actors other than the model currently changing. Public
model application now retains those old leases until all model/cache stores are
complete. Scene entry retains them through all four retirements and final shared
cleanup. Reentrant public operations continue to see busy. Private nested entry
is available only inside this owner and restores the prior guard state.

Both compilers pass106,065 focused checks with the actual owned models/motions:
385 scene-entry comparisons,384 retirements,192 whole-entry callback guards and
128 stale-row refusals. Cases vary all16 loaded-slot masks, character/class
rotations, missing/zero/nonzero asset-loading modes and repeated entry. Slots4..7
retain their model/cache state. A separate256 callback guards verify direct model
application waits for its final cache state before dropping other actors' old
leases. Existing cache, release, generation and1,196 real-header scene cases pass.

The complete source-word-audited5F0C00 and5EC270/5EC010 bodies execute in the
selected original fixture. Its1B1DF0 call is an explicit observation boundary;
the actual native shared cleanup runs here and has separate current full-body
bank qualification. Registry/HP render work remains the declared Stage5 boundary.
This is a complete admitted CPU teardown sequence, not complete cinematic setup.

Evidence is `primary-scene-entry-{llvm,gcc}-v2`,
`scene-entry-initialization-{llvm,gcc}-v1` and
`scene-entry-shared-banks-{llvm,gcc}-v1`. V1's GCC receipt records a fixture-only
misleading-indentation warning; braces were corrected and both compilers rerun.
The seal is `native_primary_scene_entry_qualification_v1.json`.

Earlier5F0DC0 assignment uses a separate temporary actor pool. The current model
adapter admits canonical roster identities, so that temporary ownership still
requires implementation and source replay before actual caller adoption. See
PRIMARY_TEMPORARY_ACTOR_OWNERSHIP.md. No game was run; V39 remains installed and
Step4 remains incomplete.
